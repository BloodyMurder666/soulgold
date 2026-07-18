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
	bosslegendaryencounter SPECIES_CHIEN_PAO, 70, 1, FLAG_HIDE_CHIENPAO, 3, SPECIES_NONE, 110
# 11 "data/maps/IcePath_Depths2/scripts.pory"
	release
	end

