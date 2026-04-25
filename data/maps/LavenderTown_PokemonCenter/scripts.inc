.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "To the north of Lavender is Rock\n"
	.string "Tunnel. Go through it to get to\l"
	.string "the Power Plant.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "There's a radio program that plays\n"
	.string "POKé Flute music.\p"
	.string "Oh? Ah, your radio needs an Expn\n"
	.string "Card to tune into it.$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "If the Power Plant isn't running,\n"
	.string "the Magnet Train won't run either…\p"
	.string "It also means the Radio Station\n"
	.string "can't broadcast…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "The Director of the Radio Station\n"
	.string "sure was happy.\p"
	.string "He said they're back on the air\n"
	.string "because the Power Plant is running\l"
	.string "smoothly again.$"
