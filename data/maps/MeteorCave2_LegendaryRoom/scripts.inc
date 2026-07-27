MeteorCave2_LegendaryRoom_MapScripts::
# 2 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_LEAVESDOOR, MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_2
MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 10 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_BOULDERDOOR, MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_5
MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 17 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_CROWNDOOR, MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_7
	return

MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 5, 35, 5, 29, 0x482, TRUE
# 5 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 6, 35, 6, 29, 0x498
# 6 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 7, 35, 7, 29, 0x486
# 7 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 8, 35, 8, 29, 0x49A
# 8 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 9, 34, 9, 29, 0x480, TRUE
	goto MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1

MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_5:
# 11 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 17, 34, 17, 29, 0x482, TRUE
# 12 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 18, 35, 18, 29, 0x498
# 13 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 19, 35, 19, 29, 0x486
# 14 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 20, 35, 20, 29, 0x49A
# 15 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 21, 34, 21, 29, 0x480, TRUE
	goto MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_4

MeteorCave2_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 18 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 29, 34, 29, 29, 0x482, TRUE
# 19 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 30, 35, 30, 29, 0x498
# 20 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 31, 35, 31, 29, 0x486
# 21 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 32, 35, 32, 29, 0x49A
# 22 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 33, 34, 33, 29, 0x480, TRUE
	return


MeteorCave1_LegendaryRoom_IronLeavesDoor::
# 28 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 29 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_LEAVESDOOR, MeteorCave1_LegendaryRoom_IronLeavesDoor_2
# 34 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_1
# 37 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_VIRIZION
# 38 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_IronLeavesDoor_5
# 44 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	closemessage
# 45 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 46 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 5, 35, 5, 29, 0x482, TRUE
# 47 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 6, 35, 6, 29, 0x498
# 48 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 7, 35, 7, 29, 0x486
# 49 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 8, 35, 8, 29, 0x49A
# 50 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 9, 34, 9, 29, 0x480, TRUE
# 51 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 52 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setflag FLAG_LEAVESDOOR
# 53 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	waitse
# 54 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	return

MeteorCave1_LegendaryRoom_IronLeavesDoor_2:
# 30 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_0
# 31 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_IronLeavesDoor_5:
# 39 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	delay 30
# 40 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_2
# 41 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_IronBoulderDoor::
# 58 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 59 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_BOULDERDOOR, MeteorCave1_LegendaryRoom_IronBoulderDoor_2
# 64 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronBoulderDoor_Text_0
# 67 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_TERRAKION
# 68 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_IronBoulderDoor_5
# 74 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	closemessage
# 75 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 76 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 17, 34, 17, 29, 0x482, TRUE
# 77 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 18, 35, 18, 29, 0x498
# 78 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 19, 35, 19, 29, 0x486
# 79 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 20, 35, 20, 29, 0x49A
# 80 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 21, 34, 21, 29, 0x480, TRUE
# 81 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 82 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setflag FLAG_BOULDERDOOR
# 83 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	waitse
# 84 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	return

MeteorCave1_LegendaryRoom_IronBoulderDoor_2:
# 60 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_0
# 61 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_IronBoulderDoor_5:
# 69 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	delay 30
# 70 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_2
# 71 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_IronCrownDoor::
# 89 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 90 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_CROWNDOOR, MeteorCave1_LegendaryRoom_IronCrownDoor_2
# 95 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronCrownDoor_Text_0
# 98 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_COBALION
# 99 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_IronCrownDoor_5
# 105 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	closemessage
# 106 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 107 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 29, 34, 29, 29, 0x482, TRUE
# 108 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 30, 35, 30, 29, 0x498
# 109 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 31, 35, 31, 29, 0x486
# 110 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 32, 35, 32, 29, 0x49A
# 111 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setmetatileinrange 33, 34, 33, 29, 0x480, TRUE
# 112 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 113 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	setflag FLAG_CROWNDOOR
# 114 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	waitse
# 115 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	return

MeteorCave1_LegendaryRoom_IronCrownDoor_2:
# 91 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_0
# 92 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_IronCrownDoor_5:
# 100 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	delay 30
# 101 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_2
# 102 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave2_LegeRoom_IronLeaves::
# 120 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 121 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	faceplayer
# 122 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	legendaryencounter SPECIES_IRON_LEAVES, 75, LOCALID_IRONLEAVES, FLAG_HIDE_IRONLEAVES
# 123 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave2_LegeRoom_IronBoulder::
# 128 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 129 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	faceplayer
# 130 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	legendaryencounter SPECIES_IRON_BOULDER, 75, LOCALID_IRON_BOULDER, FLAG_HIDE_IRONBOULDER
# 131 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave2_LegeRoom_IronCrown::
# 136 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	lock
# 137 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	faceplayer
# 138 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	legendaryencounter SPECIES_IRON_CROWN, 75, LOCALID_IRONCROWN, FLAG_HIDE_IRONCROWN
# 139 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_0:
# 30 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	.string "The path is open.$"

MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_1:
# 34 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING LEAVES$"

MeteorCave1_LegendaryRoom_IronLeavesDoor_Text_2:
# 40 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	.string "Nothing seems to happen.$"

MeteorCave1_LegendaryRoom_IronBoulderDoor_Text_0:
# 64 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING TERRA$"

MeteorCave1_LegendaryRoom_IronCrownDoor_Text_0:
# 95 "data/maps/MeteorCave2_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING WILL$"
