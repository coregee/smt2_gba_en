#!/usr/bin/env python3
"""Regression proof for the two-pass best-fit-decreasing (BFD) code-cave allocator.

The build's cave placement (rompatch.plan_pool_layout + build_rom.build_patcher) is order-independent
BFD instead of order-sensitive first-fit. This script proves a BFD build is FUNCTIONALLY EQUIVALENT to
the old first-fit build, and that placement no longer depends on PATCH_ORDER. Because caves move, the
final ROM hash legitimately differs — so equivalence is proven structurally, not by hash:

  A. same multiset of (cave name, size)            — same caves built
  B. same set of hook (site, size)                 — same engine locations patched
  C. every hook site: byte-identical, or every byte difference explained by same-named-cave
     relocation (branch retarget / interior cave-pointer reloc)
  D. whole-ROM diff: EVERY differing byte lies inside a cave region or a hook site (0 stray) — no
     cave pointer escapes through a channel p.hooks doesn't record
  E. every cave body, independently RE-DERIVED (re-assembled / re-compiled) at its final address,
     byte-matches the ROM — proves each body is correct FOR ITS ADDRESS, not merely 'inside a cave'

Then the ORDER-INDEPENDENCE stress test moves the two biggest caves to the end of PATCH_ORDER (the
exact hostile order the old 'big caves first' comments guarded against): first-fit FAILS (exhaustion),
BFD builds and stays equivalent.

Usage:  python -m text.script.tools.verify_cave_layout [--quick]
Needs the base ROM + devkitARM (a full build runs twice).  Exit 0 = PASS.
"""
import sys
import importlib
from pathlib import Path

try:
    from text.script.tools import _boot  # noqa: F401
except ModuleNotFoundError:
    import _boot  # noqa: F401

from engine.script import build_rom, rommap
from engine.script import rompatch as _rp
from engine.script.rompatch import RomPatcher, plan_pool_layout
from engine.script.cave_asm import assemble as _assemble
from engine.script.cave_cc import build_blob as _build_blob
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB

B = rommap.ROM_BASE
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
_BR = {"b", "bl", "blx", "beq", "bne", "bcs", "bcc", "bmi", "bpl",
       "bhi", "bls", "bge", "blt", "bgt", "ble"}

# --- provenance capture so check E can independently re-derive each cave at its final address ---
_PROV = {}  # (id(patcher), final_addr) -> rederive(addr) -> bytes
_oa, _oc, _od, _of = (RomPatcher.cave_asm, RomPatcher.cave_c, RomPatcher.data, RomPatcher.cave_c_far)
RomPatcher.cave_asm = lambda self, asm, literals=(), at=None, name="asm": _rec(
    self, _oa(self, asm, literals, at, name), lambda a, asm=asm, l=list(literals): _assemble(asm, a, l))
RomPatcher.cave_c = lambda self, src, at=None, name="c": _rec(
    self, _oc(self, src, at, name), lambda a, src=src: _build_blob(Path(src), a)[0])
RomPatcher.cave_c_far = lambda self, src, name="cfar": _rec(
    self, _of(self, src, name), lambda a, src=src: _build_blob(Path(src), a)[0])
RomPatcher.data = lambda self, blob, at=None, name="data": _rec(
    self, _od(self, blob, at, name), lambda a, b=bytes(blob): b)


def _rec(self, addr, fn):
    _PROV[(id(self), addr)] = fn
    return addr


def caveset(p):
    ms = {}
    for _a, size, name in p.caves:
        ms[(name, size)] = ms.get((name, size), 0) + 1
    return ms


def cave_at(caves, target):
    t = target & ~1
    for addr, size, name in caves:
        if addr <= t < addr + size:
            return (name, t - addr)
    return None


def disasm(rom, site, size):
    out = []
    for ins in md.disasm(bytes(rom[site - B:site - B + size]), site):
        tgt = None
        if ins.mnemonic.split('.')[0] in _BR:
            try:
                tgt = int(ins.op_str.lstrip("#"), 0)
            except ValueError:
                tgt = None
        out.append((ins.mnemonic, tgt))
    return out


def first_fit():
    """The original allocator: a single-pass first-fit RomPatcher (no plan)."""
    p = RomPatcher(build_rom._fresh_rom())
    for mod in build_rom.PATCHES:
        mod.apply(p)
    return p


def verify(p_old, p_new, pairing=None, label=""):
    """pairing = {new_cave_index: old_cave_index} for the SAME logical cave (needed when apply order
    differs, e.g. a reordered PATCH_ORDER); default = identity."""
    if label:
        print(f"--- {label} ---")
    ok = True

    A = caveset(p_old) == caveset(p_new)
    print(f"A. cave (name,size) multiset {'IDENTICAL' if A else '*** DIFFERS ***'} "
          f"({sum(caveset(p_new).values())} caves)")
    ok &= A

    old_sites = {(s, sz) for s, sz, _n in p_old.hooks}
    new_sites = {(s, sz) for s, sz, _n in p_new.hooks}
    Bok = old_sites == new_sites
    print(f"B. hook (site,size) set {'IDENTICAL' if Bok else '*** DIFFERS ***'} ({len(new_sites)} sites)")
    ok &= Bok

    assert len(p_old.caves) == len(p_new.caves)
    if pairing is None:
        pairing = {i: i for i in range(len(p_new.caves))}
    for ni, oi in pairing.items():
        assert p_new.caves[ni][1:] == p_old.caves[oi][1:], \
            f"pairing mismatch: {p_new.caves[ni]} vs {p_old.caves[oi]}"
    new_names = [n for _a, _s, n in p_new.caves]
    assert len(set(new_names)) == len(new_names), \
        f"cave names NOT unique: {sorted(n for n in new_names if new_names.count(n) > 1)}"

    def reloc_word(nw):
        thumb = nw & 1
        t = nw & ~1
        for ni, (na, ns, _nn) in enumerate(p_new.caves):
            if na <= t < na + ns:
                oa, _os, _on = p_old.caves[pairing[ni]]
                return (oa + (t - na)) | thumb
        return None

    identical = explained = 0
    unexplained = []
    for site, size in sorted(new_sites):
        ob = bytes(p_old.rom[site - B:site - B + size])
        nb = bytes(p_new.rom[site - B:site - B + size])
        if ob == nb:
            identical += 1
            continue
        od, nd = disasm(p_old.rom, site, size), disasm(p_new.rom, site, size)
        good = None
        if [m for m, _ in od] == [m for m, _ in nd]:
            good = True
            for (_om, ot), (_nm, nt) in zip(od, nd):
                if ot is None and nt is None:
                    continue
                oc, nc = cave_at(p_old.caves, ot or 0), cave_at(p_new.caves, nt or 0)
                if oc is not None or nc is not None:
                    if oc != nc:
                        good = False
                        unexplained.append((hex(site), "branch", oc, nc))
                elif ot != nt:
                    good = False
                    unexplained.append((hex(site), "fixed", hex(ot or 0), hex(nt or 0)))
        if not good:
            dgood = True
            for o in range(0, size - 3, 4):
                ow = int.from_bytes(ob[o:o + 4], "little")
                nw = int.from_bytes(nb[o:o + 4], "little")
                if ow != nw and reloc_word(nw) != ow:
                    dgood = False
                    unexplained.append((hex(site), f"word@+{o}", hex(ow), hex(nw)))
            good = dgood
        if good:
            explained += 1
    print(f"C. {identical} byte-identical, {explained} explained-by-relocation, "
          f"{len(unexplained)} UNEXPLAINED")
    for u in unexplained[:15]:
        print("   UNEXPLAINED", u)
    ok &= (not unexplained)

    # D. whole-ROM diff: every differing byte must be inside a cave region or a hook site
    import bisect
    ivals = [(a, a + s) for a, s, _n in p_old.caves] + [(a, a + s) for a, s, _n in p_new.caves]
    ivals += [(s, s + sz) for s, sz in new_sites]
    ivals.sort()
    merged = []
    for lo, hi in ivals:
        if merged and lo <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(merged[-1][1], hi))
        else:
            merged.append((lo, hi))
    starts = [m[0] for m in merged]

    def allowed(addr):
        i = bisect.bisect_right(starts, addr) - 1
        return i >= 0 and merged[i][0] <= addr < merged[i][1]

    oldr, newr, n_diff, stray = p_old.rom, p_new.rom, 0, []
    for base in range(0, min(len(oldr), len(newr)), 1 << 16):
        ob, nb = oldr[base:base + (1 << 16)], newr[base:base + (1 << 16)]
        if ob == nb:
            continue
        for j in range(len(ob)):
            if ob[j] != nb[j]:
                n_diff += 1
                if not allowed(B + base + j):
                    stray.append(B + base + j)
    print(f"D. whole-ROM diff: {n_diff} bytes differ, all inside cave regions or hook sites "
          f"except {len(stray)} STRAY")
    for s in stray[:15]:
        print("   STRAY @0x%08X" % s)
    ok &= (not stray)

    # E. independently re-derive each cave body at its final address and byte-compare
    match, noprov, body_bad = 0, 0, []
    for na, ns, nn in p_new.caves:
        fn = _PROV.get((id(p_new), na))
        if fn is None:
            noprov += 1
            continue
        if fn(na) == bytes(p_new.rom[na - B:na - B + ns]):
            match += 1
        else:
            body_bad.append((nn, hex(na)))
    print(f"E. cave bodies re-derived at final addr: {match} MATCH, {noprov} no-provenance, "
          f"{len(body_bad)} BAD")
    for b in body_bad[:15]:
        print("   BAD BODY", b)
    ok &= (not body_bad and noprov == 0)

    print("RESULT:", "PASS" if ok else "*** FAIL ***")
    return ok


def two_pass(mods):
    """build_patcher() for an arbitrary module order (returns pass-2 patcher + identity tags)."""
    scratch = (max(hi for _l, hi in rommap.FARCAVE_POOL_SPANS), rommap.ROM_BASE + rommap.ROM_TARGET_SIZE)
    p1 = RomPatcher(build_rom._fresh_rom(), pool=scratch)
    for m in mods:
        m.apply(p1)
    plan = plan_pool_layout(p1._plan_log, list(rommap.CAVE_POOL_SPANS))
    p = RomPatcher(build_rom._fresh_rom())
    p._plan = plan
    tags = {}
    for m in mods:
        before = len(p.caves)
        m.apply(p)
        for j in range(len(p.caves) - before):
            tags[(m.__name__.split('.')[-1], j)] = before + j
    assert p._req_ord == len(plan)
    return p, tags


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    quick = "--quick" in sys.argv

    print("== canonical order: first-fit vs BFD ==")
    ref = first_fit()
    bfd = build_rom.build_patcher()
    ok = verify(ref, bfd, label="canonical: first-fit == BFD (functionally)")

    if not quick:
        print("\n== order-independence stress: move the two biggest caves to the END ==")
        canon = [m.__name__.split('.')[-1] for m in build_rom.PATCHES]
        move_last = ["patch_msgwin", "patch_markerlist"]
        hostile = [n for n in canon if n not in move_last] + move_last
        assert hostile.index("patch_font") < hostile.index("patch_vwf"), "keep font before vwf"
        hostile_mods = [importlib.import_module(n) for n in hostile]
        # tag the reference build so we can pair caves across the reordered build
        ref2 = RomPatcher(build_rom._fresh_rom())
        tags_ref = {}
        for m in build_rom.PATCHES:
            before = len(ref2.caves)
            m.apply(ref2)
            for j in range(len(ref2.caves) - before):
                tags_ref[(m.__name__.split('.')[-1], j)] = before + j
        # (1) first-fit on the hostile order — the old allocator
        try:
            pf = RomPatcher(build_rom._fresh_rom())
            for m in hostile_mods:
                m.apply(pf)
            print(f"(1) first-fit @hostile: BUILT (pool not tight enough to fail this move): {pf.summary()}")
        except SystemExit as e:
            print(f"(1) first-fit @hostile: FAILED as the old comments predicted -> {e}")
        # (2) BFD on the hostile order — must build and stay equivalent
        ph, tags_ph = two_pass(hostile_mods)
        assert set(tags_ph) == set(tags_ref)
        pairing = {tags_ph[t]: tags_ref[t] for t in tags_ph}
        ok &= verify(ref2, ph, pairing, "(2) BFD@hostile-order == first-fit@canonical (functionally)")
        print("\nORDER-INDEPENDENCE:", "PROVEN" if ok else "*** NOT proven ***")

    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
