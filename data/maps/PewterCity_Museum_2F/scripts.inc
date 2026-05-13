PewterCity_Museum_2F_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "They say that meteorites struck\n"
	.string "Birth Island.\p"
	.string "We would love to display them here\n"
	.string "in our museum, but...\p"
	.string "These meteorites are said to emit\n"
	.string "strange energy and cannot be\l"
	.string "carried away...$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "I want a Pikachu!\n"
    .string "It's so cute!\p"
    .string "I asked my daddy to catch me one!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Yeah, a Pikachu soon, I promise!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Space Shuttle$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "A meteorite that fell on Mt. Moon.\n"
    .string "It is thought to be a Moon Stone.$"
