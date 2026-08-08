from __future__ import annotations

import unittest
from dataclasses import dataclass

from tools.soulgold_docs.parsers.forms import add_rotom_form_change_locations


@dataclass
class StubSpecies:
    name: str


class RotomFormLocationTests(unittest.TestCase):
    def test_only_alternate_rotom_forms_receive_apartment_location(self) -> None:
        forms = {
            "SPECIES_ROTOM_HEAT",
            "SPECIES_ROTOM_WASH",
            "SPECIES_ROTOM_FROST",
            "SPECIES_ROTOM_FAN",
            "SPECIES_ROTOM_MOW",
        }
        species = {
            constant: StubSpecies(constant.removeprefix("SPECIES_").title())
            for constant in forms | {"SPECIES_ROTOM", "SPECIES_PIKACHU"}
        }
        locations = {}

        add_rotom_form_change_locations(locations, species)  # type: ignore[arg-type]

        self.assertEqual(set(locations), forms)
        for constant in forms:
            with self.subTest(constant=constant):
                self.assertEqual(
                    locations[constant],
                    [
                        {
                            "map": "MAP_GOLDENROD_APARTMENT_BASEMENT",
                            "name": "Goldenrod Apartment Basement",
                            "time": "",
                            "method": "Bring Rotom here to change form",
                            "minLevel": None,
                            "maxLevel": None,
                            "rate": None,
                        }
                    ],
                )


if __name__ == "__main__":
    unittest.main()
