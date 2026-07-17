DarkraiInnFinalRoom_MapScripts::
# 2 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DarkraiInnFinalRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkraiInnFinalRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
	return


DarkraiEncounter::
# 8 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	lock
# 9 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	faceplayer
# 10 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 11 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	waitmoncry
# 12 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_DARKRAI
# 13 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setvar VAR_0x8005, 70
# 14 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	special BattleSetup_StartLegendaryEncounter
# 15 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	waitstate
# 16 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DarkraiEncounter_2
DarkraiEncounter_1:
# 27 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	release
	end

DarkraiEncounter_2:
# 18 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 19 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setvar VAR_0x8006, LOCALID_DARKRAI
# 20 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setvar VAR_0x8007, FLAG_HIDE_DARKRAI
# 21 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	special BattleSetup_FinishLegendaryEncounter
# 22 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 23 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq DarkraiEncounter_4
	goto DarkraiEncounter_1

DarkraiEncounter_4:
# 24 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto DarkraiEncounter_1


WarpPlayerOutDarkraiRoom::
# 32 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	warpwhitefade MAP_CHERRYGROVE_CITY, 29, 21
# 33 "data/maps/DarkraiInnFinalRoom/scripts.pory"
	waitstate
	end

