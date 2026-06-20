Route40_House5_MapScripts::
	.byte 0


Route40Cafe_InpatientWoman::
# 4 "data/maps/Route40_House5/scripts.pory"
	lock
# 5 "data/maps/Route40_House5/scripts.pory"
	faceplayer
# 6 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_InpatientWoman_Text_0
# 8 "data/maps/Route40_House5/scripts.pory"
	release
	end


Route40Cafe_Fatman::
# 13 "data/maps/Route40_House5/scripts.pory"
	lock
# 14 "data/maps/Route40_House5/scripts.pory"
	faceplayer
# 15 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_Fatman_Text_0
# 17 "data/maps/Route40_House5/scripts.pory"
	release
	end


Route40Cafe_Rocker::
# 22 "data/maps/Route40_House5/scripts.pory"
	lock
# 23 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_Rocker_Text_0
# 24 "data/maps/Route40_House5/scripts.pory"
	release
	end


Route40Cafe_Lady::
# 29 "data/maps/Route40_House5/scripts.pory"
	lock
# 30 "data/maps/Route40_House5/scripts.pory"
	faceplayer
# 31 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_Lady_Text_0
# 33 "data/maps/Route40_House5/scripts.pory"
	release
	end


Route40Cafe_SellerLady::
# 38 "data/maps/Route40_House5/scripts.pory"
	lock
# 39 "data/maps/Route40_House5/scripts.pory"
	faceplayer
# 40 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_SellerLady_Text_0
# 41 "data/maps/Route40_House5/scripts.pory"
	pokemart CafeCook2
# 42 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_SellerLady_Text_1
# 43 "data/maps/Route40_House5/scripts.pory"
	release
	end


Route40Cafe_SellerCook::
# 48 "data/maps/Route40_House5/scripts.pory"
	lock
# 49 "data/maps/Route40_House5/scripts.pory"
	faceplayer
# 50 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_SellerCook_Text_0
# 51 "data/maps/Route40_House5/scripts.pory"
	pokemart CafeCook
# 52 "data/maps/Route40_House5/scripts.pory"
	msgbox Route40Cafe_SellerCook_Text_1
# 53 "data/maps/Route40_House5/scripts.pory"
	release
	end


	.align 2
# 57 "data/maps/Route40_House5/scripts.pory"
CafeCook:
# 58 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 59 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_TART_APPLE
# 60 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 61 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_FRESH_WATER
# 62 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SODA_POP
# 63 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_LEMONADE
# 64 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SWEET_HEART
# 65 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_PEWTER_CRUNCHIES
# 66 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_LAVA_COOKIE
# 67 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_OLD_GATEAU
# 68 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_CASTELIACONE
# 69 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_LUMIOSE_GALETTE
# 70 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SHALOUR_SABLE
# 71 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_NONE

	.align 2
# 74 "data/maps/Route40_House5/scripts.pory"
CafeCook2:
# 75 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 76 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 77 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 78 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_CALM_MINT
# 79 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 80 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
# 81 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 82 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 83 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 84 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 85 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_LAX_MINT
# 86 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 87 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_MILD_MINT
# 88 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 89 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 90 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 91 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 92 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_RASH_MINT
# 93 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 94 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 95 "data/maps/Route40_House5/scripts.pory"
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_NONE

Route40Cafe_InpatientWoman_Text_0:
# 6 "data/maps/Route40_House5/scripts.pory"
	.string "Where's my order?! I've been waiting for\n"
	.string "10 minutes already!$"

Route40Cafe_Fatman_Text_0:
# 15 "data/maps/Route40_House5/scripts.pory"
	.string "This cafe has been a hit among the \n"
	.string "tourists ever since it opened last year.$"

Route40Cafe_Rocker_Text_0:
# 23 "data/maps/Route40_House5/scripts.pory"
	.string "I'll have uhh...$"

Route40Cafe_Lady_Text_0:
# 31 "data/maps/Route40_House5/scripts.pory"
	.string "I bought a mint from the lady over\n"
	.string "there and my Pokémon's nature changed!$"

Route40Cafe_SellerLady_Text_0:
# 40 "data/maps/Route40_House5/scripts.pory"
	.string "Welcome! We sell mints for Pokémon!$"

Route40Cafe_SellerLady_Text_1:
# 42 "data/maps/Route40_House5/scripts.pory"
	.string "We hope to see you again!$"

Route40Cafe_SellerCook_Text_0:
# 50 "data/maps/Route40_House5/scripts.pory"
	.string "Welcome, what will you have?$"

Route40Cafe_SellerCook_Text_1:
# 52 "data/maps/Route40_House5/scripts.pory"
	.string "Come back soon!$"
