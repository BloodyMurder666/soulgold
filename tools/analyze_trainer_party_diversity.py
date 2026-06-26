#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT))

from tools.soulgold_docs.c_parser import (  # noqa: E402
    collect_strings,
    eval_int_expr,
    extract_balanced_call,
    extract_braced_constants,
    extract_field,
    extract_number,
    normalize_token,
    split_top_level_braces,
    split_top_level_commas,
    strip_c_comments,
)
from tools.soulgold_docs.constants import (  # noqa: E402
    EXCLUDED_TRAINER_MAP_GROUPS,
    EXCLUDED_TRAINER_MAP_NAMES,
    EXCLUDED_TRAINER_MAP_PREFIXES,
)
from tools.soulgold_docs.parsers.evolutions import parse_evolutions  # noqa: E402


SPECIES_H = REPO_ROOT / "include/constants/species.h"
SPECIES_INFO_H = REPO_ROOT / "src/data/pokemon/species_info.h"
SPECIES_INFO_DIR = REPO_ROOT / "src/data/pokemon/species_info"
TRAINERS_PARTY = REPO_ROOT / "src/data/trainers.party"
WILD_ENCOUNTERS_JSON = REPO_ROOT / "src/data/wild_encounters.json"
MAP_GROUPS_JSON = REPO_ROOT / "data/maps/map_groups.json"
DEFAULT_OUTPUT = REPO_ROOT / "tools/trainer_party_diversity_report.md"

SPECIES_DEFINE_RE = re.compile(r"^\s*#define\s+(SPECIES_[A-Z0-9_]+)\s+(\d+)\b")
ENTRY_START_RE = re.compile(r"^\s*\[(\d+)\]\s*=\s*$")
TRAINER_HEADER_RE = re.compile(r"^===\s*(TRAINER_[A-Z0-9_]+)\s*===\s*$")
SPECIES_ENTRY_RE = re.compile(r"\[\s*(SPECIES_[A-Z0-9_]+)\s*\]\s*=")
FAMILY_IF_RE = re.compile(r"^\s*#if\s+(P_FAMILY_[A-Z0-9_]+)\s*$")
ANY_IF_RE = re.compile(r"^\s*#(?:if|ifdef|ifndef)\b")
ENDIF_RE = re.compile(r"^\s*#endif\b")
TRUE_FLAG_RE = re.compile(r"^\s*\.(is[A-Za-z0-9_]+)\s*=\s*(?:TRUE|1)\b")

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
    "Difficulty:",
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

LEGENDARY_FLAGS = {
    "isRestrictedLegendary",
    "isSubLegendary",
    "isMythical",
}

EXCLUDED_FORM_FLAGS = {
    "isMegaEvolution",
    "isPrimalReversion",
    "isUltraBurst",
    "isGigantamax",
    "isTeraForm",
    "isTotem",
}

CLASS_TYPE_PREFERENCES = {
    "aromalady": {"TYPE_GRASS", "TYPE_POISON", "TYPE_FAIRY"},
    "battlegirl": {"TYPE_FIGHTING"},
    "beauty": {"TYPE_NORMAL", "TYPE_FAIRY", "TYPE_GRASS", "TYPE_WATER"},
    "biker": {"TYPE_POISON", "TYPE_DARK", "TYPE_FIGHTING", "TYPE_FIRE", "TYPE_STEEL"},
    "birdkeeper": {"TYPE_FLYING"},
    "blackbelt": {"TYPE_FIGHTING"},
    "bugcatcher": {"TYPE_BUG"},
    "bugmaniac": {"TYPE_BUG"},
    "burglar": {"TYPE_FIRE", "TYPE_POISON", "TYPE_DARK"},
    "camper": {"TYPE_NORMAL", "TYPE_FLYING", "TYPE_GROUND", "TYPE_BUG"},
    "dragon": {"TYPE_DRAGON"},
    "dragontamer": {"TYPE_DRAGON"},
    "elder": {"TYPE_PSYCHIC", "TYPE_GHOST", "TYPE_GRASS"},
    "engineer": {"TYPE_ELECTRIC", "TYPE_STEEL"},
    "expert": {"TYPE_FIGHTING", "TYPE_NORMAL", "TYPE_PSYCHIC"},
    "firebreather": {"TYPE_FIRE", "TYPE_POISON", "TYPE_DRAGON"},
    "fisherman": {"TYPE_WATER"},
    "guitarist": {"TYPE_ELECTRIC", "TYPE_STEEL"},
    "hexmaniac": {"TYPE_GHOST", "TYPE_PSYCHIC", "TYPE_DARK"},
    "hiker": {"TYPE_ROCK", "TYPE_GROUND", "TYPE_STEEL", "TYPE_FIGHTING"},
    "juggler": {"TYPE_PSYCHIC", "TYPE_GHOST", "TYPE_POISON", "TYPE_ELECTRIC"},
    "kimono": {"TYPE_PSYCHIC", "TYPE_FAIRY", "TYPE_GHOST"},
    "lass": {"TYPE_NORMAL", "TYPE_FAIRY", "TYPE_GRASS"},
    "picnicker": {"TYPE_NORMAL", "TYPE_GRASS", "TYPE_FAIRY", "TYPE_WATER"},
    "pokefan": {"TYPE_NORMAL", "TYPE_FAIRY", "TYPE_ELECTRIC"},
    "pokemaniac": {"TYPE_ROCK", "TYPE_GROUND", "TYPE_DRAGON", "TYPE_NORMAL"},
    "psychic": {"TYPE_PSYCHIC", "TYPE_GHOST"},
    "ruinmaniac": {"TYPE_ROCK", "TYPE_GROUND", "TYPE_STEEL"},
    "sage": {"TYPE_PSYCHIC", "TYPE_GHOST", "TYPE_GRASS"},
    "sailor": {"TYPE_WATER", "TYPE_FIGHTING"},
    "schoolkid": {"TYPE_NORMAL", "TYPE_ELECTRIC", "TYPE_PSYCHIC"},
    "supernerd": {"TYPE_ELECTRIC", "TYPE_STEEL", "TYPE_POISON", "TYPE_PSYCHIC"},
    "swimmer": {"TYPE_WATER"},
    "tuber": {"TYPE_WATER"},
    "youngster": {"TYPE_NORMAL", "TYPE_FLYING", "TYPE_BUG"},
}

PROTECTED_CLASS_TOKENS = (
    "leader",
    "elitefour",
    "champion",
    "rival",
)

PROTECTED_TRAINER_IDS = {
    "TRAINER_RED",
    "TRAINER_LANCE",
    "TRAINER_SILVER",
    "TRAINER_EUSINE",
}

EXCLUDED_ANALYSIS_MAP_PREFIXES = (
    *EXCLUDED_TRAINER_MAP_PREFIXES,
    "Route26",
    "Route27",
    "SSAqua",
    "SSAnne",
    "SSTidal",
    "ViridianForest",
)


@dataclass
class SpeciesEntry:
    species_id: int
    constant: str
    name: str
    flags: set[str]
    types: tuple[str, str]
    bst: int
    family: str = ""
    min_stage_level: int = 1
    next_level_evo: int | None = None

    @property
    def target_eligible(self) -> bool:
        return not self.flags.intersection(LEGENDARY_FLAGS | EXCLUDED_FORM_FLAGS)


@dataclass
class TrainerMon:
    trainer_id: str
    trainer_name: str
    trainer_class: str
    trainer_pic: str
    trainer_music: str
    trainer_start_line: int
    line: int
    party_index: int
    species: str
    level: int = 100
    party_size: int = 0
    maps: tuple[str, ...] = ()


@dataclass
class TrainerBlock:
    trainer_id: str
    start_line: int
    metadata: dict[str, str] = field(default_factory=dict)
    mons: list[TrainerMon] = field(default_factory=list)

    @property
    def name(self) -> str:
        return self.metadata.get("name", "")

    @property
    def trainer_class(self) -> str:
        return self.metadata.get("class", "")

    @property
    def pic(self) -> str:
        return self.metadata.get("pic", "")

    @property
    def music(self) -> str:
        return self.metadata.get("music", "")

    @property
    def is_rocket(self) -> bool:
        joined = " ".join([self.trainer_class, self.pic, self.music]).lower()
        return "rocket" in joined

    @property
    def protected(self) -> bool:
        class_token = normalize_token(self.trainer_class)
        return self.trainer_id in PROTECTED_TRAINER_IDS or any(token in class_token for token in PROTECTED_CLASS_TOKENS)


@dataclass
class WildInfo:
    slots: int = 0
    min_level: int = 999
    max_level: int = 0
    maps: set[str] = field(default_factory=set)
    methods: set[str] = field(default_factory=set)

    def add(self, map_name: str, method: str, min_level: int, max_level: int) -> None:
        self.slots += 1
        self.min_level = min(self.min_level, min_level)
        self.max_level = max(self.max_level, max_level)
        self.maps.add(format_map_name(map_name))
        self.methods.add(method.replace("_mons", "").replace("_", " ").title())

    @property
    def has_data(self) -> bool:
        return self.slots > 0


def format_map_name(map_constant: str) -> str:
    return map_constant.removeprefix("MAP_").replace("_", " ").title()


def format_constant(constant: str) -> str:
    return constant.removeprefix("SPECIES_").replace("_", " ").title()


def parse_species_constants() -> tuple[dict[int, str], dict[str, int]]:
    id_to_constant: dict[int, str] = {}
    constant_to_id: dict[str, int] = {}
    for line in SPECIES_H.read_text(encoding="utf-8").splitlines():
        match = SPECIES_DEFINE_RE.match(line)
        if not match:
            continue
        constant, value = match.groups()
        species_id = int(value)
        id_to_constant[species_id] = constant
        constant_to_id[constant] = species_id
    return id_to_constant, constant_to_id


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


def parse_enabled_species(id_to_constant: dict[int, str]) -> dict[str, SpeciesEntry]:
    entries: dict[str, SpeciesEntry] = {}
    in_array = False
    current_id: int | None = None
    current_lines: list[str] = []
    brace_depth = 0

    for line in preprocess_species_info().splitlines():
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
            entry_text = "\n".join(current_lines)
            base_hp = extract_number(entry_text, "baseHP")
            if base_hp > 0:
                name = collect_strings(extract_field(entry_text, "speciesName") or "") or format_constant(constant)
                types = extract_braced_constants(entry_text, "types", "TYPE_") or ["TYPE_NORMAL"]
                if len(types) == 1:
                    types.append(types[0])
                flags = {
                    flag_match.group(1)
                    for entry_line in current_lines
                    if (flag_match := TRUE_FLAG_RE.match(entry_line))
                }
                stats = [
                    extract_number(entry_text, field_name)
                    for field_name in ("baseHP", "baseAttack", "baseDefense", "baseSpAttack", "baseSpDefense", "baseSpeed")
                ]
                entries[constant] = SpeciesEntry(
                    species_id=current_id,
                    constant=constant,
                    name=name,
                    flags=flags,
                    types=(types[0], types[1]),
                    bst=sum(stats),
                )

        current_id = None
        current_lines = []

    return entries


def build_alias_map(entries: dict[str, SpeciesEntry], constant_to_id: dict[str, int]) -> dict[str, str]:
    aliases: dict[str, str] = {}
    for constant in constant_to_id:
        if constant in {"SPECIES_NONE", "SPECIES_EGG"}:
            continue
        constant_name = constant.removeprefix("SPECIES_")
        alias_values = [
            constant,
            constant_name,
            constant_name.replace("_", " "),
            constant_name.replace("_", "-"),
        ]
        for suffix in ("_STANDARD", "_AVERAGE", "_OVERCAST", "_RED_STRIPED", "_BLUE_STRIPED"):
            if constant_name.endswith(suffix):
                shorter_name = constant_name.removesuffix(suffix)
                alias_values.extend(
                    [
                        shorter_name,
                        shorter_name.replace("_", " "),
                        shorter_name.replace("_", "-"),
                    ]
                )
        for alias in alias_values:
            aliases.setdefault(normalize_token(alias), constant)

    for constant, entry in entries.items():
        aliases.setdefault(normalize_token(entry.name), constant)
    return aliases


def parse_species_from_party_line(line: str, aliases: dict[str, str]) -> str | None:
    constant_match = re.search(r"\b(SPECIES_[A-Z0-9_]+)\b", line)
    if constant_match:
        return constant_match.group(1)

    candidates = []
    for match in re.findall(r"\(([^()]*)\)", line):
        if match not in {"M", "F"}:
            candidates.append(match)

    stripped = line.split("@", 1)[0].strip()
    stripped = re.sub(r"\s+\((M|F)\)\s*$", "", stripped)
    candidates.append(stripped)
    candidates.append(line)

    for candidate in candidates:
        species = aliases.get(normalize_token(candidate))
        if species:
            return species
    return None


def strip_c_comment_line(line: str, in_comment: bool) -> tuple[str, bool]:
    output = []
    index = 0
    while index < len(line):
        if in_comment:
            end = line.find("*/", index)
            if end == -1:
                return "".join(output), True
            index = end + 2
            in_comment = False
            continue
        start = line.find("/*", index)
        if start == -1:
            output.append(line[index:])
            break
        output.append(line[index:start])
        index = start + 2
        in_comment = True
    return "".join(output), in_comment


def parse_level(value: str, default: int = 100) -> int:
    level = eval_int_expr(value)
    return level if level is not None else default


def parse_trainers_party(aliases: dict[str, str]) -> tuple[list[TrainerBlock], list[tuple[int, str]]]:
    trainers: list[TrainerBlock] = []
    unresolved: list[tuple[int, str]] = []
    current: TrainerBlock | None = None
    current_mon: TrainerMon | None = None
    in_comment = False

    def close_mon() -> None:
        nonlocal current_mon
        if current is not None and current_mon is not None:
            current.mons.append(current_mon)
            current_mon = None

    def close_trainer() -> None:
        if current is not None:
            close_mon()
            trainers.append(current)

    for lineno, raw_line in enumerate(TRAINERS_PARTY.read_text(encoding="utf-8").splitlines(), start=1):
        uncommented, in_comment = strip_c_comment_line(raw_line, in_comment)
        line = uncommented.strip()
        if not line:
            close_mon()
            continue

        header_match = TRAINER_HEADER_RE.match(line)
        if header_match:
            close_trainer()
            current = TrainerBlock(trainer_id=header_match.group(1), start_line=lineno)
            current_mon = None
            continue

        if current is None:
            continue

        if line.startswith(TRAINER_METADATA_PREFIXES):
            key, _, value = line.partition(":")
            current.metadata[key.strip().lower()] = value.strip()
            continue

        if current_mon is not None and line.startswith("Level:"):
            current_mon.level = parse_level(line.partition(":")[2].strip())
            continue

        if line.startswith(POKEMON_FIELD_PREFIXES) or line.startswith("- ") or line.endswith("Nature"):
            continue

        species = parse_species_from_party_line(line, aliases)
        if species:
            close_mon()
            current_mon = TrainerMon(
                trainer_id=current.trainer_id,
                trainer_name=current.name,
                trainer_class=current.trainer_class,
                trainer_pic=current.pic,
                trainer_music=current.music,
                trainer_start_line=current.start_line,
                line=lineno,
                party_index=len(current.mons) + 1,
                species=species,
            )
        else:
            unresolved.append((lineno, line))

    close_trainer()

    for trainer in trainers:
        for mon in trainer.mons:
            mon.party_size = len(trainer.mons)
    return trainers, unresolved


def parse_wild_encounters() -> dict[str, WildInfo]:
    data = json.loads(WILD_ENCOUNTERS_JSON.read_text(encoding="utf-8"))
    wild: dict[str, WildInfo] = defaultdict(WildInfo)
    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            map_name = encounter.get("map", "UNKNOWN_MAP")
            for method, payload in encounter.items():
                if not isinstance(payload, dict) or "mons" not in payload:
                    continue
                for mon in payload.get("mons", []):
                    species = mon.get("species")
                    if not species:
                        continue
                    wild[species].add(
                        map_name,
                        method,
                        int(mon.get("min_level", 0)),
                        int(mon.get("max_level", mon.get("min_level", 0))),
                    )
    return wild


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
            if ENDIF_RE.match(line):
                current_family = family_stack.pop() if family_stack else None
                continue
            if current_family is None:
                continue
            species_match = SPECIES_ENTRY_RE.search(line)
            if species_match:
                species_to_family.setdefault(species_match.group(1), current_family)
    return species_to_family


def parse_map_group_lookup() -> dict[str, str]:
    try:
        data = json.loads(MAP_GROUPS_JSON.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError):
        return {}

    lookup: dict[str, str] = {}
    for group_name in data.get("group_order") or []:
        for map_name in data.get(group_name) or []:
            lookup[map_name] = group_name
    return lookup


def is_analysis_excluded_map(map_name: str, map_group_lookup: dict[str, str]) -> bool:
    group_name = map_group_lookup.get(map_name, "")
    if group_name in EXCLUDED_TRAINER_MAP_GROUPS:
        return True
    if map_name in EXCLUDED_TRAINER_MAP_NAMES:
        return True
    if map_name.endswith("_Frlg"):
        return True
    return map_name.startswith(EXCLUDED_ANALYSIS_MAP_PREFIXES)


def parse_trainer_map_references() -> dict[str, set[str]]:
    references: dict[str, set[str]] = defaultdict(set)
    trainer_re = re.compile(r"\bTRAINER_[A-Z0-9_]+\b")
    map_group_lookup = parse_map_group_lookup()
    for script_path in sorted((REPO_ROOT / "data/maps").glob("*/scripts.*")):
        if script_path.suffix not in {".inc", ".pory"}:
            continue
        map_name = script_path.parent.name
        if is_analysis_excluded_map(map_name, map_group_lookup):
            continue
        text = strip_c_comments(script_path.read_text(encoding="utf-8"))
        for trainer_id in trainer_re.findall(text):
            if trainer_id != "TRAINER_NONE":
                references[trainer_id].add(map_name)
    return references


def assign_evolution_levels(entries: dict[str, SpeciesEntry]) -> None:
    evolutions = parse_evolutions({})
    known = set(entries)
    min_stage = {constant: 1 for constant in known}
    next_level_evo: dict[str, int] = {}
    edges: list[tuple[str, str, int]] = []

    for source, source_evos in evolutions.items():
        if source not in known:
            continue
        for evo in source_evos:
            target = evo["target"]
            if target not in known:
                continue
            method = evo["method"]
            param = eval_int_expr(evo["param"]) or 0
            if method in {"EVO_LEVEL", "EVO_LEVEL_BATTLE_ONLY"} and param > 0:
                required_level = param
                next_level_evo[source] = min(next_level_evo.get(source, required_level), required_level)
            else:
                required_level = 1
            edges.append((source, target, required_level))

    changed = True
    while changed:
        changed = False
        for source, target, required_level in edges:
            candidate = max(min_stage[source], required_level)
            if candidate > min_stage[target]:
                min_stage[target] = candidate
                changed = True

    for constant, entry in entries.items():
        entry.min_stage_level = min_stage.get(constant, 1)
        entry.next_level_evo = next_level_evo.get(constant)


def display_species(constant: str, entries: dict[str, SpeciesEntry]) -> str:
    entry = entries.get(constant)
    if not entry:
        return format_constant(constant)
    if entry.name == format_constant(constant):
        return entry.name
    suffix = constant.removeprefix("SPECIES_").replace("_", " ").title()
    return f"{entry.name} [{suffix}]"


def class_type_preferences(trainer_class: str) -> set[str]:
    class_token = normalize_token(trainer_class)
    prefs: set[str] = set()
    for token, types in CLASS_TYPE_PREFERENCES.items():
        if token in class_token:
            prefs.update(types)
    return prefs


def type_names(types: tuple[str, str]) -> str:
    names = [type_constant.removeprefix("TYPE_").title() for type_constant in types]
    if names[0] == names[1]:
        return names[0]
    return "/".join(names)


def compact_list(values: list[str] | set[str] | tuple[str, ...], limit: int = 3) -> str:
    ordered = sorted(values)
    if not ordered:
        return "-"
    if len(ordered) <= limit:
        return ", ".join(ordered)
    return ", ".join(ordered[:limit]) + f" +{len(ordered) - limit}"


def line_link(line: int) -> str:
    return f"src/data/trainers.party:{line}"


def build_usage_rows(
    trainers: list[TrainerBlock],
    trainer_refs: dict[str, set[str]],
) -> tuple[list[TrainerMon], list[TrainerMon]]:
    all_uses: list[TrainerMon] = []
    nonrocket_uses: list[TrainerMon] = []
    for trainer in trainers:
        maps = tuple(sorted(trainer_refs.get(trainer.trainer_id, set())))
        if not maps:
            continue
        for mon in trainer.mons:
            mon.maps = maps
            all_uses.append(mon)
            if not trainer.is_rocket and trainer.trainer_id != "TRAINER_NONE":
                nonrocket_uses.append(mon)
    return all_uses, nonrocket_uses


def ordinary_nonrocket_trainers(trainers: list[TrainerBlock]) -> dict[str, TrainerBlock]:
    return {
        trainer.trainer_id: trainer
        for trainer in trainers
        if not trainer.is_rocket
        and not trainer.protected
        and trainer.trainer_id != "TRAINER_NONE"
        and trainer.trainer_class
    }


def replacement_candidates(
    nonrocket_uses: list[TrainerMon],
    entries: dict[str, SpeciesEntry],
    wild: dict[str, WildInfo],
    trainer_blocks: dict[str, TrainerBlock],
    limit: int,
    overuse_threshold: int,
) -> list[dict[str, object]]:
    usage_count = Counter(mon.species for mon in nonrocket_uses)
    trainer_species_count = Counter((mon.trainer_id, mon.species) for mon in nonrocket_uses)
    family_usage = Counter(entries[mon.species].family for mon in nonrocket_uses if mon.species in entries)
    used_targets: set[str] = set()
    used_donor_slots: Counter[tuple[str, str]] = Counter()

    missing_targets = [
        entry
        for entry in entries.values()
        if entry.target_eligible
        and usage_count.get(entry.constant, 0) == 0
        and wild.get(entry.constant, WildInfo()).has_data
    ]

    def target_score(mon: TrainerMon, target: SpeciesEntry, prefs: set[str]) -> tuple[int, str] | None:
        wild_info = wild.get(target.constant, WildInfo())
        if target.constant in used_targets:
            return None
        if mon.level < target.min_stage_level:
            return None
        if wild_info.has_data and wild_info.min_level > mon.level + 2:
            return None
        if target.next_level_evo is not None and mon.level > target.next_level_evo + 10:
            return None

        type_match = bool(set(target.types).intersection(prefs)) if prefs else True
        if prefs and not type_match:
            return None

        anchor = target.min_stage_level
        if wild_info.has_data:
            anchor = min(max(mon.level, wild_info.min_level), wild_info.max_level)
        level_gap = abs(mon.level - anchor)
        family_bonus = 12 if family_usage.get(target.family, 0) == 0 else 0
        type_bonus = 18 if type_match and prefs else 0
        bst_gap = abs(entries.get(mon.species, target).bst - target.bst) // 20
        score = 100 + type_bonus + family_bonus - level_gap - bst_gap
        reason_bits = []
        if prefs and type_match:
            reason_bits.append(f"class type fit ({type_names(target.types)})")
        elif not prefs:
            reason_bits.append(f"generic class fit ({type_names(target.types)})")
        reason_bits.append(f"min stage L{target.min_stage_level}")
        if wild_info.has_data:
            reason_bits.append(f"wild L{wild_info.min_level}-{wild_info.max_level}")
        return score, "; ".join(reason_bits)

    donors = []
    for mon in nonrocket_uses:
        trainer = trainer_blocks.get(mon.trainer_id)
        if trainer is None or trainer.protected:
            continue
        duplicate_bonus = 50 if trainer_species_count[(mon.trainer_id, mon.species)] > 1 else 0
        if usage_count[mon.species] < overuse_threshold and not duplicate_bonus:
            continue
        referenced_bonus = 20 if mon.maps else 0
        donors.append((duplicate_bonus + referenced_bonus + usage_count[mon.species], mon))

    suggestions: list[dict[str, object]] = []
    for _, mon in sorted(donors, key=lambda item: (-item[0], item[1].line)):
        donor_key = (mon.trainer_id, mon.species)
        duplicate_count = trainer_species_count[donor_key]
        max_replacements = duplicate_count - 1 if duplicate_count > 1 else 1
        if used_donor_slots[donor_key] >= max_replacements:
            continue
        prefs = class_type_preferences(mon.trainer_class)
        scored_targets = []
        for target in missing_targets:
            scored = target_score(mon, target, prefs)
            if scored is not None:
                score, reason = scored
                scored_targets.append((score, target, reason))
        if not scored_targets:
            continue
        score, target, reason = max(scored_targets, key=lambda item: (item[0], -item[1].species_id))
        used_targets.add(target.constant)
        used_donor_slots[donor_key] += 1
        current_count = usage_count[mon.species]
        suggestions.append(
            {
                "line": mon.line,
                "trainer": mon.trainer_name or mon.trainer_id,
                "trainer_id": mon.trainer_id,
                "class": mon.trainer_class or "-",
                "level": mon.level,
                "from": mon.species,
                "to": target.constant,
                "from_count": current_count,
                "maps": mon.maps,
                "reason": reason,
            }
        )
        if len(suggestions) >= limit:
            break
    return suggestions


def make_markdown_report(args: argparse.Namespace) -> str:
    id_to_constant, constant_to_id = parse_species_constants()
    entries = parse_enabled_species(id_to_constant)
    species_to_family = parse_species_to_family()
    for constant, entry in entries.items():
        entry.family = species_to_family.get(constant, constant)
    assign_evolution_levels(entries)

    aliases = build_alias_map(entries, constant_to_id)
    trainers, unresolved = parse_trainers_party(aliases)
    trainer_refs = parse_trainer_map_references()
    wild = parse_wild_encounters()
    _, nonrocket_uses = build_usage_rows(trainers, trainer_refs)
    trainer_blocks = ordinary_nonrocket_trainers(trainers)

    target_entries = [entry for entry in entries.values() if entry.target_eligible]
    enabled_targets = {entry.constant for entry in target_entries}
    wild_enabled = {constant for constant in wild if constant in enabled_targets}
    nonrocket_present = {mon.species for mon in nonrocket_uses if mon.species in enabled_targets}
    usage_count = Counter(mon.species for mon in nonrocket_uses if mon.species in enabled_targets)

    all_species_by_count = sorted(
        usage_count.items(),
        key=lambda item: (-item[1], entries[item[0]].species_id),
    )

    uses_by_species: dict[str, list[TrainerMon]] = defaultdict(list)
    for mon in nonrocket_uses:
        if mon.species in enabled_targets:
            uses_by_species[mon.species].append(mon)

    duplicate_parties = []
    per_trainer_species = defaultdict(Counter)
    for mon in nonrocket_uses:
        if mon.species in enabled_targets:
            per_trainer_species[mon.trainer_id][mon.species] += 1
    for trainer in trainers:
        if trainer.is_rocket or trainer.protected or trainer.trainer_id == "TRAINER_NONE":
            continue
        for species, count in per_trainer_species[trainer.trainer_id].items():
            if count > 1:
                lines = [mon.line for mon in trainer.mons if mon.species == species]
                duplicate_parties.append((count, trainer, species, lines))
    duplicate_parties.sort(key=lambda item: (-item[0], item[1].start_line))

    missing_trainer_wild = sorted(
        (constant for constant in wild_enabled if constant not in nonrocket_present),
        key=lambda constant: (wild[constant].min_level, entries[constant].species_id),
    )
    missing_everywhere = sorted(
        (entry.constant for entry in target_entries if entry.constant not in wild_enabled and entry.constant not in nonrocket_present),
        key=lambda constant: entries[constant].species_id,
    )

    suggestions = replacement_candidates(
        nonrocket_uses,
        entries,
        wild,
        trainer_blocks,
        args.suggestion_limit,
        args.overuse_threshold,
    )

    referenced_trainers = {trainer_id for trainer_id, maps in trainer_refs.items() if maps}
    included_trainers = [trainer for trainer in trainers if trainer.trainer_id in referenced_trainers]
    protected_or_rocket_trainers = sum(1 for trainer in included_trainers if trainer.is_rocket or trainer.protected)
    rocket_mons = sum(len(trainer.mons) for trainer in included_trainers if trainer.is_rocket)
    referenced_nonrocket_uses = [mon for mon in nonrocket_uses if mon.trainer_id in referenced_trainers]

    lines: list[str] = []
    lines.append("# Trainer Party Diversity Report")
    lines.append("")
    lines.append("Generated by `tools/analyze_trainer_party_diversity.py`.")
    lines.append("")
    lines.append("## Scope")
    lines.append("")
    lines.append("- Excludes Team Rocket by trainer class/pic/music containing `rocket`.")
    lines.append("- Keeps gym leaders, Elite Four, champions, Red, Silver, and Eusine out of automated swap suggestions.")
    lines.append("- Ignores trainer references from Emerald map groups, Kanto maps, and SS Anne/ship maps before counting.")
    lines.append("- Counts only enabled, non-legendary, non-mythical, non-battle-only-form species for coverage totals.")
    lines.append("- Uses `src/data/wild_encounters.json` as the level sanity check for candidate additions.")
    lines.append("")
    lines.append("## Summary")
    lines.append("")
    lines.append("| Metric | Count |")
    lines.append("| --- | ---: |")
    lines.append(f"| Trainer blocks parsed | {len(trainers)} |")
    lines.append(f"| Trainer blocks with included map references | {len(trainer_refs)} |")
    lines.append(f"| Protected or Rocket trainer blocks | {protected_or_rocket_trainers} |")
    lines.append(f"| Rocket mons excluded | {rocket_mons} |")
    lines.append(f"| Non-Rocket mon entries counted | {len(nonrocket_uses)} |")
    lines.append(f"| Referenced non-Rocket mon entries counted | {len(referenced_nonrocket_uses)} |")
    lines.append(f"| Eligible enabled species | {len(target_entries)} |")
    lines.append(f"| Eligible species in wild encounters | {len(wild_enabled)} |")
    lines.append(f"| Eligible species in non-Rocket trainer parties | {len(nonrocket_present)} |")
    lines.append(f"| Wild-enabled species missing from non-Rocket trainer parties | {len(missing_trainer_wild)} |")
    lines.append(f"| Eligible species missing from both wild and non-Rocket trainers | {len(missing_everywhere)} |")
    if unresolved:
        lines.append(f"| Unresolved party header-ish lines | {len(unresolved)} |")
    lines.append("")

    lines.append("## Most Reused Non-Rocket Species")
    lines.append("")
    lines.append("| Species | Count | Trainers | Level range | Common classes | Wild range |")
    lines.append("| --- | ---: | ---: | --- | --- | --- |")
    for species, count in all_species_by_count[: args.top_limit]:
        uses = uses_by_species[species]
        trainer_count = len({mon.trainer_id for mon in uses})
        levels = [mon.level for mon in uses]
        class_counts = Counter(mon.trainer_class or "-" for mon in uses)
        classes = ", ".join(name for name, _ in class_counts.most_common(3))
        wild_info = wild.get(species, WildInfo())
        wild_range = f"L{wild_info.min_level}-{wild_info.max_level}" if wild_info.has_data else "-"
        lines.append(
            f"| {display_species(species, entries)} | {count} | {trainer_count} | "
            f"L{min(levels)}-{max(levels)} | {classes} | {wild_range} |"
        )
    lines.append("")

    lines.append("## Duplicate Hotspots")
    lines.append("")
    lines.append("These are ordinary non-Rocket parties with the same species repeated in one party. They are the safest cleanup targets because one swap preserves the trainer's existing theme while adding a new dex sighting.")
    lines.append("")
    lines.append("| Lines | Trainer | Class | Duplicate | Count | Maps |")
    lines.append("| --- | --- | --- | --- | ---: | --- |")
    for count, trainer, species, species_lines in duplicate_parties[: args.top_limit]:
        maps = trainer_refs.get(trainer.trainer_id, set())
        lines.append(
            f"| {', '.join(line_link(line) for line in species_lines)} | "
            f"{trainer.name or trainer.trainer_id} | {trainer.trainer_class or '-'} | "
            f"{display_species(species, entries)} | {count} | {compact_list(maps)} |"
        )
    lines.append("")

    lines.append("## Wild-Enabled Species Missing From Non-Rocket Trainers")
    lines.append("")
    lines.append("Sorted by earliest wild level, so early-game opportunities float up first.")
    lines.append("")
    lines.append("| Species | Types | Wild range | Wild maps | Stage floor |")
    lines.append("| --- | --- | --- | --- | ---: |")
    for species in missing_trainer_wild[: args.missing_limit]:
        entry = entries[species]
        wild_info = wild[species]
        lines.append(
            f"| {display_species(species, entries)} | {type_names(entry.types)} | "
            f"L{wild_info.min_level}-{wild_info.max_level} | {compact_list(wild_info.maps, 4)} | "
            f"{entry.min_stage_level} |"
        )
    if len(missing_trainer_wild) > args.missing_limit:
        lines.append(f"| ... | ... | ... | {len(missing_trainer_wild) - args.missing_limit} more omitted by `--missing-limit` | ... |")
    lines.append("")

    lines.append("## Suggested Low-Risk Swaps")
    lines.append("")
    lines.append("These are suggestions only. They replace overrepresented or duplicated ordinary non-Rocket mons with species that are enabled, present in wild encounters, absent from non-Rocket trainer parties, type-appropriate for the class when the class has a strong theme, and plausible at the trainer level.")
    lines.append("")
    lines.append("| Line | Trainer | Class | Level | Replace | Add | Current count | Maps | Why this fits |")
    lines.append("| --- | --- | --- | ---: | --- | --- | ---: | --- | --- |")
    for suggestion in suggestions:
        lines.append(
            f"| {line_link(int(suggestion['line']))} | {suggestion['trainer']} | {suggestion['class']} | "
            f"{suggestion['level']} | {display_species(str(suggestion['from']), entries)} | "
            f"{display_species(str(suggestion['to']), entries)} | {suggestion['from_count']} | "
            f"{compact_list(suggestion['maps'])} | {suggestion['reason']} |"
        )
    lines.append("")

    lines.append("## Missing Everywhere")
    lines.append("")
    lines.append("These eligible enabled species are absent from both wild encounters and non-Rocket trainer parties. I would treat these as separate distribution design work rather than trainer-party cleanup.")
    lines.append("")
    lines.append("| Species | Types | Stage floor |")
    lines.append("| --- | --- | ---: |")
    for species in missing_everywhere[: args.missing_limit]:
        entry = entries[species]
        lines.append(f"| {display_species(species, entries)} | {type_names(entry.types)} | {entry.min_stage_level} |")
    if len(missing_everywhere) > args.missing_limit:
        lines.append(f"| ... | ... | {len(missing_everywhere) - args.missing_limit} more omitted by `--missing-limit` |")
    lines.append("")

    if unresolved:
        lines.append("## Parser Notes")
        lines.append("")
        lines.append("The following lines looked like possible species lines but did not resolve. They may be harmless custom syntax.")
        lines.append("")
        for line_number, text in unresolved[:25]:
            lines.append(f"- {line_link(line_number)}: `{text}`")
        if len(unresolved) > 25:
            lines.append(f"- ... {len(unresolved) - 25} more")
        lines.append("")

    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description="Analyze non-Rocket trainer party species reuse and coverage.")
    parser.add_argument("-o", "--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--top-limit", type=int, default=35)
    parser.add_argument("--missing-limit", type=int, default=80)
    parser.add_argument("--suggestion-limit", type=int, default=45)
    parser.add_argument("--overuse-threshold", type=int, default=6)
    args = parser.parse_args()

    output_path = args.output
    if not output_path.is_absolute():
        output_path = REPO_ROOT / output_path

    report = make_markdown_report(args)
    output_path.write_text(report + "\n", encoding="utf-8")
    print(f"Wrote {output_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
