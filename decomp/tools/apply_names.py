#!/usr/bin/env python3
"""Merge proposed names (src/*_names.tsv: address, name, kind, evidence) into
reference/symbols.tsv and rename the old identifiers in src/ and include/.

Existing names marked `proven` are kept unless --force; a proposal that collides with a name
already used at another address is skipped and reported.  Run tools/disasm.py and build.py
afterwards so the assembly uses the new names too.

    python tools/apply_names.py [--force] [--dry-run]
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from symbols import Sym, Symbols  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    syms = Symbols.load(ROOT / "reference" / "symbols.tsv")
    rows = dict(syms.by_addr)
    used = {s.name: a for a, s in rows.items()}
    renames = {}
    skipped = []
    for tsv in sorted((ROOT / "src").glob("*_names.tsv")):
        for ln in tsv.read_text(encoding="utf-8").splitlines():
            if not ln.strip() or ln.startswith("#") or ln.lower().startswith("address"):
                continue
            f = ln.split("\t")
            if len(f) < 2:
                continue
            a = int(f[0], 16)
            name = f[1].strip()
            kind = f[2].strip() if len(f) > 2 and f[2].strip() else "func"
            why = f[3].strip() if len(f) > 3 else ""
            if not re.fullmatch(r"[A-Za-z_]\w*", name):
                skipped.append(f"{tsv.name}: bad name {name!r}")
                continue
            if name in used and used[name] != a:
                skipped.append(f"{tsv.name}: {name} already names 0x{used[name]:08X}")
                continue
            old = rows.get(a)
            if old and old.confidence == "proven" and not args.force and old.name != name:
                skipped.append(f"{tsv.name}: 0x{a:08X} keeps proven name {old.name}")
                continue
            if kind == "func":
                old_name = old.name if old else f"sub_{a:08X}"
            else:
                old_name = old.name if old else None
            if old_name and old_name != name:
                renames[old_name] = name
            if kind != "func":
                for alias in (f"gUnk_{a:08X}", f"gUnknown_{a:08X}"):
                    if alias != name:
                        renames[alias] = name
            rows[a] = Sym(a, name, kind, "probable", why or f"proposed in {tsv.name}")
            used[name] = a
    print(f"{len(renames)} renames, {len(skipped)} skipped")
    for s in skipped:
        print("  skip:", s)
    if args.dry_run:
        return
    Symbols.save(ROOT / "reference" / "symbols.tsv", rows.values())
    # Two proposals for one address chain (sub_X -> A, A -> B): every old name goes to the last.
    for k in list(renames):
        seen = {k}
        while renames[k] in renames and renames[k] not in seen:
            seen.add(renames[k])
            renames[k] = renames[renames[k]]
    if renames:
        pat = re.compile(r"\b(" + "|".join(map(re.escape, sorted(renames, key=len, reverse=True))) + r")\b")
        for p in list((ROOT / "src").rglob("*.c")) + list((ROOT / "include").rglob("*.h")):
            t = p.read_text(encoding="utf-8")
            n = pat.sub(lambda m: renames[m.group(1)], t)
            if n != t:
                p.write_text(n, encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
