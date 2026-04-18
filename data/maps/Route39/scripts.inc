# 1 "data/maps/Route39/scripts.pory"

# 2 "data/maps/Route39/scripts.pory"
.set LOCALID_R39_SHADOW, 17
# 3 "data/maps/Route39/scripts.pory"
.set LOCALID_R39_BAOBA, 2
# 4 "data/maps/Route39/scripts.pory"

# 5 "data/maps/Route39/scripts.pory"
Route39_MapScripts::
# 6 "data/maps/Route39/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
# 7 "data/maps/Route39/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 8 "data/maps/Route39/scripts.pory"
	.byte 0
# 9 "data/maps/Route39/scripts.pory"

# 10 "data/maps/Route39/scripts.pory"
Route39_OnTransition: 
# 11 "data/maps/Route39/scripts.pory"
	callnative SetTimeBasedEncounters
# 12 "data/maps/Route39/scripts.pory"
	end
# 13 "data/maps/Route39/scripts.pory"

# 14 "data/maps/Route39/scripts.pory"
Route39_EventScript_LegendaryTrigger::
# 15 "data/maps/Route39/scripts.pory"
	lock
# 16 "data/maps/Route39/scripts.pory"
	clearflag FLAG_HIDE_ROUTE39_SHADOW
# 17 "data/maps/Route39/scripts.pory"
	addobject LOCALID_R39_SHADOW
# 18 "data/maps/Route39/scripts.pory"
	playse SE_M_RAZOR_WIND
# 19 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
# 20 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 21 "data/maps/Route39/scripts.pory"
	setflag FLAG_HIDE_ROUTE39_SHADOW
# 22 "data/maps/Route39/scripts.pory"
	removeobject LOCALID_R39_SHADOW
# 23 "data/maps/Route39/scripts.pory"
	playse SE_PIN
# 24 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
# 25 "data/maps/Route39/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
# 26 "data/maps/Route39/scripts.pory"
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
# 27 "data/maps/Route39/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
# 28 "data/maps/Route39/scripts.pory"
	delay 60
# 29 "data/maps/Route39/scripts.pory"

# 30 "data/maps/Route39/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 31 "data/maps/Route39/scripts.pory"

# 32 "data/maps/Route39/scripts.pory"
	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
# 33 "data/maps/Route39/scripts.pory"
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
# 34 "data/maps/Route39/scripts.pory"
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
# 35 "data/maps/Route39/scripts.pory"
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4
# 36 "data/maps/Route39/scripts.pory"

# 37 "data/maps/Route39/scripts.pory"
	turnobject LOCALID_R39_BAOBA DIR_EAST
# 38 "data/maps/Route39/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
# 39 "data/maps/Route39/scripts.pory"
Route39_EventScript_ChooseLegend::
# 40 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
# 41 "data/maps/Route39/scripts.pory"
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
# 42 "data/maps/Route39/scripts.pory"
	switch VAR_RESULT
# 43 "data/maps/Route39/scripts.pory"
	case 0, Route39_EventScript_LegendaryTriggerGold
# 44 "data/maps/Route39/scripts.pory"
	case 1, Route39_EventScript_LegendaryTriggerSilver
# 45 "data/maps/Route39/scripts.pory"
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
# 46 "data/maps/Route39/scripts.pory"
	release
# 47 "data/maps/Route39/scripts.pory"
	end
# 48 "data/maps/Route39/scripts.pory"

# 49 "data/maps/Route39/scripts.pory"
Route39_EventScript_BaobaMovement1::
# 50 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
# 51 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 52 "data/maps/Route39/scripts.pory"
	return
# 53 "data/maps/Route39/scripts.pory"
Route39_EventScript_BaobaMovement2::
# 54 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
# 55 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route39/scripts.pory"
	return
# 57 "data/maps/Route39/scripts.pory"
Route39_EventScript_BaobaMovement3::
# 58 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
# 59 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 60 "data/maps/Route39/scripts.pory"
	return
# 61 "data/maps/Route39/scripts.pory"
Route39_EventScript_BaobaMovement4::
# 62 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
# 63 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route39/scripts.pory"
	return
# 65 "data/maps/Route39/scripts.pory"

# 66 "data/maps/Route39/scripts.pory"
Route39_Movement_Baoba1:
# 67 "data/maps/Route39/scripts.pory"
	walk_up
# 68 "data/maps/Route39/scripts.pory"
	walk_up
# 69 "data/maps/Route39/scripts.pory"
	walk_up
# 70 "data/maps/Route39/scripts.pory"
	walk_up
# 71 "data/maps/Route39/scripts.pory"
	walk_up
# 72 "data/maps/Route39/scripts.pory"
	walk_up
# 73 "data/maps/Route39/scripts.pory"
	walk_up
# 74 "data/maps/Route39/scripts.pory"
	walk_right
# 75 "data/maps/Route39/scripts.pory"
	walk_right
# 76 "data/maps/Route39/scripts.pory"
	walk_right
# 77 "data/maps/Route39/scripts.pory"
	step_end
# 78 "data/maps/Route39/scripts.pory"
Route39_Movement_Baoba2:
# 79 "data/maps/Route39/scripts.pory"
	walk_up
# 80 "data/maps/Route39/scripts.pory"
	walk_up
# 81 "data/maps/Route39/scripts.pory"
	walk_up
# 82 "data/maps/Route39/scripts.pory"
	walk_up
# 83 "data/maps/Route39/scripts.pory"
	walk_up
# 84 "data/maps/Route39/scripts.pory"
	walk_up
# 85 "data/maps/Route39/scripts.pory"
	walk_right
# 86 "data/maps/Route39/scripts.pory"
	walk_right
# 87 "data/maps/Route39/scripts.pory"
	walk_right
# 88 "data/maps/Route39/scripts.pory"
	step_end
# 89 "data/maps/Route39/scripts.pory"
Route39_Movement_Baoba3:
# 90 "data/maps/Route39/scripts.pory"
	walk_up
# 91 "data/maps/Route39/scripts.pory"
	walk_up
# 92 "data/maps/Route39/scripts.pory"
	walk_up
# 93 "data/maps/Route39/scripts.pory"
	walk_up
# 94 "data/maps/Route39/scripts.pory"
	walk_up
# 95 "data/maps/Route39/scripts.pory"
	walk_right
# 96 "data/maps/Route39/scripts.pory"
	walk_right
# 97 "data/maps/Route39/scripts.pory"
	walk_right
# 98 "data/maps/Route39/scripts.pory"
	step_end
# 99 "data/maps/Route39/scripts.pory"
Route39_Movement_Baoba4:
# 100 "data/maps/Route39/scripts.pory"
	walk_up
# 101 "data/maps/Route39/scripts.pory"
	walk_up
# 102 "data/maps/Route39/scripts.pory"
	walk_up
# 103 "data/maps/Route39/scripts.pory"
	walk_up
# 104 "data/maps/Route39/scripts.pory"
	walk_right
# 105 "data/maps/Route39/scripts.pory"
	walk_right
# 106 "data/maps/Route39/scripts.pory"
	walk_right
# 107 "data/maps/Route39/scripts.pory"
	step_end
# 108 "data/maps/Route39/scripts.pory"

# 109 "data/maps/Route39/scripts.pory"
Route39_EventScript_LegendaryTriggerGold::
# 110 "data/maps/Route39/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 2
# 111 "data/maps/Route39/scripts.pory"
	goto Route39_EventScript_BaobaIntro
# 112 "data/maps/Route39/scripts.pory"

# 113 "data/maps/Route39/scripts.pory"
Route39_EventScript_LegendaryTriggerSilver::
# 114 "data/maps/Route39/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 1
# 115 "data/maps/Route39/scripts.pory"
	goto Route39_EventScript_BaobaIntro
# 116 "data/maps/Route39/scripts.pory"

# 117 "data/maps/Route39/scripts.pory"
Route39_EventScript_BaobaIntro::
# 118 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
# 119 "data/maps/Route39/scripts.pory"
	playse MUS_HG_POKEGEAR_REGISTERED
# 120 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
# 121 "data/maps/Route39/scripts.pory"
	waitse
# 122 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
# 123 "data/maps/Route39/scripts.pory"
	closemessage
# 124 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
# 125 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 126 "data/maps/Route39/scripts.pory"
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
# 127 "data/maps/Route39/scripts.pory"
	removeobject LOCALID_R39_BAOBA
# 128 "data/maps/Route39/scripts.pory"
	call_if_eq VAR_MAHOGANY_TOWN_STATE, 18, Mahoganytown_EventScript_RocketTrigger
# 129 "data/maps/Route39/scripts.pory"
	release
# 130 "data/maps/Route39/scripts.pory"
	end
# 131 "data/maps/Route39/scripts.pory"

# 132 "data/maps/Route39/scripts.pory"
Route39_Text_ChooseLegend::
# 133 "data/maps/Route39/scripts.pory"
	.string "BAOBA: GOOD HEAVENS! Did that\n"
# 134 "data/maps/Route39/scripts.pory"
	.string "shadow belong to a POKéMON?\p"
# 135 "data/maps/Route39/scripts.pory"
	.string "Did you get a good look at it?\n"
# 136 "data/maps/Route39/scripts.pory"
	.string "I can't tell what color it was...$"
# 137 "data/maps/Route39/scripts.pory"

# 138 "data/maps/Route39/scripts.pory"
Route39_Text_BaobaIntro::
# 139 "data/maps/Route39/scripts.pory"
	.string "How strange...\p"
# 140 "data/maps/Route39/scripts.pory"
	.string "...Ohh!\n"
# 141 "data/maps/Route39/scripts.pory"
	.string "What you are holding is...\l"
# 142 "data/maps/Route39/scripts.pory"
	.string "what they call... a POKéDEX!\p"
# 143 "data/maps/Route39/scripts.pory"
	.string "Haven't seen one of those in ages.\p"
# 144 "data/maps/Route39/scripts.pory"
	.string "My name is BAOBA!\n"
# 145 "data/maps/Route39/scripts.pory"
	.string "I used to run a SAFARI ZONE in\l"
# 146 "data/maps/Route39/scripts.pory"
	.string "FUCHSIA CITY, but it was becoming\l"
# 147 "data/maps/Route39/scripts.pory"
	.string "out of date with new entertainment\l"
# 148 "data/maps/Route39/scripts.pory"
	.string "options coming out.\p"
# 149 "data/maps/Route39/scripts.pory"
	.string "I decided to go overseas to learn\n"
# 150 "data/maps/Route39/scripts.pory"
	.string "the newest technology and open a\l"
# 151 "data/maps/Route39/scripts.pory"
	.string "state-of-the-art SAFARI ZONE\l"
# 152 "data/maps/Route39/scripts.pory"
	.string "in CIANWOOD.\p"
# 153 "data/maps/Route39/scripts.pory"
	.string "It may be more than a coincidence\n"
# 154 "data/maps/Route39/scripts.pory"
	.string "that we are chatting.\p"
# 155 "data/maps/Route39/scripts.pory"
	.string "Why don't we register each other's\n"
# 156 "data/maps/Route39/scripts.pory"
	.string "numbers in the Pokégear?\p"
# 157 "data/maps/Route39/scripts.pory"
	.string "I can give you a call once the\n"
# 158 "data/maps/Route39/scripts.pory"
	.string "SAFARI ZONE is open before I call\l"
# 159 "data/maps/Route39/scripts.pory"
	.string "anyone else!$"
# 160 "data/maps/Route39/scripts.pory"

# 161 "data/maps/Route39/scripts.pory"
Route39_Text_Registered:
# 162 "data/maps/Route39/scripts.pory"
	.string "{PLAYER} registered BAOBA\n"
# 163 "data/maps/Route39/scripts.pory"
	.string "in the POKéGEAR!$"
# 164 "data/maps/Route39/scripts.pory"

# 165 "data/maps/Route39/scripts.pory"

# 166 "data/maps/Route39/scripts.pory"
Route39_Text_WillCall:
# 167 "data/maps/Route39/scripts.pory"
	.string "BAOBA: I'll let you know\n"
# 168 "data/maps/Route39/scripts.pory"
	.string "on the POKéGEAR soon!$"
# 169 "data/maps/Route39/scripts.pory"

# 170 "data/maps/Route39/scripts.pory"
Route39_Movement_BaobaLeave:
# 171 "data/maps/Route39/scripts.pory"
	walk_left
# 172 "data/maps/Route39/scripts.pory"
	walk_left
# 173 "data/maps/Route39/scripts.pory"
	walk_left
# 174 "data/maps/Route39/scripts.pory"
	walk_left
# 175 "data/maps/Route39/scripts.pory"
	walk_left
# 176 "data/maps/Route39/scripts.pory"
	walk_down
# 177 "data/maps/Route39/scripts.pory"
	walk_down
# 178 "data/maps/Route39/scripts.pory"
	walk_down
# 179 "data/maps/Route39/scripts.pory"
	walk_down
# 180 "data/maps/Route39/scripts.pory"
	walk_down
# 181 "data/maps/Route39/scripts.pory"
	walk_down
# 182 "data/maps/Route39/scripts.pory"
	walk_down
# 183 "data/maps/Route39/scripts.pory"
	walk_down
# 184 "data/maps/Route39/scripts.pory"
	step_end
# 185 "data/maps/Route39/scripts.pory"

# 186 "data/maps/Route39/scripts.pory"
Route39_Movement_ShadowSlideDown:
# 187 "data/maps/Route39/scripts.pory"
	slide_down
# 188 "data/maps/Route39/scripts.pory"
	slide_down
# 189 "data/maps/Route39/scripts.pory"
	slide_down
# 190 "data/maps/Route39/scripts.pory"
	slide_down
# 191 "data/maps/Route39/scripts.pory"
	slide_down
# 192 "data/maps/Route39/scripts.pory"
	slide_down
# 193 "data/maps/Route39/scripts.pory"
	slide_down
# 194 "data/maps/Route39/scripts.pory"
	slide_down
# 195 "data/maps/Route39/scripts.pory"
	slide_down
# 196 "data/maps/Route39/scripts.pory"
	slide_down
# 197 "data/maps/Route39/scripts.pory"
	slide_down
# 198 "data/maps/Route39/scripts.pory"
	slide_down
# 199 "data/maps/Route39/scripts.pory"
	slide_down
# 200 "data/maps/Route39/scripts.pory"
	slide_down
# 201 "data/maps/Route39/scripts.pory"
	slide_down
# 202 "data/maps/Route39/scripts.pory"
	slide_down
# 203 "data/maps/Route39/scripts.pory"
	slide_down
# 204 "data/maps/Route39/scripts.pory"
	slide_down
# 205 "data/maps/Route39/scripts.pory"
	slide_down
# 206 "data/maps/Route39/scripts.pory"
	slide_down
# 207 "data/maps/Route39/scripts.pory"
	step_end
# 208 "data/maps/Route39/scripts.pory"

# 209 "data/maps/Route39/scripts.pory"
Route39_EventScript_Woman::
# 210 "data/maps/Route39/scripts.pory"
	lock
# 211 "data/maps/Route39/scripts.pory"
	faceplayer
# 212 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
# 213 "data/maps/Route39/scripts.pory"
	closemessage
# 214 "data/maps/Route39/scripts.pory"
	release
# 215 "data/maps/Route39/scripts.pory"
	end
# 216 "data/maps/Route39/scripts.pory"

# 217 "data/maps/Route39/scripts.pory"
Route39_Text_Woman:
# 218 "data/maps/Route39/scripts.pory"
	.string "That shadow... Maybe it was a giant\n"
# 219 "data/maps/Route39/scripts.pory"
	.string "PIDGEY?$"
# 220 "data/maps/Route39/scripts.pory"

# 221 "data/maps/Route39/scripts.pory"
Route39_EventScript_Miltank::
# 222 "data/maps/Route39/scripts.pory"
	lock
# 223 "data/maps/Route39/scripts.pory"
	faceplayer
# 224 "data/maps/Route39/scripts.pory"
	waitse
# 225 "data/maps/Route39/scripts.pory"
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
# 226 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
# 227 "data/maps/Route39/scripts.pory"
	waitmoncry
# 228 "data/maps/Route39/scripts.pory"
	release
# 229 "data/maps/Route39/scripts.pory"
	end
# 230 "data/maps/Route39/scripts.pory"

# 231 "data/maps/Route39/scripts.pory"
Route39_Text_Miltank:
# 232 "data/maps/Route39/scripts.pory"
	.string "MILTANK: Mooo!$"
# 233 "data/maps/Route39/scripts.pory"

# 234 "data/maps/Route39/scripts.pory"
Route39_EventScript_Eugene::
# 235 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_EUGENE, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
# 236 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
# 237 "data/maps/Route39/scripts.pory"
	end
# 238 "data/maps/Route39/scripts.pory"

# 239 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneSeen:
# 240 "data/maps/Route39/scripts.pory"
	.string "I just got back to OLIVINE.\p"
# 241 "data/maps/Route39/scripts.pory"
	.string "So how about a POKéMON battle?$"
# 242 "data/maps/Route39/scripts.pory"

# 243 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneBeaten:
# 244 "data/maps/Route39/scripts.pory"
	.string "Awaaargh!$"
# 245 "data/maps/Route39/scripts.pory"

# 246 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneAfter:
# 247 "data/maps/Route39/scripts.pory"
	.string "My POKéMON were caught and\n"
# 248 "data/maps/Route39/scripts.pory"
	.string "raised overseas.\p"
# 249 "data/maps/Route39/scripts.pory"
	.string "They're my companions on\n"
# 250 "data/maps/Route39/scripts.pory"
	.string "those long voyages.$"
# 251 "data/maps/Route39/scripts.pory"

# 252 "data/maps/Route39/scripts.pory"
Route39_EventScript_Derek::
# 253 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
# 254 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
# 255 "data/maps/Route39/scripts.pory"
	end
# 256 "data/maps/Route39/scripts.pory"

# 257 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekSeen:
# 258 "data/maps/Route39/scripts.pory"
	.string "This is a good time to brag\n"
# 259 "data/maps/Route39/scripts.pory"
	.string "about my PIKACHU!$"
# 260 "data/maps/Route39/scripts.pory"

# 261 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekBeaten:
# 262 "data/maps/Route39/scripts.pory"
	.string "I had no time to show off\n"
# 263 "data/maps/Route39/scripts.pory"
	.string "PIKACHU…$"
# 264 "data/maps/Route39/scripts.pory"

# 265 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekAfter:
# 266 "data/maps/Route39/scripts.pory"
	.string "I'm not listening to your\n"
# 267 "data/maps/Route39/scripts.pory"
	.string "bragging!\p"
# 268 "data/maps/Route39/scripts.pory"
	.string "We POKé FANS have a policy\n"
# 269 "data/maps/Route39/scripts.pory"
	.string "of not listening to bragging!$"
# 270 "data/maps/Route39/scripts.pory"

# 271 "data/maps/Route39/scripts.pory"
Route39_EventScript_Ruth::
# 272 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
# 273 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
# 274 "data/maps/Route39/scripts.pory"
	end
# 275 "data/maps/Route39/scripts.pory"

# 276 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthSeen:
# 277 "data/maps/Route39/scripts.pory"
	.string "Such darling POKéMON.\p"
# 278 "data/maps/Route39/scripts.pory"
	.string "Let's show our POKéMON\n"
# 279 "data/maps/Route39/scripts.pory"
	.string "together at the same time.$"
# 280 "data/maps/Route39/scripts.pory"

# 281 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthBeaten:
# 282 "data/maps/Route39/scripts.pory"
	.string "I don't mind losing.$"
# 283 "data/maps/Route39/scripts.pory"

# 284 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthAfter:
# 285 "data/maps/Route39/scripts.pory"
	.string "Do you know about baby\n"
# 286 "data/maps/Route39/scripts.pory"
	.string "POKéMON?\p"
# 287 "data/maps/Route39/scripts.pory"
	.string "I bet they're just adorable!$"
# 288 "data/maps/Route39/scripts.pory"

# 289 "data/maps/Route39/scripts.pory"
Route39_EventScript_Norman::
# 290 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
# 291 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route39/scripts.pory"
	end
# 293 "data/maps/Route39/scripts.pory"

# 294 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanSeen:
# 295 "data/maps/Route39/scripts.pory"
	.string "Let me see what your\n"
# 296 "data/maps/Route39/scripts.pory"
	.string "POKéMON are capable of.$"
# 297 "data/maps/Route39/scripts.pory"

# 298 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanBeaten:
# 299 "data/maps/Route39/scripts.pory"
	.string "Ooh, your POKéMON have\n"
# 300 "data/maps/Route39/scripts.pory"
	.string "potential.$"
# 301 "data/maps/Route39/scripts.pory"

# 302 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanAfter:
# 303 "data/maps/Route39/scripts.pory"
	.string "You know how POKéMON have\n"
# 304 "data/maps/Route39/scripts.pory"
	.string "different abilities?\p"
# 305 "data/maps/Route39/scripts.pory"
	.string "People are like that too.\n"
# 306 "data/maps/Route39/scripts.pory"
	.string "Everyone has different\l"
# 307 "data/maps/Route39/scripts.pory"
	.string "potential.$"
# 308 "data/maps/Route39/scripts.pory"

# 309 "data/maps/Route39/scripts.pory"
Route39_EventScript_Jamie::
# 310 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
# 311 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
# 312 "data/maps/Route39/scripts.pory"
	end
# 313 "data/maps/Route39/scripts.pory"

# 314 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeSeen:
# 315 "data/maps/Route39/scripts.pory"
	.string "You came at just the right\n"
# 316 "data/maps/Route39/scripts.pory"
	.string "time.\p"
# 317 "data/maps/Route39/scripts.pory"
	.string "Let's battle.$"
# 318 "data/maps/Route39/scripts.pory"

# 319 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeBeaten:
# 320 "data/maps/Route39/scripts.pory"
	.string "Oh, how disappointing…$"
# 321 "data/maps/Route39/scripts.pory"

# 322 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeAfter:
# 323 "data/maps/Route39/scripts.pory"
	.string "I met UMBREON at night right\n"
# 324 "data/maps/Route39/scripts.pory"
	.string "here on ROUTE 39.\p"
# 325 "data/maps/Route39/scripts.pory"
	.string "I'm not sure why, but it\n"
# 326 "data/maps/Route39/scripts.pory"
	.string "seems to like it when I\l"
# 327 "data/maps/Route39/scripts.pory"
	.string "train here.\p"
# 328 "data/maps/Route39/scripts.pory"
	.string "It seems to become friendlier\n"
# 329 "data/maps/Route39/scripts.pory"
	.string "by training here than\l"
# 330 "data/maps/Route39/scripts.pory"
	.string "anywhere else.$"
# 331 "data/maps/Route39/scripts.pory"

# 332 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign1::
# 333 "data/maps/Route39/scripts.pory"
	lock
# 334 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Sign, MSGBOX_SIGN
# 335 "data/maps/Route39/scripts.pory"
	closemessage
# 336 "data/maps/Route39/scripts.pory"
	release
# 337 "data/maps/Route39/scripts.pory"
	end
# 338 "data/maps/Route39/scripts.pory"

# 339 "data/maps/Route39/scripts.pory"
Route39_Text_Sign:
# 340 "data/maps/Route39/scripts.pory"
	.string "ROUTE 39\p"
# 341 "data/maps/Route39/scripts.pory"
	.string "OLIVINE CITY - ECRUTEAK CITY$"
# 342 "data/maps/Route39/scripts.pory"

# 343 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign2::
# 344 "data/maps/Route39/scripts.pory"
	lock
# 345 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
# 346 "data/maps/Route39/scripts.pory"
	closemessage
# 347 "data/maps/Route39/scripts.pory"
	release
# 348 "data/maps/Route39/scripts.pory"
	end
# 349 "data/maps/Route39/scripts.pory"

# 350 "data/maps/Route39/scripts.pory"
Route39_Text_MoomooFarmSign:
# 351 "data/maps/Route39/scripts.pory"
	.string "MOOMOO FARM\p"
# 352 "data/maps/Route39/scripts.pory"
	.string "Enjoy Our Fresh and Tasty Milk$"
# 353 "data/maps/Route39/scripts.pory"

# 354 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign3::
# 355 "data/maps/Route39/scripts.pory"
	lock
# 356 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
# 357 "data/maps/Route39/scripts.pory"
	closemessage
# 358 "data/maps/Route39/scripts.pory"
	release
# 359 "data/maps/Route39/scripts.pory"
	end
# 360 "data/maps/Route39/scripts.pory"

# 361 "data/maps/Route39/scripts.pory"
Route39_Text_TrainerTips:
# 362 "data/maps/Route39/scripts.pory"
	.string "TRAINER TIPS\p"
# 363 "data/maps/Route39/scripts.pory"
	.string "Use HEADBUTT on trees to shake\n"
# 364 "data/maps/Route39/scripts.pory"
	.string "POKéMON out.\p"
# 365 "data/maps/Route39/scripts.pory"
	.string "Different kinds of POKéMON\n"
# 366 "data/maps/Route39/scripts.pory"
	.string "drop out of trees.\p"
# 367 "data/maps/Route39/scripts.pory"
	.string "Use HEADBUTT on any tree\n"
# 368 "data/maps/Route39/scripts.pory"
	.string "you see!$"

Route39_NorthSign::
# 372 "data/maps/Route39/scripts.pory"
	msgbox Route39_NorthSign_Text_0, MSGBOX_SIGN
	return


Route39_NorthSign_Text_0:
# 372 "data/maps/Route39/scripts.pory"
	.string "{UP_ARROW} Snowtop Mountain trail$"
