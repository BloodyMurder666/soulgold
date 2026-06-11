RailwayCave_2F_MapScripts::
# 2 "data/maps/RailwayCave_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/RailwayCave_2F/scripts.pory"
	goto_if_set FLAG_SUS_RAILWAY_DOOR, RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

RailwayCave_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 10, 0x45A, FALSE
# 5 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 9, 0x452, FALSE
	return


# 10 "data/maps/RailwayCave_2F/scripts.pory"

# 11 "data/maps/RailwayCave_2F/scripts.pory"
RailwayCave_BrailleRegisteel:
# 12 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "THE ONE WHO\n"
# 13 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "CLANGS THE\n"
# 14 "data/maps/RailwayCave_2F/scripts.pory"
	.braille "SCALES.$"

RailwayCave_SusDoor::
# 18 "data/maps/RailwayCave_2F/scripts.pory"
	lock
# 19 "data/maps/RailwayCave_2F/scripts.pory"
	msgbox RailwayCave_SusDoor_Text_0
# 20 "data/maps/RailwayCave_2F/scripts.pory"
	closemessage
# 21 "data/maps/RailwayCave_2F/scripts.pory"
	braillemsgbox RailwayCave_BrailleRegisteel
# 22 "data/maps/RailwayCave_2F/scripts.pory"
	checkspecies SPECIES_KOMMO_O
# 23 "data/maps/RailwayCave_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RailwayCave_SusDoor_2
RailwayCave_SusDoor_1:
# 30 "data/maps/RailwayCave_2F/scripts.pory"
	release
	end

RailwayCave_SusDoor_2:
# 24 "data/maps/RailwayCave_2F/scripts.pory"
	setflag FLAG_SUS_RAILWAY_DOOR
# 25 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 10, 0x45A, FALSE
# 26 "data/maps/RailwayCave_2F/scripts.pory"
	setmetatile 73, 9, 0x452, FALSE
# 27 "data/maps/RailwayCave_2F/scripts.pory"
	playse SE_EXIT
# 28 "data/maps/RailwayCave_2F/scripts.pory"
	special DrawWholeMapView
	goto RailwayCave_SusDoor_1


RailwayCave_SusDoor_Text_0:
# 19 "data/maps/RailwayCave_2F/scripts.pory"
	.string "Something is carven on the door...$"
