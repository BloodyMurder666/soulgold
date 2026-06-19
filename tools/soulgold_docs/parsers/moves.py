"""Move table parsing for the SoulGold docs generator."""

from __future__ import annotations

import re

from ..c_parser import clean_constant_name, collect_strings, extract_field, extract_number, parse_shared_strings, preprocess, read, split_designated_entries
from ..models import NamedRecord
from ..paths import REPO_ROOT


def parse_moves() -> dict[str, NamedRecord]:
    include_path = "data/moves_info.h"
    key_prefix = "MOVE_"
    name_prefix = "MOVE_"
    text = preprocess(include_path)
    source_path = REPO_ROOT / include_path
    if not source_path.exists():
        source_path = REPO_ROOT / "src" / include_path
    source_text = read(source_path)
    shared_strings = parse_shared_strings(source_text)
    entries = split_designated_entries(text)
    rows: dict[str, NamedRecord] = {}

    for key, entry in entries.items():
        if not key.startswith(key_prefix):
            continue
        name_expr = extract_field(entry, "name") or ""
        desc_expr = extract_field(entry, "description") or ""
        name = collect_strings(name_expr) or clean_constant_name(key, name_prefix)
        description = collect_strings(desc_expr)
        if not description and desc_expr in shared_strings:
            description = shared_strings[desc_expr]
        rows[key] = {"constant": key, "name": name, "description": description}
        for field_name in ("power", "accuracy", "pp", "priority"):
            rows[key][field_name] = extract_number(entry, field_name)
        for field_name in ("type", "category"):
            expr = extract_field(entry, field_name) or ""
            const = re.search(r"\b[A-Z][A-Z0-9_]+\b", expr)
            rows[key][field_name] = const.group(0) if const else ""
    return rows
