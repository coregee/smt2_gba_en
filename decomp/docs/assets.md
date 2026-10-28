# Asset formats

`assets/manifest.json` lists every extracted blob; `tools/assets/assets.py` extracts and
rebuilds them (`docs` in its header). This page records what is known about each family.

## Compression

| Codec | Streams | Notes |
|---|---:|---|
| `lz77` | 1,123 | BIOS LZ77 (type 0x10). The game's encoder is greedy, takes the nearest longest match, never closer than distance 4; `bios.lz77_compress` reproduces every stream. |
| `huff+lz77` | 1,337 | BIOS Huffman (4-bit) around an LZ77 stream: the loaders run `HuffUnComp` into a buffer, then `LZ77UnCompWram` (see `sub_080B3C5C`). Extracted to the doubly decompressed data; rebuilt with the matching LZ77 encoder and the stream's own stored Huffman tree. |
| `raw` | ~100 | Streams kept compressed: Huffman trees that point past their declared size, and RLE. |

Every asset rebuilds byte-identically (`assets.py build --verify`).

## Location scenes (`assets/scenes/`)

398 records of 0x5C bytes at `0x08341170` (`sub_080C5EF0(id)` returns the record;
`sub_080C5F04(id, k)` the k-th chunk), loaded by `sub_080B3C5C`:

| Offset | Field |
|---|---|
| `+0x00` | type: 1 = chunks are LZ77, 2 = chunks are Huffman+LZ77 |
| `+0x04` | chunk pointers 0–7 |
| `+0x24` | chunk pointers 8–15 (a second set; loaded as upload slot k−5) |
| `+0x44` | width, height in pixels (224×104 for the first-person view; some 224×176) |
| `+0x48` | palette: 0x100 bytes = 8 lines of 16 colours |
| `+0x50`, `+0x54` | attribute maps: one byte per 16×16 block (`0x20` + palette line), 14 columns |

Tiles are 4bpp in raster order (28 tiles per row for a 224-pixel scene); each chunk is
uploaded by its own routine from the table at `0x081625D4`. Type-1 scenes compose exactly
from chunks 0–2 and the first attribute map. Type-2 records list fewer distinct chunks
(`c0, c1, c0, c1`), so their placement through the upload table still needs decoding.
Chunk PNGs are named `scene_NNN_chunkK` after the first record that uses them and are
coloured with the scene palette's most common line (the real colours vary per block).

## Battle effect animations (`assets/battle_effects/`)

211 records of 24 bytes at `0x0876CE10`, indexed by a byte effect id (`sub_080EC9AC` and
neighbours; ids >= 200 are handled differently): `+0x00` a sprite layout in the program's
read-only data near `0x080F68E0`, `+0x04` a 16-colour palette, `+0x08..+0x14` four frame
graphics (Huffman+LZ77, 4bpp tiles in OAM order, shown 8 tiles wide). Frames shared
between effects are named after the first id that uses them (288 frames).

## Fonts

- Main font: 4,608 glyphs, 16×16 2bpp, banked through the table at `0x0815ED88`
  (`font/script/font_codec.py` in the translation project decodes it).
- 8-pixel font sheet at `0x081AD7B8`.

## Still unclassified

The remaining streams carry a format guessed from their size (`4bpp` when the size is a
multiple of 32) and grey previews. Families still to identify: the other Huffman frames at `0x086C0000-0x08770000` (tables
from `0x0876E1D8`, used by `sub_080F0F68`/`sub_080F108C`), the 2 KB LZ77 blocks at
`0x08500000-0x08580000`, and the large images at `0x08340000-0x084D0000`.
