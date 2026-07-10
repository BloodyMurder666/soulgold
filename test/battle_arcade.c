#include "global.h"
#include "battle_arcade.h"
#include "battle_setup.h"
#include "event_data.h"
#include "money.h"
#include "test/test.h"
#include "constants/battle_arcade.h"
#include "constants/opponents.h"

TEST("Rocket Arcade exposes every payout across its eight ordinary wins")
{
    static const u32 expectedPayouts[] =
    {
        4000,
        8000,
        12000,
        24000,
        48000,
        96000,
        192000,
        384000,
    };

    TRAINER_BATTLE_PARAM.opponentA = TRAINER_NONE;
    for (u32 win = 1; win <= ARRAY_COUNT(expectedPayouts); win++)
    {
        SetMoney(&gSaveBlock1Ptr->money, 0);
        FRONTIER_SAVEDATA.curChallengeBattleNum = win;
        gSpecialVar_0x8004 = ARCADE_FUNC_AWARD_PRIZE;
        CallBattleArcadeFunc();
        EXPECT_EQ(gSaveBlock1Ptr->money, expectedPayouts[win - 1]);
    }
}
