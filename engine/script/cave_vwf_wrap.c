/* Runtime word-wrap safety net for EventVM_RunStep.
 *
 * The build-time autowrapper measures each corpus entry from column zero.  Negotiation
 * dialogue is different: its entries are callable fragments.  ScriptOp_EndMessage (0x0301)
 * returns to the caller without resetting g_wMsgTextCol/g_wMsgTextRow, so a second fragment
 * continues on the first fragment's visual line.  Independently safe fragments can therefore
 * overflow when the event VM composes them at runtime.
 *
 * patch_vwf hooks EventVM_RunStep immediately before it snapshots the current X/Y into a glyph
 * record.  At the start of each English word, this helper looks ahead in the active script stream
 * and measures that complete word with the same WIDTH_TABLE and EVENT_WRAP_PX used by tr.autowrap.
 * If it will not fit at the live pixel column, it performs the exact state changes made by
 * ScriptOp_Newline: X=0 and both row counters += 1.  The current glyph is then recorded on the new
 * row, so the whole word moves before any part of it is displayed.
 *
 * The hook is gated on an English current glyph.  Untranslated Japanese keeps the stock layout,
 * and authored {n}/{PAGE} behavior is untouched.  Runtime substitutions still use their existing
 * appenders; the next ordinary English word is protected at the same live composition boundary.
 */

typedef unsigned short u16;
typedef unsigned int u32;

#include <rommap.h>

#define COL (*(volatile u16 *)RM_MSG_TEXT_COL)
#define ROW (*(volatile u16 *)RM_MSG_TEXT_ROW)
#define BREAKS (*(volatile u16 *)RM_MSG_TEXT_BREAKS)
#define PC (*(volatile u16 *)RM_SCRIPT_PC)
#define CUR (*(volatile u16 *)RM_SCRIPT_CUR_OPCODE)
#define BASE (*(const u16 *volatile *)RM_SCRIPT_BASE_PTR)
#define WIDTH ((const unsigned char *)RM_WIDTH_TABLE)

static int is_english(u16 token)
{
    return token >= RM_ENG_LO && token < RM_ENG_HI;
}

static int is_control(u16 token)
{
    return token == RM_TERM_NUL || token == RM_TOK_NEWLINE || token == RM_TERM_MSG ||
           (token >= RM_OP_LO && token <= RM_VMCTRL_HI);
}

static int is_word_boundary(u16 token)
{
    /* 0x003f is the stock full-width space; RM_ENG_LO is the English VWF space. */
    return token == RM_ENG_LO || token == 0x003f || is_control(token);
}

__attribute__((noinline, used))
static u16 wrap_before_current_word(void)
{
    const u16 *base = BASE;
    u16 pc = PC;
    u16 current = CUR;
    u32 word_width;
    u32 i;

    if (COL == 0 || !is_english(current) || current == RM_ENG_LO || base == 0 || pc == 0)
        return COL;

    /* PC already points one word past CUR.  Only look ahead at a real word start: the first
       glyph of a fragment, or a glyph following a space/control in the same fragment. */
    if (pc > 1 && !is_word_boundary(base[pc - 2]))
        return COL;

    word_width = WIDTH[current];
    for (i = pc; i < pc + 64; i++)
    {
        u16 token = base[i];
        if (is_word_boundary(token))
            break;
        if (token >= RM_CODE_LO)
            break;
        word_width += WIDTH[token];
        if (word_width > RM_EVENT_WRAP_PX)
            break;
    }

    if ((u32)COL + word_width > RM_EVENT_WRAP_PX)
    {
        COL = 0;
        ROW++;
        BREAKS++;
    }
    return COL;
}

/* Replaces `ldrh r0,[r6]; movs r5,#13`.  r1-r3 are live record-placement values at the
 * hook and must survive; r4-r7 are ABI-preserved by the C helper.  Returning r0=COL and
 * r5=13 exactly recreates the two displaced instructions for the stock continuation. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "push {r1,r2,r3,lr}          \n"
        "bl   wrap_before_current_word \n"
        "movs r5, #13                \n"
        "pop  {r1,r2,r3,pc}          \n");
}
