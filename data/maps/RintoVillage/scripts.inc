RintoVillage_MapScripts::
	.byte 0


Rinto_OldLady::
# 4 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_OldLady_Text_0, MSGBOX_NPC
	return


Rinto_TempleSage::
# 8 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gentleman::
# 13 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0, MSGBOX_NPC
	return


Rinto_EastGuard::
# 17 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 23 "data/maps/RintoVillage/scripts.pory"
	lock
# 24 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 25 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 26 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 27 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 28 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 31 "data/maps/RintoVillage/scripts.pory"
	waitmessage
# 32 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 33 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 34 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 40 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 44 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 48 "data/maps/RintoVillage/scripts.pory"
	lock
# 49 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 50 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 55 "data/maps/RintoVillage/scripts.pory"
	lock
# 56 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 57 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 58 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 59 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 64 "data/maps/RintoVillage/scripts.pory"
	lock
# 65 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 66 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 67 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 71 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 76 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 24 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 24 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 26 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 26 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 32 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 32 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_OldLady_Text_0:
# 4 "data/maps/RintoVillage/scripts.pory"
	.string "More visitors lately...$"

Rinto_TempleSage_Text_0:
# 8 "data/maps/RintoVillage/scripts.pory"
	.string "Access to the temple is only permitted\n"
	.string "to those with permission from our Sage.$"

Rinto_Gentleman_Text_0:
# 13 "data/maps/RintoVillage/scripts.pory"
	.string "I travelled...$"

Rinto_EastGuard_Text_0:
# 17 "data/maps/RintoVillage/scripts.pory"
	.string "The treacherous desert to the east is\n"
	.string "too dangerous right now. I cannot allow\l"
	.string "you to pass as you are right now.$"

Rinto_LittleGirl_Text_0:
# 40 "data/maps/RintoVillage/scripts.pory"
	.string "Our town...$"

Rinto_Fatman_Text_0:
# 44 "data/maps/RintoVillage/scripts.pory"
	.string "The local...$"

Rinto_Dancer_Text_0:
# 49 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 57 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 66 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check our wares!$"

Rinto_GameboyKid_Text_0:
# 76 "data/maps/RintoVillage/scripts.pory"
	.string "Yo$"
