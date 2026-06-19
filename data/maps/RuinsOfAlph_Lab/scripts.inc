# 1 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 2 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_MapScripts::
# 3 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
# 4 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.byte 0
# 5 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 6 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_OnTransition:
# 7 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 8 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 9 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 10 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_Scientist1::
# 11 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	lock
# 12 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	faceplayer
# 13 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_Scientist1, MSGBOX_DEFAULT
# 14 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 15 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 16 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_Scientist2::
# 17 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	lock
# 18 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	faceplayer
# 19 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_Scientist2, MSGBOX_DEFAULT
# 20 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 21 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 22 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_Fossils::
# 23 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	lock
# 24 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_Fossils, MSGBOX_DEFAULT
# 25 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	closemessage
# 26 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 27 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 28 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 29 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_Scientist1:
# 30 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "The Ruins are about 1500 years old.\p"
# 31 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But it's not known why they were\n"
# 32 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "built--or by whom.$"
# 33 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 34 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_Scientist2:
# 35 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "There are odd patterns drawn on\n"
# 36 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "on the walls of the Ruins.\p"
# 37 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "They must be the keys for\n"
# 38 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "unraveling the Ruins' mystery.$"
# 39 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 40 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_Fossils:
# 41 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Fossils found within the Ruins.\n"
# 42 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Maybe there are more somewhere...$"
# 43 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 44 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 45 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FossilScientist::
# 46 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	lock
# 47 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	faceplayer
# 48 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RuinsOfAlph_Lab_EventScript_FossilMonReady
# 49 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RuinsOfAlph_Lab_EventScript_StillRegenerating
# 50 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 51 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 52 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
# 53 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ChooseFossil
# 54 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 55 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveRootFossil::
# 56 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 57 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 58 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 59 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_LileepReady
# 60 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 61 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveClawFossil::
# 62 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 63 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 64 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 65 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_AnorithReady
# 66 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 67 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveHelixFossil::
# 68 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
# 69 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 70 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 71 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_OmanyteReady
# 72 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 73 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveDomeFossil::
# 74 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
# 75 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 76 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 77 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_KabutoReady
# 78 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 79 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveOldAmber::
# 80 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
# 81 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 82 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 83 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_AeroReady
# 84 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 85 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GivePlumeFossil::
# 86 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PLUME_FOSSIL
# 87 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 88 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_PLUME_FOSSIL
# 89 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ArchenReady
# 90 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 91 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveJawFossil::
# 92 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
# 93 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 94 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_JAW_FOSSIL
# 95 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TyruntReady
# 96 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 97 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveSailFossil::
# 98 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SAIL_FOSSIL
# 99 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 100 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	removeitem ITEM_SAIL_FOSSIL
# 101 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_AmauraReady
# 102 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 103 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_DeclineGiveFossil::
# 104 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo, MSGBOX_DEFAULT
# 105 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 106 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 107 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 108 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2::
# 109 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo2, MSGBOX_DEFAULT
# 110 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 111 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 112 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 113 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_StillRegenerating::
# 114 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 115 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 116 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 117 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 118 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FossilMonReady::
# 119 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RuinsOfAlph_Lab_EventScript_LileepReady
# 120 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RuinsOfAlph_Lab_EventScript_AnorithReady
# 121 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RuinsOfAlph_Lab_EventScript_OmanyteReady
# 122 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RuinsOfAlph_Lab_EventScript_KabutoReady
# 123 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RuinsOfAlph_Lab_EventScript_AeroReady
# 124 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 6, RuinsOfAlph_Lab_EventScript_ArchenReady
# 125 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 7, RuinsOfAlph_Lab_EventScript_TyruntReady
# 126 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 8, RuinsOfAlph_Lab_EventScript_AmauraReady
# 127 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 128 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 129 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_LileepReady::
# 130 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 131 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 132 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveLileep
# 133 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 134 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 135 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_AnorithReady::
# 136 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 137 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 138 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveAnorith
# 139 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 140 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 141 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_OmanyteReady::
# 142 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
# 143 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 144 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveOmanyte
# 145 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 146 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 147 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_KabutoReady::
# 148 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
# 149 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 150 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveKabuto
# 151 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 152 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 153 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_AeroReady::
# 154 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
# 155 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 156 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveAero
# 157 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 158 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 159 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ArchenReady::
# 160 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARCHEN
# 161 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_NewFossilReady
# 162 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 163 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TyruntReady::
# 164 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYRUNT
# 165 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_NewFossilReady
# 166 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 167 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_AmauraReady::
# 168 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AMAURA
# 169 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_NewFossilReady
# 170 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 171 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_NewFossilReady::
# 172 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
# 173 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 174 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMon
# 175 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 176 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 177 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveLileep::
# 178 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 179 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 180 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty
# 181 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC
# 182 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 183 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 184 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 185 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveLileepParty::
# 186 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
# 187 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 188 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
# 189 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 190 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 191 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
# 192 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 193 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 194 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveLileepPC::
# 195 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
# 196 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 197 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferLileepToPC
# 198 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 199 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
# 200 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 201 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	
# 202 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferLileepToPC::
# 203 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 204 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
# 205 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 206 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 207 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare::
# 208 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 209 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 210 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 211 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 212 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 213 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 214 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 215 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 216 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingLileep::
# 217 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 218 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 219 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 220 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 221 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 222 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAnorith::
# 223 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 224 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 225 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty
# 226 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC
# 227 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 228 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 229 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 230 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty::
# 231 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
# 232 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 233 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
# 234 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 235 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 236 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
# 237 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 238 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 239 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC::
# 240 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
# 241 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 242 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
# 243 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 244 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
# 245 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 246 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 247 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferAnorithToPC::
# 248 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 249 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
# 250 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 251 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 252 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare::
# 253 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 254 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 255 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 256 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 257 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 258 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 259 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 260 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 261 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith::
# 262 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 263 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 264 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 265 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 266 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 267 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveOmanyte::
# 268 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_OMANYTE
# 269 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_OMANYTE, 20
# 270 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty
# 271 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC
# 272 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 273 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 274 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 275 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty::
# 276 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
# 277 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 278 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
# 279 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 280 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 281 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
# 282 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 283 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 284 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC::
# 285 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
# 286 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 287 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
# 288 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 289 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
# 290 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 291 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	
# 292 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC::
# 293 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 294 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
# 295 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 296 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 297 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare::
# 298 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
# 299 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 300 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 301 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 302 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 303 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 304 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 305 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 306 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte::
# 307 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 308 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 309 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 310 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 311 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 312 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveKabuto::
# 313 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_KABUTO
# 314 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call_if_unset FLAG_GARBAGEFLAG, RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto
# 315 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call_if_set FLAG_GARBAGEFLAG, RuinsOfAlph_Lab_EventScript_GiveLateKabuto
# 316 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty
# 317 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC
# 318 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 319 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 320 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 321 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto::
# 322 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_KABUTO, 5
# 323 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 324 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 325 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_GiveLateKabuto::
# 326 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_KABUTO, 20
# 327 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 328 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 329 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty::
# 330 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
# 331 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 332 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
# 333 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 334 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 335 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
# 336 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 337 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 338 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 339 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC::
# 340 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
# 341 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 342 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
# 343 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 344 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
# 345 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 346 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	
# 347 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferKabutoToPC::
# 348 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 349 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
# 350 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 351 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 352 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare::
# 353 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
# 354 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 355 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 356 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 357 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 358 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 359 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 360 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 361 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto::
# 362 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 363 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 364 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 365 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 366 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 367 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAero::
# 368 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
# 369 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon SPECIES_AERODACTYL, 20
# 370 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty
# 371 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC
# 372 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 373 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 374 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 375 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAeroParty::
# 376 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
# 377 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 378 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAero
# 379 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 380 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 381 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
# 382 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 383 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 384 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveAeroPC::
# 385 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
# 386 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 387 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAeroToPC
# 388 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 389 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
# 390 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 391 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	
# 392 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferAeroToPC::
# 393 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 394 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
# 395 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 396 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 397 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare::
# 398 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
# 399 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 400 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 401 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 402 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 403 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 404 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 405 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 406 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingAero::
# 407 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 408 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 409 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 410 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 411 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 412 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMon::
# 413 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 20
# 414 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMonParty
# 415 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMonPC
# 416 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 417 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 418 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 419 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMonParty::
# 420 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedNewFossilMonFanfare
# 421 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 422 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingNewFossilMon
# 423 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 424 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 425 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingNewFossilMon
# 426 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 427 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 428 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceiveNewFossilMonPC::
# 429 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call RuinsOfAlph_Lab_EventScript_ReceivedNewFossilMonFanfare
# 430 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 431 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferNewFossilMonToPC
# 432 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 433 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_TransferNewFossilMonToPC
# 434 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 435 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 436 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_TransferNewFossilMonToPC::
# 437 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 438 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingNewFossilMon
# 439 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 440 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 441 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ReceivedNewFossilMonFanfare::
# 442 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
# 443 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 444 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
# 445 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitmessage
# 446 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	waitfanfare
# 447 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
# 448 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	return
# 449 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 450 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_FinishReceivingNewFossilMon::
# 451 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 452 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 453 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 454 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 455 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 456 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 457 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseFossil::
# 458 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_PickFossilFromBag, MSGBOX_DEFAULT
# 459 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	chooseitem POCKET_ITEMS
# 460 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	switch VAR_ITEM_ID
# 461 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_NONE, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
# 462 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_DOME_FOSSIL, RuinsOfAlph_Lab_EventScript_GiveDomeFossil
# 463 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_ROOT_FOSSIL, RuinsOfAlph_Lab_EventScript_GiveRootFossil
# 464 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_PLUME_FOSSIL, RuinsOfAlph_Lab_EventScript_GivePlumeFossil
# 465 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_JAW_FOSSIL, RuinsOfAlph_Lab_EventScript_GiveJawFossil
# 466 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_SAIL_FOSSIL, RuinsOfAlph_Lab_EventScript_GiveSailFossil
# 467 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	case ITEM_OLD_AMBER, RuinsOfAlph_Lab_EventScript_GiveOldAmber
# 468 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_ThatsNotAFossil, MSGBOX_DEFAULT
# 469 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto RuinsOfAlph_Lab_EventScript_ChooseFossil
# 470 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 471 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 472 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseClawFossil::
# 473 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 474 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveClawFossil
# 475 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
# 476 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 477 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 478 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseRootFossil::
# 479 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 480 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveRootFossil
# 481 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
# 482 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 483 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 484 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseHelixFossil::
# 485 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	checkitem ITEM_HELIX_FOSSIL
# 486 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveHelixFossil
# 487 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
# 488 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 489 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 490 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseDomeFossil::
# 491 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	checkitem ITEM_DOME_FOSSIL
# 492 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveDomeFossil
# 493 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
# 494 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 495 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 496 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_ChooseOldAmber::
# 497 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	checkitem ITEM_OLD_AMBER
# 498 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveOldAmber
# 499 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
# 500 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 501 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 502 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_CancelFossilSelect::
# 503 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 504 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 505 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 506 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_EventScript_WorkOnNext::
# 507 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	msgbox RuinsOfAlph_Lab_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 508 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	release
# 509 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	end
# 510 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 511 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_DeviceForTalkingToPokemon:
# 512 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "We're developing a device for talking\n"
# 513 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "with Pokémon.\p"
# 514 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But we haven't had much success…$"
# 515 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 516 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_DevelopingNewBalls:
# 517 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I'm developing new kinds of\n"
# 518 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Poké Balls…\p"
# 519 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But I haven't made much headway…$"
# 520 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 521 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_WeFinallyMadeNewBalls:
# 522 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "We finally made new kinds of\n"
# 523 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Poké Balls!\p"
# 524 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "The Repeat Ball makes it easier to\n"
# 525 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "catch Pokémon you've caught before.\p"
# 526 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "The Timer Ball gets better at catching\n"
# 527 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Pokémon the longer a battle runs.\p"
# 528 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Both are proudly developed by\n"
# 529 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "the Devon Corporation.\p"
# 530 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Please give them a try!$"
# 531 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 532 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_IMadePokenav:
# 533 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I made the PokéNav!\p"
# 534 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 535 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "made something so great!$"
# 536 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 537 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_WowThatsAPokenav:
# 538 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Oh, wow!\n"
# 539 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "That's a PokéNav!\p"
# 540 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "It came about as a result of our\n"
# 541 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "President's desire to learn about\l"
# 542 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "the feelings of Pokémon.\p"
# 543 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Would you like me to describe its\n"
# 544 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "features in detail?\p"
# 545 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 546 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "trying the PokéNav out.$"
# 547 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 548 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_DeviceToVisualizePokemonDreams:
# 549 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 550 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 551 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Pokémon…\p"
# 552 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But it's not going well.$"
# 553 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 554 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils:
# 555 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I've been trying to develop a device\n"
# 556 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "that resurrects Pokémon from fossils…\p"
# 557 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "And, it's working!$"
# 558 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 559 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife:
# 560 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Would you like to bring that Pokémon\n"
# 561 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "back to life?\p"
# 562 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I can with my newly developed\n"
# 563 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Fossil Regenerator.$"
# 564 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 565 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_OhIsThatSo:
# 566 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Oh, is that so?\p"
# 567 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "My technological expertise\n"
# 568 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "is outstanding, I tell you.$"
# 569 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 570 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_OhIsThatSo2:
# 571 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Oh, you don't have this fossil.\n"
# 572 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Come back if you manage to find it.$"
# 573 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 574 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_TwoFossilsPickOne:
# 575 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 576 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "You have more than one fossil?\p"
# 577 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 578 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "regenerate one Pokémon at a time.\p"
# 579 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Which fossil would you like to\n"
# 580 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "regenerate?$"
# 581 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 582 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_PickFossilFromBag:
# 583 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Please choose the fossil you'd like\n"
# 584 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "to regenerate.$"
# 585 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 586 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_ThatsNotAFossil:
# 587 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "That's not a fossil!$"
# 588 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 589 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_HandedFossilToResearcher:
# 590 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Excellent!\n"
# 591 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Let's do this right away.\p"
# 592 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 593 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "the Ruins Researcher.$"
# 594 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 595 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime:
# 596 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "The Fossil Regenerator, which I made,\n"
# 597 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "is incredible.\p"
# 598 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 599 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "a long time to work.\p"
# 600 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 601 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "and look around for a while?$"
# 602 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 603 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife:
# 604 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Thanks for waiting!\p"
# 605 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Your fossilized Pokémon has been\n"
# 606 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "brought back to life!\p"
# 607 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "The fossil was an ancient Pokémon.\n"
# 608 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 609 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 610 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher:
# 611 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 612 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "the Researcher.$"
# 613 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 614 "data/maps/RuinsOfAlph_Lab/scripts.pory"
@ Unused
# 615 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_TooManyPokemon:
# 616 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Uh-oh, you've got too many Pokémon.\n"
# 617 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "You have no room for this one.$"
# 618 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 619 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_DevelopNewPokenavFeature:
# 620 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 621 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "for the PokéNav…\p"
# 622 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "But it's not going well.$"
# 623 "data/maps/RuinsOfAlph_Lab/scripts.pory"

# 624 "data/maps/RuinsOfAlph_Lab/scripts.pory"
RuinsOfAlph_Lab_Text_WhatToWorkOnNext:
# 625 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Well, now what shall I work on\n"
# 626 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "developing next?\p"
# 627 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "Our company allows us to make our\n"
# 628 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "inspirations into reality.\p"
# 629 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "One couldn't ask for a better\n"
# 630 "data/maps/RuinsOfAlph_Lab/scripts.pory"
	.string "environment as an engineer.$"
