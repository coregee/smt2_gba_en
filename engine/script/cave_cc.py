#!/usr/bin/env python3
"""Shared helper: compile a freestanding C cave with devkitARM and return a flat Thumb blob.

Used by the C-based code patches (patch_spritebuf.py, patch_skilllist.py, ...).  The C file's
entry must live in section `.text.entry` so it is linked first (at the cave base); the linker
script places .text.entry, then the rest of .text/.rodata.
"""
import shutil
import subprocess
import tempfile
from pathlib import Path

import rom_layout as rommap

# devkitARM (discovered on this machine); fall back to PATH.
DKP_BIN = Path("C:/msys64/opt/devkitpro/devkitARM/bin")


def _tool(name):
    exe = DKP_BIN / f"{name}.exe"
    if exe.exists():
        return str(exe)
    found = shutil.which(name)
    if found:
        return found
    raise SystemExit(f"toolchain not found: {name} (looked in {DKP_BIN} and PATH)")


def build_blob(src: Path, cave: int) -> bytes:
    """Compile + link `src` at absolute address `cave`, objcopy to a flat binary blob."""
    if cave % 4:
        raise SystemExit(f"cave @0x{cave:08X} not 4-byte aligned: word literals / `.word` data "
                         "would be misaligned on ARM7TDMI")
    gcc = _tool("arm-none-eabi-gcc")
    objcopy = _tool("arm-none-eabi-objcopy")
    with tempfile.TemporaryDirectory() as td:
        td = Path(td)
        obj, elf, binf, lds = td / "c.o", td / "c.elf", td / "c.bin", td / "c.ld"
        rommap.write_header(td / "rommap.h")     # shared address defines (RM_*) for the cave .c
        lds.write_text(
            "ENTRY(cave_entry)\n"
            "SECTIONS {\n"
            f"  . = 0x{cave:08X};\n"
            "  .text : { *(.text.entry) *(.text*) *(.rodata*) }\n"
            "  /DISCARD/ : { *(.ARM.exidx*) *(.comment) *(.note*) }\n"
            "}\n"
        )
        subprocess.run(
            [gcc, "-mthumb", "-mcpu=arm7tdmi", "-Os", "-ffreestanding", "-fno-builtin",
             "-fno-toplevel-reorder", "-mlong-calls", f"-I{td}", "-c", str(src), "-o", str(obj)],
            check=True, cwd=td)
        subprocess.run(
            [gcc, "-nostdlib", "-Wl,-T", str(lds), "-Wl,--gc-sections", str(obj), "-o", str(elf)],
            check=True, cwd=td)
        subprocess.run([objcopy, "-O", "binary", str(elf), str(binf)], check=True, cwd=td)
        # symbol -> offset from `cave` (lets a patch bl into a 2nd entry point in the same blob)
        nm = subprocess.run([_tool("arm-none-eabi-nm"), str(elf)],
                            check=True, cwd=td, capture_output=True, text=True).stdout
        syms = {}
        for line in nm.splitlines():
            f = line.split()
            if len(f) == 3 and all(c in "0123456789abcdefABCDEF" for c in f[0]):
                syms[f[2]] = int(f[0], 16) - cave
        return binf.read_bytes(), syms
