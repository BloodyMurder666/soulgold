#include "global.h"
#include "battle_pyramid.h"
#include "coins.h"
#include "comfy_anim.h"
#include "gpu_regs.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"
#include "field_message_box.h"
#include "text_window.h"
#include "script.h"
#include "script_menu.h"
#include "field_name_box.h"
#include "field_mugshot.h"
#include "sprite.h"

static EWRAM_DATA u8 sFieldMessageBoxMode = 0;
static EWRAM_DATA bool8 sFieldMessageBoxVisible = FALSE;
EWRAM_DATA u8 gWalkAwayFromSignpostTimer = 0;

static void ExpandStringAndStartDrawFieldMessage(const u8 *, bool32);
static void StartDrawFieldMessage(void);
static void RestoreFieldMessageSlide(struct Task *task);
static void FinishFieldMessageBoxClose(void);

void InitFieldMessageBox(void)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
    sFieldMessageBoxVisible = FALSE;
    gTextFlags.canABSpeedUpPrint = FALSE;
    gTextFlags.useAlternateDownArrow = FALSE;
    gTextFlags.autoScroll = FALSE;
    gTextFlags.forceMidTextSpeed = FALSE;
}

#define FIELD_MESSAGE_SLIDE_IN_DURATION    12
#define FIELD_MESSAGE_SLIDE_OUT_DURATION   6
#define FIELD_MESSAGE_SLIDE_DISTANCE       48
#define FIELD_MESSAGE_NAME_SLIDE_DISTANCE  56
#define FIELD_MESSAGE_TOP                  112
#define FIELD_MESSAGE_NAME_TOP             104

#define tState              data[0]
#define tSlideAnimId        data[1]
#define tSavedBg0Vofs       data[2]
#define tSavedDispCnt       data[3]
#define tSavedWin0H         data[4]
#define tSavedWin0V         data[5]
#define tSavedWinIn         data[6]
#define tSavedWinOut        data[7]
#define tSlidePrepared      data[8]
#define tSlideTop           data[9]
#define tMugshotSpriteId    data[10]
#define tMugshotBaseY2      data[11]

static bool32 CanAnimateFieldMessage(void)
{
    return GetFlashLevel() == 0
        && !InBattlePyramid_()
        && !gSaveBlock2Ptr->optionsUiAnimationsOff
        && !IsMoneyBoxActive()
        && !IsCoinsWindowActive()
        && !ScriptMenu_IsPokemonPicActive();
}

static void SetFieldMessageSlideOffset(struct Task *task, s16 offset)
{
    s16 top = task->tSlideTop + offset;

    if (top > DISPLAY_HEIGHT)
        top = DISPLAY_HEIGHT;

    SetGpuReg(REG_OFFSET_BG0VOFS, task->tSavedBg0Vofs - offset);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(top, DISPLAY_HEIGHT));

    if (task->tMugshotSpriteId != SPRITE_NONE
     && IsFieldMugshotActive()
     && GetFieldMugshotSpriteId() == task->tMugshotSpriteId)
        gSprites[task->tMugshotSpriteId].y2 = task->tMugshotBaseY2 + offset;
}

static void PrepareFieldMessageSlide(struct Task *task, s16 distance)
{
    task->tSavedBg0Vofs = GetGpuReg(REG_OFFSET_BG0VOFS);
    task->tSavedDispCnt = GetGpuReg(REG_OFFSET_DISPCNT);
    task->tSavedWin0H = GetGpuReg(REG_OFFSET_WIN0H);
    task->tSavedWin0V = GetGpuReg(REG_OFFSET_WIN0V);
    task->tSavedWinIn = GetGpuReg(REG_OFFSET_WININ);
    task->tSavedWinOut = GetGpuReg(REG_OFFSET_WINOUT);
    task->tSlidePrepared = TRUE;
    task->tMugshotSpriteId = SPRITE_NONE;
    if (IsFieldMugshotActive())
    {
        task->tMugshotSpriteId = GetFieldMugshotSpriteId();
        task->tMugshotBaseY2 = gSprites[task->tMugshotSpriteId].y2;
    }

    // BG0 wraps vertically when scrolled. Clip it to the visible portion of
    // the message box so the offscreen edge cannot wrap onto the top.
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WININ, (task->tSavedWinIn & ~WININ_WIN0_ALL) | WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, (task->tSavedWinOut | WINOUT_WIN01_ALL) & ~WINOUT_WIN01_BG0);
    SetFieldMessageSlideOffset(task, distance);
}

static void StartFieldMessageSlide(struct Task *task, bool32 hasNamebox)
{
    struct ComfyAnimEasingConfig config;
    s16 distance = hasNamebox ? FIELD_MESSAGE_NAME_SLIDE_DISTANCE : FIELD_MESSAGE_SLIDE_DISTANCE;

    task->tSlideTop = hasNamebox ? FIELD_MESSAGE_NAME_TOP : FIELD_MESSAGE_TOP;
    PrepareFieldMessageSlide(task, distance);

    InitComfyAnimConfig_Easing(&config);
    config.durationFrames = FIELD_MESSAGE_SLIDE_IN_DURATION;
    config.from = Q_24_8(distance);
    config.to = Q_24_8(0);
    config.easingFunc = ComfyAnimEasing_EaseOutCubic;
    task->tSlideAnimId = CreateComfyAnim_Easing(&config);
}

static bool32 AdvanceFieldMessageSlide(struct Task *task)
{
    if (task->tSlideAnimId != INVALID_COMFY_ANIM)
    {
        struct ComfyAnim *anim = &gComfyAnims[task->tSlideAnimId];

        if (anim->inUse)
        {
            TryAdvanceComfyAnim(anim);
            SetFieldMessageSlideOffset(task, ReadComfyAnimValueSmooth(anim));
            if (!anim->completed)
                return FALSE;
        }
    }

    return TRUE;
}

static bool32 UpdateFieldMessageSlide(struct Task *task)
{
    if (!AdvanceFieldMessageSlide(task))
        return FALSE;

    RestoreFieldMessageSlide(task);
    return TRUE;
}

static void RestoreFieldMessageSlide(struct Task *task)
{
    if (task->tSlideAnimId != INVALID_COMFY_ANIM)
        ReleaseComfyAnim(task->tSlideAnimId);
    task->tSlideAnimId = INVALID_COMFY_ANIM;

    if (!task->tSlidePrepared)
        return;

    if (task->tMugshotSpriteId != SPRITE_NONE
     && IsFieldMugshotActive()
     && GetFieldMugshotSpriteId() == task->tMugshotSpriteId)
        gSprites[task->tMugshotSpriteId].y2 = task->tMugshotBaseY2;

    SetGpuReg(REG_OFFSET_BG0VOFS, task->tSavedBg0Vofs);
    SetGpuReg(REG_OFFSET_WIN0H, task->tSavedWin0H);
    SetGpuReg(REG_OFFSET_WIN0V, task->tSavedWin0V);
    SetGpuReg(REG_OFFSET_WININ, task->tSavedWinIn);
    SetGpuReg(REG_OFFSET_WINOUT, task->tSavedWinOut);
    SetGpuReg(REG_OFFSET_DISPCNT, task->tSavedDispCnt);
    task->tSlidePrepared = FALSE;
}

static void Task_DrawFieldMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        if (gMsgIsSignPost)
            LoadSignPostWindowFrameGfx();
        else
            LoadMessageBoxAndBorderGfx();
        task->tState++;
        break;
    case 1:
    {
        bool32 boxWasVisible = sFieldMessageBoxVisible;
        u32 nameboxWinId = GetNameboxWindowId();
        DrawDialogueFrame(0, TRUE);
        if (nameboxWinId != WINDOW_NONE)
            DrawNamebox(nameboxWinId, NAME_BOX_BASE_TILE_NUM - NAME_BOX_BASE_TILES_TOTAL, TRUE);
        sFieldMessageBoxVisible = TRUE;

        if (!boxWasVisible && CanAnimateFieldMessage())
            StartFieldMessageSlide(task, nameboxWinId != WINDOW_NONE);
        if (IsFieldMugshotActive())
            gSprites[GetFieldMugshotSpriteId()].data[0] = TRUE;
        task->tState++;
        break;
    }
    case 2:
        if (task->tSlidePrepared && !UpdateFieldMessageSlide(task))
            break;
        task->tState++;
        break;
    case 3:
        if (RunTextPrintersAndIsPrinter0Active() != TRUE)
        {
            sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
            DestroyTask(taskId);
        }
    }
}

static void Task_AnimateFieldMessageSlideOut(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        if (!AdvanceFieldMessageSlide(task))
            return;

        if (task->tSlideAnimId != INVALID_COMFY_ANIM)
            ReleaseComfyAnim(task->tSlideAnimId);
        task->tSlideAnimId = INVALID_COMFY_ANIM;

        // Keep BG0 offscreen until the cleared window tilemap has reached
        // VRAM. Restoring it in this frame briefly reveals the old box.
        FinishFieldMessageBoxClose();
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_UNUSED;
        task->tState++;
        break;
    case 1:
        RestoreFieldMessageSlide(task);
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
        break;
    }
}

static bool32 StartFieldMessageSlideOut(void)
{
    struct ComfyAnimEasingConfig config;
    bool32 hasNamebox = GetNameboxWindowId() != WINDOW_NONE;
    s16 distance = hasNamebox ? FIELD_MESSAGE_NAME_SLIDE_DISTANCE : FIELD_MESSAGE_SLIDE_DISTANCE;
    u8 taskId = CreateTask(Task_AnimateFieldMessageSlideOut, 0x50);
    struct Task *task;

    if (taskId == TASK_NONE)
        return FALSE;

    task = &gTasks[taskId];
    task->tSlideAnimId = INVALID_COMFY_ANIM;
    task->tSlideTop = hasNamebox ? FIELD_MESSAGE_NAME_TOP : FIELD_MESSAGE_TOP;
    PrepareFieldMessageSlide(task, 0);

    InitComfyAnimConfig_Easing(&config);
    config.durationFrames = FIELD_MESSAGE_SLIDE_OUT_DURATION;
    config.from = Q_24_8(0);
    config.to = Q_24_8(distance);
    config.easingFunc = ComfyAnimEasing_EaseInCubic;
    task->tSlideAnimId = CreateComfyAnim_Easing(&config);
    if (task->tSlideAnimId == INVALID_COMFY_ANIM)
    {
        RestoreFieldMessageSlide(task);
        DestroyTask(taskId);
        return FALSE;
    }

    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_UNUSED;
    return TRUE;
}

static void CreateTask_DrawFieldMessage(void)
{
    u8 taskId = CreateTask(Task_DrawFieldMessage, 0x50);

    if (taskId != TASK_NONE)
        gTasks[taskId].tSlideAnimId = INVALID_COMFY_ANIM;
}

static void DestroyTask_DrawFieldMessage(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawFieldMessage);
    if (taskId != TASK_NONE)
    {
        RestoreFieldMessageSlide(&gTasks[taskId]);
        DestroyTask(taskId);
    }
}

static void DestroyTask_FieldMessageSlideOut(void)
{
    u8 taskId = FindTaskIdByFunc(Task_AnimateFieldMessageSlideOut);

    if (taskId != TASK_NONE)
    {
        RestoreFieldMessageSlide(&gTasks[taskId]);
        DestroyTask(taskId);
    }
}

#undef tState
#undef tSlideAnimId
#undef tSavedBg0Vofs
#undef tSavedDispCnt
#undef tSavedWin0H
#undef tSavedWin0V
#undef tSavedWinIn
#undef tSavedWinOut
#undef tSlidePrepared
#undef tSlideTop
#undef tMugshotSpriteId
#undef tMugshotBaseY2

static void FinishFieldMessageBoxClose(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
    DestroyNamebox();
    sFieldMessageBoxVisible = FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
    if (IsFieldMugshotActive())
    {
        gSprites[GetFieldMugshotSpriteId()].data[0] = FALSE;
        RemoveFieldMugshot();
    }
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    TryCreateFieldMugshotFromObjectEventSource();
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

static void Task_HidePokenavMessageWhenDone(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 ShowPokenavFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    RemoveFieldMugshot();
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(Task_HidePokenavMessageWhenDone, 0);
    StartMatchCallFromScript(str);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    TryCreateFieldMugshotFromObjectEventSource();
    ExpandStringAndStartDrawFieldMessage(str, FALSE);
    return TRUE;
}

static bool8 UNUSED ForceShowFieldAutoScrollMessage(const u8 *str)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    return TRUE;
}

// Same as ShowFieldMessage, but instead of accepting a
// string arg it just prints whats already in gStringVar4
bool8 ShowFieldMessageFromBuffer(void)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    TryCreateFieldMugshotFromObjectEventSource();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    StartDrawFieldMessage();
    return TRUE;
}

static void ExpandStringAndStartDrawFieldMessage(const u8 *str, bool32 allowSkippingDelayWithButtonPress)
{
    TrySpawnNamebox(NAME_BOX_BASE_TILE_NUM);
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    CreateTask_DrawFieldMessage();
    if (!sFieldMessageBoxVisible && IsFieldMugshotActive())
        gSprites[GetFieldMugshotSpriteId()].data[0] = FALSE;
}

static void StartDrawFieldMessage(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessage();
    if (!sFieldMessageBoxVisible && IsFieldMugshotActive())
        gSprites[GetFieldMugshotSpriteId()].data[0] = FALSE;
}

void HideFieldMessageBox(void)
{
    if (FindTaskIdByFunc(Task_AnimateFieldMessageSlideOut) != TASK_NONE)
        return;

    DestroyTask_DrawFieldMessage();
    if (sFieldMessageBoxVisible && CanAnimateFieldMessage() && StartFieldMessageSlideOut())
        return;

    FinishFieldMessageBoxClose();
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageBoxMode == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    return FALSE;
}

static void UNUSED ReplaceFieldMessageWithFrame(void)
{
    DestroyTask_DrawFieldMessage();
    DrawStdWindowFrame(0, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

void StopFieldMessage(void)
{
    DestroyTask_DrawFieldMessage();
    DestroyTask_FieldMessageSlideOut();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}
