MtMortar_Depths_1_MapScripts::
# 2 "data/maps/MtMortar_Depths_1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_MTMORTAR_DEPTHS_PUZZLE1SOLVED, MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_2
MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 8 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_MTMORTAR_DEPTHS_HEATRANPUZZLED, MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 18, 0x4E5, FALSE
# 5 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 19, 0x4E5, FALSE
# 6 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 20, 0x4E5, FALSE
	goto MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_1

MtMortar_Depths_1_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 9 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 1, 0x414, FALSE
# 10 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 0, 0x40C, FALSE
# 12 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 4, 0x4F3, FALSE
# 13 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 38, 6, 0x4F3, FALSE
# 14 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 39, 6, 0x4F3, FALSE
# 15 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 6, 0x4F3, FALSE
# 16 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 41, 6, 0x4F3, FALSE
# 17 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 42, 6, 0x4F3, FALSE
# 18 "data/maps/MtMortar_Depths_1/scripts.pory"
	setvar VAR_TEMP_E, 1
	return


firetitePuzzleButton1::
# 26 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 27 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_A, 1
# 28 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 29 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 27, 14, 0x4E5, FALSE
# 30 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 31 "data/maps/MtMortar_Depths_1/scripts.pory"
	call firetitePuzzleCall
# 32 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_0, 1
# 33 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


firetitePuzzleButton2::
# 37 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 38 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_A, 1
# 39 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 40 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 12, 11, 0x4E5, FALSE
# 41 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 42 "data/maps/MtMortar_Depths_1/scripts.pory"
	call firetitePuzzleCall
# 43 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_1, 1
# 44 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


firetitePuzzleButton3::
# 48 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 49 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_A, 1
# 50 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 51 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 23, 34, 0x4E6, FALSE
# 52 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 53 "data/maps/MtMortar_Depths_1/scripts.pory"
	call firetitePuzzleCall
# 54 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_TEMP_2, 1
# 55 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


firetitePuzzleCall::
# 60 "data/maps/MtMortar_Depths_1/scripts.pory"
	compare VAR_TEMP_A, 3
	goto_if_ge firetitePuzzleCall_2
firetitePuzzleCall_1:
	return

firetitePuzzleCall_2:
# 61 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_CLICK
# 62 "data/maps/MtMortar_Depths_1/scripts.pory"
	delay 30
# 63 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 18, 0x404, FALSE
# 64 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 19, 0x404, FALSE
# 65 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 20, 20, 0x404, FALSE
# 66 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_MTMORTAR_DEPTHS_PUZZLE1SOLVED
# 67 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
	goto firetitePuzzleCall_1


heatranPuzzleButtonCorrect1::
# 79 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_3, heatranPuzzleButtonCorrect1_2
# 83 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 84 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_3
# 85 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 86 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 4, 0x4F3, FALSE
# 87 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 88 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 89 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 90 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect1_2:
# 80 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleButtonCorrect2::
# 94 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_6, heatranPuzzleButtonCorrect2_2
# 98 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 99 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_6
# 100 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 101 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 38, 6, 0x4F3, FALSE
# 102 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 103 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 104 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 105 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect2_2:
# 95 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleButtonCorrect3::
# 109 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_7, heatranPuzzleButtonCorrect3_2
# 113 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 114 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_7
# 115 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 116 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 39, 6, 0x4F3, FALSE
# 117 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 118 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 119 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 120 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect3_2:
# 110 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleButtonCorrect4::
# 124 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_8, heatranPuzzleButtonCorrect4_2
# 128 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 129 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_8
# 130 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 131 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 6, 0x4F3, FALSE
# 132 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 133 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 134 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 135 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect4_2:
# 125 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleButtonCorrect5::
# 139 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_9, heatranPuzzleButtonCorrect5_2
# 143 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 144 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_9
# 145 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 146 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 41, 6, 0x4F3, FALSE
# 147 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 148 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 149 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 150 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect5_2:
# 140 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleButtonCorrect6::
# 154 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_A, heatranPuzzleButtonCorrect6_2
# 158 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 159 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_A
# 160 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 161 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 42, 6, 0x4F3, FALSE
# 162 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 163 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 164 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 165 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleButtonCorrect6_2:
# 155 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleWrongButton1::
# 172 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_1, heatranPuzzleWrongButton1_2
# 176 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 177 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_1
# 178 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_WRONG_BUTTON_HEATRAN
# 179 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 180 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 38, 4, 0x4F3, FALSE
# 181 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 182 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 183 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 184 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleWrongButton1_2:
# 173 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleWrongButton2::
# 189 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_2, heatranPuzzleWrongButton2_2
# 193 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 194 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_2
# 195 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_WRONG_BUTTON_HEATRAN
# 196 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 197 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 39, 4, 0x4F3, FALSE
# 198 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 199 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 200 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 201 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleWrongButton2_2:
# 190 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleWrongButton3::
# 206 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_4, heatranPuzzleWrongButton3_2
# 210 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 211 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_4
# 212 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_WRONG_BUTTON_HEATRAN
# 213 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 214 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 41, 4, 0x4F3, FALSE
# 215 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 216 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 217 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 218 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleWrongButton3_2:
# 207 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleWrongButton4::
# 223 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_TEMP_5, heatranPuzzleWrongButton4_2
# 227 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 228 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_TEMP_5
# 229 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_WRONG_BUTTON_HEATRAN
# 230 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_PIN
# 231 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 42, 4, 0x4F3, FALSE
# 232 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 233 "data/maps/MtMortar_Depths_1/scripts.pory"
	addvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 1
# 234 "data/maps/MtMortar_Depths_1/scripts.pory"
	call heatranPuzzleCall
# 235 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end

heatranPuzzleWrongButton4_2:
# 224 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleCall::
# 242 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto_if_set FLAG_WRONG_BUTTON_HEATRAN, heatranPuzzleCall_3
heatranPuzzleCall_1:
# 245 "data/maps/MtMortar_Depths_1/scripts.pory"
	compare VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 6
	goto_if_eq heatranPuzzleCall_7
heatranPuzzleCall_6:
	return

heatranPuzzleCall_2:
# 243 "data/maps/MtMortar_Depths_1/scripts.pory"
	goto heatranPuzzleReset
	goto heatranPuzzleCall_1

heatranPuzzleCall_3:
# 242 "data/maps/MtMortar_Depths_1/scripts.pory"
	compare VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 6
	goto_if_eq heatranPuzzleCall_2
	goto heatranPuzzleCall_1

heatranPuzzleCall_7:
# 246 "data/maps/MtMortar_Depths_1/scripts.pory"
	setflag FLAG_MTMORTAR_DEPTHS_HEATRANPUZZLED
# 247 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_BANG
# 248 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 1, 0x414, FALSE
# 249 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatile 40, 0, 0x40C, FALSE
# 250 "data/maps/MtMortar_Depths_1/scripts.pory"
	setvar VAR_TEMP_E, 1
# 251 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
	goto heatranPuzzleCall_6


heatranPuzzleReset::
# 259 "data/maps/MtMortar_Depths_1/scripts.pory"
	setvar VAR_MTMORTAR_DEPTHS_HEATRAN_BUTTONS, 0
# 260 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_WRONG_BUTTON_HEATRAN
# 261 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_1
# 262 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_2
# 263 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_3
# 264 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_4
# 265 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_5
# 266 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_6
# 267 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_7
# 268 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_8
# 269 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_9
# 270 "data/maps/MtMortar_Depths_1/scripts.pory"
	clearflag FLAG_TEMP_A
# 271 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_FAILURE
# 272 "data/maps/MtMortar_Depths_1/scripts.pory"
	waitse
# 273 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatileinrange 38, 4, 42, 4, 0x4E3
# 274 "data/maps/MtMortar_Depths_1/scripts.pory"
	setmetatileinrange 38, 6, 42, 6, 0x4E3
# 275 "data/maps/MtMortar_Depths_1/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 276 "data/maps/MtMortar_Depths_1/scripts.pory"
	special DrawWholeMapView
# 277 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleHint::
# 284 "data/maps/MtMortar_Depths_1/scripts.pory"
	msgbox heatranPuzzleHint_Text_0, MSGBOX_SIGN
	return


MtMortarDepthsHeatran::
# 289 "data/maps/MtMortar_Depths_1/scripts.pory"
	lock
# 290 "data/maps/MtMortar_Depths_1/scripts.pory"
	faceplayer
# 291 "data/maps/MtMortar_Depths_1/scripts.pory"
	legendaryencounter SPECIES_HEATRAN, 70, 1, FLAG_HIDE_HEATRAN
# 292 "data/maps/MtMortar_Depths_1/scripts.pory"
	release
	end


heatranPuzzleHint_Text_0:
# 284 "data/maps/MtMortar_Depths_1/scripts.pory"
	.string "Face of the heat,\n"
	.string "wielder of the magma storm.$"
