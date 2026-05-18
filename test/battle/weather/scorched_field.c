#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Scorched Field damages non-Fire battlers")
{
    s16 damage;

    GIVEN {
        STARTING_WEATHER(B_WEATHER_SCORCHED_FIELD);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The scorched field blazes.");
        MESSAGE("The opposing Wobbuffet is scorched by the burning field!");
        HP_BAR(opponent);
        MESSAGE("Wobbuffet is scorched by the burning field!");
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, player->maxHP / 16);
    }
}

SINGLE_BATTLE_TEST("Scorched Field boosts Fire and weakens Water except Scald", s16 damage)
{
    enum Move move;
    bool32 hasScorchedField;

    PARAMETRIZE { move = MOVE_EMBER;     hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_EMBER;     hasScorchedField = TRUE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; hasScorchedField = TRUE; }
    PARAMETRIZE { move = MOVE_SCALD;     hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_SCALD;     hasScorchedField = TRUE; }
    GIVEN {
        if (hasScorchedField)
            STARTING_WEATHER(B_WEATHER_SCORCHED_FIELD);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.8), results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Scorched Field respects Magic Guard")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SCORCHED_FIELD);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The scorched field blazes.");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Scorched Field is replaced by other weather")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        STARTING_WEATHER(B_WEATHER_SCORCHED_FIELD);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN);
        EXPECT(!(gBattleWeather & B_WEATHER_SCORCHED_FIELD));
    }
}

SINGLE_BATTLE_TEST("Scorched Field is cleared by weather-clearing effects")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SCORCHED_FIELD);
        PLAYER(SPECIES_TERAPAGOS_TERASTAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TERAFORM_ZERO);
        MESSAGE("The scorched field settled.");
    } THEN {
        EXPECT_EQ(gBattleWeather, B_WEATHER_NONE);
    }
}
