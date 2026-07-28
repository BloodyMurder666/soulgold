RailwayCave_3F_MapScripts::
# 2 "data/maps/RailwayCave_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/RailwayCave_3F/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 6 "data/maps/RailwayCave_3F/scripts.pory"
	setflag FLAG_HIDE_COBALION
	return

RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/RailwayCave_3F/scripts.pory"
	clearflag FLAG_HIDE_COBALION
	return

RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 3 "data/maps/RailwayCave_3F/scripts.pory"
	goto_if_unset FLAG_CAUGHT_COBALION, RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto RailwayCave_3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2


RailwayCave_Cobalion::
# 12 "data/maps/RailwayCave_3F/scripts.pory"
	lock
# 13 "data/maps/RailwayCave_3F/scripts.pory"
	faceplayer
# 14 "data/maps/RailwayCave_3F/scripts.pory"
	bosslegendaryencounter SPECIES_COBALION, 80, LOCALID_COBALION, FLAG_HIDE_COBALION, 2, SPECIES_NONE, 110
# 15 "data/maps/RailwayCave_3F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RailwayCave_Cobalion_2
RailwayCave_Cobalion_1:
# 18 "data/maps/RailwayCave_3F/scripts.pory"
	release
	end

RailwayCave_Cobalion_2:
# 16 "data/maps/RailwayCave_3F/scripts.pory"
	setflag FLAG_CAUGHT_COBALION
	goto RailwayCave_Cobalion_1

