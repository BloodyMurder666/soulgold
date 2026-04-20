#ifndef GUARD_HIDDEN_GROTTO_H
#define GUARD_HIDDEN_GROTTO_H

#include "gba/types.h"

enum HiddenGrottoContentType
{
    HIDDEN_GROTTO_UNSET,
    HIDDEN_GROTTO_EMPTY,
    HIDDEN_GROTTO_POKEMON,
    HIDDEN_GROTTO_ITEM,
    HIDDEN_GROTTO_HIDDEN_ITEM,
};

struct HiddenGrottoContent
{
    u8 type;
    u16 id;
};

void DailyResetHiddenGrottoes(void);
void HiddenGrotto_InitializeCurrent(void);
void HiddenGrotto_EmptyCurrent(void);
void HiddenGrotto_GetCurrentContentType(void);
void HiddenGrotto_GetCurrentContentId(void);
void HiddenGrotto_CreateCurrentMon(void);
void HiddenGrotto_TestCurrentMonBounds(void);

#define NUM_HIDDEN_GROTTOES 9

#endif // GUARD_HIDDEN_GROTTO_H
