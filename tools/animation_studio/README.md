# Battle Animation Studio

This is a local studio for browsing, composing, and previewing battle move
animations in the real game engine.

## Build The Index

From the repo root:

```sh
python3 tools/animation_studio/studio.py build-manifest
python3 -m http.server 8000
```

Then open:

```text
http://127.0.0.1:8000/tools/animation_studio/
```

The browser studio reads `tools/animation_studio/data/manifest.json`. Regenerate
that file whenever animation scripts, move data, or battle animation assets
change.

## Exact Preview

The browser view does not reimplement the GBA renderer. For exact playback it
generates a focused battle test that runs the move through the ROM's actual
battle animation engine.

```sh
python3 tools/animation_studio/studio.py preview-test --move MOVE_POUND
```

The command writes `test/battle/move_animations/studio_preview.c` and prints a
sharded build command like:

```sh
make pokeemerald-test-0.elf TEST_SHARDS=4 TESTS="Animation Studio Preview: MOVE_POUND"
```

Open the printed `pokeemerald-test-N.elf` in a graphical GBA emulator to watch
the animation.

You can pick the battler species used by the preview harness:

```sh
python3 tools/animation_studio/studio.py preview-test \
  --move MOVE_DRAGON_DARTS \
  --attacker SPECIES_DRAGAPULT \
  --target SPECIES_WOBBUFFET
```

## Add A New Animation

Create a starter script and link a move to it:

```sh
python3 tools/animation_studio/studio.py new \
  --move MOVE_MY_MOVE \
  --label gBattleAnimMove_MyMove \
  --preview-test
```

Compose a new animation by inlining existing move scripts:

```sh
python3 tools/animation_studio/studio.py new \
  --move MOVE_MY_MOVE \
  --label gBattleAnimMove_MyMove \
  --source MOVE_EMBER \
  --source MOVE_ICE_BEAM \
  --preview-test
```

The tool updates:

- `data/battle_anim_scripts.s`
- `include/battle_anim_scripts.h`
- `src/data/moves_info.h`, when `--move` is supplied
- `test/battle/move_animations/studio_preview.c`, when `--preview-test` is supplied

Use `--dry-run` to print the generated script without editing files.

## Notes

Combining existing move animations uses inlining, not `call`, because full move
scripts usually end with `end` instead of `return`. Review any inlined labels,
`goto`s, and conditionals before shipping the new animation.

For new sprite assets, add the graphics under `graphics/battle_anims`, register
the asset symbols in `src/graphics.c`, add an `ANIM_TAG_*`, and add a
`BATTLE_ANIMATION(...)` entry in `src/data/battle_anim.h`.
