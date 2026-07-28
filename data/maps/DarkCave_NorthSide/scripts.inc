# 1 "data/maps/DarkCave_NorthSide/scripts.pory"

# 2 "data/maps/DarkCave_NorthSide/scripts.pory"
DarkCave2_EventScript_BlackGlasses::
# 3 "data/maps/DarkCave_NorthSide/scripts.pory"
	lock
# 4 "data/maps/DarkCave_NorthSide/scripts.pory"
	faceplayer
# 5 "data/maps/DarkCave_NorthSide/scripts.pory"
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
# 6 "data/maps/DarkCave_NorthSide/scripts.pory"
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
# 7 "data/maps/DarkCave_NorthSide/scripts.pory"
	giveitem ITEM_BLACK_GLASSES
# 8 "data/maps/DarkCave_NorthSide/scripts.pory"
	setflag FLAG_GOT_BLACK_GLASSES
# 9 "data/maps/DarkCave_NorthSide/scripts.pory"
	closemessage
# 10 "data/maps/DarkCave_NorthSide/scripts.pory"
	release
# 11 "data/maps/DarkCave_NorthSide/scripts.pory"
	end
# 12 "data/maps/DarkCave_NorthSide/scripts.pory"

# 13 "data/maps/DarkCave_NorthSide/scripts.pory"
DarkCave2_EventScript_BlackGlassesGot::
# 14 "data/maps/DarkCave_NorthSide/scripts.pory"
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
# 15 "data/maps/DarkCave_NorthSide/scripts.pory"
	closemessage
# 16 "data/maps/DarkCave_NorthSide/scripts.pory"
	release
# 17 "data/maps/DarkCave_NorthSide/scripts.pory"
	end
# 18 "data/maps/DarkCave_NorthSide/scripts.pory"

# 19 "data/maps/DarkCave_NorthSide/scripts.pory"
DarkCave2_Text_Nerd:
# 20 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Whoa! You startled me there!\p"
# 21 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "I had my Black-Glasses on, so I\n"
# 22 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "didn't notice you at all.\p"
# 23 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "What am I doing here?\p"
# 24 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Hey, don't you worry about it.\p"
# 25 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "I'll give you a pair of Black-\n"
# 26 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Glasses, so forget you saw me,\n"
# 27 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Ok?$"
# 28 "data/maps/DarkCave_NorthSide/scripts.pory"

# 29 "data/maps/DarkCave_NorthSide/scripts.pory"
DarkCave2_Text_Nerd2:
# 30 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Black-Glasses ups the power of\n"
# 31 "data/maps/DarkCave_NorthSide/scripts.pory"
    .string "Dark-type moves.$"

DarkCave_NorthSide_MapScripts::
# 35 "data/maps/DarkCave_NorthSide/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 36 "data/maps/DarkCave_NorthSide/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 39 "data/maps/DarkCave_NorthSide/scripts.pory"
	setflag FLAG_HIDE_TERRAKION
	return

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 37 "data/maps/DarkCave_NorthSide/scripts.pory"
	clearflag FLAG_HIDE_TERRAKION
	return

DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 36 "data/maps/DarkCave_NorthSide/scripts.pory"
	goto_if_unset FLAG_CAUGHT_TERRAKION, DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto DarkCave_NorthSide_MapScripts_MAP_SCRIPT_ON_TRANSITION_2


DarkCave_TerrakionEncounter::
# 45 "data/maps/DarkCave_NorthSide/scripts.pory"
	lock
# 46 "data/maps/DarkCave_NorthSide/scripts.pory"
	faceplayer
# 47 "data/maps/DarkCave_NorthSide/scripts.pory"
	bosslegendaryencounter SPECIES_TERRAKION, 80, LOCALID_TERRAKION, FLAG_HIDE_TERRAKION, 2, SPECIES_NONE, 110
# 48 "data/maps/DarkCave_NorthSide/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DarkCave_TerrakionEncounter_2
DarkCave_TerrakionEncounter_1:
# 51 "data/maps/DarkCave_NorthSide/scripts.pory"
	release
	end

DarkCave_TerrakionEncounter_2:
# 49 "data/maps/DarkCave_NorthSide/scripts.pory"
	setflag FLAG_CAUGHT_TERRAKION
	goto DarkCave_TerrakionEncounter_1

