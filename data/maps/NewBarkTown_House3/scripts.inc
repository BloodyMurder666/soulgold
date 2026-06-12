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
# 21 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_2
NewBarkTown_RivalsMom_1:
# 25 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_2:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_1
	goto NewBarkTown_RivalsMom_1


NewBarkTown_RivalsSister::
# 30 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 31 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 32 "data/maps/NewBarkTown_House3/scripts.pory"
	checkplayergender
# 33 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsSister_2
# 38 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_1
NewBarkTown_RivalsSister_1:
# 42 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsSister_2:
# 34 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_0
	goto NewBarkTown_RivalsSister_1


NewBarkTownRivalHouseRival::
# 50 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 51 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_0, MSGBOX_NPC
	return


NewBarkTownRivalHouseMarill::
# 56 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 57 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 58 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
# 59 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseMarill_Text_0
# 60 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 61 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTown_RivalsMom_Text_0:
# 15 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Oh, hello {PLAYER}!$"

NewBarkTown_RivalsMom_Text_1:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Crystal is currently upstairs if\n"
	.string "you are looking for her. She is playing\l"
	.string "with her Marill.$"

NewBarkTown_RivalsMom_Text_2:
# 21 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Gold is currently upstairs if\n"
	.string "you are looking for her. She is playing\l"
	.string "with his Marill.$"

NewBarkTown_RivalsSister_Text_0:
# 34 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my sister a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTown_RivalsSister_Text_1:
# 38 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my brother a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTownRivalHouseRival_Text_0:
# 51 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! Have you visited\n"
	.string "any new places?$"

NewBarkTownRivalHouseMarill_Text_0:
# 59 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Marii!$"
