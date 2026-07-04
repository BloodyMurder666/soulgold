# 1 "data/maps/BlackthornCity_Gym/scripts.pory"

# 2 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornCity_Gym_MapScripts::
# 3 "data/maps/BlackthornCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
# 4 "data/maps/BlackthornCity_Gym/scripts.pory"
	.byte 0
# 5 "data/maps/BlackthornCity_Gym/scripts.pory"

# 6 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_OnLoad::
# 7 "data/maps/BlackthornCity_Gym/scripts.pory"
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
# 8 "data/maps/BlackthornCity_Gym/scripts.pory"
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
# 9 "data/maps/BlackthornCity_Gym/scripts.pory"
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
# 10 "data/maps/BlackthornCity_Gym/scripts.pory"
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
# 11 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 12 "data/maps/BlackthornCity_Gym/scripts.pory"

# 13 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_Var1::
# 14 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge1
# 15 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 16 "data/maps/BlackthornCity_Gym/scripts.pory"

# 17 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_Var2::
# 18 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge1
# 19 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge2
# 20 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 21 "data/maps/BlackthornCity_Gym/scripts.pory"

# 22 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_Var3::
# 23 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge1
# 24 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge2
# 25 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge3
# 26 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 27 "data/maps/BlackthornCity_Gym/scripts.pory"

# 28 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_Var4::
# 29 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge1
# 30 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge2
# 31 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge3
# 32 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge4
# 33 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 34 "data/maps/BlackthornCity_Gym/scripts.pory"

# 35 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_TriggerBridge1::
# 36 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge1
# 37 "data/maps/BlackthornCity_Gym/scripts.pory"
	playse SE_BANG
# 38 "data/maps/BlackthornCity_Gym/scripts.pory"
	special DrawWholeMapView
# 39 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_BLACKTHORN_GYM_STATE, 1
# 40 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 41 "data/maps/BlackthornCity_Gym/scripts.pory"

# 42 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_BuildBridge1::
# 43 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 47, 0x4DA, FALSE
# 44 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 48, 0x4DA, FALSE
# 45 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 49, 0x4DA, FALSE
# 46 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 50, 0x4DA, FALSE
# 47 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 51, 0x4DA, FALSE
# 48 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 52, 0x4DA, FALSE
# 49 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 53, 0x4DA, FALSE
# 50 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 54, 0x4DA, FALSE
# 51 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 47, 0x4DA, FALSE
# 52 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 48, 0x4DA, FALSE
# 53 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 49, 0x4DA, FALSE
# 54 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 50, 0x4DA, FALSE
# 55 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 51, 0x4DA, FALSE
# 56 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 52, 0x4DA, FALSE
# 57 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 53, 0x4DA, FALSE
# 58 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 54, 0x4DA, FALSE
# 59 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 47, 0x4DA, FALSE
# 60 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 48, 0x4DA, FALSE
# 61 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 49, 0x4DA, FALSE
# 62 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 50, 0x4DA, FALSE
# 63 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 51, 0x4DA, FALSE
# 64 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 52, 0x4DA, FALSE
# 65 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 53, 0x4DA, FALSE
# 66 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 54, 0x4DA, FALSE
# 67 "data/maps/BlackthornCity_Gym/scripts.pory"
	return
# 68 "data/maps/BlackthornCity_Gym/scripts.pory"

# 69 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_TriggerBridge2::
# 70 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge2
# 71 "data/maps/BlackthornCity_Gym/scripts.pory"
	playse SE_BANG
# 72 "data/maps/BlackthornCity_Gym/scripts.pory"
	special DrawWholeMapView
# 73 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_BLACKTHORN_GYM_STATE, 2
# 74 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 75 "data/maps/BlackthornCity_Gym/scripts.pory"

# 76 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_BuildBridge2::
# 77 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 35, 0x4DA, FALSE
# 78 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 36, 0x4DA, FALSE
# 79 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 37, 0x4DA, FALSE
# 80 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 38, 0x4DA, FALSE
# 81 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 39, 0x4DA, FALSE
# 82 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 40, 0x4DA, FALSE
# 83 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 35, 0x4DA, FALSE
# 84 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 36, 0x4DA, FALSE
# 85 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 37, 0x4DA, FALSE
# 86 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 38, 0x4DA, FALSE
# 87 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 39, 0x4DA, FALSE
# 88 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 40, 0x4DA, FALSE
# 89 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 35, 0x4DA, FALSE
# 90 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 36, 0x4DA, FALSE
# 91 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 37, 0x4DA, FALSE
# 92 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 38, 0x4DA, FALSE
# 93 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 39, 0x4DA, FALSE
# 94 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 40, 0x4DA, FALSE
# 95 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 32, 0x4D9, FALSE
# 96 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 32, 0x4D9, FALSE
# 97 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 32, 0x4D9, FALSE
# 98 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 35, 0x4E1, TRUE
# 99 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 35, 0x4E1, TRUE
# 100 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 35, 0x4E1, TRUE
# 101 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 33, 0x4DA, FALSE
# 102 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 34, 0x4DA, FALSE
# 103 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 33, 0x4DA, FALSE
# 104 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 34, 0x4DA, FALSE
# 105 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 33, 0x4DA, FALSE
# 106 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 34, 0x4DA, FALSE
# 107 "data/maps/BlackthornCity_Gym/scripts.pory"
	return
# 108 "data/maps/BlackthornCity_Gym/scripts.pory"

# 109 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_TriggerBridge3::
# 110 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge3
# 111 "data/maps/BlackthornCity_Gym/scripts.pory"
	playse SE_BANG
# 112 "data/maps/BlackthornCity_Gym/scripts.pory"
	special DrawWholeMapView
# 113 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_BLACKTHORN_GYM_STATE, 3
# 114 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 115 "data/maps/BlackthornCity_Gym/scripts.pory"

# 116 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_BuildBridge3::
# 117 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 26, 0x4D9, FALSE
# 118 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 26, 0x4D9, FALSE
# 119 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 26, 0x4D9, FALSE
# 120 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 26, 0x4D9, FALSE
# 121 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 26, 0x4D9, FALSE
# 122 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 26, 0x4D9, FALSE
# 123 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 23, 26, 0x4D9, FALSE
# 124 "data/maps/BlackthornCity_Gym/scripts.pory"

# 125 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 29, 0x4E1, TRUE
# 126 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 29, 0x4E1, TRUE
# 127 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 29, 0x4E1, TRUE
# 128 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 29, 0x4E1, TRUE
# 129 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 29, 0x4E1, TRUE
# 130 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 29, 0x4E1, TRUE
# 131 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 23, 29, 0x4E1, TRUE
# 132 "data/maps/BlackthornCity_Gym/scripts.pory"

# 133 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 27, 0x4DA, FALSE
# 134 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 17, 28, 0x4DA, FALSE
# 135 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 27, 0x4DA, FALSE
# 136 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 18, 28, 0x4DA, FALSE
# 137 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 27, 0x4DA, FALSE
# 138 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 28, 0x4DA, FALSE
# 139 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 27, 0x4DA, FALSE
# 140 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 28, 0x4DA, FALSE
# 141 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 27, 0x4DA, FALSE
# 142 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 28, 0x4DA, FALSE
# 143 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 27, 0x4DA, FALSE
# 144 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 22, 28, 0x4DA, FALSE
# 145 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 23, 27, 0x4DA, FALSE
# 146 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 23, 28, 0x4DA, FALSE
# 147 "data/maps/BlackthornCity_Gym/scripts.pory"
	return	
# 148 "data/maps/BlackthornCity_Gym/scripts.pory"

# 149 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_TriggerBridge4::
# 150 "data/maps/BlackthornCity_Gym/scripts.pory"
	call BlackthornGym_MapScript_BuildBridge4
# 151 "data/maps/BlackthornCity_Gym/scripts.pory"
	playse SE_BANG
# 152 "data/maps/BlackthornCity_Gym/scripts.pory"
	special DrawWholeMapView
# 153 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_BLACKTHORN_GYM_STATE, 4
# 154 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 155 "data/maps/BlackthornCity_Gym/scripts.pory"

# 156 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_MapScript_BuildBridge4::
# 157 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 11, 0x4DA, FALSE
# 158 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 12, 0x4DA, FALSE
# 159 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 13, 0x4DA, FALSE
# 160 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 14, 0x4DA, FALSE
# 161 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 19, 15, 0x4DA, FALSE
# 162 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 11, 0x4DA, FALSE
# 163 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 12, 0x4DA, FALSE
# 164 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 13, 0x4DA, FALSE
# 165 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 14, 0x4DA, FALSE
# 166 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 20, 15, 0x4DA, FALSE
# 167 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 11, 0x4DA, FALSE
# 168 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 12, 0x4DA, FALSE
# 169 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 13, 0x4DA, FALSE
# 170 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 14, 0x4DA, FALSE
# 171 "data/maps/BlackthornCity_Gym/scripts.pory"
	setmetatile 21, 15, 0x4DA, FALSE
# 172 "data/maps/BlackthornCity_Gym/scripts.pory"
	return
# 173 "data/maps/BlackthornCity_Gym/scripts.pory"

# 174 "data/maps/BlackthornCity_Gym/scripts.pory"

# 175 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Cody::
# 176 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_CODY BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
# 177 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
# 178 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 179 "data/maps/BlackthornCity_Gym/scripts.pory"

# 180 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Fran::
# 181 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_FRAN BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
# 182 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
# 183 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 184 "data/maps/BlackthornCity_Gym/scripts.pory"

# 185 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Paul::
# 186 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PAUL BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
# 187 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
# 188 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 189 "data/maps/BlackthornCity_Gym/scripts.pory"

# 190 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Mike::
# 191 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MIKE BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
# 192 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
# 193 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 194 "data/maps/BlackthornCity_Gym/scripts.pory"

# 195 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Lola::
# 196 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LOLA BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
# 197 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
# 198 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 199 "data/maps/BlackthornCity_Gym/scripts.pory"

# 200 "data/maps/BlackthornCity_Gym/scripts.pory"

# 201 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Clair::
# 202 "data/maps/BlackthornCity_Gym/scripts.pory"
	lock
# 203 "data/maps/BlackthornCity_Gym/scripts.pory"
	faceplayer
# 204 "data/maps/BlackthornCity_Gym/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
# 205 "data/maps/BlackthornCity_Gym/scripts.pory"
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
# 206 "data/maps/BlackthornCity_Gym/scripts.pory"
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
# 207 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
# 208 "data/maps/BlackthornCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_CLAIR_1, BlackthornGym_Text_ClairWinText
# 209 "data/maps/BlackthornCity_Gym/scripts.pory"
	createfieldmugshot MUGSHOT_CLAIR
# 210 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
# 211 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_0x8008, 8
# 212 "data/maps/BlackthornCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 213 "data/maps/BlackthornCity_Gym/scripts.pory"
	setvar VAR_BLACKTHORN_CITY_STATE, 2
# 214 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 215 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 216 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 217 "data/maps/BlackthornCity_Gym/scripts.pory"

# 218 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_ClairDuringChallenge::
# 219 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
# 220 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 221 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 222 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 223 "data/maps/BlackthornCity_Gym/scripts.pory"

# 224 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Clair_Defeated::
# 225 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
# 226 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 227 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 228 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 229 "data/maps/BlackthornCity_Gym/scripts.pory"

# 230 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_ClairAfterLeague::
# 231 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
# 232 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 233 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 234 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 235 "data/maps/BlackthornCity_Gym/scripts.pory"

# 236 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairIntroText:
# 237 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I am Clair.\p"
# 238 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "The world's best dragon master.\p"
# 239 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I can hold my own against even the\n"
# 240 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Pokémon League's Elite Four.\p"
# 241 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Do you still want to take me on?\p"
# 242 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "…Fine. Let's do it!\p"
# 243 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "As a Gym Leader, I will use my full\n"
# 244 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "power against any opponent!$"
# 245 "data/maps/BlackthornCity_Gym/scripts.pory"

# 246 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairWinText:
# 247 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I lost?\p"
# 248 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I don't believe it. There must be\n"
# 249 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "some mistake…$"
# 250 "data/maps/BlackthornCity_Gym/scripts.pory"

# 251 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairText_GoToDragonsDen:
# 252 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I won't admit this.\p"
# 253 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I may have lost, but you're still\n"
# 254 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "not ready for the Pokémon League.\p"
# 255 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I know. You should take the dragon\n"
# 256 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "user challenge.\p"
# 257 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Behind this Gym is a place called\n"
# 258 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Dragon's Den.\p"
# 259 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "There is a small shrine at its\n"
# 260 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "center. Go there.\p"
# 261 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "If you can prove that you've lost\n"
# 262 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "your lazy ideals, I will recognize\l"
# 263 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "you as a trainer worthy of a Gym\l"
# 264 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Badge!$"
# 265 "data/maps/BlackthornCity_Gym/scripts.pory"

# 266 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairText_TooMuchToExpect:
# 267 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "What's the matter?\p"
# 268 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Is it too much to expect of you?$"
# 269 "data/maps/BlackthornCity_Gym/scripts.pory"

# 270 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairText_YouKeptMeWaiting:
# 271 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You've kept me waiting!\p"
# 272 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Here! Take this!$"
# 273 "data/maps/BlackthornCity_Gym/scripts.pory"

# 274 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairText_DescribeTM:
# 275 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "That contains Dragon Claw.\p"
# 276 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You can figure out what it does.$"
# 277 "data/maps/BlackthornCity_Gym/scripts.pory"

# 278 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairText_League:
# 279 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "What's the matter?\p"
# 280 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Aren't you headed to the Pokémon\n"
# 281 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "League?\p"
# 282 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Don't you know where it is?\p"
# 283 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "From here, go to New Bark Town.\p"
# 284 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Then Surf east. The route there is\n"
# 285 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "very tough.\p"
# 286 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Don't you dare lose at the Pokémon\n"
# 287 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "League!\p"
# 288 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "If you do, I'll feel even worse\n"
# 289 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "about having lost to you!\p"
# 290 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Give it everything you've got.$"
# 291 "data/maps/BlackthornCity_Gym/scripts.pory"

# 292 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairAfterLeague:
# 293 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You did it, huh?\p"
# 294 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You are now the Johto Champ.$"
# 295 "data/maps/BlackthornCity_Gym/scripts.pory"

# 296 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairRematchText:
# 297 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You did it, huh?\p"
# 298 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You are now the Johto Champ.\p"
# 299 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You've proven your strength but can\n"
# 300 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "you handle me again?\p"
# 301 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "As a Dragon Master, I won't hold\n"
# 302 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "back.\p"
# 303 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Not this time.\p"
# 304 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Want to have a rematch with me?$"
# 305 "data/maps/BlackthornCity_Gym/scripts.pory"

# 306 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_ClairRematchDefeatText:
# 307 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I lost?\p"
# 308 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Again?\p"
# 309 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I don't believe it. There must be\n"
# 310 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "some mistake…$"
# 311 "data/maps/BlackthornCity_Gym/scripts.pory"

# 312 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermCodySeenText:
# 313 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I just got access to use Dragon-\n"
# 314 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "type Pokémon!$"
# 315 "data/maps/BlackthornCity_Gym/scripts.pory"

# 316 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermCodyBeatenText:
# 317 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Rats! If only I had a Dragonite!$"
# 318 "data/maps/BlackthornCity_Gym/scripts.pory"

# 319 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermCodyAfterBattleText:
# 320 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Members of our dragon-user clan\n"
# 321 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "can use dragon Pokémon only after\l"
# 322 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "our Master allows it.$"
# 323 "data/maps/BlackthornCity_Gym/scripts.pory"

# 324 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfFranSeenText:
# 325 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I can't allow a nameless trainer\n"
# 326 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "past me!\p"
# 327 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Clair would be livid if I did!$"
# 328 "data/maps/BlackthornCity_Gym/scripts.pory"

# 329 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfFranBeatenText:
# 330 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Awww… I lost…$"
# 331 "data/maps/BlackthornCity_Gym/scripts.pory"

# 332 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfFranAfterBattleText:
# 333 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Uh-oh… Clair is going to be mad…$"
# 334 "data/maps/BlackthornCity_Gym/scripts.pory"

# 335 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermPaulSeenText:
# 336 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Your first battle against dragons?\p"
# 337 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I'll show you how tough they are!$"
# 338 "data/maps/BlackthornCity_Gym/scripts.pory"

# 339 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermPaulBeatenText:
# 340 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "My dragon Pokémon lost?$"
# 341 "data/maps/BlackthornCity_Gym/scripts.pory"

# 342 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermPaulAfterBattleText:
# 343 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Lance told you that he'd like to\n"
# 344 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "see you again?\p"
# 345 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Not a chance!$"
# 346 "data/maps/BlackthornCity_Gym/scripts.pory"

# 347 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermMikeSeenText:
# 348 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "My chance of losing? Not even one\n"
# 349 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "percent!$"
# 350 "data/maps/BlackthornCity_Gym/scripts.pory"

# 351 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermMikeBeatenText:
# 352 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "That's odd.$"
# 353 "data/maps/BlackthornCity_Gym/scripts.pory"

# 354 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainermMikeAfterBattleText:
# 355 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "I know my short-comings now.\p"
# 356 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Thanks for showing me!$"
# 357 "data/maps/BlackthornCity_Gym/scripts.pory"

# 358 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfLolaSeenText:
# 359 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Dragons are sacred Pokémon.\p"
# 360 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "They are full of life energy.\p"
# 361 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "If you're not serious, you won't\n"
# 362 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "be able to beat them.$"
# 363 "data/maps/BlackthornCity_Gym/scripts.pory"

# 364 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfLolaBeatenText:
# 365 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Way to go!$"
# 366 "data/maps/BlackthornCity_Gym/scripts.pory"

# 367 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
# 368 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Dragons are weak against Dragon-\n"
# 369 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "type moves.$"
# 370 "data/maps/BlackthornCity_Gym/scripts.pory"

# 371 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_GymGuy::
# 372 "data/maps/BlackthornCity_Gym/scripts.pory"
	lock
# 373 "data/maps/BlackthornCity_Gym/scripts.pory"
	faceplayer
# 374 "data/maps/BlackthornCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, EcruteakCity_Gym_EventScript_GymGuy2
# 375 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
# 376 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 377 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 378 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 379 "data/maps/BlackthornCity_Gym/scripts.pory"
	
# 380 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_GymGuy2::
# 381 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
# 382 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 383 "data/maps/BlackthornCity_Gym/scripts.pory"
	end	
# 384 "data/maps/BlackthornCity_Gym/scripts.pory"

# 385 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_GuideText:
# 386 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Yo! Champ in making!\p"
# 387 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "It's been a long journey, but we\n"
# 388 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "are almost done! Count on me!\p"
# 389 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "While Clair looks up to the Dragon\n"
# 390 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Master, Lance, she's managed to\l"
# 391 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "create her own identity with a\l"
# 392 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "team consisting of dragons from\l"
# 393 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "the sea.\p"
# 394 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Dragons are supposed to be\n"
# 395 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "weak against Ice-type moves,\l"
# 396 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "but you'll need some Dragon-type\l"
# 397 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "or Fairy-type moves of your own if\l"
# 398 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "you want to win.$"
# 399 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You got this!$"
# 400 "data/maps/BlackthornCity_Gym/scripts.pory"

# 401 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_GuideWinText:
# 402 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You were great to beat Clair!\p"
# 403 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "All that's left is the Pokémon\n"
# 404 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "League challenge.\p"
# 405 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "You're on the way to becoming the\n"
# 406 "data/maps/BlackthornCity_Gym/scripts.pory"
    .string "Pokémon Champion!$"
# 407 "data/maps/BlackthornCity_Gym/scripts.pory"

# 408 "data/maps/BlackthornCity_Gym/scripts.pory"

# 409 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Statue::
# 410 "data/maps/BlackthornCity_Gym/scripts.pory"
	lock
# 411 "data/maps/BlackthornCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_Statue2
# 412 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
# 413 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 414 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 415 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 416 "data/maps/BlackthornCity_Gym/scripts.pory"

# 417 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_EventScript_Statue2::
# 418 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 419 "data/maps/BlackthornCity_Gym/scripts.pory"
	closemessage
# 420 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
# 421 "data/maps/BlackthornCity_Gym/scripts.pory"
	end
# 422 "data/maps/BlackthornCity_Gym/scripts.pory"

# 423 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_GymStatue:
# 424 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "Blackthorn City Pokémon Gym$"
# 425 "data/maps/BlackthornCity_Gym/scripts.pory"

# 426 "data/maps/BlackthornCity_Gym/scripts.pory"
BlackthornGym_Text_GymStatueCertified:
# 427 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "Blackthorn City Pokémon Gym\p"
# 428 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "Clair's Certified Trainers:\n"
# 429 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "{PLAYER}$"

BlackthornCity_Gym_EventScript_Kingdra::
# 432 "data/maps/BlackthornCity_Gym/scripts.pory"
	lock
# 433 "data/maps/BlackthornCity_Gym/scripts.pory"
	faceplayer
# 434 "data/maps/BlackthornCity_Gym/scripts.pory"
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
# 435 "data/maps/BlackthornCity_Gym/scripts.pory"
	msgbox BlackthornCity_Gym_EventScript_Kingdra_Text_0, MSGBOX_NPC
# 436 "data/maps/BlackthornCity_Gym/scripts.pory"
	waitmoncry
# 437 "data/maps/BlackthornCity_Gym/scripts.pory"
	release
	end


BlackthornCity_Gym_EventScript_Kingdra_Text_0:
# 435 "data/maps/BlackthornCity_Gym/scripts.pory"
	.string "King!!$"
