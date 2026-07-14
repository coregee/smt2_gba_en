#!/usr/bin/env python3
"""RomPatcher — in-memory ROM editing for the build, with an automatic code-cave allocator.

build_rom loads the working ROM once, makes a RomPatcher over it, then calls each patch module's
`apply(p)` in order; the patcher owns the bytes.  Code caves no longer carry a hand-picked CAVE
address: `p.cave_asm(...)` / `p.cave_c(...)` bump-allocate from the free pool (rommap.CAVE_POOL_*),
assert the region is zero, and return the address — so adding a patch never means eyeballing a gap.
Pass `at=` to force a specific address (e.g. a cave that must sit near a far hook).

A hook is `p.bl(site, target, old_hex)`: it asserts the original bytes (catching a moved/already-
patched site) and writes the Thumb BL.  `p.patch(site, old_hex, new)` is the generic guarded
replace for non-cave edits; `p.read/p.write` are raw access.  Every change is recorded for the
build summary (and the confined-diff self-check).
"""
from pathlib import Path

from engine.script import rommap
from engine.script.cave_asm import assemble, thumb_bl
from engine.script.cave_cc import build_blob

B = rommap.ROM_BASE


class RomPatcher:
    def __init__(self, rom, pool=None):
        self.rom = rom                      # bytearray (whole cartridge image)
        if pool is None:
            self._spans = list(rommap.CAVE_POOL_SPANS)
        elif isinstance(pool[0], int):
            self._spans = [tuple(pool)]     # legacy single (start, end)
        else:
            self._spans = list(pool)
        self._cursors = [lo for lo, _hi in self._spans]   # first-fit: per-span bump cursors
        self._far_spans = list(getattr(rommap, "FARCAVE_POOL_SPANS", []))
        self._far_cursors = [lo for lo, _hi in self._far_spans]
        self.caves = []                     # (addr, size, name)
        self.hooks = []                     # (addr, size, name)
        # Best-fit-decreasing placement (see plan_pool_layout + build_rom's two-pass build):
        self._plan = None                   # pass 2: {ordinal: (addr, size)} -> placement is dictated
        self._req_ord = 0                   # monotonic pool-allocation counter (the plan's join key)
        self._plan_log = []                 # single-pass/pass 1: [(ordinal, size)] recorded for the planner

    # ---- raw access ----
    def read(self, addr, n):
        return bytes(self.rom[addr - B:addr - B + n])

    def write(self, addr, data):
        self.rom[addr - B:addr - B + len(data)] = bytes(data)

    def expect(self, addr, old):
        old = bytes.fromhex(old) if isinstance(old, str) else bytes(old)
        got = self.read(addr, len(old))
        if got != old:
            raise SystemExit(f"site @0x{addr:08X}: expected {old.hex()}, found {got.hex()} "
                             "(moved / already patched / wrong address?)")
        return len(old)

    # ---- hooks / guarded edits ----
    def bl(self, addr, target, old, name=""):
        n = self.expect(addr, old)            # guard the whole replaced span
        ins = bytearray(thumb_bl(addr, target))
        ins += b"\xc0\x46" * ((n - 4) // 2)   # pad any extra (e.g. bl+nop 6-byte sites) with NOP
        self.write(addr, ins[:n])
        self.hooks.append((addr, n, name or f"bl->{target:08X}"))

    def patch(self, addr, old_hex, new, name=""):
        self.expect(addr, old_hex)
        self.write(addr, bytes(new))
        self.hooks.append((addr, len(bytes(new)), name or "patch"))

    # ---- cave allocation ----
    def _alloc(self, at):
        """Return (candidate_addr, from_pool). Pool placement is finalized by _span_fit (the
        candidate only seeds an address-independent first assembly)."""
        return (self._cursors[0], True) if at is None else (at, False)

    def _span_fit(self, size):
        """Place one pool cave and remember its span for _reserve.

        Two modes, distinguished by self._plan.  Every call consumes one request ordinal
        (self._req_ord) in apply() order — the stable join key between the two build passes.

        * PLAN mode (pass 2, self._plan set): the address is DICTATED by the precomputed
          best-fit-decreasing plan, so placement is independent of the order patches run in.
          Asserts the cave's size matches what the planning pass measured (catches a
          non-deterministic / address-dependent cave) and that it lands 4-aligned in a span.
        * FIRST-FIT mode (single pass, or pass-1 size discovery): first-fit across spans
          (was bump-forward, which stranded space behind the cursor — hit 2026-06-13 when
          cave_msgwin outgrew the tail spans while span 1 still had room), recording
          (ordinal, size) so a caller can build a BFD plan from the result."""
        ord_ = self._req_ord
        self._req_ord += 1
        if self._plan is not None:
            if ord_ not in self._plan:
                raise SystemExit(f"pass 2 made an unplanned pool request (ordinal {ord_}): the two "
                                 "passes diverged — a cave's allocation is non-deterministic")
            addr, psize = self._plan[ord_]
            if size != psize:
                raise SystemExit(f"cave size drift at pool req {ord_}: plan measured {psize} B, "
                                 f"got {size} B — a cave is non-deterministic / address-dependent")
            if addr & 3:
                raise SystemExit(f"plan address 0x{addr:08X} (req {ord_}) is not 4-byte aligned")
            for i, (lo, hi) in enumerate(self._spans):
                if lo <= addr < hi:
                    if addr + size > hi:
                        raise SystemExit(f"plan req {ord_}: {size} B at 0x{addr:08X} overflows its span")
                    self._fit_i = i
                    return addr
            raise SystemExit(f"plan address 0x{addr:08X} (req {ord_}) falls in no cave span")
        for i, (lo, hi) in enumerate(self._spans):
            cur = self._cursors[i]
            if cur + size <= hi:
                self._fit_i = i
                self._plan_log.append((ord_, size))
                return cur
        raise SystemExit(f"cave pool exhausted ({getattr(self, '_alloc_name', '?')}): {size} B "
                         f"fits no span; add a span to rommap.CAVE_POOL_SPANS")

    def _reserve(self, addr, size, from_pool, name):
        o = addr - B
        if any(self.rom[o:o + size]):
            raise SystemExit(f"cave @0x{addr:08X} ({size} B, {name}) overlaps non-zero ROM")
        if from_pool:
            # 4-byte align the next cave: cave_asm/cave_c literal pools (`ldr [pc]`, `.word`) must be
            # word-aligned or ARM7TDMI reads them rotated (garbage) -> the cave jumps off into space.
            self._cursors[self._fit_i] = (addr + size + 3) & ~3
        self.caves.append((addr, size, name))

    def cave_asm(self, asm, literals=(), at=None, name="asm"):
        self._alloc_name = name
        addr, pool = self._alloc(at)
        code = assemble(asm, addr, list(literals))    # size is address-independent
        if pool:
            naddr = self._span_fit(len(code))
            if naddr != addr:                         # crossed into a later span -> re-assemble there
                addr = naddr
                code = assemble(asm, addr, list(literals))
        self._reserve(addr, len(code), pool, name)
        self.write(addr, code)
        return addr

    def cave_c(self, src, at=None, name="c"):
        self._alloc_name = name
        addr, pool = self._alloc(at)
        blob, syms = build_blob(Path(src), addr)       # blob length is address-independent
        if pool:
            naddr = self._span_fit(len(blob))
            if naddr != addr:                          # crossed into a later span -> rebuild there
                addr = naddr
                blob, syms = build_blob(Path(src), addr)
        self._reserve(addr, len(blob), pool, name)
        self.write(addr, blob)
        self.cave_c_syms = {n: addr + o for n, o in syms.items()}   # abs addr of each blob symbol
        return addr

    def cave_c_far(self, src, name="cfar"):
        """Compile a C cave into the FAR pool (rommap.FARCAVE_POOL_SPANS, out of Thumb BL range).
        Caller reaches it with `bl_far` (a near trampoline).  Internal engine calls use -mlong-calls
        (absolute), so far placement is fine.  Sets cave_c_syms like cave_c."""
        self._alloc_name = name
        if not self._far_spans:
            raise SystemExit("cave_c_far: no rommap.FARCAVE_POOL_SPANS defined")
        for i, (lo, hi) in enumerate(self._far_spans):
            addr = (self._far_cursors[i] + 3) & ~3
            blob, syms = build_blob(Path(src), addr)
            if addr + len(blob) <= hi:
                o = addr - B
                if any(self.rom[o:o + len(blob)]):
                    raise SystemExit(f"far cave @0x{addr:08X} ({len(blob)} B, {name}) overlaps non-zero "
                                     "ROM (was build_rom's 16 MB pre-extend run?)")
                self.write(addr, blob)
                self._far_cursors[i] = addr + len(blob)
                self.caves.append((addr, len(blob), name + " (far)"))
                self.cave_c_syms = {n: addr + off for n, off in syms.items()}
                return addr
        raise SystemExit(f"far cave pool exhausted ({name}): {name} fits no FARCAVE span")

    def bl_far(self, site, far_target, old, name=""):
        """Hook `site` to a FAR target (out of BL range): allocate a tiny near trampoline that jumps
        to far_target via an absolute literal, then `bl` the trampoline.  The trampoline clobbers r3
        (free at glyph-loop hook sites; the cave veneer re-sets it) and does not return."""
        tramp = self.cave_asm("ldr r3, [pc, #0]\n bx r3", [far_target | 1],
                              name=(name or "far") + "_tramp")
        self.bl(site, tramp, old, name=name or f"bl_far->{far_target:08X}")
        return tramp

    def data(self, blob, at=None, name="data"):
        self._alloc_name = name
        addr, pool = self._alloc(at)
        blob = bytes(blob)
        if pool:
            addr = self._span_fit(len(blob))
        self._reserve(addr, len(blob), pool, name)
        self.write(addr, blob)
        return addr

    def summary(self):
        # Count only allocations that actually live in the cave spans; `at=` far-data blobs
        # (e.g. name charset, stat-label strings) are reserved too but don't consume pool budget.
        in_span = lambda a: any(st <= a < en for st, en in self._spans)
        used = sum(s for a, s, _ in self.caves if in_span(a))
        cap = sum(e - s for s, e in self._spans)
        # per-span high-water mark from the placed caves (correct for both first-fit and the
        # best-fit-decreasing plan, where _cursors no longer track the bump order).
        hw = [lo for lo, _hi in self._spans]
        for a, s, _ in self.caves:
            for i, (lo, hi) in enumerate(self._spans):
                if lo <= a < hi:
                    hw[i] = max(hw[i], a + s)
        return (f"{len(self.hooks)} hooks, {len(self.caves)} caves, "
                f"{used}/{cap} B across {len(self._spans)} cave span(s) "
                "(" + ", ".join(f"span{i+1} @0x{h:08X}" for i, h in enumerate(hw)) + ")")


def plan_pool_layout(plan_log, spans):
    """Best-fit-decreasing placement of pool caves into the (fixed, initially-empty) spans.

    plan_log = [(ordinal, size), ...] in allocation (apply) order, as recorded by a first-fit
    "planning" pass (RomPatcher._span_fit).  Returns {ordinal: (addr, size)} for the real pass
    to consume, so final placement is a function of the SIZE MULTISET + span geometry, NOT of the
    order patches happen to run in (the whole point: build_rom.PATCH_ORDER then needs only TRUE
    data dependencies, not the old "big caves first" fragmentation tuning).

    Largest caves are placed first into the span whose leftover gap is smallest-but-sufficient
    (best-fit), which removes the manual ordering and packs near-optimally.  Each span stays a
    single shrinking [cursor, hi) interval — we only bump within it and no `at=` blob lands inside
    a span (asserted by build_rom) — so no free-list is needed.  Addresses are 4-byte aligned
    (cave_asm/cave_cc require it).  Exhaustion is a hard, descriptive error."""
    cursors = [lo for lo, _hi in spans]
    plan = {}
    for ord_, size in sorted(plan_log, key=lambda t: (-t[1], t[0])):   # size desc, ordinal tiebreak
        best = None                                                    # (slack, span_index, addr)
        for i, (lo, hi) in enumerate(spans):
            addr = (cursors[i] + 3) & ~3                               # 4-align the candidate
            if addr + size <= hi:
                slack = hi - (addr + size)
                if best is None or slack < best[0]:
                    best = (slack, i, addr)
        if best is None:
            raise SystemExit(f"cave pool exhausted (pool req {ord_}): {size} B fits no span under "
                             "best-fit-decreasing; add a span to rommap.CAVE_POOL_SPANS")
        _slack, bi, baddr = best
        plan[ord_] = (baddr, size)
        cursors[bi] = baddr + size
    return plan
