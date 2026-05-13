# 1 "data/maps/Route44/scripts.pory"

# 2 "data/maps/Route44/scripts.pory"
Route44_MapScripts::
# 3 "data/maps/Route44/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
# 4 "data/maps/Route44/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route44/scripts.pory"
	.byte 0
# 6 "data/maps/Route44/scripts.pory"

# 7 "data/maps/Route44/scripts.pory"
Route44_OnTransition: 
# 8 "data/maps/Route44/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route44/scripts.pory"
	end
# 10 "data/maps/Route44/scripts.pory"

# 11 "data/maps/Route44/scripts.pory"
Route44_EventScript_Wilton::
# 12 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_WILTON Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten
# 13 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
# 14 "data/maps/Route44/scripts.pory"
	end
# 15 "data/maps/Route44/scripts.pory"

# 16 "data/maps/Route44/scripts.pory"
Route44_EventScript_Edgar::
# 17 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_EDGAR Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
# 18 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
# 19 "data/maps/Route44/scripts.pory"
	end
# 20 "data/maps/Route44/scripts.pory"

# 21 "data/maps/Route44/scripts.pory"
Route44_EventScript_Vance::
# 22 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_VANCE Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten
# 23 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
# 24 "data/maps/Route44/scripts.pory"
	end
# 25 "data/maps/Route44/scripts.pory"

# 26 "data/maps/Route44/scripts.pory"
Route44_EventScript_Phil::
# 27 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_PHIL Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
# 28 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
# 29 "data/maps/Route44/scripts.pory"
	end
# 30 "data/maps/Route44/scripts.pory"

# 31 "data/maps/Route44/scripts.pory"
Route44_EventScript_Zach::
# 32 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_ZACH Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
# 33 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
# 34 "data/maps/Route44/scripts.pory"
	end
# 35 "data/maps/Route44/scripts.pory"

# 36 "data/maps/Route44/scripts.pory"
Route44_EventScript_Allen::
# 37 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_ALLEN Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
# 38 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route44/scripts.pory"
	end
# 40 "data/maps/Route44/scripts.pory"

# 41 "data/maps/Route44/scripts.pory"
Route44_EventScript_Cybil::
# 42 "data/maps/Route44/scripts.pory"
	trainerbattle_single TRAINER_CYBIL Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
# 43 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route44/scripts.pory"
	end
# 45 "data/maps/Route44/scripts.pory"

# 46 "data/maps/Route44/scripts.pory"
Route44_EventScript_Sign1::
# 47 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
# 48 "data/maps/Route44/scripts.pory"
	end
# 49 "data/maps/Route44/scripts.pory"

# 50 "data/maps/Route44/scripts.pory"
Route44_EventScript_Sign2::
# 51 "data/maps/Route44/scripts.pory"
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
# 52 "data/maps/Route44/scripts.pory"
	end
# 53 "data/maps/Route44/scripts.pory"

# 54 "data/maps/Route44/scripts.pory"
Route44_Text_FisherWilton1Seen:
# 55 "data/maps/Route44/scripts.pory"
    .string "Aack!\p"
# 56 "data/maps/Route44/scripts.pory"
    .string "You made me lose a Poliwag!\n"
# 57 "data/maps/Route44/scripts.pory"
    .string "What are you going to do about it?$"
# 58 "data/maps/Route44/scripts.pory"

# 59 "data/maps/Route44/scripts.pory"
Route44_Text_FisherWilton1Beaten:
# 60 "data/maps/Route44/scripts.pory"
    .string "Just forget about it.$"
# 61 "data/maps/Route44/scripts.pory"

# 62 "data/maps/Route44/scripts.pory"
Route44_Text_FisherWiltonHugePoliwag:
# 63 "data/maps/Route44/scripts.pory"
    .string "That Poliwag that got away…\n"
# 64 "data/maps/Route44/scripts.pory"
    .string "it was huge.\p"
# 65 "data/maps/Route44/scripts.pory"
    .string "I swear it must've been\n"
# 66 "data/maps/Route44/scripts.pory"
    .string "16 feet long!$"
# 67 "data/maps/Route44/scripts.pory"

# 68 "data/maps/Route44/scripts.pory"
Route44_Text_FisherEdgarSeen:
# 69 "data/maps/Route44/scripts.pory"
    .string "I fish until I can't anymore.\p"
# 70 "data/maps/Route44/scripts.pory"
    .string "I also battle until I drop.\p"
# 71 "data/maps/Route44/scripts.pory"
    .string "That's my relationship with my\n"
# 72 "data/maps/Route44/scripts.pory"
    .string "Pokémon.$"
# 73 "data/maps/Route44/scripts.pory"

# 74 "data/maps/Route44/scripts.pory"
Route44_Text_FisherEdgarBeaten:
# 75 "data/maps/Route44/scripts.pory"
    .string "Hmmmm… This isn't right.$"
# 76 "data/maps/Route44/scripts.pory"

# 77 "data/maps/Route44/scripts.pory"
Route44_Text_FisherEdgarAfter:
# 78 "data/maps/Route44/scripts.pory"
    .string "That's 100 wins to 101 losses.\p"
# 79 "data/maps/Route44/scripts.pory"
    .string "I won't battle again for a while.$"
# 80 "data/maps/Route44/scripts.pory"

# 81 "data/maps/Route44/scripts.pory"
Route44_Text_BirdKeeperVance1Seen:
# 82 "data/maps/Route44/scripts.pory"
    .string "Do you know about the legendary\n"
# 83 "data/maps/Route44/scripts.pory"
    .string "bird Pokémon?$"
# 84 "data/maps/Route44/scripts.pory"

# 85 "data/maps/Route44/scripts.pory"
Route44_Text_BirdKeeperVance1Beaten:
# 86 "data/maps/Route44/scripts.pory"
    .string "Whew! You're hot stuff.$"
# 87 "data/maps/Route44/scripts.pory"

# 88 "data/maps/Route44/scripts.pory"
Route44_Text_BirdKeeperVanceBirds:
# 89 "data/maps/Route44/scripts.pory"
    .string "Articuno, Zapdos and Moltres are\n"
# 90 "data/maps/Route44/scripts.pory"
    .string "the three legendary bird Pokémon.\p"
# 91 "data/maps/Route44/scripts.pory"
    .string "I heard there are other legendary\n"
# 92 "data/maps/Route44/scripts.pory"
    .string "birds, though.$"
# 93 "data/maps/Route44/scripts.pory"

# 94 "data/maps/Route44/scripts.pory"
Route44_Text_PsychicPhilSeen:
# 95 "data/maps/Route44/scripts.pory"
    .string "I'm gonna win, for sure!$"
# 96 "data/maps/Route44/scripts.pory"

# 97 "data/maps/Route44/scripts.pory"
Route44_Text_PsychicPhilBeaten:
# 98 "data/maps/Route44/scripts.pory"
    .string "Arrgh… That's a shocking loss…$"
# 99 "data/maps/Route44/scripts.pory"

# 100 "data/maps/Route44/scripts.pory"
Route44_Text_PsychicPhilAfter:
# 101 "data/maps/Route44/scripts.pory"
    .string "It's important to have conviction\n"
# 102 "data/maps/Route44/scripts.pory"
    .string "on your side.$"
# 103 "data/maps/Route44/scripts.pory"

# 104 "data/maps/Route44/scripts.pory"
Route44_Text_PokemaniacZachSeen:
# 105 "data/maps/Route44/scripts.pory"
    .string "I'll do anything to get my hands\n"
# 106 "data/maps/Route44/scripts.pory"
    .string "on rare Pokémon!$"
# 107 "data/maps/Route44/scripts.pory"

# 108 "data/maps/Route44/scripts.pory"
Route44_Text_PokemaniacZachBeaten:
# 109 "data/maps/Route44/scripts.pory"
    .string "Oooh, your Pokémon are so\n"
# 110 "data/maps/Route44/scripts.pory"
    .string "appealing.$"
# 111 "data/maps/Route44/scripts.pory"

# 112 "data/maps/Route44/scripts.pory"
Route44_Text_PokemaniacZachAfter:
# 113 "data/maps/Route44/scripts.pory"
    .string "If a Pokémon has different colors\n"
# 114 "data/maps/Route44/scripts.pory"
    .string "from usual, it's more valuable.\p"
# 115 "data/maps/Route44/scripts.pory"
    .string "What? You mean that's not true?$"
# 116 "data/maps/Route44/scripts.pory"

# 117 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainermAllenSeen:
# 118 "data/maps/Route44/scripts.pory"
    .string "I can tell you're a good trainer\n"
# 119 "data/maps/Route44/scripts.pory"
    .string "by looking at you.\p"
# 120 "data/maps/Route44/scripts.pory"
    .string "I'm good at Pokémon, and I can\n"
# 121 "data/maps/Route44/scripts.pory"
    .string "see that you are too.$"
# 122 "data/maps/Route44/scripts.pory"

# 123 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainermAllenBeaten:
# 124 "data/maps/Route44/scripts.pory"
    .string "Tch! It's a total loss on my part.$"
# 125 "data/maps/Route44/scripts.pory"

# 126 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainermAllenAfter:
# 127 "data/maps/Route44/scripts.pory"
    .string "Wow. You have a lot of Badges.\p"
# 128 "data/maps/Route44/scripts.pory"
    .string "No wonder you're so tough.\p"
# 129 "data/maps/Route44/scripts.pory"
    .string "I wonder if Ecruteak Gym's Morty\n"
# 130 "data/maps/Route44/scripts.pory"
    .string "is still in training?\p"
# 131 "data/maps/Route44/scripts.pory"
    .string "He really hammered me.$"
# 132 "data/maps/Route44/scripts.pory"

# 133 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainerfCybilSeen:
# 134 "data/maps/Route44/scripts.pory"
    .string "You look strong.\p"
# 135 "data/maps/Route44/scripts.pory"
    .string "Good trainers seek tough\n"
# 136 "data/maps/Route44/scripts.pory"
    .string "opponents instinctively.$"
# 137 "data/maps/Route44/scripts.pory"

# 138 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainerfCybilBeaten:
# 139 "data/maps/Route44/scripts.pory"
    .string "Nope! This won't do at all.$"
# 140 "data/maps/Route44/scripts.pory"

# 141 "data/maps/Route44/scripts.pory"
Route44_Text_CooltrainerfCybilAfter:
# 142 "data/maps/Route44/scripts.pory"
    .string "We all get better by experiencing\n"
# 143 "data/maps/Route44/scripts.pory"
    .string "many battles.\p"
# 144 "data/maps/Route44/scripts.pory"
    .string "I battled a lot to become what I\n"
# 145 "data/maps/Route44/scripts.pory"
    .string "am today--an elite.$"
# 146 "data/maps/Route44/scripts.pory"

# 147 "data/maps/Route44/scripts.pory"
Route44_Text_Sign1:
# 148 "data/maps/Route44/scripts.pory"
    .string "Route 44\n"
# 149 "data/maps/Route44/scripts.pory"
    .string "Ice Path Ahead$"
# 150 "data/maps/Route44/scripts.pory"

# 151 "data/maps/Route44/scripts.pory"
Route44_Text_Sign2:
# 152 "data/maps/Route44/scripts.pory"
    .string "Route 44\p"
# 153 "data/maps/Route44/scripts.pory"
    .string "Mahogany Town - Blackthorn City$"

Route44_HiddenGrotto::
# 157 "data/maps/Route44/scripts.pory"
	msgbox Route44_HiddenGrotto_Text_0, MSGBOX_YESNO
# 159 "data/maps/Route44/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route44_HiddenGrotto_2
Route44_HiddenGrotto_1:
# 163 "data/maps/Route44/scripts.pory"
	release
	end

Route44_HiddenGrotto_2:
# 160 "data/maps/Route44/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE44, 0
# 161 "data/maps/Route44/scripts.pory"
	waitstate
	goto Route44_HiddenGrotto_1


Route44_HiddenGrotto_Text_0:
# 157 "data/maps/Route44/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
