#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Adrenaline boosts Speed by 30 percent in a pinch")
{
    u16 hp;

    PARAMETRIZE { hp = 34; }
    PARAMETRIZE { hp = 33; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ADRENALINE); MaxHP(99); HP(hp); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(120); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (hp > 33) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Adrenaline boosts Speed by 30 percent in a pinch (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_ADRENALINE); MaxHP(99); HP(33); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(120); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
#endif
