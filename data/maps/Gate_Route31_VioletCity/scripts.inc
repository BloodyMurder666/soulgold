# 1 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 2 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_MapScripts::
# 3 "data/maps/Gate_Route31_VioletCity/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, Gate_Route31_VioletCity_OnTransition
# 4 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.byte 0
# 5 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 6 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_OnTransition::
# 7 "data/maps/Gate_Route31_VioletCity/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 8 "data/maps/Gate_Route31_VioletCity/scripts.pory"
    end
# 9 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 10 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_EventScript_Policeman::
# 11 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	lock
# 12 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	faceplayer
# 13 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
# 14 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	closemessage
# 15 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	release
# 16 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	end
# 17 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 18 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_EventScript_CooltrainerF::
# 19 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	lock
# 20 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	faceplayer
# 21 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
# 22 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	closemessage
# 23 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	release
# 24 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	end
# 25 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 26 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_Text_Policeman:
# 27 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "Hi there! Did you visit\n"
# 28 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "Sprout Tower?$"
# 29 "data/maps/Gate_Route31_VioletCity/scripts.pory"

# 30 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_Text_CooltrainerF:
# 31 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "I saw the cutest Pokémon out\n"
# 32 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "there.\p"
# 33 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "It looked a lot like Pikachu!$"

Gate_Route31_VioletCity_RivalExpShare::
# 37 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	lock
# 38 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	playse SE_EXIT
# 39 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 40 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_0
# 41 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	closemessage
# 42 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	moveobjecttocoords LOCALID_PLAYER, 6, 5, DIR_EAST
# 43 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	clearflag FLAG_HIDE_RIVAL_VIOLETGATEHOUSE
# 44 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	addobject LOCALID_GATEHOUSE_RIVAL
# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	applymovement LOCALID_GATEHOUSE_RIVAL, Gate_Route31_VioletCity_RivalExpShare_Movement_0
# 46 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_1
# 48 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 49 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	setflag FLAG_RECEIVED_EXP_SHARE
# 50 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_2
# 52 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_3
# 55 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	msgbox Gate_Route31_VioletCity_RivalExpShare_Text_4
# 57 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	closemessage
# 58 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	setflag FLAG_HIDE_RIVAL_VIOLETGATEHOUSE
# 59 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 4
# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	applymovement LOCALID_GATEHOUSE_RIVAL, Gate_Route31_VioletCity_RivalExpShare_Movement_1
# 61 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	waitmovement 0
# 62 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	playse SE_EXIT
# 63 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	removeobject LOCALID_GATEHOUSE_RIVAL
# 64 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	release
	end


# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_RivalExpShare_Movement_0:
# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_left
# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_left
# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_left
# 45 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_left
	step_end

# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
Gate_Route31_VioletCity_RivalExpShare_Movement_1:
# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_right
# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_right
# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_right
# 60 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	walk_right
	step_end

Gate_Route31_VioletCity_RivalExpShare_Text_0:
# 40 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "{PLAYER}! Wait up!$"

Gate_Route31_VioletCity_RivalExpShare_Text_1:
# 47 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "Professor Elm forgot to give you this.$"

Gate_Route31_VioletCity_RivalExpShare_Text_2:
# 50 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "It lets you train multiple Pokémon at\n"
	.string "once, quite a handy piece of tech!$"

Gate_Route31_VioletCity_RivalExpShare_Text_3:
# 52 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "If you haven't already, you should make\n"
	.string "use of those Poké Balls and catch lots\l"
	.string "of new Pokémon.$"

Gate_Route31_VioletCity_RivalExpShare_Text_4:
# 55 "data/maps/Gate_Route31_VioletCity/scripts.pory"
	.string "Anyway, I need to head back home.\n"
	.string "Hope to see you soon {PLAYER}!$"
