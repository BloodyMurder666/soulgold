LakeOfRageCresseliaDen_MapScripts::
	.byte 0


CresseliaEncounter::
# 4 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	lock
# 5 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	faceplayer
# 6 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	legendaryencounter SPECIES_CRESSELIA, 60, LOCALID_CRESSELIA, FLAG_HIDE_CRESSELIA
# 7 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq CresseliaEncounter_2
CresseliaEncounter_1:
# 13 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	release
	end

CresseliaEncounter_2:
# 9 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq CresseliaEncounter_4
	goto CresseliaEncounter_1

CresseliaEncounter_4:
# 10 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto CresseliaEncounter_1

