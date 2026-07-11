#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Eelevate grants Ground immunity like Levitate")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_EELEKTROSS_MEGA) { Ability(ABILITY_EELEVATE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EELEVATE);
        MESSAGE("It doesn't affect Eelektross…");
    }
}

SINGLE_BATTLE_TEST("Eelevate boosts the user's highest stat after a KO")
{
    GIVEN {
        PLAYER(SPECIES_EELEKTROSS_MEGA) { Ability(ABILITY_EELEVATE); Attack(80); Defense(60); SpAttack(120); SpDefense(60); Speed(70); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EELEVATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Eelevate reports itself when paired with Beast Boost")
{
    GIVEN {
        PLAYER(SPECIES_EELEKTROSS_MEGA) { Ability(ABILITY_EELEVATE); Innates(ABILITY_BEAST_BOOST); Attack(120); Defense(60); SpAttack(80); SpDefense(60); Speed(70); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EELEVATE);
        NOT ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Eelevate does not boost after knocking out an ally")
{
    GIVEN {
        PLAYER(SPECIES_EELEKTROSS_MEGA) { Ability(ABILITY_EELEVATE); Attack(120); Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: playerRight); SEND_OUT(playerRight, 2); }
    } SCENE {
        NOT ABILITY_POPUP(playerLeft, ABILITY_EELEVATE);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Eelevate grants Ground immunity as an innate trait")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_EELEKTROSS_MEGA) { Ability(ABILITY_LIGHT_METAL); Innates(ABILITY_EELEVATE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EELEVATE);
        MESSAGE("It doesn't affect Eelektross…");
    }
}
#endif
