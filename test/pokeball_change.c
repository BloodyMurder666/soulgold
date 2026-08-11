#include "global.h"
#include "item.h"
#include "pokeball.h"
#include "pokemon.h"
#include "test/test.h"

static const enum Item sPokeballItems[] =
{
    ITEM_STRANGE_BALL,
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_MASTER_BALL,
    ITEM_PREMIER_BALL,
    ITEM_HEAL_BALL,
    ITEM_NET_BALL,
    ITEM_NEST_BALL,
    ITEM_DIVE_BALL,
    ITEM_DUSK_BALL,
    ITEM_TIMER_BALL,
    ITEM_QUICK_BALL,
    ITEM_REPEAT_BALL,
    ITEM_LUXURY_BALL,
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_MOON_BALL,
    ITEM_FRIEND_BALL,
    ITEM_LOVE_BALL,
    ITEM_FAST_BALL,
    ITEM_HEAVY_BALL,
    ITEM_DREAM_BALL,
    ITEM_SAFARI_BALL,
    ITEM_SPORT_BALL,
    ITEM_PARK_BALL,
    ITEM_BEAST_BALL,
    ITEM_CHERISH_BALL,
};

static void ClearPokeballPocket(void)
{
    memset(gSaveBlock1Ptr->bag.pokeBalls, 0, sizeof(gSaveBlock1Ptr->bag.pokeBalls));
}

static void SetMonPokeball(struct Pokemon *mon, enum PokeBall ball)
{
    u8 ballId = ball;

    SetMonData(mon, MON_DATA_POKEBALL, &ballId);
}

TEST("Changing a Pokemon's Poke Ball consumes exactly one selected Ball")
{
    struct Pokemon mon;
    enum Item heldItem = ITEM_LEFTOVERS;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_POKE);
    SetMonData(&mon, MON_DATA_HELD_ITEM, &heldItem);
    EXPECT(AddBagItem(ITEM_GREAT_BALL, 2));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_SUCCESS);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_GREAT);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_GREAT_BALL), 1);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POKE_BALL), 0);
}

TEST("Changing away from a Master Ball never returns the original Master Ball")
{
    struct Pokemon mon;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_MEWTWO, 70, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_MASTER);
    EXPECT(AddBagItem(ITEM_POKE_BALL, 1));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_POKE_BALL), CHANGE_MON_POKEBALL_SUCCESS);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_POKE);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POKE_BALL), 0);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_MASTER_BALL), 0);
}

TEST("Changing to a Master Ball consumes it and does not return the original Ball")
{
    struct Pokemon mon;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_MEWTWO, 70, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_POKE);
    EXPECT(AddBagItem(ITEM_MASTER_BALL, 1));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_MASTER_BALL), CHANGE_MON_POKEBALL_SUCCESS);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_MASTER_BALL), 0);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POKE_BALL), 0);
}

TEST("Using the same kind of Poke Ball is rejected without consuming it")
{
    struct Pokemon mon;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_POKE);
    EXPECT(AddBagItem(ITEM_POKE_BALL, 2));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_POKE_BALL), CHANGE_MON_POKEBALL_SAME_BALL);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_POKE);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POKE_BALL), 2);
}

TEST("A Poke Ball change requires the selected Ball to be in the Bag")
{
    struct Pokemon mon;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_POKE);

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_ITEM_NOT_OWNED);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_POKE);
}

TEST("Non-Ball items cannot change a Pokemon's Poke Ball")
{
    struct Pokemon mon;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_POKE);
    EXPECT(AddBagItem(ITEM_POTION, 1));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_POTION), CHANGE_MON_POKEBALL_INVALID_ITEM);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_POKE);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_POTION), 1);
}

TEST("Eggs and empty party slots cannot have their Poke Ball changed")
{
    struct Pokemon egg;
    struct Pokemon empty = {0};
    bool8 isEgg = TRUE;

    ClearPokeballPocket();
    CreateMon(&egg, SPECIES_TOGEPI, 1, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&egg, MON_DATA_IS_EGG, &isEgg);
    SetMonPokeball(&egg, BALL_POKE);
    EXPECT(AddBagItem(ITEM_GREAT_BALL, 2));

    EXPECT_EQ(TryChangeMonPokeball(&egg, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_INVALID_MON);
    EXPECT_EQ(TryChangeMonPokeball(&empty, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_INVALID_MON);
    EXPECT_EQ(GetMonData(&egg, MON_DATA_POKEBALL), BALL_POKE);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_GREAT_BALL), 2);
}

TEST("Poke Ball changes work for fainted Pokemon")
{
    struct Pokemon mon;
    u16 hp = 0;

    ClearPokeballPocket();
    CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_HP, &hp);
    SetMonPokeball(&mon, BALL_POKE);
    EXPECT(AddBagItem(ITEM_GREAT_BALL, 1));

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_SUCCESS);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_GREAT);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HP), 0);
}

TEST("Every defined Poke Ball item can become a Pokemon's Poke Ball")
{
    struct Pokemon mon;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sPokeballItems); i++)
    {
        enum Item item = sPokeballItems[i];
        enum PokeBall oldBall = item == ITEM_POKE_BALL ? BALL_GREAT : BALL_POKE;

        ClearPokeballPocket();
        CreateMon(&mon, SPECIES_PIKACHU, 50, 0, OTID_STRUCT_PLAYER_ID);
        SetMonPokeball(&mon, oldBall);
        EXPECT_EQ(GetItemPocket(item), POCKET_POKE_BALLS);
        EXPECT_EQ(GetItemType(item), ITEM_USE_BAG_MENU);
        EXPECT_EQ(GetItemBattleUsage(item), EFFECT_ITEM_THROW_BALL);
        EXPECT(AddBagItem(item, 1));

        EXPECT_EQ(TryChangeMonPokeball(&mon, item), CHANGE_MON_POKEBALL_SUCCESS);
        EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), ItemIdToBallId(item));
        EXPECT_EQ(CountTotalItemQuantityInBag(item), 0);
    }
}

TEST("A full Ball pocket does not receive the Pokemon's original Ball")
{
    struct Pokemon mon;
    u32 item;

    ClearPokeballPocket();
    for (item = ITEM_POKE_BALL; item <= ITEM_CHERISH_BALL; item++)
        EXPECT(AddBagItem(item, 1));

    CreateMon(&mon, SPECIES_MEWTWO, 70, 0, OTID_STRUCT_PLAYER_ID);
    SetMonPokeball(&mon, BALL_MASTER);

    EXPECT_EQ(TryChangeMonPokeball(&mon, ITEM_GREAT_BALL), CHANGE_MON_POKEBALL_SUCCESS);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_POKEBALL), BALL_GREAT);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_GREAT_BALL), 0);
    EXPECT_EQ(CountTotalItemQuantityInBag(ITEM_MASTER_BALL), 1);
}
