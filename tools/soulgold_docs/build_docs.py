#!/usr/bin/env python3

from __future__ import annotations

import json
import re
import shutil
import subprocess
import ast
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

from PIL import Image


REPO_ROOT = Path(__file__).resolve().parents[2]
SRC_DIR = REPO_ROOT / "docs" / "src"
OUT_DIR = REPO_ROOT / "docs"
TYPE_GRAPHICS_DIR = REPO_ROOT / "graphics/types"

SPECIES_H = REPO_ROOT / "include/constants/species.h"
POKEDEX_H = REPO_ROOT / "include/constants/pokedex.h"
MOVES_H = REPO_ROOT / "include/constants/moves.h"
ABILITIES_H = REPO_ROOT / "include/constants/abilities.h"
TYPES_H = REPO_ROOT / "include/constants/pokemon.h"
TMS_HMS_H = REPO_ROOT / "include/constants/tms_hms.h"
ITEMS_H = REPO_ROOT / "include/constants/items.h"
TRAINERS_H = REPO_ROOT / "src/data/trainers.party"
GRAPHICS_POKEMON_H = REPO_ROOT / "src/data/graphics/pokemon.h"
TRAINER_FRONT_PIC_DIR = REPO_ROOT / "graphics/trainers/front_pics"
WILD_ENCOUNTERS_JSON = REPO_ROOT / "src/data/wild_encounters.json"

STAT_FIELDS = {
    "baseHP": "hp",
    "baseAttack": "atk",
    "baseDefense": "def",
    "baseSpAttack": "spa",
    "baseSpDefense": "spd",
    "baseSpeed": "spe",
}

ENCOUNTER_SLOT_RATES = {
    "land_mons": [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1],
    "water_mons": [60, 30, 5, 4, 1],
    "rock_smash_mons": [60, 30, 5, 4, 1],
    "fishing_mons": [70, 30, 60, 20, 20, 40, 40, 15, 4, 1],
}

JOHTO_ROUTE_PROGRESS = {
    route: index
    for index, route in enumerate([29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48])
}

TYPE_ICON_FILES = {
    "TYPE_NONE": "none.png",
    "TYPE_NORMAL": "normal.png",
    "TYPE_FIGHTING": "fight.png",
    "TYPE_FLYING": "flying.png",
    "TYPE_POISON": "poison.png",
    "TYPE_GROUND": "ground.png",
    "TYPE_ROCK": "rock.png",
    "TYPE_BUG": "bug.png",
    "TYPE_GHOST": "ghost.png",
    "TYPE_STEEL": "steel.png",
    "TYPE_MYSTERY": "mystery.png",
    "TYPE_FIRE": "fire.png",
    "TYPE_WATER": "water.png",
    "TYPE_GRASS": "grass.png",
    "TYPE_ELECTRIC": "electric.png",
    "TYPE_PSYCHIC": "psychic.png",
    "TYPE_ICE": "ice.png",
    "TYPE_DRAGON": "dragon.png",
    "TYPE_DARK": "dark.png",
    "TYPE_FAIRY": "fairy.png",
    "TYPE_STELLAR": "stellar.png",
}

DEX_HIDDEN_SPECIES = {
    "SPECIES_MIMIKYU_BUSTED",
    "SPECIES_MIMIKYU_BUSTED_TOTEM",
    "SPECIES_MIMIKYU_TOTEM_DISGUISED",
    "SPECIES_MIMIKYU_TOTEM_BUSTED",
}

DEX_HIDDEN_PREFIXES = (
    "SPECIES_ARCEUS_",
    "SPECIES_UNOWN_",
)

DEX_HIDDEN_COLOR_FORMS = {
    "SPECIES_FLABEBE_YELLOW",
    "SPECIES_FLABEBE_ORANGE",
    "SPECIES_FLABEBE_BLUE",
    "SPECIES_FLABEBE_WHITE",
    "SPECIES_FLOETTE_YELLOW",
    "SPECIES_FLOETTE_ORANGE",
    "SPECIES_FLOETTE_BLUE",
    "SPECIES_FLOETTE_WHITE",
    "SPECIES_FLORGES_YELLOW",
    "SPECIES_FLORGES_ORANGE",
    "SPECIES_FLORGES_BLUE",
    "SPECIES_FLORGES_WHITE",
}

SPECIES_NAME_OVERRIDES = {
    "SPECIES_FLOETTE_ETERNAL": "Floette Eternal",
}

ITEMS_HIDDEN_SORT_TYPES = {
    "ITEM_TYPE_Z_CRYSTAL",
}

SPRITE_CACHE_VERSION = "alpha2"

GENERIC_MEGA_STONE_ITEMS = {
    "ITEM_NORMALITE",
    "ITEM_FIRETITE",
    "ITEM_WATERTITE",
    "ITEM_ELECTRITE",
    "ITEM_GRASSTITE",
    "ITEM_ICETITE",
    "ITEM_FIGHTITE",
    "ITEM_POISONTITE",
    "ITEM_GROUNDITE",
    "ITEM_FLYINGITE",
    "ITEM_PSYCHITE",
    "ITEM_BUGTITE",
    "ITEM_ROCKTITE",
    "ITEM_GHOSTITE",
    "ITEM_DRAGOTITE",
    "ITEM_DARKTITE",
    "ITEM_STEELTITE",
    "ITEM_FAIRYTITE",
    "ITEM_BONDSTONE",
}

IMPORTANT_ITEM_POCKETS = {
    "POCKET_BATTLE_ITEMS",
}


@dataclass
class SpeciesRow:
    id: int
    constant: str
    name: str
    nat_dex: int
    display_dex: int
    dex_visible: bool
    types: list[str]
    stats: dict[str, int]
    abilities: list[str]
    innates: list[str]
    level_up_symbol: str | None
    teachable_symbol: str | None
    front_pic_symbol: str | None
    sprite: str | None = None
    level_up: list[dict[str, Any]] = field(default_factory=list)
    tmhm: list[str] = field(default_factory=list)
    tutors: list[str] = field(default_factory=list)
    evolutions: list[dict[str, str]] = field(default_factory=list)
    locations: list[dict[str, Any]] = field(default_factory=list)


def read(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def clean_constant_name(value: str, prefix: str) -> str:
    return value.removeprefix(prefix).replace("_", " ").title()


def format_identifier_name(value: str) -> str:
    value = value.removeprefix("MAP_")
    value = re.sub(r"([a-z])([A-Z])", r"\1 \2", value)
    value = value.replace("_", " ")
    value = re.sub(r"([A-Za-z]+)(\d+)", r"\1 \2", value)
    value = re.sub(r"\b([BF]) (\d+)([FR])\b", r"\1\2\3", value)
    value = re.sub(r"\b([A-Z])\s+(\d)\b", r"\1\2", value)
    return value.title().replace("Tm", "TM").replace("Hm", "HM")


def normalize_token(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", value.lower())


def slugify(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "_", value.lower()).strip("_")


def decode_c_string(value: str) -> str:
    value = value.replace("\\p", "\\n\\n")
    try:
        decoded = ast.literal_eval(f'"{value}"')
    except (SyntaxError, ValueError):
        decoded = value.replace("\\n", " ")
    decoded = decoded.replace("\n", " ")
    decoded = decoded.replace("{PKMN}", "Pokemon")
    decoded = decoded.replace("{POKEBLOCK}", "Pokeblock")
    decoded = decoded.replace("♀", " F").replace("♂", " M")
    decoded = decoded.replace("é", "e")
    return decoded.strip()


def collect_strings(expr: str) -> str:
    parts = re.findall(r'"((?:[^"\\]|\\.)*)"', expr)
    decoded = [decode_c_string(part) for part in parts]
    if decoded and len(set(decoded)) == 1:
        decoded = decoded[:1]
    return re.sub(r"\s+", " ", " ".join(decoded)).strip()


def is_dex_visible_species(constant: str) -> bool:
    if "_TOTEM" in constant:
        return False
    if constant in DEX_HIDDEN_SPECIES or constant in DEX_HIDDEN_COLOR_FORMS:
        return False
    if any(constant.startswith(prefix) for prefix in DEX_HIDDEN_PREFIXES):
        return constant == "SPECIES_ARCEUS_NORMAL"
    return True


def strip_c_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
    return re.sub(r"//.*", "", text)


def parse_define_constants(path: Path, prefix: str) -> tuple[dict[str, int], dict[int, str]]:
    name_to_id: dict[str, int] = {}
    id_to_name: dict[int, str] = {}
    pattern = re.compile(rf"^\s*#define\s+({prefix}[A-Z0-9_]+)\s+(\d+)\b")
    for line in read(path).splitlines():
        match = pattern.match(line)
        if not match:
            continue
        name, value = match.group(1), int(match.group(2))
        name_to_id[name] = value
        id_to_name[value] = name
    return name_to_id, id_to_name


def parse_enum_constants(path: Path, prefix: str) -> tuple[dict[str, int], dict[int, str]]:
    name_to_id: dict[str, int] = {}
    id_to_name: dict[int, str] = {}
    next_value = 0
    pattern = re.compile(rf"\b({prefix}[A-Z0-9_]+)\b(?:\s*=\s*([^,/\n]+))?")
    for raw in read(path).splitlines():
        line = raw.split("//", 1)[0].strip()
        if not line or line.startswith("#"):
            continue
        match = pattern.search(line)
        if not match:
            continue
        name, expr = match.groups()
        if expr:
            expr = expr.strip()
            if expr.isdigit():
                next_value = int(expr)
            elif expr in name_to_id:
                name_to_id[name] = name_to_id[expr]
                continue
            else:
                continue
        name_to_id[name] = next_value
        id_to_name.setdefault(next_value, name)
        next_value += 1
    return name_to_id, id_to_name


def preprocess(include_path: str) -> str:
    temp = Path("/tmp/soulgold_docs_preprocess.c")
    temp.write_text(f'#include "global.h"\n#include "{include_path}"\n', encoding="utf-8")
    result = subprocess.run(
        ["gcc", "-E", "-P", str(temp), "-I.", "-Iinclude", "-Isrc"],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        raise RuntimeError(f"gcc failed for {include_path}:\n{result.stderr}")
    return result.stdout


def split_designated_entries(text: str) -> dict[str, str]:
    entries: dict[str, str] = {}
    lines = text.splitlines()
    current_key: str | None = None
    current: list[str] = []
    depth = 0
    entry_re = re.compile(r"^\s*\[\s*([A-Z0-9_]+|\d+)\s*\]\s*=")

    for line in lines:
        if current_key is None:
            match = entry_re.match(line)
            if not match:
                continue
            current_key = match.group(1)
            current = [line]
            depth = line.count("{") - line.count("}")
            if "{" in line and depth <= 0:
                entries[current_key] = "\n".join(current)
                current_key = None
                current = []
            continue

        current.append(line)
        depth += line.count("{") - line.count("}")
        if depth <= 0:
            entries[current_key] = "\n".join(current)
            current_key = None
            current = []
    return entries


def extract_field(entry: str, field_name: str) -> str | None:
    match = re.search(rf"\.{field_name}\s*=", entry)
    if not match:
        return None
    start = match.end()
    depth = 0
    for index in range(start, len(entry)):
        char = entry[index]
        if char in "({":
            depth += 1
        elif char in ")}":
            depth -= 1
        elif char == "," and depth <= 0:
            return entry[start:index].strip()
    return None


def split_top_level_ternary(expr: str) -> tuple[str, str, str] | None:
    depth = 0
    question_index: int | None = None
    nested = 0
    for index, char in enumerate(expr):
        if char in "({[":
            depth += 1
        elif char in ")}]":
            depth -= 1
        elif depth == 0 and char == "?":
            if question_index is None:
                question_index = index
            else:
                nested += 1
        elif depth == 0 and char == ":" and question_index is not None:
            if nested:
                nested -= 1
                continue
            return expr[:question_index], expr[question_index + 1:index], expr[index + 1:]
    return None


def eval_numeric_ast(node: ast.AST) -> int | bool:
    if isinstance(node, ast.Expression):
        return eval_numeric_ast(node.body)
    if isinstance(node, ast.Constant) and isinstance(node.value, (int, bool)):
        return node.value
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, (ast.UAdd, ast.USub, ast.Not)):
        value = eval_numeric_ast(node.operand)
        if isinstance(node.op, ast.UAdd):
            return int(value)
        if isinstance(node.op, ast.USub):
            return -int(value)
        return not bool(value)
    if isinstance(node, ast.BinOp) and isinstance(node.op, (ast.Add, ast.Sub, ast.Mult, ast.Div, ast.FloorDiv, ast.Mod)):
        left = int(eval_numeric_ast(node.left))
        right = int(eval_numeric_ast(node.right))
        if isinstance(node.op, ast.Add):
            return left + right
        if isinstance(node.op, ast.Sub):
            return left - right
        if isinstance(node.op, ast.Mult):
            return left * right
        if isinstance(node.op, (ast.Div, ast.FloorDiv)):
            return left // right
        return left % right
    if isinstance(node, ast.BoolOp) and isinstance(node.op, (ast.And, ast.Or)):
        values = [bool(eval_numeric_ast(value)) for value in node.values]
        return all(values) if isinstance(node.op, ast.And) else any(values)
    if isinstance(node, ast.Compare):
        left = eval_numeric_ast(node.left)
        for op, comparator in zip(node.ops, node.comparators):
            right = eval_numeric_ast(comparator)
            if isinstance(op, ast.Eq) and not left == right:
                return False
            if isinstance(op, ast.NotEq) and not left != right:
                return False
            if isinstance(op, ast.Lt) and not left < right:
                return False
            if isinstance(op, ast.LtE) and not left <= right:
                return False
            if isinstance(op, ast.Gt) and not left > right:
                return False
            if isinstance(op, ast.GtE) and not left >= right:
                return False
            left = right
        return True
    raise ValueError(f"unsupported expression: {ast.dump(node)}")


def eval_int_expr(expr: str) -> int | None:
    expr = expr.strip()
    while expr.startswith("(") and expr.endswith(")"):
        depth = 0
        encloses_expr = True
        for index, char in enumerate(expr):
            if char == "(":
                depth += 1
            elif char == ")":
                depth -= 1
                if depth == 0 and index != len(expr) - 1:
                    encloses_expr = False
                    break
        if not encloses_expr:
            break
        expr = expr[1:-1].strip()

    ternary = split_top_level_ternary(expr)
    if ternary:
        condition, true_expr, false_expr = ternary
        branch = true_expr if eval_int_expr(condition) else false_expr
        return eval_int_expr(branch)

    expr = re.sub(r"\b([0-9]+)[uUlL]+\b", r"\1", expr)
    expr = expr.replace("&&", " and ").replace("||", " or ")
    expr = re.sub(r"!(?!=)", " not ", expr)
    if re.search(r"[A-Za-z_]", expr):
        return None
    try:
        return int(eval_numeric_ast(ast.parse(expr, mode="eval")))
    except (SyntaxError, ValueError, ZeroDivisionError):
        return None


def extract_number(entry: str, field_name: str, default: int = 0) -> int:
    expr = extract_field(entry, field_name)
    if not expr:
        return default
    value = eval_int_expr(expr)
    if value is not None:
        return value
    match = re.search(r"-?\d+", expr)
    return int(match.group(0)) if match else default


def extract_braced_constants(entry: str, field_name: str, prefix: str) -> list[str]:
    expr = extract_field(entry, field_name) or ""
    return re.findall(rf"\b{prefix}[A-Z0-9_]+\b", expr)


def parse_shared_strings(text: str) -> dict[str, str]:
    shared: dict[str, str] = {}
    pattern = re.compile(
        r"(?:static\s+)?const\s+u8\s+([A-Za-z0-9_]+)\[\]\s*=\s*(?:_|COMPOUND_STRING)\((.*?)\);",
        re.DOTALL,
    )
    for name, expr in pattern.findall(text):
        shared[name] = collect_strings(expr)
    return shared


def parse_named_table(
    include_path: str,
    key_prefix: str,
    name_prefix: str,
) -> dict[str, dict[str, Any]]:
    text = preprocess(include_path)
    source_path = REPO_ROOT / include_path
    if not source_path.exists():
        source_path = REPO_ROOT / "src" / include_path
    source_text = read(source_path)
    shared_strings = parse_shared_strings(source_text)
    entries = split_designated_entries(text)
    rows: dict[str, dict[str, Any]] = {}

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


def parse_species() -> tuple[list[SpeciesRow], dict[str, SpeciesRow]]:
    species_to_id, id_to_species = parse_define_constants(SPECIES_H, "SPECIES_")
    nat_to_id, _ = parse_enum_constants(POKEDEX_H, "NATIONAL_DEX_")
    text = preprocess("data/pokemon/species_info.h")
    entries = split_designated_entries(text)
    rows: list[SpeciesRow] = []
    by_constant: dict[str, SpeciesRow] = {}

    for key, entry in entries.items():
        if not key.isdigit():
            continue
        species_id = int(key)
        constant = id_to_species.get(species_id)
        if not constant or constant in {"SPECIES_NONE", "SPECIES_EGG"}:
            continue
        name = SPECIES_NAME_OVERRIDES.get(
            constant,
            collect_strings(extract_field(entry, "speciesName") or "") or clean_constant_name(constant, "SPECIES_"),
        )
        nat_expr = extract_field(entry, "natDexNum") or "NATIONAL_DEX_NONE"
        nat_const = re.search(r"\bNATIONAL_DEX_[A-Z0-9_]+\b", nat_expr)
        if nat_const:
            species_nat_const = nat_const.group(0).replace("NATIONAL_DEX_", "SPECIES_")
            nat_dex = species_to_id.get(species_nat_const, nat_to_id.get(nat_const.group(0), 0))
        else:
            nat_dex = extract_number(entry, "natDexNum")
        stats = {short: extract_number(entry, field_name) for field_name, short in STAT_FIELDS.items()}
        types = extract_braced_constants(entry, "types", "TYPE_") or ["TYPE_NORMAL"]
        if len(types) == 1:
            types.append(types[0])
        abilities = [a for a in extract_braced_constants(entry, "abilities", "ABILITY_") if a != "ABILITY_NONE"]
        innates = [a for a in extract_braced_constants(entry, "innates", "ABILITY_") if a != "ABILITY_NONE"]
        level_expr = extract_field(entry, "levelUpLearnset") or ""
        teach_expr = extract_field(entry, "teachableLearnset") or ""
        front_expr = extract_field(entry, "frontPic") or ""
        level_symbol = re.search(r"\bs[A-Za-z0-9_]+LevelUpLearnset\b", level_expr)
        teach_symbol = re.search(r"\bs[A-Za-z0-9_]+TeachableLearnset\b", teach_expr)
        front_symbol = re.search(r"\bgMonFrontPic_[A-Za-z0-9_]+\b", front_expr)
        row = SpeciesRow(
            id=species_id,
            constant=constant,
            name=name,
            nat_dex=nat_dex,
            display_dex=0,
            dex_visible=is_dex_visible_species(constant),
            types=types[:2],
            stats=stats,
            abilities=abilities,
            innates=innates,
            level_up_symbol=level_symbol.group(0) if level_symbol else None,
            teachable_symbol=teach_symbol.group(0) if teach_symbol else None,
            front_pic_symbol=front_symbol.group(0) if front_symbol else None,
        )
        rows.append(row)
        by_constant[constant] = row

    rows.sort(key=lambda row: (row.nat_dex if row.nat_dex else 99999, row.id))
    display_by_nat_dex: dict[int, int] = {}
    for row in rows:
        if not row.nat_dex or not row.dex_visible:
            continue
        if row.nat_dex not in display_by_nat_dex:
            display_by_nat_dex[row.nat_dex] = len(display_by_nat_dex) + 1
        row.display_dex = display_by_nat_dex[row.nat_dex]
    for row in rows:
        if row.display_dex or not row.nat_dex:
            continue
        row.display_dex = display_by_nat_dex.get(row.nat_dex, 0)
    return rows, by_constant


def parse_level_up_learnsets() -> dict[str, list[dict[str, Any]]]:
    learnsets: dict[str, list[dict[str, Any]]] = {}
    text = "\n".join(read(path) for path in sorted((REPO_ROOT / "src/data/pokemon/level_up_learnsets").glob("gen_*.h")))
    pattern = re.compile(r"static\s+const\s+struct\s+LevelUpMove\s+(s[A-Za-z0-9_]+LevelUpLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = []
        for level, move in re.findall(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)", body):
            moves.append({"level": int(level), "move": move})
        learnsets[symbol] = moves
    return learnsets


def parse_teachable_learnsets(tmhm_moves: set[str]) -> dict[str, dict[str, list[str]]]:
    text = read(REPO_ROOT / "src/data/pokemon/teachable_learnsets.h")
    learnsets: dict[str, dict[str, list[str]]] = {}
    pattern = re.compile(r"static\s+const\s+u16\s+(s[A-Za-z0-9_]+TeachableLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = [move for move in re.findall(r"\bMOVE_[A-Z0-9_]+\b", body) if move != "MOVE_UNAVAILABLE"]
        learnsets[symbol] = {
            "tmhm": [move for move in moves if move in tmhm_moves],
            "tutors": [move for move in moves if move not in tmhm_moves],
        }
    return learnsets


def split_top_level_braces(text: str) -> list[str]:
    chunks: list[str] = []
    depth = 0
    start: int | None = None
    for index, char in enumerate(text):
        if char == "{":
            if depth == 0:
                start = index + 1
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0 and start is not None:
                chunks.append(text[start:index])
                start = None
    return chunks


def split_top_level_commas(text: str) -> list[str]:
    chunks: list[str] = []
    depth = 0
    start = 0
    for index, char in enumerate(text):
        if char in "{(":
            depth += 1
        elif char in "})":
            depth -= 1
        elif char == "," and depth == 0:
            chunks.append(text[start:index].strip())
            start = index + 1
    chunks.append(text[start:].strip())
    return chunks


def extract_balanced_call(text: str, start: int) -> str | None:
    open_index = text.find("(", start)
    if open_index == -1:
        return None
    depth = 0
    for index in range(open_index, len(text)):
        if text[index] == "(":
            depth += 1
        elif text[index] == ")":
            depth -= 1
            if depth == 0:
                return text[open_index + 1:index]
    return None


def format_evolution_method(method: str, param: str, item_names: dict[str, dict[str, str]]) -> str:
    if method in {"EVO_LEVEL", "EVO_LEVEL_BATTLE_ONLY"}:
        return f"Level Up ({param})" if param and param != "0" else "Level Up"
    if method == "EVO_ITEM":
        item_name = item_names.get(param, {}).get("name") or clean_constant_name(param, "ITEM_")
        return f"By Using Specific Item ({item_name})"
    if method == "EVO_TRADE":
        return "Trade"
    if method == "EVO_FRIENDSHIP":
        return "Friendship"
    if method == "EVO_MOVE":
        return f"Knowing {clean_constant_name(param, 'MOVE_')}"
    if method == "EVO_NONE":
        return "Special"
    return clean_constant_name(method, "EVO_")


def parse_evolutions(item_names: dict[str, dict[str, str]]) -> dict[str, list[dict[str, str]]]:
    evolutions: dict[str, list[dict[str, str]]] = defaultdict(list)
    entry_re = re.compile(r"\[\s*(SPECIES_[A-Z0-9_]+)\s*\]\s*=")
    for path in sorted((REPO_ROOT / "src/data/pokemon/species_info").glob("gen_*_families.h")):
        text = strip_c_comments(read(path))
        matches = list(entry_re.finditer(text))
        for index, match in enumerate(matches):
            source = match.group(1)
            end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
            block = text[match.end():end]
            evo_index = block.find(".evolutions")
            if evo_index == -1:
                continue
            call_index = block.find("EVOLUTION", evo_index)
            if call_index == -1:
                continue
            body = extract_balanced_call(block, call_index)
            if body is None:
                continue
            for chunk in split_top_level_braces(body):
                parts = split_top_level_commas(chunk)
                if len(parts) < 3:
                    continue
                method, param, target = parts[0], parts[1], parts[2]
                if method == "EVOLUTIONS_END" or not target.startswith("SPECIES_"):
                    continue
                evolutions[source].append({
                    "method": method,
                    "param": param,
                    "target": target,
                    "label": format_evolution_method(method, param, item_names),
                })
    return dict(evolutions)


def parse_tmhm_list() -> list[dict[str, Any]]:
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


def parse_item_records() -> dict[str, dict[str, Any]]:
    text = preprocess("data/items.h")
    source_text = read(REPO_ROOT / "src/data/items.h")
    shared_strings = parse_shared_strings(source_text)
    item_to_id, _ = parse_enum_constants(ITEMS_H, "ITEM_")
    entries = split_designated_entries(text)
    records: dict[str, dict[str, Any]] = {}
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
        records[key] = {
            "id": item_to_id.get(key, 0),
            "constant": key,
            "name": collect_strings(extract_field(entry, "name") or ""),
            "description": description,
            "pocket": pocket_match.group(0) if pocket_match else "",
            "sortType": sort_type_match.group(0) if sort_type_match else "",
        }
    return records


def add_location(
    locations: dict[str, list[dict[str, str]]],
    item: str,
    map_name: str,
    source: str,
) -> None:
    entry = {"map": map_name, "source": source}
    if entry not in locations[item]:
        locations[item].append(entry)


def format_item_location(map_data: dict[str, Any], fallback_name: str, source: str) -> tuple[str, str]:
    if map_data.get("layout") == "LAYOUT_MAUVILLE_CITY_GAME_CORNER":
        return "Goldenrod City Game Corner", "Bought"
    return format_identifier_name(map_data.get("name") or fallback_name), source


def format_tmhm_location(map_data: dict[str, Any], fallback_name: str, source: str) -> tuple[str, str]:
    return format_item_location(map_data, fallback_name, source)


def parse_tmhm_locations() -> dict[str, list[dict[str, str]]]:
    locations: dict[str, list[dict[str, str]]] = defaultdict(list)
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


def parse_item_locations(item_constants: set[str]) -> dict[str, list[dict[str, str]]]:
    locations: dict[str, list[dict[str, str]]] = defaultdict(list)
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


def build_important_items(item_records: dict[str, dict[str, Any]]) -> list[dict[str, Any]]:
    selected = {
        constant
        for constant, item in item_records.items()
        if (item.get("pocket") in IMPORTANT_ITEM_POCKETS or constant in GENERIC_MEGA_STONE_ITEMS)
        and item.get("sortType") not in ITEMS_HIDDEN_SORT_TYPES
    }
    locations = parse_item_locations(selected)
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
            "locations": item_locations,
            "location": "; ".join(
                f"{entry['map']} ({entry['source']})"
                for entry in item_locations
            ),
        })
    return rows


def parse_front_pic_sources() -> dict[str, Path]:
    pic_map: dict[str, Path] = {}
    pattern = re.compile(r'const\s+u32\s+(gMonFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\("([^"]+)"\);')
    for symbol, incbin in pattern.findall(read(GRAPHICS_POKEMON_H)):
        if symbol in pic_map and "_gba" in incbin:
            continue
        png = REPO_ROOT / re.sub(r"(?:_gba)?\.4bpp(?:\.smol)?$", ".png", incbin)
        if png.exists():
            pic_map[symbol] = png
    return pic_map


def process_sprite(source: Path, target: Path) -> None:
    target.parent.mkdir(parents=True, exist_ok=True)
    image = Image.open(source)
    if image.mode != "P":
        image = image.convert("P")
    frame = image.crop((0, 0, min(64, image.width), min(64, image.height)))
    rgba = frame.convert("RGBA")
    pixels = []
    for y in range(frame.height):
        for x in range(frame.width):
            pixel = rgba.getpixel((x, y))
            pixels.append((pixel[0], pixel[1], pixel[2], 0) if frame.getpixel((x, y)) == 0 else pixel)
    rgba.putdata(pixels)
    rgba.save(target)


def copy_type_icons() -> dict[str, str]:
    output_dir = OUT_DIR / "sprites" / "types"
    output_dir.mkdir(parents=True, exist_ok=True)
    icons: dict[str, str] = {}
    for type_constant, filename in TYPE_ICON_FILES.items():
        source = TYPE_GRAPHICS_DIR / filename
        if not source.exists():
            continue
        target = output_dir / filename
        shutil.copy2(source, target)
        icons[type_constant] = str(target.relative_to(OUT_DIR))
    return icons


def parse_wild_encounters(by_species: dict[str, SpeciesRow]) -> list[dict[str, Any]]:
    data = json.loads(read(WILD_ENCOUNTERS_JSON))
    rows = []
    original_index = 0
    for group in data.get("wild_encounter_groups", []):
        if group.get("label") == "gBattlePyramidWildMonHeaders":
            continue
        for encounter in group.get("encounters", []):
            map_const = encounter.get("map", "UNKNOWN_MAP")
            label = map_const.removeprefix("MAP_").replace("_", " ").title()
            base_label = encounter.get("base_label", "")
            time_label = "Night" if base_label.endswith("_Night") else "Day"
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


def merge_time_variant_encounters(rows: list[dict[str, Any]]) -> list[dict[str, Any]]:
    merged: dict[tuple[str, str], dict[str, Any]] = {}
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


def wild_encounter_sort_key(encounter: dict[str, Any]) -> tuple[int, int, int]:
    haystack = f"{encounter.get('map', '')} {encounter.get('baseLabel', '')} {encounter.get('name', '')}"
    match = re.search(r"\b(?:MAP_)?ROUTE_?(\d+)\b|\bRoute\s*(\d+)\b|\bgRoute(\d+)\b", haystack, re.IGNORECASE)
    route = int(next(group for group in match.groups() if group)) if match else None
    if route in JOHTO_ROUTE_PROGRESS:
        return (0, JOHTO_ROUTE_PROGRESS[route], encounter["_order"])
    return (1, encounter["_order"], 0)


def build_species_locations(encounters: list[dict[str, Any]]) -> dict[str, list[dict[str, Any]]]:
    locations: dict[str, list[dict[str, Any]]] = defaultdict(list)
    seen: dict[str, set[tuple[Any, ...]]] = defaultdict(set)
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


def parse_showdown_team(text: str) -> list[dict[str, Any]]:
    """Parse a Pokemon Showdown export string into a list of Pokemon dicts."""
    mons = []
    current: dict[str, Any] | None = None
    for raw_line in text.splitlines():
        line = raw_line.strip()
        if not line:
            if current is not None:
                mons.append(current)
                current = None
            continue

        # First non-empty line of a new mon: "Name @ Item" or just "Name"
        if current is None:
            if line.startswith("-") or ":" in line.split("@")[0]:
                # Looks like a move or field line without a header — malformed, skip
                continue
            if "@" in line:
                name_part, item_part = line.split("@", 1)
            else:
                name_part, item_part = line, ""
            species_match = re.search(r"\((SPECIES_[A-Z0-9_]+|[A-Za-z][A-Za-z0-9_ -]+)\)", name_part)
            # Strip gender marker e.g. "(M)"
            name_clean = re.sub(r"\s*\([MF]\)\s*", " ", name_part).strip()
            if species_match and species_match.group(1) not in {"M", "F"}:
                name_clean = species_match.group(1).strip()
            current = {
                "name": name_clean,
                "item": item_part.strip(),
                "level": 100,
                "ability": "",
                "nature": "",
                "evs": {},
                "ivs": {},
                "moves": [],
            }
            continue

        # Move line
        if line.startswith("-"):
            move = line.lstrip("- ").strip()
            if move:
                current["moves"].append(move)
            continue

        if ":" in line:
            key, _, value = line.partition(":")
            key = key.strip().lower()
            value = value.strip()
            if key == "ability":
                current["ability"] = value
            elif key == "level":
                level = eval_int_expr(value)
                current["level"] = level if level is not None else 100
            elif key == "nature" or line.endswith("Nature"):
                current["nature"] = value.replace("Nature", "").strip()
            elif key == "evs":
                current["evs"] = _parse_stat_spread(value)
            elif key == "ivs":
                current["ivs"] = _parse_stat_spread(value)
            continue

        # "Modest Nature" style (no colon)
        if line.endswith("Nature"):
            current["nature"] = line.replace("Nature", "").strip()

    if current is not None:
        mons.append(current)
    return mons


def _parse_stat_spread(text: str) -> dict[str, int]:
    """Parse '252 HP / 4 Atk / 252 Spe' into {'hp': 252, 'atk': 4, 'spe': 252}."""
    stat_aliases = {
        "hp": "hp", "atk": "atk", "def": "def",
        "spa": "spa", "spd": "spd", "spe": "spe",
        "spatk": "spa", "spdef": "spd", "spd": "spd",
    }
    result: dict[str, int] = {}
    for chunk in text.split("/"):
        chunk = chunk.strip()
        match = re.match(r"(\d+)\s+(.*)", chunk)
        if not match:
            continue
        value, stat_name = int(match.group(1)), match.group(2).strip().lower().replace(" ", "")
        canonical = stat_aliases.get(stat_name)
        if canonical:
            result[canonical] = value
    return result


def normalize_trainer_mon_details(mon: dict[str, Any]) -> dict[str, Any]:
    """Keep optional trainer set data present and consistently ordered for the docs UI."""
    stat_order = ("hp", "atk", "def", "spa", "spd", "spe")
    normalized = dict(mon)
    normalized["item"] = normalized.get("item", "")
    normalized["ability"] = normalized.get("ability", "")
    normalized["evs"] = {stat: normalized.get("evs", {})[stat] for stat in stat_order if stat in normalized.get("evs", {})}
    normalized["ivs"] = {stat: normalized.get("ivs", {})[stat] for stat in stat_order if stat in normalized.get("ivs", {})}
    normalized["moves"] = [move for move in normalized.get("moves", []) if move]
    return normalized


def trainer_display_name(name: str, constant: str, difficulty: str) -> str:
    display_name = name
    variant_match = re.search(r"_(\d+)$", constant)
    if variant_match and not re.search(rf"\b{variant_match.group(1)}\b$", display_name):
        display_name = f"{display_name} {variant_match.group(1)}"
    if difficulty.lower() == "hard":
        display_name = f"{display_name} (Hard)"
    return display_name


def average_party_level(party: list[dict[str, Any]]) -> float:
    if not party:
        return 0
    return sum(mon.get("level", 100) for mon in party) / len(party)


def build_item_lookup(item_records: dict[str, dict[str, Any]]) -> dict[str, dict[str, Any]]:
    lookup: dict[str, dict[str, Any]] = {}
    for constant, item in item_records.items():
        names = {
            constant,
            constant.removeprefix("ITEM_"),
            item.get("name", ""),
            clean_constant_name(constant, "ITEM_"),
        }
        for name in names:
            if name:
                lookup.setdefault(normalize_token(name), item)
    return lookup


def resolve_trainer_item(item_name: str, item_lookup: dict[str, dict[str, Any]]) -> dict[str, Any] | None:
    return item_lookup.get(normalize_token(item_name))


def copy_item_icon(item: dict[str, Any] | None, item_icon_dir: Path) -> str | None:
    if not item:
        return None
    icon_name = f"{item['constant'].removeprefix('ITEM_').lower()}.png"
    source = REPO_ROOT / "graphics" / "items" / "icons" / icon_name
    if not source.exists():
        return None
    target = item_icon_dir / source.name
    target.parent.mkdir(parents=True, exist_ok=True)
    image = Image.open(source)
    rgba = image.convert("RGBA")
    if image.mode == "P":
        transparent_index = image.info.get("transparency", 0)
        pixels = [
            (*pixel[:3], 0) if image.getpixel((x, y)) == transparent_index else pixel
            for y in range(image.height)
            for x, pixel in ((x, rgba.getpixel((x, y))) for x in range(image.width))
        ]
        rgba.putdata(pixels)
    rgba.save(target)
    return str(target.relative_to(OUT_DIR))


def parse_trainer_front_pic_sources() -> dict[str, Path]:
    sources: dict[str, Path] = {}
    for path in sorted(TRAINER_FRONT_PIC_DIR.glob("*.png")):
        sources[normalize_token(path.stem)] = path
    return sources


def trainer_pic_source(pic_name: str, trainer_front_sources: dict[str, Path]) -> Path | None:
    candidates = [
        normalize_token(pic_name),
        normalize_token(slugify(pic_name)),
        normalize_token(pic_name.replace("Trainer", "Trainer ")),
    ]
    for candidate in candidates:
        if candidate in trainer_front_sources:
            return trainer_front_sources[candidate]
    return None


def build_species_lookup(species: list[SpeciesRow]) -> dict[str, SpeciesRow]:
    lookup: dict[str, SpeciesRow] = {}
    for row in species:
        names = {
            row.name,
            clean_constant_name(row.constant, "SPECIES_"),
            row.constant.removeprefix("SPECIES_"),
        }
        for name in names:
            lookup.setdefault(normalize_token(name), row)
    return lookup


def species_for_trainer_mon(name: str, species_lookup: dict[str, SpeciesRow]) -> SpeciesRow | None:
    clean_name = re.sub(r"\s*\([^)]*\)\s*", " ", name)
    clean_name = clean_name.split("@", 1)[0].strip()
    return species_lookup.get(normalize_token(clean_name))


def front_pic_symbol_for_name(name: str, front_sources: dict[str, Path]) -> str | None:
    clean_name = name.removeprefix("SPECIES_")
    pascal_name = "".join(part.capitalize() for part in re.findall(r"[A-Za-z0-9]+", clean_name))
    candidates = [
        f"gMonFrontPic_{pascal_name}",
        f"gMonFrontPic_{pascal_name}Standard",
    ]
    for candidate in candidates:
        if candidate in front_sources:
            return candidate
    return None


def enrich_trainer_party(
    party: list[dict[str, Any]],
    species_lookup: dict[str, SpeciesRow],
    front_sources: dict[str, Path],
    sprite_dir: Path,
    item_lookup: dict[str, dict[str, Any]],
    item_icon_dir: Path,
) -> list[dict[str, Any]]:
    enriched = []
    for mon in party:
        mon = normalize_trainer_mon_details(mon)
        species = species_for_trainer_mon(mon["name"], species_lookup)
        held_item = resolve_trainer_item(mon["item"], item_lookup)
        display_name = mon["name"]
        if display_name.startswith("SPECIES_"):
            display_name = species.name if species else clean_constant_name(display_name, "SPECIES_")
        sprite = species.sprite if species else None
        if sprite is None:
            symbol = front_pic_symbol_for_name(display_name, front_sources)
            if symbol:
                sprite_path = sprite_dir / f"{slugify(display_name)}.png"
                process_sprite(front_sources[symbol], sprite_path)
                sprite = str(sprite_path.relative_to(OUT_DIR))
        enriched.append({
            **mon,
            "constant": species.constant if species else "",
            "displayName": display_name,
            "itemConstant": held_item["constant"] if held_item else "",
            "itemIcon": copy_item_icon(held_item, item_icon_dir),
            "sprite": sprite,
        })
    return enriched


def parse_trainers(
    species_lookup: dict[str, SpeciesRow],
    front_sources: dict[str, Path],
    trainer_front_sources: dict[str, Path],
    sprite_dir: Path,
    trainer_sprite_dir: Path,
    item_records: dict[str, dict[str, Any]],
    item_icon_dir: Path,
) -> list[dict[str, Any]]:
    """Read trainers.party and parse each === TRAINER_* === block."""
    if not TRAINERS_H.exists():
        return []

    text = strip_c_comments(read(TRAINERS_H))
    trainers: list[dict[str, Any]] = []
    header_re = re.compile(r"^===\s*(TRAINER_[A-Z0-9_]+)\s*===", re.MULTILINE)
    matches = list(header_re.finditer(text))
    item_lookup = build_item_lookup(item_records)

    for index, match in enumerate(matches):
        constant = match.group(1)
        start = match.end()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        block = text[start:end].strip()
        name_match = re.search(r"^Name:\s*(.*?)\s*$", block, re.MULTILINE)
        pic_match = re.search(r"^Pic:\s*(.*?)\s*$", block, re.MULTILINE)
        difficulty_match = re.search(r"^Difficulty:\s*(.*?)\s*$", block, re.MULTILINE)
        name = name_match.group(1).strip() if name_match and name_match.group(1).strip() else clean_constant_name(constant, "TRAINER_")
        pic = pic_match.group(1).strip() if pic_match else ""
        difficulty = difficulty_match.group(1).strip() if difficulty_match and difficulty_match.group(1).strip() else "Normal"
        party = enrich_trainer_party(parse_showdown_team(block), species_lookup, front_sources, sprite_dir, item_lookup, item_icon_dir)
        if not party:
            continue

        front_sprite = None
        source = trainer_pic_source(pic, trainer_front_sources) if pic else None
        if source:
            target = trainer_sprite_dir / source.name
            process_sprite(source, target)
            front_sprite = f"{target.relative_to(OUT_DIR)}?v={SPRITE_CACHE_VERSION}"

        trainers.append({
            "constant": constant,
            "name": name,
            "displayName": trainer_display_name(name, constant, difficulty),
            "difficulty": difficulty,
            "averageLevel": round(average_party_level(party), 2),
            "pic": pic,
            "sprite": front_sprite,
            "party": party,
        })
    return sorted(trainers, key=lambda trainer: (trainer["averageLevel"], trainer["displayName"], trainer["constant"]))


def build() -> None:
    moves = parse_named_table("data/moves_info.h", "MOVE_", "MOVE_")
    abilities = parse_named_table("data/abilities.h", "ABILITY_", "ABILITY_")
    species, by_species = parse_species()
    tmhm_rows = parse_tmhm_list()
    tmhm_moves = {row["move"] for row in tmhm_rows}
    item_records = parse_item_records()
    tmhm_locations = parse_tmhm_locations()
    evolution_map = parse_evolutions(item_records)
    level_up = parse_level_up_learnsets()
    teachables = parse_teachable_learnsets(tmhm_moves)
    front_sources = parse_front_pic_sources()
    trainer_front_sources = parse_trainer_front_pic_sources()

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for item in SRC_DIR.rglob("*"):
        dest = OUT_DIR / item.relative_to(SRC_DIR)
        if item.is_dir():
            dest.mkdir(parents=True, exist_ok=True)
        else:
            shutil.copy2(item, dest)
    (OUT_DIR / ".nojekyll").write_text("", encoding="utf-8")
    (OUT_DIR / "data").mkdir(parents=True, exist_ok=True)
    sprite_dir = OUT_DIR / "sprites" / "pokemon"
    trainer_sprite_dir = OUT_DIR / "sprites" / "trainers"
    item_icon_dir = OUT_DIR / "sprites" / "items"
    type_icons = copy_type_icons()

    for row in species:
        if row.level_up_symbol:
            row.level_up = level_up.get(row.level_up_symbol, [])
        if row.teachable_symbol:
            row.tmhm = teachables.get(row.teachable_symbol, {}).get("tmhm", [])
            row.tutors = teachables.get(row.teachable_symbol, {}).get("tutors", [])
        row.evolutions = evolution_map.get(row.constant, [])
        if row.front_pic_symbol and row.front_pic_symbol in front_sources:
            sprite_path = sprite_dir / f"{row.constant.removeprefix('SPECIES_').lower()}.png"
            process_sprite(front_sources[row.front_pic_symbol], sprite_path)
            row.sprite = str(sprite_path.relative_to(OUT_DIR))

    encounters = parse_wild_encounters(by_species)
    species_locations = build_species_locations(encounters)
    for row in species:
        row.locations = species_locations.get(row.constant, [])
    visible_species = [row for row in species if row.dex_visible]
    trainers = parse_trainers(build_species_lookup(species), front_sources, trainer_front_sources, sprite_dir, trainer_sprite_dir, item_records, item_icon_dir)

    ability_usage: dict[str, dict[str, list[dict[str, Any]]]] = defaultdict(lambda: {"base": [], "innate": []})
    for row in visible_species:
        mini = {"species": row.constant, "name": row.name, "dex": row.display_dex, "sprite": row.sprite}
        for ability in row.abilities:
            ability_usage[ability]["base"].append(mini)
        for ability in row.innates:
            ability_usage[ability]["innate"].append(mini)

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
    important_items = build_important_items(item_records)

    payload = {
        "meta": {"generatedFrom": "tools/soulgold_docs/build_docs.py"},
        "species": [
            {
                "id": row.id,
                "constant": row.constant,
                "dex": row.display_dex,
                "name": row.name,
                "types": row.types,
                "stats": row.stats,
                "bst": sum(row.stats.values()),
                "abilities": row.abilities,
                "innates": row.innates,
                "sprite": row.sprite,
                "levelUp": row.level_up,
                "tmhm": row.tmhm,
                "tutors": row.tutors,
                "evolutions": row.evolutions,
                "locations": row.locations,
            }
            for row in visible_species
        ],
        "moves": moves,
        "abilities": {
            key: {**value, "usage": ability_usage.get(key, {"base": [], "innate": []})}
            for key, value in abilities.items()
        },
        "tms": tms,
        "items": important_items,
        "encounters": encounters,
        "trainers": trainers,
        "typeIcons": type_icons,
    }
    (OUT_DIR / "data" / "romhack-docs.json").write_text(json.dumps(payload, indent=2), encoding="utf-8")


if __name__ == "__main__":
    build()
