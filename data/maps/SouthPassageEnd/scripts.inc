SouthPassageEnd_MapScripts::
	.byte 0


SouthPassageSign::
# 4 "data/maps/SouthPassageEnd/scripts.pory"
	msgbox SouthPassageSign_Text_0, MSGBOX_SIGN
	return


SouthPassageAriana::
# 11 "data/maps/SouthPassageEnd/scripts.pory"
	lock
# 12 "data/maps/SouthPassageEnd/scripts.pory"
	faceplayer
# 13 "data/maps/SouthPassageEnd/scripts.pory"
	msgbox SouthPassageAriana_Text_0
# 17 "data/maps/SouthPassageEnd/scripts.pory"
	turnobject LOCALID_SP_ARIANA, DIR_NORTH
# 18 "data/maps/SouthPassageEnd/scripts.pory"
	msgbox SouthPassageAriana_Text_1
# 30 "data/maps/SouthPassageEnd/scripts.pory"
	faceplayer
# 31 "data/maps/SouthPassageEnd/scripts.pory"
	msgbox SouthPassageAriana_Text_2
# 40 "data/maps/SouthPassageEnd/scripts.pory"
	closemessage
# 41 "data/maps/SouthPassageEnd/scripts.pory"
	setfieldeffectargument 0, 1
# 42 "data/maps/SouthPassageEnd/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 43 "data/maps/SouthPassageEnd/scripts.pory"
	delay 15
# 44 "data/maps/SouthPassageEnd/scripts.pory"
	removeobject LOCALID_SP_ARIANA
# 45 "data/maps/SouthPassageEnd/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 46 "data/maps/SouthPassageEnd/scripts.pory"
	setflag FLAG_SOUTHPASSAGE_ARIANA
# 47 "data/maps/SouthPassageEnd/scripts.pory"
	release
	end


SouthPassageSign_Text_0:
# 4 "data/maps/SouthPassageEnd/scripts.pory"
	.string "Research Facility, keep out!\p"
	.string "The text is faded and difficult\n"
	.string "to read.$"

SouthPassageAriana_Text_0:
# 13 "data/maps/SouthPassageEnd/scripts.pory"
	.string "Oh. It's you.\p"
	.string "Didn't expect you to wander all the\n"
	.string "way over here.$"

SouthPassageAriana_Text_1:
# 18 "data/maps/SouthPassageEnd/scripts.pory"
	.string "Archer sent me to check on something\n"
	.string "here.\p"
	.string "This place had been conducting illegal\n"
	.string "operations in the name of Team Rocket.\p"
	.string "Even Giovanni had not given an approval\n"
	.string "for them. \p"
	.string "Once he caught wind of it, he sent an\n"
	.string "order to cease the operations and fired\l"
	.string "all the scientists and grunts involved.$"

SouthPassageAriana_Text_2:
# 31 "data/maps/SouthPassageEnd/scripts.pory"
	.string "They tried to burn all evidence, but\n"
	.string "they were caught quickly.\p"
	.string "If you wish to explore around, then I'm \n"
	.string "not going to stop you, but don't expect\l"
	.string "to find much.\p"
	.string "I got what I need already, so I'll be\n"
	.string "heading back.$"
