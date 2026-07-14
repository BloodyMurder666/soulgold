#!/usr/bin/env python3
"""Reject disabled music that is referenced by game source data."""

from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "include/config/songs_enabled.h"
CONSTANTS = ROOT / "include/constants/songs.h"
SONG_TABLE = ROOT / "sound/song_table.inc"
SEARCH_ROOTS = ("src", "data", "include", "asm", "sound")
EXCLUDED_FILES = {CONFIG, CONSTANTS, SONG_TABLE}

CONFIG_RE = re.compile(r"^#define\s+SONG_(MUS_[A-Z0-9_]+)\s+([01])(?:\s|$)", re.MULTILINE)
CONSTANT_RE = re.compile(r"^#define\s+(MUS_[A-Z0-9_]+)\s+(\d+)(?:\s|$)", re.MULTILINE)
TABLE_ENTRY_RE = re.compile(r"^\s*song\s+(.+?),\s+MUSIC_PLAYER_", re.MULTILINE)
GUARDED_ENTRY_RE = re.compile(r"^SONG_TABLE_ENTRY\((SONG_MUS_[A-Z0-9_]+),\s*([a-z0-9_]+)\)$")
NUMERIC_SONG_USE_RE = re.compile(
    r"\b(?:playbgm|playfanfare)\s+(0x[0-9a-fA-F]+|\d+)"
    r"|\b(?:PlayBGM|PlayFanfare|m4aSongNumStart|Overworld_ChangeMusicTo|"
    r"PlayNewMapMusic|FadeOutAndPlayNewMapMusic)\s*\(\s*(0x[0-9a-fA-F]+|\d+)"
    r'|"music"\s*:\s*(0x[0-9a-fA-F]+|\d+)'
    r"|\bgSongTable\s*\[\s*(0x[0-9a-fA-F]+|\d+)"
)


def read_text(path):
    try:
        return path.read_text()
    except (OSError, UnicodeDecodeError):
        return None


def iter_source_files():
    for root_name in SEARCH_ROOTS:
        for path in (ROOT / root_name).rglob("*"):
            if path.is_file() and path not in EXCLUDED_FILES:
                yield path


def main():
    config = CONFIG.read_text()
    constants = {
        name: int(song_id)
        for name, song_id in CONSTANT_RE.findall(CONSTANTS.read_text())
    }
    settings = {name: int(enabled) for name, enabled in CONFIG_RE.findall(config)}
    table_entries = TABLE_ENTRY_RE.findall(SONG_TABLE.read_text())
    errors = []

    if not settings:
        errors.append(f"{CONFIG.relative_to(ROOT)} contains no per-song settings")

    guarded_by_flag = {}
    for song_id, entry in enumerate(table_entries):
        match = GUARDED_ENTRY_RE.match(entry)
        if match:
            flag, symbol = match.groups()
            guarded_by_flag[flag.removeprefix("SONG_")] = (song_id, symbol)

    for name in settings:
        if name not in constants:
            errors.append(f"SONG_{name} has no matching constant in include/constants/songs.h")
            continue
        if name not in guarded_by_flag:
            errors.append(f"SONG_{name} is not guarded in sound/song_table.inc")
            continue
        table_id, _ = guarded_by_flag[name]
        if table_id != constants[name]:
            errors.append(
                f"SONG_{name} guards song-table ID {table_id}, expected {constants[name]}"
            )

    for name in guarded_by_flag:
        if name not in settings:
            errors.append(f"sound/song_table.inc uses undefined setting SONG_{name}")

    disabled = {name for name, enabled in settings.items() if not enabled}
    if disabled:
        token_re = re.compile(r"\b(" + "|".join(sorted(disabled)) + r")\b")
        disabled_by_id = {constants[name]: name for name in disabled}
        for path in iter_source_files():
            text = read_text(path)
            if text is None:
                continue
            for line_number, line in enumerate(text.splitlines(), 1):
                for match in token_re.finditer(line):
                    errors.append(
                        f"{path.relative_to(ROOT)}:{line_number}: "
                        f"{match.group(1)} is referenced but SONG_{match.group(1)} is disabled"
                    )
                for match in NUMERIC_SONG_USE_RE.finditer(line):
                    value = next(group for group in match.groups() if group is not None)
                    song_id = int(value, 16 if value.lower().startswith("0x") else 10)
                    if song_id in disabled_by_id:
                        name = disabled_by_id[song_id]
                        errors.append(
                            f"{path.relative_to(ROOT)}:{line_number}: numeric song ID "
                            f"{value} refers to disabled {name}; use the named constant and enable it"
                        )

    if errors:
        print("song configuration check failed:", file=sys.stderr)
        for error in errors:
            print(f"  {error}", file=sys.stderr)
        print(
            "Enable each referenced song in include/config/songs_enabled.h.",
            file=sys.stderr,
        )
        return 1

    print(f"Song configuration: {len(disabled)} unused tracks disabled.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
