MtEmber_Summit_Frlg_MapScripts::
	.byte 0


MtEmber_Summit_EventScript_ShowMoltres::
	clearflag FLAG_HIDE_MOLTRES
	return

MtEmber_Summit_EventScript_Moltres::
	lock
	faceplayer
	release
	end

