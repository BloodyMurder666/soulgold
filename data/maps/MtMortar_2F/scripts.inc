MtMortar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_2F_EventScript_Nerd::
	trainerbattle_single TRAINER_HUGH MtMortar_2F_Text_SupernerdHughSeen, MtMortar_2F_Text_SupernerdHughBeaten
	msgbox MtMortar_2F_Text_SupernerdHughAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_2F_Text_SupernerdHughSeen::
	.string "Yo! Markus!$"

MtMortar_2F_Text_SupernerdHughBeaten:
	.string "Sorry, my mistake.\n"
	.string "I misjudged you.$"

MtMortar_2F_Text_SupernerdHughAfter:
	.string "I'm investigating Mt.Mortar,\n"
	.string "but my pal's gone Awol.\p"
	.string "Have you seen a trainer who\n"
	.string "has a Slowpoke that can use\l"
	.string "Strength?$"
