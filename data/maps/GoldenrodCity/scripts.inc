# 1 "data/maps/GoldenrodCity/scripts.pory"

# 2 "data/maps/GoldenrodCity/scripts.pory"

# 3 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_MapScripts::
# 4 "data/maps/GoldenrodCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_OnLoad
# 5 "data/maps/GoldenrodCity/scripts.pory"
	.byte 0
# 6 "data/maps/GoldenrodCity/scripts.pory"

# 7 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_OnLoad::
# 8 "data/maps/GoldenrodCity/scripts.pory"
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
# 9 "data/maps/GoldenrodCity/scripts.pory"
	end
# 10 "data/maps/GoldenrodCity/scripts.pory"

# 11 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Trigger:: @flagheap
# 12 "data/maps/GoldenrodCity/scripts.pory"
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
# 13 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_VISITED_GOLDENROD_CITY
# 14 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 15 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_BILL
# 16 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 17 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
# 18 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
# 19 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 20 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 21 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_RADIOTOWER_OAK
# 22 "data/maps/GoldenrodCity/scripts.pory"
	
# 23 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
# 24 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
# 25 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 26 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_RETURN
# 27 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_FRUSTRATION
# 28 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_BIKE
# 29 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
# 30 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_BILL_GIFTMON
# 31 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_SYS_PC_BILL
# 32 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RETURNED_MACHINE_PART
# 33 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 34 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_1
# 35 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_2
# 36 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_3
# 37 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_COMPLETED_SWITCHES
# 38 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_ENABLE_RADIO
# 39 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_KANTO_RADIO_GOT
# 40 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
# 41 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_SKILL_SWAP
# 42 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_RADIOTOWER_GATE
# 43 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 44 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
# 45 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_QUICK_CLAW
# 46 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MAGNET
# 47 "data/maps/GoldenrodCity/scripts.pory"

# 48 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_BUG_CONTEST_STATE, 0
# 49 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_KENYA, 0
# 50 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 0
# 51 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TRAIN, 0
# 52 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_ELEVATOR, 0
# 53 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 1
# 54 "data/maps/GoldenrodCity/scripts.pory"
	release
# 55 "data/maps/GoldenrodCity/scripts.pory"
	end
# 56 "data/maps/GoldenrodCity/scripts.pory"

# 57 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Trigger_Music::
# 58 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
# 59 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
# 60 "data/maps/GoldenrodCity/scripts.pory"
	playbgm MUS_HG_ROCKET_TAKEOVER, TRUE
# 61 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TEMP_0, 1 
# 62 "data/maps/GoldenrodCity/scripts.pory"
	end
# 63 "data/maps/GoldenrodCity/scripts.pory"

# 64 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Trigger_MusicNotYet::
# 65 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TEMP_0, 1
# 66 "data/maps/GoldenrodCity/scripts.pory"
	end
# 67 "data/maps/GoldenrodCity/scripts.pory"

# 68 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Elm_Togepi_Call::
# 69 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 70 "data/maps/GoldenrodCity/scripts.pory"
	pokenavcall GoldenrodCity_Text_ElmCall
# 71 "data/maps/GoldenrodCity/scripts.pory"
	waitmessage
# 72 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 73 "data/maps/GoldenrodCity/scripts.pory"
	release
# 74 "data/maps/GoldenrodCity/scripts.pory"
	return
# 75 "data/maps/GoldenrodCity/scripts.pory"

# 76 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_PokefanM::
# 77 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 78 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 79 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
# 80 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 81 "data/maps/GoldenrodCity/scripts.pory"
	release
# 82 "data/maps/GoldenrodCity/scripts.pory"
	end
# 83 "data/maps/GoldenrodCity/scripts.pory"

# 84 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster::
# 85 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
# 86 "data/maps/GoldenrodCity/scripts.pory"
	end
# 87 "data/maps/GoldenrodCity/scripts.pory"

# 88 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster2::
# 89 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
# 90 "data/maps/GoldenrodCity/scripts.pory"
	end
# 91 "data/maps/GoldenrodCity/scripts.pory"

# 92 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerF::
# 93 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 94 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 95 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
# 96 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
# 97 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 98 "data/maps/GoldenrodCity/scripts.pory"
	release
# 99 "data/maps/GoldenrodCity/scripts.pory"
	end
# 100 "data/maps/GoldenrodCity/scripts.pory"

# 101 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerFCleared::
# 102 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
# 103 "data/maps/GoldenrodCity/scripts.pory"
	end
# 104 "data/maps/GoldenrodCity/scripts.pory"

# 105 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Lass::
# 106 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 107 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 108 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
# 109 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 110 "data/maps/GoldenrodCity/scripts.pory"
	release
# 111 "data/maps/GoldenrodCity/scripts.pory"
	end
# 112 "data/maps/GoldenrodCity/scripts.pory"

# 113 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Gramps::
# 114 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 115 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 116 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
# 117 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 118 "data/maps/GoldenrodCity/scripts.pory"
	release
# 119 "data/maps/GoldenrodCity/scripts.pory"
	end
# 120 "data/maps/GoldenrodCity/scripts.pory"

# 121 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_NameRaterSign::
# 122 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
# 123 "data/maps/GoldenrodCity/scripts.pory"
	end
# 124 "data/maps/GoldenrodCity/scripts.pory"

# 125 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_RocketScout::
# 126 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 127 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
# 128 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 129 "data/maps/GoldenrodCity/scripts.pory"
	PLAYSE SE_PIN
# 130 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
# 131 "data/maps/GoldenrodCity/scripts.pory"
	delay 20
# 132 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 133 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
# 134 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 135 "data/maps/GoldenrodCity/scripts.pory"
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
# 136 "data/maps/GoldenrodCity/scripts.pory"
	release
# 137 "data/maps/GoldenrodCity/scripts.pory"
	end
# 138 "data/maps/GoldenrodCity/scripts.pory"

# 139 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket1::
# 140 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 141 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 142 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
# 143 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 144 "data/maps/GoldenrodCity/scripts.pory"
	release
# 145 "data/maps/GoldenrodCity/scripts.pory"
	end
# 146 "data/maps/GoldenrodCity/scripts.pory"

# 147 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket2::
# 148 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 149 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 150 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
# 151 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 152 "data/maps/GoldenrodCity/scripts.pory"
	release
# 153 "data/maps/GoldenrodCity/scripts.pory"
	end
# 154 "data/maps/GoldenrodCity/scripts.pory"

# 155 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket3::
# 156 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 157 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 158 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
# 159 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 160 "data/maps/GoldenrodCity/scripts.pory"
	release
# 161 "data/maps/GoldenrodCity/scripts.pory"
	end
# 162 "data/maps/GoldenrodCity/scripts.pory"

# 163 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket4::
# 164 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 165 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 166 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
# 167 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 168 "data/maps/GoldenrodCity/scripts.pory"
	release
# 169 "data/maps/GoldenrodCity/scripts.pory"
	end
# 170 "data/maps/GoldenrodCity/scripts.pory"

# 171 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket5::
# 172 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 173 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 174 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
# 175 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 176 "data/maps/GoldenrodCity/scripts.pory"
	release
# 177 "data/maps/GoldenrodCity/scripts.pory"
	end
# 178 "data/maps/GoldenrodCity/scripts.pory"

# 179 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket6::
# 180 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 181 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 182 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
# 183 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 184 "data/maps/GoldenrodCity/scripts.pory"
	release
# 185 "data/maps/GoldenrodCity/scripts.pory"
	end
# 186 "data/maps/GoldenrodCity/scripts.pory"

# 187 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Woman::
# 188 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 189 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 190 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
# 191 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 192 "data/maps/GoldenrodCity/scripts.pory"
	release
# 193 "data/maps/GoldenrodCity/scripts.pory"
	end
# 194 "data/maps/GoldenrodCity/scripts.pory"

# 195 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker::
# 196 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 197 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 198 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
# 199 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
# 200 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 201 "data/maps/GoldenrodCity/scripts.pory"
	release
# 202 "data/maps/GoldenrodCity/scripts.pory"
	end
# 203 "data/maps/GoldenrodCity/scripts.pory"

# 204 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker2::
# 205 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
# 206 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 207 "data/maps/GoldenrodCity/scripts.pory"
	release
# 208 "data/maps/GoldenrodCity/scripts.pory"
	end
# 209 "data/maps/GoldenrodCity/scripts.pory"

# 210 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Snubbull::
# 211 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 212 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 213 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 214 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 215 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
# 216 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 217 "data/maps/GoldenrodCity/scripts.pory"
	release
# 218 "data/maps/GoldenrodCity/scripts.pory"
	end
# 219 "data/maps/GoldenrodCity/scripts.pory"

# 220 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Mime::
# 221 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 222 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 223 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 224 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
# 225 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
# 226 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 227 "data/maps/GoldenrodCity/scripts.pory"
	release
# 228 "data/maps/GoldenrodCity/scripts.pory"
	end
# 229 "data/maps/GoldenrodCity/scripts.pory"

# 230 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignUnderground::
# 231 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 232 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
# 233 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 234 "data/maps/GoldenrodCity/scripts.pory"
	release
# 235 "data/maps/GoldenrodCity/scripts.pory"
	end
# 236 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignDept::
# 237 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 238 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
# 239 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 240 "data/maps/GoldenrodCity/scripts.pory"
	release
# 241 "data/maps/GoldenrodCity/scripts.pory"
	end
# 242 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignBike::
# 243 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 244 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
# 245 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 246 "data/maps/GoldenrodCity/scripts.pory"
	release
# 247 "data/maps/GoldenrodCity/scripts.pory"
	end
# 248 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignTrain::
# 249 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 250 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
# 251 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 252 "data/maps/GoldenrodCity/scripts.pory"
	release
# 253 "data/maps/GoldenrodCity/scripts.pory"
	end
# 254 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGym::
# 255 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 256 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
# 257 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 258 "data/maps/GoldenrodCity/scripts.pory"
	release
# 259 "data/maps/GoldenrodCity/scripts.pory"
	end
# 260 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignFlower::
# 261 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 262 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
# 263 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 264 "data/maps/GoldenrodCity/scripts.pory"
	release
# 265 "data/maps/GoldenrodCity/scripts.pory"
	end
# 266 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignRadio::
# 267 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 268 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
# 269 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 270 "data/maps/GoldenrodCity/scripts.pory"
	release
# 271 "data/maps/GoldenrodCity/scripts.pory"
	end
# 272 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGameCorner::
# 273 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 274 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
# 275 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 276 "data/maps/GoldenrodCity/scripts.pory"
	release
# 277 "data/maps/GoldenrodCity/scripts.pory"
	end
# 278 "data/maps/GoldenrodCity/scripts.pory"

# 279 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Beauty::
# 280 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 281 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 282 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
# 283 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 284 "data/maps/GoldenrodCity/scripts.pory"
	release
# 285 "data/maps/GoldenrodCity/scripts.pory"
	end
# 286 "data/maps/GoldenrodCity/scripts.pory"

# 287 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Beauty:
# 288 "data/maps/GoldenrodCity/scripts.pory"
	.string "This is the Goldenrod Gym!\p"
# 289 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our leader Whitney is not here\n"
# 290 "data/maps/GoldenrodCity/scripts.pory"
	.string "right now. She might be at the\l"
# 291 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio Tower.$"
# 292 "data/maps/GoldenrodCity/scripts.pory"

# 293 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Woman:
# 294 "data/maps/GoldenrodCity/scripts.pory"
	.string "I used to train in Whitney's Gym,\n"
# 295 "data/maps/GoldenrodCity/scripts.pory"
	.string "but all her crying gave me a\l"
# 296 "data/maps/GoldenrodCity/scripts.pory"
	.string "headache.$"
# 297 "data/maps/GoldenrodCity/scripts.pory"

# 298 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerDay:
# 299 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 300 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was night time... How long was I\l"
# 301 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 302 "data/maps/GoldenrodCity/scripts.pory"

# 303 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerNight:
# 304 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 305 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was day time... How long was I\l"
# 306 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 307 "data/maps/GoldenrodCity/scripts.pory"

# 308 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Snubbull:
# 309 "data/maps/GoldenrodCity/scripts.pory"
	.string "Audino: Audiiinii!$"
# 310 "data/maps/GoldenrodCity/scripts.pory"

# 311 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MrMime:
# 312 "data/maps/GoldenrodCity/scripts.pory"
	.string "............................$"
# 313 "data/maps/GoldenrodCity/scripts.pory"

# 314 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_ElmCall:
# 315 "data/maps/GoldenrodCity/scripts.pory"
	.string "Elm: Hello, {PLAYER}?\n"
# 316 "data/maps/GoldenrodCity/scripts.pory"
	.string "Has that egg hatched yet?\p"
# 317 "data/maps/GoldenrodCity/scripts.pory"
	.string "Once it hatches, don't forget to\n"
# 318 "data/maps/GoldenrodCity/scripts.pory"
	.string "bring it by the lab! I need to\l"
# 319 "data/maps/GoldenrodCity/scripts.pory"
	.string "see it!$"
# 320 "data/maps/GoldenrodCity/scripts.pory"

# 321 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_PokefanM:
# 322 "data/maps/GoldenrodCity/scripts.pory"
	.string "They built the new Radio Tower\n"
# 323 "data/maps/GoldenrodCity/scripts.pory"
	.string "to replace the old creaky one.$"
# 324 "data/maps/GoldenrodCity/scripts.pory"

# 325 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster1:
# 326 "data/maps/GoldenrodCity/scripts.pory"
	.string "I know there's a new Bike Shop,\n"
# 327 "data/maps/GoldenrodCity/scripts.pory"
	.string "but I can't find it anywhere.$"
# 328 "data/maps/GoldenrodCity/scripts.pory"

# 329 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1:
# 330 "data/maps/GoldenrodCity/scripts.pory"
	.string "Is that man in black dressed up\n"
# 331 "data/maps/GoldenrodCity/scripts.pory"
	.string "like a Team Rocket member?\p"
# 332 "data/maps/GoldenrodCity/scripts.pory"
	.string "How silly!$"
# 333 "data/maps/GoldenrodCity/scripts.pory"

# 334 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1_Cleared:
# 335 "data/maps/GoldenrodCity/scripts.pory"
	.string "Was that man in black really part\n"
# 336 "data/maps/GoldenrodCity/scripts.pory"
	.string "of Team Rocket? I can't believe it!$"
# 337 "data/maps/GoldenrodCity/scripts.pory"

# 338 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2:
# 339 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Radio Tower in Goldenrod City\n"
# 340 "data/maps/GoldenrodCity/scripts.pory"
	.string "is quite the landmark.\p"
# 341 "data/maps/GoldenrodCity/scripts.pory"
	.string "They're running a campaign now.\p"
# 342 "data/maps/GoldenrodCity/scripts.pory"
	.string "They'll give you a shiny new\n"
# 343 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio if you can pass their quiz.$"
# 344 "data/maps/GoldenrodCity/scripts.pory"

# 345 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2_GotCard:
# 346 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, your POKéGEAR already works\n"
# 347 "data/maps/GoldenrodCity/scripts.pory"
	.string "as a radio!$"
# 348 "data/maps/GoldenrodCity/scripts.pory"

# 349 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster2:
# 350 "data/maps/GoldenrodCity/scripts.pory"
	.string "E-he-he-he…\p"
# 351 "data/maps/GoldenrodCity/scripts.pory"
	.string "I got in trouble for playing in\n"
# 352 "data/maps/GoldenrodCity/scripts.pory"
	.string "the Dept.Store basement.$"
# 353 "data/maps/GoldenrodCity/scripts.pory"

# 354 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Lass:
# 355 "data/maps/GoldenrodCity/scripts.pory"
	.string "That man inside rates your\n"
# 356 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon nicknames.\p"
# 357 "data/maps/GoldenrodCity/scripts.pory"
	.string "He can even rename them.$"
# 358 "data/maps/GoldenrodCity/scripts.pory"

# 359 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Gramps:
# 360 "data/maps/GoldenrodCity/scripts.pory"
	.string "Whew! This city is so big,\n"
# 361 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can't find anything at all.$"
# 362 "data/maps/GoldenrodCity/scripts.pory"

# 363 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout1:
# 364 "data/maps/GoldenrodCity/scripts.pory"
	.string "So this is the Radio Tower…$"
# 365 "data/maps/GoldenrodCity/scripts.pory"

# 366 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout2:
# 367 "data/maps/GoldenrodCity/scripts.pory"
	.string "What do you want, pest?\n"
# 368 "data/maps/GoldenrodCity/scripts.pory"
	.string "Scram already!$"
# 369 "data/maps/GoldenrodCity/scripts.pory"

# 370 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket1:
# 371 "data/maps/GoldenrodCity/scripts.pory"
	.string "Stay out of the way!\n"
# 372 "data/maps/GoldenrodCity/scripts.pory"
	.string "Beat it, kid!$"
# 373 "data/maps/GoldenrodCity/scripts.pory"

# 374 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket2:
# 375 "data/maps/GoldenrodCity/scripts.pory"
	.string "Take over the Radio Tower…\p"
# 376 "data/maps/GoldenrodCity/scripts.pory"
	.string "What? It's none of your business!$"
# 377 "data/maps/GoldenrodCity/scripts.pory"

# 378 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket3:
# 379 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon? They're just tools\n"
# 380 "data/maps/GoldenrodCity/scripts.pory"
	.string "we use to make money!$"
# 381 "data/maps/GoldenrodCity/scripts.pory"

# 382 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket4:
# 383 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our dream will soon come true…\p"
# 384 "data/maps/GoldenrodCity/scripts.pory"
	.string "It was a long, hard struggle…$"
# 385 "data/maps/GoldenrodCity/scripts.pory"

# 386 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket5:
# 387 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, brat! You don't belong here!\n"
# 388 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get lost already!$"
# 389 "data/maps/GoldenrodCity/scripts.pory"

# 390 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket6:
# 391 "data/maps/GoldenrodCity/scripts.pory"
	.string "Come and taste the terror of\n"
# 392 "data/maps/GoldenrodCity/scripts.pory"
	.string "Team Rocket!$"
# 393 "data/maps/GoldenrodCity/scripts.pory"

# 394 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_StationSign:
# 395 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Station$"
# 396 "data/maps/GoldenrodCity/scripts.pory"

# 397 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RadioTowerSign:
# 398 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Radio Tower$"
# 399 "data/maps/GoldenrodCity/scripts.pory"

# 400 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_DeptStoreSign:
# 401 "data/maps/GoldenrodCity/scripts.pory"
	.string "Full Selection of Pokémon Goods!\p"
# 402 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Dept.Store$"
# 403 "data/maps/GoldenrodCity/scripts.pory"

# 404 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GymSign:
# 405 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Pokémon Gym\n"
# 406 "data/maps/GoldenrodCity/scripts.pory"
	.string "Leader: Whitney\p"
# 407 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Incredibly Pretty Girl!$"
# 408 "data/maps/GoldenrodCity/scripts.pory"

# 409 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CitySign:
# 410 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City\p"
# 411 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Festive City of Opulent Charm$"
# 412 "data/maps/GoldenrodCity/scripts.pory"

# 413 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_BikeShopSign:
# 414 "data/maps/GoldenrodCity/scripts.pory"
	.string "The World is a Cycle Path!\n"
# 415 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bike Shop$"
# 416 "data/maps/GoldenrodCity/scripts.pory"

# 417 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GameCornerSign:
# 418 "data/maps/GoldenrodCity/scripts.pory"
	.string "Your Playground!\p"
# 419 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Game Corner$"
# 420 "data/maps/GoldenrodCity/scripts.pory"

# 421 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_NameRaterSign:
# 422 "data/maps/GoldenrodCity/scripts.pory"
	.string "Name Rater\p"
# 423 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get Your Pokémon Nicknames Rated$"
# 424 "data/maps/GoldenrodCity/scripts.pory"

# 425 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundNorthSign:
# 426 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 427 "data/maps/GoldenrodCity/scripts.pory"

# 428 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundSouthSign:
# 429 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 430 "data/maps/GoldenrodCity/scripts.pory"

# 431 "data/maps/GoldenrodCity/scripts.pory"

# 432 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_FlowerShopSign:
# 433 "data/maps/GoldenrodCity/scripts.pory"
	.string "Blooming Beautiful Flower Shop$"
# 434 "data/maps/GoldenrodCity/scripts.pory"

# 435 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorAsk:
# 436 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can teach your Pokémon some\n"
# 437 "data/maps/GoldenrodCity/scripts.pory"
	.string "amazing moves!\p"
# 438 "data/maps/GoldenrodCity/scripts.pory"
	.string "Should I teach one?$"
# 439 "data/maps/GoldenrodCity/scripts.pory"

# 440 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorCost:
# 441 "data/maps/GoldenrodCity/scripts.pory"
	.string "It'll cost you 1000 coins.\n"
# 442 "data/maps/GoldenrodCity/scripts.pory"
	.string "Okay?$"
# 443 "data/maps/GoldenrodCity/scripts.pory"

# 444 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorDecline:
# 445 "data/maps/GoldenrodCity/scripts.pory"
	.string "Aww… But these moves are great!$"
# 446 "data/maps/GoldenrodCity/scripts.pory"

# 447 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorWhich:
# 448 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! You won't regret it!\p"
# 449 "data/maps/GoldenrodCity/scripts.pory"
	.string "Which move should I teach?$"
# 450 "data/maps/GoldenrodCity/scripts.pory"

# 451 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNoCash:
# 452 "data/maps/GoldenrodCity/scripts.pory"
	.string "Too bad. Guess I'll need to\n"
# 453 "data/maps/GoldenrodCity/scripts.pory"
	.string "get some cash from home…$"
# 454 "data/maps/GoldenrodCity/scripts.pory"

# 455 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorUnderstand:
# 456 "data/maps/GoldenrodCity/scripts.pory"
	.string "If you understand this move,\n"
# 457 "data/maps/GoldenrodCity/scripts.pory"
	.string "you've made it as a trainer.$"
# 458 "data/maps/GoldenrodCity/scripts.pory"

# 459 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorFarewell:
# 460 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! Farewell, kid!$"
# 461 "data/maps/GoldenrodCity/scripts.pory"

# 462 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorBut:
# 463 "data/maps/GoldenrodCity/scripts.pory"
	.string "B-but…$"
# 464 "data/maps/GoldenrodCity/scripts.pory"

# 465 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNotEnoughCoins:
# 466 "data/maps/GoldenrodCity/scripts.pory"
	.string "…You don't have enough coins…$"

Goldenrod_Daytime_ExpertM::
# 470 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 471 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertM_Text_0
# 473 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 474 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 475 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_STARAVIA, Goldenrod_Daytime_ExpertM_Movement_0
# 476 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 477 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_ExpertF::
# 481 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 482 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_ExpertF_Text_0
# 484 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 485 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 486 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ELECTABUZZ, Goldenrod_Daytime_ExpertF_Movement_0
# 487 "data/maps/GoldenrodCity/scripts.pory"
	waitmovement 0
# 488 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Staravia::
# 492 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 493 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_STARAVIA, CRY_MODE_NORMAL
# 494 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Staravia_Text_0
# 495 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 496 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Electabuzz::
# 500 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 501 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
# 502 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Electabuzz_Text_0
# 503 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 504 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Daytime_Bystander::
# 508 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 509 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 510 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Daytime_Bystander_Text_0
# 513 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Burglar::
# 518 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 519 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 520 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Burglar_Text_0
# 530 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


Goldenrod_Nighttime_Oldlady::
# 534 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 535 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 536 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_GOLDENROD_SMACKDOWN, Goldenrod_Nighttime_Oldlady_2
# 543 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_1
# 550 "data/maps/GoldenrodCity/scripts.pory"
	giveitem ITEM_TM_SMACK_DOWN
# 551 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_GOLDENROD_SMACKDOWN
# 552 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 555 "data/maps/GoldenrodCity/scripts.pory"
	release
	end

Goldenrod_Nighttime_Oldlady_2:
# 537 "data/maps/GoldenrodCity/scripts.pory"
	msgbox Goldenrod_Nighttime_Oldlady_Text_0
# 540 "data/maps/GoldenrodCity/scripts.pory"
	release
	end


# 475 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertM_Movement_0:
# 475 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
# 475 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_right
	step_end

# 486 "data/maps/GoldenrodCity/scripts.pory"
Goldenrod_Daytime_ExpertF_Movement_0:
# 486 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
# 486 "data/maps/GoldenrodCity/scripts.pory"
	jump_in_place_left
	step_end

Goldenrod_Daytime_ExpertM_Text_0:
# 471 "data/maps/GoldenrodCity/scripts.pory"
	.string "This time I will defeat you, Tiffany!\n"
	.string "We've been training for the whole week!$"

Goldenrod_Daytime_ExpertF_Text_0:
# 482 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hah! If you still have not learned the\n"
	.string "type-matchups, you will never beat me!$"

Goldenrod_Daytime_Staravia_Text_0:
# 494 "data/maps/GoldenrodCity/scripts.pory"
	.string "Staa!$"

Goldenrod_Daytime_Electabuzz_Text_0:
# 502 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bzz!$"

Goldenrod_Daytime_Bystander_Text_0:
# 510 "data/maps/GoldenrodCity/scripts.pory"
	.string "There two have been going on with their\n"
	.string "rivarly for weeks. The city should build\l"
	.string "a battle arena just for them.$"

Goldenrod_Nighttime_Burglar_Text_0:
# 520 "data/maps/GoldenrodCity/scripts.pory"
	.string "The city's rapid developement has \n"
	.string "raised some questions regarding\l"
	.string "where all the money is coming from.\p"
	.string "If they knew just how much money\n"
	.string "trades hands in the underground every\l"
	.string "every day, their eyeballs would pop out.\p"
	.string "Perhaps one day you too will learn, if\n"
	.string "you grow strong enough.$"

Goldenrod_Nighttime_Oldlady_Text_0:
# 537 "data/maps/GoldenrodCity/scripts.pory"
	.string "Smack Down lets you ground any target.\n"
	.string "It's also very useful against Flying\l"
	.string "Pokémon.$"

Goldenrod_Nighttime_Oldlady_Text_1:
# 543 "data/maps/GoldenrodCity/scripts.pory"
	.string "Some petty thief tried to jump me on a\n"
	.string "dark alleway, he was not expecting me\l"
	.string "to Smack Down him with a good old\l"
	.string "Ippon seoinage.\p"
	.string "Here, you should try\n"
	.string "it too.$"
