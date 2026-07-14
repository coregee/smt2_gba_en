#!/usr/bin/env python3
"""Compare two TR_PACK_LOG runs for semantic identity.

`tr.py pack` (with TR_PACK_LOG=<path>) records every semantic ROM write:
  ["pool", sha]          a pooled string blob, by content hash (address-free)
  ["ptr",  slot, sha]    a pool pointer written into a fixed ROM slot, target by hash
  ["write", addr, hex]   literal content written at a fixed ROM address

Two builds are semantically identical iff the MULTISETS of these events match —
pool addresses may differ (a section split reorders allocations), but every blob
must still exist, every slot must still point at the same content, and every
in-place write must be unchanged. This is the verification gate for refactors
that legitimately shift the pool layout (where a byte-diff of the ROMs can't work).

Usage: python -m text.script.tools.compare_pack_logs before.jsonl after.jsonl
"""
import json
import sys
from collections import Counter
from pathlib import Path


def load(path):
    return Counter(tuple(json.loads(line)) for line in
                   Path(path).read_text(encoding="utf-8").splitlines() if line.strip())


def main():
    if len(sys.argv) != 3:
        raise SystemExit(__doc__)
    a, b = load(sys.argv[1]), load(sys.argv[2])
    only_a, only_b = a - b, b - a
    if not only_a and not only_b:
        print(f"PASS: {sum(a.values())} events, semantically identical")
        return 0
    print(f"FAIL: {sum(only_a.values())} events only in {sys.argv[1]}, "
          f"{sum(only_b.values())} only in {sys.argv[2]}")
    for label, diff in ((sys.argv[1], only_a), (sys.argv[2], only_b)):
        for ev, n in sorted(diff.items())[:20]:
            print(f"  only in {label} (x{n}): {ev}")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
