#ifndef GUARD_UI_BIRCH_MENU_H
#define GUARD_UI_BIRCH_MENU_H

#include "main.h"

void Task_OpenBirchCase(u8 taskId);
void BirchCase_Init(MainCallback callback);
bool8 BirchCase_TryGetLastStarterPicData(u16 species, bool8 *isShiny, u32 *personality);


#endif // GUARD_UI_MENU_H
