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
	callnative SetTimeBasedEncounters
# 17 "data/maps/OlivineCity/scripts.pory"
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
# 18 "data/maps/OlivineCity/scripts.pory"
	end
# 19 "data/maps/OlivineCity/scripts.pory"

# 20 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_ClearWeather::
# 21 "data/maps/OlivineCity/scripts.pory"
	setweather WEATHER_NONE
# 22 "data/maps/OlivineCity/scripts.pory"
	end
# 23 "data/maps/OlivineCity/scripts.pory"

# 24 "data/maps/OlivineCity/scripts.pory"
OlivineCity_OnFrame::
# 25 "data/maps/OlivineCity/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
# 26 "data/maps/OlivineCity/scripts.pory"
	.2byte 0
# 27 "data/maps/OlivineCity/scripts.pory"

# 28 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_BaobaCall::
# 29 "data/maps/OlivineCity/scripts.pory"
	lock
# 30 "data/maps/OlivineCity/scripts.pory"
	pokenavcall OlivineCity_Text_Baoba
# 31 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 32 "data/maps/OlivineCity/scripts.pory"
	delay 30
# 33 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
# 34 "data/maps/OlivineCity/scripts.pory"
	release
# 35 "data/maps/OlivineCity/scripts.pory"
	end
# 36 "data/maps/OlivineCity/scripts.pory"

# 37 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Baoba:
# 38 "data/maps/OlivineCity/scripts.pory"
	.string "{PLAYER}!\p"
# 39 "data/maps/OlivineCity/scripts.pory"
	.string "This is Warden Baoba.\p"
# 40 "data/maps/OlivineCity/scripts.pory"
	.string "Sorry to have kept you waiting.\n"
# 41 "data/maps/OlivineCity/scripts.pory"
	.string "We've finally opened the Safari\l"
# 42 "data/maps/OlivineCity/scripts.pory"
	.string "Zone!\p"
# 43 "data/maps/OlivineCity/scripts.pory"
	.string "Do you know where it is?\p"
# 44 "data/maps/OlivineCity/scripts.pory"
	.string "You know the Gate inside the cavern\n"
# 45 "data/maps/OlivineCity/scripts.pory"
	.string "in Cianwood City?\p"
# 46 "data/maps/OlivineCity/scripts.pory"
	.string "If you go through there and walk for\n"
# 47 "data/maps/OlivineCity/scripts.pory"
	.string "a short while, you should soon see\l"
# 48 "data/maps/OlivineCity/scripts.pory"
	.string "the Safari Zone!\p"
# 49 "data/maps/OlivineCity/scripts.pory"
	.string "We're a little out of the way, but\n"
# 50 "data/maps/OlivineCity/scripts.pory"
	.string "please come visit!$"
# 51 "data/maps/OlivineCity/scripts.pory"

# 52 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
# 53 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
# 54 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 55 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_VISITED_OLIVINE_CITY
# 56 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
# 57 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
# 58 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
# 59 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_GETFLY, 0
# 60 "data/maps/OlivineCity/scripts.pory"
	
# 61 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 1
# 62 "data/maps/OlivineCity/scripts.pory"

# 63 "data/maps/OlivineCity/scripts.pory"
	@cianwood flags
# 64 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SUICUNE_ENCOUNTERS, 1
# 65 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
# 66 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_CIANWOOD_EUSINE
# 67 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_CIANWOOD_CITY_STATE, 1
# 68 "data/maps/OlivineCity/scripts.pory"
	end
# 69 "data/maps/OlivineCity/scripts.pory"

# 70 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverTrigger::
# 71 "data/maps/OlivineCity/scripts.pory"
	lock
# 72 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_SILVER
# 73 "data/maps/OlivineCity/scripts.pory"
	opendoor 11, 27
# 74 "data/maps/OlivineCity/scripts.pory"
	addobject LOCALID_OLIVINE_SILVER
# 75 "data/maps/OlivineCity/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 76 "data/maps/OlivineCity/scripts.pory"
	delay 20 
# 77 "data/maps/OlivineCity/scripts.pory"
	closedoor 11, 27
# 78 "data/maps/OlivineCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 79 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
# 80 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
# 81 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
# 82 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
# 83 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 84 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
# 85 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
# 86 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
# 87 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
# 88 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 89 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 2
# 90 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 91 "data/maps/OlivineCity/scripts.pory"
	removeobject LOCALID_OLIVINE_SILVER
# 92 "data/maps/OlivineCity/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/OlivineCity/scripts.pory"
	release
# 94 "data/maps/OlivineCity/scripts.pory"
	end
# 95 "data/maps/OlivineCity/scripts.pory"

# 96 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer1::
# 97 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
# 98 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 99 "data/maps/OlivineCity/scripts.pory"
	return
# 100 "data/maps/OlivineCity/scripts.pory"

# 101 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer2::
# 102 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
# 103 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/OlivineCity/scripts.pory"
	return
# 105 "data/maps/OlivineCity/scripts.pory"

# 106 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer3::
# 107 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
# 108 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 109 "data/maps/OlivineCity/scripts.pory"
	return
# 110 "data/maps/OlivineCity/scripts.pory"

# 111 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust1::
# 112 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
# 113 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 114 "data/maps/OlivineCity/scripts.pory"
	return
# 115 "data/maps/OlivineCity/scripts.pory"

# 116 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust2::
# 117 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
# 118 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 119 "data/maps/OlivineCity/scripts.pory"
	return
# 120 "data/maps/OlivineCity/scripts.pory"

# 121 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer1:
# 122 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 123 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 124 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 125 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 126 "data/maps/OlivineCity/scripts.pory"
	step_end
# 127 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer2:
# 128 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 129 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 130 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 131 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 132 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 133 "data/maps/OlivineCity/scripts.pory"
	step_end
# 134 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer3:
# 135 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 136 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 137 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 138 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 139 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 140 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 141 "data/maps/OlivineCity/scripts.pory"
	step_end
# 142 "data/maps/OlivineCity/scripts.pory"

# 143 "data/maps/OlivineCity/scripts.pory"

# 144 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverLeave:
# 145 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 146 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 147 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 148 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 149 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 150 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 151 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 152 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 153 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 154 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 155 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 156 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 157 "data/maps/OlivineCity/scripts.pory"
	step_end
# 158 "data/maps/OlivineCity/scripts.pory"

# 159 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_SilverEncounter:
# 160 "data/maps/OlivineCity/scripts.pory"
	.string "You again?\n"
# 161 "data/maps/OlivineCity/scripts.pory"
	.string "There's no need to be alert.\p"
# 162 "data/maps/OlivineCity/scripts.pory"
	.string "I don't bother with wimps\n"
# 163 "data/maps/OlivineCity/scripts.pory"
	.string "like you.\p"
# 164 "data/maps/OlivineCity/scripts.pory"
	.string "Speaking of weaklings, the\n"
# 165 "data/maps/OlivineCity/scripts.pory"
	.string "city's Gym Leader isn't here,\l"
# 166 "data/maps/OlivineCity/scripts.pory"
	.string "and is supposedly taking care\l"
# 167 "data/maps/OlivineCity/scripts.pory"
	.string "of a sick Pokémon at the\l"
# 168 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse.\p"
# 169 "data/maps/OlivineCity/scripts.pory"
	.string "Humph! Boo-hoo!\n"
# 170 "data/maps/OlivineCity/scripts.pory"
	.string "Just let sick Pokémon go!\p"
# 171 "data/maps/OlivineCity/scripts.pory"
	.string "A Pokémon that can't battle\n"
# 172 "data/maps/OlivineCity/scripts.pory"
	.string "is worthless!\p"
# 173 "data/maps/OlivineCity/scripts.pory"
	.string "Why don't you go train at the\n"
# 174 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse?\p"
# 175 "data/maps/OlivineCity/scripts.pory"
	.string "Who knows? It may make you a\n"
# 176 "data/maps/OlivineCity/scripts.pory"
	.string "bit of a better Trainer!$"
# 177 "data/maps/OlivineCity/scripts.pory"

# 178 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor1::
# 179 "data/maps/OlivineCity/scripts.pory"
	lock
# 180 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 181 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
# 182 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 183 "data/maps/OlivineCity/scripts.pory"
	release
# 184 "data/maps/OlivineCity/scripts.pory"
	end
# 185 "data/maps/OlivineCity/scripts.pory"

# 186 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor2::
# 187 "data/maps/OlivineCity/scripts.pory"
	lock
# 188 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 189 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
# 190 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 191 "data/maps/OlivineCity/scripts.pory"
	release
# 192 "data/maps/OlivineCity/scripts.pory"
	end
# 193 "data/maps/OlivineCity/scripts.pory"

# 194 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Youngster::
# 195 "data/maps/OlivineCity/scripts.pory"
	lock
# 196 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 197 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
# 198 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 199 "data/maps/OlivineCity/scripts.pory"
	release
# 200 "data/maps/OlivineCity/scripts.pory"
	end
# 201 "data/maps/OlivineCity/scripts.pory"

# 202 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Machoke::
# 203 "data/maps/OlivineCity/scripts.pory"
	lock
# 204 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 205 "data/maps/OlivineCity/scripts.pory"
	waitse
# 206 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 207 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
# 208 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 209 "data/maps/OlivineCity/scripts.pory"
	release
# 210 "data/maps/OlivineCity/scripts.pory"
	end
# 211 "data/maps/OlivineCity/scripts.pory"

# 212 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sign::
# 213 "data/maps/OlivineCity/scripts.pory"
	lock
# 214 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
# 215 "data/maps/OlivineCity/scripts.pory"
	end
# 216 "data/maps/OlivineCity/scripts.pory"

# 217 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_PortSign::
# 218 "data/maps/OlivineCity/scripts.pory"
	lock
# 219 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
# 220 "data/maps/OlivineCity/scripts.pory"
	end
# 221 "data/maps/OlivineCity/scripts.pory"

# 222 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CafeSign::
# 223 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
# 224 "data/maps/OlivineCity/scripts.pory"
	end
# 225 "data/maps/OlivineCity/scripts.pory"

# 226 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_GymSign::
# 227 "data/maps/OlivineCity/scripts.pory"
	lock
# 228 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
# 229 "data/maps/OlivineCity/scripts.pory"
	end
# 230 "data/maps/OlivineCity/scripts.pory"

# 231 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_LighthouseSign::
# 232 "data/maps/OlivineCity/scripts.pory"
	lock
# 233 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
# 234 "data/maps/OlivineCity/scripts.pory"
	end
# 235 "data/maps/OlivineCity/scripts.pory"

# 236 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWoman::
# 237 "data/maps/OlivineCity/scripts.pory"
	lock
# 238 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 239 "data/maps/OlivineCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 240 "data/maps/OlivineCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
# 241 "data/maps/OlivineCity/scripts.pory"
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
# 242 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
# 243 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 244 "data/maps/OlivineCity/scripts.pory"
	release
# 245 "data/maps/OlivineCity/scripts.pory"
	end
# 246 "data/maps/OlivineCity/scripts.pory"

# 247 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanChamp::
# 248 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
# 249 "data/maps/OlivineCity/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 250 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 251 "data/maps/OlivineCity/scripts.pory"
	release
# 252 "data/maps/OlivineCity/scripts.pory"
	end
# 253 "data/maps/OlivineCity/scripts.pory"

# 254 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanAfter::
# 255 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
# 256 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 257 "data/maps/OlivineCity/scripts.pory"
	release
# 258 "data/maps/OlivineCity/scripts.pory"
	end
# 259 "data/maps/OlivineCity/scripts.pory"

# 260 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_CafeSign:
# 261 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Cafe\n"
# 262 "data/maps/OlivineCity/scripts.pory"
	.string "Where Strong Sailors Enjoy\l"
# 263 "data/maps/OlivineCity/scripts.pory"
	.string "Hearty Meals Of Strength$"
# 264 "data/maps/OlivineCity/scripts.pory"

# 265 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman1:
# 266 "data/maps/OlivineCity/scripts.pory"
	.string "My name is Mary!\p"
# 267 "data/maps/OlivineCity/scripts.pory"
	.string "Just kidding, but I love Mary's\n"
# 268 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!$"
# 269 "data/maps/OlivineCity/scripts.pory"

# 270 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman2:
# 271 "data/maps/OlivineCity/scripts.pory"
	.string "You must be {PLAYER}!!!\p"
# 272 "data/maps/OlivineCity/scripts.pory"
	.string "Oh my goodness! The champion!\p"
# 273 "data/maps/OlivineCity/scripts.pory"
	.string "I heard about you on Mary's\n"
# 274 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!\p"
# 275 "data/maps/OlivineCity/scripts.pory"
	.string "Here, take this!$"
# 276 "data/maps/OlivineCity/scripts.pory"

# 277 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman3:
# 278 "data/maps/OlivineCity/scripts.pory"
	.string "I can't believe I met the\n"
# 279 "data/maps/OlivineCity/scripts.pory"
	.string "champion!!!$"
# 280 "data/maps/OlivineCity/scripts.pory"

# 281 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor1:
# 282 "data/maps/OlivineCity/scripts.pory"
	.string "Dark roads are dangerous\n"
# 283 "data/maps/OlivineCity/scripts.pory"
	.string "at night.\p"
# 284 "data/maps/OlivineCity/scripts.pory"
	.string "But in the pitch-black of\n"
# 285 "data/maps/OlivineCity/scripts.pory"
	.string "night, the sea is even more\l"
# 286 "data/maps/OlivineCity/scripts.pory"
	.string "treacherous!\p"
# 287 "data/maps/OlivineCity/scripts.pory"
	.string "Without the beacon of the\n"
# 288 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse to guide it,\l"
# 289 "data/maps/OlivineCity/scripts.pory"
	.string "no ship can sail.$"
# 290 "data/maps/OlivineCity/scripts.pory"

# 291 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokegear:
# 292 "data/maps/OlivineCity/scripts.pory"
	.string "That thing you have--\n"
# 293 "data/maps/OlivineCity/scripts.pory"
	.string "it's a POKéGEAR, right?\l"
# 294 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, that's cool.$"
# 295 "data/maps/OlivineCity/scripts.pory"

# 296 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokedex:
# 297 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, you have a POKéDEX!\p"
# 298 "data/maps/OlivineCity/scripts.pory"
	.string "That is just so awesome.$"
# 299 "data/maps/OlivineCity/scripts.pory"

# 300 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor2:
# 301 "data/maps/OlivineCity/scripts.pory"
	.string "The league has Jasmine\n"
# 302 "data/maps/OlivineCity/scripts.pory"
	.string "pegged as the sixth\l"
# 303 "data/maps/OlivineCity/scripts.pory"
	.string "strongest Gym Leader!\p"
# 304 "data/maps/OlivineCity/scripts.pory"
	.string "Hah! That's a load of crud.\p"
# 305 "data/maps/OlivineCity/scripts.pory"
	.string "There's no way Pryce could\n"
# 306 "data/maps/OlivineCity/scripts.pory"
	.string "hurt Jasmine's Steel-type\l"
# 307 "data/maps/OlivineCity/scripts.pory"
	.string "Pokémon!\p"
# 308 "data/maps/OlivineCity/scripts.pory"
	.string "Bureaucracy if you ask me.\p"
# 309 "data/maps/OlivineCity/scripts.pory"
	.string "She's something to be feared,\n"
# 310 "data/maps/OlivineCity/scripts.pory"
	.string "that's for sure!$"
# 311 "data/maps/OlivineCity/scripts.pory"

# 312 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sign:
# 313 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City\p"
# 314 "data/maps/OlivineCity/scripts.pory"
	.string "The Port Closest to Foreign Lands$"
# 315 "data/maps/OlivineCity/scripts.pory"

# 316 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_PortSign:
# 317 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Port\n"
# 318 "data/maps/OlivineCity/scripts.pory"
	.string "Fast Ship Pier$"
# 319 "data/maps/OlivineCity/scripts.pory"

# 320 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_GymSign:
# 321 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City Pokémon Gym\n"
# 322 "data/maps/OlivineCity/scripts.pory"
	.string "Leader: Jasmine\p"
# 323 "data/maps/OlivineCity/scripts.pory"
	.string "The Steel-Clad Defense Girl$"
# 324 "data/maps/OlivineCity/scripts.pory"

# 325 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_LighthouseSign:
# 326 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Lighthouse\n"
# 327 "data/maps/OlivineCity/scripts.pory"
	.string "Also known as the Glitter\l"
# 328 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse$"
# 329 "data/maps/OlivineCity/scripts.pory"

# 330 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_BattleTowerSign:
# 331 "data/maps/OlivineCity/scripts.pory"
	.string "Battle Tower Ahead\n"
# 332 "data/maps/OlivineCity/scripts.pory"
	.string "Opening Now!$"
# 333 "data/maps/OlivineCity/scripts.pory"

# 334 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Machoke:
# 335 "data/maps/OlivineCity/scripts.pory"
	.string "Machoke: Cho!$"

OlivineCity_Littlegirl_Warf::
# 339 "data/maps/OlivineCity/scripts.pory"
	lock
# 340 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 341 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Littlegirl_Warf_Text_0
# 343 "data/maps/OlivineCity/scripts.pory"
	release
	end


MareanieOlivine::
# 348 "data/maps/OlivineCity/scripts.pory"
	lock
# 349 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 350 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MAREANIE, CRY_MODE_NORMAL
# 351 "data/maps/OlivineCity/scripts.pory"
	msgbox MareanieOlivine_Text_0
# 352 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 353 "data/maps/OlivineCity/scripts.pory"
	release
	end


OlivineSouvenirMart::
# 358 "data/maps/OlivineCity/scripts.pory"
	lock
# 359 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 360 "data/maps/OlivineCity/scripts.pory"
	message OlivineSouvenirMart_Text_0
# 361 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 362 "data/maps/OlivineCity/scripts.pory"
	pokemart SouvenirMart
# 363 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineSouvenirMart_Text_1
# 364 "data/maps/OlivineCity/scripts.pory"
	release
	end


	.align 2
# 368 "data/maps/OlivineCity/scripts.pory"
SouvenirMart:
# 369 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_STRANGE_SOUVENIR
# 370 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 371 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_NONE

OlivineCity_Littlegirl_Warf_Text_0:
# 341 "data/maps/OlivineCity/scripts.pory"
	.string "I'm feeding the Mareanie every day!\n"
	.string "They sometimes let me play with them!$"

MareanieOlivine_Text_0:
# 351 "data/maps/OlivineCity/scripts.pory"
	.string "Maree!$"

OlivineSouvenirMart_Text_0:
# 360 "data/maps/OlivineCity/scripts.pory"
	.string "Welcome! How may I help you?$"

OlivineSouvenirMart_Text_1:
# 363 "data/maps/OlivineCity/scripts.pory"
	.string "Come back soon!$"
