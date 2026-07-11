#include "global.h"
#include "event_data.h"
#include "hidden_grotto.h"
#include "pokemon.h"
#include "random.h"
#include "test/test.h"
#include "constants/abilities.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/species.h"

#define HIDDEN_GROTTO_ROUTE32_SAVE_ID 0

static void SetCurrentMapToRoute32Grotto(void)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(MAP_HIDDEN_GROTTO_ROUTE32);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(MAP_HIDDEN_GROTTO_ROUTE32);
}

static struct HiddenGrottoContent *GetRoute32GrottoContent(void)
{
    return &gSaveBlock3Ptr->hiddenGrottoContents[HIDDEN_GROTTO_ROUTE32_SAVE_ID];
}

TEST("Hidden Grotto recognizes only configured grotto maps")
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(MAP_UNDEFINED);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(MAP_UNDEFINED);
    EXPECT(!IsCurrentMapHiddenGrotto());

    SetCurrentMapToRoute32Grotto();
    EXPECT(IsCurrentMapHiddenGrotto());
}

TEST("Hidden Grotto daily reset clears every reserved save slot")
{
    u32 i;

    for (i = 0; i < NUM_HIDDEN_GROTTOES; i++)
    {
        gSaveBlock3Ptr->hiddenGrottoContents[i].type = HIDDEN_GROTTO_POKEMON;
        gSaveBlock3Ptr->hiddenGrottoContents[i].id = SPECIES_APPLIN;
    }

    DailyResetHiddenGrottoes();

    for (i = 0; i < NUM_HIDDEN_GROTTOES; i++)
    {
        EXPECT_EQ(gSaveBlock3Ptr->hiddenGrottoContents[i].type, HIDDEN_GROTTO_UNSET);
        EXPECT_EQ(gSaveBlock3Ptr->hiddenGrottoContents[i].id, ITEM_NONE);
    }
}

TEST("Hidden Grotto first visit always creates and preserves a Pokemon roll")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_POKEMON, 20);

    HiddenGrotto_InitializeCurrent();
    content = GetRoute32GrottoContent();

    EXPECT(FlagGet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT));
    EXPECT_EQ(content->type, HIDDEN_GROTTO_POKEMON);
    EXPECT_EQ(content->id, SPECIES_MAREEP);
    EXPECT_EQ(gSpecialVar_Result, HIDDEN_GROTTO_POKEMON);
    EXPECT_EQ(gSpecialVar_0x8004, SPECIES_MAREEP);

    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_POKEMON, 30);
    HiddenGrotto_InitializeCurrent();
    EXPECT_EQ(content->id, SPECIES_MAREEP);
}

TEST("Hidden Grotto weighted rolls cover Pokemon, visible item, and hidden item tails")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    FlagSet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT);
    content = GetRoute32GrottoContent();

    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_CONTENT, 0);
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_POKEMON, 39);
    HiddenGrotto_InitializeCurrent();
    EXPECT_EQ(content->type, HIDDEN_GROTTO_POKEMON);
    EXPECT_EQ(content->id, SPECIES_MISDREAVUS);

    content->type = HIDDEN_GROTTO_UNSET;
    content->id = ITEM_NONE;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_CONTENT, 1);
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_ITEM, 99);
    HiddenGrotto_InitializeCurrent();
    EXPECT_EQ(content->type, HIDDEN_GROTTO_ITEM);
    EXPECT_EQ(content->id, ITEM_EVERSTONE);

    content->type = HIDDEN_GROTTO_UNSET;
    content->id = ITEM_NONE;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_CONTENT, 2);
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_HIDDEN_ITEM, 99);
    HiddenGrotto_InitializeCurrent();
    EXPECT_EQ(content->type, HIDDEN_GROTTO_HIDDEN_ITEM);
    EXPECT_EQ(content->id, ITEM_PP_MAX);
}

TEST("Hidden Grotto repairs invalid saved content before exposing it to scripts")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    FlagSet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT);
    content = GetRoute32GrottoContent();
    content->type = 0xFF;
    content->id = MAX_u16;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_CONTENT, 1);
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_ITEM, 0);

    HiddenGrotto_InitializeCurrent();

    EXPECT_EQ(content->type, HIDDEN_GROTTO_ITEM);
    EXPECT_EQ(content->id, ITEM_HEALTH_WING);
    EXPECT_EQ(gSpecialVar_Result, HIDDEN_GROTTO_ITEM);
    EXPECT_EQ(gSpecialVar_0x8004, ITEM_HEALTH_WING);
}

TEST("Hidden Grotto repairs nonempty ids stored in empty slots")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    FlagSet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT);
    content = GetRoute32GrottoContent();
    content->type = HIDDEN_GROTTO_EMPTY;
    content->id = ITEM_MASTER_BALL;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_CONTENT, 1);
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_ITEM, 0);

    HiddenGrotto_InitializeCurrent();

    EXPECT_EQ(content->type, HIDDEN_GROTTO_ITEM);
    EXPECT_EQ(content->id, ITEM_HEALTH_WING);
}

TEST("Hidden Grotto Pokemon receive a real hidden ability and two perfect IVs")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    content = GetRoute32GrottoContent();
    content->type = HIDDEN_GROTTO_POKEMON;
    content->id = SPECIES_APPLIN;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_IVS, 0);

    HiddenGrotto_CreateCurrentMon();

    EXPECT(gSpecialVar_Result);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_APPLIN);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL), 10);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM), NUM_NORMAL_ABILITY_SLOTS);
    EXPECT_EQ(GetMonAbility(&gEnemyParty[0]), ABILITY_BULLETPROOF);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_HP_IV), MAX_PER_STAT_IVS);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_ATK_IV), MAX_PER_STAT_IVS);
}

TEST("Hidden Grotto Pokemon without a hidden ability keep a valid normal slot")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    content = GetRoute32GrottoContent();
    content->type = HIDDEN_GROTTO_POKEMON;
    content->id = SPECIES_MISDREAVUS;
    SetupRiggedRng(__LINE__, RNG_HIDDEN_GROTTO_IVS, 0);

    HiddenGrotto_CreateCurrentMon();

    EXPECT(gSpecialVar_Result);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM), 0);
    EXPECT_EQ(GetMonAbility(&gEnemyParty[0]), ABILITY_LEVITATE);
}

TEST("Hidden Grotto rejects stale Pokemon ids without touching the enemy party")
{
    struct HiddenGrottoContent *content;

    SetCurrentMapToRoute32Grotto();
    content = GetRoute32GrottoContent();
    content->type = HIDDEN_GROTTO_POKEMON;
    content->id = NUM_SPECIES;

    HiddenGrotto_CreateCurrentMon();

    EXPECT(!gSpecialVar_Result);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_NONE);
}
