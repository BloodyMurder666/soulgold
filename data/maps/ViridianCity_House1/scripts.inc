ViridianCity_House1_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "Do you put a lot of thought into\n"
	.string "naming your POKéMON?\p"
	.string "Giving them good nicknames adds to\n"
	.string "the fun of trading with others.$"

ViridianCity_House1_Text_Lass:
	.string "They're Speary--a Spearow--and\n"
	.string "Rattey--a Rattata.$"

ViridianCity_House1_Text_Speary:
	.string "Speary: Ch-chun!$"

ViridianCity_House1_Text_Rattey:
	.string "Rattey: Kikiii!$"

