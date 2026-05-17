#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fighter Soul adds Fighting STAB to non-Fighting Pokemon", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_FIGHTER_SOUL; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
        ASSUME(!IsSpeciesOfType(SPECIES_SNORLAX, TYPE_FIGHTING));
        PLAYER(SPECIES_SNORLAX) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_KARATE_CHOP); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fighter Soul adds Fighting strengths and weaknesses", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS;     move = MOVE_GUST; }
    PARAMETRIZE { ability = ABILITY_FIGHTER_SOUL; move = MOVE_GUST; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;     move = MOVE_BITE; }
    PARAMETRIZE { ability = ABILITY_FIGHTER_SOUL; move = MOVE_BITE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_GUST) == TYPE_FLYING);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(!IsSpeciesOfType(SPECIES_SNORLAX, TYPE_FIGHTING));
        PLAYER(SPECIES_SNORLAX) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.5), results[3].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Fighter Soul adds Fighting STAB to non-Fighting Pokemon (Traits)", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_FIGHTER_SOUL; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
        ASSUME(!IsSpeciesOfType(SPECIES_SNORLAX, TYPE_FIGHTING));
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_KARATE_CHOP); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
#endif
