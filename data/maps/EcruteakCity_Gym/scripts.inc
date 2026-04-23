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
	addvar VAR_NUM_BADGES, 1
# 51 "data/maps/EcruteakCity_Gym/scripts.pory"
	setvar VAR_0x8008, 4
# 52 "data/maps/EcruteakCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 53 "data/maps/EcruteakCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHADOW_BALL
# 54 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
# 55 "data/maps/EcruteakCity_Gym/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_STATE, 4
# 56 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 57 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 58 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 59 "data/maps/EcruteakCity_Gym/scripts.pory"

# 60 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Morty_Defeated::
# 61 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
# 62 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 63 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 64 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 65 "data/maps/EcruteakCity_Gym/scripts.pory"

# 66 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Statue::
# 67 "data/maps/EcruteakCity_Gym/scripts.pory"
	lock
# 68 "data/maps/EcruteakCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
# 69 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 70 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 71 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 72 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 73 "data/maps/EcruteakCity_Gym/scripts.pory"

# 74 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_EventScript_Statue2::
# 75 "data/maps/EcruteakCity_Gym/scripts.pory"
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 76 "data/maps/EcruteakCity_Gym/scripts.pory"
	closemessage
# 77 "data/maps/EcruteakCity_Gym/scripts.pory"
	release
# 78 "data/maps/EcruteakCity_Gym/scripts.pory"
	end
# 79 "data/maps/EcruteakCity_Gym/scripts.pory"

# 80 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_Text_GymStatue:
# 81 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ECRUTEAK CITY POKéMON GYM$"
# 82 "data/maps/EcruteakCity_Gym/scripts.pory"

# 83 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_Gym_Text_GymStatueCertified:
# 84 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ECRUTEAK CITY POKéMON GYM\p"
# 85 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "MORTY'S CERTIFIED TRAINERS:\n"
# 86 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 87 "data/maps/EcruteakCity_Gym/scripts.pory"

# 88 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyIntroText:
# 89 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Good of you to have come.\p"
# 90 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Here in ECRUTEAK, POKéMON have\n"
# 91 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "always been revered.\p"
# 92 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It's said that a rainbow-colored\n"
# 93 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "POKéMON will come down to\l"
# 94 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "appear before a true Trainer.\p"
# 95 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I believed that tale, so I've\n"
# 96 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "trained here in secret.\p"
# 97 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "As a result, I can now see what\n"
# 98 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "others cannot.\p"
# 99 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Just a bit more...\p"
# 100 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "With a little more, I could see\n"
# 101 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "a future where I meet the\l"
# 102 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "rainbow-colored POKéMON.\p"
# 103 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You're going to help me reach\n"
# 104 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "that level!$"
# 105 "data/maps/EcruteakCity_Gym/scripts.pory"

# 106 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyWinLossText:
# 107 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I'm not good enough yet...\p"
# 108 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "All right. This BADGE is yours.$"
# 109 "data/maps/EcruteakCity_Gym/scripts.pory"

# 110 "data/maps/EcruteakCity_Gym/scripts.pory"
Text_ReceivedFogBadge:
# 111 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "{PLAYER} received the FOGBADGE.$"
# 112 "data/maps/EcruteakCity_Gym/scripts.pory"

# 113 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyText_FogBadgeSpeech:
# 114 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "With the FOGBADGE, POKéMON up\n"
# 115 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "to Level 50 will obey you.\p"
# 116 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Also, any POKéMON that knows\n"
# 117 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "SURF will be able to use it\l"
# 118 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "anytime.\p"
# 119 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I want you to have this too.$"
# 120 "data/maps/EcruteakCity_Gym/scripts.pory"

# 121 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyText_ShadowBallSpeech:
# 122 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "That's SHADOW BALL.\n"
# 123 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It causes damage and may\l"
# 124 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "lower SP. DEF.\p"
# 125 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Use it if it suits you.$"
# 126 "data/maps/EcruteakCity_Gym/scripts.pory"

# 127 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyFightDoneText:
# 128 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I see...\p"
# 129 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Your journey has taken you to\n"
# 130 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "far-off places.\p"
# 131 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've witnessed more than I\n"
# 132 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ever have.\p"
# 133 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I envy you for that...$"
# 134 "data/maps/EcruteakCity_Gym/scripts.pory"

# 135 "data/maps/EcruteakCity_Gym/scripts.pory"
MortyRematchText:
# 136 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ah, the JOHTO CHAMPION!\n"
# 137 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Good of you to come.\p"
# 138 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've shown strength and skill,\n"
# 139 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "but have you grown since we\l"
# 140 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "last battled?\p"
# 141 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I've trained with my GHOST-type\n"
# 142 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "POKéMON ever since.\p"
# 143 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Let's see if you can overcome\n"
# 144 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "the shadows again.\p"
# 145 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Want to have a rematch?$"
# 146 "data/maps/EcruteakCity_Gym/scripts.pory"

# 147 "data/maps/EcruteakCity_Gym/scripts.pory"
Morty_RematchDefeatText:
# 148 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I'm not good enough yet...\p"
# 149 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "You've witnessed more than I\n"
# 150 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "ever have.\p"
# 151 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I envy you for that...$"
# 152 "data/maps/EcruteakCity_Gym/scripts.pory"

# 153 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreySeenText:
# 154 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I spent the spring with my\n"
# 155 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "POKéMON.\p"
# 156 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Then summer, fall, and winter...\p"
# 157 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Then spring came again.\n"
# 158 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "We've been together a long time.$"
# 159 "data/maps/EcruteakCity_Gym/scripts.pory"

# 160 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreyBeatenText:
# 161 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Wins and losses--I've known\n"
# 162 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "them both.$"
# 163 "data/maps/EcruteakCity_Gym/scripts.pory"

# 164 "data/maps/EcruteakCity_Gym/scripts.pory"
SageJeffreyAfterBattleText:
# 165 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Where did POKéMON come from?$"
# 166 "data/maps/EcruteakCity_Gym/scripts.pory"

# 167 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingSeenText:
# 168 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Can you inflict any damage\n"
# 169 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "on our POKéMON?$"
# 170 "data/maps/EcruteakCity_Gym/scripts.pory"

# 171 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingBeatenText:
# 172 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Ah! Well done!$"
# 173 "data/maps/EcruteakCity_Gym/scripts.pory"

# 174 "data/maps/EcruteakCity_Gym/scripts.pory"
SagePingAfterBattleText:
# 175 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "We use GHOST-type POKéMON.\p"
# 176 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "No NORMAL-type attacks can\n"
# 177 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "harm them!$"
# 178 "data/maps/EcruteakCity_Gym/scripts.pory"

# 179 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaSeenText:
# 180 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I shall win!$"
# 181 "data/maps/EcruteakCity_Gym/scripts.pory"

# 182 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaBeatenText:
# 183 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I... I... I lost!$"
# 184 "data/maps/EcruteakCity_Gym/scripts.pory"

# 185 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumMarthaAfterBattleText:
# 186 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "The one who wants to win the\n"
# 187 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "most is the one who will!$"
# 188 "data/maps/EcruteakCity_Gym/scripts.pory"

# 189 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceSeenText:
# 190 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Stumped by our dark corridors?\n"
# 191 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Defeat me if you want a hint!$"
# 192 "data/maps/EcruteakCity_Gym/scripts.pory"

# 193 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceBeatenText:
# 194 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Wha-what?$"
# 195 "data/maps/EcruteakCity_Gym/scripts.pory"

# 196 "data/maps/EcruteakCity_Gym/scripts.pory"
MediumGraceAfterBattleText:
# 197 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Fine. I'll tell you the secret\n"
# 198 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "of the shadows.\p"
# 199 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "The path is right in front of\n"
# 200 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "your eyes!$"
# 201 "data/maps/EcruteakCity_Gym/scripts.pory"

# 202 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymGuideText:
# 203 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Hey CHAMP! You're almost\n"
# 204 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "halfway there!\p"
# 205 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Trainers here use GHOST- and\n"
# 206 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "DARK-type POKéMON.\p"
# 207 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "While MORTY is a GHOST-type\n"
# 208 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "expert, be wary of his mystic\l"
# 209 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "deer.\p"
# 210 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "It's said to cause strange\n"
# 211 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "nightmares...$"
# 212 "data/maps/EcruteakCity_Gym/scripts.pory"

# 213 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymGuideWinText:
# 214 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Whew, {PLAYER}. You did great!\p"
# 215 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "I was cowering in the corner\n"
# 216 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "out of pure terror!$"
# 217 "data/maps/EcruteakCity_Gym/scripts.pory"

# 218 "data/maps/EcruteakCity_Gym/scripts.pory"
EcruteakCity_GymClosedText:
# 219 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "MORTY, the GYM LEADER, is\n"
# 220 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "absent.\p"
# 221 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to\n"
# 222 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "leave.\p"
# 223 "data/maps/EcruteakCity_Gym/scripts.pory"
	.string "Hohohoho.$"
