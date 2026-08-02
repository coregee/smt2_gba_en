/* cave_resultmsg.c — sentinel-template rebuild of the two rigid battle-result composers.
 *
 * Battle_BuildRaceCountText 0x080eb8dc (悪魔N体をしとめた) and Battle_BuildActorStatusText
 * 0x080eb71c (おっと！NAMEは平気だ) splice the name/digits at HARDCODED template offsets,
 * which no readable English can satisfy ("Pixie3 d\nown!").  Their single BL call sites
 * are repointed here instead: when the (repointed, pooled) English template carries the
 * battlefrag-style insertion sentinels —
 *     0xFFFE  the actor/species name
 *     0xFFFF  the count digits (cave_count only)
 * — the message is rebuilt freely in template order ("Defeated {name} x{count}!",
 * "Whew! {name} is OK!").  A sentinel-less template (the untouched JP inline original)
 * tail-calls the stock composer, byte-identical behavior.
 *
 * Names emit as the 1-token 0xF000|id MARKER when NAME_TABLE has English (the hooked
 * sprite renderer expands it full-length VWF — same convention as cave_battlename);
 * otherwise the JP inline name (record+0x22, cap 8).  Humans (combatant type < 4)
 * decode their entered name via Combatant_DecodeName (already English letters).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

#define SENT_NAME  0xFFFEu
#define SENT_VALUE 0xFFFFu

/* EVERY stock composer this file replaces begins with the same interlock:
 *     if (msg-state done flag (+7) == 1) return COMPOSE_BUF;   -- compose NOTHING
 * The done flag is the "a locked message is on display" latch (set e.g. by the
 * auto-battle banner code @0x080E910C right after it shows みんな一生懸命闘っている
 * -- whose live stream pointer IS COMPOSE_BUF).  BattleMenu_SetMode no-ops on the
 * same flag, so in stock a mid-banner dodge/reward event is silently swallowed.
 * The EN sentinel paths run INSTEAD of the stock heads (call-site repoints), so
 * without this guard they clobbered the banner's on-screen buffer ("Everyone is
 * fighting hard." morphing into "Yes! <name> dodged!", user-reported 2026-07-10). */
#define MSG_LOCKED()  (*(volatile u8 *)(RM_BMSG_STATE + 7) == 1)

typedef u32 (*rec_fn)(u32);
typedef void (*decname_fn)(void *c, u16 *out);
typedef u8 *(*digits_fn)(u32 v);
typedef u16 *(*count_fn)(u32 id, u32 count, const u16 *tmpl);
typedef u16 *(*status_fn)(void *c, const u16 *tmpl);
typedef u16 *(*reward_fn)(void *c, u32 v, const u16 *strs);
typedef u16 *(*valreward_fn)(u32 v, const u16 *strs);
typedef u16 *(*itemdrop_fn)(u32 id, const u16 *base);

#define GetRecord   ((rec_fn)(RM_Combatant_GetRecord | 1))
#define DecodeName  ((decname_fn)(RM_Combatant_DecodeName | 1))
#define IntToDigits ((digits_fn)(RM_Math_IntToDigits8 | 1))
#define OrigCount   ((count_fn)(RM_Battle_BuildRaceCountText | 1))
#define OrigStatus  ((status_fn)(RM_Battle_BuildActorStatusText | 1))
#define OrigReward  ((reward_fn)(RM_Battle_BuildRewardText | 1))
#define OrigValReward ((valreward_fn)(RM_Battle_BuildValueRewardText | 1))
#define OrigItemDrop  ((itemdrop_fn)(RM_Battle_BuildItemDropText | 1))
#define BUF         ((u16 *)RM_COMPOSE_BUF)
#define DIGITS      ((const u16 *)RM_DIGIT_GLYPH_TABLE)

static int has_name_sentinel(const u16 *t)
{
    int i;
    for (i = 0; i < 64 && t[i]; i++)
        if (t[i] == SENT_NAME) return 1;
    return 0;
}

static int has_value_sentinel(const u16 *t)
{
    int i;
    for (i = 0; i < 64 && t[i]; i++)
        if (t[i] == SENT_VALUE) return 1;
    return 0;
}

static u16 *emit_species(u16 *o, u32 id)
{
    if (id < RM_NAME_COUNT && ((u16 *const *)RM_NAME_TABLE)[id]) {
        *o++ = (u16)(0xF000u | id);           /* marker: renderer draws English */
    } else {
        const u16 *n = (const u16 *)(GetRecord(id) + 0x22);
        u16 *lo = o;
        int k;
        for (k = 0; k < 8 && n[k]; k++) *o++ = n[k];
        while (o > lo && o[-1] == 0x70) o--;  /* trailing-pad trim (JP names) */
    }
    return o;
}

static u16 *emit_digits(u16 *o, u32 v)
{
    u8 *d = IntToDigits(v);
    int top = 7;
    while (top > 0 && d[top] == 0) top--;
    for (; top >= 0; top--) *o++ = DIGITS[d[top]];
    return o;
}

static u16 *build(const u16 *t, u16 *o, u32 nameIsHuman, void *hum, u32 speciesId, u32 value)
{
    int i;
    for (i = 0; i < 64 && t[i]; i++) {
        if (t[i] == SENT_NAME) {
            if (nameIsHuman) {
                u16 nb[10];
                int k;
                for (k = 0; k < 10; k++) nb[k] = 0;
                DecodeName(hum, nb);
                for (k = 0; k < 8 && nb[k]; k++)
                    if (nb[k] != 0x70) *o++ = nb[k];   /* skip pad glyphs */
            } else {
                o = emit_species(o, speciesId);
            }
        } else if (t[i] == SENT_VALUE) {
            o = emit_digits(o, value);
        } else {
            *o++ = t[i];
        }
    }
    *o = 0;
    return BUF;
}

__attribute__((used, section(".text.entry")))
u16 *cave_entry(u32 speciesId, u32 count, const u16 *tmpl)   /* count-message entry */
{
    if (MSG_LOCKED())
        return BUF;
    if (!has_name_sentinel(tmpl))
        return OrigCount(speciesId, count, tmpl);     /* JP template: stock path */
    return build(tmpl, BUF, 0, 0, speciesId & 0xFFFF, count & 0xFFFF);
}

__attribute__((used))
u16 *cave_status(void *c, const u16 *tmpl)
{
    if (MSG_LOCKED())
        return BUF;
    if (!has_name_sentinel(tmpl))
        return OrigStatus(c, tmpl);                   /* JP template: stock path */
    if (*((u8 *)c + 0xc) < 4)                         /* human: entered name */
        return build(tmpl, BUF, 1, c, 0, 0);
    return build(tmpl, BUF, 0, 0, *(u16 *)((u8 *)c + 0x12), 0);
}

/* Dodge line (FUN_080eb618, called from FUN_080f0cfc when an enemy attack misses -> the defender
 * dodged).  Same exclamation+name+suffix shape as cave_status ("やった！\n<name>はかわした"), and it
 * builds into the SAME COMPOSE_BUF (DAT_080eb718 = 0x0203CAEC) which the caller hands to
 * Battle_ShowMenuMode(3,...).  Unlike the status composer it takes NO template arg -- it loads its
 * fragment from an internal literal -- so cave_dodge reads the (extra_refs-repointed) pooled EN
 * name-sentinel template from that same literal and rebuilds freely ("Yes!\n<name> dodged!").  A JP
 * (un-repointed) template has no sentinel -> stock builder, byte-identical. */
typedef u16 *(*dodge_fn)(void *c);
#define OrigDodge ((dodge_fn)(RM_Battle_BuildDodgeText | 1))
__attribute__((used))
u16 *cave_dodge(void *c)
{
    const u16 *tmpl;
    if (MSG_LOCKED())
        return BUF;
    tmpl = *(const u16 *const *)RM_Battle_DodgeTemplatePtr;
    if (!has_name_sentinel(tmpl))
        return OrigDodge(c);                          /* JP template: stock path */
    if (*((u8 *)c + 0xc) < 4)                         /* human: entered name */
        return build(tmpl, BUF, 1, c, 0, 0);
    return build(tmpl, BUF, 0, 0, *(u16 *)((u8 *)c + 0x12), 0);
}

/* EXP-reward line (Battle_BuildRewardText call site).  The original walks three
 * consecutive 0-terminated strings from the base ({n} / は{n} / のEXPを得た); the EN
 * path repoints the base literal at ONE pooled sentinel template instead
 * (system_menu 08124298 "{=feff} gained {=ffff} EXP!"). */
__attribute__((used))
u16 *cave_reward(void *c, u32 v, const u16 *strs)
{
    if (MSG_LOCKED())
        return BUF;
    if (!has_name_sentinel(strs))
        return OrigReward(c, v, strs);                /* JP strings: stock path */
    if (*((u8 *)c + 0xc) < 4)
        return build(strs, BUF, 1, c, 0, v);
    return build(strs, BUF, 0, 0, *(u16 *)((u8 *)c + 0x12), v);
}

/* Value-only reward line (macca / magnetite — Battle_BuildValueRewardText call sites).  The
 * original walks three consecutive strings from the base ({n} / を{n}マッカ手に入れた / …)
 * splicing the digits at the break; the EN path repoints the base literal at ONE pooled
 * template carrying just the value sentinel ("{=ffff} Macca obtained!").  No combatant /
 * name here (signature is (value, strs), not (c, value, strs)). */
__attribute__((used))
u16 *cave_valreward(u32 v, const u16 *strs)
{
    if (MSG_LOCKED())
        return BUF;
    if (!has_value_sentinel(strs))
        return OrigValReward(v, strs);                /* JP strings: stock path */
    return build(strs, BUF, 0, 0, 0, v);
}

/* Item-drop line (Battle_BuildItemDropText call site).  The original composes
 * "{n}[item]を拾った" (item name spliced in the MIDDLE).  To read "Obtained [item]" the
 * name must MOVE after the verb, so the EN base is repointed to a name-sentinel template
 * ("Obtained {=fffe}") and we rebuild it, emitting the pooled English item name (ITEM_TABLE
 * [id], the same table patch_drop/patch_itemdrop fill) at the 0xFFFE.  Untranslated ids
 * (ITEM_TABLE empty — a few dummy slots) fall back to the stock JP composer with its
 * original base. */
__attribute__((used))
u16 *cave_itemdrop(u32 item_id, const u16 *base)
{
    u32 id = item_id & 0xFFFF;
    const u16 *name;
    u16 *o = BUF;
    int i;
    if (MSG_LOCKED())
        return BUF;
    name = (id < RM_ITEM_COUNT) ? ((const u16 *const *)RM_ITEM_TABLE)[id] : 0;
    if (!name)
        return OrigItemDrop(id, (const u16 *)RM_ITEMDROP_JP_BASE);   /* untranslated -> JP */
    for (i = 0; i < 64 && base[i]; i++) {
        if (base[i] == SENT_NAME) {
            const u16 *n = name;
            while (*n) *o++ = *n++;
        } else {
            *o++ = base[i];
        }
    }
    *o = 0;
    return BUF;
}

