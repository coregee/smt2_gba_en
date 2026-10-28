#ifndef GUARD_VM_H
#define GUARD_VM_H

#include "global.h"

/* Event/text script VM core (src/vm_*.c, docs/script-vm.md). Address-named until renamed. */

struct ScriptTask
{
    u8 filler0[0x1C];
    u16 unk1C;          /* 1 = the message task is finished */
};

typedef void (*ScriptFunc)(struct ScriptTask *);

/* glyph queue entry: 0x0203D800 (message window, 64 entries), 0x0203DA00 (second list) */
struct QueuedGlyph
{
    u16 glyph;
    u16 x;
    u16 y;
    u16 attr;
};

struct VmCombatant
{
    u8 filler0[0x18];
    s16 hp;
};

/* sprite slots drawn every frame by ScriptVM_DrawTask (0x03006620, 5 x 16 bytes) */
struct VmSpriteSlot
{
    u16 active;
    u16 pad2;
    u32 handle;
    u16 a;
    u16 b;
    u16 c;
    u16 padE;
};

/* 0x03006920, 3 x 8 bytes */
struct VmIconSlot
{
    u16 active;
    u16 a;
    u16 b;
    u16 pad6;
};

/* VM state */
extern u16 *gScriptBase;
extern u16 gScriptPc;
extern u16 *gScriptJumpTarget;
extern u16 gScriptCurOp;
extern s16 gScriptYield;
extern s16 gScriptWaitState;
extern u16 gTextColumn;
extern u16 gTextLine;
extern u16 gMsgGlyphCount;      /* queued glyph count */
extern s16 gScriptWaitBusy;      /* 1 = wait handler still busy: ScriptVM_Run returns */
extern s16 gUnk_0203DB5C;      /* wait-state frame counter */
extern s16 gUnk_0203DB48;      /* 1 = text drawn instantly (skip) */
extern s16 gUnk_0203DB4A;
extern u16 gUnk_0203DB46;
extern s16 gMsgWindowOpen;      /* message window open */
extern u32 gMsgWindow;      /* message window handle */
extern u16 gUnk_03006670;      /* 1 in battle */
extern s16 gUnk_0203DB7A;      /* message window layout */
extern u16 gMsgGlyphDelay;      /* frames per glyph */
extern s16 gMsgTextTop;      /* y of the first text line */
extern s16 gUnk_0203DB5E;
extern s16 gUnk_0203DB60;
extern u16 *gUnk_0203DAC8[];   /* jump targets of the current choice/menu */
extern vu16 gHeldKeys;
extern vu16 gNewKeys;
extern u32 gYesNoResult;

extern u16 gMsgGlyphQueue[];      /* message glyph queue: 64 x {glyph, x, y, attr} */
extern u16 gMsgGlyphList2[];      /* second glyph list, gMsgGlyphList2Count entries */

extern const ScriptFunc gUnknown_08790FDC[];
extern const ScriptFunc gScriptOpTable[];
extern const ScriptFunc gScriptOpAltTable[];

/* wait handlers */
extern u32 gUnk_030068E0;
extern u32 gUnk_03006954;
extern u32 gUnk_03006938;
extern u32 gUnk_03006964;
extern u16 gUnk_0203DB72;
extern u16 gUnk_030065E0;
extern s16 gUnk_030065E8;
extern u16 gUnk_03006944;
extern u32 gUnk_030068A4;
extern u32 gUnk_0203DB2C;
extern u32 gUnk_030037F0;
extern u16 gUnk_0203DB86;
extern u16 gUnk_0203DB7C;
extern u16 gUnk_0203DB7E;
extern u16 gUnk_0203DB80;
extern s16 gUnk_0300668C;
extern u32 gUnk_0203DB34;
extern const u16 gUnknown_0878FFD0[];
extern const u8 gUnknown_08790E4C[];
extern const u16 gUnknown_08790E5A[];
extern u16 gUnknown_08032CD8[];

s32 sub_080CE74C(u32);
s32 sub_080B7DF8(u32);
s32 sub_080D1EA8(u32);
s32 sub_080B8160(u32);
void Font_ResetGlyphSpriteCache(u32);
void sub_080B7E3C(u32, u32, u32, u32, u32);
u16 sub_0812DC10(void);
void sub_0812DC24(void);
void sub_080D34F0(u32);
s32 sub_080B9528(u32);
s32 SceneEffect_IsDone(void);
struct VmCombatant *Battle_GetCombatant(u16);
void sub_080C08E8(s32, u32);
void sub_080C84A0(void);
s32 sub_080B8B08(u32);
s32 sub_080C104C(void);
s32 sub_080C0A00(s16);
s32 sub_080F3EC8(s16);
u16 sub_08138CE8(void);
s32 sub_080D53E0(void);
u32 sub_080C31F0(void);
u32 sub_0812EEC4(void);
u16 Demon_GetField(u16, u16);
s32 sub_080D3AA0(u32);
s32 sub_080D3CCC(void);
u32 sub_080D3CE4(void);
s32 sub_080D4594(void);
s32 Window_IsIdle(u32);
s16 sub_080C07E0(u32);
u32 sub_080C0818(u32);
u32 sub_080C2244(void);
s32 sub_080C3100(void);
s32 sub_08135064(u16, u16);
void sub_080C30AC(s32);
void sub_081350CC(u16, u16);
u16 sub_0813560C(void);
u32 sub_08135370(void);
u32 sub_08135420(void);
u32 sub_081354B0(void);
u32 sub_08135540(void);

u32 Window_Create(u32, u32, u32, u32, u32);

/* ScriptVM_Run / renderer / init */
extern s16 gUnk_0300699C;
extern s16 gMsgGlyphList2Count;
extern struct VmSpriteSlot gUnk_03006620[5];
extern s16 gUnk_030069D0;
extern u16 gUnk_030069D8[3];
extern struct VmIconSlot gUnk_03006920[3];
extern u16 gUnk_03006958;
extern u16 gUnk_030066A0;
extern u16 gUnk_0300689C;
extern u16 gUnk_0300695C;
extern u16 gUnk_03006678[3];
extern s16 gUnk_0203DB52;
extern u16 gUnk_03006848;
extern u16 gUnk_03006680;
extern const u16 gUnknown_087923DC[];
extern const u16 gUnknown_087923FC[];
extern u16 gUnk_030065F0;
extern u16 gUnk_030069CC;
extern u16 gUnk_03006914;
extern u16 gUnk_030068AC;
extern u16 gUnk_030065E4;
extern u16 gUnk_030068A0;
extern u16 gUnk_0300693C;
extern u16 gUnk_030065FC;
extern u16 gUnk_0203DB56;
extern u32 gUnk_030069C0[2];
extern u32 gUnk_030068F0[8];
extern u16 gUnk_0203DB66;
extern u16 gUnk_0203DB68;
extern u16 gUnk_0203DB64;
extern u16 *gUnk_030068C4;
extern u16 gUnk_03006818;
extern u16 gUnk_03006600;
extern u16 gUnk_030065EC;
extern u16 *gUnk_030068D0;
extern u16 gUnk_03006610;
extern u16 gUnk_03006910;
extern struct ScriptTask *gUnk_030068B0;
extern u32 gUnk_030065F4;
extern u32 gUnk_030069E4;
extern u16 gScriptSubstBuf[16];
extern const u16 gUnknown_08790024[];
extern const u16 gUnknown_0878FB48[];
extern const u16 gUnknown_0878FB84[];

/* ScriptVM_RunAlt */
extern u16 gUnk_0203DB74;
extern u16 gUnk_0203DB76;
extern u16 gUnk_0203DB78;
extern u16 *gUnk_030068C0;
extern u16 gUnk_030068DC;
extern u8 gScriptFlagsBackup[0x168];
extern u8 gUnk_03005CA8[0x168];

/* demon helpers */
extern s16 gUnk_03006860;
struct VmGameState
{
    u8 pad0[0x1074];
    u8 unk1074[0x5E];   /* per demon id 0x54-0xB1 */
};
extern struct VmGameState gGameState;
extern u8 gUnk_0300684C;
extern u8 gUnk_030068B4;
extern u8 gUnk_030069E8;
union VmAlignByte
{
    u8 raw;
    struct
    {
        u8 lo:4;
        u8 hi:4;
    } bits;
};
extern union VmAlignByte gUnk_0300685C;   /* demon field 0x1F of the enemy leader */
extern u16 gUnk_0203DB28[2];
extern u16 gUnk_0203DB70;
extern u16 gUnk_0203DB6A;
extern u32 gUnk_0203DB30[];
extern u32 gUnk_03004530;
extern u16 gUnknown_08032C78[];
extern u16 gUnknown_08032D4C[];
extern u16 gUnknown_08032CA8[];
extern u16 gUnknown_08084020[];

void Window_Close(u32, u32);
void sub_080AF3FC(void);
void sub_080C51D4(u32);
void FontSprite_DrawGlyphTinted(u16, u16, u16, u16, u16, u16);
void Sprite_DrawNumber8(u32, u16, u16, u16);
void sub_080C6B40(u16, u32, u32, u32, u32);
void sub_080D3170(u16, u32, u32, u16);
void sub_080C49EC(u16, u32, u32, u16, u16);
void sub_080C4AB0(u32, u32, u32, u32);
void sub_080C4A4C(u32, u32, u32, u32);
void sub_0813EB6C(u16);
u16 ScriptVM_GetTextSpeed(void);
u32 Task_Create(const u16 *, u32);
u16 Settings_GetBattleMsgSpeed(void);
u16 sub_080C2AFC(void);
void ScriptVM_SaveFlags(void);
void ScriptVM_RestoreState(void);
u8 *sub_080BF648(u16);
s32 sub_080C09B0(u16);
u16 sub_08134C3C(u16);
u16 sub_0813E804(u16);
u16 sub_0813E854(u16);
u32 sub_080C1D9C(void);
u16 sub_0813E8A8(void);
u32 sub_080C0794(u32);
void sub_080EF930(u8);
u16 sub_080C0F8C(u32);
void sub_080EF978(u8);
void sub_0815BAC8(u16, u32);
void ScriptVM_Init(u16 *, u16);
u32 sub_080EDA24(u32);

#endif /* GUARD_VM_H */
