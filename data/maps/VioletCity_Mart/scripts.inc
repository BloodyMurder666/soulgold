# 1 "data/maps/VioletCity_Mart/scripts.pory"

# 2 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_MapScripts::
# 3 "data/maps/VioletCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/VioletCity_Mart/scripts.pory"

# 5 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_EventScript_Clerk::
# 6 "data/maps/VioletCity_Mart/scripts.pory"
	lock
# 7 "data/maps/VioletCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/VioletCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/VioletCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/VioletCity_Mart/scripts.pory"
	pokemart 0
# 11 "data/maps/VioletCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/VioletCity_Mart/scripts.pory"
	release
# 13 "data/maps/VioletCity_Mart/scripts.pory"
	end
# 14 "data/maps/VioletCity_Mart/scripts.pory"

# 15 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_EventScript_Granny::
# 16 "data/maps/VioletCity_Mart/scripts.pory"
	lock
# 17 "data/maps/VioletCity_Mart/scripts.pory"
	faceplayer
# 18 "data/maps/VioletCity_Mart/scripts.pory"
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
# 19 "data/maps/VioletCity_Mart/scripts.pory"
	closemessage
# 20 "data/maps/VioletCity_Mart/scripts.pory"
	release
# 21 "data/maps/VioletCity_Mart/scripts.pory"
	end
# 22 "data/maps/VioletCity_Mart/scripts.pory"

# 23 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_EventScript_Rocker::
# 24 "data/maps/VioletCity_Mart/scripts.pory"
	lock
# 25 "data/maps/VioletCity_Mart/scripts.pory"
	faceplayer
# 26 "data/maps/VioletCity_Mart/scripts.pory"
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
# 27 "data/maps/VioletCity_Mart/scripts.pory"
	closemessage
# 28 "data/maps/VioletCity_Mart/scripts.pory"
	release
# 29 "data/maps/VioletCity_Mart/scripts.pory"
	end
# 30 "data/maps/VioletCity_Mart/scripts.pory"
	
# 31 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_Text_Granny:
# 32 "data/maps/VioletCity_Mart/scripts.pory"
	.string "When you first catch a POKéMON,\n"
# 33 "data/maps/VioletCity_Mart/scripts.pory"
	.string "it may be weak.\p"
# 34 "data/maps/VioletCity_Mart/scripts.pory"
	.string "But it will eventually grow to\n"
# 35 "data/maps/VioletCity_Mart/scripts.pory"
	.string "be strong.\p"
# 36 "data/maps/VioletCity_Mart/scripts.pory"
	.string "It's important to treat POKéMON\n"
# 37 "data/maps/VioletCity_Mart/scripts.pory"
	.string "with love.$"
# 38 "data/maps/VioletCity_Mart/scripts.pory"

# 39 "data/maps/VioletCity_Mart/scripts.pory"
VioletCity_Mart_Text_CooltrainerM:
# 40 "data/maps/VioletCity_Mart/scripts.pory"
	.string "POKéMON can hold items like\n"
# 41 "data/maps/VioletCity_Mart/scripts.pory"
	.string "Potion and Antidote.\p"
# 42 "data/maps/VioletCity_Mart/scripts.pory"
	.string "But they don't appear to know\n"
# 43 "data/maps/VioletCity_Mart/scripts.pory"
	.string "how to use manmade items.$"

Violetcity_Mart2::
# 47 "data/maps/VioletCity_Mart/scripts.pory"
	lock
# 48 "data/maps/VioletCity_Mart/scripts.pory"
	faceplayer
# 49 "data/maps/VioletCity_Mart/scripts.pory"
	message Violetcity_Mart2_Text_0
# 50 "data/maps/VioletCity_Mart/scripts.pory"
	waitmessage
# 51 "data/maps/VioletCity_Mart/scripts.pory"
	pokemart Violetcity2
# 52 "data/maps/VioletCity_Mart/scripts.pory"
	msgbox Violetcity_Mart2_Text_1
# 53 "data/maps/VioletCity_Mart/scripts.pory"
	release
	end


	.align 2
# 57 "data/maps/VioletCity_Mart/scripts.pory"
Violetcity2:
# 58 "data/maps/VioletCity_Mart/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 59 "data/maps/VioletCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 60 "data/maps/VioletCity_Mart/scripts.pory"
	.2byte ITEM_NEST_BALL
# 61 "data/maps/VioletCity_Mart/scripts.pory"
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE

Violetcity_Mart2_Text_0:
# 49 "data/maps/VioletCity_Mart/scripts.pory"
	.string "Welcome! How may I help you?$"

Violetcity_Mart2_Text_1:
# 52 "data/maps/VioletCity_Mart/scripts.pory"
	.string "Come back soon!$"
