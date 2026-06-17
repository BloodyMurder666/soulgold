# 1 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 2 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodCity_DepartmentStore_5F_MapScripts::
# 3 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
# 4 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodDeptSundayNpc
# 5 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.byte 0
# 6 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 7 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 8 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Lass::
# 9 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 10 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 11 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
# 12 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 13 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 14 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 15 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 16 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_PokefanM::
# 17 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 18 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 19 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
# 20 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 21 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 22 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 23 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 24 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Girl::
# 25 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 26 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 27 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
# 28 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 29 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 30 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 31 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 32 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Sign::
# 33 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 34 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 35 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
# 36 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 37 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 38 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 39 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 40 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
# 41 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Hello. Oh, your Pokémon…$"
# 42 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 43 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistWait:
# 44 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Wait, I already gave you that TM!$"
# 45 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 46 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
# 47 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "Hmm…\n"
# 48 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "It's not bad, but it's also not good.\p"
# 49 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "You, as the Trainer, need to put in\n"
# 50 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "some more effort.$"
# 51 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 52 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 53 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
# 54 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Every evening we hand out free samples of TM. Please, take this.$"
# 55 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 56 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect2:
# 57 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "We hope that you found use for the TM.$"
# 58 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 59 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
# 60 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "It looks evil. How about this TM\n"
# 61 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "for it?$"
# 62 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 63 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
# 64 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "There are sure to be TMs that are\n"
# 65 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "just perfect for your Pokémon.$"
# 66 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 67 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FLass:
# 68 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "During evenings, a lady comes to hand\n"
# 69 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "out free TMs!$"
# 70 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 71 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FPokefanM:
# 72 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "You can't rename a Pokémon you get\n"
# 73 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "in a trade.\p"
# 74 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "The name is a reflection of the\n"
# 75 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "original trainer's feelings for it.$"
# 76 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 77 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_Girl:
# 78 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "A kind lady gave me Return\n"
# 79 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "last Sunday!$"
# 80 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 81 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FDirectory:
# 82 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Customize Your Pokémon\p"
# 83 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "5F TM Corner$"

GoldenrodDeptSundayNpc::
# 88 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	compare VAR_DAY_OF_WEEK, 0
	goto_if_ne GoldenrodDeptSundayNpc_1
	return

GoldenrodDeptSundayNpc_1:
# 89 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	setflag FLAG_TEMP_A
	return


Goldenrod_F5_ReturnClerk::
# 94 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 95 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	goto_if_set FLAG_GOT_RETURN, Goldenrod_F5_ReturnClerk_2
# 101 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox Goldenrod_F5_ReturnClerk_Text_1
# 105 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	giveitem ITEM_TM_RETURN
# 106 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	setflag FLAG_GOT_RETURN
# 107 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox Goldenrod_F5_ReturnClerk_Text_0
# 109 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
	end

Goldenrod_F5_ReturnClerk_2:
# 96 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox Goldenrod_F5_ReturnClerk_Text_0
# 98 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
	end


GoldenrodDept5FMart::
# 115 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 116 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDept5FMart_Text_0
# 117 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 118 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	pokemart Goldenrod_F5_TMMart
# 119 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDept5FMart_Text_1
# 120 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
	end


	.align 2
# 124 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
Goldenrod_F5_TMMart:
# 125 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_PROTECT
# 126 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_REFLECT
# 127 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_LIGHT_SCREEN
# 128 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_SAFEGUARD
# 129 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_FIRE_PUNCH
# 130 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_ICE_PUNCH
# 131 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_THUNDER_PUNCH
# 132 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_NONE

Goldenrod_F5_ReturnClerk_Text_0:
# 96 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "Return grows in power the more your\n"
	.string "Pokémon loves you!$"

Goldenrod_F5_ReturnClerk_Text_1:
# 101 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "We're currently handing out free\n"
	.string "samples of our most popular TM. \p"
	.string "Here, have one!$"

GoldenrodDept5FMart_Text_0:
# 116 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "Welcome to the TMs department!$"

GoldenrodDept5FMart_Text_1:
# 119 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "Come back soon!$"
