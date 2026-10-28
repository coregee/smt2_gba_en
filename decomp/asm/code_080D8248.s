	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080D8248
sub_080D8248: @ 0x080D8248
.L080D8248:
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080D825C
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080D825C: .4byte gUnknown_0872C774

	thumb_func_start sub_080D8260
sub_080D8260: @ 0x080D8260
	ldr r1, .L080D8274
	ldr r0, .L080D8278
	str r0, [r1]
	ldr r0, .L080D827C
	str r0, [r1, #4]
	ldr r0, .L080D8280
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D8274: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8278: .4byte 0x02001000 @ EWRAM+0x1000
.L080D827C: .4byte 0x06016000 @ VRAM+0x16000
.L080D8280: .4byte 0x84000800

	thumb_func_start sub_080D8284
sub_080D8284: @ 0x080D8284
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r7, r0, #0
	adds r7, #0x24
	ldr r1, .L080D82D8
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080D8248
	adds r5, r0, #0
	ldrh r0, [r7, #2]
	adds r6, r0, #0
	str r4, [r7, #0x24]
	cmp r6, #0
	bne .L080D8308
	ldr r0, [r5, #0xc]
	ldr r4, .L080D82DC
	adds r1, r4, #0
	bl HuffUnComp
	ldr r6, .L080D82E0
	adds r0, r4, #0
	adds r1, r6, #0
	bl LZ77UnCompWram
	ldr r1, [r5, #4]
	movs r2, #0xf0
	lsls r2, r2, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #0x20
	bl sub_080C3F4C
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne .L080D82E8
	ldr r0, .L080D82E4
	b .L080D8330
	.byte 0x00, 0x00
.L080D82D8: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D82DC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D82E0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D82E4: .4byte sub_080C3EBC
.L080D82E8:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl HuffUnComp
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r6, r0
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D8304
	b .L080D8330
.L080D8304: .4byte sub_080D8260
.L080D8308:
	cmp r6, #1
	bne .L080D8344
	ldr r0, [r5, #0xc]
	ldr r4, .L080D8338
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L080D833C
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r1, [r5, #4]
	movs r2, #0xf8
	lsls r2, r2, #1
	str r6, [sp]
	adds r0, r7, #0
	movs r3, #0x20
	bl sub_080C3F4C
	ldr r0, .L080D8340
.L080D8330:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080D8370
.L080D8338: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080D833C: .4byte 0x02002000 @ EWRAM+0x2000
.L080D8340: .4byte sub_080C3EE0
.L080D8344:
	ldr r0, [r5, #0xc]
	ldr r4, .L080D8378
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L080D837C
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r1, [r5, #4]
	movs r2, #0xe8
	lsls r2, r2, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #0x20
	bl sub_080C3F4C
	ldr r0, .L080D8380
	movs r1, #1
	bl VBlankTask_AddCounted
.L080D8370:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D8378: .4byte 0x0200CFC8 @ EWRAM+0xCFC8
.L080D837C: .4byte 0x02003000 @ EWRAM+0x3000
.L080D8380: .4byte sub_080C3F04

	thumb_func_start sub_080D8384
sub_080D8384: @ 0x080D8384
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r5, #0x24
	ldr r1, .L080D83CC
	ldr r0, [r5, #0x24]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080D8248
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [r4, #8]
	ldr r3, [r0, #4]
	ldr r0, .L080D83D0
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080D83BA
	adds r3, #8
.L080D83BA:
	ldr r3, [r3]
	ldrh r0, [r5, #2]
	cmp r0, #1
	beq .L080D83E2
	cmp r0, #1
	bgt .L080D83D4
	cmp r0, #0
	beq .L080D83DA
	b .L080D83F0
.L080D83CC: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D83D0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D83D4:
	cmp r0, #2
	beq .L080D83EA
	b .L080D83F0
.L080D83DA:
	movs r7, #0xe
	movs r6, #0xc0
	lsls r6, r6, #2
	b .L080D83F0
.L080D83E2:
	movs r7, #0xf
	movs r6, #0xe0
	lsls r6, r6, #2
	b .L080D83F0
.L080D83EA:
	movs r7, #0xd
	movs r6, #0xa0
	lsls r6, r6, #2
.L080D83F0:
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	str r6, [sp, #4]
	ldrh r0, [r5, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, .L080D8424
	ldrh r1, [r0]
	subs r1, #0x58
	ldrh r0, [r5, #0xa]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r3, r7, #0
	bl sub_080C44CC
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D8424: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080D8428
sub_080D8428: @ 0x080D8428
	push {lr}
	ldr r1, .L080D8434
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D8434: .4byte gUnknown_08005064

	thumb_func_start sub_080D8438
sub_080D8438: @ 0x080D8438
	push {lr}
	ldr r1, .L080D8444
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D8444: .4byte gUnknown_08005088

	thumb_func_start sub_080D8448
sub_080D8448: @ 0x080D8448
	push {lr}
	movs r1, #1
	strh r1, [r0, #0x2e]
	ldr r1, .L080D8458
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D8458: .4byte gUnknown_08005104

	thumb_func_start sub_080D845C
sub_080D845C: @ 0x080D845C
	push {lr}
	ldr r1, .L080D8468
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D8468: .4byte gUnknown_0800520C

	thumb_func_start sub_080D846C
sub_080D846C: @ 0x080D846C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080D8488
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D8484
	adds r0, r2, #0
	bl sub_080C44B0
.L080D8484:
	pop {r0}
	bx r0
.L080D8488: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080D848C
sub_080D848C: @ 0x080D848C
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r2, .L080D84A4
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
.L080D84A4: .4byte gUnknown_081A64A8

	thumb_func_start sub_080D84A8
sub_080D84A8: @ 0x080D84A8
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2a]
	cmp r0, #0xf2
	bne .L080D84DC
	ldr r0, .L080D84C4
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D84CC
	ldr r1, .L080D84C8
	b .L080D84CE
.L080D84C4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D84C8: .4byte gUnknown_080054D4
.L080D84CC:
	ldr r1, .L080D84D8
.L080D84CE:
	adds r0, r2, #0
	bl sub_080D7A84
	b .L080D84E4
	.byte 0x00, 0x00
.L080D84D8: .4byte gUnknown_08005514
.L080D84DC:
	ldr r1, .L080D84E8
	adds r0, r2, #0
	bl sub_080D7A84
.L080D84E4:
	pop {r0}
	bx r0
.L080D84E8: .4byte gUnknown_080054D4

	thumb_func_start sub_080D84EC
sub_080D84EC: @ 0x080D84EC
	push {lr}
	ldr r1, .L080D84F8
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D84F8: .4byte gUnknown_08005554

	thumb_func_start sub_080D84FC
sub_080D84FC: @ 0x080D84FC
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2a]
	cmp r0, #0xf3
	bne .L080D8530
	ldr r0, .L080D8518
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D8520
	ldr r1, .L080D851C
	b .L080D8522
.L080D8518: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D851C: .4byte gUnknown_0800559C
.L080D8520:
	ldr r1, .L080D852C
.L080D8522:
	adds r0, r2, #0
	bl sub_080D7A84
	b .L080D8538
	.byte 0x00, 0x00
.L080D852C: .4byte gUnknown_080055E4
.L080D8530:
	ldr r1, .L080D853C
	adds r0, r2, #0
	bl sub_080D7A84
.L080D8538:
	pop {r0}
	bx r0
.L080D853C: .4byte gUnknown_0800559C

	thumb_func_start sub_080D8540
sub_080D8540: @ 0x080D8540
	push {lr}
	ldr r1, .L080D854C
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D854C: .4byte gUnknown_08005624

	thumb_func_start sub_080D8550
sub_080D8550: @ 0x080D8550
	push {lr}
	ldr r1, .L080D855C
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D855C: .4byte gUnknown_08005664

	thumb_func_start sub_080D8560
sub_080D8560: @ 0x080D8560
	ldr r1, .L080D8574
	ldr r0, .L080D8578
	str r0, [r1]
	ldr r0, .L080D857C
	str r0, [r1, #4]
	ldr r0, .L080D8580
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D8574: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8578: .4byte 0x02003000 @ EWRAM+0x3000
.L080D857C: .4byte 0x06015000 @ VRAM+0x15000
.L080D8580: .4byte 0x84000200

	thumb_func_start sub_080D8584
sub_080D8584: @ 0x080D8584
	push {lr}
	sub sp, #4
	ldr r0, .L080D85B4
	ldr r1, .L080D85B8
	bl LZ77UnCompWram
	ldr r1, .L080D85BC
	ldr r2, .L080D85C0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D85C4
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D85B4: .4byte gUnknown_085171C4
.L080D85B8: .4byte 0x02003000 @ EWRAM+0x3000
.L080D85BC: .4byte gUnknown_08517414
.L080D85C0: .4byte 0x03003150 @ IWRAM+0x3150
.L080D85C4: .4byte sub_080D8560

	thumb_func_start sub_080D85C8
sub_080D85C8: @ 0x080D85C8
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r3, [r4, #0xa]
	ldr r1, .L080D860C
	ldrh r0, [r4, #6]
	subs r0, #0x3b
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xd
	bl sub_080C44CC
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D860C: .4byte gUnknown_085651B0

	thumb_func_start sub_080D8610
sub_080D8610: @ 0x080D8610
.L080D8610:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r1, #0
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r5, [r4, #2]
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r7, r2, #0
	ldrh r1, [r4, #0xa]
	ldr r0, .L080D8664
	ldrh r0, [r0]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, r3, #0
	cmp r5, #0
	bne .L080D8668
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r3, #0
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0xe
	bl sub_080C44CC
	b .L080D86C0
.L080D8664: .4byte 0x0300000E @ IWRAM+0xE
.L080D8668:
	cmp r5, #1
	bne .L080D8696
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r3, #0
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0xf
	bl sub_080C44CC
	b .L080D86C0
.L080D8696:
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	movs r3, #0xd
	bl sub_080C44CC
.L080D86C0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080D86C8
sub_080D86C8: @ 0x080D86C8
	push {lr}
	ldr r1, .L080D86D4
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D86D4: .4byte gUnknown_0800521C

	thumb_func_start sub_080D86D8
sub_080D86D8: @ 0x080D86D8
	push {lr}
	ldr r1, .L080D86E4
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D86E4: .4byte gUnknown_0800522C

	thumb_func_start sub_080D86E8
sub_080D86E8: @ 0x080D86E8
	push {lr}
	ldr r1, .L080D86F4
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D86F4: .4byte gUnknown_0800523C

	thumb_func_start sub_080D86F8
sub_080D86F8: @ 0x080D86F8
	push {lr}
	ldr r1, .L080D8704
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8704: .4byte gUnknown_08005254

	thumb_func_start sub_080D8708
sub_080D8708: @ 0x080D8708
	push {lr}
	ldr r1, .L080D8714
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8714: .4byte gUnknown_08005278

	thumb_func_start sub_080D8718
sub_080D8718: @ 0x080D8718
	push {lr}
	ldr r1, .L080D8724
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8724: .4byte gUnknown_08005290

	thumb_func_start sub_080D8728
sub_080D8728: @ 0x080D8728
	push {lr}
	ldr r1, .L080D8734
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8734: .4byte gUnknown_080052C0

	thumb_func_start sub_080D8738
sub_080D8738: @ 0x080D8738
	push {lr}
	ldr r1, .L080D8744
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8744: .4byte gUnknown_080052F0

	thumb_func_start sub_080D8748
sub_080D8748: @ 0x080D8748
	push {lr}
	ldr r1, .L080D8754
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8754: .4byte gUnknown_08005314

	thumb_func_start sub_080D8758
sub_080D8758: @ 0x080D8758
	push {lr}
	ldr r1, .L080D8764
	bl sub_080D8610
	pop {r0}
	bx r0
.L080D8764: .4byte gUnknown_08005338

	thumb_func_start sub_080D8768
sub_080D8768: @ 0x080D8768
	ldr r1, .L080D877C
	ldr r0, .L080D8780
	str r0, [r1]
	ldr r0, .L080D8784
	str r0, [r1, #4]
	ldr r0, .L080D8788
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D877C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8780: .4byte 0x02003000 @ EWRAM+0x3000
.L080D8784: .4byte 0x06015000 @ VRAM+0x15000
.L080D8788: .4byte 0x84000400

	thumb_func_start sub_080D878C
sub_080D878C: @ 0x080D878C
.L080D878C:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #0
	ldr r3, .L080D87AC
.L080D8798:
	ldr r2, [r3]
	cmp r2, #0
	beq .L080D87B0
	cmp r2, r5
	beq .L080D87B0
	ldrh r0, [r2, #0x2a]
	cmp r0, r4
	bne .L080D87B0
	adds r0, r2, #0
	b .L080D87BA
.L080D87AC: .4byte 0x02036094 @ EWRAM+0x36094
.L080D87B0:
	adds r3, #4
	adds r1, #1
	cmp r1, #5
	bls .L080D8798
	movs r0, #0
.L080D87BA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080D87C0
sub_080D87C0: @ 0x080D87C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xac
	bl sub_080D878C
	cmp r0, #0
	beq .L080D87D8
	b .L080D8910
.L080D87D8:
	adds r0, r4, #0
	movs r1, #0xad
	bl sub_080D878C
	cmp r0, #0
	beq .L080D87E6
	b .L080D8910
.L080D87E6:
	adds r0, r4, #0
	movs r1, #0xae
	bl sub_080D878C
	cmp r0, #0
	beq .L080D87F4
	b .L080D8910
.L080D87F4:
	adds r0, r4, #0
	movs r1, #0xaf
	bl sub_080D878C
	cmp r0, #0
	beq .L080D8802
	b .L080D8910
.L080D8802:
	ldr r0, .L080D88B0
	ldr r4, .L080D88B4
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D88B8
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r4, .L080D88BC
	ldr r6, .L080D88C0
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0x20
	adds r0, r0, r6
	mov sb, r0
	str r5, [sp]
	movs r0, #3
	mov r2, sb
	movs r3, #0x20
	bl Palette_CopyWithEffect
	adds r1, r4, #0
	adds r1, #0x40
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
	str r5, [sp]
	movs r0, #3
	mov r2, r8
	movs r3, #0x20
	bl Palette_CopyWithEffect
	adds r4, #0x60
	adds r7, r6, #0
	adds r7, #0x80
	str r5, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r7, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080D88D0
	ldr r0, .L080D88C4
	str r6, [r0]
	ldr r2, .L080D88C8
	str r2, [r0, #4]
	ldr r3, .L080D88CC
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sb
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0x20
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, r8
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0x40
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r7, [r0]
	adds r2, #0x80
	str r2, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
	bl Palette_MarkDirty
	b .L080D8908
.L080D88B0: .4byte gUnknown_0852C434
.L080D88B4: .4byte 0x02003000 @ EWRAM+0x3000
.L080D88B8: .4byte gUnknown_0852C8CC
.L080D88BC: .4byte gUnknown_0852CC0C
.L080D88C0: .4byte 0x03002D10 @ IWRAM+0x2D10
.L080D88C4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D88C8: .4byte 0x03003110 @ IWRAM+0x3110
.L080D88CC: .4byte 0x84000008
.L080D88D0:
	movs r0, #0xd8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	movs r0, #0xf8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080D8908:
	ldr r0, .L080D8920
	movs r1, #1
	bl VBlankTask_AddCounted
.L080D8910:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D8920: .4byte sub_080D8768

	thumb_func_start sub_080D8924
sub_080D8924: @ 0x080D8924
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4, #6]
	cmp r0, #0xad
	beq .L080D8958
	cmp r0, #0xad
	bgt .L080D8946
	cmp r0, #0xac
	beq .L080D8950
	b .L080D89A0
.L080D8946:
	cmp r0, #0xae
	beq .L080D8960
	cmp r0, #0xaf
	beq .L080D8984
	b .L080D89A0
.L080D8950:
	ldr r1, .L080D8954
	b .L080D8962
.L080D8954: .4byte gUnknown_0800536C
.L080D8958:
	ldr r1, .L080D895C
	b .L080D8962
.L080D895C: .4byte gUnknown_080053C4
.L080D8960:
	ldr r1, .L080D8980
.L080D8962:
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	str r0, [sp, #8]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xb
	bl sub_080C44CC
	b .L080D89A0
	.byte 0x00, 0x00
.L080D8980: .4byte gUnknown_080053F8
.L080D8984:
	ldr r1, .L080D89A8
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	str r0, [sp, #8]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xc
	bl sub_080C44CC
.L080D89A0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
.L080D89A8: .4byte gUnknown_0800542C

	thumb_func_start sub_080D89AC
sub_080D89AC: @ 0x080D89AC
.L080D89AC:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r1, #0
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r5, [r4, #2]
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r7, r2, #0
	ldrh r1, [r4, #0xa]
	ldr r0, .L080D8A00
	ldrh r0, [r0]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, r3, #0
	cmp r5, #0
	bne .L080D8A04
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r3, #0
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0xe
	bl sub_080C44CC
	b .L080D8A5C
.L080D8A00: .4byte 0x0300000E @ IWRAM+0xE
.L080D8A04:
	cmp r5, #1
	bne .L080D8A32
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r3, #0
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0xf
	bl sub_080C44CC
	b .L080D8A5C
.L080D8A32:
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	movs r3, #0xd
	bl sub_080C44CC
.L080D8A5C:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080D8A64
sub_080D8A64: @ 0x080D8A64
	push {lr}
	ldr r1, .L080D8A70
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8A70: .4byte gUnknown_08005460

	thumb_func_start sub_080D8A74
sub_080D8A74: @ 0x080D8A74
	push {lr}
	ldr r1, .L080D8A80
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8A80: .4byte gUnknown_08005494

	thumb_func_start sub_080D8A84
sub_080D8A84: @ 0x080D8A84
	ldr r1, .L080D8A98
	ldr r0, .L080D8A9C
	str r0, [r1]
	ldr r0, .L080D8AA0
	str r0, [r1, #4]
	ldr r0, .L080D8AA4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D8A98: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8A9C: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8AA0: .4byte 0x06016000 @ VRAM+0x16000
.L080D8AA4: .4byte 0x84000600

	thumb_func_start sub_080D8AA8
sub_080D8AA8: @ 0x080D8AA8
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080D8AF4
	ldr r4, .L080D8AF8
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D8AFC
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D8B00
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D8B04
	ldr r2, .L080D8B08
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D8B0C
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080D8AF4: .4byte gUnknown_085332EC
.L080D8AF8: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8AFC: .4byte gUnknown_08533788
.L080D8B00: .4byte gUnknown_08533C94
.L080D8B04: .4byte gUnknown_085340D8
.L080D8B08: .4byte 0x03003170 @ IWRAM+0x3170
.L080D8B0C: .4byte sub_080D8A84

	thumb_func_start sub_080D8B10
sub_080D8B10: @ 0x080D8B10
	push {lr}
	ldr r1, .L080D8B1C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B1C: .4byte gUnknown_08005810

	thumb_func_start sub_080D8B20
sub_080D8B20: @ 0x080D8B20
	push {lr}
	ldr r1, .L080D8B2C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B2C: .4byte gUnknown_08005850

	thumb_func_start sub_080D8B30
sub_080D8B30: @ 0x080D8B30
	push {lr}
	ldr r1, .L080D8B3C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B3C: .4byte gUnknown_08005898

	thumb_func_start sub_080D8B40
sub_080D8B40: @ 0x080D8B40
	push {lr}
	ldr r1, .L080D8B4C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B4C: .4byte gUnknown_080058EC

	thumb_func_start sub_080D8B50
sub_080D8B50: @ 0x080D8B50
	push {lr}
	ldr r1, .L080D8B5C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B5C: .4byte gUnknown_0800594C

	thumb_func_start sub_080D8B60
sub_080D8B60: @ 0x080D8B60
	push {lr}
	ldr r1, .L080D8B6C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B6C: .4byte gUnknown_080056AC

	thumb_func_start sub_080D8B70
sub_080D8B70: @ 0x080D8B70
	push {lr}
	ldr r1, .L080D8B7C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B7C: .4byte gUnknown_080056F8

	thumb_func_start sub_080D8B80
sub_080D8B80: @ 0x080D8B80
	push {lr}
	ldr r1, .L080D8B8C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B8C: .4byte gUnknown_08005744

	thumb_func_start sub_080D8B90
sub_080D8B90: @ 0x080D8B90
	push {lr}
	ldr r1, .L080D8B9C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8B9C: .4byte gUnknown_08005790

	thumb_func_start sub_080D8BA0
sub_080D8BA0: @ 0x080D8BA0
	push {lr}
	ldr r1, .L080D8BAC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BAC: .4byte gUnknown_080057D0

	thumb_func_start sub_080D8BB0
sub_080D8BB0: @ 0x080D8BB0
	push {lr}
	ldr r1, .L080D8BBC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BBC: .4byte gUnknown_0800595C

	thumb_func_start sub_080D8BC0
sub_080D8BC0: @ 0x080D8BC0
	push {lr}
	ldr r1, .L080D8BCC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BCC: .4byte gUnknown_08005974

	thumb_func_start sub_080D8BD0
sub_080D8BD0: @ 0x080D8BD0
	push {lr}
	ldr r1, .L080D8BDC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BDC: .4byte gUnknown_0800598C

	thumb_func_start sub_080D8BE0
sub_080D8BE0: @ 0x080D8BE0
	push {lr}
	ldr r1, .L080D8BEC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BEC: .4byte gUnknown_080059A4

	thumb_func_start sub_080D8BF0
sub_080D8BF0: @ 0x080D8BF0
	push {lr}
	ldr r1, .L080D8BFC
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8BFC: .4byte gUnknown_080059B4

	thumb_func_start sub_080D8C00
sub_080D8C00: @ 0x080D8C00
	push {lr}
	ldr r1, .L080D8C0C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8C0C: .4byte gUnknown_080059C4

	thumb_func_start sub_080D8C10
sub_080D8C10: @ 0x080D8C10
	ldr r1, .L080D8C24
	ldr r0, .L080D8C28
	str r0, [r1]
	ldr r0, .L080D8C2C
	str r0, [r1, #4]
	ldr r0, .L080D8C30
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D8C24: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8C28: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8C2C: .4byte 0x06016000 @ VRAM+0x16000
.L080D8C30: .4byte 0x84000600

	thumb_func_start sub_080D8C34
sub_080D8C34: @ 0x080D8C34
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r5, #0x24
	ldr r0, .L080D8CA8
	ldr r4, .L080D8CAC
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D8CB0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D8CB4
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D8CB8
	ldr r2, .L080D8CBC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D8CC0
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080C2244
	ldr r2, .L080D8CC4
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	str r0, [r5, #0x24]
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	adds r1, #1
	str r1, [r5, #0x28]
	str r1, [r5, #0x2c]
	movs r0, #0x50
	str r0, [r5, #0x30]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D8CA8: .4byte gUnknown_08535510
.L080D8CAC: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8CB0: .4byte gUnknown_08535988
.L080D8CB4: .4byte gUnknown_08535FB8
.L080D8CB8: .4byte gUnknown_08536318
.L080D8CBC: .4byte 0x03003170 @ IWRAM+0x3170
.L080D8CC0: .4byte sub_080D8C10
.L080D8CC4: .4byte gUnknown_08565C08

	thumb_func_start sub_080D8CC8
sub_080D8CC8: @ 0x080D8CC8
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [r4, #0x24]
	movs r0, #3
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	str r0, [sp, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xe
	bl sub_080C44CC
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D8D08
sub_080D8D08: @ 0x080D8D08
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	ldrh r0, [r1, #0xa]
	adds r0, #2
	strh r0, [r1, #0xa]
	ldr r0, [r1, #0x30]
	subs r0, #1
	str r0, [r1, #0x30]
	cmp r0, #0
	bne .L080D8D2C
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080D8D2C:
	pop {r0}
	bx r0

	thumb_func_start sub_080D8D30
sub_080D8D30: @ 0x080D8D30
	push {lr}
	ldr r1, .L080D8D3C
	bl sub_080D89AC
	pop {r0}
	bx r0
.L080D8D3C: .4byte gUnknown_08005B40

	thumb_func_start sub_080D8D40
sub_080D8D40: @ 0x080D8D40
	adds r0, #0x48
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	adds r1, #0xff
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	strh r2, [r0, #6]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D8D54
sub_080D8D54: @ 0x080D8D54
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r5, .L080D8D78
	adds r1, r5, #0
	bl HuffUnComp
	lsls r4, r4, #0xb
	ldr r0, .L080D8D7C
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D8D78: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D8D7C: .4byte 0x02001000 @ EWRAM+0x1000

	thumb_func_start sub_080D8D80
sub_080D8D80: @ 0x080D8D80
	ldr r1, .L080D8D94
	ldr r0, .L080D8D98
	str r0, [r1]
	ldr r0, .L080D8D9C
	str r0, [r1, #4]
	ldr r0, .L080D8DA0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D8D94: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8D98: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8D9C: .4byte 0x06013000 @ VRAM+0x13000
.L080D8DA0: .4byte 0x84000C00

	thumb_func_start sub_080D8DA4
sub_080D8DA4: @ 0x080D8DA4
	push {lr}
	sub sp, #4
	ldr r2, .L080D8DC8
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D8DCC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r0}
	bx r0
.L080D8DC8: .4byte 0x03003150 @ IWRAM+0x3150
.L080D8DCC: .4byte sub_080D8D80

	thumb_func_start sub_080D8DD0
sub_080D8DD0: @ 0x080D8DD0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	ldr r1, .L080D8E14
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x58
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D8E14: .4byte gUnknown_08565CD8

	thumb_func_start sub_080D8E18
sub_080D8E18: @ 0x080D8E18
	strh r1, [r0, #0x3c]
	bx lr

	thumb_func_start sub_080D8E1C
sub_080D8E1C: @ 0x080D8E1C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne .L080D8E64
	ldr r1, .L080D8E60
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x58
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	b .L080D8E92
.L080D8E60: .4byte gUnknown_08565DC4
.L080D8E64:
	ldr r1, .L080D8E9C
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x58
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
.L080D8E92:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D8E9C: .4byte gUnknown_08565DE8

	thumb_func_start sub_080D8EA0
sub_080D8EA0: @ 0x080D8EA0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r5, #0
	bl sub_080C4388
	ldrh r0, [r5, #0x18]
	adds r4, #0x48
	ldrh r6, [r5, #0xc]
	cmp r6, #0
	bne .L080D8F0C
	ldr r1, .L080D8F04
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #0x10
	bl sub_0815862C
	ldr r0, .L080D8F08
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r5, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_DrawSharedAffine
	b .L080D8F3C
.L080D8F04: .4byte gUnknown_08565F20
.L080D8F08: .4byte 0x03003800 @ IWRAM+0x3800
.L080D8F0C:
	ldr r1, .L080D8F44
	adds r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r5, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
.L080D8F3C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D8F44: .4byte gUnknown_08565F20

	thumb_func_start sub_080D8F48
sub_080D8F48: @ 0x080D8F48
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r5, #0
	bl sub_080C4388
	ldrh r0, [r5, #0x18]
	adds r4, #0x48
	ldrh r6, [r5, #0xc]
	cmp r6, #0
	bne .L080D8FB4
	ldr r1, .L080D8FAC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #0x10
	bl sub_0815862C
	ldr r0, .L080D8FB0
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r5, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_DrawSharedAffine
	b .L080D8FE4
.L080D8FAC: .4byte gUnknown_08565FE4
.L080D8FB0: .4byte 0x03003800 @ IWRAM+0x3800
.L080D8FB4:
	ldr r1, .L080D8FEC
	adds r0, #4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r5, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
.L080D8FE4:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D8FEC: .4byte gUnknown_08565FE4

	thumb_func_start sub_080D8FF0
sub_080D8FF0: @ 0x080D8FF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r1, [r4, #0x24]
	movs r0, #0x3d
	subs r0, r0, r1
	movs r6, #0
	strh r0, [r4, #8]
	strh r6, [r4, #0xa]
	ldr r1, .L080D902C
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	ldr r0, [r4, #0x24]
	adds r0, #0x63
	strh r0, [r4, #8]
	strh r6, [r4, #0xa]
	ldr r1, .L080D9030
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D902C: .4byte gUnknown_08004FF8
.L080D9030: .4byte gUnknown_08005028

	thumb_func_start sub_080D9034
sub_080D9034: @ 0x080D9034
	movs r1, #0
	str r1, [r0, #0x48]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D903C
sub_080D903C: @ 0x080D903C
	push {r4, r5, lr}
	adds r0, #0x24
	ldr r1, [r0, #0x24]
	adds r1, #1
	str r1, [r0, #0x24]
	ldr r1, .L080D9088
	movs r0, #0x3d
	strb r0, [r1]
	ldr r0, .L080D908C
	movs r2, #0
	strb r2, [r0]
	ldr r0, .L080D9090
	movs r4, #0x47
	strb r4, [r0]
	ldr r0, .L080D9094
	strb r2, [r0]
	ldr r0, .L080D9098
	movs r5, #0x3f
	movs r3, #0x2f
	strb r3, [r0]
	ldr r1, .L080D909C
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080D90A0
	movs r0, #0xb3
	strb r0, [r1]
	ldr r0, .L080D90A4
	strb r4, [r0]
	ldr r0, .L080D90A8
	strb r2, [r0]
	ldr r0, .L080D90AC
	strb r3, [r0]
	ldr r0, .L080D90B0
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9088: .4byte 0x03000030 @ IWRAM+0x30
.L080D908C: .4byte 0x03000031 @ IWRAM+0x31
.L080D9090: .4byte 0x03000034 @ IWRAM+0x34
.L080D9094: .4byte 0x03000035 @ IWRAM+0x35
.L080D9098: .4byte 0x03000038 @ IWRAM+0x38
.L080D909C: .4byte 0x03000032 @ IWRAM+0x32
.L080D90A0: .4byte 0x03000033 @ IWRAM+0x33
.L080D90A4: .4byte 0x03000036 @ IWRAM+0x36
.L080D90A8: .4byte 0x03000037 @ IWRAM+0x37
.L080D90AC: .4byte 0x03000039 @ IWRAM+0x39
.L080D90B0: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D90B4
sub_080D90B4: @ 0x080D90B4
	ldr r0, .L080D90C4
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080D90C8
	strb r1, [r0]
	ldr r0, .L080D90CC
	strb r1, [r0]
	bx lr
.L080D90C4: .4byte 0x03000038 @ IWRAM+0x38
.L080D90C8: .4byte 0x03000039 @ IWRAM+0x39
.L080D90CC: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D90D0
sub_080D90D0: @ 0x080D90D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r1, [r4, #0x24]
	movs r0, #0x4d
	subs r0, r0, r1
	strh r0, [r4, #8]
	movs r6, #0x20
	strh r6, [r4, #0xa]
	ldr r1, .L080D910C
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	ldr r0, [r4, #0x24]
	adds r0, #0x53
	strh r0, [r4, #8]
	strh r6, [r4, #0xa]
	ldr r1, .L080D9110
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D910C: .4byte gUnknown_08004FF8
.L080D9110: .4byte gUnknown_08005028

	thumb_func_start sub_080D9114
sub_080D9114: @ 0x080D9114
	movs r1, #0
	str r1, [r0, #0x48]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D911C
sub_080D911C: @ 0x080D911C
	push {r4, r5, lr}
	adds r0, #0x24
	ldr r1, [r0, #0x24]
	adds r1, #1
	str r1, [r0, #0x24]
	ldr r1, .L080D9168
	movs r0, #0x4d
	strb r0, [r1]
	ldr r0, .L080D916C
	movs r2, #0
	strb r2, [r0]
	ldr r0, .L080D9170
	movs r4, #0x57
	strb r4, [r0]
	ldr r0, .L080D9174
	strb r2, [r0]
	ldr r0, .L080D9178
	movs r5, #0x3f
	movs r3, #0x2f
	strb r3, [r0]
	ldr r1, .L080D917C
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080D9180
	movs r0, #0xa3
	strb r0, [r1]
	ldr r0, .L080D9184
	strb r4, [r0]
	ldr r0, .L080D9188
	strb r2, [r0]
	ldr r0, .L080D918C
	strb r3, [r0]
	ldr r0, .L080D9190
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9168: .4byte 0x03000030 @ IWRAM+0x30
.L080D916C: .4byte 0x03000031 @ IWRAM+0x31
.L080D9170: .4byte 0x03000034 @ IWRAM+0x34
.L080D9174: .4byte 0x03000035 @ IWRAM+0x35
.L080D9178: .4byte 0x03000038 @ IWRAM+0x38
.L080D917C: .4byte 0x03000032 @ IWRAM+0x32
.L080D9180: .4byte 0x03000033 @ IWRAM+0x33
.L080D9184: .4byte 0x03000036 @ IWRAM+0x36
.L080D9188: .4byte 0x03000037 @ IWRAM+0x37
.L080D918C: .4byte 0x03000039 @ IWRAM+0x39
.L080D9190: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D9194
sub_080D9194: @ 0x080D9194
	ldr r0, .L080D91A4
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080D91A8
	strb r1, [r0]
	ldr r0, .L080D91AC
	strb r1, [r0]
	bx lr
.L080D91A4: .4byte 0x03000038 @ IWRAM+0x38
.L080D91A8: .4byte 0x03000039 @ IWRAM+0x39
.L080D91AC: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D91B0
sub_080D91B0: @ 0x080D91B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldrh r6, [r5, #8]
	ldr r1, .L080D91E0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	ldrh r0, [r5, #8]
	adds r0, #0x50
	strh r0, [r5, #8]
	ldr r1, .L080D91E4
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	strh r6, [r5, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D91E0: .4byte gUnknown_08004FF8
.L080D91E4: .4byte gUnknown_08005028

	thumb_func_start sub_080D91E8
sub_080D91E8: @ 0x080D91E8
	ldr r1, .L080D91FC
	ldr r0, .L080D9200
	str r0, [r1]
	ldr r0, .L080D9204
	str r0, [r1, #4]
	ldr r0, .L080D9208
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D91FC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9200: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9204: .4byte 0x06014C00 @ VRAM+0x14C00
.L080D9208: .4byte 0x84000D00

	thumb_func_start sub_080D920C
sub_080D920C: @ 0x080D920C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r5, #0x24
	ldr r0, .L080D926C
	ldr r4, .L080D9270
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D9274
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D9278
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D927C
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D9280
	movs r2, #0xf0
	lsls r2, r2, #1
	movs r4, #1
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
	ldr r0, .L080D9284
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	str r0, [r5, #0x24]
	strh r4, [r5, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D926C: .4byte gUnknown_08566C34
.L080D9270: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9274: .4byte gUnknown_08567060
.L080D9278: .4byte gUnknown_085673D0
.L080D927C: .4byte gUnknown_085677A4
.L080D9280: .4byte gUnknown_08567894
.L080D9284: .4byte sub_080D91E8

	thumb_func_start sub_080D9288
sub_080D9288: @ 0x080D9288
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	ldr r1, .L080D92CC
	ldr r0, [r4, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x98
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x58
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0xe
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D92CC: .4byte gUnknown_085678B4

	thumb_func_start sub_080D92D0
sub_080D92D0: @ 0x080D92D0
	str r1, [r0, #0x48]
	bx lr

	thumb_func_start sub_080D92D4
sub_080D92D4: @ 0x080D92D4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	ldr r1, .L080D9318
	ldr r0, [r4, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x58
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #8
	movs r2, #0xf
	movs r3, #3
	bl Sprite_DrawBlended
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D9318: .4byte gUnknown_0856793C

	thumb_func_start sub_080D931C
sub_080D931C: @ 0x080D931C
	str r1, [r0, #0x48]
	bx lr

	thumb_func_start sub_080D9320
sub_080D9320: @ 0x080D9320
	ldr r1, .L080D9334
	ldr r0, .L080D9338
	str r0, [r1]
	ldr r0, .L080D933C
	str r0, [r1, #4]
	ldr r0, .L080D9340
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9334: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9338: .4byte 0x02001000 @ EWRAM+0x1000
.L080D933C: .4byte 0x06015000 @ VRAM+0x15000
.L080D9340: .4byte 0x84000B00

	thumb_func_start sub_080D9344
sub_080D9344: @ 0x080D9344
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r5, #0x24
	ldr r0, .L080D939C
	ldr r4, .L080D93A0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D93A4
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D93A8
	movs r1, #0x80
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D93AC
	ldr r2, .L080D93B0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D93B4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	str r0, [r5, #0x24]
	movs r0, #1
	strh r0, [r5, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D939C: .4byte gUnknown_08567A04
.L080D93A0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D93A4: .4byte gUnknown_08567F4C
.L080D93A8: .4byte gUnknown_08568218
.L080D93AC: .4byte gUnknown_085683D0
.L080D93B0: .4byte 0x03003170 @ IWRAM+0x3170
.L080D93B4: .4byte sub_080D9320

	thumb_func_start sub_080D93B8
sub_080D93B8: @ 0x080D93B8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [r4, #0x24]
	cmp r0, #9
	bhi .L080D9404
	ldr r1, .L080D9400
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	adds r1, r2, #0
	movs r2, #0xe
	movs r3, #3
	bl Sprite_DrawBlended
	b .L080D9430
	.byte 0x00, 0x00
.L080D9400: .4byte gUnknown_085683F0
.L080D9404:
	ldr r1, .L080D9438
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r4, #8]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r4, #0xa]
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	adds r1, r2, #0
	movs r2, #0xe
	movs r3, #3
	bl Sprite_Draw
.L080D9430:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D9438: .4byte gUnknown_085683F0

	thumb_func_start sub_080D943C
sub_080D943C: @ 0x080D943C
	adds r0, #0x24
	ldr r1, [r0, #0x24]
	adds r1, #1
	str r1, [r0, #0x24]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D9448
sub_080D9448: @ 0x080D9448
	ldr r1, .L080D945C
	ldr r0, .L080D9460
	str r0, [r1]
	ldr r0, .L080D9464
	str r0, [r1, #4]
	ldr r0, .L080D9468
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D945C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9460: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9464: .4byte 0x06013000 @ VRAM+0x13000
.L080D9468: .4byte 0x84000E00

	thumb_func_start sub_080D946C
sub_080D946C: @ 0x080D946C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r5, #0x24
	ldr r0, .L080D94D0
	ldr r4, .L080D94D4
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D94D8
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D94DC
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080D94E0
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D94E4
	ldr r2, .L080D94E8
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D94EC
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	str r0, [r5, #0x24]
	movs r0, #1
	strh r0, [r5, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D94D0: .4byte gUnknown_0853131C
.L080D94D4: .4byte 0x02001000 @ EWRAM+0x1000
.L080D94D8: .4byte gUnknown_08531914
.L080D94DC: .4byte gUnknown_08532034
.L080D94E0: .4byte gUnknown_08532744
.L080D94E4: .4byte gUnknown_08532A9C
.L080D94E8: .4byte 0x03003150 @ IWRAM+0x3150
.L080D94EC: .4byte sub_080D9448

	thumb_func_start sub_080D94F0
sub_080D94F0: @ 0x080D94F0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080D9538
	ldr r0, [r4, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	str r2, [sp]
	ldrh r2, [r4, #8]
	adds r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldrh r2, [r4, #0xa]
	adds r2, #0x58
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	movs r2, #0xd
	movs r3, #3
	bl Sprite_DrawBlended
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D9538: .4byte gUnknown_08568C14

	thumb_func_start sub_080D953C
sub_080D953C: @ 0x080D953C
	ldr r1, .L080D9550
	ldr r0, .L080D9554
	str r0, [r1]
	ldr r0, .L080D9558
	str r0, [r1, #4]
	ldr r0, .L080D955C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9550: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9554: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9558: .4byte 0x06016800 @ VRAM+0x16800
.L080D955C: .4byte 0x84000400

	thumb_func_start sub_080D9560
sub_080D9560: @ 0x080D9560
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, .L080D959C
	ldr r1, .L080D95A0
	bl LZ77UnCompWram
	ldr r1, .L080D95A4
	ldr r2, .L080D95A8
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D95AC
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	str r0, [r4, #0x24]
	movs r0, #1
	strh r0, [r4, #4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080D959C: .4byte gUnknown_08550398
.L080D95A0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D95A4: .4byte gUnknown_08550EBC
.L080D95A8: .4byte 0x03003170 @ IWRAM+0x3170
.L080D95AC: .4byte sub_080D953C

	thumb_func_start sub_080D95B0
sub_080D95B0: @ 0x080D95B0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L080D95F0
	movs r2, #0xd0
	lsls r2, r2, #2
	str r2, [sp]
	ldrh r2, [r4, #8]
	adds r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldrh r2, [r4, #0xa]
	adds r2, #0x58
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	movs r2, #0xe
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D95F0: .4byte gUnknown_080061A0

	thumb_func_start sub_080D95F4
sub_080D95F4: @ 0x080D95F4
.L080D95F4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x2c
	muls r0, r1, r0
	ldr r1, .L080D9604
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080D9604: .4byte gUnknown_08568D78

	thumb_func_start sub_080D9608
sub_080D9608: @ 0x080D9608
	push {r4, lr}
	sub sp, #0xc
	bl sub_080C1450
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080D9690
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D9694
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl Windows_Init
	bl sub_080C1328
	bl sub_080C1384
	movs r4, #0
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L080D9698
	ldr r2, .L080D969C
	bl CpuSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r1, .L080D96A0
	ldr r2, .L080D96A4
	bl CpuSet
	ldr r1, .L080D96A8
	ldr r2, .L080D96AC
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080D96B0
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L080D96B4
	movs r0, #1
	strh r0, [r1]
	bl Task_ClearAll
	bl sub_080AE2D0
	movs r0, #4
	movs r1, #3
	bl SaveScreen_Open
	movs r0, #0xd
	bl sub_080C5170
	ldr r0, .L080D96B8
	bl SetMainCallback
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9690: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9694: .4byte 0x81002000
.L080D9698: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D969C: .4byte 0x05001A00
.L080D96A0: .4byte 0x02024074 @ EWRAM+0x24074
.L080D96A4: .4byte 0x05001000
.L080D96A8: .4byte 0x04000200 @ REG_IE
.L080D96AC: .4byte 0x00002003
.L080D96B0: .4byte 0x04000004 @ REG_DISPSTAT
.L080D96B4: .4byte 0x04000208 @ REG_IME
.L080D96B8: .4byte sub_080D977C

	thumb_func_start sub_080D96BC
sub_080D96BC: @ 0x080D96BC
	push {r4, lr}
	sub sp, #0xc
	bl sub_080C1450
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080D9740
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D9744
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r4, #0
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L080D9748
	ldr r2, .L080D974C
	bl CpuSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r1, .L080D9750
	ldr r2, .L080D9754
	bl CpuSet
	ldr r1, .L080D9758
	ldr r2, .L080D975C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080D9760
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L080D9764
	movs r0, #1
	strh r0, [r1]
	bl Task_ClearAll
	bl sub_080AE2D0
	ldr r0, .L080D9768
	str r4, [r0]
	ldr r0, .L080D976C
	ldr r1, .L080D9770
	bl Task_Create
	movs r0, #0xd
	bl sub_080C5170
	ldr r0, .L080D9774
	str r4, [r0]
	ldr r0, .L080D9778
	bl SetMainCallback
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9740: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9744: .4byte 0x81002000
.L080D9748: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D974C: .4byte 0x05001A00
.L080D9750: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9754: .4byte 0x05001000
.L080D9758: .4byte 0x04000200 @ REG_IE
.L080D975C: .4byte 0x00002003
.L080D9760: .4byte 0x04000004 @ REG_DISPSTAT
.L080D9764: .4byte 0x04000208 @ REG_IME
.L080D9768: .4byte 0x03006098 @ IWRAM+0x6098
.L080D976C: .4byte gUnknown_085816B8
.L080D9770: .4byte 0x0000FFFF
.L080D9774: .4byte 0x0300609C @ IWRAM+0x609C
.L080D9778: .4byte sub_080D977C
