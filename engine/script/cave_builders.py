#!/usr/bin/env python3
"""Reusable code-cave BUILDERS for the text-render hooks (Track-3 consolidation; see
docs/text-hack-consolidation.md §2).  Each builder emits the SAME Thumb asm the hand-written
caves did, so — keystone being deterministic — a builder-generated cave is byte-identical to
the original it replaces (provable via dump/verify_cave_layout.py + the build ROM hash, no
in-game check).  Per-site differences (registers, an OOB guard, add-vs-adds, the drawer/getter/
epilogue addresses) are PARAMETERS, not copy-pasted asm.

idtable_vwf_cave — the "id -> pooled-name table" VWF draw-loop shared by the status item/
equipment-name drawers (patch_drop, patch_itemdrop, and any future id->ITEM_TABLE/NAME_TABLE
name drawer): look up TABLE[id]; if a pooled English name is present, draw it variable-width via
the WIDTH_TABLE and `bx` to the function epilogue; else re-issue the original record-getter and
`bx` to the continuation (so untranslated / out-of-range ids stay byte-for-byte original).
"""



_HI_REGS = {"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15", "sb", "sl", "fp", "ip", "sp", "lr", "pc"}


def _mv(dst, src):
    """Register move that is valid Thumb-1 on ARM7TDMI: hi-register MOV needs at
    least one high register; for low->low use the flags-setting adds rd, rm, #0."""
    if dst in _HI_REGS or src in _HI_REGS:
        return f"    mov  {dst}, {src}"
    return f"    adds {dst}, {src}, #0"


def idtable_vwf_cave(p, *, name, hook, hook_old, table, drawer, buf, width, epilogue,
                     getter, cont, x_reg, y_reg, ptr_reg, id_reg="r0", tint_reg=None,
                     xadd="add", bounds=None):
    """Build + install the id->pool VWF draw-loop cave and `bl` the hook to it.

    table/bounds : id->ptr table base, and (optional) count sym for the OOB guard (None = none).
    drawer       : glyph drawer (Font_DrawGlyph / Font_DrawGlyphTinted).
    tint_reg     : if the drawer is tinted, the reg whose value is stored at [sp,#0]; else None.
    x_reg/y_reg/ptr_reg/id_reg : the call site's live register contract.
    xadd         : legacy param (ignored) — the advance is always the T1 `adds`; the
                   hi-register "add rlow, rlow" form is ARMv4T-unpredictable and
                   misexecutes on real GBA hardware (2026-07 post-mortem).
    getter/cont  : the record-getter to re-issue + the stock continuation, for the no-override arm.
    epilogue     : the stock epilogue address (Thumb, |1) the drawn path bx-es to.
    Returns the cave address.  Emits the literal pool in the loads' flow order:
    [table, (bounds,) buf, width, epilogue, cont]."""
    asm = ["    ldr  r1, [pc, #0]      /* id->name table */"]
    lits = [table]
    if bounds is not None:
        asm += ["    ldr  r2, [pc, #0]      /* count (OOB guard) */",
                f"    cmp  {id_reg}, r2",
                "    bhs  d_orig"]
        lits.append(bounds)
    asm += [f"    lsls r2, {id_reg}, #2",
            "    ldr  r1, [r1, r2]      /* table[id] = pooled name ptr, or 0 */",
            "    cmp  r1, #0",
            "    beq  d_orig",
            _mv(ptr_reg, "r1")]
    asm += ["d_loop:",
            f"    ldrh r0, [{ptr_reg}]",
            "    cmp  r0, #0",
            "    beq  d_done"]
    if tint_reg is not None:
        asm.append(f"    str  {tint_reg}, [sp, #0]   /* tint */")
    asm += ["    ldr  r1, [pc, #0]      /* canvas buffer */",
            _mv("r2", x_reg),
            _mv("r3", y_reg),
            f"    bl   #{drawer:#x}",
            f"    ldrh r0, [{ptr_reg}]",
            "    ldr  r1, [pc, #0]      /* width table */",
            "    ldrb r1, [r1, r0]",
            f"    adds {x_reg}, {x_reg}, r1   /* X += VWF width */",
            f"    adds {ptr_reg}, #2",
            "    b    d_loop"]
    asm += ["d_done:",
            "    ldr  r0, [pc, #0]      /* epilogue */",
            "    bx   r0",
            "d_orig:",
            f"    bl   #{getter:#x}      /* original record-getter */",
            "    ldr  r1, [pc, #0]      /* continuation */",
            "    bx   r1"]
    lits += [buf, width, epilogue, cont]
    cave = p.cave_asm("\n".join(asm) + "\n", lits, name=name)
    p.bl(hook, cave, hook_old)
    return cave


def sidecar_cave(p, *, name, hook, hook_old, ptr, redo, load_reg="r0", bl_name=None):
    """The label-repoint "decouple a shared glyph literal" micro-cave: load a pooled-English
    string pointer into `load_reg`, redo the canvas-register setup the hook replaced (`redo`,
    e.g. "adds r1, r6, #0" / "mov r1, r10"), and `bx lr` — the menu/menutinted pointer hook then
    draws the pooled string VWF.  Replaces a `mov r0,rN; mov r1,sl`-style shared-literal setup at
    `hook`.  Byte-identical to the former per-module hand-asm (same instructions in → same keystone
    bytes; cave_asm rewrites the ldr-pc offset).  Used by patch_equipstat / statpage / dictstatus /
    humanmag, each supplying its own `redo` (+ `load_reg` for the load-into-r6 variant)."""
    asm = f"    ldr  {load_reg}, [pc, #0]\n    {redo}\n    bx   lr\n"
    cave = p.cave_asm(asm, [ptr], name=name)
    if bl_name:
        p.bl(hook, cave, hook_old, name=bl_name)
    else:
        p.bl(hook, cave, hook_old)
    return cave


def marker_copy_cave(p, *, name, hook, hook_old, skip, skip_old, skip_new,
                     tint_call, tint_old, tint_target, table, count, marker_hi, id_reg):
    """The "write a name MARKER instead of copying the 8 JP tokens" cave shared by the exchange /
    battle item+demon list rows (patch_exchangelist): if TABLE[id] holds a pooled English name,
    write the 1-token marker `marker_hi<<8 | id` (+ terminator) into the row buffer (sp+0xc) — the
    strip renderer (cave_runtext) expands it to the full VWF name; else copy the 8 JP tokens
    byte-for-byte (untranslated / OOB ids unchanged).  Installs all three edits the site needs: the
    `bl` to the cave, the `skip` byte-patch past the now-dead copy loop, and the tinted-printer
    `bl` retarget to the (hooked) plain printer so grayed rows expand the marker too.  Per-site:
    `table`/`count` (ITEM_TABLE+ITEM_COUNT or NAME_TABLE+NAME_COUNT), `marker_hi` (0xE0 item / 0xF0
    demon), `id_reg` (the reg the id is in).  No absolute branch in the body ⇒ byte-identical to the
    former hand-asm regardless of placement (keystone-deterministic)."""
    asm = "\n".join([
        "    ldr  r0, [pc, #0]      /* id->name table */",
        "    ldr  r1, [pc, #0]      /* count */",
        f"    cmp  {id_reg}, r1",
        "    bcs  m_jp",
        f"    lsls r2, {id_reg}, #2",
        "    ldr  r0, [r0, r2]      /* pooled EN name ptr, or 0 */",
        "    cmp  r0, #0",
        "    beq  m_jp",
        "    add  r1, sp, #0xc      /* &row buffer */",
        f"    movs r0, #{marker_hi:#x}",
        "    lsls r0, r0, #8        /* marker_hi << 8 */",
        f"    orrs r0, {id_reg}      /* marker = (marker_hi<<8) | id */",
        "    strh r0, [r1, #0]",
        "    movs r0, #0",
        "    strh r0, [r1, #2]      /* terminator */",
        "    bx   lr",
        "m_jp:",
        "    add  r1, sp, #0xc",
        "    movs r2, #0",
        "m_loop:",
        "    ldrh r0, [r3]",
        "    strh r0, [r1]",
        "    adds r3, #2",
        "    adds r1, #2",
        "    adds r2, #1",
        "    cmp  r2, #7",
        "    bls  m_loop            /* copy 8 JP tokens */",
        "    movs r0, #0",
        "    strh r0, [r1]          /* null-term buf[8] */",
        "    bx   lr",
    ]) + "\n"
    cave = p.cave_asm(asm, [table, count], name=name)
    p.bl(hook, cave, hook_old, name=f"{name} marker")
    p.patch(skip, skip_old, skip_new, name=f"{name} skip dead copy loop")
    p.bl(tint_call, tint_target, tint_old, name=f"{name} tinted->plain")
    return cave
