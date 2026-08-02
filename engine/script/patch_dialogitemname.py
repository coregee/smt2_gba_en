#!/usr/bin/env python3
"""Item / equipment names in EVENT-VM dialogue text -> English.

`{ITEM_NAME}` (opcode 0x0321) in story/dialogue streams is expanded by
`ScriptOp_DrawCharOrSubstitute 0x08132b40` (the name/value substitution handler).  Its
case @0x08132f0c reads the working item id from the script item-param global
(`*0x0203DB50`, set by `ScriptOp_SetItemParam 0x081325d2` / opcode 0x0A), resolves the
record (items id>0xCF -> ItemRecord32+0x0C; equipment -> EquipmentRecord36+0x14 via the
0x080bf32c/0x080bf354 getters), then copies a FIXED 8 inline glyph tokens of the JP name
into the substitution staging buffer (0x0203DB08).  The shared tail (0x081331da)
terminates the staging with 0x318 and the VM commits it to g_MsgGlyphList.

Two problems with the stock path: it always draws the *Japanese* record name, and the
fixed-8 copy over-reads short names into the next record field (the casino "first prize
is 月のピラー" line rendered "月のピ・ー" — Moon Pillar, garbled).

English item/equipment names already live in ITEM_TABLE (id->pooled-pointer, filled by
patch_itemname / tr.pack — the same table the shop/inventory/equip name caves read).  So
this is the exact item-name sibling of the demon-name negotiation fix in
patch_battlename (NEGO_SITES / cave_negocopy): the copy loop @0x08132f3a is byte-for-byte
the same cap-8 copy (only the pc-literal index differs), so we replace it the same way —
`bl` a tiny cave that prefers ITEM_TABLE[id] (else keeps the JP record name) and STREAMS
the whole name (cap 15) into the staging buffer up to its 0x0000 / 0x0301 terminator.  The
name then flows as ordinary VWF glyph tokens through cave_msgwin (real per-glyph widths,
length-flexible, no cap-8 truncation), and the following text reflows tight after it.

This one hook covers EVERY {ITEM_NAME} expansion in event-VM text (treasure "[item]
obtained!", prize lines, give-item dialogue, ...).  Untranslated / out-of-range ids fall
back to the original JP record name (byte-safe).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap
from engine.script.cave_asm import thumb_bl

HOOK = 0x08132F3A
# the fixed-8 copy loop: `mov r6,#0; ldr r4,=staging; <copy 8 tokens>; ble loop`.  Identical to
# patch_battlename.NEGO_COPY_OLD except byte 3 (074c vs 084c = a different pc-literal slot).
HOOK_OLD = "0026074c30040014410009191a880a80023301300004060c00140728f2dd"

ITEM_PARAM = 0x0203DB50          # *(u16*) script working item id (ScriptOp_SetItemParam writes it)
STAGING    = 0x0203DB08          # substitution staging buffer (the shared tail commits it, 0x318-term)
ITEM_TABLE = rommap.ITEM_TABLE   # id -> pooled English name ptr (0 = none); patch_itemname / tr.pack fill it
ITEM_COUNT = rommap.ITEM_COUNT

# entry (replaces the copy loop): r3 = JP inline name ptr (record+0xC items / +0x14 equipment, set by the
# original case head).  Stream the EN name (ITEM_TABLE[id], else the JP record name) into STAGING, cap 15
# (slots 0..14), stopping at 0x0000 / 0x0301 — the shared tail appends the 0x318 terminator after the last
# token.  Same streaming convention as cave_negocopy; uses only r0/r1/r3/r4/r5 (r9 left intact for the tail).
CAVE_ASM = """
    push {r4, r5}
    ldr  r1, [pc, #0]      /* &ITEM_PARAM */
    ldrh r1, [r1, #0]      /* id */
    ldr  r0, [pc, #0]      /* ITEM_COUNT */
    cmp  r1, r0
    bhs  it_src            /* id >= count: keep r3 = JP record name */
    ldr  r0, [pc, #0]      /* ITEM_TABLE */
    lsls r1, r1, #2
    ldr  r0, [r0, r1]      /* ITEM_TABLE[id] */
    cmp  r0, #0
    beq  it_src
    adds r3, r0, #0        /* src = pooled English name */
it_src:
    ldr  r1, [pc, #0]      /* STAGING dest */
    movs r5, #30
    adds r5, r5, r1        /* r5 = dest + 30 (cap: slots 0..14) */
    movs r4, #0x03
    lsls r4, r4, #8
    adds r4, #0x01         /* r4 = 0x0301 string terminator */
it_loop:
    cmp  r1, r5
    bhs  it_done
    ldrh r0, [r3]
    cmp  r0, #0
    beq  it_done
    cmp  r0, r4
    beq  it_done
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    b    it_loop
it_done:
    pop  {r4, r5}
    bx   lr
"""
LITERALS = [ITEM_PARAM, ITEM_COUNT, ITEM_TABLE, STAGING]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="dialogitemname")
    new = bytes.fromhex(thumb_bl(HOOK, cave).hex()) + b"\xc0\x46" * 13   # bl cave + 13 NOP (30 B)
    p.patch(HOOK, HOOK_OLD, new, name="dialogitem-copy")
    print(f"dialogitemname: {{ITEM_NAME}} (0x0321) dialogue sub -> EN ITEM_TABLE, cave @0x{cave:08X}")
