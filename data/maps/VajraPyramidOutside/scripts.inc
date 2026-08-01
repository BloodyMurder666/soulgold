VajraPyramidOutside_MapScripts::
# 2 "data/maps/VajraPyramidOutside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 9 "data/maps/VajraPyramidOutside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 6 "data/maps/VajraPyramidOutside/scripts.pory"
	setflag FLAG_HIDE_PYRAMIDOUT_SCIENTIST
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/VajraPyramidOutside/scripts.pory"
	clearflag FLAG_HIDE_PYRAMIDOUT_SCIENTIST
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD:
# 10 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 11 "data/maps/VajraPyramidOutside/scripts.pory"
	setmetatile 16, 6, 0x4D5, FALSE
	return

VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 10 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return


VajraPyramidOutside_Door::
# 17 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_Door_3
VajraPyramidOutside_Door_2:
# 22 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_Door_Text_1, MSGBOX_SIGN
	return

VajraPyramidOutside_Door_1:
# 18 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_Door_Text_0, MSGBOX_SIGN
	return

VajraPyramidOutside_Door_3:
# 17 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, VajraPyramidOutside_Door_1
	goto VajraPyramidOutside_Door_2


VajraPyramidOutside_ScientistPostgame::
# 27 "data/maps/VajraPyramidOutside/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, VajraPyramidOutside_ScientistPostgame_1
# 34 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_ScientistPostgame_Text_1, MSGBOX_NPC
	return

VajraPyramidOutside_ScientistPostgame_1:
# 28 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_ScientistPostgame_Text_0, MSGBOX_NPC
	return


VajraPyramidOutside_ScientistsTinkaton::
# 44 "data/maps/VajraPyramidOutside/scripts.pory"
	lock
# 45 "data/maps/VajraPyramidOutside/scripts.pory"
	faceplayer
# 46 "data/maps/VajraPyramidOutside/scripts.pory"
	playmoncry SPECIES_TINKATON, 0
# 47 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_ScientistsTinkaton_Text_0
# 48 "data/maps/VajraPyramidOutside/scripts.pory"
	waitmoncry
# 49 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_ScientistsTinkaton_Text_1
# 51 "data/maps/VajraPyramidOutside/scripts.pory"
	release
	end


VajraPyramidOutside_RuinManiac::
# 56 "data/maps/VajraPyramidOutside/scripts.pory"
	msgbox VajraPyramidOutside_RuinManiac_Text_0, MSGBOX_NPC
	return


VajraPyramidOutside_Door_Text_0:
# 18 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "The door has been busted open by\n"
	.string "repeated exposure to something\l"
	.string "blunt.$"

VajraPyramidOutside_Door_Text_1:
# 22 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "The door is sealed shut tightly.$"

VajraPyramidOutside_ScientistPostgame_Text_0:
# 28 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "We finally managed to break down the\n"
	.string "door to the Pyramid thanks to the\l"
	.string "Tinkaton you gave us!\p"
	.string "Please, feel free to explore it first!$"

VajraPyramidOutside_ScientistPostgame_Text_1:
# 34 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "We've started working on getting that\n"
	.string "door opened with the help of your\l"
	.string "Tinkaton! \p"
	.string "It might take some time, so\n"
	.string "you should come back later.$"

VajraPyramidOutside_ScientistsTinkaton_Text_0:
# 47 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "Tinkaton: Tinktii!$"

VajraPyramidOutside_ScientistsTinkaton_Text_1:
# 49 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "Your old Tinkaton seems to be having\n"
	.string "fun here!$"

VajraPyramidOutside_RuinManiac_Text_0:
# 56 "data/maps/VajraPyramidOutside/scripts.pory"
	.string "There's mystery here waiting to be\n"
	.string "uncovered! I can sense it!$"
