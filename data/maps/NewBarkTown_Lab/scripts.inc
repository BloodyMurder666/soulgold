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
	goto_if_eq VAR_FACING, DIR_SOUTH, NewBarkTown_Lab_EventScript_StarterCaseWrongSide
# 179 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
# 180 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_StarterCase_Choice
# 181 "data/maps/NewBarkTown_Lab/scripts.pory"
    msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
# 182 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 183 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 184 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 185 "data/maps/NewBarkTown_Lab/scripts.pory"

# 186 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCaseWrongSide::
# 187 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_StarterCaseWrongSide, MSGBOX_DEFAULT
# 188 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 189 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 190 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 191 "data/maps/NewBarkTown_Lab/scripts.pory"

# 192 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_StarterCase_Choice::
# 193 "data/maps/NewBarkTown_Lab/scripts.pory"
   callnative StartNewPokeballCaseUI
# 194 "data/maps/NewBarkTown_Lab/scripts.pory"
   waitstate
# 195 "data/maps/NewBarkTown_Lab/scripts.pory"
   goto NewBarkTown_Lab_EventScript_ChoseStarter
# 196 "data/maps/NewBarkTown_Lab/scripts.pory"

# 197 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter::
# 198 "data/maps/NewBarkTown_Lab/scripts.pory"
	showmonpic VAR_PLAYER_STARTER_SPECIES, 10, 3
# 199 "data/maps/NewBarkTown_Lab/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 200 "data/maps/NewBarkTown_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_PLAYER_STARTER_SPECIES
# 201 "data/maps/NewBarkTown_Lab/scripts.pory"
	message NewBarkTown_Lab_Text_ReceivedStarter
# 202 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_STARTER_PICKING_STATE 1
# 203 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitfanfare
# 204 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 205 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 206 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_StepBackFromStarter
# 207 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 208 "data/maps/NewBarkTown_Lab/scripts.pory"
	updatefollowingmon
# 209 "data/maps/NewBarkTown_Lab/scripts.pory"
	setobjectxy OBJ_EVENT_ID_FOLLOWER, 9, 5
# 210 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, NewBarkTown_Lab_Movement_StarterLeavesBall
# 211 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_BALL_OPEN
# 212 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 213 "data/maps/NewBarkTown_Lab/scripts.pory"
	playmoncry VAR_PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
# 214 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_LEDGE
# 215 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, NewBarkTown_Lab_Movement_StarterGreetsPlayer
# 216 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 217 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmoncry
# 218 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 45
# 219 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 220 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
# 221 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 222 "data/maps/NewBarkTown_Lab/scripts.pory"
    closemessage
# 223 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 224 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 225 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 226 "data/maps/NewBarkTown_Lab/scripts.pory"

# 227 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ChoseStarter2::
# 228 "data/maps/NewBarkTown_Lab/scripts.pory"
    moveobjecttocoords OBJ_EVENT_ID_PLAYER, 6, 4, DIR_NORTH
# 229 "data/maps/NewBarkTown_Lab/scripts.pory"
    waitmovement 0
# 230 "data/maps/NewBarkTown_Lab/scripts.pory"
    @applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
# 231 "data/maps/NewBarkTown_Lab/scripts.pory"
    @waitmovement 0
# 232 "data/maps/NewBarkTown_Lab/scripts.pory"
    clearflag FLAG_HIDE_NEWBARK_RIVALMARILL
# 233 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_RIVAL_STATE, 2
# 234 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_STARTER_PICKING_STATE, 2
# 235 "data/maps/NewBarkTown_Lab/scripts.pory"
    goto NewBarkTown_Lab_EventScript_MrPokemon
# 236 "data/maps/NewBarkTown_Lab/scripts.pory"

# 237 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_DeclinedStarter::
# 238 "data/maps/NewBarkTown_Lab/scripts.pory"
	hidemonpic
# 239 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
# 240 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 241 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 242 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 243 "data/maps/NewBarkTown_Lab/scripts.pory"

# 244 "data/maps/NewBarkTown_Lab/scripts.pory"

# 245 "data/maps/NewBarkTown_Lab/scripts.pory"

# 246 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_NicknameStarter::
# 247 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 248 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 249 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 250 "data/maps/NewBarkTown_Lab/scripts.pory"

# 251 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemon::
# 252 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
# 253 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 254 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 255 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 256 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 257 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 258 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 259 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 260 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
# 261 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
# 262 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 263 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 264 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 265 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 266 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 267 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 268 "data/maps/NewBarkTown_Lab/scripts.pory"

# 269 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
# 270 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
# 271 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 272 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_FIRST_BALLS
# 273 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_RECEIVED_EXP_SHARE
# 274 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 3
# 275 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 276 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 277 "data/maps/NewBarkTown_Lab/scripts.pory"

# 278 "data/maps/NewBarkTown_Lab/scripts.pory"
CopNewBarkTown_Lab_EventScript_ElmState2::
# 279 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
# 280 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
# 281 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
# 282 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 283 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 284 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 285 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 286 "data/maps/NewBarkTown_Lab/scripts.pory"

# 287 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine1::
# 288 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 289 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
# 290 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 291 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 292 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 293 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 294 "data/maps/NewBarkTown_Lab/scripts.pory"

# 295 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_HealingMachine2::
# 296 "data/maps/NewBarkTown_Lab/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 297 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 298 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 299 "data/maps/NewBarkTown_Lab/scripts.pory"

# 300 "data/maps/NewBarkTown_Lab/scripts.pory"

# 301 "data/maps/NewBarkTown_Lab/scripts.pory"

# 302 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
# 303 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 304 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 305 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 306 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 307 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
# 308 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 309 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POTION
# 310 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 311 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
# 312 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 313 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 314 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 315 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 316 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 317 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 318 "data/maps/NewBarkTown_Lab/scripts.pory"

# 319 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceEpisode::
# 320 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 321 "data/maps/NewBarkTown_Lab/scripts.pory"
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
# 322 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_EventScript_hideStarterCase
# 323 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
# 324 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 325 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_LAB_POLICEMAN
# 326 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject LOCALID_COP DIR_WEST
# 327 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
# 328 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceNameRival
# 329 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceYes
# 330 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 331 "data/maps/NewBarkTown_Lab/scripts.pory"

# 332 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNo::
# 333 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
# 334 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
# 335 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
# 336 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 337 "data/maps/NewBarkTown_Lab/scripts.pory"

# 338 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival::
# 339 "data/maps/NewBarkTown_Lab/scripts.pory"
	special NameRival
# 340 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitstate
# 341 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_NAMED_SILVER
# 342 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 343 "data/maps/NewBarkTown_Lab/scripts.pory"

# 344 "data/maps/NewBarkTown_Lab/scripts.pory"

# 345 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceNameRival2::
# 346 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 347 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 348 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes3
# 349 "data/maps/NewBarkTown_Lab/scripts.pory"

# 350 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes::
# 351 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
# 352 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 353 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto NewBarkTown_Lab_EventScript_PoliceYes2
# 354 "data/maps/NewBarkTown_Lab/scripts.pory"

# 355 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes3::
# 356 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Officer3, MSGBOX_DEFAULT
# 357 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 358 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 359 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 360 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 361 "data/maps/NewBarkTown_Lab/scripts.pory"

# 362 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 363 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 364 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 365 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 366 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 367 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 368 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 369 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 370 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 371 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 372 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 373 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 374 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 375 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 376 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 377 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 378 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 379 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 380 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 381 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 382 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 383 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 384 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 385 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 386 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 387 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 388 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 389 "data/maps/NewBarkTown_Lab/scripts.pory"

# 390 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_PoliceYes2::
# 391 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
# 392 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 393 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeobject LOCALID_COP
# 394 "data/maps/NewBarkTown_Lab/scripts.pory"

# 395 "data/maps/NewBarkTown_Lab/scripts.pory"
	@ setobjectxyperm LOCALID_COP, 25, 4
# 396 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
# 397 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 398 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 399 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
# 400 "data/maps/NewBarkTown_Lab/scripts.pory"
	removefieldmugshot
# 401 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
# 402 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 403 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
# 404 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 405 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 406 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
# 407 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 408 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 409 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
# 410 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 411 "data/maps/NewBarkTown_Lab/scripts.pory"
	createfieldmugshot MUGSHOT_ELM
# 412 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
# 413 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 414 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
# 415 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 4
# 416 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MOMS_FRIEND
# 417 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_MOMS_FRIEND2
# 418 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 419 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_EXP_SHARE
# 420 "data/maps/NewBarkTown_Lab/scripts.pory"
	removeitem ITEM_MYSTERY_EGG
# 421 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 422 "data/maps/NewBarkTown_Lab/scripts.pory"

# 423 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmState5::
# 424 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 425 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 426 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
# 427 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 428 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
# 429 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 430 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 431 "data/maps/NewBarkTown_Lab/scripts.pory"

# 432 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmMasterBall::
# 433 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 434 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 435 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
# 436 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_MASTER_BALL
# 437 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
# 438 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 439 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 20
# 440 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 441 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
# 442 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 60
# 443 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
# 444 "data/maps/NewBarkTown_Lab/scripts.pory"
	call NewBarkTown_Lab_GiveStarterMega
# 445 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 446 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
# 447 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
# 448 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_SILVER
# 449 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
# 450 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
# 451 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 452 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 453 "data/maps/NewBarkTown_Lab/scripts.pory"

# 454 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmKimono::
# 455 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 456 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 457 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
# 458 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 459 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 460 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 461 "data/maps/NewBarkTown_Lab/scripts.pory"

# 462 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmLeague::
# 463 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 464 "data/maps/NewBarkTown_Lab/scripts.pory"
	faceplayer
# 465 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
# 466 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 467 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 468 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 469 "data/maps/NewBarkTown_Lab/scripts.pory"

# 470 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_ElmSSTicket::
# 471 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
# 472 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SS_TICKET
# 473 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
# 474 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 475 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
# 476 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 477 "data/maps/NewBarkTown_Lab/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
# 478 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 479 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 480 "data/maps/NewBarkTown_Lab/scripts.pory"

# 481 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
# 482 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock
# 483 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
# 484 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 485 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 486 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
# 487 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 488 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 489 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 490 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_BALLS
# 491 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
# 492 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 493 "data/maps/NewBarkTown_Lab/scripts.pory"
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
# 494 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmovement 0
# 495 "data/maps/NewBarkTown_Lab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 496 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 497 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 498 "data/maps/NewBarkTown_Lab/scripts.pory"

# 499 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
# 500 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
# 501 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 502 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 503 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 504 "data/maps/NewBarkTown_Lab/scripts.pory"

# 505 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
# 506 "data/maps/NewBarkTown_Lab/scripts.pory"
	specialvar VAR_RESULT, CheckTogepi
# 507 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
# 508 "data/maps/NewBarkTown_Lab/scripts.pory"
	return
# 509 "data/maps/NewBarkTown_Lab/scripts.pory"

# 510 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
# 511 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
# 512 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 513 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
# 514 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 515 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
# 516 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 517 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
# 518 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitmessage
# 519 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 520 "data/maps/NewBarkTown_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 521 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
# 522 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 523 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_SHOWN_ELM_TOGEPI
# 524 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 525 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 526 "data/maps/NewBarkTown_Lab/scripts.pory"

# 527 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_EventScript_Elm_CallMe::
# 528 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
# 529 "data/maps/NewBarkTown_Lab/scripts.pory"
	closemessage
# 530 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
# 531 "data/maps/NewBarkTown_Lab/scripts.pory"
	end
# 532 "data/maps/NewBarkTown_Lab/scripts.pory"

# 533 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkRight:
# 534 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 535 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 536 "data/maps/NewBarkTown_Lab/scripts.pory"

# 537 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_WalkLeft:
# 538 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 539 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 540 "data/maps/NewBarkTown_Lab/scripts.pory"

# 541 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_StepBackFromStarter:
# 542 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 543 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 544 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 545 "data/maps/NewBarkTown_Lab/scripts.pory"

# 546 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_StarterLeavesBall:
# 547 "data/maps/NewBarkTown_Lab/scripts.pory"
	exit_pokeball
# 548 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 549 "data/maps/NewBarkTown_Lab/scripts.pory"
	set_visible
# 550 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 551 "data/maps/NewBarkTown_Lab/scripts.pory"

# 552 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_StarterGreetsPlayer:
# 553 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_player
# 554 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay_4
# 555 "data/maps/NewBarkTown_Lab/scripts.pory"
	jump_in_place_down
# 556 "data/maps/NewBarkTown_Lab/scripts.pory"
	emote_heart
# 557 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_player
# 558 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 559 "data/maps/NewBarkTown_Lab/scripts.pory"

# 560 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_LabMovement_WalkToElm:
# 561 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 562 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 563 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 564 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 565 "data/maps/NewBarkTown_Lab/scripts.pory"

# 566 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnPlayer:
# 567 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 568 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 569 "data/maps/NewBarkTown_Lab/scripts.pory"

# 570 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmail:
# 571 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 572 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 573 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 574 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 575 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 576 "data/maps/NewBarkTown_Lab/scripts.pory"

# 577 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CheckEmailSlow:
# 578 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 579 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 580 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 581 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 582 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 583 "data/maps/NewBarkTown_Lab/scripts.pory"

# 584 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_GotoComputerSafe:
# 585 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 586 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 587 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 588 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 589 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 590 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 591 "data/maps/NewBarkTown_Lab/scripts.pory"

# 592 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ReturnFromEmail:
# 593 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 594 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 595 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 596 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_right
# 597 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 598 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 599 "data/maps/NewBarkTown_Lab/scripts.pory"

# 600 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Left:
# 601 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_left
# 602 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 603 "data/maps/NewBarkTown_Lab/scripts.pory"

# 604 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Look_Up:
# 605 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 606 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 607 "data/maps/NewBarkTown_Lab/scripts.pory"

# 608 "data/maps/NewBarkTown_Lab/scripts.pory"

# 609 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
# 610 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 611 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 612 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 613 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 614 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 615 "data/maps/NewBarkTown_Lab/scripts.pory"

# 616 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_Aide1LeavePlayer:
# 617 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 618 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_left
# 619 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 620 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_up
# 621 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_down
# 622 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 623 "data/maps/NewBarkTown_Lab/scripts.pory"

# 624 "data/maps/NewBarkTown_Lab/scripts.pory"
NeBarkTownLab_Movement_PlayerWalkToCop:
# 625 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 626 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 627 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 628 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 629 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 630 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 631 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 632 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_left
# 633 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 634 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_right
# 635 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 636 "data/maps/NewBarkTown_Lab/scripts.pory"

# 637 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Right:
# 638 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_right
# 639 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 640 "data/maps/NewBarkTown_Lab/scripts.pory"

# 641 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTownLab_Movement_Elm_Down:
# 642 "data/maps/NewBarkTown_Lab/scripts.pory"
    face_down
# 643 "data/maps/NewBarkTown_Lab/scripts.pory"
    step_end
# 644 "data/maps/NewBarkTown_Lab/scripts.pory"

# 645 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_CopLeaves:
# 646 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 647 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 648 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 649 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 650 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_down
# 651 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 652 "data/maps/NewBarkTown_Lab/scripts.pory"

# 653 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_PlayerStepsToElm:
# 654 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_right
# 655 "data/maps/NewBarkTown_Lab/scripts.pory"
	face_up
# 656 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 657 "data/maps/NewBarkTown_Lab/scripts.pory"

# 658 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepBack:
# 659 "data/maps/NewBarkTown_Lab/scripts.pory"
	lock_facing_direction
# 660 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_up
# 661 "data/maps/NewBarkTown_Lab/scripts.pory"
	unlock_facing_direction
# 662 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 663 "data/maps/NewBarkTown_Lab/scripts.pory"

# 664 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Movement_ElmStepForward:
# 665 "data/maps/NewBarkTown_Lab/scripts.pory"
	walk_fast_down
# 666 "data/maps/NewBarkTown_Lab/scripts.pory"
	step_end
# 667 "data/maps/NewBarkTown_Lab/scripts.pory"

# 668 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShouldntTouch:
# 669 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Probably shouldn't touch!$"
# 670 "data/maps/NewBarkTown_Lab/scripts.pory"

# 671 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_StarterCaseWrongSide:
# 672 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oops, the case does not open\n"
# 673 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from this side!$"
# 674 "data/maps/NewBarkTown_Lab/scripts.pory"

# 675 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAccepted:
# 676 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 677 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You're a great help!$"
# 678 "data/maps/NewBarkTown_Lab/scripts.pory"

# 679 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmRefused:
# 680 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Please, I need your\n"
# 681 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "help!$"
# 682 "data/maps/NewBarkTown_Lab/scripts.pory"

# 683 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmResearchAmbitions:
# 684 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When I announce my findings,\n"
# 685 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm sure we'll delve deeper\p"
# 686 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "into the many mysteries of\n"
# 687 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon.\p"
# 688 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You can count on it!$"
# 689 "data/maps/NewBarkTown_Lab/scripts.pory"

# 690 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGotAnEmail:
# 691 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, hey! I got an e-mail!\p"
# 692 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "… … … … … … … …\n"
# 693 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hm… Uh-huh…\p"
# 694 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Okay…$"
# 695 "data/maps/NewBarkTown_Lab/scripts.pory"

# 696 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
# 697 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Hey, listen.\p"
# 698 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have an acquaintance called\n"
# 699 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon.\p"
# 700 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He keeps finding weird things and\n"
# 701 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "raving about his discoveries.\p"
# 702 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Anyway, I just got an e-mail\n"
# 703 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "from him saying that this\l"
# 704 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "time it's real.\p"
# 705 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It is intriguing, but we're\n"
# 706 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "busy with our Pokémon research...\p"
# 707 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wait!\n"
# 708 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know!\p"
# 709 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, can you go in our\n"
# 710 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "place?$"
# 711 "data/maps/NewBarkTown_Lab/scripts.pory"

# 712 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmChooseAPokemon:
# 713 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to raise one of\n"
# 714 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Pokémon contained in this case.\p"
# 715 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You'll be that Pokémon's\n"
# 716 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "first partner, {PLAYER}!\p"
# 717 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Go on. Pick one!$"
# 718 "data/maps/NewBarkTown_Lab/scripts.pory"

# 719 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWhereGoing:
# 720 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Wait! Where are you\n"
# 721 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going?$"
# 722 "data/maps/NewBarkTown_Lab/scripts.pory"

# 723 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseCyndaquil:
# 724 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: You'll take Cyndaquil,\n"
# 725 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the fire Pokémon?$"
# 726 "data/maps/NewBarkTown_Lab/scripts.pory"

# 727 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseTotodile:
# 728 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Do you want Totodile,\n"
# 729 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the water Pokémon?$"
# 730 "data/maps/NewBarkTown_Lab/scripts.pory"

# 731 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChooseChikorita:
# 732 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: So, you like Chikorita,\n"
# 733 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the grass Pokémon?$"
# 734 "data/maps/NewBarkTown_Lab/scripts.pory"

# 735 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_DidntChooseStarter:
# 736 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Think it over carefully.\p"
# 737 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Your partner is important.$"
# 738 "data/maps/NewBarkTown_Lab/scripts.pory"

# 739 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ChoseStarter:
# 740 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: I think that's a great\n"
# 741 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon too!$"
# 742 "data/maps/NewBarkTown_Lab/scripts.pory"

# 743 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ReceivedStarter:
# 744 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 745 "data/maps/NewBarkTown_Lab/scripts.pory"

# 746 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Nickname:
# 747 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Would you like to give your\n"
# 748 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{STR_VAR_1} a nickname?$"
# 749 "data/maps/NewBarkTown_Lab/scripts.pory"

# 750 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections1:
# 751 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon lives a little bit\n"
# 752 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "beyond Cherrygrove, the next\l"
# 753 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "city over.\p"
# 754 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's almost a direct route\n"
# 755 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "there, so you can't miss it.\p"
# 756 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But just in case, you have my\n"
# 757 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "phone number. Call me if\l"
# 758 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up!$"
# 759 "data/maps/NewBarkTown_Lab/scripts.pory"

# 760 "data/maps/NewBarkTown_Lab/scripts.pory"

# 761 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmLetYourMonBattle:
# 762 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears,\n"
# 763 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "let your Pokémon battle it!$"
# 764 "data/maps/NewBarkTown_Lab/scripts.pory"

# 765 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDirections2:
# 766 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If a wild Pokémon appears, let\n"
# 767 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "your Pokémon battle it!\p"
# 768 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If your Pokémon is hurt, you\n"
# 769 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "should heal it with the machine\l"
# 770 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to my right, or at the Pokémon Center.\p"
# 771 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm counting on you!$"
# 772 "data/maps/NewBarkTown_Lab/scripts.pory"

# 773 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_GotElmsNumber:
# 774 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} got Elm's phone\n"
# 775 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "number.$"
# 776 "data/maps/NewBarkTown_Lab/scripts.pory"

# 777 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
# 778 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Mr. Pokémon goes everywhere and\n"
# 779 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "finds rarities.\p"
# 780 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Too bad they're just rare and\n"
# 781 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "not very useful…$"
# 782 "data/maps/NewBarkTown_Lab/scripts.pory"

# 783 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmPokeBall:
# 784 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It contains Pokémon caught\n"
# 785 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "by Prof. Elm.$"
# 786 "data/maps/NewBarkTown_Lab/scripts.pory"

# 787 "data/maps/NewBarkTown_Lab/scripts.pory"
@THEFT================================================================================
# 788 "data/maps/NewBarkTown_Lab/scripts.pory"

# 789 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft1:
# 790 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, this is terrible…\p"
# 791 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, yes, what was Mr. Pokémon's\n"
# 792 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "big discovery?$"
# 793 "data/maps/NewBarkTown_Lab/scripts.pory"

# 794 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft2:
# 795 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER} handed the Mystery Egg\n"
# 796 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "to Prof. Elm.$"
# 797 "data/maps/NewBarkTown_Lab/scripts.pory"

# 798 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft3:
# 799 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: This?$"
# 800 "data/maps/NewBarkTown_Lab/scripts.pory"

# 801 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAfterTheft4:
# 802 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But… Is it a Pokémon Egg?\p"
# 803 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "If it is, it is a great\n"
# 804 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "discovery!\p"
# 805 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: What?!?\p"
# 806 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Oak gave you a Pokédex?\p"
# 807 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, is that true?\n"
# 808 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Th-that's incredible!\p"
# 809 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He is superb at seeing the\n"
# 810 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "potential of people as trainers.\p"
# 811 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, {PLAYER}. You may have what\n"
# 812 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "it takes to become the Champion.\p"
# 813 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You seem to be getting on\n"
# 814 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "great with Pokémon too.\p"
# 815 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should take the Pokémon\n"
# 816 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Gym challenge.\p"
# 817 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The closest Gym would be the\n"
# 818 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "one in Violet City.\p"
# 819 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…{PLAYER}. The road to the\n"
# 820 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "championship will be a long one.\p"
# 821 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Before you leave, make sure\n"
# 822 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that you talk to your mom.$"
# 823 "data/maps/NewBarkTown_Lab/scripts.pory"

# 824 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmStudyingEgg:
# 825 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Don't give up!\n"
# 826 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'll call if I learn anything\l"
# 827 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about that Egg!$"
# 828 "data/maps/NewBarkTown_Lab/scripts.pory"

# 829 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmAideHasEgg:
# 830 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}? Didn't you meet\n"
# 831 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "my assistant?\p"
# 832 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "He should have met you with\n"
# 833 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Egg at Violet City's\p"
# 834 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon Center.\p"
# 835 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You must have just missed him.\n"
# 836 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Try to catch him there.$"
# 837 "data/maps/NewBarkTown_Lab/scripts.pory"

# 838 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmWaitingEggHatch:
# 839 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hey, has that Egg changed\n"
# 840 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "any?$"
# 841 "data/maps/NewBarkTown_Lab/scripts.pory"

# 842 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmThoughtEggHatched:
# 843 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}? I thought the Egg\n"
# 844 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "hatched.\p"
# 845 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Where is the Pokémon?$"
# 846 "data/maps/NewBarkTown_Lab/scripts.pory"

# 847 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi1:
# 848 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, you look great!$"
# 849 "data/maps/NewBarkTown_Lab/scripts.pory"

# 850 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi2:
# 851 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What? That Pokémon!?!$"
# 852 "data/maps/NewBarkTown_Lab/scripts.pory"

# 853 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ShowTogepi3:
# 854 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Egg hatched! So, Pokémon\n"
# 855 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are born from Eggs…\p"
# 856 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "No, perhaps not all Pokémon\n"
# 857 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "are.\p"
# 858 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Wow, there's still a lot of\n"
# 859 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "research to be done.$"
# 860 "data/maps/NewBarkTown_Lab/scripts.pory"

# 861 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone1:
# 862 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks, {PLAYER}! You're helping\n"
# 863 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "unravel Pokémon mysteries for us!\p"
# 864 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I want you to have this as a\n"
# 865 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "token of our appreciation.$"
# 866 "data/maps/NewBarkTown_Lab/scripts.pory"

# 867 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveEverstone2:
# 868 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That's a Shiny Stone.\p"
# 869 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Some species of Pokémon evolve\n"
# 870 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "when they grow to certain levels.\p"
# 871 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A Togetic will evolve\n"
# 872 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "with this one.$"
# 873 "data/maps/NewBarkTown_Lab/scripts.pory"

# 874 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmCallYou:
# 875 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}, I'll call you if\n"
# 876 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "anything comes up.$"
# 877 "data/maps/NewBarkTown_Lab/scripts.pory"

# 878 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAfterTheft:
# 879 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 880 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 881 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 882 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 883 "data/maps/NewBarkTown_Lab/scripts.pory"

# 884 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall1:
# 885 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: Hi, {PLAYER}!\p"
# 886 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks to you, my research is\n"
# 887 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "going great!\p"
# 888 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Take this as a token of my\n"
# 889 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "appreciation.$"
# 890 "data/maps/NewBarkTown_Lab/scripts.pory"

# 891 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveMasterBall2:
# 892 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Master Ball is the best!\p"
# 893 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the ultimate Ball! It'll\n"
# 894 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "catch any Pokémon without fail.\p"
# 895 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's given only to recognized\n"
# 896 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon researchers.\p"
# 897 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I think you can make much better\n"
# 898 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "use of it than I can, {PLAYER}!$"
# 899 "data/maps/NewBarkTown_Lab/scripts.pory"

# 900 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoGirls:
# 901 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "By the way...\n"
# 902 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "A group of beautiful Kimono\l"
# 903 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls were looking for you.\p"
# 904 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They told me they are\n"
# 905 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "waiting for you at the\l" 
# 906 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ecruteak Dance Theater.\p"
# 907 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I know you've gone through many\n"
# 908 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "things since that Egg got you\l"
# 909 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "involved in all this...\p"
# 910 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I hope you'll carry through it.$"
# 911 "data/maps/NewBarkTown_Lab/scripts.pory"

# 912 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_KimonoWaiting:
# 913 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: The Kimono\n"
# 914 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Girls are waiting for you at\l"
# 915 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "the Ecruteak Dance Theater.$"
# 916 "data/maps/NewBarkTown_Lab/scripts.pory"

# 917 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_League:
# 918 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Prof. Elm: Hahaha...\n"
# 919 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Good job!\p"
# 920 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "That rare Egg has brought you\n"
# 921 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "a lot of trouble, huh?\p"
# 922 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The Kimono Girls said something\n"
# 923 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "about me?\p"
# 924 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I have nothing to do with it.\p"
# 925 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You made your decision and went\n"
# 926 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "through with it.\p"
# 927 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Having done so much, you should\n"
# 928 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "be able to face the League now!\p"
# 929 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You should head for Indigo\n"
# 930 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Plateau!\p"
# 931 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Do you know how to get there?\n"
# 932 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Follow Route 27 to Route 26.\p"
# 933 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Once there, go straight north!$"
# 934 "data/maps/NewBarkTown_Lab/scripts.pory"

# 935 "data/maps/NewBarkTown_Lab/scripts.pory"

# 936 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket1:
# 937 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\p"
# 938 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I called because I have\n"
# 939 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "something for you.\p"
# 940 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "See? It's an S.S.Ticket.\p"
# 941 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can catch Pokémon in\n"
# 942 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Sevii.$"
# 943 "data/maps/NewBarkTown_Lab/scripts.pory"

# 944 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_ElmGiveTicket2:
# 945 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "The ship departs from Olivine\n"
# 946 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "City.\p"
# 947 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But you knew that already,\n"
# 948 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}.\p"
# 949 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "After all, you've traveled all\n"
# 950 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "over with your Pokémon.$"
# 951 "data/maps/NewBarkTown_Lab/scripts.pory"

# 952 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_LabMonEgg:
# 953 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's the Pokémon Egg being\n"
# 954 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "studied by Prof. Elm.$"
# 955 "data/maps/NewBarkTown_Lab/scripts.pory"

# 956 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGivePotion:
# 957 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}, I want you to have\n"
# 958 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "this for your errand.$"
# 959 "data/maps/NewBarkTown_Lab/scripts.pory"

# 960 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideAlwaysBusy:
# 961 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There are only three of us, so\n"
# 962 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "we're always busy.$"
# 963 "data/maps/NewBarkTown_Lab/scripts.pory"

# 964 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideSave:
# 965 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Don't forget to save your game\n"
# 966 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "regularly!\p"
# 967 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Press the Start button, then\n"
# 968 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Save the game!$"
# 969 "data/maps/NewBarkTown_Lab/scripts.pory"

# 970 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideTheftTestimony:
# 971 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "There was a loud noise\n"
# 972 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "outside…\p"
# 973 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "When we went to look,\n"
# 974 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "someone stole a Pokémon.\p"
# 975 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's unbelievable that anyone\n"
# 976 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "would do that!\p"
# 977 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "…sigh… That stolen Pokémon.\p"
# 978 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I wonder how it's doing.\p"
# 979 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "They say a Pokémon raised by a\n"
# 980 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "bad person turns bad itself.$"
# 981 "data/maps/NewBarkTown_Lab/scripts.pory"

# 982 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideGiveBalls:
# 983 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "{PLAYER}!\p"
# 984 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Use these on your Pokédex\n"
# 985 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "quest!$"
# 986 "data/maps/NewBarkTown_Lab/scripts.pory"

# 987 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_AideExplainBalls:
# 988 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "To add to your Pokédex, you\n"
# 989 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "have to catch Pokémon.\p"
# 990 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Throw Poké Balls at wild\n"
# 991 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Pokémon to get them.$"
# 992 "data/maps/NewBarkTown_Lab/scripts.pory"

# 993 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer1:
# 994 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I heard a Pokémon was stolen\n"
# 995 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "here…\p"
# 996 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I was just getting some\n"
# 997 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "information from Prof. Elm.\p"
# 998 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Apparently, it was a young\n"
# 999 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "male with long, red hair…\p"
# 1000 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "What?\p"
# 1001 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "You battled a trainer like\n"
# 1002 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "that?\p"
# 1003 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Did you happen to get his\n"
# 1004 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "name?$"
# 1005 "data/maps/NewBarkTown_Lab/scripts.pory"

# 1006 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer2:
# 1007 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So Silver was his name.\p"
# 1008 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 1009 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 1010 "data/maps/NewBarkTown_Lab/scripts.pory"

# 1011 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Officer3:
# 1012 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ok! So {RIVAL} was his name.\p"
# 1013 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Thanks for helping my\n"
# 1014 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "investigation!$"
# 1015 "data/maps/NewBarkTown_Lab/scripts.pory"

# 1016 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_OfficerNo:
# 1017 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Surely you got his name?!$"
# 1018 "data/maps/NewBarkTown_Lab/scripts.pory"

# 1019 "data/maps/NewBarkTown_Lab/scripts.pory"
NewBarkTown_Lab_Text_Elm_CallMe:
# 1020 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Ah, {PLAYER}!\p"
# 1021 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "How's your Pokédex coming along?\n"
# 1022 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I'm busy now, but call me sometime\l"
# 1023 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "and I can check your progress!$"

NewBarkTown_Lab_GiveStarterMega::
# 1027 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_0
# 1031 "data/maps/NewBarkTown_Lab/scripts.pory"
	giveitem ITEM_BONDSTONE, 1
# 1032 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_GiveStarterMega_Text_1
	return


NewBarkTown_Lab_EventScript_ElmPostgameHint::
# 1039 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0
# 1048 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_1
# 1050 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1051 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1052 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1053 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1054 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_CLICK
# 1055 "data/maps/NewBarkTown_Lab/scripts.pory"
	delay 10
# 1056 "data/maps/NewBarkTown_Lab/scripts.pory"
	playse SE_PIN
# 1057 "data/maps/NewBarkTown_Lab/scripts.pory"
	waitse
# 1058 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2
# 1064 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_POSTGAME_FEATURES
# 1065 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_VICTORYROAD_RIVAL
# 1066 "data/maps/NewBarkTown_Lab/scripts.pory"
	checkplayergender
# 1067 "data/maps/NewBarkTown_Lab/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_Lab_EventScript_ElmPostgameHint_2
# 1076 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4
NewBarkTown_Lab_EventScript_ElmPostgameHint_1:
# 1084 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5
# 1086 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_HIDE_MTSILVER_GUARD
# 1087 "data/maps/NewBarkTown_Lab/scripts.pory"
	setflag FLAG_ALLOW_SOUTH_JOHTO_PASS
# 1088 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
# 1089 "data/maps/NewBarkTown_Lab/scripts.pory"
	setvar VAR_NEWBARK_TOWN_STATE, 11
# 1090 "data/maps/NewBarkTown_Lab/scripts.pory"
	release
	end

NewBarkTown_Lab_EventScript_ElmPostgameHint_2:
# 1068 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3
	goto NewBarkTown_Lab_EventScript_ElmPostgameHint_1


ElmIntro::
# 1095 "data/maps/NewBarkTown_Lab/scripts.pory"
	msgbox ElmIntro_Text_0, MSGBOX_YESNO
	return


NewBarkTown_Lab_GiveStarterMega_Text_0:
# 1027 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Oh, and you got a Mega Ring from \n"
	.string "Prof. Oak?\l"
	.string "Then I think you are ready to handle\l"
	.string "this.$"

NewBarkTown_Lab_GiveStarterMega_Text_1:
# 1032 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "It's a special Mega Stone, specifically\n"
	.string "for your starter Pokémon. I expect \l"
	.string "great things from you, {PLAYER}!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_0:
# 1039 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Elm: {PLAYER}! There you are!\n"
	.string "I called because I heard that the \l"
	.string "Battle Tower is open! \p"
	.string "I hear strong trainers\n"
	.string "are gathering in there!\p"
	.string "You can get there from Route 40\n"
	.string "near Olivine City.$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_1:
# 1048 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "But first, let me upgrade your Pokédex\n"
	.string "with a new feature!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_2:
# 1058 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "Now you can view abilities of the\n"
	.string "opposing Pokémon with the L-button\l"
	.string "in battle! \p"
	.string "That will surely be handy as the\n"
	.string "battles get tougher!$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_3:
# 1068 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Crystal went to train\n"
	.string "in Mt. Silver. \p"
	.string "She looked really tired\n"
	.string "the last time I saw her though... \p"
	.string "Could you check on her at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_4:
# 1076 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I also heard that Gold went to train\n"
	.string "in Mt. Silver. \p"
	.string "He looked really tired\n"
	.string "the last time I saw him though...\p"
	.string "Could you check on him at some point?$"

NewBarkTown_Lab_EventScript_ElmPostgameHint_Text_5:
# 1084 "data/maps/NewBarkTown_Lab/scripts.pory"
	.string "I asked from the League to let you\n"
	.string "pass since you've the new Champion.$"

ElmIntro_Text_0:
# 1095 "data/maps/NewBarkTown_Lab/scripts.pory"
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
