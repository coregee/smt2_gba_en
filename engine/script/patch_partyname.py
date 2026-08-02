#!/usr/bin/env python3
"""Party-name suffix: the "first-alive party name + 達" substitution -> EN "'s party".

The game appends the kanji 達 (tachi, "and company") after the player's name when the active
party has more than one member, expanding token 0x320 (alias {PARTY_NAME}, raw {=2003}).  In
English that drew the raw kanji ("Hawk達 found Luck Incense!", "Hawk達's attack fell").  Two
SEPARATE engine functions expand 0x320 and each appends 達 (glyph 0x0C8F); this patch hooks both
so 0x320 renders **"Hawk"** when solo / **"Hawk's party"** in a party — the game's own
solo-vs-party condition preserved, in English, everywhere the token appears:

  (1) FIELD / event-VM:  ScriptOp_DrawCharOrSubstitute 0x08132b40, jump-table 0x08132c00 index 6
      (case body 0x08132e3c).  Decodes the first-alive HUMAN slot's name into staging 0x0203DB08,
      counts active humans (slots 0..3), appends 達 when >1.  The 達-append block is the body of
      the `if activeCount>1` arm (24 B @0x08132ED2; r6 = trimmed name length).  Drives the four
      dungeon_events.json treasure/Macca/Magnetite "found" messages.

  (2) BATTLE / menu:  Menu_ExpandListTemplate 0x080EBCA4 case 10.  Copies the first-alive party
      member's display name into the compose buffer (r6 = cursor), counts active party incl. demons
      (slots 0..15), appends 達 when >1 (8 B @0x080EBDE2).  Drives the ~33 battle.json
      {PARTY_NAME} buff/debuff/heal/protect result lines (e.g. "{PARTY_NAME} recovered").

Each 達-append (one glyph) is overwritten with `bl cave` (+ NOP pad); the asm cave streams the
codec-encoded "'s party" tokens into the buffer at the cursor and advances it, then returns into
the NOPs and falls through to the original tail.  Solo still skips the whole block via the
original `ble`, so the name stands alone.  Because every live 0x320 expansion routes through one
of these two functions, all party messages are fixed at once; the JSON `replace` strings keep the
{PARTY_NAME}/{=2003} token (which now yields "Hawk" / "Hawk's party") and need no per-line wording.

(The third 0x0C8F appender, MessageBox_ComposeWrappedText 0x080ebed4, is dead code in the EN build
 — its only caller, the flee message, was retargeted to Menu_ExpandListTemplate by patch_typewriter
 — so it is left untouched.)
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from text.script import tr

STAGING = 0x0203DB08          # field substitution staging buffer (== case literal @0x08132F04)

# "'s party" through the canonical codec (no hardcoded glyph ids), 0x0000-terminated.
SUFFIX_TOKENS = tr.encode("'s party") + b"\x00\x00"

# --- (1) FIELD: ScriptOp_DrawCharOrSubstitute, the 0x320 case 達-append block -------------------
# 12 insns / 24 B: ldr r2,[stg]; add r1,r6,#0; ...; ldr r0,[達]; strh r0,[r1].  r6 = name length;
# the cave caps the write before staging slot 24 (offset 0x30) so a pathological 8-glyph name +
# suffix can't reach the next variable @0x0203DB40 (realistic player names <= 6 never hit the cap).
FIELD_HOOK = 0x08132ED2
FIELD_OLD  = bytes.fromhex("0c4a311c080480235b02c018060c0904c913891808480880")
FIELD_ASM = """
    ldr  r2, [pc, #0]      /* r2 = staging 0x0203DB08 */
    lsls r1, r6, #1
    adds  r1, r1, r2   /* r1 = dest = &staging[namelen] */
    movs r3, #0x30
    adds  r3, r3, r2   /* r3 = cap = staging + 0x30 (slot 24) */
    ldr  r0, [pc, #0]      /* r0 = suffix token stream */
pf_loop:
    ldrh r2, [r0]
    cmp  r2, #0
    beq  pf_done           /* 0 = end of suffix */
    cmp  r1, r3
    bhs  pf_done           /* buffer cap reached */
    strh r2, [r1]
    adds r0, #2
    adds r1, #2
    adds r6, #1            /* advance the staging index for the terminator block */
    b    pf_loop
pf_done:
    bx   lr
"""

# --- (2) BATTLE / menu: Menu_ExpandListTemplate case 10, the 達-append block --------------------
# 4 insns / 8 B: ldr r3,[達]; add r0,r3,#0; strh r0,[r6]; add r6,#2.  r6 = compose-buffer cursor
# (puVar9); the following `b 0x080ebe4c` (template-advance + loop) is preserved.  The cave only
# touches r0/r1 (saved+restored) and r6 (the cursor it advances), so it's independent of how the
# function allocates its other live registers (template ptr etc.).
BATTLE_HOOK = 0x080EBDE2
BATTLE_OLD  = bytes.fromhex("024b181c30800236")
BATTLE_ASM = """
    push {r0, r1}
    ldr  r1, [pc, #0]      /* r1 = suffix token stream */
pb_loop:
    ldrh r0, [r1]
    cmp  r0, #0
    beq  pb_done
    strh r0, [r6]
    adds r1, #2
    adds r6, #2
    b    pb_loop
pb_done:
    pop  {r0, r1}
    bx   lr
"""


def apply(p):
    suffix = p.data(SUFFIX_TOKENS, name="partyname-suffix")
    p.bl(FIELD_HOOK, p.cave_asm(FIELD_ASM, [STAGING, suffix], name="partyname-field"),
         FIELD_OLD, name="partyname-field-bl")
    p.bl(BATTLE_HOOK, p.cave_asm(BATTLE_ASM, [suffix], name="partyname-battle"),
         BATTLE_OLD, name="partyname-battle-bl")
