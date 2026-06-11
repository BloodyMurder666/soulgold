# 1 "data/maps/LakeOfRage_House1/scripts.pory"

# 2 "data/maps/LakeOfRage_House1/scripts.pory"
LakeOfRage_House1_MapScripts::
# 3 "data/maps/LakeOfRage_House1/scripts.pory"
	.byte 0
# 4 "data/maps/LakeOfRage_House1/scripts.pory"

# 5 "data/maps/LakeOfRage_House1/scripts.pory"
LakeOfRage_House1_EventScript_HiddenPowerGuy::
# 6 "data/maps/LakeOfRage_House1/scripts.pory"
	lock
# 7 "data/maps/LakeOfRage_House1/scripts.pory"
	faceplayer
# 8 "data/maps/LakeOfRage_House1/scripts.pory"
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
# 9 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
# 10 "data/maps/LakeOfRage_House1/scripts.pory"
	giveitem ITEM_TM_HIDDEN_POWER
# 11 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
# 12 "data/maps/LakeOfRage_House1/scripts.pory"
	setflag FLAG_GOT_HIDDEN_POWER
# 13 "data/maps/LakeOfRage_House1/scripts.pory"
	closemessage
# 14 "data/maps/LakeOfRage_House1/scripts.pory"
	release
# 15 "data/maps/LakeOfRage_House1/scripts.pory"
	end
# 16 "data/maps/LakeOfRage_House1/scripts.pory"

# 17 "data/maps/LakeOfRage_House1/scripts.pory"
LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
# 18 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
# 19 "data/maps/LakeOfRage_House1/scripts.pory"
	closemessage
# 20 "data/maps/LakeOfRage_House1/scripts.pory"
	release
# 21 "data/maps/LakeOfRage_House1/scripts.pory"
	end
# 22 "data/maps/LakeOfRage_House1/scripts.pory"

# 23 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Intro:
# 24 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "…You have strayed far…\p"
# 25 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Here I have meditated. Inside me,\n"
# 26 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "a new power has been awakened.\p"
# 27 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Let me share my power with your\n"
# 28 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Pokémon. Take this, child.$"
# 29 "data/maps/LakeOfRage_House1/scripts.pory"

# 30 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Explanation:
# 31 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Do you see it? It is Hidden Power!\p"
# 32 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "It draws out the power of Pokémon\n"
# 33 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "for attacking.\p"
# 34 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Remember this: its type and power\n"
# 35 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "depend on the Pokémon using it.$"
# 36 "data/maps/LakeOfRage_House1/scripts.pory"

# 37 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Meditating:
# 38 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "I am meditating…$"
