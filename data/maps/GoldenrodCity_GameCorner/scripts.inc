# 1 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 2 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_MapScripts::
# 3 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	.byte 0
# 4 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 5 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
# 6 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 7 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 8 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 9 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 10 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 11 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
# 12 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 13 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 14 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
# 15 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 16 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 17 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	waitmessage
# 18 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	multichoice 20, 0, MULTI_PRIZE_MONS, FALSE
# 19 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 20 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Pawniard
# 21 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax
# 22 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_SneaselHisui
# 23 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Deino
# 24 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon
# 25 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 26 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case 127, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 27 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 28 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 29 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
# 30 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 31 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 32 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 33 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 34 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 35 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_Pawniard::
# 36 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PAWNIARD
# 37 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_2, 250
# 38 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 39 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 40 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 41 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax::
# 42 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MUNCHLAX
# 43 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_2, 500
# 44 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 45 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 46 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 47 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_SneaselHisui::
# 48 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SNEASEL_HISUI
# 49 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_2, 1200
# 50 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 51 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 52 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 53 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_Deino::
# 54 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_DEINO
# 55 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_2, 2400
# 56 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 57 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 58 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 59 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon::
# 60 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PORYGON
# 61 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_2, 3000
# 62 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 63 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 64 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 65 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
# 66 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 67 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
# 68 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 69 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	checkcoins VAR_RESULT
# 70 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_lt VAR_RESULT, VAR_TEMP_2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
# 71 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 72 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 73 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 74 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_PAWNIARD,     GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePawniard
# 75 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_SNEASEL_HISUI, GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveSneaselHisui
# 76 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_DEINO,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDeino
# 77 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_MUNCHLAX,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax
# 78 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_PORYGON,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon
# 79 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	case SPECIES_PINSIR,   GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir
# 80 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 81 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 82 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePawniard::
# 83 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 84 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 85 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 86 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 87 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveSneaselHisui::
# 88 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 89 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 90 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 91 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 92 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDeino::
# 93 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 94 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 95 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 96 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 97 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax::
# 98 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 99 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 100 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 101 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 102 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
# 103 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 104 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 105 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 106 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 107 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
# 108 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, 15
# 109 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 110 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 111 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 112 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
# 113 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 114 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
# 115 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
# 116 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull
# 117 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 118 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 119 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull::
# 120 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_NoRoomForPokemon
# 121 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 122 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 123 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 124 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 125 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 126 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon::
# 127 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	getpartysize
# 128 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	subvar VAR_RESULT, 1
# 129 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 130 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 131 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 132 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 133 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 134 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 135 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
# 136 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase
# 137 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 138 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 139 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 140 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
# 141 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins
# 142 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 143 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 144 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 145 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
# 146 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	removecoins VAR_TEMP_2
# 147 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 148 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 149 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 150 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 151 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
# 152 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	waitmessage
# 153 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	waitfanfare
# 154 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodGamecorner_Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 155 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon
# 156 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 157 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 158 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 159 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
# 160 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	removecoins VAR_TEMP_2
# 161 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 162 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 163 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 164 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 165 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
# 166 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	waitmessage
# 167 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	waitfanfare
# 168 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
# 169 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 170 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 171 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
# 172 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_TransferredToPC
# 173 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 174 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 175 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 176 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyMon::
# 177 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 178 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 179 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 180 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	
# 181 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_EventScript_PcMon::
# 182 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 183 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_EventScript_SendMon
# 184 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 185 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	goto GoldenrodCity_GameCorner_EventScript_SendMon
# 186 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 187 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 188 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 189 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 190 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 191 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_SendMon::
# 192 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	call Common_EventScript_TransferredToPC
# 193 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 194 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 195 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 196 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 197 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 198 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_PokefanM::
# 199 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 200 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 201 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_PokefanM1, MSGBOX_DEFAULT
# 202 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 203 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 204 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 205 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 206 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_Hiker::
# 207 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 208 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 209 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_MoveTutorInside, MSGBOX_DEFAULT
# 210 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 211 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 212 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 213 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 214 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_Woman::
# 215 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 216 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 217 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_Woman, MSGBOX_DEFAULT
# 218 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 219 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 220 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 221 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 222 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_Gentleman::
# 223 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 224 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 225 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_Gentleman, MSGBOX_DEFAULT
# 226 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 227 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 228 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 229 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 230 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_PokefanF::
# 231 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 232 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 233 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_PokefanF, MSGBOX_DEFAULT
# 234 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 235 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 236 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 237 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 238 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_PokefanM2::
# 239 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 240 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 241 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_PokefanM2, MSGBOX_DEFAULT
# 242 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 243 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 244 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 245 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 246 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_CooltrainerM::
# 247 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 248 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 249 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_CooltrainerM, MSGBOX_DEFAULT
# 250 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 251 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 252 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 253 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 254 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_EventScript_Pharmacist::
# 255 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	lock
# 256 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	faceplayer
# 257 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	msgbox GoldenrodCity_GameCorner_Text_Pharmacist, MSGBOX_DEFAULT
# 258 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	closemessage
# 259 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	release
# 260 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	end
# 261 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 262 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize:
# 263 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	.string "{STR_VAR_1} is what you want?$"
# 264 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 265 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon:
# 266 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	.string "{PLAYER} got {STR_VAR_1}!$"
# 267 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 268 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodGamecorner_Text_GiveNicknameToThisMon:
# 269 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
	.string "Nickname {STR_VAR_1}?$"
# 270 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 271 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorIntro:
# 272 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Welcome!\p"
# 273 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "We exchange your game coins for\n"
# 274 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "fabulous prizes!$"
# 275 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 276 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize:
# 277 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Which prize would you like?$"
# 278 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 279 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo:
# 280 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Here you go!$"
# 281 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 282 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins:
# 283 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Sorry! You need more coins.$"
# 284 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 285 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorNoMoreRoom:
# 286 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Sorry. You can't carry any more.$"
# 287 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 288 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorQuit:
# 289 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Ok. Please save your coins and come\n"
# 290 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "again!$"
# 291 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 292 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase:
# 293 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Oh? You don't have a Coin Case.$"
# 294 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 295 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_Pharmacist:
# 296 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I always play this slot machine.\n"
# 297 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "It pays out more than others,\l"
# 298 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I think.$"
# 299 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 300 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_Woman:
# 301 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I can't stop winning!$"
# 302 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 303 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PokefanM1:
# 304 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I just love this new slot machine.\p"
# 305 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "It's more of a challenge than the\n"
# 306 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "ones in Celadon.$"
# 307 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 308 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_CooltrainerM:
# 309 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Life is a gamble. I'm going to pull\n"
# 310 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "till I drop!$"
# 311 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 312 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PokefanF:
# 313 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Roulette…\p"
# 314 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I prefer it over the slots because\n"
# 315 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "it's easier to figure the odds.\p"
# 316 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "But the payout is much lower.$"
# 317 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 318 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_CooltrainerF:
# 319 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I won't quit until I win!$"
# 320 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 321 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_Gentleman:
# 322 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I taught Blizzard to my POKéMON.\p"
# 323 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "It was hard to get enough coins for\n"
# 324 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "it, but it was worth it.$"
# 325 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 326 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_PokefanM2:
# 327 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I couldn't win at the slots, and I\n"
# 328 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "blew it on roulette.\p"
# 329 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "I got so furious, I tossed out my\n"
# 330 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Coin Case in the Underground.$"
# 331 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 332 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_MoveTutorInside:
# 333 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Wahahah! The coins keep rolling in!$"
# 334 "data/maps/GoldenrodCity_GameCorner/scripts.pory"

# 335 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
GoldenrodCity_GameCorner_Text_LeftTheirDrink:
# 336 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "Someone left their drink.\p"
# 337 "data/maps/GoldenrodCity_GameCorner/scripts.pory"
    .string "It smells sweet.$"
