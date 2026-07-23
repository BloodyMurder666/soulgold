RintoHouse2_MapScripts::
	.byte 0


RintoHouse2_BottleCapManiac::
# 4 "data/maps/RintoHouse2/scripts.pory"
	lock
# 5 "data/maps/RintoHouse2/scripts.pory"
	faceplayer
# 6 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_Text_0, MSGBOX_YESNO
# 16 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_2
RintoHouse2_BottleCapManiac_1:
# 19 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseMon
	return

RintoHouse2_BottleCapManiac_2:
# 17 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_Goodbye
	goto RintoHouse2_BottleCapManiac_1


RintoHouse2_BottleCapManiac_ChooseMon::
# 23 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseMon_Text_0
# 25 "data/maps/RintoHouse2/scripts.pory"
	special ChoosePartyMon
# 26 "data/maps/RintoHouse2/scripts.pory"
	waitstate
# 27 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge RintoHouse2_BottleCapManiac_ChooseMon_2
RintoHouse2_BottleCapManiac_ChooseMon_1:
# 31 "data/maps/RintoHouse2/scripts.pory"
	special IsSelectedMonEgg
# 32 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_5
RintoHouse2_BottleCapManiac_ChooseMon_4:
# 38 "data/maps/RintoHouse2/scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_0x8004
# 39 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, FALSE
# 40 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_HP, VAR_0x8004
# 41 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_8
RintoHouse2_BottleCapManiac_ChooseMon_7:
# 44 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_ATK, VAR_0x8004
# 45 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_11
RintoHouse2_BottleCapManiac_ChooseMon_10:
# 48 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_DEF, VAR_0x8004
# 49 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_14
RintoHouse2_BottleCapManiac_ChooseMon_13:
# 52 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPEED, VAR_0x8004
# 53 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_17
RintoHouse2_BottleCapManiac_ChooseMon_16:
# 56 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPATK, VAR_0x8004
# 57 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_20
RintoHouse2_BottleCapManiac_ChooseMon_19:
# 60 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPDEF, VAR_0x8004
# 61 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_23
RintoHouse2_BottleCapManiac_ChooseMon_22:
# 64 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_0x8005, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseMon_26
RintoHouse2_BottleCapManiac_ChooseMon_25:
# 70 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseCap
	return

RintoHouse2_BottleCapManiac_ChooseMon_2:
# 28 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_Goodbye
	goto RintoHouse2_BottleCapManiac_ChooseMon_1

RintoHouse2_BottleCapManiac_ChooseMon_5:
# 33 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseMon_Text_1
# 35 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseMon
	goto RintoHouse2_BottleCapManiac_ChooseMon_4

RintoHouse2_BottleCapManiac_ChooseMon_8:
# 42 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_7

RintoHouse2_BottleCapManiac_ChooseMon_11:
# 46 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_10

RintoHouse2_BottleCapManiac_ChooseMon_14:
# 50 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_13

RintoHouse2_BottleCapManiac_ChooseMon_17:
# 54 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_16

RintoHouse2_BottleCapManiac_ChooseMon_20:
# 58 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_19

RintoHouse2_BottleCapManiac_ChooseMon_23:
# 62 "data/maps/RintoHouse2/scripts.pory"
	setvar VAR_0x8005, TRUE
	goto RintoHouse2_BottleCapManiac_ChooseMon_22

RintoHouse2_BottleCapManiac_ChooseMon_26:
# 65 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseMon_Text_2
# 68 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseMon
	goto RintoHouse2_BottleCapManiac_ChooseMon_25


RintoHouse2_BottleCapManiac_ChooseCap::
# 74 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseCap_Text_0
# 76 "data/maps/RintoHouse2/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, RintoHouse2_BottleCapManiac_ChooseCap_Text_1, RintoHouse2_BottleCapManiac_ChooseCap_Text_2, RintoHouse2_BottleCapManiac_ChooseCap_Text_3, RintoHouse2_BottleCapManiac_ChooseCap_Text_4
# 81 "data/maps/RintoHouse2/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/RintoHouse2/scripts.pory"
	case 0, RintoHouse2_BottleCapManiac_ChooseCap_2
# 89 "data/maps/RintoHouse2/scripts.pory"
	case 1, RintoHouse2_BottleCapManiac_ChooseCap_3
# 127 "data/maps/RintoHouse2/scripts.pory"
	case 2, RintoHouse2_BottleCapManiac_ChooseCap_4
# 130 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_Goodbye
	return

RintoHouse2_BottleCapManiac_ChooseCap_2:
	checkitem ITEM_BOTTLE_CAP
# 0 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_7
RintoHouse2_BottleCapManiac_ChooseCap_6:
# 88 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	return

RintoHouse2_BottleCapManiac_ChooseCap_3:
	checkitem ITEM_GOLD_BOTTLE_CAP
# 0 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_10
RintoHouse2_BottleCapManiac_ChooseCap_9:
# 95 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseCap_Text_7, MSGBOX_YESNO
# 98 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_13
RintoHouse2_BottleCapManiac_ChooseCap_12:
# 101 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP, 1
# 102 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_HP, VAR_0x8004
# 103 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_16
RintoHouse2_BottleCapManiac_ChooseCap_15:
# 106 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_ATK, VAR_0x8004
# 107 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_19
RintoHouse2_BottleCapManiac_ChooseCap_18:
# 110 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_DEF, VAR_0x8004
# 111 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_22
RintoHouse2_BottleCapManiac_ChooseCap_21:
# 114 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPEED, VAR_0x8004
# 115 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_25
RintoHouse2_BottleCapManiac_ChooseCap_24:
# 118 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPATK, VAR_0x8004
# 119 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_28
RintoHouse2_BottleCapManiac_ChooseCap_27:
# 122 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPDEF, VAR_0x8004
# 123 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseCap_31
RintoHouse2_BottleCapManiac_ChooseCap_30:
# 126 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ChooseCap_4:
# 128 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseMon
	return

RintoHouse2_BottleCapManiac_ChooseCap_7:
# 84 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseCap_Text_5
# 86 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseCap
	goto RintoHouse2_BottleCapManiac_ChooseCap_6

RintoHouse2_BottleCapManiac_ChooseCap_10:
# 91 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseCap_Text_6
# 93 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseCap
	goto RintoHouse2_BottleCapManiac_ChooseCap_9

RintoHouse2_BottleCapManiac_ChooseCap_13:
# 99 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseCap
	goto RintoHouse2_BottleCapManiac_ChooseCap_12

RintoHouse2_BottleCapManiac_ChooseCap_16:
# 104 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_15

RintoHouse2_BottleCapManiac_ChooseCap_19:
# 108 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_18

RintoHouse2_BottleCapManiac_ChooseCap_22:
# 112 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_21

RintoHouse2_BottleCapManiac_ChooseCap_25:
# 116 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_24

RintoHouse2_BottleCapManiac_ChooseCap_28:
# 120 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_27

RintoHouse2_BottleCapManiac_ChooseCap_31:
# 124 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
	goto RintoHouse2_BottleCapManiac_ChooseCap_30


RintoHouse2_BottleCapManiac_ChooseStat::
# 135 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ChooseStat_Text_0
# 137 "data/maps/RintoHouse2/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, RintoHouse2_BottleCapManiac_ChooseStat_Text_1, RintoHouse2_BottleCapManiac_ChooseStat_Text_2, RintoHouse2_BottleCapManiac_ChooseStat_Text_3, RintoHouse2_BottleCapManiac_ChooseStat_Text_4, RintoHouse2_BottleCapManiac_ChooseStat_Text_5, RintoHouse2_BottleCapManiac_ChooseStat_Text_6, RintoHouse2_BottleCapManiac_ChooseStat_Text_7
# 145 "data/maps/RintoHouse2/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/RintoHouse2/scripts.pory"
	case 0, RintoHouse2_BottleCapManiac_ChooseStat_2
# 152 "data/maps/RintoHouse2/scripts.pory"
	case 1, RintoHouse2_BottleCapManiac_ChooseStat_3
# 158 "data/maps/RintoHouse2/scripts.pory"
	case 2, RintoHouse2_BottleCapManiac_ChooseStat_4
# 164 "data/maps/RintoHouse2/scripts.pory"
	case 3, RintoHouse2_BottleCapManiac_ChooseStat_5
# 170 "data/maps/RintoHouse2/scripts.pory"
	case 4, RintoHouse2_BottleCapManiac_ChooseStat_6
# 176 "data/maps/RintoHouse2/scripts.pory"
	case 5, RintoHouse2_BottleCapManiac_ChooseStat_7
# 183 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseCap
	return

RintoHouse2_BottleCapManiac_ChooseStat_2:
# 147 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_HP, VAR_0x8004
# 148 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_10
RintoHouse2_BottleCapManiac_ChooseStat_9:
# 151 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmHP
	return

RintoHouse2_BottleCapManiac_ChooseStat_3:
# 153 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_ATK, VAR_0x8004
# 154 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_13
RintoHouse2_BottleCapManiac_ChooseStat_12:
# 157 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmAttack
	return

RintoHouse2_BottleCapManiac_ChooseStat_4:
# 159 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_DEF, VAR_0x8004
# 160 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_16
RintoHouse2_BottleCapManiac_ChooseStat_15:
# 163 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmDefense
	return

RintoHouse2_BottleCapManiac_ChooseStat_5:
# 165 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPATK, VAR_0x8004
# 166 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_19
RintoHouse2_BottleCapManiac_ChooseStat_18:
# 169 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmSpAttack
	return

RintoHouse2_BottleCapManiac_ChooseStat_6:
# 171 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPDEF, VAR_0x8004
# 172 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_22
RintoHouse2_BottleCapManiac_ChooseStat_21:
# 175 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmSpDefense
	return

RintoHouse2_BottleCapManiac_ChooseStat_7:
# 177 "data/maps/RintoHouse2/scripts.pory"
	canhypertrain STAT_SPEED, VAR_0x8004
# 178 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RintoHouse2_BottleCapManiac_ChooseStat_25
RintoHouse2_BottleCapManiac_ChooseStat_24:
# 181 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ConfirmSpeed
	return

RintoHouse2_BottleCapManiac_ChooseStat_10:
# 149 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_9

RintoHouse2_BottleCapManiac_ChooseStat_13:
# 155 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_12

RintoHouse2_BottleCapManiac_ChooseStat_16:
# 161 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_15

RintoHouse2_BottleCapManiac_ChooseStat_19:
# 167 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_18

RintoHouse2_BottleCapManiac_ChooseStat_22:
# 173 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_21

RintoHouse2_BottleCapManiac_ChooseStat_25:
# 179 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_StatAlreadyMaxed
	goto RintoHouse2_BottleCapManiac_ChooseStat_24


RintoHouse2_BottleCapManiac_StatAlreadyMaxed::
# 188 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_StatAlreadyMaxed_Text_0
# 190 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	return


RintoHouse2_BottleCapManiac_ConfirmHP::
# 194 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmHP_Text_0, MSGBOX_YESNO
# 196 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmHP_2
RintoHouse2_BottleCapManiac_ConfirmHP_1:
# 199 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 200 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 201 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmHP_2:
# 197 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmHP_1


RintoHouse2_BottleCapManiac_ConfirmAttack::
# 205 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmAttack_Text_0, MSGBOX_YESNO
# 207 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmAttack_2
RintoHouse2_BottleCapManiac_ConfirmAttack_1:
# 210 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 211 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 212 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmAttack_2:
# 208 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmAttack_1


RintoHouse2_BottleCapManiac_ConfirmDefense::
# 216 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmDefense_Text_0, MSGBOX_YESNO
# 218 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmDefense_2
RintoHouse2_BottleCapManiac_ConfirmDefense_1:
# 221 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 222 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 223 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmDefense_2:
# 219 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmDefense_1


RintoHouse2_BottleCapManiac_ConfirmSpAttack::
# 227 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmSpAttack_Text_0, MSGBOX_YESNO
# 229 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmSpAttack_2
RintoHouse2_BottleCapManiac_ConfirmSpAttack_1:
# 232 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 233 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 234 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmSpAttack_2:
# 230 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmSpAttack_1


RintoHouse2_BottleCapManiac_ConfirmSpDefense::
# 238 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmSpDefense_Text_0, MSGBOX_YESNO
# 240 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmSpDefense_2
RintoHouse2_BottleCapManiac_ConfirmSpDefense_1:
# 243 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 244 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 245 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmSpDefense_2:
# 241 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmSpDefense_1


RintoHouse2_BottleCapManiac_ConfirmSpeed::
# 249 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_ConfirmSpeed_Text_0, MSGBOX_YESNO
# 251 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RintoHouse2_BottleCapManiac_ConfirmSpeed_2
RintoHouse2_BottleCapManiac_ConfirmSpeed_1:
# 254 "data/maps/RintoHouse2/scripts.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 255 "data/maps/RintoHouse2/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 256 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_TrainingDone
	return

RintoHouse2_BottleCapManiac_ConfirmSpeed_2:
# 252 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseStat
	goto RintoHouse2_BottleCapManiac_ConfirmSpeed_1


RintoHouse2_BottleCapManiac_TrainingDone::
# 260 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_TrainingDone_Text_0
# 262 "data/maps/RintoHouse2/scripts.pory"
	closemessage
# 263 "data/maps/RintoHouse2/scripts.pory"
	fadescreen FADE_TO_BLACK
# 264 "data/maps/RintoHouse2/scripts.pory"
	delay 30
# 265 "data/maps/RintoHouse2/scripts.pory"
	playse SE_EXP_MAX
# 266 "data/maps/RintoHouse2/scripts.pory"
	waitse
# 267 "data/maps/RintoHouse2/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 268 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_TrainingDone_Text_1, MSGBOX_YESNO
# 273 "data/maps/RintoHouse2/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RintoHouse2_BottleCapManiac_TrainingDone_2
RintoHouse2_BottleCapManiac_TrainingDone_1:
# 276 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_Goodbye
	return

RintoHouse2_BottleCapManiac_TrainingDone_2:
# 274 "data/maps/RintoHouse2/scripts.pory"
	goto RintoHouse2_BottleCapManiac_ChooseMon
	goto RintoHouse2_BottleCapManiac_TrainingDone_1


RintoHouse2_BottleCapManiac_Goodbye::
# 280 "data/maps/RintoHouse2/scripts.pory"
	createfieldmugshot MUGSHOT_GENTLEMAN
# 281 "data/maps/RintoHouse2/scripts.pory"
	msgbox RintoHouse2_BottleCapManiac_Goodbye_Text_0
# 283 "data/maps/RintoHouse2/scripts.pory"
	release
	end


RintoHouse2_BottleCapManiac_Text_0:
# 6 "data/maps/RintoHouse2/scripts.pory"
	.string "The name's Mr. Hyper!\p"
	.string "I can put your Pokémon through my\n"
	.string "amazing Hyper Training!\p"
	.string "A Bottle Cap trains one stat, while a\n"
	.string "Gold Bottle Cap trains every stat.\p"
	.string "Want to get your Pokémon hyped up?$"

RintoHouse2_BottleCapManiac_ChooseMon_Text_0:
# 23 "data/maps/RintoHouse2/scripts.pory"
	.string "Which one of your Pokémon wants some\n"
	.string "Hyper Training?$"

RintoHouse2_BottleCapManiac_ChooseMon_Text_1:
# 33 "data/maps/RintoHouse2/scripts.pory"
	.string "An Egg?! I admire the enthusiasm,\n"
	.string "but I can't train that just yet!$"

RintoHouse2_BottleCapManiac_ChooseMon_Text_2:
# 65 "data/maps/RintoHouse2/scripts.pory"
	.string "But {STR_VAR_1} is already so\n"
	.string "awesome that it doesn't need any\l"
	.string "training!$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_0:
# 74 "data/maps/RintoHouse2/scripts.pory"
	.string "So, will it be a Bottle Cap or a\n"
	.string "Gold Bottle Cap?$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_1:
# 77 "data/maps/RintoHouse2/scripts.pory"
	.string "Bottle Cap$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_2:
# 78 "data/maps/RintoHouse2/scripts.pory"
	.string "Gold Bottle Cap$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_3:
# 79 "data/maps/RintoHouse2/scripts.pory"
	.string "Choose another Pokémon$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_4:
# 80 "data/maps/RintoHouse2/scripts.pory"
	.string "Cancel$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_5:
# 84 "data/maps/RintoHouse2/scripts.pory"
	.string "Oh no! You don't have a\n"
	.string "Bottle Cap!$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_6:
# 91 "data/maps/RintoHouse2/scripts.pory"
	.string "Oh no! You don't have a\n"
	.string "Gold Bottle Cap!$"

RintoHouse2_BottleCapManiac_ChooseCap_Text_7:
# 95 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Gold Bottle Cap to\n"
	.string "train all of {STR_VAR_1}'s stats?$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_0:
# 135 "data/maps/RintoHouse2/scripts.pory"
	.string "Which one of {STR_VAR_1}'s stats\n"
	.string "should I train?$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_1:
# 138 "data/maps/RintoHouse2/scripts.pory"
	.string "HP$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_2:
# 139 "data/maps/RintoHouse2/scripts.pory"
	.string "Attack$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_3:
# 140 "data/maps/RintoHouse2/scripts.pory"
	.string "Defense$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_4:
# 141 "data/maps/RintoHouse2/scripts.pory"
	.string "Sp. Atk$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_5:
# 142 "data/maps/RintoHouse2/scripts.pory"
	.string "Sp. Def$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_6:
# 143 "data/maps/RintoHouse2/scripts.pory"
	.string "Speed$"

RintoHouse2_BottleCapManiac_ChooseStat_Text_7:
# 144 "data/maps/RintoHouse2/scripts.pory"
	.string "Go back$"

RintoHouse2_BottleCapManiac_StatAlreadyMaxed_Text_0:
# 188 "data/maps/RintoHouse2/scripts.pory"
	.string "That stat can't get any more hyper!\n"
	.string "It's already as high as it can get!$"

RintoHouse2_BottleCapManiac_ConfirmHP_Text_0:
# 194 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s HP?$"

RintoHouse2_BottleCapManiac_ConfirmAttack_Text_0:
# 205 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s Attack?$"

RintoHouse2_BottleCapManiac_ConfirmDefense_Text_0:
# 216 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s Defense?$"

RintoHouse2_BottleCapManiac_ConfirmSpAttack_Text_0:
# 227 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s Sp. Atk?$"

RintoHouse2_BottleCapManiac_ConfirmSpDefense_Text_0:
# 238 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s Sp. Def?$"

RintoHouse2_BottleCapManiac_ConfirmSpeed_Text_0:
# 249 "data/maps/RintoHouse2/scripts.pory"
	.string "Exchange a Bottle Cap to train\n"
	.string "{STR_VAR_1}'s Speed?$"

RintoHouse2_BottleCapManiac_TrainingDone_Text_0:
# 260 "data/maps/RintoHouse2/scripts.pory"
	.string "Then get hyped! It's time for some\n"
	.string "real Hyper Training!$"

RintoHouse2_BottleCapManiac_TrainingDone_Text_1:
# 268 "data/maps/RintoHouse2/scripts.pory"
	.string "{STR_VAR_1} grew stronger thanks\n"
	.string "to Hyper Training!\p"
	.string "Want to keep the hype rolling?$"

RintoHouse2_BottleCapManiac_Goodbye_Text_0:
# 281 "data/maps/RintoHouse2/scripts.pory"
	.string "Come back anytime! I'll always be\n"
	.string "hyped to see you!$"
