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
# 92 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_6
BattleCafe_OwnerMenu_4:
# 100 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_11
BattleCafe_OwnerMenu_9:
# 109 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_3
# 110 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_15
# 111 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_15
BattleCafe_OwnerMenu_14:
# 133 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
# 141 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OwnerMenu_20
# 143 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OwnerMenu_21
# 144 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OwnerMenu_22
# 145 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OwnerMenu_23
# 146 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_OwnerMenu_24
# 147 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_OwnerMenu_25
# 148 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_Goodbye
	return

BattleCafe_OwnerMenu_2:
# 76 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_0
# 89 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_CAFE_INTRO_DONE
	goto BattleCafe_OwnerMenu_1

BattleCafe_OwnerMenu_5:
# 94 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_1
# 98 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_6:
# 93 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_OwnerMenu_5
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_10:
# 102 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_2
# 106 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_11:
# 101 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_OwnerMenu_10
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_15:
# 112 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_8, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
# 121 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 122 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OwnerMenu_28
# 123 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OwnerMenu_29
# 124 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OwnerMenu_30
# 125 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OwnerMenu_31
# 126 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_OwnerMenu_32
# 127 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_OwnerMenu_33
# 128 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_OwnerMenu_34
# 129 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_Goodbye
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_20:
# 142 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskDailyChallenge
	return

BattleCafe_OwnerMenu_21:
# 143 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskRushMode
	return

BattleCafe_OwnerMenu_22:
# 144 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperChallenge
	return

BattleCafe_OwnerMenu_23:
# 145 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperRush
	return

BattleCafe_OwnerMenu_24:
# 146 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_OwnerMenu_25:
# 147 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	return

BattleCafe_OwnerMenu_28:
# 122 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskDailyChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_29:
# 123 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskRushMode
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_30:
# 124 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_31:
# 125 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperRush
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_32:
# 126 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_33:
# 127 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_34:
# 128 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	goto BattleCafe_OwnerMenu_14


BattleCafe_OptionsMenu::
# 153 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OptionsMenu_Text_0
# 154 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OptionsMenu_Text_1, BattleCafe_OptionsMenu_Text_2, BattleCafe_OptionsMenu_Text_3, BattleCafe_OptionsMenu_Text_4
# 159 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 160 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OptionsMenu_2
# 161 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OptionsMenu_3
# 162 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OptionsMenu_4
# 163 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_OptionsMenu_2:
# 160 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseBattleBgm
	return

BattleCafe_OptionsMenu_3:
# 161 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ViewHighScores
	return

BattleCafe_OptionsMenu_4:
# 162 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainRules
	return


BattleCafe_ChooseBattleBgm::
# 168 "data/maps/BattleCafe/scripts.pory"
	call BattleFrontier_EventScript_ChooseBattleBgm
# 169 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ViewHighScores::
# 173 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 174 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_ShowRecordsWindow
# 175 "data/maps/BattleCafe/scripts.pory"
	waitbuttonpress
# 176 "data/maps/BattleCafe/scripts.pory"
	special RemoveRecordsWindow
# 177 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ExplainRules::
# 181 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_0
# 191 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_1
# 198 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_2
# 206 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_3
# 213 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_ExplainRules_2
# 214 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_ExplainRules_2
BattleCafe_ExplainRules_1:
# 228 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ExplainRules_2:
# 215 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_4
# 221 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_5
	goto BattleCafe_ExplainRules_1


BattleCafe_AskDailyChallenge::
# 232 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON, BattleCafe_AskDailyChallenge_2
BattleCafe_AskDailyChallenge_1:
# 240 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_1, MSGBOX_YESNO
# 247 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskDailyChallenge_5
BattleCafe_AskDailyChallenge_4:
# 250 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
# 251 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskDailyChallenge_2:
# 233 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_0
# 238 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_1

BattleCafe_AskDailyChallenge_5:
# 248 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_4


BattleCafe_AskRushMode::
# 255 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_RUSH_WON, BattleCafe_AskRushMode_2
BattleCafe_AskRushMode_1:
# 263 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_1, MSGBOX_YESNO
# 270 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskRushMode_5
BattleCafe_AskRushMode_4:
# 273 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
# 274 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskRushMode_2:
# 256 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_0
# 261 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_1

BattleCafe_AskRushMode_5:
# 271 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_4


BattleCafe_AskSuperChallenge::
# 278 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_AskSuperChallenge_2
BattleCafe_AskSuperChallenge_1:
# 286 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 287 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperChallenge_5
BattleCafe_AskSuperChallenge_4:
# 293 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_2, MSGBOX_YESNO
# 299 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperChallenge_8
BattleCafe_AskSuperChallenge_7:
# 302 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
# 303 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperChallenge_2:
# 279 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_0
# 284 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_1

BattleCafe_AskSuperChallenge_5:
# 288 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_1
# 291 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_4

BattleCafe_AskSuperChallenge_8:
# 300 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_7


BattleCafe_AskSuperRush::
# 307 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_AskSuperRush_2
BattleCafe_AskSuperRush_1:
# 315 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 316 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperRush_5
BattleCafe_AskSuperRush_4:
# 324 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_2, MSGBOX_YESNO
# 331 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperRush_8
BattleCafe_AskSuperRush_7:
# 334 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
# 335 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperRush_2:
# 308 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_0
# 313 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_1

BattleCafe_AskSuperRush_5:
# 317 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_1
# 322 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_4

BattleCafe_AskSuperRush_8:
# 332 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_7


BattleCafe_EndlessMenu::
# 339 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessMenu_Text_0
# 340 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_EndlessMenu_Text_1, BattleCafe_EndlessMenu_Text_2, BattleCafe_EndlessMenu_Text_3, BattleCafe_OptionsMenu_Text_4
# 345 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 346 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_EndlessMenu_2
# 347 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_EndlessMenu_3
# 348 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_EndlessMenu_4
# 349 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_EndlessMenu_2:
# 346 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessChallenge
	return

BattleCafe_EndlessMenu_3:
# 347 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessRush
	return

BattleCafe_EndlessMenu_4:
# 348 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainEndlessRules
	return


BattleCafe_ExplainEndlessRules::
# 354 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_0
# 361 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_1
# 368 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_2
# 371 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	return


BattleCafe_AskEndlessChallenge::
# 375 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_AskEndlessChallenge_2
BattleCafe_AskEndlessChallenge_1:
# 380 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 381 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessChallenge_5
BattleCafe_AskEndlessChallenge_4:
# 389 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_2, MSGBOX_YESNO
# 396 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessChallenge_8
BattleCafe_AskEndlessChallenge_7:
# 399 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
# 400 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessChallenge_2:
# 376 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_0
# 378 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_1

BattleCafe_AskEndlessChallenge_5:
# 382 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 387 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_4

BattleCafe_AskEndlessChallenge_8:
# 397 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_7


BattleCafe_AskEndlessRush::
# 404 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_AskEndlessRush_2
BattleCafe_AskEndlessRush_1:
# 409 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 410 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessRush_5
BattleCafe_AskEndlessRush_4:
# 418 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_1, MSGBOX_YESNO
# 425 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessRush_8
BattleCafe_AskEndlessRush_7:
# 428 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
# 429 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessRush_2:
# 405 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_0
# 407 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_1

BattleCafe_AskEndlessRush_5:
# 411 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 416 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_4

BattleCafe_AskEndlessRush_8:
# 426 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_7


BattleCafe_BeginChallenge::
# 433 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 434 "data/maps/BattleCafe/scripts.pory"
	hidefollower
# 435 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 436 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_InitChallenge
# 437 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 13, DIR_EAST
# 438 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 439 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_9, 0
# 440 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 441 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_BeginChallenge_2
# 442 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_BeginChallenge_2
# 446 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_1
BattleCafe_BeginChallenge_1:
# 449 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 450 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_BeginChallenge_2:
# 443 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_0
	goto BattleCafe_BeginChallenge_1


BattleCafe_ChallengeNextRound::
# 454 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_RunRound
# 455 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChallengeNextRound_2
BattleCafe_ChallengeNextRound_1:
# 459 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AdvanceWinCount
# 460 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_5
BattleCafe_ChallengeNextRound_4:
# 481 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_8
BattleCafe_ChallengeNextRound_7:
# 513 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_9, 3
	goto_if_ge BattleCafe_ChallengeNextRound_14
BattleCafe_ChallengeNextRound_13:
# 517 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeNextRound_21
# 523 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_27
# 529 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_30
# 533 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_6
BattleCafe_ChallengeNextRound_20:
# 538 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 539 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_ChallengeNextRound_2:
# 456 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeLost
	goto BattleCafe_ChallengeNextRound_1

BattleCafe_ChallengeNextRound_5:
# 461 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 1
# 462 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 463 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 464 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 465 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 466 "data/maps/BattleCafe/scripts.pory"
	waitse
# 467 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 468 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 469 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_0, MSGBOX_YESNO
# 474 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_11
BattleCafe_ChallengeNextRound_10:
# 477 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 478 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_4

BattleCafe_ChallengeNextRound_8:
# 482 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 2
# 483 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 484 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 485 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_TEMP_C, 1
# 486 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 487 "data/maps/BattleCafe/scripts.pory"
	waitse
# 488 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 489 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 490 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, 3
	goto_if_ge BattleCafe_ChallengeNextRound_17
# 500 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_2, MSGBOX_YESNO
BattleCafe_ChallengeNextRound_16:
# 506 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_25
BattleCafe_ChallengeNextRound_24:
# 509 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 510 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_11:
# 475 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_10

BattleCafe_ChallengeNextRound_14:
# 514 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeWon
	goto BattleCafe_ChallengeNextRound_13

BattleCafe_ChallengeNextRound_17:
# 491 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 492 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 493 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 494 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_1, MSGBOX_YESNO
	goto BattleCafe_ChallengeNextRound_16

BattleCafe_ChallengeNextRound_21:
# 518 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 519 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 520 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_3
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_25:
# 507 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_24

BattleCafe_ChallengeNextRound_27:
# 524 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 525 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 526 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_4
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_30:
# 530 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_5
	goto BattleCafe_ChallengeNextRound_20


BattleCafe_EndlessRetired::
# 543 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 544 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 545 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 546 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 547 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 548 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 549 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 550 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessRetired_Text_0
# 554 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_RunRound::
# 558 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_9
# 559 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_SelectOpponent
# 560 "data/maps/BattleCafe/scripts.pory"
	setobjectxy LOCALID_BATTLE_CAFE_OPPONENT, 14, 17
# 561 "data/maps/BattleCafe/scripts.pory"
	addobject LOCALID_BATTLE_CAFE_OPPONENT
# 562 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 10, 13, DIR_WEST
# 563 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 564 "data/maps/BattleCafe/scripts.pory"
	tower_getopponentintro FRONTIER_BEFORE_TEXT
# 565 "data/maps/BattleCafe/scripts.pory"
	msgbox gStringVar4
# 566 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 567 "data/maps/BattleCafe/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_CAFE
# 568 "data/maps/BattleCafe/scripts.pory"
	waitstate
# 569 "data/maps/BattleCafe/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 570 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 572 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 14, 17, DIR_EAST
# 573 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 574 "data/maps/BattleCafe/scripts.pory"
	removeobject LOCALID_BATTLE_CAFE_OPPONENT
# 576 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_A, B_OUTCOME_WON
	goto_if_eq BattleCafe_RunRound_2
# 579 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, FALSE
BattleCafe_RunRound_1:
	return

BattleCafe_RunRound_2:
# 577 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, TRUE
	goto BattleCafe_RunRound_1


BattleCafe_ChallengeLost::
# 585 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 586 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 587 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 588 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 589 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 590 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeLost_2
# 591 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeLost_2
# 601 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_1
BattleCafe_ChallengeLost_1:
# 608 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeLost_2:
# 592 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 593 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_0
	goto BattleCafe_ChallengeLost_1


BattleCafe_ChallengeWon::
# 612 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 613 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 614 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 615 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 616 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 618 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeWon_2
# 628 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto_if_eq BattleCafe_ChallengeWon_5
# 639 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeWon_8
# 650 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON
# 651 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 10
# 652 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 653 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 654 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 655 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_3
BattleCafe_ChallengeWon_1:
# 665 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_UnlockClearAchievement
# 666 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 667 "data/maps/BattleCafe/scripts.pory"
	waitse
# 668 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeWon_2:
# 619 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON
# 620 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 3
# 621 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 622 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 623 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 624 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_0
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_5:
# 629 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_RUSH_WON
# 630 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 631 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 632 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 633 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 634 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_1
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_8:
# 640 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON
# 641 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 642 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 643 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 644 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 645 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_2
	goto BattleCafe_ChallengeWon_1


BattleCafe_RewardMenu::
# 672 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_BATTLE_CAFE_POINTS
# 673 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_RewardMenu_Text_0
# 675 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_RewardMenu_Text_1, BattleCafe_RewardMenu_Text_2, BattleCafe_RewardMenu_Text_3, BattleCafe_RewardMenu_Text_4, BattleCafe_RewardMenu_Text_5, BattleCafe_RewardMenu_Text_6, BattleCafe_RewardMenu_Text_7, BattleCafe_RewardMenu_Text_8, BattleCafe_RewardMenu_Text_9, BattleCafe_RewardMenu_Text_10, BattleCafe_RewardMenu_Text_11, BattleCafe_RewardMenu_Text_12, BattleCafe_RewardMenu_Text_13, BattleCafe_OptionsMenu_Text_4
# 690 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 691 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_RewardMenu_2
# 692 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_RewardMenu_3
# 693 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_RewardMenu_4
# 694 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_RewardMenu_5
# 695 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_RewardMenu_6
# 696 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_RewardMenu_7
# 697 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_RewardMenu_8
# 698 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_RewardMenu_9
# 699 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_RewardMenu_10
# 700 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_RewardMenu_11
# 701 "data/maps/BattleCafe/scripts.pory"
	case 10, BattleCafe_RewardMenu_12
# 702 "data/maps/BattleCafe/scripts.pory"
	case 11, BattleCafe_RewardMenu_13
# 703 "data/maps/BattleCafe/scripts.pory"
	case 12, BattleCafe_RewardMenu_14
# 704 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
# 691 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_3:
# 692 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_4:
# 693 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_5:
# 694 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTornadus
	return

BattleCafe_RewardMenu_6:
# 695 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseThundurus
	return

BattleCafe_RewardMenu_7:
# 696 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseLandorus
	return

BattleCafe_RewardMenu_8:
# 697 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseEnamorus
	return

BattleCafe_RewardMenu_9:
# 698 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_10:
# 699 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_11:
# 700 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoney
	return

BattleCafe_RewardMenu_12:
# 701 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetAtk
	return

BattleCafe_RewardMenu_13:
# 702 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetDef
	return

BattleCafe_RewardMenu_14:
# 703 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetSpe
	return


BattleCafe_ChooseArticuno::
# 709 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
# 714 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
# 715 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 716 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
# 710 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseArticuno_Text_0
# 712 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
# 720 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
# 725 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
# 726 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 727 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
# 721 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseZapdos_Text_0
# 723 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
# 731 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
# 736 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
# 737 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 2
# 738 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
# 732 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoltres_Text_0
# 734 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ChooseTornadus::
# 742 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TORNADUS_RECEIVED, BattleCafe_ChooseTornadus_2
BattleCafe_ChooseTornadus_1:
# 747 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS
# 748 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 3
# 749 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTornadus_2:
# 743 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTornadus_Text_0
# 745 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTornadus_1


BattleCafe_ChooseThundurus::
# 753 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED, BattleCafe_ChooseThundurus_2
BattleCafe_ChooseThundurus_1:
# 758 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS
# 759 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 4
# 760 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseThundurus_2:
# 754 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseThundurus_Text_0
# 756 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseThundurus_1


BattleCafe_ChooseLandorus::
# 764 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_LANDORUS_RECEIVED, BattleCafe_ChooseLandorus_2
BattleCafe_ChooseLandorus_1:
# 769 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS
# 770 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 5
# 771 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseLandorus_2:
# 765 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseLandorus_Text_0
# 767 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseLandorus_1


BattleCafe_ChooseEnamorus::
# 775 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED, BattleCafe_ChooseEnamorus_2
BattleCafe_ChooseEnamorus_1:
# 780 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENAMORUS
# 781 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 6
# 782 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseEnamorus_2:
# 776 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseEnamorus_Text_0
# 778 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseEnamorus_1


BattleCafe_ConfirmRewardMon::
# 786 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
# 789 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 790 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
# 792 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
# 796 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_9
BattleCafe_ConfirmRewardMon_7:
# 803 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 804 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_13
BattleCafe_ConfirmRewardMon_12:
# 807 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 808 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 809 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 810 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 811 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 812 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmRewardMon_19
# 813 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmRewardMon_20
# 814 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_ConfirmRewardMon_21
# 815 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_ConfirmRewardMon_22
# 816 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_ConfirmRewardMon_23
# 817 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_ConfirmRewardMon_24
# 818 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_ConfirmRewardMon_25
BattleCafe_ConfirmRewardMon_17:
# 820 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_27
BattleCafe_ConfirmRewardMon_26:
# 826 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_2
# 828 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
# 787 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
# 793 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
# 797 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_REVEAL_GLASS, 1
# 798 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_15
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_9:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_8
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_13:
# 805 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_12

BattleCafe_ConfirmRewardMon_15:
# 799 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_19:
# 812 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_20:
# 813 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_21:
# 814 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_22:
# 815 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TORNADUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_23:
# 816 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_24:
# 817 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_LANDORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_25:
# 818 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_17

BattleCafe_ConfirmRewardMon_27:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_29
	goto BattleCafe_ConfirmRewardMon_26

BattleCafe_ConfirmRewardMon_29:
# 822 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_1
# 823 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
	goto BattleCafe_ConfirmRewardMon_26


BattleCafe_ChooseShinyGenome::
# 832 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
# 835 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
# 837 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
# 840 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_SHIN_GENOME, 1
# 841 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
# 844 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 845 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
# 848 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 4
# 849 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_1
# 852 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
# 833 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
# 838 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
# 842 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
# 846 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
# 856 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
# 859 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
# 861 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
# 864 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
# 865 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
# 868 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
# 869 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
# 872 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 873 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
# 875 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
# 857 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
# 862 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
# 866 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
# 870 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
# 879 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
# 882 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
# 884 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
# 887 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 888 "data/maps/BattleCafe/scripts.pory"
	showmoneybox 0, 0
# 889 "data/maps/BattleCafe/scripts.pory"
	addmoney 250000
# 890 "data/maps/BattleCafe/scripts.pory"
	updatemoneybox 0
# 891 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 892 "data/maps/BattleCafe/scripts.pory"
	waitse
# 893 "data/maps/BattleCafe/scripts.pory"
	hidemoneybox
# 894 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_1
# 896 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
# 880 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
# 885 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_ChooseVitaminSetAtk::
# 900 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetAtk_2
BattleCafe_ChooseVitaminSetAtk_1:
# 903 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_0, MSGBOX_YESNO
# 905 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_5
BattleCafe_ChooseVitaminSetAtk_4:
# 908 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_ATK
# 909 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 910 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetAtk_8
BattleCafe_ChooseVitaminSetAtk_7:
# 913 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_11
BattleCafe_ChooseVitaminSetAtk_10:
# 916 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 917 "data/maps/BattleCafe/scripts.pory"
	waitse
# 918 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_1
# 920 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetAtk_2:
# 901 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_1

BattleCafe_ChooseVitaminSetAtk_5:
# 906 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetAtk_4

BattleCafe_ChooseVitaminSetAtk_8:
# 911 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_7

BattleCafe_ChooseVitaminSetAtk_11:
# 914 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetAtk_10


BattleCafe_ChooseVitaminSetDef::
# 924 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetDef_2
BattleCafe_ChooseVitaminSetDef_1:
# 927 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_0, MSGBOX_YESNO
# 929 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetDef_5
BattleCafe_ChooseVitaminSetDef_4:
# 932 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_DEF
# 933 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 934 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetDef_8
BattleCafe_ChooseVitaminSetDef_7:
# 937 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetDef_11
BattleCafe_ChooseVitaminSetDef_10:
# 940 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 941 "data/maps/BattleCafe/scripts.pory"
	waitse
# 942 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_1
# 944 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetDef_2:
# 925 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_1

BattleCafe_ChooseVitaminSetDef_5:
# 930 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetDef_4

BattleCafe_ChooseVitaminSetDef_8:
# 935 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_7

BattleCafe_ChooseVitaminSetDef_11:
# 938 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetDef_10


BattleCafe_ChooseVitaminSetSpe::
# 948 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 2
	goto_if_lt BattleCafe_ChooseVitaminSetSpe_2
BattleCafe_ChooseVitaminSetSpe_1:
# 951 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_0, MSGBOX_YESNO
# 953 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_5
BattleCafe_ChooseVitaminSetSpe_4:
# 956 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_SPE
# 957 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 958 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetSpe_8
BattleCafe_ChooseVitaminSetSpe_7:
# 961 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_11
BattleCafe_ChooseVitaminSetSpe_10:
# 964 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 965 "data/maps/BattleCafe/scripts.pory"
	waitse
# 966 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_1
# 967 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetSpe_2:
# 949 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_1

BattleCafe_ChooseVitaminSetSpe_5:
# 954 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetSpe_4

BattleCafe_ChooseVitaminSetSpe_8:
# 959 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_7

BattleCafe_ChooseVitaminSetSpe_11:
# 962 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetSpe_10


BattleCafe_NotEnoughPoints::
# 971 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughPoints_Text_0
# 974 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
# 978 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
# 981 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughVitaminSetPoints::
# 985 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughVitaminSetPoints_Text_0
# 990 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
# 994 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
# 997 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
# 1001 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_Goodbye_Text_0
# 1002 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDailyCandyReward::
# 1007 "data/maps/BattleCafe/scripts.pory"
	random 3
# 1008 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_RESULT, 1
# 1009 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, VAR_RESULT
	return


BattleCafe_TrainerAthena::
# 1014 "data/maps/BattleCafe/scripts.pory"
	lock
# 1015 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1017 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ATHENA, BattleCafe_TrainerAthena_2
# 1023 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_1
# 1025 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ATHENA, BattleCafe_TrainerAthena_Text_2
# 1026 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ATHENA
# 1027 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_3
# 1028 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1029 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAthena_2:
# 1018 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_0
# 1020 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDoves::
# 1034 "data/maps/BattleCafe/scripts.pory"
	lock
# 1035 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1037 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DOVES, BattleCafe_TrainerDoves_2
# 1044 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_1
# 1046 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DOVES, BattleCafe_TrainerDoves_Text_2
# 1047 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DOVES
# 1048 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_3
# 1051 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1052 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDoves_2:
# 1038 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_0
# 1041 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerElton::
# 1057 "data/maps/BattleCafe/scripts.pory"
	lock
# 1058 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1060 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ELTON, BattleCafe_TrainerElton_2
# 1065 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_1
# 1067 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ELTON, BattleCafe_TrainerElton_Text_2
# 1068 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ELTON
# 1069 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_3
# 1071 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1072 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerElton_2:
# 1061 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_0
# 1062 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerNem::
# 1077 "data/maps/BattleCafe/scripts.pory"
	lock
# 1078 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1080 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_NEM, BattleCafe_TrainerNem_2
# 1085 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_1
# 1086 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_NEM, BattleCafe_TrainerNem_Text_2
# 1087 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_NEM
# 1088 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_3
# 1089 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1090 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerNem_2:
# 1081 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_0
# 1082 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerBai::
# 1095 "data/maps/BattleCafe/scripts.pory"
	lock
# 1096 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1098 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_BAI, BattleCafe_TrainerBai_2
# 1104 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_1
# 1106 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_BAI, BattleCafe_TrainerBai_Text_2
# 1107 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_BAI
# 1108 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_3
# 1110 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1111 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerBai_2:
# 1099 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_0
# 1101 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDrac::
# 1116 "data/maps/BattleCafe/scripts.pory"
	lock
# 1117 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1119 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DRAC, BattleCafe_TrainerDrac_2
# 1125 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_1
# 1126 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DRAC, BattleCafe_TrainerDrac_Text_2
# 1127 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DRAC
# 1128 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1130 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1131 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDrac_2:
# 1120 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1122 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerMarina::
# 1136 "data/maps/BattleCafe/scripts.pory"
	lock
# 1137 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1139 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_JUNA, BattleCafe_TrainerMarina_2
# 1145 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_1
# 1147 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerMarina_Text_2
# 1148 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_JUNA
# 1149 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_3
# 1151 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1152 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerMarina_2:
# 1140 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_0
# 1142 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerTylarie::
# 1157 "data/maps/BattleCafe/scripts.pory"
	lock
# 1158 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1160 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_TYLARIE, BattleCafe_TrainerTylarie_2
# 1166 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_1
# 1168 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_TYLARIE, BattleCafe_TrainerTylarie_Text_2
# 1169 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_TYLARIE
# 1170 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_3
# 1172 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1173 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerTylarie_2:
# 1161 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_0
# 1163 "data/maps/BattleCafe/scripts.pory"
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
	.string "There's even a special prize if you\n"
	.string "manage to beat all the regulars here.\p"
	.string "Anyway, enough about me...$"

BattleCafe_OwnerMenu_Text_1:
# 94 "data/maps/BattleCafe/scripts.pory"
	.string "After seeing you clear Super Challenge,\n"
	.string "I can offer you a new format:\p"
	.string "Endless Challenge!$"

BattleCafe_OwnerMenu_Text_2:
# 102 "data/maps/BattleCafe/scripts.pory"
	.string "After seeing you conquer Super Rush,\n"
	.string "I can offer you one final format:\p"
	.string "Endless Rush!$"

BattleCafe_OwnerMenu_Text_3:
# 109 "data/maps/BattleCafe/scripts.pory"
	.string "Welcome! What'll it be today?$"

BattleCafe_OwnerMenu_Text_4:
# 113 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge$"

BattleCafe_OwnerMenu_Text_5:
# 114 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode$"

BattleCafe_OwnerMenu_Text_6:
# 115 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge$"

BattleCafe_OwnerMenu_Text_7:
# 116 "data/maps/BattleCafe/scripts.pory"
	.string "Super Rush$"

BattleCafe_OwnerMenu_Text_8:
# 117 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Modes$"

BattleCafe_OwnerMenu_Text_9:
# 118 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange Points$"

BattleCafe_OwnerMenu_Text_10:
# 119 "data/maps/BattleCafe/scripts.pory"
	.string "Café Options$"

BattleCafe_OwnerMenu_Text_11:
# 120 "data/maps/BattleCafe/scripts.pory"
	.string "Leave$"

BattleCafe_OptionsMenu_Text_0:
# 153 "data/maps/BattleCafe/scripts.pory"
	.string "What would you like to check?$"

BattleCafe_OptionsMenu_Text_1:
# 155 "data/maps/BattleCafe/scripts.pory"
	.string "Battle BGM$"

BattleCafe_OptionsMenu_Text_2:
# 156 "data/maps/BattleCafe/scripts.pory"
	.string "High Scores$"

BattleCafe_OptionsMenu_Text_3:
# 157 "data/maps/BattleCafe/scripts.pory"
	.string "Café Rules$"

BattleCafe_OptionsMenu_Text_4:
# 158 "data/maps/BattleCafe/scripts.pory"
	.string "Back$"

BattleCafe_ExplainRules_Text_0:
# 181 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors will answer each\n"
	.string "challenge, one after another.\p"
	.string "In the Daily Challenge, they bring\n"
	.string "dependable teams of four.\p"
	.string "I'll tend to your Pokémon after each\n"
	.string "battle.\p"
	.string "Win all three for 3 Café Points.$"

BattleCafe_ExplainRules_Text_1:
# 191 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode draws seasoned battlers with\n"
	.string "teams of four.\p"
	.string "Anything goes, and I can't heal\n"
	.string "your Pokémon between the matches.\p"
	.string "Win all three for 5 points.$"

BattleCafe_ExplainRules_Text_2:
# 198 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge and Super Rush pit\n"
	.string "you against full teams of six Pokémon.\p"
	.string "Anyone might show up so prepare to\n"
	.string "face literally anything.\p"
	.string "Same rules apply here for healing\n"
	.string "between the rounds.$"

BattleCafe_ExplainRules_Text_3:
# 206 "data/maps/BattleCafe/scripts.pory"
	.string "There are no breaks once service\n"
	.string "begins.\p"
	.string "A loss ends the run, though\n"
	.string "you may retry until you win.\p"
	.string "Each challenge can be won once per day.$"

BattleCafe_ExplainRules_Text_4:
# 215 "data/maps/BattleCafe/scripts.pory"
	.string "Both Endless formats use full teams\n"
	.string "of six and continue until you lose\l"
	.string "or choose to retire.\p"
	.string "Endless Challenge heals your party\n"
	.string "after every win and awards 1 point.$"

BattleCafe_ExplainRules_Text_5:
# 221 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party\n"
	.string "after every third victory and awards\l"
	.string "2 points per win.\p"
	.string "Your best streak in each format is\n"
	.string "saved under High Scores.$"

BattleCafe_AskDailyChallenge_Text_0:
# 233 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Daily Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or try another challenge!$"

BattleCafe_AskDailyChallenge_Text_1:
# 240 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors are ready with\n"
	.string "teams of four.\p"
	.string "I'll tend to your party\n"
	.string "after rounds one and two.\p"
	.string "Begin today's challenge?$"

BattleCafe_AskRushMode_Text_0:
# 256 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Rush Mode\n"
	.string "today.\p"
	.string "Come back tomorrow, or take\n"
	.string "another challenge!$"

BattleCafe_AskRushMode_Text_1:
# 263 "data/maps/BattleCafe/scripts.pory"
	.string "Three seasoned visitors are waiting\n"
	.string "with teams of four.\p"
	.string "I can't tend to\n"
	.string "your party between these battles.\p"
	.string "Begin today's rush?$"

BattleCafe_AskSuperChallenge_Text_0:
# 279 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Super Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or attempt another challenge!$"

BattleCafe_AskSuperChallenge_Text_1:
# 288 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Challenge. Bring a full party of six\l"
	.string "before entering.$"

BattleCafe_AskSuperChallenge_Text_2:
# 293 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each meet your full\n"
	.string "party with six Pokémon of their own.\p"
	.string "I'll tend to your team between battles.\p"
	.string "Begin the Super Challenge?$"

BattleCafe_AskSuperRush_Text_0:
# 308 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Super Rush\n"
	.string "today.\p"
	.string "Come back tomorrow for\n"
	.string "another full-team trial!$"

BattleCafe_AskSuperRush_Text_1:
# 317 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Rush.\p"
	.string "Bring a full party of six\n"
	.string "before entering.$"

BattleCafe_AskSuperRush_Text_2:
# 324 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each bring a full\n"
	.string "team of six.\p"
	.string "Once the rush begins, I can't heal\n"
	.string "your Pokémon between the battles.\p"
	.string "Begin the Super Rush?$"

BattleCafe_EndlessMenu_Text_0:
# 339 "data/maps/BattleCafe/scripts.pory"
	.string "Which Endless format will you try?$"

BattleCafe_EndlessMenu_Text_1:
# 341 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge$"

BattleCafe_EndlessMenu_Text_2:
# 342 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush$"

BattleCafe_EndlessMenu_Text_3:
# 343 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rules$"

BattleCafe_ExplainEndlessRules_Text_0:
# 354 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge restores your party\n"
	.string "after every victory. \p"
	.string "Each win immediately awards 1 \n"
	.string "Café Point.\p"
	.string "Clear Super Challenge to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_1:
# 361 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party after\n"
	.string "every third victory. \p"
	.string "Each win immediately awards 2 \n"
	.string "Café Points.\p"
	.string "Clear Super Rush to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_2:
# 368 "data/maps/BattleCafe/scripts.pory"
	.string "Both formats use full 6-vs-6 battles.\n"
	.string "You may retire after any victory,\l"
	.string "and your best streak is saved.$"

BattleCafe_AskEndlessChallenge_Text_0:
# 376 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Challenge to unlock\n"
	.string "Endless Challenge.$"

BattleCafe_AskEndlessChallenge_Text_1:
# 382 "data/maps/BattleCafe/scripts.pory"
	.string "Every Endless opponent brings\n"
	.string "six Pokémon.\p"
	.string "Bring a full party of six before\n"
	.string "taking your seat.$"

BattleCafe_AskEndlessChallenge_Text_2:
# 389 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every win,\n"
	.string "and each victory earns 1 Café Point.\p"
	.string "Begin Endless Challenge?$"

BattleCafe_AskEndlessRush_Text_0:
# 405 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Rush to unlock\n"
	.string "Endless Rush.$"

BattleCafe_AskEndlessRush_Text_1:
# 418 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every third\n"
	.string "victory. Each win earns 2 Café Points.\p"
	.string "Begin Endless Rush?$"

BattleCafe_BeginChallenge_Text_0:
# 443 "data/maps/BattleCafe/scripts.pory"
	.string "No final course. No final opponent.\n"
	.string "Endless service begins now!$"

BattleCafe_BeginChallenge_Text_1:
# 446 "data/maps/BattleCafe/scripts.pory"
	.string "Three courses. Three opponents.\n"
	.string "Service begins now!$"

BattleCafe_ChallengeNextRound_Text_0:
# 469 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points,\l"
	.string "and your party was restored.\p"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_1:
# 494 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Three battles cleared! Your party\n"
	.string "was restored. Continue the run?$"

BattleCafe_ChallengeNextRound_Text_2:
# 500 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Your party has not been restored.\n"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_3:
# 520 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next challenger is arriving!$"

BattleCafe_ChallengeNextRound_Text_4:
# 526 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_5:
# 530 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Super Rush!\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_6:
# 533 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Rush Mode!\n"
	.string "The next challenger is arriving!$"

BattleCafe_EndlessRetired_Text_0:
# 550 "data/maps/BattleCafe/scripts.pory"
	.string "Run retired at {STR_VAR_1} wins.\p"
	.string "Your party is fully restored, your record\n"
	.string "is safe, and every point is yours to keep.$"

BattleCafe_ChallengeLost_Text_0:
# 593 "data/maps/BattleCafe/scripts.pory"
	.string "Your Endless run ends at {STR_VAR_1}\n"
	.string "wins. I've fully\l"
	.string "restored your party.\p"
	.string "Every Café Point you earned is yours\n"
	.string "to keep. Try to push even farther\l"
	.string "next time!$"

BattleCafe_ChallengeLost_Text_1:
# 601 "data/maps/BattleCafe/scripts.pory"
	.string "Tough course, huh? I've fully restored\n"
	.string "your party.\p"
	.string "Catch your breath, rework\n"
	.string "your strategy, and come at it again\l"
	.string "whenever you like!$"

BattleCafe_ChallengeWon_Text_0:
# 624 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge complete!\p"
	.string "That's {STR_VAR_1} Café Points for you.$"

BattleCafe_ChallengeWon_Text_1:
# 634 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode complete! That took\n"
	.string "some real grit.\p"
	.string "Here's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_2:
# 645 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge complete!\n"
	.string "Full team, full effort!\p"
	.string "That's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_3:
# 655 "data/maps/BattleCafe/scripts.pory"
	.string "Incredible! You have beaten\n"
	.string "the Super Rush mode!\p"
	.string "I can hardly believe it!\p"
	.string "Here's your reward of\n"
	.string "{STR_VAR_1} Café Points.$"

BattleCafe_RewardMenu_Text_0:
# 673 "data/maps/BattleCafe/scripts.pory"
	.string "You have {STR_VAR_1} Café Points.\n"
	.string "Anything you want to exchange for?$"

BattleCafe_RewardMenu_Text_1:
# 676 "data/maps/BattleCafe/scripts.pory"
	.string "G. Articuno - 5$"

BattleCafe_RewardMenu_Text_2:
# 677 "data/maps/BattleCafe/scripts.pory"
	.string "G. Zapdos - 5$"

BattleCafe_RewardMenu_Text_3:
# 678 "data/maps/BattleCafe/scripts.pory"
	.string "G. Moltres - 5$"

BattleCafe_RewardMenu_Text_4:
# 679 "data/maps/BattleCafe/scripts.pory"
	.string "Tornadus - 5$"

BattleCafe_RewardMenu_Text_5:
# 680 "data/maps/BattleCafe/scripts.pory"
	.string "Thundurus - 5$"

BattleCafe_RewardMenu_Text_6:
# 681 "data/maps/BattleCafe/scripts.pory"
	.string "Landorus - 5$"

BattleCafe_RewardMenu_Text_7:
# 682 "data/maps/BattleCafe/scripts.pory"
	.string "Enamorus - 5$"

BattleCafe_RewardMenu_Text_8:
# 683 "data/maps/BattleCafe/scripts.pory"
	.string "Shiny Genome - 4$"

BattleCafe_RewardMenu_Text_9:
# 684 "data/maps/BattleCafe/scripts.pory"
	.string "2 Gold Caps - 5$"

BattleCafe_RewardMenu_Text_10:
# 685 "data/maps/BattleCafe/scripts.pory"
	.string "¥250,000 - 5$"

BattleCafe_RewardMenu_Text_11:
# 686 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Atk - 4$"

BattleCafe_RewardMenu_Text_12:
# 687 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Def - 4$"

BattleCafe_RewardMenu_Text_13:
# 688 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Spe - 2$"

BattleCafe_ChooseArticuno_Text_0:
# 710 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Articuno to you.$"

BattleCafe_ChooseZapdos_Text_0:
# 721 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Zapdos to you.$"

BattleCafe_ChooseMoltres_Text_0:
# 732 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Moltres to you.$"

BattleCafe_ChooseTornadus_Text_0:
# 743 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tornadus\n"
	.string "to you.$"

BattleCafe_ChooseThundurus_Text_0:
# 754 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Thundurus\n"
	.string "to you.$"

BattleCafe_ChooseLandorus_Text_0:
# 765 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Landorus\n"
	.string "to you.$"

BattleCafe_ChooseEnamorus_Text_0:
# 776 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Enamorus\n"
	.string "to you.$"

BattleCafe_ConfirmRewardMon_Text_0:
# 790 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmRewardMon_Text_1:
# 822 "data/maps/BattleCafe/scripts.pory"
	.string "You might find this useful.$"

BattleCafe_ConfirmRewardMon_Text_2:
# 826 "data/maps/BattleCafe/scripts.pory"
	.string "A fair trade. I'm sure it'll fit right\n"
	.string "into your team.$"

BattleCafe_ChooseShinyGenome_Text_0:
# 835 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for a\n"
	.string "Shiny Genome?$"

BattleCafe_ChooseShinyGenome_Text_1:
# 849 "data/maps/BattleCafe/scripts.pory"
	.string "A rare find. Use it on whichever\n"
	.string "Pokémon you want to bring out the\l"
	.string "shine.$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
# 859 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for two\n"
	.string "Gold Bottle Caps?$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
# 873 "data/maps/BattleCafe/scripts.pory"
	.string "Two Gold Bottle Caps, polished up and\n"
	.string "ready. Here you go!$"

BattleCafe_ChooseMoney_Text_0:
# 882 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "¥250,000?$"

BattleCafe_ChooseMoney_Text_1:
# 894 "data/maps/BattleCafe/scripts.pory"
	.string "Use it well, and perhaps spend a little\n"
	.string "on dessert!$"

BattleCafe_ChooseVitaminSetAtk_Text_0:
# 903 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Protein EX and Calcium EX?$"

BattleCafe_ChooseVitaminSetAtk_Text_1:
# 918 "data/maps/BattleCafe/scripts.pory"
	.string "Two Protein EX and two Calcium EX,\n"
	.string "power and wisdom!$"

BattleCafe_ChooseVitaminSetDef_Text_0:
# 927 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Iron EX and Zinc EX?$"

BattleCafe_ChooseVitaminSetDef_Text_1:
# 942 "data/maps/BattleCafe/scripts.pory"
	.string "Two Iron EX and two Zinc EX,\n"
	.string "time to bulk up!$"

BattleCafe_ChooseVitaminSetSpe_Text_0:
# 951 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 2 Café Points for\n"
	.string "two Carbos EX?$"

BattleCafe_ChooseVitaminSetSpe_Text_1:
# 966 "data/maps/BattleCafe/scripts.pory"
	.string "Two Carbos EX, ready to speed up!$"

BattleCafe_NotEnoughPoints_Text_0:
# 971 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 5 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughFourPoints_Text_0:
# 978 "data/maps/BattleCafe/scripts.pory"
	.string "The Shiny Genome costs 4 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughVitaminSetPoints_Text_0:
# 985 "data/maps/BattleCafe/scripts.pory"
	.string "You don't have enough Café Points for\n"
	.string "that vitamin set. \p"
	.string "Complete one of my\n"
	.string "challenges and try again!$"

BattleCafe_NotEnoughBagSpace_Text_0:
# 994 "data/maps/BattleCafe/scripts.pory"
	.string "Your Bag is too full for that prize.\n"
	.string "Make some room and come back whenever\l"
	.string "you're ready!$"

BattleCafe_Goodbye_Text_0:
# 1001 "data/maps/BattleCafe/scripts.pory"
	.string "Come back hungry for another battle!$"

BattleCafe_TrainerAthena_Text_0:
# 1018 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun? Let's try this\n"
	.string "again tomorrow!$"

BattleCafe_TrainerAthena_Text_1:
# 1023 "data/maps/BattleCafe/scripts.pory"
	.string "Let's see if you can survive this\n"
	.string "stall!$"

BattleCafe_TrainerAthena_Text_2:
# 1025 "data/maps/BattleCafe/scripts.pory"
	.string "Huh?$"

BattleCafe_TrainerAthena_Text_3:
# 1027 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun?$"

BattleCafe_TrainerDoves_Text_0:
# 1038 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when \n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerDoves_Text_1:
# 1044 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let me show you the power of \n"
	.string "Genesect!$"

BattleCafe_TrainerDoves_Text_2:
# 1046 "data/maps/BattleCafe/scripts.pory"
	.string "Banned again from Overused...$"

BattleCafe_TrainerDoves_Text_3:
# 1048 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when\n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerElton_Text_0:
# 1061 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Rematch tomorrow! Be there!$"

BattleCafe_TrainerElton_Text_1:
# 1065 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Let's have a battle with our\n"
	.string "favourite Pokémon!$"

BattleCafe_TrainerElton_Text_2:
# 1067 "data/maps/BattleCafe/scripts.pory"
	.string "You handled every trick I had!$"

BattleCafe_TrainerElton_Text_3:
# 1069 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Even Gengar's impressed, and it\n"
	.string "rarely takes a loss seriously.$"

BattleCafe_TrainerNem_Text_0:
# 1081 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Come back tomorrow.$"

BattleCafe_TrainerNem_Text_1:
# 1085 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Think fast!$"

BattleCafe_TrainerNem_Text_2:
# 1086 "data/maps/BattleCafe/scripts.pory"
	.string "I'll be watching.$"

BattleCafe_TrainerNem_Text_3:
# 1088 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: We can fight again tomorrow.$"

BattleCafe_TrainerBai_Text_0:
# 1099 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: That was a good match!\n"
	.string "Let's fight again tomorrow!$"

BattleCafe_TrainerBai_Text_1:
# 1104 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Let's see what you bring to \n"
	.string "the table!$"

BattleCafe_TrainerBai_Text_2:
# 1106 "data/maps/BattleCafe/scripts.pory"
	.string "Guess I'm cooked this time...$"

BattleCafe_TrainerBai_Text_3:
# 1108 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Good match! Let's try this again \n"
	.string "tomorrow!$"

BattleCafe_TrainerDrac_Text_0:
# 1120 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: You're really tough! Let's fight\n"
	.string "again tomorrow!$"

BattleCafe_TrainerDrac_Text_1:
# 1125 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: Care for a double battle?$"

BattleCafe_TrainerDrac_Text_2:
# 1126 "data/maps/BattleCafe/scripts.pory"
	.string "Soothed.$"

BattleCafe_TrainerMarina_Text_0:
# 1140 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper says the rain has\n"
	.string "passed for today. Tomorrow!$"

BattleCafe_TrainerMarina_Text_1:
# 1145 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper, call in the rain!\n"
	.string "Let's make some waves.$"

BattleCafe_TrainerMarina_Text_2:
# 1147 "data/maps/BattleCafe/scripts.pory"
	.string "You weathered the whole storm.$"

BattleCafe_TrainerMarina_Text_3:
# 1149 "data/maps/BattleCafe/scripts.pory"
	.string "Even Swampert couldn't stop you once\n"
	.string "you found your rhythm.$"

BattleCafe_TrainerTylarie_Text_0:
# 1161 "data/maps/BattleCafe/scripts.pory"
	.string "Steelix has settled down for\n"
	.string "lunch. We'll be ready tomorrow!$"

BattleCafe_TrainerTylarie_Text_1:
# 1166 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Let me show you how sturdy my\n"
	.string "team is!$"

BattleCafe_TrainerTylarie_Text_2:
# 1168 "data/maps/BattleCafe/scripts.pory"
	.string "Ouch.$"

BattleCafe_TrainerTylarie_Text_3:
# 1170 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Not bad. We can go at it again\n"
	.string "another day.$"
