# 1 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 2 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
.set LOCALID_DIRECTOR_OFFICE, 1
# 3 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
.set LOCALID_GOLDENROD_ARCHER, 2
# 4 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
.set LOCALID_GOLDENROD_ARIANA, 3
# 5 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
.set LOCALID_PETREL_OFFICE, 4
# 6 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 7 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_MapScripts::
# 8 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
# 9 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.byte 0
# 10 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 11 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ During Rocket Takeover, hide Petrel and show the Director (Petrel in disguise)
# 12 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_OnLoad::
# 13 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
# 14 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 15 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 16 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
# 17 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 18 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 19 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 20 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 21 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 22 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[OFFICE]==============================================================================================================================
# 23 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 24 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Petrel::
# 25 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 26 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ After Rocket Takeover, this is the real Director
# 27 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
# 28 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
# 29 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_SELECT
# 30 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 31 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
# 32 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 33 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
# 34 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 35 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 36 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_DIRECTOR_OFFICE
# 37 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
    removeobject LOCALID_RADIOTOWER_OAK
# 38 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 39 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_PETREL_OFFICE
# 40 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
# 41 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 42 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
# 43 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
# 44 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
# 45 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_BASEMENT_KEY
# 46 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 7
# 47 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 48 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 49 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 50 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 51 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 52 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 53 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
# 54 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 55 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 56 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
# 57 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 58 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 59 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
# 60 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 61 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 62 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 63 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 64 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ Modified in 1.2.2 to retroactively fix the Baoba Sequence Break on a 1.2.1 save file
# 65 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Director::
# 66 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 67 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 68 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_SELECT
# 69 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ If player has either wing, skip to default director
# 70 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	checkitem ITEM_SILVER_WING
# 71 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
# 72 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	checkitem ITEM_RAINBOW_WING
# 73 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
# 74 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 75 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 76 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 77 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 78 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 79 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorDone::
# 80 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
# 81 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 82 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 83 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 84 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 85 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorWest::
# 86 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorWest, MSGBOX_DEFAULT
# 87 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 88 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 89 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 90 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 91 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin:
# 92 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 93 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 94 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 95 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 96 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 97 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 98 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 99 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 100 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 101 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 102 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 103 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 104 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 105 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 106 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 107 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 108 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 109 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 110 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 111 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 112 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 113 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 114 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 115 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 116 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 117 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 118 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin2:
# 119 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 120 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 121 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 122 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 123 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 124 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 125 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 126 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 127 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 128 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 129 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
# 130 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Y-you! You came to rescue me?$"
# 131 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 132 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
# 133 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Is that what you were expecting?\p"
# 134 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Wrong! I'm an imposter!\p"
# 135 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I pretended to be the real thing to\n"
# 136 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "prepare for our takeover.\p"
# 137 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Do you want to know where we hid\n"
# 138 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the real Director?\p"
# 139 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Sure, I'll tell you. But only if you\n"
# 140 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "can beat me!$"
# 141 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 142 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
# 143 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, Ok. I'll tell you where he is.$"
# 144 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 145 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
# 146 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 147 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 148 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 149 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 150 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I am a nice guy, I will give you\n"
# 151 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Basement Key to get to the\l"
# 152 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Underground Warehouse.\p"
# 153 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 154 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 155 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
# 156 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 157 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 158 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 159 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 160 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You can use the Basement Key to\n"
# 161 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "get to the Underground Warehouse.\p"
# 162 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 163 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 164 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[STUDIO]==============================================================================================================================
# 165 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 166 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Ben::
# 167 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 168 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 169 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
# 170 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 171 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 172 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 173 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 174 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodRaidoTower4_EventScript_ARIANA::
# 175 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
# 176 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
# 177 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 178 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 179 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 180 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
# 181 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 182 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_RADIOF5DUDE
# 183 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 184 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 185 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 186 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
# 187 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 188 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 189 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 190 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 191 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 192 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 193 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 194 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 195 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 196 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 197 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 198 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
# 199 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 200 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 201 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 202 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 203 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 204 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
# 205 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 206 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 207 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 208 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 209 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 210 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 211 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 212 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 213 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 214 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 215 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 216 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 217 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
# 218 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 219 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 220 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 221 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 222 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
# 223 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 224 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 225 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 226 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 227 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 228 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 229 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 230 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 231 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 232 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 233 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 234 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 235 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 236 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
# 237 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 238 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 239 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 240 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 241 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 242 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave1:
# 243 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 246 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 247 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave2:
# 248 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 249 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 250 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 251 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 252 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 253 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 254 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
# 255 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Remember me from the Hideout in\n"
# 256 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Mahogany Town?\p"
# 257 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "My boss scolded me but I'm stronger.\p"
# 258 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I lost then, but I won't this time.$"
# 259 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 260 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
# 261 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This can't be happening!\p"
# 262 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I fought hard, but I still lost…\p"
# 263 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I'm so sorry Giovanni…$"
# 264 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 265 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
# 266 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}, isn't it?\p"
# 267 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "A brat like you won't appreciate\n"
# 268 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the magnificence of Team Rocket.\p"
# 269 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That's too bad. I really admire\n"
# 270 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "your power.$"
# 271 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 272 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
# 273 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh? You managed to get this far?\p"
# 274 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You must be quite the trainer.\p"
# 275 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We intend to take over this Radio\n"
# 276 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Station and announce our comeback.\p"
# 277 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That should bring our boss Giovanni\n"
# 278 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "back from his solitary training.\p"
# 279 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We are going to regain our former\n"
# 280 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "glory...\p"
# 281 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I won't allow you to interfere with\n"
# 282 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our meticulous plans!$"
# 283 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 284 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
# 285 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, Giovanni!$"
# 286 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 287 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
# 288 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "How could this be?\p"
# 289 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Our dreams have come to naught.\p"
# 290 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wasn't up to the task after all.\p"
# 291 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Like Giovanni did before me, I will\n"
# 292 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "disband Team Rocket here today.\p"
# 293 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Farewell.$"
# 294 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 295 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
# 296 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, thank you!\p"
# 297 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Your courageous actions have saved\n"
# 298 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Pokémon nationwide.\p"
# 299 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 300 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 301 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 302 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain:
# 303 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, once again, thank you!\p"
# 304 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The large winged Pokémon that flew past\n"
# 305 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "reminded me, I have a reward for your\l"
# 306 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "courageous actions.\p"
# 307 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 308 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 309 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 310 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
# 311 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 312 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 313 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 314 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 315 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 316 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 317 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 318 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 319 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 320 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 321 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 322 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…\p"
# 323 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 324 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 325 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 326 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2:
# 327 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 328 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 329 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 330 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 331 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 332 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 333 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 334 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 335 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 336 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 337 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 338 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…$"
# 339 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 340 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
# 341 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 342 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 343 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 344 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 345 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 346 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 347 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 348 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 349 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 350 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 351 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 352 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…\p"
# 353 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 354 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 355 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 356 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2:
# 357 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 358 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 359 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 360 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 361 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 362 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 363 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 364 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 365 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 366 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 367 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 368 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…$"
# 369 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 370 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
# 371 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ah!\p"
# 372 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That reminds me…\p"
# 373 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing I gave you... I think\n"
# 374 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "it's related to the Legendary\l"
# 375 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Pokémon.\p"
# 376 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But! The Legendary Pokémon won't\n"
# 377 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "appear with just that wing...\p"
# 378 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Apparently there is something else\n"
# 379 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "you need... Or something like that.\p"
# 380 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wonder what it was...\p"
# 381 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I can't remember.$"
# 382 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 383 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
# 384 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Are you expecting something?\n"
# 385 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This is what they call Fake Out.\p"
# 386 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I really must go back to my office\n"
# 387 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "this time. See ya!$"
# 388 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 389 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
# 390 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 391 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You know, I love Pokémon.\p"
# 392 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I built this Radio Tower so I could\n"
# 393 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "express my love of Pokémon.\p"
# 394 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It would be nice if people enjoyed\n"
# 395 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our programs.$"
# 396 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 397 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break - Directs player toward Baoba
# 398 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorWest:
# 399 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 400 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Did you see the large winged Pokémon\n"
# 401 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "that flew past earlier?\p"
# 402 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's the talk of the town!\n"
# 403 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Or should I say, of the Radio Tower?\p"
# 404 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It seemed to be headed West, in the\n"
# 405 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "direction of Route 39.$"
# 406 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 407 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Ben:
# 408 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ben: Do you listen to our music?$"
# 409 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 410 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
# 411 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Director's   Office$"
# 412 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 413 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
# 414 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Studio 1$"

OakRadioTowerF5::
# 418 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
# 419 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 420 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 421 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
# 422 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 423 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_0
# 424 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_1
# 425 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_MEGA_RING
# 426 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_2
# 427 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_3
# 428 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 429 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_RADIOTOWER_OAK
# 430 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadedefaultbgm
# 431 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 100
# 432 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 433 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end


RadioTower_5F_Archer::
# 438 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 439 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 440 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_0
# 457 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHER, RadioTower_5F_Archer_Text_1
# 458 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_2
# 469 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 470 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 471 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 472 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 473 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 474 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 10
# 475 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARCHER
# 476 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARIANA
# 477 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 478 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 479 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_PETREL_OFFICE
# 480 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_F5_DIRECTOR_2
# 481 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_RADIOTOWER_OAK
# 482 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_GOLDENROD, TRUE
# 483 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 484 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 485 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	approachobject LOCALID_F5_DIRECTOR_2, LOCALID_PLAYER, DIR_WEST, DIR_EAST
# 486 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 487 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 488 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 489 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_3
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, RadioTower_5F_Archer_Text_4, RadioTower_5F_Archer_Text_5
# 505 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	switch VAR_RESULT
# 506 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	case 0, RadioTower_5F_Archer_3
# 520 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	case 1, RadioTower_5F_Archer_4
RadioTower_5F_Archer_1:
# 535 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_8
# 537 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_F5_DIRECTOR_2, RadioTower_5F_Archer_Movement_0
# 539 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 540 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 541 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_F5_DIRECTOR_2, Common_Movement_ExclamationMark
# 542 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 543 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_F5_DIRECTOR_2, DIR_WEST
# 544 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 545 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_9
# 555 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 556 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_F5_DIRECTOR_2, 29, 5, DIR_NORTH
# 557 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 558 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 559 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_F5_DIRECTOR_2
# 560 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 17
# 561 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
# 562 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 563 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 564 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
# 565 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 566 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_OAK
# 567 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_0
# 568 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_1
# 569 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_MEGA_RING
# 570 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_OAK
# 571 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_10
# 578 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_11
# 579 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 580 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 24, 5, DIR_WEST
# 581 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 582 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 583 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 584 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_ROCKET_TAKEOVER_CAP
# 585 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 586 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_RADIOTOWER_OAK
# 587 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	savebgm MUS_DUMMY
# 589 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadedefaultbgm
# 590 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end

RadioTower_5F_Archer_3:
# 507 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 2
# 508 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 509 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 510 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_6
	goto RadioTower_5F_Archer_1

RadioTower_5F_Archer_4:
# 521 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 1
# 522 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 523 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 524 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_7
	goto RadioTower_5F_Archer_1


# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
RadioTower_5F_Archer_Movement_0:
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
	step_end

OakRadioTowerF5_Text_0:
# 423 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}! You've pulled off a miracle\n"
	.string "by taking down Team Rocket!$"

OakRadioTowerF5_Text_1:
# 424 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I knew it was the right choice to\n"
	.string "entrust Pokédex to you. I want you to\l"
	.string "have this, I think you've more than\l"
	.string "earned it.$"

OakRadioTowerF5_Text_2:
# 426 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That is a Mega Ring. When combined with\n"
	.string "a Mega stone, it allows the bond\l"
	.string "between trainer and Pokémon to fully\l"
	.string "manifest. I'm sure you'll be able to pull\l"
	.string "it off.$"

OakRadioTowerF5_Text_3:
# 427 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now I must start heading back to Kanto,\n"
	.string "I hope you'll pay a visit to the Pallet\l"
	.string "Town at some point! Give my regards to\l"
	.string "Prof. Elm.$"

RadioTower_5F_Archer_Text_0:
# 440 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Archer: Oh? You managed to get\n"
	.string "this far...?\p"
	.string "You must be quite the Trainer.\p"
	.string "We intend to take over this\n"
	.string "Radio Tower and officially announce \l"
	.string "our comeback.\p"
	.string "That should bring our boss Giovanni\n"
	.string "back from his solitary training.\p"
	.string "We are going to regain our former\n"
	.string "glory... \p"
	.string "I will not allow you to interfere with\n"
	.string "our meticulous plans!$"

RadioTower_5F_Archer_Text_1:
# 457 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, Giovanni!$"

RadioTower_5F_Archer_Text_2:
# 458 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Archer: How could this be...?\p"
	.string "It seems I was not up to the task... \n"
	.string "Yet.\p"
	.string "We shall retreat for now, but know \n"
	.string "that Team Rocket roots run deeper \l"
	.string "in this region than you might think.\p"
	.string "We shall meet again, {PLAYER}.\n"
	.string "Farewell...$"

RadioTower_5F_Archer_Text_3:
# 489 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Oh...\p"
	.string "You have already defeated them?\n"
	.string "Thank you!\p"
	.string "Your courageous actions have saved\n"
	.string "Pokémon nationwide.\p"
	.string "You deserve to be rewarded for your\n"
	.string "actions! \p"
	.string "I'll let you pick one of our \n"
	.string "prized treasures! \p"
	.string "Go ahead and pick one!$"

RadioTower_5F_Archer_Text_4:
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Rainbow Wing$"

RadioTower_5F_Archer_Text_5:
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Silver Wing$"

RadioTower_5F_Archer_Text_6:
# 510 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here.\p"
	.string "When the tower was replaced with the\n"
	.string "Radio Tower, that Rainbow Wing was \l"
	.string "found at the top of the tower.\p"
	.string "I heard from a friend from Cianwood\n"
	.string "City that you can climb the Bell\l"
	.string "Tower in Ecruteak City when you have a\l"
	.string "Rainbow Wing.$"

RadioTower_5F_Archer_Text_7:
# 524 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here.\p"
	.string "When the tower was replaced with the\n"
	.string "Radio Tower, that Silver Wing was \l"
	.string "found at the top of the tower.\p"
	.string "I heard from a friend from Cianwood\n"
	.string "City that you can go down the cave\l"
	.string "at Whirl Islands when you have a Silver\l"
	.string "Wing.$"

RadioTower_5F_Archer_Text_8:
# 535 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I have to get back to my office.\n"
	.string "See you!$"

RadioTower_5F_Archer_Text_9:
# 545 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh, I almost forgot!\p"
	.string "According to my friend from Cianwood,\n"
	.string "the legendary Pokémon will not appear\l"
	.string "if you just go to the place I mentioned.\l"
	.string "Apparently there is something else you\l"
	.string "need... Or something like that.\p"
	.string "I wonder what it was...\n"
	.string "I can't remember.$"

RadioTower_5F_Archer_Text_10:
# 571 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That is a Mega Ring. \p"
	.string "When combined with a Mega stone, \n"
	.string "it allows the bond between trainer \l"
	.string "and Pokémon to fully manifest. \p"
	.string "I'm sure you'll be able to pull it off.$"

RadioTower_5F_Archer_Text_11:
# 578 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now I must get back to my work, I hope\n"
	.string "you'll tune in to my next radio show!$"
