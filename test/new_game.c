#include "global.h"
#include "difficulty.h"
#include "event_data.h"
#include "new_game.h"
#include "overworld.h"
#include "replay_options.h"
#include "test/test.h"
#include "constants/party_menu.h"
#include "constants/vars.h"

TEST("A fresh new game defaults to 2x battle speed")
{
    Sav2_ClearSetDefault();

    NewGameInitData();

    EXPECT_EQ(VarGet(VAR_BATTLE_SPEED), OPTIONS_BATTLE_SCENE_2X);
    EXPECT_EQ((u8)gSaveBlock2Ptr->optionsBattleSpeed, OPTIONS_BATTLE_SCENE_2X);
}

TEST("Starting a new game preserves settings selected from the main menu")
{
    SetCurrentDifficultyLevel(DIFFICULTY_HARD);
    VarSet(VAR_OVERWORLD_SPEEDUP, OPTIONS_OVERWORLD_SPEED_4X);
    VarSet(VAR_BATTLE_SPEED, OPTIONS_BATTLE_SCENE_3X);
    gSaveBlock2Ptr->optionsBattleSpeed = OPTIONS_BATTLE_SCENE_3X;
    gSaveBlock1Ptr->optionsPartyMenuStyle = PARTY_MENU_OPTION_HGSS;
    gSaveBlock1Ptr->optionsPartyMenuStyleMagic = PARTY_MENU_OPTION_SAVE_MAGIC;
    SetReplayBattleFormat(REPLAY_BATTLE_FORMAT_DOUBLES);

    NewGameInitData();

    EXPECT_EQ(GetCurrentDifficultyLevel(), DIFFICULTY_HARD);
    EXPECT_EQ(VarGet(VAR_OVERWORLD_SPEEDUP), OPTIONS_OVERWORLD_SPEED_4X);
    EXPECT_EQ(VarGet(VAR_BATTLE_SPEED), OPTIONS_BATTLE_SCENE_3X);
    EXPECT_EQ((u8)gSaveBlock2Ptr->optionsBattleSpeed, OPTIONS_BATTLE_SCENE_3X);
    EXPECT_EQ(gSaveBlock1Ptr->optionsPartyMenuStyle, PARTY_MENU_OPTION_HGSS);
    EXPECT_EQ(gSaveBlock1Ptr->optionsPartyMenuStyleMagic, PARTY_MENU_OPTION_SAVE_MAGIC);
    EXPECT_EQ(GetReplayBattleFormat(), REPLAY_BATTLE_FORMAT_DOUBLES);
}
