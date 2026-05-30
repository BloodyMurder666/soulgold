Route49DesertGate_MapScripts::
	.byte 0


Route49GateJoy::
# 4 "data/maps/Route49DesertGate/scripts.pory"
	lock
# 5 "data/maps/Route49DesertGate/scripts.pory"
	faceplayer
# 6 "data/maps/Route49DesertGate/scripts.pory"
	msgbox Route49GateJoy_Text_0
# 7 "data/maps/Route49DesertGate/scripts.pory"
	playse SE_USE_ITEM
# 8 "data/maps/Route49DesertGate/scripts.pory"
	special HealPlayerParty
# 9 "data/maps/Route49DesertGate/scripts.pory"
	msgbox Route49GateJoy_Text_1
# 10 "data/maps/Route49DesertGate/scripts.pory"
	release
	end


Route49GateJoy_Text_0:
# 6 "data/maps/Route49DesertGate/scripts.pory"
	.string "Hi! Let me heal your Pokémon!$"

Route49GateJoy_Text_1:
# 9 "data/maps/Route49DesertGate/scripts.pory"
	.string "Done! All good to go!$"
