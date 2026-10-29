#ifndef GUARD_BTEXT_H
#define GUARD_BTEXT_H

#include "global.h"

/* Battle message window state at 0x0203C9E0 (inside the large EWRAM block at 0x0203C200).
   Only the fields used by the battle text code are named. */
struct BattleMsg
{
    u8 mode;            /* 0x00: see BattleMenu_SetMode / BattleMsg_Update */
    u8 unk1;
    u8 delay;           /* frames until the next character is typed */
    u8 typed;           /* characters of src typed so far */
    u8 done;            /* 1 = player pressed a key or the auto-close timer ran out */
    u8 row;             /* window position: text y = row * 16 + 0x59 */
    u8 lines;           /* line count of the message (BattleMsg_FitWindow) */
    u8 locked;          /* 0x07: 1 = mode changes and text composition are ignored */
    u16 *src;           /* 0x08: message being typed */
    u16 text[0x40];     /* 0x0C */
    u16 text2[0x40];    /* 0x8C */
    u16 compose[0x40];  /* 0x10C: built by the MessageBox_Compose* / Battle_Build* functions */
    u16 autoClose;      /* 0x18C: 1 = close after autoCloseTimer frames */
    u16 autoCloseTimer; /* 0x18E */
};

struct BattleMsgBlock
{
    u8 filler0[0x7E0];
    struct BattleMsg msg;   /* 0x7E0 */
    struct Task *task;      /* 0x970 */
    void *window;           /* 0x974 */
};

extern u8 gUnk_0203C200[];
#define BLOCK ((struct BattleMsgBlock *)gUnk_0203C200)

void BattleMenu_SetMode(u8 mode, u16 *src);
void Font_ResetGlyphSpriteCache(u32 arg);
u8 *Demon_GetRecord(u16 id);
u16 *Race_GetName(u16 race);
u8 BattleMsg_FitWindow(u16 *src);
struct Task;
void Window_SetHeight(void *window, u32 arg1);
void Window_Close(void *window, u32 arg1);
void Task_End(struct Task *task);
void Text_DrawSpriteString(u16 *str, s32 a1, s32 a2, s32 a3, u16 y, s32 a5);
void Sprite_Draw(const void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
u16 Settings_GetBattleMsgSpeed(void);

extern u16 gKeysNew;               /* new keys */
extern u32 gFrameCounter;               /* frame counter */
extern u16 gUnk_030031D0;               /* held keys */
extern const u8 gBattleMsgSpeedFrames[];    /* frames per character, by message speed */
extern const u8 gUnknown_08001000[];    /* "next" arrow sprite */
extern const u32 gUnknown_086BEC98[];
extern const u16 gUnknown_086BED48[];
u16 *Battle_AppendCombatantName(u16 who, u16 *dst);
u8 *Battle_GetCombatant(u32 idx);
void Combatant_DecodeName(u8 *combatant, u16 *dst);
u8 *sub_080BF5C0(u16 id);
u8 *Action_GetRecord(u16 id);
u8 *Item_GetRecord(u16 id);
u8 *Equipment_GetRecord36_MidRange(u16 id);
bool32 Combatant_IsInParty(u16 idx);
bool32 Combatant_IsAlive(u16 idx);
s32 sub_080F4968(void);
extern const u16 gUnknown_0812430C[];
extern const u16 gUnknown_081236FC[];
extern const u16 *const gUnknown_086BED5C[];
extern const u16 *const gUnknown_086BEF5C[];
extern const u16 gBattleDigitGlyphs[];      /* digit glyphs */
u8 *NumberToDigits(u32 value);
extern const u16 gUnknown_08123BC2[];
extern const u16 gUnknown_081230BE[];
extern const u16 gUnknown_081236BC[];
extern const u16 gUnknown_08123708[];

#endif
