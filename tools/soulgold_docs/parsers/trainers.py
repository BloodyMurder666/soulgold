"""Trainer party parsing and enrichment for the SoulGold docs generator."""

from __future__ import annotations

import json
import re
from pathlib import Path

from ..constants import ALWAYS_INCLUDED_TRAINER_CONSTANTS, SPRITE_CACHE_VERSION
from ..c_parser import clean_constant_name, eval_int_expr, normalize_token, read, slugify, strip_c_comments
from ..image_utils import copy_item_icon, process_sprite
from ..map_names import is_docs_excluded_map
from ..models import ItemRecord, ShowdownMon, SpeciesRow, TrainerMon, TrainerRow
from ..paths import MAP_GROUPS_JSON, OUT_DIR, REPO_ROOT, TRAINERS_H
from .species import species_for_trainer_mon


def parse_showdown_team(text: str) -> list[ShowdownMon]:
    """Parse a Pokemon Showdown export string into a list of Pokemon dicts."""
    mons = []
    current: ShowdownMon | None = None
    for raw_line in text.splitlines():
        line = raw_line.strip()
        if not line:
            if current is not None:
                mons.append(current)
                current = None
            continue

        # First non-empty line of a new mon: "Name @ Item" or just "Name"
        if current is None:
            if line.startswith("-") or ":" in line.split("@")[0]:
                # Looks like a move or field line without a header — malformed, skip
                continue
            if "@" in line:
                name_part, item_part = line.split("@", 1)
            else:
                name_part, item_part = line, ""
            species_match = re.search(r"\((SPECIES_[A-Z0-9_]+|[A-Za-z][A-Za-z0-9_ -]+)\)", name_part)
            # Strip gender marker e.g. "(M)"
            name_clean = re.sub(r"\s*\([MF]\)\s*", " ", name_part).strip()
            if species_match and species_match.group(1) not in {"M", "F"}:
                name_clean = species_match.group(1).strip()
            current = {
                "name": name_clean,
                "item": item_part.strip(),
                "level": 100,
                "ability": "",
                "nature": "",
                "evs": {},
                "ivs": {},
                "moves": [],
            }
            continue

        # Move line
        if line.startswith("-"):
            move = line.lstrip("- ").strip()
            if move:
                current["moves"].append(move)
            continue

        if ":" in line:
            key, _, value = line.partition(":")
            key = key.strip().lower()
            value = value.strip()
            if key == "ability":
                current["ability"] = value
            elif key == "level":
                level = eval_int_expr(value)
                current["level"] = level if level is not None else 100
            elif key == "nature" or line.endswith("Nature"):
                current["nature"] = value.replace("Nature", "").strip()
            elif key == "evs":
                current["evs"] = _parse_stat_spread(value)
            elif key == "ivs":
                current["ivs"] = _parse_stat_spread(value)
            continue

        # "Modest Nature" style (no colon)
        if line.endswith("Nature"):
            current["nature"] = line.replace("Nature", "").strip()

    if current is not None:
        mons.append(current)
    return mons

def _parse_stat_spread(text: str) -> dict[str, int]:
    """Parse '252 HP / 4 Atk / 252 Spe' into {'hp': 252, 'atk': 4, 'spe': 252}."""
    stat_aliases = {
        "hp": "hp", "atk": "atk", "def": "def",
        "spa": "spa", "spd": "spd", "spe": "spe",
        "spatk": "spa", "spdef": "spd", "spd": "spd",
    }
    result: dict[str, int] = {}
    for chunk in text.split("/"):
        chunk = chunk.strip()
        match = re.match(r"(\d+)\s+(.*)", chunk)
        if not match:
            continue
        value, stat_name = int(match.group(1)), match.group(2).strip().lower().replace(" ", "")
        canonical = stat_aliases.get(stat_name)
        if canonical:
            result[canonical] = value
    return result

def normalize_trainer_mon_details(mon: ShowdownMon) -> ShowdownMon:
    """Keep optional trainer set data present and consistently ordered for the docs UI."""
    stat_order = ("hp", "atk", "def", "spa", "spd", "spe")
    normalized = dict(mon)
    normalized["item"] = normalized.get("item", "")
    normalized["ability"] = normalized.get("ability", "")
    normalized["evs"] = {stat: normalized.get("evs", {})[stat] for stat in stat_order if stat in normalized.get("evs", {})}
    normalized["ivs"] = {stat: normalized.get("ivs", {})[stat] for stat in stat_order if stat in normalized.get("ivs", {})}
    normalized["moves"] = [move for move in normalized.get("moves", []) if move]
    return normalized

def trainer_display_name(name: str, constant: str, difficulty: str) -> str:
    display_name = name
    variant_match = re.search(r"_(\d+)$", constant)
    if variant_match and not re.search(rf"\b{variant_match.group(1)}\b$", display_name):
        display_name = f"{display_name} {variant_match.group(1)}"
    if difficulty.lower() == "hard":
        display_name = f"{display_name} (Hard)"
    return display_name

def average_party_level(party: list[TrainerMon]) -> float:
    if not party:
        return 0
    return sum(mon.get("level", 100) for mon in party) / len(party)

def build_item_lookup(item_records: dict[str, ItemRecord]) -> dict[str, ItemRecord]:
    lookup: dict[str, ItemRecord] = {}
    for constant, item in item_records.items():
        names = {
            constant,
            constant.removeprefix("ITEM_"),
            item.get("name", ""),
            clean_constant_name(constant, "ITEM_"),
        }
        for name in names:
            if name:
                lookup.setdefault(normalize_token(name), item)
    return lookup

def resolve_trainer_item(item_name: str, item_lookup: dict[str, ItemRecord]) -> ItemRecord | None:
    return item_lookup.get(normalize_token(item_name))

def trainer_pic_source(pic_name: str, trainer_front_sources: dict[str, Path]) -> Path | None:
    candidates = [
        normalize_token(pic_name),
        normalize_token(slugify(pic_name)),
        normalize_token(pic_name.replace("Trainer", "Trainer ")),
    ]
    for candidate in candidates:
        if candidate in trainer_front_sources:
            return trainer_front_sources[candidate]
    return None

def front_pic_symbol_for_name(name: str, front_sources: dict[str, Path]) -> str | None:
    clean_name = name.removeprefix("SPECIES_")
    pascal_name = "".join(part.capitalize() for part in re.findall(r"[A-Za-z0-9]+", clean_name))
    candidates = [
        f"gMonFrontPic_{pascal_name}",
        f"gMonFrontPic_{pascal_name}Standard",
    ]
    for candidate in candidates:
        if candidate in front_sources:
            return candidate
    return None

def enrich_trainer_party(
    party: list[ShowdownMon],
    species_lookup: dict[str, SpeciesRow],
    front_sources: dict[str, Path],
    sprite_dir: Path,
    item_lookup: dict[str, ItemRecord],
    item_icon_dir: Path,
) -> list[TrainerMon]:
    enriched = []
    for mon in party:
        mon = normalize_trainer_mon_details(mon)
        species = species_for_trainer_mon(mon["name"], species_lookup)
        held_item = resolve_trainer_item(mon["item"], item_lookup)
        display_name = mon["name"]
        if display_name.startswith("SPECIES_"):
            display_name = species.name if species else clean_constant_name(display_name, "SPECIES_")
        sprite = species.sprite if species else None
        if sprite is None:
            symbol = front_pic_symbol_for_name(display_name, front_sources)
            if symbol:
                sprite_path = sprite_dir / f"{slugify(display_name)}.png"
                process_sprite(front_sources[symbol], sprite_path)
                sprite = str(sprite_path.relative_to(OUT_DIR))
        enriched.append({
            **mon,
            "constant": species.constant if species else "",
            "displayName": display_name,
            "itemConstant": held_item["constant"] if held_item else "",
            "itemName": held_item["name"] if held_item else mon["item"],
            "itemDescription": held_item["description"] if held_item else "",
            "itemIcon": copy_item_icon(held_item, item_icon_dir),
            "sprite": sprite,
        })
    return enriched

def trainer_constants_for_docs_maps() -> set[str]:
    """Return trainer constants referenced by non-Kanto, non-Hoenn map scripts."""
    try:
        map_groups = json.loads(read(MAP_GROUPS_JSON))
    except (FileNotFoundError, json.JSONDecodeError):
        return set()

    constants: set[str] = set()
    trainer_re = re.compile(r"\btrainerbattle(?:_[a-z0-9_]+)?(?:\s+|\()\s*(TRAINER_[A-Z0-9_]+)\b", re.IGNORECASE)

    for group_name in map_groups.get("group_order") or []:
        for map_name in map_groups.get(group_name) or []:
            if is_docs_excluded_map(map_name, group_name):
                continue
            map_dir = REPO_ROOT / "data/maps" / map_name
            if not map_dir.is_dir():
                continue
            for script in sorted(map_dir.glob("scripts.*")):
                constants.update(
                    constant
                    for constant in trainer_re.findall(read(script))
                    if constant != "TRAINER_NONE"
                )

    return constants | ALWAYS_INCLUDED_TRAINER_CONSTANTS

def parse_trainers(
    species_lookup: dict[str, SpeciesRow],
    front_sources: dict[str, Path],
    trainer_front_sources: dict[str, Path],
    sprite_dir: Path,
    trainer_sprite_dir: Path,
    item_records: dict[str, ItemRecord],
    item_icon_dir: Path,
    allowed_trainer_constants: set[str] | None = None,
) -> list[TrainerRow]:
    """Read trainers.party and parse each === TRAINER_* === block."""
    if not TRAINERS_H.exists():
        return []

    text = strip_c_comments(read(TRAINERS_H))
    trainers: list[TrainerRow] = []
    header_re = re.compile(r"^===\s*(TRAINER_[A-Z0-9_]+)\s*===", re.MULTILINE)
    matches = list(header_re.finditer(text))
    item_lookup = build_item_lookup(item_records)

    for index, match in enumerate(matches):
        constant = match.group(1)
        if allowed_trainer_constants is not None and constant not in allowed_trainer_constants:
            continue
        start = match.end()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        block = text[start:end].strip()
        name_match = re.search(r"^Name:\s*(.*?)\s*$", block, re.MULTILINE)
        pic_match = re.search(r"^Pic:\s*(.*?)\s*$", block, re.MULTILINE)
        difficulty_match = re.search(r"^Difficulty:\s*(.*?)\s*$", block, re.MULTILINE)
        name = name_match.group(1).strip() if name_match and name_match.group(1).strip() else clean_constant_name(constant, "TRAINER_")
        pic = pic_match.group(1).strip() if pic_match else ""
        difficulty = difficulty_match.group(1).strip() if difficulty_match and difficulty_match.group(1).strip() else "Normal"
        party = enrich_trainer_party(parse_showdown_team(block), species_lookup, front_sources, sprite_dir, item_lookup, item_icon_dir)
        if not party:
            continue

        front_sprite = None
        source = trainer_pic_source(pic, trainer_front_sources) if pic else None
        if source:
            target = trainer_sprite_dir / source.name
            process_sprite(source, target)
            front_sprite = f"{target.relative_to(OUT_DIR)}?v={SPRITE_CACHE_VERSION}"

        trainers.append({
            "constant": constant,
            "name": name,
            "displayName": trainer_display_name(name, constant, difficulty),
            "difficulty": difficulty,
            "averageLevel": round(average_party_level(party), 2),
            "pic": pic,
            "sprite": front_sprite,
            "party": party,
        })
    return sorted(trainers, key=lambda trainer: (trainer["averageLevel"], trainer["displayName"], trainer["constant"]))
