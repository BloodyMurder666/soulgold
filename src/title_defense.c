#include "global.h"
#include "achievements.h"
#include "battle_setup.h"
#include "event_data.h"
#include "field_message_box.h"
#include "field_mugshot.h"
#include "random.h"
#include "title_defense.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/field_mugshots.h"
#include "constants/opponents.h"

static const u8 sText_FalknerIntro[] = _(
    "Falkner: A Champion can't stay\n"
    "grounded forever!\p"
    "My Pokémon and I came to see how\n"
    "high your strength can soar!$");
static const u8 sText_FalknerDefeat[] = _(
    "Your strength rose beyond even\n"
    "the reach of my wings!$");
static const u8 sText_FalknerFarewell[] = _(
    "Falkner: The title is still yours.\p"
    "Keep soaring, Champion. I'll train\n"
    "for our next flight!$");

static const u8 sText_BugsyIntro[] = _(
    "Bugsy: I've learned so much about\n"
    "Pokémon since our last battle!\p"
    "Today I'll prove that Bug Pokémon\n"
    "can challenge any Champion!$");
static const u8 sText_BugsyDefeat[] = _(
    "Amazing! Your strategy still has\n"
    "no obvious weakness!$");
static const u8 sText_BugsyFarewell[] = _(
    "Bugsy: That battle gave me lots of\n"
    "new research ideas!\p"
    "I'll discover a way to win yet!$");

static const u8 sText_WhitneyIntro[] = _(
    "Whitney: Being Champion looks like\n"
    "so much fun!\p"
    "But don't expect me to go easy on\n"
    "you just because we're friends!$");
static const u8 sText_WhitneyDefeat[] = _(
    "Waaah! You're still too strong!\p"
    "…Okay! That was a great battle!$");
static const u8 sText_WhitneyFarewell[] = _(
    "Whitney: You earned that win fair\n"
    "and square.\p"
    "I'll be back after more training!$");

static const u8 sText_MortyIntro[] = _(
    "Morty: I foresaw myself standing\n"
    "before the Champion one day.\p"
    "Let us discover whose vision of\n"
    "victory becomes real.$");
static const u8 sText_MortyDefeat[] = _(
    "So this was the future waiting\n"
    "beyond my vision…$");
static const u8 sText_MortyFarewell[] = _(
    "Morty: I didn't see this coming.\p"
    "Guess my visions still need work.$");

static const u8 sText_ChuckIntro[] = _(
    "Chuck: Hwaaah!\p"
    "I've trained my body and spirit for\n"
    "this chance at the title!\p"
    "Brace yourself, Champion!$");
static const u8 sText_ChuckDefeat[] = _(
    "Wahaha! Your strength shook me to\n"
    "my very core!$");
static const u8 sText_ChuckFarewell[] = _(
    "Chuck: A mighty victory!\p"
    "I'll train twice as hard and return\n"
    "for another bout!$");

static const u8 sText_JasmineIntro[] = _(
    "Jasmine: Your strength has always\n"
    "inspired me.\p"
    "Today, my steel-clad partners and I\n"
    "will test the Champion ourselves.$");
static const u8 sText_JasmineDefeat[] = _(
    "Your resolve was stronger than\n"
    "even the finest steel…$");
static const u8 sText_JasmineFarewell[] = _(
    "Jasmine: Thank you for a wonderful\n"
    "battle.\p"
    "I hope I can be even half as strong\n"
    "someday.$");

static const u8 sText_PryceIntro[] = _(
    "Pryce: Experience alone does not\n"
    "decide a battle.\p"
    "Show me the resolve that lets you\n"
    "carry the Champion's title.$");
static const u8 sText_PryceDefeat[] = _(
    "Your unwavering spirit thawed\n"
    "every obstacle before it.$");
static const u8 sText_PryceFarewell[] = _(
    "Pryce: Calm, but never lukewarm.\p"
    "That's a dangerous combination.$");

static const u8 sText_ClairIntro[] = _(
    "Clair: I've waited long enough for\n"
    "this rematch.\p"
    "This time, I'll defeat you and prove\n"
    "who the true dragon master is!$");
static const u8 sText_ClairDefeat[] = _(
    "No! Even at my strongest, you still\n"
    "stand above me?$");
static const u8 sText_ClairFarewell[] = _(
    "Clair: Hmph… Keep the title for now.\p"
    "Our rivalry is far from finished,\n"
    "Champion!$");

static const u8 sText_LanceIntro[] = _(
    "Lance: It is time I challenged the\n"
    "Champion I once welcomed here.\p"
    "My dragons and I have surpassed our\n"
    "old limits. Defend your title!$");
static const u8 sText_LanceDefeat[] = _(
    "Magnificent! You have grown beyond\n"
    "the Champion I remember.$");
static const u8 sText_LanceFarewell[] = _(
    "Lance: The League remains in worthy\n"
    "hands.\p"
    "I look forward to the day our paths\n"
    "cross in battle again.$");

static const u8 sText_StevenIntro[] = _(
    "Steven: I collect rare stones for a\n"
    "living, but a Champion's title is\p"
    "rarer than any of them.\n"
    "Let's see if it suits you.$");
static const u8 sText_StevenDefeat[] = _(
    "What a dazzling battle! Your team\n"
    "is a treasure beyond compare.$");
static const u8 sText_StevenFarewell[] = _(
    "Steven: Your title has lost none of\n"
    "its brilliance.\p"
    "Thank you for showing me its worth.$");

static const u8 sText_ElderLiIntro[] = _(
    "Elder Li: So, you've become Champion.\p"
    "Let's see if you're still as sharp\n"
    "without a Gym Leader's restraint.$");
static const u8 sText_ElderLiDefeat[] = _(
    "Future generations shine brighter\n"
    "than ever!$");
static const u8 sText_ElderLiFarewell[] = _(
    "Elder Li: A marvelous display.\p"
    "Go on, then! Johto's waiting to\n"
    "hear your name.$");

static const u8 sText_DirectorIntro[] = _(
    "Director: Ho ho ho! The Champion\n"
    "makes headlines wherever they go!\p"
    "Today, I'll show you the power of a\n"
    "former Elite Four member!$");
static const u8 sText_DirectorDefeat[] = _(
    "What a nostalgic feeling!$");
static const u8 sText_DirectorFarewell[] = _(
    "Director: That battle will be the\n"
    "talk of Johto for weeks!\p"
    "Now go on!$");

static const u8 sText_LeafIntro[] = _(
    "Leaf: Hey, Champion! Remember me?\p"
    "I told you I'd get the better of you\n"
    "next time, and that time is now!\p"
    "Get ready for a beatdown!$");
static const u8 sText_LeafDefeat[] = _(
    "Damn, you're good!\p"
    "I wasn't expecting that… again!$");
static const u8 sText_LeafFarewell[] = _(
    "Leaf: You're still a monster in\n"
    "battle!\p"
    "Keep the title warm for me. I'll be\n"
    "back for another shot! Laters!$");

const struct TitleDefenseChallenger gTitleDefenseNormalChallengers[] =
{
    { TRAINER_TITLE_DEFENSE_FALKNER, OBJ_EVENT_GFX_FALKNER, sText_FalknerIntro, sText_FalknerDefeat, sText_FalknerFarewell },
    { TRAINER_TITLE_DEFENSE_BUGSY,   OBJ_EVENT_GFX_BUGSY,   sText_BugsyIntro,   sText_BugsyDefeat,   sText_BugsyFarewell },
    { TRAINER_TITLE_DEFENSE_WHITNEY, OBJ_EVENT_GFX_WHITNEY, sText_WhitneyIntro, sText_WhitneyDefeat, sText_WhitneyFarewell },
    { TRAINER_TITLE_DEFENSE_MORTY,   OBJ_EVENT_GFX_MORTY,   sText_MortyIntro,   sText_MortyDefeat,   sText_MortyFarewell },
    { TRAINER_TITLE_DEFENSE_CHUCK,   OBJ_EVENT_GFX_CHUCK,   sText_ChuckIntro,   sText_ChuckDefeat,   sText_ChuckFarewell },
    { TRAINER_TITLE_DEFENSE_JASMINE, OBJ_EVENT_GFX_JASMINE, sText_JasmineIntro, sText_JasmineDefeat, sText_JasmineFarewell },
    { TRAINER_TITLE_DEFENSE_PRYCE,   OBJ_EVENT_GFX_PRYCE,   sText_PryceIntro,   sText_PryceDefeat,   sText_PryceFarewell },
    { TRAINER_TITLE_DEFENSE_CLAIR,   OBJ_EVENT_GFX_CLAIR,   sText_ClairIntro,   sText_ClairDefeat,   sText_ClairFarewell },
};

const struct TitleDefenseChallenger gTitleDefenseHardChallengers[] =
{
    { TRAINER_TITLE_DEFENSE_LANCE,    OBJ_EVENT_GFX_LANCE,     sText_LanceIntro,    sText_LanceDefeat,    sText_LanceFarewell },
    { TRAINER_TITLE_DEFENSE_STEVEN,   OBJ_EVENT_GFX_STEVEN,    sText_StevenIntro,   sText_StevenDefeat,   sText_StevenFarewell },
    { TRAINER_TITLE_DEFENSE_ELDER_LI, OBJ_EVENT_GFX_EXPERT_M,  sText_ElderLiIntro,  sText_ElderLiDefeat,  sText_ElderLiFarewell },
    { TRAINER_TITLE_DEFENSE_DIRECTOR, OBJ_EVENT_GFX_GENTLEMAN, sText_DirectorIntro, sText_DirectorDefeat, sText_DirectorFarewell },
    { TRAINER_TITLE_DEFENSE_LEAF,     OBJ_EVENT_GFX_LEAF,      sText_LeafIntro,     sText_LeafDefeat,     sText_LeafFarewell },
};

const u32 gTitleDefenseNormalChallengerCount = ARRAY_COUNT(gTitleDefenseNormalChallengers);
const u32 gTitleDefenseHardChallengerCount = ARRAY_COUNT(gTitleDefenseHardChallengers);

static const struct TitleDefenseChallenger *GetChallengerByPoolIndex(u32 index)
{
    if (index < gTitleDefenseNormalChallengerCount)
        return &gTitleDefenseNormalChallengers[index];

    index -= gTitleDefenseNormalChallengerCount;
    if (index < gTitleDefenseHardChallengerCount)
        return &gTitleDefenseHardChallengers[index];

    return NULL;
}

static const struct TitleDefenseChallenger *FindChallenger(u16 trainerId)
{
    u32 i;

    for (i = 0; i < gTitleDefenseNormalChallengerCount; i++)
    {
        if (gTitleDefenseNormalChallengers[i].trainerId == trainerId)
            return &gTitleDefenseNormalChallengers[i];
    }

    for (i = 0; i < gTitleDefenseHardChallengerCount; i++)
    {
        if (gTitleDefenseHardChallengers[i].trainerId == trainerId)
            return &gTitleDefenseHardChallengers[i];
    }

    return NULL;
}

const struct TitleDefenseChallenger *TitleDefense_GetCurrentChallenger(void)
{
    const struct TitleDefenseChallenger *challenger = FindChallenger(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER));

    if (challenger == NULL)
        challenger = &gTitleDefenseNormalChallengers[0];
    return challenger;
}

u16 TitleDefense_GetCurrentMugshotId(void)
{
    const struct TitleDefenseChallenger *challenger = TitleDefense_GetCurrentChallenger();

    if (challenger->trainerId == TRAINER_TITLE_DEFENSE_ELDER_LI)
        return MUGSHOT_ELDER_LI;

    return GetFieldMugshotIdByObjectGraphicsId(challenger->objectGfxId);
}

static void ShowChallengerMessage(const u8 *text)
{
    u16 mugshotId = TitleDefense_GetCurrentMugshotId();

    if (mugshotId == MUGSHOT_NONE)
        RemoveFieldMugshot();
    else
        _CreateFieldMugshot(mugshotId, EMOTE_NORMAL);
    ShowFieldMessage(text);
}

void TitleDefense_SelectChallenger(void)
{
    const struct TitleDefenseChallenger *challenger;
    u32 poolCount;
    u32 selectableCount;
    u32 selectedIndex;
    u32 i;
    u16 lastTrainerId = VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER);
    bool32 excludeLast = FALSE;

    poolCount = gTitleDefenseNormalChallengerCount;
    if (VarGet(VAR_TITLE_DEFENSE_WINS) >= 5)
        poolCount += gTitleDefenseHardChallengerCount;

    if (poolCount > 1)
    {
        for (i = 0; i < poolCount; i++)
        {
            const struct TitleDefenseChallenger *candidate = GetChallengerByPoolIndex(i);

            if (candidate->trainerId == lastTrainerId)
            {
                excludeLast = TRUE;
                break;
            }
        }
    }

    selectableCount = poolCount - excludeLast;
    selectedIndex = RandomUniform(RNG_TITLE_DEFENSE_CHALLENGER, 0, selectableCount - 1);
    challenger = NULL;
    for (i = 0; i < poolCount; i++)
    {
        const struct TitleDefenseChallenger *candidate = GetChallengerByPoolIndex(i);

        if (excludeLast && candidate->trainerId == lastTrainerId)
            continue;
        if (selectedIndex == 0)
        {
            challenger = candidate;
            break;
        }
        selectedIndex--;
    }

    if (challenger == NULL)
        challenger = &gTitleDefenseNormalChallengers[0];

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, challenger->trainerId);
    VarSet(VAR_OBJ_GFX_ID_0, challenger->objectGfxId);
}

void TitleDefense_ShowIntro(void)
{
    ShowChallengerMessage(TitleDefense_GetCurrentChallenger()->introText);
}

void TitleDefense_ShowFarewell(void)
{
    ShowChallengerMessage(TitleDefense_GetCurrentChallenger()->farewellText);
}

void TitleDefense_PrepareBattle(void)
{
    const struct TitleDefenseChallenger *challenger = TitleDefense_GetCurrentChallenger();

    InitTrainerBattleParameter();
    TRAINER_BATTLE_PARAM.mode = TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT;
    TRAINER_BATTLE_PARAM.playMusicA = TRUE;
    TRAINER_BATTLE_PARAM.opponentA = challenger->trainerId;
    TRAINER_BATTLE_PARAM.opponentB = TRAINER_NONE;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8 *)challenger->defeatText;
}

void TitleDefense_IncrementWins(void)
{
    u16 wins = VarGet(VAR_TITLE_DEFENSE_WINS);

    if (wins < MAX_u16)
        VarSet(VAR_TITLE_DEFENSE_WINS, wins + 1);
    Achievement_CheckCounter(ACH_COUNTER_TITLE_DEFENSE_WINS);
}
