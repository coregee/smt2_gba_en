# SMT2 GBA translation

This repository contains the English translation source, text and graphics assets, font pipeline,
and GBA runtime patches. Place an unmodified Japanese ROM at
`rom/Shin Megami Tensei II (Japan).gba`. Built ROMs and intermediates are written to `rom/`; that
directory is intentionally excluded from Git.

## Build

Run from the repository root:

```sh
python build.py --profile full
python build.py --profile full --check
python build.py --profile diagnostic
python build.py --list-profiles
```

`--check` assembles every hook and cave, packs the complete corpus, and reports the final hash
without writing build artifacts. The diagnostic profile writes `rom/smt2-en-diagnostic.gba`, so
hardware-test hooks cannot replace the normal translated ROM accidentally.

The normal build writes `rom/smt2-en.gba`; its pre-pack intermediate is
`rom/smt2-en-font.gba`.

## Layout

- `text/` owns the editable corpus, codec, section registry, audits, and reference material.
- `font/` owns the curated glyph atlas, declarative font configs, source faces, codecs, and repacker.
- `graphics/` owns editable baked-text assets and their codecs.
- `engine/` owns ROM patches, code caves, and the final ROM assembly pipeline.
- `rom/` is the local-only input/output directory.
