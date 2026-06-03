#ifndef GUARD_BATTLE_ARCADE_H
#define GUARD_BATTLE_ARCADE_H

void CallBattleArcadeFunc(void);
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

#define VAR_ARCADE_BERRY                        VAR_ROCKET_ARCADE_BERRY
#define VAR_ARCADE_ITEM                         VAR_ROCKET_ARCADE_ITEM
#define VAR_ARCADE_PERFORMANCE_POINTS           VAR_ROCKET_ARCADE_POINTS

#define IMPACT_PERFORMANCE_TABLE_SIZE           5
#endif //GUARD_BATTLE_ARCADE_H
