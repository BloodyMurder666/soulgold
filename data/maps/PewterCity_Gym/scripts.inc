PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	special Achievement_CheckAll
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	msgbox PewterCity_Gym_Text_EarthquakeSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "Brock: Wow, it's not often that we get a\n"
	.string "challenger from Johto.\p"
	.string "I'm Brock, the Pewter Gym Leader.\p"
	.string "I'm an expert on rock-type Pokémon.\p"
	.string "My Pokémon are impervious to most\n"
	.string "physical attacks. You'll have a hard\l"
	.string "time inflicting any damage.\p"
	.string "Come on!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "Brock: Your Pokémon's powerful attacks\n"
	.string "overcame my rock-hard defense…\p"
	.string "You're stronger than I expected…\p"
	.string "Go ahead--take this Badge.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} received Boulderbadge.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "Brock: {PLAYER}, thanks. I enjoyed\n"
	.string "battling you, even though I am a bit\l"
	.string "upset.\p"
	.string "That Boulderbadge will make your\n"
	.string "Pokémon even more powerful.$"

PewterCity_Gym_Text_EarthquakeSpeech:
    .string "That TM contains Earthquake.\p"
    .string "It's a powerful attack that\n"
    .string "shakes up the battlefield.\p"
    .string "But be careful not to\n"
    .string "undermine your own Pokémon!$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "Brock: The world is huge. There are\n"
	.string "still many strong trainers like you.\p"
	.string "Just wait and see. I'm going to become\n"
	.string "a lot stronger too.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "The trainers of this Gym use rock-type\n"
	.string "Pokémon.\p"
	.string "The rock-type has high Defense.\p"
	.string "Battles could end up going a long time.\n"
	.string "Are you ready for this?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "I have to win these battles…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hey, you! Trainer from Johto! Brock is\n"
	.string "tough. He'll punish you if you don't\l"
	.string "take him seriously.$"

PewterCity_Gym_Text_Guide:
	.string "Yo! Champ in making! You're really\n"
	.string "rocking.\p"
	.string "Are you battling the Gym Leaders of\n"
	.string "Kanto?\p"
	.string "They're strong and dedicated people,\n"
	.string "just like Johto's Gym Leaders.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Yo! Champ in making! That Gym didn't\n"
	.string "give you much trouble.\p"
	.string "The way you took charge was really\n"
	.string "inspiring. I mean that seriously.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
	.string "Winning Trainers:\n"
	.string "Blue, Red$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
    .string "Winning Trainers:\n"
	.string "Blue, Red, {PLAYER}$"

