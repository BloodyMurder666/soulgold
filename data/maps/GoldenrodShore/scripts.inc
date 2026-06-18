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
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_SAMUEL
	goto_if 1, GoldenrodShore_Expert_7
GoldenrodShore_Expert_4:
# 37 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_Expert_2:
# 7 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_0
# 10 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_Expert_5:
# 21 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_2
# 24 "data/maps/GoldenrodShore/scripts.pory"
	trainerbattle_no_intro TRAINER_GOLDENROD_SHORE_EXPERT, GoldenrodShore_Expert_Text_3
# 25 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_4
# 29 "data/maps/GoldenrodShore/scripts.pory"
	giveitem ITEM_LOADED_DICE
# 30 "data/maps/GoldenrodShore/scripts.pory"
	setflag FLAG_GOLDENRODSHORE_EXPERT
# 31 "data/maps/GoldenrodShore/scripts.pory"
	addvar VAR_ROUTE_EXPERTS_DEFEATED, 1
# 32 "data/maps/GoldenrodShore/scripts.pory"
	special Achievement_CheckAll
# 33 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Expert_Text_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_6:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_TODD
	goto_if 1, GoldenrodShore_Expert_11
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_7:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BRANDON
	goto_if 1, GoldenrodShore_Expert_6
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_10:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_GINA
	goto_if 1, GoldenrodShore_Expert_15
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_11:
# 18 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IAN
	goto_if 1, GoldenrodShore_Expert_10
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_14:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ELLIOT
	goto_if 1, GoldenrodShore_Expert_19
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_15:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_KIM
	goto_if 1, GoldenrodShore_Expert_14
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_18:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IVAN
	goto_if 1, GoldenrodShore_Expert_23
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_19:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BROOKE
	goto_if 1, GoldenrodShore_Expert_18
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_22:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_WALT
	goto_if 1, GoldenrodShore_Expert_27
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_23:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_IRWIN
	goto_if 1, GoldenrodShore_Expert_22
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_26:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_BRYAN
	goto_if 1, GoldenrodShore_Expert_31
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_27:
# 19 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ARNIE
	goto_if 1, GoldenrodShore_Expert_26
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_30:
# 20 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_ALAN
	goto_if 1, GoldenrodShore_Expert_5
	goto GoldenrodShore_Expert_4

GoldenrodShore_Expert_31:
# 20 "data/maps/GoldenrodShore/scripts.pory"
	checktrainerflag TRAINER_MARK
	goto_if 1, GoldenrodShore_Expert_30
	goto GoldenrodShore_Expert_4


GoldenrodShore_Sign::
# 42 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Sign_Text_0, MSGBOX_SIGN
	return


GoldenrodShore_Engineer::
# 46 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_Engineer_Text_0, MSGBOX_NPC
	return


GoldenrodShore_HiddenGrotto::
# 52 "data/maps/GoldenrodShore/scripts.pory"
	msgbox GoldenrodShore_HiddenGrotto_Text_0, MSGBOX_YESNO
# 54 "data/maps/GoldenrodShore/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq GoldenrodShore_HiddenGrotto_2
GoldenrodShore_HiddenGrotto_1:
# 58 "data/maps/GoldenrodShore/scripts.pory"
	release
	end

GoldenrodShore_HiddenGrotto_2:
# 55 "data/maps/GoldenrodShore/scripts.pory"
	warp MAP_HIDDEN_GROTTO_GOLDENROD_SHORE, 0
# 56 "data/maps/GoldenrodShore/scripts.pory"
	waitstate
	goto GoldenrodShore_HiddenGrotto_1


MareaniesGoldenrodShore::
# 63 "data/maps/GoldenrodShore/scripts.pory"
	msgbox MareaniesGoldenrodShore_Text_0, MSGBOX_NPC
	return


GoldenrodShore_Expert_Text_0:
# 7 "data/maps/GoldenrodShore/scripts.pory"
	.string "Guess I'm free to go home now\n"
	.string "that I no longer have to maintain\l"
	.string "this route expert title.$"

GoldenrodShore_Expert_Text_1:
# 13 "data/maps/GoldenrodShore/scripts.pory"
	.string "Hi! I'm the route expert of local area!\p"
	.string "If you can beat every trainer on routes\n"
	.string "34, 35 and 36. Come have a battle with\l"
	.string "me.$"

GoldenrodShore_Expert_Text_2:
# 21 "data/maps/GoldenrodShore/scripts.pory"
	.string "I've heard the words of your victories.\n"
	.string "Let's have a battle then, I'll show\l"
	.string "you a new type of strategy!$"

GoldenrodShore_Expert_Text_3:
# 24 "data/maps/GoldenrodShore/scripts.pory"
	.string "Outsmarted!$"

GoldenrodShore_Expert_Text_4:
# 25 "data/maps/GoldenrodShore/scripts.pory"
	.string "Even against my unrelenting tide\n"
	.string "of attacks, you prevailed. Please,\l"
	.string "have this item to boost your odds\l"
	.string "of keeping up the winning streak.$"

GoldenrodShore_Expert_Text_5:
# 33 "data/maps/GoldenrodShore/scripts.pory"
	.string "Loaded Dice boosts the minimum hit \n"
	.string "count of multi-hit moves, you should \l"
	.string "try it with moves like Bullet Seed!$"

GoldenrodShore_Sign_Text_0:
# 42 "data/maps/GoldenrodShore/scripts.pory"
	.string "Goldenrod Shore, no littering!$"

GoldenrodShore_Engineer_Text_0:
# 46 "data/maps/GoldenrodShore/scripts.pory"
	.string "Alright, time to start digging a path \n"
	.string "here. The Pokéathlon construction\l"
	.string "starts here!$"

GoldenrodShore_HiddenGrotto_Text_0:
# 52 "data/maps/GoldenrodShore/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"

MareaniesGoldenrodShore_Text_0:
# 63 "data/maps/GoldenrodShore/scripts.pory"
	.string "Mareanies seem to be blocking the way. \n"
	.string "Perhaps there is another way to Olivine?$"
