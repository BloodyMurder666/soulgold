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
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
# 103 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 104 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 105 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 106 "data/maps/NewBarkTown_Lab/scripts.pory"

# 107 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmRefused::
# 108 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 109 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
# 110 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
# 111 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
# 112 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 113 "data/maps/NewBarkTown_Lab/scripts.pory"

# 114 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmAccepted::
# 115 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 116 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
# 117 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
# 118 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 119 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PC_LOGIN
# 120 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 121 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 122 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
# 123 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 124 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
# 125 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
# 126 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 127 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 128 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
# 129 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 130 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 131 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
# 132 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 133 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 134 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 135 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 30
# 136 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 137 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
# 138 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
# 139 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 140 "data/maps/NewBarkTown_Lab/scripts.pory"

# 141 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmChoosePokemon::
# 142 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 143 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Right
# 144 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 145 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 146 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
# 147 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 148 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 149 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement LOCALID_ELM, NewBarkTownLab_Movement_Elm_Down
# 150 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 151 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
# 152 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 153 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 154 "data/maps/NewBarkTown_Lab/scripts.pory"

# 155 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
# 156 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 157 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 158 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
# 159 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 160 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 161 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
# 162 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 163 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 164 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 165 "data/maps/NewBarkTown_Lab/scripts.pory"

# 166 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ShouldntTouch::
# 167 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 168 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 169 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 170 "data/maps/NewBarkTown_Lab/scripts.pory"

# 171 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_hideStarterCase::
# 172 "data/maps/NewBarkTown_Lab/scripts.pory"
    setflag FLAG_HIDE_STARTER_CASE
# 173 "data/maps/NewBarkTown_Lab/scripts.pory"
    return
# 174 "data/maps/NewBarkTown_Lab/scripts.pory"

# 175 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase::
# 176 "data/maps/NewBarkTown_Lab/scripts.pory"
    lock
# 177 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
# 178 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_StarterCase_Choice
# 179 "data/maps/NewBarkTown_Lab/scripts.pory"
    msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 180 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 181 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 182 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 183 "data/maps/NewBarkTown_Lab/scripts.pory"

# 184 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase_Choice::
# 185 "data/maps/NewBarkTown_Lab/scripts.pory"
   callnative StartNewPokeballCaseUI
# 186 "data/maps/NewBarkTown_Lab/scripts.pory"
   waitstate
# 187 "data/maps/NewBarkTown_Lab/scripts.pory"
   goto NewBarkTown_Lab_EventScript_ChoseStarter
# 188 "data/maps/NewBarkTown_Lab/scripts.pory"

# 189 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter::
# 190 "data/maps/NewBarkTown_Lab/scripts.pory"
    removeobject VAR_LAST_TALKED
# 191 "data/maps/NewBarkTown_Lab/scripts.pory"
    showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
# 192 "data/maps/NewBarkTown_Lab/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 193 "data/maps/NewBarkTown_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
# 194 "data/maps/NewBarkTown_Lab/scripts.pory"
	message NewBarkTown_Lab_Text_ReceivedStarter
# 195 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitfanfare
# 196 "data/maps/NewBarkTown_Lab/scripts.pory"
    hidemonpic
# 197 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 198 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
# 199 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 200 "data/maps/NewBarkTown_Lab/scripts.pory"
    closemessage
# 201 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 202 "data/maps/NewBarkTown_Lab/scripts.pory"
    moveobjecttocoords OBJ_EVENT_ID_PLAYER, 6, 4, DIR_NONE
# 203 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 204 "data/maps/NewBarkTown_Lab/scripts.pory"
    applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 205 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 206 "data/maps/NewBarkTown_Lab/scripts.pory"
    clearflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 207 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_RIVAL_STATE, 2
# 208 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto NewBarkTown_Lab_EventScript_Elm
# 209 "data/maps/NewBarkTown_Lab/scripts.pory"

# 210 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_DeclinedStarter::
# 211 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 212 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
# 213 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 214 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 215 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 216 "data/maps/NewBarkTown_Lab/scripts.pory"

# 217 "data/maps/NewBarkTown_Lab/scripts.pory"

# 218 "data/maps/NewBarkTown_Lab/scripts.pory"

# 219 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_NicknameStarter::
# 220 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 221 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 222 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 223 "data/maps/NewBarkTown_Lab/scripts.pory"

# 224 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemon::
# 225 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
# 226 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 227 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 228 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 229 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 230 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 231 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 232 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 233 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
# 234 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
# 235 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 236 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 237 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 238 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 239 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 240 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 241 "data/maps/NewBarkTown_Lab/scripts.pory"

# 242 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
# 243 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
# 244 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 245 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 246 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 247 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 248 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 249 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 250 "data/maps/NewBarkTown_Lab/scripts.pory"

# 251 "data/maps/NewBarkTown_Lab/scripts.pory"
CopNewBarkTown_Lab_EventScript_ElmState2::
# 252 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 253 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 254 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
# 255 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 256 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 257 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 258 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 259 "data/maps/NewBarkTown_Lab/scripts.pory"

# 260 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine1::
# 261 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 262 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
# 263 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 264 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 265 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 266 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 267 "data/maps/NewBarkTown_Lab/scripts.pory"

# 268 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine2::
# 269 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 270 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 271 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 272 "data/maps/NewBarkTown_Lab/scripts.pory"

# 273 "data/maps/NewBarkTown_Lab/scripts.pory"

# 274 "data/maps/NewBarkTown_Lab/scripts.pory"

# 275 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
# 276 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 277 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 278 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 279 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 280 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
# 281 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 282 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POTION
# 283 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 284 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
# 285 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 286 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 287 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 288 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 289 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 290 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 291 "data/maps/NewBarkTown_Lab/scripts.pory"

# 292 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceEpisode::
# 293 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 294 "data/maps/NewBarkTown_Lab/scripts.pory"
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
# 295 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_EventScript_hideStarterCase
# 296 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
# 297 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 298 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_LAB_POLICEMAN
# 299 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject LOCALID_COP DIR_WEST
# 300 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
# 301 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceNameRival
# 302 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceYes
# 303 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 304 "data/maps/NewBarkTown_Lab/scripts.pory"

# 305 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNo::
# 306 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
# 307 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
# 308 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
# 309 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 310 "data/maps/NewBarkTown_Lab/scripts.pory"

# 311 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival::
# 312 "data/maps/NewBarkTown_Lab/scripts.pory"
	special NameRival
# 313 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitstate
# 314 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_NAMED_SILVER
# 315 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 316 "data/maps/NewBarkTown_Lab/scripts.pory"

# 317 "data/maps/NewBarkTown_Lab/scripts.pory"

# 318 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival2::
# 319 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 320 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 321 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 322 "data/maps/NewBarkTown_Lab/scripts.pory"

# 323 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes::
# 324 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
# 325 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 326 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes2
# 327 "data/maps/NewBarkTown_Lab/scripts.pory"

# 328 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes3::
# 329 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 330 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 331 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 332 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 333 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 334 "data/maps/NewBarkTown_Lab/scripts.pory"

# 335 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 336 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 337 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 338 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 339 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 340 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 341 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 342 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 343 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 344 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 345 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 346 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 347 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 348 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 349 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 350 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 351 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 352 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 353 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 354 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 355 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 356 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 357 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 358 "data/maps/NewBarkTown_Lab/scripts.pory"

# 359 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes2::
# 360 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 361 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 362 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 363 "data/maps/NewBarkTown_Lab/scripts.pory"

# 364 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 365 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 366 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 367 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 368 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 369 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 370 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 371 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 372 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 373 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 374 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 375 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 376 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 377 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 378 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 379 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 380 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 381 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 382 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 383 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 384 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 385 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 386 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 387 "data/maps/NewBarkTown_Lab/scripts.pory"

# 388 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmState5::
# 389 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 390 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 391 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
# 392 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 393 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
# 394 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 395 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 396 "data/maps/NewBarkTown_Lab/scripts.pory"
	
# 397 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmMasterBall::
# 398 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 399 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 400 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
# 401 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_MASTER_BALL
# 402 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
# 403 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 404 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 405 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 406 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
# 407 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 408 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
# 409 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_GiveStarterMega
# 410 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 411 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
# 412 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
# 413 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 414 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 415 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 416 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 417 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 418 "data/maps/NewBarkTown_Lab/scripts.pory"

# 419 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmKimono::
# 420 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 421 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 422 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
# 423 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 424 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 425 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 426 "data/maps/NewBarkTown_Lab/scripts.pory"

# 427 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmLeague::
# 428 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 429 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 430 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
# 431 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 432 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 433 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 434 "data/maps/NewBarkTown_Lab/scripts.pory"

# 435 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmSSTicket::
# 436 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
# 437 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SS_TICKET
# 438 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
# 439 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 440 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 441 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 442 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
# 443 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 444 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 445 "data/maps/NewBarkTown_Lab/scripts.pory"

# 446 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
# 447 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 448 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 449 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 450 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 451 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
# 452 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 453 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 454 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 455 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_BALLS
# 456 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
# 457 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 458 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 459 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 460 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 461 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 462 "data/maps/NewBarkTown_Lab/scripts.pory"

# 463 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
# 464 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
# 465 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 466 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 467 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 468 "data/maps/NewBarkTown_Lab/scripts.pory"

# 469 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
# 470 "data/maps/NewBarkTown_Lab/scripts.pory"
	specialvar VAR_RESULT, CheckTogepi
# 471 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
# 472 "data/maps/NewBarkTown_Lab/scripts.pory"
	return
# 473 "data/maps/NewBarkTown_Lab/scripts.pory"

# 474 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
# 475 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
# 476 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 477 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
# 478 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 479 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
# 480 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 481 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
# 482 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 483 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 484 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 485 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
# 486 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 487 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_SHOWN_ELM_TOGEPI
# 488 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 489 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 490 "data/maps/NewBarkTown_Lab/scripts.pory"

# 491 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_CallMe::
# 492 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
# 493 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 494 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 495 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 496 "data/maps/NewBarkTown_Lab/scripts.pory"

# 497 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkRight:
# 498 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 499 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 500 "data/maps/NewBarkTown_Lab/scripts.pory"

# 501 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkLeft:
# 502 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 503 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 504 "data/maps/NewBarkTown_Lab/scripts.pory"

# 505 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_LabMovement_WalkToElm:
# 506 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 507 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 508 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 509 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 510 "data/maps/NewBarkTown_Lab/scripts.pory"

# 511 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnPlayer:
# 512 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 513 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 514 "data/maps/NewBarkTown_Lab/scripts.pory"

# 515 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmail:
# 516 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 517 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 518 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 519 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 520 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 521 "data/maps/NewBarkTown_Lab/scripts.pory"

# 522 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmailSlow:
# 523 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 524 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 525 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 526 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 527 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 528 "data/maps/NewBarkTown_Lab/scripts.pory"

# 529 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_GotoComputerSafe:
# 530 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 531 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 532 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 533 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 534 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 535 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 536 "data/maps/NewBarkTown_Lab/scripts.pory"

# 537 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnFromEmail:
# 538 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 539 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 540 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 541 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 542 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 543 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 544 "data/maps/NewBarkTown_Lab/scripts.pory"

# 545 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Left:
# 546 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_left
# 547 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 548 "data/maps/NewBarkTown_Lab/scripts.pory"

# 549 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Up:
# 550 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 551 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 552 "data/maps/NewBarkTown_Lab/scripts.pory"

# 553 "data/maps/NewBarkTown_Lab/scripts.pory"

# 554 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
# 555 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 556 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 557 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 558 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 559 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 560 "data/maps/NewBarkTown_Lab/scripts.pory"

# 561 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1LeavePlayer:
# 562 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 563 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 564 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 565 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 566 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 567 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 568 "data/maps/NewBarkTown_Lab/scripts.pory"

# 569 "data/maps/NewBarkTown_Lab/scripts.pory"
NeBarkTownLab_Movement_PlayerWalkToCop:
# 570 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 571 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 572 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 573 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 574 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 575 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 576 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 577 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 578 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 579 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_right
# 580 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 581 "data/maps/NewBarkTown_Lab/scripts.pory"

# 582 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Right:
# 583 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_right
# 584 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 585 "data/maps/NewBarkTown_Lab/scripts.pory"

# 586 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Down:
# 587 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_down
# 588 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 589 "data/maps/NewBarkTown_Lab/scripts.pory"

# 590 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CopLeaves:
# 591 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 592 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 593 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 594 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 595 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 596 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 597 "data/maps/NewBarkTown_Lab/scripts.pory"

# 598 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_PlayerStepsToElm:
# 599 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 600 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 601 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 602 "data/maps/NewBarkTown_Lab/scripts.pory"

# 603 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepBack:
# 604 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock_facing_direction
# 605 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 606 "data/maps/NewBarkTown_Lab/scripts.pory"
	unlock_facing_direction
# 607 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 608 "data/maps/NewBarkTown_Lab/scripts.pory"

# 609 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepForward:
# 610 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 611 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 612 "data/maps/NewBarkTown_Lab/scripts.pory"

# 613 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShouldntTouch:
# 614 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Probably shouldn't touch!$"
# 615 "data/maps/NewBarkTown_Lab/scripts.pory"

# 616 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmIntro:
# 617 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 618 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I needed to ask you a favor.\p"
# 619 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm conducting new Pokémon\n"
# 620 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research right now. I was\l"
# 621 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "wondering if you could help\l"
# 622 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "me with it, {PLAYER}.\p"
# 623 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You see…\p"
# 624 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm writing a paper that I\n"
# 625 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "want to present at a conference.\p"
# 626 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But there are some things I\n"
# 627 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "don't quite understand yet.\p"
# 628 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "So!\p"
# 629 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'd like you to raise a\n"
# 630 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon that I recently caught.$"
# 631 "data/maps/NewBarkTown_Lab/scripts.pory"

# 632 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAccepted:
# 633 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 634 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You're a great help!$"
# 635 "data/maps/NewBarkTown_Lab/scripts.pory"

# 636 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmRefused:
# 637 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Please, I need your\n"
# 638 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "help!$"
# 639 "data/maps/NewBarkTown_Lab/scripts.pory"

# 640 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
# 641 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When I announce my findings,\n"
# 642 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm sure we'll delve deeper\p"
# 643 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "into the many mysteries of\n"
# 644 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon.\p"
# 645 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You can count on it!$"
# 646 "data/maps/NewBarkTown_Lab/scripts.pory"

# 647 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGotAnEmail:
# 648 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, hey! I got an e-mail!\p"
# 649 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "… … … … … … … …\n"
# 650 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hm… Uh-huh…\p"
# 651 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Okay…$"
# 652 "data/maps/NewBarkTown_Lab/scripts.pory"

# 653 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
# 654 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hey, listen.\p"
# 655 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have an acquaintance called\n"
# 656 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon.\p"
# 657 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He keeps finding weird things and\n"
# 658 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "raving about his discoveries.\p"
# 659 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Anyway, I just got an e-mail\n"
# 660 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from him saying that this\l"
# 661 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "time it's real.\p"
# 662 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It is intriguing, but we're\n"
# 663 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "busy with our Pokémon research...\p"
# 664 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wait!\n"
# 665 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know!\p"
# 666 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, can you go in our\n"
# 667 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "place?$"
# 668 "data/maps/NewBarkTown_Lab/scripts.pory"

# 669 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
# 670 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to raise one of\n"
# 671 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Pokémon contained in this case.\p"
# 672 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You'll be that Pokémon's\n"
# 673 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "first partner, {PLAYER}!\p"
# 674 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Go on. Pick one!$"
# 675 "data/maps/NewBarkTown_Lab/scripts.pory"

# 676 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWhereGoing:
# 677 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Wait! Where are you\n"
# 678 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going?$"
# 679 "data/maps/NewBarkTown_Lab/scripts.pory"

# 680 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseCyndaquil:
# 681 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: You'll take Cyndaquil,\n"
# 682 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the fire Pokémon?$"
# 683 "data/maps/NewBarkTown_Lab/scripts.pory"

# 684 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseTotodile:
# 685 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Do you want Totodile,\n"
# 686 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the water Pokémon?$"
# 687 "data/maps/NewBarkTown_Lab/scripts.pory"

# 688 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseChikorita:
# 689 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: So, you like Chikorita,\n"
# 690 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the grass Pokémon?$"
# 691 "data/maps/NewBarkTown_Lab/scripts.pory"

# 692 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_DidntChooseStarter:
# 693 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Think it over carefully.\p"
# 694 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Your partner is important.$"
# 695 "data/maps/NewBarkTown_Lab/scripts.pory"

# 696 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChoseStarter:
# 697 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: I think that's a great\n"
# 698 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon too!$"
# 699 "data/maps/NewBarkTown_Lab/scripts.pory"

# 700 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ReceivedStarter:
# 701 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 702 "data/maps/NewBarkTown_Lab/scripts.pory"

# 703 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Nickname:
# 704 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Would you like to give your\n"
# 705 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{STR_VAR_1} a nickname?$"
# 706 "data/maps/NewBarkTown_Lab/scripts.pory"

# 707 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections1:
# 708 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon lives a little bit\n"
# 709 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "beyond Cherrygrove, the next\l"
# 710 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "city over.\p"
# 711 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's almost a direct route\n"
# 712 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "there, so you can't miss it.\p"
# 713 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But just in case, you have my\n"
# 714 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "phone number. Call me if\l"
# 715 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up!$"
# 716 "data/maps/NewBarkTown_Lab/scripts.pory"

# 717 "data/maps/NewBarkTown_Lab/scripts.pory"

# 718 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
# 719 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears,\n"
# 720 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "let your Pokémon battle it!$"
# 721 "data/maps/NewBarkTown_Lab/scripts.pory"

# 722 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections2:
# 723 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears, let\n"
# 724 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "your Pokémon battle it!\p"
# 725 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If your Pokémon is hurt, you\n"
# 726 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "should heal it with the machine\l"
# 727 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to my right, or at the Pokémon Center.\p"
# 728 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm counting on you!$"
# 729 "data/maps/NewBarkTown_Lab/scripts.pory"

# 730 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_GotElmsNumber:
# 731 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} got Elm's phone\n"
# 732 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "number.$"
# 733 "data/maps/NewBarkTown_Lab/scripts.pory"

# 734 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
# 735 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon goes everywhere and\n"
# 736 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "finds rarities.\p"
# 737 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Too bad they're just rare and\n"
# 738 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "not very useful…$"
# 739 "data/maps/NewBarkTown_Lab/scripts.pory"

# 740 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmPokeBall:
# 741 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It contains Pokémon caught\n"
# 742 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "by Prof.Elm.$"
# 743 "data/maps/NewBarkTown_Lab/scripts.pory"

# 744 "data/maps/NewBarkTown_Lab/scripts.pory"
@THEFT================================================================================
# 745 "data/maps/NewBarkTown_Lab/scripts.pory"

# 746 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft1:
# 747 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, this is terrible…\p"
# 748 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, yes, what was Mr. Pokémon's\n"
# 749 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "big discovery?$"
# 750 "data/maps/NewBarkTown_Lab/scripts.pory"

# 751 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft2:
# 752 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} handed the Mystery Egg\n"
# 753 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to Prof.Elm.$"
# 754 "data/maps/NewBarkTown_Lab/scripts.pory"

# 755 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft3:
# 756 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: This?$"
# 757 "data/maps/NewBarkTown_Lab/scripts.pory"

# 758 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft4:
# 759 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Is it a Pokémon Egg?\p"
# 760 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If it is, it is a great\n"
# 761 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "discovery!\p"
# 762 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: What?!?\p"
# 763 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof.Oak gave you a Pokédex?\p"
# 764 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, is that true?\n"
# 765 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Th-that's incredible!\p"
# 766 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He is superb at seeing the\n"
# 767 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "potential of people as trainers.\p"
# 768 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, {PLAYER}. You may have what\n"
# 769 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "it takes to become the Champion.\p"
# 770 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You seem to be getting on\n"
# 771 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "great with Pokémon too.\p"
# 772 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should take the Pokémon\n"
# 773 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Gym challenge.\p"
# 774 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The closest Gym would be the\n"
# 775 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "one in Violet City.\p"
# 776 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…{PLAYER}. The road to the\n"
# 777 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "championship will be a long one.\p"
# 778 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Before you leave, make sure\n"
# 779 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that you talk to your mom.$"
# 780 "data/maps/NewBarkTown_Lab/scripts.pory"

# 781 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmStudyingEgg:
# 782 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Don't give up!\n"
# 783 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'll call if I learn anything\l"
# 784 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about that Egg!$"
# 785 "data/maps/NewBarkTown_Lab/scripts.pory"

# 786 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideHasEgg:
# 787 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}? Didn't you meet\n"
# 788 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "my assistant?\p"
# 789 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He should have met you with\n"
# 790 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Egg at Violet City's\p"
# 791 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon Center.\p"
# 792 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You must have just missed him.\n"
# 793 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Try to catch him there.$"
# 794 "data/maps/NewBarkTown_Lab/scripts.pory"

# 795 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
# 796 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hey, has that Egg changed\n"
# 797 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "any?$"
# 798 "data/maps/NewBarkTown_Lab/scripts.pory"

# 799 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
# 800 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}? I thought the Egg\n"
# 801 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "hatched.\p"
# 802 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Where is the Pokémon?$"
# 803 "data/maps/NewBarkTown_Lab/scripts.pory"

# 804 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi1:
# 805 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, you look great!$"
# 806 "data/maps/NewBarkTown_Lab/scripts.pory"

# 807 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi2:
# 808 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What? That Pokémon!?!$"
# 809 "data/maps/NewBarkTown_Lab/scripts.pory"

# 810 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi3:
# 811 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Egg hatched! So, Pokémon\n"
# 812 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are born from Eggs…\p"
# 813 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "No, perhaps not all Pokémon\n"
# 814 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are.\p"
# 815 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, there's still a lot of\n"
# 816 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research to be done.$"
# 817 "data/maps/NewBarkTown_Lab/scripts.pory"

# 818 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
# 819 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}! You're helping\n"
# 820 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "unravel Pokémon mysteries for us!\p"
# 821 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to have this as a\n"
# 822 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "token of our appreciation.$"
# 823 "data/maps/NewBarkTown_Lab/scripts.pory"

# 824 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
# 825 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That's a Shiny Stone.\p"
# 826 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Some species of Pokémon evolve\n"
# 827 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "when they grow to certain levels.\p"
# 828 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A Togetic will evolve\n"
# 829 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "with this one.$"
# 830 "data/maps/NewBarkTown_Lab/scripts.pory"

# 831 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmCallYou:
# 832 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, I'll call you if\n"
# 833 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up.$"
# 834 "data/maps/NewBarkTown_Lab/scripts.pory"

# 835 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAfterTheft:
# 836 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 837 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 838 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 839 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 840 "data/maps/NewBarkTown_Lab/scripts.pory"

# 841 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
# 842 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hi, {PLAYER}!\p"
# 843 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks to you, my research is\n"
# 844 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going great!\p"
# 845 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Take this as a token of my\n"
# 846 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "appreciation.$"
# 847 "data/maps/NewBarkTown_Lab/scripts.pory"

# 848 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
# 849 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Master Ball is the best!\p"
# 850 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the ultimate Ball! It'll\n"
# 851 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "catch any Pokémon without fail.\p"
# 852 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's given only to recognized\n"
# 853 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon researchers.\p"
# 854 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I think you can make much better\n"
# 855 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "use of it than I can, {PLAYER}!$"
# 856 "data/maps/NewBarkTown_Lab/scripts.pory"

# 857 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoGirls:
# 858 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "By the way...\n"
# 859 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A group of beautiful Kimono\l"
# 860 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls were looking for you.\p"
# 861 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They told me they are\n"
# 862 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "waiting for you at the\l" 
# 863 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ecruteak Dance Theater.\p"
# 864 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know you've gone through many\n"
# 865 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "things since that Egg got you\l"
# 866 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "involved in all this...\p"
# 867 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I hope you'll carry through it.$"
# 868 "data/maps/NewBarkTown_Lab/scripts.pory"

# 869 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoWaiting:
# 870 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: The Kimono\n"
# 871 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls are waiting for you at\l"
# 872 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Ecruteak Dance Theater.$"
# 873 "data/maps/NewBarkTown_Lab/scripts.pory"

# 874 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_League:
# 875 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: Hahaha...\n"
# 876 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Good job!\p"
# 877 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That rare Egg has brought you\n"
# 878 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "a lot of trouble, huh?\p"
# 879 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Kimono Girls said something\n"
# 880 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about me?\p"
# 881 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have nothing to do with it.\p"
# 882 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You made your decision and went\n"
# 883 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "through with it.\p"
# 884 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Having done so much, you should\n"
# 885 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "be able to face the League now!\p"
# 886 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should head for Indigo\n"
# 887 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Plateau!\p"
# 888 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Do you know how to get there?\n"
# 889 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Follow Route 27 to Route 26.\p"
# 890 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Once there, go straight north!$"
# 891 "data/maps/NewBarkTown_Lab/scripts.pory"

# 892 "data/maps/NewBarkTown_Lab/scripts.pory"

# 893 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket1:
# 894 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 895 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I called because I have\n"
# 896 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "something for you.\p"
# 897 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "See? It's an S.S.Ticket.\p"
# 898 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can catch Pokémon in\n"
# 899 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Sevii.$"
# 900 "data/maps/NewBarkTown_Lab/scripts.pory"

# 901 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket2:
# 902 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The ship departs from Olivine\n"
# 903 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "City.\p"
# 904 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But you knew that already,\n"
# 905 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}.\p"
# 906 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "After all, you've traveled all\n"
# 907 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "over with your Pokémon.$"
# 908 "data/maps/NewBarkTown_Lab/scripts.pory"

# 909 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_LabMonEgg:
# 910 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the Pokémon Egg being\n"
# 911 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "studied by Prof.Elm.$"
# 912 "data/maps/NewBarkTown_Lab/scripts.pory"

# 913 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGivePotion:
# 914 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, I want you to have\n"
# 915 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "this for your errand.$"
# 916 "data/maps/NewBarkTown_Lab/scripts.pory"

# 917 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAlwaysBusy:
# 918 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There are only three of us, so\n"
# 919 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "we're always busy.$"
# 920 "data/maps/NewBarkTown_Lab/scripts.pory"

# 921 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideSave:
# 922 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Don't forget to save your game\n"
# 923 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "regularly!\p"
# 924 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Press the Start button, then\n"
# 925 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Save the game!$"
# 926 "data/maps/NewBarkTown_Lab/scripts.pory"

# 927 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideTheftTestimony:
# 928 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There was a loud noise\n"
# 929 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "outside…\p"
# 930 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When we went to look,\n"
# 931 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "someone stole a Pokémon.\p"
# 932 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's unbelievable that anyone\n"
# 933 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "would do that!\p"
# 934 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 935 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 936 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 937 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 938 "data/maps/NewBarkTown_Lab/scripts.pory"

# 939 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGiveBalls:
# 940 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 941 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Use these on your Pokédex\n"
# 942 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "quest!$"
# 943 "data/maps/NewBarkTown_Lab/scripts.pory"

# 944 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideExplainBalls:
# 945 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "To add to your Pokédex, you\n"
# 946 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "have to catch Pokémon.\p"
# 947 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Throw Poké Balls at wild\n"
# 948 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon to get them.$"
# 949 "data/maps/NewBarkTown_Lab/scripts.pory"

# 950 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer1:
# 951 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I heard a Pokémon was stolen\n"
# 952 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "here…\p"
# 953 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I was just getting some\n"
# 954 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "information from Prof.Elm.\p"
# 955 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Apparently, it was a young\n"
# 956 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "male with long, red hair…\p"
# 957 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What?\p"
# 958 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You battled a trainer like\n"
# 959 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that?\p"
# 960 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Did you happen to get his\n"
# 961 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "name?$"
# 962 "data/maps/NewBarkTown_Lab/scripts.pory"

# 963 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer2:
# 964 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So Silver was his name.\p"
# 965 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 966 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 967 "data/maps/NewBarkTown_Lab/scripts.pory"

# 968 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer3:
# 969 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So {RIVAL} was his name.\p"
# 970 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 971 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 972 "data/maps/NewBarkTown_Lab/scripts.pory"

# 973 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_OfficerNo:
# 974 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Surely you got his name?!$"
# 975 "data/maps/NewBarkTown_Lab/scripts.pory"

# 976 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Elm_CallMe:
# 977 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ah, {PLAYER}!\p"
# 978 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "How's your Pokédex coming along?\n"
# 979 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm busy now, but call me sometime\l"
# 980 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "and I can check your progress!$"

NewBarkTown_Lab_GiveStarterMega::
# 984 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_0
# 988 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_BONDSTONE, 1
# 989 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_1
	return


NewBarkTown_Lab_EventScript_ElmPostgameHint::
# 996 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0
# 1010 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_1
# 1012 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1013 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1014 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1015 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1016 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1017 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1018 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 1019 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 1020 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2
# 1026 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_POSTGAME_FEATURES
# 1027 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_VICTORYROAD_RIVAL
# 1028 "data/maps/NewBarkTown_Lab/scripts.pory"
	checkplayergender
# 1029 "data/maps/NewBarkTown_Lab/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_Lab_EventScript_ElmPostgameHint_2
# 1036 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4
NewBarkTown_Lab_EventScript_ElmPostgameHint_1:
# 1042 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5
# 1044 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_GUARD
# 1045 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ALLOW_SOUTH_JOHTO_PASS
# 1046 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 1047 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
	end

NewBarkTown_Lab_EventScript_ElmPostgameHint_2:
# 1030 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3
	goto NewBarkTown_Lab_EventScript_ElmPostgameHint_1


NewBarkTown_Lab_GiveStarterMega_Text_0:
# 984 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, and you got a Mega Ring from \n"
	.string "Prof. Oak?\l"
	.string "Then I think you are ready to handle\l"
	.string "this.$"

NewBarkTown_Lab_GiveStarterMega_Text_1:
# 989 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's a special Mega Stone, specifically\n"
	.string "for your starter Pokémon. I expect \l"
	.string "great things from you, {PLAYER}!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0:
# 996 "data/maps/NewBarkTown_Lab/scripts.pory"
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
# 1010 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But first, let me upgrade your Pokédex\n"
	.string "with a new feature!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2:
# 1020 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can view abilities of the\n"
	.string "opposing Pokémon with the L-button\l"
	.string "in battle! \p"
	.string "That will surely be handy as the\n"
	.string "battles get tougher!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3:
# 1030 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Crystal went to train\n"
	.string "in Mt. Silver. She looked really tired\l"
	.string "the last time I saw her though... \p"
	.string "Could you check on her at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4:
# 1036 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Gold went to train\n"
	.string "in Mt. Silver. He looked really tired\l"
	.string "the last time I saw him thoughö...\p"
	.string "Could you check on him at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5:
# 1042 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I asked from the League to let you\n"
	.string "pass since you've the new Champion.$"
