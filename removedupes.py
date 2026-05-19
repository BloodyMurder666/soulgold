#!/usr/bin/env python3
"""
Filter disabled Pokémon species from Battle Frontier .h files.

Reads the enabled National Dex constants from include/constants/pokedex.h
(which filter_disabled_pokedex.py already keeps up to date), then rewrites:

  include/constants/battle_frontier_mons.h
      Removes #define lines for disabled species and renumbers the
      remaining defines contiguously from 0.

  src/data/battle_frontier/battle_frontier_mons.h
      Removes [FRONTIER_MON_*] = { ... } entry blocks for disabled species.

  src/data/battle_frontier/battle_frontier_trainer_mons.h
      Removes FRONTIER_MON_* lines for disabled species from every pool macro.
"""

from __future__ import annotations

import re
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent

POKEDEX_H      = REPO_ROOT / "include/constants/pokedex.h"
CONSTANTS_H    = REPO_ROOT / "include/constants/battle_frontier_mons.h"
DATA_MONS_H    = REPO_ROOT / "src/data/battle_frontier/battle_frontier_mons.h"
TRAINER_MONS_H = REPO_ROOT / "src/data/battle_frontier/battle_frontier_trainer_mons.h"

# #define FRONTIER_MON_VENUSAUR_1 42
DEFINE_RE = re.compile(r"^(#define\s+)(FRONTIER_MON_([A-Z0-9_]+)_\d+)\s+\d+\s*$")

# Extract the species name from a FRONTIER_MON constant, e.g. VENUSAUR from FRONTIER_MON_VENUSAUR_3
FRONTIER_MON_RE = re.compile(r"\bFRONTIER_MON_([A-Z0-9_]+)_\d+\b")


# ---------------------------------------------------------------------------
# Shared: determine which species are enabled
# ---------------------------------------------------------------------------

def species_is_enabled(stem: str, enabled: set[str]) -> bool:
    """
    Return True if *stem* (e.g. "RAICHU_ALOLA", "VENUSAUR", "MR_MIME") is
    considered enabled.

    Forms share the Pokédex entry of their base species, so a frontier mon
    like FRONTIER_MON_RAICHU_ALOLA_1 should be kept whenever RAICHU is
    enabled.  We check the full stem first, then iteratively strip the
    rightmost _WORD suffix until we either find a match or run out of parts.

    Examples:
        "VENUSAUR"      -> check "VENUSAUR"              (direct hit)
        "RAICHU_ALOLA"  -> check "RAICHU_ALOLA", "RAICHU"
        "MR_MIME_GALAR" -> check "MR_MIME_GALAR", "MR_MIME", "MR"
                           (MR_MIME matches before we over-strip)
    """
    candidate = stem
    while candidate:
        if candidate in enabled:
            return True
        idx = candidate.rfind("_")
        if idx == -1:
            break
        candidate = candidate[:idx]
    return False


def parse_enabled_species_names() -> set[str]:
    """
    Return the set of upper-case species name stems that are enabled,
    e.g. {"VENUSAUR", "CHARIZARD", "NIDORAN_F", ...}.

    Reads the NationalDexOrder enum from include/constants/pokedex.h, which
    filter_disabled_pokedex.py already keeps pruned to only enabled species.
    Strips the NATIONAL_DEX_ prefix from each constant.
    """
    text = POKEDEX_H.read_text(encoding="utf-8")
    enabled: set[str] = set()
    in_enum = False

    for line in text.splitlines():
        if line.startswith("enum NationalDexOrder"):
            in_enum = True
            continue
        if in_enum:
            if line.startswith("};"):
                break
            m = re.search(r"\bNATIONAL_DEX_([A-Z0-9_]+)\b", line)
            if m and m.group(1) != "NONE":
                enabled.add(m.group(1))

    if not enabled:
        raise RuntimeError(
            f"No NATIONAL_DEX_* constants found in {POKEDEX_H}. "
            "Has filter_disabled_pokedex.py been run?"
        )
    return enabled


# ---------------------------------------------------------------------------
# include/constants/battle_frontier_mons.h
# ---------------------------------------------------------------------------

def rewrite_constants_h(enabled: set[str]) -> None:
    text = CONSTANTS_H.read_text(encoding="utf-8")
    output: list[str] = []
    counter = 0

    for line in text.splitlines():
        m = DEFINE_RE.match(line)
        if m:
            constant = m.group(2)       # e.g. FRONTIER_MON_VENUSAUR_1
            species  = m.group(3)       # e.g. VENUSAUR
            if not species_is_enabled(species, enabled):
                continue                # drop disabled species
            # Renumber: keep original spacing style but replace the value
            output.append(f"{m.group(1)}{constant} {counter}")
            counter += 1
        else:
            output.append(line)

    CONSTANTS_H.write_text("\n".join(output) + "\n", encoding="utf-8")
    print(f"  {CONSTANTS_H.relative_to(REPO_ROOT)}: kept {counter} frontier mon defines.")


# ---------------------------------------------------------------------------
# src/data/battle_frontier/battle_frontier_mons.h
# ---------------------------------------------------------------------------

def rewrite_data_mons_h(enabled: set[str]) -> None:
    """
    Remove entire entry blocks of the form:

        [FRONTIER_MON_SPECIES_N] = {
            ...
        },

    for disabled species.  The block ends at the first line that is exactly
    `    },` (four spaces, closing brace, comma) after the opening `[…] = {`.
    """
    text = DATA_MONS_H.read_text(encoding="utf-8")
    lines = text.splitlines()
    output: list[str] = []
    kept = 0
    dropped = 0

    # Match the opening line of an entry: optional whitespace [FRONTIER_MON_…] = {
    ENTRY_START_RE = re.compile(r"^\s*\[(FRONTIER_MON_([A-Z0-9]+)_\d+)\]\s*=\s*\{")
    # Match the closing line of an entry
    ENTRY_END_RE   = re.compile(r"^\s*\},\s*$")

    i = 0
    while i < len(lines):
        line = lines[i]
        m = ENTRY_START_RE.match(line)
        if m:
            species = m.group(2)
            if not species_is_enabled(species, enabled):
                # Skip until we find the matching closing `},`
                i += 1
                while i < len(lines):
                    if ENTRY_END_RE.match(lines[i]):
                        i += 1          # skip the `},` line too
                        break
                    i += 1
                dropped += 1
                continue
            else:
                output.append(line)
                kept += 1
        else:
            output.append(line)
        i += 1

    DATA_MONS_H.write_text("\n".join(output) + "\n", encoding="utf-8")
    print(f"  {DATA_MONS_H.relative_to(REPO_ROOT)}: kept {kept} entries, removed {dropped}.")


# ---------------------------------------------------------------------------
# src/data/battle_frontier/battle_frontier_trainer_mons.h
# ---------------------------------------------------------------------------

def rewrite_trainer_mons_h(enabled: set[str]) -> None:
    """
    Remove any line whose only meaningful content is a FRONTIER_MON_* constant
    for a disabled species.  These lines look like:

        FRONTIER_MON_VENUSAUR_1, \
        FRONTIER_MON_VENUSAUR_1,       <- last entry, no backslash

    We also tidy up a trailing backslash on the line that becomes the new last
    entry in a macro if the original last entry was removed.
    """
    text = TRAINER_MONS_H.read_text(encoding="utf-8")
    lines = text.splitlines()
    output: list[str] = []
    removed = 0

    # A line that consists of optional whitespace, a FRONTIER_MON constant,
    # optional comma, optional backslash continuation.
    LINE_RE = re.compile(
        r"^(\s*)(FRONTIER_MON_([A-Z0-9_]+)_\d+)(,?)(\s*\\?)?\s*$"
    )

    for line in lines:
        m = LINE_RE.match(line)
        if m:
            species = m.group(3)
            if not species_is_enabled(species, enabled):
                removed += 1
                continue
        output.append(line)

    # Fix up trailing backslashes: if a FRONTIER_MON line that we kept is now
    # the last entry before the macro ends, its trailing `\` must be removed.
    # We only strip `\` when the next non-blank line is a genuine macro
    # terminator — a line starting with `#` (preprocessor directive) or the
    # end of the file.  We must NOT strip when the next line is some other
    # continuation we don't own (e.g. macro-template lines like
    # FRONTIER_MON_##legend##_1 or any other non-FRONTIER_MON content that is
    # still part of the same macro body).
    TERMINATOR_RE = re.compile(r"^\s*#")   # preprocessor line ends the macro

    cleaned: list[str] = []
    for idx, line in enumerate(output):
        stripped = line.rstrip()
        if stripped.endswith("\\"):
            rest = output[idx + 1:]
            next_nonblank = next((l for l in rest if l.strip()), "")
            # Strip the backslash only if nothing follows, or a preprocessor
            # directive follows (meaning the macro definition is over).
            if not next_nonblank or TERMINATOR_RE.match(next_nonblank):
                line = stripped[:-1].rstrip()
        cleaned.append(line)

    TRAINER_MONS_H.write_text("\n".join(cleaned) + "\n", encoding="utf-8")
    print(
        f"  {TRAINER_MONS_H.relative_to(REPO_ROOT)}: removed {removed} pool entries."
    )


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main() -> None:
    print(f"Parsing enabled species from {POKEDEX_H.relative_to(REPO_ROOT)}…")
    enabled = parse_enabled_species_names()
    print(f"  {len(enabled)} species enabled.")

    print("Rewriting battle frontier files…")
    rewrite_constants_h(enabled)
    rewrite_data_mons_h(enabled)
    rewrite_trainer_mons_h(enabled)
    print("Done.")


if __name__ == "__main__":
    main()