OlivineCity_LighthouseTop_MapScripts::
# 2 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	goto_if_unset FLAG_HIDE_ZAPDOS, OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 6 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	setweather WEATHER_NONE
	return

OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
	return


Lighthousetop_Zapdos::
# 12 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	lock
# 13 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	faceplayer
# 14 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	legendaryencounter SPECIES_ZAPDOS, 50, LOCALID_LIGHTHOUSE_ZAPDOS, FLAG_HIDE_ZAPDOS
# 15 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	release
	end


Lighthouse_Engineer::
# 20 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	lock
# 21 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	faceplayer
# 22 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	msgbox Lighthouse_Engineer_Text_0
# 27 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	release
	end


Lighthouse_Engineer_Text_0:
# 22 "data/maps/OlivineCity_LighthouseTop/scripts.pory"
	.string "Some Pokémon broke the ladder to the\n"
	.string "top floor recently.\p"
	.string "I'm trying to fix it, but it\n"
	.string "will take some time.$"
