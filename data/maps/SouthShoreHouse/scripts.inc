SouthShoreHouse_MapScripts::
	.byte 0


SouthShoreHouseMan::
# 4 "data/maps/SouthShoreHouse/scripts.pory"
	lock
# 5 "data/maps/SouthShoreHouse/scripts.pory"
	faceplayer
# 6 "data/maps/SouthShoreHouse/scripts.pory"
	goto_if_set FLAG_SHOWN_MIRROR, SouthShoreHouseMan_2
# 13 "data/maps/SouthShoreHouse/scripts.pory"
	msgbox SouthShoreHouseMan_Text_1
# 24 "data/maps/SouthShoreHouse/scripts.pory"
	checkitem ITEM_BLACK_MIRROR
# 25 "data/maps/SouthShoreHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SouthShoreHouseMan_5
# 49 "data/maps/SouthShoreHouse/scripts.pory"
	release
	end

SouthShoreHouseMan_2:
# 7 "data/maps/SouthShoreHouse/scripts.pory"
	msgbox SouthShoreHouseMan_Text_0
# 10 "data/maps/SouthShoreHouse/scripts.pory"
	release
	end

SouthShoreHouseMan_5:
# 26 "data/maps/SouthShoreHouse/scripts.pory"
	goto_if_unset FLAG_SHOWN_MIRROR, SouthShoreHouseMan_7
# 41 "data/maps/SouthShoreHouse/scripts.pory"
	msgbox SouthShoreHouseMan_Text_0
# 44 "data/maps/SouthShoreHouse/scripts.pory"
	release
	end

SouthShoreHouseMan_7:
# 27 "data/maps/SouthShoreHouse/scripts.pory"
	msgbox SouthShoreHouseMan_Text_2
# 37 "data/maps/SouthShoreHouse/scripts.pory"
	setflag FLAG_SHOWN_MIRROR
# 38 "data/maps/SouthShoreHouse/scripts.pory"
	release
	end


SouthShoreHouseSableye::
# 54 "data/maps/SouthShoreHouse/scripts.pory"
	lock
# 55 "data/maps/SouthShoreHouse/scripts.pory"
	faceplayer
# 56 "data/maps/SouthShoreHouse/scripts.pory"
	playmoncry SPECIES_SABLEYE, CRY_MODE_NORMAL
# 57 "data/maps/SouthShoreHouse/scripts.pory"
	msgbox SouthShoreHouseSableye_Text_0
# 58 "data/maps/SouthShoreHouse/scripts.pory"
	waitmoncry
# 59 "data/maps/SouthShoreHouse/scripts.pory"
	release
	end


SouthShoreHouseMan_Text_0:
# 7 "data/maps/SouthShoreHouse/scripts.pory"
	.string "You must follow the ravens with the\n"
	.string "mirror in hand to find the lair of the\l"
	.string "beast.$"

SouthShoreHouseMan_Text_1:
# 13 "data/maps/SouthShoreHouse/scripts.pory"
	.string "My grandparent always used to tell\n"
	.string "stories of a beast hiding in the\l"
	.string "depths of the forest.\p"
	.string "No normal person could ever hope to \n"
	.string "find it no matter how hard they looked,\l"
	.string "for it lived on a path that could only\l"
	.string "be revealed by a mirror that does not\l"
	.string "reflect its owner.\p"
	.string "I wonder if such object even exists.$"

SouthShoreHouseMan_Text_2:
# 27 "data/maps/SouthShoreHouse/scripts.pory"
	.string "Oh! That object you hold! That looks\n"
	.string "exactly like the item my grandpa\l"
	.string "described to me!\p"
	.string "To think that the stories were true.\p"
	.string "He told me that the path can be\n"
	.string "found by following the ravens. \p"
	.string "Best of luck finding the beast, trainer.$"

SouthShoreHouseSableye_Text_0:
# 57 "data/maps/SouthShoreHouse/scripts.pory"
	.string "Sableye: Sablblbllblb!$"
