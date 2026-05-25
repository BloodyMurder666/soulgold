#include "global.h"
#include "achievements.h"
#include "event_data.h"
#include "item.h"
#include "pokedex.h"
#include "string_util.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/opponents.h"
#include "constants/species.h"

#define TRAINER_NONE_ACH 0xFFFF

static bool32 Achievement_PredicateHoennDexComplete(void);
static bool32 Achievement_PredicateNationalDexComplete(void);
static bool32 Achievement_PredicateBadge1(void);
static bool32 Achievement_PredicateBadge8(void);
static bool32 Achievement_PredicateBadge16(void);
static bool32 Achievement_PredicateCaughtLugia(void);
static bool32 Achievement_PredicateCaughtHoOh(void);
static u32 Achievement_CountCollectedTMs(void);
static u32 Achievement_GetBestRocketArcadeStreak(void);
static void Achievement_QueuePopup(enum AchievementId id);

static const u8 sText_AchReceiveStarterName[] = _("Fresh Start");
static const u8 sText_AchReceiveStarterDesc[] = _("Receive your first partner Pokemon.");
static const u8 sText_AchFirstCaptureName[] = _("First Catch");
static const u8 sText_AchFirstCaptureDesc[] = _("Catch your first Pokemon with a Ball.");
static const u8 sText_AchFirstCriticalName[] = _("Sharp Start");
static const u8 sText_AchFirstCriticalDesc[] = _("Land your first critical hit.");
static const u8 sText_AchCritical100Name[] = _("Critical Thinker");
static const u8 sText_AchCritical100Desc[] = _("Land 100 critical hits.");
static const u8 sText_AchCapture100Name[] = _("Collector");
static const u8 sText_AchCapture100Desc[] = _("Catch 100 Pokemon.");
static const u8 sText_AchCaptureShinyName[] = _("Rare Spark");
static const u8 sText_AchCaptureShinyDesc[] = _("Catch a shiny Pokemon.");
static const u8 sText_AchDaycareEgg1Name[] = _("New Life");
static const u8 sText_AchDaycareEgg1Desc[] = _("Receive an Egg from Day Care.");
static const u8 sText_AchDaycareEggs100Name[] = _("Day Care Regular");
static const u8 sText_AchDaycareEggs100Desc[] = _("Receive 100 Day Care Eggs.");
static const u8 sText_AchHatchEggs100Name[] = _("Shell Breaker");
static const u8 sText_AchHatchEggs100Desc[] = _("Hatch 100 Eggs.");
static const u8 sText_AchTower50Name[] = _("Tower Climber");
static const u8 sText_AchTower50Desc[] = _("Reach a 50-win Battle Tower streak.");
static const u8 sText_AchTower100Name[] = _("Tower Legend");
static const u8 sText_AchTower100Desc[] = _("Reach a 100-win Battle Tower streak.");
static const u8 sText_AchHoennDexName[] = _("Johto Professor");
static const u8 sText_AchHoennDexDesc[] = _("Complete the Johto Pokedex.");
static const u8 sText_AchNationalDexName[] = _("National Professor");
static const u8 sText_AchNationalDexDesc[] = _("Complete the National Pokedex.");
static const u8 sText_AchBadge1Name[] = _("First Badge");
static const u8 sText_AchBadge1Desc[] = _("Earn your first Gym Badge.");
static const u8 sText_AchBadge8Name[] = _("League Ready");
static const u8 sText_AchBadge8Desc[] = _("Earn 8 Gym Badges.");
static const u8 sText_AchBadge16Name[] = _("World Tour");
static const u8 sText_AchBadge16Desc[] = _("Earn 16 Gym Badges.");
static const u8 sText_AchTm1Name[] = _("TM Student");
static const u8 sText_AchTm1Desc[] = _("Collect your first TM.");
static const u8 sText_AchTm20Name[] = _("TM Seeker");
static const u8 sText_AchTm20Desc[] = _("Collect 20 TMs.");
static const u8 sText_AchTm50Name[] = _("TM Expert");
static const u8 sText_AchTm50Desc[] = _("Collect 50 TMs.");
static const u8 sText_AchTm100Name[] = _("TM Master");
static const u8 sText_AchTm100Desc[] = _("Collect 100 TMs.");
static const u8 sText_AchPokedex200Name[] = _("Field Researcher");
static const u8 sText_AchPokedex200Desc[] = _("Register 200 caught Pokemon.");
static const u8 sText_AchPokedex350Name[] = _("Dex Specialist");
static const u8 sText_AchPokedex350Desc[] = _("Register 350 caught Pokemon.");
static const u8 sText_AchPokedex500Name[] = _("Living Archive");
static const u8 sText_AchPokedex500Desc[] = _("Register 500 caught Pokemon.");
static const u8 sText_AchRocketArcade50Name[] = _("Arcade Ace");
static const u8 sText_AchRocketArcade50Desc[] = _("Reach a 50-win Rocket Arcade streak.");
static const u8 sText_AchRocketArcade100Name[] = _("Arcade Legend");
static const u8 sText_AchRocketArcade100Desc[] = _("Reach a 100-win Rocket Arcade streak.");
static const u8 sText_AchCatchLugiaName[] = _("Sea Guardian");
static const u8 sText_AchCatchLugiaDesc[] = _("Catch Lugia.");
static const u8 sText_AchCatchHoOhName[] = _("Rainbow Guardian");
static const u8 sText_AchCatchHoOhDesc[] = _("Catch Ho-Oh.");

static const u8 sText_TierBronze[] = _("POKE BALL");
static const u8 sText_TierSilver[] = _("GREAT BALL");
static const u8 sText_TierGold[] = _("ULTRA BALL");
static const u8 sText_TierPlatinum[] = _("MASTER BALL");

static const struct Achievement sAchievements[] =
{
    {ACH_RECEIVE_STARTER, sText_AchReceiveStarterName, sText_AchReceiveStarterDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_FIRST_CAPTURE, sText_AchFirstCaptureName, sText_AchFirstCaptureDesc, ACH_TIER_BRONZE, ACH_COUNTER_CAPTURED_MONS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_FIRST_CRITICAL, sText_AchFirstCriticalName, sText_AchFirstCriticalDesc, ACH_TIER_BRONZE, ACH_COUNTER_CRITICAL_HITS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_CRITICAL_100, sText_AchCritical100Name, sText_AchCritical100Desc, ACH_TIER_SILVER, ACH_COUNTER_CRITICAL_HITS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_CAPTURE_100, sText_AchCapture100Name, sText_AchCapture100Desc, ACH_TIER_SILVER, ACH_COUNTER_CAPTURED_MONS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_CAPTURE_SHINY, sText_AchCaptureShinyName, sText_AchCaptureShinyDesc, ACH_TIER_GOLD, ACH_COUNTER_SHINY_CAPTURES, 1, TRAINER_NONE_ACH, NULL},
    {ACH_DAYCARE_EGG_1, sText_AchDaycareEgg1Name, sText_AchDaycareEgg1Desc, ACH_TIER_BRONZE, ACH_COUNTER_DAYCARE_EGGS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_DAYCARE_EGGS_100, sText_AchDaycareEggs100Name, sText_AchDaycareEggs100Desc, ACH_TIER_GOLD, ACH_COUNTER_DAYCARE_EGGS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_HATCH_EGGS_100, sText_AchHatchEggs100Name, sText_AchHatchEggs100Desc, ACH_TIER_GOLD, ACH_COUNTER_HATCHED_EGGS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_TOWER_50, sText_AchTower50Name, sText_AchTower50Desc, ACH_TIER_GOLD, ACH_COUNTER_BATTLE_TOWER_STREAK, 50, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_TOWER_100, sText_AchTower100Name, sText_AchTower100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_BATTLE_TOWER_STREAK, 100, TRAINER_NONE_ACH, NULL},
    {ACH_COMPLETE_HOENN_DEX, sText_AchHoennDexName, sText_AchHoennDexDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateHoennDexComplete},
    {ACH_COMPLETE_NATIONAL_DEX, sText_AchNationalDexName, sText_AchNationalDexDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateNationalDexComplete},
    {ACH_BADGE_1, sText_AchBadge1Name, sText_AchBadge1Desc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateBadge1},
    {ACH_BADGE_8, sText_AchBadge8Name, sText_AchBadge8Desc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateBadge8},
    {ACH_BADGE_16, sText_AchBadge16Name, sText_AchBadge16Desc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateBadge16},
    {ACH_TM_1, sText_AchTm1Name, sText_AchTm1Desc, ACH_TIER_BRONZE, ACH_COUNTER_TMS_COLLECTED, 1, TRAINER_NONE_ACH, NULL},
    {ACH_TM_20, sText_AchTm20Name, sText_AchTm20Desc, ACH_TIER_SILVER, ACH_COUNTER_TMS_COLLECTED, 20, TRAINER_NONE_ACH, NULL},
    {ACH_TM_50, sText_AchTm50Name, sText_AchTm50Desc, ACH_TIER_GOLD, ACH_COUNTER_TMS_COLLECTED, 50, TRAINER_NONE_ACH, NULL},
    {ACH_TM_100, sText_AchTm100Name, sText_AchTm100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_TMS_COLLECTED, 100, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_200, sText_AchPokedex200Name, sText_AchPokedex200Desc, ACH_TIER_SILVER, ACH_COUNTER_POKEDEX_CAUGHT, 200, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_350, sText_AchPokedex350Name, sText_AchPokedex350Desc, ACH_TIER_GOLD, ACH_COUNTER_POKEDEX_CAUGHT, 350, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_500, sText_AchPokedex500Name, sText_AchPokedex500Desc, ACH_TIER_PLATINUM, ACH_COUNTER_POKEDEX_CAUGHT, 500, TRAINER_NONE_ACH, NULL},
    {ACH_ROCKET_ARCADE_50, sText_AchRocketArcade50Name, sText_AchRocketArcade50Desc, ACH_TIER_GOLD, ACH_COUNTER_ROCKET_ARCADE_STREAK, 50, TRAINER_NONE_ACH, NULL},
    {ACH_ROCKET_ARCADE_100, sText_AchRocketArcade100Name, sText_AchRocketArcade100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_ROCKET_ARCADE_STREAK, 100, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_LUGIA, sText_AchCatchLugiaName, sText_AchCatchLugiaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtLugia},
    {ACH_CATCH_HO_OH, sText_AchCatchHoOhName, sText_AchCatchHoOhDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtHoOh},
};

static const u8 *const sTierLabels[] =
{
    [ACH_TIER_BRONZE] = sText_TierBronze,
    [ACH_TIER_SILVER] = sText_TierSilver,
    [ACH_TIER_GOLD] = sText_TierGold,
    [ACH_TIER_PLATINUM] = sText_TierPlatinum,
};

static const u16 sTierBallItems[] =
{
    [ACH_TIER_BRONZE] = ITEM_POKE_BALL,
    [ACH_TIER_SILVER] = ITEM_GREAT_BALL,
    [ACH_TIER_GOLD] = ITEM_ULTRA_BALL,
    [ACH_TIER_PLATINUM] = ITEM_MASTER_BALL,
};

void Achievement_EnsureSaveInitialized(void)
{
    if (gSaveBlock1Ptr->achievements.magic != ACHIEVEMENT_SAVE_MAGIC)
    {
        memset(&gSaveBlock1Ptr->achievements, 0, sizeof(gSaveBlock1Ptr->achievements));
        gSaveBlock1Ptr->achievements.magic = ACHIEVEMENT_SAVE_MAGIC;
    }
}

static bool32 Achievement_PredicateHoennDexComplete(void)
{
    return HasAllHoennMons();
}

static bool32 Achievement_PredicateNationalDexComplete(void)
{
    return HasAllMons();
}

static u8 Achievement_CountBadges(void)
{
    u8 i, count = 0;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (FlagGet(FLAG_BADGE01_GET + i))
            count++;
    }
    for (i = 0; i < 8; i++)
    {
        if (FlagGet(FLAG_BADGE09_GET + i))
            count++;
    }
    return count;
}

static bool32 Achievement_PredicateBadge1(void)
{
    return Achievement_CountBadges() >= 1;
}

static bool32 Achievement_PredicateBadge8(void)
{
    return Achievement_CountBadges() >= 8;
}

static bool32 Achievement_PredicateBadge16(void)
{
    return Achievement_CountBadges() >= 16;
}

static bool32 Achievement_PredicateCaughtLugia(void)
{
    return GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LUGIA), FLAG_GET_CAUGHT);
}

static bool32 Achievement_PredicateCaughtHoOh(void)
{
    return GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_HO_OH), FLAG_GET_CAUGHT);
}

static u32 Achievement_CountCollectedTMs(void)
{
    u16 i;
    u32 count = 0;

    for (i = 0; i < gBagPockets[POCKET_TM_HM].capacity; i++)
    {
        enum TMHMIndex index = GetItemTMHMIndex(GetBagItemId(POCKET_TM_HM, i));

        if (index > 0 && index <= NUM_TECHNICAL_MACHINES)
            count++;
    }
    return count;
}

static u32 Achievement_GetBestRocketArcadeStreak(void)
{
    u8 battleMode, lvlMode;
    u32 best = 0;

    for (battleMode = 0; battleMode < FRONTIER_MODE_COUNT; battleMode++)
    {
        for (lvlMode = 0; lvlMode < FRONTIER_LVL_MODE_COUNT; lvlMode++)
        {
            if (best < gSaveBlock2Ptr->frontier.arcadeRecordWinStreaks[battleMode][lvlMode])
                best = gSaveBlock2Ptr->frontier.arcadeRecordWinStreaks[battleMode][lvlMode];
        }
    }
    return best;
}

u16 Achievement_GetCount(void)
{
    Achievement_EnsureSaveInitialized();
    return ARRAY_COUNT(sAchievements);
}

const struct Achievement *Achievement_GetByIndex(u16 index)
{
    if (index >= ARRAY_COUNT(sAchievements))
        return NULL;
    return &sAchievements[index];
}

const struct Achievement *Achievement_GetById(enum AchievementId id)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        if (sAchievements[i].id == id)
            return &sAchievements[i];
    }
    return NULL;
}

const u8 *Achievement_GetTierLabel(enum AchievementTier tier)
{
    if (tier >= ARRAY_COUNT(sTierLabels))
        return sTierLabels[ACH_TIER_BRONZE];
    return sTierLabels[tier];
}

u16 Achievement_GetTierBallItem(enum AchievementTier tier)
{
    if (tier >= ARRAY_COUNT(sTierBallItems))
        return sTierBallItems[ACH_TIER_BRONZE];
    return sTierBallItems[tier];
}

bool32 Achievement_IsUnlocked(enum AchievementId id)
{
    if (id >= ACHIEVEMENTS_MAX)
        return FALSE;
    Achievement_EnsureSaveInitialized();
    return (gSaveBlock1Ptr->achievements.unlocked[id / 8] & (1 << (id % 8))) != 0;
}

u16 Achievement_CountUnlocked(void)
{
    u16 i, count = 0;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        if (Achievement_IsUnlocked(sAchievements[i].id))
            count++;
    }
    return count;
}

u32 Achievement_GetCounter(enum AchievementCounter counter)
{
    switch (counter)
    {
    case ACH_COUNTER_TMS_COLLECTED:
        return Achievement_CountCollectedTMs();
    case ACH_COUNTER_POKEDEX_CAUGHT:
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    case ACH_COUNTER_ROCKET_ARCADE_STREAK:
        return Achievement_GetBestRocketArcadeStreak();
    default:
        break;
    }

    if (counter >= ACH_COUNTER_COUNT)
        return 0;
    Achievement_EnsureSaveInitialized();
    return gSaveBlock1Ptr->achievements.counters[counter];
}

u32 Achievement_GetProgress(const struct Achievement *achievement)
{
    if (achievement == NULL)
        return 0;
    if (achievement->counter != ACH_COUNTER_NONE)
        return Achievement_GetCounter(achievement->counter);
    if (achievement->predicate != NULL && achievement->predicate())
        return 1;
    return Achievement_IsUnlocked(achievement->id) ? 1 : 0;
}

u32 Achievement_GetTarget(const struct Achievement *achievement)
{
    if (achievement == NULL)
        return 0;
    if (achievement->counter != ACH_COUNTER_NONE)
        return achievement->targetValue;
    return 1;
}

static void Achievement_QueuePopup(enum AchievementId id)
{
    u8 i;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ACHIEVEMENT_POPUP_QUEUE_SIZE; i++)
    {
        if (gSaveBlock1Ptr->achievements.popupQueue[i] == 0)
        {
            gSaveBlock1Ptr->achievements.popupQueue[i] = id + 1;
            return;
        }
    }
}

bool32 Achievement_Unlock(enum AchievementId id)
{
    if (id >= ACHIEVEMENTS_MAX || Achievement_GetById(id) == NULL || Achievement_IsUnlocked(id))
        return FALSE;

    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.unlocked[id / 8] |= (1 << (id % 8));
    Achievement_QueuePopup(id);
    return TRUE;
}

void Achievement_CheckAll(void)
{
    u16 i;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        const struct Achievement *achievement = &sAchievements[i];

        if (Achievement_IsUnlocked(achievement->id))
            continue;
        if (achievement->counter != ACH_COUNTER_NONE
         && Achievement_GetCounter(achievement->counter) >= achievement->targetValue)
            Achievement_Unlock(achievement->id);
        else if (achievement->predicate != NULL && achievement->predicate())
            Achievement_Unlock(achievement->id);
    }
}

void Achievement_IncrementCounter(enum AchievementCounter counter, u32 amount)
{
    if (counter >= ACH_COUNTER_COUNT)
        return;

    Achievement_EnsureSaveInitialized();
    if (UINT_MAX - gSaveBlock1Ptr->achievements.counters[counter] < amount)
        gSaveBlock1Ptr->achievements.counters[counter] = UINT_MAX;
    else
        gSaveBlock1Ptr->achievements.counters[counter] += amount;

    Achievement_CheckAll();
}

void Achievement_SetCounterMax(enum AchievementCounter counter, u32 value)
{
    if (counter >= ACH_COUNTER_COUNT)
        return;

    Achievement_EnsureSaveInitialized();
    if (gSaveBlock1Ptr->achievements.counters[counter] < value)
    {
        gSaveBlock1Ptr->achievements.counters[counter] = value;
        Achievement_CheckAll();
    }
}

void Achievement_OnTrainerDefeated(u16 trainerId)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        if (sAchievements[i].trainerId == trainerId)
            Achievement_Unlock(sAchievements[i].id);
    }
    Achievement_CheckAll();
}
