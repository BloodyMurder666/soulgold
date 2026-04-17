# 1 "data/maps/VioletCity_House1/scripts.pory"

# 2 "data/maps/VioletCity_House1/scripts.pory"
VioletCity_House1_MapScripts::
# 3 "data/maps/VioletCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/VioletCity_House1/scripts.pory"

# 5 "data/maps/VioletCity_House1/scripts.pory"
VioletCity_House1_EventScript_Kyle::
# 6 "data/maps/VioletCity_House1/scripts.pory"
	lock
# 7 "data/maps/VioletCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/VioletCity_House1/scripts.pory"
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
# 9 "data/maps/VioletCity_House1/scripts.pory"
	closemessage
# 10 "data/maps/VioletCity_House1/scripts.pory"
	release
# 11 "data/maps/VioletCity_House1/scripts.pory"
	end
# 12 "data/maps/VioletCity_House1/scripts.pory"

# 13 "data/maps/VioletCity_House1/scripts.pory"
VioletCity_House1_Text_PokefanM:
# 14 "data/maps/VioletCity_House1/scripts.pory"
	.string "A POKéMON you get in a trade\n"
# 15 "data/maps/VioletCity_House1/scripts.pory"
	.string "grows quickly.\p"
# 16 "data/maps/VioletCity_House1/scripts.pory"
	.string "But if you don't have the right\n"
# 17 "data/maps/VioletCity_House1/scripts.pory"
	.string "GYM BADGE, they may disobey you.$"

Violet_PawmiTrade::
# 22 "data/maps/VioletCity_House1/scripts.pory"
	lock
# 23 "data/maps/VioletCity_House1/scripts.pory"
	faceplayer
# 24 "data/maps/VioletCity_House1/scripts.pory"
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, Violet_PawmiTrade_2
# 27 "data/maps/VioletCity_House1/scripts.pory"
	ingame_trade INGAME_TRADE_PAWMI, Violet_PawmiTrade_Text_1, PawmiTrade_Declined, PawmiTrade_NotRequested, Violet_PawmiTrade_Text_2
# 35 "data/maps/VioletCity_House1/scripts.pory"
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
Violet_PawmiTrade_1:
# 37 "data/maps/VioletCity_House1/scripts.pory"
	release
	end

Violet_PawmiTrade_2:
# 25 "data/maps/VioletCity_House1/scripts.pory"
	msgbox Violet_PawmiTrade_Text_0
	goto Violet_PawmiTrade_1


PawmiTrade_Declined::
# 42 "data/maps/VioletCity_House1/scripts.pory"
	msgbox PawmiTrade_Declined_Text_0
# 43 "data/maps/VioletCity_House1/scripts.pory"
	release
	end


PawmiTrade_NotRequested::
# 48 "data/maps/VioletCity_House1/scripts.pory"
	msgbox PawmiTrade_NotRequested_Text_0
# 50 "data/maps/VioletCity_House1/scripts.pory"
	release
	end


Violet_PawmiTrade_Text_0:
# 25 "data/maps/VioletCity_House1/scripts.pory"
	.string "Hi, how is my old Pawmi doing?$"

Violet_PawmiTrade_Text_1:
# 27 "data/maps/VioletCity_House1/scripts.pory"
	.string "I collect Pokémon\n"
	.string "Do you have a Cottonee?\l"
	.string "Want to trade it for my\l"
	.string "Pawmi?$"

Violet_PawmiTrade_Text_2:
# 33 "data/maps/VioletCity_House1/scripts.pory"
	.string "Yay! I got myself a Cottonee!\n"
	.string "Pawmi, you take care!$"

PawmiTrade_Declined_Text_0:
# 42 "data/maps/VioletCity_House1/scripts.pory"
	.string "You don't want to trade? Aww...$"

PawmiTrade_NotRequested_Text_0:
# 48 "data/maps/VioletCity_House1/scripts.pory"
	.string "Uh, no, I don't think so.\n"
	.string "That doesn't look like a Cottonee.$"
