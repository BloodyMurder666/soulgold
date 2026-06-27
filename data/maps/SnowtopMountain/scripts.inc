SnowtopMountain_MapScripts::
	.byte 0


SnowtopMountain_Sage::
# 4 "data/maps/SnowtopMountain/scripts.pory"
	lock
# 5 "data/maps/SnowtopMountain/scripts.pory"
	faceplayer
# 6 "data/maps/SnowtopMountain/scripts.pory"
	msgbox SnowtopMountain_Sage_Text_0
# 10 "data/maps/SnowtopMountain/scripts.pory"
	msgbox SnowtopMountain_Sage_Text_1
# 11 "data/maps/SnowtopMountain/scripts.pory"
	release
	end


SnowtopMountain_Slowking::
# 16 "data/maps/SnowtopMountain/scripts.pory"
	lock
# 17 "data/maps/SnowtopMountain/scripts.pory"
	faceplayer
# 18 "data/maps/SnowtopMountain/scripts.pory"
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
# 19 "data/maps/SnowtopMountain/scripts.pory"
	msgbox SnowtopMountain_Slowking_Text_0
# 20 "data/maps/SnowtopMountain/scripts.pory"
	waitmoncry
# 21 "data/maps/SnowtopMountain/scripts.pory"
	release
	end


SnowtopMountain_Sage_Text_0:
# 6 "data/maps/SnowtopMountain/scripts.pory"
	.string "Only those who have proven themself to\n"
	.string "be more than just the region's \l"
	.string "champion may proceed past \l"
	.string "here.$"

SnowtopMountain_Sage_Text_1:
# 10 "data/maps/SnowtopMountain/scripts.pory"
	.string "...You are not worthy yet.$"

SnowtopMountain_Slowking_Text_0:
# 19 "data/maps/SnowtopMountain/scripts.pory"
	.string "Slooooow...!$"
