Kitakami_Temple_BattleRoom_MapScripts::
	.byte 0


BattleRoom_Audino::
# 4 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 5 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	faceplayer
# 6 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 7 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_Audino_Text_0
# 8 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmoncry
# 9 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


BattleRoom_Machamp::
# 14 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 15 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
# 16 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_Machamp_Text_0
# 17 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmoncry
# 18 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


BattleRoom_Mienshao::
# 23 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 24 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playmoncry SPECIES_MIENSHAO, CRY_MODE_NORMAL
# 25 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_Mienshao_Text_0
# 26 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmoncry
# 27 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


BattleRoom_BattleGirl::
# 32 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 33 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_BattleGirl_Text_0
# 34 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playmoncry SPECIES_MIENSHAO, CRY_MODE_NORMAL
# 35 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	applymovement LOCALID_KITAKAMI_MIENSHAO, BattleRoom_BattleGirl_Movement_0
# 36 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmoncry
# 38 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


BattleRoom_BlackBelt::
# 43 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 44 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_BlackBelt_Text_0
# 45 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
# 46 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	applymovement LOCALID_KITAKAMI_MACHAMP, BattleRoom_BlackBelt_Movement_0
# 47 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitmoncry
# 49 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


BattleRoom_MoneyTrainer::
# 54 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	lock
# 55 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	faceplayer
# 56 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	goto_if_unset FLAG_TEMP_1, BattleRoom_MoneyTrainer_2
BattleRoom_MoneyTrainer_1:
# 64 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	showmoneybox 0, 0
# 65 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_1, MSGBOX_YESNO
# 68 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleRoom_MoneyTrainer_5
# 88 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	hidemoneybox
# 89 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_6
# 90 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end

BattleRoom_MoneyTrainer_2:
# 57 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_0
# 62 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	setflag FLAG_TEMP_1
	goto BattleRoom_MoneyTrainer_1

BattleRoom_MoneyTrainer_4:
# 93 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end

BattleRoom_MoneyTrainer_5:
# 69 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	checkmoney 10000
# 70 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleRoom_MoneyTrainer_9
# 79 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	removemoney 10000
# 80 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	updatemoneybox 0
# 81 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	playse SE_SHOP
# 82 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	waitse
# 83 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	hidemoneybox
# 84 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_3
# 85 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DOJO_AUDINO, BattleRoom_MoneyTrainer_Text_4
# 86 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_5
	goto BattleRoom_MoneyTrainer_4

BattleRoom_MoneyTrainer_9:
# 71 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	msgbox BattleRoom_MoneyTrainer_Text_2
# 75 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	hidemoneybox
# 76 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	release
	end


# 35 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
BattleRoom_BattleGirl_Movement_0:
# 35 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	jump_in_place_left
# 35 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	jump_in_place_left
	step_end

# 46 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
BattleRoom_BlackBelt_Movement_0:
# 46 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	jump_in_place_right
# 46 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	jump_in_place_right
	step_end

BattleRoom_Audino_Text_0:
# 7 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Audino: Audiini!$"

BattleRoom_Machamp_Text_0:
# 16 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Machamp: Mach!$"

BattleRoom_Mienshao_Text_0:
# 25 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Mienshao: Mii!$"

BattleRoom_BattleGirl_Text_0:
# 33 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Now Mienshao, use Hi Jump Kick!$"

BattleRoom_BlackBelt_Text_0:
# 44 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Machamp, counter with Protect!$"

BattleRoom_MoneyTrainer_Text_0:
# 57 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Greetings, we offer paid training\n"
	.string "services for visitors. \p"
	.string "The money will be used to support our \n"
	.string "temple and the village. Interested?$"

BattleRoom_MoneyTrainer_Text_1:
# 65 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "For a low price of ¥10,000, we will\n"
	.string "let you train with our Audinos and \l"
	.string "Blisseys.$"

BattleRoom_MoneyTrainer_Text_2:
# 71 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Oh my, it seems you do not have the\n"
	.string "money right now. \p"
	.string "Please come back when you have some.$"

BattleRoom_MoneyTrainer_Text_3:
# 84 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Thank you, let us begin.$"

BattleRoom_MoneyTrainer_Text_4:
# 85 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Thank you for your support.$"

BattleRoom_MoneyTrainer_Text_5:
# 86 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "Come back if you wish to train again.$"

BattleRoom_MoneyTrainer_Text_6:
# 89 "data/maps/Kitakami_Temple_BattleRoom/scripts.pory"
	.string "That's fine.$"
