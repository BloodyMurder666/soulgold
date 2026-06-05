# 1 "data/maps/IcePath_B2F/scripts.pory"

# 2 "data/maps/IcePath_B2F/scripts.pory"
IcePath_B2F_MapScripts::
# 3 "data/maps/IcePath_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SetBoulders
# 4 "data/maps/IcePath_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 5 "data/maps/IcePath_B2F/scripts.pory"
	.byte 0

SetBoulders::
# 11 "data/maps/IcePath_B2F/scripts.pory"
	goto_if_unset FLAG_ICEPATH_BOULDER3, SetBoulders_2
SetBoulders_1:
# 14 "data/maps/IcePath_B2F/scripts.pory"
	goto_if_unset FLAG_ICEPATH_BOULDER4, SetBoulders_5
SetBoulders_4:
# 17 "data/maps/IcePath_B2F/scripts.pory"
	goto_if_unset FLAG_ICEPATH_BOULDER2, SetBoulders_8
SetBoulders_7:
# 20 "data/maps/IcePath_B2F/scripts.pory"
	goto_if_unset FLAG_ICEPATH_BOULDER1, SetBoulders_10
	return

SetBoulders_2:
# 12 "data/maps/IcePath_B2F/scripts.pory"
	setflag FLAG_TEMP_3
	goto SetBoulders_1

SetBoulders_5:
# 15 "data/maps/IcePath_B2F/scripts.pory"
	setflag FLAG_TEMP_4
	goto SetBoulders_4

SetBoulders_8:
# 18 "data/maps/IcePath_B2F/scripts.pory"
	setflag FLAG_TEMP_2
	goto SetBoulders_7

SetBoulders_10:
# 21 "data/maps/IcePath_B2F/scripts.pory"
	setflag FLAG_TEMP_1
	return

