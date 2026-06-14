# 1 "data/maps/Route27/scripts.pory"

# 2 "data/maps/Route27/scripts.pory"
.set LOCALID_ROUTE27_FATMAN, 1
# 3 "data/maps/Route27/scripts.pory"

# 4 "data/maps/Route27/scripts.pory"
Route27_MapScripts::
# 5 "data/maps/Route27/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
# 6 "data/maps/Route27/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 7 "data/maps/Route27/scripts.pory"
	.byte 0
# 8 "data/maps/Route27/scripts.pory"

# 9 "data/maps/Route27/scripts.pory"
Route27_OnTransition: 
# 10 "data/maps/Route27/scripts.pory"
	callnative SetTimeBasedEncounters
# 11 "data/maps/Route27/scripts.pory"
	end
# 12 "data/maps/Route27/scripts.pory"

# 13 "data/maps/Route27/scripts.pory"
Route27_EventScript_BaobaCall::
# 14 "data/maps/Route27/scripts.pory"
	pokenavcall BlackthornCity_Text_BaobaCall
# 15 "data/maps/Route27/scripts.pory"
	waitmessage
# 16 "data/maps/Route27/scripts.pory"
	delay 30
# 17 "data/maps/Route27/scripts.pory"
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
# 18 "data/maps/Route27/scripts.pory"
    setvar VAR_ROUTE27_BAOBA_CALL, 1
# 19 "data/maps/Route27/scripts.pory"
	end
# 20 "data/maps/Route27/scripts.pory"

# 21 "data/maps/Route27/scripts.pory"
Route27_Movement_WalkTop:
# 22 "data/maps/Route27/scripts.pory"
    face_left
# 23 "data/maps/Route27/scripts.pory"
    walk_left
# 24 "data/maps/Route27/scripts.pory"
    step_end
# 25 "data/maps/Route27/scripts.pory"

# 26 "data/maps/Route27/scripts.pory"
Route27_Movement_WalkBot:
# 27 "data/maps/Route27/scripts.pory"
    walk_down
# 28 "data/maps/Route27/scripts.pory"
    walk_left
# 29 "data/maps/Route27/scripts.pory"
    step_end
# 30 "data/maps/Route27/scripts.pory"

# 31 "data/maps/Route27/scripts.pory"
Route27_EventScript_Fatman::
# 32 "data/maps/Route27/scripts.pory"
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
# 33 "data/maps/Route27/scripts.pory"
    end
# 34 "data/maps/Route27/scripts.pory"

# 35 "data/maps/Route27/scripts.pory"
Route27_EventScript_Blake::
# 36 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
# 37 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route27/scripts.pory"
	end
# 39 "data/maps/Route27/scripts.pory"

# 40 "data/maps/Route27/scripts.pory"
Route27_EventScript_Brian::
# 41 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
# 42 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route27/scripts.pory"
	end
# 44 "data/maps/Route27/scripts.pory"

# 45 "data/maps/Route27/scripts.pory"
Route27_EventScript_Reena::
# 46 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_REENA Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten
# 47 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route27/scripts.pory"
	end
# 49 "data/maps/Route27/scripts.pory"

# 50 "data/maps/Route27/scripts.pory"
Route27_EventScript_Megan::
# 51 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
# 52 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route27/scripts.pory"
	end
# 54 "data/maps/Route27/scripts.pory"

# 55 "data/maps/Route27/scripts.pory"
Route27_EventScript_Gilbert::
# 56 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
# 57 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
# 58 "data/maps/Route27/scripts.pory"
	end
# 59 "data/maps/Route27/scripts.pory"

# 60 "data/maps/Route27/scripts.pory"
Route27_EventScript_Jose::
# 61 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_JOSE Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten
# 62 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route27/scripts.pory"
	end
# 64 "data/maps/Route27/scripts.pory"

# 65 "data/maps/Route27/scripts.pory"
Route27_EventScript_Scott::
# 66 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
# 67 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
# 68 "data/maps/Route27/scripts.pory"
	end
# 69 "data/maps/Route27/scripts.pory"

# 70 "data/maps/Route27/scripts.pory"
Route27_EventScript_TohjoFallsSign::
# 71 "data/maps/Route27/scripts.pory"
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
# 72 "data/maps/Route27/scripts.pory"
    end
# 73 "data/maps/Route27/scripts.pory"

# 74 "data/maps/Route27/scripts.pory"
Route27_Text_FisherHey:
# 75 "data/maps/Route27/scripts.pory"
    .string "Hey!$"
# 76 "data/maps/Route27/scripts.pory"

# 77 "data/maps/Route27/scripts.pory"
Route27_Text_FisherMessage:
# 78 "data/maps/Route27/scripts.pory"
    .string "Do you know what you just did?\p"
# 79 "data/maps/Route27/scripts.pory"
    .string "You've taken your first step into\n"
# 80 "data/maps/Route27/scripts.pory"
    .string "Kanto.\p"
# 81 "data/maps/Route27/scripts.pory"
    .string "Check your POKéGEAR Map and see.$"
# 82 "data/maps/Route27/scripts.pory"

# 83 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeSeen:
# 84 "data/maps/Route27/scripts.pory"
    .string "You look pretty strong.\n"
# 85 "data/maps/Route27/scripts.pory"
    .string "Let me battle you!$"
# 86 "data/maps/Route27/scripts.pory"

# 87 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeBeaten:
# 88 "data/maps/Route27/scripts.pory"
    .string "Yow!$"
# 89 "data/maps/Route27/scripts.pory"

# 90 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeAfter:
# 91 "data/maps/Route27/scripts.pory"
    .string "If you prevail on this harsh trek,\p"
# 92 "data/maps/Route27/scripts.pory"
    .string "the truth will be revealed!\p"
# 93 "data/maps/Route27/scripts.pory"
    .string "Heh, sorry, I just wanted to say\n"
# 94 "data/maps/Route27/scripts.pory"
    .string "something cool.$"
# 95 "data/maps/Route27/scripts.pory"

# 96 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianSeen:
# 97 "data/maps/Route27/scripts.pory"
    .string "Hm? You're good, aren't you?$"
# 98 "data/maps/Route27/scripts.pory"

# 99 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianBeaten:
# 100 "data/maps/Route27/scripts.pory"
    .string "Just as I thought!$"
# 101 "data/maps/Route27/scripts.pory"

# 102 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianAfter:
# 103 "data/maps/Route27/scripts.pory"
    .string "A good trainer can recognize other\n"
# 104 "data/maps/Route27/scripts.pory"
    .string "good trainers.$"
# 105 "data/maps/Route27/scripts.pory"

# 106 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaSeen:
# 107 "data/maps/Route27/scripts.pory"
    .string "You shouldn't underestimate the\n"
# 108 "data/maps/Route27/scripts.pory"
    .string "wild Pokémon in these parts.$"
# 109 "data/maps/Route27/scripts.pory"

# 110 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaBeaten:
# 111 "data/maps/Route27/scripts.pory"
    .string "Oh! You're much too strong!$"
# 112 "data/maps/Route27/scripts.pory"

# 113 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaAfter:
# 114 "data/maps/Route27/scripts.pory"
    .string "You're just a kid, but you're not\n"
# 115 "data/maps/Route27/scripts.pory"
    .string "to be underestimated either.$"
# 116 "data/maps/Route27/scripts.pory"

# 117 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganSeen:
# 118 "data/maps/Route27/scripts.pory"
    .string "It's rare to see anyone come here.\p"
# 119 "data/maps/Route27/scripts.pory"
    .string "Are you training on your own?$"
# 120 "data/maps/Route27/scripts.pory"

# 121 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganBeaten:
# 122 "data/maps/Route27/scripts.pory"
    .string "Oh! You're really strong!$"
# 123 "data/maps/Route27/scripts.pory"

# 124 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganAfter:
# 125 "data/maps/Route27/scripts.pory"
    .string "I'm checking out pre- and post-\n"
# 126 "data/maps/Route27/scripts.pory"
    .string "evolution Pokémon.\p"
# 127 "data/maps/Route27/scripts.pory"
    .string "Evolution really does make\n"
# 128 "data/maps/Route27/scripts.pory"
    .string "Pokémon stronger.\p"
# 129 "data/maps/Route27/scripts.pory"
    .string "But evolved forms also learn\n"
# 130 "data/maps/Route27/scripts.pory"
    .string "moves later on.$"
# 131 "data/maps/Route27/scripts.pory"

# 132 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertSeen:
# 133 "data/maps/Route27/scripts.pory"
    .string "Don't say a thing!\p"
# 134 "data/maps/Route27/scripts.pory"
    .string "Let me guess what you're thinking.\p"
# 135 "data/maps/Route27/scripts.pory"
    .string "Mmmmmmm…\p"
# 136 "data/maps/Route27/scripts.pory"
    .string "I got it! You're on the Pokémon\n"
# 137 "data/maps/Route27/scripts.pory"
    .string "League challenge!$"
# 138 "data/maps/Route27/scripts.pory"

# 139 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertBeaten:
# 140 "data/maps/Route27/scripts.pory"
    .string "You're too much!$"
# 141 "data/maps/Route27/scripts.pory"

# 142 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertAfter:
# 143 "data/maps/Route27/scripts.pory"
    .string "With your skills, you'll do well at\n"
# 144 "data/maps/Route27/scripts.pory"
    .string "the League.\p"
# 145 "data/maps/Route27/scripts.pory"
    .string "That's what my premonition says.$"
# 146 "data/maps/Route27/scripts.pory"

# 147 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseSeen:
# 148 "data/maps/Route27/scripts.pory"
    .string "Tweet! Tweet! Tetweet!$"
# 149 "data/maps/Route27/scripts.pory"

# 150 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseBeaten:
# 151 "data/maps/Route27/scripts.pory"
    .string "Tweet!$"
# 152 "data/maps/Route27/scripts.pory"

# 153 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseAfter:
# 154 "data/maps/Route27/scripts.pory"
    .string "Bird Keepers like me mimic bird\n"
# 155 "data/maps/Route27/scripts.pory"
    .string "whistles to command Pokémon.$"
# 156 "data/maps/Route27/scripts.pory"

# 157 "data/maps/Route27/scripts.pory"
TohjoFalls_Text_Sign:
# 158 "data/maps/Route27/scripts.pory"
    .string "Tohjo Falls\p"
# 159 "data/maps/Route27/scripts.pory"
    .string "The Link Between Kanto And Johto$"
# 160 "data/maps/Route27/scripts.pory"

# 161 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottSeen:
# 162 "data/maps/Route27/scripts.pory"
    .string "I'm feeling great today!\p"
# 163 "data/maps/Route27/scripts.pory"
    .string "I feel like I could boot even the\n"
# 164 "data/maps/Route27/scripts.pory"
    .string "League Champ!$"
# 165 "data/maps/Route27/scripts.pory"

# 166 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottBeaten:
# 167 "data/maps/Route27/scripts.pory"
    .string "No! Not in this battle!$"
# 168 "data/maps/Route27/scripts.pory"

# 169 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottAfter:
# 170 "data/maps/Route27/scripts.pory"
    .string "Just like in fish-ing, it's all over\n"
# 171 "data/maps/Route27/scripts.pory"
    .string "in Pokémon if you give up.$"

Route27_RouteExpert::
# 175 "data/maps/Route27/scripts.pory"
	lock
# 176 "data/maps/Route27/scripts.pory"
	faceplayer
# 177 "data/maps/Route27/scripts.pory"
	msgbox Route27_RouteExpert_Text_0
# 178 "data/maps/Route27/scripts.pory"
	release
	end


Route27_RouteExpert_Text_0:
# 177 "data/maps/Route27/scripts.pory"
	.string "Yo! I'm a cool trainer!$"
