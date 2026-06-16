GoldenrodShore_MapScripts::
	.byte 0


GoldenrodShore_Expert::
# 4 "data/maps/GoldenrodShore/scripts.pory"
	lock
# 5 "data/maps/GoldenrodShore/scripts.pory"
	faceplayer
# 6 "data/maps/GoldenrodShore/scripts.pory"
	goto_if_set FLAG_GOLDENRODSHORE_EXPERT, GoldenrodShore_Expert_2
# 13 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_1
# 17 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_SAMUEL
	goto_if 1, GoldenrodShore_Expert_7
GoldenrodShore_Expert_4:
# 36 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_Expert_2:
# 7 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_0
# 10 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_Expert_5:
# 20 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_2
# 23 "data/maps/GoldenrodShore/scripts.pory"
	trainerbattle_no_intro TRAINER_GOLDENROD_SHORE_EXPERT, GoldenrodShore_Expert_Text_3
# 24 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_4
# 28 "data/maps/GoldenrodShore/scripts.pory"
	giveitem ITEM_LOADED_DICE
# 29 "data/maps/GoldenrodShore/scripts.pory"
	setflag FLAG_GOLDENRODSHORE_EXPERT
# 30 "data/maps/GoldenrodShore/scripts.pory"
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
# 31 "data/maps/GoldenrodShore/scripts.pory"
	special Achievement_CheckAll
# 32 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_6:
# 17 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_TODD
	goto_if 1, GoldenrodShore_Expert_11
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_7:
# 17 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BRANDON
	goto_if 1, GoldenrodShore_Expert_6
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_10:
# 17 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_GINA
	goto_if 1, GoldenrodShore_Expert_15
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_11:
# 17 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IAN
	goto_if 1, GoldenrodShore_Expert_10
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_14:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ELLIOT
	goto_if 1, GoldenrodShore_Expert_19
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_15:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_KIM
	goto_if 1, GoldenrodShore_Expert_14
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_18:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IVAN
	goto_if 1, GoldenrodShore_Expert_23
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_19:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BROOKE
	goto_if 1, GoldenrodShore_Expert_18
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_22:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_WALT
	goto_if 1, GoldenrodShore_Expert_27
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_23:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IRWIN
	goto_if 1, GoldenrodShore_Expert_22
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_26:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BRYAN
	goto_if 1, GoldenrodShore_Expert_31
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_27:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ARNIE
	goto_if 1, GoldenrodShore_Expert_26
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_30:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ALAN
	goto_if 1, GoldenrodShore_Expert_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_31:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_MARK
	goto_if 1, GoldenrodShore_Expert_30
	goto GoldenrodShore_Expert_4


GoldenrodShore_Sign::
# 41 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Sign_Text_0, MSGBOX_SIGN
	return


GoldenrodShore_Engineer::
# 45 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Engineer_Text_0, MSGBOX_NPC
	return


GoldenrodShore_HiddenGrotto::
# 51 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_HiddenGrotto_Text_0, MSGBOX_YESNO
# 53 "data/maps/GoldenrodShore/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodShore_HiddenGrotto_2
GoldenrodShore_HiddenGrotto_1:
# 57 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_HiddenGrotto_2:
# 54 "data/maps/GoldenrodShore/scripts.pory"
	warp MAP_HIDDEN_GROTTO_GOLDENROD_SHORE, 0
# 55 "data/maps/GoldenrodShore/scripts.pory"
	waitstate
	goto GoldenrodShore_HiddenGrotto_1


MareaniesGoldenrodShore::
# 62 "data/maps/GoldenrodShore/scripts.pory"
	msgbox MareaniesGoldenrodShore_Text_0, MSGBOX_NPC
	return


GoldenrodShore_Expert_Text_0:
# 7 "data/maps/GoldenrodShore/scripts.pory"
	.string "Guess I'm free to go home now\n"
	.string "that I no longer have to maintain\l"
	.string "this route expert title.$"

GoldenrodShore_Expert_Text_1:
# 13 "data/maps/GoldenrodShore/scripts.pory"
	.string "Hi! I'm the route expert of local area!\n"
	.string "If you can beat every trainer on routes\l"
	.string "34, 35 and 36. Come have a battle with\l"
	.string "me.$"

GoldenrodShore_Expert_Text_2:
# 20 "data/maps/GoldenrodShore/scripts.pory"
	.string "I've heard the words of your victories.\n"
	.string "Let's have a battle then, I'll show\l"
	.string "you a new type of strategy!$"

GoldenrodShore_Expert_Text_3:
# 23 "data/maps/GoldenrodShore/scripts.pory"
	.string "Outsmarted!$"

GoldenrodShore_Expert_Text_4:
# 24 "data/maps/GoldenrodShore/scripts.pory"
	.string "Even against my unrelenting tide\n"
	.string "of attacks, you prevailed. Please,\l"
	.string "have this item to boost your odds\l"
	.string "of keeping up the winning streak.$"

GoldenrodShore_Expert_Text_5:
# 32 "data/maps/GoldenrodShore/scripts.pory"
	.string "Loaded Dice boosts the minimum hit \n"
	.string "count of multi-hit moves, you should \l"
	.string "try it with moves like Bullet Seed!$"

GoldenrodShore_Sign_Text_0:
# 41 "data/maps/GoldenrodShore/scripts.pory"
	.string "Goldenrod Shore, no littering!$"

GoldenrodShore_Engineer_Text_0:
# 45 "data/maps/GoldenrodShore/scripts.pory"
	.string "Alright, time to start digging a path \n"
	.string "here. The Pokéathlon construction\l"
	.string "starts here!$"

GoldenrodShore_HiddenGrotto_Text_0:
# 51 "data/maps/GoldenrodShore/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

MareaniesGoldenrodShore_Text_0:
# 62 "data/maps/GoldenrodShore/scripts.pory"
	.string "Mareanies seem to be blocking the way. \n"
	.string "Perhaps there is another way to Olivine?$"
