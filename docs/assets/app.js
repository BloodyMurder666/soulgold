const state = {
  data: null,
  activeTab: "pokedex",
  query: "",
  filteredSpecies: [],
  selectedTypes: new Set(),
  modalScrollY: 0,
};

const typeName = (value) => value.replace("TYPE_", "").replaceAll("_", " ");
const moveName = (constant) => state.data.moves[constant]?.name || constant.replace("MOVE_", "").replaceAll("_", " ");
const abilityName = (constant) => state.data.abilities[constant]?.name || constant.replace("ABILITY_", "").replaceAll("_", " ");
const fmtTitle = (value, prefix = "") => value.replace(prefix, "").replaceAll("_", " ").toLowerCase().replace(/\b\w/g, (char) => char.toUpperCase());
const fmtCategory = (value) => fmtTitle(value, "DAMAGE_CATEGORY_");
const statLabels = { hp: "HP", atk: "Atk", def: "Def", spa: "SpA", spd: "SpD", spe: "Spe" };
const searchPlaceholders = {
  pokedex: "Search Pokédex…",
  encounters: "Search areas or Pokémon…",
  machines: "Search TMs, moves, or types…",
  items: "Search items or locations…",
  trainers: "Search trainers or parties…",
  abilities: "Search abilities…",
};
const escapeHtml = (value) => String(value ?? "").replace(/[&<>"']/g, (char) => ({
  "&": "&amp;",
  "<": "&lt;",
  ">": "&gt;",
  "\"": "&quot;",
  "'": "&#39;",
}[char]));

function el(tag, className, html) {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (html !== undefined) node.innerHTML = html;
  return node;
}

function bindRowActivation(node, activate, label) {
  node.tabIndex = 0;
  node.setAttribute("role", "button");
  if (label) node.setAttribute("aria-label", label);
  node.addEventListener("click", (event) => {
    if (event.target.closest("button, a")) return;
    activate();
  });
  node.addEventListener("keydown", (event) => {
    if (event.key !== "Enter" && event.key !== " ") return;
    if (event.target.closest("button, a")) return;
    event.preventDefault();
    activate();
  });
}

function typePills(types) {
  const unique = [...new Set(types.filter(Boolean))];
  return `<div class="type-list">${unique.map((type) => {
    return `<span class="type ${type}">${typeName(type)}</span>`;
  }).join("")}</div>`;
}

function abilityPills(constants, kind = "base") {
  const kindClass = kind === "hidden" ? "hidden-ability-pill" : kind === "innate" ? "innate-ability-pill" : "base-ability-pill";
  return abilityPillList(uniqueConstants(constants).map((constant) => ({ constant, className: kindClass })));
}

function abilityPillList(entries) {
  if (!entries.length) return "";
  return `<div class="pill-list">${entries.map(({ constant, className }) => {
    const ability = state.data.abilities[constant];
    return `<button class="pill ability-pill ${className}" type="button" data-ability="${constant}">${abilityName(constant)}</button>`;
  }).join("")}</div>`;
}

function uniqueConstants(constants) {
  return [...new Set((constants || []).filter(Boolean))];
}

function pokemonAbilityGroups(mon) {
  const regular = uniqueConstants(mon.regularAbilities || (mon.abilities || []).slice(0, 2));
  const hidden = uniqueConstants(mon.hiddenAbilities || (mon.abilities || []).slice(2)).filter((constant) => !regular.includes(constant));
  const innates = uniqueConstants(mon.innates || []);
  return { regular, hidden, innates };
}

function pokemonAbilityPills(mon) {
  const groups = pokemonAbilityGroups(mon);
  return `
    <div class="dex-ability-groups">
      ${regularAndHiddenAbilityPills(groups)}
      ${abilityPills(groups.innates, "innate")}
    </div>
  `;
}

function pokemonAbilitySections(mon) {
  const groups = pokemonAbilityGroups(mon);
  return `
    <h3 class="section-title">Abilities</h3>
    ${regularAndHiddenAbilityPills(groups) || `<p class="muted">None.</p>`}
    ${groups.innates.length ? `<h3 class="section-title">Innates</h3>${abilityPills(groups.innates, "innate")}` : ""}
  `;
}

function regularAndHiddenAbilityPills(groups) {
  return abilityPillList([
    ...groups.regular.map((constant) => ({ constant, className: "base-ability-pill" })),
    ...groups.hidden.map((constant) => ({ constant, className: "hidden-ability-pill" })),
  ]);
}

function sprite(src, className = "sprite") {
  return src ? `<img class="${className}" src="${src}" alt="">` : `<span class="muted">No sprite</span>`;
}

function moveCategory(category) {
  const label = fmtCategory(category || "");
  const icon = state.data.categoryIcons?.[category];
  if (icon) {
    return `<span class="category-display" title="${label}"><img class="category-icon" src="${icon}" alt="${label}"></span>`;
  }
  return category ? `<span class="category-display category-badge">${label}</span>` : `<span class="muted">-</span>`;
}

function speciesSpritePanel(mon) {
  if (!mon.shinySprite) return sprite(mon.sprite);
  const shinyIcon = state.data.uiIcons?.shiny || "";
  return `
    <div class="species-sprite-panel">
      <img class="sprite" src="${mon.sprite}" alt="${speciesFormLabel(mon)}">
      <button class="sprite-toggle" type="button" data-state="regular" data-regular="${mon.sprite}" data-shiny="${mon.shinySprite}" aria-label="Toggle shiny colors" aria-pressed="false">${shinyIcon ? `<img class="shiny-toggle-icon" src="${shinyIcon}" alt="">` : ""}</button>
    </div>
  `;
}

async function init() {
  const response = await fetch("data/romhack-docs.json?v=20260701");
  state.data = await response.json();
  state.filteredSpecies = state.data.species;
  document.body.dataset.activeTab = state.activeTab;
  bindEvents();
  renderTypeFilter();
  updateStickyOffset();
  renderAll();
}

function bindEvents() {
  document.querySelectorAll(".tab").forEach((button) => {
    button.addEventListener("click", () => setTab(button.dataset.tab));
  });
  document.getElementById("backToTop").addEventListener("click", () => window.scrollTo({ top: 0, behavior: "smooth" }));
  document.getElementById("globalSearch").addEventListener("input", (event) => {
    state.query = event.target.value.trim().toLowerCase();
    window.scrollTo(0, 0);
    renderActive();
  });
  document.getElementById("typeFilterToggle").addEventListener("click", toggleTypeFilter);
  document.getElementById("typeFilterPanel").addEventListener("click", handleTypeFilterClick);
  document.addEventListener("click", closeTypeFilterOnOutsideClick);
  const dialog = document.getElementById("detailDialog");
  document.getElementById("closeDialog").addEventListener("click", () => closeDetailDialog());
  dialog.addEventListener("click", (event) => {
    if (event.target === dialog) closeDetailDialog();
  });
  dialog.addEventListener("close", handleDetailDialogClose);
  document.body.addEventListener("click", handleAbilityClick, true);
  document.body.addEventListener("pointerover", handleAbilityHover);
  document.body.addEventListener("pointerout", hideAbilityTooltip);
  document.body.addEventListener("click", handleMoveClick, true);
  document.body.addEventListener("click", handleSpeciesLinkClick, true);
  document.body.addEventListener("click", handleSpriteToggle, true);
  document.body.addEventListener("pointerover", handleMoveHover);
  document.body.addEventListener("pointerout", hideMoveTooltip);
  document.body.addEventListener("pointerover", handleItemHover);
  document.body.addEventListener("pointerout", hideItemTooltip);
  document.body.addEventListener("click", handleItemTooltipClick, true);
  window.addEventListener("resize", updateStickyOffset);
}

function updateStickyOffset() {
  const chrome = document.querySelector(".top-chrome");
  if (!chrome) return;
  const scale = Number.parseFloat(getComputedStyle(document.body).zoom) || 1;
  document.documentElement.style.setProperty("--top-chrome-height", `${Math.ceil(chrome.getBoundingClientRect().height / scale)}px`);
}

function setTab(tab) {
  hideAbilityTooltip();
  hideMoveTooltip();
  hideItemTooltip();
  updateStickyOffset();
  state.activeTab = tab;
  document.body.dataset.activeTab = tab;
  state.query = "";
  const search = document.getElementById("globalSearch");
  search.value = "";
  search.placeholder = searchPlaceholders[tab] || "Search…";
  closeTypeFilter();
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
  renderItems();
  renderAbilities();
  renderTrainers();
}

function renderActive() {
  if (state.activeTab === "pokedex") renderDex();
  if (state.activeTab === "encounters") renderEncounters();
  if (state.activeTab === "machines") renderTms();
  if (state.activeTab === "items") renderItems();
  if (state.activeTab === "abilities") renderAbilities();
  if (state.activeTab === "trainers") renderTrainers();
}

function renderDex() {
  state.filteredSpecies = state.data.species.filter((mon) =>
    matches(`${mon.dex} ${mon.name} ${speciesFormLabel(mon)} ${mon.types.map(typeName).join(" ")}`)
    && matchesSelectedTypes(mon)
  );
  renderDexRows();
}

function dexFilterTypes() {
  const present = new Set(state.data.species.flatMap((mon) => mon.types || []));
  return Object.keys(state.data.typeIcons || {})
    .filter((type) => present.has(type))
    .filter((type) => !["TYPE_NONE", "TYPE_MYSTERY", "TYPE_STELLAR"].includes(type));
}

function renderTypeFilter() {
  const panel = document.getElementById("typeFilterPanel");
  if (!panel) return;
  panel.innerHTML = `
    <div class="type-filter-title">Types</div>
    <button class="type-filter-clear" type="button" data-clear-types>All</button>
    <div class="type-filter-grid">
      ${dexFilterTypes().map((type) => `
        <button class="type-filter-chip type ${type}" type="button" data-type="${type}" aria-pressed="false">${typeName(type)}</button>
      `).join("")}
    </div>
  `;
  syncTypeFilter();
}

function syncTypeFilter() {
  const toggle = document.getElementById("typeFilterToggle");
  const count = state.selectedTypes.size;
  toggle.textContent = count ? `Type ${count}` : "Type";
  toggle.classList.toggle("has-filter", count > 0);
  document.querySelectorAll(".type-filter-chip").forEach((button) => {
    const active = state.selectedTypes.has(button.dataset.type);
    button.classList.toggle("active", active);
    button.setAttribute("aria-pressed", active ? "true" : "false");
  });
}

function matchesSelectedTypes(mon) {
  if (!state.selectedTypes.size) return true;
  return mon.types.some((type) => state.selectedTypes.has(type));
}

function toggleTypeFilter(event) {
  event.stopPropagation();
  const panel = document.getElementById("typeFilterPanel");
  const open = panel.hidden;
  panel.hidden = !open;
  document.getElementById("typeFilterToggle").setAttribute("aria-expanded", open ? "true" : "false");
}

function closeTypeFilter() {
  const panel = document.getElementById("typeFilterPanel");
  if (!panel || panel.hidden) return;
  panel.hidden = true;
  document.getElementById("typeFilterToggle").setAttribute("aria-expanded", "false");
}

function closeTypeFilterOnOutsideClick(event) {
  if (event.target.closest("#typeFilter")) return;
  closeTypeFilter();
}

function handleTypeFilterClick(event) {
  event.stopPropagation();
  const clear = event.target.closest("[data-clear-types]");
  const button = event.target.closest("[data-type]");
  if (!clear && !button) return;
  if (clear) {
    state.selectedTypes.clear();
  } else if (state.selectedTypes.has(button.dataset.type)) {
    state.selectedTypes.delete(button.dataset.type);
  } else {
    state.selectedTypes.add(button.dataset.type);
  }
  syncTypeFilter();
  window.scrollTo(0, 0);
  renderDex();
}

function renderDexRows() {
  const container = document.getElementById("dexRows");
  container.innerHTML = "";
  state.filteredSpecies.forEach((mon) => {
    const row = el("div", "dex-row dex-entry");
    row.innerHTML = `
      <span class="dex-id">${mon.dex || mon.id}</span>
      <span class="dex-sprite">${sprite(mon.sprite)}</span>
      <strong class="dex-name">${speciesFormLabel(mon)}</strong>
      <span class="dex-types">${typePills(mon.types)}</span>
      <span class="dex-stats">
        <span class="dex-stat" data-label="HP">${mon.stats.hp}</span>
        <span class="dex-stat" data-label="Atk">${mon.stats.atk}</span>
        <span class="dex-stat" data-label="Def">${mon.stats.def}</span>
        <span class="dex-stat" data-label="SpA">${mon.stats.spa}</span>
        <span class="dex-stat" data-label="SpD">${mon.stats.spd}</span>
        <span class="dex-stat" data-label="Spe">${mon.stats.spe}</span>
        <strong class="dex-stat dex-stat-bst" data-label="BST">${mon.bst}</strong>
      </span>
      <span class="dex-abilities">${pokemonAbilityPills(mon)}</span>
    `;
    bindRowActivation(row, () => openSpecies(mon), `Open details for ${speciesFormLabel(mon)}`);
    container.appendChild(row);
  });
}

function closeDetailDialog() {
  const dialog = document.getElementById("detailDialog");
  if (dialog.open) {
    dialog.close();
  } else {
    handleDetailDialogClose();
  }
}

function handleDetailDialogClose() {
  hideAbilityTooltip();
  hideMoveTooltip();
  hideItemTooltip();
  unlockBodyScroll();
}

function showDetailDialog(kind = "generic") {
  const dialog = document.getElementById("detailDialog");
  dialog.dataset.kind = kind;
  lockBodyScroll();
  if (!dialog.open) {
    dialog.showModal();
  }
  const mobile = window.matchMedia("(max-width: 1100px)").matches;
  dialog.querySelectorAll(".detail-accordion").forEach((section) => {
    section.open = !mobile || section.hasAttribute("data-mobile-open");
  });
  requestAnimationFrame(() => {
    document.getElementById("modalBody").scrollTop = 0;
  });
}

function lockBodyScroll() {
  if (document.body.classList.contains("modal-open")) return;
  state.modalScrollY = window.scrollY;
  const scale = Number.parseFloat(getComputedStyle(document.body).zoom) || 1;
  document.documentElement.style.setProperty("--modal-scroll-top", `${-state.modalScrollY / scale}px`);
  document.body.classList.add("modal-open");
}

function unlockBodyScroll() {
  if (!document.body.classList.contains("modal-open")) return;
  const scrollY = state.modalScrollY;
  document.body.classList.remove("modal-open");
  document.documentElement.style.removeProperty("--modal-scroll-top");
  state.modalScrollY = 0;
  window.scrollTo(0, scrollY);
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

function tooltipAnchor(event, fallback) {
  if (event && Number.isFinite(event.clientX) && Number.isFinite(event.clientY)) {
    return { x: event.clientX, y: event.clientY };
  }
  const rect = fallback.getBoundingClientRect();
  return { x: rect.left, y: rect.bottom };
}

function placeTooltip(tooltip, root, event, fallback) {
  const anchor = tooltipAnchor(event, fallback);
  tooltip.hidden = false;
  tooltip.style.visibility = "hidden";
  tooltip.style.left = "0px";
  tooltip.style.top = "0px";

  const width = tooltip.offsetWidth || 320;
  const height = tooltip.offsetHeight || 120;
  const offsetX = 14;
  const offsetY = 18;

  if (root === document.body) {
    const scale = Number.parseFloat(getComputedStyle(document.body).zoom) || 1;
    const scaledWidth = width * scale;
    const scaledHeight = height * scale;
    const scaledOffsetX = offsetX * scale;
    const scaledOffsetY = offsetY * scale;
    tooltip.style.position = "fixed";
    let left = anchor.x + scaledOffsetX;
    let top = anchor.y + scaledOffsetY;
    if (left + scaledWidth > window.innerWidth - 12) left = anchor.x - scaledWidth - scaledOffsetX;
    if (top + scaledHeight > window.innerHeight - 12) top = anchor.y - scaledHeight - scaledOffsetY;
    left = Math.max(12, Math.min(left, window.innerWidth - scaledWidth - 12));
    top = Math.max(12, Math.min(top, window.innerHeight - scaledHeight - 12));
    tooltip.style.left = `${left / scale}px`;
    tooltip.style.top = `${top / scale}px`;
  } else {
    tooltip.style.position = "absolute";
    const rootRect = root.getBoundingClientRect();
    const visibleLeft = root.scrollLeft + 12;
    const visibleTop = root.scrollTop + 12;
    const visibleRight = root.scrollLeft + root.clientWidth - width - 12;
    const visibleBottom = root.scrollTop + root.clientHeight - height - 12;
    let left = anchor.x - rootRect.left + root.scrollLeft + offsetX;
    let top = anchor.y - rootRect.top + root.scrollTop + offsetY;
    if (left > visibleRight) left = anchor.x - rootRect.left + root.scrollLeft - width - offsetX;
    if (top > visibleBottom) top = anchor.y - rootRect.top + root.scrollTop - height - offsetY;
    tooltip.style.left = `${Math.max(visibleLeft, Math.min(left, visibleRight))}px`;
    tooltip.style.top = `${Math.max(visibleTop, Math.min(top, visibleBottom))}px`;
  }

  tooltip.style.visibility = "";
}

function showAbilityTooltip(button, event) {
  const reference = button.dataset.ability;
  const ability = state.data.abilities[reference]
    || Object.values(state.data.abilities).find((entry) => entry.name === reference);
  if (!ability) return;
  const root = button.closest("dialog[open]") || document.body;
  const tooltip = getScopedTooltip(root, "abilityTooltip", "ability-tooltip");
  tooltip.innerHTML = `<strong>${ability.name}</strong><span>${ability.description}</span>`;
  placeTooltip(tooltip, root, event, button);
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
  showAbilityTooltip(button, event);
}

function handleAbilityHover(event) {
  const button = event.target.closest(".ability-pill");
  if (button) showAbilityTooltip(button, event);
}

function showMoveTooltip(button, event) {
  const reference = button.dataset.move;
  const move = state.data.moves[reference]
    || Object.values(state.data.moves).find((entry) => entry.name === reference);
  if (!move) return;
  const root = button.closest("dialog[open]") || document.body;
  const tooltip = getScopedTooltip(root, "moveTooltip", "ability-tooltip move-tooltip");
  tooltip.innerHTML = `<strong>${move.name}</strong><span>${move.description || "No description."}</span>`;
  placeTooltip(tooltip, root, event, button);
}

function hideMoveTooltip() {
  document.querySelectorAll("#moveTooltip").forEach((tooltip) => {
    tooltip.hidden = true;
  });
}

function showItemTooltip(button, event) {
  const itemName = button.dataset.itemName || "Item";
  const itemDescription = button.dataset.itemDescription || "No description.";
  const root = button.closest("dialog[open]") || document.body;
  const tooltip = getScopedTooltip(root, "itemTooltip", "ability-tooltip item-tooltip");
  tooltip.innerHTML = `<strong>${escapeHtml(itemName)}</strong><span>${escapeHtml(itemDescription)}</span>`;
  placeTooltip(tooltip, root, event, button);
}

function hideItemTooltip() {
  document.querySelectorAll("#itemTooltip").forEach((tooltip) => {
    tooltip.hidden = true;
  });
}

function handleItemHover(event) {
  const button = event.target.closest(".item-tooltip-target");
  if (button) showItemTooltip(button, event);
}

function handleItemTooltipClick(event) {
  const button = event.target.closest(".item-tooltip-target");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  showItemTooltip(button, event);
}

function handleMoveHover(event) {
  const button = event.target.closest(".move-name");
  if (button) showMoveTooltip(button, event);
}

function handleMoveClick(event) {
  const button = event.target.closest(".move-name");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  showMoveTooltip(button, event);
}

function handleSpeciesLinkClick(event) {
  const button = event.target.closest(".species-link");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  event.stopImmediatePropagation();
  openSpeciesByConstant(button.dataset.species);
}

function handleSpriteToggle(event) {
  const button = event.target.closest(".sprite-toggle");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  const image = button.closest(".species-sprite-panel")?.querySelector("img");
  if (!image) return;
  const showShiny = button.dataset.state !== "shiny";
  image.src = showShiny ? button.dataset.shiny : button.dataset.regular;
  button.dataset.state = showShiny ? "shiny" : "regular";
  button.setAttribute("aria-pressed", showShiny ? "true" : "false");
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
    ? `<div class="move-row move-head"><span>Lvl</span><span>Move</span><span>Type</span><span>Cat</span><span>Pow</span><span>Acc</span></div>`
    : `<div class="move-row move-head move-head-compat"><span>Move</span><span>Type</span><span>Cat</span><span>Pow</span><span>Acc</span></div>`;
  return `<div class="move-list">
    ${head}
    ${moves.map((entry) => {
    const constant = typeof entry === "string" ? entry : entry.move;
    const level = typeof entry === "string" ? "" : entry.level;
    const move = state.data.moves[constant] || {};
    const cells = showLevel ? `<span>${level}</span>` : "";
    return `<div class="move-row ${showLevel ? "" : "move-row-compat"}">${cells}<button class="move-name" type="button" data-move="${constant}">${move.name || moveName(constant)}</button><span>${typePills([move.type || ""])}</span><span>${moveCategory(move.category || "")}</span><span>${move.power || "-"}</span><span>${move.accuracy || "-"}</span></div>`;
  }).join("")}</div>`;
}

function learnsetSection(title, moves, options = {}) {
  return accordionSection(title, moveRows(moves || [], options), { className: "learnset-section" });
}

function accordionSection(title, content, options = {}) {
  return `
    <details class="detail-accordion ${options.className || ""}" open ${options.mobileOpen ? "data-mobile-open" : ""}>
      <summary><h3>${title}</h3><span class="accordion-icon" aria-hidden="true"></span></summary>
      <div class="accordion-body">${content}</div>
    </details>
  `;
}

function baseSpeciesForForms(mon) {
  if (!/_(?:MEGA(?:_[XYZ])?|GMAX|DMAX)$/.test(mon.constant)) return mon;
  return state.data.species.find((entry) => entry.constant === baseConstantForMega(mon.constant)) || mon;
}

function baseConstantForMega(constant) {
  return constant.replace(/_(?:MEGA(?:_[XYZ])?|GMAX|DMAX)$/, "");
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

function megaTargetLabel(mon) {
  if (mon.constant.includes("_GMAX") || mon.constant.includes("_DMAX")) return `${mon.name} Mega`;
  return speciesFormLabel(mon);
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
  const seen = new Set();
  const forms = (state.data.megaEvolutions || [])
    .filter((edge) => family.has(edge.source) && bySpecies.has(edge.target))
    .filter((edge) => {
      const key = `${edge.source}-${edge.target}-${edge.item}`;
      if (seen.has(key)) return false;
      seen.add(key);
      return true;
    });
  if (!forms.length) return "";
  return forms.map((edge) => {
    const base = bySpecies.get(edge.source) || chainMon;
    const form = bySpecies.get(edge.target);
    return `
      <div class="evolution-line">
        <button class="evolution-name species-link" type="button" data-species="${base?.constant || chainMon.constant}">${sprite(base?.sprite || chainMon.sprite, "tiny-sprite")}<strong>${base?.name || chainMon.name}</strong></button>
        <span class="evolution-arrow">-&gt;</span>
        <button class="evolution-name species-link" type="button" data-species="${form.constant}">${sprite(form.sprite, "tiny-sprite")}<strong>${megaTargetLabel(form)}</strong></button>
        <span class="evolution-method">${edge.label || `Mega Evolution (${edge.itemName || "Mega Stone"})`}</span>
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

function heldItemRows(heldItems) {
  if (!heldItems?.length) return "";
  return `
    <h3 class="section-title">Held Items</h3>
    <div class="held-item-list">
      ${heldItems.map((item) => `
        <div class="held-item-row">
          <strong>${item.name || item.constant.replace("ITEM_", "").replaceAll("_", " ")}</strong>
          <span>${item.rarity}</span>
        </div>
      `).join("")}
    </div>
  `;
}

function openSpecies(mon) {
  document.getElementById("modalTitle").textContent = `#${mon.dex || mon.id} ${speciesFormLabel(mon)}`;
  document.getElementById("modalBody").innerHTML = `
    <div class="species-hero-grid">
      <div class="species-summary">
        ${speciesSpritePanel(mon)}
        <div>
          ${typePills(mon.types)}
          ${pokemonAbilitySections(mon)}
          ${heldItemRows(mon.heldItems)}
        </div>
      </div>
      ${accordionSection("Base Stats", statBars(mon), { mobileOpen: true })}
    </div>
    ${accordionSection("Evolution", `<div class="evolution-chain">${evolutionChain(mon)}${megaFormLinks(mon)}</div>`)}
    ${accordionSection("Locations", locationRows(mon.locations), { className: "species-locations" })}
    ${learnsetSection("Level-Up Learnset", mon.levelUp)}
    ${learnsetSection("TM / TR Moves", mon.tmhm, { showLevel: false })}
    ${learnsetSection("Tutor Moves", mon.tutors, { showLevel: false })}
    ${learnsetSection("Egg Moves", mon.eggMoves || [], { showLevel: false })}
  `;
  showDetailDialog("pokemon");
}

function openSpeciesByConstant(constant) {
  const mon = state.data.species.find((entry) => entry.constant === constant);
  if (mon) openSpecies(mon);
}

function renderEncounters() {
  const container = document.getElementById("encounterList");
  const rows = state.data.encounters.filter((encounter) => matches(`${encounter.name} ${encounter.variants.map((variant) => variant.methods.map((m) => m.mons.map((mon) => mon.name).join(" ")).join(" ")).join(" ")}`));
  container.innerHTML = rows.map((encounter) => `
    <details class="card encounter-card" open>
      <summary><h2>${encounter.name}</h2></summary>
      <div class="encounter-card-body">
      ${encounter.variants.map((variant) => encounterVariant(variant, encounter.hasTimeVariants)).join("")}
      </div>
    </details>
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
  const rows = state.data.tms.filter((tm) => matches(`${tm.label} ${tm.moveName} ${tm.type} ${fmtCategory(tm.category || "")} ${tm.description}`));
  tbody.innerHTML = "";
  rows.forEach((tm) => {
    const row = el("tr", "tm-row");
    row.innerHTML = `
      <td data-label="ID"><strong>${tm.label}</strong></td>
      <td data-label="Move">${tm.moveName}</td>
      <td data-label="Type">${typePills([tm.type])}</td>
      <td data-label="Cat">${moveCategory(tm.category || "")}</td>
      <td data-label="Pow">${tm.power || "-"}</td>
      <td data-label="Acc">${tm.accuracy || "-"}</td>
      <td data-label="PP">${tm.pp || "-"}</td>
      <td data-label="Description">${tm.description}</td>
      <td data-label="Location" class="muted">${tm.location || "TBD"}</td>
    `;
    bindRowActivation(row, () => openTm(tm), `Open details for ${tm.label} ${tm.moveName}`);
    tbody.appendChild(row);
  });
}

function itemIconHtml(item, className = "item-icon") {
  return item?.itemIcon ? `<img class="${className}" src="${item.itemIcon}" alt="">` : "";
}

function renderItems() {
  const tbody = document.getElementById("itemRows");
  const rows = state.data.items.filter((item) => matches(`${item.name} ${item.description} ${item.location}`));
  tbody.innerHTML = "";
  rows.forEach((item) => {
    const row = el("tr", "item-row");
    row.innerHTML = `
      <td data-label="Name"><span class="item-name-cell">${itemIconHtml(item)}<strong>${item.name}</strong></span></td>
      <td data-label="Description">${item.description || "No description."}</td>
      <td data-label="Location" class="muted">${item.location || "TBD"}</td>
    `;
    bindRowActivation(row, () => openItem(item), `Open details for ${item.name}`);
    tbody.appendChild(row);
  });
}

function openItem(item) {
  document.getElementById("modalTitle").textContent = item.name;
  document.getElementById("modalBody").innerHTML = `
    <p>${item.description || "No description."}</p>
    <h3 class="section-title">Locations</h3>
    ${item.locations?.length ? `
      <div class="item-location-list">
        ${item.locations.map((location) => `
          <div class="item-location-row">
            <strong>${location.map}</strong>
            <span>${location.source}</span>
          </div>
        `).join("")}
      </div>
    ` : `<p class="muted">Location TBD.</p>`}
  `;
  showDetailDialog("item");
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
      <p>${moveCategory(tm.category || "")} Power ${tm.power || "-"} / Accuracy ${tm.accuracy || "-"} / PP ${tm.pp || "-"}</p>
      <p>${tm.description || "No description."}</p>
      <p class="muted">${tm.location || "Location TBD"}</p>
    </div>
    <h3 class="section-title">Compatible Pokémon</h3>
    ${speciesCards(compatible)}
  `;
  showDetailDialog("move");
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
    bindRowActivation(row, () => openAbility(ability), `Open details for ${ability.name}`);
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
    <h3 class="section-title">Base Ability Pokémon</h3>
    ${usageList(ability.usage.base)}
    <h3 class="section-title">Innate Ability Pokémon</h3>
    ${usageList(ability.usage.innate)}
  `;
  showDetailDialog("ability");
}

function renderTrainers() {
  const tbody = document.getElementById("trainerRows");
  const trainers = (state.data.trainers || []).filter((trainer) =>
    matches(`${trainer.name} ${trainer.displayName || ""} ${trainer.difficulty || ""} ${trainer.party.map((mon) => trainerMonSearchText(mon)).join(" ")}`)
  ).sort((a, b) =>
    (a.averageLevel ?? trainerAverageLevel(a.party)) - (b.averageLevel ?? trainerAverageLevel(b.party))
    || (a.displayName || a.name).localeCompare(b.displayName || b.name)
  );
  tbody.innerHTML = "";
  trainers.forEach((trainer) => {
    const row = el("tr", "trainer-row");
    row.innerHTML = `
      <td data-label="Name">
        <div class="trainer-name-cell">
          ${sprite(trainer.sprite, "trainer-sprite")}
          <strong>${trainer.displayName || trainer.name}</strong>
        </div>
      </td>
      <td data-label="Party"><div class="trainer-party-details">${trainerPartyHtml(trainer.party)}</div></td>
    `;
    tbody.appendChild(row);
  });
  if (!trainers.length) {
    const row = el("tr");
    row.innerHTML = `<td colspan="2" class="muted">No trainers found.</td>`;
    tbody.appendChild(row);
  }
}

function trainerPartyHtml(party) {
  return `<div class="trainer-party">${party.map((mon) => {
    const monSprite = mon.constant
      ? `<button class="trainer-mon-sprite species-link" type="button" data-species="${mon.constant}">${sprite(mon.sprite, "mini-sprite")}</button>`
      : sprite(mon.sprite, "mini-sprite");
    const monName = mon.constant
      ? `<button class="trainer-mon-name species-link" type="button" data-species="${mon.constant}"><strong>${mon.displayName || mon.name}</strong></button>`
      : `<strong>${mon.displayName || mon.name}</strong>`;
    return `
      <div class="trainer-mon">
        ${monSprite}
        <div class="trainer-mon-info">
          <div class="trainer-mon-top">
            <div class="trainer-mon-title">
              ${monName}
              <span class="muted">Lv ${mon.level || 100}</span>
            </div>
            ${trainerHeldItemIcon(mon)}
          </div>
          ${trainerMonDetailsHtml(mon)}
        </div>
      </div>`;
  }).join("")}</div>`;
}

function trainerAverageLevel(party) {
  if (!party?.length) return 0;
  return party.reduce((sum, mon) => sum + (mon.level || 100), 0) / party.length;
}

function trainerMonSearchText(mon) {
  return [
    mon.name,
    mon.displayName,
    mon.item,
    mon.itemName,
    mon.ability,
    ...(mon.moves || []),
    ...Object.entries(mon.evs || {}).map(([stat, value]) => `${value} ${statLabels[stat] || stat} EV`),
    ...Object.entries(mon.ivs || {}).map(([stat, value]) => `${value} ${statLabels[stat] || stat} IV`),
  ].filter(Boolean).join(" ");
}

function trainerTokenName(value, prefix) {
  if (!value) return "";
  if (!value.startsWith(prefix)) return value;
  return fmtTitle(value, prefix);
}

function trainerMoveLabel(value) {
  return state.data.moves[value]?.name || trainerTokenName(value, "MOVE_");
}

function trainerHeldItemIcon(mon) {
  if (!mon.itemIcon) return "";
  const itemName = mon.itemName || trainerTokenName(mon.itemConstant || mon.item, "ITEM_");
  const itemDescription = mon.itemDescription || "No description.";
  return `
    <button
      class="trainer-held-item-button item-tooltip-target"
      type="button"
      data-item-name="${escapeHtml(itemName)}"
      data-item-description="${escapeHtml(itemDescription)}"
      aria-label="${escapeHtml(itemName)}"
    >
      <img class="trainer-held-item" src="${mon.itemIcon}" alt="">
    </button>
  `;
}

function trainerStatSpreadHtml(label, values) {
  const entries = Object.entries(values || {});
  if (!entries.length) return "";
  if (label === "IVs" && entries.length === 6 && entries.every(([, value]) => Number(value) === 0)) return "";
  return `<div class="trainer-mon-detail trainer-stat-spread"><span>${label}:</span><strong>${entries.map(([stat, value]) => `${value} ${statLabels[stat] || stat}`).join(" / ")}</strong></div>`;
}

function trainerMonDetailsHtml(mon) {
  const rows = [];
  if (mon.ability) {
    rows.push(`<div class="trainer-mon-detail"><span>Ability:</span><strong><button class="trainer-ability ability-pill" type="button" data-ability="${escapeHtml(mon.ability)}">${trainerTokenName(mon.ability, "ABILITY_")}</button></strong></div>`);
  }
  const evs = trainerStatSpreadHtml("EVs", mon.evs);
  const ivs = trainerStatSpreadHtml("IVs", mon.ivs);
  if (evs) rows.push(evs);
  if (ivs) rows.push(ivs);
  if (mon.moves?.length) {
    rows.push(`<div class="trainer-mon-detail trainer-moves"><span>Moves:</span><strong>${mon.moves.map((move) => `- <button class="move-name trainer-move-name" type="button" data-move="${escapeHtml(move)}">${trainerMoveLabel(move)}</button>`).join("<br>")}</strong></div>`);
  }
  return rows.length ? `<div class="trainer-mon-details">${rows.join("")}</div>` : "";
}

init().catch((error) => {
  document.body.innerHTML = `<main><h1>Failed to load docs</h1><pre>${error.stack || error}</pre></main>`;
});
