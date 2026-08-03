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
# 10 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	release
	end

Route33Kyogre_2:
# 8 "data/maps/Route33South_UnderwaterCave/scripts.pory"
	finditem ITEM_BLUE_ORB
	goto Route33Kyogre_1

