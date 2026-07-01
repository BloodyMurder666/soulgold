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
	savebgm MUS_DUMMY
# 24 "data/maps/IcePath_1F/scripts.pory"
	fadedefaultbgm
# 25 "data/maps/IcePath_1F/scripts.pory"
	release
# 26 "data/maps/IcePath_1F/scripts.pory"
	end
# 27 "data/maps/IcePath_1F/scripts.pory"

# 28 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Trigger_KimonoGirl::
# 29 "data/maps/IcePath_1F/scripts.pory"
	lock
# 30 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Leave, MSGBOX_DEFAULT
# 31 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 32 "data/maps/IcePath_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
# 33 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/IcePath_1F/scripts.pory"
	release
# 35 "data/maps/IcePath_1F/scripts.pory"
	end
# 36 "data/maps/IcePath_1F/scripts.pory"

# 37 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlPushPrompt::
# 38 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
# 39 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
# 40 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlPush::
# 41 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
# 42 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 43 "data/maps/IcePath_1F/scripts.pory"
	playse SE_LEDGE
# 44 "data/maps/IcePath_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
# 45 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 46 "data/maps/IcePath_1F/scripts.pory"
	waitse
# 47 "data/maps/IcePath_1F/scripts.pory"
	playse SE_M_ICY_WIND
# 48 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoSlide
# 49 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 50 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshot MUGSHOT_KIMONO_GIRL
# 51 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Thanks, MSGBOX_DEFAULT
# 52 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 53 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoLeave
# 54 "data/maps/IcePath_1F/scripts.pory"
	waitmovement LOCALID_ICEPATH1_KIMONO
# 55 "data/maps/IcePath_1F/scripts.pory"
	setflag FLAG_HIDE_ICE_PATH_KIMONO
# 56 "data/maps/IcePath_1F/scripts.pory"
	removeobject LOCALID_ICEPATH1_KIMONO
# 57 "data/maps/IcePath_1F/scripts.pory"
	playse SE_EXIT
# 58 "data/maps/IcePath_1F/scripts.pory"
	fadedefaultbgm
# 59 "data/maps/IcePath_1F/scripts.pory"
	setvar VAR_ICE_PATH_STATE, 2
# 60 "data/maps/IcePath_1F/scripts.pory"
	release
# 61 "data/maps/IcePath_1F/scripts.pory"
	end
# 62 "data/maps/IcePath_1F/scripts.pory"

# 63 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_EventScript_KimonoGirlRefused::
# 64 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Text_Cruel, MSGBOX_YESNO
# 65 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_KimonoGirlPush
# 66 "data/maps/IcePath_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
# 67 "data/maps/IcePath_1F/scripts.pory"

# 68 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_PlayerJump:
# 69 "data/maps/IcePath_1F/scripts.pory"
	jump_in_place_down
# 70 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 71 "data/maps/IcePath_1F/scripts.pory"

# 72 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_KimonoSlide:
# 73 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 74 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 75 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 76 "data/maps/IcePath_1F/scripts.pory"
	slide_down
# 77 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_down
# 78 "data/maps/IcePath_1F/scripts.pory"
	face_up
# 79 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_up
# 80 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_fast_up
# 81 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 82 "data/maps/IcePath_1F/scripts.pory"

# 83 "data/maps/IcePath_1F/scripts.pory"
IcePath_Movement_KimonoLeave:
# 84 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 85 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 86 "data/maps/IcePath_1F/scripts.pory"
	walk_down
# 87 "data/maps/IcePath_1F/scripts.pory"
	step_end
# 88 "data/maps/IcePath_1F/scripts.pory"

# 89 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Leave:
# 90 "data/maps/IcePath_1F/scripts.pory"
	.string "Kimono Girl: .....................$"
# 91 "data/maps/IcePath_1F/scripts.pory"

# 92 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Stuck1:
# 93 "data/maps/IcePath_1F/scripts.pory"
    .string "Me oh my... Is that you, {PLAYER}?\n"
# 94 "data/maps/IcePath_1F/scripts.pory"
    .string "Fancy meeting you here!\p"
# 95 "data/maps/IcePath_1F/scripts.pory"
    .string "To tell the truth... my sandals are\n"
# 96 "data/maps/IcePath_1F/scripts.pory"
    .string "frozen on the ice, and I am stuck.\p"
# 97 "data/maps/IcePath_1F/scripts.pory"
    .string "In other words, my flip-flops are\n"
# 98 "data/maps/IcePath_1F/scripts.pory"
    .string "quick-frozen to the ground.\p"
# 99 "data/maps/IcePath_1F/scripts.pory"
    .string "Tee hee.\p"
# 100 "data/maps/IcePath_1F/scripts.pory"
    .string "Well, it's no laughing matter.\p"
# 101 "data/maps/IcePath_1F/scripts.pory"
    .string "Would you come around and push\n"
# 102 "data/maps/IcePath_1F/scripts.pory"
    .string "my back?$"
# 103 "data/maps/IcePath_1F/scripts.pory"

# 104 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Stuck2:
# 105 "data/maps/IcePath_1F/scripts.pory"
    .string "Me oh my... Is that you, {PLAYER}?\n"
# 106 "data/maps/IcePath_1F/scripts.pory"
    .string "Fancy meeting you here!\p"
# 107 "data/maps/IcePath_1F/scripts.pory"
    .string "To tell the truth... my sandals are\n"
# 108 "data/maps/IcePath_1F/scripts.pory"
    .string "frozen on the ice, and I am stuck.\p"
# 109 "data/maps/IcePath_1F/scripts.pory"
    .string "In other words, my flip-flops are\n"
# 110 "data/maps/IcePath_1F/scripts.pory"
    .string "quick-frozen with the ground.\p"
# 111 "data/maps/IcePath_1F/scripts.pory"
    .string "Tee hee.\p"
# 112 "data/maps/IcePath_1F/scripts.pory"
    .string "Well, it's no laughing matter.\n"
# 113 "data/maps/IcePath_1F/scripts.pory"
    .string "Would you push my back?$"
# 114 "data/maps/IcePath_1F/scripts.pory"

# 115 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Shove:
# 116 "data/maps/IcePath_1F/scripts.pory"
    .string "....Shove!....$"
# 117 "data/maps/IcePath_1F/scripts.pory"

# 118 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Cruel:
# 119 "data/maps/IcePath_1F/scripts.pory"
    .string "Don't be so cruel.\n"
# 120 "data/maps/IcePath_1F/scripts.pory"
    .string "You will push my back, won't you?$"
# 121 "data/maps/IcePath_1F/scripts.pory"

# 122 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Text_Thanks:
# 123 "data/maps/IcePath_1F/scripts.pory"
    .string "You really are kind.\n"
# 124 "data/maps/IcePath_1F/scripts.pory"
    .string "Thank you so much!$"

IcePath_1F_Rival::
# 128 "data/maps/IcePath_1F/scripts.pory"
	compare VAR_RIVAL_STATE, 9
	goto_if_eq IcePath_1F_Rival_2
IcePath_1F_Rival_1:
	end

IcePath_1F_Rival_2:
# 129 "data/maps/IcePath_1F/scripts.pory"
	lock
# 130 "data/maps/IcePath_1F/scripts.pory"
	playse SE_PIN
# 131 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, Common_Movement_ExclamationMark
# 132 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 133 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_0
# 134 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 135 "data/maps/IcePath_1F/scripts.pory"
	waitse
# 136 "data/maps/IcePath_1F/scripts.pory"
	approachobject LOCALID_PLAYER, LOCALID_ICEPATH_RIVAL, DIR_EAST, DIR_WEST
# 137 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 138 "data/maps/IcePath_1F/scripts.pory"
	delay 30
# 139 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 140 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_0
# 152 "data/maps/IcePath_1F/scripts.pory"
	checkplayergender
# 153 "data/maps/IcePath_1F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq IcePath_1F_Rival_5
# 156 "data/maps/IcePath_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_ICEPATH, IcePath_1F_Rival_Text_1
IcePath_1F_Rival_4:
# 158 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 159 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_2
# 165 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 166 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_1
# 167 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 168 "data/maps/IcePath_1F/scripts.pory"
	delay 30
# 169 "data/maps/IcePath_1F/scripts.pory"
	createfieldmugshotrival
# 170 "data/maps/IcePath_1F/scripts.pory"
	msgbox IcePath_1F_Rival_Text_3
# 176 "data/maps/IcePath_1F/scripts.pory"
	removefieldmugshot
# 177 "data/maps/IcePath_1F/scripts.pory"
	closemessage
# 178 "data/maps/IcePath_1F/scripts.pory"
	applymovement LOCALID_ICEPATH_RIVAL, IcePath_1F_Rival_Movement_2
# 179 "data/maps/IcePath_1F/scripts.pory"
	waitmovement 0
# 180 "data/maps/IcePath_1F/scripts.pory"
	setvar VAR_RIVAL_STATE, 10
# 181 "data/maps/IcePath_1F/scripts.pory"
	setflag FLAG_HIDE_ICEPATH_RIVAL
# 182 "data/maps/IcePath_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORYROAD_RIVAL
# 183 "data/maps/IcePath_1F/scripts.pory"
	removeobject LOCALID_ICEPATH_RIVAL
# 184 "data/maps/IcePath_1F/scripts.pory"
	release
	goto IcePath_1F_Rival_1

IcePath_1F_Rival_5:
# 154 "data/maps/IcePath_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_ICEPATH, IcePath_1F_Rival_Text_1
	goto IcePath_1F_Rival_4


# 133 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_0:
# 133 "data/maps/IcePath_1F/scripts.pory"
	face_left
	step_end

# 166 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_1:
# 166 "data/maps/IcePath_1F/scripts.pory"
	walk_in_place_left
	step_end

# 178 "data/maps/IcePath_1F/scripts.pory"
IcePath_1F_Rival_Movement_2:
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
# 178 "data/maps/IcePath_1F/scripts.pory"
	walk_fast_right
	step_end

IcePath_1F_Rival_Text_0:
# 140 "data/maps/IcePath_1F/scripts.pory"
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
# 154 "data/maps/IcePath_1F/scripts.pory"
	.string "How...?$"

IcePath_1F_Rival_Text_2:
# 159 "data/maps/IcePath_1F/scripts.pory"
	.string "I trained every route from\n"
	.string "here to Cianwood. Without any breaks.\p"
	.string "And you just do it without breaking a\n"
	.string "sweat, like it's all a fun little game\l"
	.string "to you.$"

IcePath_1F_Rival_Text_3:
# 170 "data/maps/IcePath_1F/scripts.pory"
	.string "I'm just... So frustrated with my\n"
	.string "progress.\p"
	.string "No matter how much I train...\p"
	.string "I need to keep pushing on.$"
