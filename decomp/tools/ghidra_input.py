#!/usr/bin/env python3
"""Flatten the trace + symbol table into build/ghidra_input.tsv for SetupFromTrace.java.

Lines:  F addr mode name | I addr size mode | L addr | J dispatch_site case... |
        X site target (far jump: bl that is a branch) | N site (bl that never returns)
        D addr name (data/RAM label)"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from symbols import Symbols  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def main():
    t = json.loads((ROOT / "build" / "trace.json").read_text())
    syms = Symbols.load(ROOT / "reference" / "symbols.tsv")
    rom = (ROOT / "baserom.gba").read_bytes()
    out = []
    for f in t["functions"]:
        a = f["addr"]
        other = set(f["other_mode"])
        name = syms.name(a) or (f"sub_{a:08X}" if f["mode"] == "thumb" else f"arm_{a:08X}")
        out.append(f"F\t{a:08X}\t{f['mode']}\t{name}")
        for i, n in f["insns"]:
            m = f["mode"] if i not in other else ("arm" if f["mode"] == "thumb" else "thumb")
            out.append(f"I\t{i:08X}\t{n}\t{m}")
        for l in f["literals"]:
            out.append(f"L\t{l:08X}")
        for tb, n, site in f["jumptables"]:
            cases = [int.from_bytes(rom[tb - 0x08000000 + 4 * k:tb - 0x08000000 + 4 * k + 4],
                                    "little") for k in range(n)]
            out.append(f"J\t{site:08X}\t{tb:08X}\t" + "\t".join(f"{c:08X}" for c in cases))
        for s, tg in f["farjumps"]:
            out.append(f"X\t{s:08X}\t{tg:08X}")
        for s in f["noreturn"]:
            out.append(f"N\t{s:08X}")
    for s in syms.by_addr.values():
        if s.kind != "func":
            out.append(f"D\t{s.addr:08X}\t{s.name}")
    p = ROOT / "build" / "ghidra_input.tsv"
    p.write_text("\n".join(out) + "\n")
    print(p, len(out))


if __name__ == "__main__":
    main()
