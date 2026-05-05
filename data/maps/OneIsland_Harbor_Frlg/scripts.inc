OneIsland_Harbor_Frlg_MapScripts::
	.byte 0


OneIsland_Harbor_Movement_PlayerExitHarbor::
	walk_up
	walk_up
	walk_up
	step_end

OneIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	end
