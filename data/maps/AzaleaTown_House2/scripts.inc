AzaleaTown_House2_MapScripts::
	.byte 0


Azalea_SlowpokeTrade::
# 4 "data/maps/AzaleaTown_House2/scripts.pory"
	lock
# 5 "data/maps/AzaleaTown_House2/scripts.pory"
	faceplayer
# 6 "data/maps/AzaleaTown_House2/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_TRADE, Azalea_SlowpokeTrade_2
# 9 "data/maps/AzaleaTown_House2/scripts.pory"
	ingame_trade INGAME_TRADE_SLOWPOKE, Azalea_SlowpokeTrade_Text_1, SlowpokeTrade_Declined, SlowpokeTrade_NotRequested, Azalea_SlowpokeTrade_Text_2
# 17 "data/maps/AzaleaTown_House2/scripts.pory"
	setflag FLAG_SLOWPOKE_TRADE
Azalea_SlowpokeTrade_1:
# 19 "data/maps/AzaleaTown_House2/scripts.pory"
	release
	end

Azalea_SlowpokeTrade_2:
# 7 "data/maps/AzaleaTown_House2/scripts.pory"
	msgbox Azalea_SlowpokeTrade_Text_0
	goto Azalea_SlowpokeTrade_1


SlowpokeTrade_Declined::
# 24 "data/maps/AzaleaTown_House2/scripts.pory"
	msgbox SlowpokeTrade_Declined_Text_0
# 26 "data/maps/AzaleaTown_House2/scripts.pory"
	release
	end


SlowpokeTrade_NotRequested::
# 31 "data/maps/AzaleaTown_House2/scripts.pory"
	msgbox SlowpokeTrade_NotRequested_Text_0
# 33 "data/maps/AzaleaTown_House2/scripts.pory"
	release
	end


Azalea_SlowpokeTrade_Text_0:
# 7 "data/maps/AzaleaTown_House2/scripts.pory"
	.string "Have you been amassing more slowpokes?$"

Azalea_SlowpokeTrade_Text_1:
# 9 "data/maps/AzaleaTown_House2/scripts.pory"
	.string "I love Slowpokes! They are adorable,\n"
	.string "cuddly, cute, sweet, amazing and\l"
	.string "awesome! How about I prove it to you?\l"
	.string "I'll give you one of my finest slowpokes\l"
	.string "if you give me one of yours.$"

Azalea_SlowpokeTrade_Text_2:
# 16 "data/maps/AzaleaTown_House2/scripts.pory"
	.string "Another one joins the cult of slowpoke.$"

SlowpokeTrade_Declined_Text_0:
# 24 "data/maps/AzaleaTown_House2/scripts.pory"
	.string "Huh? Don't you understand how amazing\n"
	.string "slowpokes are?!?$"

SlowpokeTrade_NotRequested_Text_0:
# 31 "data/maps/AzaleaTown_House2/scripts.pory"
	.string "Hey! That's not a real slowpoke! Are you\n"
	.string "trying to offer me an inferior Pokémon?$"
