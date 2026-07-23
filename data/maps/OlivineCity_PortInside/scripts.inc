# 1 "data/maps/OlivineCity_PortInside/scripts.pory"

# 2 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_MapScripts::
# 3 "data/maps/OlivineCity_PortInside/scripts.pory"
	.byte 0
# 4 "data/maps/OlivineCity_PortInside/scripts.pory"

# 5 "data/maps/OlivineCity_PortInside/scripts.pory"

# 6 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakFixDex:
# 7 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 8 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_up
# 9 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 10 "data/maps/OlivineCity_PortInside/scripts.pory"

# 11 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_PlayerMoveOver:
# 12 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 13 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_left
# 14 "data/maps/OlivineCity_PortInside/scripts.pory"
	face_right
# 15 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 16 "data/maps/OlivineCity_PortInside/scripts.pory"

# 17 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Movement_OakLeave:
# 18 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 19 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 20 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 21 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 22 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 23 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 24 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_up
# 25 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 26 "data/maps/OlivineCity_PortInside/scripts.pory"

# 27 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex1:
# 28 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: Hello!\n"
# 29 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You are starting to have the\l"
# 30 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "attitude of a Champion, {PLAYER}!\p"
# 31 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "It's time for your Pokédex to\n"
# 32 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "match who you are.\p"
# 33 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Let me see your Pokédex for a\n"
# 34 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "second.\p"
# 35 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I'll upgrade your Pokédex with the\n"
# 36 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "National Mode.$"
# 37 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex2:
# 38 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "{PLAYER}'s Pokédex was upgraded\n"
# 39 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "with the National Mode!$"
# 40 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex3:
# 41 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Prof.Oak: It won't be easy to\n"
# 42 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "complete the National Pokédex...\p"
# 43 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "However, I'm sure you will make\n"
# 44 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "honest attempt on our behalf!$"
# 45 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivineCity_PortInside_Text_Nationaldex4:
# 46 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Oh, time flies!\p"
# 47 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I have a radio show to record at\n"
# 48 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Goldenrod Radio Tower.\p"
# 49 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "You must be heading for Sevii.\p"
# 50 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "I hear strong trainers are\n"
# 51 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "gathering there. How exciting!$"
# 52 "data/maps/OlivineCity_PortInside/scripts.pory"

# 53 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_CooltrainerF::
# 54 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
# 55 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 56 "data/maps/OlivineCity_PortInside/scripts.pory"

# 57 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher1::
# 58 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
# 59 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 60 "data/maps/OlivineCity_PortInside/scripts.pory"

# 61 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Fisher2::
# 62 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
# 63 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 64 "data/maps/OlivineCity_PortInside/scripts.pory"

# 65 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_EventScript_Youngster::
# 66 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
# 67 "data/maps/OlivineCity_PortInside/scripts.pory"
	end
# 68 "data/maps/OlivineCity_PortInside/scripts.pory"

# 69 "data/maps/OlivineCity_PortInside/scripts.pory"

# 70 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_SailorEnterBoat:
# 71 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 72 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 73 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 74 "data/maps/OlivineCity_PortInside/scripts.pory"

# 75 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_PlayerEnterBoat:
# 76 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 77 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_down
# 78 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_in_place_down
# 79 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 80 "data/maps/OlivineCity_PortInside/scripts.pory"

# 81 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Movement_BoatLeave:
# 82 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 83 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 84 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 85 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 86 "data/maps/OlivineCity_PortInside/scripts.pory"
	walk_right
# 87 "data/maps/OlivineCity_PortInside/scripts.pory"
	step_end
# 88 "data/maps/OlivineCity_PortInside/scripts.pory"

# 89 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoPass:
# 90 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 91 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}…\p"
# 92 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no {STR_VAR_1}!\p"
# 93 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 94 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only if you have an\l"
# 95 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{STR_VAR_1}.$"
# 96 "data/maps/OlivineCity_PortInside/scripts.pory"

# 97 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorGetOnBoard:
# 98 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We're departing soon.\n"
# 99 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Please get on board.$"
# 100 "data/maps/OlivineCity_PortInside/scripts.pory"

# 101 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CantBoard:
# 102 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry. You can't board now.$"
# 103 "data/maps/OlivineCity_PortInside/scripts.pory"

# 104 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_WhereSail:
# 105 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Where would you like to sail?$"
# 106 "data/maps/OlivineCity_PortInside/scripts.pory"

# 107 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskBoard:
# 108 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Welcome to Fast Ship S.S.Aqua.\p"
# 109 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Will you be boarding today?$"
# 110 "data/maps/OlivineCity_PortInside/scripts.pory"

# 111 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_AskTicket:
# 112 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "May I see your S.S.Ticket?$"
# 113 "data/maps/OlivineCity_PortInside/scripts.pory"

# 114 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_ComeAgain:
# 115 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We hope to see you again!$"
# 116 "data/maps/OlivineCity_PortInside/scripts.pory"

# 117 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FlashTicket:
# 118 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} flashed the S.S.Ticket.\p"
# 119 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "That's it. Thank you!$"
# 120 "data/maps/OlivineCity_PortInside/scripts.pory"

# 121 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_NoTicket:
# 122 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "{PLAYER} tried to show the\n"
# 123 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Ticket…\p"
# 124 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "…But no Ticket!\p"
# 125 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Sorry!\n"
# 126 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "You may board only\l"
# 127 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "if you have an S.S.Ticket.$"
# 128 "data/maps/OlivineCity_PortInside/scripts.pory"

# 129 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru1:
# 130 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Mareanie are easy to catch here.\p"
# 131 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "They're kind of rare elsewhere.$"
# 132 "data/maps/OlivineCity_PortInside/scripts.pory"

# 133 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_FishingGuru2:
# 134 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "How many Rods do you have?\p"
# 135 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Different Rods catch different\n"
# 136 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "Pokémon.$"
# 137 "data/maps/OlivineCity_PortInside/scripts.pory"

# 138 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_Youngster:
# 139 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "S.S.Aqua uses jets to skim\n"
# 140 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "over the waves!$"
# 141 "data/maps/OlivineCity_PortInside/scripts.pory"

# 142 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_CooltrainerF:
# 143 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "There are lots of Pokémon in\p"
# 144 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "the world. I wish I could travel...$"
# 145 "data/maps/OlivineCity_PortInside/scripts.pory"

# 146 "data/maps/OlivineCity_PortInside/scripts.pory"
OlivinePort_Text_SailorBeforeHOF:
# 147 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "We don't want you to fall into the\n"
# 148 "data/maps/OlivineCity_PortInside/scripts.pory"
    .string "sea, so you're not allowed in.$"

OlivinePort_Sailor::
# 151 "data/maps/OlivineCity_PortInside/scripts.pory"
	msgbox OlivinePort_Sailor_Text_0, MSGBOX_NPC
	return


OlivinePort_Sailor_Text_0:
# 151 "data/maps/OlivineCity_PortInside/scripts.pory"
	.string "Sorry, but the ship is not going to\n"
	.string "leave anywhere anytime soon. \p"
	.string "Our engines exploded mysteriously.\p"
	.string "Strange, right?$"
