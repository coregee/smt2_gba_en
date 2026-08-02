#!/usr/bin/env python3
"""Reposition menu labels by rewriting the hardcoded X/Y draw coordinates.

Every menu label is drawn by `... mov r2,#X; mov r3,#Y; bl FUN_080ac8d0`, where X/Y are
8-bit immediates baked into the code. A label entry in menu_status.json may carry an optional
`"move": [x, y]`; this locates that label's draw call by its ORIGINAL position (kept in
slots[0][1] for X and "y" for Y — those stay as the reference) inside the right draw function,
then rewrites the two immediates to the new coordinates. Editing `move` re-centers a label;
the original coords are never lost.

Runs on the font ROM after the other code patches (it only touches mov-immediate bytes).
"""
import json
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap    # noqa: E402
from text.script import sections  # noqa: E402
from text.script import tr        # noqa: E402

TR = tr.TR
B = rommap.ROM_BASE
DRAW = rommap.Font_DrawGlyph
_md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)

# Which draw function owns a label, keyed by its glyph-literal address range.
# (lit_lo, lit_hi, draw_fn_start) — each fn ends at its literal pool, before lit_lo.
FNS = [
    (0x080CC820, 0x080CC844, 0x080CC7D4),   # base stats   FUN_080cc7d4
    (0x080CC470, 0x080CC4B4, 0x080CBC8C),   # demon combat FUN_080cbc8c
    (0x080CBC50, 0x080CBC8C, 0x080CBB34),   # human combat FUN_080cbb34
]


def fn_for(lit):
    for lo, hi, fn in FNS:
        if lo <= lit < hi:
            return fn
    return None


def draw_calls(rom, fn):
    """Map (X, Y) -> (mov_r2_addr, mov_r3_addr) for each `mov r2,#X; mov r3,#Y; bl DRAW`."""
    out, x, y, xa, ya = {}, None, None, None, None
    for ins in _md.disasm(bytes(rom[fn - B:fn - B + 0x800]), fn):
        m, o = ins.mnemonic, ins.op_str
        if m in ("mov", "movs") and o.startswith("r2, #"):
            x, xa = int(o.split("#")[1], 0), ins.address
        elif m in ("mov", "movs") and o.startswith("r3, #"):
            y, ya = int(o.split("#")[1], 0), ins.address
        elif m == "bl" and o.strip() in (hex(DRAW), f"#{hex(DRAW)}"):
            if x is not None and y is not None:
                out[(x, y)] = (xa, ya)
            x = y = None
        elif m == "bx" or (m == "pop" and "pc" in o):
            break          # end of function — don't disassemble into the literal pool
    return out


def apply(p):
    rom = p.rom
    cache, applied, skipped = {}, 0, 0
    for sec in (s for s in sections.in_pack_order() if s.route == "label"):
        for e in json.loads((TR / f"{sec.id}.json").read_text(encoding="utf-8")):
            if e.get("kind") != "label" or "move" not in e:
                continue
            lit = int(e["slots"][0][0], 16)
            x0, y0 = e["slots"][0][1], e["y"]
            nx, ny = e["move"]
            fn = fn_for(lit)
            if fn is None:
                print(f"  ! {e.get('replace')!r}: no draw fn mapped for 0x{lit:08X}")
                skipped += 1
                continue
            calls = cache.setdefault(fn, draw_calls(rom, fn))
            if (x0, y0) not in calls:
                print(f"  ! {e.get('replace')!r}: original draw @({x0},{y0}) not found in 0x{fn:08X}")
                skipped += 1
                continue
            xa, ya = calls[(x0, y0)]
            assert rom[xa - B + 1] == 0x22 and rom[ya - B + 1] == 0x23, "not a mov-imm pair"
            rom[xa - B] = nx & 0xFF
            rom[ya - B] = ny & 0xFF
            applied += 1
    print(f"repositioned {applied} label(s)" + (f"; {skipped} unresolved" if skipped else ""))
