#include "global.h"
#include "m4a.h"
#include "overworld.h"
#include "pokemon.h"
#include "sound.h"
#include "test/test.h"
#include "constants/maps.h"
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

TEST("Default map music wins if a battle starts during its fade from saved script music")
{
    struct WarpData savedLocation = gSaveBlock1Ptr->location;
    u16 savedMusic = gSaveBlock1Ptr->savedMusic;
    u8 savedMapType = gMapHeader.mapType;
    bool8 savedSurfMusic = gSaveBlock2Ptr->optionsSurfMusic;
    u16 defaultMusic;

    ResetSoundTestState();
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(MAP_ROUTE101);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(MAP_ROUTE101);
    gMapHeader.mapType = MAP_TYPE_ROUTE;
    gSaveBlock2Ptr->optionsSurfMusic = FALSE;
    defaultMusic = GetCurrLocationDefaultMusic();
    ASSUME(defaultMusic != MUS_HG_ENCOUNTER_RIVAL);

    StartMapSong(MUS_HG_ENCOUNTER_RIVAL);
    Overworld_SetSavedMusic(MUS_HG_ENCOUNTER_RIVAL);
    Overworld_ChangeMusicToDefault();

    EXPECT(!IsNotWaitingForBGMStop());

    // Starting the battle before MapMusicMain finishes the fade used to leave
    // savedMusic pointing at the script theme, which won on the field return.
    StartBattleSong(MUS_VS_WILD);
    Overworld_PlaySpecialMapMusic();
    EXPECT_EQ(GetCurrentMapMusic(), defaultMusic);
    EXPECT_EQ(gSaveBlock1Ptr->savedMusic, MUS_DUMMY);

    gSaveBlock1Ptr->location = savedLocation;
    gSaveBlock1Ptr->savedMusic = savedMusic;
    gMapHeader.mapType = savedMapType;
    gSaveBlock2Ptr->optionsSurfMusic = savedSurfMusic;
}
