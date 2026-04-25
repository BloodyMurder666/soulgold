.set LOCALID_NURSE, 1

CeladonCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "Erika is a master of grass\n"
	.string "POKéMON.\p"
	.string "She'll make you pay if you don't\n"
	.string "watch yourself.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "Team Rocket's hideout is in the\n"
	.string "basement of the Game Corner.\p"
	.string "Oh, wait. That was three years\n"
	.string "ago.$"

Celadon_Text_Eusine1:
	.string "Eusine: Hi!\p"
	.string "I'm back visiting my hometown.\p"
	.string "It's been quite a while.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, have you heard?\p"
	.string "There have been fresh rumors of a\n"
	.string "rainbow-colored POKéMON\n"
	.string "appearing at Tin Tower.\p"
	.string "I've just had my party healed,\n"
	.string "so now I'm headed to Ecruteak.\p"
	.string "I'll be seeing you, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Oh, by the way, {PLAYER}.\p"
	.string "Have you caught the legendary\n"
	.string "POKéMON Raikou and Entei?\p"
	.string "<……><……><……>\p"
	.string "Okay…\p"
	.string "If you catch even one, I hope\n"
	.string "that you'll inform me.\p"
	.string "I'm counting on you, {PLAYER}!$"
