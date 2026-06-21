#include "global.h"
#include "buenas_password.h"
#include "rtc.h"
#include "string_util.h"

#define BUENAS_PASSWORD_START_HOUR 18
#define BUENAS_PASSWORD_END_HOUR   24
#define BUENAS_PASSWORD_OPTIONS     3

enum BuenasPasswordGroup
{
    BUENA_PASSWORD_STARTERS,
    BUENA_PASSWORD_MEDICINE,
    BUENA_PASSWORD_BALLS,
    BUENA_PASSWORD_ROUTE_MONS,
    BUENA_PASSWORD_NIGHT_MONS,
    BUENA_PASSWORD_TOWNS,
    BUENA_PASSWORD_CATEGORIES,
    BUENA_PASSWORD_MOVES,
    BUENA_PASSWORD_X_ITEMS,
    BUENA_PASSWORD_RADIO_SHOWS,
    BUENA_PASSWORD_COUNT
};

static const u8 sText_Cyndaquil[] = _("Cyndaquil");
static const u8 sText_Totodile[] = _("Totodile");
static const u8 sText_Chikorita[] = _("Chikorita");
static const u8 sText_Potion[] = _("Potion");
static const u8 sText_Antidote[] = _("Antidote");
static const u8 sText_ParlyzHeal[] = _("Parlyz Heal");
static const u8 sText_PokeBall[] = _("Poke Ball");
static const u8 sText_GreatBall[] = _("Great Ball");
static const u8 sText_UltraBall[] = _("Ultra Ball");
static const u8 sText_Pikachu[] = _("Pikachu");
static const u8 sText_Rattata[] = _("Rattata");
static const u8 sText_Geodude[] = _("Geodude");
static const u8 sText_Hoothoot[] = _("Hoothoot");
static const u8 sText_Spinarak[] = _("Spinarak");
static const u8 sText_Drowzee[] = _("Drowzee");
static const u8 sText_NewBarkTown[] = _("New Bark Town");
static const u8 sText_CherrygroveCity[] = _("Cherrygrove City");
static const u8 sText_AzaleaTown[] = _("Azalea Town");
static const u8 sText_BugPokemon[] = _("Bug Pokemon");
static const u8 sText_BirdPokemon[] = _("Bird Pokemon");
static const u8 sText_GrassPokemon[] = _("Grass Pokemon");
static const u8 sText_Tackle[] = _("Tackle");
static const u8 sText_Growl[] = _("Growl");
static const u8 sText_MudSlap[] = _("Mud-Slap");
static const u8 sText_XAttack[] = _("X Attack");
static const u8 sText_XDefend[] = _("X Defend");
static const u8 sText_XSpeed[] = _("X Speed");
static const u8 sText_PokemonTalk[] = _("Pokemon Talk");
static const u8 sText_PokemonMusic[] = _("Pokemon Music");
static const u8 sText_BuenasPassword[] = _("Buena's Password");

static const u8 sText_BuenasPasswordRadio[] = _(
    "Buena: Buena's Password!\n"
    "Today's password is:\l"
    "{STR_VAR_1}!\p"
    "Come to Radio Tower 2F and\n"
    "tell me the password!{PAUSE_UNTIL_PRESS}");

static const u8 *const sBuenasPasswordOptions[][BUENAS_PASSWORD_OPTIONS] =
{
    [BUENA_PASSWORD_STARTERS] =
    {
        sText_Cyndaquil,
        sText_Totodile,
        sText_Chikorita,
    },
    [BUENA_PASSWORD_MEDICINE] =
    {
        sText_Potion,
        sText_Antidote,
        sText_ParlyzHeal,
    },
    [BUENA_PASSWORD_BALLS] =
    {
        sText_PokeBall,
        sText_GreatBall,
        sText_UltraBall,
    },
    [BUENA_PASSWORD_ROUTE_MONS] =
    {
        sText_Pikachu,
        sText_Rattata,
        sText_Geodude,
    },
    [BUENA_PASSWORD_NIGHT_MONS] =
    {
        sText_Hoothoot,
        sText_Spinarak,
        sText_Drowzee,
    },
    [BUENA_PASSWORD_TOWNS] =
    {
        sText_NewBarkTown,
        sText_CherrygroveCity,
        sText_AzaleaTown,
    },
    [BUENA_PASSWORD_CATEGORIES] =
    {
        sText_BugPokemon,
        sText_BirdPokemon,
        sText_GrassPokemon,
    },
    [BUENA_PASSWORD_MOVES] =
    {
        sText_Tackle,
        sText_Growl,
        sText_MudSlap,
    },
    [BUENA_PASSWORD_X_ITEMS] =
    {
        sText_XAttack,
        sText_XDefend,
        sText_XSpeed,
    },
    [BUENA_PASSWORD_RADIO_SHOWS] =
    {
        sText_PokemonTalk,
        sText_PokemonMusic,
        sText_BuenasPassword,
    },
};

static u16 GetBuenasPasswordIndex(u16 modulo, u32 salt)
{
    u32 seed;

    RtcCalcLocalTime();
    seed = gSaveBlock1Ptr->dailySeed ^ (gLocalTime.days * 1103515245);
    seed ^= salt * 0x45d9f3b;
    seed ^= seed >> 16;
    return seed % modulo;
}

u16 BuenasPassword_IsBroadcastTime(void)
{
    RtcCalcLocalTime();
    return IsBetweenHours(gLocalTime.hours, BUENAS_PASSWORD_START_HOUR, BUENAS_PASSWORD_END_HOUR);
}

u16 BuenasPassword_GetCurrentGroup(void)
{
    return GetBuenasPasswordIndex(BUENA_PASSWORD_COUNT, 0);
}

u16 BuenasPassword_GetCorrectAnswer(void)
{
    return GetBuenasPasswordIndex(BUENAS_PASSWORD_OPTIONS, 1);
}

void BuenasPassword_BufferCurrentPassword(void)
{
    StringCopy(gStringVar1, sBuenasPasswordOptions[BuenasPassword_GetCurrentGroup()][BuenasPassword_GetCorrectAnswer()]);
}

const u8 *BuenasPassword_GetRadioText(void)
{
    BuenasPassword_BufferCurrentPassword();
    return sText_BuenasPasswordRadio;
}
