BattleArcade_Hallway_MapScripts::
# 6 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD:
# 8 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 9 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	return

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script_2 VAR_TEMP_0, FALSE, BattleArcade_Hallway_EventScript_EnterCorridor
	.2byte 0

