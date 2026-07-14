"""One-off: verify location-name cells in rom/smt2-en.gba — every cell must be
exactly 16 glyph tokens (EN + '@' pad, no 0x0000 terminator), and the word right
after the table must be untouched code."""
try:
    from ._boot import BUILD
except ImportError:
    from _boot import BUILD

from text.script import tr

rom = (BUILD / "smt2-en.gba").read_bytes()
BASE, STRIDE, N = 0x080A548C, 0x20, 530


def u16(a):
    o = a - 0x08000000
    return rom[o] | (rom[o + 1] << 8)


bad = 0
for i in range(N):
    a = BASE + i * STRIDE
    toks = [u16(a + j * 2) for j in range(16)]
    if any(t == 0 for t in toks) or any(t > 0x11FF for t in toks):
        print(f"BAD cell {i} @{a:08X}: {' '.join(f'{t:04x}' for t in toks)}")
        bad += 1
for i in (0, 1, 288, 444, 452, 481, 497, 513, 525, 529):
    a = BASE + i * STRIDE
    s = "".join(tr.GLYPH_MAP.get(u16(a + j * 2), f"<{u16(a + j*2):04x}>") for j in range(16))
    print(f"cell {i:3d}: {s!r}")
print("word after table:", f"{u16(BASE + N * STRIDE):04x} (expect b570)")
print("BAD cells:", bad)
