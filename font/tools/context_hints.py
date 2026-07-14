#!/usr/bin/env python3
"""For each remaining unmapped/baseline glyph, capture its best context (decoded
with the CONFIRMED map only) so the kanji can be inferred from surrounding text.

Confirmed map = glyph_map_data.json. Baselines = glyph_ocr_baseline.tsv (shown as
the OCR guess). Target glyph marked ★. Ranks by frequency; prints contexts.
"""
import json
import sys
from collections import Counter, defaultdict

try:
    from ._boot import CONFIG, GENERATED, ROM as ROM_PATH
except ImportError:
    from _boot import CONFIG, GENERATED, ROM as ROM_PATH

DATA = GENERATED
ROM = ROM_PATH.read_bytes()
B = 0x08000000
u16 = lambda o: int.from_bytes(ROM[o:o + 2], "little")
u32 = lambda o: int.from_bytes(ROM[o:o + 4], "little")

CONF = {int(k, 16): v for k, v in
        json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8")).items()}
BASE = {}
bp = DATA / "glyph_ocr_baseline.tsv"
if bp.exists():
    for i, ln in enumerate(bp.read_text(encoding="utf-8").splitlines()):
        if i and ln.strip():
            p = ln.split("\t")
            if len(p) >= 2 and p[1].strip():
                BASE[int(p[0], 16)] = p[1].strip()

TARGETS = set(BASE)  # unmapped/baseline codes to resolve


def is_target(c):
    return c in TARGETS


def ch(c):
    if c in CONF:
        return CONF[c]
    if c == 0x0300:
        return "/"
    if 0x0300 <= c < 0x0400:
        return ""        # control/opcode: drop
    return None          # unmapped non-target


def collect():
    """Return code -> list of context strings (target marked ★), + frequency."""
    ctx = defaultdict(list)
    freq = Counter()

    def emit(codes):
        for i, c in enumerate(codes):
            if not is_target(c):
                continue
            freq[c] += 1
            # build window of confirmed text around i
            left = []
            for j in range(i - 1, max(-1, i - 10), -1):
                g = ch(codes[j])
                if g is None:
                    break
                left.append(g)
            right = []
            for j in range(i + 1, min(len(codes), i + 11)):
                g = ch(codes[j])
                if g is None:
                    break
                right.append(g)
            s = "".join(reversed(left)) + "★" + "".join(right)
            if len(s) >= 4:
                ctx[c].append(s)

    # dialogue
    seen = set()
    for src in range(0x08032de0 - B, 0x08035bb4 - B, 4):
        p = u32(src)
        if not (B <= p < B + len(ROM)) or (p - B) in seen:
            continue
        seen.add(p - B)
        codes = []
        for k in range(120):
            c = u16(p - B + k * 2)
            if c == 0 or c == 0x0301:
                break
            codes.append(c)
        emit(codes)
    # lore + story as long streams (split on 0/0301)
    for start, size in [(0x08009E80, 0xC000), (0x08049000, 0x5FC00)]:
        o = start - B
        codes = []
        while o < start - B + size:
            c = u16(o)
            if c == 0 or c == 0x0301:
                if codes:
                    emit(codes)
                codes = []
            else:
                codes.append(c)
            o += 2
    return ctx, freq


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    ctx, freq = collect()
    # pick the clearest (longest) context per code, ranked by frequency
    out = []
    for code, n in freq.most_common():
        if code not in ctx or not ctx[code]:
            continue
        best = max(ctx[code], key=len)
        out.append((code, n, BASE.get(code, "?"), best))
    print(f"{'code':>5} {'freq':>4} {'ocr':>3}  context (★ = the glyph)")
    for code, n, g, s in out:
        print(f"{code:04X} {n:4d}  {g:>2}  {s[:54]}")


if __name__ == "__main__":
    raise SystemExit(main())
