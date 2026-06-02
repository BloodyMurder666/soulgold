#!/usr/bin/env python3
"""
Local wizard for adding custom Pokemon species to this repo.

Usage:
  python3 tools/new_pokemon_wizard.py --serve --port 8765
  python3 tools/new_pokemon_wizard.py preview tools/new_pokemon/species/mewthree.json
  python3 tools/new_pokemon_wizard.py apply tools/new_pokemon/species/mewthree.json

The browser flow stores species as JSON manifests, previews a unified diff, and
can apply the generated changes. It intentionally edits only the custom-friendly
areas of the repo and leaves complicated form/evolution cases for manual review.
"""

from __future__ import annotations

import argparse
import copy
import difflib
import json
import mimetypes
import os
import re
import shutil
import sys
from dataclasses import dataclass, field
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, unquote, urlparse


REPO_ROOT = Path(__file__).resolve().parents[1]
MANIFEST_DIR = REPO_ROOT / "tools" / "new_pokemon" / "species"

SPECIES_CONSTANTS = Path("include/constants/species.h")
POKEDEX_CONSTANTS = Path("include/constants/pokedex.h")
CRY_CONSTANTS = Path("include/constants/cries.h")
CRY_DATA = Path("sound/direct_sound_data.inc")
CRY_TABLES = Path("sound/cry_tables.inc")
GRAPHICS_DATA = Path("src/data/graphics/pokemon.h")
SPECIES_INFO = Path("src/data/pokemon/species_info.h")
SPECIES_INFO_DIR = Path("src/data/pokemon/species_info")
FORM_SPECIES_TABLES = Path("src/data/pokemon/form_species_tables.h")
FORM_CHANGE_TABLES = Path("src/data/pokemon/form_change_tables.h")
POKEDEX_ORDERS = Path("src/data/pokemon/pokedex_orders.h")
ALL_LEARNABLES = Path("src/data/pokemon/all_learnables.json")
OBJECT_EVENT_PICS = Path("src/data/object_events/object_event_pic_tables_followers.h")
SPRITESHEET_RULES = Path("spritesheet_rules.mk")
MAKEFILE = Path("Makefile")
WILD_ENCOUNTERS = Path("src/data/wild_encounters.json")

STAT_KEYS = [
    ("hp", "baseHP", "HP"),
    ("attack", "baseAttack", "Attack"),
    ("defense", "baseDefense", "Defense"),
    ("speed", "baseSpeed", "Speed"),
    ("spAttack", "baseSpAttack", "SpAttack"),
    ("spDefense", "baseSpDefense", "SpDefense"),
]

EV_KEYS = [
    ("hp", "evYield_HP"),
    ("attack", "evYield_Attack"),
    ("defense", "evYield_Defense"),
    ("speed", "evYield_Speed"),
    ("spAttack", "evYield_SpAttack"),
    ("spDefense", "evYield_SpDefense"),
]

DEFAULT_MANIFEST = {
    "kind": "species",
    "name": "Mewthree",
    "constant": "MEWTHREE",
    "folder": "mewthree",
    "copyGraphicsFrom": "mew",
    "form": {
        "parentConstant": "MEWTWO",
        "parentFolder": "mewtwo",
        "formFolder": "mega_z",
        "copyGraphicsFrom": "mewtwo/mega_y",
        "tableSymbol": "Mewtwo",
        "speciesName": "Mewtwo",
        "natDexConstant": "NATIONAL_DEX_MEWTWO",
        "cryId": "CRY_MEWTWO",
        "footprintSymbol": "Mewtwo",
        "learnsetSymbol": "Mewtwo",
        "formSpeciesTable": "sMewtwoFormSpeciesIdTable",
        "formChangeTable": "sMewtwoFormChangeTable",
        "guard": "P_MEGA_EVOLUTIONS",
        "updateFormSpeciesTable": True,
        "updateFormChangeTable": True,
        "formChangeMethod": "FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM",
        "formChangeItem": "ITEM_PSYCHITE",
        "isMegaEvolution": True,
    },
    "include": {
        "nationalDex": True,
        "cry": True,
        "graphics": True,
        "overworld": True,
        "wildEncounter": False,
    },
    "baseStats": {
        "hp": 106,
        "attack": 150,
        "defense": 70,
        "speed": 140,
        "spAttack": 194,
        "spDefense": 120,
    },
    "types": ["TYPE_PSYCHIC", "TYPE_PSYCHIC"],
    "catchRate": 3,
    "expYield": 255,
    "evYields": {
        "hp": 0,
        "attack": 0,
        "defense": 0,
        "speed": 0,
        "spAttack": 3,
        "spDefense": 0,
    },
    "heldItems": {"common": "ITEM_NONE", "rare": "ITEM_NONE"},
    "genderRatio": "MON_GENDERLESS",
    "eggCycles": 120,
    "friendship": 0,
    "growthRate": "GROWTH_SLOW",
    "eggGroups": ["EGG_GROUP_NO_EGGS_DISCOVERED", "EGG_GROUP_NO_EGGS_DISCOVERED"],
    "abilities": ["ABILITY_INSOMNIA", "ABILITY_NONE", "ABILITY_NONE"],
    "bodyColor": "BODY_COLOR_PURPLE",
    "noFlip": False,
    "flags": {
        "isRestrictedLegendary": False,
        "isSubLegendary": False,
        "isMythical": False,
        "isUltraBeast": False,
        "isParadox": False,
        "isFrontierBanned": False,
        "tmIlliterate": False,
        "perfectIVCount": "",
    },
    "dex": {
        "categoryName": "New Species",
        "height": 15,
        "weight": 330,
        "description": [
            "The rumors became true.",
            "This is Mew's final form.",
            "Its power level is over 9000.",
            "Has science gone too far?",
        ],
        "pokemonScale": 256,
        "pokemonOffset": 0,
        "trainerScale": 290,
        "trainerOffset": 2,
    },
    "graphics": {
        "frontSource": "anim_front",
        "frontWidth": 64,
        "frontHeight": 64,
        "frontYOffset": 0,
        "frontAnimFrames": [[0, 1]],
        "frontAnimId": "ANIM_GROW_VIBRATE",
        "frontAnimDelay": 15,
        "enemyMonElevation": 6,
        "backWidth": 64,
        "backHeight": 64,
        "backYOffset": 0,
        "backAnimId": "BACK_ANIM_CONCAVE_ARC_SMALL",
        "iconPalIndex": 2,
        "shadow": {"enabled": True, "x": 0, "y": 13, "size": "SHADOW_SIZE_S"},
        "overworld": {
            "size": "SIZE_32x32",
            "frameWidthTiles": 4,
            "frameHeightTiles": 4,
            "shadowSize": "SHADOW_SIZE_M",
            "tracks": "TRACKS_FOOT",
            "animTable": "sAnimTable_Following",
        },
    },
    "moves": {
        "levelUp": "1 CONFUSION\n1 DISABLE\n11 BARRIER\n22 SWIFT\n33 PSYCH_UP\n44 FUTURE_SIGHT\n55 MIST\n66 PSYCHIC\n77 AMNESIA\n88 RECOVER\n99 SAFEGUARD",
        "teachables": "FOCUS_PUNCH\nWATER_PULSE\nCALM_MIND\nTOXIC",
    },
    "cry": {"sourcePath": ""},
    "wildEncounter": {
        "map": "MAP_PETALBURG_WOODS",
        "method": "land_mons",
        "slot": 3,
        "minLevel": 5,
        "maxLevel": 5,
    },
}


HTML = r"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>New Pokemon Wizard</title>
<style>
:root {
  color-scheme: dark;
  --bg: #17191b;
  --panel: #242729;
  --panel-head: #303335;
  --field: #1f2224;
  --field-strong: #121415;
  --ink: #f3f6f8;
  --muted: #aab3ba;
  --line: #454a4e;
  --accent: #4c9dff;
  --accent-dark: #2f73c7;
  --good: #39a66b;
  --bad: #e06a6a;
  --warn: #efc35b;
  --shadow: rgba(0, 0, 0, .38);
}
body.light {
  color-scheme: light;
  --bg: #f6f8fb;
  --panel: #ffffff;
  --panel-head: #eef3f8;
  --field: #ffffff;
  --field-strong: #f8fafc;
  --ink: #17202a;
  --muted: #5f6f82;
  --line: #d7dee8;
  --accent: #2367a6;
  --accent-dark: #164f83;
  --good: #1f7a4d;
  --bad: #a33a3a;
  --warn: #8a5b12;
  --shadow: rgba(25, 39, 54, .12);
}
* { box-sizing: border-box; }
body {
  margin: 0;
  background: var(--bg);
  color: var(--ink);
  font: 14px/1.45 system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
}
header {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 16px;
  padding: 14px 18px;
  border-bottom: 1px solid var(--line);
  background: var(--panel);
  box-shadow: 0 8px 18px var(--shadow);
  position: sticky;
  top: 0;
  z-index: 2;
}
h1 { margin: 0; font-size: 18px; }
main {
  display: grid;
  grid-template-columns: minmax(360px, 560px) minmax(360px, 1fr);
  min-height: calc(100vh - 58px);
}
form {
  padding: 16px;
  overflow: auto;
  border-right: 1px solid var(--line);
}
details {
  border: 1px solid var(--line);
  border-radius: 8px;
  background: var(--panel);
  margin-bottom: 12px;
  overflow: hidden;
}
summary {
  cursor: pointer;
  padding: 11px 12px;
  font-weight: 700;
  background: var(--panel-head);
}
.section-body { padding: 12px; }
.grid { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 10px; }
.grid-3 { display: grid; grid-template-columns: repeat(3, minmax(0, 1fr)); gap: 10px; }
.full { grid-column: 1 / -1; }
label { display: grid; gap: 4px; color: var(--muted); font-size: 12px; }
input, select, textarea {
  width: 100%;
  border: 1px solid var(--line);
  border-radius: 6px;
  padding: 7px 8px;
  background: var(--field);
  color: var(--ink);
  font: inherit;
}
input:focus, select:focus, textarea:focus {
  border-color: var(--accent);
  outline: 2px solid color-mix(in srgb, var(--accent) 35%, transparent);
}
textarea { min-height: 86px; resize: vertical; font-family: ui-monospace, SFMono-Regular, Consolas, monospace; font-size: 12px; }
input[type="checkbox"] { width: auto; }
.checks { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 8px; }
.check { display: flex; align-items: center; gap: 8px; color: var(--ink); font-size: 13px; }
.buttons { display: flex; flex-wrap: wrap; gap: 8px; align-items: center; }
button {
  border: 1px solid var(--accent);
  border-radius: 6px;
  background: var(--accent);
  color: #fff;
  padding: 7px 11px;
  font-weight: 700;
  cursor: pointer;
}
button.secondary { color: var(--accent); background: #fff; }
body:not(.light) button.secondary {
  color: var(--ink);
  background: var(--field);
  border-color: var(--line);
}
button.good { border-color: var(--good); background: var(--good); }
button:disabled { opacity: .55; cursor: wait; }
#output {
  display: grid;
  grid-template-rows: auto auto auto auto minmax(280px, 1fr);
  min-width: 0;
  padding: 16px;
  gap: 10px;
}
#status {
  min-height: 26px;
  color: var(--muted);
}
#warnings {
  margin: 0;
  padding-left: 18px;
  color: var(--warn);
}
pre {
  min-height: 280px;
  overflow: auto;
  margin: 0;
  padding: 12px;
  background: var(--field-strong);
  color: #e5edf5;
  border: 1px solid var(--line);
  border-radius: 8px;
  font-size: 12px;
  line-height: 1.45;
}
.ops {
  border: 1px solid var(--line);
  border-radius: 8px;
  background: var(--panel);
  padding: 10px 12px;
}
.ops h2 { margin: 0 0 6px; font-size: 14px; }
#operations { margin: 0; padding-left: 18px; color: var(--muted); }
.toolbar-spacer { flex: 1 1 auto; }
.hidden { display: none !important; }
.preview-panel {
  border: 1px solid var(--line);
  border-radius: 8px;
  background: var(--panel);
  padding: 10px 12px 12px;
}
.preview-head {
  display: flex;
  align-items: start;
  justify-content: space-between;
  gap: 12px;
  margin-bottom: 10px;
}
.preview-head h2 { margin: 0; font-size: 14px; }
.preview-head p { margin: 2px 0 0; color: var(--muted); font-size: 12px; }
.sprite-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(122px, 1fr));
  gap: 10px;
}
.sprite-card {
  border: 1px solid var(--line);
  border-radius: 8px;
  background: var(--field);
  overflow: hidden;
}
.sprite-title {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 8px;
  padding: 7px 8px;
  background: var(--panel-head);
  font-weight: 700;
}
.sprite-title span:last-child {
  color: var(--muted);
  font-size: 11px;
  font-weight: 500;
}
.sprite-box {
  display: grid;
  place-items: center;
  min-height: 116px;
  padding: 10px;
  background:
    linear-gradient(45deg, rgba(255,255,255,.06) 25%, transparent 25%),
    linear-gradient(-45deg, rgba(255,255,255,.06) 25%, transparent 25%),
    linear-gradient(45deg, transparent 75%, rgba(255,255,255,.06) 75%),
    linear-gradient(-45deg, transparent 75%, rgba(255,255,255,.06) 75%);
  background-color: #0c0d0e;
  background-position: 0 0, 0 8px, 8px -8px, -8px 0;
  background-size: 16px 16px;
}
body.light .sprite-box {
  background-color: #eef2f6;
}
.sprite-box canvas,
.sprite-box img {
  max-width: 100%;
  max-height: 104px;
  image-rendering: pixelated;
  object-fit: contain;
}
.sprite-status {
  min-height: 30px;
  padding: 6px 8px;
  color: var(--muted);
  font-size: 11px;
  word-break: break-word;
}
@media (max-width: 900px) {
  main { grid-template-columns: 1fr; }
  form { border-right: 0; border-bottom: 1px solid var(--line); }
}
</style>
</head>
<body>
<header>
  <h1>New Pokemon Wizard</h1>
  <div class="buttons">
    <select id="manifestSelect" aria-label="Saved manifests"></select>
    <button class="secondary" id="loadManifest" type="button">Load</button>
    <button class="secondary" id="saveManifest" type="button">Save Manifest</button>
    <button id="preview" type="button">Preview Diff</button>
    <button class="good" id="apply" type="button">Apply</button>
    <button class="secondary" id="themeToggle" type="button">Light Mode</button>
  </div>
</header>
<main>
  <form id="speciesForm">
    <details open>
      <summary>Identity</summary>
      <div class="section-body grid">
        <label>Workflow <select id="kind"><option value="species">New standalone species</option><option value="form">Existing species form / mega</option></select></label>
        <label>Name <input id="name" value="Mewthree"></label>
        <label>Constant stem <input id="constant" value="MEWTHREE"></label>
        <label>Graphics folder <input list="graphicsFolders" id="folder" value="mewthree"></label>
        <label>Clone graphics from folder <input list="graphicsFolders" id="copyGraphicsFrom" value="mew"></label>
        <div class="checks full">
          <label class="check"><input id="includeNationalDex" type="checkbox" checked> Add National Dex data</label>
          <label class="check"><input id="includeCry" type="checkbox" checked> Add cry data</label>
          <label class="check"><input id="includeGraphics" type="checkbox" checked> Add graphics data</label>
          <label class="check"><input id="includeOverworld" type="checkbox" checked> Add overworld/follower data</label>
          <label class="check"><input id="includeWildEncounter" type="checkbox"> Replace wild encounter slot</label>
        </div>
      </div>
    </details>

    <details id="formDetails">
      <summary>Existing Form / Mega</summary>
      <div class="section-body grid">
        <label>Parent species <input list="speciesConstants" id="formParentConstant" value="MEWTWO"></label>
        <label>Parent graphics folder <input list="graphicsFolders" id="formParentFolder" value="mewtwo"></label>
        <label>Nested form folder <input id="formFolder" value="mega_z"></label>
        <label>Clone form graphics from <input list="graphicsFolders" id="formCopyGraphicsFrom" value="mewtwo/mega_y"></label>
        <label>Form table symbol <input id="formTableSymbol" value="Mewtwo"></label>
        <label>Species display name <input id="formSpeciesName" value="Mewtwo"></label>
        <label>National Dex constant <input id="formNatDexConstant" value="NATIONAL_DEX_MEWTWO"></label>
        <label>Cry id <input id="formCryId" value="CRY_MEWTWO"></label>
        <label>Footprint symbol <input id="formFootprintSymbol" value="Mewtwo"></label>
        <label>Learnset symbol <input id="formLearnsetSymbol" value="Mewtwo"></label>
        <label>Guard macro <input id="formGuard" value="P_MEGA_EVOLUTIONS"></label>
        <label>Form change method <input list="formChangeMethods" id="formChangeMethod" value="FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM"></label>
        <label>Trigger item / argument <input list="items" id="formChangeItem" value="ITEM_PSYCHITE"></label>
        <div class="checks full">
          <label class="check"><input id="formIsMegaEvolution" type="checkbox" checked> Mark SpeciesInfo as mega evolution</label>
          <label class="check"><input id="formUpdateSpeciesTable" type="checkbox" checked> Add to parent form species table</label>
          <label class="check"><input id="formUpdateChangeTable" type="checkbox" checked> Add to parent form change table</label>
        </div>
      </div>
    </details>

    <details open>
      <summary>Battle Data</summary>
      <div class="section-body grid-3">
        <label>HP <input id="statHp" type="number" value="106"></label>
        <label>Attack <input id="statAttack" type="number" value="150"></label>
        <label>Defense <input id="statDefense" type="number" value="70"></label>
        <label>Speed <input id="statSpeed" type="number" value="140"></label>
        <label>Sp. Attack <input id="statSpAttack" type="number" value="194"></label>
        <label>Sp. Defense <input id="statSpDefense" type="number" value="120"></label>
        <label>Type 1 <select data-options="types" data-default="TYPE_PSYCHIC" id="type1"></select></label>
        <label>Type 2 <select data-options="types" data-default="TYPE_PSYCHIC" id="type2"></select></label>
        <label>Catch rate <input id="catchRate" type="number" value="3"></label>
        <label>EXP yield <input id="expYield" type="number" value="255"></label>
        <label>Gender ratio <input id="genderRatio" value="MON_GENDERLESS"></label>
        <label>Egg cycles <input id="eggCycles" type="number" value="120"></label>
        <label>Friendship <input id="friendship" type="number" value="0"></label>
        <label>Growth rate <select data-options="growthRates" data-default="GROWTH_SLOW" id="growthRate"></select></label>
        <label>Body color <select data-options="bodyColors" data-default="BODY_COLOR_PURPLE" id="bodyColor"></select></label>
        <label>Egg group 1 <select data-options="eggGroups" data-default="EGG_GROUP_NO_EGGS_DISCOVERED" id="eggGroup1"></select></label>
        <label>Egg group 2 <select data-options="eggGroups" data-default="EGG_GROUP_NO_EGGS_DISCOVERED" id="eggGroup2"></select></label>
        <label>Ability 1 <select data-options="abilities" data-default="ABILITY_INSOMNIA" id="ability1"></select></label>
        <label>Ability 2 <select data-options="abilities" data-default="ABILITY_NONE" id="ability2"></select></label>
        <label>Hidden Ability <select data-options="abilities" data-default="ABILITY_NONE" id="ability3"></select></label>
        <label>Common held item <input list="items" id="itemCommon" value="ITEM_NONE"></label>
        <label>Rare held item <input list="items" id="itemRare" value="ITEM_NONE"></label>
        <label class="check"><input id="noFlip" type="checkbox"> Do not flip front sprite</label>
      </div>
    </details>

    <details>
      <summary>EVs And Flags</summary>
      <div class="section-body grid-3">
        <label>HP EV <input id="evHp" type="number" value="0"></label>
        <label>Atk EV <input id="evAttack" type="number" value="0"></label>
        <label>Def EV <input id="evDefense" type="number" value="0"></label>
        <label>Speed EV <input id="evSpeed" type="number" value="0"></label>
        <label>Sp. Atk EV <input id="evSpAttack" type="number" value="3"></label>
        <label>Sp. Def EV <input id="evSpDefense" type="number" value="0"></label>
        <label>Perfect IV count expression <input id="perfectIVCount" placeholder="LEGENDARY_PERFECT_IV_COUNT"></label>
        <div class="checks full">
          <label class="check"><input id="isRestrictedLegendary" type="checkbox"> Restricted legendary</label>
          <label class="check"><input id="isSubLegendary" type="checkbox"> Sub legendary</label>
          <label class="check"><input id="isMythical" type="checkbox"> Mythical</label>
          <label class="check"><input id="isUltraBeast" type="checkbox"> Ultra Beast</label>
          <label class="check"><input id="isParadox" type="checkbox"> Paradox</label>
          <label class="check"><input id="isFrontierBanned" type="checkbox"> Frontier banned</label>
          <label class="check"><input id="tmIlliterate" type="checkbox"> TM illiterate</label>
        </div>
      </div>
    </details>

    <details open>
      <summary>Pokedex</summary>
      <div class="section-body grid">
        <label>Category <input id="categoryName" value="New Species"></label>
        <label>Height, decimeters <input id="height" type="number" value="15"></label>
        <label>Weight, hectograms <input id="weight" type="number" value="330"></label>
        <label>Pokemon scale <input id="pokemonScale" type="number" value="256"></label>
        <label>Pokemon offset <input id="pokemonOffset" type="number" value="0"></label>
        <label>Trainer scale <input id="trainerScale" type="number" value="290"></label>
        <label>Trainer offset <input id="trainerOffset" type="number" value="2"></label>
        <label class="full">Description, one line per in-game line <textarea id="description">The rumors became true.
This is Mew's final form.
Its power level is over 9000.
Has science gone too far?</textarea></label>
      </div>
    </details>

    <details open>
      <summary>Graphics</summary>
      <div class="section-body grid-3">
        <label>Front source <select id="frontSource"><option value="anim_front">anim_front</option><option value="front">front</option></select></label>
        <label>Front width <input id="frontWidth" type="number" value="64"></label>
        <label>Front height <input id="frontHeight" type="number" value="64"></label>
        <label>Front Y offset <input id="frontYOffset" type="number" value="0"></label>
        <label>Front anim <select data-options="frontAnims" data-default="ANIM_GROW_VIBRATE" id="frontAnimId"></select></label>
        <label>Front anim delay <input id="frontAnimDelay" type="number" value="15"></label>
        <label>Enemy elevation <input id="enemyMonElevation" type="number" value="6"></label>
        <label>Back width <input id="backWidth" type="number" value="64"></label>
        <label>Back height <input id="backHeight" type="number" value="64"></label>
        <label>Back Y offset <input id="backYOffset" type="number" value="0"></label>
        <label>Back anim <select data-options="backAnims" data-default="BACK_ANIM_CONCAVE_ARC_SMALL" id="backAnimId"></select></label>
        <label>Icon palette index <input id="iconPalIndex" type="number" min="0" max="5" value="2"></label>
        <label class="full">Front animation frames, frame duration per line <textarea id="frontAnimFrames">0 1</textarea></label>
        <label class="check"><input id="shadowEnabled" type="checkbox" checked> Use battle shadow</label>
        <label>Shadow X <input id="shadowX" type="number" value="0"></label>
        <label>Shadow Y <input id="shadowY" type="number" value="13"></label>
        <label>Shadow size <select data-options="shadowSizes" data-default="SHADOW_SIZE_S" id="shadowSize"></select></label>
      </div>
    </details>

    <details>
      <summary>Overworld</summary>
      <div class="section-body grid-3">
        <label>Object size <select id="owSize"><option>SIZE_32x32</option><option>SIZE_64x64</option></select></label>
        <label>Frame width tiles <input id="owFrameWidthTiles" type="number" value="4"></label>
        <label>Frame height tiles <input id="owFrameHeightTiles" type="number" value="4"></label>
        <label>Shadow size <select data-options="owShadowSizes" data-default="SHADOW_SIZE_M" id="owShadowSize"></select></label>
        <label>Tracks <select data-options="tracks" data-default="TRACKS_FOOT" id="owTracks"></select></label>
        <label>Anim table <input id="owAnimTable" value="sAnimTable_Following"></label>
      </div>
    </details>

    <details open>
      <summary>Moves And Cry</summary>
      <div class="section-body grid">
        <label class="full">Level-up moves, level move per line <textarea id="levelUp">1 CONFUSION
1 DISABLE
11 BARRIER
22 SWIFT
33 PSYCH_UP
44 FUTURE_SIGHT
55 MIST
66 PSYCHIC
77 AMNESIA
88 RECOVER
99 SAFEGUARD</textarea></label>
        <label class="full">Teachable moves, one move per line <textarea id="teachables">FOCUS_PUNCH
WATER_PULSE
CALM_MIND
TOXIC</textarea></label>
        <label class="full">Cry source .wav path to copy, optional <input id="crySourcePath" placeholder="/path/to/cry.wav"></label>
      </div>
    </details>

    <details>
      <summary>Wild Encounter Slot</summary>
      <div class="section-body grid">
        <label>Map constant <input list="wildMaps" id="wildMap" value="MAP_PETALBURG_WOODS"></label>
        <label>Method <select id="wildMethod"><option>land_mons</option><option>water_mons</option><option>rock_smash_mons</option><option>fishing_mons</option></select></label>
        <label>Slot index <input id="wildSlot" type="number" value="3"></label>
        <label>Min level <input id="wildMinLevel" type="number" value="5"></label>
        <label>Max level <input id="wildMaxLevel" type="number" value="5"></label>
      </div>
    </details>
  </form>

  <div id="output">
    <div id="status">Ready.</div>
    <ul id="warnings"></ul>
    <div class="preview-panel">
      <div class="preview-head">
        <div>
          <h2>Sprites</h2>
          <p id="spriteSource">Preview uses the new folder if present, otherwise the clone source.</p>
        </div>
        <button class="secondary" id="refreshSprites" type="button">Refresh</button>
      </div>
      <div id="spritePreview" class="sprite-grid"></div>
    </div>
    <div class="ops">
      <h2>File Operations</h2>
      <ul id="operations"></ul>
    </div>
    <pre id="diff">Preview output will appear here.</pre>
  </div>
</main>

<datalist id="types"></datalist>
<datalist id="growthRates"></datalist>
<datalist id="bodyColors"></datalist>
<datalist id="eggGroups"></datalist>
<datalist id="abilities"></datalist>
<datalist id="items"></datalist>
<datalist id="frontAnims"></datalist>
<datalist id="backAnims"></datalist>
<datalist id="moves"></datalist>
<datalist id="shadowSizes"></datalist>
<datalist id="owShadowSizes"></datalist>
<datalist id="tracks"></datalist>
<datalist id="graphicsFolders"></datalist>
<datalist id="wildMaps"></datalist>
<datalist id="speciesConstants"></datalist>
<datalist id="formChangeMethods"></datalist>

<script>
const $ = (id) => document.getElementById(id);
const num = (id) => Number($(id).value || 0);
const checked = (id) => $(id).checked;
const listLines = (id) => $(id).value.split(/\r?\n/).map(s => s.trim()).filter(Boolean);
let spritePreviewSeq = 0;
let spritePreviewTimer = null;

function escapeHtml(value) {
  return String(value ?? "").replace(/[&<>"']/g, ch => ({
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': "&quot;",
    "'": "&#39;",
  }[ch]));
}

function setList(id, values) {
  const list = $(id);
  if (!list) return;
  list.innerHTML = (values || []).map(v => `<option value="${escapeHtml(v)}"></option>`).join("");
}

function ensureSelectValue(id, value) {
  const el = $(id);
  if (!el || el.tagName !== "SELECT") return;
  const text = String(value ?? "");
  if (text && !Array.from(el.options).some(option => option.value === text)) {
    el.add(new Option(`${text} (custom)`, text));
  }
  el.value = text;
}

function setValue(id, value) {
  const el = $(id);
  if (!el) return;
  if (el.tagName === "SELECT") {
    ensureSelectValue(id, value);
  } else {
    el.value = value ?? "";
  }
}

function populateSelects(key, values) {
  document.querySelectorAll(`select[data-options="${key}"]`).forEach(select => {
    const current = select.value || select.dataset.default || "";
    select.innerHTML = (values || [])
      .map(v => `<option value="${escapeHtml(v)}">${escapeHtml(v)}</option>`)
      .join("");
    ensureSelectValue(select.id, current);
  });
}

function constantStem(value) {
  return String(value || "")
    .trim()
    .toUpperCase()
    .replace(/^SPECIES_/, "")
    .replace(/[^A-Z0-9_]+/g, "_")
    .replace(/_+/g, "_")
    .replace(/^_+|_+$/g, "");
}

function pathPart(value) {
  return String(value || "")
    .trim()
    .toLowerCase()
    .replace(/[^a-z0-9_.-]+/g, "_")
    .replace(/_+/g, "_")
    .replace(/^_+|_+$/g, "");
}

function formGraphicsFolder() {
  return [pathPart($("formParentFolder").value), pathPart($("formFolder").value)]
    .filter(Boolean)
    .join("/");
}

function titleFromStem(stem) {
  return constantStem(stem)
    .split("_")
    .filter(Boolean)
    .map(part => part.charAt(0) + part.slice(1).toLowerCase())
    .join("");
}

function syncFormFields(force = false) {
  const isForm = $("kind").value === "form";
  $("formDetails").classList.toggle("hidden", !isForm);
  if (!isForm) return;

  const parent = constantStem($("formParentConstant").value) || "MEWTWO";
  const parentFolder = pathPart($("formParentFolder").value) || pathPart(parent);
  const formFolder = pathPart($("formFolder").value) || "mega_z";
  const formSuffix = constantStem(formFolder) || "MEGA_Z";
  const tableSymbol = $("formTableSymbol").value || titleFromStem(parent);
  $("formParentConstant").value = parent;
  $("formParentFolder").value = parentFolder;
  $("formFolder").value = formFolder;
  $("folder").value = `${parentFolder}/${formFolder}`;
  $("copyGraphicsFrom").value = $("formCopyGraphicsFrom").value || parentFolder;

  if (force || !$("constant").value || $("constant").value === "MEWTHREE") {
    $("constant").value = `${parent}_${formSuffix}`;
  }
  if (force || !$("name").value || $("name").value === "Mewthree") {
    $("name").value = `${titleFromStem(parent)} ${formSuffix.split("_").map(part => part.charAt(0) + part.slice(1).toLowerCase()).join(" ")}`;
  }
  if (force) {
    setValue("frontSource", "front");
    $("includeCry").checked = false;
  }
  if (force || !$("formTableSymbol").value) $("formTableSymbol").value = tableSymbol;
  if (force || !$("formSpeciesName").value) $("formSpeciesName").value = titleFromStem(parent);
  if (force || !$("formNatDexConstant").value) $("formNatDexConstant").value = `NATIONAL_DEX_${parent}`;
  if (force || !$("formCryId").value) $("formCryId").value = `CRY_${parent}`;
  if (force || !$("formFootprintSymbol").value) $("formFootprintSymbol").value = titleFromStem(parent);
  if (force || !$("formLearnsetSymbol").value) $("formLearnsetSymbol").value = titleFromStem(parent);
}

function collect() {
  syncFormFields();
  const kind = $("kind").value;
  return {
    kind,
    name: $("name").value,
    constant: $("constant").value,
    folder: kind === "form" ? formGraphicsFolder() : $("folder").value,
    copyGraphicsFrom: kind === "form" ? ($("formCopyGraphicsFrom").value || $("copyGraphicsFrom").value) : $("copyGraphicsFrom").value,
    form: {
      parentConstant: $("formParentConstant").value,
      parentFolder: $("formParentFolder").value,
      formFolder: $("formFolder").value,
      copyGraphicsFrom: $("formCopyGraphicsFrom").value,
      tableSymbol: $("formTableSymbol").value,
      speciesName: $("formSpeciesName").value,
      natDexConstant: $("formNatDexConstant").value,
      cryId: $("formCryId").value,
      footprintSymbol: $("formFootprintSymbol").value,
      learnsetSymbol: $("formLearnsetSymbol").value,
      formSpeciesTable: `s${$("formTableSymbol").value || titleFromStem($("formParentConstant").value)}FormSpeciesIdTable`,
      formChangeTable: `s${$("formTableSymbol").value || titleFromStem($("formParentConstant").value)}FormChangeTable`,
      guard: $("formGuard").value,
      updateFormSpeciesTable: checked("formUpdateSpeciesTable"),
      updateFormChangeTable: checked("formUpdateChangeTable"),
      formChangeMethod: $("formChangeMethod").value,
      formChangeItem: $("formChangeItem").value,
      isMegaEvolution: checked("formIsMegaEvolution"),
    },
    include: {
      nationalDex: checked("includeNationalDex"),
      cry: checked("includeCry"),
      graphics: checked("includeGraphics"),
      overworld: checked("includeOverworld"),
      wildEncounter: checked("includeWildEncounter"),
    },
    baseStats: {
      hp: num("statHp"),
      attack: num("statAttack"),
      defense: num("statDefense"),
      speed: num("statSpeed"),
      spAttack: num("statSpAttack"),
      spDefense: num("statSpDefense"),
    },
    types: [$("type1").value, $("type2").value],
    catchRate: num("catchRate"),
    expYield: num("expYield"),
    evYields: {
      hp: num("evHp"),
      attack: num("evAttack"),
      defense: num("evDefense"),
      speed: num("evSpeed"),
      spAttack: num("evSpAttack"),
      spDefense: num("evSpDefense"),
    },
    heldItems: { common: $("itemCommon").value, rare: $("itemRare").value },
    genderRatio: $("genderRatio").value,
    eggCycles: num("eggCycles"),
    friendship: num("friendship"),
    growthRate: $("growthRate").value,
    eggGroups: [$("eggGroup1").value, $("eggGroup2").value],
    abilities: [$("ability1").value, $("ability2").value, $("ability3").value],
    bodyColor: $("bodyColor").value,
    noFlip: checked("noFlip"),
    flags: {
      isRestrictedLegendary: checked("isRestrictedLegendary"),
      isSubLegendary: checked("isSubLegendary"),
      isMythical: checked("isMythical"),
      isUltraBeast: checked("isUltraBeast"),
      isParadox: checked("isParadox"),
      isFrontierBanned: checked("isFrontierBanned"),
      tmIlliterate: checked("tmIlliterate"),
      perfectIVCount: $("perfectIVCount").value,
    },
    dex: {
      categoryName: $("categoryName").value,
      height: num("height"),
      weight: num("weight"),
      description: listLines("description"),
      pokemonScale: num("pokemonScale"),
      pokemonOffset: num("pokemonOffset"),
      trainerScale: num("trainerScale"),
      trainerOffset: num("trainerOffset"),
    },
    graphics: {
      frontSource: $("frontSource").value,
      frontWidth: num("frontWidth"),
      frontHeight: num("frontHeight"),
      frontYOffset: num("frontYOffset"),
      frontAnimFrames: listLines("frontAnimFrames").map(line => line.split(/[,\s]+/).map(Number)).filter(x => x.length >= 2),
      frontAnimId: $("frontAnimId").value,
      frontAnimDelay: num("frontAnimDelay"),
      enemyMonElevation: num("enemyMonElevation"),
      backWidth: num("backWidth"),
      backHeight: num("backHeight"),
      backYOffset: num("backYOffset"),
      backAnimId: $("backAnimId").value,
      iconPalIndex: num("iconPalIndex"),
      shadow: { enabled: checked("shadowEnabled"), x: num("shadowX"), y: num("shadowY"), size: $("shadowSize").value },
      overworld: {
        size: $("owSize").value,
        frameWidthTiles: num("owFrameWidthTiles"),
        frameHeightTiles: num("owFrameHeightTiles"),
        shadowSize: $("owShadowSize").value,
        tracks: $("owTracks").value,
        animTable: $("owAnimTable").value,
      },
    },
    moves: { levelUp: $("levelUp").value, teachables: $("teachables").value },
    cry: { sourcePath: $("crySourcePath").value },
    wildEncounter: {
      map: $("wildMap").value,
      method: $("wildMethod").value,
      slot: num("wildSlot"),
      minLevel: num("wildMinLevel"),
      maxLevel: num("wildMaxLevel"),
    },
  };
}

function fill(m) {
  setValue("kind", m.kind || "species");
  setValue("name", m.name || "");
  setValue("constant", m.constant || "");
  setValue("folder", m.folder || "");
  setValue("copyGraphicsFrom", m.copyGraphicsFrom || "");
  setValue("formParentConstant", m.form?.parentConstant || "MEWTWO");
  setValue("formParentFolder", m.form?.parentFolder || "mewtwo");
  setValue("formFolder", m.form?.formFolder || "mega_z");
  setValue("formCopyGraphicsFrom", m.form?.copyGraphicsFrom || (m.kind === "form" ? m.copyGraphicsFrom : "") || "mewtwo/mega_y");
  setValue("formTableSymbol", m.form?.tableSymbol || "Mewtwo");
  setValue("formSpeciesName", m.form?.speciesName || "Mewtwo");
  setValue("formNatDexConstant", m.form?.natDexConstant || "NATIONAL_DEX_MEWTWO");
  setValue("formCryId", m.form?.cryId || "CRY_MEWTWO");
  setValue("formFootprintSymbol", m.form?.footprintSymbol || "Mewtwo");
  setValue("formLearnsetSymbol", m.form?.learnsetSymbol || "Mewtwo");
  setValue("formGuard", m.form?.guard || "P_MEGA_EVOLUTIONS");
  setValue("formChangeMethod", m.form?.formChangeMethod || "FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM");
  setValue("formChangeItem", m.form?.formChangeItem || "ITEM_PSYCHITE");
  $("formIsMegaEvolution").checked = m.form?.isMegaEvolution ?? true;
  $("formUpdateSpeciesTable").checked = m.form?.updateFormSpeciesTable ?? true;
  $("formUpdateChangeTable").checked = m.form?.updateFormChangeTable ?? true;
  $("includeNationalDex").checked = !!m.include?.nationalDex;
  $("includeCry").checked = !!m.include?.cry;
  $("includeGraphics").checked = !!m.include?.graphics;
  $("includeOverworld").checked = !!m.include?.overworld;
  $("includeWildEncounter").checked = !!m.include?.wildEncounter;
  setValue("statHp", m.baseStats?.hp ?? 1);
  setValue("statAttack", m.baseStats?.attack ?? 1);
  setValue("statDefense", m.baseStats?.defense ?? 1);
  setValue("statSpeed", m.baseStats?.speed ?? 1);
  setValue("statSpAttack", m.baseStats?.spAttack ?? 1);
  setValue("statSpDefense", m.baseStats?.spDefense ?? 1);
  setValue("type1", m.types?.[0] || "TYPE_NORMAL");
  setValue("type2", m.types?.[1] || m.types?.[0] || "TYPE_NORMAL");
  setValue("catchRate", m.catchRate ?? 255);
  setValue("expYield", m.expYield ?? 67);
  setValue("evHp", m.evYields?.hp ?? 0);
  setValue("evAttack", m.evYields?.attack ?? 0);
  setValue("evDefense", m.evYields?.defense ?? 0);
  setValue("evSpeed", m.evYields?.speed ?? 0);
  setValue("evSpAttack", m.evYields?.spAttack ?? 0);
  setValue("evSpDefense", m.evYields?.spDefense ?? 0);
  setValue("itemCommon", m.heldItems?.common || "ITEM_NONE");
  setValue("itemRare", m.heldItems?.rare || "ITEM_NONE");
  setValue("genderRatio", m.genderRatio || "PERCENT_FEMALE(50)");
  setValue("eggCycles", m.eggCycles ?? 20);
  setValue("friendship", m.friendship ?? 70);
  setValue("growthRate", m.growthRate || "GROWTH_MEDIUM_FAST");
  setValue("bodyColor", m.bodyColor || "BODY_COLOR_BLACK");
  setValue("eggGroup1", m.eggGroups?.[0] || "EGG_GROUP_FIELD");
  setValue("eggGroup2", m.eggGroups?.[1] || m.eggGroups?.[0] || "EGG_GROUP_FIELD");
  setValue("ability1", m.abilities?.[0] || "ABILITY_NONE");
  setValue("ability2", m.abilities?.[1] || "ABILITY_NONE");
  setValue("ability3", m.abilities?.[2] || "ABILITY_NONE");
  $("noFlip").checked = !!m.noFlip;
  for (const key of ["isRestrictedLegendary","isSubLegendary","isMythical","isUltraBeast","isParadox","isFrontierBanned","tmIlliterate"]) {
    $(key).checked = !!m.flags?.[key];
  }
  setValue("perfectIVCount", m.flags?.perfectIVCount || "");
  setValue("categoryName", m.dex?.categoryName || "");
  setValue("height", m.dex?.height ?? 0);
  setValue("weight", m.dex?.weight ?? 0);
  setValue("description", (m.dex?.description || []).join("\n"));
  setValue("pokemonScale", m.dex?.pokemonScale ?? 256);
  setValue("pokemonOffset", m.dex?.pokemonOffset ?? 0);
  setValue("trainerScale", m.dex?.trainerScale ?? 256);
  setValue("trainerOffset", m.dex?.trainerOffset ?? 0);
  setValue("frontSource", m.graphics?.frontSource || "anim_front");
  setValue("frontWidth", m.graphics?.frontWidth ?? 64);
  setValue("frontHeight", m.graphics?.frontHeight ?? 64);
  setValue("frontYOffset", m.graphics?.frontYOffset ?? 0);
  setValue("frontAnimId", m.graphics?.frontAnimId || "ANIM_V_SQUISH_AND_BOUNCE");
  setValue("frontAnimDelay", m.graphics?.frontAnimDelay ?? 0);
  setValue("enemyMonElevation", m.graphics?.enemyMonElevation ?? 0);
  setValue("backWidth", m.graphics?.backWidth ?? 64);
  setValue("backHeight", m.graphics?.backHeight ?? 64);
  setValue("backYOffset", m.graphics?.backYOffset ?? 0);
  setValue("backAnimId", m.graphics?.backAnimId || "BACK_ANIM_NONE");
  setValue("iconPalIndex", m.graphics?.iconPalIndex ?? 0);
  setValue("frontAnimFrames", (m.graphics?.frontAnimFrames || [[0, 1]]).map(x => x.join(" ")).join("\n"));
  $("shadowEnabled").checked = !!m.graphics?.shadow?.enabled;
  setValue("shadowX", m.graphics?.shadow?.x ?? 0);
  setValue("shadowY", m.graphics?.shadow?.y ?? 0);
  setValue("shadowSize", m.graphics?.shadow?.size || "SHADOW_SIZE_S");
  setValue("owSize", m.graphics?.overworld?.size || "SIZE_32x32");
  setValue("owFrameWidthTiles", m.graphics?.overworld?.frameWidthTiles ?? 4);
  setValue("owFrameHeightTiles", m.graphics?.overworld?.frameHeightTiles ?? 4);
  setValue("owShadowSize", m.graphics?.overworld?.shadowSize || "SHADOW_SIZE_M");
  setValue("owTracks", m.graphics?.overworld?.tracks || "TRACKS_FOOT");
  setValue("owAnimTable", m.graphics?.overworld?.animTable || "sAnimTable_Following");
  setValue("levelUp", m.moves?.levelUp || "");
  setValue("teachables", m.moves?.teachables || "");
  setValue("crySourcePath", m.cry?.sourcePath || "");
  setValue("wildMap", m.wildEncounter?.map || "");
  setValue("wildMethod", m.wildEncounter?.method || "land_mons");
  setValue("wildSlot", m.wildEncounter?.slot ?? 0);
  setValue("wildMinLevel", m.wildEncounter?.minLevel ?? 5);
  setValue("wildMaxLevel", m.wildEncounter?.maxLevel ?? 5);
  syncFormFields(false);
  scheduleSpritePreview();
}

async function api(path, body) {
  const opts = body === undefined ? {} : {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(body),
  };
  const res = await fetch(path, opts);
  const json = await res.json();
  if (!res.ok) throw new Error(json.error || res.statusText);
  return json;
}

function render(result) {
  $("diff").textContent = result.diff || "No text changes.";
  $("warnings").innerHTML = (result.warnings || []).map(w => `<li>${escapeHtml(w)}</li>`).join("");
  $("operations").innerHTML = (result.operations || []).map(w => `<li>${escapeHtml(w)}</li>`).join("");
  $("status").textContent = result.message || "Done.";
}

async function refreshManifests() {
  const result = await api("/api/manifests");
  $("manifestSelect").innerHTML = result.manifests.map(n => `<option value="${escapeHtml(n)}">${escapeHtml(n)}</option>`).join("");
}

function applyTheme(theme) {
  const light = theme === "light";
  document.body.classList.toggle("light", light);
  $("themeToggle").textContent = light ? "Dark Mode" : "Light Mode";
  try {
    localStorage.setItem("newPokemonWizardTheme", light ? "light" : "dark");
  } catch {
    // Local storage can be disabled in hardened browsers.
  }
}

function cleanFolder(value) {
  return String(value || "")
    .trim()
    .replace(/^graphics\/pokemon\//i, "")
    .replace(/^\/+|\/+$/g, "")
    .split("/")
    .map(part => part.replace(/[^A-Za-z0-9_.-]/g, "_"))
    .filter(part => part && part !== "." && part !== "..")
    .join("/");
}

function unique(values) {
  return [...new Set(values.filter(Boolean))];
}

function previewFolders() {
  return unique([cleanFolder($("folder").value), cleanFolder($("copyGraphicsFrom").value)]);
}

function assetUrl(rel) {
  return "/asset/" + rel.split("/").filter(Boolean).map(encodeURIComponent).join("/");
}

async function firstExisting(candidates) {
  for (const rel of unique(candidates)) {
    try {
      const res = await fetch(assetUrl(rel), { method: "HEAD", cache: "no-store" });
      if (res.ok) return rel;
    } catch {
      // Try the next candidate.
    }
  }
  return "";
}

function candidateFiles(names) {
  const files = [];
  for (const folder of previewFolders()) {
    for (const name of names) {
      files.push(`graphics/pokemon/${folder}/${name}`);
    }
  }
  return files;
}

function imageCandidates(names) {
  return candidateFiles(names.map(name => `${name}.png`));
}

function paletteCandidates(names) {
  return candidateFiles(names);
}

function parsePalette(text) {
  const colors = [];
  for (const line of text.split(/\r?\n/)) {
    const parts = line.trim().split(/\s+/).map(Number);
    if (parts.length >= 3 && parts.slice(0, 3).every(n => Number.isFinite(n) && n >= 0 && n <= 255)) {
      colors.push(parts.slice(0, 3));
    }
  }
  return colors;
}

function paletteMap(normal, shiny) {
  const map = new Map();
  for (let i = 0; i < Math.min(normal.length, shiny.length); i++) {
    map.set(normal[i].join(","), shiny[i]);
  }
  return map;
}

async function fetchPalette(candidates) {
  const rel = await firstExisting(candidates);
  if (!rel) return null;
  const res = await fetch(assetUrl(rel), { cache: "no-store" });
  return { rel, colors: parsePalette(await res.text()) };
}

async function loadImage(rel) {
  const img = new Image();
  img.decoding = "async";
  img.src = `${assetUrl(rel)}?v=${Date.now()}`;
  await new Promise((resolve, reject) => {
    img.onload = resolve;
    img.onerror = reject;
  });
  return img;
}

function drawSprite(canvas, img, swapMap, frame) {
  const naturalWidth = img.naturalWidth || img.width;
  const naturalHeight = img.naturalHeight || img.height;
  canvas.width = Math.max(1, Math.min(frame?.w || naturalWidth, naturalWidth));
  canvas.height = Math.max(1, Math.min(frame?.h || naturalHeight, naturalHeight));
  const ctx = canvas.getContext("2d", { willReadFrequently: Boolean(swapMap) });
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.drawImage(img, 0, 0, canvas.width, canvas.height, 0, 0, canvas.width, canvas.height);
  if (!swapMap || swapMap.size === 0) return;
  const image = ctx.getImageData(0, 0, canvas.width, canvas.height);
  for (let i = 0; i < image.data.length; i += 4) {
    if (image.data[i + 3] === 0) continue;
    const replacement = swapMap.get(`${image.data[i]},${image.data[i + 1]},${image.data[i + 2]}`);
    if (!replacement) continue;
    image.data[i] = replacement[0];
    image.data[i + 1] = replacement[1];
    image.data[i + 2] = replacement[2];
  }
  ctx.putImageData(image, 0, 0);
}

function statusPath(rel) {
  return rel.replace(/^graphics\/pokemon\//, "");
}

async function renderSpriteCard(root, spec, seq) {
  const card = document.createElement("article");
  card.className = "sprite-card";
  card.innerHTML = `
    <div class="sprite-title"><span>${escapeHtml(spec.title)}</span><span>${escapeHtml(spec.tone)}</span></div>
    <div class="sprite-box"><canvas aria-label="${escapeHtml(spec.title)} preview"></canvas></div>
    <div class="sprite-status">Loading...</div>
  `;
  root.appendChild(card);

  const status = card.querySelector(".sprite-status");
  const canvas = card.querySelector("canvas");
  const imageRel = await firstExisting(spec.images);
  if (seq !== spritePreviewSeq) return;
  if (!imageRel) {
    status.textContent = "No matching PNG found.";
    return;
  }

  try {
    const img = await loadImage(imageRel);
    let note = statusPath(imageRel);
    let swap = null;
    if (spec.shiny) {
      const normalPal = await fetchPalette(spec.normalPalettes);
      const shinyPal = await fetchPalette(spec.shinyPalettes);
      if (normalPal && shinyPal && normalPal.colors.length && shinyPal.colors.length) {
        swap = paletteMap(normalPal.colors, shinyPal.colors);
        note += ` + ${statusPath(shinyPal.rel)}`;
      } else {
        note += " + shiny palette missing";
      }
    }
    if (seq !== spritePreviewSeq) return;
    drawSprite(canvas, img, swap, spec.frame);
    status.textContent = note;
  } catch (err) {
    status.textContent = `Preview failed: ${err.message}`;
  }
}

async function updateSpritePreview() {
  const seq = ++spritePreviewSeq;
  const root = $("spritePreview");
  const folders = previewFolders();
  $("spriteSource").textContent = folders.length
    ? `Source order: ${folders.join(" -> ")}`
    : "Enter a graphics folder or clone source to preview sprites.";
  root.innerHTML = "";

  const frontSource = $("frontSource").value || "anim_front";
  const frontFallback = frontSource === "front" ? "anim_front" : "front";
  const frontNames = unique([frontSource, `${frontSource}_gba`, frontFallback, `${frontFallback}_gba`]);
  const frontFrame = { w: num("frontWidth") || 64, h: num("frontHeight") || 64 };
  const backFrame = { w: num("backWidth") || 64, h: num("backHeight") || 64 };
  const iconFrame = { w: 32, h: 32 };
  const monNormal = paletteCandidates(["normal.pal", "normal_gba.pal"]);
  const monShiny = paletteCandidates(["shiny.pal", "shiny_gba.pal"]);
  const iconNormal = paletteCandidates(["icon_normal.pal"]);
  const iconShiny = paletteCandidates(["icon_shiny.pal"]);
  const specs = [
    { title: "Front", tone: "normal", images: imageCandidates(frontNames), shiny: false, frame: frontFrame },
    { title: "Front", tone: "shiny", images: imageCandidates(frontNames), shiny: true, normalPalettes: monNormal, shinyPalettes: monShiny, frame: frontFrame },
    { title: "Back", tone: "normal", images: imageCandidates(["back", "back_gba"]), shiny: false, frame: backFrame },
    { title: "Back", tone: "shiny", images: imageCandidates(["back", "back_gba"]), shiny: true, normalPalettes: monNormal, shinyPalettes: monShiny, frame: backFrame },
    { title: "Icon", tone: "normal", images: imageCandidates(["icon", "icon_gba"]), shiny: false, frame: iconFrame },
    { title: "Icon", tone: "shiny", images: imageCandidates(["icon", "icon_gba"]), shiny: true, normalPalettes: iconNormal, shinyPalettes: iconShiny, frame: iconFrame },
  ];

  await Promise.all(specs.map(spec => renderSpriteCard(root, spec, seq)));
}

function scheduleSpritePreview() {
  clearTimeout(spritePreviewTimer);
  spritePreviewTimer = setTimeout(updateSpritePreview, 100);
}

async function init() {
  try {
    applyTheme(localStorage.getItem("newPokemonWizardTheme") || "dark");
  } catch {
    applyTheme("dark");
  }
  const opts = await api("/api/options");
  const optionSets = {
    types: opts.types,
    growthRates: opts.growthRates,
    bodyColors: opts.bodyColors,
    eggGroups: opts.eggGroups,
    abilities: opts.abilities,
    items: opts.items,
    frontAnims: opts.frontAnims,
    backAnims: opts.backAnims,
    moves: opts.moves,
    formChangeMethods: opts.formChangeMethods,
    shadowSizes: opts.shadowSizes,
    owShadowSizes: opts.owShadowSizes,
    tracks: opts.tracks,
  };
  for (const [id, values] of Object.entries(optionSets)) {
    setList(id, values || []);
    populateSelects(id, values || []);
  }
  setList("graphicsFolders", opts.graphicsFolders || []);
  setList("wildMaps", opts.wildMaps || []);
  setList("speciesConstants", opts.speciesConstants || []);
  fill(opts.defaultManifest);
  await refreshManifests();
}

$("themeToggle").addEventListener("click", () => {
  applyTheme(document.body.classList.contains("light") ? "dark" : "light");
});
$("refreshSprites").addEventListener("click", updateSpritePreview);
for (const id of ["folder", "copyGraphicsFrom", "frontSource", "formParentFolder", "formFolder", "formCopyGraphicsFrom"]) {
  $(id).addEventListener("input", scheduleSpritePreview);
  $(id).addEventListener("change", scheduleSpritePreview);
}
$("kind").addEventListener("change", () => {
  syncFormFields(true);
  scheduleSpritePreview();
});
for (const id of ["formParentConstant", "formParentFolder", "formFolder", "formCopyGraphicsFrom"]) {
  $(id).addEventListener("change", () => {
    syncFormFields(id === "formParentConstant");
    scheduleSpritePreview();
  });
}

$("preview").addEventListener("click", async () => {
  $("status").textContent = "Building preview...";
  render(await api("/api/preview", collect()));
});
$("apply").addEventListener("click", async () => {
  if (!confirm("Apply these generated changes to the repo? Preview first if you have not already.")) return;
  $("status").textContent = "Applying changes...";
  render(await api("/api/apply", collect()));
  await refreshManifests();
});
$("saveManifest").addEventListener("click", async () => {
  render(await api("/api/save", collect()));
  await refreshManifests();
});
$("loadManifest").addEventListener("click", async () => {
  const name = $("manifestSelect").value;
  if (!name) return;
  const result = await api(`/api/manifest?name=${encodeURIComponent(name)}`);
  fill(result.manifest);
  render({message: `Loaded ${name}.`, warnings: [], operations: [], diff: ""});
});

init().catch(err => {
  $("status").textContent = err.message;
  $("status").style.color = "var(--bad)";
});
</script>
</body>
</html>
"""


@dataclass
class BuildResult:
    files: dict[Path, str] = field(default_factory=dict)
    warnings: list[str] = field(default_factory=list)
    operations: list[str] = field(default_factory=list)


def repo_path(rel: Path | str) -> Path:
    return REPO_ROOT / rel


def read_text(rel: Path | str) -> str:
    return repo_path(rel).read_text(encoding="utf-8")


def write_text(rel: Path | str, text: str) -> None:
    repo_path(rel).write_text(text, encoding="utf-8")


def rel_display(path: Path | str) -> str:
    return str(path).replace(os.sep, "/")


def deep_merge(base, extra):
    if isinstance(base, dict) and isinstance(extra, dict):
        out = copy.deepcopy(base)
        for key, value in extra.items():
            out[key] = deep_merge(out.get(key), value)
        return out
    if extra is None:
        return copy.deepcopy(base)
    return copy.deepcopy(extra)


def upper_words(value: str) -> str:
    value = value.strip()
    value = re.sub(r"[^A-Za-z0-9]+", "_", value)
    value = re.sub(r"_+", "_", value).strip("_")
    return value.upper() or "CUSTOM_MON"


def slugify(value: str) -> str:
    value = value.strip().lower()
    value = re.sub(r"[^a-z0-9]+", "_", value)
    value = re.sub(r"_+", "_", value).strip("_")
    return value or "custom_mon"


def species_stem(value: str) -> str:
    value = upper_words(value)
    if value.startswith("SPECIES_"):
        value = value[len("SPECIES_") :]
    return value or "CUSTOM_MON"


def graphics_rel_path(value: str, default: str = "") -> str:
    parts = []
    for part in str(value or "").replace("\\", "/").split("/"):
        slug = slugify(part)
        if slug and slug not in {".", ".."}:
            parts.append(slug)
    return "/".join(parts) or default


def symbol_from_constant(constant: str) -> str:
    parts = constant.split("_")
    return "".join(part[:1].upper() + part[1:].lower() for part in parts if part)


def ensure_prefixed(value: str, prefix: str, default: str) -> str:
    value = str(value or "").strip().upper()
    if not value:
        return default
    if value.startswith(prefix):
        return value
    return prefix + value


def c_string(value: str) -> str:
    return value.replace("\\", "\\\\").replace('"', '\\"')


def int_value(value, default=0) -> int:
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def normalize_manifest(raw: dict) -> dict:
    manifest = deep_merge(DEFAULT_MANIFEST, raw or {})
    manifest["kind"] = "form" if manifest.get("kind") == "form" else "species"
    if manifest.get("constant"):
        manifest["constant"] = upper_words(manifest["constant"])
    else:
        manifest["constant"] = upper_words(manifest.get("name", ""))

    if manifest["kind"] == "form":
        form = manifest.setdefault("form", {})
        form["parentConstant"] = species_stem(form.get("parentConstant", "MEWTWO"))
        form["parentFolder"] = graphics_rel_path(form.get("parentFolder"), slugify(form["parentConstant"]))
        form["formFolder"] = graphics_rel_path(form.get("formFolder"), "mega_z").split("/")[-1]
        form["copyGraphicsFrom"] = graphics_rel_path(form.get("copyGraphicsFrom") or manifest.get("copyGraphicsFrom"), form["parentFolder"])
        form["tableSymbol"] = str(form.get("tableSymbol") or symbol_from_constant(form["parentConstant"])).strip()
        form["speciesName"] = str(form.get("speciesName") or symbol_from_constant(form["parentConstant"])).strip()
        form["natDexConstant"] = ensure_prefixed(form.get("natDexConstant"), "NATIONAL_DEX_", f"NATIONAL_DEX_{form['parentConstant']}")
        form["cryId"] = ensure_prefixed(form.get("cryId"), "CRY_", f"CRY_{form['parentConstant']}")
        form["footprintSymbol"] = str(form.get("footprintSymbol") or symbol_from_constant(form["parentConstant"])).strip()
        form["learnsetSymbol"] = str(form.get("learnsetSymbol") or symbol_from_constant(form["parentConstant"])).strip()
        form["formSpeciesTable"] = str(form.get("formSpeciesTable") or f"s{form['tableSymbol']}FormSpeciesIdTable").strip()
        form["formChangeTable"] = str(form.get("formChangeTable") or f"s{form['tableSymbol']}FormChangeTable").strip()
        form["guard"] = upper_words(form.get("guard", "")).replace("P_", "P_", 1) if form.get("guard") else ""
        form["formChangeMethod"] = ensure_prefixed(form.get("formChangeMethod"), "FORM_CHANGE_", "FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM")
        form["formChangeItem"] = ensure_prefixed(form.get("formChangeItem"), "ITEM_", "ITEM_NONE")
        if not manifest.get("constant"):
            manifest["constant"] = f"{form['parentConstant']}_{upper_words(form['formFolder'])}"
        manifest["folder"] = f"{form['parentFolder']}/{form['formFolder']}"
        manifest["copyGraphicsFrom"] = form["copyGraphicsFrom"]
    elif manifest.get("folder"):
        manifest["folder"] = slugify(manifest["folder"])
    else:
        manifest["folder"] = slugify(manifest.get("name", manifest["constant"]))

    manifest["types"] = [
        ensure_prefixed(manifest["types"][0], "TYPE_", "TYPE_NORMAL"),
        ensure_prefixed(manifest["types"][1], "TYPE_", "TYPE_NORMAL"),
    ]
    manifest["growthRate"] = ensure_prefixed(manifest.get("growthRate"), "GROWTH_", "GROWTH_MEDIUM_FAST")
    manifest["bodyColor"] = ensure_prefixed(manifest.get("bodyColor"), "BODY_COLOR_", "BODY_COLOR_BLACK")
    manifest["eggGroups"] = [
        ensure_prefixed(manifest["eggGroups"][0], "EGG_GROUP_", "EGG_GROUP_FIELD"),
        ensure_prefixed(manifest["eggGroups"][1], "EGG_GROUP_", "EGG_GROUP_FIELD"),
    ]
    manifest["abilities"] = [
        ensure_prefixed(manifest["abilities"][0], "ABILITY_", "ABILITY_NONE"),
        ensure_prefixed(manifest["abilities"][1], "ABILITY_", "ABILITY_NONE"),
        ensure_prefixed(manifest["abilities"][2], "ABILITY_", "ABILITY_NONE"),
    ]
    manifest["heldItems"]["common"] = ensure_prefixed(manifest["heldItems"].get("common"), "ITEM_", "ITEM_NONE")
    manifest["heldItems"]["rare"] = ensure_prefixed(manifest["heldItems"].get("rare"), "ITEM_", "ITEM_NONE")
    manifest["graphics"]["frontAnimId"] = ensure_prefixed(manifest["graphics"].get("frontAnimId"), "ANIM_", "ANIM_V_SQUISH_AND_BOUNCE")
    manifest["graphics"]["backAnimId"] = ensure_prefixed(manifest["graphics"].get("backAnimId"), "BACK_ANIM_", "BACK_ANIM_NONE")
    if manifest["graphics"]["backAnimId"].startswith("BACK_ANIM_BACK_ANIM_"):
        manifest["graphics"]["backAnimId"] = manifest["graphics"]["backAnimId"].replace("BACK_ANIM_BACK_ANIM_", "BACK_ANIM_", 1)
    return manifest


def unique_constants(files: list[Path], pattern: str) -> list[str]:
    seen: set[str] = set()
    values: list[str] = []
    regex = re.compile(pattern)
    for rel in files:
        path = repo_path(rel)
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8", errors="ignore")
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
        text = re.sub(r"//.*", "", text)
        for match in regex.finditer(text):
            value = match.group(1)
            if value not in seen:
                seen.add(value)
                values.append(value)
    return values


def graphics_folders(limit: int = 2000) -> list[str]:
    root = repo_path("graphics/pokemon")
    if not root.exists():
        return []
    folders: list[str] = []
    for path in root.iterdir():
        if not path.is_dir() or not re.fullmatch(r"[A-Za-z0-9_.-]+", path.name):
            continue
        folders.append(path.name)
        for child in path.iterdir():
            if child.is_dir() and re.fullmatch(r"[A-Za-z0-9_.-]+", child.name):
                folders.append(f"{path.name}/{child.name}")
    return sorted(folders)[:limit]


def species_constants(limit: int = 2200) -> list[str]:
    text = read_text(SPECIES_CONSTANTS)
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
    text = re.sub(r"//.*", "", text)
    values: list[str] = []
    seen: set[str] = set()
    for match in re.finditer(r"^#define\s+SPECIES_([A-Z0-9_]+)\b", text, flags=re.MULTILINE):
        value = match.group(1)
        if value not in seen:
            seen.add(value)
            values.append(value)
            if len(values) >= limit:
                break
    return values


def wild_maps(limit: int = 1200) -> list[str]:
    path = repo_path(WILD_ENCOUNTERS)
    if not path.exists():
        return []
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return []
    seen: set[str] = set()
    maps: list[str] = []
    for group in data.get("wild_encounter_groups", []):
        for entry in group.get("encounters", []):
            map_name = entry.get("map")
            if isinstance(map_name, str) and map_name not in seen:
                seen.add(map_name)
                maps.append(map_name)
                if len(maps) >= limit:
                    return maps
    return maps


def load_options() -> dict:
    types = unique_constants([Path("include/constants/pokemon.h")], r"\b(TYPE_[A-Z0-9_]+)\b")
    egg_groups = unique_constants([Path("include/constants/pokemon.h")], r"\b(EGG_GROUP_[A-Z0-9_]+)\b")
    growth_rates = unique_constants([Path("include/constants/pokemon.h")], r"\b(GROWTH_[A-Z0-9_]+)\b")
    body_colors = unique_constants([Path("include/constants/pokemon.h")], r"\b(BODY_COLOR_[A-Z0-9_]+)\b")
    abilities = unique_constants([Path("include/constants/abilities.h")], r"\b(ABILITY_[A-Z0-9_]+)\b")
    items = unique_constants([Path("include/constants/items.h")], r"\b(ITEM_[A-Z0-9_]+)\b")
    moves = unique_constants([Path("include/constants/moves.h")], r"\b(MOVE_[A-Z0-9_]+)\b")
    form_change_methods = unique_constants([Path("include/pokemon.h")], r"\b(FORM_CHANGE_[A-Z0-9_]+)\b")
    front_anims = unique_constants([Path("include/pokemon_animation.h")], r"\b(ANIM_[A-Z0-9_]+)\b")
    back_anims = unique_constants([Path("include/pokemon_animation.h")], r"\b(BACK_ANIM_[A-Z0-9_]+)\b")
    shadow_sizes = unique_constants([Path("include/constants/event_objects.h")], r"\b(SHADOW_SIZE_[A-Z0-9_]+)\b")
    tracks = unique_constants([Path("include/constants/event_objects.h")], r"\b(TRACKS_[A-Z0-9_]+)\b")
    return {
        "types": types,
        "eggGroups": egg_groups,
        "growthRates": growth_rates,
        "bodyColors": body_colors,
        "abilities": abilities,
        "items": items,
        "moves": moves,
        "formChangeMethods": form_change_methods,
        "frontAnims": front_anims,
        "backAnims": back_anims,
        "shadowSizes": shadow_sizes,
        "owShadowSizes": [value for value in shadow_sizes if value != "SHADOW_SIZE_XL_BATTLE_ONLY"],
        "tracks": tracks,
        "graphicsFolders": graphics_folders(),
        "speciesConstants": species_constants(),
        "wildMaps": wild_maps(),
        "defaultManifest": DEFAULT_MANIFEST,
    }


def parse_level_moves(text: str) -> list[tuple[int, str]]:
    moves: list[tuple[int, str]] = []
    for raw in str(text or "").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or line.startswith("//"):
            continue
        macro = re.search(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)", line)
        if macro:
            moves.append((int(macro.group(1)), macro.group(2)))
            continue
        parts = re.split(r"[,\s]+", line)
        if len(parts) < 2:
            continue
        level = int_value(parts[0], None)
        if level is None:
            continue
        moves.append((level, ensure_prefixed(parts[1], "MOVE_", "MOVE_NONE")))
    return moves


def parse_move_list(text: str) -> list[str]:
    moves: list[str] = []
    seen: set[str] = set()
    for raw in str(text or "").splitlines():
        line = raw.strip().strip(",")
        if not line or line.startswith("#") or line.startswith("//"):
            continue
        found = re.search(r"\b(MOVE_[A-Z0-9_]+)\b", line.upper())
        move = found.group(1) if found else ensure_prefixed(line, "MOVE_", "MOVE_NONE")
        if move != "MOVE_NONE" and move not in seen:
            moves.append(move)
            seen.add(move)
    return moves


def parse_anim_frames(frames) -> list[tuple[int, int]]:
    parsed: list[tuple[int, int]] = []
    for frame in frames or []:
        if isinstance(frame, (list, tuple)) and len(frame) >= 2:
            parsed.append((int_value(frame[0]), int_value(frame[1], 1)))
    return parsed or [(0, 1)]


def current_level_up_file() -> Path:
    text = read_text("include/config/pokemon.h")
    match = re.search(r"^#define\s+P_LVL_UP_LEARNSETS\s+GEN_(LATEST|\d+)", text, flags=re.MULTILINE)
    if not match:
        return Path("src/data/pokemon/level_up_learnsets/gen_9.h")
    value = match.group(1)
    gen = 9 if value == "LATEST" else int(value)
    gen = max(1, min(9, gen))
    return Path(f"src/data/pokemon/level_up_learnsets/gen_{gen}.h")


def add_file(result: BuildResult, rel: Path, text: str) -> None:
    if text != read_text(rel):
        result.files[rel] = text


def update_species_constants(result: BuildResult, manifest: dict) -> None:
    const = manifest["constant"]
    text = read_text(SPECIES_CONSTANTS)
    if f"#define SPECIES_{const}" in text:
        result.warnings.append(f"SPECIES_{const} already exists; species constant was not added.")
        return

    egg_match = re.search(r"^#define\s+SPECIES_EGG\s+.+$", text, flags=re.MULTILINE)
    if not egg_match:
        result.warnings.append("Could not find SPECIES_EGG in include/constants/species.h.")
        return

    before_egg = text[: egg_match.start()]
    numeric_defines = re.findall(r"^#define\s+SPECIES_[A-Z0-9_]+\s+(\d+)\s*$", before_egg, flags=re.MULTILINE)
    if not numeric_defines:
        result.warnings.append("Could not determine next species id.")
        return

    next_id = int(numeric_defines[-1]) + 1
    new_line = f"#define SPECIES_{const:<45} {next_id}"
    text = text[: egg_match.start()] + new_line + "\n" + text[egg_match.start() :]
    text = re.sub(
        r"^#define\s+SPECIES_EGG\s+.+$",
        f"#define SPECIES_EGG                                     (SPECIES_{const} + 1)",
        text,
        count=1,
        flags=re.MULTILINE,
    )
    add_file(result, SPECIES_CONSTANTS, text)


def update_pokedex_constants(result: BuildResult, manifest: dict) -> None:
    if not manifest["include"].get("nationalDex"):
        return
    const = manifest["constant"]
    text = read_text(POKEDEX_CONSTANTS)
    if f"NATIONAL_DEX_{const}" not in text:
        marker = "\n};\n\n#define JOHTO_DEX_COUNT"
        if marker in text:
            text = text.replace(marker, f"\n    NATIONAL_DEX_{const},\n}};\n\n#define JOHTO_DEX_COUNT", 1)
        else:
            result.warnings.append("Could not find NationalDexOrder insertion point.")
    else:
        result.warnings.append(f"NATIONAL_DEX_{const} already exists; dex constant was not added.")

    if f"#define NATIONAL_DEX_COUNT  NATIONAL_DEX_{const}" not in text:
        text, count = re.subn(
            r"^(\s*#define\s+NATIONAL_DEX_COUNT\s+)NATIONAL_DEX_[A-Z0-9_]+",
            rf"\1NATIONAL_DEX_{const}",
            text,
            count=1,
            flags=re.MULTILINE,
        )
        if count == 0:
            result.warnings.append("Could not update NATIONAL_DEX_COUNT.")
        else:
            result.warnings.append("NATIONAL_DEX_COUNT was pointed at the custom species in the first config branch; review if you build with older generation toggles.")
    add_file(result, POKEDEX_CONSTANTS, text)


def update_cry_files(result: BuildResult, manifest: dict) -> None:
    if not manifest["include"].get("cry"):
        return
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    folder = manifest["folder"]

    text = read_text(CRY_CONSTANTS)
    if f"CRY_{const}," not in text:
        text = text.replace("    CRY_COUNT,\n", f"    CRY_{const},\n    CRY_COUNT,\n", 1)
        add_file(result, CRY_CONSTANTS, text)
    else:
        result.warnings.append(f"CRY_{const} already exists; cry constant was not added.")

    text = read_text(CRY_DATA)
    if f"Cry_{symbol}::" not in text:
        block = (
            f"\n\t.align 2\n"
            f"Cry_{symbol}::\n"
            f".if TESTING == FALSE\n"
            f"\t.incbin \"sound/direct_sound_samples/cries/{folder}.bin\"\n"
            f".endif\n"
        )
        anchor = ".endif @ P_FAMILY_PECHARUNT\n"
        if anchor in text:
            text = text.replace(anchor, anchor + block, 1)
        else:
            text += block
        add_file(result, CRY_DATA, text)

    text = read_text(CRY_TABLES)
    if f"\tcry Cry_{symbol}\n" not in text:
        positions = [m.start() for m in re.finditer(r"^\.endif @ P_CRIES_ENABLED$", text, flags=re.MULTILINE)]
        if len(positions) >= 2:
            first = positions[0]
            text = text[:first] + f"\tcry Cry_{symbol}\n" + text[first:]
            second = [m.start() for m in re.finditer(r"^\.endif @ P_CRIES_ENABLED$", text, flags=re.MULTILINE)][1]
            text = text[:second] + f"\tcry_reverse Cry_{symbol}\n" + text[second:]
            add_file(result, CRY_TABLES, text)
        else:
            result.warnings.append("Could not find both cry table insertion points.")


def update_graphics(result: BuildResult, manifest: dict) -> None:
    if not manifest["include"].get("graphics"):
        return
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    folder = manifest["folder"]
    gfx = manifest["graphics"]
    front_source = "front" if gfx.get("frontSource") == "front" else "anim_front"
    block_lines = [
        "",
        f"    const u32 gMonFrontPic_{symbol}[] = INCBIN_U32(\"graphics/pokemon/{folder}/{front_source}.4bpp.smol\");",
        f"    const u16 gMonPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/normal.gbapal\");",
        f"    const u32 gMonBackPic_{symbol}[] = INCBIN_U32(\"graphics/pokemon/{folder}/back.4bpp.smol\");",
        f"    const u16 gMonShinyPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/shiny.gbapal\");",
        f"    const u8 gMonIcon_{symbol}[] = INCBIN_U8(\"graphics/pokemon/{folder}/icon.4bpp\");",
        f"    const u16 gMonIconPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/icon_normal.gbapal\");",
        f"    const u16 gMonShinyIconPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/icon_shiny.gbapal\");",
        "#if P_FOOTPRINTS",
        f"    const u8 gMonFootprint_{symbol}[] = INCBIN_U8(\"graphics/pokemon/{folder}/footprint.1bpp\");",
        "#endif //P_FOOTPRINTS",
    ]
    if manifest["include"].get("overworld"):
        block_lines.extend(
            [
                "#if OW_POKEMON_OBJECT_EVENTS",
                f"    const u32 gObjectEventPic_{symbol}[] = INCBIN_COMP(\"graphics/pokemon/{folder}/overworld.4bpp\");",
                "#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE",
                f"    const u16 gOverworldPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/overworld_normal.gbapal\");",
                f"    const u16 gShinyOverworldPalette_{symbol}[] = INCBIN_U16(\"graphics/pokemon/{folder}/overworld_shiny.gbapal\");",
                "#endif //OW_PKMN_OBJECTS_SHARE_PALETTES",
                "#endif //OW_POKEMON_OBJECT_EVENTS",
            ]
        )
    block = "\n".join(block_lines) + "\n"

    text = read_text(GRAPHICS_DATA)
    if f"gMonFrontPic_{symbol}" in text:
        result.warnings.append(f"gMonFrontPic_{symbol} already exists; graphics constants were not added.")
    else:
        egg_line = '    const u8 gMonIcon_Egg[] = INCBIN_U8("graphics/pokemon/egg/icon.4bpp");\n'
        if egg_line in text:
            text = text.replace(egg_line, egg_line + block, 1)
        else:
            text += block
        add_file(result, GRAPHICS_DATA, text)

    if manifest["include"].get("overworld"):
        update_overworld_files(result, manifest)


def update_overworld_files(result: BuildResult, manifest: dict) -> None:
    symbol = symbol_from_constant(manifest["constant"])
    folder = manifest["folder"]
    ow = manifest["graphics"]["overworld"]
    width = int_value(ow.get("frameWidthTiles"), 4)
    height = int_value(ow.get("frameHeightTiles"), 4)

    text = read_text(OBJECT_EVENT_PICS)
    if f"sPicTable_{symbol}" not in text:
        block = (
            f"static const struct SpriteFrameImage sPicTable_{symbol}[] = {{\n"
            f"    overworld_ascending_frames(gObjectEventPic_{symbol}, {width}, {height}),\n"
            f"}};\n\n"
        )
        text = text.replace("#endif //OW_POKEMON_OBJECT_EVENTS\n", block + "#endif //OW_POKEMON_OBJECT_EVENTS\n", 1)
        add_file(result, OBJECT_EVENT_PICS, text)

    text = read_text(SPRITESHEET_RULES)
    rule_head = f"$(POKEMONGFXDIR)/{folder}/overworld.4bpp:"
    if rule_head not in text:
        rule = (
            f"\n$(POKEMONGFXDIR)/{folder}/overworld.4bpp: %.4bpp: %.png\n"
            f"\t$(GFX) $< $@ -mwidth {width} -mheight {height}\n"
        )
        text = text.rstrip() + "\n" + rule
        add_file(result, SPRITESHEET_RULES, text)


def update_level_up_learnset(result: BuildResult, manifest: dict) -> None:
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    rel = current_level_up_file()
    moves = parse_level_moves(manifest["moves"].get("levelUp", ""))
    if not moves:
        result.warnings.append("No level-up moves were provided; the generated learnset will only contain LEVEL_UP_END.")
    lines = [
        "",
        f"static const struct LevelUpMove s{symbol}LevelUpLearnset[] = {{",
    ]
    for level, move in moves:
        lines.append(f"    LEVEL_UP_MOVE({level:2d}, {move}),")
    lines.extend(["    LEVEL_UP_END", "};", ""])
    block = "\n".join(lines)
    text = read_text(rel)
    if f"s{symbol}LevelUpLearnset" not in text:
        text = text.rstrip() + "\n" + block
        add_file(result, rel, text)


def update_all_learnables(result: BuildResult, manifest: dict) -> None:
    const = manifest["constant"]
    moves = parse_move_list(manifest["moves"].get("teachables", ""))
    path = repo_path(ALL_LEARNABLES)
    data = json.loads(path.read_text(encoding="utf-8"))
    if const in data:
        merged = list(dict.fromkeys(list(data[const]) + moves))
        data[const] = merged
        result.warnings.append(f"{const} already existed in all_learnables.json; moves were merged in the preview.")
    else:
        data = {const: moves, **data}
    new_text = json.dumps(data, indent=2) + "\n"
    if new_text != path.read_text(encoding="utf-8"):
        result.files[ALL_LEARNABLES] = new_text


def update_makefile_teachable_dep(result: BuildResult) -> None:
    text = read_text(MAKEFILE)
    needle = "$(wildcard $(DATA_SRC_SUBDIR)/pokemon/species_info/*_families.h)  $(LEARNSET_HELPERS_DIR)/make_teaching_types.py"
    replacement = "$(wildcard $(DATA_SRC_SUBDIR)/pokemon/species_info/*_families.h) $(DATA_SRC_SUBDIR)/pokemon/species_info.h $(LEARNSET_HELPERS_DIR)/make_teaching_types.py"
    if needle in text:
        text = text.replace(needle, replacement, 1)
        add_file(result, MAKEFILE, text)


def update_species_info(result: BuildResult, manifest: dict) -> None:
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    block = species_info_block(manifest)
    text = read_text(SPECIES_INFO)
    if f"[SPECIES_{const}]" in text:
        result.warnings.append(f"SPECIES_{const} already has a SpeciesInfo block; species_info.h was not updated.")
        return
    marker = "\n};\n\nconst struct EggData"
    if marker not in text:
        result.warnings.append("Could not find SpeciesInfo insertion point.")
        return
    text = text.replace(marker, "\n" + block + marker, 1)
    add_file(result, SPECIES_INFO, text)


def species_info_block(manifest: dict) -> str:
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    gfx = manifest["graphics"]
    dex = manifest["dex"]
    flags = manifest["flags"]
    lines: list[str] = [
        f"    [SPECIES_{const}] =",
        "    {",
    ]
    for key, field_name, _label in STAT_KEYS:
        lines.append(f"        .{field_name:<13} = {int_value(manifest['baseStats'].get(key), 1)},")

    type1, type2 = manifest["types"]
    if type1 == type2:
        lines.append(f"        .types = MON_TYPES({type1}),")
    else:
        lines.append(f"        .types = MON_TYPES({type1}, {type2}),")

    lines.extend(
        [
            f"        .catchRate = {int_value(manifest.get('catchRate'), 255)},",
            f"        .expYield = {int_value(manifest.get('expYield'), 67)},",
        ]
    )
    for key, field_name in EV_KEYS:
        value = int_value(manifest["evYields"].get(key), 0)
        if value:
            lines.append(f"        .{field_name} = {value},")

    common = manifest["heldItems"].get("common", "ITEM_NONE")
    rare = manifest["heldItems"].get("rare", "ITEM_NONE")
    if common != "ITEM_NONE":
        lines.append(f"        .itemCommon = {common},")
    if rare != "ITEM_NONE":
        lines.append(f"        .itemRare = {rare},")

    egg1, egg2 = manifest["eggGroups"]
    egg_groups = egg1 if egg1 == egg2 else f"{egg1}, {egg2}"
    lines.extend(
        [
            f"        .genderRatio = {manifest.get('genderRatio') or 'PERCENT_FEMALE(50)'},",
            f"        .eggCycles = {int_value(manifest.get('eggCycles'), 20)},",
            f"        .friendship = {int_value(manifest.get('friendship'), 70)},",
            f"        .growthRate = {manifest['growthRate']},",
            f"        .eggGroups = MON_EGG_GROUPS({egg_groups}),",
            f"        .abilities = {{ {manifest['abilities'][0]}, {manifest['abilities'][1]}, {manifest['abilities'][2]} }},",
            f"        .bodyColor = {manifest['bodyColor']},",
        ]
    )
    if manifest.get("noFlip"):
        lines.append("        .noFlip = TRUE,")

    bool_flags = [
        "isRestrictedLegendary",
        "isSubLegendary",
        "isMythical",
        "isUltraBeast",
        "isParadox",
        "isFrontierBanned",
        "tmIlliterate",
    ]
    for key in bool_flags:
        if flags.get(key):
            lines.append(f"        .{key} = TRUE,")
    if str(flags.get("perfectIVCount", "")).strip():
        lines.append(f"        .perfectIVCount = {str(flags['perfectIVCount']).strip()},")

    lines.append(f"        .speciesName = _(\"{c_string(manifest.get('name', symbol))}\"),")
    if manifest["include"].get("cry"):
        lines.append(f"        .cryId = CRY_{const},")
    else:
        lines.append("        .cryId = CRY_NONE,")
    if manifest["include"].get("nationalDex"):
        lines.append(f"        .natDexNum = NATIONAL_DEX_{const},")
    else:
        lines.append("        .natDexNum = NATIONAL_DEX_NONE,")
    lines.extend(
        [
            f"        .categoryName = _(\"{c_string(dex.get('categoryName', 'Unknown'))}\"),",
            f"        .height = {int_value(dex.get('height'), 0)},",
            f"        .weight = {int_value(dex.get('weight'), 0)},",
            "        .description = COMPOUND_STRING(",
        ]
    )
    desc_lines = dex.get("description") or ["This is a newly discovered Pokemon."]
    for index, line in enumerate(desc_lines):
        suffix = "\\n" if index < len(desc_lines) - 1 else ""
        lines.append(f"            \"{c_string(str(line))}{suffix}\"")
    lines.append("        ),")
    lines.extend(
        [
            f"        .pokemonScale = {int_value(dex.get('pokemonScale'), 256)},",
            f"        .pokemonOffset = {int_value(dex.get('pokemonOffset'), 0)},",
            f"        .trainerScale = {int_value(dex.get('trainerScale'), 256)},",
            f"        .trainerOffset = {int_value(dex.get('trainerOffset'), 0)},",
        ]
    )

    if manifest["include"].get("graphics"):
        lines.extend(
            [
                f"        .frontPic = gMonFrontPic_{symbol},",
                f"        .frontPicSize = MON_COORDS_SIZE({int_value(gfx.get('frontWidth'), 64)}, {int_value(gfx.get('frontHeight'), 64)}),",
                f"        .frontPicYOffset = {int_value(gfx.get('frontYOffset'), 0)},",
                "        .frontAnimFrames = ANIM_FRAMES(",
            ]
        )
        for frame, duration in parse_anim_frames(gfx.get("frontAnimFrames")):
            lines.append(f"            ANIMCMD_FRAME({frame}, {duration}),")
        lines.extend(
            [
                "        ),",
                f"        .frontAnimId = {gfx.get('frontAnimId', 'ANIM_V_SQUISH_AND_BOUNCE')},",
            ]
        )
        if int_value(gfx.get("frontAnimDelay"), 0):
            lines.append(f"        .frontAnimDelay = {int_value(gfx.get('frontAnimDelay'), 0)},")
        if int_value(gfx.get("enemyMonElevation"), 0):
            lines.append(f"        .enemyMonElevation = {int_value(gfx.get('enemyMonElevation'), 0)},")
        lines.extend(
            [
                f"        .backPic = gMonBackPic_{symbol},",
                f"        .backPicSize = MON_COORDS_SIZE({int_value(gfx.get('backWidth'), 64)}, {int_value(gfx.get('backHeight'), 64)}),",
                f"        .backPicYOffset = {int_value(gfx.get('backYOffset'), 0)},",
                f"        .backAnimId = {gfx.get('backAnimId', 'BACK_ANIM_NONE')},",
                f"        .palette = gMonPalette_{symbol},",
                f"        .shinyPalette = gMonShinyPalette_{symbol},",
                f"        .iconSprite = gMonIcon_{symbol},",
                f"        .iconPalIndex = {int_value(gfx.get('iconPalIndex'), 0)},",
                f"        FOOTPRINT({symbol})",
            ]
        )
        shadow = gfx.get("shadow", {})
        if shadow.get("enabled"):
            lines.append(f"        SHADOW({int_value(shadow.get('x'), 0)}, {int_value(shadow.get('y'), 0)}, {shadow.get('size', 'SHADOW_SIZE_S')})")
        else:
            lines.append("        NO_SHADOW")
        if manifest["include"].get("overworld"):
            ow = gfx["overworld"]
            lines.extend(
                [
                    "        OVERWORLD(",
                    f"            sPicTable_{symbol},",
                    f"            {ow.get('size', 'SIZE_32x32')},",
                    f"            {ow.get('shadowSize', 'SHADOW_SIZE_M')},",
                    f"            {ow.get('tracks', 'TRACKS_FOOT')},",
                    f"            {ow.get('animTable', 'sAnimTable_Following')},",
                    f"            gOverworldPalette_{symbol},",
                    f"            gShinyOverworldPalette_{symbol}",
                    "        )",
                ]
            )

    lines.extend(
        [
            f"        .levelUpLearnset = s{symbol}LevelUpLearnset,",
            f"        .teachableLearnset = s{symbol}TeachableLearnset,",
            "    },",
            "",
        ]
    )
    return "\n".join(lines)


def preproc_guard_block(block: str, guard: str) -> str:
    guard = str(guard or "").strip()
    if not guard:
        return block
    return f"#if {guard}\n{block}#endif //{guard}\n"


def existing_form_species_info_block(manifest: dict) -> str:
    const = manifest["constant"]
    symbol = symbol_from_constant(const)
    gfx = manifest["graphics"]
    dex = manifest["dex"]
    flags = manifest["flags"]
    form = manifest["form"]
    lines: list[str] = [
        f"    [SPECIES_{const}] =",
        "    {",
    ]
    for key, field_name, _label in STAT_KEYS:
        lines.append(f"        .{field_name:<13} = {int_value(manifest['baseStats'].get(key), 1)},")

    type1, type2 = manifest["types"]
    if type1 == type2:
        lines.append(f"        .types = MON_TYPES({type1}),")
    else:
        lines.append(f"        .types = MON_TYPES({type1}, {type2}),")

    lines.extend(
        [
            f"        .catchRate = {int_value(manifest.get('catchRate'), 255)},",
            f"        .expYield = {int_value(manifest.get('expYield'), 67)},",
        ]
    )
    for key, field_name in EV_KEYS:
        value = int_value(manifest["evYields"].get(key), 0)
        if value:
            lines.append(f"        .{field_name} = {value},")

    lines.extend(
        [
            f"        .genderRatio = {manifest.get('genderRatio') or 'PERCENT_FEMALE(50)'},",
            f"        .eggCycles = {int_value(manifest.get('eggCycles'), 20)},",
            f"        .friendship = {int_value(manifest.get('friendship'), 70)},",
            f"        .growthRate = {manifest['growthRate']},",
            f"        .eggGroups = MON_EGG_GROUPS({manifest['eggGroups'][0]}),",
            f"        .abilities = {{ {manifest['abilities'][0]}, {manifest['abilities'][1]}, {manifest['abilities'][2]} }},",
            f"        .bodyColor = {manifest['bodyColor']},",
            f"        .speciesName = _(\"{c_string(form.get('speciesName') or manifest.get('name', symbol))}\"),",
            f"        .cryId = {form.get('cryId', 'CRY_NONE')},",
            f"        .natDexNum = {form.get('natDexConstant', 'NATIONAL_DEX_NONE')},",
            f"        .categoryName = _(\"{c_string(dex.get('categoryName', 'Unknown'))}\"),",
            f"        .height = {int_value(dex.get('height'), 0)},",
            f"        .weight = {int_value(dex.get('weight'), 0)},",
            "        .description = COMPOUND_STRING(",
        ]
    )
    desc_lines = dex.get("description") or ["This is a newly discovered form."]
    for index, line in enumerate(desc_lines):
        suffix = "\\n" if index < len(desc_lines) - 1 else ""
        lines.append(f"            \"{c_string(str(line))}{suffix}\"")
    lines.append("        ),")
    lines.extend(
        [
            f"        .pokemonScale = {int_value(dex.get('pokemonScale'), 256)},",
            f"        .pokemonOffset = {int_value(dex.get('pokemonOffset'), 0)},",
            f"        .trainerScale = {int_value(dex.get('trainerScale'), 256)},",
            f"        .trainerOffset = {int_value(dex.get('trainerOffset'), 0)},",
            f"        .frontPic = gMonFrontPic_{symbol},",
            f"        .frontPicSize = MON_COORDS_SIZE({int_value(gfx.get('frontWidth'), 64)}, {int_value(gfx.get('frontHeight'), 64)}),",
            f"        .frontPicYOffset = {int_value(gfx.get('frontYOffset'), 0)},",
            "        .frontAnimFrames = ANIM_FRAMES(",
        ]
    )
    for frame, duration in parse_anim_frames(gfx.get("frontAnimFrames")):
        lines.append(f"            ANIMCMD_FRAME({frame}, {duration}),")
    lines.extend(
        [
            "        ),",
            f"        .frontAnimId = {gfx.get('frontAnimId', 'ANIM_V_SQUISH_AND_BOUNCE')},",
        ]
    )
    if int_value(gfx.get("frontAnimDelay"), 0):
        lines.append(f"        .frontAnimDelay = {int_value(gfx.get('frontAnimDelay'), 0)},")
    if int_value(gfx.get("enemyMonElevation"), 0):
        lines.append(f"        .enemyMonElevation = {int_value(gfx.get('enemyMonElevation'), 0)},")
    lines.extend(
        [
            f"        .backPic = gMonBackPic_{symbol},",
            f"        .backPicSize = MON_COORDS_SIZE({int_value(gfx.get('backWidth'), 64)}, {int_value(gfx.get('backHeight'), 64)}),",
            f"        .backPicYOffset = {int_value(gfx.get('backYOffset'), 0)},",
            f"        .backAnimId = {gfx.get('backAnimId', 'BACK_ANIM_NONE')},",
            f"        .palette = gMonPalette_{symbol},",
            f"        .shinyPalette = gMonShinyPalette_{symbol},",
            f"        .iconSprite = gMonIcon_{symbol},",
            f"        .iconPalette = gMonIconPalette_{symbol},",
            f"        .shinyIconPalette = gMonShinyIconPalette_{symbol},",
            f"        FOOTPRINT({form.get('footprintSymbol') or form.get('tableSymbol') or symbol})",
        ]
    )
    shadow = gfx.get("shadow", {})
    if shadow.get("enabled"):
        lines.append(f"        SHADOW({int_value(shadow.get('x'), 0)}, {int_value(shadow.get('y'), 0)}, {shadow.get('size', 'SHADOW_SIZE_S')})")
    else:
        lines.append("        NO_SHADOW")
    if manifest["include"].get("overworld"):
        ow = gfx["overworld"]
        lines.extend(
            [
                "        OVERWORLD(",
                f"            sPicTable_{symbol},",
                f"            {ow.get('size', 'SIZE_32x32')},",
                f"            {ow.get('shadowSize', 'SHADOW_SIZE_M')},",
                f"            {ow.get('tracks', 'TRACKS_FOOT')},",
                f"            {ow.get('animTable', 'sAnimTable_Following')},",
                f"            gOverworldPalette_{symbol},",
                f"            gShinyOverworldPalette_{symbol}",
                "        )",
            ]
        )
    if form.get("isMegaEvolution"):
        lines.append("        .isMegaEvolution = TRUE,")
    for key in ["isRestrictedLegendary", "isSubLegendary", "isMythical", "isUltraBeast", "isParadox", "isFrontierBanned", "tmIlliterate"]:
        if flags.get(key):
            lines.append(f"        .{key} = TRUE,")
    if str(flags.get("perfectIVCount", "")).strip():
        lines.append(f"        .perfectIVCount = {str(flags['perfectIVCount']).strip()},")
    lines.extend(
        [
            f"        .levelUpLearnset = s{form.get('learnsetSymbol', symbol)}LevelUpLearnset,",
            f"        .teachableLearnset = s{form.get('learnsetSymbol', symbol)}TeachableLearnset,",
            f"        .formSpeciesIdTable = {form.get('formSpeciesTable')},",
            f"        .formChangeTable = {form.get('formChangeTable')},",
            "    },",
            "",
        ]
    )
    return "\n".join(lines)


def find_species_info_family_file(parent_const: str) -> Path | None:
    needle = f"[SPECIES_{parent_const}]"
    for path in sorted(repo_path(SPECIES_INFO_DIR).glob("*_families.h")):
        rel = path.relative_to(REPO_ROOT)
        if needle in path.read_text(encoding="utf-8", errors="ignore"):
            return rel
    return None


def family_guard_for_species(text: str, parent_const: str) -> tuple[str, int] | None:
    pos = text.find(f"[SPECIES_{parent_const}]")
    if pos == -1:
        return None
    guards = list(re.finditer(r"^#if\s+(P_FAMILY_[A-Z0-9_]+)\s*$", text[:pos], flags=re.MULTILINE))
    if not guards:
        return None
    return guards[-1].group(1), pos


def update_existing_form_species_info(result: BuildResult, manifest: dict) -> None:
    const = manifest["constant"]
    form = manifest["form"]
    rel = find_species_info_family_file(form["parentConstant"])
    if rel is None:
        result.warnings.append(f"Could not find SpeciesInfo family file for SPECIES_{form['parentConstant']}.")
        return
    text = read_text(rel)
    if f"[SPECIES_{const}]" in text:
        result.warnings.append(f"SPECIES_{const} already has a SpeciesInfo block in {rel_display(rel)}.")
        return
    family = family_guard_for_species(text, form["parentConstant"])
    if family is None:
        result.warnings.append(f"Could not find P_FAMILY guard for SPECIES_{form['parentConstant']} in {rel_display(rel)}.")
        return
    family_guard, parent_pos = family
    end_marker = f"#endif //{family_guard}"
    insert_at = text.find(end_marker, parent_pos)
    if insert_at == -1:
        result.warnings.append(f"Could not find {end_marker} in {rel_display(rel)}.")
        return
    block = "\n" + preproc_guard_block(existing_form_species_info_block(manifest), form.get("guard", ""))
    text = text[:insert_at] + block + text[insert_at:]
    add_file(result, rel, text)


def insert_guarded_table_line(body: str, line: str, guard: str) -> str:
    lines = [line]
    if guard:
        lines = [f"#if {guard}", line, f"#endif //{guard}"]
    return "\n".join(lines) + "\n"


def update_form_species_table(result: BuildResult, manifest: dict) -> None:
    form = manifest["form"]
    if not form.get("updateFormSpeciesTable"):
        return
    const = manifest["constant"]
    table = re.escape(form.get("formSpeciesTable", ""))
    text = read_text(FORM_SPECIES_TABLES)
    if f"SPECIES_{const}" in text:
        result.warnings.append(f"SPECIES_{const} is already present in form_species_tables.h.")
        return
    match = re.search(rf"static const u16 {table}\[\]\s*=\s*\{{", text)
    if not match:
        result.warnings.append(f"Could not find {form.get('formSpeciesTable')} in form_species_tables.h.")
        return
    end = text.find("};", match.end())
    if end == -1:
        result.warnings.append(f"Could not find end of {form.get('formSpeciesTable')}.")
        return
    body = text[match.end():end]
    marker = re.search(r"^(\s*)FORM_SPECIES_END,", body, flags=re.MULTILINE)
    if not marker:
        result.warnings.append(f"Could not find FORM_SPECIES_END in {form.get('formSpeciesTable')}.")
        return
    insert_at = match.end() + marker.start()
    line = f"    SPECIES_{const},"
    text = text[:insert_at] + insert_guarded_table_line(body, line, form.get("guard", "")) + text[insert_at:]
    add_file(result, FORM_SPECIES_TABLES, text)


def update_form_change_table(result: BuildResult, manifest: dict) -> None:
    form = manifest["form"]
    if not form.get("updateFormChangeTable"):
        return
    const = manifest["constant"]
    table = re.escape(form.get("formChangeTable", ""))
    text = read_text(FORM_CHANGE_TABLES)
    if f"SPECIES_{const}" in text:
        result.warnings.append(f"SPECIES_{const} is already present in form_change_tables.h.")
        return
    match = re.search(rf"static const struct FormChange {table}\[\]\s*=\s*\n\s*\{{", text)
    if not match:
        result.warnings.append(f"Could not find {form.get('formChangeTable')} in form_change_tables.h.")
        return
    end = text.find("};", match.end())
    if end == -1:
        result.warnings.append(f"Could not find end of {form.get('formChangeTable')}.")
        return
    body = text[match.end():end]
    marker = re.search(r"^\s*\{FORM_CHANGE_(?:FAINT|END_BATTLE|TERMINATOR)", body, flags=re.MULTILINE)
    if not marker:
        result.warnings.append(f"Could not find fallback insertion point in {form.get('formChangeTable')}.")
        return
    item = form.get("formChangeItem", "ITEM_NONE")
    if item and item != "ITEM_NONE":
        line = f"    {{{form.get('formChangeMethod')},    SPECIES_{const}, {item}}},"
    else:
        line = f"    {{{form.get('formChangeMethod')},    SPECIES_{const}}},"
    insert_at = match.end() + marker.start()
    text = text[:insert_at] + insert_guarded_table_line(body, line, form.get("guard", "")) + text[insert_at:]
    add_file(result, FORM_CHANGE_TABLES, text)


def update_pokedex_orders(result: BuildResult, manifest: dict) -> None:
    if not manifest["include"].get("nationalDex"):
        return
    const = manifest["constant"]
    text = read_text(POKEDEX_ORDERS)
    if f"NATIONAL_DEX_{const}" in text:
        result.warnings.append(f"NATIONAL_DEX_{const} is already present in pokedex_orders.h.")
        return

    text = insert_in_pokedex_array(text, "gPokedexOrder_Alphabetical", f"    NATIONAL_DEX_{const},", const, None)
    weight_kg = int_value(manifest["dex"].get("weight"), 0) / 10.0
    height_m = int_value(manifest["dex"].get("height"), 0) / 10.0
    text = insert_in_pokedex_array(text, "gPokedexOrder_Weight", f"    NATIONAL_DEX_{const},", const, weight_kg)
    text = insert_in_pokedex_array(text, "gPokedexOrder_Height", f"    NATIONAL_DEX_{const},", const, height_m)
    add_file(result, POKEDEX_ORDERS, text)


def insert_in_pokedex_array(text: str, array_name: str, new_line: str, const: str, metric: float | None) -> str:
    start_match = re.search(rf"const u16 {array_name}\[\]\s*=\s*\{{\n", text)
    if not start_match:
        return text
    start = start_match.end()
    end = text.find("\n};", start)
    if end == -1:
        return text
    body = text[start:end]
    lines = body.splitlines()
    insert_at = len(lines)
    if metric is None:
        for i, line in enumerate(lines):
            match = re.search(r"NATIONAL_DEX_([A-Z0-9_]+)", line)
            if match and match.group(1) > const:
                insert_at = i
                break
    else:
        unit = "kg" if "Weight" in array_name else "m"
        comment_re = re.compile(rf"//.*?/ ([0-9]+(?:\.[0-9]+)?)\s*{unit}")
        for i, line in enumerate(lines):
            match = comment_re.search(line)
            if match and float(match.group(1)) >= metric:
                insert_at = i + 1
                break
    lines.insert(insert_at, new_line)
    return text[:start] + "\n".join(lines) + text[end:]


def update_wild_encounter(result: BuildResult, manifest: dict) -> None:
    if not manifest["include"].get("wildEncounter"):
        return
    encounter = manifest["wildEncounter"]
    map_name = str(encounter.get("map", "")).strip()
    method = str(encounter.get("method", "land_mons")).strip()
    slot = int_value(encounter.get("slot"), 0)
    if not map_name:
        result.warnings.append("Wild encounter was enabled, but no map was provided.")
        return
    data = json.loads(read_text(WILD_ENCOUNTERS))
    changed = False
    for group in data.get("wild_encounter_groups", []):
        for entry in group.get("encounters", []):
            if entry.get("map") != map_name or method not in entry:
                continue
            mons = entry[method].get("mons", [])
            if not (0 <= slot < len(mons)):
                result.warnings.append(f"{map_name} {method} has no slot {slot}.")
                return
            mons[slot]["species"] = f"SPECIES_{manifest['constant']}"
            mons[slot]["min_level"] = int_value(encounter.get("minLevel"), 5)
            mons[slot]["max_level"] = int_value(encounter.get("maxLevel"), 5)
            changed = True
            break
        if changed:
            break
    if not changed:
        result.warnings.append(f"Could not find {map_name} with {method} in wild_encounters.json.")
        return
    result.files[WILD_ENCOUNTERS] = json.dumps(data, indent=2) + "\n"


def build_changes(raw_manifest: dict) -> tuple[dict, BuildResult]:
    manifest = normalize_manifest(raw_manifest)
    result = BuildResult()
    validate_manifest(manifest, result)
    if manifest.get("kind") == "form":
        update_species_constants(result, manifest)
        update_graphics(result, manifest)
        update_existing_form_species_info(result, manifest)
        update_form_species_table(result, manifest)
        update_form_change_table(result, manifest)
        add_side_effects(result, manifest)
        return manifest, result

    update_species_constants(result, manifest)
    update_pokedex_constants(result, manifest)
    update_cry_files(result, manifest)
    update_graphics(result, manifest)
    update_level_up_learnset(result, manifest)
    update_all_learnables(result, manifest)
    update_makefile_teachable_dep(result)
    update_species_info(result, manifest)
    update_pokedex_orders(result, manifest)
    update_wild_encounter(result, manifest)
    add_side_effects(result, manifest)
    return manifest, result


def validate_manifest(manifest: dict, result: BuildResult) -> None:
    const = manifest["constant"]
    if not re.fullmatch(r"[A-Z][A-Z0-9_]*", const):
        result.warnings.append("Constant stem should be uppercase C identifier text.")
    for key, _field, label in STAT_KEYS:
        value = int_value(manifest["baseStats"].get(key), 0)
        if value < 1 or value > 255:
            result.warnings.append(f"{label} base stat should be between 1 and 255.")
    total_evs = 0
    for key, _field in EV_KEYS:
        value = int_value(manifest["evYields"].get(key), 0)
        total_evs += value
        if value < 0 or value > 3:
            result.warnings.append("Individual EV yields should be between 0 and 3.")
    if total_evs > 3:
        result.warnings.append("Official-style EV yields usually total 3 or less.")
    if manifest["kind"] == "form":
        parent = manifest["form"]["parentConstant"]
        if parent not in species_constants():
            result.warnings.append(f"SPECIES_{parent} was not found in include/constants/species.h.")
        if find_species_info_family_file(parent) is None:
            result.warnings.append(f"Could not find a species_info family file for SPECIES_{parent}.")
    if manifest["kind"] != "form" and manifest["include"].get("cry") and not (repo_path(Path("sound/direct_sound_samples/cries") / f"{manifest['folder']}.wav").exists() or manifest["cry"].get("sourcePath")):
        result.warnings.append("Cry is enabled but no existing .wav or source path was found.")
    if manifest["include"].get("graphics"):
        graphics_dir = repo_path(Path("graphics/pokemon") / manifest["folder"])
        clone_dir = repo_path(Path("graphics/pokemon") / str(manifest.get("copyGraphicsFrom", "")))
        if not graphics_dir.exists() and not clone_dir.exists():
            result.warnings.append("Graphics folder does not exist, and the clone-from folder was not found.")


def add_side_effects(result: BuildResult, manifest: dict) -> None:
    if manifest["include"].get("graphics"):
        folder = manifest["folder"]
        source = str(manifest.get("copyGraphicsFrom", "")).strip()
        target_dir = Path("graphics/pokemon") / folder
        if source and not repo_path(target_dir).exists():
            result.operations.append(f"Copy graphics/pokemon/{source} -> {rel_display(target_dir)}")
    if manifest["include"].get("cry") and manifest["cry"].get("sourcePath"):
        result.operations.append(f"Copy cry source to sound/direct_sound_samples/cries/{manifest['folder']}.wav")
    result.operations.append(f"Save manifest to tools/new_pokemon/species/{manifest['folder']}.json")


def apply_side_effects(manifest: dict) -> None:
    if manifest["include"].get("graphics"):
        folder = manifest["folder"]
        source = str(manifest.get("copyGraphicsFrom", "")).strip()
        target = repo_path(Path("graphics/pokemon") / folder)
        if source and not target.exists():
            source_path = repo_path(Path("graphics/pokemon") / source)
            if source_path.exists():
                shutil.copytree(source_path, target)
    if manifest["include"].get("cry") and manifest["cry"].get("sourcePath"):
        source = Path(manifest["cry"]["sourcePath"]).expanduser()
        if source.exists():
            dest = repo_path(Path("sound/direct_sound_samples/cries") / f"{manifest['folder']}.wav")
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, dest)
    save_manifest(manifest)


def diff_result(result: BuildResult) -> str:
    parts: list[str] = []
    for rel in sorted(result.files, key=lambda p: str(p)):
        old = read_text(rel).splitlines(keepends=True)
        new = result.files[rel].splitlines(keepends=True)
        parts.extend(
            difflib.unified_diff(
                old,
                new,
                fromfile=f"a/{rel_display(rel)}",
                tofile=f"b/{rel_display(rel)}",
            )
        )
    return "".join(parts)


def result_payload(manifest: dict, result: BuildResult, message: str) -> dict:
    return {
        "manifest": manifest,
        "warnings": result.warnings,
        "operations": result.operations,
        "diff": diff_result(result),
        "message": message,
    }


def save_manifest(manifest: dict) -> Path:
    MANIFEST_DIR.mkdir(parents=True, exist_ok=True)
    path = MANIFEST_DIR / f"{manifest['folder']}.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return path


def list_manifests() -> list[str]:
    if not MANIFEST_DIR.exists():
        return []
    return sorted(rel_display(path.relative_to(MANIFEST_DIR)) for path in MANIFEST_DIR.rglob("*.json"))


def safe_asset_path(path: str) -> Path | None:
    raw = unquote(path).removeprefix("/asset/").lstrip("/")
    rel = Path(raw)
    if rel.is_absolute() or ".." in rel.parts:
        return None
    if len(rel.parts) < 4 or rel.parts[0] != "graphics" or rel.parts[1] != "pokemon":
        return None
    if rel.suffix.lower() not in {".png", ".pal"}:
        return None
    asset_root = (REPO_ROOT / "graphics" / "pokemon").resolve()
    resolved = (REPO_ROOT / rel).resolve()
    try:
        resolved.relative_to(asset_root)
    except ValueError:
        return None
    if not resolved.is_file():
        return None
    return resolved


class WizardHandler(BaseHTTPRequestHandler):
    server_version = "NewPokemonWizard/1.0"

    def log_message(self, fmt, *args):
        sys.stderr.write("%s - %s\n" % (self.address_string(), fmt % args))

    def send_json(self, payload: dict, status: int = 200) -> None:
        encoded = json.dumps(payload).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(encoded)))
        self.end_headers()
        self.wfile.write(encoded)

    def read_json(self) -> dict:
        length = int(self.headers.get("Content-Length", "0"))
        if length == 0:
            return {}
        return json.loads(self.rfile.read(length).decode("utf-8"))

    def send_asset(self, path: str, head_only: bool = False) -> None:
        asset = safe_asset_path(path)
        if asset is None:
            self.send_response(404)
            self.send_header("Content-Length", "0")
            self.end_headers()
            return
        content_type = mimetypes.guess_type(asset.name)[0] or "application/octet-stream"
        if asset.suffix.lower() == ".pal":
            content_type = "text/plain; charset=utf-8"
        size = asset.stat().st_size
        self.send_response(200)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(size))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        if not head_only:
            self.wfile.write(asset.read_bytes())

    def do_HEAD(self):
        parsed = urlparse(self.path)
        if parsed.path.startswith("/asset/"):
            self.send_asset(parsed.path, head_only=True)
            return
        self.send_response(404)
        self.send_header("Content-Length", "0")
        self.end_headers()

    def do_GET(self):
        parsed = urlparse(self.path)
        try:
            if parsed.path == "/":
                encoded = HTML.encode("utf-8")
                self.send_response(200)
                self.send_header("Content-Type", "text/html; charset=utf-8")
                self.send_header("Content-Length", str(len(encoded)))
                self.end_headers()
                self.wfile.write(encoded)
            elif parsed.path.startswith("/asset/"):
                self.send_asset(parsed.path)
            elif parsed.path == "/api/options":
                self.send_json(load_options())
            elif parsed.path == "/api/manifests":
                self.send_json({"manifests": list_manifests()})
            elif parsed.path == "/api/manifest":
                name = parse_qs(parsed.query).get("name", [""])[0]
                if not re.fullmatch(r"[A-Za-z0-9_.\-/]+\.json", name) or ".." in Path(name).parts:
                    self.send_json({"error": "Invalid manifest name."}, 400)
                    return
                path = MANIFEST_DIR / name
                if not path.exists():
                    self.send_json({"error": "Manifest not found."}, 404)
                    return
                self.send_json({"manifest": normalize_manifest(json.loads(path.read_text(encoding="utf-8")))})
            else:
                self.send_json({"error": "Not found."}, 404)
        except Exception as exc:
            self.send_json({"error": str(exc)}, 500)

    def do_POST(self):
        parsed = urlparse(self.path)
        try:
            data = self.read_json()
            if parsed.path == "/api/preview":
                manifest, result = build_changes(data)
                self.send_json(result_payload(manifest, result, "Preview generated."))
            elif parsed.path == "/api/apply":
                manifest, result = build_changes(data)
                for rel, text in result.files.items():
                    write_text(rel, text)
                apply_side_effects(manifest)
                self.send_json(result_payload(manifest, result, f"Applied {len(result.files)} file changes."))
            elif parsed.path == "/api/save":
                manifest = normalize_manifest(data)
                path = save_manifest(manifest)
                self.send_json({"message": f"Saved {path.relative_to(REPO_ROOT)}.", "warnings": [], "operations": [], "diff": ""})
            else:
                self.send_json({"error": "Not found."}, 404)
        except Exception as exc:
            self.send_json({"error": str(exc)}, 500)


def command_preview(path: Path) -> int:
    manifest, result = build_changes(json.loads(path.read_text(encoding="utf-8")))
    payload = result_payload(manifest, result, "Preview generated.")
    if payload["warnings"]:
        print("Warnings:", file=sys.stderr)
        for warning in payload["warnings"]:
            print(f"- {warning}", file=sys.stderr)
    for operation in payload["operations"]:
        print(f"operation: {operation}", file=sys.stderr)
    print(payload["diff"])
    return 0


def command_apply(path: Path) -> int:
    manifest, result = build_changes(json.loads(path.read_text(encoding="utf-8")))
    for rel, text in result.files.items():
        write_text(rel, text)
    apply_side_effects(manifest)
    print(f"Applied {len(result.files)} file changes.")
    if result.warnings:
        print("Warnings:")
        for warning in result.warnings:
            print(f"- {warning}")
    return 0


def serve(port: int, host: str) -> int:
    httpd = ThreadingHTTPServer((host, port), WizardHandler)
    url_host = "127.0.0.1" if host in ("0.0.0.0", "") else host
    print(f"New Pokemon Wizard running at http://{url_host}:{port}/")
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nStopped.")
    return 0


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Local wizard for adding custom Pokemon species.")
    parser.add_argument("command", nargs="?", choices=["preview", "apply"], help="Preview or apply a manifest from the CLI.")
    parser.add_argument("manifest", nargs="?", type=Path, help="Manifest JSON path for preview/apply.")
    parser.add_argument("--serve", action="store_true", help="Start the browser UI.")
    parser.add_argument("--host", default="127.0.0.1", help="Host for --serve.")
    parser.add_argument("--port", type=int, default=8765, help="Port for --serve.")
    args = parser.parse_args(argv)

    if args.serve:
        return serve(args.port, args.host)
    if args.command == "preview":
        if not args.manifest:
            parser.error("preview requires a manifest path")
        return command_preview(args.manifest)
    if args.command == "apply":
        if not args.manifest:
            parser.error("apply requires a manifest path")
        return command_apply(args.manifest)
    parser.print_help()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
