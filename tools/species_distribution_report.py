#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import re
import subprocess
import textwrap
from collections import defaultdict
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

from PIL import Image


REPO_ROOT = Path(__file__).resolve().parent.parent
SPECIES_H = REPO_ROOT / "include/constants/species.h"
SPECIES_ENABLED_CONFIG = REPO_ROOT / "include/config/species_enabled.h"
WILD_ENCOUNTERS_JSON = REPO_ROOT / "src/data/wild_encounters.json"
TRAINERS_PARTY = REPO_ROOT / "src/data/trainers.party"
GRAPHICS_POKEMON_H = REPO_ROOT / "src/data/graphics/pokemon.h"
SPECIES_INFO_DIR = REPO_ROOT / "src/data/pokemon/species_info"

SPECIES_DEFINE_RE = re.compile(r"^\s*#define\s+(SPECIES_[A-Z0-9_]+)\s+(\d+)\s*$")
CONFIG_DEFINE_RE = re.compile(r"^\s*#define\s+(P_[A-Z0-9_]+)\s+([A-Z0-9_]+)\b")
ENTRY_START_RE = re.compile(r"^\s*\[(\d+)\]\s*=\s*$")
SPECIES_NAME_RE = re.compile(r'^\s*\.speciesName\s*=\s*_\("((?:[^"\\]|\\.)*)"\),?\s*$')
TRUE_FLAG_RE = re.compile(r"^\s*\.(is[A-Za-z0-9_]+)\s*=\s*(?:TRUE|1)\b")
ICON_SPRITE_RE = re.compile(r"^\s*\.iconSprite\s*=\s*(gMonIcon_[A-Za-z0-9_]+),?\s*$")
TYPES_RE = re.compile(r"^\s*\.types\s*=\s*\{\s*(TYPE_[A-Z0-9_]+)\s*,\s*(TYPE_[A-Z0-9_]+)\s*\},?\s*$")
TRAINER_HEADER_RE = re.compile(r"^===\s*(TRAINER_[A-Z0-9_]+)\s*===\s*$")
GRAPHICS_ICON_RE = re.compile(
    r'^\s*const u8 (gMonIcon_[A-Za-z0-9_]+)\[\] = INCBIN_U8\(\s*"([^"]+/icon(?:f)?(?:_gba)?\.4bpp)"\s*\);'
)
FAMILY_IF_RE = re.compile(r"^\s*#if\s+(P_FAMILY_[A-Z0-9_]+)\s*$")
FAMILY_ENDIF_RE = re.compile(r"^\s*#endif\b")
ANY_IF_RE = re.compile(r"^\s*#(?:if|ifdef|ifndef)\b")
SPECIES_ENTRY_RE = re.compile(r"\[\s*(SPECIES_[A-Z0-9_]+)\s*\]\s*=")

TRAINER_METADATA_PREFIXES = (
    "Name:",
    "Class:",
    "Pic:",
    "Gender:",
    "Music:",
    "Items:",
    "Battle Type:",
    "Double Battle:",
    "AI:",
    "Mugshot:",
    "Starting Status:",
)

POKEMON_FIELD_PREFIXES = (
    "Level:",
    "Ability:",
    "IVs:",
    "EVs:",
    "Ball:",
    "Happiness:",
    "Nature:",
    "Shiny:",
    "Dynamax Level:",
    "Gigantamax:",
    "Tera Type:",
)

EXCLUDED_FORM_FLAGS = {
    "isMegaEvolution",
    "isPrimalReversion",
    "isUltraBurst",
    "isGigantamax",
    "isTeraForm",
    "isTotem",
}

LEGENDARY_FLAGS = {
    "isRestrictedLegendary",
    "isSubLegendary",
    "isMythical",
}

NOT_DISTRIBUTED_BLACKLIST = {
    "SPECIES_NIHILEGO",
    "SPECIES_BUZZWOLE",
    "SPECIES_PHEROMOSA",
    "SPECIES_XURKITREE",
    "SPECIES_CELESTEELA",
    "SPECIES_KARTANA",
    "SPECIES_GUZZLORD",
    "SPECIES_NECROZMA",
    "SPECIES_GREAT_TUSK",
    "SPECIES_SCREAM_TAIL",
    "SPECIES_BRUTE_BONNET",
    "SPECIES_FLUTTER_MANE",
    "SPECIES_SLITHER_WING",
    "SPECIES_SANDY_SHOCKS",
    "SPECIES_IRON_TREADS",
    "SPECIES_IRON_BUNDLE",
    "SPECIES_IRON_HANDS",
    "SPECIES_IRON_JUGULIS",
    "SPECIES_IRON_MOTH",
    "SPECIES_IRON_THORNS",
    "SPECIES_ROARING_MOON",
    "SPECIES_IRON_VALIANT",
    "SPECIES_WALKING_WAKE",
    "SPECIES_IRON_LEAVES",
    "SPECIES_GOUGING_FIRE",
    "SPECIES_RAGING_BOLT",
    "SPECIES_IRON_BOULDER",
    "SPECIES_IRON_CROWN",
}


@dataclass
class SpeciesEntry:
    species_id: int
    constant: str
    display_name: str
    flags: set[str]
    icon_symbol: str | None
    types: tuple[str, str]

    @property
    def excluded(self) -> bool:
        return bool(self.flags & (LEGENDARY_FLAGS | EXCLUDED_FORM_FLAGS))


def normalize_token(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", value.lower())


def parse_species_constants() -> tuple[dict[int, str], dict[str, int]]:
    id_to_constant: dict[int, str] = {}
    constant_to_id: dict[str, int] = {}
    for line in SPECIES_H.read_text(encoding="utf-8").splitlines():
        match = SPECIES_DEFINE_RE.match(line)
        if not match:
            continue
        constant, species_id = match.groups()
        species_id = int(species_id)
        id_to_constant[species_id] = constant
        constant_to_id[constant] = species_id
    return id_to_constant, constant_to_id


def parse_species_enabled_macros() -> dict[str, str]:
    macros: dict[str, str] = {}
    for line in SPECIES_ENABLED_CONFIG.read_text(encoding="utf-8").splitlines():
        match = CONFIG_DEFINE_RE.match(line)
        if match:
            macros[match.group(1)] = match.group(2)
    return macros


def resolve_config_bool(name: str, macros: dict[str, str], seen: set[str] | None = None) -> bool | None:
    if name == "TRUE":
        return True
    if name == "FALSE":
        return False
    if seen is None:
        seen = set()
    if name in seen:
        return None
    value = macros.get(name)
    if value is None:
        return None
    seen.add(name)
    return resolve_config_bool(value, macros, seen)


def preprocess_species_info() -> str:
    temp_source = Path("/tmp/species_distribution_report_species_info.c")
    temp_source.write_text('#include "global.h"\n#include "data/pokemon/species_info.h"\n', encoding="utf-8")
    cmd = ["gcc", "-E", "-P", str(temp_source), "-I.", "-Iinclude", "-Isrc"]
    result = subprocess.run(
        cmd,
        cwd=REPO_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout


def parse_enabled_species(id_to_constant: dict[int, str]) -> dict[int, SpeciesEntry]:
    preprocessed = preprocess_species_info().splitlines()
    entries: dict[int, SpeciesEntry] = {}

    in_array = False
    current_id: int | None = None
    current_lines: list[str] = []
    brace_depth = 0

    for line in preprocessed:
        if not in_array:
            if line.strip() == "const struct SpeciesInfo gSpeciesInfo[] =":
                in_array = True
            continue

        if current_id is None:
            match = ENTRY_START_RE.match(line)
            if match:
                current_id = int(match.group(1))
                current_lines = []
                brace_depth = 0
            elif line.strip() == "};":
                break
            continue

        current_lines.append(line)
        brace_depth += line.count("{")
        brace_depth -= line.count("}")
        if brace_depth > 0:
            continue

        constant = id_to_constant.get(current_id)
        if constant and constant not in {"SPECIES_NONE", "SPECIES_EGG"}:
            species_name = constant.removeprefix("SPECIES_").replace("_", " ").title()
            flags: set[str] = set()
            icon_symbol: str | None = None
            types = ("TYPE_NORMAL", "TYPE_NORMAL")
            for entry_line in current_lines:
                name_match = SPECIES_NAME_RE.match(entry_line)
                if name_match:
                    species_name = bytes(name_match.group(1), "utf-8").decode("unicode_escape")
                flag_match = TRUE_FLAG_RE.match(entry_line)
                if flag_match:
                    flags.add(flag_match.group(1))
                icon_match = ICON_SPRITE_RE.match(entry_line)
                if icon_match:
                    icon_symbol = icon_match.group(1)
                types_match = TYPES_RE.match(entry_line)
                if types_match:
                    types = (types_match.group(1), types_match.group(2))
            entries[current_id] = SpeciesEntry(
                species_id=current_id,
                constant=constant,
                display_name=species_name,
                flags=flags,
                icon_symbol=icon_symbol,
                types=types,
            )

        current_id = None
        current_lines = []

    return entries


def build_alias_map(entries: dict[int, SpeciesEntry], constant_to_id: dict[str, int]) -> dict[str, int]:
    aliases: dict[str, int] = {}

    for constant, species_id in constant_to_id.items():
        if constant in {"SPECIES_NONE", "SPECIES_EGG"}:
            continue
        constant_name = constant.removeprefix("SPECIES_")
        for alias in (
            constant,
            constant_name,
            constant_name.replace("_", " "),
            constant_name.replace("_", "-"),
        ):
            aliases.setdefault(normalize_token(alias), species_id)

    for species_id, entry in sorted(entries.items()):
        aliases.setdefault(normalize_token(entry.display_name), species_id)

    return aliases


def parse_icon_symbol_to_source_path() -> dict[str, Path]:
    icon_map: dict[str, Path] = {}

    for line in GRAPHICS_POKEMON_H.read_text(encoding="utf-8").splitlines():
        match = GRAPHICS_ICON_RE.match(line)
        if not match:
            continue
        symbol, incbin_path = match.groups()
        png_path = REPO_ROOT / re.sub(r"(?:_gba)?\.4bpp$", ".png", incbin_path)
        if not png_path.exists():
            png_path = REPO_ROOT / re.sub(r"(?:_gba)?\.4bpp$", ".opng", incbin_path)
        if png_path.exists():
            icon_map.setdefault(symbol, png_path)

    return icon_map


def guess_icon_symbol(entry: SpeciesEntry, icon_source_map: dict[str, Path]) -> str | None:
    if entry.icon_symbol and entry.icon_symbol in icon_source_map:
        return entry.icon_symbol

    target = normalize_token(entry.constant.removeprefix("SPECIES_"))
    for symbol in icon_source_map:
        if normalize_token(symbol.removeprefix("gMonIcon_")) == target:
            return symbol

    return None


def process_icon(source_path: Path, output_path: Path) -> None:
    output_path.parent.mkdir(parents=True, exist_ok=True)
    image = Image.open(source_path)
    if image.mode != "P":
        image = image.convert("P")

    cropped = image.crop((0, 0, 32, 32))
    rgba = cropped.convert("RGBA")
    transparent_index = 0

    alpha_pixels = []
    for y in range(cropped.height):
        for x in range(cropped.width):
            pixel = rgba.getpixel((x, y))
            palette_index = cropped.getpixel((x, y))
            if palette_index == transparent_index:
                alpha_pixels.append((pixel[0], pixel[1], pixel[2], 0))
            else:
                alpha_pixels.append(pixel)

    rgba.putdata(alpha_pixels)
    rgba.save(output_path)


def format_type_name(type_constant: str) -> str:
    return type_constant.removeprefix("TYPE_").replace("_", " ").title()


def format_map_name(map_constant: str) -> str:
    if not map_constant or map_constant == "UNKNOWN_MAP":
        return "Unknown Map"
    return map_constant.removeprefix("MAP_").replace("_", " ").title()


def parse_species_to_family() -> dict[str, str]:
    species_to_family: dict[str, str] = {}

    for header_path in sorted(SPECIES_INFO_DIR.glob("gen_*_families.h")):
        family_stack: list[str | None] = []
        current_family: str | None = None
        for line in header_path.read_text(encoding="utf-8").splitlines():
            family_match = FAMILY_IF_RE.match(line)
            if family_match:
                family_stack.append(current_family)
                current_family = family_match.group(1)
                continue

            if ANY_IF_RE.match(line):
                family_stack.append(current_family)
                continue

            if FAMILY_ENDIF_RE.match(line):
                current_family = family_stack.pop() if family_stack else None
                continue

            if current_family is None:
                continue

            species_match = SPECIES_ENTRY_RE.search(line)
            if species_match:
                species_to_family.setdefault(species_match.group(1), current_family)

    return species_to_family


def parse_wild_encounters() -> tuple[set[str], dict[str, list[str]], dict[str, list[str]]]:
    data = json.loads(WILD_ENCOUNTERS_JSON.read_text(encoding="utf-8"))
    present: set[str] = set()
    details: dict[str, set[str]] = defaultdict(set)
    maps: dict[str, set[str]] = defaultdict(set)

    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            map_name = encounter.get("map", "UNKNOWN_MAP")
            base_label = encounter.get("base_label", "")
            for encounter_type, payload in encounter.items():
                if not isinstance(payload, dict) or "mons" not in payload:
                    continue
                for mon in payload.get("mons", []):
                    species_constant = mon.get("species")
                    if not species_constant:
                        continue
                    present.add(species_constant)
                    location = f"{map_name} [{encounter_type}]"
                    if base_label:
                        location = f"{location} {base_label}"
                    details[species_constant].add(location)
                    maps[species_constant].add(format_map_name(map_name))

    return (
        present,
        {key: sorted(value) for key, value in details.items()},
        {key: sorted(value) for key, value in maps.items()},
    )


def strip_c_comments(text: str) -> str:
    return re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)


def parse_species_from_party_line(line: str, aliases: dict[str, int], id_to_constant: dict[int, str]) -> str | None:
    constant_match = re.search(r"\b(SPECIES_[A-Z0-9_]+)\b", line)
    if constant_match:
        return constant_match.group(1)

    candidates = [line]
    paren_matches = re.findall(r"\(([^()]*)\)", line)
    for match in paren_matches:
        if match not in {"M", "F"}:
            candidates.insert(0, match)

    stripped = line.split("@", 1)[0].strip()
    stripped = re.sub(r"\s+\((M|F)\)\s*$", "", stripped)
    candidates.append(stripped)

    for candidate in candidates:
        species_id = aliases.get(normalize_token(candidate))
        if species_id is not None:
            return id_to_constant[species_id]

    return None


def parse_trainers_party(
    aliases: dict[str, int],
    id_to_constant: dict[int, str],
) -> tuple[set[str], dict[str, list[str]]]:
    content = strip_c_comments(TRAINERS_PARTY.read_text(encoding="utf-8"))
    present: set[str] = set()
    details: dict[str, set[str]] = defaultdict(set)

    current_trainer_id: str | None = None
    current_trainer_name: str | None = None

    for raw_line in content.splitlines():
        line = raw_line.strip()
        if not line:
            continue

        header_match = TRAINER_HEADER_RE.match(line)
        if header_match:
            current_trainer_id = header_match.group(1)
            current_trainer_name = None
            continue

        if current_trainer_id is None:
            continue

        if line.startswith("Name:"):
            current_trainer_name = line.partition(":")[2].strip()
            continue

        if line.startswith(TRAINER_METADATA_PREFIXES) or line.startswith(POKEMON_FIELD_PREFIXES) or line.startswith("- "):
            continue

        species_constant = parse_species_from_party_line(line, aliases, id_to_constant)
        if not species_constant:
            continue

        present.add(species_constant)
        trainer_label = current_trainer_id
        if current_trainer_name:
            trainer_label = f"{current_trainer_name} ({current_trainer_id})"
        details[species_constant].add(trainer_label)

    return present, {key: sorted(value) for key, value in details.items()}


def build_report(output_path: Path) -> None:
    id_to_constant, constant_to_id = parse_species_constants()
    enabled_entries = parse_enabled_species(id_to_constant)
    aliases = build_alias_map(enabled_entries, constant_to_id)
    icon_source_map = parse_icon_symbol_to_source_path()
    species_to_family = parse_species_to_family()
    config_macros = parse_species_enabled_macros()
    icon_output_dir = output_path.with_suffix("").with_name(output_path.stem + "_icons")

    target_entries = [
        entry
        for _, entry in sorted(enabled_entries.items())
        if not entry.excluded
    ]
    enabled_constants = {entry.constant for entry in target_entries}

    all_wild_present, all_wild_details, all_wild_maps = parse_wild_encounters()
    all_trainer_present, all_trainer_details = parse_trainers_party(aliases, id_to_constant)
    wild_present = all_wild_present & enabled_constants
    trainer_present = all_trainer_present & enabled_constants
    wild_details = {key: value for key, value in all_wild_details.items() if key in enabled_constants}
    wild_maps = {key: value for key, value in all_wild_maps.items() if key in enabled_constants}
    trainer_details = {key: value for key, value in all_trainer_details.items() if key in enabled_constants}

    disabled_families = {
        macro
        for macro in set(species_to_family.values())
        if resolve_config_bool(macro, config_macros) is False
    }
    disabled_referenced_constants = sorted(
        (all_wild_present | all_trainer_present) - {"SPECIES_NONE", "SPECIES_EGG"},
        key=lambda constant: constant_to_id.get(constant, 999999),
    )
    disabled_referenced_constants = [
        constant
        for constant in disabled_referenced_constants
        if species_to_family.get(constant) in disabled_families
    ]

    def format_species_constant(constant: str) -> str:
        return constant.removeprefix("SPECIES_").replace("_", " ").title()

    def pack_disabled_reference(constant: str) -> dict[str, object]:
        enabled_entry = enabled_entries.get(constant_to_id.get(constant, -1))
        wild_locations = all_wild_details.get(constant, [])
        trainer_list = all_trainer_details.get(constant, [])
        if constant in all_wild_present and constant in all_trainer_present:
            reference_state = "both"
        elif constant in all_wild_present:
            reference_state = "wild"
        else:
            reference_state = "trainer"

        return {
            "id": constant_to_id.get(constant, 999999),
            "constant": constant,
            "name": enabled_entry.display_name if enabled_entry else format_species_constant(constant),
            "family": species_to_family.get(constant, "UNKNOWN_FAMILY"),
            "referenceState": reference_state,
            "inWild": constant in all_wild_present,
            "inTrainerParties": constant in all_trainer_present,
            "wildLocations": wild_locations,
            "wildMaps": all_wild_maps.get(constant, []),
            "trainerParties": trainer_list,
        }

    def pack_species(entry: SpeciesEntry) -> dict[str, object]:
        wild_locations = wild_details.get(entry.constant, [])
        wild_map_names = wild_maps.get(entry.constant, [])
        trainer_list = trainer_details.get(entry.constant, [])
        icon_path = None
        icon_symbol = guess_icon_symbol(entry, icon_source_map)
        if icon_symbol:
            relative_icon_path = Path("tools") / icon_output_dir.name / f"{entry.constant.lower()}.png"
            process_icon(icon_source_map[icon_symbol], REPO_ROOT / relative_icon_path)
            icon_path = f"{icon_output_dir.name}/{entry.constant.lower()}.png"

        if entry.constant in wild_present and entry.constant in trainer_present:
            coverage_state = "both"
        elif entry.constant in wild_present:
            coverage_state = "wild"
        elif entry.constant in trainer_present:
            coverage_state = "trainer"
        else:
            coverage_state = "missing"

        family = species_to_family.get(entry.constant, entry.constant)

        return {
            "id": entry.species_id,
            "constant": entry.constant,
            "name": entry.display_name,
            "inWild": entry.constant in wild_present,
            "inTrainerParties": entry.constant in trainer_present,
            "wildLocations": wild_locations,
            "wildMaps": wild_map_names,
            "trainerParties": trainer_list,
            "flags": sorted(entry.flags),
            "iconPath": icon_path,
            "coverageState": coverage_state,
            "hideFromNotDistributed": entry.constant in NOT_DISTRIBUTED_BLACKLIST,
            "family": family,
            "types": [format_type_name(entry.types[0]), format_type_name(entry.types[1])],
        }

    species_payload = [pack_species(entry) for entry in target_entries]

    family_species: dict[str, list[dict[str, object]]] = defaultdict(list)
    for species in species_payload:
        family_species[str(species["family"])].append(species)

    family_rank = {"both": 0, "wild": 1, "trainer": 2, "missing": 3}
    family_representatives: dict[str, str] = {}
    family_is_distributed: dict[str, bool] = {}

    for family, members in family_species.items():
        ordered = sorted(
            members,
            key=lambda species: (
                family_rank[str(species["coverageState"])],
                str(species["name"]).lower(),
                int(species["id"]),
            ),
        )
        family_representatives[family] = str(ordered[0]["constant"])
        family_is_distributed[family] = any(species["coverageState"] != "missing" for species in members)

    for species in species_payload:
        family = str(species["family"])
        species["isFamilyRepresentative"] = species["constant"] == family_representatives[family]
        species["familyDistributed"] = family_is_distributed[family]
        species["familyRepresentativeConstant"] = family_representatives[family]
    counts = {
        "eligibleSpecies": len(species_payload),
        "wildCovered": sum(1 for species in species_payload if species["inWild"]),
        "trainerCovered": sum(1 for species in species_payload if species["inTrainerParties"]),
        "coveredAnywhere": sum(
            1 for species in species_payload if species["inWild"] or species["inTrainerParties"]
        ),
        "disabledReferenced": len(disabled_referenced_constants),
        "disabledReferencedWild": sum(1 for constant in disabled_referenced_constants if constant in all_wild_present),
        "disabledReferencedTrainer": sum(1 for constant in disabled_referenced_constants if constant in all_trainer_present),
    }

    metadata = {
        "generatedAtUtc": datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M:%S UTC"),
        "sources": [
            str(path.relative_to(REPO_ROOT))
            for path in (SPECIES_H, SPECIES_ENABLED_CONFIG, WILD_ENCOUNTERS_JSON, TRAINERS_PARTY)
        ],
        "excludedReason": "Legendary, mythical, restricted legendary, and temporary battle-only forms are excluded from the target pool.",
        "typeOrder": [
            "Normal", "Fire", "Water", "Electric", "Grass", "Ice",
            "Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug",
            "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy",
        ],
    }

    disabled_references_payload = [
        pack_disabled_reference(constant)
        for constant in disabled_referenced_constants
    ]

    payload = {
        "counts": counts,
        "metadata": metadata,
        "species": species_payload,
        "disabledReferences": disabled_references_payload,
    }

    html = f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Species Distribution Report</title>
  <style>
    :root {{
      --bg: #f4efe6;
      --panel: rgba(255, 251, 245, 0.92);
      --panel-strong: #fffdf9;
      --text: #1d2430;
      --muted: #5d6776;
      --border: rgba(55, 66, 88, 0.16);
      --shadow: 0 16px 40px rgba(33, 43, 62, 0.12);
      --accent: #d15f3c;
      --accent-soft: rgba(209, 95, 60, 0.12);
      --accent-2: #1e7c69;
      --missing: #9e2f2f;
      --covered: #226a4c;
      --chip: #efe6d7;
      --tab: #efe5d9;
      --both: #226a4c;
      --either: #9c6c00;
      --missing-text: #a02e2e;
    }}

    body.dark {{
      --bg: #10161f;
      --panel: rgba(23, 31, 43, 0.92);
      --panel-strong: #182131;
      --text: #eef3fb;
      --muted: #a2b1c6;
      --border: rgba(170, 190, 220, 0.16);
      --shadow: 0 18px 44px rgba(0, 0, 0, 0.34);
      --accent: #f08d62;
      --accent-soft: rgba(240, 141, 98, 0.14);
      --accent-2: #58b9a3;
      --missing: #ff8a8a;
      --covered: #74d1a0;
      --chip: #243144;
      --tab: #243144;
      --both: #74d1a0;
      --either: #ffd36d;
      --missing-text: #ff9f9f;
    }}

    * {{ box-sizing: border-box; }}
    body {{
      margin: 0;
      font-family: "Trebuchet MS", "Segoe UI", sans-serif;
      color: var(--text);
      background:
        radial-gradient(circle at top left, rgba(209, 95, 60, 0.22), transparent 28%),
        radial-gradient(circle at top right, rgba(30, 124, 105, 0.16), transparent 30%),
        linear-gradient(180deg, #fbf7ef 0%, var(--bg) 58%, #ece4d8 100%);
      background-attachment: fixed;
      min-height: 100vh;
    }}

    body.dark {{
      background:
        radial-gradient(circle at top left, rgba(240, 141, 98, 0.14), transparent 28%),
        radial-gradient(circle at top right, rgba(88, 185, 163, 0.12), transparent 30%),
        linear-gradient(180deg, #0b1118 0%, var(--bg) 56%, #0a1017 100%);
    }}

    main {{
      width: min(1180px, calc(100% - 32px));
      margin: 32px auto 48px;
    }}

    .hero, .panel {{
      background: var(--panel);
      border: 1px solid var(--border);
      border-radius: 24px;
      box-shadow: var(--shadow);
      backdrop-filter: blur(6px);
    }}

    .hero {{
      padding: 28px;
      margin-bottom: 20px;
    }}

    h1 {{
      margin: 0 0 10px;
      font-size: clamp(2rem, 4vw, 3.6rem);
      line-height: 0.95;
      letter-spacing: -0.04em;
    }}

    .subtitle, .meta, .empty {{
      color: var(--muted);
    }}

    .summary {{
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(170px, 1fr));
      gap: 12px;
      margin-top: 22px;
    }}

    .card {{
      background: var(--panel-strong);
      border: 1px solid var(--border);
      border-radius: 18px;
      padding: 16px;
    }}

    .card .label {{
      font-size: 0.82rem;
      text-transform: uppercase;
      letter-spacing: 0.08em;
      color: var(--muted);
    }}

    .card .value {{
      font-size: 2rem;
      font-weight: 700;
      margin-top: 4px;
    }}

    .controls {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin: 20px 0 14px;
    }}

    .state-filters {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin: 0 0 16px;
    }}

    .tabs {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin-bottom: 16px;
    }}

    button, input {{
      font: inherit;
    }}

    .tab {{
      border: 1px solid transparent;
      background: var(--tab);
      color: var(--text);
      padding: 11px 16px;
      border-radius: 999px;
      cursor: pointer;
      transition: 160ms ease;
    }}

    .tab.active {{
      background: var(--accent);
      color: white;
      box-shadow: 0 12px 22px rgba(209, 95, 60, 0.22);
    }}

    .state-filter {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      color: var(--text);
      padding: 10px 14px;
      border-radius: 999px;
      cursor: pointer;
      transition: 160ms ease;
    }}

    .state-filter.active {{
      background: #2c3545;
      color: white;
      border-color: #2c3545;
    }}

    .gallery-options {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin: 0 0 16px;
    }}

    .gallery-option {{
      display: inline-flex;
      align-items: center;
      gap: 8px;
      border: 1px solid var(--border);
      background: var(--panel-strong);
      color: var(--text);
      padding: 10px 14px;
      border-radius: 999px;
      cursor: pointer;
      user-select: none;
      -webkit-tap-highlight-color: transparent;
      outline: none;
      box-shadow: none;
      transition: border-color 160ms ease;
    }}

    .gallery-option input {{
      margin: 0;
    }}

    .type-filters {{
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin: 0 0 16px;
    }}

    .type-filter {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      color: var(--text);
      padding: 10px 14px;
      border-radius: 999px;
      cursor: pointer;
      transition: 160ms ease;
    }}

    .type-filter.active {{
      background: var(--accent-2);
      color: white;
      border-color: var(--accent-2);
    }}

    .gallery-option:hover,
    .gallery-option:active,
    .gallery-option:focus,
    .gallery-option:focus-within {{
      background: var(--panel-strong);
      color: var(--text);
      outline: none;
      box-shadow: none;
    }}

    .search {{
      flex: 1 1 280px;
      min-width: 220px;
      padding: 12px 14px;
      border-radius: 14px;
      border: 1px solid var(--border);
      background: var(--panel-strong);
    }}

    .theme-toggle {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      color: var(--text);
      padding: 12px 14px;
      border-radius: 14px;
      cursor: pointer;
    }}

    .notes-button {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      color: var(--text);
      padding: 12px 14px;
      border-radius: 14px;
      cursor: pointer;
    }}

    .notes-status {{
      width: 100%;
      color: var(--muted);
      font-size: 0.88rem;
      margin-top: -2px;
    }}

    .panel {{
      padding: 20px;
    }}

    .result-count {{
      margin-bottom: 14px;
      color: var(--muted);
    }}

    .species-grid {{
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(260px, 1fr));
      gap: 14px;
    }}

    .species-card {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      border-radius: 18px;
      padding: 16px;
    }}

    .species-card h2 {{
      margin: 0;
      font-size: 1.15rem;
      line-height: 1.15;
    }}

    .constant {{
      margin-top: 6px;
      font-family: "Courier New", monospace;
      font-size: 0.83rem;
      color: var(--muted);
      word-break: break-word;
    }}

    .chips {{
      display: flex;
      flex-wrap: wrap;
      gap: 8px;
      margin: 12px 0;
    }}

    .chip {{
      display: inline-flex;
      align-items: center;
      gap: 6px;
      padding: 7px 10px;
      border-radius: 999px;
      background: var(--chip);
      font-size: 0.84rem;
    }}

    .chip.covered {{
      color: var(--covered);
      background: rgba(34, 106, 76, 0.12);
    }}

    .chip.missing {{
      color: var(--missing);
      background: rgba(158, 47, 47, 0.12);
    }}

    .detail-title {{
      margin-top: 14px;
      margin-bottom: 6px;
      font-weight: 700;
      font-size: 0.88rem;
    }}

    .detail-list {{
      margin: 0;
      padding-left: 18px;
      color: var(--muted);
      font-size: 0.92rem;
      line-height: 1.4;
      max-height: 10.5rem;
      overflow: auto;
    }}

    .footer {{
      margin-top: 18px;
      font-size: 0.9rem;
      color: var(--muted);
    }}

    .gallery-grid {{
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
      gap: 12px;
    }}

    .gallery-card {{
      border: 1px solid var(--border);
      background: var(--panel-strong);
      border-radius: 18px;
      padding: 12px 10px 14px;
      display: flex;
      flex-direction: column;
      align-items: center;
      text-align: center;
      min-height: 148px;
      cursor: pointer;
    }}

    .gallery-card:hover {{
      border-color: var(--accent);
    }}

    .gallery-icon {{
      width: 32px;
      height: 32px;
      image-rendering: pixelated;
      margin-top: 2px;
      margin-bottom: 10px;
    }}

    .gallery-name {{
      font-weight: 700;
      line-height: 1.15;
    }}

    .gallery-name.both {{
      color: var(--both);
    }}

    .gallery-name.wild,
    .gallery-name.trainer {{
      color: var(--either);
    }}

    .gallery-name.missing {{
      color: var(--missing-text);
    }}

    .gallery-subtitle {{
      margin-top: 6px;
      color: var(--muted);
      font-size: 0.8rem;
    }}

    .gallery-note {{
      margin-top: 8px;
      padding: 8px 10px;
      width: 100%;
      border-radius: 12px;
      background: var(--chip);
      color: var(--text);
      font-size: 0.78rem;
      line-height: 1.3;
      text-align: left;
      word-break: break-word;
    }}

    .gallery-note.empty {{
      color: var(--muted);
      font-style: italic;
    }}

    @media (max-width: 720px) {{
      main {{
        width: min(100% - 20px, 1180px);
        margin: 16px auto 28px;
      }}

      .hero, .panel {{
        border-radius: 20px;
      }}

      .hero {{
        padding: 22px;
      }}

      .panel {{
        padding: 16px;
      }}
    }}
  </style>
</head>
<body>
  <main>
    <section class="hero">
      <div class="subtitle">Developer dashboard for encounter and trainer-party coverage</div>
      <h1>Species Distribution Report</h1>
      <div class="meta" id="meta"></div>
      <div class="summary" id="summary"></div>
    </section>

    <div class="controls">
      <input id="search" class="search" type="search" placeholder="Filter by species name or constant">
      <button id="themeToggle" class="theme-toggle" type="button">Dark Mode</button>
      <button id="loadNotesButton" class="notes-button" type="button">Load Notes File</button>
      <button id="saveNotesButton" class="notes-button" type="button">Save Notes File</button>
      <div id="notesStatus" class="notes-status"></div>
    </div>

    <div class="tabs" id="tabs"></div>

    <section class="panel">
      <div class="result-count" id="resultCount"></div>
      <div class="state-filters" id="stateFilters"></div>
      <div class="gallery-options" id="galleryOptions"></div>
      <div class="type-filters" id="typeFilters"></div>
      <div class="species-grid" id="speciesGrid"></div>
      <div class="empty" id="emptyState" hidden>No species match the current view.</div>
      <div class="footer" id="footer"></div>
    </section>
  </main>

  <script>
    const DATA = {json.dumps(payload, ensure_ascii=False)};

    const views = [
      {{
        key: "missingWild",
        label: "Missing In Wild",
        filter: species => !species.inWild && !species.hideFromNotDistributed,
        layout: "cards",
      }},
      {{
        key: "missingTrainer",
        label: "Missing In Trainer Parties",
        filter: species => !species.inTrainerParties && !species.hideFromNotDistributed,
        layout: "cards",
      }},
      {{
        key: "missingEverywhere",
        label: "Missing Everywhere",
        filter: species => !species.inWild && !species.inTrainerParties && !species.hideFromNotDistributed,
        layout: "cards",
      }},
      {{
        key: "wildOnly",
        label: "Wild Only",
        filter: species => species.inWild && !species.inTrainerParties,
        layout: "cards",
      }},
      {{
        key: "trainerOnly",
        label: "Trainer Only",
        filter: species => !species.inWild && species.inTrainerParties,
        layout: "cards",
      }},
      {{
        key: "disabledReferences",
        label: "Disabled Still Referenced",
        filter: () => true,
        layout: "disabledReferences",
      }},
      {{
        key: "coveredAnywhere",
        label: "Covered Anywhere",
        filter: species => species.inWild || species.inTrainerParties,
        layout: "cards",
      }},
      {{
        key: "all",
        label: "All Eligible Species",
        filter: () => true,
        layout: "cards",
      }},
      {{
        key: "gallery",
        label: "Icon Gallery",
        filter: () => true,
        layout: "gallery",
      }},
    ];

    const summary = document.getElementById("summary");
    const meta = document.getElementById("meta");
    const footer = document.getElementById("footer");
    const tabs = document.getElementById("tabs");
    const search = document.getElementById("search");
    const themeToggle = document.getElementById("themeToggle");
    const loadNotesButton = document.getElementById("loadNotesButton");
    const saveNotesButton = document.getElementById("saveNotesButton");
    const notesStatus = document.getElementById("notesStatus");
    const resultCount = document.getElementById("resultCount");
    const stateFilters = document.getElementById("stateFilters");
    const galleryOptions = document.getElementById("galleryOptions");
    const typeFilters = document.getElementById("typeFilters");
    const speciesGrid = document.getElementById("speciesGrid");
    const emptyState = document.getElementById("emptyState");

    let currentView = "missingWild";
    let activeDistributionMode = null;
    const activeTypes = new Set();
    let familyRepresentativesOnly = false;
    let hideDistributedFamilies = false;
    const notesStorageKey = "speciesDistributionNotes";
    const speciesNotes = JSON.parse(localStorage.getItem(notesStorageKey) || "{{}}");
    let notesFileHandle = null;
    const stateFilterOptions = [
      {{ key: "missing", label: "Not Distributed" }},
      {{ key: "both", label: "Distributed" }},
      {{ key: "wild", label: "Wild Only" }},
      {{ key: "trainer", label: "Trainer Only" }},
    ];
      const typeFilterOptions = DATA.metadata.typeOrder.filter(type =>
      DATA.species.some(species => species.types.includes(type))
    );

    function saveSpeciesNotes() {{
      localStorage.setItem(notesStorageKey, JSON.stringify(speciesNotes));
    }}

    function updateNotesStatus(message) {{
      notesStatus.textContent = message;
    }}

    function sanitizeNotesObject(value) {{
      if (!value || typeof value !== "object" || Array.isArray(value))
        return {{}};

      const cleaned = {{}};
      for (const [key, note] of Object.entries(value)) {{
        if (typeof note === "string" && note.trim())
          cleaned[key] = note.trim();
      }}
      return cleaned;
    }}

    function replaceSpeciesNotes(nextNotes) {{
      for (const key of Object.keys(speciesNotes))
        delete speciesNotes[key];
      Object.assign(speciesNotes, sanitizeNotesObject(nextNotes));
      saveSpeciesNotes();
      renderSpecies();
    }}

    function buildNotesPayload() {{
      return {{
        version: 1,
        savedAt: new Date().toISOString(),
        notes: sanitizeNotesObject(speciesNotes),
      }};
    }}

    async function writeNotesToHandle(handle) {{
      const writable = await handle.createWritable();
      await writable.write(JSON.stringify(buildNotesPayload(), null, 2));
      await writable.close();
      notesFileHandle = handle;
      updateNotesStatus(`Notes file: ${{handle.name}}`);
    }}

    function downloadNotesFile() {{
      const blob = new Blob([JSON.stringify(buildNotesPayload(), null, 2)], {{ type: "application/json" }});
      const url = URL.createObjectURL(blob);
      const anchor = document.createElement("a");
      anchor.href = url;
      anchor.download = "species_distribution_notes.json";
      anchor.click();
      URL.revokeObjectURL(url);
      updateNotesStatus("Notes downloaded as species_distribution_notes.json");
    }}

    async function saveNotesFile() {{
      try {{
        if ("showSaveFilePicker" in window) {{
          if (!notesFileHandle) {{
            notesFileHandle = await window.showSaveFilePicker({{
              suggestedName: "species_distribution_notes.json",
              types: [{{
                description: "JSON files",
                accept: {{ "application/json": [".json"] }},
              }}],
            }});
          }}
          await writeNotesToHandle(notesFileHandle);
        }} else {{
          downloadNotesFile();
        }}
      }} catch (error) {{
        if (error && error.name === "AbortError")
          return;
        updateNotesStatus(`Could not save notes file: ${{error.message || error}}`);
      }}
    }}

    async function autosaveNotesIfPossible() {{
      try {{
        if (notesFileHandle)
          await writeNotesToHandle(notesFileHandle);
        else
          updateNotesStatus("Notes saved in browser cache. Use Save Notes File to persist to disk.");
      }} catch (error) {{
        updateNotesStatus(`Notes changed, but file save failed: ${{error.message || error}}`);
      }}
    }}

    async function loadNotesFile() {{
      try {{
        if ("showOpenFilePicker" in window) {{
          const [handle] = await window.showOpenFilePicker({{
            multiple: false,
            types: [{{
              description: "JSON files",
              accept: {{ "application/json": [".json"] }},
            }}],
          }});
          const file = await handle.getFile();
          const parsed = JSON.parse(await file.text());
          replaceSpeciesNotes(parsed.notes ?? parsed);
          notesFileHandle = handle;
          updateNotesStatus(`Notes file: ${{handle.name}}`);
          return;
        }}

        const picker = document.createElement("input");
        picker.type = "file";
        picker.accept = ".json,application/json";
        picker.addEventListener("change", async () => {{
          const file = picker.files && picker.files[0];
          if (!file)
            return;
          try {{
            const parsed = JSON.parse(await file.text());
            replaceSpeciesNotes(parsed.notes ?? parsed);
            updateNotesStatus(`Loaded notes from ${{file.name}}`);
          }} catch (error) {{
            updateNotesStatus(`Could not read notes file: ${{error.message || error}}`);
          }}
        }}, {{ once: true }});
        picker.click();
      }} catch (error) {{
        if (error && error.name === "AbortError")
          return;
        updateNotesStatus(`Could not load notes file: ${{error.message || error}}`);
      }}
    }}

    function getNotePreview(value) {{
      const note = (value || "").trim();
      if (!note)
        return "Click to add a note";
      return note.length > 90 ? `${{note.slice(0, 87)}}...` : note;
    }}

    function applyTheme(theme) {{
      document.body.classList.toggle("dark", theme === "dark");
      themeToggle.textContent = theme === "dark" ? "Light Mode" : "Dark Mode";
    }}

    function percent(value) {{
      if (!DATA.counts.eligibleSpecies) return "0%";
      return `${{Math.round((value / DATA.counts.eligibleSpecies) * 100)}}%`;
    }}

    function renderSummary() {{
      const cards = [
        ["Eligible Species", DATA.counts.eligibleSpecies],
        ["Wild Coverage", `${{DATA.counts.wildCovered}} (${{percent(DATA.counts.wildCovered)}})`],
        ["Trainer Coverage", `${{DATA.counts.trainerCovered}} (${{percent(DATA.counts.trainerCovered)}})`],
        ["Covered Anywhere", `${{DATA.counts.coveredAnywhere}} (${{percent(DATA.counts.coveredAnywhere)}})`],
        ["Disabled References", DATA.counts.disabledReferenced],
      ];
      summary.innerHTML = cards.map(([label, value]) => `
        <article class="card">
          <div class="label">${{label}}</div>
          <div class="value">${{value}}</div>
        </article>
      `).join("");
      meta.textContent = `Generated ${{DATA.metadata.generatedAtUtc}}`;
      footer.textContent = `${{DATA.metadata.excludedReason}} Sources: ${{DATA.metadata.sources.join(", ")}}.`;
    }}

    function renderTabs() {{
      tabs.innerHTML = views.map(view => `
        <button class="tab${{view.key === currentView ? " active" : ""}}" data-view="${{view.key}}">
          ${{view.label}}
        </button>
      `).join("");

      for (const button of tabs.querySelectorAll("[data-view]")) {{
        button.addEventListener("click", () => {{
          currentView = button.dataset.view;
          renderStateFilters();
          renderGalleryOptions();
          renderTypeFilters();
          renderSpecies();
          renderTabs();
        }});
      }}
    }}

    function renderStateFilters() {{
      const view = views.find(candidate => candidate.key === currentView);
      stateFilters.hidden = view.layout !== "gallery";
      if (view.layout !== "gallery") {{
        stateFilters.innerHTML = "";
        return;
      }}

      stateFilters.innerHTML = stateFilterOptions.map(option => `
        <button
          class="state-filter${{activeDistributionMode === option.key ? " active" : ""}}"
          data-state="${{option.key}}"
        >
          ${{option.label}}
        </button>
      `).join("");

      for (const button of stateFilters.querySelectorAll("[data-state]")) {{
        button.addEventListener("click", () => {{
          const key = button.dataset.state;
          activeDistributionMode = activeDistributionMode === key ? null : key;
          renderStateFilters();
          renderSpecies();
        }});
      }}
    }}

    function renderGalleryOptions() {{
      const view = views.find(candidate => candidate.key === currentView);
      galleryOptions.hidden = view.layout !== "gallery";
      if (view.layout !== "gallery") {{
        galleryOptions.innerHTML = "";
        return;
      }}

      galleryOptions.innerHTML = `
        <label class="gallery-option">
          <input id="familyRepresentativesOnly" type="checkbox" ${{familyRepresentativesOnly ? "checked" : ""}}>
          Show Family Representatives Only
        </label>
        <label class="gallery-option">
          <input id="hideDistributedFamilies" type="checkbox" ${{hideDistributedFamilies ? "checked" : ""}}>
          Hide Already Covered Families
        </label>
      `;

      document.getElementById("familyRepresentativesOnly").addEventListener("change", event => {{
        familyRepresentativesOnly = event.target.checked;
        renderSpecies();
      }});

      document.getElementById("hideDistributedFamilies").addEventListener("change", event => {{
        hideDistributedFamilies = event.target.checked;
        renderSpecies();
      }});
    }}

    function renderTypeFilters() {{
      const view = views.find(candidate => candidate.key === currentView);
      typeFilters.hidden = view.layout !== "gallery";
      if (view.layout !== "gallery") {{
        typeFilters.innerHTML = "";
        return;
      }}

      typeFilters.innerHTML = [
        `<button class="type-filter${{activeTypes.size === 0 ? " active" : ""}}" data-clear-types="true">All Types</button>`,
        ...typeFilterOptions.map(type => `
          <button class="type-filter${{activeTypes.has(type) ? " active" : ""}}" data-type="${{type}}">
            ${{type}}
          </button>
        `),
      ].join("");

      const clearButton = typeFilters.querySelector("[data-clear-types]");
      clearButton.addEventListener("click", () => {{
        activeTypes.clear();
        renderTypeFilters();
        renderSpecies();
      }});

      for (const button of typeFilters.querySelectorAll("[data-type]")) {{
        button.addEventListener("click", () => {{
          const type = button.dataset.type;
          if (activeTypes.has(type))
            activeTypes.delete(type);
          else
            activeTypes.add(type);

          renderTypeFilters();
          renderSpecies();
        }});
      }}
    }}

    function speciesMatchesSearch(species, query) {{
      if (!query) return true;
      const haystack = `${{species.name}} ${{species.constant}} ${{species.family || ""}}`.toLowerCase();
      return haystack.includes(query);
    }}

    function renderSpecies() {{
      const view = views.find(candidate => candidate.key === currentView);
      const query = search.value.trim().toLowerCase();
      if (view.layout === "disabledReferences") {{
        const filtered = DATA.disabledReferences
          .filter(species => speciesMatchesSearch(species, query))
          .sort((a, b) => {{
            if (a.referenceState !== b.referenceState)
              return a.referenceState.localeCompare(b.referenceState);
            return a.id - b.id;
          }});

        resultCount.textContent = `${{filtered.length}} disabled species referenced by wild encounters or trainer parties`;
        emptyState.hidden = filtered.length !== 0;
        speciesGrid.className = "species-grid";
        speciesGrid.innerHTML = filtered.map(species => {{
          const wildItems = species.wildLocations.length
            ? `<ul class="detail-list">${{species.wildLocations.map(item => `<li>${{item}}</li>`).join("")}}</ul>`
            : `<div class="empty">No wild encounter entries.</div>`;
          const trainerItems = species.trainerParties.length
            ? `<ul class="detail-list">${{species.trainerParties.map(item => `<li>${{item}}</li>`).join("")}}</ul>`
            : `<div class="empty">No trainer-party entries.</div>`;

          return `
            <article class="species-card">
              <h2>${{species.name}}</h2>
              <div class="constant">${{species.constant}}</div>
              <div class="constant">${{species.family}}</div>
              <div class="chips">
                <span class="chip ${{species.inWild ? "missing" : "covered"}}">
                  ${{species.inWild ? "Still in wild" : "Not in wild"}}
                </span>
                <span class="chip ${{species.inTrainerParties ? "missing" : "covered"}}">
                  ${{species.inTrainerParties ? "Still in trainer parties" : "Not in trainer parties"}}
                </span>
              </div>
              <div class="detail-title">Wild locations</div>
              ${{wildItems}}
              <div class="detail-title">Trainer parties</div>
              ${{trainerItems}}
            </article>
          `;
        }}).join("");
        return;
      }}

      const filtered = DATA.species
        .filter(view.filter)
        .filter(species => view.layout !== "gallery" || (
          activeDistributionMode !== null &&
          species.coverageState === activeDistributionMode &&
          (activeDistributionMode !== "missing" || !species.hideFromNotDistributed)
        ))
        .filter(species => view.layout !== "gallery" || activeTypes.size === 0 || species.types.some(type => activeTypes.has(type)))
        .filter(species => view.layout !== "gallery" || !familyRepresentativesOnly || species.isFamilyRepresentative)
        .filter(species => view.layout !== "gallery" || !hideDistributedFamilies || !species.familyDistributed)
        .filter(species => speciesMatchesSearch(species, query))
        .sort((a, b) => {{
          if (view.layout === "gallery")
            return a.id - b.id;
          return a.name.localeCompare(b.name);
        }});

      resultCount.textContent = `${{filtered.length}} species in this view`;
      emptyState.hidden = filtered.length !== 0;
      speciesGrid.className = view.layout === "gallery" ? "gallery-grid" : "species-grid";

      if (view.layout === "gallery") {{
        speciesGrid.innerHTML = filtered.map(species => {{
          const icon = species.iconPath
            ? `<img class="gallery-icon" src="${{species.iconPath}}" alt="">`
            : `<div class="gallery-icon"></div>`;

          let subtitle = "Not distributed";
          if (species.coverageState === "both")
            subtitle = "Wild + trainer";
          else if (species.coverageState === "wild")
            subtitle = "Wild only";
          else if (species.coverageState === "trainer")
            subtitle = "Trainer only";

          const familyNote = species.familyDistributed
            ? `Family covered by ${{species.familyRepresentativeConstant === species.constant ? "this species" : species.familyRepresentativeConstant}}`
            : "Family not yet covered";
          let mapNote = "No wild map";
          if (species.wildMaps.length === 1)
            mapNote = `Wild map: ${{species.wildMaps[0]}}`;
          else if (species.wildMaps.length > 1)
            mapNote = `Wild maps: ${{species.wildMaps.join(", ")}}`;
          const note = speciesNotes[species.constant] || "";
          const noteClass = note.trim() ? "gallery-note" : "gallery-note empty";

          return `
            <article class="gallery-card" data-species="${{species.constant}}">
              ${{icon}}
              <div class="gallery-name ${{species.coverageState}}">${{species.name}}</div>
              <div class="gallery-subtitle">${{subtitle}}</div>
              <div class="gallery-subtitle">${{mapNote}}</div>
              <div class="gallery-subtitle">${{familyNote}}</div>
              <div class="${{noteClass}}">${{getNotePreview(note)}}</div>
            </article>
          `;
        }}).join("");

        for (const card of speciesGrid.querySelectorAll("[data-species]")) {{
          card.addEventListener("click", () => {{
            const speciesConstant = card.dataset.species;
            const currentNote = speciesNotes[speciesConstant] || "";
            const nextNote = window.prompt(
              `Add a note for ${{speciesConstant}}. Leave blank to clear it.`,
              currentNote,
            );

            if (nextNote === null)
              return;

            if (nextNote.trim())
              speciesNotes[speciesConstant] = nextNote.trim();
            else
              delete speciesNotes[speciesConstant];

            saveSpeciesNotes();
            autosaveNotesIfPossible();
            renderSpecies();
          }});
        }}
        return;
      }}

      speciesGrid.innerHTML = filtered.map(species => {{
        const wildItems = species.wildLocations.length
          ? `<ul class="detail-list">${{species.wildLocations.map(item => `<li>${{item}}</li>`).join("")}}</ul>`
          : `<div class="empty">No wild encounter entries.</div>`;
        const trainerItems = species.trainerParties.length
          ? `<ul class="detail-list">${{species.trainerParties.map(item => `<li>${{item}}</li>`).join("")}}</ul>`
          : `<div class="empty">No trainer-party entries.</div>`;

        return `
          <article class="species-card">
            <h2>${{species.name}}</h2>
            <div class="constant">${{species.constant}}</div>
            <div class="chips">
              <span class="chip ${{species.inWild ? "covered" : "missing"}}">
                ${{species.inWild ? "In wild" : "Missing in wild"}}
              </span>
              <span class="chip ${{species.inTrainerParties ? "covered" : "missing"}}">
                ${{species.inTrainerParties ? "In trainer parties" : "Missing in trainer parties"}}
              </span>
            </div>
            <div class="detail-title">Wild locations</div>
            ${{wildItems}}
            <div class="detail-title">Trainer parties</div>
            ${{trainerItems}}
          </article>
        `;
      }}).join("");
    }}

    search.addEventListener("input", renderSpecies);
    themeToggle.addEventListener("click", () => {{
      const nextTheme = document.body.classList.contains("dark") ? "light" : "dark";
      localStorage.setItem("speciesDistributionTheme", nextTheme);
      applyTheme(nextTheme);
    }});
    loadNotesButton.addEventListener("click", loadNotesFile);
    saveNotesButton.addEventListener("click", saveNotesFile);

    applyTheme(localStorage.getItem("speciesDistributionTheme") || "light");
    updateNotesStatus("Notes saved in browser cache. Use Load/Save Notes File to persist to disk.");
    renderSummary();
    renderTabs();
    renderStateFilters();
    renderGalleryOptions();
    renderTypeFilters();
    renderSpecies();
  </script>
</body>
</html>
"""

    output_path.write_text(textwrap.dedent(html), encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate a standalone species distribution HTML report.")
    parser.add_argument(
        "-o",
        "--output",
        default=str(REPO_ROOT / "tools/species_distribution_report.html"),
        help="Output HTML file path.",
    )
    args = parser.parse_args()
    output_path = Path(args.output)
    build_report(output_path)
    print(output_path)


if __name__ == "__main__":
    main()
