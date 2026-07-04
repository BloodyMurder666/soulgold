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
	applymovement 1, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_1
# 32 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement 1
# 34 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_ShowIntro
# 35 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmessage
# 36 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitbuttonpress
# 37 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	closemessage
# 39 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_3
# 40 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setflag FLAG_TEMP_5
# 41 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_PrepareBattle
# 42 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special PlayTrainerEncounterMusic
# 43 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	dotrainerbattle
# 45 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	clearflag FLAG_TEMP_5
# 46 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_ShowFarewell
# 47 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmessage
# 48 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitbuttonpress
# 49 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	closemessage
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement 1, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_2
# 52 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement 1
# 53 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	removeobject 1
# 55 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setmetatile 6, 1, 0x572, FALSE
# 56 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setmetatile 6, 2, 0x416, FALSE
# 57 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	playse SE_BANG
# 58 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8004, 1
# 59 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8005, 1
# 60 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8006, 4
# 61 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_0x8007, 4
# 62 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special ShakeCamera
# 63 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitstate
# 64 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special DrawWholeMapView
# 66 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	special TitleDefense_IncrementWins
# 67 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	setvar VAR_LEAGUE_STATE, 6
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_3
# 69 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 70 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_TITLE_DEFENSE, 0
# 71 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	waitstate
# 72 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
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

# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_1:
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 31 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	face_up
	step_end

# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_2:
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_down
# 51 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	set_invisible
	step_end

# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
PokemonLeague_ChampionsRoom_TitleDefense_Begin_Movement_3:
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
# 68 "data/maps/PokemonLeague_ChampionsRoom_TitleDefense/scripts.pory"
	walk_up
	step_end
