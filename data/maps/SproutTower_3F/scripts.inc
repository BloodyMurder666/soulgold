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
	fadedefaultbgm
# 93 "data/maps/SproutTower_3F/scripts.pory"
	release
# 94 "data/maps/SproutTower_3F/scripts.pory"
	end
# 95 "data/maps/SproutTower_3F/scripts.pory"

# 96 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi::
# 97 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 98 "data/maps/SproutTower_3F/scripts.pory"
	faceplayer
# 99 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
# 100 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
# 101 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 102 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
# 103 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
# 104 "data/maps/SproutTower_3F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 105 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 106 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
# 107 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 108 "data/maps/SproutTower_3F/scripts.pory"
	release
# 109 "data/maps/SproutTower_3F/scripts.pory"
	end
# 110 "data/maps/SproutTower_3F/scripts.pory"

# 111 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi_Beaten::
# 112 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
# 113 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 114 "data/maps/SproutTower_3F/scripts.pory"
	release
# 115 "data/maps/SproutTower_3F/scripts.pory"
	end
# 116 "data/maps/SproutTower_3F/scripts.pory"

# 117 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_Silver1:
# 118 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 119 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 120 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 121 "data/maps/SproutTower_3F/scripts.pory"

# 122 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverLeft:
# 123 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 124 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 125 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 126 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 127 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 128 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 129 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 130 "data/maps/SproutTower_3F/scripts.pory"

# 131 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverRight:
# 132 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 133 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 134 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 135 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 136 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 137 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 138 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 139 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 140 "data/maps/SproutTower_3F/scripts.pory"

# 141 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_EscapeRope:
# 142 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 143 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 144 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 145 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 146 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 147 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 148 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 149 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 150 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 151 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 152 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 153 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 154 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 155 "data/maps/SproutTower_3F/scripts.pory"

# 156 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_ElderLecturesRival:
# 157 "data/maps/SproutTower_3F/scripts.pory"
	.string "Elder: You are indeed skilled\n"
# 158 "data/maps/SproutTower_3F/scripts.pory"
	.string "as a trainer.\p"
# 159 "data/maps/SproutTower_3F/scripts.pory"
	.string "As promised, here is your HM.\p"
# 160 "data/maps/SproutTower_3F/scripts.pory"
	.string "But let me say this: You should\n"
# 161 "data/maps/SproutTower_3F/scripts.pory"
	.string "treat your Pokémon better.\p"
# 162 "data/maps/SproutTower_3F/scripts.pory"
	.string "The way you battle is far too\n"
# 163 "data/maps/SproutTower_3F/scripts.pory"
	.string "harsh.\p"
# 164 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon are not tools of war…$"
# 165 "data/maps/SproutTower_3F/scripts.pory"

# 166 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalOnlyCaresStrong:
# 167 "data/maps/SproutTower_3F/scripts.pory"
	.string "…\n"
# 168 "data/maps/SproutTower_3F/scripts.pory"
	.string "…Humph!\p"
# 169 "data/maps/SproutTower_3F/scripts.pory"
	.string "He claims to be the Elder but\n"
# 170 "data/maps/SproutTower_3F/scripts.pory"
	.string "he's weak.\p"
# 171 "data/maps/SproutTower_3F/scripts.pory"
	.string "It stands to reason.\p"
# 172 "data/maps/SproutTower_3F/scripts.pory"
	.string "I'd never lose to fools who babble\n"
# 173 "data/maps/SproutTower_3F/scripts.pory"
	.string "about being nice to Pokémon.\p"
# 174 "data/maps/SproutTower_3F/scripts.pory"
	.string "I only care about strong\n"
# 175 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon that can win.\p"
# 176 "data/maps/SproutTower_3F/scripts.pory"
	.string "I really couldn't care less\n"
# 177 "data/maps/SproutTower_3F/scripts.pory"
	.string "about weak Pokémon.$"
# 178 "data/maps/SproutTower_3F/scripts.pory"

# 179 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalUsedEscapeRope:
# 180 "data/maps/SproutTower_3F/scripts.pory"
	.string "{RIVAL} used an Escape Rope!$"
# 181 "data/maps/SproutTower_3F/scripts.pory"

# 182 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Seen:
# 183 "data/maps/SproutTower_3F/scripts.pory"
	.string "So good of you to come here!\p"
# 184 "data/maps/SproutTower_3F/scripts.pory"
	.string "Sprout Tower is a place of\n"
# 185 "data/maps/SproutTower_3F/scripts.pory"
	.string "training.\p"
# 186 "data/maps/SproutTower_3F/scripts.pory"
	.string "People and Pokémon test their\n"
# 187 "data/maps/SproutTower_3F/scripts.pory"
	.string "bonds to build a bright future\l"
# 188 "data/maps/SproutTower_3F/scripts.pory"
	.string "together.\p"
# 189 "data/maps/SproutTower_3F/scripts.pory"
	.string "I am the final test.\p"
# 190 "data/maps/SproutTower_3F/scripts.pory"
	.string "Allow me to check the ties\n"
# 191 "data/maps/SproutTower_3F/scripts.pory"
	.string "between your Pokémon and you!$"
# 192 "data/maps/SproutTower_3F/scripts.pory"

# 193 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Beaten:
# 194 "data/maps/SproutTower_3F/scripts.pory"
	.string "Ah, excellent!$"
# 195 "data/maps/SproutTower_3F/scripts.pory"

# 196 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_TakeFlash:
# 197 "data/maps/SproutTower_3F/scripts.pory"
	.string "You and your Pokémon should\n"
# 198 "data/maps/SproutTower_3F/scripts.pory"
	.string "have no problem using this move.\p"
# 199 "data/maps/SproutTower_3F/scripts.pory"
	.string "Take this Flash HM.$"
# 200 "data/maps/SproutTower_3F/scripts.pory"

# 201 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_FlashExplain:
# 202 "data/maps/SproutTower_3F/scripts.pory"
	.string "Flash illuminates even the\n"
# 203 "data/maps/SproutTower_3F/scripts.pory"
	.string "darkest of all places.\p"
# 204 "data/maps/SproutTower_3F/scripts.pory"
	.string "But to use it out of battle, you\n"
# 205 "data/maps/SproutTower_3F/scripts.pory"
	.string "need the Badge from Violet's Gym.$"
# 206 "data/maps/SproutTower_3F/scripts.pory"

# 207 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_AfterBattle:
# 208 "data/maps/SproutTower_3F/scripts.pory"
	.string "I hope you learn and grow from\n"
# 209 "data/maps/SproutTower_3F/scripts.pory"
	.string "your journey.$"
# 210 "data/maps/SproutTower_3F/scripts.pory"

# 211 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Seen:
# 212 "data/maps/SproutTower_3F/scripts.pory"
	.string "I train to find enlightenment\n"
# 213 "data/maps/SproutTower_3F/scripts.pory"
	.string "in Pokémon!$"
# 214 "data/maps/SproutTower_3F/scripts.pory"

# 215 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Beaten:
# 216 "data/maps/SproutTower_3F/scripts.pory"
	.string "My training is incomplete…$"
# 217 "data/maps/SproutTower_3F/scripts.pory"

# 218 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_AfterBattle:
# 219 "data/maps/SproutTower_3F/scripts.pory"
	.string "As Pokémon grow stronger,\n"
# 220 "data/maps/SproutTower_3F/scripts.pory"
	.string "so does the trainer.\p"
# 221 "data/maps/SproutTower_3F/scripts.pory"
	.string "No, wait. As the trainer\n"
# 222 "data/maps/SproutTower_3F/scripts.pory"
	.string "grows stronger, so do the\l"
# 223 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon.$"
# 224 "data/maps/SproutTower_3F/scripts.pory"

# 225 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Seen:
# 226 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let me see how much you trust\n"
# 227 "data/maps/SproutTower_3F/scripts.pory"
	.string "your Pokémon.$"
# 228 "data/maps/SproutTower_3F/scripts.pory"

# 229 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Beaten:
# 230 "data/maps/SproutTower_3F/scripts.pory"
	.string "Yes, your trust is real!$"
# 231 "data/maps/SproutTower_3F/scripts.pory"

# 232 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_AfterBattle:
# 233 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is not far to the Elder.$"
# 234 "data/maps/SproutTower_3F/scripts.pory"

# 235 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Seen:
# 236 "data/maps/SproutTower_3F/scripts.pory"
	.string "The Elder's HM lights even\n"
# 237 "data/maps/SproutTower_3F/scripts.pory"
	.string "pitch-black darkness.$"
# 238 "data/maps/SproutTower_3F/scripts.pory"

# 239 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Beaten:
# 240 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is my head that is bright!$"
# 241 "data/maps/SproutTower_3F/scripts.pory"

# 242 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_AfterBattle:
# 243 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let there be light on your\n"
# 244 "data/maps/SproutTower_3F/scripts.pory"
	.string "journey.$"
# 245 "data/maps/SproutTower_3F/scripts.pory"

# 246 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_3F_Painting:
# 247 "data/maps/SproutTower_3F/scripts.pory"
	.string "It's a powerful painting of a\n"
# 248 "data/maps/SproutTower_3F/scripts.pory"
	.string "Bellsprout.$"

ElderPostgame::
# 255 "data/maps/SproutTower_3F/scripts.pory"
	release
	end

