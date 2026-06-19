# 1 "data/maps/OlivineCity_PortInside/scripts.pory"

# 2 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_MapScripts::
# 3 "data/maps/OlivineCity_PortInside/scripts.pory"
	.byte 0
# 4 "data/maps/OlivineCity_PortInside/scripts.pory"

# 5 "data/maps/OlivineCity_PortInside/scripts.pory"

# 6 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakFixDex:
# 7 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 8 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 9 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 10 "data/maps/OlivineCity_PortInside/scripts.pory"

# 11 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_PlayerMoveOver:
# 12 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 13 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_left
# 14 "data/maps/OlivineCity_PortInside/scripts.pory"
	face_right
# 15 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 16 "data/maps/OlivineCity_PortInside/scripts.pory"

# 17 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakLeave:
# 18 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 19 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 20 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 21 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 22 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 23 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 24 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 25 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 26 "data/maps/OlivineCity_PortInside/scripts.pory"

# 27 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex1:
# 28 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: Hello!\n"
# 29 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You are starting to have the\l"
# 30 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "attitude of a Champion, {PLAYER}!\p"
# 31 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "It's time for your Pokédex to\n"
# 32 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "match who you are.\p"
# 33 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Let me see your Pokédex for a\n"
# 34 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "second.\p"
# 35 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I'll upgrade your Pokédex with the\n"
# 36 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "National Mode.$"
# 37 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex2:
# 38 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "{PLAYER}'s Pokédex was upgraded\n"
# 39 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "with the National Mode!$"
# 40 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex3:
# 41 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: It won't be easy to\n"
# 42 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "complete the National Pokédex...\p"
# 43 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "However, I'm sure you will make\n"
# 44 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "honest attempt on our behalf!$"
# 45 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex4:
# 46 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Oh, time flies!\p"
# 47 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I have a radio show to record at\n"
# 48 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Goldenrod Radio Tower.\p"
# 49 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You must be heading for Sevii.\p"
# 50 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I hear strong trainers are\n"
# 51 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "gathering there. How exciting!$"
# 52 "data/maps/OlivineCity_PortInside/scripts.pory"

# 53 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_CooltrainerF::
# 54 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
# 55 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 56 "data/maps/OlivineCity_PortInside/scripts.pory"

# 57 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher1::
# 58 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
# 59 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 60 "data/maps/OlivineCity_PortInside/scripts.pory"

# 61 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher2::
# 62 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
# 63 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 64 "data/maps/OlivineCity_PortInside/scripts.pory"

# 65 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Youngster::
# 66 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
# 67 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 68 "data/maps/OlivineCity_PortInside/scripts.pory"

# 69 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor::
# 70 "data/maps/OlivineCity_PortInside/scripts.pory"
	lock
# 71 "data/maps/OlivineCity_PortInside/scripts.pory"
	faceplayer
# 72 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_set FLAG_DEFEATED_MTSILVER_RIVAL, OlivinePort_EventScript_Sailor_AfterRed
# 73 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
# 74 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
# 75 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
# 76 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_SS_TICKET
# 77 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
# 78 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
# 79 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 80 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 81 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 82 "data/maps/OlivineCity_PortInside/scripts.pory"

# 83 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_AfterKanto::
# 84 "data/maps/OlivineCity_PortInside/scripts.pory"
	message OlivinePort_Text_WhereSail
# 85 "data/maps/OlivineCity_PortInside/scripts.pory"
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
# 86 "data/maps/OlivineCity_PortInside/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 0, OlivinePort_EventScript_ChoseVermilion
# 88 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
# 89 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 2, OlivinePort_EventScript_ChoseBirthIsland
# 90 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
# 91 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 4, OlivinePort_EventScript_Sailor_Refused
# 92 "data/maps/OlivineCity_PortInside/scripts.pory"
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
# 93 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 94 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 95 "data/maps/OlivineCity_PortInside/scripts.pory"

# 96 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_AfterRed::
# 97 "data/maps/OlivineCity_PortInside/scripts.pory"
	message OlivinePort_Text_WhereSail
# 98 "data/maps/OlivineCity_PortInside/scripts.pory"
	multichoice 20, 0, MULTI_OLIVINE_HARBOR_RED, FALSE
# 99 "data/maps/OlivineCity_PortInside/scripts.pory"
	switch VAR_RESULT
# 100 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 0, OlivinePort_EventScript_ChoseVermilion
# 101 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
# 102 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 2, OlivinePort_EventScript_ChoseBirthIsland
# 103 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
# 104 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
# 105 "data/maps/OlivineCity_PortInside/scripts.pory"
	case 5, OlivinePort_EventScript_Sailor_Refused
# 106 "data/maps/OlivineCity_PortInside/scripts.pory"
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
# 107 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 108 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 109 "data/maps/OlivineCity_PortInside/scripts.pory"

# 110 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseBattleFrontier::
# 111 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 112 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 113 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 114 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 20, 67
# 115 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 116 "data/maps/OlivineCity_PortInside/scripts.pory"
	end	
# 117 "data/maps/OlivineCity_PortInside/scripts.pory"

# 118 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseVermilion::
# 119 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 120 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 121 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_SS_TICKET
# 122 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
# 123 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 124 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 125 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
# 126 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 127 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 128 "data/maps/OlivineCity_PortInside/scripts.pory"

# 129 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseSouthernIsland::
# 130 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 131 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 132 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_EON_TICKET
# 133 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
# 134 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 135 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 136 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
# 137 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 138 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 139 "data/maps/OlivineCity_PortInside/scripts.pory"

# 140 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseBirthIsland::
# 141 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 142 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 143 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 144 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
# 145 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 146 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 147 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 13, 23
# 148 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 149 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 150 "data/maps/OlivineCity_PortInside/scripts.pory"

# 151 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_ChoseFarawayIsland::
# 152 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 153 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 154 "data/maps/OlivineCity_PortInside/scripts.pory"
	checkitem ITEM_OLD_SEA_MAP
# 155 "data/maps/OlivineCity_PortInside/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
# 156 "data/maps/OlivineCity_PortInside/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
# 157 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 158 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
# 159 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 160 "data/maps/OlivineCity_PortInside/scripts.pory"
	end	
# 161 "data/maps/OlivineCity_PortInside/scripts.pory"

# 162 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_MaidenVoyage::
# 163 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
# 164 "data/maps/OlivineCity_PortInside/scripts.pory"
	call OlivinePort_EventScript_EnterShip
# 165 "data/maps/OlivineCity_PortInside/scripts.pory"
	setvar VAR_SSAQUA_STATE, 1
# 166 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 167 "data/maps/OlivineCity_PortInside/scripts.pory"
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER
# 168 "data/maps/OlivineCity_PortInside/scripts.pory"

# 169 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_SAILOR
# 170 "data/maps/OlivineCity_PortInside/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER
# 171 "data/maps/OlivineCity_PortInside/scripts.pory"

# 172 "data/maps/OlivineCity_PortInside/scripts.pory"
	warpsilent MAP_SSAQUA_1F, 29, 3
# 173 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 174 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 175 "data/maps/OlivineCity_PortInside/scripts.pory"

# 176 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_EnterShip::
# 177 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
# 178 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 179 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 20
# 180 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
# 181 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 182 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 183 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
# 184 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement 0
# 185 "data/maps/OlivineCity_PortInside/scripts.pory"
	special SpawnCameraObject
# 186 "data/maps/OlivineCity_PortInside/scripts.pory"
	playse SE_EXIT
# 187 "data/maps/OlivineCity_PortInside/scripts.pory"
	removeobject OBJ_EVENT_ID_PLAYER
# 188 "data/maps/OlivineCity_PortInside/scripts.pory"
	delay 60
# 189 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
# 190 "data/maps/OlivineCity_PortInside/scripts.pory"
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
# 191 "data/maps/OlivineCity_PortInside/scripts.pory"
	waitmovement LOCALID_OLIVINEPORT_BOAT
# 192 "data/maps/OlivineCity_PortInside/scripts.pory"
	setrespawn HEAL_LOCATION_OLIVINE_CITY
# 193 "data/maps/OlivineCity_PortInside/scripts.pory"
	return
# 194 "data/maps/OlivineCity_PortInside/scripts.pory"

# 195 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_Refused::
# 196 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
# 197 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 198 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 199 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 200 "data/maps/OlivineCity_PortInside/scripts.pory"

# 201 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Sailor_NoCredentials::
# 202 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
# 203 "data/maps/OlivineCity_PortInside/scripts.pory"
	closemessage
# 204 "data/maps/OlivineCity_PortInside/scripts.pory"
	release
# 205 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 206 "data/maps/OlivineCity_PortInside/scripts.pory"

# 207 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_SailorEnterBoat:
# 208 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 209 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 210 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 211 "data/maps/OlivineCity_PortInside/scripts.pory"

# 212 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_PlayerEnterBoat:
# 213 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 214 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 215 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_down
# 216 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 217 "data/maps/OlivineCity_PortInside/scripts.pory"

# 218 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_BoatLeave:
# 219 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 220 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 221 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 222 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 223 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 224 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 225 "data/maps/OlivineCity_PortInside/scripts.pory"

# 226 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoPass:
# 227 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 228 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}…\p"
# 229 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no {STR_VAR_1}!\p"
# 230 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 231 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only if you have an\l"
# 232 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}.$"
# 233 "data/maps/OlivineCity_PortInside/scripts.pory"

# 234 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorGetOnBoard:
# 235 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We're departing soon.\n"
# 236 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Please get on board.$"
# 237 "data/maps/OlivineCity_PortInside/scripts.pory"

# 238 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CantBoard:
# 239 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry. You can't board now.$"
# 240 "data/maps/OlivineCity_PortInside/scripts.pory"

# 241 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_WhereSail:
# 242 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Where would you like to sail?$"
# 243 "data/maps/OlivineCity_PortInside/scripts.pory"

# 244 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskBoard:
# 245 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Welcome to Fast Ship S.S.Aqua.\p"
# 246 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Will you be boarding today?$"
# 247 "data/maps/OlivineCity_PortInside/scripts.pory"

# 248 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskTicket:
# 249 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "May I see your S.S.Ticket?$"
# 250 "data/maps/OlivineCity_PortInside/scripts.pory"

# 251 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_ComeAgain:
# 252 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We hope to see you again!$"
# 253 "data/maps/OlivineCity_PortInside/scripts.pory"

# 254 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FlashTicket:
# 255 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} flashed the S.S.Ticket.\p"
# 256 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "That's it. Thank you!$"
# 257 "data/maps/OlivineCity_PortInside/scripts.pory"

# 258 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoTicket:
# 259 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 260 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Ticket…\p"
# 261 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no Ticket!\p"
# 262 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 263 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only\l"
# 264 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "if you have an S.S.Ticket.$"
# 265 "data/maps/OlivineCity_PortInside/scripts.pory"

# 266 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru1:
# 267 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Mareanie are easy to catch here.\p"
# 268 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "They're kind of rare elsewhere.$"
# 269 "data/maps/OlivineCity_PortInside/scripts.pory"

# 270 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru2:
# 271 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "How many Rods do you have?\p"
# 272 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Different Rods catch different\n"
# 273 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Pokémon.$"
# 274 "data/maps/OlivineCity_PortInside/scripts.pory"

# 275 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_Youngster:
# 276 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Aqua uses jets to skim\n"
# 277 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "over the waves!$"
# 278 "data/maps/OlivineCity_PortInside/scripts.pory"

# 279 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CooltrainerF:
# 280 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "There are lots of Pokémon in Kanto.\p"
# 281 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "I wish I could go…$"
# 282 "data/maps/OlivineCity_PortInside/scripts.pory"

# 283 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorBeforeHOF:
# 284 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We don't want you to fall into the\n"
# 285 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "sea, so you're not allowed in.$"

OlivinePort_Sailor::
# 288 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Sailor_Text_0, MSGBOX_NPC
	return


OlivinePort_Sailor_Text_0:
# 288 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Sorry, but the ship is not going to\n"
	.string "leave anywhere anytime soon. Our\l"
	.string "engines exploded mysteriously.\l"
	.string "Strange, right?$"
