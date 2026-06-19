EcruteakCity_House3_MapScripts::
	.byte 0


EcruteakCity_House3_HexLady::
# 4 "data/maps/EcruteakCity_House3/scripts.pory"
	lock
# 5 "data/maps/EcruteakCity_House3/scripts.pory"
	faceplayer
# 6 "data/maps/EcruteakCity_House3/scripts.pory"
	goto_if_set FLAG_TM_HEX, EcruteakCity_House3_HexLady_2
# 13 "data/maps/EcruteakCity_House3/scripts.pory"
	msgbox EcruteakCity_House3_HexLady_Text_1
# 17 "data/maps/EcruteakCity_House3/scripts.pory"
	waitmessage
# 18 "data/maps/EcruteakCity_House3/scripts.pory"
	giveitem ITEM_TM_HEX
# 19 "data/maps/EcruteakCity_House3/scripts.pory"
	setflag FLAG_TM_HEX
# 20 "data/maps/EcruteakCity_House3/scripts.pory"
	msgbox EcruteakCity_House3_HexLady_Text_0
# 23 "data/maps/EcruteakCity_House3/scripts.pory"
	release
	end

EcruteakCity_House3_HexLady_2:
# 7 "data/maps/EcruteakCity_House3/scripts.pory"
	msgbox EcruteakCity_House3_HexLady_Text_0
# 10 "data/maps/EcruteakCity_House3/scripts.pory"
	release
	end


EcruteakCity_House3_Lampent::
# 28 "data/maps/EcruteakCity_House3/scripts.pory"
	lock
# 29 "data/maps/EcruteakCity_House3/scripts.pory"
	faceplayer
# 30 "data/maps/EcruteakCity_House3/scripts.pory"
	playmoncry SPECIES_LAMPENT, CRY_MODE_NORMAL
# 31 "data/maps/EcruteakCity_House3/scripts.pory"
	msgbox EcruteakCity_House3_Lampent_Text_0
# 32 "data/maps/EcruteakCity_House3/scripts.pory"
	release
	end


EcruteakCity_House3_HexLady_Text_0:
# 7 "data/maps/EcruteakCity_House3/scripts.pory"
	.string "Hex... Doubles in power...\n"
	.string "Against those affected by status\l"
	.string "conditions...$"

EcruteakCity_House3_HexLady_Text_1:
# 13 "data/maps/EcruteakCity_House3/scripts.pory"
	.string "Attacking when the enemy is afflicted...\n"
	.string "The key strategy to winning a battle...\p"
	.string "Here... Take it...$"

EcruteakCity_House3_Lampent_Text_0:
# 31 "data/maps/EcruteakCity_House3/scripts.pory"
	.string "Lampent: Lamppp!$"
