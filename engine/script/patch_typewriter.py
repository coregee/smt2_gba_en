#!/usr/bin/env python3
"""Pixel-pace the two message-window typewriters (patch_typewriter).

Both windows revealed ONE unit per tick, so half-width English (~2x the glyphs of
Japanese) scrolled ~2x slower in pixels, and the battle "[race] [name] xN" demon
name (a single 0xF000|id marker token) popped in whole instead of typing out.
cave_typewriter.c reveals by PIXELS instead; see its header.

Hooks:
  1. BATTLE (BattleMenu_RenderMessageObject mode jump-table @0x080ea560).  The
     dispatch does `mov pc, table[mode]` with r5 = the state object, so a veneer
     runs in the renderer's frame.  Repoint:
        table[2] @0x080ea568  (mode 2, typewriter line 1)  -> veneer_mode2
        table[6] @0x080ea578  (mode 6, typewriter line 2)  -> veneer_mode6
     Each veneer copies the full line + advances REVEAL_PX (the worker), then
     enters the stock draw tail (0x080ea6a8 / 0x080ea842) with the original
     register state.  cave_runtext (patch_spritebuf) clips the battle line
     buffers at REVEAL_PX — so the marker name reveals glyph-by-glyph too.
     (`mov pc` keeps Thumb and ignores bit0, like the even stock entries.)
  2. EVENT-VM dialogue/story window: `bl ev_cave` at the state-15 setup site
     (0x0813dcd8 in EventVM_RunStep) — yields only after REVEAL_STEP px have been
     appended since the last yield, else resumes the fetch loop.  The replaced
     state-15 setup is reproduced inside ev_cave; the 0x18 bytes after the `bl`
     become dead (never re-entered — ev_cave branches away).

Depends on patch_spritebuf (cave_runtext clip) and patch_vwf (g_wMsgTextCol is a
pixel accumulator) running first; build_rom orders them before this.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap  # noqa: E402

SRC = Path(__file__).parent / "cave_typewriter.c"

# jump-table slot -> (addr, original handler bytes, cave symbol)
JT_MODE2 = (0x080EA568, "1ca60e08", "veneer_mode2")   # 0x080ea61c
JT_MODE6 = (0x080EA578, "dca70e08", "veneer_mode6")   # 0x080ea7dc

# event-VM state-15 setup hook (ldr r1,[pc,#0x40]; movs r0,#0xf)
EV_HOOK = 0x0813DCD8
EV_HOOK_OLD = "10490f20"

# Flee message ("...tried to escape...and got away!/but failed!", battle.json ids
# 324/325) — Battle_EscapeCommandState loads the pooled EN stream and runs it through
# MessageBox_ComposeWrappedText (SetMode 3 -> render mode 2 = our typewriter), which
# STRIPS the explicit {n} and re-wraps at a fixed 17-glyph count (Gap A) — mangling the
# VWF English line and (with EN words) overflowing the window with extra wrap-newlines.
# Retarget that one call to Menu_ExpandListTemplate, which expands the {=2003} name token
# the same way but PRESERVES the explicit {n} (so the line splits where authored) and the
# 0x315 pause tokens (the dot rhythm), and inserts no auto-wrap.  This call site is reached
# ONLY by the two flee literals (success 0x08126254 / fail 0x081262be), so nothing else is
# affected.  Both composers write the 64-u16 compose buffer @0x0203CAEC, so the EN flee
# streams are kept within that budget (see battle.json).
FLEE_WRAP_HOOK = 0x080EC864
FLEE_WRAP_OLD  = "fff736fb"            # bl MessageBox_ComposeWrappedText (0x080EBED4)


def apply(p):
    p.cave_c(SRC, name="typewriter")
    sy = p.cave_c_syms
    for addr, old, sym in (JT_MODE2, JT_MODE6):
        tgt = sy[sym]                                   # even Thumb addr (mov pc keeps Thumb)
        assert tgt % 2 == 0, f"{sym} odd address 0x{tgt:08X}"
        p.patch(addr, old, tgt.to_bytes(4, "little"), name=f"typewriter-jt@{addr:08x}")
    p.bl(EV_HOOK, sy["ev_cave"], EV_HOOK_OLD, name="typewriter-ev")
    p.bl(FLEE_WRAP_HOOK, rommap.Menu_ExpandListTemplate, FLEE_WRAP_OLD, name="typewriter-flee-wrap")
    print(f"typewriter: battle modes 2/6 -> veneers @0x{sy['veneer_mode2']:08X}/"
          f"0x{sy['veneer_mode6']:08X}; event-VM yield-gate @0x{sy['ev_cave']:08X} "
          f"(step {rommap.REVEAL_STEP}px)")
