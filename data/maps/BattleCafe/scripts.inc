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
# 17 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_RECEIVED, BattleCafe_Owner_4
BattleCafe_Owner_1:
# 28 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_Owner_2:
# 26 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_GiveDiancie
	goto BattleCafe_Owner_1

BattleCafe_Owner_3:
# 19 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_DOVES
	goto_if 1, BattleCafe_Owner_8
	goto BattleCafe_Owner_1

BattleCafe_Owner_4:
# 18 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_ATHENA
	goto_if 1, BattleCafe_Owner_3
	goto BattleCafe_Owner_1

BattleCafe_Owner_7:
# 21 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_NEM
	goto_if 1, BattleCafe_Owner_12
	goto BattleCafe_Owner_1

BattleCafe_Owner_8:
# 20 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_ELTON
	goto_if 1, BattleCafe_Owner_7
	goto BattleCafe_Owner_1

BattleCafe_Owner_11:
# 23 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_DRAC
	goto_if 1, BattleCafe_Owner_16
	goto BattleCafe_Owner_1

BattleCafe_Owner_12:
# 22 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_BAI
	goto_if 1, BattleCafe_Owner_11
	goto BattleCafe_Owner_1

BattleCafe_Owner_15:
# 25 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_TYLARIE
	goto_if 1, BattleCafe_Owner_2
	goto BattleCafe_Owner_1

BattleCafe_Owner_16:
# 24 "data/maps/BattleCafe/scripts.pory"
	checktrainerflag TRAINER_CAFE_JUNA
	goto_if 1, BattleCafe_Owner_15
	goto BattleCafe_Owner_1


BattleCafe_GiveDiancie::
# 32 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_DIANCIE_READY, BattleCafe_GiveDiancie_2
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
# 33 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_0
# 39 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_GiveDiancie_Text_1
# 43 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_DIANCIE_READY
# 44 "data/maps/BattleCafe/scripts.pory"
	release
	end

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
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_RewardMenu_Text_1, BattleCafe_RewardMenu_Text_2, BattleCafe_RewardMenu_Text_3, BattleCafe_RewardMenu_Text_4, BattleCafe_RewardMenu_Text_5, BattleCafe_RewardMenu_Text_6, BattleCafe_RewardMenu_Text_7, BattleCafe_RewardMenu_Text_8, BattleCafe_RewardMenu_Text_9, BattleCafe_RewardMenu_Text_10, BattleCafe_RewardMenu_Text_11
# 406 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 407 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_RewardMenu_2
# 408 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_RewardMenu_3
# 409 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_RewardMenu_4
# 410 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_RewardMenu_5
# 411 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_RewardMenu_6
# 412 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_RewardMenu_7
# 413 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_RewardMenu_8
# 414 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_RewardMenu_9
# 415 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_RewardMenu_10
# 416 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_RewardMenu_11
# 417 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
# 407 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_3:
# 408 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_4:
# 409 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_5:
# 410 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTornadus
	return

BattleCafe_RewardMenu_6:
# 411 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseThundurus
	return

BattleCafe_RewardMenu_7:
# 412 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseLandorus
	return

BattleCafe_RewardMenu_8:
# 413 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseEnamorus
	return

BattleCafe_RewardMenu_9:
# 414 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_10:
# 415 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_11:
# 416 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoney
	return


BattleCafe_ChooseArticuno::
# 422 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
# 427 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
# 428 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 429 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
# 423 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseArticuno_Text_0
# 425 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
# 433 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
# 438 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
# 439 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 440 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
# 434 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseZapdos_Text_0
# 436 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
# 444 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
# 449 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
# 450 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 2
# 451 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
# 445 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoltres_Text_0
# 447 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ChooseTornadus::
# 455 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TORNADUS_RECEIVED, BattleCafe_ChooseTornadus_2
BattleCafe_ChooseTornadus_1:
# 460 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS
# 461 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 3
# 462 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTornadus_2:
# 456 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTornadus_Text_0
# 458 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTornadus_1


BattleCafe_ChooseThundurus::
# 466 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED, BattleCafe_ChooseThundurus_2
BattleCafe_ChooseThundurus_1:
# 471 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS
# 472 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 4
# 473 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseThundurus_2:
# 467 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseThundurus_Text_0
# 469 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseThundurus_1


BattleCafe_ChooseLandorus::
# 477 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_LANDORUS_RECEIVED, BattleCafe_ChooseLandorus_2
BattleCafe_ChooseLandorus_1:
# 482 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS
# 483 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 5
# 484 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseLandorus_2:
# 478 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseLandorus_Text_0
# 480 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseLandorus_1


BattleCafe_ChooseEnamorus::
# 488 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED, BattleCafe_ChooseEnamorus_2
BattleCafe_ChooseEnamorus_1:
# 493 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENAMORUS
# 494 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 6
# 495 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseEnamorus_2:
# 489 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseEnamorus_Text_0
# 491 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseEnamorus_1


BattleCafe_ConfirmRewardMon::
# 499 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
# 502 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 503 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
# 505 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
# 509 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 510 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_8
BattleCafe_ConfirmRewardMon_7:
# 513 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 514 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 515 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 516 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 517 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 518 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmRewardMon_12
# 519 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmRewardMon_13
# 520 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_ConfirmRewardMon_14
# 521 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_ConfirmRewardMon_15
# 522 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_ConfirmRewardMon_16
# 523 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_ConfirmRewardMon_17
# 524 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_ConfirmRewardMon_18
BattleCafe_ConfirmRewardMon_10:
# 526 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_20
BattleCafe_ConfirmRewardMon_19:
# 532 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_2
# 534 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
# 500 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
# 506 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
# 511 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_12:
# 518 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_13:
# 519 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_14:
# 520 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_15:
# 521 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TORNADUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_16:
# 522 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_17:
# 523 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_LANDORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_18:
# 524 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_10

BattleCafe_ConfirmRewardMon_20:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_22
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_22:
# 528 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_1
# 529 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
	goto BattleCafe_ConfirmRewardMon_19


BattleCafe_ChooseShinyGenome::
# 538 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
# 541 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
# 543 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
# 546 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_SHIN_GENOME, 1
# 547 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
# 550 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 551 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
# 554 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 4
# 555 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_1
# 558 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
# 539 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
# 544 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
# 548 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
# 552 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
# 562 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
# 565 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
# 567 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
# 570 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
# 571 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
# 574 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
# 575 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
# 578 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 579 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
# 582 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
# 563 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
# 568 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
# 572 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
# 576 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
# 586 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
# 589 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
# 591 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
# 594 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 595 "data/maps/BattleCafe/scripts.pory"
	showmoneybox 0, 0
# 596 "data/maps/BattleCafe/scripts.pory"
	addmoney 250000
# 597 "data/maps/BattleCafe/scripts.pory"
	updatemoneybox 0
# 598 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 599 "data/maps/BattleCafe/scripts.pory"
	waitse
# 600 "data/maps/BattleCafe/scripts.pory"
	hidemoneybox
# 601 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_1
# 603 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
# 587 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
# 592 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_NotEnoughPoints::
# 607 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughPoints_Text_0
# 610 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
# 614 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
# 617 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
# 621 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
# 624 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
# 628 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_Goodbye_Text_0
# 629 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDailyCandyReward::
# 634 "data/maps/BattleCafe/scripts.pory"
	random 3
# 635 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_RESULT, 1
# 636 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, VAR_RESULT
	return


BattleCafe_TrainerAthena::
# 641 "data/maps/BattleCafe/scripts.pory"
	lock
# 642 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 644 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ATHENA, BattleCafe_TrainerAthena_2
# 650 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ATHENA
# 651 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_1
# 653 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ATHENA, BattleCafe_TrainerAthena_Text_2
# 654 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_3
# 655 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 656 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAthena_2:
# 645 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_0
# 647 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDoves::
# 661 "data/maps/BattleCafe/scripts.pory"
	lock
# 662 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 664 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DOVES, BattleCafe_TrainerDoves_2
# 671 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DOVES
# 672 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_1
# 674 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DOVES, BattleCafe_TrainerDoves_Text_2
# 675 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_3
# 678 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 679 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDoves_2:
# 665 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_0
# 668 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerElton::
# 684 "data/maps/BattleCafe/scripts.pory"
	lock
# 685 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 687 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ELTON, BattleCafe_TrainerElton_2
# 692 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ELTON
# 693 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_1
# 695 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ELTON, BattleCafe_TrainerElton_Text_2
# 696 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_3
# 698 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 699 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerElton_2:
# 688 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_0
# 689 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerNem::
# 704 "data/maps/BattleCafe/scripts.pory"
	lock
# 705 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 707 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_NEM, BattleCafe_TrainerNem_2
# 712 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_NEM
# 713 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_1
# 714 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_NEM, BattleCafe_TrainerNem_Text_2
# 715 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_3
# 716 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 717 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerNem_2:
# 708 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_0
# 709 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerBai::
# 722 "data/maps/BattleCafe/scripts.pory"
	lock
# 723 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 725 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_BAI, BattleCafe_TrainerBai_2
# 731 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_BAI
# 732 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_1
# 733 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_BAI, BattleCafe_TrainerBai_Text_2
# 734 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_3
# 736 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 737 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerBai_2:
# 726 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_0
# 728 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDrac::
# 742 "data/maps/BattleCafe/scripts.pory"
	lock
# 743 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 745 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DRAC, BattleCafe_TrainerDrac_2
# 751 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DRAC
# 752 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_1
# 753 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DRAC, BattleCafe_TrainerDrac_Text_2
# 754 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 756 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 757 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDrac_2:
# 746 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 748 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerMarina::
# 762 "data/maps/BattleCafe/scripts.pory"
	lock
# 763 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 765 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_JUNA, BattleCafe_TrainerMarina_2
# 771 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_JUNA
# 772 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_1
# 774 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerMarina_Text_2
# 775 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_3
# 777 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 778 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerMarina_2:
# 766 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_0
# 768 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerTylarie::
# 783 "data/maps/BattleCafe/scripts.pory"
	lock
# 784 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 786 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_TYLARIE, BattleCafe_TrainerTylarie_2
# 792 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_TYLARIE
# 793 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_1
# 795 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_TYLARIE, BattleCafe_TrainerTylarie_Text_2
# 796 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_3
# 798 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 799 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerTylarie_2:
# 787 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_0
# 789 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDiancie_Text_0:
# 33 "data/maps/BattleCafe/scripts.pory"
	.string "Well, look at that. You've beaten\n"
	.string "every one of my regulars at least\l"
	.string "once.\p"
	.string "Seems only right you leave with a\n"
	.string "rare dining companion, Diancie!$"

BattleCafe_GiveDiancie_Text_1:
# 39 "data/maps/BattleCafe/scripts.pory"
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
	.string "Tornadus - 5$"

BattleCafe_RewardMenu_Text_5:
# 399 "data/maps/BattleCafe/scripts.pory"
	.string "Thundurus - 5$"

BattleCafe_RewardMenu_Text_6:
# 400 "data/maps/BattleCafe/scripts.pory"
	.string "Landorus - 5$"

BattleCafe_RewardMenu_Text_7:
# 401 "data/maps/BattleCafe/scripts.pory"
	.string "Enamorus - 5$"

BattleCafe_RewardMenu_Text_8:
# 402 "data/maps/BattleCafe/scripts.pory"
	.string "Shiny Genome - 3$"

BattleCafe_RewardMenu_Text_9:
# 403 "data/maps/BattleCafe/scripts.pory"
	.string "2 Gold Caps - 3$"

BattleCafe_RewardMenu_Text_10:
# 404 "data/maps/BattleCafe/scripts.pory"
	.string "¥250,000 - 3$"

BattleCafe_RewardMenu_Text_11:
# 405 "data/maps/BattleCafe/scripts.pory"
	.string "Back$"

BattleCafe_ChooseArticuno_Text_0:
# 423 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Articuno to you.$"

BattleCafe_ChooseZapdos_Text_0:
# 434 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Zapdos to you.$"

BattleCafe_ChooseMoltres_Text_0:
# 445 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Moltres to you.$"

BattleCafe_ChooseTornadus_Text_0:
# 456 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tornadus\n"
	.string "to you.$"

BattleCafe_ChooseThundurus_Text_0:
# 467 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Thundurus\n"
	.string "to you.$"

BattleCafe_ChooseLandorus_Text_0:
# 478 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Landorus\n"
	.string "to you.$"

BattleCafe_ChooseEnamorus_Text_0:
# 489 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Enamorus\n"
	.string "to you.$"

BattleCafe_ConfirmRewardMon_Text_0:
# 503 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmRewardMon_Text_1:
# 528 "data/maps/BattleCafe/scripts.pory"
	.string "You might find this useful.$"

BattleCafe_ConfirmRewardMon_Text_2:
# 532 "data/maps/BattleCafe/scripts.pory"
	.string "A fair trade. I'm sure it'll fit right\n"
	.string "into your team.$"

BattleCafe_ChooseShinyGenome_Text_0:
# 541 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for a\n"
	.string "Shiny Genome?$"

BattleCafe_ChooseShinyGenome_Text_1:
# 555 "data/maps/BattleCafe/scripts.pory"
	.string "A rare find. Use it on whichever\n"
	.string "Pokémon you want to bring out the\l"
	.string "shine in.$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
# 565 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for two\n"
	.string "Gold Bottle Caps?$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
# 579 "data/maps/BattleCafe/scripts.pory"
	.string "Two Gold Bottle Caps, polished up and\n"
	.string "ready. They'll bring out the very\l"
	.string "best in your Pokémon.$"

BattleCafe_ChooseMoney_Text_0:
# 589 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "¥250,000?$"

BattleCafe_ChooseMoney_Text_1:
# 601 "data/maps/BattleCafe/scripts.pory"
	.string "Use it well, and perhaps spend a little\n"
	.string "on dessert!$"

BattleCafe_NotEnoughPoints_Text_0:
# 607 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 5 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughFourPoints_Text_0:
# 614 "data/maps/BattleCafe/scripts.pory"
	.string "The Shiny Genome costs 4 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughBagSpace_Text_0:
# 621 "data/maps/BattleCafe/scripts.pory"
	.string "Your Bag is too full for that prize.\n"
	.string "Make some room and come back whenever\l"
	.string "you're ready!$"

BattleCafe_Goodbye_Text_0:
# 628 "data/maps/BattleCafe/scripts.pory"
	.string "Come back hungry for another battle!$"

BattleCafe_TrainerAthena_Text_0:
# 645 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun? Let's try this\n"
	.string "again tomorrow!$"

BattleCafe_TrainerAthena_Text_1:
# 651 "data/maps/BattleCafe/scripts.pory"
	.string "Let's see if you can survive this\n"
	.string "stall!$"

BattleCafe_TrainerAthena_Text_2:
# 653 "data/maps/BattleCafe/scripts.pory"
	.string "Huh?$"

BattleCafe_TrainerAthena_Text_3:
# 654 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun?$"

BattleCafe_TrainerDoves_Text_0:
# 665 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when \n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerDoves_Text_1:
# 672 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let me show you the power of \n"
	.string "Genesect!$"

BattleCafe_TrainerDoves_Text_2:
# 674 "data/maps/BattleCafe/scripts.pory"
	.string "Banned again from Overused...$"

BattleCafe_TrainerDoves_Text_3:
# 675 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when\n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerElton_Text_0:
# 688 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Rematch tomorrow! Be there!$"

BattleCafe_TrainerElton_Text_1:
# 693 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Let's have a battle with our\n"
	.string "favourite Pokémon!$"

BattleCafe_TrainerElton_Text_2:
# 695 "data/maps/BattleCafe/scripts.pory"
	.string "You handled every trick I had!$"

BattleCafe_TrainerElton_Text_3:
# 696 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Even Gengar's impressed, and it\n"
	.string "rarely takes a loss seriously.$"

BattleCafe_TrainerNem_Text_0:
# 708 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Come back tomorrow.$"

BattleCafe_TrainerNem_Text_1:
# 713 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Think fast!$"

BattleCafe_TrainerNem_Text_2:
# 714 "data/maps/BattleCafe/scripts.pory"
	.string "I'll be watching.$"

BattleCafe_TrainerNem_Text_3:
# 715 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: We can fight again tomorrow.$"

BattleCafe_TrainerBai_Text_0:
# 726 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: That was a good match!\n"
	.string "Let's fight again tomorrow!$"

BattleCafe_TrainerBai_Text_1:
# 732 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Money money money, Ready?$"

BattleCafe_TrainerBai_Text_2:
# 733 "data/maps/BattleCafe/scripts.pory"
	.string "No money...$"

BattleCafe_TrainerBai_Text_3:
# 734 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Good match! Let's try this again \n"
	.string "tomorrow!$"

BattleCafe_TrainerDrac_Text_0:
# 746 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: You're really tough! Let's fight\n"
	.string "again tomorrow!$"

BattleCafe_TrainerDrac_Text_1:
# 752 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: Care for a double battle?$"

BattleCafe_TrainerDrac_Text_2:
# 753 "data/maps/BattleCafe/scripts.pory"
	.string "Soothed.$"

BattleCafe_TrainerMarina_Text_0:
# 766 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper says the rain has\n"
	.string "passed for today. Tomorrow!$"

BattleCafe_TrainerMarina_Text_1:
# 772 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper, call in the rain!\n"
	.string "Let's make some waves.$"

BattleCafe_TrainerMarina_Text_2:
# 774 "data/maps/BattleCafe/scripts.pory"
	.string "You weathered the whole storm.$"

BattleCafe_TrainerMarina_Text_3:
# 775 "data/maps/BattleCafe/scripts.pory"
	.string "Even Swampert couldn't stop you once\n"
	.string "you found your rhythm.$"

BattleCafe_TrainerTylarie_Text_0:
# 787 "data/maps/BattleCafe/scripts.pory"
	.string "Steelix has settled down for\n"
	.string "lunch. We'll be ready tomorrow!$"

BattleCafe_TrainerTylarie_Text_1:
# 793 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Let me show you how sturdy my\n"
	.string "team is!$"

BattleCafe_TrainerTylarie_Text_2:
# 795 "data/maps/BattleCafe/scripts.pory"
	.string "Ouch.$"

BattleCafe_TrainerTylarie_Text_3:
# 796 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Not bad. We can go at it again\n"
	.string "another day.$"
