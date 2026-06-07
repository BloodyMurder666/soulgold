# 1 "data/maps/BellchimeTrail/scripts.pory"

# 2 "data/maps/BellchimeTrail/scripts.pory"

# 3 "data/maps/BellchimeTrail/scripts.pory"
BellchimeTrail_MapScripts::
# 4 "data/maps/BellchimeTrail/scripts.pory"
	.byte 0
# 5 "data/maps/BellchimeTrail/scripts.pory"

# 6 "data/maps/BellchimeTrail/scripts.pory"

# 7 "data/maps/BellchimeTrail/scripts.pory"
BellchimeTrail_EventScript_Morty::
# 8 "data/maps/BellchimeTrail/scripts.pory"
	lock
# 9 "data/maps/BellchimeTrail/scripts.pory"
	faceplayer
# 10 "data/maps/BellchimeTrail/scripts.pory"
	msgbox BellchimeTrail_Text_Morty, MSGBOX_DEFAULT
# 11 "data/maps/BellchimeTrail/scripts.pory"
	closemessage
# 12 "data/maps/BellchimeTrail/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 13 "data/maps/BellchimeTrail/scripts.pory"
	setflag FLAG_HIDE_BELLCHIME_MORTY
# 14 "data/maps/BellchimeTrail/scripts.pory"
	removeobject LOCALID_BELLCHIME_MORTY
# 15 "data/maps/BellchimeTrail/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 16 "data/maps/BellchimeTrail/scripts.pory"
	clearflag FLAG_HIDE_DOJO_MORTY
# 17 "data/maps/BellchimeTrail/scripts.pory"
	release
# 18 "data/maps/BellchimeTrail/scripts.pory"
	end
# 19 "data/maps/BellchimeTrail/scripts.pory"

# 20 "data/maps/BellchimeTrail/scripts.pory"
BellchimeTrail_Text_Morty:
# 21 "data/maps/BellchimeTrail/scripts.pory"
	.string "Morty: The legendary Pokémon\n"
# 22 "data/maps/BellchimeTrail/scripts.pory"
	.string "did not choose me...\p"
# 23 "data/maps/BellchimeTrail/scripts.pory"
	.string "But that does not mean that I\n"
# 24 "data/maps/BellchimeTrail/scripts.pory"
	.string "have lost out on my future.\p"
# 25 "data/maps/BellchimeTrail/scripts.pory"
	.string "I will continue my training until I\n"
# 26 "data/maps/BellchimeTrail/scripts.pory"
	.string "I discover a new future for me.\p"
# 27 "data/maps/BellchimeTrail/scripts.pory"
	.string "If you seek another battle, find\n"
# 28 "data/maps/BellchimeTrail/scripts.pory"
	.string "me at the Fighting Dojo.$"
# 29 "data/maps/BellchimeTrail/scripts.pory"

# 30 "data/maps/BellchimeTrail/scripts.pory"
EcruteakBellchimeTrail_EventScript_DoorTrigger::
# 31 "data/maps/BellchimeTrail/scripts.pory"
	lock
# 32 "data/maps/BellchimeTrail/scripts.pory"
	opendoor 28, 12
# 33 "data/maps/BellchimeTrail/scripts.pory"
	waitdooranim
# 34 "data/maps/BellchimeTrail/scripts.pory"
	addobject OBJ_EVENT_ID_CAMERA
# 35 "data/maps/BellchimeTrail/scripts.pory"
	removeobject OBJ_EVENT_ID_PLAYER
# 36 "data/maps/BellchimeTrail/scripts.pory"
	closedoor 28, 12
# 37 "data/maps/BellchimeTrail/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakBellchimeTrail_Movement_CameraPanUp
# 38 "data/maps/BellchimeTrail/scripts.pory"
	waitmovement 0
# 39 "data/maps/BellchimeTrail/scripts.pory"
	warp MAP_TIN_TOWER_1F, 1
# 40 "data/maps/BellchimeTrail/scripts.pory"
	release
# 41 "data/maps/BellchimeTrail/scripts.pory"
	end
# 42 "data/maps/BellchimeTrail/scripts.pory"

# 43 "data/maps/BellchimeTrail/scripts.pory"
EcruteakBellchimeTrail_Movement_CameraPanUp::
# 44 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 45 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 46 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 47 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 48 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 49 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 50 "data/maps/BellchimeTrail/scripts.pory"
	slide_up
# 51 "data/maps/BellchimeTrail/scripts.pory"
	step_end

BellchimeTrail_MortyRematch::
# 55 "data/maps/BellchimeTrail/scripts.pory"
	lock
# 56 "data/maps/BellchimeTrail/scripts.pory"
	faceplayer
# 57 "data/maps/BellchimeTrail/scripts.pory"
	trainerbattle_no_intro TRAINER_MORTY_2, BellchimeTrail_MortyRematch_Text_0
# 58 "data/maps/BellchimeTrail/scripts.pory"
	setflag FLAG_HIDE_BELLCHIME_MORTY
# 59 "data/maps/BellchimeTrail/scripts.pory"
	release
	end


BellchimeTrail_MortyRematch_Text_0:
# 57 "data/maps/BellchimeTrail/scripts.pory"
	.string "Good$"
