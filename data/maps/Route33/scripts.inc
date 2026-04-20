# 1 "data/maps/Route33/scripts.pory"

# 2 "data/maps/Route33/scripts.pory"
Route33_MapScripts::
# 3 "data/maps/Route33/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
# 4 "data/maps/Route33/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/Route33/scripts.pory"
	.byte 0
# 6 "data/maps/Route33/scripts.pory"

# 7 "data/maps/Route33/scripts.pory"
Route33_OnTransition: 
# 8 "data/maps/Route33/scripts.pory"
	callnative SetTimeBasedEncounters
# 9 "data/maps/Route33/scripts.pory"
	end
# 10 "data/maps/Route33/scripts.pory"

# 11 "data/maps/Route33/scripts.pory"
Route33_EventScript_HikerAnthony::
# 12 "data/maps/Route33/scripts.pory"
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
# 13 "data/maps/Route33/scripts.pory"
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
# 14 "data/maps/Route33/scripts.pory"
	end
# 15 "data/maps/Route33/scripts.pory"

# 16 "data/maps/Route33/scripts.pory"
Route33_EventScript_Lass::
# 17 "data/maps/Route33/scripts.pory"
	lock
# 18 "data/maps/Route33/scripts.pory"
	faceplayer
# 19 "data/maps/Route33/scripts.pory"
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
# 20 "data/maps/Route33/scripts.pory"
	closemessage
# 21 "data/maps/Route33/scripts.pory"
	release
# 22 "data/maps/Route33/scripts.pory"
	end
# 23 "data/maps/Route33/scripts.pory"

# 24 "data/maps/Route33/scripts.pory"
Route33_Text_HikerAnthony2Seen:
# 25 "data/maps/Route33/scripts.pory"
	.string "I came through the tunnel,\n"
# 26 "data/maps/Route33/scripts.pory"
	.string "but I still have plenty\l"
# 27 "data/maps/Route33/scripts.pory"
	.string "of energy left.$"
# 28 "data/maps/Route33/scripts.pory"

# 29 "data/maps/Route33/scripts.pory"
Route33_Text_HikerAnthony2Beaten:
# 30 "data/maps/Route33/scripts.pory"
	.string "Whoa! You've got more zip\n"
# 31 "data/maps/Route33/scripts.pory"
	.string "than me!$"
# 32 "data/maps/Route33/scripts.pory"

# 33 "data/maps/Route33/scripts.pory"
Route33_Text_HikerAnthony2After:
# 34 "data/maps/Route33/scripts.pory"
	.string "We HIKERS are at our best\n"
# 35 "data/maps/Route33/scripts.pory"
	.string "in the mountains.$"
# 36 "data/maps/Route33/scripts.pory"

# 37 "data/maps/Route33/scripts.pory"
Route33_Text_HikerAnthonyDunsparce:
# 38 "data/maps/Route33/scripts.pory"
	.string "Hey, did you get a DUNSPARCE?\p"
# 39 "data/maps/Route33/scripts.pory"
	.string "I caught one too.\p"
# 40 "data/maps/Route33/scripts.pory"
	.string "Take a look at it in the light.\n"
# 41 "data/maps/Route33/scripts.pory"
	.string "It's got a funny face!$"
# 42 "data/maps/Route33/scripts.pory"

# 43 "data/maps/Route33/scripts.pory"
Route33_Text_Lass:
# 44 "data/maps/Route33/scripts.pory"
	.string "Pant, pant…\p"
# 45 "data/maps/Route33/scripts.pory"
	.string "That cave was bigger than\n"
# 46 "data/maps/Route33/scripts.pory"
	.string "I'd expected.\p"
# 47 "data/maps/Route33/scripts.pory"
	.string "I got too tired exploring\n"
# 48 "data/maps/Route33/scripts.pory"
	.string "for MARILL, so I came outside.$"

Route33_HiddenGrotto::
# 52 "data/maps/Route33/scripts.pory"
	msgbox Route33_HiddenGrotto_Text_0, MSGBOX_YESNO
# 54 "data/maps/Route33/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route33_HiddenGrotto_2
Route33_HiddenGrotto_1:
# 58 "data/maps/Route33/scripts.pory"
	release
	end

Route33_HiddenGrotto_2:
# 55 "data/maps/Route33/scripts.pory"
	warp MAP_HIDDEN_GROTTO_ROUTE33, 0
# 56 "data/maps/Route33/scripts.pory"
	waitstate
	goto Route33_HiddenGrotto_1


Route33_HiddenGrotto_Text_0:
# 52 "data/maps/Route33/scripts.pory"
	.string "There seems to be a path behind the\n"
	.string "trees. Enter?$"
