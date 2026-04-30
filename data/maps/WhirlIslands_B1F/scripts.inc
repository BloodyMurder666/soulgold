WhirlIslands_B1F_MapScripts::
	.byte 0

WhirlIslands_B1F_Trigger_Sunlight::
	setweather WEATHER_SUNNY
	doweather
	end

WhirlIslands_B1F_Trigger_Shade::
	setweather WEATHER_SHADE
	doweather
	end

WhirlIslands_B1F_Trigger_Rain::
	setweather WEATHER_RAIN
	doweather
	end

