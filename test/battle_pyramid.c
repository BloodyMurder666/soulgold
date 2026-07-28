#include "global.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "frontier_util.h"
#include "load_save.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/battle_pyramid.h"

TEST("Battle Pyramid party restoration does not persist temporary facility levels")
{
    static const u16 species[] =
    {
        SPECIES_BULBASAUR,
        SPECIES_CHARMANDER,
        SPECIES_SQUIRTLE,
    };
    static const u8 savedPartySlots[] = {0, 2, 4};
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 0; i < ARRAY_COUNT(species); i++)
    {
        CreateMonWithIVs(&gPlayerParty[savedPartySlots[i]], species[i], 35, 0, OTID_STRUCT_PLAYER_ID, 0);
        gSaveBlock2Ptr->frontier.selectedPartyMons[i] = savedPartySlots[i] + 1;
    }
    SavePlayerParty();

    ZeroPlayerPartyMons();
    for (i = 0; i < ARRAY_COUNT(species); i++)
        gPlayerParty[i] = *GetSavedPlayerPartyMon(savedPartySlots[i]);

    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_50;
    ScaleFrontierPlayerParty();

    gSpecialVar_0x8004 = BATTLE_PYRAMID_FUNC_RESTORE_PARTY;
    CallBattlePyramidFunction();

    for (i = 0; i < ARRAY_COUNT(species); i++)
    {
        EXPECT_EQ(GetMonData(GetSavedPlayerPartyMon(savedPartySlots[i]), MON_DATA_LEVEL), 35);
        EXPECT_EQ(GetMonData(&gPlayerParty[i], MON_DATA_LEVEL), FRONTIER_MAX_LEVEL_50);
    }
}
