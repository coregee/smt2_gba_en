# agbcc matching tricks

Collected by the NONMATCHING rounds (2026-10). Each entry says what source shape produced which
instruction pattern; "unsolved" entries are dead ends worth not repeating. Helper paths refer to
scratch scripts under `build/` that are not committed.


- Named temporaries for index pieces: `u32 col = x >> 3; arr[y][col]`; `u32 row=..., col=... + 0xC00; base + (row + col)` stops constants folding into the symbol address.
- Split an increment to place a constant: `v = t[3] + 1; zero = 0; t[3] = v; if ((u8)v > 59)`.
- `extern u8 gUnk_X[]; &gUnk_X[i << 7]` instead of a cast raw address swaps operand registers.
- Hoist a constant pointer argument into a local (declared after the computed one) to change load order.
- Pointer local inside the loop body (`struct Task *t = &gTasks[i]; ... return t;`).
- `for` + `break` instead of goto/do-while scans.
- Assign in each branch rather than merged: `if (r != 1) result = 0; else result = r;`.
- Switch compare tree: if the compare order differs, add empty `case N: break;` just outside the used range (separate labels, not shared).
- Do the store in every exit path (`x->f = 1; return;`) instead of `r = ..; goto done; done: x->f = r;`.
- Assignment inside the condition: `if ((st = f() & 0x4000))`.
- Put a call argument into a temporary first to reorder loads/conversions.
- Split compound arithmetic: `n &= 7; n++;`.
- Narrow parameters late: declare param u32, then `u8 slot = who; slot -= 0x10;`.
- Duplicate a call per branch (`if (c) f(0); else f(1);`) for branchy code.
- Separate stores in reverse order instead of chained `a = b = c = 0`.
- Explicit `goto` labels to reproduce shared tails / the original block layout.
- Return-type hints: `Random_Byte` returns u16 in some headers, u32 in others; `Combatant_GetStatus` u16. An `ands` operand-order difference after such a call may mean the original saw the other return type — try a local cast `((u32 (*)(void))Random_Byte)()` or masking spelled differently.
- `gC0d9Bg.exit` matched only as s16 store.
- Known blocker: gcc merges identical call tails the original kept separate — no fix found yet; try `asm("")` barriers? (not allowed in final C unless it's the only way; prefer source shapes).
- Always confirm an `OK` line from match.py: a compile failure also shows zero diff lines.

Helpers from round 1 (copy, don't edit in place): build/nm1/nm.py (show|try|apply), build/nm2/dd.py <stem> <ADDR> (full-function diff incl. past jump tables).

## More from group 3
- Use the global directly in table-scan loops (`for (i = 0; tbl[i] != 0xFF; i += 2)`), not a `const u8 *t = tbl` local.
- Stop loop strength reduction: `((struct X *)((u32)gArr + i * sizeof(struct X)))->field`.
- Byte-offset arithmetic for operand order: `u32 row = m * 34; u32 col = (u32)&tbl[0][h]; *(u16 *)(row + col)`; hold a base in a `u32` for `i + base` order.
- GCC narrows `(u32)u16 / 20` to a 16-bit divide: read as `(u32)p->v` into a u32 temp first. Reassigning the param (`x &= 0xFF;`) instead of a new local stopped `+1` becoming `|1`.
- `s16 id = f(); if (id >= 0x16A && id <= 0x17B)` gives sign-extend + sub + unsigned compare.
- CSE: pass the global you just stored (`g = 1; f(g);`); route an argument through an existing variable; load an operand into a temp before the call; `j = 0; v = t[k][j++];`.
- Load two halves separately (`lo = b[i]; hi = b[i+1]; hi <<= 16; hi |= lo;`).
- Changing the type of a pair of locals (u32 -> u8) fixed a register swap.
- Unsolved patterns: a constant base the original keeps in a callee-saved reg before the offset; store address computed before the RHS; `ands` result landing in the constant's register.
- Scratchpad helpers: nm.py (mk/try/apply), survey.py (instruction-diff count for every function in a list), hexdiff.py.

## More from group 1, round 2
- An unused loop counter: write `for (i = 0; i < N; i++)`; gcc turns it into the count-down form.
- Declare loop counters inside each branch instead of at the top.
- A dead `name++` in a sibling loop keeps a register busy and stops a constant being hoisted.
- An explicit `(u16)` cast on an argument makes gcc compute it before stack arguments.
- Keep u16-return truncation before an add: put the result in a u32 local first; call through a local cast to the real return type when headers disagree (sub_080C5D0C returns u16).
- `x = a[0]; x *= 2;` loads straight into the variable's register.
- A ternary inside `||` duplicates the compare: use if/else into a temp.
- Force a reload the original does: read via the table index (`tbl[p - tbl].f`).
- `(&tbl[0].y)[i * 2]` reproduces a separate `base + 2` register.
- File-level `extern struct T gUnk_X[][3];` instead of a cast-address macro.
- `goto` loops when the original's loop test isn't rotated (entry test kept).

## More from group 2, round 2
- Replace goto-based "readable" C with plain if/else and duplicated tails: gcc's tail merging rebuilds the shared code (fixed 5 functions). Goto versions were often further away.
- Index through a constant address `((struct T *)0xADDR)[i]` instead of the extern symbol: swaps index/base load order (gInventory at 0x030051AC was reached this way).
- Named offset temp: `u8 *blk = gX; u32 off = 0x2D0; (blk + off)` keeps the add separate.
- Block-scoped u8 local for a call result keeps it in r0.
- Assignments inside call arguments reproduce register reuse: `f(src, buf = X); g((buf -= 0x1000), ...)`.
- Dead store keeps a dead load: `if (b[1] == 0) n = 1; n = 2;`.
- u16 param compared via an s16 copy: `s16 k = kind; ... kind = k - 4;`.
- `u8 mask = mode ? 0x20 : 0xC0;` gives temp-then-move.
- Split u16 ops into separate statements: `v &= 1; r = v << 8; v = rec[0x1A]; v |= r;`.
- Callers may have seen different prototypes than the headers: sub_080F3040 used as u32 (header u16); sub_081268E4 used unnarrowed (header u8; maybe implicit decl).

## Round 2 (nm_3 list, second agent)
- Read a global twice instead of caching it in a local (`p = g >> 4; ... (g & 0xF)`): CSE merges the loads but the register allocation changes.
- Reuse one local for two unrelated values (race, then `id & 0xFF`) to share a callee-saved reg.
- An invariant test (`mask & 0x8000`) written INSIDE a loop: loop.c hoists it, giving `adds r1, r0, #0; adds r0, r5, #0; ands r0, r1` before the loop.
- `x &= C` on a global (no cached local) fixes "ands result lands in the constant's register".
- Constant base address loaded first: `extern u8 gUnk_X[]; u32 dest = (u32)gUnk_X; dest += off;`.
- Store-flag (`movs rX,#2; cmp; beq; movs rX,#1`) vs branch with pool between: duplicate the call per branch (`if (c) f(1) else f(2)`), cross-jumping merges the tails.
- `t = tbl[i]; if (t != 0) r = 1; ...` where target stores in each branch: `if (r) task->result = 1; else task->result = 0;` stopped a store-address fold.
- Plain `while (n && x != y) { ...; n--; }` instead of `if (..) do {} while(..)`.
- `goto` layout for shared `return 0/1` blocks (fail label inside an if-block).
- Compare operand order: load the left side into a temp first (`kind = rec[0x1E]; if (kind == k)`).
- Out-of-line "found" blocks / blocks moved after a loop: not reproduced (needs loop.c's block move; nested loop inside the block blocks it?).
- scratchpad/perm.py: brute-force declaration-order permutations (slow: ~3 s per variant).

## More from group 2, round 3
- SOLVED "ands result in the constant's register": `m = CONST; m &= x; if (m)`. With a u16 call result: `st = f(who) << 16; m = CONST << 16; m &= st;`.
- Constant register order follows source order: put the `= 1` store first to swap r2/r3.
- Split DmaSet3Wait: `DmaSet(3, ...)` then a wait loop with a fresh `vu32 *` pointer.
- Late invariant load: guarded do/while with the base pointer set inside the guard; `*(T *)(i + (u32)base)` sets add order.
- `u32 x = (u16)expr` instead of `u16 x = expr` avoids a second callee-saved copy.
- `(type & 0xF0) >> 4` keeps an early u8 param narrowing that `type >> 4` loses.
- K&R parameter declared s16 instead of u16 fixed narrowing order.
- `Random_Byte() % n` with u16 result and s16 n is a 16-bit mod; cast `(u32 (*)(void))Random_Byte` to avoid.
- Helper scripts may convert LF to CRLF; keep files' original line endings and never produce \r\r\n.
- Unsolved: runtime sign-extension of 0xFFCE (080D73EC/080D6EA0); separate word-zero and byte-zero registers (080DF2E8, 080E9044, 080DD278); gcc merging duplicated call tails (080F0C18, 08131400).

## Round 4 (r4_3 list)
- 0815A30C matched from 363 diffs: `a > b || (a == b && c < d)` -> `if (a > b) SWAP else if (a == b && c < d) SWAP` (body written twice; a macro is fine).
- `u16 n; n++` gave `adds/lsls/lsrs`; `s16 n` gave the original `lsls #16; add 0x10000; lsrs`. Also `s16 lv` for a spilled loop counter.
- `(s16)(q) + n` lost the sign extension of q: use a block-scoped `s16 q = expr / 3; lv = q + n;`.
- Loop with test at the top and no rotation: `loop: if (f(x) >= 0) return g(); x++; goto loop;`.
- Nested `if (ok) { ... }` -> early `return Fallback();` per failure: cross-jumping shares one call block, and stopped address hoisting across the compare.
- Index register r2 vs r1: reuse the swap temporary (made u32) as the table index (`h = a*12 + b; col = tbl[h];`) — the multi-block pseudo goes to r2.
- Call result compared with a global loaded after the narrowing: block-scoped `{ u8 level = f(); if (level >= g) continue; }`.

## Round 4 (r4_2 list)
- `s16 y = 0x120 - pos; Sprite_Draw(..., y);` (u16 param) computes y before the pointer/stack args AND keeps a non-imm8 constant in its own register (`movs r0,#0x90; lsls; adds r1,r0,#0; subs r1,r1,r4`). s32 y folds the constant into r1; inline arg computes y after the stack stores. (080D74D8)
- Read two bytes as `u8 hi = p[0xC]; u8 lo = p[0xD]; pos = (hi << 8) | lo;` for `ldrb r1; adds r0,#1; ldrb r0`; write back with `hi = pos >> 8; p = &raw[0xC]; *p++ = hi; *p = pos;`.
- List input handlers (vision/dict/casino, 080DAC70 080DC460 080DBF7C 080D38D0): page-up block is `u32 cursor = d->cursor; u16 top = d->unk02; u16 t = cursor; if (t != 0) d->cursor = down; else if (top > 4) d->unk02 = top - 5; else d->unk02 = t;`; page-down tests `if (d->cursor != 5)` (memory, not the local) and then `cursor + top + 6 < count - 1` with the locals (stops constant-folding cursor==5). `u32 zero = 0; task->result = zero; task->unk1E = zero;` materialises the 0 before the gMenuState stores. `rows = count; if (count > 5) rows = 6;` (not if/else).
- List draw functions (080DADF8, 080DC2B0): index the id list through the constant address `((u16 *)0x0203B454)[d->unk02 + row]`; reuse the row counter for the following count loop; flag tests (`v & 0x8000`) written inside the glyph loop so loop.c hoists them after the giv setup.
- Byte-offset structs -> real struct types: `struct EnemyUnit`/`struct EnemyRecord` with array fields fixed the |= 0xFF loop (ldrb/orrs/strb kept; through a u8 * gcc folded it to a store), and `rec->skills[i]` gives the hoisted `rec + 0x11` base (080F0200). Then swap loop-var roles (`for (j = 0, i = 0; i < 7; j++, i++) u->skills[j] = rec->skills[i];`).
- Variable reuse decides callee-saved assignment: one variable `r` for the call result, the crit threshold and the damage cut; `k` reused for the second Random_Byte and `power - cut` (080EE6BC: 48 -> 3 insns; remaining: s32 r vs power priority).
- `*(u32 *)(gs + off)` with `u8 *gs = gGameState; u32 off = 0x18B0;` keeps base+offset unfolded (load base, add, ldr) instead of a folded pool constant.
- h.py: "DD_NDIFF" is only printed by the DIFF branch; build/r4b/h.py now always prints it ("DD_NDIFF 0 EQUAL" on a match) — older loops that grepped DD_NDIFF printed nothing for OK *and* for compile failures.
- 081540B8: switch on `(u8)f()` gave lsls/lsrs; original was `movs r1,#0xff; ands r1,r0` + signed compare tree: `s32 k = f(); s32 kind = 0xFF; kind &= k; switch (kind)`.
- 0815B4B4: an `||` chain of `&&` triples: put the term that is `== X` first in each triple (`(a1 == B && a2 != B && a0 != B)`) to reproduce the original test order / jump threading.
- WARNING for helpers: nmb/nm4 `mk` resets the whole scratch copy; if you mk several functions of one file, `try` must set the target block to `#if 1` itself (scratchpad nm4.py does), or the NAKED copy "matches".
- 0815B11C: a short-lived call result in r2 instead of r0: reuse an existing variable (lv, made u16) that lives in r2 elsewhere, instead of a block-scoped temp.
- Constant call args written as `x + 0x25, y + 0x5A` (x, y u16 locals = 0x5C, 0x10) instead of folded `0x81, 0x6A` change register-arg load order (r1, r2, r3, then r0): fixed the last 2 insns of 080DBCDC.
- Pointer variables reused for a later call: `dst = pal; src = palDst;` after the loop, with pal/palDst declared in a block *before* the loop (their loads land before the loop in r2/r3) and `i = 0;` before that block (08126E4C). Index globals by extern array (`extern u16 gUnk_03001AB4[]`) rather than a cast constant when the original adds an offset register to the base.
- A value compared `== 1` is CSE'd into later `= 1` stores (keeping the call result in a callee-saved reg); assign it to a local that is reassigned before the store (`r = BattleMsg_IsDone(); if (r != 1) break; ... r = BCMD->unk0;`) to stop it (0812C2E4, 20 -> 3).
- Header discrepancy seen: bmenu2_a's sub_0812C2E4 passes BCMD->who to sub_0812E780 unnarrowed (ldrsh, no lsl/lsr) though bmenu2.h declares `u16 who`; cast the callee (`((void (*)(s32, u16 *, const u16 *, u8))sub_0812E780)`). sub_080F030C (battle.h: u16, u16) is called with unnarrowed args in 080EF580.
- Unsolved this round: pure callee-saved permutations (080EE6BC r/power, 080EE9F8 act/skill/k, 080E2148 i/id, 080DBA1C d vs the CSE'd constant 1), 080DABCC's `cmp r5, ip` loop bound (46 kept in a register), 08129F5C's unrotated while loop with a per-iteration reload, 0812E558's while loop whose first test is duplicated with a second load.
- Fusion swap preludes (0815999C matched, 08159A60 close): plain `if (c->race[0] == 8) {swap} else if (c->race[1] == 8) {swap}` (cross-jumping rebuilds the shared race-swap tail), and a SECOND pointer `w = &gUnk_0203B868;` for the code after the join. That gives the original `ldr r0,=sym; adds r5,r0,#0x96; ...; adds r7,r0,#0` start and `mov r8, r7` at the join.
- 08158D20: `c->result = *(u8 *)&c->result` -> `c->result &= 0xFF` keeps the 0xFF constant in a callee-saved reg for later `= 0xFF` stores; goto-shared fail tail -> duplicated `unkA6 = 0x40; return 0;` per path (matched).

## Round 4 (r4_1 list)
- Loop entry test NOT folded (`movs r5,#0; cmp r5,#5; bhs` at loop entry, `cmp #5; blo` at the bottom instead of `cmp #4; bls`): the bound was a variable initialised at the top of the function (`u16 h = 5, w = 3; for (row = 0; row < h; row++)`). CSE cannot fold it, gcse-cprop later puts the literal back. Matched 080C54D4.
- Params reused as locals: if a param's register gets overwritten with 0 mid-function (`movs r2,#0; mov r8,r2` where r8 held x), the original reused the param (`x = 0; y = 0;` then `y += *dir`). Matched 080C6BE0 (with the next trick).
- Pass the literal (`0`) when the value is known from a preceding test (`if (c->maxMp != 0) ... else f(..., 0, ...)`): CSE substitutes the register holding the tested value, like the original. A reload of the field (`ldrh r1,[r2,#0x1e]`) instead means you passed the field.
- `&arr[5 + dy][4]; cell = &cell[dx];` keeps the constant offsets folded into the pool base while the row/col adds accumulate in one register (080B0248).
- Struct table `.y` via separate base+2 register: `(&tbl[0].y)[i * 2]` (080C87AC, 080C6BE0) — confirmed again.
- `x / 4 & 3` instead of `(x >> 2) & 3` for a u16 local whose address is taken (written by a callee) and that is used twice: avoids the redundant `lsls #16; lsrs #18` re-extension (080B968C).
- Field_HandleInput (080B1C18): the u16 param is re-read from the stack at every test → declare it `vu16 keys` (18 lines left, from 110).
- Font_GetGlyphBitmap: `for (i = 0, buf = dst; ...)` gives the loop-preheader copy of the initial pointer; `return dst - 0x440` (11 left).
- Readable-C bugs seen: missing braces around `list[n] = i; n++;` (Status_BuildList), whole loops shaped differently (BlitTiles: dir tested outside the row loops, mirror loop unrolled 8x with `*d++` and `d -= 16`).
- Division `(s16)x / 8` keeps the source and the temp in different registers (`asrs r1; adds r0,r1,#0; cmp r1,#0; bge; adds r0,r1,#7`) when the operand is a variable shared across branches (`s32 cut, t;` at function scope), the tied form when it is a temporary.
- Hud_DrawGauge (080C8214, 67 -> 24): `s32 full = 46;` at the top gives `movs r0,#0x2e; subs r0,#7` / `movs r1,#0x2e; subs r0,r0,r1`; the loop bound held in a register (`movs r7,#4` before the loop, `cmp r1,r7; blt`) came closest with `u8 n = 4` (u16/s32/s16 n worse).
- Copy loops that cross-jump into one in your build but are separate in the original (080C8E64): compute the second source at run time (`buf = gPaletteBuffer; buf += 0xD1;`) so the two copies get different registers (137 -> 1).
- hudslide_a's six panel sliders: the original keeps `col = 0` in a register (`add r0, sl` in the source index); not reproduced — CSE folds it in ours. Unsolved.
- Use build/r4a/h.py (mk/get/put/run/nm/win, preserves CRLF/LF) and var.py (batch literal-replacement variants) for this workflow.
- Generalised: in the fusioncalc files a `ldr rX,=gUnk_0203B868` reload (or `mov r8, r7` copy) right after a join point means the code after the join used a fresh `w = &gUnk_0203B868;` pointer. 08158FA4 matched just by switching to `w->` after the if/else chain; 08159568 went 4 -> 2.
- Variable reuse is common in this code base: the original reuses dead locals (0815915C: `a = x * 3`, the table index in the loop counter `k`, the random id in `x`; 0815B11C: `lv` for the id). When a short-lived value sits in the register of a variable that is dead at that point, try assigning it to that variable.
- `m = 3; m &= v; if (m)` (separate test variable) stops CSE from reusing the test's `v & 3` for a later `v &= 3` (081592AC).
- sub_0815B958 is declared u16 in fusion.h but the original callers use the full int (no zero-extension): cast `((u32 (*)(u16))sub_0815B958)` or assign to s32/u32 first.
- Helper scratchpad/ft.sh <stem> <ADDR> <size> <bodyfile> [n]: inserts the body (forces `#if 1`), compiles, prints status + difflib diff (fd.py, aligned, ignores branch targets). prep.sh <src> <ADDR> <size> makes w/<ADDR>_0.c, w/<ADDR>.s, w/<ADDR>_fd0.txt. setnm4.py <src> <ADDR> <body> replaces just the NONMATCHING branch in place.

## Round 5 (r4_1 list, r5a)
- GNU hard-register locals fix pure register swaps: `register struct Task *task asm("r5") = task_;` (080B85F8), `register vu16 *p asm("r2") = &tmp;` inside a hand-expanded DmaFill16 (080C6334), `{ register u32 one asm("r0") = 1; x->f = one; }` to stop CSE storing the variable known to be 1 (080B43C0). Also blocks gcse const-prop: `register u16 *dst asm("r4") = (u16 *)(PLTT + 0x1A2);` kept `adds r4,#2` instead of a pool load in the jump-target branch (080C8E64). Pinning a u16 *param copy* tends to move its lsl/lsr narrowing and fail (080CD260/080CD668).
- RTL dumps: build/r5a/dump.sh STEM (agbcc -da into build/r5a/dump_STEM/) — x.c.gcse shows CONST-PROP lines; reload_cse turns `reg = const` into `adds reg,#k` only within one basic block (fallthrough), so a label-start block keeps the pool load.
- Block-scoped copy per branch (`u16 n = floor->floor; n = -n;` inside the if) gave the in-place `rsbs r4,r4,#0` (080B9A4C).
- Call args loaded r0-first (`movs r0,#0xc; adds r1,r4,#0`) instead of r1-first: the caller saw word-sized params; cast `((void (*)(u32, u32, u32))f)(...)` (080B8174). And merged call tails (`b` to one shared `bl`) came from the trailing store duplicated into each branch (`f(..); fs->unk46 = 1;` in both) so cross-jumping had 2+ insns to merge.
- `u16 move` (not s16) when the value is passed to a u16 param with no narrowing and stored -1 as 0xFFFF (080B1C18). A fresh reload of a field after a test on it = the first read was volatile: `((volatile struct T *)&gX)->f & 1`.
- agbcc ICE "stor-layout.c:203" in fieldframe_a NONMATCHING: a local `extern u16 gPaletteTarget[];` after the header's `[0x200]`; delete the redundant extern. Check with build/r5a/nmc.sh SRC (compiles with -DNONMATCHING).
- build/r5a/pd.py STEM ADDR show: positional diff (difflib in dd.py inflates counts on repetitive code).

## Round 5 (r4_2 list, r5b)
- SOLVED "gcc cross-jumps identical call tails the original kept apart": give each branch its own tail instead of one shared one. 08131400: `Sound_Play(100);` written in every arrow-key branch (no `goto`/shared tail) -> exact. 080F0C18: an explicit `return 0;` at the end of the first if-block (whose last call `f(w, 9)` was merged into a later identical `f(.., 9)`). 080D1828: `{ x--; moved = TRUE; } else { x = 3; moved = TRUE; }` instead of a common `moved = TRUE;` after the if/else (stopped the strh being shared).
- SOLVED "ands result in the constant's register" after a call (`movs r1,#C; ands r0,r1` wanted): assign the masked value to a *narrow user variable* in its declaration: `u16 ret = f() & 0xFF; return ret;` (080D229C), `u16 v = rand() & 0xFF; ... (u32)v % 0xC0` (080EF434), `u8 bit = ((u32 (*)(void))Random_Byte)() & 1; if (!bit)` (080DDE2C). `u32 v = f() & 0xFF`, `(u8)f()`, `v &= 0xFF`, `m = 0xFF; m &= v` all keep the wrong tie (or give lsls/lsrs). A `u8` destination with 0xFF becomes a zero-extend (shifts); use u16 for 0xFF, u8 is fine for & 1.
- Random_Byte cast to u32 (`((u32 (*)(void))Random_Byte)()`) in extras.h files (header says u16) fixed the and-tie of `& 0x1F` in 080DDE2C; with `u8 j = (... & 0x1F) + 1` it kept the original allocation.
- Keep a key-mask as a variable and store it as the zero: `s16 left = gRepeatedKeys & 0x20; if (left) ... else if (...) { menu->unk0A = left; }` (080D1828; u16/u32/u8 `left` were CSE'd to the constant 0, s16 kept `lsls/lsrs r2` and `strh r2`).
- Store/zero ordering: `dst = &gUnk_X; v = data[0]; zero = 0; *dst = v; f(0, ..., zero, zero);` reproduced `ldr r1,=g; ldrh r0; movs r2,#0; strh r0,[r1]` with the stack-arg zero in r2 (080D4954).
- Unsolved this round: 0812C2E4's reload of BCMD for `unk0` (one pool entry, so not a second symbol; BCMD_ABS gives a second pool word; a function-scope `cmd` pointer goes to r8); 080EE6BC `(rand & 0x1F) * power` into a temp makes power win r4 over r (decl perms, splitting r/threshold/dmg did not help); 080E2148 now 18 with a separate demon-loop counter and `*(u16 *)((u32)dm + (k << 1))` (gets `adds r0, r7, r0` order) but k/id still swapped; 080DBA1C (d vs CSE'd 1) unchanged; 080F2C9C `ldrh + lsls/asrs` (any (s16) of a u16 array element becomes ldrsh, also with s16 return type); 080E54F0 param copied to r2 (K&R, u32, extra param all no); 080F104C base-first via `const u8 *tbl = ...; &tbl[b + a * 4]` (8 -> 7) but a/p registers differ; 080F46E0 colour unpack (c in r0 not r1).
- Unsolved, with findings:
  - hudslide_a Hud_SlidePartyPanel (080C7070): it's `row` (=0) that stays live, as `movs r1,#0; lsls r0,r1,#5; add r0,r8` = gcse cprop wrote 0 into the *copy* `r54 = row` (RTL copies row before the shift) but CSE did not fold, so CSE must not know row=0 there; ours folds because cse-skip-blocks carries row=0 past the `if (x < *step)` block. The original also computes `w -= step-1` before narrowing col, loads the table pointer before the `cx` clamp (`src = table; cx = x; src += row*32+col;` gets that order), and stores `*state = 3` with a fresh `movs r0,#3` (ours reuses h). Tried s32/u8/s16 row, `row = 0` in the if-body or per branch: no change.
  - Font_GetGlyphBitmap (080ABF24): the original return `ldr r0,=gGlyphBitmap+0x400; ldr r1,=-0x400; adds` is loop.c's biv final value (init const sym+0x400, +0x40, -0x440), so loop 2's dst must start from the constant `gGlyphBitmap + 0x400` in RTL; written that way, loop.c hoists the constant load (reg 273 = LC2) before loop 1 into sl. Not solved.
  - Hud_DrawGauge (080C8214): the loop bound is an int 4 in r7 loaded right before the loop with an unfolded entry test `cmp r1,r7; bge` (i u16, signed compare); s32 n folds to `cmp #4`, u8/s16 n make loop.c compare i<<16. Also `tile = fill + 7 - full` with a fresh `movs r1,#0x2e`.
  - 080CD260 / 080CD668 / 080CD6C4: callee-saved swaps between u16 params / x+24; pinning a copy with asm("rN") gets the registers but moves the param narrowing or the arg-load order.

## Round 6 (r4_1 large functions, r6a)
- Address arithmetic in a dereference is expanded with EXPAND_SUM: `* 0x20` terms stay MULT rtx and their shifts are emitted late (just before the adds), while `<< 5` terms are computed at once and the adds come afterwards, left to right. Original `lsls #5` right after the index computation + all adds at the end => write the deref'd address with shifts: `*(src + ((y >> 3) << 10) + ((x >> 3) << 5) + ((y & 7) << 2) + ((x & 7) >> 1))`. An address assigned to a pointer variable first (`p = dst + ... * 0x20 ...`) is expanded normally (adds interleaved). FieldView_BlitPixels 080B210C matched (144 -> 0).
- Two increments of the same u16 (`sx++; ... sx++;`) that the original kept as two separate `adds/lsls/lsrs` while ours combined them (`add 0x10000`): the first increment was inside each if/else branch (cross-jumping later merged the branch tails into one copy), so combine saw them in different basic blocks. Write `sx++; col++;` at the end of both branches, then `sx++; dx += dir; col++;` after the join.
- Helpers: build/r6a/var.py (variants, now replaces ALL occurrences, prints DIFFLINES + POSDIFF), build/r6a/sbs.py STEM ADDR [from] [n] (full side-by-side positional listing), build/r6a/t.sh STEM ADDR BODY.

## Round 6 (r4_2 list, large functions, r6b)
- 08130694 Shop_ListInput matched from 408 (rewrite following the asm). How cross-jumping really works here (agbcc gcc/jump.c, jump2 only): for `jump L` gcc first compares the insns before the jump with the insns falling into L; that NEVER works when the fall-through code ends in a call, because flow.c inserts a `(use (const_int 0))` nop after a call that ends a basic block (call followed by a label). Then it tries the other jumps to L in reverse insn order (the LAST jump to L first) and takes the first one with >= 2 matching insns (not the longest). So redraw copies merge into the last *jumping* copy, not into the fall-through one.
- To make a copy merge into the fall-through copy instead (original had the "last case" of each key branch sharing the tail of the final branch): end that copy with a call followed by a label at flow time, so it also gets the USE nop: write the case as the last `else if (...) { ...; Sound_Play(100); }` of the inner chain (its skip test jumps to the end label) and put a dead store right after the inner if (`keys = 0;`, keys used elsewhere so cse does not delete it). The dead store stops early jump passes from threading the skip jump past the label; flow deletes it after inserting the nop; jump2 threads, deletes the label, and the block ends [call][USE][jump] which matches the [call][USE] before the fall-through label. Removing the dead store or the variable (trivially dead) loses it.
- Shared list tail: `... else goto other; list: <tail>; return; other: <A/B handling>` puts the tail between the arrow-key branches and the A/B code, with `goto list` from the non-last cases.
- `if ((u16)(gNewKeys & 4))` keeps the lsls/lsrs narrowing of the mask without a variable; with `keys = ...` the known-zero mask register was CSE'd into later `= 0` stores (TOP = 0 used r2 instead of the original r1).
- `*(s16 *)&g != 0` + `(*(s16 *)&g)--` reproduces `ldrh r2; ldrsh r0; cmp; subs r0,r2,#1`.
- `u16 row = ROW;` at the top of a branch (original `ldrh r4` before the `ldrsh; cmp #2`) and `ROW = row + 1`; plus `if (a && b) X else Y` -> `if (!c1) { if (c2) Y else X } else X` (each X in a single-predecessor block, cse reuses the early load; cross-jumping merges the X copies).
- `u16 *slots = gUnk_03006620;` in a block before the gUnk_03006920 stores: the original loads 0x03006620 first (`ldr r1,=6620; ldr r0,=6920; strh.. [r0]; adds r0,r1,#0; adds r0,#0x40`).
- Prototype: sub_080D34A4 is `(u32, u16 mode, u16 member, u16 id)` (menu2_a.c); msgwin_* files declared `s16 b`, which gave ldrsh of gUnk_03006898 instead of ldrh.
- RTL: build/r6b/dump.sh STEM (agbcc -da of build/r6b/STEM.c) + scratchpad/rtlsum.py x.c.greg|x.c.jump2 FUNC prints labels/jumps/calls, enough to see which copies cross-jumped where.

## Round 5 (r4_3 list, third pass)
- Merge two pointer locals that the original keeps in ONE register: 0815C380 (staff roll, 190 -> 0) had `obj` (sprite data) and `line` (text line) in separate variables -> whole-function r5/r6 swap. One variable for both (`line = (const void *)&s->obj->data;` then `((struct StaffRollObj *)line)->x`) matched. If a callee-saved reg holds variable A early and variable B later in the original, try making A and B the same C variable.
- A u16 value passed as a u16 argument: holding it in a `u32` local (`u32 d = c->ids[1]`) instead of `u16` made gcc load the arg into r0 before computing the second arg (`adds r0,r3,#0; movs r1,#3; ands r4,r1`) — 081592AC matched.
- `want = tbl[k] & 3;` instead of `want = 3; want &= tbl[k];` (0815915C matched): the `x = 3; x &= y` trick is not always right — when the original copies a callee-saved reg already holding 3 (`mov r8, r6`), the plain expression lets CSE reuse it.
- Store of a table byte into a struct field, value loaded in r1 vs r0 (08158E78): rewrite `if (ok) { c->result = t[x]; r = f(); } else { fail; r = 0; } return r;` as early `if (bad) { fail; return 0; } c->result = t[x]; return f();` — matched.
- `-d` as a call argument computed before the other argument's load; `d = -d; f(w->ids[0], d);` put the rsbs after (08159A60). Also `s16 va, vb` (not u16) for `if (va == 0) va--;` keeps the runtime `subs; lsls; lsrs` instead of a folded 0xFFFF constant.
- Loop-invariant hoist order (0814CD10): a block-scoped temp for the index load (`{ u8 sym = s->board[row + i].symbol; result |= tbl[sym]; }`) made loop.c hoist the loop bound copy before the table address.
- Two halves of a pair table passed as call args in reverse order (08136D5C, 6 -> 2): `u32 k = b * 2; u16 y = t[k]; f(t[k + 1], y);`.
- `*top += 1 - rows` instead of `*top = *top + 1 - rows` stops CSE reusing `rows - 1` from the preceding compare (08156B74); block-scoped copies (`u8 c1 = *cursor;`) in the second of two identical blocks fixed callee-saved allocation (64 -> 2).
- Script_QueuePartyNames (08133854, 206 -> 87): the original recomputes `idx << 7` at every gGameState[idx] access (no GCSE): write the check as `gGameState[idx = base + slot].unkE` (assignment inside the index) with `u16 idx`.
- Not solved: 0815B8F8/0815BA28 (found-block after the loop; a do/while with an explicit `if (tbl[0] != 0xFF)` entry test gets BA28 to 9 lines and the `adds r3,r0,#0` copy, but id/tbl swap r3/r4); 08159568 tail (`adds r0,#0xa0` scheduled before the `ldrb`: tried ~20 LHS/RHS forms); 08156B74 prologue (count/rows narrowing order, decl order irrelevant); 08149230 `muls r0,r1,r0` vs `muls r1,r0,r1`; 0815A6F0 r5/r6 swap of two CSE address temps (&nA, &inherit).
- Scratchpad r5/: nm4.py/fd.py/ft.sh/prep.sh copies using build/r5c, runv.sh (run several variant bodies), ours.py (print our disassembly of a function), survey.py (difflib-based diff counts for a tsv list).
- SOLVED "u16 param copied to a second register at entry (`lsrs r4,r0,#16; adds r6,r4,#0`)": cse.c keeps the narrowed incoming pseudo as the canonical register of the class (and substitutes it for the param variable) when the variable's last use lies inside the first extended basic block. Move the shared `return color;` to the very END of the function (mode-1 block falls through to it, the other branch returns its own value earlier) so the variable's last use is past the block: copy gone, all "return color" paths share one `adds r0,r4,#0` block (Color_ApplyEffect 080ACC54: 236 -> 181).
- `(x >> 16) << 5` stored to u16 keeps the original `lsrs #16; lsls #21; lsrs #16` only when gcc cannot bound x: hold the unnarrowed division result in a u32 and narrow later (`x = (g << 16) * d / 0x1F00; x = ((u16)x << 8) + 0x8000; d = (x >> 16) << 5;`). Writing it as one expression or with a u16 temp gives `asrs`/no narrowing.
- `if (a + b > LIM) c |= M; else c += b;` compiled with the `|=` out of line in the original -> write the `<=` test first (`if (a + b <= LIM) c += b; else c |= M;`).
- Register priority between two u16 accumulators (dr in sb vs r8) flipped by the number of assignments: `u16 q = expr; dr = (q + 0x80) >> 8;` instead of `dr = expr; dr = (dr + 0x80) >> 8;` (181 -> 109). Readable-C note: `dr += 0x80; dr >>= 8;` is NOT equivalent (u16 wrap).
- 08130D24 MsgWindow_DescListInput 787 -> 27 (rest = register choice only). Same recipe: every branch its own redescribe + Sound_Play(100); `if (!(gUnk_03006844 & 0xF0)) {describe} else {preview}` (asm order: describe falls through, preview after). Readable `gUnk_030068AC = ROW` (Ghidra) was really `= 3`: CSE puts the register known to hold 3 (the ldrsh compared with 3) into a constant store; `= ROW` stores the ldrh value instead.
- A split store tail (`subs r0,r2,#4; b L; movs r0,#0; L: strh`) is a plain `if (..) TOP -= 4; else TOP = 0;`: jump2 cross-jumps the two strh (fall-through match needs only 1 insn). A ternary gives a different shape. A reload of a global after such a join = the join ended cse's extended block (not an alias problem).
- `if (x) {..} else { if (y) TOP -= 3; else TOP = 0; }` after `if (ROW != 0)`: CSE stores the ROW register (known 0) for `TOP = 0`; `{ register u32 zero asm("r0") = 0; TOP = zero; }` gives the original fresh `movs r0,#0` (69 -> 27 in 08130D24). Unsolved: original keeps the `ROW = 0` zero in r2 (hard r2 breaks the index folding).
- Loop pointer initialised AFTER the hoisted invariants (`movs r5,#0; mov r8,r5; adds r0,r7,#0xb; lsls r6..; mov r4,sb` = counter, invariant, then pointer): the pointer is a loop.c giv, i.e. the source indexed `&state->party[k]` inside `for (k = 0; k < 4; k++)`, not `member = state->party; ...; member++`. Fixed a pure callee-saved swap in 080D0498 (matched).
- Variable reuse for a call argument: `phase = gTable[i]; Flag_Set(phase);` (ldrh into r1 then `adds r0,r1,#0`) with `u32 i = g.idx;` loaded first (080C1B74 matched).
- A global struct whose address the original reloads from the pool before EVERY access (even right after a previous access, across a call) while ours CSEs it into a callee-saved reg: access it through a function-scope pointer `struct T *m = &gX;` declared first. The pointer lives across the whole function, gets no hard reg, and reload rematerialises the constant at each use (080CB928 matched, with a separate `u8 s0` for the first loop's skill id so it stays in r0).
- if/else storing to the same global where the then-branch computes the value first and the else-branch loads the global's address first (then cross-jumping shares only `str r1,[r0]`): then-branch `pal = v->p; pal += 0x40; gX = pal;` with `pal` at function scope (load and add in the same register), else-branch `gX = v->p;` directly (080ADCCC matched).
- u8 locals for bytes read from a big struct (`u16/u8 x = gGameState.unk18C2`) instead of u32 kept the original's unfolded `ldr base; ldr =0x18C2; adds; ldrb` and dropped the narrowing before a u16 call arg (080B30A0: 34 -> 8, rest is a callee-saved swap).
- 0812F54C MsgWindow_ItemListInput (0xC0C bytes) matched from 1368: rewrite per asm block, each case with its own `MsgWindow_DrawItemList(gUnk_03006844); { Sound_Play(100); goto done; }` (NOT `goto sound`): cross-jumping then merges every copy into the LAST jumping copy (only the call when the `mov rX, ip` reload register differs, the whole tail when it is the same) = the original's `bl .L08130136` / `bl .L08130132` pattern. `goto sound` merged far too much (580 -> 170 with the change).
- Layout trick for the same function: the code after the last redraw copy was B's `else` store, i.e. the source ended `shiftN: ...; Sound_Play(100); goto done; cancel: gScriptWaitState = 0x1C; done: sub_0812F010();` with B written `if (ws != 0x18) goto cancel; ws = 0x37;`. That makes the last redraw copy the last *jump* to done (the chain head) and gives the shared strh before done.
- MODE as `(*(s16 *)&gUnk_03006844)` (ldrsh) instead of `((s16)gUnk_03006844)` (gcc compares the u16 load): 580 -> 382.
- A loop the original did not loop-optimise (constant 0xFFFF reloaded each iteration, no hoisting) = written with goto, not do/while (`scan: k += 2; if (k > 7) goto out; if (LIST[..] != END) goto scan;`): 170 -> 72. The for-loop next to it (0xFFFF hoisted into r8) was a real loop.
- `LIST[TOP + ROW + 2] ... LIST[TOP + ROW + 1]` (CSE shares TOP + ROW) instead of `s32 n = TOP + ROW; LIST[n + 2]`: the table base is loaded before the sum (last 25 lines).

## Round 6 (r4_3 list, r6c)
- Table symbol loaded BEFORE the index is computed (`ldr r2,=tbl; lsls r0,r1,#1; ...`): put the index assignment inside the subscript, `y = tbl[k = b * 2]; f(tbl[k + 1], y);` (08136D5C matched; `u32 k = b*2; y = tbl[k]` computes k first).
- Store whose destination address (`base + 0xA0`, too big for a strh offset) is computed before the value is loaded: take the source element pointer first, then the destination pointer, then copy: `u8 *p = &g.cand[i]; u16 *r = &g.result; *r = *p; return *(s16 *)r;` (08159568). If `&sCalc.result` folds into a new pool constant (`sym+0xA0`) and wrecks the allocation, go through a fresh struct pointer `w = &sCalc; u16 *res = &w->result;` and keep a table index in an `s32 j = k - 0x32;` so `-0x32` is not folded into the symbol (08159BFC).
- Multiply result in the constant's register (`movs r0,#0xb; muls r0,r1,r0`): the destination was u16 (`u16 y = (c / 8) * 11 + 0x27`), u32 y gives `muls r1,r0,r1` (08149230).
- An extra `adds rX, rY, #0` copy of a value that is later AND-ed in place for a call argument: modify the variable itself (`status &= tbl[i]; f(who, status | bits);`) and write the test as `status & bits` (0813B350).
- `if (x & 2) return 1; return 2;` with the original `movs r0,#2; ands r0,r1; bne`: `u32 m = 2; m &= flags; if (m) return 1;` plus `default: return 3;` inside the switch instead of after it (08158030).
- Pointer + index add order `adds r0, r1(ptr), r0(idx)` instead of `adds r0, r0, r1`: `*(u16 *)((u32)strip + (q << 1))` (08144FF0, 4 -> 3).
- Chained zero stores: the chain order changes which hoisted address gets which callee-saved reg; `a = b = c = 0` in the original store order got 081343AC from 6 to 2 (remaining: r4/r7 swap).
- Pins used this round (3): 0813DA14 `register u32 m asm("r1") = c;` (combine folds `m = c; m &= f` into f's r0 otherwise), 081562EC `register struct Task *task asm("r2")` (task stays in r0, 0 in r1), 0813DD64 `register u16 v asm("r5")` (v/task callee-saved swap).
- Not solved: 0815BA28 (pinning id to r4 leaves 3: the loop has two pseudos for the table address, the loop-top one copied `adds r1,r4,#0`); 08156B74 (count's lsrs emitted after rows'); 081337B4 (original compares the HImode reload of gMsgGlyphCount CSE'd to `zero_extend(subreg c)`, i.e. lsls/lsrs of c, ours reloads); 0813E854 (combine moves the index computation after the gGameState load); 081491BC / 081437E4 (reload-register choices: constants built in r3 then copied, ip copied into r2 vs r0).

## Round 7 (r4_1 list, r7a)
- Callee-saved swaps are global.c priority = floor_log2(refs)*refs/live_length*10000 (refs weighted by loop depth, ties -> lower pseudo number first). build/r7a/pr.sh ADDR FUNC (after `h7.py try`) dumps RTL and prints each global pseudo's priority and hard reg. Fix by changing live length: extra RTL insns (that later passes delete) in a block where the loser is dead but the winner live. 080B30A0 matched: `u16 t = x; t -= map->x0; unk12 = t; t = y; t -= map->y0; unk14 = t;` in the success block (count dead there, palette pointer live) lengthened the palette pointer 81 -> 85 insns, flipping sb/sl.
- The param copy `d = dst` placed after a call makes the param pseudo block-local and local-alloc gives it r4 first (080C7EB4: not solved, d needs live <= 22).
- FieldView_BlitTiles 080B23D0 (174 -> 16): (1) per-loop block-scoped `s`/`d` pointers (two loops sharing function-scope pointers forced the same regs); (2) row bases into separate temps `sp = src + ...; dp = dst + ...; s = (u32 *)(sp + srcOff); d = ...` (original adds into r0 temp first, final add later); (3) registers in two clip branches follow which *variable* holds which role: reuse the same function-scope variables across branches in the original's role pattern (quotient/product/s16-holder). Division `(s32)v / 8` keeps the untied form only when the holder is a global pseudo that can't get r0.
- build/r7a/: one.py/m1.sh (measure one function in isolation: enable only its #ifdef), sd2.py (difflib exact + register-normalized), h7.py get/try/apply/final, v7.py (variants), pr.sh/prio.py (priorities).

## Round 8 (list 3)
- "Found block after the loop" (0815B8F8, 0815BA28, unsolved since r5): the scan loops were not loop-optimised in the original. Write them as goto loops (`if (tbl[0] != 0xFF) { loop: if (id == tbl[i]) goto found; i += 2; if (tbl[i] != 0xFF) goto loop; }`) with the found code after the loop's own return. For 0815B8F8 the not-found code came after the found code: `goto other; found: ... goto one; zero: return 0; other: if (a != 0) goto one; if (!f(id)) goto zero; one: return 1;`.
- SkillList_SortAscending/Descending (0815AAC8/0815AB38): `list + i` recomputed in every inner iteration = goto loops for both levels (outer and inner); the descending variant has the duplicate-removal block after the final `return` (`goto dup`), the ascending one inline.
- Table indexed with the index computed before the base load (`lsls r0,r4,#2; ldr r3,=tbl; adds r1,r0,r3`): index through the constant address, `((u32 *)0x0203BD74)[i]`, in EVERY access of that table (else the symbol and the constant get two pool slots). 08134250 matched with that for gShopItemPrices and gUnk_03006620.
- 081343AC (r4/r7 swap of hoisted addresses, unsolved r6/r7): `a = b = c = 0` -> separate `a = 0; b = 0; c = 0;` in the original store order.
- BLDALPHA/BLDY mirrors set from constants: the original's `ldr r0,=0x808; strh` without the usual `ldr r2,=C; adds r0,r2,#0` copy, and a fresh/preloaded `movs #0x10`, came from expressions that CSE folds late: Keno_Init `gUnk_03000042 = (s->unk19A << 8) | s->unk198; gUnk_03000044 = s->unk19C;` (the fields were just stored), 08157534 `u16 y = 0x10; ... gUnk_03000042 = ((y / 2) << 8) | (y / 2); gUnk_03000044 = y;`.
- A zero stored before a call, and another 0 stored after it with a fresh `movs r0,#0` (ours kept the first zero in a callee-saved reg): route the first zero through a variable that the call result overwrites (`n = 0; task->result = n; n = f();`), 081454F4.
- Loop-invariant hoist order (table, then the constant y arg in r8): assign the constant inside the loop after the table element load (`g = tbl[d[i]]; y = 0x4A; Sprite_Draw(g, ..., y);`); `{ u16 st = 5; g->state = st; }` loads the value before the address (08149334, now 9 register-only diffs).
- 0815201C (52 -> 14, NORM 0): the first tile lookup used its own x/y variables (fx, fy), not the bx/by assigned later.
- 081316FC (shop arrows) findings, not solved: the final `else` copies are `gUnk_03006848 = ROW*2+k; gUnk_03006680 = gUnk_03006848;` (6848 address loaded first, no ROW reload); then the identical `6848 = 0; 6680 = ROW*2+k` copies cross-jump into the strh only, as in the original. What remains is register choice: money r8 / unit r7 / &item r6 in the original vs sb / r8 / r7 (the sell-side &qty pseudos win r5/r6 in ours), and the sell non-step branch reloads qty (`ldrsh r5` after the `> 89` test).

## Round 8 (list 2)
- Check the original's argument registers before tuning: 080F104C kept `b` in r1 up to `bl Battle_GetActionAnim` because the call really is `Battle_GetActionAnim(a, b)` (the file's local prototype had dropped `b`); fixing the call matched it at once (also without the `p` pointer local). Likewise 080D3B58 returns the AND mask register (1) when the bit is clear: the source was `if (bit set) { Flag_Set(f); return 0; } return 1;`, not "return the bit index".
- K&R definition for a u16 parameter that also receives a later u16 result in the same register (`lsrs r1,r0,#16` at entry, call result copied to r1): `u32 f(id) u16 id; { ... id = sub_080C2600(id); if (id <= 0xFE) ... }` (080DD248). A prototype-style `u16 id` + `u32 v` local gives an extra copy.
- `mask = 0xF; c <<= 8; b &= mask; f(c | b, y)` reproduced the original's "constant loaded, then the other operand shifted, then and" order with the and in the variable's register (080EF580).
- Variable reuse across if/else branches: a value that lands in the same register in both branches is one C variable (08130C6C: the row index of the then-branch and `n` of the else-branch). Sum order `v + (-0x120)` first, then the other loads: `s32 t = v - 0x120; t += (u16)g1; n = g2 + t;`.
- Loop whose first test is evaluated before jumping into the middle of the compare (`ldrsb; ldrh; ...; b .Ltest` where `.Ltest` is just `ldrh r0,[r0]; cmp; bne body`): write it with gotos and do the entry loads before the `goto test` (08129F5C, 50 -> 12, structure exact). `p = (u16 *)((idx << 1) + (u32)(list = blk->list))` gives index-then-base order with the base kept for the loop.
- Base+offset kept unfolded inside a loop (`adds r1,r7,#2` each iteration instead of a hoisted `buf+2`): `u32 two = 2; p = (u16 *)((y << 6) + ((u32)buf + two));` (080D98EC).
- In-place `v &= 0xF` on the loaded byte (`ldrb r0; ands r0, rK`) instead of `(v & 0xF)` inside the expression, and `x = 0;` before the row pointer in the outer loop body, fixed the tilemap palette loops (080D988C/080D98EC/080D7D98 down to register-only or near).
- Shared `return 1` block placed before `return 0` at the end: `goto ret1` everywhere and end with `if (r <= v) goto ret0; ret1: return 1; ret0: return 0;` (080EE028).
- `u32 m = 0x3E0; m &= c;` instead of `(c & 0x3E0)` keeps the colour word alive in its own register (080E847C 35 -> 10).
- Pins used this round (3): 080F59F8 `register s32 who asm("r2")`, 080D0EA0 `register struct SaveMenu *menu asm("r6")` (with a block-scoped second gFieldState pointer), 080DEDD8 `register vu16 *reg asm("r1")` (local-alloc put the I/O pointer in r0; non-volatile pointer fixed the regs but folded the last increment).
- Unsolved: 080E8E00 (structure exact with `u32 slot = 0xF; slot &= arg;`, but `off` needs the top callee-saved priority; pinning it disturbs id/slot), 080F46E0 (pinning any of c/b leaves 3-8), 080E2148/080DF388/080DF7B8 (pure callee-saved permutations), 080DD278 (byte/word zero registers: no source variant changed a single instruction), 0812C2E4 (BCMD reload), 08127EAC/0812F2B4/08130D24 (register-level; case 5 of 08127EAC is `str` assigned directly per branch like case 6, but that shifts the global allocation, 76 -> 220).
- build/r8b/: h.py/var.py (as r7b), nth.py (try replacing each single occurrence of a string), tn.sh ADDR FILE (try a body, print DD + exact/normalized counts), nd.py (register-normalized difflib diff with real lines), pr.sh/prio.py (priorities), nmc.sh/fin.sh (match summary + -DNONMATCHING compile), setnm.py.
