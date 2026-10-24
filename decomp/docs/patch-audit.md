# Auditing the translation's binary patches

`python tools/audit_patches.py` runs the English translation's build in memory (the engine's
`build_patcher()` and `tr.pack`; nothing is written), diffs the result against the original
ROM, and checks every changed range that touches code against the recovered program.
The full report goes to `build/patch-audit.txt`.

## Checks

| Code | Meaning |
|---|---|
| `E-MIDINSN` | Rewritten code starts with a lone `bl` suffix, or a new `bl` straddles the end of the rewrite into the next original instruction. |
| `E-REACHMID` / `E-REACHBAD` | In the **patched** ROM, an executable path (traced from the function entry, through hooks and their caves) reaches the second half of a `bl`, or an invalid instruction. |
| `E-CAVE` | A hook's cave does not trace cleanly. |
| `E-ARM` | Thumb-style bytes written into ARM code. |
| `E-BLTARGET` | A new `bl` lands in the middle of an original function. |
| `E-LITKIND` | A repointed literal changes kind: a Thumb function pointer replaced by something that is not a Thumb entry or cave, or a data pointer replaced by a pointer into code. |
| `W-LOSTDEF` | A hook displaced instructions that set a register (or flags) which the original code still reads where the cave resumes, and the cave never writes it. Duplicates of an identical earlier instruction are not counted. |
| `W-CAVEEXIT` | A cave jumps somewhere outside the function it was called from (trampolines into far caves are followed, not reported). |
| `W-LITERAL`, `W-JUMPTABLE` | Every changed literal-pool word and switch-table word, for review. |
| `I-ENTERED-DEAD` / `I-ENTERED-OK` | A branch from outside a rewrite lands inside it, but the branch is unreachable after patching, or it lands on a valid new instruction. |

Caves are analysed as the hardware runs them: a cave "returns" if it ends with `bx lr`,
`pop {pc}` or `pop {rX}; bx rX`; `ldr rX, =addr|1; bx rX` is an absolute exit; chains through
near/far trampolines are followed.

## Result (translation as of commit `3d6bf91`)

8,859 changed ranges; no errors:

- No reachable path executes half of a `bl` or an invalid instruction.
- No lost register values: the three `W-LOSTDEF` candidates found during development were
  false (an identical `adds r6, r5, #1` earlier in `Menu_DrawItemNameTriple` /
  `Menu_DrawSkillRowTriple`; the Analyze race-name cave in `sub_080F390C` exits past the old
  glyph loop).
- 13 branches land inside rewritten bytes: 9 are dead after patching (the hook skips the old
  loop), 4 land on a valid instruction of the new code (`bname-nop` sequences).
- All 358 repointed literals keep their kind; the two rewritten switch entries in the
  typewriter (`sub_080EA538`, cases 2 and 6) point at valid Thumb veneers.

So the remaining translation bugs are not low-level patch corruption; they are in what the
caves and text do. That is where the decompilation helps next: read the original function in
`reference/ghidra-c/` beside the cave that replaces it.
