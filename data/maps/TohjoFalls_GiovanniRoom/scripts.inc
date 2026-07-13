# 1 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"

# 2 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
TohjoFalls_GiovanniRoom_MapScripts::
# 3 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	.byte 0

TohjoPassGuard::
# 8 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	lock
# 9 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	faceplayer
# 10 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	playmoncry SPECIES_RHYPERIOR, CRY_MODE_NORMAL
# 11 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	msgbox TohjoPassGuard_Text_0
# 12 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	waitmoncry
# 13 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	msgbox TohjoPassGuard_Text_1
# 17 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	release
	end


TohjoPassGuard_Text_0:
# 11 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	.string "Rhyperior: Grr...$"

TohjoPassGuard_Text_1:
# 13 "data/maps/TohjoFalls_GiovanniRoom/scripts.pory"
	.string "The Rhyperior is guarding the entrance\n"
	.string "with a menacing presence.\p"
	.string "You decide to come back another time.$"
