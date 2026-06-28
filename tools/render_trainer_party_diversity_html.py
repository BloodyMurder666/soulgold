#!/usr/bin/env python3

from __future__ import annotations

import argparse
import html
import os
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT))

from tools import analyze_trainer_party_diversity as report  # noqa: E402


DEFAULT_OUTPUT = REPO_ROOT / "tools/trainer_party_diversity_report.html"
POKEMON_ICON_DIR = REPO_ROOT / "tools/species_distribution_report_icons"
TRAINER_DOC_SPRITE_DIR = REPO_ROOT / "docs/sprites/trainers"
TRAINER_FRONT_PIC_DIR = REPO_ROOT / "graphics/trainers/front_pics"

TYPE_COLORS = {
    "Bug": "#8ea820",
    "Dark": "#604c40",
    "Dragon": "#6d62d8",
    "Electric": "#d59b13",
    "Fairy": "#d871a3",
    "Fighting": "#b44a36",
    "Fire": "#d9572b",
    "Flying": "#6f8fdc",
    "Ghost": "#5c5a9b",
    "Grass": "#4b9c45",
    "Ground": "#b78a3a",
    "Ice": "#4aa9be",
    "Normal": "#85827b",
    "Poison": "#914b9d",
    "Psychic": "#d94f78",
    "Rock": "#9f8742",
    "Steel": "#758697",
    "Water": "#3f78c7",
}


def slugify(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "_", value.lower()).strip("_")


def esc(value: object) -> str:
    return html.escape(str(value), quote=True)


def rel_path(path: Path, output_path: Path) -> str:
    return os.path.relpath(path, output_path.parent).replace(os.sep, "/")


def species_icon_path(constant: str, output_path: Path) -> str | None:
    path = POKEMON_ICON_DIR / f"{constant.lower()}.png"
    if path.exists():
        return rel_path(path, output_path)
    return None


def trainer_sprite_path(pic: str, trainer_class: str, output_path: Path) -> str | None:
    candidates = []
    for value in (pic, trainer_class):
        if value:
            candidates.append(slugify(value))
    fallback_by_class = {
        "cooltrainer": "cooltrainer_m",
        "pokefan": "pokefan_m",
        "psychic": "psychic_m",
        "swimmer": "swimmer_m",
        "expert": "expert_m",
        "school_kid": "school_kid_m",
        "pkmn_trainer": "cooltrainer_m",
    }
    for key, fallback in fallback_by_class.items():
        if key in candidates:
            candidates.append(fallback)
    for stem in candidates:
        for directory in (TRAINER_DOC_SPRITE_DIR, TRAINER_FRONT_PIC_DIR):
            path = directory / f"{stem}.png"
            if path.exists():
                return rel_path(path, output_path)
    return None


def img_or_initial(path: str | None, alt: str, class_name: str, initial: str) -> str:
    if path:
        return f'<img class="{class_name}" src="{esc(path)}" alt="{esc(alt)}" loading="lazy">'
    return f'<div class="{class_name} fallback" aria-label="{esc(alt)}">{esc(initial[:2].upper())}</div>'


def species_img(constant: str, entries: dict[str, report.SpeciesEntry], output_path: Path, class_name: str = "mon-icon") -> str:
    name = report.display_species(constant, entries)
    return img_or_initial(species_icon_path(constant, output_path), name, class_name, name)


def trainer_img(trainer: report.TrainerBlock | None, output_path: Path) -> str:
    if trainer is None:
        return img_or_initial(None, "Trainer", "trainer-sprite", "?")
    name = trainer.name or trainer.trainer_id
    path = trainer_sprite_path(trainer.pic, trainer.trainer_class, output_path)
    return img_or_initial(path, name, "trainer-sprite", name)


def type_chips(type_text: str) -> str:
    chips = []
    for type_name in type_text.split("/"):
        color = TYPE_COLORS.get(type_name, "#6b7280")
        chips.append(
            f'<span class="type-chip" style="--type-color: {esc(color)}">{esc(type_name)}</span>'
        )
    return "".join(chips)


def line_badges(lines: list[int]) -> str:
    return "".join(f'<span class="line-badge">L{line}</span>' for line in lines)


def build_context(args: argparse.Namespace) -> dict[str, object]:
    id_to_constant, constant_to_id = report.parse_species_constants()
    entries = report.parse_enabled_species(id_to_constant)
    species_to_family = report.parse_species_to_family()
    for constant, entry in entries.items():
        entry.family = species_to_family.get(constant, constant)
    report.assign_evolution_levels(entries)

    aliases = report.build_alias_map(entries, constant_to_id)
    trainers, unresolved = report.parse_trainers_party(aliases)
    trainer_refs = report.parse_trainer_map_references()
    wild = report.parse_wild_encounters()
    _, nonrocket_uses = report.build_usage_rows(trainers, trainer_refs)
    ordinary_trainers = report.ordinary_nonrocket_trainers(trainers)

    target_entries = [entry for entry in entries.values() if entry.target_eligible]
    enabled_targets = {entry.constant for entry in target_entries}
    wild_enabled = {constant for constant in wild if constant in enabled_targets}
    nonrocket_present = {mon.species for mon in nonrocket_uses if mon.species in enabled_targets}
    usage_count = Counter(mon.species for mon in nonrocket_uses if mon.species in enabled_targets)

    uses_by_species: dict[str, list[report.TrainerMon]] = defaultdict(list)
    for mon in nonrocket_uses:
        if mon.species in enabled_targets:
            uses_by_species[mon.species].append(mon)

    top_species = []
    for species, count in sorted(usage_count.items(), key=lambda item: (-item[1], entries[item[0]].species_id))[: args.top_limit]:
        uses = uses_by_species[species]
        levels = [mon.level for mon in uses]
        class_counts = Counter(mon.trainer_class or "-" for mon in uses)
        wild_info = wild.get(species, report.WildInfo())
        top_species.append(
            {
                "species": species,
                "count": count,
                "trainer_count": len({mon.trainer_id for mon in uses}),
                "level_range": f"L{min(levels)}-{max(levels)}",
                "classes": [name for name, _ in class_counts.most_common(3)],
                "wild_range": f"L{wild_info.min_level}-{wild_info.max_level}" if wild_info.has_data else "-",
            }
        )

    per_trainer_species = defaultdict(Counter)
    for mon in nonrocket_uses:
        if mon.species in enabled_targets:
            per_trainer_species[mon.trainer_id][mon.species] += 1
    duplicates = []
    for trainer in trainers:
        if trainer.is_rocket or trainer.protected or trainer.trainer_id == "TRAINER_NONE":
            continue
        for species, count in per_trainer_species[trainer.trainer_id].items():
            if count > 1:
                species_lines = [mon.line for mon in trainer.mons if mon.species == species]
                duplicates.append((count, trainer, species, species_lines))
    duplicates.sort(key=lambda item: (-item[0], item[1].start_line))

    missing_trainer_wild = sorted(
        (constant for constant in wild_enabled if constant not in nonrocket_present),
        key=lambda constant: (wild[constant].min_level, entries[constant].species_id),
    )
    missing_everywhere = sorted(
        (entry.constant for entry in target_entries if entry.constant not in wild_enabled and entry.constant not in nonrocket_present),
        key=lambda constant: entries[constant].species_id,
    )

    suggestions = report.replacement_candidates(
        nonrocket_uses,
        entries,
        wild,
        ordinary_trainers,
        args.suggestion_limit,
        args.overuse_threshold,
    )

    referenced_trainers = {trainer_id for trainer_id, maps in trainer_refs.items() if maps}
    included_trainers = [trainer for trainer in trainers if trainer.trainer_id in referenced_trainers]
    protected_or_rocket_trainers = sum(1 for trainer in included_trainers if trainer.is_rocket or trainer.protected)
    rocket_mons = sum(len(trainer.mons) for trainer in included_trainers if trainer.is_rocket)
    referenced_nonrocket_uses = [mon for mon in nonrocket_uses if mon.trainer_id in referenced_trainers]

    return {
        "entries": entries,
        "trainers": trainers,
        "trainer_by_id": {trainer.trainer_id: trainer for trainer in trainers},
        "trainer_refs": trainer_refs,
        "wild": wild,
        "top_species": top_species,
        "duplicates": duplicates[: args.top_limit],
        "missing_trainer_wild": missing_trainer_wild[: args.missing_limit],
        "missing_everywhere": missing_everywhere[: args.missing_limit],
        "suggestions": suggestions,
        "counts": {
            "trainers": len(trainers),
            "included_trainers": len(referenced_trainers),
            "protected_or_rocket": protected_or_rocket_trainers,
            "rocket_mons": rocket_mons,
            "nonrocket_mons": len(nonrocket_uses),
            "referenced_nonrocket_mons": len(referenced_nonrocket_uses),
            "eligible": len(target_entries),
            "wild_enabled": len(wild_enabled),
            "trainer_present": len(nonrocket_present),
            "missing_trainers": len(wild_enabled - nonrocket_present),
            "missing_everywhere": len(missing_everywhere),
            "unresolved": len(unresolved),
        },
    }


def card_search(*values: object) -> str:
    return esc(" ".join(str(value) for value in values if value))


def render_summary(counts: dict[str, int]) -> str:
    cards = [
        ("Non-Rocket Mons", counts["nonrocket_mons"]),
        ("Trainer Coverage", counts["trainer_present"]),
        ("Wild Missing Trainers", counts["missing_trainers"]),
        ("Missing Everywhere", counts["missing_everywhere"]),
        ("Rocket Mons Excluded", counts["rocket_mons"]),
        ("Eligible Species", counts["eligible"]),
    ]
    return "".join(
        f'<article class="stat-card"><div class="stat-value">{value}</div><div class="stat-label">{esc(label)}</div></article>'
        for label, value in cards
    )


def render_suggestions(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    trainer_by_id: dict[str, report.TrainerBlock] = context["trainer_by_id"]  # type: ignore[assignment]
    cards = []
    for suggestion in context["suggestions"]:  # type: ignore[union-attr]
        trainer = trainer_by_id.get(str(suggestion["trainer_id"]))
        from_species = str(suggestion["from"])
        to_species = str(suggestion["to"])
        from_name = report.display_species(from_species, entries)
        to_name = report.display_species(to_species, entries)
        maps = report.compact_list(suggestion["maps"], 3)  # type: ignore[arg-type]
        cards.append(
            f"""
            <article class="card suggestion-card" data-search="{card_search(suggestion['trainer'], suggestion['class'], from_name, to_name, maps, suggestion['reason'])}">
              <div class="trainer-block">
                {trainer_img(trainer, output_path)}
                <div>
                  <div class="trainer-name">{esc(suggestion['trainer'])}</div>
                  <div class="muted">{esc(suggestion['class'])} &middot; L{esc(suggestion['level'])}</div>
                </div>
              </div>
              <div class="swap-row">
                <div class="mon-pill old">{species_img(from_species, entries, output_path)}<span>{esc(from_name)}</span></div>
                <div class="swap-arrow">&rarr;</div>
                <div class="mon-pill new">{species_img(to_species, entries, output_path)}<span>{esc(to_name)}</span></div>
              </div>
              <div class="meta-row"><span class="line-badge">L{esc(suggestion['line'])}</span><span>{esc(maps)}</span></div>
              <p class="reason">{esc(suggestion['reason'])}</p>
            </article>
            """
        )
    return "".join(cards)


def render_top_species(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    cards = []
    for row in context["top_species"]:  # type: ignore[union-attr]
        species = str(row["species"])
        entry = entries[species]
        name = report.display_species(species, entries)
        classes = ", ".join(row["classes"])
        cards.append(
            f"""
            <article class="card species-card" data-search="{card_search(name, classes, row['wild_range'], report.type_names(entry.types))}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(name)}</div>
                  <div class="type-list">{type_chips(report.type_names(entry.types))}</div>
                </div>
                <div class="count-badge">{esc(row['count'])}</div>
              </div>
              <div class="detail-grid">
                <div><b>{esc(row['trainer_count'])}</b><span>trainers</span></div>
                <div><b>{esc(row['level_range'])}</b><span>levels</span></div>
                <div><b>{esc(row['wild_range'])}</b><span>wild</span></div>
              </div>
              <p class="muted">{esc(classes)}</p>
            </article>
            """
        )
    return "".join(cards)


def render_duplicates(context: dict[str, object], output_path: Path) -> str:
    entries: dict[str, report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    trainer_refs: dict[str, set[str]] = context["trainer_refs"]  # type: ignore[assignment]
    cards = []
    for count, trainer, species, species_lines in context["duplicates"]:  # type: ignore[union-attr]
        name = report.display_species(species, entries)
        maps = report.compact_list(trainer_refs.get(trainer.trainer_id, set()), 3)
        cards.append(
            f"""
            <article class="card duplicate-card" data-search="{card_search(trainer.name, trainer.trainer_class, name, maps)}">
              <div class="trainer-block">
                {trainer_img(trainer, output_path)}
                <div>
                  <div class="trainer-name">{esc(trainer.name or trainer.trainer_id)}</div>
                  <div class="muted">{esc(trainer.trainer_class or '-')}</div>
                </div>
              </div>
              <div class="duplicate-mon">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div><div class="species-name">{esc(name)}</div><div class="muted">{count} copies</div></div>
              </div>
              <div class="line-wrap">{line_badges(species_lines)}</div>
              <p class="muted">{esc(maps)}</p>
            </article>
            """
        )
    return "".join(cards)


def render_missing_species(context: dict[str, object], output_path: Path, key: str, with_wild: bool) -> str:
    entries: dict[str, report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    wild: dict[str, report.WildInfo] = context["wild"]  # type: ignore[assignment]
    cards = []
    for species in context[key]:  # type: ignore[index]
        entry = entries[species]
        name = report.display_species(species, entries)
        wild_info = wild.get(species, report.WildInfo())
        wild_bits = ""
        if with_wild and wild_info.has_data:
            wild_bits = f"""
              <div class="meta-row"><span>L{wild_info.min_level}-{wild_info.max_level}</span><span>{esc(report.compact_list(wild_info.maps, 4))}</span></div>
            """
        cards.append(
            f"""
            <article class="card missing-card" data-search="{card_search(name, report.type_names(entry.types), report.compact_list(wild_info.maps, 4) if wild_info.has_data else '')}">
              <div class="species-head">
                {species_img(species, entries, output_path, "large-mon-icon")}
                <div>
                  <div class="species-name">{esc(name)}</div>
                  <div class="type-list">{type_chips(report.type_names(entry.types))}</div>
                </div>
              </div>
              {wild_bits}
              <div class="meta-row"><span>Stage floor L{entry.min_stage_level}</span><span>{esc(entry.family.removeprefix('P_FAMILY_').replace('_', ' ').title())}</span></div>
            </article>
            """
        )
    return "".join(cards)


def build_html(context: dict[str, object], output_path: Path) -> str:
    counts: dict[str, int] = context["counts"]  # type: ignore[assignment]
    tabs = [
        ("suggestions", "Suggested Swaps", render_suggestions(context, output_path)),
        ("reused", "Reused Species", render_top_species(context, output_path)),
        ("duplicates", "Duplicate Hotspots", render_duplicates(context, output_path)),
        ("missing-trainers", "Missing From Trainers", render_missing_species(context, output_path, "missing_trainer_wild", True)),
        ("missing-everywhere", "Missing Everywhere", render_missing_species(context, output_path, "missing_everywhere", False)),
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
  <title>Trainer Party Diversity Visual Report</title>
  <script>
    (() => {{
      try {{
        const stored = localStorage.getItem("trainer-party-diversity-theme");
        const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches;
        if ((stored || (prefersDark ? "dark" : "light")) === "dark")
          document.documentElement.classList.add("dark");
      }} catch (error) {{}}
    }})();
  </script>
  <style>
    :root {{
      color-scheme: light;
      --bg: #f5f7f3;
      --panel: #ffffff;
      --panel-2: #eef3f7;
      --text: #1d2430;
      --muted: #657080;
      --border: #d8dee7;
      --badge-bg: #edf1f5;
      --count-bg: #fff4dc;
      --count-border: #eed092;
      --count-text: #7a4b00;
      --green: #2f7d5c;
      --blue: #356fbb;
      --amber: #b67814;
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
      --badge-bg: #223041;
      --count-bg: #382d17;
      --count-border: #735d26;
      --count-text: #ffd27a;
      --green: #58b98f;
      --blue: #80aef2;
      --amber: #e1ae4b;
      --red: #e0736d;
      --shadow: 0 12px 32px rgba(0, 0, 0, 0.32);
    }}
    * {{ box-sizing: border-box; }}
    body {{
      margin: 0;
      font-family: "Segoe UI", system-ui, sans-serif;
      background: var(--bg);
      color: var(--text);
    }}
    main {{
      width: min(1380px, calc(100% - 28px));
      margin: 22px auto 42px;
    }}
    header {{
      display: grid;
      grid-template-columns: minmax(240px, 1fr) auto;
      gap: 18px;
      align-items: end;
      margin-bottom: 16px;
    }}
    .header-actions {{
      display: flex;
      align-items: center;
      justify-content: flex-end;
      gap: 14px;
      flex-wrap: wrap;
    }}
    h1 {{
      margin: 0 0 6px;
      font-size: 2rem;
      letter-spacing: 0;
    }}
    .subtitle, .muted, .reason {{
      color: var(--muted);
    }}
    .summary {{
      display: grid;
      grid-template-columns: repeat(6, minmax(130px, 1fr));
      gap: 10px;
      margin: 14px 0 16px;
    }}
    .stat-card, .card {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 8px;
      box-shadow: var(--shadow);
    }}
    .stat-card {{
      padding: 13px 14px;
    }}
    .stat-value {{
      font-weight: 800;
      font-size: 1.55rem;
    }}
    .stat-label {{
      font-size: 0.78rem;
      color: var(--muted);
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
      gap: 8px;
      flex-wrap: wrap;
    }}
    button, input {{
      font: inherit;
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
      transition: background 160ms ease, border-color 160ms ease;
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
      background: white;
    }}
    .theme-toggle input:focus-visible + .toggle-track {{
      outline: 2px solid var(--blue);
      outline-offset: 2px;
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
      color: white;
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
    .tab-panel {{ display: none; }}
    .tab-panel.active {{ display: block; }}
    .card-grid {{
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
      gap: 12px;
    }}
    .card {{
      padding: 13px;
      min-height: 178px;
      display: flex;
      flex-direction: column;
      gap: 11px;
    }}
    .trainer-block, .species-head, .duplicate-mon, .mon-pill, .meta-row {{
      display: flex;
      align-items: center;
      gap: 10px;
    }}
    .trainer-sprite {{
      width: 56px;
      height: 56px;
      object-fit: contain;
      image-rendering: pixelated;
      background: var(--panel-2);
      border: 1px solid var(--border);
      border-radius: 8px;
      flex: 0 0 auto;
    }}
    .mon-icon {{
      width: 32px;
      height: 32px;
      object-fit: contain;
      image-rendering: pixelated;
      flex: 0 0 auto;
    }}
    .large-mon-icon {{
      width: 46px;
      height: 46px;
      object-fit: contain;
      image-rendering: pixelated;
      flex: 0 0 auto;
    }}
    .fallback {{
      display: grid;
      place-items: center;
      font-weight: 800;
      color: var(--muted);
    }}
    .trainer-name, .species-name {{
      font-weight: 800;
      line-height: 1.15;
    }}
    .swap-row {{
      display: grid;
      grid-template-columns: minmax(0, 1fr) 28px minmax(0, 1fr);
      align-items: center;
      gap: 8px;
    }}
    .mon-pill {{
      min-height: 46px;
      border: 1px solid var(--border);
      border-radius: 8px;
      padding: 7px 8px;
      background: var(--panel-2);
      overflow: hidden;
    }}
    .mon-pill span {{
      overflow: hidden;
      text-overflow: ellipsis;
      white-space: nowrap;
      font-weight: 700;
    }}
    .mon-pill.old {{ border-left: 4px solid var(--red); }}
    .mon-pill.new {{ border-left: 4px solid var(--green); }}
    .swap-arrow {{
      text-align: center;
      font-weight: 900;
      color: var(--blue);
    }}
    .line-badge, .count-badge {{
      display: inline-flex;
      align-items: center;
      justify-content: center;
      min-height: 26px;
      border-radius: 8px;
      background: var(--badge-bg);
      border: 1px solid var(--border);
      padding: 3px 8px;
      font-weight: 800;
      color: var(--text);
    }}
    .count-badge {{
      margin-left: auto;
      background: var(--count-bg);
      border-color: var(--count-border);
      color: var(--count-text);
      min-width: 38px;
    }}
    .meta-row {{
      justify-content: space-between;
      color: var(--muted);
      font-size: 0.9rem;
      gap: 8px;
    }}
    .reason {{
      margin: 0;
      font-size: 0.9rem;
      line-height: 1.35;
    }}
    .detail-grid {{
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 8px;
    }}
    .detail-grid div {{
      background: var(--panel-2);
      border: 1px solid var(--border);
      border-radius: 8px;
      padding: 8px;
    }}
    .detail-grid b, .detail-grid span {{
      display: block;
    }}
    .detail-grid span {{
      color: var(--muted);
      font-size: 0.78rem;
    }}
    .type-list {{
      display: flex;
      flex-wrap: wrap;
      gap: 5px;
      margin-top: 5px;
    }}
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
    .line-wrap {{
      display: flex;
      flex-wrap: wrap;
      gap: 6px;
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
    @media (max-width: 920px) {{
      header, .toolbar {{ grid-template-columns: 1fr; }}
      .header-actions {{ justify-content: flex-start; }}
      .summary {{ grid-template-columns: repeat(2, 1fr); }}
    }}
    @media (max-width: 520px) {{
      main {{ width: min(100% - 18px, 1380px); }}
      .summary {{ grid-template-columns: 1fr; }}
      .card-grid {{ grid-template-columns: 1fr; }}
      .swap-row {{ grid-template-columns: 1fr; }}
      .swap-arrow {{ display: none; }}
    }}
  </style>
</head>
<body>
  <main>
    <header>
      <div>
        <h1>Trainer Party Diversity</h1>
        <div class="subtitle">Visual cleanup report for non-Rocket trainer parties, excluding Emerald, Kanto, and ship maps</div>
      </div>
      <div class="header-actions">
        <label class="theme-toggle" for="themeToggle">
          <input id="themeToggle" type="checkbox">
          <span class="toggle-track" aria-hidden="true"><span class="toggle-thumb"></span></span>
          <span>Dark</span>
        </label>
        <div class="subtitle">{counts["included_trainers"]} included trainers &middot; {counts["protected_or_rocket"]} protected or Rocket blocks</div>
      </div>
    </header>
    <section class="summary">{render_summary(counts)}</section>
    <section class="toolbar">
      <nav class="tabs" aria-label="Report sections">{tab_buttons}</nav>
      <input id="search" class="search" type="search" placeholder="Search species, trainer, map, class">
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
        localStorage.setItem("trainer-party-diversity-theme", isDark ? "dark" : "light");
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
    parser = argparse.ArgumentParser(description="Render the trainer party diversity analysis as a visual HTML report.")
    parser.add_argument("-o", "--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--top-limit", type=int, default=35)
    parser.add_argument("--missing-limit", type=int, default=80)
    parser.add_argument("--suggestion-limit", type=int, default=45)
    parser.add_argument("--overuse-threshold", type=int, default=6)
    args = parser.parse_args()

    output_path = args.output
    if not output_path.is_absolute():
        output_path = REPO_ROOT / output_path

    context = build_context(args)
    output_path.write_text(build_html(context, output_path), encoding="utf-8")
    print(f"Wrote {output_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
