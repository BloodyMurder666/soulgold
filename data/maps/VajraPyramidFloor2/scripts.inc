VajraPyramidFloor2_MapScripts::
	.byte 0


VajraPyramid2_Urn1::
# 4 "data/maps/VajraPyramidFloor2/scripts.pory"
	lock
# 5 "data/maps/VajraPyramidFloor2/scripts.pory"
	goto_if_set FLAG_VAJRAPYRAMID2_URN1, VajraPyramid2_Urn1_2
# 10 "data/maps/VajraPyramidFloor2/scripts.pory"
	finditem ITEM_RELIC_SILVER
# 11 "data/maps/VajraPyramidFloor2/scripts.pory"
	setflag FLAG_VAJRAPYRAMID2_URN1
# 12 "data/maps/VajraPyramidFloor2/scripts.pory"
	release
	end

VajraPyramid2_Urn1_2:
# 6 "data/maps/VajraPyramidFloor2/scripts.pory"
	msgbox VajraPyramid2_Urn1_Text_0
# 7 "data/maps/VajraPyramidFloor2/scripts.pory"
	release
	end


VajraPyramid2_Urn2::
# 17 "data/maps/VajraPyramidFloor2/scripts.pory"
	lock
# 18 "data/maps/VajraPyramidFloor2/scripts.pory"
	goto_if_set FLAG_VAJRAPYRAMID2_URN2, VajraPyramid2_Urn2_2
# 23 "data/maps/VajraPyramidFloor2/scripts.pory"
	finditem ITEM_RELIC_COPPER
# 24 "data/maps/VajraPyramidFloor2/scripts.pory"
	setflag FLAG_VAJRAPYRAMID2_URN2
# 25 "data/maps/VajraPyramidFloor2/scripts.pory"
	release
	end

VajraPyramid2_Urn2_2:
# 19 "data/maps/VajraPyramidFloor2/scripts.pory"
	msgbox VajraPyramid2_Urn1_Text_0
# 20 "data/maps/VajraPyramidFloor2/scripts.pory"
	release
	end


PyramidDusknoir1::
# 30 "data/maps/VajraPyramidFloor2/scripts.pory"
	lockall
# 31 "data/maps/VajraPyramidFloor2/scripts.pory"
	playmoncry SPECIES_DUSKNOIR, 0
# 32 "data/maps/VajraPyramidFloor2/scripts.pory"
	waitmoncry
# 33 "data/maps/VajraPyramidFloor2/scripts.pory"
	delay 10
# 34 "data/maps/VajraPyramidFloor2/scripts.pory"
	warpteleport MAP_VAJRA_PYRAMID_FLOOR2, 30, 28
# 35 "data/maps/VajraPyramidFloor2/scripts.pory"
	waitstate
# 36 "data/maps/VajraPyramidFloor2/scripts.pory"
	releaseall
	end


VajraPyramid2_Urn1_Text_0:
# 6 "data/maps/VajraPyramidFloor2/scripts.pory"
	.string "The urn is empty.$"
