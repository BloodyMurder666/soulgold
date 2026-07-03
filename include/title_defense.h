#ifndef GUARD_TITLE_DEFENSE_H
#define GUARD_TITLE_DEFENSE_H

struct TitleDefenseChallenger
{
    u16 trainerId;
    u16 objectGfxId;
    const u8 *introText;
    const u8 *defeatText;
    const u8 *farewellText;
};

extern const struct TitleDefenseChallenger gTitleDefenseNormalChallengers[];
extern const struct TitleDefenseChallenger gTitleDefenseHardChallengers[];
extern const u32 gTitleDefenseNormalChallengerCount;
extern const u32 gTitleDefenseHardChallengerCount;

void TitleDefense_SelectChallenger(void);
void TitleDefense_ShowIntro(void);
void TitleDefense_ShowFarewell(void);
void TitleDefense_PrepareBattle(void);
void TitleDefense_IncrementWins(void);
const struct TitleDefenseChallenger *TitleDefense_GetCurrentChallenger(void);

#endif // GUARD_TITLE_DEFENSE_H
