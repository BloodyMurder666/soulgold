# 1 "data/maps/IcePath_1F/scripts.pory"

# 2 "data/maps/IcePath_1F/scripts.pory"
.set LOCALID_ICEPATH1_KIMONO, 9
# 3 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_MapScripts::
# 4 "data/maps/IcePath_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_1F_OnTransition
# 5 "data/maps/IcePath_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/IcePath_1F/scripts.pory"
	.byte 0
# 7 "data/maps/IcePath_1F/scripts.pory"

# 8 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_OnTransition: 
# 9 "data/maps/IcePath_1F/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/IcePath_1F/scripts.pory"
	goto_if_ne VAR_RIVAL_STATE, 9, IcePath_1F_OnTransition_SetTime
# 11 "data/maps/IcePath_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_MAHOGANY_TOWN_GYM, IcePath_1F_OnTransition_SetTime
# 12 "data/maps/IcePath_1F/scripts.pory"

# 13 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_OnTransition_SetTime:
# 14 "data/maps/IcePath_1F/scripts.pory"
	callnative SetTimeBasedEncounters
# 15 "data/maps/IcePath_1F/scripts.pory"
	end
# 16 "data/maps/IcePath_1F/scripts.pory"

# 17 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirl::
# 18 "data/maps/IcePath_1F/scripts.pory"
	lock
# 19 "data/maps/IcePath_1F/scripts.pory"
	playbgm MUS_HG_KIMONO_GIRL, TRUE
# 20 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_SOUTH, IcePath_1F_EventScript_KimonoGirlPushPrompt
# 21 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Stuck1, MSGBOX_DEFAULT
# 22 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 23 "data/maps/IcePath_1F/scripts.pory"
	fadedefaultbgm
# 24 "data/maps/IcePath_1F/scripts.pory"
	release
# 25 "data/maps/IcePath_1F/scripts.pory"
	end
# 26 "data/maps/IcePath_1F/scripts.pory"

# 27 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Trigger_KimonoGirl::
# 28 "data/maps/IcePath_1F/scripts.pory"
	lock
# 29 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Leave, MSGBOX_DEFAULT
# 30 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 31 "data/maps/IcePath_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
# 32 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 33 "data/maps/IcePath_1F/scripts.pory"
	release
# 34 "data/maps/IcePath_1F/scripts.pory"
	end
# 35 "data/maps/IcePath_1F/scripts.pory"

# 36 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlPushPrompt::
# 37 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
# 38 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
# 39 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlPush::
# 40 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
# 41 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 42 "data/maps/IcePath_1F/scripts.pory"
	playse SE_LEDGE
# 43 "data/maps/IcePath_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
# 44 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 45 "data/maps/IcePath_1F/scripts.pory"
	waitse
# 46 "data/maps/IcePath_1F/scripts.pory"
	playse SE_M_ICY_WIND
# 47 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoSlide
# 48 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 49 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Thanks, MSGBOX_DEFAULT
# 50 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 51 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoLeave
# 52 "data/maps/IcePath_1F/scripts.pory"
	waitmovement LOCALID_ICEPATH1_KIMONO
# 53 "data/maps/IcePath_1F/scripts.pory"
	setflag FLAG_HIDE_ICE_PATH_KIMONO
# 54 "data/maps/IcePath_1F/scripts.pory"
	removeobject LOCALID_ICEPATH1_KIMONO
# 55 "data/maps/IcePath_1F/scripts.pory"
	playse SE_EXIT
# 56 "data/maps/IcePath_1F/scripts.pory"
	fadedefaultbgm
# 57 "data/maps/IcePath_1F/scripts.pory"
	setvar VAR_ICE_PATH_STATE, 2
# 58 "data/maps/IcePath_1F/scripts.pory"
	release
# 59 "data/maps/IcePath_1F/scripts.pory"
	end
# 60 "data/maps/IcePath_1F/scripts.pory"

# 61 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlRefused::
# 62 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Cruel, MSGBOX_YESNO
# 63 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_KimonoGirlPush
# 64 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
# 65 "data/maps/IcePath_1F/scripts.pory"

# 66 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_PlayerJump:
# 67 "data/maps/IcePath_1F/scripts.pory"
	jump_in_place_down
# 68 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 69 "data/maps/IcePath_1F/scripts.pory"

# 70 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_KimonoSlide:
# 71 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 72 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 73 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 74 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 75 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_down
# 76 "data/maps/IcePath_1F/scripts.pory"
	face_up
# 77 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_up
# 78 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_up
# 79 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 80 "data/maps/IcePath_1F/scripts.pory"

# 81 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_KimonoLeave:
# 82 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 83 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 84 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 85 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 86 "data/maps/IcePath_1F/scripts.pory"

# 87 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Leave:
# 88 "data/maps/IcePath_1F/scripts.pory"
	.string "Kimono Girl: .....................$"
# 89 "data/maps/IcePath_1F/scripts.pory"

# 90 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Stuck1:
# 91 "data/maps/IcePath_1F/scripts.pory"
    .string "Me oh my... Is that you, {PLAYER}?\n"
# 92 "data/maps/IcePath_1F/scripts.pory"
    .string "Fancy meeting you here!\p"
# 93 "data/maps/IcePath_1F/scripts.pory"
    .string "To tell the truth... my sandals are\n"
# 94 "data/maps/IcePath_1F/scripts.pory"
    .string "frozen on the ice, and I am stuck.\p"
# 95 "data/maps/IcePath_1F/scripts.pory"
    .string "In other words, my flip-flops are\n"
# 96 "data/maps/IcePath_1F/scripts.pory"
    .string "quick-frozen to the ground.\p"
# 97 "data/maps/IcePath_1F/scripts.pory"
    .string "Tee hee.\p"
# 98 "data/maps/IcePath_1F/scripts.pory"
    .string "Well, it's no laughing matter.\p"
# 99 "data/maps/IcePath_1F/scripts.pory"
    .string "Would you come around and push\n"
# 100 "data/maps/IcePath_1F/scripts.pory"
    .string "my back?$"
# 101 "data/maps/IcePath_1F/scripts.pory"

# 102 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Stuck2:
# 103 "data/maps/IcePath_1F/scripts.pory"
    .string "Me oh my... Is that you, {PLAYER}?\n"
# 104 "data/maps/IcePath_1F/scripts.pory"
    .string "Fancy meeting you here!\p"
# 105 "data/maps/IcePath_1F/scripts.pory"
    .string "To tell the truth... my sandals are\n"
# 106 "data/maps/IcePath_1F/scripts.pory"
    .string "frozen on the ice, and I am stuck.\p"
# 107 "data/maps/IcePath_1F/scripts.pory"
    .string "In other words, my flip-flops are\n"
# 108 "data/maps/IcePath_1F/scripts.pory"
    .string "quick-frozen with the ground.\p"
# 109 "data/maps/IcePath_1F/scripts.pory"
    .string "Tee hee.\p"
# 110 "data/maps/IcePath_1F/scripts.pory"
    .string "Well, it's no laughing matter.\n"
# 111 "data/maps/IcePath_1F/scripts.pory"
    .string "Would you push my back?$"
# 112 "data/maps/IcePath_1F/scripts.pory"

# 113 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Shove:
# 114 "data/maps/IcePath_1F/scripts.pory"
    .string "....Shove!....$"
# 115 "data/maps/IcePath_1F/scripts.pory"

# 116 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Cruel:
# 117 "data/maps/IcePath_1F/scripts.pory"
    .string "Don't be so cruel.\n"
# 118 "data/maps/IcePath_1F/scripts.pory"
    .string "You will push my back, won't you?$"
# 119 "data/maps/IcePath_1F/scripts.pory"

# 120 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Thanks:
# 121 "data/maps/IcePath_1F/scripts.pory"
    .string "You really are kind.\n"
# 122 "data/maps/IcePath_1F/scripts.pory"
    .string "Thank you so much!$"

IcePath_1F_Rival::
# 126 "data/maps/IcePath_1F/scripts.pory"
	compare VAR_RIVAL_STATE, 9
	goto_if_eq IcePath_1F_Rival_2
IcePath_1F_Rival_1:
	end

IcePath_1F_Rival_2:
# 127 "data/maps/IcePath_1F/scripts.pory"
	lock
# 128 "data/maps/IcePath_1F/scripts.pory"
	playse SE_PIN
# 129 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, Common_Movement_ExclamationMark
# 130 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 131 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_0
# 132 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 133 "data/maps/IcePath_1F/scripts.pory"
	waitse
# 134 "data/maps/IcePath_1F/scripts.pory"
	approachobject LOCALID_PLAYER, LOCALID_ICEPATH_RIVAL, DIR_EAST, DIR_WEST
# 135 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 136 "data/maps/IcePath_1F/scripts.pory"
	delay 30
# 137 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 138 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_0
# 150 "data/maps/IcePath_1F/scripts.pory"
	checkplayergender
# 151 "data/maps/IcePath_1F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq IcePath_1F_Rival_5
# 154 "data/maps/IcePath_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_ICEPATH, IcePath_1F_Rival_Text_1
IcePath_1F_Rival_4:
# 156 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 157 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_2
# 163 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 164 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_1
# 165 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 166 "data/maps/IcePath_1F/scripts.pory"
	delay 30
# 167 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 168 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_3
# 174 "data/maps/IcePath_1F/scripts.pory"
	removefieldmugshot
# 175 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 176 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_2
# 177 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 178 "data/maps/IcePath_1F/scripts.pory"
	setvar VAR_RIVAL_STATE, 10
# 179 "data/maps/IcePath_1F/scripts.pory"
	setflag FLAG_HIDE_ICEPATH_RIVAL
# 180 "data/maps/IcePath_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORYROAD_RIVAL
# 181 "data/maps/IcePath_1F/scripts.pory"
	removeobject LOCALID_ICEPATH_RIVAL
# 182 "data/maps/IcePath_1F/scripts.pory"
	release
	goto IcePath_1F_Rival_1

IcePath_1F_Rival_5:
# 152 "data/maps/IcePath_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_ICEPATH, IcePath_1F_Rival_Text_1
	goto IcePath_1F_Rival_4


# 131 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_0:
# 131 "data/maps/IcePath_1F/scripts.pory"
	face_left
	step_end

# 164 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_1:
# 164 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_left
	step_end

# 176 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_2:
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 176 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
	step_end

IcePath_1F_Rival_Text_0:
# 138 "data/maps/IcePath_1F/scripts.pory"
	.string "So you've made it here too... With all\n"
	.string "those badges in tow...\p"
	.string "I'm not surprised, you just have the\n"
	.string "raw talent for it I suppose.\p"
	.string "However!\n"
	.string "I've been training so hard now!\p"
	.string "There's just no way you can make\n"
	.string "up for that. Let me prove it to you,\l"
	.string "right here, right now, {PLAYER}!$"

IcePath_1F_Rival_Text_1:
# 152 "data/maps/IcePath_1F/scripts.pory"
	.string "How...?$"

IcePath_1F_Rival_Text_2:
# 157 "data/maps/IcePath_1F/scripts.pory"
	.string "I trained every route from\n"
	.string "here to Cianwood. Without any breaks.\p"
	.string "And you just do it without breaking a\n"
	.string "sweat, like it's all a fun little game\l"
	.string "to you.$"

IcePath_1F_Rival_Text_3:
# 168 "data/maps/IcePath_1F/scripts.pory"
	.string "I'm just... So frustrated with my\n"
	.string "progress.\p"
	.string "No matter how much I train...\p"
	.string "I need to keep pushing on.$"
