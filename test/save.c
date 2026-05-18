#include "global.h"
#include "pokemon_storage_system.h"
#include "test/test.h"

// If you would like to ensure save compatibility, update the values below with those for your hack. You can find these through the debug menu.
// Please note that this simple check is not 100% foolproof, but should be able to catch most unintended shifts.
#define T_SAVEBLOCK1_SIZE 15568
#define T_SAVEBLOCK2_SIZE 3884
#define T_SAVEBLOCK3_SIZE 88
#define T_POKEMON_SECURE_DATA_SIZE 44
#define T_BOX_POKEMON_SIZE 76
#define T_POKEMON_SIZE 96
#define T_POKEMONSTORAGE_SIZE 46188

TEST("SaveBlock1 is backwards compatible")
{
    KNOWN_FAILING;
    EXPECT_EQ(sizeof(struct SaveBlock1), T_SAVEBLOCK1_SIZE);
}

TEST("SaveBlock2 is backwards compatible")
{
    KNOWN_FAILING;
    EXPECT_EQ(sizeof(struct SaveBlock2), T_SAVEBLOCK2_SIZE);
}

TEST("SaveBlock3 is backwards compatible")
{
    EXPECT_EQ(sizeof(struct SaveBlock3), T_SAVEBLOCK3_SIZE);
}

TEST("PokemonStorage is backwards compatible")
{
    EXPECT_EQ(sizeof(struct PokemonStorage), T_POKEMONSTORAGE_SIZE);
}

TEST("Pokemon save structs are expected sizes")
{
    EXPECT_EQ(sizeof(struct PokemonSecureData), T_POKEMON_SECURE_DATA_SIZE);
    EXPECT_EQ(sizeof(struct BoxPokemon), T_BOX_POKEMON_SIZE);
    EXPECT_EQ(sizeof(struct Pokemon), T_POKEMON_SIZE);
}

#undef T_SAVEBLOCK1_SIZE
#undef T_SAVEBLOCK2_SIZE
#undef T_SAVEBLOCK3_SIZE
#undef T_POKEMON_SECURE_DATA_SIZE
#undef T_BOX_POKEMON_SIZE
#undef T_POKEMON_SIZE
#undef T_POKEMONSTORAGE_SIZE
