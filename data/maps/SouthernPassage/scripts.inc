SouthernPassage_MapScripts::
	.byte 0


BlockSouthJohtoAccess::
# 4 "data/maps/SouthernPassage/scripts.pory"
	lock
# 5 "data/maps/SouthernPassage/scripts.pory"
	msgbox BlockSouthJohtoAccess_Text_0
# 11 "data/maps/SouthernPassage/scripts.pory"
	applymovement LOCALID_PLAYER, BlockSouthJohtoAccess_Movement_0
# 12 "data/maps/SouthernPassage/scripts.pory"
	release
	end


# 11 "data/maps/SouthernPassage/scripts.pory"
BlockSouthJohtoAccess_Movement_0:
# 11 "data/maps/SouthernPassage/scripts.pory"
	walk_up
	step_end

BlockSouthJohtoAccess_Text_0:
# 5 "data/maps/SouthernPassage/scripts.pory"
	.string "The tides ahead seem too strong to \n"
	.string "proceed right now. Better turn back\l"
	.string "for now.\p"
	.string "System note: The area ahead is not \n"
	.string "yet accessible in this version.$"
