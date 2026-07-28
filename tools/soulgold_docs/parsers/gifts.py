"""Parse reachable scripted gift Pokemon for species location documentation."""

from __future__ import annotations

import json
import re
from collections import defaultdict
from typing import Mapping

from ..c_parser import read, strip_c_comments
from ..map_names import is_docs_excluded_map, map_display_name
from ..models import SpeciesLocation, SpeciesRow
from ..paths import GACHA_C, MAP_GROUPS_JSON, REPO_ROOT, SPECIES_H


SCRIPT_LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)(?:::|:)\s*$", re.MULTILINE)
GIFT_COMMAND_RE = re.compile(
    r"\b(givemon|giveegg)\s+(SPECIES_[A-Z0-9_]+)(?:\s*,\s*(\d+))?",
    re.IGNORECASE,
)
MASTER_GACHA_ARRAY_RE = re.compile(
    r"static\s+const\s+u16\s+sGachaMasterSpecies(?:Common|Uncommon|Rare|UltraRare)\[\]\s*=\s*\{(.*?)\};",
    re.DOTALL,
)
GIFT_LOCATION_NAME_OVERRIDES = {
    ("SPECIES_BELDUM", "MAP_KITAKAMI_HOUSES"): "Gift from Steven in Kitakami",
}


def species_aliases() -> dict[str, str]:
    aliases = dict(re.findall(
        r"^#define\s+(SPECIES_[A-Z0-9_]+)\s+(SPECIES_[A-Z0-9_]+)\s*$",
        read(SPECIES_H),
        re.MULTILINE,
    ))
    for alias in aliases:
        target = aliases[alias]
        seen = {alias}
        while target in aliases and target not in seen:
            seen.add(target)
            target = aliases[target]
        aliases[alias] = target
    return aliases


def script_blocks(text: str) -> dict[str, str]:
    text = strip_c_comments(text)
    matches = list(SCRIPT_LABEL_RE.finditer(text))
    return {
        match.group(1): text[match.end():matches[index + 1].start() if index + 1 < len(matches) else len(text)]
        for index, match in enumerate(matches)
    }


def reachable_script_labels(map_data: Mapping[str, object], blocks: dict[str, str]) -> set[str]:
    roots = {
        str(event.get("script"))
        for event_key in ("object_events", "coord_events", "bg_events")
        for event in map_data.get(event_key) or []
        if event.get("script")
    }
    roots.update(label for label in blocks if label.endswith("_MapScripts"))

    reachable: set[str] = set()
    pending = [label for label in roots if label in blocks]
    known_labels = set(blocks)
    while pending:
        label = pending.pop()
        if label in reachable:
            continue
        reachable.add(label)
        references = set(re.findall(r"\b[A-Za-z_][A-Za-z0-9_]*\b", blocks[label]))
        pending.extend(references & known_labels - reachable)
    return reachable


def add_gift_species_locations(
    locations: dict[str, list[SpeciesLocation]],
    by_species: dict[str, SpeciesRow],
) -> None:
    try:
        map_groups = json.loads(read(MAP_GROUPS_JSON))
    except (FileNotFoundError, json.JSONDecodeError):
        return

    aliases = species_aliases()
    gifts: dict[str, list[SpeciesLocation]] = defaultdict(list)
    for group_name in map_groups.get("group_order") or []:
        for map_name in map_groups.get(group_name) or []:
            if is_docs_excluded_map(map_name, group_name):
                continue
            map_dir = REPO_ROOT / "data" / "maps" / map_name
            script = map_dir / "scripts.inc"
            try:
                map_data = json.loads(read(map_dir / "map.json"))
                blocks = script_blocks(read(script))
            except (FileNotFoundError, json.JSONDecodeError):
                continue

            map_constant = str(map_data.get("id") or "")
            display_name = map_display_name(map_data, map_name)
            for label in reachable_script_labels(map_data, blocks):
                for command in GIFT_COMMAND_RE.finditer(blocks[label]):
                    method, raw_species, raw_level = command.groups()
                    species = aliases.get(raw_species, raw_species)
                    if species not in by_species:
                        continue
                    level = int(raw_level) if raw_level is not None else None
                    location_name = GIFT_LOCATION_NAME_OVERRIDES.get(
                        (species, map_constant),
                        display_name,
                    )
                    location: SpeciesLocation = {
                        "map": map_constant,
                        "name": location_name,
                        "time": "",
                        "method": "Gift Egg" if method.lower() == "giveegg" else "Gift",
                        "minLevel": level,
                        "maxLevel": level,
                        "rate": None,
                    }
                    if location not in gifts[species]:
                        gifts[species].append(location)

    for species, gift_locations in gifts.items():
        locations.setdefault(species, [])
        for location in gift_locations:
            if location not in locations[species]:
                locations[species].append(location)


def add_master_gachapon_species_locations(
    locations: dict[str, list[SpeciesLocation]],
    by_species: dict[str, SpeciesRow],
) -> None:
    try:
        text = strip_c_comments(read(GACHA_C))
    except FileNotFoundError:
        return

    aliases = species_aliases()
    for pool in MASTER_GACHA_ARRAY_RE.findall(text):
        for raw_species in re.findall(r"\bSPECIES_[A-Z0-9_]+\b", pool):
            species = aliases.get(raw_species, raw_species)
            if species not in by_species:
                continue
            location: SpeciesLocation = {
                "map": "MAP_MAUVILLE_CITY_GAME_CORNER",
                "name": "Goldenrod Gachapon",
                "time": "",
                "method": "Gachapon",
                "minLevel": None,
                "maxLevel": None,
                "rate": None,
            }
            locations.setdefault(species, [])
            if location not in locations[species]:
                locations[species].append(location)
