#!/usr/bin/env python3
"""Equipment stat-preview panel labels -> English (patch_statpage).

The item/equipment detail panel (Item_RenderDescription 0x080d2d80) shown in shops,
inventory, and the equip menu pages through four stat views with LEFT/RIGHT
(panel state[1] = 0..3, driven by the shop handler in the 0x08130xxx region):

  page 0  StatsPage_DrawLabelGrid     0x080d22c0  the equipment's own stats
            weapon (id<0x80): 攻撃 / 命中 / 攻撃回数 / 追加効果 / 属性
            armor  (id>=0x80): 防御 / 回避 / 相性 / 追加効果 / 属性
  page 1  StatsPage_DrawBaseStats     0x080d2570  wearer STR/INT/MAG/VIT/AGI/LUK
  page 2  StatsPage_DrawDerivedStats  0x080d2788  攻撃/命中 x2 (left=melee, right=ranged)
  page 3  StatsPage_DrawDerivedStats2 0x080d295c  魔法威力 / 魔法効果 / 防御 / 回避

Every label glyph is drawn one-at-a-time by Font_DrawGlyph 0x080ac8d0 from a per-label
literal slot (DAT_080d2xxx).  patch_menu hooks that drawer so a slot holding a ROM
POINTER renders the pooled string VWF instead of a single glyph.  So each label's FIRST
glyph slot is repointed to a pooled English string and its continuation slots are pointed
at an empty string (draw nothing).  The VALUE drawers (element L/N/C, hit-count "1-2",
effect "DEAD"/"JEWEL"/...) already emit ASCII via Font_DrawAsciiString8x16 - left alone.

One shared-literal conflict needs a cave: on the weapon page the 攻 (r6) / 撃 (r5)
literals are reused for both 攻撃 (X=0xf) and 攻撃回数 (X=0x95).  The X=0x95 site's
`add r0,r6,#0; add r1,r4,#0` @0x080d2334 becomes a `bl` to a cave loading the independent
"Hits" pointer; the 撃/回/数 continuation slots blank as usual.  Vocabulary matches
menu_status.json (status screen) so the same labels read identically everywhere.

Run AFTER patch_menu.py (needs its Font_DrawGlyph string-pointer hook).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path
from font.atlas import character_codes  # noqa: E402
import rom_layout as rommap  # noqa: E402
from engine.script.cave_builders import sidecar_cave  # noqa: E402

# (literal addr, expected JP glyph token, English label) -> repoint to pooled EN string.
LABELS = [
    # --- page 0 weapon ---
    (0x080D23D4, 0x08F1, "Atk"),     # 攻撃  (power)        ; col2 攻撃回数 -> "Hits" via cave
    (0x080D23E0, 0x0FFE, "Acc"),     # 命中  (accuracy)
    (0x080D23F0, 0x0D14, "Effect"),  # 追加効果
    (0x080D2400, 0x0C3E, "Use"),     # 属性  (L/N/C usability)
    # --- page 0 armor ---
    (0x080D24D8, 0x0FA9, "Def"),     # 防御
    (0x080D24E4, 0x0699, "Eva"),     # 回避
    (0x080D24EC, 0x0C1A, "Type"),    # 相性
    (0x080D24F4, 0x0D14, "Effect"),  # 追加効果
    (0x080D2504, 0x0C3E, "Use"),     # 属性
    # --- page 1 base stats (single-glyph labels) ---
    (0x080D25C8, 0x10CB, "St"),      # 力 STR
    (0x080D261C, 0x0CBA, "In"),      # 知 INT
    (0x080D266C, 0x0FC3, "Ma"),      # 魔 MAG
    (0x080D26BC, 0x0C5C, "Vi"),      # 体 VIT
    (0x080D270C, 0x0C3C, "Ag"),      # 速 AGI
    (0x080D275C, 0x0606, "Lu"),      # 運 LUK
    # --- page 2 derived (melee left / ranged right; icon distinguishes, label faithful) ---
    (0x080D27F4, 0x08F1, "Atk"),     # 攻撃 melee
    (0x080D285C, 0x0FFE, "Acc"),     # 命中 melee
    (0x080D28C0, 0x08F1, "Atk"),     # 攻撃 ranged
    (0x080D2924, 0x0FFE, "Acc"),     # 命中 ranged
    # --- page 3 derived 2 ---
    (0x080D29E0, 0x0FC3, "Mag Pwr"), # 魔法威力 (magic atk)
    (0x080D2A68, 0x0FC3, "Mag Efc"), # 魔法効果 (magic acc)
    (0x080D2AD4, 0x0FA9, "Def"),     # 防御
    (0x080D2B38, 0x0699, "Eva"),     # 回避
]

# Continuation glyph slots (2nd..4th glyph of a label) -> empty string (draw nothing).
# (addr, expected JP token)
BLANKS = [
    # page 0 weapon
    (0x080D23DC, 0x0861),  # 撃  (shared X=0x1b & 0xa1)
    (0x080D23E4, 0x0CD3),  # 中
    (0x080D23E8, 0x0699),  # 回
    (0x080D23EC, 0x0B67),  # 数
    (0x080D23F4, 0x0669),  # 加
    (0x080D23F8, 0x08D7),  # 効
    (0x080D23FC, 0x0672),  # 果
    (0x080D2404, 0x0B7E),  # 性
    # page 0 armor
    (0x080D24E0, 0x08C3),  # 御
    (0x080D24E8, 0x0EB7),  # 避
    (0x080D24F0, 0x0B7E),  # 性  (shared X=0xa0 & 0xa0,y=0xd)
    (0x080D24F8, 0x0669),  # 加
    (0x080D24FC, 0x08D7),  # 効
    (0x080D2500, 0x0672),  # 果
    # page 2
    (0x080D27FC, 0x0861),  # 撃
    (0x080D2864, 0x0CD3),  # 中
    (0x080D28C8, 0x0861),  # 撃
    (0x080D292C, 0x0CD3),  # 中
    # page 3
    (0x080D29E8, 0x0F81),  # 法
    (0x080D29EC, 0x05BB),  # 威
    (0x080D29F0, 0x10CB),  # 力
    (0x080D2A70, 0x0F81),  # 法
    (0x080D2A74, 0x08D7),  # 効
    (0x080D2A78, 0x0672),  # 果
    (0x080D2ADC, 0x08C3),  # 御
    (0x080D2B40, 0x0EB7),  # 避
]

# weapon-page 攻撃回数 "Hits": replace the X=0x95 `add r0,r6,#0; add r1,r4,#0`.
HITS_HOOK = 0x080D2334
HITS_HOOK_OLD = bytes.fromhex("301c211c")   # add r0,r6,#0 ; add r1,r4,#0
# cave: r0 = &"Hits", redo the replaced `adds r1,r4,#0` (r1 = canvas), bx lr (shared sidecar_cave).


def _char2code():
    return character_codes()


def _encode(c2c, s):
    return b"".join(c2c[ch].to_bytes(2, "little") for ch in s) + b"\x00\x00"


def apply(p):
    c2c = _char2code()

    # Strings are absolute-ptr referenced (DAT_080d2xxx slots / the cave literal), so they live in
    # far DATA (FARDATA_STATLABELS) rather than the scarce BL-range cave pool.  Bump-allocate, dedup.
    far = [rommap.FARDATA_STATLABELS]
    pool = {}
    def strptr(s):
        if s not in pool:
            blob = _encode(c2c, s)
            addr = far[0]
            assert addr + len(blob) < 0x0869D000, "statpage far-data overflow (below 0x0869D000)"
            p.data(blob, at=addr, name=f"statlbl:{s}")
            pool[s] = addr
            far[0] = addr + len(blob)
        return pool[s]

    empty = strptr("")  # shared empty string for blanked continuation slots

    for addr, jp_tok, en in LABELS:
        cur = int.from_bytes(p.read(addr, 4), "little")
        assert cur == jp_tok, f"statpage label @0x{addr:08X}: expected token 0x{jp_tok:04X}, found 0x{cur:08X}"
        p.write(addr, strptr(en).to_bytes(4, "little"))

    for addr, jp_tok in BLANKS:
        cur = int.from_bytes(p.read(addr, 4), "little")
        assert cur == jp_tok, f"statpage blank @0x{addr:08X}: expected token 0x{jp_tok:04X}, found 0x{cur:08X}"
        p.write(addr, empty.to_bytes(4, "little"))

    # 攻撃回数 -> "Hits" (independent of the shared 攻 literal).
    hits = strptr("Hits")
    cave = sidecar_cave(p, name="statpage_hits", hook=HITS_HOOK, hook_old=HITS_HOOK_OLD, ptr=hits,
                        redo="adds r1, r4, #0", bl_name="statpage Hits")

    print(f"statpage: {len(LABELS)} labels EN, {len(BLANKS)} blanks, Hits cave @0x{cave:08X}")
