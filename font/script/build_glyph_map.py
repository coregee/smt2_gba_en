#!/usr/bin/env python3
"""Consolidate the confirmed glyph map and validate it against action names.

Sources, in priority order (low -> high):
  computed base blocks (ASCII / hiragana) -> OVERRIDES (manual fixes) ->
  font/config/glyph_map_data.json (human-confirmed truth) ->
  --import-tsv PATH (a reviewed code<TAB>char TSV from the HTML review page).

Outputs:
  - font/generated/glyph_map.py   (GLYPH_MAP runtime dict: confirmed + baselines)
  - font/generated/glyph-map.tsv  (code<TAB>char, sorted)
With --freeze, the merged confirmed map is written back to glyph_map_data.json.
Then decodes every action name with the merged map to verify coherence.
"""

from __future__ import annotations
import sys
from pathlib import Path

try:
    from font.script._boot import CONFIG, GENERATED, ROM
except ModuleNotFoundError:
    from _boot import CONFIG, GENERATED, ROM

ROM_BASE = 0x08000000
ACTION_TBL = 0x0819B9F4
ACTION_SZ = 0x1C

# Manual fixes (highest priority). Each validated by the skill it appears in.
OVERRIDES: dict[int, str] = {
    0x0861: "撃",   # 電撃 でんげき
    0x0D24: "潰",   # 押し潰し おしつぶし
    0x04B8: "痺",   # 麻痺 まひ (OCR 库)
    0x0A54: "収",   # 吸収 きゅうしゅう (OCR 收, simplified)
    0x0CB2: "弾",   # 散弾 さんだん (OCR 弹, simplified)
    0x087C: "拳",   # 鉄拳/裏拳 (OCR 举)
    0x0FF7: "霧",   # 誘惑の霧 ゆうわくのきり (OCR 霖)
    0x0ACC: "掌",   # 菩薩掌 ぼさつしょう (OCR 芊)
    0x109E: "裏",   # 裏拳 うらけん
    0x096F: "砕",   # 玉砕 ぎょくさい (OCR 碎, simplified)
    0x10FC: "連",   # 連射 れんしゃ (OCR 速)
    0x0B8C: "聖",   # 聖なる光 (TSV row used spaces not a tab)
    0x0B8D: "声",   # 愚者の声 / ツァバトの声
    0x0D94: "投",   # 真空投げ
    # --- katakana table completion (crib_demons + grid + render-verified) ---
    0x017E: "ゥ", 0x018A: "ケ", 0x018B: "ゲ", 0x0195: "ゼ", 0x0196: "ソ",
    0x0197: "ゾ", 0x019B: "ヂ", 0x019E: "ヅ", 0x01A5: "ヌ", 0x01A7: "ノ",
    0x01B2: "ベ", 0x01B4: "ホ", 0x01BC: "モ", 0x01BE: "ヤ", 0x01BF: "ュ",
    0x01C0: "ユ", 0x01C2: "ヨ", 0x01CE: "ヴ",
    0x0005: "・",   # nakaguro (demon compound names)
    # --- hiragana (crib_items / context) ---
    0x0127: "が", 0x0130: "さ", 0x0138: "そ",
    # --- demon resist-text vocab (name field overruns into resist text) ---
    0x099E: "殺",   # 呪殺を反射 (Jack the Ripper resist text)
    # --- manual HTML-review corrections (2026-06-05) ---
    0x0052: "ћ",    # macca currency symbol (rendered as Cyrillic tshe)
    0x0119: "♥",    # heart (was mis-ID'd as ♪)
    0x01FE: "ζ",    # Greek zeta (bank-2 'a' slot)
    0x01FF: "η",    # Greek eta (bank-2 'b' slot)
    0x026E: "ん",   # hiragana n (duplicate in bank 2)
    0x0483: "Ⅱ",   # serif roman numeral II (game title)
    0x0498: "$",    # compact ドル ligature (single glyph) -> "$"
    # bank-0 punctuation the baseline collector skips (it scans 0x01xx+)
    0x0018: "々",   # iteration mark (嬉々として, 猛々しい)
    0x0029: "（",   # open paren
    0x002A: "）",   # close paren
    0x0041: "＝",   # equals / separator
    0x0026: "'",    # apostrophe (IT'S A ...)
    0x001E: "／",   # slash — menu separator (アイテム使用／整頓／…)
    0x0044: "＞",   # cursor / chevron at line starts
    0x004F: "￥",   # yen sign (shop: ￥(amount)で引き取り)
    0x0004: ".",    # half-width period for Latin initials (H.P.ラブクラフト, I.C.B.M) — 6px, missed by the >8px used-glyph scan
    0x0E24: "脳",   # 脳髄 / 洗脳 / 脳はコンピューター (render + context)
}

# ASCII glyphs (render-verified offsets):
#  digits/uppercase: code = ascii + 0x9C  ('0'=0xCC, 'A'=0xDD, 'S'=0xEF)
#  lowercase:        code = ascii + 0x9D  ('a'=0xFE, 'c'=0x100, 'x'=0x115)  [bank 1]
#  lowercase bank 2: code = ascii + 0x19D ('c'=0x200)  -- alt font sheet
ASCII_BLOCK: dict[int, str] = {}
for _ch in "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    ASCII_BLOCK[ord(_ch) + 0x9C] = _ch
for _ch in "abcdefghijklmnopqrstuvwxyz":
    ASCII_BLOCK[ord(_ch) + 0x9D] = _ch       # bank 1: a=0xFE .. z=0x117
# bank-2 lowercase starts at c=0x200 (a/b slots 0x1FE/0x1FF hold Greek ζ/η)
for _ch in "cdefghijklmnopqrstuvwxyz":
    ASCII_BLOCK[ord(_ch) + 0x19D] = _ch      # bank 2: c=0x200 .. z=0x217

# Hiragana gojūon table at 0x011C-0x016E (small/dakuten interleaved, same scheme
# as the katakana block). All 44 previously-confirmed hiragana match this order
# with zero conflicts; render-verified だ/も/ろ/こ/ね and the archaic ゎゐゑ.
_HIRA_SEQ = ("ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞ"
             "ただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼ"
             "ぽまみむめもゃやゅゆょよらりるれろゎわゐゑをん")
HIRAGANA_BLOCK = {0x011C + i: ch for i, ch in enumerate(_HIRA_SEQ)}


def u16(rom: bytes, addr: int) -> int:
    o = addr - ROM_BASE
    return int.from_bytes(rom[o:o + 2], "little")


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("--freeze", action="store_true",
                    help="write the merged map back to glyph_map_data.json (promote)")
    ap.add_argument("--import-tsv", metavar="PATH",
                    help="apply a reviewed code<TAB>char TSV as overrides (from the HTML review page)")
    args = ap.parse_args()

    rom = ROM.read_bytes()

    # Stable source: the frozen, confirmed map (font/config/).
    # This is the canonical committed data and the source of truth.
    import json
    data_path = CONFIG / "glyph_map_data.json"
    merged: dict[int, str] = {}
    # Priority (low -> high): computed bases -> OVERRIDES (code-side manual fixes)
    # -> frozen JSON (human-confirmed truth) -> reviewed TSV (current session).
    # So a human confirmation always wins over my defaults, but new code-side
    # additions still apply where the JSON has no entry yet.
    merged.update(ASCII_BLOCK)
    merged.update(HIRAGANA_BLOCK)
    merged.update(OVERRIDES)
    # Authored English punctuation (drawn into blank ASCII slots; see custom_glyphs.py
    # + patch_font.py). Harmless for base-ROM dumps (these codes never appear in JP text).
    from font.script.custom_glyphs import custom_chars
    merged.update({code: ch for ch, code in custom_chars().items()})
    if data_path.exists():
        merged.update({int(k, 16): v for k, v in
                       json.loads(data_path.read_text(encoding="utf-8")).items()})
    if args.import_tsv:
        for i, line in enumerate(Path(args.import_tsv).read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            parts = line.split("\t")
            if len(parts) >= 2 and parts[1].strip():
                merged[int(parts[0], 16)] = parts[1].strip()  # human review wins
        print(f"applied reviewed TSV: {args.import_tsv}")

    # Normalize simplified-Chinese -> Japanese shinjitai (PaddleOCR leans Chinese).
    # Table generated by tools/gen_simp2jp.py (opencc s2t->t2jp, false positives
    # excluded). Applied per-character to every value, confirmed included.
    simp2jp = {}
    sjp = GENERATED / "simp2jp.tsv"
    if sjp.exists():
        for i, line in enumerate(sjp.read_text(encoding="utf-8").splitlines()):
            if i and "\t" in line:
                a, b = line.split("\t")[:2]
                simp2jp[a] = b
    if simp2jp:
        n_norm = 0
        for code, v in list(merged.items()):
            nv = "".join(simp2jp.get(ch, ch) for ch in v)
            if nv != v:
                merged[code] = nv
                n_norm += 1
        if n_norm:
            print(f"normalized {n_norm} simplified->JP in confirmed map")

    # Freeze writes ONLY the confirmed map (no OCR baselines) — keeps the JSON
    # the source of truth for human-verified glyphs.
    if args.freeze:
        data_path.write_text(
            json.dumps({f"{c:04X}": merged[c] for c in sorted(merged)},
                       ensure_ascii=False, indent=0),
            encoding="utf-8")
        print(f"froze {len(merged)} confirmed glyphs to {data_path}")

    # Runtime map = confirmed (wins) + OCR baselines (gap-fill, low-confidence).
    # Used by dumps/render so text decodes maximally; baselines flagged for review.
    baselines: dict[int, str] = {}
    bpath = GENERATED / "glyph_ocr_baseline.tsv"
    if bpath.exists():
        for i, line in enumerate(bpath.read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            p = line.split("\t")
            if len(p) >= 2 and p[1].strip():
                v = p[1].strip()
                baselines[int(p[0], 16)] = "".join(simp2jp.get(ch, ch) for ch in v)
    runtime = {**baselines, **merged}

    py = GENERATED / "glyph_map.py"
    with py.open("w", encoding="utf-8") as f:
        f.write('"""SMT2 GBA glyph code -> Unicode map (runtime).\n\n')
        f.write("Built by tools/build_glyph_map.py: confirmed map (glyph_map_data.json,\n")
        f.write("verified) + OCR baselines (glyph_ocr_baseline.tsv, LOW-CONFIDENCE,\n")
        f.write('to be verified via glyph_review.html)."""\n\n')
        f.write("GLYPH_MAP = {\n")
        for code in sorted(runtime):
            f.write(f"    0x{code:04X}: {runtime[code]!r},\n")
        f.write("}\n")
    print(f"wrote {py}  ({len(runtime)} glyphs: {len(merged)} confirmed + "
          f"{len(runtime) - len(merged)} OCR baselines)")

    tsv = GENERATED / "glyph-map.tsv"
    with tsv.open("w", encoding="utf-8") as f:
        f.write("code\tchar\n")
        for code in sorted(runtime):
            f.write(f"{code:04X}\t{runtime[code]}\n")
    print(f"wrote {tsv}")

    # validate: decode every action name
    print("\n=== action names decoded with merged map ===")
    unresolved: set[int] = set()
    for aid in range(0xA0):
        rec = ACTION_TBL + aid * ACTION_SZ
        codes = [u16(rom, rec + 6 + i * 2) for i in range(8)]
        codes = [c for c in codes if c not in (0, 0x0301)]
        if not codes:
            continue
        s = ""
        for c in codes:
            if c in merged:
                s += merged[c]
            else:
                s += f"<{c:04X}>"
                unresolved.add(c)
        print(f"  {aid:02X}: {s}")

    if unresolved:
        print(f"\nstill unresolved ({len(unresolved)}): " +
              " ".join(f"{c:04X}" for c in sorted(unresolved)))
    else:
        print("\nall action-name glyphs resolved.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
