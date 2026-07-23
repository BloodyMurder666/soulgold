Rinto_PoemonCenter_MapScripts::
# 2 "data/maps/Rinto_PoemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Rinto_PoemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Rinto_PoemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Rinto_PoemonCenter/scripts.pory"
	setflag FLAG_TEMP_1
# 4 "data/maps/Rinto_PoemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_RINTO_VILLAGE_POKEMON_CENTER
	end


RintoPC_Gbakid1::
# 10 "data/maps/Rinto_PoemonCenter/scripts.pory"
	msgbox RintoPC_Gbakid1_Text_0, MSGBOX_NPC
	return


RintoPC_Battlegirl::
# 15 "data/maps/Rinto_PoemonCenter/scripts.pory"
	msgbox RintoPC_Battlegirl_Text_0, MSGBOX_NPC
	return


RintoPC_Hiker::
# 20 "data/maps/Rinto_PoemonCenter/scripts.pory"
	msgbox RintoPC_Hiker_Text_0, MSGBOX_NPC
	return


RintoPC_Gbakid1_Text_0:
# 10 "data/maps/Rinto_PoemonCenter/scripts.pory"
	.string "I wish I could fight against my friends\n"
	.string "around the globe.$"

RintoPC_Battlegirl_Text_0:
# 15 "data/maps/Rinto_PoemonCenter/scripts.pory"
	.string "The sandstorms make travelling into\n"
	.string "this village difficult at times.$"

RintoPC_Hiker_Text_0:
# 20 "data/maps/Rinto_PoemonCenter/scripts.pory"
	.string "I heard that an unusual looking pair of\n"
	.string "flying Pokémon have been spotted\l"
	.string "nearby.$"
