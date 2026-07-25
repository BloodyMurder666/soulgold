LatiTempleLobby_MapScripts::
# 2 "data/maps/LatiTempleLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LatiTempleLobby/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIAS, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/LatiTempleLobby/scripts.pory"
	setmetatile 18, 10, 0x441, FALSE
	return

LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 3 "data/maps/LatiTempleLobby/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIOS, LatiTempleLobby_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return


LobbyDoorLati::
# 10 "data/maps/LatiTempleLobby/scripts.pory"
	lock
# 11 "data/maps/LatiTempleLobby/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIAS, LobbyDoorLati_4
LobbyDoorLati_3:
# 14 "data/maps/LatiTempleLobby/scripts.pory"
	msgbox LobbyDoorLati_Text_1
LobbyDoorLati_1:
# 18 "data/maps/LatiTempleLobby/scripts.pory"
	release
	end

LobbyDoorLati_2:
# 12 "data/maps/LatiTempleLobby/scripts.pory"
	msgbox LobbyDoorLati_Text_0
	goto LobbyDoorLati_1

LobbyDoorLati_4:
# 11 "data/maps/LatiTempleLobby/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIOS, LobbyDoorLati_2
	goto LobbyDoorLati_3


LobbyDoorLati_Text_0:
# 12 "data/maps/LatiTempleLobby/scripts.pory"
	.string "The door is now open.$"

LobbyDoorLati_Text_1:
# 14 "data/maps/LatiTempleLobby/scripts.pory"
	.string "Ancient writings fill the door.\p"
	.string "It is sealed shut.$"
