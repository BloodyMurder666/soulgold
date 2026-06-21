# 1 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 2 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_MapScripts::
# 3 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.byte 0
# 4 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 5 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_EventScript_Clerk::
# 6 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	lock
# 7 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	faceplayer
# 8 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_BIKE, receivedBikePostDialogue
# 9 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
# 10 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
# 11 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
# 12 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 13 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
# 14 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	end
# 15 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 16 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
# 17 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
# 18 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 19 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	setflag FLAG_RECEIVED_BIKE
# 20 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 21 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
# 22 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	end
# 23 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 24 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
# 25 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
# 26 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 27 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
# 28 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	end
# 29 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 30 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_EventScript_Clerk2::
# 31 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	lock
# 32 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	faceplayer
# 33 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
# 34 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 35 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
# 36 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	end
# 37 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 38 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_EventScript_Bike::
# 39 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	lock
# 40 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
# 41 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 42 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
# 43 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	end
# 44 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 45 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_Clerk2:
# 46 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "Riding the bike is as simple as\n"
# 47 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "pressing a button if you\l"
# 48 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "Register it from the Bag.$"
# 49 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 50 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_ClerkIntro:
# 51 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "…sigh… I moved here, but I can't\n"
# 52 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "sell my Bicycles. Why is that?\p"
# 53 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "Could you ride a Bicycle and\n"
# 54 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "advertise for me?$"
# 55 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 56 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_ClerkAgreed:
# 57 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "Really? Great!\p"
# 58 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "Give me your name and phone number,\n"
# 59 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "and I'll loan you a Bicycle.$"
# 60 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 61 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_BorrowedBicycle:
# 62 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "{PLAYER} borrowed a Bicycle.$"
# 63 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 64 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_Mainshop:
# 65 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "The main shop is at Cerulean back\n"
# 66 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "in Kanto.\p"
# 67 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "Say hello to the shop manager if\n"
# 68 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "if you happen to go there!$"
# 69 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 70 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_Refused:
# 71 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "…sigh… Oh, for the kindness of\n"
# 72 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "people…$"
# 73 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 74 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_JustReleasedCompact:
# 75 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "Just released!\p"
# 76 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "First-rate compact Bicycles!$"
# 77 "data/maps/GoldenrodCity_BikeShop/scripts.pory"

# 78 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
GoldenrodCity_BikeShop_Text_Bicycle:
# 79 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
    .string "It's a shiny new Bicycle!$"

receivedBikePostDialogue::
# 83 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, receivedBikePostDialogue_2
# 90 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox receivedBikePostDialogue_Text_1
# 92 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 93 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
	end

receivedBikePostDialogue_2:
# 84 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	msgbox receivedBikePostDialogue_Text_0
# 86 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	closemessage
# 87 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	release
	end


receivedBikePostDialogue_Text_0:
# 84 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "Hey kid! Thanks to you, my business\n"
	.string "is booming! I owe it to you!$"

receivedBikePostDialogue_Text_1:
# 90 "data/maps/GoldenrodCity_BikeShop/scripts.pory"
	.string "I hope people start paying attention\n"
	.string "to my Bicycles now!$"
