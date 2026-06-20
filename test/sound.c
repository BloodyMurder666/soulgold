#include "global.h"
#include "m4a.h"
#include "pokemon.h"
#include "sound.h"
#include "test/test.h"
#include "constants/songs.h"

static void ResetSoundTestState(void)
{
    m4aSoundInit();
    InitMapMusic();
}

static void AdvanceBgm(u8 frames)
{
    u8 i;

    for (i = 0; i < frames; i++)
        m4aSoundMain();
}

static void StartMapSong(u16 songNum)
{
    PlayNewMapMusic(songNum);
    MapMusicMain();
    AdvanceBgm(8);
}

static void StartBattleSong(u16 songNum)
{
    PlayMapChosenOrBattleBGM(songNum);
    MapMusicMain();
    AdvanceBgm(8);
}

TEST("Map music resumes from saved position after battle BGM")
{
#if OW_RESUME_MUSIC_AFTER_BATTLE
    u8 i;
    struct SongHeader *savedHeader;
    u32 savedClock;
    u8 *savedCmdPtr;
    u8 savedWait;

    ResetSoundTestState();
    StartMapSong(MUS_ROUTE101);

    ASSUME(gMPlayInfo_BGM.songHeader != NULL);
    ASSUME(gMPlayInfo_BGM.tracks != NULL);
    ASSUME(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK);

    savedHeader = gMPlayInfo_BGM.songHeader;
    savedClock = gMPlayInfo_BGM.clock;
    savedCmdPtr = gMPlayInfo_BGM.tracks[0].cmdPtr;
    savedWait = gMPlayInfo_BGM.tracks[0].wait;

    SaveMapMusicForBattleResume();
    StartBattleSong(MUS_VS_WILD);

    EXPECT(gMPlayInfo_BGM.songHeader != savedHeader);
    EXPECT(TryResumeMapMusicAfterBattle(MUS_ROUTE101));
    EXPECT(gMPlayInfo_BGM.songHeader == savedHeader);
    EXPECT_EQ(gMPlayInfo_BGM.clock, savedClock);
    EXPECT(gMPlayInfo_BGM.tracks[0].cmdPtr == savedCmdPtr);
    EXPECT_EQ(gMPlayInfo_BGM.tracks[0].wait, savedWait);
    EXPECT_EQ(GetCurrentMapMusic(), MUS_ROUTE101);

    for (i = 0; i < gMPlayInfo_BGM.trackCount; i++)
        EXPECT(gMPlayInfo_BGM.tracks[i].chan == NULL);
#else
    EXPECT(!TryResumeMapMusicAfterBattle(MUS_ROUTE101));
#endif
}

TEST("Trainer encounter music does not replace saved map music")
{
#if OW_RESUME_MUSIC_AFTER_BATTLE
    struct SongHeader *routeHeader;
    struct SongHeader *encounterHeader;

    ResetSoundTestState();
    StartMapSong(MUS_ROUTE101);

    routeHeader = gMPlayInfo_BGM.songHeader;
    SaveMapMusicForBattleResume();

    PlayNewMapMusic(MUS_ENCOUNTER_MALE);
    MapMusicMain();
    AdvanceBgm(8);
    encounterHeader = gMPlayInfo_BGM.songHeader;

    StartBattleSong(MUS_VS_TRAINER);

    EXPECT(encounterHeader != routeHeader);
    EXPECT(TryResumeMapMusicAfterBattle(MUS_ROUTE101));
    EXPECT(gMPlayInfo_BGM.songHeader == routeHeader);
    EXPECT(gMPlayInfo_BGM.songHeader != encounterHeader);
    EXPECT_EQ(GetCurrentMapMusic(), MUS_ROUTE101);
#else
    EXPECT(!TryResumeMapMusicAfterBattle(MUS_ROUTE101));
#endif
}

TEST("Map music battle resume clears on expected music mismatch")
{
#if OW_RESUME_MUSIC_AFTER_BATTLE
    ResetSoundTestState();
    StartMapSong(MUS_ROUTE101);

    SaveMapMusicForBattleResume();
    StartBattleSong(MUS_VS_WILD);

    EXPECT(!TryResumeMapMusicAfterBattle(MUS_POKE_CENTER));
    EXPECT(!TryResumeMapMusicAfterBattle(MUS_ROUTE101));
#else
    EXPECT(!TryResumeMapMusicAfterBattle(MUS_POKE_CENTER));
#endif
}
