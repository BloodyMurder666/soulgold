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
	goto_if_eq VAR_POSTGAME_RIVAL_LEGENDARYQ, 1, LakeOfRageMystic_CresseliaQuest
# 19 "data/maps/LakeOfRage_House1/scripts.pory"
	goto_if_eq VAR_POSTGAME_RIVAL_LEGENDARYQ, 2, LakeOfRageMystic_CresseliaQuest
# 20 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
# 21 "data/maps/LakeOfRage_House1/scripts.pory"
	closemessage
# 22 "data/maps/LakeOfRage_House1/scripts.pory"
	release
# 23 "data/maps/LakeOfRage_House1/scripts.pory"
	end
# 24 "data/maps/LakeOfRage_House1/scripts.pory"

# 25 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Intro:
# 26 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "…You have strayed far…\p"
# 27 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Here I have meditated. Inside me,\n"
# 28 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "a new power has been awakened.\p"
# 29 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Let me share my power with your\n"
# 30 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Pokémon. Take this, child.$"
# 31 "data/maps/LakeOfRage_House1/scripts.pory"

# 32 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Explanation:
# 33 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Do you see it? It is Hidden Power!\p"
# 34 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "It draws out the power of Pokémon\n"
# 35 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "for attacking.\p"
# 36 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "Remember this: its type and power\n"
# 37 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "depend on the Pokémon using it.$"
# 38 "data/maps/LakeOfRage_House1/scripts.pory"

# 39 "data/maps/LakeOfRage_House1/scripts.pory"
HiddenPowerGuy_Text_Meditating:
# 40 "data/maps/LakeOfRage_House1/scripts.pory"
    .string "I am meditating…$"

LakeOfRageMystic_CresseliaQuest::
# 44 "data/maps/LakeOfRage_House1/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq LakeOfRageMystic_CresseliaQuest_2
# 50 "data/maps/LakeOfRage_House1/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto_if_ge LakeOfRageMystic_CresseliaQuest_5
# 55 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox LakeOfRageMystic_CresseliaQuest_Text_2
# 72 "data/maps/LakeOfRage_House1/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
# 73 "data/maps/LakeOfRage_House1/scripts.pory"
	release
	end

LakeOfRageMystic_CresseliaQuest_2:
# 45 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox LakeOfRageMystic_CresseliaQuest_Text_0
# 47 "data/maps/LakeOfRage_House1/scripts.pory"
	release
	end

LakeOfRageMystic_CresseliaQuest_5:
# 51 "data/maps/LakeOfRage_House1/scripts.pory"
	msgbox LakeOfRageMystic_CresseliaQuest_Text_1
# 52 "data/maps/LakeOfRage_House1/scripts.pory"
	release
	end


LakeOfRageMystic_CresseliaQuest_Text_0:
# 45 "data/maps/LakeOfRage_House1/scripts.pory"
	.string "Perhaps there is a hidden trail among\n"
	.string "the trees if you look carefully enough.$"

LakeOfRageMystic_CresseliaQuest_Text_1:
# 51 "data/maps/LakeOfRage_House1/scripts.pory"
	.string "I am meditating...$"

LakeOfRageMystic_CresseliaQuest_Text_2:
# 55 "data/maps/LakeOfRage_House1/scripts.pory"
	.string "Hmm? \n"
	.string "You wish to know about Cresselia?\p"
	.string "Fascinating. \p"
	.string "It is quite rare for someone seek me\n"
	.string "for knowledge willingly.\p"
	.string "I have indeed seen the creature in\n"
	.string "question, basking in the bright\l"
	.string "moonlight on a rare occasion.\p"
	.string "Then it vanishes into the far corners \n"
	.string "of the lake when spotted!\p"
	.string "Perhaps there is a hidden trail among\n"
	.string "the trees if you look carefully enough.$"
