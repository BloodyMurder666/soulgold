#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Jade Bloom heals and raises an eligible special stat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_JADE_BLOOM); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 90);
        EXPECT(player->statStages[STAT_SPATK] == DEFAULT_STAT_STAGE + 1 || player->statStages[STAT_SPDEF] == DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Brimstone bypasses Flash Fire")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRIMSTONE); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_FLASH_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Stygian raises priority against sleeping targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STYGIAN); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(2)); Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent); }
    }
}

SINGLE_BATTLE_TEST("Omega forces outgoing and incoming type effectiveness", s16 damage)
{
    enum Ability playerAbility;
    enum Ability opponentAbility;

    PARAMETRIZE { playerAbility = ABILITY_OMEGA; opponentAbility = ABILITY_NONE; }
    PARAMETRIZE { playerAbility = ABILITY_NONE; opponentAbility = ABILITY_OMEGA; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_CONFUSION) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(playerAbility); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(opponentAbility); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSION); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(4.0), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Permafrost prevents burns and Attack drops")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PERMAFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
        TURN { MOVE(opponent, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Permafrost can freeze or frostbite on damaging attacks")
{
    PASSES_RANDOMLY(20, 100, RNG_PERMAFROST);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PERMAFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_ICY_ANY);
    }
}

SINGLE_BATTLE_TEST("Stone Face leaves a full-HP user at one quarter HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STONE_FACE); HP(160); MaxHP(160); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(250); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, hp: 40);
        ABILITY_POPUP(player, ABILITY_STONE_FACE);
    } THEN {
        EXPECT_EQ(player->hp, 40);
    }
}

SINGLE_BATTLE_TEST("Voidtouch ignores Reflect", s16 damage)
{
    u16 ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_VOIDTOUCH; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_REFLECT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Glacial raises Sp. Def on entry and heals in hail")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GLACIAL); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Lunar Cycle raises Speed after a damaging hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_CYCLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_LUNAR_CYCLE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Frost Nova freezes or frostbites the KOing attacker")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FROST_NOVA); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_ICY_ANY);
    }
}

SINGLE_BATTLE_TEST("Shockwiring charges on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHOCKWIRING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } THEN {
        EXPECT(player->volatiles.chargeTimer > 0);
    }
}

SINGLE_BATTLE_TEST("Ritual absorbs Ghost moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RITUAL); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Ritual powers Hex to 100 BP", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_RITUAL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEX); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(75.0 / 65.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Overlock doubles the next Steel hit after Shift Gear", s16 damage)
{
    bool32 overlock;

    PARAMETRIZE { overlock = FALSE; }
    PARAMETRIZE { overlock = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(overlock ? ABILITY_OVERLOCK : ABILITY_NONE); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHIFT_GEAR); }
        TURN { MOVE(player, MOVE_METAL_CLAW); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Spectral Drain heals from Ground and Ghost damage and blocks Leech Seed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPECTRAL_DRAIN); HP(80); MaxHP(160); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEECH_SEED); }
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); }
    } THEN {
        EXPECT(!player->volatiles.leechSeed);
        EXPECT(player->hp > 80);
    }
}

SINGLE_BATTLE_TEST("Blazing Sun burns with damaging Fire moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLAZING_SUN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Overload ignores Focus Sash")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_OVERLOAD); Attack(250); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Defense(1); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->hp, 0);
    }
}

DOUBLE_BATTLE_TEST("Fill Void raises Defense and Sp. Atk after a KO")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FILL_VOID); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); SEND_OUT(opponentLeft, 2); }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Dust Devil can confuse on damaging attacks")
{
    PASSES_RANDOMLY(15, 100, RNG_DUST_DEVIL);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DUST_DEVIL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Solidify raises Sp. Def after special hits")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLIDIFY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSION); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Unleashed changes Shell Smash into all-stat boosts")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_UNLEASHED); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Tether copies opposing stat boosts")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TETHER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Solar Panel makes Electric moves always hit in sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLAR_PANEL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_THUNDER, WITH_RNG(RNG_ACCURACY, FALSE)); }
    } SCENE {
        HP_BAR(opponent);
    }
}
