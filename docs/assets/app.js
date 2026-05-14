const state = {
  data: null,
  activeTab: "pokedex",
  query: "",
  filteredSpecies: [],
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
  const response = await fetch("data/romhack-docs.json?v=20260513-30");
  state.data = await response.json();
  state.filteredSpecies = state.data.species;
  bindEvents();
  updateStickyOffset();
  renderAll();
}

function bindEvents() {
  document.querySelectorAll(".tab").forEach((button) => {
    button.addEventListener("click", () => setTab(button.dataset.tab));
  });
  document.getElementById("globalSearch").addEventListener("input", (event) => {
    state.query = event.target.value.trim().toLowerCase();
    window.scrollTo(0, 0);
    renderActive();
  });
  const dialog = document.getElementById("detailDialog");
  document.getElementById("closeDialog").addEventListener("click", () => closeDetailDialog());
  dialog.addEventListener("click", (event) => {
    if (event.target === dialog) closeDetailDialog();
  });
  document.body.addEventListener("click", handleAbilityClick, true);
  document.body.addEventListener("pointerover", handleAbilityHover);
  document.body.addEventListener("pointerout", hideAbilityTooltip);
  document.body.addEventListener("click", handleSpeciesLinkClick, true);
  document.body.addEventListener("pointerover", handleMoveHover);
  document.body.addEventListener("pointerout", hideMoveTooltip);
  window.addEventListener("resize", updateStickyOffset);
}

function updateStickyOffset() {
  const chrome = document.querySelector(".top-chrome");
  if (!chrome) return;
  document.documentElement.style.setProperty("--top-chrome-height", `${Math.ceil(chrome.getBoundingClientRect().height)}px`);
}

function setTab(tab) {
  hideAbilityTooltip();
  hideMoveTooltip();
  updateStickyOffset();
  state.activeTab = tab;
  state.query = "";
  document.getElementById("globalSearch").value = "";
  window.scrollTo(0, 0);
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
  state.filteredSpecies = state.data.species.filter((mon) => matches(`${mon.dex} ${mon.name} ${speciesFormLabel(mon)} ${mon.types.map(typeName).join(" ")}`));
  renderDexRows();
}

function renderDexRows() {
  const container = document.getElementById("dexRows");
  container.innerHTML = "";
  state.filteredSpecies.forEach((mon) => {
    const row = el("div", "dex-row dex-entry");
    row.innerHTML = `
      <span>${mon.dex || mon.id}</span>
      <span>${sprite(mon.sprite)}</span>
      <strong>${speciesFormLabel(mon)}</strong>
      <span>${typePills(mon.types)}</span>
      <span class="dex-stat" data-label="HP" style="--stat-pct:${Math.min(100, mon.stats.hp / 2)}%">${mon.stats.hp}</span>
      <span class="dex-stat" data-label="Atk" style="--stat-pct:${Math.min(100, mon.stats.atk / 2)}%">${mon.stats.atk}</span>
      <span class="dex-stat" data-label="Def" style="--stat-pct:${Math.min(100, mon.stats.def / 2)}%">${mon.stats.def}</span>
      <span class="dex-stat" data-label="SpA" style="--stat-pct:${Math.min(100, mon.stats.spa / 2)}%">${mon.stats.spa}</span>
      <span class="dex-stat" data-label="SpD" style="--stat-pct:${Math.min(100, mon.stats.spd / 2)}%">${mon.stats.spd}</span>
      <span class="dex-stat" data-label="Spe" style="--stat-pct:${Math.min(100, mon.stats.spe / 2)}%">${mon.stats.spe}</span>
      <strong class="dex-stat dex-stat-bst" data-label="BST" style="--stat-pct:${Math.min(100, mon.bst / 7.2)}%">${mon.bst}</strong>
      <span>${abilityPills(mon.abilities, "base")}${abilityPills(mon.innates, "innate")}</span>
    `;
    row.addEventListener("click", () => openSpecies(mon));
    container.appendChild(row);
  });
}

function closeDetailDialog() {
  hideAbilityTooltip();
  hideMoveTooltip();
  document.getElementById("detailDialog").close();
}

function getScopedTooltip(root, id, className) {
  let tooltip = [...root.children].find((child) => child.id === id);
  if (!tooltip) {
    tooltip = el("div", className);
    tooltip.id = id;
    root.appendChild(tooltip);
  }
  return tooltip;
}

function showAbilityTooltip(button) {
  const ability = state.data.abilities[button.dataset.ability];
  if (!ability) return;
  const root = button.closest("dialog[open]") || document.body;
  const tooltip = getScopedTooltip(root, "abilityTooltip", "ability-tooltip");
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
  const tooltip = getScopedTooltip(root, "moveTooltip", "ability-tooltip move-tooltip");
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

function handleSpeciesLinkClick(event) {
  const button = event.target.closest(".species-link");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  event.stopImmediatePropagation();
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

function moveRows(moves, options = {}) {
  if (!moves.length) return `<p class="muted">No moves listed.</p>`;
  const showLevel = options.showLevel !== false;
  const head = showLevel
    ? `<div class="move-row move-head"><span>Lvl</span><span>Move</span><span>Type</span><span>Pow</span><span>Acc</span></div>`
    : `<div class="move-row move-head move-head-compat"><span>Move</span><span>Type</span><span>Pow</span><span>Acc</span></div>`;
  return `<div class="move-list">
    ${head}
    ${moves.map((entry) => {
    const constant = typeof entry === "string" ? entry : entry.move;
    const level = typeof entry === "string" ? "" : entry.level;
    const move = state.data.moves[constant] || {};
    const cells = showLevel ? `<span>${level}</span>` : "";
    return `<div class="move-row ${showLevel ? "" : "move-row-compat"}">${cells}<button class="move-name" type="button" data-move="${constant}">${move.name || moveName(constant)}</button><span>${typePills([move.type || ""])}</span><span>${move.power || "-"}</span><span>${move.accuracy || "-"}</span></div>`;
  }).join("")}</div>`;
}

function baseSpeciesForForms(mon) {
  if (!mon.constant.includes("_MEGA")) return mon;
  return state.data.species.find((entry) => entry.dex === mon.dex && !entry.constant.includes("_MEGA")) || mon;
}

function evolutionChain(mon) {
  const bySpecies = new Map(state.data.species.map((entry) => [entry.constant, entry]));
  const chainMon = baseSpeciesForForms(mon);
  const incoming = new Map();
  state.data.species.forEach((entry) => {
    entry.evolutions.forEach((edge) => {
      if (!incoming.has(edge.target)) incoming.set(edge.target, []);
      incoming.get(edge.target).push({ from: entry.constant, ...edge });
    });
  });

  const roots = new Set([chainMon.constant]);
  const walkBack = (constant) => {
    const parents = incoming.get(constant) || [];
    if (!parents.length) roots.add(constant);
    parents.forEach((edge) => walkBack(edge.from));
  };
  roots.clear();
  walkBack(chainMon.constant);

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
          <button class="evolution-name species-link" type="button" data-species="${source.constant}">${sprite(source.sprite, "tiny-sprite")}<strong>${source.name}</strong></button>
          <span class="evolution-arrow">-&gt;</span>
          <button class="evolution-name species-link" type="button" data-species="${edge.target}">${sprite(target?.sprite, "tiny-sprite")}<strong>${target?.name || edge.target.replace("SPECIES_", "").replaceAll("_", " ")}</strong></button>
          <span class="evolution-method">${edge.label}</span>
        </div>
        ${renderFrom(edge.target)}
      `;
    }).join("");
  };

  const html = [...roots].map(renderFrom).join("");
  return html || `<p class="muted">No evolution data.</p>`;
}

function speciesFormLabel(mon) {
  if (mon.constant.includes("_MEGA_X")) return `${mon.name} X`;
  if (mon.constant.includes("_MEGA_Y")) return `${mon.name} Y`;
  if (mon.constant.includes("_MEGA_Z")) return `${mon.name} Z`;
  if (mon.constant.includes("_MEGA")) return `${mon.name} Mega`;
  return mon.name;
}

function megaFormLinks(mon) {
  const bySpecies = new Map(state.data.species.map((entry) => [entry.constant, entry]));
  const chainMon = baseSpeciesForForms(mon);
  const family = new Set([chainMon.constant]);
  let changed = true;
  while (changed) {
    changed = false;
    state.data.species.forEach((entry) => {
      entry.evolutions.forEach((edge) => {
        if (family.has(entry.constant) && !family.has(edge.target)) {
          family.add(edge.target);
          changed = true;
        }
        if (family.has(edge.target) && !family.has(entry.constant)) {
          family.add(entry.constant);
          changed = true;
        }
      });
    });
  }
  const familyDex = new Set([...family].map((constant) => bySpecies.get(constant)?.dex).filter(Boolean));
  const forms = state.data.species.filter((entry) => entry.constant.includes("_MEGA") && familyDex.has(entry.dex));
  if (!forms.length) return "";
  return forms.map((form) => {
    const base = state.data.species.find((entry) => entry.dex === form.dex && !entry.constant.includes("_MEGA"));
    return `
      <div class="evolution-line">
        <button class="evolution-name species-link" type="button" data-species="${base?.constant || chainMon.constant}">${sprite(base?.sprite || chainMon.sprite, "tiny-sprite")}<strong>${base?.name || chainMon.name}</strong></button>
        <span class="evolution-arrow">-&gt;</span>
        <button class="evolution-name species-link" type="button" data-species="${form.constant}">${sprite(form.sprite, "tiny-sprite")}<strong>${speciesFormLabel(form)}</strong></button>
        <span class="evolution-method">Mega Evolution</span>
      </div>
    `;
  }).join("");
}

function locationRows(locations) {
  if (!locations?.length) return `<p class="muted">Not found in wild encounters.</p>`;
  return `<div class="location-list">
    <div class="location-row location-head"><span>Area</span><span>Method</span><span>Level</span><span>Odds</span></div>
    ${locations.map((location) => `
      <div class="location-row">
        <strong>${location.name}</strong>
        <span>${location.time ? `${location.time} / ` : ""}${location.method}</span>
        <span>Lv ${location.minLevel ?? "?"}-${location.maxLevel ?? "?"}</span>
        <span>${location.rate ?? "-"}%</span>
      </div>
    `).join("")}
  </div>`;
}

function openSpecies(mon) {
  document.getElementById("modalTitle").textContent = `#${mon.dex || mon.id} ${speciesFormLabel(mon)}`;
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
    <div class="evolution-chain">${evolutionChain(mon)}${megaFormLinks(mon)}</div>
    <div class="detail-grid">
      <section><h3 class="section-title">Base Stats</h3>${statBars(mon)}</section>
      <section><h3 class="section-title">Locations in wild</h3>${locationRows(mon.locations)}</section>
    </div>
    <h3 class="section-title">Level-Up Learnset</h3>
    ${moveRows(mon.levelUp)}
    <h3 class="section-title">TM/HM Compatibility</h3>
    ${moveRows(mon.tmhm, { showLevel: false })}
    <h3 class="section-title">Tutor Compatibility</h3>
    ${moveRows(mon.tutors, { showLevel: false })}
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
  const rows = state.data.encounters.filter((encounter) => matches(`${encounter.name} ${encounter.variants.map((variant) => variant.methods.map((m) => m.mons.map((mon) => mon.name).join(" ")).join(" ")).join(" ")}`));
  container.innerHTML = rows.map((encounter) => `
    <article class="card">
      <h2>${encounter.name}</h2>
      ${encounter.variants.map((variant) => encounterVariant(variant, encounter.hasTimeVariants)).join("")}
    </article>
  `).join("");
}

function encounterVariant(variant, showTime) {
  return `
    <section class="encounter-variant">
      ${showTime ? `<h3 class="encounter-time">${variant.time}</h3>` : ""}
      <div class="encounter-methods">
        ${variant.methods.map((method) => `
          <section>
            <h4 class="section-title">${method.method}</h4>
            <div class="encounter-mon encounter-head">
              <span></span>
              <span>Species</span>
              <span>Level</span>
              <span>Odds</span>
            </div>
            ${method.key === "fishing_mons" ? fishingMons(method.mons) : method.mons.map((mon) => encounterMon(mon)).join("")}
          </section>
        `).join("")}
      </div>
    </section>
  `;
}

function encounterMon(mon) {
  const name = mon.hasSpecies
    ? `<button class="encounter-species species-link" type="button" data-species="${mon.species}"><strong>${mon.name}</strong></button>`
    : `<strong>${mon.name}</strong>`;
  return `
    <div class="encounter-mon">
      ${sprite(mon.sprite, "mini-sprite")}
      ${name}
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
  tbody.innerHTML = "";
  rows.forEach((tm) => {
    const row = el("tr", "tm-row");
    row.innerHTML = `
      <td data-label="ID"><strong>${tm.label}</strong></td>
      <td data-label="Move">${tm.moveName}</td>
      <td data-label="Type">${typePills([tm.type])}</td>
      <td data-label="Cat">${fmtCategory(tm.category || "")}</td>
      <td data-label="Pow">${tm.power || "-"}</td>
      <td data-label="Acc">${tm.accuracy || "-"}</td>
      <td data-label="PP">${tm.pp || "-"}</td>
      <td data-label="Description">${tm.description}</td>
      <td data-label="Location" class="muted">${tm.location || "TBD"}</td>
    `;
    row.addEventListener("click", (event) => {
      if (event.target.closest("button, a, .species-link, .ability-pill, .move-name")) return;
      openTm(tm);
    });
    tbody.appendChild(row);
  });
}

function speciesCards(list) {
  if (!list.length) return `<p class="muted">None.</p>`;
  return `<div class="ability-grid">${list.map((mon) => `
    <button class="card species-card species-link" type="button" data-species="${mon.constant || mon.species}">
      ${sprite(mon.sprite, "mini-sprite")}
      <strong>#${mon.dex || ""} ${mon.name}</strong>
    </button>
  `).join("")}</div>`;
}

function openTm(tm) {
  const compatible = state.data.species.filter((mon) => mon.tmhm.includes(tm.move));
  document.getElementById("modalTitle").textContent = `${tm.label} ${tm.moveName}`;
  document.getElementById("modalBody").innerHTML = `
    <div class="tm-detail">
      <div>${typePills([tm.type])}</div>
      <p><strong>${fmtCategory(tm.category || "")}</strong> / Power ${tm.power || "-"} / Accuracy ${tm.accuracy || "-"} / PP ${tm.pp || "-"}</p>
      <p>${tm.description || "No description."}</p>
      <p class="muted">${tm.location || "Location TBD"}</p>
    </div>
    <h3 class="section-title">Compatible Pokemon</h3>
    ${speciesCards(compatible)}
  `;
  document.getElementById("detailDialog").showModal();
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
  return speciesCards(list);
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
