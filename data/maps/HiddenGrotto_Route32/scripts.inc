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
	goto_if_unset FLAG_ROUTE32_GROTTO, handleRoute32GrottoEvent_1
	return

handleRoute32GrottoEvent_1:
# 9 "data/maps/HiddenGrotto_Route32/scripts.pory"
	random 2
# 10 "data/maps/HiddenGrotto_Route32/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 0, handleRoute32GrottoEvent_4
# 12 "data/maps/HiddenGrotto_Route32/scripts.pory"
	case 1, handleRoute32GrottoEvent_5
	return

handleRoute32GrottoEvent_4:
# 11 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 2, 8, 4
	return

handleRoute32GrottoEvent_5:
# 12 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setobjectxyperm 1, 8, 4
	return


Route32GrottoApplin::
# 18 "data/maps/HiddenGrotto_Route32/scripts.pory"
	lock
# 19 "data/maps/HiddenGrotto_Route32/scripts.pory"
	faceplayer
# 20 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setwildbattle2 SPECIES_APPLIN, 10, ITEM_SITRUS_BERRY, 2, MOVE_ASTONISH, MOVE_WITHDRAW, MOVE_RECYCLE, MOVE_ROLLOUT, FALSE
# 21 "data/maps/HiddenGrotto_Route32/scripts.pory"
	waitse
# 22 "data/maps/HiddenGrotto_Route32/scripts.pory"
	playmoncry SPECIES_APPLIN, CRY_MODE_ENCOUNTER
# 23 "data/maps/HiddenGrotto_Route32/scripts.pory"
	delay 40
# 24 "data/maps/HiddenGrotto_Route32/scripts.pory"
	waitmoncry
# 25 "data/maps/HiddenGrotto_Route32/scripts.pory"
	setflag FLAG_ROUTE32_GROTTO
# 26 "data/maps/HiddenGrotto_Route32/scripts.pory"
	dowildbattle
# 27 "data/maps/HiddenGrotto_Route32/scripts.pory"
	removeobject 2
# 28 "data/maps/HiddenGrotto_Route32/scripts.pory"
	release
	end


FindItem_Route32Grotto::
# 33 "data/maps/HiddenGrotto_Route32/scripts.pory"
	finditem ITEM_GROWTH_MULCH
# 34 "data/maps/HiddenGrotto_Route32/scripts.pory"
	removeobject 1
	end

