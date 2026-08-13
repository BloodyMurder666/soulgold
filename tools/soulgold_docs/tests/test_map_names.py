import unittest

from tools.soulgold_docs.map_names import map_constant_display_name


class MapDisplayNameTests(unittest.TestCase):
    def test_internal_foggy_shore_maps_use_their_ingame_names(self) -> None:
        self.assertEqual(map_constant_display_name("MAP_FOGGY_SHORE"), "Route 34")
        self.assertEqual(map_constant_display_name("MAP_FOGGY_SHORE2"), "South Shore")

    def test_renamed_and_split_areas_use_region_map_names(self) -> None:
        self.assertEqual(map_constant_display_name("MAP_ROUTE33SOUTH"), "South Johto Sea")
        self.assertEqual(
            map_constant_display_name("MAP_ROUTE33SOUTH_UNDERWATER"),
            "South Johto Sea Underwater",
        )
        self.assertEqual(map_constant_display_name("MAP_VAJRA_DESERT"), "Vajra Desert West")

    def test_floor_suffixes_are_retained(self) -> None:
        self.assertEqual(
            map_constant_display_name("MAP_CERULEAN_CAVE_B1F"),
            "Nameless Cave B1F",
        )
        self.assertEqual(
            map_constant_display_name("MAP_BURNED_TOWER_B1F"),
            "Burned Tower B1F",
        )


if __name__ == "__main__":
    unittest.main()
