import argparse
import re
from pathlib import Path

OLD_SECONDARY_START = 0x280
OLD_TOTAL = 0x400
SHIFT = 0x180

HEX_RE = re.compile(r"(?<![A-Za-z0-9_])0x([0-9A-Fa-f]+)\b")


def should_process_line(line, include_scripts):
    if line.lstrip().startswith("#define METATILE_"):
        return True
    if include_scripts and "setmetatile" in line:
        return True
    return False


def shift_hex_literal(match):
    value = int(match.group(1), 16)
    if OLD_SECONDARY_START <= value < OLD_TOTAL:
        return f"0x{value + SHIFT:X}"
    return match.group(0)


def process_text(text, include_scripts):
    changed = 0
    out_lines = []

    for line in text.splitlines(keepends=True):
        if should_process_line(line, include_scripts):
            new_line = HEX_RE.sub(shift_hex_literal, line)
            if new_line != line:
                changed += 1
            out_lines.append(new_line)
        else:
            out_lines.append(line)

    return "".join(out_lines), changed


def process_file(path, include_scripts, write):
    text = path.read_text()
    new_text, changed = process_text(text, include_scripts)

    if changed and write:
        path.write_text(new_text)

    return changed


def main():
    parser = argparse.ArgumentParser(
        description="Shift old FRLG secondary metatile IDs by +0x180 for the 2048-metatile map format."
    )
    parser.add_argument(
        "paths",
        nargs="*",
        type=Path,
        default=[Path("include/constants/metatile_labels.h")],
        help="Files to scan. Defaults to include/constants/metatile_labels.h.",
    )
    parser.add_argument(
        "--scripts",
        action="store_true",
        help="Also update numeric IDs on setmetatile script lines.",
    )
    parser.add_argument(
        "--write",
        action="store_true",
        help="Write changes. Without this, only reports what would change.",
    )
    args = parser.parse_args()

    total = 0
    for path in args.paths:
        changed = process_file(path, args.scripts, args.write)
        total += changed
        if changed:
            action = "Updated" if args.write else "Would update"
            print(f"{action} {changed} line(s): {path}")

    if not total:
        print("No matching old secondary metatile IDs found.")
    elif not args.write:
        print("Dry run only. Re-run with --write to modify files.")


if __name__ == "__main__":
    main()
