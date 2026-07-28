Route50_MapScripts::
	.byte 0


Route50_TrainerRowan::
# 4 "data/maps/Route50/scripts.pory"
	trainerbattle_single TRAINER_ROUTE50_ROWAN, Route50_TrainerRowan_Text_0, Route50_TrainerRowan_Text_1
# 7 "data/maps/Route50/scripts.pory"
	msgbox Route50_TrainerRowan_Text_2, MSGBOX_AUTOCLOSE
	end


Route50_TrainerCaspian::
# 13 "data/maps/Route50/scripts.pory"
	trainerbattle_double TRAINER_ROUTE50_CASPIAN, Route50_TrainerCaspian_Text_0, Route50_TrainerCaspian_Text_1, Route50_TrainerCaspian_Text_2
# 15 "data/maps/Route50/scripts.pory"
	msgbox Route50_TrainerCaspian_Text_3, MSGBOX_AUTOCLOSE
	end


Route50_TrainerIgnis::
# 22 "data/maps/Route50/scripts.pory"
	trainerbattle_single TRAINER_ROUTE50_IGNIS, Route50_TrainerIgnis_Text_0, Route50_TrainerIgnis_Text_1
# 24 "data/maps/Route50/scripts.pory"
	msgbox Route50_TrainerIgnis_Text_2, MSGBOX_AUTOCLOSE
	end


Route50_Virizion::
# 30 "data/maps/Route50/scripts.pory"
	lock
# 31 "data/maps/Route50/scripts.pory"
	faceplayer
# 32 "data/maps/Route50/scripts.pory"
	bosslegendaryencounter SPECIES_VIRIZION, 80, LOCALID_VIRIZION, FLAG_HIDE_VIRIZION, 2, SPECIES_NONE, 110
# 33 "data/maps/Route50/scripts.pory"
	release
	end


Route50_ObservingWoman::
# 38 "data/maps/Route50/scripts.pory"
	lock
# 39 "data/maps/Route50/scripts.pory"
	goto_if_unset FLAG_HIDE_VIRIZION, Route50_ObservingWoman_2
# 45 "data/maps/Route50/scripts.pory"
	msgbox Route50_ObservingWoman_Text_1
# 46 "data/maps/Route50/scripts.pory"
	release
	end

Route50_ObservingWoman_2:
# 40 "data/maps/Route50/scripts.pory"
	msgbox Route50_ObservingWoman_Text_0
# 42 "data/maps/Route50/scripts.pory"
	release
	end


Route50_TrainerRowan_Text_0:
# 4 "data/maps/Route50/scripts.pory"
	.string "Let's see if you still got energy left\n"
	.string "to face me!$"

Route50_TrainerRowan_Text_1:
# 6 "data/maps/Route50/scripts.pory"
	.string "You never lost your footing!$"

Route50_TrainerRowan_Text_2:
# 7 "data/maps/Route50/scripts.pory"
	.string "Lake of Rage ain't far away. The climate\n"
	.string "can change rapidly around here.$"

Route50_TrainerCaspian_Text_0:
# 13 "data/maps/Route50/scripts.pory"
	.string "I'm doing a tour of all the routes!$"

Route50_TrainerCaspian_Text_1:
# 13 "data/maps/Route50/scripts.pory"
	.string "You might be the strongest trainer so\n"
	.string "far.$"

Route50_TrainerCaspian_Text_2:
# 14 "data/maps/Route50/scripts.pory"
	.string "Bring two Pokémon ready to battle!$"

Route50_TrainerCaspian_Text_3:
# 15 "data/maps/Route50/scripts.pory"
	.string "Have you been making use of the \n"
	.string "weather? It can turn the tide of\l"
	.string "battle in a flash.$"

Route50_TrainerIgnis_Text_0:
# 22 "data/maps/Route50/scripts.pory"
	.string "This place is perfect for practicing\n"
	.string "firebreathing!$"

Route50_TrainerIgnis_Text_1:
# 23 "data/maps/Route50/scripts.pory"
	.string "No! My flames!$"

Route50_TrainerIgnis_Text_2:
# 24 "data/maps/Route50/scripts.pory"
	.string "Can't accidentally set anything on fire \n"
	.string "here.$"

Route50_ObservingWoman_Text_0:
# 40 "data/maps/Route50/scripts.pory"
	.string "What kind of Pokémon is that thing\n"
	.string "over there?$"

Route50_ObservingWoman_Text_1:
# 45 "data/maps/Route50/scripts.pory"
	.string "Oh you caught that thing! Nice going!$"
