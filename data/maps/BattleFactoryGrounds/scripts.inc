BattleFactoryGrounds_MapScripts::
	.byte 0


FactoryGrounds_CooltrainerF::
# 4 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_CooltrainerF_Text_0, MSGBOX_NPC
	return


FactoryGrounds_Fisher::
# 11 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 12 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Fisher_Text_0
# 14 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_Boy::
# 19 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 20 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 21 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_0
# 23 "data/maps/BattleFactoryGrounds/scripts.pory"
	applymovement LOCALID_FACTORY_ESPURR, FactoryGrounds_Boy_Movement_0
# 24 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmovement
# 25 "data/maps/BattleFactoryGrounds/scripts.pory"
	applymovement LOCALID_FACTORY_KID, FactoryGrounds_Boy_Movement_1
# 26 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmovement
# 27 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_1
# 28 "data/maps/BattleFactoryGrounds/scripts.pory"
	delay 30
# 29 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_1
# 30 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 31 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_2
# 32 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_Espurr::
# 37 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 38 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 39 "data/maps/BattleFactoryGrounds/scripts.pory"
	playmoncry SPECIES_ESPURR, CRY_MODE_NORMAL
# 40 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Espurr_Text_0
# 41 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmoncry
# 42 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_OldLady::
# 47 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_OldLady_Text_0, MSGBOX_NPC
	return


# 23 "data/maps/BattleFactoryGrounds/scripts.pory"
FactoryGrounds_Boy_Movement_0:
# 23 "data/maps/BattleFactoryGrounds/scripts.pory"
	face_right
	step_end

# 25 "data/maps/BattleFactoryGrounds/scripts.pory"
FactoryGrounds_Boy_Movement_1:
# 25 "data/maps/BattleFactoryGrounds/scripts.pory"
	face_left
	step_end

FactoryGrounds_CooltrainerF_Text_0:
# 4 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "The battles in the Factory are tough!\p"
	.string "You can't use your own Pokémon,\n"
	.string "so you must think on your feet.$"

FactoryGrounds_Fisher_Text_0:
# 12 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Hmm, there's no Magikarps in this pond,\n"
	.string "only Tynamos and Chinchous...$"

FactoryGrounds_Boy_Text_0:
# 21 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Me and Espurr can converse without\n"
	.string "speaking! Watch!$"

FactoryGrounds_Boy_Text_1:
# 27 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "...$"

FactoryGrounds_Boy_Text_2:
# 31 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Cool, right?$"

FactoryGrounds_Espurr_Text_0:
# 40 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Espurr: Essss!$"

FactoryGrounds_OldLady_Text_0:
# 47 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "I'm not fond of these modern\n"
	.string "buildings being placed so near\l"
	.string "our beloved Ecruteak City.$"
