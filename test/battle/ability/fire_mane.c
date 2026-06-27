#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fire Mane boosts physical and special Fire-type moves", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_FIRE_MANE; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_FLAME_CHARGE; }
    PARAMETRIZE { ability = ABILITY_FIRE_MANE; move = MOVE_FLAME_CHARGE; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_FLAMETHROWER; }
    PARAMETRIZE { ability = ABILITY_FIRE_MANE; move = MOVE_FLAMETHROWER; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_FLAME_CHARGE) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_FLAMETHROWER) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_FLAME_CHARGE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_FLAMETHROWER) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_PYROAR_MEGA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9999); MaxHP(9999); }
    } WHEN {
        TURN { MOVE(player, move, secondaryEffect: FALSE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Fire Mane works as an innate trait", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_FIRE_MANE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_FLAMETHROWER) == TYPE_FIRE);
        PLAYER(SPECIES_PYROAR_MEGA) { Ability(ABILITY_RIVALRY); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9999); MaxHP(9999); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLAMETHROWER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
#endif
