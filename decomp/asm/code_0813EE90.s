	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0813EE90
sub_0813EE90: @ 0x0813EE90
.L0813EE90:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r4, .L0813EEC4
	movs r0, #0
	str r0, [sp]
	ldr r2, .L0813EEC8
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r5, [r4]
	strh r6, [r4, #2]
	ldr r0, .L0813EECC
	bl SetMainCallback
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813EEC4: .4byte 0x0203B554 @ EWRAM+0x3B554
.L0813EEC8: .4byte 0x050000C0 @ PLTT+0xC0
.L0813EECC: .4byte sub_0813EED0

	thumb_func_start sub_0813EED0
sub_0813EED0: @ 0x0813EED0
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0813EF24
	bl sub_080C1450
	movs r2, #0
	str r2, [sp]
	ldr r0, .L0813EF28
	mov r1, sp
	str r1, [r0]
	ldr r1, .L0813EF2C
	str r1, [r0, #4]
	ldr r1, .L0813EF30
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, .L0813EF34
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L0813EF38
	ldrh r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, .L0813EF3C
	bl SetMainCallback
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0813EF24: .4byte 0x0203B554 @ EWRAM+0x3B554
.L0813EF28: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813EF2C: .4byte 0x02000000 @ EWRAM
.L0813EF30: .4byte 0x85000400
.L0813EF34: .4byte 0x85001000
.L0813EF38: .4byte gUnknown_0879241C
.L0813EF3C: .4byte sub_0813EF40

	thumb_func_start sub_0813EF40
sub_0813EF40: @ 0x0813EF40
	push {r4, lr}
	ldr r4, .L0813EF5C
	bl Task_RunAll
	ldr r1, .L0813EF60
	ldrh r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
.L0813EF5C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L0813EF60: .4byte gUnknown_0879243C

	thumb_func_start sub_0813EF64
sub_0813EF64: @ 0x0813EF64
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r5, .L0813EF88
	adds r1, r5, #0
	bl HuffUnComp
	lsls r4, r4, #0xc
	ldr r0, .L0813EF8C
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813EF88: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L0813EF8C: .4byte 0x02001000 @ EWRAM+0x1000

	thumb_func_start sub_0813EF90
sub_0813EF90: @ 0x0813EF90
	ldr r1, .L0813EFA4
	ldr r0, .L0813EFA8
	str r0, [r1]
	ldr r0, .L0813EFAC
	str r0, [r1, #4]
	ldr r0, .L0813EFB0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0813EFA4: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813EFA8: .4byte 0x02001000 @ EWRAM+0x1000
.L0813EFAC: .4byte 0x06008000 @ VRAM+0x8000
.L0813EFB0: .4byte 0x84002000

	thumb_func_start sub_0813EFB4
sub_0813EFB4: @ 0x0813EFB4
	push {lr}
	ldr r0, .L0813EFC4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813EFC4: .4byte sub_0813EF90

	thumb_func_start sub_0813EFC8
sub_0813EFC8: @ 0x0813EFC8
	ldr r1, .L0813EFDC
	ldr r0, .L0813EFE0
	str r0, [r1]
	ldr r0, .L0813EFE4
	str r0, [r1, #4]
	ldr r0, .L0813EFE8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0813EFDC: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813EFE0: .4byte 0x02001000 @ EWRAM+0x1000
.L0813EFE4: .4byte 0x06010000 @ VRAM+0x10000
.L0813EFE8: .4byte 0x84002000

	thumb_func_start sub_0813EFEC
sub_0813EFEC: @ 0x0813EFEC
	push {lr}
	ldr r0, .L0813EFFC
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813EFFC: .4byte sub_0813EFC8

	thumb_func_start sub_0813F000
sub_0813F000: @ 0x0813F000
	push {r4, lr}
	sub sp, #4
	adds r0, r1, #0
	ldr r4, .L0813F028
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0813F02C
	movs r3, #0x80
	lsls r3, r3, #2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0813F028: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L0813F02C: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start sub_0813F030
sub_0813F030: @ 0x0813F030
	push {r4, lr}
	sub sp, #4
	adds r0, r1, #0
	ldr r4, .L0813F058
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0813F05C
	movs r3, #0x80
	lsls r3, r3, #2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0813F058: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L0813F05C: .4byte 0x03002BB0 @ IWRAM+0x2BB0

	thumb_func_start sub_0813F060
sub_0813F060: @ 0x0813F060
	ldr r1, .L0813F074
	ldr r0, .L0813F078
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L0813F07C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L0813F074: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813F078: .4byte 0x02000000 @ EWRAM
.L0813F07C: .4byte 0x84000140

	thumb_func_start sub_0813F080
sub_0813F080: @ 0x0813F080
	ldr r1, .L0813F094
	ldr r0, .L0813F098
	str r0, [r1]
	ldr r0, .L0813F09C
	str r0, [r1, #4]
	ldr r0, .L0813F0A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0813F094: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813F098: .4byte 0x02000000 @ EWRAM
.L0813F09C: .4byte 0x06001000 @ VRAM+0x1000
.L0813F0A0: .4byte 0x84000140

	thumb_func_start sub_0813F0A4
sub_0813F0A4: @ 0x0813F0A4
	ldr r1, .L0813F0B8
	ldr r0, .L0813F0BC
	str r0, [r1]
	ldr r0, .L0813F0C0
	str r0, [r1, #4]
	ldr r0, .L0813F0C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0813F0B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813F0BC: .4byte 0x02000000 @ EWRAM
.L0813F0C0: .4byte 0x06002000 @ VRAM+0x2000
.L0813F0C4: .4byte 0x84000140

	thumb_func_start sub_0813F0C8
sub_0813F0C8: @ 0x0813F0C8
	ldr r1, .L0813F0DC
	ldr r0, .L0813F0E0
	str r0, [r1]
	ldr r0, .L0813F0E4
	str r0, [r1, #4]
	ldr r0, .L0813F0E8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0813F0DC: .4byte 0x040000D4 @ REG_DMA3SAD
.L0813F0E0: .4byte 0x02000000 @ EWRAM
.L0813F0E4: .4byte 0x06003000 @ VRAM+0x3000
.L0813F0E8: .4byte 0x84000140

	thumb_func_start sub_0813F0EC
sub_0813F0EC: @ 0x0813F0EC
.L0813F0EC:
	push {r4, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r1, .L0813F10C
	bl LZ77UnCompWram
	cmp r4, #1
	beq .L0813F118
	cmp r4, #1
	blo .L0813F110
	cmp r4, #2
	beq .L0813F120
	cmp r4, #3
	beq .L0813F130
	b .L0813F138
	.byte 0x00, 0x00
.L0813F10C: .4byte 0x02000000 @ EWRAM
.L0813F110:
	ldr r0, .L0813F114
	b .L0813F122
.L0813F114: .4byte sub_0813F060
.L0813F118:
	ldr r0, .L0813F11C
	b .L0813F122
.L0813F11C: .4byte sub_0813F080
.L0813F120:
	ldr r0, .L0813F12C
.L0813F122:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L0813F138
	.byte 0x00, 0x00
.L0813F12C: .4byte sub_0813F0A4
.L0813F130:
	ldr r0, .L0813F140
	movs r1, #1
	bl VBlankTask_AddCounted
.L0813F138:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813F140: .4byte sub_0813F0C8

	thumb_func_start sub_0813F144
sub_0813F144: @ 0x0813F144
	push {lr}
	movs r0, #1
	bl PalFade_FadeInFromBlack
	pop {r0}
	bx r0

	thumb_func_start sub_0813F150
sub_0813F150: @ 0x0813F150
	push {lr}
	movs r0, #1
	bl PalFade_FadeToBlack
	pop {r0}
	bx r0

	thumb_func_start sub_0813F15C
sub_0813F15C: @ 0x0813F15C
	push {lr}
	bl sub_080AB1A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813F168
sub_0813F168: @ 0x0813F168
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, .L0813F210
	movs r5, #0
	str r5, [sp]
	ldr r2, .L0813F214
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	ldr r1, .L0813F218
	ldr r2, .L0813F21C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L0813F220
	strh r5, [r0]
	ldr r0, .L0813F224
	strh r5, [r0]
	movs r4, #1
	strh r4, [r6]
	ldr r0, .L0813F228
	strh r0, [r6, #0x28]
	bl sub_080C31F0
	str r0, [r6, #0x3c]
	adds r0, r6, #0
	adds r0, #0x5e
	strh r5, [r0]
	subs r0, #0xc
	strh r5, [r0]
	subs r0, #0xc
	strh r5, [r0]
	adds r0, #0x1a
	strh r4, [r0]
	subs r0, #0xc
	strh r4, [r0]
	subs r0, #0xc
	strh r4, [r0]
	adds r1, r6, #0
	adds r1, #0x62
	movs r0, #2
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0x66
	movs r0, #4
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x68
	movs r1, #5
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x44
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x69
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x8e
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0813F210: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0813F214: .4byte 0x05000200 @ PLTT+0x200
.L0813F218: .4byte 0x04000008 @ REG_BG0CNT
.L0813F21C: .4byte 0x00004008
.L0813F220: .4byte 0x03000002 @ IWRAM+0x2
.L0813F224: .4byte 0x03000040 @ IWRAM+0x40
.L0813F228: .4byte 0x00000111

	thumb_func_start sub_0813F22C
sub_0813F22C: @ 0x0813F22C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r7, .L0813F294
	ldr r6, .L0813F298
	ldrh r0, [r6]
	cmp r0, #1
	bne .L0813F24A
	ldr r0, .L0813F29C
	ldr r1, .L0813F2A0
	bl Task_Create
	movs r0, #0
	strh r0, [r6]
.L0813F24A:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrb r3, [r0]
	mov r8, r0
	cmp r3, #1
	bne .L0813F32C
	ldr r0, .L0813F2A4
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0813F300
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne .L0813F300
	ldr r1, [r6, #0x3c]
	adds r5, r1, #0
	cmp r1, #0
	beq .L0813F300
	ldrh r0, [r6, #0x26]
	adds r4, r0, #0
	adds r2, r0, #0
	cmp r4, #1
	beq .L0813F282
	ldrh r0, [r6, #0x1e]
	cmp r0, #1
	bne .L0813F2FA
.L0813F282:
	cmp r4, #0
	bne .L0813F2C2
	ldrh r0, [r6, #0x20]
	cmp r0, #1
	bne .L0813F2A8
	movs r0, #6
	strh r0, [r6, #4]
	b .L0813F300
	.byte 0x00, 0x00
.L0813F294: .4byte 0x0203B554 @ EWRAM+0x3B554
.L0813F298: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0813F29C: .4byte gUnknown_08794E24
.L0813F2A0: .4byte 0x0000FFFF
.L0813F2A4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813F2A8:
	cmp r0, #2
	bne .L0813F2C2
	strh r4, [r6, #4]
	strh r4, [r6, #0x20]
	strh r4, [r6, #0x1e]
	bl sub_08141F04
	ldr r0, [r6, #0x3c]
	ldr r1, [r6, #0x30]
	adds r0, r0, r1
	str r0, [r6, #0x3c]
	str r4, [r6, #0x30]
	b .L0813F300
.L0813F2C2:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L0813F2E0
	ldrh r0, [r6, #0x20]
	cmp r0, #2
	bne .L0813F2E0
	movs r1, #0
	movs r0, #6
	strh r0, [r6, #4]
	ldr r0, [r6, #0x30]
	adds r0, r5, r0
	str r0, [r6, #0x3c]
	str r1, [r6, #0x30]
	b .L0813F300
.L0813F2E0:
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r1, #0
	movs r0, #2
	strh r0, [r6, #4]
	strh r1, [r6, #0x1e]
	strh r1, [r6, #0x20]
	ldr r0, [r6, #0x30]
	subs r0, #5
	str r0, [r6, #0x30]
	b .L0813F300
.L0813F2FA:
	strh r3, [r6, #4]
	subs r0, r1, #1
	str r0, [r6, #0x3c]
.L0813F300:
	ldr r0, .L0813F3E4
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813F32C
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne .L0813F32C
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813F32C
	ldrh r0, [r6, #0x20]
	cmp r0, #0
	bne .L0813F32C
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #9
	strh r0, [r6, #4]
.L0813F32C:
	ldrh r4, [r6, #4]
	cmp r4, #1
	bne .L0813F3F8
	ldrh r0, [r6, #0x16]
	cmp r0, #3
	bhi .L0813F350
	ldr r0, .L0813F3E8
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F350:
	ldrh r0, [r6, #0x16]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0813F374
	ldr r0, .L0813F3EC
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F374:
	ldrh r0, [r6, #0x16]
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0813F398
	ldr r0, .L0813F3F0
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F398:
	ldrh r0, [r6, #0x16]
	cmp r0, #9
	bls .L0813F3C4
	ldr r0, .L0813F3F4
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #2
	strh r0, [r6, #4]
	strh r4, [r6, #0x16]
.L0813F3C4:
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	bl .L0813FCA2
.L0813F3E4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813F3E8: .4byte gUnknown_0814EE00
.L0813F3EC: .4byte gUnknown_0814EDE8
.L0813F3F0: .4byte gUnknown_0814EDD0
.L0813F3F4: .4byte gUnknown_0814EDB8
.L0813F3F8:
	cmp r4, #6
	beq .L0813F3FE
	b .L0813F5BC
.L0813F3FE:
	ldrh r0, [r6, #0x24]
	ldrh r1, [r6, #0x22]
	cmp r0, #0
	bne .L0813F410
	cmp r1, #0xef
	bhi .L0813F410
	movs r0, #1
	strh r0, [r6, #0x24]
	b .L0813F4AA
.L0813F410:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L0813F480
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xef
	bls .L0813F480
	movs r0, #2
	strh r0, [r6, #0x24]
	movs r0, #0xf0
	strh r0, [r6, #0x22]
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813F470
	ldr r1, .L0813F46C
	movs r0, #0
	movs r2, #0
	bl sub_0813F0EC
	movs r7, #0
	movs r0, #0x84
	adds r0, r0, r6
	mov r8, r0
.L0813F440:
	bl sub_080C2244
	lsls r4, r7, #3
	mov r1, r8
	adds r5, r1, r4
	movs r1, #0xff
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #3
	bl __udivsi3
	str r0, [r5]
	adds r4, r6, r4
	adds r4, #0x88
	movs r0, #0
	strh r0, [r4]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #5
	bls .L0813F440
	b .L0813F4AA
.L0813F46C: .4byte gUnknown_087A4FA8
.L0813F470:
	ldr r1, .L0813F47C
	movs r0, #0
	movs r2, #0
	bl sub_0813F0EC
	b .L0813F4AA
.L0813F47C: .4byte gUnknown_087A51AC
.L0813F480:
	ldrh r0, [r6, #0x24]
	cmp r0, #2
	bne .L0813F4AA
	ldrh r1, [r6, #0x22]
	cmp r1, #0
	bne .L0813F4AA
	strh r1, [r6, #0x22]
	strh r1, [r6, #0x24]
	strh r1, [r6, #0x20]
	strh r1, [r6, #0x1e]
	strh r1, [r6, #4]
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813F4A2
	movs r0, #1
	strh r0, [r6, #0x26]
	b .L0813F4AA
.L0813F4A2:
	strh r1, [r6, #0x26]
	adds r0, r6, #0
	adds r0, #0x44
	strh r1, [r0]
.L0813F4AA:
	ldr r1, .L0813F514
	ldrh r0, [r6, #0x22]
	rsbs r0, r0, #0
	strh r0, [r1]
	ldr r0, .L0813F518
	bl sub_080C51D4
	ldr r0, .L0813F51C
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r0, [r6, #0x1e]
	cmp r0, #1
	bne .L0813F4F6
	bl sub_08141B08
.L0813F4F6:
	ldrh r0, [r6, #0x20]
	cmp r0, #1
	bne .L0813F524
	ldr r0, .L0813F520
	str r4, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0813F53E
.L0813F514: .4byte 0x03000000 @ IWRAM
.L0813F518: .4byte 0x0000015F
.L0813F51C: .4byte gUnknown_0814EDB8
.L0813F520: .4byte gUnknown_0814EC40
.L0813F524:
	cmp r0, #2
	bne .L0813F53E
	ldr r0, .L0813F594
	str r4, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F53E:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x14
	bls .L0813F570
	ldr r0, .L0813F598
	movs r5, #0
	str r5, [sp]
	movs r4, #0x19
	str r4, [sp, #4]
	movs r1, #0x2c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0813F59C
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x3b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F570:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x28
	bls .L0813F57A
	movs r0, #0
	strh r0, [r6, #0x12]
.L0813F57A:
	ldrh r0, [r6, #0x24]
	cmp r0, #1
	bne .L0813F5A0
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813F58E
	bl sub_08140914
	bl sub_08141D90
.L0813F58E:
	ldrh r0, [r6, #0x22]
	adds r0, #2
	b .L0813F5B6
.L0813F594: .4byte gUnknown_0814EC58
.L0813F598: .4byte gUnknown_0814EC90
.L0813F59C: .4byte gUnknown_0814EC80
.L0813F5A0:
	cmp r0, #2
	beq .L0813F5A8
	bl .L081400E0
.L0813F5A8:
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813F5B2
	bl sub_08140914
.L0813F5B2:
	ldrh r0, [r6, #0x22]
	subs r0, #2
.L0813F5B6:
	strh r0, [r6, #0x22]
	bl .L081400E0
.L0813F5BC:
	cmp r4, #2
	beq .L0813F5C2
	b .L0813F9A4
.L0813F5C2:
	bl sub_08140104
	ldr r0, .L0813F654
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813F608
	bl sub_08140914
	bl sub_08141D90
.L0813F608:
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne .L0813F658
	adds r0, r6, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F622
	adds r1, r6, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F622:
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F636
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F636:
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F64A
	adds r1, r6, #0
	adds r1, #0x80
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F64A:
	ldrh r0, [r6, #0x10]
	adds r0, #4
	strh r0, [r6, #0x10]
	b .L0813F76C
	.byte 0x00, 0x00
.L0813F654: .4byte gUnknown_0814EDB8
.L0813F658:
	cmp r0, #1
	bne .L0813F700
	adds r0, r6, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F690
	ldrh r0, [r6, #0xa]
	adds r0, #9
	strh r0, [r6, #0xa]
	bl sub_080C2244
	movs r1, #0xff
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r6, #0xa]
	adds r1, r1, r0
	strh r1, [r6, #0xa]
.L0813F690:
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F6C4
	ldrh r0, [r6, #0xc]
	adds r0, #9
	strh r0, [r6, #0xc]
	bl sub_080C2244
	movs r1, #0xff
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r6, #0xc]
	adds r1, r1, r0
	strh r1, [r6, #0xc]
.L0813F6C4:
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F6F8
	ldrh r0, [r6, #0xe]
	adds r0, #9
	strh r0, [r6, #0xe]
	bl sub_080C2244
	movs r1, #0xff
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r6, #0xe]
	adds r1, r1, r0
	strh r1, [r6, #0xe]
.L0813F6F8:
	ldrh r0, [r6, #0x10]
	adds r0, #0x12
	strh r0, [r6, #0x10]
	b .L0813F76C
.L0813F700:
	cmp r0, #2
	bne .L0813F72A
	adds r0, r6, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F718
	adds r1, r6, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F718:
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F742
	ldrh r0, [r6, #0xc]
	adds r0, #9
	strh r0, [r6, #0xc]
	b .L0813F742
.L0813F72A:
	cmp r0, #3
	bne .L0813F754
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F742
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F742:
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F76C
	ldrh r0, [r6, #0xe]
	adds r0, #9
	strh r0, [r6, #0xe]
	b .L0813F76C
.L0813F754:
	cmp r0, #4
	bne .L0813F76C
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813F76C
	adds r1, r6, #0
	adds r1, #0x80
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
.L0813F76C:
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne .L0813F79E
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r1, [r0]
	adds r4, r0, #0
	adds r3, r6, #0
	adds r3, #0x7e
	adds r2, r6, #0
	adds r2, #0x80
	cmp r1, #0x28
	beq .L0813F792
	ldrh r0, [r3]
	cmp r0, #0x28
	beq .L0813F792
	ldrh r0, [r2]
	cmp r0, #0x28
	bne .L0813F79E
.L0813F792:
	movs r1, #0
	movs r0, #1
	strh r0, [r6, #8]
	strh r1, [r2]
	strh r1, [r3]
	strh r1, [r4]
.L0813F79E:
	ldrh r0, [r6, #8]
	cmp r0, #1
	bne .L0813F7B8
	ldrh r0, [r6, #6]
	cmp r0, #5
	bne .L0813F7B8
	ldrh r0, [r6, #0x10]
	cmp r0, #0x27
	bls .L0813F7B8
	movs r1, #0
	movs r0, #2
	strh r0, [r6, #8]
	strh r1, [r6, #0x10]
.L0813F7B8:
	ldrh r0, [r6, #8]
	cmp r0, #2
	bne .L0813F7E2
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x6a
	cmp r0, #0x3c
	beq .L0813F7D2
	ldrh r0, [r1]
	cmp r0, #1
	bne .L0813F7E2
.L0813F7D2:
	ldrh r0, [r1]
	cmp r0, #0
	bne .L0813F7DE
	ldr r0, .L0813F980
	bl sub_080C51D4
.L0813F7DE:
	movs r0, #3
	strh r0, [r6, #8]
.L0813F7E2:
	ldrh r0, [r6, #8]
	cmp r0, #3
	bne .L0813F80C
	adds r0, r6, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x6c
	cmp r0, #0x3c
	beq .L0813F7FC
	ldrh r0, [r1]
	cmp r0, #1
	bne .L0813F80C
.L0813F7FC:
	ldrh r0, [r1]
	cmp r0, #0
	bne .L0813F808
	ldr r0, .L0813F980
	bl sub_080C51D4
.L0813F808:
	movs r0, #4
	strh r0, [r6, #8]
.L0813F80C:
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813F868
	ldr r0, .L0813F984
	movs r5, #0
	str r5, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0x12]
	cmp r0, #0x14
	bls .L0813F85A
	ldr r0, .L0813F988
	str r5, [sp]
	movs r4, #0x19
	str r4, [sp, #4]
	movs r1, #0x2c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0813F98C
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x3b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813F85A:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x28
	bls .L0813F862
	strh r5, [r6, #0x12]
.L0813F862:
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
.L0813F868:
	ldrh r0, [r6, #0xa]
	movs r1, #0xef
	lsls r1, r1, #1
	cmp r0, r1
	bls .L0813F876
	movs r0, #0
	strh r0, [r6, #0xa]
.L0813F876:
	ldrh r0, [r6, #0xc]
	cmp r0, r1
	bls .L0813F880
	movs r0, #0
	strh r0, [r6, #0xc]
.L0813F880:
	ldrh r0, [r6, #0xe]
	cmp r0, r1
	bls .L0813F88A
	movs r0, #0
	strh r0, [r6, #0xe]
.L0813F88A:
	ldrh r1, [r6, #0x10]
	movs r0, #0x8a
	lsls r0, r0, #1
	cmp r1, r0
	bls .L0813F89E
	movs r0, #0
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #6]
	adds r0, #1
	strh r0, [r6, #6]
.L0813F89E:
	ldrh r0, [r6, #6]
	cmp r0, #5
	bne .L0813F8AE
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0x3b
	bhi .L0813F8C6
.L0813F8AE:
	ldrh r0, [r6, #8]
	cmp r0, #4
	beq .L0813F8B8
	bl .L081400F6
.L0813F8B8:
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0813F8C6
	bl .L081400F6
.L0813F8C6:
	adds r4, r6, #0
	adds r4, #0x6e
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0813F8D6
	ldr r0, .L0813F980
	bl sub_080C51D4
.L0813F8D6:
	movs r2, #0
	movs r0, #4
	strh r0, [r6, #4]
	strh r2, [r6, #0x20]
	strh r2, [r6, #6]
	strh r2, [r6, #0x10]
	adds r5, r6, #0
	adds r5, #0x6a
	ldrh r0, [r5]
	cmp r0, #0
	bne .L0813F90C
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x4a
	strh r0, [r1]
.L0813F90C:
	adds r3, r6, #0
	adds r3, #0x6c
	ldrh r0, [r3]
	cmp r0, #0
	bne .L0813F936
	adds r0, r6, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
.L0813F936:
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0813F95C
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x5e
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x66
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x62
	strh r0, [r1]
.L0813F95C:
	adds r0, r6, #0
	adds r0, #0x80
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	ldrh r1, [r6, #0x26]
	cmp r1, #0
	beq .L0813F972
	b .L081400F6
.L0813F972:
	ldrh r0, [r6, #0x18]
	cmp r0, #0
	bne .L0813F990
	movs r0, #1
	strh r0, [r6, #0x18]
	b .L081400F6
	.byte 0x00, 0x00
.L0813F980: .4byte 0x0000015B
.L0813F984: .4byte gUnknown_0814EC40
.L0813F988: .4byte gUnknown_0814EC90
.L0813F98C: .4byte gUnknown_0814EC80
.L0813F990:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0
	bne .L0813F998
	b .L081400F6
.L0813F998:
	strh r1, [r6, #0x18]
	strh r1, [r6, #0x1a]
	strh r1, [r4]
	strh r1, [r3]
	strh r1, [r5]
	b .L081400F6
.L0813F9A4:
	cmp r4, #4
	beq .L0813F9AA
	b .L0813FAF4
.L0813F9AA:
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813F9D4
	bl sub_08140AD8
	ldr r0, .L0813F9D0
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0813FA5A
	.byte 0x00, 0x00
.L0813F9D0: .4byte gUnknown_0814EC40
.L0813F9D4:
	ldr r4, .L0813FA24
	adds r0, r6, #0
	adds r0, #0x46
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	cmp r0, #8
	bne .L0813F9FC
	movs r0, #3
	strh r0, [r6, #0x2e]
	bl sub_08140AD8
.L0813F9FC:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	cmp r0, #8
	bne .L0813FA28
	movs r0, #2
	strh r0, [r6, #0x2e]
	bl sub_08140AD8
	b .L0813FA32
.L0813FA24: .4byte gUnknown_0879245C
.L0813FA28:
	ldrh r0, [r6, #0x1e]
	cmp r0, #0
	bne .L0813FA32
	bl sub_08140A24
.L0813FA32:
	ldr r3, .L0813FAA8
	adds r0, r6, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r0, #8
	bne .L0813FA5A
	movs r0, #1
	strh r0, [r6, #0x2e]
	bl sub_08140AD8
.L0813FA5A:
	ldr r0, .L0813FAAC
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813FA9C
	bl sub_08140914
	bl sub_08141D90
.L0813FA9C:
	ldrh r0, [r6, #0x2a]
	cmp r0, #1
	bne .L0813FAB0
	movs r0, #7
	strh r0, [r6, #4]
	b .L081400F6
.L0813FAA8: .4byte gUnknown_0879245C
.L0813FAAC: .4byte gUnknown_0814EDB8
.L0813FAB0:
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813FAC6
	strh r4, [r6, #0x2c]
	strh r4, [r6, #0x2e]
	ldrh r0, [r6, #0x1e]
	cmp r0, #0
	bne .L0813FAF0
	movs r0, #3
	strh r0, [r6, #4]
	b .L081400F6
.L0813FAC6:
	bl sub_08141F04
	strh r4, [r6, #0x2c]
	strh r4, [r6, #0x2e]
	ldr r1, [r6, #0x30]
	cmp r1, #0
	bne .L0813FADA
	movs r0, #6
	strh r0, [r6, #4]
	b .L081400F6
.L0813FADA:
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #6
	bne .L0813FAF0
	strh r0, [r6, #4]
	ldr r0, [r6, #0x3c]
	adds r0, r0, r1
	str r0, [r6, #0x3c]
	str r4, [r6, #0x30]
	b .L081400F6
.L0813FAF0:
	strh r4, [r6, #4]
	b .L081400F6
.L0813FAF4:
	cmp r4, #7
	beq .L0813FAFA
	b .L0813FC0C
.L0813FAFA:
	ldr r0, .L0813FB94
	movs r4, #0
	str r4, [sp]
	movs r5, #8
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813FB52
	ldr r0, .L0813FB98
	str r4, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08140914
	bl sub_08141D90
.L0813FB52:
	ldrh r0, [r6, #0x14]
	cmp r0, #2
	bhi .L0813FBF0
	ldrh r0, [r6, #0x12]
	cmp r0, #5
	bls .L0813FBE6
	bl sub_08141B08
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813FB7E
	ldr r0, .L0813FB9C
	str r4, [sp]
	movs r1, #0x62
	str r1, [sp, #4]
	movs r1, #0xd
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FB7E:
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #8
	bhi .L0813FBE6
	lsls r0, r0, #2
	ldr r1, .L0813FBA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0813FB94: .4byte gUnknown_0814EDB8
.L0813FB98: .4byte gUnknown_0814EC40
.L0813FB9C: .4byte gUnknown_0814ECD8
.L0813FBA0: .4byte gUnknown_0813FBA4
	.global gUnknown_0813FBA4
gUnknown_0813FBA4:
.L0813FBA4: @ jump table
	.4byte .L0813FBC8
	.4byte .L0813FBC8
	.4byte .L0813FBC8
	.4byte .L0813FBC8
	.4byte .L0813FBC8
	.4byte .L0813FBC8
	.4byte .L0813FBD4
	.4byte .L0813FBD4
	.4byte .L0813FBDE
.L0813FBC8:
	ldr r0, .L0813FBD0
	bl sub_080C51D4
	b .L0813FBE6
.L0813FBD0: .4byte 0x0000015D
.L0813FBD4:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L0813FBE6
.L0813FBDE:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
.L0813FBE6:
	ldrh r0, [r6, #0x12]
	cmp r0, #0xa
	bhi .L0813FBEE
	b .L081400E0
.L0813FBEE:
	b .L081400D6
.L0813FBF0:
	strh r4, [r6, #0x14]
	strh r4, [r6, #0x2a]
	strh r4, [r6, #0x12]
	bl sub_08141B08
	bl sub_08141F04
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813FC08
	bl sub_08141C08
.L0813FC08:
	strh r5, [r6, #4]
	b .L081400F6
.L0813FC0C:
	cmp r4, #3
	bne .L0813FCB8
	ldrh r0, [r6, #0x16]
	cmp r0, #3
	bhi .L0813FC2E
	ldr r0, .L0813FCAC
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FC2E:
	ldrh r0, [r6, #0x16]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0813FC52
	ldr r0, .L0813FCB0
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FC52:
	ldrh r0, [r6, #0x16]
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0813FC76
	ldr r0, .L0813FCB4
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FC76:
	ldrh r0, [r6, #0x16]
	cmp r0, #9
	bls .L0813FC82
	movs r0, #0
	strh r0, [r6, #4]
	strh r0, [r6, #0x16]
.L0813FC82:
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	movs r0, #0
	strh r0, [r6, #8]
.L0813FCA2:
	ldrh r0, [r6, #0x16]
	adds r0, #1
	strh r0, [r6, #0x16]
	b .L081400F6
	.byte 0x00, 0x00
.L0813FCAC: .4byte gUnknown_0814EDD0
.L0813FCB0: .4byte gUnknown_0814EDE8
.L0813FCB4: .4byte gUnknown_0814EE00
.L0813FCB8:
	cmp r4, #8
	bne .L0813FD24
	ldr r0, .L0813FD1C
	movs r5, #0
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_081403C0
	bl sub_08141B08
	ldrh r0, [r6, #0x26]
	cmp r0, #1
	bne .L0813FCFE
	ldr r0, .L0813FD20
	str r5, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08140914
	bl sub_08141D90
.L0813FCFE:
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	bl sub_081420E0
	b .L081400F6
.L0813FD1C: .4byte gUnknown_0814EDB8
.L0813FD20: .4byte gUnknown_0814EC40
.L0813FD24:
	cmp r4, #0
	beq .L0813FD2A
	b .L0814008C
.L0813FD2A:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x14
	bls .L0813FD98
	ldr r0, .L0813FD64
	str r4, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0x26]
	cmp r0, #0
	bne .L0813FD6C
	ldr r0, .L0813FD68
	str r4, [sp]
	movs r1, #0xc4
	str r1, [sp, #4]
	movs r1, #0x33
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0813FD82
.L0813FD64: .4byte gUnknown_0814EC10
.L0813FD68: .4byte gUnknown_0814ECE8
.L0813FD6C:
	ldr r0, .L0813FDE4
	str r4, [sp]
	movs r1, #0xc1
	str r1, [sp, #4]
	movs r1, #0x31
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FD82:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x28
	bls .L0813FD98
	movs r0, #0
	strh r0, [r6, #0x12]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0813FD98
	movs r0, #1
	strb r0, [r1]
.L0813FD98:
	ldrh r5, [r6, #0x18]
	cmp r5, #1
	beq .L0813FDA0
	b .L0813FEBA
.L0813FDA0:
	ldr r0, .L0813FDE8
	movs r1, #0
	str r1, [sp]
	movs r1, #0xb
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0813FDEC
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L0813FDF0
	adds r4, r6, #0
	adds r4, #0x6a
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0813FDF0
	ldrh r0, [r6, #0x1a]
	cmp r0, #1
	bhi .L0813FDF0
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	strh r5, [r4]
	ldrh r0, [r6, #0x1a]
	adds r0, #1
	b .L0813FE0E
.L0813FDE4: .4byte gUnknown_0814ED00
.L0813FDE8: .4byte gUnknown_0814EC70
.L0813FDEC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813FDF0:
	ldr r0, .L0813FE40
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L0813FE10
	adds r1, r6, #0
	adds r1, #0x6a
	ldrh r0, [r1]
	cmp r0, #1
	bne .L0813FE10
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r6, #0x1a]
	subs r0, #1
.L0813FE0E:
	strh r0, [r6, #0x1a]
.L0813FE10:
	ldr r0, .L0813FE40
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813FE44
	adds r4, r6, #0
	adds r4, #0x6c
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0813FE44
	ldrh r0, [r6, #0x1a]
	cmp r0, #1
	bhi .L0813FE44
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4]
	ldrh r0, [r6, #0x1a]
	adds r0, #1
	b .L0813FE62
	.byte 0x00, 0x00
.L0813FE40: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813FE44:
	ldr r0, .L0813FE94
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813FE64
	adds r1, r6, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	cmp r0, #1
	bne .L0813FE64
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r6, #0x1a]
	subs r0, #1
.L0813FE62:
	strh r0, [r6, #0x1a]
.L0813FE64:
	ldr r2, .L0813FE94
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0813FE98
	adds r4, r6, #0
	adds r4, #0x6e
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0813FE98
	ldrh r0, [r6, #0x1a]
	cmp r0, #1
	bhi .L0813FE98
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4]
	ldrh r0, [r6, #0x1a]
	adds r0, #1
	b .L0813FEB4
	.byte 0x00, 0x00
.L0813FE94: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813FE98:
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0813FEB6
	adds r1, r6, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	cmp r0, #1
	bne .L0813FEB6
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r6, #0x1a]
	subs r0, #1
.L0813FEB4:
	strh r0, [r6, #0x1a]
.L0813FEB6:
	bl sub_08140810
.L0813FEBA:
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r4, [r6, #0x26]
	cmp r4, #1
	bne .L0813FFA4
	ldr r0, .L0813FF40
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08140914
	bl sub_08141D90
	ldrh r0, [r6, #0x20]
	cmp r0, #0
	beq .L0813FF0E
	ldr r2, .L0813FF44
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813FF12
.L0813FF0E:
	strh r4, [r6, #0x20]
	ldr r2, .L0813FF44
.L0813FF12:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0813FF20
	movs r0, #2
	strh r0, [r6, #0x20]
.L0813FF20:
	ldrh r0, [r6, #0x20]
	cmp r0, #1
	bne .L0813FF4C
	ldr r0, .L0813FF48
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0813FF68
.L0813FF40: .4byte gUnknown_0814EDB8
.L0813FF44: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0813FF48: .4byte gUnknown_0814EC40
.L0813FF4C:
	cmp r0, #2
	bne .L0813FF68
	ldr r0, .L0814000C
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FF68:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x14
	bls .L0813FF9A
	ldr r0, .L08140010
	movs r5, #0
	str r5, [sp]
	movs r4, #0x19
	str r4, [sp, #4]
	movs r1, #0x2c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08140014
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x3b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0813FF9A:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x28
	bls .L0813FFA4
	movs r0, #0
	strh r0, [r6, #0x12]
.L0813FFA4:
	ldrh r4, [r6, #0x1e]
	cmp r4, #1
	beq .L0813FFAC
	b .L081400E0
.L0813FFAC:
	ldr r0, .L08140018
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08141B08
	ldrh r0, [r6, #0x20]
	cmp r0, #0
	beq .L0813FFDA
	ldr r2, .L0814001C
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813FFDE
.L0813FFDA:
	strh r4, [r6, #0x20]
	ldr r2, .L0814001C
.L0813FFDE:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0813FFEC
	movs r0, #2
	strh r0, [r6, #0x20]
.L0813FFEC:
	ldrh r0, [r6, #0x20]
	cmp r0, #1
	bne .L08140024
	ldr r0, .L08140020
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x1b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08140040
.L0814000C: .4byte gUnknown_0814EC58
.L08140010: .4byte gUnknown_0814EC90
.L08140014: .4byte gUnknown_0814EC80
.L08140018: .4byte gUnknown_0814EDB8
.L0814001C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08140020: .4byte gUnknown_0814EC40
.L08140024:
	cmp r0, #2
	bne .L08140040
	ldr r0, .L08140080
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08140040:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x14
	bls .L08140072
	ldr r0, .L08140084
	movs r5, #0
	str r5, [sp]
	movs r4, #0x19
	str r4, [sp, #4]
	movs r1, #0x2c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08140088
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x3b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08140072:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x28
	bls .L081400E0
	movs r0, #0
	strh r0, [r6, #0x12]
	b .L081400E0
	.byte 0x00, 0x00
.L08140080: .4byte gUnknown_0814EC58
.L08140084: .4byte gUnknown_0814EC90
.L08140088: .4byte gUnknown_0814EC80
.L0814008C:
	cmp r4, #9
	bne .L081400F6
	bl sub_081403C0
	ldr r0, [r6, #0x30]
	movs r1, #0xe4
	movs r2, #0x21
	movs r3, #2
	bl sub_08141FE0
	ldr r0, [r6, #0x3c]
	movs r1, #0xe4
	movs r2, #0x4a
	movs r3, #2
	bl sub_08141FE0
	ldrh r0, [r6, #0x14]
	cmp r0, #5
	bhi .L081400EC
	ldrh r0, [r6, #0x12]
	cmp r0, #3
	bls .L081400D0
	ldr r0, .L081400E8
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081400D0:
	ldrh r0, [r6, #0x12]
	cmp r0, #6
	bls .L081400E0
.L081400D6:
	movs r0, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x14]
	adds r0, #1
	strh r0, [r6, #0x14]
.L081400E0:
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
	b .L081400F6
.L081400E8: .4byte gUnknown_0814EC28
.L081400EC:
	ldr r0, [r6, #0x3c]
	bl sub_080C31FC
	bl sub_080BE4C4
.L081400F6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08140104
sub_08140104: @ 0x08140104
.L08140104:
	push {r4, r5, lr}
	ldr r4, .L081403BC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne .L08140110
	b .L0814024E
.L08140110:
	adds r0, r4, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08140178
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x46
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x4a
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x4c
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
.L08140178:
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L0814024E
	adds r0, r4, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	cmp r0, #0
	bne .L081401E6
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x54
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x58
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x5c
	strh r0, [r1]
.L081401E6:
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0814024E
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x5e
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x60
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x62
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x68
	strh r0, [r1]
.L0814024E:
	adds r5, r4, #0
	adds r5, #0x50
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L0814025C
	movs r0, #0
	strh r0, [r5]
.L0814025C:
	movs r0, #0x4e
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L08140272
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
	movs r0, #1
	strh r0, [r5]
.L08140272:
	adds r3, r4, #0
	adds r3, #0x4c
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L0814028A
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
	movs r0, #2
	strh r0, [r5]
.L0814028A:
	adds r2, r4, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L081402A6
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
	movs r0, #3
	strh r0, [r5]
.L081402A6:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L081402C6
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
	movs r0, #4
	strh r0, [r5]
.L081402C6:
	adds r5, r4, #0
	adds r5, #0x5c
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L081402D4
	movs r0, #0
	strh r0, [r5]
.L081402D4:
	movs r0, #0x5a
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L081402EA
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
	movs r0, #1
	strh r0, [r5]
.L081402EA:
	adds r3, r4, #0
	adds r3, #0x58
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L08140302
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
	movs r0, #2
	strh r0, [r5]
.L08140302:
	adds r2, r4, #0
	adds r2, #0x56
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L0814031E
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
	movs r0, #3
	strh r0, [r5]
.L0814031E:
	adds r1, r4, #0
	adds r1, #0x54
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L0814033E
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
	movs r0, #4
	strh r0, [r5]
.L0814033E:
	adds r5, r4, #0
	adds r5, #0x68
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L0814034C
	movs r0, #0
	strh r0, [r5]
.L0814034C:
	movs r0, #0x66
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L08140362
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
	movs r0, #1
	strh r0, [r5]
.L08140362:
	adds r3, r4, #0
	adds r3, #0x64
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L0814037A
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
	movs r0, #2
	strh r0, [r5]
.L0814037A:
	adds r2, r4, #0
	adds r2, #0x62
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L08140396
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
	movs r0, #3
	strh r0, [r5]
.L08140396:
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L081403B6
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
	movs r0, #4
	strh r0, [r5]
.L081403B6:
	pop {r4, r5}
	pop {r0}
	bx r0
.L081403BC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081403C0
sub_081403C0: @ 0x081403C0
.L081403C0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, .L081407B8
	mov r8, r0
	ldr r7, .L081407BC
	ldr r4, .L081407C0
	adds r0, r7, #0
	adds r0, #0x50
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r0, [r1]
	movs r6, #0
	str r6, [sp]
	movs r5, #0x44
	mov sl, r5
	str r5, [sp, #4]
	movs r1, #0x7c
	adds r1, r1, r7
	mov sb, r1
	ldr r2, .L081407C4
	ldrh r3, [r1]
	adds r1, r2, r3
	movs r5, #0xff
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	mov ip, r1
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	ldr r3, .L081407C8
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r3, r2
	ands r1, r5
	str r1, [sp, #8]
	mov r0, ip
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x46
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r4, .L081407CC
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r1, [r1]
	mov ip, r1
	str r6, [sp]
	movs r0, #0x69
	mov sb, r0
	str r0, [sp, #4]
	movs r1, #0x7e
	adds r1, r1, r7
	mov sl, r1
	ldr r2, .L081407C4
	ldrh r3, [r1]
	adds r1, r2, r3
	ands r1, r5
	str r1, [sp, #8]
	mov r0, ip
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	mov ip, r1
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldr r3, .L081407C8
	mov r2, sl
	ldrh r2, [r2]
	adds r1, r3, r2
	ands r1, r5
	str r1, [sp, #8]
	mov r0, ip
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r2, sl
	ldrh r1, [r2]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x56
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r2, sl
	ldrh r1, [r2]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x54
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r2, sl
	ldrh r1, [r2]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x52
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r2, sl
	ldrh r1, [r2]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r4, .L081407D0
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r1, [r1]
	mov ip, r1
	str r6, [sp]
	movs r0, #0x8e
	mov sl, r0
	str r0, [sp, #4]
	movs r1, #0x80
	adds r1, r1, r7
	mov sb, r1
	ldr r2, .L081407C4
	ldrh r3, [r1]
	adds r1, r2, r3
	ands r1, r5
	str r1, [sp, #8]
	mov r0, ip
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x66
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	mov ip, r1
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	ldr r3, .L081407C8
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r3, r2
	ands r1, r5
	str r1, [sp, #8]
	mov r0, ip
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x64
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x62
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x60
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x5e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	b .L081407D4
	.byte 0x00, 0x00
.L081407B8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L081407BC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081407C0: .4byte gUnknown_0879245C
.L081407C4: .4byte 0x0000FFDC
.L081407C8: .4byte 0x0000FFF0
.L081407CC: .4byte gUnknown_087931DC
.L081407D0: .4byte gUnknown_08793F5C
.L081407D4:
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08140810
sub_08140810: @ 0x08140810
.L08140810:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, .L08140904
	adds r5, r4, #0
	adds r5, #0x6a
	ldrh r0, [r5]
	cmp r0, #1
	bne .L08140838
	ldr r0, .L08140908
	movs r1, #0
	str r1, [sp]
	movs r1, #0x44
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08140838:
	adds r0, r4, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne .L0814085C
	ldr r0, .L0814090C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x69
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814085C:
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #1
	bne .L08140880
	ldr r0, .L08140910
	movs r1, #0
	str r1, [sp]
	movs r1, #0x8f
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08140880:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bhi .L081408FC
	ldrh r1, [r5]
	cmp r1, #0
	bne .L081408A8
	ldrh r0, [r4, #0x1c]
	cmp r0, #0xa
	bls .L081408A8
	ldr r0, .L08140908
	str r1, [sp]
	movs r1, #0x44
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081408A8:
	ldrh r1, [r6]
	cmp r1, #0
	bne .L081408CA
	ldrh r0, [r4, #0x1c]
	cmp r0, #0xa
	bls .L081408CA
	ldr r0, .L0814090C
	str r1, [sp]
	movs r1, #0x69
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081408CA:
	ldrh r1, [r7]
	cmp r1, #0
	bne .L081408EC
	ldrh r0, [r4, #0x1c]
	cmp r0, #0xa
	bls .L081408EC
	ldr r0, .L08140910
	str r1, [sp]
	movs r1, #0x8f
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081408EC:
	ldrh r0, [r4, #0x1c]
	cmp r0, #0x14
	bls .L081408F6
	movs r0, #0
	strh r0, [r4, #0x1c]
.L081408F6:
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
.L081408FC:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08140904: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08140908: .4byte gUnknown_0814ECA0
.L0814090C: .4byte gUnknown_0814ECB0
.L08140910: .4byte gUnknown_0814ECC0

	thumb_func_start sub_08140914
sub_08140914: @ 0x08140914
.L08140914:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r7, .L08140A1C
	ldr r4, .L08140A20
	adds r0, r7, #0
	adds r0, #0x84
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, #4
	adds r0, r0, r4
	ldr r0, [r0]
	movs r6, #0
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0x39
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r5, #0x5a
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0x4e
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x94
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0x63
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0x8d
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0xac
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r6, [sp]
	ldrh r1, [r7, #0x22]
	adds r1, #0xa2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08140A1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08140A20: .4byte gUnknown_08794D90

	thumb_func_start sub_08140A24
sub_08140A24: @ 0x08140A24
.L08140A24:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L08140AC4
	ldr r0, .L08140AC8
	mov ip, r0
	ldr r3, .L08140ACC
	mov r7, ip
	adds r7, #0x48
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r5, [r1]
	mov r1, ip
	str r5, [r1, #0x74]
	ldr r3, .L08140AD0
	mov r6, ip
	adds r6, #0x54
	ldrh r0, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r4, r0, #5
	adds r1, r1, r4
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r5, r0
	bne .L08140ABC
	ldr r2, .L08140AD4
	mov r3, ip
	adds r3, #0x60
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r5, r0
	bne .L08140ABC
	mov r1, ip
	adds r1, #0xb8
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r3]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xb4
	str r5, [r0]
	adds r1, #6
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	mov r1, ip
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x1e]
	movs r0, #2
	strh r0, [r1, #0x38]
	bl sub_08141F24
.L08140ABC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08140AC4: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08140AC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08140ACC: .4byte gUnknown_0879245C
.L08140AD0: .4byte gUnknown_087931DC
.L08140AD4: .4byte gUnknown_08793F5C

	thumb_func_start sub_08140AD8
sub_08140AD8: @ 0x08140AD8
.L08140AD8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L08140E54
	mov r8, r0
	ldr r4, .L08140E58
	ldr r3, .L08140E5C
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	str r0, [r4, #0x70]
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	str r0, [r4, #0x74]
	movs r1, #0x4a
	adds r1, r1, r4
	mov ip, r1
	ldrh r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r6, [r1]
	str r6, [r4, #0x78]
	adds r1, r4, #0
	adds r1, #0x40
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne .L08140BD2
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140BD2
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140BCC
	ldr r3, .L08140E60
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r6, r0
	bne .L08140BCC
	ldr r2, .L08140E64
	adds r3, r4, #0
	adds r3, #0x62
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r6, r0
	bne .L08140BCC
	adds r1, r4, #0
	adds r1, #0xb8
	mov r2, ip
	ldrh r0, [r2]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r3]
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r1, #6
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140BCC:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140BD2:
	ldrh r7, [r4, #0x2c]
	cmp r7, #1
	bne .L08140C62
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140C62
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140C5C
	ldr r3, .L08140E60
	movs r0, #0x56
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140C5C
	ldr r2, .L08140E64
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140C5C
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r2, ip
	ldrh r0, [r2]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x2c
	strh r0, [r1]
	strh r7, [r4, #0x2a]
	strh r7, [r4, #0x1e]
	strh r7, [r4, #0x38]
	bl sub_08141F24
.L08140C5C:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140C62:
	ldrh r0, [r4, #0x2c]
	cmp r0, #2
	bne .L08140CF0
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140CF0
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140CEA
	ldr r3, .L08140E60
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140CEA
	ldr r2, .L08140E64
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140CEA
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140CEA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140CF0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #3
	bne .L08140D7E
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140D7E
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140D78
	ldr r3, .L08140E60
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140D78
	ldr r2, .L08140E64
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140D78
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140D78:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140D7E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #4
	bne .L08140E0C
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140E0C
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140E06
	ldr r3, .L08140E60
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140E06
	ldr r2, .L08140E64
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140E06
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140E06:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140E0C:
	ldrh r0, [r4, #0x2c]
	cmp r0, #5
	bne .L08140EB2
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140EB2
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140EAC
	ldr r3, .L08140E60
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140EAC
	ldr r2, .L08140E64
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	b .L08140E68
.L08140E54: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08140E58: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08140E5C: .4byte gUnknown_0879245C
.L08140E60: .4byte gUnknown_087931DC
.L08140E64: .4byte gUnknown_08793F5C
.L08140E68:
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140EAC
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140EAC:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140EB2:
	ldrh r0, [r4, #0x2c]
	cmp r0, #6
	bne .L08140F40
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140F40
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140F3A
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140F3A
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140F3A
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140F3A:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140F40:
	ldrh r0, [r4, #0x2c]
	cmp r0, #7
	bne .L08140FD0
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08140FD0
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08140FCA
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08140FCA
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08140FCA
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08140FCA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08140FD0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #8
	bne .L0814105E
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L0814105E
	ldrh r0, [r4, #0x2e]
	cmp r0, #1
	bhi .L08141058
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x78]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141058
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141058
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x78]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141058:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L0814105E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #9
	bne .L081410F2
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081410F2
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141074
	cmp r0, #2
	bne .L081410EC
.L08141074:
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081410EC
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081410EC
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081410EC:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081410F2:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xa
	bne .L08141186
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141186
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141108
	cmp r0, #2
	bne .L08141180
.L08141108:
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141180
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141180
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141180:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141186:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xb
	bne .L0814121C
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L0814121C
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L0814119C
	cmp r0, #2
	bne .L08141216
.L0814119C:
	ldr r3, .L08141230
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141216
	ldr r2, .L08141234
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141216
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141216:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L0814121C:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xc
	bne .L081412BC
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081412BC
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	b .L08141238
	.byte 0x00, 0x00
.L08141230: .4byte gUnknown_087931DC
.L08141234: .4byte gUnknown_08793F5C
.L08141238:
	beq .L0814123E
	cmp r0, #2
	bne .L081412B6
.L0814123E:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081412B6
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081412B6
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081412B6:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081412BC:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xd
	bne .L0814134E
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L0814134E
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081412D2
	cmp r0, #2
	bne .L08141348
.L081412D2:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141348
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141348
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141348:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L0814134E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xe
	bne .L081413E2
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081413E2
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141364
	cmp r0, #2
	bne .L081413DC
.L08141364:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081413DC
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081413DC
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081413DC:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081413E2:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0xf
	bne .L08141478
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141478
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081413F8
	cmp r0, #2
	bne .L08141472
.L081413F8:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141472
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141472
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141472:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141478:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x10
	bne .L0814150C
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L0814150C
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L0814148E
	cmp r0, #2
	bne .L08141506
.L0814148E:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141506
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141506
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141506:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L0814150C:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x11
	bne .L081415A0
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081415A0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141522
	cmp r0, #2
	bne .L0814159A
.L08141522:
	ldr r3, .L081415A8
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x74]
	ldr r0, [r1]
	cmp r3, r0
	bne .L0814159A
	ldr r2, .L081415AC
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L0814159A
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x74]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #2
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L0814159A:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081415A0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x12
	b .L081415B0
	.byte 0x00, 0x00
.L081415A8: .4byte gUnknown_087931DC
.L081415AC: .4byte gUnknown_08793F5C
.L081415B0:
	bne .L08141640
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141640
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081415C2
	cmp r0, #3
	bne .L0814163A
.L081415C2:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L0814163A
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L0814163A
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x18
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L0814163A:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141640:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x13
	bne .L081416D6
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081416D6
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141656
	cmp r0, #3
	bne .L081416D0
.L08141656:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081416D0
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081416D0
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081416D0:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081416D6:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x14
	bne .L0814176A
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L0814176A
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081416EC
	cmp r0, #3
	bne .L08141764
.L081416EC:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x56
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141764
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141764
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141764:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L0814176A:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x15
	bne .L08141800
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141800
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141780
	cmp r0, #3
	bne .L081417FA
.L08141780:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081417FA
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081417FA
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x18
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081417FA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141800:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x16
	bne .L08141894
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141894
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141816
	cmp r0, #3
	bne .L0814188E
.L08141816:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L0814188E
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L0814188E
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0xa
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x2c
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L0814188E:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141894:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x17
	bne .L08141928
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141928
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081418AA
	cmp r0, #3
	bne .L08141922
.L081418AA:
	ldr r3, .L0814192C
	adds r7, r4, #0
	adds r7, #0x54
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141922
	ldr r2, .L08141930
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141922
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0x18
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x2c
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141922:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141928:
	ldrh r1, [r4, #0x2c]
	b .L08141934
.L0814192C: .4byte gUnknown_087931DC
.L08141930: .4byte gUnknown_08793F5C
.L08141934:
	mov ip, r1
	cmp r1, #0x18
	bne .L081419CA
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L081419CA
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L0814194A
	cmp r0, #3
	bne .L081419C4
.L0814194A:
	ldr r3, .L08141B00
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L081419C4
	ldr r2, .L08141B04
	adds r6, r4, #0
	adds r6, #0x62
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L081419C4
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd6
	mov r1, ip
	strh r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L081419C4:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L081419CA:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x19
	bne .L08141A5E
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141A5E
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L081419E0
	cmp r0, #3
	bne .L08141A58
.L081419E0:
	ldr r3, .L08141B00
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141A58
	ldr r2, .L08141B04
	adds r6, r4, #0
	adds r6, #0x60
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141A58
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0x16
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #0x2c
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141A58:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141A5E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x1a
	bne .L08141AF6
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	bne .L08141AF6
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq .L08141A74
	cmp r0, #3
	bne .L08141AF0
.L08141A74:
	ldr r3, .L08141B00
	adds r7, r4, #0
	adds r7, #0x52
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r5, r0, #5
	adds r1, r1, r5
	adds r1, r1, r3
	ldr r3, [r4, #0x70]
	ldr r0, [r1]
	cmp r3, r0
	bne .L08141AF0
	ldr r2, .L08141B04
	adds r6, r4, #0
	adds r6, #0x5e
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r3, r0
	bne .L08141AF0
	adds r1, r4, #0
	adds r1, #0xb8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r7]
	str r0, [r1]
	adds r1, #0xc
	ldrh r0, [r6]
	str r0, [r1]
	subs r1, #0x1c
	ldr r0, [r4, #0x70]
	str r0, [r1]
	adds r1, #0x22
	movs r0, #0x40
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x1e]
	movs r0, #3
	strh r0, [r4, #0x38]
	bl sub_08141F24
.L08141AF0:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08141AF6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08141B00: .4byte gUnknown_087931DC
.L08141B04: .4byte gUnknown_08793F5C

	thumb_func_start sub_08141B08
sub_08141B08: @ 0x08141B08
.L08141B08:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L08141BF0
	ldr r6, .L08141BF4
	ldr r3, .L08141BF8
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r5, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	adds r1, #0xbc
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r1, #0xbe
	ldrb r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r3, .L08141BFC
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r5, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	str r4, [sp]
	adds r1, r6, #0
	adds r1, #0xc8
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r1, #0xca
	ldrb r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r3, .L08141C00
	adds r0, r6, #0
	adds r0, #0xd0
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r5, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	str r4, [sp]
	adds r1, r6, #0
	adds r1, #0xd4
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r1, #0xd6
	ldrb r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r2, .L08141C04
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	str r4, [sp]
	ldrh r2, [r1, #4]
	str r2, [sp, #4]
	ldrb r1, [r1, #6]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08141BF0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08141BF4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08141BF8: .4byte gUnknown_0879245C
.L08141BFC: .4byte gUnknown_087931DC
.L08141C00: .4byte gUnknown_08793F5C
.L08141C04: .4byte gUnknown_08794CDC

	thumb_func_start sub_08141C08
sub_08141C08: @ 0x08141C08
.L08141C08:
	push {r4, r5, lr}
	ldr r3, .L08141D88
	adds r5, r3, #0
	adds r5, #0x88
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141C4A
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141C4A
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0x84
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141C4A
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141C4A:
	adds r5, r3, #0
	adds r5, #0x90
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141C88
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141C88
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141C88
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141C88:
	adds r5, r3, #0
	adds r5, #0x98
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141CC6
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141CC6
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0x94
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141CC6
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141CC6:
	adds r5, r3, #0
	adds r5, #0xa0
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141D04
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141D04
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0x9c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141D04
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141D04:
	adds r5, r3, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141D42
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141D42
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0xa4
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141D42
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141D42:
	adds r5, r3, #0
	adds r5, #0xb0
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08141D80
	adds r4, r3, #0
	adds r4, #0x40
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08141D80
	ldr r2, .L08141D8C
	adds r0, r3, #0
	adds r0, #0xac
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L08141D80
	movs r0, #1
	strh r0, [r5]
	strh r0, [r4]
	subs r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08141D80:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08141D88: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08141D8C: .4byte gUnknown_08794D90

	thumb_func_start sub_08141D90
sub_08141D90: @ 0x08141D90
.L08141D90:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L08141EFC
	adds r0, r4, #0
	adds r0, #0x88
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141DD0
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0x39
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141DD0:
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141E0A
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0x4e
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141E0A:
	adds r0, r4, #0
	adds r0, #0x98
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141E44
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0x94
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0x63
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141E44:
	adds r0, r4, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141E7E
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141E7E:
	adds r0, r4, #0
	adds r0, #0xa8
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141EB8
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0x8d
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141EB8:
	adds r0, r4, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08141EF2
	ldr r2, .L08141F00
	adds r0, r4, #0
	adds r0, #0xac
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x22]
	adds r1, #0xa2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x5a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08141EF2:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08141EFC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08141F00: .4byte gUnknown_08794D90

	thumb_func_start sub_08141F04
sub_08141F04: @ 0x08141F04
.L08141F04:
	ldr r2, .L08141F20
	movs r1, #0
	strh r1, [r2, #0x18]
	strh r1, [r2, #0x1a]
	adds r0, r2, #0
	adds r0, #0x6e
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	strh r1, [r2, #8]
	bx lr
	.byte 0x00, 0x00
.L08141F20: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08141F24
sub_08141F24: @ 0x08141F24
.L08141F24:
	push {r4, lr}
	ldr r4, .L08141F54
	ldr r3, [r4, #0x30]
	str r3, [r4, #0x34]
	ldrh r0, [r4, #0x38]
	cmp r0, #1
	bne .L08141F5C
	ldr r2, [r4, #0x78]
	cmp r2, #8
	bne .L08141FB4
	bl sub_080C2244
	movs r1, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L08141F58
	lsls r1, r1, #1
	adds r0, #0xa8
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, [r4, #0x34]
	adds r0, r0, r1
	b .L08141FC2
.L08141F54: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08141F58: .4byte gUnknown_08794CDC
.L08141F5C:
	cmp r0, #2
	bne .L08141F88
	ldr r2, [r4, #0x74]
	cmp r2, #8
	bne .L08141FB4
	bl sub_080C2244
	movs r1, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L08141F84
	lsls r1, r1, #1
	adds r0, #0xa8
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, [r4, #0x34]
	adds r0, r0, r1
	b .L08141FC2
	.byte 0x00, 0x00
.L08141F84: .4byte gUnknown_08794CDC
.L08141F88:
	cmp r0, #3
	bne .L08141FC4
	ldr r2, [r4, #0x70]
	cmp r2, #8
	bne .L08141FB4
	bl sub_080C2244
	movs r1, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L08141FB0
	lsls r1, r1, #1
	adds r0, #0xa8
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, [r4, #0x34]
	adds r0, r0, r1
	b .L08141FC2
	.byte 0x00, 0x00
.L08141FB0: .4byte gUnknown_08794CDC
.L08141FB4:
	ldr r0, .L08141FD8
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #8]
	adds r0, r3, r0
.L08141FC2:
	str r0, [r4, #0x34]
.L08141FC4:
	ldr r1, [r4, #0x34]
	ldr r0, .L08141FDC
	cmp r1, r0
	bls .L08141FD0
	adds r0, #1
	str r0, [r4, #0x34]
.L08141FD0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08141FD8: .4byte gUnknown_08794CDC
.L08141FDC: .4byte 0x000003E7

	thumb_func_start sub_08141FE0
sub_08141FE0: @ 0x08141FE0
.L08141FE0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	mov r8, r0
	ldr r0, .L081420DC
	mov sb, r0
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	movs r6, #0
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #0xff
	ands r4, r1
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #5]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081420DC: .4byte gUnknown_08794DFC

	thumb_func_start sub_081420E0
sub_081420E0: @ 0x081420E0
.L081420E0:
	push {r4, lr}
	ldr r4, .L08142108
	ldr r0, .L0814210C
	ldr r2, [r0]
	movs r0, #3
	ands r2, r0
	cmp r2, #0
	bne .L0814212C
	ldr r1, [r4, #0x30]
	ldr r0, [r4, #0x34]
	cmp r1, r0
	beq .L08142114
	ldr r0, .L08142110
	bl sub_080C51D4
	ldr r0, [r4, #0x30]
	adds r0, #1
	str r0, [r4, #0x30]
	b .L0814212C
	.byte 0x00, 0x00
.L08142108: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814210C: .4byte 0x030031BC @ IWRAM+0x31BC
.L08142110: .4byte 0x00000159
.L08142114:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne .L08142128
	ldr r0, [r4, #0x3c]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	str r2, [r4, #0x30]
	movs r0, #6
	b .L0814212A
.L08142128:
	movs r0, #4
.L0814212A:
	strh r0, [r4, #4]
.L0814212C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08142134
sub_08142134: @ 0x08142134
	ldr r0, .L0814213C
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0814213C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08142140
sub_08142140: @ 0x08142140
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, .L081421E8
	movs r4, #0
	str r4, [sp]
	ldr r2, .L081421EC
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	ldr r1, .L081421F0
	ldr r2, .L081421F4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L081421F8
	strh r4, [r0]
	ldr r0, .L081421FC
	strh r4, [r0]
	movs r5, #1
	strh r5, [r6]
	bl sub_080C31F0
	str r0, [r6, #0x3c]
	movs r1, #2
	strh r1, [r6, #0x36]
	adds r0, r6, #0
	adds r0, #0x8c
	strh r4, [r0]
	subs r0, #0xc
	strh r4, [r0]
	subs r0, #0xc
	strh r4, [r0]
	subs r0, #0xc
	strh r4, [r0]
	adds r0, #0x26
	strh r5, [r0]
	subs r0, #0xc
	strh r5, [r0]
	subs r0, #0xc
	strh r5, [r0]
	subs r0, #0xc
	strh r5, [r0]
	adds r0, #0x26
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0x92
	movs r0, #3
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x94
	movs r1, #4
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	adds r0, #0x26
	movs r1, #5
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081421E8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081421EC: .4byte 0x05000200 @ PLTT+0x200
.L081421F0: .4byte 0x04000008 @ REG_BG0CNT
.L081421F4: .4byte 0x00004008
.L081421F8: .4byte 0x03000002 @ IWRAM+0x2
.L081421FC: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_08142200
sub_08142200: @ 0x08142200
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r5, .L081422A4
	ldrh r0, [r5]
	cmp r0, #1
	bne .L0814221E
	ldr r0, .L081422A8
	ldr r1, .L081422AC
	bl Task_Create
	movs r0, #0
	strh r0, [r5]
.L0814221E:
	bl sub_081429B4
	ldr r0, [r5, #0x40]
	movs r1, #0x2f
	movs r2, #0x20
	movs r3, #0
	bl sub_08142F08
	ldr r0, [r5, #0x3c]
	movs r1, #0xe5
	movs r2, #0x20
	movs r3, #0
	bl sub_08142F08
	ldr r0, .L081422B0
	movs r4, #0
	str r4, [sp]
	movs r1, #0x47
	str r1, [sp, #4]
	movs r1, #0x25
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #1
	bne .L08142262
	bl sub_08143BF8
.L08142262:
	ldrh r0, [r5, #0x32]
	cmp r0, #1
	bne .L0814227E
	ldr r0, .L081422B4
	str r4, [sp]
	movs r1, #0xb0
	str r1, [sp, #4]
	movs r1, #0x2b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814227E:
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #1
	bne .L0814228E
	bl sub_08143ED0
.L0814228E:
	bl sub_08144270
	ldrh r0, [r5, #0x36]
	cmp r0, #3
	beq .L081422CC
	cmp r0, #3
	bgt .L081422B8
	cmp r0, #2
	beq .L081422C2
	b .L08142306
	.byte 0x00, 0x00
.L081422A4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081422A8: .4byte gUnknown_0879874C
.L081422AC: .4byte 0x0000FFFF
.L081422B0: .4byte gUnknown_0814F508
.L081422B4: .4byte gUnknown_0814F29C
.L081422B8:
	cmp r0, #4
	beq .L081422D4
	cmp r0, #5
	beq .L081422F0
	b .L08142306
.L081422C2:
	ldr r0, .L081422C8
	b .L081422D6
	.byte 0x00, 0x00
.L081422C8: .4byte gUnknown_0814F2CC
.L081422CC:
	ldr r0, .L081422D0
	b .L081422D6
.L081422D0: .4byte gUnknown_0814F2FC
.L081422D4:
	ldr r0, .L081422EC
.L081422D6:
	str r4, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08142306
.L081422EC: .4byte gUnknown_0814F32C
.L081422F0:
	ldr r0, .L081423C8
	str r4, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08142306:
	adds r0, r5, #0
	adds r0, #0xe8
	ldrb r6, [r0]
	adds r7, r0, #0
	cmp r6, #1
	bne .L08142386
	ldr r0, .L081423CC
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08142364
	ldrb r4, [r5, #4]
	cmp r4, #0
	bne .L08142364
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	beq .L08142364
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	strb r6, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r4, [r0]
	subs r0, #0x51
	strb r4, [r0]
	subs r0, #0x25
	strb r4, [r0]
	adds r0, #0x23
	strb r4, [r0]
	subs r0, #0x24
	strb r4, [r0]
	mov r0, sb
	strb r4, [r0]
	adds r0, r5, #0
	adds r0, #0x52
	strb r4, [r0]
	subs r0, #0x27
	strb r4, [r0]
	adds r0, #0x25
	strb r6, [r0]
	ldr r0, [r5, #0x3c]
	subs r0, #1
	str r0, [r5, #0x3c]
.L08142364:
	ldr r0, .L081423CC
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08142386
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq .L0814237A
	b .L081424EA
.L0814237A:
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #0xa
	strb r0, [r5, #4]
.L08142386:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq .L0814238E
	b .L081424EA
.L0814238E:
	mov r1, r8
	ldrb r6, [r1]
	cmp r6, #1
	beq .L08142398
	b .L081424EA
.L08142398:
	ldr r0, .L081423CC
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L081423D0
	ldrb r0, [r5, #9]
	cmp r0, #0
	bne .L081423D0
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #2
	bhi .L081423D0
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	strb r6, [r5, #9]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L081423F0
	.byte 0x00, 0x00
.L081423C8: .4byte gUnknown_0814F35C
.L081423CC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081423D0:
	ldr r0, .L08142420
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L081423F0
	ldrb r0, [r5, #9]
	cmp r0, #1
	bne .L081423F0
	movs r0, #0
	strb r0, [r5, #9]
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
.L081423F0:
	ldr r0, .L08142420
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08142424
	ldrb r0, [r5, #0xa]
	cmp r0, #0
	bne .L08142424
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #2
	bhi .L08142424
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
	strb r0, [r5, #0xa]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L08142444
.L08142420: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08142424:
	ldr r0, .L08142474
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08142444
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	bne .L08142444
	movs r0, #0
	strb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
.L08142444:
	ldr r0, .L08142474
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08142478
	ldrb r0, [r5, #0xb]
	cmp r0, #0
	bne .L08142478
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #2
	bhi .L08142478
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
	strb r0, [r5, #0xb]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L08142498
.L08142474: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08142478:
	ldr r0, .L081424C8
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08142498
	ldrb r0, [r5, #0xb]
	cmp r0, #1
	bne .L08142498
	movs r0, #0
	strb r0, [r5, #0xb]
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
.L08142498:
	ldr r2, .L081424C8
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L081424CC
	ldrb r0, [r5, #0xc]
	cmp r0, #0
	bne .L081424CC
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #2
	bhi .L081424CC
	movs r0, #0xae
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
	strb r0, [r5, #0xc]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L081424EA
.L081424C8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081424CC:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L081424EA
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bne .L081424EA
	movs r0, #0
	strb r0, [r5, #0xc]
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
.L081424EA:
	ldrb r0, [r5, #4]
	cmp r0, #0xa
	bls .L081424F2
	b .L0814260A
.L081424F2:
	lsls r0, r0, #2
	ldr r1, .L081424FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081424FC: .4byte gUnknown_08142500
	.global gUnknown_08142500
gUnknown_08142500:
.L08142500: @ jump table
	.4byte .L0814252C
	.4byte .L08142568
	.4byte .L08142572
	.4byte .L0814259C
	.4byte .L0814260A
	.4byte .L0814260A
	.4byte .L0814260A
	.4byte .L0814260A
	.4byte .L0814260A
	.4byte .L0814260A
	.4byte .L081425B6
.L0814252C:
	adds r0, r5, #0
	adds r0, #0x55
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x14
	bls .L081425F2
	ldr r0, .L08142564
	movs r5, #0
	str r5, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrb r0, [r4]
	cmp r0, #0x28
	bls .L081425F2
	strb r5, [r4]
	ldrb r0, [r7]
	cmp r0, #0
	bne .L081425F2
	movs r0, #1
	strb r0, [r7]
	b .L081425F2
.L08142564: .4byte gUnknown_0814F1CC
.L08142568:
	bl sub_08142618
	bl sub_0814328C
	b .L0814260A
.L08142572:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0814257E
	bl sub_08143A68
.L0814257E:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814258C
	bl sub_08143CB8
.L0814258C:
	adds r0, r5, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814260A
	bl sub_081437E4
	b .L0814260A
.L0814259C:
	adds r0, r5, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081425AC
	bl sub_08143044
	b .L081425B0
.L081425AC:
	bl sub_081431F8
.L081425B0:
	bl sub_081445C4
	b .L0814260A
.L081425B6:
	adds r6, r5, #0
	adds r6, #0x54
	ldrb r0, [r6]
	cmp r0, #5
	bhi .L08142600
	adds r4, r5, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #3
	bls .L081425E2
	ldr r0, .L081425FC
	movs r1, #0
	str r1, [sp]
	movs r1, #9
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081425E2:
	ldrb r0, [r4]
	cmp r0, #6
	bls .L081425F2
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
.L081425F2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L0814260A
	.byte 0x00, 0x00
.L081425FC: .4byte gUnknown_0814F1E4
.L08142600:
	ldr r0, [r5, #0x3c]
	bl sub_080C31FC
	bl sub_080BE4C4
.L0814260A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08142618
sub_08142618: @ 0x08142618
.L08142618:
	push {r4, r5, lr}
	ldr r4, .L081429A0
	adds r5, r4, #0
	adds r5, #0x2b
	ldrb r0, [r5]
	cmp r0, #0
	bne .L08142628
	b .L081427C0
.L08142628:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L0814268C
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x68
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x6a
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x6c
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x70
	strh r0, [r1]
	ldrh r0, [r4, #0xe]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x72
	strh r0, [r1]
.L0814268C:
	ldrb r0, [r5]
	cmp r0, #0
	bne .L08142694
	b .L081427C0
.L08142694:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L081426F8
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x74
	strh r0, [r1]
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x76
	strh r0, [r1]
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	ldrh r0, [r4, #0x10]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x7e
	strh r0, [r1]
.L081426F8:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L0814275C
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x84
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x88
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x8a
	strh r0, [r1]
.L0814275C:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081427C0
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x8e
	strh r0, [r1]
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #2
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #3
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #4
	adds r1, r4, #0
	adds r1, #0x94
	strh r0, [r1]
	ldrh r0, [r4, #0x14]
	movs r1, #0x14
	bl __udivsi3
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x96
	strh r0, [r1]
.L081427C0:
	movs r0, #0x72
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L081427D2
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
.L081427D2:
	adds r5, r4, #0
	adds r5, #0x70
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L081427E6
	movs r0, #0
	strh r0, [r5]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
.L081427E6:
	adds r3, r4, #0
	adds r3, #0x6e
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L081427FE
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
.L081427FE:
	adds r2, r4, #0
	adds r2, #0x6c
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L0814281A
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	strh r0, [r5]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
.L0814281A:
	adds r1, r4, #0
	adds r1, #0x6a
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L0814283A
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	strh r0, [r5]
	movs r0, #4
	mov r1, ip
	strh r0, [r1]
.L0814283A:
	movs r0, #0x7e
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L0814284C
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
.L0814284C:
	adds r5, r4, #0
	adds r5, #0x7c
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L08142860
	movs r0, #0
	strh r0, [r5]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
.L08142860:
	adds r3, r4, #0
	adds r3, #0x7a
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L08142878
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
.L08142878:
	adds r2, r4, #0
	adds r2, #0x78
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L08142894
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	strh r0, [r5]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
.L08142894:
	adds r1, r4, #0
	adds r1, #0x76
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L081428B4
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	strh r0, [r5]
	movs r0, #4
	mov r1, ip
	strh r0, [r1]
.L081428B4:
	movs r0, #0x8a
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L081428C6
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
.L081428C6:
	adds r5, r4, #0
	adds r5, #0x88
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L081428DA
	movs r0, #0
	strh r0, [r5]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
.L081428DA:
	adds r3, r4, #0
	adds r3, #0x86
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L081428F2
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
.L081428F2:
	adds r2, r4, #0
	adds r2, #0x84
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L0814290E
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	strh r0, [r5]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
.L0814290E:
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L0814292E
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	movs r0, #3
	strh r0, [r5]
	movs r0, #4
	mov r1, ip
	strh r0, [r1]
.L0814292E:
	movs r0, #0x96
	adds r0, r0, r4
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0x18
	bne .L08142940
	movs r0, #0
	mov r1, ip
	strh r0, [r1]
.L08142940:
	adds r5, r4, #0
	adds r5, #0x94
	ldrh r0, [r5]
	cmp r0, #0x18
	bne .L08142954
	movs r0, #0
	strh r0, [r5]
	movs r0, #1
	mov r1, ip
	strh r0, [r1]
.L08142954:
	adds r3, r4, #0
	adds r3, #0x92
	ldrh r0, [r3]
	cmp r0, #0x18
	bne .L0814296C
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	movs r0, #2
	mov r1, ip
	strh r0, [r1]
.L0814296C:
	adds r2, r4, #0
	adds r2, #0x90
	ldrh r0, [r2]
	cmp r0, #0x18
	bne .L08142988
	movs r0, #0
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	movs r0, #2
	strh r0, [r5]
	movs r0, #3
	mov r1, ip
	strh r0, [r1]
.L08142988:
	adds r1, r4, #0
	adds r1, #0x8e
	ldrh r0, [r1]
	cmp r0, #0x18
	bne .L081429AE
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r3]
	b .L081429A4
.L081429A0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081429A4:
	movs r0, #3
	strh r0, [r5]
	movs r0, #4
	mov r1, ip
	strh r0, [r1]
.L081429AE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_081429B4
sub_081429B4: @ 0x081429B4
.L081429B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, .L08142DAC
	mov r8, r0
	ldr r7, .L08142DB0
	ldr r4, .L08142DB4
	adds r0, r7, #0
	adds r0, #0x72
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r0, [r1]
	movs r6, #0
	str r6, [sp]
	movs r1, #0x3b
	mov sb, r1
	str r1, [sp, #4]
	ldr r2, .L08142DB8
	ldrb r3, [r7, #5]
	adds r1, r2, r3
	movs r5, #0xff
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x70
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldr r2, .L08142DBC
	mov sl, r2
	ldrb r1, [r7, #5]
	add r1, sl
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #5]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #5]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #5]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #5]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r4, .L08142DC0
	adds r0, r7, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	movs r1, #0x5a
	mov sb, r1
	str r1, [sp, #4]
	ldr r2, .L08142DB8
	ldrb r3, [r7, #6]
	adds r1, r2, r3
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #6]
	add r1, sl
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #6]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x78
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #6]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x76
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #6]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x74
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #6]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r4, .L08142DC4
	adds r0, r7, #0
	adds r0, #0x8a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r4, #4
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	movs r1, #0x79
	mov sb, r1
	str r1, [sp, #4]
	ldr r2, .L08142DB8
	ldrb r3, [r7, #7]
	adds r1, r2, r3
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #7]
	add r1, sl
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x86
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #7]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #7]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x82
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #7]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x80
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #7]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r4, .L08142DC8
	adds r0, r7, #0
	adds r0, #0x96
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	b .L08142DCC
	.byte 0x00, 0x00
.L08142DAC: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08142DB0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08142DB4: .4byte gUnknown_0879505C
.L08142DB8: .4byte 0x0000FFDC
.L08142DBC: .4byte 0x0000FFF0
.L08142DC0: .4byte gUnknown_08795DDC
.L08142DC4: .4byte gUnknown_08796B5C
.L08142DC8: .4byte gUnknown_087978DC
.L08142DCC:
	adds r4, #4
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	movs r1, #0x98
	mov sb, r1
	str r1, [sp, #4]
	ldr r2, .L08142F04
	ldrb r3, [r7, #8]
	adds r1, r2, r3
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r2, [r7, #8]
	add sl, r2
	mov r3, sl
	ands r3, r5
	str r3, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, r8
	ldrh r2, [r0, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #8]
	adds r1, #4
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #8]
	adds r1, #0x18
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #8]
	adds r1, #0x2c
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	adds r0, r7, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r3, r8
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r0, [r1]
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldrb r1, [r7, #8]
	adds r1, #0x40
	ands r1, r5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08142F04: .4byte 0x0000FFDC

	thumb_func_start sub_08142F08
sub_08142F08: @ 0x08142F08
.L08142F08:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	mov r8, r0
	ldr r0, .L08143004
	mov sb, r0
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	movs r6, #0
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #0xff
	ands r4, r1
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #5]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08143004: .4byte gUnknown_087986BC

	thumb_func_start sub_08143008
sub_08143008: @ 0x08143008
.L08143008:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L08143018
	cmp r6, #0
	bne .L08143020
	movs r0, #0
	b .L0814303E
	.byte 0x00, 0x00
.L08143018: .4byte 0x00002710
.L0814301C:
	adds r0, r4, #0
	b .L0814303E
.L08143020:
	movs r5, #0
.L08143022:
	adds r0, r6, #0
	adds r1, r4, #0
	bl __udivsi3
	cmp r0, #0
	bne .L0814301C
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	adds r4, r0, #0
	adds r5, #1
	cmp r5, #4
	bls .L08143022
.L0814303E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_08143044
sub_08143044: @ 0x08143044
.L08143044:
	push {r4, lr}
	ldr r4, .L08143070
	ldr r0, .L08143074
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq .L08143056
	b .L081431C6
.L08143056:
	ldr r0, .L08143078
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0814307C
	ldr r0, [r4, #0x40]
	bl sub_08143008
	str r0, [r4, #0x4c]
	b .L0814307E
	.byte 0x00, 0x00
.L08143070: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143074: .4byte 0x030031BC @ IWRAM+0x31BC
.L08143078: .4byte 0x03003964 @ IWRAM+0x3964
.L0814307C:
	str r2, [r4, #0x4c]
.L0814307E:
	ldr r0, [r4, #0x40]
	ldr r1, [r4, #0x4c]
	adds r0, r0, r1
	str r0, [r4, #0x40]
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bge .L0814308E
	b .L081431C6
.L0814308E:
	str r1, [r4, #0x40]
	ldr r0, [r4, #0x3c]
	str r0, [r4, #0x48]
	adds r0, r4, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp r0, #1
	beq .L081430A0
	b .L081431BA
.L081430A0:
	adds r0, r4, #0
	adds r0, #0xdc
	ldr r0, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r0, #7
	bhi .L0814318E
	lsls r0, r0, #2
	ldr r1, .L081430B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081430B8: .4byte gUnknown_081430BC
	.global gUnknown_081430BC
gUnknown_081430BC:
.L081430BC: @ jump table
	.4byte .L081430DC
	.4byte .L081430F2
	.4byte .L08143108
	.4byte .L0814311E
	.4byte .L08143134
	.4byte .L0814314A
	.4byte .L08143160
	.4byte .L08143176
.L081430DC:
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2f
	b .L0814318A
.L081430F2:
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2e
	b .L0814318A
.L08143108:
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2d
	b .L0814318A
.L0814311E:
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2c
	b .L0814318A
.L08143134:
	adds r0, r4, #0
	adds r0, #0x63
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2b
	b .L0814318A
.L0814314A:
	adds r0, r4, #0
	adds r0, #0x62
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x2a
	b .L0814318A
.L08143160:
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x29
	b .L0814318A
.L08143176:
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x39
	cmp r3, #1
	bne .L0814318E
	movs r1, #0
	strb r1, [r0]
	subs r0, #0x28
.L0814318A:
	strb r1, [r0]
	strb r3, [r2]
.L0814318E:
	ldrb r2, [r2]
	cmp r2, #0
	bne .L081431C6
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne .L081431AA
	adds r0, r4, #0
	adds r0, #0x50
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	b .L081431C6
.L081431AA:
	adds r1, r4, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x51
	strb r2, [r0]
	b .L081431C6
.L081431BA:
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
.L081431C6:
	ldr r0, [r4, #0x40]
	cmp r0, #0x63
	ble .L081431F0
	adds r0, r4, #0
	adds r0, #0x60
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
.L081431F0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081431F8
sub_081431F8: @ 0x081431F8
.L081431F8:
	push {r4, r5, lr}
	ldr r4, .L08143234
	ldr r0, .L08143238
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L08143264
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x64
	bls .L08143264
	ldr r0, .L0814323C
	bl sub_080C51D4
	ldr r0, .L08143240
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L08143244
	ldr r0, [r4, #0x40]
	bl sub_08143008
	str r0, [r4, #0x4c]
	b .L08143246
	.byte 0x00, 0x00
.L08143234: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143238: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814323C: .4byte 0x00000159
.L08143240: .4byte 0x03003964 @ IWRAM+0x3964
.L08143244:
	str r2, [r4, #0x4c]
.L08143246:
	ldr r0, [r4, #0x40]
	ldr r2, [r4, #0x4c]
	subs r0, r0, r2
	str r0, [r4, #0x40]
	ldr r1, [r4, #0x3c]
	adds r1, r1, r2
	str r1, [r4, #0x3c]
	cmp r0, #0
	bgt .L0814327A
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x44]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	movs r0, #0
	str r0, [r4, #0x40]
.L08143264:
	ldr r2, [r4, #0x40]
	adds r5, r4, #0
	adds r5, #0x51
	cmp r2, #0
	bne .L0814327A
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x44]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	str r2, [r4, #0x44]
	strb r2, [r4, #4]
.L0814327A:
	ldrb r0, [r5]
	cmp r0, #0x6e
	bhi .L08143284
	adds r0, #1
	strb r0, [r5]
.L08143284:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814328C
sub_0814328C: @ 0x0814328C
.L0814328C:
	push {r4, lr}
	ldr r4, .L081432A8
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #5
	bls .L0814329C
	b .L081434DC
.L0814329C:
	lsls r0, r0, #2
	ldr r1, .L081432AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L081432A8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081432AC: .4byte gUnknown_081432B0
	.global gUnknown_081432B0
gUnknown_081432B0:
.L081432B0: @ jump table
	.4byte .L081432C8
	.4byte .L08143326
	.4byte .L081433FA
	.4byte .L0814344C
	.4byte .L08143494
	.4byte .L081434D0
.L081432C8:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L081432D4
	ldrb r0, [r4, #5]
	adds r0, #2
	strb r0, [r4, #5]
.L081432D4:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L081432E0
	ldrb r0, [r4, #6]
	adds r0, #2
	strb r0, [r4, #6]
.L081432E0:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L081432EC
	ldrb r0, [r4, #7]
	adds r0, #2
	strb r0, [r4, #7]
.L081432EC:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081432F8
	ldrb r0, [r4, #8]
	adds r0, #2
	strb r0, [r4, #8]
.L081432F8:
	ldrb r0, [r4, #5]
	cmp r0, #0x28
	beq .L08143312
	ldrb r0, [r4, #6]
	cmp r0, #0x28
	beq .L08143312
	ldrb r0, [r4, #7]
	cmp r0, #0x28
	beq .L08143312
	ldrb r0, [r4, #8]
	cmp r0, #0x28
	beq .L08143312
	b .L081434DC
.L08143312:
	adds r2, r4, #0
	adds r2, #0x2b
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	strb r1, [r4, #8]
	strb r1, [r4, #7]
	strb r1, [r4, #6]
	strb r1, [r4, #5]
	b .L081434DC
.L08143326:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L08143352
	ldrh r0, [r4, #0xe]
	adds r0, #9
	strh r0, [r4, #0xe]
	bl sub_080C2244
	adds r1, r4, #0
	adds r1, #0x34
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r4, #0xe]
	adds r1, r1, r0
	strh r1, [r4, #0xe]
.L08143352:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L0814337E
	ldrh r0, [r4, #0x10]
	adds r0, #9
	strh r0, [r4, #0x10]
	bl sub_080C2244
	adds r1, r4, #0
	adds r1, #0x34
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r4, #0x10]
	adds r1, r1, r0
	strh r1, [r4, #0x10]
.L0814337E:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L081433AA
	ldrh r0, [r4, #0x12]
	adds r0, #9
	strh r0, [r4, #0x12]
	bl sub_080C2244
	adds r1, r4, #0
	adds r1, #0x34
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r4, #0x12]
	adds r1, r1, r0
	strh r1, [r4, #0x12]
.L081433AA:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081433D6
	ldrh r0, [r4, #0x14]
	adds r0, #9
	strh r0, [r4, #0x14]
	bl sub_080C2244
	adds r1, r4, #0
	adds r1, #0x34
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	ldrh r1, [r4, #0x14]
	adds r1, r1, r0
	strh r1, [r4, #0x14]
.L081433D6:
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #5
	bne .L081433F2
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x27
	bls .L081433F2
	adds r2, r4, #0
	adds r2, #0x2b
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	strh r1, [r4, #0x2c]
.L081433F2:
	ldrh r0, [r4, #0x2c]
	adds r0, #0x12
	strh r0, [r4, #0x2c]
	b .L081434DC
.L081433FA:
	ldrb r1, [r4, #9]
	cmp r1, #0
	bne .L08143406
	ldrb r0, [r4, #5]
	adds r0, #2
	strb r0, [r4, #5]
.L08143406:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L08143412
	ldrh r0, [r4, #0x10]
	adds r0, #9
	strh r0, [r4, #0x10]
.L08143412:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L0814341E
	ldrh r0, [r4, #0x12]
	adds r0, #9
	strh r0, [r4, #0x12]
.L0814341E:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L0814342A
	ldrh r0, [r4, #0x14]
	adds r0, #9
	strh r0, [r4, #0x14]
.L0814342A:
	ldrb r0, [r4, #5]
	cmp r0, #0x3c
	beq .L08143434
	cmp r1, #1
	bne .L081434DC
.L08143434:
	cmp r1, #0
	bne .L0814343E
	ldr r0, .L08143448
	bl sub_080C51D4
.L0814343E:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #3
	strb r0, [r1]
	b .L081434DC
.L08143448: .4byte 0x0000015B
.L0814344C:
	ldrb r1, [r4, #0xa]
	cmp r1, #0
	bne .L08143458
	ldrb r0, [r4, #6]
	adds r0, #2
	strb r0, [r4, #6]
.L08143458:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L08143464
	ldrh r0, [r4, #0x12]
	adds r0, #9
	strh r0, [r4, #0x12]
.L08143464:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L08143470
	ldrh r0, [r4, #0x14]
	adds r0, #9
	strh r0, [r4, #0x14]
.L08143470:
	ldrb r0, [r4, #6]
	cmp r0, #0x3c
	beq .L0814347A
	cmp r1, #1
	bne .L081434DC
.L0814347A:
	cmp r1, #0
	bne .L08143484
	ldr r0, .L08143490
	bl sub_080C51D4
.L08143484:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	b .L081434DC
	.byte 0x00, 0x00
.L08143490: .4byte 0x0000015B
.L08143494:
	ldrb r1, [r4, #0xb]
	cmp r1, #0
	bne .L081434A0
	ldrb r0, [r4, #7]
	adds r0, #2
	strb r0, [r4, #7]
.L081434A0:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081434AC
	ldrh r0, [r4, #0x14]
	adds r0, #9
	strh r0, [r4, #0x14]
.L081434AC:
	ldrb r0, [r4, #7]
	cmp r0, #0x3c
	beq .L081434B6
	cmp r1, #1
	bne .L081434DC
.L081434B6:
	cmp r1, #0
	bne .L081434C0
	ldr r0, .L081434CC
	bl sub_080C51D4
.L081434C0:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #5
	strb r0, [r1]
	b .L081434DC
	.byte 0x00, 0x00
.L081434CC: .4byte 0x0000015B
.L081434D0:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081434DC
	ldrb r0, [r4, #8]
	adds r0, #2
	strb r0, [r4, #8]
.L081434DC:
	ldrh r0, [r4, #0xe]
	movs r1, #0xef
	lsls r1, r1, #1
	cmp r0, r1
	bls .L081434EA
	movs r0, #0
	strh r0, [r4, #0xe]
.L081434EA:
	ldrh r0, [r4, #0x10]
	cmp r0, r1
	bls .L081434F4
	movs r0, #0
	strh r0, [r4, #0x10]
.L081434F4:
	ldrh r0, [r4, #0x12]
	cmp r0, r1
	bls .L081434FE
	movs r0, #0
	strh r0, [r4, #0x12]
.L081434FE:
	ldrh r0, [r4, #0x14]
	cmp r0, r1
	bls .L08143508
	movs r0, #0
	strh r0, [r4, #0x14]
.L08143508:
	ldrh r1, [r4, #0x2c]
	movs r0, #0x8a
	lsls r0, r0, #1
	cmp r1, r0
	bls .L08143520
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08143520:
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #5
	bne .L08143604
	ldrb r0, [r4, #8]
	cmp r0, #0x3b
	bhi .L08143536
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bne .L08143604
.L08143536:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L08143542
	ldr r0, .L0814360C
	bl sub_080C51D4
.L08143542:
	movs r0, #0
	movs r1, #2
	strb r1, [r4, #4]
	movs r2, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x2e
	strb r2, [r0]
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L08143576
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x6a
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x72
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
.L08143576:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L0814359A
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x76
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
.L0814359A:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L081435BE
	adds r0, r4, #0
	adds r0, #0x86
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
.L081435BE:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne .L081435E2
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x8e
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	ldrh r1, [r0]
	subs r0, #6
	strh r1, [r0]
.L081435E2:
	strb r2, [r4, #8]
	strb r2, [r4, #7]
	strb r2, [r4, #6]
	strb r2, [r4, #5]
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne .L08143604
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x29
	strb r2, [r0]
	strb r2, [r4, #0xc]
	strb r2, [r4, #0xb]
	strb r2, [r4, #0xa]
	strb r2, [r4, #9]
.L08143604:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814360C: .4byte 0x0000015B

	thumb_func_start sub_08143610
sub_08143610: @ 0x08143610
.L08143610:
	push {r4, r5, lr}
	ldr r1, .L08143644
	adds r5, r1, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #2
	bhi .L08143648
	adds r4, r1, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L0814362C
	bl sub_08143668
.L0814362C:
	ldrb r0, [r4]
	cmp r0, #0xa
	bls .L0814363C
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L0814363C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L08143660
.L08143644: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143648:
	adds r2, r1, #0
	adds r2, #0x55
	movs r0, #0
	strb r0, [r2]
	subs r2, #2
	strb r0, [r2]
	strb r0, [r5]
	subs r2, #1
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	strb r0, [r1, #4]
.L08143660:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08143668
sub_08143668: @ 0x08143668
.L08143668:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, .L0814377C
	ldr r7, .L08143780
	ldr r3, .L08143784
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r6, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	adds r1, r7, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	movs r5, #0
	str r5, [sp]
	movs r2, #0x3b
	str r2, [sp, #4]
	movs r4, #0x2c
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r3, .L08143788
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r6, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	adds r1, r7, #0
	adds r1, #0xc0
	ldrb r1, [r1]
	str r5, [sp]
	movs r2, #0x5a
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r3, .L0814378C
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r6, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	adds r1, r7, #0
	adds r1, #0xcc
	ldrb r1, [r1]
	str r5, [sp]
	movs r2, #0x79
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r3, .L08143790
	adds r0, r7, #0
	adds r0, #0xd4
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r6, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldr r0, [r1]
	adds r1, r7, #0
	adds r1, #0xd8
	ldrb r1, [r1]
	str r5, [sp]
	movs r2, #0x98
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #3
	bl Sprite_Draw
	ldr r2, .L08143794
	adds r4, r7, #0
	adds r4, #0xdc
	ldr r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	str r5, [sp]
	ldrh r2, [r1, #4]
	str r2, [sp, #4]
	ldrb r1, [r1, #6]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, [r4]
	cmp r0, #7
	bhi .L081437DA
	lsls r0, r0, #2
	ldr r1, .L08143798
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0814377C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08143780: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143784: .4byte gUnknown_0879505C
.L08143788: .4byte gUnknown_08795DDC
.L0814378C: .4byte gUnknown_08796B5C
.L08143790: .4byte gUnknown_087978DC
.L08143794: .4byte gUnknown_0879865C
.L08143798: .4byte gUnknown_0814379C
	.global gUnknown_0814379C
gUnknown_0814379C:
.L0814379C: @ jump table
	.4byte .L081437BC
	.4byte .L081437BC
	.4byte .L081437BC
	.4byte .L081437BC
	.4byte .L081437BC
	.4byte .L081437BC
	.4byte .L081437C8
	.4byte .L081437D2
.L081437BC:
	ldr r0, .L081437C4
	bl sub_080C51D4
	b .L081437DA
.L081437C4: .4byte 0x0000015D
.L081437C8:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L081437DA
.L081437D2:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
.L081437DA:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081437E4
sub_081437E4: @ 0x081437E4
.L081437E4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r3, .L081438D0
	ldr r0, .L081438D4
	mov ip, r0
	ldr r4, .L081438D8
	ldr r1, .L081438DC
	ldrh r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r6, [r1]
	mov r2, ip
	str r6, [r2, #0x18]
	ldr r4, .L081438E0
	movs r0, #0x76
	add r0, ip
	mov sl, r0
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r5, [r1]
	mov r1, ip
	str r5, [r1, #0x1c]
	ldr r4, .L081438E4
	movs r2, #0x82
	add r2, ip
	mov sb, r2
	ldrh r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r7, [r1]
	mov r0, ip
	str r7, [r0, #0x20]
	ldr r4, .L081438E8
	movs r1, #0x8e
	add r1, ip
	mov r8, r1
	ldrh r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r3, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	mov r2, ip
	str r1, [r2, #0x24]
	cmp r6, r5
	beq .L0814387E
	b .L08143992
.L0814387E:
	cmp r6, r7
	bne .L081438EC
	cmp r6, r1
	bne .L081438EC
	adds r0, r6, #0
	subs r0, #8
	cmp r0, #2
	bhi .L08143890
	b .L08143A4C
.L08143890:
	mov r1, ip
	adds r1, #0xb0
	ldr r2, .L081438DC
	ldrh r0, [r2]
	str r0, [r1]
	adds r1, #0xc
	mov r2, sl
	ldrh r0, [r2]
	str r0, [r1]
	adds r1, #0xc
	mov r2, sb
	ldrh r0, [r2]
	str r0, [r1]
	adds r1, #0xc
	mov r2, r8
	ldrh r0, [r2]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xb4
	movs r1, #0
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #4
	str r6, [r0]
	movs r0, #1
	b .L08143A42
	.byte 0x00, 0x00
.L081438D0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L081438D4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081438D8: .4byte gUnknown_0879505C
.L081438DC: .4byte 0x0203A4BE @ EWRAM+0x3A4BE
.L081438E0: .4byte gUnknown_08795DDC
.L081438E4: .4byte gUnknown_08796B5C
.L081438E8: .4byte gUnknown_087978DC
.L081438EC:
	mov r2, ip
	ldr r1, [r2, #0x18]
	ldr r0, [r2, #0x1c]
	cmp r1, r0
	bne .L08143992
	ldr r0, [r2, #0x20]
	cmp r1, r0
	bne .L08143944
	adds r0, r1, #0
	subs r0, #8
	cmp r0, #2
	bhi .L08143906
	b .L08143A4C
.L08143906:
	mov r1, ip
	adds r1, #0xb0
	mov r0, ip
	adds r0, #0x6a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x76
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xb4
	movs r1, #0
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	mov r1, ip
	adds r1, #0xd8
	movs r0, #2
	strb r0, [r1]
	adds r1, #4
	ldr r0, [r2, #0x18]
	b .L08143A3E
.L08143944:
	mov r2, ip
	ldr r0, [r2, #0x24]
	cmp r1, r0
	bne .L08143992
	adds r0, r1, #0
	subs r0, #8
	cmp r0, #2
	bls .L08143A4C
	mov r1, ip
	adds r1, #0xb0
	mov r0, ip
	adds r0, #0x6a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x76
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0x18
	mov r0, ip
	adds r0, #0x8e
	ldrh r0, [r0]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xb4
	movs r1, #0
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #0x18
	strb r1, [r0]
	mov r1, ip
	adds r1, #0xcc
	movs r0, #2
	strb r0, [r1]
	adds r1, #0x10
	ldr r0, [r2, #0x18]
	b .L08143A3E
.L08143992:
	mov r2, ip
	ldr r0, [r2, #0x18]
	ldr r2, [r2, #0x20]
	cmp r0, r2
	bne .L081439EA
	mov r1, ip
	ldr r0, [r1, #0x24]
	cmp r2, r0
	bne .L081439EA
	adds r0, r2, #0
	subs r0, #8
	cmp r0, #2
	bls .L08143A4C
	adds r1, #0xb0
	mov r0, ip
	adds r0, #0x6a
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0x18
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x8e
	ldrh r0, [r0]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xb4
	movs r1, #0
	strb r1, [r0]
	adds r0, #0x18
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	mov r1, ip
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
	adds r1, #0x1c
	mov r2, ip
	ldr r0, [r2, #0x18]
	b .L08143A3E
.L081439EA:
	mov r0, ip
	ldr r1, [r0, #0x1c]
	cmp r1, r2
	bne .L08143A54
	ldr r0, [r0, #0x24]
	cmp r1, r0
	bne .L08143A54
	adds r0, r1, #0
	subs r0, #8
	cmp r0, #2
	bls .L08143A4C
	mov r1, ip
	adds r1, #0xbc
	mov r0, ip
	adds r0, #0x76
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	str r0, [r1]
	adds r1, #0xc
	mov r0, ip
	adds r0, #0x8e
	ldrh r0, [r0]
	str r0, [r1]
	mov r0, ip
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	adds r0, #0xc
	strb r1, [r0]
	mov r1, ip
	adds r1, #0xb4
	movs r0, #2
	strb r0, [r1]
	adds r1, #0x28
	mov r2, ip
	ldr r0, [r2, #0x1c]
.L08143A3E:
	str r0, [r1]
	movs r0, #0
.L08143A42:
	bl sub_08143EA0
	bl sub_08143610
	b .L08143A5A
.L08143A4C:
	movs r0, #3
	mov r1, ip
	strb r0, [r1, #4]
	b .L08143A5A
.L08143A54:
	movs r0, #3
	mov r2, ip
	strb r0, [r2, #4]
.L08143A5A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08143A68
sub_08143A68: @ 0x08143A68
.L08143A68:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r7, .L08143AC4
	ldr r0, .L08143AC8
	mov ip, r0
	mov r1, ip
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	mov r6, ip
	adds r6, #0x30
	ldr r0, .L08143ACC
	mov sl, r0
	ldr r0, .L08143AD0
	mov r8, r0
	ldr r0, .L08143AD4
	mov sb, r0
.L08143A92:
	lsls r3, r5, #1
	mov r0, ip
	adds r0, #0x68
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, .L08143AD8
	adds r1, r1, r0
	ldr r1, [r1]
	adds r4, r3, #0
	cmp r1, #9
	beq .L08143AE8
	cmp r1, #9
	bhi .L08143ADC
	cmp r1, #8
	beq .L08143AE2
	b .L08143AF4
	.byte 0x00, 0x00
.L08143AC4: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08143AC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143ACC: .4byte gUnknown_08795DDC
.L08143AD0: .4byte gUnknown_08796B5C
.L08143AD4: .4byte gUnknown_087978DC
.L08143AD8: .4byte gUnknown_0879505C
.L08143ADC:
	cmp r1, #0xa
	beq .L08143AEE
	b .L08143AF4
.L08143AE2:
	ldrb r0, [r6]
	adds r0, #1
	b .L08143AF2
.L08143AE8:
	ldrb r0, [r6]
	adds r0, #2
	b .L08143AF2
.L08143AEE:
	ldrb r0, [r6]
	adds r0, #3
.L08143AF2:
	strb r0, [r6]
.L08143AF4:
	mov r3, ip
	adds r3, #0x30
	mov r0, ip
	adds r0, #0x74
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	add r1, sl
	ldr r1, [r1]
	cmp r1, #9
	beq .L08143B2E
	cmp r1, #9
	bhi .L08143B22
	cmp r1, #8
	beq .L08143B28
	b .L08143B3A
.L08143B22:
	cmp r1, #0xa
	beq .L08143B34
	b .L08143B3A
.L08143B28:
	ldrb r0, [r3]
	adds r0, #1
	b .L08143B38
.L08143B2E:
	ldrb r0, [r3]
	adds r0, #2
	b .L08143B38
.L08143B34:
	ldrb r0, [r3]
	adds r0, #3
.L08143B38:
	strb r0, [r3]
.L08143B3A:
	mov r0, ip
	adds r0, #0x80
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	add r1, r8
	ldr r1, [r1]
	cmp r1, #9
	beq .L08143B70
	cmp r1, #9
	bhi .L08143B64
	cmp r1, #8
	beq .L08143B6A
	b .L08143B7C
.L08143B64:
	cmp r1, #0xa
	beq .L08143B76
	b .L08143B7C
.L08143B6A:
	ldrb r0, [r3]
	adds r0, #1
	b .L08143B7A
.L08143B70:
	ldrb r0, [r3]
	adds r0, #2
	b .L08143B7A
.L08143B76:
	ldrb r0, [r3]
	adds r0, #3
.L08143B7A:
	strb r0, [r3]
.L08143B7C:
	mov r0, ip
	adds r0, #0x8c
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r7, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	add r1, sb
	ldr r1, [r1]
	cmp r1, #9
	beq .L08143BB2
	cmp r1, #9
	bhi .L08143BA6
	cmp r1, #8
	beq .L08143BAC
	b .L08143BBE
.L08143BA6:
	cmp r1, #0xa
	beq .L08143BB8
	b .L08143BBE
.L08143BAC:
	ldrb r0, [r3]
	adds r0, #1
	b .L08143BBC
.L08143BB2:
	ldrb r0, [r3]
	adds r0, #2
	b .L08143BBC
.L08143BB8:
	ldrb r0, [r3]
	adds r0, #3
.L08143BBC:
	strb r0, [r3]
.L08143BBE:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #2
	bhi .L08143BCA
	b .L08143A92
.L08143BCA:
	movs r5, #0
	mov r4, ip
	adds r4, #0xa5
	mov r1, ip
	adds r1, #0x98
	movs r2, #0
.L08143BD6:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xc
	bls .L08143BD6
	ldrb r0, [r3]
	strb r0, [r4]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08143BF8
sub_08143BF8: @ 0x08143BF8
.L08143BF8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r5, .L08143C50
	movs r0, #0xa7
	adds r0, r0, r5
	mov sb, r0
	ldrb r2, [r0]
	cmp r2, #0
	bne .L08143C6E
	adds r0, r5, #0
	adds r0, #0xa8
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bls .L08143C68
	adds r6, r5, #0
	adds r6, #0xa6
	subs r0, #0x10
	ldrb r1, [r6]
	adds r0, r0, r1
	movs r1, #1
	mov r8, r1
	mov r1, r8
	strb r1, [r0]
	strh r2, [r7]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	adds r4, r5, #0
	adds r4, #0xa5
	ldrb r0, [r4]
	cmp r0, #0
	beq .L08143C58
	ldr r0, .L08143C54
	bl sub_080C51D4
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b .L08143C68
	.byte 0x00, 0x00
.L08143C50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143C54: .4byte 0x0000016B
.L08143C58:
	ldr r0, .L08143CB0
	bl sub_080C51D4
	movs r0, #0
	strb r0, [r6]
	mov r1, r8
	mov r0, sb
	strb r1, [r0]
.L08143C68:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
.L08143C6E:
	movs r4, #0
	adds r5, #0x98
.L08143C72:
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08143C98
	ldr r0, .L08143CB4
	lsls r2, r4, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r2, #4]
	str r1, [sp, #4]
	ldrb r1, [r2, #6]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143C98:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xc
	bls .L08143C72
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08143CB0: .4byte 0x0000016B
.L08143CB4: .4byte gUnknown_087986E4

	thumb_func_start sub_08143CB8
sub_08143CB8: @ 0x08143CB8
.L08143CB8:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r2, .L08143CD4
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0xc
	bls .L08143CCA
	b .L08143E96
.L08143CCA:
	lsls r0, r0, #2
	ldr r1, .L08143CD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08143CD4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143CD8: .4byte gUnknown_08143CDC
	.global gUnknown_08143CDC
gUnknown_08143CDC:
.L08143CDC: @ jump table
	.4byte .L08143E8E
	.4byte .L08143E8E
	.4byte .L08143E8E
	.4byte .L08143D10
	.4byte .L08143E00
	.4byte .L08143E00
	.4byte .L08143E0E
	.4byte .L08143E6A
	.4byte .L08143E6A
	.4byte .L08143E7E
	.4byte .L08143E82
	.4byte .L08143E86
	.4byte .L08143E8A
.L08143D10:
	ldrh r0, [r2, #0x36]
	cmp r0, #2
	bne .L08143D5E
	adds r5, r2, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #3
	bhi .L08143D54
	adds r4, r2, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L08143D42
	ldr r0, .L08143D50
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143D42:
	ldrb r0, [r4]
	cmp r0, #0xa
	bhi .L08143D4A
	b .L08143E50
.L08143D4A:
	movs r0, #0
	strb r0, [r4]
	b .L08143DEA
.L08143D50: .4byte gUnknown_0814F314
.L08143D54:
	movs r0, #0
	strb r0, [r5]
	movs r0, #3
	strh r0, [r2, #0x36]
	b .L08143E8E
.L08143D5E:
	cmp r0, #3
	bne .L08143DAA
	adds r5, r2, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #3
	bhi .L08143DA0
	adds r4, r2, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L08143D8E
	ldr r0, .L08143D9C
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143D8E:
	ldrb r0, [r4]
	cmp r0, #0xa
	bls .L08143E50
	movs r0, #0
	strb r0, [r4]
	b .L08143DEA
	.byte 0x00, 0x00
.L08143D9C: .4byte gUnknown_0814F344
.L08143DA0:
	movs r0, #0
	strb r0, [r5]
	movs r0, #4
	strh r0, [r2, #0x36]
	b .L08143E8E
.L08143DAA:
	adds r3, r2, #0
	adds r3, #0x38
	ldrb r6, [r3]
	cmp r6, #0
	bne .L08143E8E
	cmp r0, #4
	bne .L08143E8E
	adds r5, r2, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #3
	bhi .L08143DF8
	adds r4, r2, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L08143DE2
	ldr r0, .L08143DF4
	str r6, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143DE2:
	ldrb r0, [r4]
	cmp r0, #0xa
	bls .L08143E50
	strb r6, [r4]
.L08143DEA:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b .L08143E50
	.byte 0x00, 0x00
.L08143DF4: .4byte gUnknown_0814F374
.L08143DF8:
	strb r6, [r5]
	movs r0, #5
	strh r0, [r2, #0x36]
	b .L08143E5E
.L08143E00:
	adds r0, r2, #0
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	adds r0, #9
	strb r1, [r0]
	b .L08143E96
.L08143E0E:
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r5, [r3]
	cmp r5, #0
	bne .L08143E8E
	adds r6, r2, #0
	adds r6, #0x54
	ldrb r0, [r6]
	cmp r0, #3
	bhi .L08143E5C
	adds r4, r2, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L08143E42
	ldr r0, .L08143E58
	str r5, [sp]
	movs r1, #0xb0
	str r1, [sp, #4]
	movs r1, #0x2b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143E42:
	ldrb r0, [r4]
	cmp r0, #0xa
	bls .L08143E50
	strb r5, [r4]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
.L08143E50:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L08143E96
.L08143E58: .4byte gUnknown_0814F29C
.L08143E5C:
	strb r5, [r6]
.L08143E5E:
	movs r1, #1
	strb r1, [r3]
	adds r0, r2, #0
	adds r0, #0x31
	strb r1, [r0]
	b .L08143E96
.L08143E6A:
	adds r0, r2, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08143E78
	bl sub_08144018
.L08143E78:
	bl sub_081443F0
	b .L08143E96
.L08143E7E:
	movs r0, #5
	b .L08143E8C
.L08143E82:
	movs r0, #0xa
	b .L08143E8C
.L08143E86:
	movs r0, #0x14
	b .L08143E8C
.L08143E8A:
	movs r0, #0x64
.L08143E8C:
	str r0, [r2, #0x44]
.L08143E8E:
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
.L08143E96:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08143EA0
sub_08143EA0: @ 0x08143EA0
.L08143EA0:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r4, .L08143EC8
	ldr r3, .L08143ECC
	lsrs r0, r0, #0xf
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r3, #8
	adds r0, r0, r3
	ldrh r0, [r0]
	str r0, [r4, #0x44]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08143EC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08143ECC: .4byte gUnknown_0879865C

	thumb_func_start sub_08143ED0
sub_08143ED0: @ 0x08143ED0
.L08143ED0:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L08144004
	ldrb r0, [r4, #9]
	cmp r0, #1
	bne .L08143EF4
	ldr r0, .L08144008
	movs r1, #0
	str r1, [sp]
	movs r1, #0x3a
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143EF4:
	ldrb r0, [r4, #0xa]
	cmp r0, #1
	bne .L08143F12
	ldr r0, .L0814400C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x59
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143F12:
	ldrb r0, [r4, #0xb]
	cmp r0, #1
	bne .L08143F30
	ldr r0, .L08144010
	movs r1, #0
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143F30:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bne .L08143F4E
	ldr r0, .L08144014
	movs r1, #0
	str r1, [sp]
	movs r1, #0x97
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143F4E:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne .L08143FFC
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #2
	bhi .L08143FFC
	ldrb r1, [r4, #9]
	adds r5, r4, #0
	adds r5, #0x2a
	cmp r1, #0
	bne .L08143F84
	ldrb r0, [r5]
	cmp r0, #0xa
	bls .L08143F84
	ldr r0, .L08144008
	str r1, [sp]
	movs r1, #0x3a
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143F84:
	ldrb r1, [r4, #0xa]
	cmp r1, #0
	bne .L08143FA6
	ldrb r0, [r5]
	cmp r0, #0xa
	bls .L08143FA6
	ldr r0, .L0814400C
	str r1, [sp]
	movs r1, #0x59
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143FA6:
	ldrb r1, [r4, #0xb]
	cmp r1, #0
	bne .L08143FC8
	ldrb r0, [r5]
	cmp r0, #0xa
	bls .L08143FC8
	ldr r0, .L08144010
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143FC8:
	ldrb r1, [r4, #0xc]
	cmp r1, #0
	bne .L08143FEA
	ldrb r0, [r5]
	cmp r0, #0xa
	bls .L08143FEA
	ldr r0, .L08144014
	str r1, [sp]
	movs r1, #0x97
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08143FEA:
	adds r1, r5, #0
	ldrb r0, [r1]
	cmp r0, #0x14
	bls .L08143FF6
	movs r0, #0
	strb r0, [r1]
.L08143FF6:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L08143FFC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L08144004: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144008: .4byte gUnknown_0814F1F4
.L0814400C: .4byte gUnknown_0814F204
.L08144010: .4byte gUnknown_0814F214
.L08144014: .4byte gUnknown_0814F224

	thumb_func_start sub_08144018
sub_08144018: @ 0x08144018
.L08144018:
	push {r4, lr}
	ldr r4, .L08144054
	ldr r0, .L08144058
	mov ip, r0
	mov r1, ip
	adds r1, #0x56
	movs r0, #1
	strb r0, [r1]
	ldr r3, .L0814405C
	mov r0, ip
	adds r0, #0x6a
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r0, #7
	bhi .L081440C2
	lsls r0, r0, #2
	ldr r1, .L08144060
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08144054: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08144058: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814405C: .4byte gUnknown_0879505C
.L08144060: .4byte gUnknown_08144064
	.global gUnknown_08144064
gUnknown_08144064:
.L08144064: @ jump table
	.4byte .L08144084
	.4byte .L0814408A
	.4byte .L08144090
	.4byte .L08144096
	.4byte .L0814409C
	.4byte .L081440A2
	.4byte .L081440A8
	.4byte .L081440B6
.L08144084:
	mov r1, ip
	adds r1, #0x67
	b .L081440AC
.L0814408A:
	mov r1, ip
	adds r1, #0x66
	b .L081440AC
.L08144090:
	mov r1, ip
	adds r1, #0x65
	b .L081440AC
.L08144096:
	mov r0, ip
	adds r0, #0x64
	b .L081440BA
.L0814409C:
	mov r1, ip
	adds r1, #0x63
	b .L081440AC
.L081440A2:
	mov r1, ip
	adds r1, #0x62
	b .L081440AC
.L081440A8:
	mov r1, ip
	adds r1, #0x61
.L081440AC:
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	strb r0, [r1]
	b .L081440C2
.L081440B6:
	mov r0, ip
	adds r0, #0x60
.L081440BA:
	movs r1, #1
	strb r1, [r0]
	subs r0, #8
	strb r1, [r0]
.L081440C2:
	ldr r3, .L081440EC
	mov r0, ip
	adds r0, #0x76
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r0, #7
	bhi .L08144152
	lsls r0, r0, #2
	ldr r1, .L081440F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081440EC: .4byte gUnknown_08795DDC
.L081440F0: .4byte gUnknown_081440F4
	.global gUnknown_081440F4
gUnknown_081440F4:
.L081440F4: @ jump table
	.4byte .L08144114
	.4byte .L0814411A
	.4byte .L08144120
	.4byte .L08144126
	.4byte .L0814412C
	.4byte .L08144132
	.4byte .L08144138
	.4byte .L08144146
.L08144114:
	mov r1, ip
	adds r1, #0x67
	b .L0814413C
.L0814411A:
	mov r1, ip
	adds r1, #0x66
	b .L0814413C
.L08144120:
	mov r1, ip
	adds r1, #0x65
	b .L0814413C
.L08144126:
	mov r0, ip
	adds r0, #0x64
	b .L0814414A
.L0814412C:
	mov r1, ip
	adds r1, #0x63
	b .L0814413C
.L08144132:
	mov r1, ip
	adds r1, #0x62
	b .L0814413C
.L08144138:
	mov r1, ip
	adds r1, #0x61
.L0814413C:
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	strb r0, [r1]
	b .L08144152
.L08144146:
	mov r0, ip
	adds r0, #0x60
.L0814414A:
	movs r1, #1
	strb r1, [r0]
	subs r0, #8
	strb r1, [r0]
.L08144152:
	ldr r3, .L0814417C
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r0, #7
	bhi .L081441E2
	lsls r0, r0, #2
	ldr r1, .L08144180
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0814417C: .4byte gUnknown_08796B5C
.L08144180: .4byte gUnknown_08144184
	.global gUnknown_08144184
gUnknown_08144184:
.L08144184: @ jump table
	.4byte .L081441A4
	.4byte .L081441AA
	.4byte .L081441B0
	.4byte .L081441B6
	.4byte .L081441BC
	.4byte .L081441C2
	.4byte .L081441C8
	.4byte .L081441D6
.L081441A4:
	mov r1, ip
	adds r1, #0x67
	b .L081441CC
.L081441AA:
	mov r1, ip
	adds r1, #0x66
	b .L081441CC
.L081441B0:
	mov r1, ip
	adds r1, #0x65
	b .L081441CC
.L081441B6:
	mov r0, ip
	adds r0, #0x64
	b .L081441DA
.L081441BC:
	mov r1, ip
	adds r1, #0x63
	b .L081441CC
.L081441C2:
	mov r1, ip
	adds r1, #0x62
	b .L081441CC
.L081441C8:
	mov r1, ip
	adds r1, #0x61
.L081441CC:
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	strb r0, [r1]
	b .L081441E2
.L081441D6:
	mov r0, ip
	adds r0, #0x60
.L081441DA:
	movs r1, #1
	strb r1, [r0]
	subs r0, #8
	strb r1, [r0]
.L081441E2:
	ldr r3, .L0814420C
	mov r0, ip
	adds r0, #0x8e
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldrh r2, [r4, #2]
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	cmp r0, #7
	bhi .L0814426A
	lsls r0, r0, #2
	ldr r1, .L08144210
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0814420C: .4byte gUnknown_087978DC
.L08144210: .4byte gUnknown_08144214
	.global gUnknown_08144214
gUnknown_08144214:
.L08144214: @ jump table
	.4byte .L08144234
	.4byte .L0814423A
	.4byte .L08144240
	.4byte .L08144246
	.4byte .L0814424C
	.4byte .L08144252
	.4byte .L08144258
	.4byte .L0814425E
.L08144234:
	mov r0, ip
	adds r0, #0x67
	b .L08144262
.L0814423A:
	mov r0, ip
	adds r0, #0x66
	b .L08144262
.L08144240:
	mov r0, ip
	adds r0, #0x65
	b .L08144262
.L08144246:
	mov r0, ip
	adds r0, #0x64
	b .L08144262
.L0814424C:
	mov r0, ip
	adds r0, #0x63
	b .L08144262
.L08144252:
	mov r0, ip
	adds r0, #0x62
	b .L08144262
.L08144258:
	mov r0, ip
	adds r0, #0x61
	b .L08144262
.L0814425E:
	mov r0, ip
	adds r0, #0x60
.L08144262:
	movs r1, #1
	strb r1, [r0]
	subs r0, #8
	strb r1, [r0]
.L0814426A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08144270
sub_08144270: @ 0x08144270
.L08144270:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L081443CC
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081442A0
	adds r0, r4, #0
	adds r0, #0x58
	ldrb r1, [r0]
	cmp r1, #0
	bne .L081442A0
	ldr r0, .L081443D0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081442A0:
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081442CA
	adds r0, r4, #0
	adds r0, #0x59
	ldrb r1, [r0]
	cmp r1, #0
	bne .L081442CA
	ldr r0, .L081443D4
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081442CA:
	adds r0, r4, #0
	adds r0, #0x62
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081442F4
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r1, [r0]
	cmp r1, #0
	bne .L081442F4
	ldr r0, .L081443D8
	str r1, [sp]
	movs r1, #0x72
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081442F4:
	adds r0, r4, #0
	adds r0, #0x63
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814431E
	adds r0, r4, #0
	adds r0, #0x5b
	ldrb r1, [r0]
	cmp r1, #0
	bne .L0814431E
	ldr r0, .L081443DC
	str r1, [sp]
	movs r1, #0x88
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814431E:
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08144348
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	cmp r1, #0
	bne .L08144348
	ldr r0, .L081443E0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144348:
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08144372
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	cmp r1, #0
	bne .L08144372
	ldr r0, .L081443E4
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144372:
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814439A
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r1, [r0]
	cmp r1, #0
	bne .L0814439A
	ldr r0, .L081443E8
	str r1, [sp]
	movs r1, #0x72
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814439A:
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081443C4
	adds r0, r4, #0
	adds r0, #0x5f
	ldrb r1, [r0]
	cmp r1, #0
	bne .L081443C4
	ldr r0, .L081443EC
	str r1, [sp]
	movs r1, #0x88
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081443C4:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L081443CC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081443D0: .4byte gUnknown_0814F10C
.L081443D4: .4byte gUnknown_0814F124
.L081443D8: .4byte gUnknown_0814F13C
.L081443DC: .4byte gUnknown_0814F154
.L081443E0: .4byte gUnknown_0814F16C
.L081443E4: .4byte gUnknown_0814F184
.L081443E8: .4byte gUnknown_0814F19C
.L081443EC: .4byte gUnknown_0814F1B4

	thumb_func_start sub_081443F0
sub_081443F0: @ 0x081443F0
.L081443F0:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L08144560
	adds r5, r4, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #3
	bls .L08144402
	b .L08144584
.L08144402:
	adds r0, r4, #0
	adds r0, #0x58
	ldrb r0, [r0]
	adds r5, #1
	cmp r0, #1
	bne .L0814442C
	ldrb r0, [r5]
	cmp r0, #7
	bls .L0814442C
	ldr r0, .L08144564
	movs r1, #0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814442C:
	adds r0, r4, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08144454
	ldrb r0, [r5]
	cmp r0, #7
	bls .L08144454
	ldr r0, .L08144568
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144454:
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814447C
	ldrb r0, [r5]
	cmp r0, #7
	bls .L0814447C
	ldr r0, .L0814456C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x72
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814447C:
	adds r0, r4, #0
	adds r0, #0x5b
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081444A4
	ldrb r0, [r5]
	cmp r0, #7
	bls .L081444A4
	ldr r0, .L08144570
	movs r1, #0
	str r1, [sp]
	movs r1, #0x88
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081444A4:
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081444CC
	ldrb r0, [r5]
	cmp r0, #7
	bls .L081444CC
	ldr r0, .L08144574
	movs r1, #0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081444CC:
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081444F4
	ldrb r0, [r5]
	cmp r0, #7
	bls .L081444F4
	ldr r0, .L08144578
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081444F4:
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814451A
	ldrb r0, [r5]
	cmp r0, #7
	bls .L0814451A
	ldr r0, .L0814457C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x72
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814451A:
	adds r0, r4, #0
	adds r0, #0x5f
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08144542
	ldrb r0, [r5]
	cmp r0, #7
	bls .L08144542
	ldr r0, .L08144580
	movs r1, #0
	str r1, [sp]
	movs r1, #0x88
	str r1, [sp, #4]
	movs r1, #0x72
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144542:
	adds r1, r5, #0
	ldrb r0, [r1]
	cmp r0, #0xa
	bls .L08144558
	movs r0, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08144558:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b .L081445B8
.L08144560: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144564: .4byte gUnknown_0814F10C
.L08144568: .4byte gUnknown_0814F124
.L0814456C: .4byte gUnknown_0814F13C
.L08144570: .4byte gUnknown_0814F154
.L08144574: .4byte gUnknown_0814F16C
.L08144578: .4byte gUnknown_0814F184
.L0814457C: .4byte gUnknown_0814F19C
.L08144580: .4byte gUnknown_0814F1B4
.L08144584:
	ldr r0, .L081445C0
	bl sub_080C51D4
	adds r0, r4, #0
	adds r0, #0x5f
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	strb r1, [r5]
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
.L081445B8:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L081445C0: .4byte 0x0000015D

	thumb_func_start sub_081445C4
sub_081445C4: @ 0x081445C4
.L081445C4:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, .L08144604
	adds r3, r4, #0
	adds r3, #0x39
	ldrb r0, [r3]
	cmp r0, #1
	beq .L081445D6
	b .L0814476A
.L081445D6:
	adds r2, r4, #0
	adds r2, #0x54
	ldrb r0, [r2]
	adds r6, r2, #0
	cmp r0, #3
	bls .L081445E4
	b .L08144758
.L081445E4:
	adds r0, r4, #0
	adds r0, #0x55
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #7
	bhi .L081445F2
	b .L08144738
.L081445F2:
	adds r0, #0x87
	ldr r0, [r0]
	cmp r0, #7
	bhi .L081446D0
	lsls r0, r0, #2
	ldr r1, .L08144608
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08144604: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144608: .4byte gUnknown_0814460C
	.global gUnknown_0814460C
gUnknown_0814460C:
.L0814460C: @ jump table
	.4byte .L0814462C
	.4byte .L08144640
	.4byte .L08144650
	.4byte .L08144664
	.4byte .L08144678
	.4byte .L08144688
	.4byte .L08144698
	.4byte .L081446B8
.L0814462C:
	ldr r0, .L0814463C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x88
	str r1, [sp, #4]
	movs r1, #0x72
	b .L081446A4
	.byte 0x00, 0x00
.L0814463C: .4byte gUnknown_0814F1B4
.L08144640:
	ldr r0, .L0814464C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x72
	str r1, [sp, #4]
	b .L081446A4
.L0814464C: .4byte gUnknown_0814F19C
.L08144650:
	ldr r0, .L08144660
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x72
	b .L081446A4
	.byte 0x00, 0x00
.L08144660: .4byte gUnknown_0814F184
.L08144664:
	ldr r0, .L08144674
	movs r1, #0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x72
	b .L081446A4
	.byte 0x00, 0x00
.L08144674: .4byte gUnknown_0814F16C
.L08144678:
	ldr r0, .L08144684
	movs r1, #0
	str r1, [sp]
	movs r1, #0x88
	b .L081446A0
	.byte 0x00, 0x00
.L08144684: .4byte gUnknown_0814F154
.L08144688:
	ldr r0, .L08144694
	movs r1, #0
	str r1, [sp]
	movs r1, #0x72
	b .L081446A0
	.byte 0x00, 0x00
.L08144694: .4byte gUnknown_0814F13C
.L08144698:
	ldr r0, .L081446B4
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5b
.L081446A0:
	str r1, [sp, #4]
	movs r1, #0x65
.L081446A4:
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L081446D0
	.byte 0x00, 0x00
.L081446B4: .4byte gUnknown_0814F124
.L081446B8:
	ldr r0, .L081446E0
	movs r1, #0
	str r1, [sp]
	movs r1, #0x45
	str r1, [sp, #4]
	movs r1, #0x65
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081446D0:
	ldrh r0, [r4, #0x36]
	cmp r0, #3
	beq .L081446F8
	cmp r0, #3
	bgt .L081446E4
	cmp r0, #2
	beq .L081446EE
	b .L08144738
.L081446E0: .4byte gUnknown_0814F10C
.L081446E4:
	cmp r0, #4
	beq .L08144700
	cmp r0, #5
	beq .L08144720
	b .L08144738
.L081446EE:
	ldr r0, .L081446F4
	b .L08144702
	.byte 0x00, 0x00
.L081446F4: .4byte gUnknown_0814F2E4
.L081446F8:
	ldr r0, .L081446FC
	b .L08144702
.L081446FC: .4byte gUnknown_0814F314
.L08144700:
	ldr r0, .L0814471C
.L08144702:
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08144738
	.byte 0x00, 0x00
.L0814471C: .4byte gUnknown_0814F344
.L08144720:
	ldr r0, .L08144754
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0x6c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144738:
	adds r1, r5, #0
	ldrb r0, [r1]
	cmp r0, #0xa
	bls .L0814474A
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
.L0814474A:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b .L0814476A
	.byte 0x00, 0x00
.L08144754: .4byte gUnknown_0814F374
.L08144758:
	ldrh r1, [r4, #0x36]
	ldr r0, [r4, #0x44]
	muls r0, r1, r0
	str r0, [r4, #0x44]
	movs r1, #0
	movs r0, #2
	strh r0, [r4, #0x36]
	strb r1, [r3]
	strb r1, [r2]
.L0814476A:
	adds r2, r4, #0
	adds r2, #0x33
	ldrb r0, [r2]
	cmp r0, #1
	bne .L081447CE
	adds r5, r4, #0
	adds r5, #0x54
	ldrb r0, [r5]
	cmp r0, #3
	bhi .L081447BC
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #7
	bls .L0814479E
	ldr r0, .L081447B8
	movs r1, #0
	str r1, [sp]
	movs r1, #0xb0
	str r1, [sp, #4]
	movs r1, #0x2b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814479E:
	ldrb r0, [r4]
	cmp r0, #0xa
	bls .L081447AE
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L081447AE:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L081447CE
	.byte 0x00, 0x00
.L081447B8: .4byte gUnknown_0814F29C
.L081447BC:
	movs r1, #0
	strb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x32
	strb r1, [r0]
	ldr r0, [r4, #0x44]
	lsls r0, r0, #1
	str r0, [r4, #0x44]
	strb r1, [r5]
.L081447CE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081447D8
sub_081447D8: @ 0x081447D8
	ldr r0, .L081447E0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L081447E0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081447E4
sub_081447E4: @ 0x081447E4
.L081447E4:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r3, .L08144860
	ldr r1, .L08144864
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #0xec
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08144858
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne .L0814482A
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r0, r3, r7
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08144836
.L0814482A:
	ldrh r6, [r2]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r0, r1, r0
	ldrh r5, [r0]
.L08144836:
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #0xec
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08144858:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08144860: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144864: .4byte gUnknown_0879A264

	thumb_func_start sub_08144868
sub_08144868: @ 0x08144868
.L08144868:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, .L081448A4
	mov ip, r2
	lsrs r2, r0, #0xf
	mov r0, ip
	adds r0, #0xec
	adds r0, r2, r0
	strh r1, [r0]
	cmp r4, #0
	beq .L08144890
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, ip
	adds r0, r2, r0
	strh r4, [r0]
.L08144890:
	cmp r3, #0
	beq .L0814489E
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, ip
	adds r0, r2, r0
	strh r3, [r0]
.L0814489E:
	pop {r4}
	pop {r0}
	bx r0
.L081448A4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081448A8
sub_081448A8: @ 0x081448A8
.L081448A8:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r4, .L081448D4
	mov ip, r4
	lsrs r0, r0, #0xf
	adds r4, #0xec
	adds r4, r0, r4
	strh r1, [r4]
	movs r1, #0x8a
	lsls r1, r1, #1
	add r1, ip
	adds r1, r0, r1
	strh r2, [r1]
	movs r1, #0x9e
	lsls r1, r1, #1
	add r1, ip
	adds r0, r0, r1
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081448D4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081448D8
sub_081448D8: @ 0x081448D8
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_08144868
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081448FC
sub_081448FC: @ 0x081448FC
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_081448A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08144920
sub_08144920: @ 0x08144920
.L08144920:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	bl NumberToDigits
	mov r8, r0
	subs r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0
	cmp r5, r7
	bhs .L08144982
	ldr r0, .L08144994
	mov sl, r0
.L08144950:
	mov r1, r8
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r6, #5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #1
	cmp r5, r7
	blo .L08144950
.L08144982:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08144994: .4byte gUnknown_0879A29C

	thumb_func_start sub_08144998
sub_08144998: @ 0x08144998
.L08144998:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, .L081449F8
	adds r0, r6, #0
	adds r0, #0x98
	ldr r2, [r0]
	cmp r2, #0
	beq .L081449EE
	subs r0, #2
	ldrh r0, [r0]
	cmp r0, #0
	beq .L081449BE
	ldr r0, .L081449FC
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081449EE
.L081449BE:
	movs r5, #0
	cmp r5, r2
	bhs .L081449EE
	ldr r4, .L08144A00
	ldr r7, .L08144A04
.L081449C8:
	ldm r7!, {r0}
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4]
	str r1, [sp, #4]
	ldrh r1, [r4, #2]
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r4, #4
	adds r5, #1
	adds r0, r6, #0
	adds r0, #0x98
	ldr r0, [r0]
	cmp r5, r0
	blo .L081449C8
.L081449EE:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081449F8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081449FC: .4byte 0x030031BC @ IWRAM+0x31BC
.L08144A00: .4byte gUnknown_0879A2C4
.L08144A04: .4byte gUnknown_0879A2E4

	thumb_func_start sub_08144A08
sub_08144A08: @ 0x08144A08
.L08144A08:
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	ldr r0, .L08144A4C
	ldr r5, .L08144A50
	ldrh r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L08144A54
	adds r0, r0, r1
	lsrs r4, r4, #0xe
	adds r1, r5, #0
	adds r1, #0x70
	adds r1, r4, r1
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1]
	bl sub_080C2244
	adds r5, #4
	adds r4, r4, r5
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	lsrs r1, r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x12
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08144A4C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08144A50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144A54: .4byte gUnknown_0879C6A4

	thumb_func_start sub_08144A58
sub_08144A58: @ 0x08144A58
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, .L08144B50
	movs r4, #0
	str r4, [sp]
	ldr r2, .L08144B54
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldr r1, .L08144B58
	ldr r2, .L08144B5C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L08144B60
	strh r4, [r0]
	ldr r0, .L08144B64
	strh r4, [r0]
	str r4, [sp, #4]
	adds r1, #0xcc
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L08144B68
	str r0, [r1, #4]
	ldr r0, .L08144B6C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	strh r0, [r5]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #2
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #5
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #6
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #7
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #8
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #0xa
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #0xd
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	movs r0, #9
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08144B3A:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08144A08
	adds r4, #1
	cmp r4, #8
	bls .L08144B3A
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L08144B50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144B54: .4byte 0x05000200 @ PLTT+0x200
.L08144B58: .4byte 0x04000008 @ REG_BG0CNT
.L08144B5C: .4byte 0x00004008
.L08144B60: .4byte 0x03000002 @ IWRAM+0x2
.L08144B64: .4byte 0x03000040 @ IWRAM+0x40
.L08144B68: .4byte 0x02005004 @ EWRAM+0x5004
.L08144B6C: .4byte 0x85000800

	thumb_func_start sub_08144B70
sub_08144B70: @ 0x08144B70
.L08144B70:
	push {r4, lr}
	ldr r4, .L08144BFC
	movs r0, #6
	ldrsh r1, [r4, r0]
	ldr r2, [r4, #0x70]
	movs r0, #0
	bl sub_08144FF0
	movs r0, #0xa
	ldrsh r1, [r4, r0]
	ldr r2, [r4, #0x74]
	movs r0, #1
	bl sub_08144FF0
	movs r0, #0xe
	ldrsh r1, [r4, r0]
	ldr r2, [r4, #0x78]
	movs r0, #2
	bl sub_08144FF0
	movs r0, #0x12
	ldrsh r1, [r4, r0]
	ldr r2, [r4, #0x7c]
	movs r0, #3
	bl sub_08144FF0
	movs r0, #0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0x80
	ldr r2, [r0]
	movs r0, #4
	bl sub_08144FF0
	movs r0, #0x1a
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r2, [r0]
	movs r0, #5
	bl sub_08144FF0
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0x88
	ldr r2, [r0]
	movs r0, #6
	bl sub_08144FF0
	movs r0, #0x22
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r2, [r0]
	movs r0, #7
	bl sub_08144FF0
	movs r0, #0x26
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0x90
	ldr r2, [r0]
	movs r0, #8
	bl sub_08144FF0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08144BFC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08144C00
sub_08144C00: @ 0x08144C00
	push {lr}
	bl sub_08144B70
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08144C0C
sub_08144C0C: @ 0x08144C0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r5, .L08144C30
	ldrh r0, [r5]
	cmp r0, #1
	beq .L08144C34
	movs r1, #0xec
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #1
	bgt .L08144C2A
	b .L08144E1E
.L08144C2A:
	cmp r0, #2
	beq .L08144C50
	b .L08144E1E
.L08144C30: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08144C34:
	ldr r0, .L08144C48
	ldr r1, .L08144C4C
	bl Task_Create
	movs r0, #0
	strh r0, [r5]
	movs r0, #0xec
	adds r0, r0, r5
	mov r8, r0
	b .L08144E1E
.L08144C48: .4byte gUnknown_0879A304
.L08144C4C: .4byte 0x0000FFFF
.L08144C50:
	ldr r2, .L08144CA4
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08144CAC
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r3, [r0]
	cmp r3, #0
	bne .L08144CAC
	movs r2, #1
	ldr r0, .L08144CA8
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08144C76
	movs r2, #8
.L08144C76:
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	cmp r0, #8
	beq .L08144C92
	adds r0, r0, r2
	str r0, [r1]
	cmp r0, #8
	bls .L08144C8C
	movs r0, #8
	str r0, [r1]
.L08144C8C:
	adds r0, r5, #0
	adds r0, #0x96
	strh r3, [r0]
.L08144C92:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r1, #0xec
	adds r1, r1, r5
	mov r8, r1
	b .L08144D90
	.byte 0x00, 0x00
.L08144CA4: .4byte 0x03003964 @ IWRAM+0x3964
.L08144CA8: .4byte 0x030031D0 @ IWRAM+0x31D0
.L08144CAC:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08144CDE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r2, [r0]
	cmp r2, #0
	bne .L08144CDE
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	cmp r0, #0
	beq .L08144CD4
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x96
	strh r2, [r0]
.L08144CD4:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L08144D64
.L08144CDE:
	ldr r2, .L08144D3C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08144D6C
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r6, [r0]
	cmp r6, #0
	bne .L08144D40
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	movs r1, #0xec
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq .L08144D90
	bl sub_080C31F0
	ldr r1, [r4]
	cmp r0, r1
	blo .L08144D90
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	bl sub_081457FC
	adds r0, r5, #0
	adds r0, #0xa4
	strh r6, [r0]
	subs r0, #0xe
	strh r6, [r0]
	ldr r0, [r4]
	rsbs r0, r0, #0
	bl sub_080C31B4
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	b .L08144D90
.L08144D3C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08144D40:
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	bl sub_081457FC
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	strh r1, [r0]
	subs r0, #0xe
	strh r1, [r0]
	movs r0, #3
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08144D64:
	movs r0, #0xec
	adds r0, r0, r5
	mov r8, r0
	b .L08144D90
.L08144D6C:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	movs r1, #0xec
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq .L08144D90
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08144D90
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	bl sub_08145260
.L08144D90:
	ldrh r0, [r5]
	cmp r0, #2
	bne .L08144E1E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08144DE0
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	cmp r0, #0
	beq .L08144DDA
	bl sub_080C31F0
	ldr r1, [r4]
	cmp r0, r1
	blo .L08144DDA
	adds r0, r5, #0
	adds r0, #0xee
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08144DDA
	ldr r0, .L08144DD0
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08144DD4
	movs r0, #3
	b .L08144E08
.L08144DD0: .4byte 0x030031BC @ IWRAM+0x31BC
.L08144DD4:
	movs r0, #3
	movs r1, #2
	b .L08144E08
.L08144DDA:
	movs r0, #3
	movs r1, #1
	b .L08144E08
.L08144DE0:
	adds r0, r5, #0
	adds r0, #0xee
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08144E12
	ldr r0, .L08144E00
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08144E04
	movs r0, #3
	movs r1, #3
	b .L08144E08
	.byte 0x00, 0x00
.L08144E00: .4byte 0x030031BC @ IWRAM+0x31BC
.L08144E04:
	movs r0, #3
	movs r1, #4
.L08144E08:
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	b .L08144E1E
.L08144E12:
	movs r0, #3
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08144E1E:
	ldrh r0, [r5]
	cmp r0, #1
	bls .L08144E2C
	cmp r0, #3
	beq .L08144E2C
	bl sub_08144B70
.L08144E2C:
	movs r6, #0
	movs r0, #0xa0
	adds r0, r0, r5
	mov sb, r0
	ldr r4, .L08144E8C
	ldr r7, .L08144E90
.L08144E38:
	ldm r7!, {r0}
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4]
	str r1, [sp, #4]
	ldrh r1, [r4, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
	adds r4, #8
	adds r6, #1
	cmp r6, #8
	bls .L08144E38
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	beq .L08144EA4
	movs r0, #2
	movs r1, #8
	movs r2, #6
	bl sub_081447E4
	ldrh r0, [r5]
	cmp r0, #3
	bne .L08144EA4
	ldr r0, .L08144E94
	ldr r0, [r0]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08144E98
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	b .L08144EA4
	.byte 0x00, 0x00
.L08144E8C: .4byte gUnknown_0879A190
.L08144E90: .4byte gUnknown_0879A16C
.L08144E94: .4byte 0x030031BC @ IWRAM+0x31BC
.L08144E98:
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08144EA4:
	ldr r0, .L08144EC8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L08144EF0
	adds r0, r5, #0
	adds r0, #0x98
	ldr r3, [r0]
	cmp r3, #0
	beq .L08144ED8
	mov r1, r8
	ldrh r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	bne .L08144ECC
	movs r0, #4
	b .L08144ED2
.L08144EC8: .4byte 0x030031BC @ IWRAM+0x31BC
.L08144ECC:
	cmp r1, #1
	beq .L08144EF0
	subs r0, #1
.L08144ED2:
	mov r1, r8
	strh r0, [r1]
	b .L08144EF0
.L08144ED8:
	mov r2, r8
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq .L08144EF0
	cmp r1, #4
	beq .L08144EEC
	adds r0, #1
	strh r0, [r2]
	b .L08144EF0
.L08144EEC:
	mov r0, r8
	strh r3, [r0]
.L08144EF0:
	movs r0, #0
	movs r1, #7
	movs r2, #4
	bl sub_081447E4
	movs r0, #3
	movs r1, #0xba
	movs r2, #6
	bl sub_081447E4
	movs r0, #1
	movs r1, #0xbb
	movs r2, #4
	bl sub_081447E4
	movs r0, #5
	movs r1, #7
	movs r2, #0x29
	bl sub_081447E4
	movs r0, #6
	movs r1, #7
	movs r2, #0x36
	bl sub_081447E4
	movs r0, #7
	movs r1, #7
	movs r2, #0x43
	bl sub_081447E4
	movs r0, #8
	movs r1, #7
	movs r2, #0x50
	bl sub_081447E4
	movs r0, #4
	movs r1, #7
	movs r2, #0x5d
	bl sub_081447E4
	movs r0, #0xa
	movs r1, #6
	movs r2, #0x87
	bl sub_081447E4
	movs r0, #0xb
	movs r1, #6
	movs r2, #0x93
	bl sub_081447E4
	movs r0, #0xc
	movs r1, #0x87
	movs r2, #0x7b
	bl sub_081447E4
	movs r0, #0xd
	movs r1, #0x87
	movs r2, #0x87
	bl sub_081447E4
	movs r0, #9
	movs r1, #0x87
	movs r2, #0x93
	bl sub_081447E4
	mov r1, sb
	ldr r0, [r1]
	movs r1, #6
	movs r2, #0xe
	movs r3, #0x1d
	bl sub_08144920
	bl sub_080C31F0
	movs r1, #6
	movs r2, #0xc4
	movs r3, #0x1d
	bl sub_08144920
	bl sub_08144998
	bl sub_08145194
	bl sub_081451FC
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08144FA8
sub_08144FA8: @ 0x08144FA8
	ldr r0, .L08144FB0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L08144FB0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08144FB4
sub_08144FB4: @ 0x08144FB4
	ldr r1, .L08144FC8
	ldr r0, .L08144FCC
	str r0, [r1]
	ldr r0, .L08144FD0
	str r0, [r1, #4]
	ldr r0, .L08144FD4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08144FC8: .4byte 0x040000D4 @ REG_DMA3SAD
.L08144FCC: .4byte 0x02005004 @ EWRAM+0x5004
.L08144FD0: .4byte 0x06016000 @ VRAM+0x16000
.L08144FD4: .4byte 0x84000800

	thumb_func_start sub_08144FD8
sub_08144FD8: @ 0x08144FD8
.L08144FD8:
	push {lr}
	adds r2, r0, #0
	movs r3, #0
.L08144FDE:
	ldr r0, [r2]
	str r0, [r1]
	adds r2, #0x20
	adds r1, #0x20
	adds r3, #1
	cmp r3, #3
	bls .L08144FDE
	pop {r0}
	bx r0

	thumb_func_start sub_08144FF0
sub_08144FF0: @ 0x08144FF0
.L08144FF0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L081450B0
	lsls r2, r3, #1
	adds r0, #0x4c
	adds r2, r2, r0
	ldrh r2, [r2]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xa
	mov sl, r0
	lsls r1, r1, #0x10
	ldr r0, .L081450B4
	adds r1, r1, r0
	lsrs r2, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	bge .L0814502C
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L0814502C:
	movs r6, #0
	lsls r2, r2, #0x10
	mov sb, r2
	lsls r1, r3, #2
	ldr r7, .L081450B8
	ldr r0, .L081450BC
	adds r1, r1, r0
	mov r8, r1
	str r7, [sp, #4]
.L0814503E:
	mov r3, sb
	asrs r0, r3, #0x10
	adds r5, r0, r6
	ldr r0, .L081450C0
	cmp r5, r0
	bls .L0814504E
	ldr r0, .L081450C4
	adds r5, r5, r0
.L0814504E:
	adds r0, r5, #0
	movs r1, #0x14
	bl __udivsi3
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r0, r1, r0
	ldr r1, .L081450C8
	ldrh r4, [r0]
	lsls r4, r4, #2
	adds r4, r4, r1
	adds r0, r5, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r4]
	ldr r0, [r0]
	adds r2, r2, r0
	add r2, sl
	ldr r0, .L081450CC
	adds r2, r2, r0
	mov r3, r8
	ldr r1, [r3]
	ldr r3, [sp, #4]
	ldm r3!, {r0}
	str r3, [sp, #4]
	adds r1, r1, r0
	ldr r0, .L081450D0
	adds r1, r1, r0
	adds r0, r2, #0
	bl sub_08144FD8
	adds r6, #1
	cmp r6, #0x18
	bls .L0814503E
	ldr r0, .L081450D4
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081450B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081450B4: .4byte 0xFFFE0000
.L081450B8: .4byte gUnknown_0879A56C
.L081450BC: .4byte gUnknown_0879A548
.L081450C0: .4byte 0x000001DF
.L081450C4: .4byte 0xFFFFFE20
.L081450C8: .4byte gUnknown_0879A52C
.L081450CC: .4byte gUnknown_0879896C
.L081450D0: .4byte 0x02005004 @ EWRAM+0x5004
.L081450D4: .4byte sub_08144FB4

	thumb_func_start sub_081450D8
sub_081450D8: @ 0x081450D8
.L081450D8:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r2, .L081450F8
	lsrs r0, r0, #0xe
	adds r0, #4
	adds r3, r0, r2
	ldr r0, [r3]
	adds r2, r0, r1
	str r2, [r3]
	asrs r1, r2, #0x10
	cmp r1, #0
	bge .L081450FC
	movs r4, #0xf0
	lsls r4, r4, #1
	adds r0, r1, r4
	b .L0814510A
.L081450F8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081450FC:
	ldr r0, .L0814511C
	cmp r1, r0
	ble .L08145114
	movs r4, #0xf0
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
.L0814510A:
	ldr r1, .L08145120
	ands r2, r1
	lsls r0, r0, #0x10
	orrs r2, r0
	str r2, [r3]
.L08145114:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814511C: .4byte 0x000001DF
.L08145120: .4byte 0x0000FFFF

	thumb_func_start sub_08145124
sub_08145124: @ 0x08145124
.L08145124:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r3, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, .L0814518C
	adds r0, #0x98
	ldr r0, [r0]
	muls r0, r6, r0
	lsls r0, r0, #2
	adds r7, r7, r0
	movs r4, #0
	cmp r4, r6
	bhs .L0814517E
	ldr r0, .L08145190
	mov sb, r0
.L08145154:
	ldm r7!, {r0}
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r5, #0
	adds r0, #0x17
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, #1
	cmp r4, r6
	blo .L08145154
.L0814517E:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814518C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145190: .4byte gUnknown_0879A928

	thumb_func_start sub_08145194
sub_08145194: @ 0x08145194
.L08145194:
	push {lr}
	ldr r3, .L081451E4
	movs r0, #0x38
	movs r1, #0x78
	movs r2, #1
	bl sub_08145124
	ldr r3, .L081451E8
	movs r0, #0xb
	movs r1, #0x8b
	movs r2, #5
	bl sub_08145124
	ldr r3, .L081451EC
	movs r0, #0xb
	movs r1, #0x97
	movs r2, #5
	bl sub_08145124
	ldr r3, .L081451F0
	movs r0, #0x8c
	movs r1, #0x7f
	movs r2, #4
	bl sub_08145124
	ldr r3, .L081451F4
	movs r0, #0x8c
	movs r1, #0x8b
	movs r2, #4
	bl sub_08145124
	ldr r3, .L081451F8
	movs r0, #0x8c
	movs r1, #0x97
	movs r2, #4
	bl sub_08145124
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081451E4: .4byte gUnknown_0879A5EC
.L081451E8: .4byte gUnknown_0879A610
.L081451EC: .4byte gUnknown_0879A6C4
.L081451F0: .4byte gUnknown_0879A778
.L081451F4: .4byte gUnknown_0879A808
.L081451F8: .4byte gUnknown_0879A898

	thumb_func_start sub_081451FC
sub_081451FC: @ 0x081451FC
.L081451FC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r5, .L08145258
	movs r0, #0xb4
	mov r8, r0
	movs r6, #0x61
	adds r1, r5, #0
	adds r1, #0xa4
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0814524A
	movs r4, #0
	ldrh r1, [r1]
	cmp r4, r1
	bhs .L0814524A
	ldr r7, .L0814525C
.L08145220:
	ldm r7!, {r0}
	movs r1, #0
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r6, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r0, r6, #0
	subs r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #1
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	cmp r4, r0
	blo .L08145220
.L0814524A:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145258: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814525C: .4byte gUnknown_0879AA24

	thumb_func_start sub_08145260
sub_08145260: @ 0x08145260
.L08145260:
	push {r4, lr}
	ldr r4, .L08145278
	ldr r0, .L0814527C
	ldr r1, .L08145280
	bl Task_Create
	movs r0, #3
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145278: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814527C: .4byte gUnknown_0879AA3C
.L08145280: .4byte 0x0000FFFF

	thumb_func_start sub_08145284
sub_08145284: @ 0x08145284
	push {lr}
	ldrh r0, [r0, #0x24]
	bl sub_081450D8
	pop {r0}
	bx r0

	thumb_func_start sub_08145290
sub_08145290: @ 0x08145290
.L08145290:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r2, .L081452B8
	lsrs r0, r0, #0xe
	adds r1, r2, #0
	adds r1, #0x70
	adds r1, r0, r1
	ldr r4, [r1]
	adds r2, r2, r0
	ldrh r0, [r2, #6]
	movs r1, #0x14
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081452B8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081452BC
sub_081452BC: @ 0x081452BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L0814532C
	bl sub_080C2244
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	lsrs r4, r1, #8
	ldrh r0, [r5, #0x24]
	lsls r1, r0, #2
	adds r2, r7, #0
	adds r2, #0x70
	adds r1, r1, r2
	ldr r6, [r1]
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L08145330
	cmp r6, r0
	bne .L081452F8
	ldrh r0, [r5, #0x24]
	bl sub_08144A08
	ldrh r0, [r5, #0x24]
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L081452F8:
	lsls r0, r4, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r5, #0x24]
	adds r2, r7, #4
	cmp r0, r3
	bne .L08145318
.L08145306:
	adds r4, #1
	cmp r4, #0x18
	bne .L0814530E
	movs r4, #0
.L0814530E:
	lsls r0, r4, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, r3
	beq .L08145306
.L08145318:
	lsls r1, r1, #2
	adds r1, r2, r1
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #0x12
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814532C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145330: .4byte gUnknown_0879C7C4

	thumb_func_start sub_08145334
sub_08145334: @ 0x08145334
	ldr r1, .L08145344
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r1, #0x28
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr
.L08145344: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145348
sub_08145348: @ 0x08145348
	push {lr}
	ldr r3, .L08145370
	ldrh r2, [r0, #0x24]
	movs r1, #0x26
	ldrsh r0, [r0, r1]
	cmp r0, #5
	bne .L0814536C
	lsls r2, r2, #2
	adds r0, r3, #4
	adds r0, r2, r0
	movs r1, #0xa0
	lsls r1, r1, #0xe
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x70
	adds r2, r2, r0
	ldr r0, .L08145374
	str r0, [r2]
.L0814536C:
	pop {r0}
	bx r0
.L08145370: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145374: .4byte gUnknown_0879C7C4

	thumb_func_start sub_08145378
sub_08145378: @ 0x08145378
.L08145378:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, .L081453A4
	ldr r0, .L081453A8
	ldr r1, .L081453AC
	bl Task_Create
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	lsls r4, r4, #2
	adds r6, #0x28
	adds r4, r4, r6
	str r0, [r4]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081453A4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081453A8: .4byte gUnknown_0879AA94
.L081453AC: .4byte 0x0000FFFF

	thumb_func_start sub_081453B0
sub_081453B0: @ 0x081453B0
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r1, .L081453E0
	movs r0, #0
	strh r0, [r4, #0x1c]
	lsls r0, r2, #1
	adds r1, #0x5e
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L081453D8
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_08145378
	movs r0, #1
	strh r0, [r4, #0x1c]
.L081453D8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081453E0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081453E4
sub_081453E4: @ 0x081453E4
.L081453E4:
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r4, .L08145414
	movs r0, #0
	strh r0, [r3, #0x1c]
	lsls r0, r2, #1
	adds r1, r4, #0
	adds r1, #0x5e
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0814540C
	lsls r0, r2, #2
	subs r1, #0x36
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	strh r0, [r3, #0x1c]
.L0814540C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145414: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145418
sub_08145418: @ 0x08145418
	push {lr}
	adds r3, r0, #0
	ldr r1, .L0814543C
	movs r0, #0
	strh r0, [r3, #0x1c]
	movs r2, #0
	adds r1, #0x28
.L08145426:
	ldr r0, [r1]
	cmp r0, #0
	bne .L08145438
	adds r1, #4
	adds r2, #1
	cmp r2, #8
	bls .L08145426
	movs r0, #1
	strh r0, [r3, #0x1c]
.L08145438:
	pop {r0}
	bx r0
.L0814543C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145440
sub_08145440: @ 0x08145440
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L08145480
	movs r1, #0
	strh r1, [r5, #0x1c]
	adds r0, #0x98
	ldr r0, [r0]
	cmp r0, r4
	blo .L08145478
	ldr r3, .L08145484
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r0, r2, r3
	ldr r0, [r0]
	adds r1, r3, #4
	adds r1, r2, r1
	ldr r1, [r1]
	adds r3, #8
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_08145CC8
	cmp r0, #0
	blt .L08145478
	movs r0, #1
	strh r0, [r5, #0x1c]
.L08145478:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145480: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145484: .4byte gUnknown_0879AC18

	thumb_func_start sub_08145488
sub_08145488: @ 0x08145488
.L08145488:
	push {r4, r5, r6, lr}
	ldr r6, .L081454C4
	ldr r5, .L081454C8
	lsls r3, r1, #1
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r3, r5
	ldr r4, [r0]
	subs r4, #1
	adds r0, r5, #4
	adds r0, r3, r0
	ldr r1, [r0]
	subs r1, #1
	adds r5, #8
	adds r3, r3, r5
	ldr r0, [r3]
	subs r0, #1
	lsls r4, r4, #1
	adds r6, #0x4c
	adds r4, r4, r6
	strh r2, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	strh r2, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081454C4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081454C8: .4byte gUnknown_0879AC18

	thumb_func_start sub_081454CC
sub_081454CC: @ 0x081454CC
.L081454CC:
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
.L081454D2:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne .L081454E4
	adds r5, #1
.L081454E4:
	adds r4, #1
	cmp r4, #8
	bls .L081454D2
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_081454F4
sub_081454F4: @ 0x081454F4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08145528
	movs r2, #0
	strh r2, [r5, #0x1c]
	bl sub_081454CC
	adds r2, r0, #0
	cmp r2, #3
	bls .L08145520
	adds r0, r4, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa8
	strh r2, [r0]
	movs r0, #1
	strh r0, [r5, #0x1c]
.L08145520:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145528: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814552C
sub_0814552C: @ 0x0814552C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_081454CC
	cmp r0, #3
	bls .L0814553C
	movs r0, #1
	b .L0814553E
.L0814553C:
	movs r0, #0
.L0814553E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08145548
sub_08145548: @ 0x08145548
	push {lr}
	adds r3, r0, #0
	ldr r1, .L08145574
	movs r0, #0
	strh r0, [r3, #0x1c]
	adds r2, r1, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, #0xa6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L08145570
	movs r0, #1
	strh r0, [r3, #0x1c]
.L08145570:
	pop {r0}
	bx r0
.L08145574: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145578
sub_08145578: @ 0x08145578
.L08145578:
	push {lr}
	ldr r0, .L08145590
	movs r1, #0
	movs r2, #0
	adds r0, #0x5e
.L08145582:
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, #8
	bls .L08145582
	pop {r0}
	bx r0
.L08145590: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145594
sub_08145594: @ 0x08145594
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, .L081455BC
	movs r1, #0
	strh r1, [r3, #0x1c]
	adds r1, r0, #0
	adds r1, #0x94
	ldrh r0, [r1]
	cmp r0, r2
	beq .L081455B8
	strh r2, [r1]
	movs r0, #1
	strh r0, [r3, #0x1c]
	cmp r2, #0
	bne .L081455B8
	bl sub_08145578
.L081455B8:
	pop {r0}
	bx r0
.L081455BC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081455C0
sub_081455C0: @ 0x081455C0
.L081455C0:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r5, .L081455F4
	movs r4, #0
.L081455CA:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bne .L081455E6
	lsls r0, r4, #1
	adds r1, r5, #0
	adds r1, #0x5e
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1]
.L081455E6:
	adds r4, #1
	cmp r4, #8
	bls .L081455CA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081455F4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081455F8
sub_081455F8: @ 0x081455F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r5, .L08145620
	movs r0, #0
	strh r0, [r6, #0x1c]
	bl sub_08145578
	adds r0, r5, #0
	adds r0, #0xa8
	ldrh r0, [r0]
	subs r0, #4
	cmp r0, #5
	bls .L08145616
	b .L0814577C
.L08145616:
	lsls r0, r0, #2
	ldr r1, .L08145624
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08145620: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145624: .4byte gUnknown_08145628
	.global gUnknown_08145628
gUnknown_08145628:
.L08145628: @ jump table
	.4byte .L08145640
	.4byte .L08145648
	.4byte .L08145650
	.4byte .L08145694
	.4byte .L08145702
	.4byte .L0814577C
.L08145640:
	movs r0, #6
	bl sub_081455C0
	b .L0814577C
.L08145648:
	movs r0, #1
	bl sub_081455C0
	b .L0814577C
.L08145650:
	cmp r4, #0
	bne .L0814567C
	adds r0, r5, #0
	adds r0, #0x62
	movs r4, #1
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	adds r0, #0xa
	strh r4, [r0]
	subs r0, #4
	strh r4, [r0]
	adds r0, #0xa
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	movs r0, #4
	b .L08145738
.L0814567C:
	cmp r4, #1
	bne .L0814568A
	adds r0, r6, #0
	movs r1, #4
	bl sub_081453E4
	b .L0814577C
.L0814568A:
	adds r1, r5, #0
	adds r1, #0x66
	movs r0, #1
	strh r0, [r1]
	b .L0814577C
.L08145694:
	cmp r4, #0
	bne .L081456CC
	adds r0, r5, #0
	adds r0, #0x62
	movs r4, #1
	strh r4, [r0]
	subs r0, #4
	strh r4, [r0]
	adds r0, #8
	strh r4, [r0]
	adds r0, #8
	strh r4, [r0]
	subs r0, #4
	strh r4, [r0]
	movs r0, #1
	movs r1, #5
	bl sub_08145378
	movs r0, #3
	movs r1, #5
	bl sub_08145378
	movs r0, #5
	movs r1, #5
	bl sub_08145378
	movs r0, #7
	b .L08145738
.L081456CC:
	cmp r4, #1
	bne .L081456F2
	adds r0, r6, #0
	movs r1, #1
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #3
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #5
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #7
	bl sub_081453E4
	b .L0814577C
.L081456F2:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #1
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	adds r0, #4
	b .L08145776
.L08145702:
	cmp r4, #0
	bne .L08145742
	adds r0, r5, #0
	adds r0, #0x60
	movs r4, #1
	strh r4, [r0]
	adds r0, #8
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	subs r0, #2
	strh r4, [r0]
	adds r0, #8
	strh r4, [r0]
	movs r0, #0
	movs r1, #5
	bl sub_08145378
	movs r0, #2
	movs r1, #5
	bl sub_08145378
	movs r0, #6
	movs r1, #5
	bl sub_08145378
	movs r0, #8
.L08145738:
	movs r1, #5
	bl sub_08145378
	strh r4, [r6, #0x1c]
	b .L0814577C
.L08145742:
	cmp r4, #1
	bne .L08145768
	adds r0, r6, #0
	movs r1, #0
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #2
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #6
	bl sub_081453E4
	adds r0, r6, #0
	movs r1, #8
	bl sub_081453E4
	b .L0814577C
.L08145768:
	adds r0, r5, #0
	adds r0, #0x5e
	movs r1, #1
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	adds r0, #8
.L08145776:
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
.L0814577C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
