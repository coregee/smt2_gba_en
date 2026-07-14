"""One-off (2026-06-11): find system_menu entries that are sentinel'd (0xFFFF) in the
built ROM and locate every JP-ROM pointer reference to them. A sentinel is only
resolved by the BattleMenu_SetMode entry hook; a string read via a menu-record slot
by any other drawer renders the raw sentinel as garbage ('not seeing save/load
messages'). Output: which entries are at risk + their candidate repoint slots."""
import json
import struct

try:
    from ._boot import BUILD, CORPUS, ROM
except ImportError:
    from _boot import BUILD, CORPUS, ROM

jp = ROM.read_bytes()
en = (BUILD / "smt2-en.gba").read_bytes()

entries = json.loads((CORPUS / "system_menu.json").read_text(encoding="utf-8"))

# index all aligned u32s in the JP ROM
targets = {}
for e in entries:
    a = int(e["addr"], 16)
    if struct.unpack_from("<H", en, a - 0x08000000)[0] == 0xFFFF:
        targets[a] = e

refs = {}
for off in range(0, len(jp) - 3, 2):       # 2-aligned: menu records may be halfword-packed
    v = struct.unpack_from("<I", jp, off)[0]
    if v in targets:
        refs.setdefault(v, []).append(off + 0x08000000)

print(f"{len(targets)} sentinel'd system_menu entries")
for a, e in sorted(targets.items()):
    r = refs.get(a, [])
    print(f"{a:08X} refs={[hex(x) for x in r]}  {e['original'][:28]!r} -> {e['replace'][:36]!r}")
