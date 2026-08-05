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
	createfieldmugshot MUGSHOT_ELDER_LI
# 40 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
# 41 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 42 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_PIN
# 43 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
# 44 "data/maps/SproutTower_3F/scripts.pory"
	delay 60
# 45 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
# 46 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 47 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 48 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
# 49 "data/maps/SproutTower_3F/scripts.pory"
	delay 30
# 50 "data/maps/SproutTower_3F/scripts.pory"
	removefieldmugshot
# 51 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
# 52 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
# 53 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 54 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 55 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 56 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 57 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 58 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 59 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 60 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 61 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 62 "data/maps/SproutTower_3F/scripts.pory"
	delay 15
# 63 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 64 "data/maps/SproutTower_3F/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/SproutTower_3F/scripts.pory"
	release
# 66 "data/maps/SproutTower_3F/scripts.pory"
	end
# 67 "data/maps/SproutTower_3F/scripts.pory"

# 68 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_TriggerSceneRight::
# 69 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 70 "data/maps/SproutTower_3F/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 71 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
# 72 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 73 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_ELDER_LI
# 74 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
# 75 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 76 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_PIN
# 77 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
# 78 "data/maps/SproutTower_3F/scripts.pory"
	delay 60
# 79 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
# 80 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 81 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 82 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 83 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
# 84 "data/maps/SproutTower_3F/scripts.pory"
	removefieldmugshot
# 85 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
# 86 "data/maps/SproutTower_3F/scripts.pory"
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
# 87 "data/maps/SproutTower_3F/scripts.pory"
	waitmovement 0
# 88 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 89 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 90 "data/maps/SproutTower_3F/scripts.pory"
	playse SE_EXIT
# 91 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
# 92 "data/maps/SproutTower_3F/scripts.pory"
	removeobject LOCALID_SPROUT_TOWER_SILVER
# 93 "data/maps/SproutTower_3F/scripts.pory"
	savebgm MUS_DUMMY
# 94 "data/maps/SproutTower_3F/scripts.pory"
	fadedefaultbgm
# 95 "data/maps/SproutTower_3F/scripts.pory"
	delay 55
# 96 "data/maps/SproutTower_3F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 97 "data/maps/SproutTower_3F/scripts.pory"
	special DrawWholeMapView
# 98 "data/maps/SproutTower_3F/scripts.pory"
	delay 15
# 99 "data/maps/SproutTower_3F/scripts.pory"
	setvar VAR_SPROUT_TOWER, 1
# 100 "data/maps/SproutTower_3F/scripts.pory"
	release
# 101 "data/maps/SproutTower_3F/scripts.pory"
	end
# 102 "data/maps/SproutTower_3F/scripts.pory"

# 103 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi::
# 104 "data/maps/SproutTower_3F/scripts.pory"
	lock
# 105 "data/maps/SproutTower_3F/scripts.pory"
	faceplayer
# 106 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
# 107 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
# 108 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 109 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
# 110 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_ELDER_LI
# 111 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
# 112 "data/maps/SproutTower_3F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 113 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 114 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_ELDER_LI
# 115 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
# 116 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 117 "data/maps/SproutTower_3F/scripts.pory"
	release
# 118 "data/maps/SproutTower_3F/scripts.pory"
	end
# 119 "data/maps/SproutTower_3F/scripts.pory"

# 120 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_EventScript_SageLi_Beaten::
# 121 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SageLiPostBadges
# 122 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
# 123 "data/maps/SproutTower_3F/scripts.pory"
	closemessage
# 124 "data/maps/SproutTower_3F/scripts.pory"
	release
# 125 "data/maps/SproutTower_3F/scripts.pory"
	end
# 126 "data/maps/SproutTower_3F/scripts.pory"

# 127 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_Silver1:
# 128 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 129 "data/maps/SproutTower_3F/scripts.pory"
	walk_fast_up
# 130 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 131 "data/maps/SproutTower_3F/scripts.pory"

# 132 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_SilverLeft:
# 133 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 134 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
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
SproutTower_3F_Movement_SilverRight:
# 142 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 143 "data/maps/SproutTower_3F/scripts.pory"
	delay_16
# 144 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 145 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 146 "data/maps/SproutTower_3F/scripts.pory"
	walk_right
# 147 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 148 "data/maps/SproutTower_3F/scripts.pory"
	walk_down
# 149 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 150 "data/maps/SproutTower_3F/scripts.pory"

# 151 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_3F_Movement_EscapeRope:
# 152 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 153 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 154 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 155 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 156 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 157 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 158 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 159 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 160 "data/maps/SproutTower_3F/scripts.pory"
	face_right
# 161 "data/maps/SproutTower_3F/scripts.pory"
	face_up
# 162 "data/maps/SproutTower_3F/scripts.pory"
	face_left
# 163 "data/maps/SproutTower_3F/scripts.pory"
	face_down
# 164 "data/maps/SproutTower_3F/scripts.pory"
	step_end
# 165 "data/maps/SproutTower_3F/scripts.pory"

# 166 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_ElderLecturesRival:
# 167 "data/maps/SproutTower_3F/scripts.pory"
	.string "Elder: You are indeed skilled\n"
# 168 "data/maps/SproutTower_3F/scripts.pory"
	.string "as a trainer.\p"
# 169 "data/maps/SproutTower_3F/scripts.pory"
	.string "As promised, here is your HM.\p"
# 170 "data/maps/SproutTower_3F/scripts.pory"
	.string "But let me say this: You should\n"
# 171 "data/maps/SproutTower_3F/scripts.pory"
	.string "treat your Pokémon better.\p"
# 172 "data/maps/SproutTower_3F/scripts.pory"
	.string "The way you battle is far too\n"
# 173 "data/maps/SproutTower_3F/scripts.pory"
	.string "harsh.\p"
# 174 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon are not tools of war…$"
# 175 "data/maps/SproutTower_3F/scripts.pory"

# 176 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalOnlyCaresStrong:
# 177 "data/maps/SproutTower_3F/scripts.pory"
	.string "…\n"
# 178 "data/maps/SproutTower_3F/scripts.pory"
	.string "…Humph!\p"
# 179 "data/maps/SproutTower_3F/scripts.pory"
	.string "He claims to be the Elder but\n"
# 180 "data/maps/SproutTower_3F/scripts.pory"
	.string "he's weak.\p"
# 181 "data/maps/SproutTower_3F/scripts.pory"
	.string "It stands to reason.\p"
# 182 "data/maps/SproutTower_3F/scripts.pory"
	.string "I'd never lose to fools who babble\n"
# 183 "data/maps/SproutTower_3F/scripts.pory"
	.string "about being nice to Pokémon.\p"
# 184 "data/maps/SproutTower_3F/scripts.pory"
	.string "I only care about strong\n"
# 185 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon that can win.\p"
# 186 "data/maps/SproutTower_3F/scripts.pory"
	.string "I really couldn't care less\n"
# 187 "data/maps/SproutTower_3F/scripts.pory"
	.string "about weak Pokémon.$"
# 188 "data/maps/SproutTower_3F/scripts.pory"

# 189 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_RivalUsedEscapeRope:
# 190 "data/maps/SproutTower_3F/scripts.pory"
	.string "{RIVAL} used an Escape Rope!$"
# 191 "data/maps/SproutTower_3F/scripts.pory"

# 192 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Seen:
# 193 "data/maps/SproutTower_3F/scripts.pory"
	.string "So good of you to come here!\p"
# 194 "data/maps/SproutTower_3F/scripts.pory"
	.string "Sprout Tower is a place of\n"
# 195 "data/maps/SproutTower_3F/scripts.pory"
	.string "training.\p"
# 196 "data/maps/SproutTower_3F/scripts.pory"
	.string "People and Pokémon test their\n"
# 197 "data/maps/SproutTower_3F/scripts.pory"
	.string "bonds to build a bright future\l"
# 198 "data/maps/SproutTower_3F/scripts.pory"
	.string "together.\p"
# 199 "data/maps/SproutTower_3F/scripts.pory"
	.string "I am the final test.\p"
# 200 "data/maps/SproutTower_3F/scripts.pory"
	.string "Allow me to check the ties\n"
# 201 "data/maps/SproutTower_3F/scripts.pory"
	.string "between your Pokémon and you!$"
# 202 "data/maps/SproutTower_3F/scripts.pory"

# 203 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_Beaten:
# 204 "data/maps/SproutTower_3F/scripts.pory"
	.string "Ah, excellent!$"
# 205 "data/maps/SproutTower_3F/scripts.pory"

# 206 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_TakeFlash:
# 207 "data/maps/SproutTower_3F/scripts.pory"
	.string "You and your Pokémon should\n"
# 208 "data/maps/SproutTower_3F/scripts.pory"
	.string "have no problem using this move.\p"
# 209 "data/maps/SproutTower_3F/scripts.pory"
	.string "Take this Flash HM.$"
# 210 "data/maps/SproutTower_3F/scripts.pory"

# 211 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_FlashExplain:
# 212 "data/maps/SproutTower_3F/scripts.pory"
	.string "Flash illuminates even the\n"
# 213 "data/maps/SproutTower_3F/scripts.pory"
	.string "darkest of all places.\p"
# 214 "data/maps/SproutTower_3F/scripts.pory"
	.string "But to use it out of battle, you\n"
# 215 "data/maps/SproutTower_3F/scripts.pory"
	.string "need the Badge from Violet's Gym.$"
# 216 "data/maps/SproutTower_3F/scripts.pory"

# 217 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageLi_AfterBattle:
# 218 "data/maps/SproutTower_3F/scripts.pory"
	.string "I hope you learn and grow from\n"
# 219 "data/maps/SproutTower_3F/scripts.pory"
	.string "your journey.$"
# 220 "data/maps/SproutTower_3F/scripts.pory"

# 221 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Seen:
# 222 "data/maps/SproutTower_3F/scripts.pory"
	.string "I train to find enlightenment\n"
# 223 "data/maps/SproutTower_3F/scripts.pory"
	.string "in Pokémon!$"
# 224 "data/maps/SproutTower_3F/scripts.pory"

# 225 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_Beaten:
# 226 "data/maps/SproutTower_3F/scripts.pory"
	.string "My training is incomplete…$"
# 227 "data/maps/SproutTower_3F/scripts.pory"

# 228 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageJin_AfterBattle:
# 229 "data/maps/SproutTower_3F/scripts.pory"
	.string "As Pokémon grow stronger,\n"
# 230 "data/maps/SproutTower_3F/scripts.pory"
	.string "so does the trainer.\p"
# 231 "data/maps/SproutTower_3F/scripts.pory"
	.string "No, wait. As the trainer\n"
# 232 "data/maps/SproutTower_3F/scripts.pory"
	.string "grows stronger, so do the\l"
# 233 "data/maps/SproutTower_3F/scripts.pory"
	.string "Pokémon.$"
# 234 "data/maps/SproutTower_3F/scripts.pory"

# 235 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Seen:
# 236 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let me see how much you trust\n"
# 237 "data/maps/SproutTower_3F/scripts.pory"
	.string "your Pokémon.$"
# 238 "data/maps/SproutTower_3F/scripts.pory"

# 239 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_Beaten:
# 240 "data/maps/SproutTower_3F/scripts.pory"
	.string "Yes, your trust is real!$"
# 241 "data/maps/SproutTower_3F/scripts.pory"

# 242 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageTroy_AfterBattle:
# 243 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is not far to the Elder.$"
# 244 "data/maps/SproutTower_3F/scripts.pory"

# 245 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Seen:
# 246 "data/maps/SproutTower_3F/scripts.pory"
	.string "The Elder's HM lights even\n"
# 247 "data/maps/SproutTower_3F/scripts.pory"
	.string "pitch-black darkness.$"
# 248 "data/maps/SproutTower_3F/scripts.pory"

# 249 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_Beaten:
# 250 "data/maps/SproutTower_3F/scripts.pory"
	.string "It is my head that is bright!$"
# 251 "data/maps/SproutTower_3F/scripts.pory"

# 252 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_SageNeal_AfterBattle:
# 253 "data/maps/SproutTower_3F/scripts.pory"
	.string "Let there be light on your\n"
# 254 "data/maps/SproutTower_3F/scripts.pory"
	.string "journey.$"
# 255 "data/maps/SproutTower_3F/scripts.pory"

# 256 "data/maps/SproutTower_3F/scripts.pory"
SproutTower_Text_3F_Painting:
# 257 "data/maps/SproutTower_3F/scripts.pory"
	.string "It's a powerful painting of a\n"
# 258 "data/maps/SproutTower_3F/scripts.pory"
	.string "Bellsprout.$"

SageLiPostBadges::
# 263 "data/maps/SproutTower_3F/scripts.pory"
	goto_if_unset FLAG_HIDE_SPROUT_BASEMENT_GUARD, SageLiPostBadges_2
# 298 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_4
SageLiPostBadges_1:
# 301 "data/maps/SproutTower_3F/scripts.pory"
	release
	end

SageLiPostBadges_2:
# 264 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_0
# 277 "data/maps/SproutTower_3F/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
# 278 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_1
# 279 "data/maps/SproutTower_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_LI_2, SageLiPostBadges_Text_2
# 281 "data/maps/SproutTower_3F/scripts.pory"
	createfieldmugshot MUGSHOT_ELDER_LI
# 282 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_3
# 294 "data/maps/SproutTower_3F/scripts.pory"
	msgbox SageLiPostBadges_Text_4
# 296 "data/maps/SproutTower_3F/scripts.pory"
	setflag FLAG_HIDE_SPROUT_BASEMENT_GUARD
	goto SageLiPostBadges_1


SageLiPostBadges_Text_0:
# 264 "data/maps/SproutTower_3F/scripts.pory"
	.string "{PLAYER}!\p"
	.string "I have heard of your triumphs across\n"
	.string "Johto!\p"
	.string "I am overjoyed to see how far the bonds\n"
	.string "between Trainers and Pokémon can go.\p"
	.string "To that end, I would like to test you\n"
	.string "once again. \p"
	.string "This time I won't be holding back.$"

SageLiPostBadges_Text_1:
# 278 "data/maps/SproutTower_3F/scripts.pory"
	.string "Prepare yourself!$"

SageLiPostBadges_Text_2:
# 279 "data/maps/SproutTower_3F/scripts.pory"
	.string "Future generations shine brighter than\n"
	.string "ever! Walk this path, young Trainer.$"

SageLiPostBadges_Text_3:
# 282 "data/maps/SproutTower_3F/scripts.pory"
	.string "A marvelous display of skill!\p"
	.string "I believe the borders of Johto won't\n"
	.string "be enough for you at your current pace.\p"
	.string "I will allow you access to this tower's\n"
	.string "basement floor.\p"
	.string "A strong Pokémon resides there.\p"
	.string "Guarding it has been one of our\n"
	.string "tasks for a very long time.$"

SageLiPostBadges_Text_4:
# 294 "data/maps/SproutTower_3F/scripts.pory"
	.string "I look forward to hearing where your\n"
	.string "journey next takes you.$"
