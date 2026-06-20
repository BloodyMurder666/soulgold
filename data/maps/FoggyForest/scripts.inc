FoggyForest_MapScripts::
	.byte 0


FoggyForest_HexManiac::
# 4 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_HexManiac_Text_0, MSGBOX_NPC
	return


FoggyForest_Girl::
# 8 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_Girl_Text_0, MSGBOX_NPC
	return


FoggyForest_Phantump::
# 12 "data/maps/FoggyForest/scripts.pory"
	lock
# 13 "data/maps/FoggyForest/scripts.pory"
	faceplayer
# 14 "data/maps/FoggyForest/scripts.pory"
	playmoncry SPECIES_PHANTUMP, CRY_MODE_NORMAL
# 15 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_Phantump_Text_0
# 16 "data/maps/FoggyForest/scripts.pory"
	waitmoncry
# 17 "data/maps/FoggyForest/scripts.pory"
	release
	end


FoggyForestBMTeleport::
# 22 "data/maps/FoggyForest/scripts.pory"
	checkitem ITEM_BLACK_MIRROR
# 23 "data/maps/FoggyForest/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FoggyForestBMTeleport_1
	return

FoggyForestBMTeleport_1:
# 24 "data/maps/FoggyForest/scripts.pory"
	warpwhitefade MAP_FOGGYFOREST_DEPTHS, 8, 46
	return


FoggyForestBMOutTeleport::
# 29 "data/maps/FoggyForest/scripts.pory"
	warpsilent MAP_FOGGY_FOREST, 38, 5
	return


FoggyForest_HexManiac_Text_0:
# 4 "data/maps/FoggyForest/scripts.pory"
	.string "TODO, Something spooky$"

FoggyForest_Girl_Text_0:
# 8 "data/maps/FoggyForest/scripts.pory"
	.string "Spooky TODO$"

FoggyForest_Phantump_Text_0:
# 15 "data/maps/FoggyForest/scripts.pory"
	.string "Phantump: Phoo!$"
