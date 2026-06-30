# 1 "data/maps/GoldenrodCity/scripts.pory"

# 2 "data/maps/GoldenrodCity/scripts.pory"

# 3 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_MapScripts::
# 4 "data/maps/GoldenrodCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_OnTransition
# 5 "data/maps/GoldenrodCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Goldenrod_OnFrame
# 6 "data/maps/GoldenrodCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_OnLoad
# 7 "data/maps/GoldenrodCity/scripts.pory"
	.byte 0
# 8 "data/maps/GoldenrodCity/scripts.pory"

# 9 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_OnLoad::
# 10 "data/maps/GoldenrodCity/scripts.pory"
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
# 11 "data/maps/GoldenrodCity/scripts.pory"
	end
# 12 "data/maps/GoldenrodCity/scripts.pory"

# 13 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Trigger:: @flagheap
# 14 "data/maps/GoldenrodCity/scripts.pory"
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
# 15 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_VISITED_GOLDENROD_CITY
# 16 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 17 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_BILL
# 18 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 19 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
# 20 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
# 21 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 22 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 23 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_RADIOTOWER_OAK
# 24 "data/maps/GoldenrodCity/scripts.pory"
	
# 25 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
# 26 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
# 27 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 28 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_RETURN
# 29 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_FRUSTRATION
# 30 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_BIKE
# 31 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
# 32 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_BILL_GIFTMON
# 33 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_SYS_PC_BILL
# 34 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RETURNED_MACHINE_PART
# 35 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 36 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_1
# 37 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_2
# 38 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_3
# 39 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_COMPLETED_SWITCHES
# 40 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_ENABLE_RADIO
# 41 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_KANTO_RADIO_GOT
# 42 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
# 43 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_SKILL_SWAP
# 44 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_RADIOTOWER_GATE
# 45 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 46 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
# 47 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_QUICK_CLAW
# 48 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MAGNET
# 49 "data/maps/GoldenrodCity/scripts.pory"

# 50 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_BUG_CONTEST_STATE, 0
# 51 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_KENYA, 0
# 52 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 0
# 53 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TRAIN, 0
# 54 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_ELEVATOR, 0
# 55 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 1
# 56 "data/maps/GoldenrodCity/scripts.pory"
	release
# 57 "data/maps/GoldenrodCity/scripts.pory"
	end
# 58 "data/maps/GoldenrodCity/scripts.pory"

# 59 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Elm_Togepi_Call::
# 60 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 61 "data/maps/GoldenrodCity/scripts.pory"
	pokenavcall GoldenrodCity_Text_ElmCall
# 62 "data/maps/GoldenrodCity/scripts.pory"
	waitmessage
# 63 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 64 "data/maps/GoldenrodCity/scripts.pory"
	release
# 65 "data/maps/GoldenrodCity/scripts.pory"
	return
# 66 "data/maps/GoldenrodCity/scripts.pory"

# 67 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_PokefanM::
# 68 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 69 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 70 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
# 71 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 72 "data/maps/GoldenrodCity/scripts.pory"
	release
# 73 "data/maps/GoldenrodCity/scripts.pory"
	end
# 74 "data/maps/GoldenrodCity/scripts.pory"

# 75 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster::
# 76 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
# 77 "data/maps/GoldenrodCity/scripts.pory"
	end
# 78 "data/maps/GoldenrodCity/scripts.pory"

# 79 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster2::
# 80 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
# 81 "data/maps/GoldenrodCity/scripts.pory"
	end
# 82 "data/maps/GoldenrodCity/scripts.pory"

# 83 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerF::
# 84 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 85 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 86 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
# 87 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
# 88 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 89 "data/maps/GoldenrodCity/scripts.pory"
	release
# 90 "data/maps/GoldenrodCity/scripts.pory"
	end
# 91 "data/maps/GoldenrodCity/scripts.pory"

# 92 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerFCleared::
# 93 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
# 94 "data/maps/GoldenrodCity/scripts.pory"
	end
# 95 "data/maps/GoldenrodCity/scripts.pory"

# 96 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Lass::
# 97 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 98 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 99 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
# 100 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 101 "data/maps/GoldenrodCity/scripts.pory"
	release
# 102 "data/maps/GoldenrodCity/scripts.pory"
	end
# 103 "data/maps/GoldenrodCity/scripts.pory"

# 104 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Gramps::
# 105 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 106 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 107 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
# 108 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 109 "data/maps/GoldenrodCity/scripts.pory"
	release
# 110 "data/maps/GoldenrodCity/scripts.pory"
	end
# 111 "data/maps/GoldenrodCity/scripts.pory"

# 112 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_NameRaterSign::
# 113 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
# 114 "data/maps/GoldenrodCity/scripts.pory"
	end
# 115 "data/maps/GoldenrodCity/scripts.pory"

# 116 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_RocketScout::
# 117 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 118 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
# 119 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 120 "data/maps/GoldenrodCity/scripts.pory"
	PLAYSE SE_PIN
# 121 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
# 122 "data/maps/GoldenrodCity/scripts.pory"
	delay 20
# 123 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 124 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
# 125 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 126 "data/maps/GoldenrodCity/scripts.pory"
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
# 127 "data/maps/GoldenrodCity/scripts.pory"
	release
# 128 "data/maps/GoldenrodCity/scripts.pory"
	end
# 129 "data/maps/GoldenrodCity/scripts.pory"

# 130 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket1::
# 131 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 132 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 133 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
# 134 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 135 "data/maps/GoldenrodCity/scripts.pory"
	release
# 136 "data/maps/GoldenrodCity/scripts.pory"
	end
# 137 "data/maps/GoldenrodCity/scripts.pory"

# 138 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket2::
# 139 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 140 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 141 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
# 142 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 143 "data/maps/GoldenrodCity/scripts.pory"
	release
# 144 "data/maps/GoldenrodCity/scripts.pory"
	end
# 145 "data/maps/GoldenrodCity/scripts.pory"

# 146 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket3::
# 147 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 148 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 149 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
# 150 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 151 "data/maps/GoldenrodCity/scripts.pory"
	release
# 152 "data/maps/GoldenrodCity/scripts.pory"
	end
# 153 "data/maps/GoldenrodCity/scripts.pory"

# 154 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket4::
# 155 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 156 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 157 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
# 158 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 159 "data/maps/GoldenrodCity/scripts.pory"
	release
# 160 "data/maps/GoldenrodCity/scripts.pory"
	end
# 161 "data/maps/GoldenrodCity/scripts.pory"

# 162 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket5::
# 163 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 164 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 165 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
# 166 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 167 "data/maps/GoldenrodCity/scripts.pory"
	release
# 168 "data/maps/GoldenrodCity/scripts.pory"
	end
# 169 "data/maps/GoldenrodCity/scripts.pory"

# 170 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket6::
# 171 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 172 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 173 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
# 174 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 175 "data/maps/GoldenrodCity/scripts.pory"
	release
# 176 "data/maps/GoldenrodCity/scripts.pory"
	end
# 177 "data/maps/GoldenrodCity/scripts.pory"

# 178 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Woman::
# 179 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 180 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 181 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
# 182 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 183 "data/maps/GoldenrodCity/scripts.pory"
	release
# 184 "data/maps/GoldenrodCity/scripts.pory"
	end
# 185 "data/maps/GoldenrodCity/scripts.pory"

# 186 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker::
# 187 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 188 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 189 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
# 190 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
# 191 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 192 "data/maps/GoldenrodCity/scripts.pory"
	release
# 193 "data/maps/GoldenrodCity/scripts.pory"
	end
# 194 "data/maps/GoldenrodCity/scripts.pory"

# 195 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker2::
# 196 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
# 197 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 198 "data/maps/GoldenrodCity/scripts.pory"
	release
# 199 "data/maps/GoldenrodCity/scripts.pory"
	end
# 200 "data/maps/GoldenrodCity/scripts.pory"

# 201 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Snubbull::
# 202 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 203 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 204 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 205 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 206 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
# 207 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 208 "data/maps/GoldenrodCity/scripts.pory"
	release
# 209 "data/maps/GoldenrodCity/scripts.pory"
	end
# 210 "data/maps/GoldenrodCity/scripts.pory"

# 211 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Mime::
# 212 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 213 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 214 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 215 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
# 216 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
# 217 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 218 "data/maps/GoldenrodCity/scripts.pory"
	release
# 219 "data/maps/GoldenrodCity/scripts.pory"
	end
# 220 "data/maps/GoldenrodCity/scripts.pory"

# 221 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignUnderground::
# 222 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 223 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
# 224 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 225 "data/maps/GoldenrodCity/scripts.pory"
	release
# 226 "data/maps/GoldenrodCity/scripts.pory"
	end
# 227 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignDept::
# 228 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 229 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
# 230 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 231 "data/maps/GoldenrodCity/scripts.pory"
	release
# 232 "data/maps/GoldenrodCity/scripts.pory"
	end
# 233 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignBike::
# 234 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 235 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
# 236 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 237 "data/maps/GoldenrodCity/scripts.pory"
	release
# 238 "data/maps/GoldenrodCity/scripts.pory"
	end
# 239 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignTrain::
# 240 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 241 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
# 242 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 243 "data/maps/GoldenrodCity/scripts.pory"
	release
# 244 "data/maps/GoldenrodCity/scripts.pory"
	end
# 245 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGym::
# 246 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 247 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
# 248 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 249 "data/maps/GoldenrodCity/scripts.pory"
	release
# 250 "data/maps/GoldenrodCity/scripts.pory"
	end
# 251 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignFlower::
# 252 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 253 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
# 254 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 255 "data/maps/GoldenrodCity/scripts.pory"
	release
# 256 "data/maps/GoldenrodCity/scripts.pory"
	end
# 257 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignRadio::
# 258 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 259 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
# 260 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 261 "data/maps/GoldenrodCity/scripts.pory"
	release
# 262 "data/maps/GoldenrodCity/scripts.pory"
	end
# 263 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGameCorner::
# 264 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 265 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
# 266 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 267 "data/maps/GoldenrodCity/scripts.pory"
	release
# 268 "data/maps/GoldenrodCity/scripts.pory"
	end
# 269 "data/maps/GoldenrodCity/scripts.pory"

# 270 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Beauty::
# 271 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 272 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 273 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
# 274 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 275 "data/maps/GoldenrodCity/scripts.pory"
	release
# 276 "data/maps/GoldenrodCity/scripts.pory"
	end
# 277 "data/maps/GoldenrodCity/scripts.pory"

# 278 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Beauty:
# 279 "data/maps/GoldenrodCity/scripts.pory"
	.string "This is the Goldenrod Gym!\p"
# 280 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our leader Whitney is not here\n"
# 281 "data/maps/GoldenrodCity/scripts.pory"
	.string "right now. She might be at the\l"
# 282 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio Tower.$"
# 283 "data/maps/GoldenrodCity/scripts.pory"

# 284 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Woman:
# 285 "data/maps/GoldenrodCity/scripts.pory"
	.string "I used to train in Whitney's Gym,\n"
# 286 "data/maps/GoldenrodCity/scripts.pory"
	.string "but all her crying gave me a\l"
# 287 "data/maps/GoldenrodCity/scripts.pory"
	.string "headache.$"
# 288 "data/maps/GoldenrodCity/scripts.pory"

# 289 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerDay:
# 290 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 291 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was night time... How long was I\l"
# 292 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 293 "data/maps/GoldenrodCity/scripts.pory"

# 294 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerNight:
# 295 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 296 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was day time... How long was I\l"
# 297 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 298 "data/maps/GoldenrodCity/scripts.pory"

# 299 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Snubbull:
# 300 "data/maps/GoldenrodCity/scripts.pory"
	.string "Audino: Audiiinii!$"
# 301 "data/maps/GoldenrodCity/scripts.pory"

# 302 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MrMime:
# 303 "data/maps/GoldenrodCity/scripts.pory"
	.string "............................$"
# 304 "data/maps/GoldenrodCity/scripts.pory"

# 305 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_ElmCall:
# 306 "data/maps/GoldenrodCity/scripts.pory"
	.string "Elm: Hello, {PLAYER}?\n"
# 307 "data/maps/GoldenrodCity/scripts.pory"
	.string "Has that egg hatched yet?\p"
# 308 "data/maps/GoldenrodCity/scripts.pory"
	.string "Once it hatches, don't forget to\n"
# 309 "data/maps/GoldenrodCity/scripts.pory"
	.string "bring it by the lab! I need to\l"
# 310 "data/maps/GoldenrodCity/scripts.pory"
	.string "see it!$"
# 311 "data/maps/GoldenrodCity/scripts.pory"

# 312 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_PokefanM:
# 313 "data/maps/GoldenrodCity/scripts.pory"
	.string "They built the new Radio Tower\n"
# 314 "data/maps/GoldenrodCity/scripts.pory"
	.string "to replace the old creaky one.$"
# 315 "data/maps/GoldenrodCity/scripts.pory"

# 316 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster1:
# 317 "data/maps/GoldenrodCity/scripts.pory"
	.string "I know there's a new Bike Shop,\n"
# 318 "data/maps/GoldenrodCity/scripts.pory"
	.string "but I can't find it anywhere.$"
# 319 "data/maps/GoldenrodCity/scripts.pory"

# 320 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1:
# 321 "data/maps/GoldenrodCity/scripts.pory"
	.string "Is that man in black dressed up\n"
# 322 "data/maps/GoldenrodCity/scripts.pory"
	.string "like a Team Rocket member?\p"
# 323 "data/maps/GoldenrodCity/scripts.pory"
	.string "How silly!$"
# 324 "data/maps/GoldenrodCity/scripts.pory"

# 325 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1_Cleared:
# 326 "data/maps/GoldenrodCity/scripts.pory"
	.string "Was that man in black really part\n"
# 327 "data/maps/GoldenrodCity/scripts.pory"
	.string "of Team Rocket? I can't believe it!$"
# 328 "data/maps/GoldenrodCity/scripts.pory"

# 329 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2:
# 330 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Radio Tower in Goldenrod City\n"
# 331 "data/maps/GoldenrodCity/scripts.pory"
	.string "is quite the landmark.\p"
# 332 "data/maps/GoldenrodCity/scripts.pory"
	.string "They're running a campaign now.\p"
# 333 "data/maps/GoldenrodCity/scripts.pory"
	.string "They'll give you a shiny new\n"
# 334 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio if you can pass their quiz.$"
# 335 "data/maps/GoldenrodCity/scripts.pory"

# 336 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2_GotCard:
# 337 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, your Pokégear already works\n"
# 338 "data/maps/GoldenrodCity/scripts.pory"
	.string "as a radio!$"
# 339 "data/maps/GoldenrodCity/scripts.pory"

# 340 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster2:
# 341 "data/maps/GoldenrodCity/scripts.pory"
	.string "E-he-he-he…\p"
# 342 "data/maps/GoldenrodCity/scripts.pory"
	.string "I got in trouble for playing in\n"
# 343 "data/maps/GoldenrodCity/scripts.pory"
	.string "the Dept.Store basement.$"
# 344 "data/maps/GoldenrodCity/scripts.pory"

# 345 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Lass:
# 346 "data/maps/GoldenrodCity/scripts.pory"
	.string "That man inside rates your\n"
# 347 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon nicknames.\p"
# 348 "data/maps/GoldenrodCity/scripts.pory"
	.string "He can even rename them.$"
# 349 "data/maps/GoldenrodCity/scripts.pory"

# 350 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Gramps:
# 351 "data/maps/GoldenrodCity/scripts.pory"
	.string "Whew! This city is so big,\n"
# 352 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can't find anything at all.$"
# 353 "data/maps/GoldenrodCity/scripts.pory"

# 354 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout1:
# 355 "data/maps/GoldenrodCity/scripts.pory"
	.string "So this is the Radio Tower…$"
# 356 "data/maps/GoldenrodCity/scripts.pory"

# 357 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout2:
# 358 "data/maps/GoldenrodCity/scripts.pory"
	.string "What do you want, pest?\n"
# 359 "data/maps/GoldenrodCity/scripts.pory"
	.string "Scram already!$"
# 360 "data/maps/GoldenrodCity/scripts.pory"

# 361 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket1:
# 362 "data/maps/GoldenrodCity/scripts.pory"
	.string "Stay out of the way!\n"
# 363 "data/maps/GoldenrodCity/scripts.pory"
	.string "Beat it, kid!$"
# 364 "data/maps/GoldenrodCity/scripts.pory"

# 365 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket2:
# 366 "data/maps/GoldenrodCity/scripts.pory"
	.string "Take over the Radio Tower…\p"
# 367 "data/maps/GoldenrodCity/scripts.pory"
	.string "What? It's none of your business!$"
# 368 "data/maps/GoldenrodCity/scripts.pory"

# 369 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket3:
# 370 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon? They're just tools\n"
# 371 "data/maps/GoldenrodCity/scripts.pory"
	.string "we use to make money!$"
# 372 "data/maps/GoldenrodCity/scripts.pory"

# 373 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket4:
# 374 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our dream will soon come true…\p"
# 375 "data/maps/GoldenrodCity/scripts.pory"
	.string "It was a long, hard struggle…$"
# 376 "data/maps/GoldenrodCity/scripts.pory"

# 377 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket5:
# 378 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, brat! You don't belong here!\n"
# 379 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get lost already!$"
# 380 "data/maps/GoldenrodCity/scripts.pory"

# 381 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket6:
# 382 "data/maps/GoldenrodCity/scripts.pory"
	.string "Come and taste the terror of\n"
# 383 "data/maps/GoldenrodCity/scripts.pory"
	.string "Team Rocket!$"
# 384 "data/maps/GoldenrodCity/scripts.pory"

# 385 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_StationSign:
# 386 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Station$"
# 387 "data/maps/GoldenrodCity/scripts.pory"

# 388 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RadioTowerSign:
# 389 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Radio Tower$"
# 390 "data/maps/GoldenrodCity/scripts.pory"

# 391 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_DeptStoreSign:
# 392 "data/maps/GoldenrodCity/scripts.pory"
	.string "Full Selection of Pokémon Goods!\p"
# 393 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Dept.Store$"
# 394 "data/maps/GoldenrodCity/scripts.pory"

# 395 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GymSign:
# 396 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Pokémon Gym\n"
# 397 "data/maps/GoldenrodCity/scripts.pory"
	.string "Leader: Whitney\p"
# 398 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Incredibly Pretty Girl!$"
# 399 "data/maps/GoldenrodCity/scripts.pory"

# 400 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CitySign:
# 401 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City\p"
# 402 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Festive City of Opulent Charm$"
# 403 "data/maps/GoldenrodCity/scripts.pory"

# 404 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_BikeShopSign:
# 405 "data/maps/GoldenrodCity/scripts.pory"
	.string "The World is a Cycle Path!\n"
# 406 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bike Shop$"
# 407 "data/maps/GoldenrodCity/scripts.pory"

# 408 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GameCornerSign:
# 409 "data/maps/GoldenrodCity/scripts.pory"
	.string "Your Playground!\p"
# 410 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Game Corner$"
# 411 "data/maps/GoldenrodCity/scripts.pory"

# 412 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_NameRaterSign:
# 413 "data/maps/GoldenrodCity/scripts.pory"
	.string "Name Rater\p"
# 414 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get Your Pokémon Nicknames Rated$"
# 415 "data/maps/GoldenrodCity/scripts.pory"

# 416 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundNorthSign:
# 417 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 418 "data/maps/GoldenrodCity/scripts.pory"

# 419 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundSouthSign:
# 420 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 421 "data/maps/GoldenrodCity/scripts.pory"

# 422 "data/maps/GoldenrodCity/scripts.pory"

# 423 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_FlowerShopSign:
# 424 "data/maps/GoldenrodCity/scripts.pory"
	.string "Blooming Beautiful Flower Shop$"
# 425 "data/maps/GoldenrodCity/scripts.pory"

# 426 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorAsk:
# 427 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can teach your Pokémon some\n"
# 428 "data/maps/GoldenrodCity/scripts.pory"
	.string "amazing moves!\p"
# 429 "data/maps/GoldenrodCity/scripts.pory"
	.string "Should I teach one?$"
# 430 "data/maps/GoldenrodCity/scripts.pory"

# 431 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorCost:
# 432 "data/maps/GoldenrodCity/scripts.pory"
	.string "It'll cost you 1000 coins.\n"
# 433 "data/maps/GoldenrodCity/scripts.pory"
	.string "Okay?$"
# 434 "data/maps/GoldenrodCity/scripts.pory"

# 435 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorDecline:
# 436 "data/maps/GoldenrodCity/scripts.pory"
	.string "Aww… But these moves are great!$"
# 437 "data/maps/GoldenrodCity/scripts.pory"

# 438 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorWhich:
# 439 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! You won't regret it!\p"
# 440 "data/maps/GoldenrodCity/scripts.pory"
	.string "Which move should I teach?$"
# 441 "data/maps/GoldenrodCity/scripts.pory"

# 442 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNoCash:
# 443 "data/maps/GoldenrodCity/scripts.pory"
	.string "Too bad. Guess I'll need to\n"
# 444 "data/maps/GoldenrodCity/scripts.pory"
	.string "get some cash from home…$"
# 445 "data/maps/GoldenrodCity/scripts.pory"

# 446 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorUnderstand:
# 447 "data/maps/GoldenrodCity/scripts.pory"
	.string "If you understand this move,\n"
# 448 "data/maps/GoldenrodCity/scripts.pory"
	.string "you've made it as a trainer.$"
# 449 "data/maps/GoldenrodCity/scripts.pory"

# 450 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorFarewell:
# 451 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! Farewell, kid!$"
# 452 "data/maps/GoldenrodCity/scripts.pory"

# 453 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorBut:
# 454 "data/maps/GoldenrodCity/scripts.pory"
	.string "B-but…$"
# 455 "data/maps/GoldenrodCity/scripts.pory"

# 456 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNotEnoughCoins:
# 457 "data/maps/GoldenrodCity/scripts.pory"
	.string "…You don't have enough coins…$"
# 458 "data/maps/GoldenrodCity/scripts.pory"

# 459 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_OnFrame:: 
# 460 "data/maps/GoldenrodCity/scripts.pory"
	map_script_2 VAR_RIVAL_STATE, 6, GoldenrodCity_RivalAfterWhitney
# 461 "data/maps/GoldenrodCity/scripts.pory"
	.2byte 0

Goldenrod_Daytime_ExpertM::
# 465 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 466 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertM_Text_0
# 468 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 469 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 470 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_STARAVIA, Goldenrod_Daytime_ExpertM_Movement_0
# 471 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 472 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_ExpertF::
# 476 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 477 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertF_Text_0
# 479 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 480 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 481 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ELECTABUZZ, Goldenrod_Daytime_ExpertF_Movement_0
# 482 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 483 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Staravia::
# 487 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 488 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 489 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Staravia_Text_0
# 490 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 491 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Electabuzz::
# 495 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 496 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 497 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Electabuzz_Text_0
# 498 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 499 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Bystander::
# 503 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 504 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 505 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Bystander_Text_0
# 508 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Burglar::
# 513 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 514 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 515 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Burglar_Text_0
# 525 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Oldlady::
# 529 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 530 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 531 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_GOLDENROD_SMACKDOWN, Goldenrod_Nighttime_Oldlady_2
# 538 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_1
# 545 "data/maps/GoldenrodCity/scripts.pory"
	giveitem ITEM_TM_SMACK_DOWN
# 546 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_GOLDENROD_SMACKDOWN
# 547 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 550 "data/maps/GoldenrodCity/scripts.pory"
	release
	end

Goldenrod_Nighttime_Oldlady_2:
# 532 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 535 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


GoldenrodCity_OnTransition::
# 556 "data/maps/GoldenrodCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 557 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RIVAL
# 558 "data/maps/GoldenrodCity/scripts.pory"
	compare VAR_RIVAL_STATE, 6
	goto_if_eq GoldenrodCity_OnTransition_3
GoldenrodCity_OnTransition_1:
	end

GoldenrodCity_OnTransition_2:
# 559 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RIVAL
	goto GoldenrodCity_OnTransition_1

GoldenrodCity_OnTransition_3:
# 558 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_OnTransition_2
	goto GoldenrodCity_OnTransition_1


GoldenrodCity_RivalAfterWhitney::
# 565 "data/maps/GoldenrodCity/scripts.pory"
	compare VAR_RIVAL_STATE, 6
	goto_if_eq GoldenrodCity_RivalAfterWhitney_3
GoldenrodCity_RivalAfterWhitney_1:
	end

GoldenrodCity_RivalAfterWhitney_2:
# 566 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 567 "data/maps/GoldenrodCity/scripts.pory"
	playse SE_PIN
# 568 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_RIVAL, Common_Movement_ExclamationMark
# 569 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 570 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 571 "data/maps/GoldenrodCity/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 572 "data/maps/GoldenrodCity/scripts.pory"
	createfieldmugshotrival
# 573 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_0
# 578 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_1
# 584 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_2
# 592 "data/maps/GoldenrodCity/scripts.pory"
	removefieldmugshot
# 593 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 594 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_RIVAL, GoldenrodCity_RivalAfterWhitney_Movement_0
# 595 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 7
# 597 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RIVAL
# 598 "data/maps/GoldenrodCity/scripts.pory"
	removeobject LOCALID_GOLDENROD_RIVAL
# 599 "data/maps/GoldenrodCity/scripts.pory"
	savebgm MUS_DUMMY
# 600 "data/maps/GoldenrodCity/scripts.pory"
	fadedefaultbgm
# 601 "data/maps/GoldenrodCity/scripts.pory"
	release
	goto GoldenrodCity_RivalAfterWhitney_1

GoldenrodCity_RivalAfterWhitney_3:
# 565 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_RivalAfterWhitney_2
	goto GoldenrodCity_RivalAfterWhitney_1


# 470 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertM_Movement_0:
# 470 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
# 470 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
	step_end

# 481 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertF_Movement_0:
# 481 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
# 481 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
	step_end

# 594 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_RivalAfterWhitney_Movement_0:
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 594 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
	step_end

Goldenrod_Daytime_ExpertM_Text_0:
# 466 "data/maps/GoldenrodCity/scripts.pory"
	.string "This time I will defeat you, Tiffany!\n"
	.string "We've been training for the whole week!$"

Goldenrod_Daytime_ExpertF_Text_0:
# 477 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hah! If you still have not learned the\n"
	.string "type-matchups, you will never beat me!$"

Goldenrod_Daytime_Staravia_Text_0:
# 489 "data/maps/GoldenrodCity/scripts.pory"
	.string "Staa!$"

Goldenrod_Daytime_Electabuzz_Text_0:
# 497 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bzz!$"

Goldenrod_Daytime_Bystander_Text_0:
# 505 "data/maps/GoldenrodCity/scripts.pory"
	.string "Those two have been going on with their\n"
	.string "rivalry for weeks. The city should build\l"
	.string "a battle arena just for them.$"

Goldenrod_Nighttime_Burglar_Text_0:
# 515 "data/maps/GoldenrodCity/scripts.pory"
	.string "The city's rapid development has\n"
	.string "raised some questions regarding\l"
	.string "where all the money is coming from.\p"
	.string "If they knew just how much money\n"
	.string "changes hands in the underground every\l"
	.string "day, their eyeballs would pop out.\p"
	.string "Perhaps one day you too will learn, if\n"
	.string "you grow strong enough.$"

Goldenrod_Nighttime_Oldlady_Text_0:
# 532 "data/maps/GoldenrodCity/scripts.pory"
	.string "Smack Down lets you ground any target.\n"
	.string "It's also very useful against Flying\l"
	.string "Pokémon.$"

Goldenrod_Nighttime_Oldlady_Text_1:
# 538 "data/maps/GoldenrodCity/scripts.pory"
	.string "Some petty thief tried to jump me on a\n"
	.string "dark alleyway, he was not expecting me\l"
	.string "to Smack Down him with a good old\l"
	.string "Ippon seoinage.\p"
	.string "Here, you should try\n"
	.string "it too.$"

GoldenrodCity_RivalAfterWhitney_Text_0:
# 573 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey {PLAYER}! \n"
	.string "How did the battle with Whitney go? \p"
	.string "Her Miltank made short work of \n"
	.string "my team a while ago!$"

GoldenrodCity_RivalAfterWhitney_Text_1:
# 578 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, you have got the badge... \p"
	.string "Congratulations. \p"
	.string "Another easy victory eh?\n"
	.string "Just like always.$"

GoldenrodCity_RivalAfterWhitney_Text_2:
# 584 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, want to head to\n"
	.string "Ecruteak together?\p"
	.string "Actually never mind, you'll probably\n"
	.string "want to catch more Pokémon, I'll\l"
	.string "go visit my grandparents instead.\p"
	.string "Well, see ya!$"
