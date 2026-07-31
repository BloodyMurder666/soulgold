Route39_FarmHouse_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_ECHOED_VOICE
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "My Miltank ain't givin' me\n"
	.string "milk no more.\p"
	.string "This here Farm's got famous milk.\p"
	.string "Most everyone wants a drink.\p"
	.string "It'll give me lots o' milk if'n\n"
	.string "I feed it lots o' Berries,\l"
	.string "I reckon.$"

Route39_Text_FarmerMBuyMilk:
	.string "How'd you like my Moomoo Milk?\p"
	.string "It's my pride and joy, there.\p"
	.string "Give it to Pokémon to restore Hp!\p"
	.string "I'll give it to ya fer just\n"
	.string "¥500.$"

Route39_Text_FarmerMGotMilk:
	.string "Here ya go!\n"
	.string "Drink up'n enjoy!$"

Route39_Text_FarmerMNoMoney:
	.string "Sorry, there.\n"
	.string "No cash, no sale!$"

Route39_Text_FarmerMNoRoom:
	.string "I reckon yer Pack's full.$"

Route39_Text_FarmerMNoSale:
	.string "You don't want it?\n"
	.string "Come again, hear?$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "How bout another?$"

Route39_Text_GotMilk:
	.string "{PLAYER} got Moomoo Milk.$"

Route39_Text_FarmerMMilking:
	.string "I best go do my milkin'.$"

Route39_Text_FarmerFInTrouble:
	.string "Our milk even goes out to\n"
	.string "Kanto.\p"
	.string "So if our own Miltank won't\n"
	.string "give us any milk, we're in trouble.$"

Route39_Text_FarmerFHealedMiltank:
	.string "You fixed our Miltank, hon.\n"
	.string "Now it gives Moomoo Milk again.\p"
	.string "Here's somethin' fer your trouble.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "That there's Echoed Voice.\pn"
	.string "Use it many times, hon.\p"
	.string "It will grow in power.$"
