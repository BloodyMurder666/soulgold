VajraDesert_MapScripts::
# 2 "data/maps/VajraDesert/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/VajraDesert/scripts.pory"
	goto_if_set FLAG_SUS_DESERT_DOOR, VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

VajraDesert_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/VajraDesert/scripts.pory"
	setmetatile 37, 6, 0x4AE, FALSE
	return


VajraDesert_ManSighing::
# 10 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_ManSighing_Text_0, MSGBOX_NPC
	return


VajraDesert_TrainerJill::
# 16 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_JILL, VajraDesert_TrainerJill_Text_0, VajraDesert_TrainerJill_Text_1
# 19 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerJill_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerRodaros::
# 23 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_RODAROS, VajraDesert_TrainerRodaros_Text_0, VajraDesert_TrainerRodaros_Text_1
# 25 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerRodaros_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerBelmare::
# 30 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_BELMARE, VajraDesert_TrainerBelmare_Text_0, VajraDesert_TrainerBelmare_Text_1
# 32 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerBelmare_Text_2, MSGBOX_AUTOCLOSE
	return


VajraDesert_TrainerKennedy::
# 37 "data/maps/VajraDesert/scripts.pory"
	trainerbattle_single TRAINER_KENNEDY, VajraDesert_TrainerKennedy_Text_0, VajraDesert_TrainerKennedy_Text_1
# 40 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_TrainerKennedy_Text_2, MSGBOX_AUTOCLOSE
	return


# 44 "data/maps/VajraDesert/scripts.pory"

# 45 "data/maps/VajraDesert/scripts.pory"
VajraDesert_BrailleRegirock:
# 46 "data/maps/VajraDesert/scripts.pory"
	.braille "TYRANT OF\n"
# 47 "data/maps/VajraDesert/scripts.pory"
	.braille "THE DESERT\n"
# 48 "data/maps/VajraDesert/scripts.pory"
	.braille "FULLY EVOLVED.$"

VajraDesert_SusDoor::
# 51 "data/maps/VajraDesert/scripts.pory"
	lock
# 52 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesert_SusDoor_Text_0
# 53 "data/maps/VajraDesert/scripts.pory"
	closemessage
# 54 "data/maps/VajraDesert/scripts.pory"
	braillemsgbox VajraDesert_BrailleRegirock
# 55 "data/maps/VajraDesert/scripts.pory"
	checkspecies SPECIES_TYRANITAR
# 56 "data/maps/VajraDesert/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VajraDesert_SusDoor_2
VajraDesert_SusDoor_1:
# 62 "data/maps/VajraDesert/scripts.pory"
	release
	end

VajraDesert_SusDoor_2:
# 57 "data/maps/VajraDesert/scripts.pory"
	setflag FLAG_SUS_DESERT_DOOR
# 58 "data/maps/VajraDesert/scripts.pory"
	setmetatile 37, 6, 0x4AE, FALSE
# 59 "data/maps/VajraDesert/scripts.pory"
	playse SE_EXIT
# 60 "data/maps/VajraDesert/scripts.pory"
	special DrawWholeMapView
	goto VajraDesert_SusDoor_1


VajraDesertWest_GrottoDoor::
# 67 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_GrottoDoor_Text_0, MSGBOX_YESNO
# 69 "data/maps/VajraDesert/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq VajraDesertWest_GrottoDoor_2
VajraDesertWest_GrottoDoor_1:
# 73 "data/maps/VajraDesert/scripts.pory"
	release
	end

VajraDesertWest_GrottoDoor_2:
# 70 "data/maps/VajraDesert/scripts.pory"
	warp MAP_HIDDEN_GROTTO_UNUSED, 0
# 71 "data/maps/VajraDesert/scripts.pory"
	waitstate
	goto VajraDesertWest_GrottoDoor_1


VajraDesertWest_WestSign::
# 78 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_WestSign_Text_0, MSGBOX_SIGN
	return


VajraDesertWest_EastSign::
# 83 "data/maps/VajraDesert/scripts.pory"
	msgbox VajraDesertWest_EastSign_Text_0, MSGBOX_SIGN
	return


VajraDesert_ManSighing_Text_0:
# 10 "data/maps/VajraDesert/scripts.pory"
	.string "Man... The sandpits seem terrible at\n"
	.string "this moment. The path to the village\l"
	.string "is blocked. I hope it clears up soon.$"

VajraDesert_TrainerJill_Text_0:
# 16 "data/maps/VajraDesert/scripts.pory"
	.string "I read on a magazine that training in\n"
	.string "harsh environments is great for you!$"

VajraDesert_TrainerJill_Text_1:
# 18 "data/maps/VajraDesert/scripts.pory"
	.string "I wanna go home...$"

VajraDesert_TrainerJill_Text_2:
# 19 "data/maps/VajraDesert/scripts.pory"
	.string "I should've listened to mom, that\n"
	.string "magazine was really sketchy...$"

VajraDesert_TrainerRodaros_Text_0:
# 23 "data/maps/VajraDesert/scripts.pory"
	.string "Behold the might of the sandstorm!$"

VajraDesert_TrainerRodaros_Text_1:
# 24 "data/maps/VajraDesert/scripts.pory"
	.string "Gah! Sand in my mouth!$"

VajraDesert_TrainerRodaros_Text_2:
# 25 "data/maps/VajraDesert/scripts.pory"
	.string "The area can be unstable with the\n"
	.string "sandpits shifting around by phases\l"
	.string "of the moon.$"

VajraDesert_TrainerBelmare_Text_0:
# 30 "data/maps/VajraDesert/scripts.pory"
	.string "Let me show you my cutest Pokémon!$"

VajraDesert_TrainerBelmare_Text_1:
# 31 "data/maps/VajraDesert/scripts.pory"
	.string "Oh dear...$"

VajraDesert_TrainerBelmare_Text_2:
# 32 "data/maps/VajraDesert/scripts.pory"
	.string "My Maractus is absolutely most\n"
	.string "adorable Pokémon. We come here to\l"
	.string "sunbath!$"

VajraDesert_TrainerKennedy_Text_0:
# 37 "data/maps/VajraDesert/scripts.pory"
	.string "Overcoming harhest ordeals with your\n"
	.string "Pokémon is the spirit of the journey!$"

VajraDesert_TrainerKennedy_Text_1:
# 39 "data/maps/VajraDesert/scripts.pory"
	.string "Marvelous battling skills!$"

VajraDesert_TrainerKennedy_Text_2:
# 40 "data/maps/VajraDesert/scripts.pory"
	.string "I've lived in the nearby village for the\n"
	.string "past 40 years, we've never missed a\l"
	.string "training day.$"

VajraDesert_SusDoor_Text_0:
# 52 "data/maps/VajraDesert/scripts.pory"
	.string "Something is carved on the door...$"

VajraDesertWest_GrottoDoor_Text_0:
# 67 "data/maps/VajraDesert/scripts.pory"
	.string "There seems to be a small path in\n"
	.string "the sand. Enter?$"

VajraDesertWest_WestSign_Text_0:
# 78 "data/maps/VajraDesert/scripts.pory"
	.string "Vajra Desert\n"
	.string "{RIGHT_ARROW} Rinto Village$"

VajraDesertWest_EastSign_Text_0:
# 83 "data/maps/VajraDesert/scripts.pory"
	.string "{UP_ARROW}{RIGHT_ARROW} Rinto Village$"
