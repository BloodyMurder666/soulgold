#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rooted gains Ingrain on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROOTED); HP(50); MaxHP(128); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ROOTED);
        MESSAGE("Wobbuffet planted its roots!");
    } THEN {
        EXPECT_EQ(player->hp, 58);
        EXPECT_EQ(CanBattlerEscape(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), FALSE);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Rooted gains Ingrain on entry (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_ROOTED); HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ROOTED);
        MESSAGE("Wobbuffet planted its roots!");
    } THEN {
        EXPECT_EQ(player->hp, 58);
    }
}
#endif
