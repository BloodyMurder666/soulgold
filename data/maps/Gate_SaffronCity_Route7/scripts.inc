Gate_SaffronCity_Route7_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "Did you hear about the accident\n"
	.string "at the Power Plant?\p"
	.string "It's located in the East, close\n"
	.string "to Lavender Town.$"

Route7_Text_SaffronGuard_Serious:
	.string "I take my Guard job seriously.\p"
	.string "Hey! You have a Pokédex.\p"
	.string "Ok. You can go through.$"
