#!/usr/bin/env python3
"""Cap the race-name copy in MessageBox_ComposeSpeciesText (patch_racecap).

The composer's 0x31F race branch copies Race_GetName's string with NO length
cap (unlike the species branch's cap-8): `strh/adds/ldrh/cmp/bne` until a zero
halfword @0x080EACCC-0x080EACD7.  The 2026-07 MiSTer investigation showed what
happens when the source data is bad: the EN race names packed above a
truncated ROM copy's end, the reads came back as GBA open bus (the loop's own
`bne` opcode, 0xD1F9 — never zero), and the uncapped copy flooded the entire
EWRAM mirror space forever: sound/scroll shadows destroyed, main loop never
returning, every battle a lockup.  The root fix was the ROM file itself, but
no data problem should ever be able to melt RAM: cap the copy at 15 tokens
(the longest EN race name fits; JP names are <=5).

Mechanics: the 12-byte inner loop is replaced by `bl cave` + `b.n exit` + NOPs;
the cave runs the same copy capped at 15, preserving r0/r3/r5 (live: occurrence
counter / next-template ptr / template ptr) and leaving r1/r2/r4 exactly as the
stock loop exit expects.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

SITE = 0x080EACCC
OLD = "21800232023411880029f9d1"   # strh r1,[r4]; adds r2,#2; adds r4,#2; ldrh r1,[r2]; cmp r1,#0; bne loop

CAVE = """
push {r0}
movs r0, #15
racecopy:
strh r1, [r4]
adds r2, #2
adds r4, #2
ldrh r1, [r2]
cmp  r1, #0
beq  racedone
subs r0, #1
bne  racecopy
racedone:
pop  {r0}
bx   lr
"""


def apply(p):
    cave = p.cave_asm(CAVE, name="racecap")
    ins = bytearray()
    from engine.script.cave_asm import thumb_bl
    ins += thumb_bl(SITE, cave)          # bl racecap cave
    ins += (0xE002).to_bytes(2, "little")  # b.n 0x080EACD8 (stock loop exit)
    ins += b"\xc0\x46" * 3               # nop padding over the old loop tail
    p.patch(SITE, OLD, bytes(ins), name="racecap@080eaccc")
    print(f"racecap: race-name copy capped at 15 tokens (cave @0x{cave:08X})")
