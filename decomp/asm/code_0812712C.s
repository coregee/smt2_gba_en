	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0812712C
sub_0812712C: @ 0x0812712C
	push {r4, lr}
	ldr r1, .L0812719C
	ldr r0, .L081271A0
	str r0, [r1]
	ldr r0, .L081271A4
	str r0, [r1, #4]
	ldr r0, .L081271A8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	ldr r3, .L081271AC
	ldr r4, .L081271B0
	cmp r0, #0
	bge .L08127154
.L0812714C:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812714C
.L08127154:
	ldr r1, .L0812719C
	str r3, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L081271B4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127176
.L0812716E:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812716E
.L08127176:
	ldr r1, .L0812719C
	str r4, [r1]
	ldr r0, .L081271B8
	str r0, [r1, #4]
	ldr r0, .L081271BC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127196
.L0812718E:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812718E
.L08127196:
	pop {r4}
	pop {r0}
	bx r0
.L0812719C: .4byte 0x040000D4 @ REG_DMA3SAD
.L081271A0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L081271A4: .4byte 0x06001000 @ VRAM+0x1000
.L081271A8: .4byte 0x84000200
.L081271AC: .4byte gUnknown_08770C54
.L081271B0: .4byte 0x030000B4 @ IWRAM+0xB4
.L081271B4: .4byte 0x840000A0
.L081271B8: .4byte 0x06006000 @ VRAM+0x6000
.L081271BC: .4byte 0x84000800

	thumb_func_start sub_081271C0
sub_081271C0: @ 0x081271C0
	push {lr}
	sub sp, #4
	ldr r1, .L08127238
	ldr r0, .L0812723C
	str r0, [r1]
	ldr r0, .L08127240
	str r0, [r1, #4]
	ldr r0, .L08127244
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	ldr r3, .L08127248
	cmp r0, #0
	bge .L081271E8
.L081271E0:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L081271E0
.L081271E8:
	movs r0, #0
	str r0, [sp]
	ldr r1, .L08127238
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L0812724C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127210
.L08127208:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127208
.L08127210:
	ldr r1, .L08127238
	str r3, [r1]
	ldr r0, .L08127250
	str r0, [r1, #4]
	ldr r0, .L08127254
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127230
.L08127228:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127228
.L08127230:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08127238: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812723C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L08127240: .4byte 0x06001000 @ VRAM+0x1000
.L08127244: .4byte 0x84000200
.L08127248: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812724C: .4byte 0x850000A0
.L08127250: .4byte 0x06006000 @ VRAM+0x6000
.L08127254: .4byte 0x84000800
