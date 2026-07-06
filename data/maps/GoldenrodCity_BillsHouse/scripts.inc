# 1 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 2 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
GoldenrodCity_BillsHouse_MapScripts::
# 3 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.byte 0
# 4 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 5 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
GoldenrodCity_BillsHouse_EventScript_Sister::
# 6 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	lock
# 7 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	faceplayer
# 8 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
# 9 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	closemessage
# 10 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
# 11 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	end
# 12 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 13 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
GoldenrodCity_BillsHouse_EventScript_Mom::
# 14 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	lock
# 15 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	faceplayer
# 16 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
# 17 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
# 18 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	closemessage
# 19 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
# 20 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	end
# 21 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 22 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
GoldenrodCity_BillsHouse_EventScript_Mom2::
# 23 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
# 24 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	closemessage
# 25 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
# 26 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	end
# 27 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 28 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_EeveeMayEvolve:
# 29 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Bill: Prof.Elm claims Eevee may\n"
# 30 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "evolve in new and unknown ways.$"
# 31 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 32 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_PartyFull:
# 33 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Whoa, wait. You can't carry any\n"
# 34 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "more Pokémon.$"
# 35 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 36 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_NoEevee:
# 37 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Oh… Now what to do?$"
# 38 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 39 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_PopWontWork:
# 40 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Bill: My pop, he won't work. All he\n"
# 41 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "does is goof off all day long.\p"
# 42 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "He's getting to be a real headache…$"
# 43 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 44 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_MomBeforeEcruteak:
# 45 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Oh, you collect Pokémon? My son\n"
# 46 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Bill is an expert.\p"
# 47 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "He just got called to the Pokémon\n"
# 48 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Center in Ecruteak City.\p"
# 49 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "My husband went off to the Game\n"
# 50 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Corner without being called…$"
# 51 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 52 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_MomAfterEcruteak:
# 53 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "My husband was once known as a\n"
# 54 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Pokémaniac.\p"
# 55 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Bill must have taken after his\n"
# 56 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "father.$"
# 57 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 58 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_SisterUsefulNumber:
# 59 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Are you a trainer?\p"
# 60 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "I've got a useful phone number\n"
# 61 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "for you.$"
# 62 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 63 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_RecordedBillsNumber:
# 64 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "{PLAYER} recorded Bill's number.$"
# 65 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 66 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_SisterRefusedNumber:
# 67 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "My brother made the PC Pokémon\n"
# 68 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "storage system.\p"
# 69 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "I was going to give you Bill's\n"
# 70 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "number…$"
# 71 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 72 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_SisterPhoneFull:
# 73 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "You can't record any more numbers.$"
# 74 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"

# 75 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
BillHouse_Text_SisterStorageSystem:
# 76 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "My big brother Bill made the PC\n"
# 77 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
    .string "Pokémon storage system.$"

GoldenrodCity_Bill_GiveEeveeOrPikachu::
# 81 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	lock
# 82 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	faceplayer
# 83 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	goto_if_unset FLAG_GOT_BILL_GIFTMON, GoldenrodCity_Bill_GiveEeveeOrPikachu_2
# 135 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_6
# 138 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_2:
# 84 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_0
# 97 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_1, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_2, GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_3
# 98 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	case 0, GoldenrodCity_Bill_GiveEeveeOrPikachu_5
# 114 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	case 1, GoldenrodCity_Bill_GiveEeveeOrPikachu_6
# 130 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_5
# 131 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_5:
# 100 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE_STARTER
# 101 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE_STARTER
# 102 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	givemon SPECIES_EEVEE_STARTER, 25
# 104 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	setflag FLAG_GOT_BILL_GIFTMON
# 105 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	showgivemonpic 10, 3
# 106 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	call Common_EventScript_GiftMon
# 107 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	hidemonpic
# 108 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE_STARTER
# 109 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4
# 112 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
	end

GoldenrodCity_Bill_GiveEeveeOrPikachu_6:
# 115 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIKACHU_STARTER
# 116 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU_STARTER
# 117 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	givemon SPECIES_PIKACHU_STARTER, 25
# 119 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	setflag FLAG_GOT_BILL_GIFTMON
# 120 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	showgivemonpic 10, 3
# 121 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	call Common_EventScript_GiftMon
# 122 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	hidemonpic
# 123 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU_STARTER
# 124 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	msgbox GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4
# 127 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	release
	end


GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_0:
# 84 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Bill: Hi, {PLAYER}! Do us a favor and\n"
	.string "take one of these two Pokémon. \p"
	.string "Both of them came over when I \n"
	.string "was adjusting the Time Capsule.\p"
	.string "I don't have time to take care \n"
	.string "of both of them even with help of\l"
	.string "my family. \p"
	.string "I think both of them have some special\n"
	.string "characteristics, so can I count on you\l"
	.string "to take either one, {PLAYER}?$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_1:
# 97 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Eevee$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_2:
# 97 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Pikachu$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_3:
# 97 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "No thanks$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_4:
# 109 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Bill: I knew you'd come through!\n"
	.string "Way to go! I'm counting on you\l"
	.string "to take good care of it!$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_5:
# 130 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Oh… Now what to do?$"

GoldenrodCity_Bill_GiveEeveeOrPikachu_Text_6:
# 135 "data/maps/GoldenrodCity_BillsHouse/scripts.pory"
	.string "Come to think of it. I've heard rumours\n"
	.string "of rare Pokémon being distributed in\l"
	.string "the Game Corner.$"
