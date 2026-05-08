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
	applymovement LOCALID_KITAKAMI_OGERPON, Common_Movement_ExclamationMark
# 21 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_0
# 22 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 23 "data/maps/Kitakami/scripts.pory"
	delay 48
# 24 "data/maps/Kitakami/scripts.pory"
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
# 25 "data/maps/Kitakami/scripts.pory"
	waitmoncry
# 26 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_1
# 30 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 31 "data/maps/Kitakami/scripts.pory"
	playmoncry SPECIES_OGERPON, CRY_MODE_NORMAL
# 32 "data/maps/Kitakami/scripts.pory"
	waitmoncry
# 33 "data/maps/Kitakami/scripts.pory"
	delay 20
# 34 "data/maps/Kitakami/scripts.pory"
	applymovement LOCALID_KITAKAMI_OGERPON, Kitakami_OgerponTrigger_Movement_2
# 35 "data/maps/Kitakami/scripts.pory"
	waitmovement 0
# 36 "data/maps/Kitakami/scripts.pory"
	setflag FLAG_HIDE_KITAKAMI_OGERPON
# 37 "data/maps/Kitakami/scripts.pory"
	removeobject LOCALID_KITAKAMI_OGERPON
# 38 "data/maps/Kitakami/scripts.pory"
	setvar VAR_KITAKAMI_STATE, 2
# 39 "data/maps/Kitakami/scripts.pory"
	release
	end


Kitakami_Fatman::
# 44 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Fatman_Text_0, MSGBOX_NPC
	return


Kitakami_Battlegirl::
# 49 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Battlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_Littlegirl::
# 55 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_Littlegirl_Text_0, MSGBOX_NPC
	return


Kitakami_WestSign::
# 61 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_WestSign_Text_0, MSGBOX_SIGN
	return


Kitakami_WellSign::
# 65 "data/maps/Kitakami/scripts.pory"
	msgbox Kitakami_WellSign_Text_0, MSGBOX_SIGN
	return


# 21 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_0:
# 21 "data/maps/Kitakami/scripts.pory"
	face_down
	step_end

# 26 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_1:
# 26 "data/maps/Kitakami/scripts.pory"
	jump_in_place_down
# 27 "data/maps/Kitakami/scripts.pory"
	jump_in_place_up
# 28 "data/maps/Kitakami/scripts.pory"
	jump_in_place_down
# 29 "data/maps/Kitakami/scripts.pory"
	delay_16
	step_end

# 34 "data/maps/Kitakami/scripts.pory"
Kitakami_OgerponTrigger_Movement_2:
# 34 "data/maps/Kitakami/scripts.pory"
	jump_2_up
# 34 "data/maps/Kitakami/scripts.pory"
	jump_2_up
	step_end

Kitakami_OldLady_Text_0:
# 4 "data/maps/Kitakami/scripts.pory"
	.string "Oh a visitor? Where are you from?\n"
	.string "...\l"
	.string "Newbark Town? That's quite a journey\l"
	.string "to get here!$"

Kitakami_Fatman_Text_0:
# 44 "data/maps/Kitakami/scripts.pory"
	.string "There's no technology here!\n"
	.string "WHAT DO I DO?$"

Kitakami_Battlegirl_Text_0:
# 49 "data/maps/Kitakami/scripts.pory"
	.string "I come here to train once a year. It's a\n"
	.string "nice middle ground between the busy\l"
	.string "city life and harshness of Mt. Silver.$"

Kitakami_Littlegirl_Text_0:
# 55 "data/maps/Kitakami/scripts.pory"
	.string "Mom used to say bad children are taken\n"
	.string "to the well. But actually it's a place\l"
	.string "where Fezandipiti roosts sometimes.$"

Kitakami_WestSign_Text_0:
# 61 "data/maps/Kitakami/scripts.pory"
	.string "Kitakami Town - Timeless traditions$"

Kitakami_WellSign_Text_0:
# 65 "data/maps/Kitakami/scripts.pory"
	.string "Kitakami Well - Careful with the ladder!$"
