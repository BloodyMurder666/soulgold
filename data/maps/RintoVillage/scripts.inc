RintoVillage_MapScripts::
# 2 "data/maps/RintoVillage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/RintoVillage/scripts.pory"
	setflag FLAG_VISITED_RINTO_VILLAGE
	end


Rinto_OldLady::
# 9 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_OldLady_Text_0, MSGBOX_NPC
	return


Rinto_TempleSage::
# 14 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gentleman::
# 19 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0, MSGBOX_NPC
	return


Rinto_EastGuard::
# 23 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 29 "data/maps/RintoVillage/scripts.pory"
	lock
# 30 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 31 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 32 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 33 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 34 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 37 "data/maps/RintoVillage/scripts.pory"
	waitmessage
# 38 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 39 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 40 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 46 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 50 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 54 "data/maps/RintoVillage/scripts.pory"
	lock
# 55 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 56 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 61 "data/maps/RintoVillage/scripts.pory"
	lock
# 62 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 63 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 64 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 65 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 70 "data/maps/RintoVillage/scripts.pory"
	lock
# 71 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 72 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 73 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 77 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 82 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 30 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 30 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 32 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 32 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 38 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 38 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_OldLady_Text_0:
# 9 "data/maps/RintoVillage/scripts.pory"
	.string "The recent heatwaves make it difficult\n"
	.string "to sleep.$"

Rinto_TempleSage_Text_0:
# 14 "data/maps/RintoVillage/scripts.pory"
	.string "Access to the temple is only permitted\n"
	.string "to those with permission from our Sage.$"

Rinto_Gentleman_Text_0:
# 19 "data/maps/RintoVillage/scripts.pory"
	.string "I travelled...$"

Rinto_EastGuard_Text_0:
# 23 "data/maps/RintoVillage/scripts.pory"
	.string "The treacherous desert to the east is\n"
	.string "too dangerous right now. I cannot allow\l"
	.string "you to pass as you are right now.$"

Rinto_LittleGirl_Text_0:
# 46 "data/maps/RintoVillage/scripts.pory"
	.string "Our town...$"

Rinto_Fatman_Text_0:
# 50 "data/maps/RintoVillage/scripts.pory"
	.string "The local...$"

Rinto_Dancer_Text_0:
# 55 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 63 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 72 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check our wares!$"

Rinto_GameboyKid_Text_0:
# 82 "data/maps/RintoVillage/scripts.pory"
	.string "Yo$"
