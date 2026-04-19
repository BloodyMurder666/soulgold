# 1 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 2 "data/maps/CherrygroveCity_Mart/scripts.pory"
CherrygroveCity_Mart_MapScripts::
# 3 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 5 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_EventScript_Clerk::
# 6 "data/maps/CherrygroveCity_Mart/scripts.pory"
	lock
# 7 "data/maps/CherrygroveCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/CherrygroveCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/CherrygroveCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/CherrygroveCity_Mart/scripts.pory"
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
# 11 "data/maps/CherrygroveCity_Mart/scripts.pory"
	pokemart Cherrygrove_Pokemart_Pokemart
# 12 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 14 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 15 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 16 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_EventScript_Youngster::
# 17 "data/maps/CherrygroveCity_Mart/scripts.pory"
	lock
# 18 "data/maps/CherrygroveCity_Mart/scripts.pory"
	faceplayer
# 19 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
# 20 "data/maps/CherrygroveCity_Mart/scripts.pory"
	closemessage
# 21 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 22 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 23 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 24 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_EventScript_Bugcatcher::
# 25 "data/maps/CherrygroveCity_Mart/scripts.pory"
	lock
# 26 "data/maps/CherrygroveCity_Mart/scripts.pory"
	faceplayer
# 27 "data/maps/CherrygroveCity_Mart/scripts.pory"
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
# 28 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
# 29 "data/maps/CherrygroveCity_Mart/scripts.pory"
	closemessage
# 30 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 31 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 32 "data/maps/CherrygroveCity_Mart/scripts.pory"
	
# 33 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
# 34 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
# 35 "data/maps/CherrygroveCity_Mart/scripts.pory"
	closemessage
# 36 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 37 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 38 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 39 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_EventScript_Clerk2::
# 40 "data/maps/CherrygroveCity_Mart/scripts.pory"
	pokemart 0
# 41 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 42 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 43 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 44 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 45 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.align 3
# 46 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_Pokemart:
# 47 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 48 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 49 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 50 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
# 51 "data/maps/CherrygroveCity_Mart/scripts.pory"
	end
# 52 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 53 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_Text_CooltrainerM:
# 54 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "They're fresh out of POKé BALLS!\p"
# 55 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "When will they get more of them?$"
# 56 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 57 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
# 58 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "POKé BALLS are in stock!\n"
# 59 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "Now I can catch POKéMON!$"
# 60 "data/maps/CherrygroveCity_Mart/scripts.pory"

# 61 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove_Pokemart_Text_Youngster:
# 62 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "When I was walking in the grass, a\n"
# 63 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "bug POKéMON poisoned my POKéMON!\p"
# 64 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "I just kept going, but then my\n"
# 65 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "POKéMON fainted.\p"
# 66 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "You should keep an ANTIDOTE\n"
# 67 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "with you.$"

Cherrygrove_Mart2::
# 71 "data/maps/CherrygroveCity_Mart/scripts.pory"
	lock
# 72 "data/maps/CherrygroveCity_Mart/scripts.pory"
	faceplayer
# 73 "data/maps/CherrygroveCity_Mart/scripts.pory"
	compare VAR_NEWBARK_TOWN_STATE, 5
	goto_if_lt Cherrygrove_Mart2_2
# 79 "data/maps/CherrygroveCity_Mart/scripts.pory"
	message Cherrygrove_Mart2_Text_1
# 80 "data/maps/CherrygroveCity_Mart/scripts.pory"
	waitmessage
# 81 "data/maps/CherrygroveCity_Mart/scripts.pory"
	pokemart Cherrygrove2
# 82 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox Cherrygrove_Mart2_Text_2
# 83 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
	end

Cherrygrove_Mart2_2:
# 74 "data/maps/CherrygroveCity_Mart/scripts.pory"
	msgbox Cherrygrove_Mart2_Text_0
# 76 "data/maps/CherrygroveCity_Mart/scripts.pory"
	release
	end


	.align 2
# 87 "data/maps/CherrygroveCity_Mart/scripts.pory"
Cherrygrove2:
# 88 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 89 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE

Cherrygrove_Mart2_Text_0:
# 74 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "We're still setting up, come back\n"
	.string "a bit later.$"

Cherrygrove_Mart2_Text_1:
# 79 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "Welcome!$"

Cherrygrove_Mart2_Text_2:
# 82 "data/maps/CherrygroveCity_Mart/scripts.pory"
	.string "Come back soon.$"
