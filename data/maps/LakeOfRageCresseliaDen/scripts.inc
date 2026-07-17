LakeOfRageCresseliaDen_MapScripts::
	.byte 0


CresseliaEncounter::
# 4 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	lock
# 5 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	faceplayer
# 6 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 7 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	waitmoncry
# 8 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_0x8004, SPECIES_CRESSELIA
# 9 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_0x8005, 60
# 10 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	special BattleSetup_StartLegendaryEncounter
# 11 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	waitstate
# 12 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq CresseliaEncounter_2
CresseliaEncounter_1:
# 23 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	release
	end

CresseliaEncounter_2:
# 14 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 15 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_0x8006, LOCALID_CRESSELIA
# 16 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_0x8007, FLAG_HIDE_CRESSELIA
# 17 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	special BattleSetup_FinishLegendaryEncounter
# 18 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 19 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq CresseliaEncounter_4
	goto CresseliaEncounter_1

CresseliaEncounter_4:
# 20 "data/maps/LakeOfRageCresseliaDen/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto CresseliaEncounter_1

