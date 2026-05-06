ValorCavern_MapScripts::
	.byte 0


ValorCavern_Azelf::
# 4 "data/maps/ValorCavern/scripts.pory"
	lock
# 5 "data/maps/ValorCavern/scripts.pory"
	faceplayer
# 6 "data/maps/ValorCavern/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 7 "data/maps/ValorCavern/scripts.pory"
	legendaryencounter SPECIES_AZELF, 50, LOCALID_VALOR_AZELF, FLAG_HIDE_AZELF
# 8 "data/maps/ValorCavern/scripts.pory"
	release
	end

