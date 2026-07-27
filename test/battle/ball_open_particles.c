#include "global.h"
#include "battle_anim.h"
#include "test/battle.h"

static u32 CountActiveSprites(void)
{
    u32 count = 0;

    for (u32 i = 0; i < MAX_SPRITES; i++)
        count += gSprites[i].inUse;

    return count;
}

enum BallParticleSpawnMode
{
    PARTICLES_SEQUENTIAL,
    PARTICLES_TWO_WAVES,
    PARTICLES_IMMEDIATE,
};

static void TestDenseBallParticleCount(enum PokeBall ball, enum BallParticleSpawnMode mode, u32 expectedCount)
{
    u32 spritesBefore = CountActiveSprites();
    u8 taskId = AnimateBallOpenParticles(100, 80, 1, 1, ball);

    if (mode == PARTICLES_SEQUENTIAL)
    {
        for (u32 i = 0; i < expectedCount; i++)
            gTasks[taskId].func(taskId);
    }
    else
    {
        gTasks[taskId].func(taskId);

        if (mode == PARTICLES_TWO_WAVES)
        {
            // The second wave starts after eight task ticks.
            for (u32 i = 0; i < 9; i++)
                gTasks[taskId].func(taskId);
        }
    }

    EXPECT_EQ(CountActiveSprites(), spritesBefore + expectedCount);
}

#define PARAMETRIZE_DENSE_BALL_EFFECTS                                              \
    PARAMETRIZE { ball = BALL_POKE;    mode = PARTICLES_SEQUENTIAL; }               \
    PARAMETRIZE { ball = BALL_HEAL;    mode = PARTICLES_SEQUENTIAL; }               \
    PARAMETRIZE { ball = BALL_STRANGE; mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_GREAT;   mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_LUXURY;  mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_LURE;    mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_LOVE;    mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_FAST;    mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_HEAVY;   mode = PARTICLES_TWO_WAVES; }                \
    PARAMETRIZE { ball = BALL_MASTER;  mode = PARTICLES_IMMEDIATE; }                \
    PARAMETRIZE { ball = BALL_CHERISH; mode = PARTICLES_IMMEDIATE; }

SINGLE_BATTLE_TEST("Dense ball effects keep sixteen particles in single battles")
{
    enum PokeBall ball;
    enum BallParticleSpawnMode mode;

    PARAMETRIZE_DENSE_BALL_EFFECTS;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } THEN {
        TestDenseBallParticleCount(ball, mode, 16);
    }
}

DOUBLE_BATTLE_TEST("Dense ball effects use eight particles in double battles")
{
    enum PokeBall ball;
    enum BallParticleSpawnMode mode;

    PARAMETRIZE_DENSE_BALL_EFFECTS;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } THEN {
        TestDenseBallParticleCount(ball, mode, 8);
    }
}

#undef PARAMETRIZE_DENSE_BALL_EFFECTS
