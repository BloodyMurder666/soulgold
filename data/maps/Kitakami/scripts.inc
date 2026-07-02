Kitakami_MapScripts::
	.byte 0


Kitakami_OldLady::
# 4 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_OldLady_Text_0, MSGBOX_NPC
	return


Kitakami_Trigger::
# 11 "data/maps/Kitakami/scripts.pory"
	setflag FLAG_VISITED_KITAKAMI
# 12 "data/maps/Kitakami/scripts.pory"
	setvar VAR_KITAKAMI_STATE, 1
	end


Kitakami_OgerponTrigger::
# 17 "data/maps/Kitakami/scripts.pory"
	lock
# 18 "data/maps/Kitakami/scripts.pory"
	playse SE_PIN
# 19 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 20 "data/maps/Kitakami/scripts.pory"
	turnobject LOCALID_KITAKAMI_OGERPON, DIR_SOUTH
# 21 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Common_Movement_ExclamationMark
# 22 "data/maps/Kitakami/scripts.pory"
	delay 30
# 23 "data/maps/Kitakami/scripts.pory"
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
# 24 "data/maps/Kitakami/scripts.pory"
	waitmoncry
# 25 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 26 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_0
# 28 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 29 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 30 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_1
# 32 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 33 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 34 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_0
# 36 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 37 "data/maps/Kitakami/scripts.pory"
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
# 38 "data/maps/Kitakami/scripts.pory"
	waitmoncry
# 39 "data/maps/Kitakami/scripts.pory"
	delay 20
# 40 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 41 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
# 42 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 43 "data/maps/Kitakami/scripts.pory"
	waitse
# 45 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 46 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
# 47 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 48 "data/maps/Kitakami/scripts.pory"
	waitse
# 50 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 51 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
# 52 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 53 "data/maps/Kitakami/scripts.pory"
	waitse
# 55 "data/maps/Kitakami/scripts.pory"
	playse SE_LEDGE
# 56 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
# 57 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 58 "data/maps/Kitakami/scripts.pory"
	waitse
# 60 "data/maps/Kitakami/scripts.pory"
	setflag FLAG_HIDE_KITAKAMI_OGERPON
# 61 "data/maps/Kitakami/scripts.pory"
	removeobject LOCALID_KITAKAMI_OGERPON
# 62 "data/maps/Kitakami/scripts.pory"
	setvar VAR_KITAKAMI_STATE, 2
# 63 "data/maps/Kitakami/scripts.pory"
	release
	end


Kitakami_Fatman::
# 68 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Fatman_Text_0, MSGBOX_NPC
	return


Kitakami_Battlegirl::
# 73 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Battlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_Littlegirl::
# 79 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Littlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_WestSign::
# 87 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_WestSign_Text_0, MSGBOX_SIGN
	return


Kitakami_WellSign::
# 91 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_WellSign_Text_0, MSGBOX_SIGN
	return


# 26 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_0:
# 26 "data/maps/Kitakami/scripts.pory"
	jump_in_place_down
# 27 "data/maps/Kitakami/scripts.pory"
	delay_16
	step_end

# 30 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_1:
# 30 "data/maps/Kitakami/scripts.pory"
	jump_in_place_up
# 31 "data/maps/Kitakami/scripts.pory"
	delay_16
	step_end

# 41 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_2:
# 41 "data/maps/Kitakami/scripts.pory"
	jump_up
	step_end

Kitakami_OldLady_Text_0:
# 4 "data/maps/Kitakami/scripts.pory"
	.string "Oh a visitor? Where are you from?\n"
	.string "...\l"
	.string "Newbark Town? That's quite a journey\l"
	.string "to get here!$"

Kitakami_Fatman_Text_0:
# 68 "data/maps/Kitakami/scripts.pory"
	.string "There's no technology here!\n"
	.string "WHAT AM I SUPPOSED TO DO??$"

Kitakami_Battlegirl_Text_0:
# 73 "data/maps/Kitakami/scripts.pory"
	.string "I come here to train once a year. It's a\n"
	.string "nice middle ground between the busy\l"
	.string "city life and harshness of Mt. Silver.$"

Kitakami_Littlegirl_Text_0:
# 79 "data/maps/Kitakami/scripts.pory"
	.string "Mom used to say bad children are taken\n"
	.string "to the cave down there. \p"
	.string "It's a place where Fezandipiti \n"
	.string "roosts during the summer.$"

Kitakami_WestSign_Text_0:
# 87 "data/maps/Kitakami/scripts.pory"
	.string "Kitakami Town - Timeless traditions$"

Kitakami_WellSign_Text_0:
# 91 "data/maps/Kitakami/scripts.pory"
	.string "Old Well - Careful with the ladder!$"
