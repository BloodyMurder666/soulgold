MeteorCave2_MapScripts::
# 2 "data/maps/MeteorCave2/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorCave2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MeteorCave2_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MeteorCave2/scripts.pory"
	goto_if_set FLAG_ALL_FUTUREMONS, MeteorCave2_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

MeteorCave2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/MeteorCave2/scripts.pory"
	setmetatile 8, 32, 0x4D5, FALSE
	return


IronValiantEnc::
# 11 "data/maps/MeteorCave2/scripts.pory"
	lock
# 12 "data/maps/MeteorCave2/scripts.pory"
	faceplayer
# 13 "data/maps/MeteorCave2/scripts.pory"
	legendaryencounter SPECIES_IRON_VALIANT, 70, LOCALID_IRON_VALIANT, FLAG_HIDE_IRONVALIANT
# 14 "data/maps/MeteorCave2/scripts.pory"
	release
	end


AncientWallMet::
# 19 "data/maps/MeteorCave2/scripts.pory"
	lock
# 20 "data/maps/MeteorCave2/scripts.pory"
	goto_if_set FLAG_ALL_FUTUREMONS, AncientWallMet_2
# 25 "data/maps/MeteorCave2/scripts.pory"
	msgbox AncientWallMet_Text_1
# 29 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_TREADS
# 30 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_5
AncientWallMet_4:
# 33 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_BUNDLE
# 34 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_8
AncientWallMet_7:
# 37 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_HANDS
# 38 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_11
AncientWallMet_10:
# 41 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_JUGULIS
# 42 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_14
AncientWallMet_13:
# 45 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_MOTH
# 46 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_17
AncientWallMet_16:
# 49 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_THORNS
# 50 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_20
AncientWallMet_19:
# 53 "data/maps/MeteorCave2/scripts.pory"
	getcaughtmon SPECIES_IRON_VALIANT
# 54 "data/maps/MeteorCave2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq AncientWallMet_23
AncientWallMet_22:
# 57 "data/maps/MeteorCave2/scripts.pory"
	closemessage
# 58 "data/maps/MeteorCave2/scripts.pory"
	playse SE_BANG
# 59 "data/maps/MeteorCave2/scripts.pory"
	setmetatile 8, 32, 0x4D5, FALSE
# 60 "data/maps/MeteorCave2/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/MeteorCave2/scripts.pory"
	setflag FLAG_ALL_FUTUREMONS
# 62 "data/maps/MeteorCave2/scripts.pory"
	waitse
# 63 "data/maps/MeteorCave2/scripts.pory"
	release
	return

AncientWallMet_2:
# 21 "data/maps/MeteorCave2/scripts.pory"
	msgbox AncientWallMet_Text_0
# 22 "data/maps/MeteorCave2/scripts.pory"
	release
	end

AncientWallMet_5:
# 31 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_4

AncientWallMet_8:
# 35 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_7

AncientWallMet_11:
# 39 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_10

AncientWallMet_14:
# 43 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_13

AncientWallMet_17:
# 47 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_16

AncientWallMet_20:
# 51 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_19

AncientWallMet_23:
# 55 "data/maps/MeteorCave2/scripts.pory"
	goto MeteorCave1_NothingHappens
	goto AncientWallMet_22


AncientWallMet_Text_0:
# 21 "data/maps/MeteorCave2/scripts.pory"
	.string "The way is open.$"

AncientWallMet_Text_1:
# 25 "data/maps/MeteorCave2/scripts.pory"
	.string "There's an inscription on the wall.\p"
	.string "GATHER ALL\n"
	.string "OF THE FUTURE$"
