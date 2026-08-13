#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GRAVITY) == EFFECT_GRAVITY);
}

SINGLE_BATTLE_TEST("Gravity Well sets Gravity on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
        EXPECT_EQ(gFieldTimers.gravityTimer, 4);
    }
}

SINGLE_BATTLE_TEST("Gravity Well's Gravity lasts five turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
        TURN { }
        TURN { }
        TURN { }
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        MESSAGE("Gravity returned to normal!");
    } THEN {
        EXPECT(!(gFieldStatuses & STATUS_FIELD_GRAVITY));
        EXPECT_EQ(gFieldTimers.gravityTimer, 0);
    }
}

SINGLE_BATTLE_TEST("Gravity Well does not restart Gravity that is already active")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRAVITY); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, opponent);
        MESSAGE("Gravity intensified!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
            MESSAGE("Gravity intensified!");
        }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
        EXPECT_EQ(gFieldTimers.gravityTimer, 3);
    }
}

SINGLE_BATTLE_TEST("Gravity Well does not activate later when pre-existing Gravity expires")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRAVITY); }
        TURN { SWITCH(player, 1); }
        TURN { }
        TURN { }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, opponent);
        MESSAGE("Gravity intensified!");
        MESSAGE("Gravity returned to normal!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
            MESSAGE("Gravity intensified!");
        }
    } THEN {
        EXPECT(!(gFieldStatuses & STATUS_FIELD_GRAVITY));
    }
}

SINGLE_BATTLE_TEST("Gravity Well does not reactivate when its Gravity expires while the user remains active")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
        TURN { }
        TURN { }
        TURN { }
        TURN { }
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        MESSAGE("Gravity returned to normal!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
            MESSAGE("Gravity intensified!");
        }
    } THEN {
        EXPECT(!(gFieldStatuses & STATUS_FIELD_GRAVITY));
    }
}

SINGLE_BATTLE_TEST("Gravity Well reactivates after the user leaves and re-enters battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
        TURN { }
        TURN { }
        TURN { }
        TURN { }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        MESSAGE("Gravity returned to normal!");
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
    }
}

SINGLE_BATTLE_TEST("Gravity Well activates when it is no longer suppressed by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_GRAVITY_WELL);
            MESSAGE("Gravity intensified!");
        }
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
    }
}

SINGLE_BATTLE_TEST("Gravity Well activates through Neutralizing Gas when protected by Ability Shield")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's Ability is protected by the effects of its Ability Shield!");
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
    }
}

DOUBLE_BATTLE_TEST("Only one Gravity Well activates when multiple battlers enter at once")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_GRAVITY_WELL); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(25); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_GRAVITY_WELL);
            MESSAGE("Gravity intensified!");
        }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
    }
}

SINGLE_BATTLE_TEST("Gravity Well grounds Flying types, Levitate users, and Air Balloon holders")
{
    u32 species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_PIDGEY;   ability = ABILITY_TANGLED_FEET; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_LEVITATE;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SHADOW_TAG;    item = ITEM_AIR_BALLOON; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); Moves(MOVE_EARTHQUAKE); }
        OPPONENT(species) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Gravity Well cancels Fly and Sky Drop when it activates")
{
    u8 visibility;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(90); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); Speed(80); }
        OPPONENT(SPECIES_PIDGEY) { Speed(50); }
        OPPONENT(SPECIES_ROOKIDEE) { Speed(45); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SKY_DROP, target: playerRight); MOVE(opponentRight, MOVE_FLY, target: playerLeft); }
        TURN { SWITCH(playerLeft, 2); SKIP_TURN(opponentLeft); SKIP_TURN(opponentRight); }
    } SCENE {
        MESSAGE("The opposing Pidgey used Sky Drop!");
        MESSAGE("The opposing Pidgey took Wynaut into the sky!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
        MESSAGE("The opposing Rookidee used Fly!");
        MESSAGE("The opposing Rookidee flew up high!");
        ABILITY_POPUP(playerLeft, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        MESSAGE("The opposing Pidgey fell from the sky due to the gravity!");
        MESSAGE("The opposing Rookidee fell from the sky due to the gravity!");
    } THEN {
        visibility = gBattleSpritesDataPtr->battlerData[B_POSITION_PLAYER_LEFT].invisible;
        EXPECT_EQ(visibility, FALSE);
        visibility = gBattleSpritesDataPtr->battlerData[B_POSITION_PLAYER_RIGHT].invisible;
        EXPECT_EQ(visibility, FALSE);
        visibility = gBattleSpritesDataPtr->battlerData[B_POSITION_OPPONENT_LEFT].invisible;
        EXPECT_EQ(visibility, FALSE);
        visibility = gBattleSpritesDataPtr->battlerData[B_POSITION_OPPONENT_RIGHT].invisible;
        EXPECT_EQ(visibility, FALSE);
    }
}

DOUBLE_BATTLE_TEST("Gravity Well clears Magnet Rise and Telekinesis when it activates")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGNET_RISE) == EFFECT_MAGNET_RISE);
        ASSUME(GetMoveEffect(MOVE_TELEKINESIS) == EFFECT_TELEKINESIS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(90); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GRAVITY_WELL); Speed(80); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(45); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_MAGNET_RISE); MOVE(opponentRight, MOVE_TELEKINESIS, target: playerRight); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, opponentLeft);
        MESSAGE("The opposing Wobbuffet levitated with electromagnetism!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEKINESIS, opponentRight);
        MESSAGE("Wynaut was hurled into the air!");
        ABILITY_POPUP(playerLeft, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
        MESSAGE("Wynaut fell from the sky due to the gravity!");
    } THEN {
        EXPECT(!playerRight->volatiles.telekinesis);
        EXPECT(!opponentLeft->volatiles.magnetRise);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Gravity Well sets Gravity on entry as an innate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_GRAVITY_WELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_GRAVITY_WELL);
        MESSAGE("Gravity intensified!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_GRAVITY);
    }
}
#endif
