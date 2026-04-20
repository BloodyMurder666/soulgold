HiddenGrotto_Ilex_MapScripts::
# 2 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HiddenGrotto_Ilex_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

HiddenGrotto_Ilex_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	goto handleILEXGrottoEvent
	return


handleILEXGrottoEvent::
# 8 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_InitializeCurrent
# 9 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	switch VAR_RESULT
# 10 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	case 0, handleILEXGrottoEvent_2
# 14 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	case 1, handleILEXGrottoEvent_3
# 18 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	case 2, handleILEXGrottoEvent_4
# 22 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	case 3, handleILEXGrottoEvent_5
# 26 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	case 4, handleILEXGrottoEvent_6
	return

handleILEXGrottoEvent_2:
# 11 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	clearflag FLAG_ILEX_GROTTO
# 12 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 1, 28, 27
# 13 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleILEXGrottoEvent_3:
# 15 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setflag FLAG_ILEX_GROTTO
# 16 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 1, 28, 27
# 17 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleILEXGrottoEvent_4:
# 19 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	clearflag FLAG_ILEX_GROTTO
# 20 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 1, 28, 27
# 21 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 2, 14, 11
	return

handleILEXGrottoEvent_5:
# 23 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	clearflag FLAG_ILEX_GROTTO
# 24 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 2, 28, 27
# 25 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm 1, 14, 11
	return

handleILEXGrottoEvent_6:
# 27 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	clearflag FLAG_ILEX_GROTTO
# 28 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_ITEM_ILEX, 28, 27
# 29 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_POKEMON_ILEX, 28, 27
# 30 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_ILEX, 14, 11
	return


ILEX_GrottoPokemon::
# 36 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	lock
# 37 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	faceplayer
# 38 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 39 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 40 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
# 41 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_CreateCurrentMon
# 42 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ILEX_GrottoPokemon_2
# 46 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	waitse
# 47 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	delay 40
# 48 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	waitmoncry
# 49 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 50 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setflag FLAG_ILEX_GROTTO
# 51 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	dowildbattle
# 52 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	removeobject 2
# 53 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	release
	end

ILEX_GrottoPokemon_2:
# 43 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	release
	end


FindItem_ILEX_Grotto::
# 58 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 59 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	finditem VAR_RESULT
# 60 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 61 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setflag FLAG_ILEX_GROTTO
# 62 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	removeobject 1
	end


FindHiddenItem_ILEX_Grotto::
# 67 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_GetCurrentContentType
# 68 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_ne FindHiddenItem_ILEX_Grotto_2
# 72 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 73 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	finditem VAR_RESULT
# 74 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 75 "data/maps/HiddenGrotto_Ilex/scripts.pory"
	setflag FLAG_ILEX_GROTTO
	end

FindHiddenItem_ILEX_Grotto_2:
	end

