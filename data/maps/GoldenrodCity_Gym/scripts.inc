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
	call WhitneyChooseDifficulty
# 51 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
# 52 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 3
# 53 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 54 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 55 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 56 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 57 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyCrying::
# 58 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 59 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 60 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
# 61 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 62 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 63 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 64 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 65 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyBadge::
# 66 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 67 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 68 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
# 69 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 70 "data/maps/GoldenrodCity_Gym/scripts.pory"
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
# 71 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmessage
# 72 "data/maps/GoldenrodCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 73 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
# 74 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 75 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
# 76 "data/maps/GoldenrodCity_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 77 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 78 "data/maps/GoldenrodCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 79 "data/maps/GoldenrodCity_Gym/scripts.pory"
	giveitem ITEM_TM_ATTRACT
# 80 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
# 81 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 5
# 82 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 83 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 84 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 85 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 86 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_WhitneyDefeated::
# 87 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 88 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 89 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
# 90 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 91 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 92 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 93 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 94 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Trigger::	
# 95 "data/maps/GoldenrodCity_Gym/scripts.pory"
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
# 96 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
# 97 "data/maps/GoldenrodCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
# 98 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmovement 0
# 99 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 4
# 100 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 101 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 102 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 103 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 104 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 105 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Statue::
# 106 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 107 "data/maps/GoldenrodCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
# 108 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 109 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 110 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 111 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 112 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 113 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_EventScript_Statue2::
# 114 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 115 "data/maps/GoldenrodCity_Gym/scripts.pory"
	closemessage
# 116 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
# 117 "data/maps/GoldenrodCity_Gym/scripts.pory"
	end
# 118 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 119 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymStatue:
# 120 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "GOLDENROD POKéMON GYM$"
# 121 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 122 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymStatueCertified:
# 123 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "GOLDENROD TOWN POKéMON GYM\p"
# 124 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "WHITNEY'S CERTIFIED TRAINERS:\n"
# 125 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 126 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 127 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyBefore:
# 128 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Hi! I'm WHITNEY!\p"
# 129 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Everyone was into POKéMON, so I got\n"
# 130 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "into it too!\p"
# 131 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "POKéMON are super-cute!\p"
# 132 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You want to battle? I'm warning\n"
# 133 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you- I'm good!$"
# 134 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 135 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
# 136 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Sob…\p"
# 137 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Waaaaaaah! You're mean!\p"
# 138 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You shouldn't be so serious! You…\n"
# 139 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you child, you!$"
# 140 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 141 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyYouMeanie:
# 142 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 143 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 144 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Snivel, hic… …You meanie!$"
# 145 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 146 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
# 147 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Sniff…\p"
# 148 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "What? What do you want? A BADGE?\p"
# 149 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, right. I forgot. Here's\n"
# 150 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "PLAINBADGE.$"
# 151 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 152 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
# 153 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "{PLAYER} received PLAINBADGE.$"
# 154 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 155 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyPlainBadge:
# 156 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "PLAINBADGE lets your POKéMON use\n"
# 157 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "STRENGTH outside of battle.\p"
# 158 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It also boosts your POKéMON's\n"
# 159 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "DEFENSE.\p"
# 160 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, you can have this too!$"
# 161 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 162 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyAttract:
# 163 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's ATTRACT! It makes full use of a\n"
# 164 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "POKéMON's charm.\p"
# 165 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Isn't it just perfect for a cutie\n"
# 166 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "like me?$"
# 167 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 168 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyGoodCry:
# 169 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Ah, that was a good cry!$"
# 170 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 171 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyRematch:
# 172 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Hi! It's you!\p"
# 173 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Wow, JOHTO CHAMPION now?\p"
# 174 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You really are amazing!\p"
# 175 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I want to see how strong you are.\p"
# 176 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Want to have a rematch with me?$"
# 177 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 178 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
# 179 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 180 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Waaaaah!\p"
# 181 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "…Snivel, hic… …You meanie!$"
# 182 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 183 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieSeen:
# 184 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Don't let my POKéMON's cute looks\n"
# 185 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "fool you.\p"
# 186 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "They can whip you!$"
# 187 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 188 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieBeaten:
# 189 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Darn… I thought you were weak…$"
# 190 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 191 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassCarrieAfter:
# 192 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Do my POKéMON think I'm cute?$"
# 193 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 194 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetSeen:
# 195 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I like cute POKéMON better than\n"
# 196 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "strong POKéMON.\p"
# 197 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "But I have strong and cute POKéMON!$"
# 198 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 199 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetBeaten:
# 200 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, no, no, no!$"
# 201 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 202 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_LassBridgetAfter:
# 203 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I'm trying to beat WHITNEY, but…\n"
# 204 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's depressing.\p"
# 205 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I'm okay! If I lose, I'll just try\n"
# 206 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "harder next time!$"
# 207 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 208 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BridgetWhitneyCries:
# 209 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, no. You made WHITNEY cry.\p"
# 210 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "It's OK. She'll stop soon. She\n"
# 211 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "always cries when she loses.$"
# 212 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 213 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
# 214 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Oh, you are a cute little trainer!\p"
# 215 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I like you, but I won't hold back!$"
# 216 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 217 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
# 218 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Let's see… Oops, it's over?$"
# 219 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 220 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
# 221 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Wow, you must be good to beat me!\n"
# 222 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Keep it up!$"
# 223 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 224 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaSeen:
# 225 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Give it your best shot, or I'll take\n"
# 226 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "you down!$"
# 227 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 228 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
# 229 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "No! Oh, MEOWTH, I'm so sorry!$"
# 230 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 231 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_BeautySamanthaAfter:
# 232 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "I taught MEOWTH moves for taking on\n"
# 233 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "any type…$"
# 234 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 235 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymGuide:
# 236 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Yo! CHAMP in making!\p"
# 237 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "This GYM is home to WHITNEY, the\n"
# 238 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "master of NORMAL-type POKéMON.\p"
# 239 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Be cautious of her cute team.\p"
# 240 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "Check ROUTE 34 if you need a\n"
# 241 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "FIGHTING-type POKéMON.$"
# 242 "data/maps/GoldenrodCity_Gym/scripts.pory"

# 243 "data/maps/GoldenrodCity_Gym/scripts.pory"
GoldenrodCity_Gym_Text_GymGuideWin:
# 244 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "You won? Great! I was busy admiring\n"
# 245 "data/maps/GoldenrodCity_Gym/scripts.pory"
    .string "the ladies here.$"

WhitneyChooseDifficulty::
# 250 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox WhitneyChooseDifficulty_Text_0
# 256 "data/maps/GoldenrodCity_Gym/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, WhitneyChooseDifficulty_Text_1, WhitneyChooseDifficulty_Text_2, WhitneyChooseDifficulty_Text_3
# 257 "data/maps/GoldenrodCity_Gym/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/GoldenrodCity_Gym/scripts.pory"
	case 0, WhitneyChooseDifficulty_3
# 262 "data/maps/GoldenrodCity_Gym/scripts.pory"
	case 1, WhitneyChooseDifficulty_4
# 267 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
	end

	return

WhitneyChooseDifficulty_3:
# 259 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setdifficulty DIFFICULTY_NORMAL
# 260 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	return

WhitneyChooseDifficulty_4:
# 263 "data/maps/GoldenrodCity_Gym/scripts.pory"
	setdifficulty DIFFICULTY_HARD
# 264 "data/maps/GoldenrodCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	return


WhitneyMiltank::
# 274 "data/maps/GoldenrodCity_Gym/scripts.pory"
	lock
# 275 "data/maps/GoldenrodCity_Gym/scripts.pory"
	faceplayer
# 276 "data/maps/GoldenrodCity_Gym/scripts.pory"
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
# 277 "data/maps/GoldenrodCity_Gym/scripts.pory"
	msgbox WhitneyMiltank_Text_0
# 278 "data/maps/GoldenrodCity_Gym/scripts.pory"
	waitmoncry
# 279 "data/maps/GoldenrodCity_Gym/scripts.pory"
	release
	end


WhitneyChooseDifficulty_Text_0:
# 250 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Hi I'm Whitney!\n"
	.string "Everyone was into Pokémon so I got\l"
	.string "into it too!\l"
	.string "Pokémon are super cute!\l"
	.string "You want to battle? Do you want to do\l"
	.string "against my normal team or bestie team?$"

WhitneyChooseDifficulty_Text_1:
# 256 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Regular$"

WhitneyChooseDifficulty_Text_2:
# 256 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Hard$"

WhitneyChooseDifficulty_Text_3:
# 256 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Cancel$"

WhitneyMiltank_Text_0:
# 277 "data/maps/GoldenrodCity_Gym/scripts.pory"
	.string "Mooo!$"
