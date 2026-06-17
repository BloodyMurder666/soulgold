VajraDesert_MapScripts::
# 2 "data/maps/VajraDesert/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/VajraDesert/scripts.pory"
	goto_if_set FLAG_SUS_DESERT_DOOR, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_2
VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 6 "data/maps/VajraDesert/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/VajraDesert/scripts.pory"
	setmetatile 37, 6, 0x4AE, FALSE
	goto VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 7 "data/maps/VajraDesert/scripts.pory"
	setmetatileinrange 82, 9, 85, 9, 0x408
# 8 "data/maps/VajraDesert/scripts.pory"
	setmetatileinrange 82, 10, 85, 10, 0x408
# 9 "data/maps/VajraDesert/scripts.pory"
	setmetatileinrange 82, 11, 85, 11, 0x408
	return


VajraDesert_ManSighing::
# 15 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_ManSighing_Text_0, MSGBOX_NPC
	return


VajraDesert_TrainerJill::
# 21 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_JILL, VajraDesert_TrainerJill_Text_0, VajraDesert_TrainerJill_Text_1
# 24 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerJill_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerRodaros::
# 28 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_RODAROS, VajraDesert_TrainerRodaros_Text_0, VajraDesert_TrainerRodaros_Text_1
# 30 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerRodaros_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerBelmare::
# 35 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_BELMARE, VajraDesert_TrainerBelmare_Text_0, VajraDesert_TrainerBelmare_Text_1
# 37 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerBelmare_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerKennedy::
# 42 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_KENNEDY, VajraDesert_TrainerKennedy_Text_0, VajraDesert_TrainerKennedy_Text_1
# 45 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerKennedy_Text_2, MSGBOX_AUTOCLOSE
	return


# 49 "data/maps/VajraDesert/scripts.pory"

# 50 "data/maps/VajraDesert/scripts.pory"
VajraDesert_BrailleRegirock:
# 51 "data/maps/VajraDesert/scripts.pory"
	.braille "TYRANT OF\n"
# 52 "data/maps/VajraDesert/scripts.pory"
	.braille "THE DESERT\n"
# 53 "data/maps/VajraDesert/scripts.pory"
	.braille "FULLY EVOLVED.$"

VajraDesert_SusDoor::
# 56 "data/maps/VajraDesert/scripts.pory"
	lock
# 57 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_SusDoor_Text_0
# 58 "data/maps/VajraDesert/scripts.pory"
	closemessage
# 59 "data/maps/VajraDesert/scripts.pory"
	braillemsgbox VajraDesert_BrailleRegirock
# 60 "data/maps/VajraDesert/scripts.pory"
	checkspecies SPECIES_TYRANITAR
# 61 "data/maps/VajraDesert/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VajraDesert_SusDoor_2
VajraDesert_SusDoor_1:
# 67 "data/maps/VajraDesert/scripts.pory"
	release
	end

VajraDesert_SusDoor_2:
# 62 "data/maps/VajraDesert/scripts.pory"
	setflag FLAG_SUS_DESERT_DOOR
# 63 "data/maps/VajraDesert/scripts.pory"
	setmetatile 37, 6, 0x4AE, FALSE
# 64 "data/maps/VajraDesert/scripts.pory"
	playse SE_EXIT
# 65 "data/maps/VajraDesert/scripts.pory"
	special DrawWholeMapView
	goto VajraDesert_SusDoor_1


VajraDesertWest_GrottoDoor::
# 72 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_GrottoDoor_Text_0, MSGBOX_YESNO
# 74 "data/maps/VajraDesert/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq VajraDesertWest_GrottoDoor_2
VajraDesertWest_GrottoDoor_1:
# 78 "data/maps/VajraDesert/scripts.pory"
	release
	end

VajraDesertWest_GrottoDoor_2:
# 75 "data/maps/VajraDesert/scripts.pory"
	warp MAP_HIDDEN_GROTTO_UNUSED, 0
# 76 "data/maps/VajraDesert/scripts.pory"
	waitstate
	goto VajraDesertWest_GrottoDoor_1


VajraDesertWest_WestSign::
# 83 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_WestSign_Text_0, MSGBOX_SIGN
	return


VajraDesertWest_EastSign::
# 88 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_EastSign_Text_0, MSGBOX_SIGN
	return


VajraDesert_ManSighing_Text_0:
# 15 "data/maps/VajraDesert/scripts.pory"
	.string "Man... The sandpits seem terrible at\n"
	.string "this moment. The path to the village\l"
	.string "is blocked. I hope it clears up soon.$"

VajraDesert_TrainerJill_Text_0:
# 21 "data/maps/VajraDesert/scripts.pory"
	.string "I read on a magazine that training in\n"
	.string "harsh environments is great for you!$"

VajraDesert_TrainerJill_Text_1:
# 23 "data/maps/VajraDesert/scripts.pory"
	.string "I wanna go home...$"

VajraDesert_TrainerJill_Text_2:
# 24 "data/maps/VajraDesert/scripts.pory"
	.string "I should've listened to mom, that\n"
	.string "magazine was really sketchy...$"

VajraDesert_TrainerRodaros_Text_0:
# 28 "data/maps/VajraDesert/scripts.pory"
	.string "Behold the might of the sandstorm!$"

VajraDesert_TrainerRodaros_Text_1:
# 29 "data/maps/VajraDesert/scripts.pory"
	.string "Gah! Sand in my mouth!$"

VajraDesert_TrainerRodaros_Text_2:
# 30 "data/maps/VajraDesert/scripts.pory"
	.string "The area can be unstable with the\n"
	.string "sandpits shifting around by phases\l"
	.string "of the moon.$"

VajraDesert_TrainerBelmare_Text_0:
# 35 "data/maps/VajraDesert/scripts.pory"
	.string "Let me show you my cutest Pokémon!$"

VajraDesert_TrainerBelmare_Text_1:
# 36 "data/maps/VajraDesert/scripts.pory"
	.string "Oh dear...$"

VajraDesert_TrainerBelmare_Text_2:
# 37 "data/maps/VajraDesert/scripts.pory"
	.string "My Maractus is absolutely most\n"
	.string "adorable Pokémon. We come here to\l"
	.string "sunbath!$"

VajraDesert_TrainerKennedy_Text_0:
# 42 "data/maps/VajraDesert/scripts.pory"
	.string "Overcoming harhest ordeals with your\n"
	.string "Pokémon is the spirit of the journey!$"

VajraDesert_TrainerKennedy_Text_1:
# 44 "data/maps/VajraDesert/scripts.pory"
	.string "Marvelous battling skills!$"

VajraDesert_TrainerKennedy_Text_2:
# 45 "data/maps/VajraDesert/scripts.pory"
	.string "I've lived in the nearby village for the\n"
	.string "past 40 years, we've never missed a\l"
	.string "training day.$"

VajraDesert_SusDoor_Text_0:
# 57 "data/maps/VajraDesert/scripts.pory"
	.string "Something is carved on the door...$"

VajraDesertWest_GrottoDoor_Text_0:
# 72 "data/maps/VajraDesert/scripts.pory"
	.string "There seems to be a small path in\n"
	.string "the sand. Enter?$"

VajraDesertWest_WestSign_Text_0:
# 83 "data/maps/VajraDesert/scripts.pory"
	.string "Vajra Desert\n"
	.string "{RIGHT_ARROW} Rinto Village$"

VajraDesertWest_EastSign_Text_0:
# 88 "data/maps/VajraDesert/scripts.pory"
	.string "{UP_ARROW}{RIGHT_ARROW} Rinto Village$"
