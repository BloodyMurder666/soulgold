#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mystic Force doubles Speed in Psychic Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MYSTIC_FORCE); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Mystic Force doubles Speed in Psychic Terrain (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_MYSTIC_FORCE); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
#endif
