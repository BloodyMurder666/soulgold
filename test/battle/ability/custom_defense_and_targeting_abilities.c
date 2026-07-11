#include "global.h"
#include "achievements.h"
#include "test/battle.h"
#include "battle_ai_util.h"
#include "battle_util.h"
#include "event_data.h"

static struct BattleContext MakeDryRunContext(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, u32 fixedBasePower)
{
    struct BattleContext ctx = {0};

    ctx.battlerAtk = battlerAtk;
    ctx.battlerDef = battlerDef;
    ctx.move = ctx.chosenMove = move;
    ctx.moveType = GetMoveType(move);
    ctx.fieldStatuses = gFieldStatuses;
    ctx.weather = gBattleWeather;
    ctx.fixedBasePower = fixedBasePower;
    ctx.randomFactor = FALSE;
    ctx.updateFlags = FALSE;
    return ctx;
}

SINGLE_BATTLE_TEST("Aegis damage previews do not consume its once-per-turn cap")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_AEGIS); HP(100); MaxHP(100); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        struct BattleContext ctx = MakeDryRunContext(battlerAtk, battlerDef, MOVE_SCRATCH, 500);

        EXPECT_EQ(CalculateMoveDamage(&ctx), 25);
        EXPECT(!gBattleStruct->aegisUsed[battlerDef]);
    }
}

SINGLE_BATTLE_TEST("Reborn damage previews do not revive or consume the ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); HP(100); MaxHP(100); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        struct BattleContext ctx = MakeDryRunContext(battlerAtk, battlerDef, MOVE_SCRATCH, 500);

        EXPECT_EQ(CalculateMoveDamage(&ctx), 0);
        EXPECT_EQ(gBattleMons[battlerDef].hp, 100);
        EXPECT_EQ(gBattleStruct->rebornUsed[GetBattlerSide(battlerDef)] & (1u << gBattlerPartyIndexes[battlerDef]), 0);
    }
}

SINGLE_BATTLE_TEST("Custom Sturdy damage previews preserve battle state")
{
    enum Ability ability;
    s16 expectedDamage;

    PARAMETRIZE { ability = ABILITY_STONE_FACE; expectedDamage = 75; }
    PARAMETRIZE { ability = ABILITY_NINE_LIVES; expectedDamage = 99; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        struct BattleContext ctx = MakeDryRunContext(battlerAtk, battlerDef, MOVE_SCRATCH, 500);

        EXPECT_EQ(CalculateMoveDamage(&ctx), expectedDamage);
        EXPECT(!gProtectStructs[battlerDef].assuranceDoubled);
        EXPECT_EQ(gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_STURDIED, 0);
    }
}

SINGLE_BATTLE_TEST("Critical-hit damage previews do not advance achievement counters")
{
    GIVEN {
        ASSUME(MoveAlwaysCrits(MOVE_FROST_BREATH));
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(500); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        struct BattleContext ctx = MakeDryRunContext(battlerAtk, battlerDef, MOVE_FROST_BREATH, 100);

        EXPECT_GT(CalculateMoveDamage(&ctx), 0);
        EXPECT_EQ(Achievement_GetCounter(ACH_COUNTER_CRITICAL_HITS), 0);
        EXPECT(!gSpecialStatuses[battlerDef].criticalHit);
    }
}

SINGLE_BATTLE_TEST("AI applies Aegis to only one hit of a multi-hit move", u16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_AEGIS; }
    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_HIT) == 2);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        uq4_12_t effectiveness;

        // AI_CalcDamageSaveBattlers consumes the per-turn cache populated by
        // SetAiLogicDataForTurn during normal AI execution.
        gAiLogicData->abilities[battlerDef] = ability;
        struct SimulatedDamage damage = AI_CalcDamageSaveBattlers(
            MOVE_DOUBLE_HIT, battlerAtk, battlerDef, &effectiveness, NO_GIMMICK, NO_GIMMICK);

        results[i].damage = damage.median;
    } FINALLY {
        EXPECT_GT(results[1].damage, 50);
        EXPECT_LT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("AI applies Aegis to only one Beat Up strike", u16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_AEGIS; }
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); Defense(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(500); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        uq4_12_t effectiveness;

        gAiLogicData->abilities[battlerDef] = ability;
        struct SimulatedDamage simulated = AI_CalcDamageSaveBattlers(
            MOVE_BEAT_UP, battlerAtk, battlerDef, &effectiveness, NO_GIMMICK, NO_GIMMICK);

        results[i].damage = simulated.median;
    } FINALLY {
        EXPECT_GT(results[1].damage, 25);
        EXPECT_LT(results[1].damage, results[0].damage);
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
        EXPECT_EQ(results[1].damage, 25);
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

SINGLE_BATTLE_TEST("Colossal uses unmodified base power when Technician boosts a move")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) <= 44);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOSSAL); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TECHNICIAN); Attack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
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

DOUBLE_BATTLE_TEST("Guardian redirects selected damaging moves to itself")
{
    enum Ability partnerAbility;

    PARAMETRIZE { partnerAbility = ABILITY_BIG_PECKS; }
    PARAMETRIZE { partnerAbility = ABILITY_GUARDIAN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(partnerAbility); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        if (partnerAbility == ABILITY_GUARDIAN) {
            EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
            EXPECT_LT(playerRight->hp, playerRight->maxHP);
        } else {
            EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
            EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        }
    }
}

SINGLE_BATTLE_TEST("Guardian reduces direct damage it takes", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_GUARDIAN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Valkyrie grants Steel resistances without Steel weaknesses", u16 hp)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE;  move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_CLEAR_SMOG; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE;  move = MOVE_CLEAR_SMOG; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE;  move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE;  move = MOVE_EARTHQUAKE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_CLEAR_SMOG) == TYPE_POISON);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_GT(results[1].hp, results[0].hp); // Normal resistance
        EXPECT_LT(results[2].hp, 100);
        EXPECT_EQ(results[3].hp, 100);           // Poison immunity
        EXPECT_EQ(results[4].hp, results[5].hp); // No Fire weakness
        EXPECT_EQ(results[6].hp, results[7].hp); // No Ground weakness
    }
}

SINGLE_BATTLE_TEST("Valkyrie does not change offensive stat selection", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_VALKYRIE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(50); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Valkyrie blocks Poison status moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_VALKYRIE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC, hit: TRUE); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Immovable blocks phasing moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_IMMOVABLE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROAR); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Roar!");
        ABILITY_POPUP(player, ABILITY_IMMOVABLE);
        MESSAGE("Wobbuffet anchors itself with Immovable!");
        NOT MESSAGE("Wynaut was dragged out!");
    }
}

SINGLE_BATTLE_TEST("Immovable makes its user move last")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_IMMOVABLE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(1); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        if (ability == ABILITY_IMMOVABLE)
            EXPECT_EQ(opponent->hp, opponent->maxHP);
        else
            EXPECT_LT(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Transmute reduces the first incoming direct hit", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_TRANSMUTE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_CHARMANDER) { Ability(ability); HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Transmute is consumed after its first use")
{
    s16 firstDamage, secondDamage;

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_TRANSMUTE); HP(500); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(player, captureDamage: &firstDamage);
        HP_BAR(player, captureDamage: &secondDamage);
    } THEN {
        EXPECT_GT(secondDamage, firstDamage);
    }
}

DOUBLE_BATTLE_TEST("Spacetime Rift protects same-side Palkia and Dialga from spread moves")
{
    bool32 rift;

    PARAMETRIZE { rift = FALSE; }
    PARAMETRIZE { rift = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_PALKIA) { Ability(rift ? ABILITY_SPACETIME_RIFT : ABILITY_BIG_PECKS); HP(100); MaxHP(100); }
        PLAYER(SPECIES_DIALGA) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } THEN {
        if (rift) {
            EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
            EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        } else {
            EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
            EXPECT_LT(playerRight->hp, playerRight->maxHP);
        }
    }
}

DOUBLE_BATTLE_TEST("Spacetime Rift requires Palkia and Dialga to share a side")
{
    GIVEN {
        PLAYER(SPECIES_PALKIA) { Ability(ABILITY_SPACETIME_RIFT); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DIALGA) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_EARTHQUAKE); }
    } THEN {
        EXPECT_LT(playerLeft->hp, playerLeft->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Spacetime Rift records the ability on its owner")
{
    GIVEN {
        PLAYER(SPECIES_PALKIA) { Ability(ABILITY_BIG_PECKS); HP(100); MaxHP(100); }
        PLAYER(SPECIES_DIALGA) { Ability(ABILITY_SPACETIME_RIFT); HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } THEN {
        EXPECT_EQ(gBattleHistory->abilities[B_POSITION_PLAYER_RIGHT], ABILITY_SPACETIME_RIFT);
        EXPECT_NE(gBattleHistory->abilities[B_POSITION_PLAYER_LEFT], ABILITY_SPACETIME_RIFT);
    }
}

SINGLE_BATTLE_TEST("Defensive custom damage abilities are recorded on their owners")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SHARDPLATE; }
    PARAMETRIZE { ability = ABILITY_GUARDIAN; }
    PARAMETRIZE { ability = ABILITY_COSMIC_FORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_BITE); }
    } SCENE {
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(gBattleHistory->abilities[B_POSITION_OPPONENT_LEFT], ability);
        EXPECT_NE(gBattleHistory->abilities[B_POSITION_PLAYER_LEFT], ability);
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

SINGLE_BATTLE_TEST("Coalwalker works while its holder is airborne", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_COALWALKER; }
    SetStartingStatus(STARTING_STATUS_SCORCHED_FIELD);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Attack(200); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ability); Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
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

SINGLE_BATTLE_TEST("Nine Lives has Sturdy and adds priority at low HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NINE_LIVES); HP(33); MaxHP(99); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

SINGLE_BATTLE_TEST("Reborn prevents a KO once and restores full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        HP_BAR(player, damage: -50);
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Reborn prevents a KO from poison damage and restores full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); HP(10); MaxHP(80); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(player, damage: -70);
        ABILITY_POPUP(player, ABILITY_REBORN);
    } THEN {
        EXPECT_EQ(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Reborn can be followed by another innate popup for the same battler")
{
    PASSES_RANDOMLY(3, 10, RNG_FLAME_BODY);
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_REBORN); Innates(ABILITY_FLAME_BODY); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, damage: -99);
        ABILITY_POPUP(opponent, ABILITY_REBORN);
        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
    } THEN {
        EXPECT_EQ(opponent->hp, 100);
        EXPECT(player->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Smouldering makes Water-type moves ineffective and raises Sp. Def")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SMOULDERING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SMOULDERING);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF { HP_BAR(player); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Sandshield doubles Defense during sandstorm", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SANDSHIELD; }
    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
