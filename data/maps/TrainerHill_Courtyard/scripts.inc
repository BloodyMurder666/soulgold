# 1 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 2 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_MapScripts::
# 3 "data/maps/TrainerHill_Courtyard/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
# 4 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.byte 0
# 5 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 6 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_OnTransition::
# 7 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 8 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_VISITED_BATTLE_TOWER
# 9 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_set FLAG_CAUGHT_ZERAORA, TrainerHill_Courtyard_EventScript_HideZeraora
# 10 "data/maps/TrainerHill_Courtyard/scripts.pory"
	specialvar VAR_RESULT, HasBattleTowerStreakForZeraora
# 11 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_HideZeraora
# 12 "data/maps/TrainerHill_Courtyard/scripts.pory"
	clearflag FLAG_HIDE_ZERAORA
# 13 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 14 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 15 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_HideZeraora::
# 16 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_HIDE_ZERAORA
# 17 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 18 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 19 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Zeraora::
# 20 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 21 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 22 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_ZeraoraChallenge, MSGBOX_YESNO
# 23 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_DeclineZeraora
# 24 "data/maps/TrainerHill_Courtyard/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_ZERAORA, 80, LOCALID_ZERAORA, FLAG_HIDE_ZERAORA, 4, SPECIES_NONE, 110, MOVE_PLASMA_FISTS, MOVE_CLOSE_COMBAT, MOVE_FIRE_PUNCH, MOVE_GRASS_KNOT
# 25 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, TrainerHill_Courtyard_EventScript_ZeraoraEnd
# 26 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_CAUGHT_ZERAORA
# 27 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ZeraoraEnd
# 28 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 29 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_DeclineZeraora::
# 30 "data/maps/TrainerHill_Courtyard/scripts.pory"
    playmoncry SPECIES_ZERAORA, 0
# 31 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_ZeraoraDisappointed, MSGBOX_DEFAULT
# 32 "data/maps/TrainerHill_Courtyard/scripts.pory"
    waitmoncry
# 33 "data/maps/TrainerHill_Courtyard/scripts.pory"
    release
# 34 "data/maps/TrainerHill_Courtyard/scripts.pory"
    end
# 35 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 36 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ZeraoraEnd::
# 37 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 38 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 39 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 40 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ZeraoraChallenge:
# 41 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Zeraora seems to be challenging\n"
# 42 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "you.\p"
# 43 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Will you accept its challenge?$"
# 44 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 45 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ZeraoraDisappointed:
# 46 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Zeraora howls in disappointment.$"
# 47 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 48 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_BattleTowerSign::
# 49 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 50 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
# 51 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage	
# 52 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 53 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 54 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 55 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Tent_Factory::
# 56 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 57 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
# 58 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage	
# 59 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 60 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 61 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 62 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Tent_Palace::
# 63 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 64 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
# 65 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage	
# 66 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 67 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 68 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 69 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Tent_Arena::
# 70 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 71 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
# 72 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage	
# 73 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 74 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 75 "data/maps/TrainerHill_Courtyard/scripts.pory"
	
# 76 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Engineer::
# 77 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 78 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 79 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
# 80 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage
# 81 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 82 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 83 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 84 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Youngster::
# 85 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 86 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 87 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
# 88 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage
# 89 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 90 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 91 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 92 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Beauty::
# 93 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 94 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 95 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
# 96 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage
# 97 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 98 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 99 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 100 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Sailor::
# 101 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 102 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 103 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
# 104 "data/maps/TrainerHill_Courtyard/scripts.pory"
	closemessage
# 105 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 106 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 107 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 108 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTowerOutsideYoungsterText:
# 109 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Wow, the Trainer Hill is huge!\p"
# 110 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "There must be many kinds of\n"
# 111 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Pokémon in there!$"
# 112 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 113 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTowerOutsideBeautyText:
# 114 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "In the Battle Tents, you can\n"
# 115 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "use only three Pokémon.\p"
# 116 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "It's so hard to decide which\n"
# 117 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "three should go into battle…$"
# 118 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 119 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTowerOutsideSailorText:
# 120 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hehehe, I snuck out from work.\p"
# 121 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I can't bail out until I've won!\p"
# 122 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I have to win it all. That I must!$"
# 123 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 124 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTowerOutsideSignText:
# 125 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "{UP_ARROW} Trainer Hill Entrance\p"
# 126 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 127 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Trainers!”\p"
# 128 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "{RIGHT_ARROW} Battle Tents.$"
# 129 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 130 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTower_Battle_Tent_Text_Factory:
# 131 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Battle Tent: Factory\n"
# 132 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "“Find it! The ultimate Pokémon!”$"
# 133 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 134 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTower_Battle_Tent_Text_Palace:
# 135 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Battle Tent: Palace\n"
# 136 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "“Feast Your Eyes on Battles!”$"
# 137 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 138 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTower_Battle_Tent_Text_Arena:
# 139 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Battle Tent: Arena\n"
# 140 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "“May the Greatest Teams Gather!”$"
# 141 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 142 "data/maps/TrainerHill_Courtyard/scripts.pory"
BattleTowerOutsideText_Closed:
# 143 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "The Trainer Hill is currently\n"
# 144 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "closed for repairs.$"
# 145 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 146 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 147 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_LeftMoveTutor::
# 148 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 149 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 150 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 151 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor
# 152 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_LeftTutorIntro, MSGBOX_DEFAULT
# 153 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
# 154 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
# 155 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 156 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 157 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor::
# 158 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
# 159 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
# 160 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 161 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 162 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove::
# 163 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMove
# 164 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 165 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowBattlePointsWindow
# 166 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 167 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 168 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 0
# 169 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 170 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 171 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 172 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 173 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
# 174 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
# 175 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
# 176 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
# 177 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
# 178 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
# 179 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
# 180 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_EventScript_Counter
# 181 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
# 182 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
# 183 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 184 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 185 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 186 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 187 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove::
# 188 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMove
# 189 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 190 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 191 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 192 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 1
# 193 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 194 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 195 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 196 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 197 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
# 198 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
# 199 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
# 200 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
# 201 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
# 202 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
# 203 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
# 204 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_EventScript_Counter
# 205 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
# 206 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
# 207 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 208 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 209 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 210 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 211 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Softboiled::
# 212 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 16
# 213 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 214 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 215 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 216 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_SeismicToss::
# 217 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 218 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 219 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 220 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 221 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_DreamEater::
# 222 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 223 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 224 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 225 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 226 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_MegaPunch::
# 227 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 228 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 229 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 230 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 231 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_MegaKick::
# 232 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 233 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 234 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 235 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 236 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_BodySlam::
# 237 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 238 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 239 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 240 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 241 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_RockSlide::
# 242 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 243 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 244 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 245 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 246 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Counter::
# 247 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 248 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 249 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 250 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 251 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ThunderWave::
# 252 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 253 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 254 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 255 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 256 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_SwordsDance::
# 257 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 258 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 259 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 260 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 261 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_RightMoveTutor::
# 262 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 263 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 264 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 265 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor
# 266 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_RightTutorIntro, MSGBOX_DEFAULT
# 267 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
# 268 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
# 269 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 270 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 271 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor::
# 272 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
# 273 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
# 274 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 275 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 276 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseRightTutorMove::
# 277 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMove
# 278 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 279 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowBattlePointsWindow
# 280 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 281 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 282 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 0
# 283 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 284 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 285 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 286 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 287 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
# 288 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_Snore
# 289 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
# 290 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_Swift
# 291 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
# 292 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_EventScript_Endure
# 293 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
# 294 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
# 295 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
# 296 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
# 297 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 298 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 299 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 300 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 301 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove::
# 302 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMove
# 303 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 304 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 305 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 306 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 1
# 307 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 308 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 309 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 310 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 311 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
# 312 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_Snore
# 313 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
# 314 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_Swift
# 315 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
# 316 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_EventScript_Endure
# 317 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
# 318 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
# 319 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
# 320 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
# 321 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 322 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 323 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 324 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 325 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_DefenseCurl::
# 326 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 16
# 327 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 328 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 329 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 330 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Snore::
# 331 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 332 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 333 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 334 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 335 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_MudSlap::
# 336 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 337 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 338 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 339 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 340 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Swift::
# 341 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 342 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 343 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 344 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 345 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_IcyWind::
# 346 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 24
# 347 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 348 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 349 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 350 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_Endure::
# 351 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 352 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 353 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 354 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 355 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_PsychUp::
# 356 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 357 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 358 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 359 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 360 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_IcePunch::
# 361 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 362 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 363 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 364 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 365 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ThunderPunch::
# 366 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 367 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 368 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 369 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 370 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_FirePunch::
# 371 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 372 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 373 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 374 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 375 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
# 376 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 377 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 378 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
# 379 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor
# 380 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_ElementalTutorIntro, MSGBOX_DEFAULT
# 381 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
# 382 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
# 383 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 384 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 385 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor::
# 386 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
# 387 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
# 388 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 389 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 390 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove::
# 391 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
# 392 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 393 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowBattlePointsWindow
# 394 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
# 395 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
# 396 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 0
# 397 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 398 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 399 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 400 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 401 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
# 402 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
# 403 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
# 404 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 405 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 406 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 407 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 408 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove::
# 409 "data/maps/TrainerHill_Courtyard/scripts.pory"
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
# 410 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitmessage
# 411 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
# 412 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
# 413 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8006, 1
# 414 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 415 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 416 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 417 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 418 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
# 419 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
# 420 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
# 421 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 422 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
# 423 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 424 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 425 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_FrenzyPlant::
# 426 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 427 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 428 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 429 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 430 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_BlastBurn::
# 431 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 432 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 433 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 434 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 435 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_HydroCannon::
# 436 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 437 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
# 438 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 439 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 440 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect::
# 441 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 442 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattlePointsWindow
# 443 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
# 444 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 445 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 446 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 447 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_CancelChooseMon::
# 448 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
# 449 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 450 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 451 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 452 "data/maps/TrainerHill_Courtyard/scripts.pory"
@ VAR_0x8008 is the price
# 453 "data/maps/TrainerHill_Courtyard/scripts.pory"
@ VAR_TEMP_C is the scroll multichoice ID
# 454 "data/maps/TrainerHill_Courtyard/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
# 455 "data/maps/TrainerHill_Courtyard/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
# 456 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ConfirmMoveSelection::
# 457 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
# 458 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
# 459 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special BufferBattleFrontierTutorMoveName
# 460 "data/maps/TrainerHill_Courtyard/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8008
# 461 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_C
# 462 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
# 463 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_ChooseNewMove
# 464 "data/maps/TrainerHill_Courtyard/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 465 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_EventScript_TeachTutorMove
# 466 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
# 467 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseNewMove
# 468 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 469 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 470 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_TeachTutorMove::
# 471 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
# 472 "data/maps/TrainerHill_Courtyard/scripts.pory"
	@special GetBattleFrontierTutorMoveIndex
# 473 "data/maps/TrainerHill_Courtyard/scripts.pory"
	fadescreen FADE_TO_BLACK
# 474 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattlePointsWindow
# 475 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 476 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ChooseMonForMoveTutor
# 477 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 478 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_CancelChooseMon
# 479 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
# 480 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 481 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special TakeFrontierBattlePoints
# 482 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 483 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 484 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 485 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_EventScript_ChooseNewMove::
# 486 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove
# 487 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove
# 488 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove
# 489 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 490 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 491 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_LeftTutorIntro:
# 492 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Buhahaha!\p"
# 493 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You couldn't tell it from looking now,\n"
# 494 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "but I used to be one tough Trainer.\p"
# 495 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I had a reputation as the toughest\n"
# 496 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Beauty around, I tell you!\p"
# 497 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "… … … … … …\p"
# 498 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What is it now?\n"
# 499 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You don't believe me.\p"
# 500 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm not like that blowhard woman over\n"
# 501 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "there. I'm actually talented!\p"
# 502 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Let me prove it to you.\n"
# 503 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I can teach your Pokémon special and\l"
# 504 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "yet cute moves.\p"
# 505 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "But my lessons don't come free.\n"
# 506 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 507 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 508 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 509 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_LeftTutorWelcomeBack:
# 510 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Buhahaha!\p"
# 511 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Are you back to learn special and\n"
# 512 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "yet cute Pokémon moves?$"
# 513 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 514 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_TeachWhichMove:
# 515 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Fine, fine, look here!\n"
# 516 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Which move should I teach?$"
# 517 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 518 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints:
# 519 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "The move {STR_VAR_1}, is it?\n"
# 520 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"
# 521 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 522 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_TeachMoveToWhichMon:
# 523 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Fine, fine, now pick the Pokémon\n"
# 524 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I should teach the move to.$"
# 525 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 526 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_HaventGotEnoughPoints:
# 527 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What the…\n"
# 528 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You haven't got enough Battle Points!$"
# 529 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 530 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_IllTakeBattlePoints:
# 531 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Do you see how skilled I am now?\n"
# 532 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'll take your Battle Points, thanks!$"
# 533 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 534 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_YouDontWantTo:
# 535 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What's that?\n"
# 536 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You don't want to…\p"
# 537 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "If you want to see how skilled I am,\n"
# 538 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "you come see me anytime!$"
# 539 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 540 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_RightTutorIntro:
# 541 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Ihihihi!\p"
# 542 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I know it's hard to see now, but I used\n"
# 543 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "to be one fantastic Trainer.\p"
# 544 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I had a reputation as the most\n"
# 545 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "invincible Swimmer around, I tell you!\p"
# 546 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "… … … … … …\p"
# 547 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What's wrong?\n"
# 548 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You don't believe me.\p"
# 549 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm not like that buffoonish woman over\n"
# 550 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "there. I'm actually experienced!\p"
# 551 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I can prove it to you.\n"
# 552 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I can teach your Pokémon hard and\l"
# 553 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "yet pretty moves.\p"
# 554 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "But my lessons don't come free.\n"
# 555 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 556 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 557 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 558 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_RightTutorWelcomeBack:
# 559 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Ihihihi!\p"
# 560 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Have you come to learn hard and\n"
# 561 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "yet pretty Pokémon moves?$"
# 562 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 563 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ThinkLadiesDontGetAlong:
# 564 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Those ladies, the way they bad-mouth\n"
# 565 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "each other, you probably think that\l"
# 566 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "they don't get along.\p"
# 567 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "But if that were true, they wouldn't\n"
# 568 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "stay out here together, would they?$"
# 569 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 570 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_LadiesWereStrongAndBeautiful:
# 571 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "When I was just a wee Youngster,\n"
# 572 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "those ladies were strong and beautiful.\p"
# 573 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "They were idols among us Trainers.\p"
# 574 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Even now, age hasn't dulled their\n"
# 575 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "abilities.\p"
# 576 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "In fact, their Pokémon moves have\n"
# 577 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "grown even more polished.\p"
# 578 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "But… For some reason, I can't help\n"
# 579 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "but feel this…\p"
# 580 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Time is so cruel…$"
# 581 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 582 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_SoftboiledDesc::
# 583 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Recovers up to\n"
# 584 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "half the user's\n"
# 585 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "maximum Hp.$"
# 586 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 587 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_SeismicTossDesc::
# 588 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Inflicts damage\n"
# 589 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "identical to the\n"
# 590 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "user's level.$"
# 591 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 592 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_DreamEaterDesc::
# 593 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Recovers half the\n"
# 594 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "damage inflicted\n"
# 595 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "on a sleeping foe.$"
# 596 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 597 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_MegaPunchDesc::
# 598 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A strong punch\n"
# 599 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "thrown with\n"
# 600 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "incredible power.$"
# 601 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 602 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_MegaKickDesc::
# 603 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "An extremely\n"
# 604 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "powerful kick with\n"
# 605 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "intense force.$"
# 606 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 607 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_BodySlamDesc::
# 608 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A full-body slam\n"
# 609 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that may cause\n"
# 610 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "paralysis.$"
# 611 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 612 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_RockSlideDesc::
# 613 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Large boulders\n"
# 614 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "are hurled. May\n"
# 615 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "cause flinching.$"
# 616 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 617 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_CounterDesc::
# 618 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Retaliates any\n"
# 619 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "physical hit with\n"
# 620 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "double the power.$"
# 621 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 622 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ThunderWaveDesc::
# 623 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A weak jolt of\n"
# 624 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "electricity that\n"
# 625 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "paralyzes the foe.$"
# 626 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 627 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_SwordsDanceDesc::
# 628 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A fighting dance\n"
# 629 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that sharply\n"
# 630 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "raises Attack.$"
# 631 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 632 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_DefenseCurlDesc::
# 633 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Curls up to con-\n"
# 634 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "ceal weak spots\n"
# 635 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "and raise Defense.$"
# 636 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 637 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_SnoreDesc::
# 638 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A loud attack\n"
# 639 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that can be used\n"
# 640 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "only while asleep.$"
# 641 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 642 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_MudSlapDesc::
# 643 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hurls mud in the\n"
# 644 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "foe's face to re-\n"
# 645 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "duce its accuracy.$"
# 646 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 647 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_SwiftDesc::
# 648 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Sprays star-\n"
# 649 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "shaped rays\n"
# 650 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that never miss.$"
# 651 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 652 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_IcyWindDesc::
# 653 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A chilling attack\n"
# 654 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that lowers the\n"
# 655 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "foe's Speed.$"
# 656 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 657 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_EndureDesc::
# 658 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Endures any at-\n"
# 659 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "tack for 1 turn,\n"
# 660 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "leaving 1HP.$"
# 661 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 662 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_PsychUpDesc::
# 663 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Copies the foe's\n"
# 664 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "effect(s) and\n"
# 665 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "gives to the user.$"
# 666 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 667 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_IcePunchDesc::
# 668 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "An icy punch\n"
# 669 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that may\n"
# 670 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "freeze the foe.$"
# 671 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 672 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ThunderPunchDesc::
# 673 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "An electrified\n"
# 674 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "punch that may\n"
# 675 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "paralyze the foe.$"
# 676 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 677 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_FirePunchDesc::
# 678 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A fiery punch\n"
# 679 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "that may burn\n"
# 680 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "the foe.$"
# 681 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 682 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ElementalTutorIntro::
# 683 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Zzzzzz…\p"
# 684 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What, how, what?\p"
# 685 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Oh, sorry, I was snoozing a bit.\p"
# 686 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm the Elemental Tutor.\p"
# 687 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I have the power to teach the most\n"
# 688 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "powerful moves to Grass, Fire and\l"
# 689 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Water Type Pokémon.\p"
# 690 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Did you come to learn such a strong\n"
# 691 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "power?$"
# 692 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 693 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack:
# 694 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Zzzzzz…\p"
# 695 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What, how, what, who?\p"
# 696 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Oh, did you come to learn the\n"
# 697 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "power of my strongest moves?$"
# 698 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 699 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_TeachWhichMoveElemental::
# 700 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Which move do you think is suitable\n"
# 701 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "for your Pokémon?$"
# 702 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 703 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_Text_StrongElementalMoveDesc::
# 704 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Powerful, but\n"
# 705 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "leaves the user\n"
# 706 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "immobile one turn.$"
# 707 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 708 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome::
# 709 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
# 710 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowBattlePointsWindow
# 711 "data/maps/TrainerHill_Courtyard/scripts.pory"
	return
# 712 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 713 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye::
# 714 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
# 715 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattlePointsWindow
# 716 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 717 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 718 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 719 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize::
# 720 "data/maps/TrainerHill_Courtyard/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 721 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize
# 722 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
# 723 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 724 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 725 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 726 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 727 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 728 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 729 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize::
# 730 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
# 731 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
# 732 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem
# 733 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 734 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 735 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor::
# 736 "data/maps/TrainerHill_Courtyard/scripts.pory"
	checkdecorspace VAR_0x8009
# 737 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor
# 738 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 739 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special TakeFrontierBattlePoints
# 740 "data/maps/TrainerHill_Courtyard/scripts.pory"
	adddecoration VAR_0x8009
# 741 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special UpdateBattlePointsWindow
# 742 "data/maps/TrainerHill_Courtyard/scripts.pory"
	playse SE_SHOP
# 743 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
# 744 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 745 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 746 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 747 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 748 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor::
# 749 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
# 750 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattlePointsWindow
# 751 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 752 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 753 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 754 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem::
# 755 "data/maps/TrainerHill_Courtyard/scripts.pory"
	checkitemspace VAR_0x8009
# 756 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull
# 757 "data/maps/TrainerHill_Courtyard/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 758 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special TakeFrontierBattlePoints
# 759 "data/maps/TrainerHill_Courtyard/scripts.pory"
	additem VAR_0x8009
# 760 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special UpdateBattlePointsWindow
# 761 "data/maps/TrainerHill_Courtyard/scripts.pory"
	playse SE_SHOP
# 762 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
# 763 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 764 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 765 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 766 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 767 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull::
# 768 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
# 769 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseBattlePointsWindow
# 770 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 771 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 772 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 773 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
# 774 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 775 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 776 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 777 "data/maps/TrainerHill_Courtyard/scripts.pory"
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
# 778 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 779 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 780 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 781 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1::
# 782 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
# 783 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 784 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 785 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 786 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 787 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 788 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster
# 789 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion
# 790 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll
# 791 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll
# 792 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll
# 793 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll
# 794 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll
# 795 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll
# 796 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll
# 797 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll
# 798 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 10, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 799 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 800 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 801 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 802 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster::
# 803 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
# 804 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 805 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 16
# 806 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_POSTER
# 807 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 808 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 809 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 810 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion::
# 811 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
# 812 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 813 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 32
# 814 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_CUSHION
# 815 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 816 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 817 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 818 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll::
# 819 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
# 820 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 821 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 32
# 822 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
# 823 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 824 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 825 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 826 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll::
# 827 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
# 828 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 829 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 830 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
# 831 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 832 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 833 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 834 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll::
# 835 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
# 836 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 837 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 838 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
# 839 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 840 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 841 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 842 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll::
# 843 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
# 844 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 845 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 846 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
# 847 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 848 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 849 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 850 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll::
# 851 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
# 852 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 853 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 854 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_DITTO_DOLL
# 855 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 856 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 857 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 858 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll::
# 859 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
# 860 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 861 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 80
# 862 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
# 863 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 864 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 865 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 866 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll::
# 867 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
# 868 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 869 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 80
# 870 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
# 871 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 872 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 873 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 874 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll::
# 875 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
# 876 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
# 877 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 80
# 878 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
# 879 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 880 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 881 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 882 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
# 883 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 884 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 885 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
# 886 "data/maps/TrainerHill_Courtyard/scripts.pory"
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
# 887 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 888 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 889 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 890 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2::
# 891 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
# 892 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 893 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 894 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 895 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 896 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 897 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll
# 898 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll
# 899 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll
# 900 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll
# 901 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll
# 902 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 903 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 904 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 905 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 906 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll::
# 907 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
# 908 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 909 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 128
# 910 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
# 911 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 912 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 913 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 914 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll::
# 915 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
# 916 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 917 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 128
# 918 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
# 919 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 920 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 921 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 922 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll::
# 923 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
# 924 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 925 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 256
# 926 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
# 927 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 928 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 929 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 930 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll::
# 931 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
# 932 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 933 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 256
# 934 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
# 935 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 936 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 937 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 938 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll::
# 939 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
# 940 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
# 941 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 256
# 942 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
# 943 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 944 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 945 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 946 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
# 947 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 948 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 949 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
# 950 "data/maps/TrainerHill_Courtyard/scripts.pory"
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
# 951 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 952 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 953 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 954 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin::
# 955 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
# 956 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 957 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 958 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 959 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 960 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 961 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein
# 962 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium
# 963 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron
# 964 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc
# 965 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos
# 966 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp
# 967 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 968 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 969 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 970 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 971 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
# 972 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
# 973 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 974 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 975 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 976 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 977 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein::
# 978 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
# 979 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 980 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 981 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_PROTEIN
# 982 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 983 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 984 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 985 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium::
# 986 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
# 987 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 988 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 989 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_CALCIUM
# 990 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 991 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 992 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 993 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron::
# 994 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
# 995 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 996 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 997 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_IRON
# 998 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 999 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1000 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1001 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc::
# 1002 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
# 1003 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 1004 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 1005 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_ZINC
# 1006 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1007 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1008 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1009 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos::
# 1010 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
# 1011 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 1012 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 1013 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_CARBOS
# 1014 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1015 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1016 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1017 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp::
# 1018 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
# 1019 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
# 1020 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 1
# 1021 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_HP_UP
# 1022 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1023 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1024 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1025 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
# 1026 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 1027 "data/maps/TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 1028 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
# 1029 "data/maps/TrainerHill_Courtyard/scripts.pory"
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
# 1030 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1031 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1032 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1033 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem::
# 1034 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
# 1035 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 1036 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special ShowScrollableMultichoice
# 1037 "data/maps/TrainerHill_Courtyard/scripts.pory"
	waitstate
# 1038 "data/maps/TrainerHill_Courtyard/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 1039 "data/maps/TrainerHill_Courtyard/scripts.pory"
	switch VAR_RESULT
# 1040 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers
# 1041 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb
# 1042 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw
# 1043 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb
# 1044 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder
# 1045 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand
# 1046 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock
# 1047 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand
# 1048 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens
# 1049 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 1050 "data/maps/TrainerHill_Courtyard/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 1051 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1052 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1053 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers::
# 1054 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
# 1055 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1056 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 1057 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_LEFTOVERS
# 1058 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1059 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1060 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1061 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb::
# 1062 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
# 1063 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1064 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 1065 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_WHITE_HERB
# 1066 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1067 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1068 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1069 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw::
# 1070 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
# 1071 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1072 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 1073 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_QUICK_CLAW
# 1074 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1075 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1076 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1077 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb::
# 1078 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
# 1079 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1080 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 48
# 1081 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_MENTAL_HERB
# 1082 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1083 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1084 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1085 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder::
# 1086 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
# 1087 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1088 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 1089 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
# 1090 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1091 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1092 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1093 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand::
# 1094 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
# 1095 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1096 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 1097 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_CHOICE_BAND
# 1098 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1099 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1100 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1101 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock::
# 1102 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
# 1103 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1104 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 1105 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_KINGS_ROCK
# 1106 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1107 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1108 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1109 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand::
# 1110 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
# 1111 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1112 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 1113 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_FOCUS_BAND
# 1114 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1115 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1116 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1117 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens::
# 1118 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
# 1119 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 1120 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8008, 64
# 1121 "data/maps/TrainerHill_Courtyard/scripts.pory"
	setvar VAR_0x8009, ITEM_SCOPE_LENS
# 1122 "data/maps/TrainerHill_Courtyard/scripts.pory"
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 1123 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1124 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1125 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
# 1126 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
# 1127 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1128 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1129 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
# 1130 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
# 1131 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1132 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1133 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
# 1134 "data/maps/TrainerHill_Courtyard/scripts.pory"
	lock
# 1135 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
# 1136 "data/maps/TrainerHill_Courtyard/scripts.pory"
	release
# 1137 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1138 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1139 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
# 1140 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
# 1141 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1142 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1143 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
# 1144 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
# 1145 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1146 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1147 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
# 1148 "data/maps/TrainerHill_Courtyard/scripts.pory"
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
# 1149 "data/maps/TrainerHill_Courtyard/scripts.pory"
	end
# 1150 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1151 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
# 1152 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You already have this item.$"
# 1153 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1154 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
# 1155 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hi! If you are looking for the\n"
# 1156 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Wondertrade, they're now located in\l"
# 1157 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "every Pokémon Center. Have fun!$"
# 1158 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1159 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
# 1160 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hello, this is the Exchange Service\n"
# 1161 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Corner.\p"
# 1162 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "We exchange the Battle Points you\n"
# 1163 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "have collected for lovely prizes.\p"
# 1164 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Please choose a prize from this list.$"
# 1165 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1166 "data/maps/TrainerHill_Courtyard/scripts.pory"
@ Unused
# 1167 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PleaseChoosePrize:
# 1168 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Please choose a prize from this list.$"
# 1169 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1170 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster:
# 1171 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Kiss Poster.\n"
# 1172 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1173 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1174 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion:
# 1175 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Kiss Cushion.\n"
# 1176 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1177 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1178 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
# 1179 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Smoochum Doll.\n"
# 1180 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1181 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1182 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
# 1183 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Togepi Doll.\n"
# 1184 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1185 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1186 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
# 1187 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Meowth Doll.\n"
# 1188 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1189 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1190 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
# 1191 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Clefairy Doll.\n"
# 1192 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1193 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1194 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll:
# 1195 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Ditto Doll.\n"
# 1196 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1197 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1198 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
# 1199 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Cyndaquil Doll.\n"
# 1200 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1201 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1202 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
# 1203 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Chikorita Doll.\n"
# 1204 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1205 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1206 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
# 1207 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Totodile Doll.\n"
# 1208 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1209 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1210 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
# 1211 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Lapras Doll.\n"
# 1212 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1213 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1214 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
# 1215 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Snorlax Doll.\n"
# 1216 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1217 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1218 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
# 1219 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Venusaur Doll.\n"
# 1220 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1221 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1222 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
# 1223 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Charizard Doll.\n"
# 1224 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1225 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1226 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
# 1227 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Blastoise Doll.\n"
# 1228 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1229 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1230 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein:
# 1231 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Protein.\n"
# 1232 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1233 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1234 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium:
# 1235 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Calcium.\n"
# 1236 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1237 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1238 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron:
# 1239 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Iron.\n"
# 1240 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1241 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1242 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc:
# 1243 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Zinc.\n"
# 1244 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1245 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1246 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos:
# 1247 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Carbos.\n"
# 1248 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1249 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1250 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp:
# 1251 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Hp Up.\n"
# 1252 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1253 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1254 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder:
# 1255 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Brightpowder.\n"
# 1256 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1257 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1258 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
# 1259 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the White Herb.\n"
# 1260 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1261 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1262 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw:
# 1263 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Quick Claw.\n"
# 1264 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1265 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1266 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb:
# 1267 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Mental Herb.\n"
# 1268 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1269 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1270 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand:
# 1271 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Choice Band.\n"
# 1272 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1273 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1274 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock:
# 1275 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the King's Rock.\n"
# 1276 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1277 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1278 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand:
# 1279 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Focus Band.\n"
# 1280 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1281 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1282 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens:
# 1283 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Scope Lens.\n"
# 1284 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1285 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1286 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers:
# 1287 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You've chosen the Leftovers.\n"
# 1288 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Is that correct?$"
# 1289 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1290 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC:
# 1291 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Thank you!\n"
# 1292 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 1293 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1294 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize:
# 1295 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Here is your prize!$"
# 1296 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1297 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
# 1298 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm so sorry…\n"
# 1299 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You don't have enough Battle Points…$"
# 1300 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1301 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull:
# 1302 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm so sorry…\n"
# 1303 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Your PC appears to be full…$"
# 1304 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1305 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
# 1306 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I'm so sorry…\n"
# 1307 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You don't have space to hold it…$"
# 1308 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1309 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
# 1310 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Thank you very much.\p"
# 1311 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Please visit us when you have\n"
# 1312 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "saved up Battle Points.$"
# 1313 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1314 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
# 1315 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Oh, they're so nice!\n"
# 1316 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I wish I had them!\l"
# 1317 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Cute cushions!\l"
# 1318 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Big plush Dolls!\l"
# 1319 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Little plush Dolls!\l"
# 1320 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I wish I had them all!$"
# 1321 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1322 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
# 1323 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Leave it to your mommy!\p"
# 1324 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "If it's anything you want, I'll go\n"
# 1325 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "through anything to get it, honey!$"
# 1326 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1327 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
# 1328 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "If I can get hold of the items here,\n"
# 1329 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "my Pokémon will get tougher.\p"
# 1330 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "You bet they will!\n"
# 1331 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "No question about it!$"
# 1332 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1333 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
# 1334 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hah?\n"
# 1335 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "What are you gawking at?\p"
# 1336 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "I don't like you staring at my plush\n"
# 1337 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "doll like that.\p"
# 1338 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "If you want it, go get one yourself!\n"
# 1339 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Isn't that right, Smoochum?$"
# 1340 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1341 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
# 1342 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Did you know?\p"
# 1343 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "If you stretch your record at any of\n"
# 1344 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "the Battle facilities, they start\l"
# 1345 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "giving you more and more Battle Points.$"
# 1346 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1347 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissPosterDesc::
# 1348 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A large poster with a Smoochum print.$"
# 1349 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1350 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissCushionDesc::
# 1351 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Smoochum cushion.\n"
# 1352 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1353 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1354 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_SmoochumDollDesc::
# 1355 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Smoochum Doll.\n"
# 1356 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1357 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1358 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_TogepiDollDesc::
# 1359 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Togepi Doll.\n"
# 1360 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1361 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1362 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_MeowthDollDesc::
# 1363 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Meowth Doll.\n"
# 1364 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1365 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1366 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ClefairyDollDesc::
# 1367 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Clefairy Doll.\n"
# 1368 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1369 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1370 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_DittoDollDesc::
# 1371 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Ditto Doll.\n"
# 1372 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1373 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1374 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_CyndaquilDollDesc::
# 1375 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Cyndaquil Doll.\n"
# 1376 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1377 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1378 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChikoritaDollDesc::
# 1379 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Chikorita Doll.\n"
# 1380 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1381 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1382 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_TotodileDollDesc::
# 1383 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A Totodile Doll.\n"
# 1384 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1385 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1386 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_LargeDollDesc::
# 1387 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A large Doll.\n"
# 1388 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1389 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1390 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ProteinDesc::
# 1391 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A strange ticket that will get\n"
# 1392 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "you to an abandoned island.$"
# 1393 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1394 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_CalciumDesc::
# 1395 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A strange ticket that will get\n"
# 1396 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "you to an abandoned island.$"
# 1397 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1398 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_IronDesc::
# 1399 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A strange ticket that will get\n"
# 1400 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "you to an abandoned island.$"
# 1401 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1402 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ZincDesc::
# 1403 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "An… old map? Maybe\n"
# 1404 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "it will get you somewhere.$"
# 1405 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1406 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_CarbosDesc::
# 1407 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "x10 EV gain, but halves speed.$"
# 1408 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1409 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_HPUpDesc::
# 1410 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A peculiar box made\n"
# 1411 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "by Silph Co.$"  
# 1412 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1413 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_LeftoversDesc::
# 1414 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that gradually restores\n"
# 1415 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Hp in battle.$"
# 1416 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1417 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_WhiteHerbDesc::
# 1418 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that restores any\n"
# 1419 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "lowered stat.$"
# 1420 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1421 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_QuickClawDesc::
# 1422 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that occasionally allows\n"
# 1423 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "the first strike.$"
# 1424 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1425 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_MentalHerbDesc::
# 1426 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that snaps Pokémon out\n"
# 1427 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "of infatuation.$"
# 1428 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1429 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_BrightpowderDesc::
# 1430 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that casts a glare to\n"
# 1431 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "reduce accuracy.$"
# 1432 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1433 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChoiceBandDesc::
# 1434 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "Raises a move's power, but permits\n"
# 1435 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "only that move.$"
# 1436 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1437 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_KingsRockDesc::
# 1438 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that may cause flinching\n"
# 1439 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "when the foe is hit.$"
# 1440 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1441 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_FocusBandDesc::
# 1442 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that occasionally\n"
# 1443 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "prevents fainting.$"
# 1444 "data/maps/TrainerHill_Courtyard/scripts.pory"

# 1445 "data/maps/TrainerHill_Courtyard/scripts.pory"
TrainerHill_Courtyard_ExchangeServiceCorner_Text_ScopeLensDesc::
# 1446 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "A hold item that raises the\n"
# 1447 "data/maps/TrainerHill_Courtyard/scripts.pory"
	.string "critical-hit rate.$"
