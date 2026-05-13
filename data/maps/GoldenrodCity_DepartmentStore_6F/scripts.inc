# 1 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 2 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
.set LOCALID_STORE_WHITNEY, 4
# 3 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 4 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_MapScripts::
# 5 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
# 6 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.byte 0
# 7 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 8 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Whitney::
# 9 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 10 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 11 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
# 12 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 13 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 14 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
# 15 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	removeobject LOCALID_STORE_WHITNEY
# 16 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 17 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	clearflag FLAG_HIDE_DOJO_WHITNEY
# 18 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 19 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 20 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 21 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_Text_Whitney:
# 22 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{PLAYER}! Fancy seeing you here!\p"
# 23 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I'm picking up something for\n"
# 24 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "my Miltank.\p"
# 25 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "If you want another battle, come to\n"
# 26 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "the Fighting Dojo!$"
# 27 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 28 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
# 29 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
# 30 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 31 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 32 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 33 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
# 34 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 35 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
# 36 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 37 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 38 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 39 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
# 40 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
# 41 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 42 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 43 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 44 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
# 45 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I collect Pokémon!\n"
# 46 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Do you have a {STR_VAR_1}?\p"
# 47 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Want to trade it for my\n"
# 48 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{STR_VAR_2}?$"
# 49 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 50 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
# 51 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Yay! I got myself {STR_VAR_1}!\p"
# 52 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{STR_VAR_2}, you take care!$"
# 53 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 54 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
# 55 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Uh, no, I don't think so.\n"
# 56 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "That isn't a {STR_VAR_1}.$"
# 57 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 58 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
# 59 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "You don't want to trade? Aww...$"
# 60 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 61 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_After:
# 62 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Hi, how's my old Machop doing?$"
# 63 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 64 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 65 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Lass::
# 66 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 67 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 68 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
# 69 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 70 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 71 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 72 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 73 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Nerd::
# 74 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 75 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 76 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
# 77 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 78 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 79 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 80 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 81 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Sign::
# 82 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 83 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 84 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
# 85 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 86 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 87 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 88 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 89 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FLass:
# 90 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Do you listen to Lucky Channel?\p"
# 91 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "If you want to win, trade Pokémon\n"
# 92 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "with as many people as possible to\l"
# 93 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "get different Id numbers.$"
# 94 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 95 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FSuperNerd:
# 96 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "If you're tired, try the vending\n"
# 97 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "machine's drinks.\p"
# 98 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Your Pokémon will love them too.$"
# 99 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 100 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FDirectory:
# 101 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Take a Break from Shopping!\p"
# 102 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "6F Tranquil Square$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
# 106 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 107 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 108 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2
# 112 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	ingame_trade INGAME_TRADE_HONEDGE, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1, HonedgeTrade_Declined, HonedgeTrade_NotRequested, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2
# 119 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1:
# 121 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2:
# 109 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0
	goto GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1


HonedgeTrade_Declined::
# 126 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox HonedgeTrade_Declined_Text_0
# 127 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end


HonedgeTrade_NotRequested::
# 132 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox HonedgeTrade_NotRequested_Text_0
# 133 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end


GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0:
# 109 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Thanks for the clefairy again! \n"
	.string "Hope my pokémon has been of use to you!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1:
# 113 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I've been looking for a rare Pokémon\n"
	.string "Clefairy for a while now. Do you have it?\l"
	.string "I'll give you something rare in return!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2:
# 118 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Thanks a lot!$"

HonedgeTrade_Declined_Text_0:
# 126 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Shame, I hear Clefairy can be found on\n"
	.string "Route 34 sometimes.$"

HonedgeTrade_NotRequested_Text_0:
# 132 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I don't think that's a Clefairy...$"
