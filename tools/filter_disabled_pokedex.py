#!/usr/bin/env python3

from __future__ import annotations

import re
import subprocess
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
POKEDEX_H = REPO_ROOT / "include/constants/pokedex.h"
POKEDEX_ORDERS_H = REPO_ROOT / "src/data/pokemon/pokedex_orders.h"
POKEMON_C = REPO_ROOT / "src/pokemon.c"

NATIONAL_DEX_RE = re.compile(r"\b(NATIONAL_DEX_[A-Z0-9_]+)\b")
HOENN_DEX_RE = re.compile(r"\b(HOENN_DEX_[A-Z0-9_]+)\b")
HOENN_TO_NATIONAL_RE = re.compile(r"\bHOENN_TO_NATIONAL\(([A-Z0-9_]+)\)")


def preprocess_species_info() -> str:
    temp_source = Path("/tmp/filter_disabled_pokedex_species_info.c")
    temp_source.write_text('#include "global.h"\n#include "data/pokemon/species_info.h"\n', encoding="utf-8")
    result = subprocess.run(
        ["gcc", "-E", "-P", str(temp_source), "-I.", "-Iinclude", "-Isrc"],
        cwd=REPO_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout


def parse_enabled_national_dex_constants() -> list[str]:
    enabled: list[str] = []
    seen: set[str] = set()
    for match in re.finditer(r"\.natDexNum\s*=\s*(NATIONAL_DEX_[A-Z0-9_]+)", preprocess_species_info()):
        constant = match.group(1)
        if constant not in seen:
            enabled.append(constant)
            seen.add(constant)
    if not enabled:
        raise RuntimeError("No enabled National Dex constants found in preprocessed species info.")
    return enabled


def parse_original_national_order(text: str) -> list[str]:
    constants: list[str] = []
    in_national_enum = False
    for line in text.splitlines():
        if line.startswith("enum NationalDexOrder"):
            in_national_enum = True
            continue
        if in_national_enum and line == "};":
            break
        if not in_national_enum:
            continue
        match = NATIONAL_DEX_RE.search(line)
        if match and match.group(1) != "NATIONAL_DEX_NONE":
            constants.append(match.group(1))
    return constants


def last_enabled_before_or_at(order: list[str], enabled: set[str], marker: str) -> str:
    last: str | None = None
    for constant in order:
        if constant in enabled:
            last = constant
        if constant == marker:
            break
    if last is None:
        raise RuntimeError(f"No enabled National Dex constants found at or before {marker}.")
    return last


def should_keep_national_line(line: str, enabled: set[str]) -> bool:
    match = NATIONAL_DEX_RE.search(line)
    return not match or match.group(1) == "NATIONAL_DEX_NONE" or match.group(1) in enabled


def should_keep_hoenn_line(line: str, enabled: set[str]) -> bool:
    match = HOENN_DEX_RE.search(line)
    if not match or match.group(1) == "HOENN_DEX_NONE":
        return True
    name = match.group(1).removeprefix("HOENN_DEX_")
    return f"NATIONAL_DEX_{name}" in enabled


def rewrite_pokedex_h(enabled_order: list[str]) -> None:
    enabled = set(enabled_order)
    text = POKEDEX_H.read_text(encoding="utf-8")
    original_order = parse_original_national_order(text)
    kanto_count = last_enabled_before_or_at(original_order, enabled, "NATIONAL_DEX_MEW")
    johto_count = last_enabled_before_or_at(original_order, enabled, "NATIONAL_DEX_CELEBI")
    national_count = enabled_order[-1]

    output: list[str] = []
    in_national_enum = False
    in_hoenn_enum = False
    skipping_national_count_block = False

    for line in text.splitlines():
        if line.startswith("// These constants are NOT disabled"):
            output.append("// Disabled species are filtered out by tools/filter_disabled_pokedex.py.")
            continue

        if line.startswith("enum NationalDexOrder"):
            in_national_enum = True
            output.append(line)
            continue

        if in_national_enum:
            if line == "};":
                in_national_enum = False
                output.append(line)
                continue
            if should_keep_national_line(line, enabled):
                output.append(line)
            continue

        if line.startswith("#define KANTO_DEX_COUNT"):
            output.append(f"#define KANTO_DEX_COUNT     {kanto_count}")
            continue
        if line.startswith("#define JOHTO_DEX_COUNT"):
            output.append(f"#define JOHTO_DEX_COUNT     {johto_count}")
            continue

        if line.startswith("#if P_GEN_9_POKEMON == TRUE"):
            skipping_national_count_block = True
            output.append(f"#define NATIONAL_DEX_COUNT  {national_count}")
            continue
        if skipping_national_count_block:
            if line == "#endif":
                skipping_national_count_block = False
            continue

        if line.startswith("enum HoennDexOrder"):
            in_hoenn_enum = True
            output.append(line)
            continue

        if in_hoenn_enum:
            if line == "};":
                in_hoenn_enum = False
                output.append(line)
                continue
            if should_keep_hoenn_line(line, enabled):
                output.append(line)
            continue

        if line.startswith("#define HOENN_DEX_COUNT"):
            hoenn_constants = [
                match.group(1)
                for match in HOENN_DEX_RE.finditer("\n".join(output))
                if match.group(1) != "HOENN_DEX_NONE"
            ]
            if not hoenn_constants:
                raise RuntimeError("No enabled Hoenn Dex constants remain.")
            output.append(f"#define HOENN_DEX_COUNT ({hoenn_constants[-1]} + 1)")
            continue

        output.append(line)

    POKEDEX_H.write_text("\n".join(output) + "\n", encoding="utf-8")


def rewrite_pokedex_orders_h(enabled_order: list[str]) -> None:
    enabled = set(enabled_order)
    output = [
        line
        for line in POKEDEX_ORDERS_H.read_text(encoding="utf-8").splitlines()
        if should_keep_national_line(line, enabled)
    ]
    POKEDEX_ORDERS_H.write_text("\n".join(output) + "\n", encoding="utf-8")


def rewrite_pokemon_c(enabled_order: list[str]) -> None:
    enabled = set(enabled_order)
    output: list[str] = []
    for line in POKEMON_C.read_text(encoding="utf-8").splitlines():
        match = HOENN_TO_NATIONAL_RE.search(line)
        if match and f"NATIONAL_DEX_{match.group(1)}" not in enabled:
            continue
        output.append(line)
    POKEMON_C.write_text("\n".join(output) + "\n", encoding="utf-8")


def main() -> None:
    enabled_order = parse_enabled_national_dex_constants()
    rewrite_pokedex_h(enabled_order)
    rewrite_pokedex_orders_h(enabled_order)
    rewrite_pokemon_c(enabled_order)
    print(f"Filtered dex data to {len(enabled_order)} enabled National Dex entries.")


if __name__ == "__main__":
    main()
