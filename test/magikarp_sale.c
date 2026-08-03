#include "global.h"
#include "event_data.h"
#include "mail.h"
#include "money.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/species.h"

static void CreateSaleMon(u8 partyIndex, u16 species, u8 level)
{
    CreateMonWithIVs(&gPlayerParty[partyIndex], species, level, 0, OTID_STRUCT_PLAYER_ID, 0);
    CalculatePlayerPartyCount();
}

static struct BoxPokemon *CreateSaleBoxMon(u8 boxId, u8 boxPosition, u16 species, u8 level)
{
    struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);

    CreateBoxMon(boxMon, species, level, 0, OTID_STRUCT_PLAYER_ID);
    SetBoxMonIVs(boxMon, 0);
    return boxMon;
}

static NOINLINE void TrySellPartyMon(u8 partyIndex)
{
    gSpecialVar_0x8004 = partyIndex;
    RUN_OVERWORLD_SCRIPT(
        removegenericmon SPECIES_MAGIKARP;
    );
}

static void TrySellBoxMon(u8 boxId, u8 boxPosition)
{
    gSpecialVar_MonBoxId = boxId;
    gSpecialVar_MonBoxPos = boxPosition;
    TrySellPartyMon(PC_MON_CHOSEN);
}

TEST("Magikarp sale removes a valid Magikarp and refreshes party count")
{
    CreateSaleMon(0, SPECIES_MAGIKARP, 10);
    CreateSaleMon(1, SPECIES_BULBASAUR, 10);
    SetMoney(&gSaveBlock1Ptr->money, 0);

    TrySellPartyMon(0);

    EXPECT_EQ(gSpecialVar_Result, MON_UNSATISFACTORY);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_BULBASAUR);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_NONE);
    EXPECT_EQ(gPlayerPartyCount, 1);
}

TEST("Magikarp sale rejects an Egg")
{
    bool8 isEgg = TRUE;

    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, 10);
    SetMonData(&gPlayerParty[1], MON_DATA_IS_EGG, &isEgg);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_IS_EGG);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_MAGIKARP);
}

TEST("Magikarp sale rejects the last usable Pokemon")
{
    bool8 isEgg = TRUE;

    CreateSaleMon(0, SPECIES_MAGIKARP, 10);
    CreateSaleMon(1, SPECIES_BULBASAUR, 10);
    SetMonData(&gPlayerParty[1], MON_DATA_IS_EGG, &isEgg);

    TrySellPartyMon(0);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_LAST_USABLE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_MAGIKARP);
}

TEST("Magikarp sale rejects held Mail without orphaning it")
{
    u8 mailId;

    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, 10);
    mailId = GiveMailToMonByItemId(&gPlayerParty[1], ITEM_ORANGE_MAIL);
    EXPECT_NE(mailId, MAIL_NONE);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_HAS_HELD_ITEM);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_MAGIKARP);
    EXPECT_EQ(gSaveBlock1Ptr->mail[mailId].itemId, ITEM_ORANGE_MAIL);
}

TEST("Magikarp sale rejects an ordinary held item")
{
    u16 heldItem = ITEM_NUGGET;

    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, 10);
    SetMonData(&gPlayerParty[1], MON_DATA_HELD_ITEM, &heldItem);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_HAS_HELD_ITEM);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_MAGIKARP);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_HELD_ITEM), ITEM_NUGGET);
}

TEST("Magikarp sale rejects a payout that would exceed the money cap")
{
    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, 10);
    SetMoney(&gSaveBlock1Ptr->money, MAX_MONEY - 1999);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_NO_PAYMENT_ROOM);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_MAGIKARP);
    EXPECT_EQ(GetMoney(&gSaveBlock1Ptr->money), MAX_MONEY - 1999);
}

TEST("Magikarp sale permits a payout that exactly reaches the money cap")
{
    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, 10);
    SetMoney(&gSaveBlock1Ptr->money, MAX_MONEY - 2000);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_UNSATISFACTORY);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("Magikarp sale recognizes a level 100 Magikarp")
{
    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    CreateSaleMon(1, SPECIES_MAGIKARP, MAX_LEVEL);
    SetMoney(&gSaveBlock1Ptr->money, 0);

    TrySellPartyMon(1);

    EXPECT_EQ(gSpecialVar_Result, MON_SATISFACTORY);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("Magikarp sale removes a boxed Magikarp without applying the last party mon guard")
{
    struct BoxPokemon *boxMon;

    CreateSaleMon(0, SPECIES_BULBASAUR, 10);
    boxMon = CreateSaleBoxMon(0, 0, SPECIES_MAGIKARP, 10);
    SetMoney(&gSaveBlock1Ptr->money, 0);

    TrySellBoxMon(0, 0);

    EXPECT_EQ(gSpecialVar_Result, MON_UNSATISFACTORY);
    EXPECT_EQ(GetBoxMonData(boxMon, MON_DATA_SPECIES), SPECIES_NONE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_BULBASAUR);
    EXPECT_EQ(gPlayerPartyCount, 1);
}

TEST("Magikarp sale recognizes a boxed level 100 Magikarp")
{
    struct BoxPokemon *boxMon = CreateSaleBoxMon(0, 0, SPECIES_MAGIKARP, MAX_LEVEL);

    SetMoney(&gSaveBlock1Ptr->money, 0);
    TrySellBoxMon(0, 0);

    EXPECT_EQ(gSpecialVar_Result, MON_SATISFACTORY);
    EXPECT_EQ(GetBoxMonData(boxMon, MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("Magikarp sale rejects and preserves a boxed held item")
{
    struct BoxPokemon *boxMon = CreateSaleBoxMon(0, 0, SPECIES_MAGIKARP, 10);
    u16 heldItem = ITEM_NUGGET;

    SetBoxMonData(boxMon, MON_DATA_HELD_ITEM, &heldItem);
    TrySellBoxMon(0, 0);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_HAS_HELD_ITEM);
    EXPECT_EQ(GetBoxMonData(boxMon, MON_DATA_SPECIES), SPECIES_MAGIKARP);
    EXPECT_EQ(GetBoxMonData(boxMon, MON_DATA_HELD_ITEM), ITEM_NUGGET);
}

TEST("Magikarp sale rejects a boxed Egg")
{
    struct BoxPokemon *boxMon = CreateSaleBoxMon(0, 0, SPECIES_MAGIKARP, 10);
    bool8 isEgg = TRUE;

    SetBoxMonData(boxMon, MON_DATA_IS_EGG, &isEgg);
    TrySellBoxMon(0, 0);

    EXPECT_EQ(gSpecialVar_Result, MON_REMOVE_IS_EGG);
    EXPECT_EQ(GetBoxMonData(boxMon, MON_DATA_SPECIES), SPECIES_MAGIKARP);
}

TEST("Magikarp sale rejects invalid PC coordinates")
{
    TrySellBoxMon(0, IN_BOX_COUNT);

    EXPECT_EQ(gSpecialVar_Result, FALSE);
}

TEST("Magikarp sale command reports its save effect before mutating party data")
{
    const u8 *script = OVERWORLD_SCRIPT(
        removegenericmon SPECIES_MAGIKARP;
    );

    ZeroPlayerPartyMons();
    CreateSaleMon(0, SPECIES_MAGIKARP, 10);
    CreateSaleMon(1, SPECIES_BULBASAUR, 10);
    gSpecialVar_0x8004 = 0;

    EXPECT(!Script_HasNoEffect(script));
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_MAGIKARP);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_BULBASAUR);
    EXPECT_EQ(gPlayerPartyCount, 2);
}
