BattleArcade_Challenge_EventScript_BeginChallenge::
# 13 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_0, 2
# 14 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCFaceCrowd
# 15 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BeginChallenge_Text_0, MSGBOX_DEFAULT
# 16 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BeginChallenge_Text_1, MSGBOX_DEFAULT
# 17 "data/scripts/battle_arcade_battle.pory"
	arcade_takeplayerhelditems
# 18 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BattleOpponent::
# 23 "data/scripts/battle_arcade_battle.pory"
	tower_setopponent
# 24 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard::
# 29 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AnnounceGameNumber
# 30 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance
# 31 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainIntro
# 32 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartGameBoard
# 33 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentBattleMovement
# 34 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_LoadOpponentText
# 35 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_StartBattle
# 36 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HandleBattleResult
	return


BattleArcade_Challenge_EventScript_AnnounceGameNumber::
# 41 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 42 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_AnnounceGameNumber_Text_0, MSGBOX_DEFAULT
# 43 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_EventScript_BufferNextBattleNumber::
# 48 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 49 "data/scripts/battle_arcade_battle.pory"
	addvar VAR_RESULT, 1
# 50 "data/scripts/battle_arcade_battle.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
	return


BattleArcade_Challenge_EventScript_StartGameBoard::
# 55 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition
# 56 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_PlayGameBoard
# 57 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_HandleGameResults
	return


BattleArcade_Challenge_EventScript_PlayGameBoard::
# 63 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_PlayGameBoard_Text_0, MSGBOX_DEFAULT
# 64 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 65 "data/scripts/battle_arcade_battle.pory"
	arcade_generateopponentparty
# 66 "data/scripts/battle_arcade_battle.pory"
	arcade_takeenemyhelditems
# 67 "data/scripts/battle_arcade_battle.pory"
	arcade_playgameboard
	return


BattleArcade_Challenge_EventScript_HandleGameResults::
# 72 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_HandleGameResults_Text_0, MSGBOX_DEFAULT
# 73 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact
# 74 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem
# 75 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCBack
# 76 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_SkipBattle_Script
# 77 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_HandleGameResults_Text_1, MSGBOX_DEFAULT
# 78 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_AnnounceImpactGiveItem::
# 83 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8009, 0
	goto_if_ne BattleArcade_Challenge_AnnounceImpactGiveItem_2
# 89 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Failure
BattleArcade_Challenge_AnnounceImpactGiveItem_1:
# 91 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 92 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_GiveItem_Script
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_2:
# 85 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_AnnounceImpactGiveItem_Success
	goto BattleArcade_Challenge_AnnounceImpactGiveItem_1


BattleArcade_Challenge_AnnounceImpactGiveItem_Success::
# 97 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 99 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LOWER_HP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2
# 101 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3
# 103 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4
# 105 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5
# 107 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6
# 109 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7
# 111 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BERRY, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 112 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_ITEM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8
# 114 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_LEVEL_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9
# 116 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SUN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10
# 118 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RAIN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11
# 120 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SAND, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12
# 122 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_HAIL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13
# 124 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FOG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14
# 126 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_TRICK_ROOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15
# 128 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SWAP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16
# 130 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_UP, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17
# 132 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SPEED_DOWN, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18
# 134 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_RANDOM, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19
# 136 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_SMALL, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 137 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_GIVE_BP_BIG, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20
# 139 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_BATTLE, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21
# 142 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_NO_EVENT, BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22
BattleArcade_Challenge_AnnounceImpactGiveItem_Success_22:
# 143 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_20, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_2:
# 100 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_0, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_3:
# 102 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_1, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_4:
# 104 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_2, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_5:
# 106 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_3, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_6:
# 108 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_4, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_7:
# 110 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_5, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_8:
# 113 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_6, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_9:
# 115 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_7, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_10:
# 117 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_8, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_11:
# 119 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_9, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_12:
# 121 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_10, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_13:
# 123 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_11, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_14:
# 125 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_12, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_15:
# 127 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_13, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_16:
# 129 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_14, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_17:
# 131 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_15, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_18:
# 133 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_16, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_19:
# 135 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_17, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_20:
# 138 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_18, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_21:
# 140 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_19, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_AnnounceImpactGiveItem_Failure::
# 149 "data/scripts/battle_arcade_battle.pory"
	switch VAR_0x8007
# 151 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_POISON, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2
# 153 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_PARALYZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3
# 155 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_BURN, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4
# 157 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_SLEEP, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5
# 160 "data/scripts/battle_arcade_battle.pory"
	case ARCADE_EVENT_FREEZE, BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6
BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_6:
# 161 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_4, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_2:
# 152 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_0, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_3:
# 154 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_1, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_4:
# 156 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_2, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_5:
# 158 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_3, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_GiveItem_Script::
# 166 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_3
BattleArcade_Challenge_GiveItem_Script_1:
# 170 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCToTrainer
# 171 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_GiveItem_Script_Text_0
# 172 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 173 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer
	return

BattleArcade_Challenge_GiveItem_Script_2:
	return

BattleArcade_Challenge_GiveItem_Script_3:
# 166 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_Challenge_GiveItem_Script_2
	goto BattleArcade_Challenge_GiveItem_Script_1


BattleArcade_Challenge_SkipBattle_Script::
# 178 "data/scripts/battle_arcade_battle.pory"
	compare VAR_0x8007, ARCADE_EVENT_NO_BATTLE
	goto_if_ne BattleArcade_Challenge_SkipBattle_Script_2
# 183 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 184 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	return

BattleArcade_Challenge_SkipBattle_Script_2:
	return


BattleArcade_Challenge_EventScript_BattleBrain::
# 189 "data/scripts/battle_arcade_battle.pory"
	arcade_setbrainobj
# 190 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SpawnOpponentStartGameBoard
	return


BattleArcade_Challenge_EventScript_LoadOpponentText::
# 196 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 197 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_LoadOpponentText_2
# 204 "data/scripts/battle_arcade_battle.pory"
	tower_getopponentintro 0
# 205 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_LoadOpponentText_1:
# 207 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 208 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_LoadOpponentText_2:
# 199 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferBrainPreBattleText
# 200 "data/scripts/battle_arcade_battle.pory"
	msgbox gStringVar3, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_LoadOpponentText_1


BattleArcade_Challenge_EventScript_StartBattle::
# 213 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition
# 214 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_DoArcadeBattle
	return


BattleArcade_Challenge_EventScript_DoArcadeBattle::
# 219 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 221 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, FALSE
# 222 "data/scripts/battle_arcade_battle.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 223 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_0x8005, 0
# 225 "data/scripts/battle_arcade_battle.pory"
	special DoArcadeTrainerBattle
# 226 "data/scripts/battle_arcade_battle.pory"
	waitstate
# 227 "data/scripts/battle_arcade_battle.pory"
	arcade_eventcleanup
# 229 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 230 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return


BattleArcade_Challenge_EventScript_HandleBattleResult::
# 235 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_Challenge_EventScript_HandleBattleResult_2
BattleArcade_Challenge_EventScript_HandleBattleResult_1:
# 239 "data/scripts/battle_arcade_battle.pory"
	arcade_checkdoubledown
# 240 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_HandleBattleResult_5
BattleArcade_Challenge_EventScript_HandleBattleResult_4:
# 245 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_RESULT, B_OUTCOME_LOST
# 246 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby
	return

BattleArcade_Challenge_EventScript_HandleBattleResult_2:
# 237 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent
	goto BattleArcade_Challenge_EventScript_HandleBattleResult_1

BattleArcade_Challenge_EventScript_HandleBattleResult_5:
# 242 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_HandleBattleResult_Text_0, MSGBOX_DEFAULT
# 243 "data/scripts/battle_arcade_battle.pory"
	arcade_clearprize
	goto BattleArcade_Challenge_EventScript_HandleBattleResult_4


BattleArcade_Challenge_EventScript_Save::
# 251 "data/scripts/battle_arcade_battle.pory"
	message gText_SavingDontTurnOffPower
# 252 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 253 "data/scripts/battle_arcade_battle.pory"
	special LoadPlayerParty
# 254 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_SetChallengeStatus
# 255 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 256 "data/scripts/battle_arcade_battle.pory"
	waitse
# 257 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return


BattleArcade_Challenge_EventScript_SetChallengeStatus::
# 262 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleArcade_Challenge_EventScript_SetChallengeStatus_1
# 268 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_LOST
	return

BattleArcade_Challenge_EventScript_SetChallengeStatus_1:
# 264 "data/scripts/battle_arcade_battle.pory"
	tower_save CHALLENGE_STATUS_WON
	return


BattleArcade_Challenge_EventScript_SaveWarpToLobby::
# 274 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_Save
# 276 "data/scripts/battle_arcade_battle.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 277 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
	goto_if_eq BattleArcade_Challenge_EventScript_SaveWarpToLobby_2
# 283 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_GOLDENROD_BATTLE_ARACDE_LOBBY, 7, 6
BattleArcade_Challenge_EventScript_SaveWarpToLobby_1:
# 285 "data/scripts/battle_arcade_battle.pory"
	waitstate
	end

BattleArcade_Challenge_EventScript_SaveWarpToLobby_2:
# 279 "data/scripts/battle_arcade_battle.pory"
	warpsilent MAP_GOLDENROD_BATTLE_ARACDE_LOBBY, 8, 6
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby_1


BattleArcade_Challenge_EventScript_DefeatedOpponent::
# 291 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 292 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_ne BattleArcade_Challenge_EventScript_DefeatedOpponent_2
BattleArcade_Challenge_EventScript_DefeatedOpponent_1:
# 300 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 302 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 303 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_STAGES_PER_CHALLENGE
	goto_if_gt BattleArcade_Challenge_EventScript_DefeatedOpponent_5
BattleArcade_Challenge_EventScript_DefeatedOpponent_4:
# 307 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_CashOutOrDoubleDown
# 308 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement
# 309 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_HealPlayer
	return

BattleArcade_Challenge_EventScript_DefeatedOpponent_2:
# 294 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BrainCongratsText
# 295 "data/scripts/battle_arcade_battle.pory"
	arcade_setbattlewon
# 296 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_MoveBattlersBack
# 297 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_1

BattleArcade_Challenge_EventScript_DefeatedOpponent_5:
# 305 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge
	goto BattleArcade_Challenge_EventScript_DefeatedOpponent_4


BattleArcade_Challenge_EventScript_CashOutOrDoubleDown::
# 314 "data/scripts/battle_arcade_battle.pory"
	arcade_bufferprize
# 315 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_Text_0
# 316 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 317 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 8, MULTI_ROCKET_ARCADE_CASH_OUT, TRUE
# 318 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 320 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_2
# 321 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_3
# 322 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_4
	return

BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_2:
# 320 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_DoubleDown
	return

BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_3:
# 321 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_CashOut
	return

BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_4:
# 322 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_CashOutOrDoubleDown
	return


BattleArcade_Challenge_EventScript_CashOut::
# 328 "data/scripts/battle_arcade_battle.pory"
	showmoneybox 0, 0
# 329 "data/scripts/battle_arcade_battle.pory"
	delay 30
# 330 "data/scripts/battle_arcade_battle.pory"
	arcade_awardprize
# 331 "data/scripts/battle_arcade_battle.pory"
	updatemoneybox 0
# 332 "data/scripts/battle_arcade_battle.pory"
	playse SE_SHOP
# 333 "data/scripts/battle_arcade_battle.pory"
	waitse
# 334 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_CashOut_Text_0, MSGBOX_DEFAULT
# 335 "data/scripts/battle_arcade_battle.pory"
	hidemoneybox
# 336 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_RESULT, B_OUTCOME_WON
# 337 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby
	return


BattleArcade_Challenge_EventScript_DoubleDown::
# 342 "data/scripts/battle_arcade_battle.pory"
	arcade_doubledown
# 343 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_DoubleDown_Text_0, MSGBOX_DEFAULT
	return


BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge::
# 350 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 351 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1:
# 355 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_GivePrize
# 356 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_Text_0
# 357 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby
	return

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_2:
# 353 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_1


BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge::
# 362 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 363 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge_2
BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge_1:
# 367 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_GivePrize
# 368 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_Text_0
# 369 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby
	return

BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge_2:
# 365 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
	goto BattleArcade_RoulettRoom_EventScript_ResolveBrainChallenge_1


BattleArcade_Challenge_EventScript_GivePrize::
# 374 "data/scripts/battle_arcade_battle.pory"
	showmoneybox 0, 0
# 375 "data/scripts/battle_arcade_battle.pory"
	delay 30
# 376 "data/scripts/battle_arcade_battle.pory"
	arcade_awardprize
# 377 "data/scripts/battle_arcade_battle.pory"
	updatemoneybox 0
# 378 "data/scripts/battle_arcade_battle.pory"
	playse SE_SHOP
# 379 "data/scripts/battle_arcade_battle.pory"
	waitse
# 380 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_GivePrize_Text_0, MSGBOX_DEFAULT
# 381 "data/scripts/battle_arcade_battle.pory"
	hidemoneybox
	return


BattleArcade_Challenge_EventScript_HealPlayer::
# 386 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_HealPlayer_Text_0
# 387 "data/scripts/battle_arcade_battle.pory"
	playfanfare MUS_HEAL
# 388 "data/scripts/battle_arcade_battle.pory"
	waitfanfare
# 389 "data/scripts/battle_arcade_battle.pory"
	special HealPlayerParty
# 390 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 391 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_BattleRoom_EventScript_AttendantLeave
# 392 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskReadyForOpponent::
# 397 "data/scripts/battle_arcade_battle.pory"
	arcade_getbrainstatus
# 398 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
	goto_if_ne BattleArcade_Challenge_EventScript_AskReadyForOpponent_2
BattleArcade_Challenge_EventScript_AskReadyForOpponent_1:
# 403 "data/scripts/battle_arcade_battle.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 404 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_ReadyForOpponent
# 405 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 406 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForOpponent_5
BattleArcade_Challenge_EventScript_AskReadyForOpponent_4:
# 410 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenu
	return

BattleArcade_Challenge_EventScript_AskReadyForOpponent_2:
# 400 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainUpNext
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_1

BattleArcade_Challenge_EventScript_AskReadyForOpponent_5:
# 408 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ReadyMenuNoRecord
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent_4


BattleArcade_Challenge_EventScript_ReadyForOpponent::
# 416 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_BufferNextBattleNumber
# 417 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_EventScript_ReadyForOpponent_Text_0
# 418 "data/scripts/battle_arcade_battle.pory"
	waitmessage
	return


BattleArcade_Challenge_EventScript_ReadyMenu::
# 423 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 424 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 426 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenu_2
# 427 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenu_3
# 428 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenu_4
# 429 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_ReadyMenu_5
# 430 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenu_6
	return

BattleArcade_Challenge_EventScript_ReadyMenu_2:
# 426 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_3:
# 427 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_ReadyMenu_4:
# 428 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_5:
# 429 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenu_6:
# 430 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_ReadyMenuNoRecord::
# 436 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 437 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 439 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2
# 440 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3
# 441 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4
# 442 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_2:
# 439 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_ContinueChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_3:
# 440 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_4:
# 441 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_ReadyMenuNoRecord_5:
# 442 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle::
# 448 "data/scripts/battle_arcade_battle.pory"
	call BattleArcade_Challenge_EventScript_AskRecordBattle
# 449 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return


BattleArcade_Challenge_EventScript_AskRecordBattle::
# 454 "data/scripts/battle_arcade_battle.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 455 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 456 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 457 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRecordBattle_1
	return

BattleArcade_Challenge_EventScript_AskRecordBattle_1:
# 459 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_SaveBattle
	return


BattleArcade_Challenge_EventScript_AskPauseChallenge::
# 465 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_AskPauseChallenge_Text_0, MSGBOX_YESNO
# 466 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleArcade_Challenge_EventScript_AskPauseChallenge_2
BattleArcade_Challenge_EventScript_AskPauseChallenge_1:
# 470 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskPauseChallenge_2:
# 468 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_PauseChallenge
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge_1


BattleArcade_Challenge_EventScript_PauseChallenge::
# 475 "data/scripts/battle_arcade_battle.pory"
	message gText_SavingDontTurnOffPower
# 476 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 478 "data/scripts/battle_arcade_battle.pory"
	arcade_save CHALLENGE_STATUS_PAUSED
# 479 "data/scripts/battle_arcade_battle.pory"
	playse SE_SAVE
# 480 "data/scripts/battle_arcade_battle.pory"
	waitse
# 482 "data/scripts/battle_arcade_battle.pory"
	fadescreen FADE_TO_BLACK
# 483 "data/scripts/battle_arcade_battle.pory"
	frontier_reset
	end


BattleArcade_Challenge_EventScript_AskRetireChallenge::
# 489 "data/scripts/battle_arcade_battle.pory"
	message BattleArcade_Challenge_EventScript_AskRetireChallenge_Text_0
# 490 "data/scripts/battle_arcade_battle.pory"
	waitmessage
# 491 "data/scripts/battle_arcade_battle.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 492 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleArcade_Challenge_EventScript_AskRetireChallenge_2
BattleArcade_Challenge_EventScript_AskRetireChallenge_1:
# 496 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForOpponent
	return

BattleArcade_Challenge_EventScript_AskRetireChallenge_2:
# 494 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_RetireChallenge
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge_1


BattleArcade_Challenge_EventScript_RetireChallenge::
# 501 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_RESULT, B_OUTCOME_LOST
# 502 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_SaveWarpToLobby
	return


BattleArcade_Challenge_EventScript_ContinueChallenge::
# 507 "data/scripts/battle_arcade_battle.pory"
	closemessage
# 508 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleOpponent
	return


BattleArcade_Challenge_EventScript_BrainUpNext::
# 513 "data/scripts/battle_arcade_battle.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainUpNext_2
BattleArcade_Challenge_EventScript_BrainUpNext_1:
# 518 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainUpNext_Text_0, MSGBOX_DEFAULT
# 519 "data/scripts/battle_arcade_battle.pory"
	setvar VAR_TEMP_2, TRUE
# 521 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return

BattleArcade_Challenge_EventScript_BrainUpNext_2:
# 515 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	goto BattleArcade_Challenge_EventScript_BrainUpNext_1


BattleArcade_Challenge_EventScript_AskReadyForBrain::
# 526 "data/scripts/battle_arcade_battle.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 527 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_Challenge_EventScript_AskReadyForBrain_1
# 533 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenu
	return

BattleArcade_Challenge_EventScript_AskReadyForBrain_1:
# 529 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord
	return


BattleArcade_Challenge_EventScript_BrainReadyMenu::
# 539 "data/scripts/battle_arcade_battle.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 540 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 542 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenu_2
# 543 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenu_3
# 544 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenu_4
# 545 "data/scripts/battle_arcade_battle.pory"
	case 3, BattleArcade_Challenge_EventScript_BrainReadyMenu_5
# 546 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenu_6
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_2:
# 542 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_3:
# 543 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRecordBattleNextBattle
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_4:
# 544 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_5:
# 545 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenu_6:
# 546 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord::
# 552 "data/scripts/battle_arcade_battle.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 553 "data/scripts/battle_arcade_battle.pory"
	switch VAR_RESULT
# 555 "data/scripts/battle_arcade_battle.pory"
	case 0, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2
# 556 "data/scripts/battle_arcade_battle.pory"
	case 1, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3
# 557 "data/scripts/battle_arcade_battle.pory"
	case 2, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4
# 558 "data/scripts/battle_arcade_battle.pory"
	case MULTI_B_PRESSED, BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_2:
# 555 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_BattleBrain
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_3:
# 556 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskPauseChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_4:
# 557 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskRetireChallenge
	return

BattleArcade_Challenge_EventScript_BrainReadyMenuNoRecord_5:
# 558 "data/scripts/battle_arcade_battle.pory"
	goto BattleArcade_Challenge_EventScript_AskReadyForBrain
	return


BattleArcade_Challenge_EventScript_BrainIntro::
# 564 "data/scripts/battle_arcade_battle.pory"
	frontier_isbrain
# 565 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_2
# 570 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainIntro_Text_0, MSGBOX_DEFAULT
# 571 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 572 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainIntro_4
# 578 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainIntro_Text_2, MSGBOX_DEFAULT
	return

BattleArcade_Challenge_EventScript_BrainIntro_2:
	return

BattleArcade_Challenge_EventScript_BrainIntro_4:
# 574 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainIntro_Text_1, MSGBOX_DEFAULT
	return


BattleArcade_Challenge_EventScript_BufferBrainPreBattleText::
# 584 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 585 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1
# 591 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_Text_1
	return

BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_1:
# 587 "data/scripts/battle_arcade_battle.pory"
	bufferstring STR_VAR_3, BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_Text_0
	return


BattleArcade_Challenge_EventScript_BrainCongratsText::
# 597 "data/scripts/battle_arcade_battle.pory"
	arcade_getprintfromstreak
# 598 "data/scripts/battle_arcade_battle.pory"
	compare VAR_RESULT, ARCADE_SYMBOL_SILVER
	goto_if_eq BattleArcade_Challenge_EventScript_BrainCongratsText_2
# 604 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainCongratsText_Text_1, MSGBOX_DEFAULT
BattleArcade_Challenge_EventScript_BrainCongratsText_1:
# 606 "data/scripts/battle_arcade_battle.pory"
	closemessage
	return

BattleArcade_Challenge_EventScript_BrainCongratsText_2:
# 600 "data/scripts/battle_arcade_battle.pory"
	msgbox BattleArcade_Challenge_EventScript_BrainCongratsText_Text_0, MSGBOX_DEFAULT
	goto BattleArcade_Challenge_EventScript_BrainCongratsText_1


BattleArcade_Challenge_EventScript_BeginChallenge_Text_0:
# 15 "data/scripts/battle_arcade_battle.pory"
	.string "Welcome to the Rocket Arcade!$"

BattleArcade_Challenge_EventScript_BeginChallenge_Text_1:
# 16 "data/scripts/battle_arcade_battle.pory"
	.string "First, I’ll need to hold on to any items\n"
	.string "held by your Pokémon.$"

BattleArcade_Challenge_EventScript_AnnounceGameNumber_Text_0:
# 42 "data/scripts/battle_arcade_battle.pory"
	.string "Game no. {STR_VAR_1}! Come on!$"

BattleArcade_Challenge_EventScript_PlayGameBoard_Text_0:
# 63 "data/scripts/battle_arcade_battle.pory"
	.string "Without further ado... Let’s activate\n"
	.string "the game board!$"

BattleArcade_Challenge_EventScript_HandleGameResults_Text_0:
# 72 "data/scripts/battle_arcade_battle.pory"
	.string "This is our current event!$"

BattleArcade_Challenge_EventScript_HandleGameResults_Text_1:
# 77 "data/scripts/battle_arcade_battle.pory"
	.string "OK! Let the battle commence!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_0:
# 100 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon without full\l"
	.string "HP!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_1:
# 102 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon poisoned!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_2:
# 104 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon paralyzed!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_3:
# 106 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon burned!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_4:
# 108 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon asleep!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_5:
# 110 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon frozen!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_6:
# 113 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will be loaned\n"
	.string "the {STR_VAR_3}.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_7:
# 115 "data/scripts/battle_arcade_battle.pory"
	.string "The match will commence with\n"
	.string "{STR_VAR_1}’s Pokémon leveled up!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_8:
# 117 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "harsh sunlight.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_9:
# 119 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "steady rainfall.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_10:
# 121 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under a\n"
	.string "raging sandstorm.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_11:
# 123 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted under\n"
	.string "pelting hail.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_12:
# 125 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted in a dense\n"
	.string "fog.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_13:
# 127 "data/scripts/battle_arcade_battle.pory"
	.string "This match will be conducted on a floor\n"
	.string "where time and space are distorted.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_14:
# 129 "data/scripts/battle_arcade_battle.pory"
	.string "Your Pokémon will be switched with the\n"
	.string "other Trainer’s for this match.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_15:
# 131 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be increased.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_16:
# 133 "data/scripts/battle_arcade_battle.pory"
	.string "From the next game on, the game board’s\n"
	.string "speed will be decreased.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_17:
# 135 "data/scripts/battle_arcade_battle.pory"
	.string "For the next game, the game board’s\n"
	.string "motion will become random.$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_18:
# 138 "data/scripts/battle_arcade_battle.pory"
	.string "The prize panel flashes, but the Rocket\n"
	.string "Arcade only pays out after a win!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_19:
# 140 "data/scripts/battle_arcade_battle.pory"
	.string "Oh! Lucky! You can skip the battle!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Success_Text_20:
# 143 "data/scripts/battle_arcade_battle.pory"
	.string "Too bad! There is no event this time!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_0:
# 152 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match poisoned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be poisoned!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_1:
# 154 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match paralyzed... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be paralyzed!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_2:
# 156 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match burned... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be burned!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_3:
# 158 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match asleep... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be made to sleep!$"

BattleArcade_Challenge_AnnounceImpactGiveItem_Failure_Text_4:
# 161 "data/scripts/battle_arcade_battle.pory"
	.string "{STR_VAR_1}’s Pokémon will enter the\n"
	.string "match frozen... Oh! A lucky break!\l"
	.string "{STR_VAR_1} has no Pokémon that\l"
	.string "can be frozen!$"

BattleArcade_Challenge_GiveItem_Script_Text_0:
# 171 "data/scripts/battle_arcade_battle.pory"
	.string "Here you go!$"

BattleArcade_Challenge_EventScript_HandleBattleResult_Text_0:
# 242 "data/scripts/battle_arcade_battle.pory"
	.string "You lost it all! Better luck next time.$"

BattleArcade_Challenge_EventScript_CashOutOrDoubleDown_Text_0:
# 315 "data/scripts/battle_arcade_battle.pory"
	.string "You won ¥{STR_VAR_1}!\n"
	.string "Cash out or risk it all?$"

BattleArcade_Challenge_EventScript_CashOut_Text_0:
# 334 "data/scripts/battle_arcade_battle.pory"
	.string "You cashed out ¥{STR_VAR_1}!$"

BattleArcade_Challenge_EventScript_DoubleDown_Text_0:
# 343 "data/scripts/battle_arcade_battle.pory"
	.string "Double down accepted! The next round\n"
	.string "puts it all on the line.$"

BattleArcade_RoulettRoom_EventScript_ResolveEndChallenge_Text_0:
# 356 "data/scripts/battle_arcade_battle.pory"
	.string "We will return any items we were holding\n"
	.string "for you.$"

BattleArcade_Challenge_EventScript_GivePrize_Text_0:
# 380 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations! You earned\n"
	.string "¥{STR_VAR_1} as your prize!$"

BattleArcade_Challenge_EventScript_HealPlayer_Text_0:
# 386 "data/scripts/battle_arcade_battle.pory"
	.string "Good going! We’ll heal your Pokémon now.$"

BattleArcade_Challenge_EventScript_ReadyForOpponent_Text_0:
# 417 "data/scripts/battle_arcade_battle.pory"
	.string "Next up, game no. {STR_VAR_1}! Are\n"
	.string "you ready?$"

BattleArcade_Challenge_EventScript_AskPauseChallenge_Text_0:
# 465 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to save and take a break\n"
	.string "from playing?$"

BattleArcade_Challenge_EventScript_AskRetireChallenge_Text_0:
# 489 "data/scripts/battle_arcade_battle.pory"
	.string "Would you like to retire from this\n"
	.string "challenge?$"

BattleArcade_Challenge_EventScript_BrainUpNext_Text_0:
# 518 "data/scripts/battle_arcade_battle.pory"
	.string "Congratulations, Trainer! In\n"
	.string "recognition of your outstanding nerve,\l"
	.string "our Frontier Brain is demanding a match\l"
	.string "with you. So, your next match is against\l"
	.string "Archer, the Rocket Arcade Boss; no ifs\l"
	.string "or buts! Are you ready?$"

BattleArcade_Challenge_EventScript_BrainIntro_Text_0:
# 570 "data/scripts/battle_arcade_battle.pory"
	.string "Archer: The Rocket Arcade rewards\n"
	.string "skill, not luck.\p"
	.string "You have pressed your advantage well\n"
	.string "enough to stand before me once more.\l"
	.string "But this time I will show you the true\l"
	.string "might of Team Rocket.$"

BattleArcade_Challenge_EventScript_BrainIntro_Text_1:
# 574 "data/scripts/battle_arcade_battle.pory"
	.string "Show me whether your skill is true, or\n"
	.string "mere luck.$"

BattleArcade_Challenge_EventScript_BrainIntro_Text_2:
# 578 "data/scripts/battle_arcade_battle.pory"
	.string "You have returned with the same\n"
	.string "arrogance as before. I will correct\l"
	.string "that.$"

BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_Text_0:
# 587 "data/scripts/battle_arcade_battle.pory"
	.string "Archer: A proper Rocket Operative\n"
	.string "never leaves victory to chance. Let us\l"
	.string "see if you can stand against it.$"

BattleArcade_Challenge_EventScript_BufferBrainPreBattleText_Text_1:
# 591 "data/scripts/battle_arcade_battle.pory"
	.string "Archer: You have pushed deeper into my\n"
	.string "house than most. Now pay attention to\l"
	.string "how a Rocket closes a game.$"

BattleArcade_Challenge_EventScript_BrainCongratsText_Text_0:
# 600 "data/scripts/battle_arcade_battle.pory"
	.string "Archer: Hmph. You read the table\n"
	.string "correctly and struck when it mattered.\l"
	.string "Take your winnings.$"

BattleArcade_Challenge_EventScript_BrainCongratsText_Text_1:
# 604 "data/scripts/battle_arcade_battle.pory"
	.string "Archer: You have taken even the\n"
	.string "house's best hand. Remember this\l"
	.string "feeling. It is expensive to chase.$"
