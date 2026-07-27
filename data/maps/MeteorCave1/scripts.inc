MeteorCave1_MapScripts::
# 2 "data/maps/MeteorCave1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MeteorCave1/scripts.pory"
	goto_if_set FLAG_ALL_PASTMONS, MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

MeteorCave1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/MeteorCave1/scripts.pory"
	setmetatile 36, 2, 0x4DD, FALSE
	return


MeteorCave1_WallIns::
# 10 "data/maps/MeteorCave1/scripts.pory"
	lock
# 11 "data/maps/MeteorCave1/scripts.pory"
	goto_if_set FLAG_ALL_PASTMONS, MeteorCave1_WallIns_2
# 16 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_WallIns_Text_1
# 20 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_GREAT_TUSK
# 21 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_5
MeteorCave1_WallIns_4:
# 24 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SCREAM_TAIL
# 25 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_8
MeteorCave1_WallIns_7:
# 28 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_BRUTE_BONNET
# 29 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_11
MeteorCave1_WallIns_10:
# 32 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_FLUTTER_MANE
# 33 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_14
MeteorCave1_WallIns_13:
# 36 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SLITHER_WING
# 37 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_17
MeteorCave1_WallIns_16:
# 40 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_SANDY_SHOCKS
# 41 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_20
MeteorCave1_WallIns_19:
# 44 "data/maps/MeteorCave1/scripts.pory"
	getcaughtmon SPECIES_ROARING_MOON
# 45 "data/maps/MeteorCave1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MeteorCave1_WallIns_23
MeteorCave1_WallIns_22:
# 48 "data/maps/MeteorCave1/scripts.pory"
	closemessage
# 49 "data/maps/MeteorCave1/scripts.pory"
	playse SE_BANG
# 50 "data/maps/MeteorCave1/scripts.pory"
	setmetatile 36, 2, 0x4DD, FALSE
# 51 "data/maps/MeteorCave1/scripts.pory"
	special DrawWholeMapView
# 52 "data/maps/MeteorCave1/scripts.pory"
	setflag FLAG_ALL_PASTMONS
# 53 "data/maps/MeteorCave1/scripts.pory"
	waitse
# 54 "data/maps/MeteorCave1/scripts.pory"
	release
	return

MeteorCave1_WallIns_2:
# 12 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_WallIns_Text_0
# 13 "data/maps/MeteorCave1/scripts.pory"
	release
	end

MeteorCave1_WallIns_5:
# 22 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_4

MeteorCave1_WallIns_8:
# 26 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_7

MeteorCave1_WallIns_11:
# 30 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_10

MeteorCave1_WallIns_14:
# 34 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_13

MeteorCave1_WallIns_17:
# 38 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_16

MeteorCave1_WallIns_20:
# 42 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_19

MeteorCave1_WallIns_23:
# 46 "data/maps/MeteorCave1/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto MeteorCave1_WallIns_22


MeteorCave1_NothingHappens::
# 58 "data/maps/MeteorCave1/scripts.pory"
	delay 30
# 59 "data/maps/MeteorCave1/scripts.pory"
	msgbox MeteorCave1_NothingHappens_Text_0
# 60 "data/maps/MeteorCave1/scripts.pory"
	release
	end


FlutterManeEnc::
# 65 "data/maps/MeteorCave1/scripts.pory"
	lock
# 66 "data/maps/MeteorCave1/scripts.pory"
	faceplayer
# 67 "data/maps/MeteorCave1/scripts.pory"
	legendaryencounter SPECIES_FLUTTER_MANE, 70, LOCALID_FLUTTERMANE, FLAG_HIDE_FLUTTERMANE
# 68 "data/maps/MeteorCave1/scripts.pory"
	release
	end


MeteorCave1_WallIns_Text_0:
# 12 "data/maps/MeteorCave1/scripts.pory"
	.string "The way is open.$"

MeteorCave1_WallIns_Text_1:
# 16 "data/maps/MeteorCave1/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "GATHER ALL\n"
	.string "ANCIENTS$"

MeteorCave1_NothingHappens_Text_0:
# 59 "data/maps/MeteorCave1/scripts.pory"
	.string "Nothing seems to happen.$"
