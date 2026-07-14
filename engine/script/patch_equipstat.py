#!/usr/bin/env python3
"""Decouple the equip-preview 攻撃回数 (hit count) from the 攻撃 (attack) label.

The equip-status bottom panel is drawn by FUN_080ccab4. In its weapon layout the
"攻撃" (attack power) label and the "攻撃回数" (number of attacks) label SHARE the same
攻 / 撃 glyph literals (DAT_080ccbb0 / DAT_080ccbb8, held in r5 / r4): col1 draws them at
X=9, col2 redraws the very same r5/r4 at X=0x49/0x55. So once 攻撃 is translated, both
columns would read identically — they can't say "Atk" and "Hits" at once.

This patch replaces the col2 攻 draw setup `add r0,r5,#0; add r1,r6,#0` (4 bytes
@0x080ccb20) with a `bl` to a tiny cave that loads an independent "Hits" string pointer
into r0 (r1 stays buf). The following `mov r2,#0x49; mov r3,#0x8b; bl 0x080ac8d0` then
draws "Hits" VWF at col2 via the menu-label hook (patch_menu). col1's 攻撃 -> "Atk" and
the residual 回/数 cells are handled in menu_status.json. Run AFTER patch_menu.py.
"""
import json
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from font.script.custom_glyphs import custom_chars  # noqa: E402
from paths import ProjectPaths
from engine.script import rommap                                     # noqa: E402
from engine.script.cave_builders import sidecar_cave            # noqa: E402

DATA = ProjectPaths.discover().font_config_root
B = rommap.ROM_BASE

HOOK = 0x080CCB20          # FUN_080ccab4: col2 攻 draw `add r0,r5,#0; add r1,r6,#0` (28 1c 31 1c)
HOOK_OLD = bytes.fromhex("281c311c")
HITS = "Hits"
# cave: r0 = &"Hits", redo the replaced `adds r1,r6,#0` (r1 = buf), bx lr (shared sidecar_cave).


def char2code():
    m = {}
    for k, v in json.loads((DATA / "glyph_map_data.json").read_text(encoding="utf-8")).items():
        m.setdefault(v, int(k, 16))
    m.update(custom_chars())
    return m


def apply(p):
    c2c = char2code()
    hits = b"".join(c2c[ch].to_bytes(2, "little") for ch in HITS) + b"\x00\x00"
    hits_addr = p.data(hits, name="Hits")
    sidecar_cave(p, name="equipstat", hook=HOOK, hook_old=HOOK_OLD, ptr=hits_addr,
                 redo="adds r1, r6, #0")
