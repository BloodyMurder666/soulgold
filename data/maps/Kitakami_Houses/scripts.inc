Kitakami_Houses_MapScripts::
	.byte 0


KitakamiHouses_1_Oldman::
# 4 "data/maps/Kitakami_Houses/scripts.pory"
	lock
# 5 "data/maps/Kitakami_Houses/scripts.pory"
	faceplayer
# 6 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_set FLAG_CANDY_KITAKAMI, KitakamiHouses_1_Oldman_2
# 12 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_1_Oldman_Text_1
# 15 "data/maps/Kitakami_Houses/scripts.pory"
	random 3
# 16 "data/maps/Kitakami_Houses/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/Kitakami_Houses/scripts.pory"
	case 0, KitakamiHouses_1_Oldman_6
# 19 "data/maps/Kitakami_Houses/scripts.pory"
	case 1, KitakamiHouses_1_Oldman_7
# 22 "data/maps/Kitakami_Houses/scripts.pory"
	case 2, KitakamiHouses_1_Oldman_8
KitakamiHouses_1_Oldman_4:
# 26 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_CANDY_KITAKAMI
# 27 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_1_Oldman_Text_0
# 29 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_1_Oldman_2:
# 7 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_1_Oldman_Text_0
# 9 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_1_Oldman_6:
# 18 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_EXP_CANDY_M, 3
	goto KitakamiHouses_1_Oldman_4

KitakamiHouses_1_Oldman_7:
# 20 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_EXP_CANDY_L, 2
# 21 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_EXP_CANDY_M, 1
	goto KitakamiHouses_1_Oldman_4

KitakamiHouses_1_Oldman_8:
# 23 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, 1
# 24 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_EXP_CANDY_L, 1
	goto KitakamiHouses_1_Oldman_4


KitakamiHouses_2_Steven::
# 35 "data/maps/Kitakami_Houses/scripts.pory"
	lock
# 36 "data/maps/Kitakami_Houses/scripts.pory"
	faceplayer
# 37 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_set FLAG_MET_STEVEN, KitakamiHouses_2_Steven_2
# 102 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_7
# 107 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_8
# 117 "data/maps/Kitakami_Houses/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
# 118 "data/maps/Kitakami_Houses/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
# 119 "data/maps/Kitakami_Houses/scripts.pory"
	givemon SPECIES_BELDUM, 15, ITEM_METAGROSSITE, ITEM_LUXURY_BALL
# 120 "data/maps/Kitakami_Houses/scripts.pory"
	call Common_EventScript_GiftMon
# 121 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_MET_STEVEN
# 122 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_9
# 123 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 124 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_2:
# 38 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, KitakamiHouses_2_Steven_5
# 93 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_6
# 98 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_5:
# 40 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_unset FLAG_TEMP_10, KitakamiHouses_2_Steven_9
KitakamiHouses_2_Steven_8:
# 54 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_1, MSGBOX_YESNO
# 55 "data/maps/Kitakami_Houses/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KitakamiHouses_2_Steven_11
# 88 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_9:
# 41 "data/maps/Kitakami_Houses/scripts.pory"
	playse SE_PIN
# 42 "data/maps/Kitakami_Houses/scripts.pory"
	applymovement LOCALID_KITAKAMI_STEVEN, Common_Movement_ExclamationMark
# 43 "data/maps/Kitakami_Houses/scripts.pory"
	applymovement LOCALID_KITAKAMI_STEVEN, KitakamiHouses_2_Steven_Movement_0
# 44 "data/maps/Kitakami_Houses/scripts.pory"
	waitmovement 0
# 45 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_0
# 52 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_TEMP_10
	goto KitakamiHouses_2_Steven_8

KitakamiHouses_2_Steven_11:
# 57 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_2
# 59 "data/maps/Kitakami_Houses/scripts.pory"
	trainerbattle_no_intro TRAINER_STEVEN, KitakamiHouses_2_Steven_Text_3
# 61 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_4
# 69 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_JADE_ORB
# 70 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 71 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_5
# 74 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 75 "data/maps/Kitakami_Houses/scripts.pory"
	waitbuttonpress
# 76 "data/maps/Kitakami_Houses/scripts.pory"
	closemessage
# 77 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_BEAT_STEVEN_KITAKAMI
# 78 "data/maps/Kitakami_Houses/scripts.pory"
	moveobjecttocoords LOCALID_KITAKAMI_STEVEN, 28, 8, DIR_SOUTH
# 79 "data/maps/Kitakami_Houses/scripts.pory"
	waitmovement LOCALID_KITAKAMI_STEVEN
# 80 "data/maps/Kitakami_Houses/scripts.pory"
	delay 15
# 81 "data/maps/Kitakami_Houses/scripts.pory"
	playse SE_EXIT
# 83 "data/maps/Kitakami_Houses/scripts.pory"
	removeobject LOCALID_KITAKAMI_STEVEN
# 84 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end


PorygonPC::
# 129 "data/maps/Kitakami_Houses/scripts.pory"
	lockall
# 130 "data/maps/Kitakami_Houses/scripts.pory"
	playmoncry SPECIES_PORYGON_Z, CRY_MODE_NORMAL
# 131 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox PorygonPC_Text_0
# 133 "data/maps/Kitakami_Houses/scripts.pory"
	goto EventScript_PCMainMenu
	return


KitakamiHouses_3_Lady::
# 137 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_3_Lady_Text_0, MSGBOX_NPC
	return


KitakamiHouses_3_Man::
# 141 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_3_Lady_Text_0, MSGBOX_NPC
	return


# 43 "data/maps/Kitakami_Houses/scripts.pory"
KitakamiHouses_2_Steven_Movement_0:
# 43 "data/maps/Kitakami_Houses/scripts.pory"
	face_player
	step_end

KitakamiHouses_1_Oldman_Text_0:
# 7 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Come back tomorrow when I have\n"
	.string "prepared another batch!$"

KitakamiHouses_1_Oldman_Text_1:
# 12 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Ho ho ho, I'm the best candy baker in\n"
	.string "Johto! Here, have some from my daily\l"
	.string "batch!$"

KitakamiHouses_2_Steven_Text_0:
# 45 "data/maps/Kitakami_Houses/scripts.pory"
	.string "That face of determination... I assume\n"
	.string "you have become the Champion of Johto?\l"
	.string "...\l"
	.string "Impressive, I was right about your\l"
	.string "potential as a trainer. \l"
	.string "I'd be more than happy to battle you\l"
	.string "now, if you are alright with that.$"

KitakamiHouses_2_Steven_Text_1:
# 54 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Are you ready to face me?$"

KitakamiHouses_2_Steven_Text_2:
# 57 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Splendid, I'll hold nothing back\n"
	.string "and I expect you to do the same!$"

KitakamiHouses_2_Steven_Text_3:
# 59 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Outstanding, you truly have earned\n"
	.string "the title of a Champion.$"

KitakamiHouses_2_Steven_Text_4:
# 61 "data/maps/Kitakami_Houses/scripts.pory"
	.string "It cannot be overstated how happy\n"
	.string "this battle made me. You are a\l"
	.string "trainer of exceptional skill.\p"
	.string "I want you to have this as a gift\n"
	.string "of our meeting. I excavated it from\l"
	.string "nearby mountain. You might find some\l"
	.string "use for it near Route 46.$"

KitakamiHouses_2_Steven_Text_5:
# 71 "data/maps/Kitakami_Houses/scripts.pory"
	.string "I think I'll start heading out to \n"
	.string "explore new places now. I hope our \l"
	.string "paths cross again some day, {PLAYER}.$"

KitakamiHouses_2_Steven_Text_6:
# 93 "data/maps/Kitakami_Houses/scripts.pory"
	.string "If you end up becoming a Champion of\n"
	.string "the region, you should come see me.\l"
	.string "I would love to battle you with my\l"
	.string "full strength.$"

KitakamiHouses_2_Steven_Text_7:
# 102 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Oh, hello. Who might you be?\n"
	.string "...\l"
	.string "{PLAYER}? Nice to meet you.\l"
	.string "My name is Steven, I hail from the Hoenn\l"
	.string "region in search of rare stones.$"

KitakamiHouses_2_Steven_Text_8:
# 107 "data/maps/Kitakami_Houses/scripts.pory"
	.string "You look like a trainer, are you on the\n"
	.string "quest to collect badges in Johto?\l"
	.string "Hmm.. Perhaps... Yes, you may have the\l"
	.string "potential for what it takes.\l"
	.string "Would you be willing to hear my request?\l"
	.string "I would like you to have this Beldum.\l"
	.string "It's a rare Pokémon from Hoenn. \l"
	.string "Take care of it and come see me again\l"
	.string "if you become the Champion. I would\l"
	.string "like to battle you then.$"

KitakamiHouses_2_Steven_Text_9:
# 122 "data/maps/Kitakami_Houses/scripts.pory"
	.string "I have high expectations for you.$"

PorygonPC_Text_0:
# 131 "data/maps/Kitakami_Houses/scripts.pory"
	.string "{PLAYER} booted up the Porygon \n"
	.string "remote PC.$"

KitakamiHouses_3_Lady_Text_0:
# 137 "data/maps/Kitakami_Houses/scripts.pory"
	.string "TODO$"
