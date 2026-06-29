# 1 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 2 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_MapScripts::
# 3 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.byte 0
# 4 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 5 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Quagsire::
# 6 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 7 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 8 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	waitse
# 9 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
# 10 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
# 11 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	waitmoncry
# 12 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 13 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 14 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 15 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Quagsire:
# 16 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Quagsire: Quag Quag$"
# 17 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 18 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Stan::
# 19 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	trainerbattle_single TRAINER_STAN, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
# 20 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
# 21 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 22 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 23 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Nathan::
# 24 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	trainerbattle_single TRAINER_NATHAN, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
# 25 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
# 26 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 27 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 28 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Youngster1::
# 29 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 30 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 31 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
# 32 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 33 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 34 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 35 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 36 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Youngster2::
# 37 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 38 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 39 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
# 40 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 41 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 42 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 43 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 44 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Fisher1::
# 45 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 46 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 47 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
# 48 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 49 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 50 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 51 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 52 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Fisher2::
# 53 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 54 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 55 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
# 56 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 57 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 58 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 59 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 60 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Sign1::
# 61 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 62 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
# 63 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 64 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 65 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 66 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 67 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Sign2::
# 68 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 69 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
# 70 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 71 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 72 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 73 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 74 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_EventScript_Sign3::
# 75 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 76 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
# 77 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 78 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
# 79 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	end
# 80 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 81 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Scientist:
# 82 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Hm? That's a Pokédex, isn't it?\n"
# 83 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "May I see it?\p"
# 84 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "There are so many kinds of\n"
# 85 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Pokémon.\p"
# 86 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Hm? What's this?\p"
# 87 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "What is this Pokémon?\p"
# 88 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "It looks like the strange\n"
# 89 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "writing on the walls of the\p"
# 90 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Ruins.\p"
# 91 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "If those drawings are really\n"
# 92 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Pokémon, there should be many\n"
# 93 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "more.\p"
# 94 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "I know! Let me upgrade your\n"
# 95 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Pokédex. Follow me.$"
# 96 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 97 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
# 98 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "What do you want? I'm studying--\n"
# 99 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "don't disturb me!$"
# 100 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 101 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
# 102 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Sorry…\n"
# 103 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "I'm frustrated by our lack of\p"
# 104 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "real understanding…$"
# 105 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 106 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_SuperNerdStan_After:
# 107 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "The Ruins are from about 1500\n"
# 108 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "years ago.\p"
# 109 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Nobody knows who built them.\p"
# 110 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "It's also not known if the Pokémon\n"
# 111 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "statues have any meaning.\p"
# 112 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "It's all one big mystery…$"
# 113 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 114 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
# 115 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Hmmm… This is a strange place.$"
# 116 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 117 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
# 118 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "…$"
# 119 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 120 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_PsychicNathan_After:
# 121 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "I like thinking here.$"
# 122 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 123 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_MysteryChamberSign:
# 124 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Mystery Stone Panel Chamber$"
# 125 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 126 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_MainSign:
# 127 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Ruins Of Alph\n"
# 128 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Visitors Welcome$"
# 129 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 130 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_ResearchSign:
# 131 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Ruins Of Alph Research Center\p"
# 132 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "The Authority On The\n"
# 133 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Ruins Of Alph$"
# 134 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 135 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Fisher1:
# 136 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "While exploring the Ruins, we\n"
# 137 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "suddenly noticed an odd presence.\p"
# 138 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "We all got scared and ran away.\n"
# 139 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "You should be careful too.$"
# 140 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 141 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Fisher2:
# 142 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "The Ruins hide a huge secret!\p"
# 143 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "…I think…$"
# 144 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 145 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Youngster1:
# 146 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "There are many kinds of Unown, so\n"
# 147 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "we use them for our secret codes.$"
# 148 "data/maps/RuinsOfAlph_Outside/scripts.pory"

# 149 "data/maps/RuinsOfAlph_Outside/scripts.pory"
RuinsOfAlph_Outside_Text_Youngster2:
# 150 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "A… H… E… A… D… Hmm…\p"
# 151 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "What?\p"
# 152 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "I'm decoding this message!$"

RuinsofAlph_Scientist::
# 156 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox RuinsofAlph_Scientist_Text_0, MSGBOX_NPC
	return


CameronCamera::
# 161 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	lock
# 162 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	faceplayer
# 163 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox CameronCamera_Text_0, MSGBOX_YESNO
# 170 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CameronCamera_1
# 194 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox CameronCamera_Text_2
# 195 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	release
	end

CameronCamera_1:
# 171 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	msgbox CameronCamera_Text_1
# 172 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	closemessage
# 174 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 175 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	setflag FLAG_HIDE_CAMERON
# 176 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	removeobject VAR_LAST_TALKED
# 177 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	special ShowPartyPhotoLineup
# 178 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	delay 60
# 179 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 180 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	waitbuttonpress
# 181 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 182 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	delay 30
# 183 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	special HidePartyPhotoLineup
# 184 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	delay 30
# 185 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	setflag FLAG_CAMERON_PHOTO1
# 186 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	special Achievement_CheckAll
# 187 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	clearflag FLAG_HIDE_CAMERON
# 188 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	addobject VAR_LAST_TALKED
# 190 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 191 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	releaseall
	end


RuinsofAlph_Scientist_Text_0:
# 156 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Sometimes fossils can be found while\n"
	.string "breaking rocks in here.$"

CameronCamera_Text_0:
# 163 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Hello, \n"
	.string "just when you least expect it! \p"
	.string "I am Cameron the Photographer. \p"
	.string "You look so photogenic! \n"
	.string "Why not have a picture taken?$"

CameronCamera_Text_1:
# 171 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "All right, then! Get yourselves ready!$"

CameronCamera_Text_2:
# 194 "data/maps/RuinsOfAlph_Outside/scripts.pory"
	.string "Aren't you a shy one?$"
