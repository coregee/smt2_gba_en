#!/usr/bin/env python3
"""Raise the event-VM message window's glyph capacity 64 -> 192 (patch_msgwin).

Found live 2026-06-12 during harness QA: g_MsgGlyphList (0x0203D800) holds 64
records, the appender clamps the count at 0x3F, and the hidden per-frame
renderer (@0x0813ded8, 5th ARM-broken Thumb region) draws one OAM sprite per
record via the 64-cell glyph sprite cache.  Any English page > ~2.5 lines
truncated mid-word.  tr.autowrap's page split is the backstop; this patch is
the real fix:

  1. RELOCATE the record list to free EWRAM scratch (MSG_GLYPH_LIST2,
     MSG_GLYPH_REC_MAX=192 records) by rewriting all 18 literal pools that
     hold 0x0203D800.  Every consumer was verified to use the address purely
     as the record-array base (separate literals for count/col/row), so the
     move is transparent.  (First raised to 128; 192 since 2026-07-02 so a
     FULL 4-line VWF page fits — ~140 records of typical English — and
     pagination is governed by window geometry, not the record count.)
  2. RAISE the appender's clamp 0x3F -> 0xBF (EventVM_RunStep glyph append;
     the menu/shop appenders keep their 0x3F clamps — menus never approach it).
  3. REPLACE the renderer's per-record draw loop with cave_msgwin.c: adjacent
     half-width English glyphs STRIP-pack by ink across cells (see the cave
     header; v1 pair-packing hit the cell cap on 4-line pages).  Cell cost is
     geometry-bounded (~52 of 56 cells for 4 full lines), so cells stay safe
     at any record count the window can physically hold.

Static layout sanity: list 0x0203F400..F9FF (0x600), cave state 0x0203FA00+
(0x3C8 B reserved) — both inside the zero-verified scratch run
0x0203F400..0x0203FFFF (layout asserts in rommap.py).  The row-save buffer
moved to the DEAD stock-list block 0x0203D800 (see rommap.MSG_ROWSAVE2).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap  # noqa: E402

SRC = Path(__file__).parent / "cave_msgwin.c"

LIST_OLD_HEX = "00d80302"               # 0x0203D800 little-endian
LIST_NEW = rommap.MSG_GLYPH_LIST2

# All literal pools holding 0x0203D800 (exhaustive byte-pattern scan, verified
# against Ghidra xrefs 2026-06-12; consumers audited individually — appenders,
# row save/restore copies, the shop/cost-menu builders, and the renderer).
LIST_LITERALS = [
    0x0812F1DC, 0x0812F2A4, 0x0812F538,
    0x081305D0, 0x08130608, 0x0813067C,
    0x08133694, 0x0813384C, 0x08133BA0, 0x08133C04, 0x08133F0C,
    0x08134184, 0x08134554, 0x08134808,
    0x081394AC,
    0x0813DBF0,                          # EventVM_RunStep appender
    0x0813DED4, 0x0813DFD8,              # the hidden renderer (loop replaced, kept consistent)
]

# EventVM_RunStep append clamp: cmp r4,#0x3f / movs r0,#0x3f  ->  0xbf
# (= MSG_GLYPH_REC_MAX - 1; Thumb imm8, so anything <= 0xFF works)
CLAMP_CMP = (0x0813DCBE, "3f2c", bytes.fromhex("bf2c"))
CLAMP_MOV = (0x0813DCC2, "3f20", bytes.fromhex("bf20"))

# ---- choice-prompt row save/re-append (VWF pass, 2026-06-13) -----------------
# ScriptOp_Choice (+5 service-menu flows) saves the page's record TOKENS into a
# 16-slot IWRAM buffer (FUN_0812f198 @0x03006870), re-laid out after the choice
# window opens by FUN_0812f1e4.  16 slots truncated any EN prompt > 16 glyphs
# ("＞What will you d").  Relocate the buffer to EWRAM scratch (192 + term, the
# dead stock-list block @0x0203D800) and raise both caps; also raise the
# re-append/label-renderer count clamps to 0xBF to match the 192-record list
# (a full 4-line EN prompt + menu rows passes the old 128).
ROWSAVE_OLD_HEX = "70680003"             # 0x03006870 little-endian
ROWSAVE_LITERALS = [0x0812F1D8, 0x0812F29C]      # exhaustive byte scan 2026-06-13
ROWSAVE_PATCHES = [
    (0x0812F1C2, "0f2a", "bf2a", "rowsave-cap"),       # cmp r2,#0xf  -> #0xbf (save <=192 tokens)
    (0x0812F272, "0f2e", "bf2e", "rowapp-cap"),        # cmp r6,#0xf  -> #0xbf (re-append <=192)
    (0x0812F25C, "3e28", "be28", "rowapp-clamp"),      # cmp r0,#0x3e -> #0xbe (count clamp 0xbf)
    (0x0812F486, "3f2a", "bf2a", "label-clamp-cmp"),   # FUN_0812f2b4 label appender
    (0x0812F48A, "3f20", "bf20", "label-clamp-mov"),   #   count clamp 0x3f -> 0xbf
]

# Renderer hook: replace the first loop's head with `bl cave` then branch over
# the dead loop body to the second loop @0x0813DF3A.
HOOK_BL = 0x0813DEDE                     # ldr r1,[pc,#0xf4]; ldrh r0,[r1]
HOOK_BL_OLD = "3d490888"
HOOK_BR = 0x0813DEE2                     # cmp r0,#0; beq -> b 0x0813DF3A; nop
HOOK_BR_OLD = "002829d0"
HOOK_BR_NEW = bytes.fromhex("2ae0c046")  # b +0x54 ; nop

# Second loop @0x0813DF44 = the shop LIST-window record renderer (NOT "furniture"
# as previously thought — that's the THIRD loop @0x0813DF94): draws SHOP_GLYPH_LIST
# 0x0203DA00 (count s16 @0x0300669C, enable s16 @0x0300699C checked @0x0813DF3A,
# which we keep) one sprite per record via FontSprite_DrawCached.  Replaced with
# cave_entry2 (same reflow + the patch_shopname 0xF000|id name markers), then
# branch over the dead loop to the widget loop @0x0813DF94.
HOOK2_BL = 0x0813DF44                    # movs r2,#0 ; ldr r0,[pc,#0x9c]
HOOK2_BL_OLD = "00222748"
HOOK2_BR = 0x0813DF48                    # movs r1,#0  -> b 0x0813DF94
HOOK2_BR_OLD = "0021"
HOOK2_BR_NEW = bytes.fromhex("24e0")


def apply(p):
    for addr in LIST_LITERALS:
        p.patch(addr, LIST_OLD_HEX, LIST_NEW.to_bytes(4, "little"),
                name=f"msgwin-lit@{addr:08x}")
    p.patch(*CLAMP_CMP, name="msgwin-clamp-cmp")
    p.patch(*CLAMP_MOV, name="msgwin-clamp-mov")

    for addr in ROWSAVE_LITERALS:
        p.patch(addr, ROWSAVE_OLD_HEX, rommap.MSG_ROWSAVE2.to_bytes(4, "little"),
                name=f"rowsave-lit@{addr:08x}")
    for addr, old, new, name in ROWSAVE_PATCHES:
        p.patch(addr, old, bytes.fromhex(new), name=name)

    # FAR cave: the per-glyph fast path (try_per_glyph) pushed the blob past the scarce near
    # pool, so place it in the 3 MB far pool and reach both entries via near bl_far trampolines.
    # The cave's engine calls use absolute fn-pointers (RM_* | 1), so far placement is fine; the
    # trampoline's r3 clobber is harmless here (both hook sites branch away after the C call).
    p.cave_c_far(SRC, name="msgwin")
    entry = p.cave_c_syms["cave_entry"]
    p.bl_far(HOOK_BL, entry, HOOK_BL_OLD, name="msgwin-render-bl")
    p.patch(HOOK_BR, HOOK_BR_OLD, HOOK_BR_NEW, name="msgwin-render-skip")
    entry2 = p.cave_c_syms["cave_entry2"]
    p.bl_far(HOOK2_BL, entry2, HOOK2_BL_OLD, name="msgwin-list2-bl")
    p.patch(HOOK2_BR, HOOK2_BR_OLD, HOOK2_BR_NEW, name="msgwin-list2-skip")
    print(f"msgwin: list -> 0x{LIST_NEW:08X} ({rommap.MSG_GLYPH_REC_MAX} rec), "
          f"clamp 0x{rommap.MSG_GLYPH_REC_MAX - 1:02X}, "
          f"strip-pack cave @0x{entry:08X}, list2 cave @0x{entry2:08X}")
