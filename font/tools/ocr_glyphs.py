#!/usr/bin/env python3
"""Run PaddleOCR over rendered glyph PNGs and score against ground truth.

Reads glyph_out/manifest.tsv (file, code, truth), runs PaddleOCR (lang=japan)
on each PNG, prints per-glyph predicted vs. truth, and a summary accuracy.

Must run under the OCR venv (Python 3.11):
    .venv-ocr\\Scripts\\python.exe -m font.tools.ocr_glyphs --dir glyph_out
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path


def load_manifest(path: Path) -> list[tuple[str, str, str]]:
    rows = []
    for i, line in enumerate(path.read_text(encoding="utf-8").splitlines()):
        if i == 0 or not line.strip():
            continue
        parts = line.split("\t")
        if len(parts) >= 3:
            rows.append((parts[0], parts[1], parts[2]))
        elif len(parts) == 2:
            rows.append((parts[0], parts[1], ""))
    return rows


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default="glyph_out", help="dir with manifest.tsv + PNGs")
    ap.add_argument("--engine", choices=["paddle", "manga"], default="paddle")
    ap.add_argument("--model", default="PP-OCRv5_mobile_rec",
                    help="paddle recognition model (mobile is stronger on isolated kana)")
    ap.add_argument("--normalize", action="store_true",
                    help="apply confusion fixups (e.g. ASCII '-' -> 'ー')")
    ap.add_argument("--show-raw", action="store_true", help="print raw OCR predictions")
    args = ap.parse_args()

    # common OCR confusions for isolated glyphs -> canonical JP char
    NORM = {"-": "ー", "ー": "ー", "−": "ー", "100": "", " ": ""}

    def normalize(s: str) -> str:
        if not args.normalize:
            return s
        return NORM.get(s, s)

    d = Path(args.dir)
    rows = load_manifest(d / "manifest.tsv")
    print(f"loaded {len(rows)} glyphs from {d}/manifest.tsv")

    scores: dict[str, float] = {}

    if args.engine == "paddle":
        # Recognition-only: PaddleOCR's detection stage is trained on text lines
        # and won't localize a single isolated glyph, so we feed the whole image
        # straight to the recognizer. enable_mkldnn=False avoids a oneDNN PIR crash.
        from paddleocr import TextRecognition
        model = TextRecognition(model_name=args.model, enable_mkldnn=False)

        def predict(img_path: str) -> str:
            out = model.predict(img_path)
            texts = []
            for res in out:
                t = res.get("rec_text", "")
                scores[img_path] = res.get("rec_score", 0.0)
                if args.show_raw:
                    print("   raw:", repr(t), res.get("rec_score"))
                texts.append(t)
            return normalize("".join(texts))
    else:
        from manga_ocr import MangaOcr
        mocr = MangaOcr()

        def predict(img_path: str) -> str:
            return normalize(mocr(img_path))

    correct = 0
    total = 0
    misses = []
    for fname, code, truth in rows:
        path = str(d / fname)
        pred = predict(path).strip()
        sc = scores.get(path, 0.0)
        total += 1
        ok = (pred == truth)
        if ok:
            correct += 1
        else:
            misses.append((code, truth, pred, sc))
        mark = "OK " if ok else "XX "
        print(f"  {mark} {code}  truth={truth!r:6s} pred={pred!r:6s} conf={sc:.2f}")

    print()
    print(f"accuracy: {correct}/{total} = {correct/total*100:.1f}%")
    if misses:
        print(f"misses ({len(misses)}):")
        for code, truth, pred, sc in misses:
            print(f"  {code}: truth={truth!r} pred={pred!r} conf={sc:.2f}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
