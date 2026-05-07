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
    clearflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 195 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_RIVAL_STATE, 2
# 196 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto NewBarkTown_Lab_EventScript_Elm
# 197 "data/maps/NewBarkTown_Lab/scripts.pory"

# 198 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_DeclinedStarter::
# 199 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 200 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
# 201 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 202 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 203 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 204 "data/maps/NewBarkTown_Lab/scripts.pory"

# 205 "data/maps/NewBarkTown_Lab/scripts.pory"

# 206 "data/maps/NewBarkTown_Lab/scripts.pory"

# 207 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_NicknameStarter::
# 208 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 209 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 210 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 211 "data/maps/NewBarkTown_Lab/scripts.pory"

# 212 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemon::
# 213 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
# 214 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 215 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 216 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 217 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 218 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 219 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
# 220 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
# 221 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 222 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 223 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 224 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 225 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 226 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 227 "data/maps/NewBarkTown_Lab/scripts.pory"

# 228 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
# 229 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
# 230 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 231 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 232 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 233 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 234 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 235 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 236 "data/maps/NewBarkTown_Lab/scripts.pory"

# 237 "data/maps/NewBarkTown_Lab/scripts.pory"
CopNewBarkTown_Lab_EventScript_ElmState2::
# 238 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 239 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 240 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
# 241 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 242 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 243 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 244 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 245 "data/maps/NewBarkTown_Lab/scripts.pory"

# 246 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine1::
# 247 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 248 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
# 249 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 250 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 251 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 252 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 253 "data/maps/NewBarkTown_Lab/scripts.pory"

# 254 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine2::
# 255 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 256 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 257 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 258 "data/maps/NewBarkTown_Lab/scripts.pory"

# 259 "data/maps/NewBarkTown_Lab/scripts.pory"

# 260 "data/maps/NewBarkTown_Lab/scripts.pory"

# 261 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
# 262 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 263 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 264 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 265 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 266 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
# 267 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 268 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POTION
# 269 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 270 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 271 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_EXP_SHARE
# 272 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
# 273 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 274 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 275 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 276 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 277 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 278 "data/maps/NewBarkTown_Lab/scripts.pory"

# 279 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceEpisode::
# 280 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 281 "data/maps/NewBarkTown_Lab/scripts.pory"
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
# 282 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_EventScript_hideStarterCase
# 283 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
# 284 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 285 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_LAB_POLICEMAN
# 286 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject LOCALID_COP DIR_WEST
# 287 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
# 288 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceNameRival
# 289 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceYes
# 290 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 291 "data/maps/NewBarkTown_Lab/scripts.pory"

# 292 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNo::
# 293 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
# 294 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
# 295 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
# 296 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 297 "data/maps/NewBarkTown_Lab/scripts.pory"

# 298 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival::
# 299 "data/maps/NewBarkTown_Lab/scripts.pory"
	special NameRival
# 300 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_NAMED_SILVER
# 301 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 302 "data/maps/NewBarkTown_Lab/scripts.pory"

# 303 "data/maps/NewBarkTown_Lab/scripts.pory"

# 304 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival2::
# 305 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 306 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 307 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 308 "data/maps/NewBarkTown_Lab/scripts.pory"

# 309 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes::
# 310 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
# 311 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 312 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes2
# 313 "data/maps/NewBarkTown_Lab/scripts.pory"

# 314 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes3::
# 315 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT @okay, for some reason this script doesn't take effect at all... Added a duplicate after this because it was a workaround.
# 316 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 317 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 318 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 319 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 320 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 321 "data/maps/NewBarkTown_Lab/scripts.pory"

# 322 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 323 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 324 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 325 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 326 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 327 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 328 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 329 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 330 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 331 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 332 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 333 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 334 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 335 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 336 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 337 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 338 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 339 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 340 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 341 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 342 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 343 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 344 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 345 "data/maps/NewBarkTown_Lab/scripts.pory"

# 346 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes2::
# 347 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 348 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 349 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 350 "data/maps/NewBarkTown_Lab/scripts.pory"

# 351 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 352 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 353 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 354 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 355 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 356 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 357 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 358 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 359 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 360 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 361 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 362 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 363 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 364 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 365 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 366 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 367 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 368 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 369 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 370 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 371 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 372 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 373 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 374 "data/maps/NewBarkTown_Lab/scripts.pory"

# 375 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmState5::
# 376 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 377 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 378 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
# 379 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 380 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
# 381 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 382 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 383 "data/maps/NewBarkTown_Lab/scripts.pory"
	
# 384 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmMasterBall::
# 385 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 386 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 387 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
# 388 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_MASTER_BALL
# 389 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
# 390 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 391 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 392 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 393 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
# 394 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 395 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
# 396 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 397 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_GiveStarterMega
# 398 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
# 399 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
# 400 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 401 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 402 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 403 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 404 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 405 "data/maps/NewBarkTown_Lab/scripts.pory"

# 406 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmKimono::
# 407 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 408 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 409 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
# 410 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 411 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 412 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 413 "data/maps/NewBarkTown_Lab/scripts.pory"

# 414 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmLeague::
# 415 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 416 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 417 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
# 418 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 419 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 420 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 421 "data/maps/NewBarkTown_Lab/scripts.pory"

# 422 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmSSTicket::
# 423 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
# 424 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SS_TICKET
# 425 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
# 426 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 427 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 428 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 429 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
# 430 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 431 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 432 "data/maps/NewBarkTown_Lab/scripts.pory"

# 433 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
# 434 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 435 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 436 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 437 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 438 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
# 439 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 440 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 441 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 442 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_BALLS
# 443 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
# 444 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 445 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 446 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 447 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 448 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 449 "data/maps/NewBarkTown_Lab/scripts.pory"

# 450 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
# 451 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
# 452 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 453 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 454 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 455 "data/maps/NewBarkTown_Lab/scripts.pory"

# 456 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
# 457 "data/maps/NewBarkTown_Lab/scripts.pory"
	specialvar VAR_RESULT, CheckTogepi
# 458 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
# 459 "data/maps/NewBarkTown_Lab/scripts.pory"
	return
# 460 "data/maps/NewBarkTown_Lab/scripts.pory"

# 461 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
# 462 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
# 463 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 464 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
# 465 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 466 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
# 467 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 468 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
# 469 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 470 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 471 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 472 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
# 473 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 474 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_SHOWN_ELM_TOGEPI
# 475 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 476 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 477 "data/maps/NewBarkTown_Lab/scripts.pory"

# 478 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_CallMe::
# 479 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
# 480 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 481 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 482 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 483 "data/maps/NewBarkTown_Lab/scripts.pory"

# 484 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkRight:
# 485 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 486 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 487 "data/maps/NewBarkTown_Lab/scripts.pory"

# 488 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkLeft:
# 489 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 490 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 491 "data/maps/NewBarkTown_Lab/scripts.pory"

# 492 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_LabMovement_WalkToElm:
# 493 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 494 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 495 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 496 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 497 "data/maps/NewBarkTown_Lab/scripts.pory"

# 498 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnPlayer:
# 499 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 500 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 501 "data/maps/NewBarkTown_Lab/scripts.pory"

# 502 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmail:
# 503 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 504 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 505 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 506 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 507 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 508 "data/maps/NewBarkTown_Lab/scripts.pory"

# 509 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmailSlow:
# 510 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 511 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 512 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 513 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 514 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 515 "data/maps/NewBarkTown_Lab/scripts.pory"

# 516 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_GotoComputerSafe:
# 517 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 518 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 519 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 520 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 521 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 522 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 523 "data/maps/NewBarkTown_Lab/scripts.pory"

# 524 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnFromEmail:
# 525 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 526 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 527 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 528 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 529 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 530 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 531 "data/maps/NewBarkTown_Lab/scripts.pory"

# 532 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Left:
# 533 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_left
# 534 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 535 "data/maps/NewBarkTown_Lab/scripts.pory"

# 536 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Up:
# 537 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 538 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 539 "data/maps/NewBarkTown_Lab/scripts.pory"

# 540 "data/maps/NewBarkTown_Lab/scripts.pory"

# 541 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
# 542 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 543 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 544 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 545 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 546 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 547 "data/maps/NewBarkTown_Lab/scripts.pory"

# 548 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1LeavePlayer:
# 549 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 550 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 551 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 552 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 553 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 554 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 555 "data/maps/NewBarkTown_Lab/scripts.pory"

# 556 "data/maps/NewBarkTown_Lab/scripts.pory"
NeBarkTownLab_Movement_PlayerWalkToCop:
# 557 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 558 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 559 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 560 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 561 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 562 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 563 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 564 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 565 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 566 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_right
# 567 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 568 "data/maps/NewBarkTown_Lab/scripts.pory"

# 569 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Right:
# 570 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_right
# 571 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 572 "data/maps/NewBarkTown_Lab/scripts.pory"

# 573 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Down:
# 574 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_down
# 575 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 576 "data/maps/NewBarkTown_Lab/scripts.pory"

# 577 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CopLeaves:
# 578 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 579 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 580 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 581 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 582 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 583 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 584 "data/maps/NewBarkTown_Lab/scripts.pory"

# 585 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_PlayerStepsToElm:
# 586 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 587 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 588 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 589 "data/maps/NewBarkTown_Lab/scripts.pory"

# 590 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepBack:
# 591 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock_facing_direction
# 592 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 593 "data/maps/NewBarkTown_Lab/scripts.pory"
	unlock_facing_direction
# 594 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 595 "data/maps/NewBarkTown_Lab/scripts.pory"

# 596 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepForward:
# 597 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 598 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 599 "data/maps/NewBarkTown_Lab/scripts.pory"

# 600 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShouldntTouch:
# 601 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Probably shouldn't touch!$"
# 602 "data/maps/NewBarkTown_Lab/scripts.pory"

# 603 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmIntro:
# 604 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 605 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I needed to ask you a favor.\p"
# 606 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm conducting new Pokémon\n"
# 607 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research right now. I was\l"
# 608 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "wondering if you could help\l"
# 609 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "me with it, {PLAYER}.\p"
# 610 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You see…\p"
# 611 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm writing a paper that I\n"
# 612 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "want to present at a conference.\p"
# 613 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But there are some things I\n"
# 614 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "don't quite understand yet.\p"
# 615 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "So!\p"
# 616 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'd like you to raise a\n"
# 617 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon that I recently caught.$"
# 618 "data/maps/NewBarkTown_Lab/scripts.pory"

# 619 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAccepted:
# 620 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 621 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You're a great help!$"
# 622 "data/maps/NewBarkTown_Lab/scripts.pory"

# 623 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmRefused:
# 624 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Please, I need your\n"
# 625 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "help!$"
# 626 "data/maps/NewBarkTown_Lab/scripts.pory"

# 627 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
# 628 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When I announce my findings,\n"
# 629 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm sure we'll delve deeper\p"
# 630 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "into the many mysteries of\n"
# 631 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon.\p"
# 632 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You can count on it!$"
# 633 "data/maps/NewBarkTown_Lab/scripts.pory"

# 634 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGotAnEmail:
# 635 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, hey! I got an e-mail!\p"
# 636 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "… … … … … … … …\n"
# 637 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hm… Uh-huh…\p"
# 638 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Okay…$"
# 639 "data/maps/NewBarkTown_Lab/scripts.pory"

# 640 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
# 641 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hey, listen.\p"
# 642 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have an acquaintance called\n"
# 643 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon.\p"
# 644 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He keeps finding weird things and\n"
# 645 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "raving about his discoveries.\p"
# 646 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Anyway, I just got an e-mail\n"
# 647 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from him saying that this\l"
# 648 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "time it's real.\p"
# 649 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It is intriguing, but we're\n"
# 650 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "busy with our Pokémon research...\p"
# 651 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wait!\n"
# 652 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know!\p"
# 653 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, can you go in our\n"
# 654 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "place?$"
# 655 "data/maps/NewBarkTown_Lab/scripts.pory"

# 656 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
# 657 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to raise one of\n"
# 658 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Pokémon contained in this case.\p"
# 659 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You'll be that Pokémon's\n"
# 660 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "first partner, {PLAYER}!\p"
# 661 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Go on. Pick one!$"
# 662 "data/maps/NewBarkTown_Lab/scripts.pory"

# 663 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWhereGoing:
# 664 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Wait! Where are you\n"
# 665 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going?$"
# 666 "data/maps/NewBarkTown_Lab/scripts.pory"

# 667 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseCyndaquil:
# 668 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: You'll take Cyndaquil,\n"
# 669 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the fire Pokémon?$"
# 670 "data/maps/NewBarkTown_Lab/scripts.pory"

# 671 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseTotodile:
# 672 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Do you want Totodile,\n"
# 673 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the water Pokémon?$"
# 674 "data/maps/NewBarkTown_Lab/scripts.pory"

# 675 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseChikorita:
# 676 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: So, you like Chikorita,\n"
# 677 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the grass Pokémon?$"
# 678 "data/maps/NewBarkTown_Lab/scripts.pory"

# 679 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_DidntChooseStarter:
# 680 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Think it over carefully.\p"
# 681 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Your partner is important.$"
# 682 "data/maps/NewBarkTown_Lab/scripts.pory"

# 683 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChoseStarter:
# 684 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: I think that's a great\n"
# 685 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon too!$"
# 686 "data/maps/NewBarkTown_Lab/scripts.pory"

# 687 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ReceivedStarter:
# 688 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 689 "data/maps/NewBarkTown_Lab/scripts.pory"

# 690 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Nickname:
# 691 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Would you like to give your\n"
# 692 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{STR_VAR_1} a nickname?$"
# 693 "data/maps/NewBarkTown_Lab/scripts.pory"

# 694 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections1:
# 695 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon lives a little bit\n"
# 696 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "beyond Cherrygrove, the next\l"
# 697 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "city over.\p"
# 698 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's almost a direct route\n"
# 699 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "there, so you can't miss it.\p"
# 700 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But just in case, you have my\n"
# 701 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "phone number. Call me if\l"
# 702 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up!$"
# 703 "data/maps/NewBarkTown_Lab/scripts.pory"

# 704 "data/maps/NewBarkTown_Lab/scripts.pory"

# 705 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
# 706 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears,\n"
# 707 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "let your Pokémon battle it!$"
# 708 "data/maps/NewBarkTown_Lab/scripts.pory"

# 709 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections2:
# 710 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears, let\n"
# 711 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "your Pokémon battle it!\p"
# 712 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If your Pokémon is hurt, you\n"
# 713 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "should heal it with the machine\l"
# 714 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to my right, or at the POKéCENTER.\p"
# 715 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm counting on you!$"
# 716 "data/maps/NewBarkTown_Lab/scripts.pory"

# 717 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_GotElmsNumber:
# 718 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} got Elm's phone\n"
# 719 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "number.$"
# 720 "data/maps/NewBarkTown_Lab/scripts.pory"

# 721 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
# 722 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon goes everywhere and\n"
# 723 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "finds rarities.\p"
# 724 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Too bad they're just rare and\n"
# 725 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "not very useful…$"
# 726 "data/maps/NewBarkTown_Lab/scripts.pory"

# 727 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmPokeBall:
# 728 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It contains Pokémon caught\n"
# 729 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "by Prof.Elm.$"
# 730 "data/maps/NewBarkTown_Lab/scripts.pory"

# 731 "data/maps/NewBarkTown_Lab/scripts.pory"
@THEFT================================================================================
# 732 "data/maps/NewBarkTown_Lab/scripts.pory"

# 733 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft1:
# 734 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, this is terrible…\p"
# 735 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, yes, what was Mr. Pokémon's\n"
# 736 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "big discovery?$"
# 737 "data/maps/NewBarkTown_Lab/scripts.pory"

# 738 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft2:
# 739 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} handed the Mystery Egg\n"
# 740 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to Prof.Elm.$"
# 741 "data/maps/NewBarkTown_Lab/scripts.pory"

# 742 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft3:
# 743 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: This?$"
# 744 "data/maps/NewBarkTown_Lab/scripts.pory"

# 745 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft4:
# 746 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Is it a Pokémon Egg?\p"
# 747 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If it is, it is a great\n"
# 748 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "discovery!\p"
# 749 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: What?!?\p"
# 750 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof.Oak gave you a POKéDEX?\p"
# 751 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, is that true?\n"
# 752 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Th-that's incredible!\p"
# 753 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He is superb at seeing the\n"
# 754 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "potential of people as trainers.\p"
# 755 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, {PLAYER}. You may have what\n"
# 756 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "it takes to become the Champion.\p"
# 757 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You seem to be getting on\n"
# 758 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "great with Pokémon too.\p"
# 759 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should take the Pokémon\n"
# 760 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Gym challenge.\p"
# 761 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The closest Gym would be the\n"
# 762 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "one in Violet City.\p"
# 763 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…{PLAYER}. The road to the\n"
# 764 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "championship will be a long one.\p"
# 765 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Before you leave, make sure\n"
# 766 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that you talk to your mom.$"
# 767 "data/maps/NewBarkTown_Lab/scripts.pory"

# 768 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmStudyingEgg:
# 769 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Don't give up!\n"
# 770 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'll call if I learn anything\l"
# 771 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about that Egg!$"
# 772 "data/maps/NewBarkTown_Lab/scripts.pory"

# 773 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideHasEgg:
# 774 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}? Didn't you meet\n"
# 775 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "my assistant?\p"
# 776 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He should have met you with\n"
# 777 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Egg at Violet City's\p"
# 778 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon Center.\p"
# 779 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You must have just missed him.\n"
# 780 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Try to catch him there.$"
# 781 "data/maps/NewBarkTown_Lab/scripts.pory"

# 782 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
# 783 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hey, has that Egg changed\n"
# 784 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "any?$"
# 785 "data/maps/NewBarkTown_Lab/scripts.pory"

# 786 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
# 787 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}? I thought the Egg\n"
# 788 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "hatched.\p"
# 789 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Where is the Pokémon?$"
# 790 "data/maps/NewBarkTown_Lab/scripts.pory"

# 791 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi1:
# 792 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, you look great!$"
# 793 "data/maps/NewBarkTown_Lab/scripts.pory"

# 794 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi2:
# 795 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What? That Pokémon!?!$"
# 796 "data/maps/NewBarkTown_Lab/scripts.pory"

# 797 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi3:
# 798 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Egg hatched! So, Pokémon\n"
# 799 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are born from Eggs…\p"
# 800 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "No, perhaps not all Pokémon\n"
# 801 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are.\p"
# 802 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, there's still a lot of\n"
# 803 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research to be done.$"
# 804 "data/maps/NewBarkTown_Lab/scripts.pory"

# 805 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
# 806 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}! You're helping\n"
# 807 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "unravel Pokémon mysteries for us!\p"
# 808 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to have this as a\n"
# 809 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "token of our appreciation.$"
# 810 "data/maps/NewBarkTown_Lab/scripts.pory"

# 811 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
# 812 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That's a Shiny Stone.\p"
# 813 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Some species of Pokémon evolve\n"
# 814 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "when they grow to certain levels.\p"
# 815 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A Togetic will evolve\n"
# 816 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "with this one.$"
# 817 "data/maps/NewBarkTown_Lab/scripts.pory"

# 818 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmCallYou:
# 819 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, I'll call you if\n"
# 820 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up.$"
# 821 "data/maps/NewBarkTown_Lab/scripts.pory"

# 822 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAfterTheft:
# 823 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 824 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 825 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 826 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 827 "data/maps/NewBarkTown_Lab/scripts.pory"

# 828 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
# 829 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hi, {PLAYER}!\p"
# 830 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks to you, my research is\n"
# 831 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going great!\p"
# 832 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Take this as a token of my\n"
# 833 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "appreciation.$"
# 834 "data/maps/NewBarkTown_Lab/scripts.pory"

# 835 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
# 836 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Master Ball is the best!\p"
# 837 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the ultimate Ball! It'll\n"
# 838 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "catch any Pokémon without fail.\p"
# 839 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's given only to recognized\n"
# 840 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon researchers.\p"
# 841 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I think you can make much better\n"
# 842 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "use of it than I can, {PLAYER}!$"
# 843 "data/maps/NewBarkTown_Lab/scripts.pory"

# 844 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoGirls:
# 845 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "By the way...\n"
# 846 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A group of beautiful Kimono\l"
# 847 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls were looking for you.\p"
# 848 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They told me they are\n"
# 849 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "waiting for you at the\l" 
# 850 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ecruteak Dance Theater.\p"
# 851 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know you've gone through many\n"
# 852 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "things since that Egg got you\l"
# 853 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "involved in all this...\p"
# 854 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I hope you'll carry through it.$"
# 855 "data/maps/NewBarkTown_Lab/scripts.pory"

# 856 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoWaiting:
# 857 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: The Kimono\n"
# 858 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls are waiting for you at\l"
# 859 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Ecruteak Dance Theater.$"
# 860 "data/maps/NewBarkTown_Lab/scripts.pory"

# 861 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_League:
# 862 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: Hahaha...\n"
# 863 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Good job!\p"
# 864 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That rare Egg has brought you\n"
# 865 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "a lot of trouble, huh?\p"
# 866 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Kimono Girls said something\n"
# 867 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about me?\p"
# 868 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have nothing to do with it.\p"
# 869 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You made your decision and went\n"
# 870 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "through with it.\p"
# 871 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Having done so much, you should\n"
# 872 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "be able to face the League now!\p"
# 873 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should head for Indigo\n"
# 874 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Plateau!\p"
# 875 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Do you know how to get there?\n"
# 876 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Follow Route 27 to Route 26.\p"
# 877 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Once there, go straight north!$"
# 878 "data/maps/NewBarkTown_Lab/scripts.pory"

# 879 "data/maps/NewBarkTown_Lab/scripts.pory"

# 880 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket1:
# 881 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 882 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I called because I have\n"
# 883 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "something for you.\p"
# 884 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "See? It's an S.S.Ticket.\p"
# 885 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can catch Pokémon in\n"
# 886 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Kanto.$"
# 887 "data/maps/NewBarkTown_Lab/scripts.pory"

# 888 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket2:
# 889 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The ship departs from Olivine\n"
# 890 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "City.\p"
# 891 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But you knew that already,\n"
# 892 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}.\p"
# 893 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "After all, you've traveled all\n"
# 894 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "over with your Pokémon.\p"
# 895 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Give my regards to Prof.Oak in\n"
# 896 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Kanto!$"
# 897 "data/maps/NewBarkTown_Lab/scripts.pory"

# 898 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_LabMonEgg:
# 899 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the Pokémon Egg being\n"
# 900 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "studied by Prof.Elm.$"
# 901 "data/maps/NewBarkTown_Lab/scripts.pory"

# 902 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGivePotion:
# 903 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, I want you to have\n"
# 904 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "this for your errand.$"
# 905 "data/maps/NewBarkTown_Lab/scripts.pory"

# 906 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAlwaysBusy:
# 907 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There are only three of us, so\n"
# 908 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "we're always busy.$"
# 909 "data/maps/NewBarkTown_Lab/scripts.pory"

# 910 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideSave:
# 911 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Don't forget to save your game\n"
# 912 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "regularly!\p"
# 913 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Press the Start button, then\n"
# 914 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Save the game!$"
# 915 "data/maps/NewBarkTown_Lab/scripts.pory"

# 916 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideTheftTestimony:
# 917 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There was a loud noise\n"
# 918 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "outside…\p"
# 919 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When we went to look,\n"
# 920 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "someone stole a Pokémon.\p"
# 921 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's unbelievable that anyone\n"
# 922 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "would do that!\p"
# 923 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 924 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 925 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 926 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 927 "data/maps/NewBarkTown_Lab/scripts.pory"

# 928 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGiveBalls:
# 929 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 930 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Use these on your POKéDEX\n"
# 931 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "quest!$"
# 932 "data/maps/NewBarkTown_Lab/scripts.pory"

# 933 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideExplainBalls:
# 934 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "To add to your POKéDEX, you\n"
# 935 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "have to catch Pokémon.\p"
# 936 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Throw POKé Balls at wild\n"
# 937 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon to get them.$"
# 938 "data/maps/NewBarkTown_Lab/scripts.pory"

# 939 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer1:
# 940 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I heard a Pokémon was stolen\n"
# 941 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "here…\p"
# 942 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I was just getting some\n"
# 943 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "information from Prof.Elm.\p"
# 944 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Apparently, it was a young\n"
# 945 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "male with long, red hair…\p"
# 946 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What?\p"
# 947 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You battled a trainer like\n"
# 948 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that?\p"
# 949 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Did you happen to get his\n"
# 950 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "name?$"
# 951 "data/maps/NewBarkTown_Lab/scripts.pory"

# 952 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer2:
# 953 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So Silver was his name.\p"
# 954 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 955 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 956 "data/maps/NewBarkTown_Lab/scripts.pory"

# 957 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer3:
# 958 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So {RIVAL} was his name.\p"
# 959 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 960 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 961 "data/maps/NewBarkTown_Lab/scripts.pory"

# 962 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_OfficerNo:
# 963 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Surely you got his name?!$"
# 964 "data/maps/NewBarkTown_Lab/scripts.pory"

# 965 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Elm_CallMe:
# 966 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ah, {PLAYER}!\p"
# 967 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "How's your POKéDEX coming along?\n"
# 968 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm busy now, but call me sometime\l"
# 969 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "and I can check your progress!$"

NewBarkTown_Lab_GiveStarterMega::
# 973 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_0
# 977 "data/maps/NewBarkTown_Lab/scripts.pory"
	special GetStarterMegaStone
# 978 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem VAR_RESULT, 1
# 979 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_1
	return


NewBarkTown_Lab_GiveStarterMega_Text_0:
# 973 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, and you got a Mega Ring from \n"
	.string "Prof. Oak?\l"
	.string "Then I think you are ready to handle\l"
	.string "this.$"

NewBarkTown_Lab_GiveStarterMega_Text_1:
# 979 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's a special Mega Stone, specifically\n"
	.string "for your starter Pokémon. I expect \l"
	.string "great things from you, {PLAYER}!$"
