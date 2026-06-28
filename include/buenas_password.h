#ifndef GUARD_BUENAS_PASSWORD_H
#define GUARD_BUENAS_PASSWORD_H

u16 BuenasPassword_IsBroadcastTime(void);
const u8 *BuenasPassword_GetRadioText(void);
void BuenasPassword_BufferCurrentPassword(void);
u16 BuenasPassword_GetCurrentGroup(void);
u16 BuenasPassword_GetCorrectAnswer(void);

#endif // GUARD_BUENAS_PASSWORD_H
