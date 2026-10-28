	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_081272CC
sub_081272CC: @ 0x081272CC
.L081272CC:
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #4
	bne .L08127358
	ldr r0, .L08127344
	ldr r2, .L08127348
	adds r1, r0, r2
	movs r2, #0x80
	bl CpuFastSet
	movs r4, #0
.L081272E8:
	lsls r2, r4, #1
	adds r1, r2, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0812730A
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0x80
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L0812734C
	movs r3, #2
	bl Font_DrawGlyphTinted
.L0812730A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L081272E8
	ldr r4, .L08127350
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0x80
	lsls r0, r0, #3
	adds r5, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #4]
	ldr r2, .L08127354
	add r0, sp, #4
	adds r1, r5, #0
	bl CpuFastSet
	b .L08127386
.L08127344: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L08127348: .4byte 0xFFFFE600
.L0812734C: .4byte 0x030000B4 @ IWRAM+0xB4
.L08127350: .4byte 0x030002B4 @ IWRAM+0x2B4
.L08127354: .4byte 0x01000080
.L08127358:
	movs r4, #0
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #6
	lsls r6, r0, #0x10
.L08127362:
	lsls r2, r4, #1
	adds r1, r2, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0812737C
	adds r2, r2, r4
	lsls r2, r2, #2
	movs r1, #0
	str r1, [sp]
	ldr r1, .L08127390
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
.L0812737C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L08127362
.L08127386:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08127390: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_08127394
sub_08127394: @ 0x08127394
.L08127394:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	cmp r1, #4
	bne .L08127424
	ldr r0, .L08127410
	ldr r2, .L08127414
	adds r1, r0, r2
	movs r2, #0x80
	bl CpuFastSet
	movs r4, #0
.L081273B4:
	lsls r2, r4, #1
	adds r1, r2, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq .L081273D4
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0x80
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	str r5, [sp]
	ldr r1, .L08127418
	movs r3, #2
	bl Font_DrawGlyphTinted
.L081273D4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L081273B4
	ldr r4, .L0812741C
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0x80
	lsls r0, r0, #3
	adds r5, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #4]
	ldr r2, .L08127420
	add r0, sp, #4
	adds r1, r5, #0
	bl CpuFastSet
	b .L08127450
	.byte 0x00, 0x00
.L08127410: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L08127414: .4byte 0xFFFFE600
.L08127418: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812741C: .4byte 0x030002B4 @ IWRAM+0x2B4
.L08127420: .4byte 0x01000080
.L08127424:
	movs r4, #0
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #6
	lsls r7, r0, #0x10
.L0812742E:
	lsls r2, r4, #1
	adds r1, r2, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08127446
	adds r2, r2, r4
	lsls r2, r2, #2
	str r5, [sp]
	ldr r1, .L08127458
	lsrs r3, r7, #0x10
	bl Font_DrawGlyphTinted
.L08127446:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L0812742E
.L08127450:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08127458: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_0812745C
sub_0812745C: @ 0x0812745C
.L0812745C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl NumberToDigits
	adds r7, r0, #0
	cmp r5, #4
	bne .L08127518
	ldr r4, .L081274FC
	ldr r0, .L08127500
	adds r0, r0, r4
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, .L08127504
	adds r1, r1, r4
	mov sl, r1
	ldr r0, .L08127508
	adds r0, r0, r4
	mov r8, r0
	mov r0, sl
	mov r1, r8
	movs r2, #0x80
	bl CpuFastSet
	ldrb r0, [r7]
	adds r0, #0x10
	ldr r1, .L0812750C
	adds r5, r4, r1
	movs r6, #0
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0xf7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r7, #1]
	adds r0, #0x10
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0xef
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	str r6, [sp]
	movs r0, #0x3e
	adds r1, r5, #0
	movs r2, #0xe3
	movs r3, #0x13
	bl Font_DrawGlyphTinted
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	mov r0, r8
	mov r1, sl
	movs r2, #0x80
	bl CpuFastSet
	str r6, [sp, #4]
	ldr r0, .L08127510
	adds r4, r4, r0
	ldr r2, .L08127514
	add r0, sp, #4
	adds r1, r4, #0
	bl CpuFastSet
	b .L08127556
.L081274FC: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L08127500: .4byte 0xFFFFEE00
.L08127504: .4byte 0xFFFFE600
.L08127508: .4byte 0xFFFFF200
.L0812750C: .4byte 0xFFFFE400
.L08127510: .4byte 0xFFFFEA00
.L08127514: .4byte 0x01000080
.L08127518:
	ldrb r0, [r7]
	adds r0, #0x10
	ldr r6, .L08127568
	movs r1, #0xd
	muls r5, r1, r5
	movs r1, #8
	adds r1, r1, r5
	mov r8, r1
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x77
	mov r3, r8
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r7, #1]
	adds r0, #0x10
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x6f
	mov r3, r8
	bl DigitFont_DrawGlyphTinted
	adds r5, #7
	str r4, [sp]
	movs r0, #0x3e
	adds r1, r6, #0
	movs r2, #0x63
	adds r3, r5, #0
	bl Font_DrawGlyphTinted
.L08127556:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08127568: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_0812756C
sub_0812756C: @ 0x0812756C
.L0812756C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	bl NumberToDigits
	adds r7, r0, #0
	cmp r4, #4
	bne .L08127628
	ldr r4, .L0812760C
	ldr r0, .L08127610
	adds r0, r0, r4
	mov r8, r0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, .L08127614
	adds r1, r1, r4
	mov sb, r1
	ldr r0, .L08127618
	adds r0, r0, r4
	mov sl, r0
	mov r0, sb
	mov r1, sl
	movs r2, #0x80
	bl CpuFastSet
	ldrb r0, [r7]
	adds r0, #0x10
	str r6, [sp]
	ldr r1, .L0812761C
	movs r2, #0xf7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r7, #1]
	adds r0, #0x10
	str r6, [sp]
	ldr r1, .L0812761C
	movs r2, #0xef
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	str r6, [sp]
	movs r0, #0x3e
	ldr r1, .L0812761C
	movs r2, #0xe3
	movs r3, #0x13
	bl Font_DrawGlyphTinted
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	mov r0, sl
	mov r1, sb
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L08127620
	adds r4, r4, r1
	ldr r2, .L08127624
	add r0, sp, #4
	adds r1, r4, #0
	bl CpuFastSet
	b .L08127664
.L0812760C: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L08127610: .4byte 0xFFFFEE00
.L08127614: .4byte 0xFFFFE600
.L08127618: .4byte 0xFFFFF200
.L0812761C: .4byte 0x030000B4 @ IWRAM+0xB4
.L08127620: .4byte 0xFFFFEA00
.L08127624: .4byte 0x01000080
.L08127628:
	ldrb r0, [r7]
	adds r0, #0x10
	ldr r1, .L08127674
	mov r8, r1
	movs r1, #0xd
	muls r4, r1, r4
	adds r5, r4, #0
	adds r5, #8
	str r6, [sp]
	mov r1, r8
	movs r2, #0x77
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r7, #1]
	adds r0, #0x10
	str r6, [sp]
	mov r1, r8
	movs r2, #0x6f
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
	adds r4, #7
	str r6, [sp]
	movs r0, #0x3e
	mov r1, r8
	movs r2, #0x63
	adds r3, r4, #0
	bl Font_DrawGlyphTinted
.L08127664:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08127674: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_08127678
sub_08127678: @ 0x08127678
.L08127678:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl NumberToDigits
	adds r4, r0, #0
	cmp r5, #4
	bne .L08127748
	ldr r5, .L0812772C
	ldr r0, .L08127730
	adds r0, r0, r5
	mov sb, r0
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, .L08127734
	adds r1, r1, r5
	mov sl, r1
	ldr r0, .L08127738
	adds r0, r0, r5
	mov r8, r0
	mov r0, sl
	mov r1, r8
	movs r2, #0x80
	bl CpuFastSet
	ldrb r0, [r4]
	adds r0, #0x10
	ldr r1, .L0812773C
	adds r6, r5, r1
	movs r7, #0
	str r7, [sp]
	adds r1, r6, #0
	movs r2, #0xf7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	beq .L081276EA
	adds r0, #0x10
	str r7, [sp]
	adds r1, r6, #0
	movs r2, #0xef
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
.L081276EA:
	str r7, [sp]
	movs r0, #0x2d
	adds r1, r6, #0
	movs r2, #0xdf
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	str r7, [sp]
	movs r0, #0x30
	adds r1, r6, #0
	movs r2, #0xe7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0x80
	bl CpuFastSet
	mov r0, r8
	mov r1, sl
	movs r2, #0x80
	bl CpuFastSet
	str r7, [sp, #4]
	ldr r0, .L08127740
	adds r1, r5, r0
	ldr r2, .L08127744
	add r0, sp, #4
	bl CpuFastSet
	b .L08127796
	.byte 0x00, 0x00
.L0812772C: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L08127730: .4byte 0xFFFFEE00
.L08127734: .4byte 0xFFFFE600
.L08127738: .4byte 0xFFFFF200
.L0812773C: .4byte 0xFFFFE400
.L08127740: .4byte 0xFFFFEA00
.L08127744: .4byte 0x01000080
.L08127748:
	ldrb r0, [r4]
	adds r0, #0x10
	ldr r7, .L081277A8
	movs r1, #0xd
	muls r1, r5, r1
	adds r5, r1, #0
	adds r5, #8
	movs r6, #0
	str r6, [sp]
	adds r1, r7, #0
	movs r2, #0x77
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0812777A
	adds r0, #0x10
	str r6, [sp]
	adds r1, r7, #0
	movs r2, #0x6f
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
.L0812777A:
	str r6, [sp]
	movs r0, #0x2d
	adds r1, r7, #0
	movs r2, #0x5f
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
	str r6, [sp]
	movs r0, #0x30
	adds r1, r7, #0
	movs r2, #0x67
	adds r3, r5, #0
	bl DigitFont_DrawGlyphTinted
.L08127796:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081277A8: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_081277AC
sub_081277AC: @ 0x081277AC
.L081277AC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	movs r0, #0
	mov sb, r0
	adds r0, r4, #0
	bl NumberToDigits
	adds r5, r0, #0
	cmp r4, #0x63
	bls .L081277D4
	movs r1, #8
	mov sb, r1
.L081277D4:
	cmp r7, #4
	bne .L081278C0
	ldr r4, .L081278A4
	ldr r2, .L081278A8
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, .L081278AC
	adds r0, r4, r1
	ldr r2, .L081278B0
	adds r1, r4, r2
	movs r2, #0x80
	bl CpuFastSet
	ldrb r0, [r5]
	adds r0, #0x10
	ldr r1, .L081278B4
	adds r4, r4, r1
	movs r6, #0
	str r6, [sp]
	adds r1, r4, #0
	movs r2, #0xf7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne .L08127816
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq .L08127826
.L08127816:
	ldrb r0, [r5, #1]
	adds r0, #0x10
	str r6, [sp]
	adds r1, r4, #0
	movs r2, #0xef
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
.L08127826:
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L0812783C
	adds r0, #0x10
	ldr r1, .L081278B8
	movs r2, #0
	str r2, [sp]
	movs r2, #0xe7
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
.L0812783C:
	ldr r4, .L081278B8
	movs r2, #0xdf
	mov r0, sb
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0
	str r5, [sp]
	movs r0, #0x28
	adds r1, r4, #0
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	movs r2, #0xe7
	mov r1, sb
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	movs r0, #0x30
	adds r1, r4, #0
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r4, r2
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r4, r2
	movs r2, #0x80
	bl CpuFastSet
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x80
	bl CpuFastSet
	str r5, [sp, #4]
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r2, .L081278BC
	add r0, sp, #4
	adds r1, r4, #0
	bl CpuFastSet
	b .L0812794E
.L081278A4: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L081278A8: .4byte 0xFFFFEE00
.L081278AC: .4byte 0xFFFFE600
.L081278B0: .4byte 0xFFFFF200
.L081278B4: .4byte 0xFFFFE400
.L081278B8: .4byte 0x030000B4 @ IWRAM+0xB4
.L081278BC: .4byte 0x01000080
.L081278C0:
	ldrb r0, [r5]
	adds r0, #0x10
	ldr r1, .L0812795C
	mov r8, r1
	movs r1, #0xd
	muls r1, r7, r1
	adds r4, r1, #0
	adds r4, #8
	movs r6, #0
	str r6, [sp]
	mov r1, r8
	movs r2, #0x77
	adds r3, r4, #0
	bl DigitFont_DrawGlyphTinted
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne .L081278EA
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq .L081278FA
.L081278EA:
	ldrb r0, [r5, #1]
	adds r0, #0x10
	str r6, [sp]
	mov r1, r8
	movs r2, #0x6f
	adds r3, r4, #0
	bl DigitFont_DrawGlyphTinted
.L081278FA:
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L08127916
	adds r0, #0x10
	ldr r1, .L0812795C
	movs r2, #0xd
	adds r3, r7, #0
	muls r3, r2, r3
	adds r3, #8
	movs r2, #0
	str r2, [sp]
	movs r2, #0x67
	bl DigitFont_DrawGlyphTinted
.L08127916:
	ldr r6, .L0812795C
	movs r2, #0x5f
	mov r0, sb
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xd
	adds r4, r7, #0
	muls r4, r0, r4
	adds r4, #8
	movs r5, #0
	str r5, [sp]
	movs r0, #0x28
	adds r1, r6, #0
	adds r3, r4, #0
	bl DigitFont_DrawGlyphTinted
	movs r2, #0x67
	mov r1, sb
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	movs r0, #0x30
	adds r1, r6, #0
	adds r3, r4, #0
	bl DigitFont_DrawGlyphTinted
.L0812794E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812795C: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_08127960
sub_08127960: @ 0x08127960
.L08127960:
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_08126D1C
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r5, #0xc]
	strh r0, [r5, #0xe]
	strh r0, [r5, #0x16]
	strh r0, [r5, #0x18]
	strh r4, [r5, #0x12]
	ldrh r1, [r5, #0x12]
	ldrh r0, [r5, #0xa]
	subs r0, #1
	cmp r1, r0
	ble .L0812798A
	strh r0, [r5, #0x12]
.L0812798A:
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x10]
	bl __udivsi3
	strh r0, [r5, #0x16]
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x10]
	bl __umodsi3
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x12]
	ldrh r2, [r5, #0x10]
	adds r3, r1, #0
	ldrh r4, [r5, #0xc]
	cmp r0, r4
	blo .L081279BA
	ldrh r0, [r5, #0xc]
	adds r0, r0, r2
	subs r0, #1
	cmp r1, r0
	ble .L081279BC
	adds r0, r1, #1
	subs r0, r0, r2
.L081279BA:
	strh r0, [r5, #0xc]
.L081279BC:
	ldrh r1, [r5, #0xc]
	ldrh r0, [r5, #0xa]
	subs r0, r0, r2
	cmp r1, r0
	ble .L081279C8
	strh r0, [r5, #0xc]
.L081279C8:
	ldrh r0, [r5, #0xc]
	subs r0, r3, r0
	strh r0, [r5, #0xe]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_081279D4
sub_081279D4: @ 0x081279D4
.L081279D4:
	push {r4, r5, lr}
	ldr r4, .L08127A0C
	ldr r3, .L08127A10
	ldr r2, .L08127A14
	ldr r0, .L08127A18
	movs r1, #0
	strb r1, [r0]
	strb r1, [r2]
	strb r1, [r3]
	strb r1, [r4]
	ldr r0, .L08127A1C
	movs r3, #0x3f
	strb r3, [r0]
	ldr r5, .L08127A20
	ldr r4, .L08127A24
	ldr r2, .L08127A28
	ldr r0, .L08127A2C
	strb r1, [r0]
	strb r1, [r2]
	strb r1, [r4]
	strb r1, [r5]
	ldr r0, .L08127A30
	strb r3, [r0]
	ldr r0, .L08127A34
	strb r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08127A0C: .4byte 0x03000030 @ IWRAM+0x30
.L08127A10: .4byte 0x03000031 @ IWRAM+0x31
.L08127A14: .4byte 0x03000035 @ IWRAM+0x35
.L08127A18: .4byte 0x03000034 @ IWRAM+0x34
.L08127A1C: .4byte 0x03000038 @ IWRAM+0x38
.L08127A20: .4byte 0x03000032 @ IWRAM+0x32
.L08127A24: .4byte 0x03000033 @ IWRAM+0x33
.L08127A28: .4byte 0x03000037 @ IWRAM+0x37
.L08127A2C: .4byte 0x03000036 @ IWRAM+0x36
.L08127A30: .4byte 0x03000039 @ IWRAM+0x39
.L08127A34: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_08127A38
sub_08127A38: @ 0x08127A38
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r1, .L08127A94
	ldrh r0, [r1]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	ldrh r0, [r1, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	ldrh r0, [r1, #6]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	ldrh r0, [r1, #8]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	ldrh r0, [r1, #0xa]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	ldrh r0, [r1, #0xc]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08127A8E
	movs r0, #1
	strh r0, [r2, #0x1c]
.L08127A8E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08127A94: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_08127A98
sub_08127A98: @ 0x08127A98
.L08127A98:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L08127AC4
	mov r8, r1
	movs r5, #0xb4
	lsls r5, r5, #2
	add r5, r8
	movs r7, #0
	cmp r0, #9
	bls .L08127ABA
	b .L08127D58
.L08127ABA:
	lsls r0, r0, #2
	ldr r1, .L08127AC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08127AC4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08127AC8: .4byte gUnknown_08127ACC
	.global gUnknown_08127ACC
gUnknown_08127ACC:
.L08127ACC: @ jump table
	.4byte .L08127AF4
	.4byte .L08127B2C
	.4byte .L08127B5E
	.4byte .L08127B8C
	.4byte .L08127BBE
	.4byte .L08127BF2
	.4byte .L08127C14
	.4byte .L08127C46
	.4byte .L08127CB8
	.4byte .L08127CEC
.L08127AF4:
	movs r4, #0
.L08127AF6:
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r4, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L08127B16
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127B16:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127AF6
	ldr r1, .L08127B28
	adds r0, r1, #0
	b .L08127D56
	.byte 0x00, 0x00
.L08127B28: .4byte 0x0000FFFF
.L08127B2C:
	movs r4, #0
	movs r6, #0xc0
	lsls r6, r6, #8
.L08127B32:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, r6
	bne .L08127B52
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127B52:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127B32
	b .L08127D52
.L08127B5E:
	movs r4, #4
.L08127B60:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L08127B80
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127B80:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127B60
	b .L08127D52
.L08127B8C:
	movs r4, #4
	movs r6, #0xc0
	lsls r6, r6, #8
.L08127B92:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, r6
	bne .L08127BB2
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127BB2:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127B92
	b .L08127D52
.L08127BBE:
	movs r4, #4
	movs r0, #0x80
	lsls r0, r0, #8
	mov r8, r0
	adds r6, r0, #0
.L08127BC8:
	mov r1, r8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, r6
	bne .L08127BE6
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127BE6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127BC8
	b .L08127D52
.L08127BF2:
	movs r4, #0
.L08127BF4:
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xff
	bls .L08127BF4
	ldr r1, .L08127C10
	adds r0, r1, #0
	b .L08127D56
	.byte 0x00, 0x00
.L08127C10: .4byte 0x0000FFFF
.L08127C14:
	movs r4, #0
	movs r6, #0xc0
	lsls r6, r6, #8
.L08127C1A:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, r6
	bne .L08127C3A
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127C3A:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #3
	bls .L08127C1A
	b .L08127D52
.L08127C46:
	movs r4, #4
	movs r0, #0x80
	lsls r0, r0, #8
	mov sl, r0
	mov sb, r0
.L08127C50:
	mov r1, sl
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	adds r6, r4, #1
	str r6, [sp]
	cmp r0, sb
	bne .L08127CAC
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L08127CAC
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	bne .L08127CAC
	movs r3, #0
	movs r1, #0
	movs r2, #0xef
	lsls r2, r2, #4
	add r2, r8
.L08127C86:
	lsls r0, r1, #1
	adds r0, r2, r0
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r4
	bne .L08127C94
	movs r3, #1
.L08127C94:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls .L08127C86
	cmp r3, #1
	beq .L08127CAC
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127CAC:
	ldr r1, [sp]
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127C50
	b .L08127D52
.L08127CB8:
	movs r4, #4
.L08127CBA:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L08127CE0
	ldrh r0, [r1, #0x10]
	cmp r0, #0
	bne .L08127CE0
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127CE0:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127CBA
	b .L08127D52
.L08127CEC:
	movs r4, #4
	movs r0, #0x80
	lsls r0, r0, #8
	mov sl, r0
	mov sb, r0
.L08127CF6:
	mov r1, sl
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	adds r6, r4, #1
	str r6, [sp]
	cmp r0, sb
	bne .L08127D48
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #1
	bne .L08127D48
	movs r3, #0
	movs r1, #0
	movs r2, #0xef
	lsls r2, r2, #4
	add r2, r8
.L08127D22:
	lsls r0, r1, #1
	adds r0, r2, r0
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r4
	bne .L08127D30
	movs r3, #1
.L08127D30:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls .L08127D22
	cmp r3, #1
	beq .L08127D48
	strh r4, [r5]
	adds r5, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08127D48:
	ldr r1, [sp]
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L08127CF6
.L08127D52:
	ldr r6, .L08127D6C
	adds r0, r6, #0
.L08127D56:
	strh r0, [r5]
.L08127D58:
	adds r0, r7, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08127D6C: .4byte 0x0000FFFF

	thumb_func_start sub_08127D70
sub_08127D70: @ 0x08127D70
	push {r4, lr}
	ldr r1, .L08127DE0
	ldr r0, .L08127DE4
	str r0, [r1]
	ldr r0, .L08127DE8
	str r0, [r1, #4]
	ldr r0, .L08127DEC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	ldr r3, .L08127DF0
	ldr r4, .L08127DF4
	cmp r0, #0
	bge .L08127D98
.L08127D90:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127D90
.L08127D98:
	ldr r1, .L08127DE0
	str r3, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L08127DF8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127DBA
.L08127DB2:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127DB2
.L08127DBA:
	ldr r1, .L08127DE0
	str r4, [r1]
	ldr r0, .L08127DFC
	str r0, [r1, #4]
	ldr r0, .L08127E00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127DDA
.L08127DD2:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127DD2
.L08127DDA:
	pop {r4}
	pop {r0}
	bx r0
.L08127DE0: .4byte 0x040000D4 @ REG_DMA3SAD
.L08127DE4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L08127DE8: .4byte 0x06001000 @ VRAM+0x1000
.L08127DEC: .4byte 0x84000200
.L08127DF0: .4byte gUnknown_08770C54
.L08127DF4: .4byte 0x030000B4 @ IWRAM+0xB4
.L08127DF8: .4byte 0x840000A0
.L08127DFC: .4byte 0x06006000 @ VRAM+0x6000
.L08127E00: .4byte 0x84000800

	thumb_func_start sub_08127E04
sub_08127E04: @ 0x08127E04
	push {r4, lr}
	ldr r1, .L08127E74
	ldr r0, .L08127E78
	str r0, [r1]
	ldr r0, .L08127E7C
	str r0, [r1, #4]
	ldr r0, .L08127E80
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	ldr r3, .L08127E84
	ldr r4, .L08127E88
	cmp r0, #0
	bge .L08127E2C
.L08127E24:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127E24
.L08127E2C:
	ldr r1, .L08127E74
	str r3, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L08127E8C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127E4E
.L08127E46:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127E46
.L08127E4E:
	ldr r1, .L08127E74
	str r4, [r1]
	ldr r0, .L08127E90
	str r0, [r1, #4]
	ldr r0, .L08127E94
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08127E6E
.L08127E66:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08127E66
.L08127E6E:
	pop {r4}
	pop {r0}
	bx r0
.L08127E74: .4byte 0x040000D4 @ REG_DMA3SAD
.L08127E78: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L08127E7C: .4byte 0x06001000 @ VRAM+0x1000
.L08127E80: .4byte 0x84000200
.L08127E84: .4byte gUnknown_08772294
.L08127E88: .4byte 0x030000B4 @ IWRAM+0xB4
.L08127E8C: .4byte 0x840000A0
.L08127E90: .4byte 0x06006000 @ VRAM+0x6000
.L08127E94: .4byte 0x84000800

	thumb_func_start sub_08127E98
sub_08127E98: @ 0x08127E98
.L08127E98:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x67
	bhi .L08127EA6
	movs r0, #0
	b .L08127EA8
.L08127EA6:
	movs r0, #1
.L08127EA8:
	pop {r1}
	bx r1

	thumb_func_start sub_08127EAC
sub_08127EAC: @ 0x08127EAC
.L08127EAC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldr r0, .L08127EE4
	mov sb, r0
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldr r1, .L08127EE8
	ldr r2, .L08127EEC
	bl CpuFastSet
	cmp r4, #8
	bls .L08127ED8
	b .L08128332
.L08127ED8:
	lsls r0, r4, #2
	ldr r1, .L08127EF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08127EE4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08127EE8: .4byte 0x030000B4 @ IWRAM+0xB4
.L08127EEC: .4byte 0x01000800
.L08127EF0: .4byte gUnknown_08127EF4
	.global gUnknown_08127EF4
gUnknown_08127EF4:
.L08127EF4: @ jump table
	.4byte .L08127F18
	.4byte .L08127F98
	.4byte .L08128332
	.4byte .L0812801C
	.4byte .L08128094
	.4byte .L081280FC
	.4byte .L081281A8
	.4byte .L08128234
	.4byte .L08128290
.L08127F18:
	movs r6, #0
	lsls r1, r7, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L08127F58
	cmp r4, r0
	bne .L08127F2E
	b .L08128332
.L08127F2E:
	adds r5, r0, #0
.L08127F30:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	ldrb r0, [r1, #0xc]
	cmp r0, #3
	bhi .L08127F5C
	adds r0, r1, #0
	mov r1, sp
	bl Combatant_DecodeName
	mov r0, sp
	adds r1, r6, #0
	bl sub_081272CC
	b .L08127F6A
.L08127F58: .4byte 0x0000FFFF
.L08127F5C:
	ldrh r0, [r1, #0x12]
	bl sub_080BF648
	adds r0, #0x22
	adds r1, r6, #0
	bl sub_081272CC
.L08127F6A:
	ldr r0, .L08127F94
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L08127F7E
	b .L08128332
.L08127F7E:
	adds r1, r6, r7
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, r5
	bne .L08127F30
	b .L08128332
	.byte 0x00, 0x00
.L08127F94: .4byte sub_08127D70
.L08127F98:
	movs r6, #0
	lsls r1, r7, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L08127FD4
	cmp r4, r0
	bne .L08127FAE
	b .L08128332
.L08127FAE:
	adds r5, r0, #0
.L08127FB0:
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08127FE0
	ldr r0, .L08127FD8
	adds r1, r6, #0
	movs r2, #2
	bl sub_08127394
	ldr r0, .L08127FDC
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L08127FF6
	.byte 0x00, 0x00
.L08127FD4: .4byte 0x0000FFFF
.L08127FD8: .4byte gUnknown_08777D44
.L08127FDC: .4byte sub_08127D70
.L08127FE0:
	adds r0, r4, #0
	bl sub_080BF648
	adds r0, #0x22
	adds r1, r6, #0
	bl sub_081272CC
	ldr r0, .L08128018
	movs r1, #1
	bl VBlankTask_AddCounted
.L08127FF6:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L08128002
	b .L08128332
.L08128002:
	adds r1, r6, r7
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, r5
	bne .L08127FB0
	b .L08128332
	.byte 0x00, 0x00
.L08128018: .4byte sub_08127D70
.L0812801C:
	movs r6, #0
	lsls r1, r7, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L0812808C
	cmp r4, r0
	bne .L08128032
	b .L08128332
.L08128032:
	mov r8, r0
.L08128034:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	movs r5, #0
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	bl sub_080C29B0
	cmp r0, #0
	beq .L08128054
	movs r5, #6
.L08128054:
	ldrh r0, [r4, #0x12]
	bl sub_080BF648
	adds r0, #0x22
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_08127394
	ldr r0, .L08128090
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L08128078
	b .L08128332
.L08128078:
	adds r1, r6, r7
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, r8
	bne .L08128034
	b .L08128332
.L0812808C: .4byte 0x0000FFFF
.L08128090: .4byte sub_08127D70
.L08128094:
	movs r6, #0
	lsls r1, r7, #2
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L081280F4
	cmp r4, r0
	bne .L081280AA
	b .L08128332
.L081280AA:
	movs r5, #0xb4
	lsls r5, r5, #2
	add r5, sb
	mov r8, r0
.L081280B2:
	adds r0, r4, #0
	bl Action_GetRecord
	adds r0, #0xc
	adds r1, r6, #0
	bl sub_081272CC
	adds r0, r6, r7
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	adds r1, r6, #0
	bl sub_0812745C
	ldr r0, .L081280F8
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L081280E6
	b .L08128332
.L081280E6:
	adds r0, r6, r7
	lsls r0, r0, #2
	adds r0, r5, r0
	ldrh r4, [r0]
	cmp r4, r8
	bne .L081280B2
	b .L08128332
.L081280F4: .4byte 0x0000FFFF
.L081280F8: .4byte sub_08127E04
.L081280FC:
	movs r0, #0xff
	mov sl, r0
	mov r1, sl
	ands r1, r7
	mov sl, r1
	lsrs r7, r7, #8
	movs r6, #0
	lsls r0, r1, #2
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, sb
	adds r1, r1, r0
	ldrh r4, [r1]
	ldr r0, .L0812812C
	cmp r4, r0
	bne .L0812811E
	b .L08128332
.L0812811E:
	cmp r4, #0x7f
	bhi .L08128130
	adds r0, r4, #0
	bl sub_080BF32C
	adds r0, #0x14
	b .L0812814A
.L0812812C: .4byte 0x0000FFFF
.L08128130:
	cmp r4, #0xcf
	bhi .L0812813E
	adds r0, r4, #0
	bl Equipment_GetRecord36_MidRange
	adds r0, #0x14
	b .L0812814A
.L0812813E:
	cmp r4, #0xfe
	bhi .L0812814C
	adds r0, r4, #0
	bl Action_GetRecord
	adds r0, #0xc
.L0812814A:
	mov r8, r0
.L0812814C:
	movs r5, #0
	cmp r4, r7
	bne .L08128154
	movs r5, #2
.L08128154:
	mov r0, r8
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_08127394
	mov r2, sl
	adds r0, r6, r2
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	movs r4, #0xb4
	lsls r4, r4, #2
	add r4, sb
	adds r0, r4, r0
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_0812756C
	ldr r0, .L081281A0
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L0812818E
	b .L08128332
.L0812818E:
	mov r1, sl
	adds r0, r6, r1
	lsls r0, r0, #2
	adds r0, r4, r0
	ldrh r4, [r0]
	ldr r0, .L081281A4
	cmp r4, r0
	bne .L0812811E
	b .L08128332
.L081281A0: .4byte sub_08127E04
.L081281A4: .4byte 0x0000FFFF
.L081281A8:
	movs r6, #0
	lsls r1, r7, #2
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L081281CC
	cmp r4, r0
	bne .L081281BE
	b .L08128332
.L081281BE:
	mov r8, r0
.L081281C0:
	cmp r4, #0x7f
	bhi .L081281D0
	adds r0, r4, #0
	bl sub_080BF32C
	b .L081281DA
.L081281CC: .4byte 0x0000FFFF
.L081281D0:
	cmp r4, #0xcf
	bhi .L081281E0
	adds r0, r4, #0
	bl Equipment_GetRecord36_MidRange
.L081281DA:
	adds r5, r0, #0
	adds r5, #0x14
	b .L081281EE
.L081281E0:
	cmp r4, #0xfe
	bhi .L081281EE
	adds r0, r4, #0
	bl Action_GetRecord
	adds r5, r0, #0
	adds r5, #0xc
.L081281EE:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_081272CC
	adds r0, r6, r7
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	movs r4, #0xb4
	lsls r4, r4, #2
	add r4, sb
	adds r0, r4, r0
	ldrh r0, [r0]
	adds r1, r6, #0
	bl sub_0812745C
	ldr r0, .L08128230
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bls .L08128222
	b .L08128332
.L08128222:
	adds r0, r6, r7
	lsls r0, r0, #2
	adds r0, r4, r0
	ldrh r4, [r0]
	cmp r4, r8
	bne .L081281C0
	b .L08128332
.L08128230: .4byte sub_08127E04
.L08128234:
	movs r6, #0
	lsls r1, r7, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L08128288
	cmp r4, r0
	beq .L08128332
	adds r5, r0, #0
.L0812824A:
	adds r0, r4, #0
	bl sub_080BF5C0
	adds r4, r0, #0
	adds r0, r4, #6
	adds r1, r6, #0
	bl sub_081272CC
	ldrb r0, [r4, #3]
	adds r1, r6, #0
	bl sub_08127678
	ldr r0, .L0812828C
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bhi .L08128332
	adds r1, r6, r7
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, r5
	bne .L0812824A
	b .L08128332
.L08128288: .4byte 0x0000FFFF
.L0812828C: .4byte sub_08127E04
.L08128290:
	movs r6, #0
	lsls r0, r7, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, sb
	adds r1, r1, r0
	ldrh r4, [r1]
	ldr r0, .L081282F8
	cmp r4, r0
	beq .L08128332
	ldr r2, .L081282FC
	mov r8, r2
.L081282A8:
	adds r0, r4, #0
	bl sub_080BF5C0
	adds r5, r0, #0
	adds r0, r5, #6
	adds r1, r6, #0
	bl sub_081272CC
	adds r0, r4, #0
	bl sub_08127E98
	cmp r0, #1
	bne .L08128304
	ldr r1, .L08128300
	add r1, sb
	movs r0, #0xa2
	lsls r0, r0, #4
	add r0, r8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	ldrb r1, [r5, #3]
	lsrs r0, r0, #9
	add r0, r8
	movs r2, #0x1a
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	movs r1, #0x64
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl sub_081277AC
	b .L0812830C
	.byte 0x00, 0x00
.L081282F8: .4byte 0x0000FFFF
.L081282FC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08128300: .4byte 0x00000691
.L08128304:
	ldrb r0, [r5, #3]
	adds r1, r6, #0
	bl sub_08127678
.L0812830C:
	ldr r0, .L08128344
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bhi .L08128332
	adds r0, r6, r7
	lsls r0, r0, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, sb
	adds r1, r1, r0
	ldrh r4, [r1]
	ldr r0, .L08128348
	cmp r4, r0
	bne .L081282A8
.L08128332:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128344: .4byte sub_08127E04
.L08128348: .4byte 0x0000FFFF

	thumb_func_start sub_0812834C
sub_0812834C: @ 0x0812834C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L08128380
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L08128384
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08128378
.L08128370:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08128370
.L08128378:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128380: .4byte 0x040000D4 @ REG_DMA3SAD
.L08128384: .4byte 0x850000A0

	thumb_func_start sub_08128388
sub_08128388: @ 0x08128388
.L08128388:
	push {lr}
	ldr r0, .L08128398
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128398: .4byte sub_0812834C

	thumb_func_start sub_0812839C
sub_0812839C: @ 0x0812839C
.L0812839C:
	push {r4, lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	bl sub_080C29B0
	adds r1, r0, #0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #5
	lsls r0, r1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_081283C4
sub_081283C4: @ 0x081283C4
.L081283C4:
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	ldr r0, .L08128438
	lsrs r1, r1, #0xf
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	ldrh r5, [r1]
	ldr r0, .L0812843C
	cmp r5, r0
	bne .L081283E4
	b .L081284F4
.L081283E4:
	movs r4, #0
.L081283E6:
	movs r0, #0
	str r0, [sp]
	adds r1, r4, #2
	lsls r1, r1, #5
	adds r1, #0x10
	lsls r1, r1, #5
	ldr r0, .L08128440
	adds r1, r1, r0
	mov r0, sp
	ldr r2, .L08128444
	bl CpuFastSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls .L081283E6
	cmp r6, #0
	bne .L08128448
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	ldrh r1, [r4, #0x1a]
	bl sub_081284FC
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	bl sub_08128634
	ldrh r0, [r4, #0x10]
	ldrb r1, [r4, #0xc]
	bl sub_08128828
	b .L081284F4
	.byte 0x00, 0x00
.L08128438: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812843C: .4byte 0x0000FFFF
.L08128440: .4byte 0x030000B4 @ IWRAM+0xB4
.L08128444: .4byte 0x01000080
.L08128448:
	cmp r6, #1
	bne .L0812846E
	adds r0, r5, #0
	bl sub_080BF648
	adds r4, r0, #0
	ldrh r1, [r4, #2]
	adds r0, r1, #0
	bl sub_081284FC
	ldrh r1, [r4, #4]
	adds r0, r1, #0
	bl sub_08128634
	movs r0, #0
	movs r1, #4
	bl sub_08128828
	b .L081284F4
.L0812846E:
	cmp r6, #2
	bne .L081284B0
	ldr r0, .L08128498
	ands r0, r5
	bl sub_080BF648
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r5, r0
	cmp r5, #0
	beq .L081284A0
	movs r0, #1
	rsbs r0, r0, #0
	bl Menu_DrawLabeledName
	ldr r0, .L0812849C
	bl sub_08128AAC
	b .L081284F4
	.byte 0x00, 0x00
.L08128498: .4byte 0x00007FFF
.L0812849C: .4byte 0x0000FFFF
.L081284A0:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl Menu_DrawLabeledName
	ldrb r0, [r4, #1]
	bl sub_08128AAC
	b .L081284F4
.L081284B0:
	cmp r6, #3
	bne .L081284F4
	movs r6, #0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	ldrh r1, [r4, #0x1a]
	bl sub_081284FC
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	bl sub_08128634
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	bl sub_080C29B0
	cmp r0, #0
	beq .L081284E4
	movs r6, #6
.L081284E4:
	adds r0, r5, #0
	bl sub_0812839C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl sub_0812876C
.L081284F4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_081284FC
sub_081284FC: @ 0x081284FC
.L081284FC:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldr r6, .L08128630
	movs r5, #4
	str r5, [sp]
	movs r0, #0x28
	adds r1, r6, #0
	movs r2, #3
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	str r5, [sp]
	movs r0, #0x30
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	movs r5, #0
	str r5, [sp]
	movs r0, #0xf
	adds r1, r6, #0
	movs r2, #0x3d
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	adds r0, r4, #0
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r1, #1]
	ldrb r0, [r2, #1]
	strb r0, [r1, #2]
	adds r0, r1, #0
	ldrb r0, [r0]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x35
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	add r0, sp, #4
	ldrb r1, [r0, #1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	movs r0, #0
	cmp r1, #0
	bne .L0812857E
	add r0, sp, #4
	ldrb r1, [r0, #2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L0812857E:
	orrs r2, r0
	cmp r2, #0
	beq .L08128596
	add r0, sp, #4
	ldrb r0, [r0, #1]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x2d
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
.L08128596:
	add r0, sp, #4
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L081285B0
	add r0, sp, #4
	ldrb r0, [r0, #2]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x25
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
.L081285B0:
	adds r0, r7, #0
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r1, #1]
	ldrb r0, [r2, #1]
	strb r0, [r1, #2]
	adds r0, r1, #0
	ldrb r0, [r0]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	add r0, sp, #4
	ldrb r1, [r0, #1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	movs r0, #0
	cmp r1, #0
	bne .L081285F4
	add r0, sp, #4
	ldrb r1, [r0, #2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L081285F4:
	orrs r2, r0
	cmp r2, #0
	beq .L0812860C
	add r0, sp, #4
	ldrb r0, [r0, #1]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x4d
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
.L0812860C:
	add r0, sp, #4
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L08128626
	add r0, sp, #4
	ldrb r0, [r0, #2]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x45
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
.L08128626:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128630: .4byte 0x03000AB4 @ IWRAM+0xAB4

	thumb_func_start sub_08128634
sub_08128634: @ 0x08128634
.L08128634:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldr r6, .L08128768
	movs r5, #4
	str r5, [sp]
	movs r0, #0x2d
	adds r1, r6, #0
	movs r2, #3
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
	str r5, [sp]
	movs r0, #0x30
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
	movs r5, #0
	str r5, [sp]
	movs r0, #0xf
	adds r1, r6, #0
	movs r2, #0x3d
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
	adds r0, r4, #0
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r1, #1]
	ldrb r0, [r2, #1]
	strb r0, [r1, #2]
	adds r0, r1, #0
	ldrb r0, [r0]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x35
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
	add r0, sp, #4
	ldrb r1, [r0, #1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	movs r0, #0
	cmp r1, #0
	bne .L081286B6
	add r0, sp, #4
	ldrb r1, [r0, #2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L081286B6:
	orrs r2, r0
	cmp r2, #0
	beq .L081286CE
	add r0, sp, #4
	ldrb r0, [r0, #1]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x2d
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
.L081286CE:
	add r0, sp, #4
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L081286E8
	add r0, sp, #4
	ldrb r0, [r0, #2]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x25
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
.L081286E8:
	adds r0, r7, #0
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r1, #1]
	ldrb r0, [r2, #1]
	strb r0, [r1, #2]
	adds r0, r1, #0
	ldrb r0, [r0]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
	add r0, sp, #4
	ldrb r1, [r0, #1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	movs r0, #0
	cmp r1, #0
	bne .L0812872C
	add r0, sp, #4
	ldrb r1, [r0, #2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L0812872C:
	orrs r2, r0
	cmp r2, #0
	beq .L08128744
	add r0, sp, #4
	ldrb r0, [r0, #1]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x4d
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
.L08128744:
	add r0, sp, #4
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L0812875E
	add r0, sp, #4
	ldrb r0, [r0, #2]
	adds r0, #0x10
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #0x45
	movs r3, #0x12
	bl DigitFont_DrawGlyphTinted
.L0812875E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128768: .4byte 0x03000AB4 @ IWRAM+0xAB4

	thumb_func_start sub_0812876C
sub_0812876C: @ 0x0812876C
.L0812876C:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r5, .L081287E8
	movs r4, #4
	str r4, [sp]
	movs r0, #0x23
	adds r1, r5, #0
	movs r2, #3
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0x2f
	adds r1, r5, #0
	movs r2, #0xb
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0x33
	adds r1, r5, #0
	movs r2, #0x13
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0x34
	adds r1, r5, #0
	movs r2, #0x1b
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	adds r0, r6, #0
	bl NumberToDigits
	add r2, sp, #4
	ldrb r1, [r0]
	strb r1, [r2]
	adds r0, #1
	ldrb r1, [r0]
	strb r1, [r2, #1]
	adds r0, #1
	ldrb r1, [r0]
	strb r1, [r2, #2]
	adds r1, r2, #0
	ldrb r0, [r0, #1]
	strb r0, [r1, #3]
	movs r3, #4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08128818
	adds r0, r1, #0
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L081287EC
	movs r3, #3
	b .L081287F2
.L081287E8: .4byte 0x03000AB4 @ IWRAM+0xAB4
.L081287EC:
	adds r0, r1, #0
	ldrb r0, [r0, #1]
	movs r3, #2
.L081287F2:
	subs r4, r3, #1
	mov r0, sp
	adds r0, r0, r4
	adds r0, #4
	ldrb r0, [r0]
	adds r0, #0x10
	ldr r1, .L08128824
	movs r2, #0xb
	subs r2, r2, r3
	lsls r2, r2, #3
	adds r2, #5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r7, [sp]
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	lsls r4, r4, #0x18
	lsrs r3, r4, #0x18
.L08128818:
	cmp r3, #0
	bne .L081287F2
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08128824: .4byte 0x03000AB4 @ IWRAM+0xAB4

	thumb_func_start sub_08128828
sub_08128828: @ 0x08128828
.L08128828:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldr r4, .L0812886C
	movs r6, #4
	str r6, [sp]
	movs r0, #0x33
	adds r1, r4, #0
	movs r2, #3
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	str r6, [sp]
	movs r0, #0x34
	adds r1, r4, #0
	movs r2, #0xb
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L08128874
	ldr r4, .L08128870
	cmp r7, #3
	bls .L08128866
	b .L0812897C
.L08128866:
	adds r4, #8
	b .L0812897C
	.byte 0x00, 0x00
.L0812886C: .4byte 0x03000AB4 @ IWRAM+0xAB4
.L08128870: .4byte gUnknown_08777D54
.L08128874:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L08128888
	ldr r4, .L08128884
	b .L0812897C
	.byte 0x00, 0x00
.L08128884: .4byte gUnknown_08777D64
.L08128888:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L0812889C
	ldr r4, .L08128898
	b .L0812897C
	.byte 0x00, 0x00
.L08128898: .4byte gUnknown_08777D6C
.L0812889C:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L081288B0
	ldr r4, .L081288AC
	b .L0812897C
	.byte 0x00, 0x00
.L081288AC: .4byte gUnknown_08777D74
.L081288B0:
	adds r0, r5, #0
	ands r0, r6
	cmp r0, #0
	beq .L081288C0
	ldr r4, .L081288BC
	b .L0812897C
.L081288BC: .4byte gUnknown_08777DC4
.L081288C0:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L081288D4
	ldr r4, .L081288D0
	b .L0812897C
	.byte 0x00, 0x00
.L081288D0: .4byte gUnknown_08777D7C
.L081288D4:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r5
	cmp r0, #0
	beq .L081288E8
	ldr r4, .L081288E4
	b .L0812897C
	.byte 0x00, 0x00
.L081288E4: .4byte gUnknown_08777D84
.L081288E8:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L081288F8
	ldr r4, .L081288F4
	b .L0812897C
.L081288F4: .4byte gUnknown_08777DD4
.L081288F8:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L0812890C
	ldr r4, .L08128908
	b .L0812897C
	.byte 0x00, 0x00
.L08128908: .4byte gUnknown_08777D8C
.L0812890C:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L0812891C
	ldr r4, .L08128918
	b .L0812897C
.L08128918: .4byte gUnknown_08777DA4
.L0812891C:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L0812892C
	ldr r4, .L08128928
	b .L0812897C
.L08128928: .4byte gUnknown_08777DAC
.L0812892C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08128940
	ldr r4, .L0812893C
	b .L0812897C
	.byte 0x00, 0x00
.L0812893C: .4byte gUnknown_08777D94
.L08128940:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L08128950
	ldr r4, .L0812894C
	b .L0812897C
.L0812894C: .4byte gUnknown_08777D9C
.L08128950:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08128960
	ldr r4, .L0812895C
	b .L0812897C
.L0812895C: .4byte gUnknown_08777DCC
.L08128960:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L08128970
	ldr r4, .L0812896C
	b .L0812897C
.L0812896C: .4byte gUnknown_08777DB4
.L08128970:
	movs r0, #8
	ands r0, r5
	ldr r4, .L081289B0
	cmp r0, #0
	beq .L0812897C
	subs r4, #0x20
.L0812897C:
	movs r5, #0
.L0812897E:
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0812899E
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, #1
	adds r2, r5, #5
	lsls r2, r2, #3
	adds r2, #5
	movs r1, #0
	str r1, [sp]
	ldr r1, .L081289B4
	movs r3, #0x1e
	bl DigitFont_DrawGlyphTinted
.L0812899E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L0812897E
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081289B0: .4byte gUnknown_08777DDC
.L081289B4: .4byte 0x03000AB4 @ IWRAM+0xAB4

	thumb_func_start Menu_DrawLabeledName
Menu_DrawLabeledName: @ 0x081289B8
.L081289B8:
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r6, .L08128A38
	movs r5, #4
	str r5, [sp]
	movs r0, #0x32
	adds r1, r6, #0
	movs r2, #3
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	str r5, [sp]
	movs r0, #0x21
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	str r5, [sp]
	movs r0, #0x23
	adds r1, r6, #0
	movs r2, #0x13
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	str r5, [sp]
	movs r0, #0x25
	adds r1, r6, #0
	movs r2, #0x1b
	movs r3, #6
	bl DigitFont_DrawGlyphTinted
	lsls r4, r4, #0x18
	asrs r1, r4, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08128A3C
	movs r5, #0
.L08128A0C:
	cmp r5, #2
	bls .L08128A2C
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x12
	movs r0, #0x8c
	lsls r0, r0, #0xe
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L08128A38
	movs r3, #3
	bl Font_DrawGlyphTinted
.L08128A2C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls .L08128A0C
	b .L08128A9A
.L08128A38: .4byte 0x03000AB4 @ IWRAM+0xAB4
.L08128A3C:
	ldr r0, .L08128AA4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r4, [r1]
	movs r6, #0
	movs r5, #0
	ldrh r0, [r4]
	cmp r0, #0
	beq .L08128A68
.L08128A4E:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bhi .L08128A68
	lsls r0, r5, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08128A4E
.L08128A68:
	movs r5, #0
	cmp r5, r6
	bhs .L08128A9A
.L08128A6E:
	ldrh r0, [r4]
	adds r4, #2
	adds r1, r5, #5
	subs r1, r1, r6
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #0x12
	movs r1, #0x8c
	lsls r1, r1, #0xe
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L08128AA8
	movs r3, #3
	bl Font_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r6
	blo .L08128A6E
.L08128A9A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128AA4: .4byte gUnknown_08777DE4
.L08128AA8: .4byte 0x03000AB4 @ IWRAM+0xAB4

	thumb_func_start sub_08128AAC
sub_08128AAC: @ 0x08128AAC
.L08128AAC:
	push {r4, r5, r6, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r6, .L08128AFC
	movs r4, #4
	str r4, [sp]
	movs r0, #0x2c
	adds r1, r6, #0
	movs r2, #3
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0x36
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	ldr r0, .L08128B00
	cmp r5, r0
	bne .L08128B04
	movs r4, #0
	str r4, [sp]
	movs r0, #0xd
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xd
	adds r1, r6, #0
	movs r2, #0x4d
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	b .L08128B7C
	.byte 0x00, 0x00
.L08128AFC: .4byte 0x03000AB4 @ IWRAM+0xAB4
.L08128B00: .4byte 0x0000FFFF
.L08128B04:
	adds r0, r5, #0
	bl NumberToDigits
	add r2, sp, #4
	ldrb r1, [r0]
	movs r4, #0
	strb r1, [r2]
	adds r0, #1
	ldrb r1, [r0]
	strb r1, [r2, #1]
	adds r1, r2, #0
	ldrb r0, [r0, #1]
	strb r0, [r1, #2]
	adds r0, r1, #0
	ldrb r0, [r0]
	adds r0, #0x10
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
	add r0, sp, #4
	ldrb r1, [r0, #1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	movs r0, #0
	cmp r1, #0
	bne .L08128B4A
	add r0, sp, #4
	ldrb r1, [r0, #2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L08128B4A:
	orrs r2, r0
	cmp r2, #0
	beq .L08128B62
	add r0, sp, #4
	ldrb r0, [r0, #1]
	adds r0, #0x10
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x4d
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
.L08128B62:
	add r0, sp, #4
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq .L08128B7C
	add r0, sp, #4
	ldrb r0, [r0, #2]
	adds r0, #0x10
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x45
	movs r3, #0x14
	bl DigitFont_DrawGlyphTinted
.L08128B7C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_08128B84
sub_08128B84: @ 0x08128B84
.L08128B84:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r4, .L08128BA0
	movs r0, #0
	str r0, [r4, #0x50]
	str r0, [r4, #0x4c]
	cmp r1, #4
	bhi .L08128C20
	lsls r0, r1, #2
	ldr r1, .L08128BA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08128BA0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08128BA4: .4byte gUnknown_08128BA8
	.global gUnknown_08128BA8
gUnknown_08128BA8:
.L08128BA8: @ jump table
	.4byte .L08128BBC
	.4byte .L08128BCE
	.4byte .L08128BFC
	.4byte .L08128C06
	.4byte .L08128C1C
.L08128BBC:
	bl sub_080C7218
	bl sub_080C7648
	bl sub_080C7C60
	bl BattleMenu_Reset
	b .L08128BDA
.L08128BCE:
	bl sub_080C700C
	bl sub_080C7430
	bl sub_080C7648
.L08128BDA:
	ldr r0, .L08128BF0
	ldr r1, .L08128BF4
	bl Task_Create
	str r0, [r4, #0x40]
	ldr r0, .L08128BF8
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b .L08128C20
	.byte 0x00, 0x00
.L08128BF0: .4byte gUnknown_08777EB8
.L08128BF4: .4byte 0x0000FFFF
.L08128BF8: .4byte 0x00000696
.L08128BFC:
	bl sub_080C7C60
	bl sub_0812A710
	b .L08128C20
.L08128C06:
	ldr r0, .L08128C14
	ldr r1, .L08128C18
	bl Task_Create
	str r0, [r4, #0x40]
	b .L08128C20
	.byte 0x00, 0x00
.L08128C14: .4byte gUnknown_08777EB8
.L08128C18: .4byte 0x0000FFFF
.L08128C1C:
	bl sub_08128EB4
.L08128C20:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08128C28
sub_08128C28: @ 0x08128C28
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L08128C54
	movs r0, #0
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x16]
	movs r0, #0
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrb r0, [r5]
	cmp r0, #4
	bne .L08128C58
	movs r0, #1
	strh r0, [r4, #0x1c]
	bl sub_08128E28
	b .L08128D1E
.L08128C54: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08128C58:
	cmp r0, #3
	bne .L08128CC8
	ldrh r0, [r5, #0x16]
	cmp r0, #5
	bhi .L08128D1E
	lsls r0, r0, #2
	ldr r1, .L08128C6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08128C6C: .4byte gUnknown_08128C70
	.global gUnknown_08128C70
gUnknown_08128C70:
.L08128C70: @ jump table
	.4byte .L08128C88
	.4byte .L08128C9C
	.4byte .L08128CA2
	.4byte .L08128CA8
	.4byte .L08128CB2
	.4byte .L08128CBA
.L08128C88:
	bl sub_08128EB4
	ldr r1, .L08128C98
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	b .L08128CBE
	.byte 0x00, 0x00
.L08128C98: .4byte 0x00000696
.L08128C9C:
	bl sub_0812C0D0
	b .L08128CBE
.L08128CA2:
	bl sub_0812AD70
	b .L08128CBE
.L08128CA8:
	movs r0, #0
	movs r1, #0
	bl sub_080CE258
	b .L08128CBE
.L08128CB2:
	movs r0, #0
	bl sub_0812CC70
	b .L08128CBE
.L08128CBA:
	bl sub_0812CE78
.L08128CBE:
	movs r0, #1
	strh r0, [r4, #0x1c]
	bl sub_08128E80
	b .L08128D1E
.L08128CC8:
	cmp r0, #6
	bne .L08128CFC
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08128CE2
	bl BattleMenu_Reset
	bl BattleMsg_Close
	b .L08128D1E
.L08128CE2:
	bl sub_080EA2AC
	ldr r0, .L08128CF8
	ldrh r1, [r5, #0x16]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L08128D1E
.L08128CF8: .4byte gUnknown_08777EA0
.L08128CFC:
	ldrh r0, [r5, #0x16]
	cmp r6, r0
	beq .L08128D1E
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08128D1E
	ldr r0, .L08128D48
	ldrh r1, [r5, #0x16]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L08128D1E:
	ldr r0, .L08128D4C
	movs r1, #0
	str r1, [sp]
	ldr r2, .L08128D50
	ldrh r1, [r5, #0x16]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128D48: .4byte gUnknown_08777EA0
.L08128D4C: .4byte gUnknown_08000868
.L08128D50: .4byte gUnknown_08777E94

	thumb_func_start sub_08128D54
sub_08128D54: @ 0x08128D54
	push {r4, r5, lr}
	sub sp, #0x2c
	movs r0, #0
	movs r1, #0
	bl sub_08126E4C
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #1
	movs r2, #6
	movs r3, #1
	bl sub_08126928
	ldr r0, .L08128DB4
	movs r5, #0xf0
	strb r5, [r0]
	ldr r0, .L08128DB8
	movs r4, #0
	strb r4, [r0]
	ldr r0, .L08128DBC
	movs r3, #0x5e
	strb r3, [r0]
	ldr r0, .L08128DC0
	movs r2, #0x68
	strb r2, [r0]
	ldr r1, .L08128DC4
	movs r0, #0x1d
	strb r0, [r1]
	ldr r0, .L08128DC8
	strb r5, [r0]
	ldr r0, .L08128DCC
	strb r4, [r0]
	ldr r0, .L08128DD0
	strb r3, [r0]
	ldr r0, .L08128DD4
	strb r2, [r0]
	ldr r1, .L08128DD8
	movs r0, #0x1f
	strb r0, [r1]
	ldr r1, .L08128DDC
	movs r0, #0x3f
	strb r0, [r1]
	add sp, #0x2c
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128DB4: .4byte 0x03000030 @ IWRAM+0x30
.L08128DB8: .4byte 0x03000031 @ IWRAM+0x31
.L08128DBC: .4byte 0x03000035 @ IWRAM+0x35
.L08128DC0: .4byte 0x03000034 @ IWRAM+0x34
.L08128DC4: .4byte 0x03000038 @ IWRAM+0x38
.L08128DC8: .4byte 0x03000032 @ IWRAM+0x32
.L08128DCC: .4byte 0x03000033 @ IWRAM+0x33
.L08128DD0: .4byte 0x03000037 @ IWRAM+0x37
.L08128DD4: .4byte 0x03000036 @ IWRAM+0x36
.L08128DD8: .4byte 0x03000039 @ IWRAM+0x39
.L08128DDC: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_08128DE0
sub_08128DE0: @ 0x08128DE0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r3, .L08128E1C
	ldrb r1, [r3]
	adds r1, #8
	strb r1, [r3]
	ldr r2, .L08128E20
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x77
	bls .L08128E16
	movs r0, #0xf0
	strb r0, [r2]
	strb r0, [r3]
	ldr r1, .L08128E24
	movs r0, #0x1f
	strb r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0x67
	bl sub_080ECF70
.L08128E16:
	pop {r4}
	pop {r0}
	bx r0
.L08128E1C: .4byte 0x03000031 @ IWRAM+0x31
.L08128E20: .4byte 0x03000030 @ IWRAM+0x30
.L08128E24: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_08128E28
sub_08128E28: @ 0x08128E28
.L08128E28:
	push {r4, lr}
	ldr r4, .L08128E60
	movs r0, #0
	bl sub_081269B0
	bl sub_08126F4C
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #4
	bne .L08128E46
	bl BattleMsg_Close
.L08128E46:
	bl sub_081279D4
	ldr r4, .L08128E64
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L08128E68
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L08128E6E
	.byte 0x00, 0x00
.L08128E60: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08128E64: .4byte 0x03004550 @ IWRAM+0x4550
.L08128E68:
	movs r0, #1
	bl Field_SetState
.L08128E6E:
	bl sub_080C7234
	bl sub_080C762C
	bl sub_080C7C94
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08128E80
sub_08128E80: @ 0x08128E80
.L08128E80:
	push {r4, lr}
	ldr r4, .L08128EB0
	bl sub_08126F4C
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #4
	bne .L08128E98
	bl BattleMsg_Close
.L08128E98:
	bl sub_081279D4
	bl sub_080C6FF0
	bl sub_080C7414
	bl sub_080C762C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08128EB0: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_08128EB4
sub_08128EB4: @ 0x08128EB4
.L08128EB4:
	push {r4, r5, lr}
	ldr r4, .L08128F04
	bl sub_080F3190
	adds r5, r0, #0
	cmp r5, #0
	beq .L08128F10
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08128ED6
	bl BattleMenu_Reset
	bl BattleMsg_Close
.L08128ED6:
	ldr r0, .L08128F08
	ldr r1, .L08128F0C
	bl Task_Create
	str r0, [r4, #0x44]
	bl sub_080EA210
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0x68
	bl sub_080C51D4
	b .L08128F1A
	.byte 0x00, 0x00
.L08128F04: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08128F08: .4byte gUnknown_0877812C
.L08128F0C: .4byte 0x0000FFFF
.L08128F10:
	ldr r0, .L08128F20
	ldr r1, .L08128F24
	bl Task_Create
	str r0, [r4, #0x44]
.L08128F1A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L08128F20: .4byte gUnknown_08778000
.L08128F24: .4byte 0x0000FFFF

	thumb_func_start sub_08128F28
sub_08128F28: @ 0x08128F28
	push {lr}
	ldr r1, .L08128F50
	ldr r0, .L08128F54
	str r0, [r1]
	ldr r0, .L08128F58
	str r0, [r1, #4]
	ldr r0, .L08128F5C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L08128F4C
.L08128F44:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L08128F44
.L08128F4C:
	pop {r0}
	bx r0
.L08128F50: .4byte 0x040000D4 @ REG_DMA3SAD
.L08128F54: .4byte 0x030000B4 @ IWRAM+0xB4
.L08128F58: .4byte 0x06015000 @ VRAM+0x15000
.L08128F5C: .4byte 0x84000180

	thumb_func_start sub_08128F60
sub_08128F60: @ 0x08128F60
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, .L08128FE8
	movs r5, #0
	ldr r0, .L08128FEC
	ldr r1, .L08128FF0
	bl sub_080C7E24
	ldr r0, .L08128FF4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r0, #3
	bl Flag_Test
	cmp r0, #0
	beq .L08128FA2
	strh r5, [r4]
	ldr r1, .L08128FF8
	adds r4, r6, r1
	movs r5, #1
	strh r5, [r4]
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #2
	strh r5, [r4]
	adds r1, #4
	adds r4, r6, r1
	movs r5, #3
.L08128FA2:
	movs r0, #3
	strh r0, [r4]
	adds r4, #2
	adds r0, r5, #1
	lsls r0, r0, #0x18
	movs r1, #4
	strh r1, [r4]
	adds r4, #2
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r5, r0, #0x18
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #0
	beq .L08128FD0
	movs r0, #5
	strh r0, [r4]
	adds r4, #2
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L08128FD0:
	ldr r1, .L08128FFC
	adds r0, r1, #0
	strh r0, [r4]
	cmp r5, #2
	bne .L08129000
	movs r0, #1
	str r0, [sp]
	movs r0, #0xa
	movs r1, #1
	movs r2, #0xa
	movs r3, #5
	b .L0812900C
.L08128FE8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08128FEC: .4byte 0x030000B4 @ IWRAM+0xB4
.L08128FF0: .4byte gUnknown_08777F2C
.L08128FF4: .4byte sub_08128F28
.L08128FF8: .4byte 0x000002D2
.L08128FFC: .4byte 0x0000FFFF
.L08129000:
	adds r3, r5, #4
	movs r0, #1
	str r0, [sp]
	movs r0, #0xa
	movs r1, #1
	movs r2, #0xa
.L0812900C:
	bl TextWindow_Create
	str r0, [r6, #0x4c]
	str r5, [sp]
	movs r0, #1
	movs r1, #1
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	ldr r0, [r6, #0x44]
	adds r0, #0x24
	strb r5, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129030
sub_08129030: @ 0x08129030
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, .L08129054
	ldr r3, [r0, #0x4c]
	adds r4, r3, #0
	adds r4, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	cmp r1, #1
	beq .L08129058
	cmp r1, #1
	bhs .L08129060
	ldrh r0, [r3, #0x1e]
	cmp r0, #0xff
	beq .L08129060
	movs r0, #1
	strh r0, [r2, #0x1c]
	b .L08129060
.L08129054: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129058:
	ldrh r0, [r4, #0xa]
	cmp r0, #2
	bne .L08129060
	strh r1, [r2, #0x1c]
.L08129060:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129068
sub_08129068: @ 0x08129068
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L081290CC
	mov r8, r0
	movs r1, #0xc
	str r1, [sp, #0xc]
	ldr r0, [r0, #0x44]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	bne .L0812908C
	movs r2, #0xe
	str r2, [sp, #0xc]
.L0812908C:
	cmp r0, #6
	bne .L08129094
	movs r0, #0xa
	str r0, [sp, #0xc]
.L08129094:
	movs r0, #1
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0x18]
	movs r0, #1
	bl sub_08126A08
	ldrh r1, [r5, #0x18]
	eors r1, r6
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r6, r0, #0x1f
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L081290D0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081290D4
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L08129130
	.byte 0x00, 0x00
.L081290CC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081290D0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081290D4:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L081290F4
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L08129130
.L081290F4:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L08129130
	movs r0, #0xfc
	lsls r0, r0, #3
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08129110
	bl BattleMenu_Reset
	bl BattleMsg_Close
	b .L08129130
.L08129110:
	bl sub_080EA210
	ldr r2, .L08129200
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #4
	bl BattleMenu_SetMode
.L08129130:
	cmp r6, #1
	bne .L0812915C
	movs r0, #0xfc
	lsls r0, r0, #3
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812915C
	ldr r2, .L08129200
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, r8
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812915C:
	ldr r0, .L08129204
	movs r1, #0
	str r1, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r2, [sp, #0xc]
	adds r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r7, #0
	movs r6, #0
	ldr r0, .L08129208
	mov sl, r0
	mov sb, r6
.L0812918C:
	lsls r1, r6, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, r8
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r1, .L0812920C
	cmp r5, r1
	beq .L081291EE
	lsls r5, r5, #4
	mov r2, sl
	adds r0, r5, r2
	mov r1, sb
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #2
	adds r4, #4
	ldr r2, [sp, #0xc]
	adds r4, r2, r4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	ldr r0, .L08129210
	adds r5, r5, r0
	mov r1, sb
	str r1, [sp]
	movs r0, #0x7c
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #5
	bls .L0812918C
.L081291EE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08129200: .4byte gUnknown_08777FE0
.L08129204: .4byte gUnknown_08000E58
.L08129208: .4byte gUnknown_08777F60
.L0812920C: .4byte 0x0000FFFF
.L08129210: .4byte gUnknown_08777F68

	thumb_func_start sub_08129214
sub_08129214: @ 0x08129214
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x1e]
	cmp r0, r1
	bne .L08129222
	movs r0, #1
	b .L08129224
.L08129222:
	movs r0, #0
.L08129224:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812922C
sub_0812922C: @ 0x0812922C
	push {r4, lr}
	ldr r1, .L08129244
	ldr r2, .L08129248
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0812924C
	movs r0, #1
	bl sub_08128B84
	b .L0812928A
	.byte 0x00, 0x00
.L08129244: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129248: .4byte 0x00000696
.L0812924C:
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812925C
	bl BattleMsg_Close
.L0812925C:
	bl sub_081279D4
	ldr r4, .L08129274
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L08129278
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L0812927E
.L08129274: .4byte 0x03004550 @ IWRAM+0x4550
.L08129278:
	movs r0, #1
	bl Field_SetState
.L0812927E:
	bl sub_080C7234
	bl sub_080C762C
	bl sub_080C7C94
.L0812928A:
	movs r0, #1
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129298
sub_08129298: @ 0x08129298
	push {r4, lr}
	ldr r4, .L081292B4
	bl BattleMsg_Close
	ldr r0, .L081292B8
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne .L081292BC
	movs r0, #1
	bl sub_08128B84
	b .L081292DE
	.byte 0x00, 0x00
.L081292B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081292B8: .4byte 0x00000696
.L081292BC:
	bl sub_081279D4
	ldr r4, .L081292D4
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L081292D8
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L081292DE
.L081292D4: .4byte 0x03004550 @ IWRAM+0x4550
.L081292D8:
	movs r0, #1
	bl Field_SetState
.L081292DE:
	movs r0, #1
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081292EC
sub_081292EC: @ 0x081292EC
	push {r4, lr}
	ldr r4, .L08129318
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L081292FC
	movs r1, #0
	bl TextWindow_Close
.L081292FC:
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812930C
	bl BattleMsg_Close
.L0812930C:
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08129318: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812931C
sub_0812931C: @ 0x0812931C
.L0812931C:
	push {r4, r5, r6, lr}
	ldr r0, .L08129354
	movs r3, #0
	movs r1, #0xef
	lsls r1, r1, #4
	adds r6, r0, r1
	ldr r1, .L08129358
	adds r4, r1, #0
	movs r1, #0xf1
	lsls r1, r1, #4
	adds r5, r0, r1
.L08129332:
	lsls r1, r3, #1
	adds r2, r6, r1
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	adds r1, r5, r1
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xf
	bls .L08129332
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08129354: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129358: .4byte 0x0000FFFF

	thumb_func_start sub_0812935C
sub_0812935C: @ 0x0812935C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1e]
	cmp r0, #5
	bhi .L081293EA
	lsls r0, r0, #2
	ldr r1, .L08129370
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08129370: .4byte gUnknown_08129374
	.global gUnknown_08129374
gUnknown_08129374:
.L08129374: @ jump table
	.4byte .L0812938C
	.4byte .L08129398
	.4byte .L0812939E
	.4byte .L081293A4
	.4byte .L081293E0
	.4byte .L081293E6
.L0812938C:
	bl sub_0812931C
	movs r0, #0
	bl sub_081293F8
	b .L081293EA
.L08129398:
	bl sub_08129D58
	b .L081293EA
.L0812939E:
	bl sub_08129FDC
	b .L081293EA
.L081293A4:
	ldr r0, .L081293BC
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L081293C0
	movs r0, #1
	bl sub_080AD6E4
	b .L081293EA
	.byte 0x00, 0x00
.L081293BC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L081293C0:
	bl sub_080EA210
	movs r0, #0x5b
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	b .L081293EA
.L081293E0:
	bl sub_0812E734
	b .L081293EA
.L081293E6:
	bl sub_0812A6F0
.L081293EA:
	movs r0, #1
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081293F8
sub_081293F8: @ 0x081293F8
.L081293F8:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r6, .L08129430
	movs r5, #1
	ands r5, r4
	ldr r0, .L08129434
	ldr r1, .L08129438
	bl Task_Create
	str r0, [r6, #0x48]
	ldr r1, .L0812943C
	adds r0, r6, r1
	strb r4, [r0]
	cmp r5, #1
	beq .L08129422
	cmp r5, #0
	bne .L08129422
	bl sub_080EA210
.L08129422:
	ldr r0, [r6, #0x48]
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08129430: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129434: .4byte gUnknown_08778160
.L08129438: .4byte 0x0000FFFF
.L0812943C: .4byte 0x00000694

	thumb_func_start sub_08129440
sub_08129440: @ 0x08129440
.L08129440:
	push {lr}
	ldr r0, .L08129450
	ldr r1, [r0, #0x48]
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08129454
	movs r0, #0
	b .L0812945A
.L08129450: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129454:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
.L0812945A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08129460
sub_08129460: @ 0x08129460
.L08129460:
	push {r4, r5, r6, lr}
	ldr r4, .L081294A4
	bl sub_080C0FC0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	cmp r3, #5
	bhi .L081294A8
	movs r1, #0
	movs r0, #0xef
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r4, #1
	rsbs r4, r4, #0
.L0812947E:
	lsls r0, r1, #1
	adds r0, r5, r0
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r4
	beq .L08129490
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08129490:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls .L0812947E
	adds r0, r3, r2
	cmp r0, #5
	bgt .L081294A8
	movs r0, #1
	b .L081294AA
.L081294A4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081294A8:
	movs r0, #0
.L081294AA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_081294B0
sub_081294B0: @ 0x081294B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldr r7, .L081294E0
	movs r5, #0
	strh r5, [r6, #0x1e]
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L081294EC
	ldr r0, .L081294E4
	ldrh r4, [r0]
	cmp r4, #1
	bne .L081294EC
	ldr r1, .L081294E8
	movs r0, #3
	bl BattleMenu_SetMode
	strh r4, [r6, #0x1e]
	b .L0812955A
.L081294E0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081294E4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081294E8: .4byte gUnknown_0812410A
.L081294EC:
	ldr r1, .L08129528
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0812952C
	bl sub_080F4504
	adds r4, r0, #0
	bl sub_080F45D4
	cmp r4, r0
	ble .L08129510
	bl sub_080C0FC0
	cmp r0, #5
	ble .L0812952C
.L08129510:
	movs r0, #0x92
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #2
	b .L08129558
.L08129528: .4byte 0x00000694
.L0812952C:
	ldr r1, .L0812953C
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq .L08129540
	movs r0, #7
	b .L08129542
	.byte 0x00, 0x00
.L0812953C: .4byte 0x00000694
.L08129540:
	movs r0, #9
.L08129542:
	bl sub_08127A98
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L08129570
	ldr r1, .L0812956C
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
.L08129558:
	strh r0, [r6, #0x1e]
.L0812955A:
	mov r0, r8
	cmp r0, #0
	bne .L081295C2
	ldr r0, [r7, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
	b .L081295C2
	.byte 0x00, 0x00
.L0812956C: .4byte gUnknown_081240F0
.L08129570:
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r7, #0x50]
	bl sub_081272AC
	cmp r5, #4
	bhi .L081295AA
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	b .L081295BA
.L081295AA:
	movs r0, #5
	str r0, [sp]
	movs r0, #3
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L081295BA:
	ldr r1, .L081295D0
	movs r0, #4
	bl BattleMenu_SetMode
.L081295C2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081295D0: .4byte gUnknown_081240A0

	thumb_func_start sub_081295D4
sub_081295D4: @ 0x081295D4
	push {r4, lr}
	movs r0, #3
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #3
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #3
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_081295F4
sub_081295F4: @ 0x081295F4
	push {lr}
	movs r0, #1
	movs r1, #0
	bl sub_080D3654
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129604
sub_08129604: @ 0x08129604
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sl, r1
	ldr r0, .L08129660
	mov r8, r0
	movs r0, #3
	bl sub_08126D1C
	adds r7, r0, #0
	ldrb r1, [r7, #0x12]
	str r1, [sp, #0xc]
	movs r0, #3
	bl sub_08126A08
	movs r0, #0
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x1c]
	ldr r0, .L08129664
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L08129668
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
	mov r2, sl
	cmp r2, #0
	bne .L0812965A
	mov r1, r8
	ldr r0, [r1, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
.L0812965A:
	bl sub_080D3688
	b .L0812979C
.L08129660: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129664: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08129668:
	ldrb r0, [r7]
	cmp r0, #3
	beq .L08129670
	b .L0812979C
.L08129670:
	movs r2, #1
	mov sb, r2
	mov r0, sb
	strh r0, [r6, #0x1c]
	ldrh r0, [r7, #0x12]
	lsls r0, r0, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r4, .L08129764
	add r4, r8
	strb r0, [r4]
	ldrb r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	str r0, [sp, #0x10]
	strh r5, [r6, #0x1e]
	mov r0, sl
	cmp r0, #0
	bne .L0812970E
	ldr r0, .L08129768
	add r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L081296D8
	ldrb r0, [r4]
	bl sub_0812839C
	adds r4, r0, #0
	bl sub_080C3100
	cmp r4, r0
	bls .L081296D8
	mov r1, sb
	strh r1, [r6, #0x1e]
	mov r2, r8
	ldr r0, [r2, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #0
	mov sb, r0
.L081296D8:
	mov r1, sl
	cmp r1, #0
	bne .L0812970E
	ldr r0, .L08129768
	add r0, r8
	ldrb r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L0812970E
	ldr r0, .L08129764
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0
	bl sub_080C07B0
	cmp r0, #0
	bne .L0812970E
	strh r4, [r6, #0x1e]
	mov r2, r8
	ldr r0, [r2, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #0
	mov sb, r0
.L0812970E:
	ldr r1, .L0812976C
	adds r0, r1, #0
	ldr r2, [sp, #0x10]
	ldrh r2, [r2, #0x12]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi .L08129740
	bl sub_080C5CC0
	cmp r0, #1
	bls .L08129740
	movs r0, #5
	strh r0, [r6, #0x1e]
	mov r0, sl
	cmp r0, #0
	bne .L0812973C
	mov r1, r8
	ldr r0, [r1, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
.L0812973C:
	movs r2, #0
	mov sb, r2
.L08129740:
	mov r5, sb
	cmp r5, #1
	bne .L08129798
	bl sub_080F4504
	adds r4, r0, #0
	bl sub_080F45D4
	cmp r4, r0
	ble .L0812975C
	bl sub_080C0FC0
	cmp r0, #5
	ble .L08129770
.L0812975C:
	movs r0, #3
	strh r0, [r6, #0x1e]
	b .L08129798
	.byte 0x00, 0x00
.L08129764: .4byte 0x00000692
.L08129768: .4byte 0x00000694
.L0812976C: .4byte 0xFFFFFE96
.L08129770:
	ldr r0, .L08129828
	add r0, r8
	ldrb r0, [r0]
	ands r5, r0
	cmp r5, #0
	beq .L08129798
	bl sub_08129460
	cmp r0, #0
	bne .L08129798
	movs r0, #4
	strh r0, [r6, #0x1e]
	mov r0, sl
	cmp r0, #0
	bne .L08129798
	mov r1, r8
	ldr r0, [r1, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
.L08129798:
	bl sub_080D3688
.L0812979C:
	ldr r0, .L0812982C
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r7, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r7, #0xa]
	cmp r0, #5
	bls .L08129800
	ldrh r0, [r7, #0xc]
	cmp r0, #0
	beq .L081297E0
	ldr r0, .L08129830
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L081297E0:
	ldrh r0, [r7, #0xc]
	adds r0, #5
	ldrh r2, [r7, #0xa]
	cmp r0, r2
	beq .L08129800
	ldr r0, .L08129834
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L08129800:
	ldr r0, [sp, #0xc]
	ldrh r1, [r7, #0x12]
	cmp r0, r1
	beq .L08129818
	ldrh r1, [r7, #0xc]
	movs r0, #3
	bl sub_08127EAC
	ldrh r1, [r7, #0x12]
	movs r0, #3
	bl sub_081283C4
.L08129818:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08129828: .4byte 0x00000694
.L0812982C: .4byte gUnknown_08000EA4
.L08129830: .4byte gUnknown_08000FF0
.L08129834: .4byte gUnknown_08001000

	thumb_func_start sub_08129838
sub_08129838: @ 0x08129838
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L0812984A
	strh r0, [r4, #0x1c]
.L0812984A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08129850
sub_08129850: @ 0x08129850
	push {lr}
	ldr r0, .L08129878
	ldr r1, .L0812987C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	bgt .L0812986E
	cmp r0, #1
	bge .L0812986E
	cmp r0, #0
	bne .L0812986E
	bl sub_08128EB4
	bl BattleMsg_Close
.L0812986E:
	movs r0, #3
	bl sub_081269B0
	pop {r0}
	bx r0
.L08129878: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812987C: .4byte 0x00000694

	thumb_func_start sub_08129880
sub_08129880: @ 0x08129880
	push {r4, lr}
	ldr r4, .L081298A8
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L08129890
	movs r1, #0
	bl TextWindow_Close
.L08129890:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812989C
	movs r1, #0
	bl TextWindow_Close
.L0812989C:
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081298A8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_081298AC
sub_081298AC: @ 0x081298AC
	push {r4, lr}
	ldr r4, .L081298D4
	movs r0, #0
	movs r1, #1
	bl sub_080C8AAC
	str r0, [r4, #0x4c]
	movs r1, #1
	bl sub_080C8ADC
	ldr r1, .L081298D8
	movs r0, #4
	bl BattleMenu_SetMode
	movs r0, #3
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
.L081298D4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081298D8: .4byte gUnknown_081240BC

	thumb_func_start sub_081298DC
sub_081298DC: @ 0x081298DC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L08129908
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812990C
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08129910
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, [r5, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	b .L08129974
.L08129908: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812990C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08129910:
	ldrh r1, [r2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq .L0812997C
	movs r6, #0
	ldr r0, [r5, #0x4c]
	bl sub_080C8AF4
	strh r0, [r4, #0x1e]
	ldr r0, .L0812996C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08129974
	ldr r1, .L08129970
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08129954
	bl sub_08129460
	cmp r0, #0
	bne .L08129954
	movs r6, #1
.L08129954:
	cmp r6, #0
	bne .L08129974
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, [r5, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	movs r0, #0x65
	bl sub_080ECF70
	b .L0812998C
.L0812996C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08129970: .4byte 0x00000694
.L08129974:
	movs r0, #0x66
	bl sub_080ECF70
	b .L0812998C
.L0812997C:
	ldrh r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L0812998C
	movs r0, #0x64
	bl sub_080ECF70
.L0812998C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129994
sub_08129994: @ 0x08129994
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L081299C0
	movs r1, #0
	strh r1, [r4, #0x1c]
	ldr r1, .L081299C4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne .L081299B8
	movs r0, #7
	bl sub_08127A98
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081299B8
	movs r0, #1
	strh r0, [r4, #0x1c]
.L081299B8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081299C0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L081299C4: .4byte 0x00000694

	thumb_func_start sub_081299C8
sub_081299C8: @ 0x081299C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	ldr r7, .L081299FC
	ldr r0, .L08129A00
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r0, r2
	ldrh r4, [r6, #0x1e]
	adds r1, r1, r4
	movs r3, #0
	ldrsb r3, [r1, r3]
	ldr r2, .L08129A04
	adds r1, r7, r2
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #7
	bls .L081299F2
	b .L08129B18
.L081299F2:
	lsls r0, r1, #2
	ldr r1, .L08129A08
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081299FC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129A00: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08129A04: .4byte 0x00000694
.L08129A08: .4byte gUnknown_08129A0C
	.global gUnknown_08129A0C
gUnknown_08129A0C:
.L08129A0C: @ jump table
	.4byte .L08129A2C
	.4byte .L08129A80
	.4byte .L08129AD0
	.4byte .L08129A80
	.4byte .L08129B18
	.4byte .L08129B18
	.4byte .L08129B18
	.4byte .L08129A80
.L08129A2C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	beq .L08129A3E
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
.L08129A3E:
	ldr r4, .L08129A7C
	adds r0, r7, r4
	ldrb r5, [r0]
	adds r0, r5, #0
	bl sub_0812839C
	rsbs r0, r0, #0
	bl sub_080C30AC
	movs r0, #0xe9
	bl Battle_GetMessage
	adds r1, r5, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldrh r1, [r6, #0x1e]
	adds r0, r5, #0
	bl sub_080C0248
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	movs r0, #1
	b .L08129B1A
.L08129A7C: .4byte 0x00000692
.L08129A80:
	ldr r1, .L08129AC8
	adds r0, r7, r1
	ldrb r5, [r0]
	ldr r4, .L08129ACC
	adds r3, r7, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r4, #0xa2
	lsls r4, r4, #4
	adds r2, r2, r4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r4, #0xef
	lsls r4, r4, #4
	adds r1, r7, r4
	adds r1, r1, r0
	movs r4, #0
	strh r5, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r2, #0xf1
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r1, r1, r0
	ldrh r0, [r6, #0x1e]
	strh r0, [r1]
	strh r4, [r6, #0x1e]
	b .L08129B1C
.L08129AC8: .4byte 0x00000692
.L08129ACC: .4byte 0x00000F66
.L08129AD0:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	beq .L08129AE2
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
.L08129AE2:
	ldr r4, .L08129B14
	adds r0, r7, r4
	ldrb r5, [r0]
	movs r0, #0xe9
	bl Battle_GetMessage
	adds r1, r5, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldrh r1, [r6, #0x1e]
	adds r0, r5, #0
	bl sub_080C0248
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	movs r0, #1
	b .L08129B1A
.L08129B14: .4byte 0x00000692
.L08129B18:
	movs r0, #0
.L08129B1A:
	strh r0, [r6, #0x1e]
.L08129B1C:
	mov r0, r8
	cmp r0, #0
	bne .L08129B2A
	ldr r0, [r7, #0x48]
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
.L08129B2A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08129B34
sub_08129B34: @ 0x08129B34
	push {lr}
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0

	thumb_func_start sub_08129B40
sub_08129B40: @ 0x08129B40
	push {lr}
	adds r0, r1, #0
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129B58
sub_08129B58: @ 0x08129B58
	push {lr}
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0

	thumb_func_start sub_08129B74
sub_08129B74: @ 0x08129B74
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r7, .L08129BA8
	movs r0, #3
	bl sub_08127A98
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L08129BB0
	ldr r1, .L08129BAC
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r4, #0x1e]
	cmp r6, #0
	bne .L08129BF8
	ldr r0, [r7, #0x48]
	adds r0, #0x24
	movs r1, #0xff
	strb r1, [r0]
	b .L08129BF8
	.byte 0x00, 0x00
.L08129BA8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129BAC: .4byte gUnknown_081240F0
.L08129BB0:
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r7, #0x50]
	bl sub_081272AC
	str r5, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	movs r0, #0x6a
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
.L08129BF8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08129C00
sub_08129C00: @ 0x08129C00
	push {r4, lr}
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #3
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #3
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08129C20
sub_08129C20: @ 0x08129C20
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r7, .L08129C64
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldrb r6, [r4, #0x12]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x1c]
	ldr r0, .L08129C68
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08129C6C
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0x66
	bl sub_080ECF70
	movs r0, #4
	bl sub_081269B0
	lsls r6, r6, #0x10
	b .L08129CBC
.L08129C64: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129C68: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08129C6C:
	ldrb r0, [r4]
	lsls r6, r6, #0x10
	cmp r0, #3
	bne .L08129CBC
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0
	ldr r0, .L08129D00
	movs r7, #0xa2
	lsls r7, r7, #4
	adds r3, r0, r7
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, r1
	beq .L08129CAA
.L08129C94:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #5
	bhi .L08129CAA
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne .L08129C94
.L08129CAA:
	strh r2, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0x65
	bl sub_080ECF70
	movs r0, #4
	bl sub_081269B0
.L08129CBC:
	ldr r0, .L08129D04
	movs r1, #0
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r4, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	lsrs r0, r6, #0x10
	ldrh r1, [r4, #0x12]
	cmp r0, r1
	beq .L08129CF6
	ldrh r1, [r4, #0xc]
	movs r0, #3
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #3
	bl sub_081283C4
.L08129CF6:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08129D00: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08129D04: .4byte gUnknown_08000EA4
