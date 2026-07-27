MeteorCave2_MapScripts::
	.byte 0


IronValiantEnc::
# 5 "data/maps/MeteorCave2/scripts.pory"
	lock
# 6 "data/maps/MeteorCave2/scripts.pory"
	faceplayer
# 7 "data/maps/MeteorCave2/scripts.pory"
	legendaryencounter SPECIES_IRON_VALIANT, 70, LOCALID_IRON_VALIANT, FLAG_HIDE_IRONVALIANT
# 8 "data/maps/MeteorCave2/scripts.pory"
	release
	end


AncientWallMet::
# 13 "data/maps/MeteorCave2/scripts.pory"
	msgbox AncientWallMet_Text_0, MSGBOX_SIGN
	return


AncientWallMet_Text_0:
# 13 "data/maps/MeteorCave2/scripts.pory"
	.string "Ancient writing covers the wall.$"
