# 1 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 2 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_MapScripts::
# 3 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_B1F_OnLoad
# 4 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
# 5 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 7 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_OnLoad::
# 8 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	call_if_eq VAR_RUINS_OF_ALPH_PUZZLES, 8, RuinsOfAlph_B1F_OpenSecretRoomDoor
# 9 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	end
# 10 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 11 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_OpenSecretRoomDoor::
# 12 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	setmetatile 12, 1, 0x487, FALSE
# 13 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	return
# 14 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 15 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_OnFrame::
# 16 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
# 17 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.2byte 0
# 18 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 19 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_EventScript_Presence::
# 20 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	lock
# 21 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
# 22 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	closemessage
# 23 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	setvar VAR_RUINSOFALPH_STATE, 0
# 24 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	release
# 25 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	end
# 26 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 27 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 28 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_EventScript_Teacher::
# 29 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	lock
# 30 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	faceplayer
# 31 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
# 32 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	release
# 33 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	end
# 34 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 35 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_EventScript_Hiker::
# 36 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	lock
# 37 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	faceplayer
# 38 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
# 39 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	release
# 40 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	end
# 41 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 42 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_EventScript_Gramps::
# 43 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	lock
# 44 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	faceplayer
# 45 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
# 46 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	release
# 47 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	end
# 48 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 49 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_Text_Presence:
# 50 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "There is a strange presence here.$"
# 51 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 52 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_Text_Hiker:
# 53 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "This is a big room, but there's\n"
# 54 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "nothing here.$"
# 55 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 56 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_Text_Teacher:
# 57 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "This place has a mystical\n"
# 58 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "quality to it.\p"
# 59 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "It feels sort of ethereal\n"
# 60 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "even.$"
# 61 "data/maps/RuinsOfAlph_B1F/scripts.pory"

# 62 "data/maps/RuinsOfAlph_B1F/scripts.pory"
RuinsOfAlph_B1F_Text_Gramps:
# 63 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "Ancient buildings are often\n"
# 64 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "tombs of kings.\p"
# 65 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "Like the pyramids, for\n"
# 66 "data/maps/RuinsOfAlph_B1F/scripts.pory"
	.string "instance.$"
