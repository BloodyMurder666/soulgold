RuinsOfAlph_PuzzleAndRewardChambers_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_PuzzleAndRewardChambers_OnLoad
	.byte 0

RuinsOfAlph_PuzzleAndRewardChambers_OnLoad::
	call_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole
	call_if_set FLAG_COMPLETED_ARCHEN_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenHole
	call_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole
	call_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole

	call_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor
	call_if_set FLAG_ARCHEN_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenDoor
	call_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor
	call_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor
	end

RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoHole::
	setmetatile 20, 5, 0x482, FALSE
	setmetatile 21, 5, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenHole::
	setmetatile 4, 22, 0x482, FALSE
	setmetatile 5, 22, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylHole::
	setmetatile 20, 22, 0x482, FALSE
	setmetatile 21, 22, 0x483, FALSE
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohHole::
	setmetatile 4, 5, 0x482, FALSE
	setmetatile 5, 5, 0x483, FALSE
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDoor::
	setmetatile 21, 1, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenDoor::
	setmetatile 5, 18, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDoor::
	setmetatile 21, 18, 0x488, FALSE 
	return
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDoor::
	setmetatile 5, 1, 0x488, FALSE 
	return


RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDescripton::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Archen, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_UnownText::
	lock
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist2::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2, MSGBOX_DEFAULT
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist3::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoSuccess::
	setflag FLAG_COMPLETED_KABUTO_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 5, 0x482, FALSE
	setmetatile 21, 5, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	setvar VAR_RUINSOFALPH_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_ArchenPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_ARCHEN
	goto_if_set FLAG_COMPLETED_ARCHEN_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_ArchenPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_ArchenPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_ArchenSuccess::
	setflag FLAG_COMPLETED_ARCHEN_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 22, 0x482, FALSE
	setmetatile 5, 22, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_AERODACTYL
	goto_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylSuccess::
	setflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 22, 0x482, FALSE
	setmetatile 21, 22, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end


RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HooHPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_HO_OH
	goto_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HoohPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohSuccess::
	setflag FLAG_COMPLETED_HOOH_PUZZLE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 4, 5, 0x482, FALSE
	setmetatile 5, 5, 0x483, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_PuzzleAndRewardChambers_Movement_Fall
	delay 30
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	warphole MAP_RUINS_OF_ALPH_B1F
	waitstate
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseEscapeRopeOpenKabuto::
	lockall
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedEscapeRope, MSGBOX_DEFAULT
	closemessage
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseWaterStoneOpenArchen::
	lockall
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedWaterStone, MSGBOX_DEFAULT
	closemessage
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardArchen

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_UseFlashOpenAerodactyl::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedFlash, MSGBOX_DEFAULT
	closemessage
	animateflash 1
	setflashlevel 1
	goto RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckHooh::
	lock
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckHooh
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardHooh::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 5, 1, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_HOOH_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckAerodactyl::
	lock
	goto_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_LightWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardAerodactyl::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 21, 18, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_AERODACTYL_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckKabuto::
	lock
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_EscapeWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardKabuto::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 21, 1, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_KABUTO_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckArchen::
	lock
	goto_if_set FLAG_ARCHEN_BROUGHT, RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_WaterWall, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardArchen::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 5, 18, 0x488, FALSE 
	special DrawWholeMapView
	setflag FLAG_ARCHEN_BROUGHT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RewardGotten::
	msgbox RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_Text_Reward:
	.string "The chamber reacts!\n"
	.string "The way is open.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_EscapeWall:
	.string "The wall reads:\n"
	.string "ESCAPE$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_LightWall:
	.string "The wall reads:\n"
	.string "LIGHT$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_HoohWall:
	.string "The wall reads:\n"
	.string "HO OH$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_WaterWall:
	.string "The wall reads:\n"
	.string "WATER$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedEscapeRope:
	.string "{PLAYER} used the\n"
	.string "Escape Rope.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedWaterStone:
	.string "{PLAYER} used the\n"
	.string "Water Stone.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UsedFlash:
	.string "{STR_VAR_1} used FLASH!$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Solved:
	.string "The way is open.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist1:
	.string "Welcome to this chamber.\p"
	.string "There are sliding panels that depict\n"
	.string "a Pokémon drawn by the ancients.\p"
	.string "Slide the panels around to form\n"
	.string "the picture.\p"
	.string "To the left is a description of\n"
	.string "the Pokémon.\p"
	.string "Scientists in the lab are examin-\n"
	.string "-ing some newly found patterns.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist2:
	.string "A hole just opened up in the floor!\n"
	.string "I'd better tell the others.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Receptionist3:
	.string "Now a hole in the wall too?!\n"
	.string "This is getting spooky.$"


RuinsOfAlph_PuzzleAndRewardChambers_Text_Kabuto:
	.string "A Pokémon that hid on the sea floor.\n"
	.string "Eyes on its back scanned the area.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_UnownText:
	.string "It's Unown text!$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Statue:
	.string "It's a replica of an ancient\n"
	.string "Pokémon.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Aerodactyl:
	.string "This flying Pokémon attacked its\n"
	.string "prey with saw-like fangs.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Archen:
	.string "This Pokémon was unable to fly\n"
	.string "despite having wings.$"

RuinsOfAlph_PuzzleAndRewardChambers_Text_Hooh:
	.string "A Pokémon that flew gracefully on\n"
	.string "rainbow-colored wings.$"

@==========================================================================================================================================================
@ Hooh
@ Aero
@ Kabuto
@ Archen
