RuinsOfAlph_SecretRoom_MapScripts::
	.byte 0


RuinsSecretRoom::
# 4 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	lock
# 5 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	checkspecies SPECIES_HOOPA
# 6 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RuinsSecretRoom_2
RuinsSecretRoom_1:
# 9 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RuinsSecretRoom_5
# 21 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	msgbox RuinsSecretRoom_Text_1, MSGBOX_SIGN
# 22 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	release
	end

RuinsSecretRoom_2:
# 7 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	checkspecies SPECIES_HOOPA_UNBOUND
	goto RuinsSecretRoom_1

RuinsSecretRoom_5:
# 10 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	msgbox RuinsSecretRoom_Text_0, MSGBOX_YESNO
# 14 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RuinsSecretRoom_8
RuinsSecretRoom_7:
# 18 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	release
	end

RuinsSecretRoom_8:
# 15 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	warp MAP_SPEAR_PILLAR_TOP, 16, 33
# 16 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	waitstate
	goto RuinsSecretRoom_7


RuinsSecretRoom_Text_0:
# 10 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	.string "Hoopa seems to want to show you\n"
	.string "something.\p"
	.string "Allow it to interact with the wall?$"

RuinsSecretRoom_Text_1:
# 21 "data/maps/RuinsOfAlph_SecretRoom/scripts.pory"
	.string "Colored symbols fill the wall.$"
