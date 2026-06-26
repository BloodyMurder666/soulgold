#ifndef GUARD_REPLAY_OPTIONS_H
#define GUARD_REPLAY_OPTIONS_H

struct Pokemon;

enum ReplayOption
{
    REPLAY_OPTION_BATTLE_FORMAT_DOUBLES,
    REPLAY_OPTION_BATTLE_FORMAT_SINGLES,
    REPLAY_OPTION_TRAINER_PERFECT_IVS,
    REPLAY_OPTION_TRAINER_MAX_EVS,
    REPLAY_OPTION_EASY_IVS,
    REPLAY_OPTION_NO_INNATES,
};

enum ReplayBattleFormat
{
    REPLAY_BATTLE_FORMAT_DESIGNED,
    REPLAY_BATTLE_FORMAT_DOUBLES,
    REPLAY_BATTLE_FORMAT_SINGLES,
};

bool32 ToggleReplayOption(enum ReplayOption option);
bool32 ToggleReplayAllInnatesUnlocked(void);
bool32 ToggleReplayTrainerFullStats(void);
bool32 ToggleMaxPainReplayOptions(void);
enum ReplayBattleFormat GetReplayBattleFormat(void);
bool32 AreReplayTrainerPerfectIVsForced(void);
bool32 AreReplayTrainerMaxEVsForced(void);
bool32 AreReplayEasyIVsEnabled(void);
bool32 AreReplayInnatesDisabled(void);
void ApplyReplayEasyIVs(struct Pokemon *mon);

#endif // GUARD_REPLAY_OPTIONS_H
