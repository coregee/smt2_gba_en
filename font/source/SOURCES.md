# Font sources (build-time only)

These TTFs are used **at build time only** to rasterize bitmap glyphs into the ROM's
2bpp/4bpp font sheets. The TTF files themselves are **not** redistributed in the patch
output (`rom/smt2-en.gba`) — only the generated pixel data is. `fontsrc/` is local /
git-ignored.

## Active (required by the build)

- **HelvetiPixel** — by *pentacom*, from the BitFontMaker2 community gallery (id 381):
  <http://www.pentacom.jp/pentacom/bitfontmaker2/gallery/?id=381>. Free pixel font.
  The **English ASCII face** injected into the main 2bpp sheet (codes `0xBC..0x117`) by
  `custom_glyphs.py` → `patch_font.py`. Rendered crisp at **px=15**.
- **Galmuri7** — by Quiple (OFL, see `OFL.txt`). The **8px small-sheet Latin face** (party-
  panel / save-screen demon+party names), rasterized by `patch_defaultnames.py`.

## Staged but unused

- **Galmuri11 / Galmuri14** — by Quiple (OFL). Kept from earlier staging; not currently
  injected. `preview_font_swap.py` defaults to Galmuri11 for its stock-vs-candidate preview.

## Other candidates evaluated (downloaded, then removed)

HelvetiPixel was chosen from a 15-font comparison (PixelMplus 10/12, Silkscreen, Cozette,
Pixellari, m5x7, and the pentacom BitFontMaker2 pack — BitCasual/CursivePixel/justabit/
KarenBook/OldWizard/OrdinaryBasis/PixelMordred/Quintet/TimesNewPixel). Those TTFs were
deleted after the decision. To re-evaluate, re-download the candidates and use
`font/script/preview_font_swap.py` to rebuild the comparison.
