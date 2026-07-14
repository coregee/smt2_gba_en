#!/usr/bin/env python3
"""Mirror the Latin/English glyphs into their code+0x200 "name-variant" slots.

Some list-row name drawers — notably FUN_08153fc8 (the Cathedral fusion candidate names) — render each
glyph as `Font_GetGlyphBitmap(code + 0x200)`, i.e. a second copy of every name glyph kept in a parallel
font bank (bank index +2).  The base JP glyphs exist in that bank; the injected English glyphs
(0xBC-0x117) do NOT, so a +0x200 drawer lands on the stale bank-2 symbols (greek/math) and the English
text renders as garbage.  Other drawers (Font_DrawGlyphTinted, used by the status/comp menus) read the
glyph directly and are unaffected — which is why English looked correct there but not in the fusion list.

Copy each FINALIZED English glyph (both 2bpp strips) to its code+0x200 slot so the +0x200 drawers render
English too.  Only the name-variants of 0xBC-0x117 are touched; the JP katakana name-variants (0x37A+)
are left intact, so untranslated demon names still draw correctly.

Run AFTER patch_vwf.py (it left-aligns the English glyphs; we mirror the left-aligned result).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from font.script.font_codec import main_glyph_offset


def apply(p):
    n = 0
    for code in range(rommap.ENG_LO, rommap.ENG_HI):          # 0xBC..0x117 (English glyph codes)
        src = main_glyph_offset(p.rom, code)
        dst = main_glyph_offset(p.rom, code + 0x200)    # parallel name-variant bank
        p.rom[dst:dst + 0x20] = p.rom[src:src + 0x20]                    # TL/TR (top strip)
        p.rom[dst + 0x200:dst + 0x220] = p.rom[src + 0x200:src + 0x220]  # BL/BR (bottom strip)
        n += 1
    print(f"mirrored {n} English glyphs to the +0x200 name-variant bank")
