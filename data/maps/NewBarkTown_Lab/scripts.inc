# 1 "data/maps/NewBarkTown_Lab/scripts.pory"

# 2 "data/maps/NewBarkTown_Lab/scripts.pory"

# 3 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_MapScripts::
# 4 "data/maps/NewBarkTown_Lab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
# 5 "data/maps/NewBarkTown_Lab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
# 6 "data/maps/NewBarkTown_Lab/scripts.pory"
	.byte 0
# 7 "data/maps/NewBarkTown_Lab/scripts.pory"

# 8 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_OnTransition::
# 9 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
# 10 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
# 11 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
# 12 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 13 "data/maps/NewBarkTown_Lab/scripts.pory"
	
# 14 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_OnFrame::
# 15 "data/maps/NewBarkTown_Lab/scripts.pory"
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
# 16 "data/maps/NewBarkTown_Lab/scripts.pory"
	.2byte 0
# 17 "data/maps/NewBarkTown_Lab/scripts.pory"

# 18 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmAtComputer::
# 19 "data/maps/NewBarkTown_Lab/scripts.pory"
	setobjectxyperm LOCALID_ELM, 3, 2
# 20 "data/maps/NewBarkTown_Lab/scripts.pory"
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
# 21 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 22 "data/maps/NewBarkTown_Lab/scripts.pory"

# 23 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
# 24 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 25 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
# 26 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 27 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
# 28 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 29 "data/maps/NewBarkTown_Lab/scripts.pory"

# 30 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerStartLabRight::
# 31 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 32 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
# 33 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 34 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
# 35 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 36 "data/maps/NewBarkTown_Lab/scripts.pory"

# 37 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerStartLab::
# 38 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 39 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
# 40 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 41 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_ElmIntro
# 42 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 43 "data/maps/NewBarkTown_Lab/scripts.pory"

# 44 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_EventScript_Aide1::
# 45 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 46 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 47 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
# 48 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 49 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 50 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 51 "data/maps/NewBarkTown_Lab/scripts.pory"

# 52 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_EventScript_Aide2::
# 53 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 54 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 55 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
# 56 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
# 57 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 58 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 59 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 60 "data/maps/NewBarkTown_Lab/scripts.pory"

# 61 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_EventScript_Aide2Testimony::
# 62 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
# 63 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 64 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 65 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 66 "data/maps/NewBarkTown_Lab/scripts.pory"

# 67 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm::
# 68 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 69 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 70 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
# 71 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
# 72 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
# 73 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
# 74 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket
# 75 "data/maps/NewBarkTown_Lab/scripts.pory"

# 76 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
# 77 "data/maps/NewBarkTown_Lab/scripts.pory"
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
# 78 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
# 79 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5
# 80 "data/maps/NewBarkTown_Lab/scripts.pory"

# 81 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
# 82 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
# 83 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
# 84 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
# 85 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
# 86 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 87 "data/maps/NewBarkTown_Lab/scripts.pory"

# 88 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
# 89 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
# 90 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 91 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 92 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 93 "data/maps/NewBarkTown_Lab/scripts.pory"

# 94 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideIsWaiting:
# 95 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 96 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What are you doing here?\p"
# 97 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "My aide is still waiting for you\n"
# 98 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "In Violet City!$"
# 99 "data/maps/NewBarkTown_Lab/scripts.pory"

# 100 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmIntro::
# 101 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
# 102 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 103 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 104 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 105 "data/maps/NewBarkTown_Lab/scripts.pory"

# 106 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmRefused::
# 107 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
# 108 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 109 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 110 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 111 "data/maps/NewBarkTown_Lab/scripts.pory"

# 112 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmAccepted::
# 113 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
# 114 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
# 115 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 116 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PC_LOGIN
# 117 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 118 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 119 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
# 120 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 121 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
# 122 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
# 123 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 124 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 125 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
# 126 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 127 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
# 128 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 129 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 130 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 131 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 132 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
# 133 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
# 134 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 135 "data/maps/NewBarkTown_Lab/scripts.pory"

# 136 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmChoosePokemon::
# 137 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Right
# 138 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 139 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
# 140 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 141 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Down
# 142 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 143 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
# 144 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 145 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 146 "data/maps/NewBarkTown_Lab/scripts.pory"

# 147 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
# 148 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 149 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
# 150 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 151 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
# 152 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 153 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 154 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 155 "data/maps/NewBarkTown_Lab/scripts.pory"

# 156 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ShouldntTouch::
# 157 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 158 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 159 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 160 "data/maps/NewBarkTown_Lab/scripts.pory"

# 161 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_hideStarterCase::
# 162 "data/maps/NewBarkTown_Lab/scripts.pory"
    setflag FLAG_HIDE_STARTER_CASE
# 163 "data/maps/NewBarkTown_Lab/scripts.pory"
    return
# 164 "data/maps/NewBarkTown_Lab/scripts.pory"

# 165 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase::
# 166 "data/maps/NewBarkTown_Lab/scripts.pory"
    lock
# 167 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
# 168 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_StarterCase_Choice
# 169 "data/maps/NewBarkTown_Lab/scripts.pory"
    msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 170 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 171 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 172 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 173 "data/maps/NewBarkTown_Lab/scripts.pory"

# 174 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase_Choice::
# 175 "data/maps/NewBarkTown_Lab/scripts.pory"
   callnative StartNewPokeballCaseUI
# 176 "data/maps/NewBarkTown_Lab/scripts.pory"
   waitstate
# 177 "data/maps/NewBarkTown_Lab/scripts.pory"
   goto NewBarkTown_Lab_EventScript_ChoseStarter
# 178 "data/maps/NewBarkTown_Lab/scripts.pory"

# 179 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter::
# 180 "data/maps/NewBarkTown_Lab/scripts.pory"
    removeobject VAR_LAST_TALKED
# 181 "data/maps/NewBarkTown_Lab/scripts.pory"
    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
# 182 "data/maps/NewBarkTown_Lab/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 183 "data/maps/NewBarkTown_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
# 184 "data/maps/NewBarkTown_Lab/scripts.pory"
	message NewBarkTown_Lab_Text_ReceivedStarter
# 185 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitfanfare
# 186 "data/maps/NewBarkTown_Lab/scripts.pory"
    hidemonpic
# 187 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
# 188 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 189 "data/maps/NewBarkTown_Lab/scripts.pory"
    closemessage
# 190 "data/maps/NewBarkTown_Lab/scripts.pory"
    moveobjecttocoords OBJ_EVENT_ID_PLAYER, 6, 4, DIR_NONE
# 191 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 192 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 193 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 194 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto NewBarkTown_Lab_EventScript_Elm
# 195 "data/maps/NewBarkTown_Lab/scripts.pory"

# 196 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_DeclinedStarter::
# 197 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 198 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
# 199 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 200 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 201 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 202 "data/maps/NewBarkTown_Lab/scripts.pory"

# 203 "data/maps/NewBarkTown_Lab/scripts.pory"

# 204 "data/maps/NewBarkTown_Lab/scripts.pory"

# 205 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_NicknameStarter::
# 206 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 207 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 208 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 209 "data/maps/NewBarkTown_Lab/scripts.pory"

# 210 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemon::
# 211 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
# 212 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 213 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 214 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 215 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 216 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 217 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
# 218 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
# 219 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 220 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 221 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 222 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 223 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 224 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 225 "data/maps/NewBarkTown_Lab/scripts.pory"

# 226 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
# 227 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
# 228 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 229 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 230 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 231 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 232 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 233 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 234 "data/maps/NewBarkTown_Lab/scripts.pory"

# 235 "data/maps/NewBarkTown_Lab/scripts.pory"
CopNewBarkTown_Lab_EventScript_ElmState2::
# 236 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 237 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 238 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
# 239 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 240 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 241 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 242 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 243 "data/maps/NewBarkTown_Lab/scripts.pory"

# 244 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine1::
# 245 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 246 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
# 247 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 248 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 249 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 250 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 251 "data/maps/NewBarkTown_Lab/scripts.pory"

# 252 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine2::
# 253 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 254 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 255 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 256 "data/maps/NewBarkTown_Lab/scripts.pory"

# 257 "data/maps/NewBarkTown_Lab/scripts.pory"

# 258 "data/maps/NewBarkTown_Lab/scripts.pory"

# 259 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
# 260 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 261 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 262 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 263 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 264 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
# 265 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 266 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POTION
# 267 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 268 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 269 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_EXP_SHARE
# 270 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
# 271 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 272 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 273 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 274 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 275 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 276 "data/maps/NewBarkTown_Lab/scripts.pory"

# 277 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceEpisode::
# 278 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 279 "data/maps/NewBarkTown_Lab/scripts.pory"
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
# 280 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_EventScript_hideStarterCase
# 281 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
# 282 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 283 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_LAB_POLICEMAN
# 284 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject LOCALID_COP DIR_WEST
# 285 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
# 286 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceNameRival
# 287 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceYes
# 288 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 289 "data/maps/NewBarkTown_Lab/scripts.pory"

# 290 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNo::
# 291 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
# 292 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
# 293 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
# 294 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 295 "data/maps/NewBarkTown_Lab/scripts.pory"

# 296 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival::
# 297 "data/maps/NewBarkTown_Lab/scripts.pory"
	special NameRival
# 298 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_NAMED_SILVER
# 299 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 300 "data/maps/NewBarkTown_Lab/scripts.pory"

# 301 "data/maps/NewBarkTown_Lab/scripts.pory"

# 302 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival2::
# 303 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 304 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 305 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 306 "data/maps/NewBarkTown_Lab/scripts.pory"

# 307 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes::
# 308 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
# 309 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 310 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes2
# 311 "data/maps/NewBarkTown_Lab/scripts.pory"

# 312 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes3::
# 313 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT @okay, for some reason this script doesn't take effect at all... Added a duplicate after this because it was a workaround.
# 314 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 315 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 316 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 317 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 318 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 319 "data/maps/NewBarkTown_Lab/scripts.pory"

# 320 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 321 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 322 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 323 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 324 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 325 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 326 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 327 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 328 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 329 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 330 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 331 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 332 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 333 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 334 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 335 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 336 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 337 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 338 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 339 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 340 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 341 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 342 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 343 "data/maps/NewBarkTown_Lab/scripts.pory"

# 344 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes2::
# 345 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 346 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 347 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 348 "data/maps/NewBarkTown_Lab/scripts.pory"

# 349 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 350 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 351 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 352 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 353 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 354 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 355 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 356 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 357 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 358 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 359 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 360 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 361 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 362 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 363 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 364 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 365 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 366 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 367 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 368 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 369 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 370 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 371 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 372 "data/maps/NewBarkTown_Lab/scripts.pory"

# 373 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmState5::
# 374 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 375 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 376 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
# 377 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 378 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
# 379 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 380 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 381 "data/maps/NewBarkTown_Lab/scripts.pory"
	
# 382 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmMasterBall::
# 383 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 384 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 385 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
# 386 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_MASTER_BALL
# 387 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
# 388 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 389 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 390 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 391 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
# 392 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 393 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
# 394 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 395 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
# 396 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
# 397 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 398 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 399 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 400 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 401 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 402 "data/maps/NewBarkTown_Lab/scripts.pory"

# 403 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmKimono::
# 404 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 405 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 406 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
# 407 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 408 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 409 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 410 "data/maps/NewBarkTown_Lab/scripts.pory"

# 411 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmLeague::
# 412 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 413 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 414 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
# 415 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 416 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 417 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 418 "data/maps/NewBarkTown_Lab/scripts.pory"

# 419 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmSSTicket::
# 420 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
# 421 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SS_TICKET
# 422 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
# 423 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 424 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 425 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 426 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
# 427 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 428 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 429 "data/maps/NewBarkTown_Lab/scripts.pory"

# 430 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
# 431 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 432 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 433 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 434 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 435 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
# 436 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 437 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 438 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 439 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_BALLS
# 440 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
# 441 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 442 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 443 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 444 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 445 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 446 "data/maps/NewBarkTown_Lab/scripts.pory"

# 447 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
# 448 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
# 449 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 450 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 451 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 452 "data/maps/NewBarkTown_Lab/scripts.pory"

# 453 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
# 454 "data/maps/NewBarkTown_Lab/scripts.pory"
	specialvar VAR_RESULT, CheckTogepi
# 455 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
# 456 "data/maps/NewBarkTown_Lab/scripts.pory"
	return
# 457 "data/maps/NewBarkTown_Lab/scripts.pory"

# 458 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
# 459 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
# 460 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 461 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
# 462 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 463 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
# 464 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 465 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
# 466 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 467 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 468 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 469 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
# 470 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 471 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_SHOWN_ELM_TOGEPI
# 472 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 473 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 474 "data/maps/NewBarkTown_Lab/scripts.pory"

# 475 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_CallMe::
# 476 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
# 477 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 478 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 479 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 480 "data/maps/NewBarkTown_Lab/scripts.pory"

# 481 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkRight:
# 482 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 483 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 484 "data/maps/NewBarkTown_Lab/scripts.pory"

# 485 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkLeft:
# 486 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 487 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 488 "data/maps/NewBarkTown_Lab/scripts.pory"

# 489 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_LabMovement_WalkToElm:
# 490 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 491 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 492 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 493 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 494 "data/maps/NewBarkTown_Lab/scripts.pory"

# 495 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnPlayer:
# 496 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 497 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 498 "data/maps/NewBarkTown_Lab/scripts.pory"

# 499 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmail:
# 500 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 501 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 502 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 503 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 504 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 505 "data/maps/NewBarkTown_Lab/scripts.pory"

# 506 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmailSlow:
# 507 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 508 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 509 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 510 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 511 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 512 "data/maps/NewBarkTown_Lab/scripts.pory"

# 513 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_GotoComputerSafe:
# 514 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 515 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 516 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 517 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 518 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 519 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 520 "data/maps/NewBarkTown_Lab/scripts.pory"

# 521 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnFromEmail:
# 522 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 523 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 524 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 525 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 526 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 527 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 528 "data/maps/NewBarkTown_Lab/scripts.pory"

# 529 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Left:
# 530 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_left
# 531 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 532 "data/maps/NewBarkTown_Lab/scripts.pory"

# 533 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Up:
# 534 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 535 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 536 "data/maps/NewBarkTown_Lab/scripts.pory"

# 537 "data/maps/NewBarkTown_Lab/scripts.pory"

# 538 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
# 539 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 540 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 541 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 542 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 543 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 544 "data/maps/NewBarkTown_Lab/scripts.pory"

# 545 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1LeavePlayer:
# 546 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 547 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 548 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 549 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 550 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 551 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 552 "data/maps/NewBarkTown_Lab/scripts.pory"

# 553 "data/maps/NewBarkTown_Lab/scripts.pory"
NeBarkTownLab_Movement_PlayerWalkToCop:
# 554 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 555 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 556 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 557 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 558 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 559 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 560 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 561 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 562 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 563 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_right
# 564 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 565 "data/maps/NewBarkTown_Lab/scripts.pory"

# 566 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Right:
# 567 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_right
# 568 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 569 "data/maps/NewBarkTown_Lab/scripts.pory"

# 570 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Down:
# 571 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_down
# 572 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 573 "data/maps/NewBarkTown_Lab/scripts.pory"

# 574 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CopLeaves:
# 575 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 576 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 577 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 578 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 579 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 580 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 581 "data/maps/NewBarkTown_Lab/scripts.pory"

# 582 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_PlayerStepsToElm:
# 583 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 584 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 585 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 586 "data/maps/NewBarkTown_Lab/scripts.pory"

# 587 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepBack:
# 588 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock_facing_direction
# 589 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 590 "data/maps/NewBarkTown_Lab/scripts.pory"
	unlock_facing_direction
# 591 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 592 "data/maps/NewBarkTown_Lab/scripts.pory"

# 593 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepForward:
# 594 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 595 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 596 "data/maps/NewBarkTown_Lab/scripts.pory"

# 597 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShouldntTouch:
# 598 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Probably shouldn't touch!$"
# 599 "data/maps/NewBarkTown_Lab/scripts.pory"

# 600 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmIntro:
# 601 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 602 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I needed to ask you a favor.\p"
# 603 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm conducting new POKéMON\n"
# 604 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research right now. I was\l"
# 605 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "wondering if you could help\l"
# 606 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "me with it, {PLAYER}.\p"
# 607 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You see…\p"
# 608 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm writing a paper that I\n"
# 609 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "want to present at a conference.\p"
# 610 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But there are some things I\n"
# 611 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "don't quite understand yet.\p"
# 612 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "So!\p"
# 613 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'd like you to raise a\n"
# 614 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON that I recently caught.$"
# 615 "data/maps/NewBarkTown_Lab/scripts.pory"

# 616 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAccepted:
# 617 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 618 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You're a great help!$"
# 619 "data/maps/NewBarkTown_Lab/scripts.pory"

# 620 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmRefused:
# 621 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Please, I need your\n"
# 622 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "help!$"
# 623 "data/maps/NewBarkTown_Lab/scripts.pory"

# 624 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
# 625 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When I announce my findings,\n"
# 626 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm sure we'll delve deeper\p"
# 627 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "into the many mysteries of\n"
# 628 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON.\p"
# 629 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You can count on it!$"
# 630 "data/maps/NewBarkTown_Lab/scripts.pory"

# 631 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGotAnEmail:
# 632 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, hey! I got an e-mail!\p"
# 633 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "… … … … … … … …\n"
# 634 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hm… Uh-huh…\p"
# 635 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Okay…$"
# 636 "data/maps/NewBarkTown_Lab/scripts.pory"

# 637 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
# 638 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hey, listen.\p"
# 639 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have an acquaintance called\n"
# 640 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. POKéMON.\p"
# 641 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He keeps finding weird things and\n"
# 642 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "raving about his discoveries.\p"
# 643 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Anyway, I just got an e-mail\n"
# 644 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from him saying that this\l"
# 645 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "time it's real.\p"
# 646 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It is intriguing, but we're\n"
# 647 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "busy with our POKéMON research...\p"
# 648 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wait!\n"
# 649 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know!\p"
# 650 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, can you go in our\n"
# 651 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "place?$"
# 652 "data/maps/NewBarkTown_Lab/scripts.pory"

# 653 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
# 654 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to raise one of\n"
# 655 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the POKéMON contained in this case.\p"
# 656 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You'll be that POKéMON's\n"
# 657 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "first partner, {PLAYER}!\p"
# 658 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Go on. Pick one!$"
# 659 "data/maps/NewBarkTown_Lab/scripts.pory"

# 660 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWhereGoing:
# 661 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Wait! Where are you\n"
# 662 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going?$"
# 663 "data/maps/NewBarkTown_Lab/scripts.pory"

# 664 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseCyndaquil:
# 665 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: You'll take Cyndaquil,\n"
# 666 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the fire POKéMON?$"
# 667 "data/maps/NewBarkTown_Lab/scripts.pory"

# 668 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseTotodile:
# 669 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Do you want Totodile,\n"
# 670 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the water POKéMON?$"
# 671 "data/maps/NewBarkTown_Lab/scripts.pory"

# 672 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseChikorita:
# 673 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: So, you like Chikorita,\n"
# 674 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the grass POKéMON?$"
# 675 "data/maps/NewBarkTown_Lab/scripts.pory"

# 676 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_DidntChooseStarter:
# 677 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Think it over carefully.\p"
# 678 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Your partner is important.$"
# 679 "data/maps/NewBarkTown_Lab/scripts.pory"

# 680 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChoseStarter:
# 681 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: I think that's a great\n"
# 682 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON too!$"
# 683 "data/maps/NewBarkTown_Lab/scripts.pory"

# 684 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ReceivedStarter:
# 685 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 686 "data/maps/NewBarkTown_Lab/scripts.pory"

# 687 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Nickname:
# 688 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Would you like to give your\n"
# 689 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{STR_VAR_1} a nickname?$"
# 690 "data/maps/NewBarkTown_Lab/scripts.pory"

# 691 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections1:
# 692 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. POKéMON lives a little bit\n"
# 693 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "beyond Cherrygrove, the next\l"
# 694 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "city over.\p"
# 695 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's almost a direct route\n"
# 696 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "there, so you can't miss it.\p"
# 697 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But just in case, you have my\n"
# 698 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "phone number. Call me if\l"
# 699 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up!$"
# 700 "data/maps/NewBarkTown_Lab/scripts.pory"

# 701 "data/maps/NewBarkTown_Lab/scripts.pory"

# 702 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
# 703 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild POKéMON appears,\n"
# 704 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "let your POKéMON battle it!$"
# 705 "data/maps/NewBarkTown_Lab/scripts.pory"

# 706 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections2:
# 707 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild POKéMON appears, let\n"
# 708 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "your POKéMON battle it!\p"
# 709 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If your POKéMON is hurt, you\n"
# 710 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "should heal it with the machine\l"
# 711 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to my right, or at the POKéCENTER.\p"
# 712 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm counting on you!$"
# 713 "data/maps/NewBarkTown_Lab/scripts.pory"

# 714 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_GotElmsNumber:
# 715 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} got Elm's phone\n"
# 716 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "number.$"
# 717 "data/maps/NewBarkTown_Lab/scripts.pory"

# 718 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
# 719 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. POKéMON goes everywhere and\n"
# 720 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "finds rarities.\p"
# 721 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Too bad they're just rare and\n"
# 722 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "not very useful…$"
# 723 "data/maps/NewBarkTown_Lab/scripts.pory"

# 724 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmPokeBall:
# 725 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It contains POKéMON caught\n"
# 726 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "by Prof.Elm.$"
# 727 "data/maps/NewBarkTown_Lab/scripts.pory"

# 728 "data/maps/NewBarkTown_Lab/scripts.pory"
@THEFT================================================================================
# 729 "data/maps/NewBarkTown_Lab/scripts.pory"

# 730 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft1:
# 731 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, this is terrible…\p"
# 732 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, yes, what was Mr. POKéMON's\n"
# 733 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "big discovery?$"
# 734 "data/maps/NewBarkTown_Lab/scripts.pory"

# 735 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft2:
# 736 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} handed the Mystery Egg\n"
# 737 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to Prof.Elm.$"
# 738 "data/maps/NewBarkTown_Lab/scripts.pory"

# 739 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft3:
# 740 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: This?$"
# 741 "data/maps/NewBarkTown_Lab/scripts.pory"

# 742 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft4:
# 743 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Is it a POKéMON Egg?\p"
# 744 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If it is, it is a great\n"
# 745 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "discovery!\p"
# 746 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: What?!?\p"
# 747 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof.Oak gave you a POKéDEX?\p"
# 748 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, is that true?\n"
# 749 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Th-that's incredible!\p"
# 750 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He is superb at seeing the\n"
# 751 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "potential of people as trainers.\p"
# 752 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, {PLAYER}. You may have what\n"
# 753 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "it takes to become the Champion.\p"
# 754 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You seem to be getting on\n"
# 755 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "great with POKéMON too.\p"
# 756 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should take the POKéMON\n"
# 757 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Gym challenge.\p"
# 758 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The closest Gym would be the\n"
# 759 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "one in Violet City.\p"
# 760 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…{PLAYER}. The road to the\n"
# 761 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "championship will be a long one.\p"
# 762 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Before you leave, make sure\n"
# 763 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that you talk to your mom.$"
# 764 "data/maps/NewBarkTown_Lab/scripts.pory"

# 765 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmStudyingEgg:
# 766 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Don't give up!\n"
# 767 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'll call if I learn anything\l"
# 768 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about that Egg!$"
# 769 "data/maps/NewBarkTown_Lab/scripts.pory"

# 770 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideHasEgg:
# 771 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}? Didn't you meet\n"
# 772 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "my assistant?\p"
# 773 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He should have met you with\n"
# 774 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Egg at Violet City's\p"
# 775 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON Center.\p"
# 776 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You must have just missed him.\n"
# 777 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Try to catch him there.$"
# 778 "data/maps/NewBarkTown_Lab/scripts.pory"

# 779 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
# 780 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hey, has that Egg changed\n"
# 781 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "any?$"
# 782 "data/maps/NewBarkTown_Lab/scripts.pory"

# 783 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
# 784 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}? I thought the Egg\n"
# 785 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "hatched.\p"
# 786 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Where is the POKéMON?$"
# 787 "data/maps/NewBarkTown_Lab/scripts.pory"

# 788 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi1:
# 789 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, you look great!$"
# 790 "data/maps/NewBarkTown_Lab/scripts.pory"

# 791 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi2:
# 792 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What? That POKéMON!?!$"
# 793 "data/maps/NewBarkTown_Lab/scripts.pory"

# 794 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi3:
# 795 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Egg hatched! So, POKéMON\n"
# 796 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are born from Eggs…\p"
# 797 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "No, perhaps not all POKéMON\n"
# 798 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are.\p"
# 799 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, there's still a lot of\n"
# 800 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research to be done.$"
# 801 "data/maps/NewBarkTown_Lab/scripts.pory"

# 802 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
# 803 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}! You're helping\n"
# 804 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "unravel POKéMON mysteries for us!\p"
# 805 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to have this as a\n"
# 806 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "token of our appreciation.$"
# 807 "data/maps/NewBarkTown_Lab/scripts.pory"

# 808 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
# 809 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That's a Shiny Stone.\p"
# 810 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Some species of POKéMON evolve\n"
# 811 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "when they grow to certain levels.\p"
# 812 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A Togetic will evolve\n"
# 813 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "with this one.$"
# 814 "data/maps/NewBarkTown_Lab/scripts.pory"

# 815 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmCallYou:
# 816 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, I'll call you if\n"
# 817 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up.$"
# 818 "data/maps/NewBarkTown_Lab/scripts.pory"

# 819 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAfterTheft:
# 820 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen POKéMON.\p"
# 821 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 822 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a POKéMON raised by a\n"
# 823 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 824 "data/maps/NewBarkTown_Lab/scripts.pory"

# 825 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
# 826 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hi, {PLAYER}!\p"
# 827 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks to you, my research is\n"
# 828 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going great!\p"
# 829 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Take this as a token of my\n"
# 830 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "appreciation.$"
# 831 "data/maps/NewBarkTown_Lab/scripts.pory"

# 832 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
# 833 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Master Ball is the best!\p"
# 834 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the ultimate Ball! It'll\n"
# 835 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "catch any POKéMON without fail.\p"
# 836 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's given only to recognized\n"
# 837 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON researchers.\p"
# 838 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I think you can make much better\n"
# 839 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "use of it than I can, {PLAYER}!$"
# 840 "data/maps/NewBarkTown_Lab/scripts.pory"

# 841 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoGirls:
# 842 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "By the way...\n"
# 843 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A group of beautiful Kimono\l"
# 844 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls were looking for you.\p"
# 845 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They told me they are\n"
# 846 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "waiting for you at the\l" 
# 847 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ecruteak Dance Theater.\p"
# 848 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know you've gone through many\n"
# 849 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "things since that Egg got you\l"
# 850 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "involved in all this...\p"
# 851 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I hope you'll carry through it.$"
# 852 "data/maps/NewBarkTown_Lab/scripts.pory"

# 853 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoWaiting:
# 854 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: The Kimono\n"
# 855 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls are waiting for you at\l"
# 856 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Ecruteak Dance Theater.$"
# 857 "data/maps/NewBarkTown_Lab/scripts.pory"

# 858 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_League:
# 859 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: Hahaha...\n"
# 860 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Good job!\p"
# 861 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That rare Egg has brought you\n"
# 862 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "a lot of trouble, huh?\p"
# 863 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Kimono Girls said something\n"
# 864 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about me?\p"
# 865 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have nothing to do with it.\p"
# 866 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You made your decision and went\n"
# 867 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "through with it.\p"
# 868 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Having done so much, you should\n"
# 869 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "be able to face the League now!\p"
# 870 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should head for Indigo\n"
# 871 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Plateau!\p"
# 872 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Do you know how to get there?\n"
# 873 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Follow Route 27 to Route 26.\p"
# 874 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Once there, go straight north!$"
# 875 "data/maps/NewBarkTown_Lab/scripts.pory"

# 876 "data/maps/NewBarkTown_Lab/scripts.pory"

# 877 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket1:
# 878 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 879 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I called because I have\n"
# 880 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "something for you.\p"
# 881 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "See? It's an S.S.Ticket.\p"
# 882 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can catch POKéMON in\n"
# 883 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Kanto.$"
# 884 "data/maps/NewBarkTown_Lab/scripts.pory"

# 885 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket2:
# 886 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The ship departs from Olivine\n"
# 887 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "City.\p"
# 888 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But you knew that already,\n"
# 889 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}.\p"
# 890 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "After all, you've traveled all\n"
# 891 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "over with your POKéMON.\p"
# 892 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Give my regards to Prof.Oak in\n"
# 893 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Kanto!$"
# 894 "data/maps/NewBarkTown_Lab/scripts.pory"

# 895 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_LabMonEgg:
# 896 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the POKéMON Egg being\n"
# 897 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "studied by Prof.Elm.$"
# 898 "data/maps/NewBarkTown_Lab/scripts.pory"

# 899 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGivePotion:
# 900 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, I want you to have\n"
# 901 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "this for your errand.$"
# 902 "data/maps/NewBarkTown_Lab/scripts.pory"

# 903 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAlwaysBusy:
# 904 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There are only three of us, so\n"
# 905 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "we're always busy.$"
# 906 "data/maps/NewBarkTown_Lab/scripts.pory"

# 907 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideSave:
# 908 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Don't forget to save your game\n"
# 909 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "regularly!\p"
# 910 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Press the Start button, then\n"
# 911 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Save the game!$"
# 912 "data/maps/NewBarkTown_Lab/scripts.pory"

# 913 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideTheftTestimony:
# 914 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There was a loud noise\n"
# 915 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "outside…\p"
# 916 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When we went to look,\n"
# 917 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "someone stole a POKéMON.\p"
# 918 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's unbelievable that anyone\n"
# 919 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "would do that!\p"
# 920 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen POKéMON.\p"
# 921 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 922 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a POKéMON raised by a\n"
# 923 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 924 "data/maps/NewBarkTown_Lab/scripts.pory"

# 925 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGiveBalls:
# 926 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 927 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Use these on your POKéDEX\n"
# 928 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "quest!$"
# 929 "data/maps/NewBarkTown_Lab/scripts.pory"

# 930 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideExplainBalls:
# 931 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "To add to your POKéDEX, you\n"
# 932 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "have to catch POKéMON.\p"
# 933 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Throw POKé Balls at wild\n"
# 934 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "POKéMON to get them.$"
# 935 "data/maps/NewBarkTown_Lab/scripts.pory"

# 936 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer1:
# 937 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I heard a POKéMON was stolen\n"
# 938 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "here…\p"
# 939 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I was just getting some\n"
# 940 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "information from Prof.Elm.\p"
# 941 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Apparently, it was a young\n"
# 942 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "male with long, red hair…\p"
# 943 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What?\p"
# 944 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You battled a trainer like\n"
# 945 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that?\p"
# 946 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Did you happen to get his\n"
# 947 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "name?$"
# 948 "data/maps/NewBarkTown_Lab/scripts.pory"

# 949 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer2:
# 950 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So Silver was his name.\p"
# 951 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 952 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 953 "data/maps/NewBarkTown_Lab/scripts.pory"

# 954 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer3:
# 955 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So {RIVAL} was his name.\p"
# 956 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 957 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 958 "data/maps/NewBarkTown_Lab/scripts.pory"

# 959 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_OfficerNo:
# 960 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Surely you got his name?!$"
# 961 "data/maps/NewBarkTown_Lab/scripts.pory"

# 962 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Elm_CallMe:
# 963 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ah, {PLAYER}!\p"
# 964 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "How's your POKéDEX coming along?\n"
# 965 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm busy now, but call me sometime\l"
# 966 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "and I can check your progress!$"
