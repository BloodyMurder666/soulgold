# 1 "data/maps/OlivineCity_PortInside/scripts.pory"

# 2 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_MapScripts::
# 3 "data/maps/OlivineCity_PortInside/scripts.pory"
	.byte 0
# 4 "data/maps/OlivineCity_PortInside/scripts.pory"

# 5 "data/maps/OlivineCity_PortInside/scripts.pory"

# 6 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_EventScript_Oak::
# 7 "data/maps/OlivineCity_PortInside/scripts.pory"
	lock
# 8 "data/maps/OlivineCity_PortInside/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 9 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_PIN
# 10 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
# 11 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 12 "data/maps/OlivineCity_PortInside/scripts.pory"
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
# 13 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
# 14 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 15 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakFixDex
# 16 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 17 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 30
# 18 "data/maps/OlivineCity_PortInside/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 19 "data/maps/OlivineCity_PortInside/scripts.pory"
	special EnableNationalPokedex
# 20 "data/maps/OlivineCity_PortInside/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 21 "data/maps/OlivineCity_PortInside/scripts.pory"
	message OlivineCity_PortInside_Text_Nationaldex2
# 22 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitfanfare
# 23 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 50
# 24 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivineCity_PortInside_Text_Nationaldex3, MSGBOX_DEFAULT
# 25 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 26 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_PIN
# 27 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
# 28 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 29 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
# 30 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 31 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
# 32 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 33 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
# 34 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 35 "data/maps/OlivineCity_PortInside/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
# 36 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 37 "data/maps/OlivineCity_PortInside/scripts.pory"
	removeobject LOCALID_OLIVINEPORT_OAK
# 38 "data/maps/OlivineCity_PortInside/scripts.pory"
	fadedefaultbgm
# 39 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitse
# 40 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 41 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 42 "data/maps/OlivineCity_PortInside/scripts.pory"

# 43 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakFixDex:
# 44 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 45 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 46 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 47 "data/maps/OlivineCity_PortInside/scripts.pory"

# 48 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_PlayerMoveOver:
# 49 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 50 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_left
# 51 "data/maps/OlivineCity_PortInside/scripts.pory"
	face_right
# 52 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 53 "data/maps/OlivineCity_PortInside/scripts.pory"

# 54 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakLeave:
# 55 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 56 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 57 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 58 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 59 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 60 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 61 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 62 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 63 "data/maps/OlivineCity_PortInside/scripts.pory"

# 64 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex1:
# 65 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: Hello!\n"
# 66 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You are starting to have the\l"
# 67 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "attitude of a Champion, {PLAYER}!\p"
# 68 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "It's time for your POKéDEX to\n"
# 69 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "match who you are.\p"
# 70 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Let me see your POKéDEX for a\n"
# 71 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "second.\p"
# 72 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I'll upgrade your POKéDEX with the\n"
# 73 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "National Mode.$"
# 74 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex2:
# 75 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 76 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "with the National Mode!$"
# 77 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex3:
# 78 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: It won't be easy to\n"
# 79 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "complete the National POKéDEX...\p"
# 80 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "However, I'm sure you will make\n"
# 81 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "honest attempt on our behalf!$"
# 82 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex4:
# 83 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Oh, time flies!\p"
# 84 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I have a radio show to record at\n"
# 85 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Goldenrod Radio Tower.\p"
# 86 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You must be heading for Sevii.\p"
# 87 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I hear strong trainers are\n"
# 88 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "gathering there. How exciting!$"
# 89 "data/maps/OlivineCity_PortInside/scripts.pory"

# 90 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_CooltrainerF::
# 91 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
# 92 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 93 "data/maps/OlivineCity_PortInside/scripts.pory"

# 94 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher1::
# 95 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
# 96 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 97 "data/maps/OlivineCity_PortInside/scripts.pory"

# 98 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher2::
# 99 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
# 100 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 101 "data/maps/OlivineCity_PortInside/scripts.pory"

# 102 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Youngster::
# 103 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
# 104 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 105 "data/maps/OlivineCity_PortInside/scripts.pory"

# 106 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor::
# 107 "data/maps/OlivineCity_PortInside/scripts.pory"
	lock
# 108 "data/maps/OlivineCity_PortInside/scripts.pory"
	faceplayer
# 109 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_set FLAG_DEFEATED_RED, OlivinePort_EventScript_Sailor_AfterRed
# 110 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
# 111 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
# 112 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
# 113 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_SS_TICKET
# 114 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
# 115 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
# 116 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 117 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 118 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 119 "data/maps/OlivineCity_PortInside/scripts.pory"

# 120 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_AfterKanto::
# 121 "data/maps/OlivineCity_PortInside/scripts.pory"
	message OlivinePort_Text_WhereSail
# 122 "data/maps/OlivineCity_PortInside/scripts.pory"
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
# 123 "data/maps/OlivineCity_PortInside/scripts.pory"
	switch VAR_RESULT
# 124 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 0, OlivinePort_EventScript_ChoseVermilion
# 125 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
# 126 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 2, OlivinePort_EventScript_ChoseBirthIsland
# 127 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
# 128 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 4, OlivinePort_EventScript_Sailor_Refused
# 129 "data/maps/OlivineCity_PortInside/scripts.pory"
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
# 130 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 131 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 132 "data/maps/OlivineCity_PortInside/scripts.pory"

# 133 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_AfterRed::
# 134 "data/maps/OlivineCity_PortInside/scripts.pory"
	message OlivinePort_Text_WhereSail
# 135 "data/maps/OlivineCity_PortInside/scripts.pory"
	multichoice 20, 0, MULTI_OLIVINE_HARBOR_RED, FALSE
# 136 "data/maps/OlivineCity_PortInside/scripts.pory"
	switch VAR_RESULT
# 137 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 0, OlivinePort_EventScript_ChoseVermilion
# 138 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
# 139 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 2, OlivinePort_EventScript_ChoseBirthIsland
# 140 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
# 141 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
# 142 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 5, OlivinePort_EventScript_Sailor_Refused
# 143 "data/maps/OlivineCity_PortInside/scripts.pory"
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
# 144 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 145 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 146 "data/maps/OlivineCity_PortInside/scripts.pory"

# 147 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseBattleFrontier::
# 148 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 149 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 150 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 151 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 20, 67
# 152 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 153 "data/maps/OlivineCity_PortInside/scripts.pory"
	end	
# 154 "data/maps/OlivineCity_PortInside/scripts.pory"

# 155 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseVermilion::
# 156 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 157 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 158 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_SS_TICKET
# 159 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
# 160 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 161 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 162 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
# 163 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 164 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 165 "data/maps/OlivineCity_PortInside/scripts.pory"

# 166 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseSouthernIsland::
# 167 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 168 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 169 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_EON_TICKET
# 170 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
# 171 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 172 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 173 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 174 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 175 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 176 "data/maps/OlivineCity_PortInside/scripts.pory"

# 177 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseBirthIsland::
# 178 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 179 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 180 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 181 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
# 182 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 183 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 184 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 13, 23
# 185 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 186 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 187 "data/maps/OlivineCity_PortInside/scripts.pory"

# 188 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseFarawayIsland::
# 189 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 190 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 191 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_OLD_SEA_MAP
# 192 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
# 193 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 194 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 195 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 196 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 197 "data/maps/OlivineCity_PortInside/scripts.pory"
	end	
# 198 "data/maps/OlivineCity_PortInside/scripts.pory"

# 199 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_MaidenVoyage::
# 200 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
# 201 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 202 "data/maps/OlivineCity_PortInside/scripts.pory"
	setvar VAR_SSAQUA_STATE, 1
# 203 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 204 "data/maps/OlivineCity_PortInside/scripts.pory"
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER
# 205 "data/maps/OlivineCity_PortInside/scripts.pory"

# 206 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_SAILOR
# 207 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER
# 208 "data/maps/OlivineCity_PortInside/scripts.pory"

# 209 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_SSAQUA_1F, 29, 3
# 210 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 211 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 212 "data/maps/OlivineCity_PortInside/scripts.pory"

# 213 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_EnterShip::
# 214 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
# 215 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 216 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 217 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
# 218 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 219 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 220 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
# 221 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 222 "data/maps/OlivineCity_PortInside/scripts.pory"
	special SpawnCameraObject
# 223 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 224 "data/maps/OlivineCity_PortInside/scripts.pory"
	removeobject OBJ_EVENT_ID_PLAYER
# 225 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 226 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
# 227 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
# 228 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement LOCALID_OLIVINEPORT_BOAT
# 229 "data/maps/OlivineCity_PortInside/scripts.pory"
	setrespawn HEAL_LOCATION_OLIVINE_CITY
# 230 "data/maps/OlivineCity_PortInside/scripts.pory"
	return
# 231 "data/maps/OlivineCity_PortInside/scripts.pory"

# 232 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_Refused::
# 233 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
# 234 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 235 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 236 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 237 "data/maps/OlivineCity_PortInside/scripts.pory"

# 238 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_NoCredentials::
# 239 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
# 240 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 241 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 242 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 243 "data/maps/OlivineCity_PortInside/scripts.pory"

# 244 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_SailorEnterBoat:
# 245 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 246 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 247 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 248 "data/maps/OlivineCity_PortInside/scripts.pory"

# 249 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_PlayerEnterBoat:
# 250 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 251 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 252 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_down
# 253 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 254 "data/maps/OlivineCity_PortInside/scripts.pory"

# 255 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_BoatLeave:
# 256 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 257 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 258 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 259 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 260 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 261 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 262 "data/maps/OlivineCity_PortInside/scripts.pory"

# 263 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoPass:
# 264 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 265 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}…\p"
# 266 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no {STR_VAR_1}!\p"
# 267 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 268 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only if you have an\l"
# 269 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}.$"
# 270 "data/maps/OlivineCity_PortInside/scripts.pory"

# 271 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorGetOnBoard:
# 272 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We're departing soon.\n"
# 273 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Please get on board.$"
# 274 "data/maps/OlivineCity_PortInside/scripts.pory"

# 275 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CantBoard:
# 276 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry. You can't board now.$"
# 277 "data/maps/OlivineCity_PortInside/scripts.pory"

# 278 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_WhereSail:
# 279 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Where would you like to sail?$"
# 280 "data/maps/OlivineCity_PortInside/scripts.pory"

# 281 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskBoard:
# 282 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Welcome to Fast Ship S.S.Aqua.\p"
# 283 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Will you be boarding today?$"
# 284 "data/maps/OlivineCity_PortInside/scripts.pory"

# 285 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskTicket:
# 286 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "May I see your S.S.Ticket?$"
# 287 "data/maps/OlivineCity_PortInside/scripts.pory"

# 288 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_ComeAgain:
# 289 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We hope to see you again!$"
# 290 "data/maps/OlivineCity_PortInside/scripts.pory"

# 291 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FlashTicket:
# 292 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} flashed the S.S.Ticket.\p"
# 293 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "That's it. Thank you!$"
# 294 "data/maps/OlivineCity_PortInside/scripts.pory"

# 295 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoTicket:
# 296 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 297 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Ticket…\p"
# 298 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no Ticket!\p"
# 299 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 300 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only\l"
# 301 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "if you have an S.S.Ticket.$"
# 302 "data/maps/OlivineCity_PortInside/scripts.pory"

# 303 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru1:
# 304 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Mareanie are easy to catch here.\p"
# 305 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "They're kind of rare elsewhere.$"
# 306 "data/maps/OlivineCity_PortInside/scripts.pory"

# 307 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru2:
# 308 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "How many Rods do you have?\p"
# 309 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Different Rods catch different\n"
# 310 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Pokémon.$"
# 311 "data/maps/OlivineCity_PortInside/scripts.pory"

# 312 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_Youngster:
# 313 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Aqua uses jets to skim\n"
# 314 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "over the waves!$"
# 315 "data/maps/OlivineCity_PortInside/scripts.pory"

# 316 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CooltrainerF:
# 317 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "There are lots of Pokémon in Kanto.\p"
# 318 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "I wish I could go…$"
# 319 "data/maps/OlivineCity_PortInside/scripts.pory"

# 320 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorBeforeHOF:
# 321 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We don't want you to fall into the\n"
# 322 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "sea, so you're not allowed in.$"

PortInsideOak::
# 326 "data/maps/OlivineCity_PortInside/scripts.pory"
	lock
# 327 "data/maps/OlivineCity_PortInside/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 328 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_PIN
# 329 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
# 330 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 331 "data/maps/OlivineCity_PortInside/scripts.pory"
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
# 332 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox PortInsideOak_Text_0
# 341 "data/maps/OlivineCity_PortInside/scripts.pory"
	giveegg SPECIES_KUBFU
# 342 "data/maps/OlivineCity_PortInside/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 343 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox PortInsideOak_Text_1
# 344 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitfanfare
# 345 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox PortInsideOak_Text_2
# 348 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 30
# 349 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_PIN
# 350 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
# 351 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 352 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox PortInsideOak_Text_3
# 361 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 362 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
# 363 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, OlivineCity_PortInside_Movement_PlayerMoveOver
# 364 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 365 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
# 366 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 367 "data/maps/OlivineCity_PortInside/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
# 368 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 369 "data/maps/OlivineCity_PortInside/scripts.pory"
	removeobject LOCALID_OLIVINEPORT_OAK
# 370 "data/maps/OlivineCity_PortInside/scripts.pory"
	fadedefaultbgm
# 371 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitse
# 372 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
	end


PortInsideOak_Text_0:
# 332 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: Hello!\n"
	.string "You are starting to have the\l"
	.string "attitude of a Champion, {PLAYER}!\l"
	.string "I hope you have been keeping up\l"
	.string "with your Pokédex!\p"
	.string "I have something to give you as\n"
	.string "a congratulationary gift for \l"
	.string "becoming a champion! No need to be shy!$"

PortInsideOak_Text_1:
# 343 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "{PLAYER} obtain a Mysterious Egg!$"

PortInsideOak_Text_2:
# 345 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "That's an egg for a Pokémon from the\n"
	.string "Galar region. I believe you can draw\l"
	.string "the full potential from it.$"

PortInsideOak_Text_3:
# 352 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Oh, time flies!\n"
	.string "I have a radio show to record at\l"
	.string "Goldenrod Radio Tower.\p"
	.string "You must be heading for Sevii.\n"
	.string "I hear strong trainers are\l"
	.string "gathering there. How exciting!\l"
	.string "I will be cheering for you from\l"
	.string "the sidelines. Take care!$"
