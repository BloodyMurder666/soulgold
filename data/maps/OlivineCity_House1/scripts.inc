# 1 "data/maps/OlivineCity_House1/scripts.pory"

# 2 "data/maps/OlivineCity_House1/scripts.pory"
OlivineCity_House1_MapScripts::
# 3 "data/maps/OlivineCity_House1/scripts.pory"
	.byte 0

Olivine_VoltorbTrade::
# 9 "data/maps/OlivineCity_House1/scripts.pory"
	lock
# 10 "data/maps/OlivineCity_House1/scripts.pory"
	faceplayer
# 11 "data/maps/OlivineCity_House1/scripts.pory"
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, Olivine_VoltorbTrade_2
# 14 "data/maps/OlivineCity_House1/scripts.pory"
	ingame_trade INGAME_TRADE_VOLTORB, Olivine_VoltorbTrade_Text_1, VoltorbTrade_Declined, VoltorbTrade_NotRequested, Olivine_VoltorbTrade_Text_2
# 22 "data/maps/OlivineCity_House1/scripts.pory"
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
Olivine_VoltorbTrade_1:
# 24 "data/maps/OlivineCity_House1/scripts.pory"
	release
	end

Olivine_VoltorbTrade_2:
# 12 "data/maps/OlivineCity_House1/scripts.pory"
	msgbox Olivine_VoltorbTrade_Text_0
	goto Olivine_VoltorbTrade_1


VoltorbTrade_Declined::
# 29 "data/maps/OlivineCity_House1/scripts.pory"
	msgbox VoltorbTrade_Declined_Text_0
# 30 "data/maps/OlivineCity_House1/scripts.pory"
	release
	end


VoltorbTrade_NotRequested::
# 35 "data/maps/OlivineCity_House1/scripts.pory"
	msgbox VoltorbTrade_NotRequested_Text_0
# 37 "data/maps/OlivineCity_House1/scripts.pory"
	release
	end


Olivine_VoltorbTrade_Text_0:
# 12 "data/maps/OlivineCity_House1/scripts.pory"
	.string "Hi, how is my old Voltorb doing?$"

Olivine_VoltorbTrade_Text_1:
# 14 "data/maps/OlivineCity_House1/scripts.pory"
	.string "I collect Pokémon\n"
	.string "Do you have a Mareanie?\l"
	.string "Want to trade it for my\l"
	.string "Hisuian Voltorb?$"

Olivine_VoltorbTrade_Text_2:
# 20 "data/maps/OlivineCity_House1/scripts.pory"
	.string "Yay! I got myself a Mareanie!\n"
	.string "Voltorb, you take care!$"

VoltorbTrade_Declined_Text_0:
# 29 "data/maps/OlivineCity_House1/scripts.pory"
	.string "You don't want to trade? Aww...$"

VoltorbTrade_NotRequested_Text_0:
# 35 "data/maps/OlivineCity_House1/scripts.pory"
	.string "Uh, no, I don't think so.\n"
	.string "That doesn't look like a Mareanie.$"
