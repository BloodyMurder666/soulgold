# 1 "data/maps/Route39/scripts.pory"

# 2 "data/maps/Route39/scripts.pory"

# 3 "data/maps/Route39/scripts.pory"
Route39_MapScripts::
# 4 "data/maps/Route39/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
# 5 "data/maps/Route39/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/Route39/scripts.pory"
	.byte 0
# 7 "data/maps/Route39/scripts.pory"

# 8 "data/maps/Route39/scripts.pory"
Route39_OnTransition: 
# 9 "data/maps/Route39/scripts.pory"
	callnative SetTimeBasedEncounters
# 10 "data/maps/Route39/scripts.pory"
	end
# 11 "data/maps/Route39/scripts.pory"

# 12 "data/maps/Route39/scripts.pory"
Route39_EventScript_Woman::
# 13 "data/maps/Route39/scripts.pory"
	lock
# 14 "data/maps/Route39/scripts.pory"
	faceplayer
# 15 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
# 16 "data/maps/Route39/scripts.pory"
	closemessage
# 17 "data/maps/Route39/scripts.pory"
	release
# 18 "data/maps/Route39/scripts.pory"
	end
# 19 "data/maps/Route39/scripts.pory"

# 20 "data/maps/Route39/scripts.pory"
Route39_Text_Woman:
# 21 "data/maps/Route39/scripts.pory"
	.string "That shadow... Maybe it was a giant\n"
# 22 "data/maps/Route39/scripts.pory"
	.string "Pidgey?$"
# 23 "data/maps/Route39/scripts.pory"

# 24 "data/maps/Route39/scripts.pory"
Route39_EventScript_Miltank::
# 25 "data/maps/Route39/scripts.pory"
	lock
# 26 "data/maps/Route39/scripts.pory"
	faceplayer
# 27 "data/maps/Route39/scripts.pory"
	waitse
# 28 "data/maps/Route39/scripts.pory"
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
# 29 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
# 30 "data/maps/Route39/scripts.pory"
	waitmoncry
# 31 "data/maps/Route39/scripts.pory"
	release
# 32 "data/maps/Route39/scripts.pory"
	end
# 33 "data/maps/Route39/scripts.pory"

# 34 "data/maps/Route39/scripts.pory"
Route39_Text_Miltank:
# 35 "data/maps/Route39/scripts.pory"
	.string "Miltank: Mooo!$"
# 36 "data/maps/Route39/scripts.pory"

# 37 "data/maps/Route39/scripts.pory"
Route39_EventScript_Eugene::
# 38 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_EUGENE, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
# 39 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
# 40 "data/maps/Route39/scripts.pory"
	end
# 41 "data/maps/Route39/scripts.pory"

# 42 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneSeen:
# 43 "data/maps/Route39/scripts.pory"
	.string "I just got back to Olivine.\p"
# 44 "data/maps/Route39/scripts.pory"
	.string "So how about a Pokémon battle?$"
# 45 "data/maps/Route39/scripts.pory"

# 46 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneBeaten:
# 47 "data/maps/Route39/scripts.pory"
	.string "Awaaargh!$"
# 48 "data/maps/Route39/scripts.pory"

# 49 "data/maps/Route39/scripts.pory"
Route39_Text_SailorEugeneAfter:
# 50 "data/maps/Route39/scripts.pory"
	.string "My Pokémon were caught and\n"
# 51 "data/maps/Route39/scripts.pory"
	.string "raised overseas.\p"
# 52 "data/maps/Route39/scripts.pory"
	.string "They're my companions on\n"
# 53 "data/maps/Route39/scripts.pory"
	.string "those long voyages.$"
# 54 "data/maps/Route39/scripts.pory"

# 55 "data/maps/Route39/scripts.pory"
Route39_EventScript_Derek::
# 56 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
# 57 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
# 58 "data/maps/Route39/scripts.pory"
	end
# 59 "data/maps/Route39/scripts.pory"

# 60 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekSeen:
# 61 "data/maps/Route39/scripts.pory"
	.string "This is a good time to brag\n"
# 62 "data/maps/Route39/scripts.pory"
	.string "about my Pikachu!$"
# 63 "data/maps/Route39/scripts.pory"

# 64 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekBeaten:
# 65 "data/maps/Route39/scripts.pory"
	.string "I had no time to show off\n"
# 66 "data/maps/Route39/scripts.pory"
	.string "Pikachu…$"
# 67 "data/maps/Route39/scripts.pory"

# 68 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanMDerekAfter:
# 69 "data/maps/Route39/scripts.pory"
	.string "I'm not listening to your\n"
# 70 "data/maps/Route39/scripts.pory"
	.string "bragging!\p"
# 71 "data/maps/Route39/scripts.pory"
	.string "We POKé Fans have a policy\n"
# 72 "data/maps/Route39/scripts.pory"
	.string "of not listening to bragging!$"
# 73 "data/maps/Route39/scripts.pory"

# 74 "data/maps/Route39/scripts.pory"
Route39_EventScript_Ruth::
# 75 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
# 76 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
# 77 "data/maps/Route39/scripts.pory"
	end
# 78 "data/maps/Route39/scripts.pory"

# 79 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthSeen:
# 80 "data/maps/Route39/scripts.pory"
	.string "Such darling Pokémon.\p"
# 81 "data/maps/Route39/scripts.pory"
	.string "Let's show our Pokémon\n"
# 82 "data/maps/Route39/scripts.pory"
	.string "together at the same time.$"
# 83 "data/maps/Route39/scripts.pory"

# 84 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthBeaten:
# 85 "data/maps/Route39/scripts.pory"
	.string "I don't mind losing.$"
# 86 "data/maps/Route39/scripts.pory"

# 87 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFRuthAfter:
# 88 "data/maps/Route39/scripts.pory"
	.string "Do you know about baby\n"
# 89 "data/maps/Route39/scripts.pory"
	.string "Pokémon?\p"
# 90 "data/maps/Route39/scripts.pory"
	.string "I bet they're just adorable!$"
# 91 "data/maps/Route39/scripts.pory"

# 92 "data/maps/Route39/scripts.pory"
Route39_EventScript_Norman::
# 93 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
# 94 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
# 95 "data/maps/Route39/scripts.pory"
	end
# 96 "data/maps/Route39/scripts.pory"

# 97 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanSeen:
# 98 "data/maps/Route39/scripts.pory"
	.string "Let me see what your\n"
# 99 "data/maps/Route39/scripts.pory"
	.string "Pokémon are capable of.$"
# 100 "data/maps/Route39/scripts.pory"

# 101 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanBeaten:
# 102 "data/maps/Route39/scripts.pory"
	.string "Ooh, your Pokémon have\n"
# 103 "data/maps/Route39/scripts.pory"
	.string "potential.$"
# 104 "data/maps/Route39/scripts.pory"

# 105 "data/maps/Route39/scripts.pory"
Route39_Text_PsychicNormanAfter:
# 106 "data/maps/Route39/scripts.pory"
	.string "You know how Pokémon have\n"
# 107 "data/maps/Route39/scripts.pory"
	.string "different abilities?\p"
# 108 "data/maps/Route39/scripts.pory"
	.string "People are like that too.\n"
# 109 "data/maps/Route39/scripts.pory"
	.string "Everyone has different\l"
# 110 "data/maps/Route39/scripts.pory"
	.string "potential.$"
# 111 "data/maps/Route39/scripts.pory"

# 112 "data/maps/Route39/scripts.pory"
Route39_EventScript_Jamie::
# 113 "data/maps/Route39/scripts.pory"
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
# 114 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
# 115 "data/maps/Route39/scripts.pory"
	end
# 116 "data/maps/Route39/scripts.pory"

# 117 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeSeen:
# 118 "data/maps/Route39/scripts.pory"
	.string "You came at just the right\n"
# 119 "data/maps/Route39/scripts.pory"
	.string "time.\p"
# 120 "data/maps/Route39/scripts.pory"
	.string "Let's battle.$"
# 121 "data/maps/Route39/scripts.pory"

# 122 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeBeaten:
# 123 "data/maps/Route39/scripts.pory"
	.string "Oh, how disappointing…$"
# 124 "data/maps/Route39/scripts.pory"

# 125 "data/maps/Route39/scripts.pory"
Route39_Text_PokefanFJaimeAfter:
# 126 "data/maps/Route39/scripts.pory"
	.string "I met Umbreon at night right\n"
# 127 "data/maps/Route39/scripts.pory"
	.string "here on Route 39.\p"
# 128 "data/maps/Route39/scripts.pory"
	.string "I'm not sure why, but it\n"
# 129 "data/maps/Route39/scripts.pory"
	.string "seems to like it when I\l"
# 130 "data/maps/Route39/scripts.pory"
	.string "train here.\p"
# 131 "data/maps/Route39/scripts.pory"
	.string "It seems to become friendlier\n"
# 132 "data/maps/Route39/scripts.pory"
	.string "by training here than\l"
# 133 "data/maps/Route39/scripts.pory"
	.string "anywhere else.$"
# 134 "data/maps/Route39/scripts.pory"

# 135 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign1::
# 136 "data/maps/Route39/scripts.pory"
	lock
# 137 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_Sign, MSGBOX_SIGN
# 138 "data/maps/Route39/scripts.pory"
	closemessage
# 139 "data/maps/Route39/scripts.pory"
	release
# 140 "data/maps/Route39/scripts.pory"
	end
# 141 "data/maps/Route39/scripts.pory"

# 142 "data/maps/Route39/scripts.pory"
Route39_Text_Sign:
# 143 "data/maps/Route39/scripts.pory"
	.string "Route 39\p"
# 144 "data/maps/Route39/scripts.pory"
	.string "Olivine City - Ecruteak City$"
# 145 "data/maps/Route39/scripts.pory"

# 146 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign2::
# 147 "data/maps/Route39/scripts.pory"
	lock
# 148 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
# 149 "data/maps/Route39/scripts.pory"
	closemessage
# 150 "data/maps/Route39/scripts.pory"
	release
# 151 "data/maps/Route39/scripts.pory"
	end
# 152 "data/maps/Route39/scripts.pory"

# 153 "data/maps/Route39/scripts.pory"
Route39_Text_MoomooFarmSign:
# 154 "data/maps/Route39/scripts.pory"
	.string "Moomoo Farm\p"
# 155 "data/maps/Route39/scripts.pory"
	.string "Enjoy Our Fresh and Tasty Milk$"
# 156 "data/maps/Route39/scripts.pory"

# 157 "data/maps/Route39/scripts.pory"
Route39_EventScript_Sign3::
# 158 "data/maps/Route39/scripts.pory"
	lock
# 159 "data/maps/Route39/scripts.pory"
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
# 160 "data/maps/Route39/scripts.pory"
	closemessage
# 161 "data/maps/Route39/scripts.pory"
	release
# 162 "data/maps/Route39/scripts.pory"
	end
# 163 "data/maps/Route39/scripts.pory"

# 164 "data/maps/Route39/scripts.pory"
Route39_Text_TrainerTips:
# 165 "data/maps/Route39/scripts.pory"
	.string "Trainer Tips\p"
# 166 "data/maps/Route39/scripts.pory"
	.string "Use Headbutt on trees to shake\n"
# 167 "data/maps/Route39/scripts.pory"
	.string "Pokémon out.\p"
# 168 "data/maps/Route39/scripts.pory"
	.string "Different kinds of Pokémon\n"
# 169 "data/maps/Route39/scripts.pory"
	.string "drop out of trees.\p"
# 170 "data/maps/Route39/scripts.pory"
	.string "Use Headbutt on any tree\n"
# 171 "data/maps/Route39/scripts.pory"
	.string "you see!$"

Route39_NorthSign::
# 175 "data/maps/Route39/scripts.pory"
	msgbox Route39_NorthSign_Text_0, MSGBOX_SIGN
	return


Route39_BaobaTrigger::
# 179 "data/maps/Route39/scripts.pory"
	lock
# 180 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_BaobaTrigger_Movement_0
# 181 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 182 "data/maps/Route39/scripts.pory"
	playse SE_PIN
# 183 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Common_Movement_ExclamationMark
# 184 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 185 "data/maps/Route39/scripts.pory"
	approachobject LOCALID_R39_BAOBA, LOCALID_PLAYER, DIR_EAST, DIR_WEST
# 186 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 187 "data/maps/Route39/scripts.pory"
	msgbox Route39_BaobaTrigger_Text_0
# 212 "data/maps/Route39/scripts.pory"
	waitmessage
# 213 "data/maps/Route39/scripts.pory"
	msgbox Route39_BaobaTrigger_Text_1
# 214 "data/maps/Route39/scripts.pory"
	waitmessage
# 215 "data/maps/Route39/scripts.pory"
	playse MUS_HG_POKEGEAR_REGISTERED
# 216 "data/maps/Route39/scripts.pory"
	msgbox Route39_BaobaTrigger_Text_2
# 218 "data/maps/Route39/scripts.pory"
	waitse
# 219 "data/maps/Route39/scripts.pory"
	msgbox Route39_BaobaTrigger_Text_3
# 221 "data/maps/Route39/scripts.pory"
	closemessage
# 222 "data/maps/Route39/scripts.pory"
	applymovement LOCALID_R39_BAOBA, Route39_BaobaTrigger_Movement_1
# 223 "data/maps/Route39/scripts.pory"
	waitmovement 0
# 224 "data/maps/Route39/scripts.pory"
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
# 225 "data/maps/Route39/scripts.pory"
	removeobject LOCALID_R39_BAOBA
# 226 "data/maps/Route39/scripts.pory"
	setvar VAR_ROUTE39_BAOBA_STATE, 1
# 227 "data/maps/Route39/scripts.pory"
	release
	end


# 180 "data/maps/Route39/scripts.pory"
Route39_BaobaTrigger_Movement_0:
# 180 "data/maps/Route39/scripts.pory"
	face_right
	step_end

# 222 "data/maps/Route39/scripts.pory"
Route39_BaobaTrigger_Movement_1:
# 222 "data/maps/Route39/scripts.pory"
	walk_left
# 222 "data/maps/Route39/scripts.pory"
	walk_left
# 222 "data/maps/Route39/scripts.pory"
	walk_left
# 222 "data/maps/Route39/scripts.pory"
	walk_left
# 222 "data/maps/Route39/scripts.pory"
	walk_left
# 222 "data/maps/Route39/scripts.pory"
	walk_down
# 222 "data/maps/Route39/scripts.pory"
	walk_down
# 222 "data/maps/Route39/scripts.pory"
	walk_down
# 222 "data/maps/Route39/scripts.pory"
	walk_down
# 222 "data/maps/Route39/scripts.pory"
	walk_down
# 222 "data/maps/Route39/scripts.pory"
	walk_down
	step_end

Route39_NorthSign_Text_0:
# 175 "data/maps/Route39/scripts.pory"
	.string "{UP_ARROW} Snowtop Mountain trail$"

Route39_BaobaTrigger_Text_0:
# 187 "data/maps/Route39/scripts.pory"
	.string "Baoba: ...Ohh! \n"
	.string "What you are holding is...\l"
	.string "what they call... a Pokédex!\l"
	.string "Haven't seen one of those in ages.\p"
	.string "My name is Baoba!\p"
	.string "I used to run a Safari Zone in Fuchsia\n"
	.string "City, but it was becoming out of date\l"
	.string "with the new entertainment options\l"
	.string "coming out.\p"
	.string "I decided to go overseas to learn the\n"
	.string "newest technology and open a\l"
	.string "state-of-the-art Safari Zone in\l"
	.string "Ciandwood.\p"
	.string "It may be more than a coincidence that\n"
	.string "we are chatting.\p"
	.string "Why don't we register each other's\n"
	.string "numbers in the Pokégear?\p"
	.string "I can give you a call once the Safari\n"
	.string "Zone is open before I call anyone else!$"

Route39_BaobaTrigger_Text_1:
# 213 "data/maps/Route39/scripts.pory"
	.string "...$"

Route39_BaobaTrigger_Text_2:
# 216 "data/maps/Route39/scripts.pory"
	.string "{PLAYER} registered Baoba\n"
	.string "in the Pokégear!$"

Route39_BaobaTrigger_Text_3:
# 219 "data/maps/Route39/scripts.pory"
	.string "That's the way! I'll let you know\n"
	.string "over the Pokégear once it's ready!$"
