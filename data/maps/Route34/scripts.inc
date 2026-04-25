.set LOCALID_ROUTE34_DAYCAREMAN, 12

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_Text_YoungsterSamuel_Seen:
	.string "Hey! I'm looking for Mankey!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Beaten by a passing stranger!$"

Route34_Text_YoungsterSamuel_After:
	.string "I'm going to train even harder.\p"
	.string "After all, I'm trying to become\n"
	.string "a Gym Leader.$"

Route34_Text_YoungsterIan_Seen:
	.string "I'm the best in my class at\n"
	.string "POKéMON.$"

Route34_Text_YoungsterIan_Beaten:
	.string "No! There are better trainers…$"

Route34_Text_YoungsterIan_After:
	.string "I'm trying hard so I can be the\n"
	.string "star in my class.$"

Route34_Text_CamperTodd_Seen:
	.string "I'm confident in my ability to\n"
	.string "raise POKéMON.\p"
	.string "Want to see?$"

Route34_Text_CamperTodd_Beaten:
	.string "Did I screw up my training?$"

Route34_Text_CamperTodd_After:
	.string "Maybe I should take one to Day-Care,\n"
	.string "or maybe use some items…$"

Route34_Text_PicnickerGina_Seen:
	.string "Are you a trainer?\p"
	.string "Let's have a practice battle.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh, no! I just can't win…$"

Route34_Text_PicnickerGina_After:
	.string "You're too strong to be a\n"
	.string "practice partner.$"

Route34_Text_OfficerKeith_Seen:
	.string "Who goes there?\n"
	.string "What are you up to?$"

Route34_Text_OfficerKeith_Win:
	.string "You're a tough little kid.$"

Route34_Text_OfficerKeith_After:
	.string "Yep, nothing wrong today.\p"
	.string "Be good and stay out of trouble.$"

Route34_Text_OfficerKeith_Daytime:
	.string "I'm on patrol for suspicious\n"
	.string "individuals.$"

Route34_Text_PokefanBrandon_Seen:
	.string "I just got my POKéMON back from\n"
	.string "Day-Care.\p"
	.string "Let's see how much stronger it got!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Why does it end this way?$"

Route34_Text_PokefanBrandon_After:
	.string "My POKéMON came back with new moves.\p"
	.string "That confounded me to no end!$"

Route34_Text_Sign_IlexForest:
	.string "Ilex Forest\n"
	.string "Through The Gate$"

Route34_Text_Sign_Route34:
	.string "Route 34\n"
	.string "Goldenrod City - Azalea Town\p"
	.string "Ilex Forest Somewhere Between$"

Route34_Text_TrainerTips:
	.string "Trainer Tips\p"
	.string "Berry trees grow new Berries\n"
	.string "several times a day.\p"
	.string "Note which trees bear which\n"
	.string "Berries.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "Irene: Kyaaah! Someone found us!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "Irene: Ohhh! You're too strong!$"

Route34_Text_CooltrainerIrene_After1:
	.string "Irene: My sister Kate will get you\n"
	.string "for this!$"

Route34_Text_CooltrainerIrene_After2:
	.string "Irene: Isn't this beach great?\p"
	.string "It's our secret little getaway!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "Jenn: You can't beat Irene and go\n"
	.string "unpunished!$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "Jenn: So sorry, Irene! Dear Sis!$"

Route34_Text_CooltrainerJenn_After1:
	.string "Jenn: Don't get cocky! My sister\n"
	.string "Kate is tough!$"

Route34_Text_CooltrainerJenn_After2:
	.string "Jenn: Sunlight makes your body\n"
	.string "stronger.$"

Route34_Text_CooltrainerKate_Seen:
	.string "Kate: You sure were mean to my\n"
	.string "little sisters!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "Kate: No! I can't believe I lost.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "Kate: You're too strong. I didn't\n"
	.string "stand a chance. Here, you deserve\n"
	.string "this.$"

Route34_Text_CooltrainerKate_After:
	.string "Kate: I'm sorry we jumped you.\p"
	.string "We never expected anyone to find\n"
	.string "us here. You sure startled us.$"


Route34_Text_Sign_DayCare:
	.string "Day-Care\p"
	.string "Let Us Raise Your POKéMON For You!$"
