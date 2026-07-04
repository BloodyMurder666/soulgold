# 1 "data/maps/EcruteakCity/scripts.pory"

# 2 "data/maps/EcruteakCity/scripts.pory"
.set LOCALID_ECRUTEAK_GRAMPS, 4
# 3 "data/maps/EcruteakCity/scripts.pory"
.set LOCALID_ECRUTEK_SILVER, 33
# 4 "data/maps/EcruteakCity/scripts.pory"

# 5 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_MapScripts::
# 6 "data/maps/EcruteakCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
# 7 "data/maps/EcruteakCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 8 "data/maps/EcruteakCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EcruteakCity_OnLoad
# 9 "data/maps/EcruteakCity/scripts.pory"
	.byte 0
# 10 "data/maps/EcruteakCity/scripts.pory"

# 11 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_OnTransition::
# 12 "data/maps/EcruteakCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 13 "data/maps/EcruteakCity/scripts.pory"

# 14 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_OnTransition_SetTime::
# 15 "data/maps/EcruteakCity/scripts.pory"
	callnative SetTimeBasedEncounters
# 16 "data/maps/EcruteakCity/scripts.pory"
	end
# 17 "data/maps/EcruteakCity/scripts.pory"

# 18 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_OnLoad::
# 19 "data/maps/EcruteakCity/scripts.pory"
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
# 20 "data/maps/EcruteakCity/scripts.pory"
	end
# 21 "data/maps/EcruteakCity/scripts.pory"

# 22 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Test_Lugia::
# 23 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 1
# 24 "data/maps/EcruteakCity/scripts.pory"
	end
# 25 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Test_League::
# 26 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_COMPLETED_HO_OH, 4
# 27 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_COMPLETED_LUGIA, 4
# 28 "data/maps/EcruteakCity/scripts.pory"
	end
# 29 "data/maps/EcruteakCity/scripts.pory"

# 30 "data/maps/EcruteakCity/scripts.pory"

# 31 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Trigger::
# 32 "data/maps/EcruteakCity/scripts.pory"
	@flagheap
# 33 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_RELEASED_BEASTS
# 34 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_AMPHAROS_HEALED
# 35 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_BILL
# 36 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_DEFEATED_HO_OH
# 37 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_CAUGHT_HO_OH
# 38 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_DEFEATED_LUGIA
# 39 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_CAUGHT_LUGIA
# 40 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
# 41 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
# 42 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
# 43 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
# 44 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
# 45 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_CAUGHT_ENTEI
# 46 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_CAUGHT_RAIKOU
# 47 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_GOT_TM_SNATCH
# 48 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
# 49 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_GOT_TYROGUE
# 50 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_BEAT_KIYO
# 51 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
# 52 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 53 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
# 54 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_TINTOWER_GUARD
# 55 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
# 56 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 57 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_HO_OH
# 58 "data/maps/EcruteakCity/scripts.pory"

# 59 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_VISITED_ECRUTEAK_CITY
# 60 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ROUTE42_EUSINE
# 61 "data/maps/EcruteakCity/scripts.pory"

# 62 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
# 63 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
# 64 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 65 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ROUTE39_SHADOW
# 66 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 67 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_COMPLETED_HO_OH, 0
# 68 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_COMPLETED_LUGIA, 0
# 69 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
# 70 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_STATE, 1
# 71 "data/maps/EcruteakCity/scripts.pory"
	end
# 72 "data/maps/EcruteakCity/scripts.pory"

# 73 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Trigger_Silver::
# 74 "data/maps/EcruteakCity/scripts.pory"
	lockall
# 75 "data/maps/EcruteakCity/scripts.pory"
	opendoor 39, 40
# 76 "data/maps/EcruteakCity/scripts.pory"
	waitdooranim
# 77 "data/maps/EcruteakCity/scripts.pory"
	delay 10
# 78 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
# 79 "data/maps/EcruteakCity/scripts.pory"
	addobject LOCALID_ECRUTEK_SILVER
# 80 "data/maps/EcruteakCity/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 81 "data/maps/EcruteakCity/scripts.pory"
	playse SE_BANG
# 82 "data/maps/EcruteakCity/scripts.pory"
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
# 83 "data/maps/EcruteakCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
# 84 "data/maps/EcruteakCity/scripts.pory"
	message EcruteakCity_Text_Silver1
# 85 "data/maps/EcruteakCity/scripts.pory"
	
# 86 "data/maps/EcruteakCity/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 87 "data/maps/EcruteakCity/scripts.pory"
	waitmovement LOCALID_ECRUTEK_SILVER
# 88 "data/maps/EcruteakCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 89 "data/maps/EcruteakCity/scripts.pory"
	closedoor 39, 40
# 90 "data/maps/EcruteakCity/scripts.pory"
	waitdooranim
# 91 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
# 92 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 93 "data/maps/EcruteakCity/scripts.pory"
	playse SE_PIN
# 94 "data/maps/EcruteakCity/scripts.pory"
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
# 95 "data/maps/EcruteakCity/scripts.pory"
	delay 60
# 96 "data/maps/EcruteakCity/scripts.pory"
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
# 97 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
# 98 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 99 "data/maps/EcruteakCity/scripts.pory"

# 100 "data/maps/EcruteakCity/scripts.pory"
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
# 101 "data/maps/EcruteakCity/scripts.pory"
	waitmovement LOCALID_ECRUTEK_SILVER
# 102 "data/maps/EcruteakCity/scripts.pory"

# 103 "data/maps/EcruteakCity/scripts.pory"

# 104 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 105 "data/maps/EcruteakCity/scripts.pory"
	removeobject LOCALID_ECRUTEK_SILVER
# 106 "data/maps/EcruteakCity/scripts.pory"
	fadedefaultbgm
# 107 "data/maps/EcruteakCity/scripts.pory"

# 108 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 5
# 109 "data/maps/EcruteakCity/scripts.pory"
	releaseall
# 110 "data/maps/EcruteakCity/scripts.pory"
	end
# 111 "data/maps/EcruteakCity/scripts.pory"

# 112 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Movement_Silver1:
# 113 "data/maps/EcruteakCity/scripts.pory"
	delay_16
# 114 "data/maps/EcruteakCity/scripts.pory"
	lock_facing_direction
# 115 "data/maps/EcruteakCity/scripts.pory"
	walk_down
# 116 "data/maps/EcruteakCity/scripts.pory"
	unlock_facing_direction
# 117 "data/maps/EcruteakCity/scripts.pory"
	step_end
# 118 "data/maps/EcruteakCity/scripts.pory"

# 119 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Movement_Silver2:
# 120 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 121 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 122 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 123 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 124 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 125 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 126 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 127 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 128 "data/maps/EcruteakCity/scripts.pory"
	walk_left
# 129 "data/maps/EcruteakCity/scripts.pory"
	step_end
# 130 "data/maps/EcruteakCity/scripts.pory"

# 131 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Silver1:
# 132 "data/maps/EcruteakCity/scripts.pory"
	.string "Thud!!$"
# 133 "data/maps/EcruteakCity/scripts.pory"

# 134 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Silver2:
# 135 "data/maps/EcruteakCity/scripts.pory"
	.string "Silver: How...? How is this\n"
# 136 "data/maps/EcruteakCity/scripts.pory"
	.string "possible? How can I lose to mere\l"
# 137 "data/maps/EcruteakCity/scripts.pory"
	.string "Kimono Girls...?$"
# 138 "data/maps/EcruteakCity/scripts.pory"

# 139 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Silver3:
# 140 "data/maps/EcruteakCity/scripts.pory"
	.string "Silver: You were watching me,\n"
# 141 "data/maps/EcruteakCity/scripts.pory"
	.string "{PLAYER}...\p"
# 142 "data/maps/EcruteakCity/scripts.pory"
	.string "Yeah, that's right!\p"
# 143 "data/maps/EcruteakCity/scripts.pory"
	.string "I never thought defeating five\n"
# 144 "data/maps/EcruteakCity/scripts.pory"
	.string "Kimono Girls would be so hard...\p"
# 145 "data/maps/EcruteakCity/scripts.pory"
	.string "I got beaten to a pulp...\p"
# 146 "data/maps/EcruteakCity/scripts.pory"
	.string "...\p"
# 147 "data/maps/EcruteakCity/scripts.pory"
	.string "You must have come here for the\n"
# 148 "data/maps/EcruteakCity/scripts.pory"
	.string "same reason, right?\p"
# 149 "data/maps/EcruteakCity/scripts.pory"
	.string "Don't get cocky just because you\n"
# 150 "data/maps/EcruteakCity/scripts.pory"
	.string "defeated Team Rocket!\p"
# 151 "data/maps/EcruteakCity/scripts.pory"
	.string "These Kimono Girls are insanely\n"
# 152 "data/maps/EcruteakCity/scripts.pory"
	.string "strong.\p"
# 153 "data/maps/EcruteakCity/scripts.pory"
	.string "See if you can defeat them.\p"
# 154 "data/maps/EcruteakCity/scripts.pory"
	.string "But I'm not going back, I don't\n"
# 155 "data/maps/EcruteakCity/scripts.pory"
	.string "want to see you win.$"
# 156 "data/maps/EcruteakCity/scripts.pory"

# 157 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Gramps::
# 158 "data/maps/EcruteakCity/scripts.pory"
	lock
# 159 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 160 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
# 161 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 162 "data/maps/EcruteakCity/scripts.pory"
	release
# 163 "data/maps/EcruteakCity/scripts.pory"
	end
# 164 "data/maps/EcruteakCity/scripts.pory"
		
# 165 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Lass::
# 166 "data/maps/EcruteakCity/scripts.pory"
	lock
# 167 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 168 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
# 169 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 170 "data/maps/EcruteakCity/scripts.pory"
	release
# 171 "data/maps/EcruteakCity/scripts.pory"
	end
# 172 "data/maps/EcruteakCity/scripts.pory"

# 173 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Girl::
# 174 "data/maps/EcruteakCity/scripts.pory"
	lock
# 175 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 176 "data/maps/EcruteakCity/scripts.pory"
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
# 177 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
# 178 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 179 "data/maps/EcruteakCity/scripts.pory"
	release
# 180 "data/maps/EcruteakCity/scripts.pory"
	end
# 181 "data/maps/EcruteakCity/scripts.pory"

# 182 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Girl2::
# 183 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
# 184 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 185 "data/maps/EcruteakCity/scripts.pory"
	release
# 186 "data/maps/EcruteakCity/scripts.pory"
	end
# 187 "data/maps/EcruteakCity/scripts.pory"

# 188 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScrip_Man::
# 189 "data/maps/EcruteakCity/scripts.pory"
	lock
# 190 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 191 "data/maps/EcruteakCity/scripts.pory"
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
# 192 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
# 193 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 194 "data/maps/EcruteakCity/scripts.pory"
	release
# 195 "data/maps/EcruteakCity/scripts.pory"
	end
# 196 "data/maps/EcruteakCity/scripts.pory"

# 197 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScrip_Man2::
# 198 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
# 199 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 200 "data/maps/EcruteakCity/scripts.pory"
	release
# 201 "data/maps/EcruteakCity/scripts.pory"
	end
# 202 "data/maps/EcruteakCity/scripts.pory"

# 203 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Youngster::
# 204 "data/maps/EcruteakCity/scripts.pory"
	lock
# 205 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 206 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
# 207 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 208 "data/maps/EcruteakCity/scripts.pory"
	release
# 209 "data/maps/EcruteakCity/scripts.pory"
	end
# 210 "data/maps/EcruteakCity/scripts.pory"

# 211 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_SageRight::
# 212 "data/maps/EcruteakCity/scripts.pory"
	lock
# 213 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 214 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
# 215 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 216 "data/maps/EcruteakCity/scripts.pory"
	release
# 217 "data/maps/EcruteakCity/scripts.pory"
	end
# 218 "data/maps/EcruteakCity/scripts.pory"

# 219 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_SageTower::
# 220 "data/maps/EcruteakCity/scripts.pory"
	lock
# 221 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 222 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
# 223 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 224 "data/maps/EcruteakCity/scripts.pory"
	release
# 225 "data/maps/EcruteakCity/scripts.pory"
	end
# 226 "data/maps/EcruteakCity/scripts.pory"

# 227 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_SageGym::
# 228 "data/maps/EcruteakCity/scripts.pory"
	lock
# 229 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 230 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
# 231 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 232 "data/maps/EcruteakCity/scripts.pory"
	release
# 233 "data/maps/EcruteakCity/scripts.pory"
	end
# 234 "data/maps/EcruteakCity/scripts.pory"

# 235 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_TheaterSign::
# 236 "data/maps/EcruteakCity/scripts.pory"
	lock
# 237 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
# 238 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 239 "data/maps/EcruteakCity/scripts.pory"
	release
# 240 "data/maps/EcruteakCity/scripts.pory"
	end	
# 241 "data/maps/EcruteakCity/scripts.pory"

# 242 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_OfficeSign::
# 243 "data/maps/EcruteakCity/scripts.pory"
	lock
# 244 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
# 245 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 246 "data/maps/EcruteakCity/scripts.pory"
	release
# 247 "data/maps/EcruteakCity/scripts.pory"
	end	
# 248 "data/maps/EcruteakCity/scripts.pory"

# 249 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_BurnedSign::
# 250 "data/maps/EcruteakCity/scripts.pory"
	lock
# 251 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
# 252 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 253 "data/maps/EcruteakCity/scripts.pory"
	release
# 254 "data/maps/EcruteakCity/scripts.pory"
	end	
# 255 "data/maps/EcruteakCity/scripts.pory"

# 256 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_CitySign::
# 257 "data/maps/EcruteakCity/scripts.pory"
	lock
# 258 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
# 259 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 260 "data/maps/EcruteakCity/scripts.pory"
	release
# 261 "data/maps/EcruteakCity/scripts.pory"
	end	
# 262 "data/maps/EcruteakCity/scripts.pory"

# 263 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_GymSign::
# 264 "data/maps/EcruteakCity/scripts.pory"
	lock
# 265 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
# 266 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 267 "data/maps/EcruteakCity/scripts.pory"
	release
# 268 "data/maps/EcruteakCity/scripts.pory"
	end
# 269 "data/maps/EcruteakCity/scripts.pory"

# 270 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Eevee::
# 271 "data/maps/EcruteakCity/scripts.pory"
	lock
# 272 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 273 "data/maps/EcruteakCity/scripts.pory"
	waitse
# 274 "data/maps/EcruteakCity/scripts.pory"
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
# 275 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
# 276 "data/maps/EcruteakCity/scripts.pory"
	waitmoncry
# 277 "data/maps/EcruteakCity/scripts.pory"
	release
# 278 "data/maps/EcruteakCity/scripts.pory"
	end
# 279 "data/maps/EcruteakCity/scripts.pory"

# 280 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_EventScript_Vulpix::
# 281 "data/maps/EcruteakCity/scripts.pory"
	lock
# 282 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 283 "data/maps/EcruteakCity/scripts.pory"
	waitse
# 284 "data/maps/EcruteakCity/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 285 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
# 286 "data/maps/EcruteakCity/scripts.pory"
	waitmoncry
# 287 "data/maps/EcruteakCity/scripts.pory"
	release
# 288 "data/maps/EcruteakCity/scripts.pory"
	end
# 289 "data/maps/EcruteakCity/scripts.pory"

# 290 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Eevee:
# 291 "data/maps/EcruteakCity/scripts.pory"
	.string "Eevee: Veee!$"
# 292 "data/maps/EcruteakCity/scripts.pory"

# 293 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Vulpix:
# 294 "data/maps/EcruteakCity/scripts.pory"
	.string "Vulpix: Vullll Pix!$"
# 295 "data/maps/EcruteakCity/scripts.pory"

# 296 "data/maps/EcruteakCity/scripts.pory"

# 297 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_UnusedMissingDaughter:
# 298 "data/maps/EcruteakCity/scripts.pory"
	.string "Oh, no. Oh, no…\p"
# 299 "data/maps/EcruteakCity/scripts.pory"
	.string "My daughter is missing.\p"
# 300 "data/maps/EcruteakCity/scripts.pory"
	.string "No… She couldn't have gone to the\n"
# 301 "data/maps/EcruteakCity/scripts.pory"
	.string "Burned Tower.\p"
# 302 "data/maps/EcruteakCity/scripts.pory"
	.string "I told her not to go near it…\p"
# 303 "data/maps/EcruteakCity/scripts.pory"
	.string "People seem to disappear there…\p"
# 304 "data/maps/EcruteakCity/scripts.pory"
	.string "Oh, what should I do…?$"
# 305 "data/maps/EcruteakCity/scripts.pory"

# 306 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Gramps1:
# 307 "data/maps/EcruteakCity/scripts.pory"
	.string "Ecruteak used to have two towers:\n"
# 308 "data/maps/EcruteakCity/scripts.pory"
	.string "one each in the east and west.$"
# 309 "data/maps/EcruteakCity/scripts.pory"

# 310 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Gramps2:
# 311 "data/maps/EcruteakCity/scripts.pory"
	.string "Ah, child. Have you learned to\n"
# 312 "data/maps/EcruteakCity/scripts.pory"
	.string "dance like the Kimono Girls?\p"
# 313 "data/maps/EcruteakCity/scripts.pory"
	.string "If you go to their Dance Theater,\n"
# 314 "data/maps/EcruteakCity/scripts.pory"
	.string "an odd old man will give you\l"
# 315 "data/maps/EcruteakCity/scripts.pory"
	.string "something nice, I hear.$"
# 316 "data/maps/EcruteakCity/scripts.pory"

# 317 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Lass1:
# 318 "data/maps/EcruteakCity/scripts.pory"
	.string "I'm going to practice at the Dance\n"
# 319 "data/maps/EcruteakCity/scripts.pory"
	.string "Theater. Care to join me?$"
# 320 "data/maps/EcruteakCity/scripts.pory"

# 321 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Lass2:
# 322 "data/maps/EcruteakCity/scripts.pory"
	.string "The tower that used to be here…\p"
# 323 "data/maps/EcruteakCity/scripts.pory"
	.string "My grandma told me it used to be\n"
# 324 "data/maps/EcruteakCity/scripts.pory"
	.string "much taller.\p"
# 325 "data/maps/EcruteakCity/scripts.pory"
	.string "I hear there are ghosts in it now.$"
# 326 "data/maps/EcruteakCity/scripts.pory"

# 327 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Lass2_ReleasedBeasts:
# 328 "data/maps/EcruteakCity/scripts.pory"
	.string "Three big Pokémon ran off in different\n"
# 329 "data/maps/EcruteakCity/scripts.pory"
	.string "directions. What were they?$"
# 330 "data/maps/EcruteakCity/scripts.pory"

# 331 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Fisher:
# 332 "data/maps/EcruteakCity/scripts.pory"
	.string "I heard a rumor about Olivine\n"
# 333 "data/maps/EcruteakCity/scripts.pory"
	.string "Lighthouse.\p"
# 334 "data/maps/EcruteakCity/scripts.pory"
	.string "The Pokémon that serves as the\n"
# 335 "data/maps/EcruteakCity/scripts.pory"
	.string "beacon fell ill. Sounds like they\l"
# 336 "data/maps/EcruteakCity/scripts.pory"
	.string "are in trouble.$"
# 337 "data/maps/EcruteakCity/scripts.pory"

# 338 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Fisher_JasmineReturned:
# 339 "data/maps/EcruteakCity/scripts.pory"
	.string "The Pokémon at Olivine Lighthouse\n"
# 340 "data/maps/EcruteakCity/scripts.pory"
	.string "has been cured.\p"
# 341 "data/maps/EcruteakCity/scripts.pory"
	.string "Boats can safely sail out to sea at\n"
# 342 "data/maps/EcruteakCity/scripts.pory"
	.string "night again.$"
# 343 "data/maps/EcruteakCity/scripts.pory"

# 344 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Youngster:
# 345 "data/maps/EcruteakCity/scripts.pory"
	.string "I hear Pokémon are rampaging at the\n"
# 346 "data/maps/EcruteakCity/scripts.pory"
	.string "Lake Of Rage. I'd like to see that.$"
# 347 "data/maps/EcruteakCity/scripts.pory"

# 348 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Gramps3:
# 349 "data/maps/EcruteakCity/scripts.pory"
	.string "In the distant past…\p"
# 350 "data/maps/EcruteakCity/scripts.pory"
	.string "This tower burned in a fire. Three\n"
# 351 "data/maps/EcruteakCity/scripts.pory"
	.string "nameless Pokémon perished in it.\p"
# 352 "data/maps/EcruteakCity/scripts.pory"
	.string "A rainbow-colored Pokémon descended\n"
# 353 "data/maps/EcruteakCity/scripts.pory"
	.string "from the sky and resurrected them…\p"
# 354 "data/maps/EcruteakCity/scripts.pory"
	.string "It's a legend that has been passed\n"
# 355 "data/maps/EcruteakCity/scripts.pory"
	.string "down by Ecruteak Gym Leaders.\p"
# 356 "data/maps/EcruteakCity/scripts.pory"
	.string "Me?\p"
# 357 "data/maps/EcruteakCity/scripts.pory"
	.string "I was a trainer way back when.\n"
# 358 "data/maps/EcruteakCity/scripts.pory"
	.string "Hohoho!$"
# 359 "data/maps/EcruteakCity/scripts.pory"

# 360 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_SageGym:
# 361 "data/maps/EcruteakCity/scripts.pory"
	.string "Gym Leader Morty is not here right\n"
# 362 "data/maps/EcruteakCity/scripts.pory"
	.string "now. You may find him at the\l"
# 363 "data/maps/EcruteakCity/scripts.pory"
	.string "Burned Tower.$"
# 364 "data/maps/EcruteakCity/scripts.pory"

# 365 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_Sign:
# 366 "data/maps/EcruteakCity/scripts.pory"
	.string "Ecruteak City\n"
# 367 "data/maps/EcruteakCity/scripts.pory"
	.string "A Historical City\p"
# 368 "data/maps/EcruteakCity/scripts.pory"
	.string "Where the Past Meets the Present$"
# 369 "data/maps/EcruteakCity/scripts.pory"

# 370 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_TinTowerSign:
# 371 "data/maps/EcruteakCity/scripts.pory"
	.string "Tin Tower\p"
# 372 "data/maps/EcruteakCity/scripts.pory"
	.string "A legendary Pokémon is said to\n"
# 373 "data/maps/EcruteakCity/scripts.pory"
	.string "roost here.$"
# 374 "data/maps/EcruteakCity/scripts.pory"

# 375 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_OfficeSign:
# 376 "data/maps/EcruteakCity/scripts.pory"
	.string "Barrier Station to Tin Tower\p"
# 377 "data/maps/EcruteakCity/scripts.pory"
	.string "No Trespassing by the Unworthy.$"
# 378 "data/maps/EcruteakCity/scripts.pory"

# 379 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_GymSign:
# 380 "data/maps/EcruteakCity/scripts.pory"
	.string "Ecruteak City Pokémon Gym\n"
# 381 "data/maps/EcruteakCity/scripts.pory"
	.string "Leader: Morty\p"
# 382 "data/maps/EcruteakCity/scripts.pory"
	.string "The Mystic Seer of the Future$"
# 383 "data/maps/EcruteakCity/scripts.pory"

# 384 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_DanceTheaterSign:
# 385 "data/maps/EcruteakCity/scripts.pory"
	.string "Ecruteak Dance Theater$"
# 386 "data/maps/EcruteakCity/scripts.pory"

# 387 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_Text_BurnedTowerSign:
# 388 "data/maps/EcruteakCity/scripts.pory"
	.string "Burned Tower\p"
# 389 "data/maps/EcruteakCity/scripts.pory"
	.string "It was destroyed by a mysterious\n"
# 390 "data/maps/EcruteakCity/scripts.pory"
	.string "fire.\p"
# 391 "data/maps/EcruteakCity/scripts.pory"
	.string "Please stay away, as it is unsafe.$"

EcruteakCity_RivalPostBattle::
# 395 "data/maps/EcruteakCity/scripts.pory"
	lock
# 396 "data/maps/EcruteakCity/scripts.pory"
	faceplayer
# 397 "data/maps/EcruteakCity/scripts.pory"
	createfieldmugshotrival
# 398 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_RivalPostBattle_Text_0
# 409 "data/maps/EcruteakCity/scripts.pory"
	removefieldmugshot
# 410 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 411 "data/maps/EcruteakCity/scripts.pory"
	moveobjecttocoords LOCALID_ECRUTEAK_RIVAL, 8, 35, DIR_WEST
# 412 "data/maps/EcruteakCity/scripts.pory"
	waitmovement 0
# 413 "data/maps/EcruteakCity/scripts.pory"
	delay 60
# 414 "data/maps/EcruteakCity/scripts.pory"
	applymovement LOCALID_ECRUTEAK_RIVAL, EcruteakCity_RivalPostBattle_Movement_0
# 415 "data/maps/EcruteakCity/scripts.pory"
	delay 30
# 416 "data/maps/EcruteakCity/scripts.pory"
	createfieldmugshotrival
# 417 "data/maps/EcruteakCity/scripts.pory"
	msgbox EcruteakCity_RivalPostBattle_Text_1
# 419 "data/maps/EcruteakCity/scripts.pory"
	removefieldmugshot
# 420 "data/maps/EcruteakCity/scripts.pory"
	closemessage
# 421 "data/maps/EcruteakCity/scripts.pory"
	applymovement LOCALID_ECRUTEAK_RIVAL, EcruteakCity_RivalPostBattle_Movement_1
# 422 "data/maps/EcruteakCity/scripts.pory"
	waitmovement 0
# 423 "data/maps/EcruteakCity/scripts.pory"
	playse SE_EXIT
# 424 "data/maps/EcruteakCity/scripts.pory"
	delay 30
# 425 "data/maps/EcruteakCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 8
# 426 "data/maps/EcruteakCity/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_RIVAL
# 427 "data/maps/EcruteakCity/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_RIVAL
# 428 "data/maps/EcruteakCity/scripts.pory"
	removeobject LOCALID_ECRUTEAK_RIVAL
# 429 "data/maps/EcruteakCity/scripts.pory"
	release
	end


# 414 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_RivalPostBattle_Movement_0:
# 414 "data/maps/EcruteakCity/scripts.pory"
	face_right
	step_end

# 421 "data/maps/EcruteakCity/scripts.pory"
EcruteakCity_RivalPostBattle_Movement_1:
# 421 "data/maps/EcruteakCity/scripts.pory"
	face_left
	step_end

EcruteakCity_RivalPostBattle_Text_0:
# 398 "data/maps/EcruteakCity/scripts.pory"
	.string "What's up {PLAYER}?\p"
	.string "Mowing down more gyms left and right?\p"
	.string "Same as always. You're on a roll,\n"
	.string "woohoo.\p"
	.string "I can't even beat Morty yet...\p"
	.string "I'm going to train in Olivine for a while.\n"
	.string "Don't wait up.$"

EcruteakCity_RivalPostBattle_Text_1:
# 417 "data/maps/EcruteakCity/scripts.pory"
	.string "...You're doing really well.\n"
	.string "I mean that.$"
