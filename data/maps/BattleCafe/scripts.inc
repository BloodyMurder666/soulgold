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
# 95 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_6
BattleCafe_OwnerMenu_4:
# 103 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_11
BattleCafe_OwnerMenu_9:
# 112 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_3
# 113 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_OwnerMenu_15
# 114 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_OwnerMenu_15
BattleCafe_OwnerMenu_14:
# 136 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
# 144 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 145 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OwnerMenu_20
# 146 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OwnerMenu_21
# 147 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OwnerMenu_22
# 148 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OwnerMenu_23
# 149 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_OwnerMenu_24
# 150 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_OwnerMenu_25
# 151 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_Goodbye
	return

BattleCafe_OwnerMenu_2:
# 76 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_0
# 92 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_CAFE_INTRO_DONE
	goto BattleCafe_OwnerMenu_1

BattleCafe_OwnerMenu_5:
# 97 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_1
# 101 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_6:
# 96 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_OwnerMenu_5
	goto BattleCafe_OwnerMenu_4

BattleCafe_OwnerMenu_10:
# 105 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OwnerMenu_Text_2
# 109 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_11:
# 104 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_OwnerMenu_10
	goto BattleCafe_OwnerMenu_9

BattleCafe_OwnerMenu_15:
# 115 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OwnerMenu_Text_4, BattleCafe_OwnerMenu_Text_5, BattleCafe_OwnerMenu_Text_6, BattleCafe_OwnerMenu_Text_7, BattleCafe_OwnerMenu_Text_8, BattleCafe_OwnerMenu_Text_9, BattleCafe_OwnerMenu_Text_10, BattleCafe_OwnerMenu_Text_11
# 124 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 125 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OwnerMenu_28
# 126 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OwnerMenu_29
# 127 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OwnerMenu_30
# 128 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OwnerMenu_31
# 129 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_OwnerMenu_32
# 130 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_OwnerMenu_33
# 131 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_OwnerMenu_34
# 132 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_Goodbye
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_20:
# 145 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskDailyChallenge
	return

BattleCafe_OwnerMenu_21:
# 146 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskRushMode
	return

BattleCafe_OwnerMenu_22:
# 147 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperChallenge
	return

BattleCafe_OwnerMenu_23:
# 148 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperRush
	return

BattleCafe_OwnerMenu_24:
# 149 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_OwnerMenu_25:
# 150 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	return

BattleCafe_OwnerMenu_28:
# 125 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskDailyChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_29:
# 126 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskRushMode
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_30:
# 127 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperChallenge
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_31:
# 128 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskSuperRush
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_32:
# 129 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_33:
# 130 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_OwnerMenu_14

BattleCafe_OwnerMenu_34:
# 131 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	goto BattleCafe_OwnerMenu_14


BattleCafe_OptionsMenu::
# 156 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_OptionsMenu_Text_0
# 157 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OptionsMenu_Text_1, BattleCafe_OptionsMenu_Text_2, BattleCafe_OptionsMenu_Text_3, BattleCafe_OptionsMenu_Text_4, BattleCafe_OptionsMenu_Text_5
# 163 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 164 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OptionsMenu_2
# 165 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OptionsMenu_3
# 166 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OptionsMenu_4
# 167 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OptionsMenu_5
# 168 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_OptionsMenu_2:
# 164 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseBattleBgm
	return

BattleCafe_OptionsMenu_3:
# 165 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ViewHighScores
	return

BattleCafe_OptionsMenu_4:
# 166 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseInnates
	return

BattleCafe_OptionsMenu_5:
# 167 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainRules
	return


BattleCafe_ChooseBattleBgm::
# 173 "data/maps/BattleCafe/scripts.pory"
	call BattleFrontier_EventScript_ChooseBattleBgm
# 174 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ViewHighScores::
# 178 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 179 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_ShowRecordsWindow
# 180 "data/maps/BattleCafe/scripts.pory"
	waitbuttonpress
# 181 "data/maps/BattleCafe/scripts.pory"
	special RemoveRecordsWindow
# 182 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ChooseInnates::
# 186 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_NO_INNATES, BattleCafe_ChooseInnates_2
# 199 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_2, MSGBOX_YESNO
# 203 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleCafe_ChooseInnates_7
BattleCafe_ChooseInnates_1:
# 211 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	return

BattleCafe_ChooseInnates_2:
# 187 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_0, MSGBOX_YESNO
# 191 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleCafe_ChooseInnates_5
	goto BattleCafe_ChooseInnates_1

BattleCafe_ChooseInnates_5:
# 192 "data/maps/BattleCafe/scripts.pory"
	clearflag FLAG_BATTLE_CAFE_NO_INNATES
# 193 "data/maps/BattleCafe/scripts.pory"
	playse SE_SWITCH
# 194 "data/maps/BattleCafe/scripts.pory"
	waitse
# 195 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_1
	goto BattleCafe_ChooseInnates_1

BattleCafe_ChooseInnates_7:
# 204 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_NO_INNATES
# 205 "data/maps/BattleCafe/scripts.pory"
	playse SE_SWITCH
# 206 "data/maps/BattleCafe/scripts.pory"
	waitse
# 207 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_3
	goto BattleCafe_ChooseInnates_1


BattleCafe_ExplainRules::
# 215 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_0
# 225 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_1
# 232 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_2
# 240 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_3
# 247 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_ExplainRules_2
# 248 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_ExplainRules_2
BattleCafe_ExplainRules_1:
# 262 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ExplainRules_2:
# 249 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_4
# 255 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_5
	goto BattleCafe_ExplainRules_1


BattleCafe_AskDailyChallenge::
# 266 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON, BattleCafe_AskDailyChallenge_2
BattleCafe_AskDailyChallenge_1:
# 274 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_1, MSGBOX_YESNO
# 281 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskDailyChallenge_5
BattleCafe_AskDailyChallenge_4:
# 284 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
# 285 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskDailyChallenge_2:
# 267 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_0
# 272 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_1

BattleCafe_AskDailyChallenge_5:
# 282 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_4


BattleCafe_AskRushMode::
# 289 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_RUSH_WON, BattleCafe_AskRushMode_2
BattleCafe_AskRushMode_1:
# 297 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_1, MSGBOX_YESNO
# 304 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskRushMode_5
BattleCafe_AskRushMode_4:
# 307 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
# 308 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskRushMode_2:
# 290 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_0
# 295 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_1

BattleCafe_AskRushMode_5:
# 305 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_4


BattleCafe_AskSuperChallenge::
# 312 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_AskSuperChallenge_2
BattleCafe_AskSuperChallenge_1:
# 320 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 321 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperChallenge_5
BattleCafe_AskSuperChallenge_4:
# 327 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_2, MSGBOX_YESNO
# 333 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperChallenge_8
BattleCafe_AskSuperChallenge_7:
# 336 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
# 337 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperChallenge_2:
# 313 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_0
# 318 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_1

BattleCafe_AskSuperChallenge_5:
# 322 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_1
# 325 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_4

BattleCafe_AskSuperChallenge_8:
# 334 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_7


BattleCafe_AskSuperRush::
# 341 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_AskSuperRush_2
BattleCafe_AskSuperRush_1:
# 349 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 350 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperRush_5
BattleCafe_AskSuperRush_4:
# 358 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_2, MSGBOX_YESNO
# 365 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperRush_8
BattleCafe_AskSuperRush_7:
# 368 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
# 369 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperRush_2:
# 342 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_0
# 347 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_1

BattleCafe_AskSuperRush_5:
# 351 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_1
# 356 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_4

BattleCafe_AskSuperRush_8:
# 366 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_7


BattleCafe_EndlessMenu::
# 373 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessMenu_Text_0
# 374 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_EndlessMenu_Text_1, BattleCafe_EndlessMenu_Text_2, BattleCafe_EndlessMenu_Text_3, BattleCafe_OptionsMenu_Text_5
# 379 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 380 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_EndlessMenu_2
# 381 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_EndlessMenu_3
# 382 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_EndlessMenu_4
# 383 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_EndlessMenu_2:
# 380 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessChallenge
	return

BattleCafe_EndlessMenu_3:
# 381 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessRush
	return

BattleCafe_EndlessMenu_4:
# 382 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainEndlessRules
	return


BattleCafe_ExplainEndlessRules::
# 388 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_0
# 395 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_1
# 402 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_2
# 405 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	return


BattleCafe_AskEndlessChallenge::
# 409 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_AskEndlessChallenge_2
BattleCafe_AskEndlessChallenge_1:
# 414 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 415 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessChallenge_5
BattleCafe_AskEndlessChallenge_4:
# 423 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_2, MSGBOX_YESNO
# 430 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessChallenge_8
BattleCafe_AskEndlessChallenge_7:
# 433 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
# 434 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessChallenge_2:
# 410 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_0
# 412 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_1

BattleCafe_AskEndlessChallenge_5:
# 416 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 421 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_4

BattleCafe_AskEndlessChallenge_8:
# 431 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_7


BattleCafe_AskEndlessRush::
# 438 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_AskEndlessRush_2
BattleCafe_AskEndlessRush_1:
# 443 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 444 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessRush_5
BattleCafe_AskEndlessRush_4:
# 452 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_1, MSGBOX_YESNO
# 459 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessRush_8
BattleCafe_AskEndlessRush_7:
# 462 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
# 463 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessRush_2:
# 439 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_0
# 441 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_1

BattleCafe_AskEndlessRush_5:
# 445 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 450 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_4

BattleCafe_AskEndlessRush_8:
# 460 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_7


BattleCafe_BeginChallenge::
# 467 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 468 "data/maps/BattleCafe/scripts.pory"
	hidefollower
# 469 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 470 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_InitChallenge
# 471 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 13, DIR_EAST
# 472 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 473 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_9, 0
# 474 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 475 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_BeginChallenge_2
# 476 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_BeginChallenge_2
# 480 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_1
BattleCafe_BeginChallenge_1:
# 483 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 484 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_BeginChallenge_2:
# 477 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_0
	goto BattleCafe_BeginChallenge_1


BattleCafe_ChallengeNextRound::
# 488 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_RunRound
# 489 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChallengeNextRound_2
BattleCafe_ChallengeNextRound_1:
# 493 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AdvanceWinCount
# 494 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_5
BattleCafe_ChallengeNextRound_4:
# 515 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_8
BattleCafe_ChallengeNextRound_7:
# 547 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_9, 3
	goto_if_ge BattleCafe_ChallengeNextRound_14
BattleCafe_ChallengeNextRound_13:
# 551 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeNextRound_21
# 557 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_27
# 563 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_30
# 567 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_6
BattleCafe_ChallengeNextRound_20:
# 572 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 573 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_ChallengeNextRound_2:
# 490 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeLost
	goto BattleCafe_ChallengeNextRound_1

BattleCafe_ChallengeNextRound_5:
# 495 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 1
# 496 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 497 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 498 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 499 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 500 "data/maps/BattleCafe/scripts.pory"
	waitse
# 501 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 502 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 503 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_0, MSGBOX_YESNO
# 508 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_11
BattleCafe_ChallengeNextRound_10:
# 511 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 512 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_4

BattleCafe_ChallengeNextRound_8:
# 516 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 2
# 517 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 518 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 519 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_TEMP_C, 1
# 520 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 521 "data/maps/BattleCafe/scripts.pory"
	waitse
# 522 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 523 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 524 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, 3
	goto_if_ge BattleCafe_ChallengeNextRound_17
# 534 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_2, MSGBOX_YESNO
BattleCafe_ChallengeNextRound_16:
# 540 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_25
BattleCafe_ChallengeNextRound_24:
# 543 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 544 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_11:
# 509 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_10

BattleCafe_ChallengeNextRound_14:
# 548 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeWon
	goto BattleCafe_ChallengeNextRound_13

BattleCafe_ChallengeNextRound_17:
# 525 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 526 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 527 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 528 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_1, MSGBOX_YESNO
	goto BattleCafe_ChallengeNextRound_16

BattleCafe_ChallengeNextRound_21:
# 552 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 553 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 554 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_3
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_25:
# 541 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_24

BattleCafe_ChallengeNextRound_27:
# 558 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 559 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 560 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_4
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_30:
# 564 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_5
	goto BattleCafe_ChallengeNextRound_20


BattleCafe_EndlessRetired::
# 577 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 578 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 579 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 580 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 581 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 582 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 583 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 584 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessRetired_Text_0
# 588 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_RunRound::
# 592 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_9
# 593 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_SelectOpponent
# 594 "data/maps/BattleCafe/scripts.pory"
	setobjectxy LOCALID_BATTLE_CAFE_OPPONENT, 14, 17
# 595 "data/maps/BattleCafe/scripts.pory"
	addobject LOCALID_BATTLE_CAFE_OPPONENT
# 596 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 10, 13, DIR_WEST
# 597 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 598 "data/maps/BattleCafe/scripts.pory"
	tower_getopponentintro FRONTIER_BEFORE_TEXT
# 599 "data/maps/BattleCafe/scripts.pory"
	msgbox gStringVar4
# 600 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 601 "data/maps/BattleCafe/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_CAFE
# 602 "data/maps/BattleCafe/scripts.pory"
	waitstate
# 603 "data/maps/BattleCafe/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 604 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 606 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 14, 17, DIR_EAST
# 607 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 608 "data/maps/BattleCafe/scripts.pory"
	removeobject LOCALID_BATTLE_CAFE_OPPONENT
# 610 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_A, B_OUTCOME_WON
	goto_if_eq BattleCafe_RunRound_2
# 613 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, FALSE
BattleCafe_RunRound_1:
	return

BattleCafe_RunRound_2:
# 611 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, TRUE
	goto BattleCafe_RunRound_1


BattleCafe_ChallengeLost::
# 619 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 620 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 621 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 622 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 623 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 624 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeLost_2
# 625 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeLost_2
# 635 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_1
BattleCafe_ChallengeLost_1:
# 642 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeLost_2:
# 626 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 627 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_0
	goto BattleCafe_ChallengeLost_1


BattleCafe_ChallengeWon::
# 646 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 647 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 648 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 649 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 650 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 652 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeWon_2
# 662 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto_if_eq BattleCafe_ChallengeWon_5
# 673 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeWon_8
# 684 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON
# 685 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 10
# 686 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 687 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 688 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 689 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_3
BattleCafe_ChallengeWon_1:
# 699 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_UnlockClearAchievement
# 700 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 701 "data/maps/BattleCafe/scripts.pory"
	waitse
# 702 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeWon_2:
# 653 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON
# 654 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 3
# 655 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 656 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 657 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 658 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_0
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_5:
# 663 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_RUSH_WON
# 664 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 665 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 666 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 667 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 668 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_1
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_8:
# 674 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON
# 675 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 676 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 677 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 678 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 679 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_2
	goto BattleCafe_ChallengeWon_1


BattleCafe_RewardMenu::
# 706 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_BATTLE_CAFE_POINTS
# 707 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_RewardMenu_Text_0
# 709 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_GetParadoxRewardEligibility
# 710 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 711 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_1, 10
# 712 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_2, 11
# 713 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_3, 12
# 714 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_4, 7
# 715 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_5, 8
# 716 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_6, 9
# 717 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_7, 0
# 718 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_8, 1
# 719 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_9, 2
# 720 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_10, 3
# 721 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_11, 4
# 722 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_12, 5
# 723 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_13, 6
# 724 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_14, 16
# 725 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_15, 17
# 726 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_16, 18
# 727 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_17, 19
# 728 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON
	goto_if_eq BattleCafe_RewardMenu_2
# 729 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_2
BattleCafe_RewardMenu_1:
# 732 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
# 733 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
BattleCafe_RewardMenu_6:
# 736 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_OptionsMenu_Text_5, 15
# 737 "data/maps/BattleCafe/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 10, DYN_MULTICHOICE_CB_NONE
# 738 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 739 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_RewardMenu_12
# 740 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_RewardMenu_13
# 741 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_RewardMenu_14
# 742 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_RewardMenu_15
# 743 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_RewardMenu_16
# 744 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_RewardMenu_17
# 745 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_RewardMenu_18
# 746 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_RewardMenu_19
# 747 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_RewardMenu_20
# 748 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_RewardMenu_21
# 749 "data/maps/BattleCafe/scripts.pory"
	case 10, BattleCafe_RewardMenu_22
# 750 "data/maps/BattleCafe/scripts.pory"
	case 11, BattleCafe_RewardMenu_23
# 751 "data/maps/BattleCafe/scripts.pory"
	case 12, BattleCafe_RewardMenu_24
# 752 "data/maps/BattleCafe/scripts.pory"
	case 13, BattleCafe_RewardMenu_25
# 753 "data/maps/BattleCafe/scripts.pory"
	case 14, BattleCafe_RewardMenu_26
# 754 "data/maps/BattleCafe/scripts.pory"
	case 16, BattleCafe_RewardMenu_27
# 755 "data/maps/BattleCafe/scripts.pory"
	case 17, BattleCafe_RewardMenu_28
# 756 "data/maps/BattleCafe/scripts.pory"
	case 18, BattleCafe_RewardMenu_29
# 757 "data/maps/BattleCafe/scripts.pory"
	case 19, BattleCafe_RewardMenu_30
# 758 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
# 730 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_18, 13
	goto BattleCafe_RewardMenu_1

BattleCafe_RewardMenu_7:
# 734 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_19, 14
	goto BattleCafe_RewardMenu_6

BattleCafe_RewardMenu_12:
# 739 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_13:
# 740 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_14:
# 741 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_15:
# 742 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTornadus
	return

BattleCafe_RewardMenu_16:
# 743 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseThundurus
	return

BattleCafe_RewardMenu_17:
# 744 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseLandorus
	return

BattleCafe_RewardMenu_18:
# 745 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseEnamorus
	return

BattleCafe_RewardMenu_19:
# 746 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_20:
# 747 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_21:
# 748 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoney
	return

BattleCafe_RewardMenu_22:
# 749 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetAtk
	return

BattleCafe_RewardMenu_23:
# 750 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetDef
	return

BattleCafe_RewardMenu_24:
# 751 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetSpe
	return

BattleCafe_RewardMenu_25:
# 752 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMiraidon
	return

BattleCafe_RewardMenu_26:
# 753 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseKoraidon
	return

BattleCafe_RewardMenu_27:
# 754 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuKoko
	return

BattleCafe_RewardMenu_28:
# 755 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuLele
	return

BattleCafe_RewardMenu_29:
# 756 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuBulu
	return

BattleCafe_RewardMenu_30:
# 757 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuFini
	return


BattleCafe_ChooseArticuno::
# 763 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
# 768 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
# 769 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 770 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
# 764 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseArticuno_Text_0
# 766 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
# 774 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
# 779 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
# 780 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 781 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
# 775 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseZapdos_Text_0
# 777 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
# 785 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
# 790 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
# 791 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 2
# 792 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
# 786 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoltres_Text_0
# 788 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ChooseTornadus::
# 796 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TORNADUS_RECEIVED, BattleCafe_ChooseTornadus_2
BattleCafe_ChooseTornadus_1:
# 801 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS
# 802 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 3
# 803 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTornadus_2:
# 797 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTornadus_Text_0
# 799 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTornadus_1


BattleCafe_ChooseThundurus::
# 807 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED, BattleCafe_ChooseThundurus_2
BattleCafe_ChooseThundurus_1:
# 812 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS
# 813 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 4
# 814 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseThundurus_2:
# 808 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseThundurus_Text_0
# 810 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseThundurus_1


BattleCafe_ChooseLandorus::
# 818 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_LANDORUS_RECEIVED, BattleCafe_ChooseLandorus_2
BattleCafe_ChooseLandorus_1:
# 823 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS
# 824 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 5
# 825 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseLandorus_2:
# 819 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseLandorus_Text_0
# 821 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseLandorus_1


BattleCafe_ChooseEnamorus::
# 829 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED, BattleCafe_ChooseEnamorus_2
BattleCafe_ChooseEnamorus_1:
# 834 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENAMORUS
# 835 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 6
# 836 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseEnamorus_2:
# 830 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseEnamorus_Text_0
# 832 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseEnamorus_1


BattleCafe_ChooseTapuKoko::
# 840 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED, BattleCafe_ChooseTapuKoko_2
BattleCafe_ChooseTapuKoko_1:
# 845 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO
# 846 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 7
# 847 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuKoko_2:
# 841 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuKoko_Text_0
# 843 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuKoko_1


BattleCafe_ChooseTapuLele::
# 851 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED, BattleCafe_ChooseTapuLele_2
BattleCafe_ChooseTapuLele_1:
# 856 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE
# 857 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 8
# 858 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuLele_2:
# 852 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuLele_Text_0
# 854 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuLele_1


BattleCafe_ChooseTapuBulu::
# 862 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED, BattleCafe_ChooseTapuBulu_2
BattleCafe_ChooseTapuBulu_1:
# 867 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU
# 868 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 9
# 869 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuBulu_2:
# 863 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuBulu_Text_0
# 865 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuBulu_1


BattleCafe_ChooseTapuFini::
# 873 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED, BattleCafe_ChooseTapuFini_2
BattleCafe_ChooseTapuFini_1:
# 878 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI
# 879 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 10
# 880 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuFini_2:
# 874 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuFini_Text_0
# 876 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuFini_1


BattleCafe_ConfirmRewardMon::
# 884 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
# 887 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 888 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
# 890 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
# 894 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_10
BattleCafe_ConfirmRewardMon_7:
# 901 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 902 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_15
BattleCafe_ConfirmRewardMon_14:
# 905 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 906 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 907 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 908 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 909 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 910 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmRewardMon_21
# 911 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmRewardMon_22
# 912 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_ConfirmRewardMon_23
# 913 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_ConfirmRewardMon_24
# 914 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_ConfirmRewardMon_25
# 915 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_ConfirmRewardMon_26
# 916 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_ConfirmRewardMon_27
# 917 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_ConfirmRewardMon_28
# 918 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_ConfirmRewardMon_29
# 919 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_ConfirmRewardMon_30
# 920 "data/maps/BattleCafe/scripts.pory"
	case 10, BattleCafe_ConfirmRewardMon_31
BattleCafe_ConfirmRewardMon_19:
# 922 "data/maps/BattleCafe/scripts.pory"
	special Achievement_CheckAll
# 923 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_34
BattleCafe_ConfirmRewardMon_32:
# 929 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_2
# 931 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
# 885 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
# 891 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
# 895 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_REVEAL_GLASS, 1
# 896 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_17
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_9:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_8
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_10:
# 894 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_9
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_15:
# 903 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_14

BattleCafe_ConfirmRewardMon_17:
# 897 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_21:
# 910 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_22:
# 911 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_23:
# 912 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_24:
# 913 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TORNADUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_25:
# 914 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_26:
# 915 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_LANDORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_27:
# 916 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_28:
# 917 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_29:
# 918 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_30:
# 919 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_31:
# 920 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_33:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_37
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_34:
# 923 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_33
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_37:
# 925 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_1
# 926 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
	goto BattleCafe_ConfirmRewardMon_32


BattleCafe_ChooseMiraidon::
# 935 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED, BattleCafe_ChooseMiraidon_2
BattleCafe_ChooseMiraidon_1:
# 940 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MIRAIDON
# 941 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 942 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseMiraidon_2:
# 936 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMiraidon_Text_0
# 938 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMiraidon_1


BattleCafe_ChooseKoraidon::
# 946 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_KORAIDON_RECEIVED, BattleCafe_ChooseKoraidon_2
BattleCafe_ChooseKoraidon_1:
# 951 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KORAIDON
# 952 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 953 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseKoraidon_2:
# 947 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseKoraidon_Text_0
# 949 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseKoraidon_1


BattleCafe_ConfirmParadoxLegend::
# 957 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 25
	goto_if_lt BattleCafe_ConfirmParadoxLegend_2
BattleCafe_ConfirmParadoxLegend_1:
# 960 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 961 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmParadoxLegend_Text_0, MSGBOX_YESNO
# 963 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmParadoxLegend_5
BattleCafe_ConfirmParadoxLegend_4:
# 966 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 967 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmParadoxLegend_8
BattleCafe_ConfirmParadoxLegend_7:
# 970 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 971 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 972 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 973 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 25
# 974 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 975 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmParadoxLegend_12
# 976 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmParadoxLegend_13
BattleCafe_ConfirmParadoxLegend_10:
# 978 "data/maps/BattleCafe/scripts.pory"
	special Achievement_CheckAll
# 979 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmParadoxLegend_Text_1
# 981 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmParadoxLegend_2:
# 958 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughLegendPoints
	goto BattleCafe_ConfirmParadoxLegend_1

BattleCafe_ConfirmParadoxLegend_5:
# 964 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmParadoxLegend_4

BattleCafe_ConfirmParadoxLegend_8:
# 968 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmParadoxLegend_7

BattleCafe_ConfirmParadoxLegend_12:
# 975 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10

BattleCafe_ConfirmParadoxLegend_13:
# 976 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_KORAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10


BattleCafe_ChooseShinyGenome::
# 985 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
# 988 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
# 990 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
# 993 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_SHIN_GENOME, 1
# 994 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
# 997 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 998 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
# 1001 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 4
# 1002 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_1
# 1005 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
# 986 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
# 991 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
# 995 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
# 999 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
# 1009 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
# 1012 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
# 1014 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
# 1017 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
# 1018 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
# 1021 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
# 1022 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
# 1025 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 1026 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
# 1028 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
# 1010 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
# 1015 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
# 1019 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
# 1023 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
# 1032 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
# 1035 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
# 1037 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
# 1040 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 1041 "data/maps/BattleCafe/scripts.pory"
	showmoneybox 0, 0
# 1042 "data/maps/BattleCafe/scripts.pory"
	addmoney 250000
# 1043 "data/maps/BattleCafe/scripts.pory"
	updatemoneybox 0
# 1044 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1045 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1046 "data/maps/BattleCafe/scripts.pory"
	hidemoneybox
# 1047 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_1
# 1049 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
# 1033 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
# 1038 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_ChooseVitaminSetAtk::
# 1053 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetAtk_2
BattleCafe_ChooseVitaminSetAtk_1:
# 1056 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_0, MSGBOX_YESNO
# 1058 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_5
BattleCafe_ChooseVitaminSetAtk_4:
# 1061 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_ATK
# 1062 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1063 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetAtk_8
BattleCafe_ChooseVitaminSetAtk_7:
# 1066 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_11
BattleCafe_ChooseVitaminSetAtk_10:
# 1069 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1070 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1071 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_1
# 1073 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetAtk_2:
# 1054 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_1

BattleCafe_ChooseVitaminSetAtk_5:
# 1059 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetAtk_4

BattleCafe_ChooseVitaminSetAtk_8:
# 1064 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_7

BattleCafe_ChooseVitaminSetAtk_11:
# 1067 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetAtk_10


BattleCafe_ChooseVitaminSetDef::
# 1077 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetDef_2
BattleCafe_ChooseVitaminSetDef_1:
# 1080 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_0, MSGBOX_YESNO
# 1082 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetDef_5
BattleCafe_ChooseVitaminSetDef_4:
# 1085 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_DEF
# 1086 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1087 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetDef_8
BattleCafe_ChooseVitaminSetDef_7:
# 1090 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetDef_11
BattleCafe_ChooseVitaminSetDef_10:
# 1093 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1094 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1095 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_1
# 1097 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetDef_2:
# 1078 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_1

BattleCafe_ChooseVitaminSetDef_5:
# 1083 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetDef_4

BattleCafe_ChooseVitaminSetDef_8:
# 1088 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_7

BattleCafe_ChooseVitaminSetDef_11:
# 1091 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetDef_10


BattleCafe_ChooseVitaminSetSpe::
# 1101 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 2
	goto_if_lt BattleCafe_ChooseVitaminSetSpe_2
BattleCafe_ChooseVitaminSetSpe_1:
# 1104 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_0, MSGBOX_YESNO
# 1106 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_5
BattleCafe_ChooseVitaminSetSpe_4:
# 1109 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_SPE
# 1110 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1111 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetSpe_8
BattleCafe_ChooseVitaminSetSpe_7:
# 1114 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_11
BattleCafe_ChooseVitaminSetSpe_10:
# 1117 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1118 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1119 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_1
# 1120 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetSpe_2:
# 1102 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_1

BattleCafe_ChooseVitaminSetSpe_5:
# 1107 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetSpe_4

BattleCafe_ChooseVitaminSetSpe_8:
# 1112 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_7

BattleCafe_ChooseVitaminSetSpe_11:
# 1115 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetSpe_10


BattleCafe_NotEnoughPoints::
# 1124 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughPoints_Text_0
# 1127 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughLegendPoints::
# 1131 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughLegendPoints_Text_0
# 1134 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
# 1138 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
# 1141 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughVitaminSetPoints::
# 1145 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughVitaminSetPoints_Text_0
# 1150 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
# 1154 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
# 1157 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
# 1161 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_Goodbye_Text_0
# 1162 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDailyCandyReward::
# 1167 "data/maps/BattleCafe/scripts.pory"
	random 3
# 1168 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_RESULT, 1
# 1169 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, VAR_RESULT
	return


BattleCafe_TrainerAthena::
# 1174 "data/maps/BattleCafe/scripts.pory"
	lock
# 1175 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1177 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ATHENA, BattleCafe_TrainerAthena_2
# 1183 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_1
# 1185 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ATHENA, BattleCafe_TrainerAthena_Text_2
# 1186 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ATHENA
# 1187 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_3
# 1188 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1189 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAthena_2:
# 1178 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_0
# 1180 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDoves::
# 1194 "data/maps/BattleCafe/scripts.pory"
	lock
# 1195 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1197 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DOVES, BattleCafe_TrainerDoves_2
# 1204 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_1
# 1206 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DOVES, BattleCafe_TrainerDoves_Text_2
# 1207 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DOVES
# 1208 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_3
# 1211 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1212 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDoves_2:
# 1198 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_0
# 1201 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerElton::
# 1217 "data/maps/BattleCafe/scripts.pory"
	lock
# 1218 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1220 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ELTON, BattleCafe_TrainerElton_2
# 1225 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_1
# 1227 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ELTON, BattleCafe_TrainerElton_Text_2
# 1228 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ELTON
# 1229 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_3
# 1231 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1232 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerElton_2:
# 1221 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_0
# 1222 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerNem::
# 1237 "data/maps/BattleCafe/scripts.pory"
	lock
# 1238 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1240 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_NEM, BattleCafe_TrainerNem_2
# 1245 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_1
# 1246 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_NEM, BattleCafe_TrainerNem_Text_2
# 1247 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_NEM
# 1248 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_3
# 1249 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1250 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerNem_2:
# 1241 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_0
# 1242 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerBai::
# 1255 "data/maps/BattleCafe/scripts.pory"
	lock
# 1256 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1258 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_BAI, BattleCafe_TrainerBai_2
# 1264 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_1
# 1266 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_BAI, BattleCafe_TrainerBai_Text_2
# 1267 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_BAI
# 1268 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_3
# 1270 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1271 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerBai_2:
# 1259 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_0
# 1261 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDrac::
# 1276 "data/maps/BattleCafe/scripts.pory"
	lock
# 1277 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1279 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DRAC, BattleCafe_TrainerDrac_2
# 1285 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_1
# 1286 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DRAC, BattleCafe_TrainerDrac_Text_2
# 1287 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DRAC
# 1288 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1290 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1291 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDrac_2:
# 1280 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1282 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerSimpli::
# 1296 "data/maps/BattleCafe/scripts.pory"
	lock
# 1297 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1299 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SIMPLI, BattleCafe_TrainerSimpli_2
# 1304 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerSimpli_Text_1
# 1305 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerSimpli_Text_2
# 1306 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SIMPLI
# 1307 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerSimpli_Text_3
# 1308 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1309 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerSimpli_2:
# 1300 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerSimpli_Text_0
# 1301 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerTylarie::
# 1314 "data/maps/BattleCafe/scripts.pory"
	lock
# 1315 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1317 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_TYLARIE, BattleCafe_TrainerTylarie_2
# 1323 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_1
# 1325 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_TYLARIE, BattleCafe_TrainerTylarie_Text_2
# 1326 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_TYLARIE
# 1327 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_3
# 1329 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1330 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerTylarie_2:
# 1318 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerTylarie_Text_0
# 1320 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_FreshWaterFountain::
# 1335 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_GOT_FRESH_WATER, BattleCafe_FreshWaterFountain_1
# 1338 "data/maps/BattleCafe/scripts.pory"
	lock
# 1339 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_FreshWaterFountain_Text_1
# 1341 "data/maps/BattleCafe/scripts.pory"
	finditem ITEM_FRESH_WATER
# 1342 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_GOT_FRESH_WATER
# 1343 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_FreshWaterFountain_Text_2
# 1344 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_FreshWaterFountain_1:
# 1336 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_FreshWaterFountain_Text_0, MSGBOX_SIGN
	return


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
	.string "However I must warn you that all the\n"
	.string "regulars here are really tough!\p"
	.string "Anyway, enough about me...$"

BattleCafe_OwnerMenu_Text_1:
# 97 "data/maps/BattleCafe/scripts.pory"
	.string "After seeing you clear Super Challenge,\n"
	.string "I can offer you a new format:\p"
	.string "Endless Challenge!$"

BattleCafe_OwnerMenu_Text_2:
# 105 "data/maps/BattleCafe/scripts.pory"
	.string "After seeing you conquer Super Rush,\n"
	.string "I can offer you one final format:\p"
	.string "Endless Rush!$"

BattleCafe_OwnerMenu_Text_3:
# 112 "data/maps/BattleCafe/scripts.pory"
	.string "Welcome! What'll it be today?$"

BattleCafe_OwnerMenu_Text_4:
# 116 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge$"

BattleCafe_OwnerMenu_Text_5:
# 117 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode$"

BattleCafe_OwnerMenu_Text_6:
# 118 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge$"

BattleCafe_OwnerMenu_Text_7:
# 119 "data/maps/BattleCafe/scripts.pory"
	.string "Super Rush$"

BattleCafe_OwnerMenu_Text_8:
# 120 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Modes$"

BattleCafe_OwnerMenu_Text_9:
# 121 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange Points$"

BattleCafe_OwnerMenu_Text_10:
# 122 "data/maps/BattleCafe/scripts.pory"
	.string "Café Options$"

BattleCafe_OwnerMenu_Text_11:
# 123 "data/maps/BattleCafe/scripts.pory"
	.string "Leave$"

BattleCafe_OptionsMenu_Text_0:
# 156 "data/maps/BattleCafe/scripts.pory"
	.string "What would you like to check?$"

BattleCafe_OptionsMenu_Text_1:
# 158 "data/maps/BattleCafe/scripts.pory"
	.string "Battle BGM$"

BattleCafe_OptionsMenu_Text_2:
# 159 "data/maps/BattleCafe/scripts.pory"
	.string "High Scores$"

BattleCafe_OptionsMenu_Text_3:
# 160 "data/maps/BattleCafe/scripts.pory"
	.string "Innates$"

BattleCafe_OptionsMenu_Text_4:
# 161 "data/maps/BattleCafe/scripts.pory"
	.string "Café Rules$"

BattleCafe_OptionsMenu_Text_5:
# 162 "data/maps/BattleCafe/scripts.pory"
	.string "Back$"

BattleCafe_ChooseInnates_Text_0:
# 187 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are disabled for both sides\n"
	.string "in every Café challenge.\p"
	.string "Enable innates?$"

BattleCafe_ChooseInnates_Text_1:
# 195 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are now enabled for\n"
	.string "all Café challenges.$"

BattleCafe_ChooseInnates_Text_2:
# 199 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are enabled for both sides\n"
	.string "in every Café challenge.\p"
	.string "Disable innates?$"

BattleCafe_ChooseInnates_Text_3:
# 207 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are now disabled for\n"
	.string "all Café challenges.$"

BattleCafe_ExplainRules_Text_0:
# 215 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors will answer each\n"
	.string "challenge, one after another.\p"
	.string "In the Daily Challenge, they bring\n"
	.string "dependable teams of four.\p"
	.string "I'll tend to your Pokémon after each\n"
	.string "battle.\p"
	.string "Win all three for 3 Café Points.$"

BattleCafe_ExplainRules_Text_1:
# 225 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode draws seasoned battlers with\n"
	.string "teams of four.\p"
	.string "Anything goes, and I can't heal\n"
	.string "your Pokémon between the matches.\p"
	.string "Win all three for 5 points.$"

BattleCafe_ExplainRules_Text_2:
# 232 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge and Super Rush pit\n"
	.string "you against full teams of six Pokémon.\p"
	.string "Anyone might show up so prepare to\n"
	.string "face literally anything.\p"
	.string "Same rules apply here for healing\n"
	.string "between the rounds.$"

BattleCafe_ExplainRules_Text_3:
# 240 "data/maps/BattleCafe/scripts.pory"
	.string "There are no breaks once service\n"
	.string "begins.\p"
	.string "A loss ends the run, though\n"
	.string "you may retry until you win.\p"
	.string "Each challenge can be won once per day.$"

BattleCafe_ExplainRules_Text_4:
# 249 "data/maps/BattleCafe/scripts.pory"
	.string "Both Endless formats use full teams\n"
	.string "of six and continue until you lose\l"
	.string "or choose to retire.\p"
	.string "Endless Challenge heals your party\n"
	.string "after every win and awards 1 point.$"

BattleCafe_ExplainRules_Text_5:
# 255 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party\n"
	.string "after every third victory and awards\l"
	.string "2 points per win.\p"
	.string "Your best streak in each format is\n"
	.string "saved under High Scores.$"

BattleCafe_AskDailyChallenge_Text_0:
# 267 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Daily Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or try another challenge!$"

BattleCafe_AskDailyChallenge_Text_1:
# 274 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors are ready with\n"
	.string "teams of four.\p"
	.string "I'll tend to your party\n"
	.string "after rounds one and two.\p"
	.string "Begin today's challenge?$"

BattleCafe_AskRushMode_Text_0:
# 290 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Rush Mode\n"
	.string "today.\p"
	.string "Come back tomorrow, or take\n"
	.string "another challenge!$"

BattleCafe_AskRushMode_Text_1:
# 297 "data/maps/BattleCafe/scripts.pory"
	.string "Three seasoned visitors are waiting\n"
	.string "with teams of four.\p"
	.string "I can't tend to your party between \n"
	.string "these battles.\p"
	.string "Begin today's rush?$"

BattleCafe_AskSuperChallenge_Text_0:
# 313 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Super Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or attempt another challenge!$"

BattleCafe_AskSuperChallenge_Text_1:
# 322 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Challenge. Bring a full party of six\l"
	.string "before entering.$"

BattleCafe_AskSuperChallenge_Text_2:
# 327 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each meet your full\n"
	.string "party with six Pokémon of their own.\p"
	.string "I'll tend to your team between battles.\p"
	.string "Begin the Super Challenge?$"

BattleCafe_AskSuperRush_Text_0:
# 342 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Super Rush\n"
	.string "today.\p"
	.string "Come back tomorrow for\n"
	.string "another full-team trial!$"

BattleCafe_AskSuperRush_Text_1:
# 351 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Rush.\p"
	.string "Bring a full party of six\n"
	.string "before entering.$"

BattleCafe_AskSuperRush_Text_2:
# 358 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each bring a full\n"
	.string "team of six.\p"
	.string "Once the rush begins, I can't heal\n"
	.string "your Pokémon between the battles.\p"
	.string "Begin the Super Rush?$"

BattleCafe_EndlessMenu_Text_0:
# 373 "data/maps/BattleCafe/scripts.pory"
	.string "Which Endless format will you try?$"

BattleCafe_EndlessMenu_Text_1:
# 375 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge$"

BattleCafe_EndlessMenu_Text_2:
# 376 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush$"

BattleCafe_EndlessMenu_Text_3:
# 377 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rules$"

BattleCafe_ExplainEndlessRules_Text_0:
# 388 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge restores your party\n"
	.string "after every victory. \p"
	.string "Each win immediately awards 1 \n"
	.string "Café Point.\p"
	.string "Clear Super Challenge to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_1:
# 395 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party after\n"
	.string "every third victory. \p"
	.string "Each win immediately awards 2 \n"
	.string "Café Points.\p"
	.string "Clear Super Rush to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_2:
# 402 "data/maps/BattleCafe/scripts.pory"
	.string "Both formats use full 6-vs-6 battles.\n"
	.string "You may retire after any victory,\l"
	.string "and your best streak is saved.$"

BattleCafe_AskEndlessChallenge_Text_0:
# 410 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Challenge to unlock\n"
	.string "Endless Challenge.$"

BattleCafe_AskEndlessChallenge_Text_1:
# 416 "data/maps/BattleCafe/scripts.pory"
	.string "Every Endless opponent brings\n"
	.string "six Pokémon.\p"
	.string "Bring a full party of six before\n"
	.string "taking your seat.$"

BattleCafe_AskEndlessChallenge_Text_2:
# 423 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every win,\n"
	.string "and each victory earns 1 Café Point.\p"
	.string "Begin Endless Challenge?$"

BattleCafe_AskEndlessRush_Text_0:
# 439 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Rush to unlock\n"
	.string "Endless Rush.$"

BattleCafe_AskEndlessRush_Text_1:
# 452 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every third\n"
	.string "victory. Each win earns 2 Café Points.\p"
	.string "Begin Endless Rush?$"

BattleCafe_BeginChallenge_Text_0:
# 477 "data/maps/BattleCafe/scripts.pory"
	.string "No final course. No final opponent.\n"
	.string "Endless service begins now!$"

BattleCafe_BeginChallenge_Text_1:
# 480 "data/maps/BattleCafe/scripts.pory"
	.string "Three courses. Three opponents.\n"
	.string "Service begins now!$"

BattleCafe_ChallengeNextRound_Text_0:
# 503 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points,\l"
	.string "and your party was restored.\p"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_1:
# 528 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Three battles cleared! Your party\n"
	.string "was restored. Continue the run?$"

BattleCafe_ChallengeNextRound_Text_2:
# 534 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Your party has not been restored.\n"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_3:
# 554 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next challenger is arriving!$"

BattleCafe_ChallengeNextRound_Text_4:
# 560 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_5:
# 564 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Super Rush!\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_6:
# 567 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Rush Mode!\n"
	.string "The next challenger is arriving!$"

BattleCafe_EndlessRetired_Text_0:
# 584 "data/maps/BattleCafe/scripts.pory"
	.string "Run retired at {STR_VAR_1} wins.\p"
	.string "Your party is fully restored, your record\n"
	.string "is safe, and every point is yours to keep.$"

BattleCafe_ChallengeLost_Text_0:
# 627 "data/maps/BattleCafe/scripts.pory"
	.string "Your Endless run ends at {STR_VAR_1}\n"
	.string "wins. I've fully\l"
	.string "restored your party.\p"
	.string "Every Café Point you earned is yours\n"
	.string "to keep. Try to push even farther\l"
	.string "next time!$"

BattleCafe_ChallengeLost_Text_1:
# 635 "data/maps/BattleCafe/scripts.pory"
	.string "Tough course, huh? I've fully restored\n"
	.string "your party.\p"
	.string "Catch your breath, rework\n"
	.string "your strategy, and come at it again\l"
	.string "whenever you like!$"

BattleCafe_ChallengeWon_Text_0:
# 658 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge complete!\p"
	.string "That's {STR_VAR_1} Café Points for you.$"

BattleCafe_ChallengeWon_Text_1:
# 668 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode complete! That took\n"
	.string "some real grit.\p"
	.string "Here's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_2:
# 679 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge complete!\n"
	.string "Full team, full effort!\p"
	.string "That's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_3:
# 689 "data/maps/BattleCafe/scripts.pory"
	.string "Incredible! You have beaten\n"
	.string "the Super Rush mode!\p"
	.string "I can hardly believe it!\p"
	.string "Here's your reward of\n"
	.string "{STR_VAR_1} Café Points.$"

BattleCafe_RewardMenu_Text_0:
# 707 "data/maps/BattleCafe/scripts.pory"
	.string "You have {STR_VAR_1} Café Points.\n"
	.string "Anything you want to exchange for?$"

BattleCafe_RewardMenu_Text_1:
# 711 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Atk - 4$"

BattleCafe_RewardMenu_Text_2:
# 712 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Def - 4$"

BattleCafe_RewardMenu_Text_3:
# 713 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Spe - 2$"

BattleCafe_RewardMenu_Text_4:
# 714 "data/maps/BattleCafe/scripts.pory"
	.string "Shiny Genome - 4$"

BattleCafe_RewardMenu_Text_5:
# 715 "data/maps/BattleCafe/scripts.pory"
	.string "2 Gold Caps - 5$"

BattleCafe_RewardMenu_Text_6:
# 716 "data/maps/BattleCafe/scripts.pory"
	.string "¥250,000 - 5$"

BattleCafe_RewardMenu_Text_7:
# 717 "data/maps/BattleCafe/scripts.pory"
	.string "G. Articuno - 5$"

BattleCafe_RewardMenu_Text_8:
# 718 "data/maps/BattleCafe/scripts.pory"
	.string "G. Zapdos - 5$"

BattleCafe_RewardMenu_Text_9:
# 719 "data/maps/BattleCafe/scripts.pory"
	.string "G. Moltres - 5$"

BattleCafe_RewardMenu_Text_10:
# 720 "data/maps/BattleCafe/scripts.pory"
	.string "Tornadus - 5$"

BattleCafe_RewardMenu_Text_11:
# 721 "data/maps/BattleCafe/scripts.pory"
	.string "Thundurus - 5$"

BattleCafe_RewardMenu_Text_12:
# 722 "data/maps/BattleCafe/scripts.pory"
	.string "Landorus - 5$"

BattleCafe_RewardMenu_Text_13:
# 723 "data/maps/BattleCafe/scripts.pory"
	.string "Enamorus - 5$"

BattleCafe_RewardMenu_Text_14:
# 724 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Koko - 5$"

BattleCafe_RewardMenu_Text_15:
# 725 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Lele - 5$"

BattleCafe_RewardMenu_Text_16:
# 726 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Bulu - 5$"

BattleCafe_RewardMenu_Text_17:
# 727 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Fini - 5$"

BattleCafe_RewardMenu_Text_18:
# 730 "data/maps/BattleCafe/scripts.pory"
	.string "Miraidon - 25$"

BattleCafe_RewardMenu_Text_19:
# 734 "data/maps/BattleCafe/scripts.pory"
	.string "Koraidon - 25$"

BattleCafe_ChooseArticuno_Text_0:
# 764 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Articuno to you.$"

BattleCafe_ChooseZapdos_Text_0:
# 775 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Zapdos to you.$"

BattleCafe_ChooseMoltres_Text_0:
# 786 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Moltres to you.$"

BattleCafe_ChooseTornadus_Text_0:
# 797 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tornadus\n"
	.string "to you.$"

BattleCafe_ChooseThundurus_Text_0:
# 808 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Thundurus\n"
	.string "to you.$"

BattleCafe_ChooseLandorus_Text_0:
# 819 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Landorus\n"
	.string "to you.$"

BattleCafe_ChooseEnamorus_Text_0:
# 830 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Enamorus\n"
	.string "to you.$"

BattleCafe_ChooseTapuKoko_Text_0:
# 841 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Koko\n"
	.string "to you.$"

BattleCafe_ChooseTapuLele_Text_0:
# 852 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Lele\n"
	.string "to you.$"

BattleCafe_ChooseTapuBulu_Text_0:
# 863 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Bulu\n"
	.string "to you.$"

BattleCafe_ChooseTapuFini_Text_0:
# 874 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Fini\n"
	.string "to you.$"

BattleCafe_ConfirmRewardMon_Text_0:
# 888 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmRewardMon_Text_1:
# 925 "data/maps/BattleCafe/scripts.pory"
	.string "You might find this useful.$"

BattleCafe_ConfirmRewardMon_Text_2:
# 929 "data/maps/BattleCafe/scripts.pory"
	.string "A fair trade. I'm sure it'll fit right\n"
	.string "into your team.$"

BattleCafe_ChooseMiraidon_Text_0:
# 936 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Miraidon\n"
	.string "to you.$"

BattleCafe_ChooseKoraidon_Text_0:
# 947 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Koraidon\n"
	.string "to you.$"

BattleCafe_ConfirmParadoxLegend_Text_0:
# 961 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 25 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmParadoxLegend_Text_1:
# 979 "data/maps/BattleCafe/scripts.pory"
	.string "A rare specimen from Paldea. Take good\n"
	.string "care of it!$"

BattleCafe_ChooseShinyGenome_Text_0:
# 988 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for a\n"
	.string "Shiny Genome?$"

BattleCafe_ChooseShinyGenome_Text_1:
# 1002 "data/maps/BattleCafe/scripts.pory"
	.string "A rare find. Use it on whichever\n"
	.string "Pokémon you want to bring out the\l"
	.string "shine.$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
# 1012 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for two\n"
	.string "Gold Bottle Caps?$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
# 1026 "data/maps/BattleCafe/scripts.pory"
	.string "Two Gold Bottle Caps, polished up and\n"
	.string "ready. Here you go!$"

BattleCafe_ChooseMoney_Text_0:
# 1035 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "¥250,000?$"

BattleCafe_ChooseMoney_Text_1:
# 1047 "data/maps/BattleCafe/scripts.pory"
	.string "Use it well, and perhaps spend a little\n"
	.string "on dessert!$"

BattleCafe_ChooseVitaminSetAtk_Text_0:
# 1056 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Protein EX and Calcium EX?$"

BattleCafe_ChooseVitaminSetAtk_Text_1:
# 1071 "data/maps/BattleCafe/scripts.pory"
	.string "Two Protein EX and two Calcium EX,\n"
	.string "power and wisdom!$"

BattleCafe_ChooseVitaminSetDef_Text_0:
# 1080 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Iron EX and Zinc EX?$"

BattleCafe_ChooseVitaminSetDef_Text_1:
# 1095 "data/maps/BattleCafe/scripts.pory"
	.string "Two Iron EX and two Zinc EX,\n"
	.string "time to bulk up!$"

BattleCafe_ChooseVitaminSetSpe_Text_0:
# 1104 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 2 Café Points for\n"
	.string "two Carbos EX?$"

BattleCafe_ChooseVitaminSetSpe_Text_1:
# 1119 "data/maps/BattleCafe/scripts.pory"
	.string "Two Carbos EX, ready to speed up!$"

BattleCafe_NotEnoughPoints_Text_0:
# 1124 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 5 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughLegendPoints_Text_0:
# 1131 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 25 Café Points.\n"
	.string "Complete more of my challenges and\l"
	.string "try again!$"

BattleCafe_NotEnoughFourPoints_Text_0:
# 1138 "data/maps/BattleCafe/scripts.pory"
	.string "The Shiny Genome costs 4 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughVitaminSetPoints_Text_0:
# 1145 "data/maps/BattleCafe/scripts.pory"
	.string "You don't have enough Café Points for\n"
	.string "that vitamin set. \p"
	.string "Complete one of my\n"
	.string "challenges and try again!$"

BattleCafe_NotEnoughBagSpace_Text_0:
# 1154 "data/maps/BattleCafe/scripts.pory"
	.string "Your Bag is too full for that prize.\n"
	.string "Make some room and come back whenever\l"
	.string "you're ready!$"

BattleCafe_Goodbye_Text_0:
# 1161 "data/maps/BattleCafe/scripts.pory"
	.string "Come back hungry for another battle!$"

BattleCafe_TrainerAthena_Text_0:
# 1178 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun? Let's try this\n"
	.string "again tomorrow!$"

BattleCafe_TrainerAthena_Text_1:
# 1183 "data/maps/BattleCafe/scripts.pory"
	.string "Let's see if you can survive this\n"
	.string "stall!$"

BattleCafe_TrainerAthena_Text_2:
# 1185 "data/maps/BattleCafe/scripts.pory"
	.string "Huh?$"

BattleCafe_TrainerAthena_Text_3:
# 1187 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun?$"

BattleCafe_TrainerDoves_Text_0:
# 1198 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when \n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerDoves_Text_1:
# 1204 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let me show you the power of \n"
	.string "Genesect!$"

BattleCafe_TrainerDoves_Text_2:
# 1206 "data/maps/BattleCafe/scripts.pory"
	.string "Banned again from Overused...$"

BattleCafe_TrainerDoves_Text_3:
# 1208 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when\n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerElton_Text_0:
# 1221 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Rematch tomorrow! Be there!$"

BattleCafe_TrainerElton_Text_1:
# 1225 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Let's have a battle with our\n"
	.string "favourite Pokémon!$"

BattleCafe_TrainerElton_Text_2:
# 1227 "data/maps/BattleCafe/scripts.pory"
	.string "You handled every trick I had!$"

BattleCafe_TrainerElton_Text_3:
# 1229 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Even Gengar's impressed, and it\n"
	.string "rarely takes a loss seriously.$"

BattleCafe_TrainerNem_Text_0:
# 1241 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Come back tomorrow.$"

BattleCafe_TrainerNem_Text_1:
# 1245 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Think fast!$"

BattleCafe_TrainerNem_Text_2:
# 1246 "data/maps/BattleCafe/scripts.pory"
	.string "I'll be watching.$"

BattleCafe_TrainerNem_Text_3:
# 1248 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: We can fight again tomorrow.$"

BattleCafe_TrainerBai_Text_0:
# 1259 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: That was a good match!\n"
	.string "Let's fight again tomorrow!$"

BattleCafe_TrainerBai_Text_1:
# 1264 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Let's see what you bring to \n"
	.string "the table!$"

BattleCafe_TrainerBai_Text_2:
# 1266 "data/maps/BattleCafe/scripts.pory"
	.string "Guess I'm cooked this time...$"

BattleCafe_TrainerBai_Text_3:
# 1268 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Good match! Let's try this again \n"
	.string "tomorrow!$"

BattleCafe_TrainerDrac_Text_0:
# 1280 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: You're really tough! Let's fight\n"
	.string "again tomorrow!$"

BattleCafe_TrainerDrac_Text_1:
# 1285 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: Care for a double battle?$"

BattleCafe_TrainerDrac_Text_2:
# 1286 "data/maps/BattleCafe/scripts.pory"
	.string "Soothed.$"

BattleCafe_TrainerSimpli_Text_0:
# 1300 "data/maps/BattleCafe/scripts.pory"
	.string "Tomorrow will surely be better.$"

BattleCafe_TrainerSimpli_Text_1:
# 1304 "data/maps/BattleCafe/scripts.pory"
	.string "Gamble with the rain!$"

BattleCafe_TrainerSimpli_Text_2:
# 1305 "data/maps/BattleCafe/scripts.pory"
	.string "Weathered...$"

BattleCafe_TrainerSimpli_Text_3:
# 1307 "data/maps/BattleCafe/scripts.pory"
	.string "Maybe tomorrow will go better.$"

BattleCafe_TrainerTylarie_Text_0:
# 1318 "data/maps/BattleCafe/scripts.pory"
	.string "Steelix has settled down for\n"
	.string "lunch. We'll be ready tomorrow!$"

BattleCafe_TrainerTylarie_Text_1:
# 1323 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Let me show you how sturdy my\n"
	.string "team is!$"

BattleCafe_TrainerTylarie_Text_2:
# 1325 "data/maps/BattleCafe/scripts.pory"
	.string "Ouch.$"

BattleCafe_TrainerTylarie_Text_3:
# 1327 "data/maps/BattleCafe/scripts.pory"
	.string "Tylarie: Not bad. We can go at it again\n"
	.string "another day.$"

BattleCafe_FreshWaterFountain_Text_0:
# 1336 "data/maps/BattleCafe/scripts.pory"
	.string "It's a small fountain of water.$"

BattleCafe_FreshWaterFountain_Text_1:
# 1339 "data/maps/BattleCafe/scripts.pory"
	.string "You decide to grab some fresh water\n"
	.string "from the fountain.$"

BattleCafe_FreshWaterFountain_Text_2:
# 1343 "data/maps/BattleCafe/scripts.pory"
	.string "Stay hydrated.$"
