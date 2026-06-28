# 1 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 2 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 3 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
Route30_MrPokemonsHouse_MapScripts::
# 4 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
# 5 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.byte 0
# 6 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 7 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_OnFrame::
# 8 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
# 9 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.2byte 0
# 10 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 11 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_GiveEgg::
# 12 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	lock
# 13 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	playse SE_PIN
# 14 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
# 15 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	delay 60
# 16 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
# 17 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_GENTLEMAN
# 18 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
# 19 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 20 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 21 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
# 22 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	waitmovement 0
# 23 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_GENTLEMAN
# 24 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT
# 25 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 26 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	giveitem ITEM_MYSTERY_EGG
# 27 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 28 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_GENTLEMAN
# 29 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
# 30 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
# 31 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 32 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
# 33 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_GENTLEMAN
# 34 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
# 35 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 36 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 37 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	playbgm MUS_HG_OAK, TRUE
# 38 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
# 39 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	waitmovement 0 
# 40 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 41 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_OAK
# 42 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
# 43 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 44 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 45 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 46 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 47 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	message MrPokemonHouse_Text_GetDex
# 48 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	waitfanfare
# 49 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 50 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_OAK
# 51 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_OakParting MSGBOX_DEFAULT
# 52 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 53 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 54 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
# 55 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	playse SE_EXIT
# 57 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	removeobject LOCALID_ROUTE30_OAK
# 58 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setflag FLAG_DELIVERED_EGG
# 59 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
# 60 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	fadedefaultbgm
# 61 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    createfieldmugshot MUGSHOT_GENTLEMAN
# 62 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
# 63 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 64 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
# 65 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 66 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
    removefieldmugshot
# 67 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
# 68 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	removeobject LOCALID_MRPOKEMON
# 70 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	clearflag FLAG_HIDE_MRPOKEMON
# 71 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	addobject LOCALID_MRPOKEMON2
# 72 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	
# 73 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
# 74 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
# 75 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 76 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	special EnableNationalPokedex
# 77 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setflag FLAG_DEXNAV_OBTAINED
# 78 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	clearflag FLAG_HIDE_LAB_POLICEMAN
# 79 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
# 80 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
# 81 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
# 82 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
# 83 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
# 84 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 85 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 86 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 87 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 88 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_MrPokemon::
# 89 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	lock
# 90 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	faceplayer
# 91 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	checkitem ITEM_RED_SCALE
# 92 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
# 93 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
# 94 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 95 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 96 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 97 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 98 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_MrPokemon_RedScale::
# 99 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
# 100 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
# 101 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
# 102 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	closemessage
# 103 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 104 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end	
# 105 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 106 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
# 107 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	removeitem ITEM_RED_SCALE
# 108 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	giveitem ITEM_FAIRYTITE
# 109 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 110 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 111 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 112 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 113 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 114 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_Computer::
# 115 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	lock
# 116 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
# 117 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 118 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 119 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 120 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_Magazine::
# 121 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	lock
# 122 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
# 123 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 124 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 125 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 126 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_EventScript_Coins::
# 127 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	lock
# 128 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
# 129 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	release
# 130 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	end
# 131 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 132 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Movement_MeetMrPokemon:
# 133 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_up
# 134 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_up
# 135 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_right
# 136 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_right
# 137 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	face_up
# 138 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	step_end
# 139 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 140 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Movement_OakToPlayer:
# 141 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_down
# 142 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	face_left
# 143 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	step_end
# 144 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 145 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Movement_OakLeave:
# 146 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_down
# 147 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_left
# 148 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_left
# 149 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_left
# 150 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_down
# 151 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_in_place_down
# 152 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	step_end
# 153 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 154 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Movement_MrPokemon_Leave:
# 155 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_up
# 156 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_left
# 157 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	walk_left
# 158 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	step_end
# 159 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 160 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Intro1:
# 161 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Hello, hello! You must be\n"
# 162 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER}.\p"
# 163 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Prof.Elm said that you would\n"
# 164 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "visit.$"
# 165 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 166 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Intro2:
# 167 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "This is what I want Prof.Elm\n"
# 168 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "to examine.$"
# 169 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 170 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_GotEgg:
# 171 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER} received Mystery Egg.$"
# 172 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 173 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Intro3:
# 174 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I know a couple who run a\n"
# 175 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Pokémon Day-Care service.\p"
# 176 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "They gave me that Egg.\p"
# 177 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I was intrigued, so I sent\n"
# 178 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "mail to Prof.Elm.\p"
# 179 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "For Pokémon evolution,\n"
# 180 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Prof.Elm is the authority.$"
# 181 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 182 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 183 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Intro4:
# 184 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Even Prof.Oak here recognizes\n"
# 185 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "that.$"
# 186 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 187 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Intro5:
# 188 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "If my assumption is correct,\n"
# 189 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Prof.Elm will know it.$"
# 190 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 191 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Heal:
# 192 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "You are returning to Prof.Elm?\p"
# 193 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Here. Your Pokémon should have\n"
# 194 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "some rest.$"
# 195 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 196 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_DependingOnYou:
# 197 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I'm depending on you!$"
# 198 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 199 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_AlwaysNewDiscoveries:
# 200 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Life is delightful!\n"
# 201 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Always, new discoveries to be made.$"
# 202 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 203 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_OakIntro:
# 204 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Oak: Aha! So you're {PLAYER}!\p"
# 205 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I'm Oak! A Pokémon researcher.\p"
# 206 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I was just visiting my old friend\n"
# 207 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Mr. Pokémon.\p"
# 208 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I heard you were running an errand\n"
# 209 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "for Prof.Elm, so I waited here.\p"
# 210 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Oh! What's this? A rare Pokémon!\p"
# 211 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Let's see…\n"
# 212 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Hm, I see!\p"
# 213 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I understand why Prof.Elm gave\n"
# 214 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "you a Pokémon for this errand.\p"
# 215 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "To researchers like Prof.Elm and\n"
# 216 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I, Pokémon are our friends.\p"
# 217 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "He saw that you would treat your\n"
# 218 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Pokémon with love and care.\p"
# 219 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "…Ah!\p"
# 220 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "You seem to be dependable. How\n"
# 221 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "would you like to help me out?\p"
# 222 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "See? This is the latest version of\n"
# 223 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "the Pokédex.\p"
# 224 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "It automatically records data on\n"
# 225 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Pokémon you've seen or caught.\p"
# 226 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "It's a hi-tech encyclopedia!\p"
# 227 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "It shows their habitats, how\n"
# 228 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "they evolve, and their moves.$"
# 229 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 230 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_GetDex:
# 231 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER} received Pokédex!$"
# 232 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 233 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_OakParting:
# 234 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Go meet many kinds of Pokémon and\n"
# 235 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "complete that Pokédex!\p"
# 236 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "But I've stayed too long.\p"
# 237 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I have to get to Goldenrod\n"
# 238 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "for my usual radio show.\p"
# 239 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER}, I'm counting on you!$"
# 240 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 241 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_GimmeTheScale:
# 242 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Hm? That Scale! What's that?\n"
# 243 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "A red Gyarados?\p"
# 244 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "That's rare! I, I want it…\p"
# 245 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER}, would you care to\n"
# 246 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "trade it?\p"
# 247 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I can offer this Mega Stone\n"
# 248 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "that I got from Prof.Oak.$"
# 249 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 250 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_Disappointed:
# 251 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "That's disappointing.\n"
# 252 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "That happens to be very rare.$"
# 253 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 254 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_ExpShare:
# 255 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "I also have a special item\n"
# 256 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "for you.$"
# 257 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 258 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_ForeignMagazines:
# 259 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "It's packed with foreign\n"
# 260 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "magazines.\p"
# 261 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Can't even read their titles…$"
# 262 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 263 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_BrokenComputer:
# 264 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "It's a big computer.\n"
# 265 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Hmm. It's broken.$"
# 266 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 267 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_StrangeCoins:
# 268 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "A whole pile of strange coins!\p"
# 269 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "Maybe they're from another\n"
# 270 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "country…$"
# 271 "data/maps/Route30_MrPokemonsHouse/scripts.pory"

# 272 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
MrPokemonHouse_Text_GotExpShare:
# 273 "data/maps/Route30_MrPokemonsHouse/scripts.pory"
	.string "{PLAYER} received Eviolite!$"
