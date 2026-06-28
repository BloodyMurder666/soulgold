# 1 "data/maps/MahoganyTown_Gym/scripts.pory"

# 2 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_MapScripts::
# 3 "data/maps/MahoganyTown_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/MahoganyTown_Gym/scripts.pory"

# 5 "data/maps/MahoganyTown_Gym/scripts.pory"

# 6 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Statue::
# 7 "data/maps/MahoganyTown_Gym/scripts.pory"
	lock
# 8 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
# 9 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 10 "data/maps/MahoganyTown_Gym/scripts.pory"
	closemessage
# 11 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 12 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 13 "data/maps/MahoganyTown_Gym/scripts.pory"

# 14 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Statue2::
# 15 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 16 "data/maps/MahoganyTown_Gym/scripts.pory"
	closemessage
# 17 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 18 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 19 "data/maps/MahoganyTown_Gym/scripts.pory"

# 20 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_GymStatue:
# 21 "data/maps/MahoganyTown_Gym/scripts.pory"
	.string "Mahogany Town Pokémon Gym$"
# 22 "data/maps/MahoganyTown_Gym/scripts.pory"

# 23 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_GymStatueCertified:
# 24 "data/maps/MahoganyTown_Gym/scripts.pory"
	.string "Mahogany Town Pokémon Gym\p"
# 25 "data/maps/MahoganyTown_Gym/scripts.pory"
	.string "Pryce's Certified Trainers:\n"
# 26 "data/maps/MahoganyTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 27 "data/maps/MahoganyTown_Gym/scripts.pory"

# 28 "data/maps/MahoganyTown_Gym/scripts.pory"

# 29 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_GymEventScript_GymGuy::
# 30 "data/maps/MahoganyTown_Gym/scripts.pory"
	lock
# 31 "data/maps/MahoganyTown_Gym/scripts.pory"
	faceplayer
# 32 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
# 33 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
# 34 "data/maps/MahoganyTown_Gym/scripts.pory"
	closemessage
# 35 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 36 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 37 "data/maps/MahoganyTown_Gym/scripts.pory"
	
# 38 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_GymGuy2::
# 39 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
# 40 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 41 "data/maps/MahoganyTown_Gym/scripts.pory"
	end	
# 42 "data/maps/MahoganyTown_Gym/scripts.pory"

# 43 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Ronald::
# 44 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
# 45 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
# 46 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 47 "data/maps/MahoganyTown_Gym/scripts.pory"

# 48 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Brad::
# 49 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
# 50 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
# 51 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 52 "data/maps/MahoganyTown_Gym/scripts.pory"

# 53 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Douglas::
# 54 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
# 55 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
# 56 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 57 "data/maps/MahoganyTown_Gym/scripts.pory"

# 58 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Roxanne::
# 59 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
# 60 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
# 61 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 62 "data/maps/MahoganyTown_Gym/scripts.pory"

# 63 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Clarissa::
# 64 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
# 65 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
# 66 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 67 "data/maps/MahoganyTown_Gym/scripts.pory"

# 68 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Pryce::
# 69 "data/maps/MahoganyTown_Gym/scripts.pory"
	lock
# 70 "data/maps/MahoganyTown_Gym/scripts.pory"
	faceplayer
# 71 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
# 72 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
# 73 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
# 74 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
# 75 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1
# 76 "data/maps/MahoganyTown_Gym/scripts.pory"

# 77 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_PryceVictory::
# 78 "data/maps/MahoganyTown_Gym/scripts.pory"
	message MahoganyTown_Gym_Text_ReceivedBadge
# 79 "data/maps/MahoganyTown_Gym/scripts.pory"
	waitmessage
# 80 "data/maps/MahoganyTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 81 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
# 82 "data/maps/MahoganyTown_Gym/scripts.pory"
	setflag FLAG_BADGE07_GET
# 83 "data/maps/MahoganyTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
# 84 "data/maps/MahoganyTown_Gym/scripts.pory"
    addvar VAR_NUM_BADGES, 1
# 85 "data/maps/MahoganyTown_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 86 "data/maps/MahoganyTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 87 "data/maps/MahoganyTown_Gym/scripts.pory"
	giveitem ITEM_TM_HAIL
# 88 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
# 89 "data/maps/MahoganyTown_Gym/scripts.pory"
	setvar VAR_MAHOGANY_TOWN_STATE, 15
# 90 "data/maps/MahoganyTown_Gym/scripts.pory"
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
# 91 "data/maps/MahoganyTown_Gym/scripts.pory"
	closemessage
# 92 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 93 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 94 "data/maps/MahoganyTown_Gym/scripts.pory"

# 95 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
# 96 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
# 97 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
# 98 "data/maps/MahoganyTown_Gym/scripts.pory"

# 99 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
# 100 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
# 101 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
# 102 "data/maps/MahoganyTown_Gym/scripts.pory"
	
# 103 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Pryce_Battle1::
# 104 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_PRYCE_1, MahoganyTown_Gym_Text_PryceImpressed
# 105 "data/maps/MahoganyTown_Gym/scripts.pory"
    setflag FLAG_RECEIVED_BADGE_5
# 106 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_PryceVictory
# 107 "data/maps/MahoganyTown_Gym/scripts.pory"

# 108 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Pryce_Battle2::
# 109 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_PRYCE_1_2, MahoganyTown_Gym_Text_PryceImpressed
# 110 "data/maps/MahoganyTown_Gym/scripts.pory"
    setflag FLAG_RECEIVED_BADGE_6
# 111 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_PryceVictory
# 112 "data/maps/MahoganyTown_Gym/scripts.pory"

# 113 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Pryce_Battle3::
# 114 "data/maps/MahoganyTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_PRYCE_1_3, MahoganyTown_Gym_Text_PryceImpressed
# 115 "data/maps/MahoganyTown_Gym/scripts.pory"
    setflag FLAG_RECEIVED_BADGE_7
# 116 "data/maps/MahoganyTown_Gym/scripts.pory"
	goto MahoganyTown_Gym_EventScript_PryceVictory
# 117 "data/maps/MahoganyTown_Gym/scripts.pory"

# 118 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_EventScript_Pryce_Defeated::
# 119 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
# 120 "data/maps/MahoganyTown_Gym/scripts.pory"
	closemessage
# 121 "data/maps/MahoganyTown_Gym/scripts.pory"
	release
# 122 "data/maps/MahoganyTown_Gym/scripts.pory"
	end
# 123 "data/maps/MahoganyTown_Gym/scripts.pory"

# 124 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_PryceIntro:
# 125 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pokémon have many experiences\n"
# 126 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "in their lives, just like we do.\p"
# 127 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I, too, have seen and suffered\n"
# 128 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "much in my life.\p"
# 129 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Since I am your elder, let me\n"
# 130 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "show you what I mean.\p"
# 131 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I have been with Pokémon since\n"
# 132 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "before you were born.\p"
# 133 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I do not lose easily.\p"
# 134 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I, Pryce--the winter trainer--\n"
# 135 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "shall demonstrate my power!$"
# 136 "data/maps/MahoganyTown_Gym/scripts.pory"

# 137 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_PryceImpressed:
# 138 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Ah, I am impressed by your\n"
# 139 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "prowess.\p"
# 140 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "With your strong will, I know you\n"
# 141 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "will overcome all life's obstacles.\p"
# 142 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "You are worthy of this Badge!$"
# 143 "data/maps/MahoganyTown_Gym/scripts.pory"

# 144 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_ReceivedBadge:
# 145 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "{PLAYER} received Glacierbadge.$"
# 146 "data/maps/MahoganyTown_Gym/scripts.pory"

# 147 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_GlacierBadgeSpeech:
# 148 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "That Badge lets your Pokémon use\n"
# 149 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Whirlpool to get across\l"
# 150 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "real whirlpools.\p"
# 151 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "And this… This is a gift from me!$"
# 152 "data/maps/MahoganyTown_Gym/scripts.pory"

# 153 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_HailSpeech:
# 154 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "That TM contains Hail.\p"
# 155 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "It inflicts damage every\n"
# 156 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "turn for 5 turns.\p"
# 157 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "It demonstrates the harshness\n"
# 158 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "of winter.$"
# 159 "data/maps/MahoganyTown_Gym/scripts.pory"

# 160 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_CherishPokemon:
# 161 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "When the ice and snow melt,\n"
# 162 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "spring arrives.\p"
# 163 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "You and your Pokémon will be\n"
# 164 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "together for many years to come.\p"
# 165 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Cherish your time together!$"
# 166 "data/maps/MahoganyTown_Gym/scripts.pory"

# 167 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_PryceRematch:
# 168 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Ah, Johto Champion!\p"
# 169 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Your skills are indeed\n"
# 170 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "remarkable.\p"
# 171 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I am impressed.\p"
# 172 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "But even now, there is much to\n"
# 173 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "learn from each other.\p"
# 174 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I, Pryce--the winter trainer--\n"
# 175 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "still have a few tricks left.\p"
# 176 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Want to have a rematch with me?$"
# 177 "data/maps/MahoganyTown_Gym/scripts.pory"

# 178 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_PryceRematchDefeat:
# 179 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Ah, yet again I'm impressed by\n"
# 180 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "your prowess.\p"
# 181 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "With your strong will, I know you\n"
# 182 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "will overcome all life's obstacles.$"
# 183 "data/maps/MahoganyTown_Gym/scripts.pory"

# 184 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_Guide:
# 185 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pryce is a veteran who has\n"
# 186 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "trained Pokémon for some 50 years.\p"
# 187 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "He's got a solid lineup of\n"
# 188 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pokémon to cover whatever\l"
# 189 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "you bring his way.\p"
# 190 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Fire is a good place to start,\n"
# 191 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "but watch out for the rain!$"
# 192 "data/maps/MahoganyTown_Gym/scripts.pory"

# 193 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_GuideWin:
# 194 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pryce is something, but you're\n"
# 195 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "something else!\p"
# 196 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "That was a hot battle that\n"
# 197 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "bridged the generation gap!$"
# 198 "data/maps/MahoganyTown_Gym/scripts.pory"

# 199 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderRonaldSeen:
# 200 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I'll freeze your Pokémon,\n"
# 201 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "so you can't do a thing!$"
# 202 "data/maps/MahoganyTown_Gym/scripts.pory"

# 203 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderRonaldBeaten:
# 204 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Darn. I couldn't do a thing.$"
# 205 "data/maps/MahoganyTown_Gym/scripts.pory"

# 206 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderRonaldAfter:
# 207 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I think there's a move a\n"
# 208 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pokémon can use while it's\l"
# 209 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "frozen.$"
# 210 "data/maps/MahoganyTown_Gym/scripts.pory"

# 211 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderBradSeen:
# 212 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "This Gym has a slippery floor.\p"
# 213 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "It's fun, isn't it?\p"
# 214 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "But hey--we're not playing\n"
# 215 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "games here!$"
# 216 "data/maps/MahoganyTown_Gym/scripts.pory"

# 217 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderBradBeaten:
# 218 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Do you see how serious we are?$"
# 219 "data/maps/MahoganyTown_Gym/scripts.pory"

# 220 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderBradAfter:
# 221 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "This Gym is great.\n"
# 222 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I love boarding with my\l"
# 223 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Pokémon!$"
# 224 "data/maps/MahoganyTown_Gym/scripts.pory"

# 225 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderDouglasSeen:
# 226 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I know Pryce's secret.$"
# 227 "data/maps/MahoganyTown_Gym/scripts.pory"

# 228 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderDouglasBeaten:
# 229 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Ok. I'll tell you Pryce's secret.$"
# 230 "data/maps/MahoganyTown_Gym/scripts.pory"

# 231 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_BoarderDouglasAfter:
# 232 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "The secret behind Pryce's power…\p"
# 233 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "He meditates under a waterfall\n"
# 234 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "daily to strengthen his mind\l"
# 235 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "and body.$"
# 236 "data/maps/MahoganyTown_Gym/scripts.pory"

# 237 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierRoxanneSeen:
# 238 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "To get to Pryce, our Gym Leader,\n"
# 239 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "you need to think before you skate.$"
# 240 "data/maps/MahoganyTown_Gym/scripts.pory"

# 241 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierRoxanneBeaten:
# 242 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I wouldn't lose to you in skiing!$"
# 243 "data/maps/MahoganyTown_Gym/scripts.pory"

# 244 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierRoxanneAfter:
# 245 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "If you don't skate with precision,\n"
# 246 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "you won't get far in this Gym.$"
# 247 "data/maps/MahoganyTown_Gym/scripts.pory"

# 248 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierClarissaSeen:
# 249 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "Check out my parallel turn!$"
# 250 "data/maps/MahoganyTown_Gym/scripts.pory"

# 251 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierClarissaBeaten:
# 252 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "No! You made me wipe out!$"
# 253 "data/maps/MahoganyTown_Gym/scripts.pory"

# 254 "data/maps/MahoganyTown_Gym/scripts.pory"
MahoganyTown_Gym_Text_SkierClarissaAfter:
# 255 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "I shouldn't have been bragging\n"
# 256 "data/maps/MahoganyTown_Gym/scripts.pory"
    .string "about my skiing…$"

MahoganyTown_Gym_EventScript_Froslass::
# 261 "data/maps/MahoganyTown_Gym/scripts.pory"
	playmoncry SPECIES_FROSLASS, CRY_MODE_NORMAL
# 262 "data/maps/MahoganyTown_Gym/scripts.pory"
	msgbox MahoganyTown_Gym_EventScript_Froslass_Text_0, MSGBOX_NPC
	return


MahoganyTown_Gym_EventScript_Froslass_Text_0:
# 262 "data/maps/MahoganyTown_Gym/scripts.pory"
	.string "Fross!!$"
