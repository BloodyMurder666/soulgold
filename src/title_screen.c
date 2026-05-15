#include "global.h"
#include "battle.h"
#include "title_screen.h"
#include "sprite.h"
#include "gba/m4a_internal.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "event_data.h"
#include "intro.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "palette.h"
#include "random.h"
#include "reset_rtc_screen.h"
#include "berry_fix_program.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "trig.h"
#include "graphics.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum {
    TAG_PRESS_START_COPYRIGHT = 1001,
};

#define START_BANNER_X 128
#define START_BANNER_Y 86
#define COPYRIGHT_BANNER_Y 152
#define POKEMON_LOGO_Y -80

#define CLEAR_SAVE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_UP)
#define RESET_RTC_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_LEFT)
#define BERRY_UPDATE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON)
#define A_B_START_SELECT (A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON)

static void MainCB2(void);
static void Task_TitleScreenPhase1(u8);
static void Task_TitleScreenPhase2(u8);
static void Task_TitleScreenPhase3(u8);
static void CB2_GoToMainMenu(void);
static void CB2_GoToClearSaveDataScreen(void);
static void CB2_GoToResetRtcScreen(void);
static void CB2_GoToBerryFixScreen(void);
static void CB2_GoToCopyrightScreen(void);
static void UpdateTitleScreenBgPulse(u8);

static void SpriteCB_PressStartCopyrightBanner(struct Sprite *sprite);

// const rom data
static const u16 sUnusedUnknownPal[] = INCBIN_U16("graphics/title_screen/unused.gbapal");

static const u32 sTitleScreenRayquazaGfx[] = INCBIN_U32("graphics/title_screen/rayquaza.8bpp.smol");
static const u32 sTitleScreenRayquazaTilemap[] = INCBIN_U32("graphics/title_screen/rayquaza.bin.smolTM");

// Also used by the intro to blend the Game Freak name/logo in and out as they appear and disappear.
const u16 gTitleScreenAlphaBlend[64] =
{
    BLDALPHA_BLEND(16, 0),
    BLDALPHA_BLEND(16, 1),
    BLDALPHA_BLEND(16, 2),
    BLDALPHA_BLEND(16, 3),
    BLDALPHA_BLEND(16, 4),
    BLDALPHA_BLEND(16, 5),
    BLDALPHA_BLEND(16, 6),
    BLDALPHA_BLEND(16, 7),
    BLDALPHA_BLEND(16, 8),
    BLDALPHA_BLEND(16, 9),
    BLDALPHA_BLEND(16, 10),
    BLDALPHA_BLEND(16, 11),
    BLDALPHA_BLEND(16, 12),
    BLDALPHA_BLEND(16, 13),
    BLDALPHA_BLEND(16, 14),
    BLDALPHA_BLEND(16, 15),
    BLDALPHA_BLEND(15, 16),
    BLDALPHA_BLEND(14, 16),
    BLDALPHA_BLEND(13, 16),
    BLDALPHA_BLEND(12, 16),
    BLDALPHA_BLEND(11, 16),
    BLDALPHA_BLEND(10, 16),
    BLDALPHA_BLEND(9, 16),
    BLDALPHA_BLEND(8, 16),
    BLDALPHA_BLEND(7, 16),
    BLDALPHA_BLEND(6, 16),
    BLDALPHA_BLEND(5, 16),
    BLDALPHA_BLEND(4, 16),
    BLDALPHA_BLEND(3, 16),
    BLDALPHA_BLEND(2, 16),
    BLDALPHA_BLEND(1, 16),
    BLDALPHA_BLEND(0, 16),
    [32 ... 63] = BLDALPHA_BLEND(0, 16)
};

static const struct OamData sOamData_CopyrightBanner =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PressStart_0[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_PressStart_1[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_PressStart_2[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_PressStart_3[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_PressStart_4[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Copyright_0[] =
{
    ANIMCMD_FRAME(21, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Copyright_1[] =
{
    ANIMCMD_FRAME(25, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Copyright_2[] =
{
    ANIMCMD_FRAME(29, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Copyright_3[] =
{
    ANIMCMD_FRAME(33, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Copyright_4[] =
{
    ANIMCMD_FRAME(37, 4),
    ANIMCMD_END,
};

// The "Press Start" and copyright graphics are each 5 32x8 segments long
#define NUM_PRESS_START_FRAMES 5
#define NUM_COPYRIGHT_FRAMES 5

static const union AnimCmd *const sStartCopyrightBannerAnimTable[NUM_PRESS_START_FRAMES + NUM_COPYRIGHT_FRAMES] =
{
    sAnim_PressStart_0,
    sAnim_PressStart_1,
    sAnim_PressStart_2,
    sAnim_PressStart_3,
    sAnim_PressStart_4,
    [NUM_PRESS_START_FRAMES] =
    sAnim_Copyright_0,
    sAnim_Copyright_1,
    sAnim_Copyright_2,
    sAnim_Copyright_3,
    sAnim_Copyright_4,
};

static const struct SpriteTemplate sStartCopyrightBannerSpriteTemplate =
{
    .tileTag = TAG_PRESS_START_COPYRIGHT,
    .paletteTag = TAG_PRESS_START_COPYRIGHT,
    .oam = &sOamData_CopyrightBanner,
    .anims = sStartCopyrightBannerAnimTable,
    .callback = SpriteCB_PressStartCopyrightBanner,
};

static const struct CompressedSpriteSheet sSpriteSheet_PressStart[] =
{
    {
        .data = gTitleScreenPressStartGfx,
        .size = 0x520,
        .tag = TAG_PRESS_START_COPYRIGHT
    },
    {},
};

static const struct SpritePalette sSpritePalette_PressStart[] =
{
    {
        .data = gTitleScreenPressStartPal,
        .tag = TAG_PRESS_START_COPYRIGHT
    },
    {},
};

// Task data for the main title screen tasks (Task_TitleScreenPhase#)
#define tCounter    data[0]
#define tSkipToNext data[1]
#define tPointless  data[2] // Incremented but never used to do anything.

// Sprite data for SpriteCB_PressStartCopyrightBanner
#define sAnimate data[0]
#define sTimer   data[1]

static void SpriteCB_PressStartCopyrightBanner(struct Sprite *sprite)
{
    if (sprite->sAnimate == TRUE)
    {
        // Alternate between hidden and shown every 16th frame
        if (++sprite->sTimer & 16)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

static void CreatePressStartBanner(s16 x, s16 y)
{
    u8 i;
    u8 spriteId;

    x -= 64;
    for (i = 0; i < NUM_PRESS_START_FRAMES; i++, x += 32)
    {
        spriteId = CreateSprite(&sStartCopyrightBannerSpriteTemplate, x, y, 0);
        StartSpriteAnim(&gSprites[spriteId], i);
        gSprites[spriteId].sAnimate = TRUE;
    }
}

static void CreateCopyrightBanner(s16 x, s16 y)
{
    u8 i;
    u8 spriteId;

    x -= 64;
    for (i = 0; i < NUM_COPYRIGHT_FRAMES; i++, x += 32)
    {
        spriteId = CreateSprite(&sStartCopyrightBannerSpriteTemplate, x, y, 0);
        StartSpriteAnim(&gSprites[spriteId], i + NUM_PRESS_START_FRAMES);
    }
}

#undef sAnimate
#undef sTimer

static void VBlankCB(void)
{
    ScanlineEffect_InitHBlankDmaTransfer();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitTitleScreen(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *((u16 *)PLTT) = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
        DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        gMain.state = 1;
        break;
    case 1:
        // bg2
        DecompressDataWithHeaderVram(gTitleScreenPokemonLogoGfx, (void *)(BG_CHAR_ADDR(0)));
        DecompressDataWithHeaderVram(gTitleScreenPokemonLogoTilemap, (void *)(BG_SCREEN_ADDR(9)));
        LoadPalette(gTitleScreenBgPalettes, BG_PLTT_ID(0), 16 * PLTT_SIZE_4BPP);
        // bg0
        DecompressDataWithHeaderVram(sTitleScreenRayquazaGfx, (void *)(BG_CHAR_ADDR(2)));
        DecompressDataWithHeaderVram(sTitleScreenRayquazaTilemap, (void *)(BG_SCREEN_ADDR(31)));
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 9;
        LoadCompressedSpriteSheet(&sSpriteSheet_PressStart[0]);
        LoadSpritePalette(&sSpritePalette_PressStart[0]);
        gMain.state = 2;
        break;
    case 2:
    {
        u8 taskId = CreateTask(Task_TitleScreenPhase1, 0);

        gTasks[taskId].tCounter = 256;
        gTasks[taskId].tSkipToNext = FALSE;
        gTasks[taskId].tPointless = -16;
        gMain.state = 3;
        break;
    }
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_WHITEALPHA);
        SetVBlankCallback(VBlankCB);
        gMain.state = 4;
        break;
    case 4:
        PanFadeAndZoomScreen(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 0x100, 0);
        SetGpuReg(REG_OFFSET_BG2X_L, -29 * 256);
        SetGpuReg(REG_OFFSET_BG2X_H, -1);
        SetGpuReg(REG_OFFSET_BG2Y_L, POKEMON_LOGO_Y * 256);
        SetGpuReg(REG_OFFSET_BG2Y_H, -1);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WINOBJ_ALL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(31) | BGCNT_256COLOR | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(9) | BGCNT_256COLOR | BGCNT_AFF256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_OBJ_ON
                                    | DISPCNT_WIN0_ON
                                    | DISPCNT_OBJWIN_ON);
        m4aSongNumStart(MUS_HG_TITLE);
        gMain.state = 5;
        break;
    case 5:
        if (!UpdatePaletteFade())
        {
            SetMainCallback2(MainCB2);
        }
        break;
    }
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// Wait briefly before showing the title prompts.
static void Task_TitleScreenPhase1(u8 taskId)
{
    // Skip to next phase when A, B, Start, or Select is pressed
    if (JOY_NEW(A_B_START_SELECT) || gTasks[taskId].tSkipToNext)
    {
        gTasks[taskId].tSkipToNext = TRUE;
        gTasks[taskId].tCounter = 0;
    }

    if (gTasks[taskId].tCounter != 0)
    {
        gTasks[taskId].tCounter--;
    }
    else
    {
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        SetGpuReg(REG_OFFSET_BLDY, 0);

        gTasks[taskId].tCounter = 144;
        gTasks[taskId].func = Task_TitleScreenPhase2;
    }
}

// Create "Press Start" and copyright banners.
static void Task_TitleScreenPhase2(u8 taskId)
{
    // Skip to next phase when A, B, Start, or Select is pressed
    if (JOY_NEW(A_B_START_SELECT) || gTasks[taskId].tSkipToNext)
    {
        gTasks[taskId].tSkipToNext = TRUE;
        gTasks[taskId].tCounter = 0;
    }

    if (gTasks[taskId].tCounter != 0)
    {
        gTasks[taskId].tCounter--;
    }
    else
    {
        gTasks[taskId].tSkipToNext = TRUE;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_OBJ_ON);
        CreatePressStartBanner(START_BANNER_X, START_BANNER_Y);
        CreateCopyrightBanner(START_BANNER_X, COPYRIGHT_BANNER_Y);
        gTasks[taskId].func = Task_TitleScreenPhase3;
    }

    if (!(gTasks[taskId].tCounter & 3) && gTasks[taskId].tPointless != 0)
        gTasks[taskId].tPointless++;
    gTasks[taskId].data[5] = 15; // Unused
    gTasks[taskId].data[6] = 6;  // Unused
}

// Show Rayquaza silhouette and process main title screen input
static void Task_TitleScreenPhase3(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGM(4);
        PlayCry_Normal((Random() & 1) ? SPECIES_HO_OH : SPECIES_LUGIA, CRY_PRIORITY_AMBIENT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
        SetMainCallback2(CB2_GoToMainMenu);
    }
    else if (JOY_HELD(CLEAR_SAVE_BUTTON_COMBO) == CLEAR_SAVE_BUTTON_COMBO)
    {
        SetMainCallback2(CB2_GoToClearSaveDataScreen);
    }
    else if (JOY_HELD(RESET_RTC_BUTTON_COMBO) == RESET_RTC_BUTTON_COMBO
      && CanResetRTC() == TRUE)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToResetRtcScreen);
    }
    else if (JOY_HELD(BERRY_UPDATE_BUTTON_COMBO) == BERRY_UPDATE_BUTTON_COMBO)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToBerryFixScreen);
    }
    else
    {
        ++gTasks[taskId].tCounter;
       //UpdateTitleScreenBgPulse(gTasks[taskId].tCounter);
        if ((gMPlayInfo_BGM.status & 0xFFFF) == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
            SetMainCallback2(CB2_GoToCopyrightScreen);
        }
    }
}

static void CB2_GoToMainMenu(void)
{
    if (!UpdatePaletteFade() && !IsCryPlaying())
        SetMainCallback2(CB2_InitMainMenu);
}

static void CB2_GoToCopyrightScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitCopyrightScreenAfterTitleScreen);
}

static void CB2_GoToClearSaveDataScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitClearSaveDataScreen);
}

static void CB2_GoToResetRtcScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitResetRtcScreen);
}

static void CB2_GoToBerryFixScreen(void)
{
    if (!UpdatePaletteFade())
    {
        m4aMPlayAllStop();
        SetMainCallback2(CB2_InitBerryFixProgram);
    }
}

static void UNUSED UpdateTitleScreenBgPulse(u8 frameNum)
{
    u8 intensity = Q_8_8_TO_INT((Cos(frameNum, Q_8_8(0.5)) + Q_8_8(0.5)) * 6);

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, intensity);
}
