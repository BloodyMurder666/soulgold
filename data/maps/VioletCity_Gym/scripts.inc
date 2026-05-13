# 1 "data/maps/VioletCity_Gym/scripts.pory"

# 2 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_MapScripts::
# 3 "data/maps/VioletCity_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/VioletCity_Gym/scripts.pory"

# 5 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_GymGuy::
# 6 "data/maps/VioletCity_Gym/scripts.pory"
	lock
# 7 "data/maps/VioletCity_Gym/scripts.pory"
	faceplayer
# 8 "data/maps/VioletCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
# 9 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
# 10 "data/maps/VioletCity_Gym/scripts.pory"
	closemessage
# 11 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 12 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 13 "data/maps/VioletCity_Gym/scripts.pory"
	
# 14 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_GymGuy2::
# 15 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
# 16 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 17 "data/maps/VioletCity_Gym/scripts.pory"
	end	
# 18 "data/maps/VioletCity_Gym/scripts.pory"

# 19 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Rod::
# 20 "data/maps/VioletCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROD VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
# 21 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
# 22 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 23 "data/maps/VioletCity_Gym/scripts.pory"

# 24 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Abe::
# 25 "data/maps/VioletCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ABE VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
# 26 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
# 27 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 28 "data/maps/VioletCity_Gym/scripts.pory"

# 29 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Falkner::
# 30 "data/maps/VioletCity_Gym/scripts.pory"
	lock
# 31 "data/maps/VioletCity_Gym/scripts.pory"
	faceplayer
# 32 "data/maps/VioletCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
# 33 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
# 34 "data/maps/VioletCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_FALKNER_1, VioletGym_Text_Falkner_WinLoss
# 35 "data/maps/VioletCity_Gym/scripts.pory"
	message VioletGym_Text_ReceivedZephyrBadge
# 36 "data/maps/VioletCity_Gym/scripts.pory"
	waitmessage
# 37 "data/maps/VioletCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 38 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
# 39 "data/maps/VioletCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 40 "data/maps/VioletCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_VIOLET_GYM
# 41 "data/maps/VioletCity_Gym/scripts.pory"
	addvar VAR_NUM_BADGES, 1
# 42 "data/maps/VioletCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 43 "data/maps/VioletCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 44 "data/maps/VioletCity_Gym/scripts.pory"
	giveitem ITEM_TM_DOUBLE_TEAM
# 45 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
# 46 "data/maps/VioletCity_Gym/scripts.pory"
	setvar VAR_VIOLET_CITY_STATE, 3
# 47 "data/maps/VioletCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_TUESCANY
# 48 "data/maps/VioletCity_Gym/scripts.pory"
	setrespawn HEAL_LOCATION_VIOLET_CITY
# 49 "data/maps/VioletCity_Gym/scripts.pory"
	closemessage
# 50 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 51 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 52 "data/maps/VioletCity_Gym/scripts.pory"

# 53 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Falkner_Defeated::
# 54 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
# 55 "data/maps/VioletCity_Gym/scripts.pory"
	closemessage
# 56 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 57 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 58 "data/maps/VioletCity_Gym/scripts.pory"

# 59 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_Intro:
# 60 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I'm Falkner, the Violet Pokémon\n"
# 61 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Gym leader!\p"
# 62 "data/maps/VioletCity_Gym/scripts.pory"
	.string "People say you can clip\n"
# 63 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Flying-type Pokémon's wings\p"
# 64 "data/maps/VioletCity_Gym/scripts.pory"
	.string "with a jolt of electricity…\n"
# 65 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I won't allow such insults to bird\l"
# 66 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Pokémon!\p"
# 67 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I'll show you the real power\n"
# 68 "data/maps/VioletCity_Gym/scripts.pory"
	.string "of the magnificent bird Pokémon!$"
# 69 "data/maps/VioletCity_Gym/scripts.pory"

# 70 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_WinLoss:
# 71 "data/maps/VioletCity_Gym/scripts.pory"
	.string "…Darn! My dad's cherished bird\n"
# 72 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Pokémon…\p"
# 73 "data/maps/VioletCity_Gym/scripts.pory"
	.string "All right. Take this.\p"
# 74 "data/maps/VioletCity_Gym/scripts.pory"
	.string "It's the official Pokémon League\n"
# 75 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Zephyrbadge.$"
# 76 "data/maps/VioletCity_Gym/scripts.pory"

# 77 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_ReceivedZephyrBadge:
# 78 "data/maps/VioletCity_Gym/scripts.pory"
	.string "{PLAYER} received Zephyrbadge.$"
# 79 "data/maps/VioletCity_Gym/scripts.pory"

# 80 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_BadgeExplain:
# 81 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Zephyrbadge raises the Attack\n"
# 82 "data/maps/VioletCity_Gym/scripts.pory"
	.string "power of Pokémon.\p"
# 83 "data/maps/VioletCity_Gym/scripts.pory"
	.string "It also enables Pokémon to use\n"
# 84 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Flash, if they can learn it,\l"
# 85 "data/maps/VioletCity_Gym/scripts.pory"
	.string "anytime.\p"
# 86 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Here--take this too.$"
# 87 "data/maps/VioletCity_Gym/scripts.pory"

# 88 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_TMExplain:
# 89 "data/maps/VioletCity_Gym/scripts.pory"
	.string "By using a TM, a Pokémon will\n"
# 90 "data/maps/VioletCity_Gym/scripts.pory"
	.string "instantly learn a new move.\p"
# 91 "data/maps/VioletCity_Gym/scripts.pory"
	.string "TM32 contains Double Team.\p"
# 92 "data/maps/VioletCity_Gym/scripts.pory"
	.string "It increase a Pokémon's evasion.\p"
# 93 "data/maps/VioletCity_Gym/scripts.pory"
	.string "In other words, your Pokémon\n"
# 94 "data/maps/VioletCity_Gym/scripts.pory"
	.string "will be harder to hit.$"
# 95 "data/maps/VioletCity_Gym/scripts.pory"

# 96 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_AfterFight:
# 97 "data/maps/VioletCity_Gym/scripts.pory"
	.string "There are Pokémon Gyms in cities\n"
# 98 "data/maps/VioletCity_Gym/scripts.pory"
	.string "and towns ahead.\p"
# 99 "data/maps/VioletCity_Gym/scripts.pory"
	.string "You should test your skills at\n"
# 100 "data/maps/VioletCity_Gym/scripts.pory"
	.string "these Gyms.\p"
# 101 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I'm going to train harder to\n"
# 102 "data/maps/VioletCity_Gym/scripts.pory"
	.string "become the greatest bird master!$"
# 103 "data/maps/VioletCity_Gym/scripts.pory"

# 104 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_Rematch:
# 105 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Congratulations on defeating\n"
# 106 "data/maps/VioletCity_Gym/scripts.pory"
	.string "the Elite 4!\p"
# 107 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I've been training my\n"
# 108 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Flying-type Pokémon even harder.\p"
# 109 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Think you can take on the power\n"
# 110 "data/maps/VioletCity_Gym/scripts.pory"
	.string "of the skies again?$"
# 111 "data/maps/VioletCity_Gym/scripts.pory"

# 112 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_Falkner_RematchLoss:
# 113 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Wow… You beat me again.\p"
# 114 "data/maps/VioletCity_Gym/scripts.pory"
	.string "I'm going to train harder to\n"
# 115 "data/maps/VioletCity_Gym/scripts.pory"
	.string "become the greatest bird master!$"
# 116 "data/maps/VioletCity_Gym/scripts.pory"

# 117 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperRod_Seen:
# 118 "data/maps/VioletCity_Gym/scripts.pory"
	.string "The keyword is guts!\p"
# 119 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Those here are training night and\n"
# 120 "data/maps/VioletCity_Gym/scripts.pory"
	.string "day to become bird Pokémon masters.\p"
# 121 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Come on!$"
# 122 "data/maps/VioletCity_Gym/scripts.pory"

# 123 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperRod_Beaten:
# 124 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Gaaah!$"
# 125 "data/maps/VioletCity_Gym/scripts.pory"

# 126 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperRod_After:
# 127 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Falkner's skills are for real!\p"
# 128 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Don't get cocky just because\n"
# 129 "data/maps/VioletCity_Gym/scripts.pory"
	.string "you beat me!$"
# 130 "data/maps/VioletCity_Gym/scripts.pory"

# 131 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperAbe_Seen:
# 132 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Let me see if you are good\n"
# 133 "data/maps/VioletCity_Gym/scripts.pory"
	.string "enough to face Falkner!$"
# 134 "data/maps/VioletCity_Gym/scripts.pory"

# 135 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperAbe_Beaten:
# 136 "data/maps/VioletCity_Gym/scripts.pory"
	.string "This can't be true!$"
# 137 "data/maps/VioletCity_Gym/scripts.pory"

# 138 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_BirdKeeperAbe_After:
# 139 "data/maps/VioletCity_Gym/scripts.pory"
	.string "This is pathetic, losing to some\n"
# 140 "data/maps/VioletCity_Gym/scripts.pory"
	.string "rookie trainer…$"
# 141 "data/maps/VioletCity_Gym/scripts.pory"

# 142 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_GymGuide_Intro:
# 143 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Hey! What's up? I'm no trainer,\n"
# 144 "data/maps/VioletCity_Gym/scripts.pory"
	.string "but I can give some advice!\p"
# 145 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Believe me! If you believe, a\n"
# 146 "data/maps/VioletCity_Gym/scripts.pory"
	.string "championship dream can come true.\p"
# 147 "data/maps/VioletCity_Gym/scripts.pory"
	.string "You believe? Then listen.\p"
# 148 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Falkner's ace is a bulky owl\n"
# 149 "data/maps/VioletCity_Gym/scripts.pory"
	.string "that loves to eat Berries.\p"
# 150 "data/maps/VioletCity_Gym/scripts.pory"
	.string "While it's not the strongest,\n"
# 151 "data/maps/VioletCity_Gym/scripts.pory"
	.string "it can take a lot of hits.\p"
# 152 "data/maps/VioletCity_Gym/scripts.pory"
	.string "You can hurt it with Electric \n"
# 153 "data/maps/VioletCity_Gym/scripts.pory"
	.string "and Rock-type moves, but watch out\l"
# 154 "data/maps/VioletCity_Gym/scripts.pory"
	.string "for Mud-Slap!\p"
# 155 "data/maps/VioletCity_Gym/scripts.pory"
	.string "If you want more help, go visit the\n"
# 156 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Pokémon Academy.\p"
# 157 "data/maps/VioletCity_Gym/scripts.pory"
	.string "The students there really know\n"
# 158 "data/maps/VioletCity_Gym/scripts.pory"
	.string "their stuff!$"
# 159 "data/maps/VioletCity_Gym/scripts.pory"

# 160 "data/maps/VioletCity_Gym/scripts.pory"
VioletGym_Text_GymGuide_Win:
# 161 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Nice battle! Keep it up,\n"
# 162 "data/maps/VioletCity_Gym/scripts.pory"
	.string "and you'll be the Champ in no\l"
# 163 "data/maps/VioletCity_Gym/scripts.pory"
	.string "time at all!$"
# 164 "data/maps/VioletCity_Gym/scripts.pory"

# 165 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Statue::
# 166 "data/maps/VioletCity_Gym/scripts.pory"
	lock
# 167 "data/maps/VioletCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
# 168 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 169 "data/maps/VioletCity_Gym/scripts.pory"
	closemessage
# 170 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 171 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 172 "data/maps/VioletCity_Gym/scripts.pory"

# 173 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_EventScript_Statue2::
# 174 "data/maps/VioletCity_Gym/scripts.pory"
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 175 "data/maps/VioletCity_Gym/scripts.pory"
	closemessage
# 176 "data/maps/VioletCity_Gym/scripts.pory"
	release
# 177 "data/maps/VioletCity_Gym/scripts.pory"
	end
# 178 "data/maps/VioletCity_Gym/scripts.pory"

# 179 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_Text_GymStatue:
# 180 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Violet City Pokémon Gym$"
# 181 "data/maps/VioletCity_Gym/scripts.pory"

# 182 "data/maps/VioletCity_Gym/scripts.pory"
VioletCity_Gym_Text_GymStatueCertified:
# 183 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Violet City Pokémon Gym\p"
# 184 "data/maps/VioletCity_Gym/scripts.pory"
	.string "Falkner'S Certified Trainers:\n"
# 185 "data/maps/VioletCity_Gym/scripts.pory"
	.string "{PLAYER}$"
