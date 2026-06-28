DeepIlexForest_MapScripts::
	.byte 0


Ilex_Larvesta::
# 5 "data/maps/DeepIlexForest/scripts.pory"
	lock
# 6 "data/maps/DeepIlexForest/scripts.pory"
	faceplayer
# 7 "data/maps/DeepIlexForest/scripts.pory"
	legendaryencounter SPECIES_LARVESTA, 30, LOCALID_ILEX_LARVESTA, FLAG_HIDE_LARVESTA
# 8 "data/maps/DeepIlexForest/scripts.pory"
	release
	end


DeepIlex_Hex::
# 13 "data/maps/DeepIlexForest/scripts.pory"
	msgbox DeepIlex_Hex_Text_0, MSGBOX_NPC
	return


DeepIlex_Hex_Text_0:
# 13 "data/maps/DeepIlexForest/scripts.pory"
	.string "Engineers from Hoenn tried to\n"
	.string "build another Battle Factory here.\p"
	.string "They were chased away by the\n"
	.string "guardian of the forest before\l"
	.string "they made much progress.$"
