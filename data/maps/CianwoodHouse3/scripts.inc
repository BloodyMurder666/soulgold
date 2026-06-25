# 1 "data/maps/CianwoodHouse3/scripts.pory"

# 2 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodHouse3_MapScripts::
# 3 "data/maps/CianwoodHouse3/scripts.pory"
	.byte 0
# 4 "data/maps/CianwoodHouse3/scripts.pory"

# 5 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_Kirk::
# 6 "data/maps/CianwoodHouse3/scripts.pory"
	lock
# 7 "data/maps/CianwoodHouse3/scripts.pory"
	faceplayer
# 8 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
# 9 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_SHUCKIE, 2, CianwoodCity_EventScript_KirkReturnShuckie
# 10 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
# 11 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
# 12 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined
# 13 "data/maps/CianwoodHouse3/scripts.pory"

# 14 "data/maps/CianwoodHouse3/scripts.pory"
	@HnS named gift pokemon setup
# 15 "data/maps/CianwoodHouse3/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
# 16 "data/maps/CianwoodHouse3/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
# 17 "data/maps/CianwoodHouse3/scripts.pory"
	givenamedmon 2
# 18 "data/maps/CianwoodHouse3/scripts.pory"
	call Common_EventScript_GiftMonNamed
# 19 "data/maps/CianwoodHouse3/scripts.pory"

# 20 "data/maps/CianwoodHouse3/scripts.pory"
	setvar VAR_SHUCKIE, 1
# 21 "data/maps/CianwoodHouse3/scripts.pory"
	release
# 22 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 23 "data/maps/CianwoodHouse3/scripts.pory"

# 24 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkDeclined::
# 25 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
# 26 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 27 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 28 "data/maps/CianwoodHouse3/scripts.pory"

# 29 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkGivenShuckie::
# 30 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
# 31 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 32 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 33 "data/maps/CianwoodHouse3/scripts.pory"

# 34 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkReturnShuckie::
# 35 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
# 36 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
# 37 "data/maps/CianwoodHouse3/scripts.pory"
	removenamedmon 2
# 38 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
# 39 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
# 40 "data/maps/CianwoodHouse3/scripts.pory"
	playse MUS_OBTAIN_ITEM
# 41 "data/maps/CianwoodHouse3/scripts.pory"
	callnative UpdateFollowingPokemon
# 42 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
# 43 "data/maps/CianwoodHouse3/scripts.pory"
	waitse
# 44 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
# 45 "data/maps/CianwoodHouse3/scripts.pory"
	setvar VAR_SHUCKIE, 3
# 46 "data/maps/CianwoodHouse3/scripts.pory"
	release
# 47 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 48 "data/maps/CianwoodHouse3/scripts.pory"

# 49 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkDeclineReturnShuckie::
# 50 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
# 51 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 52 "data/maps/CianwoodHouse3/scripts.pory"
	release
# 53 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 54 "data/maps/CianwoodHouse3/scripts.pory"

# 55 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkNotRight::
# 56 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
# 57 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 58 "data/maps/CianwoodHouse3/scripts.pory"
	release
# 59 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 60 "data/maps/CianwoodHouse3/scripts.pory"

# 61 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkKeepShuckie::
# 62 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
# 63 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 64 "data/maps/CianwoodHouse3/scripts.pory"
	setvar VAR_SHUCKIE, 3
# 65 "data/maps/CianwoodHouse3/scripts.pory"
	release
# 66 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 67 "data/maps/CianwoodHouse3/scripts.pory"

# 68 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_EventScript_KirkReturnedShuckie::
# 69 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
# 70 "data/maps/CianwoodHouse3/scripts.pory"
	closemessage
# 71 "data/maps/CianwoodHouse3/scripts.pory"
	end
# 72 "data/maps/CianwoodHouse3/scripts.pory"

# 73 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacAskShuckle:
# 74 "data/maps/CianwoodHouse3/scripts.pory"
	.string "I, I'm in shock!\p"
# 75 "data/maps/CianwoodHouse3/scripts.pory"
	.string "A guy about your age with piercing\n"
# 76 "data/maps/CianwoodHouse3/scripts.pory"
	.string "eyes and long hair came in.\p"
# 77 "data/maps/CianwoodHouse3/scripts.pory"
	.string "He scared me into giving him my\n"
# 78 "data/maps/CianwoodHouse3/scripts.pory"
	.string "prized Pokémon!\p"
# 79 "data/maps/CianwoodHouse3/scripts.pory"
	.string "I still have one left, but what if\n"
# 80 "data/maps/CianwoodHouse3/scripts.pory"
	.string "he comes back?\p"
# 81 "data/maps/CianwoodHouse3/scripts.pory"
	.string "You look strong. Could you look\n"
# 82 "data/maps/CianwoodHouse3/scripts.pory"
	.string "after my Pokémon for a while?$"
# 83 "data/maps/CianwoodHouse3/scripts.pory"

# 84 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacTakeCareShuckle:
# 85 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Oh, thank you!\p"
# 86 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Take good care of it, please!$"
# 87 "data/maps/CianwoodHouse3/scripts.pory"

# 88 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacGotShuckle:
# 89 "data/maps/CianwoodHouse3/scripts.pory"
	.string "{PLAYER} received a Pokémon.$"
# 90 "data/maps/CianwoodHouse3/scripts.pory"

# 91 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacPartyFull:
# 92 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Your Pokémon party is full.$"
# 93 "data/maps/CianwoodHouse3/scripts.pory"

# 94 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacIfHeComesBack:
# 95 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Oh, no… What'll I do if he comes\n"
# 96 "data/maps/CianwoodHouse3/scripts.pory"
	.string "back?$"
# 97 "data/maps/CianwoodHouse3/scripts.pory"

# 98 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacHowsdoing:
# 99 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Hi! How's my Pokémon?$"
# 100 "data/maps/CianwoodHouse3/scripts.pory"

# 101 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacAskReturn:
# 102 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Hi! How's my Pokémon?\p"
# 103 "data/maps/CianwoodHouse3/scripts.pory"
	.string "I think I'm safe now, so may I\n"
# 104 "data/maps/CianwoodHouse3/scripts.pory"
	.string "have it back?$"
# 105 "data/maps/CianwoodHouse3/scripts.pory"

# 106 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacThankYou:
# 107 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Thank you!$"
# 108 "data/maps/CianwoodHouse3/scripts.pory"

# 109 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacShuckleNotThere:
# 110 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Hey, you don't have my Pokémon\n"
# 111 "data/maps/CianwoodHouse3/scripts.pory"
	.string "with you.$"
# 112 "data/maps/CianwoodHouse3/scripts.pory"

# 113 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacShuckleLikesYou:
# 114 "data/maps/CianwoodHouse3/scripts.pory"
	.string "My Pokémon has come to like you.\p"
# 115 "data/maps/CianwoodHouse3/scripts.pory"
	.string "All right, you should keep it.\p"
# 116 "data/maps/CianwoodHouse3/scripts.pory"
	.string "But promise to be good to it!$"
# 117 "data/maps/CianwoodHouse3/scripts.pory"

# 118 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacRobbed:
# 119 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Huh, something's not right.$"
# 120 "data/maps/CianwoodHouse3/scripts.pory"

# 121 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacRobbed2:
# 122 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Oh, no, no… That's the same as\n"
# 123 "data/maps/CianwoodHouse3/scripts.pory"
	.string "being robbed.$"
# 124 "data/maps/CianwoodHouse3/scripts.pory"

# 125 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacHappinessSpeech:
# 126 "data/maps/CianwoodHouse3/scripts.pory"
	.string "For Pokémon, happiness is being\n"
# 127 "data/maps/CianwoodHouse3/scripts.pory"
	.string "with a person who treats them well.$"
# 128 "data/maps/CianwoodHouse3/scripts.pory"

# 129 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacLastMon:
# 130 "data/maps/CianwoodHouse3/scripts.pory"
	.string "If I take my Pokémon back,\n"
# 131 "data/maps/CianwoodHouse3/scripts.pory"
	.string "what are you going to use\n"
# 132 "data/maps/CianwoodHouse3/scripts.pory"
	.string "in battle?$"
# 133 "data/maps/CianwoodHouse3/scripts.pory"

# 134 "data/maps/CianwoodHouse3/scripts.pory"

# 135 "data/maps/CianwoodHouse3/scripts.pory"
CianwoodCity_Text_ManiacReturnedMon:
# 136 "data/maps/CianwoodHouse3/scripts.pory"
	.string "{PLAYER} returned Shuckie.$"

Cianwood_Kirk::
# 140 "data/maps/CianwoodHouse3/scripts.pory"
	lock
# 141 "data/maps/CianwoodHouse3/scripts.pory"
	faceplayer
# 142 "data/maps/CianwoodHouse3/scripts.pory"
	goto_if_set FLAG_CIANWOOD_GIMMIGHOUL, Cianwood_Kirk_2
# 147 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox Cianwood_Kirk_Text_1, MSGBOX_YESNO
# 161 "data/maps/CianwoodHouse3/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Cianwood_Kirk_5
# 170 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox Cianwood_Kirk_Text_3
Cianwood_Kirk_4:
# 172 "data/maps/CianwoodHouse3/scripts.pory"
	release
	end

Cianwood_Kirk_2:
# 143 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox Cianwood_Kirk_Text_0
# 144 "data/maps/CianwoodHouse3/scripts.pory"
	release
	end

Cianwood_Kirk_5:
# 162 "data/maps/CianwoodHouse3/scripts.pory"
	msgbox Cianwood_Kirk_Text_2
# 165 "data/maps/CianwoodHouse3/scripts.pory"
	givemon SPECIES_GIMMIGHOUL_CHEST, 30
# 166 "data/maps/CianwoodHouse3/scripts.pory"
	call Common_EventScript_GiftMon
# 167 "data/maps/CianwoodHouse3/scripts.pory"
	setflag FLAG_CIANWOOD_GIMMIGHOUL
	goto Cianwood_Kirk_4


Cianwood_Kirk_Text_0:
# 143 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Hi, how's my Pokémon doing?$"

Cianwood_Kirk_Text_1:
# 147 "data/maps/CianwoodHouse3/scripts.pory"
	.string "I, I'm in shock!\p"
	.string "A guy about your age with piercing\n"
	.string "eyes and long hair came in.\p"
	.string "He scared me into giving him my\n"
	.string "prized Pokémon!\p"
	.string "I still have one left, but what if\n"
	.string "he comes back?\p"
	.string "You look strong. Could you look\n"
	.string "after my Pokémon for a while?$"

Cianwood_Kirk_Text_2:
# 162 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Oh, thank you!\p"
	.string "Take good care of it, please!$"

Cianwood_Kirk_Text_3:
# 170 "data/maps/CianwoodHouse3/scripts.pory"
	.string "Oh, what am I going to do...$"
