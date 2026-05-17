#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Unstoppable prevents fatigue confusion from rampage moves")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_THRASH, MOVE_EFFECT_THRASH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_UNSTOPPABLE); MovesWithPP({MOVE_THRASH, 10}); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        NONE_OF { ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player); }
        NONE_OF { MESSAGE("Wobbuffet became confused due to fatigue!"); }
    } THEN {
        EXPECT(player->volatiles.confusionTurns == 0);
    }
}

SINGLE_BATTLE_TEST("Unstoppable does not block regular confusion")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_UNSTOPPABLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Wobbuffet became confused!");
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

