# 1 "data/maps/Route38/scripts.pory"

# 2 "data/maps/Route38/scripts.pory"
Route38_MapScripts::
# 3 "data/maps/Route38/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
# 4 "data/maps/Route38/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route38/scripts.pory"
	.byte 0
# 6 "data/maps/Route38/scripts.pory"

# 7 "data/maps/Route38/scripts.pory"
Route38_OnTransition: 
# 8 "data/maps/Route38/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route38/scripts.pory"
	end
# 10 "data/maps/Route38/scripts.pory"

# 11 "data/maps/Route38/scripts.pory"
Route38_EventScript_Toby::
# 12 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_TOBY, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
# 13 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
# 14 "data/maps/Route38/scripts.pory"
	end
# 15 "data/maps/Route38/scripts.pory"

# 16 "data/maps/Route38/scripts.pory"
Route38_EventScript_Chad::
# 17 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_CHAD, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten
# 18 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
# 19 "data/maps/Route38/scripts.pory"
	end
# 20 "data/maps/Route38/scripts.pory"

# 21 "data/maps/Route38/scripts.pory"
Route38_EventScript_Dana::
# 22 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_DANA, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten
# 23 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
# 24 "data/maps/Route38/scripts.pory"
	end
# 25 "data/maps/Route38/scripts.pory"

# 26 "data/maps/Route38/scripts.pory"
Route38_EventScript_Valerie::
# 27 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_VALERIE, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
# 28 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route38/scripts.pory"
	end
# 30 "data/maps/Route38/scripts.pory"

# 31 "data/maps/Route38/scripts.pory"
Route38_EventScript_Harry::
# 32 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_HARRY, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
# 33 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
# 34 "data/maps/Route38/scripts.pory"
	end
# 35 "data/maps/Route38/scripts.pory"

# 36 "data/maps/Route38/scripts.pory"
Route38_EventScript_Olivia::
# 37 "data/maps/Route38/scripts.pory"
	trainerbattle_single TRAINER_OLIVIA, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
# 38 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route38/scripts.pory"
	end
# 40 "data/maps/Route38/scripts.pory"

# 41 "data/maps/Route38/scripts.pory"
Route38_EventScript_Sign1::
# 42 "data/maps/Route38/scripts.pory"
	lock
# 43 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_Sign, MSGBOX_SIGN
# 44 "data/maps/Route38/scripts.pory"
	closemessage
# 45 "data/maps/Route38/scripts.pory"
	release
# 46 "data/maps/Route38/scripts.pory"
	end
# 47 "data/maps/Route38/scripts.pory"

# 48 "data/maps/Route38/scripts.pory"
Route38_EventScript_Sign2::
# 49 "data/maps/Route38/scripts.pory"
	lock
# 50 "data/maps/Route38/scripts.pory"
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
# 51 "data/maps/Route38/scripts.pory"
	closemessage
# 52 "data/maps/Route38/scripts.pory"
	release
# 53 "data/maps/Route38/scripts.pory"
	end
# 54 "data/maps/Route38/scripts.pory"

# 55 "data/maps/Route38/scripts.pory"
Route38_Text_BirdKeeperTobySeen:
# 56 "data/maps/Route38/scripts.pory"
	.string "Fly high into the sky,\n"
# 57 "data/maps/Route38/scripts.pory"
	.string "my beloved bird POKéMON!$"
# 58 "data/maps/Route38/scripts.pory"

# 59 "data/maps/Route38/scripts.pory"
Route38_Text_BirdKeeperTobyBeaten:
# 60 "data/maps/Route38/scripts.pory"
	.string "I feel like just flying\n"
# 61 "data/maps/Route38/scripts.pory"
	.string "away now.$"
# 62 "data/maps/Route38/scripts.pory"

# 63 "data/maps/Route38/scripts.pory"
Route38_Text_BirdKeeperTobyAfter:
# 64 "data/maps/Route38/scripts.pory"
	.string "I plan to train in CIANWOOD CITY\n"
# 65 "data/maps/Route38/scripts.pory"
	.string "to teach my POKéMON how to FLY.$"
# 66 "data/maps/Route38/scripts.pory"

# 67 "data/maps/Route38/scripts.pory"
Route38_Text_SchoolboyChad1Seen:
# 68 "data/maps/Route38/scripts.pory"
	.string "Let me try something\n"
# 69 "data/maps/Route38/scripts.pory"
	.string "I learned today.$"
# 70 "data/maps/Route38/scripts.pory"

# 71 "data/maps/Route38/scripts.pory"
Route38_Text_SchoolboyChad1Beaten:
# 72 "data/maps/Route38/scripts.pory"
	.string "I didn't study enough,\n"
# 73 "data/maps/Route38/scripts.pory"
	.string "I guess.$"
# 74 "data/maps/Route38/scripts.pory"

# 75 "data/maps/Route38/scripts.pory"
Route38_Text_SchoolboyChadAfter:
# 76 "data/maps/Route38/scripts.pory"
	.string "I have to take so many\n"
# 77 "data/maps/Route38/scripts.pory"
	.string "tests, I don't have much\l"
# 78 "data/maps/Route38/scripts.pory"
	.string "time for POKéMON.\p"
# 79 "data/maps/Route38/scripts.pory"
	.string "So when I do get to play,\n"
# 80 "data/maps/Route38/scripts.pory"
	.string "I really concentrate.$"
# 81 "data/maps/Route38/scripts.pory"

# 82 "data/maps/Route38/scripts.pory"
Route38_Text_LassDana1Seen:
# 83 "data/maps/Route38/scripts.pory"
	.string "You seem to be good at\n"
# 84 "data/maps/Route38/scripts.pory"
	.string "POKéMON.\p"
# 85 "data/maps/Route38/scripts.pory"
	.string "If you are, how about\n"
# 86 "data/maps/Route38/scripts.pory"
	.string "giving me some advice?$"
# 87 "data/maps/Route38/scripts.pory"

# 88 "data/maps/Route38/scripts.pory"
Route38_Text_LassDana1Beaten:
# 89 "data/maps/Route38/scripts.pory"
	.string "I see. So you can battle\n"
# 90 "data/maps/Route38/scripts.pory"
	.string "that way.$"
# 91 "data/maps/Route38/scripts.pory"

# 92 "data/maps/Route38/scripts.pory"
Route38_Text_LassDanaAfter:
# 93 "data/maps/Route38/scripts.pory"
	.string "I know something good!\p"
# 94 "data/maps/Route38/scripts.pory"
	.string "MOOMOO FARM's milk is\n"
# 95 "data/maps/Route38/scripts.pory"
	.string "famous for its flavor.$"
# 96 "data/maps/Route38/scripts.pory"

# 97 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyValerieSeen:
# 98 "data/maps/Route38/scripts.pory"
	.string "Hi! Aren't you a cute\n"
# 99 "data/maps/Route38/scripts.pory"
	.string "trainer!\p"
# 100 "data/maps/Route38/scripts.pory"
	.string "May I see your POKéMON?$"
# 101 "data/maps/Route38/scripts.pory"

# 102 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyValerieBeaten:
# 103 "data/maps/Route38/scripts.pory"
	.string "I'm glad I got to see\n"
# 104 "data/maps/Route38/scripts.pory"
	.string "your POKéMON!$"
# 105 "data/maps/Route38/scripts.pory"

# 106 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyValerieAfter:
# 107 "data/maps/Route38/scripts.pory"
	.string "When I see POKéMON, it\n"
# 108 "data/maps/Route38/scripts.pory"
	.string "seems to soothe my nerves.$"
# 109 "data/maps/Route38/scripts.pory"

# 110 "data/maps/Route38/scripts.pory"
Route38_Text_SailorHarrySeen:
# 111 "data/maps/Route38/scripts.pory"
	.string "I've been overseas, so I\n"
# 112 "data/maps/Route38/scripts.pory"
	.string "know about all sorts of\l"
# 113 "data/maps/Route38/scripts.pory"
	.string "POKéMON!$"
# 114 "data/maps/Route38/scripts.pory"

# 115 "data/maps/Route38/scripts.pory"
Route38_Text_SailorHarryBeaten:
# 116 "data/maps/Route38/scripts.pory"
	.string "Your skill is world class!$"
# 117 "data/maps/Route38/scripts.pory"

# 118 "data/maps/Route38/scripts.pory"
Route38_Text_SailorHarryAfter:
# 119 "data/maps/Route38/scripts.pory"
	.string "All kinds of people around\n"
# 120 "data/maps/Route38/scripts.pory"
	.string "the world live happily with\l"
# 121 "data/maps/Route38/scripts.pory"
	.string "POKéMON.$"
# 122 "data/maps/Route38/scripts.pory"

# 123 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyOliviaSeen:
# 124 "data/maps/Route38/scripts.pory"
	.string "Don't you think my POKéMON\n"
# 125 "data/maps/Route38/scripts.pory"
	.string "and I are beautiful?$"
# 126 "data/maps/Route38/scripts.pory"

# 127 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyOliviaBeaten:
# 128 "data/maps/Route38/scripts.pory"
	.string "We drink MOOMOO MILK every\n"
# 129 "data/maps/Route38/scripts.pory"
	.string "day.$"
# 130 "data/maps/Route38/scripts.pory"

# 131 "data/maps/Route38/scripts.pory"
Route38_Text_BeautyOliviaAfter:
# 132 "data/maps/Route38/scripts.pory"
	.string "MOOMOO MILK is good for\n"
# 133 "data/maps/Route38/scripts.pory"
	.string "beauty and health,\p"
# 134 "data/maps/Route38/scripts.pory"
	.string "but inconveniently, they\n"
# 135 "data/maps/Route38/scripts.pory"
	.string "only sell one bottle at a time.$"
# 136 "data/maps/Route38/scripts.pory"

# 137 "data/maps/Route38/scripts.pory"
Route38_Text_Sign:
# 138 "data/maps/Route38/scripts.pory"
	.string "ROUTE 38\p"
# 139 "data/maps/Route38/scripts.pory"
	.string "OLIVINE CITY - ECRUTEAK CITY$"
# 140 "data/maps/Route38/scripts.pory"

# 141 "data/maps/Route38/scripts.pory"
Route38_Text_TrainerTips:
# 142 "data/maps/Route38/scripts.pory"
	.string "TRAINER TIPS\p"
# 143 "data/maps/Route38/scripts.pory"
	.string "If a POKéMON is trying to\n"
# 144 "data/maps/Route38/scripts.pory"
	.string "evolve, you can stop it.\p"
# 145 "data/maps/Route38/scripts.pory"
	.string "Press the B Button during\n"
# 146 "data/maps/Route38/scripts.pory"
	.string "evolution to cancel it.\p"
# 147 "data/maps/Route38/scripts.pory"
	.string "That startles the POKéMON\n"
# 148 "data/maps/Route38/scripts.pory"
	.string "and stops its evolution.$"
# 149 "data/maps/Route38/scripts.pory"

# 150 "data/maps/Route38/scripts.pory"

# 151 "data/maps/Route38/scripts.pory"
Route38_Text_WaterSign:
# 152 "data/maps/Route38/scripts.pory"
	.string "NO SWIMMING OR FISHING.\n"
# 153 "data/maps/Route38/scripts.pory"
	.string "WATER FOR FARMING ONLY.\p"
# 154 "data/maps/Route38/scripts.pory"
	.string "-ECRUTEAK COUNCIL$"

Route38_HiddenGrotto::
# 158 "data/maps/Route38/scripts.pory"
	msgbox Route38_HiddenGrotto_Text_0, MSGBOX_YESNO
# 160 "data/maps/Route38/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route38_HiddenGrotto_2
Route38_HiddenGrotto_1:
# 164 "data/maps/Route38/scripts.pory"
	release
	end

Route38_HiddenGrotto_2:
# 161 "data/maps/Route38/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE38, 0
# 162 "data/maps/Route38/scripts.pory"
	waitstate
	goto Route38_HiddenGrotto_1


Route38_HiddenGrotto_Text_0:
# 158 "data/maps/Route38/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
