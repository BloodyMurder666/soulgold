# 1 "data/maps/DarkraiInn1/scripts.pory"

# 2 "data/maps/DarkraiInn1/scripts.pory"
DarkraiInn1_MapScripts::
# 3 "data/maps/DarkraiInn1/scripts.pory"
	.byte 0

Inn_LockedDoor::
# 8 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_LockedDoor_Text_0, MSGBOX_NPC
	return


FoggyWindow_Inn::
# 13 "data/maps/DarkraiInn1/scripts.pory"
	msgbox FoggyWindow_Inn_Text_0, MSGBOX_NPC
	return


Inn_LockedDoor_Text_0:
# 8 "data/maps/DarkraiInn1/scripts.pory"
	.string "You try to open the door but it\n"
	.string "seems to be locked.$"

FoggyWindow_Inn_Text_0:
# 13 "data/maps/DarkraiInn1/scripts.pory"
	.string "You peek out of the window...\p"
	.string "A strange fog seems to cover your\n"
	.string "view of the outside world.$"
