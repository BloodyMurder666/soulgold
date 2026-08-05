#include "global.h"
#include "roamer.h"
#include "test/test.h"

TEST("HasActiveRoamers only reports active roamers")
{
    bool8 savedActiveStates[ROAMER_COUNT];
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        savedActiveStates[i] = gSaveBlock1Ptr->roamer[i].active;
        gSaveBlock1Ptr->roamer[i].active = FALSE;
    }

    EXPECT_EQ(HasActiveRoamers(), FALSE);
    gSaveBlock1Ptr->roamer[ROAMER_COUNT - 1].active = TRUE;
    EXPECT_EQ(HasActiveRoamers(), TRUE);

    for (i = 0; i < ROAMER_COUNT; i++)
        gSaveBlock1Ptr->roamer[i].active = savedActiveStates[i];
}
