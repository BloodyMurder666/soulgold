CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Hello! Welcome to Celadon Dept.\n"
    .string "Store!\p"
    .string "The directory is on the wall.$"

CeladonDeptStore_Text_1FGentleman:
    .string "This Dept.Store is part of the same\n"
    .string "chain as the one in Goldenrod City.\p"
    .string "They were both renovated at the same\n"
    .string "time.$"

CeladonDeptStore_Text_1FTeacher:
    .string "This is my first time here.\p"
    .string "It's so big…\p"
    .string "I'm afraid I'll get lost.$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F: Service Counter\p"
    .string "2F: Trainer's Market\p"
    .string "3F: TM Shop\p"
    .string "4F: Wiseman Gifts\p"
    .string "5F: Drug Store\p"
    .string "6F: Rooftop Square$"
