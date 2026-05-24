#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAdditionalEffectById(MOVE_ANCIENT_POWER, 0)->moveEffect == MOVE_EFFECT_ALL_STATS_UP);
}

SINGLE_BATTLE_TEST("Ancient Power prints one all-stats message when all five regular stats rise")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ANCIENT_POWER); }
    } SCENE {
        MESSAGE("Wobbuffet's all stats rose!");
        NONE_OF {
            MESSAGE("Wobbuffet's Attack rose!");
            MESSAGE("Wobbuffet's Speed rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Ancient Power lists only changed stats when one regular stat is already maxed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_ANCIENT_POWER); }
    } SCENE {
        MESSAGE("Wobbuffet's Defense, Sp. Atk, Sp. Def and Speed rose!");
        NONE_OF {
            MESSAGE("Wobbuffet's all stats rose!");
            MESSAGE("Wobbuffet's Attack, Defense, Sp. Atk, Sp. Def and Speed rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
