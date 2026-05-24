# 1 "data/maps/OlivineCity_Mart/scripts.pory"

# 2 "data/maps/OlivineCity_Mart/scripts.pory"
OlivineCity_Mart_MapScripts::
# 3 "data/maps/OlivineCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/OlivineCity_Mart/scripts.pory"

# 5 "data/maps/OlivineCity_Mart/scripts.pory"
OlivineCity_EventScript_Trainer1::
# 6 "data/maps/OlivineCity_Mart/scripts.pory"
	lock
# 7 "data/maps/OlivineCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/OlivineCity_Mart/scripts.pory"
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
# 9 "data/maps/OlivineCity_Mart/scripts.pory"
	closemessage
# 10 "data/maps/OlivineCity_Mart/scripts.pory"
	release
# 11 "data/maps/OlivineCity_Mart/scripts.pory"
	end
# 12 "data/maps/OlivineCity_Mart/scripts.pory"

# 13 "data/maps/OlivineCity_Mart/scripts.pory"
OlivineCity_EventScript_Lass::
# 14 "data/maps/OlivineCity_Mart/scripts.pory"
	lock
# 15 "data/maps/OlivineCity_Mart/scripts.pory"
	faceplayer
# 16 "data/maps/OlivineCity_Mart/scripts.pory"
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
# 17 "data/maps/OlivineCity_Mart/scripts.pory"
	closemessage
# 18 "data/maps/OlivineCity_Mart/scripts.pory"
	release
# 19 "data/maps/OlivineCity_Mart/scripts.pory"
	end
# 20 "data/maps/OlivineCity_Mart/scripts.pory"

# 21 "data/maps/OlivineCity_Mart/scripts.pory"
OlivineCity_Text_MartCooltrainerF:
# 22 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "Do your Pokémon already know\n"
# 23 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "the move for carrying people\l"
# 24 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "across water?$"
# 25 "data/maps/OlivineCity_Mart/scripts.pory"

# 26 "data/maps/OlivineCity_Mart/scripts.pory"
OlivineCity_Text_MartLass:
# 27 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "My Butterfree came from my\n"
# 28 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "boyfriend overseas.\p"
# 29 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "It carried some Mail from him.\p"
# 30 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "Want to know what it says?\p"
# 31 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "Let's see... Nope! It's a\n"
# 32 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "secret!$"

Olivine_Mart2::
# 36 "data/maps/OlivineCity_Mart/scripts.pory"
	lock
# 37 "data/maps/OlivineCity_Mart/scripts.pory"
	faceplayer
# 38 "data/maps/OlivineCity_Mart/scripts.pory"
	message Olivine_Mart2_Text_0
# 39 "data/maps/OlivineCity_Mart/scripts.pory"
	waitmessage
# 40 "data/maps/OlivineCity_Mart/scripts.pory"
	pokemart Olivine2
# 41 "data/maps/OlivineCity_Mart/scripts.pory"
	msgbox Olivine_Mart2_Text_1
# 42 "data/maps/OlivineCity_Mart/scripts.pory"
	release
	end


	.align 2
# 46 "data/maps/OlivineCity_Mart/scripts.pory"
Olivine2:
# 47 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_TM_SKY_DROP
# 48 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_TM_BRUTAL_SWING
# 49 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 50 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 51 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 52 "data/maps/OlivineCity_Mart/scripts.pory"
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE

Olivine_Mart2_Text_0:
# 38 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "Welcome! How may I help you?$"

Olivine_Mart2_Text_1:
# 41 "data/maps/OlivineCity_Mart/scripts.pory"
	.string "Come back soon!$"
