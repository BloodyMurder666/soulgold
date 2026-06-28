#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Spicy Spray burns attackers after contact and non-contact direct damage")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray does not trigger when only the defender's Substitute is damaged")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
            STATUS_ICON(player, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Spicy Spray triggers when a sound move bypasses the defender's Substitute")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray triggers even if the holder faints from the hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Spicy Spray works as an innate trait")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_CHLOROPHYLL); Innates(ABILITY_SPICY_SPRAY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}
#endif
