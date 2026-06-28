#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT))

from tools import analyze_trainer_party_diversity as trainer_report  # noqa: E402
from tools.soulgold_docs.constants import ENCOUNTER_SLOT_RATES  # noqa: E402


WILD_ENCOUNTERS_JSON = REPO_ROOT / "src/data/wild_encounters.json"
HIDDEN_GROTTO_C = REPO_ROOT / "src/hidden_grotto.c"
MAP_GROUPS_JSON = REPO_ROOT / "data/maps/map_groups.json"
SCRCMD_C = REPO_ROOT / "src/scrcmd.c"
DEFAULT_OUTPUT = REPO_ROOT / "tools/species_availability_report.md"

GIVEMON_RE = re.compile(r"\bgivemon\s+([^,\s]+)\s*,\s*([^,\s]+)")
GIVEEGG_RE = re.compile(r"\bgiveegg\s+([^,\s]+)")
GIVENAMEDMON_RE = re.compile(r"\bgivenamedmon\s+(\d+)")
SETVAR_SPECIES_RE = re.compile(r"\bsetvar\s+(VAR_[A-Z0-9_]+)\s*,\s*(SPECIES_[A-Z0-9_]+)")
SPECIES_RE = re.compile(r"\bSPECIES_[A-Z0-9_]+\b")
HIDDEN_GROTTO_ENTRY_RE = re.compile(r"\[(HIDDEN_GROTTO_[A-Z0-9_]+)\]\s*=")
MAP_GROTTO_RE = re.compile(r"\b(MAP_HIDDEN_GROTTO_[A-Z0-9_]+)\b")


METHOD_LABELS = {
    "land_mons": "Land",
    "water_mons": "Water",
    "rock_smash_mons": "Rock Smash",
    "fishing_mons": "Fishing",
}

MAP_THEME_TYPES = (
    ("Forest", {"TYPE_GRASS", "TYPE_BUG", "TYPE_POISON", "TYPE_GHOST", "TYPE_FLYING"}),
    ("Ilex", {"TYPE_GRASS", "TYPE_BUG", "TYPE_GHOST", "TYPE_FAIRY"}),
    ("Park", {"TYPE_BUG", "TYPE_NORMAL", "TYPE_GRASS", "TYPE_FLYING"}),
    ("Cave", {"TYPE_ROCK", "TYPE_GROUND", "TYPE_GHOST", "TYPE_DARK", "TYPE_STEEL"}),
    ("Mt", {"TYPE_ROCK", "TYPE_GROUND", "TYPE_FIGHTING", "TYPE_STEEL", "TYPE_ICE"}),
    ("Mountain", {"TYPE_ROCK", "TYPE_GROUND", "TYPE_FIGHTING", "TYPE_STEEL", "TYPE_ICE"}),
    ("Tunnel", {"TYPE_ROCK", "TYPE_GROUND", "TYPE_DARK", "TYPE_STEEL"}),
    ("Well", {"TYPE_WATER", "TYPE_POISON", "TYPE_GHOST"}),
    ("Tower", {"TYPE_GHOST", "TYPE_PSYCHIC", "TYPE_FLYING", "TYPE_NORMAL"}),
    ("Ruins", {"TYPE_PSYCHIC", "TYPE_ROCK", "TYPE_GHOST", "TYPE_GROUND", "TYPE_STEEL"}),
    ("Lake", {"TYPE_WATER", "TYPE_DRAGON", "TYPE_FLYING", "TYPE_NORMAL"}),
    ("Shore", {"TYPE_WATER", "TYPE_FLYING", "TYPE_NORMAL"}),
    ("Sea", {"TYPE_WATER", "TYPE_ICE", "TYPE_FLYING"}),
    ("Whirl", {"TYPE_WATER", "TYPE_ICE", "TYPE_FLYING"}),
    ("Island", {"TYPE_WATER", "TYPE_FLYING", "TYPE_ROCK"}),
    ("Ice", {"TYPE_ICE", "TYPE_WATER", "TYPE_ROCK"}),
    ("Desert", {"TYPE_GROUND", "TYPE_ROCK", "TYPE_FIRE", "TYPE_STEEL"}),
    ("Safari", {"TYPE_NORMAL", "TYPE_GRASS", "TYPE_WATER", "TYPE_GROUND", "TYPE_FLYING"}),
)


@dataclass(frozen=True)
class WildSlot:
    species: str
    map_name: str
    map_constant: str
    method: str
    min_level: int
    max_level: int
    slot_rate: int
    encounter_rate: int
    effective_weight: float
    in_scope: bool


@dataclass(frozen=True)
class GiftMon:
    species: str
    level: int | None
    location: str
    map_name: str | None
    path: Path
    line: int
    source_kind: str
    in_scope: bool
    note: str = ""
    is_egg: bool = False


@dataclass(frozen=True)
class GrottoMon:
    species: str
    level: int
    grotto_id: str
    grotto_map: str
    source_maps: tuple[str, ...]
    in_scope: bool
    note: str = ""


@dataclass
class SpeciesWildStats:
    slots: int = 0
    slot_weight: int = 0
    effective_weight: float = 0.0
    min_level: int = 999
    max_level: int = 0
    maps: set[str] = field(default_factory=set)
    methods: Counter[str] = field(default_factory=Counter)
    examples: list[WildSlot] = field(default_factory=list)

    def add(self, slot: WildSlot) -> None:
        self.slots += 1
        self.slot_weight += slot.slot_rate
        self.effective_weight += slot.effective_weight
        self.min_level = min(self.min_level, slot.min_level)
        self.max_level = max(self.max_level, slot.max_level)
        self.maps.add(slot.map_name)
        self.methods[METHOD_LABELS.get(slot.method, slot.method)] += 1
        if len(self.examples) < 5:
            self.examples.append(slot)


@dataclass
class MapProfile:
    map_name: str
    slots: int = 0
    slot_weight: int = 0
    effective_weight: float = 0.0
    min_level: int = 999
    max_level: int = 0
    methods: Counter[str] = field(default_factory=Counter)
    method_weights: Counter[str] = field(default_factory=Counter)
    method_min_level: dict[str, int] = field(default_factory=dict)
    method_max_level: dict[str, int] = field(default_factory=dict)
    method_species_slots: dict[str, Counter[str]] = field(default_factory=dict)
    species_slots: Counter[str] = field(default_factory=Counter)
    species_weight: Counter[str] = field(default_factory=Counter)
    type_weight: Counter[str] = field(default_factory=Counter)

    def add(self, slot: WildSlot, entries: dict[str, trainer_report.SpeciesEntry]) -> None:
        self.slots += 1
        self.slot_weight += slot.slot_rate
        self.effective_weight += slot.effective_weight
        self.min_level = min(self.min_level, slot.min_level)
        self.max_level = max(self.max_level, slot.max_level)
        self.methods[METHOD_LABELS.get(slot.method, slot.method)] += 1
        self.method_weights[slot.method] += slot.slot_rate
        self.method_min_level[slot.method] = min(self.method_min_level.get(slot.method, 999), slot.min_level)
        self.method_max_level[slot.method] = max(self.method_max_level.get(slot.method, 0), slot.max_level)
        self.method_species_slots.setdefault(slot.method, Counter())[slot.species] += 1
        self.species_slots[slot.species] += 1
        self.species_weight[slot.species] += slot.slot_rate
        entry = entries.get(slot.species)
        if entry:
            for type_constant in set(entry.types):
                self.type_weight[type_constant] += slot.slot_rate

    @property
    def level_range(self) -> str:
        if self.slots == 0:
            return "-"
        return f"L{self.min_level}-{self.max_level}"

    def dominant_types(self, limit: int = 3) -> tuple[str, ...]:
        return tuple(type_constant for type_constant, _ in self.type_weight.most_common(limit))

    def method_range(self, method: str) -> tuple[int, int]:
        return self.method_min_level.get(method, 999), self.method_max_level.get(method, 0)

    def method_level_range(self, method: str) -> str:
        min_level, max_level = self.method_range(method)
        if min_level == 999:
            return "-"
        return f"L{min_level}-{max_level}"

    def candidate_methods(self, types: tuple[str, str]) -> list[str]:
        type_set = set(types)
        methods: list[str] = []
        if "TYPE_WATER" in type_set:
            methods.extend(method for method in ("water_mons", "fishing_mons") if self.method_weights.get(method, 0))
        if type_set & {"TYPE_ROCK", "TYPE_GROUND", "TYPE_FIGHTING", "TYPE_WATER"}:
            if self.method_weights.get("rock_smash_mons", 0):
                methods.append("rock_smash_mons")
        if self.method_weights.get("land_mons", 0):
            methods.append("land_mons")
        return list(dict.fromkeys(methods))


@dataclass(frozen=True)
class EncounterSuggestion:
    species: str
    map_name: str
    method: str
    source_state: str
    score: int
    replace_species: str | None
    reason: str


def split_camel(value: str) -> str:
    return re.sub(r"(?<=[a-z0-9])(?=[A-Z])", "_", value)


def map_name_to_constant(map_name: str) -> str:
    return "MAP_" + "_".join(split_camel(part).upper() for part in map_name.split("_"))


def build_map_constant_lookup() -> dict[str, str]:
    try:
        data = json.loads(MAP_GROUPS_JSON.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError):
        return {}

    lookup: dict[str, str] = {}
    for group_name in data.get("group_order") or []:
        for map_name in data.get(group_name) or []:
            lookup[map_name_to_constant(map_name)] = map_name
    return lookup


def map_constant_to_name(map_constant: str, lookup: dict[str, str]) -> str:
    if map_constant in lookup:
        return lookup[map_constant]
    return map_constant.removeprefix("MAP_").replace("_", " ").title().replace(" ", "")


def format_map_name(map_name: str) -> str:
    chunks: list[str] = []
    for part in map_name.split("_"):
        chunks.extend(split_camel(part).split("_"))
    spaced = " ".join(chunk for chunk in chunks if chunk)
    spaced = re.sub(r"\bRoute\s+(\d+)\b", r"Route\1", spaced)
    return spaced


def clean_family_name(family: str) -> str:
    return family.removeprefix("P_FAMILY_").replace("_", " ").title()


def type_set_text(types: set[str]) -> str:
    if not types:
        return "-"
    return "/".join(type_constant.removeprefix("TYPE_").title() for type_constant in sorted(types))


def type_overlap_text(types: set[str]) -> str:
    if not types:
        return "generic route mix"
    return type_set_text(types)


def parse_level_token(token: str, default: int | None = None) -> int | None:
    value = trainer_report.eval_int_expr(token) if hasattr(trainer_report, "eval_int_expr") else None
    if value is None:
        try:
            return int(token, 0)
        except ValueError:
            return default
    return value


def parse_named_gift_table() -> dict[int, tuple[str, int]]:
    text = trainer_report.strip_c_comments(SCRCMD_C.read_text(encoding="utf-8"))
    if "ScrCmd_givenamedmon" in text:
        text = text.split("ScrCmd_givenamedmon", 1)[1]
        next_function = re.search(r"\n(?:bool8|void|static)\s+[A-Za-z0-9_]+\s*\(", text)
        if next_function:
            text = text[: next_function.start()]
    table: dict[int, tuple[str, int]] = {}
    for match in re.finditer(r"case\s+(\d+)\s*:([\s\S]*?)break\s*;", text):
        gift_id = int(match.group(1))
        block = match.group(2)
        species_match = re.search(r"\bspecies\s*=\s*(SPECIES_[A-Z0-9_]+)\s*;", block)
        level_match = re.search(r"\blevel\s*=\s*(\d+)\s*;", block)
        if species_match and level_match:
            table[gift_id] = (species_match.group(1), int(level_match.group(1)))
    return table


def path_map_name(path: Path) -> str | None:
    try:
        relative = path.relative_to(REPO_ROOT)
    except ValueError:
        return None
    parts = relative.parts
    if len(parts) >= 4 and parts[0] == "data" and parts[1] == "maps":
        return parts[2]
    return None


def is_source_map_in_scope(map_name: str | None, map_group_lookup: dict[str, str]) -> bool:
    if map_name is None:
        return True
    return not trainer_report.is_analysis_excluded_map(map_name, map_group_lookup)


def source_location(path: Path, map_name: str | None) -> str:
    if map_name:
        return format_map_name(map_name)
    try:
        return str(path.relative_to(REPO_ROOT))
    except ValueError:
        return str(path)


def parse_wild_slots(
    map_constant_lookup: dict[str, str],
    map_group_lookup: dict[str, str],
) -> list[WildSlot]:
    data = json.loads(WILD_ENCOUNTERS_JSON.read_text(encoding="utf-8"))
    slots: list[WildSlot] = []

    for group in data.get("wild_encounter_groups", []):
        if not group.get("for_maps", False):
            continue
        field_rates = {
            field.get("type"): field.get("encounter_rates", ENCOUNTER_SLOT_RATES.get(field.get("type"), []))
            for field in group.get("fields", [])
            if field.get("type")
        }
        for encounter in group.get("encounters", []):
            map_constant = encounter.get("map", "MAP_UNKNOWN")
            map_name = map_constant_to_name(map_constant, map_constant_lookup)
            in_scope = is_source_map_in_scope(map_name, map_group_lookup)
            for method, payload in encounter.items():
                if not isinstance(payload, dict) or "mons" not in payload:
                    continue
                rates = field_rates.get(method) or ENCOUNTER_SLOT_RATES.get(method, [])
                encounter_rate = int(payload.get("encounter_rate", 100))
                for index, mon in enumerate(payload.get("mons") or []):
                    species = mon.get("species")
                    if not species or species == "SPECIES_NONE":
                        continue
                    slot_rate = int(rates[index]) if index < len(rates) else 1
                    effective_weight = slot_rate * encounter_rate / 100.0
                    slots.append(
                        WildSlot(
                            species=species,
                            map_name=map_name,
                            map_constant=map_constant,
                            method=method,
                            min_level=int(mon.get("min_level", 0)),
                            max_level=int(mon.get("max_level", mon.get("min_level", 0))),
                            slot_rate=slot_rate,
                            encounter_rate=encounter_rate,
                            effective_weight=effective_weight,
                            in_scope=in_scope,
                        )
                    )
    return slots


def parse_script_lines(path: Path) -> list[tuple[int, str]]:
    lines: list[tuple[int, str]] = []
    in_comment = False
    for lineno, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        uncommented, in_comment = trainer_report.strip_c_comment_line(raw_line, in_comment)
        line = uncommented.strip()
        if line:
            lines.append((lineno, line))
    return lines


def parse_gift_mons(map_group_lookup: dict[str, str]) -> tuple[list[GiftMon], list[str]]:
    named_gifts = parse_named_gift_table()
    gifts: list[GiftMon] = []
    unresolved: list[str] = []

    for path in sorted((REPO_ROOT / "data").rglob("*.inc")):
        lines = parse_script_lines(path)
        if not any(
            "givemon" in line or "giveegg" in line or "givenamedmon" in line
            for _, line in lines
        ):
            continue

        map_name = path_map_name(path)
        rel_path = path.relative_to(REPO_ROOT)
        is_debug = str(rel_path) == "data/scripts/debug.inc"
        in_scope = not is_debug and is_source_map_in_scope(map_name, map_group_lookup)
        location = source_location(path, map_name)
        note = "debug script" if is_debug else ""

        assignments: dict[str, list[tuple[int, str]]] = defaultdict(list)
        for lineno, line in lines:
            match = SETVAR_SPECIES_RE.search(line)
            if match:
                variable, species = match.groups()
                assignments[variable].append((lineno, species))

        seen_inferred: set[tuple[Path, str, int | None, str]] = set()
        for lineno, line in lines:
            if match := GIVEMON_RE.search(line):
                species_token, level_token = match.groups()
                level = parse_level_token(level_token)
                if species_token.startswith("SPECIES_"):
                    gifts.append(
                        GiftMon(
                            species=species_token,
                            level=level,
                            location=location,
                            map_name=map_name,
                            path=path,
                            line=lineno,
                            source_kind="Gift",
                            in_scope=in_scope,
                            note=note,
                        )
                    )
                    continue

                inferred = [species for _, species in assignments.get(species_token, [])]
                if not inferred:
                    unresolved.append(f"{rel_path}:{lineno} {line}")
                    continue

                for species in sorted(set(inferred)):
                    key = (path, species_token, level, species)
                    if key in seen_inferred:
                        continue
                    seen_inferred.add(key)
                    gifts.append(
                        GiftMon(
                            species=species,
                            level=level,
                            location=location,
                            map_name=map_name,
                            path=path,
                            line=lineno,
                            source_kind="Gift Inferred",
                            in_scope=in_scope,
                            note=f"inferred from {species_token}",
                        )
                    )

            if match := GIVEEGG_RE.search(line):
                species = match.group(1)
                gifts.append(
                    GiftMon(
                        species=species,
                        level=1,
                        location=location,
                        map_name=map_name,
                        path=path,
                        line=lineno,
                        source_kind="Egg",
                        in_scope=in_scope,
                        note=note,
                        is_egg=True,
                    )
                )

            if match := GIVENAMEDMON_RE.search(line):
                gift_id = int(match.group(1))
                if gift_id not in named_gifts:
                    unresolved.append(f"{rel_path}:{lineno} {line}")
                    continue
                species, level = named_gifts[gift_id]
                gifts.append(
                    GiftMon(
                        species=species,
                        level=level,
                        location=location,
                        map_name=map_name,
                        path=path,
                        line=lineno,
                        source_kind="Named Gift",
                        in_scope=in_scope,
                        note=f"named gift {gift_id}",
                    )
                )

    return gifts, unresolved


def parse_grotto_warp_sources(map_group_lookup: dict[str, str]) -> dict[str, set[str]]:
    sources: dict[str, set[str]] = defaultdict(set)
    for path in sorted((REPO_ROOT / "data/maps").glob("*/scripts.inc")):
        map_name = path.parent.name
        if trainer_report.is_analysis_excluded_map(map_name, map_group_lookup):
            continue
        text = trainer_report.strip_c_comments(path.read_text(encoding="utf-8"))
        for map_constant in MAP_GROTTO_RE.findall(text):
            sources[map_constant].add(map_name)
    return sources


def split_hidden_grotto_entries(text: str) -> list[tuple[str, str]]:
    matches = list(HIDDEN_GROTTO_ENTRY_RE.finditer(text))
    entries: list[tuple[str, str]] = []
    for index, match in enumerate(matches):
        start = match.end()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        entries.append((match.group(1), text[start:end]))
    return entries


def parse_hidden_grotto_mons(
    map_constant_lookup: dict[str, str],
    map_group_lookup: dict[str, str],
) -> list[GrottoMon]:
    text = trainer_report.strip_c_comments(HIDDEN_GROTTO_C.read_text(encoding="utf-8"))
    if "sHiddenGrottoData" in text:
        text = text.split("sHiddenGrottoData", 1)[1]
    if "sHiddenGrottoPokemonIndexes" in text:
        text = text.split("sHiddenGrottoPokemonIndexes", 1)[0]

    warp_sources = parse_grotto_warp_sources(map_group_lookup)
    mons: list[GrottoMon] = []
    seen_map_constants: set[str] = set()

    for grotto_id, body in split_hidden_grotto_entries(text):
        map_match = re.search(r"\.mapGroup\s*=\s*MAP_GROUP\((MAP_[A-Z0-9_]+)\)", body)
        level_match = re.search(r"\.monLevel\s*=\s*(\d+)", body)
        if not map_match or not level_match:
            continue
        map_constant = map_match.group(1)
        level = int(level_match.group(1))
        grotto_map = map_constant_to_name(map_constant, map_constant_lookup)
        source_maps = tuple(sorted(warp_sources.get(map_constant, set())))
        duplicate_map_constant = map_constant in seen_map_constants
        seen_map_constants.add(map_constant)

        in_scope = not duplicate_map_constant
        note = ""
        if duplicate_map_constant:
            in_scope = False
            note = "unreachable duplicate map constant"
        elif "UNUSED" in grotto_id and not source_maps:
            in_scope = False
            note = "unused hidden grotto entry"
        elif source_maps:
            in_scope = any(is_source_map_in_scope(source_map, map_group_lookup) for source_map in source_maps)
        else:
            in_scope = is_source_map_in_scope(grotto_map, map_group_lookup)

        for species in SPECIES_RE.findall(body):
            mons.append(
                GrottoMon(
                    species=species,
                    level=level,
                    grotto_id=grotto_id,
                    grotto_map=grotto_map,
                    source_maps=source_maps,
                    in_scope=in_scope,
                    note=note,
                )
            )

    return mons


def build_species_context() -> tuple[dict[str, trainer_report.SpeciesEntry], set[str]]:
    id_to_constant, _ = trainer_report.parse_species_constants()
    entries = trainer_report.parse_enabled_species(id_to_constant)
    species_to_family = trainer_report.parse_species_to_family()
    for constant, entry in entries.items():
        entry.family = species_to_family.get(constant, constant)
    trainer_report.assign_evolution_levels(entries)
    eligible = {entry.constant for entry in entries.values() if entry.target_eligible}
    return entries, eligible


def build_wild_stats(
    wild_slots: list[WildSlot],
    entries: dict[str, trainer_report.SpeciesEntry],
    eligible: set[str],
) -> tuple[dict[str, SpeciesWildStats], dict[str, MapProfile]]:
    stats: dict[str, SpeciesWildStats] = defaultdict(SpeciesWildStats)
    maps: dict[str, MapProfile] = {}
    for slot in wild_slots:
        if not slot.in_scope or slot.species not in eligible or slot.species not in entries:
            continue
        stats[slot.species].add(slot)
        maps.setdefault(slot.map_name, MapProfile(slot.map_name)).add(slot, entries)
    return stats, maps


def map_theme_types(map_name: str) -> set[str]:
    types: set[str] = set()
    display = format_map_name(map_name)
    for keyword, keyword_types in MAP_THEME_TYPES:
        if keyword in map_name or keyword in display:
            types.update(keyword_types)
    if re.match(r"Route(?:4[01]|2[09])\b", display):
        types.add("TYPE_WATER")
    return types


def level_gap_to_range(level: int, min_level: int, max_level: int) -> int:
    if min_level <= level <= max_level:
        return 0
    return min(abs(level - min_level), abs(level - max_level))


def source_state_for_species(
    species: str,
    wild_species: set[str],
    gift_species: set[str],
    grotto_species: set[str],
) -> str:
    if species in wild_species:
        return "Wild"
    if species in grotto_species and species not in gift_species:
        return "Grotto-only"
    if species in gift_species and species not in grotto_species:
        return "Gift-only"
    if species in gift_species and species in grotto_species:
        return "Gift + Grotto"
    return "Missing"


def species_source_levels(
    species: str,
    gifts_by_species: dict[str, list[GiftMon]],
    grottos_by_species: dict[str, list[GrottoMon]],
) -> list[int]:
    levels = [gift.level for gift in gifts_by_species.get(species, []) if gift.level is not None]
    levels.extend(grotto.level for grotto in grottos_by_species.get(species, []))
    return sorted(level for level in levels if level is not None)


def species_source_maps(
    species: str,
    gifts_by_species: dict[str, list[GiftMon]],
    grottos_by_species: dict[str, list[GrottoMon]],
) -> set[str]:
    maps = {gift.map_name for gift in gifts_by_species.get(species, []) if gift.map_name}
    for grotto in grottos_by_species.get(species, []):
        maps.update(grotto.source_maps)
    return {map_name for map_name in maps if map_name}


def pick_replace_species(
    profile: MapProfile,
    method: str,
    global_stats: dict[str, SpeciesWildStats],
    entries: dict[str, trainer_report.SpeciesEntry],
) -> str | None:
    species_slots = profile.method_species_slots.get(method, Counter())
    if not species_slots:
        return None

    def score(item: tuple[str, int]) -> tuple[int, float, int]:
        species, local_slots = item
        global_weight = global_stats.get(species, SpeciesWildStats()).effective_weight
        species_id = entries.get(species, trainer_report.SpeciesEntry(0, species, species, set(), ("TYPE_NORMAL", "TYPE_NORMAL"), 0)).species_id
        duplicate_bonus = 20 if local_slots > 1 else 0
        return duplicate_bonus + local_slots, global_weight, -species_id

    return max(species_slots.items(), key=score)[0]


def build_encounter_suggestions(
    entries: dict[str, trainer_report.SpeciesEntry],
    eligible: set[str],
    wild_stats: dict[str, SpeciesWildStats],
    map_profiles: dict[str, MapProfile],
    gifts_by_species: dict[str, list[GiftMon]],
    grottos_by_species: dict[str, list[GrottoMon]],
    limit: int,
) -> list[EncounterSuggestion]:
    wild_species = set(wild_stats)
    gift_species = set(gifts_by_species)
    grotto_species = set(grottos_by_species)
    candidates = sorted(
        (species for species in eligible if species not in wild_species and species in entries),
        key=lambda species: entries[species].species_id,
    )
    suggestions: list[EncounterSuggestion] = []

    for species in candidates:
        entry = entries[species]
        source_state = source_state_for_species(species, wild_species, gift_species, grotto_species)
        source_levels = species_source_levels(species, gifts_by_species, grottos_by_species)
        source_maps = species_source_maps(species, gifts_by_species, grottos_by_species)
        best: EncounterSuggestion | None = None

        for profile in map_profiles.values():
            if profile.slots == 0:
                continue
            species_types = set(entry.types)
            dominant_types = set(profile.dominant_types())
            keyword_types = map_theme_types(profile.map_name)
            overlap = species_types & (dominant_types | keyword_types)
            same_source_map = profile.map_name in source_maps
            if not overlap and not same_source_map and source_state != "Missing":
                continue
            if not overlap and source_state == "Missing" and "TYPE_NORMAL" not in species_types:
                continue

            for method in profile.candidate_methods(entry.types):
                method_min, method_max = profile.method_range(method)
                if method_min == 999:
                    continue
                if entry.min_stage_level > method_max + 3:
                    continue
                if entry.next_level_evo is not None and method_min > entry.next_level_evo + 12:
                    continue

                stage_gap = level_gap_to_range(entry.min_stage_level, method_min, method_max)
                source_level_gap = min(
                    (level_gap_to_range(level, method_min, method_max) for level in source_levels),
                    default=stage_gap,
                )
                if source_levels and source_level_gap > 12 and not same_source_map:
                    continue

                method_species = profile.method_species_slots.get(method, Counter())
                family_present = any(
                    entries.get(existing_species, entry).family == entry.family
                    for existing_species in method_species
                )
                duplicate_pressure = sum(max(0, count - 1) for count in method_species.values())
                score = 60
                score += 45 if same_source_map else 0
                score += 28 if species_types & keyword_types else 0
                score += 22 if species_types & dominant_types else 0
                score += 12 if not family_present else -6
                score += min(18, duplicate_pressure * 3)
                score += {"Grotto-only": 16, "Gift-only": 10, "Gift + Grotto": 14, "Missing": 4}.get(source_state, 0)
                score -= stage_gap * 2
                score -= source_level_gap
                if method == "land_mons":
                    score += 6

                replace_species = pick_replace_species(profile, method, wild_stats, entries)
                reason_bits = [
                    f"{profile.method_level_range(method)} {METHOD_LABELS.get(method, method)}",
                    f"{type_overlap_text(overlap)} fit",
                ]
                if same_source_map:
                    reason_bits.append("same map as current gift/grotto source")
                if not family_present:
                    reason_bits.append("family absent from this table")
                if replace_species:
                    reason_bits.append(
                        f"replace one {trainer_report.display_species(replace_species, entries)} slot"
                    )

                suggestion = EncounterSuggestion(
                    species=species,
                    map_name=profile.map_name,
                    method=METHOD_LABELS.get(method, method),
                    source_state=source_state,
                    score=score,
                    replace_species=replace_species,
                    reason="; ".join(reason_bits),
                )
                if best is None or (suggestion.score, -entries[species].species_id) > (best.score, -entries[species].species_id):
                    best = suggestion

        if best is not None:
            suggestions.append(best)

    suggestions.sort(
        key=lambda suggestion: (
            {"Grotto-only": 0, "Gift + Grotto": 1, "Gift-only": 2, "Missing": 3}.get(suggestion.source_state, 4),
            -suggestion.score,
            entries[suggestion.species].species_id,
        )
    )
    return suggestions[:limit]


def build_context(args: argparse.Namespace) -> dict[str, object]:
    entries, eligible = build_species_context()
    map_constant_lookup = build_map_constant_lookup()
    map_group_lookup = trainer_report.parse_map_group_lookup()

    wild_slots = parse_wild_slots(map_constant_lookup, map_group_lookup)
    gifts, unresolved_gifts = parse_gift_mons(map_group_lookup)
    grottos = parse_hidden_grotto_mons(map_constant_lookup, map_group_lookup)
    wild_stats, map_profiles = build_wild_stats(wild_slots, entries, eligible)

    gifts_by_species: dict[str, list[GiftMon]] = defaultdict(list)
    excluded_gifts = []
    for gift in gifts:
        if gift.species not in eligible or gift.species not in entries:
            continue
        if gift.in_scope:
            gifts_by_species[gift.species].append(gift)
        else:
            excluded_gifts.append(gift)

    grottos_by_species: dict[str, list[GrottoMon]] = defaultdict(list)
    excluded_grottos = []
    for grotto in grottos:
        if grotto.species not in eligible or grotto.species not in entries:
            continue
        if grotto.in_scope:
            grottos_by_species[grotto.species].append(grotto)
        else:
            excluded_grottos.append(grotto)

    wild_species = set(wild_stats)
    gift_species = set(gifts_by_species)
    grotto_species = set(grottos_by_species)
    available_species = wild_species | gift_species | grotto_species

    overrepresented = sorted(
        wild_species,
        key=lambda species: (
            -wild_stats[species].effective_weight,
            -wild_stats[species].slots,
            -len(wild_stats[species].maps),
            entries[species].species_id,
        ),
    )
    thin_wild = sorted(
        (
            species
            for species in wild_species
            if wild_stats[species].slots <= 2 or len(wild_stats[species].maps) <= 1
        ),
        key=lambda species: (
            wild_stats[species].min_level,
            wild_stats[species].slots,
            entries[species].species_id,
        ),
    )
    grotto_only = sorted(
        grotto_species - wild_species - gift_species,
        key=lambda species: (
            min(grotto.level for grotto in grottos_by_species[species]),
            entries[species].species_id,
        ),
    )
    gift_only = sorted(
        gift_species - wild_species - grotto_species,
        key=lambda species: (
            min(gift.level or 999 for gift in gifts_by_species[species]),
            entries[species].species_id,
        ),
    )
    missing = sorted(
        eligible - available_species,
        key=lambda species: (entries[species].min_stage_level, entries[species].species_id),
    )
    suggestions = build_encounter_suggestions(
        entries,
        eligible,
        wild_stats,
        map_profiles,
        gifts_by_species,
        grottos_by_species,
        args.suggestion_limit,
    )

    in_scope_wild_slots = [slot for slot in wild_slots if slot.in_scope and slot.species in eligible]
    out_of_scope_wild_slots = [slot for slot in wild_slots if not slot.in_scope and slot.species in eligible]

    return {
        "entries": entries,
        "eligible": eligible,
        "wild_slots": wild_slots,
        "wild_stats": wild_stats,
        "map_profiles": map_profiles,
        "gifts": gifts,
        "gifts_by_species": gifts_by_species,
        "grottos": grottos,
        "grottos_by_species": grottos_by_species,
        "overrepresented": overrepresented[: args.overrepresented_limit],
        "thin_wild": thin_wild[: args.missing_limit],
        "grotto_only": grotto_only,
        "gift_only": gift_only,
        "missing": missing[: args.missing_limit],
        "all_missing_count": len(missing),
        "suggestions": suggestions,
        "unresolved_gifts": unresolved_gifts,
        "excluded_gifts": excluded_gifts,
        "excluded_grottos": excluded_grottos,
        "counts": {
            "eligible": len(eligible),
            "wild_species": len(wild_species),
            "gift_species": len(gift_species),
            "grotto_species": len(grotto_species),
            "available_species": len(available_species),
            "missing_species": len(missing),
            "grotto_only": len(grotto_only),
            "gift_only": len(gift_only),
            "thin_wild": len(thin_wild),
            "wild_slots": len(in_scope_wild_slots),
            "wild_maps": len(map_profiles),
            "excluded_wild_slots": len(out_of_scope_wild_slots),
            "gift_events": sum(len(value) for value in gifts_by_species.values()),
            "grotto_entries": sum(len(value) for value in grottos_by_species.values()),
            "excluded_gifts": len(excluded_gifts),
            "excluded_grottos": len(excluded_grottos),
            "unresolved_gifts": len(unresolved_gifts),
        },
    }


def source_summary_for_species(
    species: str,
    gifts_by_species: dict[str, list[GiftMon]],
    grottos_by_species: dict[str, list[GrottoMon]],
) -> str:
    bits = []
    for gift in gifts_by_species.get(species, [])[:3]:
        level = "Egg" if gift.is_egg else f"L{gift.level}" if gift.level is not None else "L?"
        bits.append(f"{gift.location} {level}")
    for grotto in grottos_by_species.get(species, [])[:3]:
        locations = ", ".join(format_map_name(map_name) for map_name in grotto.source_maps) or format_map_name(grotto.grotto_map)
        bits.append(f"{locations} grotto L{grotto.level}")
    return "; ".join(bits) if bits else "-"


def make_markdown_report(args: argparse.Namespace) -> str:
    context = build_context(args)
    entries: dict[str, trainer_report.SpeciesEntry] = context["entries"]  # type: ignore[assignment]
    wild_stats: dict[str, SpeciesWildStats] = context["wild_stats"]  # type: ignore[assignment]
    gifts_by_species: dict[str, list[GiftMon]] = context["gifts_by_species"]  # type: ignore[assignment]
    grottos_by_species: dict[str, list[GrottoMon]] = context["grottos_by_species"]  # type: ignore[assignment]
    counts: dict[str, int] = context["counts"]  # type: ignore[assignment]

    lines: list[str] = []
    lines.append("# Species Availability Report")
    lines.append("")
    lines.append("Generated by `tools/analyze_species_availability.py`.")
    lines.append("")
    lines.append("## Scope")
    lines.append("")
    lines.append("- Uses enabled, non-legendary, non-mythical, non-battle-only-form species.")
    lines.append("- Reads `src/data/wild_encounters.json`, `givemon`/`giveegg`/`givenamedmon` calls in `.inc` files, and `src/hidden_grotto.c`.")
    lines.append("- Uses the same Emerald/Kanto/ship map exclusions as the trainer-party diversity report.")
    lines.append("- Skips the debug cheat gift script and unreachable duplicate hidden grotto rows from coverage totals.")
    lines.append("- Wild exposure uses slot rate multiplied by the table encounter rate; fishing rods are counted as separate rod pools.")
    lines.append("")
    lines.append("## Summary")
    lines.append("")
    lines.append("| Metric | Count |")
    lines.append("| --- | ---: |")
    for label, key in (
        ("Eligible enabled species", "eligible"),
        ("Species in scoped wild tables", "wild_species"),
        ("Species from scoped gift scripts", "gift_species"),
        ("Species from scoped hidden grottoes", "grotto_species"),
        ("Species available from any scoped source", "available_species"),
        ("Species missing from all scoped sources", "missing_species"),
        ("Hidden grotto only species", "grotto_only"),
        ("Gift only species", "gift_only"),
        ("Thin wild coverage species", "thin_wild"),
        ("Scoped wild slots", "wild_slots"),
        ("Scoped wild maps/tables", "wild_maps"),
        ("Out-of-scope wild slots ignored", "excluded_wild_slots"),
        ("Out-of-scope/debug gift events ignored", "excluded_gifts"),
        ("Unused hidden grotto mon entries ignored", "excluded_grottos"),
    ):
        lines.append(f"| {label} | {counts[key]} |")
    if counts["unresolved_gifts"]:
        lines.append(f"| Unresolved gift commands | {counts['unresolved_gifts']} |")
    lines.append("")

    lines.append("## Highest Wild Exposure")
    lines.append("")
    lines.append("| Species | Effective exposure | Slots | Maps | Levels | Methods | Example maps |")
    lines.append("| --- | ---: | ---: | ---: | --- | --- | --- |")
    for species in context["overrepresented"]:  # type: ignore[index]
        stats = wild_stats[species]
        lines.append(
            f"| {trainer_report.display_species(species, entries)} | {stats.effective_weight:.1f} | "
            f"{stats.slots} | {len(stats.maps)} | L{stats.min_level}-{stats.max_level} | "
            f"{trainer_report.compact_list(set(stats.methods), 3)} | {trainer_report.compact_list(stats.maps, 4)} |"
        )
    lines.append("")

    lines.append("## Hidden Grotto Only")
    lines.append("")
    lines.append("| Species | Types | Sources | Stage floor |")
    lines.append("| --- | --- | --- | ---: |")
    for species in context["grotto_only"]:  # type: ignore[index]
        entry = entries[species]
        lines.append(
            f"| {trainer_report.display_species(species, entries)} | {trainer_report.type_names(entry.types)} | "
            f"{source_summary_for_species(species, gifts_by_species, grottos_by_species)} | {entry.min_stage_level} |"
        )
    lines.append("")

    lines.append("## Gift Only")
    lines.append("")
    lines.append("| Species | Types | Sources | Stage floor |")
    lines.append("| --- | --- | --- | ---: |")
    for species in context["gift_only"]:  # type: ignore[index]
        entry = entries[species]
        lines.append(
            f"| {trainer_report.display_species(species, entries)} | {trainer_report.type_names(entry.types)} | "
            f"{source_summary_for_species(species, gifts_by_species, grottos_by_species)} | {entry.min_stage_level} |"
        )
    lines.append("")

    lines.append("## Suggested Encounter Table Adds")
    lines.append("")
    lines.append("| Species | Source state | Suggested table | Method | Replace | Why |")
    lines.append("| --- | --- | --- | --- | --- | --- |")
    for suggestion in context["suggestions"]:  # type: ignore[index]
        replace = trainer_report.display_species(suggestion.replace_species, entries) if suggestion.replace_species else "-"
        lines.append(
            f"| {trainer_report.display_species(suggestion.species, entries)} | {suggestion.source_state} | "
            f"{format_map_name(suggestion.map_name)} | {suggestion.method} | {replace} | {suggestion.reason} |"
        )
    lines.append("")

    lines.append("## Missing From All Scoped Sources")
    lines.append("")
    lines.append("| Species | Types | Stage floor | Family |")
    lines.append("| --- | --- | ---: | --- |")
    for species in context["missing"]:  # type: ignore[index]
        entry = entries[species]
        lines.append(
            f"| {trainer_report.display_species(species, entries)} | {trainer_report.type_names(entry.types)} | "
            f"{entry.min_stage_level} | {clean_family_name(entry.family)} |"
        )
    omitted = context["all_missing_count"] - len(context["missing"])  # type: ignore[operator,arg-type]
    if omitted > 0:
        lines.append(f"| ... | ... | {omitted} more omitted by `--missing-limit` | ... |")
    lines.append("")

    if context["unresolved_gifts"]:  # type: ignore[index]
        lines.append("## Unresolved Gift Commands")
        lines.append("")
        for unresolved in context["unresolved_gifts"]:  # type: ignore[index]
            lines.append(f"- `{unresolved}`")
        lines.append("")

    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description="Analyze wild, gift, and hidden grotto species availability.")
    parser.add_argument("-o", "--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--overrepresented-limit", type=int, default=60)
    parser.add_argument("--missing-limit", type=int, default=120)
    parser.add_argument("--suggestion-limit", type=int, default=80)
    args = parser.parse_args()

    output_path = args.output
    if not output_path.is_absolute():
        output_path = REPO_ROOT / output_path
    output_path.write_text(make_markdown_report(args), encoding="utf-8")
    print(f"Wrote {output_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
