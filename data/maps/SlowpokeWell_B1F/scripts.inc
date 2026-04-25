# 1 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 2 "data/maps/SlowpokeWell_B1F/scripts.pory"
.set LOCALID_WELL_KURT, 19
# 3 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 4 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_MapScripts::
# 5 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 7 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_EventScript_Kurt::
# 8 "data/maps/SlowpokeWell_B1F/scripts.pory"
	lock
# 9 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
# 10 "data/maps/SlowpokeWell_B1F/scripts.pory"
	closemessage
# 11 "data/maps/SlowpokeWell_B1F/scripts.pory"
	end
# 12 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 13 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_EventScript_Grunt21::
# 14 "data/maps/SlowpokeWell_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
# 15 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
# 16 "data/maps/SlowpokeWell_B1F/scripts.pory"
	end
# 17 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 18 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_EventScript_Grunt22F::
# 19 "data/maps/SlowpokeWell_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
# 20 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
# 21 "data/maps/SlowpokeWell_B1F/scripts.pory"
	end
# 22 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 23 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_EventScript_Eto::
# 24 "data/maps/SlowpokeWell_B1F/scripts.pory"
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
# 25 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
# 26 "data/maps/SlowpokeWell_B1F/scripts.pory"
	end
# 27 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 28 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_EventScript_Proton::
# 29 "data/maps/SlowpokeWell_B1F/scripts.pory"
	lock
# 30 "data/maps/SlowpokeWell_B1F/scripts.pory"
	faceplayer
# 31 "data/maps/SlowpokeWell_B1F/scripts.pory"
    msgbox SlowpokeWell_B1F_Text_ProtonSeen
# 32 "data/maps/SlowpokeWell_B1F/scripts.pory"
	trainerbattle_no_intro TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonBeaten
# 33 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_DEFAULT
# 34 "data/maps/SlowpokeWell_B1F/scripts.pory"
	closemessage
# 35 "data/maps/SlowpokeWell_B1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 36 "data/maps/SlowpokeWell_B1F/scripts.pory"
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
# 37 "data/maps/SlowpokeWell_B1F/scripts.pory"
	clearflag FLAG_HIDE_KURT_1
# 38 "data/maps/SlowpokeWell_B1F/scripts.pory"
	addobject LOCALID_WELL_KURT
# 39 "data/maps/SlowpokeWell_B1F/scripts.pory"
	removeobject 11
# 40 "data/maps/SlowpokeWell_B1F/scripts.pory"
	removeobject 12
# 41 "data/maps/SlowpokeWell_B1F/scripts.pory"
	removeobject 13
# 42 "data/maps/SlowpokeWell_B1F/scripts.pory"
	delay 120
# 43 "data/maps/SlowpokeWell_B1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 44 "data/maps/SlowpokeWell_B1F/scripts.pory"
	special DrawWholeMapView
# 45 "data/maps/SlowpokeWell_B1F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 46 "data/maps/SlowpokeWell_B1F/scripts.pory"
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
# 47 "data/maps/SlowpokeWell_B1F/scripts.pory"
	waitmovement 0
# 48 "data/maps/SlowpokeWell_B1F/scripts.pory"
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
# 49 "data/maps/SlowpokeWell_B1F/scripts.pory"
	closemessage
# 50 "data/maps/SlowpokeWell_B1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 51 "data/maps/SlowpokeWell_B1F/scripts.pory"
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
# 52 "data/maps/SlowpokeWell_B1F/scripts.pory"
	setflag FLAG_HIDE_KURT_1
# 53 "data/maps/SlowpokeWell_B1F/scripts.pory"
	clearflag FLAG_HIDE_KURT_2
# 54 "data/maps/SlowpokeWell_B1F/scripts.pory"
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
# 55 "data/maps/SlowpokeWell_B1F/scripts.pory"
	setvar VAR_AZALEA_TOWN_STATE, 3
# 56 "data/maps/SlowpokeWell_B1F/scripts.pory"
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
# 57 "data/maps/SlowpokeWell_B1F/scripts.pory"
	release
# 58 "data/maps/SlowpokeWell_B1F/scripts.pory"
	end
# 59 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 60 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Movement_Kurt:
# 61 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_left
# 62 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_left
# 63 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_left
# 64 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_up
# 65 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_up
# 66 "data/maps/SlowpokeWell_B1F/scripts.pory"
	walk_up
# 67 "data/maps/SlowpokeWell_B1F/scripts.pory"
	step_end
# 68 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 69 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_KurtIntro:
# 70 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Kurt: Hey there, {PLAYER}!\p"
# 71 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "The guard up top took off when\n"
# 72 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "I shouted at him.\p"
# 73 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "But then I took a tumble down\n"
# 74 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "the Well.\p"
# 75 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "I slammed down hard on my back,\n"
# 76 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "so I can't move.\p"
# 77 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Rats! If I were fit, my POKéMON\n"
# 78 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "would've punished them…\p"
# 79 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Ah, it can't be helped.\p"
# 80 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "{PLAYER}, show them how gutsy\n"
# 81 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "you are in my place!$"
# 82 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 83 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_KurtAfter:
# 84 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Kurt: Way to go, {PLAYER}!\p"
# 85 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Team Rocket has taken off.\p"
# 86 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "My back's better too.\n"
# 87 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Let's get out of here.$"
# 88 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 89 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM29Seen:
# 90 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Darn! I was standing guard up\n"
# 91 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "top when some old coot yelled\l"
# 92 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "at me.\p"
# 93 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "He startled me so much that\n"
# 94 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "I fell down here.\p"
# 95 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "I think I'll vent my anger by\n"
# 96 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "taking it out on you!$"
# 97 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 98 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM29Beaten:
# 99 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Arrgh! This is Not my day!$"
# 100 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 101 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM29After:
# 102 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Sure, we've been hacking the\n"
# 103 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "tails off Slowpoke and selling\l"
# 104 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "them.\p"
# 105 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Everything we do is for profit.\p"
# 106 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "That's right! We're Team Rocket,\n"
# 107 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "and we'll do anything for money!$"
# 108 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 109 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_ProtonSeen:
# 110 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "What do you want?\p"
# 111 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "If you interrupt our work,\n"
# 112 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "don't expect any mercy!$"
# 113 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 114 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_ProtonBeaten:
# 115 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "You did Ok today,\n"
# 116 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "but wait till next time!$"
# 117 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 118 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_ProtonAfter:
# 119 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Yeah, Team Rocket was broken up\n"
# 120 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "three years ago.\p"
# 121 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "The boss went into hiding.\p"
# 122 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "But we continued our activities\n"
# 123 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "underground!\p"
# 124 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "A small obstacle like you won't be\n"
# 125 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "much of a problem for our mission.\p"
# 126 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "I advise you to be very afraid of\n"
# 127 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "what is to come!$"
# 128 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 129 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM2Seen:
# 130 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Hyuck-hyuck-hyuck!\n"
# 131 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Quit taking Slowpoketails?\p"
# 132 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "You're nuts!\n"
# 133 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "If we obeyed you, Team Rocket's\l"
# 134 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "rep would be ruined!$"
# 135 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 136 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM2Beaten:
# 137 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Hyuck…\n"
# 138 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Too strong…$"
# 139 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 140 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntM2After:
# 141 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "We need the money,\n"
# 142 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "but selling Slowpoketails?\p"
# 143 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "It's tough being a Rocket Grunt!$"
# 144 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 145 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntF1Seen:
# 146 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Stop taking Tails?\p"
# 147 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Yeah, just try to defeat all\n"
# 148 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "of us!$"
# 149 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 150 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntF1Beaten:
# 151 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "You rotten brat!$"
# 152 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 153 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_GruntF1After:
# 154 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Slowpoketails grow back fast!\p"
# 155 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "What's wrong with selling them?$"
# 156 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 157 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_SlowpokeWithMail:
# 158 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "A Slowpoke with its Tail cut off…\p"
# 159 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Huh? It has Mail.\n"
# 160 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Read it?$"
# 161 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 162 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_SlowpokeMail:
# 163 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "{PLAYER} read the Mail.\p"
# 164 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Be good and look after the\n"
# 165 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "house with Grandpa and Slowpoke.\p"
# 166 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "Love, Dad$"
# 167 "data/maps/SlowpokeWell_B1F/scripts.pory"

# 168 "data/maps/SlowpokeWell_B1F/scripts.pory"
SlowpokeWell_B1F_Text_TaillessSlowpoke:
# 169 "data/maps/SlowpokeWell_B1F/scripts.pory"
	.string "A Slowpoke with its Tail cut off…$"
