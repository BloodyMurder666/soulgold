#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Showtime sets Trick Room on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHOWTIME); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHOWTIME);
        MESSAGE("Wobbuffet twisted the dimensions!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Showtime does not toggle off existing Trick Room")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHOWTIME); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wynaut twisted the dimensions!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SHOWTIME);
            MESSAGE("Wobbuffet twisted the dimensions!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Showtime sets Trick Room on entry (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_SHOWTIME); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHOWTIME);
        MESSAGE("Wobbuffet twisted the dimensions!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
#endif
