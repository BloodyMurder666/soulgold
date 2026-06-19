# 1 "data/maps/EcruteakCity_Gym/scripts.pory"

# 2 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_MapScripts::
# 3 "data/maps/EcruteakCity_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/EcruteakCity_Gym/scripts.pory"

# 5 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_GymGuy::
# 6 "data/maps/EcruteakCity_Gym/scripts.pory"
	lock
# 7 "data/maps/EcruteakCity_Gym/scripts.pory"
	faceplayer
# 8 "data/maps/EcruteakCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
# 9 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
# 10 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 11 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 12 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 13 "data/maps/EcruteakCity_Gym/scripts.pory"
	
# 14 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_GymGuy2::
# 15 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
# 16 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 17 "data/maps/EcruteakCity_Gym/scripts.pory"
	end	
# 18 "data/maps/EcruteakCity_Gym/scripts.pory"

# 19 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Jeffrey::
# 20 "data/maps/EcruteakCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
# 21 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
# 22 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 23 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Ping::
# 24 "data/maps/EcruteakCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
# 25 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
# 26 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 27 "data/maps/EcruteakCity_Gym/scripts.pory"

# 28 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Martha::
# 29 "data/maps/EcruteakCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
# 30 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
# 31 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 32 "data/maps/EcruteakCity_Gym/scripts.pory"

# 33 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Grace::
# 34 "data/maps/EcruteakCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
# 35 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
# 36 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 37 "data/maps/EcruteakCity_Gym/scripts.pory"

# 38 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Morty::
# 39 "data/maps/EcruteakCity_Gym/scripts.pory"
	lock
# 40 "data/maps/EcruteakCity_Gym/scripts.pory"
	faceplayer
# 41 "data/maps/EcruteakCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
# 42 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyIntroText, MSGBOX_DEFAULT
# 43 "data/maps/EcruteakCity_Gym/scripts.pory"
    trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
# 44 "data/maps/EcruteakCity_Gym/scripts.pory"
	message Text_ReceivedFogBadge
# 45 "data/maps/EcruteakCity_Gym/scripts.pory"
	waitmessage
# 46 "data/maps/EcruteakCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 47 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
# 48 "data/maps/EcruteakCity_Gym/scripts.pory"
	setflag FLAG_BADGE04_GET
# 49 "data/maps/EcruteakCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
# 50 "data/maps/EcruteakCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_RIVAL
# 51 "data/maps/EcruteakCity_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 52 "data/maps/EcruteakCity_Gym/scripts.pory"
	setvar VAR_0x8008, 4
# 53 "data/maps/EcruteakCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 54 "data/maps/EcruteakCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHADOW_BALL
# 55 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
# 56 "data/maps/EcruteakCity_Gym/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_STATE, 4
# 57 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 58 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 59 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 60 "data/maps/EcruteakCity_Gym/scripts.pory"

# 61 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Morty_Defeated::
# 62 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
# 63 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 64 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 65 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 66 "data/maps/EcruteakCity_Gym/scripts.pory"

# 67 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Statue::
# 68 "data/maps/EcruteakCity_Gym/scripts.pory"
	lock
# 69 "data/maps/EcruteakCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
# 70 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 71 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 72 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 73 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 74 "data/maps/EcruteakCity_Gym/scripts.pory"

# 75 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Statue2::
# 76 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 77 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 78 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 79 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 80 "data/maps/EcruteakCity_Gym/scripts.pory"

# 81 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_Text_GymStatue:
# 82 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ecruteak City Pokémon Gym$"
# 83 "data/maps/EcruteakCity_Gym/scripts.pory"

# 84 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_Text_GymStatueCertified:
# 85 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ecruteak City Pokémon Gym\p"
# 86 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Morty's Certified Trainers:\n"
# 87 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 88 "data/maps/EcruteakCity_Gym/scripts.pory"

# 89 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyIntroText:
# 90 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Good of you to have come.\p"
# 91 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Here in Ecruteak, Pokémon have\n"
# 92 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "always been revered.\p"
# 93 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It's said that a rainbow-colored\n"
# 94 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Pokémon will come down to\l"
# 95 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "appear before a true Trainer.\p"
# 96 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I believed that tale, so I've\n"
# 97 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "trained here in secret.\p"
# 98 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "As a result, I can now see what\n"
# 99 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "others cannot.\p"
# 100 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Just a bit more...\p"
# 101 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "With a little more, I could see\n"
# 102 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "a future where I meet the\l"
# 103 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "rainbow-colored Pokémon.\p"
# 104 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You're going to help me reach\n"
# 105 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "that level!$"
# 106 "data/maps/EcruteakCity_Gym/scripts.pory"

# 107 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyWinLossText:
# 108 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I'm not good enough yet...\p"
# 109 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "All right. This Badge is yours.$"
# 110 "data/maps/EcruteakCity_Gym/scripts.pory"

# 111 "data/maps/EcruteakCity_Gym/scripts.pory"
Text_ReceivedFogBadge:
# 112 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "{PLAYER} received the Fogbadge.$"
# 113 "data/maps/EcruteakCity_Gym/scripts.pory"

# 114 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyText_FogBadgeSpeech:
# 115 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "With the Fogbadge, Pokémon up\n"
# 116 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "to Level 50 will obey you.\p"
# 117 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Also, any Pokémon that knows\n"
# 118 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Surf will be able to use it\l"
# 119 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "anytime.\p"
# 120 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I want you to have this too.$"
# 121 "data/maps/EcruteakCity_Gym/scripts.pory"

# 122 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyText_ShadowBallSpeech:
# 123 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "That's Shadow Ball.\n"
# 124 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It causes damage and may\l"
# 125 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "lower Sp. Def.\p"
# 126 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Use it if it suits you.$"
# 127 "data/maps/EcruteakCity_Gym/scripts.pory"

# 128 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyFightDoneText:
# 129 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I see...\p"
# 130 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Your journey has taken you to\n"
# 131 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "far-off places.\p"
# 132 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've witnessed more than I\n"
# 133 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ever have.\p"
# 134 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I envy you for that...$"
# 135 "data/maps/EcruteakCity_Gym/scripts.pory"

# 136 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyRematchText:
# 137 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ah, the Johto Champion!\n"
# 138 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Good of you to come.\p"
# 139 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've shown strength and skill,\n"
# 140 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "but have you grown since we\l"
# 141 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "last battled?\p"
# 142 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I've trained with my Ghost-type\n"
# 143 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Pokémon ever since.\p"
# 144 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Let's see if you can overcome\n"
# 145 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "the shadows again.\p"
# 146 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Want to have a rematch?$"
# 147 "data/maps/EcruteakCity_Gym/scripts.pory"

# 148 "data/maps/EcruteakCity_Gym/scripts.pory"
Morty_RematchDefeatText:
# 149 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I'm not good enough yet...\p"
# 150 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've witnessed more than I\n"
# 151 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ever have.\p"
# 152 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I envy you for that...$"
# 153 "data/maps/EcruteakCity_Gym/scripts.pory"

# 154 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreySeenText:
# 155 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I spent the spring with my\n"
# 156 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Pokémon.\p"
# 157 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Then summer, fall, and winter...\p"
# 158 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Then spring came again.\n"
# 159 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "We've been together a long time.$"
# 160 "data/maps/EcruteakCity_Gym/scripts.pory"

# 161 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreyBeatenText:
# 162 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Wins and losses--I've known\n"
# 163 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "them both.$"
# 164 "data/maps/EcruteakCity_Gym/scripts.pory"

# 165 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreyAfterBattleText:
# 166 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Where did Pokémon come from?$"
# 167 "data/maps/EcruteakCity_Gym/scripts.pory"

# 168 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingSeenText:
# 169 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Can you inflict any damage\n"
# 170 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "on our Pokémon?$"
# 171 "data/maps/EcruteakCity_Gym/scripts.pory"

# 172 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingBeatenText:
# 173 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ah! Well done!$"
# 174 "data/maps/EcruteakCity_Gym/scripts.pory"

# 175 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingAfterBattleText:
# 176 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "We use Ghost-type Pokémon.\p"
# 177 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "No Normal-type attacks can\n"
# 178 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "harm them!$"
# 179 "data/maps/EcruteakCity_Gym/scripts.pory"

# 180 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaSeenText:
# 181 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I shall win!$"
# 182 "data/maps/EcruteakCity_Gym/scripts.pory"

# 183 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaBeatenText:
# 184 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I... I... I lost!$"
# 185 "data/maps/EcruteakCity_Gym/scripts.pory"

# 186 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaAfterBattleText:
# 187 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "The one who wants to win the\n"
# 188 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "most is the one who will!$"
# 189 "data/maps/EcruteakCity_Gym/scripts.pory"

# 190 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceSeenText:
# 191 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Stumped by our dark corridors?\n"
# 192 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Defeat me if you want a hint!$"
# 193 "data/maps/EcruteakCity_Gym/scripts.pory"

# 194 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceBeatenText:
# 195 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Wha-what?$"
# 196 "data/maps/EcruteakCity_Gym/scripts.pory"

# 197 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceAfterBattleText:
# 198 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Fine. I'll tell you the secret\n"
# 199 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "of the shadows.\p"
# 200 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "The path is right in front of\n"
# 201 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "your eyes!$"
# 202 "data/maps/EcruteakCity_Gym/scripts.pory"

# 203 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymGuideText:
# 204 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Hey Champ! You're almost\n"
# 205 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "halfway there!\p"
# 206 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Trainers here use Ghost- and\n"
# 207 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Dark-type Pokémon.\p"
# 208 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "While Morty is a Ghost-type\n"
# 209 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "expert, be wary of his mystic\l"
# 210 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "deer.\p"
# 211 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It's said to cause strange\n"
# 212 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "nightmares...$"
# 213 "data/maps/EcruteakCity_Gym/scripts.pory"

# 214 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymGuideWinText:
# 215 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Whew, {PLAYER}. You did great!\p"
# 216 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I was cowering in the corner\n"
# 217 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "out of pure terror!$"
# 218 "data/maps/EcruteakCity_Gym/scripts.pory"

# 219 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymClosedText:
# 220 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Morty, the Gym Leader, is\n"
# 221 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "absent.\p"
# 222 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to\n"
# 223 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "leave.\p"
# 224 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Hohohoho.$"
