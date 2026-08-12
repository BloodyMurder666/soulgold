import unittest
from collections import defaultdict

from tools.soulgold_docs.parsers.items import add_bug_contest_reward_locations


class BugContestItemLocationTests(unittest.TestCase):
    def test_adds_the_correct_place_choice_to_each_reward_stone(self):
        first_place = {
            "ITEM_MOON_STONE",
            "ITEM_SUN_STONE",
            "ITEM_LEAF_STONE",
            "ITEM_DAWN_STONE",
            "ITEM_SHINY_STONE",
            "ITEM_DUSK_STONE",
            "ITEM_ICE_STONE",
        }
        second_place = {
            "ITEM_FIRE_STONE",
            "ITEM_THUNDER_STONE",
            "ITEM_WATER_STONE",
        }
        locations = defaultdict(list)

        add_bug_contest_reward_locations(locations, first_place | second_place)

        for item in first_place:
            self.assertIn(
                {"map": "Bug Catching Contest", "source": "1st place choice"},
                locations[item],
            )
        for item in second_place:
            self.assertIn(
                {"map": "Bug Catching Contest", "source": "2nd place choice"},
                locations[item],
            )


if __name__ == "__main__":
    unittest.main()
