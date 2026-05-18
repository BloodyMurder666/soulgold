#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Seer raises Speed after using a damaging Psychic-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CONFUSION) == TYPE_PSYCHIC);
        ASSUME(GetMoveCategory(MOVE_CONFUSION) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SEER); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(149); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSION); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSION, player);
        ABILITY_POPUP(player, ABILITY_SEER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Smouldering makes Water-type moves ineffective and raises Sp. Def")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SMOULDERING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SMOULDERING);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF { HP_BAR(player); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Consume heals 50 percent max HP after knocking out a foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CONSUME); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); SEND_OUT(opponent, 1); }
    } SCENE {
        MESSAGE("The opposing Wynaut fainted!");
        ABILITY_POPUP(player, ABILITY_CONSUME);
        HP_BAR(player, damage: -50);
    }
}

SINGLE_BATTLE_TEST("Lifesteal restores one eighth of damage dealt")
{
    s16 damage;
    s16 healing;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIFESTEAL); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage);
        ABILITY_POPUP(player, ABILITY_LIFESTEAL);
        HP_BAR(player, captureDamage: &healing);
    } THEN {
        EXPECT_EQ(damage / 8, -healing);
    }
}

SINGLE_BATTLE_TEST("Haunting gives Ghost-type attacks a 20 percent chance to flinch")
{
    PASSES_RANDOMLY(20, 100, RNG_HAUNTING);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HAUNTING); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BALL); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_BALL, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Windcaller boosts Flying-type damage by 30 percent", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_WINDCALLER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_GUST) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Windcaller makes Tailwind last 6 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_WINDCALLER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        MESSAGE("The Tailwind blew from behind your team!");
    } THEN {
        EXPECT_EQ(gSideTimers[B_SIDE_PLAYER].tailwindTimer, 5);
    }
}

SINGLE_BATTLE_TEST("Siegebreaker attacks scale from Defense", s16 damage)
{
    u16 defense;

    PARAMETRIZE { defense = 100; }
    PARAMETRIZE { defense = 200; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SIEGEBREAKER); Attack(50); Defense(defense); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Sandshield doubles Defense during sandstorm", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SANDSHIELD; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
