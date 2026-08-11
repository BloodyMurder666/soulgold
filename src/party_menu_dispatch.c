#include "global.h"
#include "party_menu.h"
#include "constants/battle.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"

#if PARTY_MENU_STYLE_OPTION

// State shared by both implementations. The selected implementation owns its
// private menu state, while callers continue to use the original public API.
EWRAM_DATA struct PartyMenu gPartyMenu = {0};
EWRAM_DATA bool8 gPartyMenuUseExitCallback = FALSE;
EWRAM_DATA u8 gSelectedMonPartyId = 0;
EWRAM_DATA MainCallback gPostMenuFieldCallback = NULL;
EWRAM_DATA u8 gSelectedOrderFromParty[MAX_FRONTIER_PARTY_SIZE] = {0};
EWRAM_DATA u8 gBattlePartyCurrentOrder[PARTY_SIZE / 2] = {0};
COMMON_DATA void (*gItemUseCB)(u8, TaskFunc) = NULL;

static u8 GetPartyMenuOption(void)
{
    u8 option;

    if (gSaveBlock1Ptr != NULL && gSaveBlock1Ptr->optionsPartyMenuStyleMagic == PARTY_MENU_OPTION_SAVE_MAGIC)
    {
        option = gSaveBlock1Ptr->optionsPartyMenuStyle;
        if (option < PARTY_MENU_OPTION_COUNT)
            return option;
        return PARTY_MENU_DEFAULT_OPTION;
    }

    if (gSaveBlock2Ptr != NULL && gSaveBlock2Ptr->unused1)
        return PARTY_MENU_OPTION_BW;

    return PARTY_MENU_DEFAULT_OPTION;
}

#define BW_FUNC(name) BwPartyMenu_ ## name
#define HGSS_FUNC(name) HgssPartyMenu_ ## name
#define SWSH_FUNC(name) SwShPartyMenu_ ## name

#define DISPATCH_RET(returnType, name, params, args)  \
    extern returnType BW_FUNC(name) params;           \
    extern returnType HGSS_FUNC(name) params;         \
    extern returnType SWSH_FUNC(name) params;         \
    returnType name params                            \
    {                                                 \
        switch (GetPartyMenuOption())                 \
        {                                             \
        case PARTY_MENU_OPTION_BW:                    \
            return BW_FUNC(name) args;                \
        case PARTY_MENU_OPTION_HGSS:                  \
            return HGSS_FUNC(name) args;              \
        default:                                      \
            return SWSH_FUNC(name) args;              \
        }                                             \
    }

#define DISPATCH_VOID(name, params, args)        \
    extern void BW_FUNC(name) params;             \
    extern void HGSS_FUNC(name) params;           \
    extern void SWSH_FUNC(name) params;           \
    void name params                              \
    {                                             \
        switch (GetPartyMenuOption())             \
        {                                         \
        case PARTY_MENU_OPTION_BW:                \
            BW_FUNC(name) args;                   \
            break;                                \
        case PARTY_MENU_OPTION_HGSS:              \
            HGSS_FUNC(name) args;                 \
            break;                                \
        default:                                  \
            SWSH_FUNC(name) args;                 \
            break;                                \
        }                                         \
    }

DISPATCH_VOID(AnimatePartySlot, (u8 slot, u8 animNum), (slot, animNum))
DISPATCH_VOID(BattlePyramidChooseMonHeldItems, (void), ())
DISPATCH_RET(bool8, BoxMonKnowsMove, (struct BoxPokemon *boxMon, enum Move move), (boxMon, move))
DISPATCH_VOID(BufferBattlePartyCurrentOrder, (void), ())
DISPATCH_VOID(BufferBattlePartyCurrentOrderBySide, (enum BattlerId battler, u8 flankId), (battler, flankId))
DISPATCH_VOID(BufferMoveDeleterNicknameAndMove, (void), ())
DISPATCH_VOID(CB2_ChooseMonToGiveItem, (void), ())
DISPATCH_RET(bool8, CB2_FadeFromPartyMenu, (void), ())
DISPATCH_VOID(CB2_PartyMenuFromStartMenu, (void), ())
DISPATCH_VOID(CB2_ReturnToPartyMenuFromFlyMap, (void), ())
DISPATCH_VOID(CB2_ReturnToPartyMenuFromSummaryScreen, (void), ())
DISPATCH_VOID(CB2_ShowPartyMenuForItemUse, (void), ())
DISPATCH_VOID(ChangeRotomForm, (void), ())
DISPATCH_VOID(ChooseContestMon, (void), ())
DISPATCH_VOID(ChooseMonForDaycare, (void), ())
DISPATCH_VOID(ChooseMonForInBattleItem, (void), ())
DISPATCH_VOID(ChooseMonForMoveRelearner, (void), ())
DISPATCH_VOID(ChooseMonForMoveTutor, (void), ())
DISPATCH_VOID(ChooseMonForTradingBoard, (u8 menuType, MainCallback callback), (menuType, callback))
DISPATCH_VOID(ChooseMonForWirelessMinigame, (void), ())
DISPATCH_VOID(ChooseMonToGiveMailFromMailbox, (void), ())
DISPATCH_VOID(ChoosePartyMon, (void), ())
DISPATCH_VOID(ClearSelectedPartyOrder, (void), ())
DISPATCH_VOID(CursorCb_MoveItemCallback, (u8 taskId), (taskId))
DISPATCH_VOID(DeleteMove, (struct Pokemon *mon, enum Move move), (mon, move))
DISPATCH_RET(u8, DisplayPartyMenuMessage, (const u8 *str, bool8 keepOpen), (str, keepOpen))
DISPATCH_VOID(DisplayPartyMenuStdMessage, (u32 stringId), (stringId))
DISPATCH_VOID(DoBattlePyramidMonsHaveHeldItem, (void), ())
DISPATCH_RET(bool32, DoesMonHaveAnyMoves, (struct Pokemon *mon), (mon))
DISPATCH_VOID(DrawHeldItemIconsForTrade, (u8 *partyCounts, u8 *partySpriteIds, u8 whichParty), (partyCounts, partySpriteIds, whichParty))
DISPATCH_RET(bool8, FieldCallback_PrepareFadeInForTeleport, (void), ())
DISPATCH_RET(bool8, FieldCallback_PrepareFadeInFromMenu, (void), ())
DISPATCH_VOID(FormChangeTeachMove, (u8 taskId, enum Move move, u32 slot), (taskId, move, slot))
DISPATCH_RET(u8, GetAilmentFromStatus, (u32 status), (status))
DISPATCH_RET(u8, GetCursorSelectionMonId, (void), ())
DISPATCH_RET(enum ItemEffectType, GetItemEffectType, (enum Item item), (item))
DISPATCH_RET(u8, GetMonAilment, (struct Pokemon *mon), (mon))
DISPATCH_RET(u8 *, GetMonNickname, (struct Pokemon *mon, u8 *dest), (mon, dest))
DISPATCH_VOID(GetNumMovesSelectedMonHas, (void), ())
DISPATCH_RET(u8, GetPartyIdFromBattlePartyId, (u8 battlePartyId), (battlePartyId))
DISPATCH_RET(u8, GetPartyMenuType, (void), ())
DISPATCH_VOID(InitChooseHalfPartyForBattle, (u8 unused), (unused))
DISPATCH_VOID(IsLastMonThatKnowsSurf, (void), ())
DISPATCH_RET(bool8, IsMultiBattle, (void), ())
DISPATCH_RET(bool8, IsPartyMenuTextPrinterActive, (void), ())
DISPATCH_VOID(IsSelectedMonEgg, (void), ())
DISPATCH_RET(enum Move, ItemIdToBattleMoveId, (enum Item item), (item))
DISPATCH_VOID(ItemUseCB_AbilityCapsule, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_AbilityPatch, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_BattleChooseMove, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_BattleScript, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_ChangePokeball, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_DynamaxCandy, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_EvolutionStone, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_FormChange, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_FormChange_ConsumedOnUse, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_Fusion, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_Medicine, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_Mint, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_PPRecovery, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_PPUp, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_RareCandy, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_ReduceEV, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_ResetEVs, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_RotomCatalog, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_SacredAsh, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_ShinGenome, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_TMHM, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(ItemUseCB_ZygardeCube, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_VOID(LoadHeldItemIcons, (void), ())
DISPATCH_VOID(LoadPartyMenuAilmentGfx, (void), ())
DISPATCH_RET(bool8, MonKnowsMove, (struct Pokemon *mon, enum Move move), (mon, move))
DISPATCH_VOID(MoveDeleterChooseMoveToForget, (void), ())
DISPATCH_VOID(MoveDeleterForgetMove, (void), ())
DISPATCH_VOID(OpenPartyMenuInBattle, (u8 partyAction), (partyAction))
DISPATCH_VOID(PartyMenuModifyHP, (u8 taskId, u8 slot, s8 hpIncrement, s16 hpDifference, TaskFunc task), (taskId, slot, hpIncrement, hpDifference, task))
DISPATCH_RET(bool8, PlayerHasMove, (enum Move move), (move))
DISPATCH_RET(bool32, SetUpFieldMove_Dive, (void), ())
DISPATCH_RET(bool32, SetUpFieldMove_Fly, (void), ())
DISPATCH_RET(bool32, SetUpFieldMove_RockClimb, (void), ())
DISPATCH_RET(bool32, SetUpFieldMove_Surf, (void), ())
DISPATCH_RET(bool32, SetUpFieldMove_Waterfall, (void), ())
DISPATCH_RET(bool32, SetUpFieldMove_Whirlpool, (void), ())
DISPATCH_VOID(ShowPartyMenuToShowcaseMultiBattleParty, (void), ())
DISPATCH_VOID(SwitchPartyMonSlots, (u8 slot, u8 slot2), (slot, slot2))
DISPATCH_VOID(SwitchPartyOrderLinkMulti, (enum BattlerId battler, u8 slot, u8 slot2), (battler, slot, slot2))
DISPATCH_VOID(Task_AbilityCapsule, (u8 taskId), (taskId))
DISPATCH_VOID(Task_AbilityPatch, (u8 taskId), (taskId))
DISPATCH_VOID(Task_DynamaxCandy, (u8 taskId), (taskId))
DISPATCH_VOID(Task_HandleChooseMonInput, (u8 taskId), (taskId))
DISPATCH_VOID(Task_Mint, (u8 taskId), (taskId))
DISPATCH_VOID(Task_ShinGenome, (u8 taskId), (taskId))
DISPATCH_VOID(TryItemHoldFormChange, (struct Pokemon *mon, s8 slotId), (mon, slotId))
DISPATCH_RET(bool32, TryItemUseFormChange, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_RET(bool32, TryItemUseFusionChange, (u8 taskId, TaskFunc task), (taskId, task))
DISPATCH_RET(bool32, TryMultichoiceFormChange, (u8 taskId), (taskId))

#undef DISPATCH_VOID
#undef DISPATCH_RET
#undef SWSH_FUNC
#undef HGSS_FUNC
#undef BW_FUNC

#endif // PARTY_MENU_STYLE_OPTION
