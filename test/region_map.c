#include "global.h"
#include "overworld.h"
#include "region_map.h"
#include "test/test.h"
#include "constants/map_groups.h"
#include "constants/region_map_sections.h"

TEST("Region map assigns Meteor Island to the southern map page")
{
    const struct MapHeader *meteorCave = Overworld_GetMapHeaderByGroupAndId(
        MAP_GROUP(MAP_METEOR_CAVE1), MAP_NUM(MAP_METEOR_CAVE1));

    EXPECT_EQ(meteorCave->regionMapSectionId, MAPSEC_METEOR_ISLAND);
    EXPECT_EQ(GetRegionMapPageForMapSec(MAPSEC_METEOR_ISLAND), REGION_MAP_PAGE_THIRD);
    EXPECT_EQ(GetRegionMapPageScrollXForPage(REGION_MAP_PAGE_THIRD), 0);
    EXPECT_EQ(GetRegionMapPageScrollYForPage(REGION_MAP_PAGE_THIRD), DISPLAY_HEIGHT);
}
