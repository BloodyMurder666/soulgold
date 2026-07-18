const baseElement = document.querySelector("base");
const siteRootUrl = new URL(baseElement?.getAttribute("href") || "./", window.location.href);
if (baseElement) baseElement.href = siteRootUrl.href;

const state = {
  data: {
    species: [],
    moves: {},
    abilities: {},
    tms: [],
    items: [],
    encounters: [],
    trainers: [],
    guides: [],
    typeIcons: {},
    categoryIcons: {},
    uiIcons: {},
    megaEvolutions: [],
  },
  activeTab: "pokedex",
  query: "",
  filteredSpecies: [],
  selectedTypes: new Set(),
  modalScrollY: 0,
  detail: null,
  renderToken: 0,
};

const loadedData = new Set();
const dataPromises = new Map();

const typeName = (value) => value.replace("TYPE_", "").replaceAll("_", " ");
const moveName = (constant) => state.data.moves[constant]?.name || constant.replace("MOVE_", "").replaceAll("_", " ");
const abilityName = (constant) => state.data.abilities[constant]?.name || constant.replace("ABILITY_", "").replaceAll("_", " ");
const fmtTitle = (value, prefix = "") => value.replace(prefix, "").replaceAll("_", " ").toLowerCase().replace(/\b\w/g, (char) => char.toUpperCase());
const fmtCategory = (value) => fmtTitle(value, "DAMAGE_CATEGORY_");
const statLabels = { hp: "HP", atk: "Atk", def: "Def", spa: "SpA", spd: "SpD", spe: "Spe" };
const searchPlaceholders = {
  pokedex: "Search Pokédex…",
  moves: "Search moves, types, or descriptions…",
  encounters: "Search areas or Pokémon…",
  machines: "Search TMs, moves, types, or locations…",
  items: "Search items or locations…",
  trainers: "Search trainers or parties…",
  abilities: "Search abilities…",
  guides: "Search guides, FAQs, or secrets…",
};
const tabRoutes = {
  pokedex: "pokedex",
  moves: "moves",
  encounters: "encounters",
  machines: "machines",
  items: "items",
  trainers: "trainers",
  abilities: "abilities",
  guides: "guides",
};
const detailKinds = {
  pokedex: "pokemon",
  moves: "move",
  machines: "machine",
  items: "item",
  abilities: "ability",
  guides: "guide",
};
const detailTabs = Object.fromEntries(Object.entries(detailKinds).map(([tab, kind]) => [kind, tab]));
const sectionDataFiles = {
  pokedex: [["species", "data/species.json"]],
  moves: [],
  encounters: [["encounters", "data/encounters.json"]],
  machines: [["tms", "data/machines.json"]],
  items: [["items", "data/items.json"]],
  trainers: [["trainers", "data/trainers.json"]],
  abilities: [["abilityUsage", "data/ability-usage.json"]],
  guides: [["guides", "data/guides.json"]],
};
const tabLabels = {
  pokedex: "Pokédex",
  moves: "Movedex",
  encounters: "Wild Encounters",
  machines: "TMs/HMs",
  items: "Items",
  trainers: "Trainers",
  abilities: "Abilities",
  guides: "Guides",
};
const mobileNavMedia = window.matchMedia("(max-width: 1100px)");
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
  return src ? `<img class="${className}" src="${src}" alt="" loading="lazy" decoding="async">` : `<span class="muted">No sprite</span>`;
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
  const route = routeFromLocation();
  state.activeTab = route.tab;
  state.detail = route.detail;
  applyViewState(route.view);
  syncActiveTabUi();
  history.scrollRestoration = "manual";
  history.replaceState(historyPayload({ detailOpenedInApp: false }), "");
  bindEvents();
  syncMobileNav();
  updateStickyOffset();
  try {
    await loadCommonData();
    await renderActive();
    await renderDetailFromRoute();
  } catch (error) {
    showLoadFailure(error);
  }
}

function bindEvents() {
  document.querySelectorAll(".tab").forEach((link) => {
    link.addEventListener("click", (event) => {
      if (event.button !== 0 || event.metaKey || event.ctrlKey || event.shiftKey || event.altKey) return;
      event.preventDefault();
      setTab(link.dataset.tab);
    });
  });
  document.getElementById("mobileMenuToggle").addEventListener("click", openMobileNav);
  document.getElementById("mobileMenuClose").addEventListener("click", () => closeMobileNav({ restoreFocus: true }));
  document.getElementById("navBackdrop").addEventListener("click", () => closeMobileNav({ restoreFocus: true }));
  document.getElementById("backToTop").addEventListener("click", () => window.scrollTo({ top: 0, behavior: "smooth" }));
  document.getElementById("globalSearch").addEventListener("input", (event) => {
    state.query = event.target.value.trim().toLowerCase();
    window.scrollTo(0, 0);
    syncFilterHistory();
    renderActive();
  });
  document.getElementById("typeFilterToggle").addEventListener("click", toggleTypeFilter);
  document.getElementById("typeFilterPanel").addEventListener("click", handleTypeFilterClick);
  document.addEventListener("click", closeTypeFilterOnOutsideClick);
  const dialog = document.getElementById("detailDialog");
  document.getElementById("closeDialog").addEventListener("click", requestCloseDetail);
  dialog.addEventListener("click", (event) => {
    if (event.target === dialog) requestCloseDetail();
  });
  dialog.addEventListener("cancel", (event) => {
    event.preventDefault();
    requestCloseDetail();
  });
  dialog.addEventListener("close", handleDetailDialogClose);
  document.body.addEventListener("click", handleAbilityClick, true);
  document.body.addEventListener("pointerover", handleAbilityHover);
  document.body.addEventListener("pointerout", handleAbilityOut);
  document.body.addEventListener("click", handleMoveClick, true);
  document.body.addEventListener("click", handleSpeciesLinkClick, true);
  document.body.addEventListener("click", handleSpriteToggle, true);
  document.body.addEventListener("pointerover", handleMoveHover);
  document.body.addEventListener("pointerout", handleMoveOut);
  document.body.addEventListener("pointerover", handleItemHover);
  document.body.addEventListener("pointerout", handleItemOut);
  document.body.addEventListener("click", handleItemTooltipClick, true);
  window.addEventListener("resize", () => {
    updateStickyOffset();
    syncMobileNav();
  });
  window.addEventListener("popstate", (event) => applyLocationRoute(event.state));
  document.addEventListener("keydown", handleMobileNavKeydown);
  document.getElementById("guideList").addEventListener("click", handleGuideSummaryClick);
  document.body.addEventListener("click", handleRetryClick);
}

function relativeRoutePath() {
  const rootPath = siteRootUrl.pathname.endsWith("/") ? siteRootUrl.pathname : `${siteRootUrl.pathname}/`;
  let route = window.location.pathname;
  if (route.startsWith(rootPath)) route = route.slice(rootPath.length);
  route = route.replace(/^\/+|\/+$/g, "").replace(/\/index\.html$/, "");
  if (route === "index.html") route = "";
  return route;
}

function viewFromLocation() {
  const params = new URLSearchParams(window.location.search);
  return {
    query: (params.get("q") || "").trim().toLowerCase(),
    types: (params.get("type") || "").split(",").filter(Boolean).map((type) => `TYPE_${type.toUpperCase().replace(/^TYPE_/, "")}`),
    scrollY: 0,
  };
}

function routeFromLocation() {
  const parts = relativeRoutePath().split("/").filter(Boolean);
  const tab = Object.keys(tabRoutes).find((key) => tabRoutes[key] === parts[0]) || "pokedex";
  const detail = parts[1] && detailKinds[tab] ? { kind: detailKinds[tab], slug: parts[1] } : null;
  return { tab, detail, view: viewFromLocation() };
}

function routeUrl(tab, detail = null, view = null) {
  const route = tabRoutes[tab];
  const path = detail ? `${route}/${detail.slug}/` : `${route}/`;
  const url = new URL(path, siteRootUrl);
  const nextView = view || { query: "", types: [] };
  if (!detail && nextView.query) url.searchParams.set("q", nextView.query);
  if (!detail && nextView.types?.length && tab === "pokedex") {
    url.searchParams.set("type", nextView.types.map((type) => type.replace(/^TYPE_/, "").toLowerCase()).join(","));
  }
  return url;
}

async function loadJson(path) {
  const response = await fetch(new URL(path, siteRootUrl));
  if (!response.ok) throw new Error(`${response.status} ${response.statusText} while loading ${path}`);
  return response.json();
}

async function loadData(key, path) {
  if (loadedData.has(key)) return;
  if (!dataPromises.has(key)) {
    dataPromises.set(key, loadJson(path).then((payload) => {
      if (key === "common") {
        Object.assign(state.data, payload);
      } else if (key === "speciesDetails") {
        state.data.species.forEach((mon) => Object.assign(mon, payload[mon.constant] || {}));
      } else if (key === "abilityUsage") {
        Object.entries(payload).forEach(([constant, usage]) => {
          if (state.data.abilities[constant]) state.data.abilities[constant].usage = usage;
        });
      } else {
        state.data[key] = payload;
      }
      loadedData.add(key);
      dataPromises.delete(key);
    }).catch((error) => {
      dataPromises.delete(key);
      throw error;
    }));
  }
  await dataPromises.get(key);
}

async function loadCommonData() {
  await loadData("common", "data/common.json");
}

async function ensureSectionData(tab) {
  await loadCommonData();
  await Promise.all((sectionDataFiles[tab] || []).map(([key, path]) => loadData(key, path)));
}

async function ensureSpeciesDetails() {
  await loadData("species", "data/species.json");
  await loadData("speciesDetails", "data/species-details.json");
}

function currentViewState(scrollY = window.scrollY) {
  return {
    query: state.query,
    types: [...state.selectedTypes],
    scrollY,
  };
}

function applyViewState(view = {}) {
  state.query = String(view.query || "").toLowerCase();
  state.selectedTypes = new Set(view.types || []);
  const search = document.getElementById("globalSearch");
  if (search) search.value = state.query;
}

function historyPayload(options = {}) {
  return {
    docs: true,
    tab: state.activeTab,
    detail: state.detail,
    view: currentViewState(options.scrollY),
    detailOpenedInApp: Boolean(options.detailOpenedInApp),
  };
}

function snapshotCurrentHistory() {
  const previous = history.state || {};
  const payload = historyPayload({
    scrollY: document.body.classList.contains("modal-open") ? state.modalScrollY : window.scrollY,
    detailOpenedInApp: previous.detailOpenedInApp,
  });
  const url = state.detail ? window.location.href : routeUrl(state.activeTab, null, payload.view);
  history.replaceState(payload, "", url);
}

function syncFilterHistory() {
  if (state.detail) return;
  const previous = history.state || {};
  history.replaceState(
    historyPayload({ detailOpenedInApp: previous.detailOpenedInApp }),
    "",
    routeUrl(state.activeTab, null, currentViewState()),
  );
}

async function applyLocationRoute(historyState = null) {
  const route = routeFromLocation();
  const previousTab = state.activeTab;
  const previousQuery = state.query;
  const previousTypes = [...state.selectedTypes].join(",");
  state.activeTab = route.tab;
  state.detail = route.detail;
  applyViewState(historyState?.view || route.view);
  syncActiveTabUi();
  closeMobileNav();

  const viewChanged = previousQuery !== state.query || previousTypes !== [...state.selectedTypes].join(",");
  const sectionNeedsData = (sectionDataFiles[state.activeTab] || [])
    .some(([key]) => !loadedData.has(key));
  if (previousTab !== state.activeTab || viewChanged || sectionNeedsData) {
    await renderActive();
  }
  if (state.detail) {
    await renderDetailFromRoute();
  } else {
    closeDetailVisual();
    const scrollY = Number(historyState?.view?.scrollY || 0);
    requestAnimationFrame(() => window.scrollTo(0, scrollY));
  }
}

async function navigateDetail(kind, slug) {
  const tab = detailTabs[kind];
  if (!tab || !slug) return;
  if (state.detail?.kind === kind && state.detail.slug === slug) return;
  snapshotCurrentHistory();
  const tabChanged = state.activeTab !== tab;
  state.activeTab = tab;
  state.detail = { kind, slug };
  if (tabChanged) {
    state.query = "";
    state.selectedTypes.clear();
    syncTypeFilter();
    document.getElementById("globalSearch").value = "";
  }
  history.pushState(
    historyPayload({ detailOpenedInApp: true }),
    "",
    routeUrl(tab, state.detail),
  );
  syncActiveTabUi();
  closeMobileNav();
  if (tabChanged) {
    window.scrollTo(0, 0);
    await renderActive();
  }
  await renderDetailFromRoute();
}

function requestCloseDetail() {
  if (!state.detail) {
    closeDetailVisual();
    return;
  }
  if (history.state?.detailOpenedInApp) {
    history.back();
    return;
  }
  state.detail = null;
  history.replaceState(historyPayload(), "", routeUrl(state.activeTab, null, currentViewState()));
  syncActiveTabUi();
  closeDetailVisual();
  if (state.activeTab === "guides") renderGuides();
}

function closeDetailVisual() {
  const dialog = document.getElementById("detailDialog");
  if (dialog.open) dialog.close();
  else unlockBodyScroll();
  document.querySelectorAll(".guide-card[open]").forEach((guide) => { guide.open = false; });
}

function setPanelStatus(tab, message, options = {}) {
  const status = document.getElementById(`${tab}Status`);
  if (!status) return;
  status.hidden = false;
  status.classList.toggle("loading", Boolean(options.loading));
  status.classList.toggle("error", Boolean(options.error));
  status.textContent = message;
}

function setPanelError(tab, error) {
  const status = document.getElementById(`${tab}Status`);
  if (!status) return;
  status.hidden = false;
  status.className = "panel-status error";
  status.innerHTML = `<strong>Could not load ${escapeHtml(tabLabels[tab])}.</strong> <button type="button" data-retry-section>Retry</button><span class="sr-only"> ${escapeHtml(error.message || error)}</span>`;
}

function handleRetryClick(event) {
  if (!event.target.closest("[data-retry-section]")) return;
  renderActive();
}

function showLoadFailure(error) {
  setPanelError(state.activeTab, error);
}

function syncActiveTabUi() {
  document.body.dataset.activeTab = state.activeTab;
  document.title = `${tabLabels[state.activeTab]} · Soulgold Documentation`;
  const search = document.getElementById("globalSearch");
  search.placeholder = searchPlaceholders[state.activeTab] || "Search…";
  document.querySelectorAll(".tab").forEach((link) => {
    const active = link.dataset.tab === state.activeTab;
    link.classList.toggle("active", active);
    if (active) link.setAttribute("aria-current", "page");
    else link.removeAttribute("aria-current");
  });
  document.querySelectorAll(".panel").forEach((panel) => panel.classList.toggle("active", panel.id === state.activeTab));
}

function openMobileNav() {
  if (!mobileNavMedia.matches) return;
  const nav = document.getElementById("sectionNav");
  const toggle = document.getElementById("mobileMenuToggle");
  nav.inert = false;
  nav.setAttribute("aria-hidden", "false");
  document.body.classList.add("nav-open");
  toggle.setAttribute("aria-expanded", "true");
  toggle.setAttribute("aria-label", "Close documentation sections");
  requestAnimationFrame(() => (nav.querySelector(".tab.active") || document.getElementById("mobileMenuClose")).focus());
}

function closeMobileNav({ restoreFocus = false } = {}) {
  const wasOpen = document.body.classList.contains("nav-open");
  const nav = document.getElementById("sectionNav");
  const toggle = document.getElementById("mobileMenuToggle");
  document.body.classList.remove("nav-open");
  toggle.setAttribute("aria-expanded", "false");
  toggle.setAttribute("aria-label", "Open documentation sections");
  if (mobileNavMedia.matches) {
    nav.inert = true;
    nav.setAttribute("aria-hidden", "true");
  } else {
    nav.inert = false;
    nav.removeAttribute("aria-hidden");
  }
  if (restoreFocus && wasOpen) toggle.focus();
}

function syncMobileNav() {
  closeMobileNav();
}

function handleMobileNavKeydown(event) {
  if (!document.body.classList.contains("nav-open")) return;
  if (event.key === "Escape") {
    event.preventDefault();
    closeMobileNav({ restoreFocus: true });
    return;
  }
  if (event.key !== "Tab") return;
  const focusable = [...document.querySelectorAll("#sectionNav button, #sectionNav a")];
  if (!focusable.length) return;
  const first = focusable[0];
  const last = focusable.at(-1);
  if (event.shiftKey && document.activeElement === first) {
    event.preventDefault();
    last.focus();
  } else if (!event.shiftKey && document.activeElement === last) {
    event.preventDefault();
    first.focus();
  }
}

function updateStickyOffset() {
  const chrome = document.querySelector(".top-chrome");
  if (!chrome) return;
  const scale = Number.parseFloat(getComputedStyle(document.body).zoom) || 1;
  document.documentElement.style.setProperty("--top-chrome-height", `${Math.ceil(chrome.getBoundingClientRect().height / scale)}px`);
}

async function setTab(tab, { updateHistory = true } = {}) {
  if (!Object.hasOwn(tabRoutes, tab)) tab = "pokedex";
  if (tab === state.activeTab && !state.detail && relativeRoutePath() === tabRoutes[tab]) {
    closeMobileNav({ restoreFocus: true });
    return;
  }
  snapshotCurrentHistory();
  hideAbilityTooltip();
  hideMoveTooltip();
  hideItemTooltip();
  updateStickyOffset();
  state.activeTab = tab;
  state.detail = null;
  state.query = "";
  state.selectedTypes.clear();
  syncTypeFilter();
  const search = document.getElementById("globalSearch");
  search.value = "";
  closeTypeFilter();
  closeMobileNav({ restoreFocus: true });
  if (updateHistory) history.pushState(historyPayload(), "", routeUrl(tab));
  syncActiveTabUi();
  closeDetailVisual();
  window.scrollTo(0, 0);
  await renderActive();
}

function matches(text) {
  return !state.query || text.toLowerCase().includes(state.query);
}

async function renderActive() {
  const tab = state.activeTab;
  const token = ++state.renderToken;
  setPanelStatus(tab, `Loading ${tabLabels[tab]}…`, { loading: true });
  try {
    await ensureSectionData(tab);
  } catch (error) {
    if (token === state.renderToken && tab === state.activeTab) setPanelError(tab, error);
    return;
  }
  if (token !== state.renderToken || tab !== state.activeTab) return;
  if (tab === "pokedex") renderDex();
  if (tab === "moves") renderMovedex();
  if (tab === "encounters") renderEncounters();
  if (tab === "machines") renderTms();
  if (tab === "items") renderItems();
  if (tab === "abilities") renderAbilities();
  if (tab === "trainers") renderTrainers();
  if (tab === "guides") renderGuides();
}

function renderDex() {
  renderTypeFilter();
  state.filteredSpecies = state.data.species.filter((mon) =>
    matches(`${mon.dex} ${mon.name} ${speciesFormLabel(mon)} ${mon.types.map(typeName).join(" ")}`)
    && matchesSelectedTypes(mon)
  );
  renderDexRows();
  setPanelStatus(
    "pokedex",
    state.filteredSpecies.length
      ? `${state.filteredSpecies.length} Pokémon`
      : state.query || state.selectedTypes.size ? "No Pokémon match the current search and type filters." : "No Pokémon are available.",
  );
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
  syncFilterHistory();
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
    if (!dialog.contains(document.activeElement)) {
      document.getElementById("closeDialog").focus({ preventScroll: true });
    }
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
    const scaleX = root.offsetWidth ? rootRect.width / root.offsetWidth : 1;
    const scaleY = root.offsetHeight ? rootRect.height / root.offsetHeight : 1;
    const anchorX = (anchor.x - rootRect.left) / scaleX + root.scrollLeft;
    const anchorY = (anchor.y - rootRect.top) / scaleY + root.scrollTop;
    const visibleLeft = root.scrollLeft + 12;
    const visibleTop = root.scrollTop + 12;
    const visibleRight = root.scrollLeft + root.clientWidth - width - 12;
    const visibleBottom = root.scrollTop + root.clientHeight - height - 12;
    let left = anchorX + offsetX;
    let top = anchorY + offsetY;
    if (left > visibleRight) left = anchorX - width - offsetX;
    if (top > visibleBottom) top = anchorY - height - offsetY;
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
  event.stopImmediatePropagation();
  openAbilityByReference(button.dataset.ability);
}

function handleAbilityHover(event) {
  const button = event.target.closest(".ability-pill");
  if (button && !button.contains(event.relatedTarget)) showAbilityTooltip(button, event);
}

function handleAbilityOut(event) {
  const button = event.target.closest(".ability-pill");
  if (button && !button.contains(event.relatedTarget)) hideAbilityTooltip();
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
  if (button && !button.contains(event.relatedTarget)) showItemTooltip(button, event);
}

function handleItemOut(event) {
  const button = event.target.closest(".item-tooltip-target");
  if (button && !button.contains(event.relatedTarget)) hideItemTooltip();
}

function handleItemTooltipClick(event) {
  const button = event.target.closest(".item-tooltip-target");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  if (button.dataset.item) openItemByConstant(button.dataset.item, button, event);
  else showItemTooltip(button, event);
}

function handleMoveHover(event) {
  const button = event.target.closest(".move-name");
  if (button && !button.contains(event.relatedTarget)) showMoveTooltip(button, event);
}

function handleMoveOut(event) {
  const button = event.target.closest(".move-name");
  if (button && !button.contains(event.relatedTarget)) hideMoveTooltip();
}

function handleMoveClick(event) {
  const button = event.target.closest(".move-name");
  if (!button) return;
  event.preventDefault();
  event.stopPropagation();
  event.stopImmediatePropagation();
  openMoveByReference(button.dataset.move);
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
  const formChange = (state.data.megaEvolutions || []).find((edge) => edge.target === mon.constant);
  if (formChange) {
    return state.data.species.find((entry) => entry.constant === formChange.source) || mon;
  }
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
  const ogerponForm = mon.constant.match(/^SPECIES_OGERPON_(TEAL|WELLSPRING|HEARTHFLAME|CORNERSTONE)(?:_TERA)?$/);
  if (ogerponForm) {
    const mask = ogerponForm[1][0] + ogerponForm[1].slice(1).toLowerCase();
    return `${mon.name} (${mask} Mask)`;
  }
  if (mon.constant === "SPECIES_ZACIAN_CROWNED") return `${mon.name} (Crowned Sword)`;
  if (mon.constant === "SPECIES_ZAMAZENTA_CROWNED") return `${mon.name} (Crowned Shield)`;
  if (mon.constant.includes("_MEGA_X")) return `${mon.name} X`;
  if (mon.constant.includes("_MEGA_Y")) return `${mon.name} Y`;
  if (mon.constant.includes("_MEGA_Z")) return `${mon.name} Z`;
  if (mon.constant.includes("_MEGA")) return `${mon.name} Mega`;
  return mon.name;
}

function megaTargetLabel(mon) {
  if (/^SPECIES_OGERPON_(?:TEAL|WELLSPRING|HEARTHFLAME|CORNERSTONE)_TERA$/.test(mon.constant)) {
    return `${speciesFormLabel(mon)} Mega`;
  }
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
        <button class="evolution-name species-link" type="button" data-species="${base?.constant || chainMon.constant}">${sprite(base?.sprite || chainMon.sprite, "tiny-sprite")}<strong>${speciesFormLabel(base || chainMon)}</strong></button>
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
  navigateDetail("pokemon", mon.slug);
}

function renderSpeciesDetail(mon) {
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

async function openSpeciesByConstant(constant) {
  await loadData("species", "data/species.json");
  const mon = state.data.species.find((entry) => entry.constant === constant);
  if (mon) await navigateDetail("pokemon", mon.slug);
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
  setPanelStatus("encounters", rows.length ? `${rows.length} encounter areas` : "No encounter areas match this search.");
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

function moveMetric(value, options = {}) {
  if (!value && value !== 0) return "-";
  if (options.zeroAsDash && Number(value) === 0) return "-";
  if (options.signed && Number(value) > 0) return `+${value}`;
  return String(value);
}

function renderMovedex() {
  const tbody = document.getElementById("moveRows");
  const rows = Object.values(state.data.moves || {})
    .filter((move) => move.constant !== "MOVE_NONE")
    .filter((move) => matches(`${move.id} ${move.constant} ${move.name} ${move.type} ${fmtCategory(move.category || "")} ${move.description || ""}`))
    .sort((a, b) => (a.id ?? Number.MAX_SAFE_INTEGER) - (b.id ?? Number.MAX_SAFE_INTEGER));

  tbody.innerHTML = "";
  rows.forEach((move) => {
    const row = el("tr", "move-dex-row");
    row.innerHTML = `
      <td data-label="#"><strong>${move.id ?? "-"}</strong></td>
      <td data-label="Move"><strong>${escapeHtml(move.name)}</strong></td>
      <td data-label="Type">${typePills([move.type])}</td>
      <td data-label="Cat">${moveCategory(move.category || "")}</td>
      <td data-label="Pow">${moveMetric(move.power, { zeroAsDash: true })}</td>
      <td data-label="Acc">${moveMetric(move.accuracy, { zeroAsDash: true })}</td>
      <td data-label="PP">${moveMetric(move.pp, { zeroAsDash: true })}</td>
      <td data-label="Priority">${moveMetric(move.priority, { signed: true })}</td>
      <td data-label="Description">${escapeHtml(move.description || "No description.")}</td>
    `;
    bindRowActivation(row, () => openMove(move), `Open details for ${move.name}`);
    tbody.appendChild(row);
  });

  if (!rows.length) {
    const row = el("tr");
    row.innerHTML = `<td colspan="9" class="muted">No moves found.</td>`;
    tbody.appendChild(row);
  }
  setPanelStatus("moves", rows.length ? `${rows.length} moves` : "No moves match this search.");
}

function moveLearners(moveConstant) {
  const hasMove = (moves) => (moves || []).some((entry) => (typeof entry === "string" ? entry : entry.move) === moveConstant);
  return [
    ["Level-up", state.data.species.filter((mon) => hasMove(mon.levelUp))],
    ["TM / HM", state.data.species.filter((mon) => hasMove(mon.tmhm))],
    ["Tutor", state.data.species.filter((mon) => hasMove(mon.tutors))],
    ["Egg move", state.data.species.filter((mon) => hasMove(mon.eggMoves))],
  ].filter(([, species]) => species.length);
}

function openMove(move) {
  navigateDetail("move", move.slug);
}

function openMoveByReference(reference) {
  const move = state.data.moves[reference]
    || Object.values(state.data.moves).find((entry) => entry.name === reference);
  if (move) openMove(move);
}

function renderMoveDetail(move) {
  const learners = moveLearners(move.constant);
  document.getElementById("modalTitle").textContent = `#${move.id ?? "-"} ${move.name}`;
  document.getElementById("modalBody").innerHTML = `
    <div class="move-detail-summary">
      ${typePills([move.type])}
      <span>${moveCategory(move.category || "")}</span>
      <dl>
        <div><dt>Power</dt><dd>${moveMetric(move.power, { zeroAsDash: true })}</dd></div>
        <div><dt>Accuracy</dt><dd>${moveMetric(move.accuracy, { zeroAsDash: true })}</dd></div>
        <div><dt>PP</dt><dd>${moveMetric(move.pp, { zeroAsDash: true })}</dd></div>
        <div><dt>Priority</dt><dd>${moveMetric(move.priority, { signed: true })}</dd></div>
      </dl>
      <p>${escapeHtml(move.description || "No description.")}</p>
    </div>
    <h3 class="section-title">Learned by</h3>
    ${learners.length ? `<div class="move-learner-groups">${learners.map(([label, species]) => `
      <details class="move-learner-group">
        <summary><strong>${label}</strong><span>${species.length} Pokémon</span></summary>
        <div class="move-learner-body">${speciesCards(species)}</div>
      </details>
    `).join("")}</div>` : `<p class="muted">No documented learn method.</p>`}
  `;
  showDetailDialog("move");
}

function renderTms() {
  const tbody = document.getElementById("tmRows");
  const rows = state.data.tms.filter((tm) => matches(`${tm.label} ${tm.moveName} ${tm.type} ${fmtCategory(tm.category || "")} ${tm.description} ${tm.location}`));
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
  if (!rows.length) {
    const row = el("tr");
    row.innerHTML = `<td colspan="9" class="muted">No TMs or HMs match this search.</td>`;
    tbody.appendChild(row);
  }
  setPanelStatus("machines", rows.length ? `${rows.length} machines` : "No TMs or HMs match this search.");
}

function itemIconHtml(item, className = "item-icon") {
  return item?.itemIcon
    ? `<img class="${className}" src="${item.itemIcon}" alt="" loading="lazy" decoding="async">`
    : "";
}

function itemLocationLines(location) {
  const entries = String(location || "TBD").split(/;\s*/).filter(Boolean);
  return `<span class="location-lines">${entries.map((entry) => `<span>${escapeHtml(entry)}</span>`).join("")}</span>`;
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
      <td data-label="Location" class="muted">${itemLocationLines(item.location)}</td>
    `;
    bindRowActivation(row, () => openItem(item), `Open details for ${item.name}`);
    tbody.appendChild(row);
  });
  if (!rows.length) {
    const row = el("tr");
    row.innerHTML = `<td colspan="3" class="muted">No items match this search.</td>`;
    tbody.appendChild(row);
  }
  setPanelStatus("items", rows.length ? `${rows.length} items` : "No items match this search.");
}

function openItem(item) {
  navigateDetail("item", item.slug);
}

async function openItemByConstant(constant, fallback, event) {
  await loadData("items", "data/items.json");
  const item = state.data.items.find((entry) => entry.constant === constant);
  if (item) openItem(item);
  else if (fallback) showItemTooltip(fallback, event);
}

function renderItemDetail(item) {
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
  navigateDetail("machine", tm.slug);
}

function renderTmDetail(tm) {
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
    const usage = ability.usage || { base: [], innate: [] };
    row.innerHTML = `<h2>${ability.name}</h2><p>${ability.description}</p><p class="muted">${usage.base.length} base / ${usage.innate.length} innate</p>`;
    bindRowActivation(row, () => openAbility(ability), `Open details for ${ability.name}`);
    container.appendChild(row);
  });
  setPanelStatus("abilities", abilities.length ? `${abilities.length} abilities` : "No abilities match this search.");
}

function usageList(list) {
  return speciesCards(list);
}

function openAbility(ability) {
  navigateDetail("ability", ability.slug);
}

function openAbilityByReference(reference) {
  const ability = state.data.abilities[reference]
    || Object.values(state.data.abilities).find((entry) => entry.name === reference);
  if (ability) openAbility(ability);
}

function renderAbilityDetail(ability) {
  const usage = ability.usage || { base: [], innate: [] };
  document.getElementById("modalTitle").textContent = ability.name;
  document.getElementById("modalBody").innerHTML = `
    <p>${ability.description}</p>
    <h3 class="section-title">Base Ability Pokémon</h3>
    ${usageList(usage.base)}
    <h3 class="section-title">Innate Ability Pokémon</h3>
    ${usageList(usage.innate)}
  `;
  showDetailDialog("ability");
}

async function recordForDetail(detail) {
  if (detail.kind === "pokemon") {
    await ensureSpeciesDetails();
    return state.data.species.find((entry) => entry.slug === detail.slug);
  }
  if (detail.kind === "move") {
    await ensureSpeciesDetails();
    return Object.values(state.data.moves).find((entry) => entry.slug === detail.slug);
  }
  if (detail.kind === "machine") {
    await Promise.all([loadData("tms", "data/machines.json"), ensureSpeciesDetails()]);
    return state.data.tms.find((entry) => entry.slug === detail.slug);
  }
  if (detail.kind === "item") {
    await loadData("items", "data/items.json");
    return state.data.items.find((entry) => entry.slug === detail.slug);
  }
  if (detail.kind === "ability") {
    await loadData("abilityUsage", "data/ability-usage.json");
    return Object.values(state.data.abilities).find((entry) => entry.slug === detail.slug);
  }
  if (detail.kind === "guide") {
    await loadData("guides", "data/guides.json");
    return state.data.guides.find((entry) => entry.slug === detail.slug);
  }
  return null;
}

async function renderDetailFromRoute() {
  const detail = state.detail;
  if (!detail) {
    closeDetailVisual();
    return;
  }
  const detailKey = `${detail.kind}:${detail.slug}`;
  if (detail.kind !== "guide") {
    document.getElementById("modalTitle").textContent = "Loading details…";
    document.getElementById("modalBody").innerHTML = `<div class="detail-loading" role="status">Loading details…</div>`;
    showDetailDialog("loading");
  }
  try {
    const record = await recordForDetail(detail);
    if (!state.detail || `${state.detail.kind}:${state.detail.slug}` !== detailKey) return;
    if (!record) {
      if (detail.kind === "guide") {
        setPanelStatus("guides", "This guide could not be found.", { error: true });
      } else {
        document.getElementById("modalTitle").textContent = "Page not found";
        document.getElementById("modalBody").innerHTML = `<p>The requested documentation entry does not exist.</p>`;
      }
      document.title = `Page not found · Soulgold Documentation`;
      return;
    }
    if (detail.kind === "pokemon") renderSpeciesDetail(record);
    if (detail.kind === "move") renderMoveDetail(record);
    if (detail.kind === "machine") renderTmDetail(record);
    if (detail.kind === "item") renderItemDetail(record);
    if (detail.kind === "ability") renderAbilityDetail(record);
    if (detail.kind === "guide") {
      syncGuideDetail();
      document.title = `${record.title} · Guides · Soulgold Documentation`;
      return;
    }
    document.title = `${document.getElementById("modalTitle").textContent} · ${tabLabels[state.activeTab]} · Soulgold Documentation`;
  } catch (error) {
    if (detail.kind === "guide") setPanelError("guides", error);
    else {
      document.getElementById("modalTitle").textContent = "Could not load details";
      document.getElementById("modalBody").innerHTML = `<p>Try again after reloading this page.</p>`;
    }
  }
}

function handleGuideSummaryClick(event) {
  const summary = event.target.closest(".guide-card > summary");
  if (!summary) return;
  event.preventDefault();
  const guide = summary.closest(".guide-card");
  const slug = guide.dataset.guideSlug;
  if (state.detail?.kind === "guide" && state.detail.slug === slug) requestCloseDetail();
  else navigateDetail("guide", slug);
}

function syncGuideDetail() {
  document.querySelectorAll(".guide-card").forEach((guide) => {
    guide.open = state.detail?.kind === "guide" && guide.dataset.guideSlug === state.detail.slug;
  });
  const selected = state.detail?.kind === "guide"
    ? document.querySelector(`.guide-card[data-guide-slug="${CSS.escape(state.detail.slug)}"]`)
    : null;
  if (selected) requestAnimationFrame(() => selected.scrollIntoView({ block: "start" }));
}

function guideUrl(value, guide, options = {}) {
  const url = String(value || "").trim().replace(/^<|>$/g, "");
  if (!url) return "#";
  if (url.startsWith("#")) return url;
  if (url.startsWith("/")) return new URL(url.replace(/^\/+/, ""), siteRootUrl).href;
  if (/^https?:\/\//i.test(url)) return url;
  if (options.allowMail && /^mailto:/i.test(url)) return url;
  if (/^[a-z][a-z0-9+.-]*:/i.test(url)) return "#";

  try {
    const sourceUrl = new URL(guide.source || "guides/", siteRootUrl);
    const resolved = new URL(url, sourceUrl);
    if (resolved.pathname.toLowerCase().endsWith(".md")) {
      const source = decodeURIComponent(resolved.pathname.slice(siteRootUrl.pathname.length));
      const targetGuide = state.data.guides.find((entry) => entry.source === source);
      if (targetGuide) return `${routeUrl("guides", { kind: "guide", slug: targetGuide.slug }).href}${resolved.hash}`;
    }
    return resolved.href;
  } catch (_error) {
    return "#";
  }
}

function guideInline(markdown, guide) {
  const tokens = [];
  const stash = (html) => {
    const token = `\uE000${tokens.length}\uE001`;
    tokens.push(html);
    return token;
  };

  let value = String(markdown || "");
  value = value.replace(/!\[([^\]]*)\]\(([^)\s]+)(?:\s+"[^"]*")?\)/g, (_match, alt, url) => stash(
    `<img class="guide-image" src="${escapeHtml(guideUrl(url, guide))}" alt="${escapeHtml(alt)}" loading="lazy" decoding="async">`
  ));
  value = value.replace(/\[([^\]]+)\]\(([^)\s]+)(?:\s+"[^"]*")?\)/g, (_match, label, url) => stash(
    `<a href="${escapeHtml(guideUrl(url, guide, { allowMail: true }))}">${escapeHtml(label)}</a>`
  ));
  value = value.replace(/`([^`]+)`/g, (_match, code) => stash(`<code>${escapeHtml(code)}</code>`));
  value = escapeHtml(value)
    .replace(/\*\*([^*]+)\*\*/g, "<strong>$1</strong>")
    .replace(/~~([^~]+)~~/g, "<s>$1</s>")
    .replace(/\*([^*]+)\*/g, "<em>$1</em>");
  return value.replace(/\uE000(\d+)\uE001/g, (_match, index) => tokens[Number(index)] || "");
}

function renderGuideMarkdown(markdown, guide) {
  const lines = String(markdown || "").replace(/\r\n?/g, "\n").split("\n");
  const output = [];
  let paragraph = [];
  let listType = "";
  let codeLines = [];
  let codeLanguage = "";
  let inCode = false;

  const flushParagraph = () => {
    if (!paragraph.length) return;
    output.push(`<p>${guideInline(paragraph.join(" "), guide)}</p>`);
    paragraph = [];
  };
  const closeList = () => {
    if (!listType) return;
    output.push(`</${listType}>`);
    listType = "";
  };

  lines.forEach((line) => {
    const trimmed = line.trim();
    const fence = trimmed.match(/^```\s*([A-Za-z0-9_-]*)/);
    if (fence) {
      flushParagraph();
      closeList();
      if (inCode) {
        output.push(`<pre><code${codeLanguage ? ` class="language-${escapeHtml(codeLanguage)}"` : ""}>${escapeHtml(codeLines.join("\n"))}</code></pre>`);
        codeLines = [];
        codeLanguage = "";
        inCode = false;
      } else {
        inCode = true;
        codeLanguage = fence[1] || "";
      }
      return;
    }
    if (inCode) {
      codeLines.push(line);
      return;
    }

    if (!trimmed) {
      flushParagraph();
      closeList();
      return;
    }

    const heading = trimmed.match(/^(#{2,4})\s+(.+)$/);
    if (heading) {
      flushParagraph();
      closeList();
      const level = heading[1].length;
      output.push(`<h${level}>${guideInline(heading[2], guide)}</h${level}>`);
      return;
    }

    if (/^(?:---+|\*\*\*+)$/.test(trimmed)) {
      flushParagraph();
      closeList();
      output.push("<hr>");
      return;
    }

    const image = trimmed.match(/^!\[([^\]]*)\]\(([^)\s]+)(?:\s+"[^"]*")?\)$/);
    if (image) {
      flushParagraph();
      closeList();
      output.push(`<figure><img class="guide-image" src="${escapeHtml(guideUrl(image[2], guide))}" alt="${escapeHtml(image[1])}" loading="lazy" decoding="async">${image[1] ? `<figcaption>${escapeHtml(image[1])}</figcaption>` : ""}</figure>`);
      return;
    }

    const unordered = trimmed.match(/^[-*+]\s+(.+)$/);
    const ordered = trimmed.match(/^\d+[.)]\s+(.+)$/);
    if (unordered || ordered) {
      flushParagraph();
      const nextType = ordered ? "ol" : "ul";
      if (listType && listType !== nextType) closeList();
      if (!listType) {
        listType = nextType;
        output.push(`<${listType}>`);
      }
      output.push(`<li>${guideInline((ordered || unordered)[1], guide)}</li>`);
      return;
    }

    const quote = trimmed.match(/^>\s?(.*)$/);
    if (quote) {
      flushParagraph();
      closeList();
      output.push(`<blockquote>${guideInline(quote[1], guide)}</blockquote>`);
      return;
    }

    closeList();
    paragraph.push(trimmed);
  });

  flushParagraph();
  closeList();
  if (inCode) output.push(`<pre><code>${escapeHtml(codeLines.join("\n"))}</code></pre>`);
  return output.join("");
}

function renderGuides() {
  const container = document.getElementById("guideList");
  const guides = (state.data.guides || []).filter((guide) =>
    matches(`${guide.title} ${guide.summary} ${guide.category} ${guide.content}`)
  );

  if (!guides.length) {
    const hasPublishedGuides = Boolean(state.data.guides?.length);
    container.innerHTML = hasPublishedGuides
      ? `<div class="guide-empty"><h3>No guides found</h3><p class="muted">Try another search.</p></div>`
      : `<div class="guide-empty"><h3>No guides published yet</h3><p class="muted">Player guides will appear here when they are added.</p></div>`;
    setPanelStatus("guides", hasPublishedGuides ? "No guides match this search." : "No guides have been published yet.");
    return;
  }

  container.innerHTML = guides.map((guide) => `
    <details class="guide-card" id="guide-${escapeHtml(guide.slug)}" data-guide-slug="${escapeHtml(guide.slug)}">
      <summary>
        <span class="guide-category">${escapeHtml(guide.category)}</span>
        <span class="guide-summary-copy">
          <strong>${escapeHtml(guide.title)}</strong>
          ${guide.summary ? `<span>${escapeHtml(guide.summary)}</span>` : ""}
        </span>
        <span class="guide-expand" aria-hidden="true"></span>
      </summary>
      <article class="guide-content">${renderGuideMarkdown(guide.content, guide)}</article>
    </details>
  `).join("");
  setPanelStatus("guides", `${guides.length} guides`);
  syncGuideDetail();
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
  setPanelStatus("trainers", trainers.length ? `${trainers.length} trainers` : "No trainers match this search.");
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
      data-item="${escapeHtml(mon.itemConstant || "")}"
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
