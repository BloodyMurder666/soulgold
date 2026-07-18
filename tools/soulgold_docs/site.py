"""Static site output preparation and JSON payload assembly."""

from __future__ import annotations

import json
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

SECTION_ROUTES = ("moves", "encounters", "machines", "items", "trainers", "abilities", "guides")


def prepare_output_tree() -> OutputPaths:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
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
            }
            for row in visible_species
        ],
        "moves": moves,
        "abilities": {
            key: {**value, "usage": ability_usage.get(key, {"base": [], "innate": []})}
            for key, value in abilities.items()
        },
        "tms": tms,
        "items": important_items,
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
    (OUT_DIR / "data" / "romhack-docs.json").write_text(
        json.dumps(payload, indent=2),
        encoding="utf-8",
    )
