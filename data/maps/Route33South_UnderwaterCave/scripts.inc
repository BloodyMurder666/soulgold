Route33South_UnderwaterCave_MapScripts::
	.byte 0


Route33Kyogre::
# 4 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	lock
# 5 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	faceplayer
# 6 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	bosslegendaryencounter SPECIES_KYOGRE, 80, LOCALID_KYOGRE, FLAG_HIDE_KYOGRE, 4, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_KYOGRE
# 7 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route33Kyogre_2
Route33Kyogre_1:
# 17 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	release
	end

Route33Kyogre_2:
# 8 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	goto_if_unset FLAG_GOT_BLUEORB, Route33Kyogre_5
Route33Kyogre_4:
# 12 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	goto_if_unset FLAG_ONETIME_KYOGRE, Route33Kyogre_7
	goto Route33Kyogre_1

Route33Kyogre_5:
# 9 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	finditem ITEM_BLUE_ORB
# 10 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	setflag FLAG_GOT_BLUEORB
	goto Route33Kyogre_4

Route33Kyogre_7:
# 13 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	addvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
# 14 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	setflag FLAG_ONETIME_KYOGRE
	goto Route33Kyogre_1

