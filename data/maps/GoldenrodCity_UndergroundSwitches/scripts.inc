.set LOCALID_GOLDENROD_UNDERGROUND_SILVER, 7

GoldenrodCity_UndergroundSwitches_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUnderground1_OnLoad
	.byte 0

GoldenrodUnderground1_OnLoad::
	call GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodUnderground1_LoadSolved
	clearflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	call GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_LoadSolved::
	goto_if_set FLAG_GOLDENROD_ALL_SHUTTERS_OPEN, GoldenrodUnderground1_LoadAllShuttersOpen
	call GoldenrodUnderground1_ClearTheWay
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_LoadAllShuttersOpen::
	call GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters
	goto GoldenrodUnderground1_RescuePlayerInShutter

GoldenrodUnderground1_RescuePlayerInShutter::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 7, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_1, 8, GoldenrodUnderground1_RescuePlayerInUpperShutter
	goto_if_lt VAR_TEMP_1, 11, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_1, 12, GoldenrodUnderground1_RescuePlayerInLowerShutter

GoldenrodUnderground1_EndLoad::
	end

GoldenrodUnderground1_RescuePlayerInUpperShutter::
	goto_if_lt VAR_TEMP_0, 5, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 7, GoldenrodUnderground1_RescuePlayerInShutter1
	goto_if_lt VAR_TEMP_0, 14, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 16, GoldenrodUnderground1_RescuePlayerInShutter2
	goto_if_lt VAR_TEMP_0, 23, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 25, GoldenrodUnderground1_RescuePlayerInShutter3
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInLowerShutter::
	goto_if_lt VAR_TEMP_0, 5, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 7, GoldenrodUnderground1_RescuePlayerInShutter4
	goto_if_lt VAR_TEMP_0, 14, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 16, GoldenrodUnderground1_RescuePlayerInShutter5
	goto_if_lt VAR_TEMP_0, 23, GoldenrodUnderground1_EndLoad
	goto_if_le VAR_TEMP_0, 25, GoldenrodUnderground1_RescuePlayerInShutter6
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter1::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter2::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter3::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter4::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter5::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	goto GoldenrodUnderground1_EndLoad

GoldenrodUnderground1_RescuePlayerInShutter6::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6
	goto GoldenrodUnderground1_EndLoad

GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState::
	clearflag FLAG_GOLDENROD_SWITCH_1
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_3
	return

GoldenrodUnderground1_ClearTheWay::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

@Added and antisoft lock, using wall panels

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP::
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text::
	.string "Go back to the entrance\n"
	.string "and reset switches?$"

@ The sequence is deliberately strict: 3 -> 2 -> 1.
@ Pressing any other switch resets both the visible shutters and the switch flags.
GoldenrodCity_UndergroundSwitches_EventScript_Panel1::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_1
	playse SE_CLICK
	setflag FLAG_COMPLETED_SWITCHES
	msgbox GoldenrodUnderground_Text_SequenceComplete, MSGBOX_DEFAULT
	closemessage
	call GoldenrodUnderground1_ClearTheWay
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_2
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_SequenceStep2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel3::
	lock
	goto_if_set FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	goto_if_set FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence
	setflag FLAG_GOLDENROD_SWITCH_3
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_SequenceStep1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_ResetSequence::
	call GoldenrodCity_UndergroundSwitches_EventScript_ClearSwitchState
	clearflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	playse SE_FAILURE
	msgbox GoldenrodUnderground_Text_SequenceReset, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_EmergencyRelease::
	lock
	goto_if_unset FLAG_COMPLETED_SWITCHES, GoldenrodCity_UndergroundSwitches_EventScript_EmergencyReleaseLocked
	goto_if_set FLAG_GOLDENROD_ALL_SHUTTERS_OPEN, GoldenrodCity_UndergroundSwitches_EventScript_AllShuttersAlreadyOpen
	setflag FLAG_GOLDENROD_ALL_SHUTTERS_OPEN
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_EmergencyRelease, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_EmergencyReleaseLocked::
	msgbox GoldenrodUnderground_Text_EmergencyReleaseLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AllShuttersAlreadyOpen::
	msgbox GoldenrodUnderground_Text_AllShuttersAlreadyOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AlreadySolved::
	msgbox GoldenrodUnderground_Text_AlreadySolved, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_CloseAllShutters::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

GoldenrodCity_UndergroundSwitches_EventScript_OpenAllShutters::
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1::
	setmetatile 5, 7, 0x519, FALSE
	setmetatile 6, 7, 0x51A, FALSE
	setmetatile 7, 7, 0x51B, FALSE

	setmetatile 5, 8, 0x521, FALSE
	setmetatile 6, 8, 0x522, FALSE
	setmetatile 7, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2::
	setmetatile 14, 7, 0x519, FALSE
	setmetatile 15, 7, 0x51A, FALSE
	setmetatile 16, 7, 0x51B, FALSE

	setmetatile 14, 8, 0x521, FALSE
	setmetatile 15, 8, 0x522, FALSE
	setmetatile 16, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3::
	setmetatile 23, 7, 0x519, FALSE
	setmetatile 24, 7, 0x51A, FALSE
	setmetatile 25, 7, 0x51B, FALSE

	setmetatile 23, 8, 0x521, FALSE
	setmetatile 24, 8, 0x522, FALSE
	setmetatile 25, 8, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4::
	setmetatile 5, 11, 0x519, FALSE
	setmetatile 6, 11, 0x51A, FALSE
	setmetatile 7, 11, 0x51B, FALSE

	setmetatile 5, 12, 0x521, FALSE
	setmetatile 6, 12, 0x522, FALSE
	setmetatile 7, 12, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5::
	setmetatile 14, 11, 0x519, FALSE
	setmetatile 15, 11, 0x51A, FALSE
	setmetatile 16, 11, 0x51B, FALSE

	setmetatile 14, 12, 0x521, FALSE
	setmetatile 15, 12, 0x522, FALSE
	setmetatile 16, 12, 0x523, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6::
	setmetatile 23, 11, 0x519, FALSE
	setmetatile 24, 11, 0x51A, FALSE
	setmetatile 25, 11, 0x51B, FALSE

	setmetatile 23, 12, 0x521, FALSE
	setmetatile 24, 12, 0x522, FALSE
	setmetatile 25, 12, 0x523, FALSE
	return
@======================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1::
	setmetatile 5, 7, 0x4F8, FALSE
	setmetatile 6, 7, 0x4F9, FALSE
	setmetatile 7, 7, 0x4FA, FALSE
	
	setmetatile 5, 8, 0x500, FALSE
	setmetatile 6, 8, 0x501, FALSE
	setmetatile 7, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2::
	setmetatile 14, 7, 0x4F8, FALSE
	setmetatile 15, 7, 0x4F9, FALSE
	setmetatile 16, 7, 0x4FA, FALSE
	
	setmetatile 14, 8, 0x500, FALSE
	setmetatile 15, 8, 0x501, FALSE
	setmetatile 16, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3::
	setmetatile 23, 7, 0x4F8, FALSE
	setmetatile 24, 7, 0x4F9, FALSE
	setmetatile 25, 7, 0x4FA, FALSE
	
	setmetatile 23, 8, 0x500, FALSE
	setmetatile 24, 8, 0x501, FALSE
	setmetatile 25, 8, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4::
	setmetatile 5, 11, 0x4F8, FALSE
	setmetatile 6, 11, 0x4F9, FALSE
	setmetatile 7, 11, 0x4FA, FALSE
	
	setmetatile 5, 12, 0x500, FALSE
	setmetatile 6, 12, 0x501, FALSE
	setmetatile 7, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5::
	setmetatile 14, 11, 0x4F8, FALSE
	setmetatile 15, 11, 0x4F9, FALSE
	setmetatile 16, 11, 0x4FA, FALSE
	
	setmetatile 14, 12, 0x500, FALSE
	setmetatile 15, 12, 0x501, FALSE
	setmetatile 16, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6::
	setmetatile 23, 11, 0x4F8, FALSE
	setmetatile 24, 11, 0x4F9, FALSE
	setmetatile 25, 11, 0x4FA, FALSE
	
	setmetatile 23, 12, 0x500, FALSE
	setmetatile 24, 12, 0x501, FALSE
	setmetatile 25, 12, 0x502, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerTop::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	@clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	setvar VAR_GOLDENROD_CITY_STATE, 9
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerBot::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	createfieldmugshot MUGSHOT_SILVER
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	setvar VAR_GOLDENROD_CITY_STATE, 9
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_4, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_4, GoldenrodUnderground_Text_SilverWin
	return



GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	step_end


GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end	

GoldenrodCity_UndergroundSwitches_EventScript_Grunt10::
    trainerbattle_single TRAINER_GRUNT_10, GoldenrodUnderground_Text_GruntM11Seen, GoldenrodUnderground_Text_GruntM11Beaten
	msgbox GoldenrodUnderground_Text_GruntM11After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt20::
    trainerbattle_single TRAINER_GRUNT_20, GoldenrodUnderground_Text_GruntM25Seen, GoldenrodUnderground_Text_GruntM25Beaten
	msgbox GoldenrodUnderground_Text_GruntM25After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Duncan::
    trainerbattle_single TRAINER_DUNCAN, GoldenrodUnderground_Text_BurglarDuncanSeen, GoldenrodUnderground_Text_BurglarDuncanBeaten
	msgbox GoldenrodUnderground_Text_BurglarDuncanAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Eddie::
    trainerbattle_single TRAINER_EDDIE, GoldenrodUnderground_Text_BurglarEddieSeen, GoldenrodUnderground_Text_BurglarEddieBeaten
	msgbox GoldenrodUnderground_Text_BurglarEddieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt11::
    trainerbattle_single TRAINER_GRUNT_11, GoldenrodUnderground_Text_GruntM13Seen, GoldenrodUnderground_Text_GruntM13Beaten
	msgbox GoldenrodUnderground_Text_GruntM13After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt27::
    trainerbattle_single TRAINER_GRUNT_27, GoldenrodUnderground_Text_GruntF3Seen, GoldenrodUnderground_Text_GruntF3Beaten
	msgbox GoldenrodUnderground_Text_GruntF3After, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_Text_SilverBefore:
    .string "Hold it!\p"
    .string "I saw you, so I tailed you.\p"
    .string "I don't need you underfoot while I\n"
    .string "take care of Team Rocket.\p"
    .string "…Wait a second. You beat me before,\n"
    .string "didn't you?\p"
    .string "That was just a fluke.\p"
    .string "I've been training my team and now\n"
    .string "I will repay my debts!$"

GoldenrodUnderground_Text_SilverWin:
    .string "…Why… Why do I lose?\p"
    .string "I've assembled the toughest Pokémon.\p"
    .string "I didn't ease up on the gas.\p"
    .string "So why do I lose?$"

GoldenrodUnderground_Text_SilverAfter:
    .string "…I don't understand…\p"
    .string "Is what that Lance guy said true?\p"
    .string "That I don't treat Pokémon properly?\p"
    .string "Love…\p"
    .string "Trust…\p"
    .string "Are they really what I lack?\p"
    .string "Are they keeping me from winning?\p"
    .string "I… I just don't understand.\p"
    .string "But it's not going to end here.\p"
    .string "Not now. Not because of this.\p"
    .string "I won't give up my dream of becoming\n"
    .string "the world's best Pokémon trainer!$"

GoldenrodUnderground_Text_SilverLoss:
    .string "Humph. This is my real power, wimp.\p"
    .string "I'll make Team Rocket history.\p"
    .string "And I'm going to grind that Lance\n"
    .string "under my heels.$"

GoldenrodUnderground_Text_GruntM11Seen:
    .string "Open one shutter, another closes.\p"
    .string "Bet you can't get where you want!$"

GoldenrodUnderground_Text_GruntM11Beaten:
    .string "Drat! I was sunk by indecision!$"

GoldenrodUnderground_Text_GruntM11After:
    .string "I'm confused too…\p"
    .string "The switch at the far end comes\n"
    .string "first. Then work back this way.$"

GoldenrodUnderground_Text_GruntM25Seen:
    .string "Kwahaha!\p"
    .string "Confounded by the shutters, are we?\p"
    .string "I'll let you in on a secret if you\n"
    .string "can beat me!$"

GoldenrodUnderground_Text_GruntM25Beaten:
    .string "Uwww… I blew it.$"

GoldenrodUnderground_Text_GruntM25After:
    .string "All right. A hint!\p"
    .string "Pressing the wrong switch resets\n"
    .string "the whole system.\p"
    .string "Make sure all three are OFF before\n"
    .string "you begin.$"

GoldenrodUnderground_Text_BurglarDuncanSeen:
    .string "Fork over your goodies!$"

GoldenrodUnderground_Text_BurglarDuncanBeaten:
    .string "Mercy!$"

GoldenrodUnderground_Text_BurglarDuncanAfter:
    .string "Steal and sell! That's basic in\n"
    .string "crime, kid!$"

GoldenrodUnderground_Text_BurglarEddieSeen:
    .string "They ditched this project before they\n"
    .string "finished.\p"
    .string "I'm searching for leftover loot.$"

GoldenrodUnderground_Text_BurglarEddieBeaten:
    .string "Over the top!$"

GoldenrodUnderground_Text_BurglarEddieAfter:
    .string "Underground Warehouse?\p"
    .string "What do you want to go there for?\p"
    .string "There's nothing down there.$"

GoldenrodUnderground_Text_GruntM13Seen:
    .string "I don't care if you're lost.\p"
    .string "You show up here, you're nothing but\n"
    .string "a victim!$"

GoldenrodUnderground_Text_GruntM13Beaten:
    .string "Urk! Yeah, think you're cool, huh?$"

GoldenrodUnderground_Text_GruntM13After:
    .string "You must have ice in your veins to\n"
    .string "dis Team Rocket.$"

GoldenrodUnderground_Text_GruntF3Seen:
    .string "Are you lost? No, you can't be.\p"
    .string "You don't have that scared look.\p"
    .string "I'll give you something to be\n"
    .string "scared about!$"

GoldenrodUnderground_Text_GruntF3Beaten:
    .string "How could you?$"

GoldenrodUnderground_Text_GruntF3After:
    .string "Go wherever you'd like! Get lost!\n"
    .string "See if I care!$"

GoldenrodUnderground_Text_SequenceStep1:
    .string "Switch 3 activated.\p"
    .string "The first shutter lock\n"
    .string "disengaged.$"

GoldenrodUnderground_Text_SequenceStep2:
    .string "Switch 2 activated.\p"
    .string "The second shutter lock\n"
    .string "disengaged.$"

GoldenrodUnderground_Text_SequenceComplete:
    .string "Switch 1 activated.\p"
    .string "All shutter locks disengaged!$"

GoldenrodUnderground_Text_SequenceReset:
    .string "That was the wrong switch!\p"
    .string "The sequence and shutters reset.$"

GoldenrodUnderground_Text_AlreadySolved:
    .string "The shutters are already unlocked.$"

GoldenrodUnderground_Text_EmergencyRelease:
    .string "The emergency release was\n"
    .string "activated!\p"
    .string "All shutters opened.$"

GoldenrodUnderground_Text_EmergencyReleaseLocked:
    .string "The emergency release is locked.$"

GoldenrodUnderground_Text_AllShuttersAlreadyOpen:
    .string "All shutters are already open.$"
