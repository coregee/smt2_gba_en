# Text and event scripts

Source: `assets/text/<bank>.txt` (editable), generated `assets/text/<bank>.s` (`.include`d by the
data sources through `assets/text/includes.json`), glyph table `assets/text/charmap.txt`.
Tool: `tools/assets/text.py` (`extract` from the ROM, `build` .txt → .s, `check` = build, then
assemble and link every bank at its ROM address and compare with `baserom.gba`).

## Encoding

Every string is a sequence of little-endian u16 words.

| Word | Meaning |
|---|---|
| 0x0000–0x11FF | font glyph (main 16×16 font; 0x0300–0x0470 are never drawn, see below) |
| 0x0000 | string terminator (menus, battle, tables) — `{0}` |
| 0x0300 | newline — `{n}` |
| 0x0301 | end of message; in the event VM a return off the 5-deep gosub stack — `{END}` |
| 0x0316 / 0x0317 | wait for button / new page — `{WAIT}` `{PAGE}` |
| 0x0302–0x0470 | event-VM opcodes, followed by operand words — `{NAME operands}` |
| 0x0057 | blank pad glyph (location-name cells) — `{_}` |
| 0x11FE | dead padding after jumps — `{PAD}` |

Glyph codes are written as characters using the translation project's curated atlas
(`font/atlas/main.json`). When several codes draw the same character, the lowest code is the
canonical one; the others are written `{G:XXXX}`. Words that are not glyphs (e.g. low halves of
pointers inside tables) are `{W:XXXX}`.

## Event VM

`ScriptVM_Run` (0x0813DB34) reads a word, and for 0x0300 ≤ op ≤ 0x0470 calls
`gScriptOpTable[op - 0x300]` (0x087913DC; a second table, `gScriptOpAltTable` 0x08791BDC, is
used by `ScriptVM_RunAlt` 0x0813E428). Operand counts and pointer operands come from the
translation project's `text/config/opcode_spec.json`, which was derived from the handlers:

* fixed ops: `len` operand words; each index in `ptr` is the HIGH word of a 32-bit stream
  pointer whose low word precedes it;
* 0x313 (choice) and 0x413 (negotiation response): one count word, then `(count >> 8) + 1`
  rows of 3 words `[param, lo, hi]` / 2 words `[lo, hi]`.

Opcode names (`JUMP`, `CJUMP`, `SUBMENU`, `CHOICE`, …) are the translation project's
Ghidra-grounded names; unnamed ones are `OP_XXX`. A pointer operand is written `@Txt_XXXXXXXX`
only when it targets an even address inside these banks, and a label is then placed there;
anything else stays as hex words. The rule makes every bank byte-exact whatever its content:
where a table sits between scripts, it reads as glyph soup or `{PTR}` runs, but it rebuilds
exactly.

## Banks

| Bank | ROM | Bytes | Content |
|---|---|---:|---|
| `event_a` | 0x08009010–0x08032B7C | 170,860 | BBS boards, bank/COMP menus, music player, lore, early messages; 446 `{END}` |
| `event_ptrs` | 0x08032BBC–0x08035CBC | 12,544 | 3,136 u32 pointers: taunt/status/negotiation tables (0x08032BBC, 0x08032C60, 0x08032CD8) and the dialogue table (0x08032DE0–0x08035BB4) |
| `event_b` | 0x08035CBC–0x080A548C | 456,656 | record tables (`{ptr, u16}` and pointer arrays, ~0x08035CBC–0x080372xx), then the story/dialogue event scripts; 4,420 `{END}` |
| `locations` | 0x080A548C–0x080A96CC | 16,960 | 530 location names, 16 words per cell, padded with `{_}` (cell 0 with full-width spaces), no terminator |
| `battle` | 0x08123038–0x081267F4 | 14,268 | battle messages, fragments, menu/system strings, `{0}`-terminated (369 `{END}` inside templates) |

Boundaries: `event_a` starts after the last 16-byte record of the table at 0x08000200–0x08009010
and ends where ARM code (copied to IWRAM by 0x080DEE20) begins at 0x08032B7C. `event_ptrs`
is the maximal run of aligned in-bank pointers. `battle` starts after the OAM records ending at
0x08123036 and ends at a Thumb function at 0x081267F4.

Not covered yet: 0x08000200–0x08009010 (16-byte records and mixed menu tables with some
strings, e.g. door/item/skill texts around 0x08002E2C–0x08004A00), the ARM routine at
0x08032B7C, and text outside the program's text region (0x0815BB90 fusion/greeting strings,
0x084F0xxx menus, 0x0819xxxx records).
