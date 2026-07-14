TohjoPass_MapScripts::
	.byte 0


TohjoPass_Floette::
# 4 "data/maps/TohjoPass/scripts.pory"
	lock
# 5 "data/maps/TohjoPass/scripts.pory"
	faceplayer
# 6 "data/maps/TohjoPass/scripts.pory"
	playmoncry SPECIES_FLOETTE, CRY_MODE_NORMAL
# 7 "data/maps/TohjoPass/scripts.pory"
	msgbox TohjoPass_Floette_Text_0
# 8 "data/maps/TohjoPass/scripts.pory"
	waitmoncry
# 9 "data/maps/TohjoPass/scripts.pory"
	release
	end


TohjoPass_Floette_Text_0:
# 7 "data/maps/TohjoPass/scripts.pory"
	.string "Floette: Floweeeeey!$"
