#include <rommap.h>

/* Custom event-VM opcode 0x0350 ("expanded text"): wires English dialogue longer than the original
   Japanese WITHOUT shifting any bytecode (so every existing jump stays valid).

   Inline form written into the script stream by patch_dialog.py, replacing the message head:
       [0x0350][ptr_lo][ptr_hi]   (3 u16 words)
   where ptr = the pooled English u16 string (normal glyph/control codes, ending in 0x0301).

   We simply REDIRECT the VM into the pooled string (set base = ptr, pc = 0) — a jump, not a call.
   The pooled string's own 0x0301 then ends exactly as the original message's would: ScriptOp_EndMessage
   does a real end-of-dialogue when no caller level is set, or returns to the caller when one is.  We
   deliberately do NOT touch the level/return stack — an earlier call/return version made a terminal
   message wrongly resume into the *next* message (extra glyph + extra confirm).  Because we never come
   back, the leftover original bytes after the 3-word head are dead, and {WAIT}/{PAGE}/name codes and any
   trailing opcodes (e.g. the macca-hide op) just live in the pooled copy and run natively.
   (`cave_entry` is the linker ENTRY / gc-sections root; registered into the handler table by patch_dialog.py.) */
__attribute__((used, section(".text.entry")))
void cave_entry(void)
{
    unsigned short  *pc   = (unsigned short  *)RM_SCRIPT_PC;        /* u16 PC index (points past 0x0350) */
    unsigned short **bp   = (unsigned short **)RM_SCRIPT_BASE_PTR;  /* -> current base ptr */
    unsigned short  *base = *bp;
    unsigned int i   = *pc;
    unsigned int ptr = (unsigned int)base[i] | ((unsigned int)base[i + 1] << 16);

    *bp = (unsigned short *)ptr;     /* jump: run the pooled English as the message */
    *pc = 0;
}
