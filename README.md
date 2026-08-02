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

- `rom_layout.py` is the neutral source of truth for shared ROM/RAM addresses and C header defines.
- `text/` owns the editable corpus, codec, section registry, audits, and reference material.
- `font/` owns the curated glyph atlas, declarative font configs, source faces, codecs, and repacker.
- `graphics/` owns editable baked-text assets and their codecs.
- `engine/` owns ROM patches, code caves, and the final ROM assembly pipeline.
- `rom/` is the local-only input/output directory.

`text` and `engine` are sibling domains. Both may depend on `rom_layout.py`; text packing must not
reach through the engine package for cartridge-layout constants.

## Validation

```sh
python -B -m unittest discover -v
python -B -m text.script.tools.audit_field_schema
python -B graphics/script/titlegfx.py test
python -B -m text.script.tools.verify_cave_layout --quick
python -B build.py --profile full --check
```

The unit suite includes architecture checks for the neutral layout boundary and the generated
native-cave header. The full build check remains the byte-level release gate.
