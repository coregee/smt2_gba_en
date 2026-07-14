"""One-off: decode the save/load-screen message cluster @0x084F1Dxx-0x084F20xx and
find how each string is referenced (table slots vs code literals)."""
import struct

try:
    from ._boot import ROM
except ImportError:
    from _boot import ROM

from text.script import tr

rom = ROM.read_bytes()
BASE = 0x08000000


def u16(a):
    return struct.unpack_from("<H", rom, a - BASE)[0]


# walk the region capturing terminated strings
a, LO, HI = 0x084F1C00, 0x084F1C00, 0x084F2200
strings = []
while a < HI:
    c = u16(a)
    if c in tr.GLYPH_MAP or c == 0x0300:
        start = a
        parts = []
        while a < HI:
            c = u16(a)
            if c in (0x0000, 0x0301):
                a += 2
                break
            if c == 0x0300:
                parts.append("{n}")
            elif c in tr.GLYPH_MAP:
                parts.append(tr.GLYPH_MAP[c])
            elif 0x0302 <= c <= 0x0470:
                parts.append(f"{{={c.to_bytes(2,'little').hex()}}}")
            else:
                parts.append(f"<{c:04X}>")
            a += 2
        if len(parts) >= 2:
            strings.append((start, "".join(parts), c))
    else:
        a += 2

# refs to each string start (2-aligned scan)
starts = {s[0] for s in strings}
refs = {}
for off in range(0, len(rom) - 3, 2):
    v = struct.unpack_from("<I", rom, off)[0]
    if v in starts:
        refs.setdefault(v, []).append(off + BASE)

for start, text, term in strings:
    print(f"{start:08X} term={term:04x} refs={[hex(x) for x in refs.get(start, [])]}")
    print(f"    {text[:90]!r}")
