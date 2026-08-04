# 1 "data/maps/BattleCafe/scripts.pory"

# 2 "data/maps/BattleCafe/scripts.pory"
BattleCafe_MapScripts::
# 3 "data/maps/BattleCafe/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleCafe_OnTransition
# 4 "data/maps/BattleCafe/scripts.pory"
	.byte 0

BattleCafe_OnTransition::
# 8 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_HIDE_BATTLE_CAFE_OPPONENT
# 9 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_VISITED_ROUTE50
	end


BattleCafe_Owner::
# 14 "data/maps/BattleCafe/scripts.pory"
	lock
# 15 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 16 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 18 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_RECEIVED, BattleCafe_Owner_4
BattleCafe_Owner_1:
# 29 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_Owner_2:
# 27 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_GiveDiancie
	goto BattleCafe_Owner_1

BattleCafe_Owner_3:
# 20 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_MOIRA
	goto_if 1, BattleCafe_Owner_8
	goto BattleCafe_Owner_1

BattleCafe_Owner_4:
# 19 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_ASTRA
	goto_if 1, BattleCafe_Owner_3
	goto BattleCafe_Owner_1

BattleCafe_Owner_7:
# 22 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_DARIUS
	goto_if 1, BattleCafe_Owner_12
	goto BattleCafe_Owner_1

BattleCafe_Owner_8:
# 21 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_MAUGA
	goto_if 1, BattleCafe_Owner_7
	goto BattleCafe_Owner_1

BattleCafe_Owner_11:
# 24 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_LYSANDER
	goto_if 1, BattleCafe_Owner_16
	goto BattleCafe_Owner_1

BattleCafe_Owner_12:
# 23 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_IVY
	goto_if 1, BattleCafe_Owner_11
	goto BattleCafe_Owner_1

BattleCafe_Owner_15:
# 26 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_PHAINON
	goto_if 1, BattleCafe_Owner_2
	goto BattleCafe_Owner_1

BattleCafe_Owner_16:
# 25 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_JUNA
	goto_if 1, BattleCafe_Owner_15
	goto BattleCafe_Owner_1


BattleCafe_GiveDiancie::
# 33 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_READY, BattleCafe_GiveDiancie_2
BattleCafe_GiveDiancie_1:
# 48 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_2, MSGBOX_YESNO
# 52 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_GiveDiancie_5
BattleCafe_GiveDiancie_4:
# 58 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIANCIE
# 59 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIANCIE
# 60 "data/maps/BattleCafe/scripts.pory"
	givemon SPECIES_DIANCIE, 70
# 61 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_GiveDiancie_8
BattleCafe_GiveDiancie_7:
# 64 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 65 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 66 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 67 "data/maps/BattleCafe/scripts.pory"
	clearflag FLAG_BATTLE_CAFE_DIANCIE_READY
# 68 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_DIANCIE_RECEIVED
# 69 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_4
# 71 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_GiveDiancie_2:
# 34 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_0
# 40 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_1
# 44 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_DIANCIE_READY
# 45 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_GiveDiancie_1

BattleCafe_GiveDiancie_5:
# 53 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_3
# 55 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_GiveDiancie_4

BattleCafe_GiveDiancie_8:
# 62 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_GiveDiancie_7


BattleCafe_OwnerMenu::
# 75 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_CAFE_INTRO_DONE, BattleCafe_OwnerMenu_2
BattleCafe_OwnerMenu_1:
# 88 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_1
# 89 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_2, BattleCafe_OwnerMenu_Text_3, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_8
# 97 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 98 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OwnerMenu_5
# 99 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OwnerMenu_6
# 100 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OwnerMenu_7
# 101 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OwnerMenu_8
# 102 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_OwnerMenu_9
# 103 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_OwnerMenu_10
# 104 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_Goodbye
	return

BattleCafe_OwnerMenu_2:
# 76 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_0
# 86 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_CAFE_INTRO_DONE
	goto BattleCafe_OwnerMenu_1

BattleCafe_OwnerMenu_5:
# 98 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskDailyChallenge
	return

BattleCafe_OwnerMenu_6:
# 99 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskRushMode
	return

BattleCafe_OwnerMenu_7:
# 100 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperChallenge
	return

BattleCafe_OwnerMenu_8:
# 101 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperRush
	return

BattleCafe_OwnerMenu_9:
# 102 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_OwnerMenu_10:
# 103 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainRules
	return


BattleCafe_ExplainRules::
# 109 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_0
# 119 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_1
# 126 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_2
# 134 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_3
# 141 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_AskDailyChallenge::
# 145 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON, BattleCafe_AskDailyChallenge_2
BattleCafe_AskDailyChallenge_1:
# 153 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_1, MSGBOX_YESNO
# 160 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskDailyChallenge_5
BattleCafe_AskDailyChallenge_4:
# 163 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
# 164 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskDailyChallenge_2:
# 146 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_0
# 151 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_1

BattleCafe_AskDailyChallenge_5:
# 161 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_4


BattleCafe_AskRushMode::
# 168 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_RUSH_WON, BattleCafe_AskRushMode_2
BattleCafe_AskRushMode_1:
# 176 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_1, MSGBOX_YESNO
# 183 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskRushMode_5
BattleCafe_AskRushMode_4:
# 186 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
# 187 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskRushMode_2:
# 169 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_0
# 174 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_1

BattleCafe_AskRushMode_5:
# 184 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_4


BattleCafe_AskSuperChallenge::
# 191 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_AskSuperChallenge_2
BattleCafe_AskSuperChallenge_1:
# 199 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 200 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperChallenge_5
BattleCafe_AskSuperChallenge_4:
# 206 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_2, MSGBOX_YESNO
# 212 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperChallenge_8
BattleCafe_AskSuperChallenge_7:
# 215 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
# 216 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperChallenge_2:
# 192 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_0
# 197 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_1

BattleCafe_AskSuperChallenge_5:
# 201 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_1
# 204 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_4

BattleCafe_AskSuperChallenge_8:
# 213 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_7


BattleCafe_AskSuperRush::
# 220 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_AskSuperRush_2
BattleCafe_AskSuperRush_1:
# 228 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 229 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperRush_5
BattleCafe_AskSuperRush_4:
# 237 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_2, MSGBOX_YESNO
# 244 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperRush_8
BattleCafe_AskSuperRush_7:
# 247 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
# 248 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperRush_2:
# 221 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_0
# 226 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_1

BattleCafe_AskSuperRush_5:
# 230 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_1
# 235 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_4

BattleCafe_AskSuperRush_8:
# 245 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_7


BattleCafe_BeginChallenge::
# 252 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 253 "data/maps/BattleCafe/scripts.pory"
	hidefollower
# 254 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 255 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_InitChallenge
# 256 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 13, DIR_EAST
# 257 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 258 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_9, 0
# 259 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_0
# 261 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 262 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return


BattleCafe_ChallengeNextRound::
# 266 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_RunRound
# 267 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChallengeNextRound_2
BattleCafe_ChallengeNextRound_1:
# 271 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_TEMP_9, 1
# 272 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_9, 3
	goto_if_ge BattleCafe_ChallengeNextRound_5
BattleCafe_ChallengeNextRound_4:
# 276 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeNextRound_8
# 282 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_11
# 288 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_14
# 292 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_3
BattleCafe_ChallengeNextRound_7:
# 297 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 298 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_ChallengeNextRound_2:
# 268 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeLost
	goto BattleCafe_ChallengeNextRound_1

BattleCafe_ChallengeNextRound_5:
# 273 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeWon
	goto BattleCafe_ChallengeNextRound_4

BattleCafe_ChallengeNextRound_8:
# 277 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 278 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 279 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_0
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_11:
# 283 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 284 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 285 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_1
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_14:
# 289 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_2
	goto BattleCafe_ChallengeNextRound_7


BattleCafe_RunRound::
# 302 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_9
# 303 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_SelectOpponent
# 304 "data/maps/BattleCafe/scripts.pory"
	setobjectxy LOCALID_BATTLE_CAFE_OPPONENT, 14, 17
# 305 "data/maps/BattleCafe/scripts.pory"
	addobject LOCALID_BATTLE_CAFE_OPPONENT
# 306 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 10, 13, DIR_WEST
# 307 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 308 "data/maps/BattleCafe/scripts.pory"
	tower_getopponentintro FRONTIER_BEFORE_TEXT
# 309 "data/maps/BattleCafe/scripts.pory"
	msgbox gStringVar4
# 310 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 311 "data/maps/BattleCafe/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_CAFE
# 312 "data/maps/BattleCafe/scripts.pory"
	waitstate
# 313 "data/maps/BattleCafe/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 314 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 316 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 14, 17, DIR_EAST
# 317 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 318 "data/maps/BattleCafe/scripts.pory"
	removeobject LOCALID_BATTLE_CAFE_OPPONENT
# 320 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_A, B_OUTCOME_WON
	goto_if_eq BattleCafe_RunRound_2
# 323 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, FALSE
BattleCafe_RunRound_1:
	return

BattleCafe_RunRound_2:
# 321 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, TRUE
	goto BattleCafe_RunRound_1


BattleCafe_ChallengeLost::
# 329 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 330 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 331 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 332 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 333 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 334 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_0
# 340 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ChallengeWon::
# 344 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 345 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 346 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 347 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 348 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 350 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeWon_2
# 357 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto_if_eq BattleCafe_ChallengeWon_5
# 365 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeWon_8
# 373 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON
# 374 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_BATTLE_CAFE_POINTS, 10
# 375 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_3
BattleCafe_ChallengeWon_1:
# 385 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 386 "data/maps/BattleCafe/scripts.pory"
	waitse
# 387 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeWon_2:
# 351 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON
# 352 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_BATTLE_CAFE_POINTS, 3
# 353 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_0
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_5:
# 358 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_RUSH_WON
# 359 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_BATTLE_CAFE_POINTS, 5
# 360 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_1
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_8:
# 366 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON
# 367 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_BATTLE_CAFE_POINTS, 5
# 368 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_2
	goto BattleCafe_ChallengeWon_1


BattleCafe_RewardMenu::
# 391 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_BATTLE_CAFE_POINTS
# 392 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_RewardMenu_Text_0
# 394 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_RewardMenu_Text_1, BattleCafe_RewardMenu_Text_2, BattleCafe_RewardMenu_Text_3, BattleCafe_RewardMenu_Text_4, BattleCafe_RewardMenu_Text_5, BattleCafe_RewardMenu_Text_6, BattleCafe_RewardMenu_Text_7
# 402 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 403 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_RewardMenu_2
# 404 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_RewardMenu_3
# 405 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_RewardMenu_4
# 406 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_RewardMenu_5
# 407 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_RewardMenu_6
# 408 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_RewardMenu_7
# 409 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
# 403 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_3:
# 404 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_4:
# 405 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_5:
# 406 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_6:
# 407 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_7:
# 408 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoney
	return


BattleCafe_ChooseArticuno::
# 414 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
# 419 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
# 420 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 421 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
# 415 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseArticuno_Text_0
# 417 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
# 425 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
# 430 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
# 431 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 432 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
# 426 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseZapdos_Text_0
# 428 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
# 436 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
# 441 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
# 442 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 2
# 443 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
# 437 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoltres_Text_0
# 439 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ConfirmRewardMon::
# 447 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
# 450 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 451 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
# 453 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
# 457 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 458 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_8
BattleCafe_ConfirmRewardMon_7:
# 461 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 462 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 463 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 464 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 465 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 466 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmRewardMon_12
# 467 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmRewardMon_13
# 468 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_ConfirmRewardMon_14
BattleCafe_ConfirmRewardMon_10:
# 470 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_1
# 472 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
# 448 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
# 454 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
# 459 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_12:
# 466 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_13:
# 467 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_14:
# 468 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10


BattleCafe_ChooseShinyGenome::
# 476 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
# 479 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
# 481 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
# 484 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_SHIN_GENOME, 1
# 485 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
# 488 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 489 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
# 492 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 4
# 493 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_1
# 496 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
# 477 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
# 482 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
# 486 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
# 490 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
# 500 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
# 503 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
# 505 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
# 508 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
# 509 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
# 512 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
# 513 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
# 516 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 517 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
# 520 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
# 501 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
# 506 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
# 510 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
# 514 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
# 524 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
# 527 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
# 529 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
# 532 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 533 "data/maps/BattleCafe/scripts.pory"
	showmoneybox 0, 0
# 534 "data/maps/BattleCafe/scripts.pory"
	addmoney 250000
# 535 "data/maps/BattleCafe/scripts.pory"
	updatemoneybox 0
# 536 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 537 "data/maps/BattleCafe/scripts.pory"
	waitse
# 538 "data/maps/BattleCafe/scripts.pory"
	hidemoneybox
# 539 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_1
# 541 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
# 525 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
# 530 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_NotEnoughPoints::
# 545 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughPoints_Text_0
# 548 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
# 552 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
# 555 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
# 559 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
# 562 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
# 566 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_Goodbye_Text_0
# 567 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerAstra::
# 572 "data/maps/BattleCafe/scripts.pory"
	lock
# 573 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 574 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 575 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ASTRA, BattleCafe_TrainerAstra_2
# 583 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ASTRA
# 584 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAstra_Text_1
# 587 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ASTRA, BattleCafe_TrainerAstra_Text_2
# 588 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAstra_Text_3
# 591 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAstra_2:
# 576 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAstra_Text_0
# 580 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerMora::
# 596 "data/maps/BattleCafe/scripts.pory"
	lock
# 597 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 598 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 599 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_MOIRA, BattleCafe_TrainerMora_2
# 606 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_MOIRA
# 607 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMora_Text_1
# 610 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_MOIRA, BattleCafe_TrainerMora_Text_2
# 611 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMora_Text_3
# 614 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerMora_2:
# 600 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMora_Text_0
# 603 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerRook::
# 619 "data/maps/BattleCafe/scripts.pory"
	lock
# 620 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 621 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 622 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_MAUGA, BattleCafe_TrainerRook_2
# 629 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_MAUGA
# 630 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerRook_Text_1
# 633 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_MAUGA, BattleCafe_TrainerRook_Text_2
# 634 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerRook_Text_3
# 636 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerRook_2:
# 623 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerRook_Text_0
# 626 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDarius::
# 641 "data/maps/BattleCafe/scripts.pory"
	lock
# 642 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 643 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 644 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DARIUS, BattleCafe_TrainerDarius_2
# 651 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DARIUS
# 652 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDarius_Text_1
# 655 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DARIUS, BattleCafe_TrainerDarius_Text_2
# 657 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDarius_Text_3
# 660 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDarius_2:
# 645 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDarius_Text_0
# 648 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerIvy::
# 665 "data/maps/BattleCafe/scripts.pory"
	lock
# 666 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 667 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 668 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_IVY, BattleCafe_TrainerIvy_2
# 674 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_IVY
# 675 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIvy_Text_1
# 678 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_IVY, BattleCafe_TrainerIvy_Text_2
# 679 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIvy_Text_3
# 681 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerIvy_2:
# 669 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIvy_Text_0
# 671 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerIgnis::
# 686 "data/maps/BattleCafe/scripts.pory"
	lock
# 687 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 688 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 689 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_LYSANDER, BattleCafe_TrainerIgnis_2
# 696 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_LYSANDER
# 697 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIgnis_Text_1
# 700 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_LYSANDER, BattleCafe_TrainerIgnis_Text_2
# 701 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIgnis_Text_3
# 703 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerIgnis_2:
# 690 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerIgnis_Text_0
# 693 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerMarina::
# 708 "data/maps/BattleCafe/scripts.pory"
	lock
# 709 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 710 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 711 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_JUNA, BattleCafe_TrainerMarina_2
# 717 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_JUNA
# 718 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_1
# 720 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerMarina_Text_2
# 721 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_3
# 723 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerMarina_2:
# 712 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_0
# 714 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerAtlas::
# 728 "data/maps/BattleCafe/scripts.pory"
	lock
# 729 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 730 "data/maps/BattleCafe/scripts.pory"
	dotimebasedevents
# 731 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_PHAINON, BattleCafe_TrainerAtlas_2
# 738 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_PHAINON
# 739 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAtlas_Text_1
# 742 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_PHAINON, BattleCafe_TrainerAtlas_Text_2
# 743 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAtlas_Text_3
# 746 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAtlas_2:
# 732 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAtlas_Text_0
# 735 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDiancie_Text_0:
# 34 "data/maps/BattleCafe/scripts.pory"
	.string "Well, look at that. You've beaten\n"
	.string "every one of my regulars at least\l"
	.string "once.\p"
	.string "Seems only right you leave with a\n"
	.string "rare dining companion: Diancie!$"

BattleCafe_GiveDiancie_Text_1:
# 40 "data/maps/BattleCafe/scripts.pory"
	.string "It'll be waiting right here. Make\n"
	.string "whatever preparations you need, then\l"
	.string "come talk to me when you're ready to\l"
	.string "welcome it aboard.$"

BattleCafe_GiveDiancie_Text_2:
# 48 "data/maps/BattleCafe/scripts.pory"
	.string "Diancie is waiting for you.\p"
	.string "Are you ready to receive it?$"

BattleCafe_GiveDiancie_Text_3:
# 53 "data/maps/BattleCafe/scripts.pory"
	.string "No rush. Diancie will be right\n"
	.string "here whenever you're ready.$"

BattleCafe_GiveDiancie_Text_4:
# 69 "data/maps/BattleCafe/scripts.pory"
	.string "Diancie's a fine addition to the menu.\n"
	.string "Take good care of it!$"

BattleCafe_OwnerMenu_Text_0:
# 76 "data/maps/BattleCafe/scripts.pory"
	.string "Welcome to my Battle Café!\p"
	.string "I picked up my recipes and my battling\n"
	.string "chops back home in Galar.\p"
	.string "These days I bring Trainers together\n"
	.string "for good food and good battles, right\l"
	.string "here in Johto.\p"
	.string "Anyway, enough about me...$"

BattleCafe_OwnerMenu_Text_1:
# 88 "data/maps/BattleCafe/scripts.pory"
	.string "Welcome! What'll it be today?$"

BattleCafe_OwnerMenu_Text_2:
# 90 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge$"

BattleCafe_OwnerMenu_Text_3:
# 91 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode$"

BattleCafe_OwnerMenu_Text_4:
# 92 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge$"

BattleCafe_OwnerMenu_Text_5:
# 93 "data/maps/BattleCafe/scripts.pory"
	.string "Super Rush$"

BattleCafe_OwnerMenu_Text_6:
# 94 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange Points$"

BattleCafe_OwnerMenu_Text_7:
# 95 "data/maps/BattleCafe/scripts.pory"
	.string "Café Rules$"

BattleCafe_OwnerMenu_Text_8:
# 96 "data/maps/BattleCafe/scripts.pory"
	.string "Leave$"

BattleCafe_ExplainRules_Text_0:
# 109 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors will answer each\n"
	.string "challenge, one after another.\p"
	.string "In the Daily Challenge, they bring\n"
	.string "dependable teams of four.\p"
	.string "I'll tend to your Pokémon after each\n"
	.string "battle.\p"
	.string "Win all three for 3 Café Points.$"

BattleCafe_ExplainRules_Text_1:
# 119 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode draws seasoned battlers with\n"
	.string "teams of four.\p"
	.string "Anything goes, and I can't heal\n"
	.string "your Pokémon between the matches.\p"
	.string "Win all three for 5 points.$"

BattleCafe_ExplainRules_Text_2:
# 126 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge and Super Rush pit\n"
	.string "you against full teams of six Pokémon.\p"
	.string "Anyone might show up so prepare to\n"
	.string "face literally anything.\p"
	.string "Same rules apply here for healing\n"
	.string "between the rounds.$"

BattleCafe_ExplainRules_Text_3:
# 134 "data/maps/BattleCafe/scripts.pory"
	.string "There are no breaks once service\n"
	.string "begins.\p"
	.string "A loss ends the run, though\n"
	.string "you may retry until you win.\p"
	.string "Each challenge can be won once per day.$"

BattleCafe_AskDailyChallenge_Text_0:
# 146 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Daily Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or try another challenge!$"

BattleCafe_AskDailyChallenge_Text_1:
# 153 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors are ready with\n"
	.string "teams of four.\p"
	.string "I'll tend to your party\n"
	.string "after rounds one and two.\p"
	.string "Begin today's challenge?$"

BattleCafe_AskRushMode_Text_0:
# 169 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Rush Mode\n"
	.string "today.\p"
	.string "Come back tomorrow, or take\n"
	.string "another challenge!$"

BattleCafe_AskRushMode_Text_1:
# 176 "data/maps/BattleCafe/scripts.pory"
	.string "Three seasoned visitors are waiting\n"
	.string "with teams of four.\p"
	.string "I can't tend to\n"
	.string "your party between these battles.\p"
	.string "Begin today's rush?$"

BattleCafe_AskSuperChallenge_Text_0:
# 192 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Super Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or attempt another challenge!$"

BattleCafe_AskSuperChallenge_Text_1:
# 201 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Challenge. Bring a full party of six\l"
	.string "before entering.$"

BattleCafe_AskSuperChallenge_Text_2:
# 206 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each meet your full\n"
	.string "party with six Pokémon of their own.\p"
	.string "I'll tend to your team between battles.\p"
	.string "Begin the Super Challenge?$"

BattleCafe_AskSuperRush_Text_0:
# 221 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Super Rush\n"
	.string "today.\p"
	.string "Come back tomorrow for\n"
	.string "another full-team trial!$"

BattleCafe_AskSuperRush_Text_1:
# 230 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Rush.\p"
	.string "Bring a full party of six\n"
	.string "before entering.$"

BattleCafe_AskSuperRush_Text_2:
# 237 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each bring a full\n"
	.string "team of six.\p"
	.string "Once the rush begins, I can't heal\n"
	.string "your Pokémon between the battles.\p"
	.string "Begin the Super Rush?$"

BattleCafe_BeginChallenge_Text_0:
# 259 "data/maps/BattleCafe/scripts.pory"
	.string "Three courses. Three opponents.\n"
	.string "Service begins now!$"

BattleCafe_ChallengeNextRound_Text_0:
# 279 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next challenger is arriving!$"

BattleCafe_ChallengeNextRound_Text_1:
# 285 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_2:
# 289 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Super Rush!\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_3:
# 292 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Rush Mode!\n"
	.string "The next challenger is arriving!$"

BattleCafe_ChallengeLost_Text_0:
# 334 "data/maps/BattleCafe/scripts.pory"
	.string "Tough course, huh? I've fully restored\n"
	.string "your party.\p"
	.string "Catch your breath, rework\n"
	.string "your strategy, and come at it again\l"
	.string "whenever you like!$"

BattleCafe_ChallengeWon_Text_0:
# 353 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge complete!\p"
	.string "That's 3 Café Points for you.$"

BattleCafe_ChallengeWon_Text_1:
# 360 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode complete! That took\n"
	.string "some real grit.\p"
	.string "Here's 5 Café Points.$"

BattleCafe_ChallengeWon_Text_2:
# 368 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge complete!\n"
	.string "Full team, full effort!\p"
	.string "that's 5 Café Points.$"

BattleCafe_ChallengeWon_Text_3:
# 375 "data/maps/BattleCafe/scripts.pory"
	.string "Incredible! You have beaten\n"
	.string "the Super Rush mode!\p"
	.string "I can hardly believe it!\p"
	.string "Here's your reward of\n"
	.string "10 Café Points.$"

BattleCafe_RewardMenu_Text_0:
# 392 "data/maps/BattleCafe/scripts.pory"
	.string "You have {STR_VAR_1} Café Points.\n"
	.string "Anything you want to exchange for?$"

BattleCafe_RewardMenu_Text_1:
# 395 "data/maps/BattleCafe/scripts.pory"
	.string "G. Articuno - 5$"

BattleCafe_RewardMenu_Text_2:
# 396 "data/maps/BattleCafe/scripts.pory"
	.string "G. Zapdos - 5$"

BattleCafe_RewardMenu_Text_3:
# 397 "data/maps/BattleCafe/scripts.pory"
	.string "G. Moltres - 5$"

BattleCafe_RewardMenu_Text_4:
# 398 "data/maps/BattleCafe/scripts.pory"
	.string "Shiny Genome - 3$"

BattleCafe_RewardMenu_Text_5:
# 399 "data/maps/BattleCafe/scripts.pory"
	.string "2 Gold Caps - 3$"

BattleCafe_RewardMenu_Text_6:
# 400 "data/maps/BattleCafe/scripts.pory"
	.string "¥250,000 - 3$"

BattleCafe_RewardMenu_Text_7:
# 401 "data/maps/BattleCafe/scripts.pory"
	.string "Back$"

BattleCafe_ChooseArticuno_Text_0:
# 415 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Articuno to you.$"

BattleCafe_ChooseZapdos_Text_0:
# 426 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Zapdos to you.$"

BattleCafe_ChooseMoltres_Text_0:
# 437 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Moltres to you.$"

BattleCafe_ConfirmRewardMon_Text_0:
# 451 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmRewardMon_Text_1:
# 470 "data/maps/BattleCafe/scripts.pory"
	.string "A fair trade. I'm sure it'll fit right\n"
	.string "into your team.$"

BattleCafe_ChooseShinyGenome_Text_0:
# 479 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for a\n"
	.string "Shiny Genome?$"

BattleCafe_ChooseShinyGenome_Text_1:
# 493 "data/maps/BattleCafe/scripts.pory"
	.string "A rare find. Use it on whichever\n"
	.string "Pokémon you want to bring out the\l"
	.string "shine in.$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
# 503 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for two\n"
	.string "Gold Bottle Caps?$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
# 517 "data/maps/BattleCafe/scripts.pory"
	.string "Two Gold Bottle Caps, polished up and\n"
	.string "ready. They'll bring out the very\l"
	.string "best in your Pokémon.$"

BattleCafe_ChooseMoney_Text_0:
# 527 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "¥250,000?$"

BattleCafe_ChooseMoney_Text_1:
# 539 "data/maps/BattleCafe/scripts.pory"
	.string "Use it well, and perhaps spend a little\n"
	.string "on dessert!$"

BattleCafe_NotEnoughPoints_Text_0:
# 545 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 5 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughFourPoints_Text_0:
# 552 "data/maps/BattleCafe/scripts.pory"
	.string "The Shiny Genome costs 4 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughBagSpace_Text_0:
# 559 "data/maps/BattleCafe/scripts.pory"
	.string "Your Bag is too full for that prize.\n"
	.string "Make some room and come back whenever\l"
	.string "you're ready!$"

BattleCafe_Goodbye_Text_0:
# 566 "data/maps/BattleCafe/scripts.pory"
	.string "Come back hungry for another battle!$"

BattleCafe_TrainerAstra_Text_0:
# 576 "data/maps/BattleCafe/scripts.pory"
	.string "Ninetales has curled up by\n"
	.string "the stove.\p"
	.string "We'll bring the snow again tomorrow!$"

BattleCafe_TrainerAstra_Text_1:
# 584 "data/maps/BattleCafe/scripts.pory"
	.string "Ninetales called down the\n"
	.string "snow! Let's see how well your team\l"
	.string "handles the cold!$"

BattleCafe_TrainerAstra_Text_2:
# 587 "data/maps/BattleCafe/scripts.pory"
	.string "Even Aurora Veil couldn't save me from that!$"

BattleCafe_TrainerAstra_Text_3:
# 588 "data/maps/BattleCafe/scripts.pory"
	.string "Your Pokémon never lost their footing\n"
	.string "in the blizzard. They trust you\l"
	.string "completely.$"

BattleCafe_TrainerMora_Text_0:
# 600 "data/maps/BattleCafe/scripts.pory"
	.string "Farigiraf says time is\n"
	.string "flowing normally again. Come back\l"
	.string "tomorrow!$"

BattleCafe_TrainerMora_Text_1:
# 607 "data/maps/BattleCafe/scripts.pory"
	.string "Farigiraf, twist the dimensions!\n"
	.string "Let's make slow Pokémon the stars for\l"
	.string "once.$"

BattleCafe_TrainerMora_Text_2:
# 610 "data/maps/BattleCafe/scripts.pory"
	.string "You're a tricky customer, huh.$"

BattleCafe_TrainerMora_Text_3:
# 611 "data/maps/BattleCafe/scripts.pory"
	.string "Ursaluna's never minded moving last,\n"
	.string "but today you were always a step\l"
	.string "ahead of it.$"

BattleCafe_TrainerRook_Text_0:
# 623 "data/maps/BattleCafe/scripts.pory"
	.string "Meowscarada and Skeledirge\n"
	.string "are sharing a table. Rematch\l"
	.string "tomorrow!$"

BattleCafe_TrainerRook_Text_1:
# 630 "data/maps/BattleCafe/scripts.pory"
	.string "My team never battles the same\n"
	.string "way twice. Ready for a few\l"
	.string "surprises?$"

BattleCafe_TrainerRook_Text_2:
# 633 "data/maps/BattleCafe/scripts.pory"
	.string "I got played!$"

BattleCafe_TrainerRook_Text_3:
# 634 "data/maps/BattleCafe/scripts.pory"
	.string "Even Sableye's impressed, and it\n"
	.string "barely takes anything seriously.$"

BattleCafe_TrainerDarius_Text_0:
# 645 "data/maps/BattleCafe/scripts.pory"
	.string "Scizor's polishing its\n"
	.string "pincers. We'll strike again\l"
	.string "tomorrow!$"

BattleCafe_TrainerDarius_Text_1:
# 652 "data/maps/BattleCafe/scripts.pory"
	.string "Rillaboom sets the rhythm,\n"
	.string "then my whole team strikes. Think\l"
	.string "you can keep up?$"

BattleCafe_TrainerDarius_Text_2:
# 655 "data/maps/BattleCafe/scripts.pory"
	.string "Not even my Kingambit could turn\n"
	.string "that one around.$"

BattleCafe_TrainerDarius_Text_3:
# 657 "data/maps/BattleCafe/scripts.pory"
	.string "Your Pokémon held their ground\n"
	.string "against every quick attack we threw.\l"
	.string "Nice work.$"

BattleCafe_TrainerIvy_Text_0:
# 669 "data/maps/BattleCafe/scripts.pory"
	.string "Glimmora needs time to grow\n"
	.string "fresh crystals. Tomorrow!$"

BattleCafe_TrainerIvy_Text_1:
# 675 "data/maps/BattleCafe/scripts.pory"
	.string "Glimmora and Samurott have set\n"
	.string "up quite a welcome for you. Watch\l"
	.string "your footing.$"

BattleCafe_TrainerIvy_Text_2:
# 678 "data/maps/BattleCafe/scripts.pory"
	.string "You cleared every hazard I laid out?!$"

BattleCafe_TrainerIvy_Text_3:
# 679 "data/maps/BattleCafe/scripts.pory"
	.string "Gholdengo hates admitting defeat, but\n"
	.string "even it knows you earned that one.$"

BattleCafe_TrainerIgnis_Text_0:
# 690 "data/maps/BattleCafe/scripts.pory"
	.string "Charizard's warming\n"
	.string "itself by the ovens. We'll blaze\l"
	.string "again tomorrow!$"

BattleCafe_TrainerIgnis_Text_1:
# 697 "data/maps/BattleCafe/scripts.pory"
	.string "Ninetales brought the sun,\n"
	.string "and Charizard brought the heat.\l"
	.string "Let's battle!$"

BattleCafe_TrainerIgnis_Text_2:
# 700 "data/maps/BattleCafe/scripts.pory"
	.string "You outlasted my whole team.$"

BattleCafe_TrainerIgnis_Text_3:
# 701 "data/maps/BattleCafe/scripts.pory"
	.string "Venusaur thrives in sunlight, but\n"
	.string "your Pokémon shone brighter today.$"

BattleCafe_TrainerMarina_Text_0:
# 712 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper says the rain has\n"
	.string "passed for today. Tomorrow!$"

BattleCafe_TrainerMarina_Text_1:
# 718 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper, call in the rain!\n"
	.string "Let's make some waves.$"

BattleCafe_TrainerMarina_Text_2:
# 720 "data/maps/BattleCafe/scripts.pory"
	.string "You weathered the whole storm.$"

BattleCafe_TrainerMarina_Text_3:
# 721 "data/maps/BattleCafe/scripts.pory"
	.string "Even Swampert couldn't stop you once\n"
	.string "you found your rhythm.$"

BattleCafe_TrainerAtlas_Text_0:
# 732 "data/maps/BattleCafe/scripts.pory"
	.string "Tyranitar has settled\n"
	.string "down for lunch. The sandstorm\l"
	.string "returns tomorrow!$"

BattleCafe_TrainerAtlas_Text_1:
# 739 "data/maps/BattleCafe/scripts.pory"
	.string "Tyranitar, whip up a\n"
	.string "sandstorm! Let's see how sturdy your\l"
	.string "team really is.$"

BattleCafe_TrainerAtlas_Text_2:
# 742 "data/maps/BattleCafe/scripts.pory"
	.string "You stood firm right to the end.$"

BattleCafe_TrainerAtlas_Text_3:
# 743 "data/maps/BattleCafe/scripts.pory"
	.string "Excadrill loves a sandstorm, but your\n"
	.string "Pokémon looked right at home in it\l"
	.string "too.$"
