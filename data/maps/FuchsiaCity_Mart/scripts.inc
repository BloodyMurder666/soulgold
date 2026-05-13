FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Fisher::
	msgbox FuchsiaMart_Text_Fisher, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Woman::
	msgbox FuchsiaMart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaMart_Text_Fisher:
	.string "The old Safari Zone had way better\n"
	.string "souvenirs...$"

FuchsiaMart_Text_CooltrainerF:
	.string "The old Safari Zone Warden's \n"
	.string "granddaughter lives in town.$"
