# 1 "data/maps/LakeOfRage/scripts.pory"

# 2 "data/maps/LakeOfRage/scripts.pory"

# 3 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_MapScripts::
# 4 "data/maps/LakeOfRage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
# 5 "data/maps/LakeOfRage/scripts.pory"
	.byte 0
# 6 "data/maps/LakeOfRage/scripts.pory"

# 7 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_OnTransition::
# 8 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_VISITED_LAKE_OF_RAGE
# 9 "data/maps/LakeOfRage/scripts.pory"
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
# 10 "data/maps/LakeOfRage/scripts.pory"
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
# 11 "data/maps/LakeOfRage/scripts.pory"
	special UpdateShoalTideFlag
# 12 "data/maps/LakeOfRage/scripts.pory"
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
# 13 "data/maps/LakeOfRage/scripts.pory"
	goto LakeOfRage_EventScript_SetLowTide
# 14 "data/maps/LakeOfRage/scripts.pory"

# 15 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_SetLowTide::
# 16 "data/maps/LakeOfRage/scripts.pory"
	setweather WEATHER_NONE
# 17 "data/maps/LakeOfRage/scripts.pory"
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
# 18 "data/maps/LakeOfRage/scripts.pory"
	end
# 19 "data/maps/LakeOfRage/scripts.pory"

# 20 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_SetHighTide::
# 21 "data/maps/LakeOfRage/scripts.pory"
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
# 22 "data/maps/LakeOfRage/scripts.pory"
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
# 23 "data/maps/LakeOfRage/scripts.pory"
	random 2
# 24 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
# 25 "data/maps/LakeOfRage/scripts.pory"
	end
# 26 "data/maps/LakeOfRage/scripts.pory"

# 27 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_HideLois::
# 28 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_TEMP_1
# 29 "data/maps/LakeOfRage/scripts.pory"
	return
# 30 "data/maps/LakeOfRage/scripts.pory"

# 31 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_ThunderStorm::
# 32 "data/maps/LakeOfRage/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
# 33 "data/maps/LakeOfRage/scripts.pory"
	end
# 34 "data/maps/LakeOfRage/scripts.pory"

# 35 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Pryce::
# 36 "data/maps/LakeOfRage/scripts.pory"
    lock
# 37 "data/maps/LakeOfRage/scripts.pory"
    faceplayer
# 38 "data/maps/LakeOfRage/scripts.pory"
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
# 39 "data/maps/LakeOfRage/scripts.pory"
    closemessage
# 40 "data/maps/LakeOfRage/scripts.pory"
    fadescreenswapbuffers FADE_TO_BLACK
# 41 "data/maps/LakeOfRage/scripts.pory"
    setflag FLAG_HIDE_LAKE_PRYCE
# 42 "data/maps/LakeOfRage/scripts.pory"
    removeobject LOCALID_PRYCE_REMATCH
# 43 "data/maps/LakeOfRage/scripts.pory"
    fadescreenswapbuffers FADE_FROM_BLACK
# 44 "data/maps/LakeOfRage/scripts.pory"
    clearflag FLAG_HIDE_DOJO_PRYCE
# 45 "data/maps/LakeOfRage/scripts.pory"
    release
# 46 "data/maps/LakeOfRage/scripts.pory"
    end
# 47 "data/maps/LakeOfRage/scripts.pory"

# 48 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Pryce:
# 49 "data/maps/LakeOfRage/scripts.pory"
    .string "{PLAYER}.\p"
# 50 "data/maps/LakeOfRage/scripts.pory"
	.string "Even here, the cold keeps me sharp.\p"
# 51 "data/maps/LakeOfRage/scripts.pory"
	.string "If you wish to battle again, come\n"
# 52 "data/maps/LakeOfRage/scripts.pory"
	.string "to the Fighting Dojo.$"
# 53 "data/maps/LakeOfRage/scripts.pory"

# 54 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gramps::
# 55 "data/maps/LakeOfRage/scripts.pory"
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
# 56 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
# 57 "data/maps/LakeOfRage/scripts.pory"
	end
# 58 "data/maps/LakeOfRage/scripts.pory"

# 59 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gramps2::
# 60 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
# 61 "data/maps/LakeOfRage/scripts.pory"
	end
# 62 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lass::
# 63 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
# 64 "data/maps/LakeOfRage/scripts.pory"
	end
# 65 "data/maps/LakeOfRage/scripts.pory"

# 66 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Nerd::
# 67 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
# 68 "data/maps/LakeOfRage/scripts.pory"
	end
# 69 "data/maps/LakeOfRage/scripts.pory"

# 70 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Andre::
# 71 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_ANDRE LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
# 72 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
# 73 "data/maps/LakeOfRage/scripts.pory"
	end
# 74 "data/maps/LakeOfRage/scripts.pory"

# 75 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Raymond::
# 76 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_RAYMOND LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
# 77 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
# 78 "data/maps/LakeOfRage/scripts.pory"
	end
# 79 "data/maps/LakeOfRage/scripts.pory"

# 80 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Aaron::
# 81 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_AARON LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
# 82 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
# 83 "data/maps/LakeOfRage/scripts.pory"
	end
# 84 "data/maps/LakeOfRage/scripts.pory"

# 85 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lois::
# 86 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_single TRAINER_LOIS LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
# 87 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
# 88 "data/maps/LakeOfRage/scripts.pory"
	end
# 89 "data/maps/LakeOfRage/scripts.pory"

# 90 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Gyarados::
# 91 "data/maps/LakeOfRage/scripts.pory"
	lock
# 92 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 93 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
# 94 "data/maps/LakeOfRage/scripts.pory"
	waitse
# 95 "data/maps/LakeOfRage/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 96 "data/maps/LakeOfRage/scripts.pory"
	delay 40
# 97 "data/maps/LakeOfRage/scripts.pory"
	waitmoncry
# 98 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_SET_SHINY
# 99 "data/maps/LakeOfRage/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 35
# 100 "data/maps/LakeOfRage/scripts.pory"
	dowildbattle
# 101 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_SET_SHINY
# 102 "data/maps/LakeOfRage/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 103 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
# 104 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
# 105 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
# 106 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Defeated_Gyarados::
# 107 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
# 108 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_TEMP_1
# 109 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
# 110 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
# 111 "data/maps/LakeOfRage/scripts.pory"
	addobject LOCALID_LAKEOFRAGE_LANCE
# 112 "data/maps/LakeOfRage/scripts.pory"
	giveitem ITEM_RED_SCALE
# 113 "data/maps/LakeOfRage/scripts.pory"
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 33, 43
# 114 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 2
# 115 "data/maps/LakeOfRage/scripts.pory"
	release
# 116 "data/maps/LakeOfRage/scripts.pory"
	end
# 117 "data/maps/LakeOfRage/scripts.pory"

# 118 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Ran_Gyarados::
# 119 "data/maps/LakeOfRage/scripts.pory"
	release
# 120 "data/maps/LakeOfRage/scripts.pory"
	end
# 121 "data/maps/LakeOfRage/scripts.pory"

# 122 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Dragonite::
# 123 "data/maps/LakeOfRage/scripts.pory"
	lock
# 124 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 125 "data/maps/LakeOfRage/scripts.pory"
	waitse
# 126 "data/maps/LakeOfRage/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 127 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
# 128 "data/maps/LakeOfRage/scripts.pory"
	waitmoncry
# 129 "data/maps/LakeOfRage/scripts.pory"
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
# 130 "data/maps/LakeOfRage/scripts.pory"
	release
# 131 "data/maps/LakeOfRage/scripts.pory"
	end
# 132 "data/maps/LakeOfRage/scripts.pory"

# 133 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lance::
# 134 "data/maps/LakeOfRage/scripts.pory"
	lock
# 135 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
# 136 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
# 137 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 138 "data/maps/LakeOfRage/scripts.pory"
	delay 20
# 139 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 140 "data/maps/LakeOfRage/scripts.pory"
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
# 141 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
# 142 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 3
# 143 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
# 144 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
# 145 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LanceAccept::
# 146 "data/maps/LakeOfRage/scripts.pory"
	lock
# 147 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
# 148 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 149 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
# 150 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
# 151 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
# 152 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_LANCE
# 153 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
# 154 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_EndScene::
# 155 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
# 156 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_LANCE
# 157 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
# 158 "data/maps/LakeOfRage/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 4
# 159 "data/maps/LakeOfRage/scripts.pory"
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
# 160 "data/maps/LakeOfRage/scripts.pory"
	release
# 161 "data/maps/LakeOfRage/scripts.pory"
	end
# 162 "data/maps/LakeOfRage/scripts.pory"

# 163 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Lance_Return::
# 164 "data/maps/LakeOfRage/scripts.pory"
	lock
# 165 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 166 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
# 167 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
# 168 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
# 169 "data/maps/LakeOfRage/scripts.pory"

# 170 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LancDeclined::
# 171 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
# 172 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 173 "data/maps/LakeOfRage/scripts.pory"
	release
# 174 "data/maps/LakeOfRage/scripts.pory"
	end
# 175 "data/maps/LakeOfRage/scripts.pory"

# 176 "data/maps/LakeOfRage/scripts.pory"

# 177 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
# 178 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
# 179 "data/maps/LakeOfRage/scripts.pory"
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
# 180 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_LANCE
# 181 "data/maps/LakeOfRage/scripts.pory"
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
# 182 "data/maps/LakeOfRage/scripts.pory"
	goto LakeOfRage_EventScript_EndScene
# 183 "data/maps/LakeOfRage/scripts.pory"

# 184 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_LanceLeaveNorth:
# 185 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 186 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 187 "data/maps/LakeOfRage/scripts.pory"
	delay_8
# 188 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 189 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 190 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 191 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 192 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 193 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 194 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 195 "data/maps/LakeOfRage/scripts.pory"

# 196 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_DragoniteLeaveNorth:
# 197 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 198 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 199 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 200 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 201 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 202 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 203 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 204 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 205 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 206 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 207 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 208 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 209 "data/maps/LakeOfRage/scripts.pory"

# 210 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_LanceLeave:
# 211 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 212 "data/maps/LakeOfRage/scripts.pory"
	delay_8
# 213 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 214 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 215 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 216 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 217 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 218 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 219 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 220 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 221 "data/maps/LakeOfRage/scripts.pory"

# 222 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Movement_DragoniteLeave:
# 223 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 224 "data/maps/LakeOfRage/scripts.pory"
	delay_16
# 225 "data/maps/LakeOfRage/scripts.pory"
	walk_left
# 226 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 227 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 228 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 229 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 230 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 231 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 232 "data/maps/LakeOfRage/scripts.pory"
	walk_down
# 233 "data/maps/LakeOfRage/scripts.pory"
	step_end
# 234 "data/maps/LakeOfRage/scripts.pory"

# 235 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Dragonite:
# 236 "data/maps/LakeOfRage/scripts.pory"
	.string "Dragonite: Gyafooha!$"
# 237 "data/maps/LakeOfRage/scripts.pory"

# 238 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceForcedToEvolve:
# 239 "data/maps/LakeOfRage/scripts.pory"
    .string "This lake is full of Gyarados\n"
# 240 "data/maps/LakeOfRage/scripts.pory"
    .string "but nothing else…\p"
# 241 "data/maps/LakeOfRage/scripts.pory"
    .string "So the Magikarp are being forced\n"
# 242 "data/maps/LakeOfRage/scripts.pory"
    .string "to evolve…$"
# 243 "data/maps/LakeOfRage/scripts.pory"

# 244 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro1:
# 245 "data/maps/LakeOfRage/scripts.pory"
    .string "Did you come here because of\n"
# 246 "data/maps/LakeOfRage/scripts.pory"
    .string "the rumors?\p"
# 247 "data/maps/LakeOfRage/scripts.pory"
    .string "You're {PLAYER}? I'm Lance, a\n"
# 248 "data/maps/LakeOfRage/scripts.pory"
    .string "trainer like you.$"
# 249 "data/maps/LakeOfRage/scripts.pory"

# 250 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro2:
# 251 "data/maps/LakeOfRage/scripts.pory"
    .string "This man here informed me of\n"
# 252 "data/maps/LakeOfRage/scripts.pory"
    .string "some rumors.\p"
# 253 "data/maps/LakeOfRage/scripts.pory"
    .string "So we came to investigate…$"
# 254 "data/maps/LakeOfRage/scripts.pory"

# 255 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceIntro3:
# 256 "data/maps/LakeOfRage/scripts.pory"
    .string "I saw the way you battled\n"
# 257 "data/maps/LakeOfRage/scripts.pory"
    .string "earlier, {PLAYER}.\p"
# 258 "data/maps/LakeOfRage/scripts.pory"
    .string "I can tell that you're a trainer\n"
# 259 "data/maps/LakeOfRage/scripts.pory"
    .string "with considerable skill.\p"
# 260 "data/maps/LakeOfRage/scripts.pory"
    .string "If you don't mind, could you help\n"
# 261 "data/maps/LakeOfRage/scripts.pory"
    .string "us investigate?$"
# 262 "data/maps/LakeOfRage/scripts.pory"

# 263 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceRadioSignal:
# 264 "data/maps/LakeOfRage/scripts.pory"
    .string "Lance: Excellent!\p"
# 265 "data/maps/LakeOfRage/scripts.pory"
    .string "It seems that the Lake's Magikarp\n"
# 266 "data/maps/LakeOfRage/scripts.pory"
    .string "are being forced to evolve.\p"
# 267 "data/maps/LakeOfRage/scripts.pory"
    .string "A mysterious radio broadcast\n"
# 268 "data/maps/LakeOfRage/scripts.pory"
    .string "coming from Mahogany is the cause.\p"
# 269 "data/maps/LakeOfRage/scripts.pory"
    .string "We'll be waiting for you,\n"
# 270 "data/maps/LakeOfRage/scripts.pory"
    .string "{PLAYER}.$"
# 271 "data/maps/LakeOfRage/scripts.pory"

# 272 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceRefused:
# 273 "data/maps/LakeOfRage/scripts.pory"
    .string "Oh… Well, if you change your mind,\n"
# 274 "data/maps/LakeOfRage/scripts.pory"
    .string "please help us.$"
# 275 "data/maps/LakeOfRage/scripts.pory"

# 276 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_LanceAskHelp:
# 277 "data/maps/LakeOfRage/scripts.pory"
    .string "Lance: Hm? Are you going to help\n"
# 278 "data/maps/LakeOfRage/scripts.pory"
    .string "us?$"
# 279 "data/maps/LakeOfRage/scripts.pory"

# 280 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_GyaradosCry:
# 281 "data/maps/LakeOfRage/scripts.pory"
    .string "Gyarados: Gyashaa!$"
# 282 "data/maps/LakeOfRage/scripts.pory"

# 283 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Gramps:
# 284 "data/maps/LakeOfRage/scripts.pory"
    .string "The Gyarados are angry!\p"
# 285 "data/maps/LakeOfRage/scripts.pory"
    .string "It's a bad omen!$"
# 286 "data/maps/LakeOfRage/scripts.pory"

# 287 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_GrampsCleared:
# 288 "data/maps/LakeOfRage/scripts.pory"
    .string "Hahah! The Magikarp are biting!$"
# 289 "data/maps/LakeOfRage/scripts.pory"

# 290 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_SuperNerd:
# 291 "data/maps/LakeOfRage/scripts.pory"
    .string "I heard this lake was made by\n"
# 292 "data/maps/LakeOfRage/scripts.pory"
    .string "rampaging Gyarados.\p"
# 293 "data/maps/LakeOfRage/scripts.pory"
    .string "I wonder if there is any\n"
# 294 "data/maps/LakeOfRage/scripts.pory"
    .string "connection to their mass outbreak\l"
# 295 "data/maps/LakeOfRage/scripts.pory"
    .string "now?$"
# 296 "data/maps/LakeOfRage/scripts.pory"

# 297 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerF:
# 298 "data/maps/LakeOfRage/scripts.pory"
    .string "Did my eyes deceive me? I saw a\n"
# 299 "data/maps/LakeOfRage/scripts.pory"
    .string "red Gyarados in the Lake…\p"
# 300 "data/maps/LakeOfRage/scripts.pory"
    .string "But I thought Gyarados were\n"
# 301 "data/maps/LakeOfRage/scripts.pory"
    .string "usually blue?$"
# 302 "data/maps/LakeOfRage/scripts.pory"

# 303 "data/maps/LakeOfRage/scripts.pory"

# 304 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreSeen:
# 305 "data/maps/LakeOfRage/scripts.pory"
    .string "Let me battle with the Pokémon I\n"
# 306 "data/maps/LakeOfRage/scripts.pory"
    .string "just caught!$"
# 307 "data/maps/LakeOfRage/scripts.pory"

# 308 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreBeaten:
# 309 "data/maps/LakeOfRage/scripts.pory"
    .string "I might be an expert angler, but\n"
# 310 "data/maps/LakeOfRage/scripts.pory"
    .string "I stink as a Pokémon trainer…$"
# 311 "data/maps/LakeOfRage/scripts.pory"

# 312 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherAndreAfter:
# 313 "data/maps/LakeOfRage/scripts.pory"
    .string "I won't lose as an angler! I catch\n"
# 314 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon all day.$"
# 315 "data/maps/LakeOfRage/scripts.pory"

# 316 "data/maps/LakeOfRage/scripts.pory"

# 317 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondSeen:
# 318 "data/maps/LakeOfRage/scripts.pory"
    .string "No matter what I do, all I catch\n"
# 319 "data/maps/LakeOfRage/scripts.pory"
    .string "are the same Pokémon…$"
# 320 "data/maps/LakeOfRage/scripts.pory"

# 321 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondBeaten:
# 322 "data/maps/LakeOfRage/scripts.pory"
    .string "My line's all tangled up…$"
# 323 "data/maps/LakeOfRage/scripts.pory"

# 324 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FisherRaymondAfter:
# 325 "data/maps/LakeOfRage/scripts.pory"
    .string "Why can't I catch any good\n"
# 326 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon?$"
# 327 "data/maps/LakeOfRage/scripts.pory"

# 328 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronSeen:
# 329 "data/maps/LakeOfRage/scripts.pory"
    .string "If a trainer spots another trainer,\n"
# 330 "data/maps/LakeOfRage/scripts.pory"
    .string "he has to make a challenge.\p"
# 331 "data/maps/LakeOfRage/scripts.pory"
    .string "That is our destiny.$"
# 332 "data/maps/LakeOfRage/scripts.pory"

# 333 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronBeaten:
# 334 "data/maps/LakeOfRage/scripts.pory"
    .string "Whew… Good battle.$"
# 335 "data/maps/LakeOfRage/scripts.pory"

# 336 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainermAaronAfter:
# 337 "data/maps/LakeOfRage/scripts.pory"
    .string "Pokémon and their trainer become\n"
# 338 "data/maps/LakeOfRage/scripts.pory"
    .string "powerful through constant battling.$"
# 339 "data/maps/LakeOfRage/scripts.pory"

# 340 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisSeen:
# 341 "data/maps/LakeOfRage/scripts.pory"
    .string "What happened to the red\n"
# 342 "data/maps/LakeOfRage/scripts.pory"
    .string "Gyarados?\p"
# 343 "data/maps/LakeOfRage/scripts.pory"
    .string "It's gone?\p"
# 344 "data/maps/LakeOfRage/scripts.pory"
    .string "Oh, darn. I came here for\n"
# 345 "data/maps/LakeOfRage/scripts.pory"
    .string "nothing?\p"
# 346 "data/maps/LakeOfRage/scripts.pory"
    .string "I know--let's battle!$"
# 347 "data/maps/LakeOfRage/scripts.pory"

# 348 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisBeaten:
# 349 "data/maps/LakeOfRage/scripts.pory"
    .string "Good going!$"
# 350 "data/maps/LakeOfRage/scripts.pory"

# 351 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_CooltrainerfLoisAfter:
# 352 "data/maps/LakeOfRage/scripts.pory"
    .string "Come to think of it, I've seen a\n"
# 353 "data/maps/LakeOfRage/scripts.pory"
    .string "pink Butterfree.$"
# 354 "data/maps/LakeOfRage/scripts.pory"

# 355 "data/maps/LakeOfRage/scripts.pory"

# 356 "data/maps/LakeOfRage/scripts.pory"

# 357 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Wesley::
# 358 "data/maps/LakeOfRage/scripts.pory"
	lock
# 359 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 360 "data/maps/LakeOfRage/scripts.pory"
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
# 361 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
# 362 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 363 "data/maps/LakeOfRage/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 364 "data/maps/LakeOfRage/scripts.pory"
	switch VAR_RESULT
# 365 "data/maps/LakeOfRage/scripts.pory"
	case 0, LakeOfRage_EventScript_WesleyNope
# 366 "data/maps/LakeOfRage/scripts.pory"
	case 1, LakeOfRage_EventScript_WesleyNope
# 367 "data/maps/LakeOfRage/scripts.pory"
	case 2, LakeOfRage_EventScript_WesleyNope
# 368 "data/maps/LakeOfRage/scripts.pory"
	case 3, LakeOfRage_EventScript_WesleyYes
# 369 "data/maps/LakeOfRage/scripts.pory"
	case 4, LakeOfRage_EventScript_WesleyNope
# 370 "data/maps/LakeOfRage/scripts.pory"
	case 5, LakeOfRage_EventScript_WesleyNope
# 371 "data/maps/LakeOfRage/scripts.pory"
	case 6, LakeOfRage_EventScript_WesleyNope
# 372 "data/maps/LakeOfRage/scripts.pory"
	case 7 LakeOfRage_EventScript_WesleyCancel
# 373 "data/maps/LakeOfRage/scripts.pory"
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
# 374 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 375 "data/maps/LakeOfRage/scripts.pory"
	release
# 376 "data/maps/LakeOfRage/scripts.pory"
	end
# 377 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyYes::
# 378 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
# 379 "data/maps/LakeOfRage/scripts.pory"
	giveitem ITEM_BLACK_BELT
# 380 "data/maps/LakeOfRage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 381 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_GOT_BLACK_BELT
# 382 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
# 383 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 384 "data/maps/LakeOfRage/scripts.pory"
	release
# 385 "data/maps/LakeOfRage/scripts.pory"
	end
# 386 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyNope::
# 387 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
# 388 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 389 "data/maps/LakeOfRage/scripts.pory"
	release
# 390 "data/maps/LakeOfRage/scripts.pory"
	end
# 391 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyCancel::
# 392 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 393 "data/maps/LakeOfRage/scripts.pory"
	release
# 394 "data/maps/LakeOfRage/scripts.pory"
	end
# 395 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_WesleyCompleted::
# 396 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
# 397 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 398 "data/maps/LakeOfRage/scripts.pory"
	release
# 399 "data/maps/LakeOfRage/scripts.pory"
	end
# 400 "data/maps/LakeOfRage/scripts.pory"

# 401 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_MeetWesley:
# 402 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Well, how do you do?\p"
# 403 "data/maps/LakeOfRage/scripts.pory"
    .string "I'm a member of the Weekday family!\n"
# 404 "data/maps/LakeOfRage/scripts.pory"
	.string "Can you guess my favorite day?$"
# 405 "data/maps/LakeOfRage/scripts.pory"

# 406 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyGivesGift:
# 407 "data/maps/LakeOfRage/scripts.pory"
    .string "Pleased to meet you. Please take a\n"
# 408 "data/maps/LakeOfRage/scripts.pory"
    .string "souvenir.$"
# 409 "data/maps/LakeOfRage/scripts.pory"

# 410 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyGaveGift:
# 411 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Blackbelt beefs up the\n"
# 412 "data/maps/LakeOfRage/scripts.pory"
    .string "power of fighting moves.$"
# 413 "data/maps/LakeOfRage/scripts.pory"

# 414 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyWednesday:
# 415 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Since you found me, you\n"
# 416 "data/maps/LakeOfRage/scripts.pory"
    .string "must have met my brothers and\l"
# 417 "data/maps/LakeOfRage/scripts.pory"
    .string "sisters.\p"
# 418 "data/maps/LakeOfRage/scripts.pory"
    .string "Or did you just get lucky?$"
# 419 "data/maps/LakeOfRage/scripts.pory"

# 420 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_WesleyNotWednesday:
# 421 "data/maps/LakeOfRage/scripts.pory"
    .string "Wesley: Not exactly...$"
# 422 "data/maps/LakeOfRage/scripts.pory"

# 423 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Sign1::
# 424 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
# 425 "data/maps/LakeOfRage/scripts.pory"
	end
# 426 "data/maps/LakeOfRage/scripts.pory"

# 427 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_EventScript_Sign2::
# 428 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
# 429 "data/maps/LakeOfRage/scripts.pory"
	end
# 430 "data/maps/LakeOfRage/scripts.pory"

# 431 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_Sign:
# 432 "data/maps/LakeOfRage/scripts.pory"
    .string "Lake Of Rage,\n"
# 433 "data/maps/LakeOfRage/scripts.pory"
    .string "also known as Gyarados Lake.$"
# 434 "data/maps/LakeOfRage/scripts.pory"

# 435 "data/maps/LakeOfRage/scripts.pory"
LakeOfRage_Text_FishingGuruSign:
# 436 "data/maps/LakeOfRage/scripts.pory"
    .string "Fishing Guru's House$"

Lakeofrage_HiddenGrotto::
# 440 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_HiddenGrotto_Text_0, MSGBOX_YESNO
# 442 "data/maps/LakeOfRage/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lakeofrage_HiddenGrotto_2
Lakeofrage_HiddenGrotto_1:
# 446 "data/maps/LakeOfRage/scripts.pory"
	release
	end

Lakeofrage_HiddenGrotto_2:
# 443 "data/maps/LakeOfRage/scripts.pory"
	warp MAP_HIDDEN_GROTTO_LAKEOFRAGE, 0
# 444 "data/maps/LakeOfRage/scripts.pory"
	waitstate
	goto Lakeofrage_HiddenGrotto_1


Lakeofrage_PryceRematch::
# 451 "data/maps/LakeOfRage/scripts.pory"
	lock
# 452 "data/maps/LakeOfRage/scripts.pory"
	faceplayer
# 453 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_0
# 460 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_1, MSGBOX_YESNO
# 463 "data/maps/LakeOfRage/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lakeofrage_PryceRematch_2
Lakeofrage_PryceRematch_1:
# 483 "data/maps/LakeOfRage/scripts.pory"
	release
	end

Lakeofrage_PryceRematch_2:
# 464 "data/maps/LakeOfRage/scripts.pory"
	trainerbattle_no_intro TRAINER_PRYCE_2, Lakeofrage_PryceRematch_Text_2
# 465 "data/maps/LakeOfRage/scripts.pory"
	msgbox Lakeofrage_PryceRematch_Text_3
# 476 "data/maps/LakeOfRage/scripts.pory"
	closemessage
# 477 "data/maps/LakeOfRage/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 478 "data/maps/LakeOfRage/scripts.pory"
	setflag FLAG_HIDE_LAKE_PRYCE
# 479 "data/maps/LakeOfRage/scripts.pory"
	removeobject LOCALID_PRYCE_REMATCH
# 480 "data/maps/LakeOfRage/scripts.pory"
	delay 30
# 481 "data/maps/LakeOfRage/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Lakeofrage_PryceRematch_1


LakeOfRagePostgamePoliceman::
# 488 "data/maps/LakeOfRage/scripts.pory"
	msgbox LakeOfRagePostgamePoliceman_Text_0, MSGBOX_NPC
	return


Lakeofrage_HiddenGrotto_Text_0:
# 440 "data/maps/LakeOfRage/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Lakeofrage_PryceRematch_Text_0:
# 453 "data/maps/LakeOfRage/scripts.pory"
	.string "{PLAYER}, the cold of Indigo Plateau\n"
	.string "has not worn you down I see.\p"
	.string "Personally I prefer the cold, it keeps\n"
	.string "my senses sharp. Warmth can make one\l"
	.string "drop their guard.$"

Lakeofrage_PryceRematch_Text_1:
# 460 "data/maps/LakeOfRage/scripts.pory"
	.string "How about I show you what I mean\n"
	.string "in a battle. I won't be holding\l"
	.string "back this time.$"

Lakeofrage_PryceRematch_Text_2:
# 464 "data/maps/LakeOfRage/scripts.pory"
	.string "Reminds me of the old days.$"

Lakeofrage_PryceRematch_Text_3:
# 465 "data/maps/LakeOfRage/scripts.pory"
	.string "I worry less for the future generations\n"
	.string "when I see trainers like you rise up.\p"
	.string "I hope you will foster the growth\n"
	.string "of future generations in your own\l"
	.string "time, too.\p"
	.string "I believe I still have more I can\n"
	.string "show you another time, but I must\l"
	.string "return to my training in order\l"
	.string "to achieve it.$"

LakeOfRagePostgamePoliceman_Text_0:
# 488 "data/maps/LakeOfRage/scripts.pory"
	.string "The road has been blocked by a\n"
	.string "landslide, we're working on clearing\l"
	.string "it up, so please have patience.$"
