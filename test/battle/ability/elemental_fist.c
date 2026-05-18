#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Elemental Fist makes physical punch moves scale with Sp. Atk", s16 damage)
{
    u16 spAttack;

    PARAMETRIZE { spAttack = 50; }
    PARAMETRIZE { spAttack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FIRE_PUNCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(IsPunchingMove(MOVE_FIRE_PUNCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ELEMENTAL_FIST); Attack(50); SpAttack(spAttack); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_PUNCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Elemental Fist does not affect non-punch physical moves", s16 damage)
{
    u16 spAttack;

    PARAMETRIZE { spAttack = 50; }
    PARAMETRIZE { spAttack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(!IsPunchingMove(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ELEMENTAL_FIST); Attack(100); SpAttack(spAttack); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_EQ(results[1].damage, results[0].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Elemental Fist makes physical punch moves scale with Sp. Atk (Traits)", s16 damage)
{
    u16 spAttack;

    PARAMETRIZE { spAttack = 50; }
    PARAMETRIZE { spAttack = 200; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FIRE_PUNCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(IsPunchingMove(MOVE_FIRE_PUNCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_ELEMENTAL_FIST); Attack(50); SpAttack(spAttack); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_PUNCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[1].damage, results[0].damage);
    }
}
#endif
