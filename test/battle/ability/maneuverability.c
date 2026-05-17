#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Maneuverability gives priority to damaging moves below 60 printed BP")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CUT; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_CUT) > 0 && GetMovePower(MOVE_CUT) < 60);
        ASSUME(GetMovePower(MOVE_SWIFT) == 60);
        ASSUME(GetMoveCategory(MOVE_CELEBRATE) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MANEUVERABILITY); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (move == MOVE_CUT) {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, move, player);
        }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Maneuverability gives priority to damaging moves below 60 printed BP (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_MANEUVERABILITY); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_CUT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
#endif
