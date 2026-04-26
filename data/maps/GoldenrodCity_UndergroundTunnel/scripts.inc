# 1 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 2 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 3 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScripts::
# 4 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
# 5 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.byte 0
# 6 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 7 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_OnLoad::
# 8 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
# 9 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 10 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	
# 11 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
# 12 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 13 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 14 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
# 15 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 16 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
# 17 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 18 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_PIN
# 19 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
# 20 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	delay 60
# 21 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
# 22 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 23 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
# 24 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 25 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
# 26 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 27 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_M_PETAL_DANCE
# 28 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
# 29 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 30 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
# 31 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 32 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 33 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
# 34 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadedefaultbgm
# 35 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 8
# 36 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 37 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 38 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
# 39 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 40 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 41 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
# 42 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 43 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
# 44 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 45 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_PIN
# 46 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
# 47 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	delay 60
# 48 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
# 49 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 50 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
# 51 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 52 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
# 53 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 54 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_M_PETAL_DANCE
# 55 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
# 56 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 57 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
# 58 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmovement 0
# 59 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 60 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
# 61 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadedefaultbgm
# 62 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 8
# 63 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 64 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 65 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 66 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
# 67 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 68 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 69 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 70 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 71 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 72 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 73 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
# 74 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
# 75 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 76 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 77 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 78 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
# 79 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 80 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 81 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
# 82 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_left
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
	step_end
# 90 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 91 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
# 92 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_down
# 93 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_right
# 94 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_up
# 95 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_left
# 96 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_down
# 97 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_right
# 98 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	face_up
# 99 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	step_end
# 100 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 101 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
# 102 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	walk_up
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
	step_end
# 109 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 110 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 111 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Text_Kimono1:
# 112 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Team Rocket members in black suits\n"
# 113 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "have been running around...\p"
# 114 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "I was wondering what was going on.\n"
# 115 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "So, you took on Team Rocket?\l"
# 116 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "You are impressive!\p"
# 117 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "You may be able to face the\n"
# 118 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "legendary POKé...$"
# 119 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 120 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_Text_Kimono2:
# 121 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Hahaha! Never mind.\n"
# 122 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "I must go now.$"
# 123 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 124 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Eric::
# 125 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_ERIC GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
# 126 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
# 127 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 128 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 129 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Teru::
# 130 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_TERU GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
# 131 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
# 132 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 133 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 134 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Issac::
# 135 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_ISSAC GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
# 136 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 138 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 139 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Donald::
# 140 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	trainerbattle_single TRAINER_DONALD GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
# 141 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
# 142 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 143 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 144 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Brother_Haircut1::
# 145 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 146 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 147 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GARBAGEFLAG, GoldenrodUnderground_EventScript_Already_Got_Haircut1
# 148 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 149 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
# 150 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
# 151 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
# 152 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 153 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 154 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 155 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 156 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Haircut1::
# 157 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
# 158 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special ChoosePartyMon
# 159 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitstate
# 160 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 161 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 162 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 163 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
# 164 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 165 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
# 166 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkmoney 500, 0
# 167 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
# 168 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removemoney 500
# 169 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	updatemoneybox 0
# 170 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_SHOP
# 171 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
# 172 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 173 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_TO_BLACK
# 174 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playfanfare MUS_HEAL
# 175 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitfanfare
# 176 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special HaircutBrother1
# 177 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 178 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special BufferMonNickname
# 179 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
# 180 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 181 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_GARBAGEFLAG
# 182 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 183 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 184 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 185 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Declined_Haircut1::
# 186 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
# 187 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 188 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 189 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 190 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 191 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 192 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Already_Got_Haircut1::
# 193 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
# 194 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 195 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 196 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 197 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 198 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_NotEnough_Haircut1::
# 199 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
# 200 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 201 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 202 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 203 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 204 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 205 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 206 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Brother_Haircut2::
# 207 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 208 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 209 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GARBAGEFLAG, GoldenrodUnderground_EventScript_Already_Got_Haircut2
# 210 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 211 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
# 212 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
# 213 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
# 214 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 215 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 216 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 217 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 218 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Haircut2::
# 219 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
# 220 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special ChoosePartyMon
# 221 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitstate
# 222 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	showmoneybox 0, 0
# 223 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 224 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 225 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
# 226 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 227 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
# 228 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkmoney 300, 0
# 229 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
# 230 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	removemoney 300
# 231 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	updatemoneybox 0
# 232 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_SHOP
# 233 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
# 234 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 235 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_TO_BLACK
# 236 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playfanfare MUS_HEAL
# 237 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitfanfare
# 238 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special HaircutBrother1
# 239 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 240 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special BufferMonNickname
# 241 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
# 242 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 243 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_GARBAGEFLAG
# 244 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 245 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 246 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 247 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Declined_Haircut2::
# 248 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
# 249 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 250 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 251 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 252 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 253 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 254 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_Already_Got_Haircut2::
# 255 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
# 256 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 257 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 258 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 259 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 260 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_EventScript_NotEnough_Haircut2::
# 261 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
# 262 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 263 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	hidemoneybox
# 264 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 265 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 266 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 267 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 268 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
# 269 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
# 270 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 271 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 272 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
# 273 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setmetatile 12, 10, 0x2DD, FALSE
# 274 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 275 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 276 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_Door::
# 277 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 278 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
# 279 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	checkitem ITEM_BASEMENT_KEY
# 280 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
# 281 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
# 282 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 283 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 284 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 285 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 286 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
# 287 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
# 288 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 289 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 290 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	setmetatile 12, 10, 0x2DD, FALSE
# 291 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	playse SE_BANG
# 292 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	special DrawWholeMapView
# 293 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitse
# 294 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 295 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 296 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 297 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
# 298 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
# 299 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	closemessage
# 300 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
# 301 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	end
# 302 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 303 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 304 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherOffer:
# 305 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Welcome to the POKéMON Salon!\p"
# 306 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm the younger and less expensive\n"
# 307 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "of the two Haircut Brothers.\p"
# 308 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'll spiff up your POKéMON for just\n"
# 309 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "¥300.\p"
# 310 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "So? How about it?$"
# 311 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 312 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherAskWhich:
# 313 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok, which POKéMON should I do?$"
# 314 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 315 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherLookCool:
# 316 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok! I'll make it look cool!$"
# 317 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 318 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherAllDone:
# 319 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "There we go! All done!$"
# 320 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 321 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherDisappointed:
# 322 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "No? How disappointing!$"
# 323 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 324 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
# 325 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "You're a little short on funds.$"
# 326 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 327 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
# 328 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I can do only one haircut a day.\p"
# 329 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Sorry, but I'm all done for today.$"
# 330 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 331 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 332 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 333 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherOffer:
# 334 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Welcome!\p"
# 335 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I run the POKéMON Salon!\p"
# 336 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm the older and better of the two\n"
# 337 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Haircut Brothers.\p"
# 338 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I can make your POKéMON beautiful\n"
# 339 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "for just ¥500.\p"
# 340 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Would you like me to do that?$"
# 341 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 342 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherAskWhich:
# 343 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Which POKéMON should I work on?$"
# 344 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 345 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
# 346 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ok! Watch it become beautiful!$"
# 347 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 348 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherAllDone:
# 349 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "There! All done!$"
# 350 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 351 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherThatsAShame:
# 352 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Is that right? That's a shame!$"
# 353 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 354 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
# 355 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "You'll need more money than that.$"
# 356 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 357 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_OlderBrotherOnePerDay:
# 358 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I do only one haircut a day.\n"
# 359 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'm done for today.$"
# 360 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 361 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricSeen:
# 362 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I got booted out of the Game Corner.\p"
# 363 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I was trying to cheat using my\n"
# 364 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "POKéMON…$"
# 365 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 366 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricBeaten:
# 367 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "…Grumble…$"
# 368 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 369 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdEricAfterBattle:
# 370 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I guess I have to do things fair and\n"
# 371 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "square…$"
# 372 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 373 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruSeen:
# 374 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Do you consider type alignments in\n"
# 375 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "battle?\p"
# 376 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "If you know your type advantages,\n"
# 377 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "you'll do better in battle.$"
# 378 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 379 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruBeaten:
# 380 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Ow, ow, ow!$"
# 381 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 382 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
# 383 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I know my POKéMON type alignments.\p"
# 384 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "But I only use one type of POKéMON.$"
# 385 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 386 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacSeen:
# 387 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "My POKéMON just got a haircut!\p"
# 388 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I'll show you how strong it is!$"
# 389 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 390 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacBeaten:
# 391 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Aiyeeee!$"
# 392 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 393 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
# 394 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Your POKéMON will like you more if\n"
# 395 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "you give them haircuts.$"
# 396 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 397 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldSeen:
# 398 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "I think you have some rare POKéMON\n"
# 399 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "with you.\p"
# 400 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Let me see them!$"
# 401 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 402 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
# 403 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Gaah! I lost! That makes me mad!$"
# 404 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 405 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
# 406 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "When I was walking near the Bike\n"
# 407 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Shop last night, I felt like I was\l"
# 408 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "being watched from the rooftops...$"
# 409 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 410 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
# 411 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "Are you making a POKéDEX? Here's a\n"
# 412 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "hot tip.\p"
# 413 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The Hiker on Route 33, Anthony, is a\n"
# 414 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "good guy.\p"
# 415 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "He'll phone you if he sees any rare\n"
# 416 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "POKéMON.$"
# 417 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 418 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_DoorsLocked:
# 419 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The door's locked…$"
# 420 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 421 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_DoorIsOpen:
# 422 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The door is open.$"
# 423 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 424 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_KeyOpenedDoor:
# 425 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "The Basement Key opened the door.$"
# 426 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"

# 427 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
GoldenrodUnderground_Text_NoEntry:
# 428 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
    .string "No Entry Beyond This Point$"

goldenrod_utility_shop_girl::
# 433 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 434 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox goldenrod_utility_shop_girl_Text_0
# 435 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmessage
# 436 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	pokemart goldenrod_utility_shop
# 437 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox goldenrod_utility_shop_girl_Text_1
# 438 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	return


	.align 2
# 441 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
goldenrod_utility_shop:
# 442 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
# 443 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_COVERT_CLOAK
# 444 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_ABILITY_SHIELD
# 445 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.2byte ITEM_CLEAR_AMULET
	.2byte ITEM_NONE

suspiciousdoor_goldenrod_underground::
# 449 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 450 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox suspiciousdoor_goldenrod_underground_Text_0
# 451 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	waitmessage
# 452 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	end


rocket_bouncer::
# 457 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	lock
# 458 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	faceplayer
# 459 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	goto_if_set FLAG_GOLDEN_COLOSSEUM, rocket_bouncer_2
# 462 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox rocket_bouncer_Text_1
rocket_bouncer_1:
# 464 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	release
	end

rocket_bouncer_2:
# 460 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	msgbox rocket_bouncer_Text_0
	goto rocket_bouncer_1


goldenrod_utility_shop_girl_Text_0:
# 434 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Hi, take a look at my exclusive wares!$"

goldenrod_utility_shop_girl_Text_1:
# 437 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Come on, buy some more!$"

suspiciousdoor_goldenrod_underground_Text_0:
# 450 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Door seems to be locked, but you can\n"
	.string "faintly discern noise coming from\l"
	.string "somewhere far behind the door.$"

rocket_bouncer_Text_0:
# 460 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "TODO$"

rocket_bouncer_Text_1:
# 462 "data/maps/GoldenrodCity_UndergroundTunnel/scripts.pory"
	.string "Sorry kid, only those with special\n"
	.string "permission are allowed past here.$"
