#!/usr/bin/env python3
"""Render the translation corpus to generated/readable/<section>.txt.

Replaces the old bespoke dump_script.py. The translation files
(text/corpus/*.json) already hold every decoded string in their `original`
field (names, descriptions, dialogue, lore, story, system, menus, …), so the
readable dumps are now just a view over that single source of truth.

Each entry is printed as `[key] <original>` with `{n}` newlines expanded and
control tokens ({WAIT}/{PAGE}/{ALEPH}/…) left intact. If a translation has been
written, it is shown on an indented `-> ` line beneath the original.

Usage:  python -m text.script.tools.render_dumps
"""
from __future__ import annotations
import argparse
import json
import sys
from pathlib import Path

try:
    from text.script.tools._boot import PATHS
except ModuleNotFoundError:
    from _boot import PATHS

from text.script import sections, tr  # noqa: E402

TR = tr.TR
OUT = PATHS.text_dump_root
KEEP = {"text_banks_scan"}


def field_iter(entry):
    """Yield (sub-label, field-dict) for each translatable field in an entry."""
    if "name" in entry or "desc" in entry:
        for k in ("name", "desc"):
            if k in entry:
                yield k, entry[k]
    else:
        yield "", entry


def key_of(entry, f):
    return (f.get("addr") or (f.get("addrs") or [None])[0]
            or f.get("ptr") or (f.get("ptrs") or [None])[0]
            or (entry.get("id") if isinstance(entry, dict) else None) or "?")


import re as _re
_TOK = _re.compile(r"\{[^}]*\}")
_VAR_CHOICE = ("CHOICE", "NEGRESP")   # 0x313 / 0x413 choice ops


def _strip_dead_choice_tail(s: str) -> str:
    """Collapse a TRUNCATED choice-op tail to a clean marker for readability.  A {CHOICE…}/{NEGRESP…} op
    followed only by leaked optail-kanji / junk glyphs to end-of-string is a truncated-at-choice capture
    that the packer DROPS (tail_cluster jumps back to the ROM choice rows) — so the trailing glyphs are
    dead, not in the build.  Show just {CHOICE}/{NEGRESP} instead of the hex+kanji noise.  A full choice
    mid-string (another token follows) is left untouched."""
    last = None
    for m in _TOK.finditer(s):
        nm = m.group(0)[1:-1].split(":", 1)[0]
        if nm in _VAR_CHOICE:
            last = (m.start(), m.end(), nm)
    if not last:
        return s
    start, end, nm = last
    if _TOK.search(s, end):              # another token after -> a real (non-truncated) choice; keep
        return s
    return s[:start] + "{%s}" % nm       # drop the truncated operand + leaked glyph tail


def render(text: str) -> str:
    return _strip_dead_choice_tail(text or "").replace("{n}", "\n    ")


def main(argv: list[str] | None = None) -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--section",
        action="append",
        choices=sorted(section.id for section in sections.SECTIONS),
        help="render only this section; repeat for multiple sections",
    )
    parser.add_argument("--out", type=Path, default=OUT, help="output directory")
    args = parser.parse_args(argv)

    output_root = args.out.resolve()
    selected = set(args.section or ())
    output_root.mkdir(parents=True, exist_ok=True)
    total = 0
    if not selected:
        for stale in output_root.glob("*.txt"):
            if stale.stem not in KEEP and stale.stem not in {s.id for s in sections.SECTIONS}:
                stale.unlink()
                print(f"removed stale {stale}")
    for sec in sections.in_pack_order():
        if selected and sec.id not in selected:
            continue
        path = TR / f"{sec.id}.json"
        rows = json.loads(path.read_text(encoding="utf-8"))
        lines = [f"# {path.stem}  ({len(rows)} entries) — rendered from corpus/{path.name}", ""]
        for entry in rows:
            for sub, f in field_iter(entry):
                orig = f.get("original")
                if not orig:
                    continue
                tag = f"{sub}:" if sub else ""
                lines.append(f"[{key_of(entry, f)}] {tag}{render(orig)}")
                if f.get("replace"):
                    lines.append(f"    -> {render(f['replace'])}")
        output = output_root / f"{path.stem}.txt"
        output.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"wrote {output} ({len(rows)} entries)")
        total += 1
    print(f"rendered {total} sections")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
