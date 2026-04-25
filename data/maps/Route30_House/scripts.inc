Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "When you follow that path up north,\n"
	.string "you will see Mr. POKéMON’s house.\p"
	.string "But before you go, allow me to\n"
	.string "tell you about Berries!\p"
	.string "POKéMON get healthier by eating\n"
	.string "Berries.\p"
	.string "They can even eat Berries\n"
	.string "they're holding in battle.\p"
	.string "Berries can also be turned into\n"
	.string "Balls by Kurt in Azalea Town.\p"
	.string "Here. I'll share one with you!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Check trees for Berries.\n"
	.string "They grow back after a few hours.$"
