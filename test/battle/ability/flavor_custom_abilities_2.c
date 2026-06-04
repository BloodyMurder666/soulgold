#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Infernal lowers the foe's Attack and Defense on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_INFERNAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INFERNAL);
        MESSAGE("The opposing Wobbuffet's Attack and Defense fell!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Attack fell!");
            MESSAGE("The opposing Wobbuffet's Defense fell!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Reef Warden heals 50 percent on switch-out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); HP(80); MaxHP(160); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 160);
    }
}

SINGLE_BATTLE_TEST("Reef Warden still heals on switch-out after taking contact")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); HP(120); MaxHP(160); Defense(200); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(1); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 160);
    }
}

SINGLE_BATTLE_TEST("Reef Warden prevents contact attackers from healing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); Defense(200); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(80); MaxHP(160); Attack(1); Speed(2); Item(ITEM_LEFTOVERS); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_REEF_WARDEN);
        MESSAGE("The opposing Wobbuffet was prevented from healing!");
        NONE_OF { HP_BAR(opponent); }
    } THEN {
        EXPECT_EQ(opponent->hp, 80);
        EXPECT(opponent->volatiles.healBlock);
    }
}

SINGLE_BATTLE_TEST("Solar Armor blocks status moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLAR_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Abyssal Veil blocks status moves only above 75 percent HP")
{
    u32 hp;
    bool32 blocked;

    PARAMETRIZE { hp = 76; blocked = TRUE; }
    PARAMETRIZE { hp = 75; blocked = FALSE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ABYSSAL_VEIL); HP(hp); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } THEN {
        if (blocked)
            EXPECT_EQ(player->status1, STATUS1_NONE);
        else
            EXPECT(player->status1 & STATUS1_SLEEP);
    }
}

SINGLE_BATTLE_TEST("Plasma Surge paralyzes with attacks during Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLASMA_SURGE); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Plasma Surge does not paralyze outside Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLASMA_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Phalanx and Spectral halve matching damage categories", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_NONE;     move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_PHALANX;  move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_NONE;     move = MOVE_CONFUSION; }
    PARAMETRIZE { ability = ABILITY_SPECTRAL; move = MOVE_CONFUSION; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Sunhardened doubles Sp. Def during sun", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_SUNHARDENED; }
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SUN);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSION); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Heatstorm sets Scorched Field on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HEATSTORM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_SCORCHED_FIELD);
    }
}

SINGLE_BATTLE_TEST("Coalwalker doubles Defense during Scorched Field", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_COALWALKER; }
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Lava Surfer doubles Speed during Scorched Field")
{
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LAVA_SURFER); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Ash Assets boosts damage during Scorched Field", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_ASH_ASSETS; }
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.15), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Ash Assets starts Scorched Field after a KO")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ASH_ASSETS); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_SCORCHED_FIELD);
    }
}

SINGLE_BATTLE_TEST("Ash Assets does not restart Scorched Field after a KO if it is already active")
{
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ASH_ASSETS); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_ASH_ASSETS); }
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_SCORCHED_FIELD);
    }
}

SINGLE_BATTLE_TEST("Force Return reflects 30 percent of damage dealt")
{
    s16 damage;
    s16 reflectedDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); HP(160); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_FORCE_RETURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &reflectedDamage);
    } THEN {
        EXPECT_EQ(reflectedDamage, (damage * 30) / 100);
    }
}

SINGLE_BATTLE_TEST("Enigma doubles Power moves", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_ENIGMA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_GEM); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Burrower makes Dig instant and stronger than Earthquake")
{
    s16 digDamage;
    s16 earthquakeDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BURROWER); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIG); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &digDamage);
        HP_BAR(opponent, captureDamage: &earthquakeDamage);
    } THEN {
        EXPECT_GT(digDamage, earthquakeDamage);
    }
}

SINGLE_BATTLE_TEST("Diver makes Dive instant and stronger than Waterfall")
{
    s16 diveDamage;
    s16 waterfallDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DIVER); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
        TURN { MOVE(player, MOVE_WATERFALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &diveDamage);
        HP_BAR(opponent, captureDamage: &waterfallDamage);
    } THEN {
        EXPECT_GT(diveDamage, waterfallDamage);
    }
}

SINGLE_BATTLE_TEST("Last Stand boosts attack damage", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_LAST_STAND; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Last Stand costs 10 percent max HP after attacking")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LAST_STAND); HP(100); MaxHP(100); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 90);
    }
}
