KitakamiBorder_MapScripts::
	.byte 0


KitakamiBorder_OldLady::
# 4 "data/maps/KitakamiBorder/scripts.pory"
	msgbox KitakamiBorder_OldLady_Text_0, MSGBOX_NPC
	return


KitakamiBorder_HikerMoulder::
# 11 "data/maps/KitakamiBorder/scripts.pory"
	trainerbattle_single TRAINER_MOULDER, KitakamiBorder_HikerMoulder_Text_0, KitakamiBorder_HikerMoulder_Text_1
# 12 "data/maps/KitakamiBorder/scripts.pory"
	msgbox KitakamiBorder_HikerMoulder_Text_2, MSGBOX_AUTOCLOSE
	return


KitakamiBorder_OldLady_Text_0:
# 4 "data/maps/KitakamiBorder/scripts.pory"
	.string "I often come here to watch the valley\n"
	.string "between here and Mt. Silver. \p"
	.string "It soothes my mind.$"

KitakamiBorder_HikerMoulder_Text_0:
# 11 "data/maps/KitakamiBorder/scripts.pory"
	.string "Are you heading to visit Kitakami?$"

KitakamiBorder_HikerMoulder_Text_1:
# 11 "data/maps/KitakamiBorder/scripts.pory"
	.string "Enjoy the sights!$"

KitakamiBorder_HikerMoulder_Text_2:
# 12 "data/maps/KitakamiBorder/scripts.pory"
	.string "I visit this place almost every month!$"
