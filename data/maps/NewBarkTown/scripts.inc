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
	map_script_2 VAR_NEWBARK_TOWN_STATE, 11, NewBarkTown_EventScript_ArcherArcadeCall
# 19 "data/maps/NewBarkTown/scripts.pory"
    map_script_2 VAR_RIVAL_STATE, 0, NewBarkTown_EventScript_RivalIntro
# 20 "data/maps/NewBarkTown/scripts.pory"
    map_script_2 VAR_RIVAL_STATE, 2, NewBarkTown_EventScript_RivalBattle
# 21 "data/maps/NewBarkTown/scripts.pory"
	.2byte 0
# 22 "data/maps/NewBarkTown/scripts.pory"

# 23 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmCallAfterLeague::
# 24 "data/maps/NewBarkTown/scripts.pory"
	lock
# 25 "data/maps/NewBarkTown/scripts.pory"
	pokenavcall BlackthornCity_Text_ElmCall
# 26 "data/maps/NewBarkTown/scripts.pory"
	waitmessage
# 27 "data/maps/NewBarkTown/scripts.pory"
	delay 30
# 28 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 7
# 29 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 10
# 30 "data/maps/NewBarkTown/scripts.pory"
	release
# 31 "data/maps/NewBarkTown/scripts.pory"
	end
# 32 "data/maps/NewBarkTown/scripts.pory"

# 33 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_OnTransition::
# 34 "data/maps/NewBarkTown/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 35 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_Set_TalkToElm
# 36 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_Set_TalkToMom
# 37 "data/maps/NewBarkTown/scripts.pory"
	end
# 38 "data/maps/NewBarkTown/scripts.pory"

# 39 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToElm::
# 40 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 41 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 42 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 43 "data/maps/NewBarkTown/scripts.pory"
	end
# 44 "data/maps/NewBarkTown/scripts.pory"

# 45 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Set_TalkToMom::
# 46 "data/maps/NewBarkTown/scripts.pory"
	setobjectxyperm LOCALID_LASS, 0, 11
# 47 "data/maps/NewBarkTown/scripts.pory"
	callnative SetTimeBasedEncounters
# 48 "data/maps/NewBarkTown/scripts.pory"
	end
# 49 "data/maps/NewBarkTown/scripts.pory"

# 50 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LabSign::
# 51 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LabSign, MSGBOX_SIGN
# 52 "data/maps/NewBarkTown/scripts.pory"
	end
# 53 "data/maps/NewBarkTown/scripts.pory"

# 54 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TownSign::
# 55 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
# 56 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 57 "data/maps/NewBarkTown/scripts.pory"
	end
# 58 "data/maps/NewBarkTown/scripts.pory"

# 59 "data/maps/NewBarkTown/scripts.pory"

# 60 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Lass::
# 61 "data/maps/NewBarkTown/scripts.pory"
	lock
# 62 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 63 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LassState2
# 64 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_EventScript_LassState3
# 65 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LassState4
# 66 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState5, MSGBOX_DEFAULT
# 67 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 68 "data/maps/NewBarkTown/scripts.pory"
	release
# 69 "data/maps/NewBarkTown/scripts.pory"
	end
# 70 "data/maps/NewBarkTown/scripts.pory"
	
# 71 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState2::
# 72 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 73 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 74 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 75 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 76 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 77 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 78 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 79 "data/maps/NewBarkTown/scripts.pory"
	release
# 80 "data/maps/NewBarkTown/scripts.pory"
	end
# 81 "data/maps/NewBarkTown/scripts.pory"

# 82 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState3::
# 83 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState3, MSGBOX_DEFAULT
# 84 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 85 "data/maps/NewBarkTown/scripts.pory"
	release
# 86 "data/maps/NewBarkTown/scripts.pory"
	end
# 87 "data/maps/NewBarkTown/scripts.pory"

# 88 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LassState4::
# 89 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 90 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 91 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 92 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 93 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 94 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 95 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 96 "data/maps/NewBarkTown/scripts.pory"
	release
# 97 "data/maps/NewBarkTown/scripts.pory"
	end
# 98 "data/maps/NewBarkTown/scripts.pory"

# 99 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Wooper::
# 100 "data/maps/NewBarkTown/scripts.pory"
	lock
# 101 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 102 "data/maps/NewBarkTown/scripts.pory"
	waitse
# 103 "data/maps/NewBarkTown/scripts.pory"
	playmoncry SPECIES_WOOPER, CRY_MODE_NORMAL
# 104 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Wooper, MSGBOX_DEFAULT
# 105 "data/maps/NewBarkTown/scripts.pory"
	waitmoncry
# 106 "data/maps/NewBarkTown/scripts.pory"
	release
# 107 "data/maps/NewBarkTown/scripts.pory"
	end
# 108 "data/maps/NewBarkTown/scripts.pory"

# 109 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTrigger::
# 110 "data/maps/NewBarkTown/scripts.pory"
	lock
# 111 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LeaveTriggersState2
# 112 "data/maps/NewBarkTown/scripts.pory"
	call_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LeaveTriggersState4
# 113 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 114 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 115 "data/maps/NewBarkTown/scripts.pory"
	release
# 116 "data/maps/NewBarkTown/scripts.pory"
	end
# 117 "data/maps/NewBarkTown/scripts.pory"

# 118 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState2::
# 119 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 120 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 121 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 122 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 123 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 124 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
# 125 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 126 "data/maps/NewBarkTown/scripts.pory"
	return
# 127 "data/maps/NewBarkTown/scripts.pory"

# 128 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_LeaveTriggersState4::
# 129 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 130 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
# 131 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
# 133 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 134 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
# 135 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 136 "data/maps/NewBarkTown/scripts.pory"
	return 
# 137 "data/maps/NewBarkTown/scripts.pory"

# 138 "data/maps/NewBarkTown/scripts.pory"

# 139 "data/maps/NewBarkTown/scripts.pory"

# 140 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatMan::
# 141 "data/maps/NewBarkTown/scripts.pory"
	lock
# 142 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 143 "data/maps/NewBarkTown/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_FatManState2
# 144 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState3, MSGBOX_DEFAULT
# 145 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 146 "data/maps/NewBarkTown/scripts.pory"
	release
# 147 "data/maps/NewBarkTown/scripts.pory"
	end
# 148 "data/maps/NewBarkTown/scripts.pory"

# 149 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_FatManState2::
# 150 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_FatManState2, MSGBOX_DEFAULT
# 151 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 152 "data/maps/NewBarkTown/scripts.pory"
	release
# 153 "data/maps/NewBarkTown/scripts.pory"
	end
# 154 "data/maps/NewBarkTown/scripts.pory"

# 155 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Silver::
# 156 "data/maps/NewBarkTown/scripts.pory"
	lock
# 157 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver1, MSGBOX_DEFAULT
# 158 "data/maps/NewBarkTown/scripts.pory"
	delay 60
# 159 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 160 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_ExclamationMark
# 161 "data/maps/NewBarkTown/scripts.pory"
	faceplayer
# 162 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Silver2, MSGBOX_DEFAULT
# 164 "data/maps/NewBarkTown/scripts.pory"
	playse SE_BANG
# 165 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, NewBarkTown_Movement_SilverPushesPlayer
# 166 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerPushedBySilver
# 167 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_SILVER, Common_Movement_FaceOriginalDirection
# 169 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 170 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 171 "data/maps/NewBarkTown/scripts.pory"
	release
# 172 "data/maps/NewBarkTown/scripts.pory"
	end
# 173 "data/maps/NewBarkTown/scripts.pory"

# 174 "data/maps/NewBarkTown/scripts.pory"

# 175 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_Door::
# 176 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_Door, MSGBOX_SIGN
# 177 "data/maps/NewBarkTown/scripts.pory"
	end
# 178 "data/maps/NewBarkTown/scripts.pory"

# 179 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan1::
# 180 "data/maps/NewBarkTown/scripts.pory"
	givebp 4
# 181 "data/maps/NewBarkTown/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 182 "data/maps/NewBarkTown/scripts.pory"
	end
# 183 "data/maps/NewBarkTown/scripts.pory"

# 184 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan2::
# 185 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 186 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 187 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 188 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 189 "data/maps/NewBarkTown/scripts.pory"
	end
# 190 "data/maps/NewBarkTown/scripts.pory"

# 191 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_TestMan3::
# 192 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 5
# 193 "data/maps/NewBarkTown/scripts.pory"
	
# 194 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_AERODACTYL_PUZZLE
# 195 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_HOOH_PUZZLE
# 196 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_KABUTO_PUZZLE
# 197 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_COMPLETED_ARCHEN_PUZZLE
# 198 "data/maps/NewBarkTown/scripts.pory"
	end
# 199 "data/maps/NewBarkTown/scripts.pory"

# 200 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_SilverPushesPlayer:
# 201 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 202 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 203 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 204 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 205 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 206 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 207 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 208 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 209 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 210 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 211 "data/maps/NewBarkTown/scripts.pory"

# 212 "data/maps/NewBarkTown/scripts.pory"

# 213 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_PlayerPushedBySilver:
# 214 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 215 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 216 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 217 "data/maps/NewBarkTown/scripts.pory"
	face_up
# 218 "data/maps/NewBarkTown/scripts.pory"
	lock_facing_direction
# 219 "data/maps/NewBarkTown/scripts.pory"
	jump_2_down
# 220 "data/maps/NewBarkTown/scripts.pory"
	unlock_facing_direction
# 221 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 222 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 223 "data/maps/NewBarkTown/scripts.pory"

# 224 "data/maps/NewBarkTown/scripts.pory"
	
# 225 "data/maps/NewBarkTown/scripts.pory"

# 226 "data/maps/NewBarkTown/scripts.pory"

# 227 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Movement_FaceDown:
# 228 "data/maps/NewBarkTown/scripts.pory"
	face_down
# 229 "data/maps/NewBarkTown/scripts.pory"
	step_end
# 230 "data/maps/NewBarkTown/scripts.pory"

# 231 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LabSign:
# 232 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's Lab$"
# 233 "data/maps/NewBarkTown/scripts.pory"

# 234 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Door:
# 235 "data/maps/NewBarkTown/scripts.pory"
	.string "The door is locked.$"
# 236 "data/maps/NewBarkTown/scripts.pory"

# 237 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Wooper:
# 238 "data/maps/NewBarkTown/scripts.pory"
	.string "Wooper: Woooooop.$"
# 239 "data/maps/NewBarkTown/scripts.pory"

# 240 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState2:
# 241 "data/maps/NewBarkTown/scripts.pory"
	.string "Wow, your Pokégear is impressive!\n"
# 242 "data/maps/NewBarkTown/scripts.pory"
	.string "Did your mom get it for you?$"
# 243 "data/maps/NewBarkTown/scripts.pory"

# 244 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_FatManState3:
# 245 "data/maps/NewBarkTown/scripts.pory"
	.string "Yo, {PLAYER}!\p"
# 246 "data/maps/NewBarkTown/scripts.pory"
	.string "I hear Prof.Elm discovered\n"
# 247 "data/maps/NewBarkTown/scripts.pory"
	.string "some new Pokémon.$"
# 248 "data/maps/NewBarkTown/scripts.pory"

# 249 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState2:
# 250 "data/maps/NewBarkTown/scripts.pory"
	.string "Wait, {PLAYER}!\p"
# 251 "data/maps/NewBarkTown/scripts.pory"
	.string "It's dangerous to go out\n"
# 252 "data/maps/NewBarkTown/scripts.pory"
	.string "without a Pokémon!\p"
# 253 "data/maps/NewBarkTown/scripts.pory"
	.string "Wild Pokémon jump out of the grass\n"
# 254 "data/maps/NewBarkTown/scripts.pory"
	.string "on the way to the next town.$"
# 255 "data/maps/NewBarkTown/scripts.pory"

# 256 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState3:
# 257 "data/maps/NewBarkTown/scripts.pory"
	.string "Oh! Your Pokémon is adorable!\n"
# 258 "data/maps/NewBarkTown/scripts.pory"
	.string "I wish I had one!$"
# 259 "data/maps/NewBarkTown/scripts.pory"

# 260 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState4:
# 261 "data/maps/NewBarkTown/scripts.pory"
	.string "Hi, {PLAYER}! Leaving again?\p"
# 262 "data/maps/NewBarkTown/scripts.pory"
	.string "You should tell your mom if\n"
# 263 "data/maps/NewBarkTown/scripts.pory"
	.string "you are leaving.$"
# 264 "data/maps/NewBarkTown/scripts.pory"

# 265 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_LassState5:
# 266 "data/maps/NewBarkTown/scripts.pory"
	.string "Call your mom on your Pokégear\n"
# 267 "data/maps/NewBarkTown/scripts.pory"
	.string "to let her know how you're doing.$\p"
# 268 "data/maps/NewBarkTown/scripts.pory"

# 269 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver1:
# 270 "data/maps/NewBarkTown/scripts.pory"
	.string ". . .\p"
# 271 "data/maps/NewBarkTown/scripts.pory"
	.string "So this is the famous Elm\n"
# 272 "data/maps/NewBarkTown/scripts.pory"
	.string "Pokémon Lab…$"
# 273 "data/maps/NewBarkTown/scripts.pory"

# 274 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Silver2:
# 275 "data/maps/NewBarkTown/scripts.pory"
	.string "…What are you staring at?$"
# 276 "data/maps/NewBarkTown/scripts.pory"

# 277 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_Sign:
# 278 "data/maps/NewBarkTown/scripts.pory"
	.string "New Bark Town\p"
# 279 "data/maps/NewBarkTown/scripts.pory"
	.string "The Town Where the Winds of\n"
# 280 "data/maps/NewBarkTown/scripts.pory"
	.string "a New Beginning Blow$"
# 281 "data/maps/NewBarkTown/scripts.pory"

# 282 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_PlayersHouseMailbox::
# 283 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_PlayersHouse, MSGBOX_SIGN
# 284 "data/maps/NewBarkTown/scripts.pory"
	end
# 285 "data/maps/NewBarkTown/scripts.pory"

# 286 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_ElmsHouseMailbox::
# 287 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_Text_ElmsHouse, MSGBOX_SIGN
# 288 "data/maps/NewBarkTown/scripts.pory"
	end
# 289 "data/maps/NewBarkTown/scripts.pory"

# 290 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_PlayersHouse:
# 291 "data/maps/NewBarkTown/scripts.pory"
	.string "{PLAYER}'s House$"
# 292 "data/maps/NewBarkTown/scripts.pory"

# 293 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_Text_ElmsHouse:
# 294 "data/maps/NewBarkTown/scripts.pory"
	.string "Prof.Elm's House$"

NewBarkTown_EventScript_RivalIntro::
# 298 "data/maps/NewBarkTown/scripts.pory"
	lock
# 299 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_0
# 300 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 301 "data/maps/NewBarkTown/scripts.pory"
	playse SE_WALL_HIT
# 302 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_1
# 303 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 304 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_2
# 306 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 307 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 308 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 309 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 310 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_3
# 311 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 312 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 313 "data/maps/NewBarkTown/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 314 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_4
# 315 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 316 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, Common_Movement_ExclamationMark
# 317 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 318 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_5
# 319 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 320 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_6
# 321 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 322 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 323 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 324 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 325 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_7
# 326 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 327 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 328 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_8
# 329 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL, NewBarkTown_EventScript_RivalIntro_Movement_9
# 330 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 331 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 332 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_RIVAL
# 333 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL
# 334 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL2
# 335 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_RIVAL_STATE, 1
# 336 "data/maps/NewBarkTown/scripts.pory"
	fadedefaultbgm
# 337 "data/maps/NewBarkTown/scripts.pory"
	release
	end


NewBarkTown_EventScript_RivalBattle::
# 342 "data/maps/NewBarkTown/scripts.pory"
	lock
# 343 "data/maps/NewBarkTown/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 344 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_0
# 345 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 346 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 347 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_0
# 348 "data/maps/NewBarkTown/scripts.pory"
	playse SE_LEDGE
# 349 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 350 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_1
# 352 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalBattle_Movement_2
# 353 "data/maps/NewBarkTown/scripts.pory"
	waitmovement LOCALID_NEWBARK_MARILL2
# 354 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, Common_Movement_ExclamationMark
# 355 "data/maps/NewBarkTown/scripts.pory"
	playse SE_PIN
# 356 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 357 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_PLAYER, NewBarkTown_EventScript_RivalBattle_Movement_3
# 358 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 359 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalIntro_Movement_5
# 360 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 361 "data/maps/NewBarkTown/scripts.pory"
	createfieldmugshotrival
# 362 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_0
# 363 "data/maps/NewBarkTown/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, NewBarkTown_EventScript_RivalBattle_Movement_4
# 364 "data/maps/NewBarkTown/scripts.pory"
	playse SE_BALL_OPEN
# 365 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 366 "data/maps/NewBarkTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 367 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_1
# 369 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_2
# 370 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_3
# 372 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_4
# 374 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_5
# 377 "data/maps/NewBarkTown/scripts.pory"
	setflag FLAG_NO_WHITEOUT
# 378 "data/maps/NewBarkTown/scripts.pory"
	checkplayergender
# 379 "data/maps/NewBarkTown/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_EventScript_RivalBattle_2
# 382 "data/maps/NewBarkTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALGOLD1, NewBarkTown_EventScript_RivalBattle_Text_6
NewBarkTown_EventScript_RivalBattle_1:
# 384 "data/maps/NewBarkTown/scripts.pory"
	clearflag FLAG_NO_WHITEOUT
# 385 "data/maps/NewBarkTown/scripts.pory"
	special HealPlayerParty
# 386 "data/maps/NewBarkTown/scripts.pory"
	createfieldmugshotrival
# 387 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_7
# 389 "data/maps/NewBarkTown/scripts.pory"
	msgbox NewBarkTown_EventScript_RivalBattle_Text_8
# 392 "data/maps/NewBarkTown/scripts.pory"
	removefieldmugshot
# 393 "data/maps/NewBarkTown/scripts.pory"
	closemessage
# 394 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_RIVAL, NewBarkTown_EventScript_RivalBattle_Movement_5
# 395 "data/maps/NewBarkTown/scripts.pory"
	applymovement LOCALID_NEWBARK_MARILL2, NewBarkTown_EventScript_RivalBattle_Movement_6
# 396 "data/maps/NewBarkTown/scripts.pory"
	waitmovement 0
# 397 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_RIVAL
# 398 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL
# 399 "data/maps/NewBarkTown/scripts.pory"
	removeobject LOCALID_NEWBARK_MARILL2
# 400 "data/maps/NewBarkTown/scripts.pory"
	fadedefaultbgm
# 401 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_RIVAL_STATE, 3
# 402 "data/maps/NewBarkTown/scripts.pory"
	release
	end

NewBarkTown_EventScript_RivalBattle_2:
# 380 "data/maps/NewBarkTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALCRYSTAL1, NewBarkTown_EventScript_RivalBattle_Text_6
	goto NewBarkTown_EventScript_RivalBattle_1


RivalsMailbox::
# 407 "data/maps/NewBarkTown/scripts.pory"
	lock
# 408 "data/maps/NewBarkTown/scripts.pory"
	checkplayergender
# 409 "data/maps/NewBarkTown/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq RivalsMailbox_2
# 412 "data/maps/NewBarkTown/scripts.pory"
	msgbox RivalsMailbox_Text_1
RivalsMailbox_1:
# 414 "data/maps/NewBarkTown/scripts.pory"
	release
	end

RivalsMailbox_2:
# 410 "data/maps/NewBarkTown/scripts.pory"
	msgbox RivalsMailbox_Text_0
	goto RivalsMailbox_1


NewBarkTown_EventScript_ArcherArcadeCall::
# 419 "data/maps/NewBarkTown/scripts.pory"
	lock
# 420 "data/maps/NewBarkTown/scripts.pory"
	pokenavcall NewBarkTown_EventScript_ArcherArcadeCall_Text_0
# 435 "data/maps/NewBarkTown/scripts.pory"
	waitmessage
# 436 "data/maps/NewBarkTown/scripts.pory"
	delay 30
# 437 "data/maps/NewBarkTown/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 12
# 438 "data/maps/NewBarkTown/scripts.pory"
	release
	end


# 299 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_0:
# 299 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 299 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 299 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 299 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 299 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
	step_end

# 302 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_1:
# 302 "data/maps/NewBarkTown/scripts.pory"
	jump_down
	step_end

# 305 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_2:
# 305 "data/maps/NewBarkTown/scripts.pory"
	walk_up
	step_end

# 307 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_3:
# 307 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_up
	step_end

# 314 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_4:
# 314 "data/maps/NewBarkTown/scripts.pory"
	walk_right
# 314 "data/maps/NewBarkTown/scripts.pory"
	walk_right
	step_end

# 318 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_5:
# 318 "data/maps/NewBarkTown/scripts.pory"
	face_left
	step_end

# 320 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_6:
# 320 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 320 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 320 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 320 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 320 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 322 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_7:
# 322 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_left
	step_end

# 328 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_8:
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 328 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 329 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalIntro_Movement_9:
# 329 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 329 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 329 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 329 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 329 "data/maps/NewBarkTown/scripts.pory"
	walk_left
	step_end

# 344 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_0:
# 344 "data/maps/NewBarkTown/scripts.pory"
	jump_in_place_right
	step_end

# 350 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_1:
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 350 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 351 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 351 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_up
# 351 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 351 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_right
# 351 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_down
# 351 "data/maps/NewBarkTown/scripts.pory"
	face_left
	step_end

# 352 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_2:
# 352 "data/maps/NewBarkTown/scripts.pory"
	face_up
	step_end

# 357 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_3:
# 357 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 357 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 357 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 357 "data/maps/NewBarkTown/scripts.pory"
	walk_right
	step_end

# 363 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_4:
# 363 "data/maps/NewBarkTown/scripts.pory"
	walk_fast_left
# 363 "data/maps/NewBarkTown/scripts.pory"
	face_right
# 363 "data/maps/NewBarkTown/scripts.pory"
	exit_pokeball
# 363 "data/maps/NewBarkTown/scripts.pory"
	set_visible
	step_end

# 394 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_5:
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 394 "data/maps/NewBarkTown/scripts.pory"
	walk_down
	step_end

# 395 "data/maps/NewBarkTown/scripts.pory"
NewBarkTown_EventScript_RivalBattle_Movement_6:
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_left
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
# 395 "data/maps/NewBarkTown/scripts.pory"
	walk_down
	step_end

NewBarkTown_EventScript_RivalBattle_Text_0:
# 362 "data/maps/NewBarkTown/scripts.pory"
	.string "{PLAYER}!$"

NewBarkTown_EventScript_RivalBattle_Text_1:
# 367 "data/maps/NewBarkTown/scripts.pory"
	.string "So you picked...\n"
	.string "a {STR_VAR_1}!$"

NewBarkTown_EventScript_RivalBattle_Text_2:
# 369 "data/maps/NewBarkTown/scripts.pory"
	.string "That's a cute Pokémon you have!$"

NewBarkTown_EventScript_RivalBattle_Text_3:
# 370 "data/maps/NewBarkTown/scripts.pory"
	.string "When you walk with it, it'll become\n"
	.string "more friendly!$"

NewBarkTown_EventScript_RivalBattle_Text_4:
# 372 "data/maps/NewBarkTown/scripts.pory"
	.string "You should turn around and talk to it\n"
	.string "sometimes, too.$"

NewBarkTown_EventScript_RivalBattle_Text_5:
# 374 "data/maps/NewBarkTown/scripts.pory"
	.string "Hey, why don't we have a battle?\n"
	.string "That's what trainers usually do when\l"
	.string "they meet!$"

NewBarkTown_EventScript_RivalBattle_Text_6:
# 380 "data/maps/NewBarkTown/scripts.pory"
	.string "You did really well, {PLAYER}!$"

NewBarkTown_EventScript_RivalBattle_Text_7:
# 387 "data/maps/NewBarkTown/scripts.pory"
	.string "That was really fun, and both of our\n"
	.string "Pokémon did their best!$"

NewBarkTown_EventScript_RivalBattle_Text_8:
# 389 "data/maps/NewBarkTown/scripts.pory"
	.string "You got a task from Elm right?\n"
	.string "I'll leave you to it then.\l"
	.string "See ya!$"

RivalsMailbox_Text_0:
# 410 "data/maps/NewBarkTown/scripts.pory"
	.string "Crystal's house$"

RivalsMailbox_Text_1:
# 412 "data/maps/NewBarkTown/scripts.pory"
	.string "Gold's house$"

NewBarkTown_EventScript_ArcherArcadeCall_Text_0:
# 420 "data/maps/NewBarkTown/scripts.pory"
	.string "???: Greetings, {PLAYER}.\p"
	.string "This is Archer speaking.\p"
	.string "Archer: I've heard of your victory\n"
	.string "in the League and would like to \l"
	.string "offer you an invitation to our \l"
	.string "newly opened Rocket Arcade.\p"
	.string "If you are interested in gambling\n"
	.string "your way to the top, come visit us\l"
	.string "in the Goldenrod Underground.\p"
	.string "I assure you no tricks or traps are\n"
	.string "planned for you this time.$"
