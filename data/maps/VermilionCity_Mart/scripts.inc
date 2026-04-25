VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_BirdMan::
	msgbox VermilionMart_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_Woman::
	msgbox VermilionMart_Text_Beauty, MSGBOX_NPC
	end

VermilionMart_Text_SuperNerd:
	.string "Team Rocket is no longer in\n"
	.string "Kanto.\p"
	.string "That alone makes me happy.$"

VermilionMart_Text_Beauty:
	.string "I'm thinking about going shopping\n"
	.string "in Saffron.$"
