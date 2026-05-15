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


KitakamiHouses_3_Sinistea::
# 35 "data/maps/Kitakami_Houses/scripts.pory"
	lock
# 36 "data/maps/Kitakami_Houses/scripts.pory"
	faceplayer
# 37 "data/maps/Kitakami_Houses/scripts.pory"
	playmoncry SPECIES_SINISTEA, CRY_MODE_NORMAL
# 38 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_3_Sinistea_Text_0
# 39 "data/maps/Kitakami_Houses/scripts.pory"
	waitmoncry
# 40 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end


KitakamiHouses_2_Steven::
# 45 "data/maps/Kitakami_Houses/scripts.pory"
	lock
# 46 "data/maps/Kitakami_Houses/scripts.pory"
	faceplayer
# 47 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_set FLAG_MET_STEVEN, KitakamiHouses_2_Steven_2
# 112 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_7
# 117 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_8
# 127 "data/maps/Kitakami_Houses/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
# 128 "data/maps/Kitakami_Houses/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
# 129 "data/maps/Kitakami_Houses/scripts.pory"
	givemon SPECIES_BELDUM, 15, ITEM_IRON_PLATE, ITEM_LUXURY_BALL
# 130 "data/maps/Kitakami_Houses/scripts.pory"
	call Common_EventScript_GiftMon
# 131 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_MET_STEVEN
# 132 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_9
# 133 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 134 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_2:
# 48 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, KitakamiHouses_2_Steven_5
# 103 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_6
# 108 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_5:
# 50 "data/maps/Kitakami_Houses/scripts.pory"
	goto_if_unset FLAG_TEMP_10, KitakamiHouses_2_Steven_9
KitakamiHouses_2_Steven_8:
# 65 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_1, MSGBOX_YESNO
# 66 "data/maps/Kitakami_Houses/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KitakamiHouses_2_Steven_11
# 98 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end

KitakamiHouses_2_Steven_9:
# 51 "data/maps/Kitakami_Houses/scripts.pory"
	playse SE_PIN
# 52 "data/maps/Kitakami_Houses/scripts.pory"
	applymovement LOCALID_KITAKAMI_STEVEN, Common_Movement_ExclamationMark
# 53 "data/maps/Kitakami_Houses/scripts.pory"
	applymovement LOCALID_KITAKAMI_STEVEN, KitakamiHouses_2_Steven_Movement_0
# 54 "data/maps/Kitakami_Houses/scripts.pory"
	waitmovement 0
# 55 "data/maps/Kitakami_Houses/scripts.pory"
	waitse
# 56 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_0
# 63 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_TEMP_10
	goto KitakamiHouses_2_Steven_8

KitakamiHouses_2_Steven_11:
# 68 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_2
# 70 "data/maps/Kitakami_Houses/scripts.pory"
	trainerbattle_no_intro TRAINER_STEVEN, KitakamiHouses_2_Steven_Text_3
# 72 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_4
# 80 "data/maps/Kitakami_Houses/scripts.pory"
	giveitem ITEM_JADE_ORB
# 81 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 82 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_2_Steven_Text_5
# 85 "data/maps/Kitakami_Houses/scripts.pory"
	waitmessage
# 86 "data/maps/Kitakami_Houses/scripts.pory"
	closemessage
# 87 "data/maps/Kitakami_Houses/scripts.pory"
	setflag FLAG_BEAT_STEVEN_KITAKAMI
# 88 "data/maps/Kitakami_Houses/scripts.pory"
	moveobjecttocoords LOCALID_KITAKAMI_STEVEN, 28, 8, DIR_SOUTH
# 89 "data/maps/Kitakami_Houses/scripts.pory"
	waitmovement LOCALID_KITAKAMI_STEVEN
# 90 "data/maps/Kitakami_Houses/scripts.pory"
	delay 15
# 91 "data/maps/Kitakami_Houses/scripts.pory"
	playse SE_EXIT
# 93 "data/maps/Kitakami_Houses/scripts.pory"
	removeobject LOCALID_KITAKAMI_STEVEN
# 94 "data/maps/Kitakami_Houses/scripts.pory"
	release
	end


PorygonPC::
# 139 "data/maps/Kitakami_Houses/scripts.pory"
	lockall
# 140 "data/maps/Kitakami_Houses/scripts.pory"
	playmoncry SPECIES_PORYGON_Z, CRY_MODE_NORMAL
# 141 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox PorygonPC_Text_0
# 143 "data/maps/Kitakami_Houses/scripts.pory"
	goto EventScript_PCMainMenu
	return


KitakamiHouses_3_Lady::
# 147 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_3_Lady_Text_0, MSGBOX_NPC
	return


KitakamiHouses_3_Man::
# 152 "data/maps/Kitakami_Houses/scripts.pory"
	msgbox KitakamiHouses_3_Man_Text_0, MSGBOX_NPC
	return


# 53 "data/maps/Kitakami_Houses/scripts.pory"
KitakamiHouses_2_Steven_Movement_0:
# 53 "data/maps/Kitakami_Houses/scripts.pory"
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

KitakamiHouses_3_Sinistea_Text_0:
# 38 "data/maps/Kitakami_Houses/scripts.pory"
	.string "SIIII!$"

KitakamiHouses_2_Steven_Text_0:
# 56 "data/maps/Kitakami_Houses/scripts.pory"
	.string "That face of determination... I assume\n"
	.string "you have become the Champion of Johto?\l"
	.string "...\l"
	.string "Impressive, I was right about your\l"
	.string "potential as a trainer. \l"
	.string "I'd be more than happy to battle you\l"
	.string "now, if you are alright with that.$"

KitakamiHouses_2_Steven_Text_1:
# 65 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Are you ready to face me?$"

KitakamiHouses_2_Steven_Text_2:
# 68 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Splendid, I'll hold nothing back\n"
	.string "and I expect you to do the same!$"

KitakamiHouses_2_Steven_Text_3:
# 70 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Outstanding, you truly have earned\n"
	.string "the title of a Champion.$"

KitakamiHouses_2_Steven_Text_4:
# 72 "data/maps/Kitakami_Houses/scripts.pory"
	.string "It cannot be overstated how happy\n"
	.string "this battle made me. You are a\l"
	.string "trainer of exceptional skill.\p"
	.string "I want you to have this as a gift\n"
	.string "of our meeting. I excavated it from\l"
	.string "nearby mountain. You might find some\l"
	.string "use for it near Route 46.$"

KitakamiHouses_2_Steven_Text_5:
# 82 "data/maps/Kitakami_Houses/scripts.pory"
	.string "I think I'll start heading out to \n"
	.string "explore new places now. I hope our \l"
	.string "paths cross again some day, {PLAYER}.$"

KitakamiHouses_2_Steven_Text_6:
# 103 "data/maps/Kitakami_Houses/scripts.pory"
	.string "If you end up becoming a Champion of\n"
	.string "the region, you should come see me.\l"
	.string "I would love to battle you with my\l"
	.string "full strength.$"

KitakamiHouses_2_Steven_Text_7:
# 112 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Oh, hello. Who might you be?\n"
	.string "...\l"
	.string "{PLAYER}? Nice to meet you.\l"
	.string "My name is Steven, I hail from the Hoenn\l"
	.string "region in search of rare stones.$"

KitakamiHouses_2_Steven_Text_8:
# 117 "data/maps/Kitakami_Houses/scripts.pory"
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
# 132 "data/maps/Kitakami_Houses/scripts.pory"
	.string "I have high expectations for you.$"

PorygonPC_Text_0:
# 141 "data/maps/Kitakami_Houses/scripts.pory"
	.string "{PLAYER} booted up the Porygon \n"
	.string "remote PC.$"

KitakamiHouses_3_Lady_Text_0:
# 147 "data/maps/Kitakami_Houses/scripts.pory"
	.string "Life is peaceful here with my family,\n"
	.string "I couldn't ask for much else.$"

KitakamiHouses_3_Man_Text_0:
# 152 "data/maps/Kitakami_Houses/scripts.pory"
	.string "This town is protected by Ogerpon, who\n"
	.string "sometimes visits this town. Personally\l"
	.string "I have never seen it, but kids say\l"
	.string "they have.$"
