# Shin Megami Tensei II (GBA) — decompilation

A source reconstruction of the Japanese GBA release (`A5TJ`, Atlus 2003,
sha1 `8a4a52eb5538d52762337ca045e5c85e00f19ff0`) that rebuilds the cartridge byte for byte.
It exists to make the English translation debuggable: with the whole program as named,
cross-referenced source, a translation bug can be traced to the code that misbehaves instead
of being guessed at from patch sites.

```sh
python build.py           # assets -> asm/data/src -> build/smt2.gba, compared with the original
python build.py --regen   # re-run discovery and regenerate asm/ data/ layout.json first
```

Requirements: Python 3.11+ with `capstone` (the parent project's `.venv` works), and the Arm
GNU toolchain (`arm-none-eabi-as`, `-ld`, `-objcopy`; see the parent README). The original ROM
is read from `../rom/Shin Megami Tensei II (Japan).gba` and copied to `baserom.gba`.

## Status

| Layer | State |
|---|---|
| Code discovery | all 4,501 functions found, ARM vs Thumb decided per instruction (not guessed); every byte of the program segment accounted for |
| Assembly | every function disassembled to GNU-as source with symbolic branches, literal pools, jump tables and function pointers; builds sha1-exact |
| Names | 485 functions named (crt0, IRQ handlers, BIOS wrappers, libgcc/newlib, the whole m4a sound library, the script VM and its opcode handlers, 75 engine functions from the translation patches) — see `reference/function-map.tsv` |
| Readable C | Ghidra decompilation of every function in `reference/ghidra-c/`, with names, inferred signatures and I/O register names (reference, not compiled) |
| C | 2,153 functions in `src/` (2,002 byte-matching, 151 readable C with the original instructions kept): the m4a library's C half, system/init, palettes and sprites, windows and font rendering, tasks, field/dungeon and 3D view, automap and field events, menus/save/name entry/casino/keypad, combatant records and stats, flags and options, battle rules, battle message building and flow, field event commands, elevator and doors, the title screen and opening, the extras menu, vision replay, demon compendium and link cable, event character sprites, scene effects, the script VM core and opcode handlers, the message-window renderer — `docs/matching.md` |
| Findings | translation-relevant limits and original bugs read from the C: `docs/translation-findings.md` |
| Graphics/data | 2,565 compressed streams extracted to PNG/bin and rebuilt exactly (the LZ77 encoder matches the original tool; Huffman streams keep their tree); all but 62 are identified and coloured — demons, characters, field map, dungeon, location scenes, battle effects, casino, fusion, UI (`docs/assets.md`); `tools/assets/sprites.py` draws demons and characters through their cell lists |
| Text and scripts | 659 KB in five banks as editable text with symbolic jump/choice labels (`assets/text/`, `docs/text.md`) |
| Music | 202 songs as pret-style sources, 6 voicegroups and a drum kit, 132 samples as WAV, MIDI export (`assets/sound/`) |
| Coverage | 81.8% of the ROM is built from code, text, music or asset sources; the rest is still `.incbin` of `baserom.gba` (uncompressed tile sheets, palettes, record tables) |
| Translation audit | `tools/audit_patches.py` checks the English patches against the recovered code (`docs/patch-audit.md`); `tools/battle_text_budget.py` checks every battle message against the 64-glyph buffers; both currently clean |

## Layout

| Path | What it is |
|---|---|
| `asm/` | Generated code, one file per run of ~96 functions (`code_<addr>.s`) plus `crt0.s`. Functions start with `thumb_func_start`/`arm_func_start`. |
| `data/` | Generated data sources: `.incbin` of extracted assets (`build/assets/*.bin`) or of `baserom.gba` for bytes not yet extracted, with a global label at every address the code references. |
| `layout.json` | Every source file in ROM order; the linker places them exactly in this order. |
| `assets/` | Extracted assets. `manifest.json` describes each blob (address, codec, format); `*/includes.json` lists `.s` sources (songs, scripts) that replace base-ROM bytes. |
| `reference/` | `symbols.tsv` (names: address, name, kind, confidence, evidence), `function-map.tsv` (status of every function), `ghidra-c/` (decompiler output beside each asm file). |
| `tools/` | `trace.py` (code discovery), `disasm.py` (source generation), `assets/` (codecs and extractors), `ghidra/` (headless project setup and export), `signatures.py`, `harvest_names.py`, `function_map.py`. |
| `docs/` | How the game and the tools work. |

## How the pieces fit

1. `tools/trace.py` finds code by recursive descent from the reset vector, crt0's IRQ handler
   and every Thumb function pointer in data, deciding ARM/Thumb from how each address is
   reached. It knows agbcc's habits: `bl` used as a long branch inside a function, the
   `pop {r0}; bx r0` interworking return, `adds rX, rY, #0` moves, switch tables after
   `mov pc, rX`. Coverage of the program segment is checked by `tools/coverage.py`.
2. `tools/disasm.py` writes `asm/` and `data/`. Instruction text comes from capstone and is
   accepted only if GNU as re-encodes it identically (29 instructions stay as raw `.2byte`).
3. `tools/assets/assets.py` extracts/re-encodes assets; `build.py` builds them first, then
   assembles and links everything in `layout.json` order and compares with the original.
4. `tools/ghidra/` builds a Ghidra project from the trace (headless) so Ghidra never has to
   guess instruction sets, and exports the decompilation to `reference/ghidra-c/`.

See `docs/` for the ROM map, naming rules and the workflow for turning a function into C.

## Matching C

The game code was compiled with pret's [agbcc](https://github.com/pret/agbcc) and the m4a
library with its `old_agbcc`; both run in WSL (setup in `docs/matching.md`). Write a function
in `src/`, check it with `python tools/match.py src/<file>.c --diff`, and the full build's
sha1 check proves it.
