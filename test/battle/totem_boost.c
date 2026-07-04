#include "global.h"
#include "test/battle.h"

#define QUEUED_STAT(stat) (1 << ((stat) - 1))
#define QUEUED_TOTEM_FLARE (1 << 7)

static void QueueTotemBoosts(enum BattlerId battler, u8 stats)
{
    u32 i;

    gQueuedStatBoosts[battler].stats = stats | QUEUED_TOTEM_FLARE;
    for (i = 0; i < NUM_BATTLE_STATS - 1; i++)
    {
        if (stats & (1 << i))
            gQueuedStatBoosts[battler].statChanges[i] = 1;
    }
}

SINGLE_BATTLE_TEST("Totem boosts combine all five regular stat messages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        QueueTotemBoosts(B_BATTLER_1,
                         QUEUED_STAT(STAT_ATK)
                       | QUEUED_STAT(STAT_DEF)
                       | QUEUED_STAT(STAT_SPATK)
                       | QUEUED_STAT(STAT_SPDEF)
                       | QUEUED_STAT(STAT_SPEED));
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet's aura flared to life!");
        MESSAGE("The opposing Wobbuffet's all stats rose!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Attack rose!");
            MESSAGE("The opposing Wobbuffet's Speed rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Totem boosts combine a subset of stat messages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        QueueTotemBoosts(B_BATTLER_1, QUEUED_STAT(STAT_ATK) | QUEUED_STAT(STAT_SPEED));
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet's aura flared to life!");
        MESSAGE("The opposing Wobbuffet's Attack and Speed rose!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Attack rose!");
            MESSAGE("The opposing Wobbuffet's Speed rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

#undef QUEUED_STAT
#undef QUEUED_TOTEM_FLARE
