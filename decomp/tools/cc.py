#!/usr/bin/env python3
"""Compile decompiled C with the original compiler.

The game code was built with the GCC 2.9 Thumb compiler that pret ships as `agbcc`; the
Nintendo SDK's precompiled m4a library with the older one, `old_agbcc` (see
docs/matching.md).  A C file selects the old compiler with a line `// compiler: old_agbcc`
in its first lines.  It runs in WSL:

    cpp -nostdinc -undef -I include src/x.c | agbcc -mthumb-interwork -O2 -fhex-asm

and the resulting assembly is assembled on Windows by arm-none-eabi-as like the rest of the
build.  AGBCC_DIR overrides the directory holding the compilers (a path inside WSL).

    python tools/cc.py src/foo.c ...        compile to build/src/*.s
"""
from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AGBCC_DIR = os.environ.get("AGBCC_DIR", "~/work/agbcc")


def compiler_for(src) -> str:
    """agbcc, unless the file asks for old_agbcc in its first lines."""
    head = (ROOT / src).read_text(encoding="utf-8").splitlines()[:5]
    for ln in head:
        if ln.strip().startswith("// compiler:"):
            return f"{AGBCC_DIR}/{ln.split(':', 1)[1].strip()}"
    return os.environ.get("AGBCC", f"{AGBCC_DIR}/agbcc")
CFLAGS = "-mthumb-interwork -O2 -fhex-asm -Wimplicit -Wparentheses"


def wsl_path(p: Path) -> str:
    p = p.resolve()
    drive = p.drive.rstrip(":").lower()
    return f"/mnt/{drive}" + p.as_posix()[2:]


def compile_many(sources, outdir=None):
    """Compile .c files (repo-relative) to <outdir or build>/src/*.s in one WSL call.
    Returns the compiler's messages."""
    if not sources:
        return ""
    base = Path(outdir) if outdir else ROOT / "build"
    lines = ["set -e -o pipefail", f"cd {wsl_path(ROOT)}"]
    for src in sources:
        out = base / Path(src).with_suffix(".s")
        out.parent.mkdir(parents=True, exist_ok=True)
        lines.append(f"cpp -nostdinc -undef -P -I include {src} | {compiler_for(src)} {CFLAGS} -o "
                     f"{wsl_path(out)}")
    import uuid
    script = ROOT / "build" / f"cc_{uuid.uuid4().hex[:8]}.sh"
    script.parent.mkdir(parents=True, exist_ok=True)
    script.write_text("\n".join(lines) + "\n", newline="\n")
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    r = subprocess.run(["wsl.exe", "-d", "Ubuntu", "--", "bash", wsl_path(script)],
                       capture_output=True, env=env)
    text = (r.stdout + r.stderr).decode("utf-8", "replace").replace("\x00", "")
    script.unlink(missing_ok=True)
    if r.returncode:
        raise SystemExit(f"C compile failed:\n{text}")
    # agbcc ends a file without padding; when the last function ends at 2 mod 4, the
    # assembler would pad the section with a Thumb nop where the ROM has zeros.
    for src in sources:
        out = base / Path(src).with_suffix(".s")
        out.write_text(out.read_text() + "\t.align 2, 0\n", newline="\n")
    return text


if __name__ == "__main__":
    print(compile_many(sys.argv[1:]))
