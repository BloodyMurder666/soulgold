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
# 13 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gentleman::
# 18 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0, MSGBOX_NPC
	return


Rinto_EastGuard::
# 22 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 28 "data/maps/RintoVillage/scripts.pory"
	lock
# 29 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 30 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 31 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 32 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 33 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 36 "data/maps/RintoVillage/scripts.pory"
	waitmessage
# 37 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 38 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 39 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 45 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 49 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 53 "data/maps/RintoVillage/scripts.pory"
	lock
# 54 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 55 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 60 "data/maps/RintoVillage/scripts.pory"
	lock
# 61 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 62 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 63 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 64 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 69 "data/maps/RintoVillage/scripts.pory"
	lock
# 70 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 71 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 72 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 76 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 81 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 29 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 29 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 31 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 31 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 37 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 37 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_OldLady_Text_0:
# 9 "data/maps/RintoVillage/scripts.pory"
	.string "More visitors lately...$"

Rinto_TempleSage_Text_0:
# 13 "data/maps/RintoVillage/scripts.pory"
	.string "Access to the temple is only permitted\n"
	.string "to those with permission from our Sage.$"

Rinto_Gentleman_Text_0:
# 18 "data/maps/RintoVillage/scripts.pory"
	.string "I travelled...$"

Rinto_EastGuard_Text_0:
# 22 "data/maps/RintoVillage/scripts.pory"
	.string "The treacherous desert to the east is\n"
	.string "too dangerous right now. I cannot allow\l"
	.string "you to pass as you are right now.$"

Rinto_LittleGirl_Text_0:
# 45 "data/maps/RintoVillage/scripts.pory"
	.string "Our town...$"

Rinto_Fatman_Text_0:
# 49 "data/maps/RintoVillage/scripts.pory"
	.string "The local...$"

Rinto_Dancer_Text_0:
# 54 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 62 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 71 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check our wares!$"

Rinto_GameboyKid_Text_0:
# 81 "data/maps/RintoVillage/scripts.pory"
	.string "Yo$"
