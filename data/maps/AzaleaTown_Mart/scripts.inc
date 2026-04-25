# 1 "data/maps/AzaleaTown_Mart/scripts.pory"

# 2 "data/maps/AzaleaTown_Mart/scripts.pory"
AzaleaTown_Mart_MapScripts::
# 3 "data/maps/AzaleaTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/AzaleaTown_Mart/scripts.pory"

# 5 "data/maps/AzaleaTown_Mart/scripts.pory"
AzaleaTown_Mart_EventScriptBugCatcher::
# 6 "data/maps/AzaleaTown_Mart/scripts.pory"
	lock
# 7 "data/maps/AzaleaTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/AzaleaTown_Mart/scripts.pory"
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
# 9 "data/maps/AzaleaTown_Mart/scripts.pory"
	closemessage
# 10 "data/maps/AzaleaTown_Mart/scripts.pory"
	release
# 11 "data/maps/AzaleaTown_Mart/scripts.pory"
	end
# 12 "data/maps/AzaleaTown_Mart/scripts.pory"

# 13 "data/maps/AzaleaTown_Mart/scripts.pory"
AzaleaMart_Text_BugCatcher:
# 14 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "A Great Ball is better for catch-\n"
# 15 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "ing POKéMON than a POKé Ball.\p"
# 16 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "But Kurt's might be better some-\n"
# 17 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "times.$"

AzaleaTownMart2::
# 22 "data/maps/AzaleaTown_Mart/scripts.pory"
	lock
# 23 "data/maps/AzaleaTown_Mart/scripts.pory"
	faceplayer
# 24 "data/maps/AzaleaTown_Mart/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, AzaleaTownMart2_2
# 32 "data/maps/AzaleaTown_Mart/scripts.pory"
	message AzaleaTownMart2_Text_1
# 34 "data/maps/AzaleaTown_Mart/scripts.pory"
	waitmessage
# 35 "data/maps/AzaleaTown_Mart/scripts.pory"
	pokemart GalaricaVendor
# 36 "data/maps/AzaleaTown_Mart/scripts.pory"
	msgbox AzaleaTownMart2_Text_2
# 37 "data/maps/AzaleaTown_Mart/scripts.pory"
	release
	end

AzaleaTownMart2_2:
# 25 "data/maps/AzaleaTown_Mart/scripts.pory"
	msgbox AzaleaTownMart2_Text_0
# 29 "data/maps/AzaleaTown_Mart/scripts.pory"
	release
	end


	.align 2
# 41 "data/maps/AzaleaTown_Mart/scripts.pory"
GalaricaVendor:
# 42 "data/maps/AzaleaTown_Mart/scripts.pory"
	.2byte ITEM_GALARICA_WREATH
# 43 "data/maps/AzaleaTown_Mart/scripts.pory"
	.2byte ITEM_GALARICA_CUFF
# 44 "data/maps/AzaleaTown_Mart/scripts.pory"
	.2byte ITEM_NEST_BALL
# 45 "data/maps/AzaleaTown_Mart/scripts.pory"
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE

AzaleaTownMartNpc::
# 49 "data/maps/AzaleaTown_Mart/scripts.pory"
	lock
# 50 "data/maps/AzaleaTown_Mart/scripts.pory"
	faceplayer
# 51 "data/maps/AzaleaTown_Mart/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, AzaleaTownMartNpc_2
# 57 "data/maps/AzaleaTown_Mart/scripts.pory"
	msgbox AzaleaTownMartNpc_Text_1
# 60 "data/maps/AzaleaTown_Mart/scripts.pory"
	release
	end

AzaleaTownMartNpc_2:
# 52 "data/maps/AzaleaTown_Mart/scripts.pory"
	msgbox AzaleaTownMartNpc_Text_0
# 54 "data/maps/AzaleaTown_Mart/scripts.pory"
	release
	end


AzaleaTownMart2_Text_0:
# 25 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "Sorry, but we're out of Galarica wreaths\n"
	.string "and cuffs after the rocket incident.\l"
	.string "Come back later after we have\l"
	.string "restocked.$"

AzaleaTownMart2_Text_1:
# 32 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "Welcome! The Galarian items back \n"
	.string "in stock!$"

AzaleaTownMart2_Text_2:
# 36 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "Come back again soon!$"

AzaleaTownMartNpc_Text_0:
# 52 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "Galarian evolution items are back in\n"
	.string "stock!$"

AzaleaTownMartNpc_Text_1:
# 57 "data/maps/AzaleaTown_Mart/scripts.pory"
	.string "Apparently the Team Rocket had taken \n"
	.string "all evolution items specifically for\l"
	.string "Galarian Slowpokes.$"
