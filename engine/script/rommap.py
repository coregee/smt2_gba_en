#!/usr/bin/env python3
"""Single source of truth for ROM/RAM addresses shared across the build scripts.

Before this existed, addresses like the VWF width table (0x087F2F40), the demon/item name
pointer tables, the status text buffer and engine entry points were copy-pasted into ~8 patch
scripts and tr.py, kept in sync only by hand and by comments like "= tr.py ITEM_TABLE".  Import
from here instead so a layout change is a one-line edit.

Conventions: addresses are the byte address in the cartridge/RAM map.  Engine *functions* are
given as their even (ARM-style) entry; add `| 1` at the call site when a Thumb `bx`/pointer needs
the low bit set.  See docs/text-render-hooks.md and docs/text-extraction.md for context.
"""

ROM_BASE = 0x08000000

# Base-ROM location. The source image lives under the repository's local-only rom/ directory.
# `load_rom()` instead of re-hardcoding the filename (was copy-pasted into ~25 scripts + tr.py).
from paths import ProjectPaths

_PATHS = ProjectPaths.discover()
ROOT = _PATHS.project_root
ROM_FILENAME = _PATHS.source_rom.name
ROM_PATH = _PATHS.source_rom


def load_rom():
    """Read the base ROM as a mutable bytearray (the patch/pack pipeline edits in place)."""
    return bytearray(ROM_PATH.read_bytes())


# Free 0x00 region used as the code-cave pool (RomPatcher auto-allocates here).  Verified all-zero
# in the base ROM; tile graphics start at 0x081AC8B8 (first nonzero byte 0x99), so that is the hard
# upper bound (extended 2026-06-14 from 0x081AC800 by 184 B of verified 0x00 padding / 0 ptr refs).
CAVE_POOL_START = 0x081AB3A0
CAVE_POOL_END   = 0x081AC8B8
# Code caves bump-allocate across these free spans in order.  All are 0x00 padding within Thumb BL range
# (+-4MB) of the hooks (~0x080A..0x0815xxxx), so a `bl` from any hook reaches them; far free blocks (the
# 0xFF text pool @0x087F2F40, the 0x0869xxxx runs) are OUT of BL range and can't hold code.  A single
# cave_c/cave_asm blob is placed whole into the first span it fits, so keep new battle-text caves as
# SEPARATE .c blobs (not appended to a big existing one) so they can land in a later span.  Add more
# verified-free reachable runs here before resorting to a 16MB ROM expansion.
CAVE_POOL_SPANS = [(CAVE_POOL_START, CAVE_POOL_END),   # 5216 B (original)
                   (0x081B72BC, 0x081B8170),            # 3764 B (verified 0x00 padding, 0 ptr refs)
                   (0x081B9D20, 0x081BA3B0),            # 1680 B (verified 2026-06-13: 0x00 pad, 0 refs)
                   (0x081AA7B8, 0x081AADB8),           # 1536 B (verified 2026-06-13: 0x00 pad; one
                                                        #   2-aligned u32 coincidence inside compressed
                                                        #   gfx @0x0820F7B4 - not a pointer)
                   (0x081B98AC, 0x081B9BB0),           # 772 B (verified 2026-06-13: 0x00 pad, 0 ptr refs;
                                                        #   for the grown cave_runtext/cave_strip cell-packer)
                   (0x081BA8AC, 0x081BABB0),           # 772 B (verified 2026-06-14: 0x00 pad, 0 ptr refs;
                                                        #   gap between a ptr/index table and the following
                                                        #   gfx. Added for cave_dictinfo, the detail-screen.)
                   (0x081C0DB0, 0x081C1270)]            # 1216 B (verified 2026-06-14: all-0x00 pad between
                                                        #   two data blocks, 0 ptr refs anywhere in ROM, in
                                                        #   BL range. Added for patch_namehuman (human-name VWF).)

# FAR code-cave pool: the 16 MB ROM's upper padding (the translation pool ends ~9 MB; everything
# above is 0xFF/0x00 fill).  This is OUT of Thumb BL range from the ~0x080xxxx hooks, so a far cave
# can't be `bl`'d directly -- the hook `bl`s a tiny NEAR trampoline (RomPatcher.bl_far) that jumps to
# the far body via an absolute literal.  Lets big caves (the strip core, etc.) live here instead of
# fighting for the scarce near pool.  build_rom pre-extends the working ROM to 16 MB with 0x00 so
# these addresses are writable during the patch phase; tr.pack's pool never reaches this high and its
# final pad is a no-op (the ROM is already 16 MB), so the far caves survive packing.  12 MB base
# leaves a ~3 MB margin above the live translation data.
# The bottom of the far region is reserved for far DATA (the wider location-name table + the
# relocated title graphics, below); the far CODE-cave allocator starts ABOVE them so a far cave
# can never collide.  (Far data must sit INSIDE the far region's declared extent, not above it,
# because build_rom's pass-1 scratch pool occupies everything above max(FARCAVE hi) — see
# build_rom._fresh_rom / build_patcher.)
FARCAVE_POOL_SPANS = [(0x08C90000, 0x08F00000)]         # ~2.4 MB of far code-cave space (table below)
ROM_TARGET_SIZE    = 0x01000000                          # 16 MB (build_rom pre-extends to this)

# Wider save/load + map-banner location-name table (patch_savevwf cap-lift): a parallel copy of the
# 0x080A548C cells at 0x40 stride (32 u16 tokens, '@' 0x0057 pad, no terminator) so English names can
# exceed the original 16-token cap (longest ~27).  The three index computations that feed the five
# drawers (Location_GetNameCellFromCoords coords path, the save-screen region loop, +4 cap raises) are
# redirected here; the old 0x20 table stays in place as a graceful fallback for any unhooked reader.
# 1024 cells (0x10000 B) = the full reserved 64 KB; cells past the 530 real ones are blank (a coords
# index out of range stops at the first 0x57 = nothing drawn, never garbage).
FARDATA_LOCTABLE   = 0x08C00000                          # ends 0x08C10000
LOCTABLE_STRIDE    = 0x40                                 # 32 u16 tokens/cell
LOCTABLE_CELLS     = 1024                                 # fills the reserved 64 KB; 530 real, rest blank

# Relocated title/intro/game-over baked-text graphics (patch_titlegfx): when a re-encoded
# tile block (graphics/assets/*.png, registry in graphics/script/gbagfx.py) outgrows its original compressed
# slot it is placed here (bump allocator inside the patch) and its literal-pool pointer(s)
# are repointed.  512 KB is generous: the sum of ALL registered blocks' compressed streams
# is ~0x10000.
FARDATA_TITLEGFX   = 0x08C10000                          # ends at FARDATA_TITLELOGO

# Extended title-logo metasprite (patch_titlegfx logo-caption step): the stock logo
# attrList @0x0813EE60 (6 OAM entries) + 6 caption strips displaying the sheet's unused
# y72..87 rows as small EN text above the kanji; desc {attrList, NULL} follows.  The four
# title-state pool literals holding 0x0813EE88 are repointed here.
FARDATA_TITLELOGO  = 0x08C8FF00                          # ends 0x08C90000 (= FARCAVE start)

# ---------------------------------------------------------------------------
# Translation data block (written by tr.py pack, past the VWF width table)
# ---------------------------------------------------------------------------
WIDTH_TABLE      = 0x087F2F40        # VWF advance table, indexed by glyph code (1 byte each)
WIDTH_TABLE_SIZE = 0x1300            # ends exactly at SMALLSHEET_EXT

# Relocated 8px thin-face sheet (patch_defaultnames): the party-panel / name-preview 8px name
# drawers index the small sheet by raw NAME-CHARSET INDEX (cell = 0x100 + idx, literal
# 0x081AF7B8 = smallsheet base + 0x100*0x20).  Lowercase charset indices (0xE0+) would land in
# the live UI-tile cells (0x1E0+ = moon phase/shop icons), so the thin face is copied here
# (idx 0x00-0xDF = original cells 0x100-0x1DF) + 26 rasterized Galmuri7 lowercase cells at
# idx 0xE0-0xF9, and both literals are retargeted.  Sits between the width table and the
# string pool (0xFF free space; pack pads the ROM to 16MB so the pool just shifts up).
SMALLSHEET_EXT      = 0x087F4240
SMALLSHEET_EXT_WIDTHS = SMALLSHEET_EXT + 0x1F40  # 8px VWF advance per charset idx (0xFA bytes)
SMALLSHEET_EXT_SIZE = 0x2040         # 0xFA cells * 0x20 = 0x1F40 + 0xFA width bytes, rounded up
SMALLSHEET_THIN_REFS = [0x080C6ECC, 0x080D0310]  # literal pools holding 0x081AF7B8

# The two index-direct 8px name drawers (VWF-hooked by patch_defaultnames):
PARTY_NAME_CANVAS   = 0x020399E4     # Party_BuildMemberNameTiles strip canvas (6 panels x 0x100 B = 8 linear 4bpp tiles)
PARTY_PANEL_RESOLVE = 0x080C0148     # roster pos (0-5) -> Combatant struct ptr, 0 = empty

POOL_START       = 0x087F6280        # start of the packed-string pool (free 0xFF padding)

# Parallel id -> pooled-name-pointer tables reserved at the pool front (one u32 per id, 0 = none).
# tr.py pack fills them; the name-draw caves index them.  Demon table first, then item table.
NAME_COUNT       = 0x17C             # real demon ids 0-379
NAME_TABLE       = POOL_START
NAME_TABLE_SIZE  = NAME_COUNT * 4
ITEM_COUNT       = 0x15A             # item ids 0x00-0x159 (equipment 0x00-0xCF + items 0xD0-0x159).
# NB: was 0x150 (off by 10) -> names_item ids 0x150-0x159 (フォトフレーム-era "material"/visionary
# items like 百合のコサージュ=0x155) were written PAST ITEM_TABLE into MARKER_TABLE, clobbering demon
# markers 0-9 AND leaving those items untranslated everywhere (shop, visionary list, ...).
ITEM_TABLE       = NAME_TABLE + NAME_TABLE_SIZE
ITEM_TABLE_SIZE  = ITEM_COUNT * 4

# Battle demon-name MARKER table: id -> the 2-u16 token [MARKER_BASE|id, 0].  patch_battlename's cave
# returns &MARKER_TABLE[id], so the battle name-copy emits just the 1-u16 token (fits any cap-8/fixed copy
# loop); patch_spritebuf expands MARKER_BASE|id through NAME_TABLE in the sprite-strip renderer.
MARKER_BASE       = 0xF000           # glyph codes >= 0xF000 are name markers (0xF000 | demon id)
MARKER_TABLE      = ITEM_TABLE + ITEM_TABLE_SIZE
MARKER_TABLE_SIZE = NAME_COUNT * 4

# Item/equipment name records (inline word[8] pDisplayText).  The item-use menu draws the inline
# name; cave_skilllist maps that name pointer back to an id to read the pooled name from ITEM_TABLE.
EQUIP_REC_BASE   = 0x08198B74        # EquipmentRecord36[id], id 0x00-0xCF; pDisplayText @ +0x14
EQUIP_REC_STRIDE = 36
EQUIP_NAME_OFF   = 0x14
ITEM_REC_BASE    = 0x08198EB4        # Biased ItemRecord32 base: base + id*32, ids 0xD0-0x159
ITEM_REC_STRIDE  = 32
ITEM_NAME_OFF    = 0x0C
# Demon name records (combatant_table; the +0x22 "skills"-misnamed name field, ids 0-0x17B).  The
# party/ally menu list draws this inline; cave_skilllist maps the pointer back to an id -> NAME_TABLE.
DEMON_REC_BASE   = 0x0819CB74
DEMON_REC_STRIDE = 0x60
DEMON_NAME_OFF   = 0x22

# English glyph code range (digits/letters/punct/space); outside this = Japanese -> keep fixed pitch.
ENG_LO = 0xBC
ENG_HI = 0x118

# ---------------------------------------------------------------------------
# Stream tokenizer control codes — the glyph/opcode/optail walk constants that
# were copy-pasted across the four stream walkers (tr.decode/encode,
# tr.extract_story_vm, scriptrefs.tokenize_stream/tokenize_rep; backlog #4).
# Centralized here 2026-06-16 so the walkers — and, via write_header -> rommap.h,
# the C/asm caves — agree on one set. (scriptrefs adopted first; tr.py follows.)
# ---------------------------------------------------------------------------
TERM_NUL     = 0x0000   # plain (0000) string terminator
TERM_MSG     = 0x0301   # ScriptOp_EndMessage: event-VM message / template terminator
TOK_NEWLINE  = 0x0300   # {n} newline token (lowest VM-control code)
OP_LO        = 0x0302   # first real VM opcode (after the {n}/terminator codes)
VMCTRL_HI    = 0x0470   # top of the VM-control / name-value substitution range (inclusive)
TOK_WAIT     = 0x0316   # {WAIT}
TOK_PAGE     = 0x0317   # {PAGE}
PAD_WORD     = 0x11FE   # dead-space padding word after jumps (skipped, never text)
FONT_CODE_HI = 0x11FF   # last font glyph code (font ends here)
CODE_LO      = 0x1300   # codes >= this are pure script code, never a drawable glyph
OPTAIL_LO    = 0x0801   # story-bank pointer high-half range (近金吟銀九倶句区狗玖苦): a glyph in
OPTAIL_HI    = 0x080B   #   [LO,HI] directly after an op is an operand-tail anchor, not prose

# ---------------------------------------------------------------------------
# Engine entry points (ROM, Thumb)
# ---------------------------------------------------------------------------
Font_DrawGlyph              = 0x080AC8D0   # one opaque glyph into a BG canvas
Font_DrawGlyphTinted        = 0x080AC980   # one tinted glyph into a BG canvas (code,canvas,x,y,tint)
FontSprite_DrawGlyph        = 0x080AC218   # one glyph as an OAM sprite (cached)
FontSprite_DrawCached       = 0x080AC2A0   # one OAM glyph at (x,y) via the glyph cache (code,_,_,x,y,flag)
LEVEL_CAT_BASE              = 0x087E32C8   # compendium LEVEL-filter range strings (10 x 0xC bytes: "1-9"..)
Race_GetNamePtr             = 0x080C068C   # race id -> ENGLISH race-name ptr (compendium uses it; Ghidra
                                           # mislabels it Race_GetSkillListPtr — it returns the name)
Text_DrawSpriteString       = 0x080AC334   # u16 string -> OAM sprites (running-buffer rewrite target)
Location_GetNameCellFromCoords = 0x080B968C # (mapId,a,coord,coord) -> ptr into location-name table cell
                                           # (save-screen + automap marker-list location names)
Font_GetGlyphBitmap         = 0x080ABF24   # decode one glyph to 4bpp, returns buffer
Font_BlitGlyph              = 0x080AC62C   # 4bpp OR-blit into a 32-tile-wide canvas (dst base = arg)
OAM_EmitSprite              = 0x080AA1F4   # emit one OAM sprite from a 3-u16 template
INTRO_DISCLAIMER_STR_PTR    = 0x080D6868   # literal-pool slot the boot fiction-disclaimer renderer
                                           # (Intro_DrawDisclaimer 0x080D67BC) reads for its glyph string;
                                           # the intro_disclaimer section repoints it to the pooled English
INTRO_DISCLAIMER_FNPTR      = 0x08509EEC   # intro cutscene step record's fn-ptr -> 0x080D67BD; repointed to
                                           # cave_introdisclaimer so the disclaimer draws proportional English
Equipment_GetRecord36_MidRange = 0x080BF354
Item_GetRecord32            = 0x080BF418
Action_GetRecord            = 0x080BF5C0   # action/skill id -> record; name is inline u16[8] at record+6
Combatant_GetRecord         = 0x080BF648   # demon id -> combatant_table record; inline name (skills) at +0x22
CpuFastSet                  = 0x0815CAF4   # CpuFastSet wrapper (src, dst, len/mode)

# ---------------------------------------------------------------------------
# Event/dialogue script VM (Script_ExecOpcode @0x0813db8c) — for the dialog repointer.
# The VM runs inline bytecode: code = *(u16*)(SCRIPT_BASE_PTR)[*(u16*)SCRIPT_PC]; opcode = code-0x300;
# opcode<0x171 -> g_ScriptOpcodeHandlerTable[opcode].  Our cave handler (cave_dialog.c) registers as
# opcode 0x0350 (an unused slot) and JUMPS the VM into a pooled English string (base=ptr, pc=0); that
# string's own 0x0301 ends the message exactly as the original would (we never touch the level/return
# stack).  ScriptOp_EndMessage (0x0301) handles real-end vs caller-return itself.  See docs/text-extraction.md.
SCRIPT_BASE_PTR   = 0x03006950   # -> current script base (u16*); ROM or RAM
SCRIPT_PC         = 0x0203DB40   # u16 PC index into base
SCRIPT_OP_TABLE   = 0x087913DC   # opcode->handler table (u32 each); slot 0x50 = our expanded-text op
SCRIPT_EXPAND_CODE = 0x0350      # sentinel opcode = expanded text (slot 0x50, verified unused in script)

# Battle UI message system: BattleMenu_SetMode(mode, msgPtr) stores msgPtr at struct(0x0203c200)+0x7e8
# and (mode 4/8/9) copies the message into battle-state buffers (+0x7ec/+0x86c) that the battle-UI loop
# renders.  patch_battlemenu hooks its command-description call site to resolve a 0xFFFF+pool sentinel in
# the message pointer (so over-budget English menu text draws from the pool through the existing path).
BattleMenu_SetMode = 0x080EA37C

# Battle message template table (FUN_080ec038: table[id] -> template ptr).  ~393 entries (ids 0x24-0x3B3)
# of full templates in 0x0812xxxx — combat log, encounter, battle-menu/shop commands, prompts.  FUN_080ebca4
# expands a template (subs 0x316-0x325 = actor/skill/item/count) into a 128B buffer, drawn via
# Battle_ShowMenuMode.  tr.pack repoints table[id] -> pooled English (no runtime hook).  See docs.
BATTLE_MSG_TABLE = 0x0876FB54

# Template expander: expands {=2403}/{=2003} name/skill/item/count subs into the 128B compose
# buffer.  patch_typewriter retargets the flee composer here; dump/{trace_help,verify_literal}_
# consumers.py reference it too.  Single source of truth for the address.
Menu_ExpandListTemplate = 0x080EBCA4

# Battle action-fragment table (the battlefrag block's main entry point): slot = action byte
# (combatant+0x5c) - 0x40, bytes 0x40-0xC5.  0x40-0x9F = skill-result template strings
# (0x08125xxx, owned by other sections); 0xA0-0xBF = the status-result は/を pairs;
# 0xC0-0xC5 = the verb fragments (gun/attack/summon/protect/COMP-return).  Read by the three
# plain-fragment builders that patch_namemove hooks (Battle_BuildStatusResultText 0x080EB16C,
# Battle_BuildCombatActionList 0x080EB220, Battle_BuildDefeatedTargetText 0x080EB570).
# tr.pack derives the movable-[name] fragment set from these slots + the defeated literal.
BATTLEFRAG_ACTION_TABLE       = 0x086BED5C
BATTLEFRAG_ACTION_TABLE_COUNT = 0x86          # bytes 0x40..0xC5 inclusive
BATTLEFRAG_DEFEATED_SLOT      = 0x080EB5EC    # code literal -> を倒した fragment (auto-repointed)
BATTLEFRAG_PROMPT_SLOT        = 0x080EAE04    # Battle_BuildActorPrompt code literal -> はどうしますか
                                              # fragment (auto-repointed; hooked by patch_namemove so
                                              # the prompt's mid-string [name] can be spliced)

# Name-entry charset + default human names (patch_defaultnames).  Player names are 8 INDEX bytes
# (Combatant+0x00..07, 0xFF = pad) decoded through g_wNameCharsetTable (index -> glyph token).
# The base table has uppercase only (A-Z @ idx 0x17-0x30); the patch copies it to FARDATA and
# appends lowercase a-z at idx 0xE0+ (decoders are unbounded; only the 0xDF-capped token->index
# encoders can't see them, and no flow encodes lowercase).  See docs/names.md.
NAME_CHARSET_TABLE  = 0x081A5A6C   # g_wNameCharsetTable: 224 u16 glyph tokens
NAME_CHARSET_COUNT  = 224
NAME_CHARSET_REFS   = [0x080C0358, 0x080C03A4, 0x080C03CC, 0x080C041C]  # all 4 literal pools -> table
NAME_LOWER_IDX      = 0xE0         # extended charset index of 'a' (b..z follow)
DEFAULT_NAMES_A     = 0x081A5A00   # 4x8B new-game human defaults: ホーク/ヒロコ/ベス/カオスヒーロー
DEFAULT_NAMES_B     = 0x081A6244   # 4x8B story-join defaults: ギメル/ダレス/ザイン/アレフ

# ---------------------------------------------------------------------------
# Name-entry screen grid (patch_nameentry) — EN-friendly categories.  See docs/name-entry-rework.md.
# ---------------------------------------------------------------------------
# The screen is an Object task list from descriptor 0x084F3074 (NameEntry_InitAllyNameInput
# 0x080d1e48 builds it).  The grid is a SEPARATE table of u16 GLYPH TOKENS, 11 cols x 25 rows
# (spacer cell = 0x003F), drawn by NameEntry_DrawGrid 0x080d15dc (4 rows visible, scrolled by
# work+8).  The right-panel "categories" are just vertical scroll bookmarks (0/10/20) set by
# NameEntry_HandleInput 0x080d1828.  A-press: name[i] = NameEntry_TokenToCharsetIndex(grid cell)
# -- but that scanner stops at the first 0-token charset entry (0xD3-0xDF are 0), so it can't return
# a lowercase index (0xE0+).  patch_nameentry rewrites the token table to an EN 3-page layout, adds a
# PARALLEL charset-INDEX byte table the A-press reads directly, and repoints the input handler.
NAMEENTRY_GRID_TOKENS = 0x084F2DDC  # 11*25 u16 glyph tokens (display), ends at the category text 0x084F3002
NAMEENTRY_GRID_COLS   = 11
NAMEENTRY_GRID_ROWS   = 25
NAMEENTRY_INPUT_TBL_LITERAL = 0x080d18b8  # literal in NameEntry_HandleInput -> token table; repoint to index table
NAMEENTRY_APRESS_LSL  = 0x080d188c  # `lsl r0,r0,#1` (u16 stride) -> nop (byte table)
NAMEENTRY_APRESS_LDRH = 0x080d1890  # `ldrh r0,[r0]` -> `ldrb r0,[r0]`
NAMEENTRY_APRESS_BL   = 0x080d1892  # `bl NameEntry_TokenToCharsetIndex` -> nop;nop (read index directly)
# Vertical-scroll layout: patch_nameentry packs the 3 pages with ONE blank row between (bookmarks
# 0/4/8) and tightens the free-scroll clamps in NameEntry_HandleInput so scrolling stops at the
# symbols block (no empty tail).  Each site is a Thumb `mov/cmp rN,#imm8` whose imm8 we rewrite.
NAMEENTRY_BOOKMARK_LO = 0x080d1a28  # `mov r0,#0xa`  Lowercase category -> scrollY
NAMEENTRY_BOOKMARK_SY = 0x080d1a32  # `mov r0,#0x14` Symbols category -> scrollY
NAMEENTRY_DOWNCAP     = 0x080d192e  # `cmp r0,#0x18` down-scroll cap (blocks when scrollY+4 > imm)
NAMEENTRY_PAGEROWS_R3 = 0x080d182e  # `mov r3,#0x19` grid-row count for the R/L page-scroll clamp (caps scrollY at r3-4)
NAMEENTRY_DOWNARROW   = 0x080d1792  # `cmp r0,#0x18` down-ARROW visibility (NameEntry_DrawGrid: hide when scrollY+4 > imm) — match the down cap

# Far data block: 0x00 inter-asset padding @0x0869C26A (3935 B) — OUT of Thumb BL range, so pure
# DATA only (tables read via literal pointers), never code.  One ROM pointer targets the run's
# tail (0x0869D1C4, ref @0x0858D170): stay below 0x0869D000.
FARDATA_NAMECHARSET = 0x0869C26C   # extended name charset copy (224+26 u16 = 500 B), ends 0x0869C460
# Equip stat-page label strings (patch_statpage): ~17 short EN glyph-token strings, absolute-ptr
# referenced from DAT_080d2xxx slots, so they live far (no BL-range cave-pool pressure).  Bump up
# from here; ample room below the 0x0869D000 ceiling.
FARDATA_STATLABELS  = 0x0869C480   # ~24 EN glyph strings, ends ~0x0869C50D
# Demon-dictionary NAME-page bucket labels (patch_dictsort): 11 EN glyph-token strings
# ("A","B-C",.."Y-Z","Other"), absolute-ptr referenced from the relabelled selector table.
FARDATA_DICTBUCKETS = 0x0869C580

# ---------------------------------------------------------------------------
# Demon-dictionary ("DDS dictionary") NAME-page sort (patch_dictsort)
# ---------------------------------------------------------------------------
# The NAME page is table-driven: build-mode 2 (Dict_BuildList 0x080db4a8) copies ids from this
# precomputed {u16 demonId, u16 group} array (stride 4, 0xFFFF-terminated) in order, tagging
# entries whose group != the selected category with bit 0x8000, and jumps the cursor to the
# selected group's first entry.  JP groups demons by first kana (10 groups 0-9; その他 = empty
# 11th).  patch_dictsort rewrites it IN PLACE: same 325 ids, re-sorted alphabetically by ENGLISH
# name, group = letter bucket (0-9; bucket 10 "Other" stays empty).  No runtime-sort code changes.
DICT_SORT_TABLE     = 0x08585C34   # {u16 id, u16 group} * 325, 0xFFFF-terminated
DICT_NAME_LABELS    = 0x0858367C   # NAME-page selector label-ptr table (11 slots)
# The in-game compendium (Cathedral of Shadows, drawer 0x08156xxx) SHARES DICT_SORT_TABLE (so it
# already inherited the EN alphabetical ordering) but has its OWN NAME-category label table: 10
# ptr slots (ア行..ワ行, no その他).  patch_dictsort repoints these to FARDATA_DICTBUCKETS[0..9]
# too; patch_skilllist VWFs the draw (0x08156888 -> label_str_vwf).
COMP_NAME_LABELS    = 0x087E32A0   # compendium NAME-category label-ptr table (10 slots)

# Demon "parent race" (族-suffixed clan family) name table, distinct from the 44-entry demon-race
# table g_wRaceNameTable (0x081A5C34).  The full-info detail screen's RacePanel (0x080dc6d0) shows
# BOTH: demon race via Race_GetName (already EN via names_race) AND parent race via
# ParentRace_GetName(0x080c069c) = parentId*0x10 + this base, where parentId =
# Race_GetParentId(0x080c09a4) maps the demon race -> one of 15 clans (神族/鬼神族/魔族/飛天/竜族/
# 鳥族/獣族/鬼族/精霊/邪霊/外道/人/マシン/樹霊/魔人).  Cells are 0x10 bytes, glyph-token strings,
# 0x0000-terminated, drawn fixed-pitch by Text_DrawStringTinted (sentinel-UNAWARE -> inline EN
# tokens only, <=7 glyphs).  patch_parentrace writes English in place.
PARENTRACE_NAME_TABLE = 0x081A5F24   # 15 cells * 0x10 bytes, ends 0x081A6014 (JP, left intact)
PARENTRACE_COUNT      = 15
# patch_parentrace overlays English without the inline 7-glyph cell limit: a 15-slot u32 ptr table
# + pooled EN glyph strings in far data; cave_dictname's dict_parentrace_vwf indexes the table by
# parentId (recovered from the JP cell ptr) and VWF-draws the pooled name (JP cell fallback).
FARDATA_PARENTRACE      = 0x0869C700   # 15*4 ptr table, then strings; ends well under 0x0869D000
# Demon-dictionary STATUS-screen stat labels (patch_dictstatus): ~13 pooled EN glyph strings
# (St/In/Ma/Vi/Ag/Lu, Atk/Hit/Def/Eva, "Mag Pwr"/"Mag Efc", ""), absolute-ptr referenced from the
# Font_DrawGlyphTinted literal pool @0x080dcbac (menutinted pointer hook draws them VWF).
# Sits in PARENTRACE's reserved tail slack (PARENTRACE ends ~0x0869C836).  Was 0x0869C940 — only
# 0x80 B before FARDATA_VISION, but the real pool is 134 B, so "Mag Efc" (last string) overran
# FARDATA_VISION by 6 B and got clobbered by "Extract a vision" ("Mag E"+"Extract a vision" bug).
FARDATA_DICTSTATLABELS  = 0x0869C8A0   # 134 B pool, ends ~0x0869C926, clears FARDATA_VISION (0x0869C9C0)
# DDS "素材補完" (Visionary) service prompt fragments (patch_vision): pooled EN glyph strings drawn
# by Text_DrawSpriteString from code literals @0x080dafe4/e8 + the no-materials error @0x080daa5c.
FARDATA_VISION          = 0x0869C9C0   # 3 prompts + 5 DDS-menu rows; ends ~0x0869CB12 under the ceiling
# Level-up screen "残りポイント" (Points left) label (patch_levelup): one pooled EN glyph string,
# drawn via Font_DrawGlyph's patch_menu pointer hook (the draw is retargeted Text_DrawString->
# Font_DrawGlyph so the pointer renders VWF and fits before the value column at x=0x88).
FARDATA_LEVELUP         = 0x0869CB20   # ends ~0x0869CB3C, under the 0x0869D000 ceiling
# Demon status-screen "NO ITEM" drop label (patch_noitemdrop): one pooled EN glyph string
# "(No item)", drawn VWF (tinted) by a cave replacing Status_DrawDropItem's f1a==0xFF branch.
FARDATA_NOITEM          = 0x0869CB40   # "(No item)" = 9 glyphs + term = 20 B, ends ~0x0869CB54
# Name-entry grid charset-INDEX table (patch_nameentry): 11*25 = 275 bytes, parallel to the token
# table; NameEntry_HandleInput's A-press reads the stored charset index directly from here (bypasses
# the 0-token-limited token->index scanner, so lowercase 0xE0+ works).  Absolute-ptr referenced.
FARDATA_NAMEGRID_IDX    = 0x0869CB60   # 275 B, ends ~0x0869CC73, under the 0x0869D000 ceiling
PARENTRACE_EN_PTRS      = FARDATA_PARENTRACE          # the u32[15] slot table
PARENTRACE_EN_POOL      = FARDATA_PARENTRACE + 15 * 4 # strings begin here

# ---------------------------------------------------------------------------
# RAM buffers / engine state
# ---------------------------------------------------------------------------
STATUS_TEXT_BUF   = 0x0200F874     # status-screen text tile buffer (name/drop/resist drawers)
SKILL_LIST_CANVAS = 0x030000B4     # skill/magic list BG canvas (FUN_081272cc)
GLYPH_CACHE_CTX   = 0x020360DC     # sprite glyph-cache ctx: +0 baseTile,+2 count,+4 capacity
GLYPH_STAGING     = 0x020361DC     # sprite glyph-cache EWRAM staging canvas

# Event-VM message window glyph-record list (patch_msgwin).  The stock list @0x0203D800 holds
# 64 x 8B {token, pixelX, pixelY, flag} records; the appender (EventVM_RunStep @0x0813dcbe)
# clamps the count to 0x3F and the per-frame renderer (hidden Thumb fn @0x0813ded8, 5th
# ARM-broken region) draws ONE OAM sprite per record through the 64-cell glyph sprite cache.
# JP pages (~51 glyphs) fit; EN half-width pages truncate.  patch_msgwin relocates the list to
# free top-of-EWRAM scratch (MSG_GLYPH_REC_MAX records), raises the appender clamp to match, and
# replaces the per-record draw loop with cave_msgwin's ink-packing strip composer (v2: one blit
# per glyph at its reflowed px, one sprite per 16px slice).  Cell cost is bounded by WINDOW
# GEOMETRY — 4 lines x 198px = ~52 of NCELLS=56 worst case — so the RECORD list, not the cell
# cache, is the page-capacity limit; 192 records = a full 4-line VWF page (~140 records at the
# measured ~5.7px avg EN advance) with narrow-glyph headroom.
MSG_GLYPH_LIST    = 0x0203D800     # stock list — DEAD in the EN build: all 18 literal pools are
                                   #   rewritten to MSG_GLYPH_LIST2 and a built-ROM scan (2026-07-02)
                                   #   found 0 pointers into 0x0203D800..D9FF and 0 reach-below
                                   #   bases.  The 512 B block is reused for MSG_ROWSAVE2 below.
MSG_GLYPH_REC_MAX = 192            # relocated-list capacity in RECORDS (one per drawn glyph).
                                   #   Drives the list/state sizes here, the appender + row-save
                                   #   clamps (patch_msgwin), and cave_msgwin's chunk[] array;
                                   #   pack-time backstop = sections.PAGE_GLYPHS.
MSG_GLYPH_LIST2   = 0x0203F400     # relocated list: 192 x 8B = 0x600 (free EWRAM scratch,
                                   #   zero-verified run 0x0203F400..0x0203FFFF) -> 0x0203FA00
MSG_GLYPH_COUNT   = 0x0203DB3E     # g_wMsgGlyphCount (unchanged address)
MSG_CLIP_Y        = 0x03006614     # s16 scroll/clip threshold the renderer tests record y against
MSGWIN_STATE      = 0x0203FA00     # cave state: u32 chunk[192] + u32 chunk2[33] + u8 pool[56] +
                                   #   5 u16 = 0x3C6 B (cave_msgwin compile-time-checks sizeof
                                   #   against MSGWIN_STATE_SIZE)
MSGWIN_STATE_SIZE = 0x3C8          # reserved span for MSGWIN_STATE (next tenant: REVEAL_PX)
SHOP_GLYPH_LIST   = 0x0203DA00     # the LIST-window record array (33 x 8B; shop buy/sell rows,
                                   # FUN_08133a80 writes it) — rendered by the hidden renderer's
                                   # second loop @0x0813DF44, replaced by cave_entry2
SHOP_GLYPH_COUNT  = 0x0300669C     # s16 record count for SHOP_GLYPH_LIST
MSG_ROWSAVE2      = 0x0203D800     # relocated choice-prompt row-save buffer (was 0x03006870 16
                                   # u16 + term, then 0x0203FB00 64 + term): now 192 u16 + term =
                                   # 386 B in the dead stock-list block (see MSG_GLYPH_LIST).
                                   # FUN_0812f198 saves the page's record tokens here,
                                   # FUN_0812f1e4 re-appends them after the choice-window
                                   # re-layout; caps raised in patch_msgwin to MSG_GLYPH_REC_MAX.
                                   # The 16-token cap silently DROPPED prompt tokens
                                   # ("＞What will you d", 2026-06-13)
SPRITE_TMPL_GLYPH = 0x0815EE18     # 3-u16 OAM template the stock glyph renderer passes to
                                   # Sprite_DrawSingle (pool @0x080AC330)
Font_ResetGlyphSpriteCache = 0x080AC0F0  # clear the glyph-sprite cache, set OBJ base tile + capacity
Font_CacheGlyphSprite = 0x080AC124 # alloc one cache cell + expand glyph into the staging canvas
Font_UploadGlyphSpriteTiles = 0x080AC198  # the staging->VRAM upload callback: length =
                                   # (cache count/16 + 1) cell-rows, then CLEARS the dirty
                                   # flag @ctx+6.  The upload is ONE-SHOT: only CacheGlyph
                                   # allocation arms it (DisplayList_Add + flag=1) -- a blit
                                   # into an EXISTING cell does NOT, so cave_msgwin re-arms
                                   # it after composing (found live 2026-06-13: typewriter
                                   # tail glyphs blitted into already-allocated strip cells
                                   # never reached VRAM -- "You're gratefu").
DisplayList_Add = 0x080A9C40       # register an 8-byte {state=1, type, dataPtr} display-
                                   # update entry (docs/engine-runtime.md); type 1 = call ptr
Combatant_DecodeName = 0x080C0344  # decode Combatant+0x00..07 charset indices -> glyph tokens
Math_IntToDigits8 = 0x080A9CC0     # value -> 8 decimal digit bytes (LSB first)
DIGIT_GLYPH_TABLE = 0x086BEF74     # u16 glyph token per decimal digit 0-9
COMPOSE_BUF = 0x0203CAEC           # the MessageBox composer family's output buffer
Battle_BuildRaceCountText = 0x080EB8DC   # 悪魔N体をしとめた composer (rigid splice -- replaced
                                   # by cave_resultmsg when the template carries sentinels)
Battle_BuildActorStatusText = 0x080EB71C # おっと！は平気だ composer (5+4 fixed shape -- ditto)
Battle_BuildRewardText = 0x080EB9EC      # EXP line composer: walks THREE consecutive strings
                                   # from the passed base ({n} / は{n} / のEXPを得た) around
                                   # name+digits -- replaced by cave_resultmsg's cave_reward
Battle_BuildValueRewardText = 0x080EBB20 # value-only reward composer (value, strs): walks the
                                   # base ({n}/を{n}マッカ手に入れた/...) splicing ONLY digits, no
                                   # name -- macca @0x080E9DA0, magnetite @0x080E9DF8 call sites;
                                   # replaced by cave_resultmsg's cave_valreward
Battle_BuildItemDropText = 0x080EBBF0    # item-drop composer (itemId, base): "{n}[item]を拾った";
                                   # call @0x080E9C90; replaced by cave_resultmsg's cave_itemdrop
ITEMDROP_JP_BASE = 0x08124452      # the stock item-drop base ("{n}を拾った") for the JP fallback
MessageBox_ComposeRaceNameText = 0x080EAA08  # victory line: race + species(+0x22 raw) + suffix
Battle_BuildDodgeText = 0x080EB618 # dodge composer (やった！\n<name>はかわした): rigid 5+name+5
                                   # splice into COMPOSE_BUF (returns it); reads its fragment from
                                   # the internal literal below.  Call @0x080F0EA0 (enemy attack
                                   # missed -> defender dodged) -> cave_resultmsg's cave_dodge.
Battle_DodgeTemplatePtr = 0x080EB6A0  # FUN_080eb618's internal fragment-ptr literal; system_battle_log
                                   # extra_refs repoints it to the pooled EN name-sentinel template
                                   # ("Yes!\n{=fffe} dodged!"), which cave_dodge reads + rebuilds.

# ---------------------------------------------------------------------------
# Typewriter pixel-pacing (patch_typewriter) — both message windows reveal text
# one UNIT per tick (battle: one stream TOKEN; event-VM: one glyph RECORD), so
# half-width English (~2x the glyphs/page of Japanese) scrolls ~2x slower in
# pixels, and the battle "[race] [name] xN" name (a single 0xF000|id MARKER
# token) pops in whole.  Fix = pace the reveal by PIXELS instead of units.
#   Battle: the mode-2/6 typewriter copies the FULL line each tick and advances
#   REVEAL_PX; cave_runtext clips its draw of the battle line buffers at
#   REVEAL_PX (so the marker name reveals glyph-by-glyph too).  The clip is
#   gated by REVEAL_STAMP == (frame & 0xffff): the worker stamps the current
#   frame each tick it runs, so static modes (which never run the worker) draw
#   unclipped automatically — no stale-clip after an interrupted message.
#   Event-VM: the per-glyph yield is skipped until REVEAL_STEP px have been
#   appended since the last yield (tracked via g_wMsgTextCol vs EV_LASTCOL).
REVEAL_PX        = 0x0203FDC8     # u16 cumulative ink px revealed this battle message
REVEAL_STAMP     = 0x0203FDCA     # u16 frame&0xffff the battle reveal worker last ran
EV_LASTCOL       = 0x0203FDCC     # u16 event-VM g_wMsgTextCol at the last typewriter yield
REVEAL_FINE      = 0x0203FDCE     # u16 flag (battle typewriter): 1 = reveal the current line PER-PIXEL
                                  #   (cave_strip blits incrementally up to REVEAL_PX) instead of the
                                  #   default pre-blit-whole-line + 16px-cell sprite clip.  Set by the
                                  #   reveal worker only when the message contains 0x315 pause tokens
                                  #   (the flee "...." ellipsis), so each narrow dot types out one at a
                                  #   time; cleared for normal lines so the encounter-intro/victory hot
                                  #   path keeps the O(K) pre-blit.  Free 2 B between EV_LASTCOL/NEGONAME.
NEGONAME_BUF     = 0x0203FDD0     # 8-u16 scratch the negotiation name-assembly fixed-8 copies read.
                                  #   cave_negoname now writes ONE demon-name MARKER here
                                  #   (NEGO_NAME_MARKER|id) + 0x70 pad; cave_msgwin expands it to the
                                  #   full NAME_TABLE[id] VWF string (length-flexible, no cap-8 trunc)
NEGO_NAME_MARKER = 0x0000F800     # demon-name marker for the EVENT-VM window (cave_msgwin): a distinct
                                  #   namespace from the item marker 0xF000|id (id < ITEM_COUNT 0x15A),
                                  #   so 0xF800|id (id < NAME_COUNT 0x17C) never collides.  cave_negoname
                                  #   emits it; cave_msgwin's marker branch resolves NAME_TABLE[id].
MARKER_CACHE     = 0x0203FDE0     # cave_markerlist per-chunk content cache: u32 lastFrame +
                                  #   u32 hash[8] (skip the re-blit when a chunk is unchanged;
                                  #   frame-gap-invalidated on screen re-enter).  40 B — ends exactly
                                  #   at RUNTEXT_STRIP.  idx4 (cs=24, no chunk) is lastHeaderFrame;
                                  #   idx9 is marker entryFrame; chunk hashes are idx 1-3,5-8.
RUNTEXT_STRIP    = 0x0203FE08     # cave_strip StripState for cave_runtext (battle/menu sprite
                                  #   text): magic+frame+floor/cap + 12 cell-packed slots. 0xC8 B.
VISION_STRIP     = 0x0203FED0     # cave_strip StripState for cave_vision's NPC material-list strip
                                  #   renderer (vis2_*): 0xC8 B (ends 0x0203FF98; 0x0203FF98..FFFF
                                  #   = the run's remaining FREE scratch).  Keyed by ITEM ID so a
                                  #   row's strip persists in VRAM across scroll.
REVEAL_STEP      = 24             # px revealed per tick.  Drives BOTH typewriter paths (strip
                                  #   reveal + the short-string per-glyph sprite reveal) via
                                  #   REVEAL_PX, so they stay in step.  JP glyph = 12-13px/tick;
                                  #   24 ~= 2 JP glyphs / ~4 half-width EN glyphs per tick.

# EWRAM scratch layout guards — the zero-verified run 0x0203F400..0x0203FFFF is fully packed,
# and a tenant growing past its reservation would corrupt its neighbour silently.  Fail at
# import instead (every build script imports rommap).
assert MSG_GLYPH_LIST2 + MSG_GLYPH_REC_MAX * 8 == MSGWIN_STATE
assert MSGWIN_STATE + MSGWIN_STATE_SIZE == REVEAL_PX
assert REVEAL_PX + 8 == NEGONAME_BUF                      # PX/STAMP/LASTCOL/FINE = 4 u16
assert NEGONAME_BUF + 16 == MARKER_CACHE
assert MARKER_CACHE + 40 == RUNTEXT_STRIP
assert RUNTEXT_STRIP + 0xC8 == VISION_STRIP               # sizeof(StripState) = 0xC8
assert VISION_STRIP + 0xC8 <= 0x02040000
assert MSG_ROWSAVE2 + (MSG_GLYPH_REC_MAX + 1) * 2 <= SHOP_GLYPH_LIST  # dead-block tenant fits
BMSG_STATE       = 0x0203C9E0     # battle message-box state object (0x0203C200 + 0x7E0)
BMSG_LINE_LO     = 0x0203C9EC     # state+0xC  = line-1 display buffer (clip range start)
BMSG_LINE2       = 0x0203CA6C     # state+0x8C = line-2 (reward) buffer; clip floor while a reward
                                  #   line types so the header (line-1, below this addr) stays unclipped
BMSG_LINE_HI     = 0x0203CAEC     # state+0x10C = compose buffer (clip range end, exclusive;
                                  #   [LO,HI) covers line-1 +0xC and line-2 +0x8C buffers,
                                  #   incl. the +2 leading-0x300 skip the line-2 tail does)
HELD_BUTTONS     = 0x030031D0     # g_wHeldButtons (bit 0 = A: typewriter fast-forward)
FRAME_COUNTER    = 0x030031BC     # g_dwFrameCounter (Main_GameLoop ++ each frame)
BATTLE_MSG_DELAY_TABLE = 0x086BEC94  # g_bBattleMsgDelayTable {2,1} frames/tick by msg speed
Settings_GetBattleMsgSpeed = 0x080C2B34  # -> 0/1 message-speed setting (delay-table index)


def write_header(path):
    """Emit these constants as a C header (RM_<NAME>) so the cave .c sources share one source of
    truth.  cave_cc generates this before compiling; the .c files #include it and add the Thumb
    low bit / casts themselves."""
    from pathlib import Path
    lines = ["/* Auto-generated from engine/script/rommap.py - do not edit. */", "#pragma once", ""]
    for k, v in sorted(globals().items()):
        if k.isidentifier() and not k.startswith("_") and type(v) is int:
            lines.append(f"#define RM_{k} 0x{v:08X}")
    Path(path).write_text("\n".join(lines) + "\n", encoding="utf-8")
