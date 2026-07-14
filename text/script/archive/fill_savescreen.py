"""One-off (2026-06-11): translations for config_help + save_screen sections.
Validates encode + inline budgets for the slot-less (walk-reached) entries."""
import json
import sys

try:
    from . import _boot  # noqa: F401
except ImportError:
    import _boot  # noqa: F401

from text.script import tr

CONFIG = {  # keyed by first addr
    "084F1A40": "Display messages at{n}normal speed",
    "084F1A66": "Display messages with{n}no text delay",
    "084F1AE4": "Show attack effects",
    "084F1B00": "Turn attack effect{n}display off",
    "084F1B28": "Repeat the last action{n}(sword/gun/attack only)",
    "084F1B58": "Repeat the last action;{n}attack when out of items/MP",
    "084F1B96": "Repeat the last action;{n}defend when out of items/MP",
    "084F1BD0": "Keep north at the{n}top of the screen",
    "084F1BF0": "The map rotates to{n}face your direction",
    "084F1C0E": "Auto-heal using items",
    "084F1C32": "Auto-heal using{n}magic only",
    "084F1C56": "Exit CONFIG and return{n}to the system menu",
    "084F1C90": "Exit CONFIG and return{n}to the title screen",
    "084F1CC2": "Optimize colors for the{n}Game Boy Advance",
    "084F1CF4": "Optimize colors for the{n}Game Boy Advance SP",
    "084F1D2A": "Optimize colors for the{n}Game Boy Player",
}

SAVE = {
    "084F1DDC": "Choose a file to save to",
    "084F1E02": "Choose a file to load",
    "084F1E28": "Save complete",
    "084F1E3E": "Power off and rest…{n}Don't let demons{n}take your body…",
    "084F1EA8": "This file already has data{n}Overwriting will erase it{n}Are you sure?",
    "084F1F0E": "Pause?",
    "084F1F20": " has suspend data{n}Overwrite it?",
    "084F1F7C": "Load File 1?{n}Are you sure?",
    "084F1FA8": "Load File 2?{n}Are you sure?",
    "084F1FD4": "Load File 3?{n}Are you sure?",
    "084F2000": "Resuming erases the suspend{n}data. Are you sure?",
    "084F2036": "Continue?",
    "084F204C": "Make a suspend save?",
    "084F2062": "Save failed",
    "084F2078": "Load failed",
    "084F208E": "Save complete",
}

errors = []
for fname, table in (("config_help", CONFIG), ("save_screen", SAVE)):
    path = tr.TR / f"{fname}.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    used = set()
    for e in data:
        key = e.get("addr") or e["addrs"][0]
        en = table.get(key)
        if en is None:
            errors.append(f"{fname} {key}: no translation authored")
            continue
        used.add(key)
        try:
            blob = tr.encode(en)
        except ValueError as ex:
            errors.append(f"{fname} {key} {en!r}: {ex}")
            continue
        # slot-less entries must fit the inline budget (max tokens + terminator)
        if not e.get("ptrs") and len(blob) // 2 > e["max"]:
            errors.append(f"{fname} {key} {en!r}: {len(blob)//2} tokens > inline "
                          f"budget {e['max']} (no slots to repoint)")
            continue
        e["replace"] = en
    for k in set(table) - used:
        errors.append(f"{fname}: authored {k} matches no entry")
    if not errors:
        path.write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding="utf-8")
        print(f"{fname}: {len(used)}/{len(data)} translated")
if errors:
    print("ERRORS:")
    for x in errors:
        print(" ", x)
    sys.exit(1)
