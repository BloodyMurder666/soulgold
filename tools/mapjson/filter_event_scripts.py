#!/usr/bin/env python3

import argparse
import json
import re
from pathlib import Path


MAP_SCRIPT_INCLUDE = re.compile(
    r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"\s*$'
)


def main():
    parser = argparse.ArgumentParser(
        description="Remove ROM-excluded map script includes from event_scripts.s."
    )
    parser.add_argument("source", type=Path)
    parser.add_argument("map_groups", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    with args.map_groups.open(encoding="utf-8") as groups_file:
        groups = json.load(groups_file)

    excluded_groups = set(groups.get("rom_excluded_groups", []))
    shared_script_maps = set(groups.get("rom_shared_script_maps", []))
    excluded_maps = {
        map_name
        for group_name in excluded_groups
        for map_name in groups.get(group_name, [])
    }

    unknown_shared_maps = shared_script_maps - excluded_maps
    if unknown_shared_maps:
        parser.error(
            "rom_shared_script_maps contains maps outside excluded groups: "
            + ", ".join(sorted(unknown_shared_maps))
        )

    output_lines = []
    for line in args.source.read_text(encoding="utf-8").splitlines(keepends=True):
        match = MAP_SCRIPT_INCLUDE.match(line)
        if match:
            map_name = match.group(1)
            if map_name in excluded_maps and map_name not in shared_script_maps:
                continue
        output_lines.append(line)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("".join(output_lines), encoding="utf-8")


if __name__ == "__main__":
    main()
