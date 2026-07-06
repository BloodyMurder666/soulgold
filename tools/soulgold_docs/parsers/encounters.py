"""Wild encounter parsing and species-location aggregation."""

from __future__ import annotations

import json
import re
from collections import defaultdict

from ..constants import BATTLE_PYRAMID_WILD_LABEL, ENCOUNTER_SLOT_RATES, JOHTO_ROUTE_PROGRESS, TIME_NIGHT_SUFFIX, UNKNOWN_MAP
from ..c_parser import clean_constant_name, read
from ..map_names import map_constant_display_name
from ..models import RawEncounterRow, SpeciesLocation, SpeciesRow, WildEncounterRow
from ..paths import WILD_ENCOUNTERS_JSON


def parse_wild_encounters(by_species: dict[str, SpeciesRow]) -> list[WildEncounterRow]:
    data = json.loads(read(WILD_ENCOUNTERS_JSON))
    rows = []
    original_index = 0
    for group in data.get("wild_encounter_groups", []):
        if group.get("label") == BATTLE_PYRAMID_WILD_LABEL:
            continue
        for encounter in group.get("encounters", []):
            map_const = encounter.get("map", UNKNOWN_MAP)
            label = map_constant_display_name(map_const)
            base_label = encounter.get("base_label", "")
            time_label = "Night" if base_label.endswith(TIME_NIGHT_SUFFIX) else "Day"
            methods = []
            for method, payload in encounter.items():
                if not isinstance(payload, dict) or "mons" not in payload:
                    continue
                mons = []
                slot_rates = ENCOUNTER_SLOT_RATES.get(method, [])
                for slot, mon in enumerate(payload.get("mons", [])):
                    species_const = mon.get("species", "SPECIES_NONE")
                    species = by_species.get(species_const)
                    mons.append({
                        "species": species_const,
                        "hasSpecies": species is not None,
                        "name": species.name if species else clean_constant_name(species_const, "SPECIES_"),
                        "sprite": species.sprite if species else None,
                        "minLevel": mon.get("min_level"),
                        "maxLevel": mon.get("max_level"),
                        "rate": slot_rates[slot] if slot < len(slot_rates) else mon.get("encounter_rate"),
                    })
                methods.append({"key": method, "method": method.replace("_", " ").title(), "mons": mons})
            if methods:
                rows.append({
                    "map": map_const,
                    "name": label,
                    "baseLabel": base_label,
                    "time": time_label,
                    "methods": methods,
                    "_order": original_index,
                })
                original_index += 1
    rows = merge_time_variant_encounters(rows)
    rows.sort(key=wild_encounter_sort_key)
    for row in rows:
        row.pop("_order", None)
    return rows

def canonical_encounter_label(base_label: str) -> str:
    return re.sub(r"_Night$", "", base_label or "")

def merge_time_variant_encounters(rows: list[RawEncounterRow]) -> list[RawEncounterRow]:
    merged: dict[tuple[str, str], RawEncounterRow] = {}
    for row in rows:
        key = (row["map"], canonical_encounter_label(row["baseLabel"]))
        if key not in merged:
            merged[key] = {
                "map": row["map"],
                "name": row["name"],
                "baseLabel": canonical_encounter_label(row["baseLabel"]) or row["baseLabel"],
                "variants": [],
                "_order": row["_order"],
            }
        target = merged[key]
        target["_order"] = min(target["_order"], row["_order"])
        target["variants"].append({
            "time": row["time"],
            "baseLabel": row["baseLabel"],
            "methods": row["methods"],
            "_order": row["_order"],
        })

    for row in merged.values():
        row["variants"].sort(key=lambda variant: (variant["time"] == "Night", variant["_order"]))
        has_night_variant = any(variant["time"] == "Night" for variant in row["variants"])
        row["hasTimeVariants"] = has_night_variant
        for variant in row["variants"]:
            variant["showTime"] = has_night_variant
            variant.pop("_order", None)
    return list(merged.values())

def wild_encounter_sort_key(encounter: RawEncounterRow) -> tuple[int, int, int]:
    haystack = f"{encounter.get('map', '')} {encounter.get('baseLabel', '')} {encounter.get('name', '')}"
    match = re.search(r"\b(?:MAP_)?ROUTE_?(\d+)\b|\bRoute\s*(\d+)\b|\bgRoute(\d+)\b", haystack, re.IGNORECASE)
    route = int(next(group for group in match.groups() if group)) if match else None
    if route in JOHTO_ROUTE_PROGRESS:
        return (0, JOHTO_ROUTE_PROGRESS[route], encounter["_order"])
    return (1, encounter["_order"], 0)

def build_species_locations(encounters: list[WildEncounterRow]) -> dict[str, list[SpeciesLocation]]:
    locations: dict[str, list[SpeciesLocation]] = defaultdict(list)
    seen: dict[str, set[tuple[object, ...]]] = defaultdict(set)
    for encounter in encounters:
        for variant in encounter.get("variants", [{"time": "", "methods": encounter.get("methods", [])}]):
            time = variant.get("time", "") if variant.get("showTime") else ""
            for method in variant["methods"]:
                for mon in method["mons"]:
                    key = (
                        encounter["map"],
                        time,
                        method["method"],
                        mon.get("minLevel"),
                        mon.get("maxLevel"),
                        mon.get("rate"),
                    )
                    if key in seen[mon["species"]]:
                        continue
                    seen[mon["species"]].add(key)
                    locations[mon["species"]].append({
                        "map": encounter["map"],
                        "name": encounter["name"],
                        "time": time,
                        "method": method["method"],
                        "minLevel": mon.get("minLevel"),
                        "maxLevel": mon.get("maxLevel"),
                        "rate": mon.get("rate"),
                    })
    return dict(locations)
