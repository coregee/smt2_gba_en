# Decompilation status (2026-10-31)

The ROM rebuilds byte for byte from this repository (`python build.py` prints `OK`, sha1
`8a4a52eb5538d52762337ca045e5c85e00f19ff0`). That build is the proof behind every number below.

## Code

| | Functions |
|---|---|
| Game code in C, byte-matching | 4,258 |
| Game code in C, NONMATCHING (readable C plus the original instructions) | 122 |
| Assembly that is assembly in Nintendo's SDK too (crt0, the m4a mixer and track commands, libgcc, `memcpy`/`memset`/`rand`, one ARM MultiSio interrupt routine) | 121 |
| Total | 4,501 |

Every function of the game's own code has C source. For the 122 NONMATCHING functions the build
uses the original instructions (a NAKED body), so the build does not prove their C; it compiles,
and each was written against the original, but treat it as a reading, not as the source.

Of the matching functions, two groups are matched with source that is less likely to be what the
original programmers wrote:

- **Register pins (12):** GNU `register T x asm("rN")` in `battle_080F57F4.c`, `charsprite_a.c`,
  `compendium_a.c`, `dungeonmap_b.c`, `fieldbg_a.c`, `fieldevent_f.c`, `game_k.c`, `link_a.c`,
  `menu_b.c`, `msgwin_qtyinput.c`, `vm_run.c`, `vm_wait.c`.
- **Allocation-steering dead stores (6):** five HUD slide functions in `hudslide_a.c` end with a
  dead `cx = 0;`/`cy = 0;`, and `Shop_ListInput` (`msgwin_shoplist.c`) has two dead `keys = 0;`
  stores. Each is commented.

## Matching work, 2026-10-30/31

Thirteen rounds of three parallel agents took the NONMATCHING count from 386 to 122 (and moved the
last 136 functions out of assembly before that: the m4a C half, the fusion calculator, shop and
message-window input, battle actions, the status screen, the dictionary, multi-play serial link).
The largest functions now matching include `Baccarat_Update` (4 KB), `MsgWindow_ItemListInput`
(3 KB), `Shop_ListInput`, `MsgWindow_DrawItemList`, `Field_CheckCellEvents`,
`Battle_SortEntriesQuick` and `Fusion_ThreeNormal`.

What worked, and every dead end, is in `docs/matching-tricks.md`. The main lessons:

- **Rewrite large functions to follow the original block by block** rather than tuning readable
  C: one C branch per path, calls and tails repeated where the original repeats them, the
  original's loop forms. This turned 400-1,400-line diffs into exact matches.
- **gcc's tail sharing is predictable:** it merges duplicated code into the last copy that jumps
  to the shared label; copies written out per branch reproduce the original's layout.
- **Register allocation is a priority order** (references weighted by loop depth over live
  length; ties to the first-declared variable). Most stubborn swaps were fixed by reusing variables
  the way the original reuses registers, or by a spelling that moves a near-tie.
- **Declaration order is stack-slot order** for spilled variables.

## Bugs found in the readable C

The build never used these versions (the functions were NONMATCHING), but anyone reading the C
would have been misled. All are fixed:

- `Status_DrawSkillName`, `Status_DrawActionName`: advanced `x` but drew every glyph at `cx`.
- `Status_BuildList`: a missing pair of braces made the count run on every pass (16 or 4).
- `0x081594B4`: read an `s8` field signed; the original reads it unsigned.
- `MsgWindow_DescListInput`: stored the row where the original stores the constant 3.
- `sub_080D34A4` was declared with a signed parameter in two files (it takes `u16`), so callers
  sign-extended where the original zero-extends.
- `0x080D3B58`: returns 1 when the bit is clear, not the bit index.
- `0x080F104C`: the call to `Battle_GetActionAnim` had lost its second argument.
- `Fusion_DrawListRow`: called `sub_0815B884` with four arguments (the prototype in
  `include/worldmap.h`); it takes five, and mode 5's arguments were shifted.
- `Field_UpdateFrame`: its readable C crashed agbcc (a local `extern` clashed with the header's
  array size).

Header prototypes that still disagree with how the original callers used the function (left as
is; callers use local casts): `Random_Byte` (`u16` in some headers, `u32` in others),
`sub_080C5D0C` (returns `u16`, three headers say `u32`, but one caller needs `u32`),
`sub_0815B958` (`u16`/`u32`/`s32` in three headers), `sub_0815B884` in `worldmap.h`,
`sub_080E8AC0`, `sub_080F3040`, `sub_081268E4`, `sub_0812E780`, `sub_080F030C`, `sub_080ECE38`.

## What the code says about the game

- **Fusion rules** as the code implements them: `docs/fusion.md` (race and level of the result,
  the 1-in-256 accident and its level band, the alignment shift of every fusion, skill
  inheritance).
- **Original bugs and odds quirks** (casino odds, uninitialised values, unchecked records, the
  speed roll thrown away, the special-encounter moon test): "Possible original bugs" and "Odds
  quirks" in `docs/translation-findings.md`.
- **Translation limits** found in the code (fixed-width buffers, hard-coded positions, glyph
  queues): the rest of `docs/translation-findings.md`; the shop/item-list glyph queue, ailment-name
  positions and compendium label slots there are read from code and not yet checked on screen.

## What is left

- **122 NONMATCHING functions.** Some already have the original's instruction sequence and differ
  only in register choice; others still differ in structure. The large ones: `Field_UpdateFrame` (0x080B0C90), `Color_ApplyEffect` (0x080ACC54),
  `FieldView_BlitTiles` (0x080B23D0), `Compendium_BuildList` (0x08156ECC), `ScriptOp_445`
  (0x0813B524), `ScriptOp_447` (0x0813BF98), `ScriptOp_Substitute` (0x08132B40),
  `MsgWindow_DescListInput` (0x08130D24), `Shop_UpdateQuantityArrows` (0x081316FC). Known dead
  ends and their mechanisms are recorded per function in `docs/matching-tricks.md`.
- **Data:** about 18% of the ROM is still `.incbin` from `baserom.gba` (uncompressed tile sheets,
  palettes, record tables).
- **On-screen checks** of the translation findings above, with the mGBA harness
  (`docs/emulator.md`).

To resume matching: `reference/function-map.tsv` lists every function with state `nonmatching`;
split them by address so parallel workers edit disjoint files, have workers experiment in copies
and apply a function only once `tools/match.py` reports it OK, and integrate in a separate
`git worktree` (never run `build.py` where `match.py` is in use).
