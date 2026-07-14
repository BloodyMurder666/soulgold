#include "global.h"
#include "battle_arcade.h"
#include "battle_setup.h"
#include "event_data.h"
#include "money.h"
#include "pokemon.h"
#include "test/battle.h"
#include "test/test.h"
#include "constants/battle_arcade.h"
#include "constants/battle.h"
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

SINGLE_BATTLE_TEST("Pika Papow uses the player's friendship in Rocket Arcade battles", s16 damage)
{
    u32 friendship;

    PARAMETRIZE { friendship = 0; }
    PARAMETRIZE { friendship = 200; }
    GIVEN {
        gBattleTestRunnerState->data.recordedBattle.battleFlags |= BATTLE_TYPE_BATTLE_TOWER;
        PLAYER(SPECIES_PIKACHU) {
            Friendship(friendship);
            Speed(2);
            Moves(MOVE_PIKA_PAPOW);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Speed(1);
            Moves(MOVE_SPLASH);
        }
    } WHEN {
        TURN { MOVE(player, MOVE_PIKA_PAPOW); MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PIKA_PAPOW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(player->friendship, friendship);
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_FRIENDSHIP), friendship);
        if (i > 0)
            EXPECT_GT(results[i].damage, results[i - 1].damage);
    }
}
