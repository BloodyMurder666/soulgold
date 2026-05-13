AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "All the Slowpoke have disappeared\n"
	.string "from the town.\p"
	.string "The forest's protector may be\n"
	.string "angry with us…\p"
	.string "It may be a bad omen. We should\n"
	.string "stay in.$"

CharcoalKiln_Text_Boss2:
	.string "The Slowpoke have returned…$"

CharcoalKiln_Text_Boss3:
	.string "The Slowpoke have returned…\p"
	.string "But my Apprentice hasn't come back\n"
	.string "from Ilex Forest.\p"
	.string "Where in the world is that lazy guy?$"

CharcoalKiln_Text_Boss4:
	.string "You chased off Team Rocket and\n"
	.string "went to Ilex Forest alone?\p"
	.string "That takes guts! I like that.\n"
	.string "Come train with us.$"

CharcoalKiln_Text_Apprentice1:
	.string "Where have all the Slowpoke gone?\p"
	.string "Are they out playing somewhere?$"

CharcoalKiln_Text_Apprentice2:
	.string "The Slowpoke came back!$"

CharcoalKiln_Text_Apprentice3:
	.string "I'm sorry--I forgot to thank you.\p"
	.string "This is Charcoal that I made.\p"
	.string "Fire-type Pokémon would be happy\n"
	.string "to hold that.$"

CharcoalKiln_Text_Apprentice4:
	.string "The Slowpoke came back, and you even\n"
	.string "found Farfetch'D.\p"
	.string "You're the coolest, man!$"

CharcoalKiln_Text_Farfetchd:
	.string "Farfetch'D: Kwaa!$"
