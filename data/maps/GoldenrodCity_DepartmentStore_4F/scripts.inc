GoldenrodCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Hey. I love strong Pokémon.\p"
    .string "I feed them Protein to crank up\n"
    .string "their Attack.$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Iron adds to your Pokémon's\n"
    .string "Defense.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "There were rumours that some\n"
    .string "Pokémon evolve only by\l"
    .string "being traded via a Game Link\l"
    .string "cable.\p"
    .string "Pfft...\p"
    .string "Such misinformation.\p"
    .string "I know some of the rumoured\n"
    .string "Pokémon:\l"
    .string "Machoke, Kadabra, Haunter and,\l"
    .string "um, Graveler,\l"
    .string "but they all evolve through\l"
    .string "level up.$"

GoldenrodDeptStore_Text_4FDirectory:
    .string "Let Us Pump Up Your Pokémon!\p"
    .string "4F Medicine Box$"
