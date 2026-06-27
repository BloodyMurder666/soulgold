#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mega Sol applies sunlight Fire and Water damage modifiers to the holder's moves", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_OVERGROW; move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_OVERGROW; move = MOVE_WATER_GUN; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; move = MOVE_WATER_GUN; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol turns Weather Ball into a boosted Fire-type move", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability); }
        OPPONENT(SPECIES_PINSIR) { HP(9999); MaxHP(9999); }
    } WHEN {
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (ability == ABILITY_MEGA_SOL)
            MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(6.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol lets Solar Beam fire immediately and avoids low-light weakening", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }

    GIVEN {
        WITH_CONFIG(B_SANDSTORM_SOLAR_BEAM, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SOLAR_BEAM) == EFFECT_SOLAR_BEAM);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); MOVE(player, MOVE_SOLAR_BEAM); }
        if (ability == ABILITY_OVERGROW) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        if (ability == ABILITY_OVERGROW) {
            MESSAGE("Meganium used Solar Beam!");
            MESSAGE("Meganium absorbed light!");
        }
        MESSAGE("Meganium used Solar Beam!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol strengthens sunlight healing moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_MORNING_SUN; }
    PARAMETRIZE { move = MOVE_SYNTHESIS; }
    PARAMETRIZE { move = MOVE_MOONLIGHT; }

    GIVEN {
        WITH_CONFIG(B_TIME_OF_DAY_HEALING_MOVES, GEN_3);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_MEGA_SOL); HP(1); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(player, damage: -(300 / 1.5));
    } THEN {
        EXPECT_EQ(player->hp, 1 + 20 * player->maxHP / 30);
    }
}

SINGLE_BATTLE_TEST("Mega Sol makes Growth raise Attack and Sp. Atk by two stages")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_GROWTH);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_MEGA_SOL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWTH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Mega Sol works through Cloud Nine and Air Lock", s16 damage)
{
    enum Ability ability;
    u32 species;
    enum Ability weatherSuppressor;

    PARAMETRIZE { ability = ABILITY_OVERGROW; species = SPECIES_GOLDUCK;  weatherSuppressor = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; species = SPECIES_GOLDUCK;  weatherSuppressor = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { ability = ABILITY_OVERGROW; species = SPECIES_RAYQUAZA; weatherSuppressor = ABILITY_AIR_LOCK; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; species = SPECIES_RAYQUAZA; weatherSuppressor = ABILITY_AIR_LOCK; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability); }
        OPPONENT(species) { Ability(weatherSuppressor); HP(9999); MaxHP(9999); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol works through the holder's Utility Umbrella", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ability); Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Sol does not globally activate the target's Leaf Guard")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_MEGA_SOL); }
        OPPONENT(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_WILL_O_WISP, hit: TRUE); }
    } SCENE {
        if (move == MOVE_CELEBRATE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
            STATUS_ICON(opponent, burn: TRUE);
        }
        else {
            ABILITY_POPUP(opponent, ABILITY_LEAF_GUARD);
            NOT STATUS_ICON(opponent, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Mega Sol lowers the holder's Thunder accuracy like sunlight")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_THUNDER) == 70);
        ASSUME(MoveHas50AccuracyInSun(MOVE_THUNDER) == TRUE);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_MEGA_SOL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, player);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Mega Sol works as an innate trait", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_OVERGROW; }
    PARAMETRIZE { ability = ABILITY_MEGA_SOL; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_MEGANIUM_MEGA) { Ability(ABILITY_OVERGROW); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
#endif
