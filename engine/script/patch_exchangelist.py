#!/usr/bin/env python3
"""Exchange / battle item-list (Battle_DrawItemListPage 0x080e0a1c) names -> pooled English.

The bank/exchange + battle item-list drawer copies EXACTLY 8 JP tokens from each row's item/
equipment record pDisplayText into a stack buffer (local_34 @ sp+0xc), then draws via
Text_DrawSpriteString -> cave_runtext.  English item names never fit the 8 inline slots, so the
list drew JP (the "DDS Demon Exchange" item list).  Fix = the patch_shopname marker pattern on the
cave_runtext substrate: replace the per-row copy loop with a cave that writes ONE marker
0xE000|itemId when ITEM_TABLE[itemId] holds a pooled English name (cave_runtext's STRIP_MARK2
expands it to the full VWF name), else copies the 8 JP tokens byte-for-byte.

  hook  @0x080e0b28 (`lsl r0,r2,#1; mov r1,sp`)  -> `bl cave`
  skip  @0x080e0b2c (`add r1,r1,r0`)             -> `b 0x080e0b4c` (past the dead loop + null-term)
  at the hook r5 = itemId, r3 = JP pDisplayText ptr, buffer = sp+0xc; r4/r6/r7/r8/r9/r10 must
  survive (the cave touches only r0/r1/r2/r3).

The grayed-out rows use Text_DrawSpriteStringTinted 0x080ac3ac, a SEPARATE unhooked drawer on the
glyph-cache substrate that can't expand the marker (it would draw 0xE000 as garbage).  So the
tinted call @0x080e0b72 is retargeted to the hooked non-tinted Text_DrawSpriteString 0x080ac334
(its 7th stack arg = the tint is simply ignored): every row now renders English VWF via strips.
Cost: the ~5 "marked" rows lose their gray tint (cosmetic).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap  # noqa: E402
from engine.script.cave_builders import marker_copy_cave  # noqa: E402

HOOK = 0x080E0B28
HOOK_OLD = bytes.fromhex("50006946")     # lsl r0,r2,#1 ; mov r1,sp
SKIP = 0x080E0B2C
SKIP_OLD = bytes.fromhex("0918")         # add r1,r1,r0
SKIP_NEW = bytes.fromhex("0ee0")         # b 0x080e0b4c (past the dead copy loop + null-term)

TINT_CALL = 0x080E0B72                    # bl Text_DrawSpriteStringTinted (grayed rows)
TINT_OLD = bytes.fromhex("cbf71bfc")     # -> 0x080ac3ac
TEXT_DRAW_SPRITE = 0x080AC334            # hooked non-tinted printer (cave_runtext)

# entry (bl from hook): r5 = item id, r3 = JP pDisplayText ptr, buffer = sp+0xc (local_34[10]).
# The marker cave (shared marker_copy_cave): write 0xE000|id when ITEM_TABLE[id] is pooled, else
# copy the 8 JP tokens; cave_runtext's STRIP_MARK2 expands the marker to the full VWF name.

# --- Exchange DEMON list (the stock-demon-name list, drawer @0x080e14xx) -------------------------
# Same shape: per row it resolves the demon (handle -> record), reads species = [record+0x12],
# FUN_080bf648(species)+0x22 = the JP name, copies 8 tokens into sp+0xc, draws via the tinted/plain
# sprite printers.  At the copy loop r4 = species, r3 = JP name ptr.  Write a 0xF000|species demon
# marker -> cave_runtext's STRIP_MARK expands it to the pooled English name (NAME_TABLE); the tinted
# call is likewise routed to the hooked plain printer so the marker expands.
DEMON_HOOK = 0x080E14B2
DEMON_HOOK_OLD = bytes.fromhex("50006946")   # lsls r0,r2,#1 ; mov r1,sp
DEMON_SKIP = 0x080E14B6
DEMON_SKIP_OLD = bytes.fromhex("0918")       # adds r1,r1,r0
DEMON_SKIP_NEW = bytes.fromhex("0ee0")       # b 0x080e14d6 (past the dead copy loop + null-term)
DEMON_TINT = 0x080E14FC
DEMON_TINT_OLD = bytes.fromhex("caf756ff")   # bl 0x080ac3ac

# entry (bl from hook): r4 = species id, r3 = JP name ptr, buffer = sp+0xc.  Same shape as the item
# cave: marker 0xF000|species from NAME_TABLE; cave_runtext's STRIP_MARK expands it.

# --- the "×NN" QUANTITY glyph (FontSprite_DrawGlyph token 0x3e @0x080e0ba2) is drawn through the
# engine glyph cache (bottom-up, cell 0); once cave_strip fills its rows bottom-up it collides with
# the name strips ("So02").  Route the × through cave_runtext (cave_xglyph.c) so it occupies a
# managed strip cell like the name/number -- no engine glyph-cache cell, nothing to overdraw. ---
XGLYPH_HOOK = 0x080E0BA2
XGLYPH_HOOK_OLD = bytes.fromhex("cbf739fb")     # bl FontSprite_DrawGlyph 0x080ac218
XGLYPH_SRC = Path(__file__).resolve().parent / "cave_xglyph.c"


def apply(p):
    cave = marker_copy_cave(
        p, name="exchangelist", hook=HOOK, hook_old=HOOK_OLD,
        skip=SKIP, skip_old=SKIP_OLD, skip_new=SKIP_NEW,
        tint_call=TINT_CALL, tint_old=TINT_OLD, tint_target=TEXT_DRAW_SPRITE,
        table=rommap.ITEM_TABLE, count=rommap.ITEM_COUNT, marker_hi=0xE0, id_reg="r5")
    dcave = marker_copy_cave(
        p, name="exchangedemon", hook=DEMON_HOOK, hook_old=DEMON_HOOK_OLD,
        skip=DEMON_SKIP, skip_old=DEMON_SKIP_OLD, skip_new=DEMON_SKIP_NEW,
        tint_call=DEMON_TINT, tint_old=DEMON_TINT_OLD, tint_target=TEXT_DRAW_SPRITE,
        table=rommap.NAME_TABLE, count=rommap.NAME_COUNT, marker_hi=0xF0, id_reg="r4")

    p.cave_c(XGLYPH_SRC, name="xglyph")
    p.bl(XGLYPH_HOOK, p.cave_c_syms["cave_entry"], XGLYPH_HOOK_OLD, name="exchange × glyph -> strip")
    print(f"exchangelist: item cave @0x{cave:08X}, demon cave @0x{dcave:08X}, × glyph -> strip "
          f"@0x{p.cave_c_syms['cave_entry']:08X}")
