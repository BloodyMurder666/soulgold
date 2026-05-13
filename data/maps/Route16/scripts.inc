Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route16_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route16_EventScript_Sign::
	msgbox Route16_Text_Sign, MSGBOX_SIGN
	end

Route16_Text_Sign:
	.string "Cycling Road\n"
	.string "Downhill Coasing\l"
	.string "All The Way Down!$"
