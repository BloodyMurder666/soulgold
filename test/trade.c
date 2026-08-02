#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "trade.h"
#include "test/test.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/trade.h"

TEST("NPC trades use the release shiny odds and preserve their fixed data")
{
    bool8 isShiny;

    PARAMETRIZE { isShiny = FALSE; }
    PARAMETRIZE { isShiny = TRUE; }

    EXPECT_EQ(RELEASE_SHINY_ODDS, (1 << 16) / 256);

    CreateMon(&gPlayerParty[0], SPECIES_RALTS, 25, 0, OTID_STRUCT_PLAYER_ID);
    gSpecialVar_0x8004 = 0;
    gSpecialVar_0x8005 = INGAME_TRADE_SEEDOT;
    SET_RNG(RNG_IN_GAME_TRADE_SHINY, isShiny ? RELEASE_SHINY_ODDS - 1 : RELEASE_SHINY_ODDS);

    CreateInGameTradePokemon();

    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY), isShiny);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_BUDEW);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL), 25);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY), 0x84);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_OT_ID), 38726);
}
