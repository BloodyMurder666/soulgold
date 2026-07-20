EcruteakCity_House4_MapScripts::
	.byte 0


Itemfinder_Cooltrainer::
# 4 "data/maps/EcruteakCity_House4/scripts.pory"
	lock
# 5 "data/maps/EcruteakCity_House4/scripts.pory"
	faceplayer
# 6 "data/maps/EcruteakCity_House4/scripts.pory"
	goto_if_set FLAG_GOT_DOWSING_MACHINE, Itemfinder_Cooltrainer_2
# 18 "data/maps/EcruteakCity_House4/scripts.pory"
	msgbox Itemfinder_Cooltrainer_Text_1, MSGBOX_YESNO
# 25 "data/maps/EcruteakCity_House4/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Itemfinder_Cooltrainer_5
# 41 "data/maps/EcruteakCity_House4/scripts.pory"
	msgbox Itemfinder_Cooltrainer_Text_3
Itemfinder_Cooltrainer_4:
# 43 "data/maps/EcruteakCity_House4/scripts.pory"
	release
	end

Itemfinder_Cooltrainer_2:
# 7 "data/maps/EcruteakCity_House4/scripts.pory"
	msgbox Itemfinder_Cooltrainer_Text_0
# 15 "data/maps/EcruteakCity_House4/scripts.pory"
	release
	end

Itemfinder_Cooltrainer_5:
# 26 "data/maps/EcruteakCity_House4/scripts.pory"
	msgbox Itemfinder_Cooltrainer_Text_2
# 30 "data/maps/EcruteakCity_House4/scripts.pory"
	giveitem ITEM_DOWSING_MACHINE
# 31 "data/maps/EcruteakCity_House4/scripts.pory"
	setflag FLAG_GOT_DOWSING_MACHINE
# 32 "data/maps/EcruteakCity_House4/scripts.pory"
	msgbox Itemfinder_Cooltrainer_Text_0
	goto Itemfinder_Cooltrainer_4


Itemfinder_Cooltrainer_Text_0:
# 7 "data/maps/EcruteakCity_House4/scripts.pory"
	.string "There are many items lying about\n"
	.string "that aren't obvious.\p"
	.string "Use the Dowsing Machine for a while\n"
	.string "to see if it points you towards them.\p"
	.string "When it does, you know there's an\n"
	.string "item near you.$"

Itemfinder_Cooltrainer_Text_1:
# 18 "data/maps/EcruteakCity_House4/scripts.pory"
	.string "Ah. You're on an adventure with\n"
	.string "your Pokémon?\p"
	.string "Well, what's an adventure without\n"
	.string "treasure hunting?\p"
	.string "Am I right, or am I right?$"

Itemfinder_Cooltrainer_Text_2:
# 26 "data/maps/EcruteakCity_House4/scripts.pory"
	.string "Good! You understand the true\n"
	.string "spirit of adventure.\p"
	.string "I like that! Take this with you.$"

Itemfinder_Cooltrainer_Text_3:
# 41 "data/maps/EcruteakCity_House4/scripts.pory"
	.string "Oh... To each his own, I suppose...$"
