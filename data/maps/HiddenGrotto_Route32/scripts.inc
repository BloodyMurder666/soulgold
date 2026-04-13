HiddenGrotto_Route32_MapScripts::
# 2 "data/maps/HiddenGrotto_Route32/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HiddenGrotto_Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

HiddenGrotto_Route32_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/HiddenGrotto_Route32/scripts.pory"
	goto handleRoute32GrottoEvent
	return


handleRoute32GrottoEvent::
# 8 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_InitializeCurrent
# 9 "data/maps/HiddenGrotto_Route32/scripts.pory"
	switch VAR_RESULT
# 10 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 0, handleRoute32GrottoEvent_2
# 14 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 1, handleRoute32GrottoEvent_3
# 18 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 2, handleRoute32GrottoEvent_4
# 22 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 3, handleRoute32GrottoEvent_5
# 26 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 4, handleRoute32GrottoEvent_6
	return

handleRoute32GrottoEvent_2:
# 11 "data/maps/HiddenGrotto_Route32/scripts.pory"
	clearflag FLAG_ROUTE32_GROTTO
# 12 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 28, 27
# 13 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleRoute32GrottoEvent_3:
# 15 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setflag FLAG_ROUTE32_GROTTO
# 16 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 28, 27
# 17 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleRoute32GrottoEvent_4:
# 19 "data/maps/HiddenGrotto_Route32/scripts.pory"
	clearflag FLAG_ROUTE32_GROTTO
# 20 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 28, 27
# 21 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 14, 11
	return

handleRoute32GrottoEvent_5:
# 23 "data/maps/HiddenGrotto_Route32/scripts.pory"
	clearflag FLAG_ROUTE32_GROTTO
# 24 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 28, 27
# 25 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 14, 11
	return

handleRoute32GrottoEvent_6:
# 27 "data/maps/HiddenGrotto_Route32/scripts.pory"
	clearflag FLAG_ROUTE32_GROTTO
# 28 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 28, 27
# 29 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 28, 27
	return


Route32GrottoPokemon::
# 35 "data/maps/HiddenGrotto_Route32/scripts.pory"
	lock
# 36 "data/maps/HiddenGrotto_Route32/scripts.pory"
	faceplayer
# 37 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 38 "data/maps/HiddenGrotto_Route32/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 39 "data/maps/HiddenGrotto_Route32/scripts.pory"
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
# 40 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_CreateCurrentMon
# 41 "data/maps/HiddenGrotto_Route32/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route32GrottoPokemon_2
# 45 "data/maps/HiddenGrotto_Route32/scripts.pory"
	waitse
# 46 "data/maps/HiddenGrotto_Route32/scripts.pory"
	delay 40
# 47 "data/maps/HiddenGrotto_Route32/scripts.pory"
	waitmoncry
# 48 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 49 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setflag FLAG_ROUTE32_GROTTO
# 50 "data/maps/HiddenGrotto_Route32/scripts.pory"
	dowildbattle
# 51 "data/maps/HiddenGrotto_Route32/scripts.pory"
	removeobject 2
# 52 "data/maps/HiddenGrotto_Route32/scripts.pory"
	release
	end

Route32GrottoPokemon_2:
# 42 "data/maps/HiddenGrotto_Route32/scripts.pory"
	release
	end


FindItem_Route32Grotto::
# 57 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 58 "data/maps/HiddenGrotto_Route32/scripts.pory"
	finditem VAR_RESULT
# 59 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 60 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setflag FLAG_ROUTE32_GROTTO
# 61 "data/maps/HiddenGrotto_Route32/scripts.pory"
	removeobject 1
	end


FindHiddenItem_Route32Grotto::
# 66 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_GetCurrentContentType
# 67 "data/maps/HiddenGrotto_Route32/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_ne FindHiddenItem_Route32Grotto_2
# 71 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 72 "data/maps/HiddenGrotto_Route32/scripts.pory"
	finditem VAR_RESULT
# 73 "data/maps/HiddenGrotto_Route32/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 74 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setflag FLAG_ROUTE32_GROTTO
	end

FindHiddenItem_Route32Grotto_2:
	end

