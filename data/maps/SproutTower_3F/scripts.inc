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
    fadedefaultbgm
# 53 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 54 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 55 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 56 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 57 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 58 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 60 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 61 "data/maps/SproutTower_3F/scripts.pory"
	release
# 62 "data/maps/SproutTower_3F/scripts.pory"
	end
# 63 "data/maps/SproutTower_3F/scripts.pory"

# 64 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_TriggerSceneRight::
# 65 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 66 "data/maps/SproutTower_3F/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 67 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
# 68 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 69 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
# 70 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 71 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_PIN
# 72 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
# 73 "data/maps/SproutTower_3F/scripts.pory"
	delay 60
# 74 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
# 75 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 76 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 77 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
# 78 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
# 79 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
# 80 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 81 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 82 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 83 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 84 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 85 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 86 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 87 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 88 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 89 "data/maps/SproutTower_3F/scripts.pory"
	fadedefaultbgm
# 90 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 91 "data/maps/SproutTower_3F/scripts.pory"
	release
# 92 "data/maps/SproutTower_3F/scripts.pory"
	end
# 93 "data/maps/SproutTower_3F/scripts.pory"

# 94 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi::
# 95 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 96 "data/maps/SproutTower_3F/scripts.pory"
	faceplayer
# 97 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
# 98 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
# 99 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 100 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
# 101 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
# 102 "data/maps/SproutTower_3F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 103 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 104 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
# 105 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 106 "data/maps/SproutTower_3F/scripts.pory"
	release
# 107 "data/maps/SproutTower_3F/scripts.pory"
	end
# 108 "data/maps/SproutTower_3F/scripts.pory"

# 109 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi_Beaten::
# 110 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
# 111 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 112 "data/maps/SproutTower_3F/scripts.pory"
	release
# 113 "data/maps/SproutTower_3F/scripts.pory"
	end
# 114 "data/maps/SproutTower_3F/scripts.pory"

# 115 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_Silver1:
# 116 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 117 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 118 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 119 "data/maps/SproutTower_3F/scripts.pory"

# 120 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverLeft:
# 121 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 122 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 123 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 124 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 125 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 126 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 127 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 128 "data/maps/SproutTower_3F/scripts.pory"

# 129 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverRight:
# 130 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 131 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 132 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 133 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 134 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 135 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 136 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 137 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 138 "data/maps/SproutTower_3F/scripts.pory"

# 139 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_EscapeRope:
# 140 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 141 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 142 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 143 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 144 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 145 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 146 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 147 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 148 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 149 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 150 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 151 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 152 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 153 "data/maps/SproutTower_3F/scripts.pory"

# 154 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_ElderLecturesRival:
# 155 "data/maps/SproutTower_3F/scripts.pory"
	.string "Elder: You are indeed skilled\n"
# 156 "data/maps/SproutTower_3F/scripts.pory"
	.string "as a trainer.\p"
# 157 "data/maps/SproutTower_3F/scripts.pory"
	.string "As promised, here is your HM.\p"
# 158 "data/maps/SproutTower_3F/scripts.pory"
	.string "But let me say this: You should\n"
# 159 "data/maps/SproutTower_3F/scripts.pory"
	.string "treat your Pokémon better.\p"
# 160 "data/maps/SproutTower_3F/scripts.pory"
	.string "The way you battle is far too\n"
# 161 "data/maps/SproutTower_3F/scripts.pory"
	.string "harsh.\p"
# 162 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon are not tools of war…$"
# 163 "data/maps/SproutTower_3F/scripts.pory"

# 164 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalOnlyCaresStrong:
# 165 "data/maps/SproutTower_3F/scripts.pory"
	.string "…\n"
# 166 "data/maps/SproutTower_3F/scripts.pory"
	.string "…Humph!\p"
# 167 "data/maps/SproutTower_3F/scripts.pory"
	.string "He claims to be the Elder but\n"
# 168 "data/maps/SproutTower_3F/scripts.pory"
	.string "he's weak.\p"
# 169 "data/maps/SproutTower_3F/scripts.pory"
	.string "It stands to reason.\p"
# 170 "data/maps/SproutTower_3F/scripts.pory"
	.string "I'd never lose to fools who babble\n"
# 171 "data/maps/SproutTower_3F/scripts.pory"
	.string "about being nice to Pokémon.\p"
# 172 "data/maps/SproutTower_3F/scripts.pory"
	.string "I only care about strong\n"
# 173 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon that can win.\p"
# 174 "data/maps/SproutTower_3F/scripts.pory"
	.string "I really couldn't care less\n"
# 175 "data/maps/SproutTower_3F/scripts.pory"
	.string "about weak Pokémon.$"
# 176 "data/maps/SproutTower_3F/scripts.pory"

# 177 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalUsedEscapeRope:
# 178 "data/maps/SproutTower_3F/scripts.pory"
	.string "{RIVAL} used an Escape Rope!$"
# 179 "data/maps/SproutTower_3F/scripts.pory"

# 180 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Seen:
# 181 "data/maps/SproutTower_3F/scripts.pory"
	.string "So good of you to come here!\p"
# 182 "data/maps/SproutTower_3F/scripts.pory"
	.string "Sprout Tower is a place of\n"
# 183 "data/maps/SproutTower_3F/scripts.pory"
	.string "training.\p"
# 184 "data/maps/SproutTower_3F/scripts.pory"
	.string "People and Pokémon test their\n"
# 185 "data/maps/SproutTower_3F/scripts.pory"
	.string "bonds to build a bright future\l"
# 186 "data/maps/SproutTower_3F/scripts.pory"
	.string "together.\p"
# 187 "data/maps/SproutTower_3F/scripts.pory"
	.string "I am the final test.\p"
# 188 "data/maps/SproutTower_3F/scripts.pory"
	.string "Allow me to check the ties\n"
# 189 "data/maps/SproutTower_3F/scripts.pory"
	.string "between your Pokémon and you!$"
# 190 "data/maps/SproutTower_3F/scripts.pory"

# 191 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Beaten:
# 192 "data/maps/SproutTower_3F/scripts.pory"
	.string "Ah, excellent!$"
# 193 "data/maps/SproutTower_3F/scripts.pory"

# 194 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_TakeFlash:
# 195 "data/maps/SproutTower_3F/scripts.pory"
	.string "You and your Pokémon should\n"
# 196 "data/maps/SproutTower_3F/scripts.pory"
	.string "have no problem using this move.\p"
# 197 "data/maps/SproutTower_3F/scripts.pory"
	.string "Take this Flash HM.$"
# 198 "data/maps/SproutTower_3F/scripts.pory"

# 199 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_FlashExplain:
# 200 "data/maps/SproutTower_3F/scripts.pory"
	.string "Flash illuminates even the\n"
# 201 "data/maps/SproutTower_3F/scripts.pory"
	.string "darkest of all places.\p"
# 202 "data/maps/SproutTower_3F/scripts.pory"
	.string "But to use it out of battle, you\n"
# 203 "data/maps/SproutTower_3F/scripts.pory"
	.string "need the Badge from Violet'S Gym.$"
# 204 "data/maps/SproutTower_3F/scripts.pory"

# 205 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_AfterBattle:
# 206 "data/maps/SproutTower_3F/scripts.pory"
	.string "I hope you learn and grow from\n"
# 207 "data/maps/SproutTower_3F/scripts.pory"
	.string "your journey.$"
# 208 "data/maps/SproutTower_3F/scripts.pory"

# 209 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Seen:
# 210 "data/maps/SproutTower_3F/scripts.pory"
	.string "I train to find enlightenment\n"
# 211 "data/maps/SproutTower_3F/scripts.pory"
	.string "in Pokémon!$"
# 212 "data/maps/SproutTower_3F/scripts.pory"

# 213 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Beaten:
# 214 "data/maps/SproutTower_3F/scripts.pory"
	.string "My training is incomplete…$"
# 215 "data/maps/SproutTower_3F/scripts.pory"

# 216 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_AfterBattle:
# 217 "data/maps/SproutTower_3F/scripts.pory"
	.string "As Pokémon grow stronger,\n"
# 218 "data/maps/SproutTower_3F/scripts.pory"
	.string "so does the trainer.\p"
# 219 "data/maps/SproutTower_3F/scripts.pory"
	.string "No, wait. As the trainer\n"
# 220 "data/maps/SproutTower_3F/scripts.pory"
	.string "grows stronger, so do the\l"
# 221 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon.$"
# 222 "data/maps/SproutTower_3F/scripts.pory"

# 223 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Seen:
# 224 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let me see how much you trust\n"
# 225 "data/maps/SproutTower_3F/scripts.pory"
	.string "your Pokémon.$"
# 226 "data/maps/SproutTower_3F/scripts.pory"

# 227 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Beaten:
# 228 "data/maps/SproutTower_3F/scripts.pory"
	.string "Yes, your trust is real!$"
# 229 "data/maps/SproutTower_3F/scripts.pory"

# 230 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_AfterBattle:
# 231 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is not far to the Elder.$"
# 232 "data/maps/SproutTower_3F/scripts.pory"

# 233 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Seen:
# 234 "data/maps/SproutTower_3F/scripts.pory"
	.string "The Elder's HM lights even\n"
# 235 "data/maps/SproutTower_3F/scripts.pory"
	.string "pitch-black darkness.$"
# 236 "data/maps/SproutTower_3F/scripts.pory"

# 237 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Beaten:
# 238 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is my head that is bright!$"
# 239 "data/maps/SproutTower_3F/scripts.pory"

# 240 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_AfterBattle:
# 241 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let there be light on your\n"
# 242 "data/maps/SproutTower_3F/scripts.pory"
	.string "journey.$"
# 243 "data/maps/SproutTower_3F/scripts.pory"

# 244 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_3F_Painting:
# 245 "data/maps/SproutTower_3F/scripts.pory"
	.string "It's a powerful painting of a\n"
# 246 "data/maps/SproutTower_3F/scripts.pory"
	.string "Bellsprout.$"

ElderPostgame::
# 253 "data/maps/SproutTower_3F/scripts.pory"
	release
	end

