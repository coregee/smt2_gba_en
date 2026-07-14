#!/usr/bin/env python3
"""Demon names in battle text -> English.  English demon names live in NAME_TABLE (names_demon.json) but
are only drawn through the compendium's name-DRAW cave; the battle TEXT builders instead COPY the JP inline
name from the ROM record (Combatant_GetRecord(id)+0x22), so they showed Japanese.

These six VERIFIED builders share the exact simple pattern
    ldrh r0,[combatant,#0x12]; bl Combatant_GetRecord; add rX,r0,#0; add rX,#0x22; <copy, cap 8>
We repoint each `bl` to cave_battlename (GetRecordNameEN: id -> NAME_TABLE[id] English, else record+0x22)
and NOP the `add rX,#0x22` (the cave returns the name pointer directly), so rX ends up = the English name.

NOTE: an earlier version AUTO-SCANNED for every `bl GetRecord; add #0x22` site (~40) and hooked them all —
that corrupted the encounter-intro name (some of those sites aren't a plain copy: they use the record+0x22
pointer for more than a simple read).  So this is back to the curated, individually-verified set.  Other
demon-name spots (encounter intro, COMP/fusion menus) need their own targeted handling.  These name BRANCHES
are disjoint from patch_battlewedge's hooks (those sit in the later WEDGE sections).

2026-06-10: added the MessageBox composer sites (COMPOSER_BLS/COMPOSER_PATCHES below) — the battle
event/negotiation message family ("X joined the party" etc., see docs/battle-message-window.md)."""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from pathlib import Path
from engine.script import rommap
from engine.script.cave_asm import thumb_bl

SRC = Path(__file__).resolve().parent / "cave_battlename.c"
GETREC = rommap.Combatant_GetRecord

# (bl_site -> Combatant_GetRecord, add_site `add rX,#0x22`, add_old_hex) per verified name builder
SITES = [
    (0x080EB276, 0x080EB27C, "2231"),  # Battle_BuildCombatActionList (r1)
    (0x080EAE86, 0x080EAE8C, "2234"),  # Battle_BuildCombatSkillList   (r4)
    (0x080EAF76, 0x080EAF7C, "2234"),  # Battle_BuildSkillCastText     (r4)
    (0x080EB0D6, 0x080EB0DC, "2234"),  # Battle_BuildItemActionList    (r4)
    (0x080EBEA6, 0x080EBEAC, "2232"),  # Combatant_GetSkillList        (r2) — template expander name sub
    (0x080EADDA, 0x080EADE0, "2232"),  # Battle_BuildActorPrompt       (r2)
    (0x080EB4B2, 0x080EB4B8, "2232"),  # Battle_BuildDamageDealtText   (r2) — "Xに{n}25のダメージを与えた"
                                       #   (fragment @08123BCC; guard reads via r2, plain copy; the
                                       #    trailing-0x70 trim no-ops on a marker token)
    (0x080EB1BE, 0x080EB1C4, "2232"),  # Battle_BuildStatusResultText  (r2) — status は/を + skill results;
    (0x080EB5C2, 0x080EB5C8, "2232"),  # Battle_BuildDefeatedTargetText (r2) — を倒した.  Both feed
                                       #   patch_namemove's cave (their copy loops are replaced by it,
                                       #   so the record ptr is provably a plain name read)
    # ---- the reward/result composers (the "parked splice lines", traced 2026-06-13) ----
    (0x080EB7AE, 0x080EB7B4, "2232"),  # Battle_BuildActorStatusText 0x080eb71c (r2) —
                                       #   おっと！{n}NAMEは平気だ: FIXED 5-token template prefix
                                       #   + name + FIXED 4-token suffix.  EN template must be
                                       #   exactly 5+4 tokens (system_menu 08124234).
    (0x080EB3FE, 0x080EB404, "2232"),  # Battle_BuildNamePrefixText 0x080eb37c (r2) —
                                       #   レベルが上がった: template = [u16 prefix COUNT]
                                       #   [prefix tokens] name [suffix..0].  EN replace
                                       #   carries the count head as {=0100}.
    (0x080EB32E, 0x080EB334, "2232"),  # Battle_BuildNamePrependText 0x080eb2d4 (r2) — builds
                                       #   "[name]<template>" (name PREPENDED, cap-8 loop reading
                                       #   via r2 -> a plain copy; the 1-token marker fits).  All 6
                                       #   callers render via BattleMenu_SetMode(3): "[name]は力尽きた"
                                       #   (has fallen, the report), は跳ね返した (reflected),
                                       #   と別れますか/と別れました (COMP dismiss confirm/done).
]

# The MessageBox composers (battle event/negotiation messages: "X joined the party",
# "X is eager to fight", "X walked away from the Y"...) use the same
# `bl Combatant_GetRecord; add rX,#0x22; <copy, cap 8>` shape, EXCEPT their loop-entry
# guard reads the first name glyph THROUGH THE RECORD register (`ldrh r0,[rec,#0x22]`)
# instead of through rX — so each needs a third 2-byte patch retargeting the guard at the
# cave-returned name pointer.  Verified plain copies (record ptr unused after the loop):
#   MessageBox_ComposeNameText    0x080eaab0 — name + caller suffix (Battle_ShowEventMessage,
#                                              Battle_TurnState_CommandMenu hostile msg, ...)
#   MessageBox_ComposeSpeciesText 0x080eac0c — 0x031e species-name sub-code (two bl sites,
#                                              idA/idB, converging on one copy loop)
COMPOSER_BLS = [
    0x080EAAD8,               # ComposeNameText
    0x080EACEA, 0x080EACF6,   # ComposeSpeciesText 0x031e branch (first/second occurrence)
    0x080EB922,               # Battle_BuildRaceCountText 0x080eb8dc (悪魔N体をしとめた) —
                              #   species name copy; guard reads through the record reg
]
COMPOSER_PATCHES = [
    (0x080EAAF2, "2231", "c046"),  # ComposeNameText: add r1,#0x22 -> NOP
    (0x080EAAF6, "688c", "0888"),  # ComposeNameText: ldrh r0,[r5,#0x22] -> ldrh r0,[r1,#0]
    (0x080EACFC, "2232", "c046"),  # ComposeSpeciesText: add r2,#0x22 -> NOP
    (0x080EAD00, "408c", "0088"),  # ComposeSpeciesText: ldrh r0,[r0,#0x22] -> ldrh r0,[r0,#0]
    (0x080EB928, "2234", "c046"),  # BuildRaceCountText: add r4,#0x22 -> NOP
    (0x080EB92C, "408c", "2088"),  # BuildRaceCountText: ldrh r0,[r0,#0x22] -> ldrh r0,[r4,#0]
]

# Battle_BuildDamageDealtText 0x080eb454 builds "<target>に{n}<digits>のダメージを与えた" by
# copying EXACTLY fragment tokens[0..1] before splicing the damage digits — too rigid for
# English ("<target> took <digits> damage" needs a 6-token prefix).  Replace the inline
# 2-token copy (0x080eb4e2..0x080eb4f1) with a cave that copies the fragment prefix up to a
# 0xFFFF sentinel (skipping it; same convention as the battlewedge fragments — tr.pack emits
# prefix 0xFFFF suffix for the battlefrag entry @08123BCC "[name] took [damage] damage").
# A sentinel-less fragment (untranslated JP) falls back to the original 2-token copy.
# Registers at the site: r4 = fragment ptr, r5 = dest ptr (both advanced for the caller);
# r0-r3 are dead (digit code reloads them); r6/r7/r8 untouched.
DMGSPLIT_HOOK = 0x080EB4E2
DMGSPLIT_OLD  = "20882880023402352088288002340235"   # 2x (ldrh r0,[r4]; strh r0,[r5]; add r4,#2; add r5,#2)
DMGSPLIT_ASM = """
    movs r1, #1
    lsls r1, r1, #16
    subs r1, #1          /* r1 = 0xFFFF sentinel */
    adds  r2, r4, #0   /* scan: does the fragment contain a sentinel before the terminator? */
scan:
    ldrh r0, [r2]
    cmp  r0, r1
    beq  wedge
    cmp  r0, #0
    beq  plain
    adds r2, #2
    b    scan
wedge:                   /* copy prefix tokens until the sentinel, then skip it */
    ldrh r0, [r4]
    cmp  r0, r1
    beq  wskip
    strh r0, [r5]
    adds r4, #2
    adds r5, #2
    b    wedge
wskip:
    adds r4, #2
    bx   lr
plain:                   /* no sentinel (JP fragment): original behavior, copy 2 tokens */
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #2
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #2
    bx   lr
"""


# Battle_BuildRaceCountText 0x080eb8dc builds "<species><digits>体を{n}しとめた" with a RIGID
# splice: template tokens[0..2] skipped, species name, count digits (NO separator), then
# template[3], template[4], a HARDCODED {n} (movs #0xC0; lsls #2), then template[5..].
# Two micro-caves make English possible ("Pixie 3 down!"):
#   The first cut used two micro-caves bending the RIGID splice order ("Pixie 3 down!").
#   Superseded 2026-06-13 (user: "Defeated Pixie x3!"): the composer CALL SITES are
#   repointed to cave_resultmsg.c, which rebuilds the message from a sentinel template
#   (0xFFFE = name, 0xFFFF = count digits) in free order, and tail-calls the stock
#   composer for sentinel-less (JP) templates.
RESULTMSG_SRC = Path(__file__).resolve().parent / "cave_resultmsg.c"
COUNT_CALL  = (0x080E9A16, "01f061ff")   # bl Battle_BuildRaceCountText   (悪魔N体をしとめた)
STATUS_CALL = (0x080F1FE0, "f9f79cfb")   # bl Battle_BuildActorStatusText (おっと！は平気だ)
REWARD_CALL = (0x080E9ED4, "01f08afd")   # bl Battle_BuildRewardText      (NAMEはNのEXPを得た)
VICTORY_CALL = (0x080E98D8, "01f096f8")  # bl MessageBox_ComposeRaceNameText (RACE+NAMEを倒した)
MACCA_CALL  = (0x080E9DA0, "01f0befe")    # bl Battle_BuildValueRewardText (Nマッカ手に入れた)
MAG_CALL    = (0x080E9DF8, "01f092fe")    # bl Battle_BuildValueRewardText (Nマグネタイトを得た)
ITEMDROP_CALL = (0x080E9C90, "01f0aeff")  # bl Battle_BuildItemDropText    ([item]を拾った)
GEMDROP_CALL  = (0x080E9D44, "01f0ecfe")  # bl Battle_BuildValueRewardText (N個の魔石/宝石を拾った)
DODGE_CALL    = 0x080F0EA0                 # bl Battle_BuildDodgeText (やった！\n<name>はかわした);
                                           # enemy attack missed -> defender dodged (FUN_080f0cfc).
                                           # old bytes computed from thumb_bl(site, Battle_BuildDodgeText).

# ---- pixel wrap for MessageBox_ComposeWrappedText 0x080ebed4 (2026-06-13) ------------
# The composer auto-wraps with a 0x300 every 17 glyphs (`bl __umodsi3(count,0x11)` —
# fixed-pitch JP assumption; EN half-width text broke ~40% into the window).  The BL is
# repointed to a cave that accumulates PIXEL width instead: w = WIDTH_TABLE[tok] for EN
# glyphs, 12 (the battle sprite pitch) otherwise — so a pure-JP page wraps at exactly
# 17*12 = 204px = the original behavior, byte-identical.  EN breaks early at a space
# once the line passes 165px (keeps words whole); hard-wraps at 204px mid-word.
# Registers at the site: r0 = glyph count (1 = first -> reset the accumulator),
# r5 -> the just-copied token, r6 = out cursor; return r0==0 -> the engine inserts {n}.
# Known limitation: the 0x320 party-name expansion adds glyphs without passing through
# this site, so a line containing it under-counts by the name's width (~50px) — the
# name sits at the start of those streams, so the slack only pads the first wrap.
# Accumulator: u16 @ MSGWIN_STATE+0x2F0 (state struct ends at +0x2CA; ROWSAVE2 at +0x300).
WRAP_HOOK = 0x080EBFEE
WRAP_OLD  = "70f075ff"               # bl __umodsi3
WRAP_ASM = """
    push {r4, r5}
    ldrh r3, [r5]        /* the just-copied token */
    movs r4, #0x08       /* r4 = WIDTH_TABLE 0x087F2F40 */
    lsls r4, r4, #8
    adds r4, #0x7F
    lsls r4, r4, #8
    adds r4, #0x2F
    lsls r4, r4, #8
    adds r4, #0x40
    movs r2, #12         /* JP/control: the battle sprite pitch */
    cmp  r3, #0xBC
    blo  gotw
    movs r5, #0x8C
    lsls r5, r5, #1      /* 0x118 = ENG_HI */
    cmp  r3, r5
    bhs  gotw
    ldrb r2, [r4, r3]    /* EN: VWF advance */
gotw:
    movs r4, #0x02       /* r4 = the px accumulator @0x0203FAF0 */
    lsls r4, r4, #8
    adds r4, #0x03
    lsls r4, r4, #8
    adds r4, #0xFA
    lsls r4, r4, #8
    adds r4, #0xF0
    cmp  r0, #1          /* first counted glyph: fresh line */
    bne  acc
    movs r1, #0
    b    sum
acc:
    ldrh r1, [r4]
sum:
    adds r1, r1, r2
    cmp  r3, #0xBC       /* space: early word-break past 165px */
    bne  hard
    cmp  r1, #165
    bhs  wrap
    b    store
hard:
    cmp  r1, #204
    bhs  wrap
store:
    strh r1, [r4]
    movs r0, #1          /* nonzero -> no wrap */
    pop  {r4, r5}
    bx   lr
wrap:
    movs r0, #0
    strh r0, [r4]        /* reset; r0==0 -> the engine inserts {n} */
    pop  {r4, r5}
    bx   lr
"""


# Negotiation name-assembly (the 0x08132xxx event-VM message builder, ScriptOp_DrawCharOrSubstitute)
# copies the demon name into the substitution staging buffer 0x0203DB08 with a FIXED-8 loop, then
# the EVENT-VM window (cave_msgwin) draws it.  We hook each `bl Combatant_GetRecord` to cave_negoname
# (returns the pooled EN name ptr, else the JP record+0x22) and NOP the following `add r3,#0x22`,
# exactly like SITES.  We ALSO replace the fixed-8 copy LOOP that follows with `bl cave_negocopy`:
# the stock loop copied a fixed 8 tokens (truncating long EN names) AND, when fed the 0xF800-marker
# scheme, left a fixed-field gap; cave_negocopy instead streams the WHOLE name (cap 15) up to its
# 0x0000/0x0301 terminator, so the name flows as ordinary VWF glyphs (real per-glyph widths, the
# next word sits tight).  Both sites copy to the same staging 0x0203DB08, so one copy cave serves
# both.  Loop bytes are identical at both sites; it sits at bl_site+8 and the `b <tail>` after it
# (0x081331da) is preserved.
NEGO_SITES = [
    (0x08132D18, 0x08132D1E, "2233"),   # demon name (idA)  -> 0x0203DB08
    (0x08132F7C, 0x08132F82, "2233"),   # demon name (idB / two-type)
]
# The fixed-8 copy loop at bl_site+8 (30 bytes, identical at both sites) -> bl cave_negocopy + NOPs.
NEGO_COPY_OLD = "0026084c30040014410009191a880a80023301300004060c00140728f2dd"
NEGO_COPY_ASM = """
    push {r4, r5}
    movs r1, #0x02
    lsls r1, r1, #8
    adds r1, #0x03
    lsls r1, r1, #8
    adds r1, #0xDB
    lsls r1, r1, #8
    adds r1, #0x08          /* r1 = staging dest 0x0203DB08 */
    movs r5, #30
    adds r5, r5, r1         /* r5 = dest + 30 = cap (slots 0..14; staging is 16, slot 15 -> 0x318) */
    movs r4, #0x03
    lsls r4, r4, #8
    adds r4, #0x01          /* r4 = 0x0301 string terminator */
nc_loop:
    cmp  r1, r5
    bhs  nc_done
    ldrh r0, [r3]           /* r3 = name ptr (set by `add r3,r0,#0`; the +0x22 add is NOPed) */
    cmp  r0, #0
    beq  nc_done
    cmp  r0, r4
    beq  nc_done
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    b    nc_loop
nc_done:
    pop  {r4, r5}
    bx   lr
"""


def apply(p):
    p.cave_c(SRC, name="battlename")
    cave = p.cave_c_syms["cave_entry"]
    negocave = p.cave_c_syms["cave_negoname"]
    negocopy = p.cave_asm(NEGO_COPY_ASM, name="negocopy")
    for bl_site, add_site, add_old in NEGO_SITES:
        p.bl(bl_site, negocave, thumb_bl(bl_site, GETREC).hex(), name="bname-nego-bl")
        p.patch(add_site, add_old, b"\xc0\x46", name="bname-nego-nop")
        loop_site = bl_site + 8                       # the fixed-8 copy loop -> bl cave_negocopy + NOPs
        new_loop = bytes.fromhex(thumb_bl(loop_site, negocopy).hex()) + b"\xc0\x46" * 13
        p.patch(loop_site, NEGO_COPY_OLD, new_loop, name="bname-nego-copy")
    for bl_site, add_site, add_old in SITES:
        p.bl(bl_site, cave, thumb_bl(bl_site, GETREC).hex(), name="bname-bl")
        p.patch(add_site, add_old, b"\xc0\x46", name="bname-nop")   # add rX,#0x22 -> NOP (mov r8,r8)
    for bl_site in COMPOSER_BLS:
        p.bl(bl_site, cave, thumb_bl(bl_site, GETREC).hex(), name="bname-compose-bl")
    for site, old, new in COMPOSER_PATCHES:
        p.patch(site, old, bytes.fromhex(new), name="bname-compose-fix")
    dmgcave = p.cave_asm(DMGSPLIT_ASM, name="dmgsplit")
    p.bl(DMGSPLIT_HOOK, dmgcave, DMGSPLIT_OLD, name="dmgsplit-bl")   # bl + 6 pad NOPs
    p.cave_c(RESULTMSG_SRC, name="resultmsg")
    p.bl(COUNT_CALL[0], p.cave_c_syms["cave_entry"], COUNT_CALL[1], name="resultmsg-count")
    p.bl(STATUS_CALL[0], p.cave_c_syms["cave_status"], STATUS_CALL[1], name="resultmsg-status")
    p.bl(REWARD_CALL[0], p.cave_c_syms["cave_reward"], REWARD_CALL[1], name="resultmsg-reward")
    p.bl(MACCA_CALL[0], p.cave_c_syms["cave_valreward"], MACCA_CALL[1], name="resultmsg-macca")
    p.bl(MAG_CALL[0],   p.cave_c_syms["cave_valreward"], MAG_CALL[1],   name="resultmsg-mag")
    p.bl(ITEMDROP_CALL[0], p.cave_c_syms["cave_itemdrop"], ITEMDROP_CALL[1], name="resultmsg-itemdrop")
    p.bl(GEMDROP_CALL[0], p.cave_c_syms["cave_valreward"], GEMDROP_CALL[1], name="resultmsg-gemdrop")
    p.bl(DODGE_CALL, p.cave_c_syms["cave_dodge"],
         thumb_bl(DODGE_CALL, rommap.Battle_BuildDodgeText).hex(), name="resultmsg-dodge")
    p.cave_c(Path(__file__).resolve().parent / "cave_victory.c", name="victory")
    p.bl(VICTORY_CALL[0], p.cave_c_syms["cave_entry"], VICTORY_CALL[1], name="resultmsg-victory")
    wrapcave = p.cave_asm(WRAP_ASM, name="pxwrap")
    p.bl(WRAP_HOOK, wrapcave, WRAP_OLD, name="pxwrap-bl")
