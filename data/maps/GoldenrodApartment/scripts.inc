GoldenrodApartment_MapScripts::
# 2 "data/maps/GoldenrodApartment/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/GoldenrodApartment/scripts.pory"
	goto_if_set FLAG_MAGERNA_DOOR_OPENED, GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

GoldenrodApartment_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/GoldenrodApartment/scripts.pory"
	setmetatile 62, 8, 0x401, FALSE
	return


GoldenrodApartments_BasementGuard::
# 10 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_BasementGuard_Text_0
# 16 "data/maps/GoldenrodApartment/scripts.pory"
	checkspecies SPECIES_ROTOM
# 17 "data/maps/GoldenrodApartment/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodApartments_BasementGuard_2
# 21 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_BasementGuard_Text_1
# 27 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 28 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_HIDE_GROD_APARTMENTS_GUARD
# 29 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 30 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_APARTMENT_GUARD
# 31 "data/maps/GoldenrodApartment/scripts.pory"
	delay 60
# 32 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 33 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end

GoldenrodApartments_BasementGuard_2:
# 18 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_OldLady::
# 38 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_OldLady_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Child::
# 44 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Child_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Girl::
# 48 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Girl_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_Breloom::
# 55 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 56 "data/maps/GoldenrodApartment/scripts.pory"
	playmoncry SPECIES_BRELOOM, CRY_MODE_NORMAL
# 57 "data/maps/GoldenrodApartment/scripts.pory"
	waitmoncry
# 58 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Breloom_Text_0
# 59 "data/maps/GoldenrodApartment/scripts.pory"
	waitmessage
# 60 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_Gameboykid::
# 65 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Gameboykid_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistF::
# 71 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_ScientistF_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_ScientistM::
# 77 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_ScientistM_Text_0, MSGBOX_NPC
	return


GoldenrodApartments_LockedDoor::
# 83 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 84 "data/maps/GoldenrodApartment/scripts.pory"
	goto_if_set FLAG_MAGERNA_DOOR_OPENED, GoldenrodApartments_LockedDoor_2
# 89 "data/maps/GoldenrodApartment/scripts.pory"
	goto_if_set FLAG_GOT_MAGERNA_KEY, GoldenrodApartments_LockedDoor_5
# 107 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_3
# 110 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end

GoldenrodApartments_LockedDoor_2:
# 85 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_0
# 86 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end

GoldenrodApartments_LockedDoor_5:
# 90 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_1
# 94 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 95 "data/maps/GoldenrodApartment/scripts.pory"
	playse SE_UNLOCK
# 96 "data/maps/GoldenrodApartment/scripts.pory"
	setmetatile 62, 8, 0x401, FALSE
# 97 "data/maps/GoldenrodApartment/scripts.pory"
	special DrawWholeMapView
# 98 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_MAGERNA_DOOR_OPENED
# 99 "data/maps/GoldenrodApartment/scripts.pory"
	waitse
# 100 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_HIDE_MAGERNA_POLICE
# 101 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_M_POLICE1
# 102 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_M_POLICE2
# 103 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_LockedDoor_Text_2
# 104 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


GoldenrodApartments_Apartment1::
# 115 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment1_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment2::
# 119 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment2_Text_0, MSGBOX_SIGN
	return


GoldenrodApartments_Apartment3::
# 123 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox GoldenrodApartments_Apartment3_Text_0, MSGBOX_SIGN
	return


MagearnaEncounter::
# 128 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 129 "data/maps/GoldenrodApartment/scripts.pory"
	faceplayer
# 130 "data/maps/GoldenrodApartment/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_MAGEARNA, 75, LOCALID_MAGEARNA, FLAG_HIDE_MAGEARNA, 4, SPECIES_NONE, 110, MOVE_SHIFT_GEAR, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_STORED_POWER
# 141 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


MadScientistEvent::
# 146 "data/maps/GoldenrodApartment/scripts.pory"
	lock
# 147 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_0
# 148 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_1, MSGBOX_YESNO
# 149 "data/maps/GoldenrodApartment/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MadScientistEvent_2
# 155 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 156 "data/maps/GoldenrodApartment/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 53, 14, DIR_NORTH
# 157 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 158 "data/maps/GoldenrodApartment/scripts.pory"
	delay 15
# 159 "data/maps/GoldenrodApartment/scripts.pory"
	playbgm MUS_HG_TEAM_ROCKET_HQ, FALSE
# 160 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_1
# 161 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 162 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_2
# 168 "data/maps/GoldenrodApartment/scripts.pory"
	playse SE_LEDGE
# 169 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_2
# 170 "data/maps/GoldenrodApartment/scripts.pory"
	playse SE_LEDGE
# 171 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_2
# 172 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement
# 173 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_3
# 178 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_4
# 179 "data/maps/GoldenrodApartment/scripts.pory"
	delay 30
# 180 "data/maps/GoldenrodApartment/scripts.pory"
	turnobject LOCALID_MADSC, DIR_SOUTH
# 181 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_5
# 183 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_6
# 187 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 188 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_3
# 189 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 190 "data/maps/GoldenrodApartment/scripts.pory"
	trainerbattle_no_intro TRAINER_MAD_SCIENTIST, MadScientistEvent_Text_7
# 191 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_4
# 192 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_8
# 202 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 203 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_5
# 204 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 205 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_9
# 207 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 208 "data/maps/GoldenrodApartment/scripts.pory"
	playmoncry SPECIES_MAGEARNA, CRY_MODE_NORMAL
# 209 "data/maps/GoldenrodApartment/scripts.pory"
	waitmoncry
# 210 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MAGEARNA, MadScientistEvent_Movement_6
# 211 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 212 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_7
# 213 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 214 "data/maps/GoldenrodApartment/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_MAGEARNA, 75, LOCALID_MAGEARNA, FLAG_HIDE_MAGEARNA, 4, SPECIES_NONE, 110, MOVE_SHIFT_GEAR, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_STORED_POWER
# 225 "data/maps/GoldenrodApartment/scripts.pory"
	playbgm MUS_HG_TEAM_ROCKET_HQ, FALSE
# 226 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_10
# 233 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_11
# 234 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 235 "data/maps/GoldenrodApartment/scripts.pory"
	playse SE_PIN
# 236 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, Common_Movement_ExclamationMark
# 237 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 238 "data/maps/GoldenrodApartment/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 239 "data/maps/GoldenrodApartment/scripts.pory"
	turnobject LOCALID_MADSC, DIR_SOUTH
# 240 "data/maps/GoldenrodApartment/scripts.pory"
	waitse
# 241 "data/maps/GoldenrodApartment/scripts.pory"
	clearflag FLAG_HIDE_MAGERNA_POLICE
# 242 "data/maps/GoldenrodApartment/scripts.pory"
	addobject LOCALID_M_POLICE1
# 243 "data/maps/GoldenrodApartment/scripts.pory"
	addobject LOCALID_M_POLICE2
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_M_POLICE1, MadScientistEvent_Movement_8
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_M_POLICE2, MadScientistEvent_Movement_9
# 246 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 247 "data/maps/GoldenrodApartment/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 248 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_12
# 251 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_MADSC, MadScientistEvent_Movement_4
# 252 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 253 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_13
# 258 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_M_POLICE2, MadScientistEvent_Movement_10
# 259 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement
# 260 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_14
# 261 "data/maps/GoldenrodApartment/scripts.pory"
	turnobject LOCALID_M_POLICE1, DIR_WEST
# 262 "data/maps/GoldenrodApartment/scripts.pory"
	fadedefaultbgm
# 263 "data/maps/GoldenrodApartment/scripts.pory"
	msgbox MadScientistEvent_Text_15
# 275 "data/maps/GoldenrodApartment/scripts.pory"
	closemessage
# 276 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreen FADE_TO_BLACK
# 277 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_MADSC
# 278 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_M_POLICE1
# 279 "data/maps/GoldenrodApartment/scripts.pory"
	removeobject LOCALID_M_POLICE2
# 280 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_HIDE_MAGERNA_POLICE
# 281 "data/maps/GoldenrodApartment/scripts.pory"
	setflag FLAG_HIDE_MAD_SCIENTIST
# 282 "data/maps/GoldenrodApartment/scripts.pory"
	delay 45
# 283 "data/maps/GoldenrodApartment/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 284 "data/maps/GoldenrodApartment/scripts.pory"
	setvar VAR_MAD_SCIENTIST_EVENT_STATE, 1
# 285 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end

MadScientistEvent_2:
# 150 "data/maps/GoldenrodApartment/scripts.pory"
	applymovement LOCALID_PLAYER, MadScientistEvent_Movement_0
# 151 "data/maps/GoldenrodApartment/scripts.pory"
	waitmovement 0
# 152 "data/maps/GoldenrodApartment/scripts.pory"
	release
	end


# 150 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_0:
# 150 "data/maps/GoldenrodApartment/scripts.pory"
	walk_right
	step_end

# 160 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_1:
# 160 "data/maps/GoldenrodApartment/scripts.pory"
	walk_in_place_up
	step_end

# 169 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_2:
# 169 "data/maps/GoldenrodApartment/scripts.pory"
	jump_in_place_up
	step_end

# 188 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_3:
# 188 "data/maps/GoldenrodApartment/scripts.pory"
	walk_down
	step_end

# 191 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_4:
# 191 "data/maps/GoldenrodApartment/scripts.pory"
	walk_in_place_down
	step_end

# 203 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_5:
# 203 "data/maps/GoldenrodApartment/scripts.pory"
	walk_right
# 203 "data/maps/GoldenrodApartment/scripts.pory"
	face_up
	step_end

# 210 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_6:
# 210 "data/maps/GoldenrodApartment/scripts.pory"
	walk_down
# 210 "data/maps/GoldenrodApartment/scripts.pory"
	delay_16
# 210 "data/maps/GoldenrodApartment/scripts.pory"
	walk_down
	step_end

# 212 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_7:
# 212 "data/maps/GoldenrodApartment/scripts.pory"
	face_left
	step_end

# 244 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_8:
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 244 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
	step_end

# 245 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_9:
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_left
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodApartment/scripts.pory"
	face_left
	step_end

# 258 "data/maps/GoldenrodApartment/scripts.pory"
MadScientistEvent_Movement_10:
# 258 "data/maps/GoldenrodApartment/scripts.pory"
	walk_in_place_left
	step_end

GoldenrodApartments_BasementGuard_Text_0:
# 10 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Sorry but this stairway leads to the\n"
	.string "apartments storage. Besides, I don't\l"
	.string "think there's any reason why a trainer\l"
	.string "would want to check out old house\l"
	.string "appliances that have been abandoned\l"
	.string "due to rampant consumerism.$"

GoldenrodApartments_BasementGuard_Text_1:
# 21 "data/maps/GoldenrodApartment/scripts.pory"
	.string "...What? You have a Rotom that wants\n"
	.string "check out the appliances? Well... \l"
	.string "I suppose the tenants wouldn't\l"
	.string "use them anyway. Let's say I never\l"
	.string "saw you if anyone asks. I'm going to\l"
	.string "have a coffee break.$"

GoldenrodApartments_OldLady_Text_0:
# 38 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The city has been expanding a lot in\n"
	.string "recent years. I fear I've been left\l"
	.string "behind by the rapid changes.$"

GoldenrodApartments_Child_Text_0:
# 44 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Mom always comes home late...$"

GoldenrodApartments_Girl_Text_0:
# 48 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Our mother works at the radio tower,\n"
	.string "which makes her very busy. Luckily\l"
	.string "we have mom's Breloom to help with\l"
	.string "everything!$"

GoldenrodApartments_Breloom_Text_0:
# 58 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Breloom is joyfully doing the dishes!$"

GoldenrodApartments_Gameboykid_Text_0:
# 65 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Strange noises can be heard from the\n"
	.string "floor above this. I have never seen\l"
	.string "anyone who lives there though, strange.$"

GoldenrodApartments_ScientistF_Text_0:
# 71 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod recently invited scientists\n"
	.string "from other regions to the Radio Tower\l"
	.string "for a business meeting.$"

GoldenrodApartments_ScientistM_Text_0:
# 77 "data/maps/GoldenrodApartment/scripts.pory"
	.string "These SkyBNB apartments are barely\n"
	.string "equipped with the most basics of\l"
	.string "tools... How vexing.$"

GoldenrodApartments_LockedDoor_Text_0:
# 85 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The door is now open.$"

GoldenrodApartments_LockedDoor_Text_1:
# 90 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The way seems to be barred by a metal\n"
	.string "door. A small keyhole is visible. \p"
	.string "You used the Apartment Key.$"

GoldenrodApartments_LockedDoor_Text_2:
# 103 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The way is now open.$"

GoldenrodApartments_LockedDoor_Text_3:
# 107 "data/maps/GoldenrodApartment/scripts.pory"
	.string "The way seems to be barred by a metal\n"
	.string "door. A small keyhole is visible, but\l"
	.string "you have nothing that would fit it.$"

GoldenrodApartments_Apartment1_Text_0:
# 115 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F1$"

GoldenrodApartments_Apartment2_Text_0:
# 119 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F2$"

GoldenrodApartments_Apartment3_Text_0:
# 123 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Goldenrod Sky Apartments F3$"

MadScientistEvent_Text_0:
# 147 "data/maps/GoldenrodApartment/scripts.pory"
	.string "You sense trouble in this direction.$"

MadScientistEvent_Text_1:
# 148 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Are you prepared to go forward?$"

MadScientistEvent_Text_2:
# 162 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: Ha haa! The machine is nearly\n"
	.string "complete! \p"
	.string "I shall have my revenge on those \n"
	.string "Rocket executives for taking my\l"
	.string "research funding!$"

MadScientistEvent_Text_3:
# 173 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: And then! The rest of those\n"
	.string "snobby scientific committee members!\p"
	.string "This will be my ultimate creation!\n"
	.string "Ahahahahahahahahaaaaaaaaaaaaaa!$"

MadScientistEvent_Text_4:
# 178 "data/maps/GoldenrodApartment/scripts.pory"
	.string "But first...$"

MadScientistEvent_Text_5:
# 181 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: Who are you and how \n"
	.string "did you get in?!$"

MadScientistEvent_Text_6:
# 183 "data/maps/GoldenrodApartment/scripts.pory"
	.string "I don't have time for \n"
	.string "debt collectors or salespeople! \p"
	.string "I will be rid of you!$"

MadScientistEvent_Text_7:
# 190 "data/maps/GoldenrodApartment/scripts.pory"
	.string "No! I can't afford this!$"

MadScientistEvent_Text_8:
# 192 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: It seems the tax office has \n"
	.string "sent quite a tough customer this time. \p"
	.string "No matter!\p"
	.string "I've been looking for volunteers\n"
	.string "actually, so this will work out nicely!\p"
	.string "You shall be the first to witness the\n"
	.string "raw power of my mechanical Pokémon!$"

MadScientistEvent_Text_9:
# 205 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: Magearna! Destroy this \n"
	.string "foolish intruder!$"

MadScientistEvent_Text_10:
# 226 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: This... THIS CANNOT BE!\p"
	.string "My creation... Gone? JUST LIKE THAT?\p"
	.string "It was supposed to be invincible!\p"
	.string "This isn't over! I can still-$"

MadScientistEvent_Text_11:
# 233 "data/maps/GoldenrodApartment/scripts.pory"
	.string "??? Hold it right there!$"

MadScientistEvent_Text_12:
# 248 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Police: You're under arrest for tax \n"
	.string "evasion, having ties to the Team Rocket\l"
	.string "and for developing illegal Pokémon.$"

MadScientistEvent_Text_13:
# 253 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Scientist: B-But I was the one whom \n"
	.string "Team Rocket abandoned!\p"
	.string "I'm innocent! I just wanted\n"
	.string "to show them they were in the wrong!$"

MadScientistEvent_Text_14:
# 260 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Save it for the judge.$"

MadScientistEvent_Text_15:
# 263 "data/maps/GoldenrodApartment/scripts.pory"
	.string "Police: I thank you for help \n"
	.string "subduing this crook. \p"
	.string "They've been holed up here\n"
	.string "for a while, causing all sorts of\l"
	.string "disturbance.\p"
	.string "We'll let you keep the Pokémon if\n"
	.string "you stay quiet about it. \p"
	.string "We trust it will be in good \n"
	.string "hands with you.$"
