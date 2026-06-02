#!/usr/bin/env python3
"""Battle animation studio tooling.

This tool indexes the move animation system, generates a static manifest for the
browser studio, and writes small repo patches for new move animation scripts.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from datetime import datetime
from pathlib import Path


TOOL_DIR = Path(__file__).resolve().parent
ROOT = TOOL_DIR.parent.parent
DEFAULT_MANIFEST = TOOL_DIR / "data" / "manifest.json"

ANIM_SCRIPT_PATH = ROOT / "data" / "battle_anim_scripts.s"
ANIM_HEADER_PATH = ROOT / "include" / "battle_anim_scripts.h"
MOVES_INFO_PATH = ROOT / "src" / "data" / "moves_info.h"
MOVES_CONSTANTS_PATH = ROOT / "include" / "constants" / "moves.h"
BATTLE_ANIM_CONSTANTS_PATH = ROOT / "include" / "constants" / "battle_anim.h"
BATTLE_ANIM_DATA_PATH = ROOT / "src" / "data" / "battle_anim.h"
GRAPHICS_C_PATH = ROOT / "src" / "graphics.c"
MACROS_PATH = ROOT / "asm" / "macros" / "battle_anim_script.inc"
PREVIEW_TEST_PATH = ROOT / "test" / "battle" / "move_animations" / "studio_preview.c"
DEFAULT_TEST_SHARDS = 4


LABEL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
MOVE_RE = re.compile(r"^MOVE_[A-Z0-9_]+$")
SPECIES_RE = re.compile(r"^SPECIES_[A-Z0-9_]+$")


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8", newline="\n")


def rel(path: Path) -> str:
    return str(path.relative_to(ROOT)).replace("\\", "/")


def strip_line_comment(line: str) -> str:
    return line.split("//", 1)[0].split("@", 1)[0]


def eval_constant_expr(expr: str, values: dict[str, int]) -> int | None:
    expr = expr.strip()
    if not expr:
        return None

    if re.fullmatch(r"0x[0-9A-Fa-f]+|\d+", expr):
        return int(expr, 0)

    if "+" in expr:
        total = 0
        for part in expr.split("+"):
            value = eval_constant_expr(part, values)
            if value is None:
                return None
            total += value
        return total

    if "-" in expr and not expr.startswith("-"):
        parts = expr.split("-")
        value = eval_constant_expr(parts[0], values)
        if value is None:
            return None
        for part in parts[1:]:
            sub = eval_constant_expr(part, values)
            if sub is None:
                return None
            value -= sub
        return value

    return values.get(expr)


def parse_move_constants() -> dict[str, int]:
    text = read_text(MOVES_CONSTANTS_PATH)
    values: dict[str, int] = {}
    current = -1
    in_enum = False

    for raw_line in text.splitlines():
        line = strip_line_comment(raw_line).strip()
        if line.startswith("enum ") or line == "enum __attribute__((packed)) Move":
            in_enum = True
            continue
        if not in_enum:
            continue
        if line.startswith("};"):
            break
        if not line or line == "{":
            continue

        match = re.match(r"([A-Z0-9_]+)\s*(?:=\s*([^,]+))?,?", line)
        if not match:
            continue

        name, expr = match.groups()
        if expr is not None:
            value = eval_constant_expr(expr, values)
            if value is None:
                continue
            current = value
        else:
            current += 1
        values[name] = current

    return {name: value for name, value in values.items() if name.startswith("MOVE_")}


def find_matching_brace(text: str, open_index: int) -> int:
    depth = 0
    in_string = False
    escape = False
    in_line_comment = False
    in_block_comment = False

    i = open_index
    while i < len(text):
        char = text[i]
        next_char = text[i + 1] if i + 1 < len(text) else ""

        if in_line_comment:
            if char == "\n":
                in_line_comment = False
            i += 1
            continue

        if in_block_comment:
            if char == "*" and next_char == "/":
                in_block_comment = False
                i += 2
            else:
                i += 1
            continue

        if in_string:
            if escape:
                escape = False
            elif char == "\\":
                escape = True
            elif char == '"':
                in_string = False
            i += 1
            continue

        if char == "/" and next_char == "/":
            in_line_comment = True
            i += 2
            continue

        if char == "/" and next_char == "*":
            in_block_comment = True
            i += 2
            continue

        if char == '"':
            in_string = True
        elif char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1

    raise ValueError("unmatched brace in source file")


def c_string_value(expr: str) -> str:
    strings = re.findall(r'"((?:\\.|[^"\\])*)"', expr)
    return "".join(bytes(part, "utf-8").decode("unicode_escape") for part in strings)


def pretty_constant(name: str, prefix: str) -> str:
    value = name
    if value.startswith(prefix):
        value = value[len(prefix):]
    return " ".join(token.capitalize() for token in value.split("_") if token)


def field_expr(block: str, field: str) -> str | None:
    match = re.search(rf"\.{re.escape(field)}\s*=\s*(.*?),\s*(?:\n|$)", block, re.S)
    return match.group(1).strip() if match else None


def parse_move_blocks(text: str) -> list[tuple[str, int, int, str]]:
    blocks: list[tuple[str, int, int, str]] = []
    for match in re.finditer(r"\[(MOVE_[A-Z0-9_]+)\]\s*=\s*\{", text):
        open_index = text.find("{", match.start())
        close_index = find_matching_brace(text, open_index)
        blocks.append((match.group(1), match.start(), close_index + 1, text[open_index + 1:close_index]))
    return blocks


def parse_moves_info(move_values: dict[str, int]) -> list[dict[str, object]]:
    text = read_text(MOVES_INFO_PATH)
    moves: list[dict[str, object]] = []

    for move_id, start, _, block in parse_move_blocks(text):
        name_expr = field_expr(block, "name")
        name = c_string_value(name_expr) if name_expr else pretty_constant(move_id, "MOVE_")

        script = field_expr(block, "battleAnimScript")
        move_type_expr = field_expr(block, "type") or ""
        type_tokens = re.findall(r"\bTYPE_[A-Z0-9_]+\b", move_type_expr)

        moves.append({
            "id": move_id,
            "value": move_values.get(move_id),
            "name": name,
            "script": script,
            "type": " / ".join(type_tokens) if type_tokens else move_type_expr,
            "effect": field_expr(block, "effect"),
            "power": field_expr(block, "power"),
            "accuracy": field_expr(block, "accuracy"),
            "category": field_expr(block, "category"),
            "target": field_expr(block, "target"),
            "sourceLine": text.count("\n", 0, start) + 1,
        })

    return moves


def parse_scripts() -> list[dict[str, object]]:
    text = read_text(ANIM_SCRIPT_PATH)
    labels = list(re.finditer(r"^([A-Za-z_][A-Za-z0-9_]*)::.*$", text, re.M))
    scripts: list[dict[str, object]] = []

    for i, match in enumerate(labels):
        label = match.group(1)
        body_start = match.end()
        body_end = labels[i + 1].start() if i + 1 < len(labels) else len(text)
        body = text[body_start:body_end].strip("\n")
        body_lines = body.splitlines()

        commands: dict[str, int] = {}
        tags: set[str] = set()
        backgrounds: set[str] = set()
        templates: set[str] = set()
        tasks: set[str] = set()
        sounds: set[str] = set()

        for line in body_lines:
            command_line = line.split("@", 1)[0].strip()
            if not command_line or command_line.startswith("."):
                continue
            if re.match(r"^[A-Za-z_][A-Za-z0-9_]*:$", command_line):
                continue

            command = re.match(r"([A-Za-z_][A-Za-z0-9_]*)", command_line)
            if command:
                commands[command.group(1)] = commands.get(command.group(1), 0) + 1

            tags.update(re.findall(r"\bANIM_TAG_[A-Z0-9_]+\b", command_line))
            backgrounds.update(re.findall(r"\bBG_[A-Z0-9_]+\b", command_line))
            templates.update(re.findall(r"\bg[A-Za-z0-9_]*SpriteTemplate\b", command_line))
            tasks.update(re.findall(r"\b(?:AnimTask|SoundTask)_[A-Za-z0-9_]+\b", command_line))
            sounds.update(re.findall(r"\bSE_[A-Z0-9_]+\b", command_line))

        scripts.append({
            "label": label,
            "kind": "move" if label.startswith("gBattleAnimMove_") else "helper",
            "line": text.count("\n", 0, match.start()) + 1,
            "body": body,
            "commands": commands,
            "tags": sorted(tags),
            "backgrounds": sorted(backgrounds),
            "templates": sorted(templates),
            "tasks": sorted(tasks),
            "sounds": sorted(sounds),
        })

    return scripts


def parse_animation_constants() -> tuple[list[dict[str, object]], list[dict[str, object]]]:
    text = read_text(BATTLE_ANIM_CONSTANTS_PATH)
    values = {"ANIM_SPRITES_START": 10000}
    tags: list[dict[str, object]] = []
    backgrounds: list[dict[str, object]] = []

    for raw_line in text.splitlines():
        comment = ""
        if "//" in raw_line:
            raw_line, comment = raw_line.split("//", 1)
            comment = comment.strip()

        match = re.match(r"\s*#define\s+(ANIM_TAG_[A-Z0-9_]+)\s+(.+?)\s*$", raw_line)
        if match:
            name, expr = match.groups()
            if name == "ANIM_TAG_COUNT":
                continue
            value = eval_constant_expr(expr.replace("(", "").replace(")", ""), values)
            if value is not None:
                values[name] = value
            tags.append({
                "id": name,
                "value": value,
                "name": pretty_constant(name, "ANIM_TAG_"),
                "comment": comment,
            })
            continue

        match = re.match(r"\s*#define\s+(BG_[A-Z0-9_]+)\s+(\d+)\b", raw_line)
        if match:
            name, value = match.groups()
            backgrounds.append({
                "id": name,
                "value": int(value),
                "name": pretty_constant(name, "BG_"),
                "comment": comment,
            })

    return tags, backgrounds


def parse_graphics_symbols() -> dict[str, str]:
    text = read_text(GRAPHICS_C_PATH)
    symbols: dict[str, str] = {}
    for match in re.finditer(r"const\s+u(?:16|32)\s+(\w+)\[\]\s*=\s*INCBIN_U(?:16|32)\(\"([^\"]+)\"\)", text):
        symbols[match.group(1)] = match.group(2)
    return symbols


def png_candidate(path: str | None) -> str | None:
    if not path:
        return None
    p = Path(path)
    suffixes = [
        ".4bpp.smol",
        ".8bpp.smol",
        ".gbapal",
        ".bin.smolTM",
    ]
    candidate = None
    for suffix in suffixes:
        if path.endswith(suffix):
            candidate = Path(path[:-len(suffix)] + ".png")
            break
    if candidate is None:
        candidate = p.with_suffix(".png")
    full = ROOT / candidate
    return str(candidate).replace("\\", "/") if full.exists() else None


def parse_animation_table(tags: list[dict[str, object]]) -> list[dict[str, object]]:
    text = read_text(BATTLE_ANIM_DATA_PATH)
    graphics_symbols = parse_graphics_symbols()
    by_tag = {tag["id"]: dict(tag) for tag in tags}

    table_re = re.compile(
        r"BATTLE_ANIMATION\(\s*(ANIM_TAG_[A-Z0-9_]+)\s*,\s*([^,]+?)\s*,\s*([^,]+?)\s*,\s*([^)]+?)\s*\)",
        re.S,
    )

    for match in table_re.finditer(text):
        tag, gfx_expr, size_expr, pal_expr = [group.strip() for group in match.groups()]
        entry = by_tag.setdefault(tag, {"id": tag, "name": pretty_constant(tag, "ANIM_TAG_")})
        gfx_symbols = re.findall(r"\bgBattleAnimSpriteGfx_[A-Za-z0-9_]+\b", gfx_expr)
        pal_symbols = re.findall(r"\bgBattleAnimSpritePal_[A-Za-z0-9_]+\b", pal_expr)
        gfx_symbol = gfx_symbols[0] if gfx_symbols else gfx_expr
        pal_symbol = pal_symbols[0] if pal_symbols else pal_expr
        gfx_path = graphics_symbols.get(gfx_symbol)
        pal_path = graphics_symbols.get(pal_symbol)

        entry.update({
            "gfxSymbol": gfx_symbol,
            "palSymbol": pal_symbol,
            "size": size_expr,
            "gfxPath": gfx_path,
            "palPath": pal_path,
            "pngPath": png_candidate(gfx_path) or png_candidate(pal_path),
        })

    return [by_tag[tag["id"]] for tag in tags if tag["id"] in by_tag]


def parse_macros() -> list[dict[str, object]]:
    text = read_text(MACROS_PATH)
    macros: list[dict[str, object]] = []
    for match in re.finditer(r"^\s*\.macro\s+([A-Za-z_][A-Za-z0-9_]*)\s*(.*?)\s*$", text, re.M):
        args = match.group(2).strip()
        arg_names = []
        for arg in args.split(","):
            arg = arg.strip()
            if not arg:
                continue
            arg_names.append(arg.split(":", 1)[0].split("=", 1)[0].strip())
        macros.append({
            "name": match.group(1),
            "args": arg_names,
            "line": text.count("\n", 0, match.start()) + 1,
        })
    return macros


def build_manifest() -> dict[str, object]:
    move_values = parse_move_constants()
    moves = parse_moves_info(move_values)
    scripts = parse_scripts()
    tags, backgrounds = parse_animation_constants()
    tags = parse_animation_table(tags)

    scripts_by_label = {script["label"]: script for script in scripts}
    for move in moves:
        script = scripts_by_label.get(move.get("script"))
        if script:
            move["scriptLine"] = script["line"]
            move["tags"] = script["tags"]
            move["backgrounds"] = script["backgrounds"]
            move["templates"] = script["templates"]
            move["tasks"] = script["tasks"]

    asset_files = sorted(
        rel(path)
        for path in (ROOT / "graphics" / "battle_anims").glob("**/*.png")
    )

    return {
        "generatedAt": datetime.now().isoformat(timespec="seconds"),
        "repo": str(ROOT),
        "sources": {
            "scripts": rel(ANIM_SCRIPT_PATH),
            "movesInfo": rel(MOVES_INFO_PATH),
            "scriptHeader": rel(ANIM_HEADER_PATH),
            "constants": rel(BATTLE_ANIM_CONSTANTS_PATH),
            "animationTable": rel(BATTLE_ANIM_DATA_PATH),
            "macros": rel(MACROS_PATH),
        },
        "moves": moves,
        "scripts": scripts,
        "tags": tags,
        "backgrounds": backgrounds,
        "commands": parse_macros(),
        "assetFiles": asset_files,
    }


def cmd_build_manifest(args: argparse.Namespace) -> int:
    manifest = build_manifest()
    output = Path(args.output) if args.output else DEFAULT_MANIFEST
    write_text(output, json.dumps(manifest, indent=2, sort_keys=True))
    print(f"Wrote {output.relative_to(ROOT)}")
    print(f"Indexed {len(manifest['moves'])} moves, {len(manifest['scripts'])} scripts, {len(manifest['tags'])} sprite tags.")
    return 0


def load_manifest() -> dict[str, object]:
    if DEFAULT_MANIFEST.exists():
        return json.loads(read_text(DEFAULT_MANIFEST))
    return build_manifest()


def move_index(manifest: dict[str, object]) -> dict[str, dict[str, object]]:
    return {move["id"]: move for move in manifest["moves"]}  # type: ignore[index]


def script_index(manifest: dict[str, object]) -> dict[str, dict[str, object]]:
    return {script["label"]: script for script in manifest["scripts"]}  # type: ignore[index]


def pascal_from_move(move: str) -> str:
    tokens = move.removeprefix("MOVE_").split("_")
    return "".join(token[:1] + token[1:].lower() for token in tokens if token)


def normalize_label(label: str | None, move: str | None) -> str:
    if not label and move:
        label = f"gBattleAnimMove_{pascal_from_move(move)}"
    if not label:
        raise SystemExit("Pass --label, or pass --move so a label can be derived.")
    if not LABEL_RE.fullmatch(label):
        raise SystemExit(f"Invalid animation label: {label}")
    return label


def resolve_script_ref(manifest: dict[str, object], ref: str) -> dict[str, object]:
    scripts = script_index(manifest)
    moves = move_index(manifest)

    if ref in scripts:
        return scripts[ref]
    if ref in moves and moves[ref].get("script") in scripts:
        return scripts[moves[ref]["script"]]  # type: ignore[index]

    ref_lower = ref.lower()
    for move in moves.values():
        if str(move.get("name", "")).lower() == ref_lower and move.get("script") in scripts:
            return scripts[move["script"]]  # type: ignore[index]

    raise SystemExit(f"Could not resolve animation source: {ref}")


def trim_primary_body(lines: list[str]) -> list[str]:
    """Return the runnable body before a move script's first top-level end.

    Many move scripts keep helper labels after the first `end`. Inlining those
    helpers would duplicate labels and, worse, retain a mid-composition `end`.
    The helper labels are global in the source file, so the copied body can keep
    calling them without copying their definitions.
    """
    trimmed: list[str] = []
    for line in lines:
        command = line.strip().split("@", 1)[0].strip()
        if command == "end":
            break
        trimmed.append(line)
    while trimmed and not trimmed[-1].strip():
        trimmed.pop()
    return trimmed


def starter_script(label: str) -> str:
    return "\n".join([
        f"{label}::",
        "\tloadspritegfx ANIM_TAG_IMPACT",
        "\tmonbg ANIM_TARGET",
        "\tsplitbgprio ANIM_TARGET",
        "\tsetalpha 12, 8",
        "\tplaysewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET",
        "\tcreate_basic_hitsplat_sprite ANIM_TARGET, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=0",
        "\tcreatevisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 2",
        "\twaitforvisualfinish",
        "\tclearmonbg ANIM_TARGET",
        "\tblendoff",
        "\tend",
        "",
    ])


def composed_script(label: str, sources: list[dict[str, object]]) -> str:
    lines = [f"{label}::"]
    for source in sources:
        lines.append(f"\t@ Inlined from {source['label']}. Review labels/gotos before shipping.")
        for line in trim_primary_body(str(source["body"]).splitlines()):
            if not line.strip():
                lines.append("")
            elif line.startswith("\t"):
                lines.append(line)
            else:
                lines.append("\t" + line)
        lines.append("\twaitforvisualfinish")
    lines.append("\tend")
    lines.append("")
    return "\n".join(lines)


def script_from_file(label: str, path: Path) -> str:
    body = read_text(path).strip("\n")
    if re.search(rf"^{re.escape(label)}::", body, re.M):
        return body + "\n"
    return f"{label}::\n" + "\n".join("\t" + line if line.strip() else "" for line in body.splitlines()) + "\n"


def ensure_unique_label(label: str) -> None:
    script_text = read_text(ANIM_SCRIPT_PATH)
    header_text = read_text(ANIM_HEADER_PATH)
    if re.search(rf"^{re.escape(label)}::", script_text, re.M):
        raise SystemExit(f"{label} already exists in {rel(ANIM_SCRIPT_PATH)}")
    if re.search(rf"\b{re.escape(label)}\[\]", header_text):
        raise SystemExit(f"{label} already exists in {rel(ANIM_HEADER_PATH)}")


def append_script(script: str) -> None:
    text = read_text(ANIM_SCRIPT_PATH)
    marker = "@@@ ANIMATION STUDIO GENERATED SCRIPTS"
    if marker not in text:
        text = text.rstrip() + "\n\n" + marker + "\n"
    text = text.rstrip() + "\n\n" + script.strip() + "\n"
    write_text(ANIM_SCRIPT_PATH, text)


def insert_extern(label: str) -> None:
    text = read_text(ANIM_HEADER_PATH)
    extern = f"extern const u8 {label}[];"
    if extern in text:
        return

    section = "// status animations"
    if section in text:
        text = text.replace(section, extern + "\n" + section, 1)
    else:
        text = text.replace("#endif // GUARD_BATTLE_ANIM_SCRIPTS_H", extern + "\n\n#endif // GUARD_BATTLE_ANIM_SCRIPTS_H", 1)
    write_text(ANIM_HEADER_PATH, text)


def update_move_animation(move_id: str, label: str) -> None:
    if not MOVE_RE.fullmatch(move_id):
        raise SystemExit(f"Invalid move constant: {move_id}")

    text = read_text(MOVES_INFO_PATH)
    for block_move, start, end, block in parse_move_blocks(text):
        if block_move != move_id:
            continue

        full_block = text[start:end]
        if ".battleAnimScript" in full_block:
            new_block = re.sub(r"(\.battleAnimScript\s*=\s*)[A-Za-z_][A-Za-z0-9_]*", rf"\g<1>{label}", full_block, count=1)
        else:
            insert_at = full_block.rfind("}")
            new_block = full_block[:insert_at] + f"        .battleAnimScript = {label},\n" + full_block[insert_at:]
        write_text(MOVES_INFO_PATH, text[:start] + new_block + text[end:])
        return

    raise SystemExit(f"Could not find {move_id} in {rel(MOVES_INFO_PATH)}")


def preview_test_source(move: str, attacker: str, target: str, test_name: str) -> str:
    return "\n".join([
        '#include "global.h"',
        '#include "test/battle.h"',
        "",
        f'SINGLE_BATTLE_TEST("{test_name}")',
        "{",
        "    FORCE_MOVE_ANIM(TRUE);",
        "",
        "    GIVEN {",
        f"        PLAYER({attacker}) {{ MaxHP(9999); HP(9999); Speed(100); Moves({move}, MOVE_CELEBRATE); }}",
        f"        OPPONENT({target}) {{ MaxHP(9999); HP(9999); Speed(1); Moves(MOVE_CELEBRATE); }}",
        "    } WHEN {",
        f"        TURN {{ MOVE(player, {move}); MOVE(opponent, MOVE_CELEBRATE); }}",
        "    } SCENE {",
        f"        ANIMATION(ANIM_TYPE_MOVE, {move}, player);",
        "    } THEN {",
        "        FORCE_MOVE_ANIM(FALSE);",
        "    }",
        "}",
        "",
    ])


def write_preview_test(move: str, attacker: str, target: str) -> str:
    if not MOVE_RE.fullmatch(move):
        raise SystemExit(f"Invalid move constant: {move}")
    if not SPECIES_RE.fullmatch(attacker):
        raise SystemExit(f"Invalid attacker species constant: {attacker}")
    if not SPECIES_RE.fullmatch(target):
        raise SystemExit(f"Invalid target species constant: {target}")

    test_name = f"Animation Studio Preview: {move}"
    write_text(PREVIEW_TEST_PATH, preview_test_source(move, attacker, target, test_name))
    return test_name


def iter_test_sources() -> list[Path]:
    paths: list[Path] = []
    test_root = ROOT / "test"
    for pattern in ("*.c", "*/*.c", "*/*/*.c"):
        paths.extend(sorted(test_root.glob(pattern)))
    return [path for path in paths if not path.name.endswith(".inc.c")]


def test_obj_rel(path: Path) -> str:
    source_rel = path.relative_to(ROOT / "test").with_suffix(".o")
    return str(Path("test") / source_rel).replace("\\", "/")


def preview_shard_id(test_shards: int) -> int:
    if test_shards < 1:
        raise SystemExit("--test-shards must be at least 1")

    support_objs = {
        "test/test_runner.o",
        "test/test_runner_args.o",
        "test/test_runner_battle.o",
    }
    shardable = [path for path in iter_test_sources() if test_obj_rel(path) not in support_objs]
    preview_obj = test_obj_rel(PREVIEW_TEST_PATH)

    for index, path in enumerate(shardable):
        if test_obj_rel(path) == preview_obj:
            return index % test_shards

    raise SystemExit(f"Could not locate {rel(PREVIEW_TEST_PATH)} in the test shard list.")


def preview_elf_target(test_shards: int) -> str:
    return f"pokeemerald-test-{preview_shard_id(test_shards)}.elf"


def print_preview_instructions(test_name: str, test_shards: int, emulator: str | None = None) -> None:
    target = preview_elf_target(test_shards)
    print(f"Wrote {rel(PREVIEW_TEST_PATH)}")
    print("Build the visual test ROM with:")
    print(f'  make {target} TEST_SHARDS={test_shards} TESTS="{test_name}"')
    if emulator:
        print("Launch command:")
        print(f"  {emulator} {target}")
    else:
        print(f"Then open {target} in a graphical GBA emulator for exact in-engine playback.")


def cmd_preview_test(args: argparse.Namespace) -> int:
    test_name = write_preview_test(args.move, args.attacker, args.target)
    print_preview_instructions(test_name, args.test_shards, args.emulator)
    return 0


def cmd_new(args: argparse.Namespace) -> int:
    manifest = load_manifest()
    label = normalize_label(args.label, args.move)
    ensure_unique_label(label)

    if args.script_file:
        script = script_from_file(label, Path(args.script_file))
    elif args.source:
        sources = [resolve_script_ref(manifest, ref) for ref in args.source]
        script = composed_script(label, sources)
    else:
        script = starter_script(label)

    if args.dry_run:
        print(script)
        if args.move:
            print(f"Would set {args.move}.battleAnimScript = {label}")
        return 0

    append_script(script)
    insert_extern(label)
    if args.move:
        update_move_animation(args.move, label)
    if args.preview_test:
        if not args.move:
            raise SystemExit("--preview-test requires --move")
        test_name = write_preview_test(args.move, args.attacker, args.target)
        print_preview_instructions(test_name, args.test_shards)

    print(f"Added {label}")
    if args.move:
        print(f"Linked {args.move} to {label}")
    print("Regenerate the browser index with:")
    print("  python3 tools/animation_studio/studio.py build-manifest")
    return 0


def cmd_launch_preview(args: argparse.Namespace) -> int:
    test_name = write_preview_test(args.move, args.attacker, args.target)
    target = preview_elf_target(args.test_shards)
    build_cmd = ["make", target, f"TEST_SHARDS={args.test_shards}", f"TESTS={test_name}"]
    print("Running:", " ".join(build_cmd))
    subprocess.run(build_cmd, cwd=ROOT, check=True)
    if args.emulator:
        subprocess.Popen([args.emulator, str(ROOT / target)], cwd=ROOT)
    else:
        print(f"Build complete. Open {target} in a graphical GBA emulator.")
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Battle animation studio tooling")
    sub = parser.add_subparsers(dest="command", required=True)

    build = sub.add_parser("build-manifest", help="index moves, scripts, commands, and animation assets")
    build.add_argument("--output", help="manifest output path")
    build.set_defaults(func=cmd_build_manifest)

    preview = sub.add_parser("preview-test", help="write a focused exact-playback battle animation test")
    preview.add_argument("--move", required=True, help="move constant, e.g. MOVE_POUND")
    preview.add_argument("--attacker", default="SPECIES_WOBBUFFET")
    preview.add_argument("--target", default="SPECIES_WOBBUFFET")
    preview.add_argument("--test-shards", type=int, default=DEFAULT_TEST_SHARDS)
    preview.add_argument("--emulator", help="optional graphical emulator command to show after generation")
    preview.set_defaults(func=cmd_preview_test)

    new = sub.add_parser("new", help="append a new move animation script and optionally link it to a move")
    new.add_argument("--move", help="move constant to link, e.g. MOVE_POUND")
    new.add_argument("--label", help="animation label; defaults from --move")
    new.add_argument("--source", action="append", help="move constant, move name, or animation label to inline; repeat to combine")
    new.add_argument("--script-file", help="raw animation script body to add under --label")
    new.add_argument("--preview-test", action="store_true", help="also write studio_preview.c for the linked move")
    new.add_argument("--attacker", default="SPECIES_WOBBUFFET")
    new.add_argument("--target", default="SPECIES_WOBBUFFET")
    new.add_argument("--test-shards", type=int, default=DEFAULT_TEST_SHARDS)
    new.add_argument("--dry-run", action="store_true", help="print generated script without editing files")
    new.set_defaults(func=cmd_new)

    launch = sub.add_parser("launch-preview", help="write preview test, build test ELF, and optionally launch an emulator")
    launch.add_argument("--move", required=True)
    launch.add_argument("--attacker", default="SPECIES_WOBBUFFET")
    launch.add_argument("--target", default="SPECIES_WOBBUFFET")
    launch.add_argument("--test-shards", type=int, default=DEFAULT_TEST_SHARDS)
    launch.add_argument("--emulator", help="graphical emulator command, e.g. mgba")
    launch.set_defaults(func=cmd_launch_preview)

    return parser


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
