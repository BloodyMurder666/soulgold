#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fire-ate turns a Normal-type move into a Fire-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_FIRE_ATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Fire-ate boosts affected Normal-type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_BLAZE; }
    PARAMETRIZE { ability = ABILITY_FIRE_ATE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_7);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
    }
}

