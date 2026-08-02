#!/usr/bin/env python3
"""DDS demon-dictionary "parent race" (clan family) names -> English, in place (pure data).

The full-info detail screen's RacePanel (0x080dc6d0) shows TWO race fields for each demon:
  - the demon RACE  (Race_GetName 0x080c068c -> g_wRaceNameTable 0x081A5C34) -- already English
    via names_race (e.g. Orochi = "Snake"); and
  - the PARENT RACE (ParentRace_GetName 0x080c069c -> PARENTRACE_NAME_TABLE 0x081A5F24), keyed by
    Race_GetParentId(0x080c09a4)[race] -> one of 15 clans.  For many demons the parent clan equals
    the race; for some it differs (Orochi: race Snake, parent clan 竜族 "Dragons").

Both fields are drawn fixed-pitch by Text_DrawStringTinted (0x080ac9c8) on the BG canvas, walking
the cell's u16 glyph tokens.  Rather than overwrite the 0x10-byte JP cells (which would cap English
at 7 inline glyphs and require sentinel handling the terminator-bounded drawer can't do), we leave
the JP table intact and OVERLAY English via a cave (cave_dictname's dict_parentrace_vwf, hooked by
patch_dictname): this patch writes the pooled EN glyph strings + a 15-slot u32 ptr table to far data
(PARENTRACE_EN_PTRS), and the cave indexes it by parentId (recovered from the JP cell ptr) to VWF-
draw the English (proportional, any length).  Untranslated slots fall back to the JP cell.

Names live in text/corpus/names_parentrace.json (curated, user-editable).
"""
import json
import struct
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap
from text.script import tr

TERM = b"\x01\x03"               # 0x0301 string terminator (VWF draw stops here or at NUL)
CEILING = rommap.FARDATA_DICTSTATLABELS   # next far-data region (sits right after this pool)


def apply(p):
    entries = json.load(open(tr.TR / "names_parentrace.json", encoding="utf-8"))
    n = rommap.PARENTRACE_COUNT
    ptrs = [0] * n
    pool = bytearray()
    written = []
    for e in entries:
        pid = e["id"]
        if not (0 <= pid < n):
            raise SystemExit(f"patch_parentrace: id {pid} out of range 0..{n-1}")
        en = (e.get("replace") or "").strip()
        if not en:
            continue                         # leave JP (cave falls back to the JP cell)
        ptrs[pid] = rommap.PARENTRACE_EN_POOL + len(pool)
        pool += tr.encode(en) + TERM
        written.append(en)

    table = b"".join(struct.pack("<I", v) for v in ptrs)
    end = rommap.PARENTRACE_EN_POOL + len(pool)
    if end > CEILING:
        raise SystemExit(f"patch_parentrace: EN pool overruns the far-data ceiling (0x{end:08X})")
    p.write(rommap.PARENTRACE_EN_PTRS, table)     # u32[15] slot table
    p.write(rommap.PARENTRACE_EN_POOL, bytes(pool))
    print(f"parentrace: {len(written)} clan names -> EN pool @0x{rommap.PARENTRACE_EN_POOL:08X} "
          f"(table @0x{rommap.PARENTRACE_EN_PTRS:08X}) [{', '.join(written)}]")
