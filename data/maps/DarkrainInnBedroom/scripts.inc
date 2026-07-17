DarkrainInnBedroom_MapScripts::
# 2 "data/maps/DarkrainInnBedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DarkrainInnBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkrainInnBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/DarkrainInnBedroom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 4 "data/maps/DarkrainInnBedroom/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 1
	goto_if_eq DarkrainInnBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 7 "data/maps/DarkrainInnBedroom/scripts.pory"
	setdynamicwarp MAP_DARKRAI_INN1RUINED, 0
	return

DarkrainInnBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data/maps/DarkrainInnBedroom/scripts.pory"
	setdynamicwarp MAP_DARKRAI_INN1, 0
	return


DarkraiInnBedroom_Phone::
# 13 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Phone_Text_0, MSGBOX_SIGN
	return


DarkraiInnBedroom_Bed::
# 20 "data/maps/DarkrainInnBedroom/scripts.pory"
	lock
# 21 "data/maps/DarkrainInnBedroom/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 1
	goto_if_eq DarkraiInnBedroom_Bed_2
# 71 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_8
DarkraiInnBedroom_Bed_1:
# 73 "data/maps/DarkrainInnBedroom/scripts.pory"
	release
	end

DarkraiInnBedroom_Bed_2:
# 22 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_0
# 27 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_1, MSGBOX_YESNO
# 28 "data/maps/DarkrainInnBedroom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DarkraiInnBedroom_Bed_5
# 58 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_7
# 59 "data/maps/DarkrainInnBedroom/scripts.pory"
	closemessage
# 60 "data/maps/DarkrainInnBedroom/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 2
# 61 "data/maps/DarkrainInnBedroom/scripts.pory"
	setdynamicwarp MAP_DARKRAI_INN1RUINED, 0
# 62 "data/maps/DarkrainInnBedroom/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_NORMAL
# 63 "data/maps/DarkrainInnBedroom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 64 "data/maps/DarkrainInnBedroom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 65 "data/maps/DarkrainInnBedroom/scripts.pory"
	waitmoncry
# 66 "data/maps/DarkrainInnBedroom/scripts.pory"
	waitmovement 0
# 67 "data/maps/DarkrainInnBedroom/scripts.pory"
	release
	end

DarkraiInnBedroom_Bed_5:
# 29 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_2
# 30 "data/maps/DarkrainInnBedroom/scripts.pory"
	dynmultichoice 20, 4, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, DarkraiInnBedroom_Bed_Text_3, DarkraiInnBedroom_Bed_Text_3, DarkraiInnBedroom_Bed_Text_3, DarkraiInnBedroom_Bed_Text_3, DarkraiInnBedroom_Bed_Text_4
# 31 "data/maps/DarkrainInnBedroom/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/DarkrainInnBedroom/scripts.pory"
	case 0, DarkraiInnBedroom_Bed_9
# 33 "data/maps/DarkrainInnBedroom/scripts.pory"
	case 1, DarkraiInnBedroom_Bed_9
# 34 "data/maps/DarkrainInnBedroom/scripts.pory"
	case 2, DarkraiInnBedroom_Bed_9
# 35 "data/maps/DarkrainInnBedroom/scripts.pory"
	case 3, DarkraiInnBedroom_Bed_9
# 43 "data/maps/DarkrainInnBedroom/scripts.pory"
	case 4, DarkraiInnBedroom_Bed_10
	goto DarkraiInnBedroom_Bed_1

DarkraiInnBedroom_Bed_9:
# 36 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_5
# 38 "data/maps/DarkrainInnBedroom/scripts.pory"
	applymovement LOCALID_PLAYER, DarkraiInnBedroom_Bed_Movement_0
# 39 "data/maps/DarkrainInnBedroom/scripts.pory"
	waitmovement
# 40 "data/maps/DarkrainInnBedroom/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 41 "data/maps/DarkrainInnBedroom/scripts.pory"
	special DoSoftReset
	end

DarkraiInnBedroom_Bed_10:
# 44 "data/maps/DarkrainInnBedroom/scripts.pory"
	msgbox DarkraiInnBedroom_Bed_Text_6
# 46 "data/maps/DarkrainInnBedroom/scripts.pory"
	closemessage
# 47 "data/maps/DarkrainInnBedroom/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 2
# 48 "data/maps/DarkrainInnBedroom/scripts.pory"
	setdynamicwarp MAP_DARKRAI_INN1RUINED, 0
# 49 "data/maps/DarkrainInnBedroom/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_NORMAL
# 50 "data/maps/DarkrainInnBedroom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 51 "data/maps/DarkrainInnBedroom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 52 "data/maps/DarkrainInnBedroom/scripts.pory"
	waitmoncry
# 53 "data/maps/DarkrainInnBedroom/scripts.pory"
	waitmovement 0
# 54 "data/maps/DarkrainInnBedroom/scripts.pory"
	release
	end


# 38 "data/maps/DarkrainInnBedroom/scripts.pory"
DarkraiInnBedroom_Bed_Movement_0:
# 38 "data/maps/DarkrainInnBedroom/scripts.pory"
	walk_slow_right
# 38 "data/maps/DarkrainInnBedroom/scripts.pory"
	face_down
	step_end

DarkraiInnBedroom_Phone_Text_0:
# 13 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "An antique telephone.\p"
	.string "The cord doesn't seem to connect\n"
	.string "anywhere.$"

DarkraiInnBedroom_Bed_Text_0:
# 22 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Just staring at this bed makes you feel\n"
	.string "drowsy.\p"
	.string "Perhaps it's time to take a rest and\n"
	.string "close your eyes for a little while...$"

DarkraiInnBedroom_Bed_Text_1:
# 27 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Take a short nap..?$"

DarkraiInnBedroom_Bed_Text_2:
# 29 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Was there something you forgot...?$"

DarkraiInnBedroom_Bed_Text_3:
# 30 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Sleep$"

DarkraiInnBedroom_Bed_Text_4:
# 30 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Resist$"

DarkraiInnBedroom_Bed_Text_5:
# 36 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "It was probably nothing that can't wait\n"
	.string "a bit...$"

DarkraiInnBedroom_Bed_Text_6:
# 44 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "You feel a chill and decide to step away\n"
	.string "from the bed.$"

DarkraiInnBedroom_Bed_Text_7:
# 58 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "You decide to step away from the bed.$"

DarkraiInnBedroom_Bed_Text_8:
# 71 "data/maps/DarkrainInnBedroom/scripts.pory"
	.string "Now's not the time to be napping.$"
