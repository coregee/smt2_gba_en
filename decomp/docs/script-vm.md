# Event script VM: state and opcodes 0x300-0x32F

Source: `src/script_ops_300.c`, `src/script_ops_304.c`, `src/script_subst.c`,
`include/script.h`. Proposed names in `src/script_names.tsv`. Globals are still
address-named (`gUnk_XXXXXXXX`) in the C. See `docs/text.md` for the encoding.

## Dispatch

`ScriptVM_Run` (0x0813DB34) first calls the wait-state handler
`table_0x08790FDC[gUnk_0203DB5A]`. It then loops:

1. if `gUnk_030068E4` (pending jump) is non-zero, the base becomes that pointer, the jump is
   cleared, and pc = 0;
2. `op = base[pc++]` (stored in `gUnk_0203DB44`);
3. if `op - 0x300 <= 0x170`, it calls `gScriptOpTable[op - 0x300]` (0x087913DC) and returns if
   the handler set `gUnk_0203DB6E` (yield) to 1. Otherwise `op` is a glyph and is queued for
   drawing at (column `gUnk_0203DB38`, line `gUnk_0203DB3A`).

`ScriptVM_RunAlt` uses `gScriptOpAltTable` (0x08791BDC). That table's handlers do almost
nothing: they skip operands (`ScriptOpAlt_Skip1/2/3`), set `gUnk_0203DB5E` to 1 or 2, or run
the real control-flow handlers (0x308, 0x30A-0x30D, 0x30F, 0x312, 0x319, 0x32A). It looks
like a pre-scan of a message. Its text-substitution entries take no operands.

## State

| Address | Type | Proposed name | Meaning |
|---|---|---|---|
| 0x03006950 | `u16 *` | gScriptBase | current script / string |
| 0x0203DB40 | u16 | gScriptPc | word index into the base; operand reads post-increment it |
| 0x030068E4 | `u16 *` | gScriptJumpTarget | pending jump (low word first in the stream, then high word) |
| 0x0203DB44 | u16 | gScriptCurOp | opcode being executed |
| 0x0203DB6E | u16 | gScriptYield | 1 = return from `ScriptVM_Run` after this handler |
| 0x0203DB5A | u16 | gScriptWaitState | wait handler index: 2 (0x305), 3 (0x316/0x341), 5 (0x317), 7 (0x310), 10 (0x30E), 15 (0x315) |
| 0x0203DB38 / 0x0203DB3A | u16 | gTextColumn / gTextLine | text cursor (13-pixel cells) |
| 0x0203DB3E | u16 | | queued glyph count (capped at 0x3F by the VM) |
| 0x0203DB48 | s16 | | 1 while the player skips text; shortens 0x315 delays |
| 0x0203DB6C | s16 | | message window open (window handle in 0x03006968) |
| 0x0203DB50 | u16 | gScriptItemCheckId | item id for 0x30B |
| 0x0203DB28[2], 0x03006970[2], 0x0203DB66/68 | u16 | | two display slots (0x308/0x309/0x307, `sub_08132890`) |
| 0x030068F0[16], 0x030069C0[16] | u32 | | handles created by 0x304 and 0x309, freed by 0x307 |
| 0x0203DB08[16] | u16 | gScriptSubstBuf | text-substitution string |
| 0x0203DB4E / 0x030068CC | u16 / `u16 *` | gScriptSubstSavedPc / Base | return position for 0x318 |

**Return stack (0x301).** There is no stack array. There are five levels, each a separate
"active" variable plus a saved pc and base, checked innermost first:

| active | saved pc | saved base |
|---|---|---|
| 0x030069CC (u16) | 0 | 0x0203DB04 (= `((u16 **)0x0203DAC8)[15]`) |
| 0x03006910 (s16) | 0x03006610 | 0x030068D0 |
| 0x030065EC (s16) | 0x03006960 | 0x03006854 |
| 0x03006600 (s16) | 0x030069E0 | 0x03006674 |
| 0x0203DB64 (s16) | 0x03006818 | 0x030068C4 |

When no level is active, 0x301 ends the message: it clears the cursor and pc, sets
`task->unk1C = 1` (the argument the VM passes to every handler), and sets 0x0203DB46 to 1.
It also calls `sub_0813EB6C(0)`, `Font_ResetGlyphSpriteCache(0x180)` and
`sub_080AD1FC(*0x030069E4)`, then yields.

## Opcodes in this range

"ops" = operand words read by the main-table handler. "ptr" = a 32-bit stream pointer given
as two words, low word first.

| Op | Handler | ops | Meaning |
|---|---|---|---|
| 0x300 | ScriptOp_300 | 0 | newline: column 0, line+1 (and 0x0203DB4A+1) |
| 0x301 | ScriptOp_301 | 0 | return from the innermost active level, or end the message (above) |
| 0x302 | ScriptOp_Shared_081321B4 | 0 | no-op (as are 0x314, 0x330-0x332, 0x335, 0x339, 0x342-0x351, ...) |
| 0x303 | ScriptOp_303 | 1 | `sub_08132350(id)`: 0xFF -> `sub_080C5170(0)`; 0xC4/C5/C0/C2 remap to 0x8F-0x92; ids < 0xC0 are mapped through u16 table 0x08790180 (0xFFFF = none), then results < 100 go to `sub_080C5170` and others to `sub_080C51D4` |
| 0x304 | ScriptOp_304 | 3 | `h[a&15] = sub_080C4618(a, b, c>>8, c&0xFF, a&0x10?1:0, a&0x20?1:0)`; yields if `sub_080D95F4(b)->+0x28` is non-zero |
| 0x305 | ScriptOp_305 | 1 | `0x030068B0 = sub_080B6DB4(x)`, wait state 2, yield |
| 0x306 | ScriptOp_306 | 1 | operand ignored |
| 0x307 | ScriptOp_307 | 1 | frees slot i: `sub_080E9044(0x030069C0[i], i)` if set, else `sub_080C48F0(0x030068F0[i], 0)` |
| 0x308 | ScriptOp_308 | 1 | slot 0 id := low byte of operand, 0x03006970[0] = 1, 0x0203DB66 = 1 |
| 0x309 | ScriptOp_309 | 1 | `0x030069C0[a] = sub_080E8E00(a, 0x0203DB28[a&15])` |
| 0x30A | ScriptOp_30A | 1 | item id for 0x30B := operand |
| 0x30B | ScriptOp_30B | ptr | jump unless the item is held. For ids < 300, `sub_080C32D4(id)` (the item's count byte) must be 0 for the jump. For ids >= 300, `sub_080C57CC(id) == 1` means held; the handler then calls `sub_080C3328(id)` (Alt: no call) and does not jump. |
| 0x30C | ScriptOp_30C | 1 + ptr | jump if `Flag_Test(id) == 1` (id 0x114: `sub_080C2A84(2) == 1`); otherwise skip the pointer |
| 0x30D | ScriptOp_30D | ptr | party-condition jump: needs member 1 or 2 present (`sub_080C09B0`); jumps if member 0's or 1/2's 0x18 field is 0, or if the OR of `sub_080C0818` over members 0 and absent 1/2 has bits 0x3000 |
| 0x30E | ScriptOp_30E | ptr | stores the pointer at 0x0203DAC8, wait state 10, `0x030068E0 = sub_080ABEB4(0)`, yield (sub-menu) |
| 0x30F | ScriptOp_30F | ptr | unconditional jump |
| 0x310 | ScriptOp_310 | 1 | flag 0xD5 := operand != 0; wait state 7; `sub_08132890()` (shows slots); clears cursor; closes the window if open; resets the glyph cache; yield |
| 0x311 | ScriptOp_311 | 1 | 0x030068A8 := operand |
| 0x312 | ScriptOp_312 | 1 | Flag_Set(operand) |
| 0x315 | ScriptOp_315 | 0 | delay: wait state 15, 20 frames (1 frame when skipping), yield |
| 0x316 | ScriptOp_316 | 0 | wait for button: wait state 3, `sub_080AD0FC(0x087900EC, 0xFFFF)` (prompt sprite), 0x0203DB52/54/56 = 1/30/1, yield |
| 0x317 | ScriptOp_317 | 0 | new page: wait state 5, `sub_080AD0FC(0x087900A0, 0xFFFF)`, yield |
| 0x318 | ScriptOp_318 | 0 | return from a substitution string (pc/base := saved) |
| 0x319 | ScriptOp_319 | 1 | Flag_Clear(operand) |
| 0x31A-0x329, 0x32E, 0x32F, 0x36E | ScriptOp_DrawCharOrSubstitute | 0 (0x327: 1) | text substitution (below) |
| 0x341 | ScriptOp_341 | 0 | like 0x316 without the 0x0203DB52/54/56 setup |

Flag functions: `Flag_Test` 0x080C2340, `Flag_Set` 0x080C2364 and `Flag_Clear` 0x080C23BC
work on the bit array at 0x03005CA8. Flags 0x120-0x14D are mirrored at 0x03004680.

## Text substitution (ScriptOp_DrawCharOrSubstitute, 0x08132B40)

The handler clears the 16-word buffer at 0x0203DB08. It saves pc and base in
0x0203DB4E/0x030068CC, writes a string into the buffer, and makes the buffer the script
(pc = 0). The string ends with 0x318, so the VM draws it as ordinary text and then returns.
"party[n]" is the 0x80-byte combatant record at 0x030046C0 + n*0x80.

| Op | Text |
|---|---|
| 0x31A | name of party[0] (`Combatant_DecodeName`) |
| 0x31B / 0x31C / 0x32E | name of the combatant `sub_080C10E4(0x8001 / 0x8002 / 0x8000)` |
| 0x31D | in battle (0x03006670 == 1): party[2] if `sub_080C09B0(2)`, else party[1]; outside battle: party[1] |
| 0x31E | demon name: 8 words at `sub_080BF648(id) + 0x22`, id = 0x0203DB7C in battle, else 0x0203DB28[0] |
| 0x31F | race name of that demon (`Race_GetName(*(s8 *)record)`), 8 words |
| 0x320 | name of the first party member with `sub_080C0A00(i) == 1`. If more than one member is present, glyph 0xC8F follows (plural suffix). The handler writes its own 0x318. |
| 0x321 | item/equipment/action name for id 0x0203DB50: ids >= 0xD0 use `Action_GetRecord(id) + 0xC`; 0x80-0xCF use `Equipment_GetRecord36_MidRange(id) + 0x14`; others use `sub_080BF32C(id) + 0x14`. 8 words. |
| 0x322 | demon name for 0x0203DB7E (battle) or 0x0203DB28[1], 8 words |
| 0x323 | decimal number from u32 0x0203DB2C |
| 0x324 | name of party[*0x03006850] |
| 0x325 | name of party[2] |
| 0x327 n | n=0: race of demon 0x0203DB28[1]; n=1: 8 words at `sub_080BF5C0(*0x0203DB80) + 6`; n=2: number from u32 0x0203DB30; n=3: number = count of item 0x11F (`sub_080C32D4`); other n: empty |
| 0x328 | up to 10 words from record 0x0203DB72 of the 20-byte table 0x0878F9CC, starting at word 1 and stopping at 0x301 |
| 0x329 | up to 10 words from record `0x030069A0[0x0300696C]` of the 20-byte table 0x0878EF04, stopping at 0x301 |
| 0x32F | decimal number `sub_080C31F0()` |
| 0x36E | the single glyph 0x52, then 0x318 |
| 0x326 (and 0x327 with n > 3) | nothing is written (default case) |

Numbers are written with the digit glyphs at 0x0878F9B8 (0xCC-0xD5). There are at most 8
digits; leading zeros are dropped, and 0 is written as one digit. For name cases the handler
then searches back from word 14 for the last non-zero word and puts 0x318 after it.

### Notes for the translation

* **Names are cut to 8 glyphs.** The copy loops are fixed 8-word copies, and after
  `Combatant_DecodeName` the handler clears word 8. A longer English demon, race, item or
  party name is truncated when substituted, even if the source table stores more. Longer
  names need a new copy length and terminator position in this handler. The buffer has room
  for 15 glyphs plus 0x318, and 0x0203DB28 (live slot ids) comes right after it.
* **0x328 and 0x329 copy at most 10 words.** 0x328 reads words 1-10 of a 10-word record.
  If no 0x301 appears in words 1-9, it also copies the next record's first word.
* **The substitution opcodes have no operand, except 0x327.** `opcode_spec.json` gives
  0x31A-0x32F and 0x36E `len: 1`. As a result `assets/text/*.txt` shows `{ALEPH 014A}`,
  `{DEMON_NAME 0006}` and so on: the first glyph after the name is printed as an operand.
  The ROM data confirms this. In event_b, 0x31A is followed by 0x0300 (newline) 39 times,
  by 0x0316 (wait) 16 times and by 0xC8F 18 times. These are text, not operands. The
  rebuild is still byte-exact, but an edit to that "operand" changes the visible text. The
  translation tool's `ALIAS_OPC`, which treats them as bare 2-byte tokens, is right.
* The number formatter drops digits above 8 (values >= 100,000,000).
* **Possible original bug: an empty substitution has no terminator.** The search for the end
  needs at least one non-zero word. When nothing is written (0x326, 0x327 with n > 3, or
  0x328/0x329 whose record starts with 0x301), no 0x318 is placed. The VM then runs past the
  16-word buffer into 0x0203DB28 and the words after it, drawing glyph 0 until it reaches a
  word that is an opcode. The event banks contain no 0x326, and every 0x327 there has
  operand 2. Opcodes may also be built at run time, e.g. battle text, which was not checked.
