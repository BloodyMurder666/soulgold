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
# 15 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 1, handleLAKEOFRAGEGrottoEvent_3
# 20 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 2, handleLAKEOFRAGEGrottoEvent_4
# 25 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 3, handleLAKEOFRAGEGrottoEvent_5
# 30 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	case 4, handleLAKEOFRAGEGrottoEvent_6
	return

handleLAKEOFRAGEGrottoEvent_2:
# 11 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 12 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 13 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
# 14 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_3:
# 16 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 17 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 18 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
# 19 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_4:
# 21 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 22 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 28, 27
# 23 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 14, 11
# 24 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_5:
# 26 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 27 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 2, 28, 27
# 28 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm 1, 14, 11
# 29 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 28, 27
	return

handleLAKEOFRAGEGrottoEvent_6:
# 31 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	clearflag FLAG_LAKEOFRAGE_GROTTO
# 32 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_ITEM_LAKEOFRAGE, 28, 27
# 33 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_POKEMON_LAKEOFRAGE, 28, 27
# 34 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setobjectxyperm LOCALID_GROTTO_HIDDEN_ITEM_LAKEOFRAGE, 14, 11
	return


LAKEOFRAGE_GrottoPokemon::
# 40 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	lock
# 41 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	faceplayer
# 42 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 43 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 44 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
# 45 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_CreateCurrentMon
# 46 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LAKEOFRAGE_GrottoPokemon_2
# 50 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	waitse
# 51 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	delay 40
# 52 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	waitmoncry
# 53 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 54 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 55 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	dowildbattle
# 56 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	removeobject 2
# 57 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	release
	end

LAKEOFRAGE_GrottoPokemon_2:
# 47 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	release
	end


FindItem_LAKEOFRAGE_Grotto::
# 62 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 63 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	finditem VAR_RESULT
# 64 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq FindItem_LAKEOFRAGE_Grotto_2
# 67 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 68 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
# 69 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	removeobject 1
	end

FindItem_LAKEOFRAGE_Grotto_2:
	end


FindHiddenItem_LAKEOFRAGE_Grotto::
# 74 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentType
# 75 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_ne FindHiddenItem_LAKEOFRAGE_Grotto_2
# 79 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_GetCurrentContentId
# 80 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	finditem VAR_RESULT
# 81 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq FindHiddenItem_LAKEOFRAGE_Grotto_5
# 84 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	special HiddenGrotto_EmptyCurrent
# 85 "data/maps/HiddenGrotto_Lakeofrage/scripts.pory"
	setflag FLAG_LAKEOFRAGE_GROTTO
	end

FindHiddenItem_LAKEOFRAGE_Grotto_2:
	end

FindHiddenItem_LAKEOFRAGE_Grotto_5:
	end

