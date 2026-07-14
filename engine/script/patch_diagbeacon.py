#!/usr/bin/env python3
"""DIAGNOSTIC ONLY — battle-entry palette beacons (included when SMT2_DIAG=1).

MiSTer-only battle-entry freeze (2026-07).  History: round 2 = frozen YELLOW
(inside ComposeSpeciesText); round 3 = still YELLOW with the caller-return
beacon never firing (composer entered ONCE, never exits — not even the busy
early-out); round 4 = still YELLOW with every branch beacon dark, and the user
reports MUSIC KEEPS PLAYING (IRQs alive).  Every instruction in the remaining
window is straight-line or JP-exonerated (the 0x0815CAF8 buffer clear = BIOS
CpuSet, identical literals, JP passes) — so round 5 tests two rival models:

  (a) main-loop livelock (something retries forever)      -> strobing beacons
  (b) an IRQ handler that never returns (e.g. the VBlank display-list flush
      walking a bad entry) freezing the main loop mid-composer while nested
      timer IRQs keep the music going                     -> SOLID beacons

The compose-entry beacon STROBES (yellow on even frames, black on odd) so a
frozen screen distinguishes alive-and-retrying (flicker) from main-loop-dead
(solid).  Colors:
  RED     intro dispatch (per frame, liveness)
  YELLOW~ compose entry, STROBED yellow/black by frame parity
  ORANGE  composer busy-check passed, about to BIOS-CpuSet the buffer
  GREEN   a template token completed (all paths converge 0x080EAD50)
  WHITE   composer epilogue reached (normal return OR busy early-out)
  MAGENTA SetMode proceeding (post its busy check)
  CYAN    BattleMenu_RenderMessageObject entry (per frame while window active)
  BLUE    (C-side, temp edit) battle_reveal_worker entry — live typewriter
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path
import os

# (site, replaced bytes, redo asm, color, tag) — bytes verified vs JP base AND
# the current EN build (no collision with existing hooks).
SITES = [
    (0x080E4AD2, "474680b4", "mov r7, r8\npush {r7}",             0x001F, "introdisp"),  # RED
    (0x080EAC4C, "6846211c", "mov r0, sp\nadds r1, r4, #0",       0x021F, "pre_cpuset"), # ORANGE
    (0x080EAD50, "1d1c2988", "adds r5, r3, #0\nldrh r1, [r5]",    0x03E0, "token_done"), # GREEN
    (0x080EAD66, "03b038bc", "add sp, #0xc\npop {r3, r4, r5}",    0x7FFF, "epilogue"),   # WHITE
    (0x080EA396, "00213470", "movs r1, #0\nstrb r4, [r6]",        0x7C1F, "setmode"),    # MAGENTA
    (0x080EA53E, "fc21c900", "movs r1, #0xfc\nlsls r1, r1, #3",   0x7FE0, "render"),     # CYAN
]

CAVE = """
push {{r0, r1}}
ldr r0, [pc, #0]
ldr r1, [pc, #0]
str r1, [r0]
str r1, [r0, #4]
str r1, [r0, #8]
str r1, [r0, #12]
pop {{r0, r1}}
{redo}
bx lr
"""

# Compose-entry strobe: palette = yellow on even frames, black on odd — a live
# retry loop reads as flicker, a dead main loop as one solid state.  Branch-free
# (broadcast frame bit0 into a mask).  Literal order = ldr-pc order.
BLINK_SITE = (0x080EAC0E, "57464e46", "blink_compose")
CAVE_BLINK = """
push {r0, r1}
ldr  r0, [pc, #0]
ldr  r0, [r0]
lsls r0, r0, #31
asrs r0, r0, #31
mvns r0, r0
ldr  r1, [pc, #0]
ands r1, r0
ldr  r0, [pc, #0]
str  r1, [r0]
str  r1, [r0, #4]
str  r1, [r0, #8]
str  r1, [r0, #12]
pop  {r0, r1}
mov  r7, r10
mov  r6, r9
bx   lr
"""


# SMT2_DIAG_NOSWI=1: replace the composer's buffer-clear BIOS CpuSet (`bl
# 0x0815CAF8` @0x080EAC50, ctrl=0x05000020 = 32-bit fill x32 words) with an
# inline software fill.  Tests the SWI-entry-race theory: every prior beacon
# round pins the MiSTer freeze inside THIS CpuSet, with all IRQ-source theories
# eliminated — if the freeze MOVES past ORANGE (or vanishes) with the SWI gone,
# the core's SWI handling at that timing alignment is implicated.  The cave
# implements full CpuSet semantics (16/32-bit x copy/fill), r4/r5 preserved.
FILL_ASM = """
push {r4, r5}
ldr  r4, [pc, #0]
ands r4, r2
beq  done
lsls r5, r2, #5
bmi  words32
lsls r5, r2, #7
bmi  fill16
copy16:
ldrh r3, [r0]
strh r3, [r1]
adds r0, #2
adds r1, #2
subs r4, #1
bne  copy16
b    done
fill16:
ldrh r3, [r0]
f16l:
strh r3, [r1]
adds r1, #2
subs r4, #1
bne  f16l
b    done
words32:
lsls r5, r2, #7
bmi  fill32
copy32:
ldr  r3, [r0]
str  r3, [r1]
adds r0, #4
adds r1, #4
subs r4, #1
bne  copy32
b    done
fill32:
ldr  r3, [r0]
f32l:
str  r3, [r1]
adds r1, #4
subs r4, #1
bne  f32l
done:
pop  {r4, r5}
bx   lr
"""
NOSWI_SITE = (0x080EAC50, "71f052ff")   # bl 0x0815CAF8 (CpuSet wrapper)


# SMT2_DIAG_ISR=1 (round 9, exclusive mode): beacon the VBLANK ISR CHAIN.
# With the SWI dodge changing nothing, the model is: the freeze is IN the
# VBlank handler chain, and the composer is just where the main loop parks.
# Chain (global callback 0x080A9AF5, installed once, runs from ROM in place):
#   bl 0x080E2954 -> bl 0x080DF15C -> either [OAM/PAL DMA + walker(1)] or
#   [scroll upload + walker(2) + bl 0x080E3018] -> frame flag.  The walker
#   0x080A9C78 bx-calls task fns from the 10-slot table @0x03003900 IN THE ISR.
# Tints (on COMPLETION of each stage): RED=callback entered, ORANGE=0x080E2954
# done, YELLOW=0x080DF15C done, GREEN=walker(1) done, CYAN=walker(2) done,
# BLUE=0x080E3018 done, WHITE=whole callback done, MAGENTA=about to call a
# task-slot fn.  Frozen WHITE = ISR healthy & main loop dead (pivot back);
# frozen MAGENTA = a queued task fn hung; other colors = that stage hung.
CB_LIT = (0x080A9AF0, "f59a0a08")            # callback ptr literal (0x080A9AF5)
ISR_BLS = [  # (site, old bl bytes, real target|1, completion color, tag)
    (0x080A9AF6, "38f02dff", 0x080E2955, 0x021F, "vb_e2954"),   # ORANGE
    (0x080A9AFA, "35f02ffb", 0x080DF15D, 0x03FF, "vb_df15c"),   # YELLOW
    (0x080A9B42, "00f099f8", 0x080A9C79, 0x03E0, "vb_walker1"), # GREEN
    (0x080A9BAA, "00f065f8", 0x080A9C79, 0x7FE0, "vb_walker2"), # CYAN
    (0x080A9BAE, "39f033fa", 0x080E3019, 0x7C00, "vb_e3018"),   # BLUE
]
SLOT_SITE = (0x080A9C94, "b3f014f8")         # walker: bl 0x0815CCC0 (bx r0)

CAVE_CBWRAP = """
push {lr}
ldr  r0, [pc, #0]
ldr  r1, [pc, #0]
str  r1, [r0]
str  r1, [r0, #4]
str  r1, [r0, #8]
str  r1, [r0, #12]
ldr  r3, [pc, #0]
bl   callr3
ldr  r0, [pc, #0]
ldr  r1, [pc, #0]
str  r1, [r0]
str  r1, [r0, #4]
str  r1, [r0, #8]
str  r1, [r0, #12]
pop  {r0}
bx   r0
callr3:
bx   r3
"""

CAVE_POSTTINT = """
push {lr}
ldr  r3, [pc, #0]
bl   callr3
ldr  r1, [pc, #0]
ldr  r2, [pc, #0]
str  r2, [r1]
str  r2, [r1, #4]
str  r2, [r1, #8]
str  r2, [r1, #12]
pop  {r0}
bx   r0
callr3:
bx   r3
"""

CAVE_SLOT = """
push {r0, r1, lr}
ldr  r0, [pc, #0]
ldr  r1, [pc, #0]
str  r1, [r0]
str  r1, [r0, #4]
str  r1, [r0, #8]
str  r1, [r0, #12]
pop  {r0, r1}
bl   callfn
pop  {pc}
callfn:
bx   r0
"""


def _apply_isr(p):
    cb = p.cave_asm(CAVE_CBWRAP,
                    literals=[0x05000000, 0x001F001F, 0x080A9AF5,
                              0x05000000, 0x7FFF7FFF],
                    name="diagisr_cbwrap")
    p.patch(CB_LIT[0], CB_LIT[1], (cb | 1).to_bytes(4, "little"), name="diagisr_cblit")
    for site, old, real, color, tag in ISR_BLS:
        cave = p.cave_asm(CAVE_POSTTINT,
                          literals=[real, 0x05000000, (color << 16) | color],
                          name=f"diagisr_{tag}")
        p.bl(site, cave, old, name=f"diagisr_{tag}@{site:08x}")
    slot = p.cave_asm(CAVE_SLOT, literals=[0x05000000, 0x7C1F7C1F],
                      name="diagisr_slot")
    p.bl(SLOT_SITE[0], slot, SLOT_SITE[1], name=f"diagisr_slot@{SLOT_SITE[0]:08x}")
    print("diagbeacon: ISR-chain beacons (round 9) — 7 stages + per-slot MAGENTA")


def apply(p):
    if os.environ.get("SMT2_DIAG_ISR"):
        _apply_isr(p)
        return
    for site, old, redo, color, tag in SITES:
        cave = p.cave_asm(CAVE.format(redo=redo),
                          literals=[0x05000000, (color << 16) | color],
                          name=f"diagbeacon_{tag}")
        p.bl(site, cave, old, name=f"diagbeacon_{tag}@{site:08x}")
    site, old, tag = BLINK_SITE
    cave = p.cave_asm(CAVE_BLINK,
                      literals=[rommap.FRAME_COUNTER, 0x03FF03FF, 0x05000000],
                      name=f"diagbeacon_{tag}")
    p.bl(site, cave, old, name=f"diagbeacon_{tag}@{site:08x}")
    n = len(SITES) + 1
    if os.environ.get("SMT2_DIAG_NOSWI"):
        fill = p.cave_asm(FILL_ASM, literals=[0x001FFFFF], name="diag_noswi_fill")
        p.bl(NOSWI_SITE[0], fill, NOSWI_SITE[1], name="diag_noswi@080eac50")
        n += 1
        print("diagbeacon: composer CpuSet SWI -> inline fill (SWI-race dodge)")
    print(f"diagbeacon: {n} diagnostic hooks (DIAGNOSTIC BUILD)")
