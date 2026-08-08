#include "global.h"
#include "field_screen_effect.h"
#include "overworld.h"
#include "script.h"
#include "task.h"
#include "test/test.h"

static void FieldCallbackDummy(void)
{
}

static void FillTaskTable(void)
{
    u32 i;

    for (i = 0; i < NUM_TASKS; i++)
        EXPECT_NE(TryCreateTask(TaskDummy, i), TASK_NONE);
}

TEST("DoWarp does not fade or lock controls when its transition task cannot be created")
{
    FillTaskTable();
    UnlockPlayerFieldControls();
    gFieldCallback = FieldCallbackDummy;

    DoWarp();

    EXPECT(!ArePlayerFieldControlsLocked());
    EXPECT(gFieldCallback == FieldCallbackDummy);
    EXPECT_EQ(GetTaskCount(), NUM_TASKS);
    ResetTasks();
}

TEST("DoDoorWarp does not lock controls when its transition task cannot be created")
{
    FillTaskTable();
    UnlockPlayerFieldControls();
    gFieldCallback = FieldCallbackDummy;

    DoDoorWarp();

    EXPECT(!ArePlayerFieldControlsLocked());
    EXPECT(gFieldCallback == FieldCallbackDummy);
    EXPECT_EQ(GetTaskCount(), NUM_TASKS);
    ResetTasks();
}
