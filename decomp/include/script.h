#ifndef GUARD_SCRIPT_H
#define GUARD_SCRIPT_H

#include "global.h"

/* Event/text script VM state (see docs/script-vm.md). Address-named until renamed. */

struct ScriptTask
{
    u8 filler0[0x1C];
    u16 unk1C;          /* set to 1 when the message ends (ScriptOp_End) */
};

extern u16 *gScriptBase;   /* current script base */
extern u16 gScriptPc;    /* program counter, in words from gScriptBase */
extern u16 *gScriptJumpTarget;   /* pending jump: picked up by ScriptVM_Run (pc := 0) */
extern u16 gTextColumn;    /* text cursor column */
extern u16 gTextLine;    /* text cursor line */
extern u16 gMsgGlyphCount;    /* queued glyph count */
extern u16 gUnk_0203DB46;
extern u16 gUnk_0203DB4A;
extern u16 gScriptWaitState;    /* VM wait state, indexes the table at 0x08790FDC */
extern u16 gUnk_0203DB5E;
extern u16 gUnk_0203DB60;
extern u16 gScriptYield;    /* yield: ScriptVM_Run stops after the handler when 1 */

/* gosub return stack, unrolled into separate variables (ScriptOp_End) */
extern u16 *gUnk_0203DAC8[];
extern u16 gUnk_030069CC;
extern s16 gUnk_03006910;
extern u16 gUnk_03006610;
extern u16 *gUnk_030068D0;
extern s16 gUnk_030065EC;
extern u16 gUnk_03006960;
extern u16 *gUnk_03006854;
extern s16 gUnk_03006600;
extern u16 gUnk_030069E0;
extern u16 *gUnk_03006674;
extern s16 gUnk_0203DB64;
extern u16 gUnk_03006818;
extern u16 *gUnk_030068C4;
extern u32 gUnk_030069E4;

extern const u16 gUnknown_08790180[];

void sub_0813EB6C(u32);
void Font_ResetGlyphSpriteCache(u32);
void Task_End(u32);
void Music_Play(u32);
void Sound_Play(u32);

extern u16 gUnk_0203DB28[];  /* [0],[1]: ids for the two display slots (ScriptOp_308/309,
                                sub_08132890); 0x31E/0x322 use them as demon ids */
extern u16 gUnk_03006970[];
extern u16 gUnk_0203DB66;
extern u16 gUnk_0203DB68;
extern u16 gScriptItemCheckId;    /* item id tested by ScriptOp_JumpIfItemMissing (set by 0x30A) */
extern u16 gScriptSubstSavedPc;
extern u16 *gScriptSubstSavedBase;
extern s16 gUnk_0203DB48;    /* message skip (B held) */
extern s16 gMsgWindowOpen;    /* message window open */
extern u32 gMsgWindow;
extern u16 gUnk_0203DB52;
extern u16 gUnk_0203DB54;
extern u16 gUnk_0203DB56;
extern u16 gUnk_0203DB5C;
extern u16 gUnk_030068A8;
extern u32 gUnk_030068B0;
extern u32 gUnk_030068E0;
extern u32 gUnk_030068F0[];
extern u32 gUnk_030069C0[];

struct PartySlot
{
    u8 filler0[0x18];
    u16 unk18;
    u8 filler1A[0x66];
};
extern struct PartySlot gGameState[];

extern const u16 gUnknown_087900A0[];
extern const u16 gUnknown_087900EC[];

u32 CharObj_Create(u16, u16, u16, u16, u32, u32);
u8 *Char_GetRecord(u16);
u32 BgPicture_StartTask(u16);
void sub_080E9044(u32, u16);
void CharObj_End(u32, u32);
u32 sub_080E8E00(u16, u16);
s32 KeyItem_IsObtainable(u16);
void Inventory_AddItem(u16);
bool8 Inventory_GetCount(u16);
u16 sub_080C2A84(u32);
s32 Flag_Test(u16);
s32 Combatant_IsUsed(u32);
u16 Combatant_GetStatus(u32);
u32 YesNo_Create(u32);
void sub_080E47A8(u32, u16, u16, u16, u16);
void Flag_Set(u16);
void Flag_Clear(u16);
void Window_Close(u32, u32);
void Task_Create(const u16 *, u32);
void sub_08132890(void);

/* text substitution (ScriptOp_Substitute) */
extern u16 gScriptSubstBuf[16]; /* substitution string buffer, 0x318-terminated */
extern u16 gScriptCurOp;     /* opcode being executed */
extern u16 gUnk_03006670;     /* 1 in battle */
extern u16 gUnk_03006850;
extern u16 gUnk_0203DB7C;
extern u16 gUnk_0203DB7E;
extern u16 gUnk_0203DB80;
extern u16 gUnk_0203DB72;
extern u32 gUnk_0203DB2C;
extern u32 gUnk_0203DB30;
extern s16 gUnk_0300696C;
extern s16 gUnk_030069A0[];
extern const u16 gScriptDigitGlyphs[]; /* digit glyphs 0-9 */
extern const u16 gUnknown_0878F9CC[];
extern const u16 gUnknown_0878EF04[];

void Combatant_DecodeName(struct PartySlot *, u16 *);
struct PartySlot *sub_080C10E4(u16);
u8 *Demon_GetRecord(u16);
u16 *Race_GetName(u16);
u8 *sub_080BF5C0(u16);
u8 *Item_GetRecord(u16);
u8 *Equipment_GetRecord36_MidRange(u16);
u8 *Action_GetRecord(u16);
s32 Combatant_IsAlive(s16);
s32 sub_080C31F0(void);

#define SCRIPT_READ() (gScriptBase[gScriptPc++])

#endif /* GUARD_SCRIPT_H */
