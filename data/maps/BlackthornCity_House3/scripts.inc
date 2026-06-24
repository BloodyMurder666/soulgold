# 1 "data/maps/BlackthornCity_House3/scripts.pory"

# 2 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_House3_MapScripts::
# 3 "data/maps/BlackthornCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/BlackthornCity_House3/scripts.pory"

# 5 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
# 6 "data/maps/BlackthornCity_House3/scripts.pory"
	lockall
# 7 "data/maps/BlackthornCity_House3/scripts.pory"
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
# 8 "data/maps/BlackthornCity_House3/scripts.pory"
	waitmovement 0
# 9 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
# 10 "data/maps/BlackthornCity_House3/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/BlackthornCity_House3/scripts.pory"
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 12 "data/maps/BlackthornCity_House3/scripts.pory"
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
# 13 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 14 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 15 "data/maps/BlackthornCity_House3/scripts.pory"

# 16 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
# 17 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 18 "data/maps/BlackthornCity_House3/scripts.pory"
	special ChoosePartyMon
# 19 "data/maps/BlackthornCity_House3/scripts.pory"
	waitstate
# 20 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
# 21 "data/maps/BlackthornCity_House3/scripts.pory"
	special IsSelectedMonEgg
# 22 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 23 "data/maps/BlackthornCity_House3/scripts.pory"
	special GetNumMovesSelectedMonHas
# 24 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 25 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 26 "data/maps/BlackthornCity_House3/scripts.pory"
	fadescreen FADE_TO_BLACK
# 27 "data/maps/BlackthornCity_House3/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 28 "data/maps/BlackthornCity_House3/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 29 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 30 "data/maps/BlackthornCity_House3/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 31 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 32 "data/maps/BlackthornCity_House3/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/BlackthornCity_House3/scripts.pory"
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
# 34 "data/maps/BlackthornCity_House3/scripts.pory"
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
# 35 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 36 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 37 "data/maps/BlackthornCity_House3/scripts.pory"

# 38 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 39 "data/maps/BlackthornCity_House3/scripts.pory"
	special IsLastMonThatKnowsSurf
# 40 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 41 "data/maps/BlackthornCity_House3/scripts.pory"
	special MoveDeleterForgetMove
# 42 "data/maps/BlackthornCity_House3/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 43 "data/maps/BlackthornCity_House3/scripts.pory"
	waitfanfare
# 44 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 45 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 46 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 47 "data/maps/BlackthornCity_House3/scripts.pory"

# 48 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 49 "data/maps/BlackthornCity_House3/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 50 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 51 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 52 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 53 "data/maps/BlackthornCity_House3/scripts.pory"

# 54 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 55 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 56 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 57 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 58 "data/maps/BlackthornCity_House3/scripts.pory"

# 59 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
# 60 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 61 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 62 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 63 "data/maps/BlackthornCity_House3/scripts.pory"

# 64 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 65 "data/maps/BlackthornCity_House3/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 66 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 67 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 68 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 69 "data/maps/BlackthornCity_House3/scripts.pory"

# 70 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 71 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Uh…\n"
# 72 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Oh, yes, I'm the Move Deleter.\p"
# 73 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I can make Pokémon forget their moves.\p"
# 74 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Would you like me to do that?$"
# 75 "data/maps/BlackthornCity_House3/scripts.pory"

# 76 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 77 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Which Pokémon should forget a move?$"
# 78 "data/maps/BlackthornCity_House3/scripts.pory"

# 79 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 80 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Which move should be forgotten?$"
# 81 "data/maps/BlackthornCity_House3/scripts.pory"

# 82 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 83 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 84 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "so it can't be forgotten…$"
# 85 "data/maps/BlackthornCity_House3/scripts.pory"

# 86 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 87 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 88 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "That move should be forgotten?$"
# 89 "data/maps/BlackthornCity_House3/scripts.pory"

# 90 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 91 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "It worked to perfection!\p"
# 92 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 93 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 94 "data/maps/BlackthornCity_House3/scripts.pory"

# 95 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
# 96 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Come again if there are moves that\n"
# 97 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "need to be forgotten.$"
# 98 "data/maps/BlackthornCity_House3/scripts.pory"

# 99 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 100 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "What?\n"
# 101 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "No Egg should know any moves.$"
# 102 "data/maps/BlackthornCity_House3/scripts.pory"

# 103 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
# 104 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Hm!\p"
# 105 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 106 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "to forget Surf.$"
# 107 "data/maps/BlackthornCity_House3/scripts.pory"

# 108 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
# 109 "data/maps/BlackthornCity_House3/scripts.pory"
	lockall
# 110 "data/maps/BlackthornCity_House3/scripts.pory"
	faceplayer
# 111 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
# 112 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 113 "data/maps/BlackthornCity_House3/scripts.pory"
	setflag FLAG_TEMP_1
# 114 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
# 115 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 116 "data/maps/BlackthornCity_House3/scripts.pory"

# 117 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
# 118 "data/maps/BlackthornCity_House3/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 119 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 120 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 121 "data/maps/BlackthornCity_House3/scripts.pory"
	switch VAR_RESULT
# 122 "data/maps/BlackthornCity_House3/scripts.pory"
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 123 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
# 124 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 125 "data/maps/BlackthornCity_House3/scripts.pory"

# 126 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
# 127 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 128 "data/maps/BlackthornCity_House3/scripts.pory"
	special ChooseMonForMoveRelearner
# 129 "data/maps/BlackthornCity_House3/scripts.pory"
	waitstate
# 130 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 131 "data/maps/BlackthornCity_House3/scripts.pory"
	special IsSelectedMonEgg
# 132 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
# 133 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_0x8005, 0, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 134 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
# 135 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 136 "data/maps/BlackthornCity_House3/scripts.pory"

# 137 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
# 138 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 139 "data/maps/BlackthornCity_House3/scripts.pory"
	special TeachMoveRelearnerMove
# 140 "data/maps/BlackthornCity_House3/scripts.pory"
	waitstate
# 141 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
# 142 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 143 "data/maps/BlackthornCity_House3/scripts.pory"
	removeitem ITEM_HEART_SCALE
# 144 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 145 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 146 "data/maps/BlackthornCity_House3/scripts.pory"

# 147 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 148 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 149 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
# 150 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 151 "data/maps/BlackthornCity_House3/scripts.pory"

# 152 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 153 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 154 "data/maps/BlackthornCity_House3/scripts.pory"
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
# 155 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 156 "data/maps/BlackthornCity_House3/scripts.pory"

# 157 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 158 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 159 "data/maps/BlackthornCity_House3/scripts.pory"
	releaseall
# 160 "data/maps/BlackthornCity_House3/scripts.pory"
	end
# 161 "data/maps/BlackthornCity_House3/scripts.pory"

# 162 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 163 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I'm the Move Tutor.\p"
# 164 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I know all the moves that Pokémon\n"
# 165 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 166 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "teach Pokémon those moves.\p"
# 167 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I can teach a move to a Pokémon\n"
# 168 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "of yours if you'd like.\p"
# 169 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I'll do it for a Heart Scale.\n"
# 170 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I'm collecting those now.$"
# 171 "data/maps/BlackthornCity_House3/scripts.pory"

# 172 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 173 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 174 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "goodness Heart Scale!\p"
# 175 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 176 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "a move?$"
# 177 "data/maps/BlackthornCity_House3/scripts.pory"

# 178 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
# 179 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Which Pokémon needs tutoring?$"
# 180 "data/maps/BlackthornCity_House3/scripts.pory"

# 181 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
# 182 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Which move should I teach?$"
# 183 "data/maps/BlackthornCity_House3/scripts.pory"

# 184 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 185 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Sorry…\p"
# 186 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 187 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I can teach that Pokémon.$"
# 188 "data/maps/BlackthornCity_House3/scripts.pory"

# 189 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 190 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "{PLAYER} handed over one Heart Scale\n"
# 191 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "in exchange.$"
# 192 "data/maps/BlackthornCity_House3/scripts.pory"

# 193 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 194 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "If your Pokémon need to learn a move,\n"
# 195 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "come back with a Heart Scale.$"
# 196 "data/maps/BlackthornCity_House3/scripts.pory"

# 197 "data/maps/BlackthornCity_House3/scripts.pory"
BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
# 198 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 199 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I can teach an Egg.$"

EggMoveMaster::
# 205 "data/maps/BlackthornCity_House3/scripts.pory"
	lock
# 206 "data/maps/BlackthornCity_House3/scripts.pory"
	faceplayer
# 207 "data/maps/BlackthornCity_House3/scripts.pory"
	goto_if_set FLAG_EGG_MOVES_UNLOCKED, EggMoveMaster_2
# 215 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_1
# 222 "data/maps/BlackthornCity_House3/scripts.pory"
	showmoneybox 0, 0
# 223 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_2, MSGBOX_YESNO
# 225 "data/maps/BlackthornCity_House3/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EggMoveMaster_5
# 258 "data/maps/BlackthornCity_House3/scripts.pory"
	hidemoneybox
# 259 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_6
# 260 "data/maps/BlackthornCity_House3/scripts.pory"
	release
	end

EggMoveMaster_2:
# 208 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_0
# 212 "data/maps/BlackthornCity_House3/scripts.pory"
	release
	end

EggMoveMaster_4:
# 263 "data/maps/BlackthornCity_House3/scripts.pory"
	release
	end

EggMoveMaster_5:
# 226 "data/maps/BlackthornCity_House3/scripts.pory"
	checkmoney 88888
# 227 "data/maps/BlackthornCity_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EggMoveMaster_9
# 234 "data/maps/BlackthornCity_House3/scripts.pory"
	removemoney 88888
# 235 "data/maps/BlackthornCity_House3/scripts.pory"
	updatemoneybox 0
# 236 "data/maps/BlackthornCity_House3/scripts.pory"
	playse SE_SHOP
# 237 "data/maps/BlackthornCity_House3/scripts.pory"
	waitse
# 238 "data/maps/BlackthornCity_House3/scripts.pory"
	setflag FLAG_EGG_MOVES_UNLOCKED
	special Achievement_CheckAll
# 239 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_4
# 243 "data/maps/BlackthornCity_House3/scripts.pory"
	hidemoneybox
# 244 "data/maps/BlackthornCity_House3/scripts.pory"
	closemessage
# 245 "data/maps/BlackthornCity_House3/scripts.pory"
	fadescreen FADE_TO_BLACK
# 246 "data/maps/BlackthornCity_House3/scripts.pory"
	delay 60
# 247 "data/maps/BlackthornCity_House3/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 248 "data/maps/BlackthornCity_House3/scripts.pory"
	delay 20
# 249 "data/maps/BlackthornCity_House3/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 250 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_5
# 252 "data/maps/BlackthornCity_House3/scripts.pory"
	waitse
# 253 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_0
	goto EggMoveMaster_4

EggMoveMaster_9:
# 228 "data/maps/BlackthornCity_House3/scripts.pory"
	msgbox EggMoveMaster_Text_3
# 230 "data/maps/BlackthornCity_House3/scripts.pory"
	hidemoneybox
# 231 "data/maps/BlackthornCity_House3/scripts.pory"
	release
	end


EggMoveMaster_Text_0:
# 208 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "You can teach Egg Moves by\n"
	.string "pressing Start on the Battle Moves\l"
	.string "page of the Summary Screen and\l"
	.string "switching to the Egg Moves page.$"

EggMoveMaster_Text_1:
# 215 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I'm the Egg Move Master.\p"
	.string "I know all there is to know about Egg\n"
	.string "Moves.\p"
	.string "If you wish, I can teach you all that I \n"
	.string "know for a one-time fee of ¥88,888.$"

EggMoveMaster_Text_2:
# 223 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "What do you say? Do you wish to learn\n"
	.string "everything about Egg Moves?$"

EggMoveMaster_Text_3:
# 228 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "It seems you do not have the money\n"
	.string "to learn. A pity.$"

EggMoveMaster_Text_4:
# 239 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "Thank you for the business!\p"
	.string "Now let me teach you the grand\n"
	.string "secrets of the Egg Moves.$"

EggMoveMaster_Text_5:
# 250 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "You can now teach Egg Moves to\n"
	.string "your Pokémon!$"

EggMoveMaster_Text_6:
# 259 "data/maps/BlackthornCity_House3/scripts.pory"
	.string "I see.$"
