typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>   /* RM_* address defines, generated from rom_layout.py */

/* Natural-order battle "wedge" — fixes the item-used / skill-cast battle-log lines.

   The three assemblers (Battle_BuildCombatSkillList, FUN_080eaf1c, Battle_BuildItemActionList) build the
   line as  name + frag[0] + {n} + name2 + frag[1:]  — the item/skill name2 is WEDGED between two halves
   of the fragment, so a pure fragment swap can only reach passive "Hiroko\nDia was cast".  patch_battlewedge
   replaces each wedge section with a call to this cave, which instead assembles
       <actor name, already in buf> + prefix + name2 + suffix
   from a fragment shaped  prefix 0xFFFF suffix  (tr.pack builds those from battlefrag.json's
   "[name]{n}used [item]." templates — the leading [name] is the engine's prepend, the newline is
   the template's own {n}, no longer hardcoded here), giving natural "Hiroko\ncast Dia."

   buf  = write cursor (after the actor name + its trailing-0x70 trim)
   frag = the (tr.pack-repointed English) fragment, read straight from the function's own literal
   arg/mode select name2:  mode 0 = skill via *(u8*)(combatant+0x5c), 1 = skill via action id (arg),
                           2 = item via *(u8*)(combatant+0x5c).  name2 is the inline u16[8] name at
                           Action record+6 / Item record+0xC.
   If the fragment has no 0xFFFF (e.g. an untranslated JP fragment), we copy it verbatim and skip the
   name — degraded but safe. */

typedef u32 (*rec_fn)(u32);
#define Action_GetRecord ((rec_fn)(RM_Action_GetRecord | 1))
#define Item_GetRecord32 ((rec_fn)(RM_Item_GetRecord32 | 1))
#define ITEM_TABLE ((const u16 *const *)RM_ITEM_TABLE)

/* name2 is the skill/item name.  For SKILLS, the action record's inline name field (+6) holds an
   English name <=8 glyphs OR the 0xFFFF SENTINEL when the EN name is longer (93/160 skills) -- the
   real name is then at the +8 pooled pointer (tr.pack writes it; the inline-only cap-8 copy used to
   render the bare 0xFFFF as garbage for Megidolaon/Mediarahan/Samarecarm/Marin Karin/...).  For ITEMS,
   route through ITEM_TABLE[id] (the canonical EN item pool, any length) with the JP +0xC inline as the
   fallback.  Pooled names are 0-/0x0301-terminated, so lift the cap to a full length for them. */
__attribute__((used, section(".text.entry")))
u16 *cave_entry(u16 *buf, const u16 *frag, u32 arg, u32 mode)
{
    const u16 *name2;
    int cap = 8;                                   /* inline record name field = 8 tokens */
    if (mode == 2) {
        u32 id = *(u8 *)(arg + 0x5c);
        name2 = (const u16 *)(Item_GetRecord32(id) + 0x0C);   /* JP inline fallback */
        if (id < RM_ITEM_COUNT && ITEM_TABLE[id]) {
            name2 = ITEM_TABLE[id];                /* pooled English item name */
            cap = 24;
        }
    } else {
        u32 rec = Action_GetRecord(mode == 1 ? arg : *(u8 *)(arg + 0x5c));
        name2 = (const u16 *)(rec + 6);
        if (name2[0] == 0xFFFF) {                  /* long EN skill: name is at the +8 pool pointer */
            name2 = *(const u16 *const *)(rec + 8);
            cap = 24;
        }
    }

    while (*frag && *frag != 0xFFFF) *buf++ = *frag++;  /* prefix  ("{n}cast " / "{n}used ") */
    if (*frag == 0xFFFF) {                              /* sentinel -> insert name2, then suffix */
        int i;
        frag++;
        for (i = 0; i < cap && *name2 && *name2 != 0x0301; i++) *buf++ = *name2++;
        while (*frag) *buf++ = *frag++;                 /* suffix  (".") */
    }
    return buf;
}
