GoldenrodBattleArcadeBattleRoom_MapScripts::
# 20 "data/maps/GoldenrodBattleArcadeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodBattleArcadeBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 24 "data/maps/GoldenrodBattleArcadeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodBattleArcadeBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

GoldenrodBattleArcadeBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 22 "data/maps/GoldenrodBattleArcadeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0

GoldenrodBattleArcadeBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 26 "data/maps/GoldenrodBattleArcadeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 27 "data/maps/GoldenrodBattleArcadeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleArcade_Challenge_EventScript_BeginChallenge
	.2byte 0

