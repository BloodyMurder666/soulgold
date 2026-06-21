# 1 "data/maps/Route37/scripts.pory"

# 2 "data/maps/Route37/scripts.pory"
Route37_MapScripts::
# 3 "data/maps/Route37/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
# 4 "data/maps/Route37/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route37/scripts.pory"
	.byte 0
# 6 "data/maps/Route37/scripts.pory"

# 7 "data/maps/Route37/scripts.pory"
Route37_OnTransition: 
# 8 "data/maps/Route37/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route37/scripts.pory"
	end
# 10 "data/maps/Route37/scripts.pory"

# 11 "data/maps/Route37/scripts.pory"

# 12 "data/maps/Route37/scripts.pory"

# 13 "data/maps/Route37/scripts.pory"
Route37_EventScript_TwinAnn::
# 14 "data/maps/Route37/scripts.pory"
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
# 15 "data/maps/Route37/scripts.pory"
	special GetPlayerBigGuyGirlString
# 16 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
# 17 "data/maps/Route37/scripts.pory"
	release
# 18 "data/maps/Route37/scripts.pory"
	end
# 19 "data/maps/Route37/scripts.pory"
	
# 20 "data/maps/Route37/scripts.pory"
Route37_EventScript_TwinAnne::
# 21 "data/maps/Route37/scripts.pory"
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
# 22 "data/maps/Route37/scripts.pory"
	special GetPlayerBigGuyGirlString
# 23 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
# 24 "data/maps/Route37/scripts.pory"
	release
# 25 "data/maps/Route37/scripts.pory"
	end
# 26 "data/maps/Route37/scripts.pory"

# 27 "data/maps/Route37/scripts.pory"
Route37_EventScript_Greg::
# 28 "data/maps/Route37/scripts.pory"
	trainerbattle_single TRAINER_GREG Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
# 29 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
# 30 "data/maps/Route37/scripts.pory"
	end
# 31 "data/maps/Route37/scripts.pory"

# 32 "data/maps/Route37/scripts.pory"

# 33 "data/maps/Route37/scripts.pory"
Route37_EventScript_Sunny::
# 34 "data/maps/Route37/scripts.pory"
	lock
# 35 "data/maps/Route37/scripts.pory"
	faceplayer
# 36 "data/maps/Route37/scripts.pory"
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
# 37 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
# 38 "data/maps/Route37/scripts.pory"
	closemessage
# 39 "data/maps/Route37/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 40 "data/maps/Route37/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/Route37/scripts.pory"
	case 0, Route37_EventScript_SunnyYes
# 42 "data/maps/Route37/scripts.pory"
	case 1, Route37_EventScript_SunnyNope
# 43 "data/maps/Route37/scripts.pory"
	case 2, Route37_EventScript_SunnyNope
# 44 "data/maps/Route37/scripts.pory"
	case 3, Route37_EventScript_SunnyNope
# 45 "data/maps/Route37/scripts.pory"
	case 4, Route37_EventScript_SunnyNope
# 46 "data/maps/Route37/scripts.pory"
	case 5, Route37_EventScript_SunnyNope
# 47 "data/maps/Route37/scripts.pory"
	case 6, Route37_EventScript_SunnyNope
# 48 "data/maps/Route37/scripts.pory"
	case 7 Route37_EventScript_SunnyCancel
# 49 "data/maps/Route37/scripts.pory"
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
# 50 "data/maps/Route37/scripts.pory"
	closemessage
# 51 "data/maps/Route37/scripts.pory"
	release
# 52 "data/maps/Route37/scripts.pory"
	end
# 53 "data/maps/Route37/scripts.pory"
Route37_EventScript_SunnyYes::
# 54 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
# 55 "data/maps/Route37/scripts.pory"
	giveitem ITEM_MAGNET
# 56 "data/maps/Route37/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 57 "data/maps/Route37/scripts.pory"
	setflag FLAG_GOT_MAGNET
# 58 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
# 59 "data/maps/Route37/scripts.pory"
	closemessage
# 60 "data/maps/Route37/scripts.pory"
	release
# 61 "data/maps/Route37/scripts.pory"
	end
# 62 "data/maps/Route37/scripts.pory"
Route37_EventScript_SunnyNope::
# 63 "data/maps/Route37/scripts.pory"
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
# 64 "data/maps/Route37/scripts.pory"
	closemessage
# 65 "data/maps/Route37/scripts.pory"
	release
# 66 "data/maps/Route37/scripts.pory"
	end
# 67 "data/maps/Route37/scripts.pory"
Route37_EventScript_SunnyCancel::
# 68 "data/maps/Route37/scripts.pory"
	closemessage
# 69 "data/maps/Route37/scripts.pory"
	release
# 70 "data/maps/Route37/scripts.pory"
	end
# 71 "data/maps/Route37/scripts.pory"
Route37_EventScript_SunnyCompleted::
# 72 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
# 73 "data/maps/Route37/scripts.pory"
	closemessage
# 74 "data/maps/Route37/scripts.pory"
	release
# 75 "data/maps/Route37/scripts.pory"
	end
# 76 "data/maps/Route37/scripts.pory"

# 77 "data/maps/Route37/scripts.pory"
Route37_EventScript_Sign::
# 78 "data/maps/Route37/scripts.pory"
	lock
# 79 "data/maps/Route37/scripts.pory"
	msgbox Route37_Text_Sign, MSGBOX_SIGN
# 80 "data/maps/Route37/scripts.pory"
	closemessage
# 81 "data/maps/Route37/scripts.pory"
	release
# 82 "data/maps/Route37/scripts.pory"
	end
# 83 "data/maps/Route37/scripts.pory"

# 84 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne1_Seen:
# 85 "data/maps/Route37/scripts.pory"
	.string "Ann: Anne and I are in this\n"
# 86 "data/maps/Route37/scripts.pory"
	.string "together!$"
# 87 "data/maps/Route37/scripts.pory"

# 88 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne1_Beaten:
# 89 "data/maps/Route37/scripts.pory"
	.string "Ann & Anne: Nnn… A little too\n"
# 90 "data/maps/Route37/scripts.pory"
	.string "strong.$"
# 91 "data/maps/Route37/scripts.pory"

# 92 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne1_After:
# 93 "data/maps/Route37/scripts.pory"
	.string "Ann: I can tell what my sister and\n"
# 94 "data/maps/Route37/scripts.pory"
	.string "my Pokémon are thinking.$"
# 95 "data/maps/Route37/scripts.pory"

# 96 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne2_Seen:
# 97 "data/maps/Route37/scripts.pory"
	.string "Anne: Ann and I are in this\n"
# 98 "data/maps/Route37/scripts.pory"
	.string "together!$"
# 99 "data/maps/Route37/scripts.pory"

# 100 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne2_Beaten:
# 101 "data/maps/Route37/scripts.pory"
	.string "Ann & Anne: Nnn… A little too\n"
# 102 "data/maps/Route37/scripts.pory"
	.string "strong.$"
# 103 "data/maps/Route37/scripts.pory"

# 104 "data/maps/Route37/scripts.pory"
Route37_Text_TwinsAnnAndAnne2_After:
# 105 "data/maps/Route37/scripts.pory"
	.string "Anne: We share the same feelings as\n"
# 106 "data/maps/Route37/scripts.pory"
	.string "our Pokémon.$"
# 107 "data/maps/Route37/scripts.pory"

# 108 "data/maps/Route37/scripts.pory"
Route37_Text_PsychicGreg_Seen:
# 109 "data/maps/Route37/scripts.pory"
	.string "Pokémon can't do a thing if they are\n"
# 110 "data/maps/Route37/scripts.pory"
	.string "asleep.\p"
# 111 "data/maps/Route37/scripts.pory"
	.string "I'll show you how scary that is!$"
# 112 "data/maps/Route37/scripts.pory"

# 113 "data/maps/Route37/scripts.pory"
Route37_Text_PsychicGreg_Beaten:
# 114 "data/maps/Route37/scripts.pory"
	.string "I lost. That's pretty sad…$"
# 115 "data/maps/Route37/scripts.pory"

# 116 "data/maps/Route37/scripts.pory"
Route37_Text_PsychicGreg_After:
# 117 "data/maps/Route37/scripts.pory"
	.string "Putting Pokémon to sleep or paralyz-\n"
# 118 "data/maps/Route37/scripts.pory"
	.string "ing them are good battle techniques.$"
# 119 "data/maps/Route37/scripts.pory"

# 120 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_Meet:
# 121 "data/maps/Route37/scripts.pory"
	.string "Sunny: Hi!\p"
# 122 "data/maps/Route37/scripts.pory"
	.string "I'm Sunny of the Weekday family!\p"
# 123 "data/maps/Route37/scripts.pory"
	.string "If you can guess my favorite day,\n"
# 124 "data/maps/Route37/scripts.pory"
	.string "I'll give you a reward.$"
# 125 "data/maps/Route37/scripts.pory"

# 126 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_GiveGift1:
# 127 "data/maps/Route37/scripts.pory"
	.string "I was told to give you this if I saw\n"
# 128 "data/maps/Route37/scripts.pory"
	.string "you!$"
# 129 "data/maps/Route37/scripts.pory"

# 130 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_GiveGift2:
# 131 "data/maps/Route37/scripts.pory"
	.string "I was told to give you this if I saw\n"
# 132 "data/maps/Route37/scripts.pory"
	.string "you!$"
# 133 "data/maps/Route37/scripts.pory"

# 134 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_GaveGift:
# 135 "data/maps/Route37/scripts.pory"
	.string "Sunny: That thing…\p"
# 136 "data/maps/Route37/scripts.pory"
	.string "Um…\p"
# 137 "data/maps/Route37/scripts.pory"
	.string "… What was it now…\p"
# 138 "data/maps/Route37/scripts.pory"
	.string "…\p"
# 139 "data/maps/Route37/scripts.pory"
	.string "Oh! I remember now!\p"
# 140 "data/maps/Route37/scripts.pory"
	.string "A Pokémon that knows electric\n"
# 141 "data/maps/Route37/scripts.pory"
	.string "moves should hold it.\p"
# 142 "data/maps/Route37/scripts.pory"
	.string "My sis Monica said it powers up\n"
# 143 "data/maps/Route37/scripts.pory"
	.string "electric moves!$"
# 144 "data/maps/Route37/scripts.pory"

# 145 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_Sunday:
# 146 "data/maps/Route37/scripts.pory"
	.string "Sunny: My sisters and brothers are\n"
# 147 "data/maps/Route37/scripts.pory"
	.string "Monica, Tuscany, Wesley, Arthur,\l"
# 148 "data/maps/Route37/scripts.pory"
	.string "Frieda and Santos.\p"
# 149 "data/maps/Route37/scripts.pory"
	.string "They're all older than me!$"
# 150 "data/maps/Route37/scripts.pory"

# 151 "data/maps/Route37/scripts.pory"
Route37_Text_Sunny_NotSunday:
# 152 "data/maps/Route37/scripts.pory"
	.string "Sunny: Isn't today Sunday?\n"
# 153 "data/maps/Route37/scripts.pory"
	.string "Um… I forgot!$"
# 154 "data/maps/Route37/scripts.pory"

# 155 "data/maps/Route37/scripts.pory"
Route37_Text_Sign:
# 156 "data/maps/Route37/scripts.pory"
	.string "Route 37\n"
# 157 "data/maps/Route37/scripts.pory"
	.string "Ecruteak City Ahead$"

Route37Sign::
# 161 "data/maps/Route37/scripts.pory"
	msgbox Route37Sign_Text_0, MSGBOX_SIGN
	return


Route37Sign_Text_0:
# 161 "data/maps/Route37/scripts.pory"
	.string "{UP_ARROW} Ecruteak City\n"
	.string "{LEFT_ARROW} Battle Factory$"
