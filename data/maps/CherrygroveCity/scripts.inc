# 1 "data/maps/CherrygroveCity/scripts.pory"

# 2 "data/maps/CherrygroveCity/scripts.pory"

# 3 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_MapScripts::
# 4 "data/maps/CherrygroveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CherrygroveCity_OnTransition
# 5 "data/maps/CherrygroveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/CherrygroveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_OnLoad
# 7 "data/maps/CherrygroveCity/scripts.pory"
	.byte 0
# 8 "data/maps/CherrygroveCity/scripts.pory"

# 9 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_OnTransition::
# 10 "data/maps/CherrygroveCity/scripts.pory"
	callnative SetTimeBasedEncounters
# 11 "data/maps/CherrygroveCity/scripts.pory"
	end
# 12 "data/maps/CherrygroveCity/scripts.pory"

# 13 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_OnLoad::
# 14 "data/maps/CherrygroveCity/scripts.pory"
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
# 15 "data/maps/CherrygroveCity/scripts.pory"
	end
# 16 "data/maps/CherrygroveCity/scripts.pory"

# 17 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerGent_Top::
# 18 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 19 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_VISITED_CHERRYGROVE_CITY
# 20 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
# 21 "data/maps/CherrygroveCity/scripts.pory"
	playse SE_PIN
# 22 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
# 23 "data/maps/CherrygroveCity/scripts.pory"
	delay 60
# 24 "data/maps/CherrygroveCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 25 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
# 26 "data/maps/CherrygroveCity/scripts.pory"
	waitmessage
# 27 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
# 28 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
# 29 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 30 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Top
# 31 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0 
# 32 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
# 33 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0 
# 34 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_EventScript_GentTour
# 35 "data/maps/CherrygroveCity/scripts.pory"
	release
# 36 "data/maps/CherrygroveCity/scripts.pory"
	end
# 37 "data/maps/CherrygroveCity/scripts.pory"

# 38 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerGent_Mid::
# 39 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 40 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_VISITED_CHERRYGROVE_CITY
# 41 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
# 42 "data/maps/CherrygroveCity/scripts.pory"
	playse SE_PIN
# 43 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
# 44 "data/maps/CherrygroveCity/scripts.pory"
	delay 60
# 45 "data/maps/CherrygroveCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 46 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
# 47 "data/maps/CherrygroveCity/scripts.pory"
	waitmessage
# 48 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
# 49 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
# 50 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 51 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
# 52 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0 
# 53 "data/maps/CherrygroveCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 54 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_EventScript_GentTour
# 55 "data/maps/CherrygroveCity/scripts.pory"
	release
# 56 "data/maps/CherrygroveCity/scripts.pory"
	end
# 57 "data/maps/CherrygroveCity/scripts.pory"

# 58 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerGent_Bottom::
# 59 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 60 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_VISITED_CHERRYGROVE_CITY
# 61 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
# 62 "data/maps/CherrygroveCity/scripts.pory"
	playse SE_PIN
# 63 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
# 64 "data/maps/CherrygroveCity/scripts.pory"
	delay 60
# 65 "data/maps/CherrygroveCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 66 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
# 67 "data/maps/CherrygroveCity/scripts.pory"
	waitmessage
# 68 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
# 69 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
# 70 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 71 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
# 72 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0 
# 73 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Bottom
# 74 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0 
# 75 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_EventScript_GentTour
# 76 "data/maps/CherrygroveCity/scripts.pory"
	release
# 77 "data/maps/CherrygroveCity/scripts.pory"
	end
# 78 "data/maps/CherrygroveCity/scripts.pory"

# 79 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerGent_Cancel::
# 80 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentDecline, MSGBOX_DEFAULT
# 81 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 82 "data/maps/CherrygroveCity/scripts.pory"
	setvar VAR_CHERRYGROVE_CITY_STATE, 1 @ CHANGE THIS TO 1 LATER
# 83 "data/maps/CherrygroveCity/scripts.pory"
	release
# 84 "data/maps/CherrygroveCity/scripts.pory"
	end
# 85 "data/maps/CherrygroveCity/scripts.pory"

# 86 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_GentTour::
# 87 "data/maps/CherrygroveCity/scripts.pory"
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
# 88 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokecenter
# 89 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokecenter
# 90 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentPokecenter, MSGBOX_DEFAULT
# 93 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 94 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokemart
# 95 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokemart
# 96 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 98 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentMart, MSGBOX_DEFAULT
# 99 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 100 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Route30
# 101 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Route30
# 102 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 103 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentRoute30, MSGBOX_DEFAULT
# 105 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 106 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Sea
# 107 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Sea
# 108 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 109 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 110 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentSea, MSGBOX_DEFAULT
# 111 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 112 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_House_Gent
# 113 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_House_Player
# 114 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 115 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 116 "data/maps/CherrygroveCity/scripts.pory"
	delay 20
# 117 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_GuideGentMap, MSGBOX_DEFAULT
# 118 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 119 "data/maps/CherrygroveCity/scripts.pory"

# 120 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Gent_Leave
# 121 "data/maps/CherrygroveCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 122 "data/maps/CherrygroveCity/scripts.pory"
	delay 20
# 123 "data/maps/CherrygroveCity/scripts.pory"
	opendoor 42, 14
# 124 "data/maps/CherrygroveCity/scripts.pory"
	waitdooranim
# 125 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 126 "data/maps/CherrygroveCity/scripts.pory"
	removeobject LOCALID_GUIDE_GENT
# 127 "data/maps/CherrygroveCity/scripts.pory"
	closedoor 42, 14
# 128 "data/maps/CherrygroveCity/scripts.pory"
	waitdooranim
# 129 "data/maps/CherrygroveCity/scripts.pory"
	
# 130 "data/maps/CherrygroveCity/scripts.pory"
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
# 131 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
# 132 "data/maps/CherrygroveCity/scripts.pory"
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
# 133 "data/maps/CherrygroveCity/scripts.pory"
	fadedefaultbgm
# 134 "data/maps/CherrygroveCity/scripts.pory"
	release
# 135 "data/maps/CherrygroveCity/scripts.pory"
	end
# 136 "data/maps/CherrygroveCity/scripts.pory"

# 137 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Fisherman::
# 138 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 139 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 140 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_set FLAG_GOT_MYSTICWATER, CherryGroveCity_EventScript_Fisherman2
# 141 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
# 142 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_Fisherman2
# 143 "data/maps/CherrygroveCity/scripts.pory"
	giveitem ITEM_MYSTIC_WATER
# 144 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull 
# 145 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 146 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_GOT_MYSTICWATER
# 147 "data/maps/CherrygroveCity/scripts.pory"
	release
# 148 "data/maps/CherrygroveCity/scripts.pory"
	end
# 149 "data/maps/CherrygroveCity/scripts.pory"

# 150 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Fisherman2::
# 151 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
# 152 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 153 "data/maps/CherrygroveCity/scripts.pory"
	release
# 154 "data/maps/CherrygroveCity/scripts.pory"
	end
# 155 "data/maps/CherrygroveCity/scripts.pory"

# 156 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Lass::
# 157 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 158 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 159 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_TeacherHaveMapCard, MSGBOX_DEFAULT
# 160 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 161 "data/maps/CherrygroveCity/scripts.pory"
	release
# 162 "data/maps/CherrygroveCity/scripts.pory"
	end
# 163 "data/maps/CherrygroveCity/scripts.pory"

# 164 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Boy::
# 165 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 166 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 167 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_set FLAG_SYS_POKEDEX_GET, CherryGroveCity_EventScript_Boy2
# 168 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_YoungsterNoPokedex, MSGBOX_DEFAULT
# 169 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 170 "data/maps/CherrygroveCity/scripts.pory"
	release
# 171 "data/maps/CherrygroveCity/scripts.pory"
	end
# 172 "data/maps/CherrygroveCity/scripts.pory"

# 173 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Boy2::
# 174 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_YoungsterHavePokedex, MSGBOX_DEFAULT
# 175 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 176 "data/maps/CherrygroveCity/scripts.pory"
	release
# 177 "data/maps/CherrygroveCity/scripts.pory"
	end
# 178 "data/maps/CherrygroveCity/scripts.pory"

# 179 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Staryu::
# 180 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 181 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 182 "data/maps/CherrygroveCity/scripts.pory"
	waitse
# 183 "data/maps/CherrygroveCity/scripts.pory"
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
# 184 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherryGroveCity_Text_Staryu, MSGBOX_DEFAULT
# 185 "data/maps/CherrygroveCity/scripts.pory"
	waitmoncry
# 186 "data/maps/CherrygroveCity/scripts.pory"
	release
# 187 "data/maps/CherrygroveCity/scripts.pory"
	end
# 188 "data/maps/CherrygroveCity/scripts.pory"

# 189 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Corsola::
# 190 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 191 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 192 "data/maps/CherrygroveCity/scripts.pory"
	waitse
# 193 "data/maps/CherrygroveCity/scripts.pory"
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
# 194 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
# 195 "data/maps/CherrygroveCity/scripts.pory"
	waitmoncry
# 196 "data/maps/CherrygroveCity/scripts.pory"
	release
# 197 "data/maps/CherrygroveCity/scripts.pory"
	end
# 198 "data/maps/CherrygroveCity/scripts.pory"

# 199 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Krabby::
# 200 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 201 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 202 "data/maps/CherrygroveCity/scripts.pory"
	waitse
# 203 "data/maps/CherrygroveCity/scripts.pory"
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
# 204 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
# 205 "data/maps/CherrygroveCity/scripts.pory"
	waitmoncry
# 206 "data/maps/CherrygroveCity/scripts.pory"
	release
# 207 "data/maps/CherrygroveCity/scripts.pory"
	end
# 208 "data/maps/CherrygroveCity/scripts.pory"

# 209 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_Sign::
# 210 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 211 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_CitySign, MSGBOX_SIGN
# 212 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 213 "data/maps/CherrygroveCity/scripts.pory"
	release
# 214 "data/maps/CherrygroveCity/scripts.pory"
	end	
# 215 "data/maps/CherrygroveCity/scripts.pory"

# 216 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerSilver_Top::
# 217 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 218 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Top
# 219 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 220 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_EventScript_TriggerSilver
# 221 "data/maps/CherrygroveCity/scripts.pory"
	end
# 222 "data/maps/CherrygroveCity/scripts.pory"

# 223 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerSilver_Bottom::
# 224 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 225 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Bottom
# 226 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 227 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_EventScript_TriggerSilver
# 228 "data/maps/CherrygroveCity/scripts.pory"
	end
# 229 "data/maps/CherrygroveCity/scripts.pory"

# 230 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_EventScript_TriggerSilver::
# 231 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 232 "data/maps/CherrygroveCity/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 233 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Enter
# 234 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 235 "data/maps/CherrygroveCity/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 236 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_RivalSeen, MSGBOX_DEFAULT
# 237 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 238 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, CherryGroveCity_Silver_Battle_Cyndaquil
# 239 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, CherryGroveCity_Silver_Battle_Totodile
# 240 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, CherryGroveCity_Silver_Battle_Chikorita
# 241 "data/maps/CherrygroveCity/scripts.pory"
	release
# 242 "data/maps/CherrygroveCity/scripts.pory"
	end
# 243 "data/maps/CherrygroveCity/scripts.pory"

# 244 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Silver_Battle_Cyndaquil::
# 245 "data/maps/CherrygroveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_1, CherrygroveCity_Text_SilverWin
# 246 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_Silver_AfterBattle
# 247 "data/maps/CherrygroveCity/scripts.pory"

# 248 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Silver_Battle_Totodile::
# 249 "data/maps/CherrygroveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_1, CherrygroveCity_Text_SilverWin
# 250 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_Silver_AfterBattle
# 251 "data/maps/CherrygroveCity/scripts.pory"

# 252 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Silver_Battle_Chikorita::
# 253 "data/maps/CherrygroveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_1, CherrygroveCity_Text_SilverWin
# 254 "data/maps/CherrygroveCity/scripts.pory"
	goto CherryGroveCity_Silver_AfterBattle
# 255 "data/maps/CherrygroveCity/scripts.pory"

# 256 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Silver_AfterBattle::
# 257 "data/maps/CherrygroveCity/scripts.pory"
	playbgm MUS_HG_RIVAL_EXIT, TRUE
# 258 "data/maps/CherrygroveCity/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 259 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_RivalAfter, MSGBOX_DEFAULT
# 260 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 261 "data/maps/CherrygroveCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Silver_Leave1Player
# 262 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave1
# 263 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 264 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 265 "data/maps/CherrygroveCity/scripts.pory"
	playse SE_PIN
# 266 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_CHERRYGROVE_SILVER, Common_Movement_ExclamationMark
# 267 "data/maps/CherrygroveCity/scripts.pory"
	delay 60
# 268 "data/maps/CherrygroveCity/scripts.pory"
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_EAST
# 269 "data/maps/CherrygroveCity/scripts.pory"
	delay 60
# 270 "data/maps/CherrygroveCity/scripts.pory"
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_SOUTH
# 271 "data/maps/CherrygroveCity/scripts.pory"
	delay 30
# 272 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Return
# 273 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 274 "data/maps/CherrygroveCity/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 275 "data/maps/CherrygroveCity/scripts.pory"
	msgbox CherrygroveCity_Text_RivalID, MSGBOX_DEFAULT
# 276 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 277 "data/maps/CherrygroveCity/scripts.pory"
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave2
# 278 "data/maps/CherrygroveCity/scripts.pory"
	waitmovement 0
# 279 "data/maps/CherrygroveCity/scripts.pory"
	removeobject LOCALID_CHERRYGROVE_SILVER
# 280 "data/maps/CherrygroveCity/scripts.pory"
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
# 281 "data/maps/CherrygroveCity/scripts.pory"
	setvar VAR_CHERRYGROVE_CITY_STATE, 4
# 282 "data/maps/CherrygroveCity/scripts.pory"
	fadedefaultbgm
# 283 "data/maps/CherrygroveCity/scripts.pory"
	release
# 284 "data/maps/CherrygroveCity/scripts.pory"
	end
# 285 "data/maps/CherrygroveCity/scripts.pory"

# 286 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentIntro:
# 287 "data/maps/CherrygroveCity/scripts.pory"
	.string "You're a rookie trainer,\n"
# 288 "data/maps/CherrygroveCity/scripts.pory"
	.string "aren't you? I can tell!\p"
# 289 "data/maps/CherrygroveCity/scripts.pory"
	.string "That's Ok! Everyone is a\n"
# 290 "data/maps/CherrygroveCity/scripts.pory"
	.string "rookie at some point!\p"
# 291 "data/maps/CherrygroveCity/scripts.pory"
	.string "If you'd like, I can teach\n"
# 292 "data/maps/CherrygroveCity/scripts.pory"
	.string "you a few things.$"
# 293 "data/maps/CherrygroveCity/scripts.pory"

# 294 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentTourStart:
# 295 "data/maps/CherrygroveCity/scripts.pory"
	.string "Ok, then!\n"
# 296 "data/maps/CherrygroveCity/scripts.pory"
	.string "Follow me!$"
# 297 "data/maps/CherrygroveCity/scripts.pory"

# 298 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentPokecenter:
# 299 "data/maps/CherrygroveCity/scripts.pory"
	.string "This is a Pokémon Center.\p"
# 300 "data/maps/CherrygroveCity/scripts.pory"
	.string "They heal your Pokémon in no\n"
# 301 "data/maps/CherrygroveCity/scripts.pory"
	.string "time at all.\p"
# 302 "data/maps/CherrygroveCity/scripts.pory"
	.string "You'll be relying on them a lot,\n"
# 303 "data/maps/CherrygroveCity/scripts.pory"
	.string "so you better learn about them.$"
# 304 "data/maps/CherrygroveCity/scripts.pory"

# 305 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentMart:
# 306 "data/maps/CherrygroveCity/scripts.pory"
	.string "This is a Pokémon Mart.\p"
# 307 "data/maps/CherrygroveCity/scripts.pory"
	.string "They sell Balls for catching wild\n"
# 308 "data/maps/CherrygroveCity/scripts.pory"
	.string "Pokémon and other useful items.$"
# 309 "data/maps/CherrygroveCity/scripts.pory"

# 310 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentRoute30:
# 311 "data/maps/CherrygroveCity/scripts.pory"
	.string "Route 30 is out this way.\p"
# 312 "data/maps/CherrygroveCity/scripts.pory"
	.string "Trainers will be battling\n"
# 313 "data/maps/CherrygroveCity/scripts.pory"
	.string "their prized Pokémon there.$"
# 314 "data/maps/CherrygroveCity/scripts.pory"

# 315 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentSea:
# 316 "data/maps/CherrygroveCity/scripts.pory"
	.string "This is the sea, as you can see.\p"
# 317 "data/maps/CherrygroveCity/scripts.pory"
	.string "Some Pokémon are found only in\n"
# 318 "data/maps/CherrygroveCity/scripts.pory"
	.string "in water.$"
# 319 "data/maps/CherrygroveCity/scripts.pory"

# 320 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentMap:
# 321 "data/maps/CherrygroveCity/scripts.pory"
	.string "Here…\p"
# 322 "data/maps/CherrygroveCity/scripts.pory"
	.string "It's my house! Thanks for\n"
# 323 "data/maps/CherrygroveCity/scripts.pory"
	.string "your company.\p"
# 324 "data/maps/CherrygroveCity/scripts.pory"
	.string "Oh, and if you're ever lost, check\n"
# 325 "data/maps/CherrygroveCity/scripts.pory"
	.string "the Map on your Pokégear!\p"
# 326 "data/maps/CherrygroveCity/scripts.pory"
	.string "I wish you luck on your journey!$"
# 327 "data/maps/CherrygroveCity/scripts.pory"

# 328 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentDecline:
# 329 "data/maps/CherrygroveCity/scripts.pory"
	.string "Oh… It's something I enjoy\n"
# 330 "data/maps/CherrygroveCity/scripts.pory"
	.string "doing…\p"
# 331 "data/maps/CherrygroveCity/scripts.pory"
	.string "Fine. Come see me whenever\n"
# 332 "data/maps/CherrygroveCity/scripts.pory"
	.string "you like.$"
# 333 "data/maps/CherrygroveCity/scripts.pory"

# 334 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_RivalSeen:
# 335 "data/maps/CherrygroveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 336 "data/maps/CherrygroveCity/scripts.pory"
	.string "You got a Pokémon at the Lab.\p"
# 337 "data/maps/CherrygroveCity/scripts.pory"
	.string "What a waste.\n"
# 338 "data/maps/CherrygroveCity/scripts.pory"
	.string "A wimp like you.\p"
# 339 "data/maps/CherrygroveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 340 "data/maps/CherrygroveCity/scripts.pory"
	.string "Don't you get what I'm saying?\n"
# 341 "data/maps/CherrygroveCity/scripts.pory"
	.string "Well, I too, have a good Pokémon.\p"
# 342 "data/maps/CherrygroveCity/scripts.pory"
	.string "I'll show you what I mean!$"
# 343 "data/maps/CherrygroveCity/scripts.pory"

# 344 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_SilverWin:
# 345 "data/maps/CherrygroveCity/scripts.pory"
	.string "Humph. Are you happy you won?$"
# 346 "data/maps/CherrygroveCity/scripts.pory"

# 347 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_RivalAfter:
# 348 "data/maps/CherrygroveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 349 "data/maps/CherrygroveCity/scripts.pory"
	.string "Do you want to know who I am?\p"
# 350 "data/maps/CherrygroveCity/scripts.pory"
	.string "I'm going to be the world's\n"
# 351 "data/maps/CherrygroveCity/scripts.pory"
	.string "greatest Pokémon trainer.$"
# 352 "data/maps/CherrygroveCity/scripts.pory"

# 353 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_RivalID:
# 354 "data/maps/CherrygroveCity/scripts.pory"
	.string "Give it back!\n"
# 355 "data/maps/CherrygroveCity/scripts.pory"
	.string "That's my Trainer Card!\p"
# 356 "data/maps/CherrygroveCity/scripts.pory"
	.string "Oh no!\n"
# 357 "data/maps/CherrygroveCity/scripts.pory"
	.string "You saw my name...$"
# 358 "data/maps/CherrygroveCity/scripts.pory"

# 359 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_TeacherHaveMapCard:
# 360 "data/maps/CherrygroveCity/scripts.pory"
	.string "When you're with Pokémon,\n"
# 361 "data/maps/CherrygroveCity/scripts.pory"
	.string "going anywhere is fun.$"
# 362 "data/maps/CherrygroveCity/scripts.pory"

# 363 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_YoungsterNoPokedex:
# 364 "data/maps/CherrygroveCity/scripts.pory"
	.string "Mr. Pokémon's house is still\n"
# 365 "data/maps/CherrygroveCity/scripts.pory"
	.string "farther up ahead.$"
# 366 "data/maps/CherrygroveCity/scripts.pory"

# 367 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_YoungsterHavePokedex:
# 368 "data/maps/CherrygroveCity/scripts.pory"
	.string "I battled the trainers on the\n"
# 369 "data/maps/CherrygroveCity/scripts.pory"
	.string "road.\p"
# 370 "data/maps/CherrygroveCity/scripts.pory"
	.string "My Pokémon lost. They're a\n"
# 371 "data/maps/CherrygroveCity/scripts.pory"
	.string "mess! I must take them to a\l"
# 372 "data/maps/CherrygroveCity/scripts.pory"
	.string "Pokémon Center.$"
# 373 "data/maps/CherrygroveCity/scripts.pory"

# 374 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_MysticWaterGuyBefore:
# 375 "data/maps/CherrygroveCity/scripts.pory"
	.string "A Pokémon I caught had an\n"
# 376 "data/maps/CherrygroveCity/scripts.pory"
	.string "item.\p"
# 377 "data/maps/CherrygroveCity/scripts.pory"
	.string "I think it's Mystic Water.\p"
# 378 "data/maps/CherrygroveCity/scripts.pory"
	.string "I don't need it, so do you\n"
# 379 "data/maps/CherrygroveCity/scripts.pory"
	.string "want it?$"
# 380 "data/maps/CherrygroveCity/scripts.pory"

# 381 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_MysticWaterGuyAfter:
# 382 "data/maps/CherrygroveCity/scripts.pory"
	.string "Back to fishing for me, then.$"
# 383 "data/maps/CherrygroveCity/scripts.pory"

# 384 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_CitySign:
# 385 "data/maps/CherrygroveCity/scripts.pory"
	.string "Cherrygrove City\p"
# 386 "data/maps/CherrygroveCity/scripts.pory"
	.string "The City of Cute, Fragrant\n"
# 387 "data/maps/CherrygroveCity/scripts.pory"
	.string "Flowers$"
# 388 "data/maps/CherrygroveCity/scripts.pory"

# 389 "data/maps/CherrygroveCity/scripts.pory"
CherrygroveCity_Text_GuideGentsHouseSign:
# 390 "data/maps/CherrygroveCity/scripts.pory"
	.string "Guide Gent's House$"
# 391 "data/maps/CherrygroveCity/scripts.pory"

# 392 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Text_Staryu:
# 393 "data/maps/CherrygroveCity/scripts.pory"
	.string "Staryu: Yuuuuuuuu.$"
# 394 "data/maps/CherrygroveCity/scripts.pory"

# 395 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Text_Corsola:
# 396 "data/maps/CherrygroveCity/scripts.pory"
	.string "Corsola: Corsola! La!$"
# 397 "data/maps/CherrygroveCity/scripts.pory"

# 398 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Text_Krabby:
# 399 "data/maps/CherrygroveCity/scripts.pory"
	.string "Krabby: Kooookeee!$"
# 400 "data/maps/CherrygroveCity/scripts.pory"

# 401 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Trigger_Gent:
# 402 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 403 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 404 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 405 "data/maps/CherrygroveCity/scripts.pory"
	face_left
# 406 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 407 "data/maps/CherrygroveCity/scripts.pory"

# 408 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Trigger_Top:
# 409 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 410 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 411 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 412 "data/maps/CherrygroveCity/scripts.pory"

# 413 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Trigger_Bottom:
# 414 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 415 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 416 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 417 "data/maps/CherrygroveCity/scripts.pory"

# 418 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Pokecenter:
# 419 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 420 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 421 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 422 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 423 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 424 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 425 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 426 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 427 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 428 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 429 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 430 "data/maps/CherrygroveCity/scripts.pory"

# 431 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Pokemart:
# 432 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 433 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 434 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 435 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 436 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 437 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 438 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 439 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 440 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 441 "data/maps/CherrygroveCity/scripts.pory"

# 442 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Route30:
# 443 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 444 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 445 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 446 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 447 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 448 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 449 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 450 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 451 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 452 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 453 "data/maps/CherrygroveCity/scripts.pory"

# 454 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Sea:
# 455 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 456 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 457 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 458 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 459 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 460 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 461 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 462 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 463 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 464 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 465 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 466 "data/maps/CherrygroveCity/scripts.pory"
	walk_left
# 467 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 468 "data/maps/CherrygroveCity/scripts.pory"

# 469 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_House_Gent:
# 470 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 471 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 472 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 473 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 474 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 475 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 476 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 477 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 478 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 479 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 480 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 481 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 482 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 483 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 484 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 485 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 486 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 487 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 488 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 489 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 490 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 491 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 492 "data/maps/CherrygroveCity/scripts.pory"

# 493 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_House_Player:
# 494 "data/maps/CherrygroveCity/scripts.pory"
	delay_16
# 495 "data/maps/CherrygroveCity/scripts.pory"
	delay_16
# 496 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 497 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 498 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 499 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 500 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 501 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 502 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 503 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 504 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 505 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 506 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 507 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 508 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 509 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 510 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 511 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 512 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 513 "data/maps/CherrygroveCity/scripts.pory"
	walk_right
# 514 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 515 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 516 "data/maps/CherrygroveCity/scripts.pory"

# 517 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Gent_Leave:
# 518 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 519 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 520 "data/maps/CherrygroveCity/scripts.pory"

# 521 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Trigger_Silver_Top:
# 522 "data/maps/CherrygroveCity/scripts.pory"
	walk_down
# 523 "data/maps/CherrygroveCity/scripts.pory"
	face_right
# 524 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 525 "data/maps/CherrygroveCity/scripts.pory"

# 526 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Trigger_Silver_Bottom:
# 527 "data/maps/CherrygroveCity/scripts.pory"
	walk_up
# 528 "data/maps/CherrygroveCity/scripts.pory"
	face_right
# 529 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 530 "data/maps/CherrygroveCity/scripts.pory"

# 531 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Silver_Enter:
# 532 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 533 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 534 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 535 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 536 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 537 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 538 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 539 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 540 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 541 "data/maps/CherrygroveCity/scripts.pory"

# 542 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Silver_Leave1:
# 543 "data/maps/CherrygroveCity/scripts.pory"
	delay_16
# 544 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 545 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 546 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 547 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 548 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 549 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 550 "data/maps/CherrygroveCity/scripts.pory"

# 551 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Silver_Leave1Player:
# 552 "data/maps/CherrygroveCity/scripts.pory"
	lock_facing_direction
# 553 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_down
# 554 "data/maps/CherrygroveCity/scripts.pory"
	unlock_facing_direction
# 555 "data/maps/CherrygroveCity/scripts.pory"
	face_up
# 556 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 557 "data/maps/CherrygroveCity/scripts.pory"

# 558 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Silver_Return:
# 559 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_right
# 560 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_right
# 561 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_right
# 562 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_right
# 563 "data/maps/CherrygroveCity/scripts.pory"
	face_down
# 564 "data/maps/CherrygroveCity/scripts.pory"
	step_end
# 565 "data/maps/CherrygroveCity/scripts.pory"

# 566 "data/maps/CherrygroveCity/scripts.pory"

# 567 "data/maps/CherrygroveCity/scripts.pory"
CherryGroveCity_Movement_Silver_Leave2:
# 568 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 569 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 570 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 571 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 572 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 573 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 574 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 575 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 576 "data/maps/CherrygroveCity/scripts.pory"
	walk_fast_left
# 577 "data/maps/CherrygroveCity/scripts.pory"
	step_end

Cherrygrove_FadedSign::
# 581 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FadedSign_Text_0, MSGBOX_SIGN
	return


Cherrygrove_DarkraiEventDoor::
# 586 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 587 "data/maps/CherrygroveCity/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq Cherrygrove_DarkraiEventDoor_2
# 619 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_7
# 622 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_DarkraiEventDoor_2:
# 588 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_0
# 593 "data/maps/CherrygroveCity/scripts.pory"
	checkspecies SPECIES_CRESSELIA
# 594 "data/maps/CherrygroveCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Cherrygrove_DarkraiEventDoor_6
# 600 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_2
# 601 "data/maps/CherrygroveCity/scripts.pory"
	dynmultichoice 20, 8, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Cherrygrove_DarkraiEventDoor_Text_3, Cherrygrove_DarkraiEventDoor_Text_4
# 602 "data/maps/CherrygroveCity/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Cherrygrove_DarkraiEventDoor_8
# 613 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_6
# 614 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_DarkraiEventDoor_6:
# 595 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_1
# 597 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_DarkraiEventDoor_8:
# 603 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_DarkraiEventDoor_Text_5
# 604 "data/maps/CherrygroveCity/scripts.pory"
	closemessage
# 605 "data/maps/CherrygroveCity/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 2
	goto_if_ge Cherrygrove_DarkraiEventDoor_12
# 608 "data/maps/CherrygroveCity/scripts.pory"
	warpwhitefade MAP_DARKRAI_INN1, 1
Cherrygrove_DarkraiEventDoor_11:
# 610 "data/maps/CherrygroveCity/scripts.pory"
	waitstate
	end

Cherrygrove_DarkraiEventDoor_12:
# 606 "data/maps/CherrygroveCity/scripts.pory"
	warpwhitefade MAP_DARKRAI_INN1RUINED, 28, 18
	goto Cherrygrove_DarkraiEventDoor_11


Cherrygrove_Littlegirl::
# 627 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 628 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 629 "data/maps/CherrygroveCity/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_eq Cherrygrove_Littlegirl_2
# 635 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_Littlegirl_Text_1
# 638 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_Littlegirl_2:
# 630 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_Littlegirl_Text_0
# 632 "data/maps/CherrygroveCity/scripts.pory"
	release
	end


Cherrygrove_Zigzagoon::
# 643 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 644 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 645 "data/maps/CherrygroveCity/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON_GALAR, CRY_MODE_NORMAL
# 646 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_Zigzagoon_Text_0
# 647 "data/maps/CherrygroveCity/scripts.pory"
	release
	end


Cherrygrove_Rattata::
# 652 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 653 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 654 "data/maps/CherrygroveCity/scripts.pory"
	playmoncry SPECIES_RATTATA_ALOLA, CRY_MODE_NORMAL
# 655 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_Rattata_Text_0
# 656 "data/maps/CherrygroveCity/scripts.pory"
	release
	end


Cherrygrove_FriendlyTrader::
# 661 "data/maps/CherrygroveCity/scripts.pory"
	lock
# 662 "data/maps/CherrygroveCity/scripts.pory"
	faceplayer
# 663 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_set FLAG_PICKED_ZIGZAGOON, Cherrygrove_FriendlyTrader_2
# 663 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_set FLAG_PICKED_RATTATA, Cherrygrove_FriendlyTrader_2
# 668 "data/maps/CherrygroveCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_FIRST_BALLS, Cherrygrove_FriendlyTrader_7
# 718 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_7
# 725 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_FriendlyTrader_2:
# 664 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_0
# 665 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

# 728 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_FriendlyTrader_7:
# 669 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_1
# 680 "data/maps/CherrygroveCity/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Cherrygrove_FriendlyTrader_Text_2, Cherrygrove_FriendlyTrader_Text_3, Cherrygrove_FriendlyTrader_Text_4
# 681 "data/maps/CherrygroveCity/scripts.pory"
	switch VAR_RESULT
# 682 "data/maps/CherrygroveCity/scripts.pory"
	case 0, Cherrygrove_FriendlyTrader_11
# 697 "data/maps/CherrygroveCity/scripts.pory"
	case 1, Cherrygrove_FriendlyTrader_12
# 713 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_6
# 714 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_FriendlyTrader_11:
# 683 "data/maps/CherrygroveCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZIGZAGOON_GALAR
# 684 "data/maps/CherrygroveCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON_GALAR
# 685 "data/maps/CherrygroveCity/scripts.pory"
	givemon SPECIES_ZIGZAGOON_GALAR, 5
# 686 "data/maps/CherrygroveCity/scripts.pory"
	showgivemonpic 10, 3
# 687 "data/maps/CherrygroveCity/scripts.pory"
	removeobject LOCALID_CHERRY_ZIGZAGOON
# 688 "data/maps/CherrygroveCity/scripts.pory"
	call Common_EventScript_GiftMon
# 689 "data/maps/CherrygroveCity/scripts.pory"
	hidemonpic
# 690 "data/maps/CherrygroveCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON_GALAR
# 691 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_5
# 695 "data/maps/CherrygroveCity/scripts.pory"
	release
	end

Cherrygrove_FriendlyTrader_12:
# 698 "data/maps/CherrygroveCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RATTATA_ALOLA
# 699 "data/maps/CherrygroveCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RATTATA_ALOLA
# 700 "data/maps/CherrygroveCity/scripts.pory"
	givemon SPECIES_RATTATA_ALOLA, 5
# 701 "data/maps/CherrygroveCity/scripts.pory"
	showgivemonpic 10, 3
# 702 "data/maps/CherrygroveCity/scripts.pory"
	removeobject LOCALID_CHERRY_RATTATA
# 703 "data/maps/CherrygroveCity/scripts.pory"
	call Common_EventScript_GiftMon
# 704 "data/maps/CherrygroveCity/scripts.pory"
	hidemonpic
# 705 "data/maps/CherrygroveCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RATTATA_ALOLA
# 706 "data/maps/CherrygroveCity/scripts.pory"
	msgbox Cherrygrove_FriendlyTrader_Text_5
# 710 "data/maps/CherrygroveCity/scripts.pory"
	release
	end


Cherrygrove_FadedSign_Text_0:
# 581 "data/maps/CherrygroveCity/scripts.pory"
	.string "Cherrygrove inn...\n"
	.string "The text is too faded to read.$"

Cherrygrove_DarkraiEventDoor_Text_0:
# 588 "data/maps/CherrygroveCity/scripts.pory"
	.string "Darkrai might be residing in this \n"
	.string "old inn.\p"
	.string "It would be best to prepare for\n"
	.string "anything.$"

Cherrygrove_DarkraiEventDoor_Text_1:
# 595 "data/maps/CherrygroveCity/scripts.pory"
	.string "You should also bring Cresselia with \n"
	.string "you.$"

Cherrygrove_DarkraiEventDoor_Text_2:
# 600 "data/maps/CherrygroveCity/scripts.pory"
	.string "Are you absolutely sure you are ready?$"

Cherrygrove_DarkraiEventDoor_Text_3:
# 601 "data/maps/CherrygroveCity/scripts.pory"
	.string "Prepare first$"

Cherrygrove_DarkraiEventDoor_Text_4:
# 601 "data/maps/CherrygroveCity/scripts.pory"
	.string "Go in$"

Cherrygrove_DarkraiEventDoor_Text_5:
# 603 "data/maps/CherrygroveCity/scripts.pory"
	.string "You grab the door handle and-$"

Cherrygrove_DarkraiEventDoor_Text_6:
# 613 "data/maps/CherrygroveCity/scripts.pory"
	.string "Best to prepare first.$"

Cherrygrove_DarkraiEventDoor_Text_7:
# 619 "data/maps/CherrygroveCity/scripts.pory"
	.string "The door won't budge. It seems\n"
	.string "to be stuck.$"

Cherrygrove_Littlegirl_Text_0:
# 630 "data/maps/CherrygroveCity/scripts.pory"
	.string "I saw you dozing off in front of the\n"
	.string "old inn's door. Are you okay?$"

Cherrygrove_Littlegirl_Text_1:
# 635 "data/maps/CherrygroveCity/scripts.pory"
	.string "That inn... I don't think it\n"
	.string "has ever been open. My mom said it was\l"
	.string "abandoned even in her youth.$"

Cherrygrove_Zigzagoon_Text_0:
# 646 "data/maps/CherrygroveCity/scripts.pory"
	.string "Zig!$"

Cherrygrove_Rattata_Text_0:
# 655 "data/maps/CherrygroveCity/scripts.pory"
	.string "Rat!$"

Cherrygrove_FriendlyTrader_Text_0:
# 664 "data/maps/CherrygroveCity/scripts.pory"
	.string "Hi! Has my Pokémon been helpful?$"

Cherrygrove_FriendlyTrader_Text_1:
# 669 "data/maps/CherrygroveCity/scripts.pory"
	.string "Hello! Are you a new trainer per chance?\p"
	.string "Listen, I received two exotic Pokémon\n"
	.string "as a gift from my uncle in the Safari\l"
	.string "Zone, but I can't keep both. \p"
	.string "Would you be willing to take one of \n"
	.string "them with you?\p"
	.string "I'm sure either one would love to go on\n"
	.string "an adventure with you!$"

Cherrygrove_FriendlyTrader_Text_2:
# 680 "data/maps/CherrygroveCity/scripts.pory"
	.string "Zigzagoon$"

Cherrygrove_FriendlyTrader_Text_3:
# 680 "data/maps/CherrygroveCity/scripts.pory"
	.string "Rattata$"

Cherrygrove_FriendlyTrader_Text_4:
# 680 "data/maps/CherrygroveCity/scripts.pory"
	.string "No thanks$"

Cherrygrove_FriendlyTrader_Text_5:
# 691 "data/maps/CherrygroveCity/scripts.pory"
	.string "Take good care of my {STR_VAR_1}!\p"
	.string "Say hi to my uncle, Baoba if you are\n"
	.string "ever visiting the Safari Zone!$"

Cherrygrove_FriendlyTrader_Text_6:
# 713 "data/maps/CherrygroveCity/scripts.pory"
	.string "Oh... That's a shame...$"

Cherrygrove_FriendlyTrader_Text_7:
# 718 "data/maps/CherrygroveCity/scripts.pory"
	.string "Hey! Can I ask you a favour? \p"
	.string "Wait... You don't have any\n"
	.string "Poké Balls...\p"
	.string "Sorry,\n"
	.string "I thought you were a trainer.$"
