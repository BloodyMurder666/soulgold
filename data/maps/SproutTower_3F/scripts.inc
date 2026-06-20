# 1 "data/maps/SproutTower_3F/scripts.pory"

# 2 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_MapScripts::
# 3 "data/maps/SproutTower_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
# 4 "data/maps/SproutTower_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/SproutTower_3F/scripts.pory"
	.byte 0
# 6 "data/maps/SproutTower_3F/scripts.pory"

# 7 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_OnTransition: 
# 8 "data/maps/SproutTower_3F/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/SproutTower_3F/scripts.pory"
	end
# 10 "data/maps/SproutTower_3F/scripts.pory"

# 11 "data/maps/SproutTower_3F/scripts.pory"

# 12 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageJin::
# 13 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_single TRAINER_JIN SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
# 14 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
# 15 "data/maps/SproutTower_3F/scripts.pory"
	end
# 16 "data/maps/SproutTower_3F/scripts.pory"

# 17 "data/maps/SproutTower_3F/scripts.pory"

# 18 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageNeal::
# 19 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_single TRAINER_NEAL SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
# 20 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
# 21 "data/maps/SproutTower_3F/scripts.pory"
	end
# 22 "data/maps/SproutTower_3F/scripts.pory"

# 23 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageTroy::
# 24 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_single TRAINER_TROY SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
# 25 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
# 26 "data/maps/SproutTower_3F/scripts.pory"
	end
# 27 "data/maps/SproutTower_3F/scripts.pory"

# 28 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_Painting::
# 29 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 30 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
# 31 "data/maps/SproutTower_3F/scripts.pory"
	release
# 32 "data/maps/SproutTower_3F/scripts.pory"
	end
# 33 "data/maps/SproutTower_3F/scripts.pory"

# 34 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_TriggerSceneLeft::
# 35 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 36 "data/maps/SproutTower_3F/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 37 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
# 38 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 39 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
# 40 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 41 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_PIN
# 42 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
# 43 "data/maps/SproutTower_3F/scripts.pory"
	delay 60
# 44 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
# 45 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 46 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
# 47 "data/maps/SproutTower_3F/scripts.pory"
	delay 30
# 48 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
# 49 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
# 50 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 51 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 52 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 53 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 54 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 55 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 56 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 57 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 58 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 59 "data/maps/SproutTower_3F/scripts.pory"
	delay 15
# 60 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 61 "data/maps/SproutTower_3F/scripts.pory"
	fadedefaultbgm
# 62 "data/maps/SproutTower_3F/scripts.pory"
	release
# 63 "data/maps/SproutTower_3F/scripts.pory"
	end
# 64 "data/maps/SproutTower_3F/scripts.pory"

# 65 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_TriggerSceneRight::
# 66 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 67 "data/maps/SproutTower_3F/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 68 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
# 69 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 70 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
# 71 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 72 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_PIN
# 73 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
# 74 "data/maps/SproutTower_3F/scripts.pory"
	delay 60
# 75 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
# 76 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 77 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 78 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
# 79 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
# 80 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
# 81 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 82 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 83 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 84 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 85 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 86 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 87 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 88 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 89 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 90 "data/maps/SproutTower_3F/scripts.pory"
	delay 15
# 91 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 92 "data/maps/SproutTower_3F/scripts.pory"
	savebgm MUS_DUMMY
# 93 "data/maps/SproutTower_3F/scripts.pory"
	fadedefaultbgm
# 94 "data/maps/SproutTower_3F/scripts.pory"
	release
# 95 "data/maps/SproutTower_3F/scripts.pory"
	end
# 96 "data/maps/SproutTower_3F/scripts.pory"

# 97 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi::
# 98 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 99 "data/maps/SproutTower_3F/scripts.pory"
	faceplayer
# 100 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
# 101 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
# 102 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 103 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
# 104 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
# 105 "data/maps/SproutTower_3F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 106 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 107 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
# 108 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 109 "data/maps/SproutTower_3F/scripts.pory"
	release
# 110 "data/maps/SproutTower_3F/scripts.pory"
	end
# 111 "data/maps/SproutTower_3F/scripts.pory"

# 112 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi_Beaten::
# 113 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
# 114 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 115 "data/maps/SproutTower_3F/scripts.pory"
	release
# 116 "data/maps/SproutTower_3F/scripts.pory"
	end
# 117 "data/maps/SproutTower_3F/scripts.pory"

# 118 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_Silver1:
# 119 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 120 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 121 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 122 "data/maps/SproutTower_3F/scripts.pory"

# 123 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverLeft:
# 124 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 125 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 126 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 127 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 128 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 129 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 130 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 131 "data/maps/SproutTower_3F/scripts.pory"

# 132 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverRight:
# 133 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 134 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 135 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 136 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 137 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 138 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 139 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 140 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 141 "data/maps/SproutTower_3F/scripts.pory"

# 142 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_EscapeRope:
# 143 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 144 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 145 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 146 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 147 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 148 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 149 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 150 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 151 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 152 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 153 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 154 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 155 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 156 "data/maps/SproutTower_3F/scripts.pory"

# 157 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_ElderLecturesRival:
# 158 "data/maps/SproutTower_3F/scripts.pory"
	.string "Elder: You are indeed skilled\n"
# 159 "data/maps/SproutTower_3F/scripts.pory"
	.string "as a trainer.\p"
# 160 "data/maps/SproutTower_3F/scripts.pory"
	.string "As promised, here is your HM.\p"
# 161 "data/maps/SproutTower_3F/scripts.pory"
	.string "But let me say this: You should\n"
# 162 "data/maps/SproutTower_3F/scripts.pory"
	.string "treat your Pokémon better.\p"
# 163 "data/maps/SproutTower_3F/scripts.pory"
	.string "The way you battle is far too\n"
# 164 "data/maps/SproutTower_3F/scripts.pory"
	.string "harsh.\p"
# 165 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon are not tools of war…$"
# 166 "data/maps/SproutTower_3F/scripts.pory"

# 167 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalOnlyCaresStrong:
# 168 "data/maps/SproutTower_3F/scripts.pory"
	.string "…\n"
# 169 "data/maps/SproutTower_3F/scripts.pory"
	.string "…Humph!\p"
# 170 "data/maps/SproutTower_3F/scripts.pory"
	.string "He claims to be the Elder but\n"
# 171 "data/maps/SproutTower_3F/scripts.pory"
	.string "he's weak.\p"
# 172 "data/maps/SproutTower_3F/scripts.pory"
	.string "It stands to reason.\p"
# 173 "data/maps/SproutTower_3F/scripts.pory"
	.string "I'd never lose to fools who babble\n"
# 174 "data/maps/SproutTower_3F/scripts.pory"
	.string "about being nice to Pokémon.\p"
# 175 "data/maps/SproutTower_3F/scripts.pory"
	.string "I only care about strong\n"
# 176 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon that can win.\p"
# 177 "data/maps/SproutTower_3F/scripts.pory"
	.string "I really couldn't care less\n"
# 178 "data/maps/SproutTower_3F/scripts.pory"
	.string "about weak Pokémon.$"
# 179 "data/maps/SproutTower_3F/scripts.pory"

# 180 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalUsedEscapeRope:
# 181 "data/maps/SproutTower_3F/scripts.pory"
	.string "{RIVAL} used an Escape Rope!$"
# 182 "data/maps/SproutTower_3F/scripts.pory"

# 183 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Seen:
# 184 "data/maps/SproutTower_3F/scripts.pory"
	.string "So good of you to come here!\p"
# 185 "data/maps/SproutTower_3F/scripts.pory"
	.string "Sprout Tower is a place of\n"
# 186 "data/maps/SproutTower_3F/scripts.pory"
	.string "training.\p"
# 187 "data/maps/SproutTower_3F/scripts.pory"
	.string "People and Pokémon test their\n"
# 188 "data/maps/SproutTower_3F/scripts.pory"
	.string "bonds to build a bright future\l"
# 189 "data/maps/SproutTower_3F/scripts.pory"
	.string "together.\p"
# 190 "data/maps/SproutTower_3F/scripts.pory"
	.string "I am the final test.\p"
# 191 "data/maps/SproutTower_3F/scripts.pory"
	.string "Allow me to check the ties\n"
# 192 "data/maps/SproutTower_3F/scripts.pory"
	.string "between your Pokémon and you!$"
# 193 "data/maps/SproutTower_3F/scripts.pory"

# 194 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Beaten:
# 195 "data/maps/SproutTower_3F/scripts.pory"
	.string "Ah, excellent!$"
# 196 "data/maps/SproutTower_3F/scripts.pory"

# 197 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_TakeFlash:
# 198 "data/maps/SproutTower_3F/scripts.pory"
	.string "You and your Pokémon should\n"
# 199 "data/maps/SproutTower_3F/scripts.pory"
	.string "have no problem using this move.\p"
# 200 "data/maps/SproutTower_3F/scripts.pory"
	.string "Take this Flash HM.$"
# 201 "data/maps/SproutTower_3F/scripts.pory"

# 202 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_FlashExplain:
# 203 "data/maps/SproutTower_3F/scripts.pory"
	.string "Flash illuminates even the\n"
# 204 "data/maps/SproutTower_3F/scripts.pory"
	.string "darkest of all places.\p"
# 205 "data/maps/SproutTower_3F/scripts.pory"
	.string "But to use it out of battle, you\n"
# 206 "data/maps/SproutTower_3F/scripts.pory"
	.string "need the Badge from Violet's Gym.$"
# 207 "data/maps/SproutTower_3F/scripts.pory"

# 208 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_AfterBattle:
# 209 "data/maps/SproutTower_3F/scripts.pory"
	.string "I hope you learn and grow from\n"
# 210 "data/maps/SproutTower_3F/scripts.pory"
	.string "your journey.$"
# 211 "data/maps/SproutTower_3F/scripts.pory"

# 212 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Seen:
# 213 "data/maps/SproutTower_3F/scripts.pory"
	.string "I train to find enlightenment\n"
# 214 "data/maps/SproutTower_3F/scripts.pory"
	.string "in Pokémon!$"
# 215 "data/maps/SproutTower_3F/scripts.pory"

# 216 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Beaten:
# 217 "data/maps/SproutTower_3F/scripts.pory"
	.string "My training is incomplete…$"
# 218 "data/maps/SproutTower_3F/scripts.pory"

# 219 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_AfterBattle:
# 220 "data/maps/SproutTower_3F/scripts.pory"
	.string "As Pokémon grow stronger,\n"
# 221 "data/maps/SproutTower_3F/scripts.pory"
	.string "so does the trainer.\p"
# 222 "data/maps/SproutTower_3F/scripts.pory"
	.string "No, wait. As the trainer\n"
# 223 "data/maps/SproutTower_3F/scripts.pory"
	.string "grows stronger, so do the\l"
# 224 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon.$"
# 225 "data/maps/SproutTower_3F/scripts.pory"

# 226 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Seen:
# 227 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let me see how much you trust\n"
# 228 "data/maps/SproutTower_3F/scripts.pory"
	.string "your Pokémon.$"
# 229 "data/maps/SproutTower_3F/scripts.pory"

# 230 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Beaten:
# 231 "data/maps/SproutTower_3F/scripts.pory"
	.string "Yes, your trust is real!$"
# 232 "data/maps/SproutTower_3F/scripts.pory"

# 233 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_AfterBattle:
# 234 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is not far to the Elder.$"
# 235 "data/maps/SproutTower_3F/scripts.pory"

# 236 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Seen:
# 237 "data/maps/SproutTower_3F/scripts.pory"
	.string "The Elder's HM lights even\n"
# 238 "data/maps/SproutTower_3F/scripts.pory"
	.string "pitch-black darkness.$"
# 239 "data/maps/SproutTower_3F/scripts.pory"

# 240 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Beaten:
# 241 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is my head that is bright!$"
# 242 "data/maps/SproutTower_3F/scripts.pory"

# 243 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_AfterBattle:
# 244 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let there be light on your\n"
# 245 "data/maps/SproutTower_3F/scripts.pory"
	.string "journey.$"
# 246 "data/maps/SproutTower_3F/scripts.pory"

# 247 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_3F_Painting:
# 248 "data/maps/SproutTower_3F/scripts.pory"
	.string "It's a powerful painting of a\n"
# 249 "data/maps/SproutTower_3F/scripts.pory"
	.string "Bellsprout.$"

ElderPostgame::
# 256 "data/maps/SproutTower_3F/scripts.pory"
	release
	end

