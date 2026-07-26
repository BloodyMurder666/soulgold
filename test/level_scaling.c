#include "global.h"
#include "battle_main.h"
#include "data.h"
#include "level_scaling.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/battle.h"
#include "constants/opponents.h"

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

TEST("Trainer scaling preserves small authored level gaps")
{
    static const struct TrainerMon trainerMons[] =
    {
        { .species = SPECIES_WOBBUFFET, .lvl = 54 },
        { .species = SPECIES_WOBBUFFET, .lvl = 55 },
        { .species = SPECIES_WOBBUFFET, .lvl = 56 },
    };
    static const struct Trainer trainer =
    {
        .party = trainerMons,
        .partySize = ARRAY_COUNT(trainerMons),
    };

    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 70, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 1;
    gSaveBlock2Ptr->optionsTrainerLevelScaling = LEVEL_SCALING_OPTION_ON;

    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &trainer, TRUE, BATTLE_TYPE_TRAINER, TRAINER_NONE);

    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL) + 1, GetMonData(&gEnemyParty[1], MON_DATA_LEVEL));
    EXPECT_EQ(GetMonData(&gEnemyParty[1], MON_DATA_LEVEL) + 1, GetMonData(&gEnemyParty[2], MON_DATA_LEVEL));
}

TEST("Trainer scaling caps large authored level gaps")
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

    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL) - B_TRAINER_SCALING_MAX_AUTHORED_GAP,
              GetMonData(&gEnemyParty[1], MON_DATA_LEVEL));
}

TEST("Optional trainer scaling activates only when the anti-sandbag average is more than five levels ahead")
{
    static const struct TrainerMon trainerMons[] =
    {
        { .species = SPECIES_DRILBUR, .lvl = 40 },
    };
    static const struct Trainer trainer =
    {
        .party = trainerMons,
        .partySize = ARRAY_COUNT(trainerMons),
    };

    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 45, 0, OTID_STRUCT_PLAYER_ID, 0);
    CreateMonWithIVs(&gPlayerParty[1], SPECIES_WOBBUFFET, 5, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 2;
    gSaveBlock2Ptr->optionsTrainerLevelScaling = LEVEL_SCALING_OPTION_OFF;

    // The weak passenger is ignored. A difference of exactly five does not scale.
    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &trainer, TRUE, BATTLE_TYPE_TRAINER, TRAINER_KEIRA);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL), 40);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_DRILBUR);

    SetMonData(&gPlayerParty[0], MON_DATA_LEVEL, (u8[]){46});

    // A difference of six activates forced upward scaling and evolution.
    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &trainer, TRUE, BATTLE_TYPE_TRAINER, TRAINER_KEIRA);
    EXPECT(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL) >= 46);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_EXCADRILL);
}

TEST("Optional trainers never scale below their authored levels")
{
    static const struct TrainerMon trainerMons[] =
    {
        { .species = SPECIES_DRILBUR, .lvl = 38 },
        { .species = SPECIES_EXCADRILL, .lvl = 40 },
    };
    static const struct Trainer trainer =
    {
        .party = trainerMons,
        .partySize = ARRAY_COUNT(trainerMons),
    };

    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_WOBBUFFET, 20, 0, OTID_STRUCT_PLAYER_ID, 0);
    gPlayerPartyCount = 1;
    gSaveBlock2Ptr->optionsTrainerLevelScaling = LEVEL_SCALING_OPTION_ON;

    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &trainer, TRUE, BATTLE_TYPE_TRAINER, TRAINER_KEIRA);

    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_LEVEL), 38);
    EXPECT_EQ(GetMonData(&gEnemyParty[1], MON_DATA_LEVEL), 40);
    EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SPECIES_DRILBUR);
}

TEST("Forced trainer evolution follows only unambiguous unconditional level evolutions")
{
    EXPECT_EQ(EvolveSpeciesForLevel(SPECIES_CHARMANDER, 35), SPECIES_CHARMELEON);
    EXPECT_EQ(EvolveSpeciesForLevel(SPECIES_CHARMANDER, 36), SPECIES_CHARIZARD);
    EXPECT_EQ(EvolveSpeciesForLevel(SPECIES_TOXEL, 50), SPECIES_TOXEL);
}
