Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "What's this flyer?\p"
	.string "… Uncouth trainers have been\n"
	.string "holding battles in the\l"
	.string "Underground Path.\p"
	.string "Because of rising complaints by\n"
	.string "local residents, the Underground\l"
	.string "Path has been sealed indefinitely.\p"
	.string "Celadon Police$"

Route7_Text_LockedDoor:
	.string "It's locked…$"

