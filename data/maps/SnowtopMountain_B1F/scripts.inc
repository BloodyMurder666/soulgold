SnowtopMountain_B1F_MapScripts::
# 2 "data/maps/SnowtopMountain_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/SnowtopMountain_B1F/scripts.pory"
	goto_if_set FLAG_SNOWTOP_REGICE_DOOR, SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SnowtopMountain_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/SnowtopMountain_B1F/scripts.pory"
	setmetatile 5, 36, 0x414, FALSE
# 5 "data/maps/SnowtopMountain_B1F/scripts.pory"
	setmetatile 5, 35, 0x40C, FALSE
	return


# 10 "data/maps/SnowtopMountain_B1F/scripts.pory"

# 11 "data/maps/SnowtopMountain_B1F/scripts.pory"
Snowtopmountain_BrailleRegice:
# 12 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.braille "TYRANT OF\n"
# 13 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.braille "THE SNOW\n"
# 14 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.braille "FULLY EVOLVED.$"

B1F_Snowtopmountain_Bearnese::
# 18 "data/maps/SnowtopMountain_B1F/scripts.pory"
	trainerbattle_single TRAINER_BEARNESE, B1F_Snowtopmountain_Bearnese_Text_0, B1F_Snowtopmountain_Bearnese_Text_1
# 21 "data/maps/SnowtopMountain_B1F/scripts.pory"
	msgbox B1F_Snowtopmountain_Bearnese_Text_2, MSGBOX_AUTOCLOSE
	return


B1F_Snowtopmountain_Susdoor::
# 27 "data/maps/SnowtopMountain_B1F/scripts.pory"
	lock
# 28 "data/maps/SnowtopMountain_B1F/scripts.pory"
	msgbox B1F_Snowtopmountain_Susdoor_Text_0
# 29 "data/maps/SnowtopMountain_B1F/scripts.pory"
	closemessage
# 30 "data/maps/SnowtopMountain_B1F/scripts.pory"
	braillemsgbox Snowtopmountain_BrailleRegice
# 31 "data/maps/SnowtopMountain_B1F/scripts.pory"
	checkspecies SPECIES_BAXCALIBUR
# 32 "data/maps/SnowtopMountain_B1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq B1F_Snowtopmountain_Susdoor_2
B1F_Snowtopmountain_Susdoor_1:
# 39 "data/maps/SnowtopMountain_B1F/scripts.pory"
	release
	end

B1F_Snowtopmountain_Susdoor_2:
# 33 "data/maps/SnowtopMountain_B1F/scripts.pory"
	setflag FLAG_SNOWTOP_REGICE_DOOR
# 34 "data/maps/SnowtopMountain_B1F/scripts.pory"
	setmetatile 5, 36, 0x414, FALSE
# 35 "data/maps/SnowtopMountain_B1F/scripts.pory"
	setmetatile 5, 35, 0x40C, FALSE
# 36 "data/maps/SnowtopMountain_B1F/scripts.pory"
	playse SE_EXIT
# 37 "data/maps/SnowtopMountain_B1F/scripts.pory"
	special DrawWholeMapView
	goto B1F_Snowtopmountain_Susdoor_1


B1F_Snowtopmountain_Bearnese_Text_0:
# 18 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.string "Check it out, my breath is forming\n"
	.string "icicles!$"

B1F_Snowtopmountain_Bearnese_Text_1:
# 20 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.string "Feeling kind of chilly here.$"

B1F_Snowtopmountain_Bearnese_Text_2:
# 21 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.string "They say an ancient ice Pokémon sleeps\n"
	.string "somewhere inside the mountain. I\l"
	.string "wonder where it could be?$"

B1F_Snowtopmountain_Susdoor_Text_0:
# 28 "data/maps/SnowtopMountain_B1F/scripts.pory"
	.string "Something is carved on the wall...$"
