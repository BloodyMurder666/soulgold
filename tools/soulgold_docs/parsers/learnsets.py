"""Learnset parsing for level-up, TM/HM, tutor, and egg moves."""

from __future__ import annotations

import re

from ..c_parser import parse_enum_constants, read
from ..models import LevelUpMove, Teachables, TMHMRow
from ..paths import MOVES_H, REPO_ROOT

_move_ids, _ = parse_enum_constants(MOVES_H, "")

_canonical_move_by_id: dict[int, str] = {}

for constant, move_id in _move_ids.items():
    if constant.startswith("MOVE_"):
        _canonical_move_by_id.setdefault(move_id, constant)


def canonical_move(move: str) -> str:
    move_id = _move_ids.get(move)
    if move_id is None:
        return move

    return _canonical_move_by_id.get(move_id, move)


def parse_level_up_learnsets() -> dict[str, list[LevelUpMove]]:
    learnsets: dict[str, list[LevelUpMove]] = {}
    text = "\n".join(read(path) for path in sorted((REPO_ROOT / "src/data/pokemon/level_up_learnsets").glob("gen_*.h")))
    pattern = re.compile(r"static\s+const\s+struct\s+LevelUpMove\s+(s[A-Za-z0-9_]+LevelUpLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = []
        for level, move in re.findall(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)", body):
            moves.append({
                "level": int(level),
                "move": canonical_move(move),
            })
        learnsets[symbol] = moves
    return learnsets

def parse_teachable_learnsets(tmhm_moves: set[str]) -> dict[str, Teachables]:
    text = read(REPO_ROOT / "src/data/pokemon/teachable_learnsets.h")
    learnsets: dict[str, Teachables] = {}
    pattern = re.compile(r"static\s+const\s+u16\s+(s[A-Za-z0-9_]+TeachableLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = [
                    canonical_move(move)
                    for move in re.findall(r"\bMOVE_[A-Z0-9_]+\b", body)
                    if move != "MOVE_UNAVAILABLE"
                ]
        learnsets[symbol] = {
            "tmhm": [move for move in moves if move in tmhm_moves],
            "tutors": [move for move in moves if move not in tmhm_moves],
        }
    return learnsets


def parse_egg_move_learnsets() -> dict[str, list[str]]:
    text = read(REPO_ROOT / "src/data/pokemon/egg_moves.h")
    learnsets: dict[str, list[str]] = {}
    pattern = re.compile(r"static\s+const\s+u16\s+(s[A-Za-z0-9_]+EggMoveLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = [
                    canonical_move(move)
                    for move in re.findall(r"\bMOVE_[A-Z0-9_]+\b", body)
                    if move != "MOVE_UNAVAILABLE"
                ]
        learnsets[symbol] = moves
    return learnsets


def tmhm_move_constants(tmhm_rows: list[TMHMRow]) -> set[str]:
    return {row["move"] for row in tmhm_rows}
