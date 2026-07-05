#include "global.h"
#include "battle.h"
#include "battle_script_commands.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "test/test.h"

static void RunPostBattlePickup(void)
{
    static const u8 sPickupCommand[] = { B_SCR_OP_PICKUP };

    gBattlescriptCurrInstr = sPickupCommand;
    gBattleScriptingCommandsTable[B_SCR_OP_PICKUP]();
}

static void SetUpPickupMon(enum Item heldItem)
{
    gMapHeader.mapLayoutId = 0;
    ZeroPlayerPartyMons();
    CreateMon(&gPlayerParty[0], SPECIES_ZIGZAGOON, 1, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM, &heldItem);

    SET_RNG(RNG_PICKUP_ITEM_CHANCE, TRUE);
    SET_RNG(RNG_PICKUP_ITEM, 0);
}

TEST("Post-battle Pickup gives an item to the Pokémon when its held item slot is empty")
{
    struct BagPocket *pocket = &gBagPockets[POCKET_MEDICINE];

    memset(pocket->itemSlots, 0, sizeof(gSaveBlock1Ptr->bag.medicine));
    SetUpPickupMon(ITEM_NONE);

    ASSUME(MonHasTrait(&gPlayerParty[0], ABILITY_PICKUP));

    RunPostBattlePickup();

    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), ITEM_POTION);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POTION), 0);
}

TEST("Post-battle Pickup puts an item in the Bag when the holder's item slot is occupied")
{
    enum Item heldItem = ITEM_LEFTOVERS;
    struct BagPocket *pocket = &gBagPockets[POCKET_MEDICINE];

    memset(pocket->itemSlots, 0, sizeof(gSaveBlock1Ptr->bag.medicine));
    SetUpPickupMon(heldItem);

    ASSUME(MonHasTrait(&gPlayerParty[0], ABILITY_PICKUP));

    RunPostBattlePickup();

    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POTION), 1);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), heldItem);
}

TEST("Post-battle Pickup leaves the held item unchanged when the Bag is full")
{
    enum Item heldItem = ITEM_LEFTOVERS;
    struct BagPocket *pocket = &gBagPockets[POCKET_MEDICINE];
    u16 quantityBefore;

    memset(pocket->itemSlots, 0, sizeof(gSaveBlock1Ptr->bag.medicine));
    for (u32 i = 0; i < pocket->capacity; i++)
    {
        pocket->itemSlots[i].itemId = ITEM_POTION;
        pocket->itemSlots[i].quantity = MAX_BAG_ITEM_CAPACITY;
    }
    quantityBefore = CountTotalItemQuantityInBag(ITEM_POTION);
    SetUpPickupMon(heldItem);

    ASSUME(MonHasTrait(&gPlayerParty[0], ABILITY_PICKUP));
    ASSUME(GetFreeSpaceForItemInBag(ITEM_POTION) == 0);

    RunPostBattlePickup();

    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POTION), quantityBefore);
    EXPECT_EQ(GetFreeSpaceForItemInBag(ITEM_POTION), 0);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), heldItem);

    memset(pocket->itemSlots, 0, sizeof(gSaveBlock1Ptr->bag.medicine));
}
