.set LOCALID_INDIGOJUNCTION_POLICEMAN, 1
.set LOCALID_INDIGOJUNCTION_JANINE, 4

ReceptionGate_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "Jaine: I'm on the way to my dad's\n"
    .string "house to give him his lunch.\p"
    .string "The Elite Four has no time to rest\n"
    .string "day or night. It's such hard work,\l"
    .string "you know?\p"
    .string "If you're ready for another battle,\n"
    .string "I'll be at the Dojo later.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 20
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 7, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Only trainers who have proven\n"
    .string "themselves may pass.$"

VictoryRoadGate_Text_Kimono:
    .string "Sorry kid, this way is closed until\n"
    .string "someone deals with that Legendary\l"
    .string "POKéMON...$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "You don't have all the Gym Badges\n"
    .string "of Johto.\p"
    .string "I'm sorry, but I can't let you go\n"
    .string "through.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh! The eight Badges of Johto!\p"
    .string "Please, go right on through!$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "This way leads to Mt.Silver.\p"
    .string "You'll see scary-strong POKéMON out\n"
    .string "there.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Off to the POKéMON League, are you?\p"
    .string "The Elite Four are so strong it's\n"
    .string "scary, and they're ready for you!$"
