"""Static site output preparation and JSON payload assembly."""

from __future__ import annotations

import json
import re
import shutil

from .models import (
    AbilityUsage,
    DocsPayload,
    GuideRow,
    ImportantItemRow,
    MegaEvolutionRow,
    NamedRecord,
    OutputPaths,
    SpeciesRow,
    TMRow,
    TrainerRow,
    WildEncounterRow,
)
from .paths import OUT_DIR, SRC_DIR

SECTION_ROUTES = ("pokedex", "moves", "encounters", "machines", "items", "trainers", "abilities", "guides")


def route_slug(constant: str, prefix: str = "") -> str:
    """Return a stable, URL-safe slug derived from a unique game constant."""
    value = constant.removeprefix(prefix).lower()
    return re.sub(r"[^a-z0-9]+", "-", value).strip("-")


def prepare_output_tree() -> OutputPaths:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    # These directories are generated entry points. Remove them first so
    # deleted or renamed records cannot leave stale shareable URLs behind.
    for route in SECTION_ROUTES:
        route_dir = OUT_DIR / route
        if route_dir.exists():
            shutil.rmtree(route_dir)
    for item in SRC_DIR.rglob("*"):
        relative = item.relative_to(SRC_DIR)
        # Guide Markdown is authoring source embedded into the JSON payload.
        # Only its attached assets need to be copied to the published site.
        if relative.parts[0] == "guides" and (item.suffix == ".md" or item.name == ".gitkeep"):
            continue
        dest = OUT_DIR / relative
        if item.is_dir():
            dest.mkdir(parents=True, exist_ok=True)
        else:
            shutil.copy2(item, dest)
    write_section_routes()
    (OUT_DIR / ".nojekyll").write_text("", encoding="utf-8")
    (OUT_DIR / "data").mkdir(parents=True, exist_ok=True)
    return OutputPaths(
        sprite_dir=OUT_DIR / "sprites" / "pokemon",
        trainer_sprite_dir=OUT_DIR / "sprites" / "trainers",
        item_icon_dir=OUT_DIR / "sprites" / "items",
    )


def write_section_routes() -> None:
    """Create static entry points so section URLs work without server rewrites."""
    index_html = (OUT_DIR / "index.html").read_text(encoding="utf-8")
    route_html = index_html.replace('<base href="./">', '<base href="../">', 1)
    if route_html == index_html:
        raise ValueError('docs/src/index.html must contain <base href="./">')
    for route in SECTION_ROUTES:
        route_dir = OUT_DIR / route
        route_dir.mkdir(parents=True, exist_ok=True)
        (route_dir / "index.html").write_text(route_html, encoding="utf-8")


def write_detail_routes(payload: DocsPayload) -> None:
    """Create static entry points for every shareable record URL."""
    index_html = (OUT_DIR / "index.html").read_text(encoding="utf-8")
    detail_html = index_html.replace('<base href="./">', '<base href="../../">', 1)
    if detail_html == index_html:
        raise ValueError('docs/src/index.html must contain <base href="./">')

    records = {
        "pokedex": payload["species"],
        "moves": payload["moves"].values(),
        "machines": payload["tms"],
        "items": payload["items"],
        "abilities": payload["abilities"].values(),
        "guides": payload["guides"],
    }
    for route, entries in records.items():
        seen_slugs: dict[str, str] = {}
        for entry in entries:
            if entry.get("constant") in {"MOVE_NONE", "ABILITY_NONE"}:
                continue
            slug = entry.get("slug")
            if not slug:
                continue
            identity = entry.get("constant") or entry.get("label") or entry.get("title") or slug
            if slug in seen_slugs:
                raise ValueError(f"Duplicate {route} route slug '{slug}': {seen_slugs[slug]} and {identity}")
            seen_slugs[slug] = identity
            route_dir = OUT_DIR / route / slug
            route_dir.mkdir(parents=True, exist_ok=True)
            (route_dir / "index.html").write_text(detail_html, encoding="utf-8")


def build_docs_payload(
    visible_species: list[SpeciesRow],
    moves: dict[str, NamedRecord],
    abilities: dict[str, NamedRecord],
    ability_usage: AbilityUsage,
    tms: list[TMRow],
    important_items: list[ImportantItemRow],
    encounters: list[WildEncounterRow],
    trainers: list[TrainerRow],
    type_icons: dict[str, str],
    category_icons: dict[str, str],
    shiny_toggle_icon: str | None,
    mega_evolutions: list[MegaEvolutionRow],
    guides: list[GuideRow],
) -> DocsPayload:
    payload: DocsPayload = {
        "meta": {"generatedFrom": "tools/soulgold_docs/build_docs.py"},
        "species": [
            {
                "id": row.id,
                "constant": row.constant,
                "dex": row.display_dex,
                "name": row.name,
                "types": row.types,
                "stats": row.stats,
                "evYield": row.ev_yield,
                "eggGroups": row.egg_groups,
                "bst": sum(row.stats.values()),
                "abilities": row.abilities,
                "regularAbilities": row.regular_abilities,
                "hiddenAbilities": row.hidden_abilities,
                "innates": row.innates,
                "sprite": row.sprite,
                "shinySprite": row.shiny_sprite,
                "levelUp": row.level_up,
                "tmhm": row.tmhm,
                "tutors": row.tutors,
                "eggMoves": row.egg_moves,
                "evolutions": row.evolutions,
                "locations": row.locations,
                "heldItems": row.held_items,
                "slug": route_slug(row.constant, "SPECIES_"),
            }
            for row in visible_species
        ],
        "moves": {
            key: {**value, "slug": route_slug(key, "MOVE_")}
            for key, value in moves.items()
        },
        "abilities": {
            key: {
                **value,
                "slug": route_slug(key, "ABILITY_"),
                "usage": ability_usage.get(key, {"base": [], "innate": []}),
            }
            for key, value in abilities.items()
        },
        "tms": [{**row, "slug": row["label"].lower()} for row in tms],
        "items": [
            {**row, "slug": route_slug(row["constant"], "ITEM_")}
            for row in important_items
        ],
        "encounters": encounters,
        "trainers": trainers,
        "typeIcons": type_icons,
        "categoryIcons": category_icons,
        "uiIcons": {"shiny": shiny_toggle_icon} if shiny_toggle_icon else {},
        "megaEvolutions": mega_evolutions,
        "guides": guides,
    }
    return payload


def write_docs_payload(payload: DocsPayload) -> None:
    data_dir = OUT_DIR / "data"

    def write_json(name: str, value: object, *, pretty: bool = False) -> None:
        (data_dir / name).write_text(
            json.dumps(value, indent=2 if pretty else None, separators=None if pretty else (",", ":")),
            encoding="utf-8",
        )

    # Keep the full payload for downstream tooling while the website itself
    # loads compact, section-specific files on demand.
    write_json("romhack-docs.json", payload, pretty=True)
    write_json("common.json", {
        "meta": payload["meta"],
        "moves": payload["moves"],
        "abilities": {
            key: {field: value for field, value in ability.items() if field != "usage"}
            for key, ability in payload["abilities"].items()
        },
        "typeIcons": payload["typeIcons"],
        "categoryIcons": payload["categoryIcons"],
        "uiIcons": payload["uiIcons"],
        "megaEvolutions": payload["megaEvolutions"],
    })
    summary_fields = {
        "id", "constant", "dex", "name", "types", "stats", "bst",
        "abilities", "regularAbilities", "hiddenAbilities", "innates",
        "sprite", "slug",
    }
    write_json("species.json", [
        {key: value for key, value in row.items() if key in summary_fields}
        for row in payload["species"]
    ])
    write_json("species-details.json", {
        row["constant"]: {key: value for key, value in row.items() if key not in summary_fields}
        for row in payload["species"]
    })
    write_json("ability-usage.json", {
        key: ability["usage"]
        for key, ability in payload["abilities"].items()
    })
    for name, key in (
        ("encounters.json", "encounters"),
        ("machines.json", "tms"),
        ("items.json", "items"),
        ("trainers.json", "trainers"),
        ("guides.json", "guides"),
    ):
        write_json(name, payload[key])
    write_detail_routes(payload)
