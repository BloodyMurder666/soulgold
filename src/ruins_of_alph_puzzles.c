#include "global.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "ruins_of_alph_puzzles.h"
#include "script.h"
#include "task.h"

extern const u8 RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseEscapeRopeOpenKabuto[];
extern const u8 RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseWaterStoneOpenArchen[];
extern const u8 RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseFlashOpenAerodactyl[];

static bool8 IsInPuzzleAndRewardChambers(void)
{
    return gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUINS_OF_ALPH_PUZZLE_AND_REWARD_CHAMBERS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_RUINS_OF_ALPH_PUZZLE_AND_REWARD_CHAMBERS);
}

static bool8 IsFacingNorthAtRearWall(u16 x1, u16 x2, u16 y)
{
    if (GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;
    if (gSaveBlock1Ptr->pos.y != y)
        return FALSE;
    return gSaveBlock1Ptr->pos.x == x1 || gSaveBlock1Ptr->pos.x == x2;
}

bool8 ShouldDoRuinsOfAlphEscapeRopePuzzle(void)
{
    return IsInPuzzleAndRewardChambers()
        && !FlagGet(FLAG_KABUTO_BROUGHT)
        && IsFacingNorthAtRearWall(20, 21, 2);
}

bool8 ShouldDoRuinsOfAlphWaterStonePuzzle(void)
{
    return IsInPuzzleAndRewardChambers()
        && !FlagGet(FLAG_ARCHEN_BROUGHT)
        && IsFacingNorthAtRearWall(4, 5, 19);
}

bool8 ShouldDoRuinsOfAlphFlashPuzzle(void)
{
    return IsInPuzzleAndRewardChambers()
        && !FlagGet(FLAG_AERODACTYL_BROUGHT)
        && IsFacingNorthAtRearWall(20, 21, 19);
}

void StartRuinsOfAlphEscapeRopePuzzle(u8 taskId)
{
    LockPlayerFieldControls();
    ScriptContext_SetupScript(RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseEscapeRopeOpenKabuto);
    DestroyTask(taskId);
}

void StartRuinsOfAlphWaterStonePuzzle(u8 taskId)
{
    LockPlayerFieldControls();
    ScriptContext_SetupScript(RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseWaterStoneOpenArchen);
    DestroyTask(taskId);
}

void SetUpRuinsOfAlphFlashPuzzle(void)
{
    ScriptContext_SetupScript(RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseFlashOpenAerodactyl);
}
