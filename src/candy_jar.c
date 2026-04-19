#include "global.h"
#include "candy_jar.h"
#include "load_save.h"

#define MAX_CANDY_JAR_EXP 99999999

static u32 DecryptCandyJarExp(u32 *exp)
{
    return *exp ^ gSaveBlock2Ptr->encryptionKey;
}

void SetCandyJarExp(u32 *exp, u32 amount)
{
    *exp = amount ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToCandyJarExp(u32 encryptionKey)
{
    ApplyNewEncryptionKeyToWord(&gSaveBlock3Ptr->candyJarExp, encryptionKey);
}

bool8 GiveCandyJarExp(u32 amountToAdd)
{
    u32 *exp = &gSaveBlock3Ptr->candyJarExp;
    u32 amount = DecryptCandyJarExp(exp);

    if (MAX_CANDY_JAR_EXP - amount <= amountToAdd)
    {
        SetCandyJarExp(exp, MAX_CANDY_JAR_EXP);
        return FALSE;
    }

    SetCandyJarExp(exp, amount + amountToAdd);
    return TRUE;
}

bool8 TakeCandyJarExp(u32 amountToTake)
{
    u32 *exp = &gSaveBlock3Ptr->candyJarExp;
    u32 amount = DecryptCandyJarExp(exp);

    if (amount < amountToTake)
        return FALSE;

    SetCandyJarExp(exp, amount - amountToTake);
    return TRUE;
}

u32 GetCandyJarExp(void)
{
    return DecryptCandyJarExp(&gSaveBlock3Ptr->candyJarExp);
}
