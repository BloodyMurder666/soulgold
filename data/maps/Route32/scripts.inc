# 1 "data/maps/Route32/scripts.pory"

# 2 "data/maps/Route32/scripts.pory"

# 3 "data/maps/Route32/scripts.pory"

# 4 "data/maps/Route32/scripts.pory"
Route32_MapScripts::
# 5 "data/maps/Route32/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
# 6 "data/maps/Route32/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 7 "data/maps/Route32/scripts.pory"
	.byte 0
# 8 "data/maps/Route32/scripts.pory"

# 9 "data/maps/Route32/scripts.pory"
Route32_OnTransition: 
# 10 "data/maps/Route32/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/Route32/scripts.pory"
	callnative SetTimeBasedEncounters
# 12 "data/maps/Route32/scripts.pory"
	end
# 13 "data/maps/Route32/scripts.pory"

# 14 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherJustin::
# 15 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_JUSTIN Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
# 16 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route32/scripts.pory"
	end
# 18 "data/maps/Route32/scripts.pory"

# 19 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherRalph::
# 20 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_RALPH Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten
# 21 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
# 22 "data/maps/Route32/scripts.pory"
	end
# 23 "data/maps/Route32/scripts.pory"

# 24 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherHenry::
# 25 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_HENRY Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
# 26 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
# 27 "data/maps/Route32/scripts.pory"
	end
# 28 "data/maps/Route32/scripts.pory"

# 29 "data/maps/Route32/scripts.pory"
Route32_EventScript_YoungsterAlbert::
# 30 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_ALBERT Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
# 31 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route32/scripts.pory"
	end
# 33 "data/maps/Route32/scripts.pory"

# 34 "data/maps/Route32/scripts.pory"
Route32_EventScript_YoungsterGordon::
# 35 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_GORDON Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
# 36 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route32/scripts.pory"
	end
# 38 "data/maps/Route32/scripts.pory"

# 39 "data/maps/Route32/scripts.pory"
Route32_EventScript_CamperRoland::
# 40 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_ROLAND Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
# 41 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route32/scripts.pory"
	end
# 43 "data/maps/Route32/scripts.pory"

# 44 "data/maps/Route32/scripts.pory"
Route32_EventScript_PicnickerLiz::
# 45 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_LIZ Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten
# 46 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route32/scripts.pory"
	end
# 48 "data/maps/Route32/scripts.pory"

# 49 "data/maps/Route32/scripts.pory"
Route32_EventScript_BirdkeeperPeter::
# 50 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_PETER Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
# 51 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route32/scripts.pory"
	end
# 53 "data/maps/Route32/scripts.pory"

# 54 "data/maps/Route32/scripts.pory"
Route32_EventScript_Roar::
# 55 "data/maps/Route32/scripts.pory"
	lock
# 56 "data/maps/Route32/scripts.pory"
	faceplayer
# 57 "data/maps/Route32/scripts.pory"
	checkitem ITEM_TM_ROAR
# 58 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route32_EventScript_Roar2
# 59 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
# 60 "data/maps/Route32/scripts.pory"
	giveitem ITEM_TM_ROAR
# 61 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
# 62 "data/maps/Route32/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROAR
# 63 "data/maps/Route32/scripts.pory"
	closemessage
# 64 "data/maps/Route32/scripts.pory"
	release
# 65 "data/maps/Route32/scripts.pory"
	end
# 66 "data/maps/Route32/scripts.pory"
Route32_EventScript_Roar2::
# 67 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
# 68 "data/maps/Route32/scripts.pory"
	closemessage
# 69 "data/maps/Route32/scripts.pory"
	release
# 70 "data/maps/Route32/scripts.pory"
	end
# 71 "data/maps/Route32/scripts.pory"

# 72 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerLeft::
# 73 "data/maps/Route32/scripts.pory"
	lock
# 74 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 75 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 76 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 77 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 78 "data/maps/Route32/scripts.pory"
	delay 60
# 79 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
# 80 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 82 "data/maps/Route32/scripts.pory"

# 83 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerMid::
# 84 "data/maps/Route32/scripts.pory"
	lock
# 85 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 86 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 87 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 88 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 89 "data/maps/Route32/scripts.pory"
	delay 60
# 90 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
# 91 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 92 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 93 "data/maps/Route32/scripts.pory"

# 94 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerRight::
# 95 "data/maps/Route32/scripts.pory"
	lock
# 96 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 97 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 98 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 99 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 100 "data/maps/Route32/scripts.pory"
	delay 60
# 101 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
# 102 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 103 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 104 "data/maps/Route32/scripts.pory"

# 105 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger::
# 106 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 107 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
# 108 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 109 "data/maps/Route32/scripts.pory"
	closemessage
# 110 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 111 "data/maps/Route32/scripts.pory"
	release
# 112 "data/maps/Route32/scripts.pory"
	end	
# 113 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger2::
# 114 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 115 "data/maps/Route32/scripts.pory"
	closemessage
# 116 "data/maps/Route32/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 117 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
# 118 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
# 119 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 120 "data/maps/Route32/scripts.pory"
	release
# 121 "data/maps/Route32/scripts.pory"
	end
# 122 "data/maps/Route32/scripts.pory"

# 123 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Left::
# 124 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 125 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 126 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 127 "data/maps/Route32/scripts.pory"
	return 
# 128 "data/maps/Route32/scripts.pory"

# 129 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Right::
# 130 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 131 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 132 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 133 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 134 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 135 "data/maps/Route32/scripts.pory"
	return 	
# 136 "data/maps/Route32/scripts.pory"

# 137 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail::
# 138 "data/maps/Route32/scripts.pory"
	lock
# 139 "data/maps/Route32/scripts.pory"
	faceplayer
# 140 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 141 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
# 142 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 143 "data/maps/Route32/scripts.pory"
	closemessage
# 144 "data/maps/Route32/scripts.pory"
	release
# 145 "data/maps/Route32/scripts.pory"
	end
# 146 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail2::
# 147 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 148 "data/maps/Route32/scripts.pory"
	closemessage
# 149 "data/maps/Route32/scripts.pory"
	release
# 150 "data/maps/Route32/scripts.pory"
	end
# 151 "data/maps/Route32/scripts.pory"

# 152 "data/maps/Route32/scripts.pory"

# 153 "data/maps/Route32/scripts.pory"
Route32_EventScript_Frieda::
# 154 "data/maps/Route32/scripts.pory"
	lock
# 155 "data/maps/Route32/scripts.pory"
	faceplayer
# 156 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
# 157 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
# 158 "data/maps/Route32/scripts.pory"
	closemessage
# 159 "data/maps/Route32/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 160 "data/maps/Route32/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/Route32/scripts.pory"
	case 0, Route32_EventScript_FriedaNope
# 162 "data/maps/Route32/scripts.pory"
	case 1, Route32_EventScript_FriedaNope
# 163 "data/maps/Route32/scripts.pory"
	case 2, Route32_EventScript_FriedaNope
# 164 "data/maps/Route32/scripts.pory"
	case 3, Route32_EventScript_FriedaNope
# 165 "data/maps/Route32/scripts.pory"
	case 4, Route32_EventScript_FriedaNope
# 166 "data/maps/Route32/scripts.pory"
	case 5, Route32_EventScript_FriedaYes
# 167 "data/maps/Route32/scripts.pory"
	case 6, Route32_EventScript_FriedaNope
# 168 "data/maps/Route32/scripts.pory"
	case 7, Route32_EventScript_FriedaCancel
# 169 "data/maps/Route32/scripts.pory"
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
# 170 "data/maps/Route32/scripts.pory"
	closemessage
# 171 "data/maps/Route32/scripts.pory"
	release
# 172 "data/maps/Route32/scripts.pory"
	end
# 173 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaYes::
# 174 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
# 175 "data/maps/Route32/scripts.pory"
	giveitem ITEM_POISON_BARB
# 176 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 177 "data/maps/Route32/scripts.pory"
	setflag FLAG_GOT_POISON_BARB
# 178 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
# 179 "data/maps/Route32/scripts.pory"
	closemessage
# 180 "data/maps/Route32/scripts.pory"
	release
# 181 "data/maps/Route32/scripts.pory"
	end
# 182 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaNope::
# 183 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
# 184 "data/maps/Route32/scripts.pory"
	closemessage
# 185 "data/maps/Route32/scripts.pory"
	release
# 186 "data/maps/Route32/scripts.pory"
	end
# 187 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCancel::
# 188 "data/maps/Route32/scripts.pory"
	closemessage
# 189 "data/maps/Route32/scripts.pory"
	release
# 190 "data/maps/Route32/scripts.pory"
	end
# 191 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCompleted::
# 192 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
# 193 "data/maps/Route32/scripts.pory"
	closemessage
# 194 "data/maps/Route32/scripts.pory"
	release
# 195 "data/maps/Route32/scripts.pory"
	end
# 196 "data/maps/Route32/scripts.pory"

# 197 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingMan::
# 198 "data/maps/Route32/scripts.pory"
	lock
# 199 "data/maps/Route32/scripts.pory"
	faceplayer
# 200 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
# 201 "data/maps/Route32/scripts.pory"
	closemessage
# 202 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
# 203 "data/maps/Route32/scripts.pory"
	release
# 204 "data/maps/Route32/scripts.pory"
	end
# 205 "data/maps/Route32/scripts.pory"

# 206 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerLeft::
# 207 "data/maps/Route32/scripts.pory"
	lock
# 208 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 209 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 210 "data/maps/Route32/scripts.pory"
	delay 60
# 211 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 212 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 213 "data/maps/Route32/scripts.pory"
	end
# 214 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerMid::
# 215 "data/maps/Route32/scripts.pory"
	lock
# 216 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 217 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 218 "data/maps/Route32/scripts.pory"
	delay 60
# 219 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
# 220 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 221 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 222 "data/maps/Route32/scripts.pory"
	end
# 223 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerRight::
# 224 "data/maps/Route32/scripts.pory"
	lock
# 225 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 226 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 227 "data/maps/Route32/scripts.pory"
	delay 60
# 228 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
# 229 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 231 "data/maps/Route32/scripts.pory"
	end
# 232 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManCheck::
# 233 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
# 234 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
# 235 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
# 236 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
# 237 "data/maps/Route32/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 238 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 239 "data/maps/Route32/scripts.pory"
	closemessage
# 240 "data/maps/Route32/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 5
# 241 "data/maps/Route32/scripts.pory"
	release
# 242 "data/maps/Route32/scripts.pory"
	end
# 243 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTower::
# 244 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 245 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
# 246 "data/maps/Route32/scripts.pory"
	closemessage
# 247 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 248 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 249 "data/maps/Route32/scripts.pory"
	release
# 250 "data/maps/Route32/scripts.pory"
	end
# 251 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManGym::
# 252 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 253 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
# 254 "data/maps/Route32/scripts.pory"
	closemessage
# 255 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 256 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 257 "data/maps/Route32/scripts.pory"
	release
# 258 "data/maps/Route32/scripts.pory"
	end
# 259 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManEgg::
# 260 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 261 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
# 262 "data/maps/Route32/scripts.pory"
	closemessage
# 263 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 264 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 265 "data/maps/Route32/scripts.pory"
	release
# 266 "data/maps/Route32/scripts.pory"
	end
# 267 "data/maps/Route32/scripts.pory"

# 268 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign1::
# 269 "data/maps/Route32/scripts.pory"
	lock
# 270 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
# 271 "data/maps/Route32/scripts.pory"
	closemessage
# 272 "data/maps/Route32/scripts.pory"
	release
# 273 "data/maps/Route32/scripts.pory"
	end
# 274 "data/maps/Route32/scripts.pory"

# 275 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign2::
# 276 "data/maps/Route32/scripts.pory"
	lock
# 277 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
# 278 "data/maps/Route32/scripts.pory"
	closemessage
# 279 "data/maps/Route32/scripts.pory"
	release
# 280 "data/maps/Route32/scripts.pory"
	end
# 281 "data/maps/Route32/scripts.pory"

# 282 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign3::
# 283 "data/maps/Route32/scripts.pory"
	lock
# 284 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
# 285 "data/maps/Route32/scripts.pory"
	closemessage
# 286 "data/maps/Route32/scripts.pory"
	release
# 287 "data/maps/Route32/scripts.pory"
	end
# 288 "data/maps/Route32/scripts.pory"

# 289 "data/maps/Route32/scripts.pory"
Route32_Movement_Turnback:
# 290 "data/maps/Route32/scripts.pory"
	walk_up
# 291 "data/maps/Route32/scripts.pory"
	step_end
# 292 "data/maps/Route32/scripts.pory"

# 293 "data/maps/Route32/scripts.pory"
Route32_Movement_StartMid:
# 294 "data/maps/Route32/scripts.pory"
	walk_left
# 295 "data/maps/Route32/scripts.pory"
	step_end
# 296 "data/maps/Route32/scripts.pory"

# 297 "data/maps/Route32/scripts.pory"
Route32_Movment_StartRight:
# 298 "data/maps/Route32/scripts.pory"
	walk_left
# 299 "data/maps/Route32/scripts.pory"
	walk_left
# 300 "data/maps/Route32/scripts.pory"
	step_end
# 301 "data/maps/Route32/scripts.pory"

# 302 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeLeft::
# 303 "data/maps/Route32/scripts.pory"
	step_end
# 304 "data/maps/Route32/scripts.pory"

# 305 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeMid::
# 306 "data/maps/Route32/scripts.pory"
	walk_right
# 307 "data/maps/Route32/scripts.pory"
	step_end
# 308 "data/maps/Route32/scripts.pory"

# 309 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeRight::
# 310 "data/maps/Route32/scripts.pory"
	walk_right
# 311 "data/maps/Route32/scripts.pory"
	walk_right
# 312 "data/maps/Route32/scripts.pory"
	step_end
# 313 "data/maps/Route32/scripts.pory"

# 314 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_WhatsTheHurry:
# 315 "data/maps/Route32/scripts.pory"
	.string "Wait up!\n"
# 316 "data/maps/Route32/scripts.pory"
	.string "What's the hurry?$"
# 317 "data/maps/Route32/scripts.pory"

# 318 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_AideIsWaiting:
# 319 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}, right?\n"
# 320 "data/maps/Route32/scripts.pory"
	.string "Some guy wearing glasses\p"
# 321 "data/maps/Route32/scripts.pory"
	.string "was looking for you.\p"
# 322 "data/maps/Route32/scripts.pory"
	.string "See for yourself. He's waiting for\n"
# 323 "data/maps/Route32/scripts.pory"
	.string "you at the Pokémon Center.$"
# 324 "data/maps/Route32/scripts.pory"

# 325 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_SproutTower:
# 326 "data/maps/Route32/scripts.pory"
	.string "Have you gone to Sprout Tower?\n"
# 327 "data/maps/Route32/scripts.pory"
	.string "If you ever visit Violet City,\p"
# 328 "data/maps/Route32/scripts.pory"
	.string "they'll expect you to train there.\n"
# 329 "data/maps/Route32/scripts.pory"
	.string "That's basic for trainers.\p"
# 330 "data/maps/Route32/scripts.pory"
	.string "Go to Sprout Tower!$"
# 331 "data/maps/Route32/scripts.pory"

# 332 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_VioletGym:
# 333 "data/maps/Route32/scripts.pory"
	.string "Have you gone to the Pokémon Gym?\n"
# 334 "data/maps/Route32/scripts.pory"
	.string "You can test your Pokémon and\p"
# 335 "data/maps/Route32/scripts.pory"
	.string "yourself there.\n"
# 336 "data/maps/Route32/scripts.pory"
	.string "It's a rite of passage for all\p"
# 337 "data/maps/Route32/scripts.pory"
	.string "trainers!$"
# 338 "data/maps/Route32/scripts.pory"

# 339 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_HaveThisSeed:
# 340 "data/maps/Route32/scripts.pory"
	.string "You have some good Pokémon there.\n"
# 341 "data/maps/Route32/scripts.pory"
	.string "It must be from the training you\p"
# 342 "data/maps/Route32/scripts.pory"
	.string "gave them around Violet City.\n"
# 343 "data/maps/Route32/scripts.pory"
	.string "The training at the Gym must have\p"
# 344 "data/maps/Route32/scripts.pory"
	.string "been especially helpful. As a\n"
# 345 "data/maps/Route32/scripts.pory"
	.string "souvenir of Violet City, take this.\p"
# 346 "data/maps/Route32/scripts.pory"
	.string "It increases the power of Grass-\n"
# 347 "data/maps/Route32/scripts.pory"
	.string "type moves.$"
# 348 "data/maps/Route32/scripts.pory"

# 349 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_Experiences:
# 350 "data/maps/Route32/scripts.pory"
	.string "Your experiences in Violet City\n"
# 351 "data/maps/Route32/scripts.pory"
	.string "should be useful for your journey.$"
# 352 "data/maps/Route32/scripts.pory"

# 353 "data/maps/Route32/scripts.pory"
Route32_Text_SlowpokeTailOffer:
# 354 "data/maps/Route32/scripts.pory"
	.string "How would you like to have this\n"
# 355 "data/maps/Route32/scripts.pory"
	.string "tasty, nutritious Slowpoke Tail?\p"
# 356 "data/maps/Route32/scripts.pory"
	.string "For you right now, just\n"
# 357 "data/maps/Route32/scripts.pory"
	.string "¥1,000,000!\p"
# 358 "data/maps/Route32/scripts.pory"
	.string "You'll want this!$"
# 359 "data/maps/Route32/scripts.pory"

# 360 "data/maps/Route32/scripts.pory"
Route32_Text_ThoughtKidsLoaded:
# 361 "data/maps/Route32/scripts.pory"
	.string "Tch! I thought kids\n"
# 362 "data/maps/Route32/scripts.pory"
	.string "these days were loaded…$"
# 363 "data/maps/Route32/scripts.pory"

# 364 "data/maps/Route32/scripts.pory"
Route32_Text_RefusedSlowpokeTail:
# 365 "data/maps/Route32/scripts.pory"
	.string "You don't want it?\n"
# 366 "data/maps/Route32/scripts.pory"
	.string "Then scram. Shoo!$"
# 367 "data/maps/Route32/scripts.pory"

# 368 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Seen:
# 369 "data/maps/Route32/scripts.pory"
	.string "Whoa!\p"
# 370 "data/maps/Route32/scripts.pory"
	.string "You made me lose that fish!$"
# 371 "data/maps/Route32/scripts.pory"

# 372 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Beaten:
# 373 "data/maps/Route32/scripts.pory"
	.string "Sploosh!$"
# 374 "data/maps/Route32/scripts.pory"

# 375 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_After:
# 376 "data/maps/Route32/scripts.pory"
	.string "Calm, collected… The essence of\n"
# 377 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon is the same.$"
# 378 "data/maps/Route32/scripts.pory"

# 379 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Seen:
# 380 "data/maps/Route32/scripts.pory"
	.string "I'm really good at both\n"
# 381 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon.\p"
# 382 "data/maps/Route32/scripts.pory"
	.string "I'm not about to lose to any kid!$"
# 383 "data/maps/Route32/scripts.pory"

# 384 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Beaten:
# 385 "data/maps/Route32/scripts.pory"
	.string "Tch! I tried to rush\n"
# 386 "data/maps/Route32/scripts.pory"
	.string "things…$"
# 387 "data/maps/Route32/scripts.pory"

# 388 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_After:
# 389 "data/maps/Route32/scripts.pory"
	.string "Fishing is a lifelong\n"
# 390 "data/maps/Route32/scripts.pory"
	.string "passion.\p"
# 391 "data/maps/Route32/scripts.pory"
	.string "Pokémon are lifelong friends!$"
# 392 "data/maps/Route32/scripts.pory"

# 393 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Seen:
# 394 "data/maps/Route32/scripts.pory"
	.string "My Pokémon? Freshly caught!$"
# 395 "data/maps/Route32/scripts.pory"

# 396 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Beaten:
# 397 "data/maps/Route32/scripts.pory"
	.string "Splash?$"
# 398 "data/maps/Route32/scripts.pory"

# 399 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_After:
# 400 "data/maps/Route32/scripts.pory"
	.string "Freshly caught Pokémon are\n"
# 401 "data/maps/Route32/scripts.pory"
	.string "no match for properly raised ones.$"
# 402 "data/maps/Route32/scripts.pory"

# 403 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Seen:
# 404 "data/maps/Route32/scripts.pory"
	.string "I haven't seen you around before.\n"
# 405 "data/maps/Route32/scripts.pory"
	.string "So you think you are pretty tough?$"
# 406 "data/maps/Route32/scripts.pory"

# 407 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Beaten:
# 408 "data/maps/Route32/scripts.pory"
	.string "You're strong!$"
# 409 "data/maps/Route32/scripts.pory"

# 410 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_After:
# 411 "data/maps/Route32/scripts.pory"
	.string "I'm going to try to be the\n"
# 412 "data/maps/Route32/scripts.pory"
	.string "best with my favorites.\p"
# 413 "data/maps/Route32/scripts.pory"
	.string "I'm not using the same tough\n"
# 414 "data/maps/Route32/scripts.pory"
	.string "Pokémon as everyone else.$"
# 415 "data/maps/Route32/scripts.pory"

# 416 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Seen:
# 417 "data/maps/Route32/scripts.pory"
	.string "I found some good Pokémon\n"
# 418 "data/maps/Route32/scripts.pory"
	.string "in the grass!\p"
# 419 "data/maps/Route32/scripts.pory"
	.string "I think they'll do it for me!$"
# 420 "data/maps/Route32/scripts.pory"

# 421 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Beaten:
# 422 "data/maps/Route32/scripts.pory"
	.string "Darn. I thought I could win.$"
# 423 "data/maps/Route32/scripts.pory"

# 424 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_After:
# 425 "data/maps/Route32/scripts.pory"
	.string "The grass is full of\n"
# 426 "data/maps/Route32/scripts.pory"
	.string "clingy things.$"
# 427 "data/maps/Route32/scripts.pory"

# 428 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Seen:
# 429 "data/maps/Route32/scripts.pory"
	.string "That glance… It's intriguing.$"
# 430 "data/maps/Route32/scripts.pory"

# 431 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Beaten:
# 432 "data/maps/Route32/scripts.pory"
	.string "Hmmm. This is disappointing.$"
# 433 "data/maps/Route32/scripts.pory"

# 434 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_After:
# 435 "data/maps/Route32/scripts.pory"
	.string "If you don't want to battle,\n"
# 436 "data/maps/Route32/scripts.pory"
	.string "just avoid eye contact.$"
# 437 "data/maps/Route32/scripts.pory"

# 438 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Seen:
# 439 "data/maps/Route32/scripts.pory"
	.string "Uh-huh. Yeah, and you know…\p"
# 440 "data/maps/Route32/scripts.pory"
	.string "Pardon? Battle? I'm on the phone.\n"
# 441 "data/maps/Route32/scripts.pory"
	.string "Oh, all right. But make it fast.$"
# 442 "data/maps/Route32/scripts.pory"

# 443 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Beaten:
# 444 "data/maps/Route32/scripts.pory"
	.string "Oh! I've got to relieve\n"
# 445 "data/maps/Route32/scripts.pory"
	.string "my anger!$"
# 446 "data/maps/Route32/scripts.pory"

# 447 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_After:
# 448 "data/maps/Route32/scripts.pory"
	.string "I was having a nice chat too.$"
# 449 "data/maps/Route32/scripts.pory"

# 450 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Seen:
# 451 "data/maps/Route32/scripts.pory"
	.string "That Badge! It's from Violet City!\n"
# 452 "data/maps/Route32/scripts.pory"
	.string "You beat Falkner?$"
# 453 "data/maps/Route32/scripts.pory"

# 454 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Beaten:
# 455 "data/maps/Route32/scripts.pory"
	.string "I know what my weaknesses are.$"
# 456 "data/maps/Route32/scripts.pory"

# 457 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_After:
# 458 "data/maps/Route32/scripts.pory"
	.string "I should train again at the\n"
# 459 "data/maps/Route32/scripts.pory"
	.string "Gym in Violet City.$"
# 460 "data/maps/Route32/scripts.pory"

# 461 "data/maps/Route32/scripts.pory"
Route32_Text_RoarIntro:
# 462 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! People Run When I\n"
# 463 "data/maps/Route32/scripts.pory"
	.string "Roar! But You Came Looking!\p"
# 464 "data/maps/Route32/scripts.pory"
	.string "That Pleases Me! Now Take This!$"
# 465 "data/maps/Route32/scripts.pory"

# 466 "data/maps/Route32/scripts.pory"
Route32_Text_RoarOutro:
# 467 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! It'S Roar!\p"
# 468 "data/maps/Route32/scripts.pory"
	.string "Even Pokémon Run From A Good\n"
# 469 "data/maps/Route32/scripts.pory"
	.string "Roar!$"
# 470 "data/maps/Route32/scripts.pory"

# 471 "data/maps/Route32/scripts.pory"
Route32_Text_MeetFrieda:
# 472 "data/maps/Route32/scripts.pory"
	.string "Frieda: Yahoo!\p"
# 473 "data/maps/Route32/scripts.pory"
	.string "I'm Frieda of the Weekday Family!\n"
# 474 "data/maps/Route32/scripts.pory"
	.string "Nice to meet you!\p"
# 475 "data/maps/Route32/scripts.pory"
	.string "If you can guess my favorite day,\n"
# 476 "data/maps/Route32/scripts.pory"
	.string "I'll give you a reward.$"
# 477 "data/maps/Route32/scripts.pory"

# 478 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGivesGift:
# 479 "data/maps/Route32/scripts.pory"
	.string "Here's a Poison Barb for you!$"
# 480 "data/maps/Route32/scripts.pory"

# 481 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGaveGift:
# 482 "data/maps/Route32/scripts.pory"
	.string "Frieda: Give it to a Pokémon\n"
# 483 "data/maps/Route32/scripts.pory"
	.string "that has Poison-type moves.\p"
# 484 "data/maps/Route32/scripts.pory"
	.string "Oh!\p"
# 485 "data/maps/Route32/scripts.pory"
	.string "It's wicked!\p"
# 486 "data/maps/Route32/scripts.pory"
	.string "You'll be shocked how good it\n"
# 487 "data/maps/Route32/scripts.pory"
	.string "makes poison moves!$"
# 488 "data/maps/Route32/scripts.pory"

# 489 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaFriday:
# 490 "data/maps/Route32/scripts.pory"
	.string "Frieda: Hiya! What day do\n"
# 491 "data/maps/Route32/scripts.pory"
	.string "you like?\p"
# 492 "data/maps/Route32/scripts.pory"
	.string "I love Friday. No doubt about\n"
# 493 "data/maps/Route32/scripts.pory"
	.string "it!\p"
# 494 "data/maps/Route32/scripts.pory"
	.string "Don't you think it's great too?$"
# 495 "data/maps/Route32/scripts.pory"

# 496 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaNope:
# 497 "data/maps/Route32/scripts.pory"
	.string "Frieda: Not that one!$"
# 498 "data/maps/Route32/scripts.pory"

# 499 "data/maps/Route32/scripts.pory"
Route32_Text_Sign1:
# 500 "data/maps/Route32/scripts.pory"
	.string "Route 32\p"
# 501 "data/maps/Route32/scripts.pory"
	.string "Violet City - Azalea Town$"
# 502 "data/maps/Route32/scripts.pory"

# 503 "data/maps/Route32/scripts.pory"
Route32_Text_Sign2:
# 504 "data/maps/Route32/scripts.pory"
	.string "Ruins Of Alph\n"
# 505 "data/maps/Route32/scripts.pory"
	.string "East Entrance$"
# 506 "data/maps/Route32/scripts.pory"

# 507 "data/maps/Route32/scripts.pory"
Route32_Text_Sign3:
# 508 "data/maps/Route32/scripts.pory"
	.string "Union Cave\n"
# 509 "data/maps/Route32/scripts.pory"
	.string "Ahead$"

Route32HiddenGrottoWarp::
# 513 "data/maps/Route32/scripts.pory"
	lock
# 514 "data/maps/Route32/scripts.pory"
	msgbox Route32HiddenGrottoWarp_Text_0, MSGBOX_YESNO
# 516 "data/maps/Route32/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route32HiddenGrottoWarp_2
Route32HiddenGrottoWarp_1:
# 520 "data/maps/Route32/scripts.pory"
	release
	end

Route32HiddenGrottoWarp_2:
# 517 "data/maps/Route32/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE32, 0
# 518 "data/maps/Route32/scripts.pory"
	waitstate
	goto Route32HiddenGrottoWarp_1


Route32RivalGrottoTutorial::
# 525 "data/maps/Route32/scripts.pory"
	lock
# 526 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_0
# 528 "data/maps/Route32/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 529 "data/maps/Route32/scripts.pory"
	closemessage
# 530 "data/maps/Route32/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 25, 25, DIR_SOUTH
# 531 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_0
# 532 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_1
# 533 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 534 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 535 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 536 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 537 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 538 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 539 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 540 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_1
# 541 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_2
# 544 "data/maps/Route32/scripts.pory"
	closemessage
# 545 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_3
# 546 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_4
# 547 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_PLAYER, Route32RivalGrottoTutorial_Movement_5
# 548 "data/maps/Route32/scripts.pory"
	waitmovement LOCALID_ROUTE32_MARILL
# 549 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_3
# 562 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_4
# 566 "data/maps/Route32/scripts.pory"
	closemessage
# 567 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_6
# 568 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_7
# 569 "data/maps/Route32/scripts.pory"
	waitmovement
# 570 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_8
# 571 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_9
# 572 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 573 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 574 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 575 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 576 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 577 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 578 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 579 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_10
# 580 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 581 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_RIVAL
# 582 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_MARILL
# 583 "data/maps/Route32/scripts.pory"
	setflag FLAG_HIDE_ROUTE32_RIVAL
# 584 "data/maps/Route32/scripts.pory"
	setvar VAR_RIVAL_STATE, 5
# 585 "data/maps/Route32/scripts.pory"
	fadedefaultbgm
# 586 "data/maps/Route32/scripts.pory"
	release
	end


# 531 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_0:
# 531 "data/maps/Route32/scripts.pory"
	walk_up
# 531 "data/maps/Route32/scripts.pory"
	walk_up
# 531 "data/maps/Route32/scripts.pory"
	walk_up
# 531 "data/maps/Route32/scripts.pory"
	walk_up
# 531 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 532 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_1:
# 532 "data/maps/Route32/scripts.pory"
	walk_up
# 532 "data/maps/Route32/scripts.pory"
	walk_up
# 532 "data/maps/Route32/scripts.pory"
	walk_up
# 532 "data/maps/Route32/scripts.pory"
	walk_up
# 532 "data/maps/Route32/scripts.pory"
	walk_up
# 532 "data/maps/Route32/scripts.pory"
	walk_right
# 532 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 534 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_2:
# 534 "data/maps/Route32/scripts.pory"
	jump_in_place_up
	step_end

# 545 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_3:
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_left
# 545 "data/maps/Route32/scripts.pory"
	walk_up
# 545 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 546 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_4:
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_left
# 546 "data/maps/Route32/scripts.pory"
	walk_up
# 546 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 547 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_5:
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
# 547 "data/maps/Route32/scripts.pory"
	walk_left
	step_end

# 567 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_6:
# 567 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 568 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_7:
# 568 "data/maps/Route32/scripts.pory"
	walk_right
# 568 "data/maps/Route32/scripts.pory"
	face_down
	step_end

# 570 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_8:
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
# 570 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 571 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_9:
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	face_up
	step_end

# 579 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_10:
# 579 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 579 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 579 "data/maps/Route32/scripts.pory"
	walk_fast_down
	step_end

Route32HiddenGrottoWarp_Text_0:
# 514 "data/maps/Route32/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Route32RivalGrottoTutorial_Text_0:
# 526 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}! I see you managed to get\n"
	.string "your first badge!$"

Route32RivalGrottoTutorial_Text_1:
# 540 "data/maps/Route32/scripts.pory"
	.string "Even Marill wanted to congratulate you!$"

Route32RivalGrottoTutorial_Text_2:
# 541 "data/maps/Route32/scripts.pory"
	.string "Listen, there's something you should\n"
	.string "see. I came across it when exploring\l"
	.string "the route. Follow me!$"

Route32RivalGrottoTutorial_Text_3:
# 549 "data/maps/Route32/scripts.pory"
	.string "See this small spot between the trees?\n"
	.string "It leads to a Hidden Grotto.\p"
	.string "I hear they may contain Pokémon that\n"
	.string "are sometimes quite rare, or items\l"
	.string "dropped by them.\p"
	.string "I'll let you explore\n"
	.string "this one, since it's your first time\l"
	.string "seeing one! \l"
	.string "Even if you don't manage to find\l"
	.string "a Pokémon there today, \l"
	.string "you should check it again another day.$"

Route32RivalGrottoTutorial_Text_4:
# 562 "data/maps/Route32/scripts.pory"
	.string "Marill and I will take a trip to\n"
	.string "the Goldenrod City, I hope to see\l"
	.string "you there! Good luck with the\l"
	.string "next Gym, {PLAYER}!$"
