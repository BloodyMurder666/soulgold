#include "global.h"
#include "achievements.h"
#include "bg.h"
#include "comfy_anim.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "item_icon.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"

#define tState data[0]
#define tTimer data[1]
#define tWindowId data[2]
#define tAchievementId data[3]
#define tSpriteId data[4]
#define tAnimId data[5]
#define tYOffset data[6]
#define ACHIEVEMENT_POPUP_ICON_TAG 0xACE0
#define ACHIEVEMENT_POPUP_WINDOW_WIDTH 15
#define ACHIEVEMENT_POPUP_ICON_X 131
#define ACHIEVEMENT_POPUP_ICON_Y 32
#define ACHIEVEMENT_POPUP_OFFSCREEN_Y 48
#define ACHIEVEMENT_POPUP_SLIDE_DURATION 18

static void Task_AchievementPopup(u8 taskId);
static u8 GetAchievementPopupTaskId(void);
static bool32 IsAchievementPopupActive(void);
static enum AchievementId PopQueuedAchievement(void);
static void StartAchievementPopupSlide(u8 taskId, s16 from, s16 to, u16 duration, ComfyAnimEasingFunc easingFunc);
static bool8 UpdateAchievementPopupSlide(u8 taskId);
static void SetAchievementPopupOffset(u8 taskId, s16 yOffset);
static void DestroyAchievementPopup(u8 taskId);
static bool8 ShouldYieldAchievementPopup(void);

enum
{
    POPUP_STATE_INIT,
    POPUP_STATE_SLIDE_IN,
    POPUP_STATE_WAIT,
    POPUP_STATE_SLIDE_OUT,
};

static const struct WindowTemplate sPopupWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 14,
    .tilemapTop = 1,
    .width = ACHIEVEMENT_POPUP_WINDOW_WIDTH,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x240,
};

static const union AffineAnimCmd sAffineAnim_PopupIconSmall[] =
{
    AFFINEANIMCMD_FRAME(206, 206, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_PopupIcon[] =
{
    sAffineAnim_PopupIconSmall,
};

static u8 GetAchievementPopupTaskId(void)
{
    return FindTaskIdByFunc(Task_AchievementPopup);
}

static bool32 IsAchievementPopupActive(void)
{
    return GetAchievementPopupTaskId() != TASK_NONE;
}

static enum AchievementId PopQueuedAchievement(void)
{
    u8 i;
    enum AchievementId id = gSaveBlock1Ptr->achievements.popupQueue[0] - 1;

    for (i = 1; i < ACHIEVEMENT_POPUP_QUEUE_SIZE; i++)
        gSaveBlock1Ptr->achievements.popupQueue[i - 1] = gSaveBlock1Ptr->achievements.popupQueue[i];
    gSaveBlock1Ptr->achievements.popupQueue[ACHIEVEMENT_POPUP_QUEUE_SIZE - 1] = 0;
    return id;
}

void Achievement_TryShowQueuedPopup(void)
{
    u8 taskId;
    enum AchievementId id;

    Achievement_EnsureSaveInitialized();
    if (gSaveBlock1Ptr->achievements.popupQueue[0] == 0
     || IsAchievementPopupActive()
     || IsMapNamePopUpWindowActive()
     || GetStartMenuWindowId() != WINDOW_NONE
     || IsOverworldLinkActive()
     || gPaletteFade.active
     || ScriptContext_IsEnabled()
     || ArePlayerFieldControlsLocked()
     || gMain.callback2 != CB2_Overworld)
        return;

    id = PopQueuedAchievement();
    if (Achievement_GetById(id) == NULL)
        return;
    taskId = CreateTask(Task_AchievementPopup, 0);
    gTasks[taskId].tWindowId = WINDOW_NONE;
    gTasks[taskId].tSpriteId = MAX_SPRITES;
    gTasks[taskId].tAnimId = INVALID_COMFY_ANIM;
    gTasks[taskId].tAchievementId = id;
}

void Achievement_HidePopup(void)
{
    u8 taskId = GetAchievementPopupTaskId();

    if (taskId != TASK_NONE)
        DestroyAchievementPopup(taskId);
}

static void DrawAchievementPopup(u8 windowId, enum AchievementId id)
{
    const struct Achievement *achievement = Achievement_GetById(id);
    u8 countX;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    DrawStdWindowFrame(windowId, FALSE);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, COMPOUND_STRING("ACHIEVEMENT!"), 8, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, achievement->name, 38, 15, TEXT_SKIP_DRAW, NULL);

    ConvertIntToDecimalStringN(gStringVar1, Achievement_CountUnlocked(), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, Achievement_GetCount(), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("{STR_VAR_1}/{STR_VAR_2}"));
    countX = ACHIEVEMENT_POPUP_WINDOW_WIDTH * 8 - 8 - GetStringWidth(FONT_SMALL, gStringVar4, 0);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gStringVar4, countX, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Task_AchievementPopup(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->tState != POPUP_STATE_INIT && ShouldYieldAchievementPopup())
    {
        DestroyAchievementPopup(taskId);
        return;
    }

    switch (task->tState)
    {
    case POPUP_STATE_INIT:
        task->tWindowId = AddWindow(&sPopupWindowTemplate);
        if (task->tWindowId == WINDOW_NONE)
        {
            DestroyTask(taskId);
            return;
        }
        SetAchievementPopupOffset(taskId, ACHIEVEMENT_POPUP_OFFSCREEN_Y);
        PutWindowTilemap(task->tWindowId);
        DrawAchievementPopup(task->tWindowId, task->tAchievementId);
        PlaySE(SE_M_HARDEN);
        task->tSpriteId = AddItemIconSprite(ACHIEVEMENT_POPUP_ICON_TAG, ACHIEVEMENT_POPUP_ICON_TAG, Achievement_GetTierBallItem(Achievement_GetById(task->tAchievementId)->tier));
        if (task->tSpriteId != MAX_SPRITES)
        {
            gSprites[task->tSpriteId].x = ACHIEVEMENT_POPUP_ICON_X;
            gSprites[task->tSpriteId].y = ACHIEVEMENT_POPUP_ICON_Y - ACHIEVEMENT_POPUP_OFFSCREEN_Y;
            gSprites[task->tSpriteId].oam.priority = 0;
            gSprites[task->tSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[task->tSpriteId].affineAnims = sAffineAnims_PopupIcon;
            InitSpriteAffineAnim(&gSprites[task->tSpriteId]);
            StartSpriteAffineAnim(&gSprites[task->tSpriteId], 0);
        }
        StartAchievementPopupSlide(taskId, ACHIEVEMENT_POPUP_OFFSCREEN_Y, 0, ACHIEVEMENT_POPUP_SLIDE_DURATION, ComfyAnimEasing_EaseOutCubic);
        task->tState = POPUP_STATE_SLIDE_IN;
        break;
    case POPUP_STATE_SLIDE_IN:
        if (UpdateAchievementPopupSlide(taskId))
        {
            task->tTimer = 0;
            task->tState = POPUP_STATE_WAIT;
        }
        break;
    case POPUP_STATE_WAIT:
        if (++task->tTimer > 150 || JOY_NEW(A_BUTTON | B_BUTTON))
        {
            StartAchievementPopupSlide(taskId, task->tYOffset, ACHIEVEMENT_POPUP_OFFSCREEN_Y, ACHIEVEMENT_POPUP_SLIDE_DURATION, ComfyAnimEasing_EaseInCubic);
            task->tState = POPUP_STATE_SLIDE_OUT;
        }
        break;
    case POPUP_STATE_SLIDE_OUT:
        if (UpdateAchievementPopupSlide(taskId))
            DestroyAchievementPopup(taskId);
        break;
    }
}

static void StartAchievementPopupSlide(u8 taskId, s16 from, s16 to, u16 duration, ComfyAnimEasingFunc easingFunc)
{
    struct ComfyAnimEasingConfig config;
    struct Task *task = &gTasks[taskId];

    if (task->tAnimId != INVALID_COMFY_ANIM)
        ReleaseComfyAnim(task->tAnimId);

    SetAchievementPopupOffset(taskId, from);
    InitComfyAnimConfig_Easing(&config);
    config.durationFrames = duration;
    config.easingFunc = easingFunc;
    config.from = Q_24_8(from);
    config.to = Q_24_8(to);
    task->tAnimId = CreateComfyAnim_Easing(&config);
    if (task->tAnimId == INVALID_COMFY_ANIM)
        SetAchievementPopupOffset(taskId, to);
}

static bool8 UpdateAchievementPopupSlide(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ComfyAnim *anim;

    if (task->tAnimId == INVALID_COMFY_ANIM)
        return TRUE;

    anim = &gComfyAnims[task->tAnimId];
    if (!anim->inUse)
    {
        task->tAnimId = INVALID_COMFY_ANIM;
        return TRUE;
    }

    TryAdvanceComfyAnim(anim);
    SetAchievementPopupOffset(taskId, ReadComfyAnimValueSmooth(anim));
    if (!anim->completed)
        return FALSE;

    ReleaseComfyAnim(task->tAnimId);
    task->tAnimId = INVALID_COMFY_ANIM;
    return TRUE;
}

static void SetAchievementPopupOffset(u8 taskId, s16 yOffset)
{
    struct Task *task = &gTasks[taskId];

    task->tYOffset = yOffset;
    SetGpuReg(REG_OFFSET_BG0VOFS, yOffset);
    if (task->tSpriteId != MAX_SPRITES)
        gSprites[task->tSpriteId].y = ACHIEVEMENT_POPUP_ICON_Y - yOffset;
}

static void DestroyAchievementPopup(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->tAnimId != INVALID_COMFY_ANIM)
    {
        ReleaseComfyAnim(task->tAnimId);
        task->tAnimId = INVALID_COMFY_ANIM;
    }
    if (task->tSpriteId != MAX_SPRITES)
    {
        FreeSpriteTilesByTag(ACHIEVEMENT_POPUP_ICON_TAG);
        FreeSpritePaletteByTag(ACHIEVEMENT_POPUP_ICON_TAG);
        FreeSpriteOamMatrix(&gSprites[task->tSpriteId]);
        DestroySprite(&gSprites[task->tSpriteId]);
        task->tSpriteId = MAX_SPRITES;
    }
    if (task->tWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrame(task->tWindowId, TRUE);
        RemoveWindow(task->tWindowId);
        task->tWindowId = WINDOW_NONE;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DestroyTask(taskId);
}

static bool8 ShouldYieldAchievementPopup(void)
{
    return gMain.callback2 != CB2_Overworld
        || IsMapNamePopUpWindowActive()
        || GetStartMenuWindowId() != WINDOW_NONE
        || ScriptContext_IsEnabled()
        || ArePlayerFieldControlsLocked();
}

#undef tState
#undef tTimer
#undef tWindowId
#undef tAchievementId
#undef tSpriteId
#undef tAnimId
#undef tYOffset
#undef ACHIEVEMENT_POPUP_ICON_TAG
#undef ACHIEVEMENT_POPUP_WINDOW_WIDTH
#undef ACHIEVEMENT_POPUP_ICON_X
#undef ACHIEVEMENT_POPUP_ICON_Y
#undef ACHIEVEMENT_POPUP_OFFSCREEN_Y
#undef ACHIEVEMENT_POPUP_SLIDE_DURATION
