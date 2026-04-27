# 1 "data/maps/IcePath_Depths2/scripts.pory"

# 2 "data/maps/IcePath_Depths2/scripts.pory"
IcePath_Depths2_MapScripts::
# 3 "data/maps/IcePath_Depths2/scripts.pory"
	.byte 0

icePathDepthsChienPao::
# 8 "data/maps/IcePath_Depths2/scripts.pory"
	lock
# 9 "data/maps/IcePath_Depths2/scripts.pory"
	faceplayer
# 10 "data/maps/IcePath_Depths2/scripts.pory"
	waitse
# 11 "data/maps/IcePath_Depths2/scripts.pory"
	playmoncry SPECIES_CHIEN_PAO, CRY_MODE_ENCOUNTER
# 12 "data/maps/IcePath_Depths2/scripts.pory"
	delay 40
# 13 "data/maps/IcePath_Depths2/scripts.pory"
	waitmoncry
# 14 "data/maps/IcePath_Depths2/scripts.pory"
	setwildbattle SPECIES_CHIEN_PAO, 50
# 15 "data/maps/IcePath_Depths2/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 16 "data/maps/IcePath_Depths2/scripts.pory"
	waitstate
# 17 "data/maps/IcePath_Depths2/scripts.pory"
	calculatemonstats
# 18 "data/maps/IcePath_Depths2/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 19 "data/maps/IcePath_Depths2/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq icePathDepthsChienPao_2
# 24 "data/maps/IcePath_Depths2/scripts.pory"
	setflag FLAG_HIDE_CHIENPAO
# 25 "data/maps/IcePath_Depths2/scripts.pory"
	removeobject 1
# 26 "data/maps/IcePath_Depths2/scripts.pory"
	release
	end

icePathDepthsChienPao_2:
# 20 "data/maps/IcePath_Depths2/scripts.pory"
	setflag FLAG_HIDE_CHIENPAO
# 21 "data/maps/IcePath_Depths2/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
	end

