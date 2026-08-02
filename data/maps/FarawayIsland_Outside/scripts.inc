FarawayIsland_Outside_MapScripts::
	.byte 0


FarawayIslandSailor::
# 4 "data/maps/FarawayIsland_Outside/scripts.pory"
	lock
# 5 "data/maps/FarawayIsland_Outside/scripts.pory"
	faceplayer
# 6 "data/maps/FarawayIsland_Outside/scripts.pory"
	msgbox FarawayIslandSailor_Text_0, MSGBOX_YESNO
# 7 "data/maps/FarawayIsland_Outside/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FarawayIslandSailor_2
# 12 "data/maps/FarawayIsland_Outside/scripts.pory"
	msgbox FarawayIslandSailor_Text_2
# 14 "data/maps/FarawayIsland_Outside/scripts.pory"
	closemessage
# 15 "data/maps/FarawayIsland_Outside/scripts.pory"
	hidefollower
# 16 "data/maps/FarawayIsland_Outside/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 17 "data/maps/FarawayIsland_Outside/scripts.pory"
	waitmovement 0
# 18 "data/maps/FarawayIsland_Outside/scripts.pory"
	delay 30
# 19 "data/maps/FarawayIsland_Outside/scripts.pory"
	hideobjectat LOCALID_FARAWAY_SAILOR, MAP_FARAWAY_ISLAND_OUTSIDE
# 20 "data/maps/FarawayIsland_Outside/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL_FARAWAY
# 21 "data/maps/FarawayIsland_Outside/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 22 "data/maps/FarawayIsland_Outside/scripts.pory"
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE, 8, 16
# 23 "data/maps/FarawayIsland_Outside/scripts.pory"
	waitstate
# 24 "data/maps/FarawayIsland_Outside/scripts.pory"
	release
	end

FarawayIslandSailor_2:
# 8 "data/maps/FarawayIsland_Outside/scripts.pory"
	msgbox FarawayIslandSailor_Text_1
# 9 "data/maps/FarawayIsland_Outside/scripts.pory"
	release
	end


FarawayIslandSailor_Text_0:
# 6 "data/maps/FarawayIsland_Outside/scripts.pory"
	.string "Do you want to head back to Olivine?$"

FarawayIslandSailor_Text_1:
# 8 "data/maps/FarawayIsland_Outside/scripts.pory"
	.string "Alright, I'll be waiting here.$"

FarawayIslandSailor_Text_2:
# 12 "data/maps/FarawayIsland_Outside/scripts.pory"
	.string "Aye, right!\n"
	.string "Then sail home we will!$"
