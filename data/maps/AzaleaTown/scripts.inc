# 1 "data/maps/AzaleaTown/scripts.pory"

# 2 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_MapScripts::
# 3 "data/maps/AzaleaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_OnTransition
# 4 "data/maps/AzaleaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
# 5 "data/maps/AzaleaTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AzaleaTown_OnLoad
# 6 "data/maps/AzaleaTown/scripts.pory"
	.byte 0
# 7 "data/maps/AzaleaTown/scripts.pory"

# 8 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_OnLoad::
# 9 "data/maps/AzaleaTown/scripts.pory"
	setrespawn HEAL_LOCATION_AZALEA_TOWN
# 10 "data/maps/AzaleaTown/scripts.pory"
	end
# 11 "data/maps/AzaleaTown/scripts.pory"

# 12 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_OnTransition::
# 13 "data/maps/AzaleaTown/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_MapScript_Hide_Silver
# 14 "data/maps/AzaleaTown/scripts.pory"
	end
# 15 "data/maps/AzaleaTown/scripts.pory"
	
# 16 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_OnFrame::
# 17 "data/maps/AzaleaTown/scripts.pory"
	map_script_2 VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_EventScript_GSBall
# 18 "data/maps/AzaleaTown/scripts.pory"
	.2byte 0
# 19 "data/maps/AzaleaTown/scripts.pory"

# 20 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_MapScript_Hide_Silver:
# 21 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 22 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_SILVER
# 23 "data/maps/AzaleaTown/scripts.pory"
	end
# 24 "data/maps/AzaleaTown/scripts.pory"

# 25 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Trigger:: @flagheap
# 26 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_VISITED_AZALEA_TOWN
# 27 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
# 28 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 29 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_KURT_2
# 30 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 31 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
# 32 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 33 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 34 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 35 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 36 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_CELEBI
# 37 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_KURT
# 38 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
# 39 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 40 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 41 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 42 "data/maps/AzaleaTown/scripts.pory"
	
# 43 "data/maps/AzaleaTown/scripts.pory"

# 44 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
# 45 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE
# 46 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
# 47 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
# 48 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_KURT_1
# 49 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_GOT_CHARCOAL
# 50 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
# 51 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
# 52 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_MOVE_TUTOR_TAUGHT_HEADBUTT
# 53 "data/maps/AzaleaTown/scripts.pory"

# 54 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 1
# 55 "data/maps/AzaleaTown/scripts.pory"
	end
# 56 "data/maps/AzaleaTown/scripts.pory"

# 57 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Rocket1::
# 58 "data/maps/AzaleaTown/scripts.pory"
	lock
# 59 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 60 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Rocket1, MSGBOX_DEFAULT
# 61 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 62 "data/maps/AzaleaTown/scripts.pory"
	release
# 63 "data/maps/AzaleaTown/scripts.pory"
	end
# 64 "data/maps/AzaleaTown/scripts.pory"

# 65 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Rocket2::
# 66 "data/maps/AzaleaTown/scripts.pory"
	lock
# 67 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 68 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Rocket2, MSGBOX_DEFAULT
# 69 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 70 "data/maps/AzaleaTown/scripts.pory"
	release
# 71 "data/maps/AzaleaTown/scripts.pory"
	end
# 72 "data/maps/AzaleaTown/scripts.pory"

# 73 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Gramps::
# 74 "data/maps/AzaleaTown/scripts.pory"
	lock
# 75 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 76 "data/maps/AzaleaTown/scripts.pory"
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_EventScript_Gramps2
# 77 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
# 78 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 79 "data/maps/AzaleaTown/scripts.pory"
	release
# 80 "data/maps/AzaleaTown/scripts.pory"
	end
# 81 "data/maps/AzaleaTown/scripts.pory"

# 82 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Gramps2::
# 83 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
# 84 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 85 "data/maps/AzaleaTown/scripts.pory"
	release
# 86 "data/maps/AzaleaTown/scripts.pory"
	end
# 87 "data/maps/AzaleaTown/scripts.pory"

# 88 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Lass::
# 89 "data/maps/AzaleaTown/scripts.pory"
	lock
# 90 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 91 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Teacher, MSGBOX_DEFAULT
# 92 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 93 "data/maps/AzaleaTown/scripts.pory"
	release
# 94 "data/maps/AzaleaTown/scripts.pory"
	end
# 95 "data/maps/AzaleaTown/scripts.pory"

# 96 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Youngster::
# 97 "data/maps/AzaleaTown/scripts.pory"
	lock
# 98 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 99 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Youngster, MSGBOX_DEFAULT
# 100 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 101 "data/maps/AzaleaTown/scripts.pory"
	release
# 102 "data/maps/AzaleaTown/scripts.pory"
	end
# 103 "data/maps/AzaleaTown/scripts.pory"

# 104 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Slowpoke::
# 105 "data/maps/AzaleaTown/scripts.pory"
	lock
# 106 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 107 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 108 "data/maps/AzaleaTown/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 109 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
# 110 "data/maps/AzaleaTown/scripts.pory"
	waitmoncry
# 111 "data/maps/AzaleaTown/scripts.pory"
	release
# 112 "data/maps/AzaleaTown/scripts.pory"
	end
# 113 "data/maps/AzaleaTown/scripts.pory"

# 114 "data/maps/AzaleaTown/scripts.pory"

# 115 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_GymSign::
# 116 "data/maps/AzaleaTown/scripts.pory"
	lock
# 117 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
# 118 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 119 "data/maps/AzaleaTown/scripts.pory"
	release
# 120 "data/maps/AzaleaTown/scripts.pory"
	end
# 121 "data/maps/AzaleaTown/scripts.pory"

# 122 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_KurtSign::
# 123 "data/maps/AzaleaTown/scripts.pory"
	lock
# 124 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
# 125 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 126 "data/maps/AzaleaTown/scripts.pory"
	release
# 127 "data/maps/AzaleaTown/scripts.pory"
	end
# 128 "data/maps/AzaleaTown/scripts.pory"

# 129 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_KilnSign::
# 130 "data/maps/AzaleaTown/scripts.pory"
	lock
# 131 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
# 132 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 133 "data/maps/AzaleaTown/scripts.pory"
	release
# 134 "data/maps/AzaleaTown/scripts.pory"
	end
# 135 "data/maps/AzaleaTown/scripts.pory"

# 136 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_IlexSign::
# 137 "data/maps/AzaleaTown/scripts.pory"
	lock
# 138 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_IlexForestSign, MSGBOX_SIGN
# 139 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 140 "data/maps/AzaleaTown/scripts.pory"
	release
# 141 "data/maps/AzaleaTown/scripts.pory"
	end
# 142 "data/maps/AzaleaTown/scripts.pory"

# 143 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_WellSign::
# 144 "data/maps/AzaleaTown/scripts.pory"
	lock
# 145 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
# 146 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 147 "data/maps/AzaleaTown/scripts.pory"
	release
# 148 "data/maps/AzaleaTown/scripts.pory"
	end
# 149 "data/maps/AzaleaTown/scripts.pory"

# 150 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_AzaleaSign::
# 151 "data/maps/AzaleaTown/scripts.pory"
	lock
# 152 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
# 153 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 154 "data/maps/AzaleaTown/scripts.pory"
	release
# 155 "data/maps/AzaleaTown/scripts.pory"
	end
# 156 "data/maps/AzaleaTown/scripts.pory"

# 157 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_SilverTriggerTop::
# 158 "data/maps/AzaleaTown/scripts.pory"
	lock
# 159 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 160 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_SILVER
# 161 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 162 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterTop
# 163 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 164 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 165 "data/maps/AzaleaTown/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 166 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
# 167 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 168 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
# 169 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
# 170 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
# 171 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_RIVAL_EXIT, TRUE
# 172 "data/maps/AzaleaTown/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 173 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
# 174 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 175 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveTop
# 176 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 177 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveTop
# 178 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 179 "data/maps/AzaleaTown/scripts.pory"
	playse SE_EXIT
# 180 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 181 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_SILVER
# 182 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 6
# 183 "data/maps/AzaleaTown/scripts.pory"
	savebgm MUS_DUMMY
# 184 "data/maps/AzaleaTown/scripts.pory"
	fadedefaultbgm
# 185 "data/maps/AzaleaTown/scripts.pory"
	release
# 186 "data/maps/AzaleaTown/scripts.pory"
	end
# 187 "data/maps/AzaleaTown/scripts.pory"

# 188 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_SilverTriggerBot::
# 189 "data/maps/AzaleaTown/scripts.pory"
	lock
# 190 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 191 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_SILVER
# 192 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 193 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterBot
# 194 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 195 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 196 "data/maps/AzaleaTown/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 197 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
# 198 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 199 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
# 200 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
# 201 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
# 202 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_RIVAL_EXIT, TRUE
# 203 "data/maps/AzaleaTown/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 204 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
# 205 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 206 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveBot
# 207 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 208 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveBot
# 209 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 210 "data/maps/AzaleaTown/scripts.pory"
	playse SE_EXIT
# 211 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 212 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_SILVER
# 213 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 6
# 214 "data/maps/AzaleaTown/scripts.pory"
	savebgm MUS_DUMMY
# 215 "data/maps/AzaleaTown/scripts.pory"
	fadedefaultbgm
# 216 "data/maps/AzaleaTown/scripts.pory"
	release
# 217 "data/maps/AzaleaTown/scripts.pory"
	end
# 218 "data/maps/AzaleaTown/scripts.pory"

# 219 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Cyndaquil::
# 220 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_2, AzaleaTown_Text_RivalWin
# 221 "data/maps/AzaleaTown/scripts.pory"
	return
# 222 "data/maps/AzaleaTown/scripts.pory"

# 223 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Totodile::
# 224 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_2, AzaleaTown_Text_RivalWin
# 225 "data/maps/AzaleaTown/scripts.pory"
	return
# 226 "data/maps/AzaleaTown/scripts.pory"

# 227 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Chikorita::
# 228 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_2, AzaleaTown_Text_RivalWin
# 229 "data/maps/AzaleaTown/scripts.pory"
	return
# 230 "data/maps/AzaleaTown/scripts.pory"

# 231 "data/maps/AzaleaTown/scripts.pory"

# 232 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_GSBall::
# 233 "data/maps/AzaleaTown/scripts.pory"
	lock
# 234 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerGSBall
# 235 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_KURT
# 237 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_KURT_GS
# 238 "data/maps/AzaleaTown/scripts.pory"
	opendoor 19, 11
# 239 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 240 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 241 "data/maps/AzaleaTown/scripts.pory"
	closedoor 19, 11
# 242 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 243 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_Kurt2
# 244 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 245 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 246 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt1, MSGBOX_DEFAULT
# 247 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 248 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 249 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt2, MSGBOX_DEFAULT
# 250 "data/maps/AzaleaTown/scripts.pory"
	giveitem ITEM_GS_BALL
# 251 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 252 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 253 "data/maps/AzaleaTown/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_WEST
# 254 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 255 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 256 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 257 "data/maps/AzaleaTown/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_SOUTH
# 258 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 259 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt3, MSGBOX_DEFAULT
# 260 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 261 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_KurtLeave
# 262 "data/maps/AzaleaTown/scripts.pory"
	delay 60
# 263 "data/maps/AzaleaTown/scripts.pory"
	opendoor 19, 11
# 264 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 265 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 266 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
# 267 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_KURT_GS
# 268 "data/maps/AzaleaTown/scripts.pory"
	closedoor 19, 11
# 269 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 270 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 9
# 271 "data/maps/AzaleaTown/scripts.pory"
	release
# 272 "data/maps/AzaleaTown/scripts.pory"
	end
# 273 "data/maps/AzaleaTown/scripts.pory"

# 274 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_EnterTop:
# 275 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 276 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 277 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 278 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 279 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 280 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 281 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 282 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 283 "data/maps/AzaleaTown/scripts.pory"

# 284 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_EnterBot:
# 285 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_down
# 286 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 287 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 288 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 289 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 290 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 291 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 292 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 293 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 294 "data/maps/AzaleaTown/scripts.pory"

# 295 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_LeaveTop:
# 296 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 297 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 298 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 299 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 300 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 301 "data/maps/AzaleaTown/scripts.pory"

# 302 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_LeaveBot:
# 303 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 304 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 305 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 306 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_up
# 307 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 308 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 309 "data/maps/AzaleaTown/scripts.pory"

# 310 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Player_LeaveTop:
# 311 "data/maps/AzaleaTown/scripts.pory"
	lock_facing_direction
# 312 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_down
# 313 "data/maps/AzaleaTown/scripts.pory"
	unlock_facing_direction
# 314 "data/maps/AzaleaTown/scripts.pory"
	face_up
# 315 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 316 "data/maps/AzaleaTown/scripts.pory"

# 317 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Player_LeaveBot:
# 318 "data/maps/AzaleaTown/scripts.pory"
	lock_facing_direction
# 319 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_up
# 320 "data/maps/AzaleaTown/scripts.pory"
	unlock_facing_direction
# 321 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 322 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 323 "data/maps/AzaleaTown/scripts.pory"

# 324 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Kurt1:
# 325 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 326 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 327 "data/maps/AzaleaTown/scripts.pory"

# 328 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Kurt2:
# 329 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 330 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 331 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 332 "data/maps/AzaleaTown/scripts.pory"
	face_right
# 333 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 334 "data/maps/AzaleaTown/scripts.pory"
	face_left
# 335 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 336 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 337 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 338 "data/maps/AzaleaTown/scripts.pory"

# 339 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_PlayerGSBall:
# 340 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 341 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 342 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 343 "data/maps/AzaleaTown/scripts.pory"
	face_left
# 344 "data/maps/AzaleaTown/scripts.pory"
	face_right
# 345 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 346 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 347 "data/maps/AzaleaTown/scripts.pory"
	face_up
# 348 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 349 "data/maps/AzaleaTown/scripts.pory"

# 350 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_KurtLeave:
# 351 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 352 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 353 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 354 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 355 "data/maps/AzaleaTown/scripts.pory"

# 356 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalBefore:
# 357 "data/maps/AzaleaTown/scripts.pory"
	.string "…Tell me something.\p"
# 358 "data/maps/AzaleaTown/scripts.pory"
	.string "Is it true that Team Rocket\n"
# 359 "data/maps/AzaleaTown/scripts.pory"
	.string "has returned?\p"
# 360 "data/maps/AzaleaTown/scripts.pory"
	.string "What? You beat them? Hah! Quit\n"
# 361 "data/maps/AzaleaTown/scripts.pory"
	.string "lying.\p"
# 362 "data/maps/AzaleaTown/scripts.pory"
	.string "You're not joking?\n"
# 363 "data/maps/AzaleaTown/scripts.pory"
	.string "Then let's see how good you are.$"
# 364 "data/maps/AzaleaTown/scripts.pory"

# 365 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalWin:
# 366 "data/maps/AzaleaTown/scripts.pory"
	.string "…Humph! Useless Pokémon!\p"
# 367 "data/maps/AzaleaTown/scripts.pory"
	.string "Listen, you. You only won because\n"
# 368 "data/maps/AzaleaTown/scripts.pory"
	.string "my Pokémon were weak.$"
# 369 "data/maps/AzaleaTown/scripts.pory"

# 370 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalAfter:
# 371 "data/maps/AzaleaTown/scripts.pory"
	.string "I hate the weak.\p"
# 372 "data/maps/AzaleaTown/scripts.pory"
	.string "Pokémon, trainers. It doesn't\n"
# 373 "data/maps/AzaleaTown/scripts.pory"
	.string "matter who or what.\p"
# 374 "data/maps/AzaleaTown/scripts.pory"
	.string "I'm going to be strong and wipe\n"
# 375 "data/maps/AzaleaTown/scripts.pory"
	.string "out the weak.\p"
# 376 "data/maps/AzaleaTown/scripts.pory"
	.string "That goes for Team Rocket too.\p"
# 377 "data/maps/AzaleaTown/scripts.pory"
	.string "They act big and tough in a group.\p"
# 378 "data/maps/AzaleaTown/scripts.pory"
	.string "But get them alone, and they're weak.\n"
# 379 "data/maps/AzaleaTown/scripts.pory"
	.string "I hate them all.\p"
# 380 "data/maps/AzaleaTown/scripts.pory"
	.string "You stay out of my way. A weakling\n"
# 381 "data/maps/AzaleaTown/scripts.pory"
	.string "like you is only a distraction.$"
# 382 "data/maps/AzaleaTown/scripts.pory"

# 383 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalLoss:
# 384 "data/maps/AzaleaTown/scripts.pory"
	.string "…Humph! I knew you were lying.$"
# 385 "data/maps/AzaleaTown/scripts.pory"

# 386 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Rocket1:
# 387 "data/maps/AzaleaTown/scripts.pory"
	.string "It's unsafe to go in there,\n"
# 388 "data/maps/AzaleaTown/scripts.pory"
	.string "so I'm standing guard.\p"
# 389 "data/maps/AzaleaTown/scripts.pory"
	.string "Aren't I a good Samaritan?$"
# 390 "data/maps/AzaleaTown/scripts.pory"

# 391 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Rocket2:
# 392 "data/maps/AzaleaTown/scripts.pory"
	.string "Do you know about Slowpoketail?\n"
# 393 "data/maps/AzaleaTown/scripts.pory"
	.string "I heard it's tasty!\p"
# 394 "data/maps/AzaleaTown/scripts.pory"
	.string "Aren't you glad I told you that?$"
# 395 "data/maps/AzaleaTown/scripts.pory"

# 396 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GrampsBefore:
# 397 "data/maps/AzaleaTown/scripts.pory"
	.string "The Slowpoke have disappeared\n"
# 398 "data/maps/AzaleaTown/scripts.pory"
	.string "from town…\p"
# 399 "data/maps/AzaleaTown/scripts.pory"
	.string "I heard their Tails are being\n"
# 400 "data/maps/AzaleaTown/scripts.pory"
	.string "sold somewhere.$"
# 401 "data/maps/AzaleaTown/scripts.pory"

# 402 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GrampsAfter:
# 403 "data/maps/AzaleaTown/scripts.pory"
	.string "The Slowpoke have returned.\p"
# 404 "data/maps/AzaleaTown/scripts.pory"
	.string "Knowing them, they could've just\n"
# 405 "data/maps/AzaleaTown/scripts.pory"
	.string "been goofing off somewhere.$"
# 406 "data/maps/AzaleaTown/scripts.pory"

# 407 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Teacher:
# 408 "data/maps/AzaleaTown/scripts.pory"
	.string "Did you come to get Kurt to make\n"
# 409 "data/maps/AzaleaTown/scripts.pory"
	.string "some Balls?\p"
# 410 "data/maps/AzaleaTown/scripts.pory"
	.string "A lot of people do just that.$"
# 411 "data/maps/AzaleaTown/scripts.pory"

# 412 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Youngster:
# 413 "data/maps/AzaleaTown/scripts.pory"
	.string "Cut through Azalea and you'll be\n"
# 414 "data/maps/AzaleaTown/scripts.pory"
	.string "in Ilex Forest.\p"
# 415 "data/maps/AzaleaTown/scripts.pory"
	.string "But these skinny trees make it\n"
# 416 "data/maps/AzaleaTown/scripts.pory"
	.string "impossible to get through.\p"
# 417 "data/maps/AzaleaTown/scripts.pory"
	.string "The Charcoal Man's Pokémon\n"
# 418 "data/maps/AzaleaTown/scripts.pory"
	.string "can Cut down trees.$"
# 419 "data/maps/AzaleaTown/scripts.pory"

# 420 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Slowpoke1:
# 421 "data/maps/AzaleaTown/scripts.pory"
	.string "Slowpoke:..........\p"
# 422 "data/maps/AzaleaTown/scripts.pory"
	.string "...............Yawn?$"
# 423 "data/maps/AzaleaTown/scripts.pory"

# 424 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt1:
# 425 "data/maps/AzaleaTown/scripts.pory"
	.string "Ilex Forest is restless!\p"
# 426 "data/maps/AzaleaTown/scripts.pory"
	.string "What is going on?$"
# 427 "data/maps/AzaleaTown/scripts.pory"

# 428 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt2:
# 429 "data/maps/AzaleaTown/scripts.pory"
	.string "{PLAYER}, here's your GS Ball back!$"
# 430 "data/maps/AzaleaTown/scripts.pory"

# 431 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt3:
# 432 "data/maps/AzaleaTown/scripts.pory"
	.string "Could you go see why Ilex Forest\n"
# 433 "data/maps/AzaleaTown/scripts.pory"
	.string "is so restless?$"
# 434 "data/maps/AzaleaTown/scripts.pory"

# 435 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Sign:
# 436 "data/maps/AzaleaTown/scripts.pory"
	.string "Azalea Town\n"
# 437 "data/maps/AzaleaTown/scripts.pory"
	.string "Where People and Pokémon Live in\l"
# 438 "data/maps/AzaleaTown/scripts.pory"
	.string "Happy Harmony.$"
# 439 "data/maps/AzaleaTown/scripts.pory"

# 440 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_KurtsHouseSign:
# 441 "data/maps/AzaleaTown/scripts.pory"
	.string "Kurt's House$"
# 442 "data/maps/AzaleaTown/scripts.pory"

# 443 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GymSign:
# 444 "data/maps/AzaleaTown/scripts.pory"
	.string "Azalea Town\n"
# 445 "data/maps/AzaleaTown/scripts.pory"
	.string "Pokémon Gym\p"
# 446 "data/maps/AzaleaTown/scripts.pory"
	.string "Leader: Bugsy\p"
# 447 "data/maps/AzaleaTown/scripts.pory"
	.string "The Walking Bug Pokémon\n"
# 448 "data/maps/AzaleaTown/scripts.pory"
	.string "Encyclopedia$"
# 449 "data/maps/AzaleaTown/scripts.pory"

# 450 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_SlowpokeWellSign:
# 451 "data/maps/AzaleaTown/scripts.pory"
	.string "Slowpoke Well\p"
# 452 "data/maps/AzaleaTown/scripts.pory"
	.string "Also known as the Rainmaker Well.\p"
# 453 "data/maps/AzaleaTown/scripts.pory"
	.string "Locals believe that a Slowpoke's\n"
# 454 "data/maps/AzaleaTown/scripts.pory"
	.string "yawn summons rain.\p"
# 455 "data/maps/AzaleaTown/scripts.pory"
	.string "Records show that a Slowpoke's\n"
# 456 "data/maps/AzaleaTown/scripts.pory"
	.string "yawn ended a drought 400 years ago.$"
# 457 "data/maps/AzaleaTown/scripts.pory"

# 458 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_CharcoalKilnSign:
# 459 "data/maps/AzaleaTown/scripts.pory"
	.string "Charcoal Kiln$"
# 460 "data/maps/AzaleaTown/scripts.pory"

# 461 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_IlexForestSign:
# 462 "data/maps/AzaleaTown/scripts.pory"
	.string "Ilex Forest\p"
# 463 "data/maps/AzaleaTown/scripts.pory"
	.string "Enter through the gate.$"

AzaleaTownKid::
# 467 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTownKid_Text_0, MSGBOX_NPC
	return


AzaleaTownVulpix::
# 472 "data/maps/AzaleaTown/scripts.pory"
	lock
# 473 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 474 "data/maps/AzaleaTown/scripts.pory"
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
# 475 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTownVulpix_Text_0
# 476 "data/maps/AzaleaTown/scripts.pory"
	waitmessage
# 477 "data/maps/AzaleaTown/scripts.pory"
	release
	end


AzaleaTownKid_Text_0:
# 467 "data/maps/AzaleaTown/scripts.pory"
	.string "That Vulpix keeps taunting me from up\n"
	.string "there... If only I could use Rock Climb.$"

AzaleaTownVulpix_Text_0:
# 475 "data/maps/AzaleaTown/scripts.pory"
	.string "Vulpix: Vul!$"
