#!/usr/bin/env python3
"""Round-trip every referenced LZ77 stream through bios.lz77_compress; report mismatches."""
import json
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import bios  # noqa: E402

ROOT = HERE.parents[1]


def one(args):
    rom, a = args
    o = a - 0x08000000
    raw, cl = bios.lz77(rom, o)
    c = bios.lz77_compress(raw)
    return a, c == rom[o:o + len(c)] and len(c) == ((cl + 3) & ~3)


def main():
    rom = (ROOT / "baserom.gba").read_bytes()
    streams = [s["addr"] for s in json.loads((ROOT / "build" / "datamap.json").read_text())["streams"]
               if s["type"] == 0x10 and s["addr"] >= 0x0815E828]
    with ProcessPoolExecutor() as ex:
        res = list(ex.map(one, [(rom, a) for a in streams], chunksize=8))
    bad = [a for a, ok in res if not ok]
    print(f"LZ77: {len(res) - len(bad)}/{len(res)} streams re-encode exactly")
    for a in bad[:20]:
        print(f"  {a:08X}")


if __name__ == "__main__":
    main()
