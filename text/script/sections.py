"""Declarative manifest of every translation section: one JSON file per ROM text source.

This is the single registry the text pipeline dispatches on. `tr.py extract` walks each
section's `source` spec; `tr.py pack` injects by its `route`; the coverage audit
enumerates the same specs. NOTHING in the pipeline may key behavior off a filename —
adding a text site = adding a Section here.

Source kinds (extractor selectors):
  name_bank       fixed-stride record sweep, inline name field
                  params: start, stride, name_off, name_max, count
  paired_records  record sweep with inline name + description pointer (skills, items)
                  params: start, stride, name_off, name_max, desc_ptr_off, count,
                          id_base (0 if ids are the record index), desc_max
  ptr_table       contiguous u32 pointer table(s) into terminated strings
                  params: tables = [(lo_addr, count_or_hi)], dedup ("text" | None), str_max
  bank_walk       sweep a glyph bank capturing maximal clean terminated strings
                  params: lo, hi, str_max, filter (optional predicate on (addr, term))
  msg_id_table    id -> template-pointer table (battle message templates)
                  params: table, count, target_lo, target_hi, str_max
  lore_table      compendium table: per-id string pointer (+ inline entries appended
                  by the story walker — see story_vm)
  story_vm        event-VM bank walk (opcode-aware); also feeds lore's inline entries
  literal_slots   hand-declared (string_addr -> [code-literal slot addrs]) entries;
                  fully deterministic, regenerated from the slot list
  none            hand-authored JSON; extract never regenerates it (curated)

Routes (injection mechanisms — each is one arm in tr.pack):
  inline        budget-capped in-place overwrite; over budget -> warn-skip
  sentinel      inline when it fits; over budget -> 0xFFFF at field[0] + pool ptr at +2
                (a hooked drawer resolves it; never use on a path without a hook!)
  name_table    pooled string + NAME_TABLE[id] (demon names; nested aff lines force-repoint)
  item_table    inline when it fits + ALWAYS mirror into ITEM_TABLE[id]
  ptr_repoint   dedup'd string; rewrite every pointer slot to the pooled English
  msg_table     BATTLE_MSG_TABLE[id] repoint (battle templates)
  story_expand  inline when it fits, else [0x0350, ptr] head -> pooled English (event VM)
  label         menu glyph-literal slots; over-length -> slot0 becomes a pool pointer
  literal_ptr   inline when it fits, else rewrite the declared code-literal slots to a
                pool ptr — NEVER the sentinel arm (the battle-event composer copy paths
                are sentinel-unaware; a 0xFFFF would be copied as garbage glyphs)
  block_rebuild battlefrag: rebuild the whole contiguous block in addr order in the pool,
                then auto-repoint every original fragment pointer (phase 2)

`order` pins pack/pool-allocation order (pooled string addresses depend on it).
`phase`: 1 = main per-field loop, 2 = block rebuild, 3 = mirror post-passes.
"""
from dataclasses import dataclass, field as dc_field

from engine.script import rommap


@dataclass(frozen=True)
class Source:
    kind: str
    params: dict = dc_field(default_factory=dict)


@dataclass(frozen=True)
class Mirror:
    """Post-pass: repoint parallel ROM tables that hold a JP-only copy of this section's
    strings (matched by JP text). `extra` adds translations for strings that exist only
    in the mirrored copy."""
    tables: tuple            # (table_addr, ...) — u32 ptr tables
    count: int               # entries per table
    extra: tuple = ()        # ((jp, en), ...)


# Event-VM window page budget in g_MsgGlyphList RECORDS (one per drawn glyph; name/number
# subs reserve their runtime expansion, see tr._atom_glyphs).  The runtime list holds
# rommap.MSG_GLYPH_REC_MAX (192) records, so this is a pure SAFETY BACKSTOP: window geometry
# (autowrap's rommap.EVENT_WRAP_PX lines x the 4-line _paginate cap) bounds a physically-fitting page at
# ~140-160 records of real English, so _paginate's record split should essentially never fire
# — pagination is governed by pixels/lines, the record cap only catches pathological
# narrow-glyph pages before the engine would truncate them on screen.  (History: 104 was the
# v1 pair-packing cell budget — 56 cells x 2 glyphs minus margin — kept while the runtime
# list held 128; both limits lifted 2026-07-02.)
PAGE_GLYPHS = 176
assert PAGE_GLYPHS <= rommap.MSG_GLYPH_REC_MAX - 15   # >= one name sub's worst under-count


@dataclass(frozen=True)
class Section:
    id: str                  # corpus/<id>.json and generated/readable/<id>.txt stem
    source: Source
    route: str
    desc_route: str = ""     # paired sections: route of the desc sub-field
    term: str = "0000"
    wrap_px: int = 0         # 0 = no auto-wrap
    wrap_jp_pitch: int = 0
    page_glyphs: int = 0     # event-VM window page budget in g_MsgGlyphList records —
    #   the engine stops appending at capacity, truncating the page on screen (found
    #   live 2026-06-12).  Nonzero = autowrap re-paginates: pages exceeding this many
    #   records are split at a line break with {WAIT}{PAGE} (the JP originals' own page
    #   idiom).  Use PAGE_GLYPHS (a backstop under the 192-record runtime list; the
    #   real per-page limit is _paginate's 4 px-measured lines).
    strip_manual_n: bool = False  # prose windows: dissolve hand-authored {n} into spaces before
    #   auto-wrapping (the bulk translation placed manual breaks mimicking JP line structure,
    #   which STACK with autowrap's px-budget breaks since autowrap only ADDS breaks). Soft
    #   breaks become spaces; {n} adjacent to a structural opcode / {WAIT} / {PAGE} / blank line
    #   is kept. Only the VWF event-VM windows opt in — never the rigid composer templates.
    curated: bool = False    # extract() never regenerates; audit enumerates from the JSON
    order: int = 0           # pack processing order (pins pool layout)
    phase: int = 1
    mirrors: tuple = ()      # Mirror specs (phase 3)
    extra_refs: dict = dc_field(default_factory=dict)
    #   ^ string addr -> (slot addr, ...): extra ROM pointer slots (code literals /
    #     handler-record fields) that reference this section's strings OUTSIDE its main
    #     mechanism and would otherwise keep reading the JP original. pack() rewrites
    #     each slot to the same pooled English it allocated for the string. Slots are
    #     declared (never scanned blind) and each consumer must be verified to treat
    #     the pointer with the same stream semantics as the main mechanism.
    sentinel_gate: dict = dc_field(default_factory=dict)
    #   ^ legacy stage-A gate for the mixed `system` section: the sentinel arm is allowed
    #     only for fields with addr >= min_addr and term == term. Removed by the stage-B
    #     split (system_menu gets route="sentinel" outright).
    notes: str = ""


SECTIONS = [
    # ---- battle message templates -------------------------------------------------
    # FUN_080ec038 table (BATTLE_MSG_TABLE 0x0876FB54), id -> template ptr. Visible
    # combat-log / encounter / battle-menu / prompt messages (full templates with
    # substitution codes), expanded by FUN_080ebca4. Dedup by text; packed by
    # repointing table[id] -> pooled English (no runtime hook needed).
    Section("battle", Source("msg_id_table",
                             dict(table=0x0876FB54, count=0x3C0,
                                  target_lo=0x08120000, target_hi=0x08128000, str_max=80)),
            route="msg_table", term="0301", wrap_px=194, wrap_jp_pitch=12, order=10,
            # 25 verified out-of-table refs to template strings (found 2026-06-11 by
            # dump/attic/scan_battle_literals.py; consumers checked by
            # dump/attic/verify_literal_consumers.py + Ghidra). Each site loads the
            # string address directly — bypassing the
            # BATTLE_MSG_TABLE repoint — so these prompts stayed JP ("partial coverage"):
            # the item/magic-select prompts, COMP/analyze errors, stair prompts (field
            # dialog path, opcode tail preserved in the replaces), the negotiation
            # "spoke to the demon" line, and the two flee messages (ComposeWrappedText
            # path, same window/stream semantics). NOT declared (and why):
            #   0x0812B100/0x0812C3B4 -> FUN_0812e780 param_3 is dead (never displayed);
            #   0x08165250/0x08165298 (Mapper/Core Shield expiry) -> no Thumb ldr found,
            #     unknown reader in the 0x0816xxxx sprite-list region — LEAD;
            #   96 slots in g_pBattleActionFragTable 0x086BED5C..0x086BEED8 (ids 818-913
            #     enemy-action lines) -> consumer is the plain-fragment builder family,
            #     whether it expands {=2403} is unverified — LEAD (these also have live
            #     BATTLE_MSG_TABLE ids, so the table path shows English already).
            extra_refs={
                0x0812490C: (0x080EC410,),                # COMPは使えません
                0x08124A50: (0x080F3638, 0x080F3708),     # NO DATA (analyze)
                0x08124A62: (0x080F3468, 0x0812A820),     # アナライズできる悪魔はいません
                0x08124BD2: (0x0812B514,),                # 使えるアイテムは持っていません
                0x08124CC8: (0x0812B594,),                # どのアイテムを使いますか？
                0x08124CE6: (0x0812BF50,),                # どのアイテムを捨てますか？
                0x08124D5E: (0x0812B088,),                # 〜は〜を使った
                0x08124D72: (0x0812B874, 0x0812CAD8, 0x0812EE24),  # 誰に使いますか？
                0x08124DBC: (0x080B14A0,),                # 階段をのぼりますか？ (field)
                0x08124DD8: (0x080B158C,),                # 階段をおりますか？ (field)
                0x08124EFA: (0x0812C148,),                # 誰も魔法を使えない
                0x08124F12: (0x0812C178,),                # 誰の魔法を使いますか？
                0x08124F2C: (0x0812C744,),                # どの魔法を使いますか？
                0x08124F46: (0x0812C6B0,),                # 使える魔法がありません
                0x08124F60: (0x0812C6C8,),                # 魔法を使える状態ではありません
                0x0812507E: (0x0877829C, 0x0877A8BC),     # 属性が違うので呼び出せない
                0x08126254: (0x080EC85C,),                # 逃げだした (got away)
                0x081262BE: (0x080EC874,),                # 逃げだした (tripped)
                0x0812634E: (0x080EC4A0,),                # 悪魔に話しかけた
                0x08126368: (0x080E9118,),                # みんな一生懸命独っている
                0x081263D6: (0x08770088,),                # やった！〜はかわした (dodge; handler-record
                                                          #   slot @0x08770088, not the msg_table)
            }),

    # ---- battle action fragments (hand-curated) -----------------------------------
    # Short fragments copied into a buffer with the actor name PREPENDED. Reached by a
    # patchwork of small tables (g_pBattleActionFragTable 0x086BED5C), code literals,
    # and skip-null walks, so the whole contiguous block is rebuilt in the pool in addr
    # order and every original fragment pointer auto-repointed (phase 2). Every replace
    # is a full template with exactly one [name]: leading = engine-prepended (stripped);
    # elsewhere = the 0xFFFE moved-name sentinel spliced by cave_namemove ("Defeated
    # [name]") — only on fragments reached via the three hooked builders (tr.pack
    # validates against the ROM table). One [item]/[skill]/[damage] insertion sentinel
    # (0xFFFF) allowed on leading-[name] entries. "standalone": true = a slot pointing
    # mid-string gets its own pooled copy (kept OUT of the blob so skip-null walk
    # contiguity is preserved).
    Section("battlefrag", Source("none"), route="block_rebuild", curated=True,
            wrap_px=194, wrap_jp_pitch=12, order=20, phase=2),

    # ---- negotiation dialogue ------------------------------------------------------
    # Pointer-table slots 0x08032DE0..0x08035BB4 into the event bank. Aggregated by
    # TEXT: one entry per unique line carrying every pointer slot (translate once,
    # lands everywhere).  ws_fold=True: cosmetic {n}/full-width-space variants of the
    # same shop/greeting line fold into one entry (they re-wrap identically given
    # strip_manual_n — see tr._ws_dedup_key).
    Section("dialogue", Source("ptr_table",
                               dict(tables=((0x08032DE0, 0x08035BB4),), dedup="text",
                                    ws_fold=True, str_max=240)),
            route="ptr_repoint", term="0301", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=30),

    # ---- demon compendium lore -----------------------------------------------------
    # Per-demon table @0x08583E84 (stride 0x14), lore-string PTR @+0 -> bank @0x08009C4E+.
    # Plus inline compendium entries found in the event bank by the story walker
    # (matched by the 出身地　　： template) — appended here so compendium text stays
    # together. Repointable -> any-length English.
    Section("lore", Source("lore_table",
                           dict(table=0x08583E84, stride=0x14, count=0x148, str_max=800,
                                appended_by="story")),
            route="ptr_repoint", order=40),

    # ---- composite/confirm menu prompts (hand-curated) -----------------------------
    Section("menu_comp", Source("none"), route="sentinel", curated=True, order=50),
    Section("menu_config", Source("none"), route="sentinel", curated=True, order=60),

    # ---- element/attribute names ----------------------------------------------------
    # Equip-screen 属性 value + combatant 相性 type names (ノーマル/対火炎…, boss types).
    # 0x0E stride, right-aligned full-width-space pad, 6-glyph field, 67 entries (last =
    # 究極 @0x084F06C8). Indexed by EquipmentRecord36.bCategory*0xE (FUN_080cd87c).
    # Do NOT extend past 0x43: the narrow copy follows immediately on a different grid.
    Section("menu_element", Source("name_bank",
                                   dict(start=0x084F032C, stride=0x0E, name_off=0,
                                        name_max=6, count=0x43)),
            route="sentinel", order=70),
    # Narrow (abbreviated) variant right after: 0x0A stride, 4-glyph right-aligned cell,
    # only equipment categories 0-15 ever drawn (FUN_080cd8c4, patch_element_narrow).
    Section("menu_element_narrow", Source("name_bank",
                                          dict(start=0x084F06D6, stride=0x0A, name_off=0,
                                               name_max=4, count=0x10)),
            route="sentinel", order=80),

    # ---- fixed menu labels (hand-curated) -------------------------------------------
    # Glyph literals in draw code; entries carry slots [[lit,x],…] and optional move[x,y]
    # (consumed by patch_positions).
    Section("menu_status", Source("none"), route="label", curated=True, order=90),

    # ---- demon-dictionary "parent race" clan names (patch-owned) ---------------------
    # Consumed by patch_parentrace (writes a pooled-EN ptr table to far data; cave_dictinfo
    # VWF-draws it on the full-info detail screen), NOT by tr.pack.  Registered only so the
    # manifest guard accepts the JSON in text/corpus/. phase=2 + a non-block_rebuild
    # route => every tr.pack loop skips it (the main loop is phase==1, the phase-2 loop filters
    # block_rebuild, phase-3 acts only on mirrors).  Entries are {id, original, replace}.
    Section("names_parentrace", Source("none"), route="label", curated=True, phase=2, order=95),

    # ---- demon names (+ nested resist lines) ----------------------------------------
    # Combatant table 0x0819CB74, stride 0x60, name @+0x22 (6 glyphs + term; +0x30 is f30
    # status data). count 0x17C: real demons are ids 0-379 (both Pascals at 368 & 375).
    # Route: pooled string + NAME_TABLE[id] (patch_name status screen; battle text via
    # MARKER_TABLE/patch_spritebuf). Nested aff1/aff2 resist lines @+0x32/+0x48 (single
    # reader FUN_080cd2a0, hooked by patch_resist) FORCE-repoint so the hooked drawer
    # always takes the VWF path.
    Section("names_demon", Source("name_bank",
                                  dict(start=0x0819CB74, stride=0x60, name_off=0x22,
                                       name_max=6, count=0x17C,
                                       aff_offsets=((0x32, 11), (0x48, 11)))),
            route="name_table", order=100),

    # ---- equipment names -------------------------------------------------------------
    # EquipmentRecord36 table 0x08198B74 (ids 0x00-0xCF, weapons/armor, no description),
    # name @+0x14. Inline when it fits + ALWAYS mirrored to ITEM_TABLE[id]
    # (patch_drop/patch_itemname draw from the table; inline feeds unhooked drawers).
    # name_max=7, NOT 8: the inline field is word[8] = 16 bytes filling the record to its
    # 36-byte end, and a written name needs its 0x0000 terminator WITHIN those 8 slots, so
    # only 7 glyphs are usable. The pack budget is (max+1)*2; max=8 would write 18 bytes and
    # overrun 2 bytes into the NEXT record's +0x00 (bClassAndFlags) / +0x01 (Def/Atk),
    # zeroing them (e.g. "Pahourat" id 187 clobbered Leather Boots id 188). Matches the
    # identical 16-byte race-name field below, which correctly uses name_max=7.
    Section("names_equipment", Source("name_bank",
                                      dict(start=0x08198B74, stride=36, name_off=0x14,
                                           name_max=7, count=0xD0)),
            route="item_table", order=110),

    # ---- item names + descriptions ----------------------------------------------------
    # ItemRecord32 (ids 0xD0-0x159): 138 records from 0x0819A8B4, name @+0x0C, desc PTR @+0x1C.
    # name_max=7 for the same reason as names_equipment: the inline name field is 16 bytes
    # (+0x0C..+0x1C) and the terminator must fit within it — max=8 would overrun 2 bytes into
    # the +0x1C description pointer. (Latent today: no item name is currently 8 glyphs.)
    # wrap_px 176: the description box holds 15 fullwidth glyphs on one line (180px — the
    # shipped JP single-line skill descs fill exactly to there; items share the box), so
    # auto-wrap English descriptions to ~10px under that (the EN left-bearing-overhang
    # margin, same convention as the story/dialogue windows). Descriptions are repointed
    # (any length), so this only governs line breaks, never a budget. Item NAMES (<=7
    # glyphs) never reach the budget, so the section-wide wrap is a no-op for them.
    # NB: keep descriptions to <=2 lines (the box is 2 lines tall) — condense any English
    # that wraps to 3 (the JP used up to 3 short fullwidth lines).
    Section("names_item", Source("paired_records",
                                 dict(start=0x0819A8B4, stride=32, name_off=0x0C,
                                      name_max=7, desc_ptr_off=0x1C, desc_max=200,
                                      id_base=0xD0, count=0x8A, skip_empty=True)),
            route="item_table", desc_route="ptr_repoint", wrap_px=176, wrap_jp_pitch=12,
            order=120),
    # count 0x8A (138, not 0x80): the table runs to the skills/action table @0x0819B9F4.
    # Records 128-137 (ids 0x150-0x159) are special inventory items (Bodhi Leaf, Copper
    # Circuit, Lily Corsage, Ice Crown, King's Sunglasses, ...) — uncovered before this.

    # ---- race/clan names ---------------------------------------------------------------
    # 45 entries (race id 0-44), 16-byte records, name @+0 (whole record is the name).
    # max 7: no pointer table, written in place; over-budget English -> 0xFFFF sentinel +
    # pool (patch_race, status top bar). The encounter/ID battle lines use two SEPARATE
    # parallel tables pointing at a JP-only copy @0x08123590+ -> mirrored in phase 3.
    # 2026-06-13: mirror extended from the 27-entry tails (0x086BECDC/0x08777E28) to the
    # FULL 44-slot tables (the first 17 races 神霊..竜王 stayed JP in battle contexts);
    # the battle copy abbreviates two races -> `extra` (メシア=メシアン, ガイア=ガイアーズ;
    # "Gaean" = the names_race spelling, unified repo-wide 2026-06-13).
    Section("names_race", Source("name_bank",
                                 dict(start=0x081A5C34, stride=0x10, name_off=0,
                                      name_max=7, count=45)),
            route="sentinel", order=130,
            mirrors=(Mirror(tables=(0x086BEC98, 0x08777DE4), count=44,
                            extra=(("ガイア", "Gaean"), ("メシア", "Messian"))),)),

    # ---- skill names + descriptions ----------------------------------------------------
    # Action table 0x0819B9F4, stride 0x1C, name @+6 (8 glyphs, 0xFFFF sentinel via
    # patch_names), desc PTR @+0x18.
    # wrap_px 176: same description box as items (15 fullwidth = 180px single-line in JP).
    # Most shipped skill descriptions are ONE long line with no break, so unwrapped English
    # ran off the right edge — auto-wrap fixes that. Keep to <=2 lines (condense the few EN
    # lines that wrap to 3). Skill NAMES (<=8 glyphs) never reach the budget.
    Section("skills", Source("paired_records",
                             dict(start=0x0819B9F4, stride=0x1C, name_off=6, name_max=8,
                                  desc_ptr_off=0x18, desc_max=160, id_base=0, count=0xA0)),
            route="sentinel", desc_route="ptr_repoint", wrap_px=176, wrap_jp_pitch=12,
            order=140),

    # ---- story / event script -----------------------------------------------------------
    # Event-VM bank 0x08016000..0x080A8C00 walked opcode-aware (controls kept as tokens,
    # opcodes byte-exact {=hex}); dedup by text. Inline when it fits, else the message
    # head becomes [0x0350, ptr] (custom opcode, patch_dialog cave).
    Section("story", Source("story_vm",
                            dict(lo=0x08016000, hi=0x080A8C00,
                                 skip_tables=((0x08032DE0, 0x08035BB4),
                                              # location-name table (own section below) —
                                              # the walker used to mis-capture it as one
                                              # giant phantom message @0x080A548C
                                              (0x080A548C, 0x080A96CC)),
                                 min_glyphs=3)),
            route="story_expand", term="0301", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=150),

    # ---- save/load + map-banner location names ------------------------------------------
    # Fixed-stride name table 0x080A548C: 530 cells x 0x20 = 16 u16 glyph tokens, NO
    # terminator; pad token = '@' 0x57 (cell 0 pads with full-width space 0x3F). Readers
    # index by map id (save/load slot header, the map/area location banner — the
    # "イェソドの街" class), so cells can never be repointed: route=inline with `pad`
    # semantics (pack pads English to exactly 16 tokens and writes no terminator; over
    # 16 tokens = warn-skip). The table tail (cells 445+, beyond the story walker's hi)
    # includes the endgame dungeons + 17 world-map region names.
    Section("location_names", Source("name_bank",
                                     dict(start=0x080A548C, stride=0x20, name_off=0,
                                          name_max=16, count=530, pad=0x57)),
            route="inline", order=155),

    # ---- system bank: menu/command/error text -------------------------------------------
    # The battle/system message bank 0x081236FC..0x0812682E interleaves message strings
    # with jump tables / code; it held ONE mixed section ("system") until 2026-06-10,
    # split three ways by injection route. This section = the menu/command/error text
    # (addr >= 0x08123800, 0000-terminated).
    #
    # ROUTE CHANGE 2026-06-11 (second session): was route="sentinel" on the assumption
    # that everything here flows through BattleMenu_SetMode (whose entry hook resolves
    # the 0xFFFF sentinel). A full ref scan (scan_sentinel_refs.py) disproved it: of the
    # 77 over-budget entries, 37 have NO pointer reference anywhere in ROM (2-aligned
    # scan) — they are walk/composition-reached and their copy paths drew the raw
    # sentinel as garbage glyphs (the user-reported "悪魔を倒した　７２０<garbage>マッカ"
    # kill-reward line). Now: over-budget entries with refs declared below are slot/
    # literal-repointed (original JP left intact inline — never a sentinel); the
    # unreferenced rest stay inline-budget-only (JP until the deferred walk-path
    # mechanism exists). Ref classes, each verified:
    #   0x08777Exx/0x08777Fxx/0x08778xxx/0x08779xxx = menu help-pointer arrays + handler
    #     record fields (consumers traced to BattleMenu_SetMode(4, arr[cursor]) by
    #     trace_help_consumers.py — a clean repointed slot works there too);
    #   0x086BE638/0x086BEC4C = encounter/negotiation menu-row table slots;
    #   0x080Exxxx/0x080Fxxxx/0x0812Axxx = pc-relative ldr literal pools of the battle
    #     result/menu composers (copy semantics: pooled EN is copied like the JP was).
    Section("system_menu", Source("bank_walk",
                                  dict(lo=0x08123052, hi=0x0812682E,
                                       filter=dict(addr_ge=0x08123800, term="0000"),
                                       exclude_owned_by=("system_battle_events", "battle",
                                                         "battlefrag", "menu_comp",
                                                         "menu_config"))),
            route="literal_ptr", order=160,
            extra_refs={
                0x08123C9A: (0x086BE638, 0x086BEC4C, 0x08777EA0),  # COMPを使用します
                0x08123CB0: (0x08777EA4,),   # 魔法を使用します
                0x08123CC2: (0x08777EA8,),   # アイテム使用／整頓…
                0x08123CE6: (0x08777EAC,),   # 装備を変更します
                0x08123CF8: (0x08777EB0,),   # 詳細ステータス…
                0x08123D14: (0x08777EB4,),   # 隊列を変更します
                0x08123D26: (0x08777FE0,),   # COMP内の仲魔を召喚…
                0x08123D44: (0x08777FE4,),   # 仲魔をCOMP内に戻します
                0x08123D60: (0x08777FE8,),   # 仲魔をパーティーから外します
                0x08123D7E: (0x08777FEC,),   # MAPを表示します
                0x08123DA6: (0x08777FF0,),   # パーティー全員の回復…
                0x08123DD0: (0x08777FF4,),   # 倒した悪魔を分析します
                0x08123E0C: (0x08779EB8,),   # 中断セーブを行います
                0x08123E22: (0x08779EBC,),   # セーブデータをロードします
                0x08123E3E: (0x08779EC0,),   # 設定メニューを起動します
                0x08123E58: (0x08778ACC,),   # 種族別に並べて表示します
                0x08123E96: (0x08778AD4,),   # レベル順に並べて表示します
                0x08123EB2: (0x08778AD8,),   # 属性別に並べて表示します
                0x08124140: (0x087782B8, 0x0877A8D8),  # マッカが足りません
                0x08124182: (0x08129F88,),   # は{n}COMPに戻った
                0x081241B0: (0x080F0DF0,),   # しかし魔法は封じ込まれている
                0x081241D0: (0x080F0E04,),   # MPが足りない
                0x081241F0: (0x080F210C,),   # は{n}跳ね返した
                0x08124200: (0x080F2188,),   # しまった跳ね返された
                0x08124218: (0x080F1FCC,),   # おっと！はずしてしまった
                0x08124264: (0x080F08CC,),   # は力尽きた
                0x08124284: (0x080E98F4,),   # を倒した (victory composer)
                0x081242EC: (0x080F1E60,),   # 必殺の一撃！！
                0x081242FC: (0x080F1E7C,),   # 会心の一撃！！
                0x0812430C: (0x080EB060,),   # を覚えた
                0x08124316: (0x080F1BFC,),   # すでに効いている
                0x08124328: (0x087782F0, 0x0877A910),  # これ以上修復悪魔は…
                # ---- the reward/result splice composers (traced 2026-06-13; their
                # templates have RIGID splice shapes — replaces must match EXACTLY,
                # see patch_battlename's composer notes):
                0x08124234: (0x080F1FF8,),   # おっと！{n}は平気だ — Battle_BuildActorStatusText:
                                             #   EXACTLY 5 prefix + name + EXACTLY 4 suffix tokens
                0x08124270: (0x080E9A2C,),   # 悪魔{n}体をしとめた — Battle_BuildRaceCountText:
                                             #   tokens[0..2] skipped, name+digits spliced, [3],[4],
                                             #   injected token (countnl cave: EN='o'), [5..]
                0x0812434A: (0x080E9FD8,),   # 、{n}の{n}レベルが上がった — Battle_BuildNamePrefixText:
                                             #   [u16 COUNT][prefix]name[suffix..0] — replace head {=0100}
                0x08124298: (0x080E9F48,),   # のEXPを得た — the slot holds the BASE of the three
                                             #   reward strings ({n}/は{n}/のEXPを得た); repointed at
                                             #   THIS entry's pooled replace, which must be the FULL
                                             #   sentinel template for cave_reward
                                             #   ("{=feff} gained {=ffff} EXP!")
                0x081243F2: (0x080E9DB8,),   # Nマッカ手に入れた — slot holds the value-reward base
                                             #   0x081243EE; cave_valreward rebuilds from this
                                             #   entry's value-only template ("{=ffff} Macca obtained!")
                0x0812440E: (0x080E9E18,),   # Nマグネタイトを得た — slot holds base 0x0812440A;
                                             #   value-only template ("{=ffff} Magnetite obtained!")
                0x0812442A: (0x080E9D60,),   # N個の魔石を拾った — Life Stone-drop base 0x08124426
                                             #   (item id 0xE5=229); value template "Gained {=ffff} Life Stones"
                0x08124440: (0x080E9D5C,),   # N個の宝玉を拾った — Bead-drop base 0x0812443C (item id 0xDB=219)
                                             #   value template "Gained {=ffff} Beads"
                0x08124456: (0x080E9CAC,),   # [item]を拾った — slot holds the item-drop base
                                             #   0x08124452; cave_itemdrop rebuilds this entry's
                                             #   name-sentinel template ("Obtained {=fffe}") with
                                             #   the moved item name (ITEM_TABLE[id])
                0x0812437C: (0x0812A2E8,),   # と別れます よろしいですか？
                0x081243B0: (0x0812A398,),   # の死体を捨てました
                0x081243C6: (0x0812A37C,),   # と別れました
                0x08124460: (0x08778DF4,),   # アイテムを使用します
                0x08124476: (0x08778DF8,),   # アイテムを整頓します
                0x081244A4: (0x08778E00,),   # アイテムを廃棄します
            }),

    # ---- system bank: battle-log lines ---------------------------------------------------
    # The complement of system_menu in the same bank: 0x0301-terminated battle-log /
    # event lines. Their copy paths have no sentinel hook, so they are inline
    # budget-capped only (over-budget English stays JP — repoint mechanism deferred).
    # walk lo extended 0x081236FC -> 0x08123052 (2026-06-10): the strings before the
    # battlefrag block ("は呪われた", "剣で攻撃します", encounter/negotiation menu rows)
    # are reached via the 0x086BExxx table patchwork (live base literal 0x086BED5C
    # @0x080EB1EC; the individual tables have NO direct code refs). In-place inline
    # writes are mechanism-agnostic — every reader sees them — so they belong to the
    # bank-walk sections.
    #
    # 2026-06-13: slot-level repoint wired (the deferred-backlog pass). extra_refs below
    # = every battle-log string with a verified pointer ref (full 4-aligned ROM scan).
    # Ref classes, same as system_menu's: 0x086BE5xx/0x086BECxx = battle command-row /
    # help-pointer widget arrays (fn-ptr records 0x080E66xx/0x080E8xxx around them);
    # 0x0877Axxx = CONFIG menu handler-record string fields; 0x080Fxxxx = composer ldr
    # literals (capstone-verified: ldr r2,=str; bl Battle_BuildDamageDealtText/expander).
    # The 44 battle-copy RACE NAMES @0x08123590-0x081236B2 are NOT here — the extended
    # names_race Mirror repoints their two tables (0x086BEC98/0x08777DE4) by JP text.
    # Deliberately NOT repointed: 08123052 は斬りかかった (sole ref 0x086BEF5C sits in the
    # frag-table patchwork whose builder expansion is unverified — same skip as the 96
    # action-frag slots) and 081230BE やった！はかわした (consumer @0x080EB64E is a
    # fixed-width ldrh/strh record splice, not a ptr-follow).
    # 0812310C は{n}のダメージを受けた goes through Battle_BuildDamageDealtText, which
    # copies EXACTLY 2 fragment tokens before splicing the damage digits — its replace
    # must mark the digit position with the raw insertion sentinel {=ffff} (handled at
    # draw time by patch_battlename's dmgsplit cave; same convention as battlefrag's
    # [damage], e.g. " took{n}{=ffff} damage").
    Section("system_battle_log", Source("bank_walk",
                                        dict(lo=0x08123052, hi=0x0812682E,
                                             filter=dict(addr_ge=0x08123800, term="0000",
                                                         negate=True),
                                             exclude_owned_by=("system_battle_events",
                                                               "battle", "battlefrag",
                                                               "menu_comp", "menu_config"))),
            route="inline", term="0301", order=165,
            extra_refs={
                0x081230BE: (0x080EB6A0,),             # やった！{n}はかわした — the dodge builder
                                             #   FUN_080eb618's internal fragment-ptr literal; repoint to
                                             #   the pooled EN name-sentinel template, which cave_dodge
                                             #   (patch_battlename DODGE_CALL) reads + rebuilds with the name.
                0x0812310C: (0x080F24EC, 0x080F2948),  # は{n}のダメージを受けた (dmgsplit)
                0x08123124: (0x080E98B4,),             # 悪魔を倒した — the multi-demon (two-type)
                                             #   kill summary; slot holds a private copy 0x086BEC18
                                             #   drawn RAW via BattleMenu_SetMode(3) (no composer).
                                             #   Repoint to a pooled EN string ("The demons were
                                             #   defeated!").
                0x081231C2: (0x086BE5EC, 0x086BEC28),  # 戦闘を開始します
                0x081231D4: (0x086BE5F0, 0x086BEC2C),  # 悪魔と会話します
                0x081231E6: (0x086BE5F4, 0x086BEC30),  # 戦闘から逃げ出します
                0x081231FC: (0x086BE5F8, 0x086BEC34),  # オートバトルを開始します
                0x08123216: (0x086BE630, 0x086BEC38),  # 剣で攻撃します
                0x08123226: (0x086BE634, 0x086BEC3C),  # 銃で攻撃します
                0x08123236: (0x086BE63C, 0x086BEC40),  # 魔法を使用します
                0x08123248: (0x086BE640, 0x086BEC44),  # アイテムを使用します
                0x08123278: (0x086BE690, 0x086BEC50),  # 仲魔を1体召喚します
                0x0812328E: (0x086BE694, 0x086BEC54),  # 今までに倒した悪魔を分析します
                0x081232C2: (0x086BE648,),             # 通常攻撃をします
                0x081232D4: (0x086BE64C,),             # 特殊攻撃をします
                0x081232E6: (0x086BE650,),             # 仲魔がCOMP内に戻ります
                0x08123312: (0x086BEC60, 0x0877A004),  # 攻撃エフェクトの設定…
                0x08123332: (0x086BEC64, 0x0877A008),  # 戦闘メッセージスピード…
                0x08123356: (0x086BEC68, 0x0877A00C),  # オートバトルの設定…
                0x0812338E: (0x086BEC70, 0x0877A01C),  # 攻撃エフェクトを表示します
                0x081233AA: (0x086BEC74, 0x0877A020),  # 攻撃エフェクトの表示をOFF…
                0x081233F4: (0x086BEC7C, 0x0877A03C),  # 通常の速度でメッセージ…
                0x08123418: (0x086BEC80, 0x0877A040),  # 文字ウェイトなしで…
                0x0812345E: (0x086BEC88, 0x0877A064),  # 剣・銃・通常攻撃のみ…
                0x0812348E: (0x086BEC8C, 0x0877A068),  # 前回の行動…通常攻撃をします
                0x081234D6: (0x086BEC90, 0x0877A06C),  # 前回の行動…防御します
            }),

    # ---- battle-event suffix streams ------------------------------------------------------
    # The MessageBox composer family (Battle_ShowEventMessage ids 1-11, ComposeNameText
    # suffixes, encounter intro, treasure box — docs/battle-message-window.md) copies
    # these streams via code-literal pointers. The composer copy paths are
    # SENTINEL-UNAWARE: a 0xFFFF marker would be byte-copied and drawn as garbage, so
    # over-budget English rewrites the declared literal slots to a pooled string
    # (route literal_ptr), never the sentinel. Slots were traced in Ghidra 2026-06-10.
    Section("system_battle_events",
            Source("literal_slots",
                   dict(slots=((0x081245B4, (0x080ED110,)),
                               (0x081245D2, (0x080ED148,)),
                               (0x081245F6, (0x080ED12C, 0x080ED164)),
                               (0x08124608, (0x080ED0E8,)),
                               (0x0812461A, (0x080ED18C, 0x080ED1C0)),
                               (0x0812463A, (0x080ED0CC,)),
                               (0x0812464E, (0x080ED0B0,)),
                               (0x0812466C, (0x080ED0A0, 0x080EC478)),
                               (0x081267A6, (0x080EC138,)),
                               (0x081267BA, (0x080EC0F4,)),
                               (0x081267E0, (0x080EC0C4,)),
                               # battle command-window prompt どうしますか？ — embedded
                               # INSIDE the menu widget descriptor @0x086BE5C2 (not in any
                               # text bank; the bank twin 08123042 is ref-less/vestigial).
                               # Three verified code literals read it as a plain string.
                               (0x086BE5DA, (0x080E5FC8, 0x080EC280, 0x080EC2CC))))),
            route="literal_ptr", order=170),

    # ---- demon battle taunts ---------------------------------------------------------
    # Pointer table 0x08032CD8 (29 slots, immediately BEFORE the negotiation dialogue
    # table — the dialogue extractor started one table too late, found 2026-06-10).
    # Read by FUN_0813d814: combatant f1c[5] -> type map -> taunt_table[type]
    # (type<=0x1C), pointer stored for the event/message window. Strings live inside
    # the story bank @0x080A1190-0x080A14F2; being a ptr_table section automatically
    # excludes them from the story walk.
    Section("battle_taunts", Source("ptr_table",
                                    dict(tables=((0x08032CD8, 0x08032CD8 + 29 * 4),),
                                         dedup="text", str_max=240)),
            route="ptr_repoint", term="", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=175,
            notes="event-VM message window: dispatched as a script stream by "
                  "ScriptState79_BranchByPersonality 0x0813d874 (= the dialogue.json window)"),

    # ---- demon recruit greetings -----------------------------------------------------
    # Two pointer tables into the same 12 personality-variant greeting strings
    # @0x0815BBD4-0x0815BDC4 ("I am X, I pledge my loyalty…"): 0x084F3838 (18 slots,
    # reader literal 0x080D480C — in the shipped JP ROM ALL 18 point at the one pledge
    # line 0x0815BC8C) and 0x087F02C8 (12 distinct variants, reader literal 0x081579D0).
    # ONE section for both tables: the dedup-by-text extractor merges the shared string
    # instead of double-claiming it. Drawer is in the 0x0815xxxx sprite-list region
    # (near the FUN_0815c380 LEAD) — text repoint is correct regardless; render pitch
    # to be verified in BizHawk.
    Section("greetings", Source("ptr_table",
                                dict(tables=((0x084F3838, 0x084F3838 + 18 * 4),
                                             (0x087F02C8, 0x087F02C8 + 12 * 4)),
                                     dedup="text", str_max=120)),
            route="ptr_repoint", term="", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=180,
            notes="field message window: FUN_080af178(id=0x1a) -> FUN_080af060 -> "
                  "FUN_0813e184 (Field_SetState 0x19); reader ldr @0x080d47f6"),

    # ---- negotiation status / outcome lines (audit find, 2026-06-11) -----------------
    # Two sister tables of the taunts table (all three sit in 0x08032Bxx-0x08032CDx;
    # no direct code literal to either — likely ldr-offset-reached from the taunt
    # reader's base). 0x08032BBC ×41: status-effect / outcome lines ("□は倒された…体が
    # 麻痺した…"). 0x08032C60 ×6: negotiation antic outcomes (the kiss attempt → elbow
    # strike line). Strings live in the story bank @0x080A0C2E+/0x080A0FEE+, referenced
    # ONLY by these tables. In-budget English writes in place (any reader sees it);
    # over-budget repoints the slots.
    # CORRECTED 2026-06-19: was 0x08032BDC×29 — that "started one table too late" (same
    # class as battle_taunts), leaving 8 front slots (倒された/アンデッド/石にされた death &
    # body-change lines) + 4 back slots (ITEM used/got/thrown) pointing at JP, so those
    # rendered "[EnglishName]は[Japanese]" — the user's recurring particle-substitution
    # glitch in negotiation. True table = 0x08032BBC..0x08032C5C (next table 0x08032C60);
    # 0x08032BB8 is a RAM ptr, before that is ARM code.  See memory negotiate-status-table-undersized.
    Section("negotiate_status", Source("ptr_table",
                                       dict(tables=((0x08032BBC, 0x08032C60),),
                                            dedup="text", str_max=240)),
            route="ptr_repoint", term="", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=185,
            # The item-get template "{ALEPH}は ”{ITEM_NAME}”を 手に入れた" (0x080A0BC6) is reached
            # THREE ways: the negotiation gift via the table slot 0x08032C54 (repointed by the
            # ptr_repoint route above), and the GENERIC field/chest/event give-item display via two
            # hardcoded code literals -- FUN_0813b2c0 (opcode 0x0B ScriptOp_GiveItemOrBranch, sets
            # g_pScriptNextStream=template on success) @0x0813B31C and Script_CheckCombatCondition's
            # give path @0x0813C79C. The table repoint only fixed the negotiation case; the give-item
            # literals kept loading JP (the user's "Alephは ”Life Stone”を 手に入れた" on a chest pickup).
            # _arm_repoint rewrites these to the same pooled EN.  (Sibling JP still open: the
            # inventory-full literal 0x080A0C0A @0x0813C7B4 -- not extracted by any section yet.)
            extra_refs={0x080A0BC6: (0x0813B31C, 0x0813C79C)},
            notes="event-VM message window (sister table of dialogue.json @0x08032DE0)"),
    Section("negotiate_outcomes", Source("ptr_table",
                                         dict(tables=((0x08032C60, 0x08032C60 + 6 * 4),),
                                              dedup="text", str_max=240)),
            route="ptr_repoint", term="", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=186,
            notes="event-VM message window (sister table of dialogue.json @0x08032DE0)"),

    # ---- field door entry-check messages (audit find) --------------------------------
    # ptr table 0x0819853C ×6 ("入室チェックを行います…あなたは力が足りません…"),
    # reader literal 0x080BE964.
    Section("door_check", Source("ptr_table",
                                 dict(tables=((0x0819853C, 0x0819853C + 6 * 4),),
                                      dedup="text", str_max=200)),
            route="ptr_repoint", term="", wrap_px=rommap.EVENT_WRAP_PX, wrap_jp_pitch=13,
            page_glyphs=PAGE_GLYPHS, strip_manual_n=True, order=190,
            notes="field message window: FUN_080b832c -> FUN_080af1e8(id=0x20) -> "
                  "FUN_080af060 (Field_SetState 0x19); reader ldr @0x080be948"),

    # ---- terminal / devil-bank / link-cable UI text (audit find) ---------------------
    # A family of live tables in 0x0858xxxx with reader literals in the 0x080DA-0x080E1
    # menu subsystem: the BBS message-board terminal, devil-bank send-back, the
    # compendium level-filter SECOND copy (0x08583788 — distinct strings from the
    # cave-covered rommap.LEVEL_CAT_BASE list; this one IS slot-read @0x080DC2AC so a
    # plain repoint works), the macca exchange, and link-cable comm errors.
    Section("bbs_boards", Source("ptr_table",
                                 dict(tables=((0x08581598, 0x08581598 + 25 * 4),),
                                      dedup="text", str_max=200)),
            route="ptr_repoint", term="", order=195,
            notes="reader literal 0x080DA18C"),
    Section("bank_sendback", Source("ptr_table",
                                    dict(tables=((0x0858329C, 0x0858329C + 4 * 4),),
                                         dedup="text", str_max=200)),
            route="ptr_repoint", term="", order=196,
            notes="reader literal 0x080DBCD8"),
    Section("comp_levelrange", Source("ptr_table",
                                      dict(tables=((0x08583788, 0x08583788 + 11 * 4),),
                                           dedup="text", str_max=60)),
            route="ptr_repoint", term="", order=197,
            notes="reader literal 0x080DC2AC; NOT the cave-synthesized LEVEL_CAT_BASE copy"),
    Section("bank_exchange", Source("ptr_table",
                                    dict(tables=((0x08589CA8, 0x08589CA8 + 5 * 4),),
                                         dedup="text", str_max=200)),
            route="ptr_repoint", term="", order=198,
            notes="reader literal 0x080DFD98"),
    Section("link_comm", Source("ptr_table",
                                dict(tables=((0x0858B250, 0x0858B250 + 14 * 4),),
                                     dedup="text", str_max=200)),
            route="ptr_repoint", term="", order=199,
            notes="reader literal 0x080E1BB4"),

    # ---- CONFIG menu help texts (user-report find, 2026-06-11 second session) --------
    # Ptr table 0x084F1D5C..0x084F1DD8: 8 rows x 4 slots (per config item, null-padded —
    # the sparse layout defeats the audit's min_run=4 contiguous scan, which is why this
    # was never flagged UNCOVERED). Targets = the CONFIG screen help lines
    # 0x084F1A40-0x084F1D2A (auto-heal modes, GBA/SP/GB-Player color modes, exit lines).
    Section("config_help", Source("ptr_table",
                                  dict(tables=((0x084F1D5C, 0x084F1DDC),),
                                       dedup="text", str_max=120)),
            route="ptr_repoint", term="", order=200),

    # ---- save/load screen messages (user-report find, 2026-06-11 second session) -----
    # The save/load screen's prompts/confirms @0x084F1DDC-0x084F208E. Referenced from
    # per-state record fields in 0x084F2258-0x084F28BC (the save-screen state machine
    # data) and three code literals 0x080D0A54/5C/70 (file-load confirms; the 0x080D0xxx
    # listing is ARM-broken in Ghidra). Entries with empty slot lists have NO pointer
    # refs anywhere (2-aligned ROM scan) — reached by walk/composition — so they are
    # inline-budget-only (over-budget would warn-skip; replaces sized to fit).
    # NOT covered here: the 'NEW GAME'/カテドラルカオス/ロウ fixed cells @0x084F20A8+
    # (file-select special location labels, code literal 0x080D03A0) — LEAD.
    Section("save_screen",
            Source("literal_slots",
                   dict(slots=((0x084F1DDC, (0x084F2734,)),
                               (0x084F1E02, (0x084F2258,)),
                               (0x084F1E28, (0x084F263C,)),
                               (0x084F1E3E, ()),
                               (0x084F1EA8, (0x084F27B8,)),
                               (0x084F1F0E, ()),
                               (0x084F1F20, ()),
                               (0x084F1F7C, (0x080D0A54,)),
                               (0x084F1FA8, (0x080D0A5C,)),
                               (0x084F1FD4, (0x080D0A70,)),
                               (0x084F2000, (0x084F2408,)),
                               (0x084F2036, ()),
                               (0x084F204C, (0x084F2548,)),
                               (0x084F2062, (0x084F2688, 0x084F28BC)),
                               (0x084F2078, (0x084F236C, 0x084F24B8)),
                               (0x084F208E, (0x084F2868,))))),
            route="literal_ptr", order=201),

    # ---- automap marker-menu system messages (user-report find, map screen) ----------
    # The dungeon automap's marker feature prompts @0x08162B0C-0x08162C2A (contiguous,
    # 0x0000-term). Each is referenced by exactly ONE pc-relative code literal in the
    # marker-UI Thumb pocket 0x080B52F0-0x080B5560 (not a contiguous u32 table, so the
    # min_run=4 coverage scan was blind to them — same blind spot as save_screen). The
    # drawer is Text_DrawSpriteString (already VWF-covered); strings are tightly packed
    # so longer English must repoint -> literal_ptr (inline-when-fits, else rewrite slot).
    # The last 10 are six two-line marker-type captions (top half + bottom half).
    Section("automap_markers",
            Source("literal_slots",
                   dict(slots=((0x08162B0C, (0x080B5530,)),   # NO DATA
                               (0x08162B1C, (0x080B5314,)),   # set a marker
                               (0x08162B34, (0x080B5390,)),   # select marker type
                               (0x08162B56, (0x080B532C,)),   # can't place here
                               (0x08162B76, (0x080B54FC,)),   # erase this marker
                               (0x08162B8E, (0x080B53CC,)),   # general use (top)
                               (0x08162B9C, (0x080B53D0,)),   # general use (bottom)
                               (0x08162BA8, (0x080B53EC,)),   # event point (top)
                               (0x08162BBE, (0x080B53F0,)),   # event point (bottom)
                               (0x08162BD0, (0x080B540C,)),   # treasure spot (top)
                               (0x08162BE4, (0x080B5410,)),   # treasure spot (bottom)
                               (0x08162BF6, (0x080B543C,)),   # boss room (top)
                               (0x08162C06, (0x080B5440,)),   # boss room (bottom)
                               (0x08162C12, (0x080B5474,)),   # other (top)
                               (0x08162C26, (0x080B5478,))))),  # other (bottom)
            route="literal_ptr", order=202),

    # ---- dungeon field-event prompts (user-report find: "アレフ達" trap message) -------
    # Messages in the early bank @0x08002Exx-0x08003xxx reached by single absolute-pointer
    # code literals in the field/door/mode/dismiss handlers + field-task records — invisible
    # to the contiguous-ptr scan. The TRAP-damage line @0x080033FC carries {ALEPH}達
    # ("Aleph's party took damage") — the user saw the raw アレフ達 here.
    # EXPANDED 2026-06-20 (audit_orphans triage): +20 cluster-1 strings whose refs are ALL
    # in clean single-purpose handlers (verified every ref site holds the exact string ptr,
    # full-ROM 2-aligned scan; repointable). Subsystems: door entry-check / ID-code gate
    # (0x08198xxx mode handler + 0x080BExxx field handler), the per-party-member field
    # damage/poison/封じ hazard lines (0x080B8xxx field handler, 2 code paths each = 2 slots),
    # box found / gave-up (0x08164xxx field-task records), money/magnetite/can't-carry pickup
    # (0x080B8xxx), demon dismissal prompts (0x0812Axxx menu handler).
    # STILL DEFERRED: (a) refs in the 0x083xxxx-0x084xxxx data/ptr-table region = a shared
    # status-message table indexed by status id, OR mid-string sub-window entry points —
    # need the status-table-slot mechanism, not a literal_ptr repoint: 08002F10, 08003254,
    # 08003320, 08003332, 08003456.  (b) embedded yes/no choice-ops (`{=0e03}<ptr>`): the simple
    # codec mis-groups the 0x30E op's 4-byte operand as glyphs (<3370>謹), so they "don't round
    # trip" through the literal_slots extractor -- HAND-AUTHOR the entry with the full 6-byte op
    # token (encode() passes {=hex} through verbatim).  Both branch targets turned out to be inert
    # 0x0301 terminators (the No->end-message target, NOT a translated entry), so NO scriptrefs
    # remap is needed: translate only the prose, keep the op byte-exact, repoint the record/literal.
    # SHIPPED 2026-06-21: 0800334A (box found/open?, rec 0x08164BFC -> term 0x08003370) and
    # 08002E80 (wrong-ID retry?, lit 0x08198418 -> term 0x08002EB8).
    # VESTIGIAL / NO CONSUMER (full-ROM 2-aligned ptr scan = 0 refs; variable-length so not a
    # computed-stride table either -- repointing them would draw nothing): the field status-affliction
    # copies 080031F6-08003330 (は倒された/石に/まひ/...; the LIVE status path is `status_messages`
    # @0x0819873C for battle + the field-specific poison 080034EA) and the trap line 080034D2
    # (わなにかかった; the live field trap message is 080033FC).  Do NOT add these.
    Section("dungeon_events",
            Source("literal_slots",
                   dict(slots=((0x080033FC, (0x08164E88,)),          # trap! party took damage
                               (0x0800338A, (0x08164D24,)),          # box was empty
                               # door entry-check / ID-code gate
                               (0x08002E2C, (0x08198330,)),          # "ID code, please input"
                               (0x08002E56, (0x081983D4,)),          # "ID confirmed, opening door"
                               (0x08002E80, (0x08198418,)),          # "Wrong ID, input again?" (yes/no retry; 0x30E No-branch op kept byte-exact)
                               (0x08002EBA, (0x08198474,)),          # "Wrong ID, no more attempts"
                               (0x08002EFE, (0x080BE944, 0x080BE9C8)),  # "entry check... opening door"
                               (0x08003192, (0x080BE9E0,)),          # entry check: wrong element
                               # field hazard / status lines (per party-member name-sub)
                               (0x08003432, (0x080B8820, 0x080B8F90)),  # {ALEPH}は N damage
                               (0x08003452, (0x080B8828, 0x080B8F98)),  # {GIMMEL}は N damage
                               (0x08003472, (0x080B8830, 0x080B8FA0)),  # {HIROKO}は N damage
                               (0x08003492, (0x080B8840, 0x080B8FB0)),  # {ZAYIN}は N damage
                               (0x080034B2, (0x080B8868, 0x080B8FD8)),  # {=031e}は N damage
                               (0x080034EA, (0x080B8EF8,)),          # {ALEPH}は poisoned
                               (0x08198834, (0x080BEBB4,)),          # は魔法を封じられた
                               # box / treasure pickup
                               (0x0800334A, (0x08164BFC,)),          # "Found a box. Open it?" prompt (full 0x30E No-branch op kept byte-exact)
                               (0x08003372, (0x08164CE8,)),          # は box gave-up
                               (0x080033A0, (0x080B8574,)),          # は {item} found (box pickup: "Hawk found / Fritz Helm")
                               (0x080033BA, (0x080B8654,)),          # は {N} money (Macca) found
                               (0x080033D6, (0x080B8620,)),          # は N magnetite found
                               (0x08003502, (0x080B8520,)),          # found... can't carry... gave up
                               # demon dismissal
                               (0x0800354A, (0x0812A4D8,)),          # "will part with {demon}"
                               (0x08003556, (0x0812A4DC,)),          # "are you sure?"
                               (0x08003568, (0x0812A508,)),          # "this demon can't be removed"
                               # status afflict tail (orphan sweep 2026-06-20; both event-blob copies, nref=2)
                               (0x08003320, (0x083BAA64, 0x084B4F0C))))),  # "<name> was afflicted"
            route="literal_ptr", order=203),

    # ---- boot "this is a work of fiction" disclaimer (user-report find) ---------------
    # The fiction disclaimer shown at boot ("このゲームは　フィクションであり…"), drawn by
    # Intro_DrawDisclaimer 0x080D67BC as 3 hardcoded fixed-pitch (13px) rows of 17/16/17
    # full-width glyphs read sequentially from the string @0x085096C4. The renderer is an
    # intro-cutscene STEP, reached only via the fn-ptr embedded in the step record at
    # 0x08509EEC (-> 0x080D67BD), so the contiguous-ptr coverage scan never saw the string.
    # ONE literal slot: the renderer's string-ptr literal @0x080D6868. patch_introdisclaimer
    # repoints the step fn-ptr to a cave that draws the pooled English proportionally via the
    # VWF strip path (Text_DrawSpriteString / cave_runtext), so the EN need not be fixed-pitch.
    Section("intro_disclaimer",
            Source("literal_slots",
                   dict(slots=((0x085096C4, (0x080D6868,)),))),
            route="literal_ptr", order=204),

    # ---- compendium / COMP-summon messages (user-report find: "召喚するのに…") -----------
    # The Cathedral-of-Shadows compendium summon/confirm/error messages @0x0815bf80-0x0815c0de,
    # each reached by a single pc-relative code literal in the COMP handler (0x080ce/0x080cf/
    # 0x080d4/0x08157 — invisible to the contiguous-ptr scan). Drawn fixed-pitch via 0x80ac334.
    # The SUMMON prompt is 3 fragments on 3 lines with the macca cost spliced on line 2:
    #   0x0815bfbe (line1)  /  [N] + 0x0815bfcc (line2)  /  0x0815bfd6 (line3).
    # DEFERRED (number placeholders embedded in the string -> translating them would misalign the
    # overdrawn cost): the 抽出/還元 memory-chip lines 0x0815bfea / 0x0815c0aa / 0x0815c0de.
    Section("comp_messages",
            Source("literal_slots",
                   dict(slots=((0x0815BFBE, (0x080CEAC0,)),   # "Summon for"  (line 1)
                               (0x0815BFCC, (0x080CEAC8,)),   # "Macca."      (line 2, after [N])
                               (0x0815BFD6, (0x080CEACC,)),   # "Is that okay?" (line 3)
                               (0x0815BF92, (0x08157A5C,)),   # "Here is {=031e}..." (give item)
                               (0x0815C02C, (0x080CF45C,)),   # not enough Memory Chips
                               (0x0815C048, (0x080CF468,)),   # not enough macca
                               (0x0815C05A, (0x080CF474,)),   # party full
                               (0x0815C06E, (0x080CF494,)),   # level too low
                               (0x0815C082, (0x080CF4D4,)),   # wrong alignment
                               (0x0815C090, (0x080D4820,))))),  # extraction failed
            route="literal_ptr", order=205),

    # ---- Cathedral of Shadows: demon fusion UI (audit find 2026-06-15, user "all-JP") --
    # Fusion prompts / validation errors / result, sandwiched in the gap between greetings
    # (ends 0x0815BDC4) and comp_messages (starts 0x0815BFBE) — invisible to the
    # contiguous-ptr coverage scan (single pc-relative code literals, the same blind spot as
    # comp_messages/save_screen). Reached by: the fusion-input prompt pocket 0x08155xxx
    # (fusion-master "which one's the Nth?"), the validate/error handler family 0x080CExxx,
    # the accident handler (0x08157A30), the extract/return result handlers (0x080D4938/50),
    # the no-partner UI descriptor records (0x087E2628 family, string at record +0x00,
    # computed-index base 0x08156024), and the casino "Blend" script copy (0x08133228).
    # MIXED stream drawers, all repointable: prompts/errors/accident -> Text_DrawSpriteString
    # 0x080ac334 (OAM flowing text, rendered VWF by patch_spritebuf); return ok/fail ->
    # the event-VM field window FUN_080af178 (which is what expands return-ok's {=2303} count).
    # route=literal_ptr (inline-when-fits, else slot repoint; NEVER sentinel — the "Blend"
    # copy path is sentinel-unaware). Fusion-master voice = gruff archaic OLD MAN ("じゃ").
    # DEFERRED (NOT here): 0x0815BFEA (extract cost) + 0x0815C0AA (return cost) carry bare
    # placeholder digit glyphs 0xCC('0')/0xCD('1') (+ ћ 0x52) that the 0x080cf2xx loop detects
    # by glyph code at stream position and overdraws with the runtime chip/macca value —
    # reflowing EN moves the placeholder; needs an overdraw cave first. 0x0815C0DE (return ok)
    # is SAFE (real {=2303} count token) and IS included. Also excluded: 0x08009534/40
    # (Visionary extract = patch_vision) and the 0x0815BFxx COMP-summon strings (= comp_messages,
    # a different screen — keep wording consistent across the two).
    Section("fusion_menu",
            Source("literal_slots",
                   dict(slots=((0x0815BE50, (0x0815545C,)),   # まず1体目はどれじゃ？ (first demon)
                               (0x0815BE68, (0x08155478,)),   # 2体目はどいつじゃ？
                               (0x0815BE7E, (0x081554B4,)),   # 3体目はだれじゃ？
                               (0x0815BE92, (0x08155464,)),   # 1本目はどれじゃ？ (first sword)
                               (0x0815BEA6, (0x0815548C,)),   # では2本目はなんじゃ？
                               (0x0815BEBE, (0x08155494, 0x08155508)),  # では仲魔はだれじゃ？
                               (0x0815BED4, (0x080CE95C,)),   # これでいいかね？ (confirm)
                               (0x0815BEFA, (0x080CEA30,)),   # では　合体させるぞ (do-fuse)
                               (0x0815BF0E, (0x080CE8DC,)),   # 残念だが…お前のレベルでは (level too low)
                               (0x0815BF36, (0x080CE9C4,)),   # 属性が違うがよいか (alignment differs)
                               (0x0815BF4A, (0x080CE8D0,)),   # 同じ仲魔がおるようだな (same demon)
                               (0x0815BF62, (0x080CE8FC,)),   # アイテムがいっぱいじゃ… (items full)
                               (0x0815BF7C, (0x080CE920,)),   # 仲魔がいっぱいじゃ… (allies full)
                               (0x0815BB90, (0x08157A30,)),   # しまった！事故が起こった！ (accident)
                               (0x0815C0DE, (0x080D4938,)),   # 還元成功 (return ok — {=2303} count)
                               (0x0815C110, (0x080D4950,)),   # 還元失敗 (return fail)
                               (0x0815BDFC, (0x087F0300,)),   # 我は平将門なるぞ (Masakado result 1)
                               (0x0815BE18, (0x087F0304,)),   # Masakado result line 2
                               (0x087E1C48, (0x087E2628, 0x087E2728,
                                             0x087E2AF0, 0x087E2BF0)),  # 合体させる仲魔がおらん (no partner)
                               (0x0878EF04, (0x08133228,))))),  # ブレンド (casino Blend)
            route="literal_ptr", order=206),

    # ---- status-affliction messages (census leak find 2026-06-17, docs/smt1-coverage-audit.md) -
    # 14 affliction predicates @0x0819873C-0x08198822 ("は倒された".."は毒におかされた"), in the
    # gap between door_check (0x0819853C) and names_equipment (0x08198B88) — owned by no section.
    # Consumer: Status_ShowAfflictionMessage 0x080BEA60 switches on a status bitmask and
    # `ldr r6,[pc,#0]`-loads the matching string from 14 inline literals @0x080BEB34..0x080BEB9C
    # (stride 8), composing [name]+string (name from Combatant_DecodeName 0x080C0348). Reached via
    # the status-effect descriptor table @0x08198848 (handler fn-ptrs) by COMPUTED index -> no
    # static xref, invisible to the contiguous-ptr audit. This is a DUPLICATE of battlefrag's
    # [name]-templated copies @0x08123xxx, so this path rendered JP. Resolves the dungeon_events
    # NOTE ("status-result lines reached by a computed index table, ref NONE -> trace consumers").
    # JP starts with the particle は (name is drawn before) -> EN replace is predicate-only with a
    # LEADING SPACE so "Hawk" + " was defeated." reads correctly.
    Section("status_messages",
            Source("literal_slots",
                   dict(slots=((0x0819873C, (0x080BEB34,)),   # は倒された
                               (0x08198748, (0x080BEB3C,)),   # はアンデッドにされた
                               (0x0819875E, (0x080BEB44,)),   # は石にされた
                               (0x0819876C, (0x080BEB4C,)),   # はからだがまひした
                               (0x08198780, (0x080BEB54,)),   # はハエにかえられた
                               (0x08198794, (0x080BEB5C,)),   # はこうもりになった
                               (0x081987A8, (0x080BEB64,)),   # はとりこになった
                               (0x081987BA, (0x080BEB6C,)),   # は凍りついた
                               (0x081987C8, (0x080BEB74,)),   # は感電した
                               (0x081987D4, (0x080BEB7C,)),   # は眠ってしまった
                               (0x081987E6, (0x080BEB84,)),   # はかなしばりになった
                               (0x081987FC, (0x080BEB8C,)),   # はおかしくなった
                               (0x0819880E, (0x080BEB94,)),   # は幸せにつつまれた
                               (0x08198822, (0x080BEB9C,))))),  # は毒におかされた
            route="literal_ptr", order=207),

    # ---- COMP / field standalone messages (census leak find 2026-06-17) ----------------
    # Clean (no □ substitution) messages in the COMP/field module 0x080B9xxx, each an inline
    # pc-relative code literal -> a string in the 0x08165xxx COMP/Mapper region (the region
    # CLAUDE.md flagged as "unknown reader"). COMP + collapse are duplicates of text translated
    # elsewhere (battle/system_menu) that this path still drew in JP; the elevator floor prompt
    # is genuinely untranslated (census MISSING). The damage/status-result □-templates in the
    # 0x08003xxx bank are a SEPARATE follow-up (they carry inline □ name/number tokens and need
    # per-template composition tracing like battlefrag's cave_namemove — not a blind repoint).
    Section("field_messages",
            Source("literal_slots",
                   dict(slots=((0x08165574, (0x080B95B8,)),   # ここではCOMPを使用できません
                               (0x081652D8, (0x080B9218,)),   # は力尽きた  (name-prepended)
                               (0x08165654, (0x080B9C54,))))),  # 声：/ご利用階をお選びください
            route="literal_ptr", order=208),

    # === orphan-coverage sweep 2026-06-20: 3 new literal_ptr Sections (28 strings) ===
    # ---- DDS bonus-menu MUSIC PLAYER track-name labels (orphan sweep 2026-06-20, user-confirmed) ---
    # The DDS bonus menu has a music player / sound-test whose track labels are named after the scene
    # each BGM plays in.  28-entry table @0x085861C8 of {meta_u32, name_ptr_u32}; 9 labels already
    # Latin (Demo/Title/Shop/...), these 20 are JP.  nref=1 each (music-table-exclusive), all round-trip;
    # repoint each name_ptr cell -> pooled EN (the meta/BGM-id word untouched).  Consumer 0x080DDxxx.
    # The audit MIN_LEN filter had dropped ジム/戦闘/敵遭遇/カジノ; the full table decode recovered them.
    Section("music_player",
            Source("literal_slots",
                   dict(slots=(
                       (0x08009B00, (0x085861DC,)),   # Gym
                       (0x08009B06, (0x085861E4,)),   # Virtual Battler
                       (0x08009B26, (0x085861F4,)),   # 3D: Valhalla
                       (0x08009B48, (0x08586204,)),   # 2D: Field
                       (0x08009B5A, (0x0858620C,)),   # Encounter
                       (0x08009B62, (0x08586214,)),   # Battle
                       (0x08009B68, (0x0858621C,)),   # Level Up
                       (0x08009B7A, (0x08586224,)),   # Memory
                       (0x08009B84, (0x0858622C,)),   # 3D: Center
                       (0x08009B9C, (0x0858623C,)),   # Cathedral
                       (0x08009BA6, (0x08586244,)),   # Demon Fusion
                       (0x08009BB0, (0x0858624C,)),   # 2D: Siren
                       (0x08009BC2, (0x08586254,)),   # 3D: Underworld
                       (0x08009BD2, (0x0858625C,)),   # Mid-Boss Battle
                       (0x08009BEA, (0x0858626C,)),   # Casino
                       (0x08009C10, (0x08586284,)),   # 2D: Makai
                       (0x08009C1C, (0x0858628C,)),   # 3D: Makai
                       (0x08009C28, (0x08586294,)),   # Heroine
                       (0x08009C32, (0x0858629C,)),   # Big-Boss Battle
                       (0x08009C3E, (0x085862A4,)),   # Game Over
                   ))),
            route="literal_ptr", order=209),

    # ---- sprite-text / yes-no prompts (orphan sweep 2026-06-20) ------------------------------------
    # OAM sprite-text popups (Text_DrawSpriteString, rendered VWF by patch_spritebuf) + the NG+
    # clear-data save prompt. Single-ref, round-trip; literal_ptr repoints over-budget English and
    # writes fitting strings in place. The two yes/no prompts are distinct ROM copies.
    Section("menu_prompts",
            Source("literal_slots",
                   dict(slots=(
                       (0x084F09B0, (0x080CDEE4,)),   # Equipment is cursed!
                       (0x084F0CA0, (0x080CE560,)),   # Is this OK? (common yes/no prompt)
                       (0x0800980C, (0x080E1B88,)),   # Is this OK?
                       (0x087F2D50, (0x0815CA78,)),   # Saving clear data lets you{n}car
                   ))),
            route="literal_ptr", order=210),

    # ---- name-entry / exchange / passcode UI headers (orphan sweep 2026-06-20) --------------------
    # Player-facing UI on the kana-toggle / spirit-exchange / passcode screens; single code-literal
    # slots, round-trip clean (084F3FFC's JP ћ alias is benign for literal_ptr).
    Section("nameentry_exchange",
            Source("literal_slots",
                   dict(slots=(
                       (0x084F3002, (0x080D17C0,)),   # Hiragana{n}Katakana{n}Alphanum{n
                       (0x084F311E, (0x080D2BC0,)),   #    Exchange Item
                       (0x084F312C, (0x080D2C98,)),   #    Trade Spirits
                       (0x084F3FDC, (0x080D4E6C,)),   # Enter the code:
                       (0x084F3FFC, (0x080D4EB4,)),   # Oh? You're short on ћ.
                   ))),
            route="literal_ptr", order=211),
]

# NOT sections, by design (the coverage audit should list these as covered/dead):
# - Compendium level-range labels ("1~9".."90~99", strings @rommap.LEVEL_CAT_BASE
#   0x087E32C8 stride 0xC, ptr table @0x087E3340): ALREADY English via code synthesis —
#   cave_skilllist.c comp_level_vwf recognizes the string ADDRESS and draws "Lv10-19".
#   A repoint section would break that address-identity check.
# - The 0x086BExxx pointer tables themselves (0x086BE630/0x086BEC28/0x086BEF10 etc.):
#   table SLOTS, not text; their target strings are owned by the bank-walk sections
#   above (in-place) and the battlefrag block (rebuild + auto-repoint).


def by_id(sec_id):
    for s in SECTIONS:
        if s.id == sec_id:
            return s
    raise KeyError(f"no section {sec_id!r} in the manifest")


def in_pack_order():
    return sorted(SECTIONS, key=lambda s: s.order)


def filenames():
    return {f"{s.id}.json" for s in SECTIONS}


# Per-field flags allowed to appear under each route (flags REFINE a route; a flag that
# implies a different mechanism than the section declares is a manifest violation and
# pack() refuses to guess).
_ROUTE_FLAGS = {
    "inline":        {"sentinel"},      # mixed legacy `system` (gated); removed at split
    "sentinel":      {"sentinel"},
    "name_table":    {"name_table", "sentinel", "aff"},   # aff lines nest here
    "item_table":    {"item_table"},
    "ptr_repoint":   set(),
    "msg_table":     {"ids"},
    "story_expand":  set(),
    "label":         {"kind", "slots", "move"},
    "literal_ptr":   set(),
    "block_rebuild": {"role"},
}
# NB: "id" and "y" are informational (which record / which row), not mechanism
# selectors — they are not validated.
_FLAGS = {"sentinel", "name_table", "item_table", "aff", "ids", "kind", "slots",
          "move", "role"}


def check_field_flags(sec, f, is_desc=False):
    """Raise if a field carries flags incompatible with its section's declared route."""
    route = sec.desc_route if is_desc and sec.desc_route else sec.route
    bad = (set(f) & _FLAGS) - _ROUTE_FLAGS.get(route, set())
    if bad:
        raise ValueError(f"{sec.id}: field {f.get('addr') or f.get('ptr')} carries "
                         f"{sorted(bad)} but section route is {route!r} — fix the "
                         f"manifest or the entry, don't rely on fallthrough")


# ---------------------------------------------------------------------------
# Field-kind schema (docs/text-hack-consolidation.md §7).  Every translatable leaf field
# (the dicts tr.fields() yields) is exactly ONE of a small closed set of KINDS, decided by
# its OWN keys/flags — NOT by its (arbitrary, mechanism-driven) section.  Inventoried
# 2026-06-16 over all 37 translation JSONs: 7401 fields, 22 raw key-shapes, 13 kinds, zero
# outliers (dump/audit_field_schema.py regenerates the proof).  `original`/`replace`/`term`
# are universal; the rest are per-kind.  ONE place to ask "what shape is this field?" — it
# replaces the scattered f.get()/key checks across extract + the pack arms.
#
# Battlefrag's bare [addr,term] fragments are the one shape that isn't purely intrinsic to
# its keys (it looks like `inline`), so `kind_of` takes the section route to disambiguate
# the block_rebuild case.
_UNIVERSAL_FIELD_KEYS = {"original", "replace", "term"}
FIELD_KINDS = {
    # kind         required keys (beyond universal)   allowed extra keys
    "label":      ({"kind", "slots"},                 {"y", "note"}),
    "msg_id":     ({"addr", "ids"},                   set()),
    "block":      ({"addr"},                          {"role", "style", "standalone"}),
    "repoint":    ({"ptrs"},                           {"addr", "addrs", "max"}),
    "story":      ({"addrs"},                          {"max"}),
    "name_table": ({"addr", "id", "name_table"},       {"max", "aff1", "aff2"}),
    "item_table": ({"addr", "id", "item_table"},       {"max"}),
    "aff":        ({"addr", "aff"},                    {"max", "sentinel"}),
    "sentinel":   ({"addr", "sentinel"},               {"max"}),
    "lore":       ({"addr", "id", "ptr"},              set()),
    "desc":       ({"addr", "ptr"},                    set()),
    "idptr":      ({"id"},                             set()),
    "inline":     ({"addr"},                           {"max"}),
}


# Which field-kinds each injection ROUTE permits — the mechanism constrains the kinds a
# section can hold.  Derived empirically (dump/audit_field_schema.py over all 37 JSONs,
# 2026-06-16); the kind-level successor to _ROUTE_FLAGS.  check_entry gates on it so a
# shape-valid field of a kind its section's mechanism can't handle is caught (e.g. a
# `sentinel` field landing in an `msg_table` section).  (A paired section's `desc`
# sub-field rides the section's main route here, so desc appears under item_table/sentinel.)
ROUTE_KINDS = {
    "inline":        {"inline"},
    "sentinel":      {"sentinel", "desc"},
    "name_table":    {"name_table", "aff"},
    "item_table":    {"item_table", "desc"},
    "ptr_repoint":   {"repoint", "lore", "inline"},
    "msg_table":     {"msg_id"},
    "story_expand":  {"story"},
    "label":         {"label", "idptr"},
    "literal_ptr":   {"inline", "repoint"},
    "block_rebuild": {"block"},
}


def kind_of(f, route=None):
    """Classify a leaf field dict into its FIELD_KINDS kind from its own keys (+ the
    block_rebuild route for battlefrag's bare fragments).  Raises on an unknown shape."""
    if f.get("kind") == "label" or "slots" in f:
        return "label"
    if "ids" in f:
        return "msg_id"
    if route == "block_rebuild":          # battlefrag fragments: [addr,term] (+role/style/standalone)
        return "block"
    if "ptrs" in f:
        return "repoint"
    if "addrs" in f:
        return "story"
    if f.get("name_table"):
        return "name_table"
    if f.get("item_table"):
        return "item_table"
    if f.get("aff"):
        return "aff"
    if f.get("sentinel"):
        return "sentinel"
    if "ptr" in f:
        return "lore" if "id" in f else "desc"
    if "addr" not in f and "id" in f:
        return "idptr"
    if "addr" in f:
        return "inline"
    raise ValueError(f"unclassifiable field (keys {sorted(f)})")


def check_entry(sec, f):
    """Validate one leaf field's key-set against its kind's schema; return the kind.
    Raises on a missing required key or an unknown extra key (a malformed entry / typo)."""
    kind = kind_of(f, sec.route)
    req, opt = FIELD_KINDS[kind]
    keys = set(f) - _UNIVERSAL_FIELD_KEYS
    missing, unknown = req - keys, keys - req - opt
    if missing or unknown:
        ident = f.get("addr") or f.get("id") or (f.get("slots") or [["?"]])[0]
        raise ValueError(f"{sec.id}: field {ident} classified {kind!r} but "
                         f"missing {sorted(missing)} / has unknown {sorted(unknown)}")
    allowed = ROUTE_KINDS.get(sec.route)
    if allowed is not None and kind not in allowed:
        ident = f.get("addr") or f.get("id") or (f.get("slots") or [["?"]])[0]
        raise ValueError(f"{sec.id}: field {ident} is kind {kind!r}, not permitted under route "
                         f"{sec.route!r} (allows {sorted(allowed)})")
    return kind
