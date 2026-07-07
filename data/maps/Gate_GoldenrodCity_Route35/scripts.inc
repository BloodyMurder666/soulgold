# 1 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 2 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_MapScripts::
# 3 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.byte 0
# 4 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 5 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_Randy::
# 6 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	lock
# 7 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	faceplayer
# 8 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
# 9 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
# 10 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
# 11 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
# 12 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
# 13 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 14 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 15 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT
# 16 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 17 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	@HnS named gift pokemon setup
# 18 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
# 19 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
# 20 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	givenamedmon 1
# 21 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	call Common_EventScript_GiftMonNamed
# 22 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 23 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	setvar VAR_KENYA, 1
# 24 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 25 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 26 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 27 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
# 28 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
# 29 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 30 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 31 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 32 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 33 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
# 34 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
# 35 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 36 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 37 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 38 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 39 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
# 40 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
# 41 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 42 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	giveitem ITEM_HP_UP
# 43 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 44 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
# 45 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 46 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	setvar VAR_KENYA, 3
# 47 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 48 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 49 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 50 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
# 51 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
# 52 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 53 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 54 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 55 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 56 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_Lady::
# 57 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	lock
# 58 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	faceplayer
# 59 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
# 60 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
# 61 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 62 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 63 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 64 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 65 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_Lady2::
# 66 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
# 67 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 68 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 69 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 70 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 71 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Gate_GoldenrodCity_Route35_EventScript_Fisher::
# 72 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	lock
# 73 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	faceplayer
# 74 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
# 75 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	closemessage
# 76 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
# 77 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	end
# 78 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 79 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_RandyAskFavor:
# 80 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Excuse me, kid! Can you do a guy\n"
# 81 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "a favor?\p"
# 82 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Can you take this Pokémon with Mail\n"
# 83 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "to my friend?\p"
# 84 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "He's on Route 31.$"
# 85 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 86 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_RandyThanks:
# 87 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "You will? Perfect! Thanks, kid!\p"
# 88 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "My pal's a chubby guy who snoozes\n"
# 89 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "all the time.\p"
# 90 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "You'll recognize him right away!$"
# 91 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 92 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_ReceivedMonWithMail:
# 93 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "{PLAYER} received a Pokémon with Mail.$"
# 94 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 95 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_RandyWeirdTree:
# 96 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Make sure to put it at the front of\n"
# 97 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "your team when you find my friend!\p"
# 98 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Route 31!\p"
# 99 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Oh, yeah. There was a weird tree\n"
# 100 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "blocking the road.\p"
# 101 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "I wonder if it's been cleared?$"
# 102 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 103 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_CantCarryMoreMon:
# 104 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "You can't carry another Pokémon…$"
# 105 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 106 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_RandyNeverMind:
# 107 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Oh… Never mind, then…$"
# 108 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 109 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_ThanksForDelivery:
# 110 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Thanks, kid! You made the delivery\n"
# 111 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "for me!\p"
# 112 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Here's something for your trouble!$"
# 113 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 114 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_RandyMyPalSnoozing:
# 115 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "My pal was snoozing, right? Heh,\n"
# 116 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "what'd I say?$"
# 117 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 118 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
# 119 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "A strange tree is blocking the road.\p"
# 120 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "It wriggles around if you talk to it.\p"
# 121 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "I heard it became wild when someone\n"
# 122 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "watered it with a Squirtbottle.$"
# 123 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 124 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_PokefanF_Lullaby:
# 125 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "I like the Pokémon Lullaby they play\n"
# 126 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "on the radio.$"
# 127 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"

# 128 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
Route35GoldenrodGate_Text_Fisher:
# 129 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "I wonder how many kinds of Pokémon\n"
# 130 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "there are in the world.\p"
# 131 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Three years ago, Prof. Oak said that\n"
# 132 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "there were 150 different kinds.\p"
# 133 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "But recently I heard there's\n"
# 134 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "over 400!$"

Route35GateGuard::
# 138 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	lock
# 139 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	faceplayer
# 140 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	goto_if_set FLAG_TM_FALSE_SWIPE, Route35GateGuard_2
# 149 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GateGuard_Text_1
# 151 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	giveitem ITEM_TM_FALSE_SWIPE
# 152 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	setflag FLAG_TM_FALSE_SWIPE
# 153 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GateGuard_Text_0
# 158 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
	end

Route35GateGuard_2:
# 141 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	msgbox Route35GateGuard_Text_0
# 146 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	release
	end


Route35GateGuard_Text_0:
# 141 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "False Swipe deals damage, but never\n"
	.string "KO's Pokémon.\p"
	.string "It's really helpful for catching\n"
	.string "Pokémon!$"

Route35GateGuard_Text_1:
# 149 "data/maps/Gate_GoldenrodCity_Route35/scripts.pory"
	.string "Having trouble catching Pokémon?\n"
	.string "Try using this.$"
