PokemonLeague_ChampionsRoom_TitleDefense_MapScripts::
# 5 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_ChampionsRoom_TitleDefense_OnTransition
# 7 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_TitleDefense_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PokemonLeague_ChampionsRoom_TitleDefense_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, PokemonLeague_ChampionsRoom_TitleDefense_Begin
	.2byte 0


PokemonLeague_ChampionsRoom_TitleDefense_OnTransition::
# 15 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_1
# 16 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_SelectChallenger
	end


PokemonLeague_ChampionsRoom_TitleDefense_Begin::
# 22 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	lockall
# 23 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_TEMP_0, 1
# 24 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_2
# 25 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special DrawWholeMapView
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_0
# 27 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 29 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	clearflag FLAG_TEMP_1
# 30 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	addobject 1
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	playse SE_EXIT
# 32 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitse
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement 1, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_1
# 34 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement 1
# 36 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_ShowIntro
# 37 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmessage
# 38 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitbuttonpress
# 39 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	closemessage
# 41 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_3
# 42 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_5
# 43 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_PrepareBattle
# 44 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special PlayTrainerEncounterMusic
# 45 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	dotrainerbattle
# 47 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	clearflag FLAG_TEMP_5
# 48 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_ShowFarewell
# 49 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmessage
# 50 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitbuttonpress
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	closemessage
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement 1, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_2
# 54 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement 1
# 55 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	removeobject 1
# 57 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setmetatile 6, 1, 0x572, FALSE
# 58 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setmetatile 6, 2, 0x416, FALSE
# 59 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	playse SE_BANG
# 60 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8004, 1
# 61 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8005, 1
# 62 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8006, 4
# 63 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8007, 4
# 64 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special ShakeCamera
# 65 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitstate
# 66 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special DrawWholeMapView
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_IncrementWins
# 69 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_LEAGUE_STATE, 6
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_3
# 71 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 72 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_TITLE_DEFENSE, 0
# 73 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitstate
# 74 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	releaseall
	end


ChampionRoom_DefendTitleTrigger::
	end


# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_0:
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 26 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	face_down
	step_end

# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_1:
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 33 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	face_up
	step_end

# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_2:
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	set_invisible
	step_end

# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_3:
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
	step_end
