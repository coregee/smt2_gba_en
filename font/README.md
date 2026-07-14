# Font

The font build follows the same extract/atlas/repack model as Devil Summoner while preserving the
GBA ROM's native layouts.

| Path | Purpose |
| --- | --- |
| `atlas/main.json` | Reviewed glyph-code atlas used directly by text encoders and decoders. |
| `config/main.json` | Main 16x16 font format, source face, raster settings, and replacement ranges. |
| `config/small8.json` | Relocated 8x8 name font, replacement ranges, and width-table settings. |
| `source/` | Licensed source fonts and provenance. |
| `script/font_codec.py` | Native 2bpp/4bpp codecs and bank-table injection. |
| `script/extract.py` | Render original and replacement atlas sheets. |
| `script/repack.py` | Build and validate injectable font files. |

## Font files

`main.fnt` is a canonical code-indexed view of the ROM's scattered font banks. Each of its 4,608
records is one 16x16 glyph: top-left, top-right, bottom-left, and bottom-right 2bpp tiles. Injection
resolves every record back through the ROM's font-bank table. The repacker also keeps the stock
bank-1/bank-2 physical aliases synchronized.

`small8.fnt` contains the relocated 8x8 name cells followed by one VWF advance byte per cell. The
font stage rasterizes its Latin cells; `patch_defaultnames.py` only injects the finished file and
installs the runtime hooks.

The normal repository build writes both files under `rom/font/` and creates ignored comparison
sheets at `font/atlas/main_{original,replaced}.png` and
`font/atlas/small8_{original,replaced}.png`. The ROM build injects the same in-memory font data, so
the preview and shipped paths cannot diverge.

## Commands

Run from the repository root:

```sh
python font/script/extract.py
python font/script/repack.py
python font/script/repack.py --check
python build.py --profile full --check
```

`--check` rebuilds both fonts, verifies main-font ROM injection round-trips, and writes nothing.
The later VWF stage still measures advances from the injected main glyphs, preserving the runtime
contract that stale generated width tables cannot affect a build.
