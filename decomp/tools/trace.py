#!/usr/bin/env python3
"""Recursive-descent code discovery for the SMT2 GBA ROM, ARM/Thumb aware.

Ghidra guesses the instruction set from byte patterns and often gets Thumb/ARM wrong.  This
tracer never guesses: the mode of every address comes from how control reaches it.

  * the reset vector and crt0 are ARM;
  * a Thumb ``bl`` reaches Thumb code; ``b``/``bcc`` stay in the current mode;
  * ``bx rN`` after ``ldr rN, =X`` switches by bit 0 of X (odd = Thumb, even = ARM);
  * a word in data with bit 0 set that points into the program is a Thumb function pointer;
  * ``mov pc, rN`` after the agbcc switch idiom indexes a table of same-mode case labels.

agbcc quirks handled here:

  * Unconditional branches longer than Thumb ``b`` can reach (+-2 KB) are emitted as ``bl``
    ("far jump"), so a ``bl`` whose target lies inside the caller's own body is a jump, not a
    call, and does not fall through.
  * Functions return with ``pop {rX}; bx rX`` for interworking.

Discovery is a fixpoint.  Each round traces every believed entry, with all other entries and
all literal pools as barriers; ``bl`` targets of accepted code become entries for the next
round; data-pointer candidates are accepted only if they trace cleanly, start outside every
accepted function, and overlap no accepted code or data.

Output: JSON with functions (instructions, literals, jump tables, callees, far jumps).
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

import capstone

ROM_BASE = 0x08000000
# The compiled program: main() is the first function after the location-name table and the LCG
# Random() is the last before the read-only tables (a sine table at 0x0815E828).  Heuristic
# entries (data pointers) are only believed inside this range.
TEXT_START, TEXT_END = 0x080A96CC, 0x0815E828

THUMB, ARM = "thumb", "arm"
REGNAMES = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
            "r8", "sb", "sl", "fp", "ip", "sp", "lr", "pc"]

SEEDS = [
    (0x080000C0, ARM, "reset vector"),
    (0x080000FC, ARM, "crt0 IRQ dispatcher (adr stored to 0x03007FFC)"),
    # Found by the text extraction: ARM code inside the text region whose address the link code
    # (0x080DEE20) only stores, and a Thumb function after a module data block too large for
    # the gap scan.
    (0x08032B7C, ARM, "ARM routine in the text region (address taken at 0x080DEED0)"),
    (0x081267F4, THUMB, "after the 0x080F6472 module data block"),
]


def s_ext(v: int, bits: int) -> int:
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


@dataclass
class Insn:
    addr: int
    size: int
    kind: str = "op"          # op | b | bcc | bl | ret | jmp | swi
    target: int | None = None
    lit: int | None = None    # literal-pool address loaded by this instruction
    falls: bool = True


class Rom:
    def __init__(self, data: bytes):
        self.data = data
        self.end = ROM_BASE + len(data)

    def inrom(self, a: int) -> bool:
        return ROM_BASE <= a < self.end

    def u16(self, a: int) -> int:
        o = a - ROM_BASE
        return self.data[o] | self.data[o + 1] << 8

    def u32(self, a: int) -> int:
        return struct.unpack_from("<I", self.data, a - ROM_BASE)[0]


# --------------------------------------------------------------------------- decoding

def decode_thumb(rom: Rom, a: int) -> Insn | None:
    """Decode one ARMv4T Thumb instruction; None if it is not valid on the ARM7TDMI."""
    if not rom.inrom(a + 1):
        return None
    h = rom.u16(a)
    top5 = h >> 11
    if top5 == 0b11110:                                   # BL prefix + suffix
        if not rom.inrom(a + 3):
            return None
        h2 = rom.u16(a + 2)
        if h2 >> 11 != 0b11111:
            return None
        off = s_ext(((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1), 23)
        return Insn(a, 4, "bl", a + 4 + off)
    if top5 in (0b11111, 0b11101):                        # lone BL suffix / BLX (v5)
        return None
    if top5 == 0b11100:                                   # B
        return Insn(a, 2, "b", a + 4 + s_ext(h & 0x7FF, 11) * 2, falls=False)
    if h >> 12 == 0xD:
        cond = (h >> 8) & 0xF
        if cond == 0xE:
            return None
        if cond == 0xF:
            return Insn(a, 2, "swi", falls=(h & 0xFF) != 0)      # swi 0 = SoftReset
        return Insn(a, 2, "bcc", a + 4 + s_ext(h & 0xFF, 8) * 2)
    if h >> 8 == 0x47:                                    # BX (BLX reg is v5)
        if h & 0x87:
            return None
        return Insn(a, 2, "jmp", falls=False)
    if h >> 10 == 0b010001:                               # hi-register add/cmp/mov
        op = (h >> 8) & 3
        rd = (h & 7) | ((h >> 4) & 8)
        if rd == 15 and op in (0, 2):                     # add pc, rm / mov pc, rm
            return Insn(a, 2, "jmp", falls=False)
        return Insn(a, 2)
    if h >> 11 == 0b01001:                                # ldr rd, [pc, #imm]
        return Insn(a, 2, lit=((a + 4) & ~3) + (h & 0xFF) * 4)
    if h >> 12 == 0xB:
        sub = (h >> 8) & 0xF
        if sub == 0x0:
            return Insn(a, 2)                             # add/sub sp
        if sub in (0x4, 0x5, 0xC, 0xD):
            if (h & 0x1FF) == 0:
                return None                               # empty register list
            if sub == 0xD:
                return Insn(a, 2, "ret", falls=False)     # pop {.., pc}
            return Insn(a, 2)
        return None                                       # v5+/v6 encodings
    if h >> 12 == 0xC and h & 0xFF == 0:
        return None                                       # ldm/stm with empty list
    return Insn(a, 2)


def decode_arm(rom: Rom, a: int) -> Insn | None:
    if a & 3 or not rom.inrom(a + 3):
        return None
    w = rom.u32(a)
    cond = w >> 28
    if cond == 0xF:
        return None                                       # unconditional space is v5+
    always = cond == 0xE
    if (w & 0x0E000000) == 0x0A000000:                    # B / BL
        tgt = a + 8 + s_ext(w & 0xFFFFFF, 24) * 4
        if w & 0x01000000:
            return Insn(a, 4, "bl", tgt)
        return Insn(a, 4, "b" if always else "bcc", tgt, falls=not always)
    if (w & 0x0FFFFFF0) == 0x012FFF10:                    # BX
        return Insn(a, 4, "jmp", falls=not always)
    if (w & 0x0F000000) == 0x0F000000:
        return Insn(a, 4, "swi")
    rd = (w >> 12) & 0xF
    if (w & 0x0F7F0000) == 0x051F0000:                    # ldr rd, [pc, #+-imm]
        off = w & 0xFFF
        lit = a + 8 + (off if w & 0x00800000 else -off)
        if rd == 15:
            return Insn(a, 4, "jmp", lit=lit, falls=not always)
        return Insn(a, 4, lit=lit)
    if (w & 0x0C000000) == 0 and rd == 15:                # data processing writing pc
        op = (w >> 21) & 0xF
        is_psr_or_misc = (w & 0x01900000) == 0x01000000
        if op not in (0x8, 0x9, 0xA, 0xB) and not is_psr_or_misc:
            return Insn(a, 4, "jmp", falls=not always)
    if (w & 0x0E100000) == 0x08100000 and w & 0x8000:     # ldm {.., pc}
        return Insn(a, 4, "ret", falls=not always)
    if (w & 0x0C500000) == 0x04100000 and rd == 15:       # ldr pc, [..]
        return Insn(a, 4, "jmp", falls=not always)
    if (w & 0x0C000000) == 0x0C000000:                    # coprocessor: none on the GBA
        return None
    return Insn(a, 4)


DECODERS = {THUMB: decode_thumb, ARM: decode_arm}


# --------------------------------------------------------------------------- one function

@dataclass
class Func:
    addr: int
    mode: str
    origin: str
    insns: dict = field(default_factory=dict)        # addr -> size
    literals: set = field(default_factory=set)
    jumptables: list = field(default_factory=list)   # [table_addr, count, dispatch_site]
    calls: dict = field(default_factory=dict)        # site -> (target, mode)
    farjumps: dict = field(default_factory=dict)     # site -> target
    tailjumps: dict = field(default_factory=dict)    # site -> target (b into another entry)
    noreturn: set = field(default_factory=set)       # bl sites that never return
    blame: int | None = None                          # last bl before a failure on this path
    pred: dict = field(default_factory=dict)          # fallthrough predecessor of each insn
    fallsinto: set = field(default_factory=set)       # entries this code runs straight into
    modes: dict = field(default_factory=dict)         # insn -> thumb/arm (m4a mixes both)
    switches: dict = field(default_factory=dict)      # bx site -> (target, mode) in-function
    ok: bool = True
    why: str = ""

    def code_bytes(self):
        for a, n in self.insns.items():
            yield from range(a, a + n)

    def end(self):
        e = max(a + n for a, n in self.insns.items())
        for l in self.literals:
            e = max(e, l + 4)
        for t, n, _ in self.jumptables:
            e = max(e, t + 4 * n)
        return e


class Explorer:
    def __init__(self, rom: Rom):
        self.rom = rom
        self._md = {}

    def explore(self, entry: int, mode: str, origin: str, barriers: set, data: set) -> Func:
        """Trace one function.  `barriers`: other function entries (flow into one ends the path).
        `data`: bytes known to be literal/table data (flow into one is an error)."""
        farjumps: set[int] = set()
        noreturn: set[int] = set()
        while True:
            f = self._trace(entry, mode, origin, barriers, data, farjumps, noreturn)
            if not f.ok:
                # A path that went wrong straight after a `bl` means the bl does not return:
                # a far jump if its target is inside this function, else a no-return call.
                s = f.blame
                if s is None or s in farjumps or s in noreturn:
                    return f
                t = f.calls.get(s, (None,))[0]
                if t is not None and entry < t < entry + 0x10000 and t not in barriers:
                    farjumps.add(s)
                else:
                    noreturn.add(s)
                continue
            top = max(f.insns)
            new = {s for s, (t, m) in f.calls.items()
                   if m == mode and entry < t <= top and s not in farjumps}
            if not new:
                return f
            farjumps |= new

    def _trace(self, entry, fmode, origin, barriers, data, farjumps, noreturn) -> Func:
        f = Func(entry, fmode, origin)
        work = [(entry, fmode)]
        cases: list = []
        while work or cases:
            a, mode = work.pop() if work else cases.pop()
            dec = DECODERS[mode]
            f.blame = None
            while True:
                if a in f.insns:
                    break
                if a != entry and a in barriers:
                    if a in f.pred or (a - 2) in f.insns or (a - 4) in f.insns:
                        f.fallsinto.add(a)
                    break                                   # falls into the next function
                if not self.rom.inrom(a):
                    return self._fail(f, f"runs out of ROM at {a:08X}")
                if a in data:
                    return self._fail(f, f"runs into data at {a:08X}")
                ins = dec(self.rom, a)
                if ins is None:
                    return self._fail(f, f"invalid {mode} instruction at {a:08X}")
                f.insns[a] = ins.size
                f.modes[a] = mode
                if ins.lit is not None:
                    if not self.rom.inrom(ins.lit + 3):
                        return self._fail(f, f"literal outside ROM at {a:08X}")
                    f.literals.add(ins.lit)
                falls = ins.falls
                if ins.kind == "bl":
                    if a in farjumps:
                        f.farjumps[a] = ins.target
                        work.append((ins.target, mode))
                        falls = False
                    else:
                        f.calls[a] = (ins.target, mode)
                        if a in noreturn:
                            f.noreturn.add(a)
                            falls = False
                        else:
                            f.blame = a
                elif ins.kind in ("b", "bcc"):
                    t = ins.target
                    if t != entry and t in barriers:
                        f.tailjumps[a] = t
                    else:
                        work.append((t, mode))
                elif ins.kind == "jmp":
                    if not self._jump(f, ins, mode, cases, work):
                        return f
                if not falls:
                    break
                f.pred[a + ins.size] = a
                a += ins.size
        f.blame = None
        cb = set(f.code_bytes())
        for l in f.literals:
            hit = cb.intersection(range(l, l + 4))
            if hit:
                f.blame = self._blame_chain(f, min(hit))
                return self._fail(f, f"literal {l:08X} overlaps own code")
        for t, n, _ in f.jumptables:
            if cb.intersection(range(t, t + 4 * n)):
                return self._fail(f, f"jump table {t:08X} overlaps own code")
        return f

    def _blame_chain(self, f: Func, byte: int):
        """Walk fallthrough predecessors back from the instruction holding `byte` to a bl."""
        a = next((i for i in (byte, byte - 1, byte - 2, byte - 3)
                  if i in f.insns and i + f.insns[i] > byte), None)
        while a is not None:
            a = f.pred.get(a)
            if a is not None and a in f.calls and self._is_bl(f.modes[a], a):
                return a
        return None

    def _is_bl(self, mode, a):
        if mode == THUMB:
            return self.rom.u16(a) >> 11 == 0b11110
        return (self.rom.u32(a) & 0x0F000000) == 0x0B000000

    @staticmethod
    def _fail(f, why):
        f.ok, f.why = False, why
        return f

    def _jump(self, f: Func, ins: Insn, mode: str, cases: list, work: list) -> bool:
        a = ins.addr
        if mode == THUMB:
            h = self.rom.u16(a)
            rm = (h >> 3) & 0xF
            if h >> 8 == 0x47:                               # bx rm
                sw = self._adr_before(f, a, rm, mode)
                if sw is not None:                           # adr rm, X; bx rm: switch to ARM
                    work.append((sw, ARM))
                    f.switches[a] = (sw, ARM)
                    return True
                if rm != 14:
                    lit = self._lit_load(f, a, rm, mode)
                    if lit is not None:
                        v = self.rom.u32(lit)
                        if v & 1 and self.rom.inrom(v):
                            f.calls[a] = (v & ~1, THUMB)
                        elif self.rom.inrom(v) and not v & 3:
                            f.calls[a] = (v, ARM)
                return True
            tbl = self._jump_table(f, a, rm)
            if tbl:
                taddr, n = tbl
                f.jumptables.append([taddr, n, a])
                for k in range(n):
                    t = self.rom.u32(taddr + 4 * k)
                    if t & 1 or not self.rom.inrom(t):
                        self._fail(f, f"bad case {t:08X} in table {taddr:08X}")
                        return False
                    cases.append((t, mode))
            return True
        w = self.rom.u32(a)
        if (w & 0x0FFFFFF0) == 0x012FFF10:
            rm = w & 0xF
            sw = self._adr_before(f, a, rm, mode)
            if sw is not None:                               # add rm, pc, #X; bx rm
                m = THUMB if sw & 1 else ARM
                work.append((sw & ~1, m))
                f.switches[a] = (sw & ~1, m)
                return True
            if rm != 14:
                lit = self._lit_load(f, a, rm, mode)
                if lit is not None:
                    v = self.rom.u32(lit)
                    if self.rom.inrom(v):
                        f.calls[a] = (v & ~1, THUMB if v & 1 else ARM)
        return True

    def _lit_load(self, f: Func, a: int, reg: int, mode: str):
        """The literal loaded into `reg` by the straight-line code just before `a`, if any.
        Any other instruction that writes `reg` (per capstone) ends the search."""
        step = 2 if mode == THUMB else 4
        b = a
        for _ in range(6):
            b -= step
            if b not in f.insns:
                return None
            ins = self._cs(mode, b)
            if ins is None:
                return None
            if mode == THUMB:
                h = self.rom.u16(b)
                if h >> 11 == 0b01001 and (h >> 8) & 7 == reg:
                    return ((b + 4) & ~3) + (h & 0xFF) * 4
            else:
                w = self.rom.u32(b)
                if (w & 0x0F7F0000) == 0x051F0000 and ((w >> 12) & 0xF) == reg:
                    off = w & 0xFFF
                    return b + 8 + (off if w & 0x00800000 else -off)
            _, written = ins.regs_access()
            if any(ins.reg_name(r) == REGNAMES[reg] for r in written):
                return None
        return None

    def _adr_before(self, f: Func, a: int, reg: int, mode: str):
        """`adr reg, X` (Thumb) / `add reg, pc, #X` (ARM) directly before a bx: its X."""
        b = a - (2 if mode == THUMB else 4)
        if b not in f.insns or f.modes.get(b) != mode:
            return None
        if mode == THUMB:
            h = self.rom.u16(b)
            if h >> 11 == 0b10100 and (h >> 8) & 7 == reg:
                return ((b + 4) & ~3) + (h & 0xFF) * 4
            return None
        w = self.rom.u32(b)
        if (w & 0x0FFFF000) == (0x028F0000 | reg << 12):
            rot = ((w >> 8) & 0xF) * 2
            imm = w & 0xFF
            imm = ((imm >> rot) | (imm << (32 - rot))) & 0xFFFFFFFF if rot else imm
            return b + 8 + imm
        return None

    def _cs(self, mode, a):
        md = self._md.get(mode)
        if md is None:
            md = capstone.Cs(capstone.CS_ARCH_ARM,
                             capstone.CS_MODE_THUMB if mode == THUMB else capstone.CS_MODE_ARM)
            md.detail = True
            self._md[mode] = md
        n = 2 if mode == THUMB else 4
        o = a - ROM_BASE
        return next(md.disasm(self.rom.data[o:o + n], a), None)

    def _jump_table(self, f: Func, a: int, rm: int):
        """agbcc: cmp rX,#N / bhi dflt / lsls rX,#2 / ldr rY,=T / adds rX,rY / ldr rX,[rX] / mov pc,rX"""
        count = None
        taddr = None
        b = a
        for _ in range(12):
            b -= 2
            if b not in f.insns:
                break
            h = self.rom.u16(b)
            if taddr is None and h >> 11 == 0b01001:
                lit = ((b + 4) & ~3) + (h & 0xFF) * 4
                v = self.rom.u32(lit)
                if self.rom.inrom(v):
                    taddr = v
            if h >> 11 == 0b00101:                          # cmp rn, #imm8
                count = (h & 0xFF) + 1
                break
        if taddr is None:
            return None
        if count is None:
            count = 0
            while count < 256:
                t = self.rom.u32(taddr + 4 * count)
                if t & 1 or not (f.addr <= t < f.addr + 0x8000):
                    break
                count += 1
            if count == 0:
                return None
        return taddr, count


# --------------------------------------------------------------------------- fixpoint

def looks_like_entry(rom: Rom, t: int, claimed_lits: set, ends: set) -> bool:
    """A data pointer is believed to be a function only where a function could start: at a
    prologue (`push {.., lr}` / `push {rN..}`), or just after the end of another function
    (its return, its last unconditional branch, its literal pool or 0 padding)."""
    h = rom.u16(t)
    if h >> 9 == 0b1011010:                               # push
        return True
    if t in ends:
        return True
    p = t - 2
    if rom.u16(p) == 0 and (p - 2) in claimed_lits | ends:
        return True
    if (t - 4) in claimed_lits:
        return True
    ph = rom.u16(p)
    return ph >> 8 == 0xBD or ph & 0xFF87 == 0x4700 or ph >> 11 == 0b11100


def data_pointer_candidates(rom: Rom, claimed: set):
    d = rom.data
    out = {}
    for o in range(0, len(d) - 3, 4):
        a = ROM_BASE + o
        if a in claimed:
            continue
        v = struct.unpack_from("<I", d, o)[0]
        if v & 1 and TEXT_START <= v < TEXT_END:
            out.setdefault(v & ~1, a)
    return out


def scan_gaps(rom: Rom, funcs: dict, max_gap=0x1000):
    """Unreferenced (dead) functions: in each unexplained gap of the program segment, try the
    first non-padding halfword as a Thumb entry.  Large gaps are module read-only data."""
    covered = set()
    for f in funcs.values():
        covered.update(f.code_bytes())
        for l in f.literals:
            covered.update(range(l, l + 4))
        for t, n, _ in f.jumptables:
            covered.update(range(t, t + 4 * n))
    out = []
    a = TEXT_START
    while a < TEXT_END:
        if a in covered:
            a += 1
            continue
        b = a
        while b < TEXT_END and b not in covered:
            b += 1
        if b - a <= max_gap:
            s = (a + 1) & ~1
            while s < b and rom.u16(s) in (0, 0x46C0):
                s += 2
            if s < b:
                out.append((s, b))
        a = b
    return out


def discover(rom: Rom, log=print):
    ex = Explorer(rom)
    origins: dict[int, tuple[str, str]] = {a: (m, o) for a, m, o in SEEDS}
    pointer_entries: dict[int, str] = {}
    rejected: dict[int, str] = {}
    funcs: dict[int, Func] = {}
    internal: set[int] = set()
    dead: dict[int, str] = {}
    seed_addrs = {a for a, _, _ in SEEDS}
    for rnd in range(1, 200):
        entries = dict(origins)
        for a, why in pointer_entries.items():
            entries.setdefault(a, (THUMB, why))
        barriers = set(entries)
        # Data barriers: literal pools/tables of last round's accepted functions.
        data = set()
        for f in funcs.values():
            for l in f.literals:
                data.update(range(l, l + 4))
            for t, n, _ in f.jumptables:
                data.update(range(t, t + 4 * n))
        new_funcs = {}
        for a in sorted(entries):
            m, why = entries[a]
            f = ex.explore(a, m, why, barriers, data)
            if f.ok:
                new_funcs[a] = f
            else:
                rejected[a] = f"{why}: {f.why}"
        # An entry that is an instruction of another accepted function is not an entry.
        inside = {}
        for f in new_funcs.values():
            for i in f.insns:
                if i != f.addr:
                    inside[i] = f.addr
        # Switch case labels are never entries.
        for f in new_funcs.values():
            for t, n, _ in f.jumptables:
                for k in range(n):
                    inside.setdefault(rom.u32(t + 4 * k), f.addr)
        # A pointer "entry" that real code runs straight into is the middle of that code.
        for f in new_funcs.values():
            for t in f.fallsinto:
                if t in pointer_entries and t in new_funcs and rom.u16(t) >> 8 != 0xB5:
                    inside[t] = f.addr
        for a in list(new_funcs):
            if a in inside and a in pointer_entries:
                rejected[a] = f"{entries[a][1]}: inside {inside[a]:08X}"
                del new_funcs[a]
                del pointer_entries[a]
        funcs = new_funcs
        # agbcc never branches (b/bcc) into another function.  A branch into an "entry" means
        # the entry is a label inside the brancher, reached elsewhere by a far-jump bl; unless
        # some other function calls it, it stops being an entry.
        callers: dict[int, set] = {}
        for f in funcs.values():
            for site, (t, m) in f.calls.items():
                callers.setdefault(t, set()).add(f.addr)
        for f in funcs.values():
            for site, t in f.tailjumps.items():
                if callers.get(t, set()) <= {f.addr} and t not in seed_addrs:
                    internal.add(t)
                    pointer_entries.pop(t, None)
        # Next round's call-derived entries.
        new_origins = {a: (m, o) for a, m, o in SEEDS}
        for f in sorted(funcs.values(), key=lambda f: f.addr):
            for site, (t, m) in sorted(f.calls.items()):
                if t not in new_origins and t not in internal:
                    new_origins[t] = (m, f"call from {site:08X}")
        # Pointers into the program held anywhere but in instructions: literal pools (callbacks
        # passed as arguments) and data tables.  Jump-table words are case labels, not entries.
        claimed = set()
        codeb = set()
        for f in funcs.values():
            codeb.update(f.code_bytes())
            for t, n, _ in f.jumptables:
                codeb.update(range(t, t + 4 * n))
        claimed |= codeb
        for f in funcs.values():
            for l in f.literals:
                claimed.update(range(l, l + 4))
        ptrs = data_pointer_candidates(rom, codeb)
        lits = set()
        ends = set()
        for f in funcs.values():
            lits.update(f.literals)
            ends.add(f.end())
            ends.add((f.end() + 3) & ~3)
        new_ptr = dict()
        for t, loc in ptrs.items():
            if t in claimed or t in new_origins or t in internal:
                continue
            if not looks_like_entry(rom, t, lits, ends):
                continue
            new_ptr[t] = f"pointer at {loc:08X}"
        # Keep previous pointer entries that still hold.
        for t, why in pointer_entries.items():
            if t in funcs:
                new_ptr.setdefault(t, why)
        for t in list(new_ptr):
            if t in rejected and t not in funcs and t not in pointer_entries:
                del new_ptr[t]
        for t, why in dead.items():
            if t not in new_origins and t not in new_ptr and t not in inside:
                new_ptr[t] = why
        stable = new_origins.keys() == origins.keys() and new_ptr.keys() == pointer_entries.keys()
        log(f"round {rnd}: {len(funcs)} functions, {len(new_origins)} call entries, "
            f"{len(new_ptr)} pointer entries")
        origins, pointer_entries = new_origins, new_ptr
        if stable:
            # Last: unreferenced functions in the gaps.  Each accepted one may expose more.
            found = 0
            for s, e in scan_gaps(rom, funcs):
                if s in dead or s in rejected:
                    continue
                f = ex.explore(s, THUMB, "unreferenced", set(funcs) | {s}, set())
                prologue = rom.u16(s) >> 8 == 0xB5
                returns = any(rom.u16(a) >> 8 == 0xBD or rom.u16(a) >> 8 == 0x47
                              for a in f.insns if f.insns[a] == 2)
                small = f.ok and f.end() - s <= 0x40
                if (f.ok and f.end() <= e and min(f.insns) >= s and not f.fallsinto
                        and returns):
                    dead[s] = "unreferenced (gap scan)"
                    found += 1
                else:
                    rejected[s] = "gap scan: " + (f.why or "extends past gap")
            if not found:
                break
            for t, why in dead.items():
                pointer_entries.setdefault(t, why)
    for a in funcs:
        rejected.pop(a, None)
    return funcs, rejected


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("-o", "--out", default="build/trace.json")
    args = ap.parse_args(argv)
    rom = Rom(Path(args.rom).read_bytes())
    funcs, rejected = discover(rom, log=lambda s: print(s, file=sys.stderr))
    out = {
        "functions": [
            {"addr": f.addr, "mode": f.mode, "origin": f.origin, "end": f.end(),
             "insns": sorted(f.insns.items()), "literals": sorted(f.literals),
             "jumptables": f.jumptables,
             "calls": sorted((s, t, m) for s, (t, m) in f.calls.items()),
             "farjumps": sorted(f.farjumps.items()),
             "tailjumps": sorted(f.tailjumps.items()),
             "noreturn": sorted(f.noreturn),
             "fallsinto": sorted(f.fallsinto),
             "other_mode": sorted(a for a, m in f.modes.items() if m != f.mode)}
            for f in sorted(funcs.values(), key=lambda f: f.addr)
        ],
        "rejected": {f"{k:08X}": v for k, v in sorted(rejected.items())},
    }
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_text(json.dumps(out))


if __name__ == "__main__":
    main()
