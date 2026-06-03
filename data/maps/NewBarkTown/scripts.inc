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
    map_script_2 VAR_RIVAL_STATE, 2, NewBarkTown_EventScript_RivalBattle
# 20 "data/maps/NewBarkTown/scripts.pory"
	.2byte 0
# 21 "data/maps/NewBarkTown/scripts.pory"

# 22 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmCallAfterLeague::
# 23 "data/maps/NewBarkTown/scripts.pory"
	lock
# 24 "data/maps/NewBarkTown/scripts.pory"
	pokenavcall BlackthornCity_Text_ElmCall
# 25 "data/maps/NewBarkTown/scripts.pory"
	waitmessage
# 26 "data/maps/NewBarkTown/scripts.pory"
	delay 30
# 27 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 7
# 28 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 10
# 29 "data/maps/NewBarkTown/scripts.pory"
	release
# 30 "data/maps/NewBarkTown/scripts.pory"
	end
# 31 "data/maps/NewBarkTown/scripts.pory"

# 32 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_OnTransition::
# 33 "data/maps/NewBarkTown/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 34 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_Set_TalkToElm
# 35 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_Set_TalkToMom
# 36 "data/maps/NewBarkTown/scripts.pory"
	end
# 37 "data/maps/NewBarkTown/scripts.pory"

# 38 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToElm::
# 39 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 40 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 41 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 42 "data/maps/NewBarkTown/scripts.pory"
	end
# 43 "data/maps/NewBarkTown/scripts.pory"

# 44 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToMom::
# 45 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 46 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 47 "data/maps/NewBarkTown/scripts.pory"
	end
# 48 "data/maps/NewBarkTown/scripts.pory"

# 49 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LabSign::
# 50 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LabSign, MSGBOX_SIGN
# 51 "data/maps/NewBarkTown/scripts.pory"
	end
# 52 "data/maps/NewBarkTown/scripts.pory"

# 53 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TownSign::
# 54 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
# 55 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 56 "data/maps/NewBarkTown/scripts.pory"
	end
# 57 "data/maps/NewBarkTown/scripts.pory"

# 58 "data/maps/NewBarkTown/scripts.pory"

# 59 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Lass::
# 60 "data/maps/NewBarkTown/scripts.pory"
	lock
# 61 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 62 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LassState2
# 63 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_EventScript_LassState3
# 64 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LassState4
# 65 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState5, MSGBOX_DEFAULT
# 66 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 67 "data/maps/NewBarkTown/scripts.pory"
	release
# 68 "data/maps/NewBarkTown/scripts.pory"
	end
# 69 "data/maps/NewBarkTown/scripts.pory"
	
# 70 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState2::
# 71 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 72 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 73 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 75 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 76 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 77 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 78 "data/maps/NewBarkTown/scripts.pory"
	release
# 79 "data/maps/NewBarkTown/scripts.pory"
	end
# 80 "data/maps/NewBarkTown/scripts.pory"

# 81 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState3::
# 82 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState3, MSGBOX_DEFAULT
# 83 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 84 "data/maps/NewBarkTown/scripts.pory"
	release
# 85 "data/maps/NewBarkTown/scripts.pory"
	end
# 86 "data/maps/NewBarkTown/scripts.pory"

# 87 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState4::
# 88 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 89 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 90 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 91 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 92 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 93 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 94 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 95 "data/maps/NewBarkTown/scripts.pory"
	release
# 96 "data/maps/NewBarkTown/scripts.pory"
	end
# 97 "data/maps/NewBarkTown/scripts.pory"

# 98 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Wooper::
# 99 "data/maps/NewBarkTown/scripts.pory"
	lock
# 100 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 101 "data/maps/NewBarkTown/scripts.pory"
	waitse
# 102 "data/maps/NewBarkTown/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_NORMAL
# 103 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Wooper, MSGBOX_DEFAULT
# 104 "data/maps/NewBarkTown/scripts.pory"
	waitmoncry
# 105 "data/maps/NewBarkTown/scripts.pory"
	release
# 106 "data/maps/NewBarkTown/scripts.pory"
	end
# 107 "data/maps/NewBarkTown/scripts.pory"

# 108 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTrigger::
# 109 "data/maps/NewBarkTown/scripts.pory"
	lock
# 110 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LeaveTriggersState2
# 111 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LeaveTriggersState4
# 112 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 113 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 114 "data/maps/NewBarkTown/scripts.pory"
	release
# 115 "data/maps/NewBarkTown/scripts.pory"
	end
# 116 "data/maps/NewBarkTown/scripts.pory"

# 117 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState2::
# 118 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 119 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 120 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 121 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 122 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 124 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 125 "data/maps/NewBarkTown/scripts.pory"
	return
# 126 "data/maps/NewBarkTown/scripts.pory"

# 127 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState4::
# 128 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 129 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 130 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 131 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 132 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 133 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 134 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 135 "data/maps/NewBarkTown/scripts.pory"
	return 
# 136 "data/maps/NewBarkTown/scripts.pory"

# 137 "data/maps/NewBarkTown/scripts.pory"

# 138 "data/maps/NewBarkTown/scripts.pory"

# 139 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatMan::
# 140 "data/maps/NewBarkTown/scripts.pory"
	lock
# 141 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 142 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_FatManState2
# 143 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState3, MSGBOX_DEFAULT
# 144 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 145 "data/maps/NewBarkTown/scripts.pory"
	release
# 146 "data/maps/NewBarkTown/scripts.pory"
	end
# 147 "data/maps/NewBarkTown/scripts.pory"

# 148 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatManState2::
# 149 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState2, MSGBOX_DEFAULT
# 150 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 151 "data/maps/NewBarkTown/scripts.pory"
	release
# 152 "data/maps/NewBarkTown/scripts.pory"
	end
# 153 "data/maps/NewBarkTown/scripts.pory"

# 154 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Silver::
# 155 "data/maps/NewBarkTown/scripts.pory"
	lock
# 156 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver1, MSGBOX_DEFAULT
# 157 "data/maps/NewBarkTown/scripts.pory"
	delay 60
# 158 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 159 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_ExclamationMark
# 160 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 161 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 162 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver2, MSGBOX_DEFAULT
# 163 "data/maps/NewBarkTown/scripts.pory"
	playse SE_BANG
# 164 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, NewBarkTown_Movement_SilverPushesPlayer
# 165 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerPushedBySilver
# 166 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 167 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_FaceOriginalDirection
# 168 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 170 "data/maps/NewBarkTown/scripts.pory"
	release
# 171 "data/maps/NewBarkTown/scripts.pory"
	end
# 172 "data/maps/NewBarkTown/scripts.pory"

# 173 "data/maps/NewBarkTown/scripts.pory"

# 174 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Door::
# 175 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Door, MSGBOX_SIGN
# 176 "data/maps/NewBarkTown/scripts.pory"
	end
# 177 "data/maps/NewBarkTown/scripts.pory"

# 178 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan1::
# 179 "data/maps/NewBarkTown/scripts.pory"
	givebp 4
# 180 "data/maps/NewBarkTown/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 181 "data/maps/NewBarkTown/scripts.pory"
	end
# 182 "data/maps/NewBarkTown/scripts.pory"

# 183 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan2::
# 184 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 185 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 186 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 187 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 188 "data/maps/NewBarkTown/scripts.pory"
	end
# 189 "data/maps/NewBarkTown/scripts.pory"

# 190 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan3::
# 191 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 5
# 192 "data/maps/NewBarkTown/scripts.pory"
	
# 193 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_AERODACTYL_PUZZLE
# 194 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_HOOH_PUZZLE
# 195 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_KABUTO_PUZZLE
# 196 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_ARCHEN_PUZZLE
# 197 "data/maps/NewBarkTown/scripts.pory"
	end
# 198 "data/maps/NewBarkTown/scripts.pory"

# 199 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_SilverPushesPlayer:
# 200 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 201 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 202 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 203 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 204 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 205 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 206 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 207 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 208 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 209 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 210 "data/maps/NewBarkTown/scripts.pory"

# 211 "data/maps/NewBarkTown/scripts.pory"

# 212 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_PlayerPushedBySilver:
# 213 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 214 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 215 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 216 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 217 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 218 "data/maps/NewBarkTown/scripts.pory"
	jump_2_down
# 219 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 220 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 221 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 222 "data/maps/NewBarkTown/scripts.pory"

# 223 "data/maps/NewBarkTown/scripts.pory"
	
# 224 "data/maps/NewBarkTown/scripts.pory"

# 225 "data/maps/NewBarkTown/scripts.pory"

# 226 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_FaceDown:
# 227 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 228 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 229 "data/maps/NewBarkTown/scripts.pory"

# 230 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LabSign:
# 231 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's Lab$"
# 232 "data/maps/NewBarkTown/scripts.pory"

# 233 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Door:
# 234 "data/maps/NewBarkTown/scripts.pory"
	.string "The door is locked.$"
# 235 "data/maps/NewBarkTown/scripts.pory"

# 236 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Wooper:
# 237 "data/maps/NewBarkTown/scripts.pory"
	.string "Wooper: Woooooop.$"
# 238 "data/maps/NewBarkTown/scripts.pory"

# 239 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState2:
# 240 "data/maps/NewBarkTown/scripts.pory"
	.string "Wow, your POKéGEAR is impressive!\n"
# 241 "data/maps/NewBarkTown/scripts.pory"
	.string "Did your mom get it for you?$"
# 242 "data/maps/NewBarkTown/scripts.pory"

# 243 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState3:
# 244 "data/maps/NewBarkTown/scripts.pory"
	.string "Yo, {PLAYER}!\p"
# 245 "data/maps/NewBarkTown/scripts.pory"
	.string "I hear Prof.Elm discovered\n"
# 246 "data/maps/NewBarkTown/scripts.pory"
	.string "some new Pokémon.$"
# 247 "data/maps/NewBarkTown/scripts.pory"

# 248 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState2:
# 249 "data/maps/NewBarkTown/scripts.pory"
	.string "Wait, {PLAYER}!\p"
# 250 "data/maps/NewBarkTown/scripts.pory"
	.string "It's dangerous to go out\n"
# 251 "data/maps/NewBarkTown/scripts.pory"
	.string "without a Pokémon!\p"
# 252 "data/maps/NewBarkTown/scripts.pory"
	.string "Wild Pokémon jump out of the grass\n"
# 253 "data/maps/NewBarkTown/scripts.pory"
	.string "on the way to the next town.$"
# 254 "data/maps/NewBarkTown/scripts.pory"

# 255 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState3:
# 256 "data/maps/NewBarkTown/scripts.pory"
	.string "Oh! Your Pokémon is adorable!\n"
# 257 "data/maps/NewBarkTown/scripts.pory"
	.string "I wish I had one!$"
# 258 "data/maps/NewBarkTown/scripts.pory"

# 259 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState4:
# 260 "data/maps/NewBarkTown/scripts.pory"
	.string "Hi, {PLAYER}! Leaving again?\p"
# 261 "data/maps/NewBarkTown/scripts.pory"
	.string "You should tell your mom if\n"
# 262 "data/maps/NewBarkTown/scripts.pory"
	.string "you are leaving.$"
# 263 "data/maps/NewBarkTown/scripts.pory"

# 264 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState5:
# 265 "data/maps/NewBarkTown/scripts.pory"
	.string "Call your mom on your POKéGEAR\n"
# 266 "data/maps/NewBarkTown/scripts.pory"
	.string "to let her know how you're doing.$\p"
# 267 "data/maps/NewBarkTown/scripts.pory"

# 268 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver1:
# 269 "data/maps/NewBarkTown/scripts.pory"
	.string ". . .\p"
# 270 "data/maps/NewBarkTown/scripts.pory"
	.string "So this is the famous Elm\n"
# 271 "data/maps/NewBarkTown/scripts.pory"
	.string "Pokémon Lab…$"
# 272 "data/maps/NewBarkTown/scripts.pory"

# 273 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver2:
# 274 "data/maps/NewBarkTown/scripts.pory"
	.string "…What are you staring at?$"
# 275 "data/maps/NewBarkTown/scripts.pory"

# 276 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Sign:
# 277 "data/maps/NewBarkTown/scripts.pory"
	.string "New Bark Town\p"
# 278 "data/maps/NewBarkTown/scripts.pory"
	.string "The Town Where the Winds of\n"
# 279 "data/maps/NewBarkTown/scripts.pory"
	.string "a New Beginning Blow$"
# 280 "data/maps/NewBarkTown/scripts.pory"

# 281 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_PlayersHouseMailbox::
# 282 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_PlayersHouse, MSGBOX_SIGN
# 283 "data/maps/NewBarkTown/scripts.pory"
	end
# 284 "data/maps/NewBarkTown/scripts.pory"

# 285 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmsHouseMailbox::
# 286 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_ElmsHouse, MSGBOX_SIGN
# 287 "data/maps/NewBarkTown/scripts.pory"
	end
# 288 "data/maps/NewBarkTown/scripts.pory"

# 289 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_PlayersHouse:
# 290 "data/maps/NewBarkTown/scripts.pory"
	.string "{PLAYER}'s House$"
# 291 "data/maps/NewBarkTown/scripts.pory"

# 292 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_ElmsHouse:
# 293 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's House$"

NewBarkTown_EventScript_RivalIntro::
# 297 "data/maps/NewBarkTown/scripts.pory"
	lock
# 298 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_0
# 299 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 300 "data/maps/NewBarkTown/scripts.pory"
	playse SE_WALL_HIT
# 301 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_1
# 302 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 303 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 304 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_2
# 305 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 306 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 307 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 308 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 309 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 310 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 311 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 312 "data/maps/NewBarkTown/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 313 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_4
# 314 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 315 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, Common_Movement_ExclamationMark
# 316 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 317 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_5
# 318 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 319 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_6
# 320 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 321 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 322 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 323 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 324 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 325 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 326 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 327 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_8
# 328 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_9
# 329 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 330 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 331 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_RIVAL
# 332 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL
# 333 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL2
# 334 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_RIVAL_STATE, 1
# 335 "data/maps/NewBarkTown/scripts.pory"
	fadedefaultbgm
# 336 "data/maps/NewBarkTown/scripts.pory"
	release
	end


NewBarkTown_EventScript_RivalBattle::
# 341 "data/maps/NewBarkTown/scripts.pory"
	lock
# 342 "data/maps/NewBarkTown/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 343 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_0
# 344 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 345 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 346 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_0
# 347 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 348 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 349 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_1
# 351 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalBattle_Movement_2
# 352 "data/maps/NewBarkTown/scripts.pory"
	waitmovement LOCALID_NEWBARK_MARILL2
# 353 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, Common_Movement_ExclamationMark
# 354 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 355 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 356 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_PLAYER, NewBarkTown_EventScript_RivalBattle_Movement_3
# 357 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 358 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_5
# 359 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 360 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_0
# 361 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, NewBarkTown_EventScript_RivalBattle_Movement_4
# 362 "data/maps/NewBarkTown/scripts.pory"
	playse SE_BALL_OPEN
# 363 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 364 "data/maps/NewBarkTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 365 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_1
# 367 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_2
# 368 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_3
# 370 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_4
# 372 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_5
# 375 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_NO_WHITEOUT
# 376 "data/maps/NewBarkTown/scripts.pory"
	checkplayergender
# 377 "data/maps/NewBarkTown/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_EventScript_RivalBattle_2
# 380 "data/maps/NewBarkTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALGOLD1, NewBarkTown_EventScript_RivalBattle_Text_6
NewBarkTown_EventScript_RivalBattle_1:
# 382 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_NO_WHITEOUT
# 383 "data/maps/NewBarkTown/scripts.pory"
	special HealPlayerParty
# 384 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_7
# 386 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_8
# 389 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 390 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalBattle_Movement_5
# 391 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_6
# 392 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 393 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_RIVAL
# 394 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL
# 395 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL2
# 396 "data/maps/NewBarkTown/scripts.pory"
	fadedefaultbgm
# 397 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_RIVAL_STATE, 3
# 398 "data/maps/NewBarkTown/scripts.pory"
	release
	end

NewBarkTown_EventScript_RivalBattle_2:
# 378 "data/maps/NewBarkTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALCRYSTAL1, NewBarkTown_EventScript_RivalBattle_Text_6
	goto NewBarkTown_EventScript_RivalBattle_1


RivalsMailbox::
# 403 "data/maps/NewBarkTown/scripts.pory"
	lock
# 404 "data/maps/NewBarkTown/scripts.pory"
	checkplayergender
# 405 "data/maps/NewBarkTown/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq RivalsMailbox_2
# 408 "data/maps/NewBarkTown/scripts.pory"
	msgbox RivalsMailbox_Text_1
RivalsMailbox_1:
# 410 "data/maps/NewBarkTown/scripts.pory"
	release
	end

RivalsMailbox_2:
# 406 "data/maps/NewBarkTown/scripts.pory"
	msgbox RivalsMailbox_Text_0
	goto RivalsMailbox_1


# 298 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_0:
# 298 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 298 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 298 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 298 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 298 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
	step_end

# 301 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_1:
# 301 "data/maps/NewBarkTown/scripts.pory"
	jump_down
	step_end

# 304 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_2:
# 304 "data/maps/NewBarkTown/scripts.pory"
	walk_up
	step_end

# 306 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_3:
# 306 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_up
	step_end

# 313 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_4:
# 313 "data/maps/NewBarkTown/scripts.pory"
	walk_right
# 313 "data/maps/NewBarkTown/scripts.pory"
	walk_right
	step_end

# 317 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_5:
# 317 "data/maps/NewBarkTown/scripts.pory"
	face_left
	step_end

# 319 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_6:
# 319 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 319 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 319 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 319 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 319 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 321 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_7:
# 321 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_left
	step_end

# 327 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_8:
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 327 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 328 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_9:
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 343 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_0:
# 343 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_right
	step_end

# 349 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_1:
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 349 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 350 "data/maps/NewBarkTown/scripts.pory"
	face_left
	step_end

# 351 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_2:
# 351 "data/maps/NewBarkTown/scripts.pory"
	face_up
	step_end

# 356 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_3:
# 356 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 356 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 356 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 356 "data/maps/NewBarkTown/scripts.pory"
	walk_right
	step_end

# 361 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_4:
# 361 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 361 "data/maps/NewBarkTown/scripts.pory"
	face_right
# 361 "data/maps/NewBarkTown/scripts.pory"
	exit_pokeball
# 361 "data/maps/NewBarkTown/scripts.pory"
	set_visible
	step_end

# 390 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_5:
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 390 "data/maps/NewBarkTown/scripts.pory"
	walk_down
	step_end

# 391 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_6:
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 391 "data/maps/NewBarkTown/scripts.pory"
	walk_down
	step_end

NewBarkTown_EventScript_RivalBattle_Text_0:
# 360 "data/maps/NewBarkTown/scripts.pory"
	.string "{PLAYER}!$"

NewBarkTown_EventScript_RivalBattle_Text_1:
# 365 "data/maps/NewBarkTown/scripts.pory"
	.string "So you picked...\n"
	.string "a {STR_VAR_1}!$"

NewBarkTown_EventScript_RivalBattle_Text_2:
# 367 "data/maps/NewBarkTown/scripts.pory"
	.string "That's a cute Pokémon you have!$"

NewBarkTown_EventScript_RivalBattle_Text_3:
# 368 "data/maps/NewBarkTown/scripts.pory"
	.string "When you walk with it, it'll become\n"
	.string "more friendly!$"

NewBarkTown_EventScript_RivalBattle_Text_4:
# 370 "data/maps/NewBarkTown/scripts.pory"
	.string "You should turn around and talk to it\n"
	.string "sometimes, too.$"

NewBarkTown_EventScript_RivalBattle_Text_5:
# 372 "data/maps/NewBarkTown/scripts.pory"
	.string "Hey, why don't we have a battle?\n"
	.string "That's what trainers usually do when\l"
	.string "they meet!$"

NewBarkTown_EventScript_RivalBattle_Text_6:
# 378 "data/maps/NewBarkTown/scripts.pory"
	.string "You did really well, {PLAYER}!$"

NewBarkTown_EventScript_RivalBattle_Text_7:
# 384 "data/maps/NewBarkTown/scripts.pory"
	.string "That was really fun, and both of our\n"
	.string "Pokémon did their best!$"

NewBarkTown_EventScript_RivalBattle_Text_8:
# 386 "data/maps/NewBarkTown/scripts.pory"
	.string "You got a task from Elm right?\n"
	.string "I'll leave you to it then.\l"
	.string "See ya!$"

RivalsMailbox_Text_0:
# 406 "data/maps/NewBarkTown/scripts.pory"
	.string "Crystal's house$"

RivalsMailbox_Text_1:
# 408 "data/maps/NewBarkTown/scripts.pory"
	.string "Gold's house$"
