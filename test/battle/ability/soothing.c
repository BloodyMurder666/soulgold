#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Soothing gives damaging moves a 10% chance to sleep the target")
{
    PASSES_RANDOMLY(10, 100, RNG_SOOTHING);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        ASSUME(!MoveHasAdditionalEffect(MOVE_SCRATCH, MOVE_EFFECT_SLEEP));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOOTHING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_SOOTHING);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Soothing only sleeps targets damaged by the move")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOOTHING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_SOOTHING, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ABILITY_POPUP(player, ABILITY_SOOTHING);
            STATUS_ICON(opponent, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Soothing does not affect targets that cannot sleep")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOOTHING); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_SOOTHING, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SOOTHING);
            STATUS_ICON(opponent, sleep: TRUE);
        }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Soothing gives damaging moves a 10% chance to sleep the target (Traits)")
{
    PASSES_RANDOMLY(10, 100, RNG_SOOTHING);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        ASSUME(!MoveHasAdditionalEffect(MOVE_SCRATCH, MOVE_EFFECT_SLEEP));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_SOOTHING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_SOOTHING);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}
#endif
