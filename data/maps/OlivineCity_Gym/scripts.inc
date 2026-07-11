# 1 "data/maps/OlivineCity_Gym/scripts.pory"

# 2 "data/maps/OlivineCity_Gym/scripts.pory"
.set LOCALID_OLIVINE_CITY_GYM_NPC1, 3
# 3 "data/maps/OlivineCity_Gym/scripts.pory"
.set LOCALID_OLIVINE_CITY_GYM_NPC2, 2
# 4 "data/maps/OlivineCity_Gym/scripts.pory"

# 5 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_MapScripts::
# 6 "data/maps/OlivineCity_Gym/scripts.pory"
	.byte 0
# 7 "data/maps/OlivineCity_Gym/scripts.pory"

# 8 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Gent::
# 9 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 10 "data/maps/OlivineCity_Gym/scripts.pory"
	faceplayer
# 11 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
# 12 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
# 13 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 14 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 15 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 16 "data/maps/OlivineCity_Gym/scripts.pory"

# 17 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Gent2::
# 18 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
# 19 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 20 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 21 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 22 "data/maps/OlivineCity_Gym/scripts.pory"

# 23 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_TriggerRow1::
# 24 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 25 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
# 26 "data/maps/OlivineCity_Gym/scripts.pory"
	playse SE_PIN
# 27 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
# 28 "data/maps/OlivineCity_Gym/scripts.pory"
	delay 60
# 29 "data/maps/OlivineCity_Gym/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 30 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
# 31 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
# 32 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
# 33 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
# 34 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
# 35 "data/maps/OlivineCity_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 36 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
# 37 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 38 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 6
# 39 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 40 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 41 "data/maps/OlivineCity_Gym/scripts.pory"

# 42 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveLeft0::
# 43 "data/maps/OlivineCity_Gym/scripts.pory"
	turnobject VAR_TEMP_0, DIR_WEST
# 44 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 45 "data/maps/OlivineCity_Gym/scripts.pory"

# 46 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveLeft1::
# 47 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 48 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 49 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 50 "data/maps/OlivineCity_Gym/scripts.pory"

# 51 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveLeft2::
# 52 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 53 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 54 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 55 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 56 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 57 "data/maps/OlivineCity_Gym/scripts.pory"

# 58 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveLeft3::
# 59 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 60 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 61 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 62 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 63 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 64 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 65 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 66 "data/maps/OlivineCity_Gym/scripts.pory"

# 67 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveLeft4::
# 68 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 69 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 70 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 71 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 72 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 73 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 74 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
# 75 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 76 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 77 "data/maps/OlivineCity_Gym/scripts.pory"

# 78 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_Gent:
# 79 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I knew you'd come here.\p"
# 80 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Thank you for helping the Gym Leader,\n"
# 81 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "but battle is a separate matter.\p"
# 82 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Go for it!$"
# 83 "data/maps/OlivineCity_Gym/scripts.pory"

# 84 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_Gent2:
# 85 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Impressive!\n"
# 86 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "You should continue your journey to\n"
# 87 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "different places.\p"
# 88 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Since you can use Surf, why don't you\n"
# 89 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "try it on the Lake Of Rage?$"
# 90 "data/maps/OlivineCity_Gym/scripts.pory"

# 91 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Lass::
# 92 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 93 "data/maps/OlivineCity_Gym/scripts.pory"
	faceplayer
# 94 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
# 95 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
# 96 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 97 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 98 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 99 "data/maps/OlivineCity_Gym/scripts.pory"

# 100 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Lass2::
# 101 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
# 102 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 103 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 104 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 105 "data/maps/OlivineCity_Gym/scripts.pory"

# 106 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_TriggerRow2::
# 107 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 108 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
# 109 "data/maps/OlivineCity_Gym/scripts.pory"
	playse SE_PIN
# 110 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
# 111 "data/maps/OlivineCity_Gym/scripts.pory"
	delay 60
# 112 "data/maps/OlivineCity_Gym/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 113 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
# 114 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
# 115 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
# 116 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
# 117 "data/maps/OlivineCity_Gym/scripts.pory"
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
# 118 "data/maps/OlivineCity_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 119 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
# 120 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 121 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 7
# 122 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 123 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 124 "data/maps/OlivineCity_Gym/scripts.pory"

# 125 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveRight0::
# 126 "data/maps/OlivineCity_Gym/scripts.pory"
	turnobject VAR_TEMP_0, DIR_EAST
# 127 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 128 "data/maps/OlivineCity_Gym/scripts.pory"

# 129 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveRight1::
# 130 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 131 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 132 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 133 "data/maps/OlivineCity_Gym/scripts.pory"

# 134 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveRight2::
# 135 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 136 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 137 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 138 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 139 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 140 "data/maps/OlivineCity_Gym/scripts.pory"

# 141 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveRight3::
# 142 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 143 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 144 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 145 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 146 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 147 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 148 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 149 "data/maps/OlivineCity_Gym/scripts.pory"

# 150 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MoveRight4::
# 151 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 152 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 153 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 154 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 155 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 156 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 157 "data/maps/OlivineCity_Gym/scripts.pory"
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
# 158 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmovement 0
# 159 "data/maps/OlivineCity_Gym/scripts.pory"
	return
# 160 "data/maps/OlivineCity_Gym/scripts.pory"

# 161 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_Lass:
# 162 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Giggle...\n"
# 163 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I know how capable you are\l"
# 164 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "from the Lighthouse.\p"
# 165 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "It's time you showed that side of\n"
# 166 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "yourself to Jasmine! Good luck!$"
# 167 "data/maps/OlivineCity_Gym/scripts.pory"

# 168 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_Lass2:
# 169 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "You are amazing...\n"
# 170 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "You should aim even higher, since\l"
# 171 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "you have such potential.\p"
# 172 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Have you been to Mahogany Town?$"
# 173 "data/maps/OlivineCity_Gym/scripts.pory"

# 174 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_GymGuide::
# 175 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 176 "data/maps/OlivineCity_Gym/scripts.pory"
	faceplayer
# 177 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
# 178 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
# 179 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
# 180 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 181 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 182 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 183 "data/maps/OlivineCity_Gym/scripts.pory"

# 184 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_GymGuideSick::
# 185 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
# 186 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 187 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 188 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 189 "data/maps/OlivineCity_Gym/scripts.pory"

# 190 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_GymGuideAfter::
# 191 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
# 192 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 193 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 194 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 195 "data/maps/OlivineCity_Gym/scripts.pory"

# 196 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_GymGuideText:
# 197 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Jasmine uses the newly discovered\n"
# 198 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Steel-type.\p"
# 199 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "She's known for having not one,\n"
# 200 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "but two aces.\p"
# 201 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "The first is a metal bug that can\n"
# 202 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "use a technique to boost its Attack.\p"
# 203 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "While fire will hurt it, it can\n"
# 204 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "sometimes endure powerful blows.\p"
# 205 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "The second is a giant iron snake\n"
# 206 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "with lots of powerful moves.\p"
# 207 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Approach it with caution.\p"
# 208 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "It may look slow, but I've seen it\n"
# 209 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "strike first with shocking displays\l"
# 210 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "of Speed.$"
# 211 "data/maps/OlivineCity_Gym/scripts.pory"

# 212 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_GymGuideWinText:
# 213 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "That was awesome.\p"
# 214 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "The Steel-type, huh?\p"
# 215 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "That was a close encounter of an\n"
# 216 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "unknown kind!$"
# 217 "data/maps/OlivineCity_Gym/scripts.pory"

# 218 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_GymGuidePreText:
# 219 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Jasmine, the Gym Leader, is at the\n"
# 220 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Lighthouse.\p"
# 221 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "She's been tending to a sick Pokémon.\p"
# 222 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "A strong trainer has to be\n"
# 223 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "compassionate.$"
# 224 "data/maps/OlivineCity_Gym/scripts.pory"

# 225 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Jasmine::
# 226 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 227 "data/maps/OlivineCity_Gym/scripts.pory"
	faceplayer
# 228 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
# 229 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
# 230 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
# 231 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
# 232 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1
# 233 "data/maps/OlivineCity_Gym/scripts.pory"

# 234 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_JasmineVictory::
# 235 "data/maps/OlivineCity_Gym/scripts.pory"
	message OlivineCity_Gym_Text_ReceivedMineralBadge
# 236 "data/maps/OlivineCity_Gym/scripts.pory"
	waitmessage
# 237 "data/maps/OlivineCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 238 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
# 239 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_BADGE06_GET
	special Achievement_CheckAll
# 240 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
# 241 "data/maps/OlivineCity_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 242 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_0x8008, 6
# 243 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_RIVAL_STATE, 9
# 244 "data/maps/OlivineCity_Gym/scripts.pory"
    setflag FLAG_HIDE_OLIVINE_RIVAL
# 245 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_RIVAL
# 246 "data/maps/OlivineCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_ICEPATH_RIVAL
# 247 "data/maps/OlivineCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 248 "data/maps/OlivineCity_Gym/scripts.pory"
	giveitem ITEM_TM_FLASH_CANNON
# 249 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
# 250 "data/maps/OlivineCity_Gym/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 8
# 251 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 252 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 253 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 254 "data/maps/OlivineCity_Gym/scripts.pory"

# 255 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_CianwoodCheckMahog::
# 256 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
# 257 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
# 258 "data/maps/OlivineCity_Gym/scripts.pory"

# 259 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_MahogCheckCianwood::
# 260 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
# 261 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
# 262 "data/maps/OlivineCity_Gym/scripts.pory"
	
# 263 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Jasmine_Battle1::
# 264 "data/maps/OlivineCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_JASMINE_1, OlivineCity_Gym_Text_JasmineBetterTrainer
# 265 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_BADGE_5
# 266 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_JasmineVictory
# 267 "data/maps/OlivineCity_Gym/scripts.pory"

# 268 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Jasmine_Battle2::
# 269 "data/maps/OlivineCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_JASMINE_1_2, OlivineCity_Gym_Text_JasmineBetterTrainer
# 270 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_BADGE_6
# 271 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_JasmineVictory
# 272 "data/maps/OlivineCity_Gym/scripts.pory"

# 273 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Jasmine_Battle3::
# 274 "data/maps/OlivineCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_JASMINE_1_3, OlivineCity_Gym_Text_JasmineBetterTrainer
# 275 "data/maps/OlivineCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_BADGE_7
# 276 "data/maps/OlivineCity_Gym/scripts.pory"
	goto OlivineCity_Gym_EventScript_JasmineVictory
# 277 "data/maps/OlivineCity_Gym/scripts.pory"

# 278 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Jasmine_Defeated::
# 279 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
# 280 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 281 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 282 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 283 "data/maps/OlivineCity_Gym/scripts.pory"

# 284 "data/maps/OlivineCity_Gym/scripts.pory"

# 285 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineSteelTypeIntro:
# 286 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…Thank you for your help at the\n"
# 287 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Lighthouse…\p"
# 288 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "But this is different.\n"
# 289 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Please allow me to introduce myself.\p"
# 290 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I am Jasmine, a Gym Leader.\n"
# 291 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I use the Steel-type.\p"
# 292 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…Do you know about the Steel-type?\p"
# 293 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "It's a type that was only recently\n"
# 294 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "discovered.\p"
# 295 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…Um… May I begin?$"
# 296 "data/maps/OlivineCity_Gym/scripts.pory"

# 297 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineBetterTrainer:
# 298 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…You are a better trainer than me,\n"
# 299 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "in both skill and kindness.\p"
# 300 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "In accordance with League rules,\n"
# 301 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I confer upon you this Badge.$"
# 302 "data/maps/OlivineCity_Gym/scripts.pory"

# 303 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_ReceivedMineralBadge:
# 304 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "{PLAYER} received Mineralbadge.$"
# 305 "data/maps/OlivineCity_Gym/scripts.pory"

# 306 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineBadgeSpeech:
# 307 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…Um… Please take this too…$"
# 308 "data/maps/OlivineCity_Gym/scripts.pory"

# 309 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineIronTailSpeech:
# 310 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…You could use that TM to teach\n"
# 311 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Flash Cannon.$"
# 312 "data/maps/OlivineCity_Gym/scripts.pory"

# 313 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineGoodLuck:
# 314 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Um… I don't know how to say this,\n"
# 315 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "but good luck…$"
# 316 "data/maps/OlivineCity_Gym/scripts.pory"

# 317 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineRematchText:
# 318 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…Congratulations, Johto Champion.\p"
# 319 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "You have become so strong…\p"
# 320 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "I wonder if I have improved.\p"
# 321 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Would you like to test that?\p"
# 322 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Want to have a rematch with me?$"
# 323 "data/maps/OlivineCity_Gym/scripts.pory"

# 324 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_JasmineRematchDefeatText:
# 325 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "…You are a better trainer than me,\n"
# 326 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "in both skill and kindness.$"
# 327 "data/maps/OlivineCity_Gym/scripts.pory"

# 328 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Statue::
# 329 "data/maps/OlivineCity_Gym/scripts.pory"
	lock
# 330 "data/maps/OlivineCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
# 331 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 332 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 333 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 334 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 335 "data/maps/OlivineCity_Gym/scripts.pory"

# 336 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_EventScript_Statue2::
# 337 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 338 "data/maps/OlivineCity_Gym/scripts.pory"
	closemessage
# 339 "data/maps/OlivineCity_Gym/scripts.pory"
	release
# 340 "data/maps/OlivineCity_Gym/scripts.pory"
	end
# 341 "data/maps/OlivineCity_Gym/scripts.pory"

# 342 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_GymStatue:
# 343 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Olivine City Pokémon Gym$"
# 344 "data/maps/OlivineCity_Gym/scripts.pory"

# 345 "data/maps/OlivineCity_Gym/scripts.pory"
OlivineCity_Gym_Text_GymStatueCertified:
# 346 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Olivine City Pokémon Gym\p"
# 347 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Jasmine's Certified Trainers:\n"
# 348 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "{PLAYER}$"

OlivineCity_Gym_EventScript_Steelix::
# 352 "data/maps/OlivineCity_Gym/scripts.pory"
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
# 353 "data/maps/OlivineCity_Gym/scripts.pory"
	msgbox OlivineCity_Gym_EventScript_Steelix_Text_0, MSGBOX_NPC
	return


OlivineCity_Gym_EventScript_Steelix_Text_0:
# 353 "data/maps/OlivineCity_Gym/scripts.pory"
	.string "Steel!!$"
