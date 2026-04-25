.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Where in the world is Viridian's Gym\n"
	.string "Leader? I wanted to challenge him.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "There are no Gym Trainers at the\n"
	.string "Viridian Gym.\p"
	.string "The Leader claims his policy is to\n"
	.string "win without having any underlings.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "I heard that the Gym in Cinnabar is\n"
	.string "gone.\p"
	.string "I wonder what became of Blaine, the\n"
	.string "Gym Leader.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "My dream is to become a Gym Leader.$"
