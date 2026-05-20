BattleArcade_BattleRoom_MapScripts::
# 20 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 24 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 22 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 26 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 27 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleArcade_Challenge_EventScript_BeginChallenge
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 33 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 34 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_0
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_1
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_2
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MCFaceCrowd_Movement_0
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_AddSetOpponent
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	frontier_isbrain
# 61 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentIntro
	return

BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1:
# 63 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponent::
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 74 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


BattleArcade_BattleRoom_EventScript_OpponentIntro::
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_OpponentIntro_Movement_0
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition_Movement_0
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 103 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_SPECIAL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_6
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 109 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 102 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_6:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_3
BattleArcade_BattleRoom_EventScript_MoveMCBack_1:
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCBack_2:
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCBack_Movement_0
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1

BattleArcade_BattleRoom_EventScript_MoveMCBack_3:
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_2
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1


BattleArcade_BattleRoom_EventScript_MoveMCToTrainer::
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_1
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1:
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2:
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_0
	goto BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1


BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer::
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_1
	return

BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1:
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_0
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_0
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1
# 153 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 154 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_0
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_1
# 164 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 165 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 166 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 172 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	approachobject 1, OBJ_EVENT_ID_PLAYER, DIR_WEST, DIR_SOUTH, 2
# 175 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_0
# 177 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_EventScript_AttendantLeave_Movement_0
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 192 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_BrainEntranceMovement_Movement_0
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_0
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 204 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_1
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_2
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_3
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	moveobjecttocoords 2, 10, 10, DIR_WEST
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_4
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield::
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield_Movement_0
	return


# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_0:
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_1:
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_2:
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MCFaceCrowd_Movement_0:
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_OpponentIntro_Movement_0:
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition_Movement_0:
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCBack_Movement_0:
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_0:
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_1:
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_0:
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_1:
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_0:
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1:
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_0:
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_1:
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_0:
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_AttendantLeave_Movement_0:
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_right
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_right
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntranceMovement_Movement_0:
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_0:
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_1:
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_2:
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_3:
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_4:
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield_Movement_0:
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end
