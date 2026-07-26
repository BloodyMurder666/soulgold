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


Rinto_OldLady::
# 12 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_OldLady_Text_0, MSGBOX_NPC
	return


Rinto_TempleSage::
# 19 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_TempleSage_Text_0, MSGBOX_NPC
	return


Rinto_Gible::
# 30 "data/maps/RintoVillage/scripts.pory"
	lock
# 31 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 32 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_GIBLE, CRY_MODE_NORMAL
# 33 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gible_Text_0
# 34 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 35 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Maractus::
# 40 "data/maps/RintoVillage/scripts.pory"
	lock
# 41 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 42 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_MARACTUS, CRY_MODE_NORMAL
# 43 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Maractus_Text_0
# 44 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 45 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Piplup::
# 50 "data/maps/RintoVillage/scripts.pory"
	lock
# 51 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Piplup_Text_0
# 52 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Gentleman::
# 57 "data/maps/RintoVillage/scripts.pory"
	lock
# 58 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 59 "data/maps/RintoVillage/scripts.pory"
	goto_if_set FLAG_GOT_TM_REST, Rinto_Gentleman_2
# 68 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_1
# 73 "data/maps/RintoVillage/scripts.pory"
	giveitem ITEM_TM_REST
# 74 "data/maps/RintoVillage/scripts.pory"
	setflag FLAG_GOT_TM_REST
# 75 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 80 "data/maps/RintoVillage/scripts.pory"
	release
	end

Rinto_Gentleman_2:
# 60 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Gentleman_Text_0
# 65 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_EastGuard::
# 85 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0, MSGBOX_NPC
	return


Rinto_TriggerEastGuard::
# 91 "data/maps/RintoVillage/scripts.pory"
	lock
# 92 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_RINTO_EAST_GUARD, Rinto_TriggerEastGuard_Movement_0
# 93 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 94 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_1
# 95 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 96 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_EastGuard_Text_0
# 99 "data/maps/RintoVillage/scripts.pory"
	closemessage
# 100 "data/maps/RintoVillage/scripts.pory"
	applymovement LOCALID_PLAYER, Rinto_TriggerEastGuard_Movement_2
# 101 "data/maps/RintoVillage/scripts.pory"
	waitmovement
# 102 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_LittleGirl::
# 108 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_LittleGirl_Text_0, MSGBOX_NPC
	return


Rinto_Fatman::
# 116 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Fatman_Text_0, MSGBOX_NPC
	return


Rinto_Dancer::
# 122 "data/maps/RintoVillage/scripts.pory"
	lock
# 123 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Dancer_Text_0
# 124 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_DancerOricorio::
# 129 "data/maps/RintoVillage/scripts.pory"
	lock
# 130 "data/maps/RintoVillage/scripts.pory"
	playmoncry SPECIES_ORICORIO_SENSU, CRY_MODE_NORMAL
# 131 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_DancerOricorio_Text_0
# 132 "data/maps/RintoVillage/scripts.pory"
	waitmoncry
# 133 "data/maps/RintoVillage/scripts.pory"
	release
	end


Rinto_Merchant::
# 138 "data/maps/RintoVillage/scripts.pory"
	lock
# 139 "data/maps/RintoVillage/scripts.pory"
	faceplayer
# 140 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_0
# 141 "data/maps/RintoVillage/scripts.pory"
	pokemart Rinto_Stall
# 142 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_Merchant_Text_1
# 143 "data/maps/RintoVillage/scripts.pory"
	release
	end


	.align 2
# 147 "data/maps/RintoVillage/scripts.pory"
Rinto_Stall:
# 148 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_RING_TARGET
# 149 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_BINDING_BAND
# 150 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 151 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WIDE_LENS
# 152 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_WISE_GLASSES
# 153 "data/maps/RintoVillage/scripts.pory"
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_NONE

Rinto_GameboyKid::
# 157 "data/maps/RintoVillage/scripts.pory"
	msgbox Rinto_GameboyKid_Text_0, MSGBOX_NPC
	return


# 92 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_0:
# 92 "data/maps/RintoVillage/scripts.pory"
	walk_in_place_down
	step_end

# 94 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_1:
# 94 "data/maps/RintoVillage/scripts.pory"
	face_up
	step_end

# 100 "data/maps/RintoVillage/scripts.pory"
Rinto_TriggerEastGuard_Movement_2:
# 100 "data/maps/RintoVillage/scripts.pory"
	walk_left
	step_end

Rinto_OldLady_Text_0:
# 12 "data/maps/RintoVillage/scripts.pory"
	.string "Oh more tourists?\p"
	.string "I hope you don't mind the\n"
	.string "temperature variations! Ho ho ho!$"

Rinto_TempleSage_Text_0:
# 19 "data/maps/RintoVillage/scripts.pory"
	.string "I used to be a member of the Team\n"
	.string "Magma. \p"
	.string "After leaving I decided that I want\n"
	.string "to travel the world as a pilgrim.\p"
	.string "It has been quite refreshing, seeing\n"
	.string "the beauty of the world.$"

Rinto_Gible_Text_0:
# 33 "data/maps/RintoVillage/scripts.pory"
	.string "Gible: Gibgib!$"

Rinto_Maractus_Text_0:
# 43 "data/maps/RintoVillage/scripts.pory"
	.string "Maractus: Maaaai!$"

Rinto_Piplup_Text_0:
# 51 "data/maps/RintoVillage/scripts.pory"
	.string "...The Piplup appears to have dozed off.$"

Rinto_Gentleman_Text_0:
# 60 "data/maps/RintoVillage/scripts.pory"
	.string "Rest let's you restore health and\n"
	.string "keep going. \p"
	.string "Do not push yourself without taking \n"
	.string "the time to heal.$"

Rinto_Gentleman_Text_1:
# 68 "data/maps/RintoVillage/scripts.pory"
	.string "Resting after travelling afar is\n"
	.string "equally important! Do not neglect\l"
	.string "your health even at a young age!\p"
	.string "Take this.$"

Rinto_EastGuard_Text_0:
# 85 "data/maps/RintoVillage/scripts.pory"
	.string "The sandstorms are too intense right\n"
	.string "now. I cannot allow you to pass until\l"
	.string "they calm down.$"

Rinto_LittleGirl_Text_0:
# 108 "data/maps/RintoVillage/scripts.pory"
	.string "I saw it! \p"
	.string "Red and blue!\p"
	.string "They flew over the town to the east!$"

Rinto_Fatman_Text_0:
# 116 "data/maps/RintoVillage/scripts.pory"
	.string "The blazing sun would make this place\n"
	.string "uninhabitable if not for the small\l"
	.string "opening to the sea.$"

Rinto_Dancer_Text_0:
# 123 "data/maps/RintoVillage/scripts.pory"
	.string "Let's go Oricorio, show them our moves!$"

Rinto_DancerOricorio_Text_0:
# 131 "data/maps/RintoVillage/scripts.pory"
	.string "Oriiii!$"

Rinto_Merchant_Text_0:
# 140 "data/maps/RintoVillage/scripts.pory"
	.string "Hey check out my wares!$"

Rinto_Merchant_Text_1:
# 142 "data/maps/RintoVillage/scripts.pory"
	.string "Come back soon!$"

Rinto_GameboyKid_Text_0:
# 157 "data/maps/RintoVillage/scripts.pory"
	.string "The pyramid in the west has been locked\n"
	.string "up for a long time. \p"
	.string "I wonder if the key to opening \n"
	.string "it even exists anymore?$"
