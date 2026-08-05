SpearPillarTop_MapScripts::
	.byte 0


exitPortalSP::
# 4 "data/maps/SpearPillarTop/scripts.pory"
	lock
# 5 "data/maps/SpearPillarTop/scripts.pory"
	warp MAP_RUINS_OF_ALPH_SECRET_ROOM, 9, 7
# 6 "data/maps/SpearPillarTop/scripts.pory"
	waitstate
# 7 "data/maps/SpearPillarTop/scripts.pory"
	release
	end


PortalDialga::
# 12 "data/maps/SpearPillarTop/scripts.pory"
	lock
# 13 "data/maps/SpearPillarTop/scripts.pory"
	faceplayer
# 14 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalDialga_Text_0
# 17 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalDialga_Text_1, MSGBOX_YESNO
# 18 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PortalDialga_2
PortalDialga_1:
# 27 "data/maps/SpearPillarTop/scripts.pory"
	release
	end

PortalDialga_2:
# 19 "data/maps/SpearPillarTop/scripts.pory"
	bosslegendaryencounter SPECIES_DIALGA, 85, LOCALID_SPEAR_PILLAR_DIALGA_PORTAL, FLAG_HIDE_SPEAR_PILLAR_DIALGA_PORTAL, 4, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_DIALGA
# 20 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PortalDialga_4
	goto PortalDialga_1

PortalDialga_4:
# 21 "data/maps/SpearPillarTop/scripts.pory"
	goto_if_unset FLAG_GOT_ADAMANT_ORB, PortalDialga_6
	goto PortalDialga_1

PortalDialga_6:
# 22 "data/maps/SpearPillarTop/scripts.pory"
	finditem ITEM_ADAMANT_ORB
# 23 "data/maps/SpearPillarTop/scripts.pory"
	setflag FLAG_GOT_ADAMANT_ORB
	goto PortalDialga_1


PortalPalkia::
# 32 "data/maps/SpearPillarTop/scripts.pory"
	lock
# 33 "data/maps/SpearPillarTop/scripts.pory"
	faceplayer
# 34 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalPalkia_Text_0
# 37 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalDialga_Text_1, MSGBOX_YESNO
# 38 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PortalPalkia_2
PortalPalkia_1:
# 47 "data/maps/SpearPillarTop/scripts.pory"
	release
	end

PortalPalkia_2:
# 39 "data/maps/SpearPillarTop/scripts.pory"
	bosslegendaryencounter SPECIES_PALKIA, 85, LOCALID_SPEAR_PILLAR_PALKIA_PORTAL, FLAG_HIDE_SPEAR_PILLAR_PALKIA_PORTAL, 4, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_PALKIA
# 40 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PortalPalkia_4
	goto PortalPalkia_1

PortalPalkia_4:
# 41 "data/maps/SpearPillarTop/scripts.pory"
	goto_if_unset FLAG_GOT_LUSTROUS_ORB, PortalPalkia_6
	goto PortalPalkia_1

PortalPalkia_6:
# 42 "data/maps/SpearPillarTop/scripts.pory"
	finditem ITEM_LUSTROUS_ORB
# 43 "data/maps/SpearPillarTop/scripts.pory"
	setflag FLAG_GOT_LUSTROUS_ORB
	goto PortalPalkia_1


PortalGiratina::
# 52 "data/maps/SpearPillarTop/scripts.pory"
	lock
# 53 "data/maps/SpearPillarTop/scripts.pory"
	faceplayer
# 54 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalGiratina_Text_0
# 57 "data/maps/SpearPillarTop/scripts.pory"
	msgbox PortalDialga_Text_1, MSGBOX_YESNO
# 58 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PortalGiratina_2
PortalGiratina_1:
# 67 "data/maps/SpearPillarTop/scripts.pory"
	release
	end

PortalGiratina_2:
# 59 "data/maps/SpearPillarTop/scripts.pory"
	bosslegendaryencounter SPECIES_GIRATINA, 85, LOCALID_SPEAR_PILLAR_GIRATINA_PORTAL, FLAG_HIDE_SPEAR_PILLAR_GIRATINA_PORTAL, 4, SPECIES_NONE, 110, BOSS_PHASE_PROFILE_GIRATINA
# 60 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PortalGiratina_4
	goto PortalGiratina_1

PortalGiratina_4:
# 61 "data/maps/SpearPillarTop/scripts.pory"
	goto_if_unset FLAG_GOT_GRISEOUS_ORB, PortalGiratina_6
	goto PortalGiratina_1

PortalGiratina_6:
# 62 "data/maps/SpearPillarTop/scripts.pory"
	finditem ITEM_GRISEOUS_ORB
# 63 "data/maps/SpearPillarTop/scripts.pory"
	setflag FLAG_GOT_GRISEOUS_ORB
	goto PortalGiratina_1


TimeGearPrimal::
# 72 "data/maps/SpearPillarTop/scripts.pory"
	lock
# 73 "data/maps/SpearPillarTop/scripts.pory"
	faceplayer
# 74 "data/maps/SpearPillarTop/scripts.pory"
	msgbox TimeGearPrimal_Text_0
# 75 "data/maps/SpearPillarTop/scripts.pory"
	checkspecies SPECIES_GROVYLE
# 76 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TimeGearPrimal_2
TimeGearPrimal_1:
# 79 "data/maps/SpearPillarTop/scripts.pory"
	checkspecies SPECIES_DUSKNOIR
# 80 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TimeGearPrimal_5
TimeGearPrimal_4:
# 83 "data/maps/SpearPillarTop/scripts.pory"
	checkspecies SPECIES_CELEBI
# 84 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TimeGearPrimal_8
TimeGearPrimal_7:
# 87 "data/maps/SpearPillarTop/scripts.pory"
	msgbox TimeGearPrimal_Text_1, MSGBOX_YESNO
# 90 "data/maps/SpearPillarTop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TimeGearPrimal_11
TimeGearPrimal_10:
# 93 "data/maps/SpearPillarTop/scripts.pory"
	release
	end

TimeGearPrimal_2:
# 77 "data/maps/SpearPillarTop/scripts.pory"
	goto TimeGearDoesNotReact
	goto TimeGearPrimal_1

TimeGearPrimal_5:
# 81 "data/maps/SpearPillarTop/scripts.pory"
	goto TimeGearDoesNotReact
	goto TimeGearPrimal_4

TimeGearPrimal_8:
# 85 "data/maps/SpearPillarTop/scripts.pory"
	goto TimeGearDoesNotReact
	goto TimeGearPrimal_7

TimeGearPrimal_11:
# 91 "data/maps/SpearPillarTop/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_DIALGA_PRIMAL, 85, LOCALID_SPEAR_PILLAR_TIME_GEAR, FLAG_HIDE_SPEAR_PILLAR_TIME_GEAR, 4, SPECIES_NONE, 110, MOVE_ROAR_OF_TIME, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_THUNDER
	goto TimeGearPrimal_10


TimeGearDoesNotReact::
# 98 "data/maps/SpearPillarTop/scripts.pory"
	msgbox TimeGearDoesNotReact_Text_0
# 99 "data/maps/SpearPillarTop/scripts.pory"
	release
	end


PortalDialga_Text_0:
# 14 "data/maps/SpearPillarTop/scripts.pory"
	.string "You gaze deep into the portal.\p"
	.string "It shows you the sea of flowing time.$"

PortalDialga_Text_1:
# 17 "data/maps/SpearPillarTop/scripts.pory"
	.string "Touch the portal?$"

PortalPalkia_Text_0:
# 34 "data/maps/SpearPillarTop/scripts.pory"
	.string "You gaze deep into the portal.\p"
	.string "It shows you a vast and endless space.$"

PortalGiratina_Text_0:
# 54 "data/maps/SpearPillarTop/scripts.pory"
	.string "You gaze deep into the portal.\p"
	.string "It shows you a bottomless abyss.$"

TimeGearPrimal_Text_0:
# 74 "data/maps/SpearPillarTop/scripts.pory"
	.string "A strange gear lies on the ground.$"

TimeGearPrimal_Text_1:
# 87 "data/maps/SpearPillarTop/scripts.pory"
	.string "The Time Gear suddenly started glowing!\p"
	.string "Touch it?$"

TimeGearDoesNotReact_Text_0:
# 98 "data/maps/SpearPillarTop/scripts.pory"
	.string "It does not react to your presence.$"
