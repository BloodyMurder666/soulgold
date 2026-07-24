RintoVillage_Mart_MapScripts::
	.byte 0


Rinto_Mart2::
# 4 "data/maps/RintoVillage_Mart/scripts.pory"
	lock
# 5 "data/maps/RintoVillage_Mart/scripts.pory"
	faceplayer
# 6 "data/maps/RintoVillage_Mart/scripts.pory"
	message Rinto_Mart2_Text_0
# 7 "data/maps/RintoVillage_Mart/scripts.pory"
	waitmessage
# 8 "data/maps/RintoVillage_Mart/scripts.pory"
	pokemart Rinto2
# 9 "data/maps/RintoVillage_Mart/scripts.pory"
	msgbox Rinto_Mart2_Text_1
# 10 "data/maps/RintoVillage_Mart/scripts.pory"
	release
	end


	.align 2
# 14 "data/maps/RintoVillage_Mart/scripts.pory"
Rinto2:
# 15 "data/maps/RintoVillage_Mart/scripts.pory"
	.2byte ITEM_TM_BRICK_BREAK
# 16 "data/maps/RintoVillage_Mart/scripts.pory"
	.2byte ITEM_TM_FACADE
# 17 "data/maps/RintoVillage_Mart/scripts.pory"
	.2byte ITEM_TM_PLAY_ROUGH
# 18 "data/maps/RintoVillage_Mart/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 19 "data/maps/RintoVillage_Mart/scripts.pory"
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NONE

RintoMart_Youngster::
# 23 "data/maps/RintoVillage_Mart/scripts.pory"
	msgbox RintoMart_Youngster_Text_0, MSGBOX_NPC
	return


RintoMart_Beauty::
# 31 "data/maps/RintoVillage_Mart/scripts.pory"
	msgbox RintoMart_Beauty_Text_0, MSGBOX_NPC
	return


Rinto_Mart2_Text_0:
# 6 "data/maps/RintoVillage_Mart/scripts.pory"
	.string "Welcome! How may I help you?$"

Rinto_Mart2_Text_1:
# 9 "data/maps/RintoVillage_Mart/scripts.pory"
	.string "Come back soon!$"

RintoMart_Youngster_Text_0:
# 23 "data/maps/RintoVillage_Mart/scripts.pory"
	.string "Every Poké Mart in Johto stocks its\n"
	.string "own selection of TMs.\p"
	.string "Collecting them all gets expensive!$"

RintoMart_Beauty_Text_0:
# 31 "data/maps/RintoVillage_Mart/scripts.pory"
	.string "I'm just hanging out here for the air\n"
	.string "conditioning.$"
