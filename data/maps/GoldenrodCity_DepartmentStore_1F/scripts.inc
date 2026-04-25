GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Welcome to Goldenrod Dept.Store.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "The Dept.Store has a decent\n"
    .string "selection.\p"
    .string "But some items are only available\n"
    .string "as Game Corner prizes.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "I'm raring to shop again today!$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Mom's good at bargain hunting.\p"
    .string "She always buys stuff at lower\n"
    .string "prices.$"

GoldenrodDeptStore1_Text_Directory:
    .string "<1F Service Counter>\p"
    .string "2F Trainer'S Market\p"
    .string "3F Battle Collection\p"
    .string "4F Medicine Box\p"
    .string "5F TM Corner\p"
    .string "6F Tranquil Square\p"
    .string "Rooftop Lookout$"
