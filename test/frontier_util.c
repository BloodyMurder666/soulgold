#include "global.h"
#include "battle_tower.h"
#include "event_data.h"
#include "field_specials.h"
#include "frontier_util.h"
#include "string_util.h"
#include "test/test.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tower.h"
#include "constants/frontier_util.h"
#include "constants/trainers.h"
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

TEST("Continuous Battle Tower progress keeps its trainer history index in bounds")
{
    u32 activeFlags = 0xA5A5A5A5;

    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_50;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 22;
    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 22;
    gSaveBlock2Ptr->frontier.winStreakActiveFlags = activeFlags;
    VarSet(VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER);
    VarSet(VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES);
    ResetFrontierTrainerIds();

    gSpecialVar_0x8004 = BATTLE_TOWER_FUNC_SET_OPPONENT;
    CallBattleTowerFunc();

    EXPECT_EQ(gSaveBlock2Ptr->frontier.curChallengeBattleNum, 1);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50], 22);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.winStreakActiveFlags, activeFlags);
}

TEST("A Battle Tower win advances the streak once and cycles the local set index")
{
    gSaveBlock2Ptr->frontier.lvlMode = FRONTIER_LVL_50;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 11;
    gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50] = 11;
    VarSet(VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER);
    VarSet(VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES);

    gSpecialVar_0x8004 = FRONTIER_UTIL_FUNC_INCREMENT_STREAK;
    CallFrontierUtilFunc();
    gSpecialVar_0x8004 = BATTLE_TOWER_FUNC_SET_BATTLE_WON;
    CallBattleTowerFunc();

    EXPECT_EQ(gSaveBlock2Ptr->frontier.towerWinStreaks[FRONTIER_MODE_SINGLES][FRONTIER_LVL_50], 12);
    EXPECT_EQ(gSaveBlock2Ptr->frontier.curChallengeBattleNum, 5);
}

TEST("The Battle Tower Frontier Brain presents as Salon Maiden Anabel")
{
    u8 name[PLAYER_NAME_LENGTH + 1];

    VarSet(VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER);
    CopyFrontierBrainTrainerName(name);

    EXPECT_EQ(GetFrontierBrainTrainerPicIndex(), TRAINER_PIC_FRONT_SALON_MAIDEN_ANABEL);
    EXPECT_EQ(GetFrontierBrainTrainerClass(), TRAINER_CLASS_SALON_MAIDEN);
    EXPECT_EQ(StringCompare(name, COMPOUND_STRING("Anabel")), 0);
}
