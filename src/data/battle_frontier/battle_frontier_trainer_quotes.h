// Dialogue selected from the user-provided XY/ORAS Maison quote transcriptions.
// Longer lines are trimmed or reflowed to fit the two-line facility text box.
static const struct FacilityTrainerQuote sYouthQuotes[] =
{
    {
        .before = COMPOUND_STRING("Snicker snicker..."),
        .win = COMPOUND_STRING("Snicker snicker!"),
        .lose = COMPOUND_STRING("Sniffle sniffle..."),
    },
    {
        .before = COMPOUND_STRING("I am the hero!\nI refuse to lose!"),
        .win = COMPOUND_STRING("I AM the hero!\nI beat a villain!"),
        .lose = COMPOUND_STRING("A hero never loses.\nA hero never dies."),
    },
    {
        .before = COMPOUND_STRING("All right! Let's go!"),
        .win = COMPOUND_STRING("Yahoo! Ya-hoooooo!\nI did it! I won again!"),
        .lose = COMPOUND_STRING("No! I lost!"),
    },
    {
        .before = COMPOUND_STRING("Ma! Pa! Watch me!\nI'll do my best!"),
        .win = COMPOUND_STRING("Ma! Pa! Were you watching?\nI was so strong!"),
        .lose = COMPOUND_STRING("Ma, Pa... I lost...\nGet revenge for me..."),
    },
};

static const struct FacilityTrainerQuote sSchoolQuotes[] =
{
    {
        .before = COMPOUND_STRING("Grumble, grumble..."),
        .win = COMPOUND_STRING("Grumble, grumble...\nHuh? Did I win?"),
        .lose = COMPOUND_STRING("Grumble, grumble...\nOh? Was that it?"),
    },
    {
        .before = COMPOUND_STRING("...Heehee. I'm confident in\nmy calculations and analysis."),
        .win = COMPOUND_STRING("Heheh. Exactly as I planned...\nThere's no way I would lose."),
        .lose = COMPOUND_STRING("Ohhhh... Perhaps calculation\nis no match for chance..."),
    },
    {
        .before = COMPOUND_STRING("I came here to goof off.\nI don't want to cram..."),
        .win = COMPOUND_STRING("I can't lose now...\nI don't want to study!"),
        .lose = COMPOUND_STRING("No! I don't want to go home!\nI don't want to study!"),
    },
    {
        .before = COMPOUND_STRING("Mwahahahaha... Please lend me\na hand for my experiment."),
        .win = COMPOUND_STRING("Mwahahaha... Yes, I did it!\nThe experiment was a success."),
        .lose = COMPOUND_STRING("Ho-hum. This is not good...\nThe experiment was a failure."),
    },
};

static const struct FacilityTrainerQuote sWealthQuotes[] =
{
    {
        .before = COMPOUND_STRING("Ahahaha!"),
        .win = COMPOUND_STRING("Ahahaha!!!"),
        .lose = COMPOUND_STRING("Ahaha-argh..."),
    },
    {
        .before = COMPOUND_STRING("Chosen Trainers will choose\nchosen POKéMON."),
        .win = COMPOUND_STRING("So it seems victory\nhas chosen me."),
        .lose = COMPOUND_STRING("It seems I have been\nchosen to lose..."),
    },
    {
        .before = COMPOUND_STRING("Yes! I'm a Rich Boy!"),
        .win = COMPOUND_STRING("Good-bye! You've been beaten\nby a Rich Boy!"),
        .lose = COMPOUND_STRING("Thank you! Merci bien!\nYou've beat a Rich Boy!"),
    },
    {
        .before = COMPOUND_STRING("Let me be brief.\nYou cannot win against me."),
        .win = COMPOUND_STRING("You cannot win,\nbecause you are very weak."),
        .lose = COMPOUND_STRING("Hummmm... You are good.\nYou are really pretty good."),
    },
};

static const struct FacilityTrainerQuote sBeautyQuotes[] =
{
    {
        .before = COMPOUND_STRING("My last ever battle...\nLet's view this match that way."),
        .win = COMPOUND_STRING("We will meet again someday...\nHeh. If only that were true..."),
        .lose = COMPOUND_STRING("It's been fun... Let's have\nanother last battle someday."),
    },
    {
        .before = COMPOUND_STRING("Isn't that nice...\nYou're still a kid..."),
        .win = COMPOUND_STRING("I've become a cynical adult,\nso I even cheat in battles."),
        .lose = COMPOUND_STRING("I was so innocent back then...\nWhere has that girl gone?"),
    },
    {
        .before = COMPOUND_STRING("Ready for the big game?\nGot your cap on straight?"),
        .win = COMPOUND_STRING("My oh my! My POKéMON\nknocked it out of the park!"),
        .lose = COMPOUND_STRING("Hey, another out. So what?\nWe'll come back!"),
    },
    {
        .before = COMPOUND_STRING("Hey there, Trainer! Do you\nthink I'm a grown-up?"),
        .win = COMPOUND_STRING("Tee hee... I won because\nI'm a grown-up!"),
        .lose = COMPOUND_STRING("Tee hee! My mom did my makeup!\nI'm actually only seven!"),
    },
};

static const struct FacilityTrainerQuote sVeteranQuotes[] =
{
    {
        .before = COMPOUND_STRING("Oh... Trainer... Isn't it\ntime...for a battle?"),
        .win = COMPOUND_STRING("Oh... Trainer... Isn't it\ntime...for a battle?"),
        .lose = COMPOUND_STRING("Oh... Trainer... Isn't it\ntime...for a battle?"),
    },
    {
        .before = COMPOUND_STRING("A true Gentleman's heart\nnever wavers in battle."),
        .win = COMPOUND_STRING("Ha... Snicker snicker...\nI can't...stop laughing..."),
        .lose = COMPOUND_STRING("Ooh... Ooh...\nI can't...stop crying..."),
    },
    {
        .before = COMPOUND_STRING("I will evaluate your ability."),
        .win = COMPOUND_STRING("As a Trainer, you are at\nthe level of a Preschooler."),
        .lose = COMPOUND_STRING("As a Trainer, you are at\nthe level of a Poké Fan."),
    },
    {
        .before = COMPOUND_STRING("Let me be brief.\nYou cannot win against me."),
        .win = COMPOUND_STRING("You cannot win,\nbecause you are very weak."),
        .lose = COMPOUND_STRING("Hummmm... You are good.\nYou are really pretty good."),
    },
};

static const struct FacilityTrainerQuote sAceQuotes[] =
{
    {
        .before = COMPOUND_STRING("Muwahaha! My legend of\ninvincibility begins with you!"),
        .win = COMPOUND_STRING("I'm completely invincible!\nMy legend begins here!"),
        .lose = COMPOUND_STRING("Ha... Are you telling me that\nyour legend just started?"),
    },
    {
        .before = COMPOUND_STRING("Halt at once! You there!\nLet us cross lances!"),
        .win = COMPOUND_STRING("Trainer, you are at my mercy!"),
        .lose = COMPOUND_STRING("Trainer, I yield!\nPlease spare me!"),
    },
    {
        .before = COMPOUND_STRING("The main character of this\nstory... I'll tell you who!"),
        .win = COMPOUND_STRING("The main character is me!\nYou are just an extra!"),
        .lose = COMPOUND_STRING("Of course, you are\nthe main character!"),
    },
    {
        .before = COMPOUND_STRING("Let me stop your\nwinning streak here."),
        .win = COMPOUND_STRING("You still have much to learn.\nLet me give you a crash course!"),
        .lose = COMPOUND_STRING("You didn't win alone.\nYour POKéMON helped you."),
    },
};

static const struct FacilityTrainerQuote sMartialQuotes[] =
{
    {
        .before = COMPOUND_STRING("Yo!"),
        .win = COMPOUND_STRING("Yo! Yo! Yo!"),
        .lose = COMPOUND_STRING("Yo!"),
    },
    {
        .before = COMPOUND_STRING("Are you ready?\nI'm taking my gloves off."),
        .win = COMPOUND_STRING("You're not even in my league.\nThis is like bullying."),
        .lose = COMPOUND_STRING("Aww... I cannot believe I lost!\nWho are you?!"),
    },
    {
        .before = COMPOUND_STRING("Let's have a fun battle!\nNo hard feelings!"),
        .win = COMPOUND_STRING("Don't look so down!\nI just happened to get lucky!"),
        .lose = COMPOUND_STRING("Heh..."),
    },
    {
        .before = COMPOUND_STRING("I praise your courage\nin challenging me!"),
        .win = COMPOUND_STRING("I did not have to use my\nstrongest kick on you."),
        .lose = COMPOUND_STRING("My strong kick didn't help\na bit."),
    },
};

static const struct FacilityTrainerQuote sMysticQuotes[] =
{
    {
        .before = COMPOUND_STRING("...Stay away."),
        .win = COMPOUND_STRING("...Go away."),
        .lose = COMPOUND_STRING("...Bye."),
    },
    {
        .before = COMPOUND_STRING("My Fairy says\nto take you out!"),
        .win = COMPOUND_STRING("My Fairy told me to do it!\nIt's all my Fairy's fault!"),
        .lose = COMPOUND_STRING("My Fairy says that\nyou're crazy dangerous!"),
    },
    {
        .before = COMPOUND_STRING("Hi! Focus!"),
        .win = COMPOUND_STRING("Fooooo!"),
        .lose = COMPOUND_STRING("Eeeeek!"),
    },
    {
        .before = COMPOUND_STRING("Heh-heh-heh. If you lose,\nI'll turn you into a POKéMON."),
        .win = COMPOUND_STRING("Heh-heh-heh. From today on,\nyou are already a POKéMON!"),
        .lose = COMPOUND_STRING("Next time, I will turn you\ninto a POKéMON with my power."),
    },
};

static const struct FacilityTrainerQuote sNatureQuotes[] =
{
    {
        .before = COMPOUND_STRING("There's a lot that goes into\nbeing a POKéMON Breeder."),
        .win = COMPOUND_STRING("The most fun part is getting\nclose to POKéMON."),
        .lose = COMPOUND_STRING("The hardest part is saying\nfarewell to POKéMON."),
    },
    {
        .before = COMPOUND_STRING("I'm a Gardener, but I'm good\nat POKéMON battles, too."),
        .win = COMPOUND_STRING("Maybe I'll try to become\nthe Champion."),
        .lose = COMPOUND_STRING("I'm a Gardener, so my real\njob is gardening."),
    },
    {
        .before = COMPOUND_STRING("I will test the POKéMON\nyou have been training."),
        .win = COMPOUND_STRING("Bah! Is that the best you can\ndo? I expected more..."),
        .lose = COMPOUND_STRING("Wow! You're amazing! You've\ntrained some great POKéMON!"),
    },
    {
        .before = COMPOUND_STRING("I made them too strong.\nThey are beyond my control..."),
        .win = COMPOUND_STRING("It's all over now...\nNobody can stop them..."),
        .lose = COMPOUND_STRING("Finally, they calmed down...\nYou've saved me. Thank you!"),
    },
};

static const struct FacilityTrainerQuote sTravelerQuotes[] =
{
    {
        .before = COMPOUND_STRING("Lalalala... Lalalala...\nI am a loner..."),
        .win = COMPOUND_STRING("Lalalala... Lalalala...\nDrifting like clouds..."),
        .lose = COMPOUND_STRING("Lalalala... Lalalala...\nTill we meet again..."),
    },
    {
        .before = COMPOUND_STRING("I am no mere Hiker.\nCall me an alpinist."),
        .win = COMPOUND_STRING("A mountain maniac like me\nis called an alpinist."),
        .lose = COMPOUND_STRING("A specialist in mountains.\nThat's an alpinist."),
    },
    {
        .before = COMPOUND_STRING("Harrumph! Harooo!"),
        .win = COMPOUND_STRING("Harooo!"),
        .lose = COMPOUND_STRING("Harrumph!!"),
    },
    {
        .before = COMPOUND_STRING("Let's take it easy with\nPOKéMON and with life."),
        .win = COMPOUND_STRING("It's OK to bust your tail.\nBut you need breathing room."),
        .lose = COMPOUND_STRING("No problem. No problem.\nI'll have another chance."),
    },
};

static const struct FacilityTrainerQuote sWaterQuotes[] =
{
    {
        .before = COMPOUND_STRING("This is Rough Skin, isn't it?!\nRain Dish, Rain Dish?"),
        .win = COMPOUND_STRING("It's not Rough Skin!\nRain Dish, Rain Dish."),
        .lose = COMPOUND_STRING("This is Rough Skin, isn't it?!\nRain Dish, Rain Dish..."),
    },
    {
        .before = COMPOUND_STRING("The weather's too awful\nfor me to work!"),
        .win = COMPOUND_STRING("Whoa! I'm in a Sunny Day\nkind of mood!!"),
        .lose = COMPOUND_STRING("If only my Ability\nwere Rain Dish..."),
    },
    {
        .before = COMPOUND_STRING("The clear blue water!\nThe beach! All the bikinis!"),
        .win = COMPOUND_STRING("What makes this place a resort?\nOnly serious Trainers are here!"),
        .lose = COMPOUND_STRING("This isn't a resort--it's\ntorture! Battles everywhere!"),
    },
};

static const struct FacilityTrainerQuote sAthleteQuotes[] =
{
    {
        .before = COMPOUND_STRING("Muwahaha! My legend of\ninvincibility begins with you!"),
        .win = COMPOUND_STRING("I'm completely invincible!\nMy legend begins here!"),
        .lose = COMPOUND_STRING("Ha... Are you telling me that\nyour legend just started?"),
    },
    {
        .before = COMPOUND_STRING("My strategy is to deceive\nmy opponents with my speed."),
        .win = COMPOUND_STRING("Ahaha... How was it?\nI bet that made you dizzy."),
        .lose = COMPOUND_STRING("How could you be quicker?\nWhat are you wearing?"),
    },
    {
        .before = COMPOUND_STRING("There are no brakes\non MY skates!"),
        .win = COMPOUND_STRING("I won't stop! I can't stop!\nThat's just the way I roll!"),
        .lose = COMPOUND_STRING("They've gotta be defective!\nSomeone! Anyone! STOP ME!"),
    },
    {
        .before = COMPOUND_STRING("Let's work up a good sweat\ntogether, right?"),
        .win = COMPOUND_STRING("Hey, don't sweat it...\nSometimes you've gotta let go."),
        .lose = COMPOUND_STRING("You had me sweating bullets!\nThat's what being young is!"),
    },
};

static const struct FacilityTrainerQuote sEnthusiastQuotes[] =
{
    {
        .before = COMPOUND_STRING("Listen, I love POKéMON\nmore than life itself!"),
        .win = COMPOUND_STRING("I'll be a POKéMON\nin my next life."),
        .lose = COMPOUND_STRING("I love your POKéMON, too!\nPlease, let me pet them!"),
    },
    {
        .before = COMPOUND_STRING("Want to see the POKéMON\nI am proudest of?"),
        .win = COMPOUND_STRING("What do you think about\nmy dear POKéMON? Great, right?"),
        .lose = COMPOUND_STRING("Oh my goodness!\nMy poor POKéMON..."),
    },
    {
        .before = COMPOUND_STRING("I think I am a Poké Fan,\ntherefore I am a Poké Fan."),
        .win = COMPOUND_STRING("The Poké Fan is power."),
        .lose = COMPOUND_STRING("Remember this:\nI am a Poké Fan."),
    },
    {
        .before = COMPOUND_STRING("Join the POKéMON Fan Club!\nYour life will be happy!"),
        .win = COMPOUND_STRING("Join the POKéMON Fan Club!\nYou'll be strong, like me!"),
        .lose = COMPOUND_STRING("Join the POKéMON Fan Club!\nYour life will be saved!"),
    },
};

static const struct FacilityTrainerQuote sPerformerQuotes[] =
{
    {
        .before = COMPOUND_STRING("A battle with me is a test\nof your aesthetic sensibility."),
        .win = COMPOUND_STRING("Hunnh... Not bad...\nYou've got a surreal side..."),
        .lose = COMPOUND_STRING("Hunnh... Not bad...\nYou've got a realistic side..."),
    },
    {
        .before = COMPOUND_STRING("Every time a POKéMON moves,\nmy heart trembles!"),
        .win = COMPOUND_STRING("Nothing stirs the soul\nlike POKéMON moves."),
        .lose = COMPOUND_STRING("POKéMON moves are so beautiful!\nI could almost faint!"),
    },
    {
        .before = COMPOUND_STRING("My POKéMON will trump yours!\nYou can bet on losing!"),
        .win = COMPOUND_STRING("All right! Victory is mine!\nFortune is smiling on me!"),
        .lose = COMPOUND_STRING("Ahh... I'm flat broke...\nI've got nothing left..."),
    },
    {
        .before = COMPOUND_STRING("All right, then. I'll watch.\nLet your passions run wild!"),
        .win = COMPOUND_STRING("What? You're done already?\nI'll have none of that!"),
        .lose = COMPOUND_STRING("Are you sure? Don't you think\nyou could keep going?"),
    },
};

static const struct FacilityTrainerQuote sBreederQuotes[] =
{
    {
        .before = COMPOUND_STRING("There's a lot that goes into\nbeing a POKéMON Breeder."),
        .win = COMPOUND_STRING("The most fun part is getting\nclose to POKéMON."),
        .lose = COMPOUND_STRING("The hardest part is saying\nfarewell to POKéMON."),
    },
    {
        .before = COMPOUND_STRING("I made them too strong.\nThey are beyond my control..."),
        .win = COMPOUND_STRING("It's all over now...\nNobody can stop them..."),
        .lose = COMPOUND_STRING("Finally, they calmed down...\nYou've saved me. Thank you!"),
    },
    {
        .before = COMPOUND_STRING("I am the top Breeder.\nI can tame any kind of POKéMON."),
        .win = COMPOUND_STRING("You see? My POKéMON are\nvery loyal to me, aren't they?"),
        .lose = COMPOUND_STRING("They are too attached to me.\nThey are not fit for battling."),
    },
    {
        .before = COMPOUND_STRING("I will test the POKéMON\nyou have been training."),
        .win = COMPOUND_STRING("Bah! Is that the best you can\ndo? I expected more..."),
        .lose = COMPOUND_STRING("Wow! You're amazing! You've\ntrained some great POKéMON!"),
    },
};

enum FacilityQuotePoolId
{
    FACILITY_QUOTE_POOL_NONE,
    FACILITY_QUOTE_POOL_YOUTH,
    FACILITY_QUOTE_POOL_SCHOOL,
    FACILITY_QUOTE_POOL_WEALTH,
    FACILITY_QUOTE_POOL_BEAUTY,
    FACILITY_QUOTE_POOL_VETERAN,
    FACILITY_QUOTE_POOL_ACE,
    FACILITY_QUOTE_POOL_MARTIAL,
    FACILITY_QUOTE_POOL_MYSTIC,
    FACILITY_QUOTE_POOL_NATURE,
    FACILITY_QUOTE_POOL_TRAVELER,
    FACILITY_QUOTE_POOL_WATER,
    FACILITY_QUOTE_POOL_ATHLETE,
    FACILITY_QUOTE_POOL_ENTHUSIAST,
    FACILITY_QUOTE_POOL_PERFORMER,
    FACILITY_QUOTE_POOL_BREEDER,
};

#define QUOTE_POOL(quotes_)             \
    {                                   \
        .quotes = quotes_,              \
        .count = ARRAY_COUNT(quotes_),  \
    }

static const struct FacilityTrainerQuotePool sFacilityTrainerQuotePools[] =
{
    [FACILITY_QUOTE_POOL_YOUTH] = QUOTE_POOL(sYouthQuotes),
    [FACILITY_QUOTE_POOL_SCHOOL] = QUOTE_POOL(sSchoolQuotes),
    [FACILITY_QUOTE_POOL_WEALTH] = QUOTE_POOL(sWealthQuotes),
    [FACILITY_QUOTE_POOL_BEAUTY] = QUOTE_POOL(sBeautyQuotes),
    [FACILITY_QUOTE_POOL_VETERAN] = QUOTE_POOL(sVeteranQuotes),
    [FACILITY_QUOTE_POOL_ACE] = QUOTE_POOL(sAceQuotes),
    [FACILITY_QUOTE_POOL_MARTIAL] = QUOTE_POOL(sMartialQuotes),
    [FACILITY_QUOTE_POOL_MYSTIC] = QUOTE_POOL(sMysticQuotes),
    [FACILITY_QUOTE_POOL_NATURE] = QUOTE_POOL(sNatureQuotes),
    [FACILITY_QUOTE_POOL_TRAVELER] = QUOTE_POOL(sTravelerQuotes),
    [FACILITY_QUOTE_POOL_WATER] = QUOTE_POOL(sWaterQuotes),
    [FACILITY_QUOTE_POOL_ATHLETE] = QUOTE_POOL(sAthleteQuotes),
    [FACILITY_QUOTE_POOL_ENTHUSIAST] = QUOTE_POOL(sEnthusiastQuotes),
    [FACILITY_QUOTE_POOL_PERFORMER] = QUOTE_POOL(sPerformerQuotes),
    [FACILITY_QUOTE_POOL_BREEDER] = QUOTE_POOL(sBreederQuotes),
};

static const u8 sFacilityClassQuotePoolIds[FACILITY_CLASSES_COUNT] =
{
    [FACILITY_CLASS_HIKER] = FACILITY_QUOTE_POOL_TRAVELER,
    [FACILITY_CLASS_PKMN_BREEDER_F] = FACILITY_QUOTE_POOL_BREEDER,
    [FACILITY_CLASS_COOLTRAINER_M] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_BIRD_KEEPER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_COLLECTOR] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_SWIMMER_M] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_EXPERT_M] = FACILITY_QUOTE_POOL_VETERAN,
    [FACILITY_CLASS_BLACK_BELT] = FACILITY_QUOTE_POOL_MARTIAL,
    [FACILITY_CLASS_HEX_MANIAC] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_AROMA_LADY] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_RUIN_MANIAC] = FACILITY_QUOTE_POOL_TRAVELER,
    [FACILITY_CLASS_TUBER_F] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_TUBER_M] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_COOLTRAINER_F] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_LADY] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_BEAUTY] = FACILITY_QUOTE_POOL_BEAUTY,
    [FACILITY_CLASS_RICH_BOY] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_EXPERT_F] = FACILITY_QUOTE_POOL_VETERAN,
    [FACILITY_CLASS_POKEMANIAC] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_GUITARIST] = FACILITY_QUOTE_POOL_PERFORMER,
    [FACILITY_CLASS_KINDLER] = FACILITY_QUOTE_POOL_PERFORMER,
    [FACILITY_CLASS_CAMPER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_PICNICKER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_BUG_MANIAC] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_PSYCHIC_M] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_PSYCHIC_F] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_GENTLEMAN] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_SCHOOL_KID_M] = FACILITY_QUOTE_POOL_SCHOOL,
    [FACILITY_CLASS_SCHOOL_KID_F] = FACILITY_QUOTE_POOL_SCHOOL,
    [FACILITY_CLASS_POKEFAN_M] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_POKEFAN_F] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_YOUNGSTER] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_FISHERMAN] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_CYCLING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_CYCLING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_RUNNING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_RUNNING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_SWIMMING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_SWIMMING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_DRAGON_TAMER] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_NINJA_BOY] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_BATTLE_GIRL] = FACILITY_QUOTE_POOL_MARTIAL,
    [FACILITY_CLASS_PARASOL_LADY] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_SWIMMER_F] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_SAILOR] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_PKMN_BREEDER_M] = FACILITY_QUOTE_POOL_BREEDER,
    [FACILITY_CLASS_BUG_CATCHER] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_PKMN_RANGER_M] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_PKMN_RANGER_F] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_LASS] = FACILITY_QUOTE_POOL_YOUTH,
};

#undef QUOTE_POOL
