# 1 "data/maps/LakeOfRage/scripts.pory"

# 2 "data/maps/LakeOfRage/scripts.pory"
.set LOCALID_LAKEOFRAGE_GYARADOS, 8
# 3 "data/maps/LakeOfRage/scripts.pory"
.set LOCALID_LAKEOFRAGE_LANCE, 3
# 4 "data/maps/LakeOfRage/scripts.pory"
.set LOCALID_LAKEOFRAGE_DRAGONITE, 16
# 5 "data/maps/LakeOfRage/scripts.pory"
.set LOCALID_LAKEOFRAGE_OLDMAN, 4
# 6 "data/maps/LakeOfRage/scripts.pory"
.set LOCALID_LAKE_PRYCE, 17
# 7 "data/maps/LakeOfRage/scripts.pory"

# 8 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_MapScripts::
# 9 "data/maps/LakeOfRage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
# 10 "data/maps/LakeOfRage/scripts.pory"
	.byte 0
# 11 "data/maps/LakeOfRage/scripts.pory"

# 12 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_OnTransition::
# 13 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_VISITED_LAKE_OF_RAGE
# 14 "data/maps/LakeOfRage/scripts.pory"
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
# 15 "data/maps/LakeOfRage/scripts.pory"
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
# 16 "data/maps/LakeOfRage/scripts.pory"
	special UpdateShoalTideFlag
# 17 "data/maps/LakeOfRage/scripts.pory"
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
# 18 "data/maps/LakeOfRage/scripts.pory"
	goto LakeOfRage_EventScript_SetLowTide
# 19 "data/maps/LakeOfRage/scripts.pory"

# 20 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_SetLowTide::
# 21 "data/maps/LakeOfRage/scripts.pory"
	setweather WEATHER_NONE
# 22 "data/maps/LakeOfRage/scripts.pory"
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
# 23 "data/maps/LakeOfRage/scripts.pory"
	end
# 24 "data/maps/LakeOfRage/scripts.pory"

# 25 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_SetHighTide::
# 26 "data/maps/LakeOfRage/scripts.pory"
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
# 27 "data/maps/LakeOfRage/scripts.pory"
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
# 28 "data/maps/LakeOfRage/scripts.pory"
	random 2
# 29 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
# 30 "data/maps/LakeOfRage/scripts.pory"
	end
# 31 "data/maps/LakeOfRage/scripts.pory"

# 32 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_HideLois::
# 33 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_TEMP_1
# 34 "data/maps/LakeOfRage/scripts.pory"
	return
# 35 "data/maps/LakeOfRage/scripts.pory"

# 36 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_ThunderStorm::
# 37 "data/maps/LakeOfRage/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
# 38 "data/maps/LakeOfRage/scripts.pory"
	end
# 39 "data/maps/LakeOfRage/scripts.pory"

# 40 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Pryce::
# 41 "data/maps/LakeOfRage/scripts.pory"
    lock
# 42 "data/maps/LakeOfRage/scripts.pory"
    faceplayer
# 43 "data/maps/LakeOfRage/scripts.pory"
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
# 44 "data/maps/LakeOfRage/scripts.pory"
    closemessage
# 45 "data/maps/LakeOfRage/scripts.pory"
    fadescreenswapbuffers FADE_TO_BLACK
# 46 "data/maps/LakeOfRage/scripts.pory"
    setflag FLAG_HIDE_LAKE_PRYCE
# 47 "data/maps/LakeOfRage/scripts.pory"
    removeobject LOCALID_LAKE_PRYCE
# 48 "data/maps/LakeOfRage/scripts.pory"
    fadescreenswapbuffers FADE_FROM_BLACK
# 49 "data/maps/LakeOfRage/scripts.pory"
    clearflag FLAG_HIDE_DOJO_PRYCE
# 50 "data/maps/LakeOfRage/scripts.pory"
    release
# 51 "data/maps/LakeOfRage/scripts.pory"
    end
# 52 "data/maps/LakeOfRage/scripts.pory"

# 53 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Pryce:
# 54 "data/maps/LakeOfRage/scripts.pory"
    .string "{PLAYER}.\p"
# 55 "data/maps/LakeOfRage/scripts.pory"
	.string "Even here, the cold keeps me sharp.\p"
# 56 "data/maps/LakeOfRage/scripts.pory"
	.string "If you wish to battle again, come\n"
# 57 "data/maps/LakeOfRage/scripts.pory"
	.string "to the Fighting Dojo.$"
# 58 "data/maps/LakeOfRage/scripts.pory"

# 59 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gramps::
# 60 "data/maps/LakeOfRage/scripts.pory"
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
# 61 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
# 62 "data/maps/LakeOfRage/scripts.pory"
	end
# 63 "data/maps/LakeOfRage/scripts.pory"

# 64 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gramps2::
# 65 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
# 66 "data/maps/LakeOfRage/scripts.pory"
	end
# 67 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lass::
# 68 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
# 69 "data/maps/LakeOfRage/scripts.pory"
	end
# 70 "data/maps/LakeOfRage/scripts.pory"

# 71 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Nerd::
# 72 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
# 73 "data/maps/LakeOfRage/scripts.pory"
	end
# 74 "data/maps/LakeOfRage/scripts.pory"

# 75 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Andre::
# 76 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_ANDRE LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
# 77 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
# 78 "data/maps/LakeOfRage/scripts.pory"
	end
# 79 "data/maps/LakeOfRage/scripts.pory"

# 80 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Raymond::
# 81 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_RAYMOND LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
# 82 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
# 83 "data/maps/LakeOfRage/scripts.pory"
	end
# 84 "data/maps/LakeOfRage/scripts.pory"

# 85 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Aaron::
# 86 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_AARON LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
# 87 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
# 88 "data/maps/LakeOfRage/scripts.pory"
	end
# 89 "data/maps/LakeOfRage/scripts.pory"

# 90 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lois::
# 91 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_LOIS LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
# 92 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
# 93 "data/maps/LakeOfRage/scripts.pory"
	end
# 94 "data/maps/LakeOfRage/scripts.pory"

# 95 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gyarados::
# 96 "data/maps/LakeOfRage/scripts.pory"
	lock
# 97 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 98 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
# 99 "data/maps/LakeOfRage/scripts.pory"
	waitse
# 100 "data/maps/LakeOfRage/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 101 "data/maps/LakeOfRage/scripts.pory"
	delay 40
# 102 "data/maps/LakeOfRage/scripts.pory"
	waitmoncry
# 103 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_SET_SHINY
# 104 "data/maps/LakeOfRage/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 35
# 105 "data/maps/LakeOfRage/scripts.pory"
	dowildbattle
# 106 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_SET_SHINY
# 107 "data/maps/LakeOfRage/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 108 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
# 109 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
# 110 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
# 111 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Defeated_Gyarados::
# 112 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
# 113 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_TEMP_1
# 114 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
# 115 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
# 116 "data/maps/LakeOfRage/scripts.pory"
	addobject LOCALID_LAKEOFRAGE_LANCE
# 117 "data/maps/LakeOfRage/scripts.pory"
	giveitem ITEM_RED_SCALE
# 118 "data/maps/LakeOfRage/scripts.pory"
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
# 119 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 2
# 120 "data/maps/LakeOfRage/scripts.pory"
	release
# 121 "data/maps/LakeOfRage/scripts.pory"
	end
# 122 "data/maps/LakeOfRage/scripts.pory"

# 123 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Ran_Gyarados::
# 124 "data/maps/LakeOfRage/scripts.pory"
	release
# 125 "data/maps/LakeOfRage/scripts.pory"
	end
# 126 "data/maps/LakeOfRage/scripts.pory"

# 127 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Dragonite::
# 128 "data/maps/LakeOfRage/scripts.pory"
	lock
# 129 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 130 "data/maps/LakeOfRage/scripts.pory"
	waitse
# 131 "data/maps/LakeOfRage/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 132 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
# 133 "data/maps/LakeOfRage/scripts.pory"
	waitmoncry
# 134 "data/maps/LakeOfRage/scripts.pory"
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
# 135 "data/maps/LakeOfRage/scripts.pory"
	release
# 136 "data/maps/LakeOfRage/scripts.pory"
	end
# 137 "data/maps/LakeOfRage/scripts.pory"

# 138 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lance::
# 139 "data/maps/LakeOfRage/scripts.pory"
	lock
# 140 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
# 141 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
# 142 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 143 "data/maps/LakeOfRage/scripts.pory"
	delay 20
# 144 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 145 "data/maps/LakeOfRage/scripts.pory"
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
# 146 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
# 147 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 3
# 148 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
# 149 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
# 150 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LanceAccept::
# 151 "data/maps/LakeOfRage/scripts.pory"
	lock
# 152 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
# 153 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 154 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
# 155 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
# 156 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
# 157 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_LANCE
# 158 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
# 159 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_EndScene::
# 160 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
# 161 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_LANCE
# 162 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
# 163 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 4
# 164 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
# 165 "data/maps/LakeOfRage/scripts.pory"
	release
# 166 "data/maps/LakeOfRage/scripts.pory"
	end
# 167 "data/maps/LakeOfRage/scripts.pory"

# 168 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lance_Return::
# 169 "data/maps/LakeOfRage/scripts.pory"
	lock
# 170 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 171 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
# 172 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
# 173 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
# 174 "data/maps/LakeOfRage/scripts.pory"

# 175 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LancDeclined::
# 176 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
# 177 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 178 "data/maps/LakeOfRage/scripts.pory"
	release
# 179 "data/maps/LakeOfRage/scripts.pory"
	end
# 180 "data/maps/LakeOfRage/scripts.pory"

# 181 "data/maps/LakeOfRage/scripts.pory"

# 182 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
# 183 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
# 184 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
# 185 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_LANCE
# 186 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
# 187 "data/maps/LakeOfRage/scripts.pory"
	goto LakeOfRage_EventScript_EndScene
# 188 "data/maps/LakeOfRage/scripts.pory"

# 189 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_LanceLeaveNorth:
# 190 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 191 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 192 "data/maps/LakeOfRage/scripts.pory"
	delay_8
# 193 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 194 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 195 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 196 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 197 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 198 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 199 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 200 "data/maps/LakeOfRage/scripts.pory"

# 201 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_DragoniteLeaveNorth:
# 202 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 203 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 204 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 205 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 206 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 207 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 208 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 209 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 210 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 211 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 212 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 213 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 214 "data/maps/LakeOfRage/scripts.pory"

# 215 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_LanceLeave:
# 216 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 217 "data/maps/LakeOfRage/scripts.pory"
	delay_8
# 218 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 219 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 220 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 221 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 222 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 223 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 224 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 225 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 226 "data/maps/LakeOfRage/scripts.pory"

# 227 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_DragoniteLeave:
# 228 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 229 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 230 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 231 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 232 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 233 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 234 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 235 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 236 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 237 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 238 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 239 "data/maps/LakeOfRage/scripts.pory"

# 240 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Dragonite:
# 241 "data/maps/LakeOfRage/scripts.pory"
	.string "Dragonite: Gyafooha!$"
# 242 "data/maps/LakeOfRage/scripts.pory"

# 243 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceForcedToEvolve:
# 244 "data/maps/LakeOfRage/scripts.pory"
    .string "This lake is full of Gyarados\n"
# 245 "data/maps/LakeOfRage/scripts.pory"
    .string "but nothing else…\p"
# 246 "data/maps/LakeOfRage/scripts.pory"
    .string "So the Magikarp are being forced\n"
# 247 "data/maps/LakeOfRage/scripts.pory"
    .string "to evolve…$"
# 248 "data/maps/LakeOfRage/scripts.pory"

# 249 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro1:
# 250 "data/maps/LakeOfRage/scripts.pory"
    .string "Did you come here because of\n"
# 251 "data/maps/LakeOfRage/scripts.pory"
    .string "the rumors?\p"
# 252 "data/maps/LakeOfRage/scripts.pory"
    .string "You're {PLAYER}? I'm Lance, a\n"
# 253 "data/maps/LakeOfRage/scripts.pory"
    .string "trainer like you.$"
# 254 "data/maps/LakeOfRage/scripts.pory"

# 255 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro2:
# 256 "data/maps/LakeOfRage/scripts.pory"
    .string "This man here informed me of\n"
# 257 "data/maps/LakeOfRage/scripts.pory"
    .string "some rumors.\p"
# 258 "data/maps/LakeOfRage/scripts.pory"
    .string "So we came to investigate…$"
# 259 "data/maps/LakeOfRage/scripts.pory"

# 260 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro3:
# 261 "data/maps/LakeOfRage/scripts.pory"
    .string "I saw the way you battled\n"
# 262 "data/maps/LakeOfRage/scripts.pory"
    .string "earlier, {PLAYER}.\p"
# 263 "data/maps/LakeOfRage/scripts.pory"
    .string "I can tell that you're a trainer\n"
# 264 "data/maps/LakeOfRage/scripts.pory"
    .string "with considerable skill.\p"
# 265 "data/maps/LakeOfRage/scripts.pory"
    .string "If you don't mind, could you help\n"
# 266 "data/maps/LakeOfRage/scripts.pory"
    .string "us investigate?$"
# 267 "data/maps/LakeOfRage/scripts.pory"

# 268 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceRadioSignal:
# 269 "data/maps/LakeOfRage/scripts.pory"
    .string "Lance: Excellent!\p"
# 270 "data/maps/LakeOfRage/scripts.pory"
    .string "It seems that the Lake's Magikarp\n"
# 271 "data/maps/LakeOfRage/scripts.pory"
    .string "are being forced to evolve.\p"
# 272 "data/maps/LakeOfRage/scripts.pory"
    .string "A mysterious radio broadcast\n"
# 273 "data/maps/LakeOfRage/scripts.pory"
    .string "coming from Mahogany is the cause.\p"
# 274 "data/maps/LakeOfRage/scripts.pory"
    .string "We'll be waiting for you,\n"
# 275 "data/maps/LakeOfRage/scripts.pory"
    .string "{PLAYER}.$"
# 276 "data/maps/LakeOfRage/scripts.pory"

# 277 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceRefused:
# 278 "data/maps/LakeOfRage/scripts.pory"
    .string "Oh… Well, if you change your mind,\n"
# 279 "data/maps/LakeOfRage/scripts.pory"
    .string "please help us.$"
# 280 "data/maps/LakeOfRage/scripts.pory"

# 281 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceAskHelp:
# 282 "data/maps/LakeOfRage/scripts.pory"
    .string "Lance: Hm? Are you going to help\n"
# 283 "data/maps/LakeOfRage/scripts.pory"
    .string "us?$"
# 284 "data/maps/LakeOfRage/scripts.pory"

# 285 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_GyaradosCry:
# 286 "data/maps/LakeOfRage/scripts.pory"
    .string "Gyarados: Gyashaa!$"
# 287 "data/maps/LakeOfRage/scripts.pory"

# 288 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Gramps:
# 289 "data/maps/LakeOfRage/scripts.pory"
    .string "The Gyarados are angry!\p"
# 290 "data/maps/LakeOfRage/scripts.pory"
    .string "It's a bad omen!$"
# 291 "data/maps/LakeOfRage/scripts.pory"

# 292 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_GrampsCleared:
# 293 "data/maps/LakeOfRage/scripts.pory"
    .string "Hahah! The Magikarp are biting!$"
# 294 "data/maps/LakeOfRage/scripts.pory"

# 295 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_SuperNerd:
# 296 "data/maps/LakeOfRage/scripts.pory"
    .string "I heard this lake was made by\n"
# 297 "data/maps/LakeOfRage/scripts.pory"
    .string "rampaging Gyarados.\p"
# 298 "data/maps/LakeOfRage/scripts.pory"
    .string "I wonder if there is any\n"
# 299 "data/maps/LakeOfRage/scripts.pory"
    .string "connection to their mass outbreak\l"
# 300 "data/maps/LakeOfRage/scripts.pory"
    .string "now?$"
# 301 "data/maps/LakeOfRage/scripts.pory"

# 302 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerF:
# 303 "data/maps/LakeOfRage/scripts.pory"
    .string "Did my eyes deceive me? I saw a\n"
# 304 "data/maps/LakeOfRage/scripts.pory"
    .string "red Gyarados in the Lake…\p"
# 305 "data/maps/LakeOfRage/scripts.pory"
    .string "But I thought Gyarados were\n"
# 306 "data/maps/LakeOfRage/scripts.pory"
    .string "usually blue?$"
# 307 "data/maps/LakeOfRage/scripts.pory"

# 308 "data/maps/LakeOfRage/scripts.pory"

# 309 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreSeen:
# 310 "data/maps/LakeOfRage/scripts.pory"
    .string "Let me battle with the Pokémon I\n"
# 311 "data/maps/LakeOfRage/scripts.pory"
    .string "just caught!$"
# 312 "data/maps/LakeOfRage/scripts.pory"

# 313 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreBeaten:
# 314 "data/maps/LakeOfRage/scripts.pory"
    .string "I might be an expert angler, but\n"
# 315 "data/maps/LakeOfRage/scripts.pory"
    .string "I stink as a Pokémon trainer…$"
# 316 "data/maps/LakeOfRage/scripts.pory"

# 317 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreAfter:
# 318 "data/maps/LakeOfRage/scripts.pory"
    .string "I won't lose as an angler! I catch\n"
# 319 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon all day.$"
# 320 "data/maps/LakeOfRage/scripts.pory"

# 321 "data/maps/LakeOfRage/scripts.pory"

# 322 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondSeen:
# 323 "data/maps/LakeOfRage/scripts.pory"
    .string "No matter what I do, all I catch\n"
# 324 "data/maps/LakeOfRage/scripts.pory"
    .string "are the same Pokémon…$"
# 325 "data/maps/LakeOfRage/scripts.pory"

# 326 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondBeaten:
# 327 "data/maps/LakeOfRage/scripts.pory"
    .string "My line's all tangled up…$"
# 328 "data/maps/LakeOfRage/scripts.pory"

# 329 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondAfter:
# 330 "data/maps/LakeOfRage/scripts.pory"
    .string "Why can't I catch any good\n"
# 331 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon?$"
# 332 "data/maps/LakeOfRage/scripts.pory"

# 333 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronSeen:
# 334 "data/maps/LakeOfRage/scripts.pory"
    .string "If a trainer spots another trainer,\n"
# 335 "data/maps/LakeOfRage/scripts.pory"
    .string "he has to make a challenge.\p"
# 336 "data/maps/LakeOfRage/scripts.pory"
    .string "That is our destiny.$"
# 337 "data/maps/LakeOfRage/scripts.pory"

# 338 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronBeaten:
# 339 "data/maps/LakeOfRage/scripts.pory"
    .string "Whew… Good battle.$"
# 340 "data/maps/LakeOfRage/scripts.pory"

# 341 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronAfter:
# 342 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon and their trainer become\n"
# 343 "data/maps/LakeOfRage/scripts.pory"
    .string "powerful through constant battling.$"
# 344 "data/maps/LakeOfRage/scripts.pory"

# 345 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisSeen:
# 346 "data/maps/LakeOfRage/scripts.pory"
    .string "What happened to the red\n"
# 347 "data/maps/LakeOfRage/scripts.pory"
    .string "Gyarados?\p"
# 348 "data/maps/LakeOfRage/scripts.pory"
    .string "It's gone?\p"
# 349 "data/maps/LakeOfRage/scripts.pory"
    .string "Oh, darn. I came here for\n"
# 350 "data/maps/LakeOfRage/scripts.pory"
    .string "nothing?\p"
# 351 "data/maps/LakeOfRage/scripts.pory"
    .string "I know--let's battle!$"
# 352 "data/maps/LakeOfRage/scripts.pory"

# 353 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisBeaten:
# 354 "data/maps/LakeOfRage/scripts.pory"
    .string "Good going!$"
# 355 "data/maps/LakeOfRage/scripts.pory"

# 356 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisAfter:
# 357 "data/maps/LakeOfRage/scripts.pory"
    .string "Come to think of it, I've seen a\n"
# 358 "data/maps/LakeOfRage/scripts.pory"
    .string "pink Butterfree.$"
# 359 "data/maps/LakeOfRage/scripts.pory"

# 360 "data/maps/LakeOfRage/scripts.pory"

# 361 "data/maps/LakeOfRage/scripts.pory"

# 362 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Wesley::
# 363 "data/maps/LakeOfRage/scripts.pory"
	lock
# 364 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 365 "data/maps/LakeOfRage/scripts.pory"
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
# 366 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
# 367 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 368 "data/maps/LakeOfRage/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 369 "data/maps/LakeOfRage/scripts.pory"
	switch VAR_RESULT
# 370 "data/maps/LakeOfRage/scripts.pory"
	case 0, LakeOfRage_EventScript_WesleyNope
# 371 "data/maps/LakeOfRage/scripts.pory"
	case 1, LakeOfRage_EventScript_WesleyNope
# 372 "data/maps/LakeOfRage/scripts.pory"
	case 2, LakeOfRage_EventScript_WesleyNope
# 373 "data/maps/LakeOfRage/scripts.pory"
	case 3, LakeOfRage_EventScript_WesleyYes
# 374 "data/maps/LakeOfRage/scripts.pory"
	case 4, LakeOfRage_EventScript_WesleyNope
# 375 "data/maps/LakeOfRage/scripts.pory"
	case 5, LakeOfRage_EventScript_WesleyNope
# 376 "data/maps/LakeOfRage/scripts.pory"
	case 6, LakeOfRage_EventScript_WesleyNope
# 377 "data/maps/LakeOfRage/scripts.pory"
	case 7 LakeOfRage_EventScript_WesleyCancel
# 378 "data/maps/LakeOfRage/scripts.pory"
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
# 379 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 380 "data/maps/LakeOfRage/scripts.pory"
	release
# 381 "data/maps/LakeOfRage/scripts.pory"
	end
# 382 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyYes::
# 383 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
# 384 "data/maps/LakeOfRage/scripts.pory"
	giveitem ITEM_BLACK_BELT
# 385 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 386 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_GOT_BLACK_BELT
# 387 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
# 388 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 389 "data/maps/LakeOfRage/scripts.pory"
	release
# 390 "data/maps/LakeOfRage/scripts.pory"
	end
# 391 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyNope::
# 392 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
# 393 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 394 "data/maps/LakeOfRage/scripts.pory"
	release
# 395 "data/maps/LakeOfRage/scripts.pory"
	end
# 396 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyCancel::
# 397 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 398 "data/maps/LakeOfRage/scripts.pory"
	release
# 399 "data/maps/LakeOfRage/scripts.pory"
	end
# 400 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyCompleted::
# 401 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
# 402 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 403 "data/maps/LakeOfRage/scripts.pory"
	release
# 404 "data/maps/LakeOfRage/scripts.pory"
	end
# 405 "data/maps/LakeOfRage/scripts.pory"

# 406 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_MeetWesley:
# 407 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Well, how do you do?\p"
# 408 "data/maps/LakeOfRage/scripts.pory"
    .string "I'm a member of the Weekday family!\n"
# 409 "data/maps/LakeOfRage/scripts.pory"
	.string "Can you guess my favorite day?$"
# 410 "data/maps/LakeOfRage/scripts.pory"

# 411 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyGivesGift:
# 412 "data/maps/LakeOfRage/scripts.pory"
    .string "Pleased to meet you. Please take a\n"
# 413 "data/maps/LakeOfRage/scripts.pory"
    .string "souvenir.$"
# 414 "data/maps/LakeOfRage/scripts.pory"

# 415 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyGaveGift:
# 416 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Blackbelt beefs up the\n"
# 417 "data/maps/LakeOfRage/scripts.pory"
    .string "power of fighting moves.$"
# 418 "data/maps/LakeOfRage/scripts.pory"

# 419 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyWednesday:
# 420 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Since you found me, you\n"
# 421 "data/maps/LakeOfRage/scripts.pory"
    .string "must have met my brothers and\l"
# 422 "data/maps/LakeOfRage/scripts.pory"
    .string "sisters.\p"
# 423 "data/maps/LakeOfRage/scripts.pory"
    .string "Or did you just get lucky?$"
# 424 "data/maps/LakeOfRage/scripts.pory"

# 425 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyNotWednesday:
# 426 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Not exactly...$"
# 427 "data/maps/LakeOfRage/scripts.pory"

# 428 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Sign1::
# 429 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
# 430 "data/maps/LakeOfRage/scripts.pory"
	end
# 431 "data/maps/LakeOfRage/scripts.pory"

# 432 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Sign2::
# 433 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
# 434 "data/maps/LakeOfRage/scripts.pory"
	end
# 435 "data/maps/LakeOfRage/scripts.pory"

# 436 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Sign:
# 437 "data/maps/LakeOfRage/scripts.pory"
    .string "Lake Of Rage,\n"
# 438 "data/maps/LakeOfRage/scripts.pory"
    .string "also known as Gyarados Lake.$"
# 439 "data/maps/LakeOfRage/scripts.pory"

# 440 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FishingGuruSign:
# 441 "data/maps/LakeOfRage/scripts.pory"
    .string "Fishing Guru'S House$"

Lakeofrage_HiddenGrotto::
# 445 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_HiddenGrotto_Text_0, MSGBOX_YESNO
# 447 "data/maps/LakeOfRage/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lakeofrage_HiddenGrotto_2
Lakeofrage_HiddenGrotto_1:
# 451 "data/maps/LakeOfRage/scripts.pory"
	release
	end

Lakeofrage_HiddenGrotto_2:
# 448 "data/maps/LakeOfRage/scripts.pory"
	warp MAP_HIDDEN_GROTTO_LAKEOFRAGE, 0
# 449 "data/maps/LakeOfRage/scripts.pory"
	waitstate
	goto Lakeofrage_HiddenGrotto_1


Lakeofrage_PryceRematch::
# 456 "data/maps/LakeOfRage/scripts.pory"
	lock
# 457 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 458 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_0
# 465 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_1, MSGBOX_YESNO
# 468 "data/maps/LakeOfRage/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lakeofrage_PryceRematch_2
Lakeofrage_PryceRematch_1:
# 488 "data/maps/LakeOfRage/scripts.pory"
	release
	end

Lakeofrage_PryceRematch_2:
# 469 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_no_intro TRAINER_PRYCE_2, Lakeofrage_PryceRematch_Text_2
# 470 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_3
# 481 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 482 "data/maps/LakeOfRage/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 483 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_PRYCE
# 484 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_PRYCE_REMATCH
# 485 "data/maps/LakeOfRage/scripts.pory"
	delay 30
# 486 "data/maps/LakeOfRage/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Lakeofrage_PryceRematch_1


Lakeofrage_HiddenGrotto_Text_0:
# 445 "data/maps/LakeOfRage/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Lakeofrage_PryceRematch_Text_0:
# 458 "data/maps/LakeOfRage/scripts.pory"
	.string "{PLAYER}, the cold of Indigo Plateau\n"
	.string "has not worn you down I see.\p"
	.string "Personally I prefer the cold, it keeps\n"
	.string "my senses sharp. Warmth can make one\l"
	.string "drop their guard.$"

Lakeofrage_PryceRematch_Text_1:
# 465 "data/maps/LakeOfRage/scripts.pory"
	.string "How about I show you what I mean\n"
	.string "in a battle. I won't be holding\l"
	.string "back this time.$"

Lakeofrage_PryceRematch_Text_2:
# 469 "data/maps/LakeOfRage/scripts.pory"
	.string "Reminds me of the old days.$"

Lakeofrage_PryceRematch_Text_3:
# 470 "data/maps/LakeOfRage/scripts.pory"
	.string "I worry less for the future generations\n"
	.string "when I see trainers like you rise up.\p"
	.string "I hope you will foster the growth\n"
	.string "of future generations in your own\l"
	.string "time, too.\p"
	.string "I believe I still have more I can\n"
	.string "show you another time, but I must\l"
	.string "return to my training in order\l"
	.string "to achieve it.$"
