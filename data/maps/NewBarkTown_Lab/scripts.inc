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
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmPostgameHint
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
	createfieldmugshot MUGSHOT_ELM
# 102 "data/maps/NewBarkTown_Lab/scripts.pory"
	call ElmIntro
# 103 "data/maps/NewBarkTown_Lab/scripts.pory"
	@msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
# 104 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 105 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 106 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 107 "data/maps/NewBarkTown_Lab/scripts.pory"

# 108 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmRefused::
# 109 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 110 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
# 111 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 112 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 113 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 114 "data/maps/NewBarkTown_Lab/scripts.pory"

# 115 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmAccepted::
# 116 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 117 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
# 118 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
# 119 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 120 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PC_LOGIN
# 121 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 122 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 123 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
# 124 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 125 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
# 126 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
# 127 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 128 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 129 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
# 130 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 131 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 132 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
# 133 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 134 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 135 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 136 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 137 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 138 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
# 139 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
# 140 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 141 "data/maps/NewBarkTown_Lab/scripts.pory"

# 142 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmChoosePokemon::
# 143 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 144 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Right
# 145 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 146 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 147 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
# 148 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 149 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 150 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Down
# 151 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 152 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
# 153 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 154 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 155 "data/maps/NewBarkTown_Lab/scripts.pory"

# 156 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
# 157 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 158 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 159 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
# 160 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 161 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 162 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
# 163 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 164 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 165 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 166 "data/maps/NewBarkTown_Lab/scripts.pory"

# 167 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ShouldntTouch::
# 168 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 169 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 170 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 171 "data/maps/NewBarkTown_Lab/scripts.pory"

# 172 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_hideStarterCase::
# 173 "data/maps/NewBarkTown_Lab/scripts.pory"
    setflag FLAG_HIDE_STARTER_CASE
# 174 "data/maps/NewBarkTown_Lab/scripts.pory"
    return
# 175 "data/maps/NewBarkTown_Lab/scripts.pory"

# 176 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase::
# 177 "data/maps/NewBarkTown_Lab/scripts.pory"
    lock
# 178 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
# 179 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_StarterCase_Choice
# 180 "data/maps/NewBarkTown_Lab/scripts.pory"
    msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 181 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 182 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 183 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 184 "data/maps/NewBarkTown_Lab/scripts.pory"

# 185 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase_Choice::
# 186 "data/maps/NewBarkTown_Lab/scripts.pory"
   callnative StartNewPokeballCaseUI
# 187 "data/maps/NewBarkTown_Lab/scripts.pory"
   waitstate
# 188 "data/maps/NewBarkTown_Lab/scripts.pory"
   goto NewBarkTown_Lab_EventScript_ChoseStarter
# 189 "data/maps/NewBarkTown_Lab/scripts.pory"

# 190 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter::
# 191 "data/maps/NewBarkTown_Lab/scripts.pory"
    removeobject VAR_LAST_TALKED
# 192 "data/maps/NewBarkTown_Lab/scripts.pory"
    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
# 193 "data/maps/NewBarkTown_Lab/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 194 "data/maps/NewBarkTown_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
# 195 "data/maps/NewBarkTown_Lab/scripts.pory"
	message NewBarkTown_Lab_Text_ReceivedStarter
# 196 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_STARTER_PICKING_STATE 1
# 197 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitfanfare
# 198 "data/maps/NewBarkTown_Lab/scripts.pory"
    hidemonpic
# 199 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 200 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
# 201 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 202 "data/maps/NewBarkTown_Lab/scripts.pory"
    closemessage
# 203 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 204 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 205 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 206 "data/maps/NewBarkTown_Lab/scripts.pory"

# 207 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter2::
# 208 "data/maps/NewBarkTown_Lab/scripts.pory"
    moveobjecttocoords OBJ_EVENT_ID_PLAYER, 6, 4, DIR_NORTH
# 209 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 210 "data/maps/NewBarkTown_Lab/scripts.pory"
    @applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 211 "data/maps/NewBarkTown_Lab/scripts.pory"
    @waitmovement 0
# 212 "data/maps/NewBarkTown_Lab/scripts.pory"
    clearflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 213 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_RIVAL_STATE, 2
# 214 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_STARTER_PICKING_STATE, 2
# 215 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto NewBarkTown_Lab_EventScript_MrPokemon
# 216 "data/maps/NewBarkTown_Lab/scripts.pory"

# 217 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_DeclinedStarter::
# 218 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 219 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
# 220 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 221 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 222 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 223 "data/maps/NewBarkTown_Lab/scripts.pory"

# 224 "data/maps/NewBarkTown_Lab/scripts.pory"

# 225 "data/maps/NewBarkTown_Lab/scripts.pory"

# 226 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_NicknameStarter::
# 227 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 228 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 229 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 230 "data/maps/NewBarkTown_Lab/scripts.pory"

# 231 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemon::
# 232 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
# 233 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 234 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 235 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 236 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 237 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 238 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 239 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 240 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
# 241 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
# 242 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 243 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 244 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 245 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 246 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 247 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 248 "data/maps/NewBarkTown_Lab/scripts.pory"

# 249 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
# 250 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
# 251 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 252 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 253 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 254 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 255 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 256 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 257 "data/maps/NewBarkTown_Lab/scripts.pory"

# 258 "data/maps/NewBarkTown_Lab/scripts.pory"
CopNewBarkTown_Lab_EventScript_ElmState2::
# 259 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 260 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 261 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
# 262 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 263 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 264 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 265 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 266 "data/maps/NewBarkTown_Lab/scripts.pory"

# 267 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine1::
# 268 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 269 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
# 270 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 271 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 272 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 273 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 274 "data/maps/NewBarkTown_Lab/scripts.pory"

# 275 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine2::
# 276 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 277 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 278 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 279 "data/maps/NewBarkTown_Lab/scripts.pory"

# 280 "data/maps/NewBarkTown_Lab/scripts.pory"

# 281 "data/maps/NewBarkTown_Lab/scripts.pory"

# 282 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
# 283 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 284 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 285 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 286 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 287 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
# 288 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 289 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POTION
# 290 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 291 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
# 292 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 293 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 294 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 295 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 296 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 297 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 298 "data/maps/NewBarkTown_Lab/scripts.pory"

# 299 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceEpisode::
# 300 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 301 "data/maps/NewBarkTown_Lab/scripts.pory"
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
# 302 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_EventScript_hideStarterCase
# 303 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
# 304 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 305 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_LAB_POLICEMAN
# 306 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject LOCALID_COP DIR_WEST
# 307 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
# 308 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceNameRival
# 309 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceYes
# 310 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 311 "data/maps/NewBarkTown_Lab/scripts.pory"

# 312 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNo::
# 313 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
# 314 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
# 315 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
# 316 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 317 "data/maps/NewBarkTown_Lab/scripts.pory"

# 318 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival::
# 319 "data/maps/NewBarkTown_Lab/scripts.pory"
	special NameRival
# 320 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitstate
# 321 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_NAMED_SILVER
# 322 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 323 "data/maps/NewBarkTown_Lab/scripts.pory"

# 324 "data/maps/NewBarkTown_Lab/scripts.pory"

# 325 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival2::
# 326 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 327 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 328 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 329 "data/maps/NewBarkTown_Lab/scripts.pory"

# 330 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes::
# 331 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
# 332 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 333 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes2
# 334 "data/maps/NewBarkTown_Lab/scripts.pory"

# 335 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes3::
# 336 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 337 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 338 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 339 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 340 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 341 "data/maps/NewBarkTown_Lab/scripts.pory"

# 342 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 343 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 344 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 345 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 346 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 347 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 348 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 349 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 350 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 351 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 352 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 353 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 354 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 355 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 356 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 357 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 358 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 359 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 360 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 361 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 362 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 363 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 364 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 365 "data/maps/NewBarkTown_Lab/scripts.pory"

# 366 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes2::
# 367 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 368 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 369 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 370 "data/maps/NewBarkTown_Lab/scripts.pory"

# 371 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 372 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 373 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 374 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 375 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 376 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 377 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 378 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 379 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 380 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 381 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 382 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 383 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 384 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 385 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 386 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 387 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 388 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 389 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 390 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 391 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 392 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 393 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 394 "data/maps/NewBarkTown_Lab/scripts.pory"

# 395 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmState5::
# 396 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 397 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 398 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
# 399 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 400 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
# 401 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 402 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 403 "data/maps/NewBarkTown_Lab/scripts.pory"
	
# 404 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmMasterBall::
# 405 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 406 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 407 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
# 408 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_MASTER_BALL
# 409 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
# 410 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 411 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 412 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 413 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
# 414 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 415 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
# 416 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_GiveStarterMega
# 417 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 418 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
# 419 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
# 420 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 421 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 422 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 423 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 424 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 425 "data/maps/NewBarkTown_Lab/scripts.pory"

# 426 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmKimono::
# 427 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 428 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 429 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
# 430 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 431 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 432 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 433 "data/maps/NewBarkTown_Lab/scripts.pory"

# 434 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmLeague::
# 435 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 436 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 437 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
# 438 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 439 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 440 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 441 "data/maps/NewBarkTown_Lab/scripts.pory"

# 442 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmSSTicket::
# 443 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
# 444 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SS_TICKET
# 445 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
# 446 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 447 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 448 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 449 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
# 450 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 451 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 452 "data/maps/NewBarkTown_Lab/scripts.pory"

# 453 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
# 454 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 455 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 456 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 457 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 458 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
# 459 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 460 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 461 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 462 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_BALLS
# 463 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
# 464 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 465 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 466 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 467 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 468 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 469 "data/maps/NewBarkTown_Lab/scripts.pory"

# 470 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
# 471 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
# 472 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 473 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 474 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 475 "data/maps/NewBarkTown_Lab/scripts.pory"

# 476 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
# 477 "data/maps/NewBarkTown_Lab/scripts.pory"
	specialvar VAR_RESULT, CheckTogepi
# 478 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
# 479 "data/maps/NewBarkTown_Lab/scripts.pory"
	return
# 480 "data/maps/NewBarkTown_Lab/scripts.pory"

# 481 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
# 482 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
# 483 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 484 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
# 485 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 486 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
# 487 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 488 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
# 489 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 490 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 491 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 492 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
# 493 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 494 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_SHOWN_ELM_TOGEPI
# 495 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 496 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 497 "data/maps/NewBarkTown_Lab/scripts.pory"

# 498 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_CallMe::
# 499 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
# 500 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 501 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 502 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 503 "data/maps/NewBarkTown_Lab/scripts.pory"

# 504 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkRight:
# 505 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 506 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 507 "data/maps/NewBarkTown_Lab/scripts.pory"

# 508 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkLeft:
# 509 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 510 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 511 "data/maps/NewBarkTown_Lab/scripts.pory"

# 512 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_LabMovement_WalkToElm:
# 513 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 514 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 515 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 516 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 517 "data/maps/NewBarkTown_Lab/scripts.pory"

# 518 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnPlayer:
# 519 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 520 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 521 "data/maps/NewBarkTown_Lab/scripts.pory"

# 522 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmail:
# 523 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 524 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 525 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 526 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 527 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 528 "data/maps/NewBarkTown_Lab/scripts.pory"

# 529 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmailSlow:
# 530 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 531 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 532 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 533 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 534 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 535 "data/maps/NewBarkTown_Lab/scripts.pory"

# 536 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_GotoComputerSafe:
# 537 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 538 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 539 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 540 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 541 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 542 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 543 "data/maps/NewBarkTown_Lab/scripts.pory"

# 544 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnFromEmail:
# 545 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 546 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 547 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 548 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 549 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 550 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 551 "data/maps/NewBarkTown_Lab/scripts.pory"

# 552 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Left:
# 553 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_left
# 554 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 555 "data/maps/NewBarkTown_Lab/scripts.pory"

# 556 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Up:
# 557 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 558 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 559 "data/maps/NewBarkTown_Lab/scripts.pory"

# 560 "data/maps/NewBarkTown_Lab/scripts.pory"

# 561 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
# 562 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 563 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 564 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 565 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 566 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 567 "data/maps/NewBarkTown_Lab/scripts.pory"

# 568 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1LeavePlayer:
# 569 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 570 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 571 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 572 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 573 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 574 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 575 "data/maps/NewBarkTown_Lab/scripts.pory"

# 576 "data/maps/NewBarkTown_Lab/scripts.pory"
NeBarkTownLab_Movement_PlayerWalkToCop:
# 577 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 578 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 579 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 580 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 581 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 582 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 583 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 584 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 585 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 586 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_right
# 587 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 588 "data/maps/NewBarkTown_Lab/scripts.pory"

# 589 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Right:
# 590 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_right
# 591 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 592 "data/maps/NewBarkTown_Lab/scripts.pory"

# 593 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Down:
# 594 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_down
# 595 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 596 "data/maps/NewBarkTown_Lab/scripts.pory"

# 597 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CopLeaves:
# 598 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 599 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 600 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 601 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 602 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 603 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 604 "data/maps/NewBarkTown_Lab/scripts.pory"

# 605 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_PlayerStepsToElm:
# 606 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 607 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 608 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 609 "data/maps/NewBarkTown_Lab/scripts.pory"

# 610 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepBack:
# 611 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock_facing_direction
# 612 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 613 "data/maps/NewBarkTown_Lab/scripts.pory"
	unlock_facing_direction
# 614 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 615 "data/maps/NewBarkTown_Lab/scripts.pory"

# 616 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepForward:
# 617 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 618 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 619 "data/maps/NewBarkTown_Lab/scripts.pory"

# 620 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShouldntTouch:
# 621 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Probably shouldn't touch!$"
# 622 "data/maps/NewBarkTown_Lab/scripts.pory"

# 623 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAccepted:
# 624 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 625 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You're a great help!$"
# 626 "data/maps/NewBarkTown_Lab/scripts.pory"

# 627 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmRefused:
# 628 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Please, I need your\n"
# 629 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "help!$"
# 630 "data/maps/NewBarkTown_Lab/scripts.pory"

# 631 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
# 632 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When I announce my findings,\n"
# 633 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm sure we'll delve deeper\p"
# 634 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "into the many mysteries of\n"
# 635 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon.\p"
# 636 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You can count on it!$"
# 637 "data/maps/NewBarkTown_Lab/scripts.pory"

# 638 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGotAnEmail:
# 639 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, hey! I got an e-mail!\p"
# 640 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "… … … … … … … …\n"
# 641 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hm… Uh-huh…\p"
# 642 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Okay…$"
# 643 "data/maps/NewBarkTown_Lab/scripts.pory"

# 644 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
# 645 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hey, listen.\p"
# 646 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have an acquaintance called\n"
# 647 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon.\p"
# 648 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He keeps finding weird things and\n"
# 649 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "raving about his discoveries.\p"
# 650 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Anyway, I just got an e-mail\n"
# 651 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from him saying that this\l"
# 652 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "time it's real.\p"
# 653 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It is intriguing, but we're\n"
# 654 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "busy with our Pokémon research...\p"
# 655 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wait!\n"
# 656 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know!\p"
# 657 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, can you go in our\n"
# 658 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "place?$"
# 659 "data/maps/NewBarkTown_Lab/scripts.pory"

# 660 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
# 661 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to raise one of\n"
# 662 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Pokémon contained in this case.\p"
# 663 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You'll be that Pokémon's\n"
# 664 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "first partner, {PLAYER}!\p"
# 665 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Go on. Pick one!$"
# 666 "data/maps/NewBarkTown_Lab/scripts.pory"

# 667 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWhereGoing:
# 668 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Wait! Where are you\n"
# 669 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going?$"
# 670 "data/maps/NewBarkTown_Lab/scripts.pory"

# 671 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseCyndaquil:
# 672 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: You'll take Cyndaquil,\n"
# 673 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the fire Pokémon?$"
# 674 "data/maps/NewBarkTown_Lab/scripts.pory"

# 675 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseTotodile:
# 676 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Do you want Totodile,\n"
# 677 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the water Pokémon?$"
# 678 "data/maps/NewBarkTown_Lab/scripts.pory"

# 679 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseChikorita:
# 680 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: So, you like Chikorita,\n"
# 681 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the grass Pokémon?$"
# 682 "data/maps/NewBarkTown_Lab/scripts.pory"

# 683 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_DidntChooseStarter:
# 684 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Think it over carefully.\p"
# 685 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Your partner is important.$"
# 686 "data/maps/NewBarkTown_Lab/scripts.pory"

# 687 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChoseStarter:
# 688 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: I think that's a great\n"
# 689 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon too!$"
# 690 "data/maps/NewBarkTown_Lab/scripts.pory"

# 691 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ReceivedStarter:
# 692 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 693 "data/maps/NewBarkTown_Lab/scripts.pory"

# 694 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Nickname:
# 695 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Would you like to give your\n"
# 696 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{STR_VAR_1} a nickname?$"
# 697 "data/maps/NewBarkTown_Lab/scripts.pory"

# 698 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections1:
# 699 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon lives a little bit\n"
# 700 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "beyond Cherrygrove, the next\l"
# 701 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "city over.\p"
# 702 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's almost a direct route\n"
# 703 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "there, so you can't miss it.\p"
# 704 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But just in case, you have my\n"
# 705 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "phone number. Call me if\l"
# 706 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up!$"
# 707 "data/maps/NewBarkTown_Lab/scripts.pory"

# 708 "data/maps/NewBarkTown_Lab/scripts.pory"

# 709 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
# 710 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears,\n"
# 711 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "let your Pokémon battle it!$"
# 712 "data/maps/NewBarkTown_Lab/scripts.pory"

# 713 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections2:
# 714 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears, let\n"
# 715 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "your Pokémon battle it!\p"
# 716 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If your Pokémon is hurt, you\n"
# 717 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "should heal it with the machine\l"
# 718 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to my right, or at the Pokémon Center.\p"
# 719 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm counting on you!$"
# 720 "data/maps/NewBarkTown_Lab/scripts.pory"

# 721 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_GotElmsNumber:
# 722 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} got Elm's phone\n"
# 723 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "number.$"
# 724 "data/maps/NewBarkTown_Lab/scripts.pory"

# 725 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
# 726 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon goes everywhere and\n"
# 727 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "finds rarities.\p"
# 728 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Too bad they're just rare and\n"
# 729 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "not very useful…$"
# 730 "data/maps/NewBarkTown_Lab/scripts.pory"

# 731 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmPokeBall:
# 732 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It contains Pokémon caught\n"
# 733 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "by Prof.Elm.$"
# 734 "data/maps/NewBarkTown_Lab/scripts.pory"

# 735 "data/maps/NewBarkTown_Lab/scripts.pory"
@THEFT================================================================================
# 736 "data/maps/NewBarkTown_Lab/scripts.pory"

# 737 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft1:
# 738 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, this is terrible…\p"
# 739 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, yes, what was Mr. Pokémon's\n"
# 740 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "big discovery?$"
# 741 "data/maps/NewBarkTown_Lab/scripts.pory"

# 742 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft2:
# 743 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} handed the Mystery Egg\n"
# 744 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to Prof.Elm.$"
# 745 "data/maps/NewBarkTown_Lab/scripts.pory"

# 746 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft3:
# 747 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: This?$"
# 748 "data/maps/NewBarkTown_Lab/scripts.pory"

# 749 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft4:
# 750 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Is it a Pokémon Egg?\p"
# 751 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If it is, it is a great\n"
# 752 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "discovery!\p"
# 753 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: What?!?\p"
# 754 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof.Oak gave you a Pokédex?\p"
# 755 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, is that true?\n"
# 756 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Th-that's incredible!\p"
# 757 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He is superb at seeing the\n"
# 758 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "potential of people as trainers.\p"
# 759 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, {PLAYER}. You may have what\n"
# 760 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "it takes to become the Champion.\p"
# 761 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You seem to be getting on\n"
# 762 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "great with Pokémon too.\p"
# 763 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should take the Pokémon\n"
# 764 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Gym challenge.\p"
# 765 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The closest Gym would be the\n"
# 766 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "one in Violet City.\p"
# 767 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…{PLAYER}. The road to the\n"
# 768 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "championship will be a long one.\p"
# 769 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Before you leave, make sure\n"
# 770 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that you talk to your mom.$"
# 771 "data/maps/NewBarkTown_Lab/scripts.pory"

# 772 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmStudyingEgg:
# 773 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Don't give up!\n"
# 774 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'll call if I learn anything\l"
# 775 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about that Egg!$"
# 776 "data/maps/NewBarkTown_Lab/scripts.pory"

# 777 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideHasEgg:
# 778 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}? Didn't you meet\n"
# 779 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "my assistant?\p"
# 780 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He should have met you with\n"
# 781 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Egg at Violet City's\p"
# 782 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon Center.\p"
# 783 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You must have just missed him.\n"
# 784 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Try to catch him there.$"
# 785 "data/maps/NewBarkTown_Lab/scripts.pory"

# 786 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
# 787 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hey, has that Egg changed\n"
# 788 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "any?$"
# 789 "data/maps/NewBarkTown_Lab/scripts.pory"

# 790 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
# 791 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}? I thought the Egg\n"
# 792 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "hatched.\p"
# 793 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Where is the Pokémon?$"
# 794 "data/maps/NewBarkTown_Lab/scripts.pory"

# 795 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi1:
# 796 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, you look great!$"
# 797 "data/maps/NewBarkTown_Lab/scripts.pory"

# 798 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi2:
# 799 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What? That Pokémon!?!$"
# 800 "data/maps/NewBarkTown_Lab/scripts.pory"

# 801 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi3:
# 802 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Egg hatched! So, Pokémon\n"
# 803 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are born from Eggs…\p"
# 804 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "No, perhaps not all Pokémon\n"
# 805 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are.\p"
# 806 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, there's still a lot of\n"
# 807 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research to be done.$"
# 808 "data/maps/NewBarkTown_Lab/scripts.pory"

# 809 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
# 810 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}! You're helping\n"
# 811 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "unravel Pokémon mysteries for us!\p"
# 812 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to have this as a\n"
# 813 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "token of our appreciation.$"
# 814 "data/maps/NewBarkTown_Lab/scripts.pory"

# 815 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
# 816 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That's a Shiny Stone.\p"
# 817 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Some species of Pokémon evolve\n"
# 818 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "when they grow to certain levels.\p"
# 819 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A Togetic will evolve\n"
# 820 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "with this one.$"
# 821 "data/maps/NewBarkTown_Lab/scripts.pory"

# 822 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmCallYou:
# 823 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, I'll call you if\n"
# 824 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up.$"
# 825 "data/maps/NewBarkTown_Lab/scripts.pory"

# 826 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAfterTheft:
# 827 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 828 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 829 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 830 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 831 "data/maps/NewBarkTown_Lab/scripts.pory"

# 832 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
# 833 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hi, {PLAYER}!\p"
# 834 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks to you, my research is\n"
# 835 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going great!\p"
# 836 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Take this as a token of my\n"
# 837 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "appreciation.$"
# 838 "data/maps/NewBarkTown_Lab/scripts.pory"

# 839 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
# 840 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Master Ball is the best!\p"
# 841 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the ultimate Ball! It'll\n"
# 842 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "catch any Pokémon without fail.\p"
# 843 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's given only to recognized\n"
# 844 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon researchers.\p"
# 845 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I think you can make much better\n"
# 846 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "use of it than I can, {PLAYER}!$"
# 847 "data/maps/NewBarkTown_Lab/scripts.pory"

# 848 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoGirls:
# 849 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "By the way...\n"
# 850 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A group of beautiful Kimono\l"
# 851 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls were looking for you.\p"
# 852 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They told me they are\n"
# 853 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "waiting for you at the\l" 
# 854 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ecruteak Dance Theater.\p"
# 855 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know you've gone through many\n"
# 856 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "things since that Egg got you\l"
# 857 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "involved in all this...\p"
# 858 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I hope you'll carry through it.$"
# 859 "data/maps/NewBarkTown_Lab/scripts.pory"

# 860 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoWaiting:
# 861 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: The Kimono\n"
# 862 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls are waiting for you at\l"
# 863 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Ecruteak Dance Theater.$"
# 864 "data/maps/NewBarkTown_Lab/scripts.pory"

# 865 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_League:
# 866 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: Hahaha...\n"
# 867 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Good job!\p"
# 868 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That rare Egg has brought you\n"
# 869 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "a lot of trouble, huh?\p"
# 870 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Kimono Girls said something\n"
# 871 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about me?\p"
# 872 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have nothing to do with it.\p"
# 873 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You made your decision and went\n"
# 874 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "through with it.\p"
# 875 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Having done so much, you should\n"
# 876 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "be able to face the League now!\p"
# 877 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should head for Indigo\n"
# 878 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Plateau!\p"
# 879 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Do you know how to get there?\n"
# 880 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Follow Route 27 to Route 26.\p"
# 881 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Once there, go straight north!$"
# 882 "data/maps/NewBarkTown_Lab/scripts.pory"

# 883 "data/maps/NewBarkTown_Lab/scripts.pory"

# 884 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket1:
# 885 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 886 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I called because I have\n"
# 887 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "something for you.\p"
# 888 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "See? It's an S.S.Ticket.\p"
# 889 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can catch Pokémon in\n"
# 890 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Sevii.$"
# 891 "data/maps/NewBarkTown_Lab/scripts.pory"

# 892 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket2:
# 893 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The ship departs from Olivine\n"
# 894 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "City.\p"
# 895 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But you knew that already,\n"
# 896 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}.\p"
# 897 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "After all, you've traveled all\n"
# 898 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "over with your Pokémon.$"
# 899 "data/maps/NewBarkTown_Lab/scripts.pory"

# 900 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_LabMonEgg:
# 901 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the Pokémon Egg being\n"
# 902 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "studied by Prof.Elm.$"
# 903 "data/maps/NewBarkTown_Lab/scripts.pory"

# 904 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGivePotion:
# 905 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, I want you to have\n"
# 906 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "this for your errand.$"
# 907 "data/maps/NewBarkTown_Lab/scripts.pory"

# 908 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAlwaysBusy:
# 909 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There are only three of us, so\n"
# 910 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "we're always busy.$"
# 911 "data/maps/NewBarkTown_Lab/scripts.pory"

# 912 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideSave:
# 913 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Don't forget to save your game\n"
# 914 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "regularly!\p"
# 915 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Press the Start button, then\n"
# 916 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Save the game!$"
# 917 "data/maps/NewBarkTown_Lab/scripts.pory"

# 918 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideTheftTestimony:
# 919 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There was a loud noise\n"
# 920 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "outside…\p"
# 921 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When we went to look,\n"
# 922 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "someone stole a Pokémon.\p"
# 923 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's unbelievable that anyone\n"
# 924 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "would do that!\p"
# 925 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 926 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 927 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 928 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 929 "data/maps/NewBarkTown_Lab/scripts.pory"

# 930 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGiveBalls:
# 931 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 932 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Use these on your Pokédex\n"
# 933 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "quest!$"
# 934 "data/maps/NewBarkTown_Lab/scripts.pory"

# 935 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideExplainBalls:
# 936 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "To add to your Pokédex, you\n"
# 937 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "have to catch Pokémon.\p"
# 938 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Throw Poké Balls at wild\n"
# 939 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon to get them.$"
# 940 "data/maps/NewBarkTown_Lab/scripts.pory"

# 941 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer1:
# 942 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I heard a Pokémon was stolen\n"
# 943 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "here…\p"
# 944 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I was just getting some\n"
# 945 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "information from Prof.Elm.\p"
# 946 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Apparently, it was a young\n"
# 947 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "male with long, red hair…\p"
# 948 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What?\p"
# 949 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You battled a trainer like\n"
# 950 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that?\p"
# 951 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Did you happen to get his\n"
# 952 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "name?$"
# 953 "data/maps/NewBarkTown_Lab/scripts.pory"

# 954 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer2:
# 955 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So Silver was his name.\p"
# 956 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 957 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 958 "data/maps/NewBarkTown_Lab/scripts.pory"

# 959 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer3:
# 960 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So {RIVAL} was his name.\p"
# 961 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 962 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 963 "data/maps/NewBarkTown_Lab/scripts.pory"

# 964 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_OfficerNo:
# 965 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Surely you got his name?!$"
# 966 "data/maps/NewBarkTown_Lab/scripts.pory"

# 967 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Elm_CallMe:
# 968 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ah, {PLAYER}!\p"
# 969 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "How's your Pokédex coming along?\n"
# 970 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm busy now, but call me sometime\l"
# 971 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "and I can check your progress!$"

NewBarkTown_Lab_GiveStarterMega::
# 975 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_0
# 979 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_BONDSTONE, 1
# 980 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_1
	return


NewBarkTown_Lab_EventScript_ElmPostgameHint::
# 987 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0
# 1001 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_1
# 1003 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1004 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1005 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1006 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1007 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1008 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1009 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 1010 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 1011 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2
# 1017 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_POSTGAME_FEATURES
# 1018 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_VICTORYROAD_RIVAL
# 1019 "data/maps/NewBarkTown_Lab/scripts.pory"
	checkplayergender
# 1020 "data/maps/NewBarkTown_Lab/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_Lab_EventScript_ElmPostgameHint_2
# 1029 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4
NewBarkTown_Lab_EventScript_ElmPostgameHint_1:
# 1037 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5
# 1039 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_GUARD
# 1040 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ALLOW_SOUTH_JOHTO_PASS
# 1041 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 11
# 1042 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
	end

NewBarkTown_Lab_EventScript_ElmPostgameHint_2:
# 1021 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3
	goto NewBarkTown_Lab_EventScript_ElmPostgameHint_1


ElmIntro::
# 1047 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox ElmIntro_Text_0, MSGBOX_YESNO
	return


NewBarkTown_Lab_GiveStarterMega_Text_0:
# 975 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, and you got a Mega Ring from \n"
	.string "Prof. Oak?\l"
	.string "Then I think you are ready to handle\l"
	.string "this.$"

NewBarkTown_Lab_GiveStarterMega_Text_1:
# 980 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's a special Mega Stone, specifically\n"
	.string "for your starter Pokémon. I expect \l"
	.string "great things from you, {PLAYER}!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0:
# 987 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\n"
	.string "I called because I heard that the way \l"
	.string "to the Johto Archipelago is open! \p"
	.string "I hear strong trainers\n"
	.string "are gathering in there, and many rare\l"
	.string "Pokémon have been spotted!\p"
	.string "You can get there if you surf south\n"
	.string "from Route 33. But you of course knew\l"
	.string "that already.\p"
	.string "After all, you've travelled all over\n"
	.string "with your Pokémon.$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_1:
# 1001 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But first, let me upgrade your Pokédex\n"
	.string "with a new feature!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2:
# 1011 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can view abilities of the\n"
	.string "opposing Pokémon with the L-button\l"
	.string "in battle! \p"
	.string "That will surely be handy as the\n"
	.string "battles get tougher!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3:
# 1021 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Crystal went to train\n"
	.string "in Mt. Silver. \p"
	.string "She looked really tired\n"
	.string "the last time I saw her though... \p"
	.string "Could you check on her at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4:
# 1029 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Gold went to train\n"
	.string "in Mt. Silver. \p"
	.string "He looked really tired\n"
	.string "the last time I saw him thoughö...\p"
	.string "Could you check on him at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5:
# 1037 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I asked from the League to let you\n"
	.string "pass since you've the new Champion.$"

ElmIntro_Text_0:
# 1047 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting new Pokémon\n"
	.string "research right now. \p"
	.string "I was wondering if you could help\n"
	.string "me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I\n"
	.string "want to present at a conference.\p"
	.string "But there are some things I\n"
	.string "don't quite understand yet.\p"
	.string "So!\p"
	.string "I'd like you to raise a\n"
	.string "Pokémon that I recently caught.$"
