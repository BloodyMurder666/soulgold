# 1 "data/maps/Route28/scripts.pory"

# 2 "data/maps/Route28/scripts.pory"
Route28_MapScripts::
# 3 "data/maps/Route28/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_OnTransition
# 4 "data/maps/Route28/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route28/scripts.pory"
	.byte 0
# 6 "data/maps/Route28/scripts.pory"

# 7 "data/maps/Route28/scripts.pory"
Route28_OnTransition: 
# 8 "data/maps/Route28/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route28/scripts.pory"
	end
# 10 "data/maps/Route28/scripts.pory"

# 11 "data/maps/Route28/scripts.pory"
Route28_EventScript_Sign::
# 12 "data/maps/Route28/scripts.pory"
	msgbox Route28_Text_Sign, MSGBOX_SIGN
# 13 "data/maps/Route28/scripts.pory"
	end
# 14 "data/maps/Route28/scripts.pory"

# 15 "data/maps/Route28/scripts.pory"
Route28_Text_Sign:
# 16 "data/maps/Route28/scripts.pory"
	.string "Route 28$"

Route28Guard::
# 20 "data/maps/Route28/scripts.pory"
	msgbox Route28Guard_Text_0, MSGBOX_NPC
	return


Route28Guard_Text_0:
# 20 "data/maps/Route28/scripts.pory"
	.string "The road beyond leads to the fierce\n"
	.string "heights of Mt Silver. Only those with\l"
	.string "explicit permission from the League\l"
	.string "are allowed to explore further.$"
