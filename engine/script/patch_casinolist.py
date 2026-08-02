#!/usr/bin/env python3
"""Casino coin->item prize list ("Which one?"): item names -> English, and the price suffix 枚 -> "C".

The prize list is drawn by `CasinoPrize_DrawList 0x0813914c` (found 2026-06-21 via an OAM caller
probe: the names render as per-glyph sprites at y=89..134, NOT the y=4..64 drawer I first tried).
Per visible row it resolves the item record (equipment id<0xd0 -> +0x14 name; item id>=0xd0 ->
Item_GetRecord32+0xC), copies EXACTLY 8 JP name tokens into the shared staging buffer 0x0203DB08,
and `FUN_08133e70(0x1a, ...)` appends them as 8 glyph records to g_MsgGlyphList (rendered by
cave_msgwin) -- then draws the price digits + a fixed 枚 glyph (`*0x081394b0` = token 0x0FC8) into
the same list.  Prize items come from the {price,id} table @0x0878FEA8 (page*0x20 + row*4: +0=price,
+2=id).

This is the SAME staging buffer / glyph-list / cave_msgwin path as patch_offerlist, so the name fix
is the identical marker: replace the 8-token copy with a cave that writes ONE 0xF000|id marker into
0x0203DB08[0] when ITEM_TABLE[id] is pooled (cave_msgwin expands it to the full VWF English name;
the preceding zero-16 loop already cleared slots 1..15), else copies the 8 JP tokens.  Untranslated
/ OOB ids keep the JP name byte-for-byte.  The cave re-derives the row's item id from the prize
table (page offset is the function local at [sp,#0x28]; row = r4-1).

  NAME hook @0x0813929a (`movs r6,#0; ldr r3,=staging`, head of the 8-token copy loop) -> `bl cave`
       skip @0x0813929e (`lsls r0,r6,#1`)                                 -> `b 0x081392b2`
  The cave touches only r0-r4/r6 (all dead/reloaded after the loop) and uses NO stack frame, so
  the live r5 / r9(sb) and the caller's [sp,#0x28] are untouched.

  枚->C: the price-suffix glyph literal `0x081394b0` (0x00000FC8 = 枚) -> 0x000000DF ("C"), so the
  drawer appends "C" after the coin price ("5000C") in place of the 枚 counter.  (The digits use the
  casino digit-glyph table @0x0878F9B8 and stay as-is.)

Run AFTER patch_msgwin (the renderer that expands the 0xF000|id marker; see patch_offerlist).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap  # noqa: E402

PRIZE_TABLE = 0x0878FEA8          # {u16 price, u16 itemId} * rows, paged by 0x20; id at +2
STAGING     = 0x0203DB08          # shared 8-token row staging -> g_MsgGlyphList (= patch_offerlist STAGING)

# --- item names -> EN marker -------------------------------------------------------------------
NAME_HOOK = 0x0813929A
NAME_HOOK_OLD = bytes.fromhex("00267b4b")   # movs r6,#0 ; ldr r3,[pc,#0x1ec] (=STAGING)
NAME_SKIP = 0x0813929E
NAME_SKIP_OLD = bytes.fromhex("7000")       # lsls r0,r6,#1 (dead copy-loop body)
NAME_SKIP_NEW = bytes.fromhex("08e0")       # b 0x081392b2 (past the dead 8-token copy loop)

# entry (bl from hook): r2 = JP name ptr, r4 = row+1, [sp,#0x28] = page offset (itemId page * 0x20).
# Derive itemId = *(u16*)(PRIZE_TABLE + [sp,#0x28] + (r4-1)*4 + 2); write 0xF000|id when pooled, else
# copy 8 JP tokens.  No push (sp must stay put so [sp,#0x28] is the caller's local); clobbers only
# r0-r4/r6 (all dead/reloaded after the loop), preserves r5 and r9(sb).
CAVE_ASM = """
    ldr  r0, [sp, #0x28]      /* page offset (page*0x20) */
    subs r1, r4, #1           /* row = r4-1 */
    lsls r1, r1, #2           /* row*4 */
    adds r0, r0, r1
    adds r0, r0, #2           /* + id field offset */
    ldr  r1, [pc, #0]         /* PRIZE_TABLE */
    adds r0, r0, r1
    ldrh r6, [r0]             /* itemId */
    ldr  r0, [pc, #0]         /* ITEM_COUNT */
    cmp  r6, r0
    bhs  n_jp
    ldr  r0, [pc, #0]         /* ITEM_TABLE */
    lsls r1, r6, #2
    ldr  r0, [r0, r1]         /* ITEM_TABLE[id], 0 = none */
    cmp  r0, #0
    beq  n_jp
    ldr  r1, [pc, #0]         /* STAGING */
    movs r0, #0xF0
    lsls r0, r0, #8           /* 0xF000 */
    orrs r0, r6              /* marker = 0xF000 | id */
    strh r0, [r1]            /* STAGING[0] = marker (slots 1..15 already zeroed) */
    bx   lr
n_jp:
    ldr  r1, [pc, #0]         /* STAGING */
    movs r6, #0
n_loop:
    ldrh r0, [r2]
    lsls r3, r6, #1
    strh r0, [r1, r3]
    adds r2, #2
    adds r6, #1
    cmp  r6, #7
    bls  n_loop              /* copy the 8 JP tokens */
    bx   lr
"""
LITERALS = [PRIZE_TABLE, rommap.ITEM_COUNT, rommap.ITEM_TABLE, STAGING, STAGING]

# --- price suffix 枚 -> "C" ---------------------------------------------------------------------
MAI_LIT = 0x081394B0
MAI_OLD = bytes.fromhex("c80f0000")          # 0x00000FC8 = 枚 glyph token
MAI_NEW = bytes.fromhex("df000000")          # 0x000000DF = "C" glyph token (drawer reads it as (short))


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="casinolist")
    p.bl(NAME_HOOK, cave, NAME_HOOK_OLD, name="casinolist name marker")
    p.patch(NAME_SKIP, NAME_SKIP_OLD, NAME_SKIP_NEW, name="casinolist skip dead copy loop")
    p.patch(MAI_LIT, MAI_OLD, MAI_NEW, name="casinolist 枚->C")
    print(f"casinolist: prize names -> EN ITEM_TABLE markers + 枚->C, cave @0x{cave:08X}")
