#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "global.h"

struct PartyMember
{
    u8 name[13];
    u8 level;
    u16 unk0E;                   /* non-zero when the slot is in use */
    u8 pad10[0x30];
    s8 stats[6];                 /* 0x40 */
    u8 pad46[2];
    s16 unk48[4];                /* 0x48 */
    s16 unk50[4];                /* 0x50 */
    u8 pad58[0x28];
};

/* Game state block (the live copy, or a save slot loaded into 0x02017874 by the save screen). */
struct GameState
{
    struct PartyMember party[4];
    u8 pad200[0xA00 - 0x200];
    u8 names[4][8];              /* 0xA00: extra character names, 8 bytes each, 0xFF-padded */
    u8 padA20[0xA2C - 0xA20];
    u16 unkA2C;
    u16 unkA2E;
    u16 unkA30;
    u16 unkA32;
    u16 unkA34;
    u16 padA36;
    u16 unkA38;
    u16 unkA3A;
    u16 unkA3C;
    u16 padA3E;
    u8 unkA40[0x3C];                  /* 0x3C bytes, copied to/from 0x030069F0 */
    u8 padA7C[0xAC0 - 0xA7C];
    u16 unkAC0;
    u8 unkAC2;
    u8 padAC3[0xAE4 - 0xAC3];
    u8 unkAE4[0x15E8 - 0xAE4];
    u8 flags[0x100];             /* event flag bitfield, tested by GameState_TestFlag */
    u8 pad16E8[0x18A0 - 0x16E8];
    u16 unk18A0;
    u16 unk18A2;
    u16 unk18A4;
    u16 unk18A6;
    u16 unk18A8;
    u16 unk18AA;
    u8 pad18AC[4];
    u32 unk18B0;
};

extern struct GameState gSaveSlotPreview;
extern u8 gUnknown_081AF7B8[];
extern u8 gUnknown_084F20A4[];
extern u16 gUnknown_084F20A8[];
extern u8 gUnknown_084F20EC[];
extern u8 gUnknown_084F20F4[];
extern u8 gUnknown_084F20F8[];
extern u16 gUnknown_080A94AC[][16];
extern u8 gUnk_0200F874[];

void Canvas_BlitOr(void *src, void *dst, u32 a2, u32 a3, u16 x, u16 y, u32 w, u32 h);
void Font_DrawGlyphTinted(u16 glyph, void *dst, u16 x, u16 y, u32 tint);
u16 *Location_GetNameCellFromCoords(u16 a, u16 b, u16 c, u16 d);
void DungeonMap_GetFloor(u16 a, u16 b);
u16 *sub_080C8B54(u16 a);
void sub_080CCE5C(const void *str, u16 x, u16 y, u32 a3);
void sub_080CCF44(u32 num, u16 x, u16 y, u32 a3);
void sub_080D01B0(void *a, u16 x, u16 y, u32 a3);
void Menu_DrawCombatantName8px(u8 *name, u16 x, u16 y);
u32 GameState_TestFlag(struct GameState *state, u32 flag);
void SaveScreen_DrawLocationName(struct GameState *state, u16 mode, u16 x, u16 y);
void SaveScreen_DrawTokenString(u16 *str, u16 y);
u32 SaveSlot_Read(u32 slot, struct GameState *dst, u32 a2);
u32 SaveSlot_IsValid(u32 slot);

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

/* Save/load screen state at 0x0203A454. */
struct SaveMenu
{
    u16 mode;
    u16 unk02;
    u16 unk04;
    u16 cursor;
    u16 unk08;
    u16 unk0A;
    union
    {
        struct
        {
            u8 *unk0C;
            u32 window[4];       /* 0x10: lazily created text windows */
            u32 unk20;
            u8 pad24[0x04];
            u32 unk28;
            void *unk2C;
        } save;
        struct
        {
            u16 menuCursor;      /* 0x0C */
            u16 delay;           /* 0x0E */
            u16 done;            /* 0x10 */
            u16 unk12;
            u16 nameLen;         /* 0x14 */
            u16 msgShown;        /* 0x16 */
            u16 gfxQueued;       /* 0x18 */
            u8 name[8];          /* 0x1A: 0xFF-terminated, at most 8 characters */
            u8 pad22[2];
            u32 window;          /* 0x24 */
        } name;
    } u;
};

extern struct SaveMenu gMenuState;
extern u16 gUnk_03000040;
extern u8 gUnknown_081B93B0[];
extern u8 gUnknown_084F20FE[];
extern u8 gUnknown_084F2110[];
extern u8 gUnknown_084F2118[];
extern u8 gUnknown_084F2124[];
extern u8 gUnknown_084F212C[];

u32 TextWindow_CreateOpenWithFrame(u32 a0, u32 x, u32 y, u32 w, u32 h, const void *frame);
void VBlankTask_AddCounted(void (*func)(void), u32 a1);
void sub_080CCEC8(const void *str, u32 x, u32 y, u32 a3);
void sub_080D0264(void);
void SaveScreen_DrawSlot(u32 unused, u32 slot);
extern vu16 gKeysNew;
extern u32 gFrameCounter;
extern u8 gUnknown_08001000[];
void Sprite_Draw(const void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 x, u16 y);
void Sound_Play(u32 sfx);
void Text_DrawSpriteString(void *str, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void BgMap_SetPaletteRect(u16 (*map)[32], u16 pal, u16 x, u16 y, u16 w, u16 h);

struct MenuTask
{
    u8 pad00[0x1C];
    u16 unk1C;
    u16 unk1E;
};

struct Unk03004550
{
    u16 unk00;
    u16 unk02;
    u8 pad04[0x0E];
    u16 unk12;
    u16 unk14;
};

extern struct GameState gGameState;
extern struct Unk03004550 gFieldState;
extern u16 gRepeatedKeys;
extern u32 gUnk_03004614;
extern u32 gUnk_03004514;
extern u32 gUnk_03003FC4;
extern u32 gUnk_03004618;
extern u8 gUnk_030069F0[0x3C];
extern u8 gUnknown_084F1F7C[];
extern u8 gUnknown_084F1FA8[];
extern u8 gUnknown_084F1FD4[];

void SetMainCallback(void (*func)(void));
void sub_080B710C(u16 a, u16 b, u16 c, u16 d, u16 e, u32 f);
void Game_NewGame(void);
void Flag_Clear(u32 a);
u32 Flag_Test(u32 flag);
void sub_080C2A50(u32 a, u32 b);
void sub_080C2CD8(s32 a, s32 b, u32 c);
void sub_080D0084(void *a, const void *str, u32 c);
void sub_080D96BC(void);
u32 SaveSlot_Write(u32 slot, struct GameState *src);
u32 SaveSlot_ClearSuspend(void);
void sub_080D0BA0(void);
void GameState_StoreLocation(u32 mode);
extern u32 gUnk_03003BB4;
extern u32 gYesNoResult;
extern u8 gWindowTilemapBuffer[];
extern u8 gUnk_02018874[];
void Window_Close(u32 window, u32 a1);
void TextWindow_Close(u32 window, u32 a1);
void Field_Step(u16 a);
u16 sub_080B1A1C(u16 a);
s32 Combatant_GetAlignment(u32 a);
void Flag_Set(u32 flag);
void Music_Play(u32 a);
void Music_FadeOut(u32 a);
void sub_080C6558(void);
void sub_080D5B8C(u32 a);
u32 sub_080D0E74(void);

/* Cartridge SRAM layout (0x0E000000):
 *   0x0000  header: u32 magic 0x10241179, u32 version 0x11, ...
 *   0x007C  u32 valid[4]     one per slot; slot 3 is the suspend/quick save
 *   0x008C  u32 checksum[4]  byte sum of the slot data
 *   0x009C  slot data, 0x1B00 apart, 0x18F8 bytes used (sizeof the game state) */
#define SRAM_BASE           ((u8 *)0x0E000000)
#define SAVE_SLOT_SIZE      0x18F8
#define SAVE_SLOT_STRIDE    0x1B00

/* Image of the 32 KB SRAM as built in RAM by Sram_FormatIfInvalid when formatting. */
struct SramImage
{
    u32 magic;
    u32 version;
    u32 pad08[2];
    u32 unk10;
    u8 pad14[0x6C9C - 0x14];
    u16 unk6C9C;                 /* 0x6C9C: just past the four slots */
    s16 unk6C9E;
    u16 unk6CA0;
    u16 unk6CA2;
};

extern u16 gUnk_030031B4;
extern u8 gUnknown_084F2134[];
u32 Task_Create(const void *a, u32 b);
void sub_080C2704(void);
void sub_080C271C(void);
void sub_080C27BC(void);
void sub_080C27F0(void);
void sub_080C2950(void);
void sub_080C2968(void);
void sub_080C2980(void);
void ComboBits_Clear(void);
void sub_0815CB50(const void *src, void *dst, u32 size);
void sub_0815CBB4(const void *src, void *dst, u32 size);
u32 sub_0815CC24(const void *a, const void *b, u32 size);
u32 Sram_WriteVerified(const void *src, void *dst, u32 size);
u32 Sram_ReadVerified(const void *src, void *dst, u32 size);
extern u8 gUnknown_084F2BFC[];
extern u8 gUnknown_084F2974[];
extern u8 gUnknown_084F2DBC[];
extern u8 gUnknown_081B6E90[];
extern u16 gUnk_0200E7D4[];
extern u8 gBgPictureBuffer[];
extern u16 gUnk_03000004;
extern u16 gUnk_03002E10[0x200];       /* palette buffer (BG then OBJ) */
extern u8 gUnk_02000000[];
void Palette_MarkDirty(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void sub_080C6E30(u32 a);
void Combatant_DecodeName(const u8 *name, u16 *out);
u32 Font_GetGlyphBitmap(u16 glyph);
void Font_CopyGlyphCell(u32 glyph, void *dst);
void Font_ResetGlyphSpriteCache(u32 a);
u32 Window_Create(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_080D1498(void);
void sub_080D1538(void);
void NameEntry_RenderName();  /* NameEntry_Backspace passes it an (unused) argument */
extern const void *gUnknown_084F3040[];
extern u8 gUnknown_0800276C[];
extern u8 gUnknown_080027CC[];
extern u8 gUnknown_080027BC[];
extern u16 gNameEntryCharGrid[];         /* name entry character grid, 25 rows of 11 */
extern u8 gUnknown_084F3002[];
extern u8 gUnknown_084F302A[];
extern u8 gUnknown_084F3038[];
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
void Sprite_DrawSingle(const void *a0, u32 a1, u32 a2, u32 a3, u16 a4, u16 x, u16 y);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
u8 sub_080C03A8(u16 glyph);
void NameEntry_Backspace(struct MenuTask *task);
extern u16 gUnknown_084F3060[];
extern u8 gUnknown_081B13B8[];
extern u16 gUnk_0200F7D8[];
u8 *Party_GetMember(u16 id);
void sub_080C1440(void);
void sub_080C6FD8(void);
void Party_BuildMemberNameTiles(void);
u32 Name_Equals8(const u8 *a, const u8 *b);
extern u8 NameEntry_InitAllyNameInput[];
extern u8 gUnknown_081B5870[];
extern u8 gUnknown_081AE5B8[];
extern u8 gUnknown_081B6ED0[];
void sub_080D1DF4(void);
void sub_080D1EBC(void);
void sub_080D1EE8(void);
void sub_080D1F0C(void);

/* Layout used by the status-screen code from sub_080D1FFC on (same block at 0x0203A454). */
struct Window
{
    u8 pad00[0x24];
    u8 unk24[0];
};

struct StatusMenu
{
    u16 mode;
    u16 unk02;
    u16 id;                      /* 0x04: demon / character id shown */
    u16 member;                  /* 0x06 */
    u8 pad08[0x08];
    u16 page;                    /* 0x10: description page */
    u16 pageCount;               /* 0x12 */
    struct Window *window14;
    struct Window *window18;
    struct PartyMember backup;   /* 0x1C */
    u16 items[3];                /* 0x9C */
};
#define STATUS_MENU ((struct StatusMenu *)&gMenuState)
extern u8 gUnknown_084F310C[];
extern u8 gUnknown_081B8170[];
extern u8 gWindowTilemapBuffer[];
void Tilemap_FillRect(u32 a0, void *buf, u32 x, u32 y, u32 w, u32 h);
void TextWindow_DrawFrame(void *a0, u32 x, u32 y, u32 w, u32 h);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void sub_080C6764(void);
u32 Combatant_GetEquip(u8 a, u16 b);
void sub_080D21C4(u16 *a, u16 *b);
u32 sub_080D2268(u16 id);
void Font_DrawGlyph(u16 glyph, void *dst, u32 x, u16 y);
void sub_080CD330(u16 id, u32 x, u32 y, u32 w);
void sub_080CD38C(u16 id, u32 x, u32 y, u32 w);
void sub_080CD3E8(u16 id, u32 x, u32 y, u32 w);
void sub_080CD45C(u16 id, u32 x, u32 y);
void sub_080CD50C(u16 id, u32 x, u32 y);
void sub_080CD668(u16 id, u32 x, u32 y, u32 w);
void sub_080CD6C4(u16 id, u32 x, u32 y, u32 w);
void sub_080CD720(u16 id, u32 x, u32 y);
void sub_080CD8C4(u16 id, u32 x, u32 y);
void Combatant_SetEquip(u8 a, u16 b, u16 c);
void Combatant_RecalcStats(u8 a);
u32 sub_080D229C(u16 id, u8 *combatant);
void sub_080CCFC4(s32 value, u32 x, u16 y, u32 color);
void StatsPage_ApplyPreview(u8 *combatant, u16 id);
void StatsPage_RestoreCombatant(u8 *combatant);
extern u8 gUnknown_084F311E[];
extern u8 gUnknown_084F312C[];
extern u8 gUnknown_084F313C[];
extern u8 gUnknown_084F3140[];
extern s32 gUnk_0203DB2C;
void Text_DrawStringTinted(const void *str, void *dst, u32 x, u32 y, u32 tint, u32 lineH);
void Text_DrawString(const u16 *str, void *dst, u32 x, u32 y, u32 lineH);
u8 *Item_GetRecord(u16 id);
u8 *Action_GetRecord(u16 id);
u8 *Demon_GetRecord(u16 id);
void StatsPage_DrawLabelGrid(void);
void StatsPage_DrawBaseStats(void);
void StatsPage_DrawDerivedStats(void);
void StatsPage_DrawDerivedStats2(void);
void Menu_DrawItemNameTriple();
void Menu_DrawSkillRowTriple();
u16 Action_CountDescriptionBreaks(u16 id);
void sub_080D2D58(void);

#endif
