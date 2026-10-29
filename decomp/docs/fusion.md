# Fusion rules

Read from `src/fusioncalc_*.c` (0x08158970-0x0815B824). The work area is `gUnk_0203B868`
(`struct FusionWork` in `fusioncalc_d.c`). Which game races ids 8, 0x16 and > 0x1A are, and
what alignment 0xB is called, is inferred from the data, not proven.

## Three materials

Materials are sorted by id, then the first rule that applies decides:

1. **Special table.** If the three materials are listed in the three-way table, it gives the result.
2. **Race 8** (ids 0x32-0x39, probably the elements):
   - One race-8 material: fuse the other two, one rank down, then fuse with the third.
   - Two of the same kind (`(id - 0x32) & 3`): the remaining demon's rank moves by the sum
     of their table values.
   - Three, all in 0x32-0x35 or all in 0x36-0x39: the first unused id of the group picks
     the result from a table.
3. **A material of race > 0x1A.** If it sorts first, the highest-level material drops three
   ranks; otherwise a pair fusion and one rank down.
4. **Exactly one dark (alignment 0xB) material.** The result is an accident: if it equals a
   material or is not allowed, `sub_08158CA4` picks one. Two or more dark materials give no
   result.
5. **Race 0x16.** All three: demon 0x35. One or two: pair fusion, one rank down.
6. **Ordinary.** Sort by level (highest first). The last two alignments choose a column and
   the first one's alignment the race. The result is the first demon of that race at or above
   average level + 4 x (materials of race <= 0xC) - 4. A table value of 0xFF means a random
   allowed demon below the hero's level.

## Accident roll (Fusion_RollAccident)

Happens 1 time in 256, or always when flag 0xD8 is set. Picks a random allowed demon not
already owned, with its level in a band above the hero:

| Materials | Level band |
|---|---|
| two | hero + 16 - 25 up to hero + 16 (exclusive) |
| three | hero + 26 - 40 up to hero + 26 (exclusive) |

The upper limit is capped at 0x4B. After 32 failed tries the result is demon 0xFB.

## Verdict (Fusion_CheckResult)

| Value | Meaning |
|---|---|
| 0 | no result |
| 1 | the result's alignment class fits the hero's (equal, or either is neutral) |
| 2 | it does not fit |
| 3 | the result's level is above the hero's (hero + 9 if a race > 0x1A material was used) |
| 4 | already in stock |

## Commit (Fusion_ApplyResult)

- A per-demon counter for ids 0x54-0xB1 (the `ItemStock` functions) drops by 2 per material
  and rises by 4 for the result.
- Unless flag 0xE0 is set, the hero's alignment value (offset 0x58, copied to party members 1
  and 2) moves 26 toward the result's class: down for class 0, up for class 2.

## Random results (Fusion_IsRandomResult)

The fusion list marks a result as random (flag 0x30) when there is exactly one dark material
and neither material is demon 0xFB, or for three materials (none above race 0x1A) whose
top-level material has alignment 3, 7, 6 or 5 with particular alignments for the other two.

## Skills

The result keeps its own skills of its class plus same-class skills from the materials,
sorted, up to 6. A result with no own skills of its class gets its other skills, then the
materials' skills in the range 0x24-0x39.

## Item demons

Modes 1, 4 and 5 (ids 0x40 and up) use tables at 0x087F1B13, 0x087F1BB3 and 0x087F1C53. A
table entry of `0x80 | race` accepts any demon of that race.
