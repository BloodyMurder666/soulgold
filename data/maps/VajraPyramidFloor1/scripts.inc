VajraPyramidFloor1_MapScripts::
	.byte 0


VajraPyramid1_Urn::
# 4 "data/maps/VajraPyramidFloor1/scripts.pory"
	lock
# 5 "data/maps/VajraPyramidFloor1/scripts.pory"
	goto_if_set FLAG_VAJRAPYRAMID1_URN, VajraPyramid1_Urn_2
# 10 "data/maps/VajraPyramidFloor1/scripts.pory"
	finditem ITEM_RELIC_GOLD
# 11 "data/maps/VajraPyramidFloor1/scripts.pory"
	setflag FLAG_VAJRAPYRAMID1_URN
# 12 "data/maps/VajraPyramidFloor1/scripts.pory"
	release
	end

VajraPyramid1_Urn_2:
# 6 "data/maps/VajraPyramidFloor1/scripts.pory"
	msgbox VajraPyramid1_Urn_Text_0
# 7 "data/maps/VajraPyramidFloor1/scripts.pory"
	release
	end


VajraPyramid1_Urn_Text_0:
# 6 "data/maps/VajraPyramidFloor1/scripts.pory"
	.string "The urn is empty.$"
