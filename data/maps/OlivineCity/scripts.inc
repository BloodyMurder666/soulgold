# 1 "data/maps/OlivineCity/scripts.pory"

# 2 "data/maps/OlivineCity/scripts.pory"
.set LOCALID_OLIVINE_SILVER, 4
# 3 "data/maps/OlivineCity/scripts.pory"

# 4 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScripts::
# 5 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
# 6 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 7 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
# 8 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OlivineCity_OnLoad
# 9 "data/maps/OlivineCity/scripts.pory"
	.byte 0
# 10 "data/maps/OlivineCity/scripts.pory"

# 11 "data/maps/OlivineCity/scripts.pory"
OlivineCity_OnLoad::
# 12 "data/maps/OlivineCity/scripts.pory"
	setrespawn HEAL_LOCATION_OLIVINE_CITY
# 13 "data/maps/OlivineCity/scripts.pory"
	end
# 14 "data/maps/OlivineCity/scripts.pory"

# 15 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_OnTransition::
# 16 "data/maps/OlivineCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data/maps/OlivineCity/scripts.pory"
	goto OlivineCity_MapScript_CheckWeather
# 18 "data/maps/OlivineCity/scripts.pory"

# 19 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_CheckWeather::
# 20 "data/maps/OlivineCity/scripts.pory"
	callnative SetTimeBasedEncounters
# 21 "data/maps/OlivineCity/scripts.pory"
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
# 22 "data/maps/OlivineCity/scripts.pory"
	end
# 23 "data/maps/OlivineCity/scripts.pory"

# 24 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_ClearWeather::
# 25 "data/maps/OlivineCity/scripts.pory"
	setweather WEATHER_NONE
# 26 "data/maps/OlivineCity/scripts.pory"
	end
# 27 "data/maps/OlivineCity/scripts.pory"

# 28 "data/maps/OlivineCity/scripts.pory"
OlivineCity_OnFrame::
# 29 "data/maps/OlivineCity/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
# 30 "data/maps/OlivineCity/scripts.pory"
	.2byte 0
# 31 "data/maps/OlivineCity/scripts.pory"

# 32 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_BaobaCall::
# 33 "data/maps/OlivineCity/scripts.pory"
	lock
# 34 "data/maps/OlivineCity/scripts.pory"
	pokenavcall OlivineCity_Text_Baoba
# 35 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 36 "data/maps/OlivineCity/scripts.pory"
	delay 30
# 37 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
# 38 "data/maps/OlivineCity/scripts.pory"
	release
# 39 "data/maps/OlivineCity/scripts.pory"
	end
# 40 "data/maps/OlivineCity/scripts.pory"

# 41 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Baoba:
# 42 "data/maps/OlivineCity/scripts.pory"
	.string "{PLAYER}!\p"
# 43 "data/maps/OlivineCity/scripts.pory"
	.string "This is Warden Baoba.\p"
# 44 "data/maps/OlivineCity/scripts.pory"
	.string "Sorry to have kept you waiting.\n"
# 45 "data/maps/OlivineCity/scripts.pory"
	.string "We've finally opened the Safari\l"
# 46 "data/maps/OlivineCity/scripts.pory"
	.string "Zone!\p"
# 47 "data/maps/OlivineCity/scripts.pory"
	.string "Do you know where it is?\p"
# 48 "data/maps/OlivineCity/scripts.pory"
	.string "You know the Gate inside the cavern\n"
# 49 "data/maps/OlivineCity/scripts.pory"
	.string "in Cianwood City?\p"
# 50 "data/maps/OlivineCity/scripts.pory"
	.string "If you go through there and walk for\n"
# 51 "data/maps/OlivineCity/scripts.pory"
	.string "a short while, you should soon see\l"
# 52 "data/maps/OlivineCity/scripts.pory"
	.string "the Safari Zone!\p"
# 53 "data/maps/OlivineCity/scripts.pory"
	.string "We're a little out of the way, but\n"
# 54 "data/maps/OlivineCity/scripts.pory"
	.string "please come visit!$"
# 55 "data/maps/OlivineCity/scripts.pory"

# 56 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
# 57 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
# 58 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 59 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_VISITED_OLIVINE_CITY
# 60 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
# 61 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
# 62 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
# 63 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_GETFLY, 0
# 64 "data/maps/OlivineCity/scripts.pory"
	
# 65 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 1
# 66 "data/maps/OlivineCity/scripts.pory"

# 67 "data/maps/OlivineCity/scripts.pory"
	@cianwood flags
# 68 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SUICUNE_ENCOUNTERS, 1
# 69 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
# 70 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_CIANWOOD_EUSINE
# 71 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_CIANWOOD_CITY_STATE, 1
# 72 "data/maps/OlivineCity/scripts.pory"
	end
# 73 "data/maps/OlivineCity/scripts.pory"

# 74 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverTrigger::
# 75 "data/maps/OlivineCity/scripts.pory"
	lock
# 76 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_SILVER
# 77 "data/maps/OlivineCity/scripts.pory"
	opendoor 11, 27
# 78 "data/maps/OlivineCity/scripts.pory"
	addobject LOCALID_OLIVINE_SILVER
# 79 "data/maps/OlivineCity/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 80 "data/maps/OlivineCity/scripts.pory"
	delay 20 
# 81 "data/maps/OlivineCity/scripts.pory"
	closedoor 11, 27
# 82 "data/maps/OlivineCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 83 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
# 84 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
# 85 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
# 86 "data/maps/OlivineCity/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 87 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
# 88 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 89 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
# 90 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
# 91 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
# 92 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
# 93 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 94 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 2
# 95 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 96 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_MAREANIES
# 97 "data/maps/OlivineCity/scripts.pory"
	removeobject LOCALID_OLIVINE_SILVER
# 98 "data/maps/OlivineCity/scripts.pory"
	fadedefaultbgm
# 99 "data/maps/OlivineCity/scripts.pory"
	release
# 100 "data/maps/OlivineCity/scripts.pory"
	end
# 101 "data/maps/OlivineCity/scripts.pory"

# 102 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer1::
# 103 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
# 104 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 105 "data/maps/OlivineCity/scripts.pory"
	return
# 106 "data/maps/OlivineCity/scripts.pory"

# 107 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer2::
# 108 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
# 109 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 110 "data/maps/OlivineCity/scripts.pory"
	return
# 111 "data/maps/OlivineCity/scripts.pory"

# 112 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer3::
# 113 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
# 114 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 115 "data/maps/OlivineCity/scripts.pory"
	return
# 116 "data/maps/OlivineCity/scripts.pory"

# 117 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust1::
# 118 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
# 119 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 120 "data/maps/OlivineCity/scripts.pory"
	return
# 121 "data/maps/OlivineCity/scripts.pory"

# 122 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust2::
# 123 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
# 124 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 125 "data/maps/OlivineCity/scripts.pory"
	return
# 126 "data/maps/OlivineCity/scripts.pory"

# 127 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer1:
# 128 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 129 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 130 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 131 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 132 "data/maps/OlivineCity/scripts.pory"
	step_end
# 133 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer2:
# 134 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 135 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 136 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 137 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 138 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 139 "data/maps/OlivineCity/scripts.pory"
	step_end
# 140 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer3:
# 141 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 142 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 143 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 144 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 145 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 146 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 147 "data/maps/OlivineCity/scripts.pory"
	step_end
# 148 "data/maps/OlivineCity/scripts.pory"

# 149 "data/maps/OlivineCity/scripts.pory"

# 150 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverLeave:
# 151 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 152 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 153 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 154 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 155 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 156 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 157 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 158 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 159 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 160 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 161 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 162 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 163 "data/maps/OlivineCity/scripts.pory"
	step_end
# 164 "data/maps/OlivineCity/scripts.pory"

# 165 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_SilverEncounter:
# 166 "data/maps/OlivineCity/scripts.pory"
	.string "You again?\n"
# 167 "data/maps/OlivineCity/scripts.pory"
	.string "There's no need to be alert.\p"
# 168 "data/maps/OlivineCity/scripts.pory"
	.string "I don't bother with wimps\n"
# 169 "data/maps/OlivineCity/scripts.pory"
	.string "like you.\p"
# 170 "data/maps/OlivineCity/scripts.pory"
	.string "Speaking of weaklings, the\n"
# 171 "data/maps/OlivineCity/scripts.pory"
	.string "city's Gym Leader isn't here,\l"
# 172 "data/maps/OlivineCity/scripts.pory"
	.string "and is supposedly taking care\l"
# 173 "data/maps/OlivineCity/scripts.pory"
	.string "of a sick Pokémon at the\l"
# 174 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse.\p"
# 175 "data/maps/OlivineCity/scripts.pory"
	.string "Humph! Boo-hoo!\n"
# 176 "data/maps/OlivineCity/scripts.pory"
	.string "Just let sick Pokémon go!\p"
# 177 "data/maps/OlivineCity/scripts.pory"
	.string "A Pokémon that can't battle\n"
# 178 "data/maps/OlivineCity/scripts.pory"
	.string "is worthless!\p"
# 179 "data/maps/OlivineCity/scripts.pory"
	.string "Why don't you go train at the\n"
# 180 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse?\p"
# 181 "data/maps/OlivineCity/scripts.pory"
	.string "Who knows? It may make you a\n"
# 182 "data/maps/OlivineCity/scripts.pory"
	.string "bit of a better Trainer!$"
# 183 "data/maps/OlivineCity/scripts.pory"

# 184 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor1::
# 185 "data/maps/OlivineCity/scripts.pory"
	lock
# 186 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 187 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
# 188 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 189 "data/maps/OlivineCity/scripts.pory"
	release
# 190 "data/maps/OlivineCity/scripts.pory"
	end
# 191 "data/maps/OlivineCity/scripts.pory"

# 192 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor2::
# 193 "data/maps/OlivineCity/scripts.pory"
	lock
# 194 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 195 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
# 196 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 197 "data/maps/OlivineCity/scripts.pory"
	release
# 198 "data/maps/OlivineCity/scripts.pory"
	end
# 199 "data/maps/OlivineCity/scripts.pory"

# 200 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Youngster::
# 201 "data/maps/OlivineCity/scripts.pory"
	lock
# 202 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 203 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
# 204 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 205 "data/maps/OlivineCity/scripts.pory"
	release
# 206 "data/maps/OlivineCity/scripts.pory"
	end
# 207 "data/maps/OlivineCity/scripts.pory"

# 208 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Machoke::
# 209 "data/maps/OlivineCity/scripts.pory"
	lock
# 210 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 211 "data/maps/OlivineCity/scripts.pory"
	waitse
# 212 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 213 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
# 214 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 215 "data/maps/OlivineCity/scripts.pory"
	release
# 216 "data/maps/OlivineCity/scripts.pory"
	end
# 217 "data/maps/OlivineCity/scripts.pory"

# 218 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sign::
# 219 "data/maps/OlivineCity/scripts.pory"
	lock
# 220 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
# 221 "data/maps/OlivineCity/scripts.pory"
	end
# 222 "data/maps/OlivineCity/scripts.pory"

# 223 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_PortSign::
# 224 "data/maps/OlivineCity/scripts.pory"
	lock
# 225 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
# 226 "data/maps/OlivineCity/scripts.pory"
	end
# 227 "data/maps/OlivineCity/scripts.pory"

# 228 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CafeSign::
# 229 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
# 230 "data/maps/OlivineCity/scripts.pory"
	end
# 231 "data/maps/OlivineCity/scripts.pory"

# 232 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_GymSign::
# 233 "data/maps/OlivineCity/scripts.pory"
	lock
# 234 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
# 235 "data/maps/OlivineCity/scripts.pory"
	end
# 236 "data/maps/OlivineCity/scripts.pory"

# 237 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_LighthouseSign::
# 238 "data/maps/OlivineCity/scripts.pory"
	lock
# 239 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
# 240 "data/maps/OlivineCity/scripts.pory"
	end
# 241 "data/maps/OlivineCity/scripts.pory"

# 242 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWoman::
# 243 "data/maps/OlivineCity/scripts.pory"
	lock
# 244 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 245 "data/maps/OlivineCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 246 "data/maps/OlivineCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
# 247 "data/maps/OlivineCity/scripts.pory"
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
# 248 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
# 249 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 250 "data/maps/OlivineCity/scripts.pory"
	release
# 251 "data/maps/OlivineCity/scripts.pory"
	end
# 252 "data/maps/OlivineCity/scripts.pory"

# 253 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanChamp::
# 254 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
# 255 "data/maps/OlivineCity/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 256 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 257 "data/maps/OlivineCity/scripts.pory"
	release
# 258 "data/maps/OlivineCity/scripts.pory"
	end
# 259 "data/maps/OlivineCity/scripts.pory"

# 260 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanAfter::
# 261 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
# 262 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 263 "data/maps/OlivineCity/scripts.pory"
	release
# 264 "data/maps/OlivineCity/scripts.pory"
	end
# 265 "data/maps/OlivineCity/scripts.pory"

# 266 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_CafeSign:
# 267 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Cafe\n"
# 268 "data/maps/OlivineCity/scripts.pory"
	.string "Where Strong Sailors Enjoy\l"
# 269 "data/maps/OlivineCity/scripts.pory"
	.string "Hearty Meals Of Strength$"
# 270 "data/maps/OlivineCity/scripts.pory"

# 271 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman1:
# 272 "data/maps/OlivineCity/scripts.pory"
	.string "My name is Mary!\p"
# 273 "data/maps/OlivineCity/scripts.pory"
	.string "Just kidding, but I love Mary's\n"
# 274 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!$"
# 275 "data/maps/OlivineCity/scripts.pory"

# 276 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman2:
# 277 "data/maps/OlivineCity/scripts.pory"
	.string "You must be {PLAYER}!!!\p"
# 278 "data/maps/OlivineCity/scripts.pory"
	.string "Oh my goodness! The champion!\p"
# 279 "data/maps/OlivineCity/scripts.pory"
	.string "I heard about you on Mary's\n"
# 280 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!\p"
# 281 "data/maps/OlivineCity/scripts.pory"
	.string "Here, take this!$"
# 282 "data/maps/OlivineCity/scripts.pory"

# 283 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman3:
# 284 "data/maps/OlivineCity/scripts.pory"
	.string "I can't believe I met the\n"
# 285 "data/maps/OlivineCity/scripts.pory"
	.string "champion!!!$"
# 286 "data/maps/OlivineCity/scripts.pory"

# 287 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor1:
# 288 "data/maps/OlivineCity/scripts.pory"
	.string "Dark roads are dangerous\n"
# 289 "data/maps/OlivineCity/scripts.pory"
	.string "at night.\p"
# 290 "data/maps/OlivineCity/scripts.pory"
	.string "But in the pitch-black of\n"
# 291 "data/maps/OlivineCity/scripts.pory"
	.string "night, the sea is even more\l"
# 292 "data/maps/OlivineCity/scripts.pory"
	.string "treacherous!\p"
# 293 "data/maps/OlivineCity/scripts.pory"
	.string "Without the beacon of the\n"
# 294 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse to guide it,\l"
# 295 "data/maps/OlivineCity/scripts.pory"
	.string "no ship can sail.$"
# 296 "data/maps/OlivineCity/scripts.pory"

# 297 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokegear:
# 298 "data/maps/OlivineCity/scripts.pory"
	.string "That thing you have--\n"
# 299 "data/maps/OlivineCity/scripts.pory"
	.string "it's a Pokégear, right?\l"
# 300 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, that's cool.$"
# 301 "data/maps/OlivineCity/scripts.pory"

# 302 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokedex:
# 303 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, you have a Pokédex!\p"
# 304 "data/maps/OlivineCity/scripts.pory"
	.string "That is just so awesome.$"
# 305 "data/maps/OlivineCity/scripts.pory"

# 306 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor2:
# 307 "data/maps/OlivineCity/scripts.pory"
	.string "The league has Jasmine\n"
# 308 "data/maps/OlivineCity/scripts.pory"
	.string "pegged as the sixth\l"
# 309 "data/maps/OlivineCity/scripts.pory"
	.string "strongest Gym Leader!\p"
# 310 "data/maps/OlivineCity/scripts.pory"
	.string "Hah! That's a load of crud.\p"
# 311 "data/maps/OlivineCity/scripts.pory"
	.string "There's no way Pryce could\n"
# 312 "data/maps/OlivineCity/scripts.pory"
	.string "hurt Jasmine's Steel-type\l"
# 313 "data/maps/OlivineCity/scripts.pory"
	.string "Pokémon!\p"
# 314 "data/maps/OlivineCity/scripts.pory"
	.string "Bureaucracy if you ask me.\p"
# 315 "data/maps/OlivineCity/scripts.pory"
	.string "She's something to be feared,\n"
# 316 "data/maps/OlivineCity/scripts.pory"
	.string "that's for sure!$"
# 317 "data/maps/OlivineCity/scripts.pory"

# 318 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sign:
# 319 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City\p"
# 320 "data/maps/OlivineCity/scripts.pory"
	.string "The Port Closest to Foreign Lands$"
# 321 "data/maps/OlivineCity/scripts.pory"

# 322 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_PortSign:
# 323 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Port\n"
# 324 "data/maps/OlivineCity/scripts.pory"
	.string "Fast Ship Pier$"
# 325 "data/maps/OlivineCity/scripts.pory"

# 326 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_GymSign:
# 327 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City Pokémon Gym\n"
# 328 "data/maps/OlivineCity/scripts.pory"
	.string "Leader: Jasmine\p"
# 329 "data/maps/OlivineCity/scripts.pory"
	.string "The Steel-Clad Defense Girl$"
# 330 "data/maps/OlivineCity/scripts.pory"

# 331 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_LighthouseSign:
# 332 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Lighthouse\n"
# 333 "data/maps/OlivineCity/scripts.pory"
	.string "Also known as the Glitter\l"
# 334 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse$"
# 335 "data/maps/OlivineCity/scripts.pory"

# 336 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_BattleTowerSign:
# 337 "data/maps/OlivineCity/scripts.pory"
	.string "Battle Tower Ahead\n"
# 338 "data/maps/OlivineCity/scripts.pory"
	.string "Opening Now!$"
# 339 "data/maps/OlivineCity/scripts.pory"

# 340 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Machoke:
# 341 "data/maps/OlivineCity/scripts.pory"
	.string "Machoke: Cho!$"

OlivineCity_Littlegirl_Warf::
# 345 "data/maps/OlivineCity/scripts.pory"
	lock
# 346 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 347 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Littlegirl_Warf_Text_0
# 349 "data/maps/OlivineCity/scripts.pory"
	release
	end


MareanieOlivine::
# 354 "data/maps/OlivineCity/scripts.pory"
	lock
# 355 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 356 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MAREANIE, CRY_MODE_NORMAL
# 357 "data/maps/OlivineCity/scripts.pory"
	msgbox MareanieOlivine_Text_0
# 358 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 359 "data/maps/OlivineCity/scripts.pory"
	release
	end


OlivineSouvenirMart::
# 364 "data/maps/OlivineCity/scripts.pory"
	lock
# 365 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 366 "data/maps/OlivineCity/scripts.pory"
	message OlivineSouvenirMart_Text_0
# 367 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 368 "data/maps/OlivineCity/scripts.pory"
	pokemart SouvenirMart
# 369 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineSouvenirMart_Text_1
# 370 "data/maps/OlivineCity/scripts.pory"
	release
	end


	.align 2
# 374 "data/maps/OlivineCity/scripts.pory"
SouvenirMart:
# 375 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_STRANGE_SOUVENIR
# 376 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 377 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_NONE

OlivineCity_RivalPier::
# 381 "data/maps/OlivineCity/scripts.pory"
	lock
# 382 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 383 "data/maps/OlivineCity/scripts.pory"
	createfieldmugshotrival
# 384 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_0
# 386 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_1
# 388 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_2
# 390 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_3
# 392 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_4
# 394 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_5
# 395 "data/maps/OlivineCity/scripts.pory"
	removefieldmugshot
# 396 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 397 "data/maps/OlivineCity/scripts.pory"
	moveobjecttocoords LOCALID_OLIVINE_RIVAL, 19, 49, DIR_NORTH
# 398 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 399 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 9
# 400 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_RIVAL
# 401 "data/maps/OlivineCity/scripts.pory"
	removeobject LOCALID_OLIVINE_RIVAL
# 402 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_ICEPATH_RIVAL
# 403 "data/maps/OlivineCity/scripts.pory"
	release
	end


OlivineCity_Littlegirl_Warf_Text_0:
# 347 "data/maps/OlivineCity/scripts.pory"
	.string "I'm feeding the Mareanie every day!\n"
	.string "They sometimes let me play with them!$"

MareanieOlivine_Text_0:
# 357 "data/maps/OlivineCity/scripts.pory"
	.string "Maree!$"

OlivineSouvenirMart_Text_0:
# 366 "data/maps/OlivineCity/scripts.pory"
	.string "Welcome! How may I help you?$"

OlivineSouvenirMart_Text_1:
# 369 "data/maps/OlivineCity/scripts.pory"
	.string "Come back soon!$"

OlivineCity_RivalPier_Text_0:
# 384 "data/maps/OlivineCity/scripts.pory"
	.string "Oh. \n"
	.string "Hey...$"

OlivineCity_RivalPier_Text_1:
# 386 "data/maps/OlivineCity/scripts.pory"
	.string "Do you ever think that some people are\n"
	.string "just not... built for this?$"

OlivineCity_RivalPier_Text_2:
# 388 "data/maps/OlivineCity/scripts.pory"
	.string "Like it comes naturally\n"
	.string "and for others it's just...$"

OlivineCity_RivalPier_Text_3:
# 390 "data/maps/OlivineCity/scripts.pory"
	.string "Never mind.\n"
	.string "It's a dumb question.$"

OlivineCity_RivalPier_Text_4:
# 392 "data/maps/OlivineCity/scripts.pory"
	.string "Jasmine's Gym is closed.\n"
	.string "You're already on it, I assume.$"

OlivineCity_RivalPier_Text_5:
# 394 "data/maps/OlivineCity/scripts.pory"
	.string "See you around.$"
