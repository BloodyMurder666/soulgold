VajraDesertEast_MapScripts::
	.byte 0


VajraDesertEast_TrainerSirocco::
# 4 "data/maps/VajraDesertEast/scripts.pory"
	trainerbattle_single TRAINER_VAJRA_EAST_SIROCCO, VajraDesertEast_TrainerSirocco_Text_0, VajraDesertEast_TrainerSirocco_Text_1
# 5 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_TrainerSirocco_Text_2
	end


VajraDesertEast_TrainerSol::
# 15 "data/maps/VajraDesertEast/scripts.pory"
	trainerbattle_double TRAINER_VAJRA_EAST_SOL, VajraDesertEast_TrainerSol_Text_0, VajraDesertEast_TrainerSol_Text_1, VajraDesertEast_TrainerSol_Text_2
# 17 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_TrainerSol_Text_3
	end


VajraDesertEast_TrainerDune::
# 25 "data/maps/VajraDesertEast/scripts.pory"
	trainerbattle_single TRAINER_VAJRA_EAST_DUNE, VajraDesertEast_TrainerDune_Text_0, VajraDesertEast_TrainerDune_Text_1
# 26 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_TrainerDune_Text_2
	end


VajraDesertEast_TrainerNori::
# 36 "data/maps/VajraDesertEast/scripts.pory"
	trainerbattle_double TRAINER_VAJRA_EAST_NORI, VajraDesertEast_TrainerNori_Text_0, VajraDesertEast_TrainerNori_Text_1, VajraDesertEast_TrainerNori_Text_2
# 38 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_TrainerNori_Text_3
	end


VajraDesertEast_TrainerAtlas::
# 45 "data/maps/VajraDesertEast/scripts.pory"
	trainerbattle_double TRAINER_VAJRA_EAST_ATLAS, VajraDesertEast_TrainerAtlas_Text_0, VajraDesertEast_TrainerAtlas_Text_1, VajraDesertEast_TrainerAtlas_Text_2
# 48 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_TrainerAtlas_Text_3
	end


VajraDesertEast_LadyofLake::
# 54 "data/maps/VajraDesertEast/scripts.pory"
	msgbox VajraDesertEast_LadyofLake_Text_0, MSGBOX_NPC
	return


VajraDesertEast_TrainerSirocco_Text_0:
# 4 "data/maps/VajraDesertEast/scripts.pory"
	.string "Let me see how tough you are!$"

VajraDesertEast_TrainerSirocco_Text_1:
# 4 "data/maps/VajraDesertEast/scripts.pory"
	.string "Tough enough, I guess...$"

VajraDesertEast_TrainerSirocco_Text_2:
# 5 "data/maps/VajraDesertEast/scripts.pory"
	.string "The hardest environments make the\n"
	.string "toughest trainers.\p"
	.string "I hope to become the very best\n"
	.string "someday!$"

VajraDesertEast_TrainerSol_Text_0:
# 15 "data/maps/VajraDesertEast/scripts.pory"
	.string "Huff, huff! One more lap!$"

VajraDesertEast_TrainerSol_Text_1:
# 15 "data/maps/VajraDesertEast/scripts.pory"
	.string "Need... water...!$"

VajraDesertEast_TrainerSol_Text_2:
# 15 "data/maps/VajraDesertEast/scripts.pory"
	.string "Hey, you need two Pokémon ready to\n"
	.string "battle!$"

VajraDesertEast_TrainerSol_Text_3:
# 17 "data/maps/VajraDesertEast/scripts.pory"
	.string "There's an oasis behind those palm\n"
	.string "trees, but you can't just go through\l"
	.string "them!$"

VajraDesertEast_TrainerDune_Text_0:
# 25 "data/maps/VajraDesertEast/scripts.pory"
	.string "Riding high!$"

VajraDesertEast_TrainerDune_Text_1:
# 25 "data/maps/VajraDesertEast/scripts.pory"
	.string "You caught me off guard...$"

VajraDesertEast_TrainerDune_Text_2:
# 26 "data/maps/VajraDesertEast/scripts.pory"
	.string "Two Pokémon I'd never seen before\n"
	.string "flew past here. They've returned a\l"
	.string "few times.\p"
	.string "What were they, I wonder?$"

VajraDesertEast_TrainerNori_Text_0:
# 36 "data/maps/VajraDesertEast/scripts.pory"
	.string "Are you the Trainer who beat Lance?$"

VajraDesertEast_TrainerNori_Text_1:
# 36 "data/maps/VajraDesertEast/scripts.pory"
	.string "No way! The Champion beat me!$"

VajraDesertEast_TrainerNori_Text_2:
# 36 "data/maps/VajraDesertEast/scripts.pory"
	.string "How does the Champion not have two\n"
	.string "Pokémon ready to battle?$"

VajraDesertEast_TrainerNori_Text_3:
# 38 "data/maps/VajraDesertEast/scripts.pory"
	.string "Can't wait to tell all my friends about\n"
	.string "this!$"

VajraDesertEast_TrainerAtlas_Text_0:
# 45 "data/maps/VajraDesertEast/scripts.pory"
	.string "Think you can reach the oasis?$"

VajraDesertEast_TrainerAtlas_Text_1:
# 45 "data/maps/VajraDesertEast/scripts.pory"
	.string "Looks like you won't get lost among\n"
	.string "the trees!$"

VajraDesertEast_TrainerAtlas_Text_2:
# 46 "data/maps/VajraDesertEast/scripts.pory"
	.string "Sorry, bud, but you need two Pokémon\n"
	.string "ready to battle.$"

VajraDesertEast_TrainerAtlas_Text_3:
# 48 "data/maps/VajraDesertEast/scripts.pory"
	.string "This place is almost like a savanna,\n"
	.string "even though it's part of the desert!$"

VajraDesertEast_LadyofLake_Text_0:
# 54 "data/maps/VajraDesertEast/scripts.pory"
	.string "$"
