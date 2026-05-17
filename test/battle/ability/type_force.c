#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rocky Payload variants boost their matching move type", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_TRUE_GRIT;       move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_ROCK_SMASH; }
    PARAMETRIZE { ability = ABILITY_WARRIOR_SPIRIT;  move = MOVE_ROCK_SMASH; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_GUST; }
    PARAMETRIZE { ability = ABILITY_WIND_FORCE;      move = MOVE_GUST; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_POISON_STING; }
    PARAMETRIZE { ability = ABILITY_TOXIC_CORE;      move = MOVE_POISON_STING; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_MUD_SHOT; }
    PARAMETRIZE { ability = ABILITY_EARTHBOUND;      move = MOVE_MUD_SHOT; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_STRUGGLE_BUG; }
    PARAMETRIZE { ability = ABILITY_HIVE_FORCE;      move = MOVE_STRUGGLE_BUG; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_SHADOW_BALL; }
    PARAMETRIZE { ability = ABILITY_SPECTRAL_FORCE;  move = MOVE_SHADOW_BALL; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_FIERY_HEART;     move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_WATER_GUN; }
    PARAMETRIZE { ability = ABILITY_SEABOUND;        move = MOVE_WATER_GUN; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_VINE_WHIP; }
    PARAMETRIZE { ability = ABILITY_VERDANT_SOUL;    move = MOVE_VINE_WHIP; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_CONFUSION; }
    PARAMETRIZE { ability = ABILITY_MIND_FORCE;      move = MOVE_CONFUSION; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_ICE_SHARD; }
    PARAMETRIZE { ability = ABILITY_FROST_FORCE;     move = MOVE_ICE_SHARD; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_BITE; }
    PARAMETRIZE { ability = ABILITY_NIGHTFALL;       move = MOVE_BITE; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;      move = MOVE_DISARMING_VOICE; }
    PARAMETRIZE { ability = ABILITY_FAE_HEART;       move = MOVE_DISARMING_VOICE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 28; j += 2)
            EXPECT_MUL_EQ(results[j].damage, Q_4_12(1.5), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Rocky Payload variants do not boost other move types", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_TRUE_GRIT; }
    PARAMETRIZE { ability = ABILITY_WIND_FORCE; }
    PARAMETRIZE { ability = ABILITY_SEABOUND; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Rocky Payload variants boost their matching move type (Traits)", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS;  move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_FIERY_HEART; move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS;  move = MOVE_WATER_GUN; }
    PARAMETRIZE { ability = ABILITY_SEABOUND;   move = MOVE_WATER_GUN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}
#endif
