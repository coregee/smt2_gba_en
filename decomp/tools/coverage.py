#!/usr/bin/env python3
"""Account for every byte of the program segment: instruction, literal, jump table or padding.
Prints the unexplained gaps (the places where discovery is still wrong or incomplete)."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from trace import ROM_BASE, TEXT_START, TEXT_END  # noqa: E402


def classify(rom: bytes, trace: dict):
    kind = {}
    for f in trace["functions"]:
        for a, n in f["insns"]:
            for b in range(a, a + n):
                kind[b] = "code"
        for l in f["literals"]:
            for b in range(l, l + 4):
                kind.setdefault(b, "lit")
        for t, n, _ in f["jumptables"]:
            for b in range(t, t + 4 * n):
                kind.setdefault(b, "jt")
    return kind


def gaps(rom: bytes, kind: dict, lo=TEXT_START, hi=TEXT_END):
    a = lo
    out = []
    while a < hi:
        if a in kind:
            a += 1
            continue
        b = a
        while b < hi and b not in kind:
            b += 1
        blob = rom[a - ROM_BASE:b - ROM_BASE]
        if not any(blob) or (len(blob) == 2 and blob == b"\xc0\x46"):
            pass                                            # 0 padding / alignment nop
        else:
            out.append((a, b))
        a = b
    return out


def main():
    rom = Path(sys.argv[1]).read_bytes()
    trace = json.loads(Path(sys.argv[2]).read_text())
    kind = classify(rom, trace)
    g = gaps(rom, kind)
    total = sum(b - a for a, b in g)
    print(f"{len(g)} unexplained gaps, {total} bytes")
    for a, b in g[: int(sys.argv[3]) if len(sys.argv) > 3 else 40]:
        print(f"  {a:08X}-{b:08X} ({b - a:5d})  {rom[a - ROM_BASE:min(b, a + 16) - ROM_BASE].hex()}")


if __name__ == "__main__":
    main()
