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
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath
# 70 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 71 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 72 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 73 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorDone::
# 74 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
# 75 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 76 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 77 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 78 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 79 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorWest::
# 80 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorWest, MSGBOX_DEFAULT
# 81 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 82 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 83 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 84 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 85 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin:
# 86 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 87 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 88 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 89 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 90 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 91 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 92 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 93 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 94 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 95 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 96 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 97 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 98 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 99 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 100 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 101 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 102 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 103 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 104 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 105 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 106 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 107 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 108 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 109 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 110 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 111 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 112 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin2:
# 113 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 114 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 115 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 116 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 117 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 118 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 119 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 120 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 121 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 122 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 123 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
# 124 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Y-you! You came to rescue me?$"
# 125 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 126 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
# 127 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Is that what you were expecting?\p"
# 128 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Wrong! I'm an imposter!\p"
# 129 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I pretended to be the real thing to\n"
# 130 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "prepare for our takeover.\p"
# 131 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Do you want to know where we hid\n"
# 132 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the real Director?\p"
# 133 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Sure, I'll tell you. But only if you\n"
# 134 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "can beat me!$"
# 135 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 136 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
# 137 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, Ok. I'll tell you where he is.$"
# 138 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 139 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
# 140 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 141 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 142 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 143 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 144 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I am a nice guy, I will give you\n"
# 145 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Basement Key to get to the\l"
# 146 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Underground Warehouse.\p"
# 147 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 148 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 149 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
# 150 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 151 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 152 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 153 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 154 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You can use the Basement Key to\n"
# 155 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "get to the Underground Warehouse.\p"
# 156 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 157 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 158 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[STUDIO]==============================================================================================================================
# 159 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 160 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Ben::
# 161 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 162 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 163 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
# 164 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 165 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 166 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 167 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 168 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodRaidoTower4_EventScript_ARIANA::
# 169 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
# 170 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
# 171 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 172 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 173 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 174 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
# 175 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 176 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_RADIOF5DUDE
# 177 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 178 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 179 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 180 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
# 181 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 182 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 183 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 184 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 185 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 186 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 187 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 188 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 189 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 190 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 191 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 192 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
# 193 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 194 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 195 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 196 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 197 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 198 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
# 199 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 200 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 201 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 202 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 203 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 204 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 205 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 206 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 207 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 208 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 209 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 210 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 211 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
# 212 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 213 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 214 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 215 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 216 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
# 217 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 218 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 219 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 220 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 221 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 222 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 223 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 224 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 225 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 226 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 227 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 228 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 229 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 230 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
# 231 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 232 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 233 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 234 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 235 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 236 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave1:
# 237 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 238 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 239 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 240 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 241 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave2:
# 242 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 243 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 244 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 245 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 246 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 247 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 248 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
# 249 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Remember me from the Hideout in\n"
# 250 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Mahogany Town?\p"
# 251 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "My boss scolded me but I'm stronger.\p"
# 252 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I lost then, but I won't this time.$"
# 253 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 254 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
# 255 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This can't be happening!\p"
# 256 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I fought hard, but I still lost…\p"
# 257 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I'm so sorry Giovanni…$"
# 258 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 259 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
# 260 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}, isn't it?\p"
# 261 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "A brat like you won't appreciate\n"
# 262 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the magnificence of Team Rocket.\p"
# 263 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That's too bad. I really admire\n"
# 264 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "your power.$"
# 265 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 266 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
# 267 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh? You managed to get this far?\p"
# 268 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You must be quite the trainer.\p"
# 269 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We intend to take over this Radio\n"
# 270 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Station and announce our comeback.\p"
# 271 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That should bring our boss Giovanni\n"
# 272 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "back from his solitary training.\p"
# 273 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We are going to regain our former\n"
# 274 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "glory...\p"
# 275 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I won't allow you to interfere with\n"
# 276 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our meticulous plans!$"
# 277 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 278 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
# 279 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, Giovanni!$"
# 280 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 281 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
# 282 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "How could this be?\p"
# 283 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Our dreams have come to naught.\p"
# 284 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wasn't up to the task after all.\p"
# 285 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Like Giovanni did before me, I will\n"
# 286 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "disband Team Rocket here today.\p"
# 287 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Farewell.$"
# 288 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 289 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
# 290 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, thank you!\p"
# 291 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Your courageous actions have saved\n"
# 292 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Pokémon nationwide.\p"
# 293 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 294 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 295 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 296 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain:
# 297 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, once again, thank you!\p"
# 298 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The large winged Pokémon that flew past\n"
# 299 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "reminded me, I have a reward for your\l"
# 300 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "courageous actions.\p"
# 301 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 302 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 303 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 304 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
# 305 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 306 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 307 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 308 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 309 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 310 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 311 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 312 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 313 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 314 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 315 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 316 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…\p"
# 317 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 318 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 319 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 320 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2:
# 321 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 322 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 323 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 324 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 325 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 326 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 327 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 328 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 329 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 330 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 331 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 332 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…$"
# 333 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 334 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
# 335 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 336 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 337 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 338 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 339 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 340 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 341 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 342 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 343 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 344 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 345 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 346 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…\p"
# 347 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 348 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 349 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 350 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2:
# 351 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 352 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 353 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 354 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 355 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 356 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 357 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 358 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of Pokémon\n"
# 359 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 360 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 361 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 362 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…$"
# 363 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 364 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
# 365 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ah!\p"
# 366 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That reminds me…\p"
# 367 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing I gave you... I think\n"
# 368 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "it's related to the Legendary\l"
# 369 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Pokémon.\p"
# 370 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But! The Legendary Pokémon won't\n"
# 371 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "appear with just that wing...\p"
# 372 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Apparently there is something else\n"
# 373 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "you need... Or something like that.\p"
# 374 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wonder what it was...\p"
# 375 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I can't remember.$"
# 376 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 377 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
# 378 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Are you expecting something?\n"
# 379 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This is what they call Fake Out.\p"
# 380 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I really must go back to my office\n"
# 381 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "this time. See ya!$"
# 382 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 383 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
# 384 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 385 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You know, I love Pokémon.\p"
# 386 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I built this Radio Tower so I could\n"
# 387 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "express my love of Pokémon.\p"
# 388 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It would be nice if people enjoyed\n"
# 389 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our programs.$"
# 390 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 391 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break - Directs player toward Baoba
# 392 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorWest:
# 393 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 394 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Did you see the large winged Pokémon\n"
# 395 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "that flew past earlier?\p"
# 396 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's the talk of the town!\n"
# 397 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Or should I say, of the Radio Tower?\p"
# 398 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It seemed to be headed West, in the\n"
# 399 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "direction of Route 39.$"
# 400 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 401 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Ben:
# 402 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ben: Do you listen to our music?$"
# 403 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 404 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
# 405 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Director's   Office$"
# 406 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 407 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
# 408 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Studio 1$"

OakRadioTowerF5::
# 412 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
# 413 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 414 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 415 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
# 416 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 417 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_0
# 418 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_1
# 419 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_MEGA_RING
# 420 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_SOUTHPASSAGE_ARIANA
# 421 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_2
# 422 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_3
# 423 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 424 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_RADIOTOWER_OAK
# 425 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadedefaultbgm
# 426 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 100
# 427 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 428 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end


RadioTower_5F_Archer::
# 433 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 434 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 435 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_0
# 452 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHER, RadioTower_5F_Archer_Text_1
# 453 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHER
# 454 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_2
# 465 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 466 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 467 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 468 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 469 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 470 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 10
# 471 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARCHER
# 472 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARIANA
# 473 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 474 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 475 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_PETREL_OFFICE
# 476 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_F5_DIRECTOR_2
# 477 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_RADIOTOWER_OAK
# 478 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_GOLDENROD, TRUE
# 479 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 480 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 481 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	approachobject LOCALID_F5_DIRECTOR_2, LOCALID_PLAYER, DIR_WEST, DIR_EAST
# 482 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 483 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 484 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 485 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_3
# 500 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, RadioTower_5F_Archer_Text_4, RadioTower_5F_Archer_Text_5
# 501 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	switch VAR_RESULT
# 502 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	case 0, RadioTower_5F_Archer_3
# 516 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	case 1, RadioTower_5F_Archer_4
RadioTower_5F_Archer_1:
# 531 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_8
# 533 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_F5_DIRECTOR_2, RadioTower_5F_Archer_Movement_0
# 535 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 536 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 537 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_F5_DIRECTOR_2, Common_Movement_ExclamationMark
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 539 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_F5_DIRECTOR_2, DIR_WEST
# 540 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 541 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_9
# 551 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 552 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_F5_DIRECTOR_2, 29, 5, DIR_NORTH
# 553 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 554 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 555 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_F5_DIRECTOR_2
# 556 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 17
# 557 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
# 558 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 559 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 560 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
# 561 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 562 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_OAK
# 563 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_0
# 564 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_1
# 565 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_MEGA_RING
# 566 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_OAK
# 567 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_10
# 574 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_11
# 575 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 576 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 24, 5, DIR_WEST
# 577 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 578 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 579 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 580 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_ROCKET_TAKEOVER_CAP
# 581 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 582 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_RADIOTOWER_OAK
# 583 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	savebgm MUS_DUMMY
# 585 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadedefaultbgm
# 586 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end

RadioTower_5F_Archer_3:
# 503 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 2
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 505 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 506 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_6
	goto RadioTower_5F_Archer_1

RadioTower_5F_Archer_4:
# 517 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 1
# 518 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 519 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 520 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox RadioTower_5F_Archer_Text_7
	goto RadioTower_5F_Archer_1


GoldenrodCity_RadioTower_5F_EventScript_DirectorPath::
# 591 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_2
# 638 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_1:
# 640 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_2:
# 592 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_set FLAG_BEAT_DIRECTOR, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_5
# 595 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_0
# 599 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_1
# 613 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
# 614 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_2
# 616 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_DIRECTOR, GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_3
# 617 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 618 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_4
# 623 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	compare VAR_LUGIA_OR_HOOH, 1
	goto_if_eq GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_9
# 628 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 629 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_COMPLETED_LUGIA, 4
# 630 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_8:
# 632 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_BEAT_DIRECTOR
# 633 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_5
# 634 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_5:
# 593 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_1

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_9:
# 624 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 625 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_COMPLETED_HO_OH, 4
# 626 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_TINTOWER_GUARD
	goto GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_8


DirectorGotSilver::
# 645 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox DirectorGotSilver_Text_0
# 646 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end


DirectorGotRainbow::
# 651 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox DirectorGotRainbow_Text_0
# 652 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end


# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
RadioTower_5F_Archer_Movement_0:
# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
	step_end

OakRadioTowerF5_Text_0:
# 417 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}! You've pulled off a miracle\n"
	.string "by taking down Team Rocket!$"

OakRadioTowerF5_Text_1:
# 418 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I knew it was the right choice to\n"
	.string "entrust Pokédex to you. I want you to\l"
	.string "have this, I think you've more than\l"
	.string "earned it.$"

OakRadioTowerF5_Text_2:
# 421 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That is a Mega Ring. When combined with\n"
	.string "a Mega stone, it allows the bond\l"
	.string "between trainer and Pokémon to fully\l"
	.string "manifest. I'm sure you'll be able to pull\l"
	.string "it off.$"

OakRadioTowerF5_Text_3:
# 422 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now I must start heading back to Kanto,\n"
	.string "I hope you'll pay a visit to the Pallet\l"
	.string "Town at some point! Give my regards to\l"
	.string "Prof. Elm.$"

RadioTower_5F_Archer_Text_0:
# 435 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
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
# 452 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, Giovanni!$"

RadioTower_5F_Archer_Text_2:
# 454 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Archer: How could this be...?\p"
	.string "It seems I was not up to the task... \n"
	.string "Yet.\p"
	.string "We shall retreat for now, but know \n"
	.string "that Team Rocket roots run deeper \l"
	.string "in this region than you might think.\p"
	.string "We shall meet again, {PLAYER}.\n"
	.string "Farewell...$"

RadioTower_5F_Archer_Text_3:
# 485 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
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
# 500 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Rainbow Wing$"

RadioTower_5F_Archer_Text_5:
# 500 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Silver Wing$"

RadioTower_5F_Archer_Text_6:
# 506 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here.\p"
	.string "When the tower was replaced with the\n"
	.string "Radio Tower, that Rainbow Wing was \l"
	.string "found at the top of the tower.\p"
	.string "I heard from a friend from Cianwood\n"
	.string "City that you can climb the Bell\l"
	.string "Tower in Ecruteak City when you have a\l"
	.string "Rainbow Wing.$"

RadioTower_5F_Archer_Text_7:
# 520 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here.\p"
	.string "When the tower was replaced with the\n"
	.string "Radio Tower, that Silver Wing was \l"
	.string "found at the top of the tower.\p"
	.string "I heard from a friend from Cianwood\n"
	.string "City that you can go down the cave\l"
	.string "at Whirl Islands when you have a Silver\l"
	.string "Wing.$"

RadioTower_5F_Archer_Text_8:
# 531 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I have to get back to my office.\n"
	.string "See you!$"

RadioTower_5F_Archer_Text_9:
# 541 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh, I almost forgot!\p"
	.string "According to my friend from Cianwood,\n"
	.string "the legendary Pokémon will not appear\l"
	.string "if you just go to the place I mentioned.\l"
	.string "Apparently there is something else you\l"
	.string "need... Or something like that.\p"
	.string "I wonder what it was...\n"
	.string "I can't remember.$"

RadioTower_5F_Archer_Text_10:
# 567 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That is a Mega Ring. \p"
	.string "When combined with a Mega stone, \n"
	.string "it allows the bond between trainer \l"
	.string "and Pokémon to fully manifest. \p"
	.string "I'm sure you'll be able to pull it off.$"

RadioTower_5F_Archer_Text_11:
# 574 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now I must get back to my work, I hope\n"
	.string "you'll tune in to my next radio show!$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_0:
# 595 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ah, {PLAYER}!\p"
	.string "I heard you became the champion,\n"
	.string "congratulations!$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_1:
# 599 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I assume you're here for the other \n"
	.string "wing? Ho ho ho!\p"
	.string "I'd be more than happy to give it\n"
	.string "to you on one condition.\p"
	.string "I have been itching for a good\n"
	.string "battle for a very long time.\p"
	.string "Team Rocket ambushed me when I had\n"
	.string "no Pokémon. \p"
	.string "They would have stood no chance \n"
	.string "against my prized team.$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_2:
# 614 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I'll show you the power of a former\n"
	.string "Elite Four member, ho ho ho!$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_3:
# 616 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "What a nostalgic feeling!$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_4:
# 618 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You are truly above and beyond other\n"
	.string "trainers in Johto, {PLAYER}!\p"
	.string "I'm more than happy to hand this over\n"
	.string "to you.$"

GoldenrodCity_RadioTower_5F_EventScript_DirectorPath_Text_5:
# 633 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now go on and continue your legend!$"

DirectorGotSilver_Text_0:
# 645 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You chose Silver Wing$"

DirectorGotRainbow_Text_0:
# 651 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You chose Rainbow Wing$"
