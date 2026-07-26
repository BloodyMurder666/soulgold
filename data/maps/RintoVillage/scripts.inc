RintoVillage_MapScripts::
# 2 "data/maps/RintoVillage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/RintoVillage/scripts.pory"
	setflag FLAG_VISITED_RINTO_VILLAGE
# 4 "data/maps/RintoVillage/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 5 "data/maps/RintoVillage/scripts.pory"
	setvar VAR_POSTGAME_UNLOCKS_STATE, 1
	goto RintoVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


Rinto_Sign::
# 12 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Sign_Text_0, MSGBOX_SIGN
	return


Rinto_OldLady::
# 17 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_OldLady_Text_0, MSGBOX_NPC
	return


Rinto_TempleSage::
# 24 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gible::
# 35 "data/maps/RintoVillage/scripts.pory"
	lock
# 36 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 37 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_GIBLE, CRY_MODE_NORMAL
# 38 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gible_Text_0
# 39 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 40 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Maractus::
# 45 "data/maps/RintoVillage/scripts.pory"
	lock
# 46 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 47 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_MARACTUS, CRY_MODE_NORMAL
# 48 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Maractus_Text_0
# 49 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 50 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Piplup::
# 55 "data/maps/RintoVillage/scripts.pory"
	lock
# 56 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Piplup_Text_0
# 57 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Gentleman::
# 62 "data/maps/RintoVillage/scripts.pory"
	lock
# 63 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 64 "data/maps/RintoVillage/scripts.pory"
	goto_if_set FLAG_GOT_TM_REST, Rinto_Gentleman_2
# 73 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_1
# 78 "data/maps/RintoVillage/scripts.pory"
	giveitem ITEM_TM_REST
# 79 "data/maps/RintoVillage/scripts.pory"
	setflag FLAG_GOT_TM_REST
# 80 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 85 "data/maps/RintoVillage/scripts.pory"
	release
	end

Rinto_Gentleman_2:
# 65 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 70 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_EastGuard::
# 90 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 96 "data/maps/RintoVillage/scripts.pory"
	lock
# 97 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 98 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 99 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 100 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 101 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 104 "data/maps/RintoVillage/scripts.pory"
	closemessage
# 105 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 106 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 107 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 113 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 121 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 127 "data/maps/RintoVillage/scripts.pory"
	lock
# 128 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 129 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 134 "data/maps/RintoVillage/scripts.pory"
	lock
# 135 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 136 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 137 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 138 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 143 "data/maps/RintoVillage/scripts.pory"
	lock
# 144 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 145 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 146 "data/maps/RintoVillage/scripts.pory"
	pokemart Rinto_Stall
# 147 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_1
# 148 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 152 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
# 153 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_RING_TARGET
# 154 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_BINDING_BAND
# 155 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 156 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WIDE_LENS
# 157 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WISE_GLASSES
# 158 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 162 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 97 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 97 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 99 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 99 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 105 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 105 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_Sign_Text_0:
# 12 "data/maps/RintoVillage/scripts.pory"
	.string "Rinto Village\n"
	.string "Sunbathed Village$"

Rinto_OldLady_Text_0:
# 17 "data/maps/RintoVillage/scripts.pory"
	.string "Oh more tourists?\p"
	.string "I hope you don't mind the\n"
	.string "temperature variations! Ho ho ho!$"

Rinto_TempleSage_Text_0:
# 24 "data/maps/RintoVillage/scripts.pory"
	.string "I used to be a member of the Team\n"
	.string "Magma. \p"
	.string "After leaving I decided that I want\n"
	.string "to travel the world as a pilgrim.\p"
	.string "It has been quite refreshing, seeing\n"
	.string "the beauty of the world.$"

Rinto_Gible_Text_0:
# 38 "data/maps/RintoVillage/scripts.pory"
	.string "Gible: Gibgib!$"

Rinto_Maractus_Text_0:
# 48 "data/maps/RintoVillage/scripts.pory"
	.string "Maractus: Maaaai!$"

Rinto_Piplup_Text_0:
# 56 "data/maps/RintoVillage/scripts.pory"
	.string "...The Piplup appears to have dozed off.$"

Rinto_Gentleman_Text_0:
# 65 "data/maps/RintoVillage/scripts.pory"
	.string "Rest let's you restore health and\n"
	.string "keep going. \p"
	.string "Do not push yourself without taking \n"
	.string "the time to heal.$"

Rinto_Gentleman_Text_1:
# 73 "data/maps/RintoVillage/scripts.pory"
	.string "Resting after travelling afar is\n"
	.string "equally important! Do not neglect\l"
	.string "your health even at a young age!\p"
	.string "Take this.$"

Rinto_EastGuard_Text_0:
# 90 "data/maps/RintoVillage/scripts.pory"
	.string "The sandstorms are too intense right\n"
	.string "now. I cannot allow you to pass until\l"
	.string "they calm down.$"

Rinto_LittleGirl_Text_0:
# 113 "data/maps/RintoVillage/scripts.pory"
	.string "I saw it! \p"
	.string "Red and blue!\p"
	.string "They flew over the town to the east!$"

Rinto_Fatman_Text_0:
# 121 "data/maps/RintoVillage/scripts.pory"
	.string "The blazing sun would make this place\n"
	.string "uninhabitable if not for the small\l"
	.string "opening to the sea.$"

Rinto_Dancer_Text_0:
# 128 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 136 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 145 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check out my wares!$"

Rinto_Merchant_Text_1:
# 147 "data/maps/RintoVillage/scripts.pory"
	.string "Come back soon!$"

Rinto_GameboyKid_Text_0:
# 162 "data/maps/RintoVillage/scripts.pory"
	.string "The pyramid in the west has been locked\n"
	.string "up for a long time. \p"
	.string "I wonder if the key to opening \n"
	.string "it even exists anymore?$"
