GoldenrodApartment_MapScripts::
	.byte 0


GoldenrodApartments_BasementGuard::
# 4 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_BasementGuard_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_OldLady::
# 8 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Child::
# 12 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Child_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Girl::
# 16 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Girl_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Breloom::
# 23 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 24 "data/maps/GoldenrodApartment/scripts.pory"
	playmoncry SPECIES_BRELOOM, CRY_MODE_NORMAL
# 25 "data/maps/GoldenrodApartment/scripts.pory"
	waitmoncry
# 26 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Breloom_Text_0
# 27 "data/maps/GoldenrodApartment/scripts.pory"
	waitmessage
# 28 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_Gameboykid::
# 33 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistF::
# 37 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistM::
# 41 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_LockedDoor::
# 45 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment1::
	return


GoldenrodApartments_Apartment2::
	return


GoldenrodApartments_Apartment3::
	return


GoldenrodApartments_BasementGuard_Text_0:
# 4 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Sorry kid, the basement is off limits.$"

GoldenrodApartments_OldLady_Text_0:
# 8 "data/maps/GoldenrodApartment/scripts.pory"
	.string "$"

GoldenrodApartments_Child_Text_0:
# 12 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Mom always comes home late...$"

GoldenrodApartments_Girl_Text_0:
# 16 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Our mother works at the radio tower,\n"
	.string "which makes her very busy. Luckily\l"
	.string "we have mom's Breloom to help with\l"
	.string "everything!$"

GoldenrodApartments_Breloom_Text_0:
# 26 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Breloom is joyfully doing the dishes!$"

GoldenrodApartments_LockedDoor_Text_0:
# 45 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The way seems to be barred by a metal\n"
	.string "door. A small keyhole is visible, but\l"
	.string "you have nothing that would fit to it.$"
