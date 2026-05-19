#ifndef GUARD_BATTLE_ARCADE_H
#define GUARD_BATTLE_ARCADE_H

void CallBattleArcadeFunc(void);
void ConvertFacilityFromArcadeToPike(s32 *);
u32 GetArcadePrintCount();

struct GameResult
{
    u8 impact:2;
    u8 event:5;
};

#define FRONTIER_SAVEDATA                       gSaveBlock2Ptr->frontier
#define ARCADE_SAVEDATA_CURRENT_STREAK          FRONTIER_SAVEDATA.arcadeWinStreaks
#define ARCADE_SAVEDATA_RECORD_STREAK           FRONTIER_SAVEDATA.arcadeRecordWinStreaks
#define ARCADE_SAVEDATA_CURSOR                  FRONTIER_SAVEDATA.gameCursor

#define VAR_ARCADE_BERRY                        VAR_0x410F
#define VAR_ARCADE_ITEM                         VAR_0x4110
#define VAR_ARCADE_PERFORMANCE_POINTS           VAR_0x4111

#define IMPACT_PERFORMANCE_TABLE_SIZE           5
#define ARCADE_BRAIN_DEFEAT_POINTS              20

#endif //GUARD_BATTLE_ARCADE_H
