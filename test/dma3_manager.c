#include "global.h"
#include "dma3.h"
#include "test/test.h"

TEST("DMA3 request queue reports overflow")
{
    ALIGNED(4) u8 src[4] = {0};
    ALIGNED(4) u8 dest[4] = {0};

    ClearDma3Requests();
    for (u32 i = 0; i < MAX_DMA_REQUESTS + 1; i++)
        RequestDma3Copy(src, dest, sizeof(src), 1);

    EXPECT_EQ(gDma3RequestCount, MAX_DMA_REQUESTS);
    EXPECT_EQ(gDma3RequestHighWaterMark, MAX_DMA_REQUESTS);
    EXPECT_EQ(gDma3RequestOverflowCount, 1);

    ClearDma3Requests();
    EXPECT_EQ(gDma3RequestCount, 0);
    EXPECT_EQ(gDma3RequestHighWaterMark, 0);
    EXPECT_EQ(gDma3RequestOverflowCount, 0);
}
