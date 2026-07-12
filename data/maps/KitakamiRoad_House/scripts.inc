KitakamiRoad_House_MapScripts::
	.byte 0


KitakamiBorder_VictiniLady::
# 4 "data/maps/KitakamiRoad_House/scripts.pory"
	lock
# 5 "data/maps/KitakamiRoad_House/scripts.pory"
	faceplayer
# 7 "data/maps/KitakamiRoad_House/scripts.pory"
	goto_if_set FLAG_GOT_VICTINI, KitakamiBorder_VictiniLady_2
# 19 "data/maps/KitakamiRoad_House/scripts.pory"
	goto_if_unset FLAG_IS_CHAMPION, KitakamiBorder_VictiniLady_5
# 47 "data/maps/KitakamiRoad_House/scripts.pory"
	goto_if_unset FLAG_STARTED_VICTINI_QUEST, KitakamiBorder_VictiniLady_8
# 85 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_FALKNER_2
	goto_if 1, KitakamiBorder_VictiniLady_16
KitakamiBorder_VictiniLady_13:
# 138 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_11
# 144 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_2:
# 8 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_0
# 15 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_5:
# 20 "data/maps/KitakamiRoad_House/scripts.pory"
	goto_if_unset FLAG_MET_VICTINI_LADY, KitakamiBorder_VictiniLady_11
# 39 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_3
# 43 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_8:
# 48 "data/maps/KitakamiRoad_House/scripts.pory"
	goto_if_unset FLAG_MET_VICTINI_LADY, KitakamiBorder_VictiniLady_31
# 61 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_5
KitakamiBorder_VictiniLady_30:
# 69 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_6
# 80 "data/maps/KitakamiRoad_House/scripts.pory"
	setflag FLAG_STARTED_VICTINI_QUEST
# 81 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_11:
# 21 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_1
# 27 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_2
# 34 "data/maps/KitakamiRoad_House/scripts.pory"
	setflag FLAG_MET_VICTINI_LADY
# 35 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_14:
# 93 "data/maps/KitakamiRoad_House/scripts.pory"
	closemessage
# 94 "data/maps/KitakamiRoad_House/scripts.pory"
	applymovement LOCALID_VICTINI_LADY, Common_Movement_ExclamationMark
# 95 "data/maps/KitakamiRoad_House/scripts.pory"
	waitmovement 0
# 96 "data/maps/KitakamiRoad_House/scripts.pory"
	delay 30
# 97 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_7
# 105 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_8
# 110 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_9
# 118 "data/maps/KitakamiRoad_House/scripts.pory"
	closemessage
# 119 "data/maps/KitakamiRoad_House/scripts.pory"
	delay 30
# 120 "data/maps/KitakamiRoad_House/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VICTINI
# 121 "data/maps/KitakamiRoad_House/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_VICTINI
# 122 "data/maps/KitakamiRoad_House/scripts.pory"
	givemon SPECIES_VICTINI, 50
# 123 "data/maps/KitakamiRoad_House/scripts.pory"
	showgivemonpic 10, 3
# 124 "data/maps/KitakamiRoad_House/scripts.pory"
	call Common_EventScript_GiftMon
# 125 "data/maps/KitakamiRoad_House/scripts.pory"
	hidemonpic
# 126 "data/maps/KitakamiRoad_House/scripts.pory"
	setflag FLAG_GOT_VICTINI
# 127 "data/maps/KitakamiRoad_House/scripts.pory"
	special Achievement_CheckAll
# 128 "data/maps/KitakamiRoad_House/scripts.pory"
	delay 60
# 129 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_10
# 134 "data/maps/KitakamiRoad_House/scripts.pory"
	release
	end

KitakamiBorder_VictiniLady_15:
# 87 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_WHITNEY_2
	goto_if 1, KitakamiBorder_VictiniLady_20
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_16:
# 86 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_BUGSY_2
	goto_if 1, KitakamiBorder_VictiniLady_15
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_19:
# 89 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_CHUCK_2
	goto_if 1, KitakamiBorder_VictiniLady_24
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_20:
# 88 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_MORTY_2
	goto_if 1, KitakamiBorder_VictiniLady_19
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_23:
# 91 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_PRYCE_2
	goto_if 1, KitakamiBorder_VictiniLady_27
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_24:
# 90 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_JASMINE_2
	goto_if 1, KitakamiBorder_VictiniLady_23
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_27:
# 92 "data/maps/KitakamiRoad_House/scripts.pory"
	checktrainerflag TRAINER_CLAIR_2
	goto_if 1, KitakamiBorder_VictiniLady_14
	goto KitakamiBorder_VictiniLady_13

KitakamiBorder_VictiniLady_31:
# 49 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_1
# 55 "data/maps/KitakamiRoad_House/scripts.pory"
	msgbox KitakamiBorder_VictiniLady_Text_4
# 59 "data/maps/KitakamiRoad_House/scripts.pory"
	setflag FLAG_MET_VICTINI_LADY
	goto KitakamiBorder_VictiniLady_30


KitakamiBorder_VictiniLady_Text_0:
# 8 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Victini chose well.\p"
	.string "Keep our Leaders ambitious, won't\n"
	.string "you? \p"
	.string "Retirement gets dreadfully dull \n"
	.string "otherwise.$"

KitakamiBorder_VictiniLady_Text_1:
# 21 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "I once served on Johto's Gym\n"
	.string "Leader Board.\p"
	.string "Don't look so impressed. It was\n"
	.string "mostly budgets, bickering, and\l"
	.string "bruised egos.$"

KitakamiBorder_VictiniLady_Text_2:
# 27 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "These days, I watch promising\n"
	.string "Trainers.\p"
	.string "You look like you are still a bit\n"
	.string "wet behind the ears.\p"
	.string "Still, I'll keep an eye on you.$"

KitakamiBorder_VictiniLady_Text_3:
# 39 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Still finding your footing? Good.\p"
	.string "I'll keep an eye on you. Try to give\n"
	.string "me something worth watching.$"

KitakamiBorder_VictiniLady_Text_4:
# 55 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "A Champion, are you? Good.\p"
	.string "Titles make some Trainers soft.\n"
	.string "Let's see what you're made of.$"

KitakamiBorder_VictiniLady_Text_5:
# 61 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "So, our promising Trainer is\n"
	.string "a Champion now.\p"
	.string "Not bad. \p"
	.string "Do stop looking so pleased though.\n"
	.string "Titles breed complacency.$"

KitakamiBorder_VictiniLady_Text_6:
# 69 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "I may be retired, but I still\n"
	.string "cultivate talent.\p"
	.string "Help me test whether the current Gym \n"
	.string "Leaders are still fit for their jobs.\p"
	.string "Beat all eight Leaders at their full\n"
	.string "strength. \p"
	.string "Make them grow and nurture your\n"
	.string "own potential further.$"

KitakamiBorder_VictiniLady_Text_7:
# 97 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Well, well. All eight, beaten at\n"
	.string "their best.\p"
	.string "You didn't merely collect victories.\p"
	.string "You gave every one of them a reason\n"
	.string "to keep striving for even greater\l"
	.string "heights.$"

KitakamiBorder_VictiniLady_Text_8:
# 105 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "I hope they learned as much from\n"
	.string "those battles as you did.\p"
	.string "If not, I'll send them a very\n"
	.string "pointed memo.$"

KitakamiBorder_VictiniLady_Text_9:
# 110 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Talent like yours deserves a proper\n"
	.string "investment.\p"
	.string "Take this Victini. \p"
	.string "It seems rather fond of you now, \n"
	.string "having watched you grow stronger \l"
	.string "through every victory.$"

KitakamiBorder_VictiniLady_Text_10:
# 129 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Don't look so stunned. I said I\n"
	.string "nurture the region's elite.\p"
	.string "Now off you go. I'm quite busy\n"
	.string "despite being retired.$"

KitakamiBorder_VictiniLady_Text_11:
# 138 "data/maps/KitakamiRoad_House/scripts.pory"
	.string "Back already? Unless all eight Leaders\n"
	.string "have shown you their full strength,\l"
	.string "you're wasting both our time.\p"
	.string "Go on. Inspire some hope in\n"
	.string "this old lady.$"
