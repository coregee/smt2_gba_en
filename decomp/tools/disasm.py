#!/usr/bin/env python3
"""Emit GNU-as source for the whole ROM from the trace, such that assembling and linking it
reproduces the cartridge byte for byte.

Code becomes real instructions with symbolic branch targets, literal pools and jump tables;
function pointers and pointers to ROM data are symbolic, so the source can later be edited and
relinked.  Everything that is not code is emitted as data (``.incbin`` of the base ROM until an
asset extractor claims it, see ``assets.py``).

Instruction text comes from capstone.  Each distinct position-independent instruction is
assembled once by GNU as (``verify_texts``); any text that GNU as rejects or encodes
differently is emitted as ``.2byte``/``.4byte`` with the mnemonic in a comment, so the build
stays exact.  Branches, ``bl``, and pc-relative loads use labels and are checked by the final
link comparison instead.
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import subprocess
import sys
import tempfile
from bisect import bisect_right
from pathlib import Path

import capstone

sys.path.insert(0, str(Path(__file__).parent))
from trace import ROM_BASE, TEXT_START, TEXT_END, THUMB, ARM  # noqa: E402
import symbols as symdb  # noqa: E402
import gbaregs  # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# Regions of the ROM that hold code (crt0 + the compiled program).  The rest is data.
CODE_REGIONS = [(ROM_BASE + 0xC0, ROM_BASE + 0x200), (TEXT_START, TEXT_END)]


def find_tool(name):
    from shutil import which
    p = which(name)
    if p:
        return p
    for d in (Path("C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi"),):
        for exe in sorted(d.glob(f"*/bin/{name}.exe")):
            return str(exe)
    for d in (Path("C:/msys64/opt/devkitpro/devkitARM/bin"),):
        if (d / f"{name}.exe").exists():
            return str(d / f"{name}.exe")
    raise SystemExit(f"{name} not found; install the Arm GNU toolchain (see README)")


class Model:
    """Everything the emitter needs to know about one address."""

    def __init__(self, rom: bytes, trace: dict, syms: symdb.Symbols):
        self.rom = rom
        self.syms = syms
        self.funcs = {f["addr"]: f for f in trace["functions"]}
        self.insn = {}           # addr -> (size, mode, func)
        self.lit = {}            # literal addr -> func
        self.jt = {}             # table addr -> (count, func)
        self.jt_word = set()
        self.local_labels = set()
        self.calls = {}          # site -> target
        self.farjumps = {}
        for f in trace["functions"]:
            other = set(f["other_mode"])
            for a, n in f["insns"]:
                m = f["mode"] if a not in other else (ARM if f["mode"] == THUMB else THUMB)
                self.insn[a] = (n, m, f["addr"])
            for l in f["literals"]:
                self.lit[l] = f["addr"]
            for t, n, _ in f["jumptables"]:
                self.jt[t] = (n, f["addr"])
                for k in range(n):
                    self.jt_word.add(t + 4 * k)
                    self.local_labels.add(struct.unpack_from("<I", rom, t + 4 * k - ROM_BASE)[0])
                self.local_labels.add(t)
            for s, t, m in f["calls"]:
                self.calls[s] = t
            for s, t in f["farjumps"]:
                self.farjumps[s] = t
                self.local_labels.add(t)
        self.func_mode = {a: f["mode"] for a, f in self.funcs.items()}
        # Data labels: ROM addresses outside code that literal pools point at.
        self.data_labels = set()
        for l in self.lit:
            v = self.u32(l)
            if self.in_rom(v) and not self.is_code_addr(v):
                self.data_labels.add(v)
        for a in syms.by_addr:
            if self.in_rom(a) and not self.is_code_addr(a) and a not in self.funcs:
                self.data_labels.add(a)

    def u16(self, a):
        return struct.unpack_from("<H", self.rom, a - ROM_BASE)[0]

    def u32(self, a):
        return struct.unpack_from("<I", self.rom, a - ROM_BASE)[0]

    def in_rom(self, a):
        return ROM_BASE <= a < ROM_BASE + len(self.rom)

    def is_code_addr(self, a):
        """True if `a` is an instruction or lies inside one (cannot carry a data label)."""
        for k in range(4):
            i = self.insn.get(a - k)
            if i is not None and k < i[0]:
                return True
        return False

    def fname(self, a):
        return self.syms.name(a) or (f"sub_{a:08X}" if self.func_mode.get(a) == THUMB
                                     else f"arm_{a:08X}")

    def dname(self, a):
        return self.syms.name(a) or f"gUnknown_{a:08X}"

    def pointer_expr(self, v):
        """Symbolic form of a word that may be a ROM pointer, or None."""
        if not self.in_rom(v & ~1):
            return None
        t = v & ~1
        if t in self.funcs:
            thumb = self.func_mode[t] == THUMB
            if thumb and v & 1:
                return self.fname(t)
            if not thumb and not v & 1:
                return self.fname(t)
            return None
        if v in self.data_labels:
            return self.dname(v)
        return None


# --------------------------------------------------------------------------- instruction text

class Texts:
    def __init__(self):
        self.th = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
        self.ar = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
        self.ok: dict = {}       # (mode, bytes) -> verified text or None

    def raw_text(self, mode, b: bytes):
        md = self.th if mode == THUMB else self.ar
        ins = next(md.disasm(b, 0), None)
        if ins is None:
            return None
        t = f"{ins.mnemonic} {ins.op_str}".strip()
        if mode == THUMB and ins.mnemonic == "adr":
            t = t.replace("adr", "add", 1).replace(", #", ", pc, #")
        return t


def verify_texts(texts: Texts, items, as_path):
    """Assemble each distinct (mode, encoding) once; keep texts GNU as reproduces exactly."""
    items = sorted(items)
    lines = [".syntax unified", ".cpu arm7tdmi"]
    order = []
    for mode, b in items:
        t = texts.raw_text(mode, b)
        if t is None:
            texts.ok[(mode, b)] = None
            continue
        lines.append(".thumb" if mode == THUMB else ".arm")
        lines.append(f".balign 4\n{t}")
        order.append((mode, b, t))
    with tempfile.TemporaryDirectory() as td:
        src = Path(td, "v.s")
        bad = set()
        for _ in range(20):
            body = [".syntax unified", ".cpu arm7tdmi"]
            line_of = {}
            for i, (mode, b, t) in enumerate(order):
                if i in bad:
                    continue
                body.append(".thumb" if mode == THUMB else ".arm")
                body.append(".balign 4")
                body.append(f"L{i}: {t}")
                line_of[len(body)] = i
            src.write_text("\n".join(body) + "\n")
            r = subprocess.run([as_path, "-mcpu=arm7tdmi", "-o", str(Path(td, "v.o")),
                                "-al=" + str(Path(td, "v.lst")), str(src)],
                               capture_output=True, text=True)
            errs = [int(m.group(1)) for m in re.finditer(r"v\.s:(\d+): Error", r.stderr)]
            if not errs:
                break
            for ln in errs:
                if ln in line_of:
                    bad.add(line_of[ln])
        objcopy = as_path.replace("as", "objcopy") if as_path.endswith("as") else \
            as_path.replace("-as", "-objcopy")
        binp = Path(td, "v.bin")
        subprocess.run([objcopy, "-O", "binary", str(Path(td, "v.o")), str(binp)], check=True)
        nm = as_path.replace("-as", "-nm")
        out = subprocess.run([nm, str(Path(td, "v.o"))], capture_output=True, text=True).stdout
        addr = {}
        for line in out.splitlines():
            parts = line.split()
            if len(parts) == 3 and parts[2].startswith("L") and parts[2][1:].isdigit():
                addr[int(parts[2][1:])] = int(parts[0], 16)
        blob = binp.read_bytes()
        for i, (mode, b, t) in enumerate(order):
            if i in bad or i not in addr:
                texts.ok[(mode, b)] = None
                continue
            got = blob[addr[i]:addr[i] + len(b)]
            texts.ok[(mode, b)] = t if got == b else None


# --------------------------------------------------------------------------- emission

COND = {"eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt",
        "gt", "le", "al"}


class Emitter:
    def __init__(self, m: Model, texts: Texts):
        self.m = m
        self.t = texts
        self.raw_count = 0

    def label_for(self, a):
        m = self.m
        if a in m.funcs:
            return m.fname(a)
        return f".L{a:08X}"

    def branch_targets(self):
        m = self.m
        out = set(m.local_labels)
        for a, (n, mode, f) in m.insn.items():
            k = self.flow(a, n, mode)
            if k:
                out.add(k[1])
        return out

    def flow(self, a, n, mode):
        """(kind, target) for b/bcc/bl instructions, else None."""
        m = self.m
        if mode == THUMB:
            h = m.u16(a)
            if n == 4:
                off = (((h & 0x7FF) << 12) | ((m.u16(a + 2) & 0x7FF) << 1))
                if off & 0x400000:
                    off -= 0x800000
                return ("bl", a + 4 + off)
            if h >> 11 == 0b11100:
                off = h & 0x7FF
                off = off - 0x800 if off & 0x400 else off
                return ("b", a + 4 + off * 2)
            if h >> 12 == 0xD and (h >> 8) & 0xF < 0xE:
                off = h & 0xFF
                off = off - 0x100 if off & 0x80 else off
                return ("bcc", a + 4 + off * 2)
            return None
        w = m.u32(a)
        if (w & 0x0E000000) == 0x0A000000 and w >> 28 != 0xF:
            off = w & 0xFFFFFF
            off = off - 0x1000000 if off & 0x800000 else off
            return ("bl" if w & 0x01000000 else "b", a + 8 + off * 4)
        return None

    def insn_line(self, a, n, mode, targets):
        m = self.m
        b = m.rom[a - ROM_BASE:a - ROM_BASE + n]
        md = self.t.th if mode == THUMB else self.t.ar
        ins = next(md.disasm(b, a), None)
        fl = self.flow(a, n, mode)
        if fl:
            kind, tgt = fl
            mnem = ins.mnemonic
            if kind == "bl" and a not in m.farjumps and tgt in m.funcs:
                return f"bl {m.fname(tgt)}"
            if mode == THUMB and kind == "bl":
                return f"bl {self.label_for(tgt)}"
            return f"{mnem} {self.label_for(tgt)}"
        if mode == THUMB and b[1] >> 3 == 0b01001:
            lit = ((a + 4) & ~3) + b[0] * 4
            return f"ldr r{b[1] & 7}, .L{lit:08X}"
        if mode == ARM:
            w = struct.unpack("<I", b)[0]
            if (w & 0x0F7F0000) == 0x051F0000:
                off = w & 0xFFF
                lit = a + 8 + (off if w & 0x00800000 else -off)
                if lit in m.lit:
                    cond = ins.mnemonic[3:] if len(ins.mnemonic) > 3 else ""
                    return f"ldr{cond} {REG[(w >> 12) & 0xF]}, .L{lit:08X}"
        text = self.t.ok.get((mode, b))
        if text is None:
            self.raw_count += 1
            raw = self.t.raw_text(mode, b) or "?"
            if mode == THUMB:
                return f".2byte 0x{struct.unpack('<H', b)[0]:04X} @ {raw}"
            return f".4byte 0x{struct.unpack('<I', b)[0]:08X} @ {raw}"
        return text

    def word_expr(self, v):
        e = self.m.pointer_expr(v)
        if e is not None:
            return e
        return f"0x{v:08X}"

    def comment_for(self, v):
        n = gbaregs.describe(v)
        return f" @ {n}" if n else ""


REG = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "sb", "sl", "fp", "ip", "sp",
       "lr", "pc"]


def emit_code_file(path: Path, lo: int, hi: int, m: Model, em: Emitter, targets: set,
                   data_split=0x40):
    out = ['\t.include "asm/macros.inc"', "", "\t.syntax unified", "\t.text", ""]
    a = lo
    cur_mode = None
    rom = m.rom
    while a < hi:
        if a in m.data_labels and (a in m.lit or a in m.jt):
            out.append(f"	.global {m.dname(a)}")
            out.append(f"{m.dname(a)}:")
        if a in m.insn:
            n, mode, f = m.insn[a]
            if mode != cur_mode:
                out.append("\t.thumb" if mode == THUMB else "\t.arm")
                cur_mode = mode
            if a in m.funcs:
                name = m.fname(a)
                macro = "thumb_func_start" if mode == THUMB else "arm_func_start"
                out.append("")
                out.append(f"\t{macro} {name}")
                out.append(f"{name}: @ 0x{a:08X}")
                if a in targets:
                    out.append(f".L{a:08X}:")
            elif a in targets:
                out.append(f".L{a:08X}:")
            out.append("\t" + em.insn_line(a, n, mode, targets))
            a += n
            continue
        if a in m.jt:
            cnt, _ = m.jt[a]
            out.append(f".L{a:08X}: @ jump table")
            for k in range(cnt):
                t = m.u32(a + 4 * k)
                out.append(f"\t.4byte .L{t:08X}")
            a += 4 * cnt
            continue
        if a in m.lit and a + 4 <= hi:
            v = m.u32(a)
            out.append(f".L{a:08X}: .4byte {em.word_expr(v)}{em.comment_for(v)}")
            a += 4
            continue
        # Data / padding up to the next code-ish thing.
        b = a + 1
        while b < hi and b not in m.insn and b not in m.jt and b not in m.lit and                 b not in m.jt_word:
            b += 1
        emit_data(out, a, b, m, data_split)
        a = b
    if path is None:
        return out
    path.write_text("\n".join(out) + "\n", newline="\n")


def load_assets():
    """Asset spans by start address: manifest blobs (.incbin of build/assets/*.bin) and source
    includes from every assets/*/includes.json ([{"addr", "len", "file"}], .s files that are
    .include'd in place of the base-ROM bytes: songs, scripts, ...)."""
    out = {}
    p = ROOT / "assets" / "manifest.json"
    if p.exists():
        for e in json.loads(p.read_text())["assets"]:
            out[int(e["addr"], 16)] = e
    for inc in sorted((ROOT / "assets").glob("*/includes.json")):
        for e in json.loads(inc.read_text()):
            a = int(e["addr"], 16)
            if a in out:
                raise SystemExit(f"{inc}: span 0x{a:08X} already claimed")
            out[a] = dict(e, include=True)
    return out


ASSETS = None


def emit_data(out, a, b, m: Model, incbin_min=0x40):
    """Bytes [a, b): extracted assets as .incbin of their rebuilt blobs, the rest from the base
    ROM, with global labels at every referenced address."""
    global ASSETS
    if ASSETS is None:
        ASSETS = load_assets()
    labels = sorted(x for x in m.data_labels if a <= x < b)
    starts = sorted(x for x in ASSETS if a <= x < b)
    cuts = sorted(set(labels) | set(starts))
    pos = a
    li = 0

    def raw(lo, hi):
        n = hi - lo
        if n <= 0:
            return
        if n >= incbin_min:
            out.append(f'	.incbin "baserom.gba", 0x{lo - ROM_BASE:X}, 0x{n:X}')
        else:
            chunk = m.rom[lo - ROM_BASE:hi - ROM_BASE]
            for i in range(0, len(chunk), 16):
                out.append("	.byte " + ", ".join(f"0x{x:02X}" for x in chunk[i:i + 16]))

    for c in cuts + [b]:
        if c < pos:
            continue
        raw(pos, c)
        pos = c
        if c >= b:
            break
        if c in m.data_labels:
            name = m.dname(c)
            out.append(f"	.global {name}")
            out.append(f"{name}: @ 0x{c:08X}")
        e = ASSETS.get(c)
        if e is not None and c + e["len"] <= b:
            inner = [x for x in labels if c < x < c + e["len"]]
            out.append(f".Lspan_{c:08X}:")
            if e.get("include"):
                out.append(f'	.include "{e["file"]}"')
            else:
                out.append(f'	.incbin "build/assets/{c:08X}.bin" @ {e["name"]}')
            for x in inner:
                out.append(f"	.global {m.dname(x)}")
                out.append(f"	.set {m.dname(x)}, .Lspan_{c:08X} + 0x{x - c:X}")
            pos = c + e["len"]


def emit_data_file(path: Path, lo: int, hi: int, m: Model):
    out = ['\t.include "asm/macros.inc"', "", "\t.section .rodata", ""]
    emit_data(out, lo, hi, m, incbin_min=0x40)
    path.write_text("\n".join(out) + "\n", newline="\n")


def split_points(m: Model):
    """File boundaries inside the program segment: the module data blocks (code after a large
    non-code run starts a new file) and every ~96 functions in between, at function starts."""
    funcs = sorted(a for a in m.funcs if TEXT_START <= a < TEXT_END)
    cuts = [TEXT_START]
    count = 0
    prev_end = TEXT_START
    for a in funcs:
        f = m.funcs[a]
        gap = a - prev_end
        if (gap > 0x200 or count >= 96) and a % 4 == 0:
            cuts.append(a)
            count = 0
        count += 1
        prev_end = max(prev_end, f["end"])
    cuts.append(TEXT_END)
    return sorted(set(cuts))


C_MARK = re.compile(r"^//\s*(\w+)\s*@\s*0x([0-9A-Fa-f]{8})\s*$", re.M)


def c_units(m: Model):
    """Decompiled C: every src/**/*.c lists its functions with `// Name @ 0xADDR` lines.  A file's
    functions must be consecutive in the ROM; the unit runs from the first entry to the
    4-aligned end of the last function (agbcc pads with zeros to the next `.align 2`)."""
    units = []
    entries = sorted(a for a in m.funcs)
    for p in sorted((ROOT / "src").rglob("*.c")) if (ROOT / "src").exists() else []:
        marks = [(int(a, 16), n) for n, a in C_MARK.findall(p.read_text(encoding="utf-8"))]
        if not marks:
            continue
        addrs = sorted(a for a, _ in marks)
        for a in addrs:
            if a not in m.funcs:
                raise SystemExit(f"{p}: 0x{a:08X} is not a function entry")
        i = entries.index(addrs[0])
        run = entries[i:i + len(addrs)]
        if run != addrs:
            missing = sorted(set(run) - set(addrs))
            raise SystemExit(f"{p}: functions must be consecutive; missing " +
                             ", ".join(f"0x{x:08X}" for x in missing))
        lo = addrs[0]
        hi = (m.funcs[addrs[-1]]["end"] + 3) & ~3
        if lo % 4:
            raise SystemExit(f"{p}: first function 0x{lo:08X} is not 4-aligned")
        for x in m.data_labels:
            if lo <= x < hi:
                # Fine if only the unit itself refers to it (its own switch tables).
                outside = [l for l in m.lit if m.u32(l) == x and not lo <= l < hi]
                if outside or x in m.syms.by_addr:
                    raise SystemExit(f"{p}: data label 0x{x:08X} lies inside the C unit and is "
                                     f"referenced from outside it")
        units.append((lo, hi, p.relative_to(ROOT).as_posix()))
    return sorted(units)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", default=str(ROOT / "baserom.gba"))
    ap.add_argument("--trace", default=str(ROOT / "build" / "trace.json"))
    ap.add_argument("--out", default=str(ROOT))
    args = ap.parse_args(argv)
    rom = Path(args.rom).read_bytes()
    trace = json.loads(Path(args.trace).read_text())
    syms = symdb.Symbols.load(ROOT / "reference" / "symbols.tsv")
    m = Model(rom, trace, syms)
    texts = Texts()
    items = set()
    em = Emitter(m, texts)
    for a, (n, mode, f) in m.insn.items():
        if em.flow(a, n, mode):
            continue
        items.add((mode, m.rom[a - ROM_BASE:a - ROM_BASE + n]))
    as_path = find_tool("arm-none-eabi-as")
    verify_texts(texts, items, as_path)
    bad = sum(1 for v in texts.ok.values() if v is None)
    print(f"{len(items)} distinct instructions, {bad} kept as raw encodings", file=sys.stderr)
    targets = em.branch_targets()

    out = Path(args.out)
    (out / "asm").mkdir(parents=True, exist_ok=True)
    (out / "data").mkdir(parents=True, exist_ok=True)
    for old in list((out / "asm").glob("code_*.s")) + list((out / "data").glob("rom_*.s")):
        old.unlink()
    layout = []      # (lo, hi, path)

    # Header + crt0.
    emit_code_file(out / "asm" / "crt0.s", ROM_BASE, ROM_BASE + 0x200, m, em, targets)
    layout.append((ROM_BASE, ROM_BASE + 0x200, "asm/crt0.s"))
    # Code that lives outside the program segment gets its own file between data files.
    stray = sorted((f["addr"], f["end"]) for f in m.funcs.values()
                   if not any(lo <= f["addr"] < hi for lo, hi in CODE_REGIONS))

    def data_with_stray(lo, hi):
        a = lo
        for s0, e0 in stray:
            if not lo <= s0 < hi:
                continue
            if s0 > a:
                p = f"data/rom_{a:08X}.s"
                emit_data_file(out / p, a, s0, m)
                layout.append((a, s0, p))
            p = f"asm/code_{s0:08X}.s"
            emit_code_file(out / p, s0, e0, m, em, targets)
            layout.append((s0, e0, p))
            a = e0
        if a < hi:
            p = f"data/rom_{a:08X}.s"
            emit_data_file(out / p, a, hi, m)
            layout.append((a, hi, p))

    # Data before the program.
    data_with_stray(ROM_BASE + 0x200, TEXT_START)
    units = c_units(m)
    cuts = sorted(set(split_points(m)) | {u[0] for u in units} | {u[1] for u in units})
    for lo, hi in zip(cuts, cuts[1:]):
        u = next((u for u in units if u[0] == lo), None)
        if u is not None:
            layout.append((lo, hi, u[2]))
            continue
        if any(u0 < lo < u1 for u0, u1, _ in units):
            continue
        p = f"asm/code_{lo:08X}.s"
        emit_code_file(out / p, lo, hi, m, em, targets)
        layout.append((lo, hi, p))
    # Data after the program, in 1 MB files.
    a = TEXT_END
    end = ROM_BASE + len(rom)
    spans = load_assets()
    while a < end:
        b = min(end, (a & ~0xFFFFF) + 0x100000)
        # Never split a data file inside an asset or include span.
        for s0, e in spans.items():
            if s0 < b < s0 + e["len"]:
                b = s0 + e["len"]
        data_with_stray(a, b)
        a = b
    rows = [f'  {{"start": "0x{lo:08X}", "end": "0x{hi:08X}", "file": "{p}"}}'
            for lo, hi, p in layout]
    (out / "layout.json").write_text("[\n" + ",\n".join(rows) + "\n]\n", newline="\n")
    print(f"{len(layout)} source files, {em.raw_count} raw instructions emitted", file=sys.stderr)


if __name__ == "__main__":
    main()
