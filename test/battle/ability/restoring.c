#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Restoring gains Aqua Ring on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RESTORING); HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RESTORING);
        MESSAGE("Wobbuffet surrounded itself with a veil of water!");
    } THEN {
        EXPECT_EQ(player->hp, 58);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Restoring gains Aqua Ring on entry (Traits)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_RESTORING); HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RESTORING);
        MESSAGE("Wobbuffet surrounded itself with a veil of water!");
    } THEN {
        EXPECT_EQ(player->hp, 58);
    }
}
#endif
