#!/usr/bin/env python3

from __future__ import annotations

import argparse
import os
import sys
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT))

from tools import analyze_species_availability as availability  # noqa: E402
from tools import analyze_trainer_party_diversity as trainer_report  # noqa: E402
from tools import render_trainer_party_diversity_html as visual  # noqa: E402


DEFAULT_OUTPUT = REPO_ROOT / "tools/species_availability_report.html"


def esc(value: object) -> str:
    return visual.esc(value)


def rel_path(path: Path, output_path: Path) -> str:
    return os.path.relpath(path, output_path.parent).replace(os.sep, "/")


def species_img(
    constant: str,
    entries: dict[str, trainer_report.SpeciesEntry],
    output_path: Path,
    class_name: str = "mon-icon",
) -> str:
    return visual.species_img(constant, entries, output_path, class_name)


def type_chips(entry: trainer_report.SpeciesEntry) -> str:
    return visual.type_chips(trainer_report.type_names(entry.types))


def card_search(*values: object) -> str:
    return esc(" ".join(str(value) for value in values if value))


def format_species(constant: str, entries: dict[str, trainer_report.SpeciesEntry]) -> str:
    return trainer_report.display_species(constant, entries)


def method_badges(methods: set[str] | list[str]) -> str:
    return "".join(f'<span class="tag">{esc(method)}</span>' for method in sorted(methods))


def compact_maps(maps: set[str], limit: int = 4) -> str:
    return trainer_report.compact_list({availability.format_map_name(map_name) for map_name in maps}, limit)


def gift_label(gift: availability.GiftMon) -> str:
    level = "Egg" if gift.is_egg else f"L{gift.level}" if gift.level is not None else "L?"
    return f"{gift.location} {level}"


def grotto_label(grotto: availability.GrottoMon) -> str:
    locations = ", ".join(availability.format_map_name(map_name) for map_name in grotto.source_maps)
    if not locations:
        locations = availability.format_map_name(grotto.grotto_map)
    return f"{locations} L{grotto.level}"


def source_tags(labels: list[str], limit: int = 4) -> str:
    visible = labels[:limit]
    tags = "".join(f'<span class="source-tag">{esc(label)}</span>' for label in visible)
    if len(labels) > limit:
        tags += f'<span class="source-tag more">+{len(labels) - limit}</span>'
    return tags


def render_summary(counts: dict[str, int]) -> str:
    cards = [
        ("Wild Species", counts["wild_species"]),
        ("Gift Species", counts["gift_species"]),
        ("Grotto Species", counts["grotto_species"]),
        ("Available", counts["available_species"]),
        ("Missing", counts["missing_species"]),
        ("Grotto Only", counts["grotto_only"]),
        ("Gift Only", counts["gift_only"]),
        ("Thin Wild", counts["thin_wild"]),
    ]
    return "".join(
        f'<article class="stat"><div class="stat-value">{value}</div><div class="stat-label">{esc(label)}</div></article>'
        for label, value in cards
    )


def render_overrepresented(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    wild_stats: dict[str, availability.SpeciesWildStats] = context["wild_stats"]  # type: ignore[assignment]
    cards = []
    for species in context["overrepresented"]:  # type: ignore[index]
        entry = entries[species]
        stats = wild_stats[species]
        methods = set(stats.methods)
        cards.append(
            f"""
            <article class="card species-card" data-search="{card_search(format_species(species, entries), trainer_report.type_names(entry.types), compact_maps(stats.maps), methods)}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
                <div class="score-badge">{stats.effective_weight:.0f}</div>
              </div>
              <div class="metric-grid">
                <div><b>{stats.slots}</b><span>slots</span></div>
                <div><b>{len(stats.maps)}</b><span>maps</span></div>
                <div><b>L{stats.min_level}-{stats.max_level}</b><span>levels</span></div>
              </div>
              <div class="tag-row">{method_badges(methods)}</div>
              <p class="muted">{esc(compact_maps(stats.maps, 5))}</p>
            </article>
            """
        )
    return "".join(cards)


def render_grotto_only(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    grottos_by_species: dict[str, list[availability.GrottoMon]] = context["grottos_by_species"]  # type: ignore[assignment]
    cards = []
    for species in context["grotto_only"]:  # type: ignore[index]
        entry = entries[species]
        labels = [grotto_label(grotto) for grotto in grottos_by_species[species]]
        cards.append(
            f"""
            <article class="card source-card" data-search="{card_search(format_species(species, entries), trainer_report.type_names(entry.types), labels)}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
              </div>
              <div class="source-row">{source_tags(labels)}</div>
              <div class="meta-line">Stage floor L{entry.min_stage_level} · {esc(availability.clean_family_name(entry.family))}</div>
            </article>
            """
        )
    return "".join(cards)


def render_gift_only(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    gifts_by_species: dict[str, list[availability.GiftMon]] = context["gifts_by_species"]  # type: ignore[assignment]
    cards = []
    for species in context["gift_only"]:  # type: ignore[index]
        entry = entries[species]
        labels = [gift_label(gift) for gift in gifts_by_species[species]]
        kinds = sorted({gift.source_kind for gift in gifts_by_species[species]})
        cards.append(
            f"""
            <article class="card source-card" data-search="{card_search(format_species(species, entries), trainer_report.type_names(entry.types), labels, kinds)}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
              </div>
              <div class="tag-row">{method_badges(kinds)}</div>
              <div class="source-row">{source_tags(labels)}</div>
              <div class="meta-line">Stage floor L{entry.min_stage_level} · {esc(availability.clean_family_name(entry.family))}</div>
            </article>
            """
        )
    return "".join(cards)


def render_suggestions(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    cards = []
    for suggestion in context["suggestions"]:  # type: ignore[index]
        species = suggestion.species
        entry = entries[species]
        replace = suggestion.replace_species
        replace_name = format_species(replace, entries) if replace else "-"
        cards.append(
            f"""
            <article class="card suggestion-card" data-search="{card_search(format_species(species, entries), suggestion.source_state, suggestion.map_name, suggestion.method, replace_name, suggestion.reason)}">
              <div class="suggestion-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
                <span class="state-badge">{esc(suggestion.source_state)}</span>
              </div>
              <div class="map-line">
                <span>{esc(availability.format_map_name(suggestion.map_name))}</span>
                <span>{esc(suggestion.method)}</span>
              </div>
              <div class="replace-row">
                <span class="replace-label">Replace</span>
                {species_img(replace, entries, output_path, "mon-icon") if replace else '<span class="mon-icon fallback">?</span>'}
                <span>{esc(replace_name)}</span>
              </div>
              <p class="reason">{esc(suggestion.reason)}</p>
            </article>
            """
        )
    return "".join(cards)


def render_thin_wild(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    wild_stats: dict[str, availability.SpeciesWildStats] = context["wild_stats"]  # type: ignore[assignment]
    cards = []
    for species in context["thin_wild"]:  # type: ignore[index]
        entry = entries[species]
        stats = wild_stats[species]
        cards.append(
            f"""
            <article class="card species-card" data-search="{card_search(format_species(species, entries), trainer_report.type_names(entry.types), compact_maps(stats.maps), set(stats.methods))}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
              </div>
              <div class="metric-grid">
                <div><b>{stats.slots}</b><span>slots</span></div>
                <div><b>{len(stats.maps)}</b><span>maps</span></div>
                <div><b>L{stats.min_level}-{stats.max_level}</b><span>levels</span></div>
              </div>
              <div class="tag-row">{method_badges(set(stats.methods))}</div>
              <p class="muted">{esc(compact_maps(stats.maps, 5))}</p>
            </article>
            """
        )
    return "".join(cards)


def render_missing(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    cards = []
    for species in context["missing"]:  # type: ignore[index]
        entry = entries[species]
        cards.append(
            f"""
            <article class="card missing-card" data-search="{card_search(format_species(species, entries), trainer_report.type_names(entry.types), availability.clean_family_name(entry.family))}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(format_species(species, entries))}</div>
                  <div class="type-list">{type_chips(entry)}</div>
                </div>
              </div>
              <div class="metric-grid two">
                <div><b>L{entry.min_stage_level}</b><span>stage floor</span></div>
                <div><b>{esc(availability.clean_family_name(entry.family))}</b><span>family</span></div>
              </div>
            </article>
            """
        )
    return "".join(cards)


def build_html(context: dict[str, object], output_path: Path) -> str:
    counts: dict[str, int] = context["counts"]  # type: ignore[assignment]
    tabs = [
        ("suggestions", "Suggested Adds", render_suggestions(context, output_path)),
        ("overrepresented", "Overrepresented", render_overrepresented(context, output_path)),
        ("grotto-only", "Grotto Only", render_grotto_only(context, output_path)),
        ("gift-only", "Gift Only", render_gift_only(context, output_path)),
        ("thin", "Thin Wild", render_thin_wild(context, output_path)),
        ("missing", "Missing", render_missing(context, output_path)),
    ]
    tab_buttons = "".join(
        f'<button class="tab-button{" active" if index == 0 else ""}" data-tab="{key}">{esc(label)}</button>'
        for index, (key, label, _) in enumerate(tabs)
    )
    tab_sections = "".join(
        f'<section class="tab-panel{" active" if index == 0 else ""}" id="{key}"><div class="card-grid">{body}</div></section>'
        for index, (key, _, body) in enumerate(tabs)
    )

    return f"""<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Species Availability Visual Report</title>
  <script>
    (() => {{
      try {{
        const stored = localStorage.getItem("species-availability-theme");
        const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches;
        if ((stored || (prefersDark ? "dark" : "light")) === "dark")
          document.documentElement.classList.add("dark");
      }} catch (error) {{}}
    }})();
  </script>
  <style>
    :root {{
      color-scheme: light;
      --bg: #f6f7f4;
      --panel: #ffffff;
      --panel-2: #eef3f5;
      --text: #1d2430;
      --muted: #667381;
      --border: #d7dee5;
      --chip: #edf1f4;
      --blue: #356fbb;
      --green: #2f7d5c;
      --amber: #a86c10;
      --red: #b84b45;
      --shadow: 0 10px 28px rgba(33, 43, 62, 0.09);
    }}
    html.dark {{
      color-scheme: dark;
      --bg: #111820;
      --panel: #17212d;
      --panel-2: #202c39;
      --text: #edf2f7;
      --muted: #a7b4c2;
      --border: #344253;
      --chip: #243244;
      --blue: #80aef2;
      --green: #58b98f;
      --amber: #e1ae4b;
      --red: #e0736d;
      --shadow: 0 12px 32px rgba(0, 0, 0, 0.32);
    }}
    * {{ box-sizing: border-box; }}
    body {{
      margin: 0;
      background: var(--bg);
      color: var(--text);
      font-family: "Segoe UI", system-ui, sans-serif;
    }}
    main {{
      width: min(1420px, calc(100% - 28px));
      margin: 22px auto 42px;
    }}
    header {{
      display: grid;
      grid-template-columns: minmax(260px, 1fr) auto;
      gap: 18px;
      align-items: end;
      margin-bottom: 16px;
    }}
    h1 {{
      margin: 0 0 6px;
      font-size: 2rem;
      letter-spacing: 0;
    }}
    .subtitle, .muted, .reason, .meta-line {{
      color: var(--muted);
    }}
    .header-actions {{
      display: flex;
      align-items: center;
      justify-content: flex-end;
      gap: 14px;
      flex-wrap: wrap;
    }}
    .summary {{
      display: grid;
      grid-template-columns: repeat(8, minmax(118px, 1fr));
      gap: 10px;
      margin: 14px 0 16px;
    }}
    .stat, .card {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 8px;
      box-shadow: var(--shadow);
    }}
    .stat {{
      padding: 13px 14px;
    }}
    .stat-value {{
      font-weight: 800;
      font-size: 1.45rem;
    }}
    .stat-label {{
      color: var(--muted);
      font-size: 0.76rem;
      text-transform: uppercase;
      letter-spacing: 0.04em;
    }}
    .toolbar {{
      display: grid;
      grid-template-columns: 1fr minmax(240px, 360px);
      gap: 12px;
      align-items: center;
      margin: 12px 0 16px;
    }}
    .tabs {{
      display: flex;
      flex-wrap: wrap;
      gap: 8px;
    }}
    button, input {{
      font: inherit;
    }}
    .tab-button {{
      border: 1px solid var(--border);
      background: var(--panel);
      color: var(--text);
      border-radius: 8px;
      padding: 10px 12px;
      cursor: pointer;
    }}
    .tab-button.active {{
      background: var(--text);
      color: var(--panel);
      border-color: var(--text);
    }}
    .search {{
      width: 100%;
      min-height: 42px;
      border: 1px solid var(--border);
      border-radius: 8px;
      padding: 10px 12px;
      background: var(--panel);
      color: var(--text);
    }}
    .theme-toggle {{
      display: inline-flex;
      align-items: center;
      gap: 8px;
      color: var(--text);
      font-weight: 700;
      cursor: pointer;
      user-select: none;
    }}
    .theme-toggle input {{
      position: absolute;
      opacity: 0;
      pointer-events: none;
    }}
    .toggle-track {{
      width: 48px;
      height: 26px;
      border: 1px solid var(--border);
      border-radius: 999px;
      background: var(--panel);
      padding: 3px;
    }}
    .toggle-thumb {{
      display: block;
      width: 18px;
      height: 18px;
      border-radius: 50%;
      background: var(--muted);
      transition: transform 160ms ease, background 160ms ease;
    }}
    .theme-toggle input:checked + .toggle-track {{
      background: var(--blue);
      border-color: var(--blue);
    }}
    .theme-toggle input:checked + .toggle-track .toggle-thumb {{
      transform: translateX(22px);
      background: #fff;
    }}
    .theme-toggle input:focus-visible + .toggle-track {{
      outline: 2px solid var(--blue);
      outline-offset: 2px;
    }}
    .tab-panel {{ display: none; }}
    .tab-panel.active {{ display: block; }}
    .card-grid {{
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
      gap: 12px;
    }}
    .card {{
      min-height: 176px;
      padding: 13px;
      display: flex;
      flex-direction: column;
      gap: 11px;
    }}
    .species-head, .suggestion-head, .replace-row, .map-line {{
      display: flex;
      align-items: center;
      gap: 10px;
    }}
    .large-mon-icon {{
      width: 48px;
      height: 48px;
      object-fit: contain;
      image-rendering: pixelated;
      flex: 0 0 auto;
    }}
    .mon-icon {{
      width: 32px;
      height: 32px;
      object-fit: contain;
      image-rendering: pixelated;
      flex: 0 0 auto;
    }}
    .fallback {{
      display: grid;
      place-items: center;
      background: var(--panel-2);
      color: var(--muted);
      border: 1px solid var(--border);
      border-radius: 8px;
      font-weight: 800;
    }}
    .species-name {{
      font-weight: 800;
      line-height: 1.15;
    }}
    .type-list, .tag-row, .source-row {{
      display: flex;
      flex-wrap: wrap;
      gap: 5px;
    }}
    .type-list {{ margin-top: 5px; }}
    .type-chip {{
      border-radius: 8px;
      border: 1px solid color-mix(in srgb, var(--type-color), #000 12%);
      background: color-mix(in srgb, var(--type-color), #fff 82%);
      color: color-mix(in srgb, var(--type-color), #000 45%);
      padding: 2px 7px;
      font-size: 0.78rem;
      font-weight: 800;
    }}
    html.dark .type-chip {{
      border-color: color-mix(in srgb, var(--type-color), #fff 18%);
      background: color-mix(in srgb, var(--type-color), #000 70%);
      color: color-mix(in srgb, var(--type-color), #fff 70%);
    }}
    .tag, .source-tag, .state-badge, .score-badge {{
      display: inline-flex;
      align-items: center;
      min-height: 26px;
      border: 1px solid var(--border);
      border-radius: 8px;
      background: var(--chip);
      color: var(--text);
      padding: 3px 8px;
      font-size: 0.82rem;
      font-weight: 800;
    }}
    .state-badge, .score-badge {{
      margin-left: auto;
      color: var(--amber);
    }}
    .source-tag {{
      color: var(--muted);
      font-weight: 700;
    }}
    .metric-grid {{
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 8px;
    }}
    .metric-grid.two {{
      grid-template-columns: 0.7fr 1.3fr;
    }}
    .metric-grid div {{
      background: var(--panel-2);
      border: 1px solid var(--border);
      border-radius: 8px;
      padding: 8px;
      min-width: 0;
    }}
    .metric-grid b, .metric-grid span {{
      display: block;
      overflow-wrap: anywhere;
    }}
    .metric-grid span {{
      color: var(--muted);
      font-size: 0.78rem;
    }}
    .map-line {{
      justify-content: space-between;
      background: var(--panel-2);
      border: 1px solid var(--border);
      border-radius: 8px;
      min-height: 38px;
      padding: 7px 9px;
      font-weight: 800;
    }}
    .replace-row {{
      min-height: 42px;
      color: var(--muted);
    }}
    .replace-row > span:last-child {{
      color: var(--text);
      font-weight: 700;
      overflow-wrap: anywhere;
    }}
    .replace-label {{
      color: var(--red);
      font-weight: 800;
      font-size: 0.78rem;
      text-transform: uppercase;
      letter-spacing: 0.04em;
    }}
    .reason {{
      margin: 0;
      font-size: 0.9rem;
      line-height: 1.35;
    }}
    .hidden {{ display: none !important; }}
    .empty-state {{
      display: none;
      padding: 24px;
      color: var(--muted);
      text-align: center;
      border: 1px dashed var(--border);
      border-radius: 8px;
      background: var(--panel);
    }}
    .empty-state.active {{ display: block; }}
    @media (max-width: 1080px) {{
      .summary {{ grid-template-columns: repeat(4, 1fr); }}
    }}
    @media (max-width: 920px) {{
      header, .toolbar {{ grid-template-columns: 1fr; }}
      .header-actions {{ justify-content: flex-start; }}
    }}
    @media (max-width: 560px) {{
      main {{ width: min(100% - 18px, 1420px); }}
      .summary {{ grid-template-columns: repeat(2, 1fr); }}
      .card-grid {{ grid-template-columns: 1fr; }}
      .metric-grid, .metric-grid.two {{ grid-template-columns: 1fr; }}
    }}
  </style>
</head>
<body>
  <main>
    <header>
      <div>
        <h1>Species Availability</h1>
        <div class="subtitle">Wild encounters, gifts, and hidden grottoes in the scoped Johto playthrough data</div>
      </div>
      <div class="header-actions">
        <label class="theme-toggle" for="themeToggle">
          <input id="themeToggle" type="checkbox">
          <span class="toggle-track" aria-hidden="true"><span class="toggle-thumb"></span></span>
          <span>Dark</span>
        </label>
        <div class="subtitle">{counts["wild_maps"]} encounter tables · {counts["excluded_wild_slots"]} out-of-scope slots ignored</div>
      </div>
    </header>
    <section class="summary">{render_summary(counts)}</section>
    <section class="toolbar">
      <nav class="tabs" aria-label="Report sections">{tab_buttons}</nav>
      <input id="search" class="search" type="search" placeholder="Search species, map, method, source">
    </section>
    {tab_sections}
    <div id="emptyState" class="empty-state">No cards match the current search.</div>
  </main>
  <script>
    const tabButtons = [...document.querySelectorAll(".tab-button")];
    const panels = [...document.querySelectorAll(".tab-panel")];
    const search = document.querySelector("#search");
    const emptyState = document.querySelector("#emptyState");
    const themeToggle = document.querySelector("#themeToggle");

    function activePanel() {{
      return document.querySelector(".tab-panel.active");
    }}

    function applySearch() {{
      const query = search.value.trim().toLowerCase();
      const panel = activePanel();
      let visible = 0;
      panel.querySelectorAll(".card").forEach(card => {{
        const haystack = card.dataset.search.toLowerCase();
        const match = !query || haystack.includes(query);
        card.classList.toggle("hidden", !match);
        if (match) visible++;
      }});
      emptyState.classList.toggle("active", visible === 0);
    }}

    tabButtons.forEach(button => {{
      button.addEventListener("click", () => {{
        tabButtons.forEach(item => item.classList.toggle("active", item === button));
        panels.forEach(panel => panel.classList.toggle("active", panel.id === button.dataset.tab));
        applySearch();
      }});
    }});

    function setTheme(isDark) {{
      document.documentElement.classList.toggle("dark", isDark);
      themeToggle.checked = isDark;
      try {{
        localStorage.setItem("species-availability-theme", isDark ? "dark" : "light");
      }} catch (error) {{}}
    }}

    themeToggle.checked = document.documentElement.classList.contains("dark");
    themeToggle.addEventListener("change", () => setTheme(themeToggle.checked));
    search.addEventListener("input", applySearch);
    applySearch();
  </script>
</body>
</html>
"""


def main() -> None:
    parser = argparse.ArgumentParser(description="Render the species availability analysis as HTML.")
    parser.add_argument("-o", "--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--overrepresented-limit", type=int, default=60)
    parser.add_argument("--missing-limit", type=int, default=140)
    parser.add_argument("--suggestion-limit", type=int, default=90)
    args = parser.parse_args()

    output_path = args.output
    if not output_path.is_absolute():
        output_path = REPO_ROOT / output_path
    context = availability.build_context(args)
    output_path.write_text(build_html(context, output_path), encoding="utf-8")
    print(f"Wrote {output_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
