#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Steel Feet increases the power of kicking moves by 20%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STEEL_FEET; }
    PARAMETRIZE { ability = ABILITY_BLAZE; }

    GIVEN {
        ASSUME(IsKickingMove(MOVE_MEGA_KICK));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MEGA_KICK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.2), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Steel Feet does not boost non-kicking moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STEEL_FEET; }
    PARAMETRIZE { ability = ABILITY_BLAZE; }

    GIVEN {
        ASSUME(!IsKickingMove(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

