#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_BITE) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
    ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
}

SINGLE_BATTLE_TEST("Reactive gives priority if the opponent is about to use a super-effective move")
{
    enum Move opponentMove;

    PARAMETRIZE { opponentMove = MOVE_BITE; }
    PARAMETRIZE { opponentMove = MOVE_TACKLE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REACTIVE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, opponentMove); }
    } SCENE {
        if (opponentMove == MOVE_BITE) {
            ABILITY_POPUP(player, ABILITY_REACTIVE);
            MESSAGE("Wobbuffet can act faster than normal, thanks to its Reactive!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponent);
        } else {
            NOT ABILITY_POPUP(player, ABILITY_REACTIVE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    }
}

DOUBLE_BATTLE_TEST("Reactive only responds to targeted super-effective moves aimed at the user")
{
    bool32 targetReactiveBattler;

    PARAMETRIZE { targetReactiveBattler = TRUE; }
    PARAMETRIZE { targetReactiveBattler = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REACTIVE); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        if (targetReactiveBattler) {
            TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentLeft, MOVE_BITE, target: playerLeft); }
        } else {
            TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentLeft, MOVE_BITE, target: playerRight); }
        }
    } SCENE {
        if (targetReactiveBattler) {
            ABILITY_POPUP(playerLeft, ABILITY_REACTIVE);
            MESSAGE("Wobbuffet can act faster than normal, thanks to its Reactive!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
        } else {
            NOT ABILITY_POPUP(playerLeft, ABILITY_REACTIVE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Reactive responds to spread super-effective moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SNARL) == TYPE_DARK);
        ASSUME(GetMoveTarget(MOVE_SNARL) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REACTIVE); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentLeft, MOVE_SNARL); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_REACTIVE);
        MESSAGE("Wobbuffet can act faster than normal, thanks to its Reactive!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNARL, opponentLeft);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Reactive gives priority if the opponent is about to use a super-effective move (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_REACTIVE); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_BITE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_REACTIVE);
        MESSAGE("Wobbuffet can act faster than normal, thanks to its Reactive!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponent);
    }
}
#endif
