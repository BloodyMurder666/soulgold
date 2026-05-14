ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, ViridianCity_OnLoad
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnLoad::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisherNew, MSGBOX_NPC
	setflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "Hey, kid! I just had a double shot\n"
	.string "of espresso, and I am wired!\p"
	.string "I need to talk to someone, so you'll\n"
	.string "have to do!\p"
	.string "I might not look like much now, but\n"
	.string "I was an expert at catching Pokémon.\p"
	.string "Do you believe me?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Good, good. Yes, I was something\n"
	.string "out of the ordinary, let me tell\l"
	.string "you!$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "What? You little whelp!\p"
	.string "If I were just a bit younger, I'd\n"
	.string "show you a thing or two. Humph!$"

ViridianCity_Text_GrampsNearGym:
	.string "This Gym didn't have a Leader\n"
	.string "until recently.\p"
	.string "A young man from Pallet became\n"
	.string "the Leader, but he's often away.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "Are you going to battle the\n"
	.string "Leader?\p"
	.string "Good luck to you. You'll need it.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "…Zzzzz…\p" 
	.string "Yawn!\p"
	.string "I must have dozed off in the sun.\p"
	.string "What? I remind you of somebody?\p"
	.string "I don't know, here, have this.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "Yawn!\p"
	.string "I must have dozed off in the sun.\p"
	.string "…I had this dream about a Drowzee\n"
	.string "eating my dream. Weird, huh?\p"
	.string "Huh? What's this?\p"
	.string "Where did this TM come from?\p"
	.string "This is spooky! Here, you can have\n"
	.string "this TM.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "TM42 contains Dream Eater…\p"
	.string "…Zzzzz…$"

ViridianCity_Text_Youngster:
	.string "I heard that there are many items\n"
	.string "on the ground in Viridian Forest.$"

ViridianCity_Text_Sign:
	.string "Viridian City\p"
	.string "The Eternally Green Paradise$"

ViridianCity_Text_GymSign:
	.string "Viridian City Pokémon Gym\n"
	.string "Leader: …\p"
	.string "The rest of the text is illegible…$"

ViridianCity_Text_WelcomeSign:
	.string "Welcome To Viridian City,\p"
	.string "The Gateway To Indigo Plateau$"

ViridianCity_Text_TrainerHouseSign:
	.string "Trainer House\p"
	.string "The Club for Top Trainer Battles$"
