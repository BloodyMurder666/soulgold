MtSilver_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	setflag FLAG_GARBAGEFLAG
	end

MtSilver_Outside_EventScript_Sign::
	msgbox MtSilver_Outside_Text_Sign, MSGBOX_SIGN
	end

MtSilver_Outside_Text_Sign:
	.string "Mt. Silver$"
