#!/usr/bin/env python3
"""reference/function-map.tsv: every function with its mode, size, name, how sure the name is,
the source file it lives in, and how far it is recovered:

    asm          generated assembly only (asm/*.s)
    named        assembly, with a name in reference/symbols.tsv
    c            matching C in src/ (the function is no longer in asm/)
    nonmatching  readable C in src/ under #ifdef NONMATCHING; the build uses the original
                 instructions (NAKED)
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from symbols import Symbols  # noqa: E402


def main():
    t = json.loads((ROOT / "build" / "trace.json").read_text())
    syms = Symbols.load(ROOT / "reference" / "symbols.tsv")
    layout = json.loads((ROOT / "layout.json").read_text())
    c_funcs = {}
    nonmatching = set()
    for p in (ROOT / "src").rglob("*.c") if (ROOT / "src").exists() else []:
        text = p.read_text(encoding="utf-8")
        for m in re.finditer(r"//\s*(\w+)\s*@\s*0x([0-9A-Fa-f]{8})\s*\n(#ifdef NONMATCHING)?", text):
            a = int(m.group(2), 16)
            c_funcs[a] = p.relative_to(ROOT).as_posix()
            if m.group(3):
                nonmatching.add(a)
    rows = ["address\tmode\tsize\tname\tconfidence\tstate\tfile"]
    counts = {}
    for f in t["functions"]:
        a = f["addr"]
        s = syms.by_addr.get(a)
        name = s.name if s else ""
        file = next((e["file"] for e in layout if int(e["start"], 16) <= a < int(e["end"], 16)), "")
        state = ("nonmatching" if a in nonmatching else "c") if a in c_funcs else ("named" if s else "asm")
        if a in c_funcs:
            file = c_funcs[a]
        counts[state] = counts.get(state, 0) + 1
        rows.append(f"{a:08X}\t{f['mode']}\t{f['end'] - a}\t{name}\t{s.confidence if s else ''}\t{state}\t{file}")
    (ROOT / "reference" / "function-map.tsv").write_text("\n".join(rows) + "\n", newline="\n")
    print(" ".join(f"{k}={v}" for k, v in sorted(counts.items())), f"total={len(t['functions'])}")


if __name__ == "__main__":
    main()
