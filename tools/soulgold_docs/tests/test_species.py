from __future__ import annotations

import unittest

from tools.soulgold_docs.parsers.species import parse_species


class SpeciesExtraDataTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.species = parse_species().by_constant

    def test_ev_yields_are_parsed(self) -> None:
        self.assertEqual(self.species["SPECIES_BULBASAUR"].ev_yield, {"spa": 1})
        self.assertEqual(
            self.species["SPECIES_ROTOM"].ev_yield,
            {"spa": 1, "spe": 1},
        )

    def test_egg_groups_are_named_and_deduplicated(self) -> None:
        self.assertEqual(
            self.species["SPECIES_BULBASAUR"].egg_groups,
            ["EGG_GROUP_MONSTER", "EGG_GROUP_GRASS"],
        )
        self.assertEqual(
            self.species["SPECIES_ROTOM"].egg_groups,
            ["EGG_GROUP_AMORPHOUS"],
        )
        self.assertEqual(
            self.species["SPECIES_MEWTWO"].egg_groups,
            ["EGG_GROUP_NO_EGGS_DISCOVERED"],
        )


if __name__ == "__main__":
    unittest.main()
