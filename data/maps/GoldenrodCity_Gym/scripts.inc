# 1 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 2 "data/maps/GoldenrodCity_Gym/scripts.pory"
.set LOCALID_GOLDENROD_CITY_GYM_BRIDGET, 6
# 3 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 4 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_MapScripts::
# 5 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.byte 0
# 6 "data/maps/GoldenrodCity_Gym/scripts.pory"
@Carrie, Bridget, Victoria, Samantha, gym guy
# 7 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 8 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 9 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Carrie::
# 10 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_CARRIE GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
# 11 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
# 12 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 13 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 14 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Bridget::
# 15 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRIDGET GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
# 16 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
# 17 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 18 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 19 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Victoria::
# 20 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VICTORIA GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
# 21 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
# 22 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 23 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 24 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Samantha::
# 25 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SAMANTHA GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
# 26 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
# 27 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 28 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 29 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Gym_Guy::
# 30 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 31 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 32 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
# 33 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
# 34 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 35 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 36 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 37 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 38 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Gym_Guy_After::
# 39 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
# 40 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 41 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 42 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 43 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 44 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Whitney::
# 45 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 46 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 47 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
# 48 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
# 49 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
# 50 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
# 51 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
# 52 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
# 53 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 3
# 54 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 55 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 56 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 57 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 58 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyCrying::
# 59 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 60 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 61 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
# 62 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 63 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 64 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 65 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 66 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyBadge::
# 67 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 68 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 69 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
# 70 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 71 "data/maps/GoldenrodCity_Gym/scripts.pory"
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
# 72 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmessage
# 73 "data/maps/GoldenrodCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 74 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
# 75 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 76 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
# 77 "data/maps/GoldenrodCity_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 78 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 79 "data/maps/GoldenrodCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 80 "data/maps/GoldenrodCity_Gym/scripts.pory"
	giveitem ITEM_TM_ATTRACT
# 81 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
# 82 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 5
# 83 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 84 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 85 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 86 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 87 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyDefeated::
# 88 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 89 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 90 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
# 91 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 92 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 93 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 94 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 95 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Trigger::	
# 96 "data/maps/GoldenrodCity_Gym/scripts.pory"
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
# 97 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
# 98 "data/maps/GoldenrodCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
# 99 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmovement 0
# 100 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 4
# 101 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 102 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 103 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 104 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 105 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 106 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Statue::
# 107 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 108 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
# 109 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 110 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 111 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 112 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 113 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 114 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Statue2::
# 115 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 116 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 117 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 118 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 119 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 120 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymStatue:
# 121 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Goldenrod POKéMON Gym$"
# 122 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 123 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymStatueCertified:
# 124 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Goldenrod Town POKéMON Gym\p"
# 125 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Whitney'S Certified Trainers:\n"
# 126 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 127 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 128 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyBefore:
# 129 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Hi! I'm Whitney!\p"
# 130 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Everyone was into POKéMON, so I got\n"
# 131 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "into it too!\p"
# 132 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "POKéMON are super-cute!\p"
# 133 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You want to battle? I'm warning\n"
# 134 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you- I'm good!$"
# 135 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 136 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
# 137 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Sob…\p"
# 138 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Waaaaaaah! You're mean!\p"
# 139 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You shouldn't be so serious! You…\n"
# 140 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you child, you!$"
# 141 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 142 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyYouMeanie:
# 143 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 144 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 145 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Snivel, hic… …You meanie!$"
# 146 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 147 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
# 148 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Sniff…\p"
# 149 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "What? What do you want? A Badge?\p"
# 150 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, right. I forgot. Here's\n"
# 151 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Plainbadge.$"
# 152 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 153 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
# 154 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "{PLAYER} received Plainbadge.$"
# 155 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 156 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyPlainBadge:
# 157 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Plainbadge lets your POKéMON use\n"
# 158 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Strength outside of battle.\p"
# 159 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It also boosts your POKéMON's\n"
# 160 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Defense.\p"
# 161 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, you can have this too!$"
# 162 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 163 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyAttract:
# 164 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's Attract! It makes full use of a\n"
# 165 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "POKéMON's charm.\p"
# 166 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Isn't it just perfect for a cutie\n"
# 167 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "like me?$"
# 168 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 169 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyGoodCry:
# 170 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Ah, that was a good cry!$"
# 171 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 172 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyRematch:
# 173 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Hi! It's you!\p"
# 174 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Wow, Johto Champion now?\p"
# 175 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You really are amazing!\p"
# 176 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I want to see how strong you are.\p"
# 177 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Want to have a rematch with me?$"
# 178 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 179 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
# 180 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 181 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 182 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Snivel, hic… …You meanie!$"
# 183 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 184 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieSeen:
# 185 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Don't let my POKéMON's cute looks\n"
# 186 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "fool you.\p"
# 187 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "They can whip you!$"
# 188 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 189 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieBeaten:
# 190 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Darn… I thought you were weak…$"
# 191 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 192 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieAfter:
# 193 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Do my POKéMON think I'm cute?$"
# 194 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 195 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetSeen:
# 196 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I like cute POKéMON better than\n"
# 197 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "strong POKéMON.\p"
# 198 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "But I have strong and cute POKéMON!$"
# 199 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 200 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetBeaten:
# 201 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, no, no, no!$"
# 202 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 203 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetAfter:
# 204 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I'm trying to beat Whitney, but…\n"
# 205 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's depressing.\p"
# 206 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I'm okay! If I lose, I'll just try\n"
# 207 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "harder next time!$"
# 208 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 209 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BridgetWhitneyCries:
# 210 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, no. You made Whitney cry.\p"
# 211 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's Ok. She'll stop soon. She\n"
# 212 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "always cries when she loses.$"
# 213 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 214 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
# 215 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, you are a cute little trainer!\p"
# 216 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I like you, but I won't hold back!$"
# 217 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 218 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
# 219 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Let's see… Oops, it's over?$"
# 220 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 221 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
# 222 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Wow, you must be good to beat me!\n"
# 223 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Keep it up!$"
# 224 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 225 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaSeen:
# 226 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Give it your best shot, or I'll take\n"
# 227 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you down!$"
# 228 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 229 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
# 230 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "No! Oh, Meowth, I'm so sorry!$"
# 231 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 232 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaAfter:
# 233 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I taught Meowth moves for taking on\n"
# 234 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "any type…$"
# 235 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 236 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymGuide:
# 237 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Yo! Champ in making!\p"
# 238 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "This Gym is home to Whitney, the\n"
# 239 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "master of Normal-type POKéMON.\p"
# 240 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Be cautious of her cute team.\p"
# 241 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Check Route 34 if you need a\n"
# 242 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Fighting-type POKéMON.$"
# 243 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 244 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymGuideWin:
# 245 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You won? Great! I was busy admiring\n"
# 246 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "the ladies here.$"

WhitneyMiltank::
# 251 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 252 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 253 "data/maps/GoldenrodCity_Gym/scripts.pory"
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
# 254 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox WhitneyMiltank_Text_0
# 255 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmoncry
# 256 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
	end


WhitneyMiltank_Text_0:
# 254 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Mooo!$"
