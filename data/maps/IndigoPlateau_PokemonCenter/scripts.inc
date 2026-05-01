# 1 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 2 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
.set LOCALID_INDIGOPLATEAU_ABRA, 6
# 4 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 5 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_PokemonCenter_MapScripts::
# 6 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	@map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
# 8 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, IndigoPlateau_PokemonCenter_OnLoad
# 9 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.byte 0
# 10 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 11 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_PokemonCenter_OnLoad::
# 12 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_POKEMON_CENTER
# 13 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 14 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 15 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_PokemonCenter_OnFrame::
# 16 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
# 17 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
# 18 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
# 19 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
# 20 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
# 21 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
# 22 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte 0
# 23 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 24 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_PokemonCenter_Enter::
# 25 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	setflag FLAG_VISITED_INDIGO_PLATEAU
# 26 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	setvar VAR_LEAGUE_STATE, 1
# 27 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 28 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 29 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_Cooltrainer::
# 30 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
# 31 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 32 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 33 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_BlackBelt::
# 34 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
# 35 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 36 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 37 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_ShigyNinja::
# 38 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
# 39 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 40 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 41 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_ShigyNinja:
# 42 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "Congrats on making it here!\p"
# 43 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "I've seen tons of trainers come\n"
# 44 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "through here over the years, and\l"
# 45 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "all of them are wonderfully unique.\p"
# 46 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "You should be proud of yourself\n"
# 47 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "for getting this far!\p"
# 48 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "Now, go get em'!$"
# 49 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 50 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_Blackbelt:
# 51 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "The Pokémon League is not taking\n"
# 52 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "new challengers at the moment.\p"
# 53 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "Please check back later.$"
# 54 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 55 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_CooltrainerM:
# 56 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "At the Pokémon League, you'll get\n"
# 57 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "tested by the Elite Four.\p"
# 58 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "You have to beat them all. If you\n"
# 59 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "lose, you have to start all over!$"
# 60 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 61 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_Silver::
# 62 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	lock
# 63 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	faceplayer 
# 64 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
# 65 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
# 66 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
# 67 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
# 68 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
# 69 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
# 70 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	setflag FLAG_DAILY_BEAT_SILVER
# 71 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
# 72 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 73 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 74 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_SilverBeat::
# 75 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
# 76 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	closemessage
# 77 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
# 78 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 79 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 80 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Silver_Battle_Cyndaquil::
# 81 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7, IndigoPlateau_Text_RivalWin
# 82 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	return
# 83 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 84 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Silver_Battle_Totodile::
# 85 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7, IndigoPlateau_Text_RivalWin
# 86 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	return
# 87 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 88 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Silver_Battle_Chikorita::
# 89 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7, IndigoPlateau_Text_RivalWin
# 90 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	return
# 91 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 92 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_RivalEntrance1:
# 93 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Hold it.\p"
# 94 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "You're going to take the Pokémon\n"
# 95 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "League challenge now?\p"
# 96 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "That's not going to happen.\p"
# 97 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "My super-well-trained Pokémon\n"
# 98 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "are going to pound you.\p"
# 99 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "{PLAYER}!\n"
# 100 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "I challenge you!$"
# 101 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 102 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_RivalWin:
# 103 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "…\p"
# 104 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Ok--I lost…$"
# 105 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 106 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_RivalAfter:
# 107 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "…Darn… I still can't win…\p"
# 108 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "I… I have to think more about my\n"
# 109 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Pokémon…\p"
# 110 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Humph! Try not to lose!$"
# 111 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 112 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_Psychic::
# 113 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	lock
# 114 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	faceplayer
# 115 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
# 116 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
# 117 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
# 118 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	closemessage
# 119 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
# 120 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 121 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 122 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_PsychicTeleport::
# 123 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
# 124 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	closemessage
# 125 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 126 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	playbgm MUS_HG_NEW_BARK, TRUE
# 127 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	delay 60
# 128 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 129 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	applymovement LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
# 130 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	waitmovement 0
# 131 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	fadescreen FADE_TO_WHITE
# 132 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	warpteleport MAP_NEW_BARK_TOWN, 20, 12
# 133 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
# 134 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 135 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	
# 136 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPLateau_Movement_Abra:
# 137 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	jump_in_place_right
# 138 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	jump_in_place_right
# 139 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	step_end
# 140 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 141 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_EventScript_Abra::
# 142 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	lock
# 143 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	faceplayer
# 144 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	waitse
# 145 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 146 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
# 147 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	waitmoncry
# 148 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
# 149 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	end
# 150 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 151 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_TeleportGuy1:
# 152 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Ah! You're challenging the Elite\n"
# 153 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Four? Are you sure you're ready?\p"
# 154 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "If you need to train some more,\n"
# 155 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "my Abra can help you.\p"
# 156 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "It can Teleport you home.\p"
# 157 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Would you like to go home now?$"
# 158 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 159 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_TeleportGuyYes:
# 160 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Ok, Ok. Picture your house in your\n"
# 161 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "mind…$"
# 162 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 163 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_TeleportGuyNo:
# 164 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Ok, Ok. The best of luck to you!$"
# 165 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"

# 166 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_Text_Abra:
# 167 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
    .string "Abra: Aabra…$"

IndigoPlateau_StoneMerchant::
# 171 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	lock
# 172 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	faceplayer
# 173 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	message IndigoPlateau_StoneMerchant_Text_0
# 174 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	waitmessage
# 175 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	pokemart IndigoPlateau_StoneMerchantMart
# 176 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	msgbox IndigoPlateau_StoneMerchant_Text_1
# 177 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	release
	end


	.align 2
# 181 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
IndigoPlateau_StoneMerchantMart:
# 182 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 183 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_WATER_STONE
# 184 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 185 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 186 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_MOON_STONE
# 187 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 188 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_ICE_STONE
# 189 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_SUN_STONE
# 190 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 191 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 192 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 193 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 194 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_AUSPICIOUS_ARMOR
# 195 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_NONE

IndigoPlateau_StoneMerchant_Text_0:
# 173 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "Welcome! How may I help you?$"

IndigoPlateau_StoneMerchant_Text_1:
# 176 "data/maps/IndigoPlateau_PokemonCenter/scripts.pory"
	.string "Come back soon!$"
