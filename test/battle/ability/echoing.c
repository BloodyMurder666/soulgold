#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Echoing gives sound-based damaging moves a 30% chance to flinch")
{
    PASSES_RANDOMLY(3, 10, RNG_ECHOING);
    GIVEN {
        ASSUME(IsSoundMove(MOVE_ROUND));
        ASSUME(GetMovePower(MOVE_ROUND) > 0);
        ASSUME(!MoveHasAdditionalEffect(MOVE_ROUND, MOVE_EFFECT_FLINCH));
        PLAYER(SPECIES_EXPLOUD) { Speed(100); Ability(ABILITY_ECHOING); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Echoing does not affect non-sound moves")
{
    GIVEN {
        ASSUME(!IsSoundMove(MOVE_SWIFT));
        ASSUME(GetMovePower(MOVE_SWIFT) > 0);
        PLAYER(SPECIES_EXPLOUD) { Speed(100); Ability(ABILITY_ECHOING); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT, WITH_RNG(RNG_ECHOING, TRUE)); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NONE_OF { MESSAGE("The opposing Wobbuffet flinched and couldn't move!"); }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Echoing gives sound-based damaging moves a 30% chance to flinch (Traits)")
{
    PASSES_RANDOMLY(3, 10, RNG_ECHOING);
    GIVEN {
        ASSUME(IsSoundMove(MOVE_ROUND));
        ASSUME(GetMovePower(MOVE_ROUND) > 0);
        ASSUME(!MoveHasAdditionalEffect(MOVE_ROUND, MOVE_EFFECT_FLINCH));
        PLAYER(SPECIES_EXPLOUD) { Speed(100); Ability(ABILITY_SOUNDPROOF); Innates(ABILITY_ECHOING); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}
#endif
