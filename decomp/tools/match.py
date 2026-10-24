#!/usr/bin/env python3
"""Check whether a C file reproduces the original functions, without a full build.

    python tools/match.py src/foo.c            per-function OK / DIFF summary
    python tools/match.py src/foo.c --diff     side-by-side disassembly of each differing function

The file is compiled with old_agbcc, assembled, and linked alone at its ROM address. External
symbols resolve to their addresses in the last full build (build/smt2.elf) or, for RAM and
address-named symbols, the same definitions build.py uses.  Everything happens in
build/match/<name>/, so several people (or agents) can work on different C files at once;
only the final `python build.py` integrates them.
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from cc import compile_many  # noqa: E402
from disasm import find_tool, C_MARK  # noqa: E402

BASE = 0x08000000


def rom_symbols():
    """name -> address for every symbol of the last full build."""
    elf = ROOT / "build" / "smt2.elf"
    if not elf.exists():
        raise SystemExit("run `python build.py` once first (needs build/smt2.elf)")
    out = subprocess.run([find_tool("arm-none-eabi-nm"), "--defined-only", str(elf)],
                         capture_output=True, text=True).stdout
    syms = {}
    for ln in out.splitlines():
        p = ln.split()
        if len(p) == 3 and not p[2].startswith(".L") and not p[2].startswith("$"):
            syms[p[2]] = int(p[0], 16)
    return syms


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("--diff", action="store_true")
    args = ap.parse_args()
    src = Path(args.source).resolve().relative_to(ROOT).as_posix()
    text = (ROOT / src).read_text(encoding="utf-8")
    marks = sorted((int(a, 16), n) for n, a in C_MARK.findall(text))
    if not marks:
        raise SystemExit(f"{src}: no `// Name @ 0xADDR` markers")
    trace = {f["addr"]: f for f in json.loads((ROOT / "build" / "trace.json").read_text())["functions"]}
    lo = marks[0][0]
    hi = (trace[marks[-1][0]]["end"] + 3) & ~3
    work = ROOT / "build" / "match" / Path(src).stem
    work.mkdir(parents=True, exist_ok=True)
    msg = compile_many([src], outdir=work)
    if msg.strip():
        print(msg.strip())
    s_file = work / Path(src).with_suffix(".s")
    obj = work / "unit.o"
    r = subprocess.run([find_tool("arm-none-eabi-as"), "-mcpu=arm7tdmi", "--no-pad-sections",
                        "-o", str(obj), str(s_file)], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(r.stderr)
    nm = find_tool("arm-none-eabi-nm")
    defined = set()
    undefined = set()
    for ln in subprocess.run([nm, str(obj)], capture_output=True, text=True).stdout.splitlines():
        p = ln.split()
        if len(p) == 2 and p[0] == "U":
            undefined.add(p[1])
        elif len(p) == 3:
            defined.add(p[2])
    syms = rom_symbols()
    named = {}
    for ln in (ROOT / "reference" / "symbols.tsv").read_text(encoding="utf-8").splitlines()[1:]:
        f = ln.split("\t")
        named[f[1]] = int(f[0], 16)
    defs = []
    missing = []
    for name in sorted(undefined):
        if name in syms:
            defs.append(f"{name} = 0x{syms[name]:08X};")
        elif name in named:
            defs.append(f"{name} = 0x{named[name]:08X};")
        elif re.search(r"_([0-9A-Fa-f]{8})$", name):
            defs.append(f"{name} = 0x{re.search(r'_([0-9A-Fa-f]{8})$', name).group(1).upper()};")
        else:
            missing.append(name)
    if missing:
        raise SystemExit("undefined symbols: " + ", ".join(missing))
    # Thumb functions must be marked as such (.thumb_set), or the linker inserts ARM
    # interworking stubs for calls to them.
    thumb_entries = {f["addr"] for f in trace.values() if f["mode"] == "thumb"}
    stub = []
    for d in defs:
        name, val = d.rstrip(";").split(" = ")
        v = int(val, 16)
        stub.append(f"\t.global {name}")
        stub.append(f"\t.thumb_set {name}, 0x{v:08X}" if v in thumb_entries
                    else f"\t.set {name}, 0x{v:08X}")
    (work / "syms.s").write_text("\n".join(stub) + "\n")
    syms_o = work / "syms.o"
    subprocess.run([find_tool("arm-none-eabi-as"), "-mcpu=arm7tdmi", "-o", str(syms_o),
                    str(work / "syms.s")], check=True)
    lds = work / "unit.ld"
    lds.write_text(f"SECTIONS {{ . = 0x{lo:08X}; .text : {{ {obj.as_posix()}(.text .rodata) }} "
                   f"/DISCARD/ : {{ *(.ARM.attributes) *(.comment) }} }}\n"
                   f"INPUT({syms_o.as_posix()})\n")
    elf = work / "unit.elf"
    r = subprocess.run([find_tool("arm-none-eabi-ld"), "-T", str(lds), "--no-warn-rwx-segments",
                        "-o", str(elf)], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(r.stderr)
    binp = work / "unit.bin"
    subprocess.run([find_tool("arm-none-eabi-objcopy"), "-O", "binary", str(elf), str(binp)],
                   check=True)
    got = binp.read_bytes()
    rom = (ROOT / "baserom.gba").read_bytes()
    want = rom[lo - BASE:hi - BASE]
    got = got + bytes(max(0, len(want) - len(got)))
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
    starts = [a for a, _ in marks]
    names = dict(marks)
    ok = 0
    for i, a in enumerate(starts):
        e = starts[i + 1] if i + 1 < len(starts) else hi
        g, w = got[a - lo:e - lo], want[a - lo:e - lo]
        if g == w:
            ok += 1
            print(f"  OK    {names[a]} @ 0x{a:08X}")
            continue
        first = next(k for k in range(len(w)) if k >= len(g) or g[k] != w[k])
        print(f"  DIFF  {names[a]} @ 0x{a:08X} (first difference at +0x{first:X})")
        if args.diff:
            gl = [f"{x.address:08X} {x.mnemonic} {x.op_str}" for x in md.disasm(g, a)]
            wl = [f"{x.address:08X} {x.mnemonic} {x.op_str}" for x in md.disasm(w, a)]
            for k in range(max(len(gl), len(wl))):
                l1 = gl[k] if k < len(gl) else ""
                l2 = wl[k] if k < len(wl) else ""
                mark = "  " if l1 == l2 else "!!"
                print(f"      {mark} {l1:42s} | {l2}")
    size_note = "" if len(binp.read_bytes()) == hi - lo else \
        f" (compiled size 0x{len(binp.read_bytes()):X}, original 0x{hi - lo:X})"
    print(f"{src}: {ok}/{len(starts)} functions match{size_note}")
    sys.exit(0 if ok == len(starts) and not size_note else 1)


if __name__ == "__main__":
    main()
