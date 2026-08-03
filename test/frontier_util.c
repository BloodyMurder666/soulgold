#include "global.h"
#include "event_data.h"
#include "field_specials.h"
#include "frontier_util.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/vars.h"

static void SetUpTowerBattlePointAward(u16 streak, u16 battlePoints)
{
    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_50;
    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_DOUBLES][FRONTIER_LVL_50] = streak;
    gSaveBlock2Ptr->frontier.battlePoints = battlePoints;
    gSaveBlock2Ptr->frontier.cardBattlePoints = 0;
    VarSet(VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES);
    VarSet(VAR_DAILY_BP, 0);
    gSpecialVar_0x8004 = FRONTIER_UTIL_FUNC_GIVE_TOWER_BP;
}

TEST("Five early Double Battle Tower wins grant 15 spendable Battle Points")
{
    u16 streak;

    SetUpTowerBattlePointAward(1, 0);
    for (streak = 1; streak <= 5; streak++)
    {
        gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_DOUBLES][FRONTIER_LVL_50] = streak;
        CallFrontierUtilFunc();
    }

    EXPECT_EQ(gSaveBlock2Ptr->frontier.battlePoints, 15);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.cardBattlePoints, 15);
    EXPECT_EQ(VarGet(VAR_DAILY_BP), 15);
}

TEST("Battle Tower per-battle rewards cap spendable Battle Points")
{
    SetUpTowerBattlePointAward(5, MAX_BATTLE_FRONTIER_POINTS - 1);

    CallFrontierUtilFunc();

    EXPECT_EQ(gSaveBlock2Ptr->frontier.battlePoints, MAX_BATTLE_FRONTIER_POINTS);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.cardBattlePoints, 3);
    EXPECT_EQ(VarGet(VAR_DAILY_BP), 3);
}

TEST("Zeraora unlock accepts current and record Battle Tower streaks")
{
    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 29;
    EXPECT(!HasBattleTowerStreakForZeraora());

    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 30;
    EXPECT(HasBattleTowerStreakForZeraora());

    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 0;
    gSaveBlock2Ptr->frontier.towerRecordWinStreaks[FRONTIER_MODE_DOUBLES][FRONTIER_LVL_OPEN] = 30;
    EXPECT(HasBattleTowerStreakForZeraora());
}
