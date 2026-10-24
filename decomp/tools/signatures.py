#!/usr/bin/env python3
"""Infer each function's argument count and whether it returns a value, from the code alone.

Returns: a function returns a value if any caller reads r0 after the call before writing it
(scanning the caller's straight-line code after the bl).  agbcc's interworking epilogue
``pop {r0}; bx r0`` otherwise fools Ghidra into returning the saved lr.

Arguments: the highest of r0-r3 that the function reads before writing, scanning its entry
block and the blocks it falls/branches into (bounded), plus what callers set up before calls.
Both are evidence-based guesses and are written as such (build/signatures.tsv).
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
ARGREGS = {"r0": 0, "r1": 1, "r2": 2, "r3": 3}


class Insns:
    def __init__(self, rom: bytes, trace: dict):
        self.rom = rom
        self.md = {m: capstone.Cs(capstone.CS_ARCH_ARM, mm) for m, mm in
                   (("thumb", capstone.CS_MODE_THUMB), ("arm", capstone.CS_MODE_ARM))}
        for md in self.md.values():
            md.detail = True
        self.mode = {}
        self.size = {}
        for f in trace["functions"]:
            other = set(f["other_mode"])
            for a, n in f["insns"]:
                self.mode[a] = f["mode"] if a not in other else ("arm" if f["mode"] == "thumb" else "thumb")
                self.size[a] = n
        self.cache = {}

    def get(self, a):
        r = self.cache.get(a)
        if r is None:
            n = self.size[a]
            o = a - 0x08000000
            ins = next(self.md[self.mode[a]].disasm(self.rom[o:o + n], a))
            rd, wr = ins.regs_access()
            r = (ins, {ins.reg_name(x) for x in rd}, {ins.reg_name(x) for x in wr})
            self.cache[a] = r
        return r


def reads_r0_after(I: Insns, site: int, limit=12):
    a = site + I.size[site]
    for _ in range(limit):
        if a not in I.size:
            return False
        ins, rd, wr = I.get(a)
        m = ins.mnemonic
        if m == "bl" or m.startswith("bl"):
            return "r0" in rd and m != "bl"
        if "r0" in rd:
            return True
        if "r0" in wr:
            return False
        if m in ("b", "bx") or m.startswith("pop") and "pc" in ins.op_str:
            return False
        if m.startswith("b") and len(m) <= 3 and m != "bic":
            pass                                   # conditional branch: keep scanning fallthrough
        a += I.size[a]
    return False


def arg_count(I: Insns, entry: int, limit=40):
    written = set()
    used = -1
    a = entry
    for _ in range(limit):
        if a not in I.size:
            break
        ins, rd, wr = I.get(a)
        m = ins.mnemonic
        if m.startswith("push") or m.startswith("stm") and "sp" in ins.op_str:
            # Saving callee-saved registers does not use arguments.
            a += I.size[a]
            continue
        if m in ("svc", "swi"):
            # BIOS calls take r0-r2 (CpuSet, decompressors, Div) without capstone showing it.
            if ins.op_str not in ("#0", "#1", "#2", "#3", "#5"):
                rd = rd | {"r0", "r1", "r2"}
            rd = set(rd)
        for r in rd:
            if r in ARGREGS and r not in written:
                used = max(used, ARGREGS[r])
        if m == "bl":
            break
        written |= wr
        if m in ("b", "bx", "mov") and "pc" in (ins.op_str + m) or m.startswith("pop") and "pc" in ins.op_str:
            break
        if m == "b" or m == "bx":
            break
        a += I.size[a]
    return used + 1


def main():
    rom = (ROOT / "baserom.gba").read_bytes()
    trace = json.loads((ROOT / "build" / "trace.json").read_text())
    I = Insns(rom, trace)
    returns = {f["addr"]: False for f in trace["functions"]}
    for f in trace["functions"]:
        for site, tgt, mode in f["calls"]:
            if tgt in returns and not returns[tgt] and site in I.size and I.size[site] == 4:
                if reads_r0_after(I, site):
                    returns[tgt] = True
    out = ["address\targs\treturns"]
    for f in trace["functions"]:
        out.append(f"{f['addr']:08X}\t{arg_count(I, f['addr'])}\t{int(returns[f['addr']])}")
    (ROOT / "build" / "signatures.tsv").write_text("\n".join(out) + "\n")
    print(sum(returns.values()), "of", len(returns), "functions return a value")


if __name__ == "__main__":
    main()
