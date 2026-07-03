Kitakami_Temple_MapScripts::
	.byte 0


megaKickTrainer::
# 4 "data/maps/Kitakami_Temple/scripts.pory"
	lock
# 5 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox megaKickTrainer_Text_0
# 6 "data/maps/Kitakami_Temple/scripts.pory"
	release
	end


megaPunchTrainer::
# 11 "data/maps/Kitakami_Temple/scripts.pory"
	lock
# 12 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox megaPunchTrainer_Text_0
# 13 "data/maps/Kitakami_Temple/scripts.pory"
	release
	end


DojoTourist::
# 18 "data/maps/Kitakami_Temple/scripts.pory"
	lock
# 19 "data/maps/Kitakami_Temple/scripts.pory"
	faceplayer
# 20 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox DojoTourist_Text_0
# 24 "data/maps/Kitakami_Temple/scripts.pory"
	release
	end


DojoTrainee::
# 29 "data/maps/Kitakami_Temple/scripts.pory"
	lock
# 30 "data/maps/Kitakami_Temple/scripts.pory"
	faceplayer
# 31 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox DojoTrainee_Text_0
# 35 "data/maps/Kitakami_Temple/scripts.pory"
	release
	end


DojoTeacher::
# 40 "data/maps/Kitakami_Temple/scripts.pory"
	lock
# 41 "data/maps/Kitakami_Temple/scripts.pory"
	faceplayer
# 42 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox DojoTeacher_Text_0
# 46 "data/maps/Kitakami_Temple/scripts.pory"
	release
	end


DojoTeacher2::
# 51 "data/maps/Kitakami_Temple/scripts.pory"
	msgbox DojoTeacher2_Text_0, MSGBOX_NPC
	return


megaKickTrainer_Text_0:
# 5 "data/maps/Kitakami_Temple/scripts.pory"
	.string "No no, you don't get it, Mega Punch is\n"
	.string "the superior move!$"

megaPunchTrainer_Text_0:
# 12 "data/maps/Kitakami_Temple/scripts.pory"
	.string "Fool! Everyone knows Mega Kick is the\n"
	.string "true path to power!$"

DojoTourist_Text_0:
# 20 "data/maps/Kitakami_Temple/scripts.pory"
	.string "The traditions here have been kept\n"
	.string "alive for countless lifetimes.\p"
	.string "It is quite impressive!$"

DojoTrainee_Text_0:
# 31 "data/maps/Kitakami_Temple/scripts.pory"
	.string "We offer paid courses for visitors. \p"
	.string "If you wish to grow stronger fast,\n"
	.string "please consider supporting our temple.$"

DojoTeacher_Text_0:
# 42 "data/maps/Kitakami_Temple/scripts.pory"
	.string "Behind me is the practice room. \p"
	.string "Take care not to disturb their\n"
	.string "training.$"

DojoTeacher2_Text_0:
# 51 "data/maps/Kitakami_Temple/scripts.pory"
	.string "These doors lead to the sleeping \n"
	.string "quarters.$"
