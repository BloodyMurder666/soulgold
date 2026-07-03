PokemonLeague_HallOfFame_TitleDefense_MapScripts::
# 3 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_TitleDefense_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PokemonLeague_HallOfFame_TitleDefense_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 6, TitleDefense_RegisterToHallOfFame
	.2byte 0


TitleDefense_RegisterToHallOfFame::
# 11 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	lock
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TitleDefense_RegisterToHallOfFame_Movement_0
# 13 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 14 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	delay 20
# 15 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 16 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 17 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	delay 40
# 18 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
# 20 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
# 21 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 22 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	special GameClear
# 23 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	waitstate
# 24 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	releaseall
	end


# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
TitleDefense_RegisterToHallOfFame_Movement_0:
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	walk_up
# 12 "data/maps/PokemonLeague_HallOfFame_TitleDefense/scripts.pory"
	face_up
	step_end
