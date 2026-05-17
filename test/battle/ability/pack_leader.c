#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Pack Leader boosts damage by 5 percent per alive party member", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_PACK_LEADER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Pack Leader counts only alive party members", s16 damage)
{
    u32 alive;

    PARAMETRIZE { alive = 1; }
    PARAMETRIZE { alive = 5; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PACK_LEADER); }
        PLAYER(SPECIES_WYNAUT) { HP(alive >= 1 ? 1 : 0); }
        PLAYER(SPECIES_WYNAUT) { HP(alive >= 2 ? 1 : 0); }
        PLAYER(SPECIES_WYNAUT) { HP(alive >= 3 ? 1 : 0); }
        PLAYER(SPECIES_WYNAUT) { HP(alive >= 4 ? 1 : 0); }
        PLAYER(SPECIES_WYNAUT) { HP(alive >= 5 ? 1 : 0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.1905), results[1].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Pack Leader boosts damage by 5 percent per alive party member (Traits)", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_PACK_LEADER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ability); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.25), results[1].damage);
    }
}
#endif
