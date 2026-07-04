SproutTower_Basement_MapScripts::
	.byte 0


MarshadowEncounter::
# 4 "data/maps/SproutTower_Basement/scripts.pory"
	lock
# 5 "data/maps/SproutTower_Basement/scripts.pory"
	faceplayer
# 6 "data/maps/SproutTower_Basement/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 7 "data/maps/SproutTower_Basement/scripts.pory"
	legendaryencounter SPECIES_MARSHADOW, 50, LOCALID_MARSHADOW, FLAG_HIDE_MARSHADOW
# 8 "data/maps/SproutTower_Basement/scripts.pory"
	release
	end


BasementSage::
# 13 "data/maps/SproutTower_Basement/scripts.pory"
	msgbox BasementSage_Text_0, MSGBOX_NPC
	return


BasementSage_Text_0:
# 13 "data/maps/SproutTower_Basement/scripts.pory"
	.string "Guarding Marshadow has been one of our\n"
	.string "secret tasks for a very long time.$"
