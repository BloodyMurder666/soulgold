#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
    ASSUME(IsWindMove(MOVE_TAILWIND));
}

SINGLE_BATTLE_TEST("Wind Chime raises Sp. Atk by one stage if it sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHIMECHO_MEGA) { Innates(ABILITY_WIND_CHIME); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_WIND_CHIME);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Chimecho's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Wind Chime raises Sp. Atk by one stage if Tailwind is set up by its partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHIMECHO_MEGA) { Innates(ABILITY_WIND_CHIME); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_WIND_CHIME);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Chimecho's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Wind Chime does not raise Sp. Atk if the opponent sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHIMECHO_MEGA) { Innates(ABILITY_WIND_CHIME); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_WIND_CHIME);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Chimecho's Sp. Atk rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Wind Chime raises Sp. Atk by one stage when switched into allied Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CHIMECHO_MEGA) { Innates(ABILITY_WIND_CHIME); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_WIND_CHIME);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Chimecho's Wind Chime raised its Sp. Atk!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Wind Chime absorbs wind moves and raises Sp. Atk by one stage")
{
    GIVEN {
        ASSUME(IsWindMove(MOVE_GUST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRAMBLIN) { Ability(ABILITY_WIND_CHIME); }
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_WIND_CHIME);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Bramblin's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}
