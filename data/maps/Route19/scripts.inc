Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "Have you ever gone swimming in the\n"
	.string "sea at night?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glub…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "At night, the sea turns black. It\n"
	.string "feels like it will swallow you up.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Pant, pant… Just… a little…\p"
	.string "farther… to… Fuchsia…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "I'm drowning!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "I… asked my girlfriend to swim to\n"
	.string "Fuchsia… Gasp…$"

Route19_Text_SwimmerfDawnSeen:
	.string "I'm disgusted by wimpy people!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "I could beat you at swimming…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "It's a quick swim between Fuchsia\n"
	.string "and Seafoam Islands…\p"
	.string "Sheesh, some big man my boyfriend\n"
	.string "is! What a wimp!$"

Route19_Text_SwimmermJeromeSeen:
	.string "Swimming? I'm lousy at it.\p"
	.string "I'm just splashing around in these\n"
	.string "shallow waters.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "I thought I could win.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "I might be bad at swimming, but I\n"
	.string "love the sea.$"

Route19_Text_Fisher1:
	.string "Sorry. This road is closed for\n"
	.string "construction.\p"
	.string "If you want to get to Cinnabar,\n"
	.string "you'd better go south from Pallet\n"
	.string "Town.$"

Route19_Text_Kingler:
	.string "Kingler: Keeeeeeeeeeee$"

Route19_Text_Fisher1_RocksCleared:
	.string "I'm all sweaty. Time for a swim!$"

Route19_Text_Fisher2:
	.string "Aw man, Kingler is blocking the\n"
	.string "beach.$"

Route19_Text_FisherBefore:
	.string "No fishing until these Kingler\n"
	.string "clear out.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Those Kingler finally left!\p"
	.string "Now I can go fishing again.$"

Route19_Text_Sign:
	.string "Route 19\p"
	.string "Fuchsia City - Seafoam Islands$"

Route19_Text_CarefulSwimmingSign:
	.string "Please be careful if you are\n"
	.string "swimming to Seafoam Islands.\p"
	.string "Fuchsia Police$"

