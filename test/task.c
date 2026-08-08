#include "global.h"
#include "task.h"
#include "test/test.h"

static void AlternateTaskDummy(u8 taskId)
{
}

TEST("TryCreateTask reports task exhaustion without changing an active task")
{
    u32 i;

    for (i = 0; i < NUM_TASKS; i++)
        EXPECT_EQ(TryCreateTask(TaskDummy, i), i);

    EXPECT_EQ(TryCreateTask(AlternateTaskDummy, 0), TASK_NONE);
    EXPECT_EQ(GetTaskCount(), NUM_TASKS);
    EXPECT(gTasks[0].func == TaskDummy);
    ResetTasks();
}
