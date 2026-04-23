# 1 "data/maps/AzaleaTown_Gym/scripts.pory"

# 2 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_LEFT1, 8
# 3 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_MID1, 9
# 4 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_RIGHT1, 10
# 5 "data/maps/AzaleaTown_Gym/scripts.pory"

# 6 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_LEFT2, 11
# 7 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_MID2, 12
# 8 "data/maps/AzaleaTown_Gym/scripts.pory"
.set LOCALID_AZALEA_ARIADOS_RIGHT2, 13
# 9 "data/maps/AzaleaTown_Gym/scripts.pory"

# 10 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_MapScripts::
# 11 "data/maps/AzaleaTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Gym_OnTransition
# 12 "data/maps/AzaleaTown_Gym/scripts.pory"
	.byte 0
# 13 "data/maps/AzaleaTown_Gym/scripts.pory"

# 14 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_OnTransition::
# 15 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 16 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 17 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 18 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 19 "data/maps/AzaleaTown_Gym/scripts.pory"

# 20 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 1-8->5,  5-9->1
# 21 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_1::
# 22 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 23 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 24 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 25 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_LEFT1
# 26 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 27 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
# 28 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 29 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_LEFT1, DIR_NORTH
# 30 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 31 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 32 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 33 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 34 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 35 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
# 36 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 37 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 38 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 39 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 40 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
# 41 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 42 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 43 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 44 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 45 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
# 46 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 47 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 48 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 49 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 50 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
# 51 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 52 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 53 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_LEFT1
# 54 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 55 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 56 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 57 "data/maps/AzaleaTown_Gym/scripts.pory"

# 58 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_5::
# 59 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 60 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 61 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 62 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_MID1
# 63 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 64 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
# 65 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 66 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_MID1, DIR_SOUTH
# 67 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 68 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 69 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 70 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 71 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 72 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
# 73 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 74 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 75 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 76 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 77 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 78 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Left
# 79 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 80 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 81 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 82 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 83 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
# 84 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 85 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 86 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 87 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 88 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 89 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 90 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
# 91 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 92 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 93 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_MID1
# 94 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 95 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 96 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 97 "data/maps/AzaleaTown_Gym/scripts.pory"

# 98 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 2-9->6,  6-10->2
# 99 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_2::
# 100 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 101 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 102 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 103 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_MID1
# 104 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 105 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
# 106 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 107 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_MID1, DIR_NORTH
# 108 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 109 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 110 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 111 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 112 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 113 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
# 114 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 115 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 116 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 117 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 118 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Right
# 119 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 120 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 121 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 122 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 123 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
# 124 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 125 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 126 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 127 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 128 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 129 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
# 130 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 131 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 132 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_MID1
# 133 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 134 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 135 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 136 "data/maps/AzaleaTown_Gym/scripts.pory"

# 137 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_6::
# 138 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 139 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 140 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 141 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_RIGHT1
# 142 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 143 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
# 144 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 145 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT1, DIR_SOUTH
# 146 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 147 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 148 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 149 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 150 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 151 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
# 152 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 153 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 154 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 155 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 156 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 157 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
# 158 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 159 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 160 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 161 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 162 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
# 163 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 164 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 165 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 166 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 167 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 168 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 169 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
# 170 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 171 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 172 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT1
# 173 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 174 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 175 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 176 "data/maps/AzaleaTown_Gym/scripts.pory"

# 177 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 3-10->4,  4-8->3
# 178 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_3::
# 179 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 180 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 181 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 182 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_RIGHT1
# 183 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 184 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
# 185 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 186 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT1, DIR_NORTH
# 187 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 188 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 189 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 190 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 191 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 192 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
# 193 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 194 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 195 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 196 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 197 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
# 198 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 199 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 200 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 201 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
# 202 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 203 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 204 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 205 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 206 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
# 207 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 208 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 209 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 210 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 211 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 212 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
# 213 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 214 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 215 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT1
# 216 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 217 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 218 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 219 "data/maps/AzaleaTown_Gym/scripts.pory"

# 220 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_4::
# 221 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 222 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 223 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 224 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_LEFT1
# 225 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 226 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
# 227 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 228 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_LEFT1, DIR_SOUTH
# 229 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 230 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 231 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 232 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 233 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 234 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
# 235 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 236 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 237 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 238 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 239 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 240 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
# 241 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 242 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 243 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 244 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
# 245 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 246 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 247 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 248 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 249 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
# 250 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 251 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 252 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 253 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 254 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 255 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 256 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
# 257 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 258 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 259 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_LEFT1
# 260 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 261 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 262 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 263 "data/maps/AzaleaTown_Gym/scripts.pory"

# 264 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 7-11->10,  10-11->7
# 265 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_7::
# 266 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 267 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 268 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 269 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_LEFT2
# 270 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 271 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
# 272 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 273 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_LEFT2, DIR_NORTH
# 274 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 275 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 276 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 277 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 278 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 279 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
# 280 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 281 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 282 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 283 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
# 284 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 285 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 286 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 287 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 288 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 289 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
# 290 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 291 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 292 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_LEFT2
# 293 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 294 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 295 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 296 "data/maps/AzaleaTown_Gym/scripts.pory"

# 297 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_10::
# 298 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 299 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 300 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 301 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_LEFT2
# 302 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 303 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
# 304 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 305 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_LEFT2, DIR_SOUTH
# 306 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 307 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 308 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 309 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 310 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 311 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
# 312 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 313 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 314 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 315 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 316 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
# 317 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 318 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 319 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 320 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 321 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 322 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 323 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
# 324 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 325 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
# 326 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_LEFT2
# 327 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 328 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 329 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 330 "data/maps/AzaleaTown_Gym/scripts.pory"

# 331 "data/maps/AzaleaTown_Gym/scripts.pory"

# 332 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 8-12->12,  12-13->8
# 333 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_8::
# 334 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 335 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 336 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 337 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_MID2
# 338 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 339 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
# 340 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 341 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_MID2, DIR_NORTH
# 342 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 343 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 344 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 345 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 346 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 347 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
# 348 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 349 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 350 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 351 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 352 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Right
# 353 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 354 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 355 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 356 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 357 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
# 358 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 359 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 360 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 361 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 362 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 363 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
# 364 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 365 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 366 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_MID2
# 367 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 368 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 369 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 370 "data/maps/AzaleaTown_Gym/scripts.pory"

# 371 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_12::
# 372 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 373 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 374 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 375 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_RIGHT2
# 376 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 377 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
# 378 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 379 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT2, DIR_SOUTH
# 380 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 381 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 382 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 383 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 384 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 385 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
# 386 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 387 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 388 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 389 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 390 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 391 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Left
# 392 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 393 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 394 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 395 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 396 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
# 397 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 398 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 399 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 400 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 401 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 402 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 403 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
# 404 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 405 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 406 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT2
# 407 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 408 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 409 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 410 "data/maps/AzaleaTown_Gym/scripts.pory"

# 411 "data/maps/AzaleaTown_Gym/scripts.pory"
@ 9-13->11,  11-12->9
# 412 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_9::
# 413 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 414 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 415 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 416 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_RIGHT2
# 417 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 418 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
# 419 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 420 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT2, DIR_NORTH
# 421 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 422 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 423 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 424 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 425 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 426 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
# 427 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 428 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 429 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 430 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 431 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Left
# 432 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
# 433 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 434 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 435 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 436 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
# 437 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
# 438 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 439 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
# 440 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 441 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 442 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
# 443 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 444 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
# 445 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT2
# 446 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 447 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 448 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 449 "data/maps/AzaleaTown_Gym/scripts.pory"

# 450 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Trigger_11::
# 451 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 452 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 453 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 454 "data/maps/AzaleaTown_Gym/scripts.pory"
	addobject LOCALID_AZALEA_ARIADOS_MID2
# 455 "data/maps/AzaleaTown_Gym/scripts.pory"
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
# 456 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
# 457 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 458 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject LOCALID_AZALEA_ARIADOS_MID2, DIR_SOUTH
# 459 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 30
# 460 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 461 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 462 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 463 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 464 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
# 465 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 466 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 467 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 468 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 469 "data/maps/AzaleaTown_Gym/scripts.pory"
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 470 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Right
# 471 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
# 472 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 473 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 474 "data/maps/AzaleaTown_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 475 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
# 476 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay 3
# 477 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
# 478 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 479 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
# 480 "data/maps/AzaleaTown_Gym/scripts.pory"
	playse SE_LEDGE
# 481 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 482 "data/maps/AzaleaTown_Gym/scripts.pory"
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
# 483 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmovement 0
# 484 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
# 485 "data/maps/AzaleaTown_Gym/scripts.pory"
	removeobject LOCALID_AZALEA_ARIADOS_MID2
# 486 "data/maps/AzaleaTown_Gym/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
# 487 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 488 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 489 "data/maps/AzaleaTown_Gym/scripts.pory"

# 490 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_GymGuy::
# 491 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 492 "data/maps/AzaleaTown_Gym/scripts.pory"
	faceplayer
# 493 "data/maps/AzaleaTown_Gym/scripts.pory"
	goto_if_set FLAG_GARBAGEFLAG, AzaleaTown_Gym_EventScript_GymGuy2
# 494 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_GymGuide, MSGBOX_DEFAULT
# 495 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 496 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 497 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 498 "data/maps/AzaleaTown_Gym/scripts.pory"

# 499 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_GymGuy2::
# 500 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
# 501 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 502 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 503 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 504 "data/maps/AzaleaTown_Gym/scripts.pory"

# 505 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Al::
# 506 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_AL AzaleaTown_Gym_Text_BugCatcherAlSeen, AzaleaTown_Gym_Text_BugCatcherAlBeaten
# 507 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_BugCatcherAlAfter, MSGBOX_AUTOCLOSE
# 508 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 509 "data/maps/AzaleaTown_Gym/scripts.pory"

# 510 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Josh::
# 511 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH AzaleaTown_Gym_Text_BugCatcherJoshSeen, AzaleaTown_Gym_Text_BugCatcherJoshBeaten
# 512 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_BugCatcherJoshAfter, MSGBOX_AUTOCLOSE
# 513 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 514 "data/maps/AzaleaTown_Gym/scripts.pory"

# 515 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Benny::
# 516 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BENNY AzaleaTown_Gym_Text_BugCatcherBennySeen, AzaleaTown_Gym_Text_BugCatcherBennyBeaten
# 517 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_BugCatcherBennyAfter, MSGBOX_AUTOCLOSE
# 518 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 519 "data/maps/AzaleaTown_Gym/scripts.pory"

# 520 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Amy::
# 521 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_TwinsAmyMay1Seen, AzaleaTown_Gym_Text_TwinsAmyMay1Beaten, Route104_Text_GinaNotEnoughMons
# 522 "data/maps/AzaleaTown_Gym/scripts.pory"
	special GetPlayerBigGuyGirlString
# 523 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_TwinsAmyMay1After, MSGBOX_DEFAULT
# 524 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 525 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 526 "data/maps/AzaleaTown_Gym/scripts.pory"
	
# 527 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_May::
# 528 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_TwinsAmyMay2Seen, AzaleaTown_Gym_Text_TwinsAmyMay2Beaten, Route104_Text_GinaNotEnoughMons
# 529 "data/maps/AzaleaTown_Gym/scripts.pory"
	special GetPlayerBigGuyGirlString
# 530 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_TwinsAmyMay2After, MSGBOX_DEFAULT
# 531 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 532 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 533 "data/maps/AzaleaTown_Gym/scripts.pory"

# 534 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Bugsy::
# 535 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 536 "data/maps/AzaleaTown_Gym/scripts.pory"
	faceplayer
# 537 "data/maps/AzaleaTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, AzaleaTown_Gym_EventScript_Bugsy_Defeated
# 538 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_BugsyIntro, MSGBOX_DEFAULT
# 539 "data/maps/AzaleaTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BUGSY_1, AzaleaTown_Gym_Text_BugsyBeaten
# 540 "data/maps/AzaleaTown_Gym/scripts.pory"
	message AzaleaTown_Gym_Text_ReceivedHiveBadge
# 541 "data/maps/AzaleaTown_Gym/scripts.pory"
	waitmessage
# 542 "data/maps/AzaleaTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 543 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_HiveBadgeSpeech, MSGBOX_DEFAULT
# 544 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 545 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_AZALEA_TOWN_GYM
# 546 "data/maps/AzaleaTown_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 547 "data/maps/AzaleaTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 548 "data/maps/AzaleaTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 549 "data/maps/AzaleaTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 550 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_FuryCutterSpeech, MSGBOX_DEFAULT
# 551 "data/maps/AzaleaTown_Gym/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 5
# 552 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 553 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
# 554 "data/maps/AzaleaTown_Gym/scripts.pory"
	setflag FLAG_GET_HEADBUTT
# 555 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
# 556 "data/maps/AzaleaTown_Gym/scripts.pory"
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
# 557 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 558 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 559 "data/maps/AzaleaTown_Gym/scripts.pory"

# 560 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Bugsy_Defeated::
# 561 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_BugsyAdvice, MSGBOX_DEFAULT
# 562 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 563 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 564 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 565 "data/maps/AzaleaTown_Gym/scripts.pory"

# 566 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Ariados_Down:
# 567 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 568 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 569 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 570 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 571 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 572 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 573 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 574 "data/maps/AzaleaTown_Gym/scripts.pory"

# 575 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Ariados_Up:
# 576 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 577 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 578 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 579 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 580 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 581 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 582 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 583 "data/maps/AzaleaTown_Gym/scripts.pory"

# 584 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Ariados_Right:
# 585 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_facing_direction
# 586 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 587 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 588 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 589 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 590 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 591 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 592 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 593 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 594 "data/maps/AzaleaTown_Gym/scripts.pory"

# 595 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Ariados_Left:
# 596 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_facing_direction
# 597 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 598 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 599 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 600 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 601 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 602 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 603 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 604 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 605 "data/maps/AzaleaTown_Gym/scripts.pory"

# 606 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Player_Down:
# 607 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_anim
# 608 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 609 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 610 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 611 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 612 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 613 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_down
# 614 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_anim
# 615 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 616 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 617 "data/maps/AzaleaTown_Gym/scripts.pory"

# 618 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Player_Up:
# 619 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_anim
# 620 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 621 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 622 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 623 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 624 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 625 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_up
# 626 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_anim
# 627 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 628 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 629 "data/maps/AzaleaTown_Gym/scripts.pory"

# 630 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Player_Right:
# 631 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_facing_direction
# 632 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_anim
# 633 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 634 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 635 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 636 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 637 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 638 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_right
# 639 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_anim
# 640 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 641 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 642 "data/maps/AzaleaTown_Gym/scripts.pory"

# 643 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Movement_Player_Left:
# 644 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_facing_direction
# 645 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock_anim
# 646 "data/maps/AzaleaTown_Gym/scripts.pory"
	delay_8
# 647 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 648 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 649 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 650 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 651 "data/maps/AzaleaTown_Gym/scripts.pory"
	walk_fast_left
# 652 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_anim
# 653 "data/maps/AzaleaTown_Gym/scripts.pory"
	unlock_facing_direction
# 654 "data/maps/AzaleaTown_Gym/scripts.pory"
	step_end
# 655 "data/maps/AzaleaTown_Gym/scripts.pory"

# 656 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Statue::
# 657 "data/maps/AzaleaTown_Gym/scripts.pory"
	lock
# 658 "data/maps/AzaleaTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, AzaleaTown_Gym_EventScript_Statue2
# 659 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 660 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 661 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 662 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 663 "data/maps/AzaleaTown_Gym/scripts.pory"

# 664 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_EventScript_Statue2::
# 665 "data/maps/AzaleaTown_Gym/scripts.pory"
	msgbox AzaleaTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 666 "data/maps/AzaleaTown_Gym/scripts.pory"
	closemessage
# 667 "data/maps/AzaleaTown_Gym/scripts.pory"
	release
# 668 "data/maps/AzaleaTown_Gym/scripts.pory"
	end
# 669 "data/maps/AzaleaTown_Gym/scripts.pory"

# 670 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_GymStatue:
# 671 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AZALEA POKéMON GYM$"
# 672 "data/maps/AzaleaTown_Gym/scripts.pory"

# 673 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_GymStatueCertified:
# 674 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AZALEA TOWN POKéMON GYM\p"
# 675 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "BUGSY'S CERTIFIED TRAINERS:\n"
# 676 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 677 "data/maps/AzaleaTown_Gym/scripts.pory"

# 678 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugsyIntro:
# 679 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I'm BUGSY!\p"
# 680 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I never lose when it comes\n"
# 681 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "to bug POKéMON.\p"
# 682 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "My research is going to make me the\n"
# 683 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "authority on bug POKéMON!\p"
# 684 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Let me demonstrate all I've\n"
# 685 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "learned from my studies.$"
# 686 "data/maps/AzaleaTown_Gym/scripts.pory"

# 687 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugsyBeaten:
# 688 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Whoa, amazing! You're an\n"
# 689 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "expert on POKéMON!\p"
# 690 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "My research isn't complete\n"
# 691 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "yet.\p"
# 692 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "OK, you win. Take this\n"
# 693 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "BADGE.$"
# 694 "data/maps/AzaleaTown_Gym/scripts.pory"

# 695 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_ReceivedHiveBadge:
# 696 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "{PLAYER} received HIVEBADGE.$"
# 697 "data/maps/AzaleaTown_Gym/scripts.pory"

# 698 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_HiveBadgeSpeech:
# 699 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Do you know the benefits\n"
# 700 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "of HIVEBADGE?\p"
# 701 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "If you have it, POKéMON up\n"
# 702 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "to L30 will obey you,\l"
# 703 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "even traded ones.\p"
# 704 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "POKéMON that know CUT will be able\n"
# 705 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "to use it outside of battle too.\p"
# 706 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Here, I also want you to\n"
# 707 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "have this.$"
# 708 "data/maps/AzaleaTown_Gym/scripts.pory"

# 709 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_FuryCutterSpeech:
# 710 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "TM09 contains BULLET SEED.\p"
# 711 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "It shoots a torrent of seeds\n"
# 712 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "between 2 and 5 times every turn.\p"
# 713 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "So even though the power is 25, it\n"
# 714 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "is really between 50 and 125 power!\p"
# 715 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Isn't that great?\n"
# 716 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I discovered it!$"
# 717 "data/maps/AzaleaTown_Gym/scripts.pory"

# 718 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugsyAdvice:
# 719 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Bug POKéMON are deep. There are\n"
# 720 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "many mysteries to be explored.\p"
# 721 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Study your favorites thoroughly.$"
# 722 "data/maps/AzaleaTown_Gym/scripts.pory"

# 723 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugsyRematch:
# 724 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Wow, you're the JOHTO CHAMPION now!\p"
# 725 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Your skills are truly impressive!\p"
# 726 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I've been busy with my research.\p"
# 727 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I'm ready to show you my new\n"
# 728 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "findings.\p"
# 729 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Want to have a rematch with me?$"
# 730 "data/maps/AzaleaTown_Gym/scripts.pory"

# 731 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugsyRematchDefeat:
# 732 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Wow, you must be an expert trainer.\n"
# 733 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "My research must not be complete...$"
# 734 "data/maps/AzaleaTown_Gym/scripts.pory"

# 735 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherBennySeen:
# 736 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Bug POKéMON evolve young. So they\n"
# 737 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "get stronger that much faster.$"
# 738 "data/maps/AzaleaTown_Gym/scripts.pory"

# 739 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherBennyBeaten:
# 740 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Just evolving isn't enough!$"
# 741 "data/maps/AzaleaTown_Gym/scripts.pory"

# 742 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherBennyAfter:
# 743 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "POKéMON become stronger\n"
# 744 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "if they evolve. Really!$"
# 745 "data/maps/AzaleaTown_Gym/scripts.pory"

# 746 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherAlSeen:
# 747 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Bug POKéMON are cool and tough!\n"
# 748 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I'll prove it to you!$"
# 749 "data/maps/AzaleaTown_Gym/scripts.pory"

# 750 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherAlBeaten:
# 751 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "You proved how tough you are…$"
# 752 "data/maps/AzaleaTown_Gym/scripts.pory"

# 753 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherAlAfter:
# 754 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "They're so cool, but most girls\n"
# 755 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "don't like bug POKéMON.\p"
# 756 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I don't know why…$"
# 757 "data/maps/AzaleaTown_Gym/scripts.pory"

# 758 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherJoshSeen:
# 759 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "You saved all the SLOWPOKE?\n"
# 760 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Whew, you're mighty!\p"
# 761 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "But my grown-up POKéMON are\n"
# 762 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "pretty tough too!$"
# 763 "data/maps/AzaleaTown_Gym/scripts.pory"

# 764 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherJoshBeaten:
# 765 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Urrgggh!$"
# 766 "data/maps/AzaleaTown_Gym/scripts.pory"

# 767 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_BugCatcherJoshAfter:
# 768 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "I guess I should teach them\n"
# 769 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "better moves…$"
# 770 "data/maps/AzaleaTown_Gym/scripts.pory"

# 771 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay1Seen:
# 772 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AMY: Hi! Are you challenging\n"
# 773 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "the LEADER? No way!$"
# 774 "data/maps/AzaleaTown_Gym/scripts.pory"

# 775 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay1Beaten:
# 776 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AMY & MAY: Oh, double\n"
# 777 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "goodness!$"
# 778 "data/maps/AzaleaTown_Gym/scripts.pory"

# 779 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay1After:
# 780 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AMY: You're really strong!\p"
# 781 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "But BUGSY's even stronger!\n"
# 782 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "His SCYTHER's U-Turn almost\l"
# 783 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "always makes turns the tide!$"
# 784 "data/maps/AzaleaTown_Gym/scripts.pory"

# 785 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay2Seen:
# 786 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "MAY: You want to see the\n"
# 787 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "LEADER? Good luck!\p"
# 788 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "BUGSY is so strong!\n"
# 789 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "His SCYTHER's U-turn always\l"
# 790 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "seems to turn tides!$"
# 791 "data/maps/AzaleaTown_Gym/scripts.pory"

# 792 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay2Beaten:
# 793 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "AMY & MAY: Oh, double\n"
# 794 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "goodness!$"
# 795 "data/maps/AzaleaTown_Gym/scripts.pory"

# 796 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_TwinsAmyMay2After:
# 797 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "MAY: Our bug POKéMON lost!\n"
# 798 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Oh, what a shame.\p"
# 799 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "BUGSY's won't lose though!\p"
# 800 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "His PINECO makes short work\n"
# 801 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "of ROCK-type POKéMON!$"
# 802 "data/maps/AzaleaTown_Gym/scripts.pory"

# 803 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_GymGuide:
# 804 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Yo, challenger!\p"
# 805 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "BUGSY's young, but his knowledge\n"
# 806 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "of bug POKéMON is for real.\p"
# 807 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "It's going to be tough\n"
# 808 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "without my advice.\p"
# 809 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Let's see… BUGSY's bagworm POKéMON\n"
# 810 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "knows a move that covers its\l"
# 811 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "ROCK-type weakness.\p"
# 812 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Oh, and don't forget about those\n"
# 813 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "nasty critical hits! Good luck!$"
# 814 "data/maps/AzaleaTown_Gym/scripts.pory"

# 815 "data/maps/AzaleaTown_Gym/scripts.pory"
AzaleaTown_Gym_Text_GymGuideWin:
# 816 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "Well done! That was a great\n"
# 817 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "clash of talented young trainers.\p"
# 818 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "With people like you, the\n"
# 819 "data/maps/AzaleaTown_Gym/scripts.pory"
	.string "future of POKéMON is bright!$"
