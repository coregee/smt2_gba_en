# Font

The GBA font pipeline is split by ownership:

- `config/` contains the curated `glyph_map_data.json` source of truth.
- `source/` contains licensed font files and provenance.
- `generated/` contains reproducible maps, OCR/context tables, and width tables.
- `script/` contains renderers, codecs, generators, and preview tools.
- `tools/` contains optional OCR, context, and interactive review utilities.
- `review/` is the gitignored workspace for generated review pages and OCR batches.

The ROM build consumes `config/`, `source/`, and the Python helpers directly. The checked-in
generated tables support extraction, review, and diagnostics; `patch_vwf.py` measures its runtime
table from the patched ROM so a stale `glyph_widths.bin` cannot alter a production build.

Run from the repository root:

```sh
python font/script/build_glyph_map.py
python font/script/build_width_table.py
python font/script/render_glyph.py 017b
python -m font.tools.build_review_html
```

OCR commands require a local Python 3.11 `.venv-ocr/`; it is intentionally not part of the
repository.
