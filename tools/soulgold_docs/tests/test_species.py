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

    def test_dex_filter_categories_are_parsed(self) -> None:
        self.assertIn("legendary", self.species["SPECIES_MEWTWO"].categories)
        self.assertIn("mythical", self.species["SPECIES_MEW"].categories)
        self.assertIn("paradox", self.species["SPECIES_GREAT_TUSK"].categories)
        self.assertIn("mega", self.species["SPECIES_VENUSAUR_MEGA"].categories)
        self.assertIn("regional", self.species["SPECIES_RAICHU_ALOLA"].categories)
        self.assertEqual(self.species["SPECIES_RATTATA"].categories, [])


if __name__ == "__main__":
    unittest.main()
