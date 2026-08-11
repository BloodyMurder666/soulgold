from __future__ import annotations

import unittest

from tools.soulgold_docs.parsers.moves import parse_moves


class MoveAbilityBoostTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.moves = parse_moves()

    def test_move_flags_expose_their_boosting_abilities(self) -> None:
        expected = {
            "MOVE_MACH_PUNCH": ("ABILITY_IRON_FIST", 20),
            "MOVE_HIGH_JUMP_KICK": ("ABILITY_STEEL_FEET", 20),
            "MOVE_CRUNCH": ("ABILITY_STRONG_JAW", 50),
            "MOVE_WATER_PULSE": ("ABILITY_MEGA_LAUNCHER", 50),
            "MOVE_ORIGIN_PULSE": ("ABILITY_MEGA_LAUNCHER", 50),
            "MOVE_HYPER_VOICE": ("ABILITY_PUNK_ROCK", 30),
            "MOVE_AERIAL_ACE": ("ABILITY_SHARPNESS", 50),
            "MOVE_WATER_SHURIKEN": ("ABILITY_SHARPNESS", 50),
        }
        for move, (ability, percent) in expected.items():
            with self.subTest(move=move):
                self.assertIn(
                    {"ability": ability, "percent": percent},
                    self.moves[move]["abilityBoosts"],
                )

    def test_non_damaging_sound_moves_are_not_marked_as_punk_rock_boosted(self) -> None:
        self.assertEqual(self.moves["MOVE_GROWL"]["abilityBoosts"], [])


if __name__ == "__main__":
    unittest.main()
