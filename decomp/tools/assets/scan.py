#!/usr/bin/env python3
"""Map the ROM's data: every 4-aligned offset outside code that holds a valid BIOS-compressed
stream, and every word that points into ROM data.  Writes build/datamap.json."""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parent))
import bios  # noqa: E402

ROOT = HERE.parents[1]
BASE = 0x08000000


def main():
    rom = (ROOT / "baserom.gba").read_bytes()
    t = json.loads((ROOT / "build" / "trace.json").read_text())
    code = set()
    lits = {}
    for f in t["functions"]:
        for a, n in f["insns"]:
            code.update(range(a, a + n))
        for l in f["literals"]:
            lits[l] = f["addr"]
    # Every pointer to ROM held in literal pools (code references) and in data (tables).
    code_refs = {}
    for l, fn in lits.items():
        v = struct.unpack_from("<I", rom, l - BASE)[0]
        if BASE <= v < BASE + len(rom) and v not in code:
            code_refs.setdefault(v, []).append(fn)
    data_refs = {}
    for o in range(0, len(rom) - 3, 4):
        a = BASE + o
        if a in code or a in lits:
            continue
        v = struct.unpack_from("<I", rom, o)[0]
        if BASE + 0x200 <= v < BASE + len(rom) and (v & ~1) not in code:
            data_refs.setdefault(v, []).append(a)
    streams = []
    o = 0x200
    while o < len(rom) - 4:
        a = BASE + o
        if a in code or rom[o] not in bios.DECODERS or (a not in code_refs and a not in data_refs):
            o += 4
            continue
        r = bios.decode(rom, o)
        if r and (a in code_refs or a in data_refs) and r[1] >= 8:
            streams.append({"addr": a, "type": rom[o], "size": len(r[0]), "clen": r[1],
                            "code_refs": code_refs.get(a, []), "data_refs": data_refs.get(a, [])[:8]})
            o += (r[1] + 3) & ~3
            continue
        o += 4
    out = {"streams": streams,
           "code_refs": {f"{k:08X}": v for k, v in sorted(code_refs.items())},
           "n_data_refs": len(data_refs)}
    (ROOT / "build" / "datamap.json").write_text(json.dumps(out))
    tot = sum(s["clen"] for s in streams)
    from collections import Counter
    print(len(streams), "referenced compressed streams,", hex(tot), "bytes;",
          Counter(hex(s["type"]) for s in streams))
    print(len(code_refs), "data addresses referenced by code;", len(data_refs), "by data")


if __name__ == "__main__":
    main()
