# New Pokemon Wizard

Run the local wizard from the repo root:

```sh
python3 tools/new_pokemon_wizard.py --serve --port 8765
```

Open `http://127.0.0.1:8765/`, fill the form, preview the diff, then apply.
The tool saves each species as `tools/new_pokemon/species/<folder>.json`, so
you can reload and tweak a species later.

The browser UI defaults to dark mode, with a light-mode toggle in the header.
Finite fields such as types, growth rates, egg groups, abilities, body colors,
animations, shadows, and tracks are populated from the current repo files.
Sprite preview cards show front, back, and icon art in normal and shiny palettes;
the preview uses the target graphics folder when it exists, otherwise it falls
back to the clone source folder.

Use the workflow selector to switch between adding a standalone species and
adding a form or mega to an existing species. Existing-form mode supports nested
graphics folders such as `graphics/pokemon/mewtwo/mega_z`, adds the new species
constant, registers graphics, inserts the SpeciesInfo block into the parent
family file, and wires the parent form species/change tables when those tables
already exist. For a custom mega, set the parent species, nested form folder,
guard macro, form-change method, and trigger item before previewing the diff.

CLI use is also available:

```sh
python3 tools/new_pokemon_wizard.py preview tools/new_pokemon/species/mewthree.json
python3 tools/new_pokemon_wizard.py apply tools/new_pokemon/species/mewthree.json
```

The first version handles the common custom-species path: species constants,
SpeciesInfo, National Dex constants/order arrays, cries, graphics registration,
overworld/follower data, level-up learnsets, teachable learnables, and one
optional wild encounter slot replacement. Forms, gender differences, and complex
evolution insertion are still best reviewed manually.
