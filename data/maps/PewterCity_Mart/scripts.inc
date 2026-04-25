PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Nerd::
	msgbox PewterCity_Mart_Text_SuperNerd, MSGBOX_NPC
	end

PewterCity_Mart_Text_Youngster:
	.string "Hi! Check out my Gyarados!\p"
	.string "I raised it from a Magikarp. I can't\n"
	.string "believe how strong it has become.$"

PewterCity_Mart_Text_SuperNerd:
	.string "There once was a weird old man who sold\n"
	.string "Magikarp.\p"
	.string "He was saying the Magikarp from the\n"
	.string "Lake Of Rage were excellent.$"

