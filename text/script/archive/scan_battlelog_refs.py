#!/usr/bin/env python3
"""For each UNTRANSLATED system_battle_log line, find every 4-aligned u32 pointer to it in
ROM and classify the referencing region — this tells us the injection mechanism each line
needs (table-slot repoint vs code-literal repoint vs builder-splice vs walk-only).

Regions (from docs/battle-message-window.md):
  0x086BE000-0x086BF000  battle command-row / action-fragment / help-pointer tables
                         (g_pBattleActionFragTable 0x086BED5C, command rows, CONFIG arrays)
  0x08777000-0x0877B000  menu/CONFIG handler-record string fields + help-pointer arrays
  0x080E0000-0x08110000  battle composer code literals (ldr r,=str pools)
  0x08120000-0x08130000  other bank literals
  else                   misc / none

Usage: python text/script/archive/scan_battlelog_refs.py
"""
import json
import struct
import sys

try:
    from ._boot import ROM
except ImportError:
    from _boot import ROM

from text.script import tr

TR = tr.TR
rom = ROM.read_bytes()
B = 0x08000000


def region(a):
    if 0x086BE000 <= a < 0x086BF000:
        return "fragtable"       # 086BExxx command-row / action-frag / help tables
    if 0x08777000 <= a < 0x0877B000:
        return "handlerrec"      # menu/CONFIG record fields + help arrays
    if 0x080E0000 <= a < 0x08110000:
        return "composerlit"     # battle composer ldr literals
    if 0x08120000 <= a < 0x08130000:
        return "banklit"
    return "other"


def main():
    sys.stdout.reconfigure(encoding="utf-8")
    data = json.loads((TR / "system_battle_log.json").read_text(encoding="utf-8"))
    null = [e for e in data if e.get("replace") is None]
    addrs = {int(e["addr"], 16): e for e in null}
    # index every aligned u32 == one of our addrs
    hits = {a: [] for a in addrs}
    for off in range(0, len(rom) - 3, 4):
        v = struct.unpack_from("<I", rom, off)[0]
        if v in hits:
            hits[v].append(off + B)
    from collections import Counter
    by_mech = Counter()
    print(f"{len(null)} untranslated system_battle_log lines:\n")
    for a in sorted(addrs):
        e = addrs[a]
        refs = hits[a]
        regs = Counter(region(r) for r in refs)
        mech = ("none(walk)" if not refs
                else "+".join(f"{k}x{v}" for k, v in regs.items()))
        by_mech[tuple(sorted(regs)) or ("none",)] += 1
        print(f"  @{a:08X} max{e.get('max','?'):>2} term{e.get('term')} [{mech:<26}] "
              f"{e['original'][:34]!r}")
        if refs and len(refs) <= 6:
            print(f"        slots: {[f'{r:08X}' for r in refs]}")
    print("\n-- by mechanism class --")
    for k, v in by_mech.most_common():
        print(f"   {'+'.join(k)}: {v}")


if __name__ == "__main__":
    main()
