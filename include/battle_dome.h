#ifndef GUARD_BATTLE_DOME_H
#define GUARD_BATTLE_DOME_H

#include "constants/battle_dome.h"

int GetDomeTrainerSelectedMons(u16 tournamentTrainerId);
int TrainerIdToDomeTournamentId(u16 trainerId);
bool8 IsPwtDomeTrainerId(u16 trainerId);
u8 PwtDomeHandleToParticipantId(u16 trainerId);
u16 GetPwtDomeTrainerId(u16 trainerId);
u8 GetPwtDomeTrainerPicId(u16 trainerId);
void CopyPwtDomeTrainerName(u8 *dst, u16 trainerId);
u8 GetPwtDomeFacilityClass(u16 trainerId);
void CopyPwtDomeTrainerText(u8 *dst, u16 trainerId, u8 textId);

#endif // GUARD_BATTLE_DOME_H
