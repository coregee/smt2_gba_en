	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DE9A8
sub_080DE9A8: @ 0x080DE9A8
.L080DE9A8:
	push {r4, lr}
	ldr r0, .L080DE9C0
	movs r1, #0x36
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L080DEA78
	lsls r0, r0, #2
	ldr r1, .L080DE9C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DE9C0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE9C4: .4byte gUnknown_080DE9C8
	.global gUnknown_080DE9C8
gUnknown_080DE9C8:
.L080DE9C8: @ jump table
	.4byte .L080DE9DC
	.4byte .L080DEA0C
	.4byte .L080DEA1C
	.4byte .L080DEA2C
	.4byte .L080DEA4C
.L080DE9DC:
	ldr r0, .L080DE9F8
	ldr r4, .L080DE9FC
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DEA00
	str r4, [r1]
	ldr r0, .L080DEA04
	str r0, [r1, #4]
	ldr r0, .L080DEA08
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080DEA34
	.byte 0x00, 0x00
.L080DE9F8: .4byte gUnknown_0858689C
.L080DE9FC: .4byte 0x02001000 @ EWRAM+0x1000
.L080DEA00: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DEA04: .4byte 0x06004000 @ VRAM+0x4000
.L080DEA08: .4byte 0x84000400
.L080DEA0C:
	ldr r0, .L080DEA14
	ldr r1, .L080DEA18
	b .L080DEA30
	.byte 0x00, 0x00
.L080DEA14: .4byte gUnknown_08588050
.L080DEA18: .4byte 0x02001000 @ EWRAM+0x1000
.L080DEA1C:
	ldr r0, .L080DEA24
	ldr r1, .L080DEA28
	b .L080DEA30
	.byte 0x00, 0x00
.L080DEA24: .4byte gUnknown_085887D4
.L080DEA28: .4byte 0x02002000 @ EWRAM+0x2000
.L080DEA2C:
	ldr r0, .L080DEA40
	ldr r1, .L080DEA44
.L080DEA30:
	bl LZ77UnCompWram
.L080DEA34:
	ldr r1, .L080DEA48
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	movs r0, #0
	b .L080DEA7A
.L080DEA40: .4byte gUnknown_08588FA4
.L080DEA44: .4byte 0x02003000 @ EWRAM+0x3000
.L080DEA48: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEA4C:
	ldr r0, .L080DEA80
	ldr r4, .L080DEA84
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DEA88
	ldr r0, .L080DEA8C
	adds r4, r4, r0
	str r4, [r1]
	ldr r0, .L080DEA90
	str r0, [r1, #4]
	ldr r0, .L080DEA94
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, .L080DEA98
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
	bl PalFade_FadeInFromBlack
	str r0, [r4]
.L080DEA78:
	movs r0, #1
.L080DEA7A:
	pop {r4}
	pop {r1}
	bx r1
.L080DEA80: .4byte gUnknown_0858979C
.L080DEA84: .4byte 0x02004000 @ EWRAM+0x4000
.L080DEA88: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DEA8C: .4byte 0xFFFFD000
.L080DEA90: .4byte 0x06008000 @ VRAM+0x8000
.L080DEA94: .4byte 0x84000E00
.L080DEA98: .4byte 0x020399E0 @ EWRAM+0x399E0
