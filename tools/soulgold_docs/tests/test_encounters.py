from __future__ import annotations

import unittest
from dataclasses import dataclass

from tools.soulgold_docs.parsers.encounters import parse_wild_encounters


@dataclass
class StubSpecies:
    name: str
    sprite: str | None = None


class WildEncounterAggregationTests(unittest.TestCase):
    def test_repeated_rotom_slots_are_combined(self) -> None:
        encounters = parse_wild_encounters(
            {"SPECIES_ROTOM": StubSpecies("Rotom")}  # type: ignore[dict-item]
        )
        nameless_cave_1f = next(
            encounter
            for encounter in encounters
            if encounter["map"] == "MAP_CERULEAN_CAVE_1F"
        )
        land_mons = next(
            method["mons"]
            for method in nameless_cave_1f["variants"][0]["methods"]
            if method["key"] == "land_mons"
        )
        rotom = [mon for mon in land_mons if mon["species"] == "SPECIES_ROTOM"]

        self.assertEqual(len(rotom), 1)
        self.assertEqual(rotom[0]["minLevel"], 58)
        self.assertEqual(rotom[0]["maxLevel"], 69)
        self.assertEqual(rotom[0]["rate"], 5)


if __name__ == "__main__":
    unittest.main()
