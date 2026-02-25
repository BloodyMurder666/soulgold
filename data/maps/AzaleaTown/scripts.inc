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
	removeitem ITEM_HM_SURF
# 55 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 1
# 56 "data/maps/AzaleaTown/scripts.pory"
	end
# 57 "data/maps/AzaleaTown/scripts.pory"

# 58 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Rocket1::
# 59 "data/maps/AzaleaTown/scripts.pory"
	lock
# 60 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 61 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Rocket1, MSGBOX_DEFAULT
# 62 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 63 "data/maps/AzaleaTown/scripts.pory"
	release
# 64 "data/maps/AzaleaTown/scripts.pory"
	end
# 65 "data/maps/AzaleaTown/scripts.pory"

# 66 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Rocket2::
# 67 "data/maps/AzaleaTown/scripts.pory"
	lock
# 68 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 69 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Rocket2, MSGBOX_DEFAULT
# 70 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 71 "data/maps/AzaleaTown/scripts.pory"
	release
# 72 "data/maps/AzaleaTown/scripts.pory"
	end
# 73 "data/maps/AzaleaTown/scripts.pory"

# 74 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Gramps::
# 75 "data/maps/AzaleaTown/scripts.pory"
	lock
# 76 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 77 "data/maps/AzaleaTown/scripts.pory"
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_EventScript_Gramps2
# 78 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
# 79 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 80 "data/maps/AzaleaTown/scripts.pory"
	release
# 81 "data/maps/AzaleaTown/scripts.pory"
	end
# 82 "data/maps/AzaleaTown/scripts.pory"

# 83 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Gramps2::
# 84 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
# 85 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 86 "data/maps/AzaleaTown/scripts.pory"
	release
# 87 "data/maps/AzaleaTown/scripts.pory"
	end
# 88 "data/maps/AzaleaTown/scripts.pory"

# 89 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Lass::
# 90 "data/maps/AzaleaTown/scripts.pory"
	lock
# 91 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 92 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Teacher, MSGBOX_DEFAULT
# 93 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 94 "data/maps/AzaleaTown/scripts.pory"
	release
# 95 "data/maps/AzaleaTown/scripts.pory"
	end
# 96 "data/maps/AzaleaTown/scripts.pory"

# 97 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Youngster::
# 98 "data/maps/AzaleaTown/scripts.pory"
	lock
# 99 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 100 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Youngster, MSGBOX_DEFAULT
# 101 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 102 "data/maps/AzaleaTown/scripts.pory"
	release
# 103 "data/maps/AzaleaTown/scripts.pory"
	end
# 104 "data/maps/AzaleaTown/scripts.pory"

# 105 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_Slowpoke::
# 106 "data/maps/AzaleaTown/scripts.pory"
	lock
# 107 "data/maps/AzaleaTown/scripts.pory"
	faceplayer
# 108 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 109 "data/maps/AzaleaTown/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 110 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
# 111 "data/maps/AzaleaTown/scripts.pory"
	waitmoncry
# 112 "data/maps/AzaleaTown/scripts.pory"
	release
# 113 "data/maps/AzaleaTown/scripts.pory"
	end
# 114 "data/maps/AzaleaTown/scripts.pory"

# 115 "data/maps/AzaleaTown/scripts.pory"

# 116 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_GymSign::
# 117 "data/maps/AzaleaTown/scripts.pory"
	lock
# 118 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
# 119 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 120 "data/maps/AzaleaTown/scripts.pory"
	release
# 121 "data/maps/AzaleaTown/scripts.pory"
	end
# 122 "data/maps/AzaleaTown/scripts.pory"

# 123 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_KurtSign::
# 124 "data/maps/AzaleaTown/scripts.pory"
	lock
# 125 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
# 126 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 127 "data/maps/AzaleaTown/scripts.pory"
	release
# 128 "data/maps/AzaleaTown/scripts.pory"
	end
# 129 "data/maps/AzaleaTown/scripts.pory"

# 130 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_KilnSign::
# 131 "data/maps/AzaleaTown/scripts.pory"
	lock
# 132 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
# 133 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 134 "data/maps/AzaleaTown/scripts.pory"
	release
# 135 "data/maps/AzaleaTown/scripts.pory"
	end
# 136 "data/maps/AzaleaTown/scripts.pory"

# 137 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_IlexSign::
# 138 "data/maps/AzaleaTown/scripts.pory"
	lock
# 139 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_IlexForestSign, MSGBOX_SIGN
# 140 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 141 "data/maps/AzaleaTown/scripts.pory"
	release
# 142 "data/maps/AzaleaTown/scripts.pory"
	end
# 143 "data/maps/AzaleaTown/scripts.pory"

# 144 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_WellSign::
# 145 "data/maps/AzaleaTown/scripts.pory"
	lock
# 146 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
# 147 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 148 "data/maps/AzaleaTown/scripts.pory"
	release
# 149 "data/maps/AzaleaTown/scripts.pory"
	end
# 150 "data/maps/AzaleaTown/scripts.pory"

# 151 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_AzaleaSign::
# 152 "data/maps/AzaleaTown/scripts.pory"
	lock
# 153 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
# 154 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 155 "data/maps/AzaleaTown/scripts.pory"
	release
# 156 "data/maps/AzaleaTown/scripts.pory"
	end
# 157 "data/maps/AzaleaTown/scripts.pory"

# 158 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_SilverTriggerTop::
# 159 "data/maps/AzaleaTown/scripts.pory"
	lock
# 160 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 161 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_SILVER
# 162 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 163 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterTop
# 164 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 165 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
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
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
# 172 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 173 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveTop
# 174 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 175 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveTop
# 176 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 177 "data/maps/AzaleaTown/scripts.pory"
	playse SE_EXIT
# 178 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 179 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_SILVER
# 180 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 6
# 181 "data/maps/AzaleaTown/scripts.pory"
	fadedefaultbgm
# 182 "data/maps/AzaleaTown/scripts.pory"
	release
# 183 "data/maps/AzaleaTown/scripts.pory"
	end
# 184 "data/maps/AzaleaTown/scripts.pory"

# 185 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_SilverTriggerBot::
# 186 "data/maps/AzaleaTown/scripts.pory"
	lock
# 187 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 188 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_SILVER
# 189 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 190 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterBot
# 191 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 192 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 193 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
# 194 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 195 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
# 196 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
# 197 "data/maps/AzaleaTown/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
# 198 "data/maps/AzaleaTown/scripts.pory"
	playbgm MUS_HG_RIVAL_EXIT, TRUE
# 199 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
# 200 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 201 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveBot
# 202 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 203 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveBot
# 204 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 205 "data/maps/AzaleaTown/scripts.pory"
	playse SE_EXIT
# 206 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
# 207 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_SILVER
# 208 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 6
# 209 "data/maps/AzaleaTown/scripts.pory"
	fadedefaultbgm
# 210 "data/maps/AzaleaTown/scripts.pory"
	release
# 211 "data/maps/AzaleaTown/scripts.pory"
	end
# 212 "data/maps/AzaleaTown/scripts.pory"

# 213 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Cyndaquil::
# 214 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_2, AzaleaTown_Text_RivalWin
# 215 "data/maps/AzaleaTown/scripts.pory"
	return
# 216 "data/maps/AzaleaTown/scripts.pory"

# 217 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Totodile::
# 218 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_2, AzaleaTown_Text_RivalWin
# 219 "data/maps/AzaleaTown/scripts.pory"
	return
# 220 "data/maps/AzaleaTown/scripts.pory"

# 221 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Silver_Battle_Chikorita::
# 222 "data/maps/AzaleaTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_2, AzaleaTown_Text_RivalWin
# 223 "data/maps/AzaleaTown/scripts.pory"
	return
# 224 "data/maps/AzaleaTown/scripts.pory"

# 225 "data/maps/AzaleaTown/scripts.pory"

# 226 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_EventScript_GSBall::
# 227 "data/maps/AzaleaTown/scripts.pory"
	lock
# 228 "data/maps/AzaleaTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerGSBall
# 229 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 230 "data/maps/AzaleaTown/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_KURT
# 231 "data/maps/AzaleaTown/scripts.pory"
	addobject LOCALID_AZALEA_TOWN_KURT_GS
# 232 "data/maps/AzaleaTown/scripts.pory"
	opendoor 19, 11
# 233 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 234 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 235 "data/maps/AzaleaTown/scripts.pory"
	closedoor 19, 11
# 236 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 237 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_Kurt2
# 238 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 239 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 240 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt1, MSGBOX_DEFAULT
# 241 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 242 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 243 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt2, MSGBOX_DEFAULT
# 244 "data/maps/AzaleaTown/scripts.pory"
	giveitem ITEM_HEAVY_BALL
# 245 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 246 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 247 "data/maps/AzaleaTown/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_WEST
# 248 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 249 "data/maps/AzaleaTown/scripts.pory"
	playse SE_M_PETAL_DANCE
# 250 "data/maps/AzaleaTown/scripts.pory"
	waitse
# 251 "data/maps/AzaleaTown/scripts.pory"
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_SOUTH
# 252 "data/maps/AzaleaTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 253 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTown_Text_Kurt3, MSGBOX_DEFAULT
# 254 "data/maps/AzaleaTown/scripts.pory"
	closemessage
# 255 "data/maps/AzaleaTown/scripts.pory"
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_KurtLeave
# 256 "data/maps/AzaleaTown/scripts.pory"
	delay 60
# 257 "data/maps/AzaleaTown/scripts.pory"
	opendoor 19, 11
# 258 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 259 "data/maps/AzaleaTown/scripts.pory"
	waitmovement 0
# 260 "data/maps/AzaleaTown/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
# 261 "data/maps/AzaleaTown/scripts.pory"
	removeobject LOCALID_AZALEA_TOWN_KURT_GS
# 262 "data/maps/AzaleaTown/scripts.pory"
	closedoor 19, 11
# 263 "data/maps/AzaleaTown/scripts.pory"
	waitdooranim
# 264 "data/maps/AzaleaTown/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 9
# 265 "data/maps/AzaleaTown/scripts.pory"
	release
# 266 "data/maps/AzaleaTown/scripts.pory"
	end
# 267 "data/maps/AzaleaTown/scripts.pory"

# 268 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_EnterTop:
# 269 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 270 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 271 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 272 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 273 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 274 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 275 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 276 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 277 "data/maps/AzaleaTown/scripts.pory"

# 278 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_EnterBot:
# 279 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_down
# 280 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 281 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 282 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 283 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 284 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 285 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 286 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 287 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 288 "data/maps/AzaleaTown/scripts.pory"

# 289 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_LeaveTop:
# 290 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 291 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 292 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 293 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 294 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 295 "data/maps/AzaleaTown/scripts.pory"

# 296 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Silver_LeaveBot:
# 297 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 298 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 299 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 300 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_left
# 302 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 303 "data/maps/AzaleaTown/scripts.pory"

# 304 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Player_LeaveTop:
# 305 "data/maps/AzaleaTown/scripts.pory"
	lock_facing_direction
# 306 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_down
# 307 "data/maps/AzaleaTown/scripts.pory"
	unlock_facing_direction
# 308 "data/maps/AzaleaTown/scripts.pory"
	face_up
# 309 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 310 "data/maps/AzaleaTown/scripts.pory"

# 311 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Player_LeaveBot:
# 312 "data/maps/AzaleaTown/scripts.pory"
	lock_facing_direction
# 313 "data/maps/AzaleaTown/scripts.pory"
	walk_fast_up
# 314 "data/maps/AzaleaTown/scripts.pory"
	unlock_facing_direction
# 315 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 316 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 317 "data/maps/AzaleaTown/scripts.pory"

# 318 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Kurt1:
# 319 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 320 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 321 "data/maps/AzaleaTown/scripts.pory"

# 322 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_Kurt2:
# 323 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 324 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 325 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 326 "data/maps/AzaleaTown/scripts.pory"
	face_right
# 327 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 328 "data/maps/AzaleaTown/scripts.pory"
	face_left
# 329 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 330 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 331 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 332 "data/maps/AzaleaTown/scripts.pory"

# 333 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_PlayerGSBall:
# 334 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 335 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 336 "data/maps/AzaleaTown/scripts.pory"
	walk_down
# 337 "data/maps/AzaleaTown/scripts.pory"
	face_left
# 338 "data/maps/AzaleaTown/scripts.pory"
	face_right
# 339 "data/maps/AzaleaTown/scripts.pory"
	face_down
# 340 "data/maps/AzaleaTown/scripts.pory"
	delay_8
# 341 "data/maps/AzaleaTown/scripts.pory"
	face_up
# 342 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 343 "data/maps/AzaleaTown/scripts.pory"

# 344 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Movement_KurtLeave:
# 345 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 346 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 347 "data/maps/AzaleaTown/scripts.pory"
	walk_up
# 348 "data/maps/AzaleaTown/scripts.pory"
	step_end
# 349 "data/maps/AzaleaTown/scripts.pory"

# 350 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalBefore:
# 351 "data/maps/AzaleaTown/scripts.pory"
	.string "…Tell me something.\p"
# 352 "data/maps/AzaleaTown/scripts.pory"
	.string "Is it true that TEAM ROCKET\n"
# 353 "data/maps/AzaleaTown/scripts.pory"
	.string "has returned?\p"
# 354 "data/maps/AzaleaTown/scripts.pory"
	.string "What? You beat them? Hah! Quit\n"
# 355 "data/maps/AzaleaTown/scripts.pory"
	.string "lying.\p"
# 356 "data/maps/AzaleaTown/scripts.pory"
	.string "You're not joking?\n"
# 357 "data/maps/AzaleaTown/scripts.pory"
	.string "Then let's see how good you are.$"
# 358 "data/maps/AzaleaTown/scripts.pory"

# 359 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalWin:
# 360 "data/maps/AzaleaTown/scripts.pory"
	.string "…Humph! Useless POKéMON!\p"
# 361 "data/maps/AzaleaTown/scripts.pory"
	.string "Listen, you. You only won because\n"
# 362 "data/maps/AzaleaTown/scripts.pory"
	.string "my POKéMON were weak.$"
# 363 "data/maps/AzaleaTown/scripts.pory"

# 364 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalAfter:
# 365 "data/maps/AzaleaTown/scripts.pory"
	.string "I hate the weak.\p"
# 366 "data/maps/AzaleaTown/scripts.pory"
	.string "POKéMON, trainers. It doesn't\n"
# 367 "data/maps/AzaleaTown/scripts.pory"
	.string "matter who or what.\p"
# 368 "data/maps/AzaleaTown/scripts.pory"
	.string "I'm going to be strong and wipe\n"
# 369 "data/maps/AzaleaTown/scripts.pory"
	.string "out the weak.\p"
# 370 "data/maps/AzaleaTown/scripts.pory"
	.string "That goes for TEAM ROCKET too.\p"
# 371 "data/maps/AzaleaTown/scripts.pory"
	.string "They act big and tough in a group.\p"
# 372 "data/maps/AzaleaTown/scripts.pory"
	.string "But get them alone, and they're weak.\n"
# 373 "data/maps/AzaleaTown/scripts.pory"
	.string "I hate them all.\p"
# 374 "data/maps/AzaleaTown/scripts.pory"
	.string "You stay out of my way. A weakling\n"
# 375 "data/maps/AzaleaTown/scripts.pory"
	.string "like you is only a distraction.$"
# 376 "data/maps/AzaleaTown/scripts.pory"

# 377 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_RivalLoss:
# 378 "data/maps/AzaleaTown/scripts.pory"
	.string "…Humph! I knew you were lying.$"
# 379 "data/maps/AzaleaTown/scripts.pory"

# 380 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Rocket1:
# 381 "data/maps/AzaleaTown/scripts.pory"
	.string "It's unsafe to go in there,\n"
# 382 "data/maps/AzaleaTown/scripts.pory"
	.string "so I'm standing guard.\p"
# 383 "data/maps/AzaleaTown/scripts.pory"
	.string "Aren't I a good Samaritan?$"
# 384 "data/maps/AzaleaTown/scripts.pory"

# 385 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Rocket2:
# 386 "data/maps/AzaleaTown/scripts.pory"
	.string "Do you know about SLOWPOKETAIL?\n"
# 387 "data/maps/AzaleaTown/scripts.pory"
	.string "I heard it's tasty!\p"
# 388 "data/maps/AzaleaTown/scripts.pory"
	.string "Aren't you glad I told you that?$"
# 389 "data/maps/AzaleaTown/scripts.pory"

# 390 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GrampsBefore:
# 391 "data/maps/AzaleaTown/scripts.pory"
	.string "The SLOWPOKE have disappeared\n"
# 392 "data/maps/AzaleaTown/scripts.pory"
	.string "from town…\p"
# 393 "data/maps/AzaleaTown/scripts.pory"
	.string "I heard their TAILS are being\n"
# 394 "data/maps/AzaleaTown/scripts.pory"
	.string "sold somewhere.$"
# 395 "data/maps/AzaleaTown/scripts.pory"

# 396 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GrampsAfter:
# 397 "data/maps/AzaleaTown/scripts.pory"
	.string "The SLOWPOKE have returned.\p"
# 398 "data/maps/AzaleaTown/scripts.pory"
	.string "Knowing them, they could've just\n"
# 399 "data/maps/AzaleaTown/scripts.pory"
	.string "been goofing off somewhere.$"
# 400 "data/maps/AzaleaTown/scripts.pory"

# 401 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Teacher:
# 402 "data/maps/AzaleaTown/scripts.pory"
	.string "Did you come to get KURT to make\n"
# 403 "data/maps/AzaleaTown/scripts.pory"
	.string "some BALLS?\p"
# 404 "data/maps/AzaleaTown/scripts.pory"
	.string "A lot of people do just that.$"
# 405 "data/maps/AzaleaTown/scripts.pory"

# 406 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Youngster:
# 407 "data/maps/AzaleaTown/scripts.pory"
	.string "Cut through AZALEA and you'll be\n"
# 408 "data/maps/AzaleaTown/scripts.pory"
	.string "in ILEX FOREST.\p"
# 409 "data/maps/AzaleaTown/scripts.pory"
	.string "But these skinny trees make it\n"
# 410 "data/maps/AzaleaTown/scripts.pory"
	.string "impossible to get through.\p"
# 411 "data/maps/AzaleaTown/scripts.pory"
	.string "The CHARCOAL MAN's POKéMON\n"
# 412 "data/maps/AzaleaTown/scripts.pory"
	.string "can CUT down trees.$"
# 413 "data/maps/AzaleaTown/scripts.pory"

# 414 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Slowpoke1:
# 415 "data/maps/AzaleaTown/scripts.pory"
	.string "SLOWPOKE:..........\p"
# 416 "data/maps/AzaleaTown/scripts.pory"
	.string "...............YAWN?$"
# 417 "data/maps/AzaleaTown/scripts.pory"

# 418 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt1:
# 419 "data/maps/AzaleaTown/scripts.pory"
	.string "ILEX FOREST is restless!\p"
# 420 "data/maps/AzaleaTown/scripts.pory"
	.string "What is going on?$"
# 421 "data/maps/AzaleaTown/scripts.pory"

# 422 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt2:
# 423 "data/maps/AzaleaTown/scripts.pory"
	.string "{PLAYER}, here's your GS BALL back!$"
# 424 "data/maps/AzaleaTown/scripts.pory"

# 425 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Kurt3:
# 426 "data/maps/AzaleaTown/scripts.pory"
	.string "Could you go see why ILEX FOREST\n"
# 427 "data/maps/AzaleaTown/scripts.pory"
	.string "is so restless?$"
# 428 "data/maps/AzaleaTown/scripts.pory"

# 429 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_Sign:
# 430 "data/maps/AzaleaTown/scripts.pory"
	.string "AZALEA TOWN\n"
# 431 "data/maps/AzaleaTown/scripts.pory"
	.string "Where People and POKéMON Live in\l"
# 432 "data/maps/AzaleaTown/scripts.pory"
	.string "Happy Harmony.$"
# 433 "data/maps/AzaleaTown/scripts.pory"

# 434 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_KurtsHouseSign:
# 435 "data/maps/AzaleaTown/scripts.pory"
	.string "KURT'S HOUSE$"
# 436 "data/maps/AzaleaTown/scripts.pory"

# 437 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_GymSign:
# 438 "data/maps/AzaleaTown/scripts.pory"
	.string "AZALEA TOWN\n"
# 439 "data/maps/AzaleaTown/scripts.pory"
	.string "POKéMON GYM\p"
# 440 "data/maps/AzaleaTown/scripts.pory"
	.string "LEADER: BUGSY\p"
# 441 "data/maps/AzaleaTown/scripts.pory"
	.string "The Walking Bug POKéMON\n"
# 442 "data/maps/AzaleaTown/scripts.pory"
	.string "Encyclopedia$"
# 443 "data/maps/AzaleaTown/scripts.pory"

# 444 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_SlowpokeWellSign:
# 445 "data/maps/AzaleaTown/scripts.pory"
	.string "SLOWPOKE WELL\p"
# 446 "data/maps/AzaleaTown/scripts.pory"
	.string "Also known as the RAINMAKER WELL.\p"
# 447 "data/maps/AzaleaTown/scripts.pory"
	.string "Locals believe that a SLOWPOKE's\n"
# 448 "data/maps/AzaleaTown/scripts.pory"
	.string "yawn summons rain.\p"
# 449 "data/maps/AzaleaTown/scripts.pory"
	.string "Records show that a SLOWPOKE's\n"
# 450 "data/maps/AzaleaTown/scripts.pory"
	.string "yawn ended a drought 400 years ago.$"
# 451 "data/maps/AzaleaTown/scripts.pory"

# 452 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_CharcoalKilnSign:
# 453 "data/maps/AzaleaTown/scripts.pory"
	.string "CHARCOAL KILN$"
# 454 "data/maps/AzaleaTown/scripts.pory"

# 455 "data/maps/AzaleaTown/scripts.pory"
AzaleaTown_Text_IlexForestSign:
# 456 "data/maps/AzaleaTown/scripts.pory"
	.string "ILEX FOREST\p"
# 457 "data/maps/AzaleaTown/scripts.pory"
	.string "Enter through the gate.$"

AzaleaTownKid::
# 461 "data/maps/AzaleaTown/scripts.pory"
	msgbox AzaleaTownKid_Text_0, MSGBOX_NPC
	return


AzaleaTownKid_Text_0:
# 461 "data/maps/AzaleaTown/scripts.pory"
	.string "That vulpix keeps taunting me from up\n"
	.string "there... If only I could use Rock Climb.$"
