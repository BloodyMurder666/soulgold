HiddenGrotto_Lakeofrage_MapScripts::
# 2 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HiddenGrotto_Lakeofrage_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

HiddenGrotto_Lakeofrage_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	goto handleLAKEOFRAGEGrottoEvent
	return


handleLAKEOFRAGEGrottoEvent::
# 8 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_InitializeCurrent
# 9 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	switch VAR_RESULT
# 10 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 0, handleLAKEOFRAGEGrottoEvent_2
# 14 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 1, handleLAKEOFRAGEGrottoEvent_3
# 18 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 2, handleLAKEOFRAGEGrottoEvent_4
# 22 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 3, handleLAKEOFRAGEGrottoEvent_5
# 26 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 4, handleLAKEOFRAGEGrottoEvent_6
	return

handleLAKEOFRAGEGrottoEvent_2:
# 11 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 12 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 13 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_3:
# 15 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 16 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 17 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_4:
# 19 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 20 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 21 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 14, 11
	return

handleLAKEOFRAGEGrottoEvent_5:
# 23 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 24 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
# 25 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 14, 11
	return

handleLAKEOFRAGEGrottoEvent_6:
# 27 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 28 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_ITEM_LAKEOFRAGE, 28, 27
# 29 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_POKEMON_LAKEOFRAGE, 28, 27
# 30 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 14, 11
	return


LAKEOFRAGE_GrottoPokemon::
# 36 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	lock
# 37 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	faceplayer
# 38 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 39 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 40 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
# 41 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_CreateCurrentMon
# 42 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LAKEOFRAGE_GrottoPokemon_2
# 46 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	waitse
# 47 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	delay 40
# 48 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	waitmoncry
# 49 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 50 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 51 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	dowildbattle
# 52 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	removeobject 2
# 53 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	release
	end

LAKEOFRAGE_GrottoPokemon_2:
# 43 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	release
	end


FindItem_LAKEOFRAGE_Grotto::
# 58 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 59 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	finditem VAR_RESULT
# 60 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 61 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 62 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	removeobject 1
	end


FindHiddenItem_LAKEOFRAGE_Grotto::
# 67 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentType
# 68 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_ne FindHiddenItem_LAKEOFRAGE_Grotto_2
# 72 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 73 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	finditem VAR_RESULT
# 74 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 75 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
	end

FindHiddenItem_LAKEOFRAGE_Grotto_2:
	end

