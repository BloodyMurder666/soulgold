LakeOfRageCresseliaDen_MapScripts::
	.byte 0


CresseliaEncounter::
# 4 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	lock
# 5 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	faceplayer
# 7 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_CRESSELIA, 60, LOCALID_CRESSELIA, FLAG_HIDE_CRESSELIA, 3, SPECIES_NONE, 110, MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_TOXIC, MOVE_CALM_MIND
# 20 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq CresseliaEncounter_2
CresseliaEncounter_1:
# 26 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	release
	end

CresseliaEncounter_2:
# 21 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq CresseliaEncounter_4
	goto CresseliaEncounter_1

CresseliaEncounter_4:
# 22 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto CresseliaEncounter_1

