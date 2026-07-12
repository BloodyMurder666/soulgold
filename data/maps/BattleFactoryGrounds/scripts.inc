BattleFactoryGrounds_MapScripts::
# 2 "data/maps/BattleFactoryGrounds/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFactoryGrounds_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

BattleFactoryGrounds_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/BattleFactoryGrounds/scripts.pory"
	goto setFactoryFlightFlag
	return


setFactoryFlightFlag::
# 8 "data/maps/BattleFactoryGrounds/scripts.pory"
	setflag FLAG_VISITED_BATTLE_FACTORY
	end


FactoryGrounds_CooltrainerF::
# 13 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_CooltrainerF_Text_0, MSGBOX_NPC
	return


FactoryGrounds_Fisher::
# 20 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 21 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Fisher_Text_0
# 23 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_Boy::
# 28 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 29 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 30 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_0
# 32 "data/maps/BattleFactoryGrounds/scripts.pory"
	applymovement LOCALID_FACTORY_ESPURR, FactoryGrounds_Boy_Movement_0
# 33 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmovement
# 34 "data/maps/BattleFactoryGrounds/scripts.pory"
	applymovement LOCALID_FACTORY_KID, FactoryGrounds_Boy_Movement_1
# 35 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmovement
# 36 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_1
# 37 "data/maps/BattleFactoryGrounds/scripts.pory"
	delay 30
# 38 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_1
# 39 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 40 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Boy_Text_2
# 41 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_Espurr::
# 46 "data/maps/BattleFactoryGrounds/scripts.pory"
	lock
# 47 "data/maps/BattleFactoryGrounds/scripts.pory"
	faceplayer
# 48 "data/maps/BattleFactoryGrounds/scripts.pory"
	playmoncry SPECIES_ESPURR, CRY_MODE_NORMAL
# 49 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_Espurr_Text_0
# 50 "data/maps/BattleFactoryGrounds/scripts.pory"
	waitmoncry
# 51 "data/maps/BattleFactoryGrounds/scripts.pory"
	release
	end


FactoryGrounds_OldLady::
# 56 "data/maps/BattleFactoryGrounds/scripts.pory"
	msgbox FactoryGrounds_OldLady_Text_0, MSGBOX_NPC
	return


# 32 "data/maps/BattleFactoryGrounds/scripts.pory"
FactoryGrounds_Boy_Movement_0:
# 32 "data/maps/BattleFactoryGrounds/scripts.pory"
	face_right
	step_end

# 34 "data/maps/BattleFactoryGrounds/scripts.pory"
FactoryGrounds_Boy_Movement_1:
# 34 "data/maps/BattleFactoryGrounds/scripts.pory"
	face_left
	step_end

FactoryGrounds_CooltrainerF_Text_0:
# 13 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "The battles in the Factory are tough!\p"
	.string "You can't use your own Pokémon,\n"
	.string "so you must think on your feet.$"

FactoryGrounds_Fisher_Text_0:
# 21 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Hmm, there's no Magikarps in this pond,\n"
	.string "only Tynamos and Chinchous...$"

FactoryGrounds_Boy_Text_0:
# 30 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Me and Espurr can converse without\n"
	.string "speaking! Watch!$"

FactoryGrounds_Boy_Text_1:
# 36 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "...$"

FactoryGrounds_Boy_Text_2:
# 40 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Cool, right?$"

FactoryGrounds_Espurr_Text_0:
# 49 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "Espurr: Essss!$"

FactoryGrounds_OldLady_Text_0:
# 56 "data/maps/BattleFactoryGrounds/scripts.pory"
	.string "I'm not fond of these modern\n"
	.string "buildings being placed so near\l"
	.string "our beloved Ecruteak City.$"
