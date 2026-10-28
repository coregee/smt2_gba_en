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

## Demon battle sprites (`assets/demons/`)

388 records of 0x1C bytes at `0x0872C774` (`Demon_GetGfxRecord` 0x080E444C; ids 0-379, id 0x12D
is replaced by one of the variants at `0x0872F104` + variant*0x1C, id 0x12E by `0x0872F174`):

| Offset | Field |
|---|---|
| `+0x00` | u16 flags (`0x0101`; `0x9200` = affine-scaled, bit 15 tested by 0x080E7D3C) |
| `+0x04` | 16-colour palette (copied to an OBJ line by `Demon_LoadGfx` 0x080E5678) |
| `+0x08` | cell animation: u16 w, u16 h, pointer to (sprite def, u32 duration) pairs ended by `0xFFFFFFFF` |
| `+0x0C` | OBJ tiles 0-127 (Huffman+LZ77, 4 KB) |
| `+0x14` | OBJ tiles 128-255 for large demons (0 otherwise) |

The tiles are in the **2D OBJ layout** (32 tiles per row): DMA'd to `0x06016000`, the sprite
defs (`Sprite_DrawWithMode` format) cut a 256x32 (or 256x64) strip into the 64x32/16x16/...
objects that form the demon. The PNGs are therefore 32 tiles wide; `tools/assets/sprites.py
demons` composes every record through its cells into `assets/previews/demons/`. 374 graphics
(13 two-part halves stay Huffman-compressed `.bin`, see "raw").

## Event character sprites (`assets/characters/`)

474 records of 0x2C bytes at `0x08568D78` (`Char_GetRecord` 0x080D95F4): `+0x00` type (0, or 2 =
scripted), `+0x04..+0x20` four poses x two 2 KB halves (LZ77; half k fills OBJ rows 2k-2k+1 of the
2D layout, `Char_LoadGfxHalf` 0x080C4080), `+0x24` palette, `+0x28` command script (type 2).
The default sprite def `0x08004FF8` draws an 80x96 figure from OBJ tile 0x300; `sprites.py
characters` writes previews. Script animation frames are 0x18 bytes {gfx half 0, gfx half 1,
sprite def, u16 duration (0xFFFF end, 0xFFFE loop), u16 tile base, u16 palette, u16 reload,
u16 sound}; their graphics are named `char_NNN_frame_<entry>_halfH` after the record whose
script contains them. `characters/set_<loader>_k` are the multi-part sprite sets loaded directly
by 0x080BC5A8, 0x080D7F20, 0x080D80C8, 0x080D920C and 0x080D9344.

## Field map (`assets/fieldmap/`)

12 area records of 0xD8 bytes at `0x087DE924` (`FieldMap_GetArea` 0x08151EB4; 10 and 11 are the
early versions of areas 2 and 5):

| Offset | Field |
|---|---|
| `+0x00` | 8 BG tile sets (4 KB each, to 0x02001000 + k*0x1000, DMA'd to `0x06004000`) |
| `+0x20` | 16 tilemap chunks of the upper layer (4 KB, concatenated to 0x0200F874; `+0x24 != 0` = present) |
| `+0x60` | 16 tilemap chunks of the lower layer (to 0x0201F874) |
| `+0xA0`, `+0xA4` | palettes: 8 lines copied to BG lines 8-15 (`0x03002AB0`) |
| `+0xA8` | 8 block-data chunks (byte per 16x16 block at +0x2000, 64 per row) |
| `+0xC8`, `+0xCA` | width, height in pixels (tilemap rows are width/8 entries) |
| `+0xCC`, `+0xCE` | origin; `+0xD0` 8 bytes of per-area ids |

The map is isometric; tile previews use the most common palette line of the tilemap entries
that reference the set. Area 6 animates tile set 4 with `area06_tiles4_alt` (0x08153DD8).
`objects0/1` are the map's OBJ sprites (palette 0x087DE8C4), `panel_*` a BG panel (0x08153890).

## Casino (`assets/casino/`)

Eight minigames (Super 27, Lucky Symbol, Joker and Stars, Baccarat, Keno, Big & Small, Code
Breaker, Russian Roulette - names from the debug menu text) are set up by command scripts at
`0x08794E00-0x0879F5A0`: words `op, func, args...` with op 0 = wait n frames, 0x0A/0x0B/0x0C =
call func with 0/1/2 arguments. Handlers: `0x0813EF64(gfx, slot)` tile set to 0x02001000 +
slot*0x1000, then `0x0813EFB4` (to BG 0x06008000) or `0x0813EFEC` (to OBJ 0x06010000);
`0x0813F000`/`0x0813F030` 512-byte BG/OBJ palettes (LZ77, `pal` assets); `0x0813F0EC(map,
layer)` 32x20 tilemaps (screen block 0x06000000 + layer*0x1000). Baccarat's cards are 8
blocks of 0x1200 bytes (table 0x0879CCF4): 20-tile 32x40 cards, `suit*0x2400 + rank*0x280`.

## Cathedral of Shadows (`assets/fusion/`)

BG tiles from `0x087E5D3C` plus the capsule tiles `0x087E5D48` (tile 0x2C0), four 32x20
tilemaps (2-way and 3-way fusion rooms and their capsules; `0x080AB250` adds tile base and
palette line), BG palettes `0x087EFF4C` (lines 2-3) and `0x087EFFCC` (lines 6-15). Room animation
frames: table `0x087F01AC` (image + 0x40-byte map patch, uploaded to tile 329). OBJ: mist frames
`0x087F020C` (11 x 2 KB, palette 0x087F012C) and effect sets `0x087F0954` (three 4 KB parts +
palette, 2D layout).

## Dungeon views (`assets/dungeon/`)

`gDungeonMaps` at `0x084ED59C`: 93 x 0x18 {floor records, floor count}; floor records are 0x268
bytes (`DungeonMap_GetFloor` 0x080C8B10): a 0x98-byte header, then two variants of 0xE8 bytes.
Variant words (index: buffer): 0-6 -> 0x0201D874 (set A), 8-11 -> 0x02024074 (B), 16-19 ->
0x0202D874 (C), 24-31 -> 0x0200F874 (D), 32-37 -> 0x02017874 (E), 40-45 -> 0x02028074 (F), one
LZ77 4 KB step each (`DungeonMap_LoadViewStep` 0x080AD824), usually only the first part is a
single large stream; `+0xC0/+0xC4/+0xC8` palettes (16/32/16 colours, darkened copies by
`Map_SetGraphicsPointers`), `+0xCC/+0xD4/+0xDC` 4 KB door OBJ graphics (to 0x06015000). The view
sets are perspective wall slices in 8x8 tiles, composed by the renderer; their layout is not
decoded, so the PNGs are plain 16-wide tile sheets.

## Event effects and menus (`assets/event_fx/`, `assets/ui/`)

The 0x08160000-0x081B0000 LZ77 blocks are named after the function that loads them
(`event_fx/<func>_NN` for the field event effects module 0x080BA000-0x080BD7FF, `ui/<func>_NN`
otherwise) with the first palette the loader copies; many of these loaders build their palette at
run time, so those previews stay grey. `ui/title_menu_tiles0-3` come from the command script at
`0x08162AB0` (sub_080B4C48).

## Still unclassified

62 streams: LZ77 blocks at 0x0822E194, 0x08245B80-0x0824DF94, 0x084F2974-0x084F9CD0 (event
background group of `0x080D6274`, partly RLE inside), Huffman+LZ77 frames at
0x0856DEF0-0x0857D558 (referenced from command tables at 0x08581xxx-0x08589xxx) and
0x0858689C-0x0858979C. `event_bg/bg_6C_rle`, `bg_65_rle`, `bg_6E_rle` (0x080D6274) are Huffman/LZ77 around a BIOS RLE stream and are kept as the inner RLE `.bin`.
