# 1 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_MapScripts::
# 3 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
# 5 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnWarp:
# 8 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
# 9 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
# 12 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame:
# 17 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 18 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 19 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 20 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 21 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 22 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
# 25 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 26 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
# 29 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 30 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 31 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 32 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 33 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 34 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 35 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 36 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 37 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 38 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 39 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 41 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
# 42 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 43 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 44 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 45 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 47 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 48 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 49 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
# 50 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 51 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 52 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 4, MULTI_LEVEL_MODE, FALSE
# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LEVEL_CHOICE_INFO, BattleFrontier_BattleFactoryLobby_EventScript_LevelInfo
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LEVEL_CHOICE_BGM, BattleFrontier_BattleFactoryLobby_EventScript_Bgm
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LevelInfo::
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_ShowLevelModeInfo
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Bgm::
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_ChooseBattleBgm
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	callnative UpdateFollowingPokemon
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper::
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of Trainers\n"
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the Battle Factory!\p"
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a Single Battle competition using\l"
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental Pokémon.\p"
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon specifically for this event.\p"
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental Pokémon,\n"
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a Single Battle.\p"
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental Pokémon.\p"
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Classic or Chaos?$"
# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your Pokémon for\n"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your Pokémon in exchange\n"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.\p"
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your Pokémon in exchange\n"
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.$"
# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal Pokémon.$"
# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of Trainers\n"
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the Battle Factory!\p"
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a Double Battle competition using\l"
# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental Pokémon.\p"
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon specifically for this event.\p"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental Pokémon,\n"
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a Double Battle.\p"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental Pokémon.\p"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the Factory Head and winning\l"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your Pokémon\n"
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.\p"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Factory match on your\l"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Frontier Pass?$"
# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of Pokémon?\p"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about Pokémon and their moves,\l"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak Pokémon…\n"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon during battle to see if\l"
# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental Pokémon.$"
# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three Pokémon.\p"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same Pokémon.$"
# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap Pokémon only with\n"
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the Trainer you have just defeated.\p"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those Pokémon\n"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten Trainer.$"
# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's Pokémon.\p"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap Pokémon\n"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh Trainer in the event.$"
# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping Pokémon.\p"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the Pokémon you are\l"
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the Pokémon on your team\n"
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In Chaos, the rental Pokémon\n"
# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing Trainers' Pokémon\l"
# 564 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"

FactoryBpLady::
# 568 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 569 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox FactoryBpLady_Text_0
# 571 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, FactoryBpLady_2
# 574 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	bpmart FactoryBpMart
FactoryBpLady_1:
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox FactoryBpLady_Text_1
# 577 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
	end

FactoryBpLady_2:
# 572 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	bpmart FactoryBpMart8Badges
	goto FactoryBpLady_1


	.align 2
# 581 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
FactoryBpMart:
# 582 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_HEALTH_FEATHER
# 583 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_MUSCLE_FEATHER
# 584 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_RESIST_FEATHER
# 585 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_GENIUS_FEATHER
# 586 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_CLEVER_FEATHER
# 587 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_SWIFT_FEATHER
# 588 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 589 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 590 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_BECKONING_BELL
	.2byte ITEM_NONE

	.align 2
# 593 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
FactoryBpMart8Badges:
# 594 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_NUGGET
# 595 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_BIG_NUGGET
# 596 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_HEALTH_FEATHER
# 597 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_MUSCLE_FEATHER
# 598 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_RESIST_FEATHER
# 599 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_GENIUS_FEATHER
# 600 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_CLEVER_FEATHER
# 601 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_SWIFT_FEATHER
# 602 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 603 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 604 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte ITEM_BECKONING_BELL
	.2byte ITEM_NONE

FactoryBpLady_Text_0:
# 570 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome!$"

FactoryBpLady_Text_1:
# 576 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thanks!$"
