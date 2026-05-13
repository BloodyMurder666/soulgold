# 1 "data/maps/GoldenrodCity/scripts.pory"

# 2 "data/maps/GoldenrodCity/scripts.pory"
.set LOCALID_GOLDENROD_ROCKET_SCOUT, 11
# 3 "data/maps/GoldenrodCity/scripts.pory"

# 4 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_MapScripts::
# 5 "data/maps/GoldenrodCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_OnLoad
# 6 "data/maps/GoldenrodCity/scripts.pory"
	.byte 0
# 7 "data/maps/GoldenrodCity/scripts.pory"

# 8 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_OnLoad::
# 9 "data/maps/GoldenrodCity/scripts.pory"
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
# 10 "data/maps/GoldenrodCity/scripts.pory"
	end
# 11 "data/maps/GoldenrodCity/scripts.pory"

# 12 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Trigger:: @flagheap
# 13 "data/maps/GoldenrodCity/scripts.pory"
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
# 14 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_VISITED_GOLDENROD_CITY
# 15 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
# 16 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_BILL
# 17 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
# 18 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
# 19 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
# 20 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
# 21 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
# 22 "data/maps/GoldenrodCity/scripts.pory"
	setflag FLAG_HIDE_RADIOTOWER_OAK
# 23 "data/maps/GoldenrodCity/scripts.pory"
	
# 24 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
# 25 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
# 26 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_NPCS
# 27 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_RETURN
# 28 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_FRUSTRATION
# 29 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_BIKE
# 30 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
# 31 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_EEVEE
# 32 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_SYS_PC_BILL
# 33 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_RETURNED_MACHINE_PART
# 34 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
# 35 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_1
# 36 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_2
# 37 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_MACHOKE_3
# 38 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_COMPLETED_SWITCHES
# 39 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_ENABLE_RADIO
# 40 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_KANTO_RADIO_GOT
# 41 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
# 42 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_SKILL_SWAP
# 43 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_RADIOTOWER_GATE
# 44 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
# 45 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
# 46 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_QUICK_CLAW
# 47 "data/maps/GoldenrodCity/scripts.pory"
	clearflag FLAG_GOT_MAGNET
# 48 "data/maps/GoldenrodCity/scripts.pory"

# 49 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_BUG_CONTEST_STATE, 0
# 50 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_KENYA, 0
# 51 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_LUGIA_OR_HOOH, 0
# 52 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TRAIN, 0
# 53 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_ELEVATOR, 0
# 54 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_GOLDENROD_CITY_STATE, 1
# 55 "data/maps/GoldenrodCity/scripts.pory"
	release
# 56 "data/maps/GoldenrodCity/scripts.pory"
	end
# 57 "data/maps/GoldenrodCity/scripts.pory"

# 58 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Trigger_Music::
# 59 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
# 60 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
# 61 "data/maps/GoldenrodCity/scripts.pory"
	playbgm MUS_HG_ROCKET_TAKEOVER, TRUE
# 62 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TEMP_0, 1 
# 63 "data/maps/GoldenrodCity/scripts.pory"
	end
# 64 "data/maps/GoldenrodCity/scripts.pory"

# 65 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Trigger_MusicNotYet::
# 66 "data/maps/GoldenrodCity/scripts.pory"
	setvar VAR_TEMP_0, 1
# 67 "data/maps/GoldenrodCity/scripts.pory"
	end
# 68 "data/maps/GoldenrodCity/scripts.pory"

# 69 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Elm_Togepi_Call::
# 70 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 71 "data/maps/GoldenrodCity/scripts.pory"
	pokenavcall GoldenrodCity_Text_ElmCall
# 72 "data/maps/GoldenrodCity/scripts.pory"
	waitmessage
# 73 "data/maps/GoldenrodCity/scripts.pory"
	delay 30
# 74 "data/maps/GoldenrodCity/scripts.pory"
	release
# 75 "data/maps/GoldenrodCity/scripts.pory"
	return
# 76 "data/maps/GoldenrodCity/scripts.pory"

# 77 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_PokefanM::
# 78 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 79 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 80 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
# 81 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 82 "data/maps/GoldenrodCity/scripts.pory"
	release
# 83 "data/maps/GoldenrodCity/scripts.pory"
	end
# 84 "data/maps/GoldenrodCity/scripts.pory"

# 85 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster::
# 86 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
# 87 "data/maps/GoldenrodCity/scripts.pory"
	end
# 88 "data/maps/GoldenrodCity/scripts.pory"

# 89 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Youngster2::
# 90 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
# 91 "data/maps/GoldenrodCity/scripts.pory"
	end
# 92 "data/maps/GoldenrodCity/scripts.pory"

# 93 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerF::
# 94 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 95 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 96 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
# 97 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
# 98 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 99 "data/maps/GoldenrodCity/scripts.pory"
	release
# 100 "data/maps/GoldenrodCity/scripts.pory"
	end
# 101 "data/maps/GoldenrodCity/scripts.pory"

# 102 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_CooltrainerFCleared::
# 103 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
# 104 "data/maps/GoldenrodCity/scripts.pory"
	end
# 105 "data/maps/GoldenrodCity/scripts.pory"

# 106 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Lass::
# 107 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 108 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 109 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
# 110 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 111 "data/maps/GoldenrodCity/scripts.pory"
	release
# 112 "data/maps/GoldenrodCity/scripts.pory"
	end
# 113 "data/maps/GoldenrodCity/scripts.pory"

# 114 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Gramps::
# 115 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 116 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 117 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
# 118 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 119 "data/maps/GoldenrodCity/scripts.pory"
	release
# 120 "data/maps/GoldenrodCity/scripts.pory"
	end
# 121 "data/maps/GoldenrodCity/scripts.pory"

# 122 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_NameRaterSign::
# 123 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
# 124 "data/maps/GoldenrodCity/scripts.pory"
	end
# 125 "data/maps/GoldenrodCity/scripts.pory"

# 126 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_RocketScout::
# 127 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 128 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
# 129 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 130 "data/maps/GoldenrodCity/scripts.pory"
	PLAYSE SE_PIN
# 131 "data/maps/GoldenrodCity/scripts.pory"
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
# 132 "data/maps/GoldenrodCity/scripts.pory"
	delay 20
# 133 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 134 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
# 135 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 136 "data/maps/GoldenrodCity/scripts.pory"
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
# 137 "data/maps/GoldenrodCity/scripts.pory"
	release
# 138 "data/maps/GoldenrodCity/scripts.pory"
	end
# 139 "data/maps/GoldenrodCity/scripts.pory"

# 140 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket1::
# 141 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 142 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 143 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
# 144 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 145 "data/maps/GoldenrodCity/scripts.pory"
	release
# 146 "data/maps/GoldenrodCity/scripts.pory"
	end
# 147 "data/maps/GoldenrodCity/scripts.pory"

# 148 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket2::
# 149 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 150 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 151 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
# 152 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 153 "data/maps/GoldenrodCity/scripts.pory"
	release
# 154 "data/maps/GoldenrodCity/scripts.pory"
	end
# 155 "data/maps/GoldenrodCity/scripts.pory"

# 156 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket3::
# 157 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 158 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 159 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
# 160 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 161 "data/maps/GoldenrodCity/scripts.pory"
	release
# 162 "data/maps/GoldenrodCity/scripts.pory"
	end
# 163 "data/maps/GoldenrodCity/scripts.pory"

# 164 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket4::
# 165 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 166 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 167 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
# 168 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 169 "data/maps/GoldenrodCity/scripts.pory"
	release
# 170 "data/maps/GoldenrodCity/scripts.pory"
	end
# 171 "data/maps/GoldenrodCity/scripts.pory"

# 172 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket5::
# 173 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 174 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 175 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
# 176 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 177 "data/maps/GoldenrodCity/scripts.pory"
	release
# 178 "data/maps/GoldenrodCity/scripts.pory"
	end
# 179 "data/maps/GoldenrodCity/scripts.pory"

# 180 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Rocket6::
# 181 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 182 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 183 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
# 184 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 185 "data/maps/GoldenrodCity/scripts.pory"
	release
# 186 "data/maps/GoldenrodCity/scripts.pory"
	end
# 187 "data/maps/GoldenrodCity/scripts.pory"

# 188 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Woman::
# 189 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 190 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 191 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
# 192 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 193 "data/maps/GoldenrodCity/scripts.pory"
	release
# 194 "data/maps/GoldenrodCity/scripts.pory"
	end
# 195 "data/maps/GoldenrodCity/scripts.pory"

# 196 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker::
# 197 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 198 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 199 "data/maps/GoldenrodCity/scripts.pory"
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
# 200 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
# 201 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 202 "data/maps/GoldenrodCity/scripts.pory"
	release
# 203 "data/maps/GoldenrodCity/scripts.pory"
	end
# 204 "data/maps/GoldenrodCity/scripts.pory"

# 205 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Hiker2::
# 206 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
# 207 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 208 "data/maps/GoldenrodCity/scripts.pory"
	release
# 209 "data/maps/GoldenrodCity/scripts.pory"
	end
# 210 "data/maps/GoldenrodCity/scripts.pory"

# 211 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Snubbull::
# 212 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 213 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 214 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 215 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
# 216 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
# 217 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 218 "data/maps/GoldenrodCity/scripts.pory"
	release
# 219 "data/maps/GoldenrodCity/scripts.pory"
	end
# 220 "data/maps/GoldenrodCity/scripts.pory"

# 221 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Mime::
# 222 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 223 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 224 "data/maps/GoldenrodCity/scripts.pory"
	waitse
# 225 "data/maps/GoldenrodCity/scripts.pory"
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
# 226 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
# 227 "data/maps/GoldenrodCity/scripts.pory"
	waitmoncry
# 228 "data/maps/GoldenrodCity/scripts.pory"
	release
# 229 "data/maps/GoldenrodCity/scripts.pory"
	end
# 230 "data/maps/GoldenrodCity/scripts.pory"

# 231 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignUnderground::
# 232 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 233 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
# 234 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 235 "data/maps/GoldenrodCity/scripts.pory"
	release
# 236 "data/maps/GoldenrodCity/scripts.pory"
	end
# 237 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignDept::
# 238 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 239 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
# 240 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 241 "data/maps/GoldenrodCity/scripts.pory"
	release
# 242 "data/maps/GoldenrodCity/scripts.pory"
	end
# 243 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignBike::
# 244 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 245 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
# 246 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 247 "data/maps/GoldenrodCity/scripts.pory"
	release
# 248 "data/maps/GoldenrodCity/scripts.pory"
	end
# 249 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignTrain::
# 250 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 251 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
# 252 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 253 "data/maps/GoldenrodCity/scripts.pory"
	release
# 254 "data/maps/GoldenrodCity/scripts.pory"
	end
# 255 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGym::
# 256 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 257 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
# 258 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 259 "data/maps/GoldenrodCity/scripts.pory"
	release
# 260 "data/maps/GoldenrodCity/scripts.pory"
	end
# 261 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignFlower::
# 262 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 263 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
# 264 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 265 "data/maps/GoldenrodCity/scripts.pory"
	release
# 266 "data/maps/GoldenrodCity/scripts.pory"
	end
# 267 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignRadio::
# 268 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 269 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
# 270 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 271 "data/maps/GoldenrodCity/scripts.pory"
	release
# 272 "data/maps/GoldenrodCity/scripts.pory"
	end
# 273 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_SignGameCorner::
# 274 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 275 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
# 276 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 277 "data/maps/GoldenrodCity/scripts.pory"
	release
# 278 "data/maps/GoldenrodCity/scripts.pory"
	end
# 279 "data/maps/GoldenrodCity/scripts.pory"

# 280 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_EventScript_Beauty::
# 281 "data/maps/GoldenrodCity/scripts.pory"
	lock
# 282 "data/maps/GoldenrodCity/scripts.pory"
	faceplayer
# 283 "data/maps/GoldenrodCity/scripts.pory"
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
# 284 "data/maps/GoldenrodCity/scripts.pory"
	closemessage
# 285 "data/maps/GoldenrodCity/scripts.pory"
	release
# 286 "data/maps/GoldenrodCity/scripts.pory"
	end
# 287 "data/maps/GoldenrodCity/scripts.pory"

# 288 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Beauty:
# 289 "data/maps/GoldenrodCity/scripts.pory"
	.string "This is the Goldenrod Gym!\p"
# 290 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our leader Whitney is not here\n"
# 291 "data/maps/GoldenrodCity/scripts.pory"
	.string "right now. She might be at the\l"
# 292 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio Tower.$"
# 293 "data/maps/GoldenrodCity/scripts.pory"

# 294 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Woman:
# 295 "data/maps/GoldenrodCity/scripts.pory"
	.string "I used to train in Whitney's Gym,\n"
# 296 "data/maps/GoldenrodCity/scripts.pory"
	.string "but all her crying gave me a\l"
# 297 "data/maps/GoldenrodCity/scripts.pory"
	.string "headache.$"
# 298 "data/maps/GoldenrodCity/scripts.pory"

# 299 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerDay:
# 300 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 301 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was night time... How long was I\l"
# 302 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 303 "data/maps/GoldenrodCity/scripts.pory"

# 304 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_HikerNight:
# 305 "data/maps/GoldenrodCity/scripts.pory"
	.string "When I went into the Game Corner\n"
# 306 "data/maps/GoldenrodCity/scripts.pory"
	.string "it was day time... How long was I\l"
# 307 "data/maps/GoldenrodCity/scripts.pory"
	.string "in there?!$"
# 308 "data/maps/GoldenrodCity/scripts.pory"

# 309 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Snubbull:
# 310 "data/maps/GoldenrodCity/scripts.pory"
	.string "Audino: Audiiinii!$"
# 311 "data/maps/GoldenrodCity/scripts.pory"

# 312 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MrMime:
# 313 "data/maps/GoldenrodCity/scripts.pory"
	.string "............................$"
# 314 "data/maps/GoldenrodCity/scripts.pory"

# 315 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_ElmCall:
# 316 "data/maps/GoldenrodCity/scripts.pory"
	.string "Elm: Hello, {PLAYER}?\n"
# 317 "data/maps/GoldenrodCity/scripts.pory"
	.string "Has that egg hatched yet?\p"
# 318 "data/maps/GoldenrodCity/scripts.pory"
	.string "Once it hatches, don't forget to\n"
# 319 "data/maps/GoldenrodCity/scripts.pory"
	.string "bring it by the lab! I need to\l"
# 320 "data/maps/GoldenrodCity/scripts.pory"
	.string "see it!$"
# 321 "data/maps/GoldenrodCity/scripts.pory"

# 322 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_PokefanM:
# 323 "data/maps/GoldenrodCity/scripts.pory"
	.string "They built the new Radio Tower\n"
# 324 "data/maps/GoldenrodCity/scripts.pory"
	.string "to replace the old creaky one.$"
# 325 "data/maps/GoldenrodCity/scripts.pory"

# 326 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster1:
# 327 "data/maps/GoldenrodCity/scripts.pory"
	.string "I know there's a new Bike Shop,\n"
# 328 "data/maps/GoldenrodCity/scripts.pory"
	.string "but I can't find it anywhere.$"
# 329 "data/maps/GoldenrodCity/scripts.pory"

# 330 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1:
# 331 "data/maps/GoldenrodCity/scripts.pory"
	.string "Is that man in black dressed up\n"
# 332 "data/maps/GoldenrodCity/scripts.pory"
	.string "like a Team Rocket member?\p"
# 333 "data/maps/GoldenrodCity/scripts.pory"
	.string "How silly!$"
# 334 "data/maps/GoldenrodCity/scripts.pory"

# 335 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF1_Cleared:
# 336 "data/maps/GoldenrodCity/scripts.pory"
	.string "Was that man in black really part\n"
# 337 "data/maps/GoldenrodCity/scripts.pory"
	.string "of Team Rocket? I can't believe it!$"
# 338 "data/maps/GoldenrodCity/scripts.pory"

# 339 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2:
# 340 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Radio Tower in Goldenrod City\n"
# 341 "data/maps/GoldenrodCity/scripts.pory"
	.string "is quite the landmark.\p"
# 342 "data/maps/GoldenrodCity/scripts.pory"
	.string "They're running a campaign now.\p"
# 343 "data/maps/GoldenrodCity/scripts.pory"
	.string "They'll give you a shiny new\n"
# 344 "data/maps/GoldenrodCity/scripts.pory"
	.string "Radio if you can pass their quiz.$"
# 345 "data/maps/GoldenrodCity/scripts.pory"

# 346 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CooltrainerF2_GotCard:
# 347 "data/maps/GoldenrodCity/scripts.pory"
	.string "Oh, your POKéGEAR already works\n"
# 348 "data/maps/GoldenrodCity/scripts.pory"
	.string "as a radio!$"
# 349 "data/maps/GoldenrodCity/scripts.pory"

# 350 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Youngster2:
# 351 "data/maps/GoldenrodCity/scripts.pory"
	.string "E-he-he-he…\p"
# 352 "data/maps/GoldenrodCity/scripts.pory"
	.string "I got in trouble for playing in\n"
# 353 "data/maps/GoldenrodCity/scripts.pory"
	.string "the Dept.Store basement.$"
# 354 "data/maps/GoldenrodCity/scripts.pory"

# 355 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Lass:
# 356 "data/maps/GoldenrodCity/scripts.pory"
	.string "That man inside rates your\n"
# 357 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon nicknames.\p"
# 358 "data/maps/GoldenrodCity/scripts.pory"
	.string "He can even rename them.$"
# 359 "data/maps/GoldenrodCity/scripts.pory"

# 360 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Gramps:
# 361 "data/maps/GoldenrodCity/scripts.pory"
	.string "Whew! This town is so big,\n"
# 362 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can't find anything at all.$"
# 363 "data/maps/GoldenrodCity/scripts.pory"

# 364 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout1:
# 365 "data/maps/GoldenrodCity/scripts.pory"
	.string "So this is the Radio Tower…$"
# 366 "data/maps/GoldenrodCity/scripts.pory"

# 367 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RocketScout2:
# 368 "data/maps/GoldenrodCity/scripts.pory"
	.string "What do you want, pest?\n"
# 369 "data/maps/GoldenrodCity/scripts.pory"
	.string "Scram already!$"
# 370 "data/maps/GoldenrodCity/scripts.pory"

# 371 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket1:
# 372 "data/maps/GoldenrodCity/scripts.pory"
	.string "Stay out of the way!\n"
# 373 "data/maps/GoldenrodCity/scripts.pory"
	.string "Beat it, kid!$"
# 374 "data/maps/GoldenrodCity/scripts.pory"

# 375 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket2:
# 376 "data/maps/GoldenrodCity/scripts.pory"
	.string "Take over the Radio Tower…\p"
# 377 "data/maps/GoldenrodCity/scripts.pory"
	.string "What? It's none of your business!$"
# 378 "data/maps/GoldenrodCity/scripts.pory"

# 379 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket3:
# 380 "data/maps/GoldenrodCity/scripts.pory"
	.string "Pokémon? They're just tools\n"
# 381 "data/maps/GoldenrodCity/scripts.pory"
	.string "we use to make money!$"
# 382 "data/maps/GoldenrodCity/scripts.pory"

# 383 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket4:
# 384 "data/maps/GoldenrodCity/scripts.pory"
	.string "Our dream will soon come true…\p"
# 385 "data/maps/GoldenrodCity/scripts.pory"
	.string "It was a long, hard struggle…$"
# 386 "data/maps/GoldenrodCity/scripts.pory"

# 387 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket5:
# 388 "data/maps/GoldenrodCity/scripts.pory"
	.string "Hey, brat! You don't belong here!\n"
# 389 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get lost already!$"
# 390 "data/maps/GoldenrodCity/scripts.pory"

# 391 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_Rocket6:
# 392 "data/maps/GoldenrodCity/scripts.pory"
	.string "Come and taste the terror of\n"
# 393 "data/maps/GoldenrodCity/scripts.pory"
	.string "Team Rocket!$"
# 394 "data/maps/GoldenrodCity/scripts.pory"

# 395 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_StationSign:
# 396 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Station$"
# 397 "data/maps/GoldenrodCity/scripts.pory"

# 398 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_RadioTowerSign:
# 399 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Radio Tower$"
# 400 "data/maps/GoldenrodCity/scripts.pory"

# 401 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_DeptStoreSign:
# 402 "data/maps/GoldenrodCity/scripts.pory"
	.string "Full Selection of Pokémon Goods!\p"
# 403 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Dept.Store$"
# 404 "data/maps/GoldenrodCity/scripts.pory"

# 405 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GymSign:
# 406 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Pokémon Gym\n"
# 407 "data/maps/GoldenrodCity/scripts.pory"
	.string "Leader: Whitney\p"
# 408 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Incredibly Pretty Girl!$"
# 409 "data/maps/GoldenrodCity/scripts.pory"

# 410 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_CitySign:
# 411 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City\p"
# 412 "data/maps/GoldenrodCity/scripts.pory"
	.string "The Festive City of Opulent Charm$"
# 413 "data/maps/GoldenrodCity/scripts.pory"

# 414 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_BikeShopSign:
# 415 "data/maps/GoldenrodCity/scripts.pory"
	.string "The World is a Cycle Path!\n"
# 416 "data/maps/GoldenrodCity/scripts.pory"
	.string "Bike Shop$"
# 417 "data/maps/GoldenrodCity/scripts.pory"

# 418 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_GameCornerSign:
# 419 "data/maps/GoldenrodCity/scripts.pory"
	.string "Your Playground!\p"
# 420 "data/maps/GoldenrodCity/scripts.pory"
	.string "Goldenrod City Game Corner$"
# 421 "data/maps/GoldenrodCity/scripts.pory"

# 422 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_NameRaterSign:
# 423 "data/maps/GoldenrodCity/scripts.pory"
	.string "Name Rater\p"
# 424 "data/maps/GoldenrodCity/scripts.pory"
	.string "Get Your Pokémon Nicknames Rated$"
# 425 "data/maps/GoldenrodCity/scripts.pory"

# 426 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundNorthSign:
# 427 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 428 "data/maps/GoldenrodCity/scripts.pory"

# 429 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_UndergroundSouthSign:
# 430 "data/maps/GoldenrodCity/scripts.pory"
	.string "Underground Entrance$"
# 431 "data/maps/GoldenrodCity/scripts.pory"

# 432 "data/maps/GoldenrodCity/scripts.pory"

# 433 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_FlowerShopSign:
# 434 "data/maps/GoldenrodCity/scripts.pory"
	.string "Blooming Beautiful Flower Shop$"
# 435 "data/maps/GoldenrodCity/scripts.pory"

# 436 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorAsk:
# 437 "data/maps/GoldenrodCity/scripts.pory"
	.string "I can teach your Pokémon some\n"
# 438 "data/maps/GoldenrodCity/scripts.pory"
	.string "amazing moves!\p"
# 439 "data/maps/GoldenrodCity/scripts.pory"
	.string "Should I teach one?$"
# 440 "data/maps/GoldenrodCity/scripts.pory"

# 441 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorCost:
# 442 "data/maps/GoldenrodCity/scripts.pory"
	.string "It'll cost you 1000 coins.\n"
# 443 "data/maps/GoldenrodCity/scripts.pory"
	.string "Okay?$"
# 444 "data/maps/GoldenrodCity/scripts.pory"

# 445 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorDecline:
# 446 "data/maps/GoldenrodCity/scripts.pory"
	.string "Aww… But these moves are great!$"
# 447 "data/maps/GoldenrodCity/scripts.pory"

# 448 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorWhich:
# 449 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! You won't regret it!\p"
# 450 "data/maps/GoldenrodCity/scripts.pory"
	.string "Which move should I teach?$"
# 451 "data/maps/GoldenrodCity/scripts.pory"

# 452 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNoCash:
# 453 "data/maps/GoldenrodCity/scripts.pory"
	.string "Too bad. Guess I'll need to\n"
# 454 "data/maps/GoldenrodCity/scripts.pory"
	.string "get some cash from home…$"
# 455 "data/maps/GoldenrodCity/scripts.pory"

# 456 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorUnderstand:
# 457 "data/maps/GoldenrodCity/scripts.pory"
	.string "If you understand this move,\n"
# 458 "data/maps/GoldenrodCity/scripts.pory"
	.string "you've made it as a trainer.$"
# 459 "data/maps/GoldenrodCity/scripts.pory"

# 460 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorFarewell:
# 461 "data/maps/GoldenrodCity/scripts.pory"
	.string "Wahahah! Farewell, kid!$"
# 462 "data/maps/GoldenrodCity/scripts.pory"

# 463 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorBut:
# 464 "data/maps/GoldenrodCity/scripts.pory"
	.string "B-but…$"
# 465 "data/maps/GoldenrodCity/scripts.pory"

# 466 "data/maps/GoldenrodCity/scripts.pory"
GoldenrodCity_Text_MoveTutorNotEnoughCoins:
# 467 "data/maps/GoldenrodCity/scripts.pory"
	.string "…You don't have enough coins…$"
