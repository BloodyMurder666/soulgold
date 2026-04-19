# 1 "data/maps/BlackthornCity_Mart/scripts.pory"

# 2 "data/maps/BlackthornCity_Mart/scripts.pory"
BlackthornCity_Mart_MapScripts::
# 3 "data/maps/BlackthornCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/BlackthornCity_Mart/scripts.pory"

# 5 "data/maps/BlackthornCity_Mart/scripts.pory"
BlackthornMart_EventScript_CoolTrainerM::
# 6 "data/maps/BlackthornCity_Mart/scripts.pory"
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
# 7 "data/maps/BlackthornCity_Mart/scripts.pory"
	end
# 8 "data/maps/BlackthornCity_Mart/scripts.pory"

# 9 "data/maps/BlackthornCity_Mart/scripts.pory"
BlackthornMart_EventScript_BlackBelt::
# 10 "data/maps/BlackthornCity_Mart/scripts.pory"
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
# 11 "data/maps/BlackthornCity_Mart/scripts.pory"
	end
# 12 "data/maps/BlackthornCity_Mart/scripts.pory"

# 13 "data/maps/BlackthornCity_Mart/scripts.pory"
BlackthornMart_Text_CooltrainerM:
# 14 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "You can't buy MAX REVIVE, but it\n"
# 15 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "fully restores a fainted POKéMON.\p"
# 16 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "Beware--it won't restore PP, the\n"
# 17 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "POWER POINTS needed for moves.$"
# 18 "data/maps/BlackthornCity_Mart/scripts.pory"

# 19 "data/maps/BlackthornCity_Mart/scripts.pory"
BlackthornMart_Text_BlackBelt:
# 20 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "MAX REPEL keeps weak POKéMON away\n"
# 21 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "from you.\p"
# 22 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "It's the longest lasting of the\n"
# 23 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "REPEL sprays.$"

Blackthorn_Mart2::
# 27 "data/maps/BlackthornCity_Mart/scripts.pory"
	lock
# 28 "data/maps/BlackthornCity_Mart/scripts.pory"
	faceplayer
# 29 "data/maps/BlackthornCity_Mart/scripts.pory"
	message Blackthorn_Mart2_Text_0
# 30 "data/maps/BlackthornCity_Mart/scripts.pory"
	waitmessage
# 31 "data/maps/BlackthornCity_Mart/scripts.pory"
	pokemart Blackthorn2
# 32 "data/maps/BlackthornCity_Mart/scripts.pory"
	msgbox Blackthorn_Mart2_Text_1
# 33 "data/maps/BlackthornCity_Mart/scripts.pory"
	release
	end


	.align 2
# 37 "data/maps/BlackthornCity_Mart/scripts.pory"
Blackthorn2:
# 38 "data/maps/BlackthornCity_Mart/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 39 "data/maps/BlackthornCity_Mart/scripts.pory"
	.2byte ITEM_PREMIER_BALL
# 40 "data/maps/BlackthornCity_Mart/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 41 "data/maps/BlackthornCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 42 "data/maps/BlackthornCity_Mart/scripts.pory"
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE

Blackthorn_Mart2_Text_0:
# 29 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "Welcome! How may I help you?$"

Blackthorn_Mart2_Text_1:
# 32 "data/maps/BlackthornCity_Mart/scripts.pory"
	.string "Come back soon!$"
