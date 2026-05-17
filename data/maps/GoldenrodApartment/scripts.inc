GoldenrodApartment_MapScripts::
	.byte 0


GoldenrodApartments_BasementGuard::
# 4 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_BasementGuard_Text_0
# 10 "data/maps/GoldenrodApartment/scripts.pory"
	checkspecies SPECIES_ROTOM
# 11 "data/maps/GoldenrodApartment/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodApartments_BasementGuard_2
# 15 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_BasementGuard_Text_1
# 21 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 22 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_HIDE_GROD_APARTMENTS_GUARD
# 23 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 24 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_APARTMENT_GUARD
# 25 "data/maps/GoldenrodApartment/scripts.pory"
	delay 60
# 26 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 27 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end

GoldenrodApartments_BasementGuard_2:
# 12 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_OldLady::
# 32 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Child::
# 38 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Child_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Girl::
# 42 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Girl_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Breloom::
# 49 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 50 "data/maps/GoldenrodApartment/scripts.pory"
	playmoncry SPECIES_BRELOOM, CRY_MODE_NORMAL
# 51 "data/maps/GoldenrodApartment/scripts.pory"
	waitmoncry
# 52 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Breloom_Text_0
# 53 "data/maps/GoldenrodApartment/scripts.pory"
	waitmessage
# 54 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_Gameboykid::
# 59 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Gameboykid_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistF::
# 65 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_ScientistF_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistM::
# 71 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_ScientistM_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_LockedDoor::
# 77 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment1::
# 83 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment1_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment2::
# 87 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment2_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment3::
# 91 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment3_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_BasementGuard_Text_0:
# 4 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Sorry but this stairway leads to the\n"
	.string "apartments storage. Besides, I don't\l"
	.string "think there's any reason why a trainer\l"
	.string "would want to check out old house\l"
	.string "appliances that have been abandoned\l"
	.string "due to rampant consumerism.$"

GoldenrodApartments_BasementGuard_Text_1:
# 15 "data/maps/GoldenrodApartment/scripts.pory"
	.string "...What? You have a Rotom that wants\n"
	.string "check out the appliances? Well... \l"
	.string "I suppose the tenants wouldn't\l"
	.string "use them anyway. Let's say I never\l"
	.string "saw you if anyone asks. I'm going to\l"
	.string "have a coffee break.$"

GoldenrodApartments_OldLady_Text_0:
# 32 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The city has been expanding a lot in\n"
	.string "recent years. I fear I've been left\l"
	.string "behind by the rapid changes.$"

GoldenrodApartments_Child_Text_0:
# 38 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Mom always comes home late...$"

GoldenrodApartments_Girl_Text_0:
# 42 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Our mother works at the radio tower,\n"
	.string "which makes her very busy. Luckily\l"
	.string "we have mom's Breloom to help with\l"
	.string "everything!$"

GoldenrodApartments_Breloom_Text_0:
# 52 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Breloom is joyfully doing the dishes!$"

GoldenrodApartments_Gameboykid_Text_0:
# 59 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Strange noises can be heard from the\n"
	.string "floor above this. I have never seen\l"
	.string "anyone who lives there though, strange.$"

GoldenrodApartments_ScientistF_Text_0:
# 65 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod recently invited scientists\n"
	.string "from other regions to the Radio Tower\l"
	.string "for a business meeting.$"

GoldenrodApartments_ScientistM_Text_0:
# 71 "data/maps/GoldenrodApartment/scripts.pory"
	.string "These SkyBNB apartments are barely\n"
	.string "equipped with the most basics of\l"
	.string "tools... How vexing.$"

GoldenrodApartments_LockedDoor_Text_0:
# 77 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The way seems to be barred by a metal\n"
	.string "door. A small keyhole is visible, but\l"
	.string "you have nothing that would fit to it.$"

GoldenrodApartments_Apartment1_Text_0:
# 83 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F1$"

GoldenrodApartments_Apartment2_Text_0:
# 87 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F2$"

GoldenrodApartments_Apartment3_Text_0:
# 91 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F3$"
