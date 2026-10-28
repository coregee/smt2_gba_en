	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_081551F8
sub_081551F8: @ 0x081551F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r6, .L0815526C
	ldr r0, [r6, #0x10]
	cmp r0, #0
	bne .L08155214
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0x12
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r6, #0x10]
.L08155214:
	ldr r0, [r6, #0x14]
	cmp r0, #0
	bne .L0815522A
	str r0, [sp]
	movs r0, #0x15
	movs r1, #0
	movs r2, #9
	movs r3, #3
	bl Window_CreateOpen
	str r0, [r6, #0x14]
.L0815522A:
	movs r0, #0
	str r0, [sp, #8]
	ldr r1, .L08155270
	add r0, sp, #8
	str r0, [r1]
	ldr r0, .L08155274
	str r0, [r1, #4]
	ldr r0, .L08155278
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r4, sp, #0xc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #8
	bl memset
	ldr r5, .L0815527C
	ldrb r0, [r5, #0xd]
	bl NumberToDigits
	movs r0, #0x4c
	strb r0, [r4]
	movs r0, #0x56
	strb r0, [r4, #1]
	ldrb r0, [r5, #0xd]
	cmp r0, #9
	bhi .L08155284
	ldr r0, .L08155280
	ldrb r0, [r0]
	adds r0, #0x30
	strb r0, [r4, #2]
	movs r0, #0x20
	b .L08155290
.L0815526C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155270: .4byte 0x040000D4 @ REG_DMA3SAD
.L08155274: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155278: .4byte 0x85002000
.L0815527C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08155280: .4byte 0x030020E8 @ IWRAM+0x20E8
.L08155284:
	ldr r0, .L081552A8
	ldrb r1, [r0, #1]
	adds r1, #0x30
	strb r1, [r4, #2]
	ldrb r0, [r0]
	adds r0, #0x30
.L08155290:
	strb r0, [r4, #3]
	movs r0, #0
	bl Combatant_GetAlignment
	cmp r0, #1
	beq .L081552B6
	cmp r0, #1
	bgt .L081552AC
	cmp r0, #0
	beq .L081552B2
	b .L081552BC
	.byte 0x00, 0x00
.L081552A8: .4byte 0x030020E8 @ IWRAM+0x20E8
.L081552AC:
	cmp r0, #2
	beq .L081552BA
	b .L081552BC
.L081552B2:
	movs r7, #8
	b .L081552BC
.L081552B6:
	movs r7, #0
	b .L081552BC
.L081552BA:
	movs r7, #0xa
.L081552BC:
	ldr r1, .L081552E4
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl SmallFont_DrawAsciiTinted
	bl sub_08154F4C
	ldrh r0, [r6, #6]
	bl sub_081551A8
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081552E4: .4byte 0x02016874 @ EWRAM+0x16874

	thumb_func_start sub_081552E8
sub_081552E8: @ 0x081552E8
	push {r4, r5, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r5, .L08155314
	movs r0, #0
	strh r0, [r3, #0x1c]
	cmp r1, #0
	bne .L08155318
	str r1, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r5, #0x18]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L08155368
	.byte 0x00, 0x00
.L08155314: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155318:
	ldr r0, .L08155338
	ldrh r1, [r0]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L0815533C
	strh r4, [r3, #0x1c]
	ldr r0, [r5, #0x18]
	movs r1, #1
	bl Window_Close
	movs r0, #1
	bl sub_0815565C
	b .L08155368
.L08155338: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0815533C:
	movs r0, #0x5b
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	ldr r0, .L08155370
	ldr r0, [r0]
	lsrs r0, r0, #4
	ands r0, r4
	cmp r0, #0
	bne .L08155368
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x8d
	bl sub_080C4AB0
.L08155368:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L08155370: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_08155374
sub_08155374: @ 0x08155374
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r5, .L08155398
	ldrh r1, [r5, #4]
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #0x44
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r2, #0
	ldr r3, .L0815539C
	ldr r4, .L081553A0
	b .L081553AA
	.byte 0x00, 0x00
.L08155398: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815539C: .4byte 0x030050E0 @ IWRAM+0x50E0
.L081553A0: .4byte gUnknown_0834A23C
.L081553A4:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L081553AA:
	cmp r2, #5
	bhi .L081553D2
	adds r0, r2, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne .L081553A4
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r1, [sp]
	movs r1, #0xaa
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081553D2:
	ldr r0, .L08155438
	movs r1, #0
	str r1, [sp]
	movs r1, #0xd0
	str r1, [sp, #4]
	movs r1, #0xe
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	ldr r1, .L0815543C
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r1, r0
	movs r2, #0
	subs r4, r6, #1
.L081553F6:
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xf
	bls .L081553F6
	ldr r1, .L08155440
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r1, r0
	movs r2, #0
.L08155412:
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xf
	bls .L08155412
	bl Palette_MarkDirty
	ldrh r1, [r5, #2]
	cmp r1, #2
	beq .L08155468
	cmp r1, #2
	bgt .L08155444
	cmp r1, #1
	beq .L0815544A
	b .L081554CC
.L08155438: .4byte gUnknown_087E1C68
.L0815543C: .4byte 0x03002E50 @ IWRAM+0x2E50
.L08155440: .4byte 0x03002A50 @ IWRAM+0x2A50
.L08155444:
	cmp r1, #3
	beq .L08155498
	b .L081554CC
.L0815544A:
	ldrh r0, [r5]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L08155460
	ldr r0, .L0815545C
	b .L081554A2
	.byte 0x00, 0x00
.L0815545C: .4byte gUnknown_0815BE50
.L08155460:
	ldr r0, .L08155464
	b .L081554A2
.L08155464: .4byte gUnknown_0815BE92
.L08155468:
	ldrh r1, [r5]
	subs r0, r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0815547C
	ldr r0, .L08155478
	b .L081554A0
.L08155478: .4byte gUnknown_0815BE68
.L0815547C:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L08155490
	ldr r0, .L0815548C
	b .L081554A0
	.byte 0x00, 0x00
.L0815548C: .4byte gUnknown_0815BEA6
.L08155490:
	ldr r0, .L08155494
	b .L081554A0
.L08155494: .4byte gUnknown_0815BEBE
.L08155498:
	ldrh r0, [r5]
	cmp r0, #3
	bne .L081554B8
	ldr r0, .L081554B4
.L081554A0:
	movs r1, #1
.L081554A2:
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x1a
	bl Text_DrawSpriteString
	b .L081554CC
.L081554B4: .4byte gUnknown_0815BE7E
.L081554B8:
	ldr r0, .L08155508
	movs r1, #1
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x1a
	bl Text_DrawSpriteString
.L081554CC:
	str r7, [sp]
	movs r0, #0x1a
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl sub_080C49EC
	ldrh r0, [r5, #6]
	cmp r0, #0
	beq .L081554EC
	movs r0, #4
	movs r1, #2
	movs r2, #0xe0
	movs r3, #0x34
	bl sub_080C4A4C
.L081554EC:
	ldrh r0, [r5, #6]
	adds r0, #6
	cmp r0, r4
	bgt .L08155500
	movs r0, #4
	movs r1, #2
	movs r2, #0xe0
	movs r3, #0x92
	bl sub_080C4AB0
.L08155500:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08155508: .4byte gUnknown_0815BEBE

	thumb_func_start sub_0815550C
sub_0815550C: @ 0x0815550C
	ldr r1, .L08155514
	ldrh r1, [r1, #0xa]
	strh r1, [r0, #0x1e]
	bx lr
.L08155514: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08155518
sub_08155518: @ 0x08155518
.L08155518:
	push {r4, r5, lr}
	ldr r3, .L08155550
	movs r2, #0
	adds r1, r3, #0
	adds r1, #0x5c
	movs r4, #0
	adds r5, r3, #0
	adds r5, #0x1c
.L08155528:
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L08155540
	ldr r0, [r3, #0x4c]
	cmp r1, r0
	beq .L08155540
	lsls r0, r2, #2
	adds r0, r5, r0
	str r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08155540:
	adds r4, #1
	adds r1, #0x80
	cmp r4, #0xb
	bls .L08155528
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
.L08155550: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08155554
sub_08155554: @ 0x08155554
.L08155554:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r7, .L081555F0
	movs r3, #0
	ldr r0, [r7, #0x4c]
	ldr r1, .L081555F4
	mov sl, r1
	cmp r0, #0
	beq .L08155572
	ldrh r0, [r0, #0x12]
	mov sl, r0
.L08155572:
	ldr r0, [r7, #0x50]
	ldr r4, .L081555F4
	mov sb, r4
	cmp r0, #0
	beq .L08155580
	ldrh r0, [r0, #0x12]
	mov sb, r0
.L08155580:
	ldr r0, [r7, #0x54]
	ldr r1, .L081555F4
	mov r8, r1
	cmp r0, #0
	beq .L0815558E
	ldrh r0, [r0, #0x12]
	mov r8, r0
.L0815558E:
	str r3, [sp]
	bl sub_08153E9C
	ldrh r1, [r7]
	subs r0, r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp]
	cmp r0, #1
	bhi .L081555FC
	movs r5, #0
.L081555A4:
	lsls r0, r5, #7
	ldr r1, .L081555F8
	adds r6, r0, r1
	adds r4, r5, #4
	adds r0, r4, #0
	str r3, [sp]
	bl Combatant_IsUsed
	ldr r3, [sp]
	cmp r0, #0
	beq .L081555E6
	adds r0, r4, #0
	bl Combatant_IsDead
	ldr r3, [sp]
	cmp r0, #0
	bne .L081555E6
	movs r4, #0x12
	ldrsh r0, [r6, r4]
	cmp r0, sl
	beq .L081555E6
	cmp r0, sb
	beq .L081555E6
	cmp r0, r8
	beq .L081555E6
	lsls r0, r3, #2
	adds r1, r7, #0
	adds r1, #0x1c
	adds r1, r1, r0
	str r6, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L081555E6:
	adds r5, #1
	cmp r5, #0xb
	bls .L081555A4
	b .L0815564C
	.byte 0x00, 0x00
.L081555F0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081555F4: .4byte 0x0000FFFF
.L081555F8: .4byte 0x030048C0 @ IWRAM+0x48C0
.L081555FC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	beq .L0815560E
	cmp r0, #5
	bne .L0815564C
	ldrh r0, [r7, #8]
	cmp r0, #0
	bne .L08155644
.L0815560E:
	adds r2, r7, #0
	adds r2, #0x5c
	movs r5, #0
	adds r1, r7, #0
	adds r1, #0x1c
.L08155618:
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	beq .L0815563A
	movs r4, #0x12
	ldrsh r0, [r2, r4]
	cmp r0, sl
	beq .L0815563A
	cmp r0, sb
	beq .L0815563A
	cmp r0, r8
	beq .L0815563A
	lsls r0, r3, #2
	adds r0, r1, r0
	str r2, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L0815563A:
	adds r5, #1
	adds r2, #0x80
	cmp r5, #0xb
	bls .L08155618
	b .L0815564C
.L08155644:
	cmp r0, #1
	bne .L0815564C
	bl sub_08155518
.L0815564C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815565C
sub_0815565C: @ 0x0815565C
.L0815565C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r5, .L0815568C
	subs r2, r6, #1
	lsls r0, r2, #2
	adds r1, r5, #0
	adds r1, #0x4c
	adds r0, r0, r1
	movs r4, #0
	str r4, [r0]
	strh r2, [r5, #8]
	bl sub_08155554
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	cmp r6, #1
	beq .L08155690
	cmp r6, #2
	beq .L08155698
	b .L0815569E
.L0815568C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155690:
	movs r0, #0
	mov r8, r0
	movs r7, #0x24
	b .L0815569E
.L08155698:
	movs r0, #0
	mov r8, r0
	movs r7, #0x32
.L0815569E:
	ldr r1, .L081556C0
	movs r0, #0xf0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	mov r2, r8
	adds r3, r7, #0
	bl Canvas_FillRect
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081556C0: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_081556C4
sub_081556C4: @ 0x081556C4
.L081556C4:
	push {r4, lr}
	sub sp, #4
	ldr r4, .L081556EC
	movs r0, #0
	str r0, [sp]
	ldr r1, .L081556F0
	ldr r2, .L081556F4
	mov r0, sp
	bl CpuSet
	bl sub_08154F4C
	ldrh r0, [r4, #6]
	bl sub_081551A8
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081556EC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081556F0: .4byte 0x02011874 @ EWRAM+0x11874
.L081556F4: .4byte 0x05000C00

	thumb_func_start sub_081556F8
sub_081556F8: @ 0x081556F8
	ldr r1, .L0815570C
	ldr r0, .L08155710
	str r0, [r1]
	ldr r0, .L08155714
	str r0, [r1, #4]
	ldr r0, .L08155718
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0815570C: .4byte 0x040000D4 @ REG_DMA3SAD
.L08155710: .4byte gUnknown_081B4F10
.L08155714: .4byte 0x06015000 @ VRAM+0x15000
.L08155718: .4byte 0x84000200

	thumb_func_start sub_0815571C
sub_0815571C: @ 0x0815571C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r6, r1, #0
	ldr r7, .L081557D0
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp, #0xc]
	mov sl, r4
	cmp r4, #5
	bls .L08155746
	movs r1, #6
	mov sl, r1
.L08155746:
	adds r0, r6, #1
	strh r0, [r7, #2]
	strh r6, [r7, #8]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r2]
	mov r1, sp
	ldrh r2, [r1, #0xc]
	mov r1, r8
	strh r2, [r1, #0x1c]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r1, #0x1e]
	ldr r2, .L081557D4
	ldrh r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L08155850
	ldrh r0, [r7, #6]
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r0, r0, #2
	adds r4, r7, #0
	adds r4, #0x1c
	adds r0, r0, r4
	ldr r0, [r0]
	mov sl, r0
	ldrh r0, [r0, #0x12]
	bl sub_081544AC
	cmp r0, #1
	beq .L0815579A
	b .L0815589C
.L0815579A:
	lsls r2, r6, #1
	mov sb, r2
	cmp r6, #0
	bne .L081557F8
	movs r5, #0
	mov sb, r6
	ldr r0, .L081557D8
	adds r3, r7, r0
	ldr r1, .L081557DC
	adds r6, r7, r1
.L081557AE:
	lsls r4, r5, #2
	ldr r2, .L081557E0
	adds r0, r2, r4
	ldr r2, [r0]
	cmp r2, #0
	beq .L081557E4
	adds r1, r3, r4
	ldrh r0, [r2, #0x12]
	strh r0, [r1]
	str r3, [sp, #0x14]
	bl Random_Byte
	adds r1, r6, r4
	strh r0, [r1]
	ldr r3, [sp, #0x14]
	b .L081557EE
	.byte 0x00, 0x00
.L081557D0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081557D4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081557D8: .4byte 0x0000066C
.L081557DC: .4byte 0x0000066E
.L081557E0: .4byte 0x0203A470 @ EWRAM+0x3A470
.L081557E4:
	adds r0, r3, r4
	ldr r1, .L08155840
	strh r1, [r0]
	adds r0, r6, r4
	strh r2, [r0]
.L081557EE:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	bls .L081557AE
.L081557F8:
	ldr r4, .L08155844
	mov r0, sb
	adds r1, r0, r4
	mov r2, sl
	ldrh r0, [r2, #0x12]
	strh r0, [r1]
	ldr r0, [sp, #0x10]
	bl sub_08153F6C
	movs r5, #0
.L0815580C:
	lsls r0, r5, #2
	ldr r1, .L08155848
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	beq .L08155826
	lsls r0, r5, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	mov r2, r8
	bl sub_081562EC
.L08155826:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #2
	bls .L0815580C
	movs r0, #0
	movs r1, #1
	mov r2, r8
	strh r1, [r2, #0x1c]
	ldr r1, .L0815584C
	str r0, [r1]
	b .L0815589C
	.byte 0x00, 0x00
.L08155840: .4byte 0x0000FFFF
.L08155844: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155848: .4byte 0x0203A4A0 @ EWRAM+0x3A4A0
.L0815584C: .4byte 0x030031CC @ IWRAM+0x31CC
.L08155850:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L0815588C
	cmp r6, #0
	beq .L08155872
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_0815565C
	movs r0, #1
	str r0, [sp, #0xc]
	mov r1, r8
	strh r0, [r1, #0x1e]
	b .L0815587E
.L08155872:
	ldr r0, .L08155888
	str r3, [r0]
	mov r2, r8
	strh r3, [r2, #0x1e]
	mov r0, sb
	strh r3, [r0]
.L0815587E:
	movs r0, #0x66
	bl sub_080C51D4
	b .L0815590C
	.byte 0x00, 0x00
.L08155888: .4byte 0x030031CC @ IWRAM+0x31CC
.L0815588C:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081558A4
	mov r1, r8
	strh r5, [r1, #0x1e]
.L0815589C:
	movs r0, #0x65
	bl sub_080C51D4
	b .L0815590C
.L081558A4:
	ldr r0, .L081558BC
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L081558D0
	ldrh r0, [r7, #4]
	cmp r0, #0
	beq .L081558C0
	subs r0, #1
	b .L081558E4
	.byte 0x00, 0x00
.L081558BC: .4byte 0x03003964 @ IWRAM+0x3964
.L081558C0:
	ldrh r0, [r7, #6]
	cmp r0, #0
	beq .L0815590C
	subs r0, #1
	strh r0, [r7, #6]
	movs r2, #1
	str r2, [sp, #0xc]
	b .L081558E6
.L081558D0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0815590C
	ldrh r1, [r7, #4]
	mov r0, sl
	subs r0, #1
	cmp r1, r0
	beq .L081558EE
	adds r0, r1, #1
.L081558E4:
	strh r0, [r7, #4]
.L081558E6:
	movs r0, #0x64
	bl sub_080C51D4
	b .L0815590C
.L081558EE:
	cmp r1, #5
	bne .L0815590C
	ldrh r2, [r7, #6]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r4, #1
	cmp r0, r1
	bgt .L0815590C
	adds r0, r2, #1
	strh r0, [r7, #6]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x64
	bl sub_080C51D4
.L0815590C:
	ldr r4, .L08155934
	ldr r0, .L08155938
	ldr r0, [r0]
	lsrs r2, r0, #3
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne .L08155940
	ldr r0, .L0815593C
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r1, #0
	movs r2, #0xc
	movs r3, #0
	bl Sprite_Draw
	b .L08155956
.L08155934: .4byte gUnknown_081B6E50
.L08155938: .4byte 0x030031BC @ IWRAM+0x31BC
.L0815593C: .4byte gUnknown_080018C0
.L08155940:
	ldr r0, .L0815598C
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0xc
	movs r3, #0
	bl Sprite_Draw
.L08155956:
	ldr r2, .L08155990
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L08155994
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, [sp, #0xc]
	cmp r1, #1
	bne .L0815597C
	bl sub_081556C4
.L0815597C:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815598C: .4byte gUnknown_080018D8
.L08155990: .4byte 0x03003150 @ IWRAM+0x3150
.L08155994: .4byte sub_081556F8

	thumb_func_start Fusion_DrawMaterialHeader
Fusion_DrawMaterialHeader: @ 0x08155998
.L08155998:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r1, #0
	lsls r0, r4, #2
	ldr r1, .L081559D8
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	bl Demon_GetRecord
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	adds r7, r0, #0
	movs r0, #6
	mov sl, r0
	cmp r4, #0
	beq .L081559DC
	cmp r4, #1
	beq .L08155A14
	b .L08155A3E
	.byte 0x00, 0x00
.L081559D8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081559DC:
	movs r1, #0x24
	str r1, [sp, #0xc]
	ldr r0, .L08155A08
	ldr r6, .L08155A0C
	movs r5, #0xa
	str r5, [sp]
	movs r4, #8
	str r4, [sp, #4]
	adds r1, r6, #0
	movs r2, #6
	movs r3, #0x26
	bl DigitFont_DrawStringTinted
	ldr r0, .L08155A10
	str r5, [sp]
	str r4, [sp, #4]
	adds r1, r6, #0
	movs r2, #0xe
	movs r3, #0x28
	bl SmallFont_DrawAsciiTinted
	b .L08155A3E
.L08155A08: .4byte gUnknown_087E1C70
.L08155A0C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155A10: .4byte gUnknown_087E1C74
.L08155A14:
	movs r2, #0x32
	str r2, [sp, #0xc]
	ldr r0, .L08155AC8
	ldr r6, .L08155ACC
	movs r5, #0xa
	str r5, [sp]
	movs r4, #8
	str r4, [sp, #4]
	adds r1, r6, #0
	movs r2, #6
	movs r3, #0x34
	bl DigitFont_DrawStringTinted
	ldr r0, .L08155AD0
	str r5, [sp]
	str r4, [sp, #4]
	adds r1, r6, #0
	movs r2, #0xe
	movs r3, #0x36
	bl SmallFont_DrawAsciiTinted
.L08155A3E:
	mov r0, sl
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r0, #0
	mov r8, r0
	mov r1, sb
	adds r1, #0x22
	str r1, [sp, #0x14]
	mov r2, sl
	lsls r5, r2, #0x10
	adds r4, r7, #0
.L08155A58:
	ldrh r0, [r4]
	lsrs r2, r5, #0x10
	movs r1, #0xa
	str r1, [sp]
	ldr r1, .L08155ACC
	ldr r3, [sp, #0xc]
	bl Font_DrawGlyphTinted
	movs r7, #0xc0
	lsls r7, r7, #0xc
	adds r5, r5, r7
	adds r4, #2
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #2
	bls .L08155A58
	mov r0, sl
	adds r0, #0x24
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r2, #0
	mov r8, r2
	ldr r1, [sp, #0x14]
	mov r7, sb
	ldrh r0, [r7, #0x22]
	cmp r0, #0
	beq .L08155B0C
	mov r0, sl
	adds r0, #4
	str r0, [sp, #0x18]
	adds r5, r1, #0
	movs r6, #0
	mov r2, sl
	lsls r4, r2, #0x10
	ldr r0, [sp, #0xc]
	subs r0, #2
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
.L08155AA8:
	mov r7, sb
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0x2c
	beq .L08155AD4
	adds r0, r1, r6
	ldrh r0, [r0]
	lsrs r2, r4, #0x10
	movs r1, #0xa
	str r1, [sp]
	ldr r1, .L08155ACC
	ldr r7, [sp, #0x10]
	lsrs r3, r7, #0x10
	bl sub_08153FC8
	b .L08155AE8
.L08155AC8: .4byte gUnknown_087E1C78
.L08155ACC: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155AD0: .4byte gUnknown_087E1C7C
.L08155AD4:
	ldrh r0, [r5]
	ldr r1, [sp, #0x18]
	lsls r2, r1, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xa
	str r1, [sp]
	ldr r1, .L08155B68
	ldr r3, [sp, #0xc]
	bl Font_DrawGlyphTinted
.L08155AE8:
	ldr r2, [sp, #0x18]
	adds r2, #0xc
	str r2, [sp, #0x18]
	adds r5, #2
	adds r6, #2
	movs r7, #0xc0
	lsls r7, r7, #0xc
	adds r4, r4, r7
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #7
	bhi .L08155B0C
	ldr r1, [sp, #0x14]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08155AA8
.L08155B0C:
	ldr r2, .L08155B6C
	ldrh r1, [r2]
	cmp r1, #1
	beq .L08155B9E
	cmp r1, #4
	beq .L08155B9E
	cmp r1, #5
	beq .L08155B9E
	mov r0, sl
	adds r0, #0x62
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r0, .L08155B70
	ldr r1, .L08155B68
	ldr r4, [sp, #0xc]
	adds r4, #2
	lsls r3, r4, #0x10
	lsrs r3, r3, #0x10
	movs r2, #0xa
	str r2, [sp]
	movs r2, #8
	str r2, [sp, #4]
	mov r2, sl
	bl DigitFont_DrawStringTinted
	mov r7, sb
	ldrb r0, [r7, #1]
	bl NumberToDigits
	ldrb r0, [r7, #1]
	cmp r0, #9
	bls .L08155B78
	add r1, sp, #8
	ldr r2, .L08155B74
	ldrb r0, [r2, #1]
	adds r0, #0x30
	movs r3, #0
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, #0x30
	strb r0, [r1, #1]
	adds r0, r1, #0
	strb r3, [r0, #2]
	b .L08155B88
	.byte 0x00, 0x00
.L08155B68: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155B6C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155B70: .4byte gUnknown_087E1C44
.L08155B74: .4byte 0x030020E8 @ IWRAM+0x20E8
.L08155B78:
	add r2, sp, #8
	ldr r0, .L08155BB0
	ldrb r0, [r0]
	adds r0, #0x30
	movs r1, #0
	strb r0, [r2]
	adds r0, r2, #0
	strb r1, [r0, #1]
.L08155B88:
	ldr r1, .L08155BB4
	movs r2, #0xb4
	lsls r3, r4, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xa
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	add r0, sp, #8
	bl DigitFont_DrawStringTinted
.L08155B9E:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08155BB0: .4byte 0x030020E8 @ IWRAM+0x20E8
.L08155BB4: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_08155BB8
sub_08155BB8: @ 0x08155BB8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r2, #0
	ldr r5, .L08155C34
	ldrh r2, [r5]
	cmp r2, #2
	bne .L08155BCA
	cmp r1, #1
	beq .L08155C2C
.L08155BCA:
	cmp r2, #1
	bne .L08155BD2
	cmp r1, #1
	beq .L08155C2C
.L08155BD2:
	cmp r2, #4
	bne .L08155BDA
	cmp r1, #1
	beq .L08155C2C
.L08155BDA:
	cmp r2, #3
	bne .L08155BE2
	cmp r1, #2
	beq .L08155C2C
.L08155BE2:
	cmp r2, #5
	bne .L08155BEA
	cmp r1, #2
	beq .L08155C2C
.L08155BEA:
	cmp r4, #0
	bne .L08155BF2
	strh r4, [r5, #4]
	strh r4, [r5, #6]
.L08155BF2:
	cmp r1, #1
	bhi .L08155BFA
	bl Fusion_DrawMaterialHeader
.L08155BFA:
	cmp r4, #0
	bne .L08155C2C
	bl sub_08155554
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ldrh r0, [r5]
	cmp r0, #1
	beq .L08155C2C
	cmp r0, #4
	beq .L08155C2C
	cmp r0, #5
	beq .L08155C2C
	str r4, [sp]
	ldr r1, .L08155C38
	ldr r2, .L08155C3C
	mov r0, sp
	bl CpuSet
	bl sub_08154F4C
	ldrh r0, [r5, #6]
	bl sub_081551A8
.L08155C2C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L08155C34: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155C38: .4byte 0x02011874 @ EWRAM+0x11874
.L08155C3C: .4byte 0x05000C00

	thumb_func_start sub_08155C40
sub_08155C40: @ 0x08155C40
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08155C58
	ldrh r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi .L08155C7C
	lsls r0, r0, #2
	ldr r1, .L08155C5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08155C58: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155C5C: .4byte gUnknown_08155C60
	.global gUnknown_08155C60
gUnknown_08155C60:
.L08155C60: @ jump table
	.4byte .L08155C74
	.4byte .L08155C74
	.4byte .L08155C78
	.4byte .L08155C74
	.4byte .L08155C78
.L08155C74:
	movs r0, #2
	b .L08155C7A
.L08155C78:
	movs r0, #3
.L08155C7A:
	strh r0, [r2, #0x1e]
.L08155C7C:
	pop {r0}
	bx r0

	thumb_func_start sub_08155C80
sub_08155C80: @ 0x08155C80
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, .L08155CB8
	ldr r0, [r6, #0x10]
	cmp r0, #0
	beq .L08155C96
	movs r1, #1
	bl Window_Close
	movs r0, #0
	str r0, [r6, #0x10]
.L08155C96:
	ldr r0, [r6, #0x14]
	cmp r0, #0
	beq .L08155CA6
	movs r1, #1
	bl Window_Close
	movs r0, #0
	str r0, [r6, #0x14]
.L08155CA6:
	ldrh r0, [r6]
	adds r1, r0, #0
	cmp r1, #1
	bne .L08155CC4
	ldr r4, .L08155CBC
	ldrh r0, [r4]
	ldr r1, .L08155CC0
	ldrh r2, [r4, #2]
	b .L08155CE8
.L08155CB8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155CBC: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155CC0: .4byte 0x0000FFFF
.L08155CC4:
	cmp r1, #4
	bne .L08155CDC
	ldr r4, .L08155CD4
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldr r2, .L08155CD8
	b .L08155CE8
	.byte 0x00, 0x00
.L08155CD4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155CD8: .4byte 0x0000FFFF
.L08155CDC:
	cmp r1, #5
	bne .L08155D00
	ldr r4, .L08155CFC
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
.L08155CE8:
	mov r3, sp
	adds r3, #6
	str r3, [sp]
	add r3, sp, #4
	bl sub_0815B884
	add r0, sp, #4
	ldrh r0, [r0]
	strh r0, [r4, #6]
	b .L08155DA2
.L08155CFC: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155D00:
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L08155D44
	bl sub_0815B260
	bl sub_081572AC
	ldr r1, .L08155D38
	strh r0, [r1, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xfe
	bls .L08155D22
	movs r0, #0xfb
	strh r0, [r1, #6]
.L08155D22:
	movs r4, #0
	ldr r3, .L08155D3C
	ldr r2, .L08155D40
.L08155D28:
	adds r0, r4, r3
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, #1
	cmp r4, #6
	bls .L08155D28
	b .L08155DA2
.L08155D38: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155D3C: .4byte 0x0203B860 @ EWRAM+0x3B860
.L08155D40: .4byte 0x0203B918 @ EWRAM+0x3B918
.L08155D44:
	cmp r1, #6
	bne .L08155DA2
	ldr r2, .L08155DC0
	movs r5, #0
	ldr r3, .L08155DC4
	ldr r1, .L08155DC8
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r4, .L08155DCC
	adds r1, r6, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L08155DD0
	ands r0, r1
	strh r0, [r3, #6]
	movs r4, #0
	ldr r3, .L08155DD4
	movs r2, #0xff
.L08155D6E:
	adds r1, r4, r3
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r4, #1
	cmp r4, #6
	bls .L08155D6E
	movs r4, #0
.L08155D7E:
	ldr r0, .L08155DC4
	ldrh r0, [r0, #6]
	bl Demon_GetRecord
	adds r0, #0x11
	adds r0, r0, r4
	ldrb r1, [r0]
	cmp r1, #0xff
	beq .L08155D9C
	ldr r0, .L08155DD4
	adds r0, r5, r0
	strb r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08155D9C:
	adds r4, #1
	cmp r4, #6
	bls .L08155D7E
.L08155DA2:
	ldr r0, .L08155DD8
	ldr r1, .L08155DDC
	ldr r2, .L08155DE0
	bl CpuSet
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r1, [r0]
	cmp r1, #1
	bne .L08155DE4
	ldr r0, [r6, #0xc]
	str r1, [r0, #0xc]
	b .L08155DEA
	.byte 0x00, 0x00
.L08155DC0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08155DC4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08155DC8: .4byte 0x00000666
.L08155DCC: .4byte 0x0000066A
.L08155DD0: .4byte 0x00007FFF
.L08155DD4: .4byte 0x0203B860 @ EWRAM+0x3B860
.L08155DD8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155DDC: .4byte 0x0203AC54 @ EWRAM+0x3AC54
.L08155DE0: .4byte 0x04000200 @ REG_IE
.L08155DE4:
	movs r0, #1
	bl PalFade_FadeToBlack
.L08155DEA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08155DF4
sub_08155DF4: @ 0x08155DF4
	push {r4, lr}
	ldr r4, .L08155E18
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08155E12
	bl sub_080CED00
	ldr r2, .L08155E1C
	ldr r1, [r4, #0xc]
	str r1, [r2, #0x38]
	ldr r1, .L08155E20
	str r0, [r1]
.L08155E12:
	pop {r4}
	pop {r0}
	bx r0
.L08155E18: .4byte 0x0203AC54 @ EWRAM+0x3AC54
.L08155E1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155E20: .4byte 0x030068E0 @ IWRAM+0x68E0

	thumb_func_start sub_08155E24
sub_08155E24: @ 0x08155E24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r4, .L08155E74
	movs r0, #0
	mov sb, r0
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r0, #0
	adds r5, r3, #0
	cmp r3, #5
	bls .L08155E46
	movs r5, #6
.L08155E46:
	mov r7, sb
	mov r1, r8
	strh r7, [r1, #0x1c]
	ldrh r2, [r4, #4]
	ldrh r0, [r4, #6]
	mov ip, r0
	adds r6, r2, r0
	lsls r0, r6, #2
	adds r1, r4, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r7, #0x12
	ldrsh r1, [r0, r7]
	ldr r7, .L08155E78
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r1, r0
	bne .L08155E7C
	movs r0, #1
	mov r1, r8
	strh r0, [r1, #0x1c]
	b .L08155EAA
.L08155E74: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155E78: .4byte 0x0000065C
.L08155E7C:
	subs r0, r5, #1
	cmp r2, r0
	beq .L08155E8E
	adds r0, r2, #1
	strh r0, [r4, #4]
	movs r0, #0x64
	bl sub_080C51D4
	b .L08155EAA
.L08155E8E:
	cmp r2, #5
	bne .L08155EAA
	adds r1, r6, #1
	subs r0, r3, #1
	cmp r1, r0
	bgt .L08155EAA
	mov r0, ip
	adds r0, #1
	strh r0, [r4, #6]
	movs r7, #1
	mov sb, r7
	movs r0, #0x64
	bl sub_080C51D4
.L08155EAA:
	mov r0, sb
	cmp r0, #1
	bne .L08155EB4
	bl sub_081556C4
.L08155EB4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08155EC0
sub_08155EC0: @ 0x08155EC0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08155EEC
	ldr r0, [r4, #0x10]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x14]
	movs r1, #1
	bl Window_Close
	ldr r2, [r4, #0xc]
	movs r0, #1
	adds r1, r5, #0
	bl sub_08157EB0
	ldr r1, .L08155EF0
	movs r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08155EEC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155EF0: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_08155EF4
sub_08155EF4: @ 0x08155EF4
	push {lr}
	sub sp, #4
	bl sub_080C98A0
	movs r3, #0
	str r3, [sp]
	ldr r0, .L08155F34
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, .L08155F38
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L08155F3C
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L08155F40
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	pop {r0}
	bx r0
.L08155F34: .4byte 0x040000D4 @ REG_DMA3SAD
.L08155F38: .4byte 0x85000400
.L08155F3C: .4byte 0x06001000 @ VRAM+0x1000
.L08155F40: .4byte 0x06002000 @ VRAM+0x2000

	thumb_func_start sub_08155F44
sub_08155F44: @ 0x08155F44
	push {r4, lr}
	ldr r4, .L08155F6C
	ldr r0, [r4, #0x10]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x14]
	movs r1, #1
	bl Window_Close
	movs r0, #0
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	ldr r0, .L08155F70
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4}
	pop {r0}
	bx r0
.L08155F6C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155F70: .4byte sub_08155EF4

	thumb_func_start sub_08155F74
sub_08155F74: @ 0x08155F74
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08155F90
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq .L08155F88
	movs r0, #0
.L08155F88:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08155F90: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08155F94
sub_08155F94: @ 0x08155F94
.L08155F94:
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r6, .L08155FB0
	cmp r5, #1
	beq .L08155FAA
	cmp r5, #4
	beq .L08155FAA
	cmp r5, #5
	bne .L08155FB8
.L08155FAA:
	ldr r0, .L08155FB4
	b .L08155FC6
	.byte 0x00, 0x00
.L08155FB0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155FB4: .4byte gUnknown_087E24CC
.L08155FB8:
	cmp r5, #6
	bne .L08155FC4
	ldr r0, .L08155FC0
	b .L08155FC6
.L08155FC0: .4byte gUnknown_087E3360
.L08155FC4:
	ldr r0, .L08155FEC
.L08155FC6:
	ldr r1, .L08155FF0
	bl Task_Create
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r1, .L08155FF4
	ldr r2, .L08155FF8
	mov r0, sp
	bl CpuSet
	strh r5, [r6]
	ldr r0, .L08155FFC
	strh r5, [r0, #8]
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L08155FEC: .4byte gUnknown_087E1C80
.L08155FF0: .4byte 0x0000FFFF
.L08155FF4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08155FF8: .4byte 0x05000200 @ PLTT+0x200
.L08155FFC: .4byte 0x0203B854 @ EWRAM+0x3B854

	thumb_func_start sub_08156000
sub_08156000: @ 0x08156000
.L08156000:
	push {r4, r5, lr}
	ldr r5, .L0815601C
	ldr r0, .L08156020
	ldrh r0, [r0, #8]
	adds r1, r0, #0
	cmp r0, #1
	beq .L08156016
	cmp r0, #4
	beq .L08156016
	cmp r0, #5
	bne .L08156028
.L08156016:
	ldr r0, .L08156024
	b .L08156036
	.byte 0x00, 0x00
.L0815601C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156020: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08156024: .4byte gUnknown_087E2974
.L08156028:
	cmp r1, #6
	bne .L08156034
	ldr r0, .L08156030
	b .L08156036
.L08156030: .4byte gUnknown_087E35F4
.L08156034:
	ldr r0, .L08156060
.L08156036:
	ldr r1, .L08156064
	bl Task_Create
	adds r4, r0, #0
	ldr r0, .L08156068
	ldr r1, .L0815606C
	ldr r2, .L08156070
	bl CpuSet
	ldrh r1, [r5]
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L0815605A
	adds r0, r1, #0
	cmp r0, #4
	bne .L08156074
.L0815605A:
	movs r0, #0
	str r0, [r5, #0x50]
	b .L08156080
.L08156060: .4byte gUnknown_087E2094
.L08156064: .4byte 0x0000FFFF
.L08156068: .4byte 0x0203AC54 @ EWRAM+0x3AC54
.L0815606C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156070: .4byte 0x04000200 @ REG_IE
.L08156074:
	cmp r0, #3
	beq .L0815607C
	cmp r0, #5
	bne .L08156080
.L0815607C:
	movs r0, #0
	str r0, [r5, #0x54]
.L08156080:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_08156088
sub_08156088: @ 0x08156088
.L08156088:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L081560B0
	mov sb, r0
	movs r6, #0
	movs r1, #0x40
	mov r8, r1
	movs r7, #0xab
	lsls r7, r7, #1
	ldrh r0, [r0]
	cmp r0, #4
	beq .L081560BE
	cmp r0, #4
	bgt .L081560B4
	cmp r0, #1
	beq .L081560BA
	b .L081560C8
.L081560B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081560B4:
	cmp r0, #5
	beq .L081560C4
	b .L081560C8
.L081560BA:
	movs r0, #0
	b .L081560C6
.L081560BE:
	movs r1, #2
	mov sl, r1
	b .L081560C8
.L081560C4:
	movs r0, #1
.L081560C6:
	mov sl, r0
.L081560C8:
	movs r5, #0
.L081560CA:
	mov r0, r8
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08156104
	ldr r0, .L08156130
	lsls r1, r5, #2
	add r1, sl
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08156104
	lsls r4, r6, #7
	adds r4, #0x5c
	add r4, sb
	adds r0, r4, #0
	movs r1, #1
	adds r2, r7, #0
	bl Combatant_InitDemon
	lsls r1, r6, #2
	mov r0, sb
	adds r0, #0x1c
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08156104:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r5, #0xf
	bls .L081560CA
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08156130: .4byte gUnknown_087E248C

	thumb_func_start sub_08156134
sub_08156134: @ 0x08156134
	push {r4, r5, lr}
	ldr r4, .L08156164
	bl sub_08153E9C
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_08156088
	movs r5, #0
	movs r1, #1
	strh r1, [r4, #2]
	ldr r1, .L08156168
	adds r4, r4, r1
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_0815B880
	ldr r0, .L0815616C
	str r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156164: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156168: .4byte 0x0000065E
.L0815616C: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_08156170
sub_08156170: @ 0x08156170
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0815618C
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldrh r4, [r1]
	cmp r4, #1
	bne .L08156190
	bl sub_08153E9C
	bl sub_08153EB8
	b .L081561AA
	.byte 0x00, 0x00
.L0815618C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156190:
	cmp r4, #4
	beq .L081561C6
	cmp r4, #5
	bne .L081561CA
	ldrh r4, [r1, #8]
	cmp r4, #0
	beq .L081561C6
	cmp r4, #1
	bne .L081561B4
	bl sub_08153E9C
	bl sub_08155518
.L081561AA:
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081561CA
	strh r4, [r5, #0x1c]
	b .L081561CA
.L081561B4:
	cmp r4, #2
	bne .L081561CA
	bl sub_08153E9C
	bl sub_08153EB8
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081561CA
.L081561C6:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L081561CA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_081561D0
sub_081561D0: @ 0x081561D0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #2]
	cmp r0, #1
	beq .L081561F4
	cmp r0, #1
	bgt .L081561E8
	cmp r0, #0
	beq .L081561EE
	b .L081561FE
.L081561E8:
	cmp r0, #2
	beq .L081561FA
	b .L081561FE
.L081561EE:
	movs r2, #0
	movs r1, #8
	b .L081561FE
.L081561F4:
	movs r2, #0x14
	movs r1, #8
	b .L081561FE
.L081561FA:
	movs r2, #0xa
	movs r1, #2
.L081561FE:
	movs r0, #0
	str r0, [sp]
	adds r0, r2, #0
	movs r2, #0xa
	movs r3, #0xb
	bl Window_CreateOpen
	str r0, [r4, #4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08156218
sub_08156218: @ 0x08156218
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #2]
	cmp r0, #1
	beq .L0815623C
	cmp r0, #1
	bgt .L08156230
	cmp r0, #0
	beq .L08156236
	b .L08156246
.L08156230:
	cmp r0, #2
	beq .L08156242
	b .L08156246
.L08156236:
	movs r2, #0
	movs r3, #0x40
	b .L08156246
.L0815623C:
	movs r2, #0xa0
	movs r3, #0x40
	b .L08156246
.L08156242:
	movs r2, #0x50
	movs r3, #0x10
.L08156246:
	ldrh r1, [r4]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	bl sub_080C3D84
	str r0, [r4, #8]
	movs r1, #0
	bl sub_080C3E40
	ldr r2, .L08156278
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x10
	strh r1, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156278: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_0815627C
sub_0815627C: @ 0x0815627C
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r5, .L08156298
	adds r6, r2, #0
	adds r6, #0x24
	ldr r1, .L0815629C
	ldrh r0, [r1]
	movs r4, #1
	adds r3, r4, #0
	ands r3, r0
	cmp r3, #0
	beq .L081562A0
	strh r4, [r2, #0x1c]
	b .L081562CA
.L08156298: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815629C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081562A0:
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L081562C8
	strh r4, [r2, #0x1c]
	ldrh r0, [r5, #8]
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne .L081562CA
	strh r4, [r5, #0xa]
	ldrh r0, [r6, #2]
	lsls r0, r0, #2
	adds r1, r5, #0
	adds r1, #0x4c
	adds r0, r0, r1
	str r3, [r0]
	b .L081562CA
.L081562C8:
	strh r0, [r2, #0x1c]
.L081562CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_081562D0
sub_081562D0: @ 0x081562D0
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r4, #4]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #8]
	movs r1, #0
	bl sub_080C3E80
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_081562EC
sub_081562EC: @ 0x081562EC
.L081562EC:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L08156314
	ldrh r1, [r2, #2]
	bl Task_Create
	adds r2, r0, #0
	ldr r1, .L08156318
	movs r0, #0
	strh r4, [r2, #0x24]
	strh r5, [r2, #0x26]
	strh r0, [r1, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08156314: .4byte gUnknown_087E2E3C
.L08156318: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0815631C
sub_0815631C: @ 0x0815631C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r2, r0, #0
	ldr r4, .L08156368
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #6]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r6, [r0, #0x12]
	ldr r0, .L0815636C
	ldrh r1, [r2, #2]
	bl Task_Create
	ldr r1, .L08156370
	ldr r2, .L08156374
	adds r0, r4, #0
	bl CpuSet
	movs r5, #0
	str r5, [sp]
	ldr r2, .L08156378
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r6, [r4, #2]
	movs r0, #7
	strh r0, [r4]
	strh r5, [r4, #0x22]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156368: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815636C: .4byte gUnknown_084F1368
.L08156370: .4byte 0x0203AC54 @ EWRAM+0x3AC54
.L08156374: .4byte 0x04000200 @ REG_IE
.L08156378: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_0815637C
sub_0815637C: @ 0x0815637C
	ldr r1, .L081563A0
	ldr r0, .L081563A4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L081563A8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L081563AC
	str r0, [r1]
	ldr r0, .L081563B0
	str r0, [r1, #4]
	ldr r0, .L081563B4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L081563A0: .4byte 0x040000D4 @ REG_DMA3SAD
.L081563A4: .4byte gUnknown_081B93B0
.L081563A8: .4byte 0x84000200
.L081563AC: .4byte 0x0200F874 @ EWRAM+0xF874
.L081563B0: .4byte 0x06004000 @ VRAM+0x4000
.L081563B4: .4byte 0x84001F00

	thumb_func_start sub_081563B8
sub_081563B8: @ 0x081563B8
	sub sp, #4
	movs r2, #0
	str r2, [sp]
	ldr r0, .L081563E4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, .L081563E8
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L081563EC
	str r1, [r0, #4]
	ldr r1, .L081563F0
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
.L081563E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L081563E8: .4byte 0x85000400
.L081563EC: .4byte 0x06004000 @ VRAM+0x4000
.L081563F0: .4byte 0x85001F00

	thumb_func_start sub_081563F4
sub_081563F4: @ 0x081563F4
.L081563F4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, .L08156460
	ldr r2, .L08156464
	ldr r3, .L08156468
	adds r0, r1, r3
	ldrb r0, [r0]
	subs r3, #4
	adds r1, r1, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r4, .L0815646C
	ands r4, r0
	movs r7, #0x82
	movs r5, #0x45
	adds r0, r4, #0
	bl Demon_GetRecord
	adds r6, r0, #0
	adds r0, r4, #0
	bl sub_0815B864
	mov r8, r0
	adds r0, r4, #0
	bl sub_081571DC
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r1, .L08156470
	ldr r2, .L08156474
	mov r0, sp
	bl CpuSet
	ldr r0, .L08156478
	movs r1, #0x82
	movs r2, #0x45
	movs r3, #4
	bl sub_080CCE5C
	ldrb r0, [r6, #1]
	cmp r0, #9
	bhi .L0815647C
	movs r1, #0xd4
	movs r2, #0x45
	movs r3, #0
	bl sub_080CCF44
	b .L08156488
.L08156460: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156464: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08156468: .4byte 0x0000066A
.L0815646C: .4byte 0x00007FFF
.L08156470: .4byte 0x0200F874 @ EWRAM+0xF874
.L08156474: .4byte 0x05002000
.L08156478: .4byte gUnknown_087E1C44
.L0815647C:
	ldrb r0, [r6, #1]
	movs r1, #0xd4
	movs r2, #0x45
	movs r3, #0
	bl sub_080CCF44
.L08156488:
	adds r0, r5, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L081564AC
	adds r1, r7, #0
	adds r2, r5, #0
	movs r3, #4
	bl sub_080CCE5C
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0xc
	bgt .L081564B4
	ldr r0, .L081564B0
	adds r1, r7, #0
	adds r1, #0x32
	b .L081564BE
.L081564AC: .4byte gUnknown_087E3250
.L081564B0: .4byte gUnknown_087E3254
.L081564B4:
	cmp r0, #0x1a
	bgt .L081564CC
	ldr r0, .L081564C8
	adds r1, r7, #0
	adds r1, #0x22
.L081564BE:
	adds r2, r5, #0
	movs r3, #0
	bl sub_080CCE5C
	b .L081564DA
.L081564C8: .4byte gUnknown_087E325C
.L081564CC:
	ldr r0, .L081564F0
	adds r1, r7, #0
	adds r1, #0x3a
	adds r2, r5, #0
	movs r3, #0
	bl sub_080CCE5C
.L081564DA:
	adds r0, r5, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	cmp r0, #0
	bne .L081564F8
	ldr r0, .L081564F4
	adds r1, r7, #0
	adds r1, #0x42
	b .L08156504
.L081564F0: .4byte gUnknown_087E3264
.L081564F4: .4byte gUnknown_087E326C
.L081564F8:
	mov r3, r8
	cmp r3, #1
	bne .L08156514
	ldr r0, .L08156510
	adds r1, r7, #0
	adds r1, #0x22
.L08156504:
	adds r2, r5, #0
	movs r3, #0
	bl sub_080CCE5C
	b .L08156528
	.byte 0x00, 0x00
.L08156510: .4byte gUnknown_087E325C
.L08156514:
	mov r0, r8
	cmp r0, #2
	bne .L08156528
	ldr r0, .L08156560
	adds r1, r7, #0
	adds r1, #0x32
	adds r2, r5, #0
	movs r3, #0
	bl sub_080CCE5C
.L08156528:
	adds r0, r5, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L08156564
	adds r1, r7, #0
	adds r2, r5, #0
	movs r3, #4
	bl sub_080CCE5C
	adds r1, r7, #0
	adds r1, #0x52
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl sub_080CCF44
	ldr r0, .L08156568
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156560: .4byte gUnknown_087E3270
.L08156564: .4byte gUnknown_087E3278
.L08156568: .4byte sub_0815637C

	thumb_func_start sub_0815656C
sub_0815656C: @ 0x0815656C
	ldr r1, .L08156588
	ldr r0, .L0815658C
	str r0, [r1]
	ldr r0, .L08156590
	str r0, [r1, #4]
	ldr r0, .L08156594
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L08156598
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08156588: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815658C: .4byte 0x02000000 @ EWRAM
.L08156590: .4byte 0x06001000 @ VRAM+0x1000
.L08156594: .4byte 0x84000400
.L08156598: .4byte 0x00008209

	thumb_func_start sub_0815659C
sub_0815659C: @ 0x0815659C
	push {lr}
	ldr r0, .L081565B0
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080C1440
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081565B0: .4byte sub_0815656C

	thumb_func_start sub_081565B4
sub_081565B4: @ 0x081565B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	cmp r1, #4
	bhi .L081566A8
	lsls r0, r1, #2
	ldr r1, .L081565D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081565D0: .4byte gUnknown_081565D4
	.global gUnknown_081565D4
gUnknown_081565D4:
.L081565D4: @ jump table
	.4byte .L081565E8
	.4byte .L0815660C
	.4byte .L08156624
	.4byte .L081566A8
	.4byte .L0815664C
.L081565E8:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, .L08156600
	ldr r2, .L08156604
	add r0, sp, #0x14
	bl CpuSet
	ldr r0, .L08156608
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L081566A8
.L08156600: .4byte 0x02000000 @ EWRAM
.L08156604: .4byte 0x05000400
.L08156608: .4byte sub_081563B8
.L0815660C:
	ldr r0, .L0815661C
	ldr r1, .L08156620
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0xa
	b .L08156632
	.byte 0x00, 0x00
.L0815661C: .4byte gUnknown_087E2E84
.L08156620: .4byte 0x02000000 @ EWRAM
.L08156624:
	ldr r0, .L08156644
	ldr r1, .L08156648
	movs r2, #0xa
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #0xb
.L08156632:
	str r2, [sp, #8]
	movs r2, #7
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L081566A8
	.byte 0x00, 0x00
.L08156644: .4byte gUnknown_087E3044
.L08156648: .4byte 0x02000000 @ EWRAM
.L0815664C:
	ldr r0, .L081566B8
	ldr r1, .L081566BC
	mov r8, r1
	movs r1, #0
	mov sl, r1
	str r1, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectStride
	ldr r0, .L081566C0
	mov sb, r0
	movs r6, #0x16
	str r6, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r5, #8
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	str r6, [sp]
	mov r1, sl
	str r1, [sp, #4]
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	adds r0, r7, #0
	bl sub_081563F4
.L081566A8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081566B8: .4byte gUnknown_08770A24
.L081566BC: .4byte 0x02000000 @ EWRAM
.L081566C0: .4byte gUnknown_081B8170

	thumb_func_start sub_081566C4
sub_081566C4: @ 0x081566C4
	push {r4, lr}
	ldr r4, .L081566D8
	ldr r0, .L081566DC
	movs r1, #1
	bl sub_080B6B58
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
.L081566D8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081566DC: .4byte sub_0815468C

	thumb_func_start sub_081566E0
sub_081566E0: @ 0x081566E0
.L081566E0:
	ldr r0, .L081566EC
	ldr r1, .L081566F0
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L081566EC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081566F0: .4byte 0x00000664

	thumb_func_start sub_081566F4
sub_081566F4: @ 0x081566F4
.L081566F4:
	push {lr}
	bl sub_081566E0
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	beq .L08156718
	cmp r1, #1
	bgt .L0815670E
	cmp r1, #0
	beq .L08156714
	b .L0815671E
.L0815670E:
	cmp r1, #2
	beq .L0815671C
	b .L0815671E
.L08156714:
	movs r0, #0x25
	b .L0815671E
.L08156718:
	movs r0, #0xa
	b .L0815671E
.L0815671C:
	movs r0, #8
.L0815671E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08156724
sub_08156724: @ 0x08156724
.L08156724:
	push {r4, lr}
	sub sp, #0xc
	ldr r2, .L0815678C
	ldr r0, .L08156790
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	ldr r1, .L08156794
	adds r2, r2, r1
	ldrb r1, [r2]
	lsls r1, r1, #4
	adds r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08156798
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #8
	bl Text_DrawSpriteString
	ldr r0, .L0815679C
	movs r1, #0x14
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #8
	bl Text_DrawSpriteString
	ldr r0, .L081567A0
	movs r1, #0x24
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #8
	bl Text_DrawSpriteString
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815678C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156790: .4byte gUnknown_08002164
.L08156794: .4byte 0x00000664
.L08156798: .4byte gUnknown_087E327E
.L0815679C: .4byte gUnknown_087E3288
.L081567A0: .4byte gUnknown_087E3292

	thumb_func_start sub_081567A4
sub_081567A4: @ 0x081567A4
.L081567A4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	bl sub_081566E0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r6, r5, #0
	ldr r1, .L08156804
	ldr r2, .L08156808
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r8, r0
	movs r3, #0x58
	mov sb, r3
	movs r0, #4
	mov sl, r0
	adds r0, r4, #0
	bl sub_08156724
	ldr r0, .L0815680C
	movs r1, #0
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldr r2, .L08156804
	ldr r3, .L08156810
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	cmp r5, #1
	beq .L08156868
	cmp r5, #1
	bgt .L08156814
	cmp r5, #0
	beq .L0815681A
	b .L081568CA
.L08156804: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156808: .4byte 0x00000669
.L0815680C: .4byte gUnknown_08002198
.L08156810: .4byte 0x00000665
.L08156814:
	cmp r6, #2
	beq .L0815689C
	b .L081568CA
.L0815681A:
	movs r5, #0
.L0815681C:
	mov r1, r8
	adds r0, r1, r5
	lsls r0, r0, #1
	ldr r2, .L08156864
	adds r0, r0, r2
	ldrh r0, [r0]
	bl Race_GetName
	adds r7, r0, #0
	movs r4, #0
	lsls r6, r5, #4
	adds r5, #1
	mov r3, sl
	orrs r6, r3
.L08156838:
	lsls r3, r4, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	adds r3, r3, r4
	lsls r3, r3, #2
	add r3, sb
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L08156838
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls .L0815681C
	b .L081568CA
	.byte 0x00, 0x00
.L08156864: .4byte gUnknown_087E3204
.L08156868:
	movs r5, #0
	ldr r4, .L08156898
.L0815686C:
	mov r1, r8
	adds r0, r1, r5
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	lsls r1, r5, #4
	mov r2, sl
	orrs r1, r2
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	mov r3, sb
	bl Text_DrawSpriteString
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls .L0815686C
	b .L081568CA
.L08156898: .4byte gUnknown_087E32A0
.L0815689C:
	movs r5, #0
	ldr r4, .L08156918
.L081568A0:
	mov r3, r8
	adds r0, r3, r5
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	lsls r1, r5, #4
	mov r2, sl
	orrs r1, r2
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	mov r3, sb
	bl Text_DrawSpriteString
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls .L081568A0
.L081568CA:
	ldr r3, .L0815691C
	ldr r0, .L08156920
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq .L081568E4
	mov r2, sb
	adds r2, #0x48
	movs r0, #0
	movs r1, #0
	mov r3, sl
	bl sub_080C4A4C
.L081568E4:
	ldrb r4, [r4]
	adds r4, #3
	bl sub_081566F4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	bgt .L08156906
	mov r2, sb
	adds r2, #0x48
	mov r3, sl
	adds r3, #0x28
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L08156906:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156918: .4byte gUnknown_087E3340
.L0815691C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156920: .4byte 0x00000669

	thumb_func_start sub_08156924
sub_08156924: @ 0x08156924
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	bl sub_08156724
	adds r0, r4, #0
	bl sub_081567A4
	ldr r0, .L081569F0
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	str r1, [sp, #4]
	ldr r2, .L081569F4
	ldr r3, .L081569F8
	adds r1, r2, r3
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xe8
	lsls r2, r2, #0xe
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L081569FC
	ldr r3, .L08156A00
	adds r0, r0, r3
	ldr r2, [r0]
	movs r0, #0x16
	movs r1, #2
	bl sub_080C7664
	ldr r0, .L08156A04
	str r4, [sp]
	movs r1, #0xb2
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080C3168
	str r4, [sp]
	movs r1, #0xb8
	movs r2, #5
	movs r3, #0
	bl sub_080C7FD0
	movs r6, #0
.L081569A0:
	ldr r1, .L081569F4
	ldr r2, .L08156A08
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, r0, r6
	lsls r0, r0, #1
	ldr r3, .L08156A0C
	adds r0, r0, r3
	ldrh r7, [r0]
	ldr r0, .L08156A10
	adds r1, r6, #1
	mov sl, r1
	cmp r7, r0
	beq .L08156A52
	ldr r2, .L08156A14
	adds r0, r2, #0
	adds r4, r7, #0
	ands r4, r0
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	bl Demon_GetRecord
	adds r0, #0x22
	mov sb, r0
	movs r5, #0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, #0x3a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L081569E0:
	movs r6, #0
	lsrs r0, r4, #0x10
	bl sub_081571F0
	cmp r0, #0
	bne .L08156A18
	movs r6, #0xa
	b .L08156A28
.L081569F0: .4byte gUnknown_080021E4
.L081569F4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081569F8: .4byte 0x00000666
.L081569FC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08156A00: .4byte 0x00000AD8
.L08156A04: .4byte gUnknown_080007FC
.L08156A08: .4byte 0x0000066A
.L08156A0C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08156A10: .4byte 0x0000FFFF
.L08156A14: .4byte 0x00007FFF
.L08156A18:
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L08156A28
	movs r6, #1
.L08156A28:
	lsls r3, r5, #1
	mov r1, sb
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r3, r3, r5
	lsls r3, r3, #2
	adds r3, #8
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r2, r8
	str r2, [sp]
	str r6, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L081569E0
.L08156A52:
	mov r3, sl
	lsls r0, r3, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #5
	bls .L081569A0
	ldr r0, .L08156AA8
	ldr r1, .L08156AAC
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq .L08156A78
	movs r2, #8
	adds r2, #0x6a
	movs r3, #0x3a
	adds r3, #2
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L08156A78:
	ldrb r4, [r4]
	adds r4, #6
	bl sub_081571AC
	subs r0, #1
	cmp r4, r0
	bhi .L08156A96
	movs r2, #8
	adds r2, #0x6a
	movs r3, #0x3a
	adds r3, #0x44
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L08156A96:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156AA8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156AAC: .4byte 0x0000066A

	thumb_func_start sub_08156AB0
sub_08156AB0: @ 0x08156AB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r3, .L08156AF8
	ldr r0, .L08156AFC
	adds r7, r3, r0
	movs r1, #0
	mov ip, r1
	movs r5, #0
	strh r5, [r2, #0x1c]
	subs r0, #4
	adds r0, r0, r3
	mov r8, r0
	strh r5, [r0]
	ldr r6, .L08156B00
	ldrh r1, [r6]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08156B0C
	ldr r1, .L08156B04
	adds r0, r3, r1
	mov r1, ip
	strb r1, [r0]
	ldr r1, .L08156B08
	adds r0, r3, r1
	mov r1, ip
	strb r1, [r0]
	strh r4, [r2, #0x1c]
	strh r5, [r2, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	b .L08156B6A
.L08156AF8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156AFC: .4byte 0x00000664
.L08156B00: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08156B04: .4byte 0x00000665
.L08156B08: .4byte 0x00000669
.L08156B0C:
	ldrh r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08156B26
	strh r4, [r2, #0x1c]
	strh r4, [r2, #0x1e]
	movs r0, #0x66
	bl sub_080C51D4
	mov r0, r8
	strh r4, [r0]
	b .L08156B6A
.L08156B26:
	ldr r0, .L08156B3C
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08156B4C
	ldrb r0, [r7]
	cmp r0, #0
	beq .L08156B40
	subs r0, #1
	b .L08156B42
.L08156B3C: .4byte 0x03003964 @ IWRAM+0x3964
.L08156B40:
	movs r0, #2
.L08156B42:
	strb r0, [r7]
	movs r0, #0x64
	bl sub_080C51D4
	b .L08156B6A
.L08156B4C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08156B6A
	ldrb r0, [r7]
	cmp r0, #2
	beq .L08156B60
	adds r0, #1
	strb r0, [r7]
	b .L08156B64
.L08156B60:
	mov r1, ip
	strb r1, [r7]
.L08156B64:
	movs r0, #0x64
	bl sub_080C51D4
.L08156B6A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08156B74
sub_08156B74: @ 0x08156B74
.L08156B74:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x28]
	mov sb, r0
	ldr r3, [sp, #0x2c]
	mov sl, r3
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsrs r6, r1, #0x10
	str r6, [sp]
	cmp r6, r4
	blo .L08156B9C
	str r4, [sp]
.L08156B9C:
	movs r0, #0
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
	ldr r2, .L08156BDC
	ldrh r1, [r2]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L08156BF8
	mov r1, sl
	cmp r1, #0
	beq .L08156BE8
	ldr r2, .L08156BE0
	ldrb r0, [r7]
	mov r3, sb
	ldrb r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L08156BE4
	ands r0, r1
	bl sub_081571F0
	cmp r0, #0
	bne .L08156BE8
	movs r0, #0x66
	bl sub_080C51D4
	b .L08156DA4
	.byte 0x00, 0x00
.L08156BDC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08156BE0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08156BE4: .4byte 0x00007FFF
.L08156BE8:
	movs r0, #0
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L08156DA4
.L08156BF8:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08156C12
	mov r0, r8
	strh r0, [r5, #0x1e]
	movs r0, #0x66
	bl sub_080C51D4
	mov r1, r8
	strh r1, [r5, #0x1c]
	b .L08156DA4
.L08156C12:
	ldr r1, .L08156C40
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L08156C52
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrb r0, [r7]
	cmp r0, #0
	beq .L08156C44
	subs r0, #1
	strb r0, [r7]
	movs r0, #0x64
	bl sub_080C51D4
	mov r2, sl
	cmp r2, #1
	beq .L08156C3E
	b .L08156DA4
.L08156C3E:
	b .L08156CA8
.L08156C40: .4byte 0x03003964 @ IWRAM+0x3964
.L08156C44:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08156C4E
	b .L08156DA4
.L08156C4E:
	subs r0, #1
	b .L08156C9A
.L08156C52:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L08156CB0
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrb r1, [r7]
	ldr r0, [sp]
	subs r0, #1
	cmp r1, r0
	beq .L08156C80
	adds r0, r1, #1
	strb r0, [r7]
	movs r0, #0x64
	bl sub_080C51D4
	mov r1, sl
	cmp r1, #1
	beq .L08156C7E
	b .L08156DA4
.L08156C7E:
	b .L08156CA8
.L08156C80:
	subs r0, r4, #1
	cmp r1, r0
	beq .L08156C88
	b .L08156DA4
.L08156C88:
	mov r3, sb
	ldrb r2, [r3]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r6, #1
	cmp r0, r1
	ble .L08156C98
	b .L08156DA4
.L08156C98:
	adds r0, r2, #1
.L08156C9A:
	strb r0, [r3]
	movs r0, #0x64
	bl sub_080C51D4
	mov r0, sl
	cmp r0, #1
	bne .L08156DA4
.L08156CA8:
	adds r0, r5, #0
	bl sub_081563F4
	b .L08156DA4
.L08156CB0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L08156D28
	cmp r6, r4
	bls .L08156D28
	ldrb r6, [r7]
	mov r1, sb
	ldrb r1, [r1]
	mov r8, r1
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrb r0, [r7]
	cmp r0, #0
	beq .L08156CE0
	movs r2, #0
	strb r2, [r7]
	mov r3, sl
	cmp r3, #1
	bne .L08156D12
	b .L08156CF8
.L08156CE0:
	mov r0, sb
	ldrb r1, [r0]
	subs r0, r4, #1
	cmp r1, r0
	blt .L08156D00
	adds r0, r1, #1
	subs r0, r0, r4
	mov r1, sb
	strb r0, [r1]
	mov r2, sl
	cmp r2, #1
	bne .L08156D12
.L08156CF8:
	adds r0, r5, #0
	bl sub_081563F4
	b .L08156D12
.L08156D00:
	movs r0, #0
	mov r3, sb
	strb r0, [r3]
	mov r1, sl
	cmp r1, #1
	bne .L08156D12
	adds r0, r5, #0
	bl sub_081563F4
.L08156D12:
	ldrb r7, [r7]
	cmp r6, r7
	bne .L08156D20
	mov r2, sb
	ldrb r2, [r2]
	cmp r8, r2
	beq .L08156DA4
.L08156D20:
	movs r0, #0x64
	bl sub_080C51D4
	b .L08156DA4
.L08156D28:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08156DA4
	cmp r6, r4
	bls .L08156DA4
	ldrb r3, [r7]
	mov r8, r3
	mov r0, sb
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrb r0, [r7]
	subs r1, r4, #1
	cmp r0, r1
	beq .L08156D5C
	strb r1, [r7]
	mov r1, sl
	cmp r1, #1
	bne .L08156D8E
	b .L08156D74
.L08156D5C:
	mov r3, sb
	ldrb r2, [r3]
	adds r0, r0, r2
	adds r0, r0, r4
	subs r1, r6, #1
	cmp r0, r1
	bge .L08156D7C
	adds r0, r2, r4
	strb r0, [r3]
	mov r0, sl
	cmp r0, #1
	bne .L08156D8E
.L08156D74:
	adds r0, r5, #0
	bl sub_081563F4
	b .L08156D8E
.L08156D7C:
	subs r0, r6, r4
	mov r1, sb
	strb r0, [r1]
	mov r2, sl
	cmp r2, #1
	bne .L08156D8E
	adds r0, r5, #0
	bl sub_081563F4
.L08156D8E:
	ldrb r7, [r7]
	cmp r8, r7
	bne .L08156D9E
	ldr r0, [sp, #4]
	mov r3, sb
	ldrb r3, [r3]
	cmp r0, r3
	beq .L08156DA4
.L08156D9E:
	movs r0, #0x64
	bl sub_080C51D4
.L08156DA4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08156DB4
sub_08156DB4: @ 0x08156DB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r6, .L08156E1C
	bl sub_081566F4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L08156E20
	adds r0, r0, r6
	mov r8, r0
	ldr r0, .L08156E24
	adds r7, r6, r0
	str r7, [sp]
	movs r4, #0
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r2, #3
	mov r3, r8
	bl sub_08156B74
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq .L08156E0E
	ldr r1, .L08156E28
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #4
	adds r0, r6, r1
	strb r4, [r0]
	subs r1, #6
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	mov r0, r8
	ldrb r2, [r0]
	ldrb r0, [r7]
	adds r2, r2, r0
	adds r0, r5, #0
	movs r3, #1
	bl sub_08156ECC
.L08156E0E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156E1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156E20: .4byte 0x00000665
.L08156E24: .4byte 0x00000669
.L08156E28: .4byte 0x00000666

	thumb_func_start sub_08156E2C
sub_08156E2C: @ 0x08156E2C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r4, .L08156E5C
	bl sub_081571AC
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L08156E60
	adds r3, r4, r0
	adds r0, #4
	adds r4, r4, r0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #6
	bl sub_08156B74
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L08156E5C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156E60: .4byte 0x00000666

	thumb_func_start sub_08156E64
sub_08156E64: @ 0x08156E64
	push {lr}
	sub sp, #4
	ldr r1, .L08156E88
	movs r0, #0
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L08156E8C
	ldr r2, .L08156E90
	mov r0, sp
	bl CpuSet
	ldr r0, .L08156E94
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r0}
	bx r0
.L08156E88: .4byte 0x03003BB4 @ IWRAM+0x3BB4
.L08156E8C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08156E90: .4byte 0x05002000
.L08156E94: .4byte sub_081563B8

	thumb_func_start sub_08156E98
sub_08156E98: @ 0x08156E98
	push {r4, lr}
	ldr r3, .L08156EC0
	ldr r2, .L08156EC4
	adds r1, r3, r2
	ldrb r1, [r1]
	adds r1, #1
	ldr r4, .L08156EC8
	adds r2, r3, r4
	ldrb r2, [r2]
	adds r4, #4
	adds r3, r3, r4
	ldrb r3, [r3]
	adds r2, r2, r3
	movs r3, #0
	bl sub_08156ECC
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08156EC0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08156EC4: .4byte 0x00000664
.L08156EC8: .4byte 0x00000665

	thumb_func_start sub_08156ECC
sub_08156ECC: @ 0x08156ECC
.L08156ECC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r1, #0
	mov r8, r2
	str r3, [sp, #4]
	ldr r7, .L08156F14
	movs r0, #0
	str r0, [sp, #8]
	movs r5, #0
	mov r0, sp
	ldr r1, .L08156F18
	mov sb, r1
	strh r1, [r0]
	ldr r2, .L08156F1C
	adds r1, r7, #0
	bl CpuSet
	cmp r4, #0
	bne .L08156F24
	movs r6, #0
	ldr r4, .L08156F20
.L08156EFE:
	adds r0, r6, #0
	bl sub_080C28CC
	cmp r0, #0
	beq .L08156F0C
	strh r6, [r7]
	adds r7, #2
.L08156F0C:
	adds r6, #1
	cmp r6, r4
	bls .L08156EFE
	b .L08157142
.L08156F14: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08156F18: .4byte 0x0000FFFF
.L08156F1C: .4byte 0x01000180
.L08156F20: .4byte 0x0000017B
.L08156F24:
	cmp r4, #1
	bne .L08156F86
	movs r4, #0
	movs r6, #0
	ldr r1, .L08156F68
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	mov r8, r0
.L08156F36:
	adds r0, r6, #0
	bl sub_080C28CC
	cmp r0, #0
	beq .L08156F7E
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r3, r8
	ldrh r3, [r3]
	cmp r0, r3
	bne .L08156F6C
	lsls r0, r4, #1
	adds r0, r0, r7
	strh r6, [r0]
	cmp r5, #0
	bne .L08156F78
	str r4, [sp, #8]
	movs r5, #1
	b .L08156F78
	.byte 0x00, 0x00
.L08156F68: .4byte gUnknown_087E3204
.L08156F6C:
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r6, r2
	strh r1, [r0]
.L08156F78:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L08156F7E:
	adds r6, #1
	cmp r6, #0xfe
	bls .L08156F36
	b .L08157142
.L08156F86:
	cmp r4, #2
	bne .L08157004
	movs r2, #0
	movs r6, #0
	movs r5, #0
	ldr r0, .L08156FF4
	ldrh r4, [r0]
	cmp r4, sb
	bne .L08156F9A
	b .L08157142
.L08156F9A:
	mov sb, r0
	ldr r3, .L08156FF8
	mov sl, r3
.L08156FA0:
	adds r0, r4, #0
	str r2, [sp, #0xc]
	bl sub_080C28CC
	ldr r2, [sp, #0xc]
	cmp r0, #0
	beq .L08156FDA
	strh r4, [r7]
	lsls r0, r5, #2
	ldr r1, .L08156FFC
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, r8
	beq .L08156FC6
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r4, r0
	strh r4, [r7]
.L08156FC6:
	adds r7, #2
	cmp r2, #0
	bne .L08156FD4
	cmp r1, r8
	bne .L08156FD4
	str r6, [sp, #8]
	movs r2, #1
.L08156FD4:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08156FDA:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, sl
	bls .L08156FE6
	b .L08157142
.L08156FE6:
	lsls r0, r5, #2
	add r0, sb
	ldrh r4, [r0]
	ldr r0, .L08157000
	cmp r4, r0
	bne .L08156FA0
	b .L08157142
.L08156FF4: .4byte gUnknown_08585C34
.L08156FF8: .4byte 0x0000017B
.L08156FFC: .4byte gUnknown_08585C36
.L08157000: .4byte 0x0000FFFF
.L08157004:
	cmp r4, #3
	beq .L0815700A
	b .L08157142
.L0815700A:
	movs r0, #2
	bl sub_080C9210
	adds r4, r0, #0
	ldrh r0, [r4]
	mov r1, sb
	movs r2, #1
	add r2, r8
	mov sb, r2
	cmp r0, r1
	beq .L0815703A
	adds r5, r1, #0
.L08157022:
	ldrh r0, [r4]
	bl sub_080C28CC
	cmp r0, #0
	beq .L08157032
	ldrh r0, [r4]
	strh r0, [r7]
	adds r7, #2
.L08157032:
	adds r4, #4
	ldrh r0, [r4]
	cmp r0, r5
	bne .L08157022
.L0815703A:
	ldr r7, .L0815707C
	movs r6, #0
	adds r2, r7, #0
	mov r5, sb
	mov r3, r8
	lsls r0, r3, #2
	add r0, r8
	lsls r0, r0, #0x11
	mov sl, r0
.L0815704C:
	ldrh r1, [r2]
	ldr r0, .L08157080
	cmp r1, r0
	beq .L081570A6
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #0x11
	ldr r3, .L08157084
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	ldr r3, .L08157088
	adds r0, r3, #0
	ands r0, r1
	str r2, [sp, #0xc]
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	ldr r2, [sp, #0xc]
	mov r1, r8
	cmp r1, #0
	bne .L0815708C
	movs r1, #1
	b .L08157090
	.byte 0x00, 0x00
.L0815707C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L08157080: .4byte 0x0000FFFF
.L08157084: .4byte 0xFFFF0000
.L08157088: .4byte 0x00007FFF
.L0815708C:
	mov r3, sl
	lsrs r1, r3, #0x10
.L08157090:
	cmp r4, #0x64
	bls .L08157096
	movs r4, #0xc8
.L08157096:
	cmp r0, r1
	blo .L081570AC
	cmp r0, r4
	bhi .L081570AC
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	b .L081570B6
.L081570A6:
	movs r0, #0
	str r0, [sp, #8]
	b .L081570B6
.L081570AC:
	adds r2, #2
	adds r6, #1
	ldr r0, .L08157110
	cmp r6, r0
	bls .L0815704C
.L081570B6:
	movs r6, #0
	mov r1, sb
	lsls r0, r1, #2
	add r0, sb
	lsls r0, r0, #0x11
	lsrs r5, r0, #0x10
	ldrh r0, [r7]
	ldr r1, .L08157114
	cmp r0, r1
	beq .L08157142
	mov sl, r1
	adds r4, r7, #0
.L081570CE:
	cmp r5, #0x64
	bls .L081570D4
	movs r5, #0xc8
.L081570D4:
	ldrh r1, [r4]
	ldr r7, .L08157118
	adds r0, r7, #0
	ands r0, r1
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	cmp r0, r5
	bhs .L0815711C
	mov r2, r8
	cmp r2, #0
	beq .L08157128
	ldrh r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	bl Demon_GetRecord
	ldrb r1, [r0, #1]
	mov r3, r8
	lsls r0, r3, #2
	add r0, r8
	lsls r0, r0, #1
	cmp r1, r0
	bhs .L08157128
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	b .L08157124
	.byte 0x00, 0x00
.L08157110: .4byte 0x0000017B
.L08157114: .4byte 0x0000FFFF
.L08157118: .4byte 0x00007FFF
.L0815711C:
	ldrh r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
.L08157124:
	orrs r0, r1
	strh r0, [r4]
.L08157128:
	adds r4, #2
	adds r6, #1
	ldr r0, .L08157170
	cmp r6, r0
	bhi .L08157142
	mov r1, sb
	lsls r0, r1, #2
	add r0, sb
	lsls r0, r0, #0x11
	lsrs r5, r0, #0x10
	ldrh r0, [r4]
	cmp r0, sl
	bne .L081570CE
.L08157142:
	ldr r2, [sp, #4]
	cmp r2, #1
	bne .L0815719C
	ldr r4, .L08157174
	bl sub_081571AC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	ldr r3, .L08157178
	adds r2, r4, r3
	movs r0, #0
	strb r0, [r2]
	adds r3, #4
	adds r4, r4, r3
	strb r0, [r4]
	cmp r1, #6
	bhi .L0815717C
	mov r1, sp
	ldrb r1, [r1, #8]
	strb r1, [r2]
	b .L0815719A
	.byte 0x00, 0x00
.L08157170: .4byte 0x0000017B
.L08157174: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157178: .4byte 0x00000666
.L0815717C:
	subs r0, r1, #7
	ldr r3, [sp, #8]
	cmp r3, r0
	ble .L08157196
	adds r0, r3, #0
	adds r0, #6
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r3, r0
	strb r1, [r4]
	strb r0, [r2]
	b .L0815719C
.L08157196:
	mov r0, sp
	ldrb r0, [r0, #8]
.L0815719A:
	strb r0, [r4]
.L0815719C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_081571AC
sub_081571AC: @ 0x081571AC
.L081571AC:
	push {r4, r5, lr}
	movs r3, #0
	movs r2, #0
	ldr r5, .L081571D0
	ldr r4, .L081571D4
	ldr r1, .L081571D8
.L081571B8:
	ldrh r0, [r1]
	cmp r0, r5
	beq .L081571C0
	adds r3, #1
.L081571C0:
	adds r1, #2
	adds r2, #1
	cmp r2, r4
	bls .L081571B8
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
.L081571D0: .4byte 0x0000FFFF
.L081571D4: .4byte 0x0000017B
.L081571D8: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_081571DC
sub_081571DC: @ 0x081571DC
.L081571DC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C10A8
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_081571F0
sub_081571F0: @ 0x081571F0
.L081571F0:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	bl Demon_GetRecord
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	bl Party_GetMember
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_081571DC
	adds r7, r0, #0
	ldrb r0, [r4, #0xd]
	ldrb r5, [r5, #1]
	cmp r0, r5
	blo .L0815722E
	adds r0, r6, #0
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815722E
	bl sub_080C3100
	cmp r0, r7
	blo .L0815722E
	movs r0, #1
	b .L08157230
.L0815722E:
	movs r0, #0
.L08157230:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08157238
sub_08157238: @ 0x08157238
.L08157238:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	movs r5, #0x40
	movs r6, #0
	cmp r0, #3
	beq .L08157260
	cmp r0, #3
	bgt .L08157256
	cmp r0, #2
	beq .L0815725C
	b .L08157266
.L08157256:
	cmp r1, #4
	beq .L08157264
	b .L08157266
.L0815725C:
	movs r7, #0
	b .L08157266
.L08157260:
	movs r7, #2
	b .L08157266
.L08157264:
	movs r7, #1
.L08157266:
	movs r4, #0
	ldr r0, .L081572A8
	mov r8, r0
.L0815726C:
	adds r0, r5, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0815728A
	lsls r0, r4, #2
	adds r0, r7, r0
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0815728A
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0815728A:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r4, #0xf
	bls .L0815726C
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081572A8: .4byte gUnknown_087E248C

	thumb_func_start sub_081572AC
sub_081572AC: @ 0x081572AC
.L081572AC:
	push {r4, lr}
	sub sp, #8
	ldr r2, .L081572E8
	ldrh r1, [r2, #8]
	adds r3, r1, #0
	cmp r1, #2
	bne .L081572F4
	ldr r4, .L081572EC
	ldrh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	ldrh r0, [r2, #2]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r1, #2
	ldr r0, .L081572F0
	strh r0, [r1]
	bl sub_0815B4B4
	bl sub_08158970
	bl sub_0815B260
	adds r0, r4, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	b .L08157392
	.byte 0x00, 0x00
.L081572E8: .4byte 0x0203B854 @ EWRAM+0x3B854
.L081572EC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081572F0: .4byte 0x0000FFFF
.L081572F4:
	cmp r1, #3
	bne .L08157330
	ldr r4, .L0815732C
	ldrh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	ldrh r0, [r2, #2]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	ldrh r1, [r2, #4]
	adds r0, r4, #0
	adds r0, #0x94
	strh r1, [r0]
	bl sub_08154074
	bl sub_0815B4B4
	bl sub_081596F0
	bl sub_0815B260
	adds r0, r4, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	b .L08157392
	.byte 0x00, 0x00
.L0815732C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08157330:
	cmp r1, #1
	bne .L08157350
	ldrh r0, [r2]
	ldr r1, .L0815734C
	ldrh r2, [r2, #2]
	mov r3, sp
	adds r3, #6
	str r3, [sp]
	add r3, sp, #4
	bl sub_0815B884
	add r0, sp, #4
	ldrh r0, [r0]
	b .L08157392
.L0815734C: .4byte 0x0000FFFF
.L08157350:
	cmp r1, #4
	bne .L08157370
	ldrh r0, [r2]
	ldrh r1, [r2, #2]
	ldr r2, .L0815736C
	mov r3, sp
	adds r3, #6
	str r3, [sp]
	add r3, sp, #4
	bl sub_0815B884
	add r0, sp, #4
	ldrh r0, [r0]
	b .L08157392
.L0815736C: .4byte 0x0000FFFF
.L08157370:
	cmp r1, #5
	bne .L0815738C
	ldrh r0, [r2]
	ldrh r1, [r2, #2]
	ldrh r2, [r2, #4]
	mov r3, sp
	adds r3, #6
	str r3, [sp]
	add r3, sp, #4
	bl sub_0815B884
	add r0, sp, #4
	ldrh r0, [r0]
	b .L08157392
.L0815738C:
	cmp r3, #6
	bne .L08157392
	ldrh r0, [r2, #6]
.L08157392:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815739C
sub_0815739C: @ 0x0815739C
	push {r4, r5, r6, lr}
	ldr r4, .L081573E8
	ldr r6, .L081573EC
	ldrh r5, [r6, #8]
	ldrh r0, [r4]
	cmp r0, #0
	bne .L081573D2
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L081573D2
	bl sub_0815B11C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, .L081573F0
	cmp r2, r0
	beq .L081573D2
	ldrh r0, [r6, #6]
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
	strh r2, [r6, #6]
	subs r1, #2
	movs r0, #1
	strh r0, [r1]
.L081573D2:
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L081573E4
	cmp r5, #4
	beq .L081573E4
	cmp r5, #6
	bne .L081573F8
.L081573E4:
	ldr r0, .L081573F4
	b .L08157402
.L081573E8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081573EC: .4byte 0x0203B854 @ EWRAM+0x3B854
.L081573F0: .4byte 0x0000FFFF
.L081573F4: .4byte gFusionRoomAnim
.L081573F8:
	cmp r5, #3
	beq .L08157400
	cmp r5, #5
	bne .L08157404
.L08157400:
	ldr r0, .L08157428
.L08157402:
	str r0, [r4, #8]
.L08157404:
	ldr r1, .L0815742C
	ldr r0, [r1]
	str r0, [r4, #0x14]
	movs r2, #0
	str r2, [r1]
	ldr r1, .L08157430
	ldrh r0, [r1]
	strh r0, [r4, #0x18]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x1a]
	strh r2, [r1]
	strh r2, [r1, #2]
	movs r0, #0x10
	bl sub_080C5170
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08157428: .4byte gUnknown_087F01DC
.L0815742C: .4byte 0x02036094 @ EWRAM+0x36094
.L08157430: .4byte 0x02036074 @ EWRAM+0x36074

	thumb_func_start sub_08157434
sub_08157434: @ 0x08157434
	push {lr}
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_08157440
sub_08157440: @ 0x08157440
	push {r4, lr}
	ldr r4, .L08157454
	ldr r0, .L08157458
	bl sub_080B6BB0
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08157454: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157458: .4byte sub_08157434

	thumb_func_start sub_0815745C
sub_0815745C: @ 0x0815745C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08157474
	ldr r0, [r0, #0x10]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08157478
	movs r0, #1
	b .L0815747A
	.byte 0x00, 0x00
.L08157474: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157478:
	movs r0, #0
.L0815747A:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_08157480
sub_08157480: @ 0x08157480
	ldr r0, .L0815748C
	ldr r1, [r0, #0x10]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L0815748C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start Fusion_LoadRoomTiles
Fusion_LoadRoomTiles: @ 0x08157490
	push {lr}
	adds r2, r1, #0
	ldr r0, .L081574B0
	cmp r2, #5
	bhi .L081574BC
	ldr r1, .L081574B4
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r2, #0xc
	ldr r2, .L081574B8
	adds r1, r1, r2
	bl LZ77UnCompWram
	b .L081574C6
	.byte 0x00, 0x00
.L081574B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081574B4: .4byte gFusionRoomTiles
.L081574B8: .4byte 0x02001000 @ EWRAM+0x1000
.L081574BC:
	ldr r0, [r0, #8]
	ldr r0, [r0]
	ldr r1, .L081574CC
	bl LZ77UnCompWram
.L081574C6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081574CC: .4byte 0x02003920 @ EWRAM+0x3920

	thumb_func_start sub_081574D0
sub_081574D0: @ 0x081574D0
.L081574D0:
	push {r4, lr}
	sub sp, #0x10
	ldr r0, .L081574F0
	ldrh r1, [r0, #8]
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L081574EA
	cmp r1, #4
	beq .L081574EA
	cmp r1, #6
	bne .L081574F8
.L081574EA:
	ldr r0, .L081574F4
	b .L081574FA
	.byte 0x00, 0x00
.L081574F0: .4byte 0x0203B854 @ EWRAM+0x3B854
.L081574F4: .4byte gUnknown_087EF03C
.L081574F8:
	ldr r0, .L08157528
.L081574FA:
	ldr r4, .L0815752C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08157530
	adds r1, r4, r0
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x1e
	str r0, [sp, #8]
	movs r0, #0x14
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #6
	bl Tilemap_CopyRectSkipZero
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08157528: .4byte gUnknown_087EF5A0
.L0815752C: .4byte 0x02000800 @ EWRAM+0x800
.L08157530: .4byte 0xFFFFF800

	thumb_func_start sub_08157534
sub_08157534: @ 0x08157534
	push {r4, r5, r6, lr}
	ldr r4, .L08157594
	ldr r0, .L08157598
	str r0, [r4]
	ldr r0, .L0815759C
	str r0, [r4, #4]
	ldr r0, .L081575A0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r6, .L081575A4
	str r6, [r4]
	ldr r0, .L081575A8
	str r0, [r4, #4]
	ldr r5, .L081575AC
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_081574D0
	str r6, [r4]
	ldr r0, .L081575B0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, .L081575B4
	ldr r2, .L081575B8
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L081575BC
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L081575C0
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x10
	ldr r1, .L081575C4
	ldr r3, .L081575C8
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L081575CC
	ldr r0, .L081575D0
	strh r0, [r1]
	ldr r0, .L081575D4
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08157594: .4byte 0x040000D4 @ REG_DMA3SAD
.L08157598: .4byte 0x02001000 @ EWRAM+0x1000
.L0815759C: .4byte 0x06004000 @ VRAM+0x4000
.L081575A0: .4byte 0x84001B00
.L081575A4: .4byte 0x02000000 @ EWRAM
.L081575A8: .4byte 0x06001000 @ VRAM+0x1000
.L081575AC: .4byte 0x84000200
.L081575B0: .4byte 0x06003000 @ VRAM+0x3000
.L081575B4: .4byte 0x0400000A @ REG_BG1CNT
.L081575B8: .4byte 0x00008205
.L081575BC: .4byte 0x00008406
.L081575C0: .4byte 0x00008607
.L081575C4: .4byte 0x03000040 @ IWRAM+0x40
.L081575C8: .4byte 0x00003C42
.L081575CC: .4byte 0x03000042 @ IWRAM+0x42
.L081575D0: .4byte 0x00000808
.L081575D4: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_081575D8
sub_081575D8: @ 0x081575D8
	push {r4, lr}
	sub sp, #0x10
	ldr r0, .L08157600
	ldrh r4, [r0, #8]
	ldr r0, .L08157604
	ldr r1, .L08157608
	bl LZ77UnCompWram
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L081575FA
	cmp r4, #4
	beq .L081575FA
	cmp r4, #6
	bne .L08157610
.L081575FA:
	ldr r0, .L0815760C
	b .L08157612
	.byte 0x00, 0x00
.L08157600: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157604: .4byte gUnknown_087E5D48
.L08157608: .4byte 0x02006800 @ EWRAM+0x6800
.L0815760C: .4byte gUnknown_087EFB04
.L08157610:
	ldr r0, .L08157640
.L08157612:
	ldr r4, .L08157644
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08157648
	adds r1, r4, r0
	movs r2, #0xb0
	lsls r2, r2, #2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x1e
	str r0, [sp, #8]
	movs r0, #0x14
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #2
	bl Tilemap_CopyRectSkipZero
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
.L08157640: .4byte gUnknown_087EFCD8
.L08157644: .4byte 0x02000800 @ EWRAM+0x800
.L08157648: .4byte 0xFFFFF800

	thumb_func_start sub_0815764C
sub_0815764C: @ 0x0815764C
	push {r4, r5, lr}
	sub sp, #4
	bl sub_080C1384
	ldr r1, .L08157688
	ldr r4, .L0815768C
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r1, .L08157690
	adds r4, #0x80
	movs r3, #0xa0
	lsls r3, r3, #1
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	bl Palette_CopyWithEffect
	ldr r0, .L08157694
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L08157688: .4byte gUnknown_087EFF4C
.L0815768C: .4byte 0x030029F0 @ IWRAM+0x29F0
.L08157690: .4byte gUnknown_087EFFCC
.L08157694: .4byte sub_08157534

	thumb_func_start sub_08157698
sub_08157698: @ 0x08157698
	push {r4, lr}
	ldr r4, .L081576B4
	movs r1, #0xe8
	lsls r1, r1, #1
	ldr r3, .L081576B8
	movs r0, #0
	movs r2, #1
	bl PalFade_FadeRangeInFromBlackTagged
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081576B4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081576B8: .4byte 0x00008001

	thumb_func_start sub_081576BC
sub_081576BC: @ 0x081576BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L081576D4
	ldr r0, [r0, #0x1c]
	bl PalFade_IsActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L081576D8
	movs r0, #1
	b .L081576DA
	.byte 0x00, 0x00
.L081576D4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081576D8:
	movs r0, #0
.L081576DA:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081576E4
sub_081576E4: @ 0x081576E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r1, #0
	ldr r0, .L0815771C
	mov r8, r0
	ldr r7, .L08157720
	cmp r4, #2
	bne .L08157708
	ldrh r1, [r7, #8]
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08157790
	cmp r1, #4
	beq .L08157790
.L08157708:
	cmp r4, #1
	beq .L08157730
	cmp r4, #1
	blo .L08157724
	cmp r4, #2
	beq .L08157736
	cmp r4, #3
	beq .L0815773C
	b .L08157740
	.byte 0x00, 0x00
.L0815771C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157720: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157724:
	ldr r3, .L0815772C
	movs r6, #0x4a
	b .L08157740
	.byte 0x00, 0x00
.L0815772C: .4byte 0x0000FFF5
.L08157730:
	movs r3, #0x82
	movs r6, #0x4a
	b .L08157740
.L08157736:
	movs r3, #0x46
	movs r6, #0x21
	b .L08157740
.L0815773C:
	movs r3, #0x3b
	movs r6, #0x2e
.L08157740:
	lsls r0, r4, #1
	adds r1, r0, r7
	ldrh r2, [r1]
	ldr r1, .L08157758
	adds r5, r0, #0
	cmp r2, r1
	bne .L0815775C
	subs r0, r6, #3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b .L08157774
	.byte 0x00, 0x00
.L08157758: .4byte 0x0000013B
.L0815775C:
	movs r0, #0x9e
	lsls r0, r0, #1
	cmp r2, r0
	bne .L08157768
	adds r0, r3, #1
	b .L08157770
.L08157768:
	ldr r0, .L0815779C
	cmp r2, r0
	bne .L08157774
	subs r0, r3, #1
.L08157770:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08157774:
	adds r0, r5, r7
	ldrh r1, [r0]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r2, r3, #0
	adds r3, r6, #0
	bl sub_080C3D84
	lsls r2, r4, #2
	mov r1, r8
	adds r1, #0x20
	adds r1, r1, r2
	str r0, [r1]
.L08157790:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815779C: .4byte 0x0000013F

	thumb_func_start sub_081577A0
sub_081577A0: @ 0x081577A0
	push {lr}
	adds r3, r1, #0
	ldr r0, .L081577DC
	lsls r1, r3, #2
	adds r0, #0x20
	adds r1, r1, r0
	ldr r1, [r1]
	cmp r3, #2
	bne .L081577C4
	ldr r0, .L081577E0
	ldrh r2, [r0, #8]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L081577D8
	cmp r2, #4
	beq .L081577D8
.L081577C4:
	cmp r1, #0
	beq .L081577CC
	ldr r0, .L081577E4
	str r0, [r1, #0x20]
.L081577CC:
	cmp r3, #3
	bne .L081577D8
	adds r0, r1, #0
	movs r1, #0
	bl sub_080C3E40
.L081577D8:
	pop {r0}
	bx r0
.L081577DC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081577E0: .4byte 0x0203B854 @ EWRAM+0x3B854
.L081577E4: .4byte sub_080C3C68

	thumb_func_start sub_081577E8
sub_081577E8: @ 0x081577E8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r2, #0
	ldr r5, .L08157820
	cmp r1, #0
	bne .L0815782C
	ldr r1, .L08157824
	lsls r2, r4, #5
	ldr r0, .L08157828
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	lsls r0, r4, #0x14
	movs r1, #0xa0
	lsls r1, r1, #0xf
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	movs r1, #0x10
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	b .L08157858
	.byte 0x00, 0x00
.L08157820: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157824: .4byte gUnknown_087EFFAC
.L08157828: .4byte 0x030029F0 @ IWRAM+0x29F0
.L0815782C:
	ldr r1, .L08157860
	ldrh r2, [r5, #0x32]
	lsls r2, r2, #5
	ldr r0, .L08157864
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldrh r0, [r5, #0x32]
	lsls r0, r0, #0x14
	movs r1, #0xa0
	lsls r1, r1, #0xf
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	movs r1, #0x10
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
.L08157858:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L08157860: .4byte gUnknown_087EFF4C
.L08157864: .4byte 0x030029F0 @ IWRAM+0x29F0

	thumb_func_start sub_08157868
sub_08157868: @ 0x08157868
	push {r4, lr}
	ldr r4, .L08157884
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0x20
	adds r1, r1, r0
	ldr r0, [r1]
	bl sub_080C3E64
	movs r0, #0
	strh r0, [r4, #6]
	pop {r4}
	pop {r0}
	bx r0
.L08157884: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08157888
sub_08157888: @ 0x08157888
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, .L08157904
	ldrh r0, [r6, #6]
	cmp r0, #3
	bhi .L08157940
	lsls r1, r4, #0xc
	ldr r0, .L08157908
	adds r3, r1, r0
	movs r5, #0
	ldr r0, .L0815790C
	mov ip, r0
.L081578A2:
	ldrh r0, [r6, #6]
	lsls r0, r0, #2
	add r0, ip
	ldr r2, [r0]
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldr r1, [r2]
	ands r0, r1
	stm r3!, {r0}
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x77
	bls .L081578A2
	cmp r4, #1
	beq .L08157918
	cmp r4, #1
	blo .L08157910
	cmp r4, #2
	beq .L08157928
	b .L08157930
	.byte 0x00, 0x00
.L08157904: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157908: .4byte 0x02001000 @ EWRAM+0x1000
.L0815790C: .4byte gUnknown_087F02B8
.L08157910:
	ldr r0, .L08157914
	b .L0815791A
.L08157914: .4byte sub_080C3EBC
.L08157918:
	ldr r0, .L08157924
.L0815791A:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L08157930
	.byte 0x00, 0x00
.L08157924: .4byte sub_080C3EE0
.L08157928:
	ldr r0, .L0815793C
	movs r1, #1
	bl VBlankTask_AddCounted
.L08157930:
	ldrh r0, [r6, #6]
	adds r0, #1
	movs r1, #0
	strh r0, [r6, #6]
	strh r1, [r7, #0x1c]
	b .L08157954
.L0815793C: .4byte sub_080C3F04
.L08157940:
	lsls r0, r4, #2
	adds r1, r6, #0
	adds r1, #0x20
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl sub_080C3E80
	movs r0, #1
	strh r0, [r7, #0x1c]
.L08157954:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815795C
sub_0815795C: @ 0x0815795C
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r4, .L08157978
	ldr r0, .L0815797C
	ldrh r1, [r2, #2]
	bl Task_Create
	movs r0, #0
	strh r0, [r4, #0x30]
	strh r5, [r4, #0x32]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08157978: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815797C: .4byte gUnknown_087F0F94

	thumb_func_start sub_08157980
sub_08157980: @ 0x08157980
	push {r4, lr}
	sub sp, #4
	ldr r4, .L081579A0
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xe
	movs r2, #0x1a
	movs r3, #6
	bl Window_CreateOpen
	str r0, [r4, #0x34]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L081579A0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081579A4
sub_081579A4: @ 0x081579A4
.L081579A4:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_0815B824
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r4, r0
	bne .L081579C0
	movs r1, #0xe
.L081579C0:
	ldr r0, .L081579D0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081579D0: .4byte gUnknown_087F02C8

	thumb_func_start sub_081579D4
sub_081579D4: @ 0x081579D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, .L08157A04
	ldr r0, .L08157A08
	ldrh r0, [r0]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	cmp r1, #0
	beq .L08157A0C
	movs r0, #0x65
	bl sub_080C51D4
	ldr r0, [r6, #0x34]
	movs r1, #1
	bl Window_Close
	strh r5, [r4, #0x1c]
	b .L08157A0E
	.byte 0x00, 0x00
.L08157A04: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157A08: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08157A0C:
	strh r1, [r4, #0x1c]
.L08157A0E:
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08157A34
	ldr r0, .L08157A30
	movs r1, #0x72
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L08157B48
	.byte 0x00, 0x00
.L08157A30: .4byte gUnknown_0815BB90
.L08157A34:
	ldr r0, .L08157A58
	ldrh r5, [r0, #6]
	ldrh r4, [r0, #8]
	adds r0, r5, #0
	bl Demon_GetRecord
	mov r8, r0
	movs r6, #0x12
	movs r7, #0x72
	cmp r4, #1
	beq .L08157A52
	cmp r4, #4
	beq .L08157A52
	cmp r4, #5
	bne .L08157A60
.L08157A52:
	ldr r2, .L08157A5C
	b .L08157B40
	.byte 0x00, 0x00
.L08157A58: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157A5C: .4byte gUnknown_0815BF92
.L08157A60:
	adds r0, r5, #0
	bl sub_081579A4
	adds r2, r0, #0
	b .L08157B40
.L08157A6A:
	ldr r0, .L08157AC4
	adds r3, r2, #2
	mov sb, r3
	cmp r1, r0
	beq .L08157B3E
	adds r0, #9
	cmp r1, r0
	bne .L08157AC8
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	adds r5, r0, #0
	movs r4, #0
	ldrh r0, [r5]
	cmp r0, #0
	beq .L08157B3E
.L08157A92:
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L08157B3E
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08157A92
	b .L08157B3E
	.byte 0x00, 0x00
.L08157AC4: .4byte 0x00000316
.L08157AC8:
	ldr r0, .L08157B10
	cmp r1, r0
	bne .L08157B14
	movs r4, #0
	mov r1, r8
	adds r1, #0x22
	mov r2, r8
	ldrh r0, [r2, #0x22]
	cmp r0, #0
	beq .L08157B3E
	adds r5, r1, #0
.L08157ADE:
	lsls r0, r4, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L08157B3E
	lsls r0, r4, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08157ADE
	b .L08157B3E
	.byte 0x00, 0x00
.L08157B10: .4byte 0x0000031E
.L08157B14:
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	bne .L08157B28
	movs r6, #0x12
	adds r0, r7, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b .L08157B3E
.L08157B28:
	ldrh r0, [r2]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08157B3E:
	mov r2, sb
.L08157B40:
	ldrh r1, [r2]
	ldr r0, .L08157B70
	cmp r1, r0
	bne .L08157A6A
.L08157B48:
	ldr r0, .L08157B74
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08157B62
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x95
	bl sub_080C4AB0
.L08157B62:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08157B70: .4byte 0x00000301
.L08157B74: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_08157B78
sub_08157B78: @ 0x08157B78
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08157B90
	ldrh r0, [r0, #8]
	subs r0, #1
	cmp r0, #4
	bhi .L08157BB4
	lsls r0, r0, #2
	ldr r1, .L08157B94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08157B90: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157B94: .4byte gUnknown_08157B98
	.global gUnknown_08157B98
gUnknown_08157B98:
.L08157B98: @ jump table
	.4byte .L08157BAC
	.4byte .L08157BAC
	.4byte .L08157BB0
	.4byte .L08157BAC
	.4byte .L08157BB0
.L08157BAC:
	movs r0, #2
	b .L08157BB2
.L08157BB0:
	movs r0, #3
.L08157BB2:
	strh r0, [r2, #0x1e]
.L08157BB4:
	pop {r0}
	bx r0

	thumb_func_start sub_08157BB8
sub_08157BB8: @ 0x08157BB8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r4, .L08157BEC
	cmp r5, #0
	bne .L08157BF8
	ldr r0, [r4, #0x2c]
	movs r1, #0
	bl sub_080C3E80
	ldr r0, .L08157BF0
	ldr r2, [r4, #0x14]
	str r2, [r0]
	ldr r1, .L08157BF4
	ldrh r0, [r4, #0x18]
	strh r0, [r1]
	ldrh r0, [r4, #0x1a]
	strh r0, [r1, #2]
	cmp r2, #0
	beq .L08157C20
	adds r0, r2, #0
	movs r1, #1
	bl sub_080CE580
	b .L08157C20
	.byte 0x00, 0x00
.L08157BEC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157BF0: .4byte 0x02036094 @ EWRAM+0x36094
.L08157BF4: .4byte 0x02036074 @ EWRAM+0x36074
.L08157BF8:
	ldr r0, .L08157C28
	ldr r0, [r0]
	cmp r0, #0
	beq .L08157C20
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl Char_GetRecord
	subs r3, r5, #1
	lsls r1, r3, #2
	adds r0, #4
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl Char_LoadGfxHalf
.L08157C20:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L08157C28: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_08157C2C
sub_08157C2C: @ 0x08157C2C
.L08157C2C:
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r5, .L08157C60
	ldrh r0, [r5]
	bl Stock_FindDemon
	adds r4, r0, #0
	ldrh r0, [r5, #2]
	bl Stock_FindDemon
	adds r2, r0, #0
	ldrh r0, [r5]
	cmp r0, #0xfb
	bne .L08157C64
	movs r0, #0x18
	ldrsh r1, [r2, r0]
	movs r3, #0x1a
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt .L08157C56
	movs r6, #1
.L08157C56:
	movs r0, #0x1c
	ldrsh r1, [r2, r0]
	movs r3, #0x1e
	ldrsh r0, [r2, r3]
	b .L08157C80
.L08157C60: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157C64:
	ldrh r0, [r5, #2]
	cmp r0, #0xfb
	bne .L08157C88
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt .L08157C78
	movs r6, #1
.L08157C78:
	movs r3, #0x1c
	ldrsh r1, [r4, r3]
	movs r2, #0x1e
	ldrsh r0, [r4, r2]
.L08157C80:
	cmp r1, r0
	blt .L08157C88
	movs r0, #2
	orrs r6, r0
.L08157C88:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_08157C90
sub_08157C90: @ 0x08157C90
	push {r4, r5, r6, r7, lr}
	ldr r7, .L08157CC8
	ldrh r0, [r7]
	cmp r0, #1
	bne .L08157CD8
	movs r0, #0x85
	lsls r0, r0, #1
	bl sub_080C33AC
	ldr r0, .L08157CCC
	bl sub_080C33AC
	movs r0, #0x86
	lsls r0, r0, #1
	bl sub_080C33AC
	ldr r0, .L08157CD0
	bl sub_080C33AC
	movs r0, #0x87
	lsls r0, r0, #1
	bl sub_080C33AC
	ldr r0, .L08157CD4
	bl sub_080C33AC
	b .L08157E6E
	.byte 0x00, 0x00
.L08157CC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157CCC: .4byte 0x0000010B
.L08157CD0: .4byte 0x0000010D
.L08157CD4: .4byte 0x0000010F
.L08157CD8:
	cmp r0, #3
	bne .L08157CF8
	ldr r4, .L08157CF4
	ldrh r0, [r4, #6]
	bl Stock_AddDemon
	ldrh r0, [r4, #6]
	bl sub_081571DC
	rsbs r0, r0, #0
	bl sub_080C30AC
	b .L08157D76
	.byte 0x00, 0x00
.L08157CF4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157CF8:
	ldr r5, .L08157D14
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L08157D18
	ldrh r0, [r5]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C33AC
	ldrh r0, [r5, #2]
	b .L08157D5C
	.byte 0x00, 0x00
.L08157D14: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157D18:
	cmp r0, #4
	bne .L08157D3A
	ldrh r0, [r5]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C33AC
	ldrh r0, [r5, #2]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C33AC
	b .L08157D68
.L08157D3A:
	cmp r0, #5
	bne .L08157D7E
	ldrh r0, [r5]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C33AC
	ldrh r0, [r5, #2]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C33AC
	ldrh r0, [r5, #4]
.L08157D5C:
	bl Stock_FindDemon
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl Party_Remove
.L08157D68:
	ldrh r0, [r5, #6]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C3328
.L08157D76:
	movs r0, #0xf
	bl sub_080C5170
	b .L08157E6E
.L08157D7E:
	movs r6, #0
	cmp r0, #2
	bne .L08157DAE
	ldrh r0, [r5]
	bl Stock_FindDemon
	adds r4, r0, #0
	ldrh r0, [r5, #2]
	bl Stock_FindDemon
	adds r5, r0, #0
	bl sub_08157C2C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrb r0, [r4, #0xc]
	movs r1, #1
	bl Party_Remove
	ldrb r0, [r5, #0xc]
	movs r1, #1
	bl Party_Remove
	b .L08157DDC
.L08157DAE:
	cmp r0, #3
	bne .L08157DDC
	ldrh r0, [r5]
	bl Stock_FindDemon
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl Party_Remove
	ldrh r0, [r5, #2]
	bl Stock_FindDemon
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl Party_Remove
	ldrh r0, [r5, #4]
	bl Stock_FindDemon
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl Party_Remove
.L08157DDC:
	ldr r4, .L08157E80
	ldrh r0, [r4, #6]
	bl Stock_AddDemon
	ldrh r0, [r4, #6]
	bl sub_080C3560
	adds r3, r0, #0
	adds r0, r7, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08157E10
	movs r2, #0
	adds r4, r3, #0
	adds r4, #0x5d
	ldr r5, .L08157E84
.L08157DFE:
	adds r1, r4, r2
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bls .L08157DFE
.L08157E10:
	cmp r6, #0
	beq .L08157E60
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq .L08157E3A
	movs r1, #0x1a
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bge .L08157E26
	adds r0, #3
.L08157E26:
	asrs r0, r0, #2
	ldrh r1, [r3, #0x18]
	adds r0, r0, r1
	strh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L08157E88
	cmp r0, r1
	ble .L08157E3A
	strh r1, [r3, #0x18]
.L08157E3A:
	movs r0, #2
	ands r6, r0
	cmp r6, #0
	beq .L08157E60
	movs r1, #0x1e
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bge .L08157E4C
	adds r0, #3
.L08157E4C:
	asrs r0, r0, #2
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L08157E88
	cmp r0, r1
	ble .L08157E60
	strh r1, [r3, #0x1c]
.L08157E60:
	bl sub_080E5DA0
	bl sub_0815B3F4
	movs r0, #0xf
	bl sub_080C5170
.L08157E6E:
	bl sub_080C366C
	ldr r1, [r7, #0x10]
	movs r0, #1
	str r0, [r1, #0xc]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08157E80: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157E84: .4byte 0x0203B860 @ EWRAM+0x3B860
.L08157E88: .4byte 0x000003E7

	thumb_func_start sub_08157E8C
sub_08157E8C: @ 0x08157E8C
	ldr r0, .L08157E9C
	ldr r1, [r0, #0xc]
	movs r0, #1
	str r0, [r1, #0xc]
	ldr r1, .L08157EA0
	movs r0, #0
	str r0, [r1]
	bx lr
.L08157E9C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157EA0: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_08157EA4
sub_08157EA4: @ 0x08157EA4
	push {lr}
	bl sub_080CED00
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08157EB0
sub_08157EB0: @ 0x08157EB0
.L08157EB0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r1, #0
	mov r8, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r6, .L08157EE0
	movs r0, #0
	str r0, [sp]
	ldr r2, .L08157EE4
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	cmp r4, #0
	bne .L08157EF0
	ldr r0, .L08157EE8
	ldr r1, .L08157EEC
	bl Task_Create
	adds r5, r0, #0
	b .L08157F38
.L08157EE0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08157EE4: .4byte 0x05000200 @ PLTT+0x200
.L08157EE8: .4byte gUnknown_087F0308
.L08157EEC: .4byte 0x0000FFFF
.L08157EF0:
	cmp r4, #1
	bne .L08157F24
	ldr r0, .L08157F18
	ldr r1, .L08157F1C
	bl Task_Create
	adds r5, r0, #0
	ldr r1, .L08157F20
	movs r0, #0x9e
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, #3
	strh r0, [r1, #2]
	subs r0, #4
	strh r0, [r1, #4]
	adds r0, #3
	strh r0, [r1, #6]
	movs r0, #3
	b .L08157F36
	.byte 0x00, 0x00
.L08157F18: .4byte gUnknown_087F106C
.L08157F1C: .4byte 0x0000FFFF
.L08157F20: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08157F24:
	cmp r4, #2
	beq .L08157F38
	ldr r0, .L08157F50
	ldr r1, .L08157F54
	bl Task_Create
	adds r5, r0, #0
	ldr r1, .L08157F58
	movs r0, #2
.L08157F36:
	strh r0, [r1, #8]
.L08157F38:
	strh r4, [r6]
	str r7, [r6, #0xc]
	mov r0, r8
	str r0, [r6, #0x10]
	adds r0, r5, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08157F50: .4byte gUnknown_087F06D8
.L08157F54: .4byte 0x0000FFFF
.L08157F58: .4byte 0x0203B854 @ EWRAM+0x3B854

	thumb_func_start sub_08157F5C
sub_08157F5C: @ 0x08157F5C
	ldr r0, .L08157F7C
	ldr r1, .L08157F80
	str r1, [r0]
	ldr r1, .L08157F84
	str r1, [r0, #4]
	ldr r2, .L08157F88
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L08157F8C
	str r1, [r0]
	ldr r1, .L08157F90
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
	.byte 0x00, 0x00
.L08157F7C: .4byte 0x040000D4 @ REG_DMA3SAD
.L08157F80: .4byte 0x02005800 @ EWRAM+0x5800
.L08157F84: .4byte 0x06006920 @ VRAM+0x6920
.L08157F88: .4byte 0x84000200
.L08157F8C: .4byte 0x02000000 @ EWRAM
.L08157F90: .4byte 0x06003000 @ VRAM+0x3000

	thumb_func_start sub_08157F94
sub_08157F94: @ 0x08157F94
.L08157F94:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r1, #0
	ldr r0, .L08158018
	ldr r0, [r0, #8]
	lsls r4, r4, #3
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r1, .L0815801C
	bl LZ77UnCompWram
	ldr r5, [r4, #4]
	bl sub_081574D0
	ldr r0, .L08158020
	mov sb, r0
	movs r0, #0
	ldr r1, .L08158024
	mov sl, r1
	ldr r1, .L08158028
	mov r8, r1
	ldr r1, .L0815802C
	mov ip, r1
.L08157FC8:
	movs r4, #0
	adds r7, r0, #1
	lsls r6, r0, #5
.L08157FCE:
	mov r0, ip
	adds r2, r4, r0
	adds r2, r6, r2
	lsls r2, r2, #1
	add r2, sb
	ldrb r1, [r5]
	adds r5, #1
	movs r0, #0xf
	ands r1, r0
	adds r1, #6
	ldrh r3, [r2]
	mov r0, r8
	ands r0, r3
	lsls r1, r1, #0xc
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L08157FCE
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls .L08157FC8
	mov r0, sl
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08158018: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815801C: .4byte 0x02005800 @ EWRAM+0x5800
.L08158020: .4byte 0x02000000 @ EWRAM
.L08158024: .4byte sub_08157F5C
.L08158028: .4byte 0x00000FFF
.L0815802C: .4byte 0x00000189

	thumb_func_start sub_08158030
sub_08158030: @ 0x08158030
.L08158030:
	push {lr}
	ldr r1, .L08158064
	ldrh r0, [r1, #8]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L08158070
	ldrh r1, [r1, #6]
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	beq .L081580A0
	adds r0, r1, #0
	bl sub_0815B958
	movs r1, #0xff
	ands r1, r0
	cmp r1, #1
	beq .L081580A0
	cmp r1, #1
	bgt .L08158068
	cmp r1, #0
	beq .L08158090
	b .L0815806C
	.byte 0x00, 0x00
.L08158064: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08158068:
	cmp r1, #2
	beq .L0815809C
.L0815806C:
	movs r0, #3
	b .L081580A2
.L08158070:
	ldrh r0, [r1, #6]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Item_GetRecord
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #7
	beq .L08158090
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08158094
.L08158090:
	movs r0, #0
	b .L081580A2
.L08158094:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L081580A0
.L0815809C:
	movs r0, #2
	b .L081580A2
.L081580A0:
	movs r0, #1
.L081580A2:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_081580A8
sub_081580A8: @ 0x081580A8
	ldr r1, .L081580BC
	ldr r0, .L081580C0
	str r0, [r1]
	ldr r0, .L081580C4
	str r0, [r1, #4]
	ldr r0, .L081580C8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L081580BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L081580C0: .4byte 0x02001000 @ EWRAM+0x1000
.L081580C4: .4byte 0x06013800 @ VRAM+0x13800
.L081580C8: .4byte 0x84000900

	thumb_func_start Fusion_LoadEffectPart
Fusion_LoadEffectPart: @ 0x081580CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r7, .L08158134
	ldr r6, .L08158138
	bl sub_08158030
	lsls r0, r0, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r4, .L0815813C
	adds r1, r4, #0
	bl HuffUnComp
	lsls r1, r5, #0xc
	ldr r0, .L08158140
	adds r1, r1, r0
	adds r0, r4, #0
	bl LZ77UnCompWram
	cmp r5, #2
	bne .L0815812C
	bl sub_08158030
	lsls r0, r0, #4
	adds r0, r0, r6
	ldr r1, [r0, #0xc]
	ldr r2, .L08158144
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L08158148
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_0815814C
	ldr r1, [r0, #4]
	adds r0, r7, #0
	adds r0, #0x84
	strh r1, [r0]
.L0815812C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08158134: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08158138: .4byte gFusionEffectSets
.L0815813C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L08158140: .4byte 0x02001000 @ EWRAM+0x1000
.L08158144: .4byte 0x03003150 @ IWRAM+0x3150
.L08158148: .4byte sub_081580A8

	thumb_func_start sub_0815814C
sub_0815814C: @ 0x0815814C
.L0815814C:
	push {r4, lr}
	ldr r4, .L08158168
	bl sub_08158030
	adds r1, r0, #0
	cmp r1, #1
	beq .L08158180
	cmp r1, #1
	blo .L0815816C
	cmp r1, #2
	beq .L08158194
	cmp r1, #3
	beq .L081581A8
	b .L081581B4
.L08158168: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0815816C:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	lsls r0, r0, #3
	ldr r1, .L0815817C
	adds r0, r0, r1
	b .L081581B4
	.byte 0x00, 0x00
.L0815817C: .4byte gUnknown_087F09E4
.L08158180:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	lsls r0, r0, #3
	ldr r1, .L08158190
	adds r0, r0, r1
	b .L081581B4
	.byte 0x00, 0x00
.L08158190: .4byte gUnknown_087F0A9C
.L08158194:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	lsls r0, r0, #3
	ldr r1, .L081581A4
	adds r0, r0, r1
	b .L081581B4
	.byte 0x00, 0x00
.L081581A4: .4byte gUnknown_087F0B6C
.L081581A8:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	lsls r0, r0, #3
	ldr r1, .L081581BC
	adds r0, r0, r1
.L081581B4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081581BC: .4byte gUnknown_087F0994

	thumb_func_start sub_081581C0
sub_081581C0: @ 0x081581C0
	push {r4, lr}
	sub sp, #0xc
	bl sub_0815814C
	adds r4, r0, #0
	bl sub_08158030
	cmp r0, #1
	beq .L081581E0
	cmp r0, #1
	blo .L081581E0
	cmp r0, #2
	beq .L081581E0
	cmp r0, #3
	beq .L081581FC
	b .L08158216
.L081581E0:
	ldr r0, [r4]
	movs r1, #0xe0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	b .L08158216
.L081581FC:
	ldr r0, [r4]
	movs r1, #0xe0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x54
	str r1, [sp, #4]
	movs r1, #0x58
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
.L08158216:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08158220
sub_08158220: @ 0x08158220
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, .L08158264
	movs r0, #0
	strh r0, [r6, #0x1c]
	adds r5, r1, #0
	adds r5, #0x84
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0815825C
	adds r4, r1, #0
	adds r4, #0x7a
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl sub_0815814C
	ldr r1, [r0, #4]
	strh r1, [r5]
	ldr r0, [r0]
	cmp r0, #0
	bne .L0815825C
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r0, #1
	strh r0, [r6, #0x1c]
.L0815825C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08158264: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08158268
sub_08158268: @ 0x08158268
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, .L08158290
	ldr r0, .L08158294
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L081582B0
	adds r0, r3, #0
	adds r0, #0x78
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne .L08158298
	adds r0, r2, #0
	movs r1, #5
	bl sub_08157F94
	b .L081582A6
.L08158290: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08158294: .4byte 0x030031BC @ IWRAM+0x31BC
.L08158298:
	adds r0, r2, #0
	movs r1, #0
	bl sub_08157F94
	ldr r0, .L081582B8
	bl sub_080C51D4
.L081582A6:
	ldrh r0, [r4]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r4]
.L081582B0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081582B8: .4byte 0x00000153

	thumb_func_start sub_081582BC
sub_081582BC: @ 0x081582BC
	ldr r1, .L081582D0
	ldr r0, .L081582D4
	str r0, [r1]
	ldr r0, .L081582D8
	str r0, [r1, #4]
	ldr r0, .L081582DC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L081582D0: .4byte 0x040000D4 @ REG_DMA3SAD
.L081582D4: .4byte 0x02008000 @ EWRAM+0x8000
.L081582D8: .4byte 0x06013800 @ VRAM+0x13800
.L081582DC: .4byte 0x84000200

	thumb_func_start Fusion_LoadMistFrame
Fusion_LoadMistFrame: @ 0x081582E0
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L08158330
	ldr r1, .L08158334
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, .L08158338
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L0815833C
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08158340
	movs r1, #1
	bl VBlankTask_AddCounted
	ldrh r0, [r5, #0x30]
	cmp r0, #0
	bne .L08158322
	ldr r1, .L08158344
	ldr r2, .L08158348
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
.L08158322:
	ldrh r0, [r5, #0x30]
	adds r0, #1
	strh r0, [r5, #0x30]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L08158330: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08158334: .4byte gFusionMistFrames
.L08158338: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L0815833C: .4byte 0x02008000 @ EWRAM+0x8000
.L08158340: .4byte sub_081582BC
.L08158344: .4byte gUnknown_087F012C
.L08158348: .4byte 0x03003130 @ IWRAM+0x3130

	thumb_func_start sub_0815834C
sub_0815834C: @ 0x0815834C
	push {lr}
	sub sp, #0xc
	ldr r0, .L08158364
	ldrh r0, [r0, #0x32]
	cmp r0, #1
	beq .L08158374
	cmp r0, #1
	bgt .L08158368
	cmp r0, #0
	beq .L0815836E
	b .L0815837E
	.byte 0x00, 0x00
.L08158364: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08158368:
	cmp r0, #2
	beq .L0815837A
	b .L0815837E
.L0815836E:
	movs r2, #0x1c
	movs r3, #0x45
	b .L0815837E
.L08158374:
	movs r2, #0xa5
	movs r3, #0x45
	b .L0815837E
.L0815837A:
	movs r2, #0x60
	movs r3, #0x10
.L0815837E:
	ldr r0, .L0815839C
	movs r1, #0xe0
	lsls r1, r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r1, #1
	movs r2, #0xc
	movs r3, #2
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815839C: .4byte gUnknown_08002134

	thumb_func_start sub_081583A0
sub_081583A0: @ 0x081583A0
	push {lr}
	sub sp, #4
	adds r3, r1, #0
	ldr r2, .L081583C0
	cmp r3, #0
	bne .L081583C8
	ldr r1, [r2, #0x14]
	ldr r0, [r1, #0x20]
	str r0, [r2, #0x7c]
	str r3, [r1, #0x20]
	ldr r0, .L081583C4
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	b .L081583E4
.L081583C0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081583C4: .4byte 0x03006968 @ IWRAM+0x6968
.L081583C8:
	ldr r0, .L081583EC
	ldr r1, [r0]
	ldr r0, [r2, #0x7c]
	str r0, [r1, #0x20]
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #8
	bl Window_Create
	ldr r1, .L081583F0
	str r0, [r1]
.L081583E4:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081583EC: .4byte 0x02036094 @ EWRAM+0x36094
.L081583F0: .4byte 0x03006968 @ IWRAM+0x6968
