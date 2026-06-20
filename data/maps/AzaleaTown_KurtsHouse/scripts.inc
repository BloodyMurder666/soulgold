# 1 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 2 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 3 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_MapScripts::
# 4 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
# 5 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
# 6 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.byte 0
# 7 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 8 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_OnTransition::
# 9 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
# 10 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 11 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 12 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_OnFrame::
# 13 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
# 14 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.2byte 0
# 15 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 16 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtBefore::
# 17 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	lock
# 18 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 19 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
# 20 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 21 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
# 22 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
# 23 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 24 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_EXIT
# 25 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
# 26 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setflag FLAG_HIDE_KURT_1
# 27 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
# 28 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 2
# 29 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 30 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 31 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 32 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_PlayerMove::
# 33 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
# 34 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 35 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
# 36 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 37 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_EXIT
# 38 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
# 39 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setflag FLAG_HIDE_KURT_1
# 40 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
# 41 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 42 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 43 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 44 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Girl::
# 45 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	lock
# 46 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 47 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
# 48 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
# 49 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
# 50 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 51 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 52 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 53 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Girl2::
# 54 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
# 55 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
# 56 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
# 57 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
# 58 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
# 59 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5
# 60 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 61 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
# 62 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 63 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 64 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 65 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 66 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Girl3::
# 67 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
# 68 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 69 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 70 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 71 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 72 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Girl4::
# 73 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
# 74 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 75 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 76 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end	
# 77 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 78 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Girl5::
# 79 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
# 80 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 81 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 82 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end	
# 83 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 84 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
# 85 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
# 86 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 87 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 88 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
# 89 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	lock
# 90 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 91 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
# 92 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_FAST_BALL
# 93 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 94 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
# 95 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 96 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 97 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 4
# 98 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 99 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 100 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 101 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
# 102 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_GS_BALL
# 103 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
# 104 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	return
# 105 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 106 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt::
# 107 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	lock
# 108 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 109 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
# 110 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
# 111 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
# 112 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 113 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
# 114 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt2::
# 115 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	multichoice 20, 0, MULTI_KURT_BALLS, FALSE
# 116 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	switch VAR_RESULT
# 117 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 0, AzaleaTown_KurtsHouse_EventScript_Kurt_Love
# 118 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 1, AzaleaTown_KurtsHouse_EventScript_Kurt_Lure
# 119 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 2, AzaleaTown_KurtsHouse_EventScript_Kurt_Friend
# 120 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 3, AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy
# 121 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 4, AzaleaTown_KurtsHouse_EventScript_Kurt_Moon
# 122 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 5, AzaleaTown_KurtsHouse_EventScript_Kurt_Fast
# 123 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 6, AzaleaTown_KurtsHouse_EventScript_Kurt_Level
# 124 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case 7, AzaleaTown_KurtsHouse_EventScript_KurtCancel
# 125 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	case MULTI_B_PRESSED, AzaleaTown_KurtsHouse_EventScript_KurtCancel
# 126 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 127 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 128 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Love::
# 129 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 130 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PECHA_BERRY
# 131 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_PECHA_BERRY, 5
# 132 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 133 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 134 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 135 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 136 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 137 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 138 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 139 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 140 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 141 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 142 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 143 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 144 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_LOVE_BALL, 5
# 145 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_PECHA_BERRY, 5
# 146 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 147 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 148 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 149 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 150 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 151 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 152 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Lure::
# 153 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 154 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_RAWST_BERRY
# 155 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_RAWST_BERRY, 5
# 156 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 157 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 158 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 159 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 160 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 161 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 162 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 163 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 164 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 165 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 166 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 167 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 168 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_LURE_BALL, 5
# 169 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_RAWST_BERRY, 5
# 170 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 171 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 172 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 173 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 174 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 175 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 176 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Friend::
# 177 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 178 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CHERI_BERRY
# 179 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_CHERI_BERRY, 5
# 180 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 181 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 182 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 183 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 184 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 185 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 186 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 187 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 188 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 189 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 190 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 191 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 192 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_FRIEND_BALL, 5
# 193 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_CHERI_BERRY, 5
# 194 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 195 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 196 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 197 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 198 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 199 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 200 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Heavy::
# 201 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 202 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ORAN_BERRY
# 203 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_ORAN_BERRY, 5
# 204 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 205 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 206 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 207 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 208 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 209 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 210 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 211 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 212 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 213 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 214 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 215 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 216 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_HEAVY_BALL, 5
# 217 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_ORAN_BERRY, 5
# 218 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 219 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 220 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 221 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 222 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 223 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 224 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Moon::
# 225 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 226 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CHESTO_BERRY
# 227 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_CHESTO_BERRY, 5
# 228 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 229 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 230 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 231 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 232 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 233 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 234 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 235 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 236 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 237 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 238 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 239 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 240 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_MOON_BALL, 5
# 241 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_CHESTO_BERRY, 5
# 242 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 243 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 244 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 245 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 246 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 247 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 248 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Fast::
# 249 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 250 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ASPEAR_BERRY
# 251 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_ASPEAR_BERRY, 5
# 252 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 253 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 254 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 255 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 256 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 257 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 258 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 259 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 260 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 261 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 262 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 263 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 264 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_FAST_BALL, 5
# 265 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_ASPEAR_BERRY, 5
# 266 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 267 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 268 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 269 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 270 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 271 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 272 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_Kurt_Level::
# 273 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 274 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PERSIM_BERRY
# 275 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	checkitem ITEM_PERSIM_BERRY, 5
# 276 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_DontHaveBerry
# 277 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtGetStarted, MSGBOX_DEFAULT
# 278 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 279 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 280 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 281 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 282 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 283 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 284 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 285 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 286 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtJustFinishedYourBall, MSGBOX_DEFAULT
# 287 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmessage
# 288 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	giveitem ITEM_LEVEL_BALL, 5
# 289 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_PERSIM_BERRY, 5
# 290 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 291 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
# 292 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 293 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 294 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 295 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 296 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 297 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_DontHaveBerry::
# 298 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtThatsALetdown, MSGBOX_DEFAULT
# 299 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 300 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
# 301 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 302 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 303 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	
# 304 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtCancel::
# 305 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 306 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
# 307 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 308 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 309 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 310 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
# 311 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
# 312 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 313 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	removeitem ITEM_GS_BALL
# 314 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 315 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 316 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 317 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_BANG
# 318 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
# 319 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 320 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	faceplayer
# 321 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
# 322 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 323 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_M_PETAL_DANCE
# 324 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitse
# 325 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_PIN
# 326 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
# 327 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 328 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay 60
# 329 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitse
# 330 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	playse SE_M_PETAL_DANCE
# 331 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitse
# 332 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
# 333 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
# 334 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 335 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	waitmovement 0
# 336 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
# 337 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
# 338 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 8
# 339 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 340 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 341 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 342 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 343 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
# 344 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
# 345 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 346 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay 30
# 347 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
# 348 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 349 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
# 350 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	release
# 351 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 352 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_BallAnyway:
# 353 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Anyway, can I make you some Balls?$"
# 354 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 355 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_OakPhoto::
# 356 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
# 357 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 358 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 359 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 360 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
# 361 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
# 362 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	closemessage
# 363 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	end
# 364 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 365 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTownKurt_Movement_Look_Around:
# 366 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_left
# 367 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 368 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_right
# 369 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 370 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_up
# 371 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 372 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_down
# 373 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 374 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_left
# 375 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	step_end
# 376 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 377 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTownKurt_Movement_Making_Ball:
# 378 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_up
# 379 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_in_place_fast_up
# 380 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 381 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_in_place_fast_up
# 382 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	delay_8
# 383 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_in_place_fast_up
# 384 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	step_end
# 385 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 386 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_Movement_Player:
# 387 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	face_right
# 388 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	lock_facing_direction
# 389 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_left
# 390 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	unlock_facing_direction
# 391 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	step_end
# 392 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 393 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
# 394 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 395 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 396 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 397 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 398 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 399 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	walk_fast_down
# 400 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	step_end
# 401 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 402 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtGetStarted:
# 403 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: I'll get started right now!$"
# 404 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 405 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtMakingBallsMustWait:
# 406 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Hm? Who are you?\p"
# 407 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "{PLAYER}, eh? You want me to make\n"
# 408 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "some Balls?\p"
# 409 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Sorry, but that'll have to wait.\p"
# 410 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Do you know Team Rocket?\n"
# 411 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Ah, don't worry.\p"
# 412 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I'll tell you anyhow.\p"
# 413 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Team Rocket's an evil gang that\n"
# 414 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "uses Pokémon for their dirty work.\p"
# 415 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "They're supposed to have disbanded\n"
# 416 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "three years ago.\p"
# 417 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Anyway, they're at the Well,\n"
# 418 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "cutting off Slowpoketails to sell!\p"
# 419 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "So I'm going to go give them a\n"
# 420 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "lesson in pain!\p"
# 421 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Hang on, Slowpoke! Old Kurt\n"
# 422 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "is on his way!$"
# 423 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 424 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtHonoredToMakeBalls:
# 425 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: Hi, {PLAYER}!\p"
# 426 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "You handled yourself like a\n"
# 427 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "real hero at the Well.\p"
# 428 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I like your style!\p"
# 429 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I would be honored to make\n"
# 430 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Balls for a trainer like you.\p"
# 431 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "This is all I have now, \n"
# 432 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "but take it.$"
# 433 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 434 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtBallsFromApricorns:
# 435 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: I make Balls from Berries.\p"
# 436 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Collect them from trees and bring\n"
# 437 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "'em to me in batches of 5.\p"
# 438 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I'll make Balls out of them.$"
# 439 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 440 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtAskYouHaveAnApricorn:
# 441 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: You have 5 Berries for me?\p"
# 442 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Fine! I'll turn them into Balls.$"
# 443 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 444 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtThatsALetdown:
# 445 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: I don't see 5 {STR_VAR_1}s!$"
# 446 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 447 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtJustFinishedYourBall:
# 448 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: Ah, {PLAYER}! \p"
# 449 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I just finished your Ball. Here!$"
# 450 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 451 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtTurnedOutGreat:
# 452 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Kurt: That turned out great.\p"
# 453 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Try catching Pokémon with it.$"
# 454 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 455 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtWhatIsThat:
# 456 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Wh-what is that?\p"
# 457 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I've never seen one before.\p"
# 458 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "It looks a like a Poké Ball, but\n"
# 459 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "it appears to be something else.\p"
# 460 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Let me check it for you.$"
# 461 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 462 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtImCheckingItNow:
# 463 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I'm checking it now.$"
# 464 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 465 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtAhHaISee:
# 466 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Ah-ha! I see! So…$"
# 467 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 468 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_KurtThisBallStartedToShake:
# 469 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "{PLAYER}!\p"
# 470 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "This Ball started to shake\n"
# 471 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "while I was checking it.\p"
# 472 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "There must be something to this!$"
# 473 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 474 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_Kurt_Whatwasthat:
# 475 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "What was that sound?!\p"
# 476 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Let's go outside to investigate!$"
# 477 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 478 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterSlowpokeGone:
# 479 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "The Slowpoke are gone… \n"
# 480 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Were they taken away by bad people?$"
# 481 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 482 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterLonely:
# 483 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Grandpa's gone… I'm so lonely…$"
# 484 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 485 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterSlowpokeBack:
# 486 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "The Slowpoke my dad gave me came back!\p"
# 487 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Its Tail is growing back too!$"
# 488 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 489 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterDad:
# 490 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Dad works at Silph where\n"
# 491 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "he studies Poké Balls.\p"
# 492 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I have to stay home\n"
# 493 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "with Grandpa and Slowpoke.$"
# 494 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 495 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterHelp:
# 496 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "I get to help Grandpa now!\p"
# 497 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "We'll make good Balls\n"
# 498 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "for you, so please wait!$"
# 499 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 500 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterFun:
# 501 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "It's fun to make Balls!$"
# 502 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 503 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_GranddaughterSound:
# 504 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Did that sound come from\n"
# 505 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Ilex Forest????$"
# 506 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 507 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_Forest:
# 508 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Did you check Ilex Forest yet?\n"
# 509 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "It sounds very restless.$"
# 510 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 511 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_Slowpoke:
# 512 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "Slowpoke: … Yawn?$"
# 513 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 514 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_OakPhoto:
# 515 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "…A young Prof. Oak?$"
# 516 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"

# 517 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
KurtsHouse_Text_CelebiStatue:
# 518 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "It's a statue of the forest's\n"
# 519 "data/maps/AzaleaTown_KurtsHouse/scripts.pory"
	.string "protector.$"
