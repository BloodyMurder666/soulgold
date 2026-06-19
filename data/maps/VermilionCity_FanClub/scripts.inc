.set LOCALID_FAN_CLUB_CLEFAIRY_DOLL, 5

VermilionCity_FanClub_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "I'm the Chairman of the Pokémon\n"
	.string "Fan Club.\p"
	.string "I've raised over 150 Pokémon.\p"
	.string "I'm very fussy when it comes to\n"
	.string "Pokémon.\p"
	.string "Did you visit just to hear about\n"
	.string "my Pokémon?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "Good! Then listen up!\p"
	.string "So… my favorite Rapidash…\p"
	.string "It… cute… lovely… smart…\n"
	.string "unbearably…\l"
	.string "plus… amazing… oh… you think\l"
	.string "so?…\l"
	.string "Too much… wild… beautiful…\l"
	.string "kindly…\l"
	.string "love it!\p"
	.string "Hug it… when… sleeping… warm\n"
	.string "and cuddly…\l"
	.string "Oh, and… spectacular…\l"
	.string "ravishing… simply divine…\p"
	.string "Oops! Look at the time!\n"
	.string "I've kept you too long!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Thanks for hearing me out.\n"
	.string "I want you to have this!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "It's a Rare Candy that makes\n"
	.string "Pokémon stronger.\p"
	.string "I prefer making my Pokémon\n"
	.string "stronger by battling, so you\l"
	.string "can have it.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "Hello, {PLAYER}!\p"
	.string "Did you come see me about my\n"
	.string "Pokémon again?\p"
	.string "No? Oh… I had more tales to\n"
	.string "tell…$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "How disappointing…\p"
	.string "Come back if you want to listen.$"

PokemonFanClub_Text_Receptionist:
	.string "Our Chairman is very vocal when\n"
	.string "it comes to Pokémon…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "I love the way Clefairy waggles\n"
	.string "its finger when it's trying to\l"
	.string "use Metronome.\p"
	.string "It's so adorable!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "I love Clefairy, but I could\n"
	.string "never catch one.\p"
	.string "So I'm making do with a\n"
	.string "Poké Doll that I found.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Oh, I see now. The girl who lost\n"
	.string "this Poké Doll is sad…\p"
	.string "Ok. Could you take this Poké Doll\n"
	.string "back to that poor little girl?\p"
	.string "I'll befriend a real Clefairy on\n"
	.string "my own one day. No worries!$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "You watch. I'm going to get a\n"
	.string "real Clefairy as my friend.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "Look at my darling Bayleef!\p"
	.string "The leaf on its head is so cute!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "It's a Clefairy! Huh?\p"
	.string "Oh, right. It's a Clefairy Poké\n"
	.string "Doll.$"

PokemonFanClub_Text_Bayleef:
	.string "Bayleef: Li liif!$"

PokemonFanClub_Text_Listen:
	.string "Let's all listen politely to\n"
	.string "other trainers.$"

PokemonFanClub_Text_Bragging:
	.string "If someone brags, brag right\n"
	.string "back!$"
