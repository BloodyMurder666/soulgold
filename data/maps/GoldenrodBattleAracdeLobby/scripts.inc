GoldenrodBattleAracdeLobby_MapScripts::
# 5 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 14 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleArcade_Registration_EventScript_GetChallengeStatus
# 8 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleArcade_Registration_EventScript_QuitWithoutSaving
# 9 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleArcade_Registration_EventScript_ResumeChallenge
# 10 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleArcade_Registration_EventScript_WonChallenge
# 11 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleArcade_Registration_EventScript_LostChallenge
	.2byte 0

GoldenrodBattleAracdeLobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 16 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_Lobby_EventScript_PlayerFaceNorth
	.2byte 0


GoldenrodArcadeLobby_Rocker::
# 25 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	lock
# 26 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcadeLobby_Rocker_Text_0
# 28 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end


GoldenrodArcadeLobby_Oldman::
# 33 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	lock
# 34 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcadeLobby_Oldman_Text_0
# 37 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end


GoldenrodArcadeLobby_Battlegirl::
# 42 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	lock
# 43 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcadeLobby_Battlegirl_Text_0
# 45 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end


GoldenrodArcadeLobby_Shop::
# 50 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	lock
# 51 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcadeLobby_Shop_Text_0
# 52 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	waitmessage
# 53 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	pokemart GoldenrodArcade_Shop
# 54 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcadeLobby_Shop_Text_1
# 55 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end


	.align 2
# 59 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
GoldenrodArcade_Shop:
# 60 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_MASTER_BALL
# 61 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_SHIN_GENOME
# 62 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_HP_UP_EX
# 63 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_PROTEIN_EX
# 64 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_IRON_EX
# 65 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_CALCIUM_EX
# 66 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_ZINC_EX
# 67 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_CARBOS_EX
# 68 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.2byte ITEM_PP_MAX
	.2byte ITEM_NONE

GoldenrodArcade_Queue2::
# 72 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcade_Queue2_Text_0, MSGBOX_NPC
	return


GoldenrodArcade_Queue3::
# 77 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcade_Queue3_Text_0, MSGBOX_NPC
	return


GoldenrodArcade_Queue4::
# 81 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox GoldenrodArcade_Queue4_Text_0, MSGBOX_NPC
	return


ArcadeLobby_GameMachine::
# 86 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox ArcadeLobby_GameMachine_Text_0, MSGBOX_NPC
	return


MagernaKeyBurglar::
# 92 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	lock
# 93 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	faceplayer
# 94 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	goto_if_set FLAG_GOT_MAGERNA_KEY, MagernaKeyBurglar_2
# 102 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	goto_if_unset FLAG_GOT_MAGERNA_KEY_INTRODONE, MagernaKeyBurglar_5
MagernaKeyBurglar_4:
# 120 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_3
# 125 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	specialvar VAR_RESULT, GetRocketArcadeWins
# 126 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_ge MagernaKeyBurglar_8
# 142 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end

MagernaKeyBurglar_2:
# 95 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_0
# 97 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_1
# 99 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end

MagernaKeyBurglar_5:
# 103 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_2
# 118 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	setflag FLAG_GOT_MAGERNA_KEY_INTRODONE
	goto MagernaKeyBurglar_4

MagernaKeyBurglar_8:
# 127 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_4
# 131 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	playfanfare MUS_HG_OBTAIN_KEY_ITEM
# 132 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_5
# 133 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	waitfanfare
# 134 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_6
# 136 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	msgbox MagernaKeyBurglar_Text_7
# 138 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	setflag FLAG_GOT_MAGERNA_KEY
# 139 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	release
	end


GoldenrodArcadeLobby_Rocker_Text_0:
# 26 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "These machines have to be rigged!\n"
	.string "There's no way I just lost it all!$"

GoldenrodArcadeLobby_Oldman_Text_0:
# 34 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Hah! Another win! I'll get to buy my\n"
	.string "daughter something nice this weekend!$"

GoldenrodArcadeLobby_Battlegirl_Text_0:
# 43 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "RAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH!\n"
	.string "JUST ONE MORE WIN AND I'LL STOP!$"

GoldenrodArcadeLobby_Shop_Text_0:
# 51 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Welcome.$"

GoldenrodArcadeLobby_Shop_Text_1:
# 54 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Pleasure doing business.$"

GoldenrodArcade_Queue2_Text_0:
# 72 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "I can't wait to see the next battle\n"
	.string "from the front-row seats!$"

GoldenrodArcade_Queue3_Text_0:
# 77 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Hey! No shoving! I was here first!$"

GoldenrodArcade_Queue4_Text_0:
# 81 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Is this the Goldenrod Casino? I think\n"
	.string "I'm a little lost...$"

ArcadeLobby_GameMachine_Text_0:
# 86 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Bright flashes and vivid pictures are\n"
	.string "flashing across the screen. Better not\l"
	.string "try...$"

MagernaKeyBurglar_Text_0:
# 95 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "You can use the key to access the top \n"
	.string "floor of Goldenrod apartment building.$"

MagernaKeyBurglar_Text_1:
# 97 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "As for me, I'm rich beyond belief \n"
	.string "now! Good bye ice soup, hello gravlax!$"

MagernaKeyBurglar_Text_2:
# 103 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "Hey there champ, may I interest\n"
	.string "you in some special wares that\l"
	.string "may or may not have been legally\l"
	.string "acquired?\p"
	.string "For example, this key to the top\n"
	.string "floor apartment residence in the\l"
	.string "Goldenrod apartment building!\p"
	.string "Who knows what kind of riches are\n"
	.string "available for the taking up there?\p"
	.string "I just need you to do me a tiny\n"
	.string "favour and it could be yours for\l"
	.string "the taking.$"

MagernaKeyBurglar_Text_3:
# 120 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "I need you to win at least 25 battles\n"
	.string "in the Rocket Arcade battles, my\l"
	.string "bets are riding on you winning\l"
	.string "me a fortune!$"

MagernaKeyBurglar_Text_4:
# 127 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "You... You did it!\p"
	.string "I can't thank you enough. Here, it's\n"
	.string "yours as promised.$"

MagernaKeyBurglar_Text_5:
# 132 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "{PLAYER} obtained Apartment Key!$"

MagernaKeyBurglar_Text_6:
# 134 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "You can use it to access the top floor\n"
	.string "of Goldenrod apartment building.$"

MagernaKeyBurglar_Text_7:
# 136 "data/maps/GoldenrodBattleAracdeLobby/scripts.pory"
	.string "As for me, it's time to say goodbye\n"
	.string "to ice soup!$"
