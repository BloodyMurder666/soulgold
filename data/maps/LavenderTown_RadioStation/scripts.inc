LavenderTown_RadioStation_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Welcome! Feel free to look around\n"
	.string "anywhere on this floor.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Sorry, but you can only tour the\n"
	.string "ground floor.\p"
	.string "Ever since Johto's Radio Tower\n"
	.string "was taken over by a criminal gang,\l"
	.string "we have had to step up our\l"
	.string "security.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Many people are hard at work here\n"
	.string "in the Radio Tower.\p"
	.string "They must be doing their best to\n"
	.string "put on good shows.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, no, no, no!\p"
	.string "We've been off the air ever since\n"
	.string "the Power Plant shut down.\p"
	.string "All my efforts to start this\n"
	.string "station would be wasted if I can't\l"
	.string "broadcast.\p"
	.string "I'll be ruined!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! So you're the {PLAYER} who\n"
	.string "solved the Power Plant's problem?\p"
	.string "Thanks to you, I never lost my\n"
	.string "job.\p"
	.string "I tell you, you're a real\n"
	.string "lifesaver!\p"
	.string "Please take this as my thanks.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtained the\n"
	.string "Radio Upgrade!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "With that thing, you can tune into\n"
	.string "the radio programs here in Kanto.\p"
	.string "Gahahahaha!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Hey there!\p"
	.string "I am the super Music Director!\p"
	.string "Huh? Your Radio can't tune into\n" @Pokégear
	.string "my music programs. How unfortunate!\p"
	.string "If you get an Expn Card upgrade,\n"
	.string "you can tune in. You'd better get\l"
	.string "one!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Hey there!\p"
	.string "I am the super Music Director!\p"
	.string "I'm responsible for the gorgeous\n"
	.string "melodies that go out over the air.\p"
	.string "Don't be square. Grab your music\n"
	.string "off the air!$"

LavenderTown_RadioStation_Text_Directory:
	.string "1F Reception 2F Sales\p"
	.string "3F Personnel 4F Production\p"
	.string "5F Director'S Office$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Perk Up Pokémon with Mellow\n"
	.string "Sounds of the POKé Flute on\l"
	.string "Channel 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Wow! A full rack of Pokémon CDs\n"
	.string "and videos.\p"
	.string "This must be the reference\n"
	.string "library.$"

