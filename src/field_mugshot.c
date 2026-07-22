#include "global.h"
#include "decompress.h"
#include "sprite.h"
#include "script.h"
#include "event_data.h"
#include "field_weather.h"
#include "field_message_box.h"
#include "field_mugshot.h"
#include "constants/event_objects.h"
#include "constants/field_mugshots.h"
#include "data/field_mugshots.h"

enum FieldMugshotMode
{
    FIELD_MUGSHOT_NONE,
    FIELD_MUGSHOT_AUTO,
    FIELD_MUGSHOT_MANUAL,
};

static EWRAM_DATA u8 sFieldMugshotSpriteIds[2] = {};
static EWRAM_DATA u8 sIsFieldMugshotActive = 0;
static EWRAM_DATA u8 sFieldMugshotSlot = 0;
static EWRAM_DATA u8 sFieldMugshotMode = FIELD_MUGSHOT_NONE;
static EWRAM_DATA u8 sFieldMugshotObjectEventSource = 0;
static EWRAM_DATA u8 sAutoFieldMugshotSuppressionCount = 0;
static EWRAM_DATA u16 sFieldMugshotId = MUGSHOT_NONE;
static EWRAM_DATA u16 sFieldMugshotEmote = EMOTE_NORMAL;

#define TAG_MUGSHOT 0x9000
#define TAG_MUGSHOT2 0x9001

// don't remove the `+ 32`
// otherwise your sprite will not be placed in the place you desire
#define MUGSHOT_X 168 + 32
#define MUGSHOT_Y 51  + 32

static void SpriteCB_FieldMugshot(struct Sprite *s);
static bool8 IsFieldMugshotDefined(u32 id, u32 emote);
static void CreateFieldMugshotInternal(u32 id, u32 emote, u8 mode);
static void RemoveAutoFieldMugshot(void);

static const struct OamData sFieldMugshot_Oam = {
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
};

static const struct SpriteTemplate sFieldMugshot_SpriteTemplate = {
    .tileTag = TAG_MUGSHOT,
    .paletteTag = TAG_MUGSHOT,
    .oam = &sFieldMugshot_Oam,
    .callback = SpriteCB_FieldMugshot,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static void SpriteCB_FieldMugshot(struct Sprite *s)
{
    if (s->data[0] == TRUE)
    {
        s->invisible = FALSE;
    }
    else
    {
        s->invisible = TRUE;
    }
}

void RemoveFieldMugshot(void)
{
    ResetPreservedPalettesInWeather();
    if (sFieldMugshotSpriteIds[0] != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_MUGSHOT);
        FreeSpritePaletteByTag(TAG_MUGSHOT);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[0]]);
        sFieldMugshotSpriteIds[0] = SPRITE_NONE;
    }
    if (sFieldMugshotSpriteIds[1] != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_MUGSHOT2);
        FreeSpritePaletteByTag(TAG_MUGSHOT2);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[1]]);
        sFieldMugshotSpriteIds[1] = SPRITE_NONE;
    }
    sIsFieldMugshotActive = FALSE;
    sFieldMugshotMode = FIELD_MUGSHOT_NONE;
    sFieldMugshotId = MUGSHOT_NONE;
    sFieldMugshotEmote = EMOTE_NORMAL;
}

void CreateFieldMugshot(struct ScriptContext *ctx)
{
    u16 id = VarGet(ScriptReadHalfword(ctx));
    u16 emote = VarGet(ScriptReadHalfword(ctx));

    CreateFieldMugshotInternal(id, emote, FIELD_MUGSHOT_MANUAL);
}

void CreateFieldMugshotRival(struct ScriptContext *ctx)
{
    u16 emote = VarGet(ScriptReadHalfword(ctx));
    u16 id = gSaveBlock2Ptr->playerGender == MALE ? MUGSHOT_KRIS : MUGSHOT_GOLD;

    CreateFieldMugshotInternal(id, emote, FIELD_MUGSHOT_MANUAL);
}

void _RemoveFieldMugshot(u8 slot)
{
    ResetPreservedPalettesInWeather();
    if (sFieldMugshotSpriteIds[slot ^ 1] != SPRITE_NONE)
    {
        gSprites[sFieldMugshotSpriteIds[slot ^ 1]].data[0] = FALSE; // same as setting visibility
    }

    if (sFieldMugshotSpriteIds[slot] != SPRITE_NONE)
    {
        gSprites[sFieldMugshotSpriteIds[slot]].data[0] = TRUE; // same as setting visibility
        FreeSpriteTilesByTag(slot + TAG_MUGSHOT);
        FreeSpritePaletteByTag(slot + TAG_MUGSHOT);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[slot]]);
        sFieldMugshotSpriteIds[slot] = SPRITE_NONE;
    }
}

void _CreateFieldMugshot(u32 id, u32 emote)
{
    CreateFieldMugshotInternal(id, emote, FIELD_MUGSHOT_MANUAL);
}

static bool8 IsFieldMugshotDefined(u32 id, u32 emote)
{
    if (id >= NELEMS(sFieldMugshots) || emote >= EMOTE_COUNT)
        return FALSE;
    if (sFieldMugshots[id][emote].gfx == NULL || sFieldMugshots[id][emote].pal == NULL)
        return FALSE;
    return TRUE;
}

u16 GetFieldMugshotIdByObjectGraphicsId(u16 graphicsId)
{
    switch (graphicsId)
    {
    case OBJ_EVENT_GFX_YOUNGSTER:
        return MUGSHOT_YOUNGSTER;
    case OBJ_EVENT_GFX_FALKNER:
        return MUGSHOT_FALKNER;
    case OBJ_EVENT_GFX_BUG_CATCHER:
        return MUGSHOT_BUG_CATCHER;
    case OBJ_EVENT_GFX_PROF_ELM:
        return MUGSHOT_ELM;
    case OBJ_EVENT_GFX_SILVER:
        return MUGSHOT_SILVER;
    case OBJ_EVENT_GFX_LASS:
        return MUGSHOT_LASS;
    case OBJ_EVENT_GFX_PICNICKER:
        return MUGSHOT_PICNICKER;
    case OBJ_EVENT_GFX_CAMPER:
        return MUGSHOT_CAMPER;
    case OBJ_EVENT_GFX_FISHERMAN:
    case OBJ_EVENT_GFX_FISHER:
        return MUGSHOT_FISHERMAN;
    case OBJ_EVENT_GFX_HIKER:
        return MUGSHOT_HIKER;
    case OBJ_EVENT_GFX_BLACK_BELT:
        return MUGSHOT_BLACK_BELT;
    case OBJ_EVENT_GFX_ROCKET_M:
        return MUGSHOT_ROCKET_GRUNT_M;
    case OBJ_EVENT_GFX_ROCKET_F:
        return MUGSHOT_ROCKET_GRUNT_F;
    case OBJ_EVENT_GFX_ARCHER:
        return MUGSHOT_ARCHER;
    case OBJ_EVENT_GFX_ARIANA:
        return MUGSHOT_ARIANA;
    case OBJ_EVENT_GFX_PETREL:
        return MUGSHOT_PETREL;
    case OBJ_EVENT_GFX_PROTON:
        return MUGSHOT_PROTON;
    case OBJ_EVENT_GFX_WILL:
        return MUGSHOT_WILL;
    case OBJ_EVENT_GFX_KOGA:
        return MUGSHOT_KOGA;
    case OBJ_EVENT_GFX_BRUNO:
        return MUGSHOT_BRUNO;
    case OBJ_EVENT_GFX_KAREN:
        return MUGSHOT_KAREN;
    case OBJ_EVENT_GFX_BUGSY:
        return MUGSHOT_BUGSY;
    case OBJ_EVENT_GFX_WHITNEY:
        return MUGSHOT_WHITNEY;
    case OBJ_EVENT_GFX_MORTY:
        return MUGSHOT_MORTY;
    case OBJ_EVENT_GFX_JASMINE:
        return MUGSHOT_JASMINE;
    case OBJ_EVENT_GFX_CHUCK:
        return MUGSHOT_CHUCK;
    case OBJ_EVENT_GFX_PRYCE:
        return MUGSHOT_PRYCE;
    case OBJ_EVENT_GFX_CLAIR:
        return MUGSHOT_CLAIR;
    case OBJ_EVENT_GFX_LANCE:
        return MUGSHOT_LANCE;
    case OBJ_EVENT_GFX_STEVEN:
        return MUGSHOT_STEVEN;
    case OBJ_EVENT_GFX_EUSINE:
        return MUGSHOT_EUSINE;
    case OBJ_EVENT_GFX_NURSE:
        return MUGSHOT_NURSE;
    case OBJ_EVENT_GFX_CLERK:
        return MUGSHOT_CLERK;
    case OBJ_EVENT_GFX_BRENDAN_NORMAL:
        return MUGSHOT_GOLD;
    case OBJ_EVENT_GFX_MAY_NORMAL:
        return MUGSHOT_KRIS;
    case OBJ_EVENT_GFX_MOM:
        return MUGSHOT_MOM;
    case OBJ_EVENT_GFX_ENGINEER:
        return MUGSHOT_ENGINEER;
    case OBJ_EVENT_GFX_GENTLEMAN:
        return MUGSHOT_GENTLEMAN;
    case OBJ_EVENT_GFX_KIMONO_GIRL:
        return MUGSHOT_KIMONO_GIRL;
    case OBJ_EVENT_GFX_LITTLE_BOY_3:
        return MUGSHOT_LITTLE_BOY_3;
    case OBJ_EVENT_GFX_PROF_OAK:
        return MUGSHOT_OAK;
    case OBJ_EVENT_GFX_SAILOR:
        return MUGSHOT_SAILOR;
    case OBJ_EVENT_GFX_SUPER_NERD:
        return MUGSHOT_SUPER_NERD;
    case OBJ_EVENT_GFX_COOLTRAINER_M:
        return MUGSHOT_COOLTRAINER_M;
    case OBJ_EVENT_GFX_COOLTRAINER_F:
        return MUGSHOT_COOLTRAINER_F;
    case OBJ_EVENT_GFX_SWIMMER_F:
    case OBJ_EVENT_GFX_SWIMMER_F_WATER:
        return MUGSHOT_SWIMMER_F;
    case OBJ_EVENT_GFX_SWIMMER_M:
    case OBJ_EVENT_GFX_SWIMMER_M_WATER:
        return MUGSHOT_SWIMMER_M;
    case OBJ_EVENT_GFX_WOMAN_1:
        return MUGSHOT_WOMAN_1;
    case OBJ_EVENT_GFX_WOMAN_2:
        return MUGSHOT_WOMAN_2;
    default:
        return MUGSHOT_NONE;
    }
}

static void RemoveAutoFieldMugshot(void)
{
    if (sFieldMugshotMode == FIELD_MUGSHOT_AUTO)
        RemoveFieldMugshot();
}

static void CreateFieldMugshotInternal(u32 id, u32 emote, u8 mode)
{
    u32 slot = sFieldMugshotSlot;
    struct SpriteTemplate temp = sFieldMugshot_SpriteTemplate;
    struct CompressedSpriteSheet sheet = { .size=0x1000, .tag=slot+TAG_MUGSHOT };
    struct SpritePalette pal = { .tag = sheet.tag };

    if (!IsFieldMugshotDefined(id, emote))
        return;

    if (sIsFieldMugshotActive
     && sFieldMugshotMode == mode
     && sFieldMugshotId == id
     && sFieldMugshotEmote == emote)
        return;

    if (sIsFieldMugshotActive)
    {
        _RemoveFieldMugshot(slot);
    }

    temp.tileTag = sheet.tag;
    temp.paletteTag = sheet.tag;
    sheet.data = sFieldMugshots[id][emote].gfx;
    pal.data = sFieldMugshots[id][emote].pal;

    LoadSpritePalette(&pal);
    LoadCompressedSpriteSheet(&sheet);

    sFieldMugshotSpriteIds[slot] = CreateSprite(&temp, MUGSHOT_X, MUGSHOT_Y, 0);
    if (sFieldMugshotSpriteIds[slot] == SPRITE_NONE)
    {
        return;
    }
    PreservePaletteInWeather(gSprites[sFieldMugshotSpriteIds[slot]].oam.paletteNum + 0x10);
    gSprites[sFieldMugshotSpriteIds[slot]].data[0] = FALSE;
    sIsFieldMugshotActive = TRUE;
    sFieldMugshotMode = mode;
    sFieldMugshotId = id;
    sFieldMugshotEmote = emote;
    sFieldMugshotSlot ^= 1;
}

void SetFieldMugshotObjectEventSource(u8 objectEventId)
{
    sFieldMugshotObjectEventSource = objectEventId;
}

void ClearFieldMugshotObjectEventSource(void)
{
    sFieldMugshotObjectEventSource = OBJECT_EVENTS_COUNT;
}

void BeginSuppressingAutoFieldMugshots(void)
{
    if (sAutoFieldMugshotSuppressionCount++ == 0)
        RemoveAutoFieldMugshot();
}

void EndSuppressingAutoFieldMugshots(void)
{
    if (sAutoFieldMugshotSuppressionCount != 0)
        sAutoFieldMugshotSuppressionCount--;
}

void TryCreateFieldMugshotFromObjectEventSource(void)
{
    u16 mugshotId;

    if (sFieldMugshotMode == FIELD_MUGSHOT_MANUAL)
        return;

    if (sAutoFieldMugshotSuppressionCount != 0)
    {
        RemoveAutoFieldMugshot();
        return;
    }

    if (sFieldMugshotObjectEventSource >= OBJECT_EVENTS_COUNT
     || !gObjectEvents[sFieldMugshotObjectEventSource].active
     || gObjectEvents[sFieldMugshotObjectEventSource].localId == LOCALID_PLAYER)
    {
        RemoveAutoFieldMugshot();
        return;
    }

    mugshotId = GetFieldMugshotIdByObjectGraphicsId(gObjectEvents[sFieldMugshotObjectEventSource].graphicsId);
    if (mugshotId == MUGSHOT_NONE || !IsFieldMugshotDefined(mugshotId, EMOTE_NORMAL))
    {
        RemoveAutoFieldMugshot();
        return;
    }

    CreateFieldMugshotInternal(mugshotId, EMOTE_NORMAL, FIELD_MUGSHOT_AUTO);
}

void CreateAutoFieldMugshot(u32 id, u32 emote)
{
    CreateFieldMugshotInternal(id, emote, FIELD_MUGSHOT_AUTO);
}

void ShowFieldMugshot(void)
{
    if (sIsFieldMugshotActive)
        gSprites[GetFieldMugshotSpriteId()].data[0] = TRUE;
}

u16 GetFieldMugshotId(void)
{
    if (!sIsFieldMugshotActive)
        return MUGSHOT_NONE;
    return sFieldMugshotId;
}

u16 GetFieldMugshotIdFromObjectEventSource(void)
{
    if (sFieldMugshotObjectEventSource >= OBJECT_EVENTS_COUNT
     || !gObjectEvents[sFieldMugshotObjectEventSource].active
     || gObjectEvents[sFieldMugshotObjectEventSource].localId == LOCALID_PLAYER)
        return MUGSHOT_NONE;

    return GetFieldMugshotIdByObjectGraphicsId(gObjectEvents[sFieldMugshotObjectEventSource].graphicsId);
}

u8 GetFieldMugshotSpriteId(void)
{
    return sFieldMugshotSpriteIds[sFieldMugshotSlot ^ 1];
}

u8 IsFieldMugshotActive(void)
{
    return sIsFieldMugshotActive;
}

void SetFieldMugshotSpriteId(u32 value)
{
    sFieldMugshotSpriteIds[0] = value;
    sFieldMugshotSpriteIds[1] = value;
    sIsFieldMugshotActive = FALSE;
    sFieldMugshotSlot = 0;
    sFieldMugshotMode = FIELD_MUGSHOT_NONE;
    sFieldMugshotObjectEventSource = OBJECT_EVENTS_COUNT;
    sAutoFieldMugshotSuppressionCount = 0;
    sFieldMugshotId = MUGSHOT_NONE;
    sFieldMugshotEmote = EMOTE_NORMAL;
}
