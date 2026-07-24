RintoHouse3_MapScripts::
	.byte 0


RintoHouse3_Guard::
# 4 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Guard_Text_0, MSGBOX_NPC
	return


RintoHouse3_ResearchGuide::
# 9 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_ResearchGuide_Text_0, MSGBOX_NPC
	return


RintoHouse3_Hiker::
# 14 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Hiker_Text_0, MSGBOX_NPC
	return


RintoHouse3_Researcher::
# 21 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Researcher_Text_0, MSGBOX_NPC
	return


RintoHouse3_Excadrill::
# 28 "data/maps/RintoHouse3/scripts.pory"
	lock
# 29 "data/maps/RintoHouse3/scripts.pory"
	faceplayer
# 30 "data/maps/RintoHouse3/scripts.pory"
	playmoncry SPECIES_EXCADRILL, CRY_MODE_NORMAL
# 31 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Excadrill_Text_0
# 32 "data/maps/RintoHouse3/scripts.pory"
	waitmoncry
# 33 "data/maps/RintoHouse3/scripts.pory"
	release
	end


RintoHouse3_TraderResearcher::
# 38 "data/maps/RintoHouse3/scripts.pory"
	lock
# 39 "data/maps/RintoHouse3/scripts.pory"
	faceplayer
# 40 "data/maps/RintoHouse3/scripts.pory"
	goto_if_set FLAG_RINTO_TRADE_COMPLETE, RintoHouse3_TraderResearcher_2
# 45 "data/maps/RintoHouse3/scripts.pory"
	ingame_trade INGAME_TRADE_MELTAN, RintoHouse3_TraderResearcher_Text_1, MeltanTrade_Declined, MeltanTrade_NotRequested, RintoHouse3_TraderResearcher_Text_2
# 60 "data/maps/RintoHouse3/scripts.pory"
	setflag FLAG_RINTO_TRADE_COMPLETE
RintoHouse3_TraderResearcher_1:
# 62 "data/maps/RintoHouse3/scripts.pory"
	release
	end

RintoHouse3_TraderResearcher_2:
# 41 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_TraderResearcher_Text_0
	goto RintoHouse3_TraderResearcher_1


MeltanTrade_Declined::
# 67 "data/maps/RintoHouse3/scripts.pory"
	msgbox MeltanTrade_Declined_Text_0
# 71 "data/maps/RintoHouse3/scripts.pory"
	release
	end


MeltanTrade_NotRequested::
# 76 "data/maps/RintoHouse3/scripts.pory"
	msgbox MeltanTrade_NotRequested_Text_0
# 78 "data/maps/RintoHouse3/scripts.pory"
	release
	end


RintoHouse3_Plaque::
# 83 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Plaque_Text_0, MSGBOX_SIGN
	return


RintoHouse3_PlaqueBall::
# 88 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_PlaqueBall_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Bookshelf::
# 95 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Bookshelf_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Painting::
# 100 "data/maps/RintoHouse3/scripts.pory"
	msgbox RintoHouse3_Painting_Text_0, MSGBOX_SIGN
	return


RintoHouse3_Guard_Text_0:
# 4 "data/maps/RintoHouse3/scripts.pory"
	.string "Downstairs is reserved for researchers\n"
	.string "only.$"

RintoHouse3_ResearchGuide_Text_0:
# 9 "data/maps/RintoHouse3/scripts.pory"
	.string "You can see our excavation results\n"
	.string "here!$"

RintoHouse3_Hiker_Text_0:
# 14 "data/maps/RintoHouse3/scripts.pory"
	.string "We've made a lot of discoveries near the\n"
	.string "pyramid, but no one has been able to get\l"
	.string "in.$"

RintoHouse3_Researcher_Text_0:
# 21 "data/maps/RintoHouse3/scripts.pory"
	.string "The door to the pyramid...\p"
	.string "It's made of a strange metal that can\n"
	.string "repel even our Excadrill's attacks.$"

RintoHouse3_Excadrill_Text_0:
# 31 "data/maps/RintoHouse3/scripts.pory"
	.string "Excadrill: Caaaaaaaa!$"

RintoHouse3_TraderResearcher_Text_0:
# 41 "data/maps/RintoHouse3/scripts.pory"
	.string "Thanks to your Tinkaton, we may\n"
	.string "finally be able to break through one\l"
	.string "of the pyramid's walls!$"

RintoHouse3_TraderResearcher_Text_1:
# 45 "data/maps/RintoHouse3/scripts.pory"
	.string "I'm researching alternative ways to\n"
	.string "get into the pyramid to the west.\p"
	.string "Would you happen to have a Tinkaton?\p"
	.string "With its powerful hammer strikes, we\n"
	.string "might be able to break through one of\l"
	.string "the pyramid's walls.\p"
	.string "I can offer you this rare Meltan in\n"
	.string "return. What do you say?$"

RintoHouse3_TraderResearcher_Text_2:
# 58 "data/maps/RintoHouse3/scripts.pory"
	.string "Amazing! Thank you on behalf of the\n"
	.string "whole research team!$"

MeltanTrade_Declined_Text_0:
# 67 "data/maps/RintoHouse3/scripts.pory"
	.string "Oh... Okay, then...\p"
	.string "I guess I'll have to ask someone to\n"
	.string "find and raise one from the Union Cave...$"

MeltanTrade_NotRequested_Text_0:
# 76 "data/maps/RintoHouse3/scripts.pory"
	.string "That doesn't look like a Tinkaton to\n"
	.string "me.$"

RintoHouse3_Plaque_Text_0:
# 83 "data/maps/RintoHouse3/scripts.pory"
	.string "It appears to be some sort of a\n"
	.string "Fossil excavated nearby.$"

RintoHouse3_PlaqueBall_Text_0:
# 88 "data/maps/RintoHouse3/scripts.pory"
	.string "An ancient Poké Ball. \p"
	.string "It looks much like the ones\n"
	.string "used in ancient Hisui.$"

RintoHouse3_Bookshelf_Text_0:
# 95 "data/maps/RintoHouse3/scripts.pory"
	.string "A Bookshelf filled with history books.\n"
	.string "Some of them look ancient!$"

RintoHouse3_Painting_Text_0:
# 100 "data/maps/RintoHouse3/scripts.pory"
	.string "A painting depicting an artist's \n"
	.string "interpretation of this land a thousand \l"
	.string "years ago.\p"
	.string "You have a hard time making out the\n"
	.string "signature.$"
