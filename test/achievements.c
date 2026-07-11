#include "global.h"
#include "achievements.h"
#include "event_data.h"
#include "item.h"
#include "test/test.h"
#include "constants/flags.h"
#include "constants/items.h"

TEST("Achievements table contains every id exactly once")
{
    bool8 seen[ACH_COUNT] = {0};
    u16 i;

    EXPECT_EQ(Achievement_GetCount(), ACH_COUNT);
    for (i = 0; i < Achievement_GetCount(); i++)
    {
        const struct Achievement *achievement = Achievement_GetByIndex(i);

        EXPECT(achievement != NULL);
        EXPECT((u32)achievement->id < ACH_COUNT);
        EXPECT(!seen[achievement->id]);
        seen[achievement->id] = TRUE;
        EXPECT(Achievement_GetById(achievement->id) == achievement);
        EXPECT(achievement->name != NULL);
        EXPECT(achievement->description != NULL);
    }
    for (i = 0; i < ACH_COUNT; i++)
        EXPECT(seen[i]);
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
