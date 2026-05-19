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
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.2), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(0.8), results[5].damage);
        EXPECT_MUL_EQ(results[6].damage, Q_4_12(0.8), results[7].damage);
    }
}

SINGLE_BATTLE_TEST("Twilight makes Moonblast Dark type")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_TWILIGHT);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(200); }
        OPPONENT(SPECIES_ESPEON);
    } WHEN {
        TURN { MOVE(player, MOVE_MOONBLAST); }
    } SCENE {
        MESSAGE("It's super effective!");
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
