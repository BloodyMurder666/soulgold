#include "global.h"
#include "test/test.h"
#include "battle.h"
#include "battle_main.h"
#include "data.h"
#include "malloc.h"
#include "random.h"
#include "string_util.h"
#include "trainer_pools.h"
#include "constants/item.h"
#include "constants/abilities.h"
#include "constants/trainers.h"
#include "constants/battle.h"
#include "constants/battle_ai.h"

#define NUM_TEST_TRAINERS 15

static const struct Trainer sTestTrainers[DIFFICULTY_COUNT][NUM_TEST_TRAINERS] =
{
#include "trainer_control.h"
};

enum DifficultyLevel GetTrainerDifficultyLevelTest(u16 trainerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (sTestTrainers[difficulty][trainerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

