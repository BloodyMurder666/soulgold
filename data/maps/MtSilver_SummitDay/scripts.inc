# 1 "data/maps/MtSilver_SummitDay/scripts.pory"

# 2 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_MapScripts::
# 3 "data/maps/MtSilver_SummitDay/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_SummitDay_OnTransition
# 4 "data/maps/MtSilver_SummitDay/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtSilver_SummitDay_OnFrame
# 5 "data/maps/MtSilver_SummitDay/scripts.pory"
	.byte 0
# 6 "data/maps/MtSilver_SummitDay/scripts.pory"

# 7 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnFrame::
# 8 "data/maps/MtSilver_SummitDay/scripts.pory"
	map_script_2 VAR_TEMP_0, 0 MtSilver_SummitDay_Blizzard
# 9 "data/maps/MtSilver_SummitDay/scripts.pory"
	.2byte 0
# 10 "data/maps/MtSilver_SummitDay/scripts.pory"

# 11 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_Blizzard::
# 12 "data/maps/MtSilver_SummitDay/scripts.pory"
	playse SE_M_BLIZZARD
# 13 "data/maps/MtSilver_SummitDay/scripts.pory"
	setvar VAR_TEMP_0, 1
# 14 "data/maps/MtSilver_SummitDay/scripts.pory"
	end
# 15 "data/maps/MtSilver_SummitDay/scripts.pory"

# 16 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnTransition:
# 17 "data/maps/MtSilver_SummitDay/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 18 "data/maps/MtSilver_SummitDay/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_RIVAL
# 19 "data/maps/MtSilver_SummitDay/scripts.pory"
	goto_if_lt VAR_RIVAL_STATE, 11, MtSilver_SummitDay_OnTransition_SetLayout
# 20 "data/maps/MtSilver_SummitDay/scripts.pory"
	goto_if_set FLAG_DEFEATED_RED, MtSilver_SummitDay_OnTransition_SetLayout
# 21 "data/maps/MtSilver_SummitDay/scripts.pory"
	clearflag FLAG_HIDE_MTSILVER_RIVAL
# 22 "data/maps/MtSilver_SummitDay/scripts.pory"

# 23 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnTransition_SetLayout:
# 24 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
# 25 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
# 26 "data/maps/MtSilver_SummitDay/scripts.pory"
	end
# 27 "data/maps/MtSilver_SummitDay/scripts.pory"

# 28 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_SetNight::
# 29 "data/maps/MtSilver_SummitDay/scripts.pory"
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_NIGHT
# 30 "data/maps/MtSilver_SummitDay/scripts.pory"
	return
# 31 "data/maps/MtSilver_SummitDay/scripts.pory"

# 32 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_SetDay::
# 33 "data/maps/MtSilver_SummitDay/scripts.pory"
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_DAY
# 34 "data/maps/MtSilver_SummitDay/scripts.pory"
	return

MtSilver_SummitDay_EventScript_Rival::
# 38 "data/maps/MtSilver_SummitDay/scripts.pory"
	lock
# 39 "data/maps/MtSilver_SummitDay/scripts.pory"
	faceplayer
# 40 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 41 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_0
# 42 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_1
# 44 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_2
# 46 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_3
# 48 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_4
# 50 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 60
# 51 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_5
# 52 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_6
# 54 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_7
# 55 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_8
# 57 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_9
# 59 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 60 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 61 "data/maps/MtSilver_SummitDay/scripts.pory"
	checkplayergender
# 62 "data/maps/MtSilver_SummitDay/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq MtSilver_SummitDay_EventScript_Rival_2
# 65 "data/maps/MtSilver_SummitDay/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_10
MtSilver_SummitDay_EventScript_Rival_1:
# 67 "data/maps/MtSilver_SummitDay/scripts.pory"
	playse SE_M_BLIZZARD
# 68 "data/maps/MtSilver_SummitDay/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 69 "data/maps/MtSilver_SummitDay/scripts.pory"
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
# 70 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 71 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 30
# 72 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_11
# 74 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_12
# 76 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_13
# 78 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 30
# 79 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_14
# 81 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 82 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 83 "data/maps/MtSilver_SummitDay/scripts.pory"
	applymovement LOCALID_MTSILVER_RIVAL, MtSilver_SummitDay_EventScript_Rival_Movement_0
# 84 "data/maps/MtSilver_SummitDay/scripts.pory"
	waitmovement 0
# 85 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 60
# 86 "data/maps/MtSilver_SummitDay/scripts.pory"
	turnobject LOCALID_MTSILVER_RIVAL, DIR_NORTH
# 87 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 88 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_15
# 90 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_16
# 91 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_17
# 93 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 94 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 95 "data/maps/MtSilver_SummitDay/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 96 "data/maps/MtSilver_SummitDay/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_RIVAL
# 97 "data/maps/MtSilver_SummitDay/scripts.pory"
	removeobject LOCALID_MTSILVER_RIVAL
# 98 "data/maps/MtSilver_SummitDay/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 99 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 180
# 100 "data/maps/MtSilver_SummitDay/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 101 "data/maps/MtSilver_SummitDay/scripts.pory"
	setflag FLAG_DEFEATED_RED
# 102 "data/maps/MtSilver_SummitDay/scripts.pory"
	setvar VAR_RIVAL_STATE, 12
# 103 "data/maps/MtSilver_SummitDay/scripts.pory"
	special GameClear
# 104 "data/maps/MtSilver_SummitDay/scripts.pory"
	waitstate
# 105 "data/maps/MtSilver_SummitDay/scripts.pory"
	releaseall
	end

MtSilver_SummitDay_EventScript_Rival_2:
# 63 "data/maps/MtSilver_SummitDay/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_10
	goto MtSilver_SummitDay_EventScript_Rival_1


# 83 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_Rival_Movement_0:
# 83 "data/maps/MtSilver_SummitDay/scripts.pory"
	walk_in_place_fast_down
	step_end

MtSilver_SummitDay_EventScript_Rival_Text_0:
# 41 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I knew you'd come here.$"

MtSilver_SummitDay_EventScript_Rival_Text_1:
# 42 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I've been up here thinking.\n"
	.string "Not much else to do.$"

MtSilver_SummitDay_EventScript_Rival_Text_2:
# 44 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I kept telling myself --\n"
	.string "one more badge. One more win.$"

MtSilver_SummitDay_EventScript_Rival_Text_3:
# 46 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "And then I'd beat you and\n"
	.string "everything would feel right.$"

MtSilver_SummitDay_EventScript_Rival_Text_4:
# 48 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "But that was never it.\n"
	.string "Was it.$"

MtSilver_SummitDay_EventScript_Rival_Text_5:
# 51 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I miss you.$"

MtSilver_SummitDay_EventScript_Rival_Text_6:
# 52 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I've been right behind you\n"
	.string "this whole journey and I...$"

MtSilver_SummitDay_EventScript_Rival_Text_7:
# 54 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I just miss my friend.$"

MtSilver_SummitDay_EventScript_Rival_Text_8:
# 55 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "One more battle.\n"
	.string "Not to prove anything.$"

MtSilver_SummitDay_EventScript_Rival_Text_9:
# 57 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I just want to battle\n"
	.string "my best friend.$"

MtSilver_SummitDay_EventScript_Rival_Text_10:
# 63 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Ha.$"

MtSilver_SummitDay_EventScript_Rival_Text_11:
# 72 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Okay.\n"
	.string "That's what I needed.$"

MtSilver_SummitDay_EventScript_Rival_Text_12:
# 74 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "When did losing become\n"
	.string "such a huge thing for me?$"

MtSilver_SummitDay_EventScript_Rival_Text_13:
# 76 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "You were never\n"
	.string "keeping score.$"

MtSilver_SummitDay_EventScript_Rival_Text_14:
# 79 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Let's go home.\n"
	.string "I want to show Prof. Elm.$"

MtSilver_SummitDay_EventScript_Rival_Text_15:
# 88 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Next time you go somewhere,\n"
	.string "tell me first.$"

MtSilver_SummitDay_EventScript_Rival_Text_16:
# 90 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I don't care if you're faster.$"

MtSilver_SummitDay_EventScript_Rival_Text_17:
# 91 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I'd rather be behind you\n"
	.string "than alone on a mountain.$"
