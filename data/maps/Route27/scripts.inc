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
Route27_EventScript_FirstSteps::
# 22 "data/maps/Route27/scripts.pory"
    lock
# 23 "data/maps/Route27/scripts.pory"
    playse SE_PIN
# 24 "data/maps/Route27/scripts.pory"
    setflag FLAG_VISITED_KANTO
# 25 "data/maps/Route27/scripts.pory"
    applymovement LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
# 26 "data/maps/Route27/scripts.pory"
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
# 27 "data/maps/Route27/scripts.pory"
    delay 30
# 28 "data/maps/Route27/scripts.pory"
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 29 "data/maps/Route27/scripts.pory"
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
# 30 "data/maps/Route27/scripts.pory"
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot
# 31 "data/maps/Route27/scripts.pory"

# 32 "data/maps/Route27/scripts.pory"
    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
# 33 "data/maps/Route27/scripts.pory"
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
# 34 "data/maps/Route27/scripts.pory"
    closemessage
# 35 "data/maps/Route27/scripts.pory"
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH
# 36 "data/maps/Route27/scripts.pory"

# 37 "data/maps/Route27/scripts.pory"
    @integrated flagheap
# 38 "data/maps/Route27/scripts.pory"
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
# 39 "data/maps/Route27/scripts.pory"
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
# 40 "data/maps/Route27/scripts.pory"
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
# 41 "data/maps/Route27/scripts.pory"
    
# 42 "data/maps/Route27/scripts.pory"
    clearflag FLAG_GOT_TM_SANDSTORM
# 43 "data/maps/Route27/scripts.pory"
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
# 44 "data/maps/Route27/scripts.pory"
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
# 45 "data/maps/Route27/scripts.pory"

# 46 "data/maps/Route27/scripts.pory"
    setvar VAR_ROUTE27_STATE, 1
# 47 "data/maps/Route27/scripts.pory"
    release
# 48 "data/maps/Route27/scripts.pory"
    end
# 49 "data/maps/Route27/scripts.pory"

# 50 "data/maps/Route27/scripts.pory"
Route27_EventScript_FirstStepsWalkTop::
# 51 "data/maps/Route27/scripts.pory"
    applymovement LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
# 52 "data/maps/Route27/scripts.pory"
    waitmovement 0
# 53 "data/maps/Route27/scripts.pory"
    return
# 54 "data/maps/Route27/scripts.pory"
Route27_EventScript_FirstStepsWalkBot::
# 55 "data/maps/Route27/scripts.pory"
    applymovement LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
# 56 "data/maps/Route27/scripts.pory"
    waitmovement 0
# 57 "data/maps/Route27/scripts.pory"
    return
# 58 "data/maps/Route27/scripts.pory"

# 59 "data/maps/Route27/scripts.pory"
Route27_Movement_WalkTop:
# 60 "data/maps/Route27/scripts.pory"
    face_left
# 61 "data/maps/Route27/scripts.pory"
    walk_left
# 62 "data/maps/Route27/scripts.pory"
    step_end
# 63 "data/maps/Route27/scripts.pory"

# 64 "data/maps/Route27/scripts.pory"
Route27_Movement_WalkBot:
# 65 "data/maps/Route27/scripts.pory"
    walk_down
# 66 "data/maps/Route27/scripts.pory"
    walk_left
# 67 "data/maps/Route27/scripts.pory"
    step_end
# 68 "data/maps/Route27/scripts.pory"

# 69 "data/maps/Route27/scripts.pory"
Route27_EventScript_Fatman::
# 70 "data/maps/Route27/scripts.pory"
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
# 71 "data/maps/Route27/scripts.pory"
    end
# 72 "data/maps/Route27/scripts.pory"

# 73 "data/maps/Route27/scripts.pory"
Route27_EventScript_Blake::
# 74 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
# 75 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
# 76 "data/maps/Route27/scripts.pory"
	end
# 77 "data/maps/Route27/scripts.pory"

# 78 "data/maps/Route27/scripts.pory"
Route27_EventScript_Brian::
# 79 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
# 80 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
# 81 "data/maps/Route27/scripts.pory"
	end
# 82 "data/maps/Route27/scripts.pory"

# 83 "data/maps/Route27/scripts.pory"
Route27_EventScript_Reena::
# 84 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_REENA Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten
# 85 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
# 86 "data/maps/Route27/scripts.pory"
	end
# 87 "data/maps/Route27/scripts.pory"

# 88 "data/maps/Route27/scripts.pory"
Route27_EventScript_Megan::
# 89 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
# 90 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
# 91 "data/maps/Route27/scripts.pory"
	end
# 92 "data/maps/Route27/scripts.pory"

# 93 "data/maps/Route27/scripts.pory"
Route27_EventScript_Gilbert::
# 94 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
# 95 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
# 96 "data/maps/Route27/scripts.pory"
	end
# 97 "data/maps/Route27/scripts.pory"

# 98 "data/maps/Route27/scripts.pory"
Route27_EventScript_Jose::
# 99 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_JOSE Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten
# 100 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route27/scripts.pory"
	end
# 102 "data/maps/Route27/scripts.pory"

# 103 "data/maps/Route27/scripts.pory"
Route27_EventScript_Scott::
# 104 "data/maps/Route27/scripts.pory"
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
# 105 "data/maps/Route27/scripts.pory"
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route27/scripts.pory"
	end
# 107 "data/maps/Route27/scripts.pory"

# 108 "data/maps/Route27/scripts.pory"
Route27_EventScript_TohjoFallsSign::
# 109 "data/maps/Route27/scripts.pory"
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
# 110 "data/maps/Route27/scripts.pory"
    end
# 111 "data/maps/Route27/scripts.pory"

# 112 "data/maps/Route27/scripts.pory"
Route27_Text_FisherHey:
# 113 "data/maps/Route27/scripts.pory"
    .string "Hey!$"
# 114 "data/maps/Route27/scripts.pory"

# 115 "data/maps/Route27/scripts.pory"
Route27_Text_FisherMessage:
# 116 "data/maps/Route27/scripts.pory"
    .string "Do you know what you just did?\p"
# 117 "data/maps/Route27/scripts.pory"
    .string "You've taken your first step into\n"
# 118 "data/maps/Route27/scripts.pory"
    .string "Kanto.\p"
# 119 "data/maps/Route27/scripts.pory"
    .string "Check your POKéGEAR Map and see.$"
# 120 "data/maps/Route27/scripts.pory"

# 121 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeSeen:
# 122 "data/maps/Route27/scripts.pory"
    .string "You look pretty strong.\n"
# 123 "data/maps/Route27/scripts.pory"
    .string "Let me battle you!$"
# 124 "data/maps/Route27/scripts.pory"

# 125 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeBeaten:
# 126 "data/maps/Route27/scripts.pory"
    .string "Yow!$"
# 127 "data/maps/Route27/scripts.pory"

# 128 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBlakeAfter:
# 129 "data/maps/Route27/scripts.pory"
    .string "If you prevail on this harsh trek,\p"
# 130 "data/maps/Route27/scripts.pory"
    .string "the truth will be revealed!\p"
# 131 "data/maps/Route27/scripts.pory"
    .string "Heh, sorry, I just wanted to say\n"
# 132 "data/maps/Route27/scripts.pory"
    .string "something cool.$"
# 133 "data/maps/Route27/scripts.pory"

# 134 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianSeen:
# 135 "data/maps/Route27/scripts.pory"
    .string "Hm? You're good, aren't you?$"
# 136 "data/maps/Route27/scripts.pory"

# 137 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianBeaten:
# 138 "data/maps/Route27/scripts.pory"
    .string "Just as I thought!$"
# 139 "data/maps/Route27/scripts.pory"

# 140 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainermBrianAfter:
# 141 "data/maps/Route27/scripts.pory"
    .string "A good trainer can recognize other\n"
# 142 "data/maps/Route27/scripts.pory"
    .string "good trainers.$"
# 143 "data/maps/Route27/scripts.pory"

# 144 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaSeen:
# 145 "data/maps/Route27/scripts.pory"
    .string "You shouldn't underestimate the\n"
# 146 "data/maps/Route27/scripts.pory"
    .string "wild Pokémon in these parts.$"
# 147 "data/maps/Route27/scripts.pory"

# 148 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaBeaten:
# 149 "data/maps/Route27/scripts.pory"
    .string "Oh! You're much too strong!$"
# 150 "data/maps/Route27/scripts.pory"

# 151 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfReenaAfter:
# 152 "data/maps/Route27/scripts.pory"
    .string "You're just a kid, but you're not\n"
# 153 "data/maps/Route27/scripts.pory"
    .string "to be underestimated either.$"
# 154 "data/maps/Route27/scripts.pory"

# 155 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganSeen:
# 156 "data/maps/Route27/scripts.pory"
    .string "It's rare to see anyone come here.\p"
# 157 "data/maps/Route27/scripts.pory"
    .string "Are you training on your own?$"
# 158 "data/maps/Route27/scripts.pory"

# 159 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganBeaten:
# 160 "data/maps/Route27/scripts.pory"
    .string "Oh! You're really strong!$"
# 161 "data/maps/Route27/scripts.pory"

# 162 "data/maps/Route27/scripts.pory"
Route27_Text_CooltrainerfMeganAfter:
# 163 "data/maps/Route27/scripts.pory"
    .string "I'm checking out pre- and post-\n"
# 164 "data/maps/Route27/scripts.pory"
    .string "evolution Pokémon.\p"
# 165 "data/maps/Route27/scripts.pory"
    .string "Evolution really does make\n"
# 166 "data/maps/Route27/scripts.pory"
    .string "Pokémon stronger.\p"
# 167 "data/maps/Route27/scripts.pory"
    .string "But evolved forms also learn\n"
# 168 "data/maps/Route27/scripts.pory"
    .string "moves later on.$"
# 169 "data/maps/Route27/scripts.pory"

# 170 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertSeen:
# 171 "data/maps/Route27/scripts.pory"
    .string "Don't say a thing!\p"
# 172 "data/maps/Route27/scripts.pory"
    .string "Let me guess what you're thinking.\p"
# 173 "data/maps/Route27/scripts.pory"
    .string "Mmmmmmm…\p"
# 174 "data/maps/Route27/scripts.pory"
    .string "I got it! You're on the Pokémon\n"
# 175 "data/maps/Route27/scripts.pory"
    .string "League challenge!$"
# 176 "data/maps/Route27/scripts.pory"

# 177 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertBeaten:
# 178 "data/maps/Route27/scripts.pory"
    .string "You're too much!$"
# 179 "data/maps/Route27/scripts.pory"

# 180 "data/maps/Route27/scripts.pory"
Route27_Text_PsychicGilbertAfter:
# 181 "data/maps/Route27/scripts.pory"
    .string "With your skills, you'll do well at\n"
# 182 "data/maps/Route27/scripts.pory"
    .string "the League.\p"
# 183 "data/maps/Route27/scripts.pory"
    .string "That's what my premonition says.$"
# 184 "data/maps/Route27/scripts.pory"

# 185 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseSeen:
# 186 "data/maps/Route27/scripts.pory"
    .string "Tweet! Tweet! Tetweet!$"
# 187 "data/maps/Route27/scripts.pory"

# 188 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseBeaten:
# 189 "data/maps/Route27/scripts.pory"
    .string "Tweet!$"
# 190 "data/maps/Route27/scripts.pory"

# 191 "data/maps/Route27/scripts.pory"
Route27_Text_BirdKeeperJoseAfter:
# 192 "data/maps/Route27/scripts.pory"
    .string "Bird Keepers like me mimic bird\n"
# 193 "data/maps/Route27/scripts.pory"
    .string "whistles to command Pokémon.$"
# 194 "data/maps/Route27/scripts.pory"

# 195 "data/maps/Route27/scripts.pory"
TohjoFalls_Text_Sign:
# 196 "data/maps/Route27/scripts.pory"
    .string "Tohjo Falls\p"
# 197 "data/maps/Route27/scripts.pory"
    .string "The Link Between Kanto And Johto$"
# 198 "data/maps/Route27/scripts.pory"

# 199 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottSeen:
# 200 "data/maps/Route27/scripts.pory"
    .string "I'm feeling great today!\p"
# 201 "data/maps/Route27/scripts.pory"
    .string "I feel like I could boot even the\n"
# 202 "data/maps/Route27/scripts.pory"
    .string "League Champ!$"
# 203 "data/maps/Route27/scripts.pory"

# 204 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottBeaten:
# 205 "data/maps/Route27/scripts.pory"
    .string "No! Not in this battle!$"
# 206 "data/maps/Route27/scripts.pory"

# 207 "data/maps/Route27/scripts.pory"
Route27_Text_FisherScottAfter:
# 208 "data/maps/Route27/scripts.pory"
    .string "Just like in fish-ing, it's all over\n"
# 209 "data/maps/Route27/scripts.pory"
    .string "in Pokémon if you give up.$"

Route27_RouteExpert::
# 213 "data/maps/Route27/scripts.pory"
	lock
# 214 "data/maps/Route27/scripts.pory"
	faceplayer
# 215 "data/maps/Route27/scripts.pory"
	msgbox Route27_RouteExpert_Text_0
# 216 "data/maps/Route27/scripts.pory"
	release
	end


Route27_RouteExpert_Text_0:
# 215 "data/maps/Route27/scripts.pory"
	.string "Yo! I'm a cool trainer!$"
