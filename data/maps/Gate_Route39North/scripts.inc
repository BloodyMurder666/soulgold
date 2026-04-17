Gate_Route39North_MapScripts::
	.byte 0


Route39North_Police::
# 4 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Police_Text_0, MSGBOX_NPC
	return


Route39North_Elder::
# 11 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Elder_Text_0, MSGBOX_NPC
	return


Route39North_Hiker::
# 19 "data/maps/Gate_Route39North/scripts.pory"
	goto_if_set FLAG_R39_NORTH_ROCKY_HELMET, Route39North_Hiker_2
# 26 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Hiker_Text_1
# 28 "data/maps/Gate_Route39North/scripts.pory"
	giveitem ITEM_ROCKY_HELMET
# 29 "data/maps/Gate_Route39North/scripts.pory"
	setflag FLAG_R39_NORTH_ROCKY_HELMET
# 30 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Hiker_Text_2
# 32 "data/maps/Gate_Route39North/scripts.pory"
	release
	end

Route39North_Hiker_2:
# 20 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Hiker_Text_0
# 23 "data/maps/Gate_Route39North/scripts.pory"
	release
	end


Route39North_Poster::
# 37 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Poster_Text_0, MSGBOX_SIGN
	return


Route39North_Binoculars::
# 42 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Binoculars_Text_0, MSGBOX_SIGN
	return


Route39North_Gameboykid::
# 51 "data/maps/Gate_Route39North/scripts.pory"
	lock
# 52 "data/maps/Gate_Route39North/scripts.pory"
	faceplayer
# 53 "data/maps/Gate_Route39North/scripts.pory"
	goto_if_set FLAG_R39_NORTH_TRADE, Route39North_Gameboykid_2
# 58 "data/maps/Gate_Route39North/scripts.pory"
	ingame_trade INGAME_TRADE_ROTOM, Route39North_Gameboykid_Text_1, RotomTrade_Declined, RotomTrade_NotRequested, Route39North_Gameboykid_Text_2
# 67 "data/maps/Gate_Route39North/scripts.pory"
	setflag FLAG_R39_NORTH_TRADE
Route39North_Gameboykid_1:
# 69 "data/maps/Gate_Route39North/scripts.pory"
	release
	end

Route39North_Gameboykid_2:
# 54 "data/maps/Gate_Route39North/scripts.pory"
	msgbox Route39North_Gameboykid_Text_0
	goto Route39North_Gameboykid_1


RotomTrade_Declined::
# 74 "data/maps/Gate_Route39North/scripts.pory"
	msgbox RotomTrade_Declined_Text_0
# 75 "data/maps/Gate_Route39North/scripts.pory"
	release
	end


RotomTrade_NotRequested::
# 80 "data/maps/Gate_Route39North/scripts.pory"
	msgbox RotomTrade_NotRequested_Text_0
# 82 "data/maps/Gate_Route39North/scripts.pory"
	release
	end


Route39North_Police_Text_0:
# 4 "data/maps/Gate_Route39North/scripts.pory"
	.string "If you want to head further north, you\n"
	.string "should find yourself some protection\l"
	.string "against the snow. The higher altitude\l"
	.string "takes a toll on the body.$"

Route39North_Elder_Text_0:
# 11 "data/maps/Gate_Route39North/scripts.pory"
	.string "When I was younger, I would hike the\n"
	.string "trail to the mountain every day, uphill\l"
	.string "both ways! I didn't have any pokémon\l"
	.string "carrying me or any of those fancy bikes\l"
	.string "you kids have these days!$"

Route39North_Hiker_Text_0:
# 20 "data/maps/Gate_Route39North/scripts.pory"
	.string "Rocky Helmet makes sure your enemies\n"
	.string "will also suffer the pain they inflict\l"
	.string "upon you!$"

Route39North_Hiker_Text_1:
# 26 "data/maps/Gate_Route39North/scripts.pory"
	.string "Tired of only taking the beating? Try\n"
	.string "this!$"

Route39North_Hiker_Text_2:
# 30 "data/maps/Gate_Route39North/scripts.pory"
	.string "That should put the pain back to your\n"
	.string "enemies.$"

Route39North_Poster_Text_0:
# 37 "data/maps/Gate_Route39North/scripts.pory"
	.string "There's a sign about a large bird \n"
	.string "Pokémon being sighted in the mountains.$"

Route39North_Binoculars_Text_0:
# 42 "data/maps/Gate_Route39North/scripts.pory"
	.string "You peer into the binoculars...\n"
	.string "...\l"
	.string "..!\l"
	.string "A majestic snowmountain towers in the\l"
	.string "distance!$"

Route39North_Gameboykid_Text_0:
# 54 "data/maps/Gate_Route39North/scripts.pory"
	.string "I hear Rotom can posses common\n"
	.string "household appliances to change\l"
	.string "form.$"

Route39North_Gameboykid_Text_1:
# 58 "data/maps/Gate_Route39North/scripts.pory"
	.string "There's this rare Pokémon\n"
	.string "I've been seeking for a while.\l"
	.string "Would you happen to have a Zorua?\l"
	.string "I would trade it for Rotom.$"

Route39North_Gameboykid_Text_2:
# 64 "data/maps/Gate_Route39North/scripts.pory"
	.string "Much appreciated! I'm a huge fan\n"
	.string "of Unova, I can't wait to show this\l"
	.string "to my friends!$"

RotomTrade_Declined_Text_0:
# 74 "data/maps/Gate_Route39North/scripts.pory"
	.string "Shame, it is quite a rare Pokémon.$"

RotomTrade_NotRequested_Text_0:
# 80 "data/maps/Gate_Route39North/scripts.pory"
	.string "Uh, no, I don't think so.\n"
	.string "That doesn't look like a Zorua.$"
