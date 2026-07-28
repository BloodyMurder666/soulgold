#include "global.h"
#include "item.h"
#include "item_use.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/items.h"

TEST("Reverse Candy costs one BP and lowers a Pokemon by one level")
{
    struct Pokemon mon;
    struct Pokemon expected;

    CreateMonWithIVs(&mon, SPECIES_WOBBUFFET, 50, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&expected, SPECIES_WOBBUFFET, 49, 0, OTID_STRUCT_PLAYER_ID, 0);

    EXPECT_EQ(GetItemBpCost(ITEM_REVERSE_CANDY), 1);
    EXPECT_EQ(GetItemFieldFunc(ITEM_REVERSE_CANDY), ItemUseOutOfBattle_RareCandy);
    EXPECT(TryDecrementMonLevel(&mon));
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEVEL), 49);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_EXP), GetMonData(&expected, MON_DATA_EXP));
    EXPECT_EQ(GetMonData(&mon, MON_DATA_MAX_HP), GetMonData(&expected, MON_DATA_MAX_HP));
}

TEST("Reverse Candy has no effect at level one")
{
    struct Pokemon mon;
    u32 exp;

    CreateMonWithIVs(&mon, SPECIES_WOBBUFFET, MIN_LEVEL, 0, OTID_STRUCT_PLAYER_ID, 0);
    exp = GetMonData(&mon, MON_DATA_EXP);

    EXPECT(!TryDecrementMonLevel(&mon));
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEVEL), MIN_LEVEL);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_EXP), exp);
}

TEST("Multiple Reverse Candies can restore a level 50 Pokemon to level 35")
{
    struct Pokemon mon;
    struct Pokemon expected;
    u32 i;

    CreateMonWithIVs(&mon, SPECIES_WOBBUFFET, 50, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&expected, SPECIES_WOBBUFFET, 35, 0, OTID_STRUCT_PLAYER_ID, 0);

    for (i = 0; i < 15; i++)
        EXPECT(TryDecrementMonLevel(&mon));

    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEVEL), 35);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_EXP), GetMonData(&expected, MON_DATA_EXP));
    EXPECT_EQ(GetMonData(&mon, MON_DATA_MAX_HP), GetMonData(&expected, MON_DATA_MAX_HP));
}
