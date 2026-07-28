MeteorCave1_MapScripts::
# 2 "data/maps/MeteorCave1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD
# 7 "data/maps/MeteorCave1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorCave1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MeteorCave1/scripts.pory"
	goto_if_set FLAG_ALL_PASTMONS, MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/MeteorCave1/scripts.pory"
	setmetatile 36, 2, 0x4DD, FALSE
	return

MeteorCave1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/MeteorCave1/scripts.pory"
	setflag FLAG_VISITED_METEOR_CAVE
	end


MeteorCave1_WallIns::
# 14 "data/maps/MeteorCave1/scripts.pory"
	lock
# 15 "data/maps/MeteorCave1/scripts.pory"
	goto_if_set FLAG_ALL_PASTMONS, MeteorCave1_WallIns_2
# 20 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_WallIns_Text_1
# 24 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_GREAT_TUSK
# 25 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_5
MeteorCave1_WallIns_4:
# 28 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SCREAM_TAIL
# 29 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_8
MeteorCave1_WallIns_7:
# 32 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_BRUTE_BONNET
# 33 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_11
MeteorCave1_WallIns_10:
# 36 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_FLUTTER_MANE
# 37 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_14
MeteorCave1_WallIns_13:
# 40 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SLITHER_WING
# 41 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_17
MeteorCave1_WallIns_16:
# 44 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SANDY_SHOCKS
# 45 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_20
MeteorCave1_WallIns_19:
# 48 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_ROARING_MOON
# 49 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_23
MeteorCave1_WallIns_22:
# 52 "data/maps/MeteorCave1/scripts.pory"
	closemessage
# 53 "data/maps/MeteorCave1/scripts.pory"
	playse SE_BANG
# 54 "data/maps/MeteorCave1/scripts.pory"
	setmetatile 36, 2, 0x4DD, FALSE
# 55 "data/maps/MeteorCave1/scripts.pory"
	special DrawWholeMapView
# 56 "data/maps/MeteorCave1/scripts.pory"
	setflag FLAG_ALL_PASTMONS
# 57 "data/maps/MeteorCave1/scripts.pory"
	waitse
# 58 "data/maps/MeteorCave1/scripts.pory"
	release
	return

MeteorCave1_WallIns_2:
# 16 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_WallIns_Text_0
# 17 "data/maps/MeteorCave1/scripts.pory"
	release
	end

MeteorCave1_WallIns_5:
# 26 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_4

MeteorCave1_WallIns_8:
# 30 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_7

MeteorCave1_WallIns_11:
# 34 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_10

MeteorCave1_WallIns_14:
# 38 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_13

MeteorCave1_WallIns_17:
# 42 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_16

MeteorCave1_WallIns_20:
# 46 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_19

MeteorCave1_WallIns_23:
# 50 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_22


MeteorCave1_NothingHappens::
# 62 "data/maps/MeteorCave1/scripts.pory"
	delay 30
# 63 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_NothingHappens_Text_0
# 64 "data/maps/MeteorCave1/scripts.pory"
	release
	end


FlutterManeEnc::
# 69 "data/maps/MeteorCave1/scripts.pory"
	lock
# 70 "data/maps/MeteorCave1/scripts.pory"
	faceplayer
# 71 "data/maps/MeteorCave1/scripts.pory"
	legendaryencounter SPECIES_FLUTTER_MANE, 70, LOCALID_FLUTTERMANE, FLAG_HIDE_FLUTTERMANE
# 72 "data/maps/MeteorCave1/scripts.pory"
	release
	end


MeteorCave1_WallIns_Text_0:
# 16 "data/maps/MeteorCave1/scripts.pory"
	.string "The way is open.$"

MeteorCave1_WallIns_Text_1:
# 20 "data/maps/MeteorCave1/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "GATHER ALL\n"
	.string "ANCIENTS$"

MeteorCave1_NothingHappens_Text_0:
# 63 "data/maps/MeteorCave1/scripts.pory"
	.string "Nothing seems to happen.$"
