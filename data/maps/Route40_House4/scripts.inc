Route40_House4_MapScripts::
	.byte 0


AchievementGuy::
# 8 "data/maps/Route40_House4/scripts.pory"
	lock
# 9 "data/maps/Route40_House4/scripts.pory"
	faceplayer
# 11 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Text_0
# 17 "data/maps/Route40_House4/scripts.pory"
	special GetCompletedAchievementsCount
# 18 "data/maps/Route40_House4/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 19 "data/maps/Route40_House4/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_0
# 21 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 15
	goto_if_lt AchievementGuy_3
AchievementGuy_1:
# 25 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 30
	goto_if_lt AchievementGuy_8
AchievementGuy_6:
# 29 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 45
	goto_if_lt AchievementGuy_13
AchievementGuy_11:
# 33 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 60
	goto_if_lt AchievementGuy_18
AchievementGuy_16:
# 37 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 75
	goto_if_lt AchievementGuy_23
AchievementGuy_21:
# 41 "data/maps/Route40_House4/scripts.pory"
	compare VAR_ACHIEVEMENT_REWARD_MILESTONE, 90
	goto_if_lt AchievementGuy_28
AchievementGuy_26:
# 46 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 90
	goto_if_ge AchievementGuy_32
# 54 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 15
# 55 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 15
	goto_if_ge AchievementGuy_35
AchievementGuy_34:
# 58 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 30
	goto_if_ge AchievementGuy_38
AchievementGuy_37:
# 61 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 45
	goto_if_ge AchievementGuy_41
AchievementGuy_40:
# 64 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 60
	goto_if_ge AchievementGuy_44
AchievementGuy_43:
# 67 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 75
	goto_if_ge AchievementGuy_47
AchievementGuy_46:
# 71 "data/maps/Route40_House4/scripts.pory"
	copyvar VAR_TEMP_2, VAR_TEMP_1
# 72 "data/maps/Route40_House4/scripts.pory"
	subvar VAR_TEMP_2, VAR_TEMP_0
# 73 "data/maps/Route40_House4/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_2
# 74 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Text_2
# 80 "data/maps/Route40_House4/scripts.pory"
	release
	end

AchievementGuy_2:
# 23 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward15
	goto AchievementGuy_1

AchievementGuy_3:
# 22 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 15
	goto_if_ge AchievementGuy_2
	goto AchievementGuy_1

AchievementGuy_7:
# 27 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward30
	goto AchievementGuy_6

AchievementGuy_8:
# 26 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 30
	goto_if_ge AchievementGuy_7
	goto AchievementGuy_6

AchievementGuy_12:
# 31 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward45
	goto AchievementGuy_11

AchievementGuy_13:
# 30 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 45
	goto_if_ge AchievementGuy_12
	goto AchievementGuy_11

AchievementGuy_17:
# 35 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward60
	goto AchievementGuy_16

AchievementGuy_18:
# 34 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 60
	goto_if_ge AchievementGuy_17
	goto AchievementGuy_16

AchievementGuy_22:
# 39 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward75
	goto AchievementGuy_21

AchievementGuy_23:
# 38 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 75
	goto_if_ge AchievementGuy_22
	goto AchievementGuy_21

AchievementGuy_27:
# 43 "data/maps/Route40_House4/scripts.pory"
	goto AchievementGuy_Reward90
	goto AchievementGuy_26

AchievementGuy_28:
# 42 "data/maps/Route40_House4/scripts.pory"
	compare VAR_TEMP_0, 90
	goto_if_ge AchievementGuy_27
	goto AchievementGuy_26

AchievementGuy_32:
# 47 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Text_1
# 50 "data/maps/Route40_House4/scripts.pory"
	release
	end

AchievementGuy_35:
# 56 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 30
	goto AchievementGuy_34

AchievementGuy_38:
# 59 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 45
	goto AchievementGuy_37

AchievementGuy_41:
# 62 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 60
	goto AchievementGuy_40

AchievementGuy_44:
# 65 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 75
	goto AchievementGuy_43

AchievementGuy_47:
# 68 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_TEMP_1, 90
	goto AchievementGuy_46


keepUpTheGoodWork::
# 86 "data/maps/Route40_House4/scripts.pory"
	msgbox keepUpTheGoodWork_Text_0
# 89 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward15::
# 94 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward15_Text_0
# 101 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_SHIN_GENOME
# 102 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 15
# 103 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 104 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward30::
# 109 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward30_Text_0
# 116 "data/maps/Route40_House4/scripts.pory"
	givemon SPECIES_GRENINJA_BOND, 36
# 117 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 30
# 118 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 119 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward45::
# 124 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward45_Text_0
# 131 "data/maps/Route40_House4/scripts.pory"
	givemon SPECIES_POIPOLE, 5
# 132 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 45
# 133 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 134 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward60::
# 139 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward60_Text_0
# 145 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_N_SOLARIZER
# 146 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_N_LUNARIZER
# 147 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 60
# 148 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 149 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward75::
# 154 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward75_Text_0
# 161 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_REINS_OF_UNITY
# 162 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 75
# 163 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 164 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Reward90::
# 169 "data/maps/Route40_House4/scripts.pory"
	msgbox AchievementGuy_Reward90_Text_0
# 178 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_RUSTED_SWORD
# 179 "data/maps/Route40_House4/scripts.pory"
	giveitem ITEM_RUSTED_SHIELD
# 180 "data/maps/Route40_House4/scripts.pory"
	setvar VAR_ACHIEVEMENT_REWARD_MILESTONE, 90
# 181 "data/maps/Route40_House4/scripts.pory"
	goto keepUpTheGoodWork
# 182 "data/maps/Route40_House4/scripts.pory"
	release
	end


AchievementGuy_Text_0:
# 11 "data/maps/Route40_House4/scripts.pory"
	.string "I've achieved many things in my life.\n"
	.string "Now, I want to see what the younger\l"
	.string "generation can do.\p"
	.string "Let me have a closer look at you...$"

AchievementGuy_Text_1:
# 47 "data/maps/Route40_House4/scripts.pory"
	.string "You've achieved everything possible!\n"
	.string "There is nothing further I could bestow\l"
	.string "upon you, true master of Pokémon.$"

AchievementGuy_Text_2:
# 74 "data/maps/Route40_House4/scripts.pory"
	.string "Hmm... \n"
	.string "You've achieved {STR_VAR_1} things \l"
	.string "so far!\p"
	.string "If you were to achieve {STR_VAR_2} more\n"
	.string "things, I might have something for you!$"

keepUpTheGoodWork_Text_0:
# 86 "data/maps/Route40_House4/scripts.pory"
	.string "Never stop reaching for greater\n"
	.string "heights. I look forward to\l"
	.string "seeing what you will do next.$"

AchievementGuy_Reward15_Text_0:
# 94 "data/maps/Route40_House4/scripts.pory"
	.string "Hmm! \p"
	.string "You have at least {STR_VAR_1} \n"
	.string "achievements under your belt! \p"
	.string "A great start! I will bestow you this\n"
	.string "as a reward!$"

AchievementGuy_Reward30_Text_0:
# 109 "data/maps/Route40_House4/scripts.pory"
	.string "Excellent! \p"
	.string "You've achieved {STR_VAR_1}\n"
	.string "things and reached the next step\l"
	.string "on your journey! \p"
	.string "I have something nice for you!$"

AchievementGuy_Reward45_Text_0:
# 124 "data/maps/Route40_House4/scripts.pory"
	.string "Superb! \p"
	.string "You've achieved {STR_VAR_1}\n"
	.string "things and reached the next\l"
	.string "milestone!\p"
	.string "I have something nice for you!$"

AchievementGuy_Reward60_Text_0:
# 139 "data/maps/Route40_House4/scripts.pory"
	.string "Woah! You've achieved {STR_VAR_1}\n"
	.string "things and are known around\l"
	.string "the Johto!\p"
	.string "I have something for you\n"
	.string "to commemorate this achievement!$"

AchievementGuy_Reward75_Text_0:
# 154 "data/maps/Route40_House4/scripts.pory"
	.string "Incredible! \p"
	.string "You've achieved {STR_VAR_1}\n"
	.string "things and reached the next\l"
	.string "milestone!\p"
	.string "Another reward just for you!$"

AchievementGuy_Reward90_Text_0:
# 169 "data/maps/Route40_House4/scripts.pory"
	.string "Amazing! \p"
	.string "You've achieved {STR_VAR_1}\n"
	.string "things and reached my final\l"
	.string "milestone!\p"
	.string "These items are the only thing\n"
	.string "left to give. I have nothing\l"
	.string "further for you!$"
