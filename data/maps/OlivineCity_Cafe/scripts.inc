# 1 "data/maps/OlivineCity_Cafe/scripts.pory"

# 2 "data/maps/OlivineCity_Cafe/scripts.pory"

# 3 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Cafe_MapScripts::
# 4 "data/maps/OlivineCity_Cafe/scripts.pory"
	.byte 0
# 5 "data/maps/OlivineCity_Cafe/scripts.pory"

# 6 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Cafe_EventScript_Jasmine::
# 7 "data/maps/OlivineCity_Cafe/scripts.pory"
	lock
# 8 "data/maps/OlivineCity_Cafe/scripts.pory"
	faceplayer
# 9 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
# 10 "data/maps/OlivineCity_Cafe/scripts.pory"
	closemessage
# 11 "data/maps/OlivineCity_Cafe/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 12 "data/maps/OlivineCity_Cafe/scripts.pory"
	setflag FLAG_HIDE_CAFE_JASMINE
# 13 "data/maps/OlivineCity_Cafe/scripts.pory"
	removeobject LOCALID_CAFE_JASMINE
# 14 "data/maps/OlivineCity_Cafe/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 15 "data/maps/OlivineCity_Cafe/scripts.pory"
	clearflag FLAG_HIDE_DOJO_JASMINE
# 16 "data/maps/OlivineCity_Cafe/scripts.pory"
	release
# 17 "data/maps/OlivineCity_Cafe/scripts.pory"
	end
# 18 "data/maps/OlivineCity_Cafe/scripts.pory"

# 19 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Cafe_Text_Jasmine:
# 20 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Oh... Hello, {PLAYER}.\p"
# 21 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "These dishes in front of me are\n"
# 22 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "not all mine...\p"
# 23 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Uh...\p"
# 24 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Actually, the person who sat here\n"
# 25 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "before me ate a lot...\p"
# 26 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "If you'd like to battle again,\n"
# 27 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "please visit me at the Fighting\l"
# 28 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Dojo in Saffron City.$"
# 29 "data/maps/OlivineCity_Cafe/scripts.pory"

# 30 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_EventScript_SailorA::
# 31 "data/maps/OlivineCity_Cafe/scripts.pory"
	lock
# 32 "data/maps/OlivineCity_Cafe/scripts.pory"
	faceplayer
# 33 "data/maps/OlivineCity_Cafe/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
# 34 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
# 35 "data/maps/OlivineCity_Cafe/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 36 "data/maps/OlivineCity_Cafe/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 37 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_EventScript_SailorA2::
# 38 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
# 39 "data/maps/OlivineCity_Cafe/scripts.pory"
	closemessage
# 40 "data/maps/OlivineCity_Cafe/scripts.pory"
	release
# 41 "data/maps/OlivineCity_Cafe/scripts.pory"
	end
# 42 "data/maps/OlivineCity_Cafe/scripts.pory"

# 43 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_EventScript_Cook::
# 44 "data/maps/OlivineCity_Cafe/scripts.pory"
	lock
# 45 "data/maps/OlivineCity_Cafe/scripts.pory"
	faceplayer
# 46 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
# 47 "data/maps/OlivineCity_Cafe/scripts.pory"
	closemessage
# 48 "data/maps/OlivineCity_Cafe/scripts.pory"
	release
# 49 "data/maps/OlivineCity_Cafe/scripts.pory"
	end
# 50 "data/maps/OlivineCity_Cafe/scripts.pory"

# 51 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_EventScript_SailorB::
# 52 "data/maps/OlivineCity_Cafe/scripts.pory"
	lock
# 53 "data/maps/OlivineCity_Cafe/scripts.pory"
	faceplayer
# 54 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
# 55 "data/maps/OlivineCity_Cafe/scripts.pory"
	closemessage
# 56 "data/maps/OlivineCity_Cafe/scripts.pory"
	release
# 57 "data/maps/OlivineCity_Cafe/scripts.pory"
	end
# 58 "data/maps/OlivineCity_Cafe/scripts.pory"

# 59 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Text_CafeSailorStrength:
# 60 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Hah! Your Pokémon sure look like\n"
# 61 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "lightweights!\p"
# 62 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "They don't have the power to\n"
# 63 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "move boulders aside.\p"
# 64 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Here, use this and teach them\n"
# 65 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Strength!$"
# 66 "data/maps/OlivineCity_Cafe/scripts.pory"

# 67 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Text_CafeSailorGotStrength:
# 68 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "On the sea, the only thing you\n"
# 69 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "can count on is your own self!\p"
# 70 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "I'm so proud of my buff bod!\n"
# 71 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "You should train like me!$"
# 72 "data/maps/OlivineCity_Cafe/scripts.pory"

# 73 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Text_CafeFishingGuru:
# 74 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Olivine Cafe's menu is packed\n"
# 75 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "with hearty fare for beefy\l"
# 76 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Sailors like me!$"
# 77 "data/maps/OlivineCity_Cafe/scripts.pory"

# 78 "data/maps/OlivineCity_Cafe/scripts.pory"
OlivineCity_Text_CafeSailor:
# 79 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Whenever I roll into this town,\n"
# 80 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "I always visit the Olivine Cafe.\p"
# 81 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Everything on the menu makes me\n"
# 82 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "feel stronger. I can't stop eating!$"

OlivineCafe_JasmineRematch::
# 87 "data/maps/OlivineCity_Cafe/scripts.pory"
	lock
# 88 "data/maps/OlivineCity_Cafe/scripts.pory"
	faceplayer
# 89 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCafe_JasmineRematch_Text_0
# 95 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCafe_JasmineRematch_Text_1, MSGBOX_YESNO
# 97 "data/maps/OlivineCity_Cafe/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq OlivineCafe_JasmineRematch_2
OlivineCafe_JasmineRematch_1:
# 111 "data/maps/OlivineCity_Cafe/scripts.pory"
	release
	end

OlivineCafe_JasmineRematch_2:
# 98 "data/maps/OlivineCity_Cafe/scripts.pory"
	trainerbattle_no_intro TRAINER_JASMINE_2, OlivineCafe_JasmineRematch_Text_2
# 100 "data/maps/OlivineCity_Cafe/scripts.pory"
	msgbox OlivineCafe_JasmineRematch_Text_3
# 104 "data/maps/OlivineCity_Cafe/scripts.pory"
	closemessage
# 105 "data/maps/OlivineCity_Cafe/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 106 "data/maps/OlivineCity_Cafe/scripts.pory"
	setflag FLAG_HIDE_CAFE_JASMINE
# 107 "data/maps/OlivineCity_Cafe/scripts.pory"
	removeobject LOCALID_CAFE_JASMINE
# 108 "data/maps/OlivineCity_Cafe/scripts.pory"
	delay 30
# 109 "data/maps/OlivineCity_Cafe/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto OlivineCafe_JasmineRematch_1


OlivineCafe_JasmineRematch_Text_0:
# 89 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "Oh, Hello {PLAYER}...\p"
	.string "Did you come here to eat too..?\n"
	.string "I really enjoy the seafood served here.\l"
	.string "It always makes me feel nostalgic for\l"
	.string "some reason.$"

OlivineCafe_JasmineRematch_Text_1:
# 95 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "I was hoping we could have another \n"
	.string "battle again, if that is okay.$"

OlivineCafe_JasmineRematch_Text_2:
# 98 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "You really are amazing, \n"
	.string "{PLAYER}.$"

OlivineCafe_JasmineRematch_Text_3:
# 100 "data/maps/OlivineCity_Cafe/scripts.pory"
	.string "You fight with both kindness and grace.\n"
	.string "Something I strive for every day...\l"
	.string "Thank you for this battle, I won't\l"
	.string "forget it.$"
