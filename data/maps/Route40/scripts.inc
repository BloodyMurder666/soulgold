# 1 "data/maps/Route40/scripts.pory"

# 2 "data/maps/Route40/scripts.pory"
Route40_MapScripts::
# 3 "data/maps/Route40/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
# 4 "data/maps/Route40/scripts.pory"
	.byte 0
# 5 "data/maps/Route40/scripts.pory"

# 6 "data/maps/Route40/scripts.pory"
Route40_EventScript_Simon::
# 7 "data/maps/Route40/scripts.pory"
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
# 8 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
# 9 "data/maps/Route40/scripts.pory"
	end
# 10 "data/maps/Route40/scripts.pory"

# 11 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermSimonSeen:
# 12 "data/maps/Route40/scripts.pory"
	.string "You have to warm up before\n"
# 13 "data/maps/Route40/scripts.pory"
	.string "going into the water.\p"
# 14 "data/maps/Route40/scripts.pory"
	.string "That's basic.$"
# 15 "data/maps/Route40/scripts.pory"

# 16 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermSimonBeaten:
# 17 "data/maps/Route40/scripts.pory"
	.string "Ok! Uncle! I give!$"
# 18 "data/maps/Route40/scripts.pory"

# 19 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermSimonAfter:
# 20 "data/maps/Route40/scripts.pory"
	.string "Cianwood City is a good\n"
# 21 "data/maps/Route40/scripts.pory"
	.string "distance away from here.$"
# 22 "data/maps/Route40/scripts.pory"

# 23 "data/maps/Route40/scripts.pory"
Route40_EventScript_Randall::
# 24 "data/maps/Route40/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
# 25 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
# 26 "data/maps/Route40/scripts.pory"
	end
# 27 "data/maps/Route40/scripts.pory"

# 28 "data/maps/Route40/scripts.pory"

# 29 "data/maps/Route40/scripts.pory"
BattleTower_Outside_EventScript_Engineer::
# 30 "data/maps/Route40/scripts.pory"
	lock
# 31 "data/maps/Route40/scripts.pory"
	faceplayer
# 32 "data/maps/Route40/scripts.pory"
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
# 33 "data/maps/Route40/scripts.pory"
	closemessage
# 34 "data/maps/Route40/scripts.pory"
	release
# 35 "data/maps/Route40/scripts.pory"
	end
# 36 "data/maps/Route40/scripts.pory"

# 37 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermRandallSeen:
# 38 "data/maps/Route40/scripts.pory"
	.string "Hey, you're young and fit!\p"
# 39 "data/maps/Route40/scripts.pory"
	.string "Don't ride your Pokémon!\n"
# 40 "data/maps/Route40/scripts.pory"
	.string "Swim!$"
# 41 "data/maps/Route40/scripts.pory"

# 42 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermRandallBeaten:
# 43 "data/maps/Route40/scripts.pory"
	.string "Uh-oh. I lost…$"
# 44 "data/maps/Route40/scripts.pory"

# 45 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmermRandallAfter:
# 46 "data/maps/Route40/scripts.pory"
	.string "Swimming exercises your\n"
# 47 "data/maps/Route40/scripts.pory"
	.string "entire body. It's healthy.$"
# 48 "data/maps/Route40/scripts.pory"

# 49 "data/maps/Route40/scripts.pory"
Route40_EventScript_Elaine::
# 50 "data/maps/Route40/scripts.pory"
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
# 51 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route40/scripts.pory"
	end
# 53 "data/maps/Route40/scripts.pory"

# 54 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfElaineSeen:
# 55 "data/maps/Route40/scripts.pory"
	.string "Are you going to Cianwood?\p"
# 56 "data/maps/Route40/scripts.pory"
	.string "How about a quick battle\n"
# 57 "data/maps/Route40/scripts.pory"
	.string "first?$"
# 58 "data/maps/Route40/scripts.pory"

# 59 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfElaineBeaten:
# 60 "data/maps/Route40/scripts.pory"
	.string "I lost that one!$"
# 61 "data/maps/Route40/scripts.pory"

# 62 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfElaineAfter:
# 63 "data/maps/Route40/scripts.pory"
	.string "I'd say I'm a better swimmer\n"
# 64 "data/maps/Route40/scripts.pory"
	.string "than you. Yeah!$"
# 65 "data/maps/Route40/scripts.pory"

# 66 "data/maps/Route40/scripts.pory"
Route40_EventScript_Paula::
# 67 "data/maps/Route40/scripts.pory"
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
# 68 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
# 69 "data/maps/Route40/scripts.pory"
	end
# 70 "data/maps/Route40/scripts.pory"

# 71 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfPaulaSeen:
# 72 "data/maps/Route40/scripts.pory"
	.string "No inner tube for me.\p"
# 73 "data/maps/Route40/scripts.pory"
	.string "I'm hanging on to a sea\n"
# 74 "data/maps/Route40/scripts.pory"
	.string "Pokémon!$"
# 75 "data/maps/Route40/scripts.pory"

# 76 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfPaulaBeaten:
# 77 "data/maps/Route40/scripts.pory"
	.string "Ooh, I'm feeling dizzy!$"
# 78 "data/maps/Route40/scripts.pory"

# 79 "data/maps/Route40/scripts.pory"
Route40_Text_SwimmerfPaulaAfter:
# 80 "data/maps/Route40/scripts.pory"
	.string "The sun is so nice and warm\n"
# 81 "data/maps/Route40/scripts.pory"
	.string "here compared to other places.$"
# 82 "data/maps/Route40/scripts.pory"

# 83 "data/maps/Route40/scripts.pory"
Route40_EventScript_Woman1::
# 84 "data/maps/Route40/scripts.pory"
	lock
# 85 "data/maps/Route40/scripts.pory"
	faceplayer
# 86 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
# 87 "data/maps/Route40/scripts.pory"
	closemessage
# 88 "data/maps/Route40/scripts.pory"
	release
# 89 "data/maps/Route40/scripts.pory"
	end
# 90 "data/maps/Route40/scripts.pory"

# 91 "data/maps/Route40/scripts.pory"
Route40_Text_Lass1:
# 92 "data/maps/Route40/scripts.pory"
	.string "Although you can't see it from here,\n"
# 93 "data/maps/Route40/scripts.pory"
	.string "Cianwood is across the sea.$"
# 94 "data/maps/Route40/scripts.pory"

# 95 "data/maps/Route40/scripts.pory"
Route40_EventScript_Woman2::
# 96 "data/maps/Route40/scripts.pory"
	lock
# 97 "data/maps/Route40/scripts.pory"
	faceplayer
# 98 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
# 99 "data/maps/Route40/scripts.pory"
	closemessage
# 100 "data/maps/Route40/scripts.pory"
	release
# 101 "data/maps/Route40/scripts.pory"
	end
# 102 "data/maps/Route40/scripts.pory"

# 103 "data/maps/Route40/scripts.pory"
Route40_Text_Lass2:
# 104 "data/maps/Route40/scripts.pory"
	.string "I came to Olivine by ship to see\n"
# 105 "data/maps/Route40/scripts.pory"
	.string "the sights and soak up the\l"
# 106 "data/maps/Route40/scripts.pory"
	.string "atmosphere.\p"
# 107 "data/maps/Route40/scripts.pory"
	.string "Being a port, it feels so\n"
# 108 "data/maps/Route40/scripts.pory"
	.string "different from a big city.$"
# 109 "data/maps/Route40/scripts.pory"

# 110 "data/maps/Route40/scripts.pory"
Route40_EventScript_Youngster::
# 111 "data/maps/Route40/scripts.pory"
	lock
# 112 "data/maps/Route40/scripts.pory"
	faceplayer
# 113 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
# 114 "data/maps/Route40/scripts.pory"
	closemessage
# 115 "data/maps/Route40/scripts.pory"
	release
# 116 "data/maps/Route40/scripts.pory"
	end
# 117 "data/maps/Route40/scripts.pory"

# 118 "data/maps/Route40/scripts.pory"
Route40_Text_StandingYoungster:
# 119 "data/maps/Route40/scripts.pory"
	.string "Have you gone to the Battle\n"
# 120 "data/maps/Route40/scripts.pory"
	.string "Tower?\p"
# 121 "data/maps/Route40/scripts.pory"
	.string "I think a lot of tough trainers\n"
# 122 "data/maps/Route40/scripts.pory"
	.string "have gathered there already.\p"
# 123 "data/maps/Route40/scripts.pory"
	.string "But since you have so many\n"
# 124 "data/maps/Route40/scripts.pory"
	.string "Badges,\p"
# 125 "data/maps/Route40/scripts.pory"
	.string "you shouldn't do badly\n"
# 126 "data/maps/Route40/scripts.pory"
	.string "at all.$"
# 127 "data/maps/Route40/scripts.pory"

# 128 "data/maps/Route40/scripts.pory"
Route40_Text_Monica:
# 129 "data/maps/Route40/scripts.pory"
	.string "Monica: Glad to meet you.\n"
# 130 "data/maps/Route40/scripts.pory"
	.string "I'm Monica of the Weekday Family.\p"
# 131 "data/maps/Route40/scripts.pory"
	.string "I bet you can't guess my favorite\n"
# 132 "data/maps/Route40/scripts.pory"
	.string "day of the week!$"
# 133 "data/maps/Route40/scripts.pory"

# 134 "data/maps/Route40/scripts.pory"
Route40_Text_MonicaGivesGift:
# 135 "data/maps/Route40/scripts.pory"
	.string "That's right!\p"
# 136 "data/maps/Route40/scripts.pory"
	.string "As a token of our friendship,\n"
# 137 "data/maps/Route40/scripts.pory"
	.string "I have a gift for you!$"
# 138 "data/maps/Route40/scripts.pory"

# 139 "data/maps/Route40/scripts.pory"
Route40_Text_MonicaGaveGift:
# 140 "data/maps/Route40/scripts.pory"
	.string "Monica: It's an item that raises\n"
# 141 "data/maps/Route40/scripts.pory"
	.string "the power of Flying-Type moves.\p"
# 142 "data/maps/Route40/scripts.pory"
	.string "You should equip a bird\n"
# 143 "data/maps/Route40/scripts.pory"
	.string "Pokémon with that item.$"
# 144 "data/maps/Route40/scripts.pory"

# 145 "data/maps/Route40/scripts.pory"
Route40_Text_MonicaMonday:
# 146 "data/maps/Route40/scripts.pory"
	.string "Monica: My brothers and\n"
# 147 "data/maps/Route40/scripts.pory"
	.string "sisters are all over the place.\p"
# 148 "data/maps/Route40/scripts.pory"
	.string "See if you could find\n"
# 149 "data/maps/Route40/scripts.pory"
	.string "them all!$"
# 150 "data/maps/Route40/scripts.pory"

# 151 "data/maps/Route40/scripts.pory"
Route40_Text_MonicaNotMonday:
# 152 "data/maps/Route40/scripts.pory"
	.string "Monica: I don't think today\n"
# 153 "data/maps/Route40/scripts.pory"
	.string "is Monday. How sad…$"
# 154 "data/maps/Route40/scripts.pory"

# 155 "data/maps/Route40/scripts.pory"
Route40_Text_MonicaNope:
# 156 "data/maps/Route40/scripts.pory"
	.string "Not that one.$"
# 157 "data/maps/Route40/scripts.pory"

# 158 "data/maps/Route40/scripts.pory"
Rotue40_EventScript_Monica::
# 159 "data/maps/Route40/scripts.pory"
	lock
# 160 "data/maps/Route40/scripts.pory"
	faceplayer
# 161 "data/maps/Route40/scripts.pory"
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
# 162 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
# 163 "data/maps/Route40/scripts.pory"
	closemessage
# 164 "data/maps/Route40/scripts.pory"
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
# 165 "data/maps/Route40/scripts.pory"
	switch VAR_RESULT
# 166 "data/maps/Route40/scripts.pory"
	case 0, Rotue40_EventScript_MonicaNope
# 167 "data/maps/Route40/scripts.pory"
	case 1, Rotue40_EventScript_MonicaYes
# 168 "data/maps/Route40/scripts.pory"
	case 2, Rotue40_EventScript_MonicaNope
# 169 "data/maps/Route40/scripts.pory"
	case 3, Rotue40_EventScript_MonicaNope
# 170 "data/maps/Route40/scripts.pory"
	case 4, Rotue40_EventScript_MonicaNope
# 171 "data/maps/Route40/scripts.pory"
	case 5, Rotue40_EventScript_MonicaNope
# 172 "data/maps/Route40/scripts.pory"
	case 6, Rotue40_EventScript_MonicaNope
# 173 "data/maps/Route40/scripts.pory"
	case 7 Rotue40_EventScript_MonicaCancel
# 174 "data/maps/Route40/scripts.pory"
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
# 175 "data/maps/Route40/scripts.pory"
	closemessage
# 176 "data/maps/Route40/scripts.pory"
	release
# 177 "data/maps/Route40/scripts.pory"
	end
# 178 "data/maps/Route40/scripts.pory"
Rotue40_EventScript_MonicaYes::
# 179 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
# 180 "data/maps/Route40/scripts.pory"
	giveitem ITEM_SHARP_BEAK
# 181 "data/maps/Route40/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 182 "data/maps/Route40/scripts.pory"
	setflag FLAG_GOT_SHARP_BEAK
# 183 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
# 184 "data/maps/Route40/scripts.pory"
	closemessage
# 185 "data/maps/Route40/scripts.pory"
	release
# 186 "data/maps/Route40/scripts.pory"
	end
# 187 "data/maps/Route40/scripts.pory"
Rotue40_EventScript_MonicaNope::
# 188 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
# 189 "data/maps/Route40/scripts.pory"
	closemessage
# 190 "data/maps/Route40/scripts.pory"
	release
# 191 "data/maps/Route40/scripts.pory"
	end
# 192 "data/maps/Route40/scripts.pory"
Rotue40_EventScript_MonicaCancel::
# 193 "data/maps/Route40/scripts.pory"
	closemessage
# 194 "data/maps/Route40/scripts.pory"
	release
# 195 "data/maps/Route40/scripts.pory"
	end
# 196 "data/maps/Route40/scripts.pory"
Rotue40_EventScript_MonicaCompleted::
# 197 "data/maps/Route40/scripts.pory"
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
# 198 "data/maps/Route40/scripts.pory"
	closemessage
# 199 "data/maps/Route40/scripts.pory"
	release
# 200 "data/maps/Route40/scripts.pory"
	end

TuberGirlRoute40::
# 204 "data/maps/Route40/scripts.pory"
	msgbox TuberGirlRoute40_Text_0, MSGBOX_NPC
	return


CafeSignRoute40::
# 209 "data/maps/Route40/scripts.pory"
	msgbox CafeSignRoute40_Text_0, MSGBOX_SIGN
	return


TuberGirlRoute40_Text_0:
# 204 "data/maps/Route40/scripts.pory"
	.string "They sell yummy food in the cafe\n"
	.string "behind me!$"

CafeSignRoute40_Text_0:
# 209 "data/maps/Route40/scripts.pory"
	.string "Olivine Beach Cafe!\n"
	.string "Snacks and Meals all day!$"
