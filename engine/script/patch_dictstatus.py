#!/usr/bin/env python3
"""DDS demon-dictionary STATUS screen stat labels -> English (patch_dictstatus).

The full-info detail screen's STATUS panel draws its kanji stat labels glyph-by-glyph with
Font_DrawGlyphTinted (0x080ac980) from a per-glyph literal pool @0x080dcbac -- the SAME mechanism
the equip stat-preview panel (patch_statpage) and status screen (menu_status) use, so the same
pointer trick works: patch_menutinted hooks Font_DrawGlyphTinted so a "code" arg that is a ROM
POINTER renders the pooled English string VWF.  Each label's first-glyph slot is repointed to a
pooled English string; continuation slots point at an empty string (draw nothing).  Vocabulary
matches menu_status / patch_statpage so the labels read identically everywhere.

Layout (drawer @0x080dc8xx-0x080dcb40; x,y are panel-local):
  base stats  力(85,14) 知(126,14) 魔(85,29) 体(126,29) 速(85,44) 運(126,44)  -> St In Ma Vi Ag Lu
  derived     攻撃(4,80) 命中(4,95) 防御(4,110) 回避(4,125)                    -> Atk Hit Def Eva
  magic       魔法威力(85,80) 魔法効果(85,95)                                  -> "Mag Pwr" "Mag Efc"

Shared-literal conflict (like statpage's 攻撃/攻撃回数): the magic labels reuse the base-stat 魔
(loaded into r6 @0x080dc98e) and 力 (loaded into r8 @0x080dc954) literals, plus a shared 法 (r5).
Repointing 魔->Ma and 力->St is correct for the base stats; the magic draws that reuse r6/r8 are
redirected by three micro-caves (statpage "Hits" pattern -- replace `mov r0,rN; mov r1,sl` with a
`bl` that loads the independent pointer and redoes r1=canvas):
  - 0x080dcaba (魔法威力 first glyph, r6) -> "Mag Pwr"
  - 0x080dcb06 (魔法効果 first glyph, r6) -> "Mag Efc"
  - 0x080dcae6 (魔法威力 4th glyph 力, r8 = "St") -> empty (the full "Mag Pwr" already covers it)
The non-shared magic continuations (法/威/効/果) blank via their own literal slots.

Run AFTER patch_menutinted.py (needs the Font_DrawGlyphTinted pointer hook).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from text.script import tr
from engine.script.cave_builders import sidecar_cave

FARDATA = rommap.FARDATA_DICTSTATLABELS
CEILING = rommap.FARDATA_VISION   # next far-data region — overrunning it corrupts "Extract a vision"

# (literal slot, expected JP glyph token, English) -> repoint first-glyph slot to a pooled EN string.
LABELS = [
    (0x080DCBAC, 0x10CB, "St"),    # 力 STR   (also r8 -> magic 力, caved below)
    (0x080DCBB0, 0x0CBA, "In"),    # 知 INT
    (0x080DCBB4, 0x0FC3, "Ma"),    # 魔 MAG   (also r6 -> magic 魔, caved below)
    (0x080DCBB8, 0x0C5C, "Vi"),    # 体 VIT
    (0x080DCBBC, 0x0C3C, "Ag"),    # 速 AGI
    (0x080DCBC0, 0x0606, "Lu"),    # 運 LUK
    (0x080DCBC4, 0x08F1, "Attack"),   # 攻撃
    (0x080DCBCC, 0x0FFE, "Accuracy"),   # 命中
    (0x080DCBD4, 0x0FA9, "Defense"),   # 防御
    (0x080DCBDC, 0x0699, "Evasion"),   # 回避
]

# continuation glyph slots -> empty string (draw nothing).
BLANKS = [
    (0x080DCBC8, 0x0861),  # 撃
    (0x080DCBD0, 0x0CD3),  # 中
    (0x080DCBD8, 0x08C3),  # 御
    (0x080DCBE0, 0x0EB7),  # 避
    (0x080DCBE4, 0x0F81),  # 法 (shared by both magic labels)
    (0x080DCBE8, 0x05BB),  # 威
    (0x080DCBEC, 0x08D7),  # 効
    (0x080DCBF0, 0x0672),  # 果
]

# magic-label shared-register draw sites: replace `mov r0,rN ; mov r1,sl` (4 bytes) with `bl cave`.
# cave: ldr r0,=ptr ; mov r1,r10 (canvas) ; bx lr  (returns to the movs r2/r3 + draw tail).
MAGIC_SITES = [
    (0x080DCABA, bytes.fromhex("301c5146"), "Mag Pwr"),  # adds r0,r6,#0 ; mov r1,sl
    (0x080DCB06, bytes.fromhex("301c5146"), "Mag Efc"),  # adds r0,r6,#0 ; mov r1,sl
    (0x080DCAE6, bytes.fromhex("40465146"), ""),         # mov r0,r8 ; mov r1,sl  (-> blank)
]

# cave: r0 = pooled EN string ptr, redo `mov r1,r10` (canvas/sl), bx lr (shared sidecar_cave).


def apply(p):
    far = [FARDATA]
    pool = {}

    def strptr(s):
        if s not in pool:
            blob = tr.encode(s) + b"\x00\x00"
            addr = far[0]
            if addr + len(blob) > CEILING:
                raise SystemExit(f"patch_dictstatus: pool overruns FARDATA_VISION (0x{CEILING:08X})")
            p.write(addr, blob)
            pool[s] = addr
            far[0] = addr + len(blob)
        return pool[s]

    empty = strptr("")

    for addr, tok, en in LABELS:
        cur = int.from_bytes(p.read(addr, 4), "little")
        if cur != tok:
            raise SystemExit(f"patch_dictstatus: label @0x{addr:08X}: expected 0x{tok:04X}, found 0x{cur:08X}")
        p.write(addr, strptr(en).to_bytes(4, "little"))

    for addr, tok in BLANKS:
        cur = int.from_bytes(p.read(addr, 4), "little")
        if cur != tok:
            raise SystemExit(f"patch_dictstatus: blank @0x{addr:08X}: expected 0x{tok:04X}, found 0x{cur:08X}")
        p.write(addr, empty.to_bytes(4, "little"))

    for site, old, en in MAGIC_SITES:
        ptr = empty if en == "" else strptr(en)
        sidecar_cave(p, name=f"dictstat:{en or 'blank'}", hook=site, hook_old=old, ptr=ptr,
                     redo="mov r1, r10", bl_name=f"dictstatus magic @0x{site:08X}")

    print(f"dictstatus: {len(LABELS)} labels + {len(BLANKS)} blanks EN, 2 magic + 1 blank cave; "
          f"pool @0x{FARDATA:08X}")
