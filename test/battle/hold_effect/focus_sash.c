#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
}

SINGLE_BATTLE_TEST("Focus Sash is restored after battle when held battle items are restored")
{
    GIVEN {
        WITH_CONFIG(B_RESTORE_HELD_BATTLE_ITEMS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(1); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet hung on using its Focus Sash!");
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), ITEM_FOCUS_SASH);
    }
}

SINGLE_BATTLE_TEST("Focus Sash is not restored after battle before held battle items are restored")
{
    GIVEN {
        WITH_CONFIG(B_RESTORE_HELD_BATTLE_ITEMS, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(1); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet hung on using its Focus Sash!");
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), ITEM_NONE);
    }
}
