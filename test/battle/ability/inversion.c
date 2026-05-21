#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Inversion makes weaknesses resist", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_INVERSION; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_LEAFEON, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_LEAFEON, 1) == TYPE_GRASS);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_LEAFEON) { Ability(ability); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Inversion makes resistances weak", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_INVERSION; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 1) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_VAPOREON) { Ability(ability); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Inversion leaves neutral matchups neutral", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_INVERSION; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 1) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_VAPOREON) { Ability(ability); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Inversion does not turn immunities into weaknesses")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 0) == TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_DUSKULL, 1) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_DUSKULL) { Ability(ABILITY_INVERSION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        NOT HP_BAR(player);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Inversion works as an innate trait", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_INVERSION; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_VAPOREON, 1) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); Innates(ability); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[1].damage);
    }
}
#endif
