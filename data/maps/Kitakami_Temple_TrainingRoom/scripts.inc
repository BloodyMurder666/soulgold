Kitakami_Temple_TrainingRoom_MapScripts::
	.byte 0


dojoFexpert::
# 4 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	lock
# 5 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	faceplayer
# 6 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	msgbox dojoFexpert_Text_0
# 12 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	goto_if_unset FLAG_RECEIVED_FOCUS_SASH, dojoFexpert_2
dojoFexpert_1:
# 17 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	release
	end

dojoFexpert_2:
# 13 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	msgbox dojoFexpert_Text_1
# 14 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	giveitem ITEM_FOCUS_SASH
# 15 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	setflag FLAG_RECEIVED_FOCUS_SASH
	goto dojoFexpert_1


dojoTrainer::
# 22 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	lock
# 23 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	msgbox dojoTrainer_Text_0
# 25 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	closemessage
# 26 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	release
	end


dojoFexpert_Text_0:
# 6 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	.string "Training yourself mentally and \n"
	.string "physically is as important as \l"
	.string "training your Pokémon. \p"
	.string "Tough challenges cannot be faced \n"
	.string "with weak body and mind.$"

dojoFexpert_Text_1:
# 13 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	.string "Perhaps this will help you focus on your\n"
	.string "training.$"

dojoTrainer_Text_0:
# 23 "data/maps/Kitakami_Temple_TrainingRoom/scripts.pory"
	.string "The trainee is meditating, \n"
	.string "it would be rude to disturb them.$"
