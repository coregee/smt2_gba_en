#!/usr/bin/env python3
"""Sweep the glyph map for simplified-Chinese characters and emit a
simplified->Japanese-shinjitai normalization table (via opencc s2t -> t2jp).

Run under the OCR venv (has opencc):
    .venv-ocr\\Scripts\\python.exe tools\\gen_simp2jp.py

Writes tools/simp2jp.tsv (simp<TAB>jp). The build tools load this to normalize
every kanji value (confirmed + baseline) to its proper Japanese form.
"""
import json
import sys
from pathlib import Path
import opencc

try:
    from font.script._boot import CONFIG, GENERATED
except ModuleNotFoundError:
    from _boot import CONFIG, GENERATED
s2t = opencc.OpenCC("s2t")
t2jp = opencc.OpenCC("t2jp")

# Inputs that are already valid Japanese kanji but ALSO happen to be the
# simplified form of a *different* character — opencc converts them backwards.
# Never normalize these.
EXCLUDE = set("占咤岩干征戯斗猪碍穎里携体並戸糸芸缶欠才万与蝎咸")


def to_jp(ch: str) -> str:
    return t2jp.convert(s2t.convert(ch))


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    chars = set()
    for v in json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8")).values():
        chars.update(v)
    bp = GENERATED / "glyph_ocr_baseline.tsv"
    if bp.exists():
        for i, ln in enumerate(bp.read_text(encoding="utf-8").splitlines()):
            if i and ln.strip():
                p = ln.split("\t")
                if len(p) >= 2:
                    chars.update(p[1])

    mapping = {}
    for c in sorted(chars):
        if not ("一" <= c <= "鿿") or c in EXCLUDE:   # CJK only, skip valid-JP
            continue
        jp = to_jp(c)
        if jp != c and len(jp) == 1 and "一" <= jp <= "鿿":
            mapping[c] = jp

    out = GENERATED / "simp2jp.tsv"
    with out.open("w", encoding="utf-8") as f:
        f.write("simp\tjp\n")
        for c in sorted(mapping):
            f.write(f"{c}\t{mapping[c]}\n")
    print(f"wrote {out}  ({len(mapping)} simplified->JP pairs found in map)")
    print("sample:", "  ".join(f"{k}->{v}" for k, v in list(mapping.items())[:30]))


if __name__ == "__main__":
    raise SystemExit(main())
