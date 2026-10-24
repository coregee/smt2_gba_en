#!/usr/bin/env python3
"""Static census of asset loads: for every call to a BIOS decompressor or CpuSet/CpuFastSet,
the constant source (r0) and destination (r1) set up by straight-line code before the call.
Classifies ROM data by where the game puts it (BG/OBJ VRAM, palette RAM, buffers)."""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[2]
LOADERS = {0x0815CB00: "LZ77UnCompWram", 0x0815CAFC: "HuffUnComp", 0x0815CB08: "RLUnCompWram",
           0x0815CAF8: "CpuSet", 0x0815CAF4: "CpuFastSet"}


def region(v):
    if v is None:
        return "?"
    if 0x05000000 <= v < 0x05000200:
        return "BG_PLTT"
    if 0x05000200 <= v < 0x05000400:
        return "OBJ_PLTT"
    if 0x06000000 <= v < 0x06010000:
        return "BG_VRAM"
    if 0x06010000 <= v < 0x06018000:
        return "OBJ_VRAM"
    if 0x02000000 <= v < 0x02040000:
        return "EWRAM"
    if 0x03000000 <= v < 0x03008000:
        return "IWRAM"
    if 0x08000000 <= v < 0x08800000:
        return "ROM"
    return "other"


def main():
    rom = (ROOT / "baserom.gba").read_bytes()
    t = json.loads((ROOT / "build" / "trace.json").read_text())
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
    md.detail = True
    rows = []
    for f in t["functions"]:
        if f["mode"] != "thumb":
            continue
        insns = dict(f["insns"])
        for site, tgt, _ in f["calls"]:
            if tgt not in LOADERS:
                continue
            regs = {}
            # Walk back up to 16 instructions of straight-line code.
            back = []
            a = site
            for _ in range(16):
                p = a - 2
                if p in insns and insns[p] == 2:
                    a = p
                elif a - 4 in insns and insns[a - 4] == 4:
                    break                                   # previous call clobbers r0-r3
                else:
                    break
                back.append(a)
            for a in reversed(back):
                o = a - 0x08000000
                ins = next(md.disasm(rom[o:o + 2], a))
                h = rom[o] | rom[o + 1] << 8
                _, wr = ins.regs_access()
                if h >> 11 == 0b01001:
                    lit = ((a + 4) & ~3) + (h & 0xFF) * 4
                    regs[(h >> 8) & 7] = struct.unpack_from("<I", rom, lit - 0x08000000)[0]
                elif h >> 11 == 0b00100:                    # movs rd, #imm
                    regs[(h >> 8) & 7] = h & 0xFF
                elif h >> 6 == 0b0001110000 and False:
                    pass
                elif ins.mnemonic in ("adds", "add") and ins.op_str.endswith(", #0") and len(ins.operands) == 3:
                    src = ins.operands[1].reg
                    rs = int(ins.reg_name(src)[1:]) if ins.reg_name(src)[1:].isdigit() else None
                    rd = int(ins.reg_name(ins.operands[0].reg)[1:])
                    regs[rd] = regs.get(rs) if rs is not None else None
                else:
                    for w in wr:
                        n = ins.reg_name(w)
                        if n[1:].isdigit() and n[0] == "r":
                            regs[int(n[1:])] = None
            src, dst, cnt = regs.get(0), regs.get(1), regs.get(2)
            rows.append({"func": f["addr"], "site": site, "call": LOADERS[tgt],
                         "src": src, "dst": dst, "count": cnt})
    (ROOT / "build" / "loads.json").write_text(json.dumps(rows))
    summ = defaultdict(int)
    for r in rows:
        summ[(r["call"], region(r["src"]), region(r["dst"]))] += 1
    for k, v in sorted(summ.items(), key=lambda kv: -kv[1]):
        print(f"{v:4d}  {k[0]:15s} {k[1]:8s} -> {k[2]}")


if __name__ == "__main__":
    main()
