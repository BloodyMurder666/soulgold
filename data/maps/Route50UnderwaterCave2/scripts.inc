Route50UnderwaterCave2_MapScripts::
	.byte 0


GroudonEncounter::
# 4 "data/maps/Route50UnderwaterCave2/scripts.pory"
	lock
# 5 "data/maps/Route50UnderwaterCave2/scripts.pory"
	faceplayer
# 6 "data/maps/Route50UnderwaterCave2/scripts.pory"
	bosslegendaryencounter SPECIES_GROUDON, 80, LOCALID_GROUDON, FLAG_HIDE_GROUDON, 4, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_GROUDON
# 7 "data/maps/Route50UnderwaterCave2/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GroudonEncounter_2
GroudonEncounter_1:
# 10 "data/maps/Route50UnderwaterCave2/scripts.pory"
	release
	end

GroudonEncounter_2:
# 8 "data/maps/Route50UnderwaterCave2/scripts.pory"
	finditem ITEM_RED_ORB
	goto GroudonEncounter_1

