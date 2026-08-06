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
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_OptionsMenu_Text_1, BattleCafe_OptionsMenu_Text_2, BattleCafe_OptionsMenu_Text_3, BattleCafe_OptionsMenu_Text_4, BattleCafe_OptionsMenu_Text_5
# 160 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_OptionsMenu_2
# 162 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_OptionsMenu_3
# 163 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_OptionsMenu_4
# 164 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_OptionsMenu_5
# 165 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_OptionsMenu_2:
# 161 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseBattleBgm
	return

BattleCafe_OptionsMenu_3:
# 162 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ViewHighScores
	return

BattleCafe_OptionsMenu_4:
# 163 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseInnates
	return

BattleCafe_OptionsMenu_5:
# 164 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainRules
	return


BattleCafe_ChooseBattleBgm::
# 170 "data/maps/BattleCafe/scripts.pory"
	call BattleFrontier_EventScript_ChooseBattleBgm
# 171 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ViewHighScores::
# 175 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 176 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_ShowRecordsWindow
# 177 "data/maps/BattleCafe/scripts.pory"
	waitbuttonpress
# 178 "data/maps/BattleCafe/scripts.pory"
	special RemoveRecordsWindow
# 179 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_ChooseInnates::
# 183 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_NO_INNATES, BattleCafe_ChooseInnates_2
# 196 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_2, MSGBOX_YESNO
# 200 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleCafe_ChooseInnates_7
BattleCafe_ChooseInnates_1:
# 208 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OptionsMenu
	return

BattleCafe_ChooseInnates_2:
# 184 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_0, MSGBOX_YESNO
# 188 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleCafe_ChooseInnates_5
	goto BattleCafe_ChooseInnates_1

BattleCafe_ChooseInnates_5:
# 189 "data/maps/BattleCafe/scripts.pory"
	clearflag FLAG_BATTLE_CAFE_NO_INNATES
# 190 "data/maps/BattleCafe/scripts.pory"
	playse SE_SWITCH
# 191 "data/maps/BattleCafe/scripts.pory"
	waitse
# 192 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_1
	goto BattleCafe_ChooseInnates_1

BattleCafe_ChooseInnates_7:
# 201 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_NO_INNATES
# 202 "data/maps/BattleCafe/scripts.pory"
	playse SE_SWITCH
# 203 "data/maps/BattleCafe/scripts.pory"
	waitse
# 204 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseInnates_Text_3
	goto BattleCafe_ChooseInnates_1


BattleCafe_ExplainRules::
# 212 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_0
# 222 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_1
# 229 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_2
# 237 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_3
# 244 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_ExplainRules_2
# 245 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_ExplainRules_2
BattleCafe_ExplainRules_1:
# 259 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ExplainRules_2:
# 246 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_4
# 252 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainRules_Text_5
	goto BattleCafe_ExplainRules_1


BattleCafe_AskDailyChallenge::
# 263 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON, BattleCafe_AskDailyChallenge_2
BattleCafe_AskDailyChallenge_1:
# 271 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_1, MSGBOX_YESNO
# 278 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskDailyChallenge_5
BattleCafe_AskDailyChallenge_4:
# 281 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
# 282 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskDailyChallenge_2:
# 264 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskDailyChallenge_Text_0
# 269 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_1

BattleCafe_AskDailyChallenge_5:
# 279 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskDailyChallenge_4


BattleCafe_AskRushMode::
# 286 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_RUSH_WON, BattleCafe_AskRushMode_2
BattleCafe_AskRushMode_1:
# 294 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_1, MSGBOX_YESNO
# 301 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskRushMode_5
BattleCafe_AskRushMode_4:
# 304 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
# 305 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskRushMode_2:
# 287 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskRushMode_Text_0
# 292 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_1

BattleCafe_AskRushMode_5:
# 302 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskRushMode_4


BattleCafe_AskSuperChallenge::
# 309 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON, BattleCafe_AskSuperChallenge_2
BattleCafe_AskSuperChallenge_1:
# 317 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 318 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperChallenge_5
BattleCafe_AskSuperChallenge_4:
# 324 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_2, MSGBOX_YESNO
# 330 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperChallenge_8
BattleCafe_AskSuperChallenge_7:
# 333 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
# 334 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperChallenge_2:
# 310 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_0
# 315 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_1

BattleCafe_AskSuperChallenge_5:
# 319 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperChallenge_Text_1
# 322 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_4

BattleCafe_AskSuperChallenge_8:
# 331 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperChallenge_7


BattleCafe_AskSuperRush::
# 338 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON, BattleCafe_AskSuperRush_2
BattleCafe_AskSuperRush_1:
# 346 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 347 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskSuperRush_5
BattleCafe_AskSuperRush_4:
# 355 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_2, MSGBOX_YESNO
# 362 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskSuperRush_8
BattleCafe_AskSuperRush_7:
# 365 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
# 366 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskSuperRush_2:
# 339 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_0
# 344 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_1

BattleCafe_AskSuperRush_5:
# 348 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskSuperRush_Text_1
# 353 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_4

BattleCafe_AskSuperRush_8:
# 363 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	goto BattleCafe_AskSuperRush_7


BattleCafe_EndlessMenu::
# 370 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessMenu_Text_0
# 371 "data/maps/BattleCafe/scripts.pory"
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, BattleCafe_EndlessMenu_Text_1, BattleCafe_EndlessMenu_Text_2, BattleCafe_EndlessMenu_Text_3, BattleCafe_OptionsMenu_Text_5
# 376 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 377 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_EndlessMenu_2
# 378 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_EndlessMenu_3
# 379 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_EndlessMenu_4
# 380 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_EndlessMenu_2:
# 377 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessChallenge
	return

BattleCafe_EndlessMenu_3:
# 378 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_AskEndlessRush
	return

BattleCafe_EndlessMenu_4:
# 379 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ExplainEndlessRules
	return


BattleCafe_ExplainEndlessRules::
# 385 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_0
# 392 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_1
# 399 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ExplainEndlessRules_Text_2
# 402 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	return


BattleCafe_AskEndlessChallenge::
# 406 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_CHALLENGE_UNLOCKED, BattleCafe_AskEndlessChallenge_2
BattleCafe_AskEndlessChallenge_1:
# 411 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 412 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessChallenge_5
BattleCafe_AskEndlessChallenge_4:
# 420 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_2, MSGBOX_YESNO
# 427 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessChallenge_8
BattleCafe_AskEndlessChallenge_7:
# 430 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
# 431 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessChallenge_2:
# 407 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_0
# 409 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_1

BattleCafe_AskEndlessChallenge_5:
# 413 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 418 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_4

BattleCafe_AskEndlessChallenge_8:
# 428 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessChallenge_7


BattleCafe_AskEndlessRush::
# 435 "data/maps/BattleCafe/scripts.pory"
	goto_if_unset FLAG_BATTLE_CAFE_ENDLESS_RUSH_UNLOCKED, BattleCafe_AskEndlessRush_2
BattleCafe_AskEndlessRush_1:
# 440 "data/maps/BattleCafe/scripts.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 441 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt BattleCafe_AskEndlessRush_5
BattleCafe_AskEndlessRush_4:
# 449 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_1, MSGBOX_YESNO
# 456 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_AskEndlessRush_8
BattleCafe_AskEndlessRush_7:
# 459 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
# 460 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_BeginChallenge
	return

BattleCafe_AskEndlessRush_2:
# 436 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessRush_Text_0
# 438 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_1

BattleCafe_AskEndlessRush_5:
# 442 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_AskEndlessChallenge_Text_1
# 447 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_4

BattleCafe_AskEndlessRush_8:
# 457 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessMenu
	goto BattleCafe_AskEndlessRush_7


BattleCafe_BeginChallenge::
# 464 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 465 "data/maps/BattleCafe/scripts.pory"
	hidefollower
# 466 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 467 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_InitChallenge
# 468 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 13, DIR_EAST
# 469 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 470 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_9, 0
# 471 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 472 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_BeginChallenge_2
# 473 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_BeginChallenge_2
# 477 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_1
BattleCafe_BeginChallenge_1:
# 480 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 481 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_BeginChallenge_2:
# 474 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_BeginChallenge_Text_0
	goto BattleCafe_BeginChallenge_1


BattleCafe_ChallengeNextRound::
# 485 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_RunRound
# 486 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChallengeNextRound_2
BattleCafe_ChallengeNextRound_1:
# 490 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AdvanceWinCount
# 491 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_5
BattleCafe_ChallengeNextRound_4:
# 512 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_8
BattleCafe_ChallengeNextRound_7:
# 544 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_9, 3
	goto_if_ge BattleCafe_ChallengeNextRound_14
BattleCafe_ChallengeNextRound_13:
# 548 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeNextRound_21
# 554 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeNextRound_27
# 560 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_RUSH
	goto_if_eq BattleCafe_ChallengeNextRound_30
# 564 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_6
BattleCafe_ChallengeNextRound_20:
# 569 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 570 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	return

BattleCafe_ChallengeNextRound_2:
# 487 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeLost
	goto BattleCafe_ChallengeNextRound_1

BattleCafe_ChallengeNextRound_5:
# 492 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 1
# 493 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 494 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 495 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 496 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 497 "data/maps/BattleCafe/scripts.pory"
	waitse
# 498 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 499 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 500 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_0, MSGBOX_YESNO
# 505 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_11
BattleCafe_ChallengeNextRound_10:
# 508 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 509 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_4

BattleCafe_ChallengeNextRound_8:
# 513 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 2
# 514 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 515 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 516 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_TEMP_C, 1
# 517 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 518 "data/maps/BattleCafe/scripts.pory"
	waitse
# 519 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 520 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_B
# 521 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, 3
	goto_if_ge BattleCafe_ChallengeNextRound_17
# 531 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_2, MSGBOX_YESNO
BattleCafe_ChallengeNextRound_16:
# 537 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChallengeNextRound_25
BattleCafe_ChallengeNextRound_24:
# 540 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 541 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeNextRound
	goto BattleCafe_ChallengeNextRound_7

BattleCafe_ChallengeNextRound_11:
# 506 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_10

BattleCafe_ChallengeNextRound_14:
# 545 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChallengeWon
	goto BattleCafe_ChallengeNextRound_13

BattleCafe_ChallengeNextRound_17:
# 522 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_C, 0
# 523 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 524 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 525 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_1, MSGBOX_YESNO
	goto BattleCafe_ChallengeNextRound_16

BattleCafe_ChallengeNextRound_21:
# 549 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 550 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 551 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_3
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_25:
# 538 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_EndlessRetired
	goto BattleCafe_ChallengeNextRound_24

BattleCafe_ChallengeNextRound_27:
# 555 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 556 "data/maps/BattleCafe/scripts.pory"
	playse SE_USE_ITEM
# 557 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_4
	goto BattleCafe_ChallengeNextRound_20

BattleCafe_ChallengeNextRound_30:
# 561 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeNextRound_Text_5
	goto BattleCafe_ChallengeNextRound_20


BattleCafe_EndlessRetired::
# 574 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 575 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 576 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 577 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 578 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 579 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 580 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 581 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_EndlessRetired_Text_0
# 585 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return


BattleCafe_RunRound::
# 589 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_9
# 590 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_SelectOpponent
# 591 "data/maps/BattleCafe/scripts.pory"
	setobjectxy LOCALID_BATTLE_CAFE_OPPONENT, 14, 17
# 592 "data/maps/BattleCafe/scripts.pory"
	addobject LOCALID_BATTLE_CAFE_OPPONENT
# 593 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 10, 13, DIR_WEST
# 594 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 595 "data/maps/BattleCafe/scripts.pory"
	tower_getopponentintro FRONTIER_BEFORE_TEXT
# 596 "data/maps/BattleCafe/scripts.pory"
	msgbox gStringVar4
# 597 "data/maps/BattleCafe/scripts.pory"
	closemessage
# 598 "data/maps/BattleCafe/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_CAFE
# 599 "data/maps/BattleCafe/scripts.pory"
	waitstate
# 600 "data/maps/BattleCafe/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 601 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 603 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_BATTLE_CAFE_OPPONENT, 14, 17, DIR_EAST
# 604 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 605 "data/maps/BattleCafe/scripts.pory"
	removeobject LOCALID_BATTLE_CAFE_OPPONENT
# 607 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_A, B_OUTCOME_WON
	goto_if_eq BattleCafe_RunRound_2
# 610 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, FALSE
BattleCafe_RunRound_1:
	return

BattleCafe_RunRound_2:
# 608 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_RESULT, TRUE
	goto BattleCafe_RunRound_1


BattleCafe_ChallengeLost::
# 616 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 617 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 618 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 619 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 620 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 621 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_CHALLENGE
	goto_if_eq BattleCafe_ChallengeLost_2
# 622 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_ENDLESS_RUSH
	goto_if_eq BattleCafe_ChallengeLost_2
# 632 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_1
BattleCafe_ChallengeLost_1:
# 639 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeLost_2:
# 623 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_9
# 624 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeLost_Text_0
	goto BattleCafe_ChallengeLost_1


BattleCafe_ChallengeWon::
# 643 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_EndChallenge
# 644 "data/maps/BattleCafe/scripts.pory"
	special HealPlayerParty
# 645 "data/maps/BattleCafe/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 24, DIR_NORTH
# 646 "data/maps/BattleCafe/scripts.pory"
	waitmovement 0
# 647 "data/maps/BattleCafe/scripts.pory"
	turnobject LOCALID_CAFE_OWNER, DIR_SOUTH
# 649 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_DAILY
	goto_if_eq BattleCafe_ChallengeWon_2
# 659 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_RUSH
	goto_if_eq BattleCafe_ChallengeWon_5
# 670 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_8, BATTLE_CAFE_MODE_SUPER_CHALLENGE
	goto_if_eq BattleCafe_ChallengeWon_8
# 681 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_RUSH_WON
# 682 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 10
# 683 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 684 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 685 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 686 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_3
BattleCafe_ChallengeWon_1:
# 696 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_UnlockClearAchievement
# 697 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 698 "data/maps/BattleCafe/scripts.pory"
	waitse
# 699 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_ChallengeWon_2:
# 650 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_CHALLENGE_WON
# 651 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 3
# 652 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 653 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 654 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 655 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_0
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_5:
# 660 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_RUSH_WON
# 661 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 662 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 663 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 664 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 665 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_1
	goto BattleCafe_ChallengeWon_1

BattleCafe_ChallengeWon_8:
# 671 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_SUPER_CHALLENGE_WON
# 672 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, 5
# 673 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_AwardPoints
# 674 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 675 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_B
# 676 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChallengeWon_Text_2
	goto BattleCafe_ChallengeWon_1


BattleCafe_RewardMenu::
# 703 "data/maps/BattleCafe/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_BATTLE_CAFE_POINTS
# 704 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_RewardMenu_Text_0
# 706 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_GetParadoxRewardEligibility
# 707 "data/maps/BattleCafe/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 708 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_1, 0
# 709 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_2, 1
# 710 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_3, 2
# 711 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_4, 3
# 712 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_5, 4
# 713 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_6, 5
# 714 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_7, 6
# 715 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_8, 16
# 716 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_9, 17
# 717 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_10, 18
# 718 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_11, 19
# 719 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_12, 7
# 720 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_13, 8
# 721 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_14, 9
# 722 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_15, 10
# 723 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_16, 11
# 724 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_17, 12
# 725 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON
	goto_if_eq BattleCafe_RewardMenu_2
# 726 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_2
BattleCafe_RewardMenu_1:
# 729 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
# 730 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_C, BATTLE_CAFE_PARADOX_REWARD_MIRAIDON + BATTLE_CAFE_PARADOX_REWARD_KORAIDON
	goto_if_eq BattleCafe_RewardMenu_7
BattleCafe_RewardMenu_6:
# 733 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_OptionsMenu_Text_5, 15
# 734 "data/maps/BattleCafe/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 735 "data/maps/BattleCafe/scripts.pory"
	switch VAR_RESULT
# 736 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_RewardMenu_12
# 737 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_RewardMenu_13
# 738 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_RewardMenu_14
# 739 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_RewardMenu_15
# 740 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_RewardMenu_16
# 741 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_RewardMenu_17
# 742 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_RewardMenu_18
# 743 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_RewardMenu_19
# 744 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_RewardMenu_20
# 745 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_RewardMenu_21
# 746 "data/maps/BattleCafe/scripts.pory"
	case 10, BattleCafe_RewardMenu_22
# 747 "data/maps/BattleCafe/scripts.pory"
	case 11, BattleCafe_RewardMenu_23
# 748 "data/maps/BattleCafe/scripts.pory"
	case 12, BattleCafe_RewardMenu_24
# 749 "data/maps/BattleCafe/scripts.pory"
	case 13, BattleCafe_RewardMenu_25
# 750 "data/maps/BattleCafe/scripts.pory"
	case 14, BattleCafe_RewardMenu_26
# 751 "data/maps/BattleCafe/scripts.pory"
	case 16, BattleCafe_RewardMenu_27
# 752 "data/maps/BattleCafe/scripts.pory"
	case 17, BattleCafe_RewardMenu_28
# 753 "data/maps/BattleCafe/scripts.pory"
	case 18, BattleCafe_RewardMenu_29
# 754 "data/maps/BattleCafe/scripts.pory"
	case 19, BattleCafe_RewardMenu_30
# 755 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_OwnerMenu
	return

BattleCafe_RewardMenu_2:
# 727 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_18, 13
	goto BattleCafe_RewardMenu_1

BattleCafe_RewardMenu_7:
# 731 "data/maps/BattleCafe/scripts.pory"
	dynmultipush BattleCafe_RewardMenu_Text_19, 14
	goto BattleCafe_RewardMenu_6

BattleCafe_RewardMenu_12:
# 736 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseArticuno
	return

BattleCafe_RewardMenu_13:
# 737 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseZapdos
	return

BattleCafe_RewardMenu_14:
# 738 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoltres
	return

BattleCafe_RewardMenu_15:
# 739 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTornadus
	return

BattleCafe_RewardMenu_16:
# 740 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseThundurus
	return

BattleCafe_RewardMenu_17:
# 741 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseLandorus
	return

BattleCafe_RewardMenu_18:
# 742 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseEnamorus
	return

BattleCafe_RewardMenu_19:
# 743 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseShinyGenome
	return

BattleCafe_RewardMenu_20:
# 744 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseGoldBottleCaps
	return

BattleCafe_RewardMenu_21:
# 745 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMoney
	return

BattleCafe_RewardMenu_22:
# 746 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetAtk
	return

BattleCafe_RewardMenu_23:
# 747 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetDef
	return

BattleCafe_RewardMenu_24:
# 748 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseVitaminSetSpe
	return

BattleCafe_RewardMenu_25:
# 749 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseMiraidon
	return

BattleCafe_RewardMenu_26:
# 750 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseKoraidon
	return

BattleCafe_RewardMenu_27:
# 751 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuKoko
	return

BattleCafe_RewardMenu_28:
# 752 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuLele
	return

BattleCafe_RewardMenu_29:
# 753 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuBulu
	return

BattleCafe_RewardMenu_30:
# 754 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ChooseTapuFini
	return


BattleCafe_ChooseArticuno::
# 760 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED, BattleCafe_ChooseArticuno_2
BattleCafe_ChooseArticuno_1:
# 765 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_GALAR
# 766 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 767 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseArticuno_2:
# 761 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseArticuno_Text_0
# 763 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseArticuno_1


BattleCafe_ChooseZapdos::
# 771 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED, BattleCafe_ChooseZapdos_2
BattleCafe_ChooseZapdos_1:
# 776 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_GALAR
# 777 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 778 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseZapdos_2:
# 772 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseZapdos_Text_0
# 774 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseZapdos_1


BattleCafe_ChooseMoltres::
# 782 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MOLTRES_RECEIVED, BattleCafe_ChooseMoltres_2
BattleCafe_ChooseMoltres_1:
# 787 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_GALAR
# 788 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 2
# 789 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseMoltres_2:
# 783 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoltres_Text_0
# 785 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoltres_1


BattleCafe_ChooseTornadus::
# 793 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TORNADUS_RECEIVED, BattleCafe_ChooseTornadus_2
BattleCafe_ChooseTornadus_1:
# 798 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS
# 799 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 3
# 800 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTornadus_2:
# 794 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTornadus_Text_0
# 796 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTornadus_1


BattleCafe_ChooseThundurus::
# 804 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED, BattleCafe_ChooseThundurus_2
BattleCafe_ChooseThundurus_1:
# 809 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS
# 810 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 4
# 811 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseThundurus_2:
# 805 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseThundurus_Text_0
# 807 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseThundurus_1


BattleCafe_ChooseLandorus::
# 815 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_LANDORUS_RECEIVED, BattleCafe_ChooseLandorus_2
BattleCafe_ChooseLandorus_1:
# 820 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS
# 821 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 5
# 822 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseLandorus_2:
# 816 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseLandorus_Text_0
# 818 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseLandorus_1


BattleCafe_ChooseEnamorus::
# 826 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED, BattleCafe_ChooseEnamorus_2
BattleCafe_ChooseEnamorus_1:
# 831 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENAMORUS
# 832 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 6
# 833 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseEnamorus_2:
# 827 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseEnamorus_Text_0
# 829 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseEnamorus_1


BattleCafe_ChooseTapuKoko::
# 837 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED, BattleCafe_ChooseTapuKoko_2
BattleCafe_ChooseTapuKoko_1:
# 842 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO
# 843 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 7
# 844 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuKoko_2:
# 838 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuKoko_Text_0
# 840 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuKoko_1


BattleCafe_ChooseTapuLele::
# 848 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED, BattleCafe_ChooseTapuLele_2
BattleCafe_ChooseTapuLele_1:
# 853 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE
# 854 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 8
# 855 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuLele_2:
# 849 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuLele_Text_0
# 851 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuLele_1


BattleCafe_ChooseTapuBulu::
# 859 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED, BattleCafe_ChooseTapuBulu_2
BattleCafe_ChooseTapuBulu_1:
# 864 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU
# 865 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 9
# 866 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuBulu_2:
# 860 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuBulu_Text_0
# 862 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuBulu_1


BattleCafe_ChooseTapuFini::
# 870 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED, BattleCafe_ChooseTapuFini_2
BattleCafe_ChooseTapuFini_1:
# 875 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI
# 876 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 10
# 877 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmRewardMon
	return

BattleCafe_ChooseTapuFini_2:
# 871 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseTapuFini_Text_0
# 873 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseTapuFini_1


BattleCafe_ConfirmRewardMon::
# 881 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ConfirmRewardMon_2
BattleCafe_ConfirmRewardMon_1:
# 884 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 885 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_0, MSGBOX_YESNO
# 887 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmRewardMon_5
BattleCafe_ConfirmRewardMon_4:
# 891 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_10
BattleCafe_ConfirmRewardMon_7:
# 898 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 899 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmRewardMon_15
BattleCafe_ConfirmRewardMon_14:
# 902 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 903 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 904 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 905 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 906 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 907 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmRewardMon_21
# 908 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmRewardMon_22
# 909 "data/maps/BattleCafe/scripts.pory"
	case 2, BattleCafe_ConfirmRewardMon_23
# 910 "data/maps/BattleCafe/scripts.pory"
	case 3, BattleCafe_ConfirmRewardMon_24
# 911 "data/maps/BattleCafe/scripts.pory"
	case 4, BattleCafe_ConfirmRewardMon_25
# 912 "data/maps/BattleCafe/scripts.pory"
	case 5, BattleCafe_ConfirmRewardMon_26
# 913 "data/maps/BattleCafe/scripts.pory"
	case 6, BattleCafe_ConfirmRewardMon_27
# 914 "data/maps/BattleCafe/scripts.pory"
	case 7, BattleCafe_ConfirmRewardMon_28
# 915 "data/maps/BattleCafe/scripts.pory"
	case 8, BattleCafe_ConfirmRewardMon_29
# 916 "data/maps/BattleCafe/scripts.pory"
	case 9, BattleCafe_ConfirmRewardMon_30
# 917 "data/maps/BattleCafe/scripts.pory"
	case 10, BattleCafe_ConfirmRewardMon_31
BattleCafe_ConfirmRewardMon_19:
# 919 "data/maps/BattleCafe/scripts.pory"
	special Achievement_CheckAll
# 920 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 3
	goto_if_ge BattleCafe_ConfirmRewardMon_34
BattleCafe_ConfirmRewardMon_32:
# 926 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_2
# 928 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmRewardMon_2:
# 882 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ConfirmRewardMon_1

BattleCafe_ConfirmRewardMon_5:
# 888 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmRewardMon_4

BattleCafe_ConfirmRewardMon_8:
# 892 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_REVEAL_GLASS, 1
# 893 "data/maps/BattleCafe/scripts.pory"
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
# 891 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_9
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_15:
# 900 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmRewardMon_14

BattleCafe_ConfirmRewardMon_17:
# 894 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ConfirmRewardMon_7

BattleCafe_ConfirmRewardMon_21:
# 907 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_22:
# 908 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_23:
# 909 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MOLTRES_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_24:
# 910 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TORNADUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_25:
# 911 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_26:
# 912 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_LANDORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_27:
# 913 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_28:
# 914 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_29:
# 915 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_30:
# 916 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_31:
# 917 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED
	goto BattleCafe_ConfirmRewardMon_19

BattleCafe_ConfirmRewardMon_33:
	checkitem ITEM_REVEAL_GLASS
# 0 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ConfirmRewardMon_37
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_34:
# 920 "data/maps/BattleCafe/scripts.pory"
	compare VAR_TEMP_B, 6
	goto_if_le BattleCafe_ConfirmRewardMon_33
	goto BattleCafe_ConfirmRewardMon_32

BattleCafe_ConfirmRewardMon_37:
# 922 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmRewardMon_Text_1
# 923 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
	goto BattleCafe_ConfirmRewardMon_32


BattleCafe_ChooseMiraidon::
# 932 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED, BattleCafe_ChooseMiraidon_2
BattleCafe_ChooseMiraidon_1:
# 937 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MIRAIDON
# 938 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 0
# 939 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseMiraidon_2:
# 933 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMiraidon_Text_0
# 935 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMiraidon_1


BattleCafe_ChooseKoraidon::
# 943 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_BATTLE_CAFE_KORAIDON_RECEIVED, BattleCafe_ChooseKoraidon_2
BattleCafe_ChooseKoraidon_1:
# 948 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KORAIDON
# 949 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_TEMP_B, 1
# 950 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_ConfirmParadoxLegend
	return

BattleCafe_ChooseKoraidon_2:
# 944 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseKoraidon_Text_0
# 946 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseKoraidon_1


BattleCafe_ConfirmParadoxLegend::
# 954 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 25
	goto_if_lt BattleCafe_ConfirmParadoxLegend_2
BattleCafe_ConfirmParadoxLegend_1:
# 957 "data/maps/BattleCafe/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 958 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmParadoxLegend_Text_0, MSGBOX_YESNO
# 960 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ConfirmParadoxLegend_5
BattleCafe_ConfirmParadoxLegend_4:
# 963 "data/maps/BattleCafe/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 70
# 964 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq BattleCafe_ConfirmParadoxLegend_8
BattleCafe_ConfirmParadoxLegend_7:
# 967 "data/maps/BattleCafe/scripts.pory"
	showgivemonpic 10, 3
# 968 "data/maps/BattleCafe/scripts.pory"
	call Common_EventScript_GiftMon
# 969 "data/maps/BattleCafe/scripts.pory"
	hidemonpic
# 970 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 25
# 971 "data/maps/BattleCafe/scripts.pory"
	switch VAR_TEMP_B
# 972 "data/maps/BattleCafe/scripts.pory"
	case 0, BattleCafe_ConfirmParadoxLegend_12
# 973 "data/maps/BattleCafe/scripts.pory"
	case 1, BattleCafe_ConfirmParadoxLegend_13
BattleCafe_ConfirmParadoxLegend_10:
# 975 "data/maps/BattleCafe/scripts.pory"
	special Achievement_CheckAll
# 976 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ConfirmParadoxLegend_Text_1
# 978 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ConfirmParadoxLegend_2:
# 955 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughLegendPoints
	goto BattleCafe_ConfirmParadoxLegend_1

BattleCafe_ConfirmParadoxLegend_5:
# 961 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ConfirmParadoxLegend_4

BattleCafe_ConfirmParadoxLegend_8:
# 965 "data/maps/BattleCafe/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
	goto BattleCafe_ConfirmParadoxLegend_7

BattleCafe_ConfirmParadoxLegend_12:
# 972 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10

BattleCafe_ConfirmParadoxLegend_13:
# 973 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_BATTLE_CAFE_KORAIDON_RECEIVED
	goto BattleCafe_ConfirmParadoxLegend_10


BattleCafe_ChooseShinyGenome::
# 982 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseShinyGenome_2
BattleCafe_ChooseShinyGenome_1:
# 985 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_0, MSGBOX_YESNO
# 987 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseShinyGenome_5
BattleCafe_ChooseShinyGenome_4:
# 990 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_SHIN_GENOME, 1
# 991 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseShinyGenome_8
BattleCafe_ChooseShinyGenome_7:
# 994 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 995 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseShinyGenome_11
BattleCafe_ChooseShinyGenome_10:
# 998 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 4
# 999 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseShinyGenome_Text_1
# 1002 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseShinyGenome_2:
# 983 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughFourPoints
	goto BattleCafe_ChooseShinyGenome_1

BattleCafe_ChooseShinyGenome_5:
# 988 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_4

BattleCafe_ChooseShinyGenome_8:
# 992 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseShinyGenome_7

BattleCafe_ChooseShinyGenome_11:
# 996 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseShinyGenome_10


BattleCafe_ChooseGoldBottleCaps::
# 1006 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseGoldBottleCaps_2
BattleCafe_ChooseGoldBottleCaps_1:
# 1009 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_0, MSGBOX_YESNO
# 1011 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_5
BattleCafe_ChooseGoldBottleCaps_4:
# 1014 "data/maps/BattleCafe/scripts.pory"
	checkitemspace ITEM_GOLD_BOTTLE_CAP, 2
# 1015 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleCafe_ChooseGoldBottleCaps_8
BattleCafe_ChooseGoldBottleCaps_7:
# 1018 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_GOLD_BOTTLE_CAP, 2
# 1019 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne BattleCafe_ChooseGoldBottleCaps_11
BattleCafe_ChooseGoldBottleCaps_10:
# 1022 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 1023 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseGoldBottleCaps_Text_1
# 1025 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseGoldBottleCaps_2:
# 1007 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseGoldBottleCaps_1

BattleCafe_ChooseGoldBottleCaps_5:
# 1012 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_4

BattleCafe_ChooseGoldBottleCaps_8:
# 1016 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseGoldBottleCaps_7

BattleCafe_ChooseGoldBottleCaps_11:
# 1020 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseGoldBottleCaps_10


BattleCafe_ChooseMoney::
# 1029 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 5
	goto_if_lt BattleCafe_ChooseMoney_2
BattleCafe_ChooseMoney_1:
# 1032 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_0, MSGBOX_YESNO
# 1034 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseMoney_5
BattleCafe_ChooseMoney_4:
# 1037 "data/maps/BattleCafe/scripts.pory"
	subvar VAR_BATTLE_CAFE_POINTS, 5
# 1038 "data/maps/BattleCafe/scripts.pory"
	showmoneybox 0, 0
# 1039 "data/maps/BattleCafe/scripts.pory"
	addmoney 250000
# 1040 "data/maps/BattleCafe/scripts.pory"
	updatemoneybox 0
# 1041 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1042 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1043 "data/maps/BattleCafe/scripts.pory"
	hidemoneybox
# 1044 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseMoney_Text_1
# 1046 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseMoney_2:
# 1030 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughPoints
	goto BattleCafe_ChooseMoney_1

BattleCafe_ChooseMoney_5:
# 1035 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseMoney_4


BattleCafe_ChooseVitaminSetAtk::
# 1050 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetAtk_2
BattleCafe_ChooseVitaminSetAtk_1:
# 1053 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_0, MSGBOX_YESNO
# 1055 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_5
BattleCafe_ChooseVitaminSetAtk_4:
# 1058 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_ATK
# 1059 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1060 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetAtk_8
BattleCafe_ChooseVitaminSetAtk_7:
# 1063 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetAtk_11
BattleCafe_ChooseVitaminSetAtk_10:
# 1066 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1067 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1068 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetAtk_Text_1
# 1070 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetAtk_2:
# 1051 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_1

BattleCafe_ChooseVitaminSetAtk_5:
# 1056 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetAtk_4

BattleCafe_ChooseVitaminSetAtk_8:
# 1061 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetAtk_7

BattleCafe_ChooseVitaminSetAtk_11:
# 1064 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetAtk_10


BattleCafe_ChooseVitaminSetDef::
# 1074 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 4
	goto_if_lt BattleCafe_ChooseVitaminSetDef_2
BattleCafe_ChooseVitaminSetDef_1:
# 1077 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_0, MSGBOX_YESNO
# 1079 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetDef_5
BattleCafe_ChooseVitaminSetDef_4:
# 1082 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_DEF
# 1083 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1084 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetDef_8
BattleCafe_ChooseVitaminSetDef_7:
# 1087 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetDef_11
BattleCafe_ChooseVitaminSetDef_10:
# 1090 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1091 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1092 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetDef_Text_1
# 1094 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetDef_2:
# 1075 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_1

BattleCafe_ChooseVitaminSetDef_5:
# 1080 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetDef_4

BattleCafe_ChooseVitaminSetDef_8:
# 1085 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetDef_7

BattleCafe_ChooseVitaminSetDef_11:
# 1088 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetDef_10


BattleCafe_ChooseVitaminSetSpe::
# 1098 "data/maps/BattleCafe/scripts.pory"
	compare VAR_BATTLE_CAFE_POINTS, 2
	goto_if_lt BattleCafe_ChooseVitaminSetSpe_2
BattleCafe_ChooseVitaminSetSpe_1:
# 1101 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_0, MSGBOX_YESNO
# 1103 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_5
BattleCafe_ChooseVitaminSetSpe_4:
# 1106 "data/maps/BattleCafe/scripts.pory"
	setvar VAR_0x8004, BATTLE_CAFE_VITAMIN_SET_SPE
# 1107 "data/maps/BattleCafe/scripts.pory"
	special BattleCafe_TryPurchaseVitaminSet
# 1108 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_NOT_ENOUGH_POINTS
	goto_if_eq BattleCafe_ChooseVitaminSetSpe_8
BattleCafe_ChooseVitaminSetSpe_7:
# 1111 "data/maps/BattleCafe/scripts.pory"
	compare VAR_RESULT, BATTLE_CAFE_VITAMIN_PURCHASE_SUCCESS
	goto_if_ne BattleCafe_ChooseVitaminSetSpe_11
BattleCafe_ChooseVitaminSetSpe_10:
# 1114 "data/maps/BattleCafe/scripts.pory"
	playse SE_SHOP
# 1115 "data/maps/BattleCafe/scripts.pory"
	waitse
# 1116 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_ChooseVitaminSetSpe_Text_1
# 1117 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return

BattleCafe_ChooseVitaminSetSpe_2:
# 1099 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_1

BattleCafe_ChooseVitaminSetSpe_5:
# 1104 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	goto BattleCafe_ChooseVitaminSetSpe_4

BattleCafe_ChooseVitaminSetSpe_8:
# 1109 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughVitaminSetPoints
	goto BattleCafe_ChooseVitaminSetSpe_7

BattleCafe_ChooseVitaminSetSpe_11:
# 1112 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_NotEnoughBagSpace
	goto BattleCafe_ChooseVitaminSetSpe_10


BattleCafe_NotEnoughPoints::
# 1121 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughPoints_Text_0
# 1124 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughLegendPoints::
# 1128 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughLegendPoints_Text_0
# 1131 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughFourPoints::
# 1135 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughFourPoints_Text_0
# 1138 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughVitaminSetPoints::
# 1142 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughVitaminSetPoints_Text_0
# 1147 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_NotEnoughBagSpace::
# 1151 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_NotEnoughBagSpace_Text_0
# 1154 "data/maps/BattleCafe/scripts.pory"
	goto BattleCafe_RewardMenu
	return


BattleCafe_Goodbye::
# 1158 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_Goodbye_Text_0
# 1159 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_GiveDailyCandyReward::
# 1164 "data/maps/BattleCafe/scripts.pory"
	random 3
# 1165 "data/maps/BattleCafe/scripts.pory"
	addvar VAR_RESULT, 1
# 1166 "data/maps/BattleCafe/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, VAR_RESULT
	return


BattleCafe_TrainerAthena::
# 1171 "data/maps/BattleCafe/scripts.pory"
	lock
# 1172 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1174 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ATHENA, BattleCafe_TrainerAthena_2
# 1180 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_1
# 1182 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ATHENA, BattleCafe_TrainerAthena_Text_2
# 1183 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ATHENA
# 1184 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_3
# 1185 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1186 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerAthena_2:
# 1175 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerAthena_Text_0
# 1177 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDoves::
# 1191 "data/maps/BattleCafe/scripts.pory"
	lock
# 1192 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1194 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DOVES, BattleCafe_TrainerDoves_2
# 1201 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_1
# 1203 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DOVES, BattleCafe_TrainerDoves_Text_2
# 1204 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DOVES
# 1205 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_3
# 1208 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1209 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDoves_2:
# 1195 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDoves_Text_0
# 1198 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerElton::
# 1214 "data/maps/BattleCafe/scripts.pory"
	lock
# 1215 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1217 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_ELTON, BattleCafe_TrainerElton_2
# 1222 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_1
# 1224 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_ELTON, BattleCafe_TrainerElton_Text_2
# 1225 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_ELTON
# 1226 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_3
# 1228 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1229 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerElton_2:
# 1218 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerElton_Text_0
# 1219 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerNem::
# 1234 "data/maps/BattleCafe/scripts.pory"
	lock
# 1235 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1237 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_NEM, BattleCafe_TrainerNem_2
# 1242 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_1
# 1243 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_NEM, BattleCafe_TrainerNem_Text_2
# 1244 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_NEM
# 1245 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_3
# 1246 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1247 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerNem_2:
# 1238 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerNem_Text_0
# 1239 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerBai::
# 1252 "data/maps/BattleCafe/scripts.pory"
	lock
# 1253 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1255 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_BAI, BattleCafe_TrainerBai_2
# 1261 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_1
# 1263 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_BAI, BattleCafe_TrainerBai_Text_2
# 1264 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_BAI
# 1265 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_3
# 1267 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1268 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerBai_2:
# 1256 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerBai_Text_0
# 1258 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerDrac::
# 1273 "data/maps/BattleCafe/scripts.pory"
	lock
# 1274 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1276 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_DRAC, BattleCafe_TrainerDrac_2
# 1282 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_1
# 1283 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_DRAC, BattleCafe_TrainerDrac_Text_2
# 1284 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_DRAC
# 1285 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1287 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1288 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerDrac_2:
# 1277 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerDrac_Text_0
# 1279 "data/maps/BattleCafe/scripts.pory"
	release
	end


BattleCafe_TrainerMarina::
# 1293 "data/maps/BattleCafe/scripts.pory"
	lock
# 1294 "data/maps/BattleCafe/scripts.pory"
	faceplayer
# 1296 "data/maps/BattleCafe/scripts.pory"
	goto_if_set FLAG_DAILY_BATTLE_CAFE_JUNA, BattleCafe_TrainerMarina_2
# 1302 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_1
# 1304 "data/maps/BattleCafe/scripts.pory"
	trainerbattle_no_intro TRAINER_CAFE_JUNA, BattleCafe_TrainerMarina_Text_2
# 1305 "data/maps/BattleCafe/scripts.pory"
	setflag FLAG_DAILY_BATTLE_CAFE_JUNA
# 1306 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_3
# 1308 "data/maps/BattleCafe/scripts.pory"
	call BattleCafe_GiveDailyCandyReward
# 1309 "data/maps/BattleCafe/scripts.pory"
	release
	end

BattleCafe_TrainerMarina_2:
# 1297 "data/maps/BattleCafe/scripts.pory"
	msgbox BattleCafe_TrainerMarina_Text_0
# 1299 "data/maps/BattleCafe/scripts.pory"
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
	.string "Innates$"

BattleCafe_OptionsMenu_Text_4:
# 158 "data/maps/BattleCafe/scripts.pory"
	.string "Café Rules$"

BattleCafe_OptionsMenu_Text_5:
# 159 "data/maps/BattleCafe/scripts.pory"
	.string "Back$"

BattleCafe_ChooseInnates_Text_0:
# 184 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are disabled for both sides\n"
	.string "in every Café challenge.\p"
	.string "Enable innates?$"

BattleCafe_ChooseInnates_Text_1:
# 192 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are now enabled for\n"
	.string "all Café challenges.$"

BattleCafe_ChooseInnates_Text_2:
# 196 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are enabled for both sides\n"
	.string "in every Café challenge.\p"
	.string "Disable innates?$"

BattleCafe_ChooseInnates_Text_3:
# 204 "data/maps/BattleCafe/scripts.pory"
	.string "Innates are now disabled for\n"
	.string "all Café challenges.$"

BattleCafe_ExplainRules_Text_0:
# 212 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors will answer each\n"
	.string "challenge, one after another.\p"
	.string "In the Daily Challenge, they bring\n"
	.string "dependable teams of four.\p"
	.string "I'll tend to your Pokémon after each\n"
	.string "battle.\p"
	.string "Win all three for 3 Café Points.$"

BattleCafe_ExplainRules_Text_1:
# 222 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode draws seasoned battlers with\n"
	.string "teams of four.\p"
	.string "Anything goes, and I can't heal\n"
	.string "your Pokémon between the matches.\p"
	.string "Win all three for 5 points.$"

BattleCafe_ExplainRules_Text_2:
# 229 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge and Super Rush pit\n"
	.string "you against full teams of six Pokémon.\p"
	.string "Anyone might show up so prepare to\n"
	.string "face literally anything.\p"
	.string "Same rules apply here for healing\n"
	.string "between the rounds.$"

BattleCafe_ExplainRules_Text_3:
# 237 "data/maps/BattleCafe/scripts.pory"
	.string "There are no breaks once service\n"
	.string "begins.\p"
	.string "A loss ends the run, though\n"
	.string "you may retry until you win.\p"
	.string "Each challenge can be won once per day.$"

BattleCafe_ExplainRules_Text_4:
# 246 "data/maps/BattleCafe/scripts.pory"
	.string "Both Endless formats use full teams\n"
	.string "of six and continue until you lose\l"
	.string "or choose to retire.\p"
	.string "Endless Challenge heals your party\n"
	.string "after every win and awards 1 point.$"

BattleCafe_ExplainRules_Text_5:
# 252 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party\n"
	.string "after every third victory and awards\l"
	.string "2 points per win.\p"
	.string "Your best streak in each format is\n"
	.string "saved under High Scores.$"

BattleCafe_AskDailyChallenge_Text_0:
# 264 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Daily Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or try another challenge!$"

BattleCafe_AskDailyChallenge_Text_1:
# 271 "data/maps/BattleCafe/scripts.pory"
	.string "Three Café visitors are ready with\n"
	.string "teams of four.\p"
	.string "I'll tend to your party\n"
	.string "after rounds one and two.\p"
	.string "Begin today's challenge?$"

BattleCafe_AskRushMode_Text_0:
# 287 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Rush Mode\n"
	.string "today.\p"
	.string "Come back tomorrow, or take\n"
	.string "another challenge!$"

BattleCafe_AskRushMode_Text_1:
# 294 "data/maps/BattleCafe/scripts.pory"
	.string "Three seasoned visitors are waiting\n"
	.string "with teams of four.\p"
	.string "I can't tend to your party between \n"
	.string "these battles.\p"
	.string "Begin today's rush?$"

BattleCafe_AskSuperChallenge_Text_0:
# 310 "data/maps/BattleCafe/scripts.pory"
	.string "You've already cleared today's\n"
	.string "Super Challenge.\p"
	.string "Come back tomorrow,\n"
	.string "or attempt another challenge!$"

BattleCafe_AskSuperChallenge_Text_1:
# 319 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Challenge. Bring a full party of six\l"
	.string "before entering.$"

BattleCafe_AskSuperChallenge_Text_2:
# 324 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each meet your full\n"
	.string "party with six Pokémon of their own.\p"
	.string "I'll tend to your team between battles.\p"
	.string "Begin the Super Challenge?$"

BattleCafe_AskSuperRush_Text_0:
# 339 "data/maps/BattleCafe/scripts.pory"
	.string "You've already conquered Super Rush\n"
	.string "today.\p"
	.string "Come back tomorrow for\n"
	.string "another full-team trial!$"

BattleCafe_AskSuperRush_Text_1:
# 348 "data/maps/BattleCafe/scripts.pory"
	.string "Every Pokémon gets a seat in Super\n"
	.string "Rush.\p"
	.string "Bring a full party of six\n"
	.string "before entering.$"

BattleCafe_AskSuperRush_Text_2:
# 355 "data/maps/BattleCafe/scripts.pory"
	.string "Three visitors will each bring a full\n"
	.string "team of six.\p"
	.string "Once the rush begins, I can't heal\n"
	.string "your Pokémon between the battles.\p"
	.string "Begin the Super Rush?$"

BattleCafe_EndlessMenu_Text_0:
# 370 "data/maps/BattleCafe/scripts.pory"
	.string "Which Endless format will you try?$"

BattleCafe_EndlessMenu_Text_1:
# 372 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge$"

BattleCafe_EndlessMenu_Text_2:
# 373 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush$"

BattleCafe_EndlessMenu_Text_3:
# 374 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rules$"

BattleCafe_ExplainEndlessRules_Text_0:
# 385 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Challenge restores your party\n"
	.string "after every victory. \p"
	.string "Each win immediately awards 1 \n"
	.string "Café Point.\p"
	.string "Clear Super Challenge to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_1:
# 392 "data/maps/BattleCafe/scripts.pory"
	.string "Endless Rush restores your party after\n"
	.string "every third victory. \p"
	.string "Each win immediately awards 2 \n"
	.string "Café Points.\p"
	.string "Clear Super Rush to unlock it.$"

BattleCafe_ExplainEndlessRules_Text_2:
# 399 "data/maps/BattleCafe/scripts.pory"
	.string "Both formats use full 6-vs-6 battles.\n"
	.string "You may retire after any victory,\l"
	.string "and your best streak is saved.$"

BattleCafe_AskEndlessChallenge_Text_0:
# 407 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Challenge to unlock\n"
	.string "Endless Challenge.$"

BattleCafe_AskEndlessChallenge_Text_1:
# 413 "data/maps/BattleCafe/scripts.pory"
	.string "Every Endless opponent brings\n"
	.string "six Pokémon.\p"
	.string "Bring a full party of six before\n"
	.string "taking your seat.$"

BattleCafe_AskEndlessChallenge_Text_2:
# 420 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every win,\n"
	.string "and each victory earns 1 Café Point.\p"
	.string "Begin Endless Challenge?$"

BattleCafe_AskEndlessRush_Text_0:
# 436 "data/maps/BattleCafe/scripts.pory"
	.string "Clear Super Rush to unlock\n"
	.string "Endless Rush.$"

BattleCafe_AskEndlessRush_Text_1:
# 449 "data/maps/BattleCafe/scripts.pory"
	.string "Full teams of six will keep coming\n"
	.string "until you lose or retire.\p"
	.string "I'll restore your party after every third\n"
	.string "victory. Each win earns 2 Café Points.\p"
	.string "Begin Endless Rush?$"

BattleCafe_BeginChallenge_Text_0:
# 474 "data/maps/BattleCafe/scripts.pory"
	.string "No final course. No final opponent.\n"
	.string "Endless service begins now!$"

BattleCafe_BeginChallenge_Text_1:
# 477 "data/maps/BattleCafe/scripts.pory"
	.string "Three courses. Three opponents.\n"
	.string "Service begins now!$"

BattleCafe_ChallengeNextRound_Text_0:
# 500 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points,\l"
	.string "and your party was restored.\p"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_1:
# 525 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Three battles cleared! Your party\n"
	.string "was restored. Continue the run?$"

BattleCafe_ChallengeNextRound_Text_2:
# 531 "data/maps/BattleCafe/scripts.pory"
	.string "Victory! Streak: {STR_VAR_1}.\n"
	.string "You received {STR_VAR_2} Café Points.\p"
	.string "Your party has not been restored.\n"
	.string "Continue the run?$"

BattleCafe_ChallengeNextRound_Text_3:
# 551 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next challenger is arriving!$"

BattleCafe_ChallengeNextRound_Text_4:
# 557 "data/maps/BattleCafe/scripts.pory"
	.string "Your party was restored.\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_5:
# 561 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Super Rush!\n"
	.string "The next full team is arriving!$"

BattleCafe_ChallengeNextRound_Text_6:
# 564 "data/maps/BattleCafe/scripts.pory"
	.string "No healing in Rush Mode!\n"
	.string "The next challenger is arriving!$"

BattleCafe_EndlessRetired_Text_0:
# 581 "data/maps/BattleCafe/scripts.pory"
	.string "Run retired at {STR_VAR_1} wins.\p"
	.string "Your party is fully restored, your record\n"
	.string "is safe, and every point is yours to keep.$"

BattleCafe_ChallengeLost_Text_0:
# 624 "data/maps/BattleCafe/scripts.pory"
	.string "Your Endless run ends at {STR_VAR_1}\n"
	.string "wins. I've fully\l"
	.string "restored your party.\p"
	.string "Every Café Point you earned is yours\n"
	.string "to keep. Try to push even farther\l"
	.string "next time!$"

BattleCafe_ChallengeLost_Text_1:
# 632 "data/maps/BattleCafe/scripts.pory"
	.string "Tough course, huh? I've fully restored\n"
	.string "your party.\p"
	.string "Catch your breath, rework\n"
	.string "your strategy, and come at it again\l"
	.string "whenever you like!$"

BattleCafe_ChallengeWon_Text_0:
# 655 "data/maps/BattleCafe/scripts.pory"
	.string "Daily Challenge complete!\p"
	.string "That's {STR_VAR_1} Café Points for you.$"

BattleCafe_ChallengeWon_Text_1:
# 665 "data/maps/BattleCafe/scripts.pory"
	.string "Rush Mode complete! That took\n"
	.string "some real grit.\p"
	.string "Here's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_2:
# 676 "data/maps/BattleCafe/scripts.pory"
	.string "Super Challenge complete!\n"
	.string "Full team, full effort!\p"
	.string "That's {STR_VAR_1} Café Points.$"

BattleCafe_ChallengeWon_Text_3:
# 686 "data/maps/BattleCafe/scripts.pory"
	.string "Incredible! You have beaten\n"
	.string "the Super Rush mode!\p"
	.string "I can hardly believe it!\p"
	.string "Here's your reward of\n"
	.string "{STR_VAR_1} Café Points.$"

BattleCafe_RewardMenu_Text_0:
# 704 "data/maps/BattleCafe/scripts.pory"
	.string "You have {STR_VAR_1} Café Points.\n"
	.string "Anything you want to exchange for?$"

BattleCafe_RewardMenu_Text_1:
# 708 "data/maps/BattleCafe/scripts.pory"
	.string "G. Articuno - 5$"

BattleCafe_RewardMenu_Text_2:
# 709 "data/maps/BattleCafe/scripts.pory"
	.string "G. Zapdos - 5$"

BattleCafe_RewardMenu_Text_3:
# 710 "data/maps/BattleCafe/scripts.pory"
	.string "G. Moltres - 5$"

BattleCafe_RewardMenu_Text_4:
# 711 "data/maps/BattleCafe/scripts.pory"
	.string "Tornadus - 5$"

BattleCafe_RewardMenu_Text_5:
# 712 "data/maps/BattleCafe/scripts.pory"
	.string "Thundurus - 5$"

BattleCafe_RewardMenu_Text_6:
# 713 "data/maps/BattleCafe/scripts.pory"
	.string "Landorus - 5$"

BattleCafe_RewardMenu_Text_7:
# 714 "data/maps/BattleCafe/scripts.pory"
	.string "Enamorus - 5$"

BattleCafe_RewardMenu_Text_8:
# 715 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Koko - 5$"

BattleCafe_RewardMenu_Text_9:
# 716 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Lele - 5$"

BattleCafe_RewardMenu_Text_10:
# 717 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Bulu - 5$"

BattleCafe_RewardMenu_Text_11:
# 718 "data/maps/BattleCafe/scripts.pory"
	.string "Tapu Fini - 5$"

BattleCafe_RewardMenu_Text_12:
# 719 "data/maps/BattleCafe/scripts.pory"
	.string "Shiny Genome - 4$"

BattleCafe_RewardMenu_Text_13:
# 720 "data/maps/BattleCafe/scripts.pory"
	.string "2 Gold Caps - 5$"

BattleCafe_RewardMenu_Text_14:
# 721 "data/maps/BattleCafe/scripts.pory"
	.string "¥250,000 - 5$"

BattleCafe_RewardMenu_Text_15:
# 722 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Atk - 4$"

BattleCafe_RewardMenu_Text_16:
# 723 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Def - 4$"

BattleCafe_RewardMenu_Text_17:
# 724 "data/maps/BattleCafe/scripts.pory"
	.string "Vitamin Set Spe - 2$"

BattleCafe_RewardMenu_Text_18:
# 727 "data/maps/BattleCafe/scripts.pory"
	.string "Miraidon - 25$"

BattleCafe_RewardMenu_Text_19:
# 731 "data/maps/BattleCafe/scripts.pory"
	.string "Koraidon - 25$"

BattleCafe_ChooseArticuno_Text_0:
# 761 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Articuno to you.$"

BattleCafe_ChooseZapdos_Text_0:
# 772 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Zapdos to you.$"

BattleCafe_ChooseMoltres_Text_0:
# 783 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Galarian\n"
	.string "Moltres to you.$"

BattleCafe_ChooseTornadus_Text_0:
# 794 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tornadus\n"
	.string "to you.$"

BattleCafe_ChooseThundurus_Text_0:
# 805 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Thundurus\n"
	.string "to you.$"

BattleCafe_ChooseLandorus_Text_0:
# 816 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Landorus\n"
	.string "to you.$"

BattleCafe_ChooseEnamorus_Text_0:
# 827 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Enamorus\n"
	.string "to you.$"

BattleCafe_ChooseTapuKoko_Text_0:
# 838 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Koko\n"
	.string "to you.$"

BattleCafe_ChooseTapuLele_Text_0:
# 849 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Lele\n"
	.string "to you.$"

BattleCafe_ChooseTapuBulu_Text_0:
# 860 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Bulu\n"
	.string "to you.$"

BattleCafe_ChooseTapuFini_Text_0:
# 871 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Tapu Fini\n"
	.string "to you.$"

BattleCafe_ConfirmRewardMon_Text_0:
# 885 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmRewardMon_Text_1:
# 922 "data/maps/BattleCafe/scripts.pory"
	.string "You might find this useful.$"

BattleCafe_ConfirmRewardMon_Text_2:
# 926 "data/maps/BattleCafe/scripts.pory"
	.string "A fair trade. I'm sure it'll fit right\n"
	.string "into your team.$"

BattleCafe_ChooseMiraidon_Text_0:
# 933 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Miraidon\n"
	.string "to you.$"

BattleCafe_ChooseKoraidon_Text_0:
# 944 "data/maps/BattleCafe/scripts.pory"
	.string "I've already entrusted Koraidon\n"
	.string "to you.$"

BattleCafe_ConfirmParadoxLegend_Text_0:
# 958 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 25 Café Points for\n"
	.string "{STR_VAR_1}?$"

BattleCafe_ConfirmParadoxLegend_Text_1:
# 976 "data/maps/BattleCafe/scripts.pory"
	.string "A rare specimen from Paldea. Take good\n"
	.string "care of it!$"

BattleCafe_ChooseShinyGenome_Text_0:
# 985 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for a\n"
	.string "Shiny Genome?$"

BattleCafe_ChooseShinyGenome_Text_1:
# 999 "data/maps/BattleCafe/scripts.pory"
	.string "A rare find. Use it on whichever\n"
	.string "Pokémon you want to bring out the\l"
	.string "shine.$"

BattleCafe_ChooseGoldBottleCaps_Text_0:
# 1009 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for two\n"
	.string "Gold Bottle Caps?$"

BattleCafe_ChooseGoldBottleCaps_Text_1:
# 1023 "data/maps/BattleCafe/scripts.pory"
	.string "Two Gold Bottle Caps, polished up and\n"
	.string "ready. Here you go!$"

BattleCafe_ChooseMoney_Text_0:
# 1032 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 5 Café Points for\n"
	.string "¥250,000?$"

BattleCafe_ChooseMoney_Text_1:
# 1044 "data/maps/BattleCafe/scripts.pory"
	.string "Use it well, and perhaps spend a little\n"
	.string "on dessert!$"

BattleCafe_ChooseVitaminSetAtk_Text_0:
# 1053 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Protein EX and Calcium EX?$"

BattleCafe_ChooseVitaminSetAtk_Text_1:
# 1068 "data/maps/BattleCafe/scripts.pory"
	.string "Two Protein EX and two Calcium EX,\n"
	.string "power and wisdom!$"

BattleCafe_ChooseVitaminSetDef_Text_0:
# 1077 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 4 Café Points for two each of\n"
	.string "Iron EX and Zinc EX?$"

BattleCafe_ChooseVitaminSetDef_Text_1:
# 1092 "data/maps/BattleCafe/scripts.pory"
	.string "Two Iron EX and two Zinc EX,\n"
	.string "time to bulk up!$"

BattleCafe_ChooseVitaminSetSpe_Text_0:
# 1101 "data/maps/BattleCafe/scripts.pory"
	.string "Exchange 2 Café Points for\n"
	.string "two Carbos EX?$"

BattleCafe_ChooseVitaminSetSpe_Text_1:
# 1116 "data/maps/BattleCafe/scripts.pory"
	.string "Two Carbos EX, ready to speed up!$"

BattleCafe_NotEnoughPoints_Text_0:
# 1121 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 5 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughLegendPoints_Text_0:
# 1128 "data/maps/BattleCafe/scripts.pory"
	.string "That prize costs 25 Café Points.\n"
	.string "Complete more of my challenges and\l"
	.string "try again!$"

BattleCafe_NotEnoughFourPoints_Text_0:
# 1135 "data/maps/BattleCafe/scripts.pory"
	.string "The Shiny Genome costs 4 Café Points.\n"
	.string "Complete one of my challenges and try\l"
	.string "again!$"

BattleCafe_NotEnoughVitaminSetPoints_Text_0:
# 1142 "data/maps/BattleCafe/scripts.pory"
	.string "You don't have enough Café Points for\n"
	.string "that vitamin set. \p"
	.string "Complete one of my\n"
	.string "challenges and try again!$"

BattleCafe_NotEnoughBagSpace_Text_0:
# 1151 "data/maps/BattleCafe/scripts.pory"
	.string "Your Bag is too full for that prize.\n"
	.string "Make some room and come back whenever\l"
	.string "you're ready!$"

BattleCafe_Goodbye_Text_0:
# 1158 "data/maps/BattleCafe/scripts.pory"
	.string "Come back hungry for another battle!$"

BattleCafe_TrainerAthena_Text_0:
# 1175 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun? Let's try this\n"
	.string "again tomorrow!$"

BattleCafe_TrainerAthena_Text_1:
# 1180 "data/maps/BattleCafe/scripts.pory"
	.string "Let's see if you can survive this\n"
	.string "stall!$"

BattleCafe_TrainerAthena_Text_2:
# 1182 "data/maps/BattleCafe/scripts.pory"
	.string "Huh?$"

BattleCafe_TrainerAthena_Text_3:
# 1184 "data/maps/BattleCafe/scripts.pory"
	.string "Did you have fun?$"

BattleCafe_TrainerDoves_Text_0:
# 1195 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when \n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerDoves_Text_1:
# 1201 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let me show you the power of \n"
	.string "Genesect!$"

BattleCafe_TrainerDoves_Text_2:
# 1203 "data/maps/BattleCafe/scripts.pory"
	.string "Banned again from Overused...$"

BattleCafe_TrainerDoves_Text_3:
# 1205 "data/maps/BattleCafe/scripts.pory"
	.string "Doves: Let's fight again tomorrow when\n"
	.string "my Genesect is allowed on the \l"
	.string "battlefield.$"

BattleCafe_TrainerElton_Text_0:
# 1218 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Rematch tomorrow! Be there!$"

BattleCafe_TrainerElton_Text_1:
# 1222 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Let's have a battle with our\n"
	.string "favourite Pokémon!$"

BattleCafe_TrainerElton_Text_2:
# 1224 "data/maps/BattleCafe/scripts.pory"
	.string "You handled every trick I had!$"

BattleCafe_TrainerElton_Text_3:
# 1226 "data/maps/BattleCafe/scripts.pory"
	.string "Elton: Even Gengar's impressed, and it\n"
	.string "rarely takes a loss seriously.$"

BattleCafe_TrainerNem_Text_0:
# 1238 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Come back tomorrow.$"

BattleCafe_TrainerNem_Text_1:
# 1242 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: Think fast!$"

BattleCafe_TrainerNem_Text_2:
# 1243 "data/maps/BattleCafe/scripts.pory"
	.string "I'll be watching.$"

BattleCafe_TrainerNem_Text_3:
# 1245 "data/maps/BattleCafe/scripts.pory"
	.string "Nem: We can fight again tomorrow.$"

BattleCafe_TrainerBai_Text_0:
# 1256 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: That was a good match!\n"
	.string "Let's fight again tomorrow!$"

BattleCafe_TrainerBai_Text_1:
# 1261 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Let's see what you bring to \n"
	.string "the table!$"

BattleCafe_TrainerBai_Text_2:
# 1263 "data/maps/BattleCafe/scripts.pory"
	.string "Guess I'm cooked this time...$"

BattleCafe_TrainerBai_Text_3:
# 1265 "data/maps/BattleCafe/scripts.pory"
	.string "Bai: Good match! Let's try this again \n"
	.string "tomorrow!$"

BattleCafe_TrainerDrac_Text_0:
# 1277 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: You're really tough! Let's fight\n"
	.string "again tomorrow!$"

BattleCafe_TrainerDrac_Text_1:
# 1282 "data/maps/BattleCafe/scripts.pory"
	.string "Drac: Care for a double battle?$"

BattleCafe_TrainerDrac_Text_2:
# 1283 "data/maps/BattleCafe/scripts.pory"
	.string "Soothed.$"

BattleCafe_TrainerMarina_Text_0:
# 1297 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper says the rain has\n"
	.string "passed for today. Tomorrow!$"

BattleCafe_TrainerMarina_Text_1:
# 1302 "data/maps/BattleCafe/scripts.pory"
	.string "Pelipper, call in the rain!\n"
	.string "Let's make some waves.$"

BattleCafe_TrainerMarina_Text_2:
# 1304 "data/maps/BattleCafe/scripts.pory"
	.string "You weathered the whole storm.$"

BattleCafe_TrainerMarina_Text_3:
# 1306 "data/maps/BattleCafe/scripts.pory"
	.string "Even Swampert couldn't stop you once\n"
	.string "you found your rhythm.$"

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
