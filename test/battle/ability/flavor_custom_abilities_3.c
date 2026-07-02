#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hunter makes Glare confuse and paralyze")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HUNTER); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_GLARE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_PARALYSIS);
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Hunter boosts Attack by 50 percent while a foe is paralyzed", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HUNTER); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Nine Lives has Sturdy and adds priority at low HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NINE_LIVES); HP(33); MaxHP(99); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

SINGLE_BATTLE_TEST("Debilitate drains 3 extra PP from opposing moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_POUND, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_DEBILITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } THEN {
        EXPECT_EQ(player->pp[0], 6);
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

SINGLE_BATTLE_TEST("Flexible makes two-turn attacks instant")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLEXIBLE); Attack(200); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Reborn prevents a KO once and restores full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        HP_BAR(player, damage: -50);
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Reborn prevents a KO from poison damage and restores full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); HP(10); MaxHP(80); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(player, damage: -70);
        ABILITY_POPUP(player, ABILITY_REBORN);
    } THEN {
        EXPECT_EQ(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Reborn can be followed by another innate popup for the same battler")
{
    PASSES_RANDOMLY(3, 10, RNG_FLAME_BODY);
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); Innates(ABILITY_FLAME_BODY); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, damage: -99);
        ABILITY_POPUP(opponent, ABILITY_REBORN);
        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
    } THEN {
        EXPECT_EQ(opponent->hp, 100);
        EXPECT(player->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Rejuvenation heals if no damage was taken this turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REJUVENATION); HP(80); MaxHP(100); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Tidal Deity bypasses Protect at full HP and summons rain after being damaged")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TIDAL_DEITY); Attack(200); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT_LT(opponent->hp, opponent->maxHP);
        EXPECT(gBattleWeather & B_WEATHER_RAIN);
    }
}

SINGLE_BATTLE_TEST("Rockstorm makes Rock moves bypass accuracy in sand")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_ROCK_THROW) < 100);
        STARTING_WEATHER(B_WEATHER_SANDSTORM);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROCKSTORM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, player);
        HP_BAR(opponent);
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
