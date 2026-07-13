AbandonedRocketHideout_MapScripts::
# 2 "data/maps/AbandonedRocketHideout/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE1, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_2
AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 11 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE3, AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 17, 10, 0x500, FALSE
# 5 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 18, 10, 0x500, FALSE
# 6 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 19, 10, 0x500, FALSE
# 7 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 17, 11, 0x500, FALSE
# 8 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 18, 11, 0x500, FALSE
# 9 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 19, 11, 0x500, FALSE
	goto AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_1

AbandonedRocketHideout_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 12 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 10, 10, 0x500, FALSE
# 13 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 11, 10, 0x500, FALSE
# 14 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 12, 10, 0x500, FALSE
# 15 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 10, 11, 0x500, FALSE
# 16 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 11, 11, 0x500, FALSE
# 17 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 12, 11, 0x500, FALSE
	return


ARH_Note1::
# 23 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Note1_Text_0, MSGBOX_SIGN
	return


ARH_MiddleDoor::
# 37 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE3, ARH_MiddleDoor_1
# 40 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MiddleDoor_Text_1, MSGBOX_SIGN
	return

ARH_MiddleDoor_1:
# 38 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MiddleDoor_Text_0, MSGBOX_SIGN
	return


ARH_RightDoor::
# 49 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE1, ARH_RightDoor_1
# 54 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_RightDoor_Text_1, MSGBOX_SIGN
	return

ARH_RightDoor_1:
# 50 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_RightDoor_Text_0, MSGBOX_SIGN
	return


ARH_Note2::
# 63 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Note2_Text_0, MSGBOX_SIGN
	return


ARH_Computer1::
# 74 "data/maps/AbandonedRocketHideout/scripts.pory"
	lock
# 75 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE1, ARH_Computer1_2
# 82 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_PC_ON
# 83 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Computer1_Text_1
# 88 "data/maps/AbandonedRocketHideout/scripts.pory"
	waitse
# 89 "data/maps/AbandonedRocketHideout/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, ARH_Computer1_Text_2, ARH_Computer1_Text_3, ARH_Computer1_Text_4, ARH_Computer1_Text_5, ARH_Computer1_Text_6
# 91 "data/maps/AbandonedRocketHideout/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 3, ARH_Computer1_6
# 108 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 4, ARH_Computer1_7
# 111 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_FAILURE
# 113 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Computer1_Text_8
ARH_Computer1_4:
# 116 "data/maps/AbandonedRocketHideout/scripts.pory"
	release
	return

ARH_Computer1_2:
# 76 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Computer1_Text_0, MSGBOX_SIGN
# 79 "data/maps/AbandonedRocketHideout/scripts.pory"
	release
	end

ARH_Computer1_6:
# 93 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_SUCCESS
# 95 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_Computer1_Text_7
# 99 "data/maps/AbandonedRocketHideout/scripts.pory"
	setflag FLAG_ARH_PUZZLE1
# 100 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 17, 10, 0x500, FALSE
# 101 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 18, 10, 0x500, FALSE
# 102 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 19, 10, 0x500, FALSE
# 103 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 17, 11, 0x500, FALSE
# 104 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 18, 11, 0x500, FALSE
# 105 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 19, 11, 0x500, FALSE
# 106 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_EXIT
# 107 "data/maps/AbandonedRocketHideout/scripts.pory"
	special DrawWholeMapView
	goto ARH_Computer1_4

ARH_Computer1_7:
# 109 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_PC_OFF
	goto ARH_Computer1_4


ARH_BoxLeft::
# 120 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxLeft_Text_0, MSGBOX_SIGN
	return


ARH_BoxRight1::
# 131 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxRight1_Text_0, MSGBOX_SIGN
	return


ARH_BoxRightRoomRightOne2::
# 140 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE2, ARH_BoxRightRoomRightOne2_2
# 145 "data/maps/AbandonedRocketHideout/scripts.pory"
	lock
# 146 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxRightRoomRightOne2_Text_1
# 148 "data/maps/AbandonedRocketHideout/scripts.pory"
	playfanfare MUS_HG_OBTAIN_ITEM
# 149 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxRightRoomRightOne2_Text_2
# 153 "data/maps/AbandonedRocketHideout/scripts.pory"
	waitfanfare
# 154 "data/maps/AbandonedRocketHideout/scripts.pory"
	setflag FLAG_ARH_PUZZLE2
# 155 "data/maps/AbandonedRocketHideout/scripts.pory"
	release
	return

ARH_BoxRightRoomRightOne2_2:
# 141 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxRightRoomRightOne2_Text_0, MSGBOX_SIGN
	end


ARH_BoxWrong::
# 159 "data/maps/AbandonedRocketHideout/scripts.pory"
	random 6
# 160 "data/maps/AbandonedRocketHideout/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 0, ARH_BoxWrong_2
# 165 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 1, ARH_BoxWrong_3
# 170 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 2, ARH_BoxWrong_4
# 175 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 3, ARH_BoxWrong_5
# 178 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 4, ARH_BoxWrong_6
# 181 "data/maps/AbandonedRocketHideout/scripts.pory"
	case 5, ARH_BoxWrong_7
	return

ARH_BoxWrong_2:
# 162 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_0, MSGBOX_SIGN
	return

ARH_BoxWrong_3:
# 166 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_1, MSGBOX_SIGN
	return

ARH_BoxWrong_4:
# 171 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_2, MSGBOX_SIGN
	return

ARH_BoxWrong_5:
# 176 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_3, MSGBOX_SIGN
	return

ARH_BoxWrong_6:
# 179 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_4, MSGBOX_SIGN
	return

ARH_BoxWrong_7:
# 182 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_BoxWrong_Text_5, MSGBOX_SIGN
	return


ARH_MachineRight::
# 192 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_set FLAG_ARH_PUZZLE3, ARH_MachineRight_2
# 198 "data/maps/AbandonedRocketHideout/scripts.pory"
	goto_if_unset FLAG_ARH_PUZZLE2, ARH_MachineRight_5
# 207 "data/maps/AbandonedRocketHideout/scripts.pory"
	lock
# 208 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MachineRight_Text_2
# 210 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_CLICK
# 211 "data/maps/AbandonedRocketHideout/scripts.pory"
	waitse
# 212 "data/maps/AbandonedRocketHideout/scripts.pory"
	setflag FLAG_ARH_PUZZLE3
# 213 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 10, 10, 0x500, FALSE
# 214 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 11, 10, 0x500, FALSE
# 215 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 12, 10, 0x500, FALSE
# 216 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 10, 11, 0x500, FALSE
# 217 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 11, 11, 0x500, FALSE
# 218 "data/maps/AbandonedRocketHideout/scripts.pory"
	setmetatile 12, 11, 0x500, FALSE
# 219 "data/maps/AbandonedRocketHideout/scripts.pory"
	playse SE_EXIT
# 220 "data/maps/AbandonedRocketHideout/scripts.pory"
	special DrawWholeMapView
# 221 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MachineRight_Text_3
# 225 "data/maps/AbandonedRocketHideout/scripts.pory"
	release
	return

ARH_MachineRight_2:
# 193 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MachineRight_Text_0, MSGBOX_SIGN
	end

ARH_MachineRight_5:
# 199 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MachineRight_Text_1, MSGBOX_SIGN
	end


ARH_MachineRight2::
# 230 "data/maps/AbandonedRocketHideout/scripts.pory"
	msgbox ARH_MachineRight2_Text_0, MSGBOX_SIGN
	return


ARH_Note1_Text_0:
# 23 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "A brittle memo is pinned beneath\n"
	.string "the dust...\p"
	.string "PROJECT SHADOW - CLOSURE ORDER\p"
	.string "All Shadow specimens are to be\n"
	.string "discarded immediately.\p"
	.string "Burn the research.\p"
	.string "Leave nothing.$"

ARH_MiddleDoor_Text_0:
# 38 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The central shutter is open.$"

ARH_MiddleDoor_Text_1:
# 40 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "CENTRAL ARCHIVE\p"
	.string "POWER RELAY: NOT DETECTED\p"
	.string "The shutter is locked in place.$"

ARH_RightDoor_Text_0:
# 50 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "STORAGE BAY R\p"
	.string "ACCESS GRANTED$"

ARH_RightDoor_Text_1:
# 54 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "STORAGE BAY R\p"
	.string "SEALED BY SHADOW PROTOCOL\p"
	.string "Remote authorization is required.$"

ARH_Note2_Text_0:
# 63 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "Most of the report has been shredded.\n"
	.string "One paragraph survives...\p"
	.string "'Houndour was the first subject to\n"
	.string "retain a stable Shadow response.\p"
	.string "Earlier Rattata and Zubat trials were\n"
	.string "judged unusable.'$"

ARH_Computer1_Text_0:
# 76 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The terminal displays a single line:\p"
	.string "STORAGE BAY R - UNSEALED$"

ARH_Computer1_Text_1:
# 83 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The old terminal sputters to life.\p"
	.string "SHADOW FAILSAFE\n"
	.string "Enter the Pokédex index of the first\l"
	.string "viable subject.$"

ARH_Computer1_Text_2:
# 90 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "019$"

ARH_Computer1_Text_3:
# 90 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "041$"

ARH_Computer1_Text_4:
# 90 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "198$"

ARH_Computer1_Text_5:
# 90 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "228$"

ARH_Computer1_Text_6:
# 90 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "Cancel$"

ARH_Computer1_Text_7:
# 95 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "SUBJECT 228: HOUNDOUR\n"
	.string "AUTHORIZATION CONFIRMED\p"
	.string "Storage Bay R is now unsealed.$"

ARH_Computer1_Text_8:
# 113 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "SUBJECT RECORD REJECTED.$"

ARH_BoxLeft_Text_0:
# 120 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "A clipboard is wedged between the\n"
	.string "packing foam and the crate wall.\p"
	.string "SUBJECT INDEX\n"
	.string "019 - RATTATA\l"
	.string "041 - ZUBAT\l"
	.string "198 - MURKROW\l"
	.string "228 - HOUNDOUR$"

ARH_BoxRight1_Text_0:
# 131 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The crate contains a Rocket uniform\n"
	.string "and a note written in red ink...\p"
	.string "'My locker code is 041.\n"
	.string "Markov, stay out this time.'$"

ARH_BoxRightRoomRightOne2_Text_0:
# 141 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The fitted compartment is empty.$"

ARH_BoxRightRoomRightOne2_Text_1:
# 146 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "Something heavy shifts beneath a false\n"
	.string "bottom.$"

ARH_BoxRightRoomRightOne2_Text_2:
# 149 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "{PLAYER} found the Magnetic Relay!\p"
	.string "It looks like it belongs in one of the\n"
	.string "warehouse machines.$"

ARH_BoxWrong_Text_0:
# 162 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "Nothing but crushed Poké Ball\n"
	.string "shells. Every one has been neatly\l"
	.string "stamped REJECTED.$"

ARH_BoxWrong_Text_1:
# 166 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "Hundreds of left-handed black\n"
	.string "gloves.\p"
	.string "There is not one right glove.$"

ARH_BoxWrong_Text_2:
# 171 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "A shipping manifest reads:\p"
	.string "SINISTER CAPES - 40\n"
	.string "DRAMATIC WIND MACHINES - 40$"

ARH_BoxWrong_Text_3:
# 176 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "A fossilized RageCandyBar sticks\n"
	.string "to the packing paper.$"

ARH_BoxWrong_Text_4:
# 179 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The crate is full of fake moustaches\n"
	.string "labeled EXECUTIVE EMERGENCY KIT.$"

ARH_BoxWrong_Text_5:
# 182 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "This crate is labeled\n"
	.string "LOTS OF VOLTORBS.\p"
	.string "It is empty... \p"
	.string "You feel a sense of relief.$"

ARH_MachineRight_Text_0:
# 193 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The restored relay hums steadily.\p"
	.string "CENTRAL ARCHIVE - ACCESS ONLINE$"

ARH_MachineRight_Text_1:
# 199 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "CENTRAL SHUTTER CONTROL\p"
	.string "ERROR: MAGNETIC RELAY MISSING\p"
	.string "A relay-shaped socket is empty.$"

ARH_MachineRight_Text_2:
# 208 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The magnetic relay fits the empty\n"
	.string "socket perfectly.$"

ARH_MachineRight_Text_3:
# 221 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "The old machinery hums to life.\p"
	.string "The central shutter seems to\n"
	.string "have opened in the hallway.$"

ARH_MachineRight2_Text_0:
# 230 "data/maps/AbandonedRocketHideout/scripts.pory"
	.string "UMBRA MEASUREMENT MONITOR\p"
	.string "The final readings are frozen on the\n"
	.string "dim display.\p"
	.string "HEART RATE: 220\n"
	.string "AGGRESSION: ERROR\l"
	.string "EMOTION: 0%$"
