# 1 "data/maps/SproutTower_1F/scripts.pory"

# 2 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_MapScripts::
# 3 "data/maps/SproutTower_1F/scripts.pory"
	.byte 0
# 4 "data/maps/SproutTower_1F/scripts.pory"

# 5 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_EventScript_SageChow::
# 6 "data/maps/SproutTower_1F/scripts.pory"
	trainerbattle_single TRAINER_CHOW, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
# 7 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SproutTower_1F/scripts.pory"
	end
# 9 "data/maps/SproutTower_1F/scripts.pory"

# 10 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_EventScript_Sage1::
# 11 "data/maps/SproutTower_1F/scripts.pory"
	lock
# 12 "data/maps/SproutTower_1F/scripts.pory"
	faceplayer
# 13 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
# 14 "data/maps/SproutTower_1F/scripts.pory"
	closemessage
# 15 "data/maps/SproutTower_1F/scripts.pory"
	release
# 16 "data/maps/SproutTower_1F/scripts.pory"
	end
# 17 "data/maps/SproutTower_1F/scripts.pory"

# 18 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_EventScript_Sage2::
# 19 "data/maps/SproutTower_1F/scripts.pory"
	lock
# 20 "data/maps/SproutTower_1F/scripts.pory"
	faceplayer
# 21 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
# 22 "data/maps/SproutTower_1F/scripts.pory"
	closemessage
# 23 "data/maps/SproutTower_1F/scripts.pory"
	release
# 24 "data/maps/SproutTower_1F/scripts.pory"
	end
# 25 "data/maps/SproutTower_1F/scripts.pory"

# 26 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_EventScript_Granny::
# 27 "data/maps/SproutTower_1F/scripts.pory"
	lock
# 28 "data/maps/SproutTower_1F/scripts.pory"
	faceplayer
# 29 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
# 30 "data/maps/SproutTower_1F/scripts.pory"
	closemessage
# 31 "data/maps/SproutTower_1F/scripts.pory"
	release
# 32 "data/maps/SproutTower_1F/scripts.pory"
	end
# 33 "data/maps/SproutTower_1F/scripts.pory"

# 34 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_1F_EventScript_Teacher::
# 35 "data/maps/SproutTower_1F/scripts.pory"
	lock
# 36 "data/maps/SproutTower_1F/scripts.pory"
	faceplayer
# 37 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
# 38 "data/maps/SproutTower_1F/scripts.pory"
	closemessage
# 39 "data/maps/SproutTower_1F/scripts.pory"
	release
# 40 "data/maps/SproutTower_1F/scripts.pory"
	end
# 41 "data/maps/SproutTower_1F/scripts.pory"

# 42 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_SageChow_Seen:
# 43 "data/maps/SproutTower_1F/scripts.pory"
	.string "We stand guard in this tower.\p"
# 44 "data/maps/SproutTower_1F/scripts.pory"
	.string "Here, we express our gratitude\n"
# 45 "data/maps/SproutTower_1F/scripts.pory"
	.string "to honor all Pokémon.$"
# 46 "data/maps/SproutTower_1F/scripts.pory"

# 47 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_SageChow_Beaten:
# 48 "data/maps/SproutTower_1F/scripts.pory"
	.string "Th-Thank you!$"
# 49 "data/maps/SproutTower_1F/scripts.pory"

# 50 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_SageChow_AfterBattle:
# 51 "data/maps/SproutTower_1F/scripts.pory"
	.string "All living beings coexist\n"
# 52 "data/maps/SproutTower_1F/scripts.pory"
	.string "through cooperation.\p"
# 53 "data/maps/SproutTower_1F/scripts.pory"
	.string "We must always be thankful\n"
# 54 "data/maps/SproutTower_1F/scripts.pory"
	.string "for this.$"
# 55 "data/maps/SproutTower_1F/scripts.pory"

# 56 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_1F_Sage1:
# 57 "data/maps/SproutTower_1F/scripts.pory"
	.string "Only if you reach the top will\n"
# 58 "data/maps/SproutTower_1F/scripts.pory"
	.string "you obtain an HM.$"
# 59 "data/maps/SproutTower_1F/scripts.pory"

# 60 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_1F_Sage2:
# 61 "data/maps/SproutTower_1F/scripts.pory"
	.string "Sprout Tower was built long ago\n"
# 62 "data/maps/SproutTower_1F/scripts.pory"
	.string "as a place for Pokémon training.$"
# 63 "data/maps/SproutTower_1F/scripts.pory"

# 64 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_1F_Granny:
# 65 "data/maps/SproutTower_1F/scripts.pory"
	.string "A Bellsprout over 100 feet\n"
# 66 "data/maps/SproutTower_1F/scripts.pory"
	.string "tall…\p"
# 67 "data/maps/SproutTower_1F/scripts.pory"
	.string "People say that it became the\n"
# 68 "data/maps/SproutTower_1F/scripts.pory"
	.string "center pillar here.$"
# 69 "data/maps/SproutTower_1F/scripts.pory"

# 70 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_1F_Teacher:
# 71 "data/maps/SproutTower_1F/scripts.pory"
	.string "See the pillar shaking?\p"
# 72 "data/maps/SproutTower_1F/scripts.pory"
	.string "People are training upstairs.$"
# 73 "data/maps/SproutTower_1F/scripts.pory"

# 74 "data/maps/SproutTower_1F/scripts.pory"
SproutTower_Text_1F_Statue:
# 75 "data/maps/SproutTower_1F/scripts.pory"
	.string "A Pokémon statue…\p"
# 76 "data/maps/SproutTower_1F/scripts.pory"
	.string "It looks very distinguished.$"

SproutTower_1F_Guard::
# 80 "data/maps/SproutTower_1F/scripts.pory"
	lock
# 81 "data/maps/SproutTower_1F/scripts.pory"
	faceplayer
# 82 "data/maps/SproutTower_1F/scripts.pory"
	goto_if_unset FLAG_BADGE08_GET, SproutTower_1F_Guard_2
# 89 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_1F_Guard_Text_1
# 93 "data/maps/SproutTower_1F/scripts.pory"
	release
	end

SproutTower_1F_Guard_2:
# 83 "data/maps/SproutTower_1F/scripts.pory"
	msgbox SproutTower_1F_Guard_Text_0
# 86 "data/maps/SproutTower_1F/scripts.pory"
	release
	end


SproutTower_1F_Guard_Text_0:
# 83 "data/maps/SproutTower_1F/scripts.pory"
	.string "My apologies, but the entry to the lower\n"
	.string "floors is restricted. Only those\l"
	.string "approved by the Sage may enter.$"

SproutTower_1F_Guard_Text_1:
# 89 "data/maps/SproutTower_1F/scripts.pory"
	.string "Greetings, {PLAYER}.\n"
	.string "Elder Li would like to speak with you.\p"
	.string "Please see him in the top floor.$"
