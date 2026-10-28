	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08126F84
sub_08126F84: @ 0x08126F84
	push {r4, lr}
	ldr r1, .L08126FD4
	ldr r2, .L08126FD8
	str r2, [r1]
	ldr r0, .L08126FDC
	str r0, [r1, #4]
	ldr r0, .L08126FE0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r3, #0x80
	lsls r3, r3, #0x18
	movs r4, #0x80
	lsls r4, r4, #4
	adds r2, r2, r4
	cmp r0, #0
	bge .L08126FAE
.L08126FA6:
	ldr r0, [r1, #8]
	ands r0, r3
	cmp r0, #0
	bne .L08126FA6
.L08126FAE:
	ldr r1, .L08126FD4
	str r2, [r1]
	ldr r0, .L08126FE4
	str r0, [r1, #4]
	ldr r0, .L08126FE8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08126FCE
.L08126FC6:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08126FC6
.L08126FCE:
	pop {r4}
	pop {r0}
	bx r0
.L08126FD4: .4byte 0x040000D4 @ REG_DMA3SAD
.L08126FD8: .4byte 0x030012B4 @ IWRAM+0x12B4
.L08126FDC: .4byte 0x0600D800 @ VRAM+0xD800
.L08126FE0: .4byte 0x84000200
.L08126FE4: .4byte 0x060010C0 @ VRAM+0x10C0
.L08126FE8: .4byte 0x84000080

	thumb_func_start sub_08126FEC
sub_08126FEC: @ 0x08126FEC
	push {r4, lr}
	ldr r1, .L0812703C
	ldr r2, .L08127040
	str r2, [r1]
	ldr r0, .L08127044
	str r0, [r1, #4]
	ldr r0, .L08127048
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r3, #0x80
	lsls r3, r3, #0x18
	movs r4, #0x80
	lsls r4, r4, #4
	adds r2, r2, r4
	cmp r0, #0
	bge .L08127016
.L0812700E:
	ldr r0, [r1, #8]
	ands r0, r3
	cmp r0, #0
	bne .L0812700E
.L08127016:
	ldr r1, .L0812703C
	str r2, [r1]
	ldr r0, .L0812704C
	str r0, [r1, #4]
	ldr r0, .L08127050
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127036
.L0812702E:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812702E
.L08127036:
	pop {r4}
	pop {r0}
	bx r0
.L0812703C: .4byte 0x040000D4 @ REG_DMA3SAD
.L08127040: .4byte 0x030012B4 @ IWRAM+0x12B4
.L08127044: .4byte 0x0600D800 @ VRAM+0xD800
.L08127048: .4byte 0x84000200
.L0812704C: .4byte 0x060012C0 @ VRAM+0x12C0
.L08127050: .4byte 0x84000020
