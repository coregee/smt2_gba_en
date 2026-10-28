	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C140C
sub_080C140C: @ 0x080C140C
.L080C140C:
	push {r4, r5, lr}
	movs r4, #0x10
	ldr r3, .L080C1430
	ldr r5, .L080C1434
	adds r2, r5, #0
	strh r2, [r3]
	ldr r2, .L080C1438
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L080C143C
	strh r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C1430: .4byte 0x03000040 @ IWRAM+0x40
.L080C1434: .4byte 0x00003C42
.L080C1438: .4byte 0x03000042 @ IWRAM+0x42
.L080C143C: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_080C1440
sub_080C1440: @ 0x080C1440
.L080C1440:
	push {lr}
	movs r0, #0xc
	movs r1, #6
	bl sub_080C140C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C1450
sub_080C1450: @ 0x080C1450
.L080C1450:
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xfe
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #8
	ldr r3, .L080C14BC
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080C14C0
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080C14C4
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080C14C8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080C14CC
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080C14D0
	strb r1, [r0]
	ldr r0, .L080C14D4
	strb r1, [r0]
	ldr r0, .L080C14D8
	movs r1, #0
	strh r1, [r0]
	ldr r2, .L080C14DC
	ldr r3, .L080C14E0
	adds r0, r3, #0
	strh r0, [r2]
	ldr r0, .L080C14E4
	strh r1, [r0]
	ldr r0, .L080C14E8
	strh r1, [r0]
	ldr r0, .L080C14EC
	strh r1, [r0]
	ldr r0, .L080C14F0
	strh r1, [r0]
	ldr r0, .L080C14F4
	strh r1, [r0]
	ldr r0, .L080C14F8
	strh r1, [r0]
	bl sub_080C1440
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C14BC: .4byte 0x00008004
.L080C14C0: .4byte 0x00008209
.L080C14C4: .4byte 0x0000840A
.L080C14C8: .4byte 0x00008607
.L080C14CC: .4byte 0x03000038 @ IWRAM+0x38
.L080C14D0: .4byte 0x03000039 @ IWRAM+0x39
.L080C14D4: .4byte 0x0300003A @ IWRAM+0x3A
.L080C14D8: .4byte 0x03000000 @ IWRAM
.L080C14DC: .4byte 0x03000002 @ IWRAM+0x2
.L080C14E0: .4byte 0x0000FFFF
.L080C14E4: .4byte 0x03000004 @ IWRAM+0x4
.L080C14E8: .4byte 0x03000006 @ IWRAM+0x6
.L080C14EC: .4byte 0x03000008 @ IWRAM+0x8
.L080C14F0: .4byte 0x0300000A @ IWRAM+0xA
.L080C14F4: .4byte 0x0300000C @ IWRAM+0xC
.L080C14F8: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080C14FC
sub_080C14FC: @ 0x080C14FC
.L080C14FC:
	push {lr}
	sub sp, #0xc
	ldr r2, .L080C152C
	ldr r0, .L080C1530
	str r0, [r2]
	ldr r0, .L080C1534
	str r0, [r2, #4]
	ldr r1, .L080C1538
	str r1, [r2, #8]
	ldr r1, [r2, #8]
	movs r1, #0
	str r1, [sp]
	movs r1, #0x1c
	str r1, [sp, #4]
	movs r1, #0xd
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #1
	bl Tilemap_OffsetRect
	add sp, #0xc
	pop {r0}
	bx r0
.L080C152C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C1530: .4byte gUnknown_081B8370
.L080C1534: .4byte 0x02000000 @ EWRAM
.L080C1538: .4byte 0x84000140

	thumb_func_start sub_080C153C
sub_080C153C: @ 0x080C153C
.L080C153C:
	ldr r1, .L080C1550
	ldr r0, .L080C1554
	str r0, [r1]
	ldr r0, .L080C1558
	str r0, [r1, #4]
	ldr r0, .L080C155C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C1550: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C1554: .4byte 0x02000000 @ EWRAM
.L080C1558: .4byte 0x06002000 @ VRAM+0x2000
.L080C155C: .4byte 0x84000140

	thumb_func_start sub_080C1560
sub_080C1560: @ 0x080C1560
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080C15FC
	movs r4, #0
	str r4, [r0]
	bl sub_080C1450
	bl VBlankTasks_Init
	str r4, [sp]
	ldr r1, .L080C1600
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080C1604
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl Windows_Init
	bl sub_080C1328
	ldr r0, .L080C1608
	strh r4, [r0, #0x32]
	bl sub_080C1384
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl sub_080C14FC
	bl sub_080C153C
	bl sub_080C65E8
	bl sub_080C6734
	bl sub_080AD7F0
	ldr r0, .L080C160C
	ldr r4, [r0]
	cmp r4, #0
	bne .L080C15D8
	bl sub_080AE234
	movs r0, #0
	movs r1, #0
	bl Field_SetPosition
	ldr r0, .L080C1610
	strh r4, [r0, #2]
	strh r4, [r0, #4]
	ldr r0, .L080C1614
	str r4, [r0]
	ldr r0, .L080C1618
	ldrh r0, [r0]
	bl sub_080B30A0
.L080C15D8:
	ldr r0, .L080C161C
	bl SetMainCallback
	ldr r1, .L080C1620
	ldr r2, .L080C1624
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080C1628
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L080C162C
	movs r0, #1
	strh r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C15FC: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C1600: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C1604: .4byte 0x85001000
.L080C1608: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C160C: .4byte 0x03004544 @ IWRAM+0x4544
.L080C1610: .4byte 0x03004550 @ IWRAM+0x4550
.L080C1614: .4byte 0x03004514 @ IWRAM+0x4514
.L080C1618: .4byte 0x03004614 @ IWRAM+0x4614
.L080C161C: .4byte sub_080C1630
.L080C1620: .4byte 0x04000200 @ REG_IE
.L080C1624: .4byte 0x00002003
.L080C1628: .4byte 0x04000004 @ REG_DISPSTAT
.L080C162C: .4byte 0x04000208 @ REG_IME

	thumb_func_start sub_080C1630
sub_080C1630: @ 0x080C1630
	push {r4, lr}
	ldr r0, .L080C1660
	ldr r0, [r0]
	cmp r0, #1
	bls .L080C1642
	cmp r0, #4
	beq .L080C1642
	cmp r0, #6
	bne .L080C1674
.L080C1642:
	ldr r0, .L080C1664
	ldrh r0, [r0]
	ldr r1, .L080C1668
	ldrh r1, [r1]
	ldr r4, .L080C166C
	adds r2, r4, #0
	bl Map_LoadGraphicsStep
	ldr r0, [r4]
	cmp r0, #0
	bne .L080C167A
	ldr r0, .L080C1670
	bl SetMainCallback
	b .L080C167A
.L080C1660: .4byte 0x03004544 @ IWRAM+0x4544
.L080C1664: .4byte 0x03004614 @ IWRAM+0x4614
.L080C1668: .4byte 0x03004514 @ IWRAM+0x4514
.L080C166C: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080C1670: .4byte sub_080C1684
.L080C1674:
	ldr r0, .L080C1680
	bl SetMainCallback
.L080C167A:
	pop {r4}
	pop {r0}
	bx r0
.L080C1680: .4byte sub_080C1684

	thumb_func_start sub_080C1684
sub_080C1684: @ 0x080C1684
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, .L080C1734
	ldr r1, [r4]
	cmp r1, #0
	bne .L080C1694
	ldr r0, .L080C1738
	str r1, [r0]
.L080C1694:
	ldrh r0, [r4]
	bl sub_080ADFEC
	bl Task_ClearAll
	ldrh r0, [r4]
	bl sub_080AE364
	ldr r1, .L080C173C
	movs r0, #1
	strh r0, [r1, #0x34]
	ldr r0, [r4]
	cmp r0, #4
	bne .L080C1714
	movs r0, #0
	movs r1, #0
	movs r2, #0x12
	bl FieldMap_HasRecordRel
	cmp r0, #1
	beq .L080C16DA
	movs r0, #0
	movs r1, #0
	movs r2, #0x13
	bl FieldMap_HasRecordRel
	cmp r0, #1
	beq .L080C16DA
	movs r0, #0
	movs r1, #0
	movs r2, #0x1e
	bl FieldMap_HasRecordRel
	cmp r0, #1
	bne .L080C1714
.L080C16DA:
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080C1714
	ldr r5, .L080C1740
	movs r0, #0
	strh r0, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x40
	bl Palette_FillWithEffect
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r2, r5, r1
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
.L080C1714:
	ldr r0, .L080C1744
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080C1768
	bl sub_080D0E74
	cmp r0, #1
	bne .L080C1748
	movs r0, #0
	bl sub_080C5170
	b .L080C1778
	.byte 0x00, 0x00
.L080C1734: .4byte 0x03004544 @ IWRAM+0x4544
.L080C1738: .4byte 0x03004514 @ IWRAM+0x4514
.L080C173C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C1740: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C1744: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1748:
	ldr r0, .L080C1760
	ldrh r0, [r0]
	ldr r1, .L080C1764
	ldrh r1, [r1]
	bl sub_080AD608
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	b .L080C1778
	.byte 0x00, 0x00
.L080C1760: .4byte 0x03004614 @ IWRAM+0x4614
.L080C1764: .4byte 0x03004514 @ IWRAM+0x4514
.L080C1768:
	ldr r0, .L080C17B4
	ldrh r0, [r0, #8]
	bl sub_080AD67C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
.L080C1778:
	bl sub_080E44A4
	ldr r0, .L080C17B8
	ldr r0, [r0]
	cmp r0, #5
	beq .L080C17D0
	movs r0, #1
	bl PalFade_FadeInFromBlack
	ldr r0, .L080C17BC
	ldr r2, [r0]
	cmp r2, #0
	bne .L080C17AC
	ldr r1, .L080C17C0
	ldrh r0, [r1, #0x12]
	cmp r0, #2
	bne .L080C17AC
	ldrh r0, [r1, #0x14]
	cmp r0, #6
	bne .L080C17AC
	str r2, [sp, #4]
	ldr r1, .L080C17C4
	ldr r2, .L080C17C8
	add r0, sp, #4
	bl CpuSet
.L080C17AC:
	ldr r0, .L080C17CC
	bl SetMainCallback
	b .L080C17DE
.L080C17B4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080C17B8: .4byte 0x03004544 @ IWRAM+0x4544
.L080C17BC: .4byte 0x03004614 @ IWRAM+0x4614
.L080C17C0: .4byte 0x03004550 @ IWRAM+0x4550
.L080C17C4: .4byte 0x03002B50 @ IWRAM+0x2B50
.L080C17C8: .4byte 0x05000018 @ PLTT+0x18
.L080C17CC: .4byte sub_080C17F0
.L080C17D0:
	ldr r0, .L080C17E8
	ldrh r0, [r0]
	bl Field_SetState
	ldr r0, .L080C17EC
	bl SetMainCallback
.L080C17DE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C17E8: .4byte 0x030045FC @ IWRAM+0x45FC
.L080C17EC: .4byte sub_080C1850

	thumb_func_start sub_080C17F0
sub_080C17F0: @ 0x080C17F0
	push {r4, r5, r6, lr}
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #1
	bne .L080C1832
	ldr r0, .L080C183C
	movs r6, #0
	strh r6, [r0, #0x34]
	ldr r0, .L080C1840
	ldrh r0, [r0]
	bl Field_SetState
	ldr r0, .L080C1844
	bl SetMainCallback
	ldr r0, .L080C1848
	ldr r0, [r0]
	cmp r0, #4
	beq .L080C1822
	bl sub_080D0E74
	cmp r0, #1
	bne .L080C1832
.L080C1822:
	ldr r4, .L080C184C
	strh r5, [r4]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl sub_080AF8D0
	strh r6, [r4]
.L080C1832:
	bl sub_080C1850
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C183C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C1840: .4byte 0x030045FC @ IWRAM+0x45FC
.L080C1844: .4byte sub_080C1850
.L080C1848: .4byte 0x03004544 @ IWRAM+0x4544
.L080C184C: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080C1850
sub_080C1850: @ 0x080C1850
.L080C1850:
	push {lr}
	bl sub_080C104C
	ldr r1, .L080C1878
	ldr r2, .L080C187C
	adds r1, r1, r2
	strb r0, [r1]
	bl sub_080E5220
	bl sub_080B0C90
	bl Task_RunAll
	bl sub_080C6804
	bl sub_080C22E4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C1878: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C187C: .4byte 0x00000AC3

	thumb_func_start sub_080C1880
sub_080C1880: @ 0x080C1880
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x14
	ldr r0, .L080C19C4
	movs r1, #1
	mov sb, r1
	str r1, [r0]
	bl sub_080C1450
	bl VBlankTasks_Init
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080C19C8
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080C19CC
	ldr r2, .L080C19D0
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080C19D4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080C19D8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080C19DC
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080C19E0
	ldr r2, .L080C19E4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080C19E8
	movs r0, #0x88
	strb r0, [r1]
	ldr r1, .L080C19EC
	movs r0, #0x68
	strb r0, [r1]
	ldr r1, .L080C19F0
	movs r0, #0x60
	strb r0, [r1]
	ldr r1, .L080C19F4
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, .L080C19F8
	movs r2, #0x3f
	strb r2, [r0]
	ldr r1, .L080C19FC
	movs r0, #0x39
	strb r0, [r1]
	ldr r1, .L080C1A00
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, .L080C1A04
	movs r0, #0x17
	strb r0, [r1]
	ldr r1, .L080C1A08
	movs r0, #3
	strb r0, [r1]
	ldr r0, .L080C1A0C
	strb r2, [r0]
	ldr r1, .L080C1A10
	movs r0, #0x1f
	strb r0, [r1]
	add r1, sp, #0x10
	ldr r2, .L080C1A14
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, .L080C1A18
	str r1, [r4]
	ldr r5, .L080C1A1C
	str r5, [r4, #4]
	ldr r0, .L080C1A20
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r5, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r6, .L080C1A24
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, .L080C1A28
	mov r1, sb
	str r1, [sp]
	movs r2, #0
	mov r8, r2
	str r2, [sp, #4]
	movs r1, #7
	str r1, [sp, #8]
	movs r1, #3
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	str r5, [r4]
	ldr r0, .L080C1A2C
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	bl Windows_Init
	bl sub_080C1328
	ldr r0, .L080C1A30
	mov r1, r8
	strh r1, [r0, #0x32]
	bl sub_080C1384
	bl sub_080C2EFC
	movs r0, #0x80
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L080C1A34
	ldr r2, .L080C1A38
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080C1A3C
	movs r0, #0x18
	strh r0, [r1]
	ldr r0, .L080C1A40
	mov r1, sb
	strh r1, [r0]
	bl Task_ClearAll
	bl sub_080C7CC8
	ldr r0, .L080C1A44
	ldrh r0, [r0]
	ldr r1, .L080C1A48
	ldrh r1, [r1]
	ldr r2, .L080C1A4C
	ldrh r2, [r2]
	bl sub_08151EEC
	ldr r0, .L080C1A50
	ldrh r0, [r0, #8]
	bl sub_080AD67C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	ldr r0, .L080C1A54
	bl SetMainCallback
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C19C4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C19C8: .4byte 0x0000FEFF
.L080C19CC: .4byte 0x0400000A @ REG_BG1CNT
.L080C19D0: .4byte 0x00000209
.L080C19D4: .4byte 0x00000406
.L080C19D8: .4byte 0x00000607
.L080C19DC: .4byte 0x03000002 @ IWRAM+0x2
.L080C19E0: .4byte 0x03000040 @ IWRAM+0x40
.L080C19E4: .4byte 0x00003C46
.L080C19E8: .4byte 0x03000030 @ IWRAM+0x30
.L080C19EC: .4byte 0x03000031 @ IWRAM+0x31
.L080C19F0: .4byte 0x03000034 @ IWRAM+0x34
.L080C19F4: .4byte 0x03000035 @ IWRAM+0x35
.L080C19F8: .4byte 0x03000038 @ IWRAM+0x38
.L080C19FC: .4byte 0x03000032 @ IWRAM+0x32
.L080C1A00: .4byte 0x03000033 @ IWRAM+0x33
.L080C1A04: .4byte 0x03000036 @ IWRAM+0x36
.L080C1A08: .4byte 0x03000037 @ IWRAM+0x37
.L080C1A0C: .4byte 0x03000039 @ IWRAM+0x39
.L080C1A10: .4byte 0x0300003A @ IWRAM+0x3A
.L080C1A14: .4byte 0x000003B3
.L080C1A18: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C1A1C: .4byte 0x02000000 @ EWRAM
.L080C1A20: .4byte 0x81000800
.L080C1A24: .4byte 0x84000400
.L080C1A28: .4byte gUnknown_081B8270
.L080C1A2C: .4byte 0x06001000 @ VRAM+0x1000
.L080C1A30: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C1A34: .4byte 0x04000200 @ REG_IE
.L080C1A38: .4byte 0x00002003
.L080C1A3C: .4byte 0x04000004 @ REG_DISPSTAT
.L080C1A40: .4byte 0x04000208 @ REG_IME
.L080C1A44: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080C1A48: .4byte 0x03004618 @ IWRAM+0x4618
.L080C1A4C: .4byte 0x03004624 @ IWRAM+0x4624
.L080C1A50: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080C1A54: .4byte sub_080C1A58

	thumb_func_start sub_080C1A58
sub_080C1A58: @ 0x080C1A58
	push {lr}
	bl sub_080C5108
	cmp r0, #0
	bne .L080C1A70
	bl sub_080B9058
	bl sub_080C1A9C
	ldr r0, .L080C1A90
	bl SetMainCallback
.L080C1A70:
	bl sub_080C104C
	ldr r1, .L080C1A94
	ldr r2, .L080C1A98
	adds r1, r1, r2
	strb r0, [r1]
	bl sub_080C7CD8
	bl sub_0815201C
	bl Task_RunAll
	bl sub_080C22E4
	pop {r0}
	bx r0
.L080C1A90: .4byte sub_080C1A9C
.L080C1A94: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1A98: .4byte 0x00000AC3

	thumb_func_start sub_080C1A9C
sub_080C1A9C: @ 0x080C1A9C
.L080C1A9C:
	push {lr}
	bl sub_080C7CD8
	bl Task_RunAll
	bl sub_080C22E4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C1AB0
sub_080C1AB0: @ 0x080C1AB0
.L080C1AB0:
	push {r4, r5, r6, lr}
	ldr r0, .L080C1AD4
	ldr r1, .L080C1AD8
	adds r6, r0, r1
	ldrb r5, [r6]
	bl sub_080C1D9C
	adds r1, r0, #0
	movs r0, #0xf0
	ands r1, r0
	adds r4, r1, #0
	cmp r5, #1
	bne .L080C1ADC
	cmp r1, #0
	beq .L080C1AEC
	movs r0, #2
	strb r0, [r6]
	b .L080C1AEC
.L080C1AD4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1AD8: .4byte 0x000018D4
.L080C1ADC:
	cmp r5, #2
	bne .L080C1AEC
	cmp r4, #0
	bne .L080C1AEC
	movs r0, #0xff
	bl sub_080C245C
	strb r4, [r6]
.L080C1AEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C1AF4
sub_080C1AF4: @ 0x080C1AF4
.L080C1AF4:
	push {r4, lr}
	bl sub_080C1DB0
	ldr r0, .L080C1B2C
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080C1B48
	bl sub_080C1D9C
	adds r4, r0, #0
	movs r0, #0xff
	ands r4, r0
	bl sub_080C1AB0
	bl sub_080C1D9C
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0
	bne .L080C1B34
	ldr r0, .L080C1B30
	bl sub_080F3F58
	b .L080C1B48
	.byte 0x00, 0x00
.L080C1B2C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1B30: .4byte 0xFFFFFEFF
.L080C1B34:
	cmp r4, #0x80
	bne .L080C1B48
	movs r0, #0x41
	rsbs r0, r0, #0
	bl sub_080F3F58
	movs r0, #0x21
	rsbs r0, r0, #0
	bl sub_080F3F58
.L080C1B48:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C1B50
sub_080C1B50: @ 0x080C1B50
.L080C1B50:
	push {lr}
	ldr r0, .L080C1B68
	adds r0, #0x8e
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L080C1B6C
	movs r0, #2
	b .L080C1B6E
	.byte 0x00, 0x00
.L080C1B68: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1B6C:
	movs r0, #1
.L080C1B6E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C1B74
sub_080C1B74: @ 0x080C1B74
.L080C1B74:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r6, #0
	bl sub_080C1D9C
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x80
	bne .L080C1C34
	movs r0, #0xcf
	bl Flag_Test
	cmp r0, #0
	beq .L080C1C4E
	movs r0, #0xe2
	bl Flag_Test
	cmp r0, #0
	beq .L080C1BA6
	movs r0, #0
	bl sub_080C1CAC
	strh r0, [r4]
	movs r6, #1
.L080C1BA6:
	movs r0, #0xe3
	bl Flag_Test
	cmp r0, #0
	beq .L080C1BC2
	bl sub_080C1B50
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C1CAC
	strh r0, [r5]
	movs r0, #2
	orrs r6, r0
.L080C1BC2:
	movs r5, #0x80
	lsls r5, r5, #8
	adds r0, r5, #0
	bl Battle_GetCombatant
	adds r1, r0, #0
	adds r0, #0x38
	movs r4, #0
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldrb r0, [r1, #0xc]
	bl sub_080BF938
	bl sub_080C1B50
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r1, r0, #0
	adds r0, #0x38
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldrb r0, [r1, #0xc]
	bl sub_080BF938
	movs r0, #0xe2
	bl Flag_Clear
	movs r0, #0xe3
	bl Flag_Clear
	movs r0, #0xcf
	bl Flag_Clear
	bl sub_080CDC34
	b .L080C1C4E
.L080C1C34:
	movs r0, #0xe2
	bl Flag_Test
	cmp r0, #0
	bne .L080C1C48
	movs r0, #0xe3
	bl Flag_Test
	cmp r0, #0
	beq .L080C1C4E
.L080C1C48:
	movs r0, #0xcf
	bl Flag_Set
.L080C1C4E:
	ldr r5, .L080C1C98
	ldr r0, .L080C1C9C
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L080C1C90
	bl sub_080C1D9C
	adds r1, r0, #0
	movs r0, #0xf0
	ands r1, r0
	ldr r2, .L080C1CA0
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r1, r2
	beq .L080C1C90
	strb r1, [r0]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080C1C90
	ldr r1, .L080C1CA4
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, .L080C1CA8
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r1, #0
	bl Flag_Set
.L080C1C90:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080C1C98: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1C9C: .4byte 0x000018B5
.L080C1CA0: .4byte 0x000018B4
.L080C1CA4: .4byte 0x000018B6
.L080C1CA8: .4byte gUnknown_081A6264

	thumb_func_start sub_080C1CAC
sub_080C1CAC: @ 0x080C1CAC
.L080C1CAC:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r5, r0, #0
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #7
	ands r4, r0
	cmp r4, #0
	beq .L080C1CE8
	movs r0, #3
	ands r4, r0
	ldr r1, .L080C1CE4
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldrb r0, [r5, #0xc]
	adds r1, r4, #0
	bl sub_080C08F8
	b .L080C1CF2
	.byte 0x00, 0x00
.L080C1CE4: .4byte gUnknown_081A626A
.L080C1CE8:
	movs r4, #4
	ldrb r0, [r5, #0xc]
	movs r1, #4
	bl sub_080C08F8
.L080C1CF2:
	bl sub_080C84A0
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C1D00
sub_080C1D00: @ 0x080C1D00
.L080C1D00:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L080C1D60
	ldr r1, .L080C1D64
	adds r3, r4, r1
	ldrh r2, [r3]
	ldr r5, .L080C1D68
	adds r1, r4, r5
	strh r2, [r1]
	adds r1, r0, r2
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls .L080C1D26
	movs r0, #0xff
	ands r1, r0
	strh r1, [r3]
.L080C1D26:
	bl sub_080C1AF4
	bl sub_080F3F44
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080C1D8E
	ldr r1, .L080C1D6C
	adds r0, r4, r1
	ldrb r4, [r0]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne .L080C1D70
	bl sub_080C1D9C
	movs r2, #0xf0
	adds r1, r4, #0
	ands r1, r2
	ands r2, r0
	cmp r2, r1
	bne .L080C1D86
	movs r4, #0
	movs r0, #0x81
	rsbs r0, r0, #0
	bl sub_080F3F58
	b .L080C1D86
.L080C1D60: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1D64: .4byte 0x00000A28
.L080C1D68: .4byte 0x00000A2A
.L080C1D6C: .4byte 0x000018BB
.L080C1D70:
	bl sub_080C1D9C
	movs r2, #0xf0
	adds r1, r4, #0
	ands r1, r2
	ands r2, r0
	cmp r2, r1
	beq .L080C1D86
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080C1D86:
	ldr r0, .L080C1D94
	ldr r5, .L080C1D98
	adds r0, r0, r5
	strb r4, [r0]
.L080C1D8E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C1D94: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1D98: .4byte 0x000018BB

	thumb_func_start sub_080C1D9C
sub_080C1D9C: @ 0x080C1D9C
.L080C1D9C:
	ldr r0, .L080C1DA8
	ldr r1, .L080C1DAC
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C1DA8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1DAC: .4byte 0x00000A28

	thumb_func_start sub_080C1DB0
sub_080C1DB0: @ 0x080C1DB0
.L080C1DB0:
	push {r4, r5, lr}
	ldr r0, .L080C1DD0
	ldr r1, .L080C1DD4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0xf0
	adds r4, r5, #0
	ands r4, r0
	bl sub_080C1D9C
	ands r0, r5
	cmp r4, r0
	bne .L080C1DD8
	movs r0, #0
	b .L080C1DDA
	.byte 0x00, 0x00
.L080C1DD0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1DD4: .4byte 0x00000A2A
.L080C1DD8:
	movs r0, #1
.L080C1DDA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C1DE0
sub_080C1DE0: @ 0x080C1DE0
.L080C1DE0:
	push {r4, lr}
	movs r0, #2
	bl sub_080C1D00
	ldr r0, .L080C1E14
	ldr r1, .L080C1E18
	adds r4, r0, r1
	ldrh r0, [r4]
	bl sub_080C4F88
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C1E08
	movs r0, #0x1f
	movs r1, #1
	bl sub_080B8B68
	ldr r0, .L080C1E1C
	bl sub_080C51D4
.L080C1E08:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L080C1E14: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1E18: .4byte 0x00000A3E
.L080C1E1C: .4byte 0x0000012B

	thumb_func_start sub_080C1E20
sub_080C1E20: @ 0x080C1E20
.L080C1E20:
	push {r4, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	bl sub_080C1D00
	mov r0, sp
	bl sub_080C1E60
	ldr r4, .L080C1E58
	ldr r0, .L080C1E5C
	adds r4, r4, r0
	ldrh r0, [r4]
	mov r1, sp
	bl sub_080C4E48
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl sub_080C4C98
	ldr r0, [sp]
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C1E58: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1E5C: .4byte 0x00000A36

	thumb_func_start sub_080C1E60
sub_080C1E60: @ 0x080C1E60
.L080C1E60:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl sub_080C3168
	cmp r0, #0
	beq .L080C1EDC
	ldr r1, .L080C1ED4
	ldr r2, .L080C1ED8
	adds r0, r1, r2
	ldrh r5, [r0]
	movs r6, #0
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r7, r1, r0
.L080C1E80:
	adds r0, r6, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L080C1EA2
	cmp r4, #3
	ble .L080C1EA2
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080ED584
	adds r5, r5, r0
.L080C1EA2:
	adds r6, #1
	cmp r6, #5
	ble .L080C1E80
	ldr r4, .L080C1ED4
	adds r0, r5, #0
	movs r1, #0xa
	bl __modsi3
	ldr r1, .L080C1ED8
	adds r4, r4, r1
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __divsi3
	adds r5, r0, #0
	rsbs r5, r5, #0
	adds r0, r5, #0
	bl sub_080C3114
	cmp r0, #0
	bne .L080C1F34
	strh r0, [r4]
	b .L080C1F34
	.byte 0x00, 0x00
.L080C1ED4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1ED8: .4byte 0x00000AC4
.L080C1EDC:
	movs r6, #0
	ldr r2, .L080C1F40
	mov r8, r2
	ldr r7, .L080C1F44
.L080C1EE4:
	mov r1, r8
	adds r0, r6, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L080C1F1E
	cmp r4, #3
	ble .L080C1F1E
	adds r0, r4, #0
	bl sub_080F401C
	adds r1, r0, #0
	cmp r1, #1
	bne .L080C1F0C
	lsls r1, r4
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
.L080C1F0C:
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C0C70
	adds r0, r6, #0
	bl sub_080C8490
	movs r0, #1
	strh r0, [r7]
.L080C1F1E:
	adds r6, #1
	cmp r6, #5
	ble .L080C1EE4
	ldr r0, .L080C1F48
	adds r0, #0x70
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080C1F34
	ldr r0, .L080C1F4C
	bl sub_080C51D4
.L080C1F34:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C1F40: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C1F44: .4byte 0x0200E844 @ EWRAM+0xE844
.L080C1F48: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C1F4C: .4byte 0x0000012B

	thumb_func_start sub_080C1F50
sub_080C1F50: @ 0x080C1F50
.L080C1F50:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080C1F8C
	ldrh r0, [r0]
	ldr r1, .L080C1F90
	ldrh r1, [r1]
	bl sub_080C8B10
	ldrh r1, [r0, #8]
	adds r4, r4, r1
	strh r4, [r6]
	ldrh r0, [r0, #0xa]
	adds r5, r5, r0
	mov r0, r8
	strh r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C1F8C: .4byte 0x03004614 @ IWRAM+0x4614
.L080C1F90: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080C1F94
sub_080C1F94: @ 0x080C1F94
.L080C1F94:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	bne .L080C1FA0
	movs r4, #1
.L080C1FA0:
	adds r0, r5, #0
	adds r1, r4, #0
	bl __modsi3
	lsrs r1, r4, #0x1f
	adds r1, r4, r1
	asrs r1, r1, #1
	movs r6, #0
	cmp r0, r1
	blt .L080C1FB6
	movs r6, #1
.L080C1FB6:
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	adds r0, r0, r6
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C1FC8
sub_080C1FC8: @ 0x080C1FC8
	push {lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, .L080C1FE4
	ldr r0, [r0]
	cmp r0, #1
	beq .L080C1FF0
	cmp r0, #1
	blo .L080C1FE8
	cmp r0, #2
	beq .L080C1FF8
	cmp r0, #3
	beq .L080C1FF8
	b .L080C1FFC
.L080C1FE4: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080C1FE8:
	strh r3, [r1]
	movs r0, #0x28
	strh r0, [r2]
	b .L080C1FFC
.L080C1FF0:
	strh r3, [r1]
	movs r0, #0x48
	strh r0, [r2]
	b .L080C1FFC
.L080C1FF8:
	strh r3, [r2]
	strh r3, [r1]
.L080C1FFC:
	pop {r0}
	bx r0

	thumb_func_start sub_080C2000
sub_080C2000: @ 0x080C2000
.L080C2000:
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	bl sub_080F3F44
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080C2084
	cmp r4, #0
	bne .L080C202E
	bl sub_080C5D0C
	movs r2, #0x7f
	ands r2, r0
	cmp r2, #0x6b
	bls .L080C2024
	movs r2, #0x3e
.L080C2024:
	add r1, sp, #4
	mov r0, sp
	bl sub_080ED398
	b .L080C2036
.L080C202E:
	add r1, sp, #4
	mov r0, sp
	bl sub_080F450C
.L080C2036:
	ldr r0, [sp]
	movs r1, #0
	bl sub_080ED5B4
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, [sp]
	movs r1, #1
	bl sub_080ED5B4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	bl sub_080C0F8C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080BF648
	ldrb r0, [r0, #1]
	cmp r4, r0
	bgt .L080C2080
	movs r0, #0
	bl sub_080C0F8C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #0
	bl sub_080BF648
	ldrb r0, [r0, #1]
	cmp r4, r0
	ble .L080C2084
.L080C2080:
	movs r0, #1
	b .L080C2086
.L080C2084:
	movs r0, #0
.L080C2086:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2090
sub_080C2090: @ 0x080C2090
.L080C2090:
	push {lr}
	ldr r0, .L080C20B8
	ldrh r0, [r0]
	ldr r1, .L080C20BC
	ldrh r1, [r1]
	bl sub_080C8B10
	ldr r1, .L080C20C0
	ldr r2, .L080C20C4
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	pop {r1}
	bx r1
.L080C20B8: .4byte 0x03004614 @ IWRAM+0x4614
.L080C20BC: .4byte 0x03004514 @ IWRAM+0x4514
.L080C20C0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C20C4: .4byte 0x00000A38

	thumb_func_start sub_080C20C8
sub_080C20C8: @ 0x080C20C8
.L080C20C8:
	push {lr}
	movs r0, #0xff
	bl Flag_Test
	cmp r0, #0
	bne .L080C20DC
	bl sub_080C2090
	cmp r0, #1
	bne .L080C20E6
.L080C20DC:
	movs r0, #0
	bl sub_080C2230
	movs r0, #0
	b .L080C20E8
.L080C20E6:
	movs r0, #1
.L080C20E8:
	pop {r1}
	bx r1

	thumb_func_start sub_080C20EC
sub_080C20EC: @ 0x080C20EC
.L080C20EC:
	push {r4, r5, r6, lr}
	bl sub_080C5D0C
	movs r6, #0x7f
	adds r5, r6, #0
	ands r5, r0
	bl sub_080C2244
	ldr r4, .L080C213C
	strh r0, [r4]
	bl sub_080C2244
	strh r0, [r4, #2]
	cmp r5, #0x6b
	bls .L080C210C
	movs r5, #0x3e
.L080C210C:
	ands r5, r6
	adds r0, r5, #0
	bl sub_080C5D48
	adds r4, r0, #0
	ldrb r5, [r4]
	lsls r5, r5, #1
	cmp r5, #0
	beq .L080C2146
	movs r0, #0xff
	bl Flag_Test
	cmp r0, #0
	bne .L080C2146
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080C214E
	bl Flag_Test
	cmp r0, #0
	beq .L080C2140
	ldrb r0, [r4, #2]
	b .L080C2142
	.byte 0x00, 0x00
.L080C213C: .4byte 0x0203A450 @ EWRAM+0x3A450
.L080C2140:
	ldrb r0, [r4, #3]
.L080C2142:
	cmp r0, #0xff
	bne .L080C214E
.L080C2146:
	movs r0, #0
	bl sub_080C2230
	b .L080C2160
.L080C214E:
	bl sub_080C221C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C2230
.L080C2160:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C2168
sub_080C2168: @ 0x080C2168
.L080C2168:
	push {r4, r5, r6, lr}
	bl sub_080C5D98
	adds r5, r0, #0
	ldrb r6, [r5]
	lsls r6, r6, #1
	bl sub_080C2244
	ldr r4, .L080C21A4
	strh r0, [r4]
	bl sub_080C2244
	strh r0, [r4, #2]
	cmp r6, #0
	beq .L080C21AE
	movs r0, #0xff
	bl Flag_Test
	cmp r0, #0
	bne .L080C21AE
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq .L080C21B6
	bl Flag_Test
	cmp r0, #0
	beq .L080C21A8
	ldrb r0, [r5, #2]
	b .L080C21AA
	.byte 0x00, 0x00
.L080C21A4: .4byte 0x0203A450 @ EWRAM+0x3A450
.L080C21A8:
	ldrb r0, [r5, #3]
.L080C21AA:
	cmp r0, #0xff
	bne .L080C21B6
.L080C21AE:
	movs r0, #0
	bl sub_080C2230
	b .L080C21C8
.L080C21B6:
	bl sub_080C221C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C2230
.L080C21C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C21D0
sub_080C21D0: @ 0x080C21D0
.L080C21D0:
	push {lr}
	bl sub_080C221C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, r1, #0
	cmp r1, #0
	bne .L080C21E4
	movs r1, #0
	b .L080C2212
.L080C21E4:
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf9
	bhi .L080C21F2
	movs r1, #1
	b .L080C2212
.L080C21F2:
	adds r0, r1, #0
	subs r0, #0xfb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf9
	bhi .L080C2202
	movs r1, #2
	b .L080C2212
.L080C2202:
	ldr r1, .L080C2218
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #4
	cmp r0, #0xf9
	bhi .L080C2212
	movs r1, #3
.L080C2212:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080C2218: .4byte 0xFFFFFE0B

	thumb_func_start sub_080C221C
sub_080C221C: @ 0x080C221C
.L080C221C:
	ldr r0, .L080C2228
	ldr r1, .L080C222C
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C2228: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C222C: .4byte 0x00000AEA

	thumb_func_start sub_080C2230
sub_080C2230: @ 0x080C2230
.L080C2230:
	ldr r1, .L080C223C
	ldr r2, .L080C2240
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080C223C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2240: .4byte 0x00000AEA

	thumb_func_start sub_080C2244
sub_080C2244: @ 0x080C2244
.L080C2244:
	push {lr}
	bl Random_Next
	adds r1, r0, #0
	movs r0, #0xff
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_080C2254
sub_080C2254: @ 0x080C2254
.L080C2254:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #3
	movs r1, #4
	bl sub_080C1F94
	adds r4, r0, #0
	adds r4, #0xa
	bl sub_080C2244
	movs r1, #0xf
	ands r1, r0
	muls r4, r1, r4
	adds r4, r4, r5
	cmp r4, #0xfe
	bgt .L080C2278
	movs r0, #0
	b .L080C227A
.L080C2278:
	movs r0, #1
.L080C227A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C2280
sub_080C2280: @ 0x080C2280
.L080C2280:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xff
	bl Flag_Test
	cmp r0, #0
	bne .L080C22C4
	cmp r4, #0
	bne .L080C2298
	movs r0, #0
	b .L080C229A
.L080C2298:
	movs r0, #1
.L080C229A:
	bl sub_080C2000
	cmp r0, #0
	bne .L080C22C4
	bl sub_080C221C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #0
	bne .L080C22C8
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	bl sub_080C2244
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	cmp r4, r1
	bls .L080C22C4
	movs r0, #1
	b .L080C22DC
.L080C22C4:
	movs r0, #0
	b .L080C22DC
.L080C22C8:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_080C2254
.L080C22DC:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C22E4
sub_080C22E4: @ 0x080C22E4
.L080C22E4:
	push {lr}
	ldr r1, .L080C2334
	ldrb r0, [r1, #3]
	adds r0, #1
	movs r2, #0
	strb r0, [r1, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls .L080C2300
	strb r2, [r1, #3]
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
.L080C2300:
	ldrb r0, [r1, #2]
	cmp r0, #0x3b
	bls .L080C230E
	strb r2, [r1, #2]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
.L080C230E:
	ldrb r0, [r1, #1]
	cmp r0, #0x3b
	bls .L080C231C
	strb r2, [r1, #1]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L080C231C:
	ldr r0, [r1]
	cmp r0, #0
	bne .L080C232E
	movs r0, #0x3b
	strb r0, [r1, #3]
	strb r0, [r1, #2]
	strb r0, [r1, #1]
	movs r0, #0xff
	strb r0, [r1]
.L080C232E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2334: .4byte 0x030051A4 @ IWRAM+0x51A4

	thumb_func_start sub_080C2338
sub_080C2338: @ 0x080C2338
	ldr r0, .L080C233C
	bx lr
.L080C233C: .4byte 0x030051A4 @ IWRAM+0x51A4

	thumb_func_start Flag_Test
Flag_Test: @ 0x080C2340
.L080C2340:
	adds r2, r0, #0
	ldr r0, .L080C235C
	lsrs r1, r2, #3
	ldr r3, .L080C2360
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C235C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2360: .4byte 0x000015E8

	thumb_func_start Flag_Set
Flag_Set: @ 0x080C2364
.L080C2364:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, .L080C23AC
	lsrs r2, r4, #3
	ldr r1, .L080C23B0
	adds r0, r0, r1
	adds r2, r2, r0
	movs r5, #7
	adds r1, r4, #0
	ands r1, r5
	movs r6, #1
	adds r0, r6, #0
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl sub_080C90FC
	ldr r0, .L080C23B4
	adds r4, r4, r0
	cmp r4, #0x2d
	bhi .L080C23A4
	ldr r0, .L080C23B8
	lsrs r2, r4, #3
	adds r2, r2, r0
	ands r4, r5
	adds r0, r6, #0
	lsls r0, r4
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
.L080C23A4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C23AC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C23B0: .4byte 0x000015E8
.L080C23B4: .4byte 0xFFFFFEE0
.L080C23B8: .4byte 0x03004680 @ IWRAM+0x4680

	thumb_func_start Flag_Clear
Flag_Clear: @ 0x080C23BC
.L080C23BC:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, .L080C2404
	lsrs r2, r4, #3
	ldr r1, .L080C2408
	adds r0, r0, r1
	adds r2, r2, r0
	movs r5, #7
	adds r0, r4, #0
	ands r0, r5
	movs r6, #1
	adds r1, r6, #0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl sub_080C90FC
	ldr r0, .L080C240C
	adds r4, r4, r0
	cmp r4, #0x2d
	bhi .L080C23FC
	ldr r0, .L080C2410
	lsrs r2, r4, #3
	adds r2, r2, r0
	ands r4, r5
	adds r1, r6, #0
	lsls r1, r4
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C23FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2404: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2408: .4byte 0x000015E8
.L080C240C: .4byte 0xFFFFFEE0
.L080C2410: .4byte 0x03004680 @ IWRAM+0x4680

	thumb_func_start sub_080C2414
sub_080C2414: @ 0x080C2414
.L080C2414:
	adds r2, r0, #0
	ldr r0, .L080C2430
	lsrs r1, r2, #3
	ldr r3, .L080C2434
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C2430: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2434: .4byte 0x00001750

	thumb_func_start sub_080C2438
sub_080C2438: @ 0x080C2438
.L080C2438:
	ldr r1, .L080C2454
	lsrs r2, r0, #3
	ldr r3, .L080C2458
	adds r1, r1, r3
	adds r2, r2, r1
	movs r1, #7
	ands r1, r0
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080C2454: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2458: .4byte 0x00001750

	thumb_func_start sub_080C245C
sub_080C245C: @ 0x080C245C
.L080C245C:
	ldr r1, .L080C2478
	lsrs r3, r0, #3
	ldr r2, .L080C247C
	adds r1, r1, r2
	adds r3, r3, r1
	movs r1, #7
	ands r1, r0
	movs r2, #1
	lsls r2, r1
	ldrb r0, [r3]
	bics r0, r2
	strb r0, [r3]
	bx lr
	.byte 0x00, 0x00
.L080C2478: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C247C: .4byte 0x00001750

	thumb_func_start sub_080C2480
sub_080C2480: @ 0x080C2480
.L080C2480:
	push {lr}
	adds r2, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	bne .L080C24B0
	ldr r0, .L080C24A8
	lsrs r1, r2, #3
	ldr r3, .L080C24AC
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	b .L080C24B2
	.byte 0x00, 0x00
.L080C24A8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C24AC: .4byte 0x000010D4
.L080C24B0:
	movs r0, #0
.L080C24B2:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C24B8
sub_080C24B8: @ 0x080C24B8
.L080C24B8:
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L080C24F0
	ldr r0, .L080C24E4
	ands r4, r0
	ldr r0, .L080C24E8
	lsrs r2, r4, #3
	ldr r1, .L080C24EC
	adds r0, r0, r1
	adds r2, r2, r0
	movs r0, #7
	ands r0, r4
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	b .L080C2510
	.byte 0x00, 0x00
.L080C24E4: .4byte 0x00007FFF
.L080C24E8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C24EC: .4byte 0x000010D4
.L080C24F0:
	adds r0, r4, #0
	bl sub_080C90F8
	cmp r0, #0
	beq .L080C2512
	ldr r0, .L080C2518
	lsrs r2, r4, #3
	ldr r1, .L080C251C
	adds r0, r0, r1
	adds r2, r2, r0
	movs r1, #7
	ands r1, r4
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
.L080C2510:
	strb r0, [r2]
.L080C2512:
	pop {r4}
	pop {r0}
	bx r0
.L080C2518: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C251C: .4byte 0x000010D4

	thumb_func_start sub_080C2520
sub_080C2520: @ 0x080C2520
	push {lr}
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L080C2546
	ldr r0, .L080C254C
	lsrs r2, r1, #3
	ldr r3, .L080C2550
	adds r0, r0, r3
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C2546:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C254C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2550: .4byte 0x000010D4

	thumb_func_start sub_080C2554
sub_080C2554: @ 0x080C2554
.L080C2554:
	push {lr}
	adds r2, r0, #0
	cmp r2, #0xff
	bhi .L080C257C
	ldr r0, .L080C2574
	lsrs r1, r2, #3
	ldr r3, .L080C2578
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	b .L080C257E
.L080C2574: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2578: .4byte 0x00001054
.L080C257C:
	movs r0, #0
.L080C257E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2584
sub_080C2584: @ 0x080C2584
.L080C2584:
	push {r4, lr}
	adds r4, r0, #0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	cmp r4, #0xff
	bls .L080C259C
	adds r0, r4, #0
	bl sub_080C2674
	b .L080C25C4
.L080C259C:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080C25AC
	adds r0, r4, #0
	bl sub_080C2674
.L080C25AC:
	ldr r0, .L080C25CC
	lsrs r2, r4, #3
	ldr r1, .L080C25D0
	adds r0, r0, r1
	adds r2, r2, r0
	movs r1, #7
	ands r1, r4
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
.L080C25C4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C25CC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C25D0: .4byte 0x00001054

	thumb_func_start sub_080C25D4
sub_080C25D4: @ 0x080C25D4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xff
	bhi .L080C25F4
	ldr r0, .L080C25F8
	lsrs r2, r1, #3
	ldr r3, .L080C25FC
	adds r0, r0, r3
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C25F4:
	pop {r0}
	bx r0
.L080C25F8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C25FC: .4byte 0x00001054

	thumb_func_start sub_080C2600
sub_080C2600: @ 0x080C2600
.L080C2600:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	ldr r4, .L080C261C
	ldr r5, .L080C2620
	adds r6, r4, #2
.L080C260E:
	lsls r1, r3, #2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r5
	bne .L080C2624
	adds r0, r2, #0
	b .L080C2634
.L080C261C: .4byte gUnknown_081A6272
.L080C2620: .4byte 0x0000FFFF
.L080C2624:
	cmp r0, r2
	beq .L080C2630
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L080C260E
.L080C2630:
	adds r0, r1, r6
	ldrh r0, [r0]
.L080C2634:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C263C
sub_080C263C: @ 0x080C263C
.L080C263C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C2644
sub_080C2644: @ 0x080C2644
.L080C2644:
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080C2664
	cmp r2, r0
	bhi .L080C266C
	ldr r1, .L080C2668
	lsrs r0, r2, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	b .L080C266E
	.byte 0x00, 0x00
.L080C2664: .4byte 0x0000017B
.L080C2668: .4byte 0x03004690 @ IWRAM+0x4690
.L080C266C:
	movs r0, #0
.L080C266E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2674
sub_080C2674: @ 0x080C2674
.L080C2674:
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L080C26B0
	cmp r4, r0
	bhi .L080C26A8
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C2600
	lsls r5, r0, #0x10
	lsrs r4, r5, #0x10
	adds r0, r4, #0
	bl sub_080DD21C
	cmp r0, #0
	beq .L080C26A8
	ldr r0, .L080C26B4
	lsrs r2, r5, #0x13
	adds r2, r2, r0
	movs r1, #7
	ands r1, r4
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
.L080C26A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C26B0: .4byte 0x0000017B
.L080C26B4: .4byte 0x03004690 @ IWRAM+0x4690

	thumb_func_start sub_080C26B8
sub_080C26B8: @ 0x080C26B8
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r0, .L080C26FC
	cmp r3, r0
	bhi .L080C26F4
	ldr r6, .L080C2700
	lsrs r2, r3, #3
	adds r2, r2, r6
	movs r5, #7
	adds r0, r3, #0
	ands r0, r5
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C2600
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsrs r0, r0, #0x13
	adds r0, r0, r6
	ands r3, r5
	lsls r4, r3
	ldrb r1, [r0]
	bics r1, r4
	strb r1, [r0]
.L080C26F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C26FC: .4byte 0x0000017B
.L080C2700: .4byte 0x03004690 @ IWRAM+0x4690

	thumb_func_start sub_080C2704
sub_080C2704: @ 0x080C2704
.L080C2704:
	push {lr}
	ldr r0, .L080C2714
	ldr r1, .L080C2718
	movs r2, #0x30
	bl Sram_WriteVerified
	pop {r0}
	bx r0
.L080C2714: .4byte 0x03004690 @ IWRAM+0x4690
.L080C2718: .4byte 0x0E000014

	thumb_func_start sub_080C271C
sub_080C271C: @ 0x080C271C
.L080C271C:
	push {lr}
	ldr r0, .L080C272C
	ldr r1, .L080C2730
	movs r2, #0x30
	bl Sram_ReadVerified
	pop {r0}
	bx r0
.L080C272C: .4byte 0x0E000014
.L080C2730: .4byte 0x03004690 @ IWRAM+0x4690

	thumb_func_start sub_080C2734
sub_080C2734: @ 0x080C2734
.L080C2734:
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080C2754
	adds r2, r2, r0
	cmp r2, #0x3f
	bhi .L080C275C
	ldr r1, .L080C2758
	lsrs r0, r2, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	b .L080C275E
.L080C2754: .4byte 0xFFFFFED4
.L080C2758: .4byte 0x03006090 @ IWRAM+0x6090
.L080C275C:
	movs r0, #0
.L080C275E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2764
sub_080C2764: @ 0x080C2764
.L080C2764:
	push {lr}
	adds r3, r0, #0
	ldr r0, .L080C2788
	adds r3, r3, r0
	cmp r3, #0x3f
	bhi .L080C2784
	ldr r0, .L080C278C
	lsrs r2, r3, #3
	adds r2, r2, r0
	movs r1, #7
	ands r1, r3
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
.L080C2784:
	pop {r0}
	bx r0
.L080C2788: .4byte 0xFFFFFED4
.L080C278C: .4byte 0x03006090 @ IWRAM+0x6090

	thumb_func_start sub_080C2790
sub_080C2790: @ 0x080C2790
.L080C2790:
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080C27B4
	adds r1, r1, r0
	cmp r1, #0x3f
	bhi .L080C27B0
	ldr r0, .L080C27B8
	lsrs r2, r1, #3
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C27B0:
	pop {r0}
	bx r0
.L080C27B4: .4byte 0xFFFFFED4
.L080C27B8: .4byte 0x03006090 @ IWRAM+0x6090

	thumb_func_start sub_080C27BC
sub_080C27BC: @ 0x080C27BC
.L080C27BC:
	push {r4, lr}
	movs r4, #0xe0
	lsls r4, r4, #0x14
	ldr r0, .L080C27E4
	adds r1, r4, #0
	adds r1, #0x44
	movs r2, #8
	bl Sram_WriteVerified
	ldr r0, .L080C27E8
	ldr r1, .L080C27EC
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #8
	bl Sram_WriteVerified
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C27E4: .4byte 0x03006090 @ IWRAM+0x6090
.L080C27E8: .4byte 0x03004680 @ IWRAM+0x4680
.L080C27EC: .4byte 0x00006CAC

	thumb_func_start sub_080C27F0
sub_080C27F0: @ 0x080C27F0
.L080C27F0:
	push {r4, r5, r6, r7, lr}
	movs r7, #0xe0
	lsls r7, r7, #0x14
	adds r0, r7, #0
	adds r0, #0x44
	ldr r1, .L080C2870
	movs r2, #8
	bl Sram_ReadVerified
	movs r5, #0
	movs r6, #0x96
	lsls r6, r6, #0x11
.L080C2808:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r5, r1
	bl sub_080C2734
	cmp r0, #0
	beq .L080C282A
	lsrs r4, r6, #0x10
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080C282A
	adds r0, r4, #0
	bl sub_080C3328
.L080C282A:
	movs r0, #0x80
	lsls r0, r0, #9
	adds r6, r6, r0
	adds r5, #1
	cmp r5, #0x3f
	bls .L080C2808
	ldr r0, .L080C2874
	adds r0, r7, r0
	ldr r4, .L080C2878
	adds r1, r4, #0
	movs r2, #8
	bl Sram_ReadVerified
	movs r5, #0
.L080C2846:
	lsrs r0, r5, #3
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r5
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080C2864
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r5, r1
	bl Flag_Set
.L080C2864:
	adds r5, #1
	cmp r5, #0x3f
	bls .L080C2846
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C2870: .4byte 0x03006090 @ IWRAM+0x6090
.L080C2874: .4byte 0x00006CAC
.L080C2878: .4byte 0x03004680 @ IWRAM+0x4680

	thumb_func_start sub_080C287C
sub_080C287C: @ 0x080C287C
.L080C287C:
	push {r4, lr}
	cmp r0, #0xfe
	bhi .L080C28C2
	cmp r0, #0
	beq .L080C28C2
	cmp r0, #0xde
	beq .L080C28C2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1d
	beq .L080C28C2
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	beq .L080C28C2
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x28
	beq .L080C28C2
	movs r0, #1
	b .L080C28C4
.L080C28C2:
	movs r0, #0
.L080C28C4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C28CC
sub_080C28CC: @ 0x080C28CC
.L080C28CC:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C287C
	adds r2, r0, #0
	cmp r2, #1
	beq .L080C28DE
	movs r0, #0
	b .L080C28EE
.L080C28DE:
	ldr r1, .L080C28F4
	lsrs r0, r4, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #7
	ands r1, r4
	asrs r0, r1
	ands r0, r2
.L080C28EE:
	pop {r4}
	pop {r1}
	bx r1
.L080C28F4: .4byte 0x03004650 @ IWRAM+0x4650

	thumb_func_start sub_080C28F8
sub_080C28F8: @ 0x080C28F8
.L080C28F8:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C287C
	adds r2, r0, #0
	cmp r2, #1
	bne .L080C2918
	ldr r0, .L080C2920
	lsrs r1, r4, #3
	adds r1, r1, r0
	movs r0, #7
	ands r0, r4
	lsls r2, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
.L080C2918:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2920: .4byte 0x03004650 @ IWRAM+0x4650

	thumb_func_start sub_080C2924
sub_080C2924: @ 0x080C2924
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080C2948
	cmp r1, r0
	bhi .L080C2942
	ldr r0, .L080C294C
	lsrs r2, r1, #3
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C2942:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2948: .4byte 0x0000017B
.L080C294C: .4byte 0x03004650 @ IWRAM+0x4650

	thumb_func_start sub_080C2950
sub_080C2950: @ 0x080C2950
.L080C2950:
	push {lr}
	ldr r0, .L080C2960
	ldr r1, .L080C2964
	movs r2, #0x30
	bl Sram_WriteVerified
	pop {r0}
	bx r0
.L080C2960: .4byte 0x03004650 @ IWRAM+0x4650
.L080C2964: .4byte 0x0E00004C

	thumb_func_start sub_080C2968
sub_080C2968: @ 0x080C2968
.L080C2968:
	push {lr}
	ldr r0, .L080C2978
	ldr r1, .L080C297C
	movs r2, #0x30
	bl Sram_ReadVerified
	pop {r0}
	bx r0
.L080C2978: .4byte 0x0E00004C
.L080C297C: .4byte 0x03004650 @ IWRAM+0x4650

	thumb_func_start sub_080C2980
sub_080C2980: @ 0x080C2980
.L080C2980:
	push {lr}
	ldr r0, .L080C2990
	ldr r1, .L080C2994
	movs r2, #0x10
	bl Sram_WriteVerified
	pop {r0}
	bx r0
.L080C2990: .4byte 0x03006080 @ IWRAM+0x6080
.L080C2994: .4byte 0x0E006C9C

	thumb_func_start sub_080C2998
sub_080C2998: @ 0x080C2998
.L080C2998:
	push {lr}
	ldr r0, .L080C29A8
	ldr r1, .L080C29AC
	movs r2, #0x10
	bl Sram_ReadVerified
	pop {r0}
	bx r0
.L080C29A8: .4byte 0x0E006C9C
.L080C29AC: .4byte 0x03006080 @ IWRAM+0x6080

	thumb_func_start sub_080C29B0
sub_080C29B0: @ 0x080C29B0
.L080C29B0:
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080C29D4
	cmp r2, r0
	bhi .L080C29E0
	ldr r0, .L080C29D8
	lsrs r1, r2, #3
	ldr r3, .L080C29DC
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	b .L080C29E2
	.byte 0x00, 0x00
.L080C29D4: .4byte 0x0000017B
.L080C29D8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C29DC: .4byte 0x00001106
.L080C29E0:
	movs r0, #0
.L080C29E2:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C29E8
sub_080C29E8: @ 0x080C29E8
.L080C29E8:
	push {lr}
	adds r3, r0, #0
	ldr r0, .L080C2A10
	cmp r3, r0
	bhi .L080C2A0A
	ldr r0, .L080C2A14
	lsrs r2, r3, #3
	ldr r1, .L080C2A18
	adds r0, r0, r1
	adds r2, r2, r0
	movs r1, #7
	ands r1, r3
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
.L080C2A0A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2A10: .4byte 0x0000017B
.L080C2A14: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2A18: .4byte 0x00001106

	thumb_func_start sub_080C2A1C
sub_080C2A1C: @ 0x080C2A1C
.L080C2A1C:
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080C2A44
	cmp r1, r0
	bhi .L080C2A3E
	ldr r0, .L080C2A48
	lsrs r2, r1, #3
	ldr r3, .L080C2A4C
	adds r0, r0, r3
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
.L080C2A3E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2A44: .4byte 0x0000017B
.L080C2A48: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2A4C: .4byte 0x00001106

	thumb_func_start sub_080C2A50
sub_080C2A50: @ 0x080C2A50
.L080C2A50:
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r5, r1, #0x10
	lsrs r5, r5, #0x10
	ldr r6, .L080C2A80
	adds r0, r6, #0
	mov r1, sp
	movs r2, #8
	bl Sram_ReadVerified
	lsls r4, r4, #1
	mov r1, sp
	adds r0, r1, r4
	strh r5, [r0]
	mov r0, sp
	adds r1, r6, #0
	movs r2, #8
	bl Sram_WriteVerified
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C2A80: .4byte 0x0E000008

	thumb_func_start sub_080C2A84
sub_080C2A84: @ 0x080C2A84
.L080C2A84:
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, .L080C2AA4
	mov r1, sp
	movs r2, #8
	bl Sram_ReadVerified
	lsls r4, r4, #1
	mov r1, sp
	adds r0, r1, r4
	ldrh r0, [r0]
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
.L080C2AA4: .4byte 0x0E000008

	thumb_func_start sub_080C2AA8
sub_080C2AA8: @ 0x080C2AA8
.L080C2AA8:
	push {lr}
	sub sp, #4
	ldr r0, .L080C2AC4
	mov r1, sp
	movs r2, #4
	bl Sram_ReadVerified
	ldr r1, .L080C2AC8
	ldr r0, [sp]
	str r0, [r1]
	add sp, #4
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C2AC4: .4byte 0x0E000010
.L080C2AC8: .4byte 0x03004688 @ IWRAM+0x4688

	thumb_func_start sub_080C2ACC
sub_080C2ACC: @ 0x080C2ACC
.L080C2ACC:
	ldr r0, .L080C2AD4
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C2AD4: .4byte 0x03004688 @ IWRAM+0x4688

	thumb_func_start sub_080C2AD8
sub_080C2AD8: @ 0x080C2AD8
.L080C2AD8:
	push {lr}
	sub sp, #4
	str r0, [sp]
	ldr r1, .L080C2AF4
	mov r0, sp
	movs r2, #4
	bl Sram_WriteVerified
	ldr r1, .L080C2AF8
	ldr r0, [sp]
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
.L080C2AF4: .4byte 0x0E000010
.L080C2AF8: .4byte 0x03004688 @ IWRAM+0x4688

	thumb_func_start sub_080C2AFC
sub_080C2AFC: @ 0x080C2AFC
.L080C2AFC:
	push {lr}
	bl sub_080C2AA8
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080C2B0E
	movs r0, #1
	b .L080C2B10
.L080C2B0E:
	movs r0, #0
.L080C2B10:
	pop {r1}
	bx r1

	thumb_func_start sub_080C2B14
sub_080C2B14: @ 0x080C2B14
.L080C2B14:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	movs r1, #4
	rsbs r1, r1, #0
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Settings_GetBattleMsgSpeed
Settings_GetBattleMsgSpeed: @ 0x080C2B34
.L080C2B34:
	push {lr}
	bl sub_080C2AA8
	movs r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L080C2B46
	movs r0, #1
	b .L080C2B48
.L080C2B46:
	movs r0, #0
.L080C2B48:
	pop {r1}
	bx r1

	thumb_func_start sub_080C2B4C
sub_080C2B4C: @ 0x080C2B4C
.L080C2B4C:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C2B6C
sub_080C2B6C: @ 0x080C2B6C
.L080C2B6C:
	push {lr}
	bl sub_080C2AA8
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0
	bne .L080C2B7E
	movs r0, #1
	b .L080C2B80
.L080C2B7E:
	movs r0, #0
.L080C2B80:
	pop {r1}
	bx r1

	thumb_func_start sub_080C2B84
sub_080C2B84: @ 0x080C2B84
.L080C2B84:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	movs r1, #0x31
	rsbs r1, r1, #0
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C2BA4
sub_080C2BA4: @ 0x080C2BA4
.L080C2BA4:
	push {lr}
	bl sub_080C2AA8
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080C2BB8
	movs r0, #0
	b .L080C2BC6
.L080C2BB8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L080C2BC4
	movs r0, #2
	b .L080C2BC6
.L080C2BC4:
	movs r0, #1
.L080C2BC6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2BCC
sub_080C2BCC: @ 0x080C2BCC
.L080C2BCC:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	ldr r1, .L080C2BEC
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2BEC: .4byte 0xFFFFFE3F

	thumb_func_start sub_080C2BF0
sub_080C2BF0: @ 0x080C2BF0
.L080C2BF0:
	push {lr}
	bl sub_080C2AA8
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080C2C04
	movs r0, #1
	b .L080C2C06
.L080C2C04:
	movs r0, #0
.L080C2C06:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2C0C
sub_080C2C0C: @ 0x080C2C0C
.L080C2C0C:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	ldr r1, .L080C2C2C
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2C2C: .4byte 0xFFFFF9FF

	thumb_func_start sub_080C2C30
sub_080C2C30: @ 0x080C2C30
.L080C2C30:
	push {lr}
	bl sub_080C2AA8
	movs r1, #0x80
	lsls r1, r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L080C2C44
	movs r0, #1
	b .L080C2C46
.L080C2C44:
	movs r0, #0
.L080C2C46:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2C4C
sub_080C2C4C: @ 0x080C2C4C
.L080C2C4C:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	ldr r1, .L080C2C6C
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2C6C: .4byte 0xFFFFE7FF

	thumb_func_start sub_080C2C70
sub_080C2C70: @ 0x080C2C70
.L080C2C70:
	push {lr}
	bl sub_080C2ACC
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq .L080C2C86
	movs r0, #0
	b .L080C2C96
.L080C2C86:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne .L080C2C94
	movs r0, #2
	b .L080C2C96
.L080C2C94:
	movs r0, #1
.L080C2C96:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C2C9C
sub_080C2C9C: @ 0x080C2C9C
.L080C2C9C:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2AA8
	ldr r1, .L080C2CBC
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0
	bl sub_080C2AD8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2CBC: .4byte 0xFFFF1FFF

	thumb_func_start sub_080C2CC0
sub_080C2CC0: @ 0x080C2CC0
.L080C2CC0:
	push {lr}
	bl sub_080C1D9C
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080C2CD4
	movs r0, #0xff
	bl sub_080C1D00
.L080C2CD4:
	pop {r0}
	bx r0

	thumb_func_start sub_080C2CD8
sub_080C2CD8: @ 0x080C2CD8
.L080C2CD8:
	push {r4, lr}
	sub sp, #4
	adds r4, r2, #0
	ldr r2, .L080C2D2C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [r2]
	ldr r0, .L080C2D30
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [r0]
	ldr r0, .L080C2D34
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	str r4, [r0]
	ldr r0, .L080C2D38
	bl SetMainCallback
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C2D3C
	ldr r2, .L080C2D40
	mov r0, sp
	bl CpuSet
	bl Palette_MarkDirty
	bl sub_080C2CC0
	cmp r4, #0
	bne .L080C2D22
	ldr r0, .L080C2D44
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
.L080C2D22:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2D2C: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080C2D30: .4byte 0x03004618 @ IWRAM+0x4618
.L080C2D34: .4byte 0x03004624 @ IWRAM+0x4624
.L080C2D38: .4byte sub_080C1880
.L080C2D3C: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080C2D40: .4byte 0x05000100 @ PLTT+0x100
.L080C2D44: .4byte 0x030046C0 @ IWRAM+0x46C0
