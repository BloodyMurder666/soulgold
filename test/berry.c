#include "global.h"
#include "berry.h"
#include "test/test.h"
#include "constants/berry.h"
#include "constants/items.h"

TEST("Picked natural Berry trees regenerate their original Berry after 24 hours")
{
    struct BerryTree *tree;

    ClearBerryTrees();
    PlantBerryTree(BERRY_TREE_CHERI_1, ITEM_TO_BERRY(ITEM_CHERI_BERRY), BERRY_STAGE_BERRIES, FALSE);
    RemoveBerryTree(BERRY_TREE_CHERI_1);
    tree = GetBerryTreeInfo(BERRY_TREE_CHERI_1);

    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_NO_BERRY);
    EXPECT_EQ((u32)tree->berry, BERRY_NONE);

    BerryTreeTimeUpdate(NATURAL_BERRY_TREE_REGEN_MINUTES - 1);
    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_NO_BERRY);

    BerryTreeTimeUpdate(1);
    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_BERRIES);
    EXPECT_EQ((u32)tree->berry, ITEM_TO_BERRY(ITEM_CHERI_BERRY));
    EXPECT(tree->stopGrowth);
}

TEST("Empty natural Berry trees from existing saves start regenerating without migration")
{
    struct BerryTree *tree;

    ClearBerryTrees();
    tree = GetBerryTreeInfo(BERRY_TREE_RAWST_1);
    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_NO_BERRY);
    EXPECT_EQ((u32)tree->minutesUntilNextStage, 0);

    BerryTreeTimeUpdate(NATURAL_BERRY_TREE_REGEN_MINUTES);

    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_BERRIES);
    EXPECT_EQ((u32)tree->berry, ITEM_TO_BERRY(ITEM_SITRUS_BERRY));
}

TEST("Planting a Berry cancels a natural tree regeneration timer")
{
    struct BerryTree *tree;

    ClearBerryTrees();
    RemoveBerryTree(BERRY_TREE_CHERI_1);
    BerryTreeTimeUpdate(NATURAL_BERRY_TREE_REGEN_MINUTES - 1);

    PlantBerryTree(BERRY_TREE_CHERI_1, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_PLANTED, TRUE);
    BerryTreeTimeUpdate(1);
    tree = GetBerryTreeInfo(BERRY_TREE_CHERI_1);

    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_PLANTED);
    EXPECT_EQ((u32)tree->berry, ITEM_TO_BERRY(ITEM_PECHA_BERRY));
}

TEST("Mulching natural soil without planting prevents regeneration")
{
    struct BerryTree *tree;

    ClearBerryTrees();
    RemoveBerryTree(BERRY_TREE_CHERI_1);
    tree = GetBerryTreeInfo(BERRY_TREE_CHERI_1);
    tree->mulch = ITEM_TO_MULCH(ITEM_GROWTH_MULCH);

    BerryTreeTimeUpdate(NATURAL_BERRY_TREE_REGEN_MINUTES);

    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_NO_BERRY);
    EXPECT_EQ((u32)tree->berry, BERRY_NONE);
    EXPECT_EQ((u32)tree->mulch, ITEM_TO_MULCH(ITEM_GROWTH_MULCH));
}

TEST("Plots that began as empty soil never regenerate a natural Berry")
{
    struct BerryTree *tree;

    ClearBerryTrees();
    BerryTreeTimeUpdate(NATURAL_BERRY_TREE_REGEN_MINUTES * 10);
    tree = GetBerryTreeInfo(BERRY_TREE_ROUTE_104_SOIL_2);

    EXPECT_EQ((u32)tree->stage, BERRY_STAGE_NO_BERRY);
    EXPECT_EQ((u32)tree->berry, BERRY_NONE);
    EXPECT_EQ((u32)tree->minutesUntilNextStage, 0);
}
