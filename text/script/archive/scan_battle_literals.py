"""One-off (2026-06-11): find battle.json template strings whose address ALSO appears
as a 4-aligned u32 literal outside BATTLE_MSG_TABLE — those sites bypass the table
repoint and still draw JP (found via FUN_0812b57c / 0x08124CC8)."""
import json
import struct

try:
    from ._boot import CORPUS, ROM
except ImportError:
    from _boot import CORPUS, ROM

rom = ROM.read_bytes()

TABLE_LO = 0x0876FB54 - 0x08000000
TABLE_HI = TABLE_LO + 0x3C0 * 4

entries = json.loads((CORPUS / "battle.json").read_text(encoding="utf-8"))
addr2ids = {int(e["addr"], 16): e["ids"] for e in entries}

# index every aligned u32 in ROM
hits = {}
for off in range(0, len(rom) - 3, 4):
    v = struct.unpack_from("<I", rom, off)[0]
    if v in addr2ids and not (TABLE_LO <= off < TABLE_HI):
        hits.setdefault(v, []).append(off + 0x08000000)

for v in sorted(hits):
    e = next(e for e in entries if int(e["addr"], 16) == v)
    print(f"{v:08X} ids={e['ids']} slots={[hex(s) for s in hits[v]]} "
          f"orig={e['original'][:32]!r}")
print(f"\n{len(hits)} strings with out-of-table literal refs")
