SnowtopMountainOutside_MapScripts::
# 2 "data/maps/SnowtopMountainOutside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SnowtopMountainOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SnowtopMountainOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SnowtopMountainOutside/scripts.pory"
	setflag FLAG_VISITED_SNOWTOP_MOUNTAIN
	end


SnowtopMountainOutside_Snover::
# 9 "data/maps/SnowtopMountainOutside/scripts.pory"
	lock
# 10 "data/maps/SnowtopMountainOutside/scripts.pory"
	faceplayer
# 11 "data/maps/SnowtopMountainOutside/scripts.pory"
	playmoncry SPECIES_SNOVER, CRY_MODE_NORMAL
# 12 "data/maps/SnowtopMountainOutside/scripts.pory"
	msgbox SnowtopMountainOutside_Snover_Text_0
# 13 "data/maps/SnowtopMountainOutside/scripts.pory"
	waitmoncry
# 14 "data/maps/SnowtopMountainOutside/scripts.pory"
	release
	end


SnowtopMountainOutside_Articuno::
# 19 "data/maps/SnowtopMountainOutside/scripts.pory"
	lock
# 20 "data/maps/SnowtopMountainOutside/scripts.pory"
	faceplayer
# 21 "data/maps/SnowtopMountainOutside/scripts.pory"
	legendaryencounter SPECIES_ARTICUNO, 50, 1, FLAG_HIDE_ARTICUNO
# 22 "data/maps/SnowtopMountainOutside/scripts.pory"
	release
	end


SnowtopMountainOutside_Sign::
# 27 "data/maps/SnowtopMountainOutside/scripts.pory"
	msgbox SnowtopMountainOutside_Sign_Text_0, MSGBOX_SIGN
	return


SnowtopMountainOutside_Snover_Text_0:
# 12 "data/maps/SnowtopMountainOutside/scripts.pory"
	.string "Snover: Snoo!$"

SnowtopMountainOutside_Sign_Text_0:
# 27 "data/maps/SnowtopMountainOutside/scripts.pory"
	.string "Snowtop Mountain\n"
	.string "Chilling temperatures ahead!$"
