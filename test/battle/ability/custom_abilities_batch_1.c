#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bloodlust raises Attack and Speed after critical hits", s16 atkStage, s16 speedStage)
{
    bool32 critical;

    PARAMETRIZE { critical = FALSE; }
    PARAMETRIZE { critical = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLOODLUST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: critical); }
    } THEN {
        results[i].atkStage = player->statStages[STAT_ATK];
        results[i].speedStage = player->statStages[STAT_SPEED];
    } FINALLY {
        EXPECT_EQ(results[0].atkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[0].speedStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].atkStage, DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(results[1].speedStage, DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Gang Up boosts damage if the target was already damaged this turn", s16 damage)
{
    bool32 priorDamage;

    PARAMETRIZE { priorDamage = FALSE; }
    PARAMETRIZE { priorDamage = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GANG_UP); Speed(50); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            if (priorDamage)
                MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            else
                MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        if (priorDamage)
            HP_BAR(opponentLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Pendulum increases repeated move damage and resets on a different move")
{
    s16 firstDamage, repeatedDamage, resetDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PENDULUM); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &firstDamage);
        HP_BAR(opponent, captureDamage: &repeatedDamage);
        HP_BAR(opponent);
        HP_BAR(opponent, captureDamage: &resetDamage);
    } THEN {
        EXPECT_GT(repeatedDamage, firstDamage);
        EXPECT_EQ(resetDamage, firstDamage);
    }
}

SINGLE_BATTLE_TEST("Momentum raises Speed after priority moves only")
{
    enum Move move;
    s16 speedStage;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MOMENTUM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } THEN {
        speedStage = player->statStages[STAT_SPEED];
        if (move == MOVE_QUICK_ATTACK)
            EXPECT_EQ(speedStage, DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(speedStage, DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Desperado raises offensive stats after taking super-effective damage", s16 atkStage, s16 spatkStage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SHADOW_BALL; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DESPERADO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        results[i].atkStage = player->statStages[STAT_ATK];
        results[i].spatkStage = player->statStages[STAT_SPATK];
    } FINALLY {
        EXPECT_EQ(results[0].atkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[0].spatkStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].atkStage, DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(results[1].spatkStage, DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Glass Cannon raises the higher offense and lowers both defenses on entry")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_GLASS_CANNON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(150); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        if (ability == ABILITY_GLASS_CANNON) {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
            EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 2);
        } else {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        }
    }
}

SINGLE_BATTLE_TEST("Aegis caps the first large direct hit each turn", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_AEGIS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); Defense(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(250); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYPER_BEAM); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 50);
    }
}

DOUBLE_BATTLE_TEST("Martyr heals remaining allies when it faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MARTYR); HP(1); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        EXPECT_EQ(playerRight->hp, 75);
    }
}

SINGLE_BATTLE_TEST("Martyr has no ally to heal in single battles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MARTYR); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(player->hp, 0);
    }
}

SINGLE_BATTLE_TEST("Indomitable prevents flinching and halves incoming status move accuracy", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_INDOMITABLE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Speed(1); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_SCRATCH); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_GT(results[0].hp, results[1].hp);
    }
}

SINGLE_BATTLE_TEST("Indomitable reduces status move accuracy")
{
    PASSES_RANDOMLY(30, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_HYPNOSIS) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveAccuracy(MOVE_HYPNOSIS) == 60);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_INDOMITABLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYPNOSIS); }
    } THEN {
        EXPECT(player->status1 & STATUS1_SLEEP);
    }
}

SINGLE_BATTLE_TEST("Colossal blocks direct moves at 44 base power or lower")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SLAM; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) <= 44);
        ASSUME(GetMovePower(MOVE_SLAM) > 44);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOSSAL); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        if (move == MOVE_SCRATCH)
            EXPECT_EQ(player->hp, player->maxHP);
        else
            EXPECT_LT(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Parrying keeps Focus Punch focused after damage and raises Defense", u16 opponentHp, s16 defStage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_PARRYING; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        results[i].opponentHp = opponent->hp;
        results[i].defStage = player->statStages[STAT_DEF];
    } FINALLY {
        EXPECT_GT(results[0].opponentHp, results[1].opponentHp);
        EXPECT_EQ(results[0].defStage, DEFAULT_STAT_STAGE);
        EXPECT_EQ(results[1].defStage, DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Faintrattle badly poisons only contact attackers that knock it out")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FAINTRATTLE); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        if (move == MOVE_SCRATCH)
            EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
        else
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Shardplate weakens direct hits until it is depleted", s16 damage)
{
    u32 hitNum;

    PARAMETRIZE { hitNum = 1; }
    PARAMETRIZE { hitNum = 6; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHARDPLATE); HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        if (hitNum == 6)
            TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (hitNum == 1) {
            HP_BAR(player, captureDamage: &results[i].damage);
        } else {
            HP_BAR(player);
            HP_BAR(player);
            HP_BAR(player);
            HP_BAR(player);
            HP_BAR(player);
            HP_BAR(player, captureDamage: &results[i].damage);
        }
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Haunted blocks real major status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HAUNTED); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Haunted counts as statused for Facade", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_HAUNTED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Mending can cure status and heal at end of turn")
{
    PASSES_RANDOMLY(30, 100, RNG_MENDING);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MENDING); HP(80); MaxHP(100); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_GT(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Mending does not heal without its ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); HP(80); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Plaguetouch can inflict a random major status with contact moves")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLAGUETOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_NE(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Plaguetouch ignores non-contact moves")
{
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLAGUETOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Monsoon lets Water moves bypass Water Absorb during rain")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_MONSOON; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        STARTING_WEATHER(B_WEATHER_RAIN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } THEN {
        if (ability == ABILITY_MONSOON)
            EXPECT_LT(opponent->hp, opponent->maxHP);
        else
            EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Mirage can confuse targets during sun only")
{
    PASSES_RANDOMLY(25, 100, RNG_MIRAGE);
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SUN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Mirage does not confuse outside sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns == 0);
    }
}

SINGLE_BATTLE_TEST("Blizzard Heart can freeze or frostbite with Ice moves during icy weather")
{
    PASSES_RANDOMLY(20, 100, RNG_BLIZZARD_HEART);
    GIVEN {
        ASSUME(GetMoveType(MOVE_ICE_SHARD) == TYPE_ICE);
        STARTING_WEATHER(B_WEATHER_HAIL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLIZZARD_HEART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_SHARD); }
    } THEN {
        EXPECT(opponent->status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE));
    }
}

SINGLE_BATTLE_TEST("Blizzard Heart ignores non-Ice moves")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_HAIL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLIZZARD_HEART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Mudslide absorbs Water moves during sandstorm only")
{
    bool32 sand;

    PARAMETRIZE { sand = FALSE; }
    PARAMETRIZE { sand = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        if (sand)
            STARTING_WEATHER(B_WEATHER_SANDSTORM);
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_MUDSLIDE); HP(300); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } THEN {
        if (sand) {
            EXPECT_EQ(player->hp, player->maxHP);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        } else {
            EXPECT_LT(player->hp, player->maxHP);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        }
    }
}
