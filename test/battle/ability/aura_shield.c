#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aura Shield blocks one damaging hit without changing form")
{
    s16 damage;

    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_AURA_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_AURA_SHIELD);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
        EXPECT_GT(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Aura Shield does not block status moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GROWL) == EFFECT_ATTACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_AURA_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        NONE_OF { ABILITY_POPUP(player, ABILITY_AURA_SHIELD); }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Aura Shield blocks one damaging hit without changing form (Traits)")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_AURA_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_AURA_SHIELD);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
        EXPECT_EQ(player->hp, player->maxHP);
    }
}
#endif
