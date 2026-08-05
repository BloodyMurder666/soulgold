#include "global.h"
#include "achievements.h"
#include "battle_tower.h"
#include "event_data.h"
#include "item.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/items.h"
#include "constants/vars.h"

TEST("Battle Cafe Endless Challenge records its own streak")
{
    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE);
    VarSet(VAR_TEMP_9, 7);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD, 6);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD, 12);

    BattleCafe_AdvanceWinCount();

    EXPECT_EQ(VarGet(VAR_TEMP_9), 8);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD), 8);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD), 12);
}

TEST("Battle Cafe Endless Rush records its own streak")
{
    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH);
    VarSet(VAR_TEMP_9, 14);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD, 20);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD, 9);

    BattleCafe_AdvanceWinCount();

    EXPECT_EQ(VarGet(VAR_TEMP_9), 15);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD), 20);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD), 15);
}

TEST("Battle Cafe Endless Challenge unlocks Endless Master at 15 wins")
{
    const struct Achievement *achievement = Achievement_GetById(ACH_BATTLE_CAFE_ENDLESS_MASTER);

    EXPECT(achievement != NULL);
    EXPECT_EQ(achievement->tier, ACH_TIER_PLATINUM);
    EXPECT_EQ(Achievement_GetTierBallItem(achievement->tier), ITEM_MASTER_BALL);

    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE);
    VarSet(VAR_TEMP_9, BATTLE_CAFE_ENDLESS_MASTER_STREAK - 2);

    BattleCafe_AdvanceWinCount();
    EXPECT_EQ(VarGet(VAR_TEMP_9), BATTLE_CAFE_ENDLESS_MASTER_STREAK - 1);
    EXPECT(!Achievement_IsUnlocked(ACH_BATTLE_CAFE_ENDLESS_MASTER));

    BattleCafe_AdvanceWinCount();
    EXPECT_EQ(VarGet(VAR_TEMP_9), BATTLE_CAFE_ENDLESS_MASTER_STREAK);
    EXPECT(Achievement_IsUnlocked(ACH_BATTLE_CAFE_ENDLESS_MASTER));
}

TEST("Battle Cafe Endless Rush does not unlock Endless Master")
{
    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH);
    VarSet(VAR_TEMP_9, BATTLE_CAFE_ENDLESS_MASTER_STREAK - 1);

    BattleCafe_AdvanceWinCount();

    EXPECT_EQ(VarGet(VAR_TEMP_9), BATTLE_CAFE_ENDLESS_MASTER_STREAK);
    EXPECT(!Achievement_IsUnlocked(ACH_BATTLE_CAFE_ENDLESS_MASTER));
}

TEST("Battle Cafe fixed challenges do not change Endless records")
{
    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY);
    VarSet(VAR_TEMP_9, 1);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD, 4);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD, 5);

    BattleCafe_AdvanceWinCount();

    EXPECT_EQ(VarGet(VAR_TEMP_9), 2);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD), 4);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_RUSH_RECORD), 5);
}

TEST("Battle Cafe streaks saturate without wrapping")
{
    VarSet(VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE);
    VarSet(VAR_TEMP_9, BATTLE_CAFE_MAX_STREAK);
    VarSet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD, BATTLE_CAFE_MAX_STREAK - 1);

    BattleCafe_AdvanceWinCount();

    EXPECT_EQ(VarGet(VAR_TEMP_9), BATTLE_CAFE_MAX_STREAK);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_ENDLESS_CHALLENGE_RECORD), BATTLE_CAFE_MAX_STREAK);
}

TEST("Battle Cafe point awards saturate and report the amount received")
{
    VarSet(VAR_BATTLE_CAFE_POINTS, BATTLE_CAFE_MAX_POINTS - 1);
    gSpecialVar_0x8004 = 5;

    BattleCafe_AwardPoints();

    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), BATTLE_CAFE_MAX_POINTS);
    EXPECT_EQ(gSpecialVar_Result, 1);

    gSpecialVar_0x8004 = 2;
    BattleCafe_AwardPoints();

    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), BATTLE_CAFE_MAX_POINTS);
    EXPECT_EQ(gSpecialVar_Result, 0);
}

TEST("Battle Cafe point awards repair an out-of-range saved total")
{
    VarSet(VAR_BATTLE_CAFE_POINTS, MAX_u16);
    gSpecialVar_0x8004 = 1;

    BattleCafe_AwardPoints();

    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), BATTLE_CAFE_MAX_POINTS);
    EXPECT_EQ(gSpecialVar_Result, 0);
}

TEST("Battle Cafe Attack vitamin set gives two Protein EX and Calcium EX for four points")
{
    ClearBag();
    VarSet(VAR_BATTLE_CAFE_POINTS, 4);
    gSpecialVar_0x8004 = BATTLE_CAFE_VITAMIN_SET_ATK;

    BattleCafe_TryPurchaseVitaminSet();

    EXPECT_EQ(gSpecialVar_Result, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), 0);
    EXPECT(CheckBagHasItem(ITEM_PROTEIN_EX, 2));
    EXPECT(CheckBagHasItem(ITEM_CALCIUM_EX, 2));
}

TEST("Battle Cafe Defense vitamin set gives two Iron EX and Zinc EX for four points")
{
    ClearBag();
    VarSet(VAR_BATTLE_CAFE_POINTS, 4);
    gSpecialVar_0x8004 = BATTLE_CAFE_VITAMIN_SET_DEF;

    BattleCafe_TryPurchaseVitaminSet();

    EXPECT_EQ(gSpecialVar_Result, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), 0);
    EXPECT(CheckBagHasItem(ITEM_IRON_EX, 2));
    EXPECT(CheckBagHasItem(ITEM_ZINC_EX, 2));
}

TEST("Battle Cafe Speed vitamin set gives two Carbos EX for two points")
{
    ClearBag();
    VarSet(VAR_BATTLE_CAFE_POINTS, 2);
    gSpecialVar_0x8004 = BATTLE_CAFE_VITAMIN_SET_SPE;

    BattleCafe_TryPurchaseVitaminSet();

    EXPECT_EQ(gSpecialVar_Result, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), 0);
    EXPECT(CheckBagHasItem(ITEM_CARBOS_EX, 2));
}

TEST("Battle Cafe vitamin sets do not charge or give items without enough points")
{
    ClearBag();
    VarSet(VAR_BATTLE_CAFE_POINTS, 3);
    gSpecialVar_0x8004 = BATTLE_CAFE_VITAMIN_SET_ATK;

    BattleCafe_TryPurchaseVitaminSet();

    EXPECT_EQ(gSpecialVar_Result, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS);
    EXPECT_EQ(VarGet(VAR_BATTLE_CAFE_POINTS), 3);
    EXPECT(!CheckBagHasItem(ITEM_PROTEIN_EX, 1));
    EXPECT(!CheckBagHasItem(ITEM_CALCIUM_EX, 1));
}
