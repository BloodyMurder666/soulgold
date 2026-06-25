OlivineCity_House4_MapScripts::
	.byte 0


OlivineTutorMoveMaster::
# 4 "data/maps/OlivineCity_House4/scripts.pory"
	lock
# 5 "data/maps/OlivineCity_House4/scripts.pory"
	faceplayer
# 6 "data/maps/OlivineCity_House4/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVES_UNLOCKED, OlivineTutorMoveMaster_2
# 14 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_1
# 21 "data/maps/OlivineCity_House4/scripts.pory"
	showmoneybox 0, 0
# 22 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_2, MSGBOX_YESNO
# 24 "data/maps/OlivineCity_House4/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq OlivineTutorMoveMaster_5
# 58 "data/maps/OlivineCity_House4/scripts.pory"
	hidemoneybox
# 59 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_6
# 60 "data/maps/OlivineCity_House4/scripts.pory"
	release
	end

OlivineTutorMoveMaster_2:
# 7 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_0
# 11 "data/maps/OlivineCity_House4/scripts.pory"
	release
	end

OlivineTutorMoveMaster_4:
# 63 "data/maps/OlivineCity_House4/scripts.pory"
	release
	end

OlivineTutorMoveMaster_5:
# 25 "data/maps/OlivineCity_House4/scripts.pory"
	checkmoney 44444
# 26 "data/maps/OlivineCity_House4/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq OlivineTutorMoveMaster_9
# 33 "data/maps/OlivineCity_House4/scripts.pory"
	removemoney 44444
# 34 "data/maps/OlivineCity_House4/scripts.pory"
	updatemoneybox 0
# 35 "data/maps/OlivineCity_House4/scripts.pory"
	playse SE_SHOP
# 36 "data/maps/OlivineCity_House4/scripts.pory"
	waitse
# 37 "data/maps/OlivineCity_House4/scripts.pory"
	setflag FLAG_TUTOR_MOVES_UNLOCKED
# 38 "data/maps/OlivineCity_House4/scripts.pory"
	special Achievement_CheckAll
# 39 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_4
# 43 "data/maps/OlivineCity_House4/scripts.pory"
	hidemoneybox
# 44 "data/maps/OlivineCity_House4/scripts.pory"
	closemessage
# 45 "data/maps/OlivineCity_House4/scripts.pory"
	fadescreen FADE_TO_BLACK
# 46 "data/maps/OlivineCity_House4/scripts.pory"
	delay 60
# 47 "data/maps/OlivineCity_House4/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 48 "data/maps/OlivineCity_House4/scripts.pory"
	delay 20
# 49 "data/maps/OlivineCity_House4/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 50 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_5
# 52 "data/maps/OlivineCity_House4/scripts.pory"
	waitse
# 53 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_0
	goto OlivineTutorMoveMaster_4

OlivineTutorMoveMaster_9:
# 27 "data/maps/OlivineCity_House4/scripts.pory"
	msgbox OlivineTutorMoveMaster_Text_3
# 29 "data/maps/OlivineCity_House4/scripts.pory"
	hidemoneybox
# 30 "data/maps/OlivineCity_House4/scripts.pory"
	release
	end


OlivineTutorMoveMaster_Text_0:
# 7 "data/maps/OlivineCity_House4/scripts.pory"
	.string "You can teach Tutor Moves by\n"
	.string "pressing Start on the Battle Moves\l"
	.string "page of the Summary Screen and\l"
	.string "switching to the Tutor Moves page.$"

OlivineTutorMoveMaster_Text_1:
# 14 "data/maps/OlivineCity_House4/scripts.pory"
	.string "I'm the Tutor Move Master.\p"
	.string "I know all there is to know about Tutor\n"
	.string "Moves.\p"
	.string "If you wish, I can teach you all that I \n"
	.string "know for a one-time fee of ¥44,444.$"

OlivineTutorMoveMaster_Text_2:
# 22 "data/maps/OlivineCity_House4/scripts.pory"
	.string "What do you say? Do you wish to learn\n"
	.string "everything about Tutor Moves?$"

OlivineTutorMoveMaster_Text_3:
# 27 "data/maps/OlivineCity_House4/scripts.pory"
	.string "It seems you do not have the money\n"
	.string "to learn. Shame.$"

OlivineTutorMoveMaster_Text_4:
# 39 "data/maps/OlivineCity_House4/scripts.pory"
	.string "Thank you for the business!\p"
	.string "Now let me teach you the grand\n"
	.string "secrets of the Tutor Moves.$"

OlivineTutorMoveMaster_Text_5:
# 50 "data/maps/OlivineCity_House4/scripts.pory"
	.string "You can now teach Tutor Moves to\n"
	.string "your Pokémon!$"

OlivineTutorMoveMaster_Text_6:
# 59 "data/maps/OlivineCity_House4/scripts.pory"
	.string "A pity.$"
