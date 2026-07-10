#include "global.h"
#include "battle_main.h"
#include "data.h"
#include "level_scaling.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/battle.h"

TEST("Trainer scaling average excludes party members seven or more levels below the highest")
{
    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 70, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[1], SPECIES_WOBBUFFET, 68, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[2], SPECIES_WOBBUFFET, 64, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[3], SPECIES_WOBBUFFET, 63, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[4], SPECIES_WOBBUFFET, 5, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 5;
    InvalidatePartyLevelCache();

    // Levels 63 and 5 are at least seven below 70. (70 + 68 + 64) / 3 = 67.
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_AVG, FALSE), 67);
}

TEST("Trainer scaling average cannot be lowered by a weak passenger")
{
    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[1], SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[2], SPECIES_WOBBUFFET, 5, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 3;
    InvalidatePartyLevelCache();

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_AVG, FALSE), 100);
}

TEST("Trainer scaling does not reapply large authored level gaps")
{
    static const struct TrainerMon trainerMons[] =
    {
        { .species = SPECIES_WOBBUFFET, .lvl = 100 },
        { .species = SPECIES_WOBBUFFET, .lvl = 55 },
    };
    static const struct Trainer trainer =
    {
        .party = trainerMons,
        .partySize = ARRAY_COUNT(trainerMons),
    };

    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 70, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[1], SPECIES_WOBBUFFET, 68, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[2], SPECIES_WOBBUFFET, 64, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 3;
    gSaveBlock2Ptr->optionsTrainerLevelScaling = LEVEL_SCALING_OPTION_ON;

    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &trainer, TRUE, BATTLE_TYPE_TRAINER, TRAINER_NONE);

    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL), GetMonData(&gEnemyParty[1], MON_DATA_LEVEL));
}
