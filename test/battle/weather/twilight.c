#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Twilight boosts Dark and Ghost and weakens Fighting and Fairy", s16 damage)
{
    enum Move move;
    bool32 twilight;

    PARAMETRIZE { move = MOVE_BITE; twilight = FALSE; }
    PARAMETRIZE { move = MOVE_BITE; twilight = TRUE; }
    PARAMETRIZE { move = MOVE_LICK; twilight = FALSE; }
    PARAMETRIZE { move = MOVE_LICK; twilight = TRUE; }
    PARAMETRIZE { move = MOVE_ROCK_SMASH; twilight = FALSE; }
    PARAMETRIZE { move = MOVE_ROCK_SMASH; twilight = TRUE; }
    PARAMETRIZE { move = MOVE_FAIRY_WIND; twilight = FALSE; }
    PARAMETRIZE { move = MOVE_FAIRY_WIND; twilight = TRUE; }
    GIVEN {
        if (twilight)
            STARTING_WEATHER(B_WEATHER_TWILIGHT);
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
        EXPECT_GT(results[3].damage, results[2].damage);
        EXPECT_LT(results[5].damage, results[4].damage);
        EXPECT_LT(results[7].damage, results[6].damage);
    }
}

SINGLE_BATTLE_TEST("Twilight makes Dark super effective against Fairy")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_TWILIGHT);
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); }
        OPPONENT(SPECIES_SYLVEON);
    } WHEN {
        TURN { MOVE(player, MOVE_BITE); }
    } SCENE {
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Twilight weakens Morning Sun and Synthesis but strengthens Moonlight")
{
    enum Move move;
    s16 heal;

    PARAMETRIZE { move = MOVE_MORNING_SUN; heal = 400 / 4; }
    PARAMETRIZE { move = MOVE_SYNTHESIS;   heal = 400 / 4; }
    PARAMETRIZE { move = MOVE_MOONLIGHT;   heal = 3 * 400 / 4; }
    GIVEN {
        WITH_CONFIG(B_TIME_OF_DAY_HEALING_MOVES, GEN_3);
        STARTING_WEATHER(B_WEATHER_TWILIGHT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(player, damage: -heal);
    }
}

SINGLE_BATTLE_TEST("Twilight doubles Night Shade damage", s16 damage)
{
    bool32 twilight;

    PARAMETRIZE { twilight = FALSE; }
    PARAMETRIZE { twilight = TRUE; }
    GIVEN {
        if (twilight)
            STARTING_WEATHER(B_WEATHER_TWILIGHT);
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHT_SHADE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 100);
    }
}
