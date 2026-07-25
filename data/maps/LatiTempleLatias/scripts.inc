LatiTempleLatias_MapScripts::
# 2 "data/maps/LatiTempleLatias/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LatiTempleLatias_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LatiTempleLatias_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
	return


LatiTemple_Latias::
# 8 "data/maps/LatiTempleLatias/scripts.pory"
	lock
# 9 "data/maps/LatiTempleLatias/scripts.pory"
	faceplayer
# 10 "data/maps/LatiTempleLatias/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_LATIAS, 80, LOCALID_LATIAS, FLAG_HIDE_LATIAS, 3, SPECIES_NONE, 110, MOVE_MIST_BALL, MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT
# 12 "data/maps/LatiTempleLatias/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq LatiTemple_Latias_2
LatiTemple_Latias_1:
# 15 "data/maps/LatiTempleLatias/scripts.pory"
	release
	end

LatiTemple_Latias_2:
# 13 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_CAUGHT_LATIAS
	goto LatiTemple_Latias_1


LatiTemple_Switch1::
# 20 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 21 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH1, LatiTemple_Switch1_2
# 24 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH1
LatiTemple_Switch1_1:
# 26 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 27 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 28 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 29 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 30 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch1_2:
# 22 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH1
	goto LatiTemple_Switch1_1


LatiTemple_Switch2::
# 34 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 35 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH2, LatiTemple_Switch2_2
# 38 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH2
LatiTemple_Switch2_1:
# 40 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 41 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 42 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 43 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 44 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch2_2:
# 36 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH2
	goto LatiTemple_Switch2_1


LatiTemple_Switch3::
# 48 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 49 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH3, LatiTemple_Switch3_2
# 52 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH3
LatiTemple_Switch3_1:
# 54 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 55 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 56 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 57 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 58 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch3_2:
# 50 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH3
	goto LatiTemple_Switch3_1


LatiTemple_Switch4::
# 62 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 63 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH4, LatiTemple_Switch4_2
# 66 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH4
LatiTemple_Switch4_1:
# 68 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 69 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 70 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 71 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 72 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch4_2:
# 64 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH4
	goto LatiTemple_Switch4_1


LatiTemple_Switch5::
# 76 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 77 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH5, LatiTemple_Switch5_2
# 80 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH5
LatiTemple_Switch5_1:
# 82 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 83 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 84 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 85 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 86 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch5_2:
# 78 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH5
	goto LatiTemple_Switch5_1


LatiTemple_RefreshPuzzle::
# 90 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch1State
# 91 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch2State
# 92 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch3State
# 93 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch4State
# 94 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch5State
	return


LatiTemple_SetSwitch1State::
# 99 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH1, LatiTemple_SetSwitch1State_2
# 113 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 17, 27, METATILE_LatiTemple_ActiveGray, FALSE
# 114 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 33, 33, METATILE_LatiTemple_ActiveGray, FALSE
# 116 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 36, 21, METATILE_LatiTemple_InactiveGreen, TRUE
# 117 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 23, METATILE_LatiTemple_InactiveGreen, TRUE
# 119 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 17, METATILE_LatiTemple_InactiveGray, TRUE
# 120 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 34, 1, METATILE_LatiTemple_InactiveGray, TRUE
# 122 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 4, METATILE_LatiTemple_ActiveGreen, FALSE
# 123 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 31, METATILE_LatiTemple_ActiveGreen, FALSE
# 124 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 21, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch1State_1:
	return

LatiTemple_SetSwitch1State_2:
# 100 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 17, 27, METATILE_LatiTemple_InactiveGray, TRUE
# 101 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 33, 33, METATILE_LatiTemple_InactiveGray, TRUE
# 103 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 36, 21, METATILE_LatiTemple_ActiveGreen, FALSE
# 104 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 23, METATILE_LatiTemple_ActiveGreen, FALSE
# 106 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 17, METATILE_LatiTemple_ActiveGray, FALSE
# 107 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 34, 1, METATILE_LatiTemple_ActiveGray, FALSE
# 109 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 4, METATILE_LatiTemple_InactiveGreen, TRUE
# 110 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 31, METATILE_LatiTemple_InactiveGreen, TRUE
# 111 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 21, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch1State_1


LatiTemple_SetSwitch2State::
# 130 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH2, LatiTemple_SetSwitch2State_2
# 135 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 25, METATILE_LatiTemple_InactiveGray, TRUE
# 136 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 54, 20, METATILE_LatiTemple_InactiveGray, TRUE
# 137 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 3, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch2State_1:
	return

LatiTemple_SetSwitch2State_2:
# 131 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 25, METATILE_LatiTemple_ActiveGray, FALSE
# 132 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 54, 20, METATILE_LatiTemple_ActiveGray, FALSE
# 133 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 3, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch2State_1


LatiTemple_SetSwitch3State::
# 143 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH3, LatiTemple_SetSwitch3State_2
# 154 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 37, 30, METATILE_LatiTemple_ActiveBlue, FALSE
# 155 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 28, 21, METATILE_LatiTemple_ActiveBlue, FALSE
# 157 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 11, METATILE_LatiTemple_ActiveGreen, FALSE
# 158 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 43, 18, METATILE_LatiTemple_ActiveGreen, FALSE
# 160 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 23, METATILE_LatiTemple_InactiveBlue, TRUE
# 161 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 14, 10, METATILE_LatiTemple_InactiveBlue, TRUE
# 162 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 46, 21, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch3State_1:
	return

LatiTemple_SetSwitch3State_2:
# 144 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 37, 30, METATILE_LatiTemple_InactiveBlue, TRUE
# 145 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 28, 21, METATILE_LatiTemple_InactiveBlue, TRUE
# 147 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 11, METATILE_LatiTemple_InactiveGreen, TRUE
# 148 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 43, 18, METATILE_LatiTemple_InactiveGreen, TRUE
# 150 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 23, METATILE_LatiTemple_ActiveBlue, FALSE
# 151 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 14, 10, METATILE_LatiTemple_ActiveBlue, FALSE
# 152 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 46, 21, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch3State_1


LatiTemple_SetSwitch4State::
# 168 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH4, LatiTemple_SetSwitch4State_2
# 173 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 30, METATILE_LatiTemple_InactiveBlue, TRUE
# 174 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 41, 31, METATILE_LatiTemple_InactiveBlue, TRUE
# 175 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 15, 6, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch4State_1:
	return

LatiTemple_SetSwitch4State_2:
# 169 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 30, METATILE_LatiTemple_ActiveBlue, FALSE
# 170 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 41, 31, METATILE_LatiTemple_ActiveBlue, FALSE
# 171 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 15, 6, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch4State_1


LatiTemple_SetSwitch5State::
# 181 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH5, LatiTemple_SetSwitch5State_2
# 189 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 30, 5, METATILE_LatiTemple_ActiveBlue, FALSE
# 190 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 11, METATILE_LatiTemple_ActiveBlue, FALSE
# 192 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 12, 30, METATILE_LatiTemple_InactiveGreen, TRUE
# 193 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 5, 23, METATILE_LatiTemple_InactiveGreen, TRUE
# 194 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 28, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch5State_1:
	return

LatiTemple_SetSwitch5State_2:
# 182 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 30, 5, METATILE_LatiTemple_InactiveBlue, TRUE
# 183 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 11, METATILE_LatiTemple_InactiveBlue, TRUE
# 185 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 12, 30, METATILE_LatiTemple_ActiveGreen, FALSE
# 186 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 5, 23, METATILE_LatiTemple_ActiveGreen, FALSE
# 187 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 28, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch5State_1

