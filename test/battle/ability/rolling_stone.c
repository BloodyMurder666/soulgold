#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rolling Stone raises Speed each time Rollout deals damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROLLOUT) == EFFECT_ROLLOUT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROLLING_STONE); Speed(80); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLLOUT); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ABILITY_POPUP(player, ABILITY_ROLLING_STONE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ABILITY_POPUP(player, ABILITY_ROLLING_STONE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Rolling Stone does not raise Speed if Rollout deals no damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROLLOUT) == EFFECT_ROLLOUT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROLLING_STONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Rolling Stone raises Speed each time Rollout deals damage (Traits)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROLLOUT) == EFFECT_ROLLOUT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_ROLLING_STONE); Speed(80); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLLOUT); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ABILITY_POPUP(player, ABILITY_ROLLING_STONE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ABILITY_POPUP(player, ABILITY_ROLLING_STONE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}
#endif
