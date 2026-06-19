"""Sprite and icon processing helpers for the SoulGold docs generator."""

from __future__ import annotations

import re
import shutil
from pathlib import Path

from PIL import Image

from .constants import GBA_COLOR_CHANNEL_MAX, MOVE_CATEGORY_ICON_FILES, PIL_PALETTE_SIZE, RGB_CHANNEL_MAX, SHINY_TOGGLE_ICON_FILE, SHINY_TOGGLE_ICON_SIZE, SPRITE_FRAME_SIZE, TYPE_ICON_FILES
from .c_parser import asset_stem, normalize_token, read
from .models import ItemRecord
from .paths import GRAPHICS_POKEMON_H, OUT_DIR, REPO_ROOT, TRAINER_FRONT_PIC_DIR, TYPE_GRAPHICS_DIR


def parse_front_pic_sources() -> dict[str, Path]:
    pic_map: dict[str, Path] = {}
    pattern = re.compile(r'const\s+u32\s+(gMonFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\("([^"]+)"\);')
    for symbol, incbin in pattern.findall(read(GRAPHICS_POKEMON_H)):
        if symbol in pic_map and "_gba" in incbin:
            continue
        png = REPO_ROOT / re.sub(r"(?:_gba)?\.4bpp(?:\.smol)?$", ".png", incbin)
        if png.exists():
            pic_map[symbol] = png
    return pic_map

def parse_shiny_palette_sources() -> dict[str, Path]:
    palette_map: dict[str, Path] = {}
    pattern = re.compile(r'const\s+u16\s+(gMonShinyPalette_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U16\("([^"]+)"\);')
    for symbol, incbin in pattern.findall(read(GRAPHICS_POKEMON_H)):
        if symbol in palette_map and "_gba" in incbin:
            continue
        palette = REPO_ROOT / incbin
        if palette.exists():
            palette_map[symbol] = palette
    return palette_map

def shiny_palette_symbol(front_pic_symbol: str) -> str:
    symbol = front_pic_symbol.replace("gMonFrontPic_", "gMonShinyPalette_", 1)
    return symbol[:-1] if symbol.endswith("F") else symbol

def read_gbapal(path: Path) -> list[int]:
    raw = path.read_bytes()
    palette: list[int] = []
    for index in range(0, len(raw) - 1, 2):
        value = raw[index] | (raw[index + 1] << 8)
        palette.extend([
            (value & 0x1F) * RGB_CHANNEL_MAX // GBA_COLOR_CHANNEL_MAX,
            ((value >> 5) & 0x1F) * RGB_CHANNEL_MAX // GBA_COLOR_CHANNEL_MAX,
            ((value >> 10) & 0x1F) * RGB_CHANNEL_MAX // GBA_COLOR_CHANNEL_MAX,
        ])
    palette.extend([0] * (PIL_PALETTE_SIZE - len(palette)))
    return palette[:PIL_PALETTE_SIZE]

def process_sprite(source: Path, target: Path, palette: Path | None = None) -> None:
    target.parent.mkdir(parents=True, exist_ok=True)
    image = Image.open(source)
    if image.mode != "P":
        image = image.convert("P")
    if palette:
        image.putpalette(read_gbapal(palette))
    frame = image.crop((0, 0, min(SPRITE_FRAME_SIZE, image.width), min(SPRITE_FRAME_SIZE, image.height)))
    rgba = frame.convert("RGBA")
    pixels = []
    for y in range(frame.height):
        for x in range(frame.width):
            pixel = rgba.getpixel((x, y))
            pixels.append((pixel[0], pixel[1], pixel[2], 0) if frame.getpixel((x, y)) == 0 else pixel)
    rgba.putdata(pixels)
    rgba.save(target)

def copy_type_icons() -> dict[str, str]:
    output_dir = OUT_DIR / "sprites" / "types"
    output_dir.mkdir(parents=True, exist_ok=True)
    icons: dict[str, str] = {}
    for type_constant, filename in TYPE_ICON_FILES.items():
        source = TYPE_GRAPHICS_DIR / filename
        if not source.exists():
            continue
        target = output_dir / filename
        shutil.copy2(source, target)
        icons[type_constant] = str(target.relative_to(OUT_DIR))
    return icons

def copy_move_category_icons() -> dict[str, str]:
    output_dir = OUT_DIR / "sprites" / "categories"
    output_dir.mkdir(parents=True, exist_ok=True)
    icons: dict[str, str] = {}
    for category, filename in MOVE_CATEGORY_ICON_FILES.items():
        source = next(
            (
                path
                for path in (REPO_ROOT / filename, output_dir / filename)
                if path.exists()
            ),
            None,
        )
        if source is None:
            continue
        target = output_dir / filename
        if source.resolve() != target.resolve():
            shutil.copy2(source, target)
        icons[category] = str(target.relative_to(OUT_DIR))
    return icons

def copy_shiny_toggle_icon() -> str | None:
    output_dir = OUT_DIR / "sprites" / "ui"
    source = next(
        (
            path
            for path in (REPO_ROOT / SHINY_TOGGLE_ICON_FILE, output_dir / SHINY_TOGGLE_ICON_FILE)
            if path.exists()
        ),
        None,
    )
    if source is None:
        return None
    output_dir.mkdir(parents=True, exist_ok=True)
    target = output_dir / SHINY_TOGGLE_ICON_FILE
    if source.resolve() == target.resolve():
        return str(target.relative_to(OUT_DIR))
    resample = getattr(Image, "Resampling", Image).LANCZOS
    image = Image.open(source).convert("RGBA")
    image = image.resize(SHINY_TOGGLE_ICON_SIZE, resample)
    image.save(target)
    return str(target.relative_to(OUT_DIR))

def copy_item_icon(item: ItemRecord | None, item_icon_dir: Path) -> str | None:
    if not item:
        return None
    icon_stems = [
        item["constant"].removeprefix("ITEM_").lower(),
        asset_stem(item.get("iconName", "")),
    ]
    source = next(
        (
            REPO_ROOT / "graphics" / "items" / "icons" / f"{stem}.png"
            for stem in icon_stems
            if stem and (REPO_ROOT / "graphics" / "items" / "icons" / f"{stem}.png").exists()
        ),
        None,
    )
    if source is None:
        return None
    target = item_icon_dir / source.name
    target.parent.mkdir(parents=True, exist_ok=True)
    image = Image.open(source)
    rgba = image.convert("RGBA")
    if image.mode == "P":
        transparent_indices = {image.getpixel((0, 0))}
        transparency = image.info.get("transparency")
        if isinstance(transparency, int):
            transparent_indices.add(transparency)
        elif isinstance(transparency, bytes):
            transparent_indices.update(index for index, alpha in enumerate(transparency) if alpha == 0)
        pixels = [
            (*pixel[:3], 0) if image.getpixel((x, y)) in transparent_indices else pixel
            for y in range(image.height)
            for x, pixel in ((x, rgba.getpixel((x, y))) for x in range(image.width))
        ]
        rgba.putdata(pixels)
    rgba.save(target)
    return str(target.relative_to(OUT_DIR))

def parse_trainer_front_pic_sources() -> dict[str, Path]:
    sources: dict[str, Path] = {}
    for path in sorted(TRAINER_FRONT_PIC_DIR.glob("*.png")):
        sources[normalize_token(path.stem)] = path
    return sources
