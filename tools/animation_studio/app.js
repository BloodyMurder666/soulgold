"use strict";

const state = {
  manifest: null,
  moves: [],
  scriptsByLabel: new Map(),
  tagsById: new Map(),
  selectedMove: null,
  composerSources: [],
};

const el = (id) => document.getElementById(id);

function showStatus(message, hidden = false) {
  const box = el("statusBox");
  box.hidden = hidden;
  box.textContent = message;
}

function prettyList(items, fallback = "None") {
  if (!items || items.length === 0) return fallback;
  return items.join(", ");
}

function scriptForMove(move) {
  if (!move || !move.script) return null;
  return state.scriptsByLabel.get(move.script) || null;
}

function defaultLabelForMove(moveId) {
  if (!moveId || !moveId.startsWith("MOVE_")) return "";
  return "gBattleAnimMove_" + moveId
    .slice(5)
    .toLowerCase()
    .split("_")
    .filter(Boolean)
    .map((part) => part.charAt(0).toUpperCase() + part.slice(1))
    .join("");
}

async function loadManifest() {
  try {
    const response = await fetch(`data/manifest.json?cache=${Date.now()}`);
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    state.manifest = await response.json();
    state.moves = state.manifest.moves
      .filter((move) => move.id && move.script)
      .sort((a, b) => (a.value ?? 99999) - (b.value ?? 99999));
    state.scriptsByLabel = new Map(state.manifest.scripts.map((script) => [script.label, script]));
    state.tagsById = new Map(state.manifest.tags.map((tag) => [tag.id, tag]));
    state.selectedMove = state.moves.find((move) => move.id === "MOVE_POUND") || state.moves[0] || null;
    showStatus("", true);
    renderAll();
  } catch (error) {
    showStatus(
      "Could not load data/manifest.json. Run: python3 tools/animation_studio/studio.py build-manifest, then serve the repo with python3 -m http.server 8000."
    );
  }
}

function moveMatches(move, query) {
  if (!query) return true;
  const haystack = [
    move.id,
    move.name,
    move.script,
    move.type,
    ...(move.tags || []),
    ...(move.backgrounds || []),
    ...(move.templates || []),
    ...(move.tasks || []),
  ].join(" ").toLowerCase();
  return haystack.includes(query);
}

function renderMoveList() {
  const query = el("moveSearch").value.trim().toLowerCase();
  const list = el("moveList");
  const matches = state.moves.filter((move) => moveMatches(move, query));
  list.innerHTML = "";
  el("moveCount").textContent = `${matches.length} of ${state.moves.length} move animations`;

  for (const move of matches.slice(0, 700)) {
    const button = document.createElement("button");
    button.type = "button";
    button.className = "move-row" + (state.selectedMove && move.id === state.selectedMove.id ? " active" : "");
    button.innerHTML = `
      <span class="move-name">${escapeHtml(move.name || move.id)}</span>
      <span class="move-meta">${escapeHtml(move.id)} · ${escapeHtml(move.script || "No script")}</span>
    `;
    button.addEventListener("click", () => {
      state.selectedMove = move;
      syncComposerDefaults();
      renderAll();
    });
    list.appendChild(button);
  }
}

function escapeHtml(value) {
  return String(value ?? "")
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;")
    .replaceAll('"', "&quot;");
}

function renderSummary() {
  const move = state.selectedMove;
  const script = scriptForMove(move);
  el("selectedMoveName").textContent = move ? move.name : "No move selected";
  el("selectedMoveMeta").textContent = move
    ? `${move.id} · ${move.type || "TYPE_UNKNOWN"} · ${script ? script.label : "No script"}`
    : "";
}

function renderDetails() {
  const move = state.selectedMove;
  const script = scriptForMove(move);
  const details = el("moveDetails");
  details.innerHTML = "";
  if (!move) return;

  const rows = [
    ["Move", move.id],
    ["Script", move.script],
    ["Type", move.type],
    ["Power", move.power],
    ["Accuracy", move.accuracy],
    ["Category", move.category],
    ["Target", move.target],
    ["Effect", move.effect],
    ["Script Line", script ? `data/battle_anim_scripts.s:${script.line}` : ""],
  ];

  for (const [key, value] of rows) {
    const dt = document.createElement("dt");
    const dd = document.createElement("dd");
    dt.textContent = key;
    dd.textContent = value || "-";
    details.append(dt, dd);
  }

  const chips = el("moveChips");
  chips.innerHTML = "";
  const chipValues = [
    ...(script?.tags || []),
    ...(script?.backgrounds || []),
    ...(script?.templates || []),
    ...(script?.tasks || []),
  ];
  for (const value of chipValues.slice(0, 80)) {
    const chip = document.createElement("span");
    chip.className = "chip";
    chip.textContent = value;
    chips.appendChild(chip);
  }
}

function previewCommandFor(move) {
  if (!move) return "";
  return [
    `python3 tools/animation_studio/studio.py preview-test --move ${move.id}`,
    "# Run the sharded make command printed by the preview-test command.",
    "# Then open the printed pokeemerald-test-N.elf in a graphical GBA emulator.",
  ].join("\n");
}

function renderPreview() {
  el("previewCommand").textContent = previewCommandFor(state.selectedMove);
}

function renderScript() {
  const script = scriptForMove(state.selectedMove);
  el("scriptSource").value = script ? `${script.label}::\n${script.body}` : "";
}

function renderAssets() {
  const script = scriptForMove(state.selectedMove);
  const query = el("assetSearch").value.trim().toLowerCase();
  let tags = state.manifest ? state.manifest.tags : [];

  if (!query && script && script.tags.length) {
    const wanted = new Set(script.tags);
    tags = tags.filter((tag) => wanted.has(tag.id));
  } else if (query) {
    tags = tags.filter((tag) => {
      const haystack = [tag.id, tag.name, tag.gfxPath, tag.palPath, tag.comment].join(" ").toLowerCase();
      return haystack.includes(query);
    });
  }

  const list = el("assetList");
  list.innerHTML = "";
  if (!tags.length) {
    list.textContent = "No matching assets.";
    return;
  }

  for (const tag of tags.slice(0, 200)) {
    const row = document.createElement("div");
    row.className = "asset-row";
    const image = tag.pngPath
      ? `<img src="../../${escapeHtml(tag.pngPath)}" alt="${escapeHtml(tag.name || tag.id)}">`
      : `<div></div>`;
    row.innerHTML = `
      ${image}
      <div>
        <div class="asset-id">${escapeHtml(tag.id)}</div>
        <div class="asset-path">${escapeHtml(tag.gfxPath || tag.palPath || tag.comment || "No path indexed")}</div>
      </div>
    `;
    list.appendChild(row);
  }
}

function syncComposerDefaults() {
  const move = state.selectedMove;
  if (!move) return;
  if (!el("composeMove").value.trim()) el("composeMove").value = move.id;
  if (!el("composeLabel").value.trim()) el("composeLabel").value = defaultLabelForMove(move.id);
}

function addCurrentSource() {
  const move = state.selectedMove;
  const script = scriptForMove(move);
  if (!move || !script) return;
  if (state.composerSources.some((source) => source.script.label === script.label)) return;
  state.composerSources.push({ ref: move.id, move, script });
  renderComposer();
}

function renderComposer() {
  const stack = el("sourceStack");
  stack.innerHTML = "";
  if (!state.composerSources.length) {
    stack.textContent = "Add one or more existing animations to inline them into a new script.";
  } else {
    for (const source of state.composerSources) {
      const pill = document.createElement("span");
      pill.className = "source-pill";
      pill.textContent = `${source.move.name} (${source.ref})`;
      stack.appendChild(pill);
    }
  }
}

function trimPrimaryBody(lines) {
  const out = [];
  for (const line of lines) {
    const command = line.trim().split("@", 1)[0].trim();
    if (command === "end") break;
    out.push(line);
  }
  while (out.length && !out[out.length - 1].trim()) out.pop();
  return out;
}

function starterScript(label) {
  return [
    `${label}::`,
    "\tloadspritegfx ANIM_TAG_IMPACT",
    "\tmonbg ANIM_TARGET",
    "\tsplitbgprio ANIM_TARGET",
    "\tsetalpha 12, 8",
    "\tplaysewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET",
    "\tcreate_basic_hitsplat_sprite ANIM_TARGET, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=0",
    "\tcreatevisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 2",
    "\twaitforvisualfinish",
    "\tclearmonbg ANIM_TARGET",
    "\tblendoff",
    "\tend",
  ].join("\n");
}

function generatedScript(label) {
  if (!state.composerSources.length) return starterScript(label);
  const lines = [`${label}::`];
  for (const source of state.composerSources) {
    lines.push(`\t@ Inlined from ${source.script.label}. Review labels/gotos before shipping.`);
    for (const line of trimPrimaryBody(source.script.body.split("\n"))) {
      lines.push(line.trim() ? (line.startsWith("\t") ? line : `\t${line}`) : "");
    }
    lines.push("\twaitforvisualfinish");
  }
  lines.push("\tend");
  return lines.join("\n");
}

function generateComposerOutput() {
  const move = el("composeMove").value.trim() || state.selectedMove?.id || "MOVE_MY_MOVE";
  const label = el("composeLabel").value.trim() || defaultLabelForMove(move);
  const sourceArgs = state.composerSources.map((source) => `--source ${source.ref}`).join(" ");
  const script = generatedScript(label);
  const testName = `Animation Studio Preview: ${move}`;

  el("composerOutput").value = [
    "# CLI apply command",
    `python3 tools/animation_studio/studio.py new --move ${move} --label ${label} ${sourceArgs} --preview-test`.replace(/\s+/g, " ").trim(),
    "",
    "# Generated script preview",
    script,
    "",
    "# Exact preview build",
    `python3 tools/animation_studio/studio.py preview-test --move ${move}`,
    `# The tool prints the correct sharded make command for "${testName}".`,
  ].join("\n");
}

async function copyText(text) {
  try {
    await navigator.clipboard.writeText(text);
    showStatus("Copied.", false);
    setTimeout(() => showStatus("", true), 1200);
  } catch {
    showStatus("Clipboard access failed; select the text and copy manually.");
  }
}

function renderAll() {
  renderMoveList();
  renderSummary();
  renderDetails();
  renderPreview();
  renderScript();
  renderAssets();
  renderComposer();
}

el("reloadButton").addEventListener("click", loadManifest);
el("moveSearch").addEventListener("input", renderMoveList);
el("assetSearch").addEventListener("input", renderAssets);
el("addCurrentSource").addEventListener("click", addCurrentSource);
el("clearSources").addEventListener("click", () => {
  state.composerSources = [];
  renderComposer();
});
el("generateComposer").addEventListener("click", generateComposerOutput);
el("copyScript").addEventListener("click", () => copyText(el("scriptSource").value));
el("copyPreviewCommand").addEventListener("click", () => copyText(el("previewCommand").textContent));
el("composeMove").addEventListener("input", () => {
  if (!el("composeLabel").value.trim()) el("composeLabel").value = defaultLabelForMove(el("composeMove").value.trim());
});

loadManifest();
