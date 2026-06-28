# 1 "data/maps/CianwoodShop/scripts.pory"

# 2 "data/maps/CianwoodShop/scripts.pory"
CianwoodShop_MapScripts::
# 3 "data/maps/CianwoodShop/scripts.pory"
	.byte 0
# 4 "data/maps/CianwoodShop/scripts.pory"

# 5 "data/maps/CianwoodShop/scripts.pory"
CianwoodShop_EventScriptMan::	
# 6 "data/maps/CianwoodShop/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 4
# 7 "data/maps/CianwoodShop/scripts.pory"
	giveitem ITEM_SECRET_POTION
# 8 "data/maps/CianwoodShop/scripts.pory"
	end
# 9 "data/maps/CianwoodShop/scripts.pory"

# 10 "data/maps/CianwoodShop/scripts.pory"
CianwoodCity_EventScript_Pharmacist::
# 11 "data/maps/CianwoodShop/scripts.pory"
	lock
# 12 "data/maps/CianwoodShop/scripts.pory"
	faceplayer
# 13 "data/maps/CianwoodShop/scripts.pory"
	checkitem ITEM_SECRET_POTION
# 14 "data/maps/CianwoodShop/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
# 15 "data/maps/CianwoodShop/scripts.pory"
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
# 16 "data/maps/CianwoodShop/scripts.pory"
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
# 17 "data/maps/CianwoodShop/scripts.pory"
	giveitem ITEM_SECRET_POTION
# 18 "data/maps/CianwoodShop/scripts.pory"
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
# 19 "data/maps/CianwoodShop/scripts.pory"
	closemessage
# 20 "data/maps/CianwoodShop/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 4
# 21 "data/maps/CianwoodShop/scripts.pory"
	release
# 22 "data/maps/CianwoodShop/scripts.pory"
	end
# 23 "data/maps/CianwoodShop/scripts.pory"

# 24 "data/maps/CianwoodShop/scripts.pory"
CianwoodCity_EventScript_PharmacistAfter::
# 25 "data/maps/CianwoodShop/scripts.pory"
	lock
# 26 "data/maps/CianwoodShop/scripts.pory"
	faceplayer
# 27 "data/maps/CianwoodShop/scripts.pory"
	message gText_HowMayIServeYou
# 28 "data/maps/CianwoodShop/scripts.pory"
	waitmessage
# 29 "data/maps/CianwoodShop/scripts.pory"
	pokemart 0
# 30 "data/maps/CianwoodShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 31 "data/maps/CianwoodShop/scripts.pory"
	release
# 32 "data/maps/CianwoodShop/scripts.pory"
	end
# 33 "data/maps/CianwoodShop/scripts.pory"

# 34 "data/maps/CianwoodShop/scripts.pory"

# 35 "data/maps/CianwoodShop/scripts.pory"
CianwoodCity_Text_PharmacistGivePotion:
# 36 "data/maps/CianwoodShop/scripts.pory"
	.string "Your Pokémon appear to be fine.\p"
# 37 "data/maps/CianwoodShop/scripts.pory"
	.string "Is something worrying you?\p"
# 38 "data/maps/CianwoodShop/scripts.pory"
	.string "…\p"
# 39 "data/maps/CianwoodShop/scripts.pory"
	.string "The Lighthouse Pokémon is in\n"
# 40 "data/maps/CianwoodShop/scripts.pory"
	.string "trouble?\p"
# 41 "data/maps/CianwoodShop/scripts.pory"
	.string "I got it!\p"
# 42 "data/maps/CianwoodShop/scripts.pory"
	.string "This ought to do the trick.$"
# 43 "data/maps/CianwoodShop/scripts.pory"

# 44 "data/maps/CianwoodShop/scripts.pory"
CianwoodCity_Text_ReceivedSecretpotion:
# 45 "data/maps/CianwoodShop/scripts.pory"
	.string "{PLAYER} received Secretpotion.$"
# 46 "data/maps/CianwoodShop/scripts.pory"

# 47 "data/maps/CianwoodShop/scripts.pory"
CianwoodCity_Text_PharmacistDescribePotion:
# 48 "data/maps/CianwoodShop/scripts.pory"
	.string "My Secretpotion is a tad too\n"
# 49 "data/maps/CianwoodShop/scripts.pory"
	.string "strong, so I only offer it in an\l"
# 50 "data/maps/CianwoodShop/scripts.pory"
	.string "emergency.$"
