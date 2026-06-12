RailwayCave_2F_MapScripts::
# 2 "data/maps/RailwayCave_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/RailwayCave_2F/scripts.pory"
	goto_if_set FLAG_SUS_RAILWAY_DOOR, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 10, 0x45A, FALSE
# 5 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 9, 0x452, FALSE
	return


# 10 "data/maps/RailwayCave_2F/scripts.pory"

# 11 "data/maps/RailwayCave_2F/scripts.pory"
RailwayCave_BrailleRegisteel:
# 12 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "THE ONE WHO\n"
# 13 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "CLANGS THE\n"
# 14 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "SCALES.$"

RailwayCave_SusDoor::
# 18 "data/maps/RailwayCave_2F/scripts.pory"
	lock
# 19 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_SusDoor_Text_0
# 20 "data/maps/RailwayCave_2F/scripts.pory"
	closemessage
# 21 "data/maps/RailwayCave_2F/scripts.pory"
	braillemsgbox RailwayCave_BrailleRegisteel
# 22 "data/maps/RailwayCave_2F/scripts.pory"
	checkspecies SPECIES_KOMMO_O
# 23 "data/maps/RailwayCave_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RailwayCave_SusDoor_2
RailwayCave_SusDoor_1:
# 30 "data/maps/RailwayCave_2F/scripts.pory"
	release
	end

RailwayCave_SusDoor_2:
# 24 "data/maps/RailwayCave_2F/scripts.pory"
	setflag FLAG_SUS_RAILWAY_DOOR
# 25 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 10, 0x45A, FALSE
# 26 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 9, 0x452, FALSE
# 27 "data/maps/RailwayCave_2F/scripts.pory"
	playse SE_EXIT
# 28 "data/maps/RailwayCave_2F/scripts.pory"
	special DrawWholeMapView
	goto RailwayCave_SusDoor_1


RailwayCave_TrainerBob::
# 35 "data/maps/RailwayCave_2F/scripts.pory"
	trainerbattle_single TRAINER_RAILWAYBOB, RailwayCave_TrainerBob_Text_0, RailwayCave_TrainerBob_Text_1
# 39 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_TrainerBob_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerMason::
# 46 "data/maps/RailwayCave_2F/scripts.pory"
	trainerbattle_single TRAINER_RAILWAYMASON, RailwayCave_TrainerMason_Text_0, RailwayCave_TrainerMason_Text_1
# 48 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_TrainerMason_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerYoda::
# 54 "data/maps/RailwayCave_2F/scripts.pory"
	trainerbattle_single TRAINER_RAILWAYYODA, RailwayCave_TrainerYoda_Text_0, RailwayCave_TrainerYoda_Text_1
# 57 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_TrainerYoda_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_TrainerSanada::
# 63 "data/maps/RailwayCave_2F/scripts.pory"
	trainerbattle_single TRAINER_RAILWAYSANADA, RailwayCave_TrainerSanada_Text_0, RailwayCave_TrainerSanada_Text_1
# 66 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_TrainerSanada_Text_2, MSGBOX_AUTOCLOSE
	return


RailwayCave_SusDoor_Text_0:
# 19 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Something is carven on the door...$"

RailwayCave_TrainerBob_Text_0:
# 35 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Did you know? Digletts and Dugtrios\n"
	.string "helped us dig these tunnels.$"

RailwayCave_TrainerBob_Text_1:
# 37 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Did you know? It still took many years\n"
	.string "to complete!$"

RailwayCave_TrainerBob_Text_2:
# 39 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Did you know? This crag is much harder\n"
	.string "than the average mountain rock. \l"
	.string "It has a lot of metal mixed into it, \l"
	.string "making digging take more time.$"

RailwayCave_TrainerMason_Text_0:
# 46 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Ow! Something latched onto my foot!$"

RailwayCave_TrainerMason_Text_1:
# 47 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Oh, it was only my Stunfisk!$"

RailwayCave_TrainerMason_Text_2:
# 48 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Stunfisk like to burrow into the ground\n"
	.string "here. They seem to enjoy the\l"
	.string "atmosphere.$"

RailwayCave_TrainerYoda_Text_0:
# 54 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Hya! The electricity running though the\n"
	.string "air is great for my muscles$"

RailwayCave_TrainerYoda_Text_1:
# 56 "data/maps/RailwayCave_2F/scripts.pory"
	.string "We must keep training!$"

RailwayCave_TrainerYoda_Text_2:
# 57 "data/maps/RailwayCave_2F/scripts.pory"
	.string "The jolts of electricity that run here\n"
	.string "are great for relaxing the muscles\l"
	.string "after a long workout!$"

RailwayCave_TrainerSanada_Text_0:
# 63 "data/maps/RailwayCave_2F/scripts.pory"
	.string "This is the maintenance tunnel for\n"
	.string "the train tracks, how did you get in?$"

RailwayCave_TrainerSanada_Text_1:
# 65 "data/maps/RailwayCave_2F/scripts.pory"
	.string "I'm reporting this to my superiors!$"

RailwayCave_TrainerSanada_Text_2:
# 66 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Just because you can run into\n"
	.string "any place you want with your Pokémon\l"
	.string "doesn't mean you should!$"
