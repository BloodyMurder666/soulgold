"""Item, TM/HM, and item-location parsing for the SoulGold docs generator."""

from __future__ import annotations

import json
import re
from collections import defaultdict
from pathlib import Path
from typing import Mapping

from ..constants import GENERIC_MEGA_STONE_ITEMS, IMPORTANT_ITEM_POCKETS, IMPORTANT_ITEM_SORT_TYPES, ITEMS_HIDDEN_CONSTANTS, ITEMS_HIDDEN_SORT_TYPES, ITEMS_HIDDEN_SUFFIXES
from ..c_parser import clean_constant_name, collect_strings, extract_field, format_identifier_name, parse_enum_constants, parse_shared_strings, preprocess, read, split_designated_entries
from ..image_utils import copy_item_icon
from ..models import ImportantItemRow, ItemLocation, ItemRecord, NamedRecord, SpeciesRow, TMHMRow, TMRow
from ..paths import ITEMS_H, REPO_ROOT, TMS_HMS_H


def item_display_name(item: str, item_names: Mapping[str, ItemRecord]) -> str:
    return item_names.get(item, {}).get("name") or clean_constant_name(item, "ITEM_")

def parse_tmhm_list() -> list[TMHMRow]:
    text = read(TMS_HMS_H)
    tm_names = re.findall(r"FOREACH_TM\(F\)\s*\\(.*?)#define\s+FOREACH_HM", text, re.DOTALL)[0]
    hm_names = re.findall(r"FOREACH_HM\(F\)\s*\\(.*?)#define\s+FOREACH_TMHM", text, re.DOTALL)[0]

    def names(block: str) -> list[str]:
        return re.findall(r"F\(([A-Z0-9_]+)\)", block)

    rows = []
    for index, name in enumerate(names(tm_names), start=1):
        rows.append({"kind": "TM", "number": index, "item": f"ITEM_TM_{name}", "move": f"MOVE_{name}", "label": f"TM{index:02d}"})
    for index, name in enumerate(names(hm_names), start=1):
        rows.append({"kind": "HM", "number": index, "item": f"ITEM_HM_{name}", "move": f"MOVE_{name}", "label": f"HM{index:02d}"})
    return rows

def parse_item_records() -> dict[str, ItemRecord]:
    text = preprocess("data/items.h")
    source_text = read(REPO_ROOT / "src/data/items.h")
    shared_strings = parse_shared_strings(source_text)
    item_to_id, _ = parse_enum_constants(ITEMS_H, "ITEM_")
    entries = split_designated_entries(text)
    records: dict[str, ItemRecord] = {}
    for key, entry in entries.items():
        if not key.startswith("ITEM_"):
            continue
        desc_expr = extract_field(entry, "description") or ""
        description = collect_strings(desc_expr)
        if not description and desc_expr in shared_strings:
            description = shared_strings[desc_expr]
        pocket_expr = extract_field(entry, "pocket") or ""
        pocket_match = re.search(r"\bPOCKET_[A-Z0-9_]+\b", pocket_expr)
        sort_type_expr = extract_field(entry, "sortType") or ""
        sort_type_match = re.search(r"\bITEM_TYPE_[A-Z0-9_]+\b", sort_type_expr)
        icon_pic_expr = extract_field(entry, "iconPic") or ""
        icon_pic_match = re.search(r"\bgItemIcon_([A-Za-z0-9_]+)\b", icon_pic_expr)
        records[key] = {
            "id": item_to_id.get(key, 0),
            "constant": key,
            "name": collect_strings(extract_field(entry, "name") or ""),
            "description": description,
            "pocket": pocket_match.group(0) if pocket_match else "",
            "sortType": sort_type_match.group(0) if sort_type_match else "",
            "iconName": icon_pic_match.group(1) if icon_pic_match else "",
        }
    return records

def add_location(
    locations: dict[str, list[ItemLocation]],
    item: str,
    map_name: str,
    source: str,
) -> None:
    entry = {"map": map_name, "source": source}
    locations.setdefault(item, [])
    if entry not in locations[item]:
        locations[item].append(entry)

def format_item_location(map_data: Mapping[str, object], fallback_name: str, source: str) -> tuple[str, str]:
    if map_data.get("layout") == "LAYOUT_MAUVILLE_CITY_GAME_CORNER":
        return "Goldenrod City Game Corner", "Bought"
    return format_identifier_name(map_data.get("name") or fallback_name), source

def format_tmhm_location(map_data: Mapping[str, object], fallback_name: str, source: str) -> tuple[str, str]:
    return format_item_location(map_data, fallback_name, source)

def parse_tmhm_locations() -> dict[str, list[ItemLocation]]:
    locations: dict[str, list[ItemLocation]] = defaultdict(list)
    item_re = re.compile(r"\b(ITEM_(?:TM|HM)_[A-Z0-9_]+)\b")

    for map_json in sorted((REPO_ROOT / "data/maps").glob("*/map.json")):
        try:
            data = json.loads(read(map_json))
        except json.JSONDecodeError:
            continue
        map_name, source = format_tmhm_location(data, map_json.parent.name, "Item ball")
        for obj in data.get("object_events") or []:
            item = obj.get("trainer_sight_or_berry_tree_id", "")
            if item_re.fullmatch(item):
                add_location(locations, item, map_name, source)

    for script in sorted((REPO_ROOT / "data/maps").glob("*/scripts.*")):
        text = read(script)
        try:
            map_data = json.loads(read(script.parent / "map.json"))
        except (FileNotFoundError, json.JSONDecodeError):
            map_data = {}
        map_name, gift_source = format_tmhm_location(map_data, script.parent.name, "Gift")
        mart_map_name, mart_source = format_tmhm_location(map_data, script.parent.name, "Mart")
        for item in re.findall(r"\bgiveitem\s+(ITEM_(?:TM|HM)_[A-Z0-9_]+)\b", text):
            add_location(locations, item, map_name, gift_source)
        for item in re.findall(r"\bfinditem\s+(ITEM_(?:TM|HM)_[A-Z0-9_]+)\b", text):
            add_location(locations, item, map_name, gift_source)
        for item in re.findall(r"\.2byte\s+(ITEM_(?:TM|HM)_[A-Z0-9_]+)\b", text):
            add_location(locations, item, mart_map_name, mart_source)

    return dict(locations)

def parse_item_locations(item_constants: set[str]) -> dict[str, list[ItemLocation]]:
    locations: dict[str, list[ItemLocation]] = defaultdict(list)
    if not item_constants:
        return {}

    item_pattern = "|".join(sorted((re.escape(item) for item in item_constants), key=len, reverse=True))
    item_re = re.compile(rf"\b({item_pattern})\b")

    for map_json in sorted((REPO_ROOT / "data/maps").glob("*/map.json")):
        try:
            data = json.loads(read(map_json))
        except json.JSONDecodeError:
            continue
        map_name, source = format_item_location(data, map_json.parent.name, "Item ball")
        for obj in data.get("object_events") or []:
            item = obj.get("trainer_sight_or_berry_tree_id", "")
            if item in item_constants:
                add_location(locations, item, map_name, source)

    for script in sorted((REPO_ROOT / "data/maps").glob("*/scripts.*")):
        text = read(script)
        try:
            map_data = json.loads(read(script.parent / "map.json"))
        except (FileNotFoundError, json.JSONDecodeError):
            map_data = {}
        map_name, gift_source = format_item_location(map_data, script.parent.name, "Gift")
        hidden_map_name, hidden_source = format_item_location(map_data, script.parent.name, "Hidden item")
        mart_map_name, mart_source = format_item_location(map_data, script.parent.name, "Mart")
        held_map_name, held_source = format_item_location(map_data, script.parent.name, "Gift Pokemon held item")

        for item in re.findall(rf"\bgiveitem(?:\s+|\()\s*({item_pattern})\b", text):
            add_location(locations, item, map_name, gift_source)
        for item in re.findall(rf"\bfinditem(?:\s+|\()\s*({item_pattern})\b", text):
            add_location(locations, item, hidden_map_name, hidden_source)
        for item in re.findall(rf"\.2byte\s+({item_pattern})\b", text):
            add_location(locations, item, mart_map_name, mart_source)
        for match in re.finditer(rf"\bgivemon(?:\s+|\()(.*?)(?:\n|$)", text):
            for item in item_re.findall(match.group(1)):
                add_location(locations, item, held_map_name, held_source)

    return dict(locations)

def add_wild_held_item_locations(
    locations: dict[str, list[ItemLocation]],
    item_constants: set[str],
    species: list[SpeciesRow],
) -> None:
    for row in species:
        if not row.dex_visible:
            continue
        for held_item in row.held_items:
            item = held_item["constant"]
            if item in item_constants:
                add_location(locations, item, row.name, f"Wild held item ({held_item['rarity']})")

def is_hidden_important_item(constant: str, item: ItemRecord) -> bool:
    return (
        item.get("sortType") in ITEMS_HIDDEN_SORT_TYPES
        or constant in ITEMS_HIDDEN_CONSTANTS
        or any(constant.endswith(suffix) for suffix in ITEMS_HIDDEN_SUFFIXES)
    )

def build_important_items(
    item_records: dict[str, ItemRecord],
    species: list[SpeciesRow],
    item_icon_dir: Path,
) -> list[ImportantItemRow]:
    selected = {
        constant
        for constant, item in item_records.items()
        if (
            item.get("pocket") in IMPORTANT_ITEM_POCKETS
            or item.get("sortType") in IMPORTANT_ITEM_SORT_TYPES
            or constant in GENERIC_MEGA_STONE_ITEMS
        )
        and not is_hidden_important_item(constant, item)
    }
    locations = parse_item_locations(selected)
    add_wild_held_item_locations(locations, selected, species)
    rows = []
    for constant in sorted(selected, key=lambda item: item_records.get(item, {}).get("id", 0)):
        item = item_records[constant]
        item_locations = locations.get(constant, [])
        rows.append({
            "id": item.get("id", 0),
            "constant": constant,
            "name": item.get("name") or clean_constant_name(constant, "ITEM_"),
            "description": item.get("description", ""),
            "pocket": item.get("pocket", ""),
            "sortType": item.get("sortType", ""),
            "itemIcon": copy_item_icon(item, item_icon_dir),
            "locations": item_locations,
            "location": "; ".join(
                f"{entry['map']} ({entry['source']})"
                for entry in item_locations
            ),
        })
    return rows


def build_tms(
    tmhm_rows: list[TMHMRow],
    moves: Mapping[str, NamedRecord],
    item_records: Mapping[str, ItemRecord],
    tmhm_locations: Mapping[str, list[ItemLocation]],
) -> list[TMRow]:
    tms = []
    for row in tmhm_rows:
        move = moves.get(row["move"], {})
        item = item_records.get(row["item"], {})
        tms.append({
            **row,
            "name": item.get("name") or row["label"],
            "description": item.get("description") or move.get("description", ""),
            "moveName": move.get("name", clean_constant_name(row["move"], "MOVE_")),
            "type": move.get("type", ""),
            "category": move.get("category", ""),
            "power": move.get("power", 0),
            "accuracy": move.get("accuracy", 0),
            "pp": move.get("pp", 0),
            "locations": tmhm_locations.get(row["item"], []),
            "location": "; ".join(
                f"{entry['map']} ({entry['source']})"
                for entry in tmhm_locations.get(row["item"], [])
            ),
        })
    return tms
