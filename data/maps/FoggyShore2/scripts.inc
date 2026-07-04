FoggyShore2_MapScripts::
	.byte 0


NijoTrainer::
# 4 "data/maps/FoggyShore2/scripts.pory"
	trainerbattle_single TRAINER_NIJO, NijoTrainer_Text_0, NijoTrainer_Text_1
# 7 "data/maps/FoggyShore2/scripts.pory"
	msgbox NijoTrainer_Text_2, MSGBOX_AUTOCLOSE
	end


SaeTrainer::
# 16 "data/maps/FoggyShore2/scripts.pory"
	trainerbattle_single TRAINER_SAE, SaeTrainer_Text_0, SaeTrainer_Text_1
# 18 "data/maps/FoggyShore2/scripts.pory"
	msgbox SaeTrainer_Text_2, MSGBOX_AUTOCLOSE
	end


FoggyShoreSign::
# 25 "data/maps/FoggyShore2/scripts.pory"
	msgbox FoggyShoreSign_Text_0, MSGBOX_SIGN
	return


FoggyShoreBuizel::
# 29 "data/maps/FoggyShore2/scripts.pory"
	lock
# 30 "data/maps/FoggyShore2/scripts.pory"
	faceplayer
# 31 "data/maps/FoggyShore2/scripts.pory"
	playmoncry SPECIES_BUIZEL, CRY_MODE_NORMAL
# 32 "data/maps/FoggyShore2/scripts.pory"
	msgbox FoggyShoreBuizel_Text_0
# 33 "data/maps/FoggyShore2/scripts.pory"
	waitmoncry
# 34 "data/maps/FoggyShore2/scripts.pory"
	release
	end


NijoTrainer_Text_0:
# 4 "data/maps/FoggyShore2/scripts.pory"
	.string "What are you doing here so far off the\n"
	.string "beaten path?$"

NijoTrainer_Text_1:
# 6 "data/maps/FoggyShore2/scripts.pory"
	.string "You'll be fine.$"

NijoTrainer_Text_2:
# 7 "data/maps/FoggyShore2/scripts.pory"
	.string "Nearby path leads to a forest where\n"
	.string "many get lost. \p"
	.string "Be careful if you decide to \n"
	.string "venture there.$"

SaeTrainer_Text_0:
# 16 "data/maps/FoggyShore2/scripts.pory"
	.string "A quiet beach, the perfect getaway!$"

SaeTrainer_Text_1:
# 17 "data/maps/FoggyShore2/scripts.pory"
	.string "Peace, ruined!$"

SaeTrainer_Text_2:
# 18 "data/maps/FoggyShore2/scripts.pory"
	.string "Not that many wander down here due to\n"
	.string "the rumours of the spooky woods\l"
	.string "nearby.$"

FoggyShoreSign_Text_0:
# 25 "data/maps/FoggyShore2/scripts.pory"
	.string "{UP_ARROW} Lost Woods$"

FoggyShoreBuizel_Text_0:
# 32 "data/maps/FoggyShore2/scripts.pory"
	.string "Buizel: Buibuibuiiii!$"
