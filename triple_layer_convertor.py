import argparse
import os
import struct


OLD_METATILE_SIZE = 16

FORMATS = {
    "emerald": {
        "description": "pokeemerald/RSE-style 2-byte metatile attributes",
        "attr_size": 2,
        "attr_unpack": "<H",
        "attr_pack_type": "H",
        "layer_type_mask": 0xF000,
        "layer_type_shift": 12,
    },
    "frlg": {
        "description": "pokefirered/FRLG-style 4-byte metatile attributes",
        "attr_size": 4,
        "attr_unpack": "<I",
        "attr_pack_type": "I",
        "layer_type_mask": 0x60000000,
        "layer_type_shift": 29,
    },
}


def get_tileset_dirs(tsroot):
    tileset_dirs = []

    for subdir in ("primary", "secondary"):
        path = os.path.join(tsroot, subdir)
        if not os.path.exists(path):
            print(f"[ERR] Given tilesets root directory does not contain a {subdir} folder, aborting.")
            exit(1)

        _, dirs, _ = next(os.walk(path))
        tileset_dirs += [os.path.join(path, d) for d in dirs]

    return tileset_dirs


def detect_format(metatiles_size, attributes_size, requested_format):
    if requested_format != "auto":
        fmt = FORMATS[requested_format]
        if attributes_size % fmt["attr_size"] != 0:
            return None
        if metatiles_size == OLD_METATILE_SIZE * (attributes_size // fmt["attr_size"]):
            return requested_format
        return None

    matches = []
    for format_name, fmt in FORMATS.items():
        if attributes_size % fmt["attr_size"] != 0:
            continue
        metatile_count = attributes_size // fmt["attr_size"]
        if metatiles_size == OLD_METATILE_SIZE * metatile_count:
            matches.append(format_name)

    if len(matches) == 1:
        return matches[0]

    return None


def read_attributes(path, fmt):
    attributes = []
    layer_types = []
    layer_clear_mask = 0xFFFFFFFF ^ fmt["layer_type_mask"]

    with open(path, "rb") as fileobj:
        for chunk in iter(lambda: fileobj.read(fmt["attr_size"]), b""):
            if len(chunk) != fmt["attr_size"]:
                raise ValueError(f"{path} is not aligned to {fmt['attr_size']}-byte attributes")
            metatile_attribute = struct.unpack(fmt["attr_unpack"], chunk)[0]
            attributes.append(metatile_attribute & layer_clear_mask)
            layer_types.append((metatile_attribute & fmt["layer_type_mask"]) >> fmt["layer_type_shift"])

    return attributes, layer_types


def convert_metatiles(path, layer_types):
    i = 0
    new_metatile_data = []

    with open(path, "rb") as fileobj:
        for chunk in iter(lambda: fileobj.read(OLD_METATILE_SIZE), b""):
            if len(chunk) != OLD_METATILE_SIZE:
                raise ValueError(f"{path} is not aligned to {OLD_METATILE_SIZE}-byte metatiles")
            metatile_data = struct.unpack("<HHHHHHHH", chunk)
            if layer_types[i] == 0:
                new_metatile_data += [0] * 4
                new_metatile_data += metatile_data
            elif layer_types[i] == 1:
                new_metatile_data += metatile_data
                new_metatile_data += [0] * 4
            elif layer_types[i] == 2:
                new_metatile_data += metatile_data[:4]
                new_metatile_data += [0] * 4
                new_metatile_data += metatile_data[4:]
            else:
                new_metatile_data += [0] * 12
            i += 1

    return struct.pack(f"<{len(new_metatile_data)}H", *new_metatile_data)


def convert_tileset(tileset_dir, requested_format):
    tileset_name = os.path.basename(tileset_dir)
    metatiles_path = os.path.join(tileset_dir, "metatiles.bin")
    metatile_attributes_path = os.path.join(tileset_dir, "metatile_attributes.bin")

    if not os.path.exists(metatiles_path):
        print(f"[SKIP] {tileset_name} skipped because metatiles.bin was not found.")
        return
    if not os.path.exists(metatile_attributes_path):
        print(f"[SKIP] {tileset_name} skipped because metatile_attributes.bin was not found.")
        return

    metatiles_size = os.path.getsize(metatiles_path)
    attributes_size = os.path.getsize(metatile_attributes_path)
    format_name = detect_format(metatiles_size, attributes_size, requested_format)
    if format_name is None:
        print(
            f"[SKIP] {tileset_name} skipped because its file sizes do not match an unconverted "
            f"{requested_format} tileset (already converted?)"
        )
        return

    fmt = FORMATS[format_name]
    attributes, layer_types = read_attributes(metatile_attributes_path, fmt)
    metatile_count = metatiles_size // OLD_METATILE_SIZE
    if metatile_count != len(layer_types):
        raise ValueError(
            f"{tileset_name} has {metatile_count} metatiles but {len(layer_types)} metatile attributes"
        )

    metatile_buffer = convert_metatiles(metatiles_path, layer_types)
    metatile_attribute_buffer = struct.pack(f"<{len(attributes)}{fmt['attr_pack_type']}", *attributes)

    with open(metatiles_path, "wb") as fileobj:
        fileobj.write(metatile_buffer)
    with open(metatile_attributes_path, "wb") as fileobj:
        fileobj.write(metatile_attribute_buffer)

    print(f"[OK] Converted {tileset_name} as {format_name}")


parser = argparse.ArgumentParser(description="Convert metatiles to use the triple layer system.")
parser.add_argument(
    "--tsroot",
    required=True,
    help="Path to the tilesets directory, e.g. /path/to/project/data/tilesets",
)
parser.add_argument(
    "--format",
    choices=("auto", "emerald", "frlg"),
    default="auto",
    help="Metatile attribute format to convert. Default: auto-detect per tileset.",
)

args = parser.parse_args()

if not os.path.exists(args.tsroot):
    print(f"Given tilesets root directory does not exist: {args.tsroot}")
    exit(1)

for tileset_dir in get_tileset_dirs(args.tsroot):
    convert_tileset(tileset_dir, args.format)
