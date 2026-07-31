# 1 "data/maps/CeruleanCave_B2F/scripts.pory"

# 2 "data/maps/CeruleanCave_B2F/scripts.pory"
CeruleanCave_B2F_MapScripts::
# 3 "data/maps/CeruleanCave_B2F/scripts.pory"
	.byte 0
# 4 "data/maps/CeruleanCave_B2F/scripts.pory"

# 5 "data/maps/CeruleanCave_B2F/scripts.pory"
CeruleanCave3_EventScript_MewtwoNew::
# 6 "data/maps/CeruleanCave_B2F/scripts.pory"
	lock
# 7 "data/maps/CeruleanCave_B2F/scripts.pory"
	faceplayer
# 8 "data/maps/CeruleanCave_B2F/scripts.pory"
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 9 "data/maps/CeruleanCave_B2F/scripts.pory"
	waitmoncry
# 10 "data/maps/CeruleanCave_B2F/scripts.pory"
	seteventmon SPECIES_MEWTWO, 80
# 11 "data/maps/CeruleanCave_B2F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 12 "data/maps/CeruleanCave_B2F/scripts.pory"
waitstate
# 13 "data/maps/CeruleanCave_B2F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/CeruleanCave_B2F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave3_EventScript_MewtwoRan
# 15 "data/maps/CeruleanCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 16 "data/maps/CeruleanCave_B2F/scripts.pory"
	removeobject LOCALID_CERULEANCAVE_MEWTWO
# 17 "data/maps/CeruleanCave_B2F/scripts.pory"
	setflag FLAG_HIDE_MEWTWO
# 18 "data/maps/CeruleanCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 19 "data/maps/CeruleanCave_B2F/scripts.pory"
	release
# 20 "data/maps/CeruleanCave_B2F/scripts.pory"
	end
# 21 "data/maps/CeruleanCave_B2F/scripts.pory"

# 22 "data/maps/CeruleanCave_B2F/scripts.pory"
CeruleanCave3_EventScript_MewtwoRan::
# 23 "data/maps/CeruleanCave_B2F/scripts.pory"
	release
# 24 "data/maps/CeruleanCave_B2F/scripts.pory"
	end

NamelessDungeonMewtwo::
# 29 "data/maps/CeruleanCave_B2F/scripts.pory"
	lock
# 30 "data/maps/CeruleanCave_B2F/scripts.pory"
	faceplayer
# 31 "data/maps/CeruleanCave_B2F/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_MEWTWO, 80, LOCALID_CERULEANCAVE_MEWTWO, FLAG_HIDE_MEWTWO, 4, SPECIES_NONE, 110, MOVE_PSYSTRIKE, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_TAUNT, BOSS_PHASE_PROFILE_MEWTWO
# 32 "data/maps/CeruleanCave_B2F/scripts.pory"
	release
	end


NamelessDungeon_Leaf::
# 37 "data/maps/CeruleanCave_B2F/scripts.pory"
	lock
# 38 "data/maps/CeruleanCave_B2F/scripts.pory"
	goto_if_unset FLAG_TEMP_3, NamelessDungeon_Leaf_2
NamelessDungeon_Leaf_1:
# 73 "data/maps/CeruleanCave_B2F/scripts.pory"
	faceplayer
# 74 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_4, MSGBOX_YESNO
# 77 "data/maps/CeruleanCave_B2F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NamelessDungeon_Leaf_5
# 84 "data/maps/CeruleanCave_B2F/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
# 85 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_6
# 86 "data/maps/CeruleanCave_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_NAMELESS_LEAF, NamelessDungeon_Leaf_Text_7
# 87 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_8
# 103 "data/maps/CeruleanCave_B2F/scripts.pory"
	closemessage
# 104 "data/maps/CeruleanCave_B2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 105 "data/maps/CeruleanCave_B2F/scripts.pory"
	setflag FLAG_HIDE_LEAF_NAMELESS
# 106 "data/maps/CeruleanCave_B2F/scripts.pory"
	setflag FLAG_POSTGAME_CAP1
# 107 "data/maps/CeruleanCave_B2F/scripts.pory"
	playse SE_EXIT
# 108 "data/maps/CeruleanCave_B2F/scripts.pory"
	removeobject LOCALID_NAMELESS_LEAF
# 109 "data/maps/CeruleanCave_B2F/scripts.pory"
	delay 60
# 110 "data/maps/CeruleanCave_B2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 111 "data/maps/CeruleanCave_B2F/scripts.pory"
	release
	end

NamelessDungeon_Leaf_2:
# 39 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_0
# 40 "data/maps/CeruleanCave_B2F/scripts.pory"
	delay 30
# 41 "data/maps/CeruleanCave_B2F/scripts.pory"
	playse SE_PIN
# 42 "data/maps/CeruleanCave_B2F/scripts.pory"
	applymovement LOCALID_NAMELESS_LEAF, Common_Movement_ExclamationMark
# 43 "data/maps/CeruleanCave_B2F/scripts.pory"
	faceplayer
# 44 "data/maps/CeruleanCave_B2F/scripts.pory"
	waitse
# 45 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_1
# 55 "data/maps/CeruleanCave_B2F/scripts.pory"
	turnobject LOCALID_NAMELESS_LEAF, DIR_WEST
# 56 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_2
# 59 "data/maps/CeruleanCave_B2F/scripts.pory"
	faceplayer
# 60 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_3
# 71 "data/maps/CeruleanCave_B2F/scripts.pory"
	setflag FLAG_TEMP_3
	goto NamelessDungeon_Leaf_1

NamelessDungeon_Leaf_5:
# 78 "data/maps/CeruleanCave_B2F/scripts.pory"
	msgbox NamelessDungeon_Leaf_Text_5
# 80 "data/maps/CeruleanCave_B2F/scripts.pory"
	turnobject LOCALID_NAMELESS_LEAF, DIR_SOUTH
# 81 "data/maps/CeruleanCave_B2F/scripts.pory"
	release
	end


NamelessDungeon_Leaf_Text_0:
# 39 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "???: Hmm, Mewtwo should be just ahead...$"

NamelessDungeon_Leaf_Text_1:
# 45 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "???: Oh, hello! Who might you be?\p"
	.string "...\p"
	.string "Oh, you're {PLAYER}? Nice to meet you!\p"
	.string "I'm Leaf. \p"
	.string "I'm in search of some rarer\n"
	.string "than your average rare Pokémon.$"

NamelessDungeon_Leaf_Text_2:
# 56 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "I've tracked it down to this cave, and\n"
	.string "the only place it can be hiding in is\l"
	.string "just past this pool of water.$"

NamelessDungeon_Leaf_Text_3:
# 60 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "Piqued your interest, eh?\p"
	.string "Can't blame you, this one is\n"
	.string "apparently an experiment created\l"
	.string "from the DNA of another Pokémon!\p"
	.string "Unfortunately for you, I was here\n"
	.string "first!\p"
	.string "Only way to convince me otherwise\n"
	.string "would involve beating me in a battle.$"

NamelessDungeon_Leaf_Text_4:
# 74 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "What do you say? Interested?\n"
	.string "I'll warn you though, I'm really\l"
	.string "tough!$"

NamelessDungeon_Leaf_Text_5:
# 78 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "Ah shame, I was hoping you'd say\n"
	.string "yes.$"

NamelessDungeon_Leaf_Text_6:
# 85 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "Great! Get ready for a beatdown!$"

NamelessDungeon_Leaf_Text_7:
# 86 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "Damn, you're good!$"

NamelessDungeon_Leaf_Text_8:
# 87 "data/maps/CeruleanCave_B2F/scripts.pory"
	.string "Let me tell you, \n"
	.string "I was not expecting that!\p"
	.string "You are a monster in battle!\p"
	.string "What? You're this region's Champion?\p"
	.string "Oh...\p"
	.string "That explains a few things!\p"
	.string "Anyway, as promised, I'll let you have\n"
	.string "this one, but mark my words, I'll get\l"
	.string "the better of you next time we meet!\p"
	.string "Laters!$"
