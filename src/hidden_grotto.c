#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "hidden_grotto.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/species.h"

#define ITEM_FROM_GROTTO_DATA 0xFFFF

enum HiddenGrottoId
{
    HIDDEN_GROTTO_ROUTE32,
};

enum
{
    HIDDEN_GROTTO_OBJ_ITEM = 1,
    HIDDEN_GROTTO_OBJ_MON = 2,
};

struct HiddenGrottoWeightedEntry
{
    u8 weight;
    u16 value;
};

struct HiddenGrottoMonEntry
{
    u16 species;
    u8 form;
};

struct HiddenGrottoData
{
    u8 mapGroup;
    u8 mapNum;
    u8 monLevel;
    u8 monObjectLocalId;
    u16 rareItem;
    struct HiddenGrottoMonEntry mons[4];
};

static u16 GetCurrentHiddenGrottoId(void);
static struct HiddenGrottoContent *GetCurrentHiddenGrottoContent(void);
static const struct HiddenGrottoData *GetCurrentHiddenGrottoData(void);
static u8 GetHiddenGrottoMonLevel(const struct HiddenGrottoData *grotto);
static void PopulateCurrentHiddenGrotto(void);
static u16 GetWeightedTableEntry(const struct HiddenGrottoWeightedEntry *table, u8 count, u16 totalWeight);
static u16 GetHiddenGrottoSpecies(const struct HiddenGrottoMonEntry *entry);
static u16 GetRandomHiddenGrottoSpecies(const struct HiddenGrottoData *grotto);
static void UpdateCurrentHiddenGrottoMonGraphics(u16 species);

static const struct HiddenGrottoData sHiddenGrottoData[NUM_HIDDEN_GROTTOES] =
{
    [HIDDEN_GROTTO_ROUTE32] =
    {
        .mapGroup = MAP_GROUP(MAP_HIDDEN_GROTTO_ROUTE32),
        .mapNum = MAP_NUM(MAP_HIDDEN_GROTTO_ROUTE32),
        .monLevel = 10,
        .monObjectLocalId = HIDDEN_GROTTO_OBJ_MON,
        .rareItem = ITEM_EVERSTONE,
        .mons =
        {
            { SPECIES_APPLIN, 0 },
            { SPECIES_WOOPER_PALDEA, 0 },
            { SPECIES_EKANS, 0 },
            { SPECIES_MISDREAVUS, 0 },
        },
    },
};

static const struct HiddenGrottoWeightedEntry sHiddenGrottoPokemonIndexes[] =
{
    { 15, 0 },
    { 15, 1 },
    {  8, 2 },
    {  2, 3 },
};

static const struct HiddenGrottoWeightedEntry sHiddenGrottoItems[] =
{
    { 50, ITEM_POKE_BALL },
    { 20, ITEM_GREAT_BALL },
    {  8, ITEM_ULTRA_BALL },
    { 25, ITEM_POTION },
    { 10, ITEM_SUPER_POTION },
    {  4, ITEM_HYPER_POTION },
    { 25, ITEM_REPEL },
    { 10, ITEM_SUPER_REPEL },
    {  4, ITEM_MAX_REPEL },
    {  4, ITEM_FROM_GROTTO_DATA },
};

static const struct HiddenGrottoWeightedEntry sHiddenGrottoHiddenItems[] =
{
    { 99, ITEM_GROWTH_MULCH },
    { 30, ITEM_TINYMUSHROOM },
    { 10, ITEM_BIG_MUSHROOM },
    {  1, ITEM_BALMMUSHROOM },
    {  8, ITEM_HEART_SCALE },
    {  8, ITEM_PEARL },
    {  1, ITEM_RARE_CANDY },
    {  2, ITEM_PP_UP },
    {  1, ITEM_PP_MAX },
};

void DailyResetHiddenGrottoes(void)
{
    memset(gSaveBlock3Ptr->hiddenGrottoContents, 0, sizeof(gSaveBlock3Ptr->hiddenGrottoContents));
}

void HiddenGrotto_InitializeCurrent(void)
{
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();

    gSpecialVar_0x8004 = ITEM_NONE;
    gSpecialVar_0x8005 = 0;

    if (content == NULL)
    {
        gSpecialVar_Result = HIDDEN_GROTTO_EMPTY;
        return;
    }

    PopulateCurrentHiddenGrotto();
    content = GetCurrentHiddenGrottoContent();

    gSpecialVar_Result = content->type;
    gSpecialVar_0x8004 = content->id;

    if (content->type == HIDDEN_GROTTO_POKEMON)
        UpdateCurrentHiddenGrottoMonGraphics(content->id);
}

void HiddenGrotto_EmptyCurrent(void)
{
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();

    if (content != NULL)
    {
        content->type = HIDDEN_GROTTO_EMPTY;
        content->id = ITEM_NONE;
    }
}

void HiddenGrotto_GetCurrentContentType(void)
{
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();

    gSpecialVar_Result = (content != NULL) ? content->type : HIDDEN_GROTTO_EMPTY;
}

void HiddenGrotto_GetCurrentContentId(void)
{
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();

    gSpecialVar_Result = (content != NULL) ? content->id : ITEM_NONE;
}

void HiddenGrotto_CreateCurrentMon(void)
{
    const struct HiddenGrottoData *grotto = GetCurrentHiddenGrottoData();
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();
    u8 abilityNum = 2;

    gSpecialVar_Result = FALSE;

    if (grotto == NULL
     || content == NULL
     || content->type != HIDDEN_GROTTO_POKEMON
     || content->id == SPECIES_NONE
     || content->id >= NUM_SPECIES)
        return;

    CreateScriptedWildMon(content->id, GetHiddenGrottoMonLevel(grotto), ITEM_NONE);
    SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
    CalculateMonStats(&gEnemyParty[0]);
    gSpecialVar_Result = TRUE;
}

void HiddenGrotto_TestCurrentMonBounds(void)
{
    const struct HiddenGrottoData *grotto = GetCurrentHiddenGrottoData();
    u16 invalidCount = 0;
    u16 minSpecies = NUM_SPECIES;
    u16 maxSpecies = SPECIES_NONE;
    u16 lastSpecies = SPECIES_NONE;
    u16 i;

    gSpecialVar_Result = 0xFFFF;
    gSpecialVar_0x8004 = 0;
    gSpecialVar_0x8005 = SPECIES_NONE;
    gSpecialVar_0x8006 = SPECIES_NONE;
    gSpecialVar_0x8007 = SPECIES_NONE;

    if (grotto == NULL)
        return;

    for (i = 0; i < 1000; i++)
    {
        u16 species = GetRandomHiddenGrottoSpecies(grotto);

        if (species == SPECIES_NONE || species >= NUM_SPECIES)
        {
            invalidCount++;
            lastSpecies = species;
            continue;
        }

        if (species < minSpecies)
            minSpecies = species;
        if (species > maxSpecies)
            maxSpecies = species;
    }

    if (minSpecies == NUM_SPECIES)
        minSpecies = SPECIES_NONE;

    gSpecialVar_Result = invalidCount;
    gSpecialVar_0x8004 = 1000;
    gSpecialVar_0x8005 = minSpecies;
    gSpecialVar_0x8006 = maxSpecies;
    gSpecialVar_0x8007 = lastSpecies;

    DebugPrintf("HiddenGrottoTest samples=%d invalid=%d min=%d max=%d lastInvalid=%d",
                gSpecialVar_0x8004, gSpecialVar_Result, gSpecialVar_0x8005, gSpecialVar_0x8006, gSpecialVar_0x8007);
}

static u16 GetCurrentHiddenGrottoId(void)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sHiddenGrottoData); i++)
    {
        if (sHiddenGrottoData[i].mapGroup == gSaveBlock1Ptr->location.mapGroup
         && sHiddenGrottoData[i].mapNum == gSaveBlock1Ptr->location.mapNum)
            return i;
    }

    return NUM_HIDDEN_GROTTOES;
}

static struct HiddenGrottoContent *GetCurrentHiddenGrottoContent(void)
{
    u16 grottoId = GetCurrentHiddenGrottoId();

    if (grottoId >= NUM_HIDDEN_GROTTOES)
        return NULL;

    return &gSaveBlock3Ptr->hiddenGrottoContents[grottoId];
}

static const struct HiddenGrottoData *GetCurrentHiddenGrottoData(void)
{
    u16 grottoId = GetCurrentHiddenGrottoId();

    if (grottoId >= NUM_HIDDEN_GROTTOES)
        return NULL;

    return &sHiddenGrottoData[grottoId];
}

static u8 GetHiddenGrottoMonLevel(const struct HiddenGrottoData *grotto)
{
    return grotto->monLevel;
}

static void PopulateCurrentHiddenGrotto(void)
{
    const struct HiddenGrottoData *grotto = GetCurrentHiddenGrottoData();
    struct HiddenGrottoContent *content = GetCurrentHiddenGrottoContent();
    u16 value;

    if (grotto == NULL || content == NULL || content->type != HIDDEN_GROTTO_UNSET)
        return;

    if (!FlagGet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT))
    {
        FlagSet(FLAG_SYS_HIDDEN_GROTTO_FIRST_VISIT);
        content->type = HIDDEN_GROTTO_POKEMON;
        content->id = GetRandomHiddenGrottoSpecies(grotto);
        return;
    }

    switch (Random() % 5)
    {
    case 0:
        content->type = HIDDEN_GROTTO_POKEMON;
        content->id = GetRandomHiddenGrottoSpecies(grotto);
        break;
    case 1:
    case 2:
        value = GetWeightedTableEntry(sHiddenGrottoItems, ARRAY_COUNT(sHiddenGrottoItems), 160);
        if (value == ITEM_FROM_GROTTO_DATA)
            value = grotto->rareItem;
        content->type = HIDDEN_GROTTO_ITEM;
        content->id = value;
        break;
    case 3:
    case 4:
    default:
        value = GetWeightedTableEntry(sHiddenGrottoHiddenItems, ARRAY_COUNT(sHiddenGrottoHiddenItems), 160);
        content->type = HIDDEN_GROTTO_HIDDEN_ITEM;
        content->id = value;
        break;
    }
}

static u16 GetWeightedTableEntry(const struct HiddenGrottoWeightedEntry *table, u8 count, u16 totalWeight)
{
    u16 roll = Random() % totalWeight;
    u32 i;

    for (i = 0; i < count; i++)
    {
        if (roll < table[i].weight)
            return table[i].value;
        roll -= table[i].weight;
    }

    return table[count - 1].value;
}

static u16 GetHiddenGrottoSpecies(const struct HiddenGrottoMonEntry *entry)
{
    return GetFormSpeciesId(entry->species, entry->form);
}

static u16 GetRandomHiddenGrottoSpecies(const struct HiddenGrottoData *grotto)
{
    u16 monIndex = GetWeightedTableEntry(sHiddenGrottoPokemonIndexes, ARRAY_COUNT(sHiddenGrottoPokemonIndexes), 40);

    return GetHiddenGrottoSpecies(&grotto->mons[monIndex]);
}

static void UpdateCurrentHiddenGrottoMonGraphics(u16 species)
{
    u8 objectEventId;
    const struct HiddenGrottoData *grotto = GetCurrentHiddenGrottoData();
    u16 graphicsId;

    if (grotto == NULL || species == SPECIES_NONE || species >= NUM_SPECIES)
        return;

    graphicsId = species + OBJ_EVENT_MON;

    // The grotto placeholder uses OBJ_EVENT_GFX_VAR_0 in the map template,
    // so the template source must be updated before/while the object spawns.
    VarSet(VAR_OBJ_GFX_ID_0, graphicsId);

    if (TryGetObjectEventIdByLocalIdAndMap(grotto->monObjectLocalId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId))
        return;

    ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], graphicsId);
}
