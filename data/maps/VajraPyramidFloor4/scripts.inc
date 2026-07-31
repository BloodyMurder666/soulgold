VajraPyramidFloor4_MapScripts::
	.byte 0


Floor4_Ghost1::
# 4 "data/maps/VajraPyramidFloor4/scripts.pory"
	trainerbattle_single TRAINER_SPIRIT1, Floor4_Ghost1_Text_0, Floor4_Ghost1_Text_1
# 5 "data/maps/VajraPyramidFloor4/scripts.pory"
	msgbox Floor4_Ghost1_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Ghost2::
# 9 "data/maps/VajraPyramidFloor4/scripts.pory"
	trainerbattle_single TRAINER_SPIRIT2, Floor4_Ghost2_Text_0, Floor4_Ghost2_Text_1
# 10 "data/maps/VajraPyramidFloor4/scripts.pory"
	msgbox Floor4_Ghost2_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Ghost3::
# 14 "data/maps/VajraPyramidFloor4/scripts.pory"
	trainerbattle_single TRAINER_SPIRIT3, Floor4_Ghost3_Text_0, Floor4_Ghost3_Text_1
# 15 "data/maps/VajraPyramidFloor4/scripts.pory"
	msgbox Floor4_Ghost3_Text_2, MSGBOX_AUTOCLOSE
	return


Floor4_Urn1::
# 19 "data/maps/VajraPyramidFloor4/scripts.pory"
	lock
# 20 "data/maps/VajraPyramidFloor4/scripts.pory"
	goto_if_set FLAG_FLOOR4_URN1LOOT, Floor4_Urn1_2
# 25 "data/maps/VajraPyramidFloor4/scripts.pory"
	finditem ITEM_RELIC_GOLD
# 26 "data/maps/VajraPyramidFloor4/scripts.pory"
	setflag FLAG_FLOOR4_URN1LOOT
# 27 "data/maps/VajraPyramidFloor4/scripts.pory"
	release
	end

Floor4_Urn1_2:
# 21 "data/maps/VajraPyramidFloor4/scripts.pory"
	msgbox Floor4_Urn1_Text_0
# 22 "data/maps/VajraPyramidFloor4/scripts.pory"
	release
	end


Floor4_Urn2::
# 32 "data/maps/VajraPyramidFloor4/scripts.pory"
	lock
# 33 "data/maps/VajraPyramidFloor4/scripts.pory"
	goto_if_set FLAG_FLOOR4_URN2LOOT, Floor4_Urn2_2
# 38 "data/maps/VajraPyramidFloor4/scripts.pory"
	finditem ITEM_RELIC_GOLD
# 39 "data/maps/VajraPyramidFloor4/scripts.pory"
	setflag FLAG_FLOOR4_URN2LOOT
# 40 "data/maps/VajraPyramidFloor4/scripts.pory"
	release
	end

Floor4_Urn2_2:
# 34 "data/maps/VajraPyramidFloor4/scripts.pory"
	msgbox Floor4_Urn1_Text_0
# 35 "data/maps/VajraPyramidFloor4/scripts.pory"
	release
	end


Floor4_Ghost1_Text_0:
# 4 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Woo!$"

Floor4_Ghost1_Text_1:
# 4 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Woo...$"

Floor4_Ghost1_Text_2:
# 5 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Woowoo...$"

Floor4_Ghost2_Text_0:
# 9 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Give...$"

Floor4_Ghost2_Text_1:
# 9 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Taken...$"

Floor4_Ghost2_Text_2:
# 10 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Lost...$"

Floor4_Ghost3_Text_0:
# 14 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "Do not release it!$"

Floor4_Ghost3_Text_1:
# 14 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "It must be kept imprisoned...$"

Floor4_Ghost3_Text_2:
# 15 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "It shall consume you.$"

Floor4_Urn1_Text_0:
# 21 "data/maps/VajraPyramidFloor4/scripts.pory"
	.string "The urn is empty.$"
