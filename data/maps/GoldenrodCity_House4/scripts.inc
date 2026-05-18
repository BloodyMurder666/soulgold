GoldenrodCity_House4_MapScripts::
	.byte 0


Golderod_House4_Fatman::
# 4 "data/maps/GoldenrodCity_House4/scripts.pory"
	msgbox Golderod_House4_Fatman_Text_0, MSGBOX_NPC
	return


Goldenrod_House4_Venipede::
# 8 "data/maps/GoldenrodCity_House4/scripts.pory"
	lock
# 9 "data/maps/GoldenrodCity_House4/scripts.pory"
	faceplayer
# 10 "data/maps/GoldenrodCity_House4/scripts.pory"
	playmoncry SPECIES_VENIPEDE, CRY_MODE_NORMAL
# 11 "data/maps/GoldenrodCity_House4/scripts.pory"
	msgbox Goldenrod_House4_Venipede_Text_0
# 12 "data/maps/GoldenrodCity_House4/scripts.pory"
	waitmoncry
# 13 "data/maps/GoldenrodCity_House4/scripts.pory"
	release
	end


Golderod_House4_Fatman_Text_0:
# 4 "data/maps/GoldenrodCity_House4/scripts.pory"
	.string "Some say once Pokémon reaches a\n"
	.string "certain level, it starts to gain more\l"
	.string "abilities. Could that be true?$"

Goldenrod_House4_Venipede_Text_0:
# 11 "data/maps/GoldenrodCity_House4/scripts.pory"
	.string "Hiss!$"
