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
# 16 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gible::
# 27 "data/maps/RintoVillage/scripts.pory"
	lock
# 28 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 29 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_GIBLE, CRY_MODE_NORMAL
# 30 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gible_Text_0
# 31 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 32 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Maractus::
# 37 "data/maps/RintoVillage/scripts.pory"
	lock
# 38 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 39 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_MARACTUS, CRY_MODE_NORMAL
# 40 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Maractus_Text_0
# 41 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 42 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Piplup::
# 47 "data/maps/RintoVillage/scripts.pory"
	lock
# 48 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Piplup_Text_0
# 49 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Gentleman::
# 54 "data/maps/RintoVillage/scripts.pory"
	lock
# 55 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 56 "data/maps/RintoVillage/scripts.pory"
	goto_if_set FLAG_GOT_TM_REST, Rinto_Gentleman_2
# 65 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_1
# 70 "data/maps/RintoVillage/scripts.pory"
	giveitem ITEM_TM_REST
# 71 "data/maps/RintoVillage/scripts.pory"
	setflag FLAG_GOT_TM_REST
# 72 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 77 "data/maps/RintoVillage/scripts.pory"
	release
	end

Rinto_Gentleman_2:
# 57 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 62 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_EastGuard::
# 82 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 88 "data/maps/RintoVillage/scripts.pory"
	lock
# 89 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 90 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 91 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 92 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 93 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 96 "data/maps/RintoVillage/scripts.pory"
	closemessage
# 97 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 98 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 99 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 105 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 113 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 119 "data/maps/RintoVillage/scripts.pory"
	lock
# 120 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 121 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 126 "data/maps/RintoVillage/scripts.pory"
	lock
# 127 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 128 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 129 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 130 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 135 "data/maps/RintoVillage/scripts.pory"
	lock
# 136 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 137 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 138 "data/maps/RintoVillage/scripts.pory"
	pokemart Rinto_Stall
# 139 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_1
# 140 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 144 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
# 145 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_RING_TARGET
# 146 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_BINDING_BAND
# 147 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 148 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WIDE_LENS
# 149 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WISE_GLASSES
# 150 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 154 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 89 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 89 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 91 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 91 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 97 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 97 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_OldLady_Text_0:
# 9 "data/maps/RintoVillage/scripts.pory"
	.string "Oh more tourists?\p"
	.string "I hope you don't mind the\n"
	.string "temperature variations! Ho ho ho!$"

Rinto_TempleSage_Text_0:
# 16 "data/maps/RintoVillage/scripts.pory"
	.string "I used to be a member of the Team\n"
	.string "Magma. \p"
	.string "After leaving I decided that I want\n"
	.string "to travel the world as a pilgrim.\p"
	.string "It has been quite refreshing, seeing\n"
	.string "the beauty of the world.$"

Rinto_Gible_Text_0:
# 30 "data/maps/RintoVillage/scripts.pory"
	.string "Gible: Gibgib!$"

Rinto_Maractus_Text_0:
# 40 "data/maps/RintoVillage/scripts.pory"
	.string "Maractus: Maaaai!$"

Rinto_Piplup_Text_0:
# 48 "data/maps/RintoVillage/scripts.pory"
	.string "...The Piplup appears to have dozed off.$"

Rinto_Gentleman_Text_0:
# 57 "data/maps/RintoVillage/scripts.pory"
	.string "Rest let's you restore health and\n"
	.string "keep going. \p"
	.string "Do not push yourself without taking \n"
	.string "the time to heal.$"

Rinto_Gentleman_Text_1:
# 65 "data/maps/RintoVillage/scripts.pory"
	.string "Resting after travelling afar is\n"
	.string "equally important! Do not neglect\l"
	.string "your health even at a young age!\p"
	.string "Take this.$"

Rinto_EastGuard_Text_0:
# 82 "data/maps/RintoVillage/scripts.pory"
	.string "The sandstorms are too intense right\n"
	.string "now. I cannot allow you to pass until\l"
	.string "they calm down.$"

Rinto_LittleGirl_Text_0:
# 105 "data/maps/RintoVillage/scripts.pory"
	.string "I saw it! \p"
	.string "Red and blue!\p"
	.string "They flew over the town to the east!$"

Rinto_Fatman_Text_0:
# 113 "data/maps/RintoVillage/scripts.pory"
	.string "The blazing sun would make this place\n"
	.string "uninhabitable if not for the small\l"
	.string "opening to the sea.$"

Rinto_Dancer_Text_0:
# 120 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 128 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 137 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check out my wares!$"

Rinto_Merchant_Text_1:
# 139 "data/maps/RintoVillage/scripts.pory"
	.string "Come back soon!$"

Rinto_GameboyKid_Text_0:
# 154 "data/maps/RintoVillage/scripts.pory"
	.string "The pyramid in the west has been locked\n"
	.string "up for a long time. \p"
	.string "I wonder if the key to opening \n"
	.string "it even exists anymore?$"
