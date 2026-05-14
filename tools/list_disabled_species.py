#!/usr/bin/env python3

from __future__ import annotations

import argparse
import re
import subprocess
import tempfile
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
SPECIES_H = REPO_ROOT / "include/constants/species.h"
DEFAULT_OUTPUT = REPO_ROOT / "tools/disabled_species.txt"

SPECIES_DEFINE_RE = re.compile(r"^#define\s+(SPECIES_[A-Z0-9_]+)\s+(\d+)\b", re.MULTILINE)
SPECIES_INFO_BLOCK_RE = re.compile(
    r"^\s*\[(?P<id>\d+)\]\s*=\s*\{(?P<body>.*?)(?=^\s*\[\d+\]\s*=\s*\{|\n\};)",
    re.MULTILINE | re.DOTALL,
)
BASE_HP_RE = re.compile(r"\.baseHP\s*=\s*(?P<value>[^,\n]+)")


def parse_species_constants() -> dict[int, str]:
    species_by_id: dict[int, str] = {}
    for name, value in SPECIES_DEFINE_RE.findall(SPECIES_H.read_text(encoding="utf-8")):
        species_by_id[int(value)] = name
    return species_by_id


def preprocess_species_info() -> str:
    with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False, encoding="utf-8") as source:
        source.write('#include "global.h"\n#include "data/pokemon/species_info.h"\n')
        source_path = Path(source.name)

    try:
        result = subprocess.run(
            ["gcc", "-E", "-P", str(source_path), "-I.", "-Iinclude", "-Isrc"],
            cwd=REPO_ROOT,
            check=True,
            capture_output=True,
            text=True,
        )
        return result.stdout
    finally:
        source_path.unlink(missing_ok=True)


def parse_enabled_species_ids(preprocessed_species_info: str) -> set[int]:
    enabled: set[int] = set()
    for match in SPECIES_INFO_BLOCK_RE.finditer(preprocessed_species_info):
        base_hp = BASE_HP_RE.search(match.group("body"))
        if base_hp and base_hp.group("value").strip() != "0":
            enabled.add(int(match.group("id")))
    return enabled


def write_disabled_species(output_path: Path) -> int:
    species_by_id = parse_species_constants()
    enabled_ids = parse_enabled_species_ids(preprocess_species_info())
    disabled_species = [
        name
        for species_id, name in sorted(species_by_id.items())
        if species_id != 0 and name != "SPECIES_EGG" and species_id not in enabled_ids
    ]

    lines = [
        "# Disabled species generated from include/config/species_enabled.h",
        f"# Count: {len(disabled_species)}",
        "",
        *disabled_species,
        "",
    ]
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(lines), encoding="utf-8")
    return len(disabled_species)


def main() -> None:
    parser = argparse.ArgumentParser(description="List disabled species into a text file.")
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        default=DEFAULT_OUTPUT,
        help=f"Output txt path. Defaults to {DEFAULT_OUTPUT.relative_to(REPO_ROOT)}.",
    )
    args = parser.parse_args()

    output_path = args.output
    if not output_path.is_absolute():
        output_path = REPO_ROOT / output_path

    count = write_disabled_species(output_path)
    print(f"Wrote {count} disabled species to {output_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
