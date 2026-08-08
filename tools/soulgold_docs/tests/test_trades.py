from __future__ import annotations

import unittest
from dataclasses import dataclass

from tools.soulgold_docs.parsers.trades import (
    _trade_species,
    add_johto_trade_species_locations,
)


@dataclass
class StubSpecies:
    name: str


class JohtoTradeLocationTests(unittest.TestCase):
    def test_only_the_allowed_johto_trades_become_locations(self) -> None:
        species = {
            constant: StubSpecies(constant.removeprefix("SPECIES_").replace("_", " ").title())
            for trade in _trade_species().values()
            for constant in trade
        }
        species.update(
            {
                "SPECIES_PAWMI": StubSpecies("Pawmi"),
                "SPECIES_COTTONEE": StubSpecies("Cottonee"),
                "SPECIES_SLOWPOKE_GALAR": StubSpecies("Galarian Slowpoke"),
                "SPECIES_SLOWPOKE": StubSpecies("Slowpoke"),
                "SPECIES_HONEDGE": StubSpecies("Honedge"),
                "SPECIES_CLEFAIRY": StubSpecies("Clefairy"),
                "SPECIES_VOLTORB_HISUI": StubSpecies("Hisuian Voltorb"),
                "SPECIES_MAREANIE": StubSpecies("Mareanie"),
                "SPECIES_MELTAN": StubSpecies("Meltan"),
                "SPECIES_TINKATON": StubSpecies("Tinkaton"),
                "SPECIES_GABITE": StubSpecies("Gabite"),
                "SPECIES_DRAGONAIR": StubSpecies("Dragonair"),
            }
        )
        locations = {}

        add_johto_trade_species_locations(locations, species)  # type: ignore[arg-type]

        self.assertEqual(
            set(locations),
            {
                "SPECIES_PAWMI",
                "SPECIES_SLOWPOKE_GALAR",
                "SPECIES_HONEDGE",
                "SPECIES_VOLTORB_HISUI",
                "SPECIES_MELTAN",
                "SPECIES_GABITE",
                "SPECIES_ROTOM",
            },
        )
        expected = {
            "SPECIES_PAWMI": ("MAP_VIOLET_CITY_HOUSE1", "Violet City", "Cottonee"),
            "SPECIES_SLOWPOKE_GALAR": (
                "MAP_AZALEA_TOWN_HOUSE2",
                "Azalea Town",
                "Slowpoke",
            ),
            "SPECIES_HONEDGE": (
                "MAP_GOLDENROD_CITY_DEPARTMENT_STORE_5F",
                "Goldenrod Dept Store",
                "Clefairy",
            ),
            "SPECIES_VOLTORB_HISUI": (
                "MAP_OLIVINE_CITY_HOUSE1",
                "Olivine City",
                "Mareanie",
            ),
            "SPECIES_MELTAN": (
                "MAP_RINTO_HOUSE3",
                "Rinto Village",
                "Tinkaton",
            ),
            "SPECIES_GABITE": (
                "MAP_BLACKTHORN_CITY_HOUSE2",
                "Blackthorn City",
                "Dragonair",
            ),
            "SPECIES_ROTOM": (
                "MAP_GATE_ROUTE39NORTH",
                "Route 39-Route 49 Gatehouse",
                "Zorua",
            ),
        }
        for constant, (map_constant, area, requirement) in expected.items():
            with self.subTest(constant=constant):
                self.assertEqual(len(locations[constant]), 1)
                location = locations[constant][0]
                self.assertEqual(location["map"], map_constant)
                self.assertEqual(location["name"], area)
                self.assertEqual(
                    location["method"],
                    f"In-game trade (requires {requirement})",
                )
                self.assertIsNone(location["minLevel"])
                self.assertIsNone(location["maxLevel"])


if __name__ == "__main__":
    unittest.main()
