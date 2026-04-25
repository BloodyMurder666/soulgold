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
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 48 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 49 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 50 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 51 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 52 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
# 53 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 54 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 55 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
# 56 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 57 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 58 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
# 59 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 60 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 61 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 62 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 63 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ Modified in 1.2.2 to retroactively fix the Baoba Sequence Break on a 1.2.1 save file
# 64 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Director::
# 65 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 66 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 67 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 68 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ If player has either wing, skip to default director
# 69 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	checkitem ITEM_SILVER_WING
# 70 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
# 71 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	checkitem ITEM_RAINBOW_WING
# 72 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_5F_EventScript_DirectorDone
# 73 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 74 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ If player has neither wing, and hasn't spoken to Baoba, direct them toward him
# 75 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_LUGIA_OR_HOOH, 0, GoldenrodCity_RadioTower_5F_EventScript_DirectorWest
# 76 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 77 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	@ If player has neither wing and has spoken to Baoba, give one
# 78 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain, MSGBOX_DEFAULT
# 79 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 80 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1, GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing2
# 81 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing2
# 82 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	
# 83 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 84 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 85 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 86 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
# 87 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 88 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 89 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 90 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 91 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 92 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorDone::
# 93 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
# 94 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 95 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 96 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 97 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 98 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_DirectorWest::
# 99 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorWest, MSGBOX_DEFAULT
# 100 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 101 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 102 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 103 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 104 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin:
# 105 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 106 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 107 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 108 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 109 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 110 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 111 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 112 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_8
# 113 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 114 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 115 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 116 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 117 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 118 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 119 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 120 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_4
# 121 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 122 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 123 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 124 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 125 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 126 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 127 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 128 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 129 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 130 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 131 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Spin2:
# 132 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_right
# 133 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 134 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_up
# 135 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 136 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_left
# 137 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay_2
# 138 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	face_down
# 139 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 140 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 141 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 142 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
# 143 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Y-you! You came to rescue me?$"
# 144 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 145 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
# 146 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Is that what you were expecting?\p"
# 147 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Wrong! I'm an imposter!\p"
# 148 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I pretended to be the real thing to\n"
# 149 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "prepare for our takeover.\p"
# 150 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Do you want to know where we hid\n"
# 151 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the real DIRECTOR?\p"
# 152 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Sure, I'll tell you. But only if you\n"
# 153 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "can beat me!$"
# 154 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 155 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
# 156 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "OK, OK. I'll tell you where he is.$"
# 157 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 158 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
# 159 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the DIRECTOR in\n"
# 160 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the UNDERGROUND WAREHOUSE.\p"
# 161 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the UNDER-\n"
# 162 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "GROUND.\p"
# 163 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I am a nice guy, I will give you\n"
# 164 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the BASEMENT KEY to get to the\l"
# 165 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "UNDERGROUND WAREHOUSE.\p"
# 166 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 167 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 168 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
# 169 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The boss stashed the DIRECTOR in\n"
# 170 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the UNDERGROUND WAREHOUSE.\p"
# 171 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's at the far end of the UNDER-\n"
# 172 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "GROUND.\p"
# 173 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You can use the BASEMENT KEY to\n"
# 174 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "get to the UNDERGROUND WAREHOUSE.\p"
# 175 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But I doubt you'll get that far.$"
# 176 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 177 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@=======[STUDIO]==============================================================================================================================
# 178 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 179 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Ben::
# 180 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 181 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 182 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
# 183 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 184 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 185 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 186 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 187 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodRaidoTower4_EventScript_ARIANA::
# 188 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
# 189 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
# 190 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 191 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 192 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Archer::
# 193 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	lock
# 194 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	faceplayer
# 195 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
# 196 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHER, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
# 197 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
# 198 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 55
# 199 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 200 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 201 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 202 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_EXIT
# 203 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 10
# 204 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARCHER
# 205 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_GOLDENROD_ARIANA
# 206 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 207 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 208 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_PETREL_OFFICE
# 209 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	addobject LOCALID_DIRECTOR_STUDIO
# 210 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playbgm MUS_HG_GOLDENROD, TRUE
# 211 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 120
# 212 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 213 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
# 214 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
# 215 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
# 216 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 217 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 218 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 219 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingTop::
# 220 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
# 221 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 222 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 223 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 224 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 225 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 226 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 227 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
# 228 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 229 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 230 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 231 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 232 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingMid::
# 233 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
# 234 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 235 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 236 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 237 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 238 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 239 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 240 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
# 241 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 242 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 243 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 244 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 245 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_WingBot::
# 246 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
# 247 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 248 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 249 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
# 250 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 251 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 1, GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
# 252 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
# 253 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
# 254 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 255 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	goto GoldenrodCity_RadioTower_5F_Fakeout
# 256 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 257 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 258 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
# 259 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 260 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
# 261 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 262 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 263 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 264 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 265 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 266 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing2::
# 267 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_SILVER_WING
# 268 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2, MSGBOX_DEFAULT
# 269 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 270 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 271 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 272 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 273 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
# 274 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 275 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
# 276 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 277 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 278 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 279 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 280 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 281 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing2::
# 282 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	giveitem ITEM_RAINBOW_WING
# 283 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2, MSGBOX_DEFAULT
# 284 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 285 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 286 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	return
# 287 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 288 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Fakeout::
# 289 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 290 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 291 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 292 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
# 293 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
# 294 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 295 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
# 296 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 297 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	playse SE_PIN
# 298 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
# 299 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	delay 60
# 300 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
# 301 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
# 302 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	closemessage
# 303 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
# 304 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	waitmovement 0
# 305 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 306 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	removeobject LOCALID_DIRECTOR_STUDIO
# 307 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 17
# 308 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	release
# 309 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 310 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 311 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
# 312 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 313 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 11
# 314 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	end
# 315 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 316 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
# 317 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 318 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 319 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 320 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 321 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 322 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 323 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 324 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 325 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 326 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 327 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 328 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
# 329 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 330 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 331 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 332 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 333 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 334 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
# 335 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 336 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 337 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 338 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 339 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 340 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 341 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 342 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 343 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 344 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 345 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 346 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 347 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
# 348 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 349 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 350 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 351 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 352 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
# 353 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 354 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
# 355 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_down
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
	walk_left
# 362 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 363 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_left
# 364 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 365 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 366 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
# 367 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 368 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 369 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_right
# 370 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 371 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 372 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave1:
# 373 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 374 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 375 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 376 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 377 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Movement_Leave2:
# 378 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 379 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 380 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 381 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	walk_up
# 382 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	step_end
# 383 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 384 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
# 385 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Remember me from the HIDEOUT in\n"
# 386 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "MAHOGANY TOWN?\p"
# 387 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "My boss scolded me but I'm stronger.\p"
# 388 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I lost then, but I won't this time.$"
# 389 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 390 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
# 391 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This can't be happening!\p"
# 392 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I fought hard, but I still lost…\p"
# 393 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I'm so sorry GIOVANNI…$"
# 394 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 395 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
# 396 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "{PLAYER}, isn't it?\p"
# 397 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "A brat like you won't appreciate\n"
# 398 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "the magnificence of TEAM ROCKET.\p"
# 399 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That's too bad. I really admire\n"
# 400 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "your power.$"
# 401 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 402 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
# 403 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Oh? You managed to get this far?\p"
# 404 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You must be quite the trainer.\p"
# 405 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We intend to take over this RADIO\n"
# 406 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "STATION and announce our comeback.\p"
# 407 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That should bring our boss GIOVANNI\n"
# 408 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "back from his solitary training.\p"
# 409 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We are going to regain our former\n"
# 410 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "glory...\p"
# 411 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I won't allow you to interfere with\n"
# 412 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our meticulous plans!$"
# 413 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 414 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
# 415 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "No! Forgive me, GIOVANNI!$"
# 416 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 417 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
# 418 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "How could this be?\p"
# 419 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Our dreams have come to naught.\p"
# 420 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wasn't up to the task after all.\p"
# 421 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Like GIOVANNI did before me, I will\n"
# 422 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "disband TEAM ROCKET here today.\p"
# 423 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Farewell.$"
# 424 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 425 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
# 426 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "DIRECTOR: {PLAYER}, thank you!\p"
# 427 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Your courageous actions have saved\n"
# 428 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "POKéMON nationwide.\p"
# 429 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 430 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 431 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 432 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorThanksAgain:
# 433 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "DIRECTOR: {PLAYER}, once again, thank you!\p"
# 434 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "The large winged POKéMON that flew past\n"
# 435 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "reminded me, I have a reward for your\l"
# 436 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "courageous actions.\p"
# 437 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I know it's not much, but please\n"
# 438 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "take this.$"
# 439 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 440 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
# 441 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 442 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in GOLDENROD CITY.\p"
# 443 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 444 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our RADIO\n"
# 445 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TOWER.\p"
# 446 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 447 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 448 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 449 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in GOLDENROD in the past.\p"
# 450 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 451 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 452 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TIN TOWER in ECRUTEAK CITY…\p"
# 453 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "OK, I better go to my OFFICE.$"
# 454 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 455 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 456 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation2:
# 457 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 458 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in GOLDENROD CITY.\p"
# 459 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 460 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our RADIO\n"
# 461 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TOWER.\p"
# 462 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 463 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 464 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 465 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in GOLDENROD in the past.\p"
# 466 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 467 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 468 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TIN TOWER in ECRUTEAK CITY…$"
# 469 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 470 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
# 471 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 472 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in GOLDENROD CITY.\p"
# 473 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 474 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our RADIO\n"
# 475 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TOWER.\p"
# 476 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 477 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 478 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 479 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in GOLDENROD in the past.\p"
# 480 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 481 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 482 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "WHIRL ISLANDS near CIANWOOD CITY…\p"
# 483 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "OK, I better go to my OFFICE.$"
# 484 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 485 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break version - slightly different text
# 486 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation2:
# 487 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "There used to be a tower right here\n"
# 488 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "in GOLDENROD CITY.\p"
# 489 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But it was old and creaky.\p"
# 490 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "So we replaced it with our RADIO\n"
# 491 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "TOWER.\p"
# 492 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "We dug up that wing during\n"
# 493 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "construction.\p"
# 494 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I heard that all sorts of POKéMON\n"
# 495 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "lived in GOLDENROD in the past.\p"
# 496 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Perhaps…\p"
# 497 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing has some connection to the\n"
# 498 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "WHIRL ISLANDS near CIANWOOD CITY…$"
# 499 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 500 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
# 501 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Ah!\p"
# 502 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That reminds me…\p"
# 503 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "That wing I gave you... I think\n"
# 504 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "it's related to the LEGENDARY\l"
# 505 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "POKéMON.\p"
# 506 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "But! The LEGENDARY POKéMON won't\n"
# 507 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "appear with just that wing...\p"
# 508 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Apparently there is something else\n"
# 509 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "you need... Or something like that.\p"
# 510 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I wonder what it was...\p"
# 511 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I can't remember.$"
# 512 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 513 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
# 514 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Are you expecting something?\n"
# 515 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "This is what they call FAKE OUT.\p"
# 516 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I really must go back to my office\n"
# 517 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "this time. See ya!$"
# 518 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 519 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
# 520 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "DIRECTOR: Hello, {PLAYER}!\p"
# 521 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "You know, I love POKéMON.\p"
# 522 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "I built this RADIO TOWER so I could\n"
# 523 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "express my love of POKéMON.\p"
# 524 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It would be nice if people enjoyed\n"
# 525 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "our programs.$"
# 526 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 527 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
@ 1.2.1 Sequence Break - Directs player toward Baoba
# 528 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorWest:
# 529 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "DIRECTOR: Hello, {PLAYER}!\p"
# 530 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Did you see the large winged POKéMON\n"
# 531 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "that flew past earlier?\p"
# 532 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It's the talk of the town!\n"
# 533 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "Or should I say, of the RADIO TOWER?\p"
# 534 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "It seemed to be headed West, in the\n"
# 535 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "direction of ROUTE 39.$"
# 536 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 537 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Ben:
# 538 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "BEN: Do you listen to our music?$"
# 539 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 540 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
# 541 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F DIRECTOR'S   OFFICE$"
# 542 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"

# 543 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
# 544 "data/maps/GoldenrodCity_RadioTower_5F/scripts.pory"
	.string "5F STUDIO 1$"
