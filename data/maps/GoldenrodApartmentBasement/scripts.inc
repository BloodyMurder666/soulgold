GoldenrodApartmentBasement_MapScripts::
	.byte 0


RotomMachine_Wash::
# 4 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 5 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	checkspecies SPECIES_ROTOM, OPEN_PARTY_SCREEN
# 7 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Wash_2
RotomMachine_Wash_1:
# 12 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Wash_2:
# 8 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, 0
# 9 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 10 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Wash_1


RotomMachine_Fan::
# 17 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 18 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	checkspecies SPECIES_ROTOM, OPEN_PARTY_SCREEN
# 20 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Fan_2
RotomMachine_Fan_1:
# 25 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Fan_2:
# 21 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, 1
# 22 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 23 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Fan_1


RotomMachine_Fridge::
# 30 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 31 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	checkspecies SPECIES_ROTOM, OPEN_PARTY_SCREEN
# 33 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Fridge_2
RotomMachine_Fridge_1:
# 38 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Fridge_2:
# 34 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, 2
# 35 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 36 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Fridge_1


RotomMachine_Lawnmower::
# 43 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 44 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	checkspecies SPECIES_ROTOM, OPEN_PARTY_SCREEN
# 46 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Lawnmower_2
RotomMachine_Lawnmower_1:
# 51 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Lawnmower_2:
# 47 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, 3
# 48 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 49 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Lawnmower_1


RotomMachine_Oven::
# 56 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	lock
# 57 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	checkspecies SPECIES_ROTOM, OPEN_PARTY_SCREEN
# 59 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomMachine_Oven_2
RotomMachine_Oven_1:
# 64 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	release
	end

RotomMachine_Oven_2:
# 60 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	setvar VAR_0x8000, 4
# 61 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	special ChangeRotomForm
# 62 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	msgbox RotomMachine_Wash_Text_0
	goto RotomMachine_Oven_1


RotomMachine_Wash_Text_0:
# 10 "data/maps/GoldenrodApartmentBasement/scripts.pory"
	.string "Rotom form was changed!$"
