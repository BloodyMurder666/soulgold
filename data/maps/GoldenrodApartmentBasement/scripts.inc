GoldenrodApartmentBasement_MapScripts::
	.byte 0


RotomMachine_Wash::
# 4 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 5 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChoosePartyMon
# 6 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	waitstate
# 7 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 8 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, MOVE_HYDRO_PUMP
# 9 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 11 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Wash_2
RotomMachine_Wash_1:
# 14 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Wash_2:
# 12 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Wash_1


RotomMachine_Fan::
# 19 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 20 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChoosePartyMon
# 21 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	waitstate
# 22 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 23 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, MOVE_AIR_SLASH
# 24 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 26 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Fan_2
RotomMachine_Fan_1:
# 29 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Fan_2:
# 27 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Fan_1


RotomMachine_Fridge::
# 34 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 35 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChoosePartyMon
# 36 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	waitstate
# 37 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 38 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, MOVE_BLIZZARD
# 39 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 41 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Fridge_2
RotomMachine_Fridge_1:
# 44 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Fridge_2:
# 42 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Fridge_1


RotomMachine_Lawnmower::
# 49 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 50 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChoosePartyMon
# 51 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	waitstate
# 52 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 53 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, MOVE_LEAF_STORM
# 54 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 56 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Lawnmower_2
RotomMachine_Lawnmower_1:
# 59 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Lawnmower_2:
# 57 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Lawnmower_1


RotomMachine_Oven::
# 64 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 65 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChoosePartyMon
# 66 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	waitstate
# 67 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 68 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, MOVE_OVERHEAT
# 69 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 71 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Oven_2
RotomMachine_Oven_1:
# 74 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Oven_2:
# 72 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Oven_1


RotomMachine_Wash_Text_0:
# 12 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	.string "Rotom form was changed!$"
