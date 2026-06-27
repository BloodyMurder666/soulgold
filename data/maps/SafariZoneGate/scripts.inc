# 1 "data/maps/SafariZoneGate/scripts.pory"

# 2 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_MapScripts::
# 3 "data/maps/SafariZoneGate/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_OnTransition
# 4 "data/maps/SafariZoneGate/scripts.pory"
	.byte 0
# 5 "data/maps/SafariZoneGate/scripts.pory"

# 6 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_OnTransition::
# 7 "data/maps/SafariZoneGate/scripts.pory"
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
# 8 "data/maps/SafariZoneGate/scripts.pory"
	end
# 9 "data/maps/SafariZoneGate/scripts.pory"

# 10 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_Trigger::
# 11 "data/maps/SafariZoneGate/scripts.pory"
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
# 12 "data/maps/SafariZoneGate/scripts.pory"
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
# 13 "data/maps/SafariZoneGate/scripts.pory"
	setflag FLAG_GARBAGEFLAG
# 14 "data/maps/SafariZoneGate/scripts.pory"
	setvar VAR_SAFARI_ZONE_GATE_STATE, 3
# 15 "data/maps/SafariZoneGate/scripts.pory"
	end
# 16 "data/maps/SafariZoneGate/scripts.pory"

# 17 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_WorkerM::
# 18 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 19 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 20 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_ForeignFeeling, MSGBOX_DEFAULT
# 21 "data/maps/SafariZoneGate/scripts.pory"
	closemessage
# 22 "data/maps/SafariZoneGate/scripts.pory"
	release
# 23 "data/maps/SafariZoneGate/scripts.pory"
	end
# 24 "data/maps/SafariZoneGate/scripts.pory"

# 25 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_Silent::
# 26 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 27 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 28 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_SilentNPC, MSGBOX_DEFAULT
# 29 "data/maps/SafariZoneGate/scripts.pory"
	closemessage
# 30 "data/maps/SafariZoneGate/scripts.pory"
	release
# 31 "data/maps/SafariZoneGate/scripts.pory"
	end
# 32 "data/maps/SafariZoneGate/scripts.pory"

# 33 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_Kangaskhan::
# 34 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 35 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 36 "data/maps/SafariZoneGate/scripts.pory"
	waitse
# 37 "data/maps/SafariZoneGate/scripts.pory"
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
# 38 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_Kangaskhan, MSGBOX_DEFAULT
# 39 "data/maps/SafariZoneGate/scripts.pory"
	waitmoncry
# 40 "data/maps/SafariZoneGate/scripts.pory"
	release
# 41 "data/maps/SafariZoneGate/scripts.pory"
	end
# 42 "data/maps/SafariZoneGate/scripts.pory"

# 43 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_Engineer::
# 44 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 45 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 46 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_JigglypuffTrainer, MSGBOX_DEFAULT
# 47 "data/maps/SafariZoneGate/scripts.pory"
	closemessage
# 48 "data/maps/SafariZoneGate/scripts.pory"
	release
# 49 "data/maps/SafariZoneGate/scripts.pory"
	end
# 50 "data/maps/SafariZoneGate/scripts.pory"

# 51 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_Girl::
# 52 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 53 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 54 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_FirstCatch, MSGBOX_DEFAULT
# 55 "data/maps/SafariZoneGate/scripts.pory"
	closemessage
# 56 "data/maps/SafariZoneGate/scripts.pory"
	release
# 57 "data/maps/SafariZoneGate/scripts.pory"
	end
# 58 "data/maps/SafariZoneGate/scripts.pory"

# 59 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_SlowpokeLady::
# 60 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 61 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 62 "data/maps/SafariZoneGate/scripts.pory"
	msgbox SafariZone_Text_SlowpokeFan, MSGBOX_DEFAULT
# 63 "data/maps/SafariZoneGate/scripts.pory"
	closemessage
# 64 "data/maps/SafariZoneGate/scripts.pory"
	release
# 65 "data/maps/SafariZoneGate/scripts.pory"
	end
# 66 "data/maps/SafariZoneGate/scripts.pory"

# 67 "data/maps/SafariZoneGate/scripts.pory"

# 68 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_ForeignFeeling:
# 69 "data/maps/SafariZoneGate/scripts.pory"
	.string "Safari Zone...\n"
# 70 "data/maps/SafariZoneGate/scripts.pory"
	.string "It makes me feel like I am in a\l"
# 71 "data/maps/SafariZoneGate/scripts.pory"
	.string "foreign country.\p"
# 72 "data/maps/SafariZoneGate/scripts.pory"
	.string "It brings up a strange feeling.$"
# 73 "data/maps/SafariZoneGate/scripts.pory"

# 74 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_SilentNPC:
# 75 "data/maps/SafariZoneGate/scripts.pory"
	.string "..................\p"
# 76 "data/maps/SafariZoneGate/scripts.pory"
	.string "(I am not a talker.)$"
# 77 "data/maps/SafariZoneGate/scripts.pory"

# 78 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_Kangaskhan:
# 79 "data/maps/SafariZoneGate/scripts.pory"
	.string "Kangaskhan: ..................$"
# 80 "data/maps/SafariZoneGate/scripts.pory"

# 81 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_JigglypuffTrainer:
# 82 "data/maps/SafariZoneGate/scripts.pory"
	.string "This Safari Zone is great!\n"
# 83 "data/maps/SafariZoneGate/scripts.pory"
	.string "I just kept going after Pokémon!\p"
# 84 "data/maps/SafariZoneGate/scripts.pory"
	.string "That made my Jigglypuff upset though.$"
# 85 "data/maps/SafariZoneGate/scripts.pory"

# 86 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_FirstCatch:
# 87 "data/maps/SafariZoneGate/scripts.pory"
	.string "I have always wanted to catch my first\n"
# 88 "data/maps/SafariZoneGate/scripts.pory"
	.string "Pokémon at the Safari Zone.$"
# 89 "data/maps/SafariZoneGate/scripts.pory"

# 90 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_SlowpokeFan:
# 91 "data/maps/SafariZoneGate/scripts.pory"
	.string "There are many Pokémon to choose from,\n"
# 92 "data/maps/SafariZoneGate/scripts.pory"
	.string "but nothing beats the cuteness of\l"
# 93 "data/maps/SafariZoneGate/scripts.pory"
	.string "Slowpoke.\p"
# 94 "data/maps/SafariZoneGate/scripts.pory"
	.string "People often say that I look like one!$"
# 95 "data/maps/SafariZoneGate/scripts.pory"

# 96 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_CustomSystem:
# 97 "data/maps/SafariZoneGate/scripts.pory"
	.string "You may be under the impression there\n"
# 98 "data/maps/SafariZoneGate/scripts.pory"
	.string "is a sophisticated system to\l"
# 99 "data/maps/SafariZoneGate/scripts.pory"
	.string "customizing the Safari Zone, right?\p"
# 100 "data/maps/SafariZoneGate/scripts.pory"
	.string "The real truth is that...$"
# 101 "data/maps/SafariZoneGate/scripts.pory"

# 102 "data/maps/SafariZoneGate/scripts.pory"
SafariZone_Text_Sign:
# 103 "data/maps/SafariZoneGate/scripts.pory"
	.string "Safari Zone\n"
# 104 "data/maps/SafariZoneGate/scripts.pory"
	.string "This is where everything is thrilling.\p"
# 105 "data/maps/SafariZoneGate/scripts.pory"
	.string "Feel free to come by and experience\n"
# 106 "data/maps/SafariZoneGate/scripts.pory"
	.string "the wild!$"
# 107 "data/maps/SafariZoneGate/scripts.pory"

# 108 "data/maps/SafariZoneGate/scripts.pory"

# 109 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_IncenseClerk::
# 110 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 111 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 112 "data/maps/SafariZoneGate/scripts.pory"
	message gText_HowMayIServeYou
# 113 "data/maps/SafariZoneGate/scripts.pory"
	waitmessage
# 114 "data/maps/SafariZoneGate/scripts.pory"
	pokemart SafariZoneGateMart1
# 115 "data/maps/SafariZoneGate/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 116 "data/maps/SafariZoneGate/scripts.pory"
	release
# 117 "data/maps/SafariZoneGate/scripts.pory"
	end
# 118 "data/maps/SafariZoneGate/scripts.pory"

# 119 "data/maps/SafariZoneGate/scripts.pory"
	.align 2
# 120 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_Pokemart_Incenses:
# 121 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_SEA_INCENSE
# 122 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_LAX_INCENSE
# 123 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_ROCK_INCENSE
# 124 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_FULL_INCENSE
# 125 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_WAVE_INCENSE
# 126 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_ROSE_INCENSE
# 127 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_LUCK_INCENSE
# 128 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_PURE_INCENSE
# 129 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_NONE
# 130 "data/maps/SafariZoneGate/scripts.pory"
	release
# 131 "data/maps/SafariZoneGate/scripts.pory"
	end
# 132 "data/maps/SafariZoneGate/scripts.pory"

# 133 "data/maps/SafariZoneGate/scripts.pory"

# 134 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_IncenseClerkFinite::
# 135 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 136 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 137 "data/maps/SafariZoneGate/scripts.pory"
	message gText_HowMayIServeYou
# 138 "data/maps/SafariZoneGate/scripts.pory"
	waitmessage
# 139 "data/maps/SafariZoneGate/scripts.pory"
	pokemart SafariZoneGateMart2
# 140 "data/maps/SafariZoneGate/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 141 "data/maps/SafariZoneGate/scripts.pory"
	release
# 142 "data/maps/SafariZoneGate/scripts.pory"
	end
# 143 "data/maps/SafariZoneGate/scripts.pory"

# 144 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_EventScript_VitaminGuru::
# 145 "data/maps/SafariZoneGate/scripts.pory"
	lock
# 146 "data/maps/SafariZoneGate/scripts.pory"
	faceplayer
# 147 "data/maps/SafariZoneGate/scripts.pory"
	message SafariZoneGate_Text_VitaminGuruSellWhatYouNeed
# 148 "data/maps/SafariZoneGate/scripts.pory"
	waitmessage
# 149 "data/maps/SafariZoneGate/scripts.pory"
	pokemart SafariZoneGateMart2
# 150 "data/maps/SafariZoneGate/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 151 "data/maps/SafariZoneGate/scripts.pory"
	release
# 152 "data/maps/SafariZoneGate/scripts.pory"
	end
# 153 "data/maps/SafariZoneGate/scripts.pory"

# 154 "data/maps/SafariZoneGate/scripts.pory"

# 155 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGate_Text_VitaminGuruSellWhatYouNeed:
# 156 "data/maps/SafariZoneGate/scripts.pory"
	.string "I'm the rare item Guru! I'll go for it and\n"
# 157 "data/maps/SafariZoneGate/scripts.pory"
	.string "sell you what you need!$"

	.align 2
# 162 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGateMart1:
# 163 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 164 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_WATER_STONE
# 165 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 166 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_NONE

	.align 2
# 169 "data/maps/SafariZoneGate/scripts.pory"
SafariZoneGateMart2:
# 170 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_TM_VENOSHOCK
# 171 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_TM_GIGA_IMPACT
# 172 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_CRACKED_POT
# 173 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_CHIPPED_POT
# 174 "data/maps/SafariZoneGate/scripts.pory"
	.2byte ITEM_UPGRADE
	.2byte ITEM_NONE
