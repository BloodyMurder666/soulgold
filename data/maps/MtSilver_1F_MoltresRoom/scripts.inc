.set LOCALID_MTSILVER_MOLTRES, 1

MtSilver_1F_MoltresRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_1F_MoltresRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_1F_MoltresRoom_OnTransition: 
	callnative SetTimeBasedEncounters
	end

