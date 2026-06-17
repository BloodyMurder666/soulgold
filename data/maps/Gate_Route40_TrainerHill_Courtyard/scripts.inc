# 1 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"

# 2 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
Gate_Route40_TrainerHill_Courtyard_MapScripts::
# 3 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	.byte 0

BattleTowerGuard::
# 7 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerGuard_Text_0, MSGBOX_NPC
	return


BattleTowerTunnelFrustrationNPC::
# 12 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	lock
# 13 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	faceplayer
# 14 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	goto_if_unset FLAG_GOT_FRUSTRATION, BattleTowerTunnelFrustrationNPC_2
BattleTowerTunnelFrustrationNPC_1:
# 21 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerTunnelFrustrationNPC_Text_1
# 24 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	release
	end

BattleTowerTunnelFrustrationNPC_2:
# 15 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	msgbox BattleTowerTunnelFrustrationNPC_Text_0
# 18 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	giveitem ITEM_TM_FRUSTRATION
# 19 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	setflag FLAG_GOT_FRUSTRATION
	goto BattleTowerTunnelFrustrationNPC_1


BattleTowerGuard_Text_0:
# 7 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	.string "Ahead is the Battle Tower, where strong\n"
	.string "trainers gather.$"

BattleTowerTunnelFrustrationNPC_Text_0:
# 15 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	.string "I lost on first round of the Battle\n"
	.string "Tower, I need to release my frustration\l"
	.string "by giving you this.$"

BattleTowerTunnelFrustrationNPC_Text_1:
# 21 "data/maps/Gate_Route40_TrainerHill_Courtyard/scripts.pory"
	.string "Frustration deals more damage the less\n"
	.string "your Pokémon likes you. It can happen\l"
	.string "if you keep losing battles like me!$"
