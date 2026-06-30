# 1 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 2 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_MapScripts::
# 3 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.byte 0
# 4 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 5 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_Grunt::
# 6 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 7 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 8 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
# 9 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_2,  RadioTower1F_Text_GruntM3Beaten
# 10 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
# 11 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
# 12 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	applymovement LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
# 13 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitmovement 0
# 14 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	playse SE_EXIT
# 15 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
# 16 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
# 17 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 18 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 19 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 20 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Movement_Rocket::
# 21 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_in_place_right
# 22 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	step_end
# 23 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 24 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_Lass::
# 25 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 26 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 27 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
# 28 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 29 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 30 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 31 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 32 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_Youngster::
# 33 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 34 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 35 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
# 36 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 37 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 38 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 39 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 40 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_Whitney::
# 41 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 42 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 43 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
# 44 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 45 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
# 46 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 47 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 48 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 49 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_Whitney1::
# 50 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Whitney: Hi!\p"
# 51 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "My name is Whitney!\p"
# 52 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "I heard about the Quiz to win a\n"
# 53 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Radio, so I came here to get\l"
# 54 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "one...\p"
# 55 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "But this Quiz is so hard!$"
# 56 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 57 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_Whitney2::
# 58 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Whitney: Wow, you did it!\p"
# 59 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "I thought the answer to the third\n"
# 60 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "question was surely apricorns!\l"
# 61 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Oops!\p"
# 62 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "It's time to go back to the Gym!$"
# 63 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 64 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_Reception::
# 65 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 66 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 67 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
# 68 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
# 69 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto RadioTowerReceiptionist
# 70 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 71 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 72 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 73 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 74 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionOfferQuiz::
# 75 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
# 76 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
# 77 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
# 78 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 79 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 80 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 81 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 82 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionQuiz1::
# 83 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
# 84 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
# 85 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
# 86 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 87 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 88 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 89 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 90 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionQuiz2::
# 91 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
# 92 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz3
# 93 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
# 94 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 95 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 96 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 97 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 98 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionQuiz3::
# 99 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
# 100 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
# 101 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
# 102 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 103 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 104 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 105 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 106 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionQuiz4::
# 107 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
# 108 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
# 109 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
# 110 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 111 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 112 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 113 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 114 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionQuiz5::
# 115 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
# 116 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
# 117 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
# 118 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 119 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 120 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 121 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 122 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_EventScript_ReceptionGiveRadio::
# 123 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
# 124 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 125 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 126 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	giveitem ITEM_RADIO
# 127 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitfanfare
# 128 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
# 129 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 130 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	playse SE_PIN
# 131 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
# 132 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	delay 60
# 133 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
# 134 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	delay 20
# 135 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 136 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
# 137 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 138 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
# 139 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitmovement 0
# 140 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	playse SE_EXIT
# 141 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
# 142 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setflag FLAG_ENABLE_RADIO
# 143 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
# 144 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 2
# 145 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 146 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 147 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 148 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
# 149 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	face_left
# 150 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_left
# 151 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_left
# 152 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_left
# 153 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_left
# 154 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_down
# 155 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_down
# 156 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	walk_in_place_down
# 157 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	step_end
# 158 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 159 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_Sign::
# 160 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 161 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
# 162 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	closemessage
# 163 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 164 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 165 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 166 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_ReceptionistWelcome:
# 167 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Welcome!$"
# 168 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 169 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_ReceptionistNoTours:
# 170 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "I'm sorry, but we're not\n"
# 171 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "offering any tours today.$"
# 172 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 173 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_RadioCardWomanOfferQuiz:
# 174 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "We have a special quiz campaign on\n"
# 175 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "right now.\p"
# 176 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Answer five questions correctly to\n"
# 177 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "win a Radio.\p"
# 178 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "You and your Pokémon can use it to\n"
# 179 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "play music anytime, anywhere.\p"
# 180 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Would you like to take the quiz?$"
# 181 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 182 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizQuestion1:
# 183 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Question 1:\p"
# 184 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Is there a Pokémon that appears only\n"
# 185 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "in the daytime?$"
# 186 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 187 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizQuestion2:
# 188 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Correct!\n"
# 189 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Question 2:\p"
# 190 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Is this statement correct?\p"
# 191 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "You can't buy a Berry at a Mart.$"
# 192 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 193 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizQuestion3:
# 194 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Bull's-eye!\n"
# 195 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Question 3:\p"
# 196 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Kurt, the Poké Ball creator, uses\n"
# 197 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "apricorns as ingredients?$"
# 198 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 199 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizQuestion4:
# 200 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "So far so good!\n"
# 201 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Question 4:\p"
# 202 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Is Falkner the Violet Gym Leader\n"
# 203 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "who uses bird Pokémon?$"
# 204 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 205 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizQuestion5:
# 206 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Wow! Right again!\n"
# 207 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Here's the final question:\p"
# 208 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Do Goldenrod Game Corner's slots\n"
# 209 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "have Charmander on their reels?$"
# 210 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 211 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_QuizWin:
# 212 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Bingo! You got it!\n"
# 213 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Congratulations!\p"
# 214 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Here's your prize, a Radio!$"
# 215 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 216 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_PokegearRadio:
# 217 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "{PLAYER}'s Pokégear can now double as\n"
# 218 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "a radio!$"
# 219 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 220 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_TuneIn:
# 221 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Please tune in to our radio shows\n"
# 222 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "between 6PM and 12AM!.$"
# 223 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 224 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_WrongAnswer:
# 225 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Oh, dear.\n"
# 226 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Sorry, but you got it wrong.\p"
# 227 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Please try again!$"
# 228 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 229 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_DeclineQuiz:
# 230 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Oh. I see. Please see me if you\n"
# 231 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "change your mind.$"
# 232 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 233 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_Lass:
# 234 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Ben is a fabulous Dj.\p"
# 235 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "His sweet voice makes me melt!$"
# 236 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 237 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_Youngster:
# 238 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "I love Mary, from Pokémon Talk.\p"
# 239 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "I only know what she sounds like,\n"
# 240 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "though.$"
# 241 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 242 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_GruntM3Seen:
# 243 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "We've finally taken over the\n"
# 244 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Radio Tower!\p"
# 245 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Now everyone will get to experience\n"
# 246 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "the true terror of Team Rocket!\p"
# 247 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "We'll show you how scary we are!$"
# 248 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 249 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_GruntM3Beaten:
# 250 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Too strong! I'm sorry boss…$"
# 251 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 252 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_GruntM3After:
# 253 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "You're too strong.\p"
# 254 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "Our plan could be ruined. I must\n"
# 255 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "warn the others…$"
# 256 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 257 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
RadioTower1F_Text_Directory:
# 258 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "1F Reception\n"
# 259 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "2F Sales\p"
# 260 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "3F Personnel\n"
# 261 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "4F Production\p"
# 262 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
    .string "5F Director's Office$"
# 263 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 264 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 265 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
# 266 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	lock
# 267 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	faceplayer
# 268 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	dotimebasedevents
# 269 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
# 270 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
# 271 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
# 272 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
# 273 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
# 274 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
# 275 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitmessage
# 276 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	special RetrieveLotteryNumber
# 277 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 278 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	special BufferLottoTicketNumber
# 279 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
# 280 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 281 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitmovement 0
# 282 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	playse SE_PC_ON
# 283 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	@special DoLotteryCornerComputerEffect
# 284 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	special PickLotteryCornerTicket
# 285 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	delay 220
# 286 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	@special EndLotteryCornerComputerEffect
# 287 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	delay 10
# 288 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	applymovement 4, Common_Movement_FacePlayer
# 289 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	waitmovement 0
# 290 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
# 291 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
# 292 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
# 293 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
# 294 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8005
# 295 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
# 296 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
# 297 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
# 298 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
# 299 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	giveitem VAR_0x8005
# 300 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
# 301 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 302 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
# 303 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 304 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 305 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
# 306 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
# 307 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 308 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 309 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
# 310 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
# 311 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 312 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 313 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
# 314 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
# 315 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 316 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 317 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 318 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
# 319 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
# 320 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 321 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 322 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 323 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
# 324 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
# 325 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
# 326 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 327 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 328 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
# 329 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
# 330 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 331 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 332 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 333 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
# 334 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
# 335 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 336 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 337 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
# 338 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
# 339 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 340 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 341 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
# 342 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
# 343 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 344 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 345 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
# 346 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
# 347 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	return
# 348 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 349 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
# 350 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
# 351 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
# 352 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
# 353 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 354 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 355 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
# 356 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
# 357 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 358 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 359 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 360 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
# 361 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
# 362 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	giveitem VAR_POKELOT_PRIZE_ITEM
# 363 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
# 364 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
# 365 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
# 366 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 367 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
# 368 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_PLACE, 0
# 369 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
# 370 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	end
# 371 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 372 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
# 373 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "This is the Pokémon Lottery Corner.\p"
# 374 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "If the Loto Ticket's number matches\n"
# 375 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "the Id number of any of your Pokémon,\l"
# 376 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "you will receive a fabulous gift.\p"
# 377 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Would you like to draw a Pokémon\n"
# 378 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Loto Ticket?$"
# 379 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 380 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
# 381 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Please come back tomorrow.$"
# 382 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 383 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
# 384 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Please do visit again.$"
# 385 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 386 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
# 387 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Please pick a Loto Ticket.\n"
# 388 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"
# 389 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 390 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
# 391 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "The Loto Ticket number is {STR_VAR_1}.\p"
# 392 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "I need to run a check on this number\n"
# 393 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "to see if it matches any of your\l"
# 394 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Pokémon's Id numbers. Please wait.$"
# 395 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 396 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
# 397 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Congratulations!\p"
# 398 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "The Id number of your team's\n"
# 399 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "{STR_VAR_1} matches your\l"
# 400 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Loto Ticket's number!$"
# 401 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 402 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
# 403 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Congratulations!\p"
# 404 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "The Id number of your PC-boxed\n"
# 405 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "{STR_VAR_1} matches your\l"
# 406 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Loto Ticket's number!$"
# 407 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 408 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
# 409 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "I'm sorry.\n"
# 410 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "None of the numbers matched.$"
# 411 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 412 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
# 413 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Two digits matched, so you win the\n"
# 414 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "third prize!\l"
# 415 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You've won the {STR_VAR_1}!$"
# 416 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 417 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
# 418 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Three digits matched, so you win the\n"
# 419 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "second prize!\l"
# 420 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You've won the {STR_VAR_1}!$"
# 421 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 422 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
# 423 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Four digits matched, so you win the\n"
# 424 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "first prize!\l"
# 425 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You've won the {STR_VAR_1}!$"
# 426 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 427 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
# 428 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Oh, my goodness, all five digits\n"
# 429 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "matched!\p"
# 430 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You've won the jackpot prize!\n"
# 431 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You've won the {STR_VAR_1}!$"
# 432 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 433 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
# 434 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Oh?\n"
# 435 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "You seem to have no room for this.\p"
# 436 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Please make room in your Bag and\n"
# 437 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "let me know.$"
# 438 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 439 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
# 440 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "{PLAYER}?\n"
# 441 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Yes, I've been expecting you.\p"
# 442 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "This is the prize we've been holding\n"
# 443 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "for you.$"
# 444 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"

# 445 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
# 446 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Please do visit again.$"

RadioTowerReceiptionist::
# 452 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	compare VAR_GOLDENROD_CITY_STATE, 6
	goto_if_ge RadioTowerReceiptionist_4
RadioTowerReceiptionist_3:
# 457 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTowerReceiptionist_Text_1
RadioTowerReceiptionist_1:
# 460 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	release
	end

RadioTowerReceiptionist_2:
# 454 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	msgbox RadioTowerReceiptionist_Text_0
	goto RadioTowerReceiptionist_1

RadioTowerReceiptionist_4:
# 453 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	compare VAR_GOLDENROD_CITY_STATE, 10
	goto_if_lt RadioTowerReceiptionist_2
	goto RadioTowerReceiptionist_3


RadioTowerReceiptionist_Text_0:
# 454 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "Wait no, Help! \n"
	.string "Where's the police?$"

RadioTowerReceiptionist_Text_1:
# 457 "data/maps/GoldenrodCity_RadioTower_1F/scripts.pory"
	.string "I'm sorry, but we're not\n"
	.string "offering any tours today.$"
