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
GoldenrodDeptStore5_EventScript_Receptionist::
# 41 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	lock
# 42 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 43 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	goto GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship
# 44 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 45 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 46 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 47 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship::
# 48 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	call_if_unset FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
# 49 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect2, MSGBOX_DEFAULT
# 50 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 51 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 52 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 53 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 54 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship::
# 55 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	call_if_unset FLAG_GOT_FRUSTRATION, GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration
# 56 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
# 57 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 58 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 59 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 60 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 61 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
# 62 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	giveitem ITEM_TM_RETURN
# 63 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	setflag FLAG_GOT_RETURN
# 64 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect
# 65 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	return
# 66 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 67 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration::
# 68 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	giveitem ITEM_TM_FRUSTRATION
# 69 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	setflag FLAG_GOT_FRUSTRATION
# 70 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	return
# 71 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 72 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort::
# 73 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
# 74 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 75 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 76 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 77 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 78 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore5_EventScript_Receptionist_Already::
# 79 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
# 80 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 81 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	release
# 82 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	end
# 83 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 84 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 85 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 86 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
# 87 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Hello. Oh, your POKéMON…$"
# 88 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 89 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistWait:
# 90 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Wait, I already gave you that TM!$"
# 91 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 92 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
# 93 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "Hmm…\n"
# 94 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "It's not bad, but it's also not good.\p"
# 95 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "You, as the Trainer, need to put in\n"
# 96 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "some more effort.$"
# 97 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 98 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 99 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
# 100 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "On Sundays we hand out free samples of TMs. Please, take this.$"
# 101 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 102 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect2:
# 103 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "We hope that you found use for the TM.$"
# 104 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 105 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
# 106 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "It looks evil. How about this TM\n"
# 107 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "for it?$"
# 108 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 109 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
# 110 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "There are sure to be TMs that are\n"
# 111 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "just perfect for your POKéMON.$"
# 112 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 113 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FLass:
# 114 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "On Sunday, a lady comes to hand\n"
# 115 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "out free TMs!$"
# 116 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 117 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FPokefanM:
# 118 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "You can't rename a POKéMON you get\n"
# 119 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "in a trade.\p"
# 120 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "The name is a reflection of the\n"
# 121 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "original trainer's feelings for it.$"
# 122 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 123 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_Girl:
# 124 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	.string "A kind lady gave me Return\n"
# 125 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "last Sunday!$"
# 126 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"

# 127 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
GoldenrodDeptStore_Text_5FDirectory:
# 128 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "Customize Your POKéMON\p"
# 129 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
    .string "5F TM Corner$"

GoldenrodDeptSundayNpc::
# 134 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	compare VAR_DAY_OF_WEEK, 0
	goto_if_ne GoldenrodDeptSundayNpc_1
	return

GoldenrodDeptSundayNpc_1:
# 135 "data/maps/GoldenrodCity_DepartmentStore_5F/scripts.pory"
	setflag FLAG_TEMP_A
	return

