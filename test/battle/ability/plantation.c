#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Plantation has a 30% chance to seed damaged targets")
{
    PASSES_RANDOMLY(3, 10, RNG_PLANTATION);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_BULBASAUR) { Ability(ABILITY_PLANTATION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_PLANTATION);
        MESSAGE("The opposing Wobbuffet was seeded!");
    }
}

SINGLE_BATTLE_TEST("Plantation does not seed Grass-type targets")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        ASSUME(IsSpeciesOfType(SPECIES_BULBASAUR, TYPE_GRASS));
        PLAYER(SPECIES_BULBASAUR) { Ability(ABILITY_PLANTATION); }
        OPPONENT(SPECIES_BULBASAUR);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_PLANTATION, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PLANTATION);
            MESSAGE("The opposing Bulbasaur was seeded!");
        }
    }
}

SINGLE_BATTLE_TEST("Plantation only seeds if the target takes damage")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_BULBASAUR) { Ability(ABILITY_PLANTATION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_PLANTATION, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ABILITY_POPUP(player, ABILITY_PLANTATION);
            MESSAGE("The opposing Wobbuffet was seeded!");
        }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Plantation has a 30% chance to seed damaged targets (Traits)")
{
    PASSES_RANDOMLY(3, 10, RNG_PLANTATION);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); Innates(ABILITY_PLANTATION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_PLANTATION);
        MESSAGE("The opposing Wobbuffet was seeded!");
    }
}
#endif
