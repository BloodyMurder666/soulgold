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
	.string "from the frontrow seats!$"

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
