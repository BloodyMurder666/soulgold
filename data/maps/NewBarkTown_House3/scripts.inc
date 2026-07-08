# 1 "data/maps/NewBarkTown_House3/scripts.pory"

# 2 "data/maps/NewBarkTown_House3/scripts.pory"
NewBarkTown_House3_MapScripts::
# 3 "data/maps/NewBarkTown_House3/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_House3_OnTransition
# 4 "data/maps/NewBarkTown_House3/scripts.pory"
	.byte 0
# 5 "data/maps/NewBarkTown_House3/scripts.pory"

# 6 "data/maps/NewBarkTown_House3/scripts.pory"
NewBarkTown_House3_OnTransition::
# 7 "data/maps/NewBarkTown_House3/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 8 "data/maps/NewBarkTown_House3/scripts.pory"
    end

NewBarkTown_RivalsMom::
# 12 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 13 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 14 "data/maps/NewBarkTown_House3/scripts.pory"
	checkplayergender
# 15 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_0
# 16 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsMom_2
# 27 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_12
NewBarkTown_RivalsMom_10:
# 33 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_4
NewBarkTown_RivalsMom_1:
# 37 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_2:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_7
NewBarkTown_RivalsMom_5:
# 23 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_2
	goto NewBarkTown_RivalsMom_1

NewBarkTown_RivalsMom_6:
# 18 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_1
# 20 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_7:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_6
	goto NewBarkTown_RivalsMom_5

NewBarkTown_RivalsMom_11:
# 28 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_3
# 30 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_12:
# 27 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_11
	goto NewBarkTown_RivalsMom_10


NewBarkTown_RivalsSister::
# 42 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 43 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 44 "data/maps/NewBarkTown_House3/scripts.pory"
	checkplayergender
# 45 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsSister_2
# 50 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_1
NewBarkTown_RivalsSister_1:
# 54 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsSister_2:
# 46 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_0
	goto NewBarkTown_RivalsSister_1


NewBarkTownRivalHouseRival::
# 60 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 61 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 62 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 63 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTownRivalHouseRival_2
# 69 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_ge NewBarkTownRivalHouseRival_5
NewBarkTownRivalHouseRival_4:
# 110 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_2:
# 64 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_0, MSGBOX_NPC
# 66 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_5:
# 70 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 0
	goto_if_eq NewBarkTownRivalHouseRival_8
# 105 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
	goto_if_eq NewBarkTownRivalHouseRival_10
	goto NewBarkTownRivalHouseRival_4

NewBarkTownRivalHouseRival_8:
# 71 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_1
# 101 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
# 102 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_10:
# 106 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_2
	goto NewBarkTownRivalHouseRival_4


NewBarkTownRivalHouseMarill::
# 116 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 117 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 118 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
# 119 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseMarill_Text_0
# 120 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 121 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTownRivalHouseAzumarill::
# 126 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 127 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 128 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 129 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseAzumarill_Text_0
# 130 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 131 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTown_RivalsMom_Text_0:
# 15 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Oh, hello {PLAYER}!$"

NewBarkTown_RivalsMom_Text_1:
# 18 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Crystal is currently out, if you were\n"
	.string "looking for her.$"

NewBarkTown_RivalsMom_Text_2:
# 23 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Crystal is currently upstairs if\n"
	.string "you are looking for her. She is playing\l"
	.string "with her Pokémon.$"

NewBarkTown_RivalsMom_Text_3:
# 28 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Gold is currently out, if you were\n"
	.string "looking for him.$"

NewBarkTown_RivalsMom_Text_4:
# 33 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Gold is currently upstairs if\n"
	.string "you are looking for him. She is playing\l"
	.string "with his Pokémon.$"

NewBarkTown_RivalsSister_Text_0:
# 46 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my sister a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTown_RivalsSister_Text_1:
# 50 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my brother a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTownRivalHouseRival_Text_0:
# 64 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! Have you visited\n"
	.string "any new places?$"

NewBarkTownRivalHouseRival_Text_1:
# 71 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! What's up?\p"
	.string "So I've been doing some thinking, and\n"
	.string "decided that I want to help Prof. Elm.\l"
	.string "with his research into legendary\l"
	.string "Pokémon!\p"
	.string "I've started looking into old rumours\n"
	.string "and stories that are circulating in\l"
	.string "Johto, and I've found my first lead.\p"
	.string "If you got time and happen to be in the\n"
	.string "area, would you mind helping me by\l"
	.string "checking them out?\p"
	.string "The first legendary I'm researching\n"
	.string "right now concerns not one but two\l"
	.string "Pokémon actually!\p"
	.string "Have you heard about Darkrai and\n"
	.string "Cresselia?\p"
	.string "One causes nightmares while the other\n"
	.string "cures them, fascinating!\p"
	.string "I think we should track down Cresselia\n"
	.string "first, in order to locate Darkrai.\p"
	.string "I hear that someone living near or in\n"
	.string "the Lake of Rage might know more.$"

NewBarkTownRivalHouseRival_Text_2:
# 106 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "I hear that someone living near or in\n"
	.string "the Lake of Rage might know more.$"

NewBarkTownRivalHouseMarill_Text_0:
# 119 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Marii!$"

NewBarkTownRivalHouseAzumarill_Text_0:
# 129 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Azumarill: Azuu!$"
