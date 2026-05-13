const state = {
  data: null,
  activeTab: "pokedex",
  query: "",
  filteredSpecies: [],
  rowHeight: 112,
};

const typeName = (value) => value.replace("TYPE_", "").replaceAll("_", " ");
const moveName = (constant) => state.data.moves[constant]?.name || constant.replace("MOVE_", "").replaceAll("_", " ");
const abilityName = (constant) => state.data.abilities[constant]?.name || constant.replace("ABILITY_", "").replaceAll("_", " ");
const fmtTitle = (value, prefix = "") => value.replace(prefix, "").replaceAll("_", " ").toLowerCase().replace(/\b\w/g, (char) => char.toUpperCase());
const fmtCategory = (value) => fmtTitle(value, "DAMAGE_CATEGORY_");

function el(tag, className, html) {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (html !== undefined) node.innerHTML = html;
  return node;
}

function typePills(types) {
  const unique = [...new Set(types.filter(Boolean))];
  return `<div class="type-list">${unique.map((type) => {
    return `<span class="type ${type}">${typeName(type)}</span>`;
  }).join("")}</div>`;
}

function abilityPills(constants, kind = "base") {
  const kindClass = kind === "innate" ? "innate-ability-pill" : "base-ability-pill";
  return `<div class="pill-list">${constants.map((constant) => {
    const ability = state.data.abilities[constant];
    return `<button class="pill ability-pill ${kindClass}" type="button" data-ability="${constant}">${abilityName(constant)}</button>`;
  }).join("")}</div>`;
}

function sprite(src, className = "sprite") {
  return src ? `<img class="${className}" src="${src}" alt="">` : `<span class="muted">No sprite</span>`;
}

async function init() {
  const response = await fetch("data/romhack-docs.json");
  state.data = await response.json();
  state.filteredSpecies = state.data.species;
  bindEvents();
  renderAll();
}

function bindEvents() {
  document.querySelectorAll(".tab").forEach((button) => {
    button.addEventListener("click", () => setTab(button.dataset.tab));
  });
  document.getElementById("globalSearch").addEventListener("input", (event) => {
    state.query = event.target.value.trim().toLowerCase();
    document.getElementById("dexScroller").scrollTop = 0;
    renderActive();
  });
  document.getElementById("dexScroller").addEventListener("scroll", renderDexRows);
  document.getElementById("closeDialog").addEventListener("click", () => document.getElementById("detailDialog").close());
  document.body.addEventListener("click", handleAbilityClick, true);
  document.body.addEventListener("pointerover", handleAbilityHover);
  document.body.addEventListener("pointerout", hideAbilityTooltip);
  document.body.addEventListener("click", handleEvolutionClick, true);
  document.body.addEventListener("pointerover", handleMoveHover);
  document.body.addEventListener("pointerout", hideMoveTooltip);
}

function setTab(tab) {
  state.activeTab = tab;
  state.query = "";
  document.getElementById("globalSearch").value = "";
  document.getElementById("dexScroller").scrollTop = 0;
  document.querySelectorAll(".tab").forEach((button) => button.classList.toggle("active", button.dataset.tab === tab));
  document.querySelectorAll(".panel").forEach((panel) => panel.classList.toggle("active", panel.id === tab));
  renderActive();
}

function matches(text) {
  return !state.query || text.toLowerCase().includes(state.query);
}

function renderAll() {
  renderDex();
  renderEncounters();
  renderTms();
  renderAbilities();
}

function renderActive() {
  if (state.activeTab === "pokedex") renderDex();
  if (state.activeTab === "encounters") renderEncounters();
  if (state.activeTab === "machines") renderTms();
  if (state.activeTab === "abilities") renderAbilities();
}

function renderDex() {
  state.filteredSpecies = state.data.species.filter((mon) => matches(`${mon.dex} ${mon.name} ${mon.types.join(" ")} ${mon.abilities.join(" ")} ${mon.innates.join(" ")}`));
  document.getElementById("dexSpacer").style.height = `${state.filteredSpecies.length * state.rowHeight}px`;
  renderDexRows();
}

function renderDexRows() {
  const scroller = document.getElementById("dexScroller");
  const container = document.getElementById("dexRows");
  const start = Math.max(0, Math.floor(scroller.scrollTop / state.rowHeight) - 4);
  const count = Math.ceil(scroller.clientHeight / state.rowHeight) + 8;
  const visible = state.filteredSpecies.slice(start, start + count);
  container.style.transform = `translateY(${start * state.rowHeight}px)`;
  container.innerHTML = "";
  visible.forEach((mon) => {
    const row = el("div", "dex-row dex-entry");
    row.innerHTML = `
      <span>${mon.dex || mon.id}</span>
      <span>${sprite(mon.sprite)}</span>
      <strong>${mon.name}</strong>
      <span>${typePills(mon.types)}</span>
      <span>${mon.stats.hp}</span><span>${mon.stats.atk}</span><span>${mon.stats.def}</span>
      <span>${mon.stats.spa}</span><span>${mon.stats.spd}</span><span>${mon.stats.spe}</span>
      <strong>${mon.bst}</strong>
      <span>${abilityPills(mon.abilities, "base")}${abilityPills(mon.innates, "innate")}</span>
    `;
    row.addEventListener("click", () => openSpecies(mon));
    container.appendChild(row);
  });
}

function showAbilityTooltip(button) {
  const ability = state.data.abilities[button.dataset.ability];
  if (!ability) return;
  const root = button.closest("dialog[open]") || document.body;
  let tooltip = root.querySelector("#abilityTooltip");
  if (!tooltip) {
    tooltip = el("div", "ability-tooltip");
    tooltip.id = "abilityTooltip";
    root.appendChild(tooltip);
  }
  tooltip.innerHTML = `<strong>${ability.name}</strong><span>${ability.description}</span>`;
  const rect = button.getBoundingClientRect();
  const left = Math.min(window.innerWidth - 340, Math.max(12, rect.left));
  const top = Math.min(window.innerHeight - 120, rect.bottom + 8);
  tooltip.style.left = `${left}px`;
  tooltip.style.top = `${top}px`;
  tooltip.hidden = false;
}

function hideAbilityTooltip() {
  document.querySelectorAll("#abilityTooltip").forEach((tooltip) => {
    tooltip.hidden = true;
  });
}

function handleAbilityClick(event) {
  const button = event.target.closest(".ability-pill");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  showAbilityTooltip(button);
}

function handleAbilityHover(event) {
  const button = event.target.closest(".ability-pill");
  if (button) showAbilityTooltip(button);
}

function showMoveTooltip(button) {
  const move = state.data.moves[button.dataset.move];
  if (!move) return;
  const root = button.closest("dialog[open]") || document.body;
  let tooltip = root.querySelector("#moveTooltip");
  if (!tooltip) {
    tooltip = el("div", "ability-tooltip move-tooltip");
    tooltip.id = "moveTooltip";
    root.appendChild(tooltip);
  }
  tooltip.innerHTML = `<strong>${move.name}</strong><span>${move.description || "No description."}</span>`;
  const rect = button.getBoundingClientRect();
  const left = Math.min(window.innerWidth - 340, Math.max(12, rect.left));
  const top = Math.min(window.innerHeight - 120, rect.bottom + 8);
  tooltip.style.left = `${left}px`;
  tooltip.style.top = `${top}px`;
  tooltip.hidden = false;
}

function hideMoveTooltip() {
  document.querySelectorAll("#moveTooltip").forEach((tooltip) => {
    tooltip.hidden = true;
  });
}

function handleMoveHover(event) {
  const button = event.target.closest(".move-name");
  if (button) showMoveTooltip(button);
}

function handleEvolutionClick(event) {
  const button = event.target.closest(".evolution-name");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  openSpeciesByConstant(button.dataset.species);
}

function statBars(mon) {
  const labels = [["hp", "HP"], ["atk", "Atk"], ["def", "Def"], ["spa", "SpA"], ["spd", "SpD"], ["spe", "Spe"]];
  return labels.map(([key, label]) => `
    <div class="stat-row">
      <strong>${label}</strong>
      <span>${mon.stats[key]}</span>
      <div class="bar"><span style="width:${Math.min(100, mon.stats[key] / 2)}%"></span></div>
    </div>
  `).join("") + `
    <div class="stat-row">
      <strong>BST</strong>
      <span>${mon.bst}</span>
      <div class="bar"><span style="width:${Math.min(100, mon.bst / 7.2)}%"></span></div>
    </div>
  `;
}

function moveRows(moves) {
  if (!moves.length) return `<p class="muted">No moves listed.</p>`;
  return `<div class="move-list">
    <div class="move-row move-head"><span>Lvl</span><span>Move</span><span>Type</span><span>Pow</span><span>Acc</span></div>
    ${moves.map((entry) => {
    const constant = typeof entry === "string" ? entry : entry.move;
    const level = typeof entry === "string" ? "" : entry.level;
    const move = state.data.moves[constant] || {};
    return `<div class="move-row"><span>${level}</span><button class="move-name" type="button" data-move="${constant}">${move.name || moveName(constant)}</button><span>${typePills([move.type || ""])}</span><span>${move.power || "-"}</span><span>${move.accuracy || "-"}</span></div>`;
  }).join("")}</div>`;
}

function evolutionChain(mon) {
  const bySpecies = new Map(state.data.species.map((entry) => [entry.constant, entry]));
  const incoming = new Map();
  state.data.species.forEach((entry) => {
    entry.evolutions.forEach((edge) => {
      if (!incoming.has(edge.target)) incoming.set(edge.target, []);
      incoming.get(edge.target).push({ from: entry.constant, ...edge });
    });
  });

  const roots = new Set([mon.constant]);
  const walkBack = (constant) => {
    const parents = incoming.get(constant) || [];
    if (!parents.length) roots.add(constant);
    parents.forEach((edge) => walkBack(edge.from));
  };
  roots.clear();
  walkBack(mon.constant);

  const seenEdges = new Set();
  const renderFrom = (constant) => {
    const source = bySpecies.get(constant);
    if (!source || !source.evolutions.length) {
      return "";
    }
    return source.evolutions.map((edge) => {
      const key = `${constant}-${edge.target}-${edge.label}`;
      if (seenEdges.has(key)) return "";
      seenEdges.add(key);
      const target = bySpecies.get(edge.target);
      return `
        <div class="evolution-line">
          <button class="evolution-name" type="button" data-species="${source.constant}">${sprite(source.sprite, "tiny-sprite")}<strong>${source.name}</strong></button>
          <span class="evolution-arrow">-&gt;</span>
          <button class="evolution-name" type="button" data-species="${edge.target}">${sprite(target?.sprite, "tiny-sprite")}<strong>${target?.name || edge.target.replace("SPECIES_", "").replaceAll("_", " ")}</strong></button>
          <span class="evolution-method">${edge.label}</span>
        </div>
        ${renderFrom(edge.target)}
      `;
    }).join("");
  };

  const html = [...roots].map(renderFrom).join("");
  return html || `<p class="muted">No evolution data.</p>`;
}

function openSpecies(mon) {
  document.getElementById("modalTitle").textContent = `#${mon.dex || mon.id} ${mon.name}`;
  document.getElementById("modalBody").innerHTML = `
    <div class="species-summary">
      ${sprite(mon.sprite)}
      <div>
        ${typePills(mon.types)}
        <h3 class="section-title">Abilities</h3>
        ${abilityPills(mon.abilities, "base")}
        <h3 class="section-title">Innates</h3>
        ${abilityPills(mon.innates, "innate")}
      </div>
    </div>
    <h3 class="section-title">Evolution</h3>
    <div class="evolution-chain">${evolutionChain(mon)}</div>
    <div class="detail-grid">
      <section><h3 class="section-title">Base Stats</h3>${statBars(mon)}</section>
      <section><h3 class="section-title">Level-Up Learnset</h3>${moveRows(mon.levelUp)}</section>
    </div>
    <h3 class="section-title">TM/HM Compatibility</h3>
    ${moveRows(mon.tmhm)}
    <h3 class="section-title">Tutor Compatibility</h3>
    ${moveRows(mon.tutors)}
  `;
  const dialog = document.getElementById("detailDialog");
  if (!dialog.open) {
    dialog.showModal();
  }
}

function openSpeciesByConstant(constant) {
  const mon = state.data.species.find((entry) => entry.constant === constant);
  if (mon) openSpecies(mon);
}

function renderEncounters() {
  const container = document.getElementById("encounterList");
  const rows = state.data.encounters.filter((encounter) => matches(`${encounter.name} ${encounter.methods.map((m) => m.mons.map((mon) => mon.name).join(" ")).join(" ")}`));
  container.innerHTML = rows.map((encounter) => `
    <article class="card">
      <h2>${encounter.name}</h2>
      <div class="encounter-methods">
        ${encounter.methods.map((method) => `
          <section>
            <h3 class="section-title">${method.method}</h3>
            ${method.method === "Fishing Mons" ? fishingMons(method.mons) : method.mons.map((mon) => encounterMon(mon)).join("")}
          </section>
        `).join("")}
      </div>
    </article>
  `).join("");
}

function encounterMon(mon) {
  return `
    <div class="encounter-mon">
      ${sprite(mon.sprite, "mini-sprite")}
      <strong>${mon.name}</strong>
      <span>Lv ${mon.minLevel ?? "?"}-${mon.maxLevel ?? "?"}</span>
      <span>${mon.rate ?? "-"}%</span>
    </div>
  `;
}

function fishingMons(mons) {
  const groups = [
    ["Old Rod", mons.slice(0, 2)],
    ["Good Rod", mons.slice(2, 5)],
    ["Super Rod", mons.slice(5)],
  ];
  return groups.map(([label, group]) => `
    <div class="rod-divider">${label}</div>
    ${group.map((mon) => encounterMon(mon)).join("")}
  `).join("");
}

function renderTms() {
  const tbody = document.getElementById("tmRows");
  const rows = state.data.tms.filter((tm) => matches(`${tm.label} ${tm.moveName} ${tm.type} ${tm.description}`));
  tbody.innerHTML = rows.map((tm) => `
    <tr>
      <td><strong>${tm.label}</strong></td>
      <td>${tm.moveName}</td>
      <td>${typePills([tm.type])}</td>
      <td>${fmtCategory(tm.category || "")}</td>
      <td>${tm.power || "-"}</td>
      <td>${tm.accuracy || "-"}</td>
      <td>${tm.pp || "-"}</td>
      <td>${tm.description}</td>
      <td class="muted">${tm.location || "TBD"}</td>
    </tr>
  `).join("");
}

function renderAbilities() {
  const container = document.getElementById("abilityList");
  const abilities = Object.values(state.data.abilities)
    .filter((ability) => ability.constant !== "ABILITY_NONE")
    .filter((ability) => matches(`${ability.name} ${ability.description}`))
    .sort((a, b) => a.name.localeCompare(b.name));
  container.innerHTML = `<div class="ability-row ability-head"><span>Name</span><span>Description</span><span>Pokemon</span></div>`;
  abilities.forEach((ability) => {
    const row = el("article", "ability-row");
    row.innerHTML = `<h2>${ability.name}</h2><p>${ability.description}</p><p class="muted">${ability.usage.base.length} base / ${ability.usage.innate.length} innate</p>`;
    row.addEventListener("click", () => openAbility(ability));
    container.appendChild(row);
  });
}

function usageList(list) {
  if (!list.length) return `<p class="muted">None.</p>`;
  return `<div class="ability-grid">${list.map((mon) => `
    <div class="card">
      ${sprite(mon.sprite, "mini-sprite")}
      <strong>#${mon.dex || ""} ${mon.name}</strong>
    </div>
  `).join("")}</div>`;
}

function openAbility(ability) {
  document.getElementById("modalTitle").textContent = ability.name;
  document.getElementById("modalBody").innerHTML = `
    <p>${ability.description}</p>
    <h3 class="section-title">Base Ability</h3>
    ${usageList(ability.usage.base)}
    <h3 class="section-title">Innate Ability</h3>
    ${usageList(ability.usage.innate)}
  `;
  document.getElementById("detailDialog").showModal();
}

init().catch((error) => {
  document.body.innerHTML = `<main><h1>Failed to load docs</h1><pre>${error.stack || error}</pre></main>`;
});
