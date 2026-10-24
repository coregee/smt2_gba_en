#!/usr/bin/env python3
"""Audit the English translation's binary patches against the recovered program.

Runs the translation build in memory (engine build_patcher + tr.pack; nothing is written),
diffs the result against the base ROM, and checks every changed byte range that touches code:

  E-MIDINSN    a changed range starts or ends inside an instruction (or splits a bl pair)
  E-ENTERED    code outside the range branches (b/bcc/bl far jump/switch case) into the
               middle of rewritten bytes, so that path now executes half-patched code
  E-ARM        Thumb-style bytes written into ARM code
  E-BLTARGET   a new bl/b in rewritten code targets the middle of an original function
               (not an entry, not a cave, not a branch target of its own function)
  W-DISPLACED  an original instruction overwritten by a hook does not reappear in the cave the
               hook calls (it may have been dropped; review by hand)
  W-LITERAL    a literal-pool word changed (a repoint; listed so each can be checked)
  W-JUMPTABLE  a switch-table word changed
  I-DATA       changes outside code (counted only)

Output: build/patch-audit.txt (full report) and a summary on stdout.
"""
from __future__ import annotations

import io
import json
import sys
from collections import defaultdict
from contextlib import redirect_stdout
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT.parent
BASE = 0x08000000


def translated_rom():
    sys.path.insert(0, str(PROJECT))
    sys.path.insert(0, str(PROJECT / "engine" / "script"))
    from engine.script import build_rom          # noqa: E402
    from text.script import tr                   # noqa: E402
    with redirect_stdout(io.StringIO()):
        p = build_rom.build_patcher()
        caves = list(p.caves)
        hooks = list(p.hooks)
        rom = tr.pack(bytearray(p.rom))
    return bytes(rom), caves, hooks


def main():
    base = (ROOT / "baserom.gba").read_bytes()
    t = json.loads((ROOT / "build" / "trace.json").read_text())
    syms = {}
    sp = ROOT / "reference" / "symbols.tsv"
    for ln in sp.read_text(encoding="utf-8").splitlines()[1:]:
        a, n = ln.split("\t")[:2]
        syms[int(a, 16)] = n
    new, caves, hooks = translated_rom()
    th = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)

    insn = {}          # addr -> (size, mode, func)
    owner = {}         # byte -> func
    lit = {}
    jt = {}
    branch_in = defaultdict(set)   # target -> {(site, func)}
    entries = set()
    for f in t["functions"]:
        entries.add(f["addr"])
        other = set(f["other_mode"])
        for a, n in f["insns"]:
            m = f["mode"] if a not in other else ("arm" if f["mode"] == "thumb" else "thumb")
            insn[a] = (n, m, f["addr"])
            for b in range(a, a + n):
                owner[b] = f["addr"]
        for l in f["literals"]:
            lit[l] = f["addr"]
        for tb, n, site in f["jumptables"]:
            for k in range(n):
                jt[tb + 4 * k] = f["addr"]
                c = int.from_bytes(base[tb + 4 * k - BASE:tb + 4 * k - BASE + 4], "little")
                branch_in[c].add((site, f["addr"]))
        for s, tg in f["farjumps"]:
            branch_in[tg].add((s, f["addr"]))
    # Ordinary branches.
    for a, (n, m, fn) in insn.items():
        if m != "thumb" or n != 2:
            continue
        h = base[a - BASE] | base[a - BASE + 1] << 8
        if h >> 11 == 0b11100:
            off = h & 0x7FF
            off = off - 0x800 if off & 0x400 else off
            branch_in[a + 4 + 2 * off].add((a, fn))
        elif h >> 12 == 0xD and (h >> 8) & 0xF < 0xE:
            off = h & 0xFF
            off = off - 0x100 if off & 0x80 else off
            branch_in[a + 4 + 2 * off].add((a, fn))

    cave_ranges = [(a, a + s, n) for a, s, n in caves]

    def in_cave(x):
        return next((n for lo, hi, n in cave_ranges if lo <= x < hi), None)

    def fname(a):
        return syms.get(a, f"sub_{a:08X}")

    # Changed ranges inside the original 8 MB.
    n = len(base)
    ranges = []
    i = 0
    while i < n:
        if new[i] != base[i]:
            j = i
            while j < n and (new[j] != base[j] or (j + 1 < n and new[j + 1] != base[j + 1])):
                j += 1
            ranges.append((BASE + i, BASE + j))
            i = j
        i += 1

    hook_name = {}
    for a, s, nm in hooks:
        for b in range(a, a + s):
            hook_name.setdefault(b, nm)

    findings = []
    counts = defaultdict(int)

    def add(code, a, msg):
        findings.append((code, a, msg))
        counts[code] += 1

    data_bytes = 0
    hook_sites = []
    for lo, hi in ranges:
        code_bytes = [b for b in range(lo, hi) if b in owner]
        lits = sorted({l for l in lit if l < hi and l + 4 > lo})
        jts = sorted({w for w in jt if w < hi and w + 4 > lo})
        nm = hook_name.get(lo) or next((hook_name[b] for b in range(lo, hi) if b in hook_name), "?")
        for l in lits:
            old = int.from_bytes(base[l - BASE:l - BASE + 4], "little")
            nv = int.from_bytes(new[l - BASE:l - BASE + 4], "little")
            if old != nv:
                add("W-LITERAL", l, f"{fname(lit[l])}: literal {old:08X} -> {nv:08X} [{nm}]")
        for w in jts:
            add("W-JUMPTABLE", w, f"{fname(jt[w])}: switch table word changed [{nm}]")
        if not code_bytes:
            if not lits and not jts:
                data_bytes += hi - lo
            continue
        # Expand to whole instructions for reporting.
        fn = owner[code_bytes[0]]
        starts = [a for a in range(lo - 3, hi) if a in insn]
        first = max((a for a in starts if a <= lo and a + insn[a][0] > lo), default=lo)
        # Instruction granularity: widen to whole original instructions, then make sure the new
        # bytes decode on the same boundaries (no bl prefix left dangling into the next
        # original instruction, no bl suffix left at the start).
        last = max((a for a in starts if a < hi), default=None)
        wlo = first
        whi = last + insn[last][0] if last is not None else hi
        h_first = new[wlo - BASE] | new[wlo - BASE + 1] << 8
        if insn.get(wlo, (2,))[0] == 2 and h_first >> 11 == 0b11111 and                 (base[wlo - BASE - 1] >> 3) != 0b11110:
            add("E-MIDINSN", wlo, f"{fname(fn)}: rewritten code starts with a lone bl suffix [{nm}]")
        a = wlo
        while a < whi:
            h = new[a - BASE] | new[a - BASE + 1] << 8
            a += 4 if h >> 11 == 0b11110 else 2
        if a != whi:
            add("E-MIDINSN", whi, f"{fname(fn)}: new bl at {a - 4:08X} straddles the end of the rewrite "
                                  f"into the original instruction at {whi:08X} [{nm}]")
        lo, hi = wlo, whi
        mode = insn[starts[0]][1] if starts else "thumb"
        if mode == "arm":
            add("E-ARM", lo, f"{fname(fn)}: ARM code rewritten [{nm}]")
            continue
        # Paths from outside that land strictly inside the rewritten bytes.
        for tgt in range(lo + 1, hi):
            for site, sf in branch_in.get(tgt, ()):
                if not lo <= site < hi:
                    add("E-ENTERED", tgt, f"{fname(sf)}: branch at {site:08X} enters rewritten bytes "
                                          f"{lo:08X}-{hi:08X} at {tgt:08X} [{nm}]")
        # Decode the new bytes and check control transfers.
        o = lo - BASE
        a = lo
        new_bls = []
        while a < hi:
            h = new[a - BASE] | new[a - BASE + 1] << 8
            if h >> 11 == 0b11110 and a + 4 <= hi + 2:
                h2 = new[a - BASE + 2] | new[a - BASE + 3] << 8
                off = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
                if off & 0x400000:
                    off -= 0x800000
                tg = a + 4 + off
                new_bls.append((a, tg))
                if not (tg in entries or in_cave(tg) or (lo <= tg < hi)):
                    if tg in owner and tg not in branch_in and tg - BASE < len(base):
                        add("E-BLTARGET", a, f"{fname(fn)}: new bl at {a:08X} -> {tg:08X} lands inside "
                                             f"{fname(owner[tg])} [{nm}]")
                a += 4
            else:
                a += 2
        hook_sites.append((lo, hi, fn, nm))

    # ---- Reachability in the patched ROM ------------------------------------------------
    # Re-trace every function the translation changed, in the patched bytes, following hooks
    # into their caves.  A cave either returns (bx lr / pop pc / pop {rX}; bx rX) or jumps back
    # to an absolute address (ldr rX, =addr|1; bx rX).  Only problems on paths that can run are
    # reported: an executable path reaching a lone bl suffix, an invalid instruction, or the
    # middle of another instruction.
    sys.path.insert(0, str(ROOT / "tools"))
    from trace import Explorer, Rom, THUMB, decode_thumb   # noqa: E402
    nrom = Rom(new)
    ex = Explorer(nrom)
    cave_info = {}

    def cave(addr):
        if addr in cave_info:
            return cave_info[addr]
        f = ex.explore(addr, THUMB, "cave", set(), set())
        rets, exits = False, set()
        if f.ok:
            for a, sz in f.insns.items():
                if sz != 2:
                    continue
                h = nrom.u16(a)
                if h >> 8 == 0xBD or h == 0x4770:
                    rets = True
                elif h >> 8 == 0x47:
                    rm = (h >> 3) & 0xF
                    ph = nrom.u16(a - 2) if (a - 2) in f.insns else 0
                    if ph >> 8 == 0xBC and ph & (1 << rm):
                        rets = True                    # pop {rX}; bx rX
                    elif a in f.calls:
                        x = f.calls[a][0]
                        if in_cave(x) and x != addr and x not in cave_info:
                            cave_info[x] = (True, "", False, set())      # cycle guard
                            ok2, _, r2, e2 = cave(x)
                            rets = rets or r2
                            exits |= e2
                        elif not in_cave(x):
                            exits.add(x)
                    else:
                        rets = True                    # unknown register target: assume return
        cave_info[addr] = (f.ok, f.why, rets, exits)
        return cave_info[addr]

    in_cave_addr = lambda x: in_cave(x) is not None
    origf = {f["addr"]: f for f in t["functions"]}
    farj = {}
    jtab = {}
    for f in t["functions"]:
        for s_, tg in f["farjumps"]:
            farj[s_] = tg
        for tb, n_, site in f["jumptables"]:
            jtab[site] = [int.from_bytes(base[tb + 4 * k - BASE:tb + 4 * k - BASE + 4], "little")
                          for k in range(n_)]
    touched = sorted({owner[b] for lo, hi in ranges for b in range(lo, hi) if b in owner})
    reach_findings = 0
    reached = {}
    for fa in touched:
        if origf[fa]["mode"] != "thumb" or origf[fa]["other_mode"]:
            continue
        starts = {}
        work = [fa]
        seen_cave_exit = set()
        while work:
            a = work.pop()
            while True:
                if a in starts:
                    break
                if (a - 2) in starts and starts[a - 2] == 4:
                    add("E-REACHMID", a, f"{fname(fa)}: a path reaches {a:08X}, the second half of the bl at {a - 2:08X}")
                    reach_findings += 1
                    break
                if a != fa and a in entries:
                    break                                      # fell into the next function
                if owner.get(a) not in (fa, None) and not in_cave_addr(a):
                    break
                ins = decode_thumb(nrom, a)
                if ins is None:
                    add("E-REACHBAD", a, f"{fname(fa)}: a path reaches an invalid instruction at {a:08X}")
                    reach_findings += 1
                    break
                starts[a] = ins.size
                if ins.size == 4 and (a + 2) in starts:
                    add("E-REACHMID", a + 2, f"{fname(fa)}: {a + 2:08X} is both an instruction and the "
                                             f"second half of the bl at {a:08X}")
                    reach_findings += 1
                falls = ins.falls
                if ins.kind == "bl":
                    tg = ins.target
                    if a in farj and base[a - BASE:a - BASE + 4] == new[a - BASE:a - BASE + 4]:
                        work.append(farj[a])
                        falls = False
                    elif in_cave_addr(tg):
                        ok, why, rets, exits = cave(tg)
                        if not ok:
                            add("E-CAVE", tg, f"{fname(fa)}: hook at {a:08X} calls cave {in_cave(tg)} that does not "
                                              f"trace cleanly: {why}")
                            reach_findings += 1
                        for x in exits:
                            if owner.get(x) == fa:
                                work.append(x)
                            elif x not in entries and (fa, x) not in seen_cave_exit:
                                seen_cave_exit.add((fa, x))
                                add("W-CAVEEXIT", x, f"{fname(fa)}: cave {in_cave(tg)} exits to {x:08X}, outside "
                                                     f"this function ({fname(owner[x]) if x in owner else 'not code'})")
                        falls = rets
                elif ins.kind in ("b", "bcc"):
                    work.append(ins.target)
                elif ins.kind == "jmp":
                    if a in jtab and base[a - BASE:a - BASE + 2] == new[a - BASE:a - BASE + 2]:
                        work.extend(jtab[a])
                    falls = False
                elif ins.kind == "ret":
                    falls = False
                if not falls:
                    break
                a += ins.size
        reached[fa] = starts
    # ---- Lost side effects -----------------------------------------------------------------
    # For each hook bl into a cave: registers (and flags) written by the original instructions
    # it displaced, still read by the original code where the cave resumes, and never written
    # by the cave, are values the patched game no longer computes.
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
    md.detail = True
    sigs = {}
    sgp = ROOT / "build" / "signatures.tsv"
    if sgp.exists():
        for ln in sgp.read_text().splitlines()[1:]:
            ad, na, rv = ln.split("\t")
            sigs[int(ad, 16)] = (int(na), rv == "1")
    REGS = [f"r{i}" for i in range(8)] + ["r8", "sb", "sl", "fp", "ip", "lr"]

    def rw(buf, a):
        o = a - BASE
        n_ = 4 if (buf[o + 1] >> 3) == 0b11110 else 2
        ins = next(md.disasm(buf[o:o + n_], a), None)
        if ins is None:
            return None, set(), set(), n_
        r, w = ins.regs_access()
        rd = {ins.reg_name(x) for x in r}
        wr = {ins.reg_name(x) for x in w}
        if ins.mnemonic == "bl":
            tg = ins.operands[0].imm
            na, rv = sigs.get(tg, (4, True))
            rd = {f"r{i}" for i in range(na)}
            wr = {"r0", "r1", "r2", "r3", "ip", "lr", "cpsr"}
        return ins, rd, wr, n_

    def live_at(start, fa, limit=24, buf=None):
        """Registers read before written on some path from `start`, decoding the patched bytes
        (the code a cave returns into may itself be rewritten)."""
        buf = new if buf is None else buf
        live = set()
        stack = [(start, frozenset(), 0)]
        seen = set()
        while stack:
            a, killed, depth = stack.pop()
            while depth < limit:
                if (a, killed) in seen or owner.get(a) != fa:
                    break
                seen.add((a, killed))
                ins, rd, wr, n_ = rw(buf, a)
                if ins is None:
                    break
                m_ = ins.mnemonic
                if m_.startswith("pop") and "pc" in ins.op_str or m_ == "bx":
                    if sigs.get(fa, (0, True))[1] and "r0" not in killed:
                        live.add("r0")
                    break
                live |= (rd - killed) - {"sp", "pc"}
                killed = killed | wr
                depth += 1
                if m_ == "bl" and in_cave(ins.operands[0].imm):
                    ok_, _, rets_, exits_ = cave(ins.operands[0].imm)
                    for x in exits_:
                        stack.append((x, killed, depth))
                    if not rets_:
                        break
                if m_ == "b":
                    a = ins.operands[0].imm
                    continue
                if m_.startswith("b") and m_ not in ("bl", "bic", "bics") and len(ins.operands) == 1:
                    stack.append((ins.operands[0].imm, killed, depth))
                a += n_
        return live

    for lo, hi, fa, nm in hook_sites:
        for site in range(lo, hi, 2):
            h = new[site - BASE] | new[site - BASE + 1] << 8
            if h >> 11 != 0b11110:
                continue
            h2 = new[site - BASE + 2] | new[site - BASE + 3] << 8
            off = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
            off -= 0x800000 if off & 0x400000 else 0
            tg = site + 4 + off
            if not in_cave(tg):
                continue
            ok, why, rets, exits = cave(tg)
            if not ok:
                continue
            displaced = [x for x in sorted(insn) if lo <= x < hi and owner.get(x) == fa]
            defs = set()
            for x in displaced:
                ins, rd, wr, n_ = rw(base, x)
                if ins is not None and not ins.mnemonic.startswith("b"):
                    defs |= wr
            # Registers the cave (and anything it calls) writes.
            cf = ex.explore(tg, THUMB, "cave", set(), set())
            cwr = set()
            for a_, sz in cf.insns.items():
                _, _, wr, _ = rw(new, a_)
                cwr |= wr
            resume = ([site + 4] if rets else []) + [x for x in exits if owner.get(x) == fa]
            # A displaced instruction that merely repeats an identical earlier one (agbcc emits
            # such duplicates), with nothing in between writing its operands, loses nothing.
            redundant = set()
            for x in displaced:
                ins, rd, wr, n_ = rw(base, x)
                if ins is None:
                    continue
                txt = (ins.mnemonic, ins.op_str)
                for y in range(x - 2, fa - 2, -2):
                    if y not in insn or owner.get(y) != fa:
                        continue
                    iy, ry, wy, _ = rw(base, y)
                    if iy is not None and (iy.mnemonic, iy.op_str) == txt:
                        clobbered = any((rw(base, z)[2] & (rd | wr)) for z in range(y + 2, x, 2)
                                        if z in insn and z not in displaced)
                        if not clobbered:
                            redundant |= wr
                        break
            for r_ in resume:
                lv = live_at(r_, fa)
                lost = sorted((defs & lv) - cwr - redundant - {"sp", "pc"})
                if lost:
                    add("W-LOSTDEF", site, f"{fname(fa)}: hook {nm} to {in_cave(tg)} drops "
                                           f"{', '.join(lost)} (set by the displaced code, read at "
                                           f"{r_:08X}, never written by the cave)")
    # ---- Repointed literals keep their kind ------------------------------------------------
    for c, a, m in list(findings):
        if c != "W-LITERAL":
            continue
        ov, nv = (int(x, 16) for x in m.split("literal ")[1].split(" [")[0].split(" -> "))
        okind = "func" if ov & 1 and (ov & ~1) in entries else (
            "code" if (ov & ~1) in owner else ("rom" if BASE <= ov < BASE + 0x2000000 else "other"))
        if okind == "func":
            t_ = nv & ~1
            if not nv & 1 or not (t_ in entries or in_cave(t_)):
                add("E-LITKIND", a, m.split(":")[0] + f": function pointer {ov:08X} replaced by "
                                                      f"{nv:08X}, which is not a Thumb entry or cave")
        elif okind == "rom" and (nv & ~1) in owner and nv not in entries and not in_cave(nv):
            add("E-LITKIND", a, m.split(":")[0] + f": data pointer {ov:08X} replaced by {nv:08X}, "
                                                  f"which points into code")
    # Re-judge the "entered" findings with the patched trace: harmless if the branching code
    # is now unreachable, or if it lands on an instruction boundary of the new code.
    judged = []
    for c, a, m in findings:
        if c == "E-ENTERED":
            site = int(m.split("branch at ")[1][:8], 16)
            fa = owner.get(site)
            r = reached.get(fa, {})
            if site not in r:
                c = "I-ENTERED-DEAD"
            elif a in r:
                c = "I-ENTERED-OK"
        judged.append((c, a, m))
    findings[:] = judged
    counts.clear()
    for c, _, _ in findings:
        counts[c] += 1

    out = [f"translation patch audit: {len(ranges)} changed ranges, {data_bytes} bytes of plain data changes",
           " ".join(f"{k}={v}" for k, v in sorted(counts.items())), ""]
    for code, a, msg in sorted(findings, key=lambda x: (x[0][0] != "E", x[0], x[1])):
        out.append(f"{code:12s} {a:08X}  {msg}")
    (ROOT / "build" / "patch-audit.txt").write_text("\n".join(out) + "\n", encoding="utf-8")
    print("\n".join(out[:2]))
    for line in out[3:]:
        if line.startswith("E-"):
            print(line)


if __name__ == "__main__":
    main()
