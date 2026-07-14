# Graphics

`assets/` contains the editable indexed PNGs for title, intro, and game-over text plus pristine
ROM-derived copies under `assets/originals/`. `script/gbagfx.py` owns the codecs and asset registry;
`script/titlegfx.py` dumps and round-trips assets, and `script/titlegfx_en.py` renders the maintained
English title sheets.

Run from the repository root:

```sh
python graphics/script/titlegfx.py test
python graphics/script/titlegfx.py dump
python graphics/script/titlegfx_en.py
```

The ROM build registers `patch_titlegfx` as the graphics-owned engine stage and injects any editable
PNG that differs from its pristine copy.
