HiddenGrotto_Unused_MapScripts::
# 2 "data/maps/HiddenGrotto_Unused/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HiddenGrotto_Unused_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

HiddenGrotto_Unused_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/HiddenGrotto_Unused/scripts.pory"
	goto handleVajraDesertWestGrottoEvent
	return


handleVajraDesertWestGrottoEvent::
# 8 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_InitializeCurrent
# 9 "data/maps/HiddenGrotto_Unused/scripts.pory"
	switch VAR_RESULT
# 10 "data/maps/HiddenGrotto_Unused/scripts.pory"
	case 0, handleVajraDesertWestGrottoEvent_2
# 14 "data/maps/HiddenGrotto_Unused/scripts.pory"
	case 1, handleVajraDesertWestGrottoEvent_3
# 18 "data/maps/HiddenGrotto_Unused/scripts.pory"
	case 2, handleVajraDesertWestGrottoEvent_4
# 22 "data/maps/HiddenGrotto_Unused/scripts.pory"
	case 3, handleVajraDesertWestGrottoEvent_5
# 26 "data/maps/HiddenGrotto_Unused/scripts.pory"
	case 4, handleVajraDesertWestGrottoEvent_6
	return

handleVajraDesertWestGrottoEvent_2:
# 11 "data/maps/HiddenGrotto_Unused/scripts.pory"
	clearflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 12 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 1, 28, 27
# 13 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleVajraDesertWestGrottoEvent_3:
# 15 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 16 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 1, 28, 27
# 17 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleVajraDesertWestGrottoEvent_4:
# 19 "data/maps/HiddenGrotto_Unused/scripts.pory"
	clearflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 20 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 1, 28, 27
# 21 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 2, 14, 11
	return

handleVajraDesertWestGrottoEvent_5:
# 23 "data/maps/HiddenGrotto_Unused/scripts.pory"
	clearflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 24 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 2, 28, 27
# 25 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm 1, 14, 11
	return

handleVajraDesertWestGrottoEvent_6:
# 27 "data/maps/HiddenGrotto_Unused/scripts.pory"
	clearflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 28 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_ITEM_VAJRA_DESERT_WEST, 28, 27
# 29 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_POKEMON_VAJRA_DESERT_WEST, 28, 27
# 30 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_VAJRA_DESERT_WEST, 14, 11
	return


VajraDesertWest_GrottoPokemon::
# 36 "data/maps/HiddenGrotto_Unused/scripts.pory"
	lock
# 37 "data/maps/HiddenGrotto_Unused/scripts.pory"
	faceplayer
# 38 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 39 "data/maps/HiddenGrotto_Unused/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 40 "data/maps/HiddenGrotto_Unused/scripts.pory"
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
# 41 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_CreateCurrentMon
# 42 "data/maps/HiddenGrotto_Unused/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq VajraDesertWest_GrottoPokemon_2
# 46 "data/maps/HiddenGrotto_Unused/scripts.pory"
	waitse
# 47 "data/maps/HiddenGrotto_Unused/scripts.pory"
	delay 40
# 48 "data/maps/HiddenGrotto_Unused/scripts.pory"
	waitmoncry
# 49 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 50 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 51 "data/maps/HiddenGrotto_Unused/scripts.pory"
	dowildbattle
# 52 "data/maps/HiddenGrotto_Unused/scripts.pory"
	removeobject 2
# 53 "data/maps/HiddenGrotto_Unused/scripts.pory"
	release
	end

VajraDesertWest_GrottoPokemon_2:
# 43 "data/maps/HiddenGrotto_Unused/scripts.pory"
	release
	end


FindItem_VajraDesertWest_Grotto::
# 58 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 59 "data/maps/HiddenGrotto_Unused/scripts.pory"
	finditem VAR_RESULT
# 60 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 61 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setflag FLAG_VAJRA_DESERT_WEST_GROTTO
# 62 "data/maps/HiddenGrotto_Unused/scripts.pory"
	removeobject 1
	end


FindHiddenItem_VajraDesertWest_Grotto::
# 67 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_GetCurrentContentType
# 68 "data/maps/HiddenGrotto_Unused/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_ne FindHiddenItem_VajraDesertWest_Grotto_2
# 72 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 73 "data/maps/HiddenGrotto_Unused/scripts.pory"
	finditem VAR_RESULT
# 74 "data/maps/HiddenGrotto_Unused/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 75 "data/maps/HiddenGrotto_Unused/scripts.pory"
	setflag FLAG_VAJRA_DESERT_WEST_GROTTO
	end

FindHiddenItem_VajraDesertWest_Grotto_2:
	end

