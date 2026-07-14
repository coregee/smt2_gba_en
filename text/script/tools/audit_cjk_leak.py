#!/usr/bin/env python3
"""Find untranslated Japanese left inside a `replace` (a visible JP leak in EN text).

A `replace` may legitimately contain CJK ONLY as a script-pointer high-word kanji — the
"optail" set 近金吟銀九倶句区狗玖苦 (glyph codes 0x0801..0x080B) that sits right after a
jump/branch/pointer opcode and MUST be preserved verbatim (tr.check_optail_preserved).
Any OTHER kana/kanji in a replace is prose the translator missed.

This walks each translated field, strips {=...}/{TOKEN} spans, and reports any remaining
CJK codepoint that is not in the optail set — with its position, so a partial-translation
leak ("The <jp> is yours") is easy to spot.

Usage:  python -m text.script.tools.audit_cjk_leak [section ...]
"""
import json
import re
import sys
from pathlib import Path

try:
    from text.script.tools._boot import REVIEW
except ModuleNotFoundError:
    from _boot import REVIEW

from font.atlas import GLYPH_MAP  # noqa: E402
from text.script import tr  # noqa: E402

TR = tr.TR

OPTAIL = {GLYPH_MAP[t] for t in range(0x0801, 0x080C) if t in GLYPH_MAP}
TOKEN = re.compile(r"\{=[0-9a-fA-F]+\}|\{[A-Za-z]+\}")
# CJK ranges: hiragana, katakana, CJK unified, halfwidth kana, fullwidth forms punctuation
CJK = re.compile(r"[぀-ヿ㐀-鿿豈-﫿ｦ-ﾟ]")


def leaks(s):
    stripped = TOKEN.sub("", s or "")
    out = []
    for m in CJK.finditer(stripped):
        ch = m.group()
        if ch in OPTAIL:
            continue
        out.append((m.start(), ch))
    return out, stripped


def main():
    secs = sys.argv[1:] or ["dialogue", "story", "lore", "battle_taunts",
                            "negotiate_status", "negotiate_outcomes", "greetings"]
    total = 0
    rows = []
    for sec in secs:
        path = TR / f"{sec}.json"
        if not path.exists():
            continue
        data = json.loads(path.read_text(encoding="utf-8"))
        n = 0
        for e in data:
            flds = ([e[k] for k in ("name", "desc") if k in e]
                    if ("name" in e or "desc" in e) else [e])
            for f in flds:
                r = f.get("replace")
                if r is None:
                    continue
                lk, stripped = leaks(r)
                if lk:
                    n += 1
                    addr = f.get("addr") or (f.get("addrs") or ["?"])[0]
                    chars = "".join(c for _, c in lk)
                    rows.append((sec, addr, len(lk), chars, r))
        print(f"== {sec}: {n} fields with a JP leak ==")
        total += n
    print(f"\nTOTAL fields with untranslated JP (excluding optail kanji): {total}\n")
    for sec, addr, n, chars, r in rows[:80]:
        snippet = r if len(r) < 160 else r[:157] + "..."
        print(f"[{sec} @{addr}] {n} CJK: {chars!r}")
        print(f"    {snippet}")
    out = REVIEW / "cjk_leak_audit.json"
    out.write_text(json.dumps([{"sec": s, "addr": a, "n": n, "chars": c, "replace": r}
                               for s, a, n, c, r in rows], ensure_ascii=False, indent=1),
                   encoding="utf-8")
    print(f"\nfull report -> {out}")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
