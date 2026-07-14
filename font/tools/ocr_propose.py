#!/usr/bin/env python3
"""OCR every used-but-unmapped kanji and write proposals to glyph_ocr_baseline.tsv.

Renders each target glyph to an in-memory PNG, runs PaddleOCR (recognition-only,
lang=japan), normalizes simplified->JP shinjitai (generated/simp2jp.tsv), and merges
the predictions into the baseline file as `code<TAB>char<TAB>ocrSCORE`. Existing
baseline rows whose code is NOT re-OCR'd here are preserved.

Run under the OCR venv (Python 3.11):
    .venv-ocr\\Scripts\\python.exe -m font.tools.ocr_propose
"""
from __future__ import annotations
import io, sys
from PIL import Image

try:
    from ._boot import GENERATED, REVIEW, ROM as ROM_PATH
    from . import build_review_html as B
except ImportError:
    from _boot import GENERATED, REVIEW, ROM as ROM_PATH
    import build_review_html as B

from font.generated.glyph_map import GLYPH_MAP
from font.script.render_glyph import render_glyph_pixels

ROM = ROM_PATH.read_bytes()
BASELINE = GENERATED / "glyph_ocr_baseline.tsv"
SIMP2JP = GENERATED / "simp2jp.tsv"
LEVELS = {0: 255, 1: 100, 2: 0, 3: 160}
PAD, SCALE = 6, 14


def glyph_png(code: int) -> str:
    """Render glyph to a padded white-on-black-ink PNG; return temp file path."""
    g = render_glyph_pixels(ROM, code)
    w = h = 16 * SCALE + PAD * 2 * SCALE
    img = Image.new("L", (w, h), 255)
    px = img.load()
    for y in range(16):
        for x in range(16):
            v = LEVELS[g[y][x]]
            for dy in range(SCALE):
                for dx in range(SCALE):
                    px[(x + PAD) * SCALE + dx, (y + PAD) * SCALE + dy] = v
    REVIEW.mkdir(parents=True, exist_ok=True)
    p = REVIEW / "_ocrtmp.png"
    img.save(p)
    return str(p)


def load_simp2jp() -> dict[str, str]:
    m = {}
    if SIMP2JP.exists():
        for i, line in enumerate(SIMP2JP.read_text(encoding="utf-8").splitlines()):
            if i and "\t" in line:
                a, b = line.split("\t")[:2]
                m[a] = b
    return m


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    mapped = set(GLYPH_MAP)
    targets = sorted(c for c in B.collect_unmapped_used(mapped) if c >= 0x04A4)
    print(f"OCR target: {len(targets)} used+unmapped kanji", flush=True)

    simp2jp = load_simp2jp()
    from paddleocr import TextRecognition
    model = TextRecognition(model_name="PP-OCRv5_mobile_rec", enable_mkldnn=False)

    results: dict[int, tuple[str, float]] = {}
    for n, code in enumerate(targets):
        path = glyph_png(code)
        pred, score = "", 0.0
        for res in model.predict(path):
            pred = res.get("rec_text", "")
            score = res.get("rec_score", 0.0)
        pred = "".join(simp2jp.get(ch, ch) for ch in pred).strip()
        # keep only a single CJK char as a proposal; blank if OCR gave punctuation/latin
        pred = "".join(ch for ch in pred if "一" <= ch <= "鿿")
        if pred:
            results[code] = (pred[:1], score)
        if (n + 1) % 25 == 0:
            print(f"  ...{n+1}/{len(targets)}", flush=True)

    # preserve existing baseline rows not re-OCR'd; overwrite/extend with new ones
    keep = []
    if BASELINE.exists():
        for i, line in enumerate(BASELINE.read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            code = int(line.split("\t")[0], 16)
            if code not in results:
                keep.append(line)

    lines = ["code\tchar\tconf"] + keep
    for code in sorted(results):
        ch, sc = results[code]
        lines.append(f"{code:04X}\t{ch}\tocr{sc:.2f}")
    BASELINE.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"wrote {len(results)} OCR proposals (+{len(keep)} preserved) -> {BASELINE}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
