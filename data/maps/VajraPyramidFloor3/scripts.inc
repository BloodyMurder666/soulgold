VajraPyramidFloor3_MapScripts::
	.byte 0


PyramidDusknoir2::
# 4 "data/maps/VajraPyramidFloor3/scripts.pory"
	lockall
# 5 "data/maps/VajraPyramidFloor3/scripts.pory"
	playmoncry SPECIES_DUSKNOIR, 0
# 6 "data/maps/VajraPyramidFloor3/scripts.pory"
	waitmoncry
# 7 "data/maps/VajraPyramidFloor3/scripts.pory"
	delay 10
# 8 "data/maps/VajraPyramidFloor3/scripts.pory"
	warpteleport MAP_VAJRA_PYRAMID_FLOOR3, 1, 4
# 9 "data/maps/VajraPyramidFloor3/scripts.pory"
	waitstate
# 10 "data/maps/VajraPyramidFloor3/scripts.pory"
	releaseall
	end

