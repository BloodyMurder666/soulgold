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
Route32_EventScript_SlowpokeTail_TriggerLeft::
# 55 "data/maps/Route32/scripts.pory"
	lock
# 56 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 57 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 58 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 59 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 60 "data/maps/Route32/scripts.pory"
	delay 60
# 61 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
# 62 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 64 "data/maps/Route32/scripts.pory"

# 65 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerMid::
# 66 "data/maps/Route32/scripts.pory"
	lock
# 67 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 68 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 69 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 70 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 71 "data/maps/Route32/scripts.pory"
	delay 60
# 72 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
# 73 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 74 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 75 "data/maps/Route32/scripts.pory"

# 76 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_TriggerRight::
# 77 "data/maps/Route32/scripts.pory"
	lock
# 78 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 79 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 80 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 81 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
# 82 "data/maps/Route32/scripts.pory"
	delay 60
# 83 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
# 84 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_SlowpokeTail_Trigger
# 86 "data/maps/Route32/scripts.pory"

# 87 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger::
# 88 "data/maps/Route32/scripts.pory"
	createfieldmugshot MUGSHOT_ROCKET_GRUNT_M
# 89 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 90 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
# 91 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 92 "data/maps/Route32/scripts.pory"
	closemessage
# 93 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 94 "data/maps/Route32/scripts.pory"
	release
# 95 "data/maps/Route32/scripts.pory"
	end	
# 96 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger2::
# 97 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 98 "data/maps/Route32/scripts.pory"
	closemessage
# 99 "data/maps/Route32/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 100 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
# 101 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
# 102 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 103 "data/maps/Route32/scripts.pory"
	release
# 104 "data/maps/Route32/scripts.pory"
	end
# 105 "data/maps/Route32/scripts.pory"

# 106 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Left::
# 107 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 108 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 110 "data/maps/Route32/scripts.pory"
	return 
# 111 "data/maps/Route32/scripts.pory"

# 112 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Right::
# 113 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 114 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 115 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 116 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 117 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 118 "data/maps/Route32/scripts.pory"
	return 	
# 119 "data/maps/Route32/scripts.pory"

# 120 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail::
# 121 "data/maps/Route32/scripts.pory"
	lock
# 122 "data/maps/Route32/scripts.pory"
	faceplayer
# 123 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 124 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
# 125 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 126 "data/maps/Route32/scripts.pory"
	closemessage
# 127 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 128 "data/maps/Route32/scripts.pory"
	release
# 129 "data/maps/Route32/scripts.pory"
	end
# 130 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail2::
# 131 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 132 "data/maps/Route32/scripts.pory"
	closemessage
# 133 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 134 "data/maps/Route32/scripts.pory"
	release
# 135 "data/maps/Route32/scripts.pory"
	end
# 136 "data/maps/Route32/scripts.pory"

# 137 "data/maps/Route32/scripts.pory"

# 138 "data/maps/Route32/scripts.pory"
Route32_EventScript_Frieda::
# 139 "data/maps/Route32/scripts.pory"
	lock
# 140 "data/maps/Route32/scripts.pory"
	faceplayer
# 141 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
# 142 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
# 143 "data/maps/Route32/scripts.pory"
	closemessage
# 144 "data/maps/Route32/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 145 "data/maps/Route32/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/Route32/scripts.pory"
	case 0, Route32_EventScript_FriedaNope
# 147 "data/maps/Route32/scripts.pory"
	case 1, Route32_EventScript_FriedaNope
# 148 "data/maps/Route32/scripts.pory"
	case 2, Route32_EventScript_FriedaNope
# 149 "data/maps/Route32/scripts.pory"
	case 3, Route32_EventScript_FriedaNope
# 150 "data/maps/Route32/scripts.pory"
	case 4, Route32_EventScript_FriedaNope
# 151 "data/maps/Route32/scripts.pory"
	case 5, Route32_EventScript_FriedaYes
# 152 "data/maps/Route32/scripts.pory"
	case 6, Route32_EventScript_FriedaNope
# 153 "data/maps/Route32/scripts.pory"
	case 7, Route32_EventScript_FriedaCancel
# 154 "data/maps/Route32/scripts.pory"
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
# 155 "data/maps/Route32/scripts.pory"
	closemessage
# 156 "data/maps/Route32/scripts.pory"
	release
# 157 "data/maps/Route32/scripts.pory"
	end
# 158 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaYes::
# 159 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
# 160 "data/maps/Route32/scripts.pory"
	giveitem ITEM_POISON_BARB
# 161 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 162 "data/maps/Route32/scripts.pory"
	setflag FLAG_GOT_POISON_BARB
# 163 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
# 164 "data/maps/Route32/scripts.pory"
	closemessage
# 165 "data/maps/Route32/scripts.pory"
	release
# 166 "data/maps/Route32/scripts.pory"
	end
# 167 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaNope::
# 168 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
# 169 "data/maps/Route32/scripts.pory"
	closemessage
# 170 "data/maps/Route32/scripts.pory"
	release
# 171 "data/maps/Route32/scripts.pory"
	end
# 172 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCancel::
# 173 "data/maps/Route32/scripts.pory"
	closemessage
# 174 "data/maps/Route32/scripts.pory"
	release
# 175 "data/maps/Route32/scripts.pory"
	end
# 176 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCompleted::
# 177 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
# 178 "data/maps/Route32/scripts.pory"
	closemessage
# 179 "data/maps/Route32/scripts.pory"
	release
# 180 "data/maps/Route32/scripts.pory"
	end
# 181 "data/maps/Route32/scripts.pory"

# 182 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingMan::
# 183 "data/maps/Route32/scripts.pory"
	lock
# 184 "data/maps/Route32/scripts.pory"
	faceplayer
# 185 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
# 186 "data/maps/Route32/scripts.pory"
	closemessage
# 187 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
# 188 "data/maps/Route32/scripts.pory"
	release
# 189 "data/maps/Route32/scripts.pory"
	end
# 190 "data/maps/Route32/scripts.pory"

# 191 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerLeft::
# 192 "data/maps/Route32/scripts.pory"
	lock
# 193 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 194 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 195 "data/maps/Route32/scripts.pory"
	delay 60
# 196 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 197 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 198 "data/maps/Route32/scripts.pory"
	end
# 199 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerMid::
# 200 "data/maps/Route32/scripts.pory"
	lock
# 201 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 202 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 203 "data/maps/Route32/scripts.pory"
	delay 60
# 204 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
# 205 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 206 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 207 "data/maps/Route32/scripts.pory"
	end
# 208 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerRight::
# 209 "data/maps/Route32/scripts.pory"
	lock
# 210 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 211 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 212 "data/maps/Route32/scripts.pory"
	delay 60
# 213 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
# 214 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 215 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 216 "data/maps/Route32/scripts.pory"
	end
# 217 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManCheck::
# 218 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
# 219 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
# 220 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
# 221 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
# 222 "data/maps/Route32/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 223 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 224 "data/maps/Route32/scripts.pory"
	closemessage
# 225 "data/maps/Route32/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 5
# 226 "data/maps/Route32/scripts.pory"
	release
# 227 "data/maps/Route32/scripts.pory"
	end
# 228 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTower::
# 229 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 230 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
# 231 "data/maps/Route32/scripts.pory"
	closemessage
# 232 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 233 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 234 "data/maps/Route32/scripts.pory"
	release
# 235 "data/maps/Route32/scripts.pory"
	end
# 236 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManGym::
# 237 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 238 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
# 239 "data/maps/Route32/scripts.pory"
	closemessage
# 240 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 241 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route32/scripts.pory"
	release
# 243 "data/maps/Route32/scripts.pory"
	end
# 244 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManEgg::
# 245 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 246 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
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

# 253 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign1::
# 254 "data/maps/Route32/scripts.pory"
	lock
# 255 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
# 256 "data/maps/Route32/scripts.pory"
	closemessage
# 257 "data/maps/Route32/scripts.pory"
	release
# 258 "data/maps/Route32/scripts.pory"
	end
# 259 "data/maps/Route32/scripts.pory"

# 260 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign2::
# 261 "data/maps/Route32/scripts.pory"
	lock
# 262 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
# 263 "data/maps/Route32/scripts.pory"
	closemessage
# 264 "data/maps/Route32/scripts.pory"
	release
# 265 "data/maps/Route32/scripts.pory"
	end
# 266 "data/maps/Route32/scripts.pory"

# 267 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign3::
# 268 "data/maps/Route32/scripts.pory"
	lock
# 269 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
# 270 "data/maps/Route32/scripts.pory"
	closemessage
# 271 "data/maps/Route32/scripts.pory"
	release
# 272 "data/maps/Route32/scripts.pory"
	end
# 273 "data/maps/Route32/scripts.pory"

# 274 "data/maps/Route32/scripts.pory"
Route32_Movement_Turnback:
# 275 "data/maps/Route32/scripts.pory"
	walk_up
# 276 "data/maps/Route32/scripts.pory"
	step_end
# 277 "data/maps/Route32/scripts.pory"

# 278 "data/maps/Route32/scripts.pory"
Route32_Movement_StartMid:
# 279 "data/maps/Route32/scripts.pory"
	walk_left
# 280 "data/maps/Route32/scripts.pory"
	step_end
# 281 "data/maps/Route32/scripts.pory"

# 282 "data/maps/Route32/scripts.pory"
Route32_Movment_StartRight:
# 283 "data/maps/Route32/scripts.pory"
	walk_left
# 284 "data/maps/Route32/scripts.pory"
	walk_left
# 285 "data/maps/Route32/scripts.pory"
	step_end
# 286 "data/maps/Route32/scripts.pory"

# 287 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeLeft::
# 288 "data/maps/Route32/scripts.pory"
	step_end
# 289 "data/maps/Route32/scripts.pory"

# 290 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeMid::
# 291 "data/maps/Route32/scripts.pory"
	walk_right
# 292 "data/maps/Route32/scripts.pory"
	step_end
# 293 "data/maps/Route32/scripts.pory"

# 294 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeRight::
# 295 "data/maps/Route32/scripts.pory"
	walk_right
# 296 "data/maps/Route32/scripts.pory"
	walk_right
# 297 "data/maps/Route32/scripts.pory"
	step_end
# 298 "data/maps/Route32/scripts.pory"

# 299 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_WhatsTheHurry:
# 300 "data/maps/Route32/scripts.pory"
	.string "Wait up!\n"
# 301 "data/maps/Route32/scripts.pory"
	.string "What's the hurry?$"
# 302 "data/maps/Route32/scripts.pory"

# 303 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_AideIsWaiting:
# 304 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}, right?\n"
# 305 "data/maps/Route32/scripts.pory"
	.string "Some guy wearing glasses\p"
# 306 "data/maps/Route32/scripts.pory"
	.string "was looking for you.\p"
# 307 "data/maps/Route32/scripts.pory"
	.string "See for yourself. He's waiting for\n"
# 308 "data/maps/Route32/scripts.pory"
	.string "you at the Pokémon Center.$"
# 309 "data/maps/Route32/scripts.pory"

# 310 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_SproutTower:
# 311 "data/maps/Route32/scripts.pory"
	.string "Have you gone to Sprout Tower?\n"
# 312 "data/maps/Route32/scripts.pory"
	.string "If you ever visit Violet City,\p"
# 313 "data/maps/Route32/scripts.pory"
	.string "they'll expect you to train there.\n"
# 314 "data/maps/Route32/scripts.pory"
	.string "That's basic for trainers.\p"
# 315 "data/maps/Route32/scripts.pory"
	.string "Go to Sprout Tower!$"
# 316 "data/maps/Route32/scripts.pory"

# 317 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_VioletGym:
# 318 "data/maps/Route32/scripts.pory"
	.string "Have you gone to the Pokémon Gym?\n"
# 319 "data/maps/Route32/scripts.pory"
	.string "You can test your Pokémon and\p"
# 320 "data/maps/Route32/scripts.pory"
	.string "yourself there.\n"
# 321 "data/maps/Route32/scripts.pory"
	.string "It's a rite of passage for all\p"
# 322 "data/maps/Route32/scripts.pory"
	.string "trainers!$"
# 323 "data/maps/Route32/scripts.pory"

# 324 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_HaveThisSeed:
# 325 "data/maps/Route32/scripts.pory"
	.string "You have some good Pokémon there.\n"
# 326 "data/maps/Route32/scripts.pory"
	.string "It must be from the training you\p"
# 327 "data/maps/Route32/scripts.pory"
	.string "gave them around Violet City.\n"
# 328 "data/maps/Route32/scripts.pory"
	.string "The training at the Gym must have\p"
# 329 "data/maps/Route32/scripts.pory"
	.string "been especially helpful. As a\n"
# 330 "data/maps/Route32/scripts.pory"
	.string "souvenir of Violet City, take this.\p"
# 331 "data/maps/Route32/scripts.pory"
	.string "It increases the power of Grass-\n"
# 332 "data/maps/Route32/scripts.pory"
	.string "type moves.$"
# 333 "data/maps/Route32/scripts.pory"

# 334 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_Experiences:
# 335 "data/maps/Route32/scripts.pory"
	.string "Your experiences in Violet City\n"
# 336 "data/maps/Route32/scripts.pory"
	.string "should be useful for your journey.$"
# 337 "data/maps/Route32/scripts.pory"

# 338 "data/maps/Route32/scripts.pory"
Route32_Text_SlowpokeTailOffer:
# 339 "data/maps/Route32/scripts.pory"
	.string "How would you like to have this\n"
# 340 "data/maps/Route32/scripts.pory"
	.string "tasty, nutritious Slowpoke Tail?\p"
# 341 "data/maps/Route32/scripts.pory"
	.string "For you right now, just\n"
# 342 "data/maps/Route32/scripts.pory"
	.string "¥1,000,000!\p"
# 343 "data/maps/Route32/scripts.pory"
	.string "You'll want this!$"
# 344 "data/maps/Route32/scripts.pory"

# 345 "data/maps/Route32/scripts.pory"
Route32_Text_ThoughtKidsLoaded:
# 346 "data/maps/Route32/scripts.pory"
	.string "Tch! I thought kids\n"
# 347 "data/maps/Route32/scripts.pory"
	.string "these days were loaded…$"
# 348 "data/maps/Route32/scripts.pory"

# 349 "data/maps/Route32/scripts.pory"
Route32_Text_RefusedSlowpokeTail:
# 350 "data/maps/Route32/scripts.pory"
	.string "You don't want it?\n"
# 351 "data/maps/Route32/scripts.pory"
	.string "Then scram. Shoo!$"
# 352 "data/maps/Route32/scripts.pory"

# 353 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Seen:
# 354 "data/maps/Route32/scripts.pory"
	.string "Whoa!\p"
# 355 "data/maps/Route32/scripts.pory"
	.string "You made me lose that fish!$"
# 356 "data/maps/Route32/scripts.pory"

# 357 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Beaten:
# 358 "data/maps/Route32/scripts.pory"
	.string "Sploosh!$"
# 359 "data/maps/Route32/scripts.pory"

# 360 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_After:
# 361 "data/maps/Route32/scripts.pory"
	.string "Calm, collected… The essence of\n"
# 362 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon is the same.$"
# 363 "data/maps/Route32/scripts.pory"

# 364 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Seen:
# 365 "data/maps/Route32/scripts.pory"
	.string "I'm really good at both\n"
# 366 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon.\p"
# 367 "data/maps/Route32/scripts.pory"
	.string "I'm not about to lose to any kid!$"
# 368 "data/maps/Route32/scripts.pory"

# 369 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Beaten:
# 370 "data/maps/Route32/scripts.pory"
	.string "Tch! I tried to rush\n"
# 371 "data/maps/Route32/scripts.pory"
	.string "things…$"
# 372 "data/maps/Route32/scripts.pory"

# 373 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_After:
# 374 "data/maps/Route32/scripts.pory"
	.string "Fishing is a lifelong\n"
# 375 "data/maps/Route32/scripts.pory"
	.string "passion.\p"
# 376 "data/maps/Route32/scripts.pory"
	.string "Pokémon are lifelong friends!$"
# 377 "data/maps/Route32/scripts.pory"

# 378 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Seen:
# 379 "data/maps/Route32/scripts.pory"
	.string "My Pokémon? Freshly caught!$"
# 380 "data/maps/Route32/scripts.pory"

# 381 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Beaten:
# 382 "data/maps/Route32/scripts.pory"
	.string "Splash?$"
# 383 "data/maps/Route32/scripts.pory"

# 384 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_After:
# 385 "data/maps/Route32/scripts.pory"
	.string "Freshly caught Pokémon are\n"
# 386 "data/maps/Route32/scripts.pory"
	.string "no match for properly raised ones.$"
# 387 "data/maps/Route32/scripts.pory"

# 388 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Seen:
# 389 "data/maps/Route32/scripts.pory"
	.string "I haven't seen you around before.\n"
# 390 "data/maps/Route32/scripts.pory"
	.string "So you think you are pretty tough?$"
# 391 "data/maps/Route32/scripts.pory"

# 392 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Beaten:
# 393 "data/maps/Route32/scripts.pory"
	.string "You're strong!$"
# 394 "data/maps/Route32/scripts.pory"

# 395 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_After:
# 396 "data/maps/Route32/scripts.pory"
	.string "I'm going to try to be the\n"
# 397 "data/maps/Route32/scripts.pory"
	.string "best with my favorites.\p"
# 398 "data/maps/Route32/scripts.pory"
	.string "I'm not using the same tough\n"
# 399 "data/maps/Route32/scripts.pory"
	.string "Pokémon as everyone else.$"
# 400 "data/maps/Route32/scripts.pory"

# 401 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Seen:
# 402 "data/maps/Route32/scripts.pory"
	.string "I found some good Pokémon\n"
# 403 "data/maps/Route32/scripts.pory"
	.string "in the grass!\p"
# 404 "data/maps/Route32/scripts.pory"
	.string "I think they'll do it for me!$"
# 405 "data/maps/Route32/scripts.pory"

# 406 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Beaten:
# 407 "data/maps/Route32/scripts.pory"
	.string "Darn. I thought I could win.$"
# 408 "data/maps/Route32/scripts.pory"

# 409 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_After:
# 410 "data/maps/Route32/scripts.pory"
	.string "The grass is full of\n"
# 411 "data/maps/Route32/scripts.pory"
	.string "clingy things.$"
# 412 "data/maps/Route32/scripts.pory"

# 413 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Seen:
# 414 "data/maps/Route32/scripts.pory"
	.string "That glance… It's intriguing.$"
# 415 "data/maps/Route32/scripts.pory"

# 416 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Beaten:
# 417 "data/maps/Route32/scripts.pory"
	.string "Hmmm. This is disappointing.$"
# 418 "data/maps/Route32/scripts.pory"

# 419 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_After:
# 420 "data/maps/Route32/scripts.pory"
	.string "If you don't want to battle,\n"
# 421 "data/maps/Route32/scripts.pory"
	.string "just avoid eye contact.$"
# 422 "data/maps/Route32/scripts.pory"

# 423 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Seen:
# 424 "data/maps/Route32/scripts.pory"
	.string "Uh-huh. Yeah, and you know…\p"
# 425 "data/maps/Route32/scripts.pory"
	.string "Pardon? Battle? I'm on the phone.\n"
# 426 "data/maps/Route32/scripts.pory"
	.string "Oh, all right. But make it fast.$"
# 427 "data/maps/Route32/scripts.pory"

# 428 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Beaten:
# 429 "data/maps/Route32/scripts.pory"
	.string "Oh! I've got to relieve\n"
# 430 "data/maps/Route32/scripts.pory"
	.string "my anger!$"
# 431 "data/maps/Route32/scripts.pory"

# 432 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_After:
# 433 "data/maps/Route32/scripts.pory"
	.string "I was having a nice chat too.$"
# 434 "data/maps/Route32/scripts.pory"

# 435 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Seen:
# 436 "data/maps/Route32/scripts.pory"
	.string "That Badge! It's from Violet City!\n"
# 437 "data/maps/Route32/scripts.pory"
	.string "You beat Falkner?$"
# 438 "data/maps/Route32/scripts.pory"

# 439 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Beaten:
# 440 "data/maps/Route32/scripts.pory"
	.string "I know what my weaknesses are.$"
# 441 "data/maps/Route32/scripts.pory"

# 442 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_After:
# 443 "data/maps/Route32/scripts.pory"
	.string "I should train again at the\n"
# 444 "data/maps/Route32/scripts.pory"
	.string "Gym in Violet City.$"
# 445 "data/maps/Route32/scripts.pory"

# 446 "data/maps/Route32/scripts.pory"
Route32_Text_RoarIntro:
# 447 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! People Run When I\n"
# 448 "data/maps/Route32/scripts.pory"
	.string "Roar! But You Came Looking!\p"
# 449 "data/maps/Route32/scripts.pory"
	.string "That Pleases Me! Now Take This!$"
# 450 "data/maps/Route32/scripts.pory"

# 451 "data/maps/Route32/scripts.pory"
Route32_Text_RoarOutro:
# 452 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! It's Roar!\p"
# 453 "data/maps/Route32/scripts.pory"
	.string "Even Pokémon Run From A Good\n"
# 454 "data/maps/Route32/scripts.pory"
	.string "Roar!$"
# 455 "data/maps/Route32/scripts.pory"

# 456 "data/maps/Route32/scripts.pory"
Route32_Text_MeetFrieda:
# 457 "data/maps/Route32/scripts.pory"
	.string "Frieda: Yahoo!\p"
# 458 "data/maps/Route32/scripts.pory"
	.string "I'm Frieda of the Weekday Family!\n"
# 459 "data/maps/Route32/scripts.pory"
	.string "Nice to meet you!\p"
# 460 "data/maps/Route32/scripts.pory"
	.string "If you can guess my favorite day,\n"
# 461 "data/maps/Route32/scripts.pory"
	.string "I'll give you a reward.$"
# 462 "data/maps/Route32/scripts.pory"

# 463 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGivesGift:
# 464 "data/maps/Route32/scripts.pory"
	.string "Here's a Poison Barb for you!$"
# 465 "data/maps/Route32/scripts.pory"

# 466 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGaveGift:
# 467 "data/maps/Route32/scripts.pory"
	.string "Frieda: Give it to a Pokémon\n"
# 468 "data/maps/Route32/scripts.pory"
	.string "that has Poison-type moves.\p"
# 469 "data/maps/Route32/scripts.pory"
	.string "Oh!\p"
# 470 "data/maps/Route32/scripts.pory"
	.string "It's wicked!\p"
# 471 "data/maps/Route32/scripts.pory"
	.string "You'll be shocked how good it\n"
# 472 "data/maps/Route32/scripts.pory"
	.string "makes poison moves!$"
# 473 "data/maps/Route32/scripts.pory"

# 474 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaFriday:
# 475 "data/maps/Route32/scripts.pory"
	.string "Frieda: Hiya! What day do\n"
# 476 "data/maps/Route32/scripts.pory"
	.string "you like?\p"
# 477 "data/maps/Route32/scripts.pory"
	.string "I love Friday. No doubt about\n"
# 478 "data/maps/Route32/scripts.pory"
	.string "it!\p"
# 479 "data/maps/Route32/scripts.pory"
	.string "Don't you think it's great too?$"
# 480 "data/maps/Route32/scripts.pory"

# 481 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaNope:
# 482 "data/maps/Route32/scripts.pory"
	.string "Frieda: Not that one!$"
# 483 "data/maps/Route32/scripts.pory"

# 484 "data/maps/Route32/scripts.pory"
Route32_Text_Sign1:
# 485 "data/maps/Route32/scripts.pory"
	.string "Route 32\p"
# 486 "data/maps/Route32/scripts.pory"
	.string "Violet City - Azalea Town$"
# 487 "data/maps/Route32/scripts.pory"

# 488 "data/maps/Route32/scripts.pory"
Route32_Text_Sign2:
# 489 "data/maps/Route32/scripts.pory"
	.string "Ruins Of Alph\n"
# 490 "data/maps/Route32/scripts.pory"
	.string "East Entrance$"
# 491 "data/maps/Route32/scripts.pory"

# 492 "data/maps/Route32/scripts.pory"
Route32_Text_Sign3:
# 493 "data/maps/Route32/scripts.pory"
	.string "Union Cave\n"
# 494 "data/maps/Route32/scripts.pory"
	.string "Ahead$"

Route32HiddenGrottoWarp::
# 498 "data/maps/Route32/scripts.pory"
	lock
# 499 "data/maps/Route32/scripts.pory"
	msgbox Route32HiddenGrottoWarp_Text_0, MSGBOX_YESNO
# 501 "data/maps/Route32/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route32HiddenGrottoWarp_2
Route32HiddenGrottoWarp_1:
# 505 "data/maps/Route32/scripts.pory"
	release
	end

Route32HiddenGrottoWarp_2:
# 502 "data/maps/Route32/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE32, 0
# 503 "data/maps/Route32/scripts.pory"
	waitstate
	goto Route32HiddenGrottoWarp_1


Route32RivalGrottoTutorial::
# 510 "data/maps/Route32/scripts.pory"
	lock
# 511 "data/maps/Route32/scripts.pory"
	createfieldmugshotrival
# 512 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_0
# 514 "data/maps/Route32/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 515 "data/maps/Route32/scripts.pory"
	closemessage
# 516 "data/maps/Route32/scripts.pory"
	removefieldmugshot
# 517 "data/maps/Route32/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 25, 25, DIR_SOUTH
# 518 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_0
# 519 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_1
# 520 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 521 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 522 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 523 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 524 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 525 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 526 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 527 "data/maps/Route32/scripts.pory"
	createfieldmugshotrival
# 528 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_1
# 529 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_2
# 536 "data/maps/Route32/scripts.pory"
	closemessage
# 537 "data/maps/Route32/scripts.pory"
	removefieldmugshot
# 538 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_3
# 539 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_4
# 540 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_PLAYER, Route32RivalGrottoTutorial_Movement_5
# 541 "data/maps/Route32/scripts.pory"
	waitmovement LOCALID_ROUTE32_MARILL
# 542 "data/maps/Route32/scripts.pory"
	createfieldmugshotrival
# 543 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_3
# 557 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_4
# 566 "data/maps/Route32/scripts.pory"
	closemessage
# 567 "data/maps/Route32/scripts.pory"
	removefieldmugshot
# 568 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_6
# 569 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_7
# 570 "data/maps/Route32/scripts.pory"
	waitmovement
# 571 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_8
# 572 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_9
# 573 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 574 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 575 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 576 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 577 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 578 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 579 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 580 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_10
# 581 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 582 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_RIVAL
# 583 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_MARILL
# 584 "data/maps/Route32/scripts.pory"
	setflag FLAG_HIDE_ROUTE32_RIVAL
# 585 "data/maps/Route32/scripts.pory"
	setflag FLAG_HIDE_NEWBARK_RIVAL
# 586 "data/maps/Route32/scripts.pory"
	setflag FLAG_HIDE_RIVAL_MARILL
# 587 "data/maps/Route32/scripts.pory"
	setvar VAR_RIVAL_STATE, 5
# 588 "data/maps/Route32/scripts.pory"
	savebgm MUS_DUMMY
# 589 "data/maps/Route32/scripts.pory"
	fadedefaultbgm
# 590 "data/maps/Route32/scripts.pory"
	release
	end


# 518 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_0:
# 518 "data/maps/Route32/scripts.pory"
	walk_up
# 518 "data/maps/Route32/scripts.pory"
	walk_up
# 518 "data/maps/Route32/scripts.pory"
	walk_up
# 518 "data/maps/Route32/scripts.pory"
	walk_up
# 518 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 519 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_1:
# 519 "data/maps/Route32/scripts.pory"
	walk_up
# 519 "data/maps/Route32/scripts.pory"
	walk_up
# 519 "data/maps/Route32/scripts.pory"
	walk_up
# 519 "data/maps/Route32/scripts.pory"
	walk_up
# 519 "data/maps/Route32/scripts.pory"
	walk_up
# 519 "data/maps/Route32/scripts.pory"
	walk_right
# 519 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 521 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_2:
# 521 "data/maps/Route32/scripts.pory"
	jump_in_place_up
	step_end

# 538 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_3:
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_left
# 538 "data/maps/Route32/scripts.pory"
	walk_up
# 538 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 539 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_4:
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_left
# 539 "data/maps/Route32/scripts.pory"
	walk_up
# 539 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 540 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_5:
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
# 540 "data/maps/Route32/scripts.pory"
	walk_left
	step_end

# 568 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_6:
# 568 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 569 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_7:
# 569 "data/maps/Route32/scripts.pory"
	walk_right
# 569 "data/maps/Route32/scripts.pory"
	face_down
	step_end

# 571 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_8:
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
# 571 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 572 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_9:
# 572 "data/maps/Route32/scripts.pory"
	walk_down
# 572 "data/maps/Route32/scripts.pory"
	walk_down
# 572 "data/maps/Route32/scripts.pory"
	walk_down
# 572 "data/maps/Route32/scripts.pory"
	walk_down
# 572 "data/maps/Route32/scripts.pory"
	face_up
	step_end

# 580 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_10:
# 580 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 580 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 580 "data/maps/Route32/scripts.pory"
	walk_fast_down
	step_end

Route32HiddenGrottoWarp_Text_0:
# 499 "data/maps/Route32/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Route32RivalGrottoTutorial_Text_0:
# 512 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}! I see you managed to get\n"
	.string "your first badge!$"

Route32RivalGrottoTutorial_Text_1:
# 528 "data/maps/Route32/scripts.pory"
	.string "Even Marill wanted to congratulate you!$"

Route32RivalGrottoTutorial_Text_2:
# 529 "data/maps/Route32/scripts.pory"
	.string "Listen, there's something you should\n"
	.string "see. \p"
	.string "I came across it when exploring\n"
	.string "the route. \p"
	.string "Follow me!$"

Route32RivalGrottoTutorial_Text_3:
# 543 "data/maps/Route32/scripts.pory"
	.string "See this small spot between the trees?\n"
	.string "It leads to a Hidden Grotto.\p"
	.string "I hear they may contain Pokémon that\n"
	.string "are sometimes quite rare, or items\l"
	.string "dropped by them.\p"
	.string "I'll let you explore\n"
	.string "this one, since it's your first time\l"
	.string "seeing one! \p"
	.string "Even if you don't manage to find\n"
	.string "a Pokémon there today, \l"
	.string "you should check it again another day.$"

Route32RivalGrottoTutorial_Text_4:
# 557 "data/maps/Route32/scripts.pory"
	.string "Marill and I decided to take on the gym\n"
	.string "challenge too!\p"
	.string "You better start\n"
	.string "training hard if you don't want to fall\l"
	.string "behind! \p"
	.string "Good luck with the\n"
	.string "next Gym, {PLAYER}!$"
