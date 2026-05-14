import os
import struct

OLD_METATILE_MASK  = 0b0000001111111111
OLD_COLLISION_MASK = 0b0000110000000000
OLD_ELEVATION_MASK = 0b1111000000000000

NEW_METATILE_MASK  = 0b0000011111111111
NEW_COLLISION_MASK = 0b0001
NEW_ELEVATION_MASK = 0b1111

OLD_METATILES_IN_PRIMARY = 640
NEW_METATILES_IN_PRIMARY = 1024
METATILE_OFFSET = NEW_METATILES_IN_PRIMARY - OLD_METATILES_IN_PRIMARY

def convert_metatile_id(metatile_id):
    if metatile_id >= OLD_METATILES_IN_PRIMARY:
        return metatile_id + METATILE_OFFSET
    return metatile_id

def process_map_data(old_data):
    new_data = []

    for value in old_data:
        metatile_id = value & OLD_METATILE_MASK
        collision = (value & OLD_COLLISION_MASK) >> 10
        elevation = (value & OLD_ELEVATION_MASK) >> 12

        metatile_id = convert_metatile_id(metatile_id)

        collision = 1 if collision else 0
        new_value = metatile_id | ((collision & NEW_COLLISION_MASK) << 11) | ((elevation & NEW_ELEVATION_MASK) << 12)
        new_data.append(new_value)
    return new_data

def process_border_data(old_data):
    new_data = []
    for value in old_data:
        metatile_id = value & OLD_METATILE_MASK

        metatile_id = convert_metatile_id(metatile_id)

        new_data.append(metatile_id)
    return new_data

def read_map_bin(file_path):
    with open(file_path, "rb") as f:
        data = f.read()
        return list(struct.unpack("<" + "H" * (len(data) // 2), data))

def write_map_bin(file_path, new_data):
    with open(file_path, "wb") as f:
        f.write(struct.pack("<" + "H" * len(new_data), *new_data))

def find_map_files(file_name="map.bin"):
    map_files = []
    for root, dirs, files in os.walk("data/layouts"):
        for file in files:
            if file == file_name:
                map_files.append(os.path.join(root, file))
    return map_files

def process_all_maps():
    map_files = find_map_files("map.bin")
    for map_file in map_files:
        print(f"Processing {map_file}...")
        old_data = read_map_bin(map_file)
        new_data = process_map_data(old_data)
        write_map_bin(map_file, new_data)

def process_all_borders():
    map_files = find_map_files("border.bin")
    for map_file in map_files:
        print(f"Processing {map_file}...")
        old_data = read_map_bin(map_file)
        new_data = process_border_data(old_data)
        write_map_bin(map_file, new_data)

if __name__ == "__main__":
    process_all_maps()
    process_all_borders()
