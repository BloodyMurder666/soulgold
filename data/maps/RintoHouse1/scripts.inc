RintoHouse1_MapScripts::
	.byte 0


RintoHouse1_Vullaby::
# 4 "data/maps/RintoHouse1/scripts.pory"
	lock
# 5 "data/maps/RintoHouse1/scripts.pory"
	faceplayer
# 6 "data/maps/RintoHouse1/scripts.pory"
	playmoncry SPECIES_VULLABY, CRY_MODE_NORMAL
# 7 "data/maps/RintoHouse1/scripts.pory"
	msgbox RintoHouse1_Vullaby_Text_0
# 8 "data/maps/RintoHouse1/scripts.pory"
	waitmoncry
# 9 "data/maps/RintoHouse1/scripts.pory"
	release
	end


RintoHouse1_Girl::
# 14 "data/maps/RintoHouse1/scripts.pory"
	msgbox RintoHouse1_Girl_Text_0, MSGBOX_NPC
	return


RintoHouse1_Mom::
# 20 "data/maps/RintoHouse1/scripts.pory"
	msgbox RintoHouse1_Mom_Text_0, MSGBOX_NPC
	return


RintoHouse1_Vullaby_Text_0:
# 7 "data/maps/RintoHouse1/scripts.pory"
	.string "Vullaby: Vuvaaaaaa!$"

RintoHouse1_Girl_Text_0:
# 14 "data/maps/RintoHouse1/scripts.pory"
	.string "I heard that several Pokémon evolve\n"
	.string "much earlier in Johto than they do\l"
	.string "in other regions.$"

RintoHouse1_Mom_Text_0:
# 20 "data/maps/RintoHouse1/scripts.pory"
	.string "Our Vullaby has been eating a lot\n"
	.string "lately.\p"
	.string "It might be close to evolving.$"
