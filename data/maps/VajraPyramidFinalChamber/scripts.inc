VajraPyramidFinalChamber_MapScripts::
	.byte 0


FinalChamber_HoopaPrison::
# 4 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	lock
# 5 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	goto_if_set FLAG_CAUGHT_HOOPA, FinalChamber_HoopaPrison_2
# 10 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	msgbox FinalChamber_HoopaPrison_Text_1, MSGBOX_YESNO
# 12 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FinalChamber_HoopaPrison_4
# 27 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	msgbox FinalChamber_HoopaPrison_Text_3
# 30 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	release
	end

FinalChamber_HoopaPrison_2:
# 6 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	msgbox FinalChamber_HoopaPrison_Text_0
# 7 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	release
	end

FinalChamber_HoopaPrison_4:
# 13 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	playmoncry SPECIES_HOOPA, 0
# 14 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	waitmoncry
# 15 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	bosslegendaryencounter SPECIES_HOOPA, 80, LOCALID_NONE, FLAG_CAUGHT_HOOPA, 3, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_HOOPA
# 16 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FinalChamber_HoopaPrison_7
# 23 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	release
	end

FinalChamber_HoopaPrison_7:
# 17 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	msgbox FinalChamber_HoopaPrison_Text_2
# 19 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	finditem ITEM_PRISON_BOTTLE
# 20 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	release
	end


FinalChamber_HoopaPrison_Text_0:
# 6 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	.string "The contraption is empty.$"

FinalChamber_HoopaPrison_Text_1:
# 10 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	.string "Something seems to be sealed inside\n"
	.string "this contraption. Release it?$"

FinalChamber_HoopaPrison_Text_2:
# 17 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	.string "Something is at the bottom of the\n"
	.string "now empty contraption.$"

FinalChamber_HoopaPrison_Text_3:
# 27 "data/maps/VajraPyramidFinalChamber/scripts.pory"
	.string "Mom did always warn about touching\n"
	.string "strange objects found deep within\l"
	.string "ancient pyramids.$"
