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
# 165 "data/maps/NewBarkTown_House3/scripts.pory"
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
	goto_if_eq NewBarkTownRivalHouseRival_11
NewBarkTownRivalHouseRival_10:
# 109 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq NewBarkTownRivalHouseRival_14
NewBarkTownRivalHouseRival_13:
# 115 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto_if_eq NewBarkTownRivalHouseRival_17
# 137 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq NewBarkTownRivalHouseRival_20
NewBarkTownRivalHouseRival_19:
# 142 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_eq NewBarkTownRivalHouseRival_23
# 159 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
	goto_if_eq NewBarkTownRivalHouseRival_25
	goto NewBarkTownRivalHouseRival_4

NewBarkTownRivalHouseRival_8:
# 71 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_1
# 101 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
# 102 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_11:
# 106 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_2
	goto NewBarkTownRivalHouseRival_10

NewBarkTownRivalHouseRival_14:
# 110 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_3
	goto NewBarkTownRivalHouseRival_13

NewBarkTownRivalHouseRival_17:
# 116 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_4
# 133 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
# 134 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_20:
# 138 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_5
	goto NewBarkTownRivalHouseRival_19

NewBarkTownRivalHouseRival_23:
# 143 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_6
# 155 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
# 156 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_25:
# 160 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_7
	goto NewBarkTownRivalHouseRival_4


NewBarkTownRivalHouseMarill::
# 171 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 172 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 173 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
# 174 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseMarill_Text_0
# 175 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 176 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTownRivalHouseAzumarill::
# 181 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 182 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 183 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 184 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseAzumarill_Text_0
# 185 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 186 "data/maps/NewBarkTown_House3/scripts.pory"
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
	.string "you are looking for him. He is playing\l"
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

NewBarkTownRivalHouseRival_Text_3:
# 110 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Oh you found Cresselia's location?\p"
	.string "That's great! You should catch it\n"
	.string "if you're able to!$"

NewBarkTownRivalHouseRival_Text_4:
# 116 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You caught Cresselia? \n"
	.string "Nice!\p"
	.string "I've been researching Darkrai's\n"
	.string "meanwhile.\p"
	.string "I'm quite sure that it has something\n"
	.string "to do with the old, run down inn in\l"
	.string "Cherrygrove City.\p"
	.string "It was closed due to some child\n"
	.string "falling to sleep and not waking up, real\l"
	.string "bad press for the inn.\p"
	.string "So in short, take Cresselia with you\n"
	.string "and go check out the inn in Cherrygrove\l"
	.string "City. See if you can find out anything!$"

NewBarkTownRivalHouseRival_Text_5:
# 138 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Go check out the old inn in\n"
	.string "Cherrygrove City. Remember to\l"
	.string "take Cresselia with you!$"

NewBarkTownRivalHouseRival_Text_6:
# 143 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You caught Darkrai! Excellent!\p"
	.string "You look like you just had a\n"
	.string "nightmare though, did something\l"
	.string "happen?\p"
	.string "Anyway, I'll need a bit more time to pin\n"
	.string "down the location of the next \l"
	.string "legendary. \p"
	.string "I'll call you once I find something\n"
	.string "worth investigating.$"

NewBarkTownRivalHouseRival_Text_7:
# 160 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "I'm still looking into possible\n"
	.string "leads on legendaries. I'll call you\l"
	.string "once I find something!$"

NewBarkTownRivalHouseMarill_Text_0:
# 174 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Marii!$"

NewBarkTownRivalHouseAzumarill_Text_0:
# 184 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Azumarill: Azuu!$"
