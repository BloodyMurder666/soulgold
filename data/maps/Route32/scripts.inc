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
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 89 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
# 90 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 91 "data/maps/Route32/scripts.pory"
	closemessage
# 92 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 93 "data/maps/Route32/scripts.pory"
	release
# 94 "data/maps/Route32/scripts.pory"
	end	
# 95 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail_Trigger2::
# 96 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 97 "data/maps/Route32/scripts.pory"
	closemessage
# 98 "data/maps/Route32/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 99 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
# 100 "data/maps/Route32/scripts.pory"
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
# 101 "data/maps/Route32/scripts.pory"
	setvar VAR_SLOWPOKE_TAIL, 1
# 102 "data/maps/Route32/scripts.pory"
	release
# 103 "data/maps/Route32/scripts.pory"
	end
# 104 "data/maps/Route32/scripts.pory"

# 105 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Left::
# 106 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 107 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 108 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 109 "data/maps/Route32/scripts.pory"
	return 
# 110 "data/maps/Route32/scripts.pory"

# 111 "data/maps/Route32/scripts.pory"
Route32_EventScript_Movement_Right::
# 112 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 113 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
# 115 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 116 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
# 117 "data/maps/Route32/scripts.pory"
	return 	
# 118 "data/maps/Route32/scripts.pory"

# 119 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail::
# 120 "data/maps/Route32/scripts.pory"
	lock
# 121 "data/maps/Route32/scripts.pory"
	faceplayer
# 122 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
# 123 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
# 124 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
# 125 "data/maps/Route32/scripts.pory"
	closemessage
# 126 "data/maps/Route32/scripts.pory"
	release
# 127 "data/maps/Route32/scripts.pory"
	end
# 128 "data/maps/Route32/scripts.pory"
Route32_EventScript_SlowpokeTail2::
# 129 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
# 130 "data/maps/Route32/scripts.pory"
	closemessage
# 131 "data/maps/Route32/scripts.pory"
	release
# 132 "data/maps/Route32/scripts.pory"
	end
# 133 "data/maps/Route32/scripts.pory"

# 134 "data/maps/Route32/scripts.pory"

# 135 "data/maps/Route32/scripts.pory"
Route32_EventScript_Frieda::
# 136 "data/maps/Route32/scripts.pory"
	lock
# 137 "data/maps/Route32/scripts.pory"
	faceplayer
# 138 "data/maps/Route32/scripts.pory"
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
# 139 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
# 140 "data/maps/Route32/scripts.pory"
	closemessage
# 141 "data/maps/Route32/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 142 "data/maps/Route32/scripts.pory"
	switch VAR_RESULT
# 143 "data/maps/Route32/scripts.pory"
	case 0, Route32_EventScript_FriedaNope
# 144 "data/maps/Route32/scripts.pory"
	case 1, Route32_EventScript_FriedaNope
# 145 "data/maps/Route32/scripts.pory"
	case 2, Route32_EventScript_FriedaNope
# 146 "data/maps/Route32/scripts.pory"
	case 3, Route32_EventScript_FriedaNope
# 147 "data/maps/Route32/scripts.pory"
	case 4, Route32_EventScript_FriedaNope
# 148 "data/maps/Route32/scripts.pory"
	case 5, Route32_EventScript_FriedaYes
# 149 "data/maps/Route32/scripts.pory"
	case 6, Route32_EventScript_FriedaNope
# 150 "data/maps/Route32/scripts.pory"
	case 7, Route32_EventScript_FriedaCancel
# 151 "data/maps/Route32/scripts.pory"
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
# 152 "data/maps/Route32/scripts.pory"
	closemessage
# 153 "data/maps/Route32/scripts.pory"
	release
# 154 "data/maps/Route32/scripts.pory"
	end
# 155 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaYes::
# 156 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
# 157 "data/maps/Route32/scripts.pory"
	giveitem ITEM_POISON_BARB
# 158 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 159 "data/maps/Route32/scripts.pory"
	setflag FLAG_GOT_POISON_BARB
# 160 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
# 161 "data/maps/Route32/scripts.pory"
	closemessage
# 162 "data/maps/Route32/scripts.pory"
	release
# 163 "data/maps/Route32/scripts.pory"
	end
# 164 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaNope::
# 165 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
# 166 "data/maps/Route32/scripts.pory"
	closemessage
# 167 "data/maps/Route32/scripts.pory"
	release
# 168 "data/maps/Route32/scripts.pory"
	end
# 169 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCancel::
# 170 "data/maps/Route32/scripts.pory"
	closemessage
# 171 "data/maps/Route32/scripts.pory"
	release
# 172 "data/maps/Route32/scripts.pory"
	end
# 173 "data/maps/Route32/scripts.pory"
Route32_EventScript_FriedaCompleted::
# 174 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
# 175 "data/maps/Route32/scripts.pory"
	closemessage
# 176 "data/maps/Route32/scripts.pory"
	release
# 177 "data/maps/Route32/scripts.pory"
	end
# 178 "data/maps/Route32/scripts.pory"

# 179 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingMan::
# 180 "data/maps/Route32/scripts.pory"
	lock
# 181 "data/maps/Route32/scripts.pory"
	faceplayer
# 182 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
# 183 "data/maps/Route32/scripts.pory"
	closemessage
# 184 "data/maps/Route32/scripts.pory"
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
# 185 "data/maps/Route32/scripts.pory"
	release
# 186 "data/maps/Route32/scripts.pory"
	end
# 187 "data/maps/Route32/scripts.pory"

# 188 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerLeft::
# 189 "data/maps/Route32/scripts.pory"
	lock
# 190 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 191 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 192 "data/maps/Route32/scripts.pory"
	delay 60
# 193 "data/maps/Route32/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 194 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 195 "data/maps/Route32/scripts.pory"
	end
# 196 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerMid::
# 197 "data/maps/Route32/scripts.pory"
	lock
# 198 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 199 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 200 "data/maps/Route32/scripts.pory"
	delay 60
# 201 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
# 202 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 203 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 204 "data/maps/Route32/scripts.pory"
	end
# 205 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTriggerRight::
# 206 "data/maps/Route32/scripts.pory"
	lock
# 207 "data/maps/Route32/scripts.pory"
	playse SE_PIN
# 208 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
# 209 "data/maps/Route32/scripts.pory"
	delay 60
# 210 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
# 211 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 212 "data/maps/Route32/scripts.pory"
	goto Route32_EventScript_BaldingManCheck
# 213 "data/maps/Route32/scripts.pory"
	end
# 214 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManCheck::
# 215 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
# 216 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
# 217 "data/maps/Route32/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
# 218 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
# 219 "data/maps/Route32/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 220 "data/maps/Route32/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 221 "data/maps/Route32/scripts.pory"
	closemessage
# 222 "data/maps/Route32/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 5
# 223 "data/maps/Route32/scripts.pory"
	release
# 224 "data/maps/Route32/scripts.pory"
	end
# 225 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManTower::
# 226 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 227 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
# 228 "data/maps/Route32/scripts.pory"
	closemessage
# 229 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 230 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 231 "data/maps/Route32/scripts.pory"
	release
# 232 "data/maps/Route32/scripts.pory"
	end
# 233 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManGym::
# 234 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 235 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
# 236 "data/maps/Route32/scripts.pory"
	closemessage
# 237 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 238 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 239 "data/maps/Route32/scripts.pory"
	release
# 240 "data/maps/Route32/scripts.pory"
	end
# 241 "data/maps/Route32/scripts.pory"
Route32_EventScript_BaldingManEgg::
# 242 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
# 243 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
# 244 "data/maps/Route32/scripts.pory"
	closemessage
# 245 "data/maps/Route32/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
# 246 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 247 "data/maps/Route32/scripts.pory"
	release
# 248 "data/maps/Route32/scripts.pory"
	end
# 249 "data/maps/Route32/scripts.pory"

# 250 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign1::
# 251 "data/maps/Route32/scripts.pory"
	lock
# 252 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
# 253 "data/maps/Route32/scripts.pory"
	closemessage
# 254 "data/maps/Route32/scripts.pory"
	release
# 255 "data/maps/Route32/scripts.pory"
	end
# 256 "data/maps/Route32/scripts.pory"

# 257 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign2::
# 258 "data/maps/Route32/scripts.pory"
	lock
# 259 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
# 260 "data/maps/Route32/scripts.pory"
	closemessage
# 261 "data/maps/Route32/scripts.pory"
	release
# 262 "data/maps/Route32/scripts.pory"
	end
# 263 "data/maps/Route32/scripts.pory"

# 264 "data/maps/Route32/scripts.pory"
Route32_EventScript_Sign3::
# 265 "data/maps/Route32/scripts.pory"
	lock
# 266 "data/maps/Route32/scripts.pory"
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
# 267 "data/maps/Route32/scripts.pory"
	closemessage
# 268 "data/maps/Route32/scripts.pory"
	release
# 269 "data/maps/Route32/scripts.pory"
	end
# 270 "data/maps/Route32/scripts.pory"

# 271 "data/maps/Route32/scripts.pory"
Route32_Movement_Turnback:
# 272 "data/maps/Route32/scripts.pory"
	walk_up
# 273 "data/maps/Route32/scripts.pory"
	step_end
# 274 "data/maps/Route32/scripts.pory"

# 275 "data/maps/Route32/scripts.pory"
Route32_Movement_StartMid:
# 276 "data/maps/Route32/scripts.pory"
	walk_left
# 277 "data/maps/Route32/scripts.pory"
	step_end
# 278 "data/maps/Route32/scripts.pory"

# 279 "data/maps/Route32/scripts.pory"
Route32_Movment_StartRight:
# 280 "data/maps/Route32/scripts.pory"
	walk_left
# 281 "data/maps/Route32/scripts.pory"
	walk_left
# 282 "data/maps/Route32/scripts.pory"
	step_end
# 283 "data/maps/Route32/scripts.pory"

# 284 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeLeft::
# 285 "data/maps/Route32/scripts.pory"
	step_end
# 286 "data/maps/Route32/scripts.pory"

# 287 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeMid::
# 288 "data/maps/Route32/scripts.pory"
	walk_right
# 289 "data/maps/Route32/scripts.pory"
	step_end
# 290 "data/maps/Route32/scripts.pory"

# 291 "data/maps/Route32/scripts.pory"
Route32_Movement_SlowpokeRight::
# 292 "data/maps/Route32/scripts.pory"
	walk_right
# 293 "data/maps/Route32/scripts.pory"
	walk_right
# 294 "data/maps/Route32/scripts.pory"
	step_end
# 295 "data/maps/Route32/scripts.pory"

# 296 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_WhatsTheHurry:
# 297 "data/maps/Route32/scripts.pory"
	.string "Wait up!\n"
# 298 "data/maps/Route32/scripts.pory"
	.string "What's the hurry?$"
# 299 "data/maps/Route32/scripts.pory"

# 300 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_AideIsWaiting:
# 301 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}, right?\n"
# 302 "data/maps/Route32/scripts.pory"
	.string "Some guy wearing glasses\p"
# 303 "data/maps/Route32/scripts.pory"
	.string "was looking for you.\p"
# 304 "data/maps/Route32/scripts.pory"
	.string "See for yourself. He's waiting for\n"
# 305 "data/maps/Route32/scripts.pory"
	.string "you at the Pokémon Center.$"
# 306 "data/maps/Route32/scripts.pory"

# 307 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_SproutTower:
# 308 "data/maps/Route32/scripts.pory"
	.string "Have you gone to Sprout Tower?\n"
# 309 "data/maps/Route32/scripts.pory"
	.string "If you ever visit Violet City,\p"
# 310 "data/maps/Route32/scripts.pory"
	.string "they'll expect you to train there.\n"
# 311 "data/maps/Route32/scripts.pory"
	.string "That's basic for trainers.\p"
# 312 "data/maps/Route32/scripts.pory"
	.string "Go to Sprout Tower!$"
# 313 "data/maps/Route32/scripts.pory"

# 314 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_VioletGym:
# 315 "data/maps/Route32/scripts.pory"
	.string "Have you gone to the Pokémon Gym?\n"
# 316 "data/maps/Route32/scripts.pory"
	.string "You can test your Pokémon and\p"
# 317 "data/maps/Route32/scripts.pory"
	.string "yourself there.\n"
# 318 "data/maps/Route32/scripts.pory"
	.string "It's a rite of passage for all\p"
# 319 "data/maps/Route32/scripts.pory"
	.string "trainers!$"
# 320 "data/maps/Route32/scripts.pory"

# 321 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_HaveThisSeed:
# 322 "data/maps/Route32/scripts.pory"
	.string "You have some good Pokémon there.\n"
# 323 "data/maps/Route32/scripts.pory"
	.string "It must be from the training you\p"
# 324 "data/maps/Route32/scripts.pory"
	.string "gave them around Violet City.\n"
# 325 "data/maps/Route32/scripts.pory"
	.string "The training at the Gym must have\p"
# 326 "data/maps/Route32/scripts.pory"
	.string "been especially helpful. As a\n"
# 327 "data/maps/Route32/scripts.pory"
	.string "souvenir of Violet City, take this.\p"
# 328 "data/maps/Route32/scripts.pory"
	.string "It increases the power of Grass-\n"
# 329 "data/maps/Route32/scripts.pory"
	.string "type moves.$"
# 330 "data/maps/Route32/scripts.pory"

# 331 "data/maps/Route32/scripts.pory"
Route32_Text_CooltrainerM_Experiences:
# 332 "data/maps/Route32/scripts.pory"
	.string "Your experiences in Violet City\n"
# 333 "data/maps/Route32/scripts.pory"
	.string "should be useful for your journey.$"
# 334 "data/maps/Route32/scripts.pory"

# 335 "data/maps/Route32/scripts.pory"
Route32_Text_SlowpokeTailOffer:
# 336 "data/maps/Route32/scripts.pory"
	.string "How would you like to have this\n"
# 337 "data/maps/Route32/scripts.pory"
	.string "tasty, nutritious Slowpoke Tail?\p"
# 338 "data/maps/Route32/scripts.pory"
	.string "For you right now, just\n"
# 339 "data/maps/Route32/scripts.pory"
	.string "¥1,000,000!\p"
# 340 "data/maps/Route32/scripts.pory"
	.string "You'll want this!$"
# 341 "data/maps/Route32/scripts.pory"

# 342 "data/maps/Route32/scripts.pory"
Route32_Text_ThoughtKidsLoaded:
# 343 "data/maps/Route32/scripts.pory"
	.string "Tch! I thought kids\n"
# 344 "data/maps/Route32/scripts.pory"
	.string "these days were loaded…$"
# 345 "data/maps/Route32/scripts.pory"

# 346 "data/maps/Route32/scripts.pory"
Route32_Text_RefusedSlowpokeTail:
# 347 "data/maps/Route32/scripts.pory"
	.string "You don't want it?\n"
# 348 "data/maps/Route32/scripts.pory"
	.string "Then scram. Shoo!$"
# 349 "data/maps/Route32/scripts.pory"

# 350 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Seen:
# 351 "data/maps/Route32/scripts.pory"
	.string "Whoa!\p"
# 352 "data/maps/Route32/scripts.pory"
	.string "You made me lose that fish!$"
# 353 "data/maps/Route32/scripts.pory"

# 354 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_Beaten:
# 355 "data/maps/Route32/scripts.pory"
	.string "Sploosh!$"
# 356 "data/maps/Route32/scripts.pory"

# 357 "data/maps/Route32/scripts.pory"
Route32_Text_FisherJustin_After:
# 358 "data/maps/Route32/scripts.pory"
	.string "Calm, collected… The essence of\n"
# 359 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon is the same.$"
# 360 "data/maps/Route32/scripts.pory"

# 361 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Seen:
# 362 "data/maps/Route32/scripts.pory"
	.string "I'm really good at both\n"
# 363 "data/maps/Route32/scripts.pory"
	.string "fishing and Pokémon.\p"
# 364 "data/maps/Route32/scripts.pory"
	.string "I'm not about to lose to any kid!$"
# 365 "data/maps/Route32/scripts.pory"

# 366 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_Beaten:
# 367 "data/maps/Route32/scripts.pory"
	.string "Tch! I tried to rush\n"
# 368 "data/maps/Route32/scripts.pory"
	.string "things…$"
# 369 "data/maps/Route32/scripts.pory"

# 370 "data/maps/Route32/scripts.pory"
Route32_Text_FisherRalph1_After:
# 371 "data/maps/Route32/scripts.pory"
	.string "Fishing is a lifelong\n"
# 372 "data/maps/Route32/scripts.pory"
	.string "passion.\p"
# 373 "data/maps/Route32/scripts.pory"
	.string "Pokémon are lifelong friends!$"
# 374 "data/maps/Route32/scripts.pory"

# 375 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Seen:
# 376 "data/maps/Route32/scripts.pory"
	.string "My Pokémon? Freshly caught!$"
# 377 "data/maps/Route32/scripts.pory"

# 378 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_Beaten:
# 379 "data/maps/Route32/scripts.pory"
	.string "Splash?$"
# 380 "data/maps/Route32/scripts.pory"

# 381 "data/maps/Route32/scripts.pory"
Route32_Text_FisherHenry_After:
# 382 "data/maps/Route32/scripts.pory"
	.string "Freshly caught Pokémon are\n"
# 383 "data/maps/Route32/scripts.pory"
	.string "no match for properly raised ones.$"
# 384 "data/maps/Route32/scripts.pory"

# 385 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Seen:
# 386 "data/maps/Route32/scripts.pory"
	.string "I haven't seen you around before.\n"
# 387 "data/maps/Route32/scripts.pory"
	.string "So you think you are pretty tough?$"
# 388 "data/maps/Route32/scripts.pory"

# 389 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_Beaten:
# 390 "data/maps/Route32/scripts.pory"
	.string "You're strong!$"
# 391 "data/maps/Route32/scripts.pory"

# 392 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterAlbert_After:
# 393 "data/maps/Route32/scripts.pory"
	.string "I'm going to try to be the\n"
# 394 "data/maps/Route32/scripts.pory"
	.string "best with my favorites.\p"
# 395 "data/maps/Route32/scripts.pory"
	.string "I'm not using the same tough\n"
# 396 "data/maps/Route32/scripts.pory"
	.string "Pokémon as everyone else.$"
# 397 "data/maps/Route32/scripts.pory"

# 398 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Seen:
# 399 "data/maps/Route32/scripts.pory"
	.string "I found some good Pokémon\n"
# 400 "data/maps/Route32/scripts.pory"
	.string "in the grass!\p"
# 401 "data/maps/Route32/scripts.pory"
	.string "I think they'll do it for me!$"
# 402 "data/maps/Route32/scripts.pory"

# 403 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_Beaten:
# 404 "data/maps/Route32/scripts.pory"
	.string "Darn. I thought I could win.$"
# 405 "data/maps/Route32/scripts.pory"

# 406 "data/maps/Route32/scripts.pory"
Route32_Text_YoungsterGordon_After:
# 407 "data/maps/Route32/scripts.pory"
	.string "The grass is full of\n"
# 408 "data/maps/Route32/scripts.pory"
	.string "clingy things.$"
# 409 "data/maps/Route32/scripts.pory"

# 410 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Seen:
# 411 "data/maps/Route32/scripts.pory"
	.string "That glance… It's intriguing.$"
# 412 "data/maps/Route32/scripts.pory"

# 413 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_Beaten:
# 414 "data/maps/Route32/scripts.pory"
	.string "Hmmm. This is disappointing.$"
# 415 "data/maps/Route32/scripts.pory"

# 416 "data/maps/Route32/scripts.pory"
Route32_Text_CamperRoland_After:
# 417 "data/maps/Route32/scripts.pory"
	.string "If you don't want to battle,\n"
# 418 "data/maps/Route32/scripts.pory"
	.string "just avoid eye contact.$"
# 419 "data/maps/Route32/scripts.pory"

# 420 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Seen:
# 421 "data/maps/Route32/scripts.pory"
	.string "Uh-huh. Yeah, and you know…\p"
# 422 "data/maps/Route32/scripts.pory"
	.string "Pardon? Battle? I'm on the phone.\n"
# 423 "data/maps/Route32/scripts.pory"
	.string "Oh, all right. But make it fast.$"
# 424 "data/maps/Route32/scripts.pory"

# 425 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_Beaten:
# 426 "data/maps/Route32/scripts.pory"
	.string "Oh! I've got to relieve\n"
# 427 "data/maps/Route32/scripts.pory"
	.string "my anger!$"
# 428 "data/maps/Route32/scripts.pory"

# 429 "data/maps/Route32/scripts.pory"
Route32_Text_PicnickerLiz1_After:
# 430 "data/maps/Route32/scripts.pory"
	.string "I was having a nice chat too.$"
# 431 "data/maps/Route32/scripts.pory"

# 432 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Seen:
# 433 "data/maps/Route32/scripts.pory"
	.string "That Badge! It's from Violet City!\n"
# 434 "data/maps/Route32/scripts.pory"
	.string "You beat Falkner?$"
# 435 "data/maps/Route32/scripts.pory"

# 436 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_Beaten:
# 437 "data/maps/Route32/scripts.pory"
	.string "I know what my weaknesses are.$"
# 438 "data/maps/Route32/scripts.pory"

# 439 "data/maps/Route32/scripts.pory"
Route32_Text_BirdKeeperPeter_After:
# 440 "data/maps/Route32/scripts.pory"
	.string "I should train again at the\n"
# 441 "data/maps/Route32/scripts.pory"
	.string "Gym in Violet City.$"
# 442 "data/maps/Route32/scripts.pory"

# 443 "data/maps/Route32/scripts.pory"
Route32_Text_RoarIntro:
# 444 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! People Run When I\n"
# 445 "data/maps/Route32/scripts.pory"
	.string "Roar! But You Came Looking!\p"
# 446 "data/maps/Route32/scripts.pory"
	.string "That Pleases Me! Now Take This!$"
# 447 "data/maps/Route32/scripts.pory"

# 448 "data/maps/Route32/scripts.pory"
Route32_Text_RoarOutro:
# 449 "data/maps/Route32/scripts.pory"
	.string "Wrooooar! It'S Roar!\p"
# 450 "data/maps/Route32/scripts.pory"
	.string "Even Pokémon Run From A Good\n"
# 451 "data/maps/Route32/scripts.pory"
	.string "Roar!$"
# 452 "data/maps/Route32/scripts.pory"

# 453 "data/maps/Route32/scripts.pory"
Route32_Text_MeetFrieda:
# 454 "data/maps/Route32/scripts.pory"
	.string "Frieda: Yahoo!\p"
# 455 "data/maps/Route32/scripts.pory"
	.string "I'm Frieda of the Weekday Family!\n"
# 456 "data/maps/Route32/scripts.pory"
	.string "Nice to meet you!\p"
# 457 "data/maps/Route32/scripts.pory"
	.string "If you can guess my favorite day,\n"
# 458 "data/maps/Route32/scripts.pory"
	.string "I'll give you a reward.$"
# 459 "data/maps/Route32/scripts.pory"

# 460 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGivesGift:
# 461 "data/maps/Route32/scripts.pory"
	.string "Here's a Poison Barb for you!$"
# 462 "data/maps/Route32/scripts.pory"

# 463 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaGaveGift:
# 464 "data/maps/Route32/scripts.pory"
	.string "Frieda: Give it to a Pokémon\n"
# 465 "data/maps/Route32/scripts.pory"
	.string "that has Poison-type moves.\p"
# 466 "data/maps/Route32/scripts.pory"
	.string "Oh!\p"
# 467 "data/maps/Route32/scripts.pory"
	.string "It's wicked!\p"
# 468 "data/maps/Route32/scripts.pory"
	.string "You'll be shocked how good it\n"
# 469 "data/maps/Route32/scripts.pory"
	.string "makes poison moves!$"
# 470 "data/maps/Route32/scripts.pory"

# 471 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaFriday:
# 472 "data/maps/Route32/scripts.pory"
	.string "Frieda: Hiya! What day do\n"
# 473 "data/maps/Route32/scripts.pory"
	.string "you like?\p"
# 474 "data/maps/Route32/scripts.pory"
	.string "I love Friday. No doubt about\n"
# 475 "data/maps/Route32/scripts.pory"
	.string "it!\p"
# 476 "data/maps/Route32/scripts.pory"
	.string "Don't you think it's great too?$"
# 477 "data/maps/Route32/scripts.pory"

# 478 "data/maps/Route32/scripts.pory"
Route32_Text_FriedaNope:
# 479 "data/maps/Route32/scripts.pory"
	.string "Frieda: Not that one!$"
# 480 "data/maps/Route32/scripts.pory"

# 481 "data/maps/Route32/scripts.pory"
Route32_Text_Sign1:
# 482 "data/maps/Route32/scripts.pory"
	.string "Route 32\p"
# 483 "data/maps/Route32/scripts.pory"
	.string "Violet City - Azalea Town$"
# 484 "data/maps/Route32/scripts.pory"

# 485 "data/maps/Route32/scripts.pory"
Route32_Text_Sign2:
# 486 "data/maps/Route32/scripts.pory"
	.string "Ruins Of Alph\n"
# 487 "data/maps/Route32/scripts.pory"
	.string "East Entrance$"
# 488 "data/maps/Route32/scripts.pory"

# 489 "data/maps/Route32/scripts.pory"
Route32_Text_Sign3:
# 490 "data/maps/Route32/scripts.pory"
	.string "Union Cave\n"
# 491 "data/maps/Route32/scripts.pory"
	.string "Ahead$"

Route32HiddenGrottoWarp::
# 495 "data/maps/Route32/scripts.pory"
	lock
# 496 "data/maps/Route32/scripts.pory"
	msgbox Route32HiddenGrottoWarp_Text_0, MSGBOX_YESNO
# 498 "data/maps/Route32/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route32HiddenGrottoWarp_2
Route32HiddenGrottoWarp_1:
# 502 "data/maps/Route32/scripts.pory"
	release
	end

Route32HiddenGrottoWarp_2:
# 499 "data/maps/Route32/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE32, 0
# 500 "data/maps/Route32/scripts.pory"
	waitstate
	goto Route32HiddenGrottoWarp_1


Route32RivalGrottoTutorial::
# 507 "data/maps/Route32/scripts.pory"
	lock
# 508 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_0
# 510 "data/maps/Route32/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 511 "data/maps/Route32/scripts.pory"
	closemessage
# 512 "data/maps/Route32/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 25, 25, DIR_SOUTH
# 513 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_0
# 514 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_1
# 515 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 516 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 517 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 518 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 519 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 520 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 521 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 522 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_1
# 523 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_2
# 526 "data/maps/Route32/scripts.pory"
	closemessage
# 527 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_3
# 528 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_4
# 529 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_PLAYER, Route32RivalGrottoTutorial_Movement_5
# 530 "data/maps/Route32/scripts.pory"
	waitmovement LOCALID_ROUTE32_MARILL
# 531 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_3
# 544 "data/maps/Route32/scripts.pory"
	msgbox Route32RivalGrottoTutorial_Text_4
# 548 "data/maps/Route32/scripts.pory"
	closemessage
# 549 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_6
# 550 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_7
# 551 "data/maps/Route32/scripts.pory"
	waitmovement
# 552 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_RIVAL, Route32RivalGrottoTutorial_Movement_8
# 553 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_9
# 554 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 555 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 556 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 557 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 558 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_2
# 559 "data/maps/Route32/scripts.pory"
	playse SE_LEDGE
# 560 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 561 "data/maps/Route32/scripts.pory"
	applymovement LOCALID_ROUTE32_MARILL, Route32RivalGrottoTutorial_Movement_10
# 562 "data/maps/Route32/scripts.pory"
	waitmovement 0
# 563 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_RIVAL
# 564 "data/maps/Route32/scripts.pory"
	removeobject LOCALID_ROUTE32_MARILL
# 565 "data/maps/Route32/scripts.pory"
	setflag FLAG_HIDE_ROUTE32_RIVAL
# 566 "data/maps/Route32/scripts.pory"
	setvar VAR_RIVAL_STATE, 5
# 567 "data/maps/Route32/scripts.pory"
	fadedefaultbgm
# 568 "data/maps/Route32/scripts.pory"
	release
	end


# 513 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_0:
# 513 "data/maps/Route32/scripts.pory"
	walk_up
# 513 "data/maps/Route32/scripts.pory"
	walk_up
# 513 "data/maps/Route32/scripts.pory"
	walk_up
# 513 "data/maps/Route32/scripts.pory"
	walk_up
# 513 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 514 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_1:
# 514 "data/maps/Route32/scripts.pory"
	walk_up
# 514 "data/maps/Route32/scripts.pory"
	walk_up
# 514 "data/maps/Route32/scripts.pory"
	walk_up
# 514 "data/maps/Route32/scripts.pory"
	walk_up
# 514 "data/maps/Route32/scripts.pory"
	walk_up
# 514 "data/maps/Route32/scripts.pory"
	walk_right
# 514 "data/maps/Route32/scripts.pory"
	walk_up
	step_end

# 516 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_2:
# 516 "data/maps/Route32/scripts.pory"
	jump_in_place_up
	step_end

# 527 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_3:
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_left
# 527 "data/maps/Route32/scripts.pory"
	walk_up
# 527 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 528 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_4:
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_left
# 528 "data/maps/Route32/scripts.pory"
	walk_up
# 528 "data/maps/Route32/scripts.pory"
	face_right
	step_end

# 529 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_5:
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
# 529 "data/maps/Route32/scripts.pory"
	walk_left
	step_end

# 549 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_6:
# 549 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 550 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_7:
# 550 "data/maps/Route32/scripts.pory"
	walk_right
# 550 "data/maps/Route32/scripts.pory"
	face_down
	step_end

# 552 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_8:
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
# 552 "data/maps/Route32/scripts.pory"
	walk_down
	step_end

# 553 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_9:
# 553 "data/maps/Route32/scripts.pory"
	walk_down
# 553 "data/maps/Route32/scripts.pory"
	walk_down
# 553 "data/maps/Route32/scripts.pory"
	walk_down
# 553 "data/maps/Route32/scripts.pory"
	walk_down
# 553 "data/maps/Route32/scripts.pory"
	face_up
	step_end

# 561 "data/maps/Route32/scripts.pory"
Route32RivalGrottoTutorial_Movement_10:
# 561 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 561 "data/maps/Route32/scripts.pory"
	walk_fast_down
# 561 "data/maps/Route32/scripts.pory"
	walk_fast_down
	step_end

Route32HiddenGrottoWarp_Text_0:
# 496 "data/maps/Route32/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

Route32RivalGrottoTutorial_Text_0:
# 508 "data/maps/Route32/scripts.pory"
	.string "{PLAYER}! I see you managed to get\n"
	.string "your first badge!$"

Route32RivalGrottoTutorial_Text_1:
# 522 "data/maps/Route32/scripts.pory"
	.string "Even Marill wanted to congratulate you!$"

Route32RivalGrottoTutorial_Text_2:
# 523 "data/maps/Route32/scripts.pory"
	.string "Listen, there's something you should\n"
	.string "see. I came across it when exploring\l"
	.string "the route. Follow me!$"

Route32RivalGrottoTutorial_Text_3:
# 531 "data/maps/Route32/scripts.pory"
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
# 544 "data/maps/Route32/scripts.pory"
	.string "Marill and I will take a trip to\n"
	.string "the Goldenrod City, I hope to see\l"
	.string "you there! Good luck with the\l"
	.string "next Gym, {PLAYER}!$"
