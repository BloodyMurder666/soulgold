#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "difficulty.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "level_scaling.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "constants/vars.h"
#include "event_data.h"

EWRAM_DATA static u8 sCurrPage = 0;

#define tMenuSelection data[0]
#define tTextSpeed data[1]
#define tBattleSceneOff data[2]
#define tBattleStyle data[3]
#define tSound data[4]
#define tButtonMode data[5]
#define tWindowFrameType data[6]
#define tLevelCaps data[7]

#define tFollowers data[8]
#define tAutorun data[9]
#define tTrainerLevelScaling data[10]
#define tWildLevelScaling data[11]
#define tDifficulty data[12]
#define tOverworldSpeedup data[13]

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_LEVELCAPS,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

// Menu items Pg2
enum
{
    MENUITEM_FOLLOWERS,
    MENUITEM_AUTORUN,
    MENUITEM_OVERWORLD_SPEEDUP,
    MENUITEM_TRAINER_LEVEL_SCALING,
    MENUITEM_WILD_LEVEL_SCALING,
    MENUITEM_DIFFICULTY,
    MENUITEM_CANCELPG2,
    MENUITEM_COUNT_PG2,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS
};

#define YPOS_TEXTSPEED    (MENUITEM_TEXTSPEED * 16)
#define YPOS_BATTLESCENE  (MENUITEM_BATTLESCENE * 16)
#define YPOS_BATTLESTYLE  (MENUITEM_BATTLESTYLE * 16)
#define YPOS_SOUND        (MENUITEM_SOUND * 16)
#define YPOS_BUTTONMODE   (MENUITEM_BUTTONMODE * 16)
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)
#define YPOS_LEVELCAPS        (MENUITEM_LEVELCAPS * 16)


#define YPOS_FOLLOWERS  (MENUITEM_FOLLOWERS * 16)
#define YPOS_AUTORUN (MENUITEM_AUTORUN * 16) 
#define YPOS_OVERWORLD_SPEEDUP (MENUITEM_OVERWORLD_SPEEDUP * 16)
#define YPOS_TRAINER_LEVEL_SCALING (MENUITEM_TRAINER_LEVEL_SCALING * 16)
#define YPOS_WILD_LEVEL_SCALING (MENUITEM_WILD_LEVEL_SCALING * 16)
#define YPOS_DIFFICULTY (MENUITEM_DIFFICULTY * 16)

#define PAGE_COUNT  2

static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuFadeIn_Pg2(u8 taskId);
static void Task_OptionMenuProcessInput_Pg2(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void HighlightOptionMenuItem(u8 selection);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection);
static u8 FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection);

static u8 Followers_ProcessInput(u8 selection);
static void Followers_DrawChoices(u8 selection);
static u8 LevelCaps_ProcessInput(u8 selection);
static void LevelCaps_DrawChoices(u8 selection);
static u8 LevelScaling_ProcessInput(u8 selection);
static void TrainerLevelScaling_DrawChoices(u8 selection);
static void WildLevelScaling_DrawChoices(u8 selection);
static u8 Difficulty_ProcessInput(u8 selection);
static void Difficulty_DrawChoices(u8 selection);
static u8   Autorun_ProcessInput(u8 selection);
static void Autorun_DrawChoices(u8 selection);
static u8 OverworldSpeedup_ProcessInput(u8 selection);
static void OverworldSpeedup_DrawChoices(u8 selection);

static void DrawTextOption(void);

static void DrawHeaderText(void);
static void DrawOptionMenuTexts(void);
static void DrawBgWindowFrames(void);

EWRAM_DATA static bool8 sArrowPressed = FALSE;

static const u8 gText_Option[]             = _("OPTION");
static const u8 gText_TextSpeedSlow[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Slow");
static const u8 gText_TextSpeedMid[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mid");
static const u8 gText_TextSpeedFast[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Fast");
static const u8 gText_BattleSceneOn[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}On");
static const u8 gText_BattleSceneOff[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Off");
static const u8 gText_BattleStyleShift[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Shift");
static const u8 gText_BattleStyleSet[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Set");
static const u8 gText_SoundMono[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mono");
static const u8 gText_SoundStereo[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Stereo");
static const u8 gText_FrameType[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Type");
static const u8 gText_FrameTypeNumber[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
static const u8 gText_ButtonTypeNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal");
static const u8 gText_ButtonTypeLR[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
static const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
static const u8 gText_AutorunOn[]            = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}On");
static const u8 gText_AutorunOff[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Off");

static const u8 gText_NoCaps[]             = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}None");
static const u8 gText_SoftCaps[]             = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Soft");
static const u8 gText_HardCaps[]             = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Hard");
static const u8 gText_ScalingOff[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_ScalingOn[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_DifficultyNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal");
static const u8 gText_DifficultyHard[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Hard");
static const u8 gText_OverworldSpeed1x[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}1x");
static const u8 gText_OverworldSpeed2x[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}2x");
static const u8 gText_OverworldSpeed4x[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}4x");
static const u8 gText_OverworldSpeed8x[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}8x");

static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp");

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = COMPOUND_STRING("Text speed"),
    [MENUITEM_BATTLESCENE] = COMPOUND_STRING("Battle scene"),
    [MENUITEM_BATTLESTYLE] = COMPOUND_STRING("Battle style"),
    [MENUITEM_SOUND]       = COMPOUND_STRING("Sound"),
    [MENUITEM_BUTTONMODE]  = COMPOUND_STRING("Button mode"),
    [MENUITEM_FRAMETYPE]   = COMPOUND_STRING("Frame"),
    [MENUITEM_LEVELCAPS]       = COMPOUND_STRING("Level caps"),
    [MENUITEM_CANCEL]      = COMPOUND_STRING("Cancel"),
};

static const u8 *const sOptionMenuItemsNames_Pg2[MENUITEM_COUNT_PG2] =
{
    [MENUITEM_FOLLOWERS]        = gText_Followers,
    [MENUITEM_AUTORUN]         = COMPOUND_STRING("Autorun"),
    [MENUITEM_OVERWORLD_SPEEDUP] = COMPOUND_STRING("OW speed"),
    [MENUITEM_TRAINER_LEVEL_SCALING] = COMPOUND_STRING("Trainer scaling"),
    [MENUITEM_WILD_LEVEL_SCALING] = COMPOUND_STRING("Wild scaling"),
    [MENUITEM_DIFFICULTY] = COMPOUND_STRING("Difficulty"),
    [MENUITEM_CANCELPG2]      = COMPOUND_STRING("Cancel"),
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ReadAllCurrentSettings(u8 taskId)
{
        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tFollowers = gSaveBlock2Ptr->optionsFollowers;
        gTasks[taskId].tLevelCaps = gSaveBlock2Ptr->optionsLevelCaps;
        gTasks[taskId].tAutorun = gSaveBlock2Ptr->optionsAutorun;
        gTasks[taskId].tTrainerLevelScaling = gSaveBlock2Ptr->optionsTrainerLevelScaling;
        gTasks[taskId].tWildLevelScaling = gSaveBlock2Ptr->optionsWildLevelScaling;
        gTasks[taskId].tDifficulty = GetCurrentDifficultyLevel() == DIFFICULTY_HARD;
        gTasks[taskId].tOverworldSpeedup = VarGet(VAR_OVERWORLD_SPEEDUP);
}

static void DrawOptionsPg1(u8 taskId)
{
    ReadAllCurrentSettings(taskId);
    TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
    BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
    BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
    Sound_DrawChoices(gTasks[taskId].tSound);
    ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
    FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
    LevelCaps_DrawChoices(gTasks[taskId].tLevelCaps);
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawOptionsPg2(u8 taskId)
{
    ReadAllCurrentSettings(taskId);
    Followers_DrawChoices(gTasks[taskId].tFollowers);
    Autorun_DrawChoices(gTasks[taskId].tAutorun);
    OverworldSpeedup_DrawChoices(gTasks[taskId].tOverworldSpeedup);
    TrainerLevelScaling_DrawChoices(gTasks[taskId].tTrainerLevelScaling);
    WildLevelScaling_DrawChoices(gTasks[taskId].tWildLevelScaling);
    Difficulty_DrawChoices(gTasks[taskId].tDifficulty);
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

void CB2_InitOptionMenu(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        switch(sCurrPage)
        {
        case 0:
            taskId = CreateTask(Task_OptionMenuFadeIn, 0);
            DrawOptionsPg1(taskId);
            break;
        case 1:
            taskId = CreateTask(Task_OptionMenuFadeIn_Pg2, 0);
            DrawOptionsPg2(taskId);
            break;            
        }
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static u8 Process_ChangePage(u8 CurrentPage)
{
    if (JOY_NEW(R_BUTTON))
   {
       if (CurrentPage < PAGE_COUNT - 1)
           CurrentPage++;
       else
           CurrentPage = 0;
   }
   if (JOY_NEW(L_BUTTON))
   {
       if (CurrentPage != 0)
           CurrentPage--;
       else
           CurrentPage = PAGE_COUNT - 1;
   }
   return CurrentPage;
}

static void Task_ChangePage(u8 taskId)
{
    PutWindowTilemap(1);
    DrawTextOption();
    DrawOptionMenuTexts();
   switch(sCurrPage)
    {
    case 0:
        DrawOptionsPg1(taskId);
        gTasks[taskId].func = Task_OptionMenuFadeIn;
        break;
    case 1:
        DrawOptionsPg2(taskId);
        gTasks[taskId].func = Task_OptionMenuFadeIn_Pg2;
        break;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
   {
        gTasks[taskId].func = Task_OptionMenuSave; 
        FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
        ClearStdWindowAndFrame(WIN_OPTIONS, FALSE);
        sCurrPage = Process_ChangePage(sCurrPage);
        gTasks[taskId].func = Task_ChangePage;
   }
   else if (JOY_NEW(A_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_LEVELCAPS;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_LEVELCAPS)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);

            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
            break;
        case MENUITEM_BATTLESCENE:
            previousOption = gTasks[taskId].tBattleSceneOff;
            gTasks[taskId].tBattleSceneOff = BattleScene_ProcessInput(gTasks[taskId].tBattleSceneOff);

            if (previousOption != gTasks[taskId].tBattleSceneOff)
                BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
            break;
        case MENUITEM_BATTLESTYLE:
            previousOption = gTasks[taskId].tBattleStyle;
            gTasks[taskId].tBattleStyle = BattleStyle_ProcessInput(gTasks[taskId].tBattleStyle);

            if (previousOption != gTasks[taskId].tBattleStyle)
                BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
            break;
        case MENUITEM_SOUND:
            previousOption = gTasks[taskId].tSound;
            gTasks[taskId].tSound = Sound_ProcessInput(gTasks[taskId].tSound);

            if (previousOption != gTasks[taskId].tSound)
                Sound_DrawChoices(gTasks[taskId].tSound);
            break;
        case MENUITEM_BUTTONMODE:
            previousOption = gTasks[taskId].tButtonMode;
            gTasks[taskId].tButtonMode = ButtonMode_ProcessInput(gTasks[taskId].tButtonMode);

            if (previousOption != gTasks[taskId].tButtonMode)
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
            break;
        case MENUITEM_FRAMETYPE:
            previousOption = gTasks[taskId].tWindowFrameType;
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);

            if (previousOption != gTasks[taskId].tWindowFrameType)
                FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
            break;
        case MENUITEM_LEVELCAPS:
            previousOption = gTasks[taskId].tLevelCaps;
            gTasks[taskId].tLevelCaps = LevelCaps_ProcessInput(gTasks[taskId].tLevelCaps);

            if (previousOption != gTasks[taskId].tLevelCaps)
                LevelCaps_DrawChoices(gTasks[taskId].tLevelCaps);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}
static void Task_OptionMenuFadeIn_Pg2(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput_Pg2;
}

static void Task_OptionMenuProcessInput_Pg2(u8 taskId)
{
    if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
        FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
        ClearStdWindowAndFrame(WIN_OPTIONS, FALSE);
        sCurrPage = Process_ChangePage(sCurrPage);
        gTasks[taskId].func = Task_ChangePage;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_CANCELPG2;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCELPG2)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_FOLLOWERS:
            previousOption = gTasks[taskId].tFollowers;
            gTasks[taskId].tFollowers = Followers_ProcessInput(gTasks[taskId].tFollowers);

            if (previousOption != gTasks[taskId].tFollowers)
                Followers_DrawChoices(gTasks[taskId].tFollowers);
            break;
        case MENUITEM_AUTORUN:
            previousOption = gTasks[taskId].tAutorun;
            gTasks[taskId].tAutorun = Autorun_ProcessInput(gTasks[taskId].tAutorun);

            if (previousOption != gTasks[taskId].tAutorun)
                Autorun_DrawChoices(gTasks[taskId].tAutorun);
            break;
        case MENUITEM_OVERWORLD_SPEEDUP:
            previousOption = gTasks[taskId].tOverworldSpeedup;
            gTasks[taskId].tOverworldSpeedup = OverworldSpeedup_ProcessInput(gTasks[taskId].tOverworldSpeedup);

            if (previousOption != gTasks[taskId].tOverworldSpeedup)
                OverworldSpeedup_DrawChoices(gTasks[taskId].tOverworldSpeedup);
            break;
        case MENUITEM_TRAINER_LEVEL_SCALING:
            previousOption = gTasks[taskId].tTrainerLevelScaling;
            gTasks[taskId].tTrainerLevelScaling = LevelScaling_ProcessInput(gTasks[taskId].tTrainerLevelScaling);

            if (previousOption != gTasks[taskId].tTrainerLevelScaling)
                TrainerLevelScaling_DrawChoices(gTasks[taskId].tTrainerLevelScaling);
            break;
        case MENUITEM_WILD_LEVEL_SCALING:
            previousOption = gTasks[taskId].tWildLevelScaling;
            gTasks[taskId].tWildLevelScaling = LevelScaling_ProcessInput(gTasks[taskId].tWildLevelScaling);

            if (previousOption != gTasks[taskId].tWildLevelScaling)
                WildLevelScaling_DrawChoices(gTasks[taskId].tWildLevelScaling);
            break;
        case MENUITEM_DIFFICULTY:
            previousOption = gTasks[taskId].tDifficulty;
            gTasks[taskId].tDifficulty = Difficulty_ProcessInput(gTasks[taskId].tDifficulty);

            if (previousOption != gTasks[taskId].tDifficulty)
                Difficulty_DrawChoices(gTasks[taskId].tDifficulty);
            break;
        default:
            return;
        }
        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}


static void DrawTextOption(void)
{
u32 i, widthOptions, xMid;
u8 pageDots[9] = _("");  // Array size should be at least (2 * PAGE_COUNT) -1
widthOptions = GetStringWidth(FONT_NORMAL, gText_Option, 0);

for (i = 0; i < PAGE_COUNT; i++)
{
    if (i == sCurrPage)
        StringAppend(pageDots, gText_LargeDot);
    else
        StringAppend(pageDots, gText_SmallDot);
    if (i < PAGE_COUNT - 1)
        StringAppend(pageDots, gText_Space);            
}
xMid = (8 + widthOptions + 5);
FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, pageDots, xMid, 1, TEXT_SKIP_DRAW, NULL);
AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_PageNav, GetStringRightAlignXOffset(FONT_NORMAL, gText_PageNav, 198), 1, TEXT_SKIP_DRAW, NULL);
CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
    gSaveBlock2Ptr->optionsBattleSceneOff = gTasks[taskId].tBattleSceneOff;
    gSaveBlock2Ptr->optionsBattleStyle = gTasks[taskId].tBattleStyle;
    gSaveBlock2Ptr->optionsSound = gTasks[taskId].tSound;
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
    gSaveBlock2Ptr->optionsFollowers = gTasks[taskId].tFollowers;
    gSaveBlock2Ptr->optionsLevelCaps = gTasks[taskId].tLevelCaps;
    gSaveBlock2Ptr->optionsAutorun = gTasks[taskId].tAutorun;
    gSaveBlock2Ptr->optionsTrainerLevelScaling = gTasks[taskId].tTrainerLevelScaling;
    gSaveBlock2Ptr->optionsWildLevelScaling = gTasks[taskId].tWildLevelScaling;
    SetCurrentDifficultyLevel(gTasks[taskId].tDifficulty ? DIFFICULTY_HARD : DIFFICULTY_NORMAL);
    VarSet(VAR_OVERWORLD_SPEEDUP, gTasks[taskId].tOverworldSpeedup);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(u8 index)
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, DISPLAY_WIDTH - 16));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(index * 16 + 40, index * 16 + 56));
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x, y + 1, TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection)
{
    u8 styles[3];
    s32 widthSlow, widthMid, widthFast, xMid;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, YPOS_TEXTSPEED, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);

    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, YPOS_TEXTSPEED, styles[1]);

    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), YPOS_TEXTSPEED, styles[2]);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, YPOS_BATTLESCENE, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), YPOS_BATTLESCENE, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, YPOS_BATTLESTYLE, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), YPOS_BATTLESTYLE, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, YPOS_SOUND, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), YPOS_SOUND, styles[1]);
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection)
{
    u8 text[16] = {EOS};
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACER;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, YPOS_FRAMETYPE, 0);
    DrawOptionMenuChoice(text, 128, YPOS_FRAMETYPE, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3];

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, YPOS_BUTTONMODE, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);

    widthLR -= 94;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 104;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, YPOS_BUTTONMODE, styles[1]);

    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), YPOS_BUTTONMODE, styles[2]);
}


static u8 Followers_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}


static void Followers_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    
    DrawOptionMenuChoice(gText_BattleSceneOn, 104, YPOS_FOLLOWERS, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), YPOS_FOLLOWERS, styles[1]);
}

static u8 Autorun_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Autorun_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AutorunOn, 104, YPOS_AUTORUN, styles[0]);
    DrawOptionMenuChoice(gText_AutorunOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_AutorunOff, 198), YPOS_AUTORUN, styles[1]);
}

static u8 OverworldSpeedup_ProcessInput(u8 selection)
{
    if (selection > OPTIONS_OVERWORLD_SPEED_8X)
        selection = OPTIONS_OVERWORLD_SPEED_1X;

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < OPTIONS_OVERWORLD_SPEED_8X)
            selection++;
        else
            selection = OPTIONS_OVERWORLD_SPEED_1X;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection > OPTIONS_OVERWORLD_SPEED_1X)
            selection--;
        else
            selection = OPTIONS_OVERWORLD_SPEED_8X;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void OverworldSpeedup_DrawChoices(u8 selection)
{
    u8 styles[4];

    if (selection > OPTIONS_OVERWORLD_SPEED_8X)
        selection = OPTIONS_OVERWORLD_SPEED_1X;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[3] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_OverworldSpeed1x, 88, YPOS_OVERWORLD_SPEEDUP, styles[OPTIONS_OVERWORLD_SPEED_1X]);
    DrawOptionMenuChoice(gText_OverworldSpeed2x, 122, YPOS_OVERWORLD_SPEEDUP, styles[OPTIONS_OVERWORLD_SPEED_2X]);
    DrawOptionMenuChoice(gText_OverworldSpeed4x, 156, YPOS_OVERWORLD_SPEEDUP, styles[OPTIONS_OVERWORLD_SPEED_4X]);
    DrawOptionMenuChoice(gText_OverworldSpeed8x, GetStringRightAlignXOffset(FONT_NORMAL, gText_OverworldSpeed8x, 198), YPOS_OVERWORLD_SPEEDUP, styles[OPTIONS_OVERWORLD_SPEED_8X]);
}

static u8 LevelCaps_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void LevelCaps_DrawChoices(u8 selection)
{
    s32 widthNoCaps, widthSoftCaps, widthHardCaps, xHardCaps;
    u8 styles[3];

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_NoCaps, 92, YPOS_LEVELCAPS, styles[0]);

    widthNoCaps = GetStringWidth(FONT_NORMAL, gText_NoCaps, 0);
    widthSoftCaps = GetStringWidth(FONT_NORMAL, gText_SoftCaps, 0);
    widthHardCaps = GetStringWidth(FONT_NORMAL, gText_HardCaps, 0);

    widthHardCaps -= 94;
    xHardCaps = (widthNoCaps - widthHardCaps - widthSoftCaps) / 2 + 100;
    DrawOptionMenuChoice(gText_SoftCaps, xHardCaps, YPOS_LEVELCAPS, styles[1]);

    DrawOptionMenuChoice(gText_HardCaps, GetStringRightAlignXOffset(FONT_NORMAL, gText_HardCaps, 198), YPOS_LEVELCAPS, styles[2]);
}

static u8 LevelScaling_ProcessInput(u8 selection)
{
    if (selection > LEVEL_SCALING_OPTION_ON)
        selection = LEVEL_SCALING_OPTION_OFF;

    if (JOY_NEW(DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }
    return selection;
}

static void LevelScaling_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2];

    if (selection > LEVEL_SCALING_OPTION_ON)
        selection = LEVEL_SCALING_OPTION_OFF;

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ScalingOn, 104, y, styles[LEVEL_SCALING_OPTION_ON]);
    DrawOptionMenuChoice(gText_ScalingOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_ScalingOff, 198), y, styles[LEVEL_SCALING_OPTION_OFF]);
}

static void TrainerLevelScaling_DrawChoices(u8 selection)
{
    LevelScaling_DrawChoices(selection, YPOS_TRAINER_LEVEL_SCALING);
}

static void WildLevelScaling_DrawChoices(u8 selection)
{
    LevelScaling_DrawChoices(selection, YPOS_WILD_LEVEL_SCALING);
}

static u8 Difficulty_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Difficulty_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_DifficultyNormal, 104, YPOS_DIFFICULTY, styles[0]);
    DrawOptionMenuChoice(gText_DifficultyHard, GetStringRightAlignXOffset(FONT_NORMAL, gText_DifficultyHard, 198), YPOS_DIFFICULTY, styles[1]);
}

static void DrawHeaderText(void)
{
    u32 i, widthOptions, xMid;
    u8 pageDots[9] = _("");  // Array size should be at least (2 * PAGE_COUNT) -1
    widthOptions = GetStringWidth(FONT_NORMAL, gText_Option, 0);

    for (i = 0; i < PAGE_COUNT; i++)
    {
        if (i == sCurrPage)
            StringAppend(pageDots, gText_LargeDot);
        else
            StringAppend(pageDots, gText_SmallDot);
        if (i < PAGE_COUNT - 1)
            StringAppend(pageDots, gText_Space);            
    }
    xMid = (8 + widthOptions + 5);
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, pageDots, xMid, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_PageNav, GetStringRightAlignXOffset(FONT_NORMAL, gText_PageNav, 198), 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void)
{
    u8 i;
    u8 items = NULL;
    const u8* const* menu = NULL;

    switch (sCurrPage){
    case 0:
        items = MENUITEM_COUNT;
        menu = sOptionMenuItemsNames;
        break;
    case 1:
        items = MENUITEM_COUNT_PG2;
        menu = sOptionMenuItemsNames_Pg2;
        break;    
    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < items; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, menu[i], 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}
#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Draw title window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    // Draw options list window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
