# 1 "data/maps/IlexForest/scripts.pory"

# 2 "data/maps/IlexForest/scripts.pory"

# 3 "data/maps/IlexForest/scripts.pory"
IlexForest_MapScripts::
# 4 "data/maps/IlexForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
# 5 "data/maps/IlexForest/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/IlexForest/scripts.pory"
	.byte 0
# 7 "data/maps/IlexForest/scripts.pory"

# 8 "data/maps/IlexForest/scripts.pory"
IlexForest_OnTransition: 
# 9 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_ReenterWhenFarfetchdLeaving
# 10 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_ReenterDuringCutScene
# 11 "data/maps/IlexForest/scripts.pory"
	callnative SetTimeBasedEncounters
# 12 "data/maps/IlexForest/scripts.pory"
	end	
# 13 "data/maps/IlexForest/scripts.pory"

# 14 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_ReenterWhenFarfetchdLeaving::
# 15 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
# 16 "data/maps/IlexForest/scripts.pory"
	return
# 17 "data/maps/IlexForest/scripts.pory"

# 18 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_ReenterDuringCutScene::
# 19 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
# 20 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 21 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
# 22 "data/maps/IlexForest/scripts.pory"
	return
# 23 "data/maps/IlexForest/scripts.pory"

# 24 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Apprentice::
# 25 "data/maps/IlexForest/scripts.pory"
	lock
# 26 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 27 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Apprentice2
# 28 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Apprentice2
# 29 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ApprenticeIntro, MSGBOX_DEFAULT
# 30 "data/maps/IlexForest/scripts.pory"
	closemessage
# 31 "data/maps/IlexForest/scripts.pory"
	release
# 32 "data/maps/IlexForest/scripts.pory"
	end
# 33 "data/maps/IlexForest/scripts.pory"

# 34 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Apprentice2::
# 35 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ApprenticeAfter, MSGBOX_DEFAULT
# 36 "data/maps/IlexForest/scripts.pory"
	closemessage
# 37 "data/maps/IlexForest/scripts.pory"
	release
# 38 "data/maps/IlexForest/scripts.pory"
	end
# 39 "data/maps/IlexForest/scripts.pory"

# 40 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Boss::
# 41 "data/maps/IlexForest/scripts.pory"
	lock
# 42 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 43 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterTalkAfter, MSGBOX_DEFAULT
# 44 "data/maps/IlexForest/scripts.pory"
	closemessage
# 45 "data/maps/IlexForest/scripts.pory"
	release
# 46 "data/maps/IlexForest/scripts.pory"
	end
# 47 "data/maps/IlexForest/scripts.pory"

# 48 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_1A::
# 49 "data/maps/IlexForest/scripts.pory"
	lock
# 50 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 51 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 52 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 53 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 54 "data/maps/IlexForest/scripts.pory"
	closemessage
# 55 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Farfetchd_Done
# 56 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Farfetchd_Done
# 57 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_Farfetchd_Leave
# 58 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_1B
# 59 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1A
# 60 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 61 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 62 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 63 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 64 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 65 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 66 "data/maps/IlexForest/scripts.pory"
	release
# 67 "data/maps/IlexForest/scripts.pory"
	end
# 68 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_1B::
# 69 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1B
# 70 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 71 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 1
# 72 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
# 73 "data/maps/IlexForest/scripts.pory"
	release
# 74 "data/maps/IlexForest/scripts.pory"
	end
# 75 "data/maps/IlexForest/scripts.pory"

# 76 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_2A::
# 77 "data/maps/IlexForest/scripts.pory"
	lock
# 78 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 79 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 80 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 81 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 82 "data/maps/IlexForest/scripts.pory"
	closemessage
# 83 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_2B
# 84 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2A
# 85 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 86 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 87 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 88 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 89 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 90 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 91 "data/maps/IlexForest/scripts.pory"
	release
# 92 "data/maps/IlexForest/scripts.pory"
	end
# 93 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_2B::
# 94 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2B
# 95 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 96 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 97 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 98 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 99 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 100 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 101 "data/maps/IlexForest/scripts.pory"
	release
# 102 "data/maps/IlexForest/scripts.pory"
	end
# 103 "data/maps/IlexForest/scripts.pory"

# 104 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_3A::
# 105 "data/maps/IlexForest/scripts.pory"
	lock
# 106 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 107 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 108 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 109 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 110 "data/maps/IlexForest/scripts.pory"
	closemessage
# 111 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_3B
# 112 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3A
# 113 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 114 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 115 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 116 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 117 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
# 118 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
# 119 "data/maps/IlexForest/scripts.pory"
	release
# 120 "data/maps/IlexForest/scripts.pory"
	end
# 121 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_3B::
# 122 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3B
# 123 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 124 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 125 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 126 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 127 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 128 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 129 "data/maps/IlexForest/scripts.pory"
	release
# 130 "data/maps/IlexForest/scripts.pory"
	end
# 131 "data/maps/IlexForest/scripts.pory"

# 132 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_4A::
# 133 "data/maps/IlexForest/scripts.pory"
	lock
# 134 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 135 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
# 136 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
# 137 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 138 "data/maps/IlexForest/scripts.pory"
	closemessage
# 139 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_4B
# 140 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4A
# 141 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 142 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 143 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 144 "data/maps/IlexForest/scripts.pory"
	@add clockwise farfetchd
# 145 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
# 146 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
# 147 "data/maps/IlexForest/scripts.pory"
	release
# 148 "data/maps/IlexForest/scripts.pory"
	end
# 149 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_4B::
# 150 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4B
# 151 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 152 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
# 153 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
# 154 "data/maps/IlexForest/scripts.pory"
	@add counterclockwise farfetchd
# 155 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 156 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
# 157 "data/maps/IlexForest/scripts.pory"
	release
# 158 "data/maps/IlexForest/scripts.pory"
	end
# 159 "data/maps/IlexForest/scripts.pory"

# 160 "data/maps/IlexForest/scripts.pory"

# 161 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Leave::
# 162 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, IlexForest_EventScript_Farfetchd_Return
# 163 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Leave
# 164 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 165 "data/maps/IlexForest/scripts.pory"
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
# 166 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 2
# 167 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
# 168 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
# 169 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
# 170 "data/maps/IlexForest/scripts.pory"
	addobject 1
# 171 "data/maps/IlexForest/scripts.pory"
	release
# 172 "data/maps/IlexForest/scripts.pory"
	end
# 173 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Return::
# 174 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 0
# 175 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Return
# 176 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 177 "data/maps/IlexForest/scripts.pory"
	release
# 178 "data/maps/IlexForest/scripts.pory"
	end
# 179 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Farfetchd_Done::
# 180 "data/maps/IlexForest/scripts.pory"
	release
# 181 "data/maps/IlexForest/scripts.pory"
	end
# 182 "data/maps/IlexForest/scripts.pory"

# 183 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_TriggerBot::
# 184 "data/maps/IlexForest/scripts.pory"
	lock
# 185 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkUp
# 186 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 187 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Trigger::
# 188 "data/maps/IlexForest/scripts.pory"
	lock
# 189 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 190 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterIntro, MSGBOX_DEFAULT
# 191 "data/maps/IlexForest/scripts.pory"
	closemessage
# 192 "data/maps/IlexForest/scripts.pory"
	giveitem ITEM_HM_CUT
# 193 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 194 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_CharcoalMasterOutro, MSGBOX_DEFAULT
# 195 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_RECEIVED_HM_CUT
# 196 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
# 197 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 198 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 199 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 3
# 200 "data/maps/IlexForest/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 7
# 201 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
# 202 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
# 203 "data/maps/IlexForest/scripts.pory"
	closemessage
# 204 "data/maps/IlexForest/scripts.pory"
	release
# 205 "data/maps/IlexForest/scripts.pory"
	end
# 206 "data/maps/IlexForest/scripts.pory"

# 207 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Picnicker::
# 208 "data/maps/IlexForest/scripts.pory"
	lock
# 209 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 210 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Lass, MSGBOX_DEFAULT
# 211 "data/maps/IlexForest/scripts.pory"
	closemessage
# 212 "data/maps/IlexForest/scripts.pory"
	release
# 213 "data/maps/IlexForest/scripts.pory"
	end
# 214 "data/maps/IlexForest/scripts.pory"

# 215 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_BugcatcherWayne::
# 216 "data/maps/IlexForest/scripts.pory"
	trainerbattle_single TRAINER_WAYNE IlexForest_Text_BugCatcherWayneSeen, IlexForest_Text_BugCatcherWayneBeaten
# 217 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_BugCatcherWayneAfter, MSGBOX_AUTOCLOSE
# 218 "data/maps/IlexForest/scripts.pory"
	end
# 219 "data/maps/IlexForest/scripts.pory"

# 220 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_HeadbuttMoveTutor::
# 221 "data/maps/IlexForest/scripts.pory"
	lock
# 222 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 223 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttTeach, MSGBOX_YESNO
# 224 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_HeadbuttDeclined
# 225 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttWhichMon, MSGBOX_DEFAULT
# 226 "data/maps/IlexForest/scripts.pory"
	setvar VAR_0x8005, MOVE_HEADBUTT
# 227 "data/maps/IlexForest/scripts.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 228 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_HeadbuttDeclined
# 229 "data/maps/IlexForest/scripts.pory"
	goto MoveTutor_EventScript_HeadbuttTaught
# 230 "data/maps/IlexForest/scripts.pory"
	end
# 231 "data/maps/IlexForest/scripts.pory"

# 232 "data/maps/IlexForest/scripts.pory"
MoveTutor_EventScript_HeadbuttDeclined::
# 233 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttDeclined, MSGBOX_DEFAULT
# 234 "data/maps/IlexForest/scripts.pory"
	release
# 235 "data/maps/IlexForest/scripts.pory"
	end
# 236 "data/maps/IlexForest/scripts.pory"

# 237 "data/maps/IlexForest/scripts.pory"
MoveTutor_EventScript_HeadbuttTaught::
# 238 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_GET_HEADBUTT
# 239 "data/maps/IlexForest/scripts.pory"
	msgbox MoveTutor_Text_HeadbuttTaught, MSGBOX_DEFAULT
# 240 "data/maps/IlexForest/scripts.pory"
	release
# 241 "data/maps/IlexForest/scripts.pory"
	end
# 242 "data/maps/IlexForest/scripts.pory"

# 243 "data/maps/IlexForest/scripts.pory"

# 244 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine::
# 245 "data/maps/IlexForest/scripts.pory"
	lock
# 246 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, IlexForest_EventScript_Celebi_Event
# 247 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
# 248 "data/maps/IlexForest/scripts.pory"
	closemessage
# 249 "data/maps/IlexForest/scripts.pory"
	release
# 250 "data/maps/IlexForest/scripts.pory"
	end
# 251 "data/maps/IlexForest/scripts.pory"

# 252 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Celebi_Event::
# 253 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_ShrineCelebiEvent, MSGBOX_YESNO
# 254 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IlexForest_EventScript_Shrine_Cancel
# 255 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_InsertGSBall, MSGBOX_DEFAULT
# 256 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_CELEBI
# 257 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_CELEBI
# 258 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 259 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi1
# 260 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 261 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 262 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi2
# 263 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 264 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 265 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 266 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi3
# 267 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 268 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 269 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 270 "data/maps/IlexForest/scripts.pory"
	delay 40
# 271 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 272 "data/maps/IlexForest/scripts.pory"
	seteventmon SPECIES_CELEBI, 40
# 273 "data/maps/IlexForest/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 274 "data/maps/IlexForest/scripts.pory"
waitstate
# 275 "data/maps/IlexForest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 276 "data/maps/IlexForest/scripts.pory"
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IlexForest_EventScript_Shrine_Caught
# 277 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 278 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_CELEBI
# 279 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_CELEBI
# 280 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 281 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Kurt::
# 282 "data/maps/IlexForest/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_KURT
# 283 "data/maps/IlexForest/scripts.pory"
	addobject LOCALID_ILEX_FOREST_KURT
# 284 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt1
# 285 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 286 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 287 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_KurtCaughtCelebi, MSGBOX_DEFAULT
# 288 "data/maps/IlexForest/scripts.pory"
	closemessage
# 289 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt2
# 290 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 291 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_KURT
# 292 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_KURT
# 293 "data/maps/IlexForest/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 10
# 294 "data/maps/IlexForest/scripts.pory"
	release
# 295 "data/maps/IlexForest/scripts.pory"
	end
# 296 "data/maps/IlexForest/scripts.pory"

# 297 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine_Caught::
# 298 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_CAUGHT_CELEBI
# 299 "data/maps/IlexForest/scripts.pory"
	return
# 300 "data/maps/IlexForest/scripts.pory"

# 301 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Shrine_Cancel::
# 302 "data/maps/IlexForest/scripts.pory"
	closemessage
# 303 "data/maps/IlexForest/scripts.pory"
	release
# 304 "data/maps/IlexForest/scripts.pory"
	end
# 305 "data/maps/IlexForest/scripts.pory"

# 306 "data/maps/IlexForest/scripts.pory"

# 307 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_SecondCelebi::
# 308 "data/maps/IlexForest/scripts.pory"
	lock
# 309 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 310 "data/maps/IlexForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 311 "data/maps/IlexForest/scripts.pory"
	delay 40
# 312 "data/maps/IlexForest/scripts.pory"
	waitmoncry
# 313 "data/maps/IlexForest/scripts.pory"
	seteventmon SPECIES_CELEBI, 40
# 314 "data/maps/IlexForest/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 315 "data/maps/IlexForest/scripts.pory"
waitstate
# 316 "data/maps/IlexForest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 317 "data/maps/IlexForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_SecondCelebiRan
# 318 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 319 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_SECOND_CELEBI
# 320 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
# 321 "data/maps/IlexForest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 322 "data/maps/IlexForest/scripts.pory"
	release
# 323 "data/maps/IlexForest/scripts.pory"
	end
# 324 "data/maps/IlexForest/scripts.pory"

# 325 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_SecondCelebiRan::
# 326 "data/maps/IlexForest/scripts.pory"
	release
# 327 "data/maps/IlexForest/scripts.pory"
	end
# 328 "data/maps/IlexForest/scripts.pory"

# 329 "data/maps/IlexForest/scripts.pory"

# 330 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Sign::
# 331 "data/maps/IlexForest/scripts.pory"
	lock
# 332 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Signpost MSGBOX_SIGN
# 333 "data/maps/IlexForest/scripts.pory"
	closemessage
# 334 "data/maps/IlexForest/scripts.pory"
	release
# 335 "data/maps/IlexForest/scripts.pory"
	end
# 336 "data/maps/IlexForest/scripts.pory"

# 337 "data/maps/IlexForest/scripts.pory"
IlexForest_EventScript_Kimono::
# 338 "data/maps/IlexForest/scripts.pory"
	lock
# 339 "data/maps/IlexForest/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 340 "data/maps/IlexForest/scripts.pory"
	playse SE_PIN
# 341 "data/maps/IlexForest/scripts.pory"
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
# 342 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, Common_Movement_ExclamationMark
# 343 "data/maps/IlexForest/scripts.pory"
	delay 60
# 344 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl1
# 345 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 346 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl1, MSGBOX_DEFAULT
# 347 "data/maps/IlexForest/scripts.pory"
	closemessage
# 348 "data/maps/IlexForest/scripts.pory"
	playse SE_M_PETAL_DANCE
# 349 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl_Spin
# 350 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 351 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
# 352 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl2, MSGBOX_YESNO
# 353 "data/maps/IlexForest/scripts.pory"
	closemessage
# 354 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl3, MSGBOX_DEFAULT
# 355 "data/maps/IlexForest/scripts.pory"
	closemessage
# 356 "data/maps/IlexForest/scripts.pory"
    clearflag FLAG_TEMP_HIDE_FOLLOWER
# 357 "data/maps/IlexForest/scripts.pory"
    applymovement OBJ_EVENT_ID_FOLLOWER, showilexfollower
# 358 "data/maps/IlexForest/scripts.pory"
    waitmovement 0
# 359 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 360 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower1
# 361 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 362 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 363 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO DIR_WEST
# 364 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl4, MSGBOX_DEFAULT
# 365 "data/maps/IlexForest/scripts.pory"
	closemessage 
# 366 "data/maps/IlexForest/scripts.pory"
	turnobject LOCALID_ILEX_FOREST_KIMONO DIR_SOUTH
# 367 "data/maps/IlexForest/scripts.pory"
	delay 16
# 368 "data/maps/IlexForest/scripts.pory"
	msgbox IlexForest_Text_Kimono_Girl5, MSGBOX_DEFAULT
# 369 "data/maps/IlexForest/scripts.pory"
	closemessage
# 370 "data/maps/IlexForest/scripts.pory"
	delay 16
# 371 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 372 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower2
# 373 "data/maps/IlexForest/scripts.pory"
	applymovement LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl2
# 374 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 375 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 376 "data/maps/IlexForest/scripts.pory"
	savebgm MUS_DUMMY
# 377 "data/maps/IlexForest/scripts.pory"
	fadedefaultbgm
# 378 "data/maps/IlexForest/scripts.pory"
	setvar VAR_ILEX_FOREST_FARFETCHD, 4
# 379 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_HIDE_ILEX_FOREST_KIMONO
# 380 "data/maps/IlexForest/scripts.pory"
	removeobject LOCALID_ILEX_FOREST_KIMONO
# 381 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 382 "data/maps/IlexForest/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower3
# 383 "data/maps/IlexForest/scripts.pory"
	waitmovement 0
# 384 "data/maps/IlexForest/scripts.pory"
	playfirstmoncry
# 385 "data/maps/IlexForest/scripts.pory"
	release
# 386 "data/maps/IlexForest/scripts.pory"
	end
# 387 "data/maps/IlexForest/scripts.pory"

# 388 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl1:
# 389 "data/maps/IlexForest/scripts.pory"
	walk_right
# 390 "data/maps/IlexForest/scripts.pory"
	face_down
# 391 "data/maps/IlexForest/scripts.pory"
	step_end
# 392 "data/maps/IlexForest/scripts.pory"

# 393 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl_Spin:
# 394 "data/maps/IlexForest/scripts.pory"
	face_left
# 395 "data/maps/IlexForest/scripts.pory"
	delay_8
# 396 "data/maps/IlexForest/scripts.pory"
	face_up
# 397 "data/maps/IlexForest/scripts.pory"
	delay_8
# 398 "data/maps/IlexForest/scripts.pory"
	face_right
# 399 "data/maps/IlexForest/scripts.pory"
	delay_8
# 400 "data/maps/IlexForest/scripts.pory"
	face_down
# 401 "data/maps/IlexForest/scripts.pory"
	delay_8
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
	step_end
# 410 "data/maps/IlexForest/scripts.pory"

# 411 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower1:
# 412 "data/maps/IlexForest/scripts.pory"
	walk_left
# 413 "data/maps/IlexForest/scripts.pory"
	jump_2_up
# 414 "data/maps/IlexForest/scripts.pory"
	walk_up
# 415 "data/maps/IlexForest/scripts.pory"
	face_right
# 416 "data/maps/IlexForest/scripts.pory"
	jump_in_place_right
# 417 "data/maps/IlexForest/scripts.pory"
	delay 16
# 418 "data/maps/IlexForest/scripts.pory"
	face_left
# 419 "data/maps/IlexForest/scripts.pory"
	jump_in_place_left
# 420 "data/maps/IlexForest/scripts.pory"
	delay 16
# 421 "data/maps/IlexForest/scripts.pory"
	face_right
# 422 "data/maps/IlexForest/scripts.pory"
	step_end
# 423 "data/maps/IlexForest/scripts.pory"

# 424 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower2:
# 425 "data/maps/IlexForest/scripts.pory"
	face_left
# 426 "data/maps/IlexForest/scripts.pory"
	walk_left
# 427 "data/maps/IlexForest/scripts.pory"
	walk_left
# 428 "data/maps/IlexForest/scripts.pory"
	walk_left
# 429 "data/maps/IlexForest/scripts.pory"
	walk_left
# 430 "data/maps/IlexForest/scripts.pory"
	walk_left
# 431 "data/maps/IlexForest/scripts.pory"
	walk_left
# 432 "data/maps/IlexForest/scripts.pory"
	walk_left
# 433 "data/maps/IlexForest/scripts.pory"
	walk_left
# 434 "data/maps/IlexForest/scripts.pory"
	step_end
# 435 "data/maps/IlexForest/scripts.pory"

# 436 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kimono_Girl2:
# 437 "data/maps/IlexForest/scripts.pory"
	face_left
# 438 "data/maps/IlexForest/scripts.pory"
	delay_16
# 439 "data/maps/IlexForest/scripts.pory"
	walk_left
# 440 "data/maps/IlexForest/scripts.pory"
	walk_left
# 441 "data/maps/IlexForest/scripts.pory"
	walk_left
# 442 "data/maps/IlexForest/scripts.pory"
	walk_left
# 443 "data/maps/IlexForest/scripts.pory"
	walk_left
# 444 "data/maps/IlexForest/scripts.pory"
	walk_left
# 445 "data/maps/IlexForest/scripts.pory"
	walk_left
# 446 "data/maps/IlexForest/scripts.pory"
	walk_left
# 447 "data/maps/IlexForest/scripts.pory"
	walk_left
# 448 "data/maps/IlexForest/scripts.pory"
	walk_left
# 449 "data/maps/IlexForest/scripts.pory"
	step_end
# 450 "data/maps/IlexForest/scripts.pory"

# 451 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Follower3:
# 452 "data/maps/IlexForest/scripts.pory"
	delay 16
# 453 "data/maps/IlexForest/scripts.pory"
	walk_right
# 454 "data/maps/IlexForest/scripts.pory"
	walk_right
# 455 "data/maps/IlexForest/scripts.pory"
	walk_right
# 456 "data/maps/IlexForest/scripts.pory"
	walk_right
# 457 "data/maps/IlexForest/scripts.pory"
	walk_right
# 458 "data/maps/IlexForest/scripts.pory"
	walk_right
# 459 "data/maps/IlexForest/scripts.pory"
	walk_right
# 460 "data/maps/IlexForest/scripts.pory"
	walk_right
# 461 "data/maps/IlexForest/scripts.pory"
	walk_down
# 462 "data/maps/IlexForest/scripts.pory"
	jump_2_down
# 463 "data/maps/IlexForest/scripts.pory"
	walk_right
# 464 "data/maps/IlexForest/scripts.pory"
	face_up
# 465 "data/maps/IlexForest/scripts.pory"
	step_end
# 466 "data/maps/IlexForest/scripts.pory"

# 467 "data/maps/IlexForest/scripts.pory"

# 468 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_1A:
# 469 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 470 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 471 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 472 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 473 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 474 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 475 "data/maps/IlexForest/scripts.pory"
	step_end
# 476 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_1B:
# 477 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 478 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 479 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 480 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 481 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 482 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 483 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 484 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 485 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 486 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 487 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 488 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 489 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 490 "data/maps/IlexForest/scripts.pory"
	step_end
# 491 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_2A:
# 492 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 493 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 494 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 495 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 496 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 497 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 498 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 499 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 500 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 501 "data/maps/IlexForest/scripts.pory"
	step_end
# 502 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_2B:
# 503 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 504 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 505 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 506 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 507 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 508 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 509 "data/maps/IlexForest/scripts.pory"
	step_end
# 510 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_3A:
# 511 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 512 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 513 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 514 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 515 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 516 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 517 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 518 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 519 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 520 "data/maps/IlexForest/scripts.pory"
	step_end
# 521 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_3B:
# 522 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 523 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 524 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 525 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 526 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 527 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 528 "data/maps/IlexForest/scripts.pory"
	step_end
# 529 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_4A:
# 530 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 531 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 532 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 533 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 534 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 535 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 536 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 537 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 538 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 539 "data/maps/IlexForest/scripts.pory"
	step_end
# 540 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_4B:
# 541 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 542 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 543 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 544 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 545 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 546 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 547 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 548 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 549 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 550 "data/maps/IlexForest/scripts.pory"
	step_end
# 551 "data/maps/IlexForest/scripts.pory"

# 552 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_Leave:
# 553 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 554 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 555 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 556 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 557 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 558 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 559 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 560 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 561 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 562 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 563 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 564 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 565 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 566 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 567 "data/maps/IlexForest/scripts.pory"
	face_down
# 568 "data/maps/IlexForest/scripts.pory"
	step_end
# 569 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Farfetchd_Return:
# 570 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 571 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 572 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 573 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 574 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 575 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 576 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 577 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 578 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 579 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 580 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 581 "data/maps/IlexForest/scripts.pory"
	walk_fast_up
# 582 "data/maps/IlexForest/scripts.pory"
	walk_fast_up	
# 583 "data/maps/IlexForest/scripts.pory"
	step_end
# 584 "data/maps/IlexForest/scripts.pory"

# 585 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi1:
# 586 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 587 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 588 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 589 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 590 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 591 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 592 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 593 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
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
	walk_fast_down
# 603 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 604 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 605 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 606 "data/maps/IlexForest/scripts.pory"
	walk_fast_down
# 607 "data/maps/IlexForest/scripts.pory"
	step_end
# 608 "data/maps/IlexForest/scripts.pory"

# 609 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi2:
# 610 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 611 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 612 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 613 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 614 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 615 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 616 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
# 617 "data/maps/IlexForest/scripts.pory"
	walk_fast_left
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
	walk_fast_up
# 627 "data/maps/IlexForest/scripts.pory"
	step_end
# 628 "data/maps/IlexForest/scripts.pory"

# 629 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Celebi3:
# 630 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 631 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 632 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 633 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 634 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 635 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 636 "data/maps/IlexForest/scripts.pory"
	walk_fast_right
# 637 "data/maps/IlexForest/scripts.pory"
	step_end
# 638 "data/maps/IlexForest/scripts.pory"

# 639 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kurt1:
# 640 "data/maps/IlexForest/scripts.pory"
	walk_right
# 641 "data/maps/IlexForest/scripts.pory"
	walk_right
# 642 "data/maps/IlexForest/scripts.pory"
	walk_right
# 643 "data/maps/IlexForest/scripts.pory"
	walk_up
# 644 "data/maps/IlexForest/scripts.pory"
	walk_up
# 645 "data/maps/IlexForest/scripts.pory"
	walk_up
# 646 "data/maps/IlexForest/scripts.pory"
	walk_up
# 647 "data/maps/IlexForest/scripts.pory"
	walk_up
# 648 "data/maps/IlexForest/scripts.pory"
	step_end
# 649 "data/maps/IlexForest/scripts.pory"

# 650 "data/maps/IlexForest/scripts.pory"
IlexForest_Movement_Kurt2:
# 651 "data/maps/IlexForest/scripts.pory"
	walk_down
# 652 "data/maps/IlexForest/scripts.pory"
	walk_down
# 653 "data/maps/IlexForest/scripts.pory"
	walk_down
# 654 "data/maps/IlexForest/scripts.pory"
	walk_down
# 655 "data/maps/IlexForest/scripts.pory"
	walk_down
# 656 "data/maps/IlexForest/scripts.pory"
	walk_left
# 657 "data/maps/IlexForest/scripts.pory"
	walk_left
# 658 "data/maps/IlexForest/scripts.pory"
	walk_left
# 659 "data/maps/IlexForest/scripts.pory"
	step_end
# 660 "data/maps/IlexForest/scripts.pory"

# 661 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ApprenticeIntro:
# 662 "data/maps/IlexForest/scripts.pory"
	.string "Oh, man… My boss is going to be\n"
# 663 "data/maps/IlexForest/scripts.pory"
	.string "steaming…\p"
# 664 "data/maps/IlexForest/scripts.pory"
	.string "The Farfetch'D that Cuts trees\n"
# 665 "data/maps/IlexForest/scripts.pory"
	.string "for charcoal took off on me.\p"
# 666 "data/maps/IlexForest/scripts.pory"
	.string "I can't go looking for it here\n"
# 667 "data/maps/IlexForest/scripts.pory"
	.string "in the Ilex Forest.\p"
# 668 "data/maps/IlexForest/scripts.pory"
	.string "It's too big, dark and scary\n"
# 669 "data/maps/IlexForest/scripts.pory"
	.string "for me…$"
# 670 "data/maps/IlexForest/scripts.pory"

# 671 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ApprenticeAfter:
# 672 "data/maps/IlexForest/scripts.pory"
	.string "Wow! Thanks a whole bunch!\p"
# 673 "data/maps/IlexForest/scripts.pory"
	.string "My boss's Pokémon won't obey me\n"
# 674 "data/maps/IlexForest/scripts.pory"
	.string "because I don't have a Badge.$"
# 675 "data/maps/IlexForest/scripts.pory"

# 676 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ItsTheMissingPokemon:
# 677 "data/maps/IlexForest/scripts.pory"
	.string "It's the missing Pokémon!$"
# 678 "data/maps/IlexForest/scripts.pory"

# 679 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kwaaaa:
# 680 "data/maps/IlexForest/scripts.pory"
	.string "Farfetch'D: Kwaa!$"
# 681 "data/maps/IlexForest/scripts.pory"

# 682 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterIntro:
# 683 "data/maps/IlexForest/scripts.pory"
	.string "Ah! My Farfetch'D!\p"
# 684 "data/maps/IlexForest/scripts.pory"
	.string "You found it for us, kid?\p"
# 685 "data/maps/IlexForest/scripts.pory"
	.string "Without it, we wouldn't be able\n"
# 686 "data/maps/IlexForest/scripts.pory"
	.string "to Cut trees for charcoal.\p"
# 687 "data/maps/IlexForest/scripts.pory"
	.string "Thanks, kid!\p"
# 688 "data/maps/IlexForest/scripts.pory"
	.string "Now, how can I thank you…\p"
# 689 "data/maps/IlexForest/scripts.pory"
	.string "I know! Here, take this.$"
# 690 "data/maps/IlexForest/scripts.pory"

# 691 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterOutro:
# 692 "data/maps/IlexForest/scripts.pory"
	.string "That's the Cut HM.\n"
# 693 "data/maps/IlexForest/scripts.pory"
	.string "Teach that to a Pokémon to clear\l"
# 694 "data/maps/IlexForest/scripts.pory"
	.string "small trees.\p"
# 695 "data/maps/IlexForest/scripts.pory"
	.string "Of course, you have to have the\n"
# 696 "data/maps/IlexForest/scripts.pory"
	.string "Gym Badge from Azalea to use it.$"
# 697 "data/maps/IlexForest/scripts.pory"

# 698 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_CharcoalMasterTalkAfter:
# 699 "data/maps/IlexForest/scripts.pory"
	.string "Do you want to apprentice as a\n"
# 700 "data/maps/IlexForest/scripts.pory"
	.string "charcoal maker with me?\p"
# 701 "data/maps/IlexForest/scripts.pory"
	.string "You'll be first-rate in ten years!$"
# 702 "data/maps/IlexForest/scripts.pory"

# 703 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttTeach:
# 704 "data/maps/IlexForest/scripts.pory"
	.string "What am I doing?\p"
# 705 "data/maps/IlexForest/scripts.pory"
	.string "I'm shaking trees using Headbutt.\p"
# 706 "data/maps/IlexForest/scripts.pory"
	.string "Do you think your Pokémon will\n"
# 707 "data/maps/IlexForest/scripts.pory"
	.string "want to Headbutt, too?\p"
# 708 "data/maps/IlexForest/scripts.pory"
	.string "I can teach one the move Headbutt\n"
# 709 "data/maps/IlexForest/scripts.pory"
	.string "if you'd like. It's fun!$"
# 710 "data/maps/IlexForest/scripts.pory"
	
# 711 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttWhichMon:
# 712 "data/maps/IlexForest/scripts.pory"
	.string "Ehehe, sure thing! It'd be great if\n"
# 713 "data/maps/IlexForest/scripts.pory"
	.string "the Pokémon looked like me.$"
# 714 "data/maps/IlexForest/scripts.pory"

# 715 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttDeclined:
# 716 "data/maps/IlexForest/scripts.pory"
	.string "You don't need to be shy about it.\n"
# 717 "data/maps/IlexForest/scripts.pory"
	.string "Let's butt heads!$"
# 718 "data/maps/IlexForest/scripts.pory"

# 719 "data/maps/IlexForest/scripts.pory"
MoveTutor_Text_HeadbuttTaught:
# 720 "data/maps/IlexForest/scripts.pory"
	.string "Rattle enemies with Headbutt.\n"
# 721 "data/maps/IlexForest/scripts.pory"
	.string "Sometimes, they will flinch.$"
# 722 "data/maps/IlexForest/scripts.pory"

# 723 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Lass:
# 724 "data/maps/IlexForest/scripts.pory"
	.string "Did something happen to the\n"
# 725 "data/maps/IlexForest/scripts.pory"
	.string "forest's guardian?$"
# 726 "data/maps/IlexForest/scripts.pory"

# 727 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Signpost:
# 728 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest is so overgrown with\n"
# 729 "data/maps/IlexForest/scripts.pory"
	.string "trees that you can't see the sky.\p"
# 730 "data/maps/IlexForest/scripts.pory"
	.string "Please watch out for items that may\n"
# 731 "data/maps/IlexForest/scripts.pory"
	.string "have been dropped.$"
# 732 "data/maps/IlexForest/scripts.pory"

# 733 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Shrine:
# 734 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest Shrine…\p"
# 735 "data/maps/IlexForest/scripts.pory"
	.string "It's in honor of the forest's\n"
# 736 "data/maps/IlexForest/scripts.pory"
	.string "protector…$"
# 737 "data/maps/IlexForest/scripts.pory"

# 738 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_ShrineCelebiEvent:
# 739 "data/maps/IlexForest/scripts.pory"
	.string "Ilex Forest Shrine…\p"
# 740 "data/maps/IlexForest/scripts.pory"
	.string "It's in honor of the forest's\n"
# 741 "data/maps/IlexForest/scripts.pory"
	.string "protector…\p"
# 742 "data/maps/IlexForest/scripts.pory"
	.string "Oh? What is this?\p"
# 743 "data/maps/IlexForest/scripts.pory"
	.string "It's a hole.\n"
# 744 "data/maps/IlexForest/scripts.pory"
	.string "It looks like the Gs Ball would fit\l"
# 745 "data/maps/IlexForest/scripts.pory"
	.string "inside it.\p"
# 746 "data/maps/IlexForest/scripts.pory"
	.string "Want to put the Gs Ball here?$"
# 747 "data/maps/IlexForest/scripts.pory"

# 748 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_InsertGSBall:
# 749 "data/maps/IlexForest/scripts.pory"
	.string "{PLAYER} put in the Gs Ball.$"
# 750 "data/maps/IlexForest/scripts.pory"

# 751 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_KurtCaughtCelebi:
# 752 "data/maps/IlexForest/scripts.pory"
	.string "Whew, wasn't that something!\p"
# 753 "data/maps/IlexForest/scripts.pory"
	.string "{PLAYER}, that was fantastic. Thanks!\p"
# 754 "data/maps/IlexForest/scripts.pory"
	.string "The legends about that Shrine were\n"
# 755 "data/maps/IlexForest/scripts.pory"
	.string "real after all.\p"
# 756 "data/maps/IlexForest/scripts.pory"
	.string "I feel inspired by what I just saw.\p"
# 757 "data/maps/IlexForest/scripts.pory"
	.string "It motivates me to make better Balls!\p"
# 758 "data/maps/IlexForest/scripts.pory"
	.string "I'm going!$"
# 759 "data/maps/IlexForest/scripts.pory"

# 760 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneSeen:
# 761 "data/maps/IlexForest/scripts.pory"
	.string "Don't sneak up on me like that!\p"
# 762 "data/maps/IlexForest/scripts.pory"
	.string "You frightened a Pokémon away!$"
# 763 "data/maps/IlexForest/scripts.pory"

# 764 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneBeaten:
# 765 "data/maps/IlexForest/scripts.pory"
	.string "I hadn't seen that Pokémon before…$"
# 766 "data/maps/IlexForest/scripts.pory"

# 767 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_BugCatcherWayneAfter:
# 768 "data/maps/IlexForest/scripts.pory"
	.string "A Pokémon I've never seen before\n"
# 769 "data/maps/IlexForest/scripts.pory"
	.string "fell out of the tree when I used\l"
# 770 "data/maps/IlexForest/scripts.pory"
	.string "Headbutt.\p"
# 771 "data/maps/IlexForest/scripts.pory"
	.string "I ought to use Headbutt in other\n"
# 772 "data/maps/IlexForest/scripts.pory"
	.string "places too.$"
# 773 "data/maps/IlexForest/scripts.pory"

# 774 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl1:
# 775 "data/maps/IlexForest/scripts.pory"
	.string "Kimono Girl, Kimono Girl, lost and\n"
# 776 "data/maps/IlexForest/scripts.pory"
	.string "all alone. Poor girl lost in the\l"
# 777 "data/maps/IlexForest/scripts.pory"
	.string "dark Ilex Forest.$"
# 778 "data/maps/IlexForest/scripts.pory"

# 779 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl2:
# 780 "data/maps/IlexForest/scripts.pory"
	.string "You remember me from Violet City?\n"
# 781 "data/maps/IlexForest/scripts.pory"
	.string "You must be imagining.\p"
# 782 "data/maps/IlexForest/scripts.pory"
	.string "Anyway, will you show me how to\n"
# 783 "data/maps/IlexForest/scripts.pory"
	.string "get out of this forest?$"
# 784 "data/maps/IlexForest/scripts.pory"

# 785 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl3:
# 786 "data/maps/IlexForest/scripts.pory"
	.string "Me oh my... You are lost yourself,\n"
# 787 "data/maps/IlexForest/scripts.pory"
	.string "aren't you?$"
# 788 "data/maps/IlexForest/scripts.pory"

# 789 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl4:
# 790 "data/maps/IlexForest/scripts.pory"
	.string "Wow! Are you going to show me how\n"
# 791 "data/maps/IlexForest/scripts.pory"
	.string "to get out?\p"
# 792 "data/maps/IlexForest/scripts.pory"
	.string "You are such a smart Pokémon!$"
# 793 "data/maps/IlexForest/scripts.pory"

# 794 "data/maps/IlexForest/scripts.pory"
IlexForest_Text_Kimono_Girl5:
# 795 "data/maps/IlexForest/scripts.pory"
	.string "See you.$"

# 798 "data/maps/IlexForest/scripts.pory"
showilexfollower:
# 799 "data/maps/IlexForest/scripts.pory"
	set_visible
# 800 "data/maps/IlexForest/scripts.pory"
	step_end

Ilex_HiddenGrotto::
# 804 "data/maps/IlexForest/scripts.pory"
	msgbox Ilex_HiddenGrotto_Text_0, MSGBOX_YESNO
# 806 "data/maps/IlexForest/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ilex_HiddenGrotto_2
Ilex_HiddenGrotto_1:
# 810 "data/maps/IlexForest/scripts.pory"
	release
	end

Ilex_HiddenGrotto_2:
# 807 "data/maps/IlexForest/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ILEX, 0
# 808 "data/maps/IlexForest/scripts.pory"
	waitstate
	goto Ilex_HiddenGrotto_1


Ilex_Larvesta::
# 815 "data/maps/IlexForest/scripts.pory"
	lock
# 816 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 817 "data/maps/IlexForest/scripts.pory"
	legendaryencounter SPECIES_LARVESTA, 30, LOCALID_ILEX_LARVESTA, FLAG_HIDE_LARVESTA
# 818 "data/maps/IlexForest/scripts.pory"
	release
	end


Ilex_LittleBoy::
# 823 "data/maps/IlexForest/scripts.pory"
	lock
# 824 "data/maps/IlexForest/scripts.pory"
	faceplayer
# 825 "data/maps/IlexForest/scripts.pory"
	goto_if_set FLAG_ILEX_BECKONING_BELL, Ilex_LittleBoy_2
# 831 "data/maps/IlexForest/scripts.pory"
	msgbox Ilex_LittleBoy_Text_1
# 833 "data/maps/IlexForest/scripts.pory"
	giveitem ITEM_BECKONING_BELL
# 834 "data/maps/IlexForest/scripts.pory"
	setflag FLAG_ILEX_BECKONING_BELL
# 835 "data/maps/IlexForest/scripts.pory"
	msgbox Ilex_LittleBoy_Text_0
# 837 "data/maps/IlexForest/scripts.pory"
	release
	end

Ilex_LittleBoy_2:
# 826 "data/maps/IlexForest/scripts.pory"
	msgbox Ilex_LittleBoy_Text_0
# 828 "data/maps/IlexForest/scripts.pory"
	release
	end


Ilex_HiddenGrotto_Text_0:
# 804 "data/maps/IlexForest/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Ilex_LittleBoy_Text_0:
# 826 "data/maps/IlexForest/scripts.pory"
	.string "Beckoning Bell renews\n"
	.string "Hidden Grottos once.$"

Ilex_LittleBoy_Text_1:
# 831 "data/maps/IlexForest/scripts.pory"
	.string "Hidden grotto didn't contain what you\n"
	.string "wanted? Try using this.$"
