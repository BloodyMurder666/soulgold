FoggyForest_MapScripts::
	.byte 0


FoggyForest_HexManiac::
# 4 "data/maps/FoggyForest/scripts.pory"
	trainerbattle_single TRAINER_MINA, FoggyForest_HexManiac_Text_0, FoggyForest_HexManiac_Text_1
# 5 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_HexManiac_Text_2, MSGBOX_AUTOCLOSE
	return


FoggyForest_Girl::
# 10 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_Girl_Text_0, MSGBOX_NPC
	return


FoggyForest_Phantump::
# 15 "data/maps/FoggyForest/scripts.pory"
	lock
# 16 "data/maps/FoggyForest/scripts.pory"
	faceplayer
# 17 "data/maps/FoggyForest/scripts.pory"
	playmoncry SPECIES_PHANTUMP, CRY_MODE_NORMAL
# 18 "data/maps/FoggyForest/scripts.pory"
	msgbox FoggyForest_Phantump_Text_0
# 19 "data/maps/FoggyForest/scripts.pory"
	waitmoncry
# 20 "data/maps/FoggyForest/scripts.pory"
	release
	end


FoggyForestBMTeleport::
# 25 "data/maps/FoggyForest/scripts.pory"
	checkitem ITEM_BLACK_MIRROR
# 26 "data/maps/FoggyForest/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FoggyForestBMTeleport_2
FoggyForestBMTeleport_1:
# 30 "data/maps/FoggyForest/scripts.pory"
	release
	end

FoggyForestBMTeleport_2:
# 27 "data/maps/FoggyForest/scripts.pory"
	warpwhitefade MAP_FOGGYFOREST_DEPTHS, 8, 24
# 28 "data/maps/FoggyForest/scripts.pory"
	waitstate
	goto FoggyForestBMTeleport_1


FoggyForestBMTeleportR::
# 35 "data/maps/FoggyForest/scripts.pory"
	checkitem ITEM_BLACK_MIRROR
# 36 "data/maps/FoggyForest/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FoggyForestBMTeleportR_2
FoggyForestBMTeleportR_1:
# 40 "data/maps/FoggyForest/scripts.pory"
	release
	end

FoggyForestBMTeleportR_2:
# 37 "data/maps/FoggyForest/scripts.pory"
	warpwhitefade MAP_FOGGYFOREST_DEPTHS, 9, 24
# 38 "data/maps/FoggyForest/scripts.pory"
	waitstate
	goto FoggyForestBMTeleportR_1


FoggyForestBMOutTeleport::
# 45 "data/maps/FoggyForest/scripts.pory"
	warpwhitefade MAP_FOGGY_FOREST, 38, 5
# 46 "data/maps/FoggyForest/scripts.pory"
	waitstate
# 47 "data/maps/FoggyForest/scripts.pory"
	release
	end


FoggyForestBMOutTeleportR::
# 52 "data/maps/FoggyForest/scripts.pory"
	warpwhitefade MAP_FOGGY_FOREST, 39, 5
# 53 "data/maps/FoggyForest/scripts.pory"
	waitstate
# 54 "data/maps/FoggyForest/scripts.pory"
	release
	end


FoggyForest_HexManiac_Text_0:
# 4 "data/maps/FoggyForest/scripts.pory"
	.string "Heeheehee, are you lost?$"

FoggyForest_HexManiac_Text_1:
# 4 "data/maps/FoggyForest/scripts.pory"
	.string "The eyes above are watching.$"

FoggyForest_HexManiac_Text_2:
# 5 "data/maps/FoggyForest/scripts.pory"
	.string "Bravery or foolishness, which one are\n"
	.string "you carrying here?$"

FoggyForest_Girl_Text_0:
# 10 "data/maps/FoggyForest/scripts.pory"
	.string "Round and round, all paths lead back\n"
	.string "here, la la la!$"

FoggyForest_Phantump_Text_0:
# 18 "data/maps/FoggyForest/scripts.pory"
	.string "Phantump: Phoo!$"
