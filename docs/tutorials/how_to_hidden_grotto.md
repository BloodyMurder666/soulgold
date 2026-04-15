# How to add Hidden Grottoes

This project’s hidden grotto implementation is data-driven from `src/hidden_grotto.c`, with per-grotto state stored in `SaveBlock3`.

## Save warning

Hidden grotto state is stored in `gSaveBlock3Ptr->hiddenGrottoContents`.
Changing `NUM_HIDDEN_GROTTOES` changes save data layout and is save-breaking.

## Add a new grotto in C

1. Increase `NUM_HIDDEN_GROTTOES` in `include/hidden_grotto.h`.

2. Add a new id to `enum HiddenGrottoId` in `src/hidden_grotto.c`.

Example:

```c
enum HiddenGrottoId
{
    HIDDEN_GROTTO_ROUTE32,
    HIDDEN_GROTTO_ILEX_FOREST,
};
```

3. Add a new entry to `sHiddenGrottoData` in `src/hidden_grotto.c`.

Each grotto entry needs:
- `mapGroup` and `mapNum`: the grotto map itself
- `monLevel`: level used by `HiddenGrotto_CreateCurrentMon`
- `monObjectLocalId`: the local object id of the placeholder Pokemon object in the grotto map
- `rareItem`: the grotto-specific rare item used by the weighted item table
- `mons[4]`: the four Pokemon slots used by the weighted Pokemon table

Example:

```c
[HIDDEN_GROTTO_ILEX_FOREST] =
{
    .mapGroup = MAP_GROUP(MAP_HIDDEN_GROTTO_ILEX_FOREST),
    .mapNum = MAP_NUM(MAP_HIDDEN_GROTTO_ILEX_FOREST),
    .monLevel = 9,
    .monObjectLocalId = 2,
    .rareItem = ITEM_LEAF_STONE,
    .mons =
    {
        { SPECIES_PARAS, 0 },
        { SPECIES_ODDISH, 0 },
        { SPECIES_PSYDUCK, 0 },
        { SPECIES_PINECO, 0 },
    },
},
```

If you need a form species, use the base species plus the form id stored in the second field.

## Add the grotto map objects

In the grotto map JSON:

- The item-ball placeholder should use local id `1` unless you changed `HIDDEN_GROTTO_OBJ_ITEM`.
- The Pokemon placeholder should use local id `2` unless you changed `HIDDEN_GROTTO_OBJ_MON`.
- The Pokemon placeholder should use `OBJ_EVENT_GFX_VAR_0` so the C code can push the correct species into `VAR_OBJ_GFX_ID_0`.

Example:

```json
{
  "graphics_id": "OBJ_EVENT_GFX_VAR_0",
  "x": 16,
  "y": 18,
  "script": "MyGrottoPokemon",
  "flag": "FLAG_MY_GROTTO_DAILY_CLEAR"
}
```

## Add the script hook

Use the same pattern as `data/maps/HiddenGrotto_Route32/scripts.pory`:

- Call `HiddenGrotto_InitializeCurrent` in the transition script.
- Show or hide the item and mon placeholders based on `VAR_RESULT`.
- For the mon interaction:
  - call `HiddenGrotto_GetCurrentContentId`
  - call `HiddenGrotto_CreateCurrentMon`
  - if `VAR_RESULT == FALSE`, bail out
  - after battle setup, call `HiddenGrotto_EmptyCurrent`
- For visible items and hidden items:
  - call `HiddenGrotto_GetCurrentContentId`
  - give/find the item
  - call `HiddenGrotto_EmptyCurrent`

The daily flag on the map objects is still useful for hiding cleared content during the current day, but the actual grotto content state lives in `SaveBlock3`.

## Graphics note

The placeholder Pokemon object uses `OBJ_EVENT_GFX_VAR_0`.
`HiddenGrotto_InitializeCurrent` updates `VAR_OBJ_GFX_ID_0` and refreshes the active object if it already exists.
If your placeholder uses a different var graphics slot, update `UpdateCurrentHiddenGrottoMonGraphics`.

## Daily reset

All grotto contents are reset by `DailyResetHiddenGrottoes()` from `src/clock.c`.
You do not need per-grotto reset logic unless you want different timing behavior.

## Test hook

`HiddenGrotto_TestCurrentMonBounds` samples the current grotto’s Pokemon table 1000 times without mutating save state.

Outputs:
- `VAR_RESULT`: number of invalid species rolls
- `gSpecialVar_0x8004`: sample count, currently `1000`
- `gSpecialVar_0x8005`: minimum valid species id seen
- `gSpecialVar_0x8006`: maximum valid species id seen
- `gSpecialVar_0x8007`: last invalid species id seen, or `0` if none

It also prints a summary to the debug logger through `DebugPrintf`.
