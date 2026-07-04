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
	goto_if_set FLAG_BADGE08_GET, SageLiPostBadges
# 114 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
# 115 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 116 "data/maps/SproutTower_3F/scripts.pory"
	release
# 117 "data/maps/SproutTower_3F/scripts.pory"
	end
# 118 "data/maps/SproutTower_3F/scripts.pory"

# 119 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_Silver1:
# 120 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 121 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 122 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 123 "data/maps/SproutTower_3F/scripts.pory"

# 124 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverLeft:
# 125 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 126 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 127 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 128 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 129 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 130 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 131 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 132 "data/maps/SproutTower_3F/scripts.pory"

# 133 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverRight:
# 134 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 135 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 136 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 137 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 138 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 139 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 140 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 141 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 142 "data/maps/SproutTower_3F/scripts.pory"

# 143 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_EscapeRope:
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
	face_right
# 153 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 154 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 155 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 156 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 157 "data/maps/SproutTower_3F/scripts.pory"

# 158 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_ElderLecturesRival:
# 159 "data/maps/SproutTower_3F/scripts.pory"
	.string "Elder: You are indeed skilled\n"
# 160 "data/maps/SproutTower_3F/scripts.pory"
	.string "as a trainer.\p"
# 161 "data/maps/SproutTower_3F/scripts.pory"
	.string "As promised, here is your HM.\p"
# 162 "data/maps/SproutTower_3F/scripts.pory"
	.string "But let me say this: You should\n"
# 163 "data/maps/SproutTower_3F/scripts.pory"
	.string "treat your Pokémon better.\p"
# 164 "data/maps/SproutTower_3F/scripts.pory"
	.string "The way you battle is far too\n"
# 165 "data/maps/SproutTower_3F/scripts.pory"
	.string "harsh.\p"
# 166 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon are not tools of war…$"
# 167 "data/maps/SproutTower_3F/scripts.pory"

# 168 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalOnlyCaresStrong:
# 169 "data/maps/SproutTower_3F/scripts.pory"
	.string "…\n"
# 170 "data/maps/SproutTower_3F/scripts.pory"
	.string "…Humph!\p"
# 171 "data/maps/SproutTower_3F/scripts.pory"
	.string "He claims to be the Elder but\n"
# 172 "data/maps/SproutTower_3F/scripts.pory"
	.string "he's weak.\p"
# 173 "data/maps/SproutTower_3F/scripts.pory"
	.string "It stands to reason.\p"
# 174 "data/maps/SproutTower_3F/scripts.pory"
	.string "I'd never lose to fools who babble\n"
# 175 "data/maps/SproutTower_3F/scripts.pory"
	.string "about being nice to Pokémon.\p"
# 176 "data/maps/SproutTower_3F/scripts.pory"
	.string "I only care about strong\n"
# 177 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon that can win.\p"
# 178 "data/maps/SproutTower_3F/scripts.pory"
	.string "I really couldn't care less\n"
# 179 "data/maps/SproutTower_3F/scripts.pory"
	.string "about weak Pokémon.$"
# 180 "data/maps/SproutTower_3F/scripts.pory"

# 181 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalUsedEscapeRope:
# 182 "data/maps/SproutTower_3F/scripts.pory"
	.string "{RIVAL} used an Escape Rope!$"
# 183 "data/maps/SproutTower_3F/scripts.pory"

# 184 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Seen:
# 185 "data/maps/SproutTower_3F/scripts.pory"
	.string "So good of you to come here!\p"
# 186 "data/maps/SproutTower_3F/scripts.pory"
	.string "Sprout Tower is a place of\n"
# 187 "data/maps/SproutTower_3F/scripts.pory"
	.string "training.\p"
# 188 "data/maps/SproutTower_3F/scripts.pory"
	.string "People and Pokémon test their\n"
# 189 "data/maps/SproutTower_3F/scripts.pory"
	.string "bonds to build a bright future\l"
# 190 "data/maps/SproutTower_3F/scripts.pory"
	.string "together.\p"
# 191 "data/maps/SproutTower_3F/scripts.pory"
	.string "I am the final test.\p"
# 192 "data/maps/SproutTower_3F/scripts.pory"
	.string "Allow me to check the ties\n"
# 193 "data/maps/SproutTower_3F/scripts.pory"
	.string "between your Pokémon and you!$"
# 194 "data/maps/SproutTower_3F/scripts.pory"

# 195 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Beaten:
# 196 "data/maps/SproutTower_3F/scripts.pory"
	.string "Ah, excellent!$"
# 197 "data/maps/SproutTower_3F/scripts.pory"

# 198 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_TakeFlash:
# 199 "data/maps/SproutTower_3F/scripts.pory"
	.string "You and your Pokémon should\n"
# 200 "data/maps/SproutTower_3F/scripts.pory"
	.string "have no problem using this move.\p"
# 201 "data/maps/SproutTower_3F/scripts.pory"
	.string "Take this Flash HM.$"
# 202 "data/maps/SproutTower_3F/scripts.pory"

# 203 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_FlashExplain:
# 204 "data/maps/SproutTower_3F/scripts.pory"
	.string "Flash illuminates even the\n"
# 205 "data/maps/SproutTower_3F/scripts.pory"
	.string "darkest of all places.\p"
# 206 "data/maps/SproutTower_3F/scripts.pory"
	.string "But to use it out of battle, you\n"
# 207 "data/maps/SproutTower_3F/scripts.pory"
	.string "need the Badge from Violet's Gym.$"
# 208 "data/maps/SproutTower_3F/scripts.pory"

# 209 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_AfterBattle:
# 210 "data/maps/SproutTower_3F/scripts.pory"
	.string "I hope you learn and grow from\n"
# 211 "data/maps/SproutTower_3F/scripts.pory"
	.string "your journey.$"
# 212 "data/maps/SproutTower_3F/scripts.pory"

# 213 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Seen:
# 214 "data/maps/SproutTower_3F/scripts.pory"
	.string "I train to find enlightenment\n"
# 215 "data/maps/SproutTower_3F/scripts.pory"
	.string "in Pokémon!$"
# 216 "data/maps/SproutTower_3F/scripts.pory"

# 217 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Beaten:
# 218 "data/maps/SproutTower_3F/scripts.pory"
	.string "My training is incomplete…$"
# 219 "data/maps/SproutTower_3F/scripts.pory"

# 220 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_AfterBattle:
# 221 "data/maps/SproutTower_3F/scripts.pory"
	.string "As Pokémon grow stronger,\n"
# 222 "data/maps/SproutTower_3F/scripts.pory"
	.string "so does the trainer.\p"
# 223 "data/maps/SproutTower_3F/scripts.pory"
	.string "No, wait. As the trainer\n"
# 224 "data/maps/SproutTower_3F/scripts.pory"
	.string "grows stronger, so do the\l"
# 225 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon.$"
# 226 "data/maps/SproutTower_3F/scripts.pory"

# 227 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Seen:
# 228 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let me see how much you trust\n"
# 229 "data/maps/SproutTower_3F/scripts.pory"
	.string "your Pokémon.$"
# 230 "data/maps/SproutTower_3F/scripts.pory"

# 231 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Beaten:
# 232 "data/maps/SproutTower_3F/scripts.pory"
	.string "Yes, your trust is real!$"
# 233 "data/maps/SproutTower_3F/scripts.pory"

# 234 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_AfterBattle:
# 235 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is not far to the Elder.$"
# 236 "data/maps/SproutTower_3F/scripts.pory"

# 237 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Seen:
# 238 "data/maps/SproutTower_3F/scripts.pory"
	.string "The Elder's HM lights even\n"
# 239 "data/maps/SproutTower_3F/scripts.pory"
	.string "pitch-black darkness.$"
# 240 "data/maps/SproutTower_3F/scripts.pory"

# 241 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Beaten:
# 242 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is my head that is bright!$"
# 243 "data/maps/SproutTower_3F/scripts.pory"

# 244 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_AfterBattle:
# 245 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let there be light on your\n"
# 246 "data/maps/SproutTower_3F/scripts.pory"
	.string "journey.$"
# 247 "data/maps/SproutTower_3F/scripts.pory"

# 248 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_3F_Painting:
# 249 "data/maps/SproutTower_3F/scripts.pory"
	.string "It's a powerful painting of a\n"
# 250 "data/maps/SproutTower_3F/scripts.pory"
	.string "Bellsprout.$"

SageLiPostBadges::
# 255 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_BASEMENT_GUARD, SageLiPostBadges_2
# 288 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_3
SageLiPostBadges_1:
# 291 "data/maps/SproutTower_3F/scripts.pory"
	release
	end

SageLiPostBadges_2:
# 256 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_0
# 270 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI_2, SageLiPostBadges_Text_1
# 272 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_2
# 284 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_3
# 286 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_BASEMENT_GUARD
	goto SageLiPostBadges_1


SageLiPostBadges_Text_0:
# 256 "data/maps/SproutTower_3F/scripts.pory"
	.string "{PLAYER}!\p"
	.string "I have heard of your triumps across\n"
	.string "Johto! \p"
	.string "I am overjoyed to see how\n"
	.string "far the bonds of trainer and Pokémon\l"
	.string "can go.\p"
	.string "To that end, I would like to test you\n"
	.string "once again. This time I won't be holding\l"
	.string "back. \p"
	.string "Prepare yourself!$"

SageLiPostBadges_Text_1:
# 270 "data/maps/SproutTower_3F/scripts.pory"
	.string "Future generations shine brighter than\n"
	.string "ever! Walk this path young trainer.$"

SageLiPostBadges_Text_2:
# 272 "data/maps/SproutTower_3F/scripts.pory"
	.string "A marvelous display of skill!\p"
	.string "I believe the borders of Johto won't\n"
	.string "enough for you at your current pace.\p"
	.string "I will allow you access this tower's\n"
	.string "basement floor. \p"
	.string "A strong Pokémon resides there.\p"
	.string "Guarding it has been one of our\n"
	.string "tasks for a very long time.$"

SageLiPostBadges_Text_3:
# 284 "data/maps/SproutTower_3F/scripts.pory"
	.string "I look forward to hearing where your\n"
	.string "journey next takes you.$"
