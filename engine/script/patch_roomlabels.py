#!/usr/bin/env python3
"""3D-map room-preview facility labels -> English (patch_roomlabels).

The labels shown over a facility in the 3D dungeon room-preview (Field_SetState 0x080ad78c
-> FUN_080ad76c -> FUN_080b6568(labelIdx); tiles built by FUN_080b6360, sprites emitted by
FUN_080b6460) are a plain-ASCII string table at 0x08163444: 38 fixed-stride cells of 10
bytes (<=9 usable chars, space-padded, NUL-terminated), drawn glyph-by-glyph as OAM
sprites from the ascii8 BLOCKY-UPPERCASE face.  They are romaji-JP (JAKYOU/KAIFUKU/...) and
were never extracted (no Section; the contiguous-ptr scan can't see a bare ASCII table) —
user-reported 2026-06-15.

This is NOT a tr.py glyph Section (the bytes are raw ASCII outside the glyph codec): a
pure-data in-place overwrite is the whole fix, since the drawer already renders any
uppercase ASCII.  CHARSET CONSTRAINT (verified from FUN_080b6360: src = glyphBase +
(char-0x41)*32, with special cases only for ( ) ' & _ ): allowed = UPPERCASE A-Z, space,
and ( ) ' & _ — NO DIGITS (0x30-0x40 -> negative index -> garbage tiles), no lowercase.
Stride 10 and the NUL must be preserved; <=9 chars.  Only the romaji cells are rewritten;
the other 30 labels already ship English (TERMINAL/ELEVATOR/CASINO/...).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # noqa: F401,F403  (sys.path for sibling imports; ROOT, B, Path)

TABLE = 0x08163444
STRIDE = 10
ALLOWED = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ ()'&_")

# Field room-preview texts (9 usable chars + NUL).
CHANGES = [
    (0,  "4a414b594f5520202000", "FUSION"),  # JAKYOU   邪教 (Cathedral of Shadows)
    (2,  "4d455349412020202000", "MESSIAN"),     # MESIA    メシア (Messian church)
    (3,  "47414941202020202000", "GAEAN"),       # GAIA     ガイア (Gaian temple)
    (4,  "4b414946554b55202000", "HEALER"),      # KAIFUKU  回復
    (5,  "495a554d492020202000", "SPRING"),      # IZUMI    泉
    (17, "4a554e4b532020202000", "SHOP"),        # JUNKS    (junk shop)
    (20, "5649525455414c532000", "VR"),          # VIRTUALS (Virtual Battler)
]


def _cell(en):
    assert len(en) <= 9 and set(en) <= ALLOWED, f"room label {en!r} violates the cell budget/charset"
    return en.ljust(9).encode("ascii") + b"\x00"      # 9 chars (space-padded) + NUL = stride 10


def apply(p):
    for idx, old_hex, en in CHANGES:
        p.patch(TABLE + idx * STRIDE, bytes.fromhex(old_hex), _cell(en), name=f"roomlabel {en}")
    print(f"roomlabels: {len(CHANGES)} facility labels -> EN @0x{TABLE:08X} "
          f"({', '.join(e for _i, _o, e in CHANGES)})")
