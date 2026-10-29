#!/usr/bin/env python3
"""Ex-appraiser demon EXTRACTION / RETURN screen -> English (patch_extract).

Script op 0x445 sub-ops 0x1D/0x1E (the ex-appraiser's "extract a demon" / "return a demon"
services) open a record list (task script 0x084F36B0) that the translation never touched:

  (1) the list rows (drawer 0x080D4190) copy 8 glyphs of each demon record's JP name, so the
      list showed katakana with broken glyphs (アプサ・ス for アプサラス);
  (2) the cost prompt (sub_080CF250) draws 抽出するのに／メモリーチップ{CC}枚と／ћ{CD}かかるが／
      いいかい？ (0x0815BFEA) or この悪魔を還元するのに／ћ{CD}かかるが／いいかい？ (0x0815C0AA),
      with the chip count / price spliced in where the glyph codes 0xCC / 0xCD stand.  Deferred
      in text/script/sections.py (the placeholders are bare digit glyphs, so reflowed English
      would misplace them).

Both confirmed on screen in the English build (decomp/docs/translation-findings.md,
"Confirmed on screen").  cave_extract.c replaces both per-glyph loops with VWF loops on the same
OBJ glyph cache: list names from NAME_TABLE[id], and the prompt from the repointed literals with
the 0xCC/0xCD placeholders expanded in place (so the English can put the numbers anywhere).

Run AFTER patch_vwf (width table) and patch_names (NAME_TABLE).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap
from text.script import tr

SRC = Path(__file__).resolve().parent / "cave_extract.c"

LIST_HOOK = 0x080D41E4          # movs r6,#0 ; lsls r1,r4,#1 (row-name loop init)
LIST_HOOK_OLD = "00266100"
PROMPT_HOOK = 0x080CF292        # movs r4,#0x12 ; movs r5,#0x5b (message loop init)
PROMPT_HOOK_OLD = "12245b25"

CHIPS = "{=cc00}"               # Memory Chip cost (drawn by the cave)
PRICE = "{=cd00}"               # macca price
# (literal slot, JP string, English).  {n} = 0x0300 new line (back to x 0x12); 4 lines fit the
# 26x8-tile window.  The ex-appraiser's voice and terms follow the story script ("That okay?",
# "Memory Chips", "Return complete!").
LITERALS = [
    (0x080CF2C4, 0x0815BFEA,
     f"Extracting it will cost{{n}}{CHIPS} Memory Chip(s) and ћ{PRICE}.{{n}}That okay?"),
    (0x080CF2C0, 0x0815C0AA,
     f"Returning this demon will cost{{n}}ћ{PRICE}.{{n}}That okay?"),
]

# Read-side coverage for lib/cave_coverage.py (these JP strings are made English here).
COVERED_TEXT_ADDRS = tuple(a for r in LITERALS for a in r[:2])


def apply(p):
    p.cave_c(SRC, name="extract")
    sy = p.cave_c_syms
    p.bl(LIST_HOOK, sy["extract_list_veneer"], LIST_HOOK_OLD, name="extract list name VWF")
    p.bl(PROMPT_HOOK, sy["extract_prompt_veneer"], PROMPT_HOOK_OLD, name="extract cost prompt VWF")

    addr = rommap.FARDATA_EXTRACT
    for slot, jp, en in LITERALS:
        cur = int.from_bytes(p.read(slot, 4), "little")
        if cur != jp:
            raise SystemExit(f"patch_extract: literal @0x{slot:08X}: expected 0x{jp:08X}, found 0x{cur:08X}")
        prose = tr.encode(en.replace(CHIPS, "").replace(PRICE, ""))
        if any(prose[i:i + 2] in (b"\xcc\x00", b"\xcd\x00") for i in range(0, len(prose), 2)):
            raise SystemExit(f"patch_extract: a '0'/'1' in {en!r} would draw as a number")
        blob = tr.encode(en) + b"\x01\x03"
        if addr + len(blob) > rommap.FARDATA_EXTRACT_END:
            raise SystemExit(f"patch_extract: pool overruns 0x{rommap.FARDATA_EXTRACT_END:08X}")
        p.data(blob, at=addr, name=f"extract prompt @{slot:08X}")
        p.write(slot, addr.to_bytes(4, "little"))
        addr += len(blob)
    print(f"extract: list names + 2 cost prompts VWF, strings @0x{rommap.FARDATA_EXTRACT:08X}")
