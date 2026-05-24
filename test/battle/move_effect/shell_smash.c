#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SHELL_SMASH) == EFFECT_SHELL_SMASH);
}

SINGLE_BATTLE_TEST("Shell Smash prints one combined drop message and one combined sharp-rise message")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SMASH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense and Sp. Def fell!");
        MESSAGE("Wobbuffet's Attack, Sp. Atk and Speed sharply rose!");
        NONE_OF {
            MESSAGE("Wobbuffet's Defense fell!");
            MESSAGE("Wobbuffet's Sp. Def fell!");
            MESSAGE("Wobbuffet's Attack sharply rose!");
            MESSAGE("Wobbuffet's Sp. Atk sharply rose!");
            MESSAGE("Wobbuffet's Speed sharply rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Shell Smash splits mixed actual boost modifiers after a stat nears its cap")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_DRAGON_DANCE); }
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
    } SCENE {
        MESSAGE("Wobbuffet's Defense and Sp. Def fell!");
        MESSAGE("Wobbuffet's Attack and Sp. Atk sharply rose!");
        MESSAGE("Wobbuffet's Speed rose!");
        NOT MESSAGE("Wobbuffet's Attack, Sp. Atk and Speed sharply rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], MAX_STAT_STAGE);
    }
}
