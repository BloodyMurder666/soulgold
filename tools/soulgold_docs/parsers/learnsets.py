"""Learnset parsing for level-up, TM/HM, and tutor moves."""

from __future__ import annotations

import re

from ..c_parser import read
from ..models import LevelUpMove, Teachables, TMHMRow
from ..paths import REPO_ROOT


def parse_level_up_learnsets() -> dict[str, list[LevelUpMove]]:
    learnsets: dict[str, list[LevelUpMove]] = {}
    text = "\n".join(read(path) for path in sorted((REPO_ROOT / "src/data/pokemon/level_up_learnsets").glob("gen_*.h")))
    pattern = re.compile(r"static\s+const\s+struct\s+LevelUpMove\s+(s[A-Za-z0-9_]+LevelUpLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = []
        for level, move in re.findall(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)", body):
            moves.append({"level": int(level), "move": move})
        learnsets[symbol] = moves
    return learnsets

def parse_teachable_learnsets(tmhm_moves: set[str]) -> dict[str, Teachables]:
    text = read(REPO_ROOT / "src/data/pokemon/teachable_learnsets.h")
    learnsets: dict[str, Teachables] = {}
    pattern = re.compile(r"static\s+const\s+u16\s+(s[A-Za-z0-9_]+TeachableLearnset)\[\]\s*=\s*\{(.*?)\};", re.DOTALL)
    for symbol, body in pattern.findall(text):
        moves = [move for move in re.findall(r"\bMOVE_[A-Z0-9_]+\b", body) if move != "MOVE_UNAVAILABLE"]
        learnsets[symbol] = {
            "tmhm": [move for move in moves if move in tmhm_moves],
            "tutors": [move for move in moves if move not in tmhm_moves],
        }
    return learnsets


def tmhm_move_constants(tmhm_rows: list[TMHMRow]) -> set[str]:
    return {row["move"] for row in tmhm_rows}
