SnowtopMountainOutside_MapScripts::
	.byte 0


SnowtopMountainOutside_Snover::
# 4 "data/maps/SnowtopMountainOutside/scripts.pory"
	lock
# 5 "data/maps/SnowtopMountainOutside/scripts.pory"
	faceplayer
# 6 "data/maps/SnowtopMountainOutside/scripts.pory"
	playmoncry SPECIES_SNOVER, CRY_MODE_NORMAL
# 7 "data/maps/SnowtopMountainOutside/scripts.pory"
	msgbox SnowtopMountainOutside_Snover_Text_0
# 8 "data/maps/SnowtopMountainOutside/scripts.pory"
	waitmoncry
# 9 "data/maps/SnowtopMountainOutside/scripts.pory"
	release
	end


SnowtopMountainOutside_Articuno::
# 14 "data/maps/SnowtopMountainOutside/scripts.pory"
	lock
# 15 "data/maps/SnowtopMountainOutside/scripts.pory"
	faceplayer
# 16 "data/maps/SnowtopMountainOutside/scripts.pory"
	legendaryencounter SPECIES_ARTICUNO, 50, 1, FLAG_HIDE_ARTICUNO
# 17 "data/maps/SnowtopMountainOutside/scripts.pory"
	release
	end


SnowtopMountainOutside_Sign::
# 22 "data/maps/SnowtopMountainOutside/scripts.pory"
	msgbox SnowtopMountainOutside_Sign_Text_0, MSGBOX_SIGN
	return


SnowtopMountainOutside_Snover_Text_0:
# 7 "data/maps/SnowtopMountainOutside/scripts.pory"
	.string "Snover: Snoo!$"

SnowtopMountainOutside_Sign_Text_0:
# 22 "data/maps/SnowtopMountainOutside/scripts.pory"
	.string "Snowtop Mountain\n"
	.string "Chilling temperatures ahead!$"
