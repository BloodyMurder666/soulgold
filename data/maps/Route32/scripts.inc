# 1 "data/maps/Route32/scripts.pory"

# 2 "data/maps/Route32/scripts.pory"
.set LOCALID_ROUTE32_BALDINGMAN, 1
# 3 "data/maps/Route32/scripts.pory"
.set LOCALID_SLOWPOKETAIL_MAN, 14
# 4 "data/maps/Route32/scripts.pory"

# 5 "data/maps/Route32/scripts.pory"

# 6 "data/maps/Route32/scripts.pory"
Route32_MapScripts::
# 7 "data/maps/Route32/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
# 8 "data/maps/Route32/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 9 "data/maps/Route32/scripts.pory"
	.byte 0
# 10 "data/maps/Route32/scripts.pory"

# 11 "data/maps/Route32/scripts.pory"
Route32_OnTransition: 
# 12 "data/maps/Route32/scripts.pory"
	callnative SetTimeBasedEncounters
# 13 "data/maps/Route32/scripts.pory"
	end
# 14 "data/maps/Route32/scripts.pory"

# 15 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherJustin::
# 16 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_JUSTIN Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
# 17 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route32/scripts.pory"
	end
# 19 "data/maps/Route32/scripts.pory"

# 20 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherRalph::
# 21 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_RALPH Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten
# 22 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route32/scripts.pory"
	end
# 24 "data/maps/Route32/scripts.pory"

# 25 "data/maps/Route32/scripts.pory"
Route32_EventScript_FisherHenry::
# 26 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_HENRY Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
# 27 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route32/scripts.pory"
	end
# 29 "data/maps/Route32/scripts.pory"

# 30 "data/maps/Route32/scripts.pory"
Route32_EventScript_YoungsterAlbert::
# 31 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_ALBERT Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
# 32 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route32/scripts.pory"
	end
# 34 "data/maps/Route32/scripts.pory"

# 35 "data/maps/Route32/scripts.pory"
Route32_EventScript_YoungsterGordon::
# 36 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_GORDON Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
# 37 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route32/scripts.pory"
	end
# 39 "data/maps/Route32/scripts.pory"

# 40 "data/maps/Route32/scripts.pory"
Route32_EventScript_CamperRoland::
# 41 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_ROLAND Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
# 42 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route32/scripts.pory"
	end
# 44 "data/maps/Route32/scripts.pory"

# 45 "data/maps/Route32/scripts.pory"
Route32_EventScript_PicnickerLiz::
# 46 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_LIZ Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten
# 47 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route32/scripts.pory"
	end
# 49 "data/maps/Route32/scripts.pory"

# 50 "data/maps/Route32/scripts.pory"
Route32_EventScript_BirdkeeperPeter::
# 51 "data/maps/Route32/scripts.pory"
	trainerbattle_single TRAINER_PETER Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
# 52 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route32/scripts.pory"
	end
# 54 "data/maps/Route32/scripts.pory"

# 55 "data/maps/Route32/scripts.pory"
Route32_EventScript_Roar::
# 56 "data/maps/Route32/scripts.pory"
	lock
# 57 "data/maps/Route32/scripts.pory"
	faceplayer
# 58 "data/maps/Route32/scripts.pory"
	checkitem ITEM_TM_ROAR
# 59 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route32_EventScript_Roar2
# 60 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
# 61 "data/maps/Route32/scripts.pory"
	giveitem ITEM_TM_ROAR
# 62 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
# 63 "data/maps/Route32/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROAR
# 64 "data/maps/Route32/scripts.pory"
	closemessage
# 65 "data/maps/Route32/scripts.pory"
	release
# 66 "data/maps/Route32/scripts.pory"
	end
# 67 "data/maps/Route32/scripts.pory"
Route32_EventScript_Roar2::
# 68 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
# 69 "data/maps/Route32/scripts.pory"
	closemessage
# 70 "data/maps/Route32/scripts.pory"
	release
# 71 "data/maps/Route32/scripts.pory"
	end
# 72 "data/maps/Route32/scripts.pory"

# 73 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerLeft::
# 74 "data/maps/Route32/scripts.pory"
	lock
# 75 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 76 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 77 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 78 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 79 "data/maps/Route32/scripts.pory"
	delay 60
# 80 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
# 81 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 82 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 83 "data/maps/Route32/scripts.pory"

# 84 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerMid::
# 85 "data/maps/Route32/scripts.pory"
	lock
# 86 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 87 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 88 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 89 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 90 "data/maps/Route32/scripts.pory"
	delay 60
# 91 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
# 92 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 93 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 94 "data/maps/Route32/scripts.pory"

# 95 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerRight::
# 96 "data/maps/Route32/scripts.pory"
	lock
# 97 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 98 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 99 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 100 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 101 "data/maps/Route32/scripts.pory"
	delay 60
# 102 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
# 103 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 104 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 105 "data/maps/Route32/scripts.pory"

# 106 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger::
# 107 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 108 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
# 109 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 110 "data/maps/Route32/scripts.pory"
	closemessage
# 111 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 112 "data/maps/Route32/scripts.pory"
	release
# 113 "data/maps/Route32/scripts.pory"
	end	
# 114 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger2::
# 115 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 116 "data/maps/Route32/scripts.pory"
	closemessage
# 117 "data/maps/Route32/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 118 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
# 119 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
# 120 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 121 "data/maps/Route32/scripts.pory"
	release
# 122 "data/maps/Route32/scripts.pory"
	end
# 123 "data/maps/Route32/scripts.pory"

# 124 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Left::
# 125 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 126 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 127 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 128 "data/maps/Route32/scripts.pory"
	return 
# 129 "data/maps/Route32/scripts.pory"

# 130 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Right::
# 131 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 132 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 133 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 134 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 135 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 136 "data/maps/Route32/scripts.pory"
	return 	
# 137 "data/maps/Route32/scripts.pory"

# 138 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail::
# 139 "data/maps/Route32/scripts.pory"
	lock
# 140 "data/maps/Route32/scripts.pory"
	faceplayer
# 141 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 142 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
# 143 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 144 "data/maps/Route32/scripts.pory"
	closemessage
# 145 "data/maps/Route32/scripts.pory"
	release
# 146 "data/maps/Route32/scripts.pory"
	end
# 147 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail2::
# 148 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 149 "data/maps/Route32/scripts.pory"
	closemessage
# 150 "data/maps/Route32/scripts.pory"
	release
# 151 "data/maps/Route32/scripts.pory"
	end
# 152 "data/maps/Route32/scripts.pory"

# 153 "data/maps/Route32/scripts.pory"

# 154 "data/maps/Route32/scripts.pory"
Route32_EventScript_Frieda::
# 155 "data/maps/Route32/scripts.pory"
	lock
# 156 "data/maps/Route32/scripts.pory"
	faceplayer
# 157 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
# 158 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
# 159 "data/maps/Route32/scripts.pory"
	closemessage
# 160 "data/maps/Route32/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 161 "data/maps/Route32/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/Route32/scripts.pory"
	case 0, Route32_EventScript_FriedaNope
# 163 "data/maps/Route32/scripts.pory"
	case 1, Route32_EventScript_FriedaNope
# 164 "data/maps/Route32/scripts.pory"
	case 2, Route32_EventScript_FriedaNope
# 165 "data/maps/Route32/scripts.pory"
	case 3, Route32_EventScript_FriedaNope
# 166 "data/maps/Route32/scripts.pory"
	case 4, Route32_EventScript_FriedaNope
# 167 "data/maps/Route32/scripts.pory"
	case 5, Route32_EventScript_FriedaYes
# 168 "data/maps/Route32/scripts.pory"
	case 6, Route32_EventScript_FriedaNope
# 169 "data/maps/Route32/scripts.pory"
	case 7, Route32_EventScript_FriedaCancel
# 170 "data/maps/Route32/scripts.pory"
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
# 171 "data/maps/Route32/scripts.pory"
	closemessage
# 172 "data/maps/Route32/scripts.pory"
	release
# 173 "data/maps/Route32/scripts.pory"
	end
# 174 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaYes::
# 175 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
# 176 "data/maps/Route32/scripts.pory"
	giveitem ITEM_POISON_BARB
# 177 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 178 "data/maps/Route32/scripts.pory"
	setflag FLAG_GOT_POISON_BARB
# 179 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
# 180 "data/maps/Route32/scripts.pory"
	closemessage
# 181 "data/maps/Route32/scripts.pory"
	release
# 182 "data/maps/Route32/scripts.pory"
	end
# 183 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaNope::
# 184 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
# 185 "data/maps/Route32/scripts.pory"
	closemessage
# 186 "data/maps/Route32/scripts.pory"
	release
# 187 "data/maps/Route32/scripts.pory"
	end
# 188 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCancel::
# 189 "data/maps/Route32/scripts.pory"
	closemessage
# 190 "data/maps/Route32/scripts.pory"
	release
# 191 "data/maps/Route32/scripts.pory"
	end
# 192 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCompleted::
# 193 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
# 194 "data/maps/Route32/scripts.pory"
	closemessage
# 195 "data/maps/Route32/scripts.pory"
	release
# 196 "data/maps/Route32/scripts.pory"
	end
# 197 "data/maps/Route32/scripts.pory"

# 198 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingMan::
# 199 "data/maps/Route32/scripts.pory"
	lock
# 200 "data/maps/Route32/scripts.pory"
	faceplayer
# 201 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
# 202 "data/maps/Route32/scripts.pory"
	closemessage
# 203 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
# 204 "data/maps/Route32/scripts.pory"
	release
# 205 "data/maps/Route32/scripts.pory"
	end
# 206 "data/maps/Route32/scripts.pory"

# 207 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerLeft::
# 208 "data/maps/Route32/scripts.pory"
	lock
# 209 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 210 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 211 "data/maps/Route32/scripts.pory"
	delay 60
# 212 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 213 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 214 "data/maps/Route32/scripts.pory"
	end
# 215 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerMid::
# 216 "data/maps/Route32/scripts.pory"
	lock
# 217 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 218 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 219 "data/maps/Route32/scripts.pory"
	delay 60
# 220 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
# 221 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 223 "data/maps/Route32/scripts.pory"
	end
# 224 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerRight::
# 225 "data/maps/Route32/scripts.pory"
	lock
# 226 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 227 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 228 "data/maps/Route32/scripts.pory"
	delay 60
# 229 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
# 230 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 231 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 232 "data/maps/Route32/scripts.pory"
	end
# 233 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManCheck::
# 234 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
# 235 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
# 236 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
# 237 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
# 238 "data/maps/Route32/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 239 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 240 "data/maps/Route32/scripts.pory"
	closemessage
# 241 "data/maps/Route32/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 5
# 242 "data/maps/Route32/scripts.pory"
	release
# 243 "data/maps/Route32/scripts.pory"
	end
# 244 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTower::
# 245 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 246 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
# 247 "data/maps/Route32/scripts.pory"
	closemessage
# 248 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 249 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 250 "data/maps/Route32/scripts.pory"
	release
# 251 "data/maps/Route32/scripts.pory"
	end
# 252 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManGym::
# 253 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 254 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
# 255 "data/maps/Route32/scripts.pory"
	closemessage
# 256 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 257 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 258 "data/maps/Route32/scripts.pory"
	release
# 259 "data/maps/Route32/scripts.pory"
	end
# 260 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManEgg::
# 261 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 262 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
# 263 "data/maps/Route32/scripts.pory"
	closemessage
# 264 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 265 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 266 "data/maps/Route32/scripts.pory"
	release
# 267 "data/maps/Route32/scripts.pory"
	end
# 268 "data/maps/Route32/scripts.pory"

# 269 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign1::
# 270 "data/maps/Route32/scripts.pory"
	lock
# 271 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
# 272 "data/maps/Route32/scripts.pory"
	closemessage
# 273 "data/maps/Route32/scripts.pory"
	release
# 274 "data/maps/Route32/scripts.pory"
	end
# 275 "data/maps/Route32/scripts.pory"

# 276 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign2::
# 277 "data/maps/Route32/scripts.pory"
	lock
# 278 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
# 279 "data/maps/Route32/scripts.pory"
	closemessage
# 280 "data/maps/Route32/scripts.pory"
	release
# 281 "data/maps/Route32/scripts.pory"
	end
# 282 "data/maps/Route32/scripts.pory"

# 283 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign3::
# 284 "data/maps/Route32/scripts.pory"
	lock
# 285 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
# 286 "data/maps/Route32/scripts.pory"
	closemessage
# 287 "data/maps/Route32/scripts.pory"
	release
# 288 "data/maps/Route32/scripts.pory"
	end
# 289 "data/maps/Route32/scripts.pory"

# 290 "data/maps/Route32/scripts.pory"
Route32_Movement_Turnback:
# 291 "data/maps/Route32/scripts.pory"
	walk_up
# 292 "data/maps/Route32/scripts.pory"
	step_end
# 293 "data/maps/Route32/scripts.pory"

# 294 "data/maps/Route32/scripts.pory"
Route32_Movement_StartMid:
# 295 "data/maps/Route32/scripts.pory"
	walk_left
# 296 "data/maps/Route32/scripts.pory"
	step_end
# 297 "data/maps/Route32/scripts.pory"

# 298 "data/maps/Route32/scripts.pory"
Route32_Movment_StartRight:
# 299 "data/maps/Route32/scripts.pory"
	walk_left
# 300 "data/maps/Route32/scripts.pory"
	walk_left
# 301 "data/maps/Route32/scripts.pory"
	step_end
# 302 "data/maps/Route32/scripts.pory"

# 303 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeLeft::
# 304 "data/maps/Route32/scripts.pory"
	step_end
# 305 "data/maps/Route32/scripts.pory"

# 306 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeMid::
# 307 "data/maps/Route32/scripts.pory"
	walk_right
# 308 "data/maps/Route32/scripts.pory"
	step_end
# 309 "data/maps/Route32/scripts.pory"

# 310 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeRight::
# 311 "data/maps/Route32/scripts.pory"
	walk_right
# 312 "data/maps/Route32/scripts.pory"
	walk_right
# 313 "data/maps/Route32/scripts.pory"
	step_end
# 314 "data/maps/Route32/scripts.pory"

# 315 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_WhatsTheHurry:
# 316 "data/maps/Route32/scripts.pory"
	.string "Wait up!\n"
# 317 "data/maps/Route32/scripts.pory"
	.string "What's the hurry?$"
# 318 "data/maps/Route32/scripts.pory"

# 319 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_AideIsWaiting:
# 320 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}, right?\n"
# 321 "data/maps/Route32/scripts.pory"
	.string "Some guy wearing glasses\p"
# 322 "data/maps/Route32/scripts.pory"
	.string "was looking for you.\p"
# 323 "data/maps/Route32/scripts.pory"
	.string "See for yourself. He's waiting for\n"
# 324 "data/maps/Route32/scripts.pory"
	.string "you at the POKéMON CENTER.$"
# 325 "data/maps/Route32/scripts.pory"

# 326 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_SproutTower:
# 327 "data/maps/Route32/scripts.pory"
	.string "Have you gone to SPROUT TOWER?\n"
# 328 "data/maps/Route32/scripts.pory"
	.string "If you ever visit VIOLET CITY,\p"
# 329 "data/maps/Route32/scripts.pory"
	.string "they'll expect you to train there.\n"
# 330 "data/maps/Route32/scripts.pory"
	.string "That's basic for trainers.\p"
# 331 "data/maps/Route32/scripts.pory"
	.string "Go to SPROUT TOWER!$"
# 332 "data/maps/Route32/scripts.pory"

# 333 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_VioletGym:
# 334 "data/maps/Route32/scripts.pory"
	.string "Have you gone to the POKéMON GYM?\n"
# 335 "data/maps/Route32/scripts.pory"
	.string "You can test your POKéMON and\p"
# 336 "data/maps/Route32/scripts.pory"
	.string "yourself there.\n"
# 337 "data/maps/Route32/scripts.pory"
	.string "It's a rite of passage for all\p"
# 338 "data/maps/Route32/scripts.pory"
	.string "trainers!$"
# 339 "data/maps/Route32/scripts.pory"

# 340 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_HaveThisSeed:
# 341 "data/maps/Route32/scripts.pory"
	.string "You have some good POKéMON there.\n"
# 342 "data/maps/Route32/scripts.pory"
	.string "It must be from the training you\p"
# 343 "data/maps/Route32/scripts.pory"
	.string "gave them around VIOLET CITY.\n"
# 344 "data/maps/Route32/scripts.pory"
	.string "The training at the GYM must have\p"
# 345 "data/maps/Route32/scripts.pory"
	.string "been especially helpful. As a\n"
# 346 "data/maps/Route32/scripts.pory"
	.string "souvenir of VIOLET CITY, take this.\p"
# 347 "data/maps/Route32/scripts.pory"
	.string "It increases the power of GRASS-\n"
# 348 "data/maps/Route32/scripts.pory"
	.string "type moves.$"
# 349 "data/maps/Route32/scripts.pory"

# 350 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_Experiences:
# 351 "data/maps/Route32/scripts.pory"
	.string "Your experiences in VIOLET CITY\n"
# 352 "data/maps/Route32/scripts.pory"
	.string "should be useful for your journey.$"
# 353 "data/maps/Route32/scripts.pory"

# 354 "data/maps/Route32/scripts.pory"
Route32_Text_SlowpokeTailOffer:
# 355 "data/maps/Route32/scripts.pory"
	.string "How would you like to have this\n"
# 356 "data/maps/Route32/scripts.pory"
	.string "tasty, nutritious SLOWPOKE TAIL?\p"
# 357 "data/maps/Route32/scripts.pory"
	.string "For you right now, just\n"
# 358 "data/maps/Route32/scripts.pory"
	.string "¥1,000,000!\p"
# 359 "data/maps/Route32/scripts.pory"
	.string "You'll want this!$"
# 360 "data/maps/Route32/scripts.pory"

# 361 "data/maps/Route32/scripts.pory"
Route32_Text_ThoughtKidsLoaded:
# 362 "data/maps/Route32/scripts.pory"
	.string "Tch! I thought kids\n"
# 363 "data/maps/Route32/scripts.pory"
	.string "these days were loaded…$"
# 364 "data/maps/Route32/scripts.pory"

# 365 "data/maps/Route32/scripts.pory"
Route32_Text_RefusedSlowpokeTail:
# 366 "data/maps/Route32/scripts.pory"
	.string "You don't want it?\n"
# 367 "data/maps/Route32/scripts.pory"
	.string "Then scram. Shoo!$"
# 368 "data/maps/Route32/scripts.pory"

# 369 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Seen:
# 370 "data/maps/Route32/scripts.pory"
	.string "Whoa!\p"
# 371 "data/maps/Route32/scripts.pory"
	.string "You made me lose that fish!$"
# 372 "data/maps/Route32/scripts.pory"

# 373 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Beaten:
# 374 "data/maps/Route32/scripts.pory"
	.string "Sploosh!$"
# 375 "data/maps/Route32/scripts.pory"

# 376 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_After:
# 377 "data/maps/Route32/scripts.pory"
	.string "Calm, collected… The essence of\n"
# 378 "data/maps/Route32/scripts.pory"
	.string "fishing and POKéMON is the same.$"
# 379 "data/maps/Route32/scripts.pory"

# 380 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Seen:
# 381 "data/maps/Route32/scripts.pory"
	.string "I'm really good at both\n"
# 382 "data/maps/Route32/scripts.pory"
	.string "fishing and POKéMON.\p"
# 383 "data/maps/Route32/scripts.pory"
	.string "I'm not about to lose to any kid!$"
# 384 "data/maps/Route32/scripts.pory"

# 385 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Beaten:
# 386 "data/maps/Route32/scripts.pory"
	.string "Tch! I tried to rush\n"
# 387 "data/maps/Route32/scripts.pory"
	.string "things…$"
# 388 "data/maps/Route32/scripts.pory"

# 389 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_After:
# 390 "data/maps/Route32/scripts.pory"
	.string "Fishing is a lifelong\n"
# 391 "data/maps/Route32/scripts.pory"
	.string "passion.\p"
# 392 "data/maps/Route32/scripts.pory"
	.string "POKéMON are lifelong friends!$"
# 393 "data/maps/Route32/scripts.pory"

# 394 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Seen:
# 395 "data/maps/Route32/scripts.pory"
	.string "My POKéMON? Freshly caught!$"
# 396 "data/maps/Route32/scripts.pory"

# 397 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Beaten:
# 398 "data/maps/Route32/scripts.pory"
	.string "SPLASH?$"
# 399 "data/maps/Route32/scripts.pory"

# 400 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_After:
# 401 "data/maps/Route32/scripts.pory"
	.string "Freshly caught POKéMON are\n"
# 402 "data/maps/Route32/scripts.pory"
	.string "no match for properly raised ones.$"
# 403 "data/maps/Route32/scripts.pory"

# 404 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Seen:
# 405 "data/maps/Route32/scripts.pory"
	.string "I haven't seen you around before.\n"
# 406 "data/maps/Route32/scripts.pory"
	.string "So you think you are pretty tough?$"
# 407 "data/maps/Route32/scripts.pory"

# 408 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Beaten:
# 409 "data/maps/Route32/scripts.pory"
	.string "You're strong!$"
# 410 "data/maps/Route32/scripts.pory"

# 411 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_After:
# 412 "data/maps/Route32/scripts.pory"
	.string "I'm going to try to be the\n"
# 413 "data/maps/Route32/scripts.pory"
	.string "best with my favorites.\p"
# 414 "data/maps/Route32/scripts.pory"
	.string "I'm not using the same tough\n"
# 415 "data/maps/Route32/scripts.pory"
	.string "POKéMON as everyone else.$"
# 416 "data/maps/Route32/scripts.pory"

# 417 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Seen:
# 418 "data/maps/Route32/scripts.pory"
	.string "I found some good POKéMON\n"
# 419 "data/maps/Route32/scripts.pory"
	.string "in the grass!\p"
# 420 "data/maps/Route32/scripts.pory"
	.string "I think they'll do it for me!$"
# 421 "data/maps/Route32/scripts.pory"

# 422 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Beaten:
# 423 "data/maps/Route32/scripts.pory"
	.string "Darn. I thought I could win.$"
# 424 "data/maps/Route32/scripts.pory"

# 425 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_After:
# 426 "data/maps/Route32/scripts.pory"
	.string "The grass is full of\n"
# 427 "data/maps/Route32/scripts.pory"
	.string "clingy things.$"
# 428 "data/maps/Route32/scripts.pory"

# 429 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Seen:
# 430 "data/maps/Route32/scripts.pory"
	.string "That glance… It's intriguing.$"
# 431 "data/maps/Route32/scripts.pory"

# 432 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Beaten:
# 433 "data/maps/Route32/scripts.pory"
	.string "Hmmm. This is disappointing.$"
# 434 "data/maps/Route32/scripts.pory"

# 435 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_After:
# 436 "data/maps/Route32/scripts.pory"
	.string "If you don't want to battle,\n"
# 437 "data/maps/Route32/scripts.pory"
	.string "just avoid eye contact.$"
# 438 "data/maps/Route32/scripts.pory"

# 439 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Seen:
# 440 "data/maps/Route32/scripts.pory"
	.string "Uh-huh. Yeah, and you know…\p"
# 441 "data/maps/Route32/scripts.pory"
	.string "Pardon? Battle? I'm on the phone.\n"
# 442 "data/maps/Route32/scripts.pory"
	.string "Oh, all right. But make it fast.$"
# 443 "data/maps/Route32/scripts.pory"

# 444 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Beaten:
# 445 "data/maps/Route32/scripts.pory"
	.string "Oh! I've got to relieve\n"
# 446 "data/maps/Route32/scripts.pory"
	.string "my anger!$"
# 447 "data/maps/Route32/scripts.pory"

# 448 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_After:
# 449 "data/maps/Route32/scripts.pory"
	.string "I was having a nice chat too.$"
# 450 "data/maps/Route32/scripts.pory"

# 451 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Seen:
# 452 "data/maps/Route32/scripts.pory"
	.string "That BADGE! It's from VIOLET CITY!\n"
# 453 "data/maps/Route32/scripts.pory"
	.string "You beat FALKNER?$"
# 454 "data/maps/Route32/scripts.pory"

# 455 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Beaten:
# 456 "data/maps/Route32/scripts.pory"
	.string "I know what my weaknesses are.$"
# 457 "data/maps/Route32/scripts.pory"

# 458 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_After:
# 459 "data/maps/Route32/scripts.pory"
	.string "I should train again at the\n"
# 460 "data/maps/Route32/scripts.pory"
	.string "GYM in VIOLET CITY.$"
# 461 "data/maps/Route32/scripts.pory"

# 462 "data/maps/Route32/scripts.pory"
Route32_Text_RoarIntro:
# 463 "data/maps/Route32/scripts.pory"
	.string "WROOOOAR! PEOPLE RUN WHEN I\n"
# 464 "data/maps/Route32/scripts.pory"
	.string "ROAR! BUT YOU CAME LOOKING!\p"
# 465 "data/maps/Route32/scripts.pory"
	.string "THAT PLEASES ME! NOW TAKE THIS!$"
# 466 "data/maps/Route32/scripts.pory"

# 467 "data/maps/Route32/scripts.pory"
Route32_Text_RoarOutro:
# 468 "data/maps/Route32/scripts.pory"
	.string "WROOOOAR! IT'S ROAR!\p"
# 469 "data/maps/Route32/scripts.pory"
	.string "EVEN POKéMON RUN FROM A GOOD\n"
# 470 "data/maps/Route32/scripts.pory"
	.string "ROAR!$"
# 471 "data/maps/Route32/scripts.pory"

# 472 "data/maps/Route32/scripts.pory"
Route32_Text_MeetFrieda:
# 473 "data/maps/Route32/scripts.pory"
	.string "FRIEDA: Yahoo!\p"
# 474 "data/maps/Route32/scripts.pory"
	.string "I'm FRIEDA of the WEEKDAY FAMILY!\n"
# 475 "data/maps/Route32/scripts.pory"
	.string "Nice to meet you!\p"
# 476 "data/maps/Route32/scripts.pory"
	.string "If you can guess my favorite day,\n"
# 477 "data/maps/Route32/scripts.pory"
	.string "I'll give you a reward.$"
# 478 "data/maps/Route32/scripts.pory"

# 479 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGivesGift:
# 480 "data/maps/Route32/scripts.pory"
	.string "Here's a POISON BARB for you!$"
# 481 "data/maps/Route32/scripts.pory"

# 482 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGaveGift:
# 483 "data/maps/Route32/scripts.pory"
	.string "FRIEDA: Give it to a POKéMON\n"
# 484 "data/maps/Route32/scripts.pory"
	.string "that has POISON-type moves.\p"
# 485 "data/maps/Route32/scripts.pory"
	.string "Oh!\p"
# 486 "data/maps/Route32/scripts.pory"
	.string "It's wicked!\p"
# 487 "data/maps/Route32/scripts.pory"
	.string "You'll be shocked how good it\n"
# 488 "data/maps/Route32/scripts.pory"
	.string "makes poison moves!$"
# 489 "data/maps/Route32/scripts.pory"

# 490 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaFriday:
# 491 "data/maps/Route32/scripts.pory"
	.string "FRIEDA: Hiya! What day do\n"
# 492 "data/maps/Route32/scripts.pory"
	.string "you like?\p"
# 493 "data/maps/Route32/scripts.pory"
	.string "I love Friday. No doubt about\n"
# 494 "data/maps/Route32/scripts.pory"
	.string "it!\p"
# 495 "data/maps/Route32/scripts.pory"
	.string "Don't you think it's great too?$"
# 496 "data/maps/Route32/scripts.pory"

# 497 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaNope:
# 498 "data/maps/Route32/scripts.pory"
	.string "FRIEDA: Not that one!$"
# 499 "data/maps/Route32/scripts.pory"

# 500 "data/maps/Route32/scripts.pory"
Route32_Text_Sign1:
# 501 "data/maps/Route32/scripts.pory"
	.string "ROUTE 32\p"
# 502 "data/maps/Route32/scripts.pory"
	.string "VIOLET CITY - AZALEA TOWN$"
# 503 "data/maps/Route32/scripts.pory"

# 504 "data/maps/Route32/scripts.pory"
Route32_Text_Sign2:
# 505 "data/maps/Route32/scripts.pory"
	.string "RUINS OF ALPH\n"
# 506 "data/maps/Route32/scripts.pory"
	.string "EAST ENTRANCE$"
# 507 "data/maps/Route32/scripts.pory"

# 508 "data/maps/Route32/scripts.pory"
Route32_Text_Sign3:
# 509 "data/maps/Route32/scripts.pory"
	.string "UNION CAVE\n"
# 510 "data/maps/Route32/scripts.pory"
	.string "AHEAD$"

Route32HiddenGrottoWarp::
# 514 "data/maps/Route32/scripts.pory"
	lock
# 515 "data/maps/Route32/scripts.pory"
	msgbox Route32HiddenGrottoWarp_Text_0, MSGBOX_YESNO
# 517 "data/maps/Route32/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route32HiddenGrottoWarp_2
Route32HiddenGrottoWarp_1:
# 521 "data/maps/Route32/scripts.pory"
	release
	end

Route32HiddenGrottoWarp_2:
# 518 "data/maps/Route32/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE32, 0
# 519 "data/maps/Route32/scripts.pory"
	waitstate
	goto Route32HiddenGrottoWarp_1


Route32HiddenGrottoWarp_Text_0:
# 515 "data/maps/Route32/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
