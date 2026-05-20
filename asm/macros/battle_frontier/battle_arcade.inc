@ Initialize the Rocket Arcade challenge
.macro arcade_init
	setvar VAR_0x8004, ARCADE_FUNC_INIT
	special CallBattleArcadeFunc
.endm

@ Get the value of some ARCADE_DATA_*. See GetArcadeData for the data types that can be retrieved
.macro arcade_get data:req
	setvar VAR_0x8004, ARCADE_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleArcadeFunc
.endm

@ Set some ARCADE_DATA_* to val. See SetArcadeData for the data types that can be set
.macro arcade_set data:req, val=0xFFFF
	setvar VAR_0x8004, ARCADE_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallBattleArcadeFunc
.endm

@ Save the game and set the challenge status
.macro arcade_save challengeStatus:req
	setvar VAR_0x8004, ARCADE_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleArcadeFunc
.endm

@ Loads the opponent's party
.macro arcade_generateopponentparty
	setvar VAR_0x8004, ARCADE_FUNC_GENERATE_OPPONENT
	special CallBattleArcadeFunc
.endm

@ Delete all the held items in the enemy's party
.macro arcade_takeenemyhelditems
	setvar VAR_0x8004, ARCADE_FUNC_TAKE_ENEMY_ITEMS
	special CallBattleArcadeFunc
.endm

@ Starts the actual game board
.macro arcade_playgameboard
	setvar VAR_0x8004, ARCADE_FUNC_PLAY_GAME_BOARD
	fadescreen FADE_TO_BLACK
	special CallBattleArcadeFunc
	waitstate
.endm

@ Clean up all the leftover remanents from the previous event
.macro arcade_eventcleanup
	setvar VAR_0x8004, ARCADE_FUNC_BATTLE_CLEAN_UP
	special CallBattleArcadeFunc
.endm

@ Increments the battle number and returns the new one. Also clears E-Reader trainer if defeated, and saves the current win streak
.macro arcade_setbattlewon
	setvar VAR_0x8004, ARCADE_FUNC_SET_BATTLE_WON
	special CallBattleArcadeFunc
.endm

@ Awards the pending Rocket Arcade money prize
.macro arcade_givepoints
	setvar VAR_0x8004, ARCADE_FUNC_GIVE_BATTLE_POINTS
	special CallBattleArcadeFunc
.endm

@ Buffers the current Rocket Arcade prize into STR_VAR_1
.macro arcade_bufferprize
	setvar VAR_0x8004, ARCADE_FUNC_BUFFER_PRIZE
	special CallBattleArcadeFunc
.endm

@ Awards the current Rocket Arcade prize and clears double-down state
.macro arcade_awardprize
	setvar VAR_0x8004, ARCADE_FUNC_AWARD_PRIZE
	special CallBattleArcadeFunc
.endm

@ Stores the current Rocket Arcade prize and marks the run as doubled down
.macro arcade_doubledown
	setvar VAR_0x8004, ARCADE_FUNC_DOUBLE_DOWN
	special CallBattleArcadeFunc
.endm

@ Clears the pending Rocket Arcade prize and double-down state
.macro arcade_clearprize
	setvar VAR_0x8004, ARCADE_FUNC_CLEAR_PRIZE
	special CallBattleArcadeFunc
.endm

@ Returns TRUE if Rocket Arcade is currently doubled down
.macro arcade_checkdoubledown
	setvar VAR_0x8004, ARCADE_FUNC_CHECK_DOUBLE_DOWN
	special CallBattleArcadeFunc
.endm

@ Check the number of types the player has previously won and sets VAR_RESULT to TRUE if the player has not have the appropriate symbol but has qualified for it
.macro arcade_checksymbol
	setvar VAR_0x8004, ARCADE_FUNC_CHECK_SYMBOL
	special CallBattleArcadeFunc
.endm

@ Looks at the player's streak and returns the print for that battle
.macro arcade_getprintfromstreak
	setvar VAR_0x8004, ARCADE_FUNC_GET_PRINT_FROM_STREAK
	special CallBattleArcadeFunc
.endm

@ Check to see if the Frontier Brain should be the next battle
.macro arcade_getbrainstatus
	setvar VAR_0x8004, ARCADE_FUNC_CHECK_BRAIN_STATUS
	special CallBattleArcadeFunc
.endm

@ Sets the Rocket Arcade brain object event
.macro arcade_setbrainobj
	setvar VAR_0x8004, ARCADE_FUNC_SET_BRAIN_OBJECT
	special CallBattleArcadeFunc
.endm

@ Shows the results window for the Arcade's chosen mode.
.macro arcade_results mode:req
	setvar VAR_0x8004, ARCADE_FUNC_RECORDS
	copyvar VAR_0x8005, \mode
	special CallBattleArcadeFunc
.endm

@ Delete all the held items in the player's party
.macro arcade_takeplayerhelditems
	setvar VAR_0x8004, ARCADE_FUNC_TAKE_PLAYER_HELD_ITEM
	special CallBattleArcadeFunc
.endm
