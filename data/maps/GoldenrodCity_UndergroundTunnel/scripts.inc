# 1 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 2 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
.set LOCALID_GOLDENROD_UNDERGROUND_KIMONO, 12
# 3 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 4 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScripts::
# 5 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
# 6 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.byte 0
# 7 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 8 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_OnLoad::
# 9 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
# 10 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 11 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	
# 12 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
# 13 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 14 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 15 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
# 16 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 17 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
# 18 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 19 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_PIN
# 20 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
# 21 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	delay 60
# 22 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
# 23 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 24 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
# 25 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 26 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
# 27 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 28 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_M_PETAL_DANCE
# 29 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
# 30 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 31 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
# 32 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 33 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 34 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
# 35 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadedefaultbgm
# 36 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 8
# 37 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 38 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 39 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
# 40 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 41 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 42 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
# 43 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 44 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
# 45 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 46 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_PIN
# 47 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
# 48 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	delay 60
# 49 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
# 50 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 51 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
# 52 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 53 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
# 54 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 55 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_M_PETAL_DANCE
# 56 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
# 57 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 58 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
# 59 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 60 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 61 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
# 62 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadedefaultbgm
# 63 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 8
# 64 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 65 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 66 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 67 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
# 68 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 69 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 70 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 71 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 72 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 73 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 74 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
# 75 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 76 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 77 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 78 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 79 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 80 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 81 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 82 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
# 83 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 84 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 85 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 86 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 87 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 88 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 89 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 90 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 91 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 92 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
# 93 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_down
# 94 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_right
# 95 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_up
# 96 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_left
# 97 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_down
# 98 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_right
# 99 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_up
# 100 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 101 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 102 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
# 103 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 104 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 105 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 106 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 107 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 108 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 109 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 110 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 111 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 112 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Text_Kimono1:
# 113 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Team Rocket members in black suits\n"
# 114 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "have been running around...\p"
# 115 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "I was wondering what was going on.\n"
# 116 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "So, you took on Team Rocket?\l"
# 117 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "You are impressive!\p"
# 118 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "You may be able to face the\n"
# 119 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "legendary POKé...$"
# 120 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 121 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Text_Kimono2:
# 122 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Hahaha! Never mind.\n"
# 123 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "I must go now.$"
# 124 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 125 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Eric::
# 126 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_ERIC GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
# 127 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
# 128 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 129 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 130 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Teru::
# 131 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_TERU GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
# 132 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
# 133 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 134 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 135 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Issac::
# 136 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_ISSAC GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
# 137 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
# 138 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 139 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 140 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Donald::
# 141 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_DONALD GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
# 142 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
# 143 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 144 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 145 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Brother_Haircut1::
# 146 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 147 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 148 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GARBAGEFLAG, GoldenrodUnderground_EventScript_Already_Got_Haircut1
# 149 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 150 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
# 151 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
# 152 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
# 153 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 154 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 155 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 156 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 157 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Haircut1::
# 158 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
# 159 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special ChoosePartyMon
# 160 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitstate
# 161 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 162 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 163 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 164 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
# 165 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 166 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
# 167 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkmoney 500, 0
# 168 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
# 169 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removemoney 500
# 170 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	updatemoneybox 0
# 171 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_SHOP
# 172 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
# 173 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 174 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_TO_BLACK
# 175 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playfanfare MUS_HEAL
# 176 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitfanfare
# 177 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special HaircutBrother1
# 178 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 179 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special BufferMonNickname
# 180 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
# 181 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 182 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_GARBAGEFLAG
# 183 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 184 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 185 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 186 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Declined_Haircut1::
# 187 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
# 188 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 189 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 190 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 191 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 192 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 193 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Already_Got_Haircut1::
# 194 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
# 195 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 196 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 197 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 198 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 199 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_NotEnough_Haircut1::
# 200 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
# 201 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 202 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 203 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 204 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 205 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 206 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 207 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Brother_Haircut2::
# 208 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 209 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 210 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GARBAGEFLAG, GoldenrodUnderground_EventScript_Already_Got_Haircut2
# 211 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 212 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
# 213 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
# 214 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
# 215 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 216 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 217 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 218 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 219 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Haircut2::
# 220 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
# 221 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special ChoosePartyMon
# 222 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitstate
# 223 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 224 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 225 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 226 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
# 227 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 228 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
# 229 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkmoney 300, 0
# 230 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
# 231 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removemoney 300
# 232 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	updatemoneybox 0
# 233 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_SHOP
# 234 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
# 235 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 236 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_TO_BLACK
# 237 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playfanfare MUS_HEAL
# 238 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitfanfare
# 239 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special HaircutBrother1
# 240 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 241 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special BufferMonNickname
# 242 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
# 243 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 244 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_GARBAGEFLAG
# 245 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 246 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 247 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 248 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Declined_Haircut2::
# 249 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
# 250 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 251 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 252 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 253 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 254 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 255 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Already_Got_Haircut2::
# 256 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
# 257 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 258 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 259 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 260 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 261 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_NotEnough_Haircut2::
# 262 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
# 263 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 264 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 265 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 266 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 267 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 268 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 269 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
# 270 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
# 271 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 272 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 273 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
# 274 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setmetatile 12, 10, 0x2DD, FALSE
# 275 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 276 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 277 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_Door::
# 278 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 279 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
# 280 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkitem ITEM_BASEMENT_KEY
# 281 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
# 282 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
# 283 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 284 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 285 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 286 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 287 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
# 288 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
# 289 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 290 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 291 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setmetatile 12, 10, 0x2DD, FALSE
# 292 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_BANG
# 293 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special DrawWholeMapView
# 294 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitse
# 295 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 296 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 297 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 298 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
# 299 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
# 300 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 301 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 302 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 303 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 304 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 305 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherOffer:
# 306 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Welcome to the Pokémon Salon!\p"
# 307 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm the younger and less expensive\n"
# 308 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "of the two Haircut Brothers.\p"
# 309 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'll spiff up your Pokémon for just\n"
# 310 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "¥300.\p"
# 311 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "So? How about it?$"
# 312 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 313 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherAskWhich:
# 314 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok, which Pokémon should I do?$"
# 315 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 316 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherLookCool:
# 317 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok! I'll make it look cool!$"
# 318 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 319 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherAllDone:
# 320 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "There we go! All done!$"
# 321 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 322 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherDisappointed:
# 323 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "No? How disappointing!$"
# 324 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 325 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
# 326 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "You're a little short on funds.$"
# 327 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 328 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
# 329 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I can do only one haircut a day.\p"
# 330 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Sorry, but I'm all done for today.$"
# 331 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 332 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 333 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 334 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherOffer:
# 335 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Welcome!\p"
# 336 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I run the Pokémon Salon!\p"
# 337 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm the older and better of the two\n"
# 338 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Haircut Brothers.\p"
# 339 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I can make your Pokémon beautiful\n"
# 340 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "for just ¥500.\p"
# 341 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Would you like me to do that?$"
# 342 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 343 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherAskWhich:
# 344 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Which Pokémon should I work on?$"
# 345 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 346 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
# 347 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok! Watch it become beautiful!$"
# 348 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 349 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherAllDone:
# 350 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "There! All done!$"
# 351 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 352 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherThatsAShame:
# 353 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Is that right? That's a shame!$"
# 354 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 355 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
# 356 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "You'll need more money than that.$"
# 357 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 358 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherOnePerDay:
# 359 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I do only one haircut a day.\n"
# 360 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm done for today.$"
# 361 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 362 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricSeen:
# 363 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I got booted out of the Game Corner.\p"
# 364 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I was trying to cheat using my\n"
# 365 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Pokémon…$"
# 366 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 367 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricBeaten:
# 368 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "…Grumble…$"
# 369 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 370 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricAfterBattle:
# 371 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I guess I have to do things fair and\n"
# 372 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "square…$"
# 373 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 374 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruSeen:
# 375 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Do you consider type alignments in\n"
# 376 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "battle?\p"
# 377 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "If you know your type advantages,\n"
# 378 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "you'll do better in battle.$"
# 379 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 380 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruBeaten:
# 381 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ow, ow, ow!$"
# 382 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 383 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
# 384 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I know my Pokémon type alignments.\p"
# 385 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "But I only use one type of Pokémon.$"
# 386 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 387 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacSeen:
# 388 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "My Pokémon just got a haircut!\p"
# 389 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'll show you how strong it is!$"
# 390 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 391 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacBeaten:
# 392 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Aiyeeee!$"
# 393 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 394 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
# 395 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Your Pokémon will like you more if\n"
# 396 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "you give them haircuts.$"
# 397 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 398 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldSeen:
# 399 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I think you have some rare Pokémon\n"
# 400 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "with you.\p"
# 401 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Let me see them!$"
# 402 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 403 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
# 404 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Gaah! I lost! That makes me mad!$"
# 405 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 406 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
# 407 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "When I was walking near the Bike\n"
# 408 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Shop last night, I felt like I was\l"
# 409 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "being watched from the rooftops...$"
# 410 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 411 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
# 412 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Are you making a POKéDEX? Here's a\n"
# 413 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "hot tip.\p"
# 414 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The Hiker on Route 33, Anthony, is a\n"
# 415 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "good guy.\p"
# 416 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "He'll phone you if he sees any rare\n"
# 417 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Pokémon.$"
# 418 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 419 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_DoorsLocked:
# 420 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The door's locked…$"
# 421 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 422 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_DoorIsOpen:
# 423 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The door is open.$"
# 424 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 425 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_KeyOpenedDoor:
# 426 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The Basement Key opened the door.$"
# 427 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 428 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_NoEntry:
# 429 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "No Entry Beyond This Point$"

goldenrod_utility_shop_girl::
# 434 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 435 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox goldenrod_utility_shop_girl_Text_0
# 436 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmessage
# 437 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	pokemart goldenrod_utility_shop
# 438 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox goldenrod_utility_shop_girl_Text_1
# 439 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	return


	.align 2
# 442 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
goldenrod_utility_shop:
# 443 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
# 444 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_COVERT_CLOAK
# 445 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_ABILITY_SHIELD
# 446 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_CLEAR_AMULET
	.2byte ITEM_NONE

suspiciousdoor_goldenrod_underground::
# 450 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 451 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox suspiciousdoor_goldenrod_underground_Text_0
# 452 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmessage
# 453 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	end


rocket_bouncer::
# 458 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 459 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 460 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GOLDEN_COLOSSEUM, rocket_bouncer_2
# 463 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox rocket_bouncer_Text_1
rocket_bouncer_1:
# 465 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	end

rocket_bouncer_2:
# 461 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox rocket_bouncer_Text_0
	goto rocket_bouncer_1


goldenrod_utility_shop_girl_Text_0:
# 435 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Hi, take a look at my exclusive wares!$"

goldenrod_utility_shop_girl_Text_1:
# 438 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Come on, buy some more!$"

suspiciousdoor_goldenrod_underground_Text_0:
# 451 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Door seems to be locked, but you can\n"
	.string "faintly discern noise coming from\l"
	.string "somewhere far behind the door.$"

rocket_bouncer_Text_0:
# 461 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "TODO$"

rocket_bouncer_Text_1:
# 463 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Sorry kid, only those with special\n"
	.string "permission are allowed past here.$"
