#include "global.h"
#include "battle_boss.h"
#include "battle_util.h"
#include "event_data.h"
#include "item_use.h"
#include "money.h"
#include "palette.h"
#include "pokemon.h"
#include "sprite.h"
#include "test/battle.h"

static void ConfigureTestBoss(u8 bars, u16 megaSpecies, u8 statMultiplier)
{
    ConfigureBossBattle(bars, megaSpecies, statMultiplier);
    gBattleTestRunnerState->data.recordedBattle.battleFlags |= BATTLE_TYPE_BOSS;
}

static void ExpectBossPhaseActive(void)
{
    enum BattlerId boss = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

    EXPECT(IsBattlerAlive(boss));
    EXPECT(!gBattleStruct->battlerState[boss].fainted);
    EXPECT(!(gHitMarker & HITMARKER_FAINTED(boss)));
    EXPECT(!gBattleSpritesDataPtr->battlerData[boss].invisible);
    EXPECT(gBattlerSpriteIds[boss] < MAX_SPRITES);
    EXPECT(!gSprites[gBattlerSpriteIds[boss]].invisible);
}

SINGLE_BATTLE_TEST("This test checks that raid boss health bars are protected from overkill")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Status1(STATUS1_TOXIC_POISON); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(4, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, player);
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BOSS_BARRIER_BREAK, opponent);
        MESSAGE("The opposing Wobbuffet's barrier broke! It's still standing!");
    } THEN {
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(gBattleStruct->boss.totalBars, 4);
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 3);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_STATUS), STATUS1_NONE);
        ExpectBossPhaseActive();
        EXPECT_EQ(CountVisibleBossHealthBarSprites(), 2);
        gBattleStruct->boss.barsRemaining = 4;
        SyncBossHealthBarSprites(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        EXPECT_EQ(CountVisibleBossHealthBarSprites(), 3);
    }
}

WILD_BATTLE_TEST("Raid boss: Poké Balls are blocked before every reserve bar and the final bar are depleted")
{
    u32 bars, barsBroken;

    PARAMETRIZE { bars = 2; barsBroken = 0; }
    PARAMETRIZE { bars = 3; barsBroken = 0; }
    PARAMETRIZE { bars = 3; barsBroken = 1; }
    PARAMETRIZE { bars = 3; barsBroken = 2; }
    PARAMETRIZE { bars = 4; barsBroken = 0; }
    PARAMETRIZE { bars = 4; barsBroken = 1; }
    PARAMETRIZE { bars = 4; barsBroken = 2; }
    PARAMETRIZE { bars = 4; barsBroken = 3; }

    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(bars, SPECIES_NONE, 100);
    } WHEN {
        for (u32 i = 0; i < barsBroken; i++)
            TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { USE_ITEM(player, ITEM_POKE_BALL); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(CanThrowBall(), FALSE);
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, bars - barsBroken);
    }
}

WILD_BATTLE_TEST("Raid boss: the final health bar enables a guaranteed victory capture")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        VICTORY_CATCH(ITEM_POKE_BALL);
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WYNAUT) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_DRAGON_RAGE); }
    } SCENE {
        MESSAGE("The wild Wynaut's barrier broke! It's making a last stand!");
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_CAUGHT);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_WYNAUT);
    }
}

WILD_BATTLE_TEST("Raid boss: cancelling the Ball menu returns to the victory capture prompt")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        VICTORY_CATCH_CANCEL_THEN(ITEM_POKE_BALL);
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WYNAUT) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(1, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_CAUGHT);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Raid boss: intermediate barriers preserve lowered stat stages")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CHARM) == EFFECT_ATTACK_DOWN_2);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CHARM, MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Raid boss: entering the last health bar clears lowered stat stages")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CHARM) == EFFECT_ATTACK_DOWN_2);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CHARM, MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Raid boss: entering the last health bar preserves raised stat stages")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SWORDS_DANCE) == EFFECT_ATTACK_UP_2);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CELEBRATE, MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_SWORDS_DANCE, MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Raid boss: OHKO moves consume exactly one health bar")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_DUGTRIO) { Speed(100); Moves(MOVE_FISSURE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE, hit: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Raid boss: multi-hit moves cannot spill through reserve health bars")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_BULLET_SEED));
        PLAYER(SPECIES_CLOYSTER) { Ability(ABILITY_SKILL_LINK); Speed(100); Moves(MOVE_BULLET_SEED); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Raid boss: poison damage breaks one health bar")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Status1(STATUS1_POISON); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_STATUS), STATUS1_NONE);
        ExpectBossPhaseActive();
    }
}

SINGLE_BATTLE_TEST("Raid boss: bad poison damage breaks one health bar and is cleared")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Status1(STATUS1_TOXIC_POISON); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_STATUS), STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Raid boss: every major status is cleared at each barrier break")
{
    u32 status;

    PARAMETRIZE { status = STATUS1_SLEEP_TURN(3); }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }

    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Status1(status); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 2);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
        EXPECT_EQ(GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_STATUS), STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Raid boss: weather damage breaks one health bar")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SANDSTORM);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        ExpectBossPhaseActive();
    }
}

SINGLE_BATTLE_TEST("Raid boss: recoil damage breaks one health bar")
{
    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_DOUBLE_EDGE) > 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); Defense(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Attack(200); Moves(MOVE_DOUBLE_EDGE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_DOUBLE_EDGE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        ExpectBossPhaseActive();
    }
}

SINGLE_BATTLE_TEST("Raid boss: Perish Song breaks one health bar")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        PLAYER(SPECIES_MR_MIME) { Ability(ABILITY_SOUNDPROOF); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_PERISH_SONG, MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_PERISH_SONG); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        ExpectBossPhaseActive();
    }
}

SINGLE_BATTLE_TEST("Raid boss: a residual phase break preserves Mega form, boosted stats, raised stages, and visibility")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        PLAYER(SPECIES_MR_MIME) { HP(200); MaxHP(200); Ability(ABILITY_SOUNDPROOF); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MANECTRIC) { Moves(MOVE_PERISH_SONG, MOVE_SWORDS_DANCE, MOVE_CELEBRATE, MOVE_TACKLE); }
        ConfigureTestBoss(2, SPECIES_NONE, 110);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_PERISH_SONG); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    } THEN {
        u32 unboostedAttack = GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_ATK);

        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->species, SPECIES_MANECTRIC_MEGA);
        EXPECT_EQ(opponent->ability, ABILITY_INTIMIDATE);
        EXPECT_EQ(opponent->attack, unboostedAttack * 110 / 100);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        ExpectBossPhaseActive();
    }
}

WILD_BATTLE_TEST("Raid boss: a final-bar Perish Song self-KO starts guaranteed victory capture before fainting")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        VICTORY_CATCH(ITEM_POKE_BALL);
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_MR_MIME) { Ability(ABILITY_SOUNDPROOF); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_PERISH_SONG, MOVE_CELEBRATE); }
        ConfigureTestBoss(1, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_PERISH_SONG); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF { MESSAGE("The wild Wynaut fainted!"); }
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_CAUGHT);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Raid boss: confusion self-damage breaks one health bar")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CONFUSE_RAY); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, TRUE)); }
    } THEN {
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
        ExpectBossPhaseActive();
    }
}

SINGLE_BATTLE_TEST("Raid boss: Destiny Bond does not trigger on an intermediate health bar")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DESTINY_BOND) == EFFECT_DESTINY_BOND);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(100); Moves(MOVE_DESTINY_BOND); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_DESTINY_BOND); }
    } SCENE {
        NONE_OF { MESSAGE("Wobbuffet took its attacker down with it!"); HP_BAR(player); }
    } THEN {
        EXPECT_GT(player->hp, 0);
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
    }
}

SINGLE_BATTLE_TEST("Raid boss: Grudge does not trigger on an intermediate health bar")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRUDGE) == EFFECT_GRUDGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(100); Moves(MOVE_GRUDGE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_GRUDGE); }
    } THEN {
        EXPECT_GT(player->pp[0], 0);
        EXPECT_EQ(gBattleStruct->boss.barsRemaining, 1);
    }
}

SINGLE_BATTLE_TEST("Raid boss: Mega animation, message, ability, and boosted stats initialize exactly once")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MANECTRIC) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 110);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Manectric is surging with power!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("The opposing Manectric transformed into Mega Manectric!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
            MESSAGE("The opposing Manectric is surging with power!");
        }
    } THEN {
        u32 unboostedAttack = GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_ATK);
        EXPECT_EQ(opponent->species, SPECIES_MANECTRIC_MEGA);
        EXPECT_EQ(opponent->ability, ABILITY_INTIMIDATE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->attack, unboostedAttack * 110 / 100);
        EXPECT(gBattleStruct->boss.initialized);
    }
}

SINGLE_BATTLE_TEST("Raid boss: Mewtwo supports explicit Mega X and Mega Y selection")
{
    u16 megaSpecies;

    PARAMETRIZE { megaSpecies = SPECIES_MEWTWO_MEGA_X; }
    PARAMETRIZE { megaSpecies = SPECIES_MEWTWO_MEGA_Y; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MEWTWO) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, megaSpecies, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(opponent->species, megaSpecies);
    }
}

SINGLE_BATTLE_TEST("Raid boss: stat recalculation reapplies the boost once and capture normalization excludes it")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MANECTRIC) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 110);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId boss = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        struct Pokemon *mon = GetBattlerMon(boss);
        u32 unboostedAttack = GetMonData(mon, MON_DATA_ATK);
        u8 savedOutcome = gBattleOutcome;

        gBattleOutcome = 0;
        RecalcBattlerStats(boss, mon, FALSE);
        EXPECT_EQ(opponent->attack, unboostedAttack * 110 / 100);
        gBattleStruct->victoryCatchState = VICTORY_CATCH_OPEN_BAG;
        RecalcBattlerStats(boss, mon, FALSE);
        EXPECT_EQ(opponent->attack, unboostedAttack);
        gBattleStruct->victoryCatchState = VICTORY_CATCH_START;
        gBattleOutcome = B_OUTCOME_RAN;
        RecalcBattlerStats(boss, mon, FALSE);
        EXPECT_EQ(opponent->attack, unboostedAttack);
        gBattleOutcome = savedOutcome;
    }
}

SINGLE_BATTLE_TEST("Raid boss: invalid or unrelated explicit Mega species are rejected without automatic fallback")
{
    u16 megaSpecies;

    PARAMETRIZE { megaSpecies = NUM_SPECIES + 10; }
    PARAMETRIZE { megaSpecies = SPECIES_GYARADOS_MEGA; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MANECTRIC) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, megaSpecies, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MANECTRIC);
    }
}

SINGLE_BATTLE_TEST("Raid boss: a species with one Mega resolves its form automatically")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GYARADOS) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_GYARADOS_MEGA);
    }
}

WILD_BATTLE_TEST("Raid boss: a captured Mega boss reverts to its base form and normal stats")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        VICTORY_CATCH(ITEM_POKE_BALL);
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_GYARADOS) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(1, SPECIES_NONE, 110);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); }
    } THEN {
        struct Pokemon expected = gPlayerParty[1];
        CalculateMonStats(&expected);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_GYARADOS);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_ATK), GetMonData(&expected, MON_DATA_ATK));
    }
}

SINGLE_BATTLE_TEST("Raid boss: health markers resynchronize from remaining bars after Bag reconstruction")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId boss = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
        {
            u8 spriteId = gBattleStruct->boss.barrierSpriteIds[i];
            if (spriteId < MAX_SPRITES)
                DestroySprite(&gSprites[spriteId]);
            gBattleStruct->boss.barrierSpriteIds[i] = SPRITE_NONE;
        }
        CreateBossHealthBarSprites(boss);
        EXPECT_EQ(CountVisibleBossHealthBarSprites(), 1);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].x, gSprites[gHealthboxSpriteIds[boss]].x + 45);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].y, gSprites[gHealthboxSpriteIds[boss]].y + 7);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].x - gSprites[gBattleStruct->boss.barrierSpriteIds[1]].x, 14);
        EXPECT(IS_BLEND_IMMUNE_TAG(GetSpritePaletteTagByPaletteNum(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].oam.paletteNum)));

        s16 markerX = gSprites[gBattleStruct->boss.barrierSpriteIds[0]].x;
        s16 markerY = gSprites[gBattleStruct->boss.barrierSpriteIds[0]].y;
        gSprites[gHealthboxSpriteIds[boss]].x += 12;
        gSprites[gHealthboxSpriteIds[boss]].y += 6;
        gSprites[gHealthboxSpriteIds[boss]].x2 = 7;
        gSprites[gHealthboxSpriteIds[boss]].y2 = -3;
        gSprites[gHealthboxSpriteIds[boss]].oam.priority = 0;
        SyncBossHealthBarSprites(boss);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].x, markerX);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].y, markerY);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].x2, 7);
        EXPECT_EQ(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].y2, -3);
        EXPECT(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].oam.priority == 0);

        u32 paletteOffset = OBJ_PLTT_ID(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].oam.paletteNum);
        bool32 paletteFadeWasActive = gPaletteFade.active;
        gPaletteFade.active = FALSE;
        gPlttBufferFaded[paletteOffset + 1] = 0;
        SyncBossHealthBarSprites(boss);
        EXPECT_EQ(gPlttBufferFaded[paletteOffset + 1], gPlttBufferUnfaded[paletteOffset + 1]);
        gPaletteFade.active = paletteFadeWasActive;
    }
}

SINGLE_BATTLE_TEST("Raid boss: barrier recreation ignores stale sprite IDs and callbacks tolerate a missing healthbox")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(3, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId boss = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        u8 oldBarrier = gBattleStruct->boss.barrierSpriteIds[0];
        u8 unrelatedSprite;
        u8 healthboxSpriteId;

        DestroySprite(&gSprites[oldBarrier]);
        unrelatedSprite = CreateSprite(&gDummySpriteTemplate, 0, 0, 0);
        gBattleStruct->boss.barrierSpriteIds[0] = unrelatedSprite;
        CreateBossHealthBarSprites(boss);
        EXPECT(gSprites[unrelatedSprite].inUse);
        EXPECT(gSprites[unrelatedSprite].template == &gDummySpriteTemplate);
        EXPECT(gBattleStruct->boss.barrierSpriteIds[0] != unrelatedSprite);

        healthboxSpriteId = gHealthboxSpriteIds[boss];
        gHealthboxSpriteIds[boss] = SPRITE_NONE;
        gSprites[gBattleStruct->boss.barrierSpriteIds[0]].callback(&gSprites[gBattleStruct->boss.barrierSpriteIds[0]]);
        EXPECT(gSprites[gBattleStruct->boss.barrierSpriteIds[0]].invisible);
        gHealthboxSpriteIds[boss] = healthboxSpriteId;
    }
}

WILD_BATTLE_TEST("Raid boss: confirming Run forfeits and tears down boss configuration")
{
    GIVEN {
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Ability(ABILITY_RUN_AWAY); Item(ITEM_SMOKE_BALL); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        SetMoney(&gSaveBlock1Ptr->money, 0);
        FlagSet(B_FLAG_NO_RUNNING);
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { RUN(player); }
    } SCENE {
        MESSAGE("You panicked and dropped ¥0…");
        NOT MESSAGE("You gave ¥0 to the winner…");
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_FORFEITED);
        FlagClear(B_FLAG_NO_RUNNING);
    }
}

WILD_BATTLE_TEST("Raid boss: escape items are unavailable")
{
    u32 item;

    PARAMETRIZE { item = ITEM_POKE_DOLL; }
    PARAMETRIZE { item = ITEM_FLUFFY_TAIL; }
    PARAMETRIZE { item = ITEM_POKE_TOY; }

    GIVEN {
        ASSUME(GetItemBattleUsage(item) == EFFECT_ITEM_ESCAPE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(CannotUseItemsInBattle(item, &gPlayerParty[0]));
    }
}

WILD_BATTLE_TEST("Raid boss: Teleport cannot escape or switch the player")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_TELEPORT); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEPORT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Teleport!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(gBattlerPartyIndexes[B_POSITION_PLAYER_LEFT], 0);
    }
}

WILD_BATTLE_TEST("Raid boss: forced switching replaces the player without ending the battle")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_ROAR); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_ROAR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROAR, opponent);
        MESSAGE("Wynaut was dragged out!");
    } THEN {
        EXPECT_EQ(gBattlerPartyIndexes[B_POSITION_PLAYER_LEFT], 1);
    }
}

WILD_BATTLE_TEST("Raid boss: forced switching cannot remove the boss")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROAR) == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_ROAR); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_ROAR); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Roar!");
        MESSAGE("But it failed!");
    }
}

WILD_BATTLE_TEST("Raid boss: Emergency Exit switches the player when a reserve is available")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(100); HP(100); Speed(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_SUPER_FANG); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUPER_FANG); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(gBattlerPartyIndexes[B_POSITION_PLAYER_LEFT], 1);
    }
}

WILD_BATTLE_TEST("Raid boss: Emergency Exit cannot end the battle without a reserve")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(100); HP(100); Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_SUPER_FANG); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
    }
}

WILD_BATTLE_TEST("Raid boss: a fainted player Pokémon must be replaced instead of offering escape")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET) { HP(20); MaxHP(20); Speed(100); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE); }
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_DRAGON_RAGE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        NOT MESSAGE("Use next Pokémon?");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(gBattlerPartyIndexes[B_POSITION_PLAYER_LEFT], 1);
    }
}

WILD_BATTLE_TEST("Raid boss: losing tears down boss configuration before the next battle")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        SetMoney(&gSaveBlock1Ptr->money, 0);
        ConfigureTestBoss(2, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        MESSAGE("You panicked and dropped ¥0…");
        NOT MESSAGE("You gave ¥0 to the winner…");
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_LOST);
    }
}

WILD_BATTLE_TEST("Raid boss: declining the victory capture tears down boss configuration")
{
    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        DECLINE_VICTORY_CATCH;
        EXPECT_BOSS_CLEANUP;
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WYNAUT) { HP(20); MaxHP(20); Speed(1); Moves(MOVE_CELEBRATE); }
        ConfigureTestBoss(1, SPECIES_NONE, 100);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); }
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_NONE);
    }
}

SINGLE_BATTLE_TEST("Raid boss: cancelling setup leaves the following battle ordinary")
{
    GIVEN {
        ConfigureTestBoss(3, SPECIES_NONE, 110);
        CancelBossBattleConfiguration();
        gBattleTestRunnerState->data.recordedBattle.battleFlags &= ~BATTLE_TYPE_BOSS;
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(IsBossBattle(), FALSE);
        EXPECT_EQ(IsBossBattlePending(), FALSE);
        EXPECT_EQ(FlagGet(B_FLAG_VICTORY_CATCH_GUARANTEED), FALSE);
    }
}

WILD_BATTLE_TEST("Raid boss: pending configuration does not promote an ordinary wild battle or enable victory catch")
{
    GIVEN {
        ConfigureBossBattle(3, SPECIES_NONE, 110);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(!IsBossBattle());
        EXPECT(!IsBossBattlePending());
        EXPECT(!IsVictoryCatch());
        EXPECT(!IsVictoryCatchGuaranteed());
        EXPECT(!FlagGet(B_FLAG_VICTORY_CATCH_GUARANTEED));
    }
}

DOUBLE_BATTLE_TEST("Raid boss: boss mechanics are rejected outside singles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        ConfigureTestBoss(3, SPECIES_NONE, 110);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } THEN {
        EXPECT_EQ(IsBossBattle(), FALSE);
        EXPECT_EQ(FlagGet(B_FLAG_VICTORY_CATCH_GUARANTEED), FALSE);
    }
}
