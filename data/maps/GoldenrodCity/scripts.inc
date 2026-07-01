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
	clearflag FLAG_HIDE_RADIOF5DUDE
# 29 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_RETURN
# 30 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_FRUSTRATION
# 31 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_BIKE
# 32 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
# 33 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_BILL_GIFTMON
# 34 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_SYS_PC_BILL
# 35 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RETURNED_MACHINE_PART
# 36 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 37 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_1
# 38 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_2
# 39 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_3
# 40 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_COMPLETED_SWITCHES
# 41 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_ENABLE_RADIO
# 42 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_KANTO_RADIO_GOT
# 43 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
# 44 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_SKILL_SWAP
# 45 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_RADIOTOWER_GATE
# 46 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 47 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
# 48 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_QUICK_CLAW
# 49 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MAGNET
# 50 "data/maps/GoldenrodCity/scripts.pory"

# 51 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_BUG_CONTEST_STATE, 0
# 52 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_KENYA, 0
# 53 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 0
# 54 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TRAIN, 0
# 55 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_ELEVATOR, 0
# 56 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 1
# 57 "data/maps/GoldenrodCity/scripts.pory"
	release
# 58 "data/maps/GoldenrodCity/scripts.pory"
	end
# 59 "data/maps/GoldenrodCity/scripts.pory"

# 60 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Elm_Togepi_Call::
# 61 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 62 "data/maps/GoldenrodCity/scripts.pory"
	pokenavcall GoldenrodCity_Text_ElmCall
# 63 "data/maps/GoldenrodCity/scripts.pory"
	waitmessage
# 64 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 65 "data/maps/GoldenrodCity/scripts.pory"
	release
# 66 "data/maps/GoldenrodCity/scripts.pory"
	return
# 67 "data/maps/GoldenrodCity/scripts.pory"

# 68 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_PokefanM::
# 69 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 70 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 71 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
# 72 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 73 "data/maps/GoldenrodCity/scripts.pory"
	release
# 74 "data/maps/GoldenrodCity/scripts.pory"
	end
# 75 "data/maps/GoldenrodCity/scripts.pory"

# 76 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster::
# 77 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
# 78 "data/maps/GoldenrodCity/scripts.pory"
	end
# 79 "data/maps/GoldenrodCity/scripts.pory"

# 80 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster2::
# 81 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
# 82 "data/maps/GoldenrodCity/scripts.pory"
	end
# 83 "data/maps/GoldenrodCity/scripts.pory"

# 84 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerF::
# 85 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 86 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 87 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
# 88 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
# 89 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 90 "data/maps/GoldenrodCity/scripts.pory"
	release
# 91 "data/maps/GoldenrodCity/scripts.pory"
	end
# 92 "data/maps/GoldenrodCity/scripts.pory"

# 93 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerFCleared::
# 94 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
# 95 "data/maps/GoldenrodCity/scripts.pory"
	end
# 96 "data/maps/GoldenrodCity/scripts.pory"

# 97 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Lass::
# 98 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 99 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 100 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
# 101 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 102 "data/maps/GoldenrodCity/scripts.pory"
	release
# 103 "data/maps/GoldenrodCity/scripts.pory"
	end
# 104 "data/maps/GoldenrodCity/scripts.pory"

# 105 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Gramps::
# 106 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 107 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 108 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
# 109 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 110 "data/maps/GoldenrodCity/scripts.pory"
	release
# 111 "data/maps/GoldenrodCity/scripts.pory"
	end
# 112 "data/maps/GoldenrodCity/scripts.pory"

# 113 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_NameRaterSign::
# 114 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
# 115 "data/maps/GoldenrodCity/scripts.pory"
	end
# 116 "data/maps/GoldenrodCity/scripts.pory"

# 117 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_RocketScout::
# 118 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 119 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
# 120 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 121 "data/maps/GoldenrodCity/scripts.pory"
	PLAYSE SE_PIN
# 122 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
# 123 "data/maps/GoldenrodCity/scripts.pory"
	delay 20
# 124 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 125 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
# 126 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 127 "data/maps/GoldenrodCity/scripts.pory"
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
# 128 "data/maps/GoldenrodCity/scripts.pory"
	release
# 129 "data/maps/GoldenrodCity/scripts.pory"
	end
# 130 "data/maps/GoldenrodCity/scripts.pory"

# 131 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket1::
# 132 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 133 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 134 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
# 135 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 136 "data/maps/GoldenrodCity/scripts.pory"
	release
# 137 "data/maps/GoldenrodCity/scripts.pory"
	end
# 138 "data/maps/GoldenrodCity/scripts.pory"

# 139 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket2::
# 140 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 141 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 142 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
# 143 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 144 "data/maps/GoldenrodCity/scripts.pory"
	release
# 145 "data/maps/GoldenrodCity/scripts.pory"
	end
# 146 "data/maps/GoldenrodCity/scripts.pory"

# 147 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket3::
# 148 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 149 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 150 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
# 151 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 152 "data/maps/GoldenrodCity/scripts.pory"
	release
# 153 "data/maps/GoldenrodCity/scripts.pory"
	end
# 154 "data/maps/GoldenrodCity/scripts.pory"

# 155 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket4::
# 156 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 157 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 158 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
# 159 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 160 "data/maps/GoldenrodCity/scripts.pory"
	release
# 161 "data/maps/GoldenrodCity/scripts.pory"
	end
# 162 "data/maps/GoldenrodCity/scripts.pory"

# 163 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket5::
# 164 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 165 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 166 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
# 167 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 168 "data/maps/GoldenrodCity/scripts.pory"
	release
# 169 "data/maps/GoldenrodCity/scripts.pory"
	end
# 170 "data/maps/GoldenrodCity/scripts.pory"

# 171 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket6::
# 172 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 173 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 174 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
# 175 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 176 "data/maps/GoldenrodCity/scripts.pory"
	release
# 177 "data/maps/GoldenrodCity/scripts.pory"
	end
# 178 "data/maps/GoldenrodCity/scripts.pory"

# 179 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Woman::
# 180 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 181 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 182 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
# 183 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 184 "data/maps/GoldenrodCity/scripts.pory"
	release
# 185 "data/maps/GoldenrodCity/scripts.pory"
	end
# 186 "data/maps/GoldenrodCity/scripts.pory"

# 187 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker::
# 188 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 189 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 190 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
# 191 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
# 192 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 193 "data/maps/GoldenrodCity/scripts.pory"
	release
# 194 "data/maps/GoldenrodCity/scripts.pory"
	end
# 195 "data/maps/GoldenrodCity/scripts.pory"

# 196 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker2::
# 197 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
# 198 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 199 "data/maps/GoldenrodCity/scripts.pory"
	release
# 200 "data/maps/GoldenrodCity/scripts.pory"
	end
# 201 "data/maps/GoldenrodCity/scripts.pory"

# 202 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Snubbull::
# 203 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 204 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 205 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 206 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 207 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
# 208 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 209 "data/maps/GoldenrodCity/scripts.pory"
	release
# 210 "data/maps/GoldenrodCity/scripts.pory"
	end
# 211 "data/maps/GoldenrodCity/scripts.pory"

# 212 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Mime::
# 213 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 214 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 215 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 216 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
# 217 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
# 218 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 219 "data/maps/GoldenrodCity/scripts.pory"
	release
# 220 "data/maps/GoldenrodCity/scripts.pory"
	end
# 221 "data/maps/GoldenrodCity/scripts.pory"

# 222 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignUnderground::
# 223 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 224 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
# 225 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 226 "data/maps/GoldenrodCity/scripts.pory"
	release
# 227 "data/maps/GoldenrodCity/scripts.pory"
	end
# 228 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignDept::
# 229 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 230 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
# 231 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 232 "data/maps/GoldenrodCity/scripts.pory"
	release
# 233 "data/maps/GoldenrodCity/scripts.pory"
	end
# 234 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignBike::
# 235 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 236 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
# 237 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 238 "data/maps/GoldenrodCity/scripts.pory"
	release
# 239 "data/maps/GoldenrodCity/scripts.pory"
	end
# 240 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignTrain::
# 241 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 242 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
# 243 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 244 "data/maps/GoldenrodCity/scripts.pory"
	release
# 245 "data/maps/GoldenrodCity/scripts.pory"
	end
# 246 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGym::
# 247 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 248 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
# 249 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 250 "data/maps/GoldenrodCity/scripts.pory"
	release
# 251 "data/maps/GoldenrodCity/scripts.pory"
	end
# 252 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignFlower::
# 253 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 254 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
# 255 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 256 "data/maps/GoldenrodCity/scripts.pory"
	release
# 257 "data/maps/GoldenrodCity/scripts.pory"
	end
# 258 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignRadio::
# 259 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 260 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
# 261 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 262 "data/maps/GoldenrodCity/scripts.pory"
	release
# 263 "data/maps/GoldenrodCity/scripts.pory"
	end
# 264 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGameCorner::
# 265 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 266 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
# 267 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 268 "data/maps/GoldenrodCity/scripts.pory"
	release
# 269 "data/maps/GoldenrodCity/scripts.pory"
	end
# 270 "data/maps/GoldenrodCity/scripts.pory"

# 271 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Beauty::
# 272 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 273 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 274 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
# 275 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 276 "data/maps/GoldenrodCity/scripts.pory"
	release
# 277 "data/maps/GoldenrodCity/scripts.pory"
	end
# 278 "data/maps/GoldenrodCity/scripts.pory"

# 279 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Beauty:
# 280 "data/maps/GoldenrodCity/scripts.pory"
	.string "This is the Goldenrod Gym!\p"
# 281 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our leader Whitney is not here\n"
# 282 "data/maps/GoldenrodCity/scripts.pory"
	.string "right now. She might be at the\l"
# 283 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio Tower.$"
# 284 "data/maps/GoldenrodCity/scripts.pory"

# 285 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Woman:
# 286 "data/maps/GoldenrodCity/scripts.pory"
	.string "I used to train in Whitney's Gym,\n"
# 287 "data/maps/GoldenrodCity/scripts.pory"
	.string "but all her crying gave me a\l"
# 288 "data/maps/GoldenrodCity/scripts.pory"
	.string "headache.$"
# 289 "data/maps/GoldenrodCity/scripts.pory"

# 290 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerDay:
# 291 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 292 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was night time... How long was I\l"
# 293 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 294 "data/maps/GoldenrodCity/scripts.pory"

# 295 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerNight:
# 296 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 297 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was day time... How long was I\l"
# 298 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 299 "data/maps/GoldenrodCity/scripts.pory"

# 300 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Snubbull:
# 301 "data/maps/GoldenrodCity/scripts.pory"
	.string "Audino: Audiiinii!$"
# 302 "data/maps/GoldenrodCity/scripts.pory"

# 303 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MrMime:
# 304 "data/maps/GoldenrodCity/scripts.pory"
	.string "............................$"
# 305 "data/maps/GoldenrodCity/scripts.pory"

# 306 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_ElmCall:
# 307 "data/maps/GoldenrodCity/scripts.pory"
	.string "Elm: Hello, {PLAYER}?\n"
# 308 "data/maps/GoldenrodCity/scripts.pory"
	.string "Has that egg hatched yet?\p"
# 309 "data/maps/GoldenrodCity/scripts.pory"
	.string "Once it hatches, don't forget to\n"
# 310 "data/maps/GoldenrodCity/scripts.pory"
	.string "bring it by the lab! I need to\l"
# 311 "data/maps/GoldenrodCity/scripts.pory"
	.string "see it!$"
# 312 "data/maps/GoldenrodCity/scripts.pory"

# 313 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_PokefanM:
# 314 "data/maps/GoldenrodCity/scripts.pory"
	.string "They built the new Radio Tower\n"
# 315 "data/maps/GoldenrodCity/scripts.pory"
	.string "to replace the old creaky one.$"
# 316 "data/maps/GoldenrodCity/scripts.pory"

# 317 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster1:
# 318 "data/maps/GoldenrodCity/scripts.pory"
	.string "I know there's a new Bike Shop,\n"
# 319 "data/maps/GoldenrodCity/scripts.pory"
	.string "but I can't find it anywhere.$"
# 320 "data/maps/GoldenrodCity/scripts.pory"

# 321 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1:
# 322 "data/maps/GoldenrodCity/scripts.pory"
	.string "Is that man in black dressed up\n"
# 323 "data/maps/GoldenrodCity/scripts.pory"
	.string "like a Team Rocket member?\p"
# 324 "data/maps/GoldenrodCity/scripts.pory"
	.string "How silly!$"
# 325 "data/maps/GoldenrodCity/scripts.pory"

# 326 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1_Cleared:
# 327 "data/maps/GoldenrodCity/scripts.pory"
	.string "Was that man in black really part\n"
# 328 "data/maps/GoldenrodCity/scripts.pory"
	.string "of Team Rocket? I can't believe it!$"
# 329 "data/maps/GoldenrodCity/scripts.pory"

# 330 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2:
# 331 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Radio Tower in Goldenrod City\n"
# 332 "data/maps/GoldenrodCity/scripts.pory"
	.string "is quite the landmark.\p"
# 333 "data/maps/GoldenrodCity/scripts.pory"
	.string "They're running a campaign now.\p"
# 334 "data/maps/GoldenrodCity/scripts.pory"
	.string "They'll give you a shiny new\n"
# 335 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio if you can pass their quiz.$"
# 336 "data/maps/GoldenrodCity/scripts.pory"

# 337 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2_GotCard:
# 338 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, your Pokégear already works\n"
# 339 "data/maps/GoldenrodCity/scripts.pory"
	.string "as a radio!$"
# 340 "data/maps/GoldenrodCity/scripts.pory"

# 341 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster2:
# 342 "data/maps/GoldenrodCity/scripts.pory"
	.string "E-he-he-he…\p"
# 343 "data/maps/GoldenrodCity/scripts.pory"
	.string "I got in trouble for playing in\n"
# 344 "data/maps/GoldenrodCity/scripts.pory"
	.string "the Dept.Store basement.$"
# 345 "data/maps/GoldenrodCity/scripts.pory"

# 346 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Lass:
# 347 "data/maps/GoldenrodCity/scripts.pory"
	.string "That man inside rates your\n"
# 348 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon nicknames.\p"
# 349 "data/maps/GoldenrodCity/scripts.pory"
	.string "He can even rename them.$"
# 350 "data/maps/GoldenrodCity/scripts.pory"

# 351 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Gramps:
# 352 "data/maps/GoldenrodCity/scripts.pory"
	.string "Whew! This city is so big,\n"
# 353 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can't find anything at all.$"
# 354 "data/maps/GoldenrodCity/scripts.pory"

# 355 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout1:
# 356 "data/maps/GoldenrodCity/scripts.pory"
	.string "So this is the Radio Tower…$"
# 357 "data/maps/GoldenrodCity/scripts.pory"

# 358 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout2:
# 359 "data/maps/GoldenrodCity/scripts.pory"
	.string "What do you want, pest?\n"
# 360 "data/maps/GoldenrodCity/scripts.pory"
	.string "Scram already!$"
# 361 "data/maps/GoldenrodCity/scripts.pory"

# 362 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket1:
# 363 "data/maps/GoldenrodCity/scripts.pory"
	.string "Stay out of the way!\n"
# 364 "data/maps/GoldenrodCity/scripts.pory"
	.string "Beat it, kid!$"
# 365 "data/maps/GoldenrodCity/scripts.pory"

# 366 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket2:
# 367 "data/maps/GoldenrodCity/scripts.pory"
	.string "Take over the Radio Tower…\p"
# 368 "data/maps/GoldenrodCity/scripts.pory"
	.string "What? It's none of your business!$"
# 369 "data/maps/GoldenrodCity/scripts.pory"

# 370 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket3:
# 371 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon? They're just tools\n"
# 372 "data/maps/GoldenrodCity/scripts.pory"
	.string "we use to make money!$"
# 373 "data/maps/GoldenrodCity/scripts.pory"

# 374 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket4:
# 375 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our dream will soon come true…\p"
# 376 "data/maps/GoldenrodCity/scripts.pory"
	.string "It was a long, hard struggle…$"
# 377 "data/maps/GoldenrodCity/scripts.pory"

# 378 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket5:
# 379 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, brat! You don't belong here!\n"
# 380 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get lost already!$"
# 381 "data/maps/GoldenrodCity/scripts.pory"

# 382 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket6:
# 383 "data/maps/GoldenrodCity/scripts.pory"
	.string "Come and taste the terror of\n"
# 384 "data/maps/GoldenrodCity/scripts.pory"
	.string "Team Rocket!$"
# 385 "data/maps/GoldenrodCity/scripts.pory"

# 386 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_StationSign:
# 387 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Station$"
# 388 "data/maps/GoldenrodCity/scripts.pory"

# 389 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RadioTowerSign:
# 390 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Radio Tower$"
# 391 "data/maps/GoldenrodCity/scripts.pory"

# 392 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_DeptStoreSign:
# 393 "data/maps/GoldenrodCity/scripts.pory"
	.string "Full Selection of Pokémon Goods!\p"
# 394 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Dept.Store$"
# 395 "data/maps/GoldenrodCity/scripts.pory"

# 396 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GymSign:
# 397 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Pokémon Gym\n"
# 398 "data/maps/GoldenrodCity/scripts.pory"
	.string "Leader: Whitney\p"
# 399 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Incredibly Pretty Girl!$"
# 400 "data/maps/GoldenrodCity/scripts.pory"

# 401 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CitySign:
# 402 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City\p"
# 403 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Festive City of Opulent Charm$"
# 404 "data/maps/GoldenrodCity/scripts.pory"

# 405 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_BikeShopSign:
# 406 "data/maps/GoldenrodCity/scripts.pory"
	.string "The World is a Cycle Path!\n"
# 407 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bike Shop$"
# 408 "data/maps/GoldenrodCity/scripts.pory"

# 409 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GameCornerSign:
# 410 "data/maps/GoldenrodCity/scripts.pory"
	.string "Your Playground!\p"
# 411 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Game Corner$"
# 412 "data/maps/GoldenrodCity/scripts.pory"

# 413 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_NameRaterSign:
# 414 "data/maps/GoldenrodCity/scripts.pory"
	.string "Name Rater\p"
# 415 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get Your Pokémon Nicknames Rated$"
# 416 "data/maps/GoldenrodCity/scripts.pory"

# 417 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundNorthSign:
# 418 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 419 "data/maps/GoldenrodCity/scripts.pory"

# 420 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundSouthSign:
# 421 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 422 "data/maps/GoldenrodCity/scripts.pory"

# 423 "data/maps/GoldenrodCity/scripts.pory"

# 424 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_FlowerShopSign:
# 425 "data/maps/GoldenrodCity/scripts.pory"
	.string "Blooming Beautiful Flower Shop$"
# 426 "data/maps/GoldenrodCity/scripts.pory"

# 427 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorAsk:
# 428 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can teach your Pokémon some\n"
# 429 "data/maps/GoldenrodCity/scripts.pory"
	.string "amazing moves!\p"
# 430 "data/maps/GoldenrodCity/scripts.pory"
	.string "Should I teach one?$"
# 431 "data/maps/GoldenrodCity/scripts.pory"

# 432 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorCost:
# 433 "data/maps/GoldenrodCity/scripts.pory"
	.string "It'll cost you 1000 coins.\n"
# 434 "data/maps/GoldenrodCity/scripts.pory"
	.string "Okay?$"
# 435 "data/maps/GoldenrodCity/scripts.pory"

# 436 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorDecline:
# 437 "data/maps/GoldenrodCity/scripts.pory"
	.string "Aww… But these moves are great!$"
# 438 "data/maps/GoldenrodCity/scripts.pory"

# 439 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorWhich:
# 440 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! You won't regret it!\p"
# 441 "data/maps/GoldenrodCity/scripts.pory"
	.string "Which move should I teach?$"
# 442 "data/maps/GoldenrodCity/scripts.pory"

# 443 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNoCash:
# 444 "data/maps/GoldenrodCity/scripts.pory"
	.string "Too bad. Guess I'll need to\n"
# 445 "data/maps/GoldenrodCity/scripts.pory"
	.string "get some cash from home…$"
# 446 "data/maps/GoldenrodCity/scripts.pory"

# 447 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorUnderstand:
# 448 "data/maps/GoldenrodCity/scripts.pory"
	.string "If you understand this move,\n"
# 449 "data/maps/GoldenrodCity/scripts.pory"
	.string "you've made it as a trainer.$"
# 450 "data/maps/GoldenrodCity/scripts.pory"

# 451 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorFarewell:
# 452 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! Farewell, kid!$"
# 453 "data/maps/GoldenrodCity/scripts.pory"

# 454 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorBut:
# 455 "data/maps/GoldenrodCity/scripts.pory"
	.string "B-but…$"
# 456 "data/maps/GoldenrodCity/scripts.pory"

# 457 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNotEnoughCoins:
# 458 "data/maps/GoldenrodCity/scripts.pory"
	.string "…You don't have enough coins…$"
# 459 "data/maps/GoldenrodCity/scripts.pory"

# 460 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_OnFrame:: 
# 461 "data/maps/GoldenrodCity/scripts.pory"
	map_script_2 VAR_RIVAL_STATE, 6, GoldenrodCity_RivalAfterWhitney
# 462 "data/maps/GoldenrodCity/scripts.pory"
	.2byte 0

Goldenrod_Daytime_ExpertM::
# 466 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 467 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertM_Text_0
# 469 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 470 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 471 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_STARAVIA, Goldenrod_Daytime_ExpertM_Movement_0
# 472 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 473 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_ExpertF::
# 477 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 478 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertF_Text_0
# 480 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 481 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 482 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ELECTABUZZ, Goldenrod_Daytime_ExpertF_Movement_0
# 483 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 484 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Staravia::
# 488 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 489 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 490 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Staravia_Text_0
# 491 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 492 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Electabuzz::
# 496 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 497 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 498 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Electabuzz_Text_0
# 499 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 500 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Bystander::
# 504 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 505 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 506 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Bystander_Text_0
# 509 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Burglar::
# 514 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 515 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 516 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Burglar_Text_0
# 526 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Oldlady::
# 530 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 531 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 532 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_GOLDENROD_SMACKDOWN, Goldenrod_Nighttime_Oldlady_2
# 539 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_1
# 546 "data/maps/GoldenrodCity/scripts.pory"
	giveitem ITEM_TM_SMACK_DOWN
# 547 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_GOLDENROD_SMACKDOWN
# 548 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 551 "data/maps/GoldenrodCity/scripts.pory"
	release
	end

Goldenrod_Nighttime_Oldlady_2:
# 533 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 536 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


GoldenrodCity_OnTransition::
# 557 "data/maps/GoldenrodCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 558 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RIVAL
# 559 "data/maps/GoldenrodCity/scripts.pory"
	compare VAR_RIVAL_STATE, 6
	goto_if_eq GoldenrodCity_OnTransition_3
GoldenrodCity_OnTransition_1:
	end

GoldenrodCity_OnTransition_2:
# 560 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RIVAL
	goto GoldenrodCity_OnTransition_1

GoldenrodCity_OnTransition_3:
# 559 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_OnTransition_2
	goto GoldenrodCity_OnTransition_1


GoldenrodCity_RivalAfterWhitney::
# 566 "data/maps/GoldenrodCity/scripts.pory"
	compare VAR_RIVAL_STATE, 6
	goto_if_eq GoldenrodCity_RivalAfterWhitney_3
GoldenrodCity_RivalAfterWhitney_1:
	end

GoldenrodCity_RivalAfterWhitney_2:
# 567 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 568 "data/maps/GoldenrodCity/scripts.pory"
	playse SE_PIN
# 569 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_RIVAL, Common_Movement_ExclamationMark
# 570 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 571 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 572 "data/maps/GoldenrodCity/scripts.pory"
	playbgm MUS_HG_LYRA, TRUE
# 573 "data/maps/GoldenrodCity/scripts.pory"
	createfieldmugshotrival
# 574 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_0
# 579 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_1
# 585 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_RivalAfterWhitney_Text_2
# 593 "data/maps/GoldenrodCity/scripts.pory"
	removefieldmugshot
# 594 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 595 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_RIVAL, GoldenrodCity_RivalAfterWhitney_Movement_0
# 596 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 597 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 7
# 598 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RIVAL
# 599 "data/maps/GoldenrodCity/scripts.pory"
	removeobject LOCALID_GOLDENROD_RIVAL
# 600 "data/maps/GoldenrodCity/scripts.pory"
	savebgm MUS_DUMMY
# 601 "data/maps/GoldenrodCity/scripts.pory"
	fadedefaultbgm
# 602 "data/maps/GoldenrodCity/scripts.pory"
	release
	goto GoldenrodCity_RivalAfterWhitney_1

GoldenrodCity_RivalAfterWhitney_3:
# 566 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_RivalAfterWhitney_2
	goto GoldenrodCity_RivalAfterWhitney_1


# 471 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertM_Movement_0:
# 471 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
# 471 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
	step_end

# 482 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertF_Movement_0:
# 482 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
# 482 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
	step_end

# 595 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_RivalAfterWhitney_Movement_0:
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_left
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
# 595 "data/maps/GoldenrodCity/scripts.pory"
	walk_down
	step_end

Goldenrod_Daytime_ExpertM_Text_0:
# 467 "data/maps/GoldenrodCity/scripts.pory"
	.string "This time I will defeat you, Tiffany!\n"
	.string "We've been training for the whole week!$"

Goldenrod_Daytime_ExpertF_Text_0:
# 478 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hah! If you still have not learned the\n"
	.string "type-matchups, you will never beat me!$"

Goldenrod_Daytime_Staravia_Text_0:
# 490 "data/maps/GoldenrodCity/scripts.pory"
	.string "Staa!$"

Goldenrod_Daytime_Electabuzz_Text_0:
# 498 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bzz!$"

Goldenrod_Daytime_Bystander_Text_0:
# 506 "data/maps/GoldenrodCity/scripts.pory"
	.string "Those two have been going on with their\n"
	.string "rivalry for weeks. The city should build\l"
	.string "a battle arena just for them.$"

Goldenrod_Nighttime_Burglar_Text_0:
# 516 "data/maps/GoldenrodCity/scripts.pory"
	.string "The city's rapid development has\n"
	.string "raised some questions regarding\l"
	.string "where all the money is coming from.\p"
	.string "If they knew just how much money\n"
	.string "changes hands in the underground every\l"
	.string "day, their eyeballs would pop out.\p"
	.string "Perhaps one day you too will learn, if\n"
	.string "you grow strong enough.$"

Goldenrod_Nighttime_Oldlady_Text_0:
# 533 "data/maps/GoldenrodCity/scripts.pory"
	.string "Smack Down lets you ground any target.\n"
	.string "It's also very useful against Flying\l"
	.string "Pokémon.$"

Goldenrod_Nighttime_Oldlady_Text_1:
# 539 "data/maps/GoldenrodCity/scripts.pory"
	.string "Some petty thief tried to jump me on a\n"
	.string "dark alleyway, he was not expecting me\l"
	.string "to Smack Down him with a good old\l"
	.string "Ippon seoinage.\p"
	.string "Here, you should try\n"
	.string "it too.$"

GoldenrodCity_RivalAfterWhitney_Text_0:
# 574 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey {PLAYER}! \n"
	.string "How did the battle with Whitney go? \p"
	.string "Her Miltank made short work of \n"
	.string "my team a while ago!$"

GoldenrodCity_RivalAfterWhitney_Text_1:
# 579 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, you have got the badge... \p"
	.string "Congratulations. \p"
	.string "Another easy victory eh?\n"
	.string "Just like always.$"

GoldenrodCity_RivalAfterWhitney_Text_2:
# 585 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, want to head to\n"
	.string "Ecruteak together?\p"
	.string "Actually never mind, you'll probably\n"
	.string "want to catch more Pokémon, I'll\l"
	.string "go visit my grandparents instead.\p"
	.string "Well, see ya!$"
