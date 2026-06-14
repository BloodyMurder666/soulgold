#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Channel Earth heals at end of turn only while terrain is active", u16 hp)
{
    bool32 terrain;

    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    if (terrain)
        SetStartingStatus(STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CHANNEL_EARTH); HP(80); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        results[i].hp = player->hp;
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_EQ(results[0].hp, 80);
        EXPECT_GT(results[1].hp, 80);
    }
}

SINGLE_BATTLE_TEST("Magnify Field extends finite weather but not infinite weather", u8 duration)
{
    bool32 finiteWeather;

    PARAMETRIZE { finiteWeather = FALSE; }
    PARAMETRIZE { finiteWeather = TRUE; }
    GIVEN {
        if (finiteWeather)
            STARTING_WEATHER_WITH_DURATION(B_WEATHER_RAIN_NORMAL, 3);
        else
            STARTING_WEATHER(B_WEATHER_RAIN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MAGNIFY_FIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        results[i].duration = gBattleStruct->weatherDuration;
    } FINALLY {
        EXPECT_EQ(results[0].duration, 0);
        EXPECT_EQ(results[1].duration, 4);
    }
}

SINGLE_BATTLE_TEST("Blitz boosts only the first damaging move after switch-in")
{
    s16 firstDamage, secondDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLITZ); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &firstDamage);
        HP_BAR(opponent, captureDamage: &secondDamage);
    } THEN {
        EXPECT_GT(firstDamage, secondDamage);
    }
}

SINGLE_BATTLE_TEST("Blitz does not boost non-damaging moves", u16 hp)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLITZ); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, move); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 200);
        EXPECT_LT(results[1].hp, 200);
    }
}

DOUBLE_BATTLE_TEST("Guardian redirects selected damaging moves to itself")
{
    enum Ability partnerAbility;

    PARAMETRIZE { partnerAbility = ABILITY_BIG_PECKS; }
    PARAMETRIZE { partnerAbility = ABILITY_GUARDIAN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(partnerAbility); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        if (partnerAbility == ABILITY_GUARDIAN) {
            EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
            EXPECT_LT(playerRight->hp, playerRight->maxHP);
        } else {
            EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
            EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        }
    }
}

SINGLE_BATTLE_TEST("Guardian reduces direct damage it takes", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_GUARDIAN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
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

SINGLE_BATTLE_TEST("Echo Chamber makes sound moves hit harder", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_ECHO_CHAMBER; }
    GIVEN {
        ASSUME(IsSoundMove(MOVE_ROUND));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_LT(results[1].hp, results[0].hp);
    }
}

SINGLE_BATTLE_TEST("Echo Chamber ignores non-sound moves", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_ECHO_CHAMBER; }
    GIVEN {
        ASSUME(!IsSoundMove(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, results[1].hp);
    }
}

SINGLE_BATTLE_TEST("Flare boosts Fire moves against burned targets", s16 damage)
{
    bool32 burned;

    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLARE); }
        OPPONENT(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Flare ignores non-Fire moves", s16 damage)
{
    bool32 burned;

    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLARE); }
        OPPONENT(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Splinter damages all foes after taking direct damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPLINTER); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        EXPECT_EQ(opponentLeft->hp, 88);
        EXPECT_EQ(opponentRight->hp, 88);
    }
}

DOUBLE_BATTLE_TEST("Splinter ignores non-damaging moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPLINTER); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GROWL, target: playerLeft); }
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

SINGLE_BATTLE_TEST("Maim and Mend heals after critical hits only", u16 hp)
{
    bool32 critical;

    PARAMETRIZE { critical = FALSE; }
    PARAMETRIZE { critical = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MAIM_AND_MEND); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: critical); }
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 50);
        EXPECT_GT(results[1].hp, 50);
    }
}

SINGLE_BATTLE_TEST("Valkyrie grants Ground immunity", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_LT(results[0].hp, 100);
        EXPECT_EQ(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Valkyrie attacks with the higher offensive stat", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(50); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Immovable blocks phasing moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_IMMOVABLE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROAR); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Roar!");
        ABILITY_POPUP(player, ABILITY_IMMOVABLE);
        MESSAGE("Wobbuffet anchors itself with Immovable!");
        NOT MESSAGE("Wynaut was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Immovable makes its user move last")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_IMMOVABLE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(1); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        if (ability == ABILITY_IMMOVABLE)
            EXPECT_EQ(opponent->hp, opponent->maxHP);
        else
            EXPECT_LT(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Transmute reduces the first incoming direct hit", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_TRANSMUTE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_CHARMANDER) { Ability(ability); HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Transmute is consumed after its first use")
{
    s16 firstDamage, secondDamage;

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_TRANSMUTE); HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(player, captureDamage: &firstDamage);
        HP_BAR(player, captureDamage: &secondDamage);
    } THEN {
        EXPECT_GT(secondDamage, firstDamage);
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

SINGLE_BATTLE_TEST("Cosmic Form lets direct attacks bypass type immunities", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_COSMIC_FORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_GEODUDE) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 100);
        EXPECT_LT(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Cosmic Form reduces super-effective direct damage taken", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_COSMIC_FORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Time Spiral blocks opposing priority moves", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_TIME_SPIRAL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_QUICK_ATTACK); }
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_LT(results[0].hp, 100);
        EXPECT_EQ(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Time Spiral accelerates finite weather timers once per turn", u8 duration)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_TIME_SPIRAL; }
    GIVEN {
        STARTING_WEATHER_WITH_DURATION(B_WEATHER_RAIN_NORMAL, 5);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        results[i].duration = gBattleStruct->weatherDuration;
    } FINALLY {
        EXPECT_EQ(results[0].duration, 4);
        EXPECT_EQ(results[1].duration, 3);
    }
}

SINGLE_BATTLE_TEST("Null Space lets direct moves hit through Protect", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_NULL_SPACE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 100);
        EXPECT_LT(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Null Space halves damage through Protect", s16 damage)
{
    bool32 protect;

    PARAMETRIZE { protect = FALSE; }
    PARAMETRIZE { protect = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NULL_SPACE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            if (protect)
                MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Spacetime Rift protects same-side Palkia and Dialga from spread moves")
{
    bool32 rift;

    PARAMETRIZE { rift = FALSE; }
    PARAMETRIZE { rift = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_PALKIA) { Ability(rift ? ABILITY_SPACETIME_RIFT : ABILITY_BIG_PECKS); HP(100); MaxHP(100); }
        PLAYER(SPECIES_DIALGA) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } THEN {
        if (rift) {
            EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
            EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        } else {
            EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
            EXPECT_LT(playerRight->hp, playerRight->maxHP);
        }
    }
}

DOUBLE_BATTLE_TEST("Spacetime Rift requires Palkia and Dialga to share a side")
{
    GIVEN {
        PLAYER(SPECIES_PALKIA) { Ability(ABILITY_SPACETIME_RIFT); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DIALGA) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_EARTHQUAKE); }
    } THEN {
        EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("Underdog boosts damage against higher-BST targets", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_UNDERDOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_MEWTWO) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Underdog does not boost damage against lower-BST targets", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_UNDERDOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_MAGIKARP) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Rock and Stone sets Stealth Rock after knocking out a foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROCK_AND_STONE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_STEALTH_ROCK));
    }
}

SINGLE_BATTLE_TEST("Rock and Stone does not set Stealth Rock without a KO")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROCK_AND_STONE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(!IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_STEALTH_ROCK));
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

SINGLE_BATTLE_TEST("Horse Council boosts physical and special damage by 10 percent per living horse ally", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_NONE; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_HORSE_COUNCIL; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_NONE; move = MOVE_CONFUSION; }
    PARAMETRIZE { ability = ABILITY_HORSE_COUNCIL; move = MOVE_CONFUSION; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_CONFUSION) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); SpAttack(200); }
        PLAYER(SPECIES_PONYTA);
        PLAYER(SPECIES_RAPIDASH_GALAR);
        PLAYER(SPECIES_PALKIA_ORIGIN);
        PLAYER(SPECIES_ARCEUS_FIRE);
        PLAYER(SPECIES_TAUROS_PALDEA_AQUA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Horse Council counts only living listed horse allies", s16 damage)
{
    u32 alive;

    PARAMETRIZE { alive = 1; }
    PARAMETRIZE { alive = 5; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HORSE_COUNCIL); Attack(200); }
        PLAYER(SPECIES_TAUROS_PALDEA_BLAZE) { HP(alive >= 1 ? 1 : 0); }
        PLAYER(SPECIES_KELDEO_RESOLUTE) { HP(alive >= 2 ? 1 : 0); }
        PLAYER(SPECIES_FARIGIRAF) { HP(alive >= 3 ? 1 : 0); }
        PLAYER(SPECIES_DEERLING_WINTER) { HP(alive >= 4 ? 1 : 0); }
        PLAYER(SPECIES_DIALGA_ORIGIN) { HP(alive >= 5 ? 1 : 0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3636), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Wishmaker casts Wish on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_WISHMAKER); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { }
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WISHMAKER);
        MESSAGE("Wobbuffet's wish came true!");
        HP_BAR(player, damage: -50);
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Flier makes Fly instant and stronger than Wing Attack")
{
    s16 flyDamage;
    s16 wingAttackDamage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLIER); Attack(200); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(999); MaxHP(999); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_WING_ATTACK); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, player);
        HP_BAR(opponent, captureDamage: &flyDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WING_ATTACK, player);
        HP_BAR(opponent, captureDamage: &wingAttackDamage);
    } THEN {
        EXPECT_GT(flyDamage, wingAttackDamage);
    }
}

DOUBLE_BATTLE_TEST("Flameburst burns the opposing side when the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLAMEBURST); HP(1); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); Speed(100); }
        OPPONENT(SPECIES_WYNAUT) { Speed(90); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_FLAMEBURST);
    } THEN {
        EXPECT(opponentLeft->status1 & STATUS1_BURN);
        EXPECT(opponentRight->status1 & STATUS1_BURN);
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

SINGLE_BATTLE_TEST("Brand of Torment has a 30 percent chance to torment contact attackers")
{
    PASSES_RANDOMLY(3, 10, RNG_BRAND_OF_TORMENT);
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRAND_OF_TORMENT); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH, allowed: FALSE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT);
        MESSAGE("The opposing Wynaut was subjected to torment!");
        MESSAGE("The opposing Wynaut used Celebrate!");
    } THEN {
        EXPECT(opponent->volatiles.torment);
    }
}

SINGLE_BATTLE_TEST("Brand of Torment only triggers on contact")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRAND_OF_TORMENT); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move, WITH_RNG(RNG_BRAND_OF_TORMENT, TRUE)); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT);
        } else {
            NONE_OF { ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT); }
        }
    } THEN {
        bool32 isTormented = opponent->volatiles.torment;
        EXPECT_EQ(isTormented, MoveMakesContact(move));
    }
}
