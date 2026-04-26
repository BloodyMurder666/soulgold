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
.set LOCALID_DIRECTOR_STUDIO, 5
# 7 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 8 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_MapScripts::
# 9 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
# 10 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.byte 0
# 11 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 12 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ During Rocket Takeover, hide Petrel and show the Director (Petrel in disguise)
# 13 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_OnLoad::
# 14 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
# 15 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 16 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 17 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
# 18 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 19 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 20 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 21 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 22 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 23 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[OFFICE]==============================================================================================================================
# 24 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 25 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Petrel::
# 26 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 27 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ After Rocket Takeover, this is the real Director
# 28 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
# 29 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
# 30 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_SELECT
# 31 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 32 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
# 33 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 34 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
# 35 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 36 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 37 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_DIRECTOR_OFFICE
# 38 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
    removeobject LOCALID_RADIOTOWER_OAK
# 39 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 40 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_PETREL_OFFICE
# 41 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
# 42 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 43 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
# 44 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
# 45 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
# 46 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_BASEMENT_KEY
# 47 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 7
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
	@ If player has neither wing, and hasn't spoken to Baoba, direct them toward him
# 76 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_LUGIA_OR_HOOH, 0, GoldenrodCity_RadioTower_5F_EventScript_DirectorWest
# 77 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 78 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ If player has neither wing and has spoken to Baoba, give one
# 79 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain, MSGBOX_DEFAULT
# 80 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 81 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1, GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing2
# 82 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing2
# 83 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 84 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 85 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 86 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 87 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
# 88 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 89 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 90 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 91 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 92 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 93 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorDone::
# 94 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
# 95 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 96 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 97 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 98 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 99 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorWest::
# 100 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorWest, MSGBOX_DEFAULT
# 101 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 102 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 103 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 104 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 105 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin:
# 106 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 107 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 108 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 109 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 110 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 111 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 112 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 113 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 114 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 115 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 116 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 117 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 118 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 119 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 120 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 121 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 122 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 123 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 124 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 125 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 126 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 127 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 128 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 129 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 130 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 131 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 132 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin2:
# 133 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 134 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 135 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 136 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 137 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 138 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 139 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 140 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 141 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 142 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 143 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
# 144 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Y-you! You came to rescue me?$"
# 145 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 146 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
# 147 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Is that what you were expecting?\p"
# 148 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Wrong! I'm an imposter!\p"
# 149 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I pretended to be the real thing to\n"
# 150 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "prepare for our takeover.\p"
# 151 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Do you want to know where we hid\n"
# 152 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the real Director?\p"
# 153 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Sure, I'll tell you. But only if you\n"
# 154 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "can beat me!$"
# 155 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 156 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
# 157 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, Ok. I'll tell you where he is.$"
# 158 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 159 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
# 160 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 161 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 162 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 163 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 164 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I am a nice guy, I will give you\n"
# 165 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Basement Key to get to the\l"
# 166 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Underground Warehouse.\p"
# 167 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 168 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 169 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
# 170 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the Director in\n"
# 171 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the Underground Warehouse.\p"
# 172 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the Under-\n"
# 173 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ground.\p"
# 174 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You can use the Basement Key to\n"
# 175 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "get to the Underground Warehouse.\p"
# 176 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 177 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 178 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[STUDIO]==============================================================================================================================
# 179 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 180 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Ben::
# 181 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 182 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 183 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
# 184 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 185 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 186 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 187 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 188 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodRaidoTower4_EventScript_ARIANA::
# 189 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
# 190 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
# 191 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 192 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 193 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Archer::
# 194 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 195 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 196 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
# 197 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHER, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
# 198 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
# 199 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 55
# 200 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 201 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 202 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 203 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 204 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 10
# 205 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARCHER
# 206 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARIANA
# 207 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 208 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 209 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_PETREL_OFFICE
# 210 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_DIRECTOR_STUDIO
# 211 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
    addobject LOCALID_RADIOTOWER_OAK
# 212 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_GOLDENROD, TRUE
# 213 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 120
# 214 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 215 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
# 216 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
# 217 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
# 218 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 219 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 220 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 221 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingTop::
# 222 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
# 223 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 224 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 225 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 226 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 227 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 228 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 229 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
# 230 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 231 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 232 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 233 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 234 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingMid::
# 235 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
# 236 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 237 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 238 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 239 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 240 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 241 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 242 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
# 243 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 244 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 245 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 246 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 247 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingBot::
# 248 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
# 249 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 250 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 251 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 252 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 253 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1, GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 254 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 255 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
# 256 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 257 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 258 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 259 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 260 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
# 261 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 262 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
# 263 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 264 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 265 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 266 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 267 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 268 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing2::
# 269 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 270 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2, MSGBOX_DEFAULT
# 271 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 272 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 273 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 274 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 275 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
# 276 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 277 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
# 278 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 279 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 280 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 281 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 282 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 283 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing2::
# 284 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 285 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2, MSGBOX_DEFAULT
# 286 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 287 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 288 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 289 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 290 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Fakeout::
# 291 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 292 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 293 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 294 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
# 295 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
# 296 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 297 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
# 298 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 299 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 300 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 301 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 302 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
# 303 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
# 304 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 305 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
# 306 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 307 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 308 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_DIRECTOR_STUDIO
# 309 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 17
# 310 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
    goto OakRadioTowerF5
# 311 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 312 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 313 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 314 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
# 315 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 316 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 317 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 318 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 319 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
# 320 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 321 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 322 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 323 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 324 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 325 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 326 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 327 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 328 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 329 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 330 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 331 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
# 332 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 333 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 334 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 335 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 336 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 337 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
# 338 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 339 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 340 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 341 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 342 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 343 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 344 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 345 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 346 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 347 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 348 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 349 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 350 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
# 351 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 352 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 353 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 354 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 355 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
# 356 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 357 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 358 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 359 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 360 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 361 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 362 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 363 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 364 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 365 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 366 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 367 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 368 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 369 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
# 370 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 371 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 372 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 373 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 374 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 375 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave1:
# 376 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 377 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 378 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 379 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 380 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave2:
# 381 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 382 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 383 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 384 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 385 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 386 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 387 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
# 388 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Remember me from the Hideout in\n"
# 389 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Mahogany Town?\p"
# 390 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "My boss scolded me but I'm stronger.\p"
# 391 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I lost then, but I won't this time.$"
# 392 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 393 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
# 394 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This can't be happening!\p"
# 395 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I fought hard, but I still lost…\p"
# 396 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I'm so sorry Giovanni…$"
# 397 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 398 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
# 399 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}, isn't it?\p"
# 400 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "A brat like you won't appreciate\n"
# 401 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the magnificence of Team Rocket.\p"
# 402 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That's too bad. I really admire\n"
# 403 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "your power.$"
# 404 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 405 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
# 406 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh? You managed to get this far?\p"
# 407 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You must be quite the trainer.\p"
# 408 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We intend to take over this Radio\n"
# 409 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Station and announce our comeback.\p"
# 410 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That should bring our boss Giovanni\n"
# 411 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "back from his solitary training.\p"
# 412 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We are going to regain our former\n"
# 413 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "glory...\p"
# 414 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I won't allow you to interfere with\n"
# 415 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our meticulous plans!$"
# 416 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 417 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
# 418 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, Giovanni!$"
# 419 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 420 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
# 421 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "How could this be?\p"
# 422 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Our dreams have come to naught.\p"
# 423 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wasn't up to the task after all.\p"
# 424 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Like Giovanni did before me, I will\n"
# 425 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "disband Team Rocket here today.\p"
# 426 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Farewell.$"
# 427 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 428 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
# 429 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, thank you!\p"
# 430 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Your courageous actions have saved\n"
# 431 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "POKéMON nationwide.\p"
# 432 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 433 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 434 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 435 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain:
# 436 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: {PLAYER}, once again, thank you!\p"
# 437 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The large winged POKéMON that flew past\n"
# 438 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "reminded me, I have a reward for your\l"
# 439 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "courageous actions.\p"
# 440 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 441 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 442 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 443 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
# 444 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 445 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 446 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 447 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 448 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 449 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 450 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 451 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 452 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 453 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 454 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 455 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…\p"
# 456 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 457 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 458 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 459 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2:
# 460 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 461 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 462 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 463 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 464 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 465 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 466 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 467 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 468 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 469 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 470 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 471 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tin Tower in Ecruteak City…$"
# 472 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 473 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
# 474 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 475 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 476 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 477 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 478 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 479 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 480 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 481 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 482 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 483 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 484 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 485 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…\p"
# 486 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ok, I better go to my Office.$"
# 487 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 488 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 489 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2:
# 490 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 491 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in Goldenrod City.\p"
# 492 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 493 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our Radio\n"
# 494 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Tower.\p"
# 495 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 496 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 497 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 498 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in Goldenrod in the past.\p"
# 499 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 500 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 501 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Whirl Islands near Cianwood City…$"
# 502 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 503 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ah!\p"
# 505 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That reminds me…\p"
# 506 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing I gave you... I think\n"
# 507 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "it's related to the Legendary\l"
# 508 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "POKéMON.\p"
# 509 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But! The Legendary POKéMON won't\n"
# 510 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "appear with just that wing...\p"
# 511 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Apparently there is something else\n"
# 512 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "you need... Or something like that.\p"
# 513 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wonder what it was...\p"
# 514 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I can't remember.$"
# 515 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 516 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
# 517 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Are you expecting something?\n"
# 518 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This is what they call Fake Out.\p"
# 519 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I really must go back to my office\n"
# 520 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "this time. See ya!$"
# 521 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 522 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
# 523 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 524 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You know, I love POKéMON.\p"
# 525 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I built this Radio Tower so I could\n"
# 526 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "express my love of POKéMON.\p"
# 527 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It would be nice if people enjoyed\n"
# 528 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our programs.$"
# 529 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 530 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break - Directs player toward Baoba
# 531 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorWest:
# 532 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Director: Hello, {PLAYER}!\p"
# 533 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Did you see the large winged POKéMON\n"
# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "that flew past earlier?\p"
# 535 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's the talk of the town!\n"
# 536 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Or should I say, of the Radio Tower?\p"
# 537 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It seemed to be headed West, in the\n"
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "direction of Route 39.$"
# 539 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 540 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Ben:
# 541 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ben: Do you listen to our music?$"
# 542 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 543 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
# 544 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Director'S   Office$"
# 545 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 546 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
# 547 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F Studio 1$"

OakRadioTowerF5::
# 551 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords OBJ_EVENT_ID_PLAYER, 28, 11, DIR_NORTH
# 552 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 553 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 554 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	moveobjecttocoords LOCALID_RADIOTOWER_OAK, 28, 10, DIR_SOUTH
# 555 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 556 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_0
# 557 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_1
# 558 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_MEGA_RING
# 559 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_2
# 560 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox OakRadioTowerF5_Text_3
# 561 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 562 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_RADIOTOWER_OAK
# 563 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadedefaultbgm
# 564 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 100
# 565 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 566 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
	end


OakRadioTowerF5_Text_0:
# 556 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}! You've pulled off a miracle\n"
	.string "by taking down Team Rocket!$"

OakRadioTowerF5_Text_1:
# 557 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I knew it was the right choice to\n"
	.string "entrust Pokédex to you. I want you to\l"
	.string "have this, I think you've more than\l"
	.string "earned it.$"

OakRadioTowerF5_Text_2:
# 559 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That is a Mega Ring. When combined with\n"
	.string "a Mega stone, it allows the bond\l"
	.string "between trainer and Pokémon to fully\l"
	.string "manifest. I'm sure you'll be able to pull\l"
	.string "it off.$"

OakRadioTowerF5_Text_3:
# 560 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Now I must start heading back to Kanto,\n"
	.string "I hope you'll pay a visit to the Pallet\l"
	.string "Town at some point! Give my regards to\l"
	.string "Prof. Elm.$"
