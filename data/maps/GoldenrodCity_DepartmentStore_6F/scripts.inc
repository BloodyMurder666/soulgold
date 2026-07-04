# 1 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 2 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_MapScripts::
# 3 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
# 4 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.byte 0
# 5 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 6 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Whitney::
# 7 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 8 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 9 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
# 10 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 11 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 12 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
# 13 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	removeobject LOCALID_STORE_WHITNEY
# 14 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 15 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	clearflag FLAG_HIDE_DOJO_WHITNEY
# 16 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 17 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 18 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 19 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_Text_Whitney:
# 20 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{PLAYER}! Fancy seeing you here!\p"
# 21 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I'm picking up something for\n"
# 22 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "my Miltank.\p"
# 23 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "If you want another battle, come to\n"
# 24 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "the Fighting Dojo!$"
# 25 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 26 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
# 27 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
# 28 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 29 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 30 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 31 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
# 32 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 33 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
# 34 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 35 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 36 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 37 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
# 38 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
# 39 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 40 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 41 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 42 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
# 43 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I collect Pokémon!\n"
# 44 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Do you have a {STR_VAR_1}?\p"
# 45 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Want to trade it for my\n"
# 46 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{STR_VAR_2}?$"
# 47 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 48 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
# 49 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Yay! I got myself {STR_VAR_1}!\p"
# 50 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "{STR_VAR_2}, you take care!$"
# 51 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 52 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
# 53 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Uh, no, I don't think so.\n"
# 54 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "That isn't a {STR_VAR_1}.$"
# 55 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 56 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
# 57 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "You don't want to trade? Aww...$"
# 58 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 59 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodCity_DepartmentStore_6F_Text_After:
# 60 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Hi, how's my old Machop doing?$"
# 61 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 62 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 63 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Lass::
# 64 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 65 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 66 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
# 67 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 68 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 69 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 70 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 71 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Nerd::
# 72 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 73 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 74 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
# 75 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 76 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 77 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 78 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 79 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore6_EventScript_Sign::
# 80 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 81 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 82 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
# 83 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 84 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
# 85 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	end
# 86 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 87 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FLass:
# 88 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Do you listen to Lucky Channel?\p"
# 89 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "If you want to win, trade Pokémon\n"
# 90 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "with as many people as possible to\l"
# 91 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "get different Id numbers.$"
# 92 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 93 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FSuperNerd:
# 94 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "If you're tired, try the vending\n"
# 95 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "machine's drinks.\p"
# 96 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Your Pokémon will love them too.$"
# 97 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"

# 98 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDeptStore_Text_6FDirectory:
# 99 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "Take a Break from Shopping!\p"
# 100 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
    .string "6F Tranquil Square$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
# 104 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 105 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	faceplayer
# 106 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2
# 110 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	ingame_trade INGAME_TRADE_HONEDGE, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1, HonedgeTrade_Declined, HonedgeTrade_NotRequested, GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2
# 117 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1:
# 119 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_2:
# 107 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0
	goto GoldenrodCity_DepartmentStore_6F_EventScript_Jose_1


HonedgeTrade_Declined::
# 124 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox HonedgeTrade_Declined_Text_0
# 125 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end


HonedgeTrade_NotRequested::
# 130 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox HonedgeTrade_NotRequested_Text_0
# 131 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end


GoldenrodDEpt6F_WhitneyRematch::
# 136 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	lock
# 137 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_0
# 140 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	applymovement LOCALID_STORE_WHITNEY, Common_Movement_ExclamationMark
# 141 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	applymovement LOCALID_STORE_WHITNEY, GoldenrodDEpt6F_WhitneyRematch_Movement_0
# 142 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	waitmovement 0
# 143 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_1
# 148 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_2, MSGBOX_YESNO
# 151 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodDEpt6F_WhitneyRematch_2
GoldenrodDEpt6F_WhitneyRematch_1:
# 172 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	release
	end

GoldenrodDEpt6F_WhitneyRematch_2:
# 152 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	trainerbattle_no_intro TRAINER_WHITNEY_2, GoldenrodDEpt6F_WhitneyRematch_Text_3
# 153 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	msgbox GoldenrodDEpt6F_WhitneyRematch_Text_4
# 165 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	closemessage
# 166 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	moveobjecttocoords LOCALID_STORE_WHITNEY, 24, 5, DIR_WEST
# 167 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
# 168 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	playse SE_EXIT
# 169 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	removeobject LOCALID_STORE_WHITNEY
# 170 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	delay 30
	goto GoldenrodDEpt6F_WhitneyRematch_1


# 141 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
GoldenrodDEpt6F_WhitneyRematch_Movement_0:
# 141 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	face_player
	step_end

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_0:
# 107 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Thanks for the Clefairy again!\n"
	.string "Hope my Pokémon has been of use to you!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_1:
# 111 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I've been looking for a rare Pokémon\n"
	.string "Clefairy for a while now. Do you have it?\l"
	.string "I'll give you something rare in return!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose_Text_2:
# 116 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Thanks a lot!$"

HonedgeTrade_Declined_Text_0:
# 124 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Shame, I hear Clefairy can be found on\n"
	.string "Route 34 sometimes.$"

HonedgeTrade_NotRequested_Text_0:
# 130 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "I don't think that's a Clefairy...$"

GoldenrodDEpt6F_WhitneyRematch_Text_0:
# 137 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Hmm... Maybe this one...?\n"
	.string "No... That one is cheaper...\l"
	.string "Wait, but if I buy two then...$"

GoldenrodDEpt6F_WhitneyRematch_Text_1:
# 143 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Oh, hi there!\n"
	.string "Do you also shop here? I was here\l"
	.string "today to check on some new Pokéfan\l"
	.string "magazines. They have the cutest\l"
	.string "Clefairies!$"

GoldenrodDEpt6F_WhitneyRematch_Text_2:
# 148 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Hey I know, how about a battle?\n"
	.string "I promise I'll make you cry this\l"
	.string "time instead!$"

GoldenrodDEpt6F_WhitneyRematch_Text_3:
# 152 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Mustn't cry... Mustn't cry...!$"

GoldenrodDEpt6F_WhitneyRematch_Text_4:
# 153 "data/maps/GoldenrodCity_DepartmentStore_6F/scripts.pory"
	.string "Aaaaargh! I thought I had you there!\n"
	.string "So frustrating...\p"
	.string "That was a really good battle, but I\n"
	.string "always get so frustrated when I lose\l"
	.string "that I want to cry. I've been trying\l"
	.string "really hard to get out of that habit.\p"
	.string "I've decided that next time we battle,\n"
	.string "I'll try even harder and we'll roll\l"
	.string "you over! Until then, you better train \l"
	.string "hard!$"
