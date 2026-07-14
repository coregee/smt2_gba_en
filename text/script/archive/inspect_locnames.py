"""One-off: inspect the 0x080A548C location-name table cells (pad token, count, end)."""
try:
    from ._boot import ROM
except ImportError:
    from _boot import ROM

from text.script import tr

rom = ROM.read_bytes()

BASE = 0x080A548C
STRIDE = 0x20


def u16(a):
    o = a - 0x08000000
    return rom[o] | (rom[o + 1] << 8)


# cell 0 raw tokens
print("cell0 tokens:", " ".join(f"{u16(BASE + i*2):04x}" for i in range(16)))
print("cell1 tokens:", " ".join(f"{u16(BASE + 0x20 + i*2):04x}" for i in range(16)))

# what token does '@' map to?
inv = {v: k for k, v in tr.GLYPH_MAP.items()}
print("'@' token:", hex(inv.get("@", -1)), " ' ' token:", hex(inv.get(" ", -1)),
      "'\\u3000' token:", hex(inv.get("　", -1)))

# walk forward with a looser "name cell" predicate: every token is in glyph range
# (<= 0x11FF, not a control word) — unmapped rare kanji allowed.
def cellish(idx):
    a = BASE + idx * STRIDE
    toks = [u16(a + j * 2) for j in range(16)]
    return all(0x0001 <= t <= 0x11FF for t in toks)


i = 0
while cellish(i):
    i += 1
print("glyph-range cells from BASE:", i, "-> table end", hex(BASE + i * STRIDE))
a = BASE + i * STRIDE
print("next cell tokens:", " ".join(f"{u16(a + j*2):04x}" for j in range(16)))

# decode every cell from 444 to the end (the uncaptured tail), flagging unmapped glyphs
for idx in range(444, i):
    a = BASE + idx * STRIDE
    toks = [u16(a + j * 2) for j in range(16)]
    s = "".join(tr.GLYPH_MAP.get(t, f"<{t:04x}>") for t in toks)
    print(f"cell {idx:3d} @{a:08X}: {s}")
