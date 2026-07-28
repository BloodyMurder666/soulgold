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

# 12 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
MtSilver_1F_MoltresRoom_EventScript_MoltresRan::
# 13 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
# 14 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	end

VictoryRoadKanto_B1F_EventScript_Moltres::
# 18 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 19 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 20 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	bosslegendaryencounter SPECIES_MOLTRES, 60, LOCALID_VICTORYROAD_MOLTRES, FLAG_HIDE_MOLTRES
# 21 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
	end


VictoryRoad_Rival::
# 26 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	goto_if_set FLAG_SPOKEN_VICTORYROAD_RIVAL, VictoryRoad_Rival_1
# 29 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 30 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 31 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	createfieldmugshotrival
# 32 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	msgbox VictoryRoad_Rival_Text_0
# 33 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	setflag FLAG_SPOKEN_VICTORYROAD_RIVAL
# 34 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
	end

VictoryRoad_Rival_1:
# 27 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	goto VictoryRoad_Rival2
	return


VictoryRoad_Rival2::
# 40 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	lock
# 41 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	faceplayer
# 42 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	createfieldmugshotrival
# 43 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	msgbox VictoryRoad_Rival2_Text_0
# 46 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	release
	end


VictoryRoad_Rival_Text_0:
# 32 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	.string "Don't.$"

VictoryRoad_Rival2_Text_0:
# 43 "data/maps/VictoryRoadKanto_B1F/scripts.pory"
	.string "I just need to train more.\p"
	.string "That's all there ever is to it.$"
