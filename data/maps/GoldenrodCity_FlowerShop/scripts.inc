# 1 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 2 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_MapScripts::
# 3 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.byte 0
# 4 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 5 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_Owner::
# 6 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 7 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 8 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
# 9 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
# 10 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
# 11 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
# 12 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 13 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 14 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 15 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 16 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
# 17 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 18 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 19 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
# 20 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	giveitem ITEM_SQUIRTBOTTLE
# 21 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
# 22 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 23 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 24 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 25 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 26 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
# 27 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 28 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 29 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
# 30 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 31 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 32 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 33 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 34 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_Normal::
# 35 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 36 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 37 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
# 38 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 39 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 40 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 41 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 42 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_Floria1::
# 43 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 44 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 45 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
# 46 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
# 47 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
# 48 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 49 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 50 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 51 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	
# 52 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_Floria2::
# 53 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
# 54 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 55 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 56 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 57 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 58 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_EventScript_Floria3::
# 59 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
# 60 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	closemessage
# 61 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 62 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 63 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 64 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
# 65 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 66 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 67 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	dotimebasedevents
# 68 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
# 69 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
# 70 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	random 8
# 71 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 72 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	giveitem VAR_RESULT
# 73 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 74 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
# 75 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 76 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 77 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 78 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 79 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
# 80 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 81 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 82 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 83 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 84 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_MintOwner::
# 85 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	lock
# 86 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	faceplayer
# 87 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, Route104_PrettyPetalFlowerShop_EventScript_NoSellMints
# 88 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_Mints1, MSGBOX_DEFAULT
# 89 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	waitmessage
# 90 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	pokemart Route104_PrettyPetalFlowerShop_MintShop
# 91 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 92 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 93 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 94 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 95 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Text_Mints1:
# 96 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "Our Nature Mints are back!\n"
# 97 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "Have a look!$"
# 98 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 99 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Text_Mints2:
# 100 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "Hi, dear trainer. If you are looking\n"
# 101 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "to buy Nature Mints, you should have\l"
# 102 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "come earlier. I just sold the last one.\n"
# 103 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "Come back later.$"
# 104 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 105 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.align 2
# 106 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_MintShop:
# 107 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
# 108 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 109 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 110 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 111 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_CALM_MINT
# 112 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 113 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 114 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 115 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 116 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 117 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_LAX_MINT
# 118 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 119 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_MILD_MINT
# 120 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 121 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 122 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 123 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 124 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_RASH_MINT
# 125 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 126 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 127 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 128 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.2byte ITEM_NONE
# 129 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 130 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 131 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 132 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_NoSellMints::
# 133 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_Mints2, MSGBOX_DEFAULT
# 134 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 135 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 136 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 137 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
# 138 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
# 139 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 140 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 141 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	release
# 142 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	end
# 143 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 144 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
# 145 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
# 146 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	return
# 147 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 148 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
# 149 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
# 150 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	return
# 151 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 152 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_Floria:
# 153 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "When I told my sis about the jiggly\n"
# 154 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "tree, she said it's dangerous.\p"
# 155 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "If I beat Whitney, I wonder if\n"
# 156 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
	.string "she'll lend me her water bottle…$"
# 157 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 158 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_Owner1:
# 159 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Apparently, there is an odd tree\n"
# 160 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "on Route 36.\p"
# 161 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "They say it dances when you water\n"
# 162 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "it...\p"
# 163 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Oh, of course not!\p"
# 164 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "This is a flower shop, so we do\n"
# 165 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "have watering cans...\p"
# 166 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "But I cannot let you have one!\n"
# 167 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "It's too dangerous!\p"
# 168 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Well, maybe if you manage to\n"
# 169 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "defeat gym leader Whitney, it\l"
# 170 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "might be okay.$"
# 171 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 172 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_Owner2:
# 173 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Apparently, there is an odd tree\n"
# 174 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "on Route 36.\p"
# 175 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "They say it dances when you water\n"
# 176 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "it...\p"
# 177 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Oh, that's a Plainbadge from\n"
# 178 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "The Goldenrod Gym!\p"
# 179 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Did you defeat Whitney?!\p"
# 180 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Well, then there's nothing to worry\n"
# 181 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "about, is there?\p"
# 182 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "I'll let you use this Squirtbottle\n"
# 183 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "for a while then.\l"
# 184 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "...\p"
# 185 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Oh, never mind. Keep it!$"
# 186 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 187 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_Owner3:
# 188 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "The odd tree is on Route 36.\n"
# 189 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
.string "Please be careful!$"
# 190 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 191 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_Owner4:
# 192 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
    .string "Lalala lalalala. Have plenty of\n"
# 193 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
    .string "water, my lovely!$"
# 194 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 195 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
# 196 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
    .string "Wow, you beat Whitney? Cool!$"
# 197 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"

# 198 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
# 199 "data/maps/GoldenrodCity_FlowerShop/scripts.pory"
    .string "So it really was a Pokémon!$"
