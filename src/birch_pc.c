#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

static bool32 IsExcludedFromJohtoDexRating(u16 species)
{
    return gSpeciesInfo[species].isRestrictedLegendary
        || gSpeciesInfo[species].isSubLegendary
        || gSpeciesInfo[species].isMythical;
}

#define JOHTO_DEX(name) SPECIES_##name,
static const u16 sJohtoDexSpecies[] =
{
#include "constants/johto_dex_order.h"
};
#undef JOHTO_DEX

STATIC_ASSERT(ARRAY_COUNT(sJohtoDexSpecies) == JOHTO_DEX_COUNT - 1, JohtoDexSpeciesCount);

bool16 ScriptGetJohtoPokedexInfo(void)
{
    u32 i;
    bool16 isComplete = TRUE;

    gSpecialVar_0x8005 = 0;
    gSpecialVar_0x8006 = 0;
    gSpecialVar_0x8008 = 0;

    for (i = 0; i < ARRAY_COUNT(sJohtoDexSpecies); i++)
    {
        u16 species = sJohtoDexSpecies[i];
        enum NationalDexOrder dexNum = gSpeciesInfo[species].natDexNum;
        bool32 caught = GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT);

        if (IsExcludedFromJohtoDexRating(species))
            continue;
        gSpecialVar_0x8008++;
        if (GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
            gSpecialVar_0x8005++;
        if (caught)
            gSpecialVar_0x8006++;
        else
            isComplete = FALSE;
    }

    return isComplete;
}

#define BIRCH_DEX_STRINGS 21

static const u8 *const sBirchDexRatingTexts[BIRCH_DEX_STRINGS] =
{
    gBirchDexRatingText_LessThan10,
    gBirchDexRatingText_LessThan20,
    gBirchDexRatingText_LessThan30,
    gBirchDexRatingText_LessThan40,
    gBirchDexRatingText_LessThan50,
    gBirchDexRatingText_LessThan60,
    gBirchDexRatingText_LessThan70,
    gBirchDexRatingText_LessThan80,
    gBirchDexRatingText_LessThan90,
    gBirchDexRatingText_LessThan100,
    gBirchDexRatingText_LessThan110,
    gBirchDexRatingText_LessThan120,
    gBirchDexRatingText_LessThan130,
    gBirchDexRatingText_LessThan140,
    gBirchDexRatingText_LessThan150,
    gBirchDexRatingText_LessThan160,
    gBirchDexRatingText_LessThan170,
    gBirchDexRatingText_LessThan180,
    gBirchDexRatingText_LessThan190,
    gBirchDexRatingText_LessThan200,
    gBirchDexRatingText_DexCompleted,
};

static const u8 *GetScaledPokedexRatingText(u32 count, u32 maxDex)
{
    if (maxDex == 0)
        return gBirchDexRatingText_DexCompleted;

    count = min(count, maxDex);
    return sBirchDexRatingTexts[(count * (BIRCH_DEX_STRINGS - 1)) / maxDex];
}

// This shows your Johto Pokédex rating and not your National Dex.
const u8 *GetPokedexRatingText(u32 count)
{
    u32 i;
    u32 maxDex = ARRAY_COUNT(sJohtoDexSpecies);

    for (i = 0; i < ARRAY_COUNT(sJohtoDexSpecies); i++)
    {
        u16 species = sJohtoDexSpecies[i];

        if (IsExcludedFromJohtoDexRating(species))
        {
            enum NationalDexOrder dexNum = gSpeciesInfo[species].natDexNum;

            if (count != 0 && GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
                count--;
            maxDex--;
        }
    }

    return GetScaledPokedexRatingText(count, maxDex);
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}

void ShowJohtoPokedexRatingMessage(void)
{
    ShowFieldMessage(GetScaledPokedexRatingText(gSpecialVar_0x8006, gSpecialVar_0x8008));
}
