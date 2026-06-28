# 1 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 2 "data/maps/OlivineCity_PortOutside/scripts.pory"
.set LOCALID_OLIVINE_SABRINA, 3
# 3 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 4 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_MapScripts::
# 5 "data/maps/OlivineCity_PortOutside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
# 6 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.byte 0
# 7 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 8 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_EventScript_Sabrina::
# 9 "data/maps/OlivineCity_PortOutside/scripts.pory"
    lock
# 10 "data/maps/OlivineCity_PortOutside/scripts.pory"
    faceplayer
# 11 "data/maps/OlivineCity_PortOutside/scripts.pory"
    msgbox OlivineCity_PortOutside_Text_Sabrina, MSGBOX_DEFAULT
# 12 "data/maps/OlivineCity_PortOutside/scripts.pory"
    closemessage
# 13 "data/maps/OlivineCity_PortOutside/scripts.pory"
    fadescreenswapbuffers FADE_TO_BLACK
# 14 "data/maps/OlivineCity_PortOutside/scripts.pory"
    setflag FLAG_HIDE_OLIVINE_SABRINA
# 15 "data/maps/OlivineCity_PortOutside/scripts.pory"
    removeobject LOCALID_OLIVINE_SABRINA
# 16 "data/maps/OlivineCity_PortOutside/scripts.pory"
    fadescreenswapbuffers FADE_FROM_BLACK
# 17 "data/maps/OlivineCity_PortOutside/scripts.pory"
    clearflag FLAG_HIDE_DOJO_SABRINA
# 18 "data/maps/OlivineCity_PortOutside/scripts.pory"
    release
# 19 "data/maps/OlivineCity_PortOutside/scripts.pory"
    end
# 20 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 21 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_Text_Sabrina:
# 22 "data/maps/OlivineCity_PortOutside/scripts.pory"
    .string "Sabrina: Out of the blue,\n"
# 23 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "I get the urge to see the ocean.\p"
# 24 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "I'll see you at the Fighting\n"
# 25 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "Dojo.$"
# 26 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 27 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_EventScript_Fisherman1::
# 28 "data/maps/OlivineCity_PortOutside/scripts.pory"
	lock
# 29 "data/maps/OlivineCity_PortOutside/scripts.pory"
	faceplayer
# 30 "data/maps/OlivineCity_PortOutside/scripts.pory"
	msgbox OlivineCity_PortOutside_Text_PortFisherman1, MSGBOX_DEFAULT
# 31 "data/maps/OlivineCity_PortOutside/scripts.pory"
	closemessage
# 32 "data/maps/OlivineCity_PortOutside/scripts.pory"
	release
# 33 "data/maps/OlivineCity_PortOutside/scripts.pory"
	end
# 34 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 35 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_EventScript_Fisherman2::
# 36 "data/maps/OlivineCity_PortOutside/scripts.pory"
	lock
# 37 "data/maps/OlivineCity_PortOutside/scripts.pory"
	faceplayer
# 38 "data/maps/OlivineCity_PortOutside/scripts.pory"
	msgbox OlivineCity_PortOutside_Text_Fisherman2, MSGBOX_DEFAULT
# 39 "data/maps/OlivineCity_PortOutside/scripts.pory"
	closemessage
# 40 "data/maps/OlivineCity_PortOutside/scripts.pory"
	release
# 41 "data/maps/OlivineCity_PortOutside/scripts.pory"
	end
# 42 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 43 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_Text_PortFisherman1:
# 44 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "Fast Ship S.S.Aqua used to sail to\n"
# 45 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "Kanto on Mondays and Fridays. But\l"
# 46 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "now, it sails almost constantly!$"
# 47 "data/maps/OlivineCity_PortOutside/scripts.pory"

# 48 "data/maps/OlivineCity_PortOutside/scripts.pory"
OlivineCity_PortOutside_Text_Fisherman2:
# 49 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "Aw yeah, I'm fishin'.$"

OlivinePortFisher::
# 53 "data/maps/OlivineCity_PortOutside/scripts.pory"
	msgbox OlivinePortFisher_Text_0, MSGBOX_NPC
	return


OlivinePortFisher_Text_0:
# 53 "data/maps/OlivineCity_PortOutside/scripts.pory"
	.string "I heard the ship broke down,\n"
	.string "I wonder when it will sail again.$"
