# 1 "data/maps/Route35/scripts.pory"

# 2 "data/maps/Route35/scripts.pory"
Route35_MapScripts::
# 3 "data/maps/Route35/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
# 4 "data/maps/Route35/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route35/scripts.pory"
	.byte 0
# 6 "data/maps/Route35/scripts.pory"

# 7 "data/maps/Route35/scripts.pory"
Route35_OnTransition: 
# 8 "data/maps/Route35/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route35/scripts.pory"
	end	
# 10 "data/maps/Route35/scripts.pory"

# 11 "data/maps/Route35/scripts.pory"
Route35_EventScript_CamperIvan::
# 12 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_IVAN Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
# 13 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
# 14 "data/maps/Route35/scripts.pory"
	end
# 15 "data/maps/Route35/scripts.pory"

# 16 "data/maps/Route35/scripts.pory"
Route35_EventScript_CamperElliot::
# 17 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_ELLIOT Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
# 18 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
# 19 "data/maps/Route35/scripts.pory"
	end
# 20 "data/maps/Route35/scripts.pory"

# 21 "data/maps/Route35/scripts.pory"
Route35_EventScript_PicnickerBrooke::
# 22 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_BROOKE Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
# 23 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
# 24 "data/maps/Route35/scripts.pory"
	end
# 25 "data/maps/Route35/scripts.pory"

# 26 "data/maps/Route35/scripts.pory"
Route35_EventScript_PicnickerKim::
# 27 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_KIM Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
# 28 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route35/scripts.pory"
	end
# 30 "data/maps/Route35/scripts.pory"

# 31 "data/maps/Route35/scripts.pory"
Route35_EventScript_BirdKeeperBryan::
# 32 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_BRYAN Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
# 33 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
# 34 "data/maps/Route35/scripts.pory"
	end
# 35 "data/maps/Route35/scripts.pory"

# 36 "data/maps/Route35/scripts.pory"
Route35_EventScript_JugglerIrwin::
# 37 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_IRWIN Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
# 38 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route35/scripts.pory"
	end
# 40 "data/maps/Route35/scripts.pory"

# 41 "data/maps/Route35/scripts.pory"
Route35_EventScript_BugCatcherArnie::
# 42 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_ARNIE Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten
# 43 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route35/scripts.pory"
	end
# 45 "data/maps/Route35/scripts.pory"

# 46 "data/maps/Route35/scripts.pory"
Route35_EventScript_FirebreatherWalt::
# 47 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_WALT Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
# 48 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
# 49 "data/maps/Route35/scripts.pory"
	end
# 50 "data/maps/Route35/scripts.pory"

# 51 "data/maps/Route35/scripts.pory"
Route35_EventScript_PolicemanDirk::
# 52 "data/maps/Route35/scripts.pory"
	trainerbattle_single TRAINER_DIRK Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
# 53 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route35/scripts.pory"
	end
# 55 "data/maps/Route35/scripts.pory"

# 56 "data/maps/Route35/scripts.pory"
Route35_EventScript_Sign1::
# 57 "data/maps/Route35/scripts.pory"
	lock
# 58 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_Sign, MSGBOX_SIGN
# 59 "data/maps/Route35/scripts.pory"
	closemessage
# 60 "data/maps/Route35/scripts.pory"
	release
# 61 "data/maps/Route35/scripts.pory"
	end
# 62 "data/maps/Route35/scripts.pory"

# 63 "data/maps/Route35/scripts.pory"
Route35_EventScript_Sign2::
# 64 "data/maps/Route35/scripts.pory"
	lock
# 65 "data/maps/Route35/scripts.pory"
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
# 66 "data/maps/Route35/scripts.pory"
	closemessage
# 67 "data/maps/Route35/scripts.pory"
	release
# 68 "data/maps/Route35/scripts.pory"
	end
# 69 "data/maps/Route35/scripts.pory"

# 70 "data/maps/Route35/scripts.pory"
Route35_Text_CamperIvanSeen:
# 71 "data/maps/Route35/scripts.pory"
	.string "I've been getting POKéMON data off\n"
# 72 "data/maps/Route35/scripts.pory"
	.string "my radio. I think I'm good.$"
# 73 "data/maps/Route35/scripts.pory"

# 74 "data/maps/Route35/scripts.pory"
Route35_Text_CamperIvanBeaten:
# 75 "data/maps/Route35/scripts.pory"
	.string "I give!$"
# 76 "data/maps/Route35/scripts.pory"

# 77 "data/maps/Route35/scripts.pory"
Route35_Text_CamperIvanAfter:
# 78 "data/maps/Route35/scripts.pory"
	.string "Music on the radio changes the\n"
# 79 "data/maps/Route35/scripts.pory"
	.string "moods of wild POKéMON.$"
# 80 "data/maps/Route35/scripts.pory"

# 81 "data/maps/Route35/scripts.pory"
Route35_Text_CamperElliotSeen:
# 82 "data/maps/Route35/scripts.pory"
	.string "I'm gonna show my girlfriend I'm\n"
# 83 "data/maps/Route35/scripts.pory"
	.string "hot stuff!$"
# 84 "data/maps/Route35/scripts.pory"

# 85 "data/maps/Route35/scripts.pory"
Route35_Text_CamperElliotBeaten:
# 86 "data/maps/Route35/scripts.pory"
	.string "I wish you would have lost for me…$"
# 87 "data/maps/Route35/scripts.pory"

# 88 "data/maps/Route35/scripts.pory"
Route35_Text_CamperElliotAfter:
# 89 "data/maps/Route35/scripts.pory"
	.string "I was humiliated in front of my\n"
# 90 "data/maps/Route35/scripts.pory"
	.string "girlfriend…$"
# 91 "data/maps/Route35/scripts.pory"

# 92 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerBrookeSeen:
# 93 "data/maps/Route35/scripts.pory"
	.string "My boyfriend's weak, so I can't rely\n"
# 94 "data/maps/Route35/scripts.pory"
	.string "on him.$"
# 95 "data/maps/Route35/scripts.pory"

# 96 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerBrookeBeaten:
# 97 "data/maps/Route35/scripts.pory"
	.string "Oh, my! You're so strong!$"
# 98 "data/maps/Route35/scripts.pory"

# 99 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerBrookeAfter:
# 100 "data/maps/Route35/scripts.pory"
	.string "I can count on my POKéMON more than\n"
# 101 "data/maps/Route35/scripts.pory"
	.string "my boyfriend.$"
# 102 "data/maps/Route35/scripts.pory"

# 103 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerKimSeen:
# 104 "data/maps/Route35/scripts.pory"
	.string "Are you going to the Gym? Me too!$"
# 105 "data/maps/Route35/scripts.pory"

# 106 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerKimBeaten:
# 107 "data/maps/Route35/scripts.pory"
	.string "Oh. I couldn't win…$"
# 108 "data/maps/Route35/scripts.pory"

# 109 "data/maps/Route35/scripts.pory"
Route35_Text_PicnickerKimAfter:
# 110 "data/maps/Route35/scripts.pory"
	.string "The Gym Badges are pretty. I collect\n"
# 111 "data/maps/Route35/scripts.pory"
	.string "them.$"
# 112 "data/maps/Route35/scripts.pory"

# 113 "data/maps/Route35/scripts.pory"
Route35_Text_BirdKeeperBryanSeen:
# 114 "data/maps/Route35/scripts.pory"
	.string "What kinds of Balls do you use?$"
# 115 "data/maps/Route35/scripts.pory"

# 116 "data/maps/Route35/scripts.pory"
Route35_Text_BirdKeeperBryanBeaten:
# 117 "data/maps/Route35/scripts.pory"
	.string "Yikes! Not fast enough!$"
# 118 "data/maps/Route35/scripts.pory"

# 119 "data/maps/Route35/scripts.pory"
Route35_Text_BirdKeeperBryanAfter:
# 120 "data/maps/Route35/scripts.pory"
	.string "Some POKéMON flee right away.\p"
# 121 "data/maps/Route35/scripts.pory"
	.string "Try catching them with Kurt's Fast\n"
# 122 "data/maps/Route35/scripts.pory"
	.string "Ball.\p"
# 123 "data/maps/Route35/scripts.pory"
	.string "Whenever I find a Wht Apricorn, I\n"
# 124 "data/maps/Route35/scripts.pory"
	.string "take it to Kurt.\p"
# 125 "data/maps/Route35/scripts.pory"
	.string "He turns it into a custom Ball.$"
# 126 "data/maps/Route35/scripts.pory"

# 127 "data/maps/Route35/scripts.pory"
Route35_Text_JugglerIrwinSeen:
# 128 "data/maps/Route35/scripts.pory"
	.string "Behold my graceful Ball dexterity!$"
# 129 "data/maps/Route35/scripts.pory"

# 130 "data/maps/Route35/scripts.pory"
Route35_Text_JugglerIrwinBeaten:
# 131 "data/maps/Route35/scripts.pory"
	.string "Whew! That was a jolt!$"
# 132 "data/maps/Route35/scripts.pory"

# 133 "data/maps/Route35/scripts.pory"
Route35_Text_JugglerIrwinAfter:
# 134 "data/maps/Route35/scripts.pory"
	.string "I was going to dazzle you with my\n"
# 135 "data/maps/Route35/scripts.pory"
	.string "prize POKéMON.\p"
# 136 "data/maps/Route35/scripts.pory"
	.string "But your prowess electrified me!$"
# 137 "data/maps/Route35/scripts.pory"

# 138 "data/maps/Route35/scripts.pory"
Route35_Text_BugCatcherArnieSeen:
# 139 "data/maps/Route35/scripts.pory"
	.string "I'll go anywhere if bug POKéMON\n"
# 140 "data/maps/Route35/scripts.pory"
	.string "appear there.$"
# 141 "data/maps/Route35/scripts.pory"

# 142 "data/maps/Route35/scripts.pory"
Route35_Text_BugCatcherArnieBeaten:
# 143 "data/maps/Route35/scripts.pory"
	.string "Huh? I shouldn't have lost that…$"
# 144 "data/maps/Route35/scripts.pory"

# 145 "data/maps/Route35/scripts.pory"
Route35_Text_BugCatcherArnieAfter:
# 146 "data/maps/Route35/scripts.pory"
	.string "My Venonat won me the Bug-Catching\n"
# 147 "data/maps/Route35/scripts.pory"
	.string "Contest at the National Park.$"
# 148 "data/maps/Route35/scripts.pory"

# 149 "data/maps/Route35/scripts.pory"
Route35_Text_BugCatcherArnieYanma:
# 150 "data/maps/Route35/scripts.pory"
	.string "Wow… Look at all those Yanma!\p"
# 151 "data/maps/Route35/scripts.pory"
	.string "I'm so blown away, I can't move.$"
# 152 "data/maps/Route35/scripts.pory"

# 153 "data/maps/Route35/scripts.pory"
Route35_Text_FirebreatherWaltSeen:
# 154 "data/maps/Route35/scripts.pory"
	.string "I'm practicing my fire breathing.$"
# 155 "data/maps/Route35/scripts.pory"

# 156 "data/maps/Route35/scripts.pory"
Route35_Text_FirebreatherWaltBeaten:
# 157 "data/maps/Route35/scripts.pory"
	.string "Ow! I scorched the tip of my nose!$"
# 158 "data/maps/Route35/scripts.pory"

# 159 "data/maps/Route35/scripts.pory"
Route35_Text_FirebreatherWaltAfter:
# 160 "data/maps/Route35/scripts.pory"
	.string "The POKéMON March on the radio\n"
# 161 "data/maps/Route35/scripts.pory"
	.string "lures wild POKéMON.$"
# 162 "data/maps/Route35/scripts.pory"

# 163 "data/maps/Route35/scripts.pory"
Route35_Text_OfficerDirkSeen:
# 164 "data/maps/Route35/scripts.pory"
	.string "Danger lurks in the night!$"
# 165 "data/maps/Route35/scripts.pory"

# 166 "data/maps/Route35/scripts.pory"
Route35_Text_OfficerDirkBeaten:
# 167 "data/maps/Route35/scripts.pory"
	.string "Whoops!$"
# 168 "data/maps/Route35/scripts.pory"

# 169 "data/maps/Route35/scripts.pory"
Route35_Text_OfficerDirkAfter:
# 170 "data/maps/Route35/scripts.pory"
	.string "You know, nighttime is fun in its\n"
# 171 "data/maps/Route35/scripts.pory"
	.string "own ways.\p"
# 172 "data/maps/Route35/scripts.pory"
	.string "But don't overdo it, Ok?$"
# 173 "data/maps/Route35/scripts.pory"

# 174 "data/maps/Route35/scripts.pory"
Route35_Text_OfficerDirkTough:
# 175 "data/maps/Route35/scripts.pory"
	.string "Your POKéMON look pretty tough.\p"
# 176 "data/maps/Route35/scripts.pory"
	.string "You could go anywhere safely.$"
# 177 "data/maps/Route35/scripts.pory"

# 178 "data/maps/Route35/scripts.pory"
Route35_Text_Sign:
# 179 "data/maps/Route35/scripts.pory"
	.string "Route 35$"
# 180 "data/maps/Route35/scripts.pory"

# 181 "data/maps/Route35/scripts.pory"
Route35_Text_Sign2:
# 182 "data/maps/Route35/scripts.pory"
	.string "National Park Gate$"

Route35_HiddenGrotto::
# 186 "data/maps/Route35/scripts.pory"
	msgbox Route35_HiddenGrotto_Text_0, MSGBOX_YESNO
# 188 "data/maps/Route35/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route35_HiddenGrotto_2
Route35_HiddenGrotto_1:
# 192 "data/maps/Route35/scripts.pory"
	release
	end

Route35_HiddenGrotto_2:
# 189 "data/maps/Route35/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE35, 0
# 190 "data/maps/Route35/scripts.pory"
	waitstate
	goto Route35_HiddenGrotto_1


Route35_HiddenGrotto_Text_0:
# 186 "data/maps/Route35/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
