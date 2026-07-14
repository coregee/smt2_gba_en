#!/usr/bin/env python3
"""English current-area names spliced into script messages (event-VM opcode 0x0328).

Script text inserts the current area name via the `{=2803..}` sub-code (event-VM code 0x0328 =
table index 0x28).  Its handler `ScriptOp_DrawCharOrSubstitute 0x08132b40` (switch case 0xE, at
0x0813313c) copies up to ~10 glyph tokens from a SEPARATE area-name table —
`AREA_NAME_TABLE 0x0878F9CC`, 0x14-stride records: u16 id at +0 (sequential 0..18), name glyph
tokens at +2, terminator 0x0301 — into the event-window name staging 0x0203DB08, which is drawn
VWF by cave_msgwin.  (This is NOT the save-screen location table 0x080A548C that the
`location_names` section translates; that one is 0x20-stride and pointer-less, invisible to this
path.)  Symptom that surfaced it: a script line drew "＞イェソド Terminal Stone is here." — the
Yesod (entry 9) area name stayed Japanese.

The table is record-embedded inline text (the audit's contiguous-pointer scan can't see it) and
its ONLY reader is that one handler (verified: exactly one ROM pointer to 0x0878F9CC, at the
literal 0x08133188), so translating the records in place is complete and safe — and renders
proportional through cave_msgwin with no cave.  Budget: the name region is +2..+0x13 = 9 u16, so
8 glyph tokens + the 0x0301 terminator (a longer name would clobber the next record's id).  The
two names over 8 chars are abbreviated (ティフェレト Tiphereth -> "Tiferet"; 金剛神界 Diamond
Realm -> "Diamond").  Entry 18 is a dev placeholder ("ERR", already Latin) — left as-is.

Pure data (like patch_defaultnames), no cave, no Section — the EN tokens flow through the stock
copy + the existing event-window VWF.
"""
import struct
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

AREA_NAME_TABLE = 0x0878F9CC
STRIDE          = 0x14
NAME_OFF        = 2
NAME_SLOTS      = 9          # u16 slots at +2..+0x13 (max 8 glyph tokens + terminator)
TERM            = 0x0301

# (record index, English name).  Index == the record's +0 id (sequential), used as the guard.
# Standard SMT2 area names; each <= 8 glyph tokens to fit the record (see module docstring).
AREA_NAMES = [
    (0,  "Valhalla"),   # ヴァルハラ
    (1,  "Center"),     # センター   (the Valhalla hub)
    (2,  "Holytown"),   # ホーリータウン
    (3,  "Factory"),    # ファクトリー
    (4,  "Arcadia"),    # アルカディア
    (5,  "Shinjuku"),   # シンジュク
    (6,  "Akasaka"),    # アカサカ
    (7,  "Roppongi"),   # ロッポンギ
    (8,  "Tiferet"),    # ティフェレト (Tiphereth, abbreviated to fit 8)
    (9,  "Yesod"),      # イェソド
    (10, "Geburah"),    # ゲブラー
    (11, "Binah"),      # ビナー
    (12, "Ark"),        # 方舟
    (13, "Gov Bldg"),   # 都庁 (Metropolitan Government building)
    (14, "Home"),       # 自宅
    (15, "Diamond"),    # 金剛神界 (Diamond Realm, abbreviated to fit 8)
    (16, "Hospital"),   # 病院
    (17, "Sugamo"),     # スガモ
    # 18 = "ERR" dev placeholder (already Latin) — left as-is.
]


def _char_tok(c):
    if c == " ":            return 0xBC
    if "A" <= c <= "Z":     return 0xDD + ord(c) - ord("A")
    if "a" <= c <= "z":     return 0xFE + ord(c) - ord("a")
    if "0" <= c <= "9":     return 0xCC + ord(c) - ord("0")
    if c == ".":            return 0xCA
    if c == "-":            return 0xC9
    if c == "'":            return 0xC0
    raise SystemExit(f"area name: no English glyph token for {c!r}")


def _encode(name):
    toks = [_char_tok(c) for c in name]
    if len(toks) > NAME_SLOTS - 1:
        raise SystemExit(f"area name {name!r} is {len(toks)} tokens > {NAME_SLOTS - 1} budget")
    toks.append(TERM)
    toks += [0] * (NAME_SLOTS - len(toks))      # clear the rest of the JP name region
    return b"".join(struct.pack("<H", t) for t in toks)


def apply(p):
    for idx, en in AREA_NAMES:
        rec = AREA_NAME_TABLE + idx * STRIDE
        got = struct.unpack("<H", p.read(rec, 2))[0]
        if got != idx:
            raise SystemExit(f"area-name table @0x{rec:08X}: id {got} != index {idx} "
                             "(table moved / wrong address?)")
        addr = rec + NAME_OFF
        old = p.read(addr, NAME_SLOTS * 2)
        p.patch(addr, old.hex(), _encode(en), name=f"area name {idx} {en}")
