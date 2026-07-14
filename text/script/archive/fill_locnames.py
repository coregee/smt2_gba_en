"""One-off (2026-06-11): feed the parked location-name translations into
text/corpus/location_names.json (cells 0-444 came from the untracked historical
location-names-en.txt review file,
cells 445-529 = the table tail beyond the old story-walk capture, translated here).
Validates every name encodes and fits the 16-token cell before writing."""
import json
import sys

try:
    from ._boot import REVIEW
except ImportError:
    from _boot import REVIEW

from text.script import tr
BASE = 0x080A548C
STRIDE = 0x20

parked = (REVIEW / "location-names-en.txt").read_text(encoding="utf-8").splitlines()
names = {}                       # cell index -> EN
for i, line in enumerate(parked[8:]):          # line 9 (idx 8) = cell 0
    if line.strip():
        names[i] = line.strip()

TAIL = {
    445: "Chokmah Tower 3F", 446: "Chokmah Tower 3F",
    444: "Chokmah Tower 4F",                     # parked blank: capture truncation only
    447: "Chokmah Tower 4F", 448: "Chokmah Tower 4F",
    452: "Hyperspace", 456: "Hyperspace", 460: "Hyperspace", 464: "Hyperspace",
    461: "Ark 4F",
    473: "Old Ichigaya B1", 474: "Old Ichigaya B1",
    475: "Old T.Tower 1F", 476: "Old T.Tower 45F",
    477: "Old Ichigaya 1F", 478: "Old Ichigaya 1F",
    479: "Old T.Tower 30F", 480: "Old T.Tower 30F",
    486: "Old Gov Bldg 1F",
    513: "Valhalla", 514: "Center", 515: "Holytown", 516: "Factory",
    517: "Arcadia", 518: "Underworld", 519: "Eden",
}
for i in (449, 450, 451, 453, 454, 455, 457, 458, 459):
    TAIL[i] = "Ark 1F"
for i in (465, 466, 469, 470):
    TAIL[i] = "Ark 2F"
for i in (467, 468, 471, 472):
    TAIL[i] = "Ark 3F"
for i in (481, 482, 483, 484, 485, 488):
    TAIL[i] = "Old Gov Bldg 15F"
for i in (487, 490, 491, 494, 495):
    TAIL[i] = "Old Imp. Palace"
for i in (489, 492, 493, 496):
    TAIL[i] = "Old Gov Bldg 18F"
for i in range(497, 513):
    TAIL[i] = "Diamond Realm"
MAKAI = ["Kether", "Binah", "Chokmah", "Geburah", "Chesed", "Tiphereth",
         "Hod", "Netzach", "Yesod", "Malkuth"]
for i, m in enumerate(MAKAI):
    TAIL[520 + i] = f"Makai: {m}"
names.update(TAIL)

path = tr.TR / "location_names.json"
data = json.loads(path.read_text(encoding="utf-8"))
by_addr = {e["addr"]: e for e in data}

errors, applied = [], 0
for cell, en in sorted(names.items()):
    addr = f"{BASE + cell * STRIDE:08X}"
    e = by_addr.get(addr)
    if e is None:
        errors.append(f"cell {cell} ({en!r}): no entry @{addr} (blank JP cell?)")
        continue
    try:
        blob = tr.encode(en)
    except ValueError as ex:
        errors.append(f"cell {cell} {en!r}: {ex}")
        continue
    if len(blob) // 2 > e["max"]:
        errors.append(f"cell {cell} {en!r}: {len(blob)//2} tokens > {e['max']}")
        continue
    e["replace"] = en
    applied += 1

# any non-blank JP cell left untranslated?
missing = [f'{e["addr"]} {e["original"]}' for e in data if not e.get("replace")]

if errors:
    print("ERRORS:")
    for x in errors:
        print(" ", x)
    sys.exit(1)
path.write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding="utf-8")
print(f"applied {applied} / {len(data)} entries")
if missing:
    print("still untranslated (unexpected):")
    for x in missing:
        print(" ", x)
