# Findings for the English translation

Behaviour of the original game, read from the decompiled C in `src/`, that constrains or
explains translation bugs. Addresses are original-ROM function addresses. "Proven" means the
code does this; consequences for the translation are inferences until reproduced in an
emulator. Several of these are already worked around by the translation's patches (see
`docs/patch-audit.md`); the list is about what any text or patch has to respect.

## Fixed-size buffers with no bounds checks

| Where | Limit | Consequence of overflow |
|---|---|---|
| Battle message window (`src/btext_*.c`, state at `0x0203C9E0`) | three u16[64] buffers: `text` `0x0203C9EC`, `text2` `0x0203CA6C`, `compose` `0x0203CAEC` | `BattleMenu_SetMode` modes 4/8/9, typing in `BattleMsg_Update` mode 6 and every `Battle_Build*Text` copy until the terminator. Past `compose` lie the auto-close flag/timer (`0x0203CB6C`) and the window and task pointers (`0x0203CB70`, `0x0203CB74`) later passed to `0x080AB91C` / `0x080AD1FC`: likely crash. |
| Battle typing counter | u8 | a message over 255 glyphs wraps |
| Script name substitution (`ScriptOp_DrawCharOrSubstitute`, `0x08132B40`) | buffer `0x0203DB08` holds 15 glyphs + `0x318`; live data at `0x0203DB28` | see name caps below |
| Save data (`src/menu_b.c`) | live state `0x030046C0` is exactly `0x18F8` bytes = the used part of each `0x1B00` SRAM slot | the state cannot grow without changing the save layout |

### Checked against the current translation build

`python tools/battle_text_budget.py` (report in `build/battle-text-budget.txt`) runs the
translation build in memory and finds every call to the battle composers and
`BattleMenu_SetMode*`, in the original code and in the translation's caves (`bl Builder`
replaced by `bl cave` is measured with the builder's arguments). It resolves the string each
call passes in the patched ROM (literals, string tables, the battle message table behind
`sub_080EC038`, action and 28-byte records behind `Action_GetRecord`/`sub_080BF5C0`, wrapper
functions that pass their parameter through), and computes the worst case after expansion:
8 glyphs per human name, 16 for `{PARTY_NAME}` ("…'s party"), 15 for `{ITEM_NAME}`, 8 per
number, `{WAIT}`/`{PAGE}` dropped by `Menu_ExpandListTemplate`.

Result (translation as of `3d6bf91`): **no overflow.** 667 (composer, string) pairs; the
largest worst cases are 62/64 (a `Menu_ExpandListTemplate` message at `0x087F83BC`) and 61/64
(action-record templates). No translated template adds a code that hangs
`Menu_ExpandListTemplate`, and every one it receives ends in `0x301`. Typed messages are safe
regardless: the translation's typewriter (`cave_typewriter.c`) clamps its line buffer at 63.
The two remaining unresolved sites pass run-time strings through the typed path or a 31-glyph
suffix. Margins are thin: a template under `Menu_ExpandListTemplate` should stay at or below
63 counted units (names 8, party 16, items 15).

`Battle_BuildStatusResultText` (`0x080EB16C`) is **dead code**: no caller and no pointer to it
anywhere in the ROM. (Its table entries end in `0x301` while it copies until `0x0000`, so it
would overrun if it ever ran.) The translation's `patch_namemove` hook on it has no effect;
the status は/を messages it was meant to cover are built elsewhere.

## Name and number caps

- Demon, race, item, party and action names are copied as **at most 8 glyphs** everywhere
  checked: battle builders (`Battle_*`), script substitution (`0x08132B40`, which also clears
  word 8 after `Combatant_DecodeName`), name entry and party names (`NameEntry_*`,
  `Name_Equals8` `0x080D1AD8`, the 4×8 extra names at state+`0xA00`), and the 3-up item/skill
  rows (`0x080D2B70` / `0x080D2C44`, exactly 8 glyphs at 12 px).
- Location/area substitutions `0x328`/`0x329` copy at most 10 words from 20-byte records
  (`0x0878F9CC`, `0x0878EF04`); a record without `0x301` in words 1–9 also copies the next
  record's first word.
- Save screen: location names stop at 16 glyphs (`0x080D035C`), the token string at 8
  (`0x080D042C`), the slot text at 9 (`0x080D0498`).
- Numbers print at most 8 digits (`NumberToDigits` `0x080A9CC0`).

## Fixed-shape templates

Several battle messages are spliced at fixed glyph counts, so translated templates must keep
these layouts (or the builders must be patched):
`Battle_BuildDodgeText` copies 5 glyphs, the name, 5 more; `Battle_BuildActorStatusText` 5,
name, 4; `Battle_BuildDamageDealtText` 2 before the number; `Battle_BuildRaceCountText`
skips `tmpl[0..2]`, appends `tmpl[3..4]` after the number and forces `0x300`; Reward,
ValueReward and ItemDrop templates are several zero-terminated pieces in a row;
`sub_080EB810` splits at the first `0x300`; `Battle_BuildNamePrefixText` takes the prefix
length from `tmpl[0]`. The status page labels (`StatsPage_*`, `0x080D22C0-0x080D2B6F`) are
hard-coded glyph IDs at fixed x positions: English labels need code changes.

## Text rendering (variable-width font)

- `Font_DrawGlyph` / `Font_DrawGlyphTinted` (`0x080AC8D0` / `0x080AC980`) copy only the 12×13
  pixels at (2,2) of each 16×16 cell; ink outside that box never reaches BG text.
- **Tinted blit (`0x080AC62C`, `Canvas_BlitOrTinted`)** adds the tint to *every* nonzero
  destination pixel in its 12×13 box after the OR (confirmed from the original instructions),
  and the 8-bit add can carry into the neighbouring pixel. Glyphs are drawn left to right, so
  glyph n+1's box overlaps glyph n's ink only if that ink is wider than glyph n's advance.
  **Checked against the current English font: no glyph's ink exceeds its width-table advance**
  (codes `0xBC`–`0x118` vs `WIDTH_TABLE`), so the translation's tinted VWF labels
  (`patch_menutinted` and the other per-glyph `Font_DrawGlyphTinted` users) do not trigger it.
  It stays a constraint for font changes: ink wider than the advance gets double-tinted
  wherever the tint is non-zero (constant tints 2, 4, 6, 8 occur at call sites).
  (`rom_layout.py` calls this function `Font_BlitGlyph`; the plain OR blit is `0x080AC4E4`.)
- **Glyph sprite cache (`0x080AC218` / `0x080AC2A0`)**: 64 slots (the OBJ tiles 384–639),
  nothing evicted until `Font_ResetGlyphSpriteCache`. When full, the cache returns -1 and the
  draw uses it as a slot (tile = base − 34): the 65th distinct glyph since the last reset
  draws wrong tiles. No bounds check on the bank index either.
  In the translation, `Text_DrawSpriteString` and most per-glyph sprite drawers are hooked into
  its own content-addressed strip allocator (`cave_strip.h`), which uses the rows of the same
  64-cell region above the engine's label cache and moves its floor every frame. Eight
  functions still draw through the engine cache unmodified: `Text_DrawSpriteStringTinted`
  (`0x080AC3AC`, 5 callers in `0x080DB188`–`0x080E3xxx` screens), `sub_080BF5D8`,
  `sub_080BF6D4`, `sub_080CF1DC`, `sub_080CF250`, `sub_080D4190`, `sub_080E1030`,
  `sub_0814ADAC`. These draw the same glyph codes as the original game (the two list screens
  behind `Text_DrawSpriteStringTinted` copy each row's inline record name), so the translation
  does not change what they put in the cache.

  **What the translation does change is the capacity.** `cave_msgwin.c` (the message-window
  strip renderer, reached from `sub_0813DED8`) lowers `gGlyphSpriteCache.capacity` from 64 to
  56 whenever a message window draws, to keep cells 56–63 for its static template strip (shop
  price digits, cursor). The cap stays at 56 until the next `Font_ResetGlyphSpriteCache`, so
  while it holds, the 57th distinct cached glyph — not the 65th — draws with slot -1.

  **Run-time check** (`tools/emu/gdbdrive.py`: mGBA's GDB server, a breakpoint on
  `Font_CacheGlyphSprite`'s full-cache path `0x080AC134` logging the caller, a write watchpoint
  on the capacity, and input injected after `Keys_Read`'s `REG_KEYINPUT` load): about 5,000
  frames of the current translation build — boot, disclaimer, title, a new game through the
  prologue, the Valhalla gym, the field command menus, VR training and a battle. **No
  overflow.** Peak use was 49 of 56 cells on the dialogue pages of the Okamoto gym intro (the
  page the translation's own notes describe as the old failure case); battles and menus kept
  the engine cache nearly empty because the strip renderers handle them. The capacity write
  was traced to the far cave at `0x08C909F2`. Not reached at this point in the game: shops,
  the DDS/Visionary and dictionary screens, the casino, and the item/exchange lists with items
  (the inventory is empty). Those need a later save to test; the driver can load one.
- The sprite path skips codes `0` and `0x3F` (space); `0x0000` and `0x0301` both end a string;
  one `advance` value is used for both x step and line height.

## Script VM

- The translation's `opcode_spec.json` gives 0x31A–0x32F and 0x36E one operand; only 0x327
  reads one (`src/script_subst.c`). The decomp's text extractor corrects this; the translation
  tool's `ALIAS_OPC` already treats them as bare.
- If a substitution writes nothing (0x326, 0x327 with operand > 3, a 0x328/0x329 record that
  starts with 0x301), no `0x318` terminator is written and the VM runs on into `0x0203DB28`.
  The event banks never do this; runtime-built text was not checked.
- `0x320` appends glyph `0xC8F` (plural) when more than one party member is present.
- `Item_RenderDescription` (`0x080D2D80`): for descriptions of 2+ pages, page 0 draws until
  the second `0x300` and page 1 starts after it, without checking `0x0000`/`0x0301`. A
  translated multi-page description with fewer than two `0x300` runs past its end.

## Possible original bugs (not translation-specific)

- `Menu_ExpandListTemplate` (`0x080EBCA4`): code `0x321` with item id ≥ `0xFF` uses a stale
  register as the name pointer; codes `0x31F`, `0x322`, `0x323`, `0x326`–`0x329` never advance
  the source pointer (infinite loop if they ever appear).
- Affine sprites (`0x080A9F04`, `0x080AA2DC`, `0x080AA514`): the OAM matrix number is masked to
  3 bits while the slot counter is not, so from the 9th affine sprite in a frame sprites use
  matrices 0–7; nothing caps the counter at 32 (a 33rd overwrites the OAM buffer at
  `0x030033F0`). `0x080AA790`/`0x080AA998` test the affine pointer after advancing it, so the
  NULL check never fires.
- `Task_GotoLabel` (`0x080AD1A8`) never stops if the label is missing; the task "loop" op with
  N = 0 runs 65,536 times.
- SRAM: a header mismatch (magic `0x10241179`, version `0x11`) makes `0x080D1180` reformat all
  32 KB.

## Found in the second conversion round

- **Untranslated shop header (likely visible).** `Shop_InitItemList` (`0x08133B18`), when its
  mode argument is non-zero, writes a 13-glyph string straight from code into the message
  glyph list: 選択中のアイテムの所持数 ("quantity owned of the selected item"). The translation
  re-points this code to its relocated list but leaves the glyph IDs, so the English build
  should still show this header in Japanese. Needs a code patch, not a text edit; confirm on
  screen at a shop.
- **Message page glyph cap.** The original `ScriptVM_Run` clamps the glyph list at 63 entries
  (`0x0813DCBE`); later glyphs overwrite the last entry. The translation raises the clamp to
  191 and moves the list to `0x0203F400` (192 records). All 18 literal pools that pointed at
  the old list `0x0203D800` are rewritten in the patched build (checked).
- **Original message layout** (`sub_0813DED8`, now replaced by the translation's renderer):
  fixed 13-px cells, no automatic wrap, no bottom check (extra lines draw below the window).
- **`MessageBox_ComposeWrappedText`** (`0x080EBED4`) inserts a newline after every 17 counted
  glyphs (a glyph count, not a pixel width) and writes the 64-glyph compose buffer unbounded.
  The translation routes the flee messages around it; any other caller still wraps at 17.
- **Second glyph list** `0x0203DA00` is cleared as 25 entries but appended without a bound
  (`sub_08133724`); shop rows start at entry `0x18`.
- **Item counts** are drawn as at most two digits (`0x08133F14`); a count over 99 indexes past
  the 10-entry digit table.
- **Fixed 8-glyph names, 12 px apart** in the casino prize list (`0x080D37BC`) and the record
  list (`0x080D4190`): longer English names are cut, shorter ones must be padded.
- **Info panel** (`0x080D3F04`): values at fixed x offsets (`x+0x22/0x32/0x3A/0x42`, number at
  `x+0x52`), so longer labels overlap them. **Keypad** prompts (`0x084F3FDC/F0/FC`) are drawn
  at a fixed 12-px advance from x=0x10 with digits at fixed x (0x4C coins, 0x7C door code).

### More possible original bugs

- `FieldView_DrawLayer` (`0x080B2D94`) compares a "kind" that is never assigned (leftover r8).
- `View_GetWall` (`0x080B0248`) takes u16 offsets but gets -1/-2; it works only because EWRAM
  mirrors every 256 KB.
- `sub_080AF85C` passes an uninitialised script pointer for kinds outside 0x30–0x34.
- `sub_080D478C` calls `sub_080C4618` with an uninitialised first argument; `sub_080D3B58`
  returns a leftover value that lands in `gYesNoResult`.
- `sub_08133854` can list a fourth party member after skipping one (inconsistent bound).

## Found in the third conversion round (title screen, opening, event character sprites)

- **Boot notice** (`Intro_DrawDisclaimer`, `0x080D67BC`): exactly 17/16/17 glyph sprites from
  the list at `0x085096C4`, 13 px apart, rows starting at x 0/13/8. Already handled: the
  translation swaps the intro step's function pointer (`0x08509EEC`) for its own proportional
  renderer (`engine/script/patch_introdisclaimer.py`) and points the string literal
  `0x080D6868` at the English text (checked in the patched build).
- **Title menu labels** are pre-drawn sprites (`0x0813ED6C`-`0x0813EE08`) at fixed positions,
  not text; the translation replaces the logo graphics (`patch_titlegfx.py`, literal
  `0x080D68BC`).

### More possible original bugs

- `sub_080D7840` matches character tasks (`+0x2A`) against a value that is never set (a
  leftover r6), so which tasks it signals depends on the caller.
- `sub_080D8384` leaves the tile and palette unset for slots other than 0-2.
- `sub_080D77FC` looks up the character record and then ignores it.

### Scene effects (`0x080BA1AC`-`0x080BD878`, script ops 0x406/0x407)

No text is drawn here, so nothing limits the translation. Oddities in the original:

- `0x080BB820` keeps a debug control: Up/Down (`gRepeatedKeys`) shrink and grow a running
  effect's sprite.
- `0x080BB2A0` and `0x080BCDC4` test `0x0200AB04 & 0x8000`, but both branches fade to white.
- `0x080BCAFC` builds a scaled copy of the sprite and then draws the original table.

### Automap and field events (`0x080B447C`-`0x080B89B0`)

- **Location banner** (`0x080B6364`/`0x080B6460`/`0x080B6568`): names are 10-byte entries at
  `0x08163444` (37 of them). Only A-Z ( ) ' & _ have glyphs; 0x100 bytes (8 tiles) are
  uploaded and the reveal is centred for 8 letters; a longer name writes past the buffer at
  `0x0203A2E4` into the banner task's pointer at `0x0203A3E4`. The translation rewrites 7
  entries (FUSION, MESSIAN, GAEAN, HEALER, SPRING, SHOP, VR), all within 8 letters and the
  glyph set (checked in the patched build).
- **`Text_CopyToMenuBuffer`** (`0x080B8490`) copies a message into `gMenuState`
  (`0x0203A454`) up to the 0x301 terminator with no length limit. Still to check: which
  translated treasure messages pass through it, and how much room follows.

### More possible original bugs

- `Spring_HealMember` (`0x080B86B0`), kind 2: calls `sub_080C8490` twice on a cure and reports
  success even when nothing was cured.
- `Warp_ToWorldPosition` (`0x080B7AFC`) and `sub_080B7E3C`: warp to an uninitialised map when
  no sub-map contains the point.
- `sub_080B8384`: the message is uninitialised outside 0x120-0x12B (`sub_080B8354` guards it).

## Found in the fourth conversion round

### Extras menu, vision replay, demon compendium, link cable (`0x080D977C`-`0x080DF6D0`)

- **8-glyph names.** `Vision_DrawItemList` (`0x080DADF8`), `sub_080DBCDC`/`sub_080DC2B0`
  (demons), `sub_080DBE9C` (races) and `sub_080DC1D8` draw exactly 8 glyphs, 12 px apart, with
  no terminator check; `sub_080DC0F0` draws at most 3. Already handled: the translation
  replaces each of these loops with a call into its own code (`0x080DAE8A`, `0x080DBD86`,
  `0x080DBF10`, `0x080DC15C`, `0x080DC23E`, `0x080DC364`; checked in the patched build).
- **Vision prompt** (`Vision_ComposePrompt`, `0x080DAF50`): the string `0x08009534` follows the
  variable-length name on one line with no wrap. The translation patches this function too
  (`0x080DAF79`, `0x080DAFE4`).
- **Help text** (`sub_080DA150`): the string comes from `0x08581598` at `(item-1)*5 + cursor`,
  so every item/row combination needs its own text.

### More possible original bugs

- `sub_080D9F40` calls `Window_Close` with one argument; the second is whatever is left in r1.

### Field event commands, elevator, doors, records (`0x080B89B0`-`0x080BA1AC`, `0x080BD878`-`0x080BF908`)

- **8-glyph names, 12 px apart:** `sub_080B9150`, `Status_ShowAfflictionMessage` (`0x080BEA60`),
  `Item_DrawName` (`0x080BF37C`), `sub_080BF5D8`, `Demon_DrawName` (`0x080BF6D4`). The first two
  decode the name into a `u16[16]` on the stack and place the following text at
  `x + 12 * glyphs`. The translation patches the first three (checked in the patched build);
  `sub_080BF5D8` and `Demon_DrawName` are unpatched but dead: no call and no pointer to them
  anywhere in the ROM.
- **Elevator floor labels** ("<n>F" / "B<n>F", `0x08165674`/`0x0816567A`, digits
  `0x0816567E`) are fixed glyph strings at hard-coded x `0x9C`-`0xCC`, at most two digits.
- **`Demon_GetRecord`** swaps in the party member's own name for ids 0x106/0x108/0x109/0x10C/
  0x10E inside a 96-byte copy at `0x03005FC0` (name at `+0x22`): the name gets only the record's
  name field.

### Battle rules (`0x080ED1C8`-`0x080F2AC8`)

- Message 0x172 (`sub_080F0C18`, through `Menu_ExpandListTemplate`) is in the battle budget
  check: 19 of 64 glyphs in English.

### More possible original bugs

- `Door_TryOpen` (`0x080BE76C`) never checks for a missing door record (reads from address 2).
- `Field_WarpToWorldPos` (`0x080BF0C0`): uninitialised map/floor when no map contains the point.
- `sub_080B8BA8` (kind > 4) and `Status_ShowAfflictionMessage` (unknown ailment bit) use
  uninitialised values; `sub_080BE6E0` falls off its end without a return value.
- `0x080ED5B4`: with the level above every threshold the table index is a leftover register.
- Escape check (`0x080EDF0C`): the enemy stat sum is uninitialised when no enemy is alive.
- `0x080EDD8C` rolls each enemy's speed twice and throws the first roll away (only the random
  sequence changes); `0x080EEEE8` has unreachable affinity cases 1-7.
- `0x080EDBCC` passes (lo, n) to an insertion sort that expects (lo, hi); harmless, lo is always 0.

## Found in the fifth conversion round

### Combatant records, field main loop, moon/encounters, flags (`0x080BF908`-`0x080C2D48`)

- **Name encoding.** Combatant names are 8 encoded bytes (a u32 follows at `+0x08`); demon
  names are 8 glyphs at `+0x22` (defaults: 4x8 bytes at `0x081A6244`). `Name_EncodeChar`
  (`0x080C03E8`) knows only the 224-entry table at `0x081A5A6C` and maps anything else to 0xE0;
  `Combatant_DecodeName` and two neighbours read the same table. Already handled: the
  translation points all four literals (`0x080C0358`, `0x080C03A4`, `0x080C03CC`, `0x080C041C`)
  at its own table at `0x0869C26C` (checked in the patched build).
- **Race names** (`Race_GetName`, `ParentRace_GetName`, `sub_080C06AC`) are fixed 16-byte slots.
- `sub_080C0378` decodes until 0 or 0xFF with no length limit, but nothing calls it.

### More possible original bugs

- `sub_080BFE98` computes an over-70 cap for the extra stats and discards it, so they are never
  capped (bonus stats are, by `Stat_CapBonus`).
- `sub_080C0E44` and `sub_080C0EC0` return an uninitialised value for a stat index above 5.
- Play time stops at 255:59:59 (`0x080C22E4`), apparently on purpose.

### Battle command menu (`0x08126F84`-`0x0812BF54`)

- **Names in the lists.** Rows (`0x081272CC`, `0x08127394`) draw at most 8 glyphs, 12 px apart;
  `Menu_DrawLabeledName` (`0x081289B8`) at most 5, right-aligned; the demon line at `0x0812A39C`
  puts the string `0x0800354A` after the name at `x = 0x12 + 12 * glyphs`. The translation
  patches all four (checked in the patched build).
- **Status names** (`BattleMenu_DrawStatus`, `0x08128828`) are 18 fixed 8-byte entries at
  `0x08777D54`, drawn with the digit font. They are ASCII already in the Japanese release
  ("DEAD", "STONE", ...), so the translation leaves them alone.
- `BattleMenu_DrawListPage` (`0x08127EAC`) decodes names into a 16-byte stack buffer; this is
  safe, because `Combatant_DecodeName` always writes exactly 8 glyphs.

### More possible original bugs

- `Inventory_Find` (`0x0812BCD4`) has no end check: an id that is not in the table walks past it.
- `0x0812876C` reads a digit it never uses and always draws at least two level digits.

### Enemy info, skill and item effects (`0x080F2AC8`-`0x080F6388`)

- **Enemy info screen** (`EnemyInfo_DrawPage` `0x080F390C`, `EnemyInfo_DrawSkillNames`
  `0x080F3850`, `EnemyInfo_HandleInput` `0x080F3C4C`) and `Skill_DrawEquippedRow`
  (`0x080F3254`) draw names as fixed 8-glyph fields, 12 px apart; the race name from
  `sub_080EA9F8` is drawn up to its terminator with no length check. The translation patches
  all four functions (checked in the patched build); long race names are still worth a look on
  screen. The labels at `0x0876F81C`/`0x0876F83C`/`0x0876F854` are ASCII in the Japanese
  release.
- Battle messages chosen here (0x96, 0x7E, 0x95, 0x119-0x139, 0x153/0x154, 0x324, 0x389,
  0x39A, 0xCB-0xCF, 0xD9/0xDA, 0xE5/0xE6) are inside the battle budget check, which stays clean.

### More possible original bugs

- `sub_080F4A60` cancels party buffs in row 4 with the unclamped `sub_080EFDEC` but enemy buffs
  with the clamped `sub_080EFE00`; `sub_080F4B54` (debuff cancel) skips row 4 entirely.
- `sub_080F5D28`: healing past 998 HP or twice max HP sets HP to half of max and inflicts a
  status (4 or 0x1000).
- Enemy skill 0x9F (`sub_080F2D4C`) goes through a counter at `0x0203C174` cycling 0-2, so it
  fires once in three tries.
- `sub_080F30CC` and `sub_080F40EC` are identical.

## Found in the sixth conversion round

### Battle menu (rest), auto-recovery, message-window helpers (`0x0812BF54`-`0x081332BC`)

- **Second untranslated Japanese header.** `sub_081305D8` writes the 13 glyphs
  選択中のアイテムの所持数 ("quantity owned of the selected item") straight into
  `gMsgGlyphQueue` entries 0-12 and appends a two-digit count (`MsgWindow_DrawItemCount`,
  `0x08130578`). It is reached from `sub_08131B1C`, a step of the task script at `0x0878FF8C`,
  which `ScriptOp_33D` starts; op 0x33D is used by the shop script at `@Txt_0807DF42`
  (`event_b.txt`). The translation's only changes in these functions are the glyph-list
  relocation literals (`patch_msgwin.py`), so the header is still Japanese, the same text as
  the `Shop_InitItemList` header found in round two. An English label needs a code patch and
  must fit 13 glyphs (or move the count). Confirm on screen in a shop.
- The count is two digits from `gScriptDigitGlyphs[n / 10]`; 100 or more reads past the table.
- `MsgWindow_RestoreGlyphs` (`0x0812F1E4`) re-lays saved glyphs at a fixed 13 px; the
  translation already patches it (row-save relocation, `patch_msgwin.py`).

### More possible original bugs

- `0x0812C760` reads the cursor's list entry as `((u8 *)list)[index]` instead of
  `list[index]`, so the skill description is right only at index 0.
- Auto-recovery uses up item 0xB5 only one time in eight (`0x0812E6C4`), and its caster
  search (`0x0812E558`) never considers member 0 (the hero).
