#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_area_region_map.h"
#include "region_map.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

static const u16 ALIGNED(4) sPokedexAreaMap_Pal[] = INCBIN_U16("graphics/pokedex/region_map.gbapal");
static const u32 sPokedexAreaMap_Gfx[] = INCBIN_U32("graphics/pokedex/region_map.8bpp.smol");
static const u32 sPokedexAreaMap_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map.bin.smolTM");
static const u16 ALIGNED(4) sPokedexAreaSevii123Map_Pal[] = INCBIN_U16("graphics/pokedex/region_map_sevii123.gbapal");
static const u32 sPokedexAreaSevii123Map_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_sevii123.8bpp.smol");
static const u32 sPokedexAreaSevii123Map_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_sevii123.bin.smolTM");
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_affine.8bpp.smol");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_affine.bin.smolTM");

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *template, u8 mapPage)
{
    u8 mode;
    void *tilemap;
    const u16 *pal = sPokedexAreaMap_Pal;
    u32 palSize = sizeof(sPokedexAreaMap_Pal);
    const u32 *gfx = sPokedexAreaMap_Gfx;
    const u32 *tilemapLz = sPokedexAreaMap_Tilemap;
    u8 screenSize = 0;

    sPokedexAreaMapBgNum = Alloc(sizeof(sPokedexAreaMapBgNum));
    mode = template->mode;
    if (mapPage != REGION_MAP_PAGE_MAIN)
    {
        pal = sPokedexAreaSevii123Map_Pal;
        palSize = sizeof(sPokedexAreaSevii123Map_Pal);
        gfx = sPokedexAreaSevii123Map_Gfx;
        tilemapLz = sPokedexAreaSevii123Map_Tilemap;
        screenSize = 0;
    }

    if (mode == 0)
    {
        SetBgAttribute(template->bg, BG_ATTR_SCREENSIZE, screenSize);
        DecompressAndCopyTileDataToVram(template->bg, gfx, 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, tilemapLz, 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 32, 32, FALSE); // template->offset is always 0, so this does nothing.
    }
    else
    {
        // This is never reached, only a mode of 0 is given
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 2);
        SetBgAttribute(template->bg, BG_ATTR_TYPE, BG_TYPE_AFFINE); // This does nothing. BG_ATTR_TYPE can't be set with this function
        DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Gfx, 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Tilemap, 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 64, 64, TRUE); // template->offset is always 0, so this does nothing.
    }

    ChangeBgX(template->bg, 0, BG_COORD_SET);
    ChangeBgY(template->bg, 0, BG_COORD_SET);
    SetBgAttribute(template->bg, BG_ATTR_PALETTEMODE, 1);
    CpuCopy32(pal, &gPlttBufferUnfaded[BG_PLTT_ID(7)], palSize);
    *sPokedexAreaMapBgNum = template->bg;
}

bool32 TryShowPokedexAreaMap(void)
{
    if (!FreeTempTileDataBuffersIfPossible())
    {
        ShowBg(*sPokedexAreaMapBgNum);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void FreePokedexAreaMapBgNum(void)
{
    TRY_FREE_AND_SET_NULL(sPokedexAreaMapBgNum);
}

void PokedexAreaMapChangeBg(s16 x, s16 y)
{
    ChangeBgX(*sPokedexAreaMapBgNum, x * 0x100, BG_COORD_SET);
    ChangeBgY(*sPokedexAreaMapBgNum, y * 0x100, BG_COORD_SET);
}

void PokedexAreaMapChangeBgY(s16 move)
{
    PokedexAreaMapChangeBg(0, move);
}
