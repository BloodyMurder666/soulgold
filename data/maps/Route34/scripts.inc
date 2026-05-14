# 1 "data/maps/Route34/scripts.pory"

# 2 "data/maps/Route34/scripts.pory"

# 3 "data/maps/Route34/scripts.pory"
Route34_MapScripts::
# 4 "data/maps/Route34/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
# 5 "data/maps/Route34/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/Route34/scripts.pory"
	.byte 0
# 7 "data/maps/Route34/scripts.pory"

# 8 "data/maps/Route34/scripts.pory"
Route34_OnTransition: 
# 9 "data/maps/Route34/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/Route34/scripts.pory"
	specialvar VAR_RESULT, GetDaycareState
# 11 "data/maps/Route34/scripts.pory"
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
# 12 "data/maps/Route34/scripts.pory"
	callnative SetTimeBasedEncounters
# 13 "data/maps/Route34/scripts.pory"
	end	
# 14 "data/maps/Route34/scripts.pory"

# 15 "data/maps/Route34/scripts.pory"
Route34_MapScript_EggReady::
# 16 "data/maps/Route34/scripts.pory"
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
# 17 "data/maps/Route34/scripts.pory"
	return
# 18 "data/maps/Route34/scripts.pory"

# 19 "data/maps/Route34/scripts.pory"
Route34_EventScript_YoungsterSamuel::
# 20 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
# 21 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
# 22 "data/maps/Route34/scripts.pory"
	end
# 23 "data/maps/Route34/scripts.pory"

# 24 "data/maps/Route34/scripts.pory"
Route34_EventScript_YoungsterIan::
# 25 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
# 26 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
# 27 "data/maps/Route34/scripts.pory"
	end
# 28 "data/maps/Route34/scripts.pory"

# 29 "data/maps/Route34/scripts.pory"
Route34_EventScript_CamperTodd::
# 30 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
# 31 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route34/scripts.pory"
	end
# 33 "data/maps/Route34/scripts.pory"

# 34 "data/maps/Route34/scripts.pory"
Route34_EventScript_PicnickerGina::
# 35 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
# 36 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route34/scripts.pory"
	end
# 38 "data/maps/Route34/scripts.pory"

# 39 "data/maps/Route34/scripts.pory"
Route34_EventScript_OfficerKeith::
# 40 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
# 41 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route34/scripts.pory"
	end
# 43 "data/maps/Route34/scripts.pory"

# 44 "data/maps/Route34/scripts.pory"

# 45 "data/maps/Route34/scripts.pory"
Route34_EventScript_PokefanMBrandon::
# 46 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
# 47 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route34/scripts.pory"
	end
# 49 "data/maps/Route34/scripts.pory"

# 50 "data/maps/Route34/scripts.pory"
Route34_EventScript_Irene::
# 51 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
# 52 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route34/scripts.pory"
	end
# 54 "data/maps/Route34/scripts.pory"

# 55 "data/maps/Route34/scripts.pory"
Route34_EventScript_Jenn::
# 56 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
# 57 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
# 58 "data/maps/Route34/scripts.pory"
	end
# 59 "data/maps/Route34/scripts.pory"

# 60 "data/maps/Route34/scripts.pory"
Route34_EventScript_Kate::
# 61 "data/maps/Route34/scripts.pory"
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
# 62 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route34/scripts.pory"
	end
# 64 "data/maps/Route34/scripts.pory"

# 65 "data/maps/Route34/scripts.pory"
Route34_EventScript_Sign1::
# 66 "data/maps/Route34/scripts.pory"
	lock
# 67 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
# 68 "data/maps/Route34/scripts.pory"
	closemessage
# 69 "data/maps/Route34/scripts.pory"
	release
# 70 "data/maps/Route34/scripts.pory"
	end
# 71 "data/maps/Route34/scripts.pory"

# 72 "data/maps/Route34/scripts.pory"
Route34_EventScript_Sign2::
# 73 "data/maps/Route34/scripts.pory"
	lock
# 74 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
# 75 "data/maps/Route34/scripts.pory"
	closemessage
# 76 "data/maps/Route34/scripts.pory"
	release
# 77 "data/maps/Route34/scripts.pory"
	end
# 78 "data/maps/Route34/scripts.pory"

# 79 "data/maps/Route34/scripts.pory"
Route34_EventScript_Sign3::
# 80 "data/maps/Route34/scripts.pory"
	lock
# 81 "data/maps/Route34/scripts.pory"
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
# 82 "data/maps/Route34/scripts.pory"
	closemessage
# 83 "data/maps/Route34/scripts.pory"
	release
# 84 "data/maps/Route34/scripts.pory"
	end
# 85 "data/maps/Route34/scripts.pory"

# 86 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterSamuel_Seen:
# 87 "data/maps/Route34/scripts.pory"
	.string "Hey! I'm looking for Mankey!$"
# 88 "data/maps/Route34/scripts.pory"

# 89 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterSamuel_Beaten:
# 90 "data/maps/Route34/scripts.pory"
	.string "Beaten by a passing stranger!$"
# 91 "data/maps/Route34/scripts.pory"

# 92 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterSamuel_After:
# 93 "data/maps/Route34/scripts.pory"
	.string "I'm going to train even harder.\p"
# 94 "data/maps/Route34/scripts.pory"
	.string "After all, I'm trying to become\n"
# 95 "data/maps/Route34/scripts.pory"
	.string "a Gym Leader.$"
# 96 "data/maps/Route34/scripts.pory"

# 97 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterIan_Seen:
# 98 "data/maps/Route34/scripts.pory"
	.string "I'm the best in my class at\n"
# 99 "data/maps/Route34/scripts.pory"
	.string "Pokémon.$"
# 100 "data/maps/Route34/scripts.pory"

# 101 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterIan_Beaten:
# 102 "data/maps/Route34/scripts.pory"
	.string "No! There are better trainers…$"
# 103 "data/maps/Route34/scripts.pory"

# 104 "data/maps/Route34/scripts.pory"
Route34_Text_YoungsterIan_After:
# 105 "data/maps/Route34/scripts.pory"
	.string "I'm trying hard so I can be the\n"
# 106 "data/maps/Route34/scripts.pory"
	.string "star in my class.$"
# 107 "data/maps/Route34/scripts.pory"

# 108 "data/maps/Route34/scripts.pory"
Route34_Text_CamperTodd_Seen:
# 109 "data/maps/Route34/scripts.pory"
	.string "I'm confident in my ability to\n"
# 110 "data/maps/Route34/scripts.pory"
	.string "raise Pokémon.\p"
# 111 "data/maps/Route34/scripts.pory"
	.string "Want to see?$"
# 112 "data/maps/Route34/scripts.pory"

# 113 "data/maps/Route34/scripts.pory"
Route34_Text_CamperTodd_Beaten:
# 114 "data/maps/Route34/scripts.pory"
	.string "Did I screw up my training?$"
# 115 "data/maps/Route34/scripts.pory"

# 116 "data/maps/Route34/scripts.pory"
Route34_Text_CamperTodd_After:
# 117 "data/maps/Route34/scripts.pory"
	.string "Maybe I should take one to Day-Care,\n"
# 118 "data/maps/Route34/scripts.pory"
	.string "or maybe use some items…$"
# 119 "data/maps/Route34/scripts.pory"

# 120 "data/maps/Route34/scripts.pory"
Route34_Text_PicnickerGina_Seen:
# 121 "data/maps/Route34/scripts.pory"
	.string "Are you a trainer?\p"
# 122 "data/maps/Route34/scripts.pory"
	.string "Let's have a practice battle.$"
# 123 "data/maps/Route34/scripts.pory"

# 124 "data/maps/Route34/scripts.pory"
Route34_Text_PicnickerGina_Beaten:
# 125 "data/maps/Route34/scripts.pory"
	.string "Oh, no! I just can't win…$"
# 126 "data/maps/Route34/scripts.pory"

# 127 "data/maps/Route34/scripts.pory"
Route34_Text_PicnickerGina_After:
# 128 "data/maps/Route34/scripts.pory"
	.string "You're too strong to be a\n"
# 129 "data/maps/Route34/scripts.pory"
	.string "practice partner.$"
# 130 "data/maps/Route34/scripts.pory"

# 131 "data/maps/Route34/scripts.pory"
Route34_Text_OfficerKeith_Seen:
# 132 "data/maps/Route34/scripts.pory"
	.string "Who goes there?\n"
# 133 "data/maps/Route34/scripts.pory"
	.string "What are you up to?$"
# 134 "data/maps/Route34/scripts.pory"

# 135 "data/maps/Route34/scripts.pory"
Route34_Text_OfficerKeith_Win:
# 136 "data/maps/Route34/scripts.pory"
	.string "You're a tough little kid.$"
# 137 "data/maps/Route34/scripts.pory"

# 138 "data/maps/Route34/scripts.pory"
Route34_Text_OfficerKeith_After:
# 139 "data/maps/Route34/scripts.pory"
	.string "Yep, nothing wrong today.\p"
# 140 "data/maps/Route34/scripts.pory"
	.string "Be good and stay out of trouble.$"
# 141 "data/maps/Route34/scripts.pory"

# 142 "data/maps/Route34/scripts.pory"
Route34_Text_OfficerKeith_Daytime:
# 143 "data/maps/Route34/scripts.pory"
	.string "I'm on patrol for suspicious\n"
# 144 "data/maps/Route34/scripts.pory"
	.string "individuals.$"
# 145 "data/maps/Route34/scripts.pory"

# 146 "data/maps/Route34/scripts.pory"
Route34_Text_PokefanBrandon_Seen:
# 147 "data/maps/Route34/scripts.pory"
	.string "I just got my Pokémon back from\n"
# 148 "data/maps/Route34/scripts.pory"
	.string "Day-Care.\p"
# 149 "data/maps/Route34/scripts.pory"
	.string "Let's see how much stronger it got!$"
# 150 "data/maps/Route34/scripts.pory"

# 151 "data/maps/Route34/scripts.pory"
Route34_Text_PokefanBrandon_Beaten:
# 152 "data/maps/Route34/scripts.pory"
	.string "Why does it end this way?$"
# 153 "data/maps/Route34/scripts.pory"

# 154 "data/maps/Route34/scripts.pory"
Route34_Text_PokefanBrandon_After:
# 155 "data/maps/Route34/scripts.pory"
	.string "My Pokémon came back with new moves.\p"
# 156 "data/maps/Route34/scripts.pory"
	.string "That confounded me to no end!$"
# 157 "data/maps/Route34/scripts.pory"

# 158 "data/maps/Route34/scripts.pory"
Route34_Text_Sign_IlexForest:
# 159 "data/maps/Route34/scripts.pory"
	.string "Ilex Forest\n"
# 160 "data/maps/Route34/scripts.pory"
	.string "Through The Gate$"
# 161 "data/maps/Route34/scripts.pory"

# 162 "data/maps/Route34/scripts.pory"
Route34_Text_Sign_Route34:
# 163 "data/maps/Route34/scripts.pory"
	.string "Route 34\n"
# 164 "data/maps/Route34/scripts.pory"
	.string "Goldenrod City - Azalea Town\p"
# 165 "data/maps/Route34/scripts.pory"
	.string "Ilex Forest Somewhere Between$"
# 166 "data/maps/Route34/scripts.pory"

# 167 "data/maps/Route34/scripts.pory"
Route34_Text_TrainerTips:
# 168 "data/maps/Route34/scripts.pory"
	.string "Trainer Tips\p"
# 169 "data/maps/Route34/scripts.pory"
	.string "Berry trees grow new Berries\n"
# 170 "data/maps/Route34/scripts.pory"
	.string "several times a day.\p"
# 171 "data/maps/Route34/scripts.pory"
	.string "Note which trees bear which\n"
# 172 "data/maps/Route34/scripts.pory"
	.string "Berries.$"
# 173 "data/maps/Route34/scripts.pory"

# 174 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerIrene_Seen:
# 175 "data/maps/Route34/scripts.pory"
	.string "Irene: Kyaaah! Someone found us!$"
# 176 "data/maps/Route34/scripts.pory"

# 177 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerIrene_Beaten:
# 178 "data/maps/Route34/scripts.pory"
	.string "Irene: Ohhh! You're too strong!$"
# 179 "data/maps/Route34/scripts.pory"

# 180 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerIrene_After1:
# 181 "data/maps/Route34/scripts.pory"
	.string "Irene: My sister Kate will get you\n"
# 182 "data/maps/Route34/scripts.pory"
	.string "for this!$"
# 183 "data/maps/Route34/scripts.pory"

# 184 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerIrene_After2:
# 185 "data/maps/Route34/scripts.pory"
	.string "Irene: Isn't this beach great?\p"
# 186 "data/maps/Route34/scripts.pory"
	.string "It's our secret little getaway!$"
# 187 "data/maps/Route34/scripts.pory"

# 188 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerJenn_Seen:
# 189 "data/maps/Route34/scripts.pory"
	.string "Jenn: You can't beat Irene and go\n"
# 190 "data/maps/Route34/scripts.pory"
	.string "unpunished!$"
# 191 "data/maps/Route34/scripts.pory"

# 192 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerJenn_Beaten:
# 193 "data/maps/Route34/scripts.pory"
	.string "Jenn: So sorry, Irene! Dear Sis!$"
# 194 "data/maps/Route34/scripts.pory"

# 195 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerJenn_After1:
# 196 "data/maps/Route34/scripts.pory"
	.string "Jenn: Don't get cocky! My sister\n"
# 197 "data/maps/Route34/scripts.pory"
	.string "Kate is tough!$"
# 198 "data/maps/Route34/scripts.pory"

# 199 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerJenn_After2:
# 200 "data/maps/Route34/scripts.pory"
	.string "Jenn: Sunlight makes your body\n"
# 201 "data/maps/Route34/scripts.pory"
	.string "stronger.$"
# 202 "data/maps/Route34/scripts.pory"

# 203 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerKate_Seen:
# 204 "data/maps/Route34/scripts.pory"
	.string "Kate: You sure were mean to my\n"
# 205 "data/maps/Route34/scripts.pory"
	.string "little sisters!$"
# 206 "data/maps/Route34/scripts.pory"

# 207 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerKate_Beaten:
# 208 "data/maps/Route34/scripts.pory"
	.string "Kate: No! I can't believe I lost.$"
# 209 "data/maps/Route34/scripts.pory"

# 210 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerKate_GiveSoftSand:
# 211 "data/maps/Route34/scripts.pory"
	.string "Kate: You're too strong. I didn't\n"
# 212 "data/maps/Route34/scripts.pory"
	.string "stand a chance. Here, you deserve\n"
# 213 "data/maps/Route34/scripts.pory"
	.string "this.$"
# 214 "data/maps/Route34/scripts.pory"

# 215 "data/maps/Route34/scripts.pory"
Route34_Text_CooltrainerKate_After:
# 216 "data/maps/Route34/scripts.pory"
	.string "Kate: I'm sorry we jumped you.\p"
# 217 "data/maps/Route34/scripts.pory"
	.string "We never expected anyone to find\n"
# 218 "data/maps/Route34/scripts.pory"
	.string "us here. You sure startled us.$"
# 219 "data/maps/Route34/scripts.pory"

# 220 "data/maps/Route34/scripts.pory"

# 221 "data/maps/Route34/scripts.pory"
Route34_Text_Sign_DayCare:
# 222 "data/maps/Route34/scripts.pory"
	.string "Day-Care\p"
# 223 "data/maps/Route34/scripts.pory"
	.string "Let Us Raise Your Pokémon For You!$"

Route34_RivalEncounter::
# 227 "data/maps/Route34/scripts.pory"
	lock
# 228 "data/maps/Route34/scripts.pory"
	applymovement LOCALID_ROUTE34_RIVAL, Common_Movement_ExclamationMark
# 229 "data/maps/Route34/scripts.pory"
	applymovement LOCALID_ROUTE34_RIVAL, Route34_RivalEncounter_Movement_0
# 230 "data/maps/Route34/scripts.pory"
	playse SE_PIN
# 231 "data/maps/Route34/scripts.pory"
	waitse
# 232 "data/maps/Route34/scripts.pory"
	waitmovement 0
# 233 "data/maps/Route34/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 234 "data/maps/Route34/scripts.pory"
	approachobject LOCALID_ROUTE34_RIVAL, LOCALID_PLAYER, DIR_SOUTH, DIR_NORTH
# 235 "data/maps/Route34/scripts.pory"
	waitmovement
# 236 "data/maps/Route34/scripts.pory"
	applymovement LOCALID_ROUTE34_DAYCAREMAN, Route34_RivalEncounter_Movement_0
# 237 "data/maps/Route34/scripts.pory"
	waitmovement
# 238 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_0
# 248 "data/maps/Route34/scripts.pory"
	checkplayergender
# 249 "data/maps/Route34/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Route34_RivalEncounter_2
# 252 "data/maps/Route34/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALGOLD2, Route34_RivalEncounter_Text_1
Route34_RivalEncounter_1:
# 254 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_2
# 259 "data/maps/Route34/scripts.pory"
	waitmessage
# 260 "data/maps/Route34/scripts.pory"
	playse SE_USE_ITEM
# 261 "data/maps/Route34/scripts.pory"
	waitse
# 262 "data/maps/Route34/scripts.pory"
	special HealPlayerParty
# 263 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_3
# 268 "data/maps/Route34/scripts.pory"
	random 7
# 269 "data/maps/Route34/scripts.pory"
	addvar VAR_RESULT, 1
# 270 "data/maps/Route34/scripts.pory"
	giveoddegg VAR_RESULT
# 271 "data/maps/Route34/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq Route34_RivalEncounter_6
# 277 "data/maps/Route34/scripts.pory"
	setflag FLAG_RECEIVED_ODD_EGG
# 278 "data/maps/Route34/scripts.pory"
	playfanfare MUS_HG_OBTAIN_ITEM
# 279 "data/maps/Route34/scripts.pory"
	message Route34_RivalEncounter_Text_5
# 280 "data/maps/Route34/scripts.pory"
	waitfanfare
# 281 "data/maps/Route34/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Route34_RivalEncounter_9
Route34_RivalEncounter_8:
# 284 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_7
# 291 "data/maps/Route34/scripts.pory"
	closemessage
# 292 "data/maps/Route34/scripts.pory"
	applymovement LOCALID_ROUTE34_RIVAL, Route34_RivalEncounter_Movement_1
# 293 "data/maps/Route34/scripts.pory"
	waitmovement 0
# 294 "data/maps/Route34/scripts.pory"
	applymovement LOCALID_ROUTE34_DAYCAREMAN, Route34_RivalEncounter_Movement_2
# 295 "data/maps/Route34/scripts.pory"
	waitmovement 0
# 296 "data/maps/Route34/scripts.pory"
	removeobject LOCALID_ROUTE34_RIVAL
# 297 "data/maps/Route34/scripts.pory"
	fadedefaultbgm
# 298 "data/maps/Route34/scripts.pory"
	setvar VAR_RIVAL_STATE, 6
# 299 "data/maps/Route34/scripts.pory"
	release
	end

Route34_RivalEncounter_2:
# 250 "data/maps/Route34/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVALCRYSTAL2, Route34_RivalEncounter_Text_1
	goto Route34_RivalEncounter_1

Route34_RivalEncounter_6:
# 272 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_4
# 273 "data/maps/Route34/scripts.pory"
	closemessage
# 274 "data/maps/Route34/scripts.pory"
	release
	end

Route34_RivalEncounter_9:
# 282 "data/maps/Route34/scripts.pory"
	msgbox Route34_RivalEncounter_Text_6
	goto Route34_RivalEncounter_8


# 229 "data/maps/Route34/scripts.pory"
Route34_RivalEncounter_Movement_0:
# 229 "data/maps/Route34/scripts.pory"
	face_down
	step_end

# 292 "data/maps/Route34/scripts.pory"
Route34_RivalEncounter_Movement_1:
# 292 "data/maps/Route34/scripts.pory"
	walk_up
# 292 "data/maps/Route34/scripts.pory"
	walk_up
# 292 "data/maps/Route34/scripts.pory"
	walk_up
# 292 "data/maps/Route34/scripts.pory"
	walk_up
# 292 "data/maps/Route34/scripts.pory"
	walk_up
	step_end

# 294 "data/maps/Route34/scripts.pory"
Route34_RivalEncounter_Movement_2:
# 294 "data/maps/Route34/scripts.pory"
	face_left
	step_end

Route34_RivalEncounter_Text_0:
# 238 "data/maps/Route34/scripts.pory"
	.string "Good pace, {PLAYER}!\n"
	.string "You've almost reached Goldenrod City!\p"
	.string "I was visiting my grandparents, they\n"
	.string "own the daycare on this route.\p"
	.string "Since you're here and grandpa is\n"
	.string "watching, how about a battle? I'll\l"
	.string "finally get to show them how much\l"
	.string "better I've gotten!$"

Route34_RivalEncounter_Text_1:
# 250 "data/maps/Route34/scripts.pory"
	.string "Still not good enough...$"

Route34_RivalEncounter_Text_2:
# 254 "data/maps/Route34/scripts.pory"
	.string "Well that sucks... When grandma hears\n"
	.string "of this, I'll never hear the end of it...\p"
	.string "Let me just heal your party quick since\n"
	.string "I was the one who started this.$"

Route34_RivalEncounter_Text_3:
# 263 "data/maps/Route34/scripts.pory"
	.string "My grandparents found this strange egg\n"
	.string "recently. They said I could have it, but\l"
	.string "I think you'd be a better fit for it.\p"
	.string "Take it as a prize for beating me!$"

Route34_RivalEncounter_Text_4:
# 272 "data/maps/Route34/scripts.pory"
	.string "Oh you have no space, how strange...$"

Route34_RivalEncounter_Text_5:
# 279 "data/maps/Route34/scripts.pory"
	.string "{PLAYER} Received the Odd Egg.$"

Route34_RivalEncounter_Text_6:
# 282 "data/maps/Route34/scripts.pory"
	.string "The Odd Egg was sent to your PC.$"

Route34_RivalEncounter_Text_7:
# 284 "data/maps/Route34/scripts.pory"
	.string "Now then, I can't keep losing you to\n"
	.string "every time, so I'm going to start\l"
	.string "training seriously! \p"
	.string "Next time we\n"
	.string "meet, you will face all new me!\l"
	.string "Look forward to a complete beatdown!$"
