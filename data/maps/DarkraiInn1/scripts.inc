DarkraiInn1_MapScripts::
# 2 "data/maps/DarkraiInn1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 5 "data/maps/DarkraiInn1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/DarkraiInn1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/DarkraiInn1/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 6 "data/maps/DarkraiInn1/scripts.pory"
	goto_if_set FLAG_OPEN_INN_DOOR, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 7 "data/maps/DarkraiInn1/scripts.pory"
	setmetatile 24, 3, 0x03C, FALSE
# 8 "data/maps/DarkraiInn1/scripts.pory"
	setmetatile 24, 2, 0x034, FALSE
	return

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/DarkraiInn1/scripts.pory"
	map_script_2 VAR_DARKRAI_INN_PROGRESS, 0, DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 14 "data/maps/DarkraiInn1/scripts.pory"
	lock
# 15 "data/maps/DarkraiInn1/scripts.pory"
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 16 "data/maps/DarkraiInn1/scripts.pory"
	closemessage
# 17 "data/maps/DarkraiInn1/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 28, 15, DIR_NORTH
# 18 "data/maps/DarkraiInn1/scripts.pory"
	waitmovement 0
# 19 "data/maps/DarkraiInn1/scripts.pory"
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
# 23 "data/maps/DarkraiInn1/scripts.pory"
	playfanfare MUS_HG_OBTAIN_ITEM
# 24 "data/maps/DarkraiInn1/scripts.pory"
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
# 25 "data/maps/DarkraiInn1/scripts.pory"
	waitfanfare
# 26 "data/maps/DarkraiInn1/scripts.pory"
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
# 29 "data/maps/DarkraiInn1/scripts.pory"
	msgbox DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
# 30 "data/maps/DarkraiInn1/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 1
# 31 "data/maps/DarkraiInn1/scripts.pory"
	release
	end


Inn_Door404::
# 38 "data/maps/DarkraiInn1/scripts.pory"
	lock
# 39 "data/maps/DarkraiInn1/scripts.pory"
	goto_if_set FLAG_OPEN_INN_DOOR, Inn_Door404_2
# 44 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_Door404_Text_1
# 49 "data/maps/DarkraiInn1/scripts.pory"
	setmetatile 24, 3, 0x03C, FALSE
# 50 "data/maps/DarkraiInn1/scripts.pory"
	setmetatile 24, 2, 0x034, FALSE
# 51 "data/maps/DarkraiInn1/scripts.pory"
	playse SE_EXIT
# 52 "data/maps/DarkraiInn1/scripts.pory"
	special DrawWholeMapView
# 53 "data/maps/DarkraiInn1/scripts.pory"
	setflag FLAG_OPEN_INN_DOOR
# 54 "data/maps/DarkraiInn1/scripts.pory"
	release
	end

# 57 "data/maps/DarkraiInn1/scripts.pory"
	release
	end

Inn_Door404_2:
# 40 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_Door404_Text_0
# 41 "data/maps/DarkraiInn1/scripts.pory"
	release
	end


Inn_Keeper::
# 62 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_Keeper_Text_0, MSGBOX_NPC
	return


Inn_AnimalHead::
# 67 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_AnimalHead_Text_0, MSGBOX_NPC
	return


Inn_LockedDoor::
# 77 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_LockedDoor_Text_0, MSGBOX_NPC
	return


FoggyWindow_Inn::
# 82 "data/maps/DarkraiInn1/scripts.pory"
	msgbox FoggyWindow_Inn_Text_0, MSGBOX_NPC
	return


Inn_OrnatePiano::
# 90 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_OrnatePiano_Text_0, MSGBOX_SIGN
	return


Inn_Drums::
# 95 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_Drums_Text_0, MSGBOX_SIGN
	return


Inn_LockedSafe::
# 99 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_LockedSafe_Text_0, MSGBOX_SIGN
	return


Inn_NoteOnWall::
# 104 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_NoteOnWall_Text_0, MSGBOX_SIGN
	return


Inn_PapersOnWall::
# 109 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_PapersOnWall_Text_0, MSGBOX_SIGN
	return


Inn_TryingToExit::
# 114 "data/maps/DarkraiInn1/scripts.pory"
	lock
# 115 "data/maps/DarkraiInn1/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 116 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_TryingToExit_Text_0
# 118 "data/maps/DarkraiInn1/scripts.pory"
	closemessage
# 119 "data/maps/DarkraiInn1/scripts.pory"
	applymovement LOCALID_PLAYER, Inn_TryingToExit_Movement_0
# 120 "data/maps/DarkraiInn1/scripts.pory"
	waitmovement
# 121 "data/maps/DarkraiInn1/scripts.pory"
	release
	end


Inn_ReceptionPhone::
# 126 "data/maps/DarkraiInn1/scripts.pory"
	msgbox Inn_ReceptionPhone_Text_0, MSGBOX_SIGN
	return


# 119 "data/maps/DarkraiInn1/scripts.pory"
Inn_TryingToExit_Movement_0:
# 119 "data/maps/DarkraiInn1/scripts.pory"
	walk_up
	step_end

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 15 "data/maps/DarkraiInn1/scripts.pory"
	.string "Welcome, honored guest!$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 19 "data/maps/DarkraiInn1/scripts.pory"
	.string "We are delighted to have you stay\n"
	.string "at our humble inn. \p"
	.string "Here is your room key.$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
# 24 "data/maps/DarkraiInn1/scripts.pory"
	.string "{PLAYER} obtained the Moon Key!$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
# 26 "data/maps/DarkraiInn1/scripts.pory"
	.string "Your room is number 404, take the stairs\n"
	.string "on your left and it will be right in\l"
	.string "front of you.$"

DarkraiInn1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
# 29 "data/maps/DarkraiInn1/scripts.pory"
	.string "We hope you enjoy your stay.$"

Inn_Door404_Text_0:
# 40 "data/maps/DarkraiInn1/scripts.pory"
	.string "The door to your room is now open.$"

Inn_Door404_Text_1:
# 44 "data/maps/DarkraiInn1/scripts.pory"
	.string "Room 404\p"
	.string "You use your key to unlock the door,\n"
	.string "however the key is now stuck in the\l"
	.string "lock.$"

Inn_Keeper_Text_0:
# 62 "data/maps/DarkraiInn1/scripts.pory"
	.string "We hope you enjoy a peaceful rest\n"
	.string "at our inn.$"

Inn_AnimalHead_Text_0:
# 67 "data/maps/DarkraiInn1/scripts.pory"
	.string "A stuffed trophy depicting a head\n"
	.string "of a Pokémon.\p"
	.string "...\p"
	.string "It feels like the eyes are following \n"
	.string "you.$"

Inn_LockedDoor_Text_0:
# 77 "data/maps/DarkraiInn1/scripts.pory"
	.string "You try to open the door but it\n"
	.string "seems to be locked.$"

FoggyWindow_Inn_Text_0:
# 82 "data/maps/DarkraiInn1/scripts.pory"
	.string "You peek out of the window...\p"
	.string "A thick fog seems to cover your\n"
	.string "view.$"

Inn_OrnatePiano_Text_0:
# 90 "data/maps/DarkraiInn1/scripts.pory"
	.string "An ornate piano sits in front of you.\n"
	.string "It seems to be well maintained.$"

Inn_Drums_Text_0:
# 95 "data/maps/DarkraiInn1/scripts.pory"
	.string "A seemingly new drumset. How cool!$"

Inn_LockedSafe_Text_0:
# 99 "data/maps/DarkraiInn1/scripts.pory"
	.string "A locked safe, you wonder what is\n"
	.string "kept inside.$"

Inn_NoteOnWall_Text_0:
# 104 "data/maps/DarkraiInn1/scripts.pory"
	.string "Seems to be some sort of notice about\n"
	.string "closure of the inn. Odd...$"

Inn_PapersOnWall_Text_0:
# 109 "data/maps/DarkraiInn1/scripts.pory"
	.string "Various notes litter the wall, the text\n"
	.string "is blurry and hard to read.$"

Inn_TryingToExit_Text_0:
# 116 "data/maps/DarkraiInn1/scripts.pory"
	.string "You just arrived, surely there's no\n"
	.string "reason to leave just yet...$"

Inn_ReceptionPhone_Text_0:
# 126 "data/maps/DarkraiInn1/scripts.pory"
	.string "This is probably used to call the \n"
	.string "residents.$"
