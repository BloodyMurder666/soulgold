#include "global.h"
#include "achievements.h"
#include "difficulty.h"
#include "event_data.h"
#include "item.h"
#include "pokedex.h"
#include "string_util.h"
#include "constants/difficulty.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/vars.h"

#define TRAINER_NONE_ACH 0xFFFF

static bool32 Achievement_PredicateHoennDexComplete(void);
static bool32 Achievement_PredicateNationalDexComplete(void);
static bool32 Achievement_PredicateBadge1(void);
static bool32 Achievement_PredicateBadge8(void);
static bool32 Achievement_PredicateBadge16(void);
static bool32 Achievement_PredicateCaughtLugia(void);
static bool32 Achievement_PredicateCaughtHoOh(void);
static bool32 Achievement_PredicateZephyrBadge(void);
static bool32 Achievement_PredicateHiveBadge(void);
static bool32 Achievement_PredicatePlainBadge(void);
static bool32 Achievement_PredicateFogBadge(void);
static bool32 Achievement_PredicateStormBadge(void);
static bool32 Achievement_PredicateMineralBadge(void);
static bool32 Achievement_PredicateGlacierBadge(void);
static bool32 Achievement_PredicateRisingBadge(void);
static bool32 Achievement_PredicateLetsGo(void);
static bool32 Achievement_PredicateRouteExperts(void);
static bool32 Achievement_PredicateCaughtCelebi(void);
static bool32 Achievement_PredicateCaughtArticuno(void);
static bool32 Achievement_PredicateCaughtMoltres(void);
static bool32 Achievement_PredicateCaughtZapdos(void);
static bool32 Achievement_PredicateCaughtRegice(void);
static bool32 Achievement_PredicateCaughtRegisteel(void);
static bool32 Achievement_PredicateCaughtRegirock(void);
static bool32 Achievement_PredicateCaughtRegigigas(void);
static bool32 Achievement_PredicateCaughtChienPao(void);
static bool32 Achievement_PredicateCaughtOgerpon(void);
static bool32 Achievement_PredicateCaughtMesprit(void);
static bool32 Achievement_PredicateCaughtUxie(void);
static bool32 Achievement_PredicateCaughtAzelf(void);
static bool32 Achievement_PredicateCaughtLapras(void);
static bool32 Achievement_PredicateCaughtVictini(void);
static u32 Achievement_CountCollectedTMs(void);
static u32 Achievement_GetBestRocketArcadeStreak(void);
static bool32 Achievement_IsHardRematchAchievement(enum AchievementId id);
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
static const u8 sText_AchZephyrBadgeName[] = _("Clipped wings");
static const u8 sText_AchZephyrBadgeDesc[] = _("Obtain Zephyrbadge\nby defeating Falkner.");
static const u8 sText_AchHiveBadgeName[] = _("Bug catcher");
static const u8 sText_AchHiveBadgeDesc[] = _("Obtain Hivebadge by defeating Bugsy.");
static const u8 sText_AchPlainBadgeName[] = _("Rolled over");
static const u8 sText_AchPlainBadgeDesc[] = _("Obtain Plainbadge\nby defeating Whitney.");
static const u8 sText_AchFogBadgeName[] = _("Lifting the fog");
static const u8 sText_AchFogBadgeDesc[] = _("Obtain Fogbadge by defeating Morty.");
static const u8 sText_AchStormBadgeName[] = _("Proven might");
static const u8 sText_AchStormBadgeDesc[] = _("Obtain Stormbadge by defeating Chuck.");
static const u8 sText_AchMineralBadgeName[] = _("Grace of steel");
static const u8 sText_AchMineralBadgeDesc[] = _("Obtain Mineralbadge\nby defeating Jasmine.");
static const u8 sText_AchGlacierBadgeName[] = _("Icebreaker");
static const u8 sText_AchGlacierBadgeDesc[] = _("Obtain Glacierbadge\nby defeating Pryce.");
static const u8 sText_AchRisingBadgeName[] = _("Risen to the top");
static const u8 sText_AchRisingBadgeDesc[] = _("Obtain Risingbadge\nafter defeating Clair.");
static const u8 sText_AchFalknerRematchName[] = _("Wings grounded");
static const u8 sText_AchFalknerRematchDesc[] = _("Defeat Falkner's rematch\non hard difficulty.");
static const u8 sText_AchBugsyRematchName[] = _("Bug squasher");
static const u8 sText_AchBugsyRematchDesc[] = _("Defeat Bugsy's rematch\non hard difficulty.");
static const u8 sText_AchWhitneyRematchName[] = _("Stomped twice");
static const u8 sText_AchWhitneyRematchDesc[] = _("Defeat Whitney's rematch\non hard difficulty.");
static const u8 sText_AchMortyRematchName[] = _("Ghost buster");
static const u8 sText_AchMortyRematchDesc[] = _("Defeat Morty's rematch\non hard difficulty.");
static const u8 sText_AchChuckRematchName[] = _("Luchador");
static const u8 sText_AchChuckRematchDesc[] = _("Defeat Chuck's rematch\non hard difficulty.");
static const u8 sText_AchJasmineRematchName[] = _("Steelmind");
static const u8 sText_AchJasmineRematchDesc[] = _("Defeat Jasmine's rematch\non hard difficulty.");
static const u8 sText_AchPryceRematchName[] = _("Cold Heart");
static const u8 sText_AchPryceRematchDesc[] = _("Defeat Pryce's rematch\non hard difficulty.");
static const u8 sText_AchClairRematchName[] = _("Dragon master");
static const u8 sText_AchClairRematchDesc[] = _("Defeat Clair's rematch\non hard difficulty.");
static const u8 sText_AchLetsGoName[] = _("Let's go!");
static const u8 sText_AchLetsGoDesc[] = _("Obtain Eevee Starter\nor Pikachu Starter.");
static const u8 sText_AchRouteExpertsName[] = _("Now I'm the expert");
static const u8 sText_AchRouteExpertsDesc[] = _("Defeat all route experts.");
static const u8 sText_AchHallOfFameDebutName[] = _("Champion");
static const u8 sText_AchHallOfFameDebutDesc[] = _("Enter the Hall of Fame\nfor the first time.");
static const u8 sText_AchCatchCelebiName[] = _("Forest guardian");
static const u8 sText_AchCatchCelebiDesc[] = _("Catch Celebi.");
static const u8 sText_AchCatchArticunoName[] = _("Frozen legend");
static const u8 sText_AchCatchArticunoDesc[] = _("Catch Articuno.");
static const u8 sText_AchCatchMoltresName[] = _("Flame legend");
static const u8 sText_AchCatchMoltresDesc[] = _("Catch Moltres.");
static const u8 sText_AchCatchZapdosName[] = _("Storm legend");
static const u8 sText_AchCatchZapdosDesc[] = _("Catch Zapdos.");
static const u8 sText_AchCatchRegiceName[] = _("Ice unsealed");
static const u8 sText_AchCatchRegiceDesc[] = _("Catch Regice.");
static const u8 sText_AchCatchRegisteelName[] = _("Steel unsealed");
static const u8 sText_AchCatchRegisteelDesc[] = _("Catch Registeel.");
static const u8 sText_AchCatchRegirockName[] = _("Rock unsealed");
static const u8 sText_AchCatchRegirockDesc[] = _("Catch Regirock.");
static const u8 sText_AchCatchRegigigasName[] = _("Ancient awakened");
static const u8 sText_AchCatchRegigigasDesc[] = _("Catch Regigigas.");
static const u8 sText_AchCatchChienPaoName[] = _("Ruinous blade");
static const u8 sText_AchCatchChienPaoDesc[] = _("Catch Chien-Pao.");
static const u8 sText_AchCatchOgerponName[] = _("Masked friend");
static const u8 sText_AchCatchOgerponDesc[] = _("Catch Ogerpon.");
static const u8 sText_AchCatchMespritName[] = _("Being of emotion");
static const u8 sText_AchCatchMespritDesc[] = _("Catch Mesprit.");
static const u8 sText_AchCatchUxieName[] = _("Being of knowledge");
static const u8 sText_AchCatchUxieDesc[] = _("Catch Uxie.");
static const u8 sText_AchCatchAzelfName[] = _("Being of willpower");
static const u8 sText_AchCatchAzelfDesc[] = _("Catch Azelf.");
static const u8 sText_AchCatchLaprasName[] = _("Gentle voyager");
static const u8 sText_AchCatchLaprasDesc[] = _("Catch Lapras.");
static const u8 sText_AchObtainVictiniName[] = _("Star of victory");
static const u8 sText_AchObtainVictiniDesc[] = _("Obtain Victini.");
static const u8 sText_AchDefeatStevenName[] = _("Mineralogy");
static const u8 sText_AchDefeatStevenDesc[] = _("Defeat Champion from another\nregion.");

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
    {ACH_JOHTO_BADGE_ZEPHYR, sText_AchZephyrBadgeName, sText_AchZephyrBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateZephyrBadge},
    {ACH_JOHTO_BADGE_HIVE, sText_AchHiveBadgeName, sText_AchHiveBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateHiveBadge},
    {ACH_JOHTO_BADGE_PLAIN, sText_AchPlainBadgeName, sText_AchPlainBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicatePlainBadge},
    {ACH_JOHTO_BADGE_FOG, sText_AchFogBadgeName, sText_AchFogBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateFogBadge},
    {ACH_JOHTO_BADGE_STORM, sText_AchStormBadgeName, sText_AchStormBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateStormBadge},
    {ACH_JOHTO_BADGE_MINERAL, sText_AchMineralBadgeName, sText_AchMineralBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateMineralBadge},
    {ACH_JOHTO_BADGE_GLACIER, sText_AchGlacierBadgeName, sText_AchGlacierBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateGlacierBadge},
    {ACH_JOHTO_BADGE_RISING, sText_AchRisingBadgeName, sText_AchRisingBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateRisingBadge},
    {ACH_HARD_REMATCH_FALKNER, sText_AchFalknerRematchName, sText_AchFalknerRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_FALKNER_2, NULL},
    {ACH_HARD_REMATCH_BUGSY, sText_AchBugsyRematchName, sText_AchBugsyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_BUGSY_2, NULL},
    {ACH_HARD_REMATCH_WHITNEY, sText_AchWhitneyRematchName, sText_AchWhitneyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_WHITNEY_2, NULL},
    {ACH_HARD_REMATCH_MORTY, sText_AchMortyRematchName, sText_AchMortyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_MORTY_2, NULL},
    {ACH_HARD_REMATCH_CHUCK, sText_AchChuckRematchName, sText_AchChuckRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_CHUCK_2, NULL},
    {ACH_HARD_REMATCH_JASMINE, sText_AchJasmineRematchName, sText_AchJasmineRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_JASMINE_2, NULL},
    {ACH_HARD_REMATCH_PRYCE, sText_AchPryceRematchName, sText_AchPryceRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_PRYCE_2, NULL},
    {ACH_HARD_REMATCH_CLAIR, sText_AchClairRematchName, sText_AchClairRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_CLAIR_2, NULL},
    {ACH_LETS_GO, sText_AchLetsGoName, sText_AchLetsGoDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateLetsGo},
    {ACH_ROUTE_EXPERTS, sText_AchRouteExpertsName, sText_AchRouteExpertsDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateRouteExperts},
    {ACH_HALL_OF_FAME_DEBUT, sText_AchHallOfFameDebutName, sText_AchHallOfFameDebutDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_CELEBI, sText_AchCatchCelebiName, sText_AchCatchCelebiDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtCelebi},
    {ACH_CATCH_ARTICUNO, sText_AchCatchArticunoName, sText_AchCatchArticunoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtArticuno},
    {ACH_CATCH_MOLTRES, sText_AchCatchMoltresName, sText_AchCatchMoltresDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMoltres},
    {ACH_CATCH_ZAPDOS, sText_AchCatchZapdosName, sText_AchCatchZapdosDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtZapdos},
    {ACH_CATCH_REGICE, sText_AchCatchRegiceName, sText_AchCatchRegiceDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegice},
    {ACH_CATCH_REGISTEEL, sText_AchCatchRegisteelName, sText_AchCatchRegisteelDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegisteel},
    {ACH_CATCH_REGIROCK, sText_AchCatchRegirockName, sText_AchCatchRegirockDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegirock},
    {ACH_CATCH_REGIGIGAS, sText_AchCatchRegigigasName, sText_AchCatchRegigigasDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegigigas},
    {ACH_CATCH_CHIEN_PAO, sText_AchCatchChienPaoName, sText_AchCatchChienPaoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtChienPao},
    {ACH_CATCH_OGERPON, sText_AchCatchOgerponName, sText_AchCatchOgerponDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtOgerpon},
    {ACH_CATCH_MESPRIT, sText_AchCatchMespritName, sText_AchCatchMespritDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMesprit},
    {ACH_CATCH_UXIE, sText_AchCatchUxieName, sText_AchCatchUxieDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtUxie},
    {ACH_CATCH_AZELF, sText_AchCatchAzelfName, sText_AchCatchAzelfDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtAzelf},
    {ACH_CATCH_LAPRAS, sText_AchCatchLaprasName, sText_AchCatchLaprasDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtLapras},
    {ACH_OBTAIN_VICTINI, sText_AchObtainVictiniName, sText_AchObtainVictiniDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtVictini},
    {ACH_DEFEAT_STEVEN, sText_AchDefeatStevenName, sText_AchDefeatStevenDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_STEVEN, NULL},
};

STATIC_ASSERT(ACH_COUNT <= ACHIEVEMENTS_MAX, AchievementCountWithinSaveBitmap);

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

static bool32 Achievement_PredicateBadgeFlag(u16 flag)
{
    return FlagGet(flag);
}

static bool32 Achievement_PredicateCaughtSpecies(u16 species)
{
    return GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT);
}

static bool32 Achievement_PredicateCaughtLugia(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_LUGIA);
}

static bool32 Achievement_PredicateCaughtHoOh(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_HO_OH);
}

static bool32 Achievement_PredicateZephyrBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE01_GET);
}

static bool32 Achievement_PredicateHiveBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE02_GET);
}

static bool32 Achievement_PredicatePlainBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE03_GET);
}

static bool32 Achievement_PredicateFogBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE04_GET);
}

static bool32 Achievement_PredicateStormBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE05_GET);
}

static bool32 Achievement_PredicateMineralBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE06_GET);
}

static bool32 Achievement_PredicateGlacierBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE07_GET);
}

static bool32 Achievement_PredicateRisingBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE08_GET);
}

static bool32 Achievement_PredicateLetsGo(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_EEVEE_STARTER)
        || Achievement_PredicateCaughtSpecies(SPECIES_PIKACHU_STARTER);
}

static bool32 Achievement_PredicateRouteExperts(void)
{
    return VarGet(VAR_ROUTE_EXPERTS_DEFEATED) >= 6;
}

static bool32 Achievement_PredicateCaughtCelebi(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_CELEBI);
}

static bool32 Achievement_PredicateCaughtArticuno(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_ARTICUNO);
}

static bool32 Achievement_PredicateCaughtMoltres(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MOLTRES);
}

static bool32 Achievement_PredicateCaughtZapdos(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_ZAPDOS);
}

static bool32 Achievement_PredicateCaughtRegice(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGICE);
}

static bool32 Achievement_PredicateCaughtRegisteel(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGISTEEL);
}

static bool32 Achievement_PredicateCaughtRegirock(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGIROCK);
}

static bool32 Achievement_PredicateCaughtRegigigas(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGIGIGAS);
}

static bool32 Achievement_PredicateCaughtChienPao(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_CHIEN_PAO);
}

static bool32 Achievement_PredicateCaughtOgerpon(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_OGERPON);
}

static bool32 Achievement_PredicateCaughtMesprit(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MESPRIT);
}

static bool32 Achievement_PredicateCaughtUxie(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_UXIE);
}

static bool32 Achievement_PredicateCaughtAzelf(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_AZELF);
}

static bool32 Achievement_PredicateCaughtLapras(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_LAPRAS);
}

static bool32 Achievement_PredicateCaughtVictini(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_VICTINI);
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

static bool32 Achievement_IsHardRematchAchievement(enum AchievementId id)
{
    switch (id)
    {
    case ACH_HARD_REMATCH_FALKNER:
    case ACH_HARD_REMATCH_BUGSY:
    case ACH_HARD_REMATCH_WHITNEY:
    case ACH_HARD_REMATCH_MORTY:
    case ACH_HARD_REMATCH_CHUCK:
    case ACH_HARD_REMATCH_JASMINE:
    case ACH_HARD_REMATCH_PRYCE:
    case ACH_HARD_REMATCH_CLAIR:
        return TRUE;
    default:
        return FALSE;
    }
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

void Achievement_UnlockHallOfFameDebut(void)
{
    Achievement_Unlock(ACH_HALL_OF_FAME_DEBUT);
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
        if (sAchievements[i].trainerId == trainerId
         && (!Achievement_IsHardRematchAchievement(sAchievements[i].id)
          || GetCurrentDifficultyLevel() == DIFFICULTY_HARD))
            Achievement_Unlock(sAchievements[i].id);
    }
    Achievement_CheckAll();
}
