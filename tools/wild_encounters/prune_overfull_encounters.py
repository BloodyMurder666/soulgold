#!/usr/bin/env python3
import argparse
import json
from pathlib import Path


def load_slot_limits(data):
    slot_limits = {}
    for group in data["wild_encounter_groups"]:
        for field in group.get("fields", []):
            slot_limits[field["type"]] = len(field["encounter_rates"])
    return slot_limits


def trim_mons(mons, max_slots):
    return mons[:max_slots]


def main():
    parser = argparse.ArgumentParser(
        description="Trim overfull wild encounter lists down to their slot limit."
    )
    parser.add_argument(
        "json_path",
        nargs="?",
        default="src/data/wild_encounters.json",
        help="Path to the wild encounter JSON file",
    )
    parser.add_argument(
        "--write",
        action="store_true",
        help="Write the pruned JSON back to disk",
    )
    parser.add_argument(
        "--mon-type",
        default="water_mons",
        help="Encounter type to prune (default: water_mons)",
    )
    args = parser.parse_args()

    json_path = Path(args.json_path)
    data = json.loads(json_path.read_text())
    slot_limits = load_slot_limits(data)

    changes = []
    for group in data["wild_encounter_groups"]:
        for encounter in group.get("encounters", []):
            mon_type = args.mon_type
            max_slots = slot_limits[mon_type]
            mons_entry = encounter.get(mon_type)
            if not isinstance(mons_entry, dict):
                continue
            mons = mons_entry.get("mons", [])
            if len(mons) <= max_slots:
                continue
            pruned = trim_mons(mons, max_slots)
            if len(pruned) > max_slots:
                raise ValueError(
                    f"{encounter['base_label']}.{mon_type} still has {len(pruned)} entries after pruning"
                )
            changes.append(
                (
                    encounter["base_label"],
                    mon_type,
                    len(mons),
                    len(pruned),
                )
            )
            mons_entry["mons"] = pruned

    if not changes:
        print("No overfull encounter lists found.")
        return

    for base_label, mon_type, before, after in changes:
        print(f"{base_label}.{mon_type}: {before} -> {after}")

    if args.write:
        json_path.write_text(json.dumps(data, indent=2) + "\n")


if __name__ == "__main__":
    main()
