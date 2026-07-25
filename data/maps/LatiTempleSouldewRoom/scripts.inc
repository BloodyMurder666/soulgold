LatiTempleSouldewRoom_MapScripts::
	.byte 0


SouldewPlatform::
# 4 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	lock
# 5 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	goto_if_set FLAG_OBTAINED_SOULDEW, SouldewPlatform_2
# 10 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	finditem ITEM_SOUL_DEW
# 11 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	setflag FLAG_OBTAINED_SOULDEW
# 12 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	release
	end

SouldewPlatform_2:
# 6 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	msgbox SouldewPlatform_Text_0
# 7 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	release
	end


SouldewPlatform_Text_0:
# 6 "data/maps/LatiTempleSouldewRoom/scripts.pory"
	.string "The pedestal is empty.$"
