Kitakami_Temple_Storage_MapScripts::
	.byte 0


StorageMienfoo::
# 4 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	lock
# 5 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	faceplayer
# 6 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	playmoncry SPECIES_MIENFOO, CRY_MODE_NORMAL
# 7 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	msgbox StorageMienfoo_Text_0
# 8 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	waitmoncry
# 9 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	release
	end


StorageKeeper::
# 14 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	lock
# 15 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	faceplayer
# 16 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	goto_if_set FLAG_OBTAINED_OGERPON_MASKS, StorageKeeper_2
# 22 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	msgbox StorageKeeper_Text_1
# 31 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	checkspecies SPECIES_OGERPON
# 32 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq StorageKeeper_5
# 53 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	release
	end

StorageKeeper_2:
# 17 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	msgbox StorageKeeper_Text_0
# 19 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	release
	end

# 56 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	release
	end

StorageKeeper_5:
# 33 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	playse SE_PIN
# 34 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	applymovement LOCALID_TEMPLE_STOREKEEPER, Common_Movement_ExclamationMark
# 35 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	waitse
# 36 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	delay 30
# 37 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	msgbox StorageKeeper_Text_2
# 44 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	giveitem ITEM_CORNERSTONE_MASK
# 45 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	giveitem ITEM_WELLSPRING_MASK
# 46 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	giveitem ITEM_HEARTHFLAME_MASK
# 47 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	setflag FLAG_OBTAINED_OGERPON_MASKS
# 48 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	msgbox StorageKeeper_Text_0
# 50 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	release
	end


StorageMienfoo_Text_0:
# 7 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	.string "Mienfoo: Foo!$"

StorageKeeper_Text_0:
# 17 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	.string "These masks allow Ogerpon to wield\n"
	.string "powers from other types in battle.$"

StorageKeeper_Text_1:
# 22 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	.string "My task is to manage the sacred relics\n"
	.string "of Kitakami. \p"
	.string "Our villages guardian, Ogerpon once\n"
	.string "entrusted powerful relics to us.\p"
	.string "We've been guarding them ever since\n"
	.string "until Ogerpon once again requires\l"
	.string "them.$"

StorageKeeper_Text_2:
# 37 "data/maps/Kitakami_Temple_Storage/scripts.pory"
	.string "Could it be...? Ogerpon has chosen you\n"
	.string "as it's partner?\p"
	.string "Incredible!\p"
	.string "In that case, you should be the one\n"
	.string "holding its sacred relics.$"
