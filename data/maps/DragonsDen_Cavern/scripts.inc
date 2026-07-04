# 1 "data/maps/DragonsDen_Cavern/scripts.pory"

# 2 "data/maps/DragonsDen_Cavern/scripts.pory"
.set LOCALID_DRAGONSDEN2_CLAIR, 5
# 3 "data/maps/DragonsDen_Cavern/scripts.pory"
.set LOCALID_DEN_CLAIR, 35
# 4 "data/maps/DragonsDen_Cavern/scripts.pory"

# 5 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_MapScripts::
# 6 "data/maps/DragonsDen_Cavern/scripts.pory"
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
# 7 "data/maps/DragonsDen_Cavern/scripts.pory"
	.byte 0
# 8 "data/maps/DragonsDen_Cavern/scripts.pory"

# 9 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_OnFrame::
# 10 "data/maps/DragonsDen_Cavern/scripts.pory"
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
# 11 "data/maps/DragonsDen_Cavern/scripts.pory"
	.2byte 0
# 12 "data/maps/DragonsDen_Cavern/scripts.pory"

# 13 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_EventScript_ClairRematch::
# 14 "data/maps/DragonsDen_Cavern/scripts.pory"
    lock
# 15 "data/maps/DragonsDen_Cavern/scripts.pory"
    faceplayer
# 16 "data/maps/DragonsDen_Cavern/scripts.pory"
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
# 17 "data/maps/DragonsDen_Cavern/scripts.pory"
    closemessage
# 18 "data/maps/DragonsDen_Cavern/scripts.pory"
    fadescreenswapbuffers FADE_TO_BLACK
# 19 "data/maps/DragonsDen_Cavern/scripts.pory"
    setflag FLAG_HIDE_DEN_CLAIR
# 20 "data/maps/DragonsDen_Cavern/scripts.pory"
    removeobject LOCALID_DEN_CLAIR
# 21 "data/maps/DragonsDen_Cavern/scripts.pory"
    fadescreenswapbuffers FADE_FROM_BLACK
# 22 "data/maps/DragonsDen_Cavern/scripts.pory"
    clearflag FLAG_HIDE_DOJO_CLAIR
# 23 "data/maps/DragonsDen_Cavern/scripts.pory"
    release
# 24 "data/maps/DragonsDen_Cavern/scripts.pory"
    end
# 25 "data/maps/DragonsDen_Cavern/scripts.pory"

# 26 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Text_Clair:
# 27 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "{PLAYER}… So you're here.\p"
# 28 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "If you think you can keep up,\n"
# 29 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "with me, come to the Fighting\l"
# 30 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "Dojo in Saffron.$"
# 31 "data/maps/DragonsDen_Cavern/scripts.pory"

# 32 "data/maps/DragonsDen_Cavern/scripts.pory"

# 33 "data/maps/DragonsDen_Cavern/scripts.pory"

# 34 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Trigger_ClairMid::
# 35 "data/maps/DragonsDen_Cavern/scripts.pory"
	lock 
# 36 "data/maps/DragonsDen_Cavern/scripts.pory"
	playse SE_PIN
# 37 "data/maps/DragonsDen_Cavern/scripts.pory"
	applymovement LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
# 38 "data/maps/DragonsDen_Cavern/scripts.pory"
	delay 60
# 39 "data/maps/DragonsDen_Cavern/scripts.pory"
	approachobject LOCALID_DRAGONSDEN2_CLAIR, LOCALID_PLAYER, DIR_EAST, DIR_WEST
# 40 "data/maps/DragonsDen_Cavern/scripts.pory"
	waitmovement 0
# 41 "data/maps/DragonsDen_Cavern/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 42 "data/maps/DragonsDen_Cavern/scripts.pory"
	call DragonsDen_Cavern_EventScript_Clair
# 43 "data/maps/DragonsDen_Cavern/scripts.pory"
	fadescreen FADE_TO_BLACK
# 44 "data/maps/DragonsDen_Cavern/scripts.pory"
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
# 45 "data/maps/DragonsDen_Cavern/scripts.pory"
	removeobject LOCALID_DRAGONSDEN2_CLAIR
# 46 "data/maps/DragonsDen_Cavern/scripts.pory"
	playse SE_EXIT
# 47 "data/maps/DragonsDen_Cavern/scripts.pory"
	delay 45
# 48 "data/maps/DragonsDen_Cavern/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 49 "data/maps/DragonsDen_Cavern/scripts.pory"
	setvar VAR_BLACKTHORN_CITY_STATE, 4
# 50 "data/maps/DragonsDen_Cavern/scripts.pory"
	release
# 51 "data/maps/DragonsDen_Cavern/scripts.pory"
	end
# 52 "data/maps/DragonsDen_Cavern/scripts.pory"

# 53 "data/maps/DragonsDen_Cavern/scripts.pory"

# 54 "data/maps/DragonsDen_Cavern/scripts.pory"

# 55 "data/maps/DragonsDen_Cavern/scripts.pory"

# 56 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_EventScript_Clair::
# 57 "data/maps/DragonsDen_Cavern/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 58 "data/maps/DragonsDen_Cavern/scripts.pory"
	createfieldmugshot MUGSHOT_CLAIR
# 59 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_ClairGiveDragonclaw, MSGBOX_DEFAULT
# 60 "data/maps/DragonsDen_Cavern/scripts.pory"
	giveitem ITEM_TM_DRAGON_CLAW
# 61 "data/maps/DragonsDen_Cavern/scripts.pory"
	createfieldmugshot MUGSHOT_CLAIR
# 62 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_ClairDescribeDragonclaw, MSGBOX_DEFAULT
# 63 "data/maps/DragonsDen_Cavern/scripts.pory"
	closemessage
# 64 "data/maps/DragonsDen_Cavern/scripts.pory"
	delay 30
# 65 "data/maps/DragonsDen_Cavern/scripts.pory"
	createfieldmugshot MUGSHOT_CLAIR
# 66 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
# 67 "data/maps/DragonsDen_Cavern/scripts.pory"
	closemessage
# 68 "data/maps/DragonsDen_Cavern/scripts.pory"
	delay 10
# 69 "data/maps/DragonsDen_Cavern/scripts.pory"
	clearflag FLAG_GOT_DRATINI
# 70 "data/maps/DragonsDen_Cavern/scripts.pory"
	return
# 71 "data/maps/DragonsDen_Cavern/scripts.pory"

# 72 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Movement_ClairLeaveLeft:
# 73 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 74 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_right
# 75 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_right
# 76 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 77 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 78 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 79 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 80 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 81 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 82 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 83 "data/maps/DragonsDen_Cavern/scripts.pory"
	step_end
# 84 "data/maps/DragonsDen_Cavern/scripts.pory"

# 85 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Movement_ClairLeaveMid:
# 86 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 87 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_right
# 88 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 89 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 90 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 91 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 92 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 93 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 94 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 95 "data/maps/DragonsDen_Cavern/scripts.pory"
	step_end
# 96 "data/maps/DragonsDen_Cavern/scripts.pory"

# 97 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Movement_ClairLeaveRight:
# 98 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 99 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 100 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 101 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 102 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 103 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 104 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 105 "data/maps/DragonsDen_Cavern/scripts.pory"
	walk_up
# 106 "data/maps/DragonsDen_Cavern/scripts.pory"
	step_end
# 107 "data/maps/DragonsDen_Cavern/scripts.pory"

# 108 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_ClairGiveDragonclaw:
# 109 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Clair: Wait!\p"
# 110 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "I'm sorry about this.\n"
# 111 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Here, take this as my apology.$"
# 112 "data/maps/DragonsDen_Cavern/scripts.pory"

# 113 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_ClairDescribeDragonclaw:
# 114 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "That contains Dragon Claw.\p"
# 115 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "No, it doesn't have anything to\n"
# 116 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "do with my nails.\p"
# 117 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "If you don't want it, you don't\n"
# 118 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "have to take it.$"
# 119 "data/maps/DragonsDen_Cavern/scripts.pory"

# 120 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_ClairWhatsTheMatter:
# 121 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "What's the matter? Aren't\n"
# 122 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "you going on to the Pokémon\l"
# 123 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "League?\p"
# 124 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "After you become Champion, you\n"
# 125 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "can rematch any Gym Leader you\l"
# 126 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "want.\p"
# 127 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Go to the Pokémon League.\p"
# 128 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Do you know how to get there?\p"
# 129 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "From here, go to New Bark Town.\p"
# 130 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Then Surf east to Pokémon League.\p"
# 131 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "The route there is very tough.\p"
# 132 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Don't you dare lose at the Pokémon\n"
# 133 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "League!\p"
# 134 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "If you do, I'll feel even worse\n"
# 135 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "about having lost to you!\p"
# 136 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Give it everything you've got.$"
# 137 "data/maps/DragonsDen_Cavern/scripts.pory"

# 138 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_EventScript_Darin::
# 139 "data/maps/DragonsDen_Cavern/scripts.pory"
	trainerbattle_single TRAINER_DARIN DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
# 140 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
# 141 "data/maps/DragonsDen_Cavern/scripts.pory"
	end
# 142 "data/maps/DragonsDen_Cavern/scripts.pory"

# 143 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_EventScript_Cara::
# 144 "data/maps/DragonsDen_Cavern/scripts.pory"
	trainerbattle_single TRAINER_CARA DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
# 145 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
# 146 "data/maps/DragonsDen_Cavern/scripts.pory"
	end
# 147 "data/maps/DragonsDen_Cavern/scripts.pory"

# 148 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_EventScript_TwinLea::
# 149 "data/maps/DragonsDen_Cavern/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
# 150 "data/maps/DragonsDen_Cavern/scripts.pory"
	special GetPlayerBigGuyGirlString
# 151 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
# 152 "data/maps/DragonsDen_Cavern/scripts.pory"
	release
# 153 "data/maps/DragonsDen_Cavern/scripts.pory"
	end
# 154 "data/maps/DragonsDen_Cavern/scripts.pory"
	
# 155 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_EventScript_TwinPia::
# 156 "data/maps/DragonsDen_Cavern/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
# 157 "data/maps/DragonsDen_Cavern/scripts.pory"
	special GetPlayerBigGuyGirlString
# 158 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
# 159 "data/maps/DragonsDen_Cavern/scripts.pory"
	release
# 160 "data/maps/DragonsDen_Cavern/scripts.pory"
	end
# 161 "data/maps/DragonsDen_Cavern/scripts.pory"

# 162 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_DragonShrineSign:
# 163 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Dragon Shrine\p"
# 164 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "A shrine honoring the dragon\n"
# 165 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Pokémon\p"
# 166 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "said to have lived in Dragon's\n"
# 167 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Den.$"
# 168 "data/maps/DragonsDen_Cavern/scripts.pory"

# 169 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_SilverTraining1:
# 170 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "…\n"
# 171 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "What? {PLAYER}?\p"
# 172 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "…No, I won't battle you now…\p"
# 173 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "My Pokémon aren't ready to beat\n"
# 174 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "you.\p"
# 175 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "I can't push them too hard now.\p"
# 176 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "I have to be disciplined to become\n"
# 177 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "the greatest Pokémon trainer…$"
# 178 "data/maps/DragonsDen_Cavern/scripts.pory"

# 179 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_SilverTraining2:
# 180 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "…\p"
# 181 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Whew…\p"
# 182 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Learn to stay out of my way…$"
# 183 "data/maps/DragonsDen_Cavern/scripts.pory"

# 184 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainermDarinSeen:
# 185 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "You! How dare you enter\n"
# 186 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "uninvited!$"
# 187 "data/maps/DragonsDen_Cavern/scripts.pory"

# 188 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
# 189 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "S-strong!$"
# 190 "data/maps/DragonsDen_Cavern/scripts.pory"

# 191 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainermDarinAfter:
# 192 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "The Shrine ahead is home to the\n"
# 193 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Master of our dragon-user clan.\p"
# 194 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "You're not allowed to just go in!$"
# 195 "data/maps/DragonsDen_Cavern/scripts.pory"

# 196 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
# 197 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "You shouldn't be in here!$"
# 198 "data/maps/DragonsDen_Cavern/scripts.pory"

# 199 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
# 200 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Oh yikes, I lost!$"
# 201 "data/maps/DragonsDen_Cavern/scripts.pory"

# 202 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
# 203 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Soon I'm going to get permission\n"
# 204 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "from our Master to use dragons.\p"
# 205 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "When I do, I'm going to become an\n"
# 206 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "admirable dragon trainer and gain\l"
# 207 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "our Master's approval.$"
# 208 "data/maps/DragonsDen_Cavern/scripts.pory"

# 209 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
# 210 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "It's a stranger we don't know.$"
# 211 "data/maps/DragonsDen_Cavern/scripts.pory"

# 212 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
# 213 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Ouchies.$"
# 214 "data/maps/DragonsDen_Cavern/scripts.pory"

# 215 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia1After:
# 216 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "It was like having to battle\n"
# 217 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Lance.$"
# 218 "data/maps/DragonsDen_Cavern/scripts.pory"

# 219 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
# 220 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Who are you?$"
# 221 "data/maps/DragonsDen_Cavern/scripts.pory"

# 222 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
# 223 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Meanie.$"
# 224 "data/maps/DragonsDen_Cavern/scripts.pory"

# 225 "data/maps/DragonsDen_Cavern/scripts.pory"
DragonsDen_Cavern_Text_TwinsLeaandPia2After:
# 226 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "We'll tell on you.\p"
# 227 "data/maps/DragonsDen_Cavern/scripts.pory"
    .string "Master will be angry with you.$"

DragonsDen_ClairRematch::
# 231 "data/maps/DragonsDen_Cavern/scripts.pory"
	lock
# 232 "data/maps/DragonsDen_Cavern/scripts.pory"
	faceplayer
# 233 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_ClairRematch_Text_0
# 238 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_ClairRematch_Text_1, MSGBOX_YESNO
# 242 "data/maps/DragonsDen_Cavern/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DragonsDen_ClairRematch_2
DragonsDen_ClairRematch_1:
# 261 "data/maps/DragonsDen_Cavern/scripts.pory"
	release
	end

DragonsDen_ClairRematch_2:
# 243 "data/maps/DragonsDen_Cavern/scripts.pory"
	trainerbattle_no_intro TRAINER_CLAIR_2, DragonsDen_ClairRematch_Text_2
# 245 "data/maps/DragonsDen_Cavern/scripts.pory"
	msgbox DragonsDen_ClairRematch_Text_3
# 253 "data/maps/DragonsDen_Cavern/scripts.pory"
	closemessage
# 254 "data/maps/DragonsDen_Cavern/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 255 "data/maps/DragonsDen_Cavern/scripts.pory"
	setflag FLAG_HIDE_DEN_CLAIR
# 256 "data/maps/DragonsDen_Cavern/scripts.pory"
	setflag FLAG_CLAIR_ON_TRIP
# 257 "data/maps/DragonsDen_Cavern/scripts.pory"
	removeobject LOCALID_CLAIR_REMATCH
# 258 "data/maps/DragonsDen_Cavern/scripts.pory"
	delay 30
# 259 "data/maps/DragonsDen_Cavern/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto DragonsDen_ClairRematch_1


DragonsDen_ClairRematch_Text_0:
# 233 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "Hey {PLAYER}.\n"
	.string "I heard from Lance that you became the\l"
	.string "new Champion. I guess the elders were\l"
	.string "right, I was just blinded by my own ego.\l"
	.string "Sorry.$"

DragonsDen_ClairRematch_Text_1:
# 238 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "Could we have another match right\n"
	.string "here? I'd like to fight the new\l"
	.string "Champion without anything holding\l"
	.string "us back.$"

DragonsDen_ClairRematch_Text_2:
# 243 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "Crazy how much stronger you can grow\n"
	.string "in such a short amount of time.$"

DragonsDen_ClairRematch_Text_3:
# 245 "data/maps/DragonsDen_Cavern/scripts.pory"
	.string "I've got a long way to go still if I want\n"
	.string "to surpass you or even Lance. I think\l"
	.string "I will leave for a trip soon. Go see\l"
	.string "places and hopefully learn from all\l"
	.string "kinds of people. Then I will face you\l"
	.string "again with all I've learned. Thank you\l"
	.string "for this lesson in battle. I won't\l"
	.string "forget it.$"
