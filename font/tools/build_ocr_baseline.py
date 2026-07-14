#!/usr/bin/env python3
"""Fill every remaining unmapped glyph with its best OCR guess as a LOW-CONFIDENCE
baseline (for later human verification).

Aggregates OCR predictions from all review_*/review.tsv batches, normalizes
simplified-Chinese kanji to Japanese, and writes generated/glyph_ocr_baseline.tsv
(code<TAB>char<TAB>conf) for the currently-unmapped codes used in the text.
build_glyph_map.py merges this as the lowest-priority source (gap-fill only),
and the review page flags these rows as OCR baselines to verify.

Prints which unmapped codes still lack any OCR prediction (need a fresh pass).
"""
from __future__ import annotations
import json
import sys

try:
    from ._boot import CONFIG, GENERATED, REVIEW, ROM as ROM_PATH
except ImportError:
    from _boot import CONFIG, GENERATED, REVIEW, ROM as ROM_PATH

from font.script.render_glyph import render_glyph_pixels

DATA = GENERATED
ROM = ROM_PATH.read_bytes()
B = 0x08000000
u16 = lambda o: int.from_bytes(ROM[o:o + 2], "little")
u32 = lambda o: int.from_bytes(ROM[o:o + 4], "little")

# simplified-Chinese -> Japanese (PP-OCR leans Chinese)
NORM = {"强": "強", "单": "単", "变": "変", "龄": "齢", "唤": "喚", "盘": "盤",
        "级": "級", "样": "様", "倾": "傾", "贝": "貝", "转": "転", "现": "現",
        "实": "実", "龙": "竜", "边": "辺", "间": "間", "关": "関", "门": "門",
        "队": "隊", "应": "応", "顏": "顔", "两": "両", "灵": "霊", "严": "厳",
        "卖": "売", "齐": "斉", "补": "補", "别": "別", "质": "質", "气": "気",
        "继": "継", "带": "帯", "县": "県", "轮": "輪", "龟": "亀", "齿": "歯",
        "测": "測", "满": "満", "观": "観", "战": "戦", "铭": "銘", "锦": "錦",
        "复": "復", "俱": "倶", "碎": "砕", "举": "挙", "収": "収", "弹": "弾"}


def load_simp2jp() -> dict[str, str]:
    m = {}
    p = DATA / "simp2jp.tsv"
    if p.exists():
        for i, line in enumerate(p.read_text(encoding="utf-8").splitlines()):
            if i and "\t" in line:
                a, b = line.split("\t")[:2]
                m[a] = b
    return m


SIMP2JP = load_simp2jp()


def jp(ch: str) -> str:
    return "".join(SIMP2JP.get(c, c) for c in ch)


def aggregate_ocr() -> dict[int, tuple[str, float]]:
    best: dict[int, tuple[str, float]] = {}
    # Legacy OCR review batches (deleted after the map was completed). If any
    # review*/review.tsv exist (fresh OCR pass), they're aggregated here.
    for tsv in REVIEW.glob("review*/review.tsv"):
        for i, line in enumerate(tsv.read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            p = line.split("\t")
            if len(p) < 4 or not p[1]:
                continue
            try:
                code = int(p[0], 16)
                conf = float(p[3])
            except ValueError:
                continue
            ch = NORM.get(p[1], p[1])
            if code not in best or conf > best[code][1]:
                best[code] = (ch, conf)
    return best


def realglyph(c: int) -> bool:
    if (c >> 8) > 0x12:
        return False
    try:
        g = render_glyph_pixels(ROM, c)
    except Exception:
        return False
    return sum(1 for row in g for v in row if v) > 8


def unmapped_used(mapped: set[int]) -> set[int]:
    used = set()

    def consider(c):
        if (0x0100 <= c < 0x0300 or 0x0400 <= c <= 0x12FF) and c not in mapped:
            used.add(c)

    seen = set()
    for src in range(0x08032de0 - B, 0x08035bb4 - B, 4):
        p = u32(src)
        if not (B <= p < B + len(ROM)) or (p - B) in seen:
            continue
        seen.add(p - B)
        for k in range(120):
            c = u16(p - B + k * 2)
            if c == 0 or c == 0x0301:
                break
            consider(c)
    for o in range(0x08009E80 - B, 0x08009E80 - B + 0xC000, 2):
        consider(u16(o))
    for o in range(0x08049000 - B, 0x080A8C00 - B, 2):
        consider(u16(o))
    return {c for c in used if realglyph(c)}


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    mapped = {int(k, 16) for k in
              json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8"))}
    ocr = aggregate_ocr()
    unmapped = unmapped_used(mapped)

    out = []
    have = miss = []
    have, miss = [], []
    for c in sorted(unmapped):
        if c in ocr and ocr[c][0].strip():
            ch, conf = ocr[c]
            out.append((c, ch, conf))
            have.append(c)
        else:
            miss.append(c)

    # Context suggestions override raw OCR (stronger; marked 'ctx').
    suggest = {}
    spath = DATA / "glyph_context_suggest.tsv"
    if spath.exists():
        for i, line in enumerate(spath.read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            p = line.split("\t")
            if len(p) >= 2 and p[1].strip():
                suggest[int(p[0], 16)] = p[1].strip()
    out = [(c, suggest[c], "ctx") if c in suggest else (c, ch, f"{conf:.2f}")
           for c, ch, conf in out]
    # include suggestions for codes that had no OCR prediction at all
    have_codes = {c for c, _, _ in out}
    for c in sorted(suggest):
        if c in unmapped and c not in have_codes:
            out.append((c, suggest[c], "ctx"))
            if c in miss:
                miss.remove(c)

    tsv = DATA / "glyph_ocr_baseline.tsv"
    with tsv.open("w", encoding="utf-8") as f:
        f.write("code\tchar\tconf\n")
        for c, ch, conf in sorted(out):
            f.write(f"{c:04X}\t{jp(ch)}\t{conf}\n")
    print(f"unmapped used codes: {len(unmapped)}")
    print(f"  baseline-filled from OCR: {len(have)} -> {tsv}")
    print(f"  no OCR prediction yet:    {len(miss)}")
    if miss:
        (DATA / "baseline_missing.txt").write_text(
            " ".join(f"{c:04X}" for c in miss))
        print(f"  wrote {DATA / 'baseline_missing.txt'} ({len(miss)} codes to OCR)")


if __name__ == "__main__":
    raise SystemExit(main())
