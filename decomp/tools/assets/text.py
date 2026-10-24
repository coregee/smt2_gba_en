#!/usr/bin/env python3
"""SMT2 text and event-script banks as editable text that rebuilds byte for byte.

    python tools/assets/text.py extract   ROM -> assets/text/<bank>.txt, then build
    python tools/assets/text.py build     assets/text/<bank>.txt -> <bank>.s + includes.json
    python tools/assets/text.py check     build, then assemble+link every bank at its ROM
                                          address and compare with baserom.gba

The .txt files are the source; the .s files are generated from them (committed so the ROM
build needs no extra step).  Format (docs/text.md has the full description):

    # comment line                       ignored
    @Txt_08009010:                       label (defines a global symbol at this position)
    ある日{n}                             glyphs are written as characters (assets/text/charmap.txt)
    {END} {0} {n} {WAIT} {PAGE} {PAD}    0x0301 0x0000 0x0300 0x0316 0x0317 0x11FE
    {JUMP @Txt_0801A2C4}                 event-VM opcode, operands: 4-hex-digit words or
    {OP_3A7 0001 00FF}                   @Label (a 32-bit stream pointer = two words lo, hi)
    {PTR @Txt_080A1190}  {PTR 08123052}  32-bit pointer (table entry)
    {G:0057}  {W:1A2B}                   a word written raw (non-canonical glyph / non-glyph)

Physical line breaks are cosmetic; every token, including each glyph, is one u16 word except
{PTR} (two).  Operand counts come from text/config/opcode_spec.json (Ghidra-verified handler
layouts) of the translation project.  A pointer operand is written as a label only when it
targets an even address inside these banks; otherwise its words stay as hex, so every byte
round-trips regardless of how well a region is understood.
"""
from __future__ import annotations

import json
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PROJECT = ROOT.parent
sys.path.insert(0, str(HERE.parent))
sys.path.insert(0, str(PROJECT))

BASE = 0x08000000
OUT = ROOT / "assets" / "text"

# Banks: (name, lo, hi, kind).  Boundaries and evidence are in docs/text.md.
BANKS = [
    ("event_a",   0x08009010, 0x08032B7C, "stream"),   # messages + event scripts
    ("event_ptrs", 0x08032BBC, 0x08035CBC, "ptr32"),   # 3136 u32 pointers into the banks
    ("event_b",   0x08035CBC, 0x080A548C, "stream"),   # tables, then messages + event scripts
    ("locations", 0x080A548C, 0x080A96CC, "cells"),    # 530 x 16-word location names
    ("battle",    0x08123038, 0x081267F4, "stream"),   # battle / menu / system strings
]

FIXED = {0x0301: "END", 0x0000: "0", 0x0300: "n", 0x0316: "WAIT", 0x0317: "PAGE", 0x11FE: "PAD",
         0x0057: "_"}
FIXED_REV = {v: k for k, v in FIXED.items()}
OP_LO, OP_HI = 0x0302, 0x0470
UNSAFE = set("{}@#") | {" ", "\t", "\r", "\n"}


# --------------------------------------------------------------------------- tables

def load_glyphs():
    from font.atlas import load_glyph_map
    return load_glyph_map()


def load_spec():
    cfg = PROJECT / "text" / "config"
    spec = {int(k, 16): v for k, v in json.loads((cfg / "opcode_spec.json").read_text("utf-8")).items()}
    args = {int(k, 16): v for k, v in json.loads((cfg / "opcode_args.json").read_text("utf-8")).items()}
    # The decompiled substitution handler (ScriptOp_DrawCharOrSubstitute, src/script_subst.c)
    # reads an operand only for 0x327; the spec's single operand for 0x31A-0x32F and 0x36E would
    # make the next character of the text look like an operand.
    for op in list(range(0x31A, 0x330)) + [0x36E]:
        if op != 0x327 and op in spec and spec[op]["len"] == 1 and not spec[op]["ptr"]:
            spec[op] = dict(spec[op], len=0)
    return spec, args


def op_names():
    """Readable opcode names: the translation project's Ghidra-grounded control-op names and
    substitution aliases; anything else is OP_XXX."""
    names = {}
    try:
        src = (PROJECT / "text" / "script" / "tr.py").read_text("utf-8")
        for block in ("CTRL_OPC = {", "ALIAS_OPC = {"):
            body = src[src.index(block):]
            body = body[:body.index("}")]
            for m in re.finditer(r'(0x[0-9A-Fa-f]+):\s*\'([A-Z0-9_]+)\'', body):
                names[int(m.group(1), 16)] = m.group(2)
            for m in re.finditer(r'"([A-Z0-9_]+)":\s*(0x[0-9A-Fa-f]+)', body):
                names[int(m.group(2), 16)] = m.group(1)
    except (OSError, ValueError):
        pass
    for code, n in {0x031A: "ALEPH", 0x031B: "HIROKO", 0x031C: "ZAYIN", 0x031D: "GIMMEL",
                    0x036E: "MACCA"}.items():
        names[code] = n
    # Names must not collide with the fixed tokens or each other.
    seen = set(FIXED_REV) | {"PTR", "G", "W"}
    out = {}
    for code in sorted(names):
        n = names[code]
        if n in seen:
            n = f"{n}_{code:03X}"
        seen.add(n)
        out[code] = n
    return out


class Charmap:
    def __init__(self, glyphs: dict):
        self.code2ch = {}
        self.ch2code = {}
        for code in sorted(glyphs):
            ch = glyphs[code]
            if OP_LO <= code <= OP_HI or code in FIXED:
                continue
            if len(ch) != 1 or ch in UNSAFE:
                continue
            if ch not in self.ch2code:
                self.ch2code[ch] = code
                self.code2ch[code] = ch

    def write(self, path: Path, glyphs: dict):
        lines = ["# SMT2 glyph code -> character (from the translation project's curated atlas).",
                 "# Canonical codes are written as the character; other codes as {G:XXXX}.",
                 "# Non-glyph words: {n}=0300 {END}=0301 {0}=0000 {WAIT}=0316 {PAGE}=0317 {PAD}=11FE,",
                 "# opcodes 0302-0470 as {NAME operands}, other words as {W:XXXX}.",
                 "# code\tchar\tcanonical"]
        for code in sorted(glyphs):
            ch = glyphs[code]
            canon = "yes" if self.code2ch.get(code) == ch else "no"
            lines.append(f"{code:04X}\t{ch}\t{canon}")
        path.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")


# --------------------------------------------------------------------------- decoding

class Rom:
    def __init__(self, data):
        self.data = data

    def w(self, a):
        o = a - BASE
        return self.data[o] | self.data[o + 1] << 8

    def u32(self, a):
        return self.w(a) | self.w(a + 2) << 16


def in_banks(t):
    return any(lo <= t < hi for _, lo, hi, _ in BANKS) and not t & 1


def op_layout(rom, a, c, spec, args):
    """(size_bytes, [hi-word indexes of pointers]) of the opcode at a (operand-relative)."""
    s = spec.get(c)
    if s is None:
        n = args.get(c) or 0
        return 2 + 2 * n, []
    var = s.get("var")
    if var:
        hdr = s["len"]
        count = rom.w(a + 2 + 2 * var["count_word"])
        rows = (count >> 8) + 1
        stride = var["stride"]
        lo = var["row_ptr"][0]
        ptrs = [hdr + r * stride + lo + 1 for r in range(rows)]
        return 2 + 2 * hdr + 2 * rows * stride, ptrs
    return 2 + 2 * s["len"], list(s["ptr"])


def tokenize(rom, lo, hi, kind, ctx, bounds):
    """Token list for [lo, hi).  Token = (addr, size, kind, payload).  `bounds`: addresses that
    must start a token (pointer targets); an opcode or pointer pair spanning one is split."""
    toks = []
    a = lo
    spec, args = ctx["spec"], ctx["args"]

    def clear(a, size):
        return not any(b in bounds for b in range(a + 2, a + size, 2))

    if kind == "ptr32":
        while a < hi:
            toks.append((a, 4, "ptr", rom.u32(a)))
            a += 4
        return toks
    while a < hi:
        c = rom.w(a)
        if kind == "stream" and OP_LO <= c <= OP_HI and c not in FIXED:
            size, ptrs = op_layout(rom, a, c, spec, args)
            if a + size <= hi and clear(a, size):
                words = [rom.w(a + 2 + 2 * i) for i in range((size - 2) // 2)]
                toks.append((a, size, "op", (c, words, ptrs)))
                a += size
                continue
        # Pointer arrays / record tables inside the banks: >= 3 pointer pairs at one stride.
        if kind == "stream" and is_ptr(rom, a, hi) and clear(a, 4) and (
                a in ctx.get("ptrrun", ()) or any(
                    all(is_ptr(rom, a + st * k, hi) for k in range(1, 3)) for st in STRIDES)):
            for st in STRIDES:
                if all(is_ptr(rom, a + st * k, hi) for k in range(1, 3)):
                    ctx.setdefault("ptrrun", set()).update(a + st * k for k in range(1, 3))
            toks.append((a, 4, "ptr", rom.u32(a)))
            a += 4
            continue
        toks.append((a, 2, "word", c))
        a += 2
    return toks


STRIDES = (4, 6, 8, 10, 12)


def is_ptr(rom, a, hi):
    return a + 4 <= hi and 0x0800 <= rom.w(a + 2) <= 0x080A and in_banks(rom.u32(a))


def pointer_targets(toks):
    out = set()
    for a, size, k, p in toks:
        if k == "ptr" and in_banks(p):
            out.add(p)
        elif k == "op":
            c, words, ptrs = p
            for i in ptrs:
                if 1 <= i < len(words):
                    t = words[i - 1] | words[i] << 16
                    if in_banks(t):
                        out.add(t)
    return out


def label(t):
    return f"Txt_{t:08X}"


def render(toks, ctx, labels, kind):
    cm, names = ctx["charmap"], ctx["names"]
    out = []
    line = []

    def flush():
        if line:
            out.append("".join(line))
            line.clear()

    cell = 0
    for a, size, k, p in toks:
        if a in labels:
            flush()
            out.append(f"@{label(a)}:")
        if kind == "cells" and (a - ctx["lo"]) % 0x20 == 0:
            flush()
            out.append(f"# cell {cell}")
            cell += 1
        if k == "ptr":
            line.append("{PTR @%s}" % label(p) if p in labels else "{PTR %08X}" % p)
            flush()
        elif k == "op":
            c, words, ptrs = p
            parts = [names.get(c, f"OP_{c:03X}")]
            i = 0
            his = set(ptrs)
            while i < len(words):
                if i + 1 in his and i + 1 < len(words) and (words[i] | words[i + 1] << 16) in labels:
                    parts.append("@" + label(words[i] | words[i + 1] << 16))
                    i += 2
                else:
                    parts.append(f"{words[i]:04X}")
                    i += 1
            line.append("{" + " ".join(parts) + "}")
        else:
            c = p
            if c == 0x0057 and kind != "cells":
                line.append(cm.code2ch[c] if c in cm.code2ch else "{_}")
            elif c in FIXED and (kind != "cells" or c == 0x0057):
                line.append("{" + FIXED[c] + "}")
                if c in (0x0301, 0x0000, 0x0300):
                    flush()
            elif c in cm.code2ch:
                line.append(cm.code2ch[c])
            elif c <= 0x11FF:
                line.append(f"{{G:{c:04X}}}")
            else:
                line.append(f"{{W:{c:04X}}}")
    flush()
    return out


# --------------------------------------------------------------------------- parsing

TOKEN_RE = re.compile(r"\{([^{}]*)\}")


def parse(text: str, ctx):
    """.txt -> list of items: ('label', name) | ('w', word) | ('ptr', label_or_int)."""
    cm = ctx["charmap"]
    rev = {v: k for k, v in ctx["names"].items()}
    items = []
    for ln, line in enumerate(text.split("\n"), 1):
        if line.startswith("#") or not line:
            continue
        if line.startswith("@") and line.endswith(":"):
            items.append(("label", line[1:-1]))
            continue
        i = 0
        while i < len(line):
            ch = line[i]
            if ch == "{":
                j = line.index("}", i)
                body = line[i + 1:j].split()
                i = j + 1
                if not body:
                    raise ValueError(f"line {ln}: empty token")
                head = body[0]
                if head in FIXED_REV and len(body) == 1:
                    items.append(("w", FIXED_REV[head]))
                elif head.startswith("G:") or head.startswith("W:"):
                    items.append(("w", int(head[2:], 16)))
                elif head == "PTR":
                    v = body[1]
                    items.append(("ptr", v[1:] if v.startswith("@") else int(v, 16)))
                else:
                    if head in rev:
                        code = rev[head]
                    elif head.startswith("OP_"):
                        code = int(head[3:], 16)
                    else:
                        raise ValueError(f"line {ln}: unknown token {{{head}}}")
                    items.append(("w", code))
                    for arg in body[1:]:
                        if arg.startswith("@"):
                            items.append(("ptr", arg[1:]))
                        else:
                            items.append(("w", int(arg, 16)))
            else:
                code = cm.ch2code.get(ch)
                if code is None:
                    raise ValueError(f"line {ln}: no glyph for {ch!r}")
                items.append(("w", code))
                i += 1
    return items


def to_asm(items, name, lo, hi):
    """Items -> GNU as source (no section/alignment directives: it is .include'd)."""
    out = [f"@ Generated by tools/assets/text.py from assets/text/{name}.txt; edit that file.",
           f"@ ROM 0x{lo:08X}-0x{hi:08X}"]
    words = []

    def flush():
        while words:
            chunk, words[:] = words[:8], words[8:]
            out.append("\t.2byte " + ", ".join(f"0x{w:04X}" for w in chunk))

    size = 0
    for kind, v in items:
        if kind == "label":
            flush()
            out.append(f"\t.global {v}")
            out.append(f"{v}:")
        elif kind == "w":
            words.append(v)
            size += 2
        else:
            flush()
            out.append(f"\t.4byte {v}" if isinstance(v, str) else f"\t.4byte 0x{v:08X}")
            size += 4
    flush()
    if size != hi - lo:
        raise ValueError(f"{name}: source encodes 0x{size:X} bytes, bank is 0x{hi - lo:X}")
    return "\n".join(out) + "\n"


def items_bytes(items, labels):
    b = bytearray()
    for kind, v in items:
        if kind == "w":
            b += struct.pack("<H", v)
        elif kind == "ptr":
            b += struct.pack("<I", labels[v] if isinstance(v, str) else v)
    return bytes(b)


# --------------------------------------------------------------------------- commands

def context():
    glyphs = load_glyphs()
    spec, args = load_spec()
    return {"charmap": Charmap(glyphs), "glyphs": glyphs, "spec": spec, "args": args,
            "names": op_names()}


def extract():
    rom = Rom((ROOT / "baserom.gba").read_bytes())
    ctx = context()
    OUT.mkdir(parents=True, exist_ok=True)
    ctx["charmap"].write(OUT / "charmap.txt", ctx["glyphs"])
    # Pass 1: pointer targets with no forced boundaries; pass 2 tokenizes with them.
    bounds = set()
    for name, lo, hi, kind in BANKS:
        bounds |= pointer_targets(tokenize(rom, lo, hi, kind, ctx, set()))
    for _ in range(4):
        toks_by = {}
        new = set()
        for name, lo, hi, kind in BANKS:
            toks = tokenize(rom, lo, hi, kind, ctx, bounds)
            toks_by[name] = toks
            new |= pointer_targets(toks)
        starts = {a for toks in toks_by.values() for a, *_ in toks}
        new &= starts | bounds
        if new <= bounds:
            break
        bounds |= new
    starts = {a for toks in toks_by.values() for a, *_ in toks}
    labels = {t for t in bounds if t in starts}
    for name, lo, hi, kind in BANKS:
        ctx["lo"] = lo
        body = render(toks_by[name], ctx, labels, kind)
        head = [f"# {name}: ROM 0x{lo:08X}-0x{hi:08X} ({kind}). Edit, then run text.py build.",
                "# Format: see the docstring of tools/assets/text.py and docs/text.md."]
        (OUT / f"{name}.txt").write_text("\n".join(head + body) + "\n", encoding="utf-8", newline="\n")
    stats = {name: sum(1 for t in toks_by[name] if t[2] == "word" and t[3] == 0x0301)
             for name, *_ in BANKS}
    print(f"extracted {len(BANKS)} banks, {len(labels)} labels; END counts {stats}")
    build(ctx)


def build(ctx=None):
    ctx = ctx or context()
    includes = []
    all_items = {}
    for name, lo, hi, kind in BANKS:
        items = parse((OUT / f"{name}.txt").read_text("utf-8"), ctx)
        all_items[name] = items
        (OUT / f"{name}.s").write_text(to_asm(items, name, lo, hi), encoding="utf-8", newline="\n")
        includes.append({"addr": f"0x{lo:08X}", "len": hi - lo, "file": f"assets/text/{name}.s"})
    (OUT / "includes.json").write_text(
        "[\n" + ",\n".join("  " + json.dumps(e) for e in includes) + "\n]\n", newline="\n")
    print(f"built {len(includes)} banks -> assets/text/*.s, includes.json")
    return all_items


def check():
    from disasm import find_tool
    ctx = context()
    all_items = build(ctx)
    rom = (ROOT / "baserom.gba").read_bytes()
    # Fast check: resolve labels by position and compare bytes directly.
    labels = {}
    for name, lo, hi, kind in BANKS:
        a = lo
        for k, v in all_items[name]:
            if k == "label":
                labels[v] = a
            else:
                a += 2 if k == "w" else 4
    ok = True
    for name, lo, hi, kind in BANKS:
        got = items_bytes(all_items[name], labels)
        if got != rom[lo - BASE:hi - BASE]:
            i = next(i for i in range(len(got)) if got[i] != rom[lo - BASE + i])
            print(f"  {name}: differs at 0x{lo + i:08X}")
            ok = False
    # Real toolchain check: assemble each bank, link all at their addresses, compare.
    asm, ld, objcopy = (find_tool(t) for t in ("arm-none-eabi-as", "arm-none-eabi-ld",
                                                 "arm-none-eabi-objcopy"))
    with tempfile.TemporaryDirectory() as td:
        td = Path(td)
        secs = []
        for name, lo, hi, kind in BANKS:
            src = td / f"{name}_wrap.s"
            src.write_text(f'\t.section .t_{name},"a"\n\t.include "assets/text/{name}.s"\n')
            subprocess.run([asm, "-mcpu=arm7tdmi", "-I", str(ROOT), "-o", str(td / f"{name}.o"),
                            str(src)], check=True, cwd=ROOT)
            secs.append(f"  .t_{name} 0x{lo:08X} : {{ {name}.o(.t_{name}) }}")
        (td / "l.ld").write_text("SECTIONS {\n" + "\n".join(secs) + "\n}\n")
        subprocess.run([ld, "-T", "l.ld", "-o", "t.elf"] + [f"{n}.o" for n, *_ in BANKS],
                       check=True, cwd=td)
        for name, lo, hi, kind in BANKS:
            subprocess.run([objcopy, "-O", "binary", "-j", f".t_{name}", "t.elf", f"{name}.bin"],
                           check=True, cwd=td)
            got = (td / f"{name}.bin").read_bytes()
            same = got == rom[lo - BASE:hi - BASE]
            ok &= same
            print(f"  {name:10s} 0x{lo:08X}-0x{hi:08X} {hi - lo:7d} bytes: "
                  f"{'OK' if same else 'MISMATCH'}")
    print("check:", "OK" if ok else "FAILED")
    return 0 if ok else 1


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "check"
    if cmd == "extract":
        extract()
    elif cmd == "build":
        build()
    elif cmd == "check":
        sys.exit(check())
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main()
