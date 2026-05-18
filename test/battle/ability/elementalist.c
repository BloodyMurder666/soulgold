#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Elementalist makes physical attacks scale with Sp. Atk", s16 damage)
{
    u16 spAttack;

    PARAMETRIZE { spAttack = 50; }
    PARAMETRIZE { spAttack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ELEMENTALIST); Attack(50); SpAttack(spAttack); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Elementalist does not change special attack damage", s16 damage)
{
    u16 attack;

    PARAMETRIZE { attack = 50; }
    PARAMETRIZE { attack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ELEMENTALIST); Attack(attack); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_EQ(results[1].damage, results[0].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Elementalist makes physical attacks scale with Sp. Atk (Traits)", s16 damage)
{
    u16 spAttack;

    PARAMETRIZE { spAttack = 50; }
    PARAMETRIZE { spAttack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_ELEMENTALIST); Attack(50); SpAttack(spAttack); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[1].damage, results[0].damage);
    }
}
#endif
