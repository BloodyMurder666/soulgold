"""Resolve internal map identifiers to their in-game display names."""

from __future__ import annotations

import json
from functools import cache
from typing import Mapping

from .constants import EXCLUDED_TRAINER_MAP_GROUPS, EXCLUDED_TRAINER_MAP_NAMES, EXCLUDED_TRAINER_MAP_PREFIXES
from .c_parser import format_identifier_name, normalize_token, read
from .paths import REGION_MAP_SECTIONS_JSON, REPO_ROOT


@cache
def region_map_section_names() -> dict[str, str]:
    try:
        data = json.loads(read(REGION_MAP_SECTIONS_JSON))
    except (FileNotFoundError, json.JSONDecodeError):
        return {}
    return {
        section["id"]: section["name"]
        for section in data.get("map_sections", [])
        if section.get("id") and section.get("name")
    }


@cache
def map_data_by_constant() -> dict[str, Mapping[str, object]]:
    maps: dict[str, Mapping[str, object]] = {}
    for map_json in sorted((REPO_ROOT / "data/maps").glob("*/map.json")):
        try:
            data = json.loads(read(map_json))
        except (FileNotFoundError, json.JSONDecodeError):
            continue
        if map_constant := data.get("id"):
            maps[str(map_constant)] = data
    return maps


def _renamed_region_map_name(map_data: Mapping[str, object], fallback: str) -> str:
    """Apply a renamed region-map name while retaining floor/variant suffixes."""
    map_constant = str(map_data.get("id") or "")
    section_constant = str(map_data.get("region_map_section") or "")
    section_name = region_map_section_names().get(section_constant)
    if not map_constant or not section_name:
        return fallback

    map_key = map_constant.removeprefix("MAP_")
    section_key = section_constant.removeprefix("MAPSEC_")
    if normalize_token(section_name) == normalize_token(format_identifier_name(section_key)):
        return fallback
    if map_key == section_key:
        return section_name
    if map_key.startswith(f"{section_key}_"):
        suffix = format_identifier_name(map_key.removeprefix(f"{section_key}_"))
        return f"{section_name} {suffix}"
    return fallback


def map_display_name(map_data: Mapping[str, object], fallback_name: str) -> str:
    fallback = format_identifier_name(str(map_data.get("name") or fallback_name))
    return _renamed_region_map_name(map_data, fallback)


def map_constant_display_name(map_constant: str) -> str:
    map_data = map_data_by_constant().get(map_constant, {})
    fallback = map_constant.removeprefix("MAP_").replace("_", " ").title()
    return _renamed_region_map_name(map_data, fallback)


def is_docs_excluded_map(map_name: str, group_name: str) -> bool:
    """Return whether a legacy or currently unreachable map is outside the docs."""
    if group_name in EXCLUDED_TRAINER_MAP_GROUPS:
        return True
    if map_name in EXCLUDED_TRAINER_MAP_NAMES:
        return True
    return map_name.endswith("_Frlg") or map_name.startswith(EXCLUDED_TRAINER_MAP_PREFIXES)
