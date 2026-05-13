#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MEDITATE) == EFFECT_ATTACK_UP);
    ASSUME(GetMoveEffect(MOVE_LEER) == EFFECT_DEFENSE_DOWN);
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_SPIN_OUT, MOVE_EFFECT_SPD_MINUS_2) == TRUE);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
    ASSUME(gItemsInfo[ITEM_GANLON_BERRY].holdEffect == HOLD_EFFECT_DEFENSE_UP);
}

SINGLE_BATTLE_TEST("Stat animation text prints during self stat-up animation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MEDITATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEDITATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE_DURING_STAT_ANIM("Wobbuffet's Attack rose!", player);
    }
}

SINGLE_BATTLE_TEST("Stat animation text prints during target stat-drop animation")
{
    FORCE_MOVE_ANIM(TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE_DURING_STAT_ANIM("The opposing Wobbuffet's Defense fell!", opponent);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
    }
}

SINGLE_BATTLE_TEST("Stat animation text prints during secondary stat-drop animation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIN_OUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIN_OUT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE_DURING_STAT_ANIM("Wobbuffet's Speed harshly fell!", player);
    }
}

SINGLE_BATTLE_TEST("Stat animation text prints during held item stat-up animation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_GANLON_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE_DURING_STAT_ANIM("Using Ganlon Berry, the Defense of Wobbuffet rose!", player);
    }
}

SINGLE_BATTLE_TEST("Stat animation text prints during ability stat-up animation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE_DURING_STAT_ANIM("The opposing Zacian's Intrepid Sword raised its Attack!", opponent);
    }
}

SINGLE_BATTLE_TEST("Stat animation text prints during Intimidate switch-in stat-drop animation")
{
    FORCE_MOVE_ANIM(TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE_DURING_STAT_ANIM("The opposing Arbok's Intimidate cuts Wobbuffet's Attack!", player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
    }
}

DOUBLE_BATTLE_TEST("Stat animation text prints during doubles stat-up animations")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HOWL) == TARGET_USER_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HOWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE_DURING_STAT_ANIM("Wobbuffet's Attack rose!", playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE_DURING_STAT_ANIM("Wynaut's Attack rose!", playerRight);
    }
}
