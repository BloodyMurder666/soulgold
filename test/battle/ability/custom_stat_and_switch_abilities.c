#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bloodlust raises Attack and Speed after critical hits", s16 atkStage, s16 speedStage)
{
    bool32 critical;

    PARAMETRIZE { critical = FALSE; }
    PARAMETRIZE { critical = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLOODLUST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: critical); }
    } THEN {
        results[i].atkStage = player->statStages[STAT_ATK];
        results[i].speedStage = player->statStages[STAT_SPEED];
    } FINALLY {
        EXPECT_EQ(results[0].atkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[0].speedStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].atkStage, DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(results[1].speedStage, DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Momentum raises Speed after priority moves only")
{
    enum Move move;
    s16 speedStage;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MOMENTUM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } THEN {
        speedStage = player->statStages[STAT_SPEED];
        if (move == MOVE_QUICK_ATTACK)
            EXPECT_EQ(speedStage, DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(speedStage, DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Desperado raises offensive stats after taking super-effective damage", s16 atkStage, s16 spatkStage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SHADOW_BALL; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DESPERADO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        results[i].atkStage = player->statStages[STAT_ATK];
        results[i].spatkStage = player->statStages[STAT_SPATK];
    } FINALLY {
        EXPECT_EQ(results[0].atkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[0].spatkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].atkStage, DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(results[1].spatkStage, DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Glass Cannon raises the higher offense and lowers both defenses on entry")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_GLASS_CANNON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(150); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        if (ability == ABILITY_GLASS_CANNON) {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
            EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 2);
        } else {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        }
    }
}

SINGLE_BATTLE_TEST("Parrying keeps Focus Punch focused after damage and raises Defense", u16 opponentHp, s16 defStage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_PARRYING; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        results[i].opponentHp = opponent->hp;
        results[i].defStage = player->statStages[STAT_DEF];
    } FINALLY {
        EXPECT_GT(results[0].opponentHp, results[1].opponentHp);
        EXPECT_EQ(results[0].defStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].defStage, DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Backdraft lowers opposing Speed after a voluntary switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BACKDRAFT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Backdraft lowers opposing Speed after U-turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BACKDRAFT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Backdraft does not trigger when its user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BACKDRAFT); HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Rally raises its partner's highest non-HP stat on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RALLY); Speed(50); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); Defense(50); SpAttack(50); SpDefense(50); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Rally does not raise stats in single battles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RALLY); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Twin Stars boosts both partners when both have it")
{
    enum Ability partnerAbility;

    PARAMETRIZE { partnerAbility = ABILITY_BIG_PECKS; }
    PARAMETRIZE { partnerAbility = ABILITY_TWIN_STARS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TWIN_STARS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(partnerAbility); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        if (partnerAbility == ABILITY_TWIN_STARS) {
            EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        } else {
            EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
            EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        }
    }
}

DOUBLE_BATTLE_TEST("Twin Stars does not boost a pair twice after switching")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TWIN_STARS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TWIN_STARS); }
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_TWIN_STARS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
        TURN { SWITCH(playerLeft, 0); }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Polarity Shift swaps Speed with the opposing Pokemon on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_POLARITY_SHIFT); Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(80); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POLARITY_SHIFT);
    } THEN {
        EXPECT_EQ(player->speed, 80);
        EXPECT_EQ(opponent->speed, 10);
    }
}

DOUBLE_BATTLE_TEST("Polarity Shift targets the opposite foe in doubles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_POLARITY_SHIFT); Speed(10); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(30); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_POLARITY_SHIFT);
    } THEN {
        EXPECT_EQ(playerLeft->speed, 80);
        EXPECT_EQ(opponentLeft->speed, 10);
        EXPECT_EQ(opponentRight->speed, 30);
    }
}

DOUBLE_BATTLE_TEST("Polarity Shift targets the remaining foe if the opposite foe has fainted")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_POLARITY_SHIFT); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(30); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        ABILITY_POPUP(playerLeft, ABILITY_POLARITY_SHIFT);
    } THEN {
        EXPECT_EQ(playerLeft->speed, 30);
        EXPECT_EQ(opponentRight->speed, 10);
    }
}

SINGLE_BATTLE_TEST("Power Shift swaps Attack and Sp. Atk with the opposing Pokemon on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_POWER_SHIFT); Attack(10); SpAttack(20); }
        OPPONENT(SPECIES_WYNAUT) { Attack(90); SpAttack(120); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POWER_SHIFT);
    } THEN {
        EXPECT_EQ(player->attack, 90);
        EXPECT_EQ(player->spAttack, 120);
        EXPECT_EQ(opponent->attack, 10);
        EXPECT_EQ(opponent->spAttack, 20);
    }
}

SINGLE_BATTLE_TEST("Inky lowers the attacker's Accuracy when hit by a damaging move")
{
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_INKY); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWIFT); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INKY);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Lunar Cycle raises Speed after a damaging hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_CYCLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_LUNAR_CYCLE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Fill Void raises Defense and Sp. Atk after a KO")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FILL_VOID); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); SEND_OUT(opponentLeft, 2); }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Solidify raises Sp. Def after special hits")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLIDIFY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSION); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Unleashed changes Shell Smash into all-stat boosts")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_UNLEASHED); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Tether copies opposing stat boosts")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TETHER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

#if MAX_MON_TRAITS > 1

SINGLE_BATTLE_TEST("Contrary inverts stat boosts copied by Tether")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TETHER); Innates(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}
#endif

SINGLE_BATTLE_TEST("Infernal lowers the foe's Attack and Defense on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_INFERNAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INFERNAL);
        MESSAGE("The opposing Wobbuffet's Attack and Defense fell!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Attack fell!");
            MESSAGE("The opposing Wobbuffet's Defense fell!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Titan Grip makes Superpower lower the target instead of the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TITAN_GRIP); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUPERPOWER); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Titan Grip target drops use normal stat interactions")
{
    enum Ability targetAbility;
    s8 expectedDef;
    s8 expectedAttackerDef;

    PARAMETRIZE { targetAbility = ABILITY_CLEAR_BODY;   expectedDef = DEFAULT_STAT_STAGE;     expectedAttackerDef = DEFAULT_STAT_STAGE; }
    PARAMETRIZE { targetAbility = ABILITY_CONTRARY;     expectedDef = DEFAULT_STAT_STAGE + 1; expectedAttackerDef = DEFAULT_STAT_STAGE; }
    PARAMETRIZE { targetAbility = ABILITY_SIMPLE;       expectedDef = DEFAULT_STAT_STAGE - 2; expectedAttackerDef = DEFAULT_STAT_STAGE; }
    PARAMETRIZE { targetAbility = ABILITY_MIRROR_ARMOR; expectedDef = DEFAULT_STAT_STAGE;     expectedAttackerDef = DEFAULT_STAT_STAGE - 1; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TITAN_GRIP); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(targetAbility); HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_CLOSE_COMBAT); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], expectedDef);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], expectedDef);
        EXPECT_EQ(player->statStages[STAT_DEF], expectedAttackerDef);
        EXPECT_EQ(player->statStages[STAT_SPDEF], expectedAttackerDef);
    }
}

SINGLE_BATTLE_TEST("Stormrider, Volcano Howl, and Arctic Aura lower foes at end of turn")
{
    enum Ability ability;
    enum Stat stat;

    PARAMETRIZE { ability = ABILITY_STORMRIDER; stat = STAT_SPDEF; }
    PARAMETRIZE { ability = ABILITY_VOLCANO_HOWL; stat = STAT_DEF; }
    PARAMETRIZE { ability = ABILITY_ARCTIC_AURA; stat = STAT_ATK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(opponent->statStages[stat], DEFAULT_STAT_STAGE - 1);
    }
}

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
