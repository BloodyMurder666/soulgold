VerityCavern_MapScripts::
	.byte 0


VerityCavern_Mesprit::
# 4 "data/maps/VerityCavern/scripts.pory"
	lock
# 5 "data/maps/VerityCavern/scripts.pory"
	faceplayer
# 6 "data/maps/VerityCavern/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 7 "data/maps/VerityCavern/scripts.pory"
	legendaryencounter SPECIES_MESPRIT, 50, LOCALID_VERITY_MESPRIT, FLAG_HIDE_MESPRIT
# 8 "data/maps/VerityCavern/scripts.pory"
	release
	end

