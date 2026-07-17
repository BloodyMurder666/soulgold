#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_boss.h"
#include "battle_gimmick.h"
#include "battle_interface.h"
#include "battle_util.h"
#include "event_data.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "sprite.h"
#include "constants/form_change_types.h"

#define TAG_BOSS_BARRIER_TILE  0x57B0
#define TAG_BOSS_BARRIER_PAL   (0x57B1 | BLEND_IMMUNE_FLAG)
#define BOSS_BARRIER_SPACING   14

static const s8 sBossBarrierPosition[2] = {45, 7};

enum
{
    BOSS_BARRIER_BROKE,
    BOSS_LAST_STAND,
};

struct PendingBossBattle
{
    u16 megaSpecies;
    u8 totalBars;
    u8 statMultiplier;
    bool8 autoMega;
    bool8 active;
};

static EWRAM_DATA struct PendingBossBattle sPendingBossBattle = {0};

static const u32 sBossBarrierGfx[] = INCBIN_U32("graphics/raid/raid_barrier.4bpp");
static const u16 sBossBarrierPal[] = INCBIN_U16("graphics/raid/raid_barrier.gbapal");

static void SpriteCB_BossBarrier(struct Sprite *sprite);

static const struct OamData sOamData_BossBarrier =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sBossBarrierSpriteSheet =
{
    .data = sBossBarrierGfx,
    .size = sizeof(sBossBarrierGfx),
    .tag = TAG_BOSS_BARRIER_TILE,
};

static const struct SpritePalette sBossBarrierSpritePalette =
{
    .data = sBossBarrierPal,
    .tag = TAG_BOSS_BARRIER_PAL,
};

static const struct SpriteTemplate sBossBarrierSpriteTemplate =
{
    .tileTag = TAG_BOSS_BARRIER_TILE,
    .paletteTag = TAG_BOSS_BARRIER_PAL,
    .oam = &sOamData_BossBarrier,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_BossBarrier,
};

bool32 IsBossBattlePending(void)
{
    return sPendingBossBattle.active;
}

void ConfigureBossBattle(u8 totalBars, u16 megaSpecies, u8 statMultiplier)
{
    bool8 autoMega = megaSpecies == SPECIES_NONE;

    totalBars = min(MAX_BOSS_HEALTH_BARS, max(1, totalBars));
    if (statMultiplier == 0)
        statMultiplier = DEFAULT_BOSS_STAT_MULTIPLIER;
    if (!autoMega && (megaSpecies >= NUM_SPECIES || !IsSpeciesEnabled(megaSpecies)))
        megaSpecies = SPECIES_NONE;
    if (gBattleStruct != NULL && gMain.inBattle && IsDoubleBattle())
    {
        CancelBossBattleConfiguration();
        return;
    }

    if (gBattleStruct != NULL && gMain.inBattle)
    {
        gBattleTypeFlags |= BATTLE_TYPE_BOSS;
        gBattleStruct->boss.megaSpecies = megaSpecies;
        gBattleStruct->boss.totalBars = totalBars;
        gBattleStruct->boss.barsRemaining = totalBars;
        gBattleStruct->boss.statMultiplier = statMultiplier;
        gBattleStruct->boss.autoMega = autoMega;
        gBattleStruct->boss.active = TRUE;
        gBattleStruct->boss.initialized = FALSE;
        for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
            gBattleStruct->boss.barrierSpriteIds[i] = SPRITE_NONE;
    }
    else
    {
        sPendingBossBattle.megaSpecies = megaSpecies;
        sPendingBossBattle.totalBars = totalBars;
        sPendingBossBattle.statMultiplier = statMultiplier;
        sPendingBossBattle.autoMega = autoMega;
        sPendingBossBattle.active = TRUE;
    }
}

void CancelBossBattleConfiguration(void)
{
    memset(&sPendingBossBattle, 0, sizeof(sPendingBossBattle));
    gBattleTypeFlags &= ~BATTLE_TYPE_BOSS;
}

void ScriptConfigureBossBattle(struct ScriptContext *ctx)
{
    u16 totalBars = VarGet(ScriptReadHalfword(ctx));
    u16 megaSpecies = VarGet(ScriptReadHalfword(ctx));
    u16 statMultiplier = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);
    ConfigureBossBattle(totalBars, megaSpecies, statMultiplier);
}

void ScriptCancelBossBattle(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    CancelBossBattleConfiguration();
}

void InitBossBattleData(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_BOSS) && IsDoubleBattle())
    {
        CancelBossBattleConfiguration();
        return;
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_BOSS))
    {
        memset(&sPendingBossBattle, 0, sizeof(sPendingBossBattle));
        return;
    }

    gBattleStruct->boss.megaSpecies = sPendingBossBattle.megaSpecies;
    gBattleStruct->boss.totalBars = sPendingBossBattle.active ? sPendingBossBattle.totalBars : 2;
    gBattleStruct->boss.barsRemaining = gBattleStruct->boss.totalBars;
    gBattleStruct->boss.statMultiplier = sPendingBossBattle.active ? sPendingBossBattle.statMultiplier : DEFAULT_BOSS_STAT_MULTIPLIER;
    gBattleStruct->boss.autoMega = sPendingBossBattle.active ? sPendingBossBattle.autoMega : TRUE;
    gBattleStruct->boss.active = TRUE;
    gBattleStruct->boss.initialized = FALSE;
    for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
        gBattleStruct->boss.barrierSpriteIds[i] = SPRITE_NONE;

    memset(&sPendingBossBattle, 0, sizeof(sPendingBossBattle));
}

bool32 IsBossBattle(void)
{
    return gBattleStruct != NULL
        && (gBattleTypeFlags & BATTLE_TYPE_BOSS)
        && gBattleStruct->boss.active;
}

static u16 GetAutomaticBossMegaSpecies(enum BattlerId battler)
{
    const struct FormChange *formChanges = GetSpeciesFormChanges(gBattleMons[battler].species);

    for (u32 i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM
         || formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE)
            return formChanges[i].targetSpecies;
    }

    return SPECIES_NONE;
}

static bool32 IsLegalBossMegaSpecies(u16 baseSpecies, u16 targetSpecies)
{
    const struct FormChange *formChanges;

    if (targetSpecies == SPECIES_NONE
     || targetSpecies >= NUM_SPECIES
     || !IsSpeciesEnabled(targetSpecies))
        return FALSE;

    formChanges = GetSpeciesFormChanges(baseSpecies);
    for (u32 i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if ((formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM
          || formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE)
         && formChanges[i].targetSpecies == targetSpecies)
            return TRUE;
    }

    return FALSE;
}

static void ApplyBossStatMultiplier(enum BattlerId battler)
{
    u32 multiplier = gBattleStruct->boss.statMultiplier;

    gBattleMons[battler].attack = min(MAX_u16, gBattleMons[battler].attack * multiplier / 100);
    gBattleMons[battler].defense = min(MAX_u16, gBattleMons[battler].defense * multiplier / 100);
    gBattleMons[battler].speed = min(MAX_u16, gBattleMons[battler].speed * multiplier / 100);
    gBattleMons[battler].spAttack = min(MAX_u16, gBattleMons[battler].spAttack * multiplier / 100);
    gBattleMons[battler].spDefense = min(MAX_u16, gBattleMons[battler].spDefense * multiplier / 100);
}

void ApplyBossStatMultiplierAfterRecalculation(enum BattlerId battler)
{
    if (!IsBossBattle()
     || !gBattleStruct->boss.initialized
     || battler != GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)
     || gBattleOutcome != 0
     || gBattleStruct->victoryCatchState != VICTORY_CATCH_START)
        return;

    ApplyBossStatMultiplier(battler);
}

static bool32 ForceBossMegaEvolution(enum BattlerId battler, u16 targetSpecies)
{
    struct Pokemon *mon = GetBattlerMon(battler);
    struct PartyState *partyState = GetBattlerPartyState(battler);

    if (targetSpecies == SPECIES_NONE || targetSpecies == gBattleMons[battler].species)
        return FALSE;

    if (partyState != NULL && partyState->changedSpecies == SPECIES_NONE)
        partyState->changedSpecies = gBattleMons[battler].species;

    SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
    gBattleMons[battler].species = targetSpecies;
    RecalcBattlerStats(battler, mon, FALSE);
    SetActiveGimmick(battler, GIMMICK_MEGA);
    SetGimmickAsActivated(battler, GIMMICK_MEGA);
    return TRUE;
}

bool32 TryStartBossBattle(void)
{
    enum BattlerId battler;
    u16 megaSpecies;

    if (!IsBossBattle() || gBattleStruct->boss.initialized)
        return FALSE;

    battler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    megaSpecies = gBattleStruct->boss.megaSpecies;
    if (gBattleStruct->boss.autoMega)
        megaSpecies = GetAutomaticBossMegaSpecies(battler);
    else if (!IsLegalBossMegaSpecies(gBattleMons[battler].species, megaSpecies))
        megaSpecies = SPECIES_NONE;

    gBattleStruct->boss.initialized = TRUE;
    if (ForceBossMegaEvolution(battler, megaSpecies))
    {
        gBattlerAttacker = battler;
        gBattleScripting.battler = battler;
        return TRUE;
    }

    ApplyBossStatMultiplierAfterRecalculation(battler);
    return FALSE;
}

static void ResetBossPhaseConditions(enum BattlerId battler, bool32 enteringLastStand)
{
    u32 status = STATUS1_NONE;

    if (enteringLastStand)
    {
        for (enum Stat stat = 0; stat < NUM_BATTLE_STATS; stat++)
        {
            if (gBattleMons[battler].statStages[stat] < DEFAULT_STAT_STAGE)
                gBattleMons[battler].statStages[stat] = DEFAULT_STAT_STAGE;
        }
    }

    gBattleMons[battler].status1 = status;
    SetMonData(GetBattlerMon(battler), MON_DATA_STATUS, &status);

    gBattleMons[battler].volatiles.confusionTurns = 0;
    gBattleMons[battler].volatiles.infiniteConfusion = FALSE;
    gBattleMons[battler].volatiles.flinched = FALSE;
    gBattleMons[battler].volatiles.wrapped = FALSE;
    gBattleMons[battler].volatiles.infatuation = 0;
    gBattleMons[battler].volatiles.escapePrevention = FALSE;
    gBattleMons[battler].volatiles.leechSeed = 0;
    gBattleMons[battler].volatiles.perishSong = FALSE;
}

bool32 TryBossHealthBarBreak(enum BattlerId battler)
{
    u16 hp;

    if (!IsBossBattle()
     || battler != GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)
     || IsBattlerAlive(battler)
     || gBattleStruct->boss.barsRemaining <= 1)
        return FALSE;

    gBattleStruct->boss.barsRemaining--;
    // A phase boundary ends the current attack. Otherwise a multi-hit move
    // would continue striking the freshly restored bar.
    if (gMultiHitCounter > 1)
        gMultiHitCounter = 1;
    hp = gBattleMons[battler].maxHP;
    gBattleMons[battler].hp = hp;
    SetMonData(GetBattlerMon(battler), MON_DATA_HP, &hp);
    gBattleStruct->customTurnStartHp[battler] = hp;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleStruct->boss.barsRemaining == 1
        ? BOSS_LAST_STAND
        : BOSS_BARRIER_BROKE;
    ResetBossPhaseConditions(battler, gBattleStruct->boss.barsRemaining == 1);
    SyncBossHealthBarSprites(battler);
    return TRUE;
}

void RefreshBossHealthbox(enum BattlerId battler)
{
    if (!IsBossBattle()
     || battler >= gBattlersCount
     || gHealthboxSpriteIds[battler] >= MAX_SPRITES
     || !gSprites[gHealthboxSpriteIds[battler]].inUse)
        return;

    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
}

static void SpriteCB_BossBarrier(struct Sprite *sprite)
{
    enum BattlerId battler = sprite->data[0];
    u32 barrier = sprite->data[1];
    struct Sprite *healthbox;

    if (!IsBossBattle()
     || battler >= gBattlersCount
     || gHealthboxSpriteIds[battler] >= MAX_SPRITES
     || !gSprites[gHealthboxSpriteIds[battler]].inUse)
    {
        sprite->invisible = TRUE;
        return;
    }

    healthbox = &gSprites[gHealthboxSpriteIds[battler]];

    // The base position is fixed when the sprite is created. Follow only the
    // healthbox's movement offsets so both sprites remain synchronized.
    sprite->x2 = healthbox->x2;
    sprite->y2 = healthbox->y2;
    // Battle animations temporarily change healthbox priority. Matching it
    // keeps the barrier's lower subpriority consistently above the frame.
    sprite->oam.priority = healthbox->oam.priority;
    sprite->invisible = healthbox->invisible
        || barrier >= gBattleStruct->boss.barsRemaining - 1;

    // Time-of-day and weather blending operate on the faded buffer. Restore
    // this UI palette once normal screen fades have finished.
    if (barrier == 0 && !gPaletteFade.active)
        CpuCopy16(sBossBarrierPal, &gPlttBufferFaded[OBJ_PLTT_ID(sprite->oam.paletteNum)], PLTT_SIZE_4BPP);
}

void SyncBossHealthBarSprites(enum BattlerId battler)
{
    if (!IsBossBattle() || battler != GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
        return;

    for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
    {
        u8 spriteId = gBattleStruct->boss.barrierSpriteIds[i];
        if (spriteId < MAX_SPRITES
         && gSprites[spriteId].inUse
         && gSprites[spriteId].template == &sBossBarrierSpriteTemplate)
            SpriteCB_BossBarrier(&gSprites[spriteId]);
    }
}

u8 CountVisibleBossHealthBarSprites(void)
{
    u8 count = 0;

    if (!IsBossBattle())
        return 0;

    for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
    {
        u8 spriteId = gBattleStruct->boss.barrierSpriteIds[i];
        if (spriteId < MAX_SPRITES
         && gSprites[spriteId].inUse
         && gSprites[spriteId].template == &sBossBarrierSpriteTemplate
         && !gSprites[spriteId].invisible)
            count++;
    }
    return count;
}

void CreateBossHealthBarSprites(enum BattlerId battler)
{
    s16 x, y;

    if (!IsBossBattle()
     || battler != GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)
     || gBattleStruct->boss.totalBars <= 1
     || gHealthboxSpriteIds[battler] >= MAX_SPRITES
     || !gSprites[gHealthboxSpriteIds[battler]].inUse)
        return;

    for (u32 i = 0; i < ARRAY_COUNT(gBattleStruct->boss.barrierSpriteIds); i++)
    {
        u8 spriteId = gBattleStruct->boss.barrierSpriteIds[i];

        if (spriteId < MAX_SPRITES
         && gSprites[spriteId].inUse
         && gSprites[spriteId].template == &sBossBarrierSpriteTemplate)
            DestroySprite(&gSprites[spriteId]);
        gBattleStruct->boss.barrierSpriteIds[i] = SPRITE_NONE;
    }

    GetBattlerHealthboxCoords(battler, &x, &y);
    if (GetSpriteTileStartByTag(TAG_BOSS_BARRIER_TILE) == 0xFFFF)
        LoadSpriteSheet(&sBossBarrierSpriteSheet);
    if (IndexOfSpritePaletteTag(TAG_BOSS_BARRIER_PAL) == 0xFF)
        LoadSpritePalette(&sBossBarrierSpritePalette);

    for (u32 i = 0; i < gBattleStruct->boss.totalBars - 1; i++)
    {
        u8 spriteId = CreateSprite(&sBossBarrierSpriteTemplate,
                                   x + sBossBarrierPosition[0] - (s16)(i * BOSS_BARRIER_SPACING),
                                   y + sBossBarrierPosition[1],
                                   0);
        if (spriteId == MAX_SPRITES)
            break;
        gBattleStruct->boss.barrierSpriteIds[i] = spriteId;
        gSprites[spriteId].data[0] = battler;
        gSprites[spriteId].data[1] = i;
    }
    SyncBossHealthBarSprites(battler);
}
