# 1 "data/maps/Route45/scripts.pory"

# 2 "data/maps/Route45/scripts.pory"
Route45_MapScripts::
# 3 "data/maps/Route45/scripts.pory"
	.byte 0
# 4 "data/maps/Route45/scripts.pory"

# 5 "data/maps/Route45/scripts.pory"
Route45_EventScript_Erik::
# 6 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_ERIK Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
# 7 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
# 8 "data/maps/Route45/scripts.pory"
	end
# 9 "data/maps/Route45/scripts.pory"

# 10 "data/maps/Route45/scripts.pory"
Route45_EventScript_Michael::
# 11 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_MICHAEL Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
# 12 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route45/scripts.pory"
	end
# 14 "data/maps/Route45/scripts.pory"

# 15 "data/maps/Route45/scripts.pory"
Route45_EventScript_Parry::
# 16 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_PARRY Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten
# 17 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route45/scripts.pory"
	end
# 19 "data/maps/Route45/scripts.pory"

# 20 "data/maps/Route45/scripts.pory"
Route45_EventScript_Timothy::
# 21 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_TIMOTHY Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
# 22 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route45/scripts.pory"
	end
# 24 "data/maps/Route45/scripts.pory"

# 25 "data/maps/Route45/scripts.pory"
Route45_EventScript_Kenji::
# 26 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_KENJI Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten
# 27 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route45/scripts.pory"
	end
# 29 "data/maps/Route45/scripts.pory"

# 30 "data/maps/Route45/scripts.pory"
Route45_EventScript_Ryan::
# 31 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_RYAN Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
# 32 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route45/scripts.pory"
	end
# 34 "data/maps/Route45/scripts.pory"

# 35 "data/maps/Route45/scripts.pory"
Route45_EventScript_Kelly::
# 36 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_KELLY Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
# 37 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route45/scripts.pory"
	end
# 39 "data/maps/Route45/scripts.pory"

# 40 "data/maps/Route45/scripts.pory"
Route45_EventScript_Quentin::
# 41 "data/maps/Route45/scripts.pory"
	trainerbattle_single TRAINER_QUENTIN Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
# 42 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route45/scripts.pory"
	end
# 44 "data/maps/Route45/scripts.pory"

# 45 "data/maps/Route45/scripts.pory"
Route45_EventScript_Sign::
# 46 "data/maps/Route45/scripts.pory"
	msgbox Route45_Text_Sign, MSGBOX_SIGN
# 47 "data/maps/Route45/scripts.pory"
	end
# 48 "data/maps/Route45/scripts.pory"

# 49 "data/maps/Route45/scripts.pory"
Route45_Text_HikerErikSeen:
# 50 "data/maps/Route45/scripts.pory"
    .string "Be prepared for anything!\p"
# 51 "data/maps/Route45/scripts.pory"
    .string "Let me see if your Pokémon have\n"
# 52 "data/maps/Route45/scripts.pory"
    .string "been raised properly!$"
# 53 "data/maps/Route45/scripts.pory"

# 54 "data/maps/Route45/scripts.pory"
Route45_Text_HikerErikBeaten:
# 55 "data/maps/Route45/scripts.pory"
    .string "Oh, I lost that!$"
# 56 "data/maps/Route45/scripts.pory"

# 57 "data/maps/Route45/scripts.pory"
Route45_Text_HikerErikAfter:
# 58 "data/maps/Route45/scripts.pory"
    .string "I'll head back to Blackthorn's\n"
# 59 "data/maps/Route45/scripts.pory"
    .string "Ice Path and train some more.$"
# 60 "data/maps/Route45/scripts.pory"

# 61 "data/maps/Route45/scripts.pory"
Route45_Text_HikerMichaelSeen:
# 62 "data/maps/Route45/scripts.pory"
    .string "Yo! You're spunky! But you know\n"
# 63 "data/maps/Route45/scripts.pory"
    .string "what?\p"
# 64 "data/maps/Route45/scripts.pory"
    .string "When it comes to sheer\n"
# 65 "data/maps/Route45/scripts.pory"
    .string "spunkiness, I'm the man!$"
# 66 "data/maps/Route45/scripts.pory"

# 67 "data/maps/Route45/scripts.pory"
Route45_Text_HikerMichaelBeaten:
# 68 "data/maps/Route45/scripts.pory"
    .string "My Pokémon weren't spunky enough!$"
# 69 "data/maps/Route45/scripts.pory"

# 70 "data/maps/Route45/scripts.pory"
Route45_Text_HikerMichaelAfter:
# 71 "data/maps/Route45/scripts.pory"
    .string "Boy, do I love Hp Up! Mmmm, yum!\p"
# 72 "data/maps/Route45/scripts.pory"
    .string "I keep drinking my Pokémon's!\p"
# 73 "data/maps/Route45/scripts.pory"
    .string "I can't help it!$"
# 74 "data/maps/Route45/scripts.pory"

# 75 "data/maps/Route45/scripts.pory"
Route45_Text_HikerParrySeen:
# 76 "data/maps/Route45/scripts.pory"
    .string "My Pokémon are power packed!$"
# 77 "data/maps/Route45/scripts.pory"

# 78 "data/maps/Route45/scripts.pory"
Route45_Text_HikerParryBeaten:
# 79 "data/maps/Route45/scripts.pory"
    .string "Wahahah! I'm the big loser!$"
# 80 "data/maps/Route45/scripts.pory"

# 81 "data/maps/Route45/scripts.pory"
Route45_Text_HikerParryAfter:
# 82 "data/maps/Route45/scripts.pory"
    .string "I'm not much good at thinking,\n"
# 83 "data/maps/Route45/scripts.pory"
    .string "see?\p"
# 84 "data/maps/Route45/scripts.pory"
    .string "So, I just plow ahead with power!$"
# 85 "data/maps/Route45/scripts.pory"

# 86 "data/maps/Route45/scripts.pory"

# 87 "data/maps/Route45/scripts.pory"
Route45_Text_HikerTimothySeen:
# 88 "data/maps/Route45/scripts.pory"
    .string "Why do I climb mountains?\p"
# 89 "data/maps/Route45/scripts.pory"
    .string "Because they're there.\p"
# 90 "data/maps/Route45/scripts.pory"
    .string "Why do I train Pokémon?\p"
# 91 "data/maps/Route45/scripts.pory"
    .string "Because they're there!$"
# 92 "data/maps/Route45/scripts.pory"

# 93 "data/maps/Route45/scripts.pory"
Route45_Text_HikerTimothyBeaten:
# 94 "data/maps/Route45/scripts.pory"
    .string "Losses… They're there too!$"
# 95 "data/maps/Route45/scripts.pory"

# 96 "data/maps/Route45/scripts.pory"
Route45_Text_HikerTimothyAfter:
# 97 "data/maps/Route45/scripts.pory"
    .string "The best thing to ever happen to\n"
# 98 "data/maps/Route45/scripts.pory"
    .string "me was discovering Pokémon.$"
# 99 "data/maps/Route45/scripts.pory"

# 100 "data/maps/Route45/scripts.pory"
Route45_Text_HikerParryGivesIron:
# 101 "data/maps/Route45/scripts.pory"
    .string "I just can't find a way to win!\p"
# 102 "data/maps/Route45/scripts.pory"
    .string "Keep it up!\p"
# 103 "data/maps/Route45/scripts.pory"
    .string "Oh, and take this -- it's the\n"
# 104 "data/maps/Route45/scripts.pory"
    .string "gift you couldn't take when we\n"
# 105 "data/maps/Route45/scripts.pory"
    .string "last met.$"
# 106 "data/maps/Route45/scripts.pory"

# 107 "data/maps/Route45/scripts.pory"
Route45_Text_BlackbeltKenjiSeen:
# 108 "data/maps/Route45/scripts.pory"
    .string "I was training here alone.\p"
# 109 "data/maps/Route45/scripts.pory"
    .string "Behold the fruits of my labor!$"
# 110 "data/maps/Route45/scripts.pory"

# 111 "data/maps/Route45/scripts.pory"
Route45_Text_BlackbeltKenjiBeaten:
# 112 "data/maps/Route45/scripts.pory"
    .string "Waaaargh!$"
# 113 "data/maps/Route45/scripts.pory"

# 114 "data/maps/Route45/scripts.pory"
Route45_Text_BlackbeltKenjiAfter:
# 115 "data/maps/Route45/scripts.pory"
    .string "This calls for extreme measures.\p"
# 116 "data/maps/Route45/scripts.pory"
    .string "I must take to the hills and train\n"
# 117 "data/maps/Route45/scripts.pory"
    .string "in solitude.$"
# 118 "data/maps/Route45/scripts.pory"

# 119 "data/maps/Route45/scripts.pory"
Route45_Text_BlackbeltKenjiMorning:
# 120 "data/maps/Route45/scripts.pory"
    .string "I'm going to train a bit more\n"
# 121 "data/maps/Route45/scripts.pory"
    .string "before I break for lunch.$"
# 122 "data/maps/Route45/scripts.pory"

# 123 "data/maps/Route45/scripts.pory"
Route45_Text_BlackbeltKenjiNight:
# 124 "data/maps/Route45/scripts.pory"
    .string "We had plenty of rest at lunch, so\p"
# 125 "data/maps/Route45/scripts.pory"
    .string "now we're all ready to go again!\p"
# 126 "data/maps/Route45/scripts.pory"
    .string "We're going to train again!$"
# 127 "data/maps/Route45/scripts.pory"

# 128 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainermRyanSeen:
# 129 "data/maps/Route45/scripts.pory"
    .string "What are your thoughts on\n"
# 130 "data/maps/Route45/scripts.pory"
    .string "raising Pokémon?$"
# 131 "data/maps/Route45/scripts.pory"

# 132 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainermRyanBeaten:
# 133 "data/maps/Route45/scripts.pory"
    .string "You've won my respect.$"
# 134 "data/maps/Route45/scripts.pory"

# 135 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainermRyanAfter:
# 136 "data/maps/Route45/scripts.pory"
    .string "I see you're raising your Pokémon\n"
# 137 "data/maps/Route45/scripts.pory"
    .string "with care.\p"
# 138 "data/maps/Route45/scripts.pory"
    .string "The bond you build will save you\n"
# 139 "data/maps/Route45/scripts.pory"
    .string "in tough situations.$"
# 140 "data/maps/Route45/scripts.pory"

# 141 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainerfKellySeen:
# 142 "data/maps/Route45/scripts.pory"
    .string "What is your battle strategy?\p"
# 143 "data/maps/Route45/scripts.pory"
    .string "It is foolish to use strong moves\n"
# 144 "data/maps/Route45/scripts.pory"
    .string "indiscriminately.$"
# 145 "data/maps/Route45/scripts.pory"

# 146 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainerfKellyBeaten:
# 147 "data/maps/Route45/scripts.pory"
    .string "Fine. I lost.$"
# 148 "data/maps/Route45/scripts.pory"

# 149 "data/maps/Route45/scripts.pory"
Route45_Text_CooltrainerfKellyAfter:
# 150 "data/maps/Route45/scripts.pory"
    .string "I'm not in favor of overly\n"
# 151 "data/maps/Route45/scripts.pory"
    .string "powerful moves.\p"
# 152 "data/maps/Route45/scripts.pory"
    .string "I want to win, but I also don't\n"
# 153 "data/maps/Route45/scripts.pory"
    .string "want to harm Pokémon.$"
# 154 "data/maps/Route45/scripts.pory"

# 155 "data/maps/Route45/scripts.pory"
Route45_Text_CamperQuentinSeen:
# 156 "data/maps/Route45/scripts.pory"
    .string "I'm really, really tough!$"
# 157 "data/maps/Route45/scripts.pory"

# 158 "data/maps/Route45/scripts.pory"
Route45_Text_CamperQuentinBeaten:
# 159 "data/maps/Route45/scripts.pory"
    .string "I was tough at the Battle Tower…$"
# 160 "data/maps/Route45/scripts.pory"

# 161 "data/maps/Route45/scripts.pory"
Route45_Text_CamperQuentinAfter:
# 162 "data/maps/Route45/scripts.pory"
    .string "Have you been to the Battle Tower?\p"
# 163 "data/maps/Route45/scripts.pory"
    .string "I never, ever lose there, but…$"
# 164 "data/maps/Route45/scripts.pory"

# 165 "data/maps/Route45/scripts.pory"
Route45_Text_Sign:
# 166 "data/maps/Route45/scripts.pory"
    .string "Route 45\n"
# 167 "data/maps/Route45/scripts.pory"
    .string "Mountain Rd. Ahead$"

R45KitakamiBorderSign::
# 171 "data/maps/Route45/scripts.pory"
	msgbox R45KitakamiBorderSign_Text_0, MSGBOX_SIGN
	return


R45KitakamiBorderSign_Text_0:
# 171 "data/maps/Route45/scripts.pory"
	.string "{RIGHT_ARROW} Road to Kitakami\n"
	.string "{DOWN_ARROW} Route 46$"
