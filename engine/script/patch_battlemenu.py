#!/usr/bin/env python3
"""Battle/menu UI text repointer (SPIKE).

Battle command/menu descriptions are set via BattleMenu_SetMode(mode, msgPtr) (0x080ea37c), which copies
the message into a battle-state buffer the UI loop renders — so long English can't fit the inline slot.
~70 call sites feed it (cursor-move, Select, auto-turn, fusion, …), so we hook its ENTRY rather than any
one caller: resolve a 0xFFFF + pool-pointer sentinel in the message pointer, then replay the overwritten
prologue and resume.  Untranslated messages (no 0xFFFF) pass straight through unchanged.

This module only installs the entry hook.  The per-message repointing is done by tr.pack: translated
system.json menu/command/error text (addr >= 0x08123800, 0x0000-terminated) gets a 0xFFFF + pool sentinel
that this hook resolves.  Battle-log fragments and battle-event lines use other copy paths (deferred).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE
ENTRY = rommap.BattleMenu_SetMode                 # 0x080ea37c
ENTRY_OLD = "f0b581b00d1c0006"                    # push{r4-r7,lr}; sub sp,#4; add r5,r1,#0; lsl r0,r0,#0x18
RESUME = (ENTRY + 8) | 1                          # resume at 0x080ea384 (lsr r4,r0,#0x18), Thumb

# entry detour: resolve r1 (msg ptr) if it's a 0xFFFF+pool sentinel, replay the prologue, resume.
CAVE_ASM = """
    ldrh r2, [r1]
    movs r3, #1
    lsls r3, r3, #16
    subs r3, #1           /* r3 = 0xFFFF */
    cmp  r2, r3
    bne  prologue
    ldrh r2, [r1, #2]     /* pooled-string pointer (field+2, two halfwords) */
    ldrh r3, [r1, #4]
    lsls r3, r3, #16
    orrs r2, r3
    adds  r1, r2, #0
prologue:
    push {r4, r5, r6, r7, lr}
    sub  sp, #4
    adds  r5, r1, #0
    lsls r0, r0, #0x18
    ldr  r3, [pc, #0]     /* RESUME = 0x080ea384|1 */
    bx   r3
"""
LITERALS = [RESUME]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="battlemenu")
    detour = b"\x00\x4b\x18\x47" + (cave | 1).to_bytes(4, "little")   # ldr r3,[pc,#0]; bx r3; .word cave|1
    p.patch(ENTRY, ENTRY_OLD, detour, name="battlemenu-entry")
