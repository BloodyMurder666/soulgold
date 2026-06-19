Route49_MapScripts::
	.byte 0


Route49_Desert_Sign::
# 4 "data/maps/Route49/scripts.pory"
	msgbox Route49_Desert_Sign_Text_0, MSGBOX_SIGN
	return


Route49_RoadSign::
# 9 "data/maps/Route49/scripts.pory"
	msgbox Route49_RoadSign_Text_0, MSGBOX_SIGN
	return


Route49_FisherJo::
# 14 "data/maps/Route49/scripts.pory"
	trainerbattle_single TRAINER_JO, Route49_FisherJo_Text_0, Route49_FisherJo_Text_1
# 17 "data/maps/Route49/scripts.pory"
	msgbox Route49_FisherJo_Text_2, MSGBOX_AUTOCLOSE
	return


Route49_Girl::
# 24 "data/maps/Route49/scripts.pory"
	msgbox Route49_Girl_Text_0, MSGBOX_NPC
	return


Route49_Stantler::
# 29 "data/maps/Route49/scripts.pory"
	lock
# 30 "data/maps/Route49/scripts.pory"
	faceplayer
# 31 "data/maps/Route49/scripts.pory"
	playmoncry SPECIES_STANTLER, CRY_MODE_NORMAL
# 32 "data/maps/Route49/scripts.pory"
	msgbox Route49_Stantler_Text_0
# 33 "data/maps/Route49/scripts.pory"
	waitmoncry
# 34 "data/maps/Route49/scripts.pory"
	release
	end


Route49_CooltrainerEma::
# 39 "data/maps/Route49/scripts.pory"
	trainerbattle_single TRAINER_EMA, Route49_CooltrainerEma_Text_0, Route49_CooltrainerEma_Text_1
# 42 "data/maps/Route49/scripts.pory"
	msgbox Route49_CooltrainerEma_Text_2, MSGBOX_AUTOCLOSE
	return


Route49_Fatman::
# 48 "data/maps/Route49/scripts.pory"
	msgbox Route49_Fatman_Text_0, MSGBOX_NPC
	return


Route49_Hiker::
# 54 "data/maps/Route49/scripts.pory"
	msgbox Route49_Hiker_Text_0, MSGBOX_NPC
	return


Route49_Desert_Sign_Text_0:
# 4 "data/maps/Route49/scripts.pory"
	.string "{RIGHT_ARROW} Vajra Desert\n"
	.string "{UP_ARROW} Snowtop Mountain$"

Route49_RoadSign_Text_0:
# 9 "data/maps/Route49/scripts.pory"
	.string "Route 49\n"
	.string "The road to harsher climates.$"

Route49_FisherJo_Text_0:
# 14 "data/maps/Route49/scripts.pory"
	.string "This is my secret fishing spot, check \n"
	.string "out what I just caught!$"

Route49_FisherJo_Text_1:
# 16 "data/maps/Route49/scripts.pory"
	.string "Wait, how many badges do you have?$"

Route49_FisherJo_Text_2:
# 17 "data/maps/Route49/scripts.pory"
	.string "I bring my daughter along when I go\n"
	.string "fishing so we can get some family time.\l"
	.string "I'm glad she has her Stantler to play\l"
	.string "with her.$"

Route49_Girl_Text_0:
# 24 "data/maps/Route49/scripts.pory"
	.string "Stantler and I like to climb around\n"
	.string "while Papa is fishing.$"

Route49_Stantler_Text_0:
# 32 "data/maps/Route49/scripts.pory"
	.string "Stantler: Staaaaa!$"

Route49_CooltrainerEma_Text_0:
# 39 "data/maps/Route49/scripts.pory"
	.string "I will check if you are prepared for\n"
	.string "the harsher environments ahead!$"

Route49_CooltrainerEma_Text_1:
# 41 "data/maps/Route49/scripts.pory"
	.string "You shall pass!$"

Route49_CooltrainerEma_Text_2:
# 42 "data/maps/Route49/scripts.pory"
	.string "Whether it's the desert or the Snowtop\n"
	.string "Mountain, both will test your skills as\l"
	.string "a trainer.$"

Route49_Fatman_Text_0:
# 48 "data/maps/Route49/scripts.pory"
	.string "The cold snow from the mountains melts\n"
	.string "and flows down here. It's really\l"
	.string "clear!$"

Route49_Hiker_Text_0:
# 54 "data/maps/Route49/scripts.pory"
	.string "They call this The Thousand Steps. At\n"
	.string "the top you will arrive at the base\l"
	.string "of Snowtop Mountain.\p"
	.string "Rumours have been circulating that\n"
	.string "a majestic blue bird has been sighted\l"
	.string "flying around the mountain.$"
