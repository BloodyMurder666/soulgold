GoldenrodBattleArcadeHallway_MapScripts::
# 5 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodBattleArcadeHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

GoldenrodBattleArcadeHallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	map_script_2 VAR_TEMP_0, FALSE, BattleArcade_Hallway_EventScript_EnterCorridor
	.2byte 0


BattleArcade_Hallway_EventScript_EnterCorridor::
# 13 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	setvar VAR_TEMP_0, TRUE
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	applymovement LOCALID_HALLWAY_ATTENDANT, BattleArcade_Hallway_EventScript_EnterCorridor_Movement_0
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_Hallway_EventScript_EnterCorridor_Movement_1
# 16 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	waitmovement LOCALID_HALLWAY_ATTENDANT
# 17 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 18 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	setvar VAR_TEMP_0, FALSE
# 19 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	warp MAP_GOLDENROD_BATTLE_ARCADE_BATTLE_ROOM, 7, 16
# 20 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	waitstate
	end


# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
BattleArcade_Hallway_EventScript_EnterCorridor_Movement_0:
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_up
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_up
# 14 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	set_invisible
	step_end

# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
BattleArcade_Hallway_EventScript_EnterCorridor_Movement_1:
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_right
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_up
# 15 "data/maps/GoldenrodBattleArcadeHallway/scripts.pory"
	walk_up
	step_end
