# 1 "data/maps/VictoryRoadKanto_B1F/scripts.pory"

# 2 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
VictoryRoadKanto_B1F_MapScripts::
# 3 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoadKanto_B1F_OnTransition
# 4 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/VictoryRoadKanto_B1F/scripts.pory"

# 6 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
VictoryRoadKanto_B1F_OnTransition::
# 7 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 8 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
    end
# 9 "data/maps/VictoryRoadKanto_B1F/scripts.pory"

# 10 "data/maps/VictoryRoadKanto_B1F/scripts.pory"

# 11 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
MtSilver_1F_MoltresRoom_EventScript_Moltres::
# 12 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 13 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 14 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 15 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
# 16 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	delay 40
# 17 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	waitmoncry
# 18 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	seteventmon SPECIES_MOLTRES, 60
# 19 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 20 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 21 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	waitstate
# 22 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtSilver_1F_MoltresRoom_EventScript_MoltresRan
# 24 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 25 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	removeobject LOCALID_VICTORYROAD_MOLTRES
# 26 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	setflag FLAG_HIDE_MOLTRES
# 27 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 28 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
# 29 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	end
# 30 "data/maps/VictoryRoadKanto_B1F/scripts.pory"

# 31 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
MtSilver_1F_MoltresRoom_EventScript_MoltresRan::
# 32 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
# 33 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	end

VictoryRoad_Rival::
# 37 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	goto_if_set FLAG_SPOKEN_VICTORYROAD_RIVAL, VictoryRoad_Rival_1
# 40 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 41 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 42 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	createfieldmugshotrival
# 43 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	msgbox VictoryRoad_Rival_Text_0
# 44 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	setflag FLAG_SPOKEN_VICTORYROAD_RIVAL
# 45 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
	end

VictoryRoad_Rival_1:
# 38 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	goto VictoryRoad_Rival2
	return


VictoryRoad_Rival2::
# 51 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 52 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 53 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	createfieldmugshotrival
# 54 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	msgbox VictoryRoad_Rival2_Text_0
# 57 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
	end


VictoryRoad_Rival_Text_0:
# 43 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	.string "Don't.$"

VictoryRoad_Rival2_Text_0:
# 54 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	.string "I just need to train more.\p"
	.string "That's all there ever is to it.$"
