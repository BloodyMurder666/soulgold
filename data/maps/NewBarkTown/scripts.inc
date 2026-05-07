# 1 "data/maps/NewBarkTown/scripts.pory"

# 2 "data/maps/NewBarkTown/scripts.pory"
.set LOCALID_LASS, 2
# 3 "data/maps/NewBarkTown/scripts.pory"
.set LOCALID_SILVER, 3
# 4 "data/maps/NewBarkTown/scripts.pory"

# 5 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_MapScripts::
# 6 "data/maps/NewBarkTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
# 7 "data/maps/NewBarkTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_OnFrame
# 8 "data/maps/NewBarkTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 9 "data/maps/NewBarkTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewBarkTown_OnLoad
# 10 "data/maps/NewBarkTown/scripts.pory"
	.byte 0
# 11 "data/maps/NewBarkTown/scripts.pory"

# 12 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_OnLoad::
# 13 "data/maps/NewBarkTown/scripts.pory"
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
# 14 "data/maps/NewBarkTown/scripts.pory"
	end
# 15 "data/maps/NewBarkTown/scripts.pory"

# 16 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_OnFrame::
# 17 "data/maps/NewBarkTown/scripts.pory"
	map_script_2 VAR_NEWBARK_TOWN_STATE, 6, NewBarkTown_EventScript_ElmCallAfterLeague
# 18 "data/maps/NewBarkTown/scripts.pory"
    map_script_2 VAR_RIVAL_STATE, 0, NewBarkTown_EventScript_RivalIntro
# 19 "data/maps/NewBarkTown/scripts.pory"
	.2byte 0
# 20 "data/maps/NewBarkTown/scripts.pory"

# 21 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmCallAfterLeague::
# 22 "data/maps/NewBarkTown/scripts.pory"
	lock
# 23 "data/maps/NewBarkTown/scripts.pory"
	pokenavcall BlackthornCity_Text_ElmCall
# 24 "data/maps/NewBarkTown/scripts.pory"
	waitmessage
# 25 "data/maps/NewBarkTown/scripts.pory"
	delay 30
# 26 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 7
# 27 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 10
# 28 "data/maps/NewBarkTown/scripts.pory"
	release
# 29 "data/maps/NewBarkTown/scripts.pory"
	end
# 30 "data/maps/NewBarkTown/scripts.pory"

# 31 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_OnTransition::
# 32 "data/maps/NewBarkTown/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 33 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_Set_TalkToElm
# 34 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_Set_TalkToMom
# 35 "data/maps/NewBarkTown/scripts.pory"
	end
# 36 "data/maps/NewBarkTown/scripts.pory"

# 37 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToElm::
# 38 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 39 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 40 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 41 "data/maps/NewBarkTown/scripts.pory"
	end
# 42 "data/maps/NewBarkTown/scripts.pory"

# 43 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToMom::
# 44 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 45 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 46 "data/maps/NewBarkTown/scripts.pory"
	end
# 47 "data/maps/NewBarkTown/scripts.pory"

# 48 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LabSign::
# 49 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LabSign, MSGBOX_SIGN
# 50 "data/maps/NewBarkTown/scripts.pory"
	end
# 51 "data/maps/NewBarkTown/scripts.pory"

# 52 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TownSign::
# 53 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
# 54 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 55 "data/maps/NewBarkTown/scripts.pory"
	end
# 56 "data/maps/NewBarkTown/scripts.pory"

# 57 "data/maps/NewBarkTown/scripts.pory"

# 58 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Lass::
# 59 "data/maps/NewBarkTown/scripts.pory"
	lock
# 60 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 61 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LassState2
# 62 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_EventScript_LassState3
# 63 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LassState4
# 64 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState5, MSGBOX_DEFAULT
# 65 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 66 "data/maps/NewBarkTown/scripts.pory"
	release
# 67 "data/maps/NewBarkTown/scripts.pory"
	end
# 68 "data/maps/NewBarkTown/scripts.pory"
	
# 69 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState2::
# 70 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 71 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 72 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 74 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 75 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 76 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 77 "data/maps/NewBarkTown/scripts.pory"
	release
# 78 "data/maps/NewBarkTown/scripts.pory"
	end
# 79 "data/maps/NewBarkTown/scripts.pory"

# 80 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState3::
# 81 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState3, MSGBOX_DEFAULT
# 82 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 83 "data/maps/NewBarkTown/scripts.pory"
	release
# 84 "data/maps/NewBarkTown/scripts.pory"
	end
# 85 "data/maps/NewBarkTown/scripts.pory"

# 86 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState4::
# 87 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 88 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 89 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 90 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 91 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 92 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 93 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 94 "data/maps/NewBarkTown/scripts.pory"
	release
# 95 "data/maps/NewBarkTown/scripts.pory"
	end
# 96 "data/maps/NewBarkTown/scripts.pory"

# 97 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Wooper::
# 98 "data/maps/NewBarkTown/scripts.pory"
	lock
# 99 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 100 "data/maps/NewBarkTown/scripts.pory"
	waitse
# 101 "data/maps/NewBarkTown/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_NORMAL
# 102 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Wooper, MSGBOX_DEFAULT
# 103 "data/maps/NewBarkTown/scripts.pory"
	waitmoncry
# 104 "data/maps/NewBarkTown/scripts.pory"
	release
# 105 "data/maps/NewBarkTown/scripts.pory"
	end
# 106 "data/maps/NewBarkTown/scripts.pory"

# 107 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTrigger::
# 108 "data/maps/NewBarkTown/scripts.pory"
	lock
# 109 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LeaveTriggersState2
# 110 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LeaveTriggersState4
# 111 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 112 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 113 "data/maps/NewBarkTown/scripts.pory"
	release
# 114 "data/maps/NewBarkTown/scripts.pory"
	end
# 115 "data/maps/NewBarkTown/scripts.pory"

# 116 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState2::
# 117 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 118 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 119 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 120 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 121 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 122 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 123 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 124 "data/maps/NewBarkTown/scripts.pory"
	return
# 125 "data/maps/NewBarkTown/scripts.pory"

# 126 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState4::
# 127 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 128 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 129 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 130 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 131 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 133 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 134 "data/maps/NewBarkTown/scripts.pory"
	return 
# 135 "data/maps/NewBarkTown/scripts.pory"

# 136 "data/maps/NewBarkTown/scripts.pory"

# 137 "data/maps/NewBarkTown/scripts.pory"

# 138 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatMan::
# 139 "data/maps/NewBarkTown/scripts.pory"
	lock
# 140 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 141 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_FatManState2
# 142 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState3, MSGBOX_DEFAULT
# 143 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 144 "data/maps/NewBarkTown/scripts.pory"
	release
# 145 "data/maps/NewBarkTown/scripts.pory"
	end
# 146 "data/maps/NewBarkTown/scripts.pory"

# 147 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatManState2::
# 148 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState2, MSGBOX_DEFAULT
# 149 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 150 "data/maps/NewBarkTown/scripts.pory"
	release
# 151 "data/maps/NewBarkTown/scripts.pory"
	end
# 152 "data/maps/NewBarkTown/scripts.pory"

# 153 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Silver::
# 154 "data/maps/NewBarkTown/scripts.pory"
	lock
# 155 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver1, MSGBOX_DEFAULT
# 156 "data/maps/NewBarkTown/scripts.pory"
	delay 60
# 157 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 158 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_ExclamationMark
# 159 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 160 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 161 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver2, MSGBOX_DEFAULT
# 162 "data/maps/NewBarkTown/scripts.pory"
	playse SE_BANG
# 163 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, NewBarkTown_Movement_SilverPushesPlayer
# 164 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerPushedBySilver
# 165 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 166 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_FaceOriginalDirection
# 167 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/NewBarkTown/scripts.pory"
	release
# 170 "data/maps/NewBarkTown/scripts.pory"
	end
# 171 "data/maps/NewBarkTown/scripts.pory"

# 172 "data/maps/NewBarkTown/scripts.pory"

# 173 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Door::
# 174 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Door, MSGBOX_SIGN
# 175 "data/maps/NewBarkTown/scripts.pory"
	end
# 176 "data/maps/NewBarkTown/scripts.pory"

# 177 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan1::
# 178 "data/maps/NewBarkTown/scripts.pory"
	givebp 4
# 179 "data/maps/NewBarkTown/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 180 "data/maps/NewBarkTown/scripts.pory"
	end
# 181 "data/maps/NewBarkTown/scripts.pory"

# 182 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan2::
# 183 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 184 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 185 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 186 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 187 "data/maps/NewBarkTown/scripts.pory"
	end
# 188 "data/maps/NewBarkTown/scripts.pory"

# 189 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan3::
# 190 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 5
# 191 "data/maps/NewBarkTown/scripts.pory"
	
# 192 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_AERODACTYL_PUZZLE
# 193 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_HOOH_PUZZLE
# 194 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_KABUTO_PUZZLE
# 195 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_OMANYTE_PUZZLE
# 196 "data/maps/NewBarkTown/scripts.pory"
	end
# 197 "data/maps/NewBarkTown/scripts.pory"

# 198 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_SilverPushesPlayer:
# 199 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 200 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 201 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 202 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 203 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 204 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 205 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 206 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 207 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 208 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 209 "data/maps/NewBarkTown/scripts.pory"

# 210 "data/maps/NewBarkTown/scripts.pory"

# 211 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_PlayerPushedBySilver:
# 212 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 214 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 215 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 216 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 217 "data/maps/NewBarkTown/scripts.pory"
	jump_2_down
# 218 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 219 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 220 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 221 "data/maps/NewBarkTown/scripts.pory"

# 222 "data/maps/NewBarkTown/scripts.pory"
	
# 223 "data/maps/NewBarkTown/scripts.pory"

# 224 "data/maps/NewBarkTown/scripts.pory"

# 225 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_FaceDown:
# 226 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 227 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 228 "data/maps/NewBarkTown/scripts.pory"

# 229 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LabSign:
# 230 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's Lab$"
# 231 "data/maps/NewBarkTown/scripts.pory"

# 232 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Door:
# 233 "data/maps/NewBarkTown/scripts.pory"
	.string "The door is locked.$"
# 234 "data/maps/NewBarkTown/scripts.pory"

# 235 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Wooper:
# 236 "data/maps/NewBarkTown/scripts.pory"
	.string "Wooper: Woooooop.$"
# 237 "data/maps/NewBarkTown/scripts.pory"

# 238 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState2:
# 239 "data/maps/NewBarkTown/scripts.pory"
	.string "Wow, your POKéGEAR is impressive!\n"
# 240 "data/maps/NewBarkTown/scripts.pory"
	.string "Did your mom get it for you?$"
# 241 "data/maps/NewBarkTown/scripts.pory"

# 242 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState3:
# 243 "data/maps/NewBarkTown/scripts.pory"
	.string "Yo, {PLAYER}!\p"
# 244 "data/maps/NewBarkTown/scripts.pory"
	.string "I hear Prof.Elm discovered\n"
# 245 "data/maps/NewBarkTown/scripts.pory"
	.string "some new Pokémon.$"
# 246 "data/maps/NewBarkTown/scripts.pory"

# 247 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState2:
# 248 "data/maps/NewBarkTown/scripts.pory"
	.string "Wait, {PLAYER}!\p"
# 249 "data/maps/NewBarkTown/scripts.pory"
	.string "It's dangerous to go out\n"
# 250 "data/maps/NewBarkTown/scripts.pory"
	.string "without a Pokémon!\p"
# 251 "data/maps/NewBarkTown/scripts.pory"
	.string "Wild Pokémon jump out of the grass\n"
# 252 "data/maps/NewBarkTown/scripts.pory"
	.string "on the way to the next town.$"
# 253 "data/maps/NewBarkTown/scripts.pory"

# 254 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState3:
# 255 "data/maps/NewBarkTown/scripts.pory"
	.string "Oh! Your Pokémon is adorable!\n"
# 256 "data/maps/NewBarkTown/scripts.pory"
	.string "I wish I had one!$"
# 257 "data/maps/NewBarkTown/scripts.pory"

# 258 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState4:
# 259 "data/maps/NewBarkTown/scripts.pory"
	.string "Hi, {PLAYER}! Leaving again?\p"
# 260 "data/maps/NewBarkTown/scripts.pory"
	.string "You should tell your mom if\n"
# 261 "data/maps/NewBarkTown/scripts.pory"
	.string "you are leaving.$"
# 262 "data/maps/NewBarkTown/scripts.pory"

# 263 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState5:
# 264 "data/maps/NewBarkTown/scripts.pory"
	.string "Call your mom on your POKéGEAR\n"
# 265 "data/maps/NewBarkTown/scripts.pory"
	.string "to let her know how you're doing.$\p"
# 266 "data/maps/NewBarkTown/scripts.pory"

# 267 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver1:
# 268 "data/maps/NewBarkTown/scripts.pory"
	.string ". . .\p"
# 269 "data/maps/NewBarkTown/scripts.pory"
	.string "So this is the famous Elm\n"
# 270 "data/maps/NewBarkTown/scripts.pory"
	.string "Pokémon Lab…$"
# 271 "data/maps/NewBarkTown/scripts.pory"

# 272 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver2:
# 273 "data/maps/NewBarkTown/scripts.pory"
	.string "…What are you staring at?$"
# 274 "data/maps/NewBarkTown/scripts.pory"

# 275 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Sign:
# 276 "data/maps/NewBarkTown/scripts.pory"
	.string "New Bark Town\p"
# 277 "data/maps/NewBarkTown/scripts.pory"
	.string "The Town Where the Winds of\n"
# 278 "data/maps/NewBarkTown/scripts.pory"
	.string "a New Beginning Blow$"
# 279 "data/maps/NewBarkTown/scripts.pory"

# 280 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_PlayersHouseMailbox::
# 281 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_PlayersHouse, MSGBOX_SIGN
# 282 "data/maps/NewBarkTown/scripts.pory"
	end
# 283 "data/maps/NewBarkTown/scripts.pory"

# 284 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmsHouseMailbox::
# 285 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_ElmsHouse, MSGBOX_SIGN
# 286 "data/maps/NewBarkTown/scripts.pory"
	end
# 287 "data/maps/NewBarkTown/scripts.pory"

# 288 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_PlayersHouse:
# 289 "data/maps/NewBarkTown/scripts.pory"
	.string "{PLAYER}'s House$"
# 290 "data/maps/NewBarkTown/scripts.pory"

# 291 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_ElmsHouse:
# 292 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's House$"

NewBarkTown_EventScript_RivalIntro::
# 296 "data/maps/NewBarkTown/scripts.pory"
	lock
# 297 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_0
# 298 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/NewBarkTown/scripts.pory"
	playse SE_WALL_HIT
# 300 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_1
# 301 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 302 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 303 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_2
# 304 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 306 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 307 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 308 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 309 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 310 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 311 "data/maps/NewBarkTown/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 312 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_4
# 313 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 314 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, Common_Movement_ExclamationMark
# 315 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 316 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_5
# 317 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 318 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_6
# 319 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 320 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 321 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 322 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 323 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 324 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 325 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 326 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_8
# 327 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_9
# 328 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 329 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 330 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_RIVAL
# 331 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL
# 332 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_RIVAL_STATE, 1
# 333 "data/maps/NewBarkTown/scripts.pory"
	fadedefaultbgm
# 334 "data/maps/NewBarkTown/scripts.pory"
	release
	end


# 297 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_0:
# 297 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 297 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 297 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 297 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 297 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
	step_end

# 300 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_1:
# 300 "data/maps/NewBarkTown/scripts.pory"
	jump_down
	step_end

# 303 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_2:
# 303 "data/maps/NewBarkTown/scripts.pory"
	walk_up
	step_end

# 305 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_3:
# 305 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_up
	step_end

# 312 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_4:
# 312 "data/maps/NewBarkTown/scripts.pory"
	walk_right
# 312 "data/maps/NewBarkTown/scripts.pory"
	walk_right
	step_end

# 316 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_5:
# 316 "data/maps/NewBarkTown/scripts.pory"
	face_left
	step_end

# 318 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_6:
# 318 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 318 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 318 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 318 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 318 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 320 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_7:
# 320 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_left
	step_end

# 326 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_8:
# 326 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 326 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 326 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 326 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 327 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_9:
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end
