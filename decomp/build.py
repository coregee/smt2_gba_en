#!/usr/bin/env python3
"""Build the SMT2 GBA decompilation into a ROM and compare it with the original.

    python build.py            assemble + link + compare (uses the committed sources)
    python build.py --regen    re-run discovery and regenerate asm/ and data/ first

The original ROM is read from ../rom/Shin Megami Tensei II (Japan).gba (the translation
project's local-only input) and copied to baserom.gba, which the data files .incbin from.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tools"))
from disasm import find_tool  # noqa: E402

BASEROM_SHA1 = "8a4a52eb5538d52762337ca045e5c85e00f19ff0"
SOURCE_ROM = ROOT.parent / "rom" / "Shin Megami Tensei II (Japan).gba"
BUILD = ROOT / "build"


def ensure_baserom():
    dst = ROOT / "baserom.gba"
    if not dst.exists():
        if not SOURCE_ROM.exists():
            raise SystemExit(f"place the Japanese ROM at {SOURCE_ROM}")
        shutil.copyfile(SOURCE_ROM, dst)
    h = hashlib.sha1(dst.read_bytes()).hexdigest()
    if h != BASEROM_SHA1:
        raise SystemExit(f"baserom.gba sha1 {h} != {BASEROM_SHA1}")
    return dst


def regen(py):
    rom = ensure_baserom()
    run([py, str(ROOT / "tools" / "trace.py"), str(rom), "-o", str(BUILD / "trace.json")])
    run([py, str(ROOT / "tools" / "disasm.py")])


def run(cmd, quiet_warnings=(), **kw):
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit(f"failed: {' '.join(map(str, cmd))}")
    lines = [ln for ln in r.stderr.splitlines()
             if ln.strip() and not ln.endswith("Assembler messages:")
             and not any(q in ln for q in quiet_warnings)]
    if lines:
        sys.stderr.write("\n".join(lines) + "\n")
    return r


def source_list():
    """Every source file in ROM order: generated asm/data plus decompiled C in src/."""
    layout = json.loads((ROOT / "layout.json").read_text())
    return [entry["file"] for entry in layout]


def ensure_extracted():
    """Extracted binaries are not committed; recreate them from baserom.gba when missing."""
    manifest = json.loads((ROOT / "assets" / "manifest.json").read_text())["assets"]
    first = manifest[0]
    ext = {"4bpp": ".png", "8bpp": ".png", "pal": ".pal"}.get(first["format"], ".bin")
    if not (ROOT / "assets" / (first["name"] + ext)).exists():
        run([sys.executable, str(ROOT / "tools" / "assets" / "assets.py"), "extract"])
    samples = ROOT / "assets" / "sound" / "samples"
    if (ROOT / "assets" / "sound" / "includes.json").exists() and not any(samples.glob("*.wav")):
        run([sys.executable, str(ROOT / "tools" / "assets" / "m4a.py"), "extract"])


def symbol_definitions(objs):
    """Absolute definitions for symbols C refers to that no source defines: RAM variables and
    any `*_XXXXXXXX` address-named symbol (gUnk_030031BC), plus ram/data names from
    reference/symbols.tsv."""
    import re
    nm = find_tool("arm-none-eabi-nm")
    c_objs = [str(o) for o in objs if (BUILD / "src") in o.parents]
    if not c_objs:
        return ""
    undefined = set()
    out = subprocess.run([nm, "-u"] + c_objs, capture_output=True, text=True).stdout
    for ln in out.splitlines():
        parts = ln.split()
        if parts and parts[0] == "U":
            undefined.add(parts[1])
    defined = set()
    out = subprocess.run([nm, "--defined-only"] + [str(o) for o in objs], capture_output=True,
                         text=True).stdout
    for ln in out.splitlines():
        parts = ln.split()
        if len(parts) == 3:
            defined.add(parts[2])
    named = {}
    for ln in (ROOT / "reference" / "symbols.tsv").read_text(encoding="utf-8").splitlines()[1:]:
        f = ln.split("\t")
        if f[2] in ("ram", "data"):
            named[f[1]] = int(f[0], 16)
    lines = []
    for name in sorted(undefined - defined):
        m = re.search(r"_([0-9A-Fa-f]{8})$", name)
        if name in named:
            lines.append(f"{name} = 0x{named[name]:08X};")
        elif m:
            lines.append(f"{name} = 0x{m.group(1).upper()};")
    return "\n".join(lines) + "\n"


def build():
    ensure_baserom()
    ensure_extracted()
    run([sys.executable, str(ROOT / "tools" / "assets" / "assets.py"), "build"])
    if (ROOT / "assets" / "text" / "includes.json").exists():
        run([sys.executable, str(ROOT / "tools" / "assets" / "text.py"), "build"])
    if (ROOT / "assets" / "sound" / "includes.json").exists():
        run([sys.executable, str(ROOT / "tools" / "assets" / "m4a.py"), "build"])
    asm = find_tool("arm-none-eabi-as")
    ld = find_tool("arm-none-eabi-ld")
    objcopy = find_tool("arm-none-eabi-objcopy")
    files = source_list()
    objs = []
    # Decompiled C: compile what changed (one WSL call), then assemble like any other source.
    from cc import compile_many
    stale = []
    for src in files:
        if src.endswith(".c"):
            out_s = BUILD / Path(src).with_suffix(".s")
            deps = [(ROOT / src).stat().st_mtime] + [h.stat().st_mtime for h in
                                                     (ROOT / "include").rglob("*.h")]
            if not out_s.exists() or out_s.stat().st_mtime <= max(deps):
                stale.append(src)
    msg = compile_many(stale)
    if msg.strip():
        sys.stderr.write(msg)

    asset_dir = BUILD / "assets"
    newest_asset = max((p.stat().st_mtime for p in asset_dir.glob("*.bin")), default=0)

    def assemble(src):
        obj = BUILD / Path(src).with_suffix(".o")
        obj.parent.mkdir(parents=True, exist_ok=True)
        s = ROOT / src
        if src.endswith(".c"):
            s = BUILD / Path(src).with_suffix(".s")
            if obj.exists() and obj.stat().st_mtime > s.stat().st_mtime:
                return obj
            run([asm, "-mcpu=arm7tdmi", "--no-pad-sections", "-o", str(obj), str(s)])
            return obj
        deps = [s.stat().st_mtime, (ROOT / "asm" / "macros.inc").stat().st_mtime]
        if src.startswith("data/") or src.startswith("asm/code_"):
            deps.append(newest_asset)      # .incbin of build/assets/*.bin
        if obj.exists() and obj.stat().st_mtime > max(deps):
            return obj
        run([asm, "-mcpu=arm7tdmi", "--no-pad-sections", "-I", ".", "-o", str(obj), src],
            quiet_warnings=("section does not have enough alignment",))
        return obj

    with ThreadPoolExecutor() as ex:
        objs = list(ex.map(assemble, files))
    syms = BUILD / "syms.ld"
    syms.write_text(symbol_definitions(objs))
    lds = BUILD / "ld_script.ld"
    body = "\n".join(f"        {o.relative_to(ROOT).as_posix()}(.text .rodata .data)" for o in objs)
    lds.write_text(f"""OUTPUT_ARCH(arm)
ENTRY(Start)
SECTIONS
{{
    . = 0x08000000;
    .rom : {{
{body}
    }}
    /DISCARD/ : {{ *(.ARM.attributes) *(.comment) }}
}}
INCLUDE {syms.relative_to(ROOT).as_posix()}
""")
    elf = BUILD / "smt2.elf"
    run([ld, "-T", str(lds), "-Map", str(BUILD / "smt2.map"), "--no-warn-rwx-segments",
         "-o", str(elf)])
    out = BUILD / "smt2.gba"
    run([objcopy, "-O", "binary", str(elf), str(out)])
    got = out.read_bytes()
    want = (ROOT / "baserom.gba").read_bytes()
    h = hashlib.sha1(got).hexdigest()
    if got == want:
        print(f"{out.relative_to(ROOT)}: OK (sha1 {h})")
        return 0
    n = min(len(got), len(want))
    first = next((i for i in range(n) if got[i] != want[i]), n)
    diffs = sum(1 for i in range(n) if got[i] != want[i])
    print(f"{out.relative_to(ROOT)}: MISMATCH sha1 {h}; size {len(got):#x} vs {len(want):#x}, "
          f"{diffs} differing bytes, first at 0x{0x08000000 + first:08X}")
    # Name the functions that differ (usually the C you just changed).
    try:
        fm = [ln.split("\t") for ln in
              (ROOT / "reference" / "function-map.tsv").read_text().splitlines()[1:]]
        bad = set()
        for i in range(n):
            if got[i] != want[i]:
                a = 0x08000000 + i
                for row in fm:
                    s0 = int(row[0], 16)
                    if s0 <= a < s0 + int(row[2]):
                        bad.add((s0, row[3] or f"sub_{s0:08X}"))
                        break
                if len(bad) > 20:
                    break
        for s0, name in sorted(bad):
            print(f"  differs: {name} @ 0x{s0:08X}")
    except OSError:
        pass
    return 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--regen", action="store_true")
    args = ap.parse_args()
    if args.regen:
        regen(sys.executable)
    sys.exit(build())


if __name__ == "__main__":
    main()
