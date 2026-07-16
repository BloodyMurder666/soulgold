#include "global.h"
#include "battle_frontier.h"
#include "item.h"
#include "test/test.h"
#include "constants/abilities.h"
#include "constants/battle_frontier_mons.h"
#include "constants/items.h"
#include "constants/moves.h"

TEST("This test checks for rain team creation")
{
    static const struct TrainerMon sMons[] =
    {
        {
            .species = SPECIES_PELIPPER,
            .moves = { MOVE_HURRICANE, MOVE_RAIN_DANCE },
            .heldItem = { ITEM_LEFTOVERS },
            .ability = ABILITY_DRIZZLE,
        },
        {
            .species = SPECIES_FLOATZEL,
            .moves = { MOVE_WATERFALL },
            .heldItem = { ITEM_LIFE_ORB },
            .ability = ABILITY_SWIFT_SWIM,
        },
        {
            .species = SPECIES_KINGDRA,
            .moves = { MOVE_HYDRO_PUMP },
            .heldItem = { ITEM_MYSTIC_WATER },
            .ability = ABILITY_SWIFT_SWIM,
        },
        {
            .species = SPECIES_TORKOAL,
            .moves = { MOVE_SOLAR_BEAM },
            .heldItem = { ITEM_CHARCOAL },
            .ability = ABILITY_DROUGHT,
        },
        {
            .species = SPECIES_GYARADOS,
            .moves = { MOVE_WATERFALL },
            .heldItem = { ITEM_GYARADOSITE },
        },
        {
            .species = SPECIES_SWAMPERT,
            .moves = { MOVE_WATERFALL },
            .heldItem = { ITEM_SWAMPERTITE },
        },
        {
            .species = SPECIES_WOBBUFFET,
            .moves = { MOVE_COUNTER },
            .heldItem = { ITEM_LUM_BERRY },
        },
        {
            .species = SPECIES_CLEFAIRY,
            .moves = { MOVE_FOLLOW_ME },
            .heldItem = { ITEM_EVIOLITE },
        },
        {
            .species = SPECIES_LUDICOLO,
            .moves = { MOVE_SURF },
            .heldItem = { ITEM_DAMP_ROCK },
            .ability = ABILITY_RAIN_DISH,
        },
    };
    static const u16 sMonSet[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, FRONTIER_MON_END };
    static const u16 sPartialMonSet[] = { 0, 1, 6, FRONTIER_MON_END };
    static const u16 sSinglesMonSet[] = { 6, 7, FRONTIER_MON_END };
    u16 chosen[4];
    u16 actualFacilityTeam[FRONTIER_DOUBLES_PARTY_SIZE];
    u16 singlesChoice;
    u32 i;
    u32 megaStoneCount = 0;

    EXPECT(BuildFacilityTrainerMonSelection(sMonSet, sMons, ARRAY_COUNT(sMons), ARRAY_COUNT(chosen),
                                            TRUE, FACILITY_TEAM_RAIN, TRUE,
                                            ARRAY_COUNT(sMons) - 1, chosen));

    // The setter leads, a rain beneficiary follows, and an opposing weather setter is excluded.
    EXPECT_EQ(chosen[0], 0);
    EXPECT(chosen[1] == 1 || chosen[1] == 2 || chosen[1] == 8);
    for (i = 0; i < ARRAY_COUNT(chosen); i++)
    {
        EXPECT_NE(chosen[i], 3);
        if (gItemsInfo[sMons[chosen[i]].heldItem[0]].sortType == ITEM_TYPE_MEGA_STONE)
            megaStoneCount++;
    }
    for (i = 1; i < ARRAY_COUNT(chosen); i++)
        EXPECT(chosen[i] == 1 || chosen[i] == 2 || chosen[i] == 8);
    EXPECT_LE(megaStoneCount, 1);

    // Before 21 wins, only the setter and first beneficiary are required to
    // match. At 21 wins this same undersized core is rejected as incomplete.
    EXPECT(BuildFacilityTrainerMonSelection(sPartialMonSet, sMons, ARRAY_COUNT(sMons), 3,
                                            FALSE, FACILITY_TEAM_RAIN, FALSE,
                                            ARRAY_COUNT(sMons) - 1, chosen));
    EXPECT_EQ(chosen[2], 6);
    EXPECT(!BuildFacilityTrainerMonSelection(sPartialMonSet, sMons, ARRAY_COUNT(sMons), 3,
                                             FALSE, FACILITY_TEAM_RAIN, TRUE,
                                             ARRAY_COUNT(sMons) - 1, chosen));

    // The authored early-streak pool also contains enough compatible spreads to
    // construct a complete rain team under the real facility restrictions.
    EXPECT(BuildFacilityTrainerMonSelection(gBattleFrontierTrainers[0].monSet, gBattleFrontierMons,
                                            NUM_FRONTIER_MONS, ARRAY_COUNT(actualFacilityTeam), TRUE,
                                            FACILITY_TEAM_RAIN, TRUE, FRONTIER_MONS_HIGH_TIER,
                                            actualFacilityTeam));

    // Follow Me is inferred as doubles-only even without an explicit format tag.
    EXPECT(BuildFacilityTrainerMonSelection(sSinglesMonSet, sMons, ARRAY_COUNT(sMons), 1,
                                            FALSE, FACILITY_TEAM_BALANCED,
                                            FALSE,
                                            ARRAY_COUNT(sMons) - 1, &singlesChoice));
    EXPECT_EQ(singlesChoice, 6);
}
