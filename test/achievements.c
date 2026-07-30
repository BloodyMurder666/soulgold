#include "global.h"
#include "achievements.h"
#include "event_data.h"
#include "item.h"
#include "overworld.h"
#include "pokedex.h"
#include "pokemon.h"
#include "test/test.h"
#include "tv.h"
#include "constants/flags.h"
#include "constants/battle_frontier.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/species.h"

TEST("Achievements table contains every id exactly once")
{
    bool8 seen[ACHIEVEMENTS_MAX] = {0};
    u16 i;

    EXPECT_EQ(Achievement_GetCount(), ACH_COUNT);
    for (i = 0; i < Achievement_GetCount(); i++)
    {
        const struct Achievement *achievement = Achievement_GetByIndex(i);

        EXPECT(achievement != NULL);
        EXPECT((u32)achievement->id < ACHIEVEMENTS_MAX);
        EXPECT(!seen[achievement->id]);
        seen[achievement->id] = TRUE;
        EXPECT(Achievement_GetById(achievement->id) == achievement);
        EXPECT(achievement->name != NULL);
        EXPECT(achievement->description != NULL);
    }
    for (i = 0; i < ACH_ID_COUNT; i++)
    {
        if (i == ACH_LEGACY_SOUTHERN_VACATION
         || i == ACH_LEGACY_CATCH_KYOGRE
         || i == ACH_LEGACY_CATCH_GROUDON
         || i == ACH_LEGACY_CATCH_DEOXYS)
            EXPECT(!seen[i]);
        else
            EXPECT(seen[i]);
    }
    EXPECT(Achievement_GetByIndex(ACH_COUNT) == NULL);
}

TEST("Achievements initialize only their reserved save region")
{
    u16 i;

    memset(&gSaveBlock1Ptr->achievements, 0xA5, sizeof(gSaveBlock1Ptr->achievements));
    gSaveBlock1Ptr->achievements.magic = 0;

    Achievement_EnsureSaveInitialized();

    EXPECT_EQ(gSaveBlock1Ptr->achievements.magic, ACHIEVEMENT_SAVE_MAGIC);
    for (i = 0; i < ACH_COUNTER_COUNT; i++)
        EXPECT_EQ(gSaveBlock1Ptr->achievements.counters[i], 0);
    for (i = 0; i < ACHIEVEMENT_UNLOCKED_BYTES; i++)
        EXPECT_EQ(gSaveBlock1Ptr->achievements.unlocked[i], 0);
    for (i = 0; i < ACHIEVEMENT_POPUP_QUEUE_SIZE; i++)
        EXPECT_EQ(gSaveBlock1Ptr->achievements.popupQueue[i], 0);
}

TEST("Achievements reject ids outside the save bitmap")
{
    EXPECT(!Achievement_IsUnlocked((enum AchievementId)-1));
    EXPECT(!Achievement_Unlock((enum AchievementId)-1));
    EXPECT(!Achievement_IsUnlocked((enum AchievementId)ACHIEVEMENTS_MAX));
    EXPECT(!Achievement_Unlock((enum AchievementId)ACHIEVEMENTS_MAX));
}

TEST("Achievement unlocks are idempotent and queue one popup")
{
    Achievement_EnsureSaveInitialized();

    EXPECT(Achievement_Unlock(ACH_RECEIVE_STARTER));
    EXPECT(Achievement_IsUnlocked(ACH_RECEIVE_STARTER));
    EXPECT_EQ(gSaveBlock1Ptr->achievements.popupQueue[0], ACH_RECEIVE_STARTER + 1);
    EXPECT_EQ(gSaveBlock1Ptr->achievements.popupQueue[1], 0);

    EXPECT(!Achievement_Unlock(ACH_RECEIVE_STARTER));
    EXPECT_EQ(gSaveBlock1Ptr->achievements.popupQueue[0], ACH_RECEIVE_STARTER + 1);
    EXPECT_EQ(gSaveBlock1Ptr->achievements.popupQueue[1], 0);
}

TEST("Achievement counters saturate and unlock every crossed threshold")
{
    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.counters[ACH_COUNTER_CRITICAL_HITS] = UINT_MAX - 1;

    Achievement_IncrementCounter(ACH_COUNTER_CRITICAL_HITS, 10);

    EXPECT_EQ(Achievement_GetCounter(ACH_COUNTER_CRITICAL_HITS), UINT_MAX);
    EXPECT(Achievement_IsUnlocked(ACH_FIRST_CRITICAL));
    EXPECT(Achievement_IsUnlocked(ACH_CRITICAL_100));
}

TEST("Planting the tenth Berry unlocks Green Thumb")
{
    const struct Achievement *achievement = Achievement_GetById(ACH_PLANT_BERRIES_10);
    u8 i;

    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.unlocked[ACH_LEGACY_SOUTHERN_VACATION / 8] |= 1 << (ACH_LEGACY_SOUTHERN_VACATION % 8);
    SetGameStat(GAME_STAT_PLANTED_BERRIES, 100);

    EXPECT_EQ(Achievement_GetProgress(achievement), 0);
    EXPECT_EQ(Achievement_GetTarget(achievement), 10);
    EXPECT(!Achievement_IsUnlocked(ACH_PLANT_BERRIES_10));

    for (i = 0; i < 9; i++)
        IncrementDailyPlantedBerries();

    EXPECT_EQ(Achievement_GetProgress(achievement), 9);
    EXPECT(!Achievement_IsUnlocked(ACH_PLANT_BERRIES_10));

    IncrementDailyPlantedBerries();
    EXPECT_EQ(Achievement_GetProgress(achievement), 10);
    EXPECT(Achievement_IsUnlocked(ACH_PLANT_BERRIES_10));
}

TEST("Legacy Deoxys completion does not unlock Hoopa")
{
    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.unlocked[ACH_LEGACY_CATCH_DEOXYS / 8] |= 1 << (ACH_LEGACY_CATCH_DEOXYS % 8);

    Achievement_CheckAll();

    EXPECT(Achievement_GetById(ACH_LEGACY_CATCH_DEOXYS) == NULL);
    EXPECT(Achievement_IsUnlocked(ACH_LEGACY_CATCH_DEOXYS));
    EXPECT(!Achievement_IsUnlocked(ACH_CATCH_HOOPA));
    EXPECT_EQ(Achievement_CountUnlocked(), 0);
}

TEST("Legacy Kyogre and Groudon completions do not unlock the new Swords of Justice")
{
    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.unlocked[ACH_LEGACY_CATCH_KYOGRE / 8] |= 1 << (ACH_LEGACY_CATCH_KYOGRE % 8);
    gSaveBlock1Ptr->achievements.unlocked[ACH_LEGACY_CATCH_GROUDON / 8] |= 1 << (ACH_LEGACY_CATCH_GROUDON % 8);

    Achievement_CheckAll();

    EXPECT(Achievement_GetById(ACH_LEGACY_CATCH_KYOGRE) == NULL);
    EXPECT(Achievement_GetById(ACH_LEGACY_CATCH_GROUDON) == NULL);
    EXPECT(Achievement_IsUnlocked(ACH_LEGACY_CATCH_KYOGRE));
    EXPECT(Achievement_IsUnlocked(ACH_LEGACY_CATCH_GROUDON));
    EXPECT(!Achievement_IsUnlocked(ACH_CATCH_COBALION));
    EXPECT(!Achievement_IsUnlocked(ACH_CATCH_TERRAKION));
    EXPECT_EQ(Achievement_CountUnlocked(), 0);
}

TEST("Battle Point achievement tracking does not alter spendable points")
{
    gSaveBlock2Ptr->frontier.battlePoints = 42;
    gSaveBlock2Ptr->frontier.cardBattlePoints = 10;

    Achievement_AddBattlePointsEarned(90);

    EXPECT_EQ(gSaveBlock2Ptr->frontier.battlePoints, 42);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.cardBattlePoints, 100);
    EXPECT(Achievement_IsUnlocked(ACH_BATTLE_CONNOISSEUR));
}

TEST("Battle Point lifetime total saturates independently")
{
    gSaveBlock2Ptr->frontier.battlePoints = 7;
    gSaveBlock2Ptr->frontier.cardBattlePoints = 0xFFFE;

    Achievement_AddBattlePointsEarned(10);

    EXPECT_EQ(gSaveBlock2Ptr->frontier.battlePoints, 7);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.cardBattlePoints, 0xFFFF);
}

TEST("Adding the final type Mega Stone checks Mega Collector immediately")
{
    enum Item item;

    for (item = ITEM_NORMALITE; item < ITEM_BONDSTONE; item++)
        EXPECT(AddBagItem(item, 1));
    EXPECT(!Achievement_IsUnlocked(ACH_MEGA_COLLECTOR));

    EXPECT(AddBagItem(ITEM_BONDSTONE, 1));
    EXPECT(Achievement_IsUnlocked(ACH_MEGA_COLLECTOR));
}

TEST("Counter-specific checks ignore event-only achievements")
{
    Achievement_CheckCounter(ACH_COUNTER_NONE);

    EXPECT_EQ(Achievement_CountUnlocked(), 0);
}

TEST("Chaos Factory rentals do not unlock Peak of Power in the results lobby")
{
    gMapHeader.mapLayoutId = LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY;
    gSaveBlock2Ptr->frontier.challengeStatus = CHALLENGE_STATUS_WON;
    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_OPEN;
    CreateMon(&gPlayerParty[0], SPECIES_BULBASAUR, MAX_LEVEL, 0, OTID_STRUCT_PLAYER_ID);

    Achievement_CheckAll();

    EXPECT(!Achievement_IsUnlocked(ACH_PEAK_OF_POWER));

    // Once the challenge is over, a real level 100 party member still counts.
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    Achievement_CheckAll();
    EXPECT(Achievement_IsUnlocked(ACH_PEAK_OF_POWER));
}

TEST("Regular Pikachu and Eevee do not unlock Let's Go")
{
    GetSetPokedexFlag(NATIONAL_DEX_PIKACHU, FLAG_SET_CAUGHT);
    GetSetPokedexFlag(NATIONAL_DEX_EEVEE, FLAG_SET_CAUGHT);

    Achievement_CheckAll();

    EXPECT(!Achievement_IsUnlocked(ACH_LETS_GO));
}

TEST("Receiving Partner Pikachu as a scripted gift unlocks Let's Go")
{
    struct Pokemon mon;

    CreateMon(&mon, SPECIES_PIKACHU_STARTER, 25, 0, OTID_STRUCT_PLAYER_ID);

    EXPECT_NE(GiveScriptedMonToPlayer(&mon, PARTY_SIZE), MON_CANT_GIVE);
    EXPECT(Achievement_IsUnlocked(ACH_LETS_GO));
}

TEST("Obtaining Partner Eevee through a captured-mon transfer unlocks Let's Go")
{
    struct Pokemon mon;

    CreateMon(&mon, SPECIES_EEVEE_STARTER, 25, 0, OTID_STRUCT_PLAYER_ID);

    EXPECT_NE(GiveCapturedMonToPlayer(&mon), MON_CANT_GIVE);
    EXPECT(Achievement_IsUnlocked(ACH_LETS_GO));
}

TEST("Regular Ursaluna does not unlock Blood Moon")
{
    GetSetPokedexFlag(NATIONAL_DEX_URSALUNA, FLAG_SET_CAUGHT);

    Achievement_CheckAll();

    EXPECT(!Achievement_IsUnlocked(ACH_CATCH_BLOOD_MOON_URSALUNA));
}

TEST("Obtaining Blood Moon Ursaluna unlocks Blood Moon")
{
    struct Pokemon mon;

    CreateMon(&mon, SPECIES_URSALUNA_BLOODMOON, 70, 0, OTID_STRUCT_PLAYER_ID);

    EXPECT_NE(GiveCapturedMonToPlayer(&mon), MON_CANT_GIVE);
    EXPECT(Achievement_IsUnlocked(ACH_CATCH_BLOOD_MOON_URSALUNA));
}

TEST("Route Experts requires every implemented expert")
{
    FlagSet(FLAG_ROUTE31_EXPERT);
    FlagSet(FLAG_GOLDENRODSHORE_EXPERT);
    FlagSet(FLAG_ROUTE43_EXPERT);
    FlagSet(FLAG_ROUTE47_EXPERT);
    Achievement_CheckAll();
    EXPECT(!Achievement_IsUnlocked(ACH_ROUTE_EXPERTS));

    FlagSet(FLAG_ROUTE27_EXPERT);
    Achievement_CheckAll();
    EXPECT(Achievement_IsUnlocked(ACH_ROUTE_EXPERTS));
}
