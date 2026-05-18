#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Windburst sets Tailwind on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Ability(ABILITY_WINDBURST); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(15); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WINDBURST);
        MESSAGE("The Tailwind blew from behind your team!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Generic switch-in boost abilities raise their matching stat")
{
    enum Ability ability;
    enum Stat statId;

    PARAMETRIZE { ability = ABILITY_BATTLE_FERVOR; statId = STAT_ATK; }
    PARAMETRIZE { ability = ABILITY_GUARD_STANCE; statId = STAT_DEF; }
    PARAMETRIZE { ability = ABILITY_MENTAL_SURGE; statId = STAT_SPATK; }
    PARAMETRIZE { ability = ABILITY_RESOLUTE_GUARD; statId = STAT_SPDEF; }
    PARAMETRIZE { ability = ABILITY_SKIP_STEP; statId = STAT_SPEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Generic switch-in drop abilities lower their matching opposing stat")
{
    enum Ability ability;
    enum Stat statId;

    PARAMETRIZE { ability = ABILITY_BREAKING_PRESENCE; statId = STAT_DEF; }
    PARAMETRIZE { ability = ABILITY_DISQUIET; statId = STAT_SPDEF; }
    PARAMETRIZE { ability = ABILITY_HOBBLE; statId = STAT_SPEED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE - 1);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("New switch-in abilities work as innates")
{
    enum Ability innate;
    enum Stat statId;
    bool32 targetsUser;

    PARAMETRIZE { innate = ABILITY_SKIP_STEP; statId = STAT_SPEED; targetsUser = TRUE; }
    PARAMETRIZE { innate = ABILITY_HOBBLE; statId = STAT_SPEED; targetsUser = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHED_SKIN); Innates(innate); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, innate);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, targetsUser ? opponent : player);
    } THEN {
        if (targetsUser)
            EXPECT_EQ(opponent->statStages[statId], DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE - 1);
    }
}
#endif
