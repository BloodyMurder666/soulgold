# 1 "data/maps/EcruteakCity_Mart/scripts.pory"

# 2 "data/maps/EcruteakCity_Mart/scripts.pory"
EcruteakCity_Mart_MapScripts::
# 3 "data/maps/EcruteakCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/EcruteakCity_Mart/scripts.pory"

# 5 "data/maps/EcruteakCity_Mart/scripts.pory"
EcruteakCity_Mart_EventScript_Nerd::
# 6 "data/maps/EcruteakCity_Mart/scripts.pory"
	lock
# 7 "data/maps/EcruteakCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/EcruteakCity_Mart/scripts.pory"
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
# 9 "data/maps/EcruteakCity_Mart/scripts.pory"
	closemessage
# 10 "data/maps/EcruteakCity_Mart/scripts.pory"
	release
# 11 "data/maps/EcruteakCity_Mart/scripts.pory"
	end
# 12 "data/maps/EcruteakCity_Mart/scripts.pory"

# 13 "data/maps/EcruteakCity_Mart/scripts.pory"
EcruteakCity_Mart_EventScript_Granny::
# 14 "data/maps/EcruteakCity_Mart/scripts.pory"
	lock
# 15 "data/maps/EcruteakCity_Mart/scripts.pory"
	faceplayer
# 16 "data/maps/EcruteakCity_Mart/scripts.pory"
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
# 17 "data/maps/EcruteakCity_Mart/scripts.pory"
	closemessage
# 18 "data/maps/EcruteakCity_Mart/scripts.pory"
	release
# 19 "data/maps/EcruteakCity_Mart/scripts.pory"
	end
# 20 "data/maps/EcruteakCity_Mart/scripts.pory"

# 21 "data/maps/EcruteakCity_Mart/scripts.pory"
EcruteakMart_Text_SuperNerd:
# 22 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "My Eevee evolved into an Espeon.\p"
# 23 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "But my friend's Eevee turned into\n"
# 24 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "an Umbreon.\p"
# 25 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "I wonder why? We both were raising\n"
# 26 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "our Eevee in the same way…$"
# 27 "data/maps/EcruteakCity_Mart/scripts.pory"

# 28 "data/maps/EcruteakCity_Mart/scripts.pory"
EcruteakMart_Text_Granny:
# 29 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "If you use Revive, a POKéMON that's\n"
# 30 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "fainted will wake right up.$"

Ecruteak_Mart2::
# 34 "data/maps/EcruteakCity_Mart/scripts.pory"
	lock
# 35 "data/maps/EcruteakCity_Mart/scripts.pory"
	faceplayer
# 36 "data/maps/EcruteakCity_Mart/scripts.pory"
	message Ecruteak_Mart2_Text_0
# 37 "data/maps/EcruteakCity_Mart/scripts.pory"
	waitmessage
# 38 "data/maps/EcruteakCity_Mart/scripts.pory"
	pokemart Ecruteak2
# 39 "data/maps/EcruteakCity_Mart/scripts.pory"
	msgbox Ecruteak_Mart2_Text_1
# 40 "data/maps/EcruteakCity_Mart/scripts.pory"
	release
	end


	.align 2
# 44 "data/maps/EcruteakCity_Mart/scripts.pory"
Ecruteak2:
# 45 "data/maps/EcruteakCity_Mart/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 46 "data/maps/EcruteakCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 47 "data/maps/EcruteakCity_Mart/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 48 "data/maps/EcruteakCity_Mart/scripts.pory"
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_NONE

Ecruteak_Mart2_Text_0:
# 36 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "Welcome! How may I help you?$"

Ecruteak_Mart2_Text_1:
# 39 "data/maps/EcruteakCity_Mart/scripts.pory"
	.string "Come back soon!$"
