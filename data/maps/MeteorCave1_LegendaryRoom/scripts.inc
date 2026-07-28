MeteorCave1_LegendaryRoom_MapScripts::
# 2 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_RAGINGDOOR, MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_2
MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 10 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_GOUGINGDOOR, MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_5
MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 17 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_WALKINGDOOR, MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_7
	return

MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 5, 35, 5, 29, 0x482, TRUE
# 5 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 6, 35, 6, 29, 0x498
# 6 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 7, 35, 7, 29, 0x486
# 7 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 8, 35, 8, 29, 0x49A
# 8 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 9, 34, 9, 29, 0x480, TRUE
	goto MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1

MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_5:
# 11 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 17, 34, 17, 29, 0x482, TRUE
# 12 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 18, 35, 18, 29, 0x498
# 13 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 19, 35, 19, 29, 0x486
# 14 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 20, 35, 20, 29, 0x49A
# 15 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 21, 34, 21, 29, 0x480, TRUE
	goto MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_4

MeteorCave1_LegendaryRoom_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 18 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 29, 34, 29, 29, 0x482, TRUE
# 19 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 30, 35, 30, 29, 0x498
# 20 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 31, 35, 31, 29, 0x486
# 21 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 32, 35, 32, 29, 0x49A
# 22 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 33, 34, 33, 29, 0x480, TRUE
	return


MeteorCave1_LegendaryRoom_RagingBoltDoor::
# 28 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 29 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_RAGINGDOOR, MeteorCave1_LegendaryRoom_RagingBoltDoor_2
# 34 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_1
# 37 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_RAIKOU
# 38 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_RagingBoltDoor_5
# 44 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	closemessage
# 45 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 46 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 5, 35, 5, 29, 0x482, TRUE
# 47 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 6, 35, 6, 29, 0x498
# 48 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 7, 35, 7, 29, 0x486
# 49 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 8, 35, 8, 29, 0x49A
# 50 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 9, 34, 9, 29, 0x480, TRUE
# 51 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 52 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setflag FLAG_RAGINGDOOR
# 53 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	waitse
# 54 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_RagingBoltDoor_2:
# 30 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_0
# 31 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_RagingBoltDoor_5:
# 39 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	delay 30
# 40 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_2
# 41 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_GougingFireDoor::
# 59 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 60 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_GOUGINGDOOR, MeteorCave1_LegendaryRoom_GougingFireDoor_2
# 65 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_GougingFireDoor_Text_0
# 68 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_ENTEI
# 69 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_GougingFireDoor_5
# 75 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	closemessage
# 76 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 77 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 17, 34, 17, 29, 0x482, TRUE
# 78 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 18, 35, 18, 29, 0x498
# 79 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 19, 35, 19, 29, 0x486
# 80 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 20, 35, 20, 29, 0x49A
# 81 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 21, 34, 21, 29, 0x480, TRUE
# 82 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 83 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setflag FLAG_GOUGINGDOOR
# 84 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	waitse
# 85 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_GougingFireDoor_2:
# 61 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_0
# 62 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_GougingFireDoor_5:
# 70 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	delay 30
# 71 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_2
# 72 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_WalkingWakeDoor::
# 90 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 91 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	goto_if_set FLAG_WALKINGDOOR, MeteorCave1_LegendaryRoom_WalkingWakeDoor_2
# 96 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_WalkingWakeDoor_Text_0
# 99 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	checkspecies SPECIES_SUICUNE
# 100 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_LegendaryRoom_WalkingWakeDoor_5
# 106 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	closemessage
# 107 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	playse SE_BANG
# 108 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 29, 34, 29, 29, 0x482, TRUE
# 109 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 30, 35, 30, 29, 0x498
# 110 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 31, 35, 31, 29, 0x486
# 111 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 32, 35, 32, 29, 0x49A
# 112 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setmetatileinrange 33, 34, 33, 29, 0x480, TRUE
# 113 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	special DrawWholeMapView
# 114 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	setflag FLAG_WALKINGDOOR
# 115 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	waitse
# 116 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_WalkingWakeDoor_2:
# 92 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_0
# 93 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end

MeteorCave1_LegendaryRoom_WalkingWakeDoor_5:
# 101 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	delay 30
# 102 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	msgbox MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_2
# 103 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegeRoom_RagingBolt::
# 121 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 122 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	faceplayer
# 123 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	bosslegendaryencounter SPECIES_RAGING_BOLT, 75, LOCALID_RAGINGBOLT, FLAG_HIDE_RAGINGBOLT
# 124 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegeRoom_GougingFire::
# 129 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 130 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	faceplayer
# 131 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	bosslegendaryencounter SPECIES_GOUGING_FIRE, 75, LOCALID_GOUGINGFIRE, FLAG_HIDE_GOUGINGFIRE
# 132 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegeRoom_WalkingWake::
# 137 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	lock
# 138 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	faceplayer
# 139 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	bosslegendaryencounter SPECIES_WALKING_WAKE, 75, LOCALID_WALKINGWAKE, FLAG_HIDE_WALKINGWAKE
# 140 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	release
	end


MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_0:
# 30 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	.string "The path is open.$"

MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_1:
# 34 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING THUNDER$"

MeteorCave1_LegendaryRoom_RagingBoltDoor_Text_2:
# 40 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	.string "Nothing seems to happen.$"

MeteorCave1_LegendaryRoom_GougingFireDoor_Text_0:
# 65 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING VOLCANO$"

MeteorCave1_LegendaryRoom_WalkingWakeDoor_Text_0:
# 96 "data/maps/MeteorCave1_LegendaryRoom/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "BRING AURORA$"
