MtSilver_1F_RegigigasRoom_MapScripts::
	.byte 0


MtSilver_Regigigas::
# 4 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	lock
# 5 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	checkspecies SPECIES_REGISTEEL
# 6 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_2
# 27 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	goto RegigigasSlumbers
MtSilver_Regigigas_1:
# 29 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	release
	end

MtSilver_Regigigas_2:
# 7 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	checkspecies SPECIES_REGIROCK
# 8 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_5
# 24 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	goto RegigigasSlumbers
	goto MtSilver_Regigigas_1

MtSilver_Regigigas_5:
# 9 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	checkspecies SPECIES_REGICE
# 10 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_8
# 21 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	goto RegigigasSlumbers
	goto MtSilver_Regigigas_1

MtSilver_Regigigas_8:
# 11 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	msgbox MtSilver_Regigigas_Text_0
# 17 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	legendaryencounter SPECIES_REGIGIGAS, 70, LOCALID_MTSILVER_REGIGIGAS, FLAG_HIDE_REGIGIGAS
# 18 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	release
	end


RegigigasSlumbers::
# 35 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	msgbox RegigigasSlumbers_Text_0
# 41 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	release
	end


MtSilver_Regigigas_Text_0:
# 11 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	.string "...!\p"
	.string "The statue suddenly started moving\n"
	.string "in reaction to your Pokémon!\p"
	.string "The statue attacked!$"

RegigigasSlumbers_Text_0:
# 35 "data/maps/MtSilver_1F_RegigigasRoom/scripts.pory"
	.string "A large, almost statue-like Pokémon\n"
	.string "seems to be resting here.\p"
	.string "...\p"
	.string "It does not react to your presence.$"
