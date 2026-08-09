from __future__ import annotations

import unittest

from tools.soulgold_docs.parsers.gifts import add_gift_species_locations


class GiftLocationTests(unittest.TestCase):
    def test_achievement_rewards_include_their_trophy_milestones(self) -> None:
        expected = {
            "SPECIES_GRENINJA_BOND": 30,
            "SPECIES_POIPOLE": 45,
            "SPECIES_FLOETTE_ETERNAL": 60,
            "SPECIES_ZARUDE": 75,
            "SPECIES_MAGEARNA_ORIGINAL": 100,
        }
        locations = {}

        add_gift_species_locations(  # type: ignore[arg-type]
            locations,
            {species: object() for species in expected},
        )

        for species, trophies in expected.items():
            with self.subTest(species=species):
                self.assertEqual(len(locations[species]), 1)
                location = locations[species][0]
                self.assertEqual(location["map"], "MAP_ROUTE40_HOUSE4")
                self.assertEqual(
                    location["name"],
                    f"Route 40 Achievement reward ({trophies} trophies)",
                )
                self.assertEqual(location["method"], "Gift")


if __name__ == "__main__":
    unittest.main()
