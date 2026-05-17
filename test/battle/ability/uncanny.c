#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Uncanny lowers the opposing battler's Sp. Atk on switch in", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_UNCANNY; }
    PARAMETRIZE { ability = ABILITY_SHED_SKIN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        if (ability == ABILITY_UNCANNY)
            ABILITY_POPUP(opponent, ABILITY_UNCANNY);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Uncanny lowers both opposing battlers' Sp. Atk")
{
    GIVEN {
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_UNCANNY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_UNCANNY);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Uncanny cannot lower Sp. Atk below minimum")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_UNCANNY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(opponent, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(opponent, MOVE_EERIE_IMPULSE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_UNCANNY);
        MESSAGE("Wobbuffet's Sp. Atk won't go any lower!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], MIN_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Contrary reverses Uncanny's Sp. Atk drop")
{
    GIVEN {
        PLAYER(SPECIES_SPINDA) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_UNCANNY); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_UNCANNY);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Clear Body prevents Uncanny's Sp. Atk drop")
{
    GIVEN {
        PLAYER(SPECIES_METANG) { Ability(ABILITY_CLEAR_BODY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_UNCANNY); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_UNCANNY);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Metang's Sp. Atk fell!");
        }
        ABILITY_POPUP(player, ABILITY_CLEAR_BODY);
        MESSAGE("Metang's Clear Body prevents stat loss!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Uncanny lowers the opposing battler's Sp. Atk on switch in (Traits)", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_UNCANNY; }
    PARAMETRIZE { ability = ABILITY_SHED_SKIN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); Innates(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        if (ability == ABILITY_UNCANNY)
            ABILITY_POPUP(opponent, ABILITY_UNCANNY);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
#endif
