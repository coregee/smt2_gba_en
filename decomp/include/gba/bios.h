#ifndef GUARD_GBA_BIOS_H
#define GUARD_GBA_BIOS_H

/* The game's BIOS call wrappers (0x0815CAF4-0x0815CB2A). */
void CpuFastSet(const void *src, void *dest, u32 control);
void CpuSet(const void *src, void *dest, u32 control);
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);
void ObjAffineSet(void *src, void *dest, s32 count, s32 offset);
void RLUnCompWram(const void *src, void *dest);
void SoftReset(u32 resetFlags);
void VBlankIntrWait(void);

#define CPU_SET_16BIT 0x00000000
#define CPU_SET_32BIT 0x04000000
#define CPU_SET_SRC_FIXED 0x01000000

#endif
