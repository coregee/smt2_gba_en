#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

/* Types and hardware definitions shared by all decompiled C.  The compiler is GCC 2.9
   (old_agbcc): no stdint.h, no C99. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef u8 bool8;
typedef u32 bool32;

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

/* Functions whose C does not reproduce the original instructions yet keep the readable C under
   #ifdef NONMATCHING and the original instructions (tools/naked.py) otherwise. */
#define NAKED __attribute__((naked))
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")

#include "gba/io_reg.h"
#include "gba/bios.h"

#endif /* GUARD_GLOBAL_H */
