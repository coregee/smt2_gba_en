# Graphics

`assets/` contains the editable indexed PNGs for title, intro, and game-over text plus pristine
ROM-derived copies under `assets/originals/`. `script/gbagfx.py` owns the codecs and asset registry;
`script/titlegfx.py` dumps and round-trips assets, and `script/titlegfx_en.py` renders the maintained
English title sheets. The automap-help facility legend is also baked 4bpp art; `patch_maphelp`
rebuilds its fixed eight-tile label strips from the stock sheet glyphs so it stays synchronized
with `patch_roomlabels`.

Run from the repository root:

```sh
python graphics/script/titlegfx.py test
python graphics/script/titlegfx.py dump
python graphics/script/titlegfx_en.py
```

The ROM build registers `patch_maphelp` and `patch_titlegfx` as the graphics-owned engine stage.
The latter injects any editable PNG that differs from its pristine copy.
