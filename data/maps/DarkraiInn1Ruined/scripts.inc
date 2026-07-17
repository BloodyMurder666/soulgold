DarkraiInn1Ruined_MapScripts::
# 2 "data/maps/DarkraiInn1Ruined/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DarkraiInn1Ruined_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DarkraiInn1Ruined_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
	return


Inn_RuinedPiano::
# 8 "data/maps/DarkraiInn1Ruined/scripts.pory"
	lock
# 9 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 6
	goto_if_lt Inn_RuinedPiano_2
# 17 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 6
	goto_if_eq Inn_RuinedPiano_5
# 30 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_ge Inn_RuinedPiano_8
# 35 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedPiano_2:
# 10 "data/maps/DarkraiInn1Ruined/scripts.pory"
	playse SE_NOTE_G
# 11 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedPiano_Text_0
# 13 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitse
# 14 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedPiano_5:
# 18 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedPiano_Text_1
# 23 "data/maps/DarkraiInn1Ruined/scripts.pory"
	playfanfare MUS_HG_OBTAIN_ITEM
# 24 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedPiano_Text_2
# 25 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitfanfare
# 26 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 7
# 27 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedPiano_8:
# 31 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedPiano_Text_3
# 32 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end


Inn_RuinedDrums::
# 41 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedDrums_Text_0, MSGBOX_SIGN
	return


Inn_RuinedSafe::
# 45 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_lt Inn_RuinedSafe_2
Inn_RuinedSafe_1:
# 48 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 7
	goto_if_eq Inn_RuinedSafe_5
Inn_RuinedSafe_4:
# 61 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedSafe_2:
# 46 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedSafe_Text_0, MSGBOX_SIGN
	goto Inn_RuinedSafe_1

Inn_RuinedSafe_5:
# 49 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedSafe_Text_1
# 54 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedSafe_Text_2, MSGBOX_YESNO
# 55 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Inn_RuinedSafe_7
	goto Inn_RuinedSafe_4

Inn_RuinedSafe_7:
# 56 "data/maps/DarkraiInn1Ruined/scripts.pory"
	warp MAP_DARKRAI_INN_FINAL_ROOM, 0
# 57 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitstate
	end


InnHideCresselia::
# 66 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setflag FLAG_HIDE_DARKRAI_INN_NPC
# 67 "data/maps/DarkraiInn1Ruined/scripts.pory"
	removeobject 1
# 68 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_TEMP_0, 1
	return


Inn_RuinedTelephone::
# 72 "data/maps/DarkraiInn1Ruined/scripts.pory"
	lock
# 73 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 4
	goto_if_lt Inn_RuinedTelephone_2
# 79 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 4
	goto_if_eq Inn_RuinedTelephone_5
Inn_RuinedTelephone_4:
# 104 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 5
	goto_if_eq Inn_RuinedTelephone_8
Inn_RuinedTelephone_7:
# 123 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 5
	goto_if_gt Inn_RuinedTelephone_13
	return

Inn_RuinedTelephone_2:
# 74 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_0
# 76 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedTelephone_5:
# 80 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_1
# 85 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 5
# 86 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_2
# 87 "data/maps/DarkraiInn1Ruined/scripts.pory"
	dynmultichoice 20, 4, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Inn_RuinedTelephone_Text_3, Inn_RuinedTelephone_Text_4, Inn_RuinedTelephone_Text_5
# 88 "data/maps/DarkraiInn1Ruined/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 0, Inn_RuinedTelephone_11
# 90 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 2, Inn_RuinedTelephone_11
# 94 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 1, Inn_RuinedTelephone_12
	goto Inn_RuinedTelephone_4

Inn_RuinedTelephone_8:
# 105 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_2
# 106 "data/maps/DarkraiInn1Ruined/scripts.pory"
	dynmultichoice 20, 4, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Inn_RuinedTelephone_Text_3, Inn_RuinedTelephone_Text_4, Inn_RuinedTelephone_Text_5
# 107 "data/maps/DarkraiInn1Ruined/scripts.pory"
	switch VAR_RESULT
# 108 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 0, Inn_RuinedTelephone_16
# 109 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 2, Inn_RuinedTelephone_16
# 113 "data/maps/DarkraiInn1Ruined/scripts.pory"
	case 1, Inn_RuinedTelephone_17
	goto Inn_RuinedTelephone_7

Inn_RuinedTelephone_11:
# 91 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_6
# 92 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedTelephone_12:
# 95 "data/maps/DarkraiInn1Ruined/scripts.pory"
	playse SE_CLICK
# 96 "data/maps/DarkraiInn1Ruined/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 97 "data/maps/DarkraiInn1Ruined/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 98 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitmovement 0
# 99 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 6
# 100 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedTelephone_13:
# 124 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_7
# 125 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedTelephone_16:
# 110 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedTelephone_Text_6
# 111 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_RuinedTelephone_17:
# 114 "data/maps/DarkraiInn1Ruined/scripts.pory"
	playse SE_CLICK
# 115 "data/maps/DarkraiInn1Ruined/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 116 "data/maps/DarkraiInn1Ruined/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 117 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitmovement 0
# 118 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 6
# 119 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end


Inn_RuinedDoor::
# 131 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_RuinedDoor_Text_0, MSGBOX_SIGN
	return


Inn_NotesOnWall::
# 136 "data/maps/DarkraiInn1Ruined/scripts.pory"
	lock
# 137 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 2
	goto_if_eq Inn_NotesOnWall_2
# 151 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_NotesOnWall_Text_1
Inn_NotesOnWall_1:
# 157 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_NotesOnWall_2:
# 138 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_NotesOnWall_Text_0
# 149 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 3
	goto Inn_NotesOnWall_1


Inn_LuxrayHead::
# 162 "data/maps/DarkraiInn1Ruined/scripts.pory"
	lock
# 163 "data/maps/DarkraiInn1Ruined/scripts.pory"
	compare VAR_DARKRAI_INN_PROGRESS, 3
	goto_if_eq Inn_LuxrayHead_1
# 178 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_LuxrayHead_Text_2
# 185 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end

Inn_LuxrayHead_1:
# 164 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_LuxrayHead_Text_0
# 171 "data/maps/DarkraiInn1Ruined/scripts.pory"
	playfanfare MUS_HG_OBTAIN_ITEM
# 172 "data/maps/DarkraiInn1Ruined/scripts.pory"
	msgbox Inn_LuxrayHead_Text_1
# 173 "data/maps/DarkraiInn1Ruined/scripts.pory"
	waitfanfare
# 174 "data/maps/DarkraiInn1Ruined/scripts.pory"
	setvar VAR_DARKRAI_INN_PROGRESS, 4
# 175 "data/maps/DarkraiInn1Ruined/scripts.pory"
	release
	end


Inn_RuinedPiano_Text_0:
# 11 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The piano has a sound, but\n"
	.string "something feels off.$"

Inn_RuinedPiano_Text_1:
# 18 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "One of the notes is loose now.\p"
	.string "...\p"
	.string "Under it you find a small key!$"

Inn_RuinedPiano_Text_2:
# 24 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "{PLAYER} obtained a small key!$"

Inn_RuinedPiano_Text_3:
# 31 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "Nothing of note is left in the piano.$"

Inn_RuinedDrums_Text_0:
# 41 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The drums are covered in dust.$"

Inn_RuinedSafe_Text_0:
# 46 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The safe is locked tight.$"

Inn_RuinedSafe_Text_1:
# 49 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The key you found fits perfectly into\n"
	.string "the lock of the safe.\p"
	.string "Inside the safe seems to be a hidden\n"
	.string "tunnel dug through the wall.$"

Inn_RuinedSafe_Text_2:
# 54 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "Enter?$"

Inn_RuinedTelephone_Text_0:
# 74 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "An old telephone. The dial\n"
	.string "appears to be missing.$"

Inn_RuinedTelephone_Text_1:
# 80 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "You fit the dial to the telephone.\p"
	.string "...\p"
	.string "It fits perfectly!$"

Inn_RuinedTelephone_Text_2:
# 86 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "Which number should you try to dial?$"

Inn_RuinedTelephone_Text_3:
# 87 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "4114$"

Inn_RuinedTelephone_Text_4:
# 87 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "1144$"

Inn_RuinedTelephone_Text_5:
# 87 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "4141$"

Inn_RuinedTelephone_Text_6:
# 91 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "There's no response...$"

Inn_RuinedTelephone_Text_7:
# 124 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The telephone is unresponsive.$"

Inn_RuinedDoor_Text_0:
# 131 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The door is locked tight, maybe there's\n"
	.string "a key somewhere?$"

Inn_NotesOnWall_Text_0:
# 138 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "The notes on the wall seem to detail\n"
	.string "the floor plan of the inn. \p"
	.string "There's a detailed marking for all the\n"
	.string "furniture.\p"
	.string "11 Wall Lamps\n"
	.string "4 Large Windows\l"
	.string "4 Sawsbuck Trophies\p"
	.string "...$"

Inn_NotesOnWall_Text_1:
# 151 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "11 Wall Lamps\n"
	.string "4 Large Windows\l"
	.string "4 Sawsbuck Trophies\p"
	.string "...$"

Inn_LuxrayHead_Text_0:
# 164 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "This trophy was not accounted for\n"
	.string "in the floor plan. \p"
	.string "You take a closer look...\p"
	.string "In the mouth of the trophy,\n"
	.string "there's a dial.$"

Inn_LuxrayHead_Text_1:
# 172 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "{PLAYER} obtained a Dial!$"

Inn_LuxrayHead_Text_2:
# 178 "data/maps/DarkraiInn1Ruined/scripts.pory"
	.string "A stuffed trophy depicting a head\n"
	.string "of a Pokémon.\p"
	.string "...\p"
	.string "It feels like the eyes are following \n"
	.string "you.$"
