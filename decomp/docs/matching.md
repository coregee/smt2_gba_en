# Matching C

Two compilers are involved, both pret builds of GCC 2.9 for Thumb, with flags
`-mthumb-interwork -O2 -fhex-asm`:

- **`agbcc`** for the game code. Evidence: leaf functions that contain a long branch save
  `lr` (`far_jump_used_p`), which `old_agbcc` never does.
- **`old_agbcc`** for Nintendo's precompiled m4a library (`src/m4a.c`): `agbcc` allocates
  registers differently there.

`tools/cc.py` uses `agbcc` unless a file has `// compiler: old_agbcc` in its first lines.

## Setup (once)

In WSL (Ubuntu): `sudo apt install build-essential git binutils-arm-none-eabi`, then
`git clone https://github.com/pret/agbcc ~/work/agbcc && cd ~/work/agbcc && ./build.sh`.
`tools/cc.py` calls the compilers in `~/work/agbcc` through `wsl.exe`; set `AGBCC_DIR` to use
another directory.

## Writing a function

1. Pick consecutive functions (a C file's functions must be consecutive in the ROM; split
   modules into several files if needed). Read `asm/code_*.s` and `reference/ghidra-c/`.
2. Write `src/<module>.c`. Put `// Name @ 0xADDR` on the line directly above each
   function. Use the function's current name from `reference/symbols.tsv` (or
   `sub_XXXXXXXX`), because other assembly calls it by that name.
3. `python tools/match.py src/<module>.c --diff` compiles just that file and compares it with
   the original, function by function, with a side-by-side disassembly of each difference.
4. When all match, `python build.py --regen` (or `python tools/disasm.py && python build.py`)
   removes those functions from `asm/` and proves the whole ROM still matches.

Globals: declare `extern` and either use a name from `symbols.tsv` (kind `ram`/`data`) or an
address name like `gUnk_030031BC` / `gUnknown_0858D354`; both build and `match.py` define
these automatically. Types and hardware definitions are in `include/global.h` and
`include/gba/`.

## When it does not match

Small register-allocation differences usually come from how the source was written: try
variable types (`u8`/`s32` locals), declaration order, `for` vs `while`, a temporary, the
operand order of a comparison, `if (!x) return;` vs nesting. When it still does not match,
keep the readable C and the original instructions:

```c
// Func @ 0x080XXXXX
#ifdef NONMATCHING
void Func(...) { ...readable C... }
#else
NAKED
void Func(...)
{
    asm_unified(...);        /* python tools/naked.py 0x080XXXXX */
}
#endif
```

`reference/function-map.tsv` counts these as `nonmatching`, matching ones as `c`.

## Known oddities

- The m4a library here is an older revision than pret's: mono output (DMA1/FIFO A only, one
  0x630-byte PCM buffer), no `soundInfo->mode & 1` test in `CgbModVol`, and a 12-entry
  extended-command table. The `ident == ID_NUMBER` functions keep pret's ident lock
  (`ident++; ... ident = ID_NUMBER;`): old_agbcc deletes both stores as redundant, and that is
  what leaves the loaded ident in `r3`.
- `gNumMusicPlayers` is an absolute symbol whose *address* is the player count (4).

## Register pins and dead stores

Twelve matching functions use GNU `register T x asm("rN")` pins and six use a dead store to steer
register allocation; `docs/status.md` lists them. Each is commented. They are a last resort, used
only where no plain source shape reproduced the original allocation; they count as matching
because the build proves the bytes, but they are less likely to be the original source.

Patterns that turned NONMATCHING functions into matches, and known dead ends, are collected in
`docs/matching-tricks.md`.
