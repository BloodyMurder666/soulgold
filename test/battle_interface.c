#include "global.h"
#include "battle.h"
#include "battle_interface.h"
#include "constants/items.h"
#include "task.h"
#include "test/test.h"

#define SWAP_TASK_TARGET_BALL 3

TEST("Last-used ball swaps coalesce rapid input to the latest ball")
{
    gBallToDisplay = ITEM_POKE_BALL;
    SwapBallToDisplay(FALSE);

    EXPECT_EQ(GetTaskCount(), 1);
    EXPECT_EQ(gTasks[0].data[SWAP_TASK_TARGET_BALL], ITEM_POKE_BALL);

    gBallToDisplay = ITEM_GREAT_BALL;
    SwapBallToDisplay(FALSE);
    gBallToDisplay = ITEM_ULTRA_BALL;
    SwapBallToDisplay(FALSE);

    EXPECT_EQ(GetTaskCount(), 1);
    EXPECT_EQ(gTasks[0].data[SWAP_TASK_TARGET_BALL], ITEM_ULTRA_BALL);

    DestroyTask(0);
}

#undef SWAP_TASK_TARGET_BALL
