# 1 "data/maps/VioletCity/scripts.pory"

# 2 "data/maps/VioletCity/scripts.pory"
.set LOCALID_VIOLETCITY_EARL, 4
# 3 "data/maps/VioletCity/scripts.pory"
.set LOCALID_VIOLET_KIMONO, 31
# 4 "data/maps/VioletCity/scripts.pory"

# 5 "data/maps/VioletCity/scripts.pory"
VioletCity_MapScripts::
# 6 "data/maps/VioletCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
# 7 "data/maps/VioletCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_OnTransition
# 8 "data/maps/VioletCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 9 "data/maps/VioletCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VioletCity_OnLoad
# 10 "data/maps/VioletCity/scripts.pory"
	.byte 0
# 11 "data/maps/VioletCity/scripts.pory"

# 12 "data/maps/VioletCity/scripts.pory"
VioletCity_OnFrame::
# 13 "data/maps/VioletCity/scripts.pory"
	map_script_2 VAR_VIOLET_CITY_KIMONO_GIRL, 1, VioletCity_EventScript_Kimono_Girl
# 14 "data/maps/VioletCity/scripts.pory"
	map_script_2 VAR_VIOLET_CITY_STATE, 3, VioletCity_EventScript_ElmCall_Trigger
# 15 "data/maps/VioletCity/scripts.pory"
	.2byte 0
# 16 "data/maps/VioletCity/scripts.pory"

# 17 "data/maps/VioletCity/scripts.pory"
VioletCity_OnTransition::
# 18 "data/maps/VioletCity/scripts.pory"
	callnative SetTimeBasedEncounters
# 19 "data/maps/VioletCity/scripts.pory"
	end
# 20 "data/maps/VioletCity/scripts.pory"

# 21 "data/maps/VioletCity/scripts.pory"
VioletCity_OnLoad::
# 22 "data/maps/VioletCity/scripts.pory"
	setrespawn HEAL_LOCATION_VIOLET_CITY
# 23 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_VISITED_VIOLET_CITY
# 24 "data/maps/VioletCity/scripts.pory"
	end
# 25 "data/maps/VioletCity/scripts.pory"

# 26 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Trigger::
# 27 "data/maps/VioletCity/scripts.pory"
	@LOCAL FLAGHEAP
# 28 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_RECEIVED_TOGEPI_EGG
# 29 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_VIOLET_NPC_TRADE_COMPLETED
# 30 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 31 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_JOHTO_GYM_LEADERS
# 32 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HOOH_BROUGHT
# 33 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_OMANYTE_BROUGHT
# 34 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_AERODACTYL_BROUGHT
# 35 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_KABUTO_BROUGHT
# 36 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_SUDOWOODO
# 37 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_GOT_HARD_STONE
# 38 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_GOT_POISON_BARB
# 39 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
# 40 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_GOT_BLACK_GLASSES
# 41 "data/maps/VioletCity/scripts.pory"
	
# 42 "data/maps/VioletCity/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 0
# 43 "data/maps/VioletCity/scripts.pory"
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 0
# 44 "data/maps/VioletCity/scripts.pory"
	setvar VAR_RUINSOFALPH_STATE, 0
# 45 "data/maps/VioletCity/scripts.pory"
	
# 46 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_TRAINER_SCHOOL_EARL
# 47 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
# 48 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
# 49 "data/maps/VioletCity/scripts.pory"
	
# 50 "data/maps/VioletCity/scripts.pory"
	setvar VAR_SPROUT_TOWER, 0
# 51 "data/maps/VioletCity/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 1
# 52 "data/maps/VioletCity/scripts.pory"
	end
# 53 "data/maps/VioletCity/scripts.pory"

# 54 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Earl::
# 55 "data/maps/VioletCity/scripts.pory"
	lock
# 56 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 57 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
# 58 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 59 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 60 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_EarlAsksIfYouBeatFalkner MSGBOX_YESNO
# 61 "data/maps/VioletCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_EarlTrainerSchool
# 62 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_VeryNiceIndeed, MSGBOX_DEFAULT
# 63 "data/maps/VioletCity/scripts.pory"
	closemessage
# 64 "data/maps/VioletCity/scripts.pory"
	release
# 65 "data/maps/VioletCity/scripts.pory"
	end
# 66 "data/maps/VioletCity/scripts.pory"

# 67 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_EarlTrainerSchool::
# 68 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_FollowEarl, MSGBOX_DEFAULT
# 69 "data/maps/VioletCity/scripts.pory"
	closemessage
# 70 "data/maps/VioletCity/scripts.pory"
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
# 71 "data/maps/VioletCity/scripts.pory"
	switch VAR_FACING
# 72 "data/maps/VioletCity/scripts.pory"
	case DIR_NORTH, VioletCity_EventScript_EarlTrainerSchoolSouth
# 73 "data/maps/VioletCity/scripts.pory"
	case DIR_WEST, VioletCity_EventScript_EarlTrainerSchoolEast
# 74 "data/maps/VioletCity/scripts.pory"
	release
# 75 "data/maps/VioletCity/scripts.pory"
	end
# 76 "data/maps/VioletCity/scripts.pory"

# 77 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_EarlTrainerSchoolSouth::
# 78 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_South_Adjustment
# 79 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 80 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
# 81 "data/maps/VioletCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_South_Adjustment
# 82 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 83 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 84 "data/maps/VioletCity/scripts.pory"
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
# 85 "data/maps/VioletCity/scripts.pory"
	release
# 86 "data/maps/VioletCity/scripts.pory"
	end
# 87 "data/maps/VioletCity/scripts.pory"

# 88 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_EarlTrainerSchoolEast::
# 89 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_East_Adjustment
# 90 "data/maps/VioletCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_East_Adjustment
# 91 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 93 "data/maps/VioletCity/scripts.pory"
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
# 94 "data/maps/VioletCity/scripts.pory"
	release
# 95 "data/maps/VioletCity/scripts.pory"
	end
# 96 "data/maps/VioletCity/scripts.pory"

# 97 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_EarlTrainerSchoolTransition:
# 98 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Walk_To_School
# 99 "data/maps/VioletCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Walk_To_School
# 100 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 101 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 102 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
# 103 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/VioletCity/scripts.pory"
	turnobject LOCALID_VIOLETCITY_EARL, DIR_WEST
# 105 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_HereTeacherIAm, MSGBOX_DEFAULT
# 106 "data/maps/VioletCity/scripts.pory"
	closemessage
# 107 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Walk_Inside
# 108 "data/maps/VioletCity/scripts.pory"
	delay 20
# 109 "data/maps/VioletCity/scripts.pory"
	opendoor 39, 36
# 110 "data/maps/VioletCity/scripts.pory"
	waitdooranim
# 111 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 112 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_VIOLET_CITY_EARL
# 113 "data/maps/VioletCity/scripts.pory"
	removeobject LOCALID_VIOLETCITY_EARL
# 114 "data/maps/VioletCity/scripts.pory"
	closedoor 39, 36
# 115 "data/maps/VioletCity/scripts.pory"
	waitdooranim
# 116 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_TRAINER_SCHOOL_EARL
# 117 "data/maps/VioletCity/scripts.pory"
	fadedefaultbgm
# 118 "data/maps/VioletCity/scripts.pory"
	release
# 119 "data/maps/VioletCity/scripts.pory"
	end
# 120 "data/maps/VioletCity/scripts.pory"

# 121 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Youngster::
# 122 "data/maps/VioletCity/scripts.pory"
	lock
# 123 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 124 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Youngster, MSGBOX_DEFAULT
# 125 "data/maps/VioletCity/scripts.pory"
	closemessage
# 126 "data/maps/VioletCity/scripts.pory"
	release
# 127 "data/maps/VioletCity/scripts.pory"
	end
# 128 "data/maps/VioletCity/scripts.pory"

# 129 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Boy::
# 130 "data/maps/VioletCity/scripts.pory"
	lock
# 131 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 132 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Boy, MSGBOX_DEFAULT
# 133 "data/maps/VioletCity/scripts.pory"
	closemessage
# 134 "data/maps/VioletCity/scripts.pory"
	release
# 135 "data/maps/VioletCity/scripts.pory"
	end
# 136 "data/maps/VioletCity/scripts.pory"

# 137 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Gramps::
# 138 "data/maps/VioletCity/scripts.pory"
	lock
# 139 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 140 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Gramps, MSGBOX_DEFAULT
# 141 "data/maps/VioletCity/scripts.pory"
	closemessage
# 142 "data/maps/VioletCity/scripts.pory"
	release
# 143 "data/maps/VioletCity/scripts.pory"
	end
# 144 "data/maps/VioletCity/scripts.pory"

# 145 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Lass::
# 146 "data/maps/VioletCity/scripts.pory"
	lock
# 147 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 148 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Lass, MSGBOX_DEFAULT
# 149 "data/maps/VioletCity/scripts.pory"
	closemessage
# 150 "data/maps/VioletCity/scripts.pory"
	release
# 151 "data/maps/VioletCity/scripts.pory"
	end
# 152 "data/maps/VioletCity/scripts.pory"

# 153 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Pichu::
# 154 "data/maps/VioletCity/scripts.pory"
	lock
# 155 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 156 "data/maps/VioletCity/scripts.pory"
	waitse
# 157 "data/maps/VioletCity/scripts.pory"
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
# 158 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Pichu, MSGBOX_DEFAULT
# 159 "data/maps/VioletCity/scripts.pory"
	waitmoncry
# 160 "data/maps/VioletCity/scripts.pory"
	release
# 161 "data/maps/VioletCity/scripts.pory"
	end
# 162 "data/maps/VioletCity/scripts.pory"

# 163 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Bellsprout::
# 164 "data/maps/VioletCity/scripts.pory"
	lock
# 165 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 166 "data/maps/VioletCity/scripts.pory"
	waitse
# 167 "data/maps/VioletCity/scripts.pory"
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
# 168 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Bellsprout, MSGBOX_DEFAULT
# 169 "data/maps/VioletCity/scripts.pory"
	waitmoncry
# 170 "data/maps/VioletCity/scripts.pory"
	release
# 171 "data/maps/VioletCity/scripts.pory"
	end
# 172 "data/maps/VioletCity/scripts.pory"

# 173 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Rattata::
# 174 "data/maps/VioletCity/scripts.pory"
	lock
# 175 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 176 "data/maps/VioletCity/scripts.pory"
	waitse
# 177 "data/maps/VioletCity/scripts.pory"
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
# 178 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Rattata, MSGBOX_DEFAULT
# 179 "data/maps/VioletCity/scripts.pory"
	waitmoncry
# 180 "data/maps/VioletCity/scripts.pory"
	release
# 181 "data/maps/VioletCity/scripts.pory"
	end
# 182 "data/maps/VioletCity/scripts.pory"

# 183 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_ElmCall_Trigger::
# 184 "data/maps/VioletCity/scripts.pory"
	lock
# 185 "data/maps/VioletCity/scripts.pory"
	pokenavcall VioletCity_Text_Elm_Call
# 186 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 187 "data/maps/VioletCity/scripts.pory"
	delay 30
# 188 "data/maps/VioletCity/scripts.pory"
	clearflag FLAG_HIDE_VIOLET_CITY_AIDE
# 189 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
# 190 "data/maps/VioletCity/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 4
# 191 "data/maps/VioletCity/scripts.pory"
	release
# 192 "data/maps/VioletCity/scripts.pory"
	end
# 193 "data/maps/VioletCity/scripts.pory"

# 194 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_Kimono_Girl::
# 195 "data/maps/VioletCity/scripts.pory"
	lock
# 196 "data/maps/VioletCity/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 197 "data/maps/VioletCity/scripts.pory"
	playse SE_PIN
# 198 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, Common_Movement_ExclamationMark
# 199 "data/maps/VioletCity/scripts.pory"
	delay 60
# 200 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_1
# 201 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 202 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Kimono_Girl1, MSGBOX_DEFAULT
# 203 "data/maps/VioletCity/scripts.pory"
	closemessage
# 204 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_2
# 205 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 206 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Kimono_Girl2, MSGBOX_DEFAULT
# 207 "data/maps/VioletCity/scripts.pory"
	closemessage
# 208 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_3
# 209 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 210 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Kimono_Girl3, MSGBOX_DEFAULT
# 211 "data/maps/VioletCity/scripts.pory"
	closemessage
# 212 "data/maps/VioletCity/scripts.pory"
	playse SE_M_PETAL_DANCE
# 213 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_4
# 214 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 215 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_Kimono_Girl4, MSGBOX_DEFAULT
# 216 "data/maps/VioletCity/scripts.pory"
	closemessage
# 217 "data/maps/VioletCity/scripts.pory"
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_5
# 218 "data/maps/VioletCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/VioletCity/scripts.pory"
	fadedefaultbgm
# 220 "data/maps/VioletCity/scripts.pory"
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 2
# 221 "data/maps/VioletCity/scripts.pory"
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
# 222 "data/maps/VioletCity/scripts.pory"
	removeobject LOCALID_VIOLET_KIMONO
# 223 "data/maps/VioletCity/scripts.pory"
	release
# 224 "data/maps/VioletCity/scripts.pory"
	end
# 225 "data/maps/VioletCity/scripts.pory"

# 226 "data/maps/VioletCity/scripts.pory"

# 227 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_ItemRareCandy::
# 228 "data/maps/VioletCity/scripts.pory"
	finditem ITEM_RARE_CANDY
# 229 "data/maps/VioletCity/scripts.pory"
	end
# 230 "data/maps/VioletCity/scripts.pory"

# 231 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_ItemPechaBerry::
# 232 "data/maps/VioletCity/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 233 "data/maps/VioletCity/scripts.pory"
	end
# 234 "data/maps/VioletCity/scripts.pory"

# 235 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_ItemHyperPotion::
# 236 "data/maps/VioletCity/scripts.pory"
	finditem ITEM_HYPER_POTION
# 237 "data/maps/VioletCity/scripts.pory"
	end
# 238 "data/maps/VioletCity/scripts.pory"

# 239 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Earl_Spin:
# 240 "data/maps/VioletCity/scripts.pory"
	face_down
# 241 "data/maps/VioletCity/scripts.pory"
	face_right
# 242 "data/maps/VioletCity/scripts.pory"
	face_up
# 243 "data/maps/VioletCity/scripts.pory"
	face_left
# 244 "data/maps/VioletCity/scripts.pory"
	face_down
# 245 "data/maps/VioletCity/scripts.pory"
	face_right
# 246 "data/maps/VioletCity/scripts.pory"
	face_up
# 247 "data/maps/VioletCity/scripts.pory"
	face_left
# 248 "data/maps/VioletCity/scripts.pory"
	face_down
# 249 "data/maps/VioletCity/scripts.pory"
	face_right
# 250 "data/maps/VioletCity/scripts.pory"
	face_up
# 251 "data/maps/VioletCity/scripts.pory"
	face_left
# 252 "data/maps/VioletCity/scripts.pory"
	face_down
# 253 "data/maps/VioletCity/scripts.pory"
	step_end
# 254 "data/maps/VioletCity/scripts.pory"

# 255 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Earl_East_Adjustment:
# 256 "data/maps/VioletCity/scripts.pory"
	walk_down
# 257 "data/maps/VioletCity/scripts.pory"
	walk_down
# 258 "data/maps/VioletCity/scripts.pory"
	walk_down
# 259 "data/maps/VioletCity/scripts.pory"
	walk_right
# 260 "data/maps/VioletCity/scripts.pory"
	step_end
# 261 "data/maps/VioletCity/scripts.pory"

# 262 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Player_East_Adjustment:
# 263 "data/maps/VioletCity/scripts.pory"
	walk_down
# 264 "data/maps/VioletCity/scripts.pory"
	walk_down
# 265 "data/maps/VioletCity/scripts.pory"
	walk_left
# 266 "data/maps/VioletCity/scripts.pory"
	walk_down
# 267 "data/maps/VioletCity/scripts.pory"
	face_right
# 268 "data/maps/VioletCity/scripts.pory"
	step_end
# 269 "data/maps/VioletCity/scripts.pory"

# 270 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Earl_South_Adjustment:
# 271 "data/maps/VioletCity/scripts.pory"
	walk_right
# 272 "data/maps/VioletCity/scripts.pory"
	walk_down
# 273 "data/maps/VioletCity/scripts.pory"
	walk_down
# 274 "data/maps/VioletCity/scripts.pory"
	walk_down
# 275 "data/maps/VioletCity/scripts.pory"
	face_right
# 276 "data/maps/VioletCity/scripts.pory"
	step_end
# 277 "data/maps/VioletCity/scripts.pory"

# 278 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Player_South_Adjustment:
# 279 "data/maps/VioletCity/scripts.pory"
	walk_down
# 280 "data/maps/VioletCity/scripts.pory"
	walk_down
# 281 "data/maps/VioletCity/scripts.pory"
	step_end
# 282 "data/maps/VioletCity/scripts.pory"

# 283 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Walk_To_School:
# 284 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 285 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 286 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 287 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 288 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 289 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 290 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 291 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 292 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 293 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 294 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 295 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 296 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 297 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 298 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 299 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 300 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 301 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 302 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 303 "data/maps/VioletCity/scripts.pory"
	walk_fast_right
# 304 "data/maps/VioletCity/scripts.pory"
	step_end
# 305 "data/maps/VioletCity/scripts.pory"

# 306 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Walk_To_School_Player:
# 307 "data/maps/VioletCity/scripts.pory"
	walk_right
# 308 "data/maps/VioletCity/scripts.pory"
	walk_right
# 309 "data/maps/VioletCity/scripts.pory"
	walk_right
# 310 "data/maps/VioletCity/scripts.pory"
	walk_right
# 311 "data/maps/VioletCity/scripts.pory"
	walk_right
# 312 "data/maps/VioletCity/scripts.pory"
	walk_right
# 313 "data/maps/VioletCity/scripts.pory"
	walk_right
# 314 "data/maps/VioletCity/scripts.pory"
	walk_right
# 315 "data/maps/VioletCity/scripts.pory"
	walk_right
# 316 "data/maps/VioletCity/scripts.pory"
	walk_right
# 317 "data/maps/VioletCity/scripts.pory"
	walk_right
# 318 "data/maps/VioletCity/scripts.pory"
	walk_right
# 319 "data/maps/VioletCity/scripts.pory"
	walk_right
# 320 "data/maps/VioletCity/scripts.pory"
	walk_right
# 321 "data/maps/VioletCity/scripts.pory"
	walk_right
# 322 "data/maps/VioletCity/scripts.pory"
	walk_right
# 323 "data/maps/VioletCity/scripts.pory"
	walk_right
# 324 "data/maps/VioletCity/scripts.pory"
	walk_right
# 325 "data/maps/VioletCity/scripts.pory"
	walk_right
# 326 "data/maps/VioletCity/scripts.pory"
	walk_right
# 327 "data/maps/VioletCity/scripts.pory"
	step_end
# 328 "data/maps/VioletCity/scripts.pory"

# 329 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Earl_Walk_Inside:
# 330 "data/maps/VioletCity/scripts.pory"
	walk_up
# 331 "data/maps/VioletCity/scripts.pory"
	walk_up
# 332 "data/maps/VioletCity/scripts.pory"
	step_end
# 333 "data/maps/VioletCity/scripts.pory"

# 334 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Kimono_Girl_1:
# 335 "data/maps/VioletCity/scripts.pory"
	walk_left
# 336 "data/maps/VioletCity/scripts.pory"
	walk_left
# 337 "data/maps/VioletCity/scripts.pory"
	walk_left
# 338 "data/maps/VioletCity/scripts.pory"
	walk_left
# 339 "data/maps/VioletCity/scripts.pory"
	face_up
# 340 "data/maps/VioletCity/scripts.pory"
	step_end
# 341 "data/maps/VioletCity/scripts.pory"

# 342 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Kimono_Girl_2:
# 343 "data/maps/VioletCity/scripts.pory"
	walk_up
# 344 "data/maps/VioletCity/scripts.pory"
	step_end
# 345 "data/maps/VioletCity/scripts.pory"

# 346 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Kimono_Girl_3:
# 347 "data/maps/VioletCity/scripts.pory"
	lock_facing_direction
# 348 "data/maps/VioletCity/scripts.pory"
	walk_down
# 349 "data/maps/VioletCity/scripts.pory"
	unlock_facing_direction
# 350 "data/maps/VioletCity/scripts.pory"
	step_end
# 351 "data/maps/VioletCity/scripts.pory"

# 352 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Kimono_Girl_4:
# 353 "data/maps/VioletCity/scripts.pory"
	face_right
# 354 "data/maps/VioletCity/scripts.pory"
	delay_8
# 355 "data/maps/VioletCity/scripts.pory"
	face_down
# 356 "data/maps/VioletCity/scripts.pory"
	delay_8
# 357 "data/maps/VioletCity/scripts.pory"
	face_left
# 358 "data/maps/VioletCity/scripts.pory"
	delay_8
# 359 "data/maps/VioletCity/scripts.pory"
	face_up
# 360 "data/maps/VioletCity/scripts.pory"
	delay_8
# 361 "data/maps/VioletCity/scripts.pory"
	face_right
# 362 "data/maps/VioletCity/scripts.pory"
	delay_8
# 363 "data/maps/VioletCity/scripts.pory"
	face_down
# 364 "data/maps/VioletCity/scripts.pory"
	delay_8
# 365 "data/maps/VioletCity/scripts.pory"
	face_left
# 366 "data/maps/VioletCity/scripts.pory"
	delay_8
# 367 "data/maps/VioletCity/scripts.pory"
	face_up
# 368 "data/maps/VioletCity/scripts.pory"
	delay_8
# 369 "data/maps/VioletCity/scripts.pory"
	step_end
# 370 "data/maps/VioletCity/scripts.pory"

# 371 "data/maps/VioletCity/scripts.pory"
VioletCity_Movement_Kimono_Girl_5:
# 372 "data/maps/VioletCity/scripts.pory"
	walk_left
# 373 "data/maps/VioletCity/scripts.pory"
	walk_left
# 374 "data/maps/VioletCity/scripts.pory"
	walk_left
# 375 "data/maps/VioletCity/scripts.pory"
	walk_left
# 376 "data/maps/VioletCity/scripts.pory"
	walk_left
# 377 "data/maps/VioletCity/scripts.pory"
	walk_up
# 378 "data/maps/VioletCity/scripts.pory"
	walk_up
# 379 "data/maps/VioletCity/scripts.pory"
	walk_up
# 380 "data/maps/VioletCity/scripts.pory"
	walk_up
# 381 "data/maps/VioletCity/scripts.pory"
	walk_up
# 382 "data/maps/VioletCity/scripts.pory"
	walk_up
# 383 "data/maps/VioletCity/scripts.pory"
	walk_up
# 384 "data/maps/VioletCity/scripts.pory"
	walk_up
# 385 "data/maps/VioletCity/scripts.pory"
	walk_up
# 386 "data/maps/VioletCity/scripts.pory"
	step_end	
# 387 "data/maps/VioletCity/scripts.pory"

# 388 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_LiquidJustice::
# 389 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_LiquidJustice, MSGBOX_NPC
# 390 "data/maps/VioletCity/scripts.pory"
	end
# 391 "data/maps/VioletCity/scripts.pory"

# 392 "data/maps/VioletCity/scripts.pory"
VioletCity_EventScript_GymSign::
# 393 "data/maps/VioletCity/scripts.pory"
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
# 394 "data/maps/VioletCity/scripts.pory"
	end
# 395 "data/maps/VioletCity/scripts.pory"

# 396 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_LiquidJustice:
# 397 "data/maps/VioletCity/scripts.pory"
	.string "Look around!\p"
# 398 "data/maps/VioletCity/scripts.pory"
	.string "It's easy to see what Pokémon\n"
# 399 "data/maps/VioletCity/scripts.pory"
	.string "you can catch in an area without\l"
# 400 "data/maps/VioletCity/scripts.pory"
	.string "having to run around in tall\l"
# 401 "data/maps/VioletCity/scripts.pory"
	.string "grass all day!$"
# 402 "data/maps/VioletCity/scripts.pory"

# 403 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_EarlAsksIfYouBeatFalkner:
# 404 "data/maps/VioletCity/scripts.pory"
	.string "Hello!\n"
# 405 "data/maps/VioletCity/scripts.pory"
	.string "You are trainer?\p"
# 406 "data/maps/VioletCity/scripts.pory"
	.string "Battle Gym Leader,\n"
# 407 "data/maps/VioletCity/scripts.pory"
	.string "win you did?$"
# 408 "data/maps/VioletCity/scripts.pory"

# 409 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_VeryNiceIndeed:
# 410 "data/maps/VioletCity/scripts.pory"
	.string "Ooh, la la!\n"
# 411 "data/maps/VioletCity/scripts.pory"
	.string "Very indeed nice!$"
# 412 "data/maps/VioletCity/scripts.pory"

# 413 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_FollowEarl:
# 414 "data/maps/VioletCity/scripts.pory"
	.string "Is that so? Then study shall\n"
# 415 "data/maps/VioletCity/scripts.pory"
	.string "you! Follow me!$"
# 416 "data/maps/VioletCity/scripts.pory"

# 417 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_HereTeacherIAm:
# 418 "data/maps/VioletCity/scripts.pory"
	.string "Here, teacher I am.\n"
# 419 "data/maps/VioletCity/scripts.pory"
	.string "Good it is you study here!$"
# 420 "data/maps/VioletCity/scripts.pory"

# 421 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Lass:
# 422 "data/maps/VioletCity/scripts.pory"
	.string "Ghosts are rumored to appear\n"
# 423 "data/maps/VioletCity/scripts.pory"
	.string "in Sprout Tower.\p"
# 424 "data/maps/VioletCity/scripts.pory"
	.string "They say that Ghost-type\n"
# 425 "data/maps/VioletCity/scripts.pory"
	.string "moves can bypass the defenses\p"
# 426 "data/maps/VioletCity/scripts.pory"
	.string "of tough Pokémon like Onix\n"
# 427 "data/maps/VioletCity/scripts.pory"
	.string "and Geodude.$"
# 428 "data/maps/VioletCity/scripts.pory"

# 429 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Boy:
# 430 "data/maps/VioletCity/scripts.pory"
	.string "Hey, you're a Pokémon trainer?\p"
# 431 "data/maps/VioletCity/scripts.pory"
	.string "If you head to the Academy,\n"
# 432 "data/maps/VioletCity/scripts.pory"
	.string "you might learn something new!$"
# 433 "data/maps/VioletCity/scripts.pory"

# 434 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Gramps:
# 435 "data/maps/VioletCity/scripts.pory"
	.string "Falkner, from the Violet\n"
# 436 "data/maps/VioletCity/scripts.pory"
	.string "Pokémon Gym, is a fine trainer!\p"
# 437 "data/maps/VioletCity/scripts.pory"
	.string "He inherited his father's gym\n"
# 438 "data/maps/VioletCity/scripts.pory"
	.string "and has done a great job with\l"
# 439 "data/maps/VioletCity/scripts.pory"
	.string "it.$"
# 440 "data/maps/VioletCity/scripts.pory"

# 441 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Youngster:
# 442 "data/maps/VioletCity/scripts.pory"
	.string "I saw a wiggly tree up ahead!\p"
# 443 "data/maps/VioletCity/scripts.pory"
	.string "If you touch it, it squirms\n"
# 444 "data/maps/VioletCity/scripts.pory"
	.string "and dances! Cool!$"
# 445 "data/maps/VioletCity/scripts.pory"

# 446 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Sign:
# 447 "data/maps/VioletCity/scripts.pory"
	.string "Violet City\p"
# 448 "data/maps/VioletCity/scripts.pory"
	.string "The City of Nostalgic Scents$"
# 449 "data/maps/VioletCity/scripts.pory"

# 450 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_GymSign:
# 451 "data/maps/VioletCity/scripts.pory"
	.string "Violet City Pokémon Gym\p"
# 452 "data/maps/VioletCity/scripts.pory"
	.string "Leader: Falkner, The Elegant\n"
# 453 "data/maps/VioletCity/scripts.pory"
	.string "Master of Flying Pokémon$"
# 454 "data/maps/VioletCity/scripts.pory"

# 455 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_SproutTowerSign:
# 456 "data/maps/VioletCity/scripts.pory"
	.string "Sprout Tower\p"
# 457 "data/maps/VioletCity/scripts.pory"
	.string "Experience the Way of Pokémon$"
# 458 "data/maps/VioletCity/scripts.pory"

# 459 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_EarlsAcademySign:
# 460 "data/maps/VioletCity/scripts.pory"
	.string "Earl'S Pokémon Academy$"
# 461 "data/maps/VioletCity/scripts.pory"

# 462 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Pichu:
# 463 "data/maps/VioletCity/scripts.pory"
	.string "Pichu: Chuuuu!$"
# 464 "data/maps/VioletCity/scripts.pory"

# 465 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Bellsprout:
# 466 "data/maps/VioletCity/scripts.pory"
	.string "Bellsprout: Sprouuuut.$"
# 467 "data/maps/VioletCity/scripts.pory"

# 468 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Rattata:
# 469 "data/maps/VioletCity/scripts.pory"
	.string "Rattata: Rattataratta!$"
# 470 "data/maps/VioletCity/scripts.pory"

# 471 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Elm_Call:
# 472 "data/maps/VioletCity/scripts.pory"
	.string "Elm: Hello, {PLAYER}? We\n"
# 473 "data/maps/VioletCity/scripts.pory"
	.string "discovered something about the Egg!\p"
# 474 "data/maps/VioletCity/scripts.pory"
	.string "My assistant is at the Pokémon\n"
# 475 "data/maps/VioletCity/scripts.pory"
	.string "Center in Violet City.\p"
# 476 "data/maps/VioletCity/scripts.pory"
	.string "Could you talk to him?$"
# 477 "data/maps/VioletCity/scripts.pory"

# 478 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Kimono_Girl1:
# 479 "data/maps/VioletCity/scripts.pory"
.string "Me oh my...\n"
# 480 "data/maps/VioletCity/scripts.pory"
.string "That Egg must be...!$"
# 481 "data/maps/VioletCity/scripts.pory"

# 482 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Kimono_Girl2:
# 483 "data/maps/VioletCity/scripts.pory"
.string "I see...\p"
# 484 "data/maps/VioletCity/scripts.pory"
.string "So it was handed from Mr. Pokémon\n"
# 485 "data/maps/VioletCity/scripts.pory"
.string "to Prof. Elm, then from \l"
# 486 "data/maps/VioletCity/scripts.pory"
.string "Prof. Elm to you.\p"
# 487 "data/maps/VioletCity/scripts.pory"
.string "Now I get it...$"
# 488 "data/maps/VioletCity/scripts.pory"

# 489 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Kimono_Girl3:
# 490 "data/maps/VioletCity/scripts.pory"
.string "That Egg is truly an important Egg.\p"
# 491 "data/maps/VioletCity/scripts.pory"
.string "Please do take good care of it\n"
# 492 "data/maps/VioletCity/scripts.pory"
.string "for me. Is that understood?$"
# 493 "data/maps/VioletCity/scripts.pory"

# 494 "data/maps/VioletCity/scripts.pory"
VioletCity_Text_Kimono_Girl4:
# 495 "data/maps/VioletCity/scripts.pory"
.string "I am counting on you.$"

berrytrader_juggler::
# 501 "data/maps/VioletCity/scripts.pory"
	lock
# 502 "data/maps/VioletCity/scripts.pory"
	faceplayer
# 503 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_0
# 504 "data/maps/VioletCity/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, berrytrader_juggler_Text_1, berrytrader_juggler_Text_2, berrytrader_juggler_Text_3, berrytrader_juggler_Text_4, berrytrader_juggler_Text_5
# 505 "data/maps/VioletCity/scripts.pory"
	switch VAR_RESULT
# 506 "data/maps/VioletCity/scripts.pory"
	case 0, berrytrader_juggler_3
# 522 "data/maps/VioletCity/scripts.pory"
	case 1, berrytrader_juggler_4
# 538 "data/maps/VioletCity/scripts.pory"
	case 2, berrytrader_juggler_5
# 554 "data/maps/VioletCity/scripts.pory"
	case 3, berrytrader_juggler_6
# 571 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_11, MSGBOX_DEFAULT
# 572 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 573 "data/maps/VioletCity/scripts.pory"
	release
	end

# 576 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_3:
# 507 "data/maps/VioletCity/scripts.pory"
	checkitem ITEM_RED_SHARD
# 508 "data/maps/VioletCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_9
# 518 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_7
# 519 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_4:
# 523 "data/maps/VioletCity/scripts.pory"
	checkitem ITEM_BLUE_SHARD
# 524 "data/maps/VioletCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_12
# 534 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_7
# 535 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_5:
# 539 "data/maps/VioletCity/scripts.pory"
	checkitem ITEM_YELLOW_SHARD
# 540 "data/maps/VioletCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_15
# 550 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_7
# 551 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_6:
# 555 "data/maps/VioletCity/scripts.pory"
	checkitem ITEM_GREEN_SHARD
# 556 "data/maps/VioletCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq berrytrader_juggler_18
# 566 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_7
# 567 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_9:
# 509 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_6
# 510 "data/maps/VioletCity/scripts.pory"
	removeitem ITEM_RED_SHARD, 1
# 511 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_CHERI_BERRY
# 512 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_PECHA_BERRY
# 513 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_LEPPA_BERRY
# 514 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 515 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_12:
# 525 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_8
# 526 "data/maps/VioletCity/scripts.pory"
	removeitem ITEM_BLUE_SHARD, 1
# 527 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_ORAN_BERRY
# 528 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 529 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_WIKI_BERRY
# 530 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 531 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_15:
# 541 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_9
# 542 "data/maps/VioletCity/scripts.pory"
	removeitem ITEM_YELLOW_SHARD, 1
# 543 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_ASPEAR_BERRY
# 544 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_SITRUS_BERRY
# 545 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 546 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 547 "data/maps/VioletCity/scripts.pory"
	release
	end

berrytrader_juggler_18:
# 557 "data/maps/VioletCity/scripts.pory"
	msgbox berrytrader_juggler_Text_10
# 558 "data/maps/VioletCity/scripts.pory"
	removeitem ITEM_GREEN_SHARD, 1
# 559 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_RAWST_BERRY
# 560 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_LUM_BERRY
# 561 "data/maps/VioletCity/scripts.pory"
	giveitem ITEM_AGUAV_BERRY
# 562 "data/maps/VioletCity/scripts.pory"
	waitmessage
# 563 "data/maps/VioletCity/scripts.pory"
	release
	end


berrytrader_juggler_Text_0:
# 503 "data/maps/VioletCity/scripts.pory"
	.string "Yah yah! I'm a huge fan of colored\n"
	.string "shards. Do you have any to trade for\l"
	.string "me? I will give you three berries for\l"
	.string "each shard.$"

berrytrader_juggler_Text_1:
# 504 "data/maps/VioletCity/scripts.pory"
	.string "Red Shard$"

berrytrader_juggler_Text_2:
# 504 "data/maps/VioletCity/scripts.pory"
	.string "Blue Shard$"

berrytrader_juggler_Text_3:
# 504 "data/maps/VioletCity/scripts.pory"
	.string "Yellow Shard$"

berrytrader_juggler_Text_4:
# 504 "data/maps/VioletCity/scripts.pory"
	.string "Green Shard$"

berrytrader_juggler_Text_5:
# 504 "data/maps/VioletCity/scripts.pory"
	.string "Cancel$"

berrytrader_juggler_Text_6:
# 509 "data/maps/VioletCity/scripts.pory"
	.string "I'll give you my berry set A for that\n"
	.string "one, yah!$"

berrytrader_juggler_Text_7:
# 518 "data/maps/VioletCity/scripts.pory"
	.string "You don't seem to have that shard with\n"
	.string "you.$"

berrytrader_juggler_Text_8:
# 525 "data/maps/VioletCity/scripts.pory"
	.string "I'll give you my berry set B for that\n"
	.string "one, yah!$"

berrytrader_juggler_Text_9:
# 541 "data/maps/VioletCity/scripts.pory"
	.string "I'll give you my berry set C for that\n"
	.string "one, yah!$"

berrytrader_juggler_Text_10:
# 557 "data/maps/VioletCity/scripts.pory"
	.string "I'll give you my berry set D for that\n"
	.string "one, yah!$"

berrytrader_juggler_Text_11:
# 571 "data/maps/VioletCity/scripts.pory"
	.string "Not interested huh? Shame...$"
