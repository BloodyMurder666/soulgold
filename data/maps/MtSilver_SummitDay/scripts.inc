# 1 "data/maps/MtSilver_SummitDay/scripts.pory"

# 2 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_MapScripts::
# 3 "data/maps/MtSilver_SummitDay/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_SummitDay_OnTransition
# 4 "data/maps/MtSilver_SummitDay/scripts.pory"
	.byte 0
# 5 "data/maps/MtSilver_SummitDay/scripts.pory"

# 6 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnFrame::
# 7 "data/maps/MtSilver_SummitDay/scripts.pory"
	map_script_2 VAR_TEMP_0, 0 MtSilver_SummitDay_Blizzard
# 8 "data/maps/MtSilver_SummitDay/scripts.pory"
	.2byte 0
# 9 "data/maps/MtSilver_SummitDay/scripts.pory"

# 10 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_Blizzard::
# 11 "data/maps/MtSilver_SummitDay/scripts.pory"
	playse SE_M_BLIZZARD
# 12 "data/maps/MtSilver_SummitDay/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/MtSilver_SummitDay/scripts.pory"
	end
# 14 "data/maps/MtSilver_SummitDay/scripts.pory"

# 15 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnTransition:
# 16 "data/maps/MtSilver_SummitDay/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 17 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
# 18 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
# 19 "data/maps/MtSilver_SummitDay/scripts.pory"
	end
# 20 "data/maps/MtSilver_SummitDay/scripts.pory"

# 21 "data/maps/MtSilver_SummitDay/scripts.pory"

# 22 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_OnTransition_SetLayout:
# 23 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_set FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetNight
# 24 "data/maps/MtSilver_SummitDay/scripts.pory"
	call_if_unset FLAG_DAY_POKEMON, MtSilver_SummitDay_EventScript_SetDay
# 25 "data/maps/MtSilver_SummitDay/scripts.pory"
	end
# 26 "data/maps/MtSilver_SummitDay/scripts.pory"

# 27 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_SetNight::
# 28 "data/maps/MtSilver_SummitDay/scripts.pory"
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_NIGHT
# 29 "data/maps/MtSilver_SummitDay/scripts.pory"
	return
# 30 "data/maps/MtSilver_SummitDay/scripts.pory"

# 31 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_SetDay::
# 32 "data/maps/MtSilver_SummitDay/scripts.pory"
	setmaplayoutindex LAYOUT_MT_SILVER_SUMMIT_DAY
# 33 "data/maps/MtSilver_SummitDay/scripts.pory"
	return

MtSilver_SummitDay_EventScript_Rival::
# 37 "data/maps/MtSilver_SummitDay/scripts.pory"
	lock
# 38 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 39 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_0
# 40 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 30
# 41 "data/maps/MtSilver_SummitDay/scripts.pory"
	faceplayer
# 42 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_1
# 56 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 57 "data/maps/MtSilver_SummitDay/scripts.pory"
	applymovement LOCALID_MTSILVER_RIVAL, MtSilver_SummitDay_EventScript_Rival_Movement_0
# 58 "data/maps/MtSilver_SummitDay/scripts.pory"
	waitmovement 0
# 59 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 30
# 60 "data/maps/MtSilver_SummitDay/scripts.pory"
	faceplayer
# 61 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 62 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_2
# 74 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 75 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 76 "data/maps/MtSilver_SummitDay/scripts.pory"
	checkplayergender
# 77 "data/maps/MtSilver_SummitDay/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq MtSilver_SummitDay_EventScript_Rival_2
# 80 "data/maps/MtSilver_SummitDay/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_GOLD_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_3
MtSilver_SummitDay_EventScript_Rival_1:
# 82 "data/maps/MtSilver_SummitDay/scripts.pory"
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
# 83 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 84 "data/maps/MtSilver_SummitDay/scripts.pory"
	delay 30
# 85 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_4
# 87 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_5
# 91 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_6
# 103 "data/maps/MtSilver_SummitDay/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 104 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 105 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_7
# 106 "data/maps/MtSilver_SummitDay/scripts.pory"
	waitfanfare
# 107 "data/maps/MtSilver_SummitDay/scripts.pory"
	giveegg SPECIES_JIRACHI
# 108 "data/maps/MtSilver_SummitDay/scripts.pory"
	createfieldmugshotrival
# 109 "data/maps/MtSilver_SummitDay/scripts.pory"
	msgbox MtSilver_SummitDay_EventScript_Rival_Text_8
# 113 "data/maps/MtSilver_SummitDay/scripts.pory"
	removefieldmugshot
# 114 "data/maps/MtSilver_SummitDay/scripts.pory"
	closemessage
# 115 "data/maps/MtSilver_SummitDay/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 116 "data/maps/MtSilver_SummitDay/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_RIVAL
# 117 "data/maps/MtSilver_SummitDay/scripts.pory"
	removeobject LOCALID_MTSILVER_RIVAL
# 118 "data/maps/MtSilver_SummitDay/scripts.pory"
	setflag FLAG_DEFEATED_MTSILVER_RIVAL
# 119 "data/maps/MtSilver_SummitDay/scripts.pory"
	setvar VAR_RIVAL_STATE, 12
# 120 "data/maps/MtSilver_SummitDay/scripts.pory"
	clearflag FLAG_HIDE_NEWBARK_RIVAL
# 121 "data/maps/MtSilver_SummitDay/scripts.pory"
	special GameClear
# 122 "data/maps/MtSilver_SummitDay/scripts.pory"
	waitstate
# 123 "data/maps/MtSilver_SummitDay/scripts.pory"
	releaseall
	end

MtSilver_SummitDay_EventScript_Rival_2:
# 78 "data/maps/MtSilver_SummitDay/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CRYSTAL_FINAL, MtSilver_SummitDay_EventScript_Rival_Text_3
	goto MtSilver_SummitDay_EventScript_Rival_1


# 57 "data/maps/MtSilver_SummitDay/scripts.pory"
MtSilver_SummitDay_EventScript_Rival_Movement_0:
# 57 "data/maps/MtSilver_SummitDay/scripts.pory"
	walk_in_place_up
	step_end

MtSilver_SummitDay_EventScript_Rival_Text_0:
# 39 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I knew you'd come here.$"

MtSilver_SummitDay_EventScript_Rival_Text_1:
# 42 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "I've been up here thinking.\n"
	.string "Not much else to do.\p"
	.string "I kept telling myself,\n"
	.string "one more badge. One more win.\p"
	.string "Then I would finally catch up.\p"
	.string "Silly isn't it? In the end I was\n"
	.string "just trying to stand out.\p"
	.string "Assuming everyone had some sort of\n"
	.string "expectation of me to reach these \l"
	.string "heights and become the best.$"

MtSilver_SummitDay_EventScript_Rival_Text_2:
# 62 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "In the end it was just all in my head\n"
	.string "when you get down to it, haha.\p"
	.string "So! I want you, {PLAYER} to give me\n"
	.string "one last battle to knock some sense\l"
	.string "into me!\p"
	.string "Not asking as a bitter rival, \n"
	.string "but as your best friend!\p"
	.string "I got nothing to prove, but let's\n"
	.string "have fun like we used to.$"

MtSilver_SummitDay_EventScript_Rival_Text_3:
# 78 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Hah, nice one.$"

MtSilver_SummitDay_EventScript_Rival_Text_4:
# 85 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Okay.\n"
	.string "That's what I needed.$"

MtSilver_SummitDay_EventScript_Rival_Text_5:
# 87 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "You always do the battling\n"
	.string "with a smile, I felt that too\l"
	.string "in this battle.$"

MtSilver_SummitDay_EventScript_Rival_Text_6:
# 91 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "When I was just standing here alone, I\n"
	.string "was wishing you could arrive.\p"
	.string "then, I saw this egg in the ground\n"
	.string "here. \p"
	.string "I think it appeared in reaction to my\n"
	.string "wish, but you should have it instead.\p"
	.string "After all, you made my wish come true!\p"
	.string "So, thanks {PLAYER}.$"

MtSilver_SummitDay_EventScript_Rival_Text_7:
# 105 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "{PLAYER} received an Egg!$"

MtSilver_SummitDay_EventScript_Rival_Text_8:
# 109 "data/maps/MtSilver_SummitDay/scripts.pory"
	.string "Now c'mon, let's race back home!\p"
	.string "My fingers are freezing from just \n"
	.string "standing around here.$"
