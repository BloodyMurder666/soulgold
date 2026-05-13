# 1 "data/maps/BlackthornCity_House2/scripts.pory"

# 2 "data/maps/BlackthornCity_House2/scripts.pory"
BlackthornCity_House2_MapScripts::
# 3 "data/maps/BlackthornCity_House2/scripts.pory"
	.byte 0

Blackthorn_GabiteTrade::
# 8 "data/maps/BlackthornCity_House2/scripts.pory"
	lock
# 9 "data/maps/BlackthornCity_House2/scripts.pory"
	faceplayer
# 10 "data/maps/BlackthornCity_House2/scripts.pory"
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, Blackthorn_GabiteTrade_2
# 13 "data/maps/BlackthornCity_House2/scripts.pory"
	ingame_trade INGAME_TRADE_GABITE, Blackthorn_GabiteTrade_Text_1, GabiteTrade_Declined, GabiteTrade_NotRequested, Blackthorn_GabiteTrade_Text_2
# 19 "data/maps/BlackthornCity_House2/scripts.pory"
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
Blackthorn_GabiteTrade_1:
# 21 "data/maps/BlackthornCity_House2/scripts.pory"
	release
	end

Blackthorn_GabiteTrade_2:
# 11 "data/maps/BlackthornCity_House2/scripts.pory"
	msgbox Blackthorn_GabiteTrade_Text_0
	goto Blackthorn_GabiteTrade_1


GabiteTrade_Declined::
# 26 "data/maps/BlackthornCity_House2/scripts.pory"
	msgbox GabiteTrade_Declined_Text_0
# 27 "data/maps/BlackthornCity_House2/scripts.pory"
	release
	end


GabiteTrade_NotRequested::
# 32 "data/maps/BlackthornCity_House2/scripts.pory"
	msgbox GabiteTrade_NotRequested_Text_0
# 34 "data/maps/BlackthornCity_House2/scripts.pory"
	release
	end


Blackthorn_GabiteTrade_Text_0:
# 11 "data/maps/BlackthornCity_House2/scripts.pory"
	.string "How has my Gabite been?$"

Blackthorn_GabiteTrade_Text_1:
# 13 "data/maps/BlackthornCity_House2/scripts.pory"
	.string "Hello. I gather Dragon-type Pokémon.\n"
	.string "Do you have Dragonair? I'm willing to \l"
	.string "trade it for Gabite.$"

Blackthorn_GabiteTrade_Text_2:
# 18 "data/maps/BlackthornCity_House2/scripts.pory"
	.string "Thank you very much.$"

GabiteTrade_Declined_Text_0:
# 26 "data/maps/BlackthornCity_House2/scripts.pory"
	.string "If you find one, come trade with me!$"

GabiteTrade_NotRequested_Text_0:
# 32 "data/maps/BlackthornCity_House2/scripts.pory"
	.string "That doesn't look like a Dragonair to\n"
	.string "me.$"
