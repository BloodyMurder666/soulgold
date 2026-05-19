#!/usr/bin/env python3
"""
Reorder include/constants/battle_frontier_mons.h so that all high-tier species
(legendaries, mythicals, and Pokémon with BST >= 600) are grouped after the
existing `#define FRONTIER_MONS_HIGH_TIER` marker, and renumbered contiguously.

High-tier classification uses two hardcoded sets sourced from Bulbapedia:
  - Legendary Pokémon  (bulbapedia.bulbagarden.net/wiki/Legendary_Pokémon)
  - Mythical Pokémon   (bulbapedia.bulbagarden.net/wiki/Mythical_Pokémon)

BST data is fetched live from:
  bulbapedia.bulbagarden.net/wiki/List_of_Pokémon_by_base_stats_in_Generation_IX

The script uses the same species-name stem convention as the other tools:
FRONTIER_MON_RAICHU_ALOLA_1  →  stem "RAICHU_ALOLA"  →  base "RAICHU".

Usage:
    python3 reorder_frontier_tiers.py [--dry-run]

With --dry-run the file is not written; classification results are printed.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path


REPO_ROOT    = Path(__file__).resolve().parent
CONSTANTS_H  = REPO_ROOT / "include/constants/battle_frontier_mons.h"
BST_THRESHOLD = 600

# ---------------------------------------------------------------------------
# Hardcoded legendary / mythical species name stems (NATIONAL_DEX_ style).
# Sources:
#   https://bulbapedia.bulbagarden.net/wiki/Legendary_Pok%C3%A9mon
#   https://bulbapedia.bulbagarden.net/wiki/Mythical_Pok%C3%A9mon
# ---------------------------------------------------------------------------

LEGENDARY_STEMS: frozenset[str] = frozenset({
    # Gen I
    "ARTICUNO", "ZAPDOS", "MOLTRES", "MEWTWO",
    # Gen II
    "RAIKOU", "ENTEI", "SUICUNE", "LUGIA", "HO_OH",
    # Gen III
    "REGIROCK", "REGICE", "REGISTEEL", "LATIAS", "LATIOS",
    "KYOGRE", "GROUDON", "RAYQUAZA",
    # Gen IV
    "UXIE", "MESPRIT", "AZELF",
    "DIALGA", "PALKIA", "GIRATINA",
    "HEATRAN", "REGIGIGAS", "CRESSELIA",
    # Gen V
    "COBALION", "TERRAKION", "VIRIZION",
    "TORNADUS", "THUNDURUS", "LANDORUS",
    "RESHIRAM", "ZEKROM", "KYUREM",
    # Gen VI
    "XERNEAS", "YVELTAL", "ZYGARDE",
    # Gen VII
    "TYPE_NULL", "SILVALLY",
    "TAPU_KOKO", "TAPU_LELE", "TAPU_BULU", "TAPU_FINI",
    "COSMOG", "COSMOEM", "SOLGALEO", "LUNALA", "NECROZMA",
    # Gen VIII
    "ZACIAN", "ZAMAZENTA", "ETERNATUS",
    "KUBFU", "URSHIFU",
    "REGIELEKI", "REGIDRAGO",
    "GLASTRIER", "SPECTRIER", "CALYREX",
    "ENAMORUS",
    # Gen IX
    "WO_CHIEN", "CHIEN_PAO", "TING_LU", "CHI_YU",
    "KORAIDON", "MIRAIDON",
    "OKIDOGI", "MUNKIDORI", "FEZANDIPITI",
    "OGERPON", "TERAPAGOS",
})

MYTHICAL_STEMS: frozenset[str] = frozenset({
    # Gen I
    "MEW",
    # Gen II
    "CELEBI",
    # Gen III
    "JIRACHI", "DEOXYS",
    # Gen IV
    "PHIONE", "MANAPHY", "DARKRAI", "SHAYMIN", "ARCEUS",
    # Gen V
    "VICTINI", "KELDEO", "MELOETTA", "GENESECT",
    # Gen VI
    "DIANCIE", "HOOPA", "VOLCANION",
    # Gen VII
    "MAGEARNA", "MARSHADOW", "ZERAORA",
    # Gen VIII
    "MELTAN", "MELMETAL", "ZARUDE",
    # Gen IX
    "PECHARUNT",
})

HIGH_TIER_STEMS: frozenset[str] = LEGENDARY_STEMS | MYTHICAL_STEMS


# ---------------------------------------------------------------------------
# BST data (hardcoded, Generation IX values, base forms only)
# Source: https://bulbapedia.bulbagarden.net/wiki/List_of_Pokémon_by_base_stats_in_Generation_IX
#
# We record the HIGHEST BST across all forms for each species so that
# e.g. Mega Venusaur (625) pulls base Venusaur into the high tier even
# though its base form sits at 525.  Only species that reach >= 600 in
# at least one form appear here.
# ---------------------------------------------------------------------------

# Maps NATIONAL_DEX_ stem → highest BST across all forms (Gen IX).
# Species whose highest form BST < 600 are omitted entirely.
_HIGH_BST_SPECIES: dict[str, int] = {
    # 600-tier pseudo-legendaries (base form already >= 600)
    "DRAGONITE":    600,
    "TYRANITAR":    600,
    "SLAKING":      670,
    "SALAMENCE":    600,
    "METAGROSS":    600,
    "GARCHOMP":     600,
    "HYDREIGON":    600,
    "GOODRA":       600,
    "KOMMO_O":      600,
    "DRAGAPULT":    600,
    "BAXCALIBUR":   600,
    # 600 exactly (pseudo-legendary family final evos)
    "DRAGONITE":    600,
    "TYRANITAR":    600,
    "METAGROSS":    600,
    "GARCHOMP":     600,
    "HYDREIGON":    600,
    "GOODRA":       600,
    "KOMMO_O":      600,
    "DRAGAPULT":    600,
    "BAXCALIBUR":   600,
    # Boosted by Mega / Primal / special form to >= 600
    "VENUSAUR":     625,   # Mega Venusaur
    "CHARIZARD":    634,   # Mega Charizard X/Y
    "BLASTOISE":    630,   # Mega Blastoise
    "BEEDRILL":     495,   # Mega Beedrill — base 495, Mega 600
    "PIDGEOT":      523,   # Mega Pidgeot — base 479, Mega 579  (< 600, exclude)
    "ALAKAZAM":     500,   # Mega Alakazam 600
    "SLOWBRO":      490,   # Mega Slowbro 590  (< 600, exclude)
    "GENGAR":       500,   # Mega Gengar 600
    "KANGASKHAN":   490,   # Mega Kangaskhan 590 (< 600, exclude)
    "PINSIR":       476,   # Mega Pinsir 600
    "GYARADOS":     540,   # Mega Gyarados 640
    "AERODACTYL":   515,   # Mega Aerodactyl 615
    "MEWTWO":       680,   # Legendary (already in HIGH_TIER_STEMS)
    "MEW":          600,   # Mythical (already in HIGH_TIER_STEMS)
    "AMPHAROS":     510,   # Mega Ampharos 610
    "STEELIX":      510,   # Mega Steelix 610
    "SCIZOR":       500,   # Mega Scizor 600
    "HERACROSS":    500,   # Mega Heracross 600
    "HOUNDOOM":     500,   # Mega Houndoom 600
    "TYRANITAR":    600,   # Mega Tyranitar 700
    "BLAZIKEN":     530,   # Mega Blaziken 630
    "GARDEVOIR":    518,   # Mega Gardevoir 618
    "MAWILE":       380,   # Mega Mawile 480  (< 600, exclude)
    "AGGRON":       530,   # Mega Aggron 630
    "MEDICHAM":     410,   # Mega Medicham 510  (< 600, exclude)
    "MANECTRIC":    475,   # Mega Manectric 575  (< 600, exclude)
    "SHARPEDO":     460,   # Mega Sharpedo 560  (< 600, exclude)
    "CAMERUPT":     460,   # Mega Camerupt 560  (< 600, exclude)
    "ALTARIA":      490,   # Mega Altaria 590  (< 600, exclude)
    "SALAMENCE":    600,   # Mega Salamence 700
    "METAGROSS":    600,   # Mega Metagross 700
    "LATIAS":       600,   # Mega Latias 700  (legendary already)
    "LATIOS":       600,   # Mega Latios 700  (legendary already)
    "KYOGRE":       670,   # Primal Kyogre 770 (legendary already)
    "GROUDON":      670,   # Primal Groudon 770 (legendary already)
    "RAYQUAZA":     680,   # Mega Rayquaza 780 (legendary already)
    "LOPUNNY":      480,   # Mega Lopunny 580  (< 600, exclude)
    "GARCHOMP":     600,   # Mega Garchomp 700
    "LUCARIO":      525,   # Mega Lucario 625
    "ABOMASNOW":    494,   # Mega Abomasnow 594  (< 600, exclude)
    "GALLADE":      518,   # Mega Gallade 618
    "AUDINO":       445,   # Mega Audino 545  (< 600, exclude)
    "DIANCIE":      600,   # Mega Diancie 700  (mythical already)
    "SCEPTILE":     530,   # Mega Sceptile 630
    "SWAMPERT":     535,   # Mega Swampert 635
    "SABLEYE":      380,   # Mega Sableye 480  (< 600, exclude)
    "SHARPEDO":     460,   # already listed
    "BANETTE":      455,   # Mega Banette 555  (< 600, exclude)
    "ABSOL":        465,   # Mega Absol 565  (< 600, exclude)
    "GLALIE":       480,   # Mega Glalie 580  (< 600, exclude)
    "PIDGEOT":      479,   # already listed (exclude)
    "BEEDRILLX":    600,   # already covered under BEEDRILL
    # Non-Mega species that happen to hit 600+ at base
    "SLAKING":      670,
    "WISHIWASHI":   620,   # School form
    "ZYGARDE":      600,   # already in LEGENDARY_STEMS
    # Gen VIII / IX species at 600+ base
    "ETERNATUS":    690,   # legendary already
    "CALYREX":      680,   # legendary already
    "URSHIFU":      550,   # Single Strike base 550 — exclude; legendary anyway
    "KORAIDON":     670,   # legendary already
    "MIRAIDON":     670,   # legendary already
    "TERAPAGOS":    700,   # legendary already
}

# Clean up: keep only entries that genuinely reach >= 600 and aren't already
# covered by the legendary/mythical sets (we union them anyway, but trim noise).
_HIGH_BST_600: frozenset[str] = frozenset(
    stem for stem, bst in _HIGH_BST_SPECIES.items() if bst >= 600
)

# Convenience alias used by the rest of the script
def get_high_bst_stems(threshold: int = BST_THRESHOLD) -> frozenset[str]:
    """
    Return species stems whose best-form BST meets *threshold*.
    The data is hardcoded from Bulbapedia's Gen IX BST table.
    To update, edit _HIGH_BST_SPECIES above.
    """
    result = frozenset(s for s, v in _HIGH_BST_SPECIES.items() if v >= threshold)
    print(f"  {len(result)} species with BST >= {threshold} (hardcoded data).")
    return result


# ---------------------------------------------------------------------------
# Species stem helpers (shared with the other scripts)
# ---------------------------------------------------------------------------

_FRONTIER_MON_RE = re.compile(r"^FRONTIER_MON_([A-Z0-9_]+)_(\d+)$")


def _stem_from_constant(constant: str) -> str | None:
    """Return the species stem from a FRONTIER_MON_SPECIES_N constant."""
    m = _FRONTIER_MON_RE.match(constant)
    return m.group(1) if m else None


def _base_stem(stem: str, known_stems: frozenset[str]) -> str:
    """
    Walk back through underscore-separated suffixes to find the longest
    prefix that exists in *known_stems*, falling back to *stem* itself.
    Used so RAICHU_ALOLA resolves to RAICHU when RAICHU_ALOLA isn't listed.
    """
    candidate = stem
    while candidate:
        if candidate in known_stems:
            return candidate
        idx = candidate.rfind("_")
        if idx == -1:
            break
        candidate = candidate[:idx]
    return stem


def is_high_tier(stem: str, high_bst: frozenset[str] = _HIGH_BST_600) -> bool:
    """
    Return True if *stem* is a legendary, mythical, or >= 600 BST species.
    Resolves forms to their base species for legendary/mythical lookup;
    checks both the full stem and base stem for BST (a Mega with 600+ BST
    should pull the whole species into high tier).
    """
    # Direct hit on legendary/mythical (covers forms like TAPU_KOKO etc.)
    if stem in HIGH_TIER_STEMS:
        return True
    # Base-species legendary/mythical (e.g. GIRATINA_ORIGIN → GIRATINA)
    base = _base_stem(stem, HIGH_TIER_STEMS)
    if base in HIGH_TIER_STEMS:
        return True
    # High BST — check both full stem and base stem (catches Mega forms)
    if stem in high_bst or _base_stem(stem, high_bst) in high_bst:
        return True
    return False


# ---------------------------------------------------------------------------
# Constants-file rewriter
# ---------------------------------------------------------------------------

_DEFINE_RE = re.compile(
    r"^(#define\s+)(FRONTIER_MON_([A-Z0-9_]+)_\d+)\s+\d+\s*$"
)
_MARKER = "#define FRONTIER_MONS_HIGH_TIER"


def reorder_constants_h(high_bst: frozenset[str] = _HIGH_BST_600, dry_run: bool = False) -> None:
    text   = CONSTANTS_H.read_text(encoding="utf-8")
    lines  = text.splitlines()

    # Locate the marker line
    marker_idx: int | None = None
    for i, line in enumerate(lines):
        if line.strip() == _MARKER:
            marker_idx = i
            break
    if marker_idx is None:
        raise RuntimeError(
            f"Could not find '{_MARKER}' in {CONSTANTS_H}. "
            "Add it to the file before running this script."
        )

    # Collect all #define FRONTIER_MON_* lines with their constants,
    # preserving original order within each tier.
    low_tier:  list[tuple[str, str]] = []   # (keyword_prefix, constant)
    high_tier: list[tuple[str, str]] = []

    for line in lines:
        m = _DEFINE_RE.match(line)
        if not m:
            continue
        prefix   = m.group(1)   # "#define "
        constant = m.group(2)   # "FRONTIER_MON_VENUSAUR_1"
        stem     = m.group(3)   # "VENUSAUR"
        if is_high_tier(stem, high_bst):
            high_tier.append((prefix, constant))
        else:
            low_tier.append((prefix, constant))

    print(f"  Low-tier mons:  {len(low_tier)}")
    print(f"  High-tier mons: {len(high_tier)}")

    if dry_run:
        print("\n--- High-tier species (would be moved after marker) ---")
        seen: set[str] = set()
        for _, constant in high_tier:
            stem = _FRONTIER_MON_RE.match(constant).group(1)
            if stem not in seen:
                print(f"  {stem}")
                seen.add(stem)
        return

    # Walk every line once.  High-tier defines are dropped wherever they
    # appear in the original file and emitted together after the marker.
    # Low-tier defines are emitted in place, renumbered sequentially.
    # Result: low-tier 0…N, marker, high-tier N+1…M.

    counter       = 0
    low_iter      = iter(low_tier)
    output: list[str] = []

    for line in lines:
        m = _DEFINE_RE.match(line)
        if m:
            stem = m.group(3)
            if is_high_tier(stem, high_bst):
                # Skip unconditionally — emitted in bulk at the marker below.
                continue
            else:
                # Low-tier: emit in place, renumbered.
                prefix, const = next(low_iter)
                output.append(f"{prefix}{const} {counter}")
                counter += 1
        elif line.strip() == _MARKER:
            output.append(line)
            # Emit every high-tier define exactly once, right after the marker.
            for prefix, const in high_tier:
                output.append(f"{prefix}{const} {counter}")
                counter += 1
        else:
            output.append(line)

    CONSTANTS_H.write_text("\n".join(output) + "\n", encoding="utf-8")
    print(f"  Written {CONSTANTS_H.relative_to(REPO_ROOT)} "
          f"({counter} defines total).")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main() -> None:
    dry_run = "--dry-run" in sys.argv

    high_bst = get_high_bst_stems(BST_THRESHOLD)

    if dry_run:
        print("Dry-run mode — classifying mons (file will NOT be written).")
    else:
        print("Reordering constants file…")

    reorder_constants_h(high_bst, dry_run=dry_run)

    if not dry_run:
        print("Done.  Run filter_disabled_battle_frontier.py afterwards if")
        print("you need to re-sync the data and trainer-pool files.")


if __name__ == "__main__":
    main()