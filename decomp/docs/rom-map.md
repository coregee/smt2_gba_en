# ROM map

Addresses are cartridge addresses (file offset + 0x08000000). "Proven" items are established
from instructions or data structure; the rest are marked.

| Range | Contents | Evidence |
|---|---|---|
| `08000000-080000C0` | Cartridge header (title `DDS_2`, code `A5TJ`, maker `EB` = Atlus) | header |
| `080000C0-08000200` | AGB SDK crt0 (ARM): `Start`, `IntrMain` and its bit-to-offset dispatch | trace |
| `08000200-080A96CC` | Text and text tables: u16 glyph strings, the 0x20-byte location-name cells at `080A548C` | translation project; `docs/text.md` |
| `080A96CC-0815E828` | The program: 4,499 functions, Thumb except crt0 and parts of m4a | `tools/trace.py`, `tools/coverage.py` |
| `080E2364-080E4450` | Nintendo m4a (MP2K) sound library inside the program | jump table `0858BBBC` |
| `0815CAF4-0815CB2A` | BIOS call wrappers (CpuFastSet, CpuSet, HuffUnComp, LZ77UnCompWram, ObjAffineSet, RLUnCompWram, SoftReset, VBlankIntrWait) | `svc` numbers |
| `0815CCC0-0815E828` | Runtime: `_call_via_rX`, libgcc division and soft-float, newlib `memcpy`/`memset`/`srand`/`rand` | instruction idioms |
| `0815E828-…` | Read-only data: sine table (`0815E828`), IRQ handler template `0815EAA8` (copied to `030020F0`), main-font bank table `0815ED88`, … | code references |
| `08160000-081B0000` | LZ77 graphics; equipment/item records `08198B74`/`08198EB4`, demon records `0819CB74` (0x60 bytes each) | translation project |
| `081AC8B8-…` | Uncompressed tile graphics (8 px font sheet `081AD7B8`) | translation project |
| `08200000-08340000` | Huffman (4-bit) image frames, ~3 KB each, indexed by 0x5C-byte records near `08341170` (width/height, palette pointer, tile map, frame list) | records; loader `080C5EF0` (to be confirmed) |
| `08340000-084D0000` | Large LZ77 images, 16–26 KB decompressed (full-screen pictures) | sizes |
| `08500000-08580000` | Hundreds of 2 KB LZ77 blocks (64 tiles each) | sizes |
| `0858A000-0858E000` | m4a tables: `gMPlayJumpTableTemplate` `0858BBBC`, `gScaleTable` `0858BC4C`, voicegroups from `0858BE94`, `gMPlayTable` `0858D354`, `gSongTable` `0858D384` (399 entries) | m4a code |
| `085xxxxx-086xxxxx` | Event/story script banks (VM bytecode with embedded text) | translation project |
| `086B3A80-…` | m4a song data | `gSongTable` |
| `086C0000-08770000` | Huffman (4-bit) small images, ~1 KB each, indexed from tables at `0876CE18-0876E1D4` | pointer tables |
| `0876F8C0`, `08790FDC` | Function-pointer tables (67 and 84 entries) | trace |
| `087913DC`, `08791BDC` | Script VM opcode tables (`gScriptOpTable`, `gScriptOpAltTable`; 369 entries, opcodes 0x300–0x470) | `ScriptVM_Run` |
| `087A0000-087F0000` | More Huffman/LZ77 images, indexed from tables near `087DE924-087F0234` | pointer tables |
| `087F2F40-08800000` | Unused 0xFF fill (53 KB; the translation puts its width table and string pool here) | |
