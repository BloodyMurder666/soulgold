#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
    ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_TACKLE) > 0);
}

SINGLE_BATTLE_TEST("Dragonize turns Normal-type moves into Dragon-type moves")
{
    GIVEN {
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_DRUDDIGON);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Dragonize boosts affected moves by the ate modifier", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_DRAGONIZE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_7);
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.8), results[1].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Dragonize works as an innate trait")
{
    GIVEN {
        PLAYER(SPECIES_FERALIGATR_MEGA) { Ability(ABILITY_TORRENT); Innates(ABILITY_DRAGONIZE); }
        OPPONENT(SPECIES_DRUDDIGON);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("It's super effective!");
    }
}
#endif
