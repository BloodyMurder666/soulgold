# 1 "data/maps/IlexForest/scripts.pory"

# 2 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_FARFETCHD_1, 3
# 3 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_FARFETCHD_2, 31
# 4 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_FARFETCHD_3, 33
# 5 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_FARFETCHD_4, 32
# 6 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_CELEBI, 7
# 7 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_KURT, 34
# 8 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_KIMONO, 36
# 9 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_BUTTERFREE, 37
# 10 "data/maps/IlexForest/scripts.pory"
.set LOCALID_ILEX_FOREST_SECOND_CELEBI, 38
# 11 "data/maps/IlexForest/scripts.pory"

# 12 "data/maps/IlexForest/scripts.pory"
IlexForest_MapScripts::
# 13 "data/maps/IlexForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
# 14 "data/maps/IlexForest/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 15 "data/maps/IlexForest/scripts.pory"
	.byte 0
# 16 "data/maps/IlexForest/scripts.pory"

# 17 "data/maps/IlexForest/scripts.pory"
IlexForest_OnTransition: 
# 18 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_ReenterWhenFarfetchdLeaving
# 19 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_ReenterDuringCutScene
# 20 "data/maps/IlexForest/scripts.pory"
	callnative SetTimeBasedEncounters
# 21 "data/maps/IlexForest/scripts.pory"
	end	
# 22 "data/maps/IlexForest/scripts.pory"

# 23 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_ReenterWhenFarfetchdLeaving::
# 24 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
# 25 "data/maps/IlexForest/scripts.pory"
	return
# 26 "data/maps/IlexForest/scripts.pory"

# 27 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_ReenterDuringCutScene::
# 28 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
# 29 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 30 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
# 31 "data/maps/IlexForest/scripts.pory"
	return
# 32 "data/maps/IlexForest/scripts.pory"

# 33 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Apprentice::
# 34 "data/maps/IlexForest/scripts.pory"
	lock
# 35 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 36 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Apprentice2
# 37 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Apprentice2
# 38 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ApprenticeIntro, MSGBOX_DEFAULT
# 39 "data/maps/IlexForest/scripts.pory"
	closemessage
# 40 "data/maps/IlexForest/scripts.pory"
	release
# 41 "data/maps/IlexForest/scripts.pory"
	end
# 42 "data/maps/IlexForest/scripts.pory"

# 43 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Apprentice2::
# 44 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ApprenticeAfter, MSGBOX_DEFAULT
# 45 "data/maps/IlexForest/scripts.pory"
	closemessage
# 46 "data/maps/IlexForest/scripts.pory"
	release
# 47 "data/maps/IlexForest/scripts.pory"
	end
# 48 "data/maps/IlexForest/scripts.pory"

# 49 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Boss::
# 50 "data/maps/IlexForest/scripts.pory"
	lock
# 51 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 52 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterTalkAfter, MSGBOX_DEFAULT
# 53 "data/maps/IlexForest/scripts.pory"
	closemessage
# 54 "data/maps/IlexForest/scripts.pory"
	release
# 55 "data/maps/IlexForest/scripts.pory"
	end
# 56 "data/maps/IlexForest/scripts.pory"

# 57 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_1A::
# 58 "data/maps/IlexForest/scripts.pory"
	lock
# 59 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 60 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 61 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 62 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 63 "data/maps/IlexForest/scripts.pory"
	closemessage
# 64 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Farfetchd_Done
# 65 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Farfetchd_Done
# 66 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_Farfetchd_Leave
# 67 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_1B
# 68 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1A
# 69 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 70 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 71 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 72 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 73 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 74 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 75 "data/maps/IlexForest/scripts.pory"
	release
# 76 "data/maps/IlexForest/scripts.pory"
	end
# 77 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_1B::
# 78 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1B
# 79 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 80 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 1
# 81 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
# 82 "data/maps/IlexForest/scripts.pory"
	release
# 83 "data/maps/IlexForest/scripts.pory"
	end
# 84 "data/maps/IlexForest/scripts.pory"

# 85 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_2A::
# 86 "data/maps/IlexForest/scripts.pory"
	lock
# 87 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 88 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 89 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 90 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 91 "data/maps/IlexForest/scripts.pory"
	closemessage
# 92 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_2B
# 93 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2A
# 94 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 95 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 96 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 97 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 98 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 99 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 100 "data/maps/IlexForest/scripts.pory"
	release
# 101 "data/maps/IlexForest/scripts.pory"
	end
# 102 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_2B::
# 103 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2B
# 104 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 105 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 106 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 107 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 108 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 109 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 110 "data/maps/IlexForest/scripts.pory"
	release
# 111 "data/maps/IlexForest/scripts.pory"
	end
# 112 "data/maps/IlexForest/scripts.pory"

# 113 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_3A::
# 114 "data/maps/IlexForest/scripts.pory"
	lock
# 115 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 116 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 117 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 118 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 119 "data/maps/IlexForest/scripts.pory"
	closemessage
# 120 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_3B
# 121 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3A
# 122 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 123 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 124 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 125 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 126 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 127 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 128 "data/maps/IlexForest/scripts.pory"
	release
# 129 "data/maps/IlexForest/scripts.pory"
	end
# 130 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_3B::
# 131 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3B
# 132 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 133 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 134 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 135 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 136 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 137 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 138 "data/maps/IlexForest/scripts.pory"
	release
# 139 "data/maps/IlexForest/scripts.pory"
	end
# 140 "data/maps/IlexForest/scripts.pory"

# 141 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_4A::
# 142 "data/maps/IlexForest/scripts.pory"
	lock
# 143 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 144 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 145 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 146 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 147 "data/maps/IlexForest/scripts.pory"
	closemessage
# 148 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_4B
# 149 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4A
# 150 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 151 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 152 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 153 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 154 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 155 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 156 "data/maps/IlexForest/scripts.pory"
	release
# 157 "data/maps/IlexForest/scripts.pory"
	end
# 158 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_4B::
# 159 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4B
# 160 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 161 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 162 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 163 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 164 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 165 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 166 "data/maps/IlexForest/scripts.pory"
	release
# 167 "data/maps/IlexForest/scripts.pory"
	end
# 168 "data/maps/IlexForest/scripts.pory"

# 169 "data/maps/IlexForest/scripts.pory"

# 170 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Leave::
# 171 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, IlexForest_EventScript_Farfetchd_Return
# 172 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Leave
# 173 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 174 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
# 175 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 2
# 176 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
# 177 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
# 178 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
# 179 "data/maps/IlexForest/scripts.pory"
	addobject 1
# 180 "data/maps/IlexForest/scripts.pory"
	release
# 181 "data/maps/IlexForest/scripts.pory"
	end
# 182 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Return::
# 183 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 0
# 184 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Return
# 185 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 186 "data/maps/IlexForest/scripts.pory"
	release
# 187 "data/maps/IlexForest/scripts.pory"
	end
# 188 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Done::
# 189 "data/maps/IlexForest/scripts.pory"
	release
# 190 "data/maps/IlexForest/scripts.pory"
	end
# 191 "data/maps/IlexForest/scripts.pory"

# 192 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_TriggerBot::
# 193 "data/maps/IlexForest/scripts.pory"
	lock
# 194 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkUp
# 195 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 196 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Trigger::
# 197 "data/maps/IlexForest/scripts.pory"
	lock
# 198 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 199 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterIntro, MSGBOX_DEFAULT
# 200 "data/maps/IlexForest/scripts.pory"
	closemessage
# 201 "data/maps/IlexForest/scripts.pory"
	giveitem ITEM_HM_CUT
# 202 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 203 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterOutro, MSGBOX_DEFAULT
# 204 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_RECEIVED_HM_CUT
# 205 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
# 206 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 207 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 208 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 3
# 209 "data/maps/IlexForest/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 7
# 210 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
# 211 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
# 212 "data/maps/IlexForest/scripts.pory"
	closemessage
# 213 "data/maps/IlexForest/scripts.pory"
	release
# 214 "data/maps/IlexForest/scripts.pory"
	end
# 215 "data/maps/IlexForest/scripts.pory"

# 216 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Picnicker::
# 217 "data/maps/IlexForest/scripts.pory"
	lock
# 218 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 219 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Lass, MSGBOX_DEFAULT
# 220 "data/maps/IlexForest/scripts.pory"
	closemessage
# 221 "data/maps/IlexForest/scripts.pory"
	release
# 222 "data/maps/IlexForest/scripts.pory"
	end
# 223 "data/maps/IlexForest/scripts.pory"

# 224 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_BugcatcherWayne::
# 225 "data/maps/IlexForest/scripts.pory"
	trainerbattle_single TRAINER_WAYNE IlexForest_Text_BugCatcherWayneSeen, IlexForest_Text_BugCatcherWayneBeaten
# 226 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_BugCatcherWayneAfter, MSGBOX_AUTOCLOSE
# 227 "data/maps/IlexForest/scripts.pory"
	end
# 228 "data/maps/IlexForest/scripts.pory"

# 229 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_HeadbuttMoveTutor::
# 230 "data/maps/IlexForest/scripts.pory"
	lock
# 231 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 232 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttTeach, MSGBOX_YESNO
# 233 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_HeadbuttDeclined
# 234 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttWhichMon, MSGBOX_DEFAULT
# 235 "data/maps/IlexForest/scripts.pory"
	setvar VAR_0x8005, MOVE_HEADBUTT
# 236 "data/maps/IlexForest/scripts.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 237 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_HeadbuttDeclined
# 238 "data/maps/IlexForest/scripts.pory"
	goto MoveTutor_EventScript_HeadbuttTaught
# 239 "data/maps/IlexForest/scripts.pory"
	end
# 240 "data/maps/IlexForest/scripts.pory"

# 241 "data/maps/IlexForest/scripts.pory"
MoveTutor_EventScript_HeadbuttDeclined::
# 242 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttDeclined, MSGBOX_DEFAULT
# 243 "data/maps/IlexForest/scripts.pory"
	release
# 244 "data/maps/IlexForest/scripts.pory"
	end
# 245 "data/maps/IlexForest/scripts.pory"

# 246 "data/maps/IlexForest/scripts.pory"
MoveTutor_EventScript_HeadbuttTaught::
# 247 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_GET_HEADBUTT
# 248 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttTaught, MSGBOX_DEFAULT
# 249 "data/maps/IlexForest/scripts.pory"
	release
# 250 "data/maps/IlexForest/scripts.pory"
	end
# 251 "data/maps/IlexForest/scripts.pory"

# 252 "data/maps/IlexForest/scripts.pory"

# 253 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine::
# 254 "data/maps/IlexForest/scripts.pory"
	lock
# 255 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, IlexForest_EventScript_Celebi_Event
# 256 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
# 257 "data/maps/IlexForest/scripts.pory"
	closemessage
# 258 "data/maps/IlexForest/scripts.pory"
	release
# 259 "data/maps/IlexForest/scripts.pory"
	end
# 260 "data/maps/IlexForest/scripts.pory"

# 261 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Celebi_Event::
# 262 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ShrineCelebiEvent, MSGBOX_YESNO
# 263 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IlexForest_EventScript_Shrine_Cancel
# 264 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_InsertGSBall, MSGBOX_DEFAULT
# 265 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_CELEBI
# 266 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_CELEBI
# 267 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 268 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi1
# 269 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 270 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 271 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi2
# 272 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 273 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 274 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 275 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi3
# 276 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 277 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 278 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 279 "data/maps/IlexForest/scripts.pory"
	delay 40
# 280 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 281 "data/maps/IlexForest/scripts.pory"
	seteventmon SPECIES_CELEBI, 40
# 282 "data/maps/IlexForest/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 283 "data/maps/IlexForest/scripts.pory"
waitstate
# 284 "data/maps/IlexForest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 285 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IlexForest_EventScript_Shrine_Caught
# 286 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 287 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_CELEBI
# 288 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_CELEBI
# 289 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 290 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Kurt::
# 291 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_KURT
# 292 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_KURT
# 293 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt1
# 294 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 295 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 296 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_KurtCaughtCelebi, MSGBOX_DEFAULT
# 297 "data/maps/IlexForest/scripts.pory"
	closemessage
# 298 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt2
# 299 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 300 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_KURT
# 301 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_KURT
# 302 "data/maps/IlexForest/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 10
# 303 "data/maps/IlexForest/scripts.pory"
	release
# 304 "data/maps/IlexForest/scripts.pory"
	end
# 305 "data/maps/IlexForest/scripts.pory"

# 306 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine_Caught::
# 307 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_CAUGHT_CELEBI
# 308 "data/maps/IlexForest/scripts.pory"
	return
# 309 "data/maps/IlexForest/scripts.pory"

# 310 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine_Cancel::
# 311 "data/maps/IlexForest/scripts.pory"
	closemessage
# 312 "data/maps/IlexForest/scripts.pory"
	release
# 313 "data/maps/IlexForest/scripts.pory"
	end
# 314 "data/maps/IlexForest/scripts.pory"

# 315 "data/maps/IlexForest/scripts.pory"

# 316 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_SecondCelebi::
# 317 "data/maps/IlexForest/scripts.pory"
	lock
# 318 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 319 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 320 "data/maps/IlexForest/scripts.pory"
	delay 40
# 321 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 322 "data/maps/IlexForest/scripts.pory"
	seteventmon SPECIES_CELEBI, 40
# 323 "data/maps/IlexForest/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 324 "data/maps/IlexForest/scripts.pory"
waitstate
# 325 "data/maps/IlexForest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 326 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_SecondCelebiRan
# 327 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 328 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_SECOND_CELEBI
# 329 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
# 330 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 331 "data/maps/IlexForest/scripts.pory"
	release
# 332 "data/maps/IlexForest/scripts.pory"
	end
# 333 "data/maps/IlexForest/scripts.pory"

# 334 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_SecondCelebiRan::
# 335 "data/maps/IlexForest/scripts.pory"
	release
# 336 "data/maps/IlexForest/scripts.pory"
	end
# 337 "data/maps/IlexForest/scripts.pory"

# 338 "data/maps/IlexForest/scripts.pory"

# 339 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Sign::
# 340 "data/maps/IlexForest/scripts.pory"
	lock
# 341 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Signpost MSGBOX_SIGN
# 342 "data/maps/IlexForest/scripts.pory"
	closemessage
# 343 "data/maps/IlexForest/scripts.pory"
	release
# 344 "data/maps/IlexForest/scripts.pory"
	end
# 345 "data/maps/IlexForest/scripts.pory"

# 346 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Kimono::
# 347 "data/maps/IlexForest/scripts.pory"
	lock
# 348 "data/maps/IlexForest/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 349 "data/maps/IlexForest/scripts.pory"
	playse SE_PIN
# 350 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
# 351 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, Common_Movement_ExclamationMark
# 352 "data/maps/IlexForest/scripts.pory"
	delay 60
# 353 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl1
# 354 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 355 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl1, MSGBOX_DEFAULT
# 356 "data/maps/IlexForest/scripts.pory"
	closemessage
# 357 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 358 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl_Spin
# 359 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 360 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
# 361 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl2, MSGBOX_YESNO
# 362 "data/maps/IlexForest/scripts.pory"
	closemessage
# 363 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl3, MSGBOX_DEFAULT
# 364 "data/maps/IlexForest/scripts.pory"
	closemessage
# 365 "data/maps/IlexForest/scripts.pory"
    clearflag FLAG_TEMP_HIDE_FOLLOWER
# 366 "data/maps/IlexForest/scripts.pory"
    applymovement OBJ_EVENT_ID_FOLLOWER, showilexfollower
# 367 "data/maps/IlexForest/scripts.pory"
    waitmovement 0
# 368 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 369 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower1
# 370 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 371 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 372 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO DIR_WEST
# 373 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl4, MSGBOX_DEFAULT
# 374 "data/maps/IlexForest/scripts.pory"
	closemessage 
# 375 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO DIR_SOUTH
# 376 "data/maps/IlexForest/scripts.pory"
	delay 16
# 377 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl5, MSGBOX_DEFAULT
# 378 "data/maps/IlexForest/scripts.pory"
	closemessage
# 379 "data/maps/IlexForest/scripts.pory"
	delay 16
# 380 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 381 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower2
# 382 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl2
# 383 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 384 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 385 "data/maps/IlexForest/scripts.pory"
	fadedefaultbgm
# 386 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 4
# 387 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_KIMONO
# 388 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_KIMONO
# 389 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 390 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower3
# 391 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 392 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 393 "data/maps/IlexForest/scripts.pory"
	release
# 394 "data/maps/IlexForest/scripts.pory"
	end
# 395 "data/maps/IlexForest/scripts.pory"

# 396 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl1:
# 397 "data/maps/IlexForest/scripts.pory"
	walk_right
# 398 "data/maps/IlexForest/scripts.pory"
	face_down
# 399 "data/maps/IlexForest/scripts.pory"
	step_end
# 400 "data/maps/IlexForest/scripts.pory"

# 401 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl_Spin:
# 402 "data/maps/IlexForest/scripts.pory"
	face_left
# 403 "data/maps/IlexForest/scripts.pory"
	delay_8
# 404 "data/maps/IlexForest/scripts.pory"
	face_up
# 405 "data/maps/IlexForest/scripts.pory"
	delay_8
# 406 "data/maps/IlexForest/scripts.pory"
	face_right
# 407 "data/maps/IlexForest/scripts.pory"
	delay_8
# 408 "data/maps/IlexForest/scripts.pory"
	face_down
# 409 "data/maps/IlexForest/scripts.pory"
	delay_8
# 410 "data/maps/IlexForest/scripts.pory"
	face_left
# 411 "data/maps/IlexForest/scripts.pory"
	delay_8
# 412 "data/maps/IlexForest/scripts.pory"
	face_up
# 413 "data/maps/IlexForest/scripts.pory"
	delay_8
# 414 "data/maps/IlexForest/scripts.pory"
	face_right
# 415 "data/maps/IlexForest/scripts.pory"
	delay_8
# 416 "data/maps/IlexForest/scripts.pory"
	face_down
# 417 "data/maps/IlexForest/scripts.pory"
	step_end
# 418 "data/maps/IlexForest/scripts.pory"

# 419 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower1:
# 420 "data/maps/IlexForest/scripts.pory"
	walk_left
# 421 "data/maps/IlexForest/scripts.pory"
	jump_2_up
# 422 "data/maps/IlexForest/scripts.pory"
	walk_up
# 423 "data/maps/IlexForest/scripts.pory"
	face_right
# 424 "data/maps/IlexForest/scripts.pory"
	jump_in_place_right
# 425 "data/maps/IlexForest/scripts.pory"
	delay 16
# 426 "data/maps/IlexForest/scripts.pory"
	face_left
# 427 "data/maps/IlexForest/scripts.pory"
	jump_in_place_left
# 428 "data/maps/IlexForest/scripts.pory"
	delay 16
# 429 "data/maps/IlexForest/scripts.pory"
	face_right
# 430 "data/maps/IlexForest/scripts.pory"
	step_end
# 431 "data/maps/IlexForest/scripts.pory"

# 432 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower2:
# 433 "data/maps/IlexForest/scripts.pory"
	face_left
# 434 "data/maps/IlexForest/scripts.pory"
	walk_left
# 435 "data/maps/IlexForest/scripts.pory"
	walk_left
# 436 "data/maps/IlexForest/scripts.pory"
	walk_left
# 437 "data/maps/IlexForest/scripts.pory"
	walk_left
# 438 "data/maps/IlexForest/scripts.pory"
	walk_left
# 439 "data/maps/IlexForest/scripts.pory"
	walk_left
# 440 "data/maps/IlexForest/scripts.pory"
	walk_left
# 441 "data/maps/IlexForest/scripts.pory"
	walk_left
# 442 "data/maps/IlexForest/scripts.pory"
	step_end
# 443 "data/maps/IlexForest/scripts.pory"

# 444 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl2:
# 445 "data/maps/IlexForest/scripts.pory"
	face_left
# 446 "data/maps/IlexForest/scripts.pory"
	delay_16
# 447 "data/maps/IlexForest/scripts.pory"
	walk_left
# 448 "data/maps/IlexForest/scripts.pory"
	walk_left
# 449 "data/maps/IlexForest/scripts.pory"
	walk_left
# 450 "data/maps/IlexForest/scripts.pory"
	walk_left
# 451 "data/maps/IlexForest/scripts.pory"
	walk_left
# 452 "data/maps/IlexForest/scripts.pory"
	walk_left
# 453 "data/maps/IlexForest/scripts.pory"
	walk_left
# 454 "data/maps/IlexForest/scripts.pory"
	walk_left
# 455 "data/maps/IlexForest/scripts.pory"
	walk_left
# 456 "data/maps/IlexForest/scripts.pory"
	walk_left
# 457 "data/maps/IlexForest/scripts.pory"
	step_end
# 458 "data/maps/IlexForest/scripts.pory"

# 459 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower3:
# 460 "data/maps/IlexForest/scripts.pory"
	delay 16
# 461 "data/maps/IlexForest/scripts.pory"
	walk_right
# 462 "data/maps/IlexForest/scripts.pory"
	walk_right
# 463 "data/maps/IlexForest/scripts.pory"
	walk_right
# 464 "data/maps/IlexForest/scripts.pory"
	walk_right
# 465 "data/maps/IlexForest/scripts.pory"
	walk_right
# 466 "data/maps/IlexForest/scripts.pory"
	walk_right
# 467 "data/maps/IlexForest/scripts.pory"
	walk_right
# 468 "data/maps/IlexForest/scripts.pory"
	walk_right
# 469 "data/maps/IlexForest/scripts.pory"
	walk_down
# 470 "data/maps/IlexForest/scripts.pory"
	jump_2_down
# 471 "data/maps/IlexForest/scripts.pory"
	walk_right
# 472 "data/maps/IlexForest/scripts.pory"
	face_up
# 473 "data/maps/IlexForest/scripts.pory"
	step_end
# 474 "data/maps/IlexForest/scripts.pory"

# 475 "data/maps/IlexForest/scripts.pory"

# 476 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_1A:
# 477 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 478 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 479 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 480 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 481 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 482 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 483 "data/maps/IlexForest/scripts.pory"
	step_end
# 484 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_1B:
# 485 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 486 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 487 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 488 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 489 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 490 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 491 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 492 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 493 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 494 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 495 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 496 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 497 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 498 "data/maps/IlexForest/scripts.pory"
	step_end
# 499 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_2A:
# 500 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 501 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 502 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 503 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 504 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 505 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 506 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 507 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 508 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 509 "data/maps/IlexForest/scripts.pory"
	step_end
# 510 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_2B:
# 511 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 512 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 513 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 514 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 515 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 516 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 517 "data/maps/IlexForest/scripts.pory"
	step_end
# 518 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_3A:
# 519 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 520 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 521 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 522 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 523 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 524 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 525 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 526 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 527 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 528 "data/maps/IlexForest/scripts.pory"
	step_end
# 529 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_3B:
# 530 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 531 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 533 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 534 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 535 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 536 "data/maps/IlexForest/scripts.pory"
	step_end
# 537 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_4A:
# 538 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 539 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 540 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 541 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 542 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 543 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 544 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 545 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 546 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 547 "data/maps/IlexForest/scripts.pory"
	step_end
# 548 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_4B:
# 549 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 550 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 551 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 552 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 553 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 554 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 555 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 556 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 557 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 558 "data/maps/IlexForest/scripts.pory"
	step_end
# 559 "data/maps/IlexForest/scripts.pory"

# 560 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_Leave:
# 561 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 562 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 563 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 564 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 565 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 566 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 567 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 568 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 569 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 570 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 571 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 572 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 573 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 574 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 575 "data/maps/IlexForest/scripts.pory"
	face_down
# 576 "data/maps/IlexForest/scripts.pory"
	step_end
# 577 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_Return:
# 578 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 579 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 580 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 581 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 582 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 583 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 584 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 585 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 586 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 587 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 588 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 589 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 590 "data/maps/IlexForest/scripts.pory"
	walk_fast_up	
# 591 "data/maps/IlexForest/scripts.pory"
	step_end
# 592 "data/maps/IlexForest/scripts.pory"

# 593 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi1:
# 594 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 595 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 596 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 597 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 598 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 599 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 600 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 601 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 602 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 603 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 604 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 605 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 606 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 607 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 608 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 609 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 610 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 611 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 612 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 613 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 614 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 615 "data/maps/IlexForest/scripts.pory"
	step_end
# 616 "data/maps/IlexForest/scripts.pory"

# 617 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi2:
# 618 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 619 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 620 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 621 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 622 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 623 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 624 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 625 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 626 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 627 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 628 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 629 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 630 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 631 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 632 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 633 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 634 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 635 "data/maps/IlexForest/scripts.pory"
	step_end
# 636 "data/maps/IlexForest/scripts.pory"

# 637 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi3:
# 638 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 639 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 640 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 641 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 642 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 643 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 644 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 645 "data/maps/IlexForest/scripts.pory"
	step_end
# 646 "data/maps/IlexForest/scripts.pory"

# 647 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kurt1:
# 648 "data/maps/IlexForest/scripts.pory"
	walk_right
# 649 "data/maps/IlexForest/scripts.pory"
	walk_right
# 650 "data/maps/IlexForest/scripts.pory"
	walk_right
# 651 "data/maps/IlexForest/scripts.pory"
	walk_up
# 652 "data/maps/IlexForest/scripts.pory"
	walk_up
# 653 "data/maps/IlexForest/scripts.pory"
	walk_up
# 654 "data/maps/IlexForest/scripts.pory"
	walk_up
# 655 "data/maps/IlexForest/scripts.pory"
	walk_up
# 656 "data/maps/IlexForest/scripts.pory"
	step_end
# 657 "data/maps/IlexForest/scripts.pory"

# 658 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kurt2:
# 659 "data/maps/IlexForest/scripts.pory"
	walk_down
# 660 "data/maps/IlexForest/scripts.pory"
	walk_down
# 661 "data/maps/IlexForest/scripts.pory"
	walk_down
# 662 "data/maps/IlexForest/scripts.pory"
	walk_down
# 663 "data/maps/IlexForest/scripts.pory"
	walk_down
# 664 "data/maps/IlexForest/scripts.pory"
	walk_left
# 665 "data/maps/IlexForest/scripts.pory"
	walk_left
# 666 "data/maps/IlexForest/scripts.pory"
	walk_left
# 667 "data/maps/IlexForest/scripts.pory"
	step_end
# 668 "data/maps/IlexForest/scripts.pory"

# 669 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ApprenticeIntro:
# 670 "data/maps/IlexForest/scripts.pory"
	.string "Oh, man… My boss is going to be\n"
# 671 "data/maps/IlexForest/scripts.pory"
	.string "steaming…\p"
# 672 "data/maps/IlexForest/scripts.pory"
	.string "The Farfetch'D that Cuts trees\n"
# 673 "data/maps/IlexForest/scripts.pory"
	.string "for charcoal took off on me.\p"
# 674 "data/maps/IlexForest/scripts.pory"
	.string "I can't go looking for it here\n"
# 675 "data/maps/IlexForest/scripts.pory"
	.string "in the Ilex Forest.\p"
# 676 "data/maps/IlexForest/scripts.pory"
	.string "It's too big, dark and scary\n"
# 677 "data/maps/IlexForest/scripts.pory"
	.string "for me…$"
# 678 "data/maps/IlexForest/scripts.pory"

# 679 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ApprenticeAfter:
# 680 "data/maps/IlexForest/scripts.pory"
	.string "Wow! Thanks a whole bunch!\p"
# 681 "data/maps/IlexForest/scripts.pory"
	.string "My boss's Pokémon won't obey me\n"
# 682 "data/maps/IlexForest/scripts.pory"
	.string "because I don't have a Badge.$"
# 683 "data/maps/IlexForest/scripts.pory"

# 684 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ItsTheMissingPokemon:
# 685 "data/maps/IlexForest/scripts.pory"
	.string "It's the missing Pokémon!$"
# 686 "data/maps/IlexForest/scripts.pory"

# 687 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kwaaaa:
# 688 "data/maps/IlexForest/scripts.pory"
	.string "Farfetch'D: Kwaa!$"
# 689 "data/maps/IlexForest/scripts.pory"

# 690 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterIntro:
# 691 "data/maps/IlexForest/scripts.pory"
	.string "Ah! My Farfetch'D!\p"
# 692 "data/maps/IlexForest/scripts.pory"
	.string "You found it for us, kid?\p"
# 693 "data/maps/IlexForest/scripts.pory"
	.string "Without it, we wouldn't be able\n"
# 694 "data/maps/IlexForest/scripts.pory"
	.string "to Cut trees for charcoal.\p"
# 695 "data/maps/IlexForest/scripts.pory"
	.string "Thanks, kid!\p"
# 696 "data/maps/IlexForest/scripts.pory"
	.string "Now, how can I thank you…\p"
# 697 "data/maps/IlexForest/scripts.pory"
	.string "I know! Here, take this.$"
# 698 "data/maps/IlexForest/scripts.pory"

# 699 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterOutro:
# 700 "data/maps/IlexForest/scripts.pory"
	.string "That's the Cut HM.\n"
# 701 "data/maps/IlexForest/scripts.pory"
	.string "Teach that to a Pokémon to clear\l"
# 702 "data/maps/IlexForest/scripts.pory"
	.string "small trees.\p"
# 703 "data/maps/IlexForest/scripts.pory"
	.string "Of course, you have to have the\n"
# 704 "data/maps/IlexForest/scripts.pory"
	.string "Gym Badge from Azalea to use it.$"
# 705 "data/maps/IlexForest/scripts.pory"

# 706 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterTalkAfter:
# 707 "data/maps/IlexForest/scripts.pory"
	.string "Do you want to apprentice as a\n"
# 708 "data/maps/IlexForest/scripts.pory"
	.string "charcoal maker with me?\p"
# 709 "data/maps/IlexForest/scripts.pory"
	.string "You'll be first-rate in ten years!$"
# 710 "data/maps/IlexForest/scripts.pory"

# 711 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttTeach:
# 712 "data/maps/IlexForest/scripts.pory"
	.string "What am I doing?\p"
# 713 "data/maps/IlexForest/scripts.pory"
	.string "I'm shaking trees using Headbutt.\p"
# 714 "data/maps/IlexForest/scripts.pory"
	.string "Do you think your Pokémon will\n"
# 715 "data/maps/IlexForest/scripts.pory"
	.string "want to Headbutt, too?\p"
# 716 "data/maps/IlexForest/scripts.pory"
	.string "I can teach one the move Headbutt\n"
# 717 "data/maps/IlexForest/scripts.pory"
	.string "if you'd like. It's fun!$"
# 718 "data/maps/IlexForest/scripts.pory"
	
# 719 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttWhichMon:
# 720 "data/maps/IlexForest/scripts.pory"
	.string "Ehehe, sure thing! It'd be great if\n"
# 721 "data/maps/IlexForest/scripts.pory"
	.string "the Pokémon looked like me.$"
# 722 "data/maps/IlexForest/scripts.pory"

# 723 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttDeclined:
# 724 "data/maps/IlexForest/scripts.pory"
	.string "You don't need to be shy about it.\n"
# 725 "data/maps/IlexForest/scripts.pory"
	.string "Let's butt heads!$"
# 726 "data/maps/IlexForest/scripts.pory"

# 727 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttTaught:
# 728 "data/maps/IlexForest/scripts.pory"
	.string "Rattle trees with Headbutt.\n"
# 729 "data/maps/IlexForest/scripts.pory"
	.string "Sometimes, sleeping Pokémon fall out.$"
# 730 "data/maps/IlexForest/scripts.pory"

# 731 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Lass:
# 732 "data/maps/IlexForest/scripts.pory"
	.string "Did something happen to the\n"
# 733 "data/maps/IlexForest/scripts.pory"
	.string "forest's guardian?$"
# 734 "data/maps/IlexForest/scripts.pory"

# 735 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Signpost:
# 736 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest is so overgrown with\n"
# 737 "data/maps/IlexForest/scripts.pory"
	.string "trees that you can't see the sky.\p"
# 738 "data/maps/IlexForest/scripts.pory"
	.string "Please watch out for items that may\n"
# 739 "data/maps/IlexForest/scripts.pory"
	.string "have been dropped.$"
# 740 "data/maps/IlexForest/scripts.pory"

# 741 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Shrine:
# 742 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest Shrine…\p"
# 743 "data/maps/IlexForest/scripts.pory"
	.string "It's in honor of the forest's\n"
# 744 "data/maps/IlexForest/scripts.pory"
	.string "protector…$"
# 745 "data/maps/IlexForest/scripts.pory"

# 746 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ShrineCelebiEvent:
# 747 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest Shrine…\p"
# 748 "data/maps/IlexForest/scripts.pory"
	.string "It's in honor of the forest's\n"
# 749 "data/maps/IlexForest/scripts.pory"
	.string "protector…\p"
# 750 "data/maps/IlexForest/scripts.pory"
	.string "Oh? What is this?\p"
# 751 "data/maps/IlexForest/scripts.pory"
	.string "It's a hole.\n"
# 752 "data/maps/IlexForest/scripts.pory"
	.string "It looks like the Gs Ball would fit\l"
# 753 "data/maps/IlexForest/scripts.pory"
	.string "inside it.\p"
# 754 "data/maps/IlexForest/scripts.pory"
	.string "Want to put the Gs Ball here?$"
# 755 "data/maps/IlexForest/scripts.pory"

# 756 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_InsertGSBall:
# 757 "data/maps/IlexForest/scripts.pory"
	.string "{PLAYER} put in the Gs Ball.$"
# 758 "data/maps/IlexForest/scripts.pory"

# 759 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_KurtCaughtCelebi:
# 760 "data/maps/IlexForest/scripts.pory"
	.string "Whew, wasn't that something!\p"
# 761 "data/maps/IlexForest/scripts.pory"
	.string "{PLAYER}, that was fantastic. Thanks!\p"
# 762 "data/maps/IlexForest/scripts.pory"
	.string "The legends about that Shrine were\n"
# 763 "data/maps/IlexForest/scripts.pory"
	.string "real after all.\p"
# 764 "data/maps/IlexForest/scripts.pory"
	.string "I feel inspired by what I just saw.\p"
# 765 "data/maps/IlexForest/scripts.pory"
	.string "It motivates me to make better Balls!\p"
# 766 "data/maps/IlexForest/scripts.pory"
	.string "I'm going!$"
# 767 "data/maps/IlexForest/scripts.pory"

# 768 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneSeen:
# 769 "data/maps/IlexForest/scripts.pory"
	.string "Don't sneak up on me like that!\p"
# 770 "data/maps/IlexForest/scripts.pory"
	.string "You frightened a Pokémon away!$"
# 771 "data/maps/IlexForest/scripts.pory"

# 772 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneBeaten:
# 773 "data/maps/IlexForest/scripts.pory"
	.string "I hadn't seen that Pokémon before…$"
# 774 "data/maps/IlexForest/scripts.pory"

# 775 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneAfter:
# 776 "data/maps/IlexForest/scripts.pory"
	.string "A Pokémon I've never seen before\n"
# 777 "data/maps/IlexForest/scripts.pory"
	.string "fell out of the tree when I used\l"
# 778 "data/maps/IlexForest/scripts.pory"
	.string "Headbutt.\p"
# 779 "data/maps/IlexForest/scripts.pory"
	.string "I ought to use Headbutt in other\n"
# 780 "data/maps/IlexForest/scripts.pory"
	.string "places too.$"
# 781 "data/maps/IlexForest/scripts.pory"

# 782 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl1:
# 783 "data/maps/IlexForest/scripts.pory"
	.string "Kimono Girl, Kimono Girl, lost and\n"
# 784 "data/maps/IlexForest/scripts.pory"
	.string "all alone. Poor girl lost in the\l"
# 785 "data/maps/IlexForest/scripts.pory"
	.string "dark Ilex Forest.$"
# 786 "data/maps/IlexForest/scripts.pory"

# 787 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl2:
# 788 "data/maps/IlexForest/scripts.pory"
	.string "You remember me from Violet City?\n"
# 789 "data/maps/IlexForest/scripts.pory"
	.string "You must be imagining.\p"
# 790 "data/maps/IlexForest/scripts.pory"
	.string "Anyway, will you show me how to\n"
# 791 "data/maps/IlexForest/scripts.pory"
	.string "get out of this forest?$"
# 792 "data/maps/IlexForest/scripts.pory"

# 793 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl3:
# 794 "data/maps/IlexForest/scripts.pory"
	.string "Me oh my... You are lost yourself,\n"
# 795 "data/maps/IlexForest/scripts.pory"
	.string "aren't you?$"
# 796 "data/maps/IlexForest/scripts.pory"

# 797 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl4:
# 798 "data/maps/IlexForest/scripts.pory"
	.string "Wow! Are you going to show me how\n"
# 799 "data/maps/IlexForest/scripts.pory"
	.string "to get out?\p"
# 800 "data/maps/IlexForest/scripts.pory"
	.string "You are such a smart Pokémon!$"
# 801 "data/maps/IlexForest/scripts.pory"

# 802 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl5:
# 803 "data/maps/IlexForest/scripts.pory"
	.string "See you.$"

# 806 "data/maps/IlexForest/scripts.pory"
showilexfollower:
# 807 "data/maps/IlexForest/scripts.pory"
	set_visible
# 808 "data/maps/IlexForest/scripts.pory"
	step_end

Ilex_HiddenGrotto::
# 812 "data/maps/IlexForest/scripts.pory"
	msgbox Ilex_HiddenGrotto_Text_0, MSGBOX_YESNO
# 814 "data/maps/IlexForest/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ilex_HiddenGrotto_2
Ilex_HiddenGrotto_1:
# 818 "data/maps/IlexForest/scripts.pory"
	release
	end

Ilex_HiddenGrotto_2:
# 815 "data/maps/IlexForest/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ILEX, 0
# 816 "data/maps/IlexForest/scripts.pory"
	waitstate
	goto Ilex_HiddenGrotto_1


Ilex_HiddenGrotto_Text_0:
# 812 "data/maps/IlexForest/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
