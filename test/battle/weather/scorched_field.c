#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Scorched Field boosts Fire and weakens Water except Scald", s16 damage)
{
    enum Move move;
    bool32 hasScorchedField;

    PARAMETRIZE { move = MOVE_EMBER;     hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_EMBER;     hasScorchedField = TRUE; }
    PARAMETRIZE { move = MOVE_SURF;      hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_SURF;      hasScorchedField = TRUE; }
    PARAMETRIZE { move = MOVE_SCALD;     hasScorchedField = FALSE; }
    PARAMETRIZE { move = MOVE_SCALD;     hasScorchedField = TRUE; }
    if (hasScorchedField)
        SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        gFieldStatuses = 0;
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.8), results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Scorched Field is terrain and is replaced by other terrain")
{
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN);
        EXPECT(!(gFieldStatuses & STATUS_FIELD_SCORCHED_FIELD));
    }
}

SINGLE_BATTLE_TEST("Scorched Field is cleared by terrain-clearing effects")
{
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TERAFORM_ZERO);
        MESSAGE("The scorched field settled.");
    } THEN {
        EXPECT(!(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY));
    }
}
