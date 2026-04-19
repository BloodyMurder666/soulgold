#ifndef GUARD_CANDY_JAR_H
#define GUARD_CANDY_JAR_H

#define EXP_CANDY_M_THRESHOLD 3000

void SetCandyJarExp(u32 *exp, u32 amount);
void ApplyNewEncryptionKeyToCandyJarExp(u32 encryptionKey);
bool8 GiveCandyJarExp(u32 amountToAdd);
bool8 TakeCandyJarExp(u32 amountToTake);
u32 GetCandyJarExp(void);

#endif // GUARD_CANDY_JAR_H
